#include "stdafx.h"
#include "CardRivalsOfIxalan.h"

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
		DEFINE_CARD(CArchOfOrazcaCard);
		DEFINE_CARD(CAngrathMinotaurPirateCard);
		DEFINE_CARD(CAngrathTheFlameChainedCard);
		DEFINE_CARD(CHuatliRadiantChampionCard);
		DEFINE_CARD(CVraskaSchemingGorgonCard);
		DEFINE_CARD(CAquaticIncursionCard);
		DEFINE_CARD(CBafflingEndCard);
		DEFINE_CARD(CCuriousObsessionCard);
		DEFINE_CARD(CFormOfTheDinosaurCard);
		DEFINE_CARD(CHadanasClimbCard);
		DEFINE_CARD(CWingedTempleOfOrazcaCard);
		DEFINE_CARD(CInducedAmnesiaCard);
		DEFINE_CARD(CKumenasAwakeningCard);
		DEFINE_CARD(CLuminousBondsCard);
		DEFINE_CARD(CPathOfDiscoveryCard);
		DEFINE_CARD(CPathOfMettleCard);
		DEFINE_CARD(CMetzaliTowerOfTriumphCard);
		DEFINE_CARD(CProfaneProcessionCard);
		DEFINE_CARD(CTombOfTheDuskRoseCard);
		DEFINE_CARD(CRadiantDestinyCard);
		DEFINE_CARD(CSeaLegsCard);
		DEFINE_CARD(CSeeRedCard);
		DEFINE_CARD(CSquiresDevotionCard);
		DEFINE_CARD(CStormTheVaultCard);
		DEFINE_CARD(CVaultOfCatlacanCard);
		DEFINE_CARD(CTilonallisCrownCard);
		DEFINE_CARD(CWaterknotCard);
		DEFINE_CARD(CAwakenedAmalgamCard);
		DEFINE_CARD(CAzorsGatewayCard);
		DEFINE_CARD(CSanctumOfTheSunCard);
		DEFINE_CARD(CCaptainsHookCard);
		DEFINE_CARD(CGleamingBarrierCard);
		DEFINE_CARD(CGoldenGuardianCard);
		DEFINE_CARD(CGoldForgeGarrisonCard);
		DEFINE_CARD(COrazcaRelicCard);
		DEFINE_CARD(CSilentGravestoneCard);
		DEFINE_CARD(CTheImmortalSunCard);
		DEFINE_CARD(CAngrathsFuryCard);
		DEFINE_CARD(CArterialFlowCard);
		DEFINE_CARD(CBrasssBountyCard);
		DEFINE_CARD(CCleansingRayCard);
		DEFINE_CARD(CCrashingTideCard);
		DEFINE_CARD(CDarkInquiryCard);
		DEFINE_CARD(CEnterTheUnknownCard);
		DEFINE_CARD(CFloodOfRecollectionCard);
		DEFINE_CARD(CGoldenDemiseCard);
		DEFINE_CARD(CGruesomeFateCard);
		DEFINE_CARD(CHuntTheWeakCard);
		DEFINE_CARD(CImpaleCard);
		DEFINE_CARD(CMastermindsAcquisitionCard);
		DEFINE_CARD(CMutinyCard);
		DEFINE_CARD(CPiratesPillageCard);
		DEFINE_CARD(CSecretsOfTheGoldenCityCard);
		DEFINE_CARD(CSlaughterTheStrongCard);
		DEFINE_CARD(CSphinxsDecreeCard);
		DEFINE_CARD(CStrengthOfThePackCard);
		DEFINE_CARD(CThunderherdMigrationCard);
		DEFINE_CARD(CVraskasScornCard);
		DEFINE_CARD(CAdmiralsOrderCard);
		DEFINE_CARD(CBlazingHopeCard);
		DEFINE_CARD(CBombardCard);
		DEFINE_CARD(CBuccaneersBravadoCard);
		DEFINE_CARD(CExpelFromOrazcaCard);
		DEFINE_CARD(CHornswoggleCard);
		DEFINE_CARD(CMomentOfCravingCard);
		DEFINE_CARD(CMomentOfTriumphCard);
		DEFINE_CARD(CPrideOfConquerorsCard);
		DEFINE_CARD(CReaverAmbushCard);
		DEFINE_CARD(CRecklessRageCard);
		DEFINE_CARD(CShakeTheFoundationsCard);
		DEFINE_CARD(CVonasHungerCard);
		DEFINE_CARD(CBishopOfBindingCard);
		DEFINE_CARD(CEverdawnChampionCard);
		DEFINE_CARD(CExultantSkymarcherCard);
		DEFINE_CARD(CFamishedPaladinCard);
		DEFINE_CARD(CForerunnerOfTheLegionCard);
		DEFINE_CARD(CImperialCeratopsCard);
		DEFINE_CARD(CMajesticHeliopterusCard);
		DEFINE_CARD(CMartyrOfDuskCard);
		DEFINE_CARD(CPaladinOfAtonementCard);
		DEFINE_CARD(CSanguineGlorifierCard);
		DEFINE_CARD(CSkymarcherAspirantCard);
		DEFINE_CARD(CSnubhornSentryCard);
		DEFINE_CARD(CSunCrestedPterodonCard);
		DEFINE_CARD(CSunSentinelCard);
		DEFINE_CARD(CTrapjawTyrantCard);
		DEFINE_CARD(CZetalpaPrimalDawnCard);
		DEFINE_CARD(CCacophodonCard);
		DEFINE_CARD(CCrestedHerdcallerCard);
		DEFINE_CARD(CDeeprootEliteCard);
		DEFINE_CARD(CForerunnerOfTheHeraldsCard);
		DEFINE_CARD(CGhaltaPrimalHungerCard);
		DEFINE_CARD(CGiltgroveStalkerCard);
		DEFINE_CARD(CHardyVeteranCard);
		DEFINE_CARD(CJadeBearerCard);
		DEFINE_CARD(CJadecraftArtisanCard);
		DEFINE_CARD(CJadelightRangerCard);
		DEFINE_CARD(CJunglebornPioneerCard);
		DEFINE_CARD(CKnightOfTheStampedeCard);
		DEFINE_CARD(COrazcaFrillbackCard);
		DEFINE_CARD(COvergrownArmasaurCard);
		DEFINE_CARD(CSwiftWardenCard);
		DEFINE_CARD(CTendershootDryadCard);
		DEFINE_CARD(CThrashingBrontodonCard);
		DEFINE_CARD(CWaywardSwordtoothCard);
		DEFINE_CARD(CWorldShaperCard);
		DEFINE_CARD(CBrazenFreebooterCard);
		DEFINE_CARD(CChargingTuskodonCard);
		DEFINE_CARD(CDaringBuccaneerCard);
		DEFINE_CARD(CDireFleetDaredevilCard);
		DEFINE_CARD(CFanaticalFirebrandCard);
		DEFINE_CARD(CForerunnerOfTheEmpireCard);
		DEFINE_CARD(CFrilledDeathspitterCard);
		DEFINE_CARD(CGoblinTrailblazerCard);
		DEFINE_CARD(CNeedletoothRaptorCard);
		DEFINE_CARD(COrazcaRaptorCard);
		DEFINE_CARD(CRekindlingPhoenixCard);
		DEFINE_CARD(CSilvercladFerocidonsCard);
		DEFINE_CARD(CStampedingHorncrestCard);
		DEFINE_CARD(CStormFleetSwashbucklerCard);
		DEFINE_CARD(CSunCollaredRaptorCard);
		DEFINE_CARD(CSwabGoblinCard);
		DEFINE_CARD(CSwaggeringCorsairCard);
		DEFINE_CARD(CAngrathsAmbusherCard);
		DEFINE_CARD(CCanalMonitorCard);
		DEFINE_CARD(CChampionOfDuskCard);
		DEFINE_CARD(CDinosaurHunterCard);
		DEFINE_CARD(CDireFleetPoisonerCard);
		DEFINE_CARD(CDuskChargerCard);
		DEFINE_CARD(CDuskLegionZealotCard);
		DEFINE_CARD(CFathomFleetBoarderCard);
		DEFINE_CARD(CForerunnerOfTheCoalitionCard);
		DEFINE_CARD(CGraspingScoundrelCard);
		DEFINE_CARD(CMausoleumHarpyCard);
		DEFINE_CARD(COathswornVampireCard);
		DEFINE_CARD(CPitilessPlundererCard);
		DEFINE_CARD(CRavenousChupacabraCard);
		DEFINE_CARD(CSadisticSkymarcherCard);
		DEFINE_CARD(CTetzimocPrimalDeathCard);
		DEFINE_CARD(CTombRobberCard);
		DEFINE_CARD(CTwilightProphetCard);
		DEFINE_CARD(CVampireChampionCard);
		DEFINE_CARD(CVampireRevenantCard);
		DEFINE_CARD(CVoraciousVampireCard);
		DEFINE_CARD(CVraskasConquistadorCard);
		DEFINE_CARD(CDeadeyeRigHaulerCard);
		DEFINE_CARD(CKitesailCorsairCard);
		DEFINE_CARD(CMistCloakedHeraldCard);
		DEFINE_CARD(CNezahalPrimalTideCard);
		DEFINE_CARD(CRiverDarterCard);
		DEFINE_CARD(CRiverwiseAugurCard);
		DEFINE_CARD(CSeafloorOracleCard);
		DEFINE_CARD(CSirenReaverCard);
		DEFINE_CARD(CSlipperyScoundrelCard);
		DEFINE_CARD(CSoulOfTheRapidsCard);
		DEFINE_CARD(CSpireWinderCard);
		DEFINE_CARD(CSwornGuardianCard);
		DEFINE_CARD(CTimestreamNavigatorCard);
		DEFINE_CARD(CWarkiteMarauderCard);
		DEFINE_CARD(CAtzocanSeerCard);
		DEFINE_CARD(CAzorTheLawbringerCard);
		DEFINE_CARD(CDeadeyeBrawlerCard);
		DEFINE_CARD(CDireFleetNeckbreakerCard);
		DEFINE_CARD(CElendaTheDuskRoseCard);
		DEFINE_CARD(CJungleCreeperCard);
		DEFINE_CARD(CKumenaTyrantOfOrazcaCard);
		DEFINE_CARD(CLegionLieutenantCard);
		DEFINE_CARD(CMerfolkMistbinderCard);
		DEFINE_CARD(CRagingRegisaurCard);
		DEFINE_CARD(CRelentlessRaptorCard);
		DEFINE_CARD(CResplendentGriffinCard);
		DEFINE_CARD(CSiegehornCeratopsCard);
		DEFINE_CARD(CStormFleetSprinterCard);
		DEFINE_CARD(CZacamaPrimalCalamityCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

CArchOfOrazcaCard::CArchOfOrazcaCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Arch of Orazca"), nID)
	, m_Ascend(this)
{
	// Ascend (If you control ten or more permanents, you get the city's blessing for the rest of the game.)
	// (CAscendSupport: checked by the core every time a permanent enters)

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {5}, {T}: Draw a card. Activate only if you have the city's blessing.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("5"), 1));

	cpAbility->AddTapCost();
	AddPlayableIf(this, cpAbility.GetPointer(), &CArchOfOrazcaCard::HasBlessing);
	AddAbility(cpAbility.GetPointer());
}

BOOL CArchOfOrazcaCard::HasBlessing(BOOL bIncludeTricks)
{
	return GetController()->HasCityBlessing();
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

#define HUATLI_RADIANT_CHAMPION_EMBLEM_NAME	_T("Huatli, Radiant Champion Emblem")
#define HUATLI_RADIANT_CHAMPION_EMBLEM_ID	61151
#define VRASKA_SCHEMING_GORGON_EFFECT_NAME	_T("Vraska, Scheming Gorgon Effect")
#define VRASKA_SCHEMING_GORGON_EFFECT_ID	61152

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

CAngrathMinotaurPirateCard::CAngrathMinotaurPirateCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Angrath, Minotaur Pirate"), nID,
		_T("4") BLACK_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Angrath, 5)
{
	// +2: Angrath deals 1 damage to target opponent or planeswalker and each creature that player or that
	// planeswalker's controller controls.
	// Note: it targets a player only (it can't target planeswalkers)
	AddPlayerLoyaltyAbility(this, +2, &CAngrathMinotaurPirateCard::BeforeDamage);

	{
		// -3: Return target Pirate card from your graveyard to the battlefield.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new CreatureTypeComparer(CREATURE_TYPE(Pirate), false),
				ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}

	// -11: Destroy all creatures target opponent controls. Angrath deals damage to that player equal to their total
	// power.
	AddPlayerLoyaltyAbility(this, -11, &CAngrathMinotaurPirateCard::BeforeDestroy);
}

bool CAngrathMinotaurPirateCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	DealDamageToPlayer(this, pPlayer, 1);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);
	return false;
}

bool CAngrathMinotaurPirateCard::BeforeDestroy(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);

	// The total power is the power of the creatures before they are destroyed
	int nPower = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && (int)pCreature->GetPower() > 0)
			nPower += (int)pCreature->GetPower();
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(creatures.GetAt(i));

	DealDamageToPlayer(this, pPlayer, nPower);
	return false;
}

CAngrathTheFlameChainedCard::CAngrathTheFlameChainedCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Angrath, the Flame-Chained"), nID,
		_T("3") BLACK_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Angrath, 4)
{
	// +1: Each opponent discards a card and loses 2 life.
	AddLoyaltyAbility(this, +1, _T("Each opponent discards a card and loses 2 life. Activates"), &CAngrathTheFlameChainedCard::BeforeDiscard);

	{
		// -3: Gain control of target creature until end of turn. Untap it. It gains haste until end of turn. Sacrifice
		// it at the beginning of the next end step if it has mana value 3 or less. (as Act of Treason)
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

		CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
		pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
		pModifier->GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

		cpAbility->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngrathTheFlameChainedCard::BeforeSteal));
		AddAbility(cpAbility.GetPointer());
	}

	// -8: Each opponent loses life equal to the number of cards in their graveyard.
	AddLoyaltyAbility(this, -8, _T("Each opponent loses life equal to the number of cards in their graveyard. Activates"), &CAngrathTheFlameChainedCard::BeforeLoseLife);
}

bool CAngrathTheFlameChainedCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);

	DrainOpponents(this, pController, 2, FALSE);
	return true;
}

// The sacrifice is scheduled before the control changes (the callback returns true: ResolveImpl moves the target)
bool CAngrathTheFlameChainedCard::BeforeSteal(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && (int)pCard->GetConvertedManaCost() <= 3)
	{
		// Sacrifice it at the beginning of the next end step (as Hazoret's Favor in Amonkhet)
		CScheduledCardModifier pSacrificeModifier = CScheduledCardModifier(GetGame(),
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice),
			TurnNumberDelta(-1), NodeId::EndStep, true, CScheduledCardModifier::Operation::ApplyToLater);
		pSacrificeModifier.ApplyTo(pCard);
	}
	return true;
}

bool CAngrathTheFlameChainedCard::BeforeLoseLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		int nCards = pPlayer->GetZoneById(ZoneId::Graveyard)->GetSize();
		if (pPlayer != pController && nCards > 0)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-nCards), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pPlayer);
		}
	}
	return true;
}

CHuatliRadiantChampionCard::CHuatliRadiantChampionCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Huatli, Radiant Champion"), nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Huatli, 3)
{
	// +1: Put a loyalty counter on Huatli for each creature you control.
	AddLoyaltyAbility(this, +1, _T("Put a loyalty counter on Huatli for each creature you control. Activates"), &CHuatliRadiantChampionCard::BeforeLoyalty);

	{
		// -1: Target creature gets +X/+X until end of turn, where X is the number of creatures you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHuatliRadiantChampionCard::BeforePump));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: You get an emblem with "Whenever a creature you control enters, you may draw a card." (as Nissa, Vital
		// Force in Kaladesh)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(pGame, HUATLI_RADIANT_CHAMPION_EMBLEM_NAME, HUATLI_RADIANT_CHAMPION_EMBLEM_ID, 1, FALSE, ZoneId::_Effects));
		cpAbility->SetAbilityText(_T("You get an emblem with \"Whenever a creature you control enters, you may draw a card.\" Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHuatliRadiantChampionCard::BeforeLoyalty(CAbilityAction* pAction)
{
	int nCount = CountCreatures(GetGame(), pAction->GetController());
	if (nCount > 0 && GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(LOYALTY_COUNTER, nCount);
		pModifier.ApplyTo(this);
	}
	return true;
}

bool CHuatliRadiantChampionCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	int nCount = CountCreatures(GetGame(), pAction->GetController());
	if (nCount > 0)
		PumpCreature(pCard, nCount, nCount);
	return false;
}

CVraskaSchemingGorgonCard::CVraskaSchemingGorgonCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vraska, Scheming Gorgon"), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Vraska, 5)
{
	// +2: Creatures you control get +1/+0 until end of turn.
	AddLoyaltyAbility(this, +2, _T("Creatures you control get +1/+0 until end of turn. Activates"), &CVraskaSchemingGorgonCard::BeforePump);

	{
		// -3: Destroy target creature.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -10: Until end of turn, creatures you control gain deathtouch and "Whenever this creature deals damage to an
	// opponent, that player loses the game." (the triggered ability is the Vraska, Scheming Gorgon Effect, which
	// remembers the creatures, as Otherworldly Outburst Effect)
	AddLoyaltyAbility(this, -10, _T("Until end of turn, creatures you control gain deathtouch and \"Whenever this creature deals damage to an opponent, that player loses the game.\" Activates"),
		&CVraskaSchemingGorgonCard::BeforeUltimate);
}

bool CVraskaSchemingGorgonCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +1, +0);
	return true;
}

bool CVraskaSchemingGorgonCard::BeforeUltimate(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	if (creatures.GetSize() == 0)
		return true;

	for (int i = 0; i < creatures.GetSize(); ++i)
		GainCardKeyword(creatures.GetAt(i), CardKeyword::Deathtouch);

	CContainerEffectModifier pModifier = CContainerEffectModifier(GetGame(), VRASKA_SCHEMING_GORGON_EFFECT_NAME, VRASKA_SCHEMING_GORGON_EFFECT_ID, &creatures);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (enchantments)

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

//____________________________________________________________________________
//
// Enchantments

CAquaticIncursionCard::CAquaticIncursionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Aquatic Incursion"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, create two 1/1 blue Merfolk creature tokens with hexproof.
	AddEnterTrigger(this, &CAquaticIncursionCard::BeforeToken);

	// {3}{U}: Target Merfolk can't be blocked this turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("3") BLUE_MANA_TEXT,
			new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false), FALSE));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAquaticIncursionCard::BeforeUnblockable));
	AddAbility(cpAbility.GetPointer());
}

bool CAquaticIncursionCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), MERFOLK_A_TOKEN_NAME, MERFOLK_A_TOKEN_ID, 2);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CAquaticIncursionCard::BeforeUnblockable(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		pCreature->GetCreatureKeyword()->AddUnblockable(TRUE);
	return false;
}

CBafflingEndCard::CBafflingEndCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Baffling End"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, exile target creature an opponent controls with mana value 3 or less.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CBafflingEndCard::BeforeExile, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(3));
	pTargeting->SetIncludeNonControllerCardsOnly();

	// When this enchantment leaves the battlefield, target opponent creates a 3/3 green Dinosaur creature token with
	// trample.
	// Note: the opponent isn't targeted (two-player games)
	AddLeaveTrigger(this, &CBafflingEndCard::BeforeToken);
}

bool CBafflingEndCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

bool CBafflingEndCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), DINOSAUR_A_TOKEN_NAME, DINOSAUR_A_TOKEN_ID, 1);
	pModifier.ApplyTo(GetGame()->GetNextPlayer(pAction->GetController()));
	return true;
}

CCuriousObsessionCard::CCuriousObsessionCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Curious Obsession"), nID,
		BLUE_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Null)
{
	{
		// Enchanted creature has "Whenever this creature deals combat damage to a player, you may draw a card."
		// (the trigger belongs to this Aura, as Sixth Sense in Amonkhet)
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new EnchantedByComparer(this));
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your end step, if you didn't attack with a creature this turn, sacrifice this Aura.
	AddStepTrigger(this, NodeId::EndStep, false, &CCuriousObsessionCard::SetTriggerContext, &CCuriousObsessionCard::BeforeSacrifice);
}

bool CCuriousObsessionCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !HasRaid(GetController());
}

bool CCuriousObsessionCard::BeforeSacrifice(CAbilityAction* pAction)
{
	SacrificeSelf(this, pAction->GetController());
	return true;
}

CFormOfTheDinosaurCard::CFormOfTheDinosaurCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Form of the Dinosaur"), CardType::GlobalEnchantment, nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, your life total becomes 15.
	AddEnterTrigger(this, &CFormOfTheDinosaurCard::BeforeLife);

	// At the beginning of your upkeep, this enchantment deals 15 damage to target creature an opponent controls and
	// that creature deals damage equal to its power to you.
	CTargeting* pTargeting = AddStepTargetTrigger<CFormOfTheDinosaurCard>(this, NodeId::UpkeepStep, NULL, &CFormOfTheDinosaurCard::BeforeDamage, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CFormOfTheDinosaurCard::BeforeLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Life nDelta = Life(15) - pController->GetLife();
	if (nDelta != Life(0))
	{
		CLifeModifier pModifier = CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pController);
	}
	return true;
}

bool CFormOfTheDinosaurCard::BeforeDamage(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return false;

	int nPower = (int)pCreature->GetPower();
	DealDamageToCreature(this, pCreature, 15);

	// The creature deals damage equal to its power (before the damage) to you
	if (nPower > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nPower), pCreature, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pAction->GetController());
	}
	return false;
}

CHadanasClimbCard::CHadanasClimbCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Hadana's Climb"), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, _T("Winged Temple of Orazca"))
{
	// At the beginning of combat on your turn, put a +1/+1 counter on target creature you control. Then if that
	// creature has three or more +1/+1 counters on it, transform Hadana's Climb.
	CTargeting* pTargeting = AddStepTargetTrigger(this, NodeId::BeginningOfCombatStep, &CHadanasClimbCard::SetTriggerContext,
		&CHadanasClimbCard::BeforeCounter, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();

	// Winged Temple of Orazca: {T}: Add one mana of any color.
	AddBackManaAbility(WHITE_MANA_TEXT);
	AddBackManaAbility(BLUE_MANA_TEXT);
	AddBackManaAbility(BLACK_MANA_TEXT);
	AddBackManaAbility(RED_MANA_TEXT);
	AddBackManaAbility(GREEN_MANA_TEXT);
	{
		// Winged Temple of Orazca: {1}{G}{U}, {T}: Target creature you control gains flying and gets +X/+X until end of
		// turn, where X is its power.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHadanasClimbCard::BeforePump));
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHadanasClimbCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return IsFirstFaceInPlay() == TRUE;
}

bool CHadanasClimbCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	AddPlusCounter(pCard);
	if (CountCounters(pCard, _T("+1/+1")) >= 3)
		DoTransform();
	return false;
}

bool CHadanasClimbCard::BeforePump(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return false;

	int nPower = (int)pCreature->GetPower();
	PumpCreature(pCreature, nPower > 0 ? nPower : 0, nPower > 0 ? nPower : 0, CreatureKeyword::Flying);
	return false;
}

CWingedTempleOfOrazcaCard::CWingedTempleOfOrazcaCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Winged Temple of Orazca"), nID, CardType::Legendary)
{
	// The back face of Hadana's Climb (its abilities are in that card)
	AddAnyColorManaAbility(this);
}

CInducedAmnesiaCard::CInducedAmnesiaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Induced Amnesia"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// When this enchantment enters, target player exiles all cards from their hand face down, then draws that many
		// cards.
		// Note: the cards are exiled face up
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInducedAmnesiaCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}

	// When this enchantment is put into a graveyard from the battlefield, return the exiled cards to their owner's hand.
	AddDiesTrigger(this, &CInducedAmnesiaCard::BeforeReturn);
}

bool CInducedAmnesiaCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
	int nCount = 0;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	while (pHand->GetSize() > 0)
	{
		CCard* pCard = pHand->GetAt(pHand->GetSize() - 1);
		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() != ZoneId::Exile)
			break;
		m_Exiled.AddCard(pCard, CardPlacement::Top);
		++nCount;
	}

	if (nCount > 0)
		DrawCards(GetGame(), pPlayer, nCount);
	return false;
}

bool CInducedAmnesiaCard::BeforeReturn(CAbilityAction* pAction)
{
	while (m_Exiled.GetSize() > 0)
	{
		CCard* pCard = m_Exiled.GetAt(0);
		m_Exiled.RemoveCard(pCard);
		if (pCard->GetZoneId() == ZoneId::Exile)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
			pModifier.ApplyTo(pCard);
		}
	}
	return true;
}

CKumenasAwakeningCard::CKumenasAwakeningCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Kumena's Awakening"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_Ascend(this)
{
	// Ascend (CAscendSupport)

	// At the beginning of your upkeep, each player draws a card. If you have the city's blessing, instead only you draw
	// a card.
	AddStepTrigger<CKumenasAwakeningCard>(this, NodeId::UpkeepStep, false, NULL, &CKumenasAwakeningCard::BeforeDraw);
}

bool CKumenasAwakeningCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (pController->HasCityBlessing())
		DrawCards(GetGame(), pController, 1);
	else
		for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
			DrawCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

CLuminousBondsCard::CLuminousBondsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Luminous Bonds"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
{
	// Enchanted creature can't attack or block.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CPathOfDiscoveryCard::CPathOfDiscoveryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Path of Discovery"), CardType::GlobalEnchantment, nID,
		_T("3") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control enters, it explores. (the creature in nValue1, as Verdant Sun's Avatar)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPathOfDiscoveryCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CPathOfDiscoveryCard::BeforeExplore));
	AddAbility(cpAbility.GetPointer());
}

bool CPathOfDiscoveryCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard)
		return false;

	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CPathOfDiscoveryCard::BeforeExplore(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (pCard)
		CExploreSupport::Explore(pCard);
	return true;
}

CPathOfMettleCard::CPathOfMettleCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Path of Mettle"), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, _T("Metzali, Tower of Triumph"))
{
	// When Path of Mettle enters, it deals 1 damage to each creature that doesn't have first strike, double strike,
	// vigilance, or haste.
	AddEnterTrigger(this, &CPathOfMettleCard::BeforeDamage);

	// Whenever you attack with at least two creatures that have first strike, double strike, vigilance, and/or haste,
	// transform Path of Mettle. (a trigger after the attackers are declared, as Legion's Landing)
	AddStepTrigger(this, NodeId::DeclareAttackersStep2, false, &CPathOfMettleCard::SetTriggerContext, &CPathOfMettleCard::BeforeTransform);

	// Metzali, Tower of Triumph: {T}: Add one mana of any color.
	AddBackManaAbility(WHITE_MANA_TEXT);
	AddBackManaAbility(BLUE_MANA_TEXT);
	AddBackManaAbility(BLACK_MANA_TEXT);
	AddBackManaAbility(RED_MANA_TEXT);
	AddBackManaAbility(GREEN_MANA_TEXT);
	{
		// Metzali, Tower of Triumph: {1}{R}, {T}: Metzali deals 2 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") RED_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Deal 2 damage to each opponent. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPathOfMettleCard::BeforeDrain));
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}

	// Metzali, Tower of Triumph: {2}{W}, {T}: Choose a creature at random that attacked this turn. Destroy that creature.
	// Not implemented: the creatures that attacked this turn aren't recorded
}

// The creature has first strike, double strike, vigilance, or haste
static BOOL HasMettleKeyword(CCreatureCard* pCreature)
{
	CCreatureKeyword* pKeyword = pCreature->GetCreatureKeyword();
	return pKeyword->FirstStrike() || pKeyword->DoubleStrike() || pKeyword->Vigilance() || pKeyword->Haste();
}

bool CPathOfMettleCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
			if (pCreature && pCreature->GetCardType().IsCreature() && !HasMettleKeyword(pCreature))
				creatures.AddCard(pCreature, CardPlacement::Top);
		}
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);
	return true;
}

bool CPathOfMettleCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	if (!IsFirstFaceInPlay())
		return false;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	int nAttacking = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (pCreature->IsAttacking() && HasMettleKeyword(pCreature))
			++nAttacking;
	}
	return nAttacking >= 2;
}

bool CPathOfMettleCard::BeforeTransform(CAbilityAction* pAction)
{
	DoTransform();
	return true;
}

bool CPathOfMettleCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	return true;
}

CMetzaliTowerOfTriumphCard::CMetzaliTowerOfTriumphCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Metzali, Tower of Triumph"), nID, CardType::Legendary)
{
	// The back face of Path of Mettle (its abilities are in that card)
	AddAnyColorManaAbility(this);
}

CProfaneProcessionCard::CProfaneProcessionCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Profane Procession"), nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, _T("Tomb of the Dusk Rose"))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CProfaneProcessionCard::OnCreatureSelected))
{
	{
		// {3}{W}{B}: Exile target creature. Then if there are three or more cards exiled with Profane Procession,
		// transform it.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CProfaneProcessionCard::BeforeExile));
		SetFace(cpAbility.GetPointer(), TRUE);
		AddAbility(cpAbility.GetPointer());
	}

	// Tomb of the Dusk Rose: {T}: Add one mana of any color.
	AddBackManaAbility(WHITE_MANA_TEXT);
	AddBackManaAbility(BLUE_MANA_TEXT);
	AddBackManaAbility(BLACK_MANA_TEXT);
	AddBackManaAbility(RED_MANA_TEXT);
	AddBackManaAbility(GREEN_MANA_TEXT);
	{
		// Tomb of the Dusk Rose: {2}{W}{B}, {T}: Put a creature card exiled with this permanent onto the battlefield
		// under your control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Put a creature card exiled with this permanent onto the battlefield. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CProfaneProcessionCard::BeforeChoose));
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CProfaneProcessionCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Exile && !pCard->GetCardType().IsToken())
			m_Exiled.AddCard(pCard, CardPlacement::Top);
	}

	// The cards exiled with it that are still in exile
	int nCount = 0;
	for (int i = 0; i < m_Exiled.GetSize(); ++i)
		if (m_Exiled.GetAt(i)->GetZoneId() == ZoneId::Exile)
			++nCount;
	if (nCount >= 3)
		DoTransform();
	return false;
}

bool CProfaneProcessionCard::BeforeChoose(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < m_Exiled.GetSize(); ++i)
	{
		CCard* pCard = m_Exiled.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Exile || !pCard->GetCardType().IsCreature())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CProfaneProcessionCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Exile)
			{
				m_Exiled.RemoveCard(pCard);
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, FALSE, MoveType::Others, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
		}
}

CTombOfTheDuskRoseCard::CTombOfTheDuskRoseCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Tomb of the Dusk Rose"), nID, CardType::Legendary)
{
	// The back face of Profane Procession (its abilities are in that card)
	AddAnyColorManaAbility(this);
}

CRadiantDestinyCard::CRadiantDestinyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Radiant Destiny"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Enchantment)
	, m_TypeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRadiantDestinyCard::OnTypeSelected))
	, m_SelectedType(SingleCreatureType::Null)
	, m_Ascend(this)
{
	// Ascend (CAscendSupport)
	// As this enchantment enters, choose a creature type. Creatures you control of the chosen type get +1/+1. As long
	// as you have the city's blessing, they also have vigilance. (the abilities are added when the type is chosen, as
	// Shared Triumph in Onslaught)
}

void CRadiantDestinyCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType,
	CardPlacement cardPlacement, BOOL can_dredge)
{
	bool bBattlefield = (GetZoneId() == ZoneId::Battlefield) || (GetZoneId() == ZoneId::_PhasedOut);

	if (!bBattlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		m_SelectedType = SingleCreatureType::Null;

		// The computer chooses among the types of its creatures; a human, among all the types
		BOOL bComputer = m_pGame->IsThinking() || GetController()->IsComputer();
		CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
		std::vector<SelectionEntry> entries;
		for (int i = 1; i < SingleCreatureType::_SingleTypeCount; ++i)
		{
			SingleCreatureType::Enum creatureType = (SingleCreatureType::Enum)i;

			BOOL bAdd = !bComputer;
			for (int k = 0; k < pBattlefield->GetSize() && !bAdd; ++k)
			{
				CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(k));
				if (pCreature && pCreature->GetCardType().IsCreature() && pCreature->GetCreatureType().HasType(creatureType))
					bAdd = TRUE;
			}

			if (bAdd)
			{
				SelectionEntry entry;
				entry.dwContext = creatureType;
				entry.strText.Format(_T("select %s for %s"), SingleCreatureType(creatureType).ToString(), GetCardName(TRUE));
				entries.push_back(entry);
			}
		}

		if (!entries.empty())
			m_TypeSelection.AddSelectionRequest(entries, 1, 1, NULL, GetController());
	}

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	if (bBattlefield && pToZone->GetZoneId() != ZoneId::Battlefield)
	{
		for (int i = 0; i < GetAbilities().GetSize(); ++i)
		{
			CPwrTghAttrEnchantment* pEnchantment = dynamic_cast<CPwrTghAttrEnchantment*>(GetAbilities().GetAt(i).GetPointer());
			if (pEnchantment)
				pEnchantment->EndEnchantment();
		}

		CCardAbilityModifier pBonus = CCardAbilityModifier(
			CCardAbilityModifier::CreateAbilityCallback(this, &CRadiantDestinyCard::CreateBonusAbility));
		pBonus.RemoveFrom(this);
		CCardAbilityModifier pVigilance = CCardAbilityModifier(
			CCardAbilityModifier::CreateAbilityCallback(this, &CRadiantDestinyCard::CreateVigilanceAbility));
		pVigilance.RemoveFrom(this);
	}
}

void CRadiantDestinyCard::OnTypeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			m_SelectedType = SingleCreatureType((SingleCreatureType::Enum)it->dwContext);

			CCardAbilityModifier pBonus = CCardAbilityModifier(
				CCardAbilityModifier::CreateAbilityCallback(this, &CRadiantDestinyCard::CreateBonusAbility));
			pBonus.ApplyTo(this);
			CCardAbilityModifier pVigilance = CCardAbilityModifier(
				CCardAbilityModifier::CreateAbilityCallback(this, &CRadiantDestinyCard::CreateVigilanceAbility));
			pVigilance.ApplyTo(this);

			for (int i = 0; i < GetAbilities().GetSize(); ++i)
			{
				CPwrTghAttrEnchantment* pEnchantment = dynamic_cast<CPwrTghAttrEnchantment*>(GetAbilities().GetAt(i).GetPointer());
				if (pEnchantment)
					pEnchantment->StartEnchantment();
			}
			break;
		}
}

counted_ptr<CAbility> CRadiantDestinyCard::CreateBonusAbility(CCard* pCard)
{
	// Creatures you control of the chosen type get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetEnchantmentCardFilter().AddComparer(new CreatureTypeComparer(m_SelectedType, false));
	cpAbility->SetAbilityName(_T("Radiant Destiny boost"));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

counted_ptr<CAbility> CRadiantDestinyCard::CreateVigilanceAbility(CCard* pCard)
{
	// As long as you have the city's blessing, they also have vigilance.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0), CreatureKeyword::Vigilance));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetEnchantmentCardFilter().AddComparer(new CreatureTypeComparer(m_SelectedType, false));
	cpAbility->GetEnchantmentCardFilter().AddComparer(new CityBlessingComparer);
	cpAbility->SetAbilityName(_T("Radiant Destiny vigilance"));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CSeaLegsCard::CSeaLegsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Sea Legs"), nID,
		BLUE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Null)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	{
		// Enchanted creature gets +0/+2 as long as it's a Pirate.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new EnchantedByComparer(this), new CreatureTypeComparer(CREATURE_TYPE(Pirate), false)),
				Power(+0), Life(+2)));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Otherwise, it gets -2/-0.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new EnchantedByComparer(this), new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false))),
				Power(-2), Life(+0)));

		AddAbility(cpAbility.GetPointer());
	}
}

CSeeRedCard::CSeeRedCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("See Red"), nID,
		_T("1") RED_MANA_TEXT,
		Power(+2), Life(+1), CreatureKeyword::FirstStrike)
{
	// At the beginning of your end step, if you didn't attack with a creature this turn, sacrifice this Aura.
	AddStepTrigger(this, NodeId::EndStep, false, &CSeeRedCard::SetTriggerContext, &CSeeRedCard::BeforeSacrifice);
}

bool CSeeRedCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !HasRaid(GetController());
}

bool CSeeRedCard::BeforeSacrifice(CAbilityAction* pAction)
{
	SacrificeSelf(this, pAction->GetController());
	return true;
}

CSquiresDevotionCard::CSquiresDevotionCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Squire's Devotion"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Null)
{
	// Enchanted creature has lifelink (as Cartouche of Ambition in Amonkhet)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);

	// When this Aura enters, create a 1/1 white Vampire creature token with lifelink.
	AddEnterTrigger(this, &CSquiresDevotionCard::BeforeToken);
}

bool CSquiresDevotionCard::BeforeToken(CAbilityAction* pAction)
{
	CreateVampire(GetGame(), pAction->GetController(), 1);
	return true;
}

CStormTheVaultCard::CStormTheVaultCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Storm the Vault"), nID,
		_T("2") BLUE_MANA_TEXT RED_MANA_TEXT, _T("Vault of Catlacan"))
	, m_nTreasureTurn(-1)
{
	{
		// Whenever one or more creatures you control deal combat damage to a player, create a Treasure token.
		// Note: it triggers once per turn
		counted_ptr<DamageTriggeredAbility> cpAbility(::CreateObject<DamageTriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(DamageTriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(DamageTriggeredAbility::ContextFunction(this, &CStormTheVaultCard::SetDamageContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStormTheVaultCard::BeforeTreasure));
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your end step, if you control five or more artifacts, transform Storm the Vault.
	AddStepTrigger(this, NodeId::EndStep, false, &CStormTheVaultCard::SetTriggerContext, &CStormTheVaultCard::BeforeTransform);

	// Vault of Catlacan: {T}: Add one mana of any color.
	AddBackManaAbility(WHITE_MANA_TEXT);
	AddBackManaAbility(BLUE_MANA_TEXT);
	AddBackManaAbility(BLACK_MANA_TEXT);
	AddBackManaAbility(RED_MANA_TEXT);
	AddBackManaAbility(GREEN_MANA_TEXT);

	// Vault of Catlacan: {T}: Add {U} for each artifact you control.
	// Not implemented: a mana ability can't add a variable amount of mana
}

bool CStormTheVaultCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	if (!IsFirstFaceInPlay() || !pToPlayer || pToPlayer == GetController())
		return false;

	int nTurn = GetGame()->GetGameTurnNumber();
	if (nTurn == m_nTreasureTurn)
		return false;

	m_nTreasureTurn = nTurn;
	return true;
}

bool CStormTheVaultCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CStormTheVaultCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	if (!IsFirstFaceInPlay())
		return false;

	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	int nArtifacts = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsArtifact() && !pBattlefield->GetAt(i)->GetIsAlsoOf())
			++nArtifacts;
	return nArtifacts >= 5;
}

bool CStormTheVaultCard::BeforeTransform(CAbilityAction* pAction)
{
	DoTransform();
	return true;
}

CVaultOfCatlacanCard::CVaultOfCatlacanCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Vault of Catlacan"), nID, CardType::Legendary)
{
	// The back face of Storm the Vault (its abilities are in that card)
	AddAnyColorManaAbility(this);
}

CTilonallisCrownCard::CTilonallisCrownCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Tilonalli's Crown"), nID,
		_T("1") RED_MANA_TEXT,
		Power(+3), Life(+0), CreatureKeyword::Trample)
{
	// When this Aura enters, it deals 1 damage to enchanted creature.
	AddEnterTrigger(this, &CTilonallisCrownCard::BeforeDamage);
}

bool CTilonallisCrownCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCreature = GetEnchantedOn();
	if (pCreature)
		DealDamageToCreature(this, pCreature, 1);
	return true;
}

CWaterknotCard::CWaterknotCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Waterknot"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Null)
{
	// Enchanted creature doesn't untap during its controller's untap step.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);

	// When this Aura enters, tap enchanted creature.
	AddEnterTrigger(this, &CWaterknotCard::BeforeTap);
}

bool CWaterknotCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCreature = GetEnchantedOn();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

CAwakenedAmalgamCard::CAwakenedAmalgamCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Awakened Amalgam"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("4"), Power(0), Life(0))
{
	// Awakened Amalgam's power and toughness are each equal to the number of differently named lands you control.
	// (as Nim Grotesque, counting only the first land of each name)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new FirstNamedLandComparer));

	AddAbility(cpAbility.GetPointer());
}

CAzorsGatewayCard::CAzorsGatewayCard(CGame* pGame, UINT nID)
	: CTransformArtifactBase(pGame, _T("Azor's Gateway"), nID,
		_T("2"), _T("Sanctum of the Sun"), CardType::_LegendaryArtifact)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CAzorsGatewayCard::OnCardSelected))
{
	// {1}, {T}: Draw a card, then exile a card from your hand. If cards with five or more different mana values are
	// exiled with Azor's Gateway, you gain 5 life, untap Azor's Gateway, and transform it.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Draw a card, then exile a card from your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAzorsGatewayCard::BeforeDraw));
	SetFace(cpAbility.GetPointer(), TRUE);
	AddAbility(cpAbility.GetPointer());

	// Sanctum of the Sun: {T}: Add X mana of any one color, where X is your life total.
	// Not implemented: a mana ability can't add a variable amount of mana
}

bool CAzorsGatewayCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);

	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CAzorsGatewayCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Hand)
				continue;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() != ZoneId::Exile)
				continue;

			int nManaValue = (int)pCard->GetConvertedManaCost();
			if (std::find(m_ManaValues.begin(), m_ManaValues.end(), nManaValue) == m_ManaValues.end())
				m_ManaValues.push_back(nManaValue);
		}

	if (m_ManaValues.size() >= 5 && IsFirstFaceInPlay())
	{
		GainLife(this, pSelectionPlayer, 5);

		CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
		pUntap.ApplyTo(this);

		DoTransform();
	}
}

CSanctumOfTheSunCard::CSanctumOfTheSunCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Sanctum of the Sun"), nID, CardType::Legendary)
{
	// The back face of Azor's Gateway (its abilities are in that card)
	// Not implemented: {T}: Add X mana of any one color, where X is your life total.
}

CCaptainsHookCard::CCaptainsHookCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Captain's Hook"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	// Equipped creature gets +2/+0, has menace, and is a Pirate in addition to its other creature types.
	// Equip {1} (as Strider Harness in Scars of Mirrodin)
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::CantBeBlockedBy1);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);

	cpAbility->AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Pirate));

	AddAbility(cpAbility.GetPointer());

	// Whenever this Equipment becomes unattached from a permanent, destroy that permanent.
	// Not implemented: there is no event for an Equipment becoming unattached
}

CGleamingBarrierCard::CGleamingBarrierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gleaming Barrier"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("2"), Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// When this creature dies, create a Treasure token.
	AddDiesTrigger(this, &CGleamingBarrierCard::BeforeTreasure);
}

bool CGleamingBarrierCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CGoldenGuardianCard::CGoldenGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Golden Guardian"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("4"), Power(4), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {2}: This creature fights another target creature you control. When this creature dies this turn, return it to
	// the battlefield transformed under your control.
	// Not implemented: the return transformed (a creature card can't come back as its land face)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2"),
			new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))), FALSE));

	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGoldenGuardianCard::BeforeFight));
	AddAbility(cpAbility.GetPointer());
}

bool CGoldenGuardianCard::BeforeFight(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && GetZoneId() == ZoneId::Battlefield)
		Fight(this, pCard);
	return false;
}

CGoldForgeGarrisonCard::CGoldForgeGarrisonCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Gold-Forge Garrison"), nID)
{
	// The back face of Golden Guardian (shown only: Golden Guardian doesn't transform)
	// {T}: Add two mana of any one color.
	AddTapManaAbility(this, WHITE_MANA_TEXT WHITE_MANA_TEXT);
	AddTapManaAbility(this, BLUE_MANA_TEXT BLUE_MANA_TEXT);
	AddTapManaAbility(this, BLACK_MANA_TEXT BLACK_MANA_TEXT);
	AddTapManaAbility(this, RED_MANA_TEXT RED_MANA_TEXT);
	AddTapManaAbility(this, GREEN_MANA_TEXT GREEN_MANA_TEXT);
	// Not implemented: {4}, {T}: Create a 4/4 colorless Golem artifact creature token.
}

COrazcaRelicCard::COrazcaRelicCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Orazca Relic"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Ascend(this)
{
	// Ascend (CAscendSupport)

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {T}, Sacrifice this artifact: You gain 3 life and draw a card. Activate only if you have the city's blessing.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("You gain 3 life and draw a card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COrazcaRelicCard::BeforeDraw));
	AddPlayableIf(this, cpAbility.GetPointer(), &COrazcaRelicCard::HasBlessing);
	AddAbility(cpAbility.GetPointer());
}

BOOL COrazcaRelicCard::HasBlessing(BOOL bIncludeTricks)
{
	return GetController()->HasCityBlessing();
}

bool COrazcaRelicCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSilentGravestoneCard::CSilentGravestoneCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Silent Gravestone"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// Cards in graveyards can't be the targets of spells or abilities.
	// Not implemented: there is no restriction on targeting cards in graveyards

	// {4}, {T}: Exile this artifact and all cards from all graveyards. Draw a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("4")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Exile this artifact and all cards from all graveyards, then draw a card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSilentGravestoneCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());
}

bool CSilentGravestoneCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController);
		pModifier.ApplyTo(this);
	}
	ExileAllGraveyards(GetGame(), pController);
	DrawCards(GetGame(), pController, 1);
	return true;
}

CTheImmortalSunCard::CTheImmortalSunCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Immortal Sun"), CardType::_LegendaryArtifact, nID,
		_T("6"), AbilityType::Artifact)
{
	// Players can't activate planeswalkers' loyalty abilities.
	// Not implemented: the loyalty abilities can't be forbidden

	{
		// At the beginning of your draw step, draw an additional card. (as Overbeing of Myth in Eventide)
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this, NodeId::DrawStep2));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Spells you cast cost {1} less to cast.
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
				_T("1")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Creatures you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(+1), Life(+1)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

CAngrathsFuryCard::CAngrathsFuryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Angrath's Fury"), CardType::Sorcery, nID)
{
	// Destroy target creature. Angrath's Fury deals 3 damage to target player or planeswalker. You may search your
	// library and/or graveyard for a card named Angrath, Minotaur Pirate, reveal it, and put it into your hand. If you
	// search your library this way, shuffle.
	// Note: it can't target planeswalkers
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			FALSE_CARD_COMPARER, TRUE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngrathsFuryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAngrathsFuryCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pCreature = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		pModifier.ApplyTo(pCreature);
	}

	CPlayer* pPlayer = (CPlayer*)pDoubleTargetAction->GetTargetGroup2().GetFirstPlayerSubject();
	if (pPlayer)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}

	SearchNamedCardToHand(pAction->GetController(), _T("Angrath, Minotaur Pirate"));
	return false;
}

CArterialFlowCard::CArterialFlowCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Arterial Flow"), CardType::Sorcery, nID)
{
	// Each opponent discards two cards. If you control a Vampire, each opponent loses 2 life and you gain 2 life.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArterialFlowCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CArterialFlowCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 2);

	CCardFilter vampires(_T("a Vampire"), _T("Vampires"), new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	if (vampires.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
		DrainOpponents(this, pController, 2, TRUE);
	return true;
}

CBrasssBountyCard::CBrasssBountyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Brass's Bounty"), CardType::Sorcery, nID)
{
	// For each land you control, create a Treasure token.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("6") RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBrasssBountyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBrasssBountyCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nLands = CCardFilter::GetFilter(_T("lands"))->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nLands > 0)
		CreateTreasure(GetGame(), pController, nLands);
	return true;
}

CCleansingRayCard::CCleansingRayCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cleansing Ray"), CardType::Sorcery, nID)
{
	// Choose one -
	{
		// Destroy target Vampire.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("1") WHITE_MANA_TEXT,
				new CreatureTypeComparer(CREATURE_TYPE(Vampire), false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Destroy target Vampire. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Destroy target enchantment.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("1") WHITE_MANA_TEXT,
				new CardTypeComparer(CardType::_Enchantment, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Destroy target enchantment. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

CCrashingTideCard::CCrashingTideCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Crashing Tide"), CardType::Sorcery, nID)
{
	// This spell has flash as long as you control a Merfolk. Return target creature to its owner's hand. Draw a card.
	// (a second spell with instant speed, cast only if you control a Merfolk)
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, i == 0 ? AbilityType::Sorcery : AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrashingTideCard::BeforeDraw));
		if (i == 1)
		{
			cpSpell->SetAbilityText(_T("Return target creature to its owner's hand and draw a card (flash, you control a Merfolk). Casts"));
			AddPlayableIf(this, cpSpell.GetPointer(), &CCrashingTideCard::ControlsMerfolk);
		}
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CCrashingTideCard::ControlsMerfolk(BOOL bIncludeTricks)
{
	CCardFilter merfolk(_T("a Merfolk"), _T("Merfolk"), new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	return merfolk.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

// The card is drawn before the creature returns (the callback returns true: ResolveImpl moves the target)
bool CCrashingTideCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDarkInquiryCard::CDarkInquiryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dark Inquiry"), CardType::Sorcery, nID)
	, m_NonlandFilter(_T("a nonland card"), _T("nonland cards"), new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Target opponent reveals their hand. You choose a nonland card from it. That player discards that card.
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			1, MoveType::Discard, ZoneId::Graveyard, TRUE,
			FALSE,
			&m_NonlandFilter));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	AddSpell(cpSpell.GetPointer());
}

CEnterTheUnknownCard::CEnterTheUnknownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Enter the Unknown"), CardType::Sorcery, nID)
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CEnterTheUnknownCard::OnCreatureSelected))
{
	// Target creature you control explores. You may play an additional land this turn. (as Explore in Worldwake)
	// Note: the creature is chosen on resolution (not targeted)
	counted_ptr<CPlayExtraLandSpell> cpSpell(
		::CreateObject<CPlayExtraLandSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT, 1, TRUE));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEnterTheUnknownCard::BeforeExplore));
	AddSpell(cpSpell.GetPointer());
}

bool CEnterTheUnknownCard::BeforeExplore(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("%s explores"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CEnterTheUnknownCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				CExploreSupport::Explore(pCard);
		}
}

CFloodOfRecollectionCard::CFloodOfRecollectionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Flood of Recollection"), CardType::Sorcery, nID)
{
	// Return target instant or sorcery card from your graveyard to your hand. Exile Flood of Recollection.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	AddSpell(cpSpell.GetPointer());
}

CGoldenDemiseCard::CGoldenDemiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Golden Demise"), CardType::Sorcery, nID)
{
	// Ascend. All creatures get -2/-2 until end of turn. If you have the city's blessing, instead only creatures your
	// opponents control get -2/-2 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGoldenDemiseCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGoldenDemiseCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	BOOL bBlessing = CAscendSupport::CheckSpell(pController);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	if (!bBlessing)
		GetCreatures(GetGame(), pController, TRUE, creatures);

	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), -2, -2);
	return true;
}

CGruesomeFateCard::CGruesomeFateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gruesome Fate"), CardType::Sorcery, nID)
{
	// Each opponent loses 1 life for each creature you control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGruesomeFateCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGruesomeFateCard::BeforeResolution(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), CountCreatures(GetGame(), pAction->GetController()), FALSE);
	return true;
}

CHuntTheWeakCard::CHuntTheWeakCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hunt the Weak"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on target creature you control. Then that creature fights target creature you don't control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHuntTheWeakCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHuntTheWeakCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pCreature = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return false;

	AddPlusCounter(pCreature);
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		Fight(pCreature, pTarget);
	return false;
}

CImpaleCard::CImpaleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Impale"), CardType::Sorcery, nID)
{
	// Destroy target creature.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CMastermindsAcquisitionCard::CMastermindsAcquisitionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mastermind's Acquisition"), CardType::Sorcery, nID)
{
	// Choose one - Search your library for a card, put it into your hand, then shuffle.
	// Not implemented: the second mode (put a card you own from outside the game into your hand)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMastermindsAcquisitionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CMastermindsAcquisitionCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // a card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CMutinyCard::CMutinyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mutiny"), CardType::Sorcery, nID)
{
	// Target creature an opponent controls deals damage equal to its power to another target creature that player
	// controls.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMutinyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CMutinyCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCreatureCard* pSource = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (!pSource || !pTarget || pSource == pTarget || pSource->GetZoneId() != ZoneId::Battlefield ||
		pSource->GetController() != pTarget->GetController())
		return false;

	DealDamageToCreature(pSource, pTarget, (int)pSource->GetPower());
	return false;
}

CPiratesPillageCard::CPiratesPillageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pirate's Pillage"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, discard a card. Draw two cards and create two Treasure tokens.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT));

	cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPiratesPillageCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPiratesPillageCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	CreateTreasure(GetGame(), pAction->GetController(), 2);
	return true;
}

CSecretsOfTheGoldenCityCard::CSecretsOfTheGoldenCityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Secrets of the Golden City"), CardType::Sorcery, nID)
{
	// Ascend. Draw two cards. If you have the city's blessing, draw three cards instead.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSecretsOfTheGoldenCityCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSecretsOfTheGoldenCityCard::BeforeResolution(CAbilityAction* pAction)
{
	BOOL bBlessing = CAscendSupport::CheckSpell(pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), bBlessing ? 3 : 2);
	return true;
}

CSlaughterTheStrongCard::CSlaughterTheStrongCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Slaughter the Strong"), CardType::Sorcery, nID)
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CSlaughterTheStrongCard::OnCreatureSelected))
	, m_nPlayer(0)
	, m_nPower(4)
	, m_pCaster(NULL)
{
	// Each player chooses any number of creatures they control with total power 4 or less, then sacrifices all other
	// creatures they control. (each player keeps creatures one by one while their total power is 4 or less; the
	// creatures with power 0 or less are always kept)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSlaughterTheStrongCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSlaughterTheStrongCard::BeforeResolution(CAbilityAction* pAction)
{
	m_Kept.clear();
	m_nPlayer = 0;
	m_nPower = 4;
	m_pCaster = pAction->GetController();
	ChooseNext();
	return true;
}

void CSlaughterTheStrongCard::ChooseNext()
{
	while (m_nPlayer < GetGame()->GetPlayerCount())
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(m_nPlayer);
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pPlayer, TRUE, creatures);

		std::vector<SelectionEntry> entries;
		for (int i = 0; i < creatures.GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
			if (!pCreature || std::find(m_Kept.begin(), m_Kept.end(), pCreature) != m_Kept.end())
				continue;

			int nPower = (int)pCreature->GetPower();
			if (nPower <= 0)
				m_Kept.push_back(pCreature);
			else if (nPower <= m_nPower)
			{
				SelectionEntry entry;
				entry.dwContext = (DWORD)pCreature;
				entry.cpAssociatedCard = pCreature;
				entry.strText.Format(_T("Keep %s (power %d)"), pCreature->GetCardName(TRUE), nPower);
				entries.push_back(entry);
			}
		}

		if (!entries.empty())
		{
			// One creature at a time; selecting none ends this player's choice
			m_CreatureSelection.AddSelectionRequest(entries, 0, 1, this, pPlayer);
			return;
		}

		++m_nPlayer;
		m_nPower = 4;
	}

	// Each player sacrifices the creatures they didn't keep
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pPlayer, TRUE, creatures);

		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pPlayer);
		for (int i = 0; i < creatures.GetSize(); ++i)
			if (std::find(m_Kept.begin(), m_Kept.end(), creatures.GetAt(i)) == m_Kept.end())
				pModifier.ApplyTo(creatures.GetAt(i));
	}
	m_Kept.clear();
}

void CSlaughterTheStrongCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	BOOL bKept = FALSE;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCreatureCard* pCreature = (CCreatureCard*)it->dwContext;
			m_Kept.push_back(pCreature);
			m_nPower -= (int)pCreature->GetPower();
			bKept = TRUE;
		}

	if (!bKept)
	{
		++m_nPlayer;
		m_nPower = 4;
	}
	ChooseNext();
}

CSphinxsDecreeCard::CSphinxsDecreeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sphinx's Decree"), CardType::Sorcery, nID)
{
	// Each opponent can't cast instant or sorcery spells during that player's next turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSphinxsDecreeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

// The effect is applied at the beginning of the opponent's next turn (upkeep) and removed at its cleanup step
// (scheduled on that player's turns, as Watertrap Weaver in Ixalan)
bool CSphinxsDecreeCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CScheduledPlayerModifier pApply = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, (int)CCardFilter::GetFilter(_T("instant cards or sorcery cards"))),
			TurnNumberDelta(-1), NodeId::UpkeepStep, CScheduledPlayerModifier::Operation::ApplyToLater,
			CScheduledPlayerModifier::DeltaOption::CustomPlayerTurn, pPlayer);
		pApply.ApplyTo(pPlayer);

		CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, (int)CCardFilter::GetFilter(_T("instant cards or sorcery cards"))),
			TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater,
			CScheduledPlayerModifier::DeltaOption::CustomPlayerTurn, pPlayer);
		pRemove.ApplyTo(pPlayer);
	}
	return true;
}

CStrengthOfThePackCard::CStrengthOfThePackCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Strength of the Pack"), CardType::Sorcery, nID)
{
	// Put two +1/+1 counters on each creature you control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStrengthOfThePackCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CStrengthOfThePackCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i), 2);
	return true;
}

CThunderherdMigrationCard::CThunderherdMigrationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thunderherd Migration"), CardType::Sorcery, nID)
	, m_DinosaurFilter(_T("a Dinosaur card"), _T("Dinosaur cards"), new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false))
{
	// As an additional cost to cast this spell, reveal a Dinosaur card from your hand or pay {1}. Search your library
	// for a basic land card, put it onto the battlefield tapped, then shuffle. (one spell for each additional cost)
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				i == 0 ? _T("1") GREEN_MANA_TEXT : _T("2") GREEN_MANA_TEXT));

		if (i == 0)
		{
			cpSpell->GetCost().AddRevealCardCost(1, &m_DinosaurFilter);
			cpSpell->SetAbilityText(_T("Reveal a Dinosaur card: search for a basic land. Casts"));
		}
		else
			cpSpell->SetAbilityText(_T("Pay {1}: search for a basic land. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThunderherdMigrationCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CThunderherdMigrationCard::BeforeResolution(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("basic lands")), TRUE);
	return true;
}

CVraskasScornCard::CVraskasScornCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vraska's Scorn"), CardType::Sorcery, nID)
{
	// Target opponent loses 4 life. You may search your library and/or graveyard for a card named Vraska, Scheming
	// Gorgon, reveal it, and put it into your hand. If you search your library this way, shuffle.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVraskasScornCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CVraskasScornCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-4), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pPlayer);
	}

	SearchNamedCardToHand(pAction->GetController(), _T("Vraska, Scheming Gorgon"));
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

CAdmiralsOrderCard::CAdmiralsOrderCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Admiral's Order"), CardType::Instant, nID)
{
	// Raid - If you attacked this turn, you may pay {U} rather than pay this spell's mana cost. Counter target spell.
	// (a second spell for {U}, as Lookout's Dispersal in Ixalan)
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				i == 0 ? _T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT : BLUE_MANA_TEXT,
				new TrueCardComparer));

		if (i == 1)
		{
			cpSpell->SetAbilityText(_T("Admiral's Order (Raid: pay {U}). Casts"));
			AddPlayableIf(this, cpSpell.GetPointer(), &CAdmiralsOrderCard::HasRaidCondition);
		}
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CAdmiralsOrderCard::HasRaidCondition(BOOL bIncludeTricks)
{
	return HasRaid(GetController());
}

CBlazingHopeCard::CBlazingHopeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blazing Hope"), CardType::Instant, nID)
{
	// Exile target creature with power greater than or equal to your life total.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT,
			new PowerAtLeastLifeComparer(this),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CBombardCard::CBombardCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bombard"), CardType::Instant, nID)
{
	// Bombard deals 4 damage to target creature.
	AddDamageSpell(this, _T("2") RED_MANA_TEXT, 4, new AnyCreatureComparer, FALSE);
}

CBuccaneersBravadoCard::CBuccaneersBravadoCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Buccaneer's Bravado"), CardType::Instant, nID)
{
	// Choose one -
	{
		// Target creature gets +1/+1 and gains first strike until end of turn.
		CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") RED_MANA_TEXT, FALSE, &CBuccaneersBravadoCard::BeforeFirstStrike);
		pSpell->SetAbilityText(_T("Target creature gets +1/+1 and gains first strike. Casts"));
	}
	{
		// Target Pirate gets +1/+1 and gains double strike until end of turn.
		CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") RED_MANA_TEXT, FALSE, &CBuccaneersBravadoCard::BeforeDoubleStrike);
		pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false));
		pSpell->SetAbilityText(_T("Target Pirate gets +1/+1 and gains double strike. Casts"));
	}
}

bool CBuccaneersBravadoCard::BeforeFirstStrike(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +1, +1, CreatureKeyword::FirstStrike);
	return false;
}

bool CBuccaneersBravadoCard::BeforeDoubleStrike(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +1, +1, CreatureKeyword::DoubleStrike);
	return false;
}

CExpelFromOrazcaCard::CExpelFromOrazcaCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Expel from Orazca"), CardType::Instant, nID)
	, m_PlaceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CExpelFromOrazcaCard::OnPlaceSelected))
{
	// Ascend. Return target nonland permanent to its owner's hand. If you have the city's blessing, you may put that
	// permanent on top of its owner's library instead.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExpelFromOrazcaCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

// Without the city's blessing the callback returns true (ResolveImpl returns the permanent to the hand); with it, the
// controller chooses the hand or the top of the library
bool CExpelFromOrazcaCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!CAscendSupport::CheckSpell(pAction->GetController()) || !pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)ZoneId::Hand;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Return %s to its owner's hand"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)ZoneId::Library;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s on top of its owner's library"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_PlaceSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController(), (DWORD)pCard);
	return false;
}

void CExpelFromOrazcaCard::OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, (ZoneId::Enum)it->dwContext, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
		}
}

CHornswoggleCard::CHornswoggleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hornswoggle"), CardType::Instant, nID)
{
	// Counter target creature spell. You create a Treasure token.
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Creature, false)));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHornswoggleCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHornswoggleCard::BeforeResolution(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CMomentOfCravingCard::CMomentOfCravingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Moment of Craving"), CardType::Instant, nID)
{
	// Target creature gets -2/-2 until end of turn. You gain 2 life.
	CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") BLACK_MANA_TEXT, FALSE, &CMomentOfCravingCard::BeforeResolution);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

bool CMomentOfCravingCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, -2, -2);
	GainLife(this, pAction->GetController(), 2);
	return false;
}

CMomentOfTriumphCard::CMomentOfTriumphCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Moment of Triumph"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 until end of turn. You gain 2 life.
	AddCreatureSpell(this, WHITE_MANA_TEXT, FALSE, &CMomentOfTriumphCard::BeforeResolution);
}

bool CMomentOfTriumphCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +2, +2);
	GainLife(this, pAction->GetController(), 2);
	return false;
}

CPrideOfConquerorsCard::CPrideOfConquerorsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pride of Conquerors"), CardType::Instant, nID)
{
	// Ascend. Creatures you control get +1/+1 until end of turn. If you have the city's blessing, those creatures get
	// +2/+2 until end of turn instead.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrideOfConquerorsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPrideOfConquerorsCard::BeforeResolution(CAbilityAction* pAction)
{
	int nBonus = CAscendSupport::CheckSpell(pAction->GetController()) ? 2 : 1;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), nBonus, nBonus);
	return true;
}

CReaverAmbushCard::CReaverAmbushCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reaver Ambush"), CardType::Instant, nID)
{
	// Exile target creature with power 3 or less.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			new CreaturePowerComparer<std::less_equal<int>>(3),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CRecklessRageCard::CRecklessRageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reckless Rage"), CardType::Instant, nID)
{
	// Reckless Rage deals 4 damage to target creature you don't control and 2 damage to target creature you control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRecklessRageCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRecklessRageCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	DealDamageToCreature(this, (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(), 4);
	DealDamageToCreature(this, (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject(), 2);
	return false;
}

CShakeTheFoundationsCard::CShakeTheFoundationsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shake the Foundations"), CardType::Instant, nID)
{
	// Shake the Foundations deals 1 damage to each creature without flying. Draw a card.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShakeTheFoundationsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CShakeTheFoundationsCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
			if (pCreature && pCreature->GetCardType().IsCreature() && !pCreature->GetCreatureKeyword()->Flying())
				creatures.AddCard(pCreature, CardPlacement::Top);
		}
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);

	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CVonasHungerCard::CVonasHungerCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vona's Hunger"), CardType::Instant, nID)
{
	// Ascend. Each opponent sacrifices a creature of their choice. If you have the city's blessing, instead each
	// opponent sacrifices half the creatures they control of their choice, rounded up.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVonasHungerCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CVonasHungerCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	BOOL bBlessing = CAscendSupport::CheckSpell(pController);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		int nCreatures = CountCreatures(GetGame(), pPlayer);
		int nCount = bBlessing ? (nCreatures + 1) / 2 : 1;
		if (nCount > nCreatures)
			nCount = nCreatures;
		if (nCount <= 0)
			continue;

		// The player chooses the creatures to sacrifice (as SacrificeOne in Hour of Devastation)
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Battlefield, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(nCount), MaximumValue(nCount), // the creatures to sacrifice
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			CCardFilter::GetFilter(_T("creatures")), // what cards
			ZoneId::Graveyard, // if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top, // put selected cards on
			MoveType::Sacrifice, // move type
			CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (white creatures)

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

//____________________________________________________________________________
//
// White creatures

CBishopOfBindingCard::CBishopOfBindingCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bishop of Binding"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("3") WHITE_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, exile target creature an opponent controls until this creature leaves the
	// battlefield.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CBishopOfBindingCard::BeforeExile, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
	AddLeaveTrigger(this, &CBishopOfBindingCard::BeforeReturn);

	// Whenever this creature attacks, target Vampire gets +X/+X until end of turn, where X is the power of the exiled
	// card.
	pTargeting = AddSelfAttackTargetTrigger(this, &CBishopOfBindingCard::BeforePump, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
}

bool CBishopOfBindingCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CBishopOfBindingCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

bool CBishopOfBindingCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || m_Exiled.GetSize() == 0)
		return false;

	CCreatureCard* pExiled = dynamic_cast<CCreatureCard*>(m_Exiled.GetAt(0));
	int nPower = pExiled && pExiled->GetZoneId() == ZoneId::Exile ? (int)pExiled->GetPower() : 0;
	if (nPower > 0)
		PumpCreature(pCard, nPower, nPower);
	return false;
}

CEverdawnChampionCard::CEverdawnChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Everdawn Champion"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Prevent all combat damage that would be dealt to this creature.
	GetCreatureKeyword()->AddPreventAllCombatDamage(FALSE);
}

CExultantSkymarcherCard::CExultantSkymarcherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Exultant Skymarcher"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
{
}

CFamishedPaladinCard::CFamishedPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Famished Paladin"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// This creature doesn't untap during your untap step.
	GetCardKeyword()->AddNoUntapInUntapPhase();

	// Whenever you gain life, untap this creature. (as Ajani's Pridemate in M11)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFamishedPaladinCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFamishedPaladinCard::BeforeUntap));
	AddAbility(cpAbility.GetPointer());
}

bool CFamishedPaladinCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

bool CFamishedPaladinCard::BeforeUntap(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CForerunnerOfTheLegionCard::CForerunnerOfTheLegionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forerunner of the Legion"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_VampireFilter(_T("a Vampire card"), _T("Vampire cards"), new CreatureTypeComparer(CREATURE_TYPE(Vampire), false))
{
	// When this creature enters, you may search your library for a Vampire card, reveal it, then shuffle and put that
	// card on top.
	AddEnterTrigger(this, &CForerunnerOfTheLegionCard::BeforeSearch, true);

	// Whenever another Vampire you control enters, target creature gets +1/+1 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CForerunnerOfTheLegionCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

// The library is shuffled first, then the chosen card is put on top (the same result)
bool CForerunnerOfTheLegionCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	pController->GetZoneById(ZoneId::Library)->Shuffle();

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a Vampire card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		&m_VampireFilter, // what cards
		ZoneId::Library, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);
	return true;
}

bool CForerunnerOfTheLegionCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +1, +1);
	return false;
}

CImperialCeratopsCard::CImperialCeratopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Imperial Ceratops"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(5))
{
	// Enrage - Whenever this creature is dealt damage, you gain 2 life.
	AddEnrageTrigger(this, &CImperialCeratopsCard::SetEnrageContext, &CImperialCeratopsCard::BeforeGainLife);
}

bool CImperialCeratopsCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CImperialCeratopsCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CMajesticHeliopterusCard::CMajesticHeliopterusCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Majestic Heliopterus"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, another target Dinosaur you control gains flying until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CMajesticHeliopterusCard::BeforeFlying, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CMajesticHeliopterusCard::BeforeFlying(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +0, +0, CreatureKeyword::Flying);
	return false;
}

CMartyrOfDuskCard::CMartyrOfDuskCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Martyr of Dusk"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// When this creature dies, create a 1/1 white Vampire creature token with lifelink.
	AddDiesTrigger(this, &CMartyrOfDuskCard::BeforeToken);
}

bool CMartyrOfDuskCard::BeforeToken(CAbilityAction* pAction)
{
	CreateVampire(GetGame(), pAction->GetController(), 1);
	return true;
}

CPaladinOfAtonementCard::CPaladinOfAtonementCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Paladin of Atonement"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1))
{
	{
		// At the beginning of each upkeep, if you lost life last turn, put a +1/+1 counter on this creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPaladinOfAtonementCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPaladinOfAtonementCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// When this creature dies, you gain life equal to its toughness.
	AddDiesTrigger(this, &CPaladinOfAtonementCard::BeforeGainLife);
}

bool CPaladinOfAtonementCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetController()->GetTotalLifeLossTakenLastTurn() > Life(0);
}

bool CPaladinOfAtonementCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

bool CPaladinOfAtonementCard::BeforeGainLife(CAbilityAction* pAction)
{
	int nToughness = (int)GetLastKnownToughness();
	if (nToughness > 0)
		GainLife(this, pAction->GetController(), nToughness);
	return true;
}

CSanguineGlorifierCard::CSanguineGlorifierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sanguine Glorifier"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, put a +1/+1 counter on another target Vampire you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CSanguineGlorifierCard::BeforeCounter, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CSanguineGlorifierCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard);
	return false;
}

CSkymarcherAspirantCard::CSkymarcherAspirantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skymarcher Aspirant"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Ascend(this)
{
	// Ascend. This creature has flying as long as you have the city's blessing.
	AddBlessingBonus(this, +0, CreatureKeyword::Flying);
}

CSnubhornSentryCard::CSnubhornSentryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Snubhorn Sentry"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		WHITE_MANA_TEXT, Power(0), Life(3))
	, m_Ascend(this)
{
	// Ascend. This creature gets +3/+0 as long as you have the city's blessing.
	AddBlessingBonus(this, +3, CreatureKeyword::Null);
}

CSunCrestedPterodonCard::CSunCrestedPterodonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sun-Crested Pterodon"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") WHITE_MANA_TEXT, Power(2), Life(5))
{
	// This creature has vigilance as long as you control another Dinosaur.
	AddAnotherTypeBonus(this, CREATURE_TYPE(Dinosaur), +0, CreatureKeyword::Vigilance);
}

CSunSentinelCard::CSunSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sun Sentinel"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CTrapjawTyrantCard::CTrapjawTyrantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trapjaw Tyrant"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	// Enrage - Whenever this creature is dealt damage, exile target creature an opponent controls until this creature
	// leaves the battlefield.
	CTargeting* pTargeting = AddEnrageTargetTrigger(this, &CTrapjawTyrantCard::SetEnrageContext, &CTrapjawTyrantCard::BeforeExile, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
	AddLeaveTrigger(this, &CTrapjawTyrantCard::BeforeReturn);
}

bool CTrapjawTyrantCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CTrapjawTyrantCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CTrapjawTyrantCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CZetalpaPrimalDawnCard::CZetalpaPrimalDawnCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Zetalpa, Primal Dawn"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dinosaur), nID,
		_T("6") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(8))
{
	// Flying, double strike, vigilance, trample, indestructible
	GetCreatureKeyword()->AddDoubleStrike(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCardKeyword()->AddIndestructible(FALSE);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (green creatures)

#define SAPROLING_TOKEN_NAME	_T("Saproling (K)")
#define SAPROLING_TOKEN_ID		62002

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

//____________________________________________________________________________
//
// Green creatures

CCacophodonCard::CCacophodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cacophodon"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(5))
{
	// Enrage - Whenever this creature is dealt damage, untap target permanent.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenDamageDealt,
								 CWhenDamageDealt::CreatureEventCallback, &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCacophodonCard::SetEnrageContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCacophodonCard::BeforeUntap));
	AddAbility(cpAbility.GetPointer());
}

bool CCacophodonCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CCacophodonCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CCrestedHerdcallerCard::CCrestedHerdcallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Crested Herdcaller"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, create a 3/3 green Dinosaur creature token with trample.
	AddEnterTrigger(this, &CCrestedHerdcallerCard::BeforeToken);
}

bool CCrestedHerdcallerCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), DINOSAUR_A_TOKEN_NAME, DINOSAUR_A_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CDeeprootEliteCard::CDeeprootEliteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deeproot Elite"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever another Merfolk you control enters, put a +1/+1 counter on target Merfolk you control.
	AddAnotherTypeEntersTrigger(this, CREATURE_TYPE(Merfolk), TRUE, &CDeeprootEliteCard::BeforeCounter);
}

bool CDeeprootEliteCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard);
	return false;
}

CForerunnerOfTheHeraldsCard::CForerunnerOfTheHeraldsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forerunner of the Heralds"), CardType::Creature, CREATURE_TYPE2(Merfolk, Scout), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_MerfolkFilter(_T("a Merfolk card"), _T("Merfolk cards"), new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false))
{
	// When this creature enters, you may search your library for a Merfolk card, reveal it, then shuffle and put that
	// card on top.
	AddEnterTrigger(this, &CForerunnerOfTheHeraldsCard::BeforeSearch, true);

	// Whenever another Merfolk you control enters, put a +1/+1 counter on this creature.
	AddAnotherTypeEntersTrigger(this, CREATURE_TYPE(Merfolk), FALSE, &CForerunnerOfTheHeraldsCard::BeforeCounter);
}

bool CForerunnerOfTheHeraldsCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToTop(GetGame(), pAction->GetController(), &m_MerfolkFilter);
	return true;
}

bool CForerunnerOfTheHeraldsCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

CGhaltaPrimalHungerCard::CGhaltaPrimalHungerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghalta, Primal Hunger"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dinosaur), nID,
		_T("10") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(12), Life(12))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// This spell costs {X} less to cast, where X is the total power of creatures you control.
	// (one more spell for the total power of your creatures, from 1 to 10 or more, as Hollow One would need)
	static LPCTSTR costs[] = { _T("9"), _T("8"), _T("7"), _T("6"), _T("5"), _T("4"), _T("3"), _T("2"), _T("1"), _T("") };
	typedef BOOL (CGhaltaPrimalHungerCard::*Condition)(BOOL);
	Condition conditions[] = {
		&CGhaltaPrimalHungerCard::CanReduce1, &CGhaltaPrimalHungerCard::CanReduce2,
		&CGhaltaPrimalHungerCard::CanReduce3, &CGhaltaPrimalHungerCard::CanReduce4,
		&CGhaltaPrimalHungerCard::CanReduce5, &CGhaltaPrimalHungerCard::CanReduce6,
		&CGhaltaPrimalHungerCard::CanReduce7, &CGhaltaPrimalHungerCard::CanReduce8,
		&CGhaltaPrimalHungerCard::CanReduce9, &CGhaltaPrimalHungerCard::CanReduce10 };

	for (int i = 0; i < 10; ++i)
	{
		CString strCost = CString(costs[i]) + GREEN_MANA_TEXT + GREEN_MANA_TEXT;
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Creature, strCost));

		cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
		AddPlayableIf(this, cpSpell.GetPointer(), conditions[i]);
		AddSpell(cpSpell.GetPointer());
	}
}

int CGhaltaPrimalHungerCard::TotalPower() const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	int nPower = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && (int)pCreature->GetPower() > 0)
			nPower += (int)pCreature->GetPower();
	}
	return nPower;
}

CGiltgroveStalkerCard::CGiltgroveStalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Giltgrove Stalker"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 2 or less.
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

CHardyVeteranCard::CHardyVeteranCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hardy Veteran"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// During your turn, this creature gets +0/+2.
	// Note: a trigger at the beginning of your upkeep gives +0/+2 until end of turn
	AddStepTrigger<CHardyVeteranCard>(this, NodeId::UpkeepStep, false, NULL, &CHardyVeteranCard::BeforePump);
}

bool CHardyVeteranCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +0, +2);
	return true;
}

CJadeBearerCard::CJadeBearerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jade Bearer"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, put a +1/+1 counter on another target Merfolk you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CJadeBearerCard::BeforeCounter, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CJadeBearerCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard);
	return false;
}

CJadecraftArtisanCard::CJadecraftArtisanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jadecraft Artisan"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, target creature gets +2/+2 until end of turn.
	AddEnterTargetTrigger(this, &CJadecraftArtisanCard::BeforePump, false, Characteristic::Positive);
}

bool CJadecraftArtisanCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +2, +2);
	return false;
}

CJadelightRangerCard::CJadelightRangerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jadelight Ranger"), CardType::Creature, CREATURE_TYPE3(Merfolk, Scout, Ranger), nID,
		_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(1))
	, m_Explore(this)
{
	// When this creature enters, it explores, then it explores again.
	m_Explore.AddExploreEnterAbility(CAbility::ResolutionStartedCallback(this, &CJadelightRangerCard::AfterExplore));
}

bool CJadelightRangerCard::AfterExplore(CAbilityAction* pAction)
{
	CExploreSupport::Explore(this);
	return true;
}

CJunglebornPioneerCard::CJunglebornPioneerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jungleborn Pioneer"), CardType::Creature, CREATURE_TYPE2(Merfolk, Scout), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, create a 1/1 blue Merfolk creature token with hexproof.
	AddEnterTrigger(this, &CJunglebornPioneerCard::BeforeToken);
}

bool CJunglebornPioneerCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), MERFOLK_A_TOKEN_NAME, MERFOLK_A_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CKnightOfTheStampedeCard::CKnightOfTheStampedeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of the Stampede"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(4))
{
	// Dinosaur spells you cast cost {2} less to cast.
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false),
			_T("2")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

COrazcaFrillbackCard::COrazcaFrillbackCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Orazca Frillback"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT, Power(4), Life(2))
{
}

COvergrownArmasaurCard::COvergrownArmasaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Overgrown Armasaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Enrage - Whenever this creature is dealt damage, create a 1/1 green Saproling creature token.
	AddEnrageTrigger(this, &COvergrownArmasaurCard::SetEnrageContext, &COvergrownArmasaurCard::BeforeToken);
}

bool COvergrownArmasaurCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool COvergrownArmasaurCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SAPROLING_TOKEN_NAME, SAPROLING_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSwiftWardenCard::CSwiftWardenCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swift Warden"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, target Merfolk you control gains hexproof until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CSwiftWardenCard::BeforeHexproof, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CSwiftWardenCard::BeforeHexproof(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		GainCardKeyword(pCard, CardKeyword::Hexproof);
	return false;
}

CTendershootDryadCard::CTendershootDryadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tendershoot Dryad"), CardType::Creature, CREATURE_TYPE(Dryad), nID,
		_T("4") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Ascend(this)
{
	// Ascend (CAscendSupport)

	{
		// At the beginning of each upkeep, create a 1/1 green Saproling creature token.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTendershootDryadCard::BeforeToken));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Saprolings you control get +2/+2 as long as you have the city's blessing.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Saproling), false), new CityBlessingComparer),
				Power(+2), Life(+2)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTendershootDryadCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SAPROLING_TOKEN_NAME, SAPROLING_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CThrashingBrontodonCard::CThrashingBrontodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thrashing Brontodon"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
{
	// {1}, Sacrifice this creature: Destroy target artifact or enchantment.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("1"),
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CWaywardSwordtoothCard::CWaywardSwordtoothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wayward Swordtooth"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT, Power(5), Life(5))
	, m_Ascend(this)
{
	// Ascend (CAscendSupport)

	{
		// You may play an additional land on each of your turns. (as Exploration)
		counted_ptr<CPlayExtraLandEnchantment> cpAbility(
			::CreateObject<CPlayExtraLandEnchantment>(this, +1));

		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// This creature can't attack or block unless you have the city's blessing.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new SpecificCardComparer(this), new NegateCardComparer(new CityBlessingComparer)),
				Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock));

		AddAbility(cpAbility.GetPointer());
	}
}

CWorldShaperCard::CWorldShaperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("World Shaper"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Whenever this creature attacks, you may mill three cards.
	AddSelfAttackTrigger(this, &CWorldShaperCard::BeforeMill, true);

	// When this creature dies, return all land cards from your graveyard to the battlefield tapped.
	AddDiesTrigger(this, &CWorldShaperCard::BeforeReturn);
}

bool CWorldShaperCard::BeforeMill(CAbilityAction* pAction)
{
	Mill(pAction->GetController(), 3);
	return true;
}

bool CWorldShaperCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer lands;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetCardType().IsLand())
			lands.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pMove = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController);
	CCardOrientationModifier pTap = CCardOrientationModifier(TRUE);
	for (int i = 0; i < lands.GetSize(); ++i)
	{
		CCard* pLand = lands.GetAt(i);
		pMove.ApplyTo(pLand);
		if (pLand->GetZoneId() == ZoneId::Battlefield)
			pTap.ApplyTo(pLand);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

#define ELEMENTAL_ZC_TOKEN_NAME	_T("Elemental (ZC)")
#define ELEMENTAL_ZC_TOKEN_ID	55108

CBrazenFreebooterCard::CBrazenFreebooterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brazen Freebooter"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, create a Treasure token.
	AddEnterTrigger(this, &CBrazenFreebooterCard::BeforeTreasure);
}

bool CBrazenFreebooterCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CChargingTuskodonCard::CChargingTuskodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charging Tuskodon"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// If this creature would deal combat damage to a player, it deals double that damage to that player instead.
	// Note: a trigger deals the same damage again after the combat damage (the damage in nValue1, the player in
	// nValue2)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CChargingTuskodonCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CChargingTuskodonCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CChargingTuskodonCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	int nDamage = -(int)damage.m_nLifeDelta;
	if (nDamage <= 0 || !pPlayer)
		return false;

	triggerContext.nValue1 = (DWORD)nDamage;
	triggerContext.nValue2 = (DWORD)pPlayer;
	return true;
}

bool CChargingTuskodonCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	int nDamage = (int)pAction->GetTriggerContext().nValue1;
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue2;
	if (pPlayer && nDamage > 0)
	{
		// (not combat damage, so that it doesn't trigger this ability again)
		CLifeModifier pModifier = CLifeModifier(Life(-nDamage), this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

CDaringBuccaneerCard::CDaringBuccaneerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Daring Buccaneer"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		RED_MANA_TEXT, Power(2), Life(2))
	, m_PirateFilter(_T("a Pirate card"), _T("Pirate cards"), new CreatureTypeComparer(CREATURE_TYPE(Pirate), false))
{
	// As an additional cost to cast this spell, reveal a Pirate card from your hand or pay {2}.
	// (the main spell reveals a Pirate card; a second spell costs {2}{R}, as Bone Picker in Amonkhet)
	GetSpells().GetAt(0)->GetCost().AddRevealCardCost(1, &m_PirateFilter);

	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("2") RED_MANA_TEXT, TRUE));
	cpSpell->SetMainSpell(FALSE);
	AddSpell(cpSpell.GetPointer());
}

CDireFleetDaredevilCard::CDireFleetDaredevilCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Daredevil"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature enters, exile target instant or sorcery card from an opponent's graveyard. You may cast it
	// this turn, and mana of any type can be spent to cast that spell. If that spell would be put into a graveyard,
	// exile it instead.
	// Not implemented: cards can't be cast from exile
}

CFanaticalFirebrandCard::CFanaticalFirebrandCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fanatical Firebrand"), CardType::Creature, CREATURE_TYPE2(Goblin, Pirate), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// {T}, Sacrifice this creature: It deals 1 damage to any target.
	// Note: it can't target planeswalkers
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			new AnyCreatureComparer, TRUE,
			Life(-1), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CForerunnerOfTheEmpireCard::CForerunnerOfTheEmpireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forerunner of the Empire"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("3") RED_MANA_TEXT, Power(1), Life(3))
	, m_DinosaurFilter(_T("a Dinosaur card"), _T("Dinosaur cards"), new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false))
{
	// When this creature enters, you may search your library for a Dinosaur card, reveal it, then shuffle and put that
	// card on top.
	AddEnterTrigger(this, &CForerunnerOfTheEmpireCard::BeforeSearch, true);

	// Whenever a Dinosaur you control enters, you may have this creature deal 1 damage to each creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CForerunnerOfTheEmpireCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CForerunnerOfTheEmpireCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToTop(GetGame(), pAction->GetController(), &m_DinosaurFilter);
	return true;
}

bool CForerunnerOfTheEmpireCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);
	return true;
}

CFrilledDeathspitterCard::CFrilledDeathspitterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frilled Deathspitter"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// Enrage - Whenever this creature is dealt damage, it deals 2 damage to target opponent or planeswalker.
	// Note: the opponent isn't targeted (two-player games), and it can't damage planeswalkers
	AddEnrageTrigger(this, &CFrilledDeathspitterCard::SetEnrageContext, &CFrilledDeathspitterCard::BeforeDamage);
}

bool CFrilledDeathspitterCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CFrilledDeathspitterCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	return true;
}

CGoblinTrailblazerCard::CGoblinTrailblazerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Trailblazer"), CardType::Creature, CREATURE_TYPE2(Goblin, Pirate), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CNeedletoothRaptorCard::CNeedletoothRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Needletooth Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(2))
{
	// Enrage - Whenever this creature is dealt damage, it deals 5 damage to target creature an opponent controls.
	CTargeting* pTargeting = AddEnrageTargetTrigger(this, &CNeedletoothRaptorCard::SetEnrageContext, &CNeedletoothRaptorCard::BeforeDamage, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CNeedletoothRaptorCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CNeedletoothRaptorCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		DealDamageToCreature(this, pCard, 5);
	return false;
}

COrazcaRaptorCard::COrazcaRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Orazca Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(4))
{
}

CRekindlingPhoenixCard::CRekindlingPhoenixCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rekindling Phoenix"), CardType::Creature, CREATURE_TYPE(Phoenix), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
{
	// When this creature dies, create a 0/1 red Elemental creature token with "At the beginning of your upkeep,
	// sacrifice this token and return target card named Rekindling Phoenix from your graveyard to the battlefield. It
	// gains haste until end of turn." (the token is Elemental (ZC) in Tokens2)
	AddDiesTrigger(this, &CRekindlingPhoenixCard::BeforeToken);
}

bool CRekindlingPhoenixCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ELEMENTAL_ZC_TOKEN_NAME, ELEMENTAL_ZC_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSilvercladFerocidonsCard::CSilvercladFerocidonsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Silverclad Ferocidons"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("5") RED_MANA_TEXT RED_MANA_TEXT, Power(8), Life(5))
{
	// Enrage - Whenever this creature is dealt damage, each opponent sacrifices a permanent of their choice.
	AddEnrageTrigger(this, &CSilvercladFerocidonsCard::SetEnrageContext, &CSilvercladFerocidonsCard::BeforeSacrifice);
}

bool CSilvercladFerocidonsCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CSilvercladFerocidonsCard::BeforeSacrifice(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pAction->GetController() || pPlayer->GetZoneById(ZoneId::Battlefield)->GetSize() == 0)
			continue;

		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Battlefield, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // a permanent
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			CCardFilter::GetFilter(_T("cards")), // what cards
			ZoneId::Graveyard, // if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top, // put selected cards on
			MoveType::Sacrifice, // move type
			CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

CStampedingHorncrestCard::CStampedingHorncrestCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stampeding Horncrest"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(4))
{
	// This creature has haste as long as you control another Dinosaur.
	AddAnotherTypeBonus(this, CREATURE_TYPE(Dinosaur), +0, CreatureKeyword::Haste);
}

CStormFleetSwashbucklerCard::CStormFleetSwashbucklerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storm Fleet Swashbuckler"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
	, m_Ascend(this)
{
	// Ascend. This creature has double strike as long as you have the city's blessing.
	AddBlessingBonus(this, +0, CreatureKeyword::DoubleStrike);
}

CSunCollaredRaptorCard::CSunCollaredRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sun-Collared Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(2))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// {2}{R}: This creature gets +3/+0 until end of turn.
	AddPumpAbility(this, _T("2") RED_MANA_TEXT, _T("This creature gets +3/+0 until end of turn. Activates"), &CSunCollaredRaptorCard::BeforePump);
}

bool CSunCollaredRaptorCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +3, +0);
	return true;
}

CSwabGoblinCard::CSwabGoblinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swab Goblin"), CardType::Creature, CREATURE_TYPE2(Goblin, Pirate), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
}

CSwaggeringCorsairCard::CSwaggeringCorsairCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swaggering Corsair"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Raid - This creature enters with a +1/+1 counter on it if you attacked this turn.
	// Note: the counter is put by a trigger when it enters (as Rigging Runner)
	AddEnterTrigger(this, &CSwaggeringCorsairCard::BeforeCounter);
}

bool CSwaggeringCorsairCard::BeforeCounter(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		AddPlusCounter(this);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (black creatures)

#define PREY_COUNTER	_T("prey counter")

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

//____________________________________________________________________________
//
// Black creatures

CAngrathsAmbusherCard::CAngrathsAmbusherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Angrath's Ambusher"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// This creature gets +2/+0 as long as you control an Angrath planeswalker.
	AddPlaneswalkerBonus(this, PlaneswalkerType::Angrath, +2, CreatureKeyword::Null);
}

CCanalMonitorCard::CCanalMonitorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Canal Monitor"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		_T("4") BLACK_MANA_TEXT, Power(5), Life(3))
{
}

CChampionOfDuskCard::CChampionOfDuskCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Champion of Dusk"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you draw X cards and you lose X life, where X is the number of Vampires you control.
	AddEnterTrigger(this, &CChampionOfDuskCard::BeforeDraw);
}

bool CChampionOfDuskCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = CountType(pController, CREATURE_TYPE(Vampire));
	if (nCount > 0)
	{
		DrawCards(GetGame(), pController, nCount);
		CLifeModifier pModifier = CLifeModifier(Life(-nCount), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pController);
	}
	return true;
}

CDinosaurHunterCard::CDinosaurHunterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dinosaur Hunter"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature deals damage to a Dinosaur, destroy that creature. (the creature in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDinosaurHunterCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDinosaurHunterCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CDinosaurHunterCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const
{
	if (!pCreature || !CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false)(pCreature))
		return false;

	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CDinosaurHunterCard::BeforeDestroy(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, GetController());
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CDireFleetPoisonerCard::CDireFleetPoisonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Poisoner"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Flash, deathtouch
	GetCardKeyword()->AddFlash(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);

	// When this creature enters, target attacking Pirate you control gets +1/+1 and gains deathtouch until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CDireFleetPoisonerCard::BeforePump, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CDireFleetPoisonerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		PumpCreature(pCard, +1, +1);
		GainCardKeyword(pCard, CardKeyword::Deathtouch);
	}
	return false;
}

CDuskChargerCard::CDuskChargerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dusk Charger"), CardType::Creature, CREATURE_TYPE(Horse), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_Ascend(this)
{
	// Ascend. This creature gets +2/+2 as long as you have the city's blessing.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new CityBlessingComparer),
			Power(+2), Life(+2)));

	AddAbility(cpAbility.GetPointer());
}

CDuskLegionZealotCard::CDuskLegionZealotCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dusk Legion Zealot"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, you draw a card and you lose 1 life.
	AddEnterTrigger(this, &CDuskLegionZealotCard::BeforeDraw);
}

bool CDuskLegionZealotCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CFathomFleetBoarderCard::CFathomFleetBoarderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fathom Fleet Boarder"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you lose 2 life unless you control another Pirate.
	AddEnterTrigger(this, &CFathomFleetBoarderCard::BeforeLoseLife);
}

bool CFathomFleetBoarderCard::BeforeLoseLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nPirates = CountType(pController, CREATURE_TYPE(Pirate));
	if (GetZoneId() == ZoneId::Battlefield && GetController() == pController)
		--nPirates;
	if (nPirates <= 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pController);
	}
	return true;
}

CForerunnerOfTheCoalitionCard::CForerunnerOfTheCoalitionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forerunner of the Coalition"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_PirateFilter(_T("a Pirate card"), _T("Pirate cards"), new CreatureTypeComparer(CREATURE_TYPE(Pirate), false))
{
	// When this creature enters, you may search your library for a Pirate card, reveal it, then shuffle and put that
	// card on top.
	AddEnterTrigger(this, &CForerunnerOfTheCoalitionCard::BeforeSearch, true);

	// Whenever another Pirate you control enters, each opponent loses 1 life.
	AddAnotherTypeEntersTrigger(this, CREATURE_TYPE(Pirate), FALSE, &CForerunnerOfTheCoalitionCard::BeforeDrain);
}

bool CForerunnerOfTheCoalitionCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToTop(GetGame(), pAction->GetController(), &m_PirateFilter);
	return true;
}

bool CForerunnerOfTheCoalitionCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, FALSE);
	return true;
}

CGraspingScoundrelCard::CGraspingScoundrelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grasping Scoundrel"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// This creature gets +1/+0 as long as it's attacking.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new AttackingCreatureComparer),
			Power(+1), Life(+0)));

	AddAbility(cpAbility.GetPointer());
}

CMausoleumHarpyCard::CMausoleumHarpyCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Mausoleum Harpy"), CardType::Creature, CREATURE_TYPE(Harpy), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_Ascend(this)
{
	// Ascend. Whenever another creature you control dies, if you have the city's blessing, put a +1/+1 counter on this
	// creature.
	AddAnotherCreatureDiesTrigger(this, &CMausoleumHarpyCard::SetTriggerContext, &CMausoleumHarpyCard::BeforeCounter);
}

bool CMausoleumHarpyCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard != this && GetController()->HasCityBlessing();
}

bool CMausoleumHarpyCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

COathswornVampireCard::COathswornVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oathsworn Vampire"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// This creature enters tapped.
	SetIntoPlayTapped();

	// You may cast this card from your graveyard if you gained life this turn. (a second spell, as the Aftermath halves)
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("1") BLACK_MANA_TEXT, TRUE));
	cpSpell->SetGraveyardOnly();
	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetAbilityText(_T("Oathsworn Vampire from your graveyard (you gained life this turn). Casts"));
	AddPlayableIf(this, cpSpell.GetPointer(), &COathswornVampireCard::GainedLifeThisTurn);
	AddSpell(cpSpell.GetPointer());
}

BOOL COathswornVampireCard::GainedLifeThisTurn(BOOL bIncludeTricks)
{
	return GetController()->GetLifeGainThisTurn() > Life(0);
}

CPitilessPlundererCard::CPitilessPlundererCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pitiless Plunderer"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") BLACK_MANA_TEXT, Power(1), Life(4))
{
	// Whenever another creature you control dies, create a Treasure token.
	AddAnotherCreatureDiesTrigger<CPitilessPlundererCard>(this, NULL, &CPitilessPlundererCard::BeforeTreasure);
}

bool CPitilessPlundererCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CRavenousChupacabraCard::CRavenousChupacabraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ravenous Chupacabra"), CardType::Creature, CREATURE_TYPE2(Beast, Horror), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, destroy target creature an opponent controls.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CRavenousChupacabraCard::BeforeDestroy, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CRavenousChupacabraCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CSadisticSkymarcherCard::CSadisticSkymarcherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sadistic Skymarcher"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_VampireFilter(_T("a Vampire card"), _T("Vampire cards"), new CreatureTypeComparer(CREATURE_TYPE(Vampire), false))
{
	// Flying, lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// As an additional cost to cast this spell, reveal a Vampire card from your hand or pay {1}.
	// (as Daring Buccaneer)
	GetSpells().GetAt(0)->GetCost().AddRevealCardCost(1, &m_VampireFilter);

	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3") BLACK_MANA_TEXT, TRUE));
	cpSpell->SetMainSpell(FALSE);
	AddSpell(cpSpell.GetPointer());
}

CTetzimocPrimalDeathCard::CTetzimocPrimalDeathCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tetzimoc, Primal Death"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dinosaur), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(6))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	{
		// {B}, Reveal this card from your hand: Put a prey counter on target creature. Activate only during your turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->SetPlayableFrom(ZoneId::Hand);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(PREY_COUNTER, +1));
		cpAbility->SetAbilityText(_T("Reveal Tetzimoc: put a prey counter on target creature. Activates"));
		AddPlayableIf(this, cpAbility.GetPointer(), &CTetzimocPrimalDeathCard::IsYourTurn);
		AddAbility(cpAbility.GetPointer());
	}

	// When Tetzimoc enters, destroy each creature your opponents control with a prey counter on it.
	AddEnterTrigger(this, &CTetzimocPrimalDeathCard::BeforeDestroy);
}

BOOL CTetzimocPrimalDeathCard::IsYourTurn(BOOL bIncludeTricks)
{
	return GetGame()->GetActivePlayer() == GetController();
}

bool CTetzimocPrimalDeathCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (CountCounters(creatures.GetAt(i), PREY_COUNTER) > 0)
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CTombRobberCard::CTombRobberCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tomb Robber"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// {1}, Discard a card: This creature explores.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetAbilityText(_T("This creature explores. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTombRobberCard::BeforeExplore));
	AddAbility(cpAbility.GetPointer());
}

bool CTombRobberCard::BeforeExplore(CAbilityAction* pAction)
{
	CExploreSupport::Explore(this);
	return true;
}

CTwilightProphetCard::CTwilightProphetCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Twilight Prophet"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(4))
	, m_Ascend(this)
{
	// Ascend. At the beginning of your upkeep, if you have the city's blessing, reveal the top card of your library and
	// put it into your hand. Each opponent loses X life and you gain X life, where X is that card's mana value.
	AddStepTrigger(this, NodeId::UpkeepStep, false, &CTwilightProphetCard::SetTriggerContext, &CTwilightProphetCard::BeforeReveal);
}

bool CTwilightProphetCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetController()->HasCityBlessing() == TRUE;
}

bool CTwilightProphetCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	int nManaValue = (int)pCard->GetConvertedManaCost();
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others);
	pModifier.ApplyTo(pCard);

	DrainOpponents(this, pController, nManaValue, TRUE);
	return true;
}

CVampireChampionCard::CVampireChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vampire Champion"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);
}

CVampireRevenantCard::CVampireRevenantCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vampire Revenant"), CardType::Creature, CREATURE_TYPE2(Vampire, Spirit), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(1))
{
}

CVoraciousVampireCard::CVoraciousVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Voracious Vampire"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When this creature enters, target Vampire you control gets +1/+1 and gains menace until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CVoraciousVampireCard::BeforePump, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CVoraciousVampireCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +1, +1, CreatureKeyword::CantBeBlockedBy1);
	return false;
}

CVraskasConquistadorCard::CVraskasConquistadorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vraska's Conquistador"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks or blocks, if you control a Vraska planeswalker, target opponent loses 2 life and
	// you gain 2 life.
	// Note: the opponent isn't targeted (two-player games) and the condition is checked on resolution
	AddSelfAttackTrigger(this, &CVraskasConquistadorCard::BeforeDrain);

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVraskasConquistadorCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CVraskasConquistadorCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCardFilter vraska(_T("a Vraska planeswalker"), _T("Vraska planeswalkers"), new PlaneswalkerTypeComparer(PlaneswalkerType::Vraska));
	if (vraska.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
		DrainOpponents(this, pController, 2, TRUE);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

CDeadeyeRigHaulerCard::CDeadeyeRigHaulerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Rig-Hauler"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// Raid - When this creature enters, if you attacked this turn, you may return target creature to its owner's hand.
	// Note: the condition is checked on resolution
	AddEnterTargetTrigger(this, &CDeadeyeRigHaulerCard::BeforeReturn, true, Characteristic::Negative);
}

bool CDeadeyeRigHaulerCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (HasRaid(pAction->GetController()) && pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CKitesailCorsairCard::CKitesailCorsairCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kitesail Corsair"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// This creature has flying as long as it's attacking.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new AttackingCreatureComparer),
			Power(+0), Life(+0), CreatureKeyword::Flying));

	AddAbility(cpAbility.GetPointer());
}

CMistCloakedHeraldCard::CMistCloakedHeraldCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mist-Cloaked Herald"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
{
	// This creature can't be blocked.
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

CNezahalPrimalTideCard::CNezahalPrimalTideCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nezahal, Primal Tide"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dinosaur), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(7), Life(7))
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	{
		// You have no maximum hand size.
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::NoMaximumHandSize));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever an opponent casts a noncreature spell, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Discard three cards: Exile Nezahal. Return it to the battlefield tapped under its owner's control at the
		// beginning of the next end step.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddDiscardCardCost(3, CCardFilter::GetFilter(_T("cards")));
		cpAbility->SetAbilityText(_T("Exile Nezahal until the next end step. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNezahalPrimalTideCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
}

// (the return as Long Road Home in Amonkhet)
bool CNezahalPrimalTideCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pExile.ApplyTo(this);
	if (GetZoneId() != ZoneId::Exile)
		return true;

	CMoveCardModifier* pReturn = new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others);
	pReturn->SetTapped(TRUE);
	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(), pReturn,
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(this);
	return true;
}

CRiverDarterCard::CRiverDarterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("River Darter"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_BlockerFilter(_T("a non-Dinosaur creature"), _T("non-Dinosaur creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false))))
{
	// This creature can't be blocked by Dinosaurs.
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

CRiverwiseAugurCard::CRiverwiseAugurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Riverwise Augur"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, draw three cards, then put two cards from your hand on top of your library in any
	// order.
	AddEnterTrigger(this, &CRiverwiseAugurCard::BeforeDraw);
}

bool CRiverwiseAugurCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 3);

	int nCount = pController->GetZoneById(ZoneId::Hand)->GetSize();
	if (nCount > 2)
		nCount = 2;
	if (nCount <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(nCount), MaximumValue(nCount), // two cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Library, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);
	return true;
}

CSeafloorOracleCard::CSeafloorOracleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Seafloor Oracle"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// Whenever a Merfolk you control deals combat damage to a player, draw a card. (as Stensia Masquerade)
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenDamageDealt,
						   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
	cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

CSirenReaverCard::CSirenReaverCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Siren Reaver"), CardType::Creature, CREATURE_TYPE2(Siren, Pirate), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// Raid - This spell costs {1} less to cast if you attacked this turn. (a second spell, as Bone Picker in Amonkhet)
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("2") BLUE_MANA_TEXT, TRUE));
	cpSpell->SetMainSpell(FALSE);
	AddPlayableIf(this, cpSpell.GetPointer(), &CSirenReaverCard::HasRaidCondition);
	AddSpell(cpSpell.GetPointer());
}

BOOL CSirenReaverCard::HasRaidCondition(BOOL bIncludeTricks)
{
	return HasRaid(GetController());
}

CSlipperyScoundrelCard::CSlipperyScoundrelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Slippery Scoundrel"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_Ascend(this)
{
	// Ascend. As long as you have the city's blessing, this creature has hexproof and can't be blocked.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new CityBlessingComparer),
			Power(+0), Life(+0), CreatureKeyword::Unblockable));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	AddAbility(cpAbility.GetPointer());
}

CSoulOfTheRapidsCard::CSoulOfTheRapidsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Soul of the Rapids"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);
}

CSpireWinderCard::CSpireWinderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spire Winder"), CardType::Creature, CREATURE_TYPE(Snake), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_Ascend(this)
{
	// Ascend. This creature gets +1/+1 as long as you have the city's blessing.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new CityBlessingComparer),
			Power(+1), Life(+1)));

	AddAbility(cpAbility.GetPointer());
}

CSwornGuardianCard::CSwornGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sworn Guardian"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
}

CTimestreamNavigatorCard::CTimestreamNavigatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Timestream Navigator"), CardType::Creature, CREATURE_TYPE3(Human, Pirate, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(1))
	, m_Ascend(this)
{
	// Ascend. {2}{U}{U}, {T}, Put this creature on the bottom of its owner's library: Take an extra turn after this
	// one. Activate only if you have the city's blessing. (as Gonti's Aether Heart in Aether Revolt)
	// Note: the creature is put on the bottom of the library on resolution
	counted_ptr<CActivatedAbility<CPlayerEffectSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CPlayerEffectSpell>>(this,
			_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlayerEffectType::TimeWalk, FALSE, 1));

	cpAbility->SetAffectControllerOnly();
	cpAbility->AddTapCost();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTimestreamNavigatorCard::BeforeExtraTurn));
	AddPlayableIf(this, cpAbility.GetPointer(), &CTimestreamNavigatorCard::HasBlessing);
	AddAbility(cpAbility.GetPointer());
}

BOOL CTimestreamNavigatorCard::HasBlessing(BOOL bIncludeTricks)
{
	return GetController()->HasCityBlessing();
}

bool CTimestreamNavigatorCard::BeforeExtraTurn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetToTop(FALSE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CWarkiteMarauderCard::CWarkiteMarauderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Warkite Marauder"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks, target creature defending player controls loses all abilities and has base power
	// and toughness 0/1 until end of turn.
	// Partial: the creature becomes 0/1 until end of turn (a -X/-Y change), but it doesn't lose its abilities
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CWarkiteMarauderCard::BeforeShrink, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CWarkiteMarauderCard::BeforeShrink(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return false;

	PumpCreature(pCreature, 0 - (int)pCreature->GetPower(), 1 - (int)pCreature->GetToughness());
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored creatures

CAtzocanSeerCard::CAtzocanSeerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Atzocan Seer"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
{
	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);

	// Sacrifice this creature: Return target Dinosaur card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false),
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CAzorTheLawbringerCard::CAzorTheLawbringerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Azor, the Lawbringer"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Sphinx), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(6), Life(6))
{
	// When Azor enters, each opponent can't cast instant or sorcery spells during that player's next turn.
	// (as Sphinx's Decree)
	AddEnterTrigger(this, &CAzorTheLawbringerCard::BeforeDecree);

	// Whenever Azor attacks, you may pay {X}{W}{U}{U}. If you do, you gain X life and draw X cards.
	// Not implemented: a triggered ability can't ask for a cost with X
}

bool CAzorTheLawbringerCard::BeforeDecree(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CScheduledPlayerModifier pApply = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, (int)CCardFilter::GetFilter(_T("instant cards or sorcery cards"))),
			TurnNumberDelta(-1), NodeId::UpkeepStep, CScheduledPlayerModifier::Operation::ApplyToLater,
			CScheduledPlayerModifier::DeltaOption::CustomPlayerTurn, pPlayer);
		pApply.ApplyTo(pPlayer);

		CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, (int)CCardFilter::GetFilter(_T("instant cards or sorcery cards"))),
			TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater,
			CScheduledPlayerModifier::DeltaOption::CustomPlayerTurn, pPlayer);
		pRemove.ApplyTo(pPlayer);
	}
	return true;
}

CDeadeyeBrawlerCard::CDeadeyeBrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Brawler"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(4))
	, m_Ascend(this)
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Ascend. Whenever this creature deals combat damage to a player, if you have the city's blessing, draw a card.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDeadeyeBrawlerCard::SetDamageContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeadeyeBrawlerCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CDeadeyeBrawlerCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	return GetController()->HasCityBlessing() == TRUE;
}

bool CDeadeyeBrawlerCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDireFleetNeckbreakerCard::CDireFleetNeckbreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Neckbreaker"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(2))
{
	// Attacking Pirates you control get +2/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false), new AttackingCreatureComparer),
			Power(+2), Life(+0)));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CElendaTheDuskRoseCard::CElendaTheDuskRoseCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elenda, the Dusk Rose"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	{
		// Whenever another creature dies, put a +1/+1 counter on Elenda.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CElendaTheDuskRoseCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CElendaTheDuskRoseCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// When Elenda dies, create X 1/1 white Vampire creature tokens with lifelink, where X is Elenda's power.
	AddDiesTrigger(this, &CElendaTheDuskRoseCard::BeforeTokens);
}

bool CElendaTheDuskRoseCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard != this;
}

bool CElendaTheDuskRoseCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

bool CElendaTheDuskRoseCard::BeforeTokens(CAbilityAction* pAction)
{
	int nPower = (int)GetLastKnownPower();
	if (nPower > 0)
		CreateVampire(GetGame(), pAction->GetController(), nPower);
	return true;
}

CJungleCreeperCard::CJungleCreeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jungle Creeper"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// {3}{B}{G}: Return this card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJungleCreeperCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CJungleCreeperCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(this);
	}
	return true;
}

CKumenaTyrantOfOrazcaCard::CKumenaTyrantOfOrazcaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kumena, Tyrant of Orazca"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(4))
	, m_OtherMerfolkFilter(_T("another untapped Merfolk you control"), _T("other untapped Merfolk you control"),
		new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false), new NegateCardComparer(new SpecificCardComparer(this))))
	, m_MerfolkFilter(_T("an untapped Merfolk you control"), _T("untapped Merfolk you control"),
		new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false))
{
	{
		// Tap another untapped Merfolk you control: Kumena can't be blocked this turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddTapCardCost(1, &m_OtherMerfolkFilter);
		cpAbility->SetAbilityText(_T("Kumena can't be blocked this turn. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKumenaTyrantOfOrazcaCard::BeforeUnblockable));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Tap three untapped Merfolk you control: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T(""), 1));

		cpAbility->GetCost().AddTapCardCost(3, &m_MerfolkFilter);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Tap five untapped Merfolk you control: Put a +1/+1 counter on each Merfolk you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddTapCardCost(5, &m_MerfolkFilter);
		cpAbility->SetAbilityText(_T("Put a +1/+1 counter on each Merfolk you control. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKumenaTyrantOfOrazcaCard::BeforeCounters));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKumenaTyrantOfOrazcaCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

bool CKumenaTyrantOfOrazcaCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CreatureTypeComparer merfolk(CREATURE_TYPE(Merfolk), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (merfolk(creatures.GetAt(i)))
			AddPlusCounter(creatures.GetAt(i));
	return true;
}

CLegionLieutenantCard::CLegionLieutenantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Legion Lieutenant"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Other Vampires you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Vampire), +1, CreatureKeyword::Null);
}

CMerfolkMistbinderCard::CMerfolkMistbinderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merfolk Mistbinder"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Other Merfolk you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Merfolk), +1, CreatureKeyword::Null);
}

CRagingRegisaurCard::CRagingRegisaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Raging Regisaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Whenever this creature attacks, it deals 1 damage to any target.
	// Note: it can't target planeswalkers
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CRagingRegisaurCard::BeforeDamage, Characteristic::Negative);
	pTargeting->SetIncludePlayers(TRUE);
}

bool CRagingRegisaurCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 1);
	return false;
}

CRelentlessRaptorCard::CRelentlessRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Relentless Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// This creature attacks or blocks each combat if able.
	// Partial: it attacks each combat if able (there is no "must block")
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);
}

CResplendentGriffinCard::CResplendentGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Resplendent Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
	, m_Ascend(this)
{
	// Ascend. Whenever this creature attacks, if you have the city's blessing, put a +1/+1 counter on it.
	// Note: the condition is checked on resolution
	AddSelfAttackTrigger(this, &CResplendentGriffinCard::BeforeCounter);
}

bool CResplendentGriffinCard::BeforeCounter(CAbilityAction* pAction)
{
	if (pAction->GetController()->HasCityBlessing())
		AddPlusCounter(this);
	return true;
}

CSiegehornCeratopsCard::CSiegehornCeratopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Siegehorn Ceratops"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Enrage - Whenever this creature is dealt damage, put two +1/+1 counters on it.
	AddEnrageTrigger(this, &CSiegehornCeratopsCard::SetEnrageContext, &CSiegehornCeratopsCard::BeforeCounters);
}

bool CSiegehornCeratopsCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature == this;
}

bool CSiegehornCeratopsCard::BeforeCounters(CAbilityAction* pAction)
{
	AddPlusCounter(this, 2);
	return true;
}

CStormFleetSprinterCard::CStormFleetSprinterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storm Fleet Sprinter"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Haste. This creature can't be blocked.
	GetCreatureKeyword()->AddHaste(FALSE);
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

CZacamaPrimalCalamityCard::CZacamaPrimalCalamityCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Zacama, Primal Calamity"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dinosaur), nID,
		_T("6") RED_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(9), Life(9))
{
	// Reach, vigilance, trample
	GetCreatureKeyword()->AddReach(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// When Zacama enters, if you cast it, untap all lands you control.
	// Note: it also untaps the lands if it enters without being cast
	AddEnterTrigger(this, &CZacamaPrimalCalamityCard::BeforeUntap);

	{
		// {2}{R}: Zacama deals 3 damage to target creature.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-3), PreventableType::Preventable));

		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{G}: Destroy target artifact or enchantment.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("2") GREEN_MANA_TEXT,
				new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{W}: You gain 3 life.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") WHITE_MANA_TEXT));

		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CLifeModifier(Life(+3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
		cpAbility->SetAbilityText(_T("You gain 3 life. Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CZacamaPrimalCalamityCard::BeforeUntap(CAbilityAction* pAction)
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsLand())
			pModifier.ApplyTo(pBattlefield->GetAt(i));
	return true;
}

//____________________________________________________________________________
//
