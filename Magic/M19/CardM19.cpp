#include "stdafx.h"
#include "CardM19.h"

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
#define SAGA_CHAPTER(n, C, f)	m_Saga.AddChapter(n, CAbility::ResolutionStartedCallback(this, &C::f))
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
#define SOLDIER_O_TOKEN_NAME	_T("Soldier (O)")
#define SOLDIER_O_TOKEN_ID		62060
#define SILVER_COUNTER		_T("silver counter")
#define CONSTRUCT_C_TOKEN_NAME	_T("Construct (C)")
#define CONSTRUCT_C_TOKEN_ID	55109
#define TEFERI_HERO_EFFECT_NAME	_T("Teferi, Hero of Dominaria Effect")
#define TEFERI_HERO_EFFECT_ID	61153
#define TEFERI_HERO_EMBLEM_NAME	_T("Teferi, Hero of Dominaria Emblem")
#define TEFERI_HERO_EMBLEM_ID	61154
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
#define WEATHERLIGHT_VEHICLE_NAME	_T("Weatherlight (Vehicle)")
#define WEATHERLIGHT_VEHICLE_ID		64129
#define ELEMENTAL_AX_TOKEN_NAME	_T("Elemental (AX)")
#define ELEMENTAL_AX_TOKEN_ID	64130
#define ELEMENTAL_Y_TOKEN_NAME		_T("Elemental (Y)")
#define ELEMENTAL_Y_TOKEN_ID		55063
#define KAROX_BLADEWING_TOKEN_NAME	_T("Karox Bladewing")
#define KAROX_BLADEWING_TOKEN_ID	55113
#define ZOMBIE_KNIGHT_TOKEN_NAME	_T("Zombie Knight")
#define ZOMBIE_KNIGHT_TOKEN_ID		55114
#define KNIGHT_E_TOKEN_NAME		_T("Knight (E)")
#define KNIGHT_E_TOKEN_ID		55046

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

//____________________________________________________________________________
//
counted_ptr<CCard> CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID)
{
	counted_ptr<CCard> cpCard;
	do
	{
		DEFINE_CARD(CNicolBolasTheRavagerCard);
		DEFINE_CARD(CNicolBolasTheArisenCard);
		DEFINE_CARD(CDetectionTowerCard);
		DEFINE_CARD(CAjaniAdversaryOfTyrantsCard);
		DEFINE_CARD(CAjaniWiseCounselorCard);
		DEFINE_CARD(CLilianaTheNecromancerCard);
		DEFINE_CARD(CLilianaUntouchedByDeathCard);
		DEFINE_CARD(CSarkhanDragonsoulCard);
		DEFINE_CARD(CSarkhanFirebloodCard);
		DEFINE_CARD(CTezzeretArtificeMasterCard);
		DEFINE_CARD(CTezzeretCruelMachinistCard);
		DEFINE_CARD(CVivienOfTheArkbowCard);
		DEFINE_CARD(CVivienReidCard);
		DEFINE_CARD(CAetherTunnelCard);
		DEFINE_CARD(CAjanisLastStandCard);
		DEFINE_CARD(CAjanisWelcomeCard);
		DEFINE_CARD(CColossalMajestyCard);
		DEFINE_CARD(CDwindleCard);
		DEFINE_CARD(CGiftOfParadiseCard);
		DEFINE_CARD(CHieromancersCageCard);
		DEFINE_CARD(CInfernalScarringCard);
		DEFINE_CARD(CKnightsPledgeCard);
		DEFINE_CARD(CLilianasContractCard);
		DEFINE_CARD(COpenTheGravesCard);
		DEFINE_CARD(CPatientRebuildingCard);
		DEFINE_CARD(CProdigiousGrowthCard);
		DEFINE_CARD(CPsychicCorrosionCard);
		DEFINE_CARD(CSarkhansUnsealingCard);
		DEFINE_CARD(CTalonsOfWildwoodCard);
		DEFINE_CARD(CAmuletOfSafekeepingCard);
		DEFINE_CARD(CArcaneEncyclopediaCard);
		DEFINE_CARD(CDesecratedTombCard);
		DEFINE_CARD(CDragonsHoardCard);
		DEFINE_CARD(CFountainOfRenewalCard);
		DEFINE_CARD(CMaraudersAxeCard);
		DEFINE_CARD(CRoguesGlovesCard);
		DEFINE_CARD(CSigiledSwordOfValeronCard);
		DEFINE_CARD(CTezzeretsGatebreakerCard);
		DEFINE_CARD(CTransmogrifyingWandCard);
		DEFINE_CARD(CAjanisInfluenceCard);
		DEFINE_CARD(CBloodDivinationCard);
		DEFINE_CARD(CCleansingNovaCard);
		DEFINE_CARD(CDeclareDominanceCard);
		DEFINE_CARD(CFieryFinishCard);
		DEFINE_CARD(CFrayingOmnipotenceCard);
		DEFINE_CARD(CHeroicReinforcementsCard);
		DEFINE_CARD(CLichsCaressCard);
		DEFINE_CARD(CLilianasSpoilsCard);
		DEFINE_CARD(COneWithTheMachineCard);
		DEFINE_CARD(CSarkhansDragonfireCard);
		DEFINE_CARD(CSovereignsBiteCard);
		DEFINE_CARD(CTakeVengeanceCard);
		DEFINE_CARD(CThudCard);
		DEFINE_CARD(CViviensInvocationCard);
		DEFINE_CARD(CAbnormalEnduranceCard);
		DEFINE_CARD(CAegisOfTheHeavensCard);
		DEFINE_CARD(CInfernalReckoningCard);
		DEFINE_CARD(CIsolateCard);
		DEFINE_CARD(CNexusOfFateCard);
		DEFINE_CARD(CNightmaresThirstCard);
		DEFINE_CARD(CRevitalizeCard);
		DEFINE_CARD(CRootSnareCard);
		DEFINE_CARD(CSpitFlameCard);
		DEFINE_CARD(CStranglingSporesCard);
		DEFINE_CARD(CUncomfortableChillCard);
		DEFINE_CARD(CAethershieldArtificerCard);
		DEFINE_CARD(CAngelOfTheDawnCard);
		DEFINE_CARD(CCavalryDrillmasterCard);
		DEFINE_CARD(CCourtClericCard);
		DEFINE_CARD(CDaybreakChaplainCard);
		DEFINE_CARD(CDwarvenPriestCard);
		DEFINE_CARD(CGallantCavalryCard);
		DEFINE_CARD(CHeraldOfFaithCard);
		DEFINE_CARD(CKnightOfTheTuskCard);
		DEFINE_CARD(CLenaSelflessChampionCard);
		DEFINE_CARD(CLeoninVanguardCard);
		DEFINE_CARD(CLeoninWarleaderCard);
		DEFINE_CARD(CLoxodonLineBreakerCard);
		DEFINE_CARD(CMilitiaBuglerCard);
		DEFINE_CARD(CNoviceKnightCard);
		DEFINE_CARD(CRemorsefulClericCard);
		DEFINE_CARD(CResplendentAngelCard);
		DEFINE_CARD(CRustwingFalconCard);
		DEFINE_CARD(CSerrasGuardianCard);
		DEFINE_CARD(CShieldMareCard);
		DEFINE_CARD(CSilverbeakGriffinCard);
		DEFINE_CARD(CStarCrownedStagCard);
		DEFINE_CARD(CTrustyPackbeastCard);
		DEFINE_CARD(CValiantKnightCard);
		DEFINE_CARD(CAggressiveMammothCard);
		DEFINE_CARD(CBristlingBoarCard);
		DEFINE_CARD(CDruidOfHornsCard);
		DEFINE_CARD(CDryadGreenseekerCard);
		DEFINE_CARD(CElvishClancallerCard);
		DEFINE_CARD(CElvishRejuvenatorCard);
		DEFINE_CARD(CGhastbarkTwinsCard);
		DEFINE_CARD(CGigantosaurusCard);
		DEFINE_CARD(CGoreclawTerrorOfQalSismaCard);
		DEFINE_CARD(CGreenwoodSentinelCard);
		DEFINE_CARD(CRhoxOracleCard);
		DEFINE_CARD(CSkallaWolfCard);
		DEFINE_CARD(CThornLieutenantCard);
		DEFINE_CARD(CUrsineChampionCard);
		DEFINE_CARD(CVigilantBalothCard);
		DEFINE_CARD(CVineMareCard);
		DEFINE_CARD(CViviensJaguarCard);
		DEFINE_CARD(CCatalystElementalCard);
		DEFINE_CARD(CDemandingDragonCard);
		DEFINE_CARD(CDismissivePyromancerCard);
		DEFINE_CARD(CGoblinInstigatorCard);
		DEFINE_CARD(CGoblinMotivatorCard);
		DEFINE_CARD(CGoblinTrashmasterCard);
		DEFINE_CARD(CHavocDevilsCard);
		DEFINE_CARD(CHostileMinotaurCard);
		DEFINE_CARD(CInfernoHellionCard);
		DEFINE_CARD(CKarganDragonriderCard);
		DEFINE_CARD(CLathlissDragonQueenCard);
		DEFINE_CARD(CLightningMareCard);
		DEFINE_CARD(COnakkeOgreCard);
		DEFINE_CARD(CSarkhansWhelpCard);
		DEFINE_CARD(CSiegebreakerGiantCard);
		DEFINE_CARD(CSparktongueDragonCard);
		DEFINE_CARD(CViashinoPyromancerCard);
		DEFINE_CARD(CVolleyVeteranCard);
		DEFINE_CARD(CArisenGorgonCard);
		DEFINE_CARD(CBogstomperCard);
		DEFINE_CARD(CBoneDragonCard);
		DEFINE_CARD(CDemonOfCatastrophesCard);
		DEFINE_CARD(CEpicureOfBloodCard);
		DEFINE_CARD(CFellSpecterCard);
		DEFINE_CARD(CGravewakerCard);
		DEFINE_CARD(CGraveyardMarshalCard);
		DEFINE_CARD(CHiredBladeCard);
		DEFINE_CARD(CIsarethTheAwakenerCard);
		DEFINE_CARD(CPlagueMareCard);
		DEFINE_CARD(CRavenousHarpyCard);
		DEFINE_CARD(CSkeletonArcherCard);
		DEFINE_CARD(CStitchersSupplierCard);
		DEFINE_CARD(CTwoHeadedZombieCard);
		DEFINE_CARD(CVampireNeonateCard);
		DEFINE_CARD(CVampireSovereignCard);
		DEFINE_CARD(CAvenWindMageCard);
		DEFINE_CARD(CAviationPioneerCard);
		DEFINE_CARD(CDepartedDeckhandCard);
		DEFINE_CARD(CExclusionMageCard);
		DEFINE_CARD(CFrilledSeaSerpentCard);
		DEFINE_CARD(CGearsmithProdigyCard);
		DEFINE_CARD(CMysticArchaeologistCard);
		DEFINE_CARD(CRiddlemasterSphinxCard);
		DEFINE_CARD(CSaiMasterThopteristCard);
		DEFINE_CARD(CSalvagerOfSecretsCard);
		DEFINE_CARD(CScholarOfStarsCard);
		DEFINE_CARD(CSkilledAnimatorCard);
		DEFINE_CARD(CSupremePhantomCard);
		DEFINE_CARD(CSurgeMareCard);
		DEFINE_CARD(CWallOfMistCard);
		DEFINE_CARD(CAerialEngineerCard);
		DEFINE_CARD(CArcadesTheStrategistCard);
		DEFINE_CARD(CBrawlBashOgreCard);
		DEFINE_CARD(CChromiumTheMutableCard);
		DEFINE_CARD(CDiamondMareCard);
		DEFINE_CARD(CDraconicDiscipleCard);
		DEFINE_CARD(CGearsmithGuardianCard);
		DEFINE_CARD(CMeteorGolemCard);
		DEFINE_CARD(CPalladiaMorsTheRuinerCard);
		DEFINE_CARD(CPoisonTipArcherCard);
		DEFINE_CARD(CPsychicSymbiontCard);
		DEFINE_CARD(CRegalBloodlordCard);
		DEFINE_CARD(CSatyrEnchanterCard);
		DEFINE_CARD(CSkyriderPatrolCard);
		DEFINE_CARD(CSkyscannerCard);
		DEFINE_CARD(CSuspiciousBookcaseCard);
		DEFINE_CARD(CTezzeretsStriderCard);
		DEFINE_CARD(CVaevictisAsmadiTheDireCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Creatures that transform into a planeswalker (CPlaneswalkerTransformCreatureCard, in the core)

CNicolBolasTheRavagerCard::CNicolBolasTheRavagerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerTransformCreatureCard(pGame, _T("Nicol Bolas, the Ravager"), CardType::Creature | CardType::Legendary,
		CREATURE_TYPE2(Elder, Dragon), nID,
		_T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4), _T("Nicol Bolas, the Arisen"))
{
	// Flying
	GetCreatureKeyword()->AddFlying(FALSE);

	// When Nicol Bolas enters, each opponent discards a card.
	AddEnterTrigger(this, &CNicolBolasTheRavagerCard::BeforeDiscard);

	// {4}{U}{B}{R}: Exile Nicol Bolas, then return him to the battlefield transformed under his owner's control.
	// Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT));

	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->SetAbilityText(_T("Transform into Nicol Bolas, the Arisen. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasTheRavagerCard::BeforeTransform));
	AddAbility(cpAbility.GetPointer());
}

bool CNicolBolasTheRavagerCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

bool CNicolBolasTheRavagerCard::BeforeTransform(CAbilityAction* pAction)
{
	ExileAndReturnTransformed(pAction->GetController());
	return true;
}

CNicolBolasTheArisenCard::CNicolBolasTheArisenCard(CGame* pGame, UINT nID)
	: CTransformedPlaneswalkerCard(pGame, _T("Nicol Bolas, the Arisen"), nID, PlaneswalkerType::Bolas, 7,
		CardType::Blue | CardType::Black | CardType::Red)
{
	// +2: Draw two cards.
	AddLoyaltyAbility(this, +2, _T("+2: Draw two cards. Activates"), &CNicolBolasTheArisenCard::BeforeDraw);

	{
		// -3: Nicol Bolas deals 10 damage to target creature or planeswalker.
		// (the damage to a planeswalker removes loyalty counters)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasTheArisenCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -4: Put target creature or planeswalker card from a graveyard onto the battlefield under your control.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
				ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -4);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}

	// -12: Exile all but the bottom card of target player's library.
	AddPlayerLoyaltyAbility(this, -12, &CNicolBolasTheArisenCard::BeforeExile);
}

bool CNicolBolasTheArisenCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	return true;
}

bool CNicolBolasTheArisenCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	if (pCard->GetCardType().IsCreature())
		DealDamageToCreature(this, pCard, 10);
	else
		CCardCounterModifier(LOYALTY_COUNTER, -10).ApplyTo(pCard);
	return false;
}

// (the bottom card of the library is the first one)
bool CNicolBolasTheArisenCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others);
	while (pLibrary->GetSize() > 1)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

CDetectionTowerCard::CDetectionTowerCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Detection Tower"), nID)
{
	// {T}: Add {C}.
	AddTapManaAbility(this, _T("1"));

	// {1}, {T}: Until end of turn, your opponents and creatures your opponents control with hexproof can be the targets
	// of spells and abilities you control as though they didn't have hexproof. (as Glaring Spotlight in Gatecrash, until
	// end of turn)
	// Partial: only the creatures (the hexproof of the players isn't ignored)
	counted_ptr<CActivatedAbility<CPlayerEffectSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CPlayerEffectSpell>>(this,
			_T("1"), PlayerEffectType::IgnoreHexproofOnCreatures, TRUE));

	cpAbility->SetAffectControllerOnly();
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

#define AJANI_ADVERSARY_EMBLEM_NAME		_T("Ajani, Adversary of Tyrants Emblem")
#define AJANI_ADVERSARY_EMBLEM_ID		61155
#define TEZZERET_ARTIFICE_EMBLEM_NAME	_T("Tezzeret, Artifice Master Emblem")
#define TEZZERET_ARTIFICE_EMBLEM_ID		61156
#define VIVIEN_REID_EMBLEM_NAME			_T("Vivien Reid Emblem")
#define VIVIEN_REID_EMBLEM_ID			61157
#define THOPTER_D_TOKEN_NAME			_T("Thopter (D)")
#define THOPTER_D_TOKEN_ID				55053
#define DRAGON_J_TOKEN_NAME				_T("Dragon (J)")
#define DRAGON_J_TOKEN_ID				55062

// "<N>: You get an emblem with <text>"
static void AddEmblemLoyaltyAbility(CPlaneswalkerCard* pCard, int nLoyalty, LPCTSTR strName, UINT uID, LPCTSTR strText)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("")));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(pCard->GetGame(), strName, uID, 1, FALSE, ZoneId::_Effects));
	cpAbility->SetAbilityText(strText);
	pCard->AddAbility(cpAbility.GetPointer());
}

// "<N>: Put <n> +1/+1 counters on each of up to <nMax> target creatures"
static void AddCountersLoyaltyAbility(CPlaneswalkerCard* pCard, int nLoyalty, int nCounters, int nMax)
{
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(pCard,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->GetTargeting()->SetSubjectCount(0, nMax);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), nCounters));
	pCard->AddAbility(cpAbility.GetPointer());
}

// The creatures pPlayer controls get +N/+N (and the keyword) until end of turn
static void PumpCreatures(CGame* pGame, CPlayer* pPlayer, int nPower, int nToughness, CreatureKeyword keyword = CreatureKeyword::Null)
{
	CCountedCardContainer creatures;
	GetCreatures(pGame, pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), nPower, nToughness, keyword);
}

CAjaniAdversaryOfTyrantsCard::CAjaniAdversaryOfTyrantsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani, Adversary of Tyrants"), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Ajani, 4)
{
	// +1: Put a +1/+1 counter on each of up to two target creatures.
	AddCountersLoyaltyAbility(this, +1, 1, 2);

	{
		// -2: Return target creature card with mana value 2 or less from your graveyard to the battlefield.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::less_equal<int>>(2)),
				ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}

	// -7: You get an emblem with "At the beginning of your end step, create three 1/1 white Cat creature tokens with
	// lifelink."
	AddEmblemLoyaltyAbility(this, -7, AJANI_ADVERSARY_EMBLEM_NAME, AJANI_ADVERSARY_EMBLEM_ID,
		_T("You get an emblem with \"At the beginning of your end step, create three 1/1 white Cat creature tokens with lifelink.\" Activates"));
}

CAjaniWiseCounselorCard::CAjaniWiseCounselorCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani, Wise Counselor"), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Ajani, 5)
{
	// +2: You gain 1 life for each creature you control.
	AddLoyaltyAbility(this, +2, _T("+2: You gain 1 life for each creature you control. Activates"), &CAjaniWiseCounselorCard::BeforeGainLife);

	// -3: Creatures you control get +2/+2 until end of turn.
	AddLoyaltyAbility(this, -3, _T("-3: Creatures you control get +2/+2 until end of turn. Activates"), &CAjaniWiseCounselorCard::BeforePump);

	// -9: Put X +1/+1 counters on target creature, where X is your life total.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniWiseCounselorCard::BeforeCounters));
	AddAbility(cpAbility.GetPointer());
}

bool CAjaniWiseCounselorCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), CountCreatures(GetGame(), pAction->GetController()));
	return true;
}

bool CAjaniWiseCounselorCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +2, +2);
	return true;
}

bool CAjaniWiseCounselorCard::BeforeCounters(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	int nLife = (int)pAction->GetController()->GetLife();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && nLife > 0)
		CCardCounterModifier(_T("+1/+1"), nLife).ApplyTo(pCard);
	return false;
}

CLilianaTheNecromancerCard::CLilianaTheNecromancerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Liliana, the Necromancer"), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Liliana, 4)
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CLilianaTheNecromancerCard::OnCreaturesSelected))
{
	// +1: Target player loses 2 life.
	AddPlayerLoyaltyAbility(this, +1, &CLilianaTheNecromancerCard::BeforeLoseLife);

	{
		// -1: Return target creature card from your graveyard to your hand.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: Destroy up to two target creatures. Put up to two creature cards from graveyards onto the battlefield
		// under your control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->GetTargeting()->SetSubjectCount(0, 2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaTheNecromancerCard::BeforeDestroy));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLilianaTheNecromancerCard::BeforeLoseLife(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	return false;
}

bool CLilianaTheNecromancerCard::BeforeDestroy(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (pTargetAction)
	{
		CCountedCardContainer targets;
		pTargetAction->GetTargetGroup().GetCardSubjects(targets);
		CMoveCardModifier pDestroy = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy);
		for (int i = 0; i < targets.GetSize(); ++i)
			if (targets.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				pDestroy.ApplyTo(targets.GetAt(i));
	}

	// Then the creature cards in every graveyard (the destroyed ones too)
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pCard = pGraveyard->GetAt(i);
			if (!pCard->GetCardType().IsCreature())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 0, entries.size() < 2 ? (int)entries.size() : 2, NULL, pController,
			(DWORD)pController);
	return false;
}

void CLilianaTheNecromancerCard::OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pController);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Graveyard)
				pModifier.ApplyTo(pCard);
		}
}

CLilianaUntouchedByDeathCard::CLilianaUntouchedByDeathCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Liliana, Untouched by Death"), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Liliana, 4)
{
	// +1: Mill three cards. If at least one Zombie card is milled this way, each opponent loses 2 life and you gain 2
	// life.
	AddLoyaltyAbility(this, +1, _T("+1: Mill three cards. Activates"), &CLilianaUntouchedByDeathCard::BeforeMill);

	// -2: Target creature gets -X/-X until end of turn, where X is the number of Zombies you control.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaUntouchedByDeathCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());

	// -3: You may cast Zombie spells from your graveyard this turn.
	// Not implemented: spells can't be cast from the graveyard by an effect
}

bool CLilianaUntouchedByDeathCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	BOOL bZombie = FALSE;
	for (int n = 0; n < 3 && pLibrary->GetSize() > 0; ++n)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
		if (CreatureTypeComparer(CREATURE_TYPE(Zombie), false)(pCard))
			bZombie = TRUE;
		pModifier.ApplyTo(pCard);
	}

	if (bZombie)
		DrainOpponents(this, pController, 2, TRUE);
	return true;
}

bool CLilianaUntouchedByDeathCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	int nZombies = CountType(pAction->GetController(), CREATURE_TYPE(Zombie));
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && nZombies > 0)
		PumpCreature(pCard, -nZombies, -nZombies);
	return false;
}

CSarkhanDragonsoulCard::CSarkhanDragonsoulCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sarkhan, Dragonsoul"), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Sarkhan, 5)
	, m_DragonFilter(_T("a Dragon creature card"), _T("Dragon creature cards"),
		new AndCardComparer(new AnyCreatureComparer, new CreatureTypeComparer(CREATURE_TYPE(Dragon), false)))
{
	// +2: Sarkhan deals 1 damage to each opponent and each creature your opponents control.
	AddLoyaltyAbility(this, +2, _T("+2: 1 damage to each opponent and each creature your opponents control. Activates"),
		&CSarkhanDragonsoulCard::BeforeDamageAll);

	{
		// -3: Sarkhan deals 4 damage to target player or planeswalker.
		// (the damage to a planeswalker removes loyalty counters)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Planeswalker, false), TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSarkhanDragonsoulCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// -9: Search your library for any number of Dragon creature cards, put them onto the battlefield, then shuffle.
	AddLoyaltyAbility(this, -9, _T("-9: Search for any number of Dragon creature cards. Activates"), &CSarkhanDragonsoulCard::BeforeSearch);
}

bool CSarkhanDragonsoulCard::BeforeDamageAll(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DamageEachOpponent(this, pController, 1);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);
	return true;
}

bool CSarkhanDragonsoulCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		DealDamageToPlayer(this, pPlayer, 4);
		return false;
	}

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(LOYALTY_COUNTER, -4).ApplyTo(pCard);
	return false;
}

bool CSarkhanDragonsoulCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nLibrary = pController->GetZoneById(ZoneId::Library)->GetSize();
	SearchToBattlefield(GetGame(), pController, nLibrary > 0 ? nLibrary : 1, &m_DragonFilter, FALSE);
	return true;
}

CSarkhanFirebloodCard::CSarkhanFirebloodCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sarkhan, Fireblood"), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Sarkhan, 3)
{
	// +1: You may discard a card. If you do, draw a card.
	// Note: activating the ability is the choice (a card is discarded if the hand isn't empty)
	AddLoyaltyAbility(this, +1, _T("+1: Discard a card. If you do, draw a card. Activates"), &CSarkhanFirebloodCard::BeforeLoot);

	// +1: Add two mana in any combination of colors. Spend this mana only to cast Dragon spells.
	// Not implemented: the engine has no restricted mana

	// -7: Create four 5/5 red Dragon creature tokens with flying.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(pGame, DRAGON_J_TOKEN_NAME, DRAGON_J_TOKEN_ID, 4));
	cpAbility->SetAbilityText(_T("-7: Create four 5/5 red Dragon creature tokens with flying. Activates"));
	AddAbility(cpAbility.GetPointer());
}

bool CSarkhanFirebloodCard::BeforeLoot(CAbilityAction* pAction)
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

CTezzeretArtificeMasterCard::CTezzeretArtificeMasterCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tezzeret, Artifice Master"), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Tezzeret, 5)
{
	{
		// +1: Create a 1/1 colorless Thopter artifact creature token with flying.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(pGame, THOPTER_D_TOKEN_NAME, THOPTER_D_TOKEN_ID, 1));
		cpAbility->SetAbilityText(_T("+1: Create a 1/1 Thopter token with flying. Activates"));
		AddAbility(cpAbility.GetPointer());
	}

	// 0: Draw a card. If you control three or more artifacts, draw two cards instead.
	AddLoyaltyAbility(this, 0, _T("0: Draw a card (two with three or more artifacts). Activates"), &CTezzeretArtificeMasterCard::BeforeDraw);

	// -9: You get an emblem with "At the beginning of your end step, search your library for a permanent card, put it
	// onto the battlefield, then shuffle."
	AddEmblemLoyaltyAbility(this, -9, TEZZERET_ARTIFICE_EMBLEM_NAME, TEZZERET_ARTIFICE_EMBLEM_ID,
		_T("You get an emblem with \"At the beginning of your end step, search your library for a permanent card, put it onto the battlefield, then shuffle.\" Activates"));
}

bool CTezzeretArtificeMasterCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nArtifacts = CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(
		pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	DrawCards(GetGame(), pController, nArtifacts >= 3 ? 2 : 1);
	return true;
}

CTezzeretCruelMachinistCard::CTezzeretCruelMachinistCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tezzeret, Cruel Machinist"), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Tezzeret, 4)
{
	{
		// +1: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// 0: Until your next turn, target artifact you control becomes a 5/5 creature in addition to its other types.
		// (as Sylvan Awakening in Dominaria, with Animated Artifact (A))
		// Partial: an artifact that is already a creature doesn't change
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AndCardComparer(new CardTypeComparer(CardType::Artifact, false), new NegateCardComparer(new AnyCreatureComparer)), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), 0);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretCruelMachinistCard::BeforeAnimate));
		AddAbility(cpAbility.GetPointer());
	}

	// -7: Put any number of cards from your hand onto the battlefield face down. They're 5/5 artifact creatures.
	// Not implemented: there are no face-down permanents apart from morph
}

bool CTezzeretCruelMachinistCard::BeforeAnimate(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetCardType().IsCreature() || pCard->GetIsAlsoA())
		return false;

	CPlayer* pController = pAction->GetController();
	CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(ANIMATED_ARTIFACT_A_TOKEN_NAME, ANIMATED_ARTIFACT_A_TOKEN_ID, pController);
	CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
		TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, GetGame()->GetNextPlayer(pController));
	pAnimate->ApplyTo(pCard);
	pRemove.ApplyTo(pCard);
	return false;
}

CVivienOfTheArkbowCard::CVivienOfTheArkbowCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vivien of the Arkbow"), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Vivien, 5)
{
	// +2: Put two +1/+1 counters on up to one target creature.
	AddCountersLoyaltyAbility(this, +2, 2, 1);

	{
		// -3: Target creature you control deals damage equal to its power to target creature you don't control.
		// (two targets, as Ral Zarek in Dragon's Maze)
		counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, false,
				new AnyCreatureComparer, false, _T(""), TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVivienOfTheArkbowCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// -9: Creatures you control get +4/+4 and gain trample until end of turn.
	AddLoyaltyAbility(this, -9, _T("-9: Creatures you control get +4/+4 and gain trample until end of turn. Activates"),
		&CVivienOfTheArkbowCard::BeforePump);
}

bool CVivienOfTheArkbowCard::BeforeDamage(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCreatureCard* pSource = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (!pSource || !pTarget || pSource->GetZoneId() != ZoneId::Battlefield || pTarget->GetZoneId() != ZoneId::Battlefield)
		return true;

	int nPower = (int)pSource->GetPower();
	if (nPower > 0)
		DealDamageToCreature(pSource, pTarget, nPower);
	return true;
}

bool CVivienOfTheArkbowCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +4, +4, CreatureKeyword::Trample);
	return true;
}

CVivienReidCard::CVivienReidCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vivien Reid"), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Vivien, 5)
	, m_CreatureOrLandFilter(_T("a creature or land card"), _T("creature or land cards"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::_Land, false)))
{
	// +1: Look at the top four cards of your library. You may reveal a creature or land card from among them and put it
	// into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	AddLoyaltyAbility(this, +1, _T("+1: Look at the top four cards for a creature or land card. Activates"), &CVivienReidCard::BeforeLook);

	{
		// -3: Destroy target artifact, enchantment, or creature with flying.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new OrCardComparer(new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
					new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false))),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -8: You get an emblem with "Creatures you control get +2/+2 and have vigilance, trample, and indestructible."
	AddEmblemLoyaltyAbility(this, -8, VIVIEN_REID_EMBLEM_NAME, VIVIEN_REID_EMBLEM_ID,
		_T("You get an emblem with \"Creatures you control get +2/+2 and have vigilance, trample, and indestructible.\" Activates"));
}

bool CVivienReidCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 4, &m_CreatureOrLandFilter);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

#define AVATAR_A_TOKEN_NAME		_T("Avatar (A)")
#define AVATAR_A_TOKEN_ID		55115
#define ZOMBIE_P_TOKEN_NAME		_T("Zombie (P)")
#define ZOMBIE_P_TOKEN_ID		55009

// The number of Demons with different names that pPlayer controls
static int CountDifferentDemons(CPlayer* pPlayer)
{
	std::vector<CString> names;
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!CreatureTypeComparer(CREATURE_TYPE(Demon), false)(pCard))
			continue;

		CString strName = pCard->GetCardName(FALSE);
		if (std::find(names.begin(), names.end(), strName) == names.end())
			names.push_back(strName);
	}
	return (int)names.size();
}

CAetherTunnelCard::CAetherTunnelCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Aether Tunnel"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(+1), Life(+0), CreatureKeyword::Unblockable)
{
	// Enchanted creature gets +1/+0 and can't be blocked.
}

CAjanisLastStandCard::CAjanisLastStandCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ajani's Last Stand"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature or planeswalker you control dies, you may sacrifice this enchantment. If you do, create a 4/4
	// white Avatar creature token with flying.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjanisLastStandCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());

	// When a spell or ability an opponent controls causes you to discard this card, if you control a Plains, create a
	// 4/4 white Avatar creature token with flying.
	// Not implemented: there is no trigger for a discard caused by an opponent
}

bool CAjanisLastStandCard::BeforeToken(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice).ApplyTo(this);
	if (GetZoneId() == ZoneId::Graveyard)
		CTokenCreationModifier(GetGame(), AVATAR_A_TOKEN_NAME, AVATAR_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CAjanisWelcomeCard::CAjanisWelcomeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ajani's Welcome"), CardType::GlobalEnchantment, nID,
		WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control enters, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjanisWelcomeCard::BeforeGainLife));
	AddAbility(cpAbility.GetPointer());
}

bool CAjanisWelcomeCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CColossalMajestyCard::CColossalMajestyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Colossal Majesty"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, if you control a creature with power 4 or greater, draw a card.
	AddStepTrigger(this, NodeId::UpkeepStep, false, &CColossalMajestyCard::SetTriggerContext, &CColossalMajestyCard::BeforeDraw);
}

bool CColossalMajestyCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	CCardFilter filter(_T("a creature with power 4 or greater"), _T("creatures with power 4 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(4));
	return filter.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

bool CColossalMajestyCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDwindleCard::CDwindleCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Dwindle"), nID,
		_T("2") BLUE_MANA_TEXT,
		Power(-6), Life(+0))
{
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// When enchanted creature blocks, destroy it. (The attacking creature remains blocked.)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::EventCallback, &CWhenAttackedBlocked::SetBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDwindleCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDwindleCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CDwindleCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const
{
	return pCreature && pCreature == GetEnchantedOn();
}

bool CDwindleCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = GetEnchantedOn();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy).ApplyTo(pCard);
	return true;
}

CGiftOfParadiseCard::CGiftOfParadiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gift of Paradise"), CardType::EnchantLand, nID)
{
	// Enchant land. Enchanted land has "{T}: Add two mana of any one color."
	// Partial: as Fertile Ground in Eighth Edition, whenever enchanted land is tapped for mana, its controller adds one
	// additional mana of any color (the engine can't grant mana abilities)
	counted_ptr<CAbilityEnchant> cpSpell(
		::CreateObject<CAbilityEnchant>(this,
			_T("2") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false),
			CAbilityEnchant::CreateAbilityCallback(this, &CGiftOfParadiseCard::CreateEnchantAbility),
			CAbilityEnchant::AdditionType::ToEnchantCard));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());

	// When this Aura enters, you gain 3 life.
	AddEnterTrigger(this, &CGiftOfParadiseCard::BeforeGainLife);
}

counted_ptr<CAbility> CGiftOfParadiseCard::CreateEnchantAbility(CCard* pEnchantedCard, CCard* pEnchantCard, ContextValue_& contextValue)
{
	typedef
		TTriggeredAbility< CTriggeredProdManaAbility, CWhenSelfTappedForMana > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pEnchantCard, pEnchantedCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
	cpAbility->SetSkipStack(TRUE);

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CGiftOfParadiseCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CHieromancersCageCard::CHieromancersCageCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hieromancer's Cage"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, exile target nonland permanent an opponent controls until this enchantment leaves
	// the battlefield. (as Bishop of Binding in Rivals of Ixalan)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHieromancersCageCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());

	AddLeaveTrigger(this, &CHieromancersCageCard::BeforeReturn);
}

bool CHieromancersCageCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CHieromancersCageCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CInfernalScarringCard::CInfernalScarringCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Infernal Scarring"), nID,
		_T("1") BLACK_MANA_TEXT,
		Power(+2), Life(+0))
{
	// Enchanted creature gets +2/+0 and has "When this creature dies, draw a card."
	// (the trigger belongs to the Aura, as Demonic Vigor in Dominaria; its controller draws)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CInfernalScarringCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInfernalScarringCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CInfernalScarringCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard == GetEnchantedOn();
}

bool CInfernalScarringCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CKnightsPledgeCard::CKnightsPledgeCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Knight's Pledge"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+2), Life(+2))
{
	// Enchanted creature gets +2/+2.
}

CLilianasContractCard::CLilianasContractCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Liliana's Contract"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, you draw four cards and you lose 4 life.
	AddEnterTrigger(this, &CLilianasContractCard::BeforeDraw);

	// At the beginning of your upkeep, if you control four or more Demons with different names, you win the game.
	// (each opponent loses the game, as Revel in Riches in Ixalan)
	counted_ptr<WinAbility> cpAbility(::CreateObject<WinAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(WinAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(WinAbility::ContextFunction(this, &CLilianasContractCard::SetWinContext));
	cpAbility->SetBeforeResolveSelectionCallback(WinAbility::BeforeResolveSelectionCallback(this, &CLilianasContractCard::BeforeWin));
	AddAbility(cpAbility.GetPointer());
}

bool CLilianasContractCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 4);
	CLifeModifier(Life(-4), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pController);
	return true;
}

bool CLilianasContractCard::SetWinContext(CTriggeredLoseGameAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return CountDifferentDemons(GetController()) >= 4;
}

bool CLilianasContractCard::BeforeWin(WinAbility::TriggeredActionType* pAction)
{
	return CountDifferentDemons(GetController()) >= 4;
}

COpenTheGravesCard::COpenTheGravesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Open the Graves"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a nontoken creature you control dies, create a 2/2 black Zombie creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CardTypeComparer(CardType::Token, false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COpenTheGravesCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool COpenTheGravesCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CPatientRebuildingCard::CPatientRebuildingCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Patient Rebuilding"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, target opponent mills three cards, then you draw a card for each land card put
	// into their graveyard this way.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPatientRebuildingCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CPatientRebuildingCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);
	int nLands = 0;
	for (int n = 0; n < 3 && pLibrary->GetSize() > 0; ++n)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Graveyard && pCard->GetCardType().IsLand())
			++nLands;
	}

	if (nLands > 0)
		DrawCards(GetGame(), pAction->GetController(), nLands);
	return false;
}

CProdigiousGrowthCard::CProdigiousGrowthCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Prodigious Growth"), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT,
		Power(+7), Life(+7), CreatureKeyword::Trample)
{
	// Enchanted creature gets +7/+7 and has trample.
}

CPsychicCorrosionCard::CPsychicCorrosionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Psychic Corrosion"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you draw a card, each opponent mills two cards.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPsychicCorrosionCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CPsychicCorrosionCard::BeforeMill(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			Mill(GetGame()->GetPlayer(ip), 2);
	return true;
}

CSarkhansUnsealingCard::CSarkhansUnsealingCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sarkhan's Unsealing"), CardType::GlobalEnchantment, nID,
		_T("3") RED_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever you cast a creature spell with power 4, 5, or 6, this enchantment deals 4 damage to any target.
		// Note: it can't target planeswalkers
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSarkhansUnsealingCard::SetSmallContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSarkhansUnsealingCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast a creature spell with power 7 or greater, this enchantment deals 4 damage to each opponent
		// and each creature and planeswalker they control. (the damage to planeswalkers removes loyalty counters)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSarkhansUnsealingCard::SetBigContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSarkhansUnsealingCard::BeforeDamageAll));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSarkhansUnsealingCard::SetSmallContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature)
		return false;

	int nPower = (int)pCreature->GetPower();
	return nPower >= 4 && nPower <= 6;
}

bool CSarkhansUnsealingCard::SetBigContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	return pCreature && (int)pCreature->GetPower() >= 7;
}

bool CSarkhansUnsealingCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 4);
	return false;
}

bool CSarkhansUnsealingCard::BeforeDamageAll(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DamageEachOpponent(this, pController, 4);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 4);

	CCardCounterModifier pLoyalty = CCardCounterModifier(LOYALTY_COUNTER, -4);
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

CTalonsOfWildwoodCard::CTalonsOfWildwoodCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Talons of Wildwood"), nID,
		_T("1") GREEN_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Trample)
{
	// Enchanted creature gets +1/+1 and has trample.

	// {2}{G}: Return this card from your graveyard to your hand. (as Jungle Creeper in Rivals of Ixalan)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") GREEN_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTalonsOfWildwoodCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CTalonsOfWildwoodCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

#define BAT_A_TOKEN_NAME		_T("Bat (A)")
#define BAT_A_TOKEN_ID			2803
#define OX_A_TOKEN_NAME			_T("Ox (A)")
#define OX_A_TOKEN_ID			55116
#define GOLD_COUNTER			_T("gold counter")

CAmuletOfSafekeepingCard::CAmuletOfSafekeepingCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Amulet of Safekeeping"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// Whenever you become the target of a spell or ability an opponent controls, counter that spell or ability unless
	// its controller pays {1}.
	// Not implemented: abilities can't be countered, and there is no trigger for a player becoming a target

	// Creature tokens get -1/-0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Token, false)),
			Power(-1), Life(+0)));

	AddAbility(cpAbility.GetPointer());
}

CArcaneEncyclopediaCard::CArcaneEncyclopediaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Arcane Encyclopedia"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// {3}, {T}: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3"), 1));

	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CDesecratedTombCard::CDesecratedTombCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Desecrated Tomb"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// Whenever one or more creature cards leave your graveyard, create a 1/1 black Bat creature token with flying.
	// Note: it triggers for each creature card
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Graveyard, ZoneId::_AllZones));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDesecratedTombCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CDesecratedTombCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), BAT_A_TOKEN_NAME, BAT_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CDragonsHoardCard::CDragonsHoardCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dragon's Hoard"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// Whenever a Dragon you control enters, put a gold counter on this artifact.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dragon), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDragonsHoardCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Remove a gold counter from this artifact: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(GOLD_COUNTER), -1);
		AddAbility(cpAbility.GetPointer());
	}

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);
}

bool CDragonsHoardCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(GOLD_COUNTER, +1).ApplyTo(this);
	return true;
}

CFountainOfRenewalCard::CFountainOfRenewalCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fountain of Renewal"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// At the beginning of your upkeep, you gain 1 life.
	AddStepTrigger<CFountainOfRenewalCard>(this, NodeId::UpkeepStep, false, NULL, &CFountainOfRenewalCard::BeforeGainLife);

	// {3}, Sacrifice this artifact: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3"), 1));

	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

bool CFountainOfRenewalCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CMaraudersAxeCard::CMaraudersAxeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Marauder's Axe"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	// Equipped creature gets +2/+0. Equip {2}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));
	AddAbility(cpAbility.GetPointer());
}

CRoguesGlovesCard::CRoguesGlovesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Rogue's Gloves"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// Whenever equipped creature deals combat damage to a player, you may draw a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback,
							   &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new EquippedByComparer(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRoguesGlovesCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}

	// Equip {2}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	AddAbility(cpAbility.GetPointer());
}

bool CRoguesGlovesCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSigiledSwordOfValeronCard::CSigiledSwordOfValeronCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sigiled Sword of Valeron"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// Equipped creature gets +2/+0, has vigilance, and is a Knight in addition to its other types. Equip {3}
		// Partial: the creature doesn't become a Knight
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("3")));

		cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));

		CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
		pModifier->GetModifier().SetToAdd(CreatureKeyword::Vigilance);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		cpAbility->AddCreatureModifier(pModifier);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever equipped creature attacks, create a 2/2 white Knight creature token with vigilance that's attacking.
		// Partial: the token isn't attacking (a token can't enter the battlefield attacking)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
							   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSigiledSwordOfValeronCard::SetAttackContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSigiledSwordOfValeronCard::BeforeToken));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSigiledSwordOfValeronCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attackSubject) const
{
	return pCreature && EquippedByComparer(this)(pCreature);
}

bool CSigiledSwordOfValeronCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CTezzeretsGatebreakerCard::CTezzeretsGatebreakerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Tezzeret's Gatebreaker"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_BlueOrArtifactFilter(_T("a blue or artifact card"), _T("blue or artifact cards"),
		new OrCardComparer(new CardTypeComparer(CardType::Blue, false), new CardTypeComparer(CardType::Artifact, false)))
{
	// When this artifact enters, look at the top five cards of your library. You may reveal a blue or artifact card
	// from among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	AddEnterTrigger(this, &CTezzeretsGatebreakerCard::BeforeLook);

	// {5}{U}, {T}, Sacrifice this artifact: Creatures you control can't be blocked this turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("5") BLUE_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Creatures you control can't be blocked this turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretsGatebreakerCard::BeforeUnblockable));
	AddAbility(cpAbility.GetPointer());
}

bool CTezzeretsGatebreakerCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_BlueOrArtifactFilter);
	return true;
}

bool CTezzeretsGatebreakerCard::BeforeUnblockable(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		((CCreatureCard*)creatures.GetAt(i))->GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

CTransmogrifyingWandCard::CTransmogrifyingWandCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Transmogrifying Wand"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// This artifact enters with three charge counters on it. (as the loyalty counters of the planeswalkers)
	GetCounterContainer()->ScheduleCounter(CHARGE_COUNTER, 3, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// {1}, {T}, Remove a charge counter from this artifact: Destroy target creature. Its controller creates a 2/4 white
	// Ox creature token. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1"),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(CHARGE_COUNTER), -1);
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTransmogrifyingWandCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CTransmogrifyingWandCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pController = pCard->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy).ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Battlefield)
		CTokenCreationModifier(GetGame(), OX_A_TOKEN_NAME, OX_A_TOKEN_ID, 1).ApplyTo(pController);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

// Destroys every permanent on the battlefield that passes the comparer
static void DestroyAll(CGame* pGame, const CardComparer& comparer)
{
	CCountedCardContainer cards;
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (comparer(pBattlefield->GetAt(i)))
				cards.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(cards.GetAt(i));
}

// A sorcery on target creature (the callback does the effect and returns false)
template <class T>
static CTargetSpell* AddCreatureSorcery(T* pCard, LPCTSTR strCost, Characteristic characteristic, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(pCard, AbilityType::Sorcery,
			strCost,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(characteristic);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A sorcery on target player (the callback does the effect and returns false)
template <class T>
static CTargetSpell* AddPlayerSorcery(T* pCard, LPCTSTR strCost, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(pCard, AbilityType::Sorcery,
			strCost,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

CAjanisInfluenceCard::CAjanisInfluenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ajani's Influence"), CardType::Sorcery, nID)
	, m_WhiteFilter(_T("a white card"), _T("white cards"), new CardTypeComparer(CardType::White, false))
{
	// Put two +1/+1 counters on target creature. Look at the top five cards of your library. You may reveal a white
	// card from among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	AddCreatureSorcery(this, _T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Characteristic::Positive, &CAjanisInfluenceCard::BeforeResolution);
}

bool CAjanisInfluenceCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(_T("+1/+1"), +2).ApplyTo(pCard);

	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_WhiteFilter);
	return false;
}

CBloodDivinationCard::CBloodDivinationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blood Divination"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, sacrifice a creature. Draw three cards. (as Divination)
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT, 3));

	cpSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	AddSpell(cpSpell.GetPointer());
}

CCleansingNovaCard::CCleansingNovaCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cleansing Nova"), CardType::Sorcery, nID)
{
	// Choose one -
	// * Destroy all creatures.
	CGenericSpell* pSpell = AddSorcery(this, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, &CCleansingNovaCard::BeforeCreatures);
	pSpell->SetAbilityText(_T("Destroy all creatures. Casts"));

	// * Destroy all artifacts and enchantments.
	pSpell = AddSorcery(this, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, &CCleansingNovaCard::BeforeArtifacts);
	pSpell->SetAbilityText(_T("Destroy all artifacts and enchantments. Casts"));
}

bool CCleansingNovaCard::BeforeCreatures(CAbilityAction* pAction)
{
	DestroyAll(GetGame(), AnyCreatureComparer());
	return true;
}

bool CCleansingNovaCard::BeforeArtifacts(CAbilityAction* pAction)
{
	DestroyAll(GetGame(), CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false));
	return true;
}

CDeclareDominanceCard::CDeclareDominanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Declare Dominance"), CardType::Sorcery, nID)
{
	// Target creature gets +3/+3 until end of turn. All creatures able to block it this turn do so. (Lure)
	AddCreatureSorcery(this, _T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Characteristic::Positive, &CDeclareDominanceCard::BeforePump);
}

bool CDeclareDominanceCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +3, +3, CreatureKeyword::Lure);
	return false;
}

CFieryFinishCard::CFieryFinishCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fiery Finish"), CardType::Sorcery, nID)
{
	// Fiery Finish deals 7 damage to target creature.
	AddDamageSorcery(this, _T("4") RED_MANA_TEXT RED_MANA_TEXT, 7, new AnyCreatureComparer, FALSE);
}

CFrayingOmnipotenceCard::CFrayingOmnipotenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fraying Omnipotence"), CardType::Sorcery, nID)
{
	// Each player loses half their life, then discards half the cards in their hand, then sacrifices half the
	// creatures they control of their choice. Round up each time.
	AddSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CFrayingOmnipotenceCard::BeforeResolution);
}

bool CFrayingOmnipotenceCard::BeforeResolution(CAbilityAction* pAction)
{
	CGame* pGame = GetGame();
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = pGame->GetPlayer(ip);
		int nLife = (int)pPlayer->GetLife();
		if (nLife > 0)
			CLifeModifier(Life(-((nLife + 1) / 2)), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	}

	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = pGame->GetPlayer(ip);
		int nDiscard = (pPlayer->GetZoneById(ZoneId::Hand)->GetSize() + 1) / 2;
		if (nDiscard > 0)
			ChooseAndMove(pGame, pPlayer, ZoneId::Hand, nDiscard, nDiscard, CCardFilter::GetFilter(_T("cards")), ZoneId::Graveyard, MoveType::Discard);
	}

	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = pGame->GetPlayer(ip);
		int nSacrifice = (CountCreatures(pGame, pPlayer) + 1) / 2;
		if (nSacrifice > 0)
			ChooseAndMove(pGame, pPlayer, ZoneId::Battlefield, nSacrifice, nSacrifice, CCardFilter::GetFilter(_T("creatures")), ZoneId::Graveyard, MoveType::Sacrifice);
	}
	return true;
}

CHeroicReinforcementsCard::CHeroicReinforcementsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Heroic Reinforcements"), CardType::Sorcery, nID)
{
	// Create two 1/1 white Soldier creature tokens. Until end of turn, creatures you control get +1/+1 and gain haste.
	AddSorcery(this, _T("2") RED_MANA_TEXT WHITE_MANA_TEXT, &CHeroicReinforcementsCard::BeforeResolution);
}

bool CHeroicReinforcementsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CTokenCreationModifier(GetGame(), SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID, 2).ApplyTo(pController);
	PumpCreatures(GetGame(), pController, +1, +1, CreatureKeyword::Haste);
	return true;
}

CLichsCaressCard::CLichsCaressCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lich's Caress"), CardType::Sorcery, nID)
{
	// Destroy target creature. You gain 3 life.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, new AnyCreatureComparer,
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLichsCaressCard::BeforeGainLife));
}

bool CLichsCaressCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CLilianasSpoilsCard::CLilianasSpoilsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Liliana's Spoils"), CardType::Sorcery, nID)
	, m_BlackFilter(_T("a black card"), _T("black cards"), new CardTypeComparer(CardType::Black, false))
{
	// Target opponent discards a card. Look at the top five cards of your library. You may reveal a black card from
	// among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("3") BLACK_MANA_TEXT, &CLilianasSpoilsCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
}

bool CLilianasSpoilsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);

	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_BlackFilter);
	return false;
}

COneWithTheMachineCard::COneWithTheMachineCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("One with the Machine"), CardType::Sorcery, nID)
{
	// Draw cards equal to the greatest mana value among artifacts you control.
	AddSorcery(this, _T("3") BLUE_MANA_TEXT, &COneWithTheMachineCard::BeforeDraw);
}

bool COneWithTheMachineCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	int nMax = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsArtifact() && (int)pCard->GetConvertedManaCost() > nMax)
			nMax = (int)pCard->GetConvertedManaCost();
	}

	if (nMax > 0)
		DrawCards(GetGame(), pController, nMax);
	return true;
}

CSarkhansDragonfireCard::CSarkhansDragonfireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sarkhan's Dragonfire"), CardType::Sorcery, nID)
	, m_RedFilter(_T("a red card"), _T("red cards"), new CardTypeComparer(CardType::Red, false))
{
	// Sarkhan's Dragonfire deals 3 damage to any target. Look at the top five cards of your library. You may reveal a
	// red card from among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// Note: it can't target planeswalkers, the cards are looked at before the damage, and the rest go to the bottom in
	// any order
	CTargetChgLifeSpell* pSpell = AddDamageSorcery(this, _T("3") RED_MANA_TEXT RED_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSarkhansDragonfireCard::BeforeLook));
}

bool CSarkhansDragonfireCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_RedFilter);
	return true;
}

CSovereignsBiteCard::CSovereignsBiteCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sovereign's Bite"), CardType::Sorcery, nID)
{
	// Target player loses 3 life and you gain 3 life.
	AddPlayerSorcery(this, _T("1") BLACK_MANA_TEXT, &CSovereignsBiteCard::BeforeDrain);
}

bool CSovereignsBiteCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	GainLife(this, pAction->GetController(), 3);
	return false;
}

CTakeVengeanceCard::CTakeVengeanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Take Vengeance"), CardType::Sorcery, nID)
{
	// Destroy target tapped creature.
	AddMoveSorcery(this, _T("1") WHITE_MANA_TEXT, new AndCardComparer(new AnyCreatureComparer, new TappedComparer),
		ZoneId::Graveyard, MoveType::Destroy);
}

CThudCard::CThudCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thud"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, sacrifice a creature. Thud deals damage equal to the sacrificed
	// creature's power to any target. (as Fling in M11)
	// Note: it can't target planeswalkers
	counted_ptr<CTargetChgLifeSpell2> cpSpell(
		::CreateObject<CTargetChgLifeSpell2>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			CCardFilter::GetFilter(_T("creatures")),
			PreventableType::Preventable, DamageType::SpellDamage | DamageType::NonCombatDamage));

	AddSpell(cpSpell.GetPointer());
}

CViviensInvocationCard::CViviensInvocationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vivien's Invocation"), CardType::Sorcery, nID)
	, m_CreatureFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
	, m_TargetSelection(pGame, CSelectionSupport::SelectionCallback(this, &CViviensInvocationCard::OnTargetSelected))
{
	// Look at the top seven cards of your library. You may put a creature card from among them onto the battlefield.
	// Put the rest on the bottom of your library in a random order. When a creature is put onto the battlefield this
	// way, it deals damage equal to its power to target creature an opponent controls.
	// Partial: the creature of the opponent is chosen on resolution (not targeted), and the rest go to the bottom in
	// any order
	AddSorcery(this, _T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, &CViviensInvocationCard::BeforeResolution);
}

bool CViviensInvocationCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	// The creatures already on the battlefield, to find the new one
	std::vector<CCard*> before;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		before.push_back(pBattlefield->GetAt(i));

	// (as Gishath, Sun's Avatar in Ixalan)
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 7,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &m_CreatureFilter,
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	CCreatureCard* pNew = NULL;
	for (int i = 0; i < pBattlefield->GetSize() && !pNew; ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && std::find(before.begin(), before.end(), pCard) == before.end())
			pNew = dynamic_cast<CCreatureCard*>(pCard);
	}
	if (!pNew)
		return true;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("%s deals damage to %s"), pNew->GetCardName(TRUE), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_TargetSelection.AddSelectionRequest(entries, 1, 1, NULL, pController, (DWORD)pNew);
	return true;
}

void CViviensInvocationCard::OnTargetSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCreatureCard* pSource = (CCreatureCard*)dwContext1;
	if (!pSource || pSource->GetZoneId() != ZoneId::Battlefield)
		return;

	int nPower = (int)pSource->GetPower();
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield && nPower > 0)
				DealDamageToCreature(pSource, pCard, nPower);
		}
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

// An instant on target creature (the callback does the effect and returns false)
template <class T>
static CTargetSpell* AddCreatureInstant(T* pCard, LPCTSTR strCost, Characteristic characteristic, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(pCard, AbilityType::Instant,
			strCost,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(characteristic);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

CAbnormalEnduranceCard::CAbnormalEnduranceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Abnormal Endurance"), CardType::Instant, nID)
	, m_pTarget(NULL)
	, m_nTurn(-1)
{
	// Until end of turn, target creature gets +2/+0 and gains "When this creature dies, return it to the battlefield
	// tapped under its owner's control."
	AddCreatureInstant(this, _T("1") BLACK_MANA_TEXT, Characteristic::Positive, &CAbnormalEnduranceCard::BeforePump);

	// The granted ability: a trigger of this card in the graveyard that remembers the creature until end of turn (as
	// Unconventional Tactics in Hour of Devastation)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard, FALSE, TRUE, FALSE));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAbnormalEnduranceCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAbnormalEnduranceCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CAbnormalEnduranceCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	PumpCreature(pCard, +2, +0);
	m_pTarget = pCard;
	m_nTurn = GetGame()->GetGameTurnNumber();
	return false;
}

bool CAbnormalEnduranceCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard == m_pTarget && GetGame()->GetGameTurnNumber() == m_nTurn;
}

bool CAbnormalEnduranceCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = m_pTarget;
	m_pTarget = NULL;
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others);
		pModifier.SetTapped(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CAegisOfTheHeavensCard::CAegisOfTheHeavensCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Aegis of the Heavens"), CardType::Instant, nID)
{
	// Target creature gets +1/+7 until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			Power(+1), Life(+7), CreatureKeyword::Null, CreatureKeyword::Null, TRUE, PreventableType::NotPreventable));

	AddSpell(cpSpell.GetPointer());
}

CInfernalReckoningCard::CInfernalReckoningCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Infernal Reckoning"), CardType::Instant, nID)
{
	// Exile target colorless creature. You gain life equal to its power. (the life is gained before the exile, with the
	// same power)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			BLACK_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer, new ColorlessComparer),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInfernalReckoningCard::BeforeGainLife));
	AddSpell(cpSpell.GetPointer());
}

bool CInfernalReckoningCard::BeforeGainLife(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && (int)pCreature->GetPower() > 0)
		GainLife(this, pAction->GetController(), (int)pCreature->GetPower());
	return true;
}

CIsolateCard::CIsolateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Isolate"), CardType::Instant, nID)
{
	// Exile target permanent with mana value 1.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT,
			new ConvertedManaCostComparer<std::equal_to<int>>(1),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CNexusOfFateCard::CNexusOfFateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nexus of Fate"), CardType::Instant, nID)
{
	// Take an extra turn after this one.
	counted_ptr<CPlayerEffectSpell> cpSpell(
		::CreateObject<CPlayerEffectSpell>(this, AbilityType::Instant,
			_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			PlayerEffectType::TimeWalk, FALSE, 1));

	cpSpell->SetAffectControllerOnly();
	AddSpell(cpSpell.GetPointer());

	// If Nexus of Fate would be put into a graveyard from anywhere, reveal Nexus of Fate and shuffle it into its
	// owner's library instead. (see Move)
}

void CNexusOfFateCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	if (pToZone && pToZone->GetZoneId() == ZoneId::Graveyard)
	{
		CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
		__super::Move(pLibrary, pByPlayer, MoveType::Others, cardPlacement, can_dredge);
		if (GetZoneId() == ZoneId::Library)
		{
			if (!GetGame()->IsThinking())
				GetGame()->Message(_T("Nexus of Fate is revealed and shuffled into its owner's library"),
					GetOwner()->IsComputer() ? GetGame()->GetComputerImage() : GetGame()->GetHumanImage(), MessageImportance::High);
			pLibrary->Shuffle();
		}
		return;
	}

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);
}

CNightmaresThirstCard::CNightmaresThirstCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nightmare's Thirst"), CardType::Instant, nID)
{
	// You gain 1 life. Target creature gets -X/-X until end of turn, where X is the amount of life you gained this turn.
	AddCreatureInstant(this, BLACK_MANA_TEXT, Characteristic::Negative, &CNightmaresThirstCard::BeforeShrink);
}

bool CNightmaresThirstCard::BeforeShrink(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	GainLife(this, pController, 1);

	CCard* pCard = pAction->GetAssociatedCard();
	int nX = (int)pController->GetLifeGainThisTurn();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && nX > 0)
		PumpCreature(pCard, -nX, -nX);
	return false;
}

CRevitalizeCard::CRevitalizeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Revitalize"), CardType::Instant, nID)
{
	// You gain 3 life. Draw a card.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT, 1));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRevitalizeCard::BeforeGainLife));
	AddSpell(cpSpell.GetPointer());
}

bool CRevitalizeCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CRootSnareCard::CRootSnareCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Root Snare"), CardType::Instant, nID)
{
	// Prevent all combat damage that would be dealt this turn. (as Fog)
	counted_ptr<CPlayerEffectSpell> cpSpell(
		::CreateObject<CPlayerEffectSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			PlayerEffectType::PreventAllCombatDamage, TRUE));

	AddSpell(cpSpell.GetPointer());
}

CSpitFlameCard::CSpitFlameCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spit Flame"), CardType::Instant, nID)
{
	// Spit Flame deals 4 damage to target creature.
	AddDamageSpell(this, _T("2") RED_MANA_TEXT, 4, new AnyCreatureComparer, FALSE);

	// Whenever a Dragon you control enters, you may pay {R}. If you do, return this card from your graveyard to your
	// hand. (a trigger of a card in the graveyard, as Unconventional Tactics in Hour of Devastation)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield, FALSE, TRUE, FALSE));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dragon), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(RED_MANA_TEXT);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSpitFlameCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpitFlameCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CSpitFlameCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Graveyard;
}

bool CSpitFlameCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(this);
	return true;
}

CStranglingSporesCard::CStranglingSporesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Strangling Spores"), CardType::Instant, nID)
{
	// Target creature gets -3/-3 until end of turn.
	AddCreatureInstant(this, _T("3") BLACK_MANA_TEXT, Characteristic::Negative, &CStranglingSporesCard::BeforeShrink);
}

bool CStranglingSporesCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, -3, -3);
	return false;
}

CUncomfortableChillCard::CUncomfortableChillCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Uncomfortable Chill"), CardType::Instant, nID)
{
	// Creatures your opponents control get -2/-0 until end of turn. Draw a card.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("2") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUncomfortableChillCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CUncomfortableChillCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), -2, +0);

	DrawCards(GetGame(), pController, 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

#define CAT_G_TOKEN_NAME		_T("Cat (G)")
#define CAT_G_TOKEN_ID			55098
#define ANGEL_M_TOKEN_NAME		_T("Angel (M)")
#define ANGEL_M_TOKEN_ID		55117

// The creatures of a type that pPlayer controls
static void GetCreaturesOfType(CGame* pGame, CPlayer* pPlayer, const CreatureType& type, CCountedCardContainer& creatures)
{
	CCountedCardContainer all;
	GetCreatures(pGame, pPlayer, TRUE, all);
	for (int i = 0; i < all.GetSize(); ++i)
		if (CreatureTypeComparer(type, false)(all.GetAt(i)))
			creatures.AddCard(all.GetAt(i), CardPlacement::Top);
}

CAethershieldArtificerCard::CAethershieldArtificerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aethershield Artificer"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// At the beginning of combat on your turn, target artifact creature you control gets +2/+2 and gains
	// indestructible until end of turn.
	CTargeting* pTargeting = AddStepTargetTrigger<CAethershieldArtificerCard>(this, NodeId::BeginningOfCombatStep, NULL,
		&CAethershieldArtificerCard::BeforePump, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CAethershieldArtificerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		PumpCreature(pCard, +2, +2);
		pCard->GetCardKeyword()->AddIndestructible(TRUE);
	}
	return false;
}

CAngelOfTheDawnCard::CAngelOfTheDawnCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of the Dawn"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, creatures you control get +1/+1 and gain vigilance until end of turn.
	AddEnterTrigger(this, &CAngelOfTheDawnCard::BeforePump);
}

bool CAngelOfTheDawnCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, +1, CreatureKeyword::Vigilance);
	return true;
}

CCavalryDrillmasterCard::CCavalryDrillmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cavalry Drillmaster"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters, target creature gets +2/+0 and gains first strike until end of turn.
	AddEnterTargetTrigger(this, &CCavalryDrillmasterCard::BeforePump, false, Characteristic::Positive);
}

bool CCavalryDrillmasterCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +2, +0, CreatureKeyword::FirstStrike);
	return false;
}

CCourtClericCard::CCourtClericCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Court Cleric"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// This creature gets +1/+1 as long as you control an Ajani planeswalker. (as Teferi's Sentinel)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+1)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Ajani));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CDaybreakChaplainCard::CDaybreakChaplainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Daybreak Chaplain"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(3))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

CDwarvenPriestCard::CDwarvenPriestCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dwarven Priest"), CardType::Creature, CREATURE_TYPE2(Dwarf, Cleric), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, you gain 1 life for each creature you control.
	AddEnterTrigger(this, &CDwarvenPriestCard::BeforeGainLife);
}

bool CDwarvenPriestCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), CountCreatures(GetGame(), pAction->GetController()));
	return true;
}

CGallantCavalryCard::CGallantCavalryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gallant Cavalry"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, create a 2/2 white Knight creature token with vigilance.
	AddEnterTrigger(this, &CGallantCavalryCard::BeforeToken);
}

bool CGallantCavalryCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CHeraldOfFaithCard::CHeraldOfFaithCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Herald of Faith"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
{
	// Whenever this creature attacks, you gain 2 life.
	AddSelfAttackTrigger(this, &CHeraldOfFaithCard::BeforeGainLife);
}

bool CHeraldOfFaithCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CKnightOfTheTuskCard::CKnightOfTheTuskCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of the Tusk"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(7))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CLenaSelflessChampionCard::CLenaSelflessChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lena, Selfless Champion"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When Lena enters, create a 1/1 white Soldier creature token for each nontoken creature you control.
	AddEnterTrigger(this, &CLenaSelflessChampionCard::BeforeTokens);

	// Sacrifice Lena: Creatures you control with power less than Lena's power gain indestructible until end of turn.
	// (Lena's last known power)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Creatures with less power gain indestructible. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLenaSelflessChampionCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CLenaSelflessChampionCard::BeforeTokens(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, TRUE, creatures);
	int nCount = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (!creatures.GetAt(i)->GetCardType().IsToken())
			++nCount;

	if (nCount > 0)
		CTokenCreationModifier(GetGame(), SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID, nCount).ApplyTo(pController);
	return true;
}

bool CLenaSelflessChampionCard::BeforeIndestructible(CAbilityAction* pAction)
{
	int nPower = (int)GetLastKnownPower();
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && (int)pCreature->GetPower() < nPower)
			pCreature->GetCardKeyword()->AddIndestructible(TRUE);
	}
	return true;
}

CLeoninVanguardCard::CLeoninVanguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Leonin Vanguard"), CardType::Creature, CREATURE_TYPE2(Cat, Soldier), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// At the beginning of combat on your turn, if you control three or more creatures, this creature gets +1/+1 until
	// end of turn and you gain 1 life.
	AddStepTrigger(this, NodeId::BeginningOfCombatStep, false, &CLeoninVanguardCard::SetTriggerContext, &CLeoninVanguardCard::BeforePump);
}

bool CLeoninVanguardCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return CountCreatures(GetGame(), GetController()) >= 3;
}

bool CLeoninVanguardCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CLeoninWarleaderCard::CLeoninWarleaderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Leonin Warleader"), CardType::Creature, CREATURE_TYPE2(Cat, Soldier), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Whenever this creature attacks, create two 1/1 white Cat creature tokens with lifelink that are tapped and
	// attacking.
	// Partial: the tokens enter tapped but not attacking (a token can't enter the battlefield attacking)
	AddSelfAttackTrigger(this, &CLeoninWarleaderCard::BeforeTokens);
}

bool CLeoninWarleaderCard::BeforeTokens(CAbilityAction* pAction)
{
	CCountedCardContainer tokens;
	CTokenCreationModifier(GetGame(), CAT_G_TOKEN_NAME, CAT_G_TOKEN_ID, 2, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pAction->GetController());
	for (int i = 0; i < tokens.GetSize(); ++i)
		CCardOrientationModifier(TRUE).ApplyTo(tokens.GetAt(i));
	return true;
}

CLoxodonLineBreakerCard::CLoxodonLineBreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loxodon Line Breaker"), CardType::Creature, CREATURE_TYPE2(Elephant, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
}

CMilitiaBuglerCard::CMilitiaBuglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Militia Bugler"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
	, m_SmallCreatureFilter(_T("a creature card with power 2 or less"), _T("creature cards with power 2 or less"),
		new CreaturePowerComparer<std::less_equal<int>>(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, look at the top four cards of your library. You may reveal a creature card with power
	// 2 or less from among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	AddEnterTrigger(this, &CMilitiaBuglerCard::BeforeLook);
}

bool CMilitiaBuglerCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 4, &m_SmallCreatureFilter);
	return true;
}

CNoviceKnightCard::CNoviceKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Novice Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Defender. As long as this creature is enchanted or equipped, it can attack as though it didn't have defender.
	// (it has defender while it isn't enchanted or equipped)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new NotEnchantedOrEquippedComparer),
			Power(+0), Life(+0), CreatureKeyword::Defender));

	AddAbility(cpAbility.GetPointer());
}

CRemorsefulClericCard::CRemorsefulClericCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Remorseful Cleric"), CardType::Creature, CREATURE_TYPE2(Spirit, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Sacrifice this creature: Exile target player's graveyard.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRemorsefulClericCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());
}

bool CRemorsefulClericCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pGraveyard = pPlayer->GetZoneById(ZoneId::Graveyard);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others);
	while (pGraveyard->GetSize() > 0)
	{
		CCard* pCard = pGraveyard->GetAt(pGraveyard->GetSize() - 1);
		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Graveyard)
			break;
	}
	return false;
}

CResplendentAngelCard::CResplendentAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Resplendent Angel"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	{
		// At the beginning of each end step, if you gained 5 or more life this turn, create a 4/4 white Angel creature
		// token with flying and vigilance.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CResplendentAngelCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CResplendentAngelCard::BeforeToken));
		AddAbility(cpAbility.GetPointer());
	}

	// {3}{W}{W}{W}: Until end of turn, this creature gets +2/+2 and gains lifelink.
	AddPumpAbility(this, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, _T("+2/+2 and lifelink. Activates"),
		&CResplendentAngelCard::BeforePump);
}

bool CResplendentAngelCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetController()->GetLifeGainThisTurn() >= Life(5);
}

bool CResplendentAngelCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ANGEL_M_TOKEN_NAME, ANGEL_M_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CResplendentAngelCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		PumpCreature(this, +2, +2);
		GetCardKeyword()->AddLifelink(TRUE);
	}
	return true;
}

CRustwingFalconCard::CRustwingFalconCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rustwing Falcon"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		WHITE_MANA_TEXT, Power(1), Life(2))
{
}

CSerrasGuardianCard::CSerrasGuardianCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Serra's Guardian"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Other creatures you control have vigilance.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+0), Life(+0), CreatureKeyword::Vigilance));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CShieldMareCard::CShieldMareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shield Mare"), CardType::Creature, CREATURE_TYPE(Horse), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
	, m_BlockerFilter(_T("a nonred creature"), _T("nonred creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CardTypeComparer(CardType::Red, false))))
{
	// This creature can't be blocked by red creatures. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);

	// When this creature enters or becomes the target of a spell or ability an opponent controls, you gain 3 life.
	AddEnterTrigger(this, &CShieldMareCard::BeforeGainLife);

	// (as Shapers' Sanctuary in Ixalan)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CShieldMareCard::SetTargetedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShieldMareCard::BeforeGainLife));
	AddAbility(cpAbility.GetPointer());
}

// The spell or ability is controlled by an opponent
bool CShieldMareCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	return pPlayer && pPlayer != GetController();
}

bool CShieldMareCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CSilverbeakGriffinCard::CSilverbeakGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Silverbeak Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
}

CStarCrownedStagCard::CStarCrownedStagCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Star-Crowned Stag"), CardType::Creature, CREATURE_TYPE(Elk), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Whenever this creature attacks, tap target creature defending player controls.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CStarCrownedStagCard::BeforeTap, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CStarCrownedStagCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && !pCard->GetOrientation()->IsTapped())
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
	return false;
}

CTrustyPackbeastCard::CTrustyPackbeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trusty Packbeast"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, return target artifact card from your graveyard to your hand.
	// Note: the card is chosen on resolution (not targeted)
	AddEnterTrigger(this, &CTrustyPackbeastCard::BeforeReturn);
}

bool CTrustyPackbeastCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("artifacts")),
		ZoneId::Hand, MoveType::Others);
	return true;
}

CValiantKnightCard::CValiantKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Valiant Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(4))
{
	// Other Knights you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Knight), 1, CreatureKeyword::Null);

	// {3}{W}{W}: Knights you control gain double strike until end of turn.
	AddPumpAbility(this, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, _T("Knights you control gain double strike. Activates"),
		&CValiantKnightCard::BeforeDoubleStrike);
}

bool CValiantKnightCard::BeforeDoubleStrike(CAbilityAction* pAction)
{
	CCountedCardContainer knights;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Knight), knights);
	for (int i = 0; i < knights.GetSize(); ++i)
		PumpCreature(knights.GetAt(i), +0, +0, CreatureKeyword::DoubleStrike);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

#define BEAST_O_TOKEN_NAME			_T("Beast (O)")
#define BEAST_O_TOKEN_ID			55037
#define ELF_WARRIOR_D_TOKEN_NAME	_T("Elf Warrior (D)")
#define ELF_WARRIOR_D_TOKEN_ID		55052

CAggressiveMammothCard::CAggressiveMammothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aggressive Mammoth"), CardType::Creature, CREATURE_TYPE(Elephant), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(8), Life(8))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Other creatures you control have trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+0), Life(+0), CreatureKeyword::Trample));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CBristlingBoarCard::CBristlingBoarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bristling Boar"), CardType::Creature, CREATURE_TYPE(Boar), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
	// This creature can't be blocked by more than one creature.
	GetCreatureKeyword()->AddCantBeBlockedByMultiple(FALSE);
}

CDruidOfHornsCard::CDruidOfHornsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Druid of Horns"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cast an Aura spell that targets this creature, create a 3/3 green Beast creature token.
	// (when this creature becomes the target of a spell of yours, if the top spell of the stack is an Aura of yours)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDruidOfHornsCard::SetTargetedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDruidOfHornsCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CDruidOfHornsCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	if (!pPlayer || pPlayer != GetController())
		return false;

	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	if (!pTop || !pTop->IsSpell() || !pTop->GetAbility())
		return false;

	CCard* pSpellCard = pTop->GetAbility()->GetCard();
	return pSpellCard && pSpellCard->GetController() == GetController() && (pSpellCard->GetCardType() & CardType::_Aura).Any();
}

bool CDruidOfHornsCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), BEAST_O_TOKEN_NAME, BEAST_O_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CDryadGreenseekerCard::CDryadGreenseekerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dryad Greenseeker"), CardType::Creature, CREATURE_TYPE(Dryad), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3))
{
	// {T}: Look at the top card of your library. If it's a land card, you may reveal it and put it into your hand.
	// Note: if it isn't put into the hand, it goes back on top (LookTopToHand with one card)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Look at the top card of your library. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDryadGreenseekerCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

bool CDryadGreenseekerCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("lands")));
	return true;
}

CElvishClancallerCard::CElvishClancallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elvish Clancaller"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(1), Life(1))
	, m_ClancallerFilter(_T("a card named Elvish Clancaller"), _T("cards named Elvish Clancaller"), new CardNameComparer(_T("Elvish Clancaller")))
{
	// Other Elves you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Elf), 1, CreatureKeyword::Null);

	// {4}{G}{G}, {T}: Search your library for a card named Elvish Clancaller, put it onto the battlefield, then shuffle.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Search for a card named Elvish Clancaller. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CElvishClancallerCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CElvishClancallerCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, &m_ClancallerFilter, FALSE);
	return true;
}

CElvishRejuvenatorCard::CElvishRejuvenatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elvish Rejuvenator"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, look at the top five cards of your library. You may put a land card from among them
	// onto the battlefield tapped. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	AddEnterTrigger(this, &CElvishRejuvenatorCard::BeforeLook);
}

bool CElvishRejuvenatorCard::BeforeLook(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 5,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, CCardFilter::GetFilter(_T("lands")),
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield && !cards.GetAt(i)->GetOrientation()->IsTapped())
			CCardOrientationModifier(TRUE).ApplyTo(cards.GetAt(i));
	return true;
}

CGhastbarkTwinsCard::CGhastbarkTwinsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghastbark Twins"), CardType::Creature, CREATURE_TYPE(Treefolk), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(7))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// This creature can block an additional creature each combat.
	SetMaxBlockingCount(2);
}

CGigantosaurusCard::CGigantosaurusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gigantosaurus"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(10), Life(10))
{
}

CGoreclawTerrorOfQalSismaCard::CGoreclawTerrorOfQalSismaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goreclaw, Terror of Qal Sisma"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Bear), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
	{
		// Creature spells you cast with power 4 or greater cost {2} less to cast.
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)),
				_T("2")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// Whenever Goreclaw attacks, each creature you control with power 4 or greater gets +1/+1 and gains trample until
	// end of turn.
	AddSelfAttackTrigger(this, &CGoreclawTerrorOfQalSismaCard::BeforePump);
}

bool CGoreclawTerrorOfQalSismaCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && (int)pCreature->GetPower() >= 4)
			PumpCreature(pCreature, +1, +1, CreatureKeyword::Trample);
	}
	return true;
}

CGreenwoodSentinelCard::CGreenwoodSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Greenwood Sentinel"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CRhoxOracleCard::CRhoxOracleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rhox Oracle"), CardType::Creature, CREATURE_TYPE2(Rhino, Monk), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(2))
{
	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CRhoxOracleCard::BeforeDraw);
}

bool CRhoxOracleCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSkallaWolfCard::CSkallaWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skalla Wolf"), CardType::Creature, CREATURE_TYPE2(Wolf, Spirit), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
	, m_GreenFilter(_T("a green card"), _T("green cards"), new CardTypeComparer(CardType::Green, false))
{
	// When this creature enters, look at the top five cards of your library. You may reveal a green card from among
	// them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// Note: the rest go to the bottom in any order
	AddEnterTrigger(this, &CSkallaWolfCard::BeforeLook);
}

bool CSkallaWolfCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_GreenFilter);
	return true;
}

CThornLieutenantCard::CThornLieutenantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thorn Lieutenant"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Whenever this creature becomes the target of a spell or ability an opponent controls, create a 1/1 green Elf
	// Warrior creature token. (as Shield Mare)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CThornLieutenantCard::SetTargetedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThornLieutenantCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());

	// {5}{G}: This creature gets +4/+4 until end of turn.
	AddPumpAbility(this, _T("5") GREEN_MANA_TEXT, _T("+4/+4 until end of turn. Activates"), &CThornLieutenantCard::BeforePump);
}

bool CThornLieutenantCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	return pPlayer && pPlayer != GetController();
}

bool CThornLieutenantCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ELF_WARRIOR_D_TOKEN_NAME, ELF_WARRIOR_D_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CThornLieutenantCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +4, +4);
	return true;
}

CUrsineChampionCard::CUrsineChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ursine Champion"), CardType::Creature, CREATURE_TYPE2(Human, Berserker), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {5}{G}: This creature gets +3/+3 and becomes a Bear Berserker until end of turn. Activate only once each turn.
	// Partial: it doesn't become a Bear Berserker
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("5") GREEN_MANA_TEXT));

	cpAbility->SetMaxTurnUsageCount(1);
	cpAbility->SetAbilityText(_T("+3/+3 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUrsineChampionCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CUrsineChampionCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +3, +3);
	return true;
}

CVigilantBalothCard::CVigilantBalothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vigilant Baloth"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CVineMareCard::CVineMareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vine Mare"), CardType::Creature, CREATURE_TYPE2(Elemental, Horse), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(3))
	, m_BlockerFilter(_T("a nonblack creature"), _T("nonblack creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CardTypeComparer(CardType::Black, false))))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);

	// This creature can't be blocked by black creatures. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

CViviensJaguarCard::CViviensJaguarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vivien's Jaguar"), CardType::Creature, CREATURE_TYPE2(Cat, Spirit), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// {2}{G}: Return this card from your graveyard to your hand. Activate only if you control a Vivien planeswalker.
	// (as Jungle Creeper in Rivals of Ixalan)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") GREEN_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CViviensJaguarCard::BeforeReturn));
	AddPlayableIf(this, cpAbility.GetPointer(), &CViviensJaguarCard::HasVivien);
	AddAbility(cpAbility.GetPointer());
}

bool CViviensJaguarCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(this);
	return true;
}

BOOL CViviensJaguarCard::HasVivien(BOOL bIncludeTricks)
{
	CCardFilter vivien(_T("a Vivien planeswalker"), _T("Vivien planeswalkers"), new PlaneswalkerTypeComparer(PlaneswalkerType::Vivien));
	return vivien.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

#define GOBLIN_C_TOKEN_NAME		_T("Goblin (C)")
#define GOBLIN_C_TOKEN_ID		2702

CCatalystElementalCard::CCatalystElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Catalyst Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Sacrifice this creature: Add {R}{R}.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT RED_MANA_TEXT));

	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CDemandingDragonCard::CDemandingDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Demanding Dragon"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(5))
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDemandingDragonCard::OnChoiceSelected))
{
	// When this creature enters, it deals 5 damage to target opponent unless that player sacrifices a creature of their
	// choice. (the opponent chooses, as Torment of Scarabs in Hour of Devastation)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDemandingDragonCard::BeforeChoice));
	AddAbility(cpAbility.GetPointer());
}

bool CDemandingDragonCard::BeforeChoice(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return false;

	if (CountCreatures(GetGame(), pOpponent) == 0)
	{
		DealDamageToPlayer(this, pOpponent, 5);
		return false;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Sacrifice a creature");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText = _T("Demanding Dragon deals 5 damage to you");
		entries.push_back(entry);
	}
	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, NULL, pOpponent);
	return false;
}

void CDemandingDragonCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 1)
				ChooseAndMove(GetGame(), pSelectionPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
					ZoneId::Graveyard, MoveType::Sacrifice);
			else
				DealDamageToPlayer(this, pSelectionPlayer, 5);
			return;
		}
}

CDismissivePyromancerCard::CDismissivePyromancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dismissive Pyromancer"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	{
		// {R}, {T}, Discard a card: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, RED_MANA_TEXT, 1));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{R}, {T}, Sacrifice this creature: It deals 4 damage to target creature.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

CGoblinInstigatorCard::CGoblinInstigatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Instigator"), CardType::Creature, CREATURE_TYPE2(Goblin, Rogue), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, create a 1/1 red Goblin creature token.
	AddEnterTrigger(this, &CGoblinInstigatorCard::BeforeToken);
}

bool CGoblinInstigatorCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), GOBLIN_C_TOKEN_NAME, GOBLIN_C_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CGoblinMotivatorCard::CGoblinMotivatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Motivator"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// {T}: Target creature gains haste until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T(""),
			Power(+0), Life(+0),
			CreatureKeyword::Haste, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CGoblinTrashmasterCard::CGoblinTrashmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Trashmaster"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
	, m_GoblinFilter(_T("a Goblin"), _T("Goblins"), new CreatureTypeComparer(CREATURE_TYPE(Goblin), false))
{
	// Other Goblins you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Goblin), 1, CreatureKeyword::Null);

	// Sacrifice a Goblin: Destroy target artifact.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new CardTypeComparer(CardType::Artifact, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_GoblinFilter);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CHavocDevilsCard::CHavocDevilsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Havoc Devils"), CardType::Creature, CREATURE_TYPE(Devil), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);
}

CHostileMinotaurCard::CHostileMinotaurCard(CGame* pGame, UINT nID)
	: CHasteCreatureCard(pGame, _T("Hostile Minotaur"), CardType::Creature, CREATURE_TYPE(Minotaur), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
}

CInfernoHellionCard::CInfernoHellionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inferno Hellion"), CardType::Creature, CREATURE_TYPE(Hellion), nID,
		_T("3") RED_MANA_TEXT, Power(7), Life(3))
	, m_nCombatTurn(-1)
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	{
		// (remembers the turn this creature attacked or blocked, without triggering)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
							   CWhenSelfAttackedBlocked::EventCallback, &CWhenSelfAttackedBlocked::SetAttackingOrBlockingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CInfernoHellionCard::SetCombatContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each end step, if this creature attacked or blocked this turn, its owner shuffles it into
		// their library.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CInfernoHellionCard::SetEndStepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInfernoHellionCard::BeforeShuffle));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CInfernoHellionCard::SetCombatContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const
{
	m_nCombatTurn = GetGame()->GetGameTurnNumber();
	return false;
}

bool CInfernoHellionCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return m_nCombatTurn == GetGame()->GetGameTurnNumber();
}

bool CInfernoHellionCard::BeforeShuffle(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others).ApplyTo(this);
	if (GetZoneId() == ZoneId::Library)
		pLibrary->Shuffle();
	return true;
}

CKarganDragonriderCard::CKarganDragonriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kargan Dragonrider"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// As long as you control a Dragon, this creature has flying.
	AddAnotherTypeBonus(this, CREATURE_TYPE(Dragon), 0, CreatureKeyword::Flying);
}

CLathlissDragonQueenCard::CLathlissDragonQueenCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Lathliss, Dragon Queen"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Dragon), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(6))
{
	{
		// Whenever another nontoken Dragon you control enters, create a 5/5 red Dragon creature token with flying.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dragon), false));
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::Token, false)));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLathlissDragonQueenCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLathlissDragonQueenCard::BeforeToken));
		AddAbility(cpAbility.GetPointer());
	}

	// {1}{R}: Dragons you control get +1/+0 until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("Dragons you control get +1/+0. Activates"), &CLathlissDragonQueenCard::BeforePump);
}

bool CLathlissDragonQueenCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard != this;
}

bool CLathlissDragonQueenCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), DRAGON_J_TOKEN_NAME, DRAGON_J_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CLathlissDragonQueenCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer dragons;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Dragon), dragons);
	for (int i = 0; i < dragons.GetSize(); ++i)
		PumpCreature(dragons.GetAt(i), +1, +0);
	return true;
}

CLightningMareCard::CLightningMareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lightning Mare"), CardType::Creature, CREATURE_TYPE2(Elemental, Horse), nID,
		RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(1))
	, m_BlockerFilter(_T("a nonblue creature"), _T("nonblue creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CardTypeComparer(CardType::Blue, false))))
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// This creature can't be blocked by blue creatures. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);

	// {1}{R}: This creature gets +1/+0 until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("+1/+0 until end of turn. Activates"), &CLightningMareCard::BeforePump);
}

bool CLightningMareCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +0);
	return true;
}

COnakkeOgreCard::COnakkeOgreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Onakke Ogre"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(4), Life(2))
{
}

CSarkhansWhelpCard::CSarkhansWhelpCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sarkhan's Whelp"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you activate an ability of a Sarkhan planeswalker, this creature deals 1 damage to any target.
	// Not implemented: there is no event for activating an ability
}

CSiegebreakerGiantCard::CSiegebreakerGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Siegebreaker Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Warrior), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// {3}{R}: Target creature can't block this turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("3") RED_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::CantBlock, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CSparktongueDragonCard::CSparktongueDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sparktongue Dragon"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you may pay {2}{R}. When you do, it deals 3 damage to any target.
	// (an optional trigger with a resolution cost, as Cloven Casting; it can't target planeswalkers)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T("2") RED_MANA_TEXT);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSparktongueDragonCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CSparktongueDragonCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 3);
	return false;
}

CViashinoPyromancerCard::CViashinoPyromancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Viashino Pyromancer"), CardType::Creature, CREATURE_TYPE2(Lizard, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters, it deals 2 damage to target player or planeswalker.
	// (the damage to a planeswalker removes loyalty counters)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Planeswalker, false));
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CViashinoPyromancerCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CViashinoPyromancerCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		DealDamageToPlayer(this, pPlayer, 2);
		return false;
	}

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(LOYALTY_COUNTER, -2).ApplyTo(pCard);
	return false;
}

CVolleyVeteranCard::CVolleyVeteranCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Volley Veteran"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(2))
{
	// When this creature enters, it deals damage to target creature an opponent controls equal to the number of
	// Goblins you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CVolleyVeteranCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CVolleyVeteranCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	int nGoblins = CountType(pAction->GetController(), CREATURE_TYPE(Goblin));
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && nGoblins > 0)
		DealDamageToCreature(this, pCard, nGoblins);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

CArisenGorgonCard::CArisenGorgonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Arisen Gorgon"), CardType::Creature, CREATURE_TYPE2(Zombie, Gorgon), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// This creature has deathtouch as long as you control a Liliana planeswalker. (as Court Cleric)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0)));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Liliana));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CBogstomperCard::CBogstomperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bogstomper"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(5))
{
}

CBoneDragonCard::CBoneDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bone Dragon"), CardType::Creature, CREATURE_TYPE2(Dragon, Skeleton), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(4))
	, m_OtherCardsFilter(_T("another card"), _T("other cards"), new NegateCardComparer(new SpecificCardComparer(this)))
{
	// {3}{B}{B}, Exile seven other cards from your graveyard: Return this card from your graveyard to the battlefield
	// tapped. (as Jungle Creeper in Rivals of Ixalan, with the exile cost of Scavenge)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->GetCost().AddExileGraveyardCardCost(7, &m_OtherCardsFilter);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to the battlefield tapped. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBoneDragonCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CBoneDragonCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others);
		pModifier.SetTapped(TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CDemonOfCatastrophesCard::CDemonOfCatastrophesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Demon of Catastrophes"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(6))
{
	// As an additional cost to cast this spell, sacrifice a creature.
	GetSpells().GetAt(0)->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));

	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);
}

CEpicureOfBloodCard::CEpicureOfBloodCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Epicure of Blood"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("4") BLACK_MANA_TEXT, Power(4), Life(4))
{
	// Whenever you gain life, each opponent loses 1 life. (as Famished Paladin in Rivals of Ixalan)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEpicureOfBloodCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEpicureOfBloodCard::BeforeLoseLife));
	AddAbility(cpAbility.GetPointer());
}

bool CEpicureOfBloodCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

bool CEpicureOfBloodCard::BeforeLoseLife(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, FALSE);
	return true;
}

CFellSpecterCard::CFellSpecterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Fell Specter"), CardType::Creature, CREATURE_TYPE(Specter), nID,
		_T("3") BLACK_MANA_TEXT, Power(1), Life(3))
{
	{
		// When this creature enters, target opponent discards a card.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFellSpecterCard::BeforeDiscard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever an opponent discards a card, that player loses 2 life. (the player in nValue1)
		counted_ptr<DiscardAbility> cpAbility(::CreateObject<DiscardAbility>(this));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(DiscardAbility::OptionalType::Required);
		cpAbility->SetContextFunction(DiscardAbility::ContextFunction(this, &CFellSpecterCard::SetDiscardContext));
		cpAbility->SetBeforeResolveSelectionCallback(DiscardAbility::BeforeResolveSelectionCallback(this, &CFellSpecterCard::BeforeLoseLife));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFellSpecterCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);
	return false;
}

bool CFellSpecterCard::SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	triggerContext.nValue1 = (DWORD)pPlayer;
	return pPlayer != NULL;
}

bool CFellSpecterCard::BeforeLoseLife(DiscardAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (pPlayer)
		CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	return true;
}

CGravewakerCard::CGravewakerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Gravewaker"), CardType::Creature, CREATURE_TYPE2(Bird, Spirit), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(5))
{
	// {5}{B}{B}: Return target creature card from your graveyard to the battlefield tapped.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGravewakerCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

// (the card is moved here, tapped)
bool CGravewakerCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others);
		pModifier.SetTapped(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CGraveyardMarshalCard::CGraveyardMarshalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Graveyard Marshal"), CardType::Creature, CREATURE_TYPE2(Zombie, Soldier), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(2))
{
	// {2}{B}, Exile a creature card from your graveyard: Create a tapped 2/2 black Zombie creature token.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") BLACK_MANA_TEXT));

	cpAbility->GetCost().AddExileGraveyardCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetAbilityText(_T("Create a tapped 2/2 black Zombie creature token. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGraveyardMarshalCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CGraveyardMarshalCard::BeforeToken(CAbilityAction* pAction)
{
	CCountedCardContainer tokens;
	CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, 1, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pAction->GetController());
	for (int i = 0; i < tokens.GetSize(); ++i)
		CCardOrientationModifier(TRUE).ApplyTo(tokens.GetAt(i));
	return true;
}

CHiredBladeCard::CHiredBladeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hired Blade"), CardType::Creature, CREATURE_TYPE2(Human, Assassin), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);
}

CIsarethTheAwakenerCard::CIsarethTheAwakenerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Isareth the Awakener"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Whenever Isareth attacks, you may pay {X}. When you do, return target creature card with mana value X from your
	// graveyard to the battlefield with a corpse counter on it. If that creature would leave the battlefield, exile it
	// instead of putting it anywhere else.
	// Not implemented: a triggered ability can't have a variable payment, and there are no replacement effects on
	// leaving the battlefield
}

CPlagueMareCard::CPlagueMareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Plague Mare"), CardType::Creature, CREATURE_TYPE2(Nightmare, Horse), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
	, m_BlockerFilter(_T("a nonwhite creature"), _T("nonwhite creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CardTypeComparer(CardType::White, false))))
{
	// This creature can't be blocked by white creatures. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);

	// When this creature enters, creatures your opponents control get -1/-1 until end of turn.
	AddEnterTrigger(this, &CPlagueMareCard::BeforeShrink);
}

bool CPlagueMareCard::BeforeShrink(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), -1, -1);
	return true;
}

CRavenousHarpyCard::CRavenousHarpyCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Ravenous Harpy"), CardType::Creature, CREATURE_TYPE(Harpy), nID,
		_T("2") BLACK_MANA_TEXT, Power(1), Life(2))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// {1}, Sacrifice another creature: Put a +1/+1 counter on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRavenousHarpyCard::BeforeCounter));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CRavenousHarpyCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
	return true;
}

CSkeletonArcherCard::CSkeletonArcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skeleton Archer"), CardType::Creature, CREATURE_TYPE2(Skeleton, Archer), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, it deals 1 damage to any target.
	// Note: it can't target planeswalkers
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CSkeletonArcherCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->SetIncludePlayers(TRUE);
}

bool CSkeletonArcherCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 1);
	return false;
}

CStitchersSupplierCard::CStitchersSupplierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stitcher's Supplier"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters or dies, mill three cards.
	AddEnterTrigger(this, &CStitchersSupplierCard::BeforeMill);
	AddDiesTrigger(this, &CStitchersSupplierCard::BeforeMill);
}

bool CStitchersSupplierCard::BeforeMill(CAbilityAction* pAction)
{
	Mill(pAction->GetController(), 3);
	return true;
}

CTwoHeadedZombieCard::CTwoHeadedZombieCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Two-Headed Zombie"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CVampireNeonateCard::CVampireNeonateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vampire Neonate"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		BLACK_MANA_TEXT, Power(0), Life(3))
{
	// {2}, {T}: Each opponent loses 1 life and you gain 1 life.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Each opponent loses 1 life and you gain 1 life. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVampireNeonateCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CVampireNeonateCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, TRUE);
	return true;
}

CVampireSovereignCard::CVampireSovereignCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vampire Sovereign"), CardType::Creature, CREATURE_TYPE2(Vampire, Noble), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, target opponent loses 3 life and you gain 3 life.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVampireSovereignCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CVampireSovereignCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	GainLife(this, pAction->GetController(), 3);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

CAvenWindMageCard::CAvenWindMageCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Wind Mage"), CardType::Creature, CREATURE_TYPE2(Bird, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast an instant or sorcery spell, this creature gets +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAvenWindMageCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CAvenWindMageCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

CAviationPioneerCard::CAviationPioneerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aviation Pioneer"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, create a 1/1 colorless Thopter artifact creature token with flying.
	AddEnterTrigger(this, &CAviationPioneerCard::BeforeToken);
}

bool CAviationPioneerCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), THOPTER_D_TOKEN_NAME, THOPTER_D_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CDepartedDeckhandCard::CDepartedDeckhandCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Departed Deckhand"), CardType::Creature, CREATURE_TYPE2(Spirit, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_SpiritFilter(_T("a Spirit"), _T("Spirits"), new CreatureTypeComparer(CREATURE_TYPE(Spirit), false))
{
	{
		// When this creature becomes the target of a spell, sacrifice it.
		// (the top of the stack is a spell, as Druid of Horns)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
							   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDepartedDeckhandCard::SetTargetedContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDepartedDeckhandCard::BeforeSacrifice));
		AddAbility(cpAbility.GetPointer());
	}

	// This creature can't be blocked except by Spirits. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_SpiritFilter);

	{
		// {3}{U}: Another target creature you control can't be blocked this turn except by Spirits.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("3") BLUE_MANA_TEXT,
				new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))), FALSE));

		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDepartedDeckhandCard::BeforeEvasion));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDepartedDeckhandCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	return pTop && pTop->IsSpell();
}

bool CDepartedDeckhandCard::BeforeSacrifice(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice).ApplyTo(this);
	return true;
}

bool CDepartedDeckhandCard::BeforeEvasion(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		pCreature->GetCreatureKeyword()->AddUnblockable(TRUE, &m_SpiritFilter);
	return false;
}

CExclusionMageCard::CExclusionMageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Exclusion Mage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, return target creature an opponent controls to its owner's hand.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CExclusionMageCard::BeforeBounce, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CExclusionMageCard::BeforeBounce(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(pCard);
	return false;
}

CFrilledSeaSerpentCard::CFrilledSeaSerpentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frilled Sea Serpent"), CardType::Creature, CREATURE_TYPE(Serpent), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(6))
{
	// {5}{U}{U}: This creature can't be blocked this turn.
	AddPumpAbility(this, _T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, _T("Can't be blocked this turn. Activates"),
		&CFrilledSeaSerpentCard::BeforeUnblockable);
}

bool CFrilledSeaSerpentCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

CGearsmithProdigyCard::CGearsmithProdigyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gearsmith Prodigy"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		BLUE_MANA_TEXT, Power(1), Life(2))
{
	// This creature gets +1/+0 as long as you control an artifact.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+0)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CMysticArchaeologistCard::CMysticArchaeologistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mystic Archaeologist"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// {3}{U}{U}: Draw two cards.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, 2));

	AddAbility(cpAbility.GetPointer());
}

CRiddlemasterSphinxCard::CRiddlemasterSphinxCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Riddlemaster Sphinx"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(5))
{
	// When this creature enters, you may return target creature an opponent controls to its owner's hand.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CRiddlemasterSphinxCard::BeforeBounce, true, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CRiddlemasterSphinxCard::BeforeBounce(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(pCard);
	return false;
}

CSaiMasterThopteristCard::CSaiMasterThopteristCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sai, Master Thopterist"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
{
	{
		// Whenever you cast an artifact spell, create a 1/1 colorless Thopter artifact creature token with flying.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaiMasterThopteristCard::BeforeToken));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{U}, Sacrifice two artifacts: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("1") BLUE_MANA_TEXT, 1));

		cpAbility->GetCost().AddSacrificeCardCost(2, CCardFilter::GetFilter(_T("artifacts")));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSaiMasterThopteristCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), THOPTER_D_TOKEN_NAME, THOPTER_D_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CSalvagerOfSecretsCard::CSalvagerOfSecretsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Salvager of Secrets"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, return target instant or sorcery card from your graveyard to your hand.
	// Note: the card is chosen on resolution (not targeted)
	AddEnterTrigger(this, &CSalvagerOfSecretsCard::BeforeReturn);
}

bool CSalvagerOfSecretsCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1,
		CCardFilter::GetFilter(_T("instant cards or sorcery cards")), ZoneId::Hand, MoveType::Others);
	return true;
}

CScholarOfStarsCard::CScholarOfStarsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scholar of Stars"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, if you control an artifact, draw a card.
	AddEnterIfTrigger(this, &CScholarOfStarsCard::SetTriggerContext, &CScholarOfStarsCard::BeforeDraw);
}

bool CScholarOfStarsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

bool CScholarOfStarsCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSkilledAnimatorCard::CSkilledAnimatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skilled Animator"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(3))
	, m_pAnimated(NULL)
{
	// When this creature enters, target artifact you control becomes an artifact creature with base power and
	// toughness 5/5 for as long as this creature remains on the battlefield. (Animated Artifact (A), as The Antiquities
	// War in Dominaria; the animation is removed when this creature leaves the battlefield)
	// Partial: an artifact that is already a creature doesn't change
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkilledAnimatorCard::BeforeAnimate));
	AddAbility(cpAbility.GetPointer());

	AddLeaveTrigger(this, &CSkilledAnimatorCard::BeforeRemove);
}

bool CSkilledAnimatorCard::BeforeAnimate(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || GetZoneId() != ZoneId::Battlefield ||
		pCard->GetCardType().IsCreature() || pCard->GetIsAlsoA() || m_apAnimate.get())
		return false;

	m_apAnimate.reset(new CCardIsAlsoAModifier(ANIMATED_ARTIFACT_A_TOKEN_NAME, ANIMATED_ARTIFACT_A_TOKEN_ID, pAction->GetController()));
	m_apAnimate->ApplyTo(pCard);
	m_pAnimated = pCard;
	return false;
}

bool CSkilledAnimatorCard::BeforeRemove(CAbilityAction* pAction)
{
	if (m_apAnimate.get() && m_pAnimated && m_pAnimated->GetZoneId() == ZoneId::Battlefield)
		m_apAnimate->RemoveFrom(m_pAnimated);
	m_apAnimate.reset();
	m_pAnimated = NULL;
	return true;
}

CSupremePhantomCard::CSupremePhantomCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Supreme Phantom"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// Other Spirits you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Spirit), 1, CreatureKeyword::Null);
}

CSurgeMareCard::CSurgeMareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Surge Mare"), CardType::Creature, CREATURE_TYPE2(Horse, Fish), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(0), Life(5))
	, m_BlockerFilter(_T("a nongreen creature"), _T("nongreen creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CardTypeComparer(CardType::Green, false))))
{
	// This creature can't be blocked by green creatures. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);

	{
		// Whenever this creature deals damage to an opponent, you may draw a card. If you do, discard a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSurgeMareCard::SetDamageContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSurgeMareCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}

	// {1}{U}: This creature gets +2/-2 until end of turn.
	AddPumpAbility(this, _T("1") BLUE_MANA_TEXT, _T("+2/-2 until end of turn. Activates"), &CSurgeMareCard::BeforePump);
}

bool CSurgeMareCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	return pPlayer && pPlayer != GetController();
}

bool CSurgeMareCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

bool CSurgeMareCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, -2);
	return true;
}

CWallOfMistCard::CWallOfMistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wall of Mist"), CardType::Creature, CREATURE_TYPE(Wall), nID,
		_T("1") BLUE_MANA_TEXT, Power(0), Life(5))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

CAerialEngineerCard::CAerialEngineerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aerial Engineer"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(4))
{
	// As long as you control an artifact, this creature gets +2/+0 and has flying. (as Gearsmith Prodigy)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+2), Life(+0), CreatureKeyword::Flying));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CArcadesTheStrategistCard::CArcadesTheStrategistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Arcades, the Strategist"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dragon), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(5))
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Whenever a creature you control with defender enters, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureKeywordComparer(CreatureKeyword::Defender, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArcadesTheStrategistCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());

	// Each creature you control with defender assigns combat damage equal to its toughness rather than its power and
	// can attack as though it didn't have defender.
	// Not implemented: there is no combat damage by toughness, and defender can't be ignored
}

bool CArcadesTheStrategistCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CBrawlBashOgreCard::CBrawlBashOgreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brawl-Bash Ogre"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Whenever this creature attacks, you may sacrifice another creature. If you do, this creature gets +2/+2 until end
	// of turn.
	AddSelfAttackTrigger(this, &CBrawlBashOgreCard::BeforeSacrifice, true);
}

bool CBrawlBashOgreCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nBefore = CountCreatures(GetGame(), pController);
	if (m_OtherCreatureFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 1, 1, &m_OtherCreatureFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	if (CountCreatures(GetGame(), pController) < nBefore && GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +2);
	return true;
}

CChromiumTheMutableCard::CChromiumTheMutableCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Chromium, the Mutable"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dragon), nID,
		_T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(7), Life(7))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Discard a card: Until end of turn, Chromium becomes a Human with base power and toughness 1/1, loses all abilities,
	// and gains hexproof. It can't be blocked this turn.
	// Partial: it becomes 1/1 (a -X/-Y change, as Warkite Marauder), gains hexproof and can't be blocked, but it doesn't
	// become a Human nor lose its abilities
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetAbilityText(_T("1/1 with hexproof, can't be blocked this turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChromiumTheMutableCard::BeforeChange));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CChromiumTheMutableCard::BeforeChange(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(this, 1 - (int)GetPower(), 1 - (int)GetToughness());
	GetCardKeyword()->AddHexproof(TRUE);
	GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

CDiamondMareCard::CDiamondMareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Diamond Mare"), CardType::_ArtifactCreature, CREATURE_TYPE(Horse), nID,
		_T("2"), Power(1), Life(3))
	, m_ColorSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDiamondMareCard::OnColorSelected))
	, m_dwChosenColor(0)
{
	// As this creature enters, choose a color.
	// Note: the color is chosen by a trigger when it enters
	AddEnterTrigger(this, &CDiamondMareCard::BeforeChoose);

	// Whenever you cast a spell of the chosen color, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDiamondMareCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDiamondMareCard::BeforeGainLife));
	AddAbility(cpAbility.GetPointer());
}

bool CDiamondMareCard::BeforeChoose(CAbilityAction* pAction)
{
	static const CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	static LPCTSTR names[] = { _T("white"), _T("blue"), _T("black"), _T("red"), _T("green") };

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 5; ++i)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)i;
		entry.strText.Format(_T("Choose %s"), names[i]);
		entries.push_back(entry);
	}
	m_ColorSelection.AddSelectionRequest(entries, 1, 1, NULL, pAction->GetController());
	return true;
}

void CDiamondMareCard::OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			m_dwChosenColor = it->dwContext + 1;	// 1..5, 0 is "not chosen"
}

bool CDiamondMareCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	static const CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	if (!pCard || m_dwChosenColor == 0 || m_dwChosenColor > 5)
		return false;

	return (pCard->GetCardType() & colors[m_dwChosenColor - 1]).Any();
}

bool CDiamondMareCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CDraconicDiscipleCard::CDraconicDiscipleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Draconic Disciple"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);

	// {7}, {T}, Sacrifice this creature: Create a 5/5 red Dragon creature token with flying.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("7"),
			DRAGON_J_TOKEN_NAME, DRAGON_J_TOKEN_ID, 1));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CGearsmithGuardianCard::CGearsmithGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gearsmith Guardian"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("5"), Power(3), Life(5))
{
	// This creature gets +2/+0 as long as you control a blue creature.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+2), Life(+0)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Blue, false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CMeteorGolemCard::CMeteorGolemCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Meteor Golem"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("7"), Power(3), Life(3))
{
	// When this creature enters, destroy target nonland permanent an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMeteorGolemCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CMeteorGolemCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy).ApplyTo(pCard);
	return false;
}

CPalladiaMorsTheRuinerCard::CPalladiaMorsTheRuinerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Palladia-Mors, the Ruiner"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dragon), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(6), Life(6))
{
	// Flying, vigilance, trample
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// Palladia-Mors has hexproof as long as it hasn't dealt damage yet.
	// (it has hexproof, and the damage triggers remove it without using the stack)
	// Partial: it doesn't get hexproof back if it leaves and returns to the battlefield
	GetCardKeyword()->AddHexproof(FALSE);
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::CreatureEventCallback,
							   &CWhenSelfDamageDealt::SetCreatureEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPalladiaMorsTheRuinerCard::SetCreatureDamageContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPalladiaMorsTheRuinerCard::SetPlayerDamageContext));
		AddAbility(cpAbility.GetPointer());
	}
}

void CPalladiaMorsTheRuinerCard::LoseHexproof() const
{
	CCardKeyword* pKeyword = const_cast<CPalladiaMorsTheRuinerCard*>(this)->GetCardKeyword();
	if (pKeyword->HasHexproof())
		pKeyword->RemoveHexproof(FALSE);
}

bool CPalladiaMorsTheRuinerCard::SetCreatureDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, Damage damage) const
{
	LoseHexproof();
	return false;
}

bool CPalladiaMorsTheRuinerCard::SetPlayerDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, Damage damage) const
{
	LoseHexproof();
	return false;
}

CPoisonTipArcherCard::CPoisonTipArcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Poison-Tip Archer"), CardType::Creature, CREATURE_TYPE2(Elf, Archer), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Reach, deathtouch
	GetCreatureKeyword()->AddReach(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Whenever another creature dies, each opponent loses 1 life. (as Elenda in Rivals of Ixalan)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPoisonTipArcherCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPoisonTipArcherCard::BeforeLoseLife));
	AddAbility(cpAbility.GetPointer());
}

bool CPoisonTipArcherCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard != this;
}

bool CPoisonTipArcherCard::BeforeLoseLife(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, FALSE);
	return true;
}

CPsychicSymbiontCard::CPsychicSymbiontCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Psychic Symbiont"), CardType::Creature, CREATURE_TYPE2(Nightmare, Horror), nID,
		_T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, target opponent discards a card and you draw a card.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPsychicSymbiontCard::BeforeDiscard));
	AddAbility(cpAbility.GetPointer());
}

bool CPsychicSymbiontCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

CRegalBloodlordCard::CRegalBloodlordCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Regal Bloodlord"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(4))
{
	// At the beginning of each end step, if you gained life this turn, create a 1/1 black Bat creature token with
	// flying. (as Resplendent Angel)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRegalBloodlordCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRegalBloodlordCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CRegalBloodlordCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetController()->GetLifeGainThisTurn() > Life(0);
}

bool CRegalBloodlordCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), BAT_A_TOKEN_NAME, BAT_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

CSatyrEnchanterCard::CSatyrEnchanterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Satyr Enchanter"), CardType::Creature, CREATURE_TYPE2(Satyr, Druid), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast an enchantment spell, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Enchantment, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSatyrEnchanterCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CSatyrEnchanterCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSkyriderPatrolCard::CSkyriderPatrolCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skyrider Patrol"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// At the beginning of combat on your turn, you may pay {G}{U}. When you do, put a +1/+1 counter on another target
	// creature you control, and that creature gains flying until end of turn. (an optional trigger with a resolution
	// cost, as Sparktongue Dragon)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(GREEN_MANA_TEXT BLUE_MANA_TEXT);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkyriderPatrolCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CSkyriderPatrolCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(pCard);
		PumpCreature(pCard, +0, +0, CreatureKeyword::Flying);
	}
	return false;
}

CSkyscannerCard::CSkyscannerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skyscanner"), CardType::_ArtifactCreature, CREATURE_TYPE(Thopter), nID,
		_T("3"), Power(1), Life(1))
{
	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CSkyscannerCard::BeforeDraw);
}

bool CSkyscannerCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSuspiciousBookcaseCard::CSuspiciousBookcaseCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Suspicious Bookcase"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("2"), Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {3}, {T}: Target creature can't be blocked this turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("3"),
			Power(+0), Life(+0),
			CreatureKeyword::Unblockable, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CTezzeretsStriderCard::CTezzeretsStriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tezzeret's Strider"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("3"), Power(3), Life(1))
{
	// As long as you control a Tezzeret planeswalker, this creature has menace.
	AddPlaneswalkerBonus(this, PlaneswalkerType::Tezzeret, 0, CreatureKeyword::CantBeBlockedBy1);
}

CVaevictisAsmadiTheDireCard::CVaevictisAsmadiTheDireCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vaevictis Asmadi, the Dire"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elder, Dragon), nID,
		_T("3") BLACK_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Whenever Vaevictis Asmadi attacks, for each player, choose target permanent that player controls. Those players
	// sacrifice those permanents. Each player who sacrificed a permanent this way reveals the top card of their
	// library, then puts it onto the battlefield if it's a permanent card.
	// Not implemented: a trigger can't have one target for each player
}

//____________________________________________________________________________
//
