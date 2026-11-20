#include "stdafx.h"
#include "CardRavnicaAllegiance.h"

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
#define AVATAR_A_TOKEN_NAME		_T("Avatar (A)")
#define AVATAR_A_TOKEN_ID		55115
#define ZOMBIE_P_TOKEN_NAME		_T("Zombie (P)")
#define ZOMBIE_P_TOKEN_ID		55009
#define BAT_A_TOKEN_NAME		_T("Bat (A)")
#define BAT_A_TOKEN_ID			2803
#define OX_A_TOKEN_NAME			_T("Ox (A)")
#define OX_A_TOKEN_ID			55116
#define GOLD_COUNTER			_T("gold counter")
#define CAT_G_TOKEN_NAME		_T("Cat (G)")
#define CAT_G_TOKEN_ID			55098
#define ANGEL_M_TOKEN_NAME		_T("Angel (M)")
#define ANGEL_M_TOKEN_ID		55117
#define BEAST_O_TOKEN_NAME			_T("Beast (O)")
#define BEAST_O_TOKEN_ID			55037
#define ELF_WARRIOR_D_TOKEN_NAME	_T("Elf Warrior (D)")
#define ELF_WARRIOR_D_TOKEN_ID		55052
#define GOBLIN_C_TOKEN_NAME		_T("Goblin (C)")
#define GOBLIN_C_TOKEN_ID		2702
#define RAL_IZZET_VICEROY_EMBLEM_NAME		_T("Ral, Izzet Viceroy Emblem")
#define RAL_IZZET_VICEROY_EMBLEM_ID			61158
#define VRASKA_GOLGARI_QUEEN_EMBLEM_NAME	_T("Vraska, Golgari Queen Emblem")
#define VRASKA_GOLGARI_QUEEN_EMBLEM_ID		61159

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

// The creatures of a type that pPlayer controls
static void GetCreaturesOfType(CGame* pGame, CPlayer* pPlayer, const CreatureType& type, CCountedCardContainer& creatures)
{
	CCountedCardContainer all;
	GetCreatures(pGame, pPlayer, TRUE, all);
	for (int i = 0; i < all.GetSize(); ++i)
		if (CreatureTypeComparer(type, false)(all.GetAt(i)))
			creatures.AddCard(all.GetAt(i), CardPlacement::Top);
}

// The cost of a spell: nGeneric generic mana plus the colored part ("" when there's no generic mana left, as Aether Revolt)
static CString MakeCost(int nGeneric, LPCTSTR strColored)
{
	CString strCost;
	if (nGeneric > 0)
		strCost.Format(_T("%d"), nGeneric);
	strCost += strColored;
	return strCost.IsEmpty() ? CString(_T("0")) : strCost;	// a free spell costs {0} (as Lotus Petal)
}

// Convoke (Your creatures can help cast this spell. Each creature you tap while casting this spell pays for {1} or one
// mana of that creature's color.)
// As Improvise in Aether Revolt (and Delve in Khans of Tarkir): besides the normal spell, the card gets one spell for each
// number of creatures that can be tapped, with that much less generic mana and the cost "tap N untapped creatures you
// control". The creatures pay only generic mana (the colored mana is paid with mana).
// addSpell(strCost, nTapped) creates the spell with that cost, calls SetConvoke(spell, nTapped) and adds it. A creature
// already has its main spell (nTapped = 0), so it starts with nFirst = 1.
template <class T>
static void AddConvokeSpells(T* pCard, int nGeneric, LPCTSTR strColored, void (T::*addSpell)(LPCTSTR, int), int nFirst = 0)
{
	for (int nTapped = nFirst; nTapped <= nGeneric; ++nTapped)
		(pCard->*addSpell)(MakeCost(nGeneric - nTapped, strColored), nTapped);
}

static void SetConvoke(CSpell* pSpell, int nTapped)
{
	if (nTapped <= 0)
		return;

	pSpell->GetCost().AddTapCardCost(nTapped, CCardFilter::GetFilter(_T("creatures")));
	pSpell->SetMainSpell(FALSE);
}

// Jump-start (You may cast this card from your graveyard by discarding a card in addition to paying its other costs. Then
// exile this card.)
// As Flashback (Deep Analysis in Torment): a second spell with the same mana cost and the discard cost, cast only from the
// graveyard; its name "Flashback" makes the stack exile the card when it leaves the stack.
static void SetJumpStart(CSpell* pSpell)
{
	pSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	pSpell->SetAbilityName(_T("Flashback"));
	pSpell->SetAbilityText(_T("Jump-start. Casts"));
	pSpell->SetGraveyardOnly();
	pSpell->SetMainSpell(FALSE);
}

// Undergrowth: the number of creature cards in pPlayer's graveyard
static int CountCreatureCardsInGraveyard(CPlayer* pPlayer)
{
	return CCardFilter::GetFilter(_T("creatures"))->CountIncluded(pPlayer->GetZoneById(ZoneId::Graveyard)->GetCardContainer());
}

// "Whenever you surveil, ..." (as AddWheneverYouExertTrigger in Hour of Devastation): CSurveilModifier fires
// SURVEIL_TRIGGER_ID on its source card, and this trigger listens for it on the cards you control.
template <class T>
static void AddWheneverYouSurveilTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional = false)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetTriggerIndex(SURVEIL_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(pCard));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);
	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// Hybrid mana (as Alara Reborn): every cost for nHybrid symbols {C1/C2} after the generic part, one per combination
static void GetHybridCosts(LPCTSTR strGeneric, int nHybrid, LPCTSTR strColor1, LPCTSTR strColor2, std::vector<CString>& costs)
{
	for (int nFirst = nHybrid; nFirst >= 0; --nFirst)
	{
		CString strCost = strGeneric;
		for (int i = 0; i < nFirst; ++i)
			strCost += strColor1;
		for (int i = nFirst; i < nHybrid; ++i)
			strCost += strColor2;
		costs.push_back(strCost);
	}
}

// Each opponent of pPlayer
static void GetOpponents(CGame* pGame, CPlayer* pPlayer, std::vector<CPlayer*>& opponents)
{
	for (int i = 0; i < pGame->GetPlayerCount(); ++i)
		if (pGame->GetPlayer(i) != pPlayer)
			opponents.push_back(pGame->GetPlayer(i));
}

// All creatures get +N/+N until end of turn
static void PumpAllCreatures(CGame* pGame, int nPower, int nToughness)
{
	for (int i = 0; i < pGame->GetPlayerCount(); ++i)
		PumpCreatures(pGame, pGame->GetPlayer(i), nPower, nToughness);
}

// An instant without targets (the callback does the effect)
template <class T>
static CGenericSpell* AddInstant(T* pCard, LPCTSTR strCost, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(pCard, AbilityType::Instant, strCost));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// An instant that moves target permanent (destroy, exile, bounce)
static CTargetMoveCardSpell* AddMoveInstant(CCard* pCard, LPCTSTR strCost, CardComparer* pComparer, ZoneId toZone, MoveType moveType)
{
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(pCard, AbilityType::Instant,
			strCost,
			pComparer,
			ZoneId::Battlefield, toZone, TRUE, moveType));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A damage instant
static CTargetChgLifeSpell* AddDamageInstant(CCard* pCard, LPCTSTR strCost, int nDamage, CardComparer* pComparer, BOOL bPlayers)
{
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(pCard, AbilityType::Instant,
			strCost,
			pComparer, bPlayers,
			Life(-nDamage), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// A pump instant (+P/+T and a keyword until end of turn)
static CTargetChgPwrTghAttrSpell* AddPumpInstant(CCard* pCard, LPCTSTR strCost, int nPower, int nToughness,
	CreatureKeyword keyword = CreatureKeyword::Null)
{
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(pCard, AbilityType::Instant,
			strCost,
			Power(nPower), Life(nToughness),
			keyword, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(nPower < 0 || nToughness < 0 ? Characteristic::Negative : Characteristic::Positive);
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

// The name and text of one half of a split card
static void SetSplitHalf(CSpell* pSpell, LPCTSTR strName)
{
	CString strText;
	strText.Format(_T("%s. Casts"), strName);
	pSpell->SetAbilityText(strText);
	pSpell->SetAbilityName(strName);
}

// Returns the creature to its owner's hand
static void BounceCreature(CCard* pCard)
{
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(pCard);
}

// Convoke in a permanent that already has its main spell (nTapped = 0): one more spell for each number of creatures
// tapped, from 1 to nGeneric (partial: the creatures pay only generic mana). If a callback is given, it's the resolution
// callback of those spells (it can read the tapped creatures with pAction->GetCostConfigEntry().GetTapCards()).
template <class T>
static void AddPermanentConvoke(T* pCard, int nGeneric, LPCTSTR strColored, bool (T::*callback)(CAbilityAction*) = NULL)
{
	for (int nTapped = 1; nTapped <= nGeneric; ++nTapped)
	{
		counted_ptr<CSpell> cpSpell(::CreateObject<CSpell>(pCard, pCard->GetSpells().GetAt(0)->GetAbilityType(),
			MakeCost(nGeneric - nTapped, strColored), TRUE));
		SetConvoke(cpSpell.GetPointer(), nTapped);
		if (callback)
			cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
		pCard->AddSpell(cpSpell.GetPointer());
	}
}

// The number of attacking creatures pPlayer controls
static int CountAttackingCreatures(CGame* pGame, CPlayer* pPlayer)
{
	CCountedCardContainer creatures;
	GetCreatures(pGame, pPlayer, TRUE, creatures);
	AttackingCreatureComparer attacking;
	int nCount = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (attacking(creatures.GetAt(i)))
			++nCount;
	return nCount;
}

// "Whenever you cast an instant or sorcery spell, <effect>"
template <class T>
static void AddInstantSorceryCastTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// Hybrid mana in a permanent (as Alara Reborn): the main spell has the first combination (all strColor1); this adds one
// more spell for each other combination of the nHybrid symbols {C1/C2}
static void AddHybridPermanentSpells(CCard* pCard, LPCTSTR strGeneric, int nHybrid, LPCTSTR strColor1, LPCTSTR strColor2)
{
	std::vector<CString> costs;
	GetHybridCosts(strGeneric, nHybrid, strColor1, strColor2, costs);
	for (size_t i = 1; i < costs.size(); ++i)
	{
		counted_ptr<CSpell> cpSpell(::CreateObject<CSpell>(pCard, pCard->GetSpells().GetAt(0)->GetAbilityType(), costs[i], TRUE));
		cpSpell->SetMainSpell(FALSE);
		pCard->AddSpell(cpSpell.GetPointer());
	}
}

// The player controls a planeswalker of the type
static BOOL ControlsPlaneswalker(CPlayer* pPlayer, PlaneswalkerType type)
{
	PlaneswalkerTypeComparer comparer(type);
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (comparer(pBattlefield->GetAt(i)))
			return TRUE;
	return FALSE;
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


CMentorSupport::CMentorSupport(CCreatureCard* pCreature)
	: m_pCreature(pCreature)
{
}

CAbility* CMentorSupport::AddMentorAbility()
{
	// "Whenever this creature attacks, put a +1/+1 counter on target attacking creature with lesser power."
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCreature));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new LesserPowerComparer(m_pCreature));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMentorSupport::OnMentorResolving));
	cpAbility->SetAbilityText(_T("Mentor"));

	m_pCreature->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

bool CMentorSupport::OnMentorResolving(CAbilityAction* pAction)
{
	CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && pTarget->IsAttacking())
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(pTarget);
	return false;
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
		DEFINE_CARD(CPlazaOfHarmonyCard);
		DEFINE_CARD(CDomriChaosBringerCard);
		DEFINE_CARD(CDomriCitySmasherCard);
		DEFINE_CARD(CDovinArchitectOfLawCard);
		DEFINE_CARD(CDovinGrandArbiterCard);
		DEFINE_CARD(CKayaOrzhovUsurperCard);
		DEFINE_CARD(CAngelicExaltationCard);
		DEFINE_CARD(CCaptiveAudienceCard);
		DEFINE_CARD(CCavalcadeOfCalamityCard);
		DEFINE_CARD(CCindervinesCard);
		DEFINE_CARD(CDovinsAcuityCard);
		DEFINE_CARD(CEtherealAbsolutionCard);
		DEFINE_CARD(CEyesEverywhereCard);
		DEFINE_CARD(CGuardianProjectCard);
		DEFINE_CARD(CHighAlertCard);
		DEFINE_CARD(CIllGottenInheritanceCard);
		DEFINE_CARD(CLawmagesBindingCard);
		DEFINE_CARD(CMirrorMarchCard);
		DEFINE_CARD(CRhythmOfTheWildCard);
		DEFINE_CARD(CSentinelsMarkCard);
		DEFINE_CARD(CSimicAscendancyCard);
		DEFINE_CARD(CSkyTetherCard);
		DEFINE_CARD(CSlimebindCard);
		DEFINE_CARD(CSmotheringTitheCard);
		DEFINE_CARD(CVerityCircleCard);
		DEFINE_CARD(CWildernessReclamationCard);
		DEFINE_CARD(CAzoriusLocketCard);
		DEFINE_CARD(CGruulLocketCard);
		DEFINE_CARD(COrzhovLocketCard);
		DEFINE_CARD(CRakdosLocketCard);
		DEFINE_CARD(CSimicLocketCard);
		DEFINE_CARD(CGlassOfTheGuildpactCard);
		DEFINE_CARD(CScreamingShieldCard);
		DEFINE_CARD(CTomeOfTheGuildpactCard);
		DEFINE_CARD(CAwakenTheErstwhileCard);
		DEFINE_CARD(CBankruptInBloodCard);
		DEFINE_CARD(CBiogenicUpgradeCard);
		DEFINE_CARD(CBringToTrialCard);
		DEFINE_CARD(CCarnivalCarnageCard);
		DEFINE_CARD(CClearTheMindCard);
		DEFINE_CARD(CConsecrateConsumeCard);
		DEFINE_CARD(CConsignToThePitCard);
		DEFINE_CARD(CCryOfTheCarnariumCard);
		DEFINE_CARD(CDeadRevelsCard);
		DEFINE_CARD(CDefaceCard);
		DEFINE_CARD(CDrillBitCard);
		DEFINE_CARD(CGatesAblazeCard);
		DEFINE_CARD(CGoblinGatheringCard);
		DEFINE_CARD(CIncubationIncongruityCard);
		DEFINE_CARD(CKayasWrathCard);
		DEFINE_CARD(CMassManipulationCard);
		DEFINE_CARD(COpenTheGatesCard);
		DEFINE_CARD(CRagefireCard);
		DEFINE_CARD(CRepudiateReplicateCard);
		DEFINE_CARD(CRevivalRevengeCard);
		DEFINE_CARD(CRubbleReadingCard);
		DEFINE_CARD(CSavageSmashCard);
		DEFINE_CARD(CShimmerOfPossibilityCard);
		DEFINE_CARD(CSkewerTheCriticsCard);
		DEFINE_CARD(CSwirlingTorrentCard);
		DEFINE_CARD(CThrashThreatCard);
		DEFINE_CARD(CWarrantWardenCard);
		DEFINE_CARD(CAppliedBiomancyCard);
		DEFINE_CARD(CArrestersAdmonitionCard);
		DEFINE_CARD(CArrestersZealCard);
		DEFINE_CARD(CBedeckBedazzleCard);
		DEFINE_CARD(CBedevilCard);
		DEFINE_CARD(CBladebrandCard);
		DEFINE_CARD(CBurnBrightCard);
		DEFINE_CARD(CClearTheStageCard);
		DEFINE_CARD(CCodeOfConstraintCard);
		DEFINE_CARD(CCollisionColossusCard);
		DEFINE_CARD(CDeposeDeployCard);
		DEFINE_CARD(CDovinsDismissalCard);
		DEFINE_CARD(CElectrodominanceCard);
		DEFINE_CARD(CEmergencyPowersCard);
		DEFINE_CARD(CEssenceCaptureCard);
		DEFINE_CARD(CExposeToDaylightCard);
		DEFINE_CARD(CFinalPaymentCard);
		DEFINE_CARD(CFlamesOfTheRazeBoarCard);
		DEFINE_CARD(CGetThePointCard);
		DEFINE_CARD(CGrotesqueDemiseCard);
		DEFINE_CARD(CGrowthSpiralCard);
		DEFINE_CARD(CJusticiarsPortalCard);
		DEFINE_CARD(CMacabreMockeryCard);
		DEFINE_CARD(CPrecognitivePerceptionCard);
		DEFINE_CARD(CPryingEyesCard);
		DEFINE_CARD(CQuenchCard);
		DEFINE_CARD(CRallyToBattleCard);
		DEFINE_CARD(CRampageOfTheClansCard);
		DEFINE_CARD(CRegenesisCard);
		DEFINE_CARD(CSagittarsVolleyCard);
		DEFINE_CARD(CScorchmarkCard);
		DEFINE_CARD(CSphinxsInsightCard);
		DEFINE_CARD(CStonyStrengthCard);
		DEFINE_CARD(CStormStrikeCard);
		DEFINE_CARD(CSummaryJudgmentCard);
		DEFINE_CARD(CThoughtCollapseCard);
		DEFINE_CARD(CTitanicBrawlCard);
		DEFINE_CARD(CUnbreakableFormationCard);
		DEFINE_CARD(CUndercitysEmbraceCard);
		DEFINE_CARD(CAngelOfGraceCard);
		DEFINE_CARD(CArchwayAngelCard);
		DEFINE_CARD(CCivicStalwartCard);
		DEFINE_CARD(CConcordiaPegasusCard);
		DEFINE_CARD(CEliteArresterCard);
		DEFINE_CARD(CForbiddingSpiritCard);
		DEFINE_CARD(CHaazdaOfficerCard);
		DEFINE_CARD(CHeroOfPrecinctOneCard);
		DEFINE_CARD(CImpassionedOratorCard);
		DEFINE_CARD(CKnightOfSorrowsCard);
		DEFINE_CARD(CLumberingBattlementCard);
		DEFINE_CARD(CMinistrantOfObligationCard);
		DEFINE_CARD(CProwlingCaracalCard);
		DEFINE_CARD(CResoluteWatchdogCard);
		DEFINE_CARD(CSpiritOfTheSpiresCard);
		DEFINE_CARD(CSyndicateMessengerCard);
		DEFINE_CARD(CTenthDistrictVeteranCard);
		DEFINE_CARD(CTitheTakerCard);
		DEFINE_CARD(CTwilightPantherCard);
		DEFINE_CARD(CWatchfulGiantCard);
		DEFINE_CARD(CAxebaneBeastCard);
		DEFINE_CARD(CBiogenicOozeCard);
		DEFINE_CARD(CEndRazeForerunnersCard);
		DEFINE_CARD(CEnragedCeratokCard);
		DEFINE_CARD(CGatebreakerRamCard);
		DEFINE_CARD(CGrowthChamberGuardianCard);
		DEFINE_CARD(CGruulBeastmasterCard);
		DEFINE_CARD(CIncubationDruidCard);
		DEFINE_CARD(CMammothSpiderCard);
		DEFINE_CARD(CRampagingRendhornCard);
		DEFINE_CARD(CSaruliCaretakerCard);
		DEFINE_CARD(CSauroformHybridCard);
		DEFINE_CARD(CSilhanaWayfinderCard);
		DEFINE_CARD(CSteepleCreeperCard);
		DEFINE_CARD(CSylvanBrushstriderCard);
		DEFINE_CARD(CTerritorialBoarCard);
		DEFINE_CARD(CTrollbredGuardianCard);
		DEFINE_CARD(CWreckingBeastCard);
		DEFINE_CARD(CAmplifireCard);
		DEFINE_CARD(CBurningTreeVandalCard);
		DEFINE_CARD(CClamorShamanCard);
		DEFINE_CARD(CDaggerCasterCard);
		DEFINE_CARD(CFeralMaakaCard);
		DEFINE_CARD(CGhorClanWreckerCard);
		DEFINE_CARD(CGravelHideGoblinCard);
		DEFINE_CARD(CImmolationShamanCard);
		DEFINE_CARD(CRixMaadiRevelerCard);
		DEFINE_CARD(CRubblebeltRecluseCard);
		DEFINE_CARD(CRumblingRuinCard);
		DEFINE_CARD(CSkarrganHellkiteCard);
		DEFINE_CARD(CSmeltWardIgnusCard);
		DEFINE_CARD(CSpearSpewerCard);
		DEFINE_CARD(CSpikewheelAcrobatCard);
		DEFINE_CARD(CTinStreetDodgerCard);
		DEFINE_CARD(CBladeJugglerCard);
		DEFINE_CARD(CBloodmistInfiltratorCard);
		DEFINE_CARD(CCarrionImpCard);
		DEFINE_CARD(CCatacombCrocodileCard);
		DEFINE_CARD(CDebtorsTransportCard);
		DEFINE_CARD(CGutterbonesCard);
		DEFINE_CARD(CNoxiousGroodionCard);
		DEFINE_CARD(COrzhovEnforcerCard);
		DEFINE_CARD(COrzhovRacketeersCard);
		DEFINE_CARD(CPestilentSpiritCard);
		DEFINE_CARD(CPlagueWightCard);
		DEFINE_CARD(CPriestOfForgottenGodsCard);
		DEFINE_CARD(CRakdosTrumpeterCard);
		DEFINE_CARD(CSpawnOfMayhemCard);
		DEFINE_CARD(CSpireManglerCard);
		DEFINE_CARD(CTheHauntOfHightowerCard);
		DEFINE_CARD(CThirstingShadeCard);
		DEFINE_CARD(CUndercityScavengerCard);
		DEFINE_CARD(CVindictiveVampireCard);
		DEFINE_CARD(CBenthicBiomancerCard);
		DEFINE_CARD(CChillbringerCard);
		DEFINE_CARD(CCoralCommandoCard);
		DEFINE_CARD(CFaerieDuelistCard);
		DEFINE_CARD(CGatewaySneakCard);
		DEFINE_CARD(CHumongulusCard);
		DEFINE_CARD(CMesmerizingBenthidCard);
		DEFINE_CARD(CPersistentPetitionersCard);
		DEFINE_CARD(CPteramanderCard);
		DEFINE_CARD(CSagesRowSavantCard);
		DEFINE_CARD(CSenateCourierCard);
		DEFINE_CARD(CSkatewingSpyCard);
		DEFINE_CARD(CSkitterEelCard);
		DEFINE_CARD(CSphinxOfForesightCard);
		DEFINE_CARD(CWallOfLostThoughtsCard);
		DEFINE_CARD(CWindstormDrakeCard);
		DEFINE_CARD(CAeromunculusCard);
		DEFINE_CARD(CAzoriusKnightArbiterCard);
		DEFINE_CARD(CAzoriusSkyguardCard);
		DEFINE_CARD(CBasilicaBellHauntCard);
		DEFINE_CARD(CBolracClanCrusherCard);
		DEFINE_CARD(CChargingWarBoarCard);
		DEFINE_CARD(CClanGuildmageCard);
		DEFINE_CARD(CCombineGuildmageCard);
		DEFINE_CARD(CCultGuildmageCard);
		DEFINE_CARD(CDeputyOfDetentionCard);
		DEFINE_CARD(CDomrisNodorogCard);
		DEFINE_CARD(CDovinsAutomatonCard);
		DEFINE_CARD(CFirebladeArtistCard);
		DEFINE_CARD(CFootlightFiendCard);
		DEFINE_CARD(CFrenziedArynxCard);
		DEFINE_CARD(CFrilledMysticCard);
		DEFINE_CARD(CGallopingLizrogCard);
		DEFINE_CARD(CGateColossusCard);
		DEFINE_CARD(CGraspingThrullCard);
		DEFINE_CARD(CGruulSpellbreakerCard);
		DEFINE_CARD(CGyreEngineerCard);
		DEFINE_CARD(CHackrobatCard);
		DEFINE_CARD(CHydroidKrasisCard);
		DEFINE_CARD(CImperiousOligarchCard);
		DEFINE_CARD(CJudithTheScourgeDivaCard);
		DEFINE_CARD(CKnightOfTheLastBreathCard);
		DEFINE_CARD(CLaviniaAzoriusRenegadeCard);
		DEFINE_CARD(CNikyaOfTheOldWaysCard);
		DEFINE_CARD(CPitilessPontiffCard);
		DEFINE_CARD(CPrimeSpeakerVannifarCard);
		DEFINE_CARD(CRafterDemonCard);
		DEFINE_CARD(CRakdosFirewheelerCard);
		DEFINE_CARD(CRakdosRoustaboutCard);
		DEFINE_CARD(CRakdosTheShowstopperCard);
		DEFINE_CARD(CRavagerWurmCard);
		DEFINE_CARD(CRubblebeltRunnerCard);
		DEFINE_CARD(CRubbleSlingerCard);
		DEFINE_CARD(CScuttlegatorCard);
		DEFINE_CARD(CSenateGriffinCard);
		DEFINE_CARD(CSenateGuildmageCard);
		DEFINE_CARD(CSeraphOfTheScalesCard);
		DEFINE_CARD(CSharktocrabCard);
		DEFINE_CARD(CSphinxOfNewPrahvCard);
		DEFINE_CARD(CSphinxOfTheGuildpactCard);
		DEFINE_CARD(CSunderShamanCard);
		DEFINE_CARD(CSyndicateGuildmageCard);
		DEFINE_CARD(CTeysaKarlovCard);
		DEFINE_CARD(CVizkopaVampireCard);
		DEFINE_CARD(CZeganaUtopianSpeakerCard);
		DEFINE_CARD(CZhurTaaGoblinCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CPlazaOfHarmonyCard::CPlazaOfHarmonyCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Plaza of Harmony"), nID)
{
	// When this land enters, if you control two or more Gates, you gain 3 life.
	AddEnterIfTrigger(this, &CPlazaOfHarmonyCard::SetGatesContext, &CPlazaOfHarmonyCard::BeforeGainLife);

	// {T}: Add {C}.
	AddTapManaAbility(this, _T("1"));

	// {T}: Add one mana of any type that a Gate you control could produce. (as Reflecting Pool)
	CManaPool::Color colors[] = { CManaPool::Color::White, CManaPool::Color::Blue, CManaPool::Color::Black,
								  CManaPool::Color::Red, CManaPool::Color::Green };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility3> cpAbility(
			::CreateObject<CManaProductionAbility3>(this, _T(""), AbilityType::Activated,
				new CardTypeComparer(CardType::Gate, false),
				colors[i]));

		cpAbility->SetMonitorControllerOnly();
		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

bool CPlazaOfHarmonyCard::SetGatesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	return CCardFilter::GetFilter(_T("Gates"))->CountIncluded(pBattlefield->GetCardContainer()) >= 2;
}

bool CPlazaOfHarmonyCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define DOMRI_CHAOS_BRINGER_EMBLEM_NAME	_T("Domri, Chaos Bringer Emblem")
#define DOMRI_CHAOS_BRINGER_EMBLEM_ID	61160

// "Look at the top nCount cards of your library. Put nMin to nMax <filter> cards among them into your hand and the
// rest on the bottom of your library in a random order."
static void LookTopToHandRestBottom(CGame* pGame, CPlayer* pPlayer, int nCount, int nMin, int nMax, const CCardFilter* pFilter)
{
	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, nCount,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(nMin), MaximumValue(nMax),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, pFilter,
		ZoneId::Hand, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pPlayer);
}

// "Tap pCard. It doesn't untap during its controller's next untap step." (Watertrap Weaver)
static void TapAndSkipUntap(CCard* pCard)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CCardOrientationModifier(TRUE).ApplyTo(pCard);
	CScheduledCardModifier pSkip = CScheduledCardModifier(pCard->GetGame(),
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pSkip.ApplyTo(pCard);
}

//____________________________________________________________________________
//
CDomriChaosBringerCard::CDomriChaosBringerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Domri, Chaos Bringer"), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Domri, 5)
{
	// +1: Add {R} or {G}. If that mana is spent on a creature spell, it gains riot.
	// Partial: the creature spell doesn't gain riot (the engine can't track how the mana is spent).
	AddLoyaltyAbility(this, +1, _T("+1: Add {R}. Activates"), &CDomriChaosBringerCard::BeforeRedMana);
	AddLoyaltyAbility(this, +1, _T("+1: Add {G}. Activates"), &CDomriChaosBringerCard::BeforeGreenMana);

	// -3: Look at the top four cards of your library. You may reveal up to two creature cards from among them and put
	// them into your hand. Put the rest on the bottom of your library in a random order.
	AddLoyaltyAbility(this, -3, _T("-3: Look at the top four cards, put up to two creature cards into your hand. Activates"),
		&CDomriChaosBringerCard::BeforeLook);

	// -8: You get an emblem with "At the beginning of each end step, create a 4/4 red and green Beast creature token
	// with trample."
	AddEmblemLoyaltyAbility(this, -8, DOMRI_CHAOS_BRINGER_EMBLEM_NAME, DOMRI_CHAOS_BRINGER_EMBLEM_ID,
		_T("You get an emblem with \"At the beginning of each end step, create a 4/4 red and green Beast creature token with trample.\" Activates"));
}

bool CDomriChaosBringerCard::BeforeRedMana(CAbilityAction* pAction)
{
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(RED_MANA_TEXT)).ApplyTo(pAction->GetController());
	return true;
}

bool CDomriChaosBringerCard::BeforeGreenMana(CAbilityAction* pAction)
{
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(GREEN_MANA_TEXT)).ApplyTo(pAction->GetController());
	return true;
}

bool CDomriChaosBringerCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 4, 0, 2, CCardFilter::GetFilter(_T("creatures")));
	return true;
}

//____________________________________________________________________________
//
CDomriCitySmasherCard::CDomriCitySmasherCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Domri, City Smasher"), nID,
		_T("4") RED_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Domri, 4)
{
	// +2: Creatures you control get +1/+1 and gain haste until end of turn.
	AddLoyaltyAbility(this, +2, _T("+2: Creatures you control get +1/+1 and gain haste until end of turn. Activates"),
		&CDomriCitySmasherCard::BeforePump);

	{
		// -3: Domri deals 3 damage to any target.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-3), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		AddAbility(cpAbility.GetPointer());
	}

	// -8: Put three +1/+1 counters on each creature you control. Those creatures gain trample until end of turn.
	AddLoyaltyAbility(this, -8, _T("-8: Put three +1/+1 counters on each creature you control; they gain trample until end of turn. Activates"),
		&CDomriCitySmasherCard::BeforeUltimate);
}

bool CDomriCitySmasherCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, +1, CreatureKeyword::Haste);
	return true;
}

bool CDomriCitySmasherCard::BeforeUltimate(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		AddPlusCounter(creatures.GetAt(i), 3);
		PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::Trample);
	}
	return true;
}

//____________________________________________________________________________
//
CDovinArchitectOfLawCard::CDovinArchitectOfLawCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Dovin, Architect of Law"), nID,
		_T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Dovin, 5)
{
	// +1: You gain 2 life and draw a card.
	AddLoyaltyAbility(this, +1, _T("+1: You gain 2 life and draw a card. Activates"), &CDovinArchitectOfLawCard::BeforeGainDraw);

	{
		// -1: Tap target creature. It doesn't untap during its controller's next untap step.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDovinArchitectOfLawCard::BeforeTap));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -9: Tap all permanents target opponent controls. That player skips their next untap step.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDovinArchitectOfLawCard::BeforeUltimate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDovinArchitectOfLawCard::BeforeGainDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CDovinArchitectOfLawCard::BeforeTap(CAbilityAction* pAction)
{
	TapAndSkipUntap(pAction->GetAssociatedCard());
	return false;
}

bool CDovinArchitectOfLawCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer permanents;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		permanents.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	CCardOrientationModifier pTap = CCardOrientationModifier(TRUE);
	for (int i = 0; i < permanents.GetSize(); ++i)
		if (permanents.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pTap.ApplyTo(permanents.GetAt(i));

	CPlayerEffectModifier(PlayerEffectType::SkipNextUntapStep).ApplyTo(pPlayer);
	return false;
}

//____________________________________________________________________________
//
CDovinGrandArbiterCard::CDovinGrandArbiterCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Dovin, Grand Arbiter"), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Dovin, 3)
	, m_nActiveTurn(-1)
{
	// +1: Until end of turn, whenever a creature you control deals combat damage to a player, put a loyalty counter on
	// Dovin.
	AddLoyaltyAbility(this, +1, _T("+1: Until end of turn, whenever a creature you control deals combat damage to a player, put a loyalty counter on Dovin. Activates"),
		&CDovinGrandArbiterCard::BeforeActivate);

	{
		// The delayed trigger of the +1 ability: it only works in the turn the ability resolved.
		counted_ptr<DamageTriggeredAbility> cpAbility(::CreateObject<DamageTriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->SetOptionalType(DamageTriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(DamageTriggeredAbility::ContextFunction(this, &CDovinGrandArbiterCard::SetDamageContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDovinGrandArbiterCard::BeforeLoyalty));
		AddAbility(cpAbility.GetPointer());
	}

	// -1: Create a 1/1 colorless Thopter artifact creature token with flying. You gain 1 life.
	AddLoyaltyAbility(this, -1, _T("-1: Create a 1/1 colorless Thopter artifact creature token with flying. You gain 1 life. Activates"),
		&CDovinGrandArbiterCard::BeforeThopter);

	// -7: Look at the top ten cards of your library. Put three of them into your hand and the rest on the bottom of
	// your library in a random order.
	AddLoyaltyAbility(this, -7, _T("-7: Look at the top ten cards, put three of them into your hand. Activates"),
		&CDovinGrandArbiterCard::BeforeLook);
}

bool CDovinGrandArbiterCard::BeforeActivate(CAbilityAction* pAction)
{
	m_nActiveTurn = GetGame()->GetGameTurnNumber();
	return true;
}

bool CDovinGrandArbiterCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	if (m_nActiveTurn != GetGame()->GetGameTurnNumber())
		return false;
	return pFromCard && pFromCard->GetCardType().IsCreature();
}

bool CDovinGrandArbiterCard::BeforeLoyalty(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(LOYALTY_COUNTER, +1).ApplyTo(this);
	return true;
}

bool CDovinGrandArbiterCard::BeforeThopter(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), THOPTER_D_TOKEN_NAME, THOPTER_D_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	GainLife(this, pAction->GetController(), 1);
	return true;
}

bool CDovinGrandArbiterCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 10, 3, 3, CCardFilter::GetFilter(_T("cards")));
	return true;
}

//____________________________________________________________________________
//
CKayaOrzhovUsurperCard::CKayaOrzhovUsurperCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Kaya, Orzhov Usurper"), nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Kaya, 3)
{
	{
		// +1: Exile up to two target cards from a single graveyard. You gain 2 life if at least one creature card was
		// exiled this way.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new TrueCardComparer,
				ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKayaOrzhovUsurperCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -1: Exile target nonland permanent with mana value 1 or less.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AndCardComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
					new ConvertedManaCostComparer<std::less_equal<int>>(1)),
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -5: Kaya deals damage to target player equal to the number of cards that player owns in exile and you gain that
	// much life.
	AddPlayerLoyaltyAbility(this, -5, &CKayaOrzhovUsurperCard::BeforeDrain);
}

bool CKayaOrzhovUsurperCard::BeforeExile(CAbilityAction* pAction)
{
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (!pTargetAction)
		return false;

	CCountedCardContainer targets;
	pTargetAction->GetTargetGroup().GetCardSubjects(targets);

	// The cards must come from a single graveyard: only the ones in the same graveyard as the first one are exiled
	CPlayer* pOwner = NULL;
	BOOL bCreature = FALSE;
	for (int i = 0; i < targets.GetSize(); ++i)
	{
		CCard* pCard = targets.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Graveyard)
			continue;
		if (!pOwner)
			pOwner = pCard->GetOwner();
		if (pCard->GetOwner() != pOwner)
			continue;

		if (pCard->GetCardType().IsCreature())
			bCreature = TRUE;
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	}

	if (bCreature)
		GainLife(this, pAction->GetController(), 2);
	return false;
}

bool CKayaOrzhovUsurperCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	int nCount = pPlayer->GetZoneById(ZoneId::Exile)->GetSize();
	if (nCount > 0)
	{
		DealDamageToPlayer(this, pPlayer, nCount);
		GainLife(this, pAction->GetController(), nCount);
	}
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define ZOMBIE_P_TOKEN_NAME		_T("Zombie (P)")
#define ZOMBIE_P_TOKEN_ID		55009
#define SPIRIT_C_TOKEN_NAME		_T("Spirit (C)")
#define SPIRIT_C_TOKEN_ID		2815
#define GROWTH_COUNTER			_T("growth counter")

// Addendum: "If you cast this spell during your main phase". A spell resolves in the same step it was cast, so it is
// checked at resolution (or when an Aura enters).
static BOOL IsYourMainPhase(CPlayer* pPlayer)
{
	CGame* pGame = pPlayer->GetGame();
	return pGame->GetActivePlayer() == pPlayer && pGame->GetCurrentNode() &&
		pGame->GetCurrentNode()->GetNodeId() == NodeId::MainPhaseStep;
}

// "An opponent lost life this turn" (Spectacle and other RNA cards)
static BOOL OpponentLostLifeThisTurn(CPlayer* pPlayer)
{
	CGame* pGame = pPlayer->GetGame();
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = pGame->GetPlayer(ip);
		if (pOpponent != pPlayer && pOpponent->GetLifeLossTakenThisTurn() > Life(0))
			return TRUE;
	}
	return FALSE;
}

//____________________________________________________________________________
//
CRiotSupport::CRiotSupport(CCard* pCard)
	: m_pCard(pCard)
	, m_Selection(pCard->GetGame(), CSelectionSupport::SelectionCallback(this, &CRiotSupport::OnRiotSelected))
	, m_cpListener(VAR_NAME(m_cpListener), CardMovementEventSource::Listener::EventCallback(this, &CRiotSupport::OnZoneChanged))
{
}

void CRiotSupport::AddRiotAbility()
{
	m_pCard->GetMovedEventSource()->AddListener(m_cpListener.GetPointer());
}

void CRiotSupport::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != m_pCard || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
		ApplyRiot(m_pCard);
}

void CRiotSupport::ApplyRiot(CCard* pCreature)
{
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || !pCreature->GetCardType().IsCreature())
		return;

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText.Format(_T("Riot: put a +1/+1 counter on %s"), pCreature->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 2;
		entry.strText.Format(_T("Riot: %s gains haste"), pCreature->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_Selection.AddSelectionRequest(entries, 1, 1, NULL, pCreature->GetController(), (DWORD)pCreature);
}

void CRiotSupport::OnRiotSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)dwContext1);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if ((int)it->dwContext == 1)
				CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(pCreature);
			else
				pCreature->GetCreatureKeyword()->AddHaste(FALSE);
		}
}

//____________________________________________________________________________
//
CAngelicExaltationCard::CAngelicExaltationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Angelic Exaltation"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control attacks alone, it gets +X/+X until end of turn, where X is the number of
	// creatures you control. (as the exalted of Ethercaste Knight)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAngelicExaltationCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CAngelicExaltationCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CAngelicExaltationCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CAngelicExaltationCard::BeforePump(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCreature = (CCard*)pAction->GetTriggerContext().nValue1;
	int nCount = CountCreatures(GetGame(), pAction->GetController());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && nCount > 0)
		PumpCreature(pCreature, nCount, nCount);
	return true;
}

//____________________________________________________________________________
//
CCaptiveAudienceCard::CCaptiveAudienceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Captive Audience"), CardType::GlobalEnchantment, nID,
		_T("5") BLACK_MANA_TEXT RED_MANA_TEXT, AbilityType::Enchantment)
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CCaptiveAudienceCard::OnModeSelected))
{
	m_bChosen[0] = m_bChosen[1] = m_bChosen[2] = FALSE;

	{
		// This enchantment enters under the control of an opponent of your choice. (done without the stack just after
		// it enters)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCaptiveAudienceCard::SetEnterContext));
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your upkeep, choose one that hasn't been chosen - Your life total becomes 4; Discard your
	// hand; Each opponent creates five 2/2 black Zombie creature tokens.
	AddStepTrigger(this, NodeId::UpkeepStep, false, &CCaptiveAudienceCard::SetUpkeepContext, &CCaptiveAudienceCard::BeforeChoose);
}

bool CCaptiveAudienceCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	m_bChosen[0] = m_bChosen[1] = m_bChosen[2] = FALSE;

	CPlayer* pController = GetController();
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	if (pOpponent && pOpponent != pController)
	{
		CCaptiveAudienceCard* pThis = const_cast<CCaptiveAudienceCard*>(this);
		CTransferControlModifier(GetGame(), pThis, pThis).ApplyTo(pOpponent);
	}
	return false;
}

bool CCaptiveAudienceCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !m_bChosen[0] || !m_bChosen[1] || !m_bChosen[2];
}

bool CCaptiveAudienceCard::BeforeChoose(CAbilityAction* pAction)
{
	static LPCTSTR texts[] = { _T("Your life total becomes 4"), _T("Discard your hand"),
							   _T("Each opponent creates five 2/2 black Zombie creature tokens") };

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 3; ++i)
		if (!m_bChosen[i])
		{
			SelectionEntry entry;
			entry.dwContext = i;
			entry.strText = texts[i];
			entries.push_back(entry);
		}

	if (!entries.empty())
		m_ModeSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CCaptiveAudienceCard::OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int nMode = (int)it->dwContext;
			m_bChosen[nMode] = TRUE;

			if (!m_pGame->IsThinking())
			{
				CString strMessage;
				strMessage.Format(_T("%s chooses: %s"), pSelectionPlayer->GetPlayerName(), (LPCTSTR)it->strText);
				m_pGame->Message(strMessage, pSelectionPlayer->IsComputer() ? m_pGame->GetComputerImage() : m_pGame->GetHumanImage(),
					MessageImportance::High);
			}

			if (nMode == 0)
			{
				CLifeModifier(Life(4) - pSelectionPlayer->GetLife(), this, PreventableType::NotPreventable,
					DamageType::NotDealingDamage).ApplyTo(pSelectionPlayer);
			}
			else if (nMode == 1)
			{
				DiscardCards(GetGame(), pSelectionPlayer, pSelectionPlayer->GetZoneById(ZoneId::Hand)->GetSize());
			}
			else
			{
				for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
					if (GetGame()->GetPlayer(ip) != pSelectionPlayer)
						CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, 5).ApplyTo(GetGame()->GetPlayer(ip));
			}
		}
}

//____________________________________________________________________________
//
CCavalcadeOfCalamityCard::CCavalcadeOfCalamityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cavalcade of Calamity"), CardType::GlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control with power 1 or less attacks, this enchantment deals 1 damage to the player or
	// planeswalker that creature is attacking.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCavalcadeOfCalamityCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CCavalcadeOfCalamityCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CCavalcadeOfCalamityCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	if (!pCreature || pCreature->GetPower() > Power(1))
		return false;

	triggerContext.nValue1 = (DWORD)attacked.pPlayer;
	triggerContext.nValue2 = (DWORD)attacked.cpPlaneswalker.GetPointer();
	return attacked.pPlayer || attacked.cpPlaneswalker.GetPointer();
}

bool CCavalcadeOfCalamityCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	CCard* pPlaneswalker = (CCard*)pAction->GetTriggerContext().nValue2;
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 1);
	else if (pPlaneswalker && pPlaneswalker->GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(LOYALTY_COUNTER, -1).ApplyTo(pPlaneswalker);
	return true;
}

//____________________________________________________________________________
//
CCindervinesCard::CCindervinesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cindervines"), CardType::GlobalEnchantment, nID,
		RED_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever an opponent casts a noncreature spell, this enchantment deals 1 damage to that player.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCindervinesCard::SetTriggerContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CCindervinesCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}, Sacrifice this enchantment: Destroy target artifact or enchantment. This enchantment deals 2 damage to
		// that permanent's controller.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false), FALSE));

		cpAbility->AddSacrificeCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCindervinesCard::BeforeDestroy));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCindervinesCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	triggerContext.nValue1 = (DWORD)pCard->GetController();
	return true;
}

bool CCindervinesCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	DealDamageToPlayer(this, (CPlayer*)pAction->GetTriggerContext().nValue1, 1);
	return true;
}

bool CCindervinesCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pController = pCard->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	DealDamageToPlayer(this, pController, 2);
	return false;
}

//____________________________________________________________________________
//
CDovinsAcuityCard::CDovinsAcuityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dovin's Acuity"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, you gain 2 life and draw a card.
	AddEnterTrigger(this, &CDovinsAcuityCard::BeforeGainDraw);

	// Whenever you cast an instant spell during your main phase, you may return this enchantment to its owner's hand.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards")));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDovinsAcuityCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDovinsAcuityCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CDovinsAcuityCard::BeforeGainDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CDovinsAcuityCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return IsYourMainPhase(GetController()) == TRUE;
}

bool CDovinsAcuityCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CEtherealAbsolutionCard::CEtherealAbsolutionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ethereal Absolution"), CardType::GlobalEnchantment, nID,
		_T("4") WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Creatures you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(+1), Life(+1)));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Creatures your opponents control get -1/-1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(-1), Life(-1)));
		cpAbility->SetAffectOpponentCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{W}{B}: Exile target card from an opponent's graveyard. If it was a creature card, you create a 1/1 white
		// and black Spirit creature token with flying.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT,
				new TrueCardComparer,
				ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEtherealAbsolutionCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CEtherealAbsolutionCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;

	BOOL bCreature = pCard->GetCardType().IsCreature();
	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	if (bCreature)
		CTokenCreationModifier(GetGame(), SPIRIT_C_TOKEN_NAME, SPIRIT_C_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CEyesEverywhereCard::CEyesEverywhereCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Eyes Everywhere"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, scry 1.
	AddStepTrigger<CEyesEverywhereCard>(this, NodeId::UpkeepStep, false, NULL, &CEyesEverywhereCard::BeforeScry);

	// {5}{U}: Exchange control of this enchantment and target nonland permanent. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("5") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)), FALSE));

	cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEyesEverywhereCard::BeforeExchange));
	AddAbility(cpAbility.GetPointer());
}

bool CEyesEverywhereCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

bool CEyesEverywhereCard::BeforeExchange(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || GetZoneId() != ZoneId::Battlefield)
		return false;

	// (as Switcheroo in M13)
	CPlayer* pPlayer1 = GetController();
	CPlayer* pPlayer2 = pCard->GetController();
	if (pPlayer1 == pPlayer2)
		return false;

	CTransferControlModifier(GetGame(), this, this).ApplyTo(pPlayer2);
	CTransferControlModifier(GetGame(), pCard, pCard).ApplyTo(pPlayer1);
	return false;
}

//____________________________________________________________________________
//
CGuardianProjectCard::CGuardianProjectCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Guardian Project"), CardType::GlobalEnchantment, nID,
		_T("3") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a nontoken creature you control enters, if it doesn't have the same name as another creature you
	// control or a creature card in your graveyard, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new CardTypeComparer(CardType::Token, false));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGuardianProjectCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGuardianProjectCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CGuardianProjectCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CString strName = pCard->GetCardName(FALSE);
	CPlayer* pController = GetController();

	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pOther = pBattlefield->GetAt(i);
		if (pOther != pCard && pOther->GetCardType().IsCreature() && pOther->GetCardName(FALSE) == strName)
			return false;
	}

	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pOther = pGraveyard->GetAt(i);
		if (pOther->GetCardType().IsCreature() && pOther->GetCardName(FALSE) == strName)
			return false;
	}
	return true;
}

bool CGuardianProjectCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CHighAlertCard::CHighAlertCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("High Alert"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Each creature you control assigns combat damage equal to its toughness rather than its power. (as Assault
		// Formation)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::ToughnessCombatDamage));
		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Creatures you control can attack as though they didn't have defender. (as Rolling Stones)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(+0), Life(+0), CreatureKeyword::DefenderMayAttack));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{W}{U}: Untap target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CIllGottenInheritanceCard::CIllGottenInheritanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ill-Gotten Inheritance"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, this enchantment deals 1 damage to each opponent and you gain 1 life.
	AddStepTrigger<CIllGottenInheritanceCard>(this, NodeId::UpkeepStep, false, NULL, &CIllGottenInheritanceCard::BeforeDrain);

	// {5}{B}, Sacrifice this enchantment: It deals 4 damage to target opponent and you gain 4 life.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("5") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIllGottenInheritanceCard::BeforeSacrifice));
	AddAbility(cpAbility.GetPointer());
}

bool CIllGottenInheritanceCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

bool CIllGottenInheritanceCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 4);
	GainLife(this, pAction->GetController(), 4);
	return false;
}

//____________________________________________________________________________
//
CLawmagesBindingCard::CLawmagesBindingCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Lawmage's Binding"), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
	, m_CardFilter(_T("enchanted by this"), _T("enchanted by this"), new EnchantedByComparer(this))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Enchant creature. Enchanted creature can't attack or block, and its activated abilities can't be activated.
	// (as Arrest in Mercadian Masques)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	CCantActivateAbilitiesModifier* pModifier = new CCantActivateAbilitiesModifier(GetGame(), &m_CardFilter);
	m_pChgPwrTghAttrEnchant->GetCreatureKeywordMod().LinkCardModifier(pModifier);
}

//____________________________________________________________________________
//
CMirrorMarchCard::CMirrorMarchCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mirror March"), CardType::GlobalEnchantment, nID,
		_T("5") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a nontoken creature you control enters, flip a coin until you lose a flip. For each flip you won, create
	// a token that's a copy of that creature. Those tokens gain haste. Exile them at the beginning of the next end step.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new CardTypeComparer(CardType::Token, false));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMirrorMarchCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CMirrorMarchCard::BeforeCopies));
	AddAbility(cpAbility.GetPointer());
}

bool CMirrorMarchCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CMirrorMarchCard::BeforeCopies(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCreature = (CCard*)pAction->GetTriggerContext().nValue1;
	CPlayer* pController = pAction->GetController();

	// Flip a coin until you lose a flip
	int nWins = 0;
	while (pController->GetRand() % 2 == 0)
		++nWins;

	if (!m_pGame->IsThinking())
	{
		CString strMessage;
		strMessage.Format(_T("%s wins %d coin flip(s)"), pController->GetPlayerName(), nWins);
		m_pGame->Message(strMessage, pController->IsComputer() ? m_pGame->GetComputerImage() : m_pGame->GetHumanImage(),
			MessageImportance::High);
	}

	if (nWins == 0 || !pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	// (as Kiki-Jiki, Mirror Breaker in Champions of Kamigawa and Splinter Twin)
	CCountedCardContainer tokens;
	for (int i = 0; i < nWins; ++i)
	{
		CCreatureKeywordModifier* pHaste = new CCreatureKeywordModifier();
		pHaste->GetModifier().SetOneTurnOnly(FALSE);
		pHaste->GetModifier().SetToAdd(CreatureKeyword::Haste);

		CCardCopyModifier pCopy = CCardCopyModifier(GetGame(), pCreature, NULL, pHaste, &tokens);
		pCopy.ApplyTo(pCreature);
	}

	CContainerEffectModifier pExile = CContainerEffectModifier(GetGame(), _T("End Step Exile Effect"), 61061, &tokens);
	pExile.ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CRhythmOfTheWildCard::CRhythmOfTheWildCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Rhythm of the Wild"), CardType::GlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_Riot(this)
{
	{
		// Creature spells you control can't be countered. (as Prowling Serpopard)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::SpellsCantBeCountered,
				reinterpret_cast<int>(CCardFilter::GetFilter(_T("creatures")))));
		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Nontoken creatures you control have riot. (the choice is made just after the creature enters, without the
		// stack: the context function asks it and the ability doesn't trigger)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new CardTypeComparer(CardType::Token, false));
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRhythmOfTheWildCard::SetTriggerContext));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRhythmOfTheWildCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (pFromZone && pFromZone->GetZoneId() != ZoneId::Battlefield)
		m_Riot.ApplyRiot(pCard);
	return false;
}

//____________________________________________________________________________
//
CSentinelsMarkCard::CSentinelsMarkCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Sentinel's Mark"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+1), Life(+2), CreatureKeyword::Vigilance)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Addendum - When this Aura enters, if you cast it during your main phase, enchanted creature gains lifelink until
	// end of turn.
	AddEnterIfTrigger(this, &CSentinelsMarkCard::SetAddendumContext, &CSentinelsMarkCard::BeforeLifelink);
}

bool CSentinelsMarkCard::SetAddendumContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Cast && IsYourMainPhase(GetController());
}

bool CSentinelsMarkCard::BeforeLifelink(CAbilityAction* pAction)
{
	GainCardKeyword(GetEnchantedOn(), CardKeyword::Lifelink);
	return true;
}

//____________________________________________________________________________
//
CSimicAscendancyCard::CSimicAscendancyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Simic Ascendancy"), CardType::GlobalEnchantment, nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// {1}{G}{U}: Put a +1/+1 counter on target creature you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever one or more +1/+1 counters are put on a creature you control, put that many growth counters on this
		// enchantment. (as Fathom Mage in Gatecrash)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().SetOnIncreaseOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSimicAscendancyCard::SetCounterContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CSimicAscendancyCard::BeforeGrowth));
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your upkeep, if this enchantment has twenty or more growth counters on it, you win the game.
	AddStepTrigger(this, NodeId::UpkeepStep, false, &CSimicAscendancyCard::SetUpkeepContext, &CSimicAscendancyCard::BeforeWin);
}

bool CSimicAscendancyCard::SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	if (!pFromCard || !pFromCard->GetCardType().IsCreature() || pFromCard->GetZoneId() != ZoneId::Battlefield)
		return false;
	if ((CString)name != _T("+1/+1") || n_value <= old)
		return false;

	triggerContext.nValue1 = (DWORD)(n_value - old);
	return true;
}

bool CSimicAscendancyCard::BeforeGrowth(TriggeredAbility::TriggeredActionType* pAction)
{
	int nCount = (int)pAction->GetTriggerContext().nValue1;
	if (nCount > 0 && GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(GROWTH_COUNTER, nCount).ApplyTo(this);
	return true;
}

bool CSimicAscendancyCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetCounterContainer()->GetCounter(GROWTH_COUNTER)->GetCount() >= 20;
}

bool CSimicAscendancyCard::BeforeWin(CAbilityAction* pAction)
{
	if (GetCounterContainer()->GetCounter(GROWTH_COUNTER)->GetCount() < 20)
		return true;

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			GetGame()->GetPlayer(ip)->SetLostByOtherReasons();
	return true;
}

//____________________________________________________________________________
//
CSkyTetherCard::CSkyTetherCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Sky Tether"), nID,
		WHITE_MANA_TEXT,
		Power(+0), Life(+0))
{
	// Enchanted creature has defender and loses flying. (loses flying as Grounded in Avacyn Restored)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCreatureKeywordMod().GetModifier().SetToRemove(CreatureKeyword::Flying);

	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new EnchantedByComparer(this),
			Power(+0), Life(+0), CreatureKeyword::Defender));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSlimebindCard::CSlimebindCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Slimebind"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(-4), Life(+0))
{
	// Flash. Enchant creature. Enchanted creature gets -4/-0.
	GetCardKeyword()->AddFlash(FALSE);
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

//____________________________________________________________________________
//
CSmotheringTitheCard::CSmotheringTitheCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Smothering Tithe"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever an opponent draws a card, that player may pay {2}. If the player doesn't, you create a Treasure token.
	// (the payment is the denial of the triggered ability on the stack, as Chancellor of the Annex)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
	cpAbility->SetCanBeDenied();
	cpAbility->GetDenialCost().SetManaCost(_T("2"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSmotheringTitheCard::BeforeTreasure));
	AddAbility(cpAbility.GetPointer());
}

bool CSmotheringTitheCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CVerityCircleCard::CVerityCircleCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Verity Circle"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever a creature an opponent controls becomes tapped, if it isn't being declared as an attacker, you may
		// draw a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenOrientationChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->GetTrigger().SetFromOrientation(Orientation::Untap);
		cpAbility->GetTrigger().SetToOrientation(Orientation::Tap);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVerityCircleCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVerityCircleCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{U}: Tap target creature without flying.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("4") BLUE_MANA_TEXT,
				new AndCardComparer(new AnyCreatureComparer,
					new NegateCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false))), FALSE));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVerityCircleCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, Orientation fromOrientation, Orientation toOrientation) const
{
	// Not when it is tapped because it is declared as an attacker
	CNode* pNode = GetGame()->GetCurrentNode();
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (pNode && pCreature && (pNode->GetNodeId() & NodeId::_DeclareAttackersStep).Any() && pCreature->IsAttacking())
		return false;
	return true;
}

bool CVerityCircleCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CWildernessReclamationCard::CWildernessReclamationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Wilderness Reclamation"), CardType::GlobalEnchantment, nID,
		_T("3") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your end step, untap all lands you control.
	AddStepTrigger<CWildernessReclamationCard>(this, NodeId::EndStep, false, NULL, &CWildernessReclamationCard::BeforeUntap);
}

bool CWildernessReclamationCard::BeforeUntap(CAbilityAction* pAction)
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer lands;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsLand())
			lands.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	for (int i = 0; i < lands.GetSize(); ++i)
		pUntap.ApplyTo(lands.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CLocketCard::CLocketCard(CGame* pGame, LPCTSTR strName, UINT nID, LPCTSTR strColor1, LPCTSTR strColor2)
	: CInPlaySpellCard(pGame, strName, CardType::Artifact, nID, _T("3"), AbilityType::Artifact)
{
	// {T}: Add {C1} or {C2}.
	AddTapManaAbility(this, strColor1);
	AddTapManaAbility(this, strColor2);

	// {C1/C2}{C1/C2}{C1/C2}{C1/C2}, {T}, Sacrifice this artifact: Draw two cards.
	// (hybrid mana, as in Alara Reborn: one ability for each combination of the two colors)
	for (int nFirst = 4; nFirst >= 0; --nFirst)
	{
		CString strCost;
		for (int i = 0; i < nFirst; ++i)
			strCost += strColor1;
		for (int i = nFirst; i < 4; ++i)
			strCost += strColor2;

		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, strCost, 2));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CAzoriusLocketCard::CAzoriusLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Azorius Locket"), nID, WHITE_MANA_TEXT, BLUE_MANA_TEXT)
{
}

CGruulLocketCard::CGruulLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Gruul Locket"), nID, RED_MANA_TEXT, GREEN_MANA_TEXT)
{
}

COrzhovLocketCard::COrzhovLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Orzhov Locket"), nID, WHITE_MANA_TEXT, BLACK_MANA_TEXT)
{
}

CRakdosLocketCard::CRakdosLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Rakdos Locket"), nID, BLACK_MANA_TEXT, RED_MANA_TEXT)
{
}

CSimicLocketCard::CSimicLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Simic Locket"), nID, GREEN_MANA_TEXT, BLUE_MANA_TEXT)
{
}

//____________________________________________________________________________
//
CGlassOfTheGuildpactCard::CGlassOfTheGuildpactCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Glass of the Guildpact"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// Multicolored creatures you control get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new CardMulticoloredComparer),
			Power(+1), Life(+1)));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CScreamingShieldCard::CScreamingShieldCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Screaming Shield"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature gets +0/+3 and has "{2}, {T}: Target player mills three cards." Equip {3}
	// (the ability is granted as Sorcerer's Wand in Dominaria)
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+3), this,
		PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE));
	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CScreamingShieldCard::CreateMillAbility)));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CScreamingShieldCard::BeforeEquip));
	AddAbility(cpAbility.GetPointer());
}

bool CScreamingShieldCard::BeforeEquip(CAbilityAction* pAction)
{
	UnequipAll(this);
	return true;
}

counted_ptr<CAbility> CScreamingShieldCard::CreateMillAbility(CCard* pCard)
{
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(pCard,
			_T("2"),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CScreamingShieldCard::BeforeMill));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CScreamingShieldCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 3);
	return false;
}

//____________________________________________________________________________
//
CTomeOfTheGuildpactCard::CTomeOfTheGuildpactCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Tome of the Guildpact"), CardType::Artifact, nID,
		_T("5"), AbilityType::Artifact)
{
	// Whenever you cast a multicolored spell, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardMulticoloredComparer);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTomeOfTheGuildpactCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);
}

bool CTomeOfTheGuildpactCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define BEAST_S_TOKEN_NAME			_T("Beast (S)")
#define BEAST_S_TOKEN_ID			55122
#define FROG_LIZARD_A_TOKEN_NAME	_T("Frog Lizard (A)")
#define FROG_LIZARD_A_TOKEN_ID		55123
#define SPHINX_B_TOKEN_NAME			_T("Sphinx (B)")
#define SPHINX_B_TOKEN_ID			55124
#define GOBLIN_C_TOKEN_NAME			_T("Goblin (C)")
#define GOBLIN_C_TOKEN_ID			2702

// Spectacle: a second spell with the spectacle cost, castable only if an opponent lost life this turn
template <class T>
static void SetSpectacle(T* pCard, CSpell* pSpell, BOOL (T::*condition)(BOOL))
{
	pSpell->SetMainSpell(FALSE);
	pSpell->SetAbilityText(_T("Spectacle. Casts"));
	AddPlayableIf(pCard, pSpell, condition);
}

// The first card of each target group of a CDoubleTargetSpell (NULL if it isn't on the battlefield anymore)
static void GetDoubleTargets(CAbilityAction* pAction, CCard*& pCard1, CCard*& pCard2)
{
	pCard1 = pCard2 = NULL;
	CDoubleTargetSpellAction* pDoubleAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleAction)
		return;

	CCountedCardContainer cards1, cards2;
	pDoubleAction->GetTargetGroup1().GetCardSubjects(cards1);
	pDoubleAction->GetTargetGroup2().GetCardSubjects(cards2);
	if (cards1.GetSize() > 0 && cards1.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		pCard1 = cards1.GetAt(0);
	if (cards2.GetSize() > 0 && cards2.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		pCard2 = cards2.GetAt(0);
}

// All the card targets of the action that are still in their zone
static void GetCardTargets(CAbilityAction* pAction, CCountedCardContainer& cards)
{
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (pTargetAction)
		pTargetAction->GetTargetGroup().GetCardSubjects(cards);
}

// Doubles the number of +1/+1 counters on the creature
static void DoublePlusCounters(CCard* pCard)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;
	int nCount = pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
	if (nCount > 0)
		AddPlusCounter(pCard, nCount);
}

//____________________________________________________________________________
//
CAwakenTheErstwhileCard::CAwakenTheErstwhileCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Awaken the Erstwhile"), CardType::Sorcery, nID)
{
	// Each player discards all the cards in their hand, then creates that many 2/2 black Zombie creature tokens.
	AddSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CAwakenTheErstwhileCard::BeforeResolution);
}

bool CAwakenTheErstwhileCard::BeforeResolution(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
		CCountedCardContainer cards;
		for (int i = 0; i < pHand->GetSize(); ++i)
			cards.AddCard(pHand->GetAt(i), CardPlacement::Top);

		int nCount = 0;
		CMoveCardModifier pDiscard = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pPlayer);
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Hand)
			{
				pDiscard.ApplyTo(cards.GetAt(i));
				++nCount;
			}

		if (nCount > 0)
			CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, nCount).ApplyTo(pPlayer);
	}
	return true;
}

//____________________________________________________________________________
//
CBankruptInBloodCard::CBankruptInBloodCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bankrupt in Blood"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, sacrifice two creatures. Draw three cards.
	CGenericSpell* pSpell = AddSorcery(this, _T("1") BLACK_MANA_TEXT, &CBankruptInBloodCard::BeforeDraw);
	pSpell->GetCost().AddSacrificeCardCost(2, CCardFilter::GetFilter(_T("creatures")));
}

bool CBankruptInBloodCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CBiogenicUpgradeCard::CBiogenicUpgradeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Biogenic Upgrade"), CardType::Sorcery, nID)
{
	// Distribute three +1/+1 counters among one, two, or three target creatures, then double the number of +1/+1
	// counters on each of those creatures. (one spell for each way of distributing the counters)
	{
		CTargetSpell* pSpell = AddCreatureSorcery(this, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Characteristic::Positive,
			&CBiogenicUpgradeCard::BeforeOne);
		pSpell->SetAbilityText(_T("Three counters on one creature. Casts"));
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetAbilityText(_T("Two counters on the first creature and one on the second. Casts"));
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBiogenicUpgradeCard::BeforeTwo));
		AddSpell(cpSpell.GetPointer());
	}
	{
		CTargetSpell* pSpell = AddCreatureSorcery(this, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Characteristic::Positive,
			&CBiogenicUpgradeCard::BeforeThree);
		pSpell->GetTargeting()->SetSubjectCount(3, 3);
		pSpell->SetAbilityText(_T("One counter on each of three creatures. Casts"));
		pSpell->SetMainSpell(FALSE);
	}
}

bool CBiogenicUpgradeCard::BeforeOne(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		AddPlusCounter(pCard, 3);
		DoublePlusCounters(pCard);
	}
	return false;
}

bool CBiogenicUpgradeCard::BeforeTwo(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	AddPlusCounter(pCard1, 2);
	AddPlusCounter(pCard2, 1);
	DoublePlusCounters(pCard1);
	DoublePlusCounters(pCard2);
	return false;
}

bool CBiogenicUpgradeCard::BeforeThree(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
		AddPlusCounter(cards.GetAt(i), 1);
	for (int i = 0; i < cards.GetSize(); ++i)
		DoublePlusCounters(cards.GetAt(i));
	return false;
}

//____________________________________________________________________________
//
CBringToTrialCard::CBringToTrialCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bring to Trial"), CardType::Sorcery, nID)
{
	// Exile target creature with power 4 or greater.
	AddMoveSorcery(this, _T("2") WHITE_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)),
		ZoneId::Exile, MoveType::Others);
}

//____________________________________________________________________________
//
CCarnivalCarnageCard::CCarnivalCarnageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Carnival // Carnage"), CardType::Instant | CardType::Sorcery, nID)
{
	// Carnival {B/R}: Carnival deals 1 damage to target creature or planeswalker and 1 damage to that permanent's
	// controller.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 1, BLACK_MANA_TEXT, RED_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				costs[i],
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCarnivalCarnageCard::BeforeCarnival));
		SetSplitHalf(cpSpell.GetPointer(), _T("Carnival"));
		AddSpell(cpSpell.GetPointer());
	}

	// Carnage {2}{B}{R}: Carnage deals 3 damage to target opponent. That player discards two cards.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("2") BLACK_MANA_TEXT RED_MANA_TEXT, &CCarnivalCarnageCard::BeforeCarnage);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	SetSplitHalf(pSpell, _T("Carnage"));
}

bool CCarnivalCarnageCard::BeforeCarnival(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pController = pCard->GetController();
	if (pCard->GetCardType().IsCreature())
		DealDamageToCreature(this, pCard, 1);
	else
		CCardCounterModifier(LOYALTY_COUNTER, -1).ApplyTo(pCard);
	DealDamageToPlayer(this, pController, 1);
	return false;
}

bool CCarnivalCarnageCard::BeforeCarnage(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		DealDamageToPlayer(this, pPlayer, 3);
		DiscardCards(GetGame(), pPlayer, 2);
	}
	return false;
}

//____________________________________________________________________________
//
CClearTheMindCard::CClearTheMindCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Clear the Mind"), CardType::Sorcery, nID)
{
	// Target player shuffles their graveyard into their library. Draw a card.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("2") BLUE_MANA_TEXT, &CClearTheMindCard::BeforeResolution);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Neutral);
}

bool CClearTheMindCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		CZone* pGraveyard = pPlayer->GetZoneById(ZoneId::Graveyard);
		CCountedCardContainer cards;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
			cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

		CMoveCardModifier pMove = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pPlayer);
		for (int i = 0; i < cards.GetSize(); ++i)
			pMove.ApplyTo(cards.GetAt(i));
		pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
	}

	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CConsecrateConsumeCard::CConsecrateConsumeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Consecrate // Consume"), CardType::Instant | CardType::Sorcery, nID)
{
	// Consecrate {1}{W/B}: Exile target card from a graveyard. Draw a card.
	std::vector<CString> costs;
	GetHybridCosts(_T("1"), 1, WHITE_MANA_TEXT, BLACK_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				costs[i],
				new TrueCardComparer,
				ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConsecrateConsumeCard::BeforeConsecrate));
		SetSplitHalf(cpSpell.GetPointer(), _T("Consecrate"));
		AddSpell(cpSpell.GetPointer());
	}

	// Consume {2}{W}{B}: Target player sacrifices a creature with the greatest power among creatures they control. You
	// gain life equal to its power.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, &CConsecrateConsumeCard::BeforeConsume);
	SetSplitHalf(pSpell, _T("Consume"));
}

bool CConsecrateConsumeCard::BeforeConsecrate(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

bool CConsecrateConsumeCard::BeforeConsume(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	// Partial: if several creatures share the greatest power, the first one is sacrificed (the player doesn't choose)
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	CCreatureCard* pBest = NULL;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && (!pBest || pCreature->GetPower() > pBest->GetPower()))
			pBest = pCreature;
	}
	if (!pBest)
		return false;

	int nPower = GET_INTEGER(pBest->GetPower());
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pPlayer).ApplyTo(pBest);
	if (nPower > 0)
		GainLife(this, pAction->GetController(), nPower);
	return false;
}

//____________________________________________________________________________
//
CConsignToThePitCard::CConsignToThePitCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Consign to the Pit"), CardType::Sorcery, nID)
{
	// Destroy target creature. Consign to the Pit deals 2 damage to that creature's controller.
	AddCreatureSorcery(this, _T("5") BLACK_MANA_TEXT, Characteristic::Negative, &CConsignToThePitCard::BeforeResolution);
}

bool CConsignToThePitCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pController = pCard->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	DealDamageToPlayer(this, pController, 2);
	return false;
}

//____________________________________________________________________________
//
CCryOfTheCarnariumCard::CCryOfTheCarnariumCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cry of the Carnarium"), CardType::Sorcery, nID)
{
	// All creatures get -2/-2 until end of turn. Exile all creature cards in all graveyards that were put there from the
	// battlefield this turn. If a creature would die this turn, exile it instead.
	// Partial: the creature cards that died earlier this turn aren't exiled, and the replacement only applies to the
	// creatures on the battlefield when it resolves.
	AddSorcery(this, _T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CCryOfTheCarnariumCard::BeforeResolution);
}

bool CCryOfTheCarnariumCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), NULL, FALSE, creatures);

	// "If a creature would die this turn, exile it instead" (as Necrotic Wound)
	CReplacementKeywordModifier pModifier;
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pModifier.ApplyTo(creatures.GetAt(i));

	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), -2, -2);
	return true;
}

//____________________________________________________________________________
//
CDeadRevelsCard::CDeadRevelsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dead Revels"), CardType::Sorcery, nID)
{
	// Spectacle {1}{B}. Return up to two target creature cards from your graveyard to your hand.
	LPCTSTR costs[] = { _T("3") BLACK_MANA_TEXT, _T("1") BLACK_MANA_TEXT };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				costs[i],
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetSubjectCount(0, 2);
		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		if (i == 1)
			SetSpectacle(this, cpSpell.GetPointer(), &CDeadRevelsCard::CanSpectacle);
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CDeadRevelsCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

//____________________________________________________________________________
//
CDefaceCard::CDefaceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deface"), CardType::Sorcery, nID)
{
	// Choose one - Destroy target artifact; or Destroy target creature with defender.
	CTargetMoveCardSpell* pSpell1 = AddMoveSorcery(this, RED_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact, false), ZoneId::Graveyard, MoveType::Destroy);
	pSpell1->SetAbilityText(_T("Destroy target artifact. Casts"));

	CTargetMoveCardSpell* pSpell2 = AddMoveSorcery(this, RED_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Defender, false)),
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell2->SetAbilityText(_T("Destroy target creature with defender. Casts"));
}

//____________________________________________________________________________
//
CDrillBitCard::CDrillBitCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Drill Bit"), CardType::Sorcery, nID)
	, m_NonlandFilter(_T("a nonland card"), _T("nonland cards"), new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Spectacle {B}. Target player reveals their hand. You choose a nonland card from it. That player discards that card.
	// (as Dark Inquiry in Rivals of Ixalan)
	LPCTSTR costs[] = { _T("2") BLACK_MANA_TEXT, BLACK_MANA_TEXT };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
			::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
				costs[i],
				1, MoveType::Discard, ZoneId::Graveyard, TRUE,
				FALSE,
				&m_NonlandFilter));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		if (i == 1)
			SetSpectacle(this, cpSpell.GetPointer(), &CDrillBitCard::CanSpectacle);
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CDrillBitCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

//____________________________________________________________________________
//
CGatesAblazeCard::CGatesAblazeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gates Ablaze"), CardType::Sorcery, nID)
{
	// Gates Ablaze deals X damage to each creature, where X is the number of Gates you control.
	AddSorcery(this, _T("2") RED_MANA_TEXT, &CGatesAblazeCard::BeforeResolution);
}

bool CGatesAblazeCard::BeforeResolution(CAbilityAction* pAction)
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	int nX = CCardFilter::GetFilter(_T("Gates"))->CountIncluded(pBattlefield->GetCardContainer());
	if (nX > 0)
		DamageEachCreature(this, nX, FALSE);
	return true;
}

//____________________________________________________________________________
//
CGoblinGatheringCard::CGoblinGatheringCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Goblin Gathering"), CardType::Sorcery, nID)
{
	// Create a number of 1/1 red Goblin creature tokens equal to two plus the number of cards named Goblin Gathering in
	// your graveyard.
	AddSorcery(this, _T("2") RED_MANA_TEXT, &CGoblinGatheringCard::BeforeResolution);
}

bool CGoblinGatheringCard::BeforeResolution(CAbilityAction* pAction)
{
	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nCount = 2;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i) != this && CString(pGraveyard->GetAt(i)->GetCardName(FALSE)) == _T("Goblin Gathering"))
			++nCount;

	CTokenCreationModifier(GetGame(), GOBLIN_C_TOKEN_NAME, GOBLIN_C_TOKEN_ID, nCount).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CIncubationIncongruityCard::CIncubationIncongruityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Incubation // Incongruity"), CardType::Instant | CardType::Sorcery, nID)
{
	// Incubation {G/U}: Look at the top five cards of your library. You may reveal a creature card from among them and
	// put it into your hand. Put the rest on the bottom of your library in a random order.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 1, GREEN_MANA_TEXT, BLUE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		SetSplitHalf(AddSorcery(this, costs[i], &CIncubationIncongruityCard::BeforeIncubation), _T("Incubation"));

	// Incongruity {1}{G}{U}: Exile target creature. That creature's controller creates a 3/3 green Frog Lizard creature
	// token.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIncubationIncongruityCard::BeforeIncongruity));
	SetSplitHalf(cpSpell.GetPointer(), _T("Incongruity"));
	AddSpell(cpSpell.GetPointer());
}

bool CIncubationIncongruityCard::BeforeIncubation(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 5, 0, 1, CCardFilter::GetFilter(_T("creatures")));
	return true;
}

bool CIncubationIncongruityCard::BeforeIncongruity(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pController = pCard->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	CTokenCreationModifier(GetGame(), FROG_LIZARD_A_TOKEN_NAME, FROG_LIZARD_A_TOKEN_ID, 1).ApplyTo(pController);
	return false;
}

//____________________________________________________________________________
//
CKayasWrathCard::CKayasWrathCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Kaya's Wrath"), CardType::Sorcery, nID)
{
	// Destroy all creatures. You gain life equal to the number of creatures you controlled that were destroyed this way.
	AddSorcery(this, WHITE_MANA_TEXT WHITE_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, &CKayasWrathCard::BeforeResolution);
}

bool CKayasWrathCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nBefore = CountCreatures(GetGame(), pController);
	DestroyAll(GetGame(), AnyCreatureComparer());
	int nDestroyed = nBefore - CountCreatures(GetGame(), pController);
	if (nDestroyed > 0)
		GainLife(this, pController, nDestroyed);
	return true;
}

//____________________________________________________________________________
//
CMassManipulationCard::CMassManipulationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mass Manipulation"), CardType::Sorcery, nID)
{
	// Gain control of X target creatures and/or planeswalkers.
	// (one spell for each X from 1 to 6: {X}{X} is 2X generic mana)
	for (int nX = 1; nX <= 6; ++nX)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				MakeCost(2 * nX, BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT),
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), FALSE));

		cpSpell->GetTargeting()->SetSubjectCount(nX, nX);
		cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		CString strText;
		strText.Format(_T("Mass Manipulation with X = %d. Casts"), nX);
		cpSpell->SetAbilityText(strText);
		if (nX > 1)
			cpSpell->SetMainSpell(FALSE);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMassManipulationCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CMassManipulationCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	CGainControlModifier pModifier = CGainControlModifier(GetGame(), this);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(cards.GetAt(i));
	return false;
}

//____________________________________________________________________________
//
COpenTheGatesCard::COpenTheGatesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Open the Gates"), CardType::Sorcery, nID)
	, m_Filter(_T("a basic land card or Gate card"), _T("basic land cards or Gate cards"),
		new OrCardComparer(new CardTypeComparer(CardType::BasicLand, false), new CardTypeComparer(CardType::Gate, false)))
{
	// Search your library for a basic land card or Gate card, reveal it, put it into your hand, then shuffle.
	AddSorcery(this, GREEN_MANA_TEXT, &COpenTheGatesCard::BeforeResolution);
}

bool COpenTheGatesCard::BeforeResolution(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, &m_Filter);
	return true;
}

//____________________________________________________________________________
//
CRagefireCard::CRagefireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ragefire"), CardType::Sorcery, nID)
{
	// Ragefire deals 3 damage to target creature.
	AddDamageSorcery(this, _T("1") RED_MANA_TEXT, 3, new AnyCreatureComparer, FALSE);
}

//____________________________________________________________________________
//
CRepudiateReplicateCard::CRepudiateReplicateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Repudiate // Replicate"), CardType::Instant | CardType::Sorcery, nID)
{
	// Repudiate {G/U}{G/U}: Counter target activated or triggered ability.
	// Not implemented: the engine can't counter abilities.

	// Replicate {1}{G}{U}: Create a token that's a copy of target creature you control.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Characteristic::Positive,
		&CRepudiateReplicateCard::BeforeReplicate);
	pSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	SetSplitHalf(pSpell, _T("Replicate"));
}

bool CRepudiateReplicateCard::BeforeReplicate(CAbilityAction* pAction)
{
	// (as Quasiduplicate in Guilds of Ravnica)
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CCardCopyModifier(GetGame(), this).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CRevivalRevengeCard::CRevivalRevengeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Revival // Revenge"), CardType::Sorcery, nID)
{
	// Revival {W/B}{W/B}: Return target creature card with mana value 3 or less from your graveyard to the battlefield.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, WHITE_MANA_TEXT, BLACK_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				costs[i],
				new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::less_equal<int>>(3)),
				ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		SetSplitHalf(cpSpell.GetPointer(), _T("Revival"));
		AddSpell(cpSpell.GetPointer());
	}

	// Revenge {4}{W}{B}: Double your life total. Target opponent loses half their life, rounded up.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("4") WHITE_MANA_TEXT BLACK_MANA_TEXT, &CRevivalRevengeCard::BeforeRevenge);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	SetSplitHalf(pSpell, _T("Revenge"));
}

bool CRevivalRevengeCard::BeforeRevenge(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nLife = GET_INTEGER(pController->GetLife());
	if (nLife > 0)
		GainLife(this, pController, nLife);

	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		int nOpponentLife = GET_INTEGER(pPlayer->GetLife());
		int nLoss = (nOpponentLife + 1) / 2;
		if (nLoss > 0)
			CLifeModifier(Life(-nLoss), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	}
	return false;
}

//____________________________________________________________________________
//
CRubbleReadingCard::CRubbleReadingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rubble Reading"), CardType::Sorcery, nID)
{
	// Destroy target land. Scry 2.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("3") RED_MANA_TEXT,
		new CardTypeComparer(CardType::_Land, false), ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRubbleReadingCard::BeforeScry));
}

bool CRubbleReadingCard::BeforeScry(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CSavageSmashCard::CSavageSmashCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Savage Smash"), CardType::Sorcery, nID)
{
	// Target creature you control gets +2/+2 until end of turn. It fights target creature you don't control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSavageSmashCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSavageSmashCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (pCard1)
	{
		PumpCreature(pCard1, +2, +2);
		if (pCard2)
			Fight(pCard1, pCard2);
	}
	return false;
}

//____________________________________________________________________________
//
CShimmerOfPossibilityCard::CShimmerOfPossibilityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shimmer of Possibility"), CardType::Sorcery, nID)
{
	// Look at the top four cards of your library. Put one of them into your hand and the rest on the bottom of your
	// library in a random order.
	AddSorcery(this, _T("1") BLUE_MANA_TEXT, &CShimmerOfPossibilityCard::BeforeResolution);
}

bool CShimmerOfPossibilityCard::BeforeResolution(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 4, 1, 1, CCardFilter::GetFilter(_T("cards")));
	return true;
}

//____________________________________________________________________________
//
CSkewerTheCriticsCard::CSkewerTheCriticsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Skewer the Critics"), CardType::Sorcery, nID)
{
	// Spectacle {R}. Skewer the Critics deals 3 damage to any target. (it can't target planeswalkers)
	AddDamageSorcery(this, _T("2") RED_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	CTargetChgLifeSpell* pSpell = AddDamageSorcery(this, RED_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	SetSpectacle(this, pSpell, &CSkewerTheCriticsCard::CanSpectacle);
}

BOOL CSkewerTheCriticsCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

//____________________________________________________________________________
//
CSwirlingTorrentCard::CSwirlingTorrentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Swirling Torrent"), CardType::Sorcery, nID)
{
	// Choose one or both - Put target creature on top of its owner's library; Return target creature to its owner's
	// hand. (one spell for each choice, as Deafening Clarion)
	CTargetSpell* pSpell1 = AddCreatureSorcery(this, _T("5") BLUE_MANA_TEXT, Characteristic::Negative, &CSwirlingTorrentCard::BeforeTop);
	pSpell1->SetAbilityText(_T("Put target creature on top of its owner's library. Casts"));

	CTargetSpell* pSpell2 = AddCreatureSorcery(this, _T("5") BLUE_MANA_TEXT, Characteristic::Negative, &CSwirlingTorrentCard::BeforeBounce);
	pSpell2->SetAbilityText(_T("Return target creature to its owner's hand. Casts"));
	pSpell2->SetMainSpell(FALSE);

	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("5") BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetAbilityText(_T("Both: the first creature on top of its owner's library, the second to its owner's hand. Casts"));
	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSwirlingTorrentCard::BeforeBoth));
	AddSpell(cpSpell.GetPointer());
}

bool CSwirlingTorrentCard::BeforeTop(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

bool CSwirlingTorrentCard::BeforeBounce(CAbilityAction* pAction)
{
	BounceCreature(GetTargetCreature(pAction));
	return false;
}

bool CSwirlingTorrentCard::BeforeBoth(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (pCard1 && pCard1 != pCard2)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard1);
	BounceCreature(pCard2);
	return false;
}

//____________________________________________________________________________
//
CThrashThreatCard::CThrashThreatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thrash // Threat"), CardType::Instant | CardType::Sorcery, nID)
{
	// Thrash {R/G}{R/G}: Target creature you control deals damage equal to its power to target creature or planeswalker
	// you don't control.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, RED_MANA_TEXT, GREEN_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				costs[i],
				new AnyCreatureComparer, FALSE,
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), FALSE, _T("")));

		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThrashThreatCard::BeforeThrash));
		SetSplitHalf(cpSpell.GetPointer(), _T("Thrash"));
		AddSpell(cpSpell.GetPointer());
	}

	// Threat {2}{R}{G}: Create a 4/4 red and green Beast creature token with trample.
	SetSplitHalf(AddSorcery(this, _T("2") RED_MANA_TEXT GREEN_MANA_TEXT, &CThrashThreatCard::BeforeThreat), _T("Threat"));
}

bool CThrashThreatCard::BeforeThrash(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard1);
	if (!pCreature || !pCard2)
		return false;

	int nPower = GET_INTEGER(pCreature->GetPower());
	if (nPower <= 0)
		return false;

	if (pCard2->GetCardType().IsCreature())
		DealDamageToCreature(pCreature, pCard2, nPower);
	else
		CCardCounterModifier(LOYALTY_COUNTER, -nPower).ApplyTo(pCard2);
	return false;
}

bool CThrashThreatCard::BeforeThreat(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), BEAST_S_TOKEN_NAME, BEAST_S_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CWarrantWardenCard::CWarrantWardenCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Warrant // Warden"), CardType::Instant | CardType::Sorcery, nID)
{
	// Warrant {W/U}{W/U}: Put target attacking or blocking creature on top of its owner's library.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, WHITE_MANA_TEXT, BLUE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				costs[i],
				new AttackingBlockingCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWarrantWardenCard::BeforeWarrant));
		SetSplitHalf(cpSpell.GetPointer(), _T("Warrant"));
		AddSpell(cpSpell.GetPointer());
	}

	// Warden {3}{W}{U}: Create a 4/4 white and blue Sphinx creature token with flying and vigilance.
	SetSplitHalf(AddSorcery(this, _T("3") WHITE_MANA_TEXT BLUE_MANA_TEXT, &CWarrantWardenCard::BeforeWarden), _T("Warden"));
}

bool CWarrantWardenCard::BeforeWarrant(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

bool CWarrantWardenCard::BeforeWarden(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), SPHINX_B_TOKEN_NAME, SPHINX_B_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define CENTAUR_E_TOKEN_NAME		_T("Centaur (E)")
#define CENTAUR_E_TOKEN_ID			55125

// "If you control a creature with power 4 or greater" (RNA, Gruul)
static BOOL ControlsPowerFourCreature(CPlayer* pPlayer)
{
	CCountedCardContainer creatures;
	GetCreatures(pPlayer->GetGame(), pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && pCreature->GetPower() >= Power(4))
			return TRUE;
	}
	return FALSE;
}

// The permanents (or cards) on pPlayer's battlefield that pass the comparer
static void GetPermanents(CPlayer* pPlayer, const CardComparer& comparer, CCountedCardContainer& cards)
{
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (comparer(pBattlefield->GetAt(i)))
			cards.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
}

//____________________________________________________________________________
//
CAppliedBiomancyCard::CAppliedBiomancyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Applied Biomancy"), CardType::Instant, nID)
{
	// Choose one or both - Target creature gets +1/+1 until end of turn; Return target creature to its owner's hand.
	// (one spell for each choice, as Deafening Clarion)
	CTargetChgPwrTghAttrSpell* pSpell1 = AddPumpInstant(this, GREEN_MANA_TEXT BLUE_MANA_TEXT, +1, +1);
	pSpell1->SetAbilityText(_T("Target creature gets +1/+1 until end of turn. Casts"));

	CTargetMoveCardSpell* pSpell2 = AddMoveInstant(this, GREEN_MANA_TEXT BLUE_MANA_TEXT, new AnyCreatureComparer,
		ZoneId::Hand, MoveType::Others);
	pSpell2->SetAbilityText(_T("Return target creature to its owner's hand. Casts"));
	pSpell2->SetMainSpell(FALSE);

	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetAbilityText(_T("Both: the first creature gets +1/+1, the second returns to its owner's hand. Casts"));
	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAppliedBiomancyCard::BeforeBoth));
	AddSpell(cpSpell.GetPointer());
}

bool CAppliedBiomancyCard::BeforeBoth(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (pCard1)
		PumpCreature(pCard1, +1, +1);
	BounceCreature(pCard2);
	return false;
}

//____________________________________________________________________________
//
CArrestersAdmonitionCard::CArrestersAdmonitionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Arrester's Admonition"), CardType::Instant, nID)
{
	// Return target creature to its owner's hand. Addendum - If you cast this spell during your main phase, draw a card.
	AddCreatureInstant(this, _T("2") BLUE_MANA_TEXT, Characteristic::Negative, &CArrestersAdmonitionCard::BeforeResolution);
}

bool CArrestersAdmonitionCard::BeforeResolution(CAbilityAction* pAction)
{
	BounceCreature(GetTargetCreature(pAction));
	if (IsYourMainPhase(pAction->GetController()))
		DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CArrestersZealCard::CArrestersZealCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Arrester's Zeal"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 until end of turn. Addendum - If you cast this spell during your main phase, that
	// creature gains flying until end of turn.
	AddCreatureInstant(this, WHITE_MANA_TEXT, Characteristic::Positive, &CArrestersZealCard::BeforeResolution);
}

bool CArrestersZealCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		if (IsYourMainPhase(pAction->GetController()))
			PumpCreature(pCard, +2, +2, CreatureKeyword::Flying);
		else
			PumpCreature(pCard, +2, +2);
	}
	return false;
}

//____________________________________________________________________________
//
CBedeckBedazzleCard::CBedeckBedazzleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bedeck // Bedazzle"), CardType::Instant, nID)
{
	// Bedeck {B/R}{B/R}: Target creature gets +3/-3 until end of turn.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, BLACK_MANA_TEXT, RED_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, costs[i], +3, -3);
		pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		SetSplitHalf(pSpell, _T("Bedeck"));
	}

	// Bedazzle {4}{B}{R}: Destroy target nonbasic land. Bedazzle deals 2 damage to target opponent or planeswalker.
	// (it can't target planeswalkers)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("4") BLACK_MANA_TEXT RED_MANA_TEXT,
			new CardTypeComparer(CardType::NonbasicLand, false), FALSE,
			FALSE_CARD_COMPARER, TRUE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBedeckBedazzleCard::BeforeBedazzle));
	SetSplitHalf(cpSpell.GetPointer(), _T("Bedazzle"));
	AddSpell(cpSpell.GetPointer());
}

bool CBedeckBedazzleCard::BeforeBedazzle(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleAction)
		return false;

	CCountedCardContainer lands;
	pDoubleAction->GetTargetGroup1().GetCardSubjects(lands);
	if (lands.GetSize() > 0 && lands.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(lands.GetAt(0));

	CPlayer* pPlayer = (CPlayer*)pDoubleAction->GetTargetGroup2().GetFirstPlayerSubject();
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 2);
	return false;
}

//____________________________________________________________________________
//
CBedevilCard::CBedevilCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bedevil"), CardType::Instant, nID)
{
	// Destroy target artifact, creature, or planeswalker.
	AddMoveInstant(this, BLACK_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::Planeswalker, false),
		ZoneId::Graveyard, MoveType::Destroy);
}

//____________________________________________________________________________
//
CBladebrandCard::CBladebrandCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bladebrand"), CardType::Instant, nID)
{
	// Target creature gains deathtouch until end of turn. Draw a card.
	AddCreatureInstant(this, _T("1") BLACK_MANA_TEXT, Characteristic::Positive, &CBladebrandCard::BeforeResolution);
}

bool CBladebrandCard::BeforeResolution(CAbilityAction* pAction)
{
	GainCardKeyword(GetTargetCreature(pAction), CardKeyword::Deathtouch);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CBurnBrightCard::CBurnBrightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Burn Bright"), CardType::Instant, nID)
{
	// Creatures you control get +2/+0 until end of turn.
	AddInstant(this, _T("2") RED_MANA_TEXT, &CBurnBrightCard::BeforeResolution);
}

bool CBurnBrightCard::BeforeResolution(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +2, 0);
	return true;
}

//____________________________________________________________________________
//
CClearTheStageCard::CClearTheStageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Clear the Stage"), CardType::Instant, nID)
{
	// Target creature gets -3/-3 until end of turn. If you control a creature with power 4 or greater, you may return up
	// to one target creature card from your graveyard to your hand.
	// Partial: the creature card is chosen on resolution (it isn't a target).
	AddCreatureInstant(this, _T("4") BLACK_MANA_TEXT, Characteristic::Negative, &CClearTheStageCard::BeforeResolution);
}

bool CClearTheStageCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, -3, -3);

	if (ControlsPowerFourCreature(pAction->GetController()))
		ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 0, 1, CCardFilter::GetFilter(_T("creatures")),
			ZoneId::Hand, MoveType::Others);
	return false;
}

//____________________________________________________________________________
//
CCodeOfConstraintCard::CCodeOfConstraintCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Code of Constraint"), CardType::Instant, nID)
{
	// Target creature gets -4/-0 until end of turn. Draw a card. Addendum - If you cast this spell during your main
	// phase, tap that creature and it doesn't untap during its controller's next untap step.
	AddCreatureInstant(this, _T("2") BLUE_MANA_TEXT, Characteristic::Negative, &CCodeOfConstraintCard::BeforeResolution);
}

bool CCodeOfConstraintCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		PumpCreature(pCard, -4, 0);
		if (IsYourMainPhase(pAction->GetController()))
			TapAndSkipUntap(pCard);
	}
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CCollisionColossusCard::CCollisionColossusCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Collision // Colossus"), CardType::Instant, nID)
{
	// Collision {1}{R/G}: Collision deals 6 damage to target creature with flying.
	std::vector<CString> costs;
	GetHybridCosts(_T("1"), 1, RED_MANA_TEXT, GREEN_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		CTargetChgLifeSpell* pSpell = AddDamageInstant(this, costs[i], 6,
			new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false)), FALSE);
		SetSplitHalf(pSpell, _T("Collision"));
	}

	// Colossus {R}{G}: Target creature gets +4/+2 and gains trample until end of turn.
	SetSplitHalf(AddPumpInstant(this, RED_MANA_TEXT GREEN_MANA_TEXT, +4, +2, CreatureKeyword::Trample), _T("Colossus"));
}

//____________________________________________________________________________
//
CDeposeDeployCard::CDeposeDeployCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Depose // Deploy"), CardType::Instant, nID)
{
	// Depose {1}{W/U}: Tap target creature. Draw a card.
	std::vector<CString> costs;
	GetHybridCosts(_T("1"), 1, WHITE_MANA_TEXT, BLUE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		SetSplitHalf(AddCreatureInstant(this, costs[i], Characteristic::Negative, &CDeposeDeployCard::BeforeDepose), _T("Depose"));

	// Deploy {2}{W}{U}: Create two 1/1 colorless Thopter artifact creature tokens with flying, then you gain 1 life for
	// each creature you control.
	SetSplitHalf(AddInstant(this, _T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, &CDeposeDeployCard::BeforeDeploy), _T("Deploy"));
}

bool CDeposeDeployCard::BeforeDepose(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

bool CDeposeDeployCard::BeforeDeploy(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), THOPTER_D_TOKEN_NAME, THOPTER_D_TOKEN_ID, 2).ApplyTo(pAction->GetController());
	int nCount = CountCreatures(GetGame(), pAction->GetController());
	if (nCount > 0)
		GainLife(this, pAction->GetController(), nCount);
	return true;
}

//____________________________________________________________________________
//
CDovinsDismissalCard::CDovinsDismissalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dovin's Dismissal"), CardType::Instant, nID)
{
	// Put up to one target tapped creature on top of its owner's library. You may search your library and/or graveyard
	// for a card named Dovin, Architect of Law, reveal it, and put it into your hand. If you search your library this
	// way, shuffle.
	CTargetSpell* pSpell = AddCreatureInstant(this, _T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, Characteristic::Negative,
		&CDovinsDismissalCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
	pSpell->GetTargeting()->SetSubjectCount(0, 1);
}

bool CDovinsDismissalCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() > 0 && cards.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(cards.GetAt(0));

	SearchNamedCardToHand(pAction->GetController(), _T("Dovin, Architect of Law"));
	return false;
}

//____________________________________________________________________________
//
CElectrodominanceCard::CElectrodominanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Electrodominance"), CardType::Instant, nID)
{
	// Electrodominance deals X damage to any target. You may cast a spell with mana value X or less from your hand
	// without paying its mana cost.
	// Partial: the free spell isn't implemented (the engine can't cast spells without paying their cost).
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CElectrodominanceCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CElectrodominanceCard::BeforeResolution(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0)
		DealDamageToTarget(this, pAction, nX);
	return false;
}

//____________________________________________________________________________
//
CEmergencyPowersCard::CEmergencyPowersCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Emergency Powers"), CardType::Instant, nID)
	, m_PermanentFilter(_T("a permanent card with mana value 7 or less"), _T("permanent cards with mana value 7 or less"),
		new AndCardComparer(new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)),
			new ConvertedManaCostComparer<std::less_equal<int>>(7)))
{
	// Each player shuffles their hand and graveyard into their library, then draws seven cards. Exile Emergency Powers.
	// Addendum - If you cast this spell during your main phase, you may put a permanent card with mana value 7 or less
	// from your hand onto the battlefield.
	CGenericSpell* pSpell = AddInstant(this, _T("5") WHITE_MANA_TEXT BLUE_MANA_TEXT, &CEmergencyPowersCard::BeforeResolution);
	pSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
}

bool CEmergencyPowersCard::BeforeResolution(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		ZoneId zones[] = { ZoneId::Hand, ZoneId::Graveyard };
		for (int z = 0; z < 2; ++z)
		{
			CZone* pZone = pPlayer->GetZoneById(zones[z]);
			CCountedCardContainer cards;
			for (int i = 0; i < pZone->GetSize(); ++i)
				if (pZone->GetAt(i) != this)
					cards.AddCard(pZone->GetAt(i), CardPlacement::Top);

			CMoveCardModifier pMove = CMoveCardModifier(zones[z], ZoneId::Library, TRUE, MoveType::Others, pPlayer);
			for (int i = 0; i < cards.GetSize(); ++i)
				pMove.ApplyTo(cards.GetAt(i));
		}
		pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
		DrawCards(GetGame(), pPlayer, 7);
	}

	if (IsYourMainPhase(pAction->GetController()))
		ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, &m_PermanentFilter, ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CEssenceCaptureCard::CEssenceCaptureCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Essence Capture"), CardType::Instant, nID)
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CEssenceCaptureCard::OnCreatureSelected))
{
	// Counter target creature spell. Put a +1/+1 counter on up to one target creature you control.
	// Partial: the creature that gets the counter is chosen on resolution (it isn't a target).
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Creature, false)));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEssenceCaptureCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CEssenceCaptureCard::BeforeResolution(CAbilityAction* pAction)
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
		entry.strText.Format(_T("Put a +1/+1 counter on %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 0, 1, this, pAction->GetController());
	return true;
}

void CEssenceCaptureCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			AddPlusCounter((CCard*)it->dwContext, 1);
}

//____________________________________________________________________________
//
CExposeToDaylightCard::CExposeToDaylightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Expose to Daylight"), CardType::Instant, nID)
{
	// Destroy target artifact or enchantment. Scry 1.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("2") WHITE_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false), ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExposeToDaylightCard::BeforeScry));
}

bool CExposeToDaylightCard::BeforeScry(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CFinalPaymentCard::CFinalPaymentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Final Payment"), CardType::Instant, nID)
	, m_SacrificeFilter(_T("a creature or enchantment"), _T("creatures or enchantments"),
		new CardTypeComparer(CardType::Creature | CardType::_Enchantment, false))
{
	// As an additional cost to cast this spell, pay 5 life or sacrifice a creature or enchantment. Destroy target
	// creature. (one spell for each additional cost)
	CTargetMoveCardSpell* pSpell1 = AddMoveInstant(this, WHITE_MANA_TEXT BLACK_MANA_TEXT, new AnyCreatureComparer,
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell1->AddPayLifeDeltaCost(Life(-5));
	pSpell1->SetAbilityText(_T("Pay 5 life. Casts"));

	CTargetMoveCardSpell* pSpell2 = AddMoveInstant(this, WHITE_MANA_TEXT BLACK_MANA_TEXT, new AnyCreatureComparer,
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell2->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	pSpell2->SetAbilityText(_T("Sacrifice a creature or enchantment. Casts"));
	pSpell2->SetMainSpell(FALSE);
}

//____________________________________________________________________________
//
CFlamesOfTheRazeBoarCard::CFlamesOfTheRazeBoarCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Flames of the Raze-Boar"), CardType::Instant, nID)
{
	// Flames of the Raze-Boar deals 4 damage to target creature an opponent controls. Then Flames of the Raze-Boar deals
	// 2 damage to each other creature that player controls if you control a creature with power 4 or greater.
	CTargetSpell* pSpell = AddCreatureInstant(this, _T("5") RED_MANA_TEXT, Characteristic::Negative,
		&CFlamesOfTheRazeBoarCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
}

bool CFlamesOfTheRazeBoarCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pPlayer = pCard->GetController();
	DealDamageToCreature(this, pCard, 4);

	if (ControlsPowerFourCreature(pAction->GetController()))
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pPlayer, TRUE, creatures);
		for (int i = 0; i < creatures.GetSize(); ++i)
			if (creatures.GetAt(i) != pCard && creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				DealDamageToCreature(this, creatures.GetAt(i), 2);
	}
	return false;
}

//____________________________________________________________________________
//
CGetThePointCard::CGetThePointCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Get the Point"), CardType::Instant, nID)
{
	// Destroy target creature. Scry 1.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("3") BLACK_MANA_TEXT RED_MANA_TEXT, new AnyCreatureComparer,
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGetThePointCard::BeforeScry));
}

bool CGetThePointCard::BeforeScry(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CGrotesqueDemiseCard::CGrotesqueDemiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grotesque Demise"), CardType::Instant, nID)
{
	// Exile target creature with power 3 or less.
	AddMoveInstant(this, _T("2") BLACK_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::less_equal<int>>(3)),
		ZoneId::Exile, MoveType::Others);
}

//____________________________________________________________________________
//
CGrowthSpiralCard::CGrowthSpiralCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Growth Spiral"), CardType::Instant, nID)
{
	// Draw a card. You may put a land card from your hand onto the battlefield.
	AddInstant(this, GREEN_MANA_TEXT BLUE_MANA_TEXT, &CGrowthSpiralCard::BeforeResolution);
}

bool CGrowthSpiralCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, CCardFilter::GetFilter(_T("lands")),
		ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CJusticiarsPortalCard::CJusticiarsPortalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Justiciar's Portal"), CardType::Instant, nID)
{
	// Exile target creature you control, then return that card to the battlefield under its owner's control. It gains
	// first strike until end of turn.
	CTargetSpell* pSpell = AddCreatureInstant(this, _T("1") WHITE_MANA_TEXT, Characteristic::Positive,
		&CJusticiarsPortalCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeControllerCardsOnly();
}

bool CJusticiarsPortalCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Exile)
	{
		CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			PumpCreature(pCard, 0, 0, CreatureKeyword::FirstStrike);
	}
	return false;
}

//____________________________________________________________________________
//
CMacabreMockeryCard::CMacabreMockeryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Macabre Mockery"), CardType::Instant, nID)
{
	// Put target creature card from an opponent's graveyard onto the battlefield under your control. It gets +2/+0 and
	// gains haste until end of turn. Sacrifice it at the beginning of the next end step.
	// (target in a graveyard as Ethereal Absolution; the callback moves the card and returns false)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMacabreMockeryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CMacabreMockeryCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;

	CPlayer* pController = pAction->GetController();
	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pController).ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	PumpCreature(pCard, +2, 0, CreatureKeyword::Haste);

	// (as Kiki-Jiki, Mirror Breaker)
	CCountedCardContainer cards;
	cards.AddCard(pCard, CardPlacement::Top);
	CContainerEffectModifier(GetGame(), _T("End Step Sacrifice Effect"), 61058, &cards).ApplyTo(pController);
	return false;
}

//____________________________________________________________________________
//
CPrecognitivePerceptionCard::CPrecognitivePerceptionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Precognitive Perception"), CardType::Instant, nID)
{
	// Draw three cards. Addendum - If you cast this spell during your main phase, instead scry 3, then draw three cards.
	AddInstant(this, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, &CPrecognitivePerceptionCard::BeforeResolution);
}

bool CPrecognitivePerceptionCard::BeforeResolution(CAbilityAction* pAction)
{
	if (IsYourMainPhase(pAction->GetController()))
		CScryModifier(GetGame(), 3, this).ApplyTo(pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CPryingEyesCard::CPryingEyesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Prying Eyes"), CardType::Instant, nID)
{
	// Draw four cards, then discard two cards.
	AddInstant(this, _T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, &CPryingEyesCard::BeforeResolution);
}

bool CPryingEyesCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 4);
	DiscardCards(GetGame(), pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CQuenchCard::CQuenchCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Quench"), CardType::Instant, nID)
{
	// Counter target spell unless its controller pays {2}. (as Mana Leak)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetCanBeDenied();
	cpSpell->GetDenialCost().SetManaCost(_T("2"));
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CRallyToBattleCard::CRallyToBattleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rally to Battle"), CardType::Instant, nID)
{
	// Creatures you control get +1/+3 until end of turn. Untap them.
	AddInstant(this, _T("3") WHITE_MANA_TEXT, &CRallyToBattleCard::BeforeResolution);
}

bool CRallyToBattleCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		PumpCreature(creatures.GetAt(i), +1, +3);
		pUntap.ApplyTo(creatures.GetAt(i));
	}
	return true;
}

//____________________________________________________________________________
//
CRampageOfTheClansCard::CRampageOfTheClansCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rampage of the Clans"), CardType::Instant, nID)
{
	// Destroy all artifacts and enchantments. For each permanent destroyed this way, its controller creates a 3/3 green
	// Centaur creature token.
	AddInstant(this, _T("3") GREEN_MANA_TEXT, &CRampageOfTheClansCard::BeforeResolution);
}

bool CRampageOfTheClansCard::BeforeResolution(CAbilityAction* pAction)
{
	CardTypeComparer comparer(CardType::Artifact | CardType::_Enchantment, false);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CCountedCardContainer cards;
		GetPermanents(pPlayer, comparer, cards);

		int nDestroyed = 0;
		CMoveCardModifier pDestroy = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		for (int i = 0; i < cards.GetSize(); ++i)
		{
			CCard* pCard = cards.GetAt(i);
			if (pCard->GetZoneId() != ZoneId::Battlefield)
				continue;
			pDestroy.ApplyTo(pCard);
			if (pCard->GetZoneId() != ZoneId::Battlefield)
				++nDestroyed;
		}

		if (nDestroyed > 0)
			CTokenCreationModifier(GetGame(), CENTAUR_E_TOKEN_NAME, CENTAUR_E_TOKEN_ID, nDestroyed).ApplyTo(pPlayer);
	}
	return true;
}

//____________________________________________________________________________
//
CRegenesisCard::CRegenesisCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Regenesis"), CardType::Instant, nID)
{
	// Return up to two target permanent cards from your graveyard to your hand.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)),
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(0, 2);
	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CSagittarsVolleyCard::CSagittarsVolleyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sagittars' Volley"), CardType::Instant, nID)
{
	// Destroy target creature with flying. Sagittars' Volley deals 1 damage to each creature with flying your opponents
	// control.
	CTargetSpell* pSpell = AddCreatureInstant(this, _T("2") GREEN_MANA_TEXT, Characteristic::Negative,
		&CSagittarsVolleyCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false));
}

bool CSagittarsVolleyCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && pCreature->GetCreatureKeyword()->Flying())
			DealDamageToCreature(this, pCreature, 1);
	}
	return false;
}

//____________________________________________________________________________
//
CScorchmarkCard::CScorchmarkCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Scorchmark"), CardType::Instant, nID)
{
	// Scorchmark deals 2 damage to target creature. If that creature would die this turn, exile it instead.
	// (as Lava Coil in Guilds of Ravnica)
	CTargetChgLifeSpell* pSpell = AddDamageInstant(this, _T("1") RED_MANA_TEXT, 2, new AnyCreatureComparer, FALSE);

	CReplacementKeywordModifier* pModifier = new CReplacementKeywordModifier();
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	pModifier->GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	pSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);
}

//____________________________________________________________________________
//
CSphinxsInsightCard::CSphinxsInsightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sphinx's Insight"), CardType::Instant, nID)
{
	// Draw two cards. Addendum - If you cast this spell during your main phase, you gain 2 life.
	AddInstant(this, _T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, &CSphinxsInsightCard::BeforeResolution);
}

bool CSphinxsInsightCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	if (IsYourMainPhase(pAction->GetController()))
		GainLife(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CStonyStrengthCard::CStonyStrengthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stony Strength"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on target creature you control. Untap that creature.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CStormStrikeCard::CStormStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Storm Strike"), CardType::Instant, nID)
{
	// Target creature gets +1/+0 and gains first strike until end of turn. Scry 1.
	CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, RED_MANA_TEXT, +1, 0, CreatureKeyword::FirstStrike);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStormStrikeCard::BeforeScry));
}

bool CStormStrikeCard::BeforeScry(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +1, 0, CreatureKeyword::FirstStrike);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CSummaryJudgmentCard::CSummaryJudgmentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Summary Judgment"), CardType::Instant, nID)
{
	// Summary Judgment deals 3 damage to target tapped creature. Addendum - If you cast this spell during your main
	// phase, it deals 5 damage instead.
	CTargetSpell* pSpell = AddCreatureInstant(this, _T("1") WHITE_MANA_TEXT, Characteristic::Negative,
		&CSummaryJudgmentCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
}

bool CSummaryJudgmentCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		DealDamageToCreature(this, pCard, IsYourMainPhase(pAction->GetController()) ? 5 : 3);
	return false;
}

//____________________________________________________________________________
//
CThoughtCollapseCard::CThoughtCollapseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thought Collapse"), CardType::Instant, nID)
{
	// Counter target spell. Its controller mills three cards. (as Ionize in Guilds of Ravnica)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThoughtCollapseCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CThoughtCollapseCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pSpellCard = pAction->GetAssociatedCard();
	if (pSpellCard)
		Mill(pSpellCard->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CTitanicBrawlCard::CTitanicBrawlCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Titanic Brawl"), CardType::Instant, nID)
{
	// This spell costs {1} less to cast if it targets a creature you control with a +1/+1 counter on it. Target creature
	// you control fights target creature you don't control.
	// (the cheaper spell requires the first target to have a +1/+1 counter, as Price of Fame)
	LPCTSTR costs[] = { _T("1") GREEN_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				costs[i],
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		if (i == 1)
		{
			cpSpell->GetTargeting1()->GetSubjectCardFilter().AddComparer(new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1));
			cpSpell->SetAbilityText(_T("Targeting a creature with a +1/+1 counter. Casts"));
			cpSpell->SetMainSpell(FALSE);
		}
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTitanicBrawlCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CTitanicBrawlCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (pCard1 && pCard2)
		Fight(pCard1, pCard2);
	return false;
}

//____________________________________________________________________________
//
CUnbreakableFormationCard::CUnbreakableFormationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unbreakable Formation"), CardType::Instant, nID)
{
	// Creatures you control gain indestructible until end of turn. Addendum - If you cast this spell during your main
	// phase, put a +1/+1 counter on each of those creatures and they gain vigilance until end of turn.
	AddInstant(this, _T("2") WHITE_MANA_TEXT, &CUnbreakableFormationCard::BeforeResolution);
}

bool CUnbreakableFormationCard::BeforeResolution(CAbilityAction* pAction)
{
	BOOL bAddendum = IsYourMainPhase(pAction->GetController());
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		GainCardKeyword(pCard, CardKeyword::Indestructible);
		if (bAddendum)
		{
			AddPlusCounter(pCard, 1);
			PumpCreature(pCard, 0, 0, CreatureKeyword::Vigilance);
		}
	}
	return true;
}

//____________________________________________________________________________
//
CUndercitysEmbraceCard::CUndercitysEmbraceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Undercity's Embrace"), CardType::Instant, nID)
{
	// Target opponent sacrifices a creature of their choice. If you control a creature with power 4 or greater, you gain
	// 4 life.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUndercitysEmbraceCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CUndercitysEmbraceCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
			ZoneId::Graveyard, MoveType::Sacrifice);

	if (ControlsPowerFourCreature(pAction->GetController()))
		GainLife(this, pAction->GetController(), 4);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define HUMAN_C_TOKEN_NAME		_T("Human (C)")
#define HUMAN_C_TOKEN_ID		62013

//____________________________________________________________________________
//
CAfterlifeSupport::CAfterlifeSupport(CCard* pCard)
	: m_pCard(pCard)
	, m_nCount(0)
{
}

void CAfterlifeSupport::AddAfterlifeAbility(int nCount)
{
	m_nCount = nCount;

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetAbilityName(_T("Afterlife"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAfterlifeSupport::BeforeTokens));
	m_pCard->AddAbility(cpAbility.GetPointer());
}

bool CAfterlifeSupport::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier(m_pCard->GetGame(), SPIRIT_C_TOKEN_NAME, SPIRIT_C_TOKEN_ID, m_nCount).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CAngelOfGraceCard::CAngelOfGraceCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Grace"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(4))
	, m_SelfFilter(_T("this card"), _T("this card"), new SpecificCardComparer(this))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, until end of turn, damage that would reduce your life total to less than 1 reduces it
	// to 1 instead. (as Worship in Seventh Edition)
	AddEnterTrigger(this, &CAngelOfGraceCard::BeforeWorship);

	// {4}{W}{W}, Exile this card from your graveyard: Your life total becomes 10.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->GetCost().AddExileGraveyardCardCost(1, &m_SelfFilter);
	cpAbility->SetAbilityText(_T("Your life total becomes 10. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngelOfGraceCard::BeforeLife));
	AddAbility(cpAbility.GetPointer());
}

bool CAngelOfGraceCard::BeforeWorship(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayerEffectModifier(PlayerEffectType::Worship, 1).ApplyTo(pController);

	CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::Worship, 1),
		TurnNumberDelta(0), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater);
	pRemove.ApplyTo(pController);
	return true;
}

bool CAngelOfGraceCard::BeforeLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Life nDelta = Life(10) - pController->GetLife();
	if (nDelta != Life(0))
		CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CArchwayAngelCard::CArchwayAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Archway Angel"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("5") WHITE_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, you gain 2 life for each Gate you control.
	AddEnterTrigger(this, &CArchwayAngelCard::BeforeGainLife);
}

bool CArchwayAngelCard::BeforeGainLife(CAbilityAction* pAction)
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	int nGates = CCardFilter::GetFilter(_T("Gates"))->CountIncluded(pBattlefield->GetCardContainer());
	if (nGates > 0)
		GainLife(this, pAction->GetController(), 2 * nGates);
	return true;
}

//____________________________________________________________________________
//
CCivicStalwartCard::CCivicStalwartCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Civic Stalwart"), CardType::Creature, CREATURE_TYPE2(Elephant, Soldier), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, creatures you control get +1/+1 until end of turn.
	AddEnterTrigger(this, &CCivicStalwartCard::BeforePump);
}

bool CCivicStalwartCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, +1);
	return true;
}

//____________________________________________________________________________
//
CConcordiaPegasusCard::CConcordiaPegasusCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Concordia Pegasus"), CardType::Creature, CREATURE_TYPE(Pegasus), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(3))
{
}

//____________________________________________________________________________
//
CEliteArresterCard::CEliteArresterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elite Arrester"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		WHITE_MANA_TEXT, Power(0), Life(3))
{
	// {1}{U}, {T}: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CForbiddingSpiritCard::CForbiddingSpiritCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forbidding Spirit"), CardType::Creature, CREATURE_TYPE2(Spirit, Cleric), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_nEnterTurn(-1)
	, m_bEnteredOnOwnTurn(FALSE)
{
	// When this creature enters, until your next turn, creatures can't attack you or planeswalkers you control unless
	// their controller pays {2} for each of those creatures. (as Ghostly Prison, while the window is active)
	// Partial: the effect ends if this creature leaves the battlefield, and it only taxes the attacks on you.
	AddEnterTrigger(this, &CForbiddingSpiritCard::BeforeTax);

	counted_ptr<CConsAttackExtraManaEnchantment> cpAbility(
		::CreateObject<CConsAttackExtraManaEnchantment>(this,
			new ForbiddingSpiritComparer(this),
			_T("2")));

	cpAbility->SetAffectOpponentCardsOnly();
	cpAbility->SetAffectOnlyPlayerDeclaration();
	AddAbility(cpAbility.GetPointer());
}

bool CForbiddingSpiritCard::BeforeTax(CAbilityAction* pAction)
{
	m_nEnterTurn = GetGame()->GetGameTurnNumber();
	m_bEnteredOnOwnTurn = GetGame()->GetActivePlayer() == pAction->GetController();
	return true;
}

BOOL CForbiddingSpiritCard::IsTaxActive() const
{
	if (m_nEnterTurn < 0)
		return FALSE;

	int nTurn = GetGame()->GetGameTurnNumber();
	if (nTurn == m_nEnterTurn)
		return TRUE;

	// The opponent's turn just after the turn in which it entered (until your next turn)
	return m_bEnteredOnOwnTurn && nTurn == m_nEnterTurn + 1;
}

//____________________________________________________________________________
//
CHaazdaOfficerCard::CHaazdaOfficerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Haazda Officer"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, target creature you control gets +1/+1 until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CHaazdaOfficerCard::BeforePump, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CHaazdaOfficerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +1, +1);
	return false;
}

//____________________________________________________________________________
//
CHeroOfPrecinctOneCard::CHeroOfPrecinctOneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hero of Precinct One"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast a multicolored spell, create a 1/1 white Human creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardMulticoloredComparer);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeroOfPrecinctOneCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CHeroOfPrecinctOneCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), HUMAN_C_TOKEN_NAME, HUMAN_C_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CImpassionedOratorCard::CImpassionedOratorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Impassioned Orator"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever another creature you control enters, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImpassionedOratorCard::BeforeGainLife));
	AddAbility(cpAbility.GetPointer());
}

bool CImpassionedOratorCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CKnightOfSorrowsCard::CKnightOfSorrowsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of Sorrows"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
	, m_Afterlife(this)
{
	// This creature can block an additional creature each combat.
	SetMaxBlockingCount(2);

	// Afterlife 1
	m_Afterlife.AddAfterlifeAbility(1);
}

//____________________________________________________________________________
//
CLumberingBattlementCard::CLumberingBattlementCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lumbering Battlement"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("4") WHITE_MANA_TEXT, Power(4), Life(5))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CLumberingBattlementCard::OnCreaturesSelected))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, exile any number of other nontoken creatures you control until it leaves the
	// battlefield. This creature gets +2/+2 for each card exiled with it.
	// (the bonus is applied when the cards are exiled, as a permanent change of this creature)
	AddEnterTrigger(this, &CLumberingBattlementCard::BeforeExile);
	AddLeaveTrigger(this, &CLumberingBattlementCard::BeforeReturn);
}

bool CLumberingBattlementCard::BeforeExile(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard == this || pCard->GetCardType().IsToken())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this, pAction->GetController());
	return true;
}

void CLumberingBattlementCard::OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	int nExiled = 0;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		int nBefore = m_Exiled.GetSize();
		ExileUntilLeaves(m_Exiled, pCard, pSelectionPlayer);
		if (m_Exiled.GetSize() > nBefore)
			++nExiled;
	}

	if (nExiled > 0)
	{
		CPowerModifier(Power(+2 * nExiled), FALSE).ApplyTo(this);
		CLifeModifier(Life(+2 * nExiled), this, PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE).ApplyTo(this);
	}
}

bool CLumberingBattlementCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CMinistrantOfObligationCard::CMinistrantOfObligationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ministrant of Obligation"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Afterlife(this)
{
	// Afterlife 2
	m_Afterlife.AddAfterlifeAbility(2);
}

//____________________________________________________________________________
//
CProwlingCaracalCard::CProwlingCaracalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prowling Caracal"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
{
}

//____________________________________________________________________________
//
CResoluteWatchdogCard::CResoluteWatchdogCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Resolute Watchdog"), CardType::Creature, CREATURE_TYPE(Dog), nID,
		WHITE_MANA_TEXT, Power(1), Life(3))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {1}, Sacrifice this creature: Target creature you control gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1"),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CResoluteWatchdogCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CResoluteWatchdogCard::BeforeIndestructible(CAbilityAction* pAction)
{
	GainCardKeyword(GetTargetCreature(pAction), CardKeyword::Indestructible);
	return false;
}

//____________________________________________________________________________
//
CSpiritOfTheSpiresCard::CSpiritOfTheSpiresCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spirit of the Spires"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(4))
{
	// Other creatures you control with flying get +0/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CreatureKeywordComparer(CreatureKeyword::Flying, false),
			Power(+0), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetEnchantmentCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSyndicateMessengerCard::CSyndicateMessengerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Syndicate Messenger"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Afterlife(this)
{
	// Afterlife 1
	m_Afterlife.AddAfterlifeAbility(1);
}

//____________________________________________________________________________
//
CTenthDistrictVeteranCard::CTenthDistrictVeteranCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tenth District Veteran"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Whenever this creature attacks, untap another target creature you control.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CTenthDistrictVeteranCard::BeforeUntap, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CTenthDistrictVeteranCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CCardOrientationModifier(FALSE).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CTitheTakerCard::CTitheTakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tithe Taker"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Afterlife(this)
{
	// During your turn, spells your opponents cast cost {1} more to cast and abilities your opponents activate cost {1}
	// more to activate unless they're mana abilities. (spells as Thalia, Guardian of Thraben)
	// Partial: the activated abilities don't cost more (the engine can't increase the cost of abilities).
	counted_ptr<CConsExtraManaEnchantment> cpAbility(
		::CreateObject<CConsExtraManaEnchantment>(this,
			new NotActivePlayerComparer,
			_T("1")));

	cpAbility->SetAffectOpponentCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// Afterlife 1
	m_Afterlife.AddAfterlifeAbility(1);
}

//____________________________________________________________________________
//
CTwilightPantherCard::CTwilightPantherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Twilight Panther"), CardType::Creature, CREATURE_TYPE2(Cat, Spirit), nID,
		WHITE_MANA_TEXT, Power(1), Life(2))
{
	// {B}: This creature gains deathtouch until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			BLACK_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Gains deathtouch until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTwilightPantherCard::BeforeDeathtouch));
	AddAbility(cpAbility.GetPointer());
}

bool CTwilightPantherCard::BeforeDeathtouch(CAbilityAction* pAction)
{
	GainCardKeyword(this, CardKeyword::Deathtouch);
	return true;
}

//____________________________________________________________________________
//
CWatchfulGiantCard::CWatchfulGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Watchful Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Soldier), nID,
		_T("5") WHITE_MANA_TEXT, Power(3), Life(6))
{
	// When this creature enters, create a 1/1 white Human creature token.
	AddEnterTrigger(this, &CWatchfulGiantCard::BeforeToken);
}

bool CWatchfulGiantCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), HUMAN_C_TOKEN_NAME, HUMAN_C_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define OOZE_G_TOKEN_NAME		_T("Ooze (G)")
#define OOZE_G_TOKEN_ID			55126

// "Look at the top nCount cards of your library. You may put nMin to nMax <filter> cards among them on top of your
// library and the rest on the bottom in a random order." (Silhana Wayfinder)
static void LookTopToTopRestBottom(CGame* pGame, CPlayer* pPlayer, int nCount, int nMin, int nMax, const CCardFilter* pFilter)
{
	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, nCount,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(nMin), MaximumValue(nMax),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, pFilter,
		ZoneId::Library, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pPlayer);
}

//____________________________________________________________________________
//
CAdaptSupport::CAdaptSupport(CCard* pCard)
	: m_pCard(pCard)
	, m_nCount(0)
{
}

CAbility* CAdaptSupport::AddAdaptAbility(LPCTSTR strCost, int nCount)
{
	m_nCount = nCount;

	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(m_pCard, strCost));

	CString strText;
	strText.Format(_T("Adapt %d. Activates"), nCount);
	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAdaptSupport::BeforeAdapt));
	m_pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

bool CAdaptSupport::BeforeAdapt(CAbilityAction* pAction)
{
	if (m_pCard->GetZoneId() == ZoneId::Battlefield &&
		m_pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() == 0)
		CCardCounterModifier(_T("+1/+1"), m_nCount).ApplyTo(m_pCard);
	return true;
}

//____________________________________________________________________________
//
CAxebaneBeastCard::CAxebaneBeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Axebane Beast"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(4))
{
}

//____________________________________________________________________________
//
CBiogenicOozeCard::CBiogenicOozeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Biogenic Ooze"), CardType::Creature, CREATURE_TYPE(Ooze), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, create a 2/2 green Ooze creature token.
	AddEnterTrigger(this, &CBiogenicOozeCard::BeforeToken);

	// At the beginning of your end step, put a +1/+1 counter on each Ooze you control.
	AddStepTrigger<CBiogenicOozeCard>(this, NodeId::EndStep, false, NULL, &CBiogenicOozeCard::BeforeCounters);

	// {1}{G}{G}{G}: Create a 2/2 green Ooze creature token.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT,
			OOZE_G_TOKEN_NAME, OOZE_G_TOKEN_ID, 1));
	AddAbility(cpAbility.GetPointer());
}

bool CBiogenicOozeCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), OOZE_G_TOKEN_NAME, OOZE_G_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CBiogenicOozeCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CreatureTypeComparer oozeComparer(CREATURE_TYPE(Ooze), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (oozeComparer(creatures.GetAt(i)))
			AddPlusCounter(creatures.GetAt(i), 1);
	return true;
}

//____________________________________________________________________________
//
CEndRazeForerunnersCard::CEndRazeForerunnersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("End-Raze Forerunners"), CardType::Creature, CREATURE_TYPE(Boar), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(7))
{
	// Vigilance, trample, haste
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, other creatures you control get +2/+2 and gain vigilance and trample until end of turn.
	AddEnterTrigger(this, &CEndRazeForerunnersCard::BeforePump);
}

bool CEndRazeForerunnersCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			PumpCreature(creatures.GetAt(i), +2, +2, CreatureKeyword::Vigilance | CreatureKeyword::Trample);
	return true;
}

//____________________________________________________________________________
//
CEnragedCeratokCard::CEnragedCeratokCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Enraged Ceratok"), CardType::Creature, CREATURE_TYPE(Rhino), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 2 or less. (as Giltgrove Stalker)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

//____________________________________________________________________________
//
CGatebreakerRamCard::CGatebreakerRamCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gatebreaker Ram"), CardType::Creature, CREATURE_TYPE(Sheep), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// This creature gets +1/+1 for each Gate you control. (as Nim Grotesque)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new CardTypeComparer(CardType::Gate, false)));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// As long as you control two or more Gates, this creature has vigilance and trample.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::Vigilance | CreatureKeyword::Trample));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Gate, false));
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(2);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CGrowthChamberGuardianCard::CGrowthChamberGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Growth-Chamber Guardian"), CardType::Creature, CREATURE_TYPE3(Elf, Crab, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Adapt(this)
	, m_NameFilter(_T("a card named Growth-Chamber Guardian"), _T("cards named Growth-Chamber Guardian"),
		new CardNameComparer(_T("Growth-Chamber Guardian")))
{
	// {2}{G}: Adapt 2.
	m_Adapt.AddAdaptAbility(_T("2") GREEN_MANA_TEXT, 2);

	// Whenever one or more +1/+1 counters are put on this creature, you may search your library for a card named
	// Growth-Chamber Guardian, reveal it, put it into your hand, then shuffle. (as Fathom Mage)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCounterMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetOnIncreaseOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGrowthChamberGuardianCard::SetCounterContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrowthChamberGuardianCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CGrowthChamberGuardianCard::SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	return pFromCard == this && (CString)name == _T("+1/+1") && n_value > old;
}

bool CGrowthChamberGuardianCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, &m_NameFilter);
	return true;
}

//____________________________________________________________________________
//
CGruulBeastmasterCard::CGruulBeastmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gruul Beastmaster"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// Whenever this creature attacks, another target creature you control gets +X/+0 until end of turn, where X is this
	// creature's power.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CGruulBeastmasterCard::BeforePump, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CGruulBeastmasterCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	int nPower = GET_INTEGER(GetPower());
	if (pCard && nPower > 0)
		PumpCreature(pCard, nPower, 0);
	return false;
}

//____________________________________________________________________________
//
CIncubationDruidCard::CIncubationDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Incubation Druid"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(0), Life(2))
	, m_Adapt(this)
{
	// {T}: Add one mana of any type that a land you control could produce. If this creature has a +1/+1 counter on it,
	// add three mana of that type instead.
	// Partial: with a +1/+1 counter, it adds three mana of any color (not limited to the types of your lands).
	CManaPool::Color colors[] = { CManaPool::Color::White, CManaPool::Color::Blue, CManaPool::Color::Black,
								  CManaPool::Color::Red, CManaPool::Color::Green };
	for (int i = 0; i < 5; ++i)
	{
		// (as Reflecting Pool in Tempest)
		counted_ptr<CManaProductionAbility3> cpAbility(
			::CreateObject<CManaProductionAbility3>(this, _T(""), AbilityType::Activated,
				new CardTypeComparer(CardType::_Land, false),
				colors[i]));

		cpAbility->SetMonitorControllerOnly();
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	LPCTSTR threeMana[] = {
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		// (a mana ability for each case, as Mox Amber)
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, threeMana[i]));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), &CIncubationDruidCard::HasPlusCounter);
		AddAbility(cpAbility.GetPointer());
	}

	// {3}{G}{G}: Adapt 3.
	m_Adapt.AddAdaptAbility(_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, 3);
}

BOOL CIncubationDruidCard::HasPlusCounter(BOOL bIncludeTricks)
{
	return GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0;
}

//____________________________________________________________________________
//
CMammothSpiderCard::CMammothSpiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mammoth Spider"), CardType::Creature, CREATURE_TYPE(Spider), nID,
		_T("4") GREEN_MANA_TEXT, Power(3), Life(5))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);
}

//____________________________________________________________________________
//
CRampagingRendhornCard::CRampagingRendhornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rampaging Rendhorn"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();
}

//____________________________________________________________________________
//
CSaruliCaretakerCard::CSaruliCaretakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Saruli Caretaker"), CardType::Creature, CREATURE_TYPE(Dryad), nID,
		GREEN_MANA_TEXT, Power(0), Life(3))
	, m_CreatureFilter(_T("another untapped creature you control"), _T("other untapped creatures you control"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {T}, Tap an untapped creature you control: Add one mana of any color. (as Hour of Devastation)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddTapCardCost(1, &m_CreatureFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSauroformHybridCard::CSauroformHybridCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sauroform Hybrid"), CardType::Creature, CREATURE_TYPE3(Human, Lizard, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Adapt(this)
{
	// {4}{G}{G}: Adapt 4.
	m_Adapt.AddAdaptAbility(_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, 4);
}

//____________________________________________________________________________
//
CSilhanaWayfinderCard::CSilhanaWayfinderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Silhana Wayfinder"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1))
	, m_CreatureOrLandFilter(_T("a creature or land card"), _T("creature or land cards"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::_Land, false)))
{
	// When this creature enters, look at the top four cards of your library. You may reveal a creature or land card from
	// among them and put it on top of your library. Put the rest on the bottom of your library in a random order.
	AddEnterTrigger(this, &CSilhanaWayfinderCard::BeforeLook);
}

bool CSilhanaWayfinderCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToTopRestBottom(GetGame(), pAction->GetController(), 4, 0, 1, &m_CreatureOrLandFilter);
	return true;
}

//____________________________________________________________________________
//
CSteepleCreeperCard::CSteepleCreeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steeple Creeper"), CardType::Creature, CREATURE_TYPE2(Frog, Snake), nID,
		_T("2") GREEN_MANA_TEXT, Power(4), Life(2))
{
	// {3}{U}: This creature gains flying until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") BLUE_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Gains flying until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSteepleCreeperCard::BeforeFlying));
	AddAbility(cpAbility.GetPointer());
}

bool CSteepleCreeperCard::BeforeFlying(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::Flying);
	return true;
}

//____________________________________________________________________________
//
CSylvanBrushstriderCard::CSylvanBrushstriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sylvan Brushstrider"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you gain 2 life.
	AddEnterTrigger(this, &CSylvanBrushstriderCard::BeforeGainLife);
}

bool CSylvanBrushstriderCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CTerritorialBoarCard::CTerritorialBoarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Territorial Boar"), CardType::Creature, CREATURE_TYPE(Boar), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Whenever a creature you control with power 4 or greater enters, this creature gets +1/+1 and gains vigilance until
	// end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTerritorialBoarCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTerritorialBoarCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CTerritorialBoarCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	return pCreature && pCreature->GetPower() >= Power(4);
}

bool CTerritorialBoarCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1, CreatureKeyword::Vigilance);
	return true;
}

//____________________________________________________________________________
//
CTrollbredGuardianCard::CTrollbredGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trollbred Guardian"), CardType::Creature, CREATURE_TYPE3(Troll, Frog, Warrior), nID,
		_T("4") GREEN_MANA_TEXT, Power(5), Life(5))
	, m_Adapt(this)
{
	// {2}{G}: Adapt 2.
	m_Adapt.AddAdaptAbility(_T("2") GREEN_MANA_TEXT, 2);

	// Each creature you control with a +1/+1 counter on it has trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1),
			Power(+0), Life(+0), CreatureKeyword::Trample));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CWreckingBeastCard::CWreckingBeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wrecking Beast"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Spectacle in a creature (or other permanent): a second spell with the spectacle cost (as Daring Buccaneer's second
// spell in Rivals of Ixalan)
template <class T>
static CSpell* AddPermanentSpectacle(T* pCard, LPCTSTR strCost, BOOL (T::*condition)(BOOL),
	bool (T::*callback)(CAbilityAction*) = NULL)
{
	counted_ptr<CSpell> cpSpell(::CreateObject<CSpell>(pCard, pCard->GetSpells().GetAt(0)->GetAbilityType(), strCost, TRUE));
	SetSpectacle(pCard, cpSpell.GetPointer(), condition);
	if (callback)
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddSpell(cpSpell.GetPointer());
	return cpSpell.GetPointer();
}

//____________________________________________________________________________
//
CAmplifireCard::CAmplifireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Amplifire"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(1), Life(1))
	, m_nPowerDelta(0)
	, m_nToughnessDelta(0)
{
	// At the beginning of your upkeep, reveal cards from the top of your library until you reveal a creature card. Until
	// your next turn, this creature's base power becomes twice that card's power and its base toughness becomes twice
	// that card's toughness. Put the revealed cards on the bottom of your library in a random order.
	// (the base power and toughness are a permanent change from the printed ones that is replaced at each upkeep)
	AddEnterTrigger(this, &CAmplifireCard::BeforeReset);
	AddStepTrigger<CAmplifireCard>(this, NodeId::UpkeepStep, false, NULL, &CAmplifireCard::BeforeReveal);
}

bool CAmplifireCard::BeforeReset(CAbilityAction* pAction)
{
	// A new object: the changes of a previous time on the battlefield are gone
	m_nPowerDelta = 0;
	m_nToughnessDelta = 0;
	return true;
}

void CAmplifireCard::SetBaseDelta(int nPowerDelta, int nToughnessDelta)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	if (nPowerDelta != m_nPowerDelta)
		CPowerModifier(Power(nPowerDelta - m_nPowerDelta), FALSE).ApplyTo(this);
	if (nToughnessDelta != m_nToughnessDelta)
		CLifeModifier(Life(nToughnessDelta - m_nToughnessDelta), this, PreventableType::NotPreventable,
			DamageType::NotDealingDamage, FALSE).ApplyTo(this);

	m_nPowerDelta = nPowerDelta;
	m_nToughnessDelta = nToughnessDelta;
}

bool CAmplifireCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	// Reveal from the top until a creature card
	CCountedCardContainer revealed;
	CCreatureCard* pFound = NULL;
	for (int i = pLibrary->GetSize() - 1; i >= 0; --i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		revealed.AddCard(pCard, CardPlacement::Top);
		if (pCard->GetCardType().IsCreature())
		{
			pFound = dynamic_cast<CCreatureCard*>(pCard);
			break;
		}
	}

	if (!m_pGame->IsThinking())
	{
		CString strMessage;
		if (pFound)
			strMessage.Format(_T("%s reveals %d card(s) until %s"), pController->GetPlayerName(), revealed.GetSize(),
				pFound->GetCardName(TRUE));
		else
			strMessage.Format(_T("%s reveals %d card(s) without finding a creature card"), pController->GetPlayerName(),
				revealed.GetSize());
		m_pGame->Message(strMessage, pController->IsComputer() ? m_pGame->GetComputerImage() : m_pGame->GetHumanImage(),
			MessageImportance::High);
	}

	if (pFound)
		SetBaseDelta(2 * GET_INTEGER(pFound->GetPower()) - 1, 2 * GET_INTEGER(pFound->GetToughness()) - 1);
	else
		SetBaseDelta(0, 0);

	// The revealed cards go to the bottom of the library (in the order they were revealed)
	if (revealed.GetSize() > 0)
		pLibrary->ReorderCards(revealed, CardPlacement::Bottom);
	return true;
}

//____________________________________________________________________________
//
CBurningTreeVandalCard::CBurningTreeVandalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Burning-Tree Vandal"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(1))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// Whenever this creature attacks, you may discard a card. If you do, draw a card.
	AddSelfAttackTrigger(this, &CBurningTreeVandalCard::BeforeRummage, true);
}

bool CBurningTreeVandalCard::BeforeRummage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (pController->GetZoneById(ZoneId::Hand)->GetSize() > 0)
	{
		DiscardCards(GetGame(), pController, 1);
		DrawCards(GetGame(), pController, 1);
	}
	return true;
}

//____________________________________________________________________________
//
CClamorShamanCard::CClamorShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Clamor Shaman"), CardType::Creature, CREATURE_TYPE2(Goblin, Shaman), nID,
		_T("2") RED_MANA_TEXT, Power(1), Life(1))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// Whenever this creature attacks, target creature an opponent controls can't block this turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CClamorShamanCard::BeforeCantBlock, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CClamorShamanCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, 0, 0, CreatureKeyword::CantBlock);
	return false;
}

//____________________________________________________________________________
//
CDaggerCasterCard::CDaggerCasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dagger Caster"), CardType::Creature, CREATURE_TYPE2(Lizard, Rogue), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, it deals 1 damage to each opponent and 1 damage to each creature your opponents control.
	AddEnterTrigger(this, &CDaggerCasterCard::BeforeDamage);
}

bool CDaggerCasterCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DamageEachOpponent(this, pController, 1);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			DealDamageToCreature(this, creatures.GetAt(i), 1);
	return true;
}

//____________________________________________________________________________
//
CFeralMaakaCard::CFeralMaakaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Feral Maaka"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
}

//____________________________________________________________________________
//
CGhorClanWreckerCard::CGhorClanWreckerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghor-Clan Wrecker"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(2))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

//____________________________________________________________________________
//
CGravelHideGoblinCard::CGravelHideGoblinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gravel-Hide Goblin"), CardType::Creature, CREATURE_TYPE2(Goblin, Shaman), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// {3}{G}: This creature gets +2/+2 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") GREEN_MANA_TEXT));

	cpAbility->SetAbilityText(_T("+2/+2 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGravelHideGoblinCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CGravelHideGoblinCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +2);
	return true;
}

//____________________________________________________________________________
//
CImmolationShamanCard::CImmolationShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Immolation Shaman"), CardType::Creature, CREATURE_TYPE2(Lizard, Shaman), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// Whenever an opponent activates an ability of an artifact, creature, or land that isn't a mana ability, this
	// creature deals 1 damage to that player.
	// Not implemented: the engine has no event for activating abilities.

	// {3}{R}{R}: This creature gets +3/+3 and gains menace until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") RED_MANA_TEXT RED_MANA_TEXT));

	cpAbility->SetAbilityText(_T("+3/+3 and menace until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImmolationShamanCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CImmolationShamanCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +3, +3, CreatureKeyword::CantBeBlockedBy1);
	return true;
}

//____________________________________________________________________________
//
CRixMaadiRevelerCard::CRixMaadiRevelerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rix Maadi Reveler"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
	, m_bSpectacle(FALSE)
	, m_bCastWithSpectacle(FALSE)
{
	// Spectacle {2}{B}{R}
	// (the spells remember which cost was paid when they resolve, as Venerated Loxodon)
	GetSpells().GetAt(0)->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRixMaadiRevelerCard::BeforeMainResolution));
	AddPermanentSpectacle(this, _T("2") BLACK_MANA_TEXT RED_MANA_TEXT, &CRixMaadiRevelerCard::CanSpectacle,
		&CRixMaadiRevelerCard::BeforeSpectacleResolution);

	// When this creature enters, discard a card, then draw a card. If this creature's spectacle cost was paid, instead
	// discard your hand, then draw three cards.
	AddEnterIfTrigger(this, &CRixMaadiRevelerCard::SetEnterContext, &CRixMaadiRevelerCard::BeforeRummage);
}

BOOL CRixMaadiRevelerCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

bool CRixMaadiRevelerCard::BeforeMainResolution(CAbilityAction* pAction)
{
	m_bSpectacle = FALSE;
	return true;
}

bool CRixMaadiRevelerCard::BeforeSpectacleResolution(CAbilityAction* pAction)
{
	m_bSpectacle = TRUE;
	return true;
}

bool CRixMaadiRevelerCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	m_bCastWithSpectacle = moveType == MoveType::Cast && m_bSpectacle;
	return true;
}

bool CRixMaadiRevelerCard::BeforeRummage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (m_bCastWithSpectacle)
	{
		DiscardCards(GetGame(), pController, pController->GetZoneById(ZoneId::Hand)->GetSize());
		DrawCards(GetGame(), pController, 3);
	}
	else
	{
		DiscardCards(GetGame(), pController, 1);
		DrawCards(GetGame(), pController, 1);
	}
	return true;
}

//____________________________________________________________________________
//
CRubblebeltRecluseCard::CRubblebeltRecluseCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rubblebelt Recluse"), CardType::Creature, CREATURE_TYPE2(Ogre, Berserker), nID,
		_T("4") RED_MANA_TEXT, Power(6), Life(5))
{
	// This creature attacks each combat if able.
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);
}

//____________________________________________________________________________
//
CRumblingRuinCard::CRumblingRuinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rumbling Ruin"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("5") RED_MANA_TEXT, Power(6), Life(6))
{
	// When this creature enters, count the number of +1/+1 counters on creatures you control. Creatures your opponents
	// control with power less than or equal to that number can't block this turn.
	AddEnterTrigger(this, &CRumblingRuinCard::BeforeCantBlock);
}

bool CRumblingRuinCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer mine;
	GetCreatures(GetGame(), pController, TRUE, mine);
	int nCounters = 0;
	for (int i = 0; i < mine.GetSize(); ++i)
		nCounters += mine.GetAt(i)->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();

	CCountedCardContainer theirs;
	GetCreatures(GetGame(), pController, FALSE, theirs);
	for (int i = 0; i < theirs.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(theirs.GetAt(i));
		if (pCreature && pCreature->GetPower() <= Power(nCounters))
			PumpCreature(pCreature, 0, 0, CreatureKeyword::CantBlock);
	}
	return true;
}

//____________________________________________________________________________
//
CSkarrganHellkiteCard::CSkarrganHellkiteCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skarrgan Hellkite"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// {3}{R}: This creature deals 2 damage divided as you choose among one or two targets. Activate only if this creature
	// has a +1/+1 counter on it. (as Ral, Caller of Storms; it can't target planeswalkers)
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetSubjectCount(1, 2);
	cpAbility->GetTargeting()->SetDistributeValues();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddPlayableIf(this, cpAbility.GetPointer(), &CSkarrganHellkiteCard::HasPlusCounter);
	AddAbility(cpAbility.GetPointer());
}

BOOL CSkarrganHellkiteCard::HasPlusCounter(BOOL bIncludeTricks)
{
	return GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0;
}

//____________________________________________________________________________
//
CSmeltWardIgnusCard::CSmeltWardIgnusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Smelt-Ward Ignus"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// {2}{R}, Sacrifice this creature: Gain control of target creature with power 3 or less until end of turn. Untap that
	// creature. It gains haste until end of turn. Activate only as a sorcery. (as Act of Treason in M10)
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2") RED_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::less_equal<int>>(3)),
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	cpAbility->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSpearSpewerCard::CSpearSpewerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spear Spewer"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		RED_MANA_TEXT, Power(0), Life(2))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {T}: This creature deals 1 damage to each player.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("1 damage to each player. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpearSpewerCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CSpearSpewerCard::BeforeDamage(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		DealDamageToPlayer(this, GetGame()->GetPlayer(ip), 1);
	return true;
}

//____________________________________________________________________________
//
CSpikewheelAcrobatCard::CSpikewheelAcrobatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spikewheel Acrobat"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("3") RED_MANA_TEXT, Power(5), Life(2))
{
	// Spectacle {2}{R}
	AddPermanentSpectacle(this, _T("2") RED_MANA_TEXT, &CSpikewheelAcrobatCard::CanSpectacle);
}

BOOL CSpikewheelAcrobatCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

//____________________________________________________________________________
//
CTinStreetDodgerCard::CTinStreetDodgerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tin Street Dodger"), CardType::Creature, CREATURE_TYPE2(Goblin, Rogue), nID,
		RED_MANA_TEXT, Power(1), Life(1))
	, m_DefenderFilter(_T("a creature with defender"), _T("creatures with defender"),
		new CreatureKeywordComparer(CreatureKeyword::Defender, false))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// {R}: This creature can't be blocked this turn except by creatures with defender.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			RED_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Can't be blocked this turn except by creatures with defender. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTinStreetDodgerCard::BeforeEvasion));
	AddAbility(cpAbility.GetPointer());
}

bool CTinStreetDodgerCard::BeforeEvasion(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE, &m_DefenderFilter);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CBladeJugglerCard::CBladeJugglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blade Juggler"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Spectacle {2}{B}
	AddPermanentSpectacle(this, _T("2") BLACK_MANA_TEXT, &CBladeJugglerCard::CanSpectacle);

	// When this creature enters, it deals 1 damage to you and you draw a card.
	AddEnterTrigger(this, &CBladeJugglerCard::BeforeDraw);
}

BOOL CBladeJugglerCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

bool CBladeJugglerCard::BeforeDraw(CAbilityAction* pAction)
{
	DealDamageToPlayer(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CBloodmistInfiltratorCard::CBloodmistInfiltratorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodmist Infiltrator"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(1))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Whenever this creature attacks, you may sacrifice another creature. If you do, this creature can't be blocked this
	// turn. (as Brawl-Bash Ogre in M19)
	AddSelfAttackTrigger(this, &CBloodmistInfiltratorCard::BeforeSacrifice, true);
}

bool CBloodmistInfiltratorCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nBefore = CountCreatures(GetGame(), pController);
	if (m_OtherCreatureFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 1, 1, &m_OtherCreatureFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	if (CountCreatures(GetGame(), pController) < nBefore && GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

//____________________________________________________________________________
//
CCarrionImpCard::CCarrionImpCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Carrion Imp"), CardType::Creature, CREATURE_TYPE(Imp), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(3))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CCarrionImpCard::OnCardSelected))
{
	// When this creature enters, you may exile target creature card from a graveyard. If you do, you gain 2 life.
	// Partial: the card is chosen on resolution (it isn't a target).
	AddEnterTrigger(this, &CCarrionImpCard::BeforeExile);
}

bool CCarrionImpCard::BeforeExile(CAbilityAction* pAction)
{
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
			entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}
	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, 1, this, pAction->GetController());
	return true;
}

void CCarrionImpCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Graveyard)
			continue;

		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Exile)
			GainLife(this, pSelectionPlayer, 2);
	}
}

//____________________________________________________________________________
//
CCatacombCrocodileCard::CCatacombCrocodileCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Catacomb Crocodile"), CardType::Creature, CREATURE_TYPE(Crocodile), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(7))
{
}

//____________________________________________________________________________
//
CDebtorsTransportCard::CDebtorsTransportCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Debtors' Transport"), CardType::Creature, CREATURE_TYPE(Thrull), nID,
		_T("5") BLACK_MANA_TEXT, Power(5), Life(3))
	, m_Afterlife(this)
{
	// Afterlife 2
	m_Afterlife.AddAfterlifeAbility(2);
}

//____________________________________________________________________________
//
CGutterbonesCard::CGutterbonesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gutterbones"), CardType::Creature, CREATURE_TYPE2(Skeleton, Warrior), nID,
		BLACK_MANA_TEXT, Power(2), Life(1))
{
	// This creature enters tapped.
	SetIntoPlayTapped();

	// {1}{B}: Return this card from your graveyard to your hand. Activate only during your turn and only if an opponent
	// lost life this turn. (as Jungle Creeper in Rivals of Ixalan)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") BLACK_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGutterbonesCard::BeforeReturn));
	AddPlayableIf(this, cpAbility.GetPointer(), &CGutterbonesCard::CanReturn);
	AddAbility(cpAbility.GetPointer());
}

BOOL CGutterbonesCard::CanReturn(BOOL bIncludeTricks)
{
	return GetGame()->GetActivePlayer() == GetController() && OpponentLostLifeThisTurn(GetController());
}

bool CGutterbonesCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CNoxiousGroodionCard::CNoxiousGroodionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Noxious Groodion"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);
}

//____________________________________________________________________________
//
COrzhovEnforcerCard::COrzhovEnforcerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Orzhov Enforcer"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
	, m_Afterlife(this)
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Afterlife 1
	m_Afterlife.AddAfterlifeAbility(1);
}

//____________________________________________________________________________
//
COrzhovRacketeersCard::COrzhovRacketeersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Orzhov Racketeers"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(2))
	, m_Afterlife(this)
{
	// Whenever this creature deals combat damage to a player, that player discards a card. (as Urgoros, the Empty One)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COrzhovRacketeersCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &COrzhovRacketeersCard::BeforeDiscard));
	AddAbility(cpAbility.GetPointer());

	// Afterlife 2
	m_Afterlife.AddAfterlifeAbility(2);
}

bool COrzhovRacketeersCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	triggerContext.nValue1 = (DWORD)pPlayer;
	return true;
}

bool COrzhovRacketeersCard::BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);
	return true;
}

//____________________________________________________________________________
//
CPestilentSpiritCard::CPestilentSpiritCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pestilent Spirit"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Menace, deathtouch
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Instant and sorcery spells you control have deathtouch.
	// Not implemented: the engine can't give deathtouch to spells.
}

//____________________________________________________________________________
//
CPlagueWightCard::CPlagueWightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Plague Wight"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature becomes blocked, each creature blocking it gets -1/-1 until end of turn.
	// (as Deeproot Warrior in Ixalan)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockedEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPlagueWightCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());
}

bool CPlagueWightCard::BeforeShrink(CAbilityAction* pAction)
{
	CCountedCardContainer blockers;
	const CCountedCardContainer_& blockedBy = GetBlockedBy();
	for (int i = 0; i < blockedBy.GetSize(); ++i)
		blockers.AddCard(blockedBy.GetAt(i), CardPlacement::Top);

	for (int i = 0; i < blockers.GetSize(); ++i)
		if (blockers.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			PumpCreature(blockers.GetAt(i), -1, -1);
	return true;
}

//____________________________________________________________________________
//
CPriestOfForgottenGodsCard::CPriestOfForgottenGodsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Priest of Forgotten Gods"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// {T}, Sacrifice two other creatures: Any number of target players each lose 2 life and sacrifice a creature of
	// their choice. You add {B}{B} and draw a card.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(2, &m_OtherCreatureFilter);
	cpAbility->GetTargeting()->SetSubjectCount(0, GetGame()->GetPlayerCount());
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPriestOfForgottenGodsCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CPriestOfForgottenGodsCard::BeforeResolution(CAbilityAction* pAction)
{
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (pTargetAction)
	{
		CPlayerContainer players;
		pTargetAction->GetTargetGroup().GetPlayerSubjects(players);
		for (int i = 0; i < players.GetSize(); ++i)
		{
			CPlayer* pPlayer = players.GetAt(i);
			CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
			ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
				ZoneId::Graveyard, MoveType::Sacrifice);
		}
	}

	CPlayer* pController = pAction->GetController();
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(BLACK_MANA_TEXT BLACK_MANA_TEXT)).ApplyTo(pController);
	DrawCards(GetGame(), pController, 1);
	return false;
}

//____________________________________________________________________________
//
CRakdosTrumpeterCard::CRakdosTrumpeterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rakdos Trumpeter"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(3))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// {3}{R}: This creature gets +2/+0 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") RED_MANA_TEXT));

	cpAbility->SetAbilityText(_T("+2/+0 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRakdosTrumpeterCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CRakdosTrumpeterCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, 0);
	return true;
}

//____________________________________________________________________________
//
CSpawnOfMayhemCard::CSpawnOfMayhemCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spawn of Mayhem"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
{
	// Spectacle {1}{B}{B}
	AddPermanentSpectacle(this, _T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CSpawnOfMayhemCard::CanSpectacle);

	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// At the beginning of your upkeep, this creature deals 1 damage to each player. Then if you have 10 or less life,
	// put a +1/+1 counter on this creature.
	AddStepTrigger<CSpawnOfMayhemCard>(this, NodeId::UpkeepStep, false, NULL, &CSpawnOfMayhemCard::BeforeDamage);
}

BOOL CSpawnOfMayhemCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

bool CSpawnOfMayhemCard::BeforeDamage(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		DealDamageToPlayer(this, GetGame()->GetPlayer(ip), 1);

	if (pAction->GetController()->GetLife() <= Life(10))
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CSpireManglerCard::CSpireManglerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spire Mangler"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, target creature you control with flying gets +2/+0 until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CSpireManglerCard::BeforePump, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false));
}

bool CSpireManglerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +2, 0);
	return false;
}

//____________________________________________________________________________
//
CTheHauntOfHightowerCard::CTheHauntOfHightowerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("The Haunt of Hightower"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Vampire), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Flying, lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// Whenever The Haunt of Hightower attacks, defending player discards a card.
	AddSelfAttackTrigger(this, &CTheHauntOfHightowerCard::BeforeDiscard);

	// Whenever a card is put into an opponent's graveyard from anywhere, put a +1/+1 counter on The Haunt of Hightower.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Graveyard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CardTypeComparer(CardType::Token, false)));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheHauntOfHightowerCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CTheHauntOfHightowerCard::BeforeDiscard(CAbilityAction* pAction)
{
	// The defending player (two-player game: the next player)
	CPlayer* pDefender = GetGame()->GetNextPlayer(pAction->GetController());
	if (pDefender && pDefender != pAction->GetController())
		DiscardCards(GetGame(), pDefender, 1);
	return true;
}

bool CTheHauntOfHightowerCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CThirstingShadeCard::CThirstingShadeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thirsting Shade"), CardType::Creature, CREATURE_TYPE(Shade), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// {2}{B}: This creature gets +1/+1 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") BLACK_MANA_TEXT));

	cpAbility->SetAbilityText(_T("+1/+1 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThirstingShadeCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CThirstingShadeCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

//____________________________________________________________________________
//
CUndercityScavengerCard::CUndercityScavengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Undercity Scavenger"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// When this creature enters, you may sacrifice another creature. If you do, put two +1/+1 counters on this creature,
	// then scry 2. (as Brawl-Bash Ogre in M19)
	AddEnterTrigger(this, &CUndercityScavengerCard::BeforeSacrifice, true);
}

bool CUndercityScavengerCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nBefore = CountCreatures(GetGame(), pController);
	if (m_OtherCreatureFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 1, 1, &m_OtherCreatureFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	if (CountCreatures(GetGame(), pController) < nBefore)
	{
		AddPlusCounter(this, 2);
		CScryModifier(GetGame(), 2, this).ApplyTo(pController);
	}
	return true;
}

//____________________________________________________________________________
//
CVindictiveVampireCard::CVindictiveVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vindictive Vampire"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Whenever another creature you control dies, this creature deals 1 damage to each opponent and you gain 1 life.
	AddAnotherCreatureDiesTrigger<CVindictiveVampireCard>(this, NULL, &CVindictiveVampireCard::BeforeDrain);
}

bool CVindictiveVampireCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define ILLUSION_D_TOKEN_NAME	_T("Illusion (D)")
#define ILLUSION_D_TOKEN_ID		55127

//____________________________________________________________________________
//
CBenthicBiomancerCard::CBenthicBiomancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Benthic Biomancer"), CardType::Creature, CREATURE_TYPE3(Merfolk, Wizard, Mutant), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
	, m_Adapt(this)
{
	// {1}{U}: Adapt 1.
	m_Adapt.AddAdaptAbility(_T("1") BLUE_MANA_TEXT, 1);

	// Whenever one or more +1/+1 counters are put on this creature, draw a card, then discard a card. (as Fathom Mage)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCounterMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetOnIncreaseOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBenthicBiomancerCard::SetCounterContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBenthicBiomancerCard::BeforeLoot));
	AddAbility(cpAbility.GetPointer());
}

bool CBenthicBiomancerCard::SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	return pFromCard == this && (CString)name == _T("+1/+1") && n_value > old;
}

bool CBenthicBiomancerCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CChillbringerCard::CChillbringerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Chillbringer"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, tap target creature an opponent controls. It doesn't untap during its controller's next
	// untap step.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CChillbringerCard::BeforeTap, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CChillbringerCard::BeforeTap(CAbilityAction* pAction)
{
	TapAndSkipUntap(GetTargetCreature(pAction));
	return false;
}

//____________________________________________________________________________
//
CCoralCommandoCard::CCoralCommandoCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Coral Commando"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("2") BLUE_MANA_TEXT, Power(3), Life(2))
{
}

//____________________________________________________________________________
//
CFaerieDuelistCard::CFaerieDuelistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Faerie Duelist"), CardType::Creature, CREATURE_TYPE2(Faerie, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, target creature an opponent controls gets -2/-0 until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CFaerieDuelistCard::BeforeShrink, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CFaerieDuelistCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, -2, 0);
	return false;
}

//____________________________________________________________________________
//
CGatewaySneakCard::CGatewaySneakCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gateway Sneak"), CardType::Creature, CREATURE_TYPE2(Vedalken, Rogue), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(3))
{
	{
		// Whenever a Gate you control enters, this creature can't be blocked this turn.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("Gates")));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGatewaySneakCard::BeforeUnblockable));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature deals combat damage to a player, draw a card.
		counted_ptr<DamageTriggeredAbility> cpAbility(::CreateObject<DamageTriggeredAbility>(this));

		cpAbility->SetOptionalType(DamageTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGatewaySneakCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGatewaySneakCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

bool CGatewaySneakCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CHumongulusCard::CHumongulusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Humongulus"), CardType::Creature, CREATURE_TYPE(Homunculus), nID,
		_T("4") BLUE_MANA_TEXT, Power(2), Life(5))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);
}

//____________________________________________________________________________
//
CMesmerizingBenthidCard::CMesmerizingBenthidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mesmerizing Benthid"), CardType::Creature, CREATURE_TYPE(Octopus), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, create two 0/2 blue Illusion creature tokens with "Whenever this token blocks a
	// creature, that creature doesn't untap during its controller's next untap step."
	AddEnterTrigger(this, &CMesmerizingBenthidCard::BeforeTokens);

	// This creature has hexproof as long as you control an Illusion. (as Slippery Scoundrel in Rivals of Ixalan)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0)));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Illusion), false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

bool CMesmerizingBenthidCard::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ILLUSION_D_TOKEN_NAME, ILLUSION_D_TOKEN_ID, 2).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CPersistentPetitionersCard::CPersistentPetitionersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Persistent Petitioners"), CardType::Creature, CREATURE_TYPE2(Human, Advisor), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
	, m_AdvisorFilter(_T("an Advisor"), _T("Advisors"), new CreatureTypeComparer(CREATURE_TYPE(Advisor), false))
{
	{
		// {1}, {T}: Target player mills a card.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPersistentPetitionersCard::BeforeMillOne));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Tap four untapped Advisors you control: Target player mills twelve cards.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddTapCardCost(4, &m_AdvisorFilter);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPersistentPetitionersCard::BeforeMillTwelve));
		AddAbility(cpAbility.GetPointer());
	}

	// A deck can have any number of cards named Persistent Petitioners.
	// Not implemented: it's a deck building rule.
}

bool CPersistentPetitionersCard::BeforeMillOne(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 1);
	return false;
}

bool CPersistentPetitionersCard::BeforeMillTwelve(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 12);
	return false;
}

//____________________________________________________________________________
//
CPteramanderCard::CPteramanderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Pteramander"), CardType::Creature, CREATURE_TYPE2(Salamander, Drake), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
	, m_Adapt(this)
{
	// {7}{U}: Adapt 4. This ability costs {1} less to activate for each instant and sorcery card in your graveyard.
	// (one ability for each reduction, as the cost reductions of Ghalta in Rivals of Ixalan)
	m_Adapt.AddAdaptAbility(_T("7") BLUE_MANA_TEXT, 4);

	typedef BOOL (CPteramanderCard::*Condition)(BOOL);
	Condition conditions[] = { &CPteramanderCard::HasSpells1, &CPteramanderCard::HasSpells2, &CPteramanderCard::HasSpells3,
		&CPteramanderCard::HasSpells4, &CPteramanderCard::HasSpells5, &CPteramanderCard::HasSpells6, &CPteramanderCard::HasSpells7 };
	for (int i = 0; i < 7; ++i)
	{
		CAbility* pAbility = m_Adapt.AddAdaptAbility(MakeCost(6 - i, BLUE_MANA_TEXT), 4);
		AddPlayableIf(this, pAbility, conditions[i]);
	}
}

int CPteramanderCard::CountInstantSorcery() const
{
	CZone* pGraveyard = GetController()->GetZoneById(ZoneId::Graveyard);
	return CCardFilter::GetFilter(_T("instant cards or sorcery cards"))->CountIncluded(pGraveyard->GetCardContainer());
}

//____________________________________________________________________________
//
CSagesRowSavantCard::CSagesRowSavantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sage's Row Savant"), CardType::Creature, CREATURE_TYPE2(Vedalken, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters, scry 2.
	AddEnterTrigger(this, &CSagesRowSavantCard::BeforeScry);
}

bool CSagesRowSavantCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSenateCourierCard::CSenateCourierCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Senate Courier"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// {1}{W}: This creature gains vigilance until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") WHITE_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Gains vigilance until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSenateCourierCard::BeforeVigilance));
	AddAbility(cpAbility.GetPointer());
}

bool CSenateCourierCard::BeforeVigilance(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::Vigilance);
	return true;
}

//____________________________________________________________________________
//
CSkatewingSpyCard::CSkatewingSpyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skatewing Spy"), CardType::Creature, CREATURE_TYPE3(Vedalken, Rogue, Mutant), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_Adapt(this)
{
	// {5}{U}: Adapt 2.
	m_Adapt.AddAdaptAbility(_T("5") BLUE_MANA_TEXT, 2);

	// Each creature you control with a +1/+1 counter on it has flying.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1),
			Power(+0), Life(+0), CreatureKeyword::Flying));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSkitterEelCard::CSkitterEelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skitter Eel"), CardType::Creature, CREATURE_TYPE2(Fish, Crab), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(3))
	, m_Adapt(this)
{
	// {2}{U}: Adapt 2.
	m_Adapt.AddAdaptAbility(_T("2") BLUE_MANA_TEXT, 2);
}

//____________________________________________________________________________
//
CSphinxOfForesightCard::CSphinxOfForesightCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sphinx of Foresight"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
{
	// You may reveal this card from your opening hand. If you do, scry 3 at the beginning of your first upkeep.
	// Not implemented: the engine has no opening hand actions.

	// At the beginning of your upkeep, scry 1.
	AddStepTrigger<CSphinxOfForesightCard>(this, NodeId::UpkeepStep, false, NULL, &CSphinxOfForesightCard::BeforeScry);
}

bool CSphinxOfForesightCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CWallOfLostThoughtsCard::CWallOfLostThoughtsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wall of Lost Thoughts"), CardType::Creature, CREATURE_TYPE(Wall), nID,
		_T("1") BLUE_MANA_TEXT, Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// When this creature enters, target player mills four cards.
	AddEnterTargetPlayerTrigger(this, &CWallOfLostThoughtsCard::BeforeMill, Characteristic::Negative);
}

bool CWallOfLostThoughtsCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 4);
	return false;
}

//____________________________________________________________________________
//
CWindstormDrakeCard::CWindstormDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Windstorm Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Other creatures you control with flying get +1/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CreatureKeywordComparer(CreatureKeyword::Flying, false),
			Power(+1), Life(+0)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetEnchantmentCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define ELEMENTAL_AK_TOKEN_NAME		_T("Elemental AK")
#define ELEMENTAL_AK_TOKEN_ID		64041

// "Target opponent" for a damage ability (players only; it can't target planeswalkers)
static CTargetChgLifeSpell* AddOpponentDamageAbility(CCard* pCard, LPCTSTR strCost, int nDamage)
{
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(pCard,
			strCost,
			FALSE_CARD_COMPARER, TRUE,
			Life(-nDamage), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

// "{cost}: This creature gets/gains ... until end of turn" (the callback does the effect)
template <class T>
static void AddSelfAbility(T* pCard, LPCTSTR strCost, LPCTSTR strText, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard, strCost));

	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "As long as you control a <type> planeswalker, this creature gets +P/+T and has <keyword>"
static void AddPlaneswalkerTypeBonus(CCard* pCard, PlaneswalkerType type, int nPower, int nToughness, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			Power(nPower), Life(nToughness), keyword));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(type));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	pCard->AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CAeromunculusCard::CAeromunculusCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aeromunculus"), CardType::Creature, CREATURE_TYPE2(Homunculus, Mutant), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
	, m_Adapt(this)
{
	// {2}{G}{U}: Adapt 1.
	m_Adapt.AddAdaptAbility(_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, 1);
}

//____________________________________________________________________________
//
CAzoriusKnightArbiterCard::CAzoriusKnightArbiterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Azorius Knight-Arbiter"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(5))
{
	// Vigilance. This creature can't be blocked.
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

//____________________________________________________________________________
//
CAzoriusSkyguardCard::CAzoriusSkyguardCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Azorius Skyguard"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Flying, first strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Creatures your opponents control get -1/-0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(-1), Life(+0)));
	cpAbility->SetAffectOpponentCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CBasilicaBellHauntCard::CBasilicaBellHauntCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Basilica Bell-Haunt"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, each opponent discards a card and you gain 3 life.
	AddEnterTrigger(this, &CBasilicaBellHauntCard::BeforeDiscard);
}

bool CBasilicaBellHauntCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	GainLife(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CBolracClanCrusherCard::CBolracClanCrusherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bolrac-Clan Crusher"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// {T}, Remove a +1/+1 counter from a creature you control: This creature deals 2 damage to any target.
	// (it can't target planeswalkers)
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddAnyCardCounterCost(_T("+1/+1"), -1, 1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CChargingWarBoarCard::CChargingWarBoarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charging War Boar"), CardType::Creature, CREATURE_TYPE(Boar), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(1))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// As long as you control a Domri planeswalker, this creature gets +1/+1 and has trample.
	AddPlaneswalkerTypeBonus(this, PlaneswalkerType::Domri, +1, +1, CreatureKeyword::Trample);
}

//____________________________________________________________________________
//
CClanGuildmageCard::CClanGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Clan Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		RED_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// {1}{R}, {T}: Target creature can't block this turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CClanGuildmageCard::BeforeCantBlock));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{G}, {T}: Target land you control becomes a 4/4 Elemental creature with haste until end of turn. It's still a
		// land. (as Skarrg Guildmage in Gatecrash)
		// Partial: the land doesn't gain haste.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") GREEN_MANA_TEXT,
				new CardTypeComparer(CardType::_Land, false), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CClanGuildmageCard::BeforeAnimate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CClanGuildmageCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, 0, 0, CreatureKeyword::CantBlock);
	return false;
}

bool CClanGuildmageCard::BeforeAnimate(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(ELEMENTAL_AK_TOKEN_NAME, ELEMENTAL_AK_TOKEN_ID, pAction->GetController());
	CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
		TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater);
	pAnimate->ApplyTo(pCard);
	pRemove.ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CCombineGuildmageCard::CCombineGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Combine Guildmage"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
	, m_nCounterTurn(-1)
{
	{
		// {1}{G}, {T}: This turn, each creature you control enters with an additional +1/+1 counter on it.
		// Partial: only while this creature stays on the battlefield (the counter is put just after the creature enters).
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") GREEN_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("This turn, each creature you control enters with an additional +1/+1 counter. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCombineGuildmageCard::BeforeActivate));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCombineGuildmageCard::SetEnterContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{U}, {T}: Move a +1/+1 counter from target creature you control onto another target creature you control.
		counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
				_T("1") BLUE_MANA_TEXT,
				new AndCardComparer(new AnyCreatureComparer, new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1)), false,
				new AnyCreatureComparer, false, _T(""), TRUE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting2()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCombineGuildmageCard::BeforeMove));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCombineGuildmageCard::BeforeActivate(CAbilityAction* pAction)
{
	m_nCounterTurn = GetGame()->GetGameTurnNumber();
	return true;
}

bool CCombineGuildmageCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (m_nCounterTurn == GetGame()->GetGameTurnNumber() && pFromZone && pFromZone->GetZoneId() != ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

bool CCombineGuildmageCard::BeforeMove(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (!pCard1 || !pCard2 || pCard1 == pCard2)
		return false;

	if (pCard1->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0)
	{
		CCardCounterModifier(_T("+1/+1"), -1).ApplyTo(pCard1);
		AddPlusCounter(pCard2, 1);
	}
	return false;
}

//____________________________________________________________________________
//
CCultGuildmageCard::CCultGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cult Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	{
		// {3}{B}, {T}: Target player discards a card. Activate only as a sorcery.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("3") BLACK_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCultGuildmageCard::BeforeDiscard));
		AddAbility(cpAbility.GetPointer());
	}

	// {R}, {T}: This creature deals 1 damage to target opponent or planeswalker. (it can't target planeswalkers)
	AddOpponentDamageAbility(this, RED_MANA_TEXT, 1);
}

bool CCultGuildmageCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);
	return false;
}

//____________________________________________________________________________
//
CDeputyOfDetentionCard::CDeputyOfDetentionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deputy of Detention"), CardType::Creature, CREATURE_TYPE2(Vedalken, Wizard), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(3))
{
	// When this creature enters, exile target nonland permanent an opponent controls and all other nonland permanents that
	// player controls with the same name as that permanent until this creature leaves the battlefield.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CDeputyOfDetentionCard::BeforeExile, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	pTargeting->SetIncludeNonControllerCardsOnly();

	AddLeaveTrigger(this, &CDeputyOfDetentionCard::BeforeReturn);
}

bool CDeputyOfDetentionCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CString strName = pTarget->GetCardName(FALSE);
	CPlayer* pPlayer = pTarget->GetController();
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer cards;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand() && pCard->GetCardName(FALSE) == strName)
			cards.AddCard(pCard, CardPlacement::Top);
	}

	for (int i = 0; i < cards.GetSize(); ++i)
		ExileUntilLeaves(m_Exiled, cards.GetAt(i), pAction->GetController());
	return false;
}

bool CDeputyOfDetentionCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CDomrisNodorogCard::CDomrisNodorogCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Domri's Nodorog"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(2))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, you may search your library and/or graveyard for a card named Domri, City Smasher,
	// reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CDomrisNodorogCard::BeforeSearch, true);
}

bool CDomrisNodorogCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Domri, City Smasher"));
	return true;
}

//____________________________________________________________________________
//
CDovinsAutomatonCard::CDovinsAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dovin's Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Homunculus), nID,
		_T("4"), Power(3), Life(3))
{
	// As long as you control a Dovin planeswalker, this creature gets +2/+2 and has vigilance.
	AddPlaneswalkerTypeBonus(this, PlaneswalkerType::Dovin, +2, +2, CreatureKeyword::Vigilance);
}

//____________________________________________________________________________
//
CFirebladeArtistCard::CFirebladeArtistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fireblade Artist"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// At the beginning of your upkeep, you may sacrifice a creature. When you do, this creature deals 2 damage to target
	// opponent or planeswalker.
	// Partial: the damage goes to the opponent (it isn't targeted and it can't go to a planeswalker).
	AddStepTrigger<CFirebladeArtistCard>(this, NodeId::UpkeepStep, true, NULL, &CFirebladeArtistCard::BeforeSacrifice);
}

bool CFirebladeArtistCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nBefore = CountCreatures(GetGame(), pController);
	if (nBefore == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Graveyard, MoveType::Sacrifice);
	if (CountCreatures(GetGame(), pController) < nBefore)
		DamageEachOpponent(this, pController, 2);
	return true;
}

//____________________________________________________________________________
//
CFootlightFiendCard::CFootlightFiendCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Footlight Fiend"), CardType::Creature, CREATURE_TYPE(Devil), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// {B/R}
	AddHybridPermanentSpells(this, _T(""), 1, BLACK_MANA_TEXT, RED_MANA_TEXT);

	// When this creature dies, it deals 1 damage to any target. (it can't target planeswalkers)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFootlightFiendCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CFootlightFiendCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 1);
	return false;
}

//____________________________________________________________________________
//
CFrenziedArynxCard::CFrenziedArynxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frenzied Arynx"), CardType::Creature, CREATURE_TYPE2(Cat, Beast), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
	, m_Riot(this)
{
	// Riot. Trample
	m_Riot.AddRiotAbility();
	GetCreatureKeyword()->AddTrample(FALSE);

	// {4}{R}{G}: This creature gets +3/+0 until end of turn.
	AddSelfAbility(this, _T("4") RED_MANA_TEXT GREEN_MANA_TEXT, _T("+3/+0 until end of turn. Activates"),
		&CFrenziedArynxCard::BeforePump);
}

bool CFrenziedArynxCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +3, 0);
	return true;
}

//____________________________________________________________________________
//
CFrilledMysticCard::CFrilledMysticCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frilled Mystic"), CardType::Creature, CREATURE_TYPE3(Elf, Lizard, Wizard), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, you may counter target spell. (as Mystic Snake in Apocalypse)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T(""));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Stack);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardKeywordComparer(CardKeyword::CantBeCountered, false)));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CGallopingLizrogCard::CGallopingLizrogCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Galloping Lizrog"), CardType::Creature, CREATURE_TYPE2(Frog, Lizard), nID,
		_T("3") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CGallopingLizrogCard::OnCreaturesSelected))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, you may remove any number of +1/+1 counters from among creatures you control. If you do,
	// put twice that many +1/+1 counters on this creature.
	// Partial: you choose creatures, and all the +1/+1 counters of each chosen creature are removed.
	AddEnterTrigger(this, &CGallopingLizrogCard::BeforeChoose);
}

bool CGallopingLizrogCard::BeforeChoose(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		int nCount = pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
		if (pCard == this || nCount == 0)
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Remove the %d +1/+1 counter(s) of %s"), nCount, pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this, pAction->GetController());
	return true;
}

void CGallopingLizrogCard::OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	int nRemoved = 0;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;

		int nCount = pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
		if (nCount > 0)
		{
			CCardCounterModifier(_T("+1/+1"), -nCount).ApplyTo(pCard);
			nRemoved += nCount;
		}
	}
	if (nRemoved > 0)
		AddPlusCounter(this, 2 * nRemoved);
}

//____________________________________________________________________________
//
CGateColossusCard::CGateColossusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gate Colossus"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("8"), Power(8), Life(8))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// Affinity for Gates (one spell for each reduction, as Ghalta, Primal Hunger)
	typedef BOOL (CGateColossusCard::*Condition)(BOOL);
	Condition conditions[] = { &CGateColossusCard::HasGates1, &CGateColossusCard::HasGates2, &CGateColossusCard::HasGates3,
		&CGateColossusCard::HasGates4, &CGateColossusCard::HasGates5, &CGateColossusCard::HasGates6,
		&CGateColossusCard::HasGates7, &CGateColossusCard::HasGates8 };
	for (int i = 0; i < 8; ++i)
	{
		CString strCost;
		if (7 - i > 0)
			strCost.Format(_T("%d"), 7 - i);
		counted_ptr<CSpell> cpSpell(::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), strCost, TRUE));
		cpSpell->SetMainSpell(FALSE);
		AddPlayableIf(this, cpSpell.GetPointer(), conditions[i]);
		AddSpell(cpSpell.GetPointer());
	}

	// This creature can't be blocked by creatures with power 2 or less.
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);

	// Whenever a Gate you control enters, you may put this card from your graveyard on top of your library.
	// (a trigger from the graveyard, as Arclight Phoenix)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield, FALSE, TRUE, FALSE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("Gates")));
	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGateColossusCard::SetGateContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGateColossusCard::BeforeTop));
	AddAbility(cpAbility.GetPointer());
}

int CGateColossusCard::CountGates() const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	return CCardFilter::GetFilter(_T("Gates"))->CountIncluded(pBattlefield->GetCardContainer());
}

bool CGateColossusCard::SetGateContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Graveyard;
}

bool CGateColossusCard::BeforeTop(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CGraspingThrullCard::CGraspingThrullCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Grasping Thrull"), CardType::Creature, CREATURE_TYPE(Thrull), nID,
		_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, it deals 2 damage to each opponent and you gain 2 life.
	AddEnterTrigger(this, &CGraspingThrullCard::BeforeDrain);
}

bool CGraspingThrullCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	GainLife(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CGruulSpellbreakerCard::CGruulSpellbreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gruul Spellbreaker"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
	, m_Riot(this)
{
	// Riot. Trample
	m_Riot.AddRiotAbility();
	GetCreatureKeyword()->AddTrample(FALSE);

	// During your turn, you and this creature have hexproof.
	// Partial: the creature gains hexproof at the beginning of your upkeep until end of turn (as Street Riot), and you
	// don't have hexproof.
	AddStepTrigger<CGruulSpellbreakerCard>(this, NodeId::UpkeepStep, false, NULL, &CGruulSpellbreakerCard::BeforeHexproof);
}

bool CGruulSpellbreakerCard::BeforeHexproof(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCardKeyword()->AddHexproof(TRUE);
	return true;
}

//____________________________________________________________________________
//
CGyreEngineerCard::CGyreEngineerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gyre Engineer"), CardType::Creature, CREATURE_TYPE2(Vedalken, Wizard), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(1))
{
	// {T}: Add {G}{U}.
	AddTapManaAbility(this, GREEN_MANA_TEXT BLUE_MANA_TEXT);
}

//____________________________________________________________________________
//
CHackrobatCard::CHackrobatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hackrobat"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(3))
{
	// Spectacle {B}{R}
	AddPermanentSpectacle(this, BLACK_MANA_TEXT RED_MANA_TEXT, &CHackrobatCard::CanSpectacle);

	// {B}: This creature gains deathtouch until end of turn.
	AddSelfAbility(this, BLACK_MANA_TEXT, _T("Gains deathtouch until end of turn. Activates"), &CHackrobatCard::BeforeDeathtouch);

	// {R}: This creature gets +2/-2 until end of turn.
	AddSelfAbility(this, RED_MANA_TEXT, _T("+2/-2 until end of turn. Activates"), &CHackrobatCard::BeforePump);
}

BOOL CHackrobatCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

bool CHackrobatCard::BeforeDeathtouch(CAbilityAction* pAction)
{
	GainCardKeyword(this, CardKeyword::Deathtouch);
	return true;
}

bool CHackrobatCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, -2);
	return true;
}

//____________________________________________________________________________
//
CHydroidKrasisCard::CHydroidKrasisCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Hydroid Krasis"), CardType::Creature, CREATURE_TYPE3(Jellyfish, Hydra, Beast), nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CHydroidKrasisCard::OnZoneChanged))
	, m_nX(0)
{
	// {X}{G}{U}. This creature enters with X +1/+1 counters on it.
	// (creature spell with {X} as Worldsoul Colossus in Guilds of Ravnica: the main spell can't be cast, the X spell
	// remembers X when it resolves and the creature gets the counters when it enters)
	AddPlayableIf(this, GetSpells().GetAt(0), &CHydroidKrasisCard::Never);

	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Creature, GREEN_MANA_TEXT BLUE_MANA_TEXT));
	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHydroidKrasisCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When you cast this spell, you gain half X life and draw half X cards. Round down each time.
	// (as Hatchery Spider: a trigger when it is put on the stack; X is the extra value of the last casting cost)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHydroidKrasisCard::BeforeCastTrigger));
	AddAbility(cpAbility.GetPointer());
}

bool CHydroidKrasisCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	return true;
}

bool CHydroidKrasisCard::BeforeCastTrigger(CAbilityAction* pAction)
{
	int nX = GetLastCastingCostConfigEntry().GetExtraValue();
	if (nX < 0)
		nX = -nX;
	if (nX / 2 > 0)
	{
		GainLife(this, pAction->GetController(), nX / 2);
		DrawCards(GetGame(), pAction->GetController(), nX / 2);
	}
	return true;
}

void CHydroidKrasisCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		if (moveType == MoveType::Cast && m_nX > 0)
			CCardCounterModifier(_T("+1/+1"), m_nX).ApplyTo(this);
		m_nX = 0;
	}
}

//____________________________________________________________________________
//
CImperiousOligarchCard::CImperiousOligarchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Imperious Oligarch"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(1))
	, m_Afterlife(this)
{
	// Vigilance. Afterlife 1
	GetCreatureKeyword()->AddVigilance(FALSE);
	m_Afterlife.AddAfterlifeAbility(1);
}

//____________________________________________________________________________
//
CJudithTheScourgeDivaCard::CJudithTheScourgeDivaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Judith, the Scourge Diva"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Shaman), nID,
		_T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	{
		// Other creatures you control get +1/+0.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(+1), Life(+0)));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->GetEnchantmentCardFilter().AddNegateComparer(new SpecificCardComparer(this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever a nontoken creature you control dies, Judith deals 1 damage to any target. (it can't target
		// planeswalkers)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new CardTypeComparer(CardType::Token, false));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJudithTheScourgeDivaCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CJudithTheScourgeDivaCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 1);
	return false;
}

//____________________________________________________________________________
//
CKnightOfTheLastBreathCard::CKnightOfTheLastBreathCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of the Last Breath"), CardType::Creature, CREATURE_TYPE2(Giant, Knight), nID,
		_T("5") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
	, m_SacrificeFilter(_T("another nontoken creature"), _T("other nontoken creatures"),
		new AndCardComparer(new AnyCreatureComparer,
			new AndCardComparer(new NegateCardComparer(new SpecificCardComparer(this)),
				new NegateCardComparer(new CardTypeComparer(CardType::Token, false)))))
	, m_Afterlife(this)
{
	// {3}, Sacrifice another nontoken creature: Create a 1/1 white and black Spirit creature token with flying.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("3"),
			SPIRIT_C_TOKEN_NAME, SPIRIT_C_TOKEN_ID, 1));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	AddAbility(cpAbility.GetPointer());

	// Afterlife 3
	m_Afterlife.AddAfterlifeAbility(3);
}

//____________________________________________________________________________
//
CLaviniaAzoriusRenegadeCard::CLaviniaAzoriusRenegadeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lavinia, Azorius Renegade"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Soldier), nID,
		WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
	, m_SpellFilter(_T("a noncreature spell with mana value greater than the number of lands its controller controls"),
		_T("noncreature spells with mana value greater than the number of lands their controller controls"),
		new LaviniaSpellComparer)
{
	// Each opponent can't cast noncreature spells with mana value greater than the number of lands that player controls.
	// (as Gaddock Teeg)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::CantPlaySpells, (int)&m_SpellFilter));
	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());

	// Whenever an opponent casts a spell, if no mana was spent to cast it, counter that spell.
	// Not implemented: the engine doesn't know the mana spent to cast a spell (and it can't cast spells for free).
}

//____________________________________________________________________________
//
CNikyaOfTheOldWaysCard::CNikyaOfTheOldWaysCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nikya of the Old Ways"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Centaur, Druid), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
	, m_NoncreatureFilter(_T("a noncreature spell"), _T("noncreature spells"), new NegateCardComparer(new AnyCreatureComparer))
{
	{
		// You can't cast noncreature spells. (as Nullhide Ferox)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantPlaySpells, (int)&m_NoncreatureFilter));
		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you tap a land for mana, add one mana of any type that land produced. (as Mana Flare in Unlimited)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNikyaOfTheOldWaysCard::SetTriggerContext));

		m_pTriggeredAbility = cpAbility.GetPointer();
		AddAbility(m_pTriggeredAbility);
	}
}

bool CNikyaOfTheOldWaysCard::SetTriggerContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
	const CManaProductionAbilityAction* pManaAction) const
{
	bool bActivate = false;
	BOOL bColorless = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction).GetMana(CManaPool::Color::Colorless) ? TRUE : FALSE;
	m_pTriggeredAbility->SetProduceColorless(bColorless);
	bActivate = bActivate || bColorless;

	BOOL bRed = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction).GetMana(CManaPool::Color::Red) ? TRUE : FALSE;
	m_pTriggeredAbility->SetProduceRed(bRed);
	bActivate = bActivate || bRed;

	BOOL bGreen = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction).GetMana(CManaPool::Color::Green) ? TRUE : FALSE;
	m_pTriggeredAbility->SetProduceGreen(bGreen);
	bActivate = bActivate || bGreen;

	BOOL bBlue = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction).GetMana(CManaPool::Color::Blue) ? TRUE : FALSE;
	m_pTriggeredAbility->SetProduceBlue(bBlue);
	bActivate = bActivate || bBlue;

	BOOL bBlack = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction).GetMana(CManaPool::Color::Black) ? TRUE : FALSE;
	m_pTriggeredAbility->SetProduceBlack(bBlack);
	bActivate = bActivate || bBlack;

	BOOL bWhite = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction).GetMana(CManaPool::Color::White) ? TRUE : FALSE;
	m_pTriggeredAbility->SetProduceWhite(bWhite);
	bActivate = bActivate || bWhite;

	return bActivate;
}

//____________________________________________________________________________
//
CPitilessPontiffCard::CPitilessPontiffCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pitiless Pontiff"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// {1}, Sacrifice another creature: This creature gains deathtouch and indestructible until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
	cpAbility->SetAbilityText(_T("Gains deathtouch and indestructible until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPitilessPontiffCard::BeforeKeywords));
	AddAbility(cpAbility.GetPointer());
}

bool CPitilessPontiffCard::BeforeKeywords(CAbilityAction* pAction)
{
	GainCardKeyword(this, CardKeyword::Deathtouch);
	GainCardKeyword(this, CardKeyword::Indestructible);
	return true;
}

//____________________________________________________________________________
//
CPrimeSpeakerVannifarCard::CPrimeSpeakerVannifarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prime Speaker Vannifar"), CardType::Creature | CardType::Legendary, CREATURE_TYPE3(Elf, Ooze, Wizard), nID,
		_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(4))
	, m_nManaValue(0)
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
	, m_SearchFilter(_T("a creature card with the chosen mana value"), _T("creature cards with the chosen mana value"),
		new VannifarComparer(&m_nManaValue))
{
	// {T}, Sacrifice another creature: Search your library for a creature card with mana value equal to 1 plus the
	// sacrificed creature's mana value, put that card onto the battlefield, then shuffle. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->SetAbilityText(_T("Search for a creature card with mana value 1 more than the sacrificed creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrimeSpeakerVannifarCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CPrimeSpeakerVannifarCard::BeforeSearch(CAbilityAction* pAction)
{
	// (the sacrificed card of the cost, as Severed Strands)
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	if (!pSacrificed || pSacrificed->GetSize() == 0)
		return true;

	m_nManaValue = (int)pSacrificed->GetAt(0)->GetConvertedManaCost() + 1;
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, &m_SearchFilter, FALSE);
	return true;
}

//____________________________________________________________________________
//
CRafterDemonCard::CRafterDemonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rafter Demon"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(4), Life(2))
	, m_bSpectacle(FALSE)
{
	// Spectacle {3}{B}{R} (the spells remember which cost was paid, as Rix Maadi Reveler)
	GetSpells().GetAt(0)->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRafterDemonCard::BeforeMainResolution));
	AddPermanentSpectacle(this, _T("3") BLACK_MANA_TEXT RED_MANA_TEXT, &CRafterDemonCard::CanSpectacle,
		&CRafterDemonCard::BeforeSpectacleResolution);

	// When this creature enters, if its spectacle cost was paid, each opponent discards a card.
	AddEnterIfTrigger(this, &CRafterDemonCard::SetEnterContext, &CRafterDemonCard::BeforeDiscard);
}

BOOL CRafterDemonCard::CanSpectacle(BOOL bIncludeTricks)
{
	return OpponentLostLifeThisTurn(GetController());
}

bool CRafterDemonCard::BeforeMainResolution(CAbilityAction* pAction)
{
	m_bSpectacle = FALSE;
	return true;
}

bool CRafterDemonCard::BeforeSpectacleResolution(CAbilityAction* pAction)
{
	m_bSpectacle = TRUE;
	return true;
}

bool CRafterDemonCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Cast && m_bSpectacle;
}

bool CRafterDemonCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

//____________________________________________________________________________
//
CRakdosFirewheelerCard::CRakdosFirewheelerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rakdos Firewheeler"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
{
	// When this creature enters, it deals 2 damage to target opponent and 2 damage to up to one target creature or
	// planeswalker.
	// Partial: the 2 damage goes to each opponent (not a target), and the target is a creature or planeswalker.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CRakdosFirewheelerCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	pTargeting->SetSubjectCount(0, 1);
}

bool CRakdosFirewheelerCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard)
	{
		if (pCard->GetZoneId() == ZoneId::Battlefield)
		{
			if (pCard->GetCardType().IsCreature())
				DealDamageToCreature(this, pCard, 2);
			else
				CCardCounterModifier(LOYALTY_COUNTER, -2).ApplyTo(pCard);
		}
	}
	return false;
}

//____________________________________________________________________________
//
CRakdosRoustaboutCard::CRakdosRoustaboutCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rakdos Roustabout"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(2))
{
	// Whenever this creature becomes blocked, it deals 1 damage to the player or planeswalker it's attacking.
	// Partial: the damage goes to the opponent. (as Deeproot Warrior in Ixalan)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockedEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRakdosRoustaboutCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CRakdosRoustaboutCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CRakdosTheShowstopperCard::CRakdosTheShowstopperCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rakdos, the Showstopper"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Demon), nID,
		_T("4") BLACK_MANA_TEXT RED_MANA_TEXT, Power(6), Life(6))
{
	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When Rakdos enters, flip a coin for each creature that isn't a Demon, Devil, or Imp. Destroy each creature whose
	// coin comes up tails.
	AddEnterTrigger(this, &CRakdosTheShowstopperCard::BeforeFlips);
}

bool CRakdosTheShowstopperCard::BeforeFlips(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), NULL, FALSE, creatures);

	CreatureTypeComparer demon(CREATURE_TYPE(Demon), false);
	CreatureTypeComparer devil(CREATURE_TYPE(Devil), false);
	CreatureTypeComparer imp(CREATURE_TYPE(Imp), false);

	CCountedCardContainer tails;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (demon(pCard) || devil(pCard) || imp(pCard))
			continue;
		if (pController->GetRand() % 2 == 0)
			tails.AddCard(pCard, CardPlacement::Top);
	}

	if (!m_pGame->IsThinking())
	{
		CString strMessage;
		strMessage.Format(_T("%d creature(s) come up tails"), tails.GetSize());
		m_pGame->Message(strMessage, pController->IsComputer() ? m_pGame->GetComputerImage() : m_pGame->GetHumanImage(),
			MessageImportance::High);
	}

	CMoveCardModifier pDestroy = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pController);
	for (int i = 0; i < tails.GetSize(); ++i)
		if (tails.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pDestroy.ApplyTo(tails.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CRavagerWurmCard::CRavagerWurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ravager Wurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(5))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();

	// When this creature enters, choose up to one - This creature fights target creature you don't control; or Destroy
	// target land with an activated ability that isn't a mana ability.
	// Partial: only the fight mode (an optional trigger).
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CRavagerWurmCard::BeforeFight, true, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CRavagerWurmCard::BeforeFight(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard && GetZoneId() == ZoneId::Battlefield)
		Fight(this, pCard);
	return false;
}

//____________________________________________________________________________
//
CRubblebeltRunnerCard::CRubblebeltRunnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rubblebelt Runner"), CardType::Creature, CREATURE_TYPE2(Lizard, Warrior), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
	, m_BlockerFilter(_T("a nontoken creature"), _T("nontoken creatures"),
		new NegateCardComparer(new CardTypeComparer(CardType::Token, false)))
{
	// This creature can't be blocked by creature tokens. (as Giltgrove Stalker: the filter of the creatures that can)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

//____________________________________________________________________________
//
CRubbleSlingerCard::CRubbleSlingerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rubble Slinger"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// {2}{R/G}
	AddHybridPermanentSpells(this, _T("2"), 1, RED_MANA_TEXT, GREEN_MANA_TEXT);

	// Reach
	GetCreatureKeyword()->AddReach(FALSE);
}

//____________________________________________________________________________
//
CScuttlegatorCard::CScuttlegatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scuttlegator"), CardType::Creature, CREATURE_TYPE3(Crab, Turtle, Crocodile), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
	, m_Adapt(this)
{
	// {4}{G/U}{G/U}
	AddHybridPermanentSpells(this, _T("4"), 2, GREEN_MANA_TEXT, BLUE_MANA_TEXT);

	// Defender. As long as this creature has a +1/+1 counter on it, it can attack as though it didn't have defender.
	// (the defender is given while it has no +1/+1 counters, as Thoughtbound Phantasm)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this),
				new NegateCardComparer(new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1))),
			Power(+0), Life(+0), CreatureKeyword::Defender));
	AddAbility(cpAbility.GetPointer());

	// {6}{G/U}{G/U}: Adapt 3.
	std::vector<CString> costs;
	GetHybridCosts(_T("6"), 2, GREEN_MANA_TEXT, BLUE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		m_Adapt.AddAdaptAbility(costs[i], 3);
}

//____________________________________________________________________________
//
CSenateGriffinCard::CSenateGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Senate Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
	// {2}{W/U}{W/U}
	AddHybridPermanentSpells(this, _T("2"), 2, WHITE_MANA_TEXT, BLUE_MANA_TEXT);

	// When this creature enters, scry 1.
	AddEnterTrigger(this, &CSenateGriffinCard::BeforeScry);
}

bool CSenateGriffinCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSenateGuildmageCard::CSenateGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Senate Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	{
		// {W}, {T}: You gain 2 life.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, WHITE_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("You gain 2 life. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSenateGuildmageCard::BeforeGainLife));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {U}, {T}: Draw a card, then discard a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, BLUE_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Draw a card, then discard a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSenateGuildmageCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSenateGuildmageCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

bool CSenateGuildmageCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSeraphOfTheScalesCard::CSeraphOfTheScalesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Seraph of the Scales"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(3))
	, m_Afterlife(this)
{
	// {W}: This creature gains vigilance until end of turn.
	AddSelfAbility(this, WHITE_MANA_TEXT, _T("Gains vigilance until end of turn. Activates"), &CSeraphOfTheScalesCard::BeforeVigilance);

	// {B}: This creature gains deathtouch until end of turn.
	AddSelfAbility(this, BLACK_MANA_TEXT, _T("Gains deathtouch until end of turn. Activates"), &CSeraphOfTheScalesCard::BeforeDeathtouch);

	// Afterlife 2
	m_Afterlife.AddAfterlifeAbility(2);
}

bool CSeraphOfTheScalesCard::BeforeVigilance(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::Vigilance);
	return true;
}

bool CSeraphOfTheScalesCard::BeforeDeathtouch(CAbilityAction* pAction)
{
	GainCardKeyword(this, CardKeyword::Deathtouch);
	return true;
}

//____________________________________________________________________________
//
CSharktocrabCard::CSharktocrabCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sharktocrab"), CardType::Creature, CREATURE_TYPE3(Shark, Octopus, Crab), nID,
		_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
	, m_Adapt(this)
{
	// {2}{G}{U}: Adapt 1.
	m_Adapt.AddAdaptAbility(_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, 1);

	// Whenever one or more +1/+1 counters are put on this creature, tap target creature an opponent controls. That
	// creature doesn't untap during its controller's next untap step. (as Fathom Mage)
	counted_ptr<CounterTriggeredAbility> cpAbility(::CreateObject<CounterTriggeredAbility>(this));

	cpAbility->SetOptionalType(CounterTriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetOnIncreaseOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(CounterTriggeredAbility::ContextFunction(this, &CSharktocrabCard::SetCounterContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSharktocrabCard::BeforeTap));
	AddAbility(cpAbility.GetPointer());
}

bool CSharktocrabCard::SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	return pFromCard == this && (CString)name == _T("+1/+1") && n_value > old;
}

bool CSharktocrabCard::BeforeTap(CAbilityAction* pAction)
{
	TapAndSkipUntap(GetTargetCreature(pAction));
	return false;
}

//____________________________________________________________________________
//
CSphinxOfNewPrahvCard::CSphinxOfNewPrahvCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sphinx of New Prahv"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(3))
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Spells your opponents cast that target this creature cost {2} more to cast.
	// Not implemented: the engine can't increase the cost of a spell depending on its targets.
}

//____________________________________________________________________________
//
CSphinxOfTheGuildpactCard::CSphinxOfTheGuildpactCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sphinx of the Guildpact"), CardType::_ArtifactCreature, CREATURE_TYPE(Sphinx), nID,
		_T("7"), Power(5), Life(5))
	, m_HexproofFrom(this, new CardMulticoloredComparer(CardMulticoloredComparer::MonocoloredCards))
{
	// Sphinx of the Guildpact is all colors. (as Transguild Courier in Dissension)
	AddCardType(CardType::_ColorMask, CardType::_ColorMask);

	// Flying. Hexproof from monocolored
}

//____________________________________________________________________________
//
CSunderShamanCard::CSunderShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sunder Shaman"), CardType::Creature, CREATURE_TYPE2(Giant, Shaman), nID,
		RED_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// This creature can't be blocked by more than one creature.
	GetCreatureKeyword()->AddCantBeBlockedByMultiple(FALSE);

	// Whenever this creature deals combat damage to a player, destroy target artifact or enchantment that player controls.
	// (the targets are the permanents of the opponents)
	counted_ptr<DamageTriggeredAbility> cpAbility(::CreateObject<DamageTriggeredAbility>(this));

	cpAbility->SetOptionalType(DamageTriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSunderShamanCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CSunderShamanCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CSyndicateGuildmageCard::CSyndicateGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syndicate Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	{
		// {1}{W}, {T}: Tap target creature with power 4 or greater.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") WHITE_MANA_TEXT,
				new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		AddAbility(cpAbility.GetPointer());
	}

	// {4}{B}, {T}: This creature deals 2 damage to target opponent or planeswalker. (it can't target planeswalkers)
	AddOpponentDamageAbility(this, _T("4") BLACK_MANA_TEXT, 2);
}

//____________________________________________________________________________
//
CTeysaKarlovCard::CTeysaKarlovCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Teysa Karlov"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Advisor), nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(4))
{
	// If a creature dying causes a triggered ability of a permanent you control to trigger, that ability triggers an
	// additional time.
	// Not implemented: the engine can't make abilities trigger an additional time.

	// Creature tokens you control have vigilance and lifelink.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CardTypeComparer(CardType::Token, false),
			Power(+0), Life(+0), CreatureKeyword::Vigilance));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CVizkopaVampireCard::CVizkopaVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vizkopa Vampire"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(1))
{
	// {2}{W/B}
	AddHybridPermanentSpells(this, _T("2"), 1, WHITE_MANA_TEXT, BLACK_MANA_TEXT);

	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

//____________________________________________________________________________
//
CZeganaUtopianSpeakerCard::CZeganaUtopianSpeakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Zegana, Utopian Speaker"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
	, m_Adapt(this)
{
	// When Zegana enters, if you control another creature with a +1/+1 counter on it, draw a card.
	AddEnterIfTrigger(this, &CZeganaUtopianSpeakerCard::SetEnterContext, &CZeganaUtopianSpeakerCard::BeforeDraw);

	// {4}{G}{U}: Adapt 4.
	m_Adapt.AddAdaptAbility(_T("4") GREEN_MANA_TEXT BLUE_MANA_TEXT, 4);

	// Each creature you control with a +1/+1 counter on it has trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1),
			Power(+0), Life(+0), CreatureKeyword::Trample));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool CZeganaUtopianSpeakerCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this && creatures.GetAt(i)->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0)
			return true;
	return false;
}

bool CZeganaUtopianSpeakerCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CZhurTaaGoblinCard::CZhurTaaGoblinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Zhur-Taa Goblin"), CardType::Creature, CREATURE_TYPE2(Goblin, Berserker), nID,
		RED_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Riot(this)
{
	// Riot
	m_Riot.AddRiotAbility();
}

//____________________________________________________________________________
//
