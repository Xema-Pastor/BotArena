#include "stdafx.h"
#include "CardDominaria.h"

#define new DEBUG_NEW

#define DEFINE_CARD(C)	\
	if (!_tcslen(strCardName))	\
	{ cardClassNames.push_back(_T(#C)); }	\
	else	\
	if (!_tcsicmp(strCardName, _T(#C))) { cpCard = counted_ptr<CCard>(new C(pGame, uID)); break; }

//____________________________________________________________________________
//
// Helpers (from Ixalan, see no_vale/PATRONES_MOTOR.md)

#define TREASURE_TOKEN_NAME		_T("Treasure")
#define TREASURE_TOKEN_ID		55102
#define DINOSAUR_A_TOKEN_NAME	_T("Dinosaur (A)")
#define DINOSAUR_A_TOKEN_ID		55103
#define PIRATE_A_TOKEN_NAME		_T("Pirate (A)")
#define PIRATE_A_TOKEN_ID		55104
#define ILLUSION_C_TOKEN_NAME	_T("Illusion (C)")
#define ILLUSION_C_TOKEN_ID		55105
#define VAMPIRE_E_TOKEN_NAME	_T("Vampire (E)")
#define VAMPIRE_E_TOKEN_ID		55106
#define MERFOLK_A_TOKEN_NAME	_T("Merfolk (A)")
#define MERFOLK_A_TOKEN_ID		55107
#define LANDMARK_COUNTER	_T("landmark counter")
#define CHARGE_COUNTER		_T("charge counter")
#define ELEMENTAL_AW_TOKEN_NAME	_T("Elemental (AW)")
#define ELEMENTAL_AW_TOKEN_ID	64128
#define HUATLI_RADIANT_CHAMPION_EMBLEM_NAME	_T("Huatli, Radiant Champion Emblem")
#define HUATLI_RADIANT_CHAMPION_EMBLEM_ID	61151
#define VRASKA_SCHEMING_GORGON_EFFECT_NAME	_T("Vraska, Scheming Gorgon Effect")
#define VRASKA_SCHEMING_GORGON_EFFECT_ID	61152
#define SAPROLING_TOKEN_NAME	_T("Saproling (K)")
#define SAPROLING_TOKEN_ID		62002
#define ELEMENTAL_ZC_TOKEN_NAME	_T("Elemental (ZC)")
#define ELEMENTAL_ZC_TOKEN_ID	55108
#define PREY_COUNTER	_T("prey counter")

// "{T}: Add <mana>." (colorless with _T("1"))
static void AddTapManaAbility(CCard* pCard, LPCTSTR strMana)
{
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(pCard, _T(""), AbilityType::Activated, strMana));
	cpAbility->AddTapCost();
	pCard->AddAbility(cpAbility.GetPointer());
}

// "{T}: Add {C}."
static void AddColorlessManaAbility(CCard* pCard)
{
	AddTapManaAbility(pCard, _T("1"));
}

// Search pPlayer's library for up to nMax cards that pass pFilter, put them onto the battlefield (tapped if bTapped),
// then shuffle (as Harvest Season's search in Amonkhet)
static void SearchToBattlefield(CGame* pGame, CPlayer* pPlayer, int nMax, const CCardFilter* pFilter, BOOL bTapped)
{
	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nMax), // up to N cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		pFilter, // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);

	if (bTapped)
	{
		CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				pTapModifier.ApplyTo(cards.GetAt(i));
	}

	pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

// The creatures on the battlefield controlled by pPlayer (bControlled) or by the other players (!bControlled)
static void GetCreatures(CGame* pGame, CPlayer* pPlayer, BOOL bControlled, CCountedCardContainer& creatures)
{
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CPlayer* pOwner = pGame->GetPlayer(ip);
		if ((pOwner == pPlayer) != (bControlled == TRUE))
			continue;

		CZone* pBattlefield = pOwner->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() && dynamic_cast<CCreatureCard*>(pCard))
				creatures.AddCard(pCard, CardPlacement::Top);
		}
	}
}

// The creature gets +N/+N (and the keyword, if any) until end of turn (as Aether Revolt)
static void PumpCreature(CCard* pCard, int nPower, int nToughness, CreatureKeyword keyword = CreatureKeyword::Null)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	CPowerModifier pPowerModifier = CPowerModifier(Power(nPower));
	pPowerModifier.ApplyTo(pCreature);
	CLifeModifier pLifeModifier = CLifeModifier(Life(nToughness), pCreature, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pCreature);

	if (keyword != CreatureKeyword::Null)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(keyword);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCreature);
	}
}

// "pSource deals nDamage damage to pTarget" (a creature)
static void DealDamageToCreature(CCard* pSource, CCard* pTarget, int nDamage)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pTarget);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || nDamage <= 0)
		return;

	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pCreature);
}

static void GainLife(CCard* pSource, CPlayer* pPlayer, int nLife)
{
	CLifeModifier pModifier = CLifeModifier(Life(nLife), pSource, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pPlayer);
}

static void DrawCards(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CDrawCardModifier pModifier = CDrawCardModifier(pGame, MinimumValue(nCount), MaximumValue(nCount));
	pModifier.ApplyTo(pPlayer);
}

// The player discards nCount cards of their choice (as Amonkhet)
static void DiscardCards(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	int nHand = pPlayer->GetZoneById(ZoneId::Hand)->GetSize();
	if (nCount > nHand)
		nCount = nHand;
	if (nCount <= 0)
		return;

	CZoneModifier pModifier = CZoneModifier(pGame,
		ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(nCount), MaximumValue(nCount), // select cards to discard
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Graveyard, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Discard, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);
}

// Create nCount Treasure tokens for pPlayer
static void CreateTreasure(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(pGame, TREASURE_TOKEN_NAME, TREASURE_TOKEN_ID, nCount);
	pModifier.ApplyTo(pPlayer);
}

// "When this enters, <effect>" with the effect in a resolution callback (as Aether Revolt)
template <class T>
static void AddEnterTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional = false)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "When this leaves the battlefield, <effect>" (as Aether Revolt)
template <class T>
static void AddLeaveTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Exile, ZoneId::Battlefield));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "At the beginning of <your upkeep / your end step>, <effect>" (the condition in a context function)
template <class T>
static CAbility* AddStepTrigger(T* pCard, NodeId node, bool bOptional,
	bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CNode*) const, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard, node));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	if (context)
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

// Exiles the card (until this permanent leaves the battlefield) and remembers it (as Aether Revolt)
static void ExileUntilLeaves(CCountedCardContainer_& exiled, CCard* pCard, CPlayer* pByPlayer)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pByPlayer);
	pModifier.ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Exile && !pCard->GetCardType().IsToken())
		exiled.AddCard(pCard, CardPlacement::Top);
}

// Returns the exiled cards to the battlefield under their owners' control (as Aether Revolt)
static void ReturnExiled(CCountedCardContainer_& exiled, CPlayer* pByPlayer)
{
	while (exiled.GetSize() > 0)
	{
		CCard* pCard = exiled.GetAt(0);
		exiled.RemoveCard(pCard);
		if (pCard->GetZoneId() == ZoneId::Exile)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pByPlayer);
			pModifier.ApplyTo(pCard);
		}
	}
}

// Mill N cards (as Kaladesh)
static void Mill(CPlayer* pPlayer, int nCount)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < nCount && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
}

// Raid: "if you attacked this turn" (as Khans of Tarkir)
static BOOL HasRaid(CPlayer* pPlayer)
{
	return pPlayer->GetAttackCount() >= 1;
}

// "Look at the top N cards of your library. You may reveal a <filter> card from among them and put it into your hand.
// Put the rest on the bottom of your library in any order." (as Mitotic Manipulation in Mirrodin Besieged)
static void LookTopToHand(CGame* pGame, CPlayer* pPlayer, int nCount, const CCardFilter* pFilter)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	if (nCount > pLibrary->GetSize())
		nCount = pLibrary->GetSize();
	if (nCount <= 0)
		return;

	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, nCount, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // up to one card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		pFilter, // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player

	// the rest go to the bottom of the library
	pModifier.SetReorderInformation(
		true,
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Bottom);

	pModifier.ApplyTo(pPlayer);
}

// The number of creatures pPlayer controls
static int CountCreatures(CGame* pGame, CPlayer* pPlayer)
{
	CCountedCardContainer creatures;
	GetCreatures(pGame, pPlayer, TRUE, creatures);
	return creatures.GetSize();
}

// Exiles every card in every graveyard (as Hour of Devastation)
static void ExileAllGraveyards(CGame* pGame, CPlayer* pByPlayer)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pByPlayer);
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);

		// Copy the cards first: the zone changes while they are moved
		CCountedCardContainer cards;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
			cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
				pModifier.ApplyTo(cards.GetAt(i));
	}
}

static int CountCounters(const CCard* pCard, LPCTSTR strCounter)
{
	const Counter* pCounter = pCard->GetCounterContainer()->GetCounter(strCounter);
	return pCounter ? pCounter->GetCount() : 0;
}

// "pCard1 fights pCard2" (each deals damage equal to its power to the other, as Amonkhet)
static void Fight(CCard* pCard1, CCard* pCard2)
{
	CCreatureCard* pCreature1 = dynamic_cast<CCreatureCard*>(pCard1);
	CCreatureCard* pCreature2 = dynamic_cast<CCreatureCard*>(pCard2);
	if (!pCreature1 || !pCreature2 || pCreature1 == pCreature2 ||
		pCreature1->GetZoneId() != ZoneId::Battlefield || pCreature2->GetZoneId() != ZoneId::Battlefield)
		return;

	int nPower1 = GET_INTEGER(pCreature1->GetPower());
	int nPower2 = GET_INTEGER(pCreature2->GetPower());
	DealDamageToCreature(pCreature1, pCreature2, nPower1);
	DealDamageToCreature(pCreature2, pCreature1, nPower2);
}

// Searches pPlayer's graveyard and then library for a card named strName and puts it into their hand (shuffling the
// library if it was searched), as Amonkhet
static void SearchNamedCardToHand(CPlayer* pPlayer, LPCTSTR strName)
{
	ZoneId zones[] = { ZoneId::Graveyard, ZoneId::Library };
	for (int z = 0; z < _countof(zones); ++z)
	{
		CZone* pZone = pPlayer->GetZoneById(zones[z]);
		for (int i = 0; i < pZone->GetSize(); ++i)
		{
			CCard* pCard = pZone->GetAt(i);
			if (pCard->GetPrintedCardName() == strName)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(zones[z], ZoneId::Hand, TRUE, MoveType::Others);
				pModifier.ApplyTo(pCard);
				if (zones[z] == ZoneId::Library)
					pZone->Shuffle();
				return;
			}
		}
	}
	pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

// "Cast only if <condition>" (pCard's member returning BOOL, as Amonkhet)
template <class T>
static void AddPlayableIf(T* pCard, CAbility* pAbility, BOOL (T::*condition)(BOOL))
{
	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(pAbility, CPlayableIfTrait::PlayableCallback(pCard, condition)));
	pAbility->Add(cpTrait.GetPointer());
}

// The X of the spell (the extra mana paid)
static int GetX(CAbilityAction* pAction)
{
	int nX = pAction->GetCostConfigEntry().GetExtraValue();
	return nX < 0 ? -nX : nX;
}

// A damage spell to any target (creatures and players; it can't target planeswalkers)
static CTargetChgLifeSpell* AddDamageSpell(CCard* pCard, LPCTSTR strCost, int nDamage, CardComparer* pComparer, BOOL bPlayers)
{
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(pCard, AbilityType::Instant,
			strCost,
			pComparer, bPlayers,
			Life(-nDamage), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A destroy spell
static CTargetMoveCardSpell* AddDestroySpell(CCard* pCard, LPCTSTR strCost, CardComparer* pComparer)
{
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(pCard, AbilityType::Instant,
			strCost,
			pComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A spell on target creature (bOwn: a creature you control) whose callback does the effect
template <class T>
static CTargetSpell* AddCreatureSpell(T* pCard, LPCTSTR strCost, BOOL bOwn, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(pCard, AbilityType::Instant,
			strCost,
			new AnyCreatureComparer, FALSE));

	if (bOwn)
		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// The card gains the card keyword until end of turn
static void GainCardKeyword(CCard* pCard, CardKeyword keyword)
{
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier = CCardKeywordModifier(keyword, TRUE);
		pModifier.ApplyTo(pCard);
	}
}

// Enrage: "Whenever this creature is dealt damage, <effect>" (as Jackal Pup in Tempest; the context function checks that
// the damaged creature is this one)
template <class T>
static void AddEnrageTrigger(T* pCard,
	bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CCard*, CCreatureCard*, Damage) const,
	bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
						   CWhenDamageDealt::CreatureEventCallback, &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever this creature attacks, <effect>"
template <class T>
static void AddSelfAttackTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional = false)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "When this creature enters, <effect on another target creature>" (the callback does the effect and returns false)
template <class T>
static CTargeting* AddEnterTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional, Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

// "This creature has <keyword> as long as you control a Dinosaur" (as Thresher Lizard in Amonkhet)
static void AddDinosaurKeyword(CCard* pCard, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			Power(+0), Life(+0), keyword));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Pay N life: This creature gains <keyword> until end of turn."
template <class T>
static void AddPayLifeKeywordAbility(T* pCard, int nLife, LPCTSTR strText, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("")));

	cpAbility->AddPayLifeDeltaCost(Life(-nLife));
	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	pCard->AddAbility(cpAbility.GetPointer());
}

// Create a 1/1 white Vampire token with lifelink
static void CreateVampire(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(pGame, VAMPIRE_E_TOKEN_NAME, VAMPIRE_E_TOKEN_ID, nCount);
	pModifier.ApplyTo(pPlayer);
}

// "Whenever a creature you control explores, <effect>" (listens to EXPLORE_TRIGGER_ID, as Shadowed Caravel)
template <class T>
static void AddWheneverExploresTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetTriggerIndex(EXPLORE_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(pCard));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// Puts a +1/+1 counter on the card (if it's on the battlefield)
static void AddPlusCounter(CCard* pCard, int nCount = 1)
{
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), nCount);
		pModifier.ApplyTo(pCard);
	}
}

// "pSource deals nDamage damage to each opponent of pPlayer"
static void DamageEachOpponent(CCard* pSource, CPlayer* pPlayer, int nDamage)
{
	CGame* pGame = pSource->GetGame();
	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		if (pGame->GetPlayer(ip) != pPlayer)
			pModifier.ApplyTo(pGame->GetPlayer(ip));
}

// "pSource deals nDamage damage to the target of the action" (a creature or a player)
static void DealDamageToTarget(CCard* pSource, CAbilityAction* pAction, int nDamage)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}
	else
		DealDamageToCreature(pSource, pAction->GetAssociatedCard(), nDamage);
}

// "This creature gets +N/+0 and has <keyword> as long as you control another <type>"
static void AddAnotherTypeBonus(CCard* pCard, const CreatureType& type, int nPower, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			Power(nPower), Life(+0), keyword));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new AndCardComparer(new CreatureTypeComparer(type, false),
		new NegateCardComparer(new SpecificCardComparer(pCard))));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	pCard->AddAbility(cpAbility.GetPointer());
}

// "{cost}: This creature gets +N/+0 until end of turn." (the callback pumps the creature)
template <class T>
static void AddPumpAbility(T* pCard, LPCTSTR strCost, LPCTSTR strText, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			strCost));

	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	pCard->AddAbility(cpAbility.GetPointer());
}

static BOOL ControlsDinosaur(CPlayer* pPlayer)
{
	CCardFilter dinosaurs(_T("a Dinosaur"), _T("Dinosaurs"), new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false));
	return dinosaurs.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

// "When this creature dies, <effect>" (as Amonkhet)
template <class T>
static void AddDiesTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// Each opponent of pPlayer loses nLife life (bGain: and pPlayer gains that much)
static void DrainOpponents(CCard* pSource, CPlayer* pPlayer, int nLife, BOOL bGain)
{
	if (nLife <= 0)
		return;

	CGame* pGame = pSource->GetGame();
	CLifeModifier pModifier = CLifeModifier(Life(-nLife), pSource, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		if (pGame->GetPlayer(ip) != pPlayer)
			pModifier.ApplyTo(pGame->GetPlayer(ip));

	if (bGain)
		GainLife(pSource, pPlayer, nLife);
}

// "Draw a card. If you do, discard a card."
static void Loot(CGame* pGame, CPlayer* pPlayer)
{
	DrawCards(pGame, pPlayer, 1);
	DiscardCards(pGame, pPlayer, 1);
}

// "This creature gets +N/+0 and has <keyword> as long as you control a <planeswalker type> planeswalker"
static void AddPlaneswalkerBonus(CCard* pCard, PlaneswalkerType type, int nPower, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			Power(nPower), Life(+0), keyword));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(type));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Other <type> creatures you control get +N/+N and have <keyword>"
static void AddOtherTypeLord(CCard* pCard, const CreatureType& type, int nBonus, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new AndCardComparer(new CreatureTypeComparer(type, false), new NegateCardComparer(new SpecificCardComparer(pCard))),
			Power(nBonus), Life(nBonus), keyword));

	cpAbility->SetAffectControllerCardsOnly();
	pCard->AddAbility(cpAbility.GetPointer());
}

// A loyalty ability on target player (the callback does the effect and returns false)
template <class T>
static void AddPlayerLoyaltyAbility(T* pCard, int nLoyalty, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(pCard,
			_T(""),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// A loyalty ability without targets (the callback does the effect)
template <class T>
static void AddLoyaltyAbility(T* pCard, int nLoyalty, LPCTSTR strText, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("")));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "pSource deals nDamage damage to pPlayer"
static void DealDamageToPlayer(CCard* pSource, CPlayer* pPlayer, int nDamage)
{
	if (!pPlayer || nDamage <= 0)
		return;

	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pPlayer);
}

// "{T}: Add one mana of any color." on a land
static void AddAnyColorManaAbility(CCard* pCard)
{
	AddTapManaAbility(pCard, WHITE_MANA_TEXT);
	AddTapManaAbility(pCard, BLUE_MANA_TEXT);
	AddTapManaAbility(pCard, BLACK_MANA_TEXT);
	AddTapManaAbility(pCard, RED_MANA_TEXT);
	AddTapManaAbility(pCard, GREEN_MANA_TEXT);
}

// "At the beginning of your end step, if you didn't attack with a creature this turn, sacrifice this Aura."
static void SacrificeSelf(CCard* pCard, CPlayer* pController)
{
	if (pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pController);
	pModifier.ApplyTo(pCard);
}

// A triggered ability with a target at the beginning of a step of your turn (as Tezzeret the Schemer Emblem)
template <class T>
static CTargeting* AddStepTargetTrigger(T* pCard, NodeId node,
	bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CNode*) const, bool (T::*callback)(CAbilityAction*),
	Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard, node));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	if (context)
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

// The creature has first strike, double strike, vigilance, or haste
static BOOL HasMettleKeyword(CCreatureCard* pCreature)
{
	CCreatureKeyword* pKeyword = pCreature->GetCreatureKeyword();
	return pKeyword->FirstStrike() || pKeyword->DoubleStrike() || pKeyword->Vigilance() || pKeyword->Haste();
}

// "Whenever this creature attacks, <effect on target creature>" (the callback does the effect and returns false)
template <class T>
static CTargeting* AddSelfAttackTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

// Enrage with a target: "Whenever this creature is dealt damage, <effect on target creature>" (the context checks that
// the damaged creature is this one; the callback does the effect and returns false)
template <class T>
static CTargeting* AddEnrageTargetTrigger(T* pCard,
	bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CCard*, CCreatureCard*, Damage) const,
	bool (T::*callback)(CAbilityAction*), Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenDamageDealt,
								 CWhenDamageDealt::CreatureEventCallback, &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

// "This creature gets +N/+0 and has <keyword> as long as you have the city's blessing"
static void AddBlessingBonus(CCard* pCard, int nPower, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new AndCardComparer(new SpecificCardComparer(pCard), new CityBlessingComparer),
			Power(nPower), Life(+0), keyword));

	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever another <type> you control enters, <effect>" (the callback does the effect; bTarget: on a target creature
// of the type that you control, and the callback returns false)
template <class T>
static void AddAnotherTypeEntersTrigger(T* pCard, const CreatureType& type, BOOL bTarget, bool (T::*callback)(CAbilityAction*))
{
	if (bTarget)
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(type, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(type, false));
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
		pCard->AddAbility(cpAbility.GetPointer());
	}
	else
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(type, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
		pCard->AddAbility(cpAbility.GetPointer());
	}
}

// Search the library for a card, then shuffle and put it on top (the library is shuffled first; the same result)
static void SearchToTop(CGame* pGame, CPlayer* pPlayer, const CCardFilter* pFilter)
{
	pPlayer->GetZoneById(ZoneId::Library)->Shuffle();

	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		pFilter, // what cards
		ZoneId::Library, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);
}

// The number of permanents of the type that the player controls
static int CountType(CPlayer* pPlayer, const CreatureType& type)
{
	CCardFilter filter(_T("a creature"), _T("creatures"), new CreatureTypeComparer(type, false));
	return filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
}

// "Whenever another creature you control dies, <effect>" (the context, optional, checks a condition)
template <class T>
static void AddAnotherCreatureDiesTrigger(T* pCard,
	bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CCard*, CZone*, CZone*, CPlayer*, MoveType) const,
	bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	if (context)
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}


CTransformArtifactBase::CTransformArtifactBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText,
	LPCTSTR strBackName, CardType cardType)
	: CDoubleFacedInPlaySpellCard(pGame, strCardName, cardType, nID,
		strCostText, strBackName, AbilityType::Artifact)
{
	// The back face is a land (it isn't an artifact)
	AddCardModifier(new CCardTypeModifier(CardType::NonbasicLand, FALSE, CardType::Artifact));
}

void CTransformArtifactBase::SetFace(CAbility* pAbility, BOOL bFirstFace)
{
	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(pAbility,
			CPlayableIfTrait::PlayableCallback(this,
				bFirstFace ? &CDoubleFacedInPlaySpellCard::CanPlayFirstFace : &CDoubleFacedInPlaySpellCard::CanPlaySecondFace)));
	pAbility->Add(cpTrait.GetPointer());
}

void CTransformArtifactBase::AddBackManaAbility(LPCTSTR strMana)
{
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, strMana));
	cpAbility->AddTapCost();
	SetFace(cpAbility.GetPointer(), FALSE);
	AddAbility(cpAbility.GetPointer());
}

void CTransformArtifactBase::DoTransform()
{
	if (IsFirstFaceInPlay())
	{
		CFaceTransformModifier pModifier = CFaceTransformModifier();
		pModifier.ApplyTo(this);
	}
}

BOOL CTransformArtifactBase::IsFirstFaceInPlay() const
{
	return GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced();
}


CTransformEnchantmentBase::CTransformEnchantmentBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText,
	LPCTSTR strBackName)
	: CDoubleFacedInPlaySpellCard(pGame, strCardName, CardType::_LegendaryGlobalEnchantment, nID,
		strCostText, strBackName, AbilityType::Enchantment)
{
	// The back face is a legendary land (it isn't an enchantment)
	AddCardModifier(new CCardTypeModifier(CardType::NonbasicLand, FALSE, CardType::GlobalEnchantment));
}

void CTransformEnchantmentBase::SetFace(CAbility* pAbility, BOOL bFirstFace)
{
	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(pAbility,
			CPlayableIfTrait::PlayableCallback(this,
				bFirstFace ? &CDoubleFacedInPlaySpellCard::CanPlayFirstFace : &CDoubleFacedInPlaySpellCard::CanPlaySecondFace)));
	pAbility->Add(cpTrait.GetPointer());
}

void CTransformEnchantmentBase::AddBackManaAbility(LPCTSTR strMana)
{
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, strMana));
	cpAbility->AddTapCost();
	SetFace(cpAbility.GetPointer(), FALSE);
	AddAbility(cpAbility.GetPointer());
}

void CTransformEnchantmentBase::DoTransform()
{
	if (IsFirstFaceInPlay())
	{
		CFaceTransformModifier pModifier = CFaceTransformModifier();
		pModifier.ApplyTo(this);
	}
}

BOOL CTransformEnchantmentBase::IsFirstFaceInPlay() const
{
	return GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced();
}

//____________________________________________________________________________
//
counted_ptr<CCard> CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID)
{
	counted_ptr<CCard> cpCard;
	do
	{
		DEFINE_CARD(CCabalStrongholdCard);
		DEFINE_CARD(CMemorialToFollyCard);
		DEFINE_CARD(CMemorialToGeniusCard);
		DEFINE_CARD(CMemorialToGloryCard);
		DEFINE_CARD(CMemorialToUnityCard);
		DEFINE_CARD(CMemorialToWarCard);
		DEFINE_CARD(CZhalfirinVoidCard);
		DEFINE_CARD(CChandraBoldPyromancerCard);
		DEFINE_CARD(CJayaBallardCard);
		DEFINE_CARD(CKarnScionOfUrzaCard);
		DEFINE_CARD(CTeferiHeroOfDominariaCard);
		DEFINE_CARD(CTeferiTimebenderCard);
		DEFINE_CARD(CArcaneFlightCard);
		DEFINE_CARD(CChainersTormentCard);
		DEFINE_CARD(CCuratorsWardCard);
		DEFINE_CARD(CDemonicVigorCard);
		DEFINE_CARD(CDubCard);
		DEFINE_CARD(CFallOfTheThranCard);
		DEFINE_CARD(CFrenziedRageCard);
		DEFINE_CARD(CFungalPlotsCard);
		DEFINE_CARD(CHaphazardBombardmentCard);
		DEFINE_CARD(CHistoryOfBenaliaCard);
		DEFINE_CARD(CInBolassClutchesCard);
		DEFINE_CARD(COathOfTeferiCard);
		DEFINE_CARD(COnSerrasWingsCard);
		DEFINE_CARD(CPhyrexianScripturesCard);
		DEFINE_CARD(CRiteOfBelzenlokCard);
		DEFINE_CARD(CSealAwayCard);
		DEFINE_CARD(CSongOfFreyaliseCard);
		DEFINE_CARD(CTheAntiquitiesWarCard);
		DEFINE_CARD(CTheEldestRebornCard);
		DEFINE_CARD(CTheFirstEruptionCard);
		DEFINE_CARD(CTheFlameOfKeldCard);
		DEFINE_CARD(CTheMendingOfDominariaCard);
		DEFINE_CARD(CTheMirariConjectureCard);
		DEFINE_CARD(CTimeOfIceCard);
		DEFINE_CARD(CTriumphOfGerrardCard);
		DEFINE_CARD(CBlackbladeReforgedCard);
		DEFINE_CARD(CBloodtallowCandleCard);
		DEFINE_CARD(CForebearsBladeCard);
		DEFINE_CARD(CJoustingLanceCard);
		DEFINE_CARD(CMoxAmberCard);
		DEFINE_CARD(CNavigatorsCompassCard);
		DEFINE_CARD(CPowerstoneShardCard);
		DEFINE_CARD(CShortSwordCard);
		DEFINE_CARD(CSorcerersWandCard);
		DEFINE_CARD(CThranTemporalGatewayCard);
		DEFINE_CARD(CUrzasTomeCard);
		DEFINE_CARD(CWeatherlightCard);
		DEFINE_CARD(CAdventurousImpulseCard);
		DEFINE_CARD(CBoardTheWeatherlightCard);
		DEFINE_CARD(CBrokenBondCard);
		DEFINE_CARD(CCallTheCavalryCard);
		DEFINE_CARD(CChandrasOutburstCard);
		DEFINE_CARD(CDivestCard);
		DEFINE_CARD(CEviscerateCard);
		DEFINE_CARD(CFieryInterventionCard);
		DEFINE_CARD(CFightWithFireCard);
		DEFINE_CARD(CFinalPartingCard);
		DEFINE_CARD(CGoblinBarrageCard);
		DEFINE_CARD(CGrowFromTheAshesCard);
		DEFINE_CARD(CJayasImmolatingInfernoCard);
		DEFINE_CARD(CKamahlsDruidicVowCard);
		DEFINE_CARD(CKarnsTemporalSunderingCard);
		DEFINE_CARD(CPrimevalsGloriousRebirthCard);
		DEFINE_CARD(CSaprolingMigrationCard);
		DEFINE_CARD(CSeismicShiftCard);
		DEFINE_CARD(CSettleTheScoreCard);
		DEFINE_CARD(CSoulSalvageCard);
		DEFINE_CARD(CSylvanAwakeningCard);
		DEFINE_CARD(CTemporalMachinationsCard);
		DEFINE_CARD(CUrzasRuinousBlastCard);
		DEFINE_CARD(CWarlordsFuryCard);
		DEFINE_CARD(CWeightOfMemoryCard);
		DEFINE_CARD(CYawgmothsVileOfferingCard);
		DEFINE_CARD(CAdamantWillCard);
		DEFINE_CARD(CAncientAnimusCard);
		DEFINE_CARD(CArborArmamentCard);
		DEFINE_CARD(CBefuddleCard);
		DEFINE_CARD(CBlessedLightCard);
		DEFINE_CARD(CBlessingOfBelzenlokCard);
		DEFINE_CARD(CBlinkOfAnEyeCard);
		DEFINE_CARD(CCastDownCard);
		DEFINE_CARD(CChargeCard);
		DEFINE_CARD(CDarkBargainCard);
		DEFINE_CARD(CFerventStrikeCard);
		DEFINE_CARD(CFungalInfectionCard);
		DEFINE_CARD(CGiftOfGrowthCard);
		DEFINE_CARD(CHealingGraceCard);
		DEFINE_CARD(CInvokeTheDivineCard);
		DEFINE_CARD(CPierceTheSkyCard);
		DEFINE_CARD(CRadiatingLightningCard);
		DEFINE_CARD(CRunAmokCard);
		DEFINE_CARD(CShivanFireCard);
		DEFINE_CARD(CSporeSwarmCard);
		DEFINE_CARD(CUnwindCard);
		DEFINE_CARD(CViciousOfferingCard);
		DEFINE_CARD(CWildOnslaughtCard);
		DEFINE_CARD(CWizardsLightningCard);
		DEFINE_CARD(CWizardsRetortCard);
		DEFINE_CARD(CAvenSentryCard);
		DEFINE_CARD(CBairdStewardOfArgiveCard);
		DEFINE_CARD(CBenalishHonorGuardCard);
		DEFINE_CARD(CBenalishMarshalCard);
		DEFINE_CARD(CDanithaCapashenParagonCard);
		DEFINE_CARD(CDaringArchaeologistCard);
		DEFINE_CARD(CDauntlessBodyguardCard);
		DEFINE_CARD(CDAvenantTrapperCard);
		DEFINE_CARD(CEvraHalcyonWitnessCard);
		DEFINE_CARD(CExcavationElephantCard);
		DEFINE_CARD(CKnightOfGraceCard);
		DEFINE_CARD(CKnightOfNewBenaliaCard);
		DEFINE_CARD(CKwendePrideOfFemerefCard);
		DEFINE_CARD(CLyraDawnbringerCard);
		DEFINE_CARD(CMesaUnicornCard);
		DEFINE_CARD(CPegasusCourserCard);
		DEFINE_CARD(CSanctumSpiritCard);
		DEFINE_CARD(CSergeantAtArmsCard);
		DEFINE_CARD(CSerraDiscipleCard);
		DEFINE_CARD(CShalaiVoiceOfPlentyCard);
		DEFINE_CARD(CTesharAncestorsApostleCard);
		DEFINE_CARD(CBalothGorgerCard);
		DEFINE_CARD(CElfhameDruidCard);
		DEFINE_CARD(CGaeasProtectorCard);
		DEFINE_CARD(CGrunnTheLonelyKingCard);
		DEFINE_CARD(CKrosanDruidCard);
		DEFINE_CARD(CLlanowarEnvoyCard);
		DEFINE_CARD(CLlanowarScoutCard);
		DEFINE_CARD(CMammothSpiderCard);
		DEFINE_CARD(CMarwynTheNurturerCard);
		DEFINE_CARD(CMultaniYavimayasAvatarCard);
		DEFINE_CARD(CPrimordialWurmCard);
		DEFINE_CARD(CSporecrownThallidCard);
		DEFINE_CARD(CSteelLeafChampionCard);
		DEFINE_CARD(CTerritorialAllosaurusCard);
		DEFINE_CARD(CUntamedKavuCard);
		DEFINE_CARD(CYavimayaSapherdCard);
		DEFINE_CARD(CBloodstoneGoblinCard);
		DEFINE_CARD(CChampionOfTheFlameCard);
		DEFINE_CARD(CFirefistAdeptCard);
		DEFINE_CARD(CGhituChroniclerCard);
		DEFINE_CARD(CGhituJourneymageCard);
		DEFINE_CARD(CGhituLavarunnerCard);
		DEFINE_CARD(CGoblinChainwhirlerCard);
		DEFINE_CARD(CKarplusanHoundCard);
		DEFINE_CARD(CKeldonOverseerCard);
		DEFINE_CARD(CKeldonRaiderCard);
		DEFINE_CARD(CKeldonWarcallerCard);
		DEFINE_CARD(COrcishVandalCard);
		DEFINE_CARD(CPyromanticPilgrimCard);
		DEFINE_CARD(CRampagingCyclopsCard);
		DEFINE_CARD(CSqueeTheImmortalCard);
		DEFINE_CARD(CTwoHeadedGiantCard);
		DEFINE_CARD(CValdukKeeperOfTheFlameCard);
		DEFINE_CARD(CVerixBladewingCard);
		DEFINE_CARD(CWarcryPhoenixCard);
		DEFINE_CARD(CCabalEvangelCard);
		DEFINE_CARD(CCabalPaladinCard);
		DEFINE_CARD(CCaligoSkinWitchCard);
		DEFINE_CARD(CDeathbloomThallidCard);
		DEFINE_CARD(CDemonlordBelzenlokCard);
		DEFINE_CARD(CDreadShadeCard);
		DEFINE_CARD(CDrudgeSentinelCard);
		DEFINE_CARD(CFeralAbominationCard);
		DEFINE_CARD(CJosuVessLichKnightCard);
		DEFINE_CARD(CKazarovSengirPurebloodCard);
		DEFINE_CARD(CKnightOfMaliceCard);
		DEFINE_CARD(CLingeringPhantomCard);
		DEFINE_CARD(CRatColonyCard);
		DEFINE_CARD(CStrongholdConfessorCard);
		DEFINE_CARD(CThallidOmnivoreCard);
		DEFINE_CARD(CThallidSoothsayerCard);
		DEFINE_CARD(CTorgaarFamineIncarnateCard);
		DEFINE_CARD(CUrgorosTheEmptyOneCard);
		DEFINE_CARD(CWhisperBloodLiturgistCard);
		DEFINE_CARD(CWindgraceAcolyteCard);
		DEFINE_CARD(CYargleGluttonOfUrborgCard);
		DEFINE_CARD(CAcademyDrakeCard);
		DEFINE_CARD(CAcademyJourneymageCard);
		DEFINE_CARD(CArtificersAssistantCard);
		DEFINE_CARD(CCloudreaderSphinxCard);
		DEFINE_CARD(CColdWaterSnapperCard);
		DEFINE_CARD(CDiligentExcavatorCard);
		DEFINE_CARD(CHomaridExplorerCard);
		DEFINE_CARD(CMerfolkTricksterCard);
		DEFINE_CARD(CNaruMehaMasterWizardCard);
		DEFINE_CARD(CRelicRunnerCard);
		DEFINE_CARD(CSentinelOfThePearlTridentCard);
		DEFINE_CARD(CSlinnVodaTheRisingDeepCard);
		DEFINE_CARD(CTempestDjinnCard);
		DEFINE_CARD(CTetsukoUmezawaFugitiveCard);
		DEFINE_CARD(CTolarianScholarCard);
		DEFINE_CARD(CVodalianArcanistCard);
		DEFINE_CARD(CZahidDjinnOfTheLampCard);
		DEFINE_CARD(CAdelizTheCinderWindCard);
		DEFINE_CARD(CAmaranthineWallCard);
		DEFINE_CARD(CArvadTheCursedCard);
		DEFINE_CARD(CAryelKnightOfWindgraceCard);
		DEFINE_CARD(CDarigaazReincarnatedCard);
		DEFINE_CARD(CGarnaTheBloodflameCard);
		DEFINE_CARD(CGrandWarlordRadhaCard);
		DEFINE_CARD(CGuardiansOfKoilosCard);
		DEFINE_CARD(CHallarTheFirefletcherCard);
		DEFINE_CARD(CHowlingGolemCard);
		DEFINE_CARD(CJhoirasFamiliarCard);
		DEFINE_CARD(CJhoiraWeatherlightCaptainCard);
		DEFINE_CARD(CJodahArchmageEternalCard);
		DEFINE_CARD(CMishrasSelfReplicatorCard);
		DEFINE_CARD(CNiambiFaithfulHealerCard);
		DEFINE_CARD(CPardicWandererCard);
		DEFINE_CARD(CRaffCapashenShipsMageCard);
		DEFINE_CARD(CShannaSisaysLegacyCard);
		DEFINE_CARD(CSkitteringSurveyorCard);
		DEFINE_CARD(CSlimefootTheStowawayCard);
		DEFINE_CARD(CSparringConstructCard);
		DEFINE_CARD(CTatyovaBenthicDruidCard);
		DEFINE_CARD(CTeferisSentinelCard);
		DEFINE_CARD(CTianaShipsCaretakerCard);
		DEFINE_CARD(CTraxosScourgeOfKroogCard);
		DEFINE_CARD(CVoltaicServantCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

#define SOLDIER_O_TOKEN_NAME	_T("Soldier (O)")
#define SOLDIER_O_TOKEN_ID		62060

CCabalStrongholdCard::CCabalStrongholdCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Cabal Stronghold"), nID)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {3}, {T}: Add {B} for each basic Swamp you control.
	// Not implemented: a mana ability can't add a variable amount of mana
}

CMemorialToFollyCard::CMemorialToFollyCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Memorial to Folly"), nID)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {B}.
	AddTapManaAbility(this, BLACK_MANA_TEXT);

	// {2}{B}, {T}, Sacrifice this land: Return target creature card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CMemorialToGeniusCard::CMemorialToGeniusCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Memorial to Genius"), nID)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {U}.
	AddTapManaAbility(this, BLUE_MANA_TEXT);

	// {4}{U}, {T}, Sacrifice this land: Draw two cards.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("4") BLUE_MANA_TEXT, 2));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CMemorialToGloryCard::CMemorialToGloryCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Memorial to Glory"), nID)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {W}.
	AddTapManaAbility(this, WHITE_MANA_TEXT);

	// {3}{W}, {T}, Sacrifice this land: Create two 1/1 white Soldier creature tokens.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("3") WHITE_MANA_TEXT,
			SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID,
			2));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CMemorialToUnityCard::CMemorialToUnityCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Memorial to Unity"), nID)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {G}.
	AddTapManaAbility(this, GREEN_MANA_TEXT);

	// {2}{G}, {T}, Sacrifice this land: Look at the top five cards of your library. You may reveal a creature card from
	// among them and put it into your hand. Then put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") GREEN_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Look at the top five cards of your library for a creature card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMemorialToUnityCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

bool CMemorialToUnityCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, CCardFilter::GetFilter(_T("creatures")));
	return true;
}

CMemorialToWarCard::CMemorialToWarCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Memorial to War"), nID)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {R}.
	AddTapManaAbility(this, RED_MANA_TEXT);

	// {4}{R}, {T}, Sacrifice this land: Destroy target land.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("4") RED_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CZhalfirinVoidCard::CZhalfirinVoidCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Zhalfirin Void"), nID)
{
	// When this land enters, scry 1.
	AddEnterTrigger(this, &CZhalfirinVoidCard::BeforeScry);

	// {T}: Add {C}.
	AddColorlessManaAbility(this);
}

bool CZhalfirinVoidCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier pModifier = CScryModifier(GetGame(), 1, this);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

#define SILVER_COUNTER		_T("silver counter")
#define CONSTRUCT_C_TOKEN_NAME	_T("Construct (C)")
#define CONSTRUCT_C_TOKEN_ID	55109
#define TEFERI_HERO_EFFECT_NAME	_T("Teferi, Hero of Dominaria Effect")
#define TEFERI_HERO_EFFECT_ID	61153
#define TEFERI_HERO_EMBLEM_NAME	_T("Teferi, Hero of Dominaria Emblem")
#define TEFERI_HERO_EMBLEM_ID	61154

CChandraBoldPyromancerCard::CChandraBoldPyromancerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Bold Pyromancer"), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Chandra, 5)
{
	// +1: Add {R}{R}. Chandra deals 2 damage to target player.
	AddPlayerLoyaltyAbility(this, +1, &CChandraBoldPyromancerCard::BeforeMana);

	{
		// -3: Chandra deals 3 damage to target creature or planeswalker.
		// Note: it can't target planeswalkers
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE,
				Life(-3), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -7: Chandra deals 10 damage to target player and each creature and planeswalker they control.
	// (the damage to the planeswalkers removes loyalty counters)
	AddPlayerLoyaltyAbility(this, -7, &CChandraBoldPyromancerCard::BeforeUltimate);
}

bool CChandraBoldPyromancerCard::BeforeMana(CAbilityAction* pAction)
{
	CManaPoolModifier pMana = CManaPoolModifier(CManaPoolModifier::Operation::Add,
		CManaPool::CManaPool(RED_MANA_TEXT RED_MANA_TEXT));
	pMana.ApplyTo(pAction->GetController());

	DealDamageToPlayer(this, pAction->GetAssociatedPlayer(), 2);
	return false;
}

bool CChandraBoldPyromancerCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	DealDamageToPlayer(this, pPlayer, 10);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 10);

	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer planeswalkers;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsPlaneswalker())
			planeswalkers.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	CCardCounterModifier pLoyalty = CCardCounterModifier(LOYALTY_COUNTER, -10);
	for (int i = 0; i < planeswalkers.GetSize(); ++i)
		pLoyalty.ApplyTo(planeswalkers.GetAt(i));
	return false;
}

CJayaBallardCard::CJayaBallardCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jaya Ballard"), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Jaya, 5)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CJayaBallardCard::OnCardsSelected))
{
	// +1: Add {R}{R}{R}. Spend this mana only to cast instant or sorcery spells.
	// Note: the mana can be spent on anything (there is no restricted mana)
	AddLoyaltyAbility(this, +1, _T("Add {R}{R}{R}. Activates"), &CJayaBallardCard::BeforeMana);

	// +1: Discard up to three cards, then draw that many cards.
	AddLoyaltyAbility(this, +1, _T("Discard up to three cards, then draw that many cards. Activates"), &CJayaBallardCard::BeforeDiscard);

	// -8: You get an emblem with "You may cast instant and sorcery spells from your graveyard. If a spell cast this way
	// would be put into your graveyard, exile it instead."
	// Not implemented: spells can't be cast from the graveyard by an emblem
}

bool CJayaBallardCard::BeforeMana(CAbilityAction* pAction)
{
	CManaPoolModifier pMana = CManaPoolModifier(CManaPoolModifier::Operation::Add,
		CManaPool::CManaPool(RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT));
	pMana.ApplyTo(pAction->GetController());
	return true;
}

bool CJayaBallardCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, entries.size() < 3 ? (int)entries.size() : 3, this, pController);
	return true;
}

void CJayaBallardCard::OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	int nDiscarded = 0;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Hand)
				continue;
			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() != ZoneId::Hand)
				++nDiscarded;
		}

	if (nDiscarded > 0)
		DrawCards(GetGame(), pSelectionPlayer, nDiscarded);
}

CKarnScionOfUrzaCard::CKarnScionOfUrzaCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Karn, Scion of Urza"), nID,
		_T("4"),
		PlaneswalkerType::Karn, 5)
	, m_RevealedSelection(pGame, CSelectionSupport::SelectionCallback(this, &CKarnScionOfUrzaCard::OnRevealedSelected))
	, m_SilverSelection(pGame, CSelectionSupport::SelectionCallback(this, &CKarnScionOfUrzaCard::OnSilverSelected))
{
	// +1: Reveal the top two cards of your library. An opponent chooses one of them. Put that card into your hand and
	// exile the other with a silver counter on it.
	AddLoyaltyAbility(this, +1, _T("Reveal the top two cards of your library; an opponent chooses one for your hand. Activates"), &CKarnScionOfUrzaCard::BeforeReveal);

	// -1: Put a card you own with a silver counter on it from exile into your hand.
	AddLoyaltyAbility(this, -1, _T("Put a card with a silver counter on it from exile into your hand. Activates"), &CKarnScionOfUrzaCard::BeforeReturn);

	{
		// -2: Create a 0/0 colorless Construct artifact creature token with "This token gets +1/+1 for each artifact
		// you control."
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				CONSTRUCT_C_TOKEN_NAME, CONSTRUCT_C_TOKEN_ID,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKarnScionOfUrzaCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	int nCount = pLibrary->GetSize() < 2 ? pLibrary->GetSize() : 2;
	if (nCount == 0)
		return true;

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < nCount; ++i)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1 - i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s into %s's hand"), pCard->GetCardName(TRUE), pController->GetPlayerName());
		entries.push_back(entry);
	}

	// An opponent chooses (the next player)
	m_RevealedSelection.AddSelectionRequest(entries, 1, 1, this, GetGame()->GetNextPlayer(pController), (DWORD)pController);
	return true;
}

void CKarnScionOfUrzaCard::OnRevealedSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Library)
			continue;

		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pController);
			pModifier.ApplyTo(pCard);
		}
		else
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others, pController);
			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() == ZoneId::Exile)
			{
				CCardCounterModifier pCounter = CCardCounterModifier(SILVER_COUNTER, +1);
				pCounter.ApplyTo(pCard);
			}
		}
	}
}

bool CKarnScionOfUrzaCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pExile = pController->GetZoneById(ZoneId::Exile);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pExile->GetSize(); ++i)
	{
		CCard* pCard = pExile->GetAt(i);
		if (pCard->GetOwner() != pController || CountCounters(pCard, SILVER_COUNTER) == 0)
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s into your hand"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_SilverSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CKarnScionOfUrzaCard::OnSilverSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Exile)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
		}
}

CTeferiHeroOfDominariaCard::CTeferiHeroOfDominariaCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Teferi, Hero of Dominaria"), nID,
		_T("3") WHITE_MANA_TEXT BLUE_MANA_TEXT,
		PlaneswalkerType::Teferi, 4)
{
	// +1: Draw a card. At the beginning of the next end step, untap up to two lands. (the untap is the Teferi, Hero
	// of Dominaria Effect)
	AddLoyaltyAbility(this, +1, _T("Draw a card; at the beginning of the next end step, untap up to two lands. Activates"), &CTeferiHeroOfDominariaCard::BeforeDraw);

	{
		// -3: Put target nonland permanent into its owner's library third from the top.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTeferiHeroOfDominariaCard::BeforeTuck));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: You get an emblem with "Whenever you draw a card, exile target permanent an opponent controls."
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(pGame, TEFERI_HERO_EMBLEM_NAME, TEFERI_HERO_EMBLEM_ID, 1, FALSE, ZoneId::_Effects));
		cpAbility->SetAbilityText(_T("You get an emblem with \"Whenever you draw a card, exile target permanent an opponent controls.\" Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTeferiHeroOfDominariaCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), TEFERI_HERO_EFFECT_NAME, TEFERI_HERO_EFFECT_ID, 1, FALSE, ZoneId::_Effects);
	pModifier.ApplyTo(pController);
	return true;
}

// The permanent goes to the top of its owner's library, then the two cards that were on top go back over it
bool CTeferiHeroOfDominariaCard::BeforeTuck(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CZone* pLibrary = pCard->GetOwner()->GetZoneById(ZoneId::Library);
	CCountedCardContainer above;	// the cards that will be over it (the second from the top first)
	for (int i = 1; i >= 0; --i)
		if (pLibrary->GetSize() > i)
			above.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(pCard);

	if (pCard->GetZoneId() == ZoneId::Library && above.GetSize() > 0)
		pLibrary->ReorderCards(above, CardPlacement::Top);
	return false;
}

CTeferiTimebenderCard::CTeferiTimebenderCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Teferi, Timebender"), nID,
		_T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT,
		PlaneswalkerType::Teferi, 5)
{
	{
		// +2: Untap up to one target artifact or creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Artifact | CardType::Creature, false), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		AddAbility(cpAbility.GetPointer());
	}

	// -3: You gain 2 life and draw two cards.
	AddLoyaltyAbility(this, -3, _T("You gain 2 life and draw two cards. Activates"), &CTeferiTimebenderCard::BeforeDraw);

	{
		// -9: Take an extra turn after this one. (as Time Walk)
		counted_ptr<CActivatedAbility<CPlayerEffectSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CPlayerEffectSpell>>(this,
				_T(""), PlayerEffectType::TimeWalk, FALSE, 1));

		cpAbility->SetAffectControllerOnly();
		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTeferiTimebenderCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	DrawCards(GetGame(), pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (enchantments)

#define KNIGHT_E_TOKEN_NAME				_T("Knight (E)")
#define KNIGHT_E_TOKEN_ID				55046
#define CLERIC_C_TOKEN_NAME				_T("Cleric (C)")
#define CLERIC_C_TOKEN_ID				55110
#define DEMON_F_TOKEN_NAME				_T("Demon (F)")
#define DEMON_F_TOKEN_ID				55111
#define NIGHTMARE_HORROR_A_TOKEN_NAME	_T("Nightmare Horror (A)")
#define NIGHTMARE_HORROR_A_TOKEN_ID		55112
#define ANIMATED_ARTIFACT_A_TOKEN_NAME	_T("Animated Artifact (A)")
#define ANIMATED_ARTIFACT_A_TOKEN_ID	64000
#define AIM_COUNTER						_T("aim counter")

#define SAGA_CHAPTER(n, C, f)	m_Saga.AddChapter(n, CAbility::ResolutionStartedCallback(this, &C::f))

// "pSource deals nDamage damage to each creature" (bWithoutFlying: only to the creatures without flying)
static void DamageEachCreature(CCard* pSource, int nDamage, BOOL bWithoutFlying)
{
	CGame* pGame = pSource->GetGame();
	CCountedCardContainer creatures;
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
			if (pCreature && pCreature->GetCardType().IsCreature() && (!bWithoutFlying || !pCreature->GetCreatureKeyword()->Flying()))
				creatures.AddCard(pCreature, CardPlacement::Top);
		}
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(pSource, creatures.GetAt(i), nDamage);
}

// The player chooses nCount cards matching the filter in a zone and moves them (MinimumValue = MaximumValue = the
// number available, up to nCount)
static void ChooseAndMove(CGame* pGame, CPlayer* pPlayer, ZoneId fromZone, int nMin, int nMax, const CCardFilter* pFilter,
	ZoneId toZone, MoveType moveType)
{
	int nAvailable = pFilter->CountIncluded(pPlayer->GetZoneById(fromZone)->GetCardContainer());
	if (nMax > nAvailable)
		nMax = nAvailable;
	if (nMin > nMax)
		nMin = nMax;
	if (nMax <= 0)
		return;

	CZoneModifier pModifier = CZoneModifier(pGame, fromZone, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(nMin), MaximumValue(nMax),
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		pFilter, // what cards
		toZone, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		moveType, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);
}

//____________________________________________________________________________
//
// Enchantments

CArcaneFlightCard::CArcaneFlightCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Arcane Flight"), nID,
		BLUE_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Flying)
{
	// Enchanted creature gets +1/+1 and has flying.
}

CChainersTormentCard::CChainersTormentCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Chainer's Torment"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - This Saga deals 2 damage to each opponent and you gain 2 life.
	SAGA_CHAPTER(1, CChainersTormentCard, BeforeDrain);
	SAGA_CHAPTER(2, CChainersTormentCard, BeforeDrain);

	// III - Create an X/X black Nightmare Horror creature token, where X is half your life total, rounded up. It deals
	// X damage to you.
	// Note: the token is 0/0 with X +1/+1 counters
	SAGA_CHAPTER(3, CChainersTormentCard, BeforeHorror);
}

bool CChainersTormentCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	GainLife(this, pAction->GetController(), 2);
	return true;
}

bool CChainersTormentCard::BeforeHorror(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nLife = (int)pController->GetLife();
	int nX = nLife > 0 ? (nLife + 1) / 2 : 0;

	CCountedCardContainer tokens;
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), NIGHTMARE_HORROR_A_TOKEN_NAME, NIGHTMARE_HORROR_A_TOKEN_ID, 1,
		false, ZoneId::Battlefield, &tokens);
	pModifier.ApplyTo(pController);

	for (int i = 0; i < tokens.GetSize(); ++i)
	{
		CCard* pToken = tokens.GetAt(i);
		if (nX > 0)
			AddPlusCounter(pToken, nX);
		if (nX > 0)
		{
			CLifeModifier pDamage = CLifeModifier(Life(-nX), pToken, PreventableType::Preventable,
				DamageType::AbilityDamage | DamageType::NonCombatDamage);
			pDamage.ApplyTo(pController);
		}
	}
	return true;
}

CCuratorsWardCard::CCuratorsWardCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Curator's Ward"), nID,
		_T("2") BLUE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Null)
{
	// Enchant permanent. Enchanted permanent has hexproof.
	// Partial: it enchants only creatures
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);

	// When enchanted permanent leaves the battlefield, if it was historic, draw two cards.
	// Not implemented: the Aura doesn't know the permanent it enchanted once it has left
}

CDemonicVigorCard::CDemonicVigorCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Demonic Vigor"), nID,
		BLACK_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Null)
{
	// When enchanted creature dies, return that card to its owner's hand. (the creature in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDemonicVigorCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDemonicVigorCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CDemonicVigorCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard != GetEnchantedOn())
		return false;

	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CDemonicVigorCard::BeforeReturn(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CDubCard::CDubCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Dub"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::FirstStrike)
{
	// Enchanted creature gets +2/+2, has first strike, and is a Knight in addition to its other types.
	// Partial: the creature doesn't become a Knight
}

CFallOfTheThranCard::CFallOfTheThranCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fall of the Thran"), CardType::GlobalEnchantment, nID,
		_T("5") WHITE_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I - Destroy all lands.
	SAGA_CHAPTER(1, CFallOfTheThranCard, BeforeDestroy);

	// II, III - Each player returns two land cards from their graveyard to the battlefield.
	SAGA_CHAPTER(2, CFallOfTheThranCard, BeforeReturn);
	SAGA_CHAPTER(3, CFallOfTheThranCard, BeforeReturn);
}

bool CFallOfTheThranCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCountedCardContainer lands;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsLand())
				lands.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	for (int i = 0; i < lands.GetSize(); ++i)
		pModifier.ApplyTo(lands.GetAt(i));
	return true;
}

bool CFallOfTheThranCard::BeforeReturn(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		ChooseAndMove(GetGame(), GetGame()->GetPlayer(ip), ZoneId::Graveyard, 2, 2, CCardFilter::GetFilter(_T("lands")),
			ZoneId::Battlefield, MoveType::Others);
	return true;
}

CFrenziedRageCard::CFrenziedRageCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Frenzied Rage"), nID,
		_T("1") RED_MANA_TEXT,
		Power(+2), Life(+1), CreatureKeyword::CantBeBlockedBy1)
{
	// Enchanted creature gets +2/+1 and has menace.
}

CFungalPlotsCard::CFungalPlotsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fungal Plots"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_CreatureCardFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
	, m_SaprolingFilter(_T("a Saproling"), _T("Saprolings"), new CreatureTypeComparer(CREATURE_TYPE(Saproling), false))
{
	{
		// {1}{G}, Exile a creature card from your graveyard: Create a 1/1 green Saproling creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("1") GREEN_MANA_TEXT,
				_T("Saproling (K)"), 62002,
				1));

		cpAbility->GetCost().AddExileGraveyardCardCost(1, &m_CreatureCardFilter);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Sacrifice two Saprolings: You gain 2 life and draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddSacrificeCardCost(2, &m_SaprolingFilter);
		cpAbility->SetAbilityText(_T("You gain 2 life and draw a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFungalPlotsCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFungalPlotsCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CHaphazardBombardmentCard::CHaphazardBombardmentCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Haphazard Bombardment"), CardType::GlobalEnchantment, nID,
		_T("5") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_PermanentSelection(pGame, CSelectionSupport::SelectionCallback(this, &CHaphazardBombardmentCard::OnPermanentsSelected))
{
	// When this enchantment enters, choose four nonenchantment permanents you don't control and put an aim counter on
	// each of them.
	AddEnterTrigger(this, &CHaphazardBombardmentCard::BeforeAim);

	// At the beginning of your end step, if two or more permanents you don't control have an aim counter on them,
	// destroy one of those permanents at random.
	AddStepTrigger(this, NodeId::EndStep, false, &CHaphazardBombardmentCard::SetTriggerContext, &CHaphazardBombardmentCard::BeforeDestroy);
}

bool CHaphazardBombardmentCard::BeforeAim(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsEnchantment() || pCard->GetIsAlsoOf())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Aim at %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	int nCount = entries.size() < 4 ? (int)entries.size() : 4;
	if (nCount > 0)
		m_PermanentSelection.AddSelectionRequest(entries, nCount, nCount, this, pController);
	return true;
}

void CHaphazardBombardmentCard::OnPermanentsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCardCounterModifier pModifier = CCardCounterModifier(AIM_COUNTER, +1);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				pModifier.ApplyTo(pCard);
		}
}

void CHaphazardBombardmentCard::GetAimed(CPlayer* pController, CCountedCardContainer& aimed) const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (CountCounters(pBattlefield->GetAt(i), AIM_COUNTER) > 0)
				aimed.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}
}

bool CHaphazardBombardmentCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	CCountedCardContainer aimed;
	GetAimed(GetController(), aimed);
	return aimed.GetSize() >= 2;
}

bool CHaphazardBombardmentCard::BeforeDestroy(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer aimed;
	GetAimed(pController, aimed);
	if (aimed.GetSize() < 2)
		return true;

	CCard* pCard = aimed.GetAt((int)(pController->GetRand() % aimed.GetSize()));
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pController);
	pModifier.ApplyTo(pCard);
	return true;
}

CHistoryOfBenaliaCard::CHistoryOfBenaliaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("History of Benalia"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - Create a 2/2 white Knight creature token with vigilance.
	SAGA_CHAPTER(1, CHistoryOfBenaliaCard, BeforeKnight);
	SAGA_CHAPTER(2, CHistoryOfBenaliaCard, BeforeKnight);

	// III - Knights you control get +2/+1 until end of turn.
	SAGA_CHAPTER(3, CHistoryOfBenaliaCard, BeforePump);
}

bool CHistoryOfBenaliaCard::BeforeKnight(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CHistoryOfBenaliaCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CreatureTypeComparer knights(CREATURE_TYPE(Knight), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (knights(creatures.GetAt(i)))
			PumpCreature(creatures.GetAt(i), +2, +1);
	return true;
}

CInBolassClutchesCard::CInBolassClutchesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("In Bolas's Clutches"), CardType::EnchantPermanent | CardType::Legendary, nID)
{
	// Enchant permanent. You control enchanted permanent. (as Control Magic)
	// Not implemented: the enchanted permanent doesn't become legendary
	counted_ptr<CControlEnchant> cpSpell(
		::CreateObject<CControlEnchant>(this,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new TrueCardComparer));

	AddSpell(cpSpell.GetPointer());
}

COathOfTeferiCard::COathOfTeferiCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Teferi"), CardType::GlobalEnchantment | CardType::Legendary, nID,
		_T("3") WHITE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// When Oath of Teferi enters, exile another target permanent you control. Return it to the battlefield under its
	// owner's control at the beginning of the next end step.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COathOfTeferiCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());

	// You may activate the loyalty abilities of planeswalkers you control twice each turn rather than only once.
	// Not implemented: the loyalty abilities can be activated only once per turn
}

// (the return as Nezahal in Rivals of Ixalan)
bool COathOfTeferiCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pExile.ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Exile || pCard->GetCardType().IsToken())
		return false;

	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
		new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others),
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
	return false;
}

COnSerrasWingsCard::COnSerrasWingsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("On Serra's Wings"), nID,
		_T("3") WHITE_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Flying | CreatureKeyword::Vigilance)
{
	// Enchanted creature is legendary, gets +1/+1, and has flying, vigilance, and lifelink.
	// Partial: the creature doesn't become legendary
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
}

CPhyrexianScripturesCard::CPhyrexianScripturesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Phyrexian Scriptures"), CardType::GlobalEnchantment, nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I - Put a +1/+1 counter on up to one target creature. That creature becomes an artifact in addition to its other
	// types.
	CTargeting* pTargeting = m_Saga.AddChapterTarget(1, CAbility::ResolutionStartedCallback(this, &CPhyrexianScripturesCard::BeforeArtifact), Characteristic::Positive);
	pTargeting->SetSubjectCount(0, 1);

	// II - Destroy all nonartifact creatures.
	SAGA_CHAPTER(2, CPhyrexianScripturesCard, BeforeDestroy);

	// III - Exile all opponents' graveyards.
	SAGA_CHAPTER(3, CPhyrexianScripturesCard, BeforeExile);
}

bool CPhyrexianScripturesCard::BeforeArtifact(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		AddPlusCounter(pCard);
		CCardTypeModifier pModifier = CCardTypeModifier(CardType::Artifact);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

bool CPhyrexianScripturesCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (!creatures.GetAt(i)->GetCardType().IsArtifact())
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

bool CPhyrexianScripturesCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CZone* pGraveyard = pPlayer->GetZoneById(ZoneId::Graveyard);
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pController);
		while (pGraveyard->GetSize() > 0)
		{
			CCard* pCard = pGraveyard->GetAt(pGraveyard->GetSize() - 1);
			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() == ZoneId::Graveyard)
				break;
		}
	}
	return true;
}

CRiteOfBelzenlokCard::CRiteOfBelzenlokCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Rite of Belzenlok"), CardType::GlobalEnchantment, nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - Create two 0/1 black Cleric creature tokens.
	SAGA_CHAPTER(1, CRiteOfBelzenlokCard, BeforeClerics);
	SAGA_CHAPTER(2, CRiteOfBelzenlokCard, BeforeClerics);

	// III - Create a 6/6 black Demon creature token with flying, trample, and "At the beginning of your upkeep,
	// sacrifice another creature. If you can't, this token deals 6 damage to you."
	SAGA_CHAPTER(3, CRiteOfBelzenlokCard, BeforeDemon);
}

bool CRiteOfBelzenlokCard::BeforeClerics(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), CLERIC_C_TOKEN_NAME, CLERIC_C_TOKEN_ID, 2);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CRiteOfBelzenlokCard::BeforeDemon(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), DEMON_F_TOKEN_NAME, DEMON_F_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSealAwayCard::CSealAwayCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Seal Away"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this enchantment enters, exile target tapped creature an opponent controls until this enchantment leaves
	// the battlefield.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CSealAwayCard::BeforeExile, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(new TappedComparer);
	pTargeting->SetIncludeNonControllerCardsOnly();
	AddLeaveTrigger(this, &CSealAwayCard::BeforeReturn);
}

bool CSealAwayCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CSealAwayCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CSongOfFreyaliseCard::CSongOfFreyaliseCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Song of Freyalise"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - Until your next turn, creatures you control gain "{T}: Add one mana of any color."
	// Not implemented: mana abilities can't be granted

	// III - Put a +1/+1 counter on each creature you control. Those creatures gain vigilance, trample, and
	// indestructible until end of turn.
	SAGA_CHAPTER(3, CSongOfFreyaliseCard, BeforeCounters);
}

bool CSongOfFreyaliseCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		AddPlusCounter(pCard);
		PumpCreature(pCard, +0, +0, CreatureKeyword::Vigilance | CreatureKeyword::Trample);
		GainCardKeyword(pCard, CardKeyword::Indestructible);
	}
	return true;
}

CTheAntiquitiesWarCard::CTheAntiquitiesWarCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Antiquities War"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_ArtifactFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
	, m_Saga(this, 3)
{
	// I, II - Look at the top five cards of your library. You may reveal an artifact card from among them and put it
	// into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	SAGA_CHAPTER(1, CTheAntiquitiesWarCard, BeforeLook);
	SAGA_CHAPTER(2, CTheAntiquitiesWarCard, BeforeLook);

	// III - Artifacts you control become artifact creatures with base power and toughness 5/5 until end of turn.
	// Partial: the artifacts that are already creatures don't change (as Sydri in Commander 2013)
	SAGA_CHAPTER(3, CTheAntiquitiesWarCard, BeforeAnimate);
}

bool CTheAntiquitiesWarCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_ArtifactFilter);
	return true;
}

bool CTheAntiquitiesWarCard::BeforeAnimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer artifacts;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsArtifact() && !pCard->GetCardType().IsCreature() && !pCard->GetIsAlsoOf() && !pCard->GetIsAlsoA())
			artifacts.AddCard(pCard, CardPlacement::Top);
	}

	for (int i = 0; i < artifacts.GetSize(); ++i)
	{
		CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(ANIMATED_ARTIFACT_A_TOKEN_NAME, ANIMATED_ARTIFACT_A_TOKEN_ID, pController);
		CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
			TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater);
		pAnimate->ApplyTo(artifacts.GetAt(i));
		pRemove.ApplyTo(artifacts.GetAt(i));
	}
	return true;
}

CTheEldestRebornCard::CTheEldestRebornCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Eldest Reborn"), CardType::GlobalEnchantment, nID,
		_T("4") BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_SacrificeFilter(_T("a creature or planeswalker"), _T("creatures or planeswalkers"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTheEldestRebornCard::OnCardSelected))
	, m_Saga(this, 3)
{
	// I - Each opponent sacrifices a creature or planeswalker of their choice.
	SAGA_CHAPTER(1, CTheEldestRebornCard, BeforeSacrifice);

	// II - Each opponent discards a card.
	SAGA_CHAPTER(2, CTheEldestRebornCard, BeforeDiscard);

	// III - Put target creature or planeswalker card from a graveyard onto the battlefield under your control.
	// Note: the card is chosen on resolution (not targeted)
	SAGA_CHAPTER(3, CTheEldestRebornCard, BeforeReanimate);
}

bool CTheEldestRebornCard::BeforeSacrifice(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			ChooseAndMove(GetGame(), GetGame()->GetPlayer(ip), ZoneId::Battlefield, 1, 1, &m_SacrificeFilter,
				ZoneId::Graveyard, MoveType::Sacrifice);
	return true;
}

bool CTheEldestRebornCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

bool CTheEldestRebornCard::BeforeReanimate(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pCard = pGraveyard->GetAt(i);
			if (!m_SacrificeFilter.IsCardIncluded(pCard))
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CTheEldestRebornCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Graveyard)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
		}
}

CTheFirstEruptionCard::CTheFirstEruptionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The First Eruption"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I - This Saga deals 1 damage to each creature without flying.
	SAGA_CHAPTER(1, CTheFirstEruptionCard, BeforeDamage);

	// II - Add {R}{R}.
	SAGA_CHAPTER(2, CTheFirstEruptionCard, BeforeMana);

	// III - Sacrifice a Mountain. If you do, this Saga deals 3 damage to each creature.
	SAGA_CHAPTER(3, CTheFirstEruptionCard, BeforeSacrifice);
}

bool CTheFirstEruptionCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachCreature(this, 1, TRUE);
	return true;
}

bool CTheFirstEruptionCard::BeforeMana(CAbilityAction* pAction)
{
	CManaPoolModifier pMana = CManaPoolModifier(CManaPoolModifier::Operation::Add,
		CManaPool::CManaPool(RED_MANA_TEXT RED_MANA_TEXT));
	pMana.ApplyTo(pAction->GetController());
	return true;
}

bool CTheFirstEruptionCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCardFilter* pMountains = CCardFilter::GetFilter(_T("Mountains"));
	int nBefore = pMountains->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nBefore == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 1, 1, pMountains, ZoneId::Graveyard, MoveType::Sacrifice);
	if (pMountains->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) < nBefore)
		DamageEachCreature(this, 3, FALSE);
	return true;
}

CTheFlameOfKeldCard::CTheFlameOfKeldCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Flame of Keld"), CardType::GlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I - Discard your hand.
	SAGA_CHAPTER(1, CTheFlameOfKeldCard, BeforeDiscard);

	// II - Draw two cards.
	SAGA_CHAPTER(2, CTheFlameOfKeldCard, BeforeDraw);

	// III - If a red source you control would deal damage to a permanent or player this turn, it deals that much damage
	// plus 2 to that permanent or player instead.
	// Not implemented: there are no replacement effects on damage (the chapter does nothing)
	SAGA_CHAPTER(3, CTheFlameOfKeldCard, BeforeChapter3);
}

bool CTheFlameOfKeldCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	while (pHand->GetSize() > 0)
	{
		CCard* pCard = pHand->GetAt(pHand->GetSize() - 1);
		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Hand)
			break;
	}
	return true;
}

bool CTheFlameOfKeldCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	return true;
}

bool CTheFlameOfKeldCard::BeforeChapter3(CAbilityAction* pAction)
{
	return true;
}

CTheMendingOfDominariaCard::CTheMendingOfDominariaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Mending of Dominaria"), CardType::GlobalEnchantment, nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - Mill two cards, then you may return a creature card from your graveyard to your hand.
	SAGA_CHAPTER(1, CTheMendingOfDominariaCard, BeforeMill);
	SAGA_CHAPTER(2, CTheMendingOfDominariaCard, BeforeMill);

	// III - Return all land cards from your graveyard to the battlefield, then shuffle your graveyard into your library.
	SAGA_CHAPTER(3, CTheMendingOfDominariaCard, BeforeLands);
}

bool CTheMendingOfDominariaCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Mill(pController, 2);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 1, CCardFilter::GetFilter(_T("creatures")), ZoneId::Hand, MoveType::Others);
	return true;
}

bool CTheMendingOfDominariaCard::BeforeLands(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer lands;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetCardType().IsLand())
			lands.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);
	CMoveCardModifier pToBattlefield = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController);
	for (int i = 0; i < lands.GetSize(); ++i)
		pToBattlefield.ApplyTo(lands.GetAt(i));

	CMoveCardModifier pToLibrary = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pController);
	while (pGraveyard->GetSize() > 0)
	{
		CCard* pCard = pGraveyard->GetAt(pGraveyard->GetSize() - 1);
		pToLibrary.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Graveyard)
			break;
	}
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CTheMirariConjectureCard::CTheMirariConjectureCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Mirari Conjecture"), CardType::GlobalEnchantment, nID,
		_T("4") BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I - Return target instant card from your graveyard to your hand.
	// Note: the card is chosen on resolution (not targeted)
	SAGA_CHAPTER(1, CTheMirariConjectureCard, BeforeInstant);

	// II - Return target sorcery card from your graveyard to your hand.
	SAGA_CHAPTER(2, CTheMirariConjectureCard, BeforeSorcery);

	// III - Until end of turn, whenever you cast an instant or sorcery spell, copy it. You may choose new targets for the
	// copy.
	// Not implemented: the spells aren't copied (the chapter does nothing)
	SAGA_CHAPTER(3, CTheMirariConjectureCard, BeforeChapter3);
}

bool CTheMirariConjectureCard::BeforeInstant(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("instant cards")), ZoneId::Hand, MoveType::Others);
	return true;
}

bool CTheMirariConjectureCard::BeforeSorcery(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("sorcery cards")), ZoneId::Hand, MoveType::Others);
	return true;
}

bool CTheMirariConjectureCard::BeforeChapter3(CAbilityAction* pAction)
{
	return true;
}

CTimeOfIceCard::CTimeOfIceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Time of Ice"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - Tap target creature an opponent controls. It doesn't untap during its controller's untap step for as long
	// as you control this Saga.
	for (int n = 1; n <= 2; ++n)
	{
		CTargeting* pTargeting = m_Saga.AddChapterTarget(n, CAbility::ResolutionStartedCallback(this, &CTimeOfIceCard::BeforeTap), Characteristic::Negative);
		pTargeting->SetIncludeNonControllerCardsOnly();
	}

	// III - Return all tapped creatures to their owners' hands.
	SAGA_CHAPTER(3, CTimeOfIceCard, BeforeBounce);

	// The creatures untap normally once the Saga leaves the battlefield
	AddLeaveTrigger(this, &CTimeOfIceCard::BeforeRelease);
}

bool CTimeOfIceCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardOrientationModifier pTap = CCardOrientationModifier(TRUE);
	pTap.ApplyTo(pCard);

	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pFreeze = CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE);
		pFreeze.ApplyTo(pCard);
		m_Frozen.AddCard(pCard, CardPlacement::Top);
	}
	return false;
}

bool CTimeOfIceCard::BeforeBounce(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetOrientation()->IsTapped())
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

bool CTimeOfIceCard::BeforeRelease(CAbilityAction* pAction)
{
	CCardKeywordModifier pFreeze = CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE);
	while (m_Frozen.GetSize() > 0)
	{
		CCard* pCard = m_Frozen.GetAt(0);
		m_Frozen.RemoveCard(pCard);
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			pFreeze.RemoveFrom(pCard);
	}
	return true;
}

CTriumphOfGerrardCard::CTriumphOfGerrardCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Triumph of Gerrard"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
	, m_Saga(this, 3)
{
	// I, II - Put a +1/+1 counter on target creature you control with the greatest power.
	// III - Target creature you control with the greatest power gains flying, first strike, and lifelink until end of
	// turn.
	for (int n = 1; n <= 3; ++n)
	{
		CTargeting* pTargeting = m_Saga.AddChapterTarget(n,
			n < 3 ? CAbility::ResolutionStartedCallback(this, &CTriumphOfGerrardCard::BeforeCounter)
				  : CAbility::ResolutionStartedCallback(this, &CTriumphOfGerrardCard::BeforeKeywords),
			Characteristic::Positive);
		pTargeting->GetSubjectCardFilter().AddComparer(new GreatestPowerComparer);
		pTargeting->SetIncludeControllerCardsOnly();
	}
}

bool CTriumphOfGerrardCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard);
	return false;
}

bool CTriumphOfGerrardCard::BeforeKeywords(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		PumpCreature(pCard, +0, +0, CreatureKeyword::Flying | CreatureKeyword::FirstStrike);
		GainCardKeyword(pCard, CardKeyword::Lifelink);
	}
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

#define WEATHERLIGHT_VEHICLE_NAME	_T("Weatherlight (Vehicle)")
#define WEATHERLIGHT_VEHICLE_ID		64129

// Unequips the Equipment before a new equip ability resolves (the granted ability belongs to the old creature, as
// Cranial Plating in Fifth Dawn)
static void UnequipAll(CCard* pEquipment)
{
	for (int i = 0; i < pEquipment->GetAbilityCount(); ++i)
	{
		CEquipAbility* pEquipAbility = dynamic_cast<CEquipAbility*>(pEquipment->GetAbility(i));
		if (pEquipAbility)
			pEquipAbility->Unequip();
	}
}

CBlackbladeReforgedCard::CBlackbladeReforgedCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Blackblade Reforged"), CardType::Artifact | CardType::Equipment | CardType::Legendary, nID,
		_T("2"), AbilityType::Artifact)
{
	// Equipped creature gets +1/+1 for each land you control. (the equipment gives the creature an ability that counts
	// the lands, as Cranial Plating in Fifth Dawn)
	// Equip legendary creature {3}. Equip {7}
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, i == 0 ? _T("3") : _T("7"),
				i == 0 ? (CardComparer*)new AndCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Legendary, false))
					   : (CardComparer*)new AnyCreatureComparer));

		cpAbility->AddCardModifier(new CCardAbilityModifier(
			CCardAbilityModifier::CreateAbilityCallback(this, &CBlackbladeReforgedCard::CreateEquipmentAbility)));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlackbladeReforgedCard::BeforeEquip));
		if (i == 0)
			cpAbility->SetAbilityText(_T("Equip legendary creature. Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBlackbladeReforgedCard::BeforeEquip(CAbilityAction* pAction)
{
	UnequipAll(this);
	return true;
}

counted_ptr<CAbility> CBlackbladeReforgedCard::CreateEquipmentAbility(CCard* pCard)
{
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(pCard,
			ZoneId::Battlefield,
			new CardTypeComparer(CardType::_Land, false)));

	cpAbility->StartListening(GetController());
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CBloodtallowCandleCard::CBloodtallowCandleCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Bloodtallow Candle"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {6}, {T}, Sacrifice this artifact: Target creature gets -5/-5 until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("6"),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBloodtallowCandleCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());
}

bool CBloodtallowCandleCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, -5, -5);
	return false;
}

CForebearsBladeCard::CForebearsBladeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Forebear's Blade"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	// Equipped creature gets +3/+0 and has vigilance and trample. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+3), FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Vigilance | CreatureKeyword::Trample);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);

	AddAbility(cpAbility.GetPointer());

	// Whenever equipped creature dies, attach this Equipment to target creature you control.
	// Not implemented: an Equipment can't be attached by an effect
}

CJoustingLanceCard::CJoustingLanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Jousting Lance"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	// Equipped creature gets +2/+0. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));
	AddAbility(cpAbility.GetPointer());

	// During your turn, equipped creature has first strike.
	// Not implemented: there is no keyword only during your turn
}

CMoxAmberCard::CMoxAmberCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mox Amber"), CardType::Artifact | CardType::Legendary, nID,
		_T("0"), AbilityType::Artifact)
{
	// {T}: Add one mana of any color among legendary creatures and planeswalkers you control.
	// (one mana ability for each color, playable only if you control a legendary creature or planeswalker of it)
	LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	typedef BOOL (CMoxAmberCard::*Condition)(BOOL);
	Condition conditions[] = { &CMoxAmberCard::HasWhite, &CMoxAmberCard::HasBlue, &CMoxAmberCard::HasBlack,
		&CMoxAmberCard::HasRed, &CMoxAmberCard::HasGreen };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, mana[i]));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), conditions[i]);
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CMoxAmberCard::HasColor(CardType color) const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsLegendary() && (pCard->GetCardType().IsCreature() || pCard->GetCardType().IsPlaneswalker()) &&
			(pCard->GetCardType() & color).Any())
			return TRUE;
	}
	return FALSE;
}

CNavigatorsCompassCard::CNavigatorsCompassCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Navigator's Compass"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// When this artifact enters, you gain 3 life.
	AddEnterTrigger(this, &CNavigatorsCompassCard::BeforeGainLife);

	// {T}: Until end of turn, target land you control becomes the basic land type of your choice in addition to its
	// other types.
	// Not implemented: there is no choice of a land type for a land
}

bool CNavigatorsCompassCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CPowerstoneShardCard::CPowerstoneShardCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Powerstone Shard"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// {T}: Add {C} for each artifact you control named Powerstone Shard.
	// (one mana ability for each count, from 1 to 4 or more, as the variants of Ghalta in Rivals of Ixalan)
	LPCTSTR mana[] = { _T("1"), _T("2"), _T("3"), _T("4") };
	typedef BOOL (CPowerstoneShardCard::*Condition)(BOOL);
	Condition conditions[] = { &CPowerstoneShardCard::Has1, &CPowerstoneShardCard::Has2,
		&CPowerstoneShardCard::Has3, &CPowerstoneShardCard::Has4 };
	for (int i = 0; i < 4; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, mana[i]));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), conditions[i]);
		AddAbility(cpAbility.GetPointer());
	}
}

int CPowerstoneShardCard::CountShards() const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	int nCount = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsArtifact() && _tcscmp(pCard->GetPrintedCardName(), _T("Powerstone Shard")) == 0)
			++nCount;
	}
	return nCount;
}

CShortSwordCard::CShortSwordCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Short Sword"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature gets +1/+1. Equip {1}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+1), this,
		PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE));
	AddAbility(cpAbility.GetPointer());
}

CSorcerersWandCard::CSorcerersWandCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sorcerer's Wand"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature has "{T}: This creature deals 1 damage to target player or planeswalker. If this creature is a
	// Wizard, it deals 2 damage instead." Equip {3} (as Cranial Plating in Fifth Dawn)
	// Note: it can't target planeswalkers, and the damage depends on the creature being a Wizard when it's equipped
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CSorcerersWandCard::CreateWandAbility)));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorcerersWandCard::BeforeEquip));
	AddAbility(cpAbility.GetPointer());
}

bool CSorcerersWandCard::BeforeEquip(CAbilityAction* pAction)
{
	UnequipAll(this);
	return true;
}

counted_ptr<CAbility> CSorcerersWandCard::CreateWandAbility(CCard* pCard)
{
	int nDamage = CreatureTypeComparer(CREATURE_TYPE(Wizard), false)(pCard) ? 2 : 1;

	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(pCard,
			_T(""),
			FALSE_CARD_COMPARER, TRUE,
			Life(-nDamage), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CThranTemporalGatewayCard::CThranTemporalGatewayCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Thran Temporal Gateway"), CardType::Artifact | CardType::Legendary, nID,
		_T("4"), AbilityType::Artifact)
	, m_HistoricPermanentFilter(_T("a historic permanent card"), _T("historic permanent cards"), new HistoricComparer)
{
	m_HistoricPermanentFilter.AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)));

	// {4}, {T}: You may put a historic permanent card from your hand onto the battlefield.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("4")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Put a historic permanent card from your hand onto the battlefield. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThranTemporalGatewayCard::BeforePut));
	AddAbility(cpAbility.GetPointer());
}

bool CThranTemporalGatewayCard::BeforePut(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, &m_HistoricPermanentFilter, ZoneId::Battlefield, MoveType::Others);
	return true;
}

CUrzasTomeCard::CUrzasTomeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Urza's Tome"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CUrzasTomeCard::OnCardSelected))
{
	// {3}, {T}: Draw a card. Then discard a card unless you exile a historic card from your graveyard.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Draw a card, then discard a card unless you exile a historic card from your graveyard. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUrzasTomeCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

// The player chooses a historic card of the graveyard to exile or a card of the hand to discard
bool CUrzasTomeCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);

	std::vector<SelectionEntry> entries;
	HistoricComparer historic;
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (!historic(pCard))
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Exile %s from your graveyard"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CUrzasTomeCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Graveyard)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
			else if (pCard->GetZoneId() == ZoneId::Hand)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
		}
}

CWeatherlightCard::CWeatherlightCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Weatherlight"), CardType::Artifact | CardType::Legendary, nID,
		_T("4"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Flying. Whenever Weatherlight deals combat damage to a player, look at the top five cards of your library. You
	// may reveal a historic card from among them and put it into your hand. Put the rest on the bottom of your library
	// in a random order. (in the creature it becomes, Weatherlight (Vehicle) in ATokens)
	// Crew 3
	m_Crew.AddCrewAbility(3, WEATHERLIGHT_VEHICLE_NAME, WEATHERLIGHT_VEHICLE_ID);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (sorceries)

#define ELEMENTAL_AX_TOKEN_NAME	_T("Elemental (AX)")
#define ELEMENTAL_AX_TOKEN_ID	64130

void CLegendarySorceryCard::SetLegendary(CAbility* pSpell)
{
	AddPlayableIf(this, pSpell, &CLegendarySorceryCard::CanCastLegendary);
}

BOOL CLegendarySorceryCard::CanCastLegendary(BOOL bIncludeTricks)
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsLegendary() && (pCard->GetCardType().IsCreature() || pCard->GetCardType().IsPlaneswalker()))
			return TRUE;
	}
	return FALSE;
}

// A sorcery with a resolution callback
template <class T>
static CGenericSpell* AddSorcery(T* pCard, LPCTSTR strCost, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(pCard, AbilityType::Sorcery, strCost));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A sorcery that destroys (or exiles) a target
static CTargetMoveCardSpell* AddMoveSorcery(CCard* pCard, LPCTSTR strCost, CardComparer* pComparer, ZoneId toZone, MoveType moveType)
{
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(pCard, AbilityType::Sorcery,
			strCost,
			pComparer,
			ZoneId::Battlefield, toZone, TRUE, moveType));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A damage sorcery
static CTargetChgLifeSpell* AddDamageSorcery(CCard* pCard, LPCTSTR strCost, int nDamage, CardComparer* pComparer, BOOL bPlayers)
{
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(pCard, AbilityType::Sorcery,
			strCost,
			pComparer, bPlayers,
			Life(-nDamage), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

//____________________________________________________________________________
//
// Sorceries

CAdventurousImpulseCard::CAdventurousImpulseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Adventurous Impulse"), CardType::Sorcery, nID)
	, m_Filter(_T("a creature or land card"), _T("creature or land cards"), new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	// Look at the top three cards of your library. You may reveal a creature or land card from among them and put it
	// into your hand. Put the rest on the bottom of your library in any order.
	AddSorcery(this, GREEN_MANA_TEXT, &CAdventurousImpulseCard::BeforeResolution);
}

bool CAdventurousImpulseCard::BeforeResolution(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 3, &m_Filter);
	return true;
}

CBoardTheWeatherlightCard::CBoardTheWeatherlightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Board the Weatherlight"), CardType::Sorcery, nID)
	, m_Filter(_T("a historic card"), _T("historic cards"), new HistoricComparer)
{
	// Look at the top five cards of your library. You may reveal a historic card from among them and put it into your
	// hand. Put the rest on the bottom of your library in a random order. (in any order)
	AddSorcery(this, _T("1") WHITE_MANA_TEXT, &CBoardTheWeatherlightCard::BeforeResolution);
}

bool CBoardTheWeatherlightCard::BeforeResolution(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_Filter);
	return true;
}

CBrokenBondCard::CBrokenBondCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Broken Bond"), CardType::Sorcery, nID)
{
	// Destroy target artifact or enchantment. You may put a land card from your hand onto the battlefield.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("1") GREEN_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false), ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBrokenBondCard::BeforeResolution));
}

// The land is put after the destruction would be more exact; here it's put before it (the callback returns true)
bool CBrokenBondCard::BeforeResolution(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, CCardFilter::GetFilter(_T("lands")), ZoneId::Battlefield, MoveType::Others);
	return true;
}

CCallTheCavalryCard::CCallTheCavalryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Call the Cavalry"), CardType::Sorcery, nID)
{
	// Create two 2/2 white Knight creature tokens with vigilance.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT,
			KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID,
			2));

	AddSpell(cpSpell.GetPointer());
}

CChandrasOutburstCard::CChandrasOutburstCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chandra's Outburst"), CardType::Sorcery, nID)
{
	// Chandra's Outburst deals 4 damage to target player or planeswalker. Search your library and/or graveyard for a
	// card named Chandra, Bold Pyromancer, reveal it, and put it into your hand. If you search your library this way,
	// shuffle.
	// Note: it can't target planeswalkers
	CTargetChgLifeSpell* pSpell = AddDamageSorcery(this, _T("3") RED_MANA_TEXT RED_MANA_TEXT, 4, FALSE_CARD_COMPARER, TRUE);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandrasOutburstCard::BeforeResolution));
}

bool CChandrasOutburstCard::BeforeResolution(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Chandra, Bold Pyromancer"));
	return true;
}

CDivestCard::CDivestCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Divest"), CardType::Sorcery, nID)
	, m_Filter(_T("an artifact or creature card"), _T("artifact or creature cards"), new CardTypeComparer(CardType::Artifact | CardType::Creature, false))
{
	// Target player reveals their hand. You choose an artifact or creature card from it. That player discards that card.
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT,
			1, MoveType::Discard, ZoneId::Graveyard, TRUE,
			FALSE,
			&m_Filter));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CEviscerateCard::CEviscerateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Eviscerate"), CardType::Sorcery, nID)
{
	// Destroy target creature.
	AddMoveSorcery(this, _T("3") BLACK_MANA_TEXT, new AnyCreatureComparer, ZoneId::Graveyard, MoveType::Destroy);
}

CFieryInterventionCard::CFieryInterventionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fiery Intervention"), CardType::Sorcery, nID)
{
	// Choose one - Fiery Intervention deals 5 damage to target creature.
	CTargetChgLifeSpell* pDamage = AddDamageSorcery(this, _T("4") RED_MANA_TEXT, 5, new AnyCreatureComparer, FALSE);
	pDamage->SetAbilityText(_T("Deal 5 damage to target creature. Casts"));

	// - Destroy target artifact.
	CTargetMoveCardSpell* pDestroy = AddMoveSorcery(this, _T("4") RED_MANA_TEXT, new CardTypeComparer(CardType::Artifact, false), ZoneId::Graveyard, MoveType::Destroy);
	pDestroy->SetAbilityText(_T("Destroy target artifact. Casts"));
}

CFightWithFireCard::CFightWithFireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fight with Fire"), CardType::Sorcery, nID)
{
	// Fight with Fire deals 5 damage to target creature.
	AddDamageSorcery(this, _T("2") RED_MANA_TEXT, 5, new AnyCreatureComparer, FALSE);

	// Kicker {5}{R}. If this spell was kicked, it deals 10 damage divided as you choose among any number of targets
	// instead. (a second spell for the kicked cost, as Forked Bolt)
	// Note: it can't target planeswalkers
	CTargetChgLifeSpell* pKicked = AddDamageSorcery(this, _T("7") RED_MANA_TEXT RED_MANA_TEXT, 10, new AnyCreatureComparer, TRUE);
	pKicked->GetTargeting()->SetSubjectCount(1, 10);
	pKicked->GetTargeting()->SetDistributeValues();
	pKicked->SetAbilityText(_T("Casts kicked"));
	pKicked->SetMainSpell(FALSE);
}

CFinalPartingCard::CFinalPartingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Final Parting"), CardType::Sorcery, nID)
{
	// Search your library for two cards. Put one into your hand and the other into your graveyard. Then shuffle.
	AddSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CFinalPartingCard::BeforeResolution);
}

bool CFinalPartingCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Library, 1, 1, CCardFilter::GetFilter(_T("cards")), ZoneId::Hand, MoveType::Others);
	ChooseAndMove(GetGame(), pController, ZoneId::Library, 1, 1, CCardFilter::GetFilter(_T("cards")), ZoneId::Graveyard, MoveType::Others);
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CGoblinBarrageCard::CGoblinBarrageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Goblin Barrage"), CardType::Sorcery, nID)
	, m_SacrificeFilter(_T("an artifact or Goblin"), _T("artifacts or Goblins"),
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CreatureTypeComparer(CREATURE_TYPE(Goblin), false)))
{
	// Goblin Barrage deals 4 damage to target creature.
	AddDamageSorcery(this, _T("3") RED_MANA_TEXT, 4, new AnyCreatureComparer, FALSE);

	// Kicker - Sacrifice an artifact or Goblin. If this spell was kicked, it also deals 4 damage to target player or
	// planeswalker. (a second spell with the additional cost)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			FALSE_CARD_COMPARER, TRUE, _T("")));

	cpSpell->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetAbilityText(_T("Casts kicked"));
	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGoblinBarrageCard::BeforeKicked));
	AddSpell(cpSpell.GetPointer());
}

bool CGoblinBarrageCard::BeforeKicked(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCountedCardContainer creatures;
	pDoubleTargetAction->GetTargetGroup1().GetCardSubjects(creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 4);

	CPlayerContainer players;
	pDoubleTargetAction->GetTargetGroup2().GetPlayerSubjects(players);
	for (int i = 0; i < players.GetSize(); ++i)
		DealDamageToPlayer(this, players.GetAt(i), 4);
	return false;
}

CGrowFromTheAshesCard::CGrowFromTheAshesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grow from the Ashes"), CardType::Sorcery, nID)
	, m_KickerCost(_T("2"))
{
	// Kicker {2}. Search your library for a basic land card, put it onto the battlefield, then shuffle. If this spell
	// was kicked, instead search your library for two basic land cards, put them onto the battlefield, then shuffle.
	CGenericSpell* pSpell = AddSorcery(this, _T("2") GREEN_MANA_TEXT, &CGrowFromTheAshesCard::BeforeResolution);
	pSpell->GetCost().AddOptionalManaCost(m_KickerCost);
}

bool CGrowFromTheAshesCard::BeforeResolution(CAbilityAction* pAction)
{
	int nCount = pAction->GetCostConfigEntry().HasOptionalManaCost(m_KickerCost) ? 2 : 1;
	SearchToBattlefield(GetGame(), pAction->GetController(), nCount, CCardFilter::GetFilter(_T("basic lands")), FALSE);
	return true;
}

CJayasImmolatingInfernoCard::CJayasImmolatingInfernoCard(CGame* pGame, UINT nID)
	: CLegendarySorceryCard(pGame, _T("Jaya's Immolating Inferno"), nID)
{
	// Jaya's Immolating Inferno deals X damage to each of up to three targets.
	// Note: it can't target planeswalkers
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->GetTargeting()->SetSubjectCount(1, 3);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJayasImmolatingInfernoCard::BeforeResolution));
	SetLegendary(cpSpell.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

bool CJayasImmolatingInfernoCard::BeforeResolution(CAbilityAction* pAction)
{
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	int nX = GetX(pAction);
	if (!pTargetAction || nX <= 0)
		return false;

	CCountedCardContainer cards;
	pTargetAction->GetTargetGroup().GetCardSubjects(cards);
	for (int i = 0; i < cards.GetSize(); ++i)
		DealDamageToCreature(this, cards.GetAt(i), nX);

	CPlayerContainer players;
	pTargetAction->GetTargetGroup().GetPlayerSubjects(players);
	for (int i = 0; i < players.GetSize(); ++i)
		DealDamageToPlayer(this, players.GetAt(i), nX);
	return false;
}

CKamahlsDruidicVowCard::CKamahlsDruidicVowCard(CGame* pGame, UINT nID)
	: CLegendarySorceryCard(pGame, _T("Kamahl's Druidic Vow"), nID)
{
	// Look at the top X cards of your library. You may put any number of land and/or legendary permanent cards with mana
	// value X or less from among them onto the battlefield. Put the rest into your graveyard.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, GREEN_MANA_TEXT GREEN_MANA_TEXT));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKamahlsDruidicVowCard::BeforeResolution));
	SetLegendary(cpSpell.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

bool CKamahlsDruidicVowCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nX = GetX(pAction);
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (nX > pLibrary->GetSize())
		nX = pLibrary->GetSize();
	if (nX <= 0)
		return true;

	CCardFilter filter(_T("a land or legendary permanent card"), _T("land or legendary permanent cards"),
		new OrCardComparer(
			new CardTypeComparer(CardType::_Land, false),
			new AndCardComparer(
				new AndCardComparer(new CardTypeComparer(CardType::Legendary, false),
					new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false))),
				new ConvertedManaCostComparer<std::less_equal<int>>(nX))));

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nX, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nX), // any number
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		&filter, // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.SetReorderInformation(true, ZoneId::Graveyard, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pModifier.ApplyTo(pController);
	return true;
}

CKarnsTemporalSunderingCard::CKarnsTemporalSunderingCard(CGame* pGame, UINT nID)
	: CLegendarySorceryCard(pGame, _T("Karn's Temporal Sundering"), nID)
{
	// Target player takes an extra turn after this one. Return up to one target nonland permanent to its owner's hand.
	// Exile Karn's Temporal Sundering.
	// Note: the extra turn is yours (the player isn't targeted)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)), FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(0, 1);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKarnsTemporalSunderingCard::BeforeResolution));
	SetLegendary(cpSpell.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

bool CKarnsTemporalSunderingCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayerEffectModifier pExtraTurn = CPlayerEffectModifier(PlayerEffectType::TimeWalk, 1);
	pExtraTurn.ApplyTo(pAction->GetController());

	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (pTargetAction)
	{
		CCountedCardContainer cards;
		pTargetAction->GetTargetGroup().GetCardSubjects(cards);
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				pModifier.ApplyTo(cards.GetAt(i));
	}
	return false;
}

CPrimevalsGloriousRebirthCard::CPrimevalsGloriousRebirthCard(CGame* pGame, UINT nID)
	: CLegendarySorceryCard(pGame, _T("Primevals' Glorious Rebirth"), nID)
{
	// Return all legendary permanent cards from your graveyard to the battlefield.
	CGenericSpell* pSpell = AddSorcery(this, _T("5") WHITE_MANA_TEXT BLACK_MANA_TEXT, &CPrimevalsGloriousRebirthCard::BeforeResolution);
	SetLegendary(pSpell);
}

bool CPrimevalsGloriousRebirthCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	CCountedCardContainer cards;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (pCard->GetCardType().IsLegendary() && !pCard->GetCardType().IsInstant() && !pCard->GetCardType().IsSorcery())
			cards.AddCard(pCard, CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		pModifier.ApplyTo(cards.GetAt(i));
	return true;
}

CSaprolingMigrationCard::CSaprolingMigrationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Saproling Migration"), CardType::Sorcery, nID)
	, m_KickerCost(_T("4"))
{
	// Kicker {4}. Create two 1/1 green Saproling creature tokens. If this spell was kicked, create four of those tokens
	// instead.
	CGenericSpell* pSpell = AddSorcery(this, _T("1") GREEN_MANA_TEXT, &CSaprolingMigrationCard::BeforeResolution);
	pSpell->GetCost().AddOptionalManaCost(m_KickerCost);
}

bool CSaprolingMigrationCard::BeforeResolution(CAbilityAction* pAction)
{
	int nCount = pAction->GetCostConfigEntry().HasOptionalManaCost(m_KickerCost) ? 4 : 2;
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Saproling (K)"), 62002, nCount);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSeismicShiftCard::CSeismicShiftCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Seismic Shift"), CardType::Sorcery, nID)
{
	// Destroy target land. Up to two target creatures can't block this turn.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false), FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetSubjectCount(0, 2);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSeismicShiftCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSeismicShiftCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCountedCardContainer lands;
	pDoubleTargetAction->GetTargetGroup1().GetCardSubjects(lands);
	CMoveCardModifier pDestroy = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	for (int i = 0; i < lands.GetSize(); ++i)
		if (lands.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pDestroy.ApplyTo(lands.GetAt(i));

	CCountedCardContainer creatures;
	pDoubleTargetAction->GetTargetGroup2().GetCardSubjects(creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
			pCreature->GetCreatureKeyword()->AddCantBlock(TRUE);
	}
	return false;
}

CSettleTheScoreCard::CSettleTheScoreCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Settle the Score"), CardType::Sorcery, nID)
	, m_PlaneswalkerSelection(pGame, CSelectionSupport::SelectionCallback(this, &CSettleTheScoreCard::OnPlaneswalkerSelected))
{
	// Exile target creature. Put two loyalty counters on a planeswalker you control.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, new AnyCreatureComparer, ZoneId::Exile, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSettleTheScoreCard::BeforeResolution));
}

bool CSettleTheScoreCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsPlaneswalker())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put two loyalty counters on %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_PlaneswalkerSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CSettleTheScoreCard::OnPlaneswalkerSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CCardCounterModifier pModifier = CCardCounterModifier(LOYALTY_COUNTER, +2);
				pModifier.ApplyTo(pCard);
			}
		}
}

CSoulSalvageCard::CSoulSalvageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Soul Salvage"), CardType::Sorcery, nID)
{
	// Return up to two target creature cards from your graveyard to your hand.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());
}

CSylvanAwakeningCard::CSylvanAwakeningCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sylvan Awakening"), CardType::Sorcery, nID)
{
	// Until your next turn, all lands you control become 2/2 Elemental creatures with reach, indestructible, and haste.
	// They're still lands. (Elemental (AX) in ATokens, removed at the end of the next turn of the opponent)
	AddSorcery(this, _T("2") GREEN_MANA_TEXT, &CSylvanAwakeningCard::BeforeResolution);
}

bool CSylvanAwakeningCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer lands;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsLand() && !pCard->GetCardType().IsCreature() && !pCard->GetIsAlsoA())
			lands.AddCard(pCard, CardPlacement::Top);
	}

	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	for (int i = 0; i < lands.GetSize(); ++i)
	{
		CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(ELEMENTAL_AX_TOKEN_NAME, ELEMENTAL_AX_TOKEN_ID, pController);
		CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
			TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater,
			CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pOpponent);
		pAnimate->ApplyTo(lands.GetAt(i));
		pRemove.ApplyTo(lands.GetAt(i));
	}
	return true;
}

CTemporalMachinationsCard::CTemporalMachinationsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Temporal Machinations"), CardType::Sorcery, nID)
{
	// Return target creature to its owner's hand. If you control an artifact, draw a card.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("2") BLUE_MANA_TEXT, new AnyCreatureComparer, ZoneId::Hand, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTemporalMachinationsCard::BeforeResolution));
}

bool CTemporalMachinationsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCardFilter artifacts(_T("an artifact"), _T("artifacts"), new CardTypeComparer(CardType::Artifact, false));
	if (artifacts.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
		DrawCards(GetGame(), pController, 1);
	return true;
}

CUrzasRuinousBlastCard::CUrzasRuinousBlastCard(CGame* pGame, UINT nID)
	: CLegendarySorceryCard(pGame, _T("Urza's Ruinous Blast"), nID)
{
	// Exile all nonland permanents that aren't legendary.
	CGenericSpell* pSpell = AddSorcery(this, _T("4") WHITE_MANA_TEXT, &CUrzasRuinousBlastCard::BeforeResolution);
	SetLegendary(pSpell);
}

bool CUrzasRuinousBlastCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (!pCard->GetCardType().IsLand() && !pCard->GetCardType().IsLegendary() && !pCard->GetIsAlsoOf())
				cards.AddCard(pCard, CardPlacement::Top);
		}
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(cards.GetAt(i));
	return true;
}

CWarlordsFuryCard::CWarlordsFuryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Warlord's Fury"), CardType::Sorcery, nID)
{
	// Creatures you control gain first strike until end of turn. Draw a card.
	AddSorcery(this, RED_MANA_TEXT, &CWarlordsFuryCard::BeforeResolution);
}

bool CWarlordsFuryCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +0, +0, CreatureKeyword::FirstStrike);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CWeightOfMemoryCard::CWeightOfMemoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Weight of Memory"), CardType::Sorcery, nID)
{
	// Draw three cards. Target player mills three cards.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWeightOfMemoryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWeightOfMemoryCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 3);
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 3);
	return true;
}

CYawgmothsVileOfferingCard::CYawgmothsVileOfferingCard(CGame* pGame, UINT nID)
	: CLegendarySorceryCard(pGame, _T("Yawgmoth's Vile Offering"), nID)
	, m_Filter(_T("a creature or planeswalker card"), _T("creature or planeswalker cards"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CYawgmothsVileOfferingCard::OnCardSelected))
{
	// Put up to one target creature or planeswalker card from a graveyard onto the battlefield under your control.
	// Destroy up to one target creature or planeswalker. Exile Yawgmoth's Vile Offering.
	// Note: the card from a graveyard is chosen on resolution (not targeted)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("4") BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false), FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(0, 1);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CYawgmothsVileOfferingCard::BeforeResolution));
	SetLegendary(cpSpell.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

bool CYawgmothsVileOfferingCard::BeforeResolution(CAbilityAction* pAction)
{
	// Destroy up to one target creature or planeswalker
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (pTargetAction)
	{
		CCountedCardContainer cards;
		pTargetAction->GetTargetGroup().GetCardSubjects(cards);
		CMoveCardModifier pDestroy = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				pDestroy.ApplyTo(cards.GetAt(i));
	}

	// Put up to one creature or planeswalker card from a graveyard onto the battlefield under your control
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pCard = pGraveyard->GetAt(i);
			if (!m_Filter.IsCardIncluded(pCard))
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, 1, this, pAction->GetController());
	return false;
}

void CYawgmothsVileOfferingCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Graveyard)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
		}
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (instants)

// The player controls a creature of the type
static BOOL ControlsType(CPlayer* pPlayer, const CreatureType& type)
{
	CCardFilter filter(_T("a creature"), _T("creatures"), new CreatureTypeComparer(type, false));
	return filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

// The target creature of a spell, if it's still on the battlefield
static CCard* GetTargetCreature(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	return pCard && pCard->GetZoneId() == ZoneId::Battlefield ? pCard : NULL;
}

//____________________________________________________________________________
//
// Instants

CAdamantWillCard::CAdamantWillCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Adamant Will"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 and gains indestructible until end of turn.
	AddCreatureSpell(this, _T("1") WHITE_MANA_TEXT, FALSE, &CAdamantWillCard::BeforeResolution);
}

bool CAdamantWillCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		PumpCreature(pCard, +2, +2);
		GainCardKeyword(pCard, CardKeyword::Indestructible);
	}
	return false;
}

CAncientAnimusCard::CAncientAnimusCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ancient Animus"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on target creature you control if it's legendary. Then it fights target creature an opponent
	// controls.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAncientAnimusCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAncientAnimusCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCountedCardContainer mine, theirs;
	pDoubleTargetAction->GetTargetGroup1().GetCardSubjects(mine);
	pDoubleTargetAction->GetTargetGroup2().GetCardSubjects(theirs);
	if (mine.GetSize() == 0 || mine.GetAt(0)->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCard* pCreature = mine.GetAt(0);
	if (pCreature->GetCardType().IsLegendary())
		AddPlusCounter(pCreature);
	if (theirs.GetSize() > 0 && theirs.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		Fight(pCreature, theirs.GetAt(0));
	return false;
}

CArborArmamentCard::CArborArmamentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Arbor Armament"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on target creature. That creature gains reach until end of turn.
	AddCreatureSpell(this, GREEN_MANA_TEXT, FALSE, &CArborArmamentCard::BeforeResolution);
}

bool CArborArmamentCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		AddPlusCounter(pCard);
		PumpCreature(pCard, +0, +0, CreatureKeyword::Reach);
	}
	return false;
}

CBefuddleCard::CBefuddleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Befuddle"), CardType::Instant, nID)
{
	// Target creature gets -4/-0 until end of turn. Draw a card.
	CTargetSpell* pSpell = AddCreatureSpell(this, _T("2") BLUE_MANA_TEXT, FALSE, &CBefuddleCard::BeforeResolution);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

bool CBefuddleCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, -4, +0);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

CBlessedLightCard::CBlessedLightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blessed Light"), CardType::Instant, nID)
{
	// Exile target creature or enchantment.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("4") WHITE_MANA_TEXT,
			new CardTypeComparer(CardType::Creature | CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CBlessingOfBelzenlokCard::CBlessingOfBelzenlokCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blessing of Belzenlok"), CardType::Instant, nID)
{
	// Target creature gets +2/+1 until end of turn. If it's legendary, it also gains lifelink until end of turn.
	AddCreatureSpell(this, BLACK_MANA_TEXT, FALSE, &CBlessingOfBelzenlokCard::BeforeResolution);
}

bool CBlessingOfBelzenlokCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		PumpCreature(pCard, +2, +1);
		if (pCard->GetCardType().IsLegendary())
			GainCardKeyword(pCard, CardKeyword::Lifelink);
	}
	return false;
}

CBlinkOfAnEyeCard::CBlinkOfAnEyeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blink of an Eye"), CardType::Instant, nID)
	, m_KickerCost(_T("1") BLUE_MANA_TEXT)
{
	// Kicker {1}{U}. Return target nonland permanent to its owner's hand. If this spell was kicked, draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetCost().AddOptionalManaCost(m_KickerCost);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlinkOfAnEyeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

// The card is drawn before the permanent returns (the callback returns true: ResolveImpl moves the target)
bool CBlinkOfAnEyeCard::BeforeResolution(CAbilityAction* pAction)
{
	if (pAction->GetCostConfigEntry().HasOptionalManaCost(m_KickerCost))
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CCastDownCard::CCastDownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cast Down"), CardType::Instant, nID)
{
	// Destroy target nonlegendary creature.
	AddDestroySpell(this, _T("1") BLACK_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CardTypeComparer(CardType::Legendary, false))));
}

CChargeCard::CChargeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Charge"), CardType::Instant, nID)
{
	// Creatures you control get +1/+1 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChargeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CChargeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +1, +1);
	return true;
}

CDarkBargainCard::CDarkBargainCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dark Bargain"), CardType::Instant, nID)
{
	// Look at the top three cards of your library. Put two of them into your hand and the other into your graveyard.
	// Dark Bargain deals 2 damage to you.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("3") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDarkBargainCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDarkBargainCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	int nCount = pLibrary->GetSize() < 3 ? pLibrary->GetSize() : 3;
	if (nCount > 0)
	{
		int nToHand = nCount < 2 ? nCount : 2;
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nCount, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(nToHand), MaximumValue(nToHand), // two of them
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			CCardFilter::GetFilter(_T("cards")), // what cards
			ZoneId::Hand, // if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top, // placement
			MoveType::Others, // move type
			CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
		pModifier.SetReorderInformation(true, ZoneId::Graveyard, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
		pModifier.ApplyTo(pController);
	}

	CLifeModifier pDamage = CLifeModifier(Life(-2), this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pDamage.ApplyTo(pController);
	return true;
}

CFerventStrikeCard::CFerventStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fervent Strike"), CardType::Instant, nID)
{
	// Target creature gets +1/+0 and gains first strike and haste until end of turn.
	AddCreatureSpell(this, RED_MANA_TEXT, FALSE, &CFerventStrikeCard::BeforeResolution);
}

bool CFerventStrikeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +1, +0, CreatureKeyword::FirstStrike | CreatureKeyword::Haste);
	return false;
}

CFungalInfectionCard::CFungalInfectionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fungal Infection"), CardType::Instant, nID)
{
	// Target creature gets -1/-1 until end of turn. Create a 1/1 green Saproling creature token.
	CTargetSpell* pSpell = AddCreatureSpell(this, BLACK_MANA_TEXT, FALSE, &CFungalInfectionCard::BeforeResolution);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

bool CFungalInfectionCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, -1, -1);

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Saproling (K)"), 62002, 1);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

CGiftOfGrowthCard::CGiftOfGrowthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gift of Growth"), CardType::Instant, nID)
	, m_KickerCost(_T("2"))
{
	// Kicker {2}. Untap target creature. It gets +2/+2 until end of turn. If this spell was kicked, that creature gets
	// +4/+4 until end of turn instead.
	CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") GREEN_MANA_TEXT, FALSE, &CGiftOfGrowthCard::BeforeResolution);
	pSpell->GetCost().AddOptionalManaCost(m_KickerCost);
}

bool CGiftOfGrowthCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	pUntap.ApplyTo(pCard);

	int nBonus = pAction->GetCostConfigEntry().HasOptionalManaCost(m_KickerCost) ? 4 : 2;
	PumpCreature(pCard, nBonus, nBonus);
	return false;
}

CHealingGraceCard::CHealingGraceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Healing Grace"), CardType::Instant, nID)
{
	// Prevent the next 3 damage that would be dealt to any target this turn by a source of your choice. You gain 3 life.
	// Partial: only the life gain (there is no prevention by a chosen source)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, WHITE_MANA_TEXT));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	AddSpell(cpSpell.GetPointer());
}

CInvokeTheDivineCard::CInvokeTheDivineCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Invoke the Divine"), CardType::Instant, nID)
{
	// Destroy target artifact or enchantment. You gain 4 life.
	CTargetMoveCardSpell* pSpell = AddDestroySpell(this, _T("2") WHITE_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false));
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInvokeTheDivineCard::BeforeResolution));
}

bool CInvokeTheDivineCard::BeforeResolution(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 4);
	return true;
}

CPierceTheSkyCard::CPierceTheSkyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pierce the Sky"), CardType::Instant, nID)
{
	// Pierce the Sky deals 7 damage to target creature with flying.
	AddDamageSpell(this, _T("1") GREEN_MANA_TEXT, 7, new CreatureKeywordComparer(CreatureKeyword::Flying, false), FALSE);
}

CRadiatingLightningCard::CRadiatingLightningCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Radiating Lightning"), CardType::Instant, nID)
{
	// Radiating Lightning deals 3 damage to target player and 1 damage to each creature that player controls.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRadiatingLightningCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRadiatingLightningCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	DealDamageToPlayer(this, pPlayer, 3);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);
	return false;
}

CRunAmokCard::CRunAmokCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Run Amok"), CardType::Instant, nID)
{
	// Target attacking creature gets +3/+3 and gains trample until end of turn.
	CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") RED_MANA_TEXT, FALSE, &CRunAmokCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
}

bool CRunAmokCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +3, +3, CreatureKeyword::Trample);
	return false;
}

CShivanFireCard::CShivanFireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shivan Fire"), CardType::Instant, nID)
	, m_KickerCost(_T("4"))
{
	// Kicker {4}. Shivan Fire deals 2 damage to target creature. If this spell was kicked, it deals 4 damage instead.
	CTargetSpell* pSpell = AddCreatureSpell(this, RED_MANA_TEXT, FALSE, &CShivanFireCard::BeforeResolution);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pSpell->GetCost().AddOptionalManaCost(m_KickerCost);
}

bool CShivanFireCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		DealDamageToCreature(this, pCard, pAction->GetCostConfigEntry().HasOptionalManaCost(m_KickerCost) ? 4 : 2);
	return false;
}

CSporeSwarmCard::CSporeSwarmCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spore Swarm"), CardType::Instant, nID)
{
	// Create three 1/1 green Saproling creature tokens.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Instant,
			_T("3") GREEN_MANA_TEXT,
			_T("Saproling (K)"), 62002,
			3));

	AddSpell(cpSpell.GetPointer());
}

CUnwindCard::CUnwindCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unwind"), CardType::Instant, nID)
	, m_LandSelection(pGame, CSelectionSupport::SelectionCallback(this, &CUnwindCard::OnLandsSelected))
{
	// Counter target noncreature spell. Untap up to three lands.
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::Creature, false))));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUnwindCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CUnwindCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand() || !pCard->GetOrientation()->IsTapped())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Untap %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_LandSelection.AddSelectionRequest(entries, 0, entries.size() < 3 ? (int)entries.size() : 3, this, pController);
	return true;
}

void CUnwindCard::OnLandsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				pModifier.ApplyTo(pCard);
		}
}

CViciousOfferingCard::CViciousOfferingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vicious Offering"), CardType::Instant, nID)
{
	// Target creature gets -2/-2 until end of turn.
	CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") BLACK_MANA_TEXT, FALSE, &CViciousOfferingCard::BeforeShrink);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// Kicker - Sacrifice a creature. If this spell was kicked, that creature gets -5/-5 until end of turn instead.
	// (a second spell with the additional cost)
	CTargetSpell* pKicked = AddCreatureSpell(this, _T("1") BLACK_MANA_TEXT, FALSE, &CViciousOfferingCard::BeforeKicked);
	pKicked->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pKicked->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	pKicked->SetAbilityText(_T("Casts kicked"));
	pKicked->SetMainSpell(FALSE);
}

bool CViciousOfferingCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, -2, -2);
	return false;
}

bool CViciousOfferingCard::BeforeKicked(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, -5, -5);
	return false;
}

CWildOnslaughtCard::CWildOnslaughtCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wild Onslaught"), CardType::Instant, nID)
	, m_KickerCost(_T("4"))
{
	// Kicker {4}. Put a +1/+1 counter on each creature you control. If this spell was kicked, put two +1/+1 counters on
	// each creature you control instead.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("3") GREEN_MANA_TEXT));

	cpSpell->GetCost().AddOptionalManaCost(m_KickerCost);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWildOnslaughtCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWildOnslaughtCard::BeforeResolution(CAbilityAction* pAction)
{
	int nCount = pAction->GetCostConfigEntry().HasOptionalManaCost(m_KickerCost) ? 2 : 1;
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i), nCount);
	return true;
}

CWizardsLightningCard::CWizardsLightningCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wizard's Lightning"), CardType::Instant, nID)
{
	// This spell costs {2} less to cast if you control a Wizard. Wizard's Lightning deals 3 damage to any target.
	// (a second spell for {R}; it can't target planeswalkers)
	AddDamageSpell(this, _T("2") RED_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	CTargetChgLifeSpell* pCheap = AddDamageSpell(this, RED_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	pCheap->SetAbilityText(_T("Wizard's Lightning (costs {2} less: you control a Wizard). Casts"));
	AddPlayableIf(this, pCheap, &CWizardsLightningCard::ControlsWizard);
}

BOOL CWizardsLightningCard::ControlsWizard(BOOL bIncludeTricks)
{
	return ControlsType(GetController(), CREATURE_TYPE(Wizard));
}

CWizardsRetortCard::CWizardsRetortCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wizard's Retort"), CardType::Instant, nID)
{
	// This spell costs {1} less to cast if you control a Wizard. Counter target spell. (a second spell for {U}{U})
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				i == 0 ? _T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT : BLUE_MANA_TEXT BLUE_MANA_TEXT,
				new TrueCardComparer));

		if (i == 1)
		{
			cpSpell->SetAbilityText(_T("Wizard's Retort (costs {1} less: you control a Wizard). Casts"));
			AddPlayableIf(this, cpSpell.GetPointer(), &CWizardsRetortCard::ControlsWizard);
		}
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CWizardsRetortCard::ControlsWizard(BOOL bIncludeTricks)
{
	return ControlsType(GetController(), CREATURE_TYPE(Wizard));
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (creatures)

// "Whenever you cast a historic spell, <effect>" (rule 700.6, HistoricComparer)
template <class T>
static void AddHistoricCastTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new HistoricComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever you cast a historic spell, <effect on target creature>" (the callback returns false)
template <class T>
static CTargeting* AddHistoricCastTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new HistoricComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

//____________________________________________________________________________
//
// White creatures

CAvenSentryCard::CAvenSentryCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Sentry"), CardType::Creature, CREATURE_TYPE2(Bird, Soldier), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(2))
{
}

CBairdStewardOfArgiveCard::CBairdStewardOfArgiveCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Baird, Steward of Argive"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(4))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Creatures can't attack you or planeswalkers you control unless their controller pays {1} for each of those
	// creatures. (as Ghostly Prison in Champions of Kamigawa)
	counted_ptr<CConsAttackExtraManaEnchantment> cpAbility(
		::CreateObject<CConsAttackExtraManaEnchantment>(this,
			new AnyCreatureComparer,
			_T("1")));

	cpAbility->SetAffectOpponentCardsOnly();
	cpAbility->SetAffectOnlyPlayerDeclaration();
	AddAbility(cpAbility.GetPointer());
}

CBenalishHonorGuardCard::CBenalishHonorGuardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Benalish Honor Guard"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// This creature gets +1/+0 for each legendary creature you control. (as Nim Grotesque in Fifth Dawn)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new AndCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Legendary, false))));

	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());
}

CBenalishMarshalCard::CBenalishMarshalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Benalish Marshal"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Other creatures you control get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CDanithaCapashenParagonCard::CDanithaCapashenParagonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Danitha Capashen, Paragon"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// First strike, vigilance, lifelink
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// Aura and Equipment spells you cast cost {1} less to cast.
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CardTypeComparer(CardType::_Aura | CardType::Equipment, false),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CDaringArchaeologistCard::CDaringArchaeologistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Daring Archaeologist"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you may return target artifact card from your graveyard to your hand.
	// Note: the card is chosen on resolution (not targeted)
	AddEnterTrigger(this, &CDaringArchaeologistCard::BeforeReturn, true);

	// Whenever you cast a historic spell, put a +1/+1 counter on this creature.
	AddHistoricCastTrigger(this, &CDaringArchaeologistCard::BeforeCounter);
}

bool CDaringArchaeologistCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("artifacts")), ZoneId::Hand, MoveType::Others);
	return true;
}

bool CDaringArchaeologistCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

CDauntlessBodyguardCard::CDauntlessBodyguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dauntless Bodyguard"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT, Power(2), Life(1))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDauntlessBodyguardCard::OnCreatureSelected))
{
	// As this creature enters, choose another creature you control.
	// Note: the creature is chosen by a trigger when it enters
	AddEnterTrigger(this, &CDauntlessBodyguardCard::BeforeChoose);

	// Sacrifice this creature: The chosen creature gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("The chosen creature gains indestructible until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDauntlessBodyguardCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CDauntlessBodyguardCard::BeforeChoose(CAbilityAction* pAction)
{
	while (m_Chosen.GetSize() > 0)
		m_Chosen.RemoveCard(m_Chosen.GetAt(0));

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard == this)
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Choose %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CDauntlessBodyguardCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			m_Chosen.AddCard((CCard*)it->dwContext, CardPlacement::Top);
}

bool CDauntlessBodyguardCard::BeforeIndestructible(CAbilityAction* pAction)
{
	for (int i = 0; i < m_Chosen.GetSize(); ++i)
		if (m_Chosen.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			GainCardKeyword(m_Chosen.GetAt(i), CardKeyword::Indestructible);
	return true;
}

CDAvenantTrapperCard::CDAvenantTrapperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("D'Avenant Trapper"), CardType::Creature, CREATURE_TYPE2(Human, Archer), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Whenever you cast a historic spell, tap target creature an opponent controls.
	CTargeting* pTargeting = AddHistoricCastTargetTrigger(this, &CDAvenantTrapperCard::BeforeTap, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CDAvenantTrapperCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CEvraHalcyonWitnessCard::CEvraHalcyonWitnessCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Evra, Halcyon Witness"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Avatar), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// {4}: Exchange your life total with Evra's power.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("4")));

	cpAbility->SetAbilityText(_T("Exchange your life total with Evra's power. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEvraHalcyonWitnessCard::BeforeExchange));
	AddAbility(cpAbility.GetPointer());
}

bool CEvraHalcyonWitnessCard::BeforeExchange(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pAction->GetController();
	int nLife = (int)pController->GetLife();
	int nPower = (int)GetPower();

	// The power becomes the old life total (a permanent change of power)
	if (nLife != nPower)
	{
		CPowerModifier pPower = CPowerModifier(Power(nLife - nPower), FALSE);
		pPower.ApplyTo(this);

		CLifeModifier pLife = CLifeModifier(Life(nPower - nLife), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pLife.ApplyTo(pController);
	}
	return true;
}

CExcavationElephantCard::CExcavationElephantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Excavation Elephant"), CardType::Creature, CREATURE_TYPE(Elephant), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(5))
	, m_KickerCost(_T("1") WHITE_MANA_TEXT)
{
	// Kicker {1}{W} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, return target artifact card from your graveyard to your hand.
	// Note: the card is chosen on resolution (not targeted)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CExcavationElephantCard::SetKickedContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExcavationElephantCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

// The trigger needs the creature cast with its kicker (as Gatekeeper of Malakir in Zendikar)
bool CExcavationElephantCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CExcavationElephantCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("artifacts")), ZoneId::Hand, MoveType::Others);
	return true;
}

CKnightOfGraceCard::CKnightOfGraceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of Grace"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_HexproofFrom(this, new CardTypeComparer(CardType::Black, false))
{
	// First strike. Hexproof from black (CHexproofFromSupport)
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// This creature gets +1/+0 as long as any player controls a black permanent.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new AnyBlackPermanentComparer),
			Power(+1), Life(+0)));

	AddAbility(cpAbility.GetPointer());
}

CKnightOfNewBenaliaCard::CKnightOfNewBenaliaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of New Benalia"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
{
}

CKwendePrideOfFemerefCard::CKwendePrideOfFemerefCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kwende, Pride of Femeref"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Double strike
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// Creatures you control with first strike have double strike.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CreatureKeywordComparer(CreatureKeyword::FirstStrike, false),
			Power(+0), Life(+0), CreatureKeyword::DoubleStrike));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CLyraDawnbringerCard::CLyraDawnbringerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Lyra Dawnbringer"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	// Flying, first strike, lifelink
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// Other Angels you control get +1/+1 and have lifelink.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Angel), false), new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	AddAbility(cpAbility.GetPointer());
}

CMesaUnicornCard::CMesaUnicornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mesa Unicorn"), CardType::Creature, CREATURE_TYPE(Unicorn), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

CPegasusCourserCard::CPegasusCourserCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Pegasus Courser"), CardType::Creature, CREATURE_TYPE(Pegasus), nID,
		_T("2") WHITE_MANA_TEXT, Power(1), Life(3))
{
	// Whenever this creature attacks, another target attacking creature gains flying until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CPegasusCourserCard::BeforeFlying, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CPegasusCourserCard::BeforeFlying(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +0, +0, CreatureKeyword::Flying);
	return false;
}

CSanctumSpiritCard::CSanctumSpiritCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sanctum Spirit"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(2))
	, m_HistoricFilter(_T("a historic card"), _T("historic cards"), new HistoricComparer)
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// Discard a historic card: This creature gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddDiscardCardCost(1, &m_HistoricFilter);
	cpAbility->SetAbilityText(_T("This creature gains indestructible until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSanctumSpiritCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CSanctumSpiritCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GainCardKeyword(this, CardKeyword::Indestructible);
	return true;
}

CSergeantAtArmsCard::CSergeantAtArmsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sergeant-at-Arms"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
	, m_KickerCost(_T("2") WHITE_MANA_TEXT)
{
	// Kicker {2}{W} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, create two 1/1 white Soldier creature tokens.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSergeantAtArmsCard::SetKickedContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSergeantAtArmsCard::BeforeTokens));
		AddAbility(cpAbility.GetPointer());
	}
}

// The trigger needs the creature cast with its kicker (as Gatekeeper of Malakir in Zendikar)
bool CSergeantAtArmsCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CSergeantAtArmsCard::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID, 2);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSerraDiscipleCard::CSerraDiscipleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Serra Disciple"), CardType::Creature, CREATURE_TYPE2(Bird, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Flying, first strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Whenever you cast a historic spell, this creature gets +1/+1 until end of turn.
	AddHistoricCastTrigger(this, &CSerraDiscipleCard::BeforePump);
}

bool CSerraDiscipleCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

CShalaiVoiceOfPlentyCard::CShalaiVoiceOfPlentyCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shalai, Voice of Plenty"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(4))
{
	{
		// You, planeswalkers you control, and other creatures you control have hexproof.
		// Partial: the other creatures have hexproof and you can't be the target of your opponents' spells (as Leyline
		// of Sanctity); the planeswalkers don't get hexproof
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+0), Life(+0)));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantBeTargetedByOpponentsSpells));

		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{G}{G}: Put a +1/+1 counter on each creature you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT));

		cpAbility->SetAbilityText(_T("Put a +1/+1 counter on each creature you control. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShalaiVoiceOfPlentyCard::BeforeCounters));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CShalaiVoiceOfPlentyCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i));
	return true;
}

CTesharAncestorsApostleCard::CTesharAncestorsApostleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Teshar, Ancestor's Apostle"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Bird, Cleric), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_ReturnFilter(_T("a creature card with mana value 3 or less"), _T("creature cards with mana value 3 or less"),
		new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::less_equal<int>>(3)))
{
	// Whenever you cast a historic spell, return target creature card with mana value 3 or less from your graveyard to
	// the battlefield.
	// Note: the card is chosen on resolution (not targeted)
	AddHistoricCastTrigger(this, &CTesharAncestorsApostleCard::BeforeReturn);
}

bool CTesharAncestorsApostleCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, &m_ReturnFilter, ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (green creatures)

// "Double this creature's power and toughness until end of turn" (rule 701.10b-c: +X/+Y with its current power and
// toughness; a negative value gives -X instead)
static void DoublePowerToughness(CCreatureCard* pCreature)
{
	int nPower = (int)pCreature->GetPower();
	int nToughness = (int)pCreature->GetToughness();
	if (nPower != 0 || nToughness != 0)
		PumpCreature(pCreature, nPower, nToughness);
}

// The creature enters with nCounters +1/+1 counters if it was cast with its kicker (as AEther Figment in Zendikar)
static void PutKickerCounters(CCard* pCard, CZone* pFromZone, CZone* pToZone, MoveType moveType, const CManaCost& kickerCost, int nCounters)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		pCard->GetLastCastingCostConfigEntry().HasOptionalManaCost(kickerCost))
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), nCounters);
		pModifier.ApplyTo(pCard);
	}
}

//____________________________________________________________________________
//
// Green creatures

CBalothGorgerCard::CBalothGorgerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Baloth Gorger"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_KickerCost(_T("4"))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CBalothGorgerCard::OnZoneChanged))
{
	// Kicker {4}. If this creature was kicked, it enters with three +1/+1 counters on it. (as AEther Figment in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CBalothGorgerCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard == this)
		PutKickerCounters(this, pFromZone, pToZone, moveType, m_KickerCost, 3);
}

CElfhameDruidCard::CElfhameDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elfhame Druid"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(0), Life(2))
{
	// {T}: Add {G}.
	AddTapManaAbility(this, GREEN_MANA_TEXT);

	// {T}: Add {G}{G}. Spend this mana only to cast kicked spells.
	// Not implemented: there is no restricted mana
}

CGaeasProtectorCard::CGaeasProtectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gaea's Protector"), CardType::Creature, CREATURE_TYPE2(Elemental, Warrior), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(2))
{
	// This creature must be blocked if able.
	// Not implemented: there is no "must be blocked if able" (as Fibrous Entangler in Eldritch Moon)
}

CGrunnTheLonelyKingCard::CGrunnTheLonelyKingCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grunn, the Lonely King"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Ape, Warrior), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
	, m_KickerCost(_T("3"))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CGrunnTheLonelyKingCard::OnZoneChanged))
{
	// Kicker {3}. If Grunn was kicked, it enters with five +1/+1 counters on it. (as AEther Figment in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// Whenever Grunn attacks alone, double its power and toughness until end of turn. (as Reckless Ogre in Exodus)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingAloneEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrunnTheLonelyKingCard::BeforeDouble));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

void CGrunnTheLonelyKingCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard == this)
		PutKickerCounters(this, pFromZone, pToZone, moveType, m_KickerCost, 5);
}

bool CGrunnTheLonelyKingCard::BeforeDouble(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		DoublePowerToughness(this);
	return true;
}

CKrosanDruidCard::CKrosanDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Krosan Druid"), CardType::Creature, CREATURE_TYPE2(Centaur, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
	, m_KickerCost(_T("4") GREEN_MANA_TEXT)
{
	// Kicker {4}{G} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, you gain 10 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKrosanDruidCard::SetKickedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKrosanDruidCard::BeforeGainLife));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CKrosanDruidCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CKrosanDruidCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 10);
	return true;
}

CLlanowarEnvoyCard::CLlanowarEnvoyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Llanowar Envoy"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// {1}{G}: Add one mana of any color.
	LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("1") GREEN_MANA_TEXT, AbilityType::Activated, mana[i]));
		AddAbility(cpAbility.GetPointer());
	}
}

CLlanowarScoutCard::CLlanowarScoutCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Llanowar Scout"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3))
{
	// {T}: You may put a land card from your hand onto the battlefield.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Put a land card from your hand onto the battlefield. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLlanowarScoutCard::BeforePutLand));
	AddAbility(cpAbility.GetPointer());
}

bool CLlanowarScoutCard::BeforePutLand(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, CCardFilter::GetFilter(_T("lands")), ZoneId::Battlefield, MoveType::Others);
	return true;
}

CMammothSpiderCard::CMammothSpiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mammoth Spider"), CardType::Creature, CREATURE_TYPE(Spider), nID,
		_T("4") GREEN_MANA_TEXT, Power(3), Life(5))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);
}

CMarwynTheNurturerCard::CMarwynTheNurturerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Marwyn, the Nurturer"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever another Elf you control enters, put a +1/+1 counter on Marwyn.
	AddAnotherTypeEntersTrigger(this, CREATURE_TYPE(Elf), FALSE, &CMarwynTheNurturerCard::BeforeCounter);

	// {T}: Add an amount of {G} equal to Marwyn's power.
	// (one mana ability for each power from 1 to 6 or more, as Powerstone Shard; with power 7 or more it adds {G}x6)
	LPCTSTR mana[] = { GREEN_MANA_TEXT, GREEN_MANA_TEXT GREEN_MANA_TEXT, GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT };
	typedef BOOL (CMarwynTheNurturerCard::*Condition)(BOOL);
	Condition conditions[] = { &CMarwynTheNurturerCard::Has1, &CMarwynTheNurturerCard::Has2, &CMarwynTheNurturerCard::Has3,
		&CMarwynTheNurturerCard::Has4, &CMarwynTheNurturerCard::Has5, &CMarwynTheNurturerCard::Has6 };
	for (int i = 0; i < 6; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, mana[i]));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), conditions[i]);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMarwynTheNurturerCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

BOOL CMarwynTheNurturerCard::HasPower(int nPower) const
{
	int nCurrent = (int)GetPower();
	return nPower == 6 ? nCurrent >= 6 : nCurrent == nPower;
}

CMultaniYavimayasAvatarCard::CMultaniYavimayasAvatarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Multani, Yavimaya's Avatar"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elemental, Avatar), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(0))
{
	// Reach, trample
	GetCreatureKeyword()->AddReach(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// Multani gets +1/+1 for each land you control and each land card in your graveyard. (as Nim Grotesque and Maro,
	// one ability for each zone)
	ZoneId zones[] = { ZoneId::Battlefield, ZoneId::Graveyard };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				zones[i],
				new CardTypeComparer(CardType::_Land, false)));

		AddAbility(cpAbility.GetPointer());
	}

	// {1}{G}, Return two lands you control to their owner's hand: Return this card from your graveyard to your hand.
	// (the cost as Uyo, Silent Prophet in Champions of Kamigawa)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") GREEN_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->GetCost().AddReturnFromPlayCardCost(2, CCardFilter::GetFilter(_T("lands")));
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMultaniYavimayasAvatarCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CMultaniYavimayasAvatarCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(this);
	}
	return true;
}

CPrimordialWurmCard::CPrimordialWurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Primordial Wurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(6))
{
}

CSporecrownThallidCard::CSporecrownThallidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sporecrown Thallid"), CardType::Creature, CREATURE_TYPE(Fungus), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Each other creature you control that's a Fungus or Saproling gets +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(
				new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Fungus), false), new CreatureTypeComparer(CREATURE_TYPE(Saproling), false)),
				new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CSteelLeafChampionCard::CSteelLeafChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steel Leaf Champion"), CardType::Creature, CREATURE_TYPE2(Elf, Knight), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(4))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 2 or less. (as Giltgrove Stalker in Rivals of Ixalan)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

CTerritorialAllosaurusCard::CTerritorialAllosaurusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Territorial Allosaurus"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
	, m_KickerCost(_T("2") GREEN_MANA_TEXT)
{
	// Kicker {2}{G} (as Kor Aeronaut in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, it fights another target creature.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTerritorialAllosaurusCard::SetKickedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTerritorialAllosaurusCard::BeforeFight));
	AddAbility(cpAbility.GetPointer());
}

bool CTerritorialAllosaurusCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CTerritorialAllosaurusCard::BeforeFight(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && GetZoneId() == ZoneId::Battlefield)
		Fight(this, pCard);
	return false;
}

CUntamedKavuCard::CUntamedKavuCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Untamed Kavu"), CardType::Creature, CREATURE_TYPE(Kavu), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_KickerCost(_T("3"))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CUntamedKavuCard::OnZoneChanged))
{
	// Vigilance, trample
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// Kicker {3}. If this creature was kicked, it enters with three +1/+1 counters on it. (as AEther Figment in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CUntamedKavuCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard == this)
		PutKickerCounters(this, pFromZone, pToZone, moveType, m_KickerCost, 3);
}

CYavimayaSapherdCard::CYavimayaSapherdCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yavimaya Sapherd"), CardType::Creature, CREATURE_TYPE(Fungus), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, create a 1/1 green Saproling creature token.
	AddEnterTrigger(this, &CYavimayaSapherdCard::BeforeToken);
}

bool CYavimayaSapherdCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Saproling (K)"), 62002, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

#define ELEMENTAL_Y_TOKEN_NAME		_T("Elemental (Y)")
#define ELEMENTAL_Y_TOKEN_ID		55063
#define KAROX_BLADEWING_TOKEN_NAME	_T("Karox Bladewing")
#define KAROX_BLADEWING_TOKEN_ID	55113

// "When this creature enters, if <condition>, <effect>" with the condition in the context function (as Gatekeeper of
// Malakir in Zendikar)
template <class T>
static void AddEnterIfTrigger(T* pCard,
	bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CZone*, CZone*, CPlayer*, MoveType) const,
	bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

CBloodstoneGoblinCard::CBloodstoneGoblinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodstone Goblin"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast a spell, if that spell was kicked, this creature gets +1/+1 and gains menace until end of turn.
	// Note: a spell is kicked if an optional mana cost was paid (the spells kicked with a second spell aren't seen)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodstoneGoblinCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBloodstoneGoblinCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CBloodstoneGoblinCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return pCard && !pCard->GetLastCastingCostConfigEntry().GetOptionalManaCosts().empty();
}

bool CBloodstoneGoblinCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1, CreatureKeyword::CantBeBlockedBy1);
	return true;
}

CChampionOfTheFlameCard::CChampionOfTheFlameCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Champion of the Flame"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(1))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// This creature gets +2/+2 for each Aura and Equipment attached to it. (as Uril, the Miststalker in Alara Reborn)
	// Partial: only the Auras are counted (the engine doesn't count the Equipment attached)
	counted_ptr<CPwrTghAttrEnchantmentCount> cpAbility(
		::CreateObject<CPwrTghAttrEnchantmentCount>(this,
			new SpecificCardComparer(this),
			Power(+2), Life(+2)));

	AddAbility(cpAbility.GetPointer());
}

CFirefistAdeptCard::CFirefistAdeptCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Firefist Adept"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("4") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, it deals X damage to target creature an opponent controls, where X is the number of
	// Wizards you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CFirefistAdeptCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CFirefistAdeptCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	int nWizards = CountType(pAction->GetController(), CREATURE_TYPE(Wizard));
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && nWizards > 0)
		DealDamageToCreature(this, pCard, nWizards);
	return false;
}

CGhituChroniclerCard::CGhituChroniclerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghitu Chronicler"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
	, m_KickerCost(_T("3") RED_MANA_TEXT)
{
	// Kicker {3}{R} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, return target instant or sorcery card from your graveyard to your
	// hand.
	// Note: the card is chosen on resolution (not targeted)
	AddEnterIfTrigger(this, &CGhituChroniclerCard::SetKickedContext, &CGhituChroniclerCard::BeforeReturn);
}

bool CGhituChroniclerCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CGhituChroniclerCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("instant cards or sorcery cards")), ZoneId::Hand, MoveType::Others);
	return true;
}

CGhituJourneymageCard::CGhituJourneymageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghitu Journeymage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, if you control another Wizard, this creature deals 2 damage to each opponent.
	AddEnterIfTrigger(this, &CGhituJourneymageCard::SetTriggerContext, &CGhituJourneymageCard::BeforeDamage);
}

bool CGhituJourneymageCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return CountType(GetController(), CREATURE_TYPE(Wizard)) >= 2;
}

bool CGhituJourneymageCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	return true;
}

CGhituLavarunnerCard::CGhituLavarunnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghitu Lavarunner"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		RED_MANA_TEXT, Power(1), Life(2))
{
	// As long as there are two or more instant and/or sorcery cards in your graveyard, this creature gets +1/+0 and has
	// haste. (the condition as in Amonkhet)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+0), CreatureKeyword::Haste));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->SetConditionCheckZone(ZoneId::Graveyard);
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(2);
	AddAbility(cpAbility.GetPointer());
}

CGoblinChainwhirlerCard::CGoblinChainwhirlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Chainwhirler"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature enters, it deals 1 damage to each opponent and each creature and planeswalker they control.
	// (the damage to the planeswalkers removes loyalty counters)
	AddEnterTrigger(this, &CGoblinChainwhirlerCard::BeforeDamage);
}

bool CGoblinChainwhirlerCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DamageEachOpponent(this, pController, 1);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);

	CCardCounterModifier pLoyalty = CCardCounterModifier(LOYALTY_COUNTER, -1);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		CCountedCardContainer planeswalkers;
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsPlaneswalker())
				planeswalkers.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
		for (int i = 0; i < planeswalkers.GetSize(); ++i)
			pLoyalty.ApplyTo(planeswalkers.GetAt(i));
	}
	return true;
}

CKarplusanHoundCard::CKarplusanHoundCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Karplusan Hound"), CardType::Creature, CREATURE_TYPE(Dog), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// Whenever this creature attacks, if you control a Chandra planeswalker, this creature deals 2 damage to any
	// target.
	// Note: the condition is checked on resolution, and it can't target planeswalkers
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CKarplusanHoundCard::BeforeDamage, Characteristic::Negative);
	pTargeting->SetIncludePlayers(TRUE);
}

bool CKarplusanHoundCard::BeforeDamage(CAbilityAction* pAction)
{
	CCardFilter chandra(_T("a Chandra planeswalker"), _T("Chandra planeswalkers"), new PlaneswalkerTypeComparer(PlaneswalkerType::Chandra));
	if (chandra.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
		DealDamageToTarget(this, pAction, 2);
	return false;
}

CKeldonOverseerCard::CKeldonOverseerCard(CGame* pGame, UINT nID)
	: CHasteCreatureCard(pGame, _T("Keldon Overseer"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(1))
	, m_KickerCost(_T("3") RED_MANA_TEXT)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CKeldonOverseerCard::OnResolutionCompleted))
{
	// Kicker {3}{R} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, gain control of target creature until end of turn. Untap that
	// creature. It gains haste until end of turn. (as Zealous Conscripts in Avacyn Restored)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Battlefield));

	CGainControlModifier* pGain = new CGainControlModifier(GetGame(), (CCard*)this);
	CGainControlModifier* pReturn = new CGainControlModifier(GetGame(), (CCard*)this, true);
	CScheduledCardModifier* pSchedule = new CScheduledCardModifier(
		pGame, pReturn, TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::ApplyToLater);
	pGain->LinkCardModifier(pSchedule);
	cpAbility->GetMoveCardModifier().LinkCardModifier(pGain);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(FALSE);

	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKeldonOverseerCard::SetKickedContext));
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddAbility(cpAbility.GetPointer());
}

bool CKeldonOverseerCard::SetKickedContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

void CKeldonOverseerCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(pAbilityAction->GetAssociatedCard());
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return;

	CCreatureKeywordModifier pHaste;
	pHaste.GetModifier().SetToAdd(CreatureKeyword::Haste);
	pHaste.GetModifier().SetOneTurnOnly(TRUE);
	pHaste.ApplyTo(pTarget);

	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	pUntap.ApplyTo(pTarget);
}

CKeldonRaiderCard::CKeldonRaiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Keldon Raider"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
{
	// When this creature enters, you may discard a card. If you do, draw a card.
	AddEnterTrigger(this, &CKeldonRaiderCard::BeforeDiscard, true);
}

bool CKeldonRaiderCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	int nBefore = pHand->GetSize();
	if (nBefore == 0)
		return true;

	DiscardCards(GetGame(), pController, 1);
	if (pHand->GetSize() < nBefore)
		DrawCards(GetGame(), pController, 1);
	return true;
}

CKeldonWarcallerCard::CKeldonWarcallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Keldon Warcaller"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, put a lore counter on target Saga you control.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new SagaComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKeldonWarcallerCard::BeforeLore));
	AddAbility(cpAbility.GetPointer());
}

bool CKeldonWarcallerCard::BeforeLore(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	CSagaSupport* pSaga = pCard ? CSagaSupport::Find(pCard) : NULL;
	if (pSaga && pCard->GetZoneId() == ZoneId::Battlefield)
		pSaga->AddLoreCounters(1);
	return false;
}

COrcishVandalCard::COrcishVandalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Orcish Vandal"), CardType::Creature, CREATURE_TYPE2(Orc, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(1))
{
	// {T}, Sacrifice an artifact: This creature deals 2 damage to any target.
	// Note: it can't target planeswalkers
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CPyromanticPilgrimCard::CPyromanticPilgrimCard(CGame* pGame, UINT nID)
	: CHasteCreatureCard(pGame, _T("Pyromantic Pilgrim"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(1))
{
}

CRampagingCyclopsCard::CRampagingCyclopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rampaging Cyclops"), CardType::Creature, CREATURE_TYPE(Cyclops), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(4))
{
	// This creature gets -2/-0 as long as two or more creatures are blocking it.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new BlockedByTwoComparer),
			Power(-2), Life(+0)));

	AddAbility(cpAbility.GetPointer());
}

CSqueeTheImmortalCard::CSqueeTheImmortalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Squee, the Immortal"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Goblin), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, Power(2), Life(1))
{
	// You may cast this card from your graveyard or from exile. (a second spell from the graveyard, as Oathsworn
	// Vampire in Rivals of Ixalan)
	// Partial: it can't be cast from exile
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("1") RED_MANA_TEXT RED_MANA_TEXT, TRUE));
	cpSpell->SetGraveyardOnly();
	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetAbilityText(_T("Squee from your graveyard. Casts"));
	AddSpell(cpSpell.GetPointer());
}

CTwoHeadedGiantCard::CTwoHeadedGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Two-Headed Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Warrior), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// Whenever this creature attacks, flip two coins. If both coins come up heads, this creature gains double strike
	// until end of turn. If both coins come up tails, this creature gains menace until end of turn.
	AddSelfAttackTrigger(this, &CTwoHeadedGiantCard::BeforeFlip);
}

// (the coins as in M12: GetRand() % 2)
bool CTwoHeadedGiantCard::BeforeFlip(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCoin1 = pController->GetRand() % 2;
	int nCoin2 = pController->GetRand() % 2;

	if (!pAction->GetGame()->IsThinking())
	{
		CString strMessage;
		strMessage.Format(_T("%s flips two coins: %s and %s"), GetCardName(TRUE),
			nCoin1 ? _T("heads") : _T("tails"), nCoin2 ? _T("heads") : _T("tails"));
		GetGame()->Message(strMessage, pController->IsComputer() ? GetGame()->GetComputerImage() : GetGame()->GetHumanImage(),
			MessageImportance::High);
	}

	if (GetZoneId() != ZoneId::Battlefield)
		return true;
	if (nCoin1 && nCoin2)
		PumpCreature(this, +0, +0, CreatureKeyword::DoubleStrike);
	else if (!nCoin1 && !nCoin2)
		PumpCreature(this, +0, +0, CreatureKeyword::CantBeBlockedBy1);
	return true;
}

CValdukKeeperOfTheFlameCard::CValdukKeeperOfTheFlameCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Valduk, Keeper of the Flame"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Shaman), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// At the beginning of combat on your turn, for each Aura and Equipment attached to Valduk, create a 3/1 red
	// Elemental creature token with trample and haste. Exile those tokens at the beginning of the next end step.
	// (Elemental (Y) exiles itself at the next end step)
	// Partial: only the Auras are counted (the engine doesn't count the Equipment attached)
	AddStepTrigger(this, NodeId::BeginningOfCombatStep, false, &CValdukKeeperOfTheFlameCard::SetTriggerContext, &CValdukKeeperOfTheFlameCard::BeforeTokens);
}

bool CValdukKeeperOfTheFlameCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetEnchantCount() > 0;
}

bool CValdukKeeperOfTheFlameCard::BeforeTokens(CAbilityAction* pAction)
{
	int nCount = GetEnchantCount();
	if (nCount > 0)
	{
		CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ELEMENTAL_Y_TOKEN_NAME, ELEMENTAL_Y_TOKEN_ID, nCount);
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CVerixBladewingCard::CVerixBladewingCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Verix Bladewing"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Dragon), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
	, m_KickerCost(_T("3"))
{
	// Kicker {3} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When Verix Bladewing enters, if it was kicked, create Karox Bladewing, a legendary 4/4 red Dragon creature token
	// with flying.
	AddEnterIfTrigger(this, &CVerixBladewingCard::SetKickedContext, &CVerixBladewingCard::BeforeToken);
}

bool CVerixBladewingCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CVerixBladewingCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), KAROX_BLADEWING_TOKEN_NAME, KAROX_BLADEWING_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CWarcryPhoenixCard::CWarcryPhoenixCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Warcry Phoenix"), CardType::Creature, CREATURE_TYPE(Phoenix), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(2))
{
	// Flying, haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever you attack with three or more creatures, you may pay {2}{R}. If you do, return this card from your
	// graveyard to the battlefield tapped and attacking.
	// Not implemented: a card can't enter the battlefield attacking
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

#define ZOMBIE_KNIGHT_TOKEN_NAME	_T("Zombie Knight")
#define ZOMBIE_KNIGHT_TOKEN_ID		55114

CCabalEvangelCard::CCabalEvangelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cabal Evangel"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
}

CCabalPaladinCard::CCabalPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cabal Paladin"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// Whenever you cast a historic spell, this creature deals 2 damage to each opponent.
	AddHistoricCastTrigger(this, &CCabalPaladinCard::BeforeDamage);
}

bool CCabalPaladinCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	return true;
}

CCaligoSkinWitchCard::CCaligoSkinWitchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Caligo Skin-Witch"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(3))
	, m_KickerCost(_T("3") BLACK_MANA_TEXT)
{
	// Kicker {3}{B} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When this creature enters, if it was kicked, each opponent discards two cards.
	AddEnterIfTrigger(this, &CCaligoSkinWitchCard::SetKickedContext, &CCaligoSkinWitchCard::BeforeDiscard);
}

bool CCaligoSkinWitchCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CCaligoSkinWitchCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 2);
	return true;
}

CDeathbloomThallidCard::CDeathbloomThallidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deathbloom Thallid"), CardType::Creature, CREATURE_TYPE(Fungus), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// When this creature dies, create a 1/1 green Saproling creature token.
	AddDiesTrigger(this, &CDeathbloomThallidCard::BeforeToken);
}

bool CDeathbloomThallidCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SAPROLING_TOKEN_NAME, 62002, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CDemonlordBelzenlokCard::CDemonlordBelzenlokCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Demonlord Belzenlok"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Demon), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(6))
{
	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When Demonlord Belzenlok enters, exile cards from the top of your library until you exile a nonland card, then
	// put that card into your hand. If the card's mana value is 4 or greater, repeat this process. Demonlord Belzenlok
	// deals 1 damage to you for each card put into your hand this way.
	AddEnterTrigger(this, &CDemonlordBelzenlokCard::BeforeExile);
}

bool CDemonlordBelzenlokCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others);
	CMoveCardModifier pToHand = CMoveCardModifier(ZoneId::Exile, ZoneId::Hand, TRUE, MoveType::Others);

	int nCards = 0;
	bool bRepeat = true;
	while (bRepeat && pLibrary->GetSize() > 0)
	{
		bRepeat = false;
		while (pLibrary->GetSize() > 0)
		{
			CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
			pExile.ApplyTo(pCard);
			if (pCard->GetCardType().IsLand())
				continue;

			pToHand.ApplyTo(pCard);
			++nCards;
			bRepeat = pCard->GetConvertedManaCost() >= 4;
			break;
		}
	}

	if (nCards > 0)
	{
		CLifeModifier pDamage = CLifeModifier(Life(-nCards), this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pDamage.ApplyTo(pController);
	}
	return true;
}

CDreadShadeCard::CDreadShadeCard(CGame* pGame, UINT nID)
	: CPumpCreatureCard(pGame, _T("Dread Shade"), CardType::Creature, CREATURE_TYPE(Shade), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3),
		BLACK_MANA_TEXT, Power(+1), Life(+1))
{
	// {B}: This creature gets +1/+1 until end of turn. (as Frozen Shade in Unlimited)
}

CDrudgeSentinelCard::CDrudgeSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Drudge Sentinel"), CardType::Creature, CREATURE_TYPE2(Skeleton, Warrior), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// {3}: Tap this creature. It gains indestructible until end of turn.
	AddPumpAbility(this, _T("3"), _T("Tap and gain indestructible. Activates"), &CDrudgeSentinelCard::BeforeTap);
}

bool CDrudgeSentinelCard::BeforeTap(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	if (!GetOrientation()->IsTapped())
		CCardOrientationModifier(TRUE).ApplyTo(this);
	GetCardKeyword()->AddIndestructible(TRUE);
	return true;
}

CFeralAbominationCard::CFeralAbominationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Feral Abomination"), CardType::Creature, CREATURE_TYPE(Thrull), nID,
		_T("5") BLACK_MANA_TEXT, Power(5), Life(5))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);
}

CJosuVessLichKnightCard::CJosuVessLichKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Josu Vess, Lich Knight"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Zombie, Knight), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(5))
	, m_KickerCost(_T("5") BLACK_MANA_TEXT)
{
	// Kicker {5}{B} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When Josu Vess enters, if he was kicked, create eight 2/2 black Zombie Knight creature tokens with menace.
	AddEnterIfTrigger(this, &CJosuVessLichKnightCard::SetKickedContext, &CJosuVessLichKnightCard::BeforeTokens);
}

bool CJosuVessLichKnightCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CJosuVessLichKnightCard::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ZOMBIE_KNIGHT_TOKEN_NAME, ZOMBIE_KNIGHT_TOKEN_ID, 8);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CKazarovSengirPurebloodCard::CKazarovSengirPurebloodCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kazarov, Sengir Pureblood"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Vampire), nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
{
	{
		// Whenever a creature an opponent controls is dealt damage, put a +1/+1 counter on Kazarov.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::CreatureEventCallback,
							   &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKazarovSengirPurebloodCard::SetDamageContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKazarovSengirPurebloodCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{R}: Kazarov deals 2 damage to target creature.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("3") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-2), PreventableType::Preventable));

		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKazarovSengirPurebloodCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	// SetToOpponentsOnly only filters players: check the controller of the damaged creature
	return pToCreature && pToCreature->GetController() != GetController();
}

bool CKazarovSengirPurebloodCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
	return true;
}

CKnightOfMaliceCard::CKnightOfMaliceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of Malice"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_HexproofFrom(this, new CardTypeComparer(CardType::White, false))
{
	// First strike. Hexproof from white (CHexproofFromSupport)
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// This creature gets +1/+0 as long as any player controls a white permanent. (as Knight of Grace)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new AnyWhitePermanentComparer),
			Power(+1), Life(+0)));

	AddAbility(cpAbility.GetPointer());
}

CLingeringPhantomCard::CLingeringPhantomCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lingering Phantom"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("5") BLACK_MANA_TEXT, Power(5), Life(4))
{
	// Whenever you cast a historic spell, you may pay {B}. If you do, return this card from your graveyard to your
	// hand. (a trigger of a card in the graveyard, as Unconventional Tactics in Hour of Devastation: the spell moves
	// to the stack)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Stack, FALSE, TRUE, FALSE));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new HistoricComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(BLACK_MANA_TEXT);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLingeringPhantomCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLingeringPhantomCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CLingeringPhantomCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Graveyard && pCard != this;
}

bool CLingeringPhantomCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(this);
	}
	return true;
}

CRatColonyCard::CRatColonyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rat Colony"), CardType::Creature, CREATURE_TYPE(Rat), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// This creature gets +1/+0 for each other Rat you control. (as Nim Grotesque in Fifth Dawn)
	// A deck can have any number of cards named Rat Colony. (deck building rule, not needed)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Rat), false),
				new NegateCardComparer(new SpecificCardComparer(this)))));

	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());
}

CStrongholdConfessorCard::CStrongholdConfessorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stronghold Confessor"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
	, m_KickerCost(_T("3"))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CStrongholdConfessorCard::OnZoneChanged))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Kicker {3}. If this creature was kicked, it enters with two +1/+1 counters on it. (as AEther Figment in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CStrongholdConfessorCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard == this)
		PutKickerCounters(this, pFromZone, pToZone, moveType, m_KickerCost, 2);
}

CThallidOmnivoreCard::CThallidOmnivoreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thallid Omnivore"), CardType::Creature, CREATURE_TYPE(Fungus), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_OtherFilter(_T("another non-Saproling creature"), _T("other non-Saproling creatures"),
		new AndCardComparer(new AnyCreatureComparer,
			new AndCardComparer(new NegateCardComparer(new SpecificCardComparer(this)),
				new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Saproling), false)))))
	, m_SaprolingFilter(_T("another Saproling"), _T("other Saprolings"),
		new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Saproling), false),
			new NegateCardComparer(new SpecificCardComparer(this))))
{
	// {1}, Sacrifice another creature: This creature gets +2/+2 until end of turn. If a Saproling was sacrificed this
	// way, you gain 2 life.
	// (one ability for each kind of sacrificed creature, so the Saproling is known on resolution)
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));

		cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherFilter);
		cpAbility->SetAbilityText(_T("+2/+2 (sacrifice a non-Saproling). Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThallidOmnivoreCard::BeforePump));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));

		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SaprolingFilter);
		cpAbility->SetAbilityText(_T("+2/+2 and gain 2 life (sacrifice a Saproling). Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThallidOmnivoreCard::BeforePumpSaproling));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CThallidOmnivoreCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +2);
	return true;
}

bool CThallidOmnivoreCard::BeforePumpSaproling(CAbilityAction* pAction)
{
	BeforePump(pAction);
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CThallidSoothsayerCard::CThallidSoothsayerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thallid Soothsayer"), CardType::Creature, CREATURE_TYPE(Fungus), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// {2}, Sacrifice a creature: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("2"), 1));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	AddAbility(cpAbility.GetPointer());
}

CTorgaarFamineIncarnateCard::CTorgaarFamineIncarnateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Torgaar, Famine Incarnate"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Avatar), nID,
		_T("6") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(7), Life(6))
{
	// As an additional cost to cast this spell, you may sacrifice any number of creatures. This spell costs {2} less
	// to cast for each creature sacrificed this way.
	// (one more spell for each useful number of creatures, as the additional costs of Daring Buccaneer: sacrificing a
	// fourth creature doesn't reduce the cost)
	static LPCTSTR costs[] = { _T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		BLACK_MANA_TEXT BLACK_MANA_TEXT };
	static LPCTSTR texts[] = { _T("Sacrifice one creature. Casts"), _T("Sacrifice two creatures. Casts"),
		_T("Sacrifice three creatures. Casts") };
	for (int i = 0; i < 3; ++i)
	{
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), costs[i], TRUE));

		cpSpell->GetCost().AddSacrificeCardCost(i + 1, CCardFilter::GetFilter(_T("creatures")));
		cpSpell->SetAbilityText(texts[i]);
		cpSpell->SetMainSpell(FALSE);
		AddSpell(cpSpell.GetPointer());
	}

	// When Torgaar enters, up to one target player's life total becomes half their starting life total, rounded down.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetSubjectCount(0, 1);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTorgaarFamineIncarnateCard::BeforeLife));
	AddAbility(cpAbility.GetPointer());
}

bool CTorgaarFamineIncarnateCard::BeforeLife(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		Life nDelta = pPlayer->GetStartingLife() / Life(2) - pPlayer->GetLife();
		if (nDelta != Life(0))
		{
			CLifeModifier pModifier = CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pPlayer);
		}
	}
	return false;
}

CUrgorosTheEmptyOneCard::CUrgorosTheEmptyOneCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Urgoros, the Empty One"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Specter), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(3))
{
	// Whenever Urgoros deals combat damage to a player, that player discards a card at random. If the player can't,
	// you draw a card. (as Gishath, Sun's Avatar in Ixalan: the player is kept in the trigger context)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUrgorosTheEmptyOneCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CUrgorosTheEmptyOneCard::BeforeDiscard));
	AddAbility(cpAbility.GetPointer());
}

bool CUrgorosTheEmptyOneCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	triggerContext.nValue1 = (DWORD)pPlayer;
	return true;
}

bool CUrgorosTheEmptyOneCard::BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (!pPlayer)
		return true;

	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
	if (pHand->GetSize() > 0)
	{
		CCard* pCard = pHand->GetAt(pPlayer->GetRand() % pHand->GetSize());
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard);
		pModifier.ApplyTo(pCard);
	}
	else
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CWhisperBloodLiturgistCard::CWhisperBloodLiturgistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Whisper, Blood Liturgist"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Cleric), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// {T}, Sacrifice two creatures: Return target creature card from your graveyard to the battlefield.
	// (as Dissension's reanimation abilities)
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(2, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CWindgraceAcolyteCard::CWindgraceAcolyteCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Windgrace Acolyte"), CardType::Creature, CREATURE_TYPE2(Cat, Warrior), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, mill three cards and you gain 3 life.
	AddEnterTrigger(this, &CWindgraceAcolyteCard::BeforeMill);
}

bool CWindgraceAcolyteCard::BeforeMill(CAbilityAction* pAction)
{
	Mill(pAction->GetController(), 3);
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CYargleGluttonOfUrborgCard::CYargleGluttonOfUrborgCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yargle, Glutton of Urborg"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Frog, Spirit), nID,
		_T("4") BLACK_MANA_TEXT, Power(9), Life(3))
{
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

// "When this creature enters, target player <effect>" (the callback does the effect and returns false)
template <class T>
static void AddEnterTargetPlayerTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

CAcademyDrakeCard::CAcademyDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Academy Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_KickerCost(_T("4"))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CAcademyDrakeCard::OnZoneChanged))
{
	// Kicker {4}. If this creature was kicked, it enters with two +1/+1 counters on it. (as AEther Figment in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CAcademyDrakeCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard == this)
		PutKickerCounters(this, pFromZone, pToZone, moveType, m_KickerCost, 2);
}

CAcademyJourneymageCard::CAcademyJourneymageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Academy Journeymage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// This spell costs {1} less to cast if you control a Wizard.
	// (a second, cheaper spell with AddPlayableIf, as Ghalta, Primal Hunger in Rivals of Ixalan)
	AddPlayableIf(this, GetSpells().GetAt(0), &CAcademyJourneymageCard::HasNoWizard);
	{
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3") BLUE_MANA_TEXT, TRUE));

		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityText(_T("Costs {1} less (you control a Wizard). Casts"));
		AddPlayableIf(this, cpSpell.GetPointer(), &CAcademyJourneymageCard::HasWizard);
		AddSpell(cpSpell.GetPointer());
	}

	// When this creature enters, return target creature an opponent controls to its owner's hand.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CAcademyJourneymageCard::BeforeBounce, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

BOOL CAcademyJourneymageCard::HasWizard(BOOL bIncludeTricks)
{
	return ControlsType(GetController(), CREATURE_TYPE(Wizard));
}

BOOL CAcademyJourneymageCard::HasNoWizard(BOOL bIncludeTricks)
{
	return !ControlsType(GetController(), CREATURE_TYPE(Wizard));
}

bool CAcademyJourneymageCard::BeforeBounce(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(pCard);
	return false;
}

CArtificersAssistantCard::CArtificersAssistantCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Artificer's Assistant"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
{
	// Whenever you cast a historic spell, scry 1.
	AddHistoricCastTrigger(this, &CArtificersAssistantCard::BeforeScry);
}

bool CArtificersAssistantCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CCloudreaderSphinxCard::CCloudreaderSphinxCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cloudreader Sphinx"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, scry 2.
	AddEnterTrigger(this, &CCloudreaderSphinxCard::BeforeScry);
}

bool CCloudreaderSphinxCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CColdWaterSnapperCard::CColdWaterSnapperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cold-Water Snapper"), CardType::Creature, CREATURE_TYPE(Turtle), nID,
		_T("5") BLUE_MANA_TEXT, Power(4), Life(5))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);
}

CDiligentExcavatorCard::CDiligentExcavatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Diligent Excavator"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// Whenever you cast a historic spell, target player mills two cards.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new HistoricComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDiligentExcavatorCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CDiligentExcavatorCard::BeforeMill(CAbilityAction* pAction)
{
	if (pAction->GetAssociatedPlayer())
		Mill(pAction->GetAssociatedPlayer(), 2);
	return false;
}

CHomaridExplorerCard::CHomaridExplorerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Homarid Explorer"), CardType::Creature, CREATURE_TYPE2(Homarid, Scout), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, target player mills four cards.
	AddEnterTargetPlayerTrigger(this, &CHomaridExplorerCard::BeforeMill, Characteristic::Negative);
}

bool CHomaridExplorerCard::BeforeMill(CAbilityAction* pAction)
{
	if (pAction->GetAssociatedPlayer())
		Mill(pAction->GetAssociatedPlayer(), 4);
	return false;
}

CMerfolkTricksterCard::CMerfolkTricksterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merfolk Trickster"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, tap target creature an opponent controls. It loses all abilities until end of turn.
	// Partial: the creature doesn't lose its abilities (as Warkite Marauder in Rivals of Ixalan)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CMerfolkTricksterCard::BeforeTap, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CMerfolkTricksterCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && !pCard->GetOrientation()->IsTapped())
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
	return false;
}

CNaruMehaMasterWizardCard::CNaruMehaMasterWizardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Naru Meha, Master Wizard"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When Naru Meha enters, copy target instant or sorcery spell you control. You may choose new targets for the
	// copy. (as Cloven Casting in Alara Reborn)
	// Partial: the spell isn't targeted; the last instant or sorcery spell you control on the stack is copied
	typedef
		TTriggeredAbility< CTriggeredCopyCastAbility1, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNaruMehaMasterWizardCard::SetCopyContext));
	AddAbility(cpAbility.GetPointer());

	// Other Wizards you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Wizard), 1, CreatureKeyword::Null);
}

bool CNaruMehaMasterWizardCard::SetCopyContext(CTriggeredCopyCastAbility1::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_pCard = NULL;
	triggerContext.m_pStackAction = NULL;

	const CStack& stack = m_pGame->GetStack();
	for (int i = 0; i < stack.GetStackSize(); ++i)
	{
		CStackAbilityAction* pStackAction = const_cast<CStackAbilityAction*>(stack.GetStackAction(i).GetPointer());
		if (!pStackAction->IsSpell())
			continue;

		CCard* pCard = pStackAction->GetAbility()->GetCard();
		if (pCard && pCard->GetController() == GetController() &&
			(pCard->GetCardType().IsInstant() || pCard->GetCardType().IsSorcery()))
		{
			triggerContext.m_pCard = pCard;
			triggerContext.m_pStackAction = pStackAction;
		}
	}

	return triggerContext.m_pCard != NULL;
}

CRelicRunnerCard::CRelicRunnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Relic Runner"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// This creature can't be blocked if you've cast a historic spell this turn.
	// Partial: when you cast a historic spell (without using the stack), it can't be blocked this turn; a historic spell
	// cast before it entered the battlefield doesn't count
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new HistoricComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetSkipStack(TRUE);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRelicRunnerCard::BeforeUnblockable));
	AddAbility(cpAbility.GetPointer());
}

bool CRelicRunnerCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

CSentinelOfThePearlTridentCard::CSentinelOfThePearlTridentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sentinel of the Pearl Trident"), CardType::Creature, CREATURE_TYPE2(Merfolk, Soldier), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, you may exile target historic permanent you control. If you do, return that card to
	// the battlefield under its owner's control at the beginning of the next end step.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new HistoricComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSentinelOfThePearlTridentCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());
}

// (the return as Nezahal, Primal Tide in Rivals of Ixalan)
bool CSentinelOfThePearlTridentCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pExile.ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Exile)
		return false;

	CMoveCardModifier* pReturn = new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others);
	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(), pReturn,
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
	return false;
}

CSlinnVodaTheRisingDeepCard::CSlinnVodaTheRisingDeepCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Slinn Voda, the Rising Deep"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Leviathan), nID,
		_T("6") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(8), Life(8))
	, m_KickerCost(_T("1") BLUE_MANA_TEXT)
{
	// Kicker {1}{U} (as Gatekeeper of Malakir in Zendikar)
	this->GetSpells().GetAt(0)->GetCost().AddOptionalManaCost(m_KickerCost);

	// When Slinn Voda enters, if it was kicked, return all creatures to their owners' hands except for Merfolk,
	// Krakens, Leviathans, Octopuses, and Serpents.
	AddEnterIfTrigger(this, &CSlinnVodaTheRisingDeepCard::SetKickedContext, &CSlinnVodaTheRisingDeepCard::BeforeBounce);
}

bool CSlinnVodaTheRisingDeepCard::SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	return GetLastCastingCostConfigEntry().HasOptionalManaCost(m_KickerCost);
}

bool CSlinnVodaTheRisingDeepCard::BeforeBounce(CAbilityAction* pAction)
{
	CCardFilter excluded(_T("a sea creature"), _T("sea creatures"),
		new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false),
			new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Kraken), false),
				new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Leviathan), false),
					new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Octopus), false),
						new CreatureTypeComparer(CREATURE_TYPE(Serpent), false))))));

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (!excluded.IsCardIncluded(pCard) && pCard->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(pCard);
	}
	return true;
}

CTempestDjinnCard::CTempestDjinnCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Tempest Djinn"), CardType::Creature, CREATURE_TYPE(Djinn), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(0), Life(4))
{
	// This creature gets +1/+0 for each basic Island you control. (as Nim Grotesque in Fifth Dawn)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new AndCardComparer(new CardTypeComparer(CardType::BasicLand, false), new CardTypeComparer(CardType::Island, false))));

	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());
}

CTetsukoUmezawaFugitiveCard::CTetsukoUmezawaFugitiveCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tetsuko Umezawa, Fugitive"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// Creatures you control with power or toughness 1 or less can't be blocked.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new OrCardComparer(new CreaturePowerComparer<std::less_equal<int>>(1),
				new CreatureToughnessComparer<std::less_equal<int>>(1)),
			Power(+0), Life(+0), CreatureKeyword::Unblockable));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CTolarianScholarCard::CTolarianScholarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tolarian Scholar"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
}

CVodalianArcanistCard::CVodalianArcanistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vodalian Arcanist"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// {T}: Add {C}. Spend this mana only to cast an instant or sorcery spell.
	// Partial: the engine has no restricted mana, so the mana can be spent on anything
	AddTapManaAbility(this, _T("1"));
}

CZahidDjinnOfTheLampCard::CZahidDjinnOfTheLampCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Zahid, Djinn of the Lamp"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Djinn), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(6))
{
	// You may pay {3}{U} and tap an untapped artifact you control rather than pay this spell's mana cost.
	// (an alternative cost as a second spell, as the additional costs of Daring Buccaneer)
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3") BLUE_MANA_TEXT, TRUE));

	cpSpell->GetCost().AddTapCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetAbilityText(_T("Pay {3}{U} and tap an artifact. Casts"));
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

#define KNIGHT_E_TOKEN_NAME		_T("Knight (E)")
#define KNIGHT_E_TOKEN_ID		55046

// Search pPlayer's library for up to nMax cards that pass pFilter, reveal them, put them into the hand, then shuffle
// (as SearchToBattlefield)
static void SearchToHand(CGame* pGame, CPlayer* pPlayer, int nMax, const CCardFilter* pFilter)
{
	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nMax),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::AllPlayers,
		pFilter,
		ZoneId::Hand,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pPlayer);
	pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

CAdelizTheCinderWindCard::CAdelizTheCinderWindCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Adeliz, the Cinder Wind"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Flying, haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever you cast an instant or sorcery spell, Wizards you control get +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAdelizTheCinderWindCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CAdelizTheCinderWindCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (CreatureTypeComparer(CREATURE_TYPE(Wizard), false)(creatures.GetAt(i)))
			PumpCreature(creatures.GetAt(i), +1, +1);
	return true;
}

CAmaranthineWallCard::CAmaranthineWallCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Amaranthine Wall"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("4"), Power(0), Life(6))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {2}: This creature gains indestructible until end of turn.
	AddPumpAbility(this, _T("2"), _T("Gain indestructible. Activates"), &CAmaranthineWallCard::BeforeIndestructible);
}

bool CAmaranthineWallCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCardKeyword()->AddIndestructible(TRUE);
	return true;
}

CArvadTheCursedCard::CArvadTheCursedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Arvad the Cursed"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// Other legendary creatures you control get +2/+2.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CardTypeComparer(CardType::Legendary, false),
				new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+2), Life(+2)));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CAryelKnightOfWindgraceCard::CAryelKnightOfWindgraceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aryel, Knight of Windgrace"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
	, m_KnightFilter(_T("another Knight"), _T("other Knights"),
		new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false),
			new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	{
		// {2}{W}, {T}: Create a 2/2 white Knight creature token with vigilance.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2") WHITE_MANA_TEXT,
				KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1));

		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	// {B}, {T}, Tap X untapped Knights you control: Destroy target creature with power X or less.
	// (one ability for each X from 0 to 4, as the variable costs of Ghalta in Rivals of Ixalan)
	static LPCTSTR texts[] = { _T("X = 0. Activates"), _T("X = 1. Activates"), _T("X = 2. Activates"),
		_T("X = 3. Activates"), _T("X = 4. Activates") };
	for (int nX = 0; nX <= 4; ++nX)
	{
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				BLACK_MANA_TEXT,
				new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::less_equal<int>>(nX)),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->AddTapCost();
		if (nX > 0)
			cpAbility->GetCost().AddTapCardCost(nX, &m_KnightFilter);
		cpAbility->SetAbilityText(texts[nX]);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

CDarigaazReincarnatedCard::CDarigaazReincarnatedCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Darigaaz Reincarnated"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Dragon), nID,
		_T("4") BLACK_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(7))
{
	// Flying, trample, haste
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// If Darigaaz would die, instead exile it with three egg counters on it.
	// At the beginning of your upkeep, if this card is exiled with an egg counter on it, remove an egg counter from it.
	// Then if this card has no egg counters on it, return it to the battlefield.
	// Not implemented: the engine has no replacement effects on dying
}

CGarnaTheBloodflameCard::CGarnaTheBloodflameCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Garna, the Bloodflame"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When Garna enters, return to your hand all creature cards in your graveyard that were put there from anywhere
	// this turn.
	// Not implemented: the engine doesn't keep when a card was put into a graveyard

	// Other creatures you control have haste.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+0), Life(+0), CreatureKeyword::Haste));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CGrandWarlordRadhaCard::CGrandWarlordRadhaCard(CGame* pGame, UINT nID)
	: CHasteCreatureCard(pGame, _T("Grand Warlord Radha"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
{
	// Whenever one or more creatures you control attack, add that much mana in any combination of {R} and/or {G}.
	// Until end of turn, you don't lose this mana as steps and phases end.
	// Not implemented: the mana pool is emptied at the end of each step
}

CGuardiansOfKoilosCard::CGuardiansOfKoilosCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Guardians of Koilos"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("5"), Power(4), Life(4))
{
	// When this creature enters, you may return another target historic permanent you control to its owner's hand.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new HistoricComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGuardiansOfKoilosCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CGuardiansOfKoilosCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(pCard);
	return false;
}

CHallarTheFirefletcherCard::CHallarTheFirefletcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hallar, the Firefletcher"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Archer), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever you cast a spell, if that spell was kicked, put a +1/+1 counter on Hallar, then Hallar deals damage
	// equal to the number of +1/+1 counters on it to each opponent. (as Bloodstone Goblin)
	// Note: the spells kicked with a second spell ("Casts kicked") aren't seen
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CHallarTheFirefletcherCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHallarTheFirefletcherCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CHallarTheFirefletcherCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return pCard && !pCard->GetLastCastingCostConfigEntry().GetOptionalManaCosts().empty();
}

bool CHallarTheFirefletcherCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
	int nCounters = GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
	if (nCounters > 0)
		DamageEachOpponent(this, pAction->GetController(), nCounters);
	return true;
}

CHowlingGolemCard::CHowlingGolemCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Howling Golem"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("3"), Power(2), Life(3))
{
	// Whenever this creature attacks or blocks, each player draws a card.
	AddSelfAttackTrigger(this, &CHowlingGolemCard::BeforeDraw);

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHowlingGolemCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CHowlingGolemCard::BeforeDraw(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		DrawCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

CJhoirasFamiliarCard::CJhoirasFamiliarCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Jhoira's Familiar"), CardType::_ArtifactCreature, CREATURE_TYPE(Bird), nID,
		_T("4"), Power(2), Life(2))
{
	// Historic spells you cast cost {1} less to cast.
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new HistoricComparer,
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CJhoiraWeatherlightCaptainCard::CJhoiraWeatherlightCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jhoira, Weatherlight Captain"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") BLUE_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Whenever you cast a historic spell, draw a card.
	AddHistoricCastTrigger(this, &CJhoiraWeatherlightCaptainCard::BeforeDraw);
}

bool CJhoiraWeatherlightCaptainCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CJodahArchmageEternalCard::CJodahArchmageEternalCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Jodah, Archmage Eternal"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
{
	// You may pay {W}{U}{B}{R}{G} rather than pay the mana cost for spells you cast.
	// Not implemented: the engine can't give an alternative cost to other cards
}

CMishrasSelfReplicatorCard::CMishrasSelfReplicatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mishra's Self-Replicator"), CardType::_ArtifactCreature, CREATURE_TYPE(AssemblyWorker), nID,
		_T("5"), Power(2), Life(2))
{
	// Whenever you cast a historic spell, you may pay {1}. If you do, create a token that's a copy of this creature.
	// (the payment as Cloven Casting, the copy as Rite of Replication in Zendikar)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new HistoricComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T("1"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMishrasSelfReplicatorCard::BeforeCopy));
	AddAbility(cpAbility.GetPointer());
}

bool CMishrasSelfReplicatorCard::BeforeCopy(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCopyModifier(GetGame(), this).ApplyTo(this);
	return true;
}

CNiambiFaithfulHealerCard::CNiambiFaithfulHealerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Niambi, Faithful Healer"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When Niambi enters, you may search your library and/or graveyard for a card named Teferi, Timebender, reveal it,
	// and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CNiambiFaithfulHealerCard::BeforeSearch, true);
}

bool CNiambiFaithfulHealerCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Teferi, Timebender"));
	return true;
}

CPardicWandererCard::CPardicWandererCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pardic Wanderer"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("6"), Power(5), Life(5))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);
}

CRaffCapashenShipsMageCard::CRaffCapashenShipsMageCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Raff Capashen, Ship's Mage"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Flash. Flying
	GetCardKeyword()->AddFlash(FALSE);

	// You may cast historic spells as though they had flash.
	// Not implemented: the engine can't give flash to other cards
}

CShannaSisaysLegacyCard::CShannaSisaysLegacyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shanna, Sisay's Legacy"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Warrior), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(0), Life(0))
	, m_HexproofFrom(this, new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery | CardType::_Aura, false)))
{
	// Shanna can't be the target of abilities your opponents control.
	// (CHexproofFromSupport with the sources that aren't instants, sorceries or Auras: the abilities of permanents)
	// Note: the abilities of instant and sorcery cards (cycling...) can still target it

	// Shanna gets +1/+1 for each creature you control. (as Nim Grotesque in Fifth Dawn)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new AnyCreatureComparer));

	AddAbility(cpAbility.GetPointer());
}

CSkitteringSurveyorCard::CSkitteringSurveyorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skittering Surveyor"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(1), Life(2))
{
	// When this creature enters, you may search your library for a basic land card, reveal it, put it into your hand,
	// then shuffle.
	AddEnterTrigger(this, &CSkitteringSurveyorCard::BeforeSearch, true);
}

bool CSkitteringSurveyorCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("basic lands")));
	return true;
}

CSlimefootTheStowawayCard::CSlimefootTheStowawayCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Slimefoot, the Stowaway"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Fungus), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Whenever a Saproling you control dies, Slimefoot deals 1 damage to each opponent and you gain 1 life.
	AddAnotherCreatureDiesTrigger(this, &CSlimefootTheStowawayCard::SetTriggerContext, &CSlimefootTheStowawayCard::BeforeDrain);

	// {4}: Create a 1/1 green Saproling creature token.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("4"),
			SAPROLING_TOKEN_NAME, SAPROLING_TOKEN_ID, 1));

	AddAbility(cpAbility.GetPointer());
}

bool CSlimefootTheStowawayCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return CreatureTypeComparer(CREATURE_TYPE(Saproling), false)(pCard);
}

bool CSlimefootTheStowawayCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CSparringConstructCard::CSparringConstructCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sparring Construct"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("1"), Power(1), Life(1))
{
	// When this creature dies, put a +1/+1 counter on target creature you control.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSparringConstructCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CSparringConstructCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(pCard);
	return false;
}

CTatyovaBenthicDruidCard::CTatyovaBenthicDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tatyova, Benthic Druid"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Merfolk, Druid), nID,
		_T("3") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Landfall - Whenever a land you control enters, you gain 1 life and draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTatyovaBenthicDruidCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CTatyovaBenthicDruidCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CTeferisSentinelCard::CTeferisSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Teferi's Sentinel"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("5"), Power(2), Life(6))
{
	// As long as you control a Teferi planeswalker, this creature gets +4/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+4), Life(+0)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Teferi));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CTianaShipsCaretakerCard::CTianaShipsCaretakerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Tiana, Ship's Caretaker"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Angel, Artificer), nID,
		_T("3") RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Flying, first strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Whenever an Aura or Equipment you control is put into a graveyard from the battlefield, you may return that card
	// to its owner's hand at the beginning of the next end step. (the card is kept in the trigger context, as Gishath;
	// the return as Long Road Home in Amonkhet)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Aura | CardType::Equipment, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTianaShipsCaretakerCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CTianaShipsCaretakerCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CTianaShipsCaretakerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CTianaShipsCaretakerCard::BeforeReturn(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return true;

	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
		new CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others),
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
	return true;
}

CTraxosScourgeOfKroogCard::CTraxosScourgeOfKroogCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Traxos, Scourge of Kroog"), CardType::_ArtifactCreature | CardType::Legendary, CREATURE_TYPE2(Dragon, Construct), nID,
		_T("4"), Power(7), Life(7))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Traxos enters tapped and doesn't untap during your untap step.
	SetIntoPlayTapped();
	GetCardKeyword()->AddNoUntapInUntapPhase();

	// Whenever you cast a historic spell, untap Traxos.
	AddHistoricCastTrigger(this, &CTraxosScourgeOfKroogCard::BeforeUntap);
}

bool CTraxosScourgeOfKroogCard::BeforeUntap(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsTapped())
		CCardOrientationModifier(FALSE).ApplyTo(this);
	return true;
}

CVoltaicServantCard::CVoltaicServantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Voltaic Servant"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("2"), Power(1), Life(3))
{
	// At the beginning of your end step, untap target artifact. (as Tezzeret the Schemer Emblem)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVoltaicServantCard::BeforeUntap));
	AddAbility(cpAbility.GetPointer());
}

bool CVoltaicServantCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetOrientation()->IsTapped())
		CCardOrientationModifier(FALSE).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
