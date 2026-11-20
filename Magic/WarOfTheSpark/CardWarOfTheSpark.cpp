#include "stdafx.h"
#include "CardWarOfTheSpark.h"

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
#define DOMRI_CHAOS_BRINGER_EMBLEM_NAME	_T("Domri, Chaos Bringer Emblem")
#define DOMRI_CHAOS_BRINGER_EMBLEM_ID	61160
#define ZOMBIE_P_TOKEN_NAME		_T("Zombie (P)")
#define ZOMBIE_P_TOKEN_ID		55009
#define SPIRIT_C_TOKEN_NAME		_T("Spirit (C)")
#define SPIRIT_C_TOKEN_ID		2815
#define GROWTH_COUNTER			_T("growth counter")
#define BEAST_S_TOKEN_NAME			_T("Beast (S)")
#define BEAST_S_TOKEN_ID			55122
#define FROG_LIZARD_A_TOKEN_NAME	_T("Frog Lizard (A)")
#define FROG_LIZARD_A_TOKEN_ID		55123
#define SPHINX_B_TOKEN_NAME			_T("Sphinx (B)")
#define SPHINX_B_TOKEN_ID			55124
#define GOBLIN_C_TOKEN_NAME			_T("Goblin (C)")
#define GOBLIN_C_TOKEN_ID			2702
#define CENTAUR_E_TOKEN_NAME		_T("Centaur (E)")
#define CENTAUR_E_TOKEN_ID			55125
#define HUMAN_C_TOKEN_NAME		_T("Human (C)")
#define HUMAN_C_TOKEN_ID		62013
#define OOZE_G_TOKEN_NAME		_T("Ooze (G)")
#define OOZE_G_TOKEN_ID			55126
#define ILLUSION_D_TOKEN_NAME	_T("Illusion (D)")
#define ILLUSION_D_TOKEN_ID		55127
#define ELEMENTAL_AK_TOKEN_NAME		_T("Elemental AK")
#define ELEMENTAL_AK_TOKEN_ID		64041

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
		DEFINE_CARD(CBlastZoneCard);
		DEFINE_CARD(CEmergenceZoneCard);
		DEFINE_CARD(CInterplanarBeaconCard);
		DEFINE_CARD(CKarnsBastionCard);
		DEFINE_CARD(CMobilizedDistrictCard);
		DEFINE_CARD(CAjaniTheGreatheartedCard);
		DEFINE_CARD(CAngrathCaptainOfChaosCard);
		DEFINE_CARD(CArlinnVoiceOfThePackCard);
		DEFINE_CARD(CAshiokDreamRenderCard);
		DEFINE_CARD(CDavrielRogueShadowmageCard);
		DEFINE_CARD(CDomriAnarchOfBolasCard);
		DEFINE_CARD(CDovinHandOfControlCard);
		DEFINE_CARD(CGideonBlackbladeCard);
		DEFINE_CARD(CGideonTheOathswornCard);
		DEFINE_CARD(CHuatliTheSunsHeartCard);
		DEFINE_CARD(CJaceArcaneStrategistCard);
		DEFINE_CARD(CJaceWielderOfMysteriesCard);
		DEFINE_CARD(CJayaVeneratedFiremageCard);
		DEFINE_CARD(CJiangYangguWildcrafterCard);
		DEFINE_CARD(CKarnTheGreatCreatorCard);
		DEFINE_CARD(CKasminaEnigmaticMentorCard);
		DEFINE_CARD(CKayaBaneOfTheDeadCard);
		DEFINE_CARD(CKioraBehemothBeckonerCard);
		DEFINE_CARD(CLilianaDreadhordeGeneralCard);
		DEFINE_CARD(CNahiriStormOfStoneCard);
		DEFINE_CARD(CNarsetParterOfVeilsCard);
		DEFINE_CARD(CNicolBolasDragonGodCard);
		DEFINE_CARD(CNissaWhoShakesTheWorldCard);
		DEFINE_CARD(CObNixilisTheHateTwistedCard);
		DEFINE_CARD(CRalStormConduitCard);
		DEFINE_CARD(CSaheeliSublimeArtificerCard);
		DEFINE_CARD(CSamutTyrantSmasherCard);
		DEFINE_CARD(CSarkhanTheMasterlessCard);
		DEFINE_CARD(CSorinVengefulBloodlordCard);
		DEFINE_CARD(CTamiyoCollectorOfTalesCard);
		DEFINE_CARD(CTeferiTimeRavelerCard);
		DEFINE_CARD(CTeyoTheShieldmageCard);
		DEFINE_CARD(CTezzeretMasterOfTheBridgeCard);
		DEFINE_CARD(CTheWandererCard);
		DEFINE_CARD(CTibaltRakishInstigatorCard);
		DEFINE_CARD(CUginTheIneffableCard);
		DEFINE_CARD(CVivienChampionOfTheWildsCard);
		DEFINE_CARD(CVraskaSwarmsEminenceCard);
		DEFINE_CARD(CFiremindVesselCard);
		DEFINE_CARD(CGodPharaohsStatueCard);
		DEFINE_CARD(CGuildGlobeCard);
		DEFINE_CARD(CManaGeodeCard);
		DEFINE_CARD(CMizziumTankCard);
		DEFINE_CARD(CParhelionIICard);
		DEFINE_CARD(CSilentSubmersibleCard);
		DEFINE_CARD(CViviensArkbowCard);
		DEFINE_CARD(CAidTheFallenCard);
		DEFINE_CARD(CAngrathsRampageCard);
		DEFINE_CARD(CBleedingEdgeCard);
		DEFINE_CARD(CBondOfDisciplineCard);
		DEFINE_CARD(CBondOfFlourishingCard);
		DEFINE_CARD(CBondOfInsightCard);
		DEFINE_CARD(CBondOfPassionCard);
		DEFINE_CARD(CBondOfRevivalCard);
		DEFINE_CARD(CCallousDismissalCard);
		DEFINE_CARD(CCasualtiesOfWarCard);
		DEFINE_CARD(CCommandTheDreadhordeCard);
		DEFINE_CARD(CContentiousPlanCard);
		DEFINE_CARD(CCourageInCrisisCard);
		DEFINE_CARD(CDavrielsShadowfugueCard);
		DEFINE_CARD(CDeliverUntoEvilCard);
		DEFINE_CARD(CDomrisAmbushCard);
		DEFINE_CARD(CEnterTheGodEternalsCard);
		DEFINE_CARD(CFinaleOfDevastationCard);
		DEFINE_CARD(CFinaleOfEternityCard);
		DEFINE_CARD(CFinaleOfGloryCard);
		DEFINE_CARD(CFinaleOfRevelationCard);
		DEFINE_CARD(CGideonsBattleCryCard);
		DEFINE_CARD(CHonorTheGodPharaohCard);
		DEFINE_CARD(CInvadeTheCityCard);
		DEFINE_CARD(CJacesRuseCard);
		DEFINE_CARD(CJacesTriumphCard);
		DEFINE_CARD(CNeoformCard);
		DEFINE_CARD(CNissasTriumphCard);
		DEFINE_CARD(CPlanewideCelebrationCard);
		DEFINE_CARD(CPriceOfBetrayalCard);
		DEFINE_CARD(CRavnicaAtWarCard);
		DEFINE_CARD(CRelentlessAdvanceCard);
		DEFINE_CARD(CRoleReversalCard);
		DEFINE_CARD(CSingleCombatCard);
		DEFINE_CARD(CSolarBlazeCard);
		DEFINE_CARD(CSparkHarvestCard);
		DEFINE_CARD(CStealthMissionCard);
		DEFINE_CARD(CStormTheCitadelCard);
		DEFINE_CARD(CTamiyosEpiphanyCard);
		DEFINE_CARD(CTheElderspellCard);
		DEFINE_CARD(CTimeWipeCard);
		DEFINE_CARD(CTollOfTheInvasionCard);
		DEFINE_CARD(CWanderersStrikeCard);
		DEFINE_CARD(CWidespreadBrutalityCard);
		DEFINE_CARD(CAwakeningOfVituGhaziCard);
		DEFINE_CARD(CBandTogetherCard);
		DEFINE_CARD(CBattlefieldPromotionCard);
		DEFINE_CARD(CBlindblastCard);
		DEFINE_CARD(CBoltBendCard);
		DEFINE_CARD(CChandrasTriumphCard);
		DEFINE_CARD(CCommenceTheEndgameCard);
		DEFINE_CARD(CCrushDissentCard);
		DEFINE_CARD(CDeathsproutCard);
		DEFINE_CARD(CDesparkCard);
		DEFINE_CARD(CDesperateLungeCard);
		DEFINE_CARD(CDivineArrowCard);
		DEFINE_CARD(CDovinsVetoCard);
		DEFINE_CARD(CForcedLandingCard);
		DEFINE_CARD(CGideonsTriumphCard);
		DEFINE_CARD(CHeartfireCard);
		DEFINE_CARD(CHeartwarmingRedemptionCard);
		DEFINE_CARD(CIgniteTheBeaconCard);
		DEFINE_CARD(CJayasGreetingCard);
		DEFINE_CARD(CLazotepPlatingCard);
		DEFINE_CARD(CLilianasTriumphCard);
		DEFINE_CARD(CNahirisStonebladesCard);
		DEFINE_CARD(CNoEscapeCard);
		DEFINE_CARD(CObNixilissCrueltyCard);
		DEFINE_CARD(CPledgeOfUnityCard);
		DEFINE_CARD(CRallyOfWingsCard);
		DEFINE_CARD(CRalsOutburstCard);
		DEFINE_CARD(CReturnToNatureCard);
		DEFINE_CARD(CSamutsSprintCard);
		DEFINE_CARD(CSarkhansCatharsisCard);
		DEFINE_CARD(CSteadyAimCard);
		DEFINE_CARD(CTeferisTimeTwistCard);
		DEFINE_CARD(CToppleTheStatueCard);
		DEFINE_CARD(CTyrantsScornCard);
		DEFINE_CARD(CUnlikelyAidCard);
		DEFINE_CARD(CBulwarkGiantCard);
		DEFINE_CARD(CCharmedStrayCard);
		DEFINE_CARD(CEnforcerGriffinCard);
		DEFINE_CARD(CGideonsCompanyCard);
		DEFINE_CARD(CGodEternalOketraCard);
		DEFINE_CARD(CGratefulApparitionCard);
		DEFINE_CARD(CIroncladKrovodCard);
		DEFINE_CARD(CLawRuneEnforcerCard);
		DEFINE_CARD(CLoxodonSergeantCard);
		DEFINE_CARD(CMakeshiftBattalionCard);
		DEFINE_CARD(CMartyrForTheCauseCard);
		DEFINE_CARD(CPouncingLynxCard);
		DEFINE_CARD(CRisingPopulaceCard);
		DEFINE_CARD(CSunbladeAngelCard);
		DEFINE_CARD(CTeyosLightshieldCard);
		DEFINE_CARD(CTomikDistinguishedAdvokistCard);
		DEFINE_CARD(CTrustedPegasusCard);
		DEFINE_CARD(CWarScreecherCard);
		DEFINE_CARD(CArborealGrazerCard);
		DEFINE_CARD(CArlinnsWolfCard);
		DEFINE_CARD(CBloomHulkCard);
		DEFINE_CARD(CCentaurNurturerCard);
		DEFINE_CARD(CChallengerTrollCard);
		DEFINE_CARD(CEvolutionSageCard);
		DEFINE_CARD(CGodEternalRhonasCard);
		DEFINE_CARD(CKraulStingerCard);
		DEFINE_CARD(CKronchWranglerCard);
		DEFINE_CARD(CMowuLoyalCompanionCard);
		DEFINE_CARD(CParadiseDruidCard);
		DEFINE_CARD(CPollenbrightDruidCard);
		DEFINE_CARD(CSnarespinnerCard);
		DEFINE_CARD(CThunderingCeratokCard);
		DEFINE_CARD(CViviensGrizzlyCard);
		DEFINE_CARD(CWardscaleCrocodileCard);
		DEFINE_CARD(CAhnCropInvaderCard);
		DEFINE_CARD(CBurningProphetCard);
		DEFINE_CARD(CChainwhipCyclopsCard);
		DEFINE_CARD(CCyclopsElectromancerCard);
		DEFINE_CARD(CDevouringHellionCard);
		DEFINE_CARD(CDreadhordeTwinsCard);
		DEFINE_CARD(CGoblinAssailantCard);
		DEFINE_CARD(CGoblinAssaultTeamCard);
		DEFINE_CARD(CGrimInitiateCard);
		DEFINE_CARD(CIlhargTheRazeBoarCard);
		DEFINE_CARD(CInvadingManticoreCard);
		DEFINE_CARD(CKrenkoTinStreetKingpinCard);
		DEFINE_CARD(CNehebDreadhordeChampionCard);
		DEFINE_CARD(CRagingKronchCard);
		DEFINE_CARD(CSpellgorgerWeirdCard);
		DEFINE_CARD(CTibaltsRagerCard);
		DEFINE_CARD(CTurretOgreCard);
		DEFINE_CARD(CBanehoundCard);
		DEFINE_CARD(CCharityExtractorCard);
		DEFINE_CARD(CDreadmalkinCard);
		DEFINE_CARD(CDuskmantleOperativeCard);
		DEFINE_CARD(CEternalTaskmasterCard);
		DEFINE_CARD(CGodEternalBontuCard);
		DEFINE_CARD(CHeraldOfTheDreadhordeCard);
		DEFINE_CARD(CLazotepBehemothCard);
		DEFINE_CARD(CLazotepReaverCard);
		DEFINE_CARD(CMassacreGirlCard);
		DEFINE_CARD(CShriekdiverCard);
		DEFINE_CARD(CSparkReaperCard);
		DEFINE_CARD(CTithebearerGiantCard);
		DEFINE_CARD(CVampireOpportunistCard);
		DEFINE_CARD(CVizierOfTheScorpionCard);
		DEFINE_CARD(CVraskasFinisherCard);
		DEFINE_CARD(CAshioksSkulkerCard);
		DEFINE_CARD(CAvenEternalCard);
		DEFINE_CARD(CErraticVisionaryCard);
		DEFINE_CARD(CEternalSkylordCard);
		DEFINE_CARD(CFblthpTheLostCard);
		DEFINE_CARD(CFluxChannelerCard);
		DEFINE_CARD(CGodEternalKefnetCard);
		DEFINE_CARD(CGuildpactInformantCard);
		DEFINE_CARD(CJacesProjectionCard);
		DEFINE_CARD(CKiorasDambreakerCard);
		DEFINE_CARD(CNagaEternalCard);
		DEFINE_CARD(CRescuerSphinxCard);
		DEFINE_CARD(CSkyTheaterStrixCard);
		DEFINE_CARD(CSpellkeeperWeirdCard);
		DEFINE_CARD(CThunderDrakeCard);
		DEFINE_CARD(CWallOfRunesCard);
		DEFINE_CARD(CBioessenceHydraCard);
		DEFINE_CARD(CCruelCelebrantCard);
		DEFINE_CARD(CDreadhordeButcherCard);
		DEFINE_CARD(CEliteGuardmageCard);
		DEFINE_CARD(CGleamingOverseerCard);
		DEFINE_CARD(CHuatlisRaptorCard);
		DEFINE_CARD(CIronBullyCard);
		DEFINE_CARD(CLeylineProwlerCard);
		DEFINE_CARD(CLivingTwisterCard);
		DEFINE_CARD(CMayhemDevilCard);
		DEFINE_CARD(CMerfolkSkydiverCard);
		DEFINE_CARD(CNivMizzetRebornCard);
		DEFINE_CARD(CPrismiteCard);
		DEFINE_CARD(CRoaleskApexHybridCard);
		DEFINE_CARD(CRubblebeltRiotersCard);
		DEFINE_CARD(CSaheelisSilverwingCard);
		DEFINE_CARD(CSoulDivinerCard);
		DEFINE_CARD(CStorrevDevkarinLichCard);
		DEFINE_CARD(CTenthDistrictLegionnaireCard);
		DEFINE_CARD(CTolsimirFriendToWolvesCard);
		DEFINE_CARD(CDreadhordeInvasionCard);
		DEFINE_CARD(CKayasGhostformCard);
		DEFINE_CARD(CNewHorizonsCard);
		DEFINE_CARD(COathOfKayaCard);
		DEFINE_CARD(CPrisonRealmCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define PROLIFERATE_TRIGGER_INDEX	7701		// index of the special trigger of CProliferateSupport (per card)
#define CITIZEN_A_TOKEN_NAME		_T("Citizen (A)")
#define CITIZEN_A_TOKEN_ID			64131

//____________________________________________________________________________
//
CProliferateSupport::CProliferateSupport(CCard* pCard)
	: m_pCard(pCard)
	, m_PoisonSelection(pCard->GetGame(), CSelectionSupport::SelectionCallback(this, &CProliferateSupport::OnPoisonSelected))
{
}

void CProliferateSupport::AddProliferateTrigger()
{
	typedef
		TTriggeredSubjectAbility< CTriggeredProliferateAbility, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetTriggerIndex(PROLIFERATE_TRIGGER_INDEX);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(m_pCard));

	cpAbility->GetGatherer().SetSubjectZoneId(ZoneId::Battlefield);
	cpAbility->GetGatherer().GetSubjectCardFilter().AddComparer(new CardAnyCountersComparer);
	cpAbility->GetGatherer().SetSubjectCount(0, SpecialNumber::Any);

	cpAbility->SetSkipStack(TRUE);
	m_pCard->AddAbility(cpAbility.GetPointer());
}

void CProliferateSupport::Proliferate(CPlayer* pController)
{
	// The permanents (the special trigger)
	CSpecialEffectModifier pModifier = CSpecialEffectModifier(m_pCard, PROLIFERATE_TRIGGER_INDEX);
	pModifier.ApplyTo(m_pCard);

	// The players with poison counters (as Contagion Clasp)
	CPlayer* pOpponent = m_pCard->GetGame()->GetNextPlayer(pController);
	BOOL bOpponent = pOpponent && pOpponent != pController && pOpponent->GetPoisonCounters() > 0;
	BOOL bSelf = pController->GetPoisonCounters() > 0 && !pController->IsComputer();
	if (!bOpponent && !bSelf)
		return;

	std::vector<SelectionEntry> entries;
	if (bOpponent)
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Give the opponent another poison counter");
		entries.push_back(entry);
	}
	if (bSelf)
	{
		SelectionEntry entry;
		entry.dwContext = 2;
		entry.strText = _T("Give yourself another poison counter");
		entries.push_back(entry);
	}
	if (bOpponent && bSelf)
	{
		SelectionEntry entry;
		entry.dwContext = 3;
		entry.strText = _T("Give yourself and the opponent another poison counter");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText = _T("Don't choose players");
		entries.push_back(entry);
	}
	m_PoisonSelection.AddSelectionRequest(entries, 1, 1, NULL, pController);
}

void CProliferateSupport::OnPoisonSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CGame* pGame = m_pCard->GetGame();
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int nChoice = (int)it->dwContext;
			if (nChoice == 1 || nChoice == 3)
				CPoisonModifier(pGame, 1).ApplyTo(pGame->GetNextPlayer(pSelectionPlayer));
			if (nChoice == 2 || nChoice == 3)
				CPoisonModifier(pGame, 1).ApplyTo(pSelectionPlayer);
		}
}

//____________________________________________________________________________
//
CBlastZoneCard::CBlastZoneCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Blast Zone"), nID)
	, m_cpCListener(VAR_NAME(m_cpCListener), CounterMovedEventSource::Listener::EventCallback(this, &CBlastZoneCard::OnCounterMoved))
	, m_nChargeCounters(0)
{
	// This land enters with a charge counter on it. (as the artifacts of M19)
	GetCounterContainer()->ScheduleCounter(CHARGE_COUNTER, 1, true, ZoneId::_AllZones, ZoneId::Battlefield, true);
	GetCounterMovedEventSource()->AddListener(m_cpCListener.GetPointer());

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	{
		// {X}{X}, {T}: Put X charge counters on this land. (doubled X as Floodwater Dam in Alliances)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

		cpAbility->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);
		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Put X charge counters on this land. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlastZoneCard::BeforeCounters));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}, {T}, Sacrifice this land: Destroy each nonland permanent with mana value equal to the number of charge
		// counters on this land.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("3")));

		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Destroy each nonland permanent with mana value equal to the charge counters. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlastZoneCard::BeforeDestroy));
		AddAbility(cpAbility.GetPointer());
	}
}

void CBlastZoneCard::OnCounterMoved(CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	// Remember the charge counters while it is on the battlefield (the last value is used after the sacrifice)
	if (pFromCard == this && GetZoneId() == ZoneId::Battlefield && (CString)name == CHARGE_COUNTER)
		m_nChargeCounters = n_value;
}

bool CBlastZoneCard::BeforeCounters(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0 && GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(CHARGE_COUNTER, nX).ApplyTo(this);
	return true;
}

bool CBlastZoneCard::BeforeDestroy(CAbilityAction* pAction)
{
	AndCardComparer comparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
		new ConvertedManaCostComparer<std::equal_to<int>>(m_nChargeCounters));
	DestroyAll(GetGame(), comparer);
	return true;
}

//____________________________________________________________________________
//
CEmergenceZoneCard::CEmergenceZoneCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Emergence Zone"), nID)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {1}, {T}, Sacrifice this land: You may cast spells this turn as though they had flash.
	// Partial: the cards in your hand get flash until end of turn (not the cards drawn later this turn).
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("You may cast spells this turn as though they had flash. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmergenceZoneCard::BeforeFlash));
	AddAbility(cpAbility.GetPointer());
}

bool CEmergenceZoneCard::BeforeFlash(CAbilityAction* pAction)
{
	// (as Leyline of Anticipation, until end of turn)
	CZone* pHand = pAction->GetController()->GetZoneById(ZoneId::Hand);
	CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Pflash, TRUE);
	for (int i = 0; i < pHand->GetSize(); ++i)
		if (!pHand->GetAt(i)->GetCardType().IsLand())
			pModifier.ApplyTo(pHand->GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CInterplanarBeaconCard::CInterplanarBeaconCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Interplanar Beacon"), nID)
{
	// Whenever you cast a planeswalker spell, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Planeswalker, false));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInterplanarBeaconCard::BeforeGainLife));
	AddAbility(cpAbility.GetPointer());

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {1}, {T}: Add two mana of different colors. Spend this mana only to cast planeswalker spells.
	// Not implemented: the engine has no mana with spending restrictions.
}

bool CInterplanarBeaconCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CKarnsBastionCard::CKarnsBastionCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Karn's Bastion"), nID)
	, m_Proliferate(this)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {4}, {T}: Proliferate.
	m_Proliferate.AddProliferateTrigger();

	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("4")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityName(_T("Proliferate."));
	cpAbility->SetAbilityText(_T("Proliferate."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKarnsBastionCard::BeforeProliferate));
	AddAbility(cpAbility.GetPointer());
}

bool CKarnsBastionCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CMobilizedDistrictCard::CMobilizedDistrictCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Mobilized District"), nID)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {4}: This land becomes a 3/3 Citizen creature with vigilance until end of turn. It's still a land. This ability
	// costs {1} less to activate for each legendary creature and planeswalker you control.
	// (as Hostile Desert; one ability for each reduction, as Ghalta)
	typedef BOOL (CMobilizedDistrictCard::*Condition)(BOOL);
	Condition conditions[] = { NULL, &CMobilizedDistrictCard::HasLegends1, &CMobilizedDistrictCard::HasLegends2,
		&CMobilizedDistrictCard::HasLegends3, &CMobilizedDistrictCard::HasLegends4 };
	for (int i = 0; i <= 4; ++i)
	{
		CString strCost;
		if (4 - i > 0)
			strCost.Format(_T("%d"), 4 - i);

		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				strCost,
				CITIZEN_A_TOKEN_NAME, CITIZEN_A_TOKEN_ID));

		if (conditions[i])
			AddPlayableIf(this, cpAbility.GetPointer(), conditions[i]);
		AddAbility(cpAbility.GetPointer());
	}
}

int CMobilizedDistrictCard::CountLegends() const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	int nCount = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if ((pCard->GetCardType().IsLegendary() && pCard->GetCardType().IsCreature()) || pCard->GetCardType().IsPlaneswalker())
			++nCount;
	}
	return nCount;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define ZOMBIE_ARMY_A_TOKEN_NAME		_T("Zombie Army (A)")
#define ZOMBIE_ARMY_A_TOKEN_ID			55128
#define WIZARD_A_TOKEN_NAME				_T("Wizard (A)")
#define WIZARD_A_TOKEN_ID				55129
#define WALL_C_TOKEN_NAME				_T("Wall (C)")
#define WALL_C_TOKEN_ID					55130
#define ASSASSIN_A_TOKEN_NAME			_T("Assassin (A)")
#define ASSASSIN_A_TOKEN_ID				55131
#define SPIRIT_T_TOKEN_NAME				_T("Spirit (T)")
#define SPIRIT_T_TOKEN_ID				55132
#define WOLF_K_TOKEN_NAME				_T("Wolf (K)")
#define WOLF_K_TOKEN_ID					55004
#define ZOMBIE_P_TOKEN_NAME				_T("Zombie (P)")
#define ZOMBIE_P_TOKEN_ID				55009
#define DRAGON_H_TOKEN_NAME				_T("Dragon (H)")
#define DRAGON_H_TOKEN_ID				55027
#define DEVIL_A_TOKEN_NAME				_T("Devil (A)")
#define DEVIL_A_TOKEN_ID				55079
#define SERVO_A_TOKEN_NAME				_T("Servo (A)")
#define SERVO_A_TOKEN_ID				55090
#define ANIMATED_GIDEON_BLACKBLADE_NAME	_T("Animated Gideon Blackblade")
#define ANIMATED_GIDEON_BLACKBLADE_ID	64132
#define ANIMATED_GIDEON_OATHSWORN_NAME	_T("Animated Gideon, the Oathsworn")
#define ANIMATED_GIDEON_OATHSWORN_ID	64133
#define DRAGON_AF_TOKEN_NAME			_T("Dragon (AF)")
#define DRAGON_AF_TOKEN_ID				64134
#define ELEMENTAL_AY_TOKEN_NAME			_T("Elemental (AY)")
#define ELEMENTAL_AY_TOKEN_ID			64135
#define ANIMATED_ARTIFACT_B_TOKEN_NAME	_T("Animated Artifact B")
#define ANIMATED_ARTIFACT_B_TOKEN_ID	64058
#define NISSA_WHO_SHAKES_EMBLEM_NAME	_T("Nissa, Who Shakes the World Emblem")
#define NISSA_WHO_SHAKES_EMBLEM_ID		61161

// Amass Zombies N (rule 701.47): if pPlayer controls no Army, create a 0/0 black Zombie Army token; put N +1/+1 counters
// on an Army they control and return it ("the Army you amassed"). In WAR the Army is always a Zombie (the token).
// Partial: with several Armies, the first one is used (the player doesn't choose).
static CCard* Amass(CCard* pSource, CPlayer* pPlayer, int nCount)
{
	CGame* pGame = pSource->GetGame();
	CreatureTypeComparer armyComparer(CREATURE_TYPE(Army), false);

	CCard* pArmy = NULL;
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize() && !pArmy; ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature() && armyComparer(pBattlefield->GetAt(i)))
			pArmy = pBattlefield->GetAt(i);

	if (!pArmy)
	{
		CCountedCardContainer tokens;
		CTokenCreationModifier(pGame, ZOMBIE_ARMY_A_TOKEN_NAME, ZOMBIE_ARMY_A_TOKEN_ID, 1, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pPlayer);
		if (tokens.GetSize() > 0)
			pArmy = tokens.GetAt(0);
	}

	if (pArmy && nCount > 0 && pArmy->GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(_T("+1/+1"), nCount).ApplyTo(pArmy);
	return pArmy;
}

// "Until your next turn": a card modifier applied now and removed at the beginning of pController's next untap step
// (as Gideon of the Trials in Amonkhet)
static void ApplyUntilYourNextTurn(CCard* pCard, CCardModifier* pModifier, CPlayer* pController)
{
	CScheduledCardModifier pScheduled = CScheduledCardModifier(pCard->GetGame(), pModifier,
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pController);
	pScheduled.ApplyTo(pCard);
}

// The creature keywords until your next turn (as Gideon of the Trials)
static void CreatureKeywordUntilYourNextTurn(CCard* pCard, CreatureKeyword keyword, CPlayer* pController)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier();
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	pKeywordModifier->GetModifier().SetToAdd(keyword);

	CScheduledCreatureModifier pModifier = CScheduledCreatureModifier(pCard->GetGame(),
		pKeywordModifier,
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pController);
	pModifier.ApplyTo(pCreature);
}

// Destroys pCard (if it is still on the battlefield)
static void DestroyPermanent(CCard* pCard, CPlayer* pByPlayer)
{
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pByPlayer).ApplyTo(pCard);
}

//____________________________________________________________________________
//
CDuringYourTurnSupport::CDuringYourTurnSupport(CCard* pCard)
	: m_pCard(pCard)
{
}

void CDuringYourTurnSupport::Add(CEnchantment* pEnchantment)
{
	m_Enchantments.push_back(pEnchantment);
}

void CDuringYourTurnSupport::AddTurnTriggers()
{
	{
		// At the beginning of each upkeep (without the stack): start or end the static abilities
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDuringYourTurnSupport::SetNodeContext));
		m_pCard->AddAbility(cpAbility.GetPointer());
	}
	{
		// When it enters during another player's turn, the static abilities end
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDuringYourTurnSupport::SetEnterContext));
		m_pCard->AddAbility(cpAbility.GetPointer());
	}
}

bool CDuringYourTurnSupport::SetNodeContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	Update();
	return false;
}

bool CDuringYourTurnSupport::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	Update();
	return false;
}

void CDuringYourTurnSupport::Update() const
{
	if (m_pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	BOOL bYourTurn = m_pCard->GetGame()->GetActivePlayer() == m_pCard->GetController();
	for (size_t i = 0; i < m_Enchantments.size(); ++i)
	{
		if (bYourTurn)
			m_Enchantments[i]->StartEnchantment();
		else
			m_Enchantments[i]->EndEnchantment();
	}
}

//____________________________________________________________________________
//
CAjaniTheGreatheartedCard::CAjaniTheGreatheartedCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani, the Greathearted"), nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Ajani, 5)
{
	// Creatures you control have vigilance.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0), CreatureKeyword::Vigilance));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// +1: You gain 3 life.
	AddLoyaltyAbility(this, +1, _T("+1: You gain 3 life. Activates"), &CAjaniTheGreatheartedCard::BeforeGainLife);

	// -2: Put a +1/+1 counter on each creature you control and a loyalty counter on each other planeswalker you control.
	AddLoyaltyAbility(this, -2, _T("-2: Put a +1/+1 counter on each creature you control and a loyalty counter on each other planeswalker you control. Activates"),
		&CAjaniTheGreatheartedCard::BeforeCounters);
}

bool CAjaniTheGreatheartedCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

bool CAjaniTheGreatheartedCard::BeforeCounters(CAbilityAction* pAction)
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer cards;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		cards.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		if (pCard->GetCardType().IsCreature())
			AddPlusCounter(pCard, 1);
		if (pCard->GetCardType().IsPlaneswalker() && pCard != this)
			CCardCounterModifier(LOYALTY_COUNTER, +1).ApplyTo(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
CAngrathCaptainOfChaosCard::CAngrathCaptainOfChaosCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Angrath, Captain of Chaos"), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Angrath, 5)
{
	// {2}{B/R}{B/R}
	AddHybridPermanentSpells(this, _T("2"), 2, BLACK_MANA_TEXT, RED_MANA_TEXT);

	// Creatures you control have menace.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0), CreatureKeyword::CantBeBlockedBy1));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// -2: Amass Zombies 2.
	AddLoyaltyAbility(this, -2, _T("-2: Amass Zombies 2. Activates"), &CAngrathCaptainOfChaosCard::BeforeAmass);
}

bool CAngrathCaptainOfChaosCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CArlinnVoiceOfThePackCard::CArlinnVoiceOfThePackCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Arlinn, Voice of the Pack"), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Arlinn, 7)
{
	// Each creature you control that's a Wolf or a Werewolf enters with an additional +1/+1 counter on it.
	// (the counter is put just after it enters, without the stack, as the Riot of Rhythm of the Wild)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Wolf), false), new CreatureTypeComparer(CREATURE_TYPE(Werewolf), false)));
	cpAbility->SetSkipStack(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CArlinnVoiceOfThePackCard::SetEnterContext));
	AddAbility(cpAbility.GetPointer());

	// -2: Create a 2/2 green Wolf creature token.
	AddLoyaltyAbility(this, -2, _T("-2: Create a 2/2 green Wolf creature token. Activates"), &CArlinnVoiceOfThePackCard::BeforeWolf);
}

bool CArlinnVoiceOfThePackCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (pCard->GetCardType().IsCreature() && pFromZone && pFromZone->GetZoneId() != ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

bool CArlinnVoiceOfThePackCard::BeforeWolf(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), WOLF_K_TOKEN_NAME, WOLF_K_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CAshiokDreamRenderCard::CAshiokDreamRenderCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ashiok, Dream Render"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Ashiok, 5)
{
	// {1}{U/B}{U/B}
	AddHybridPermanentSpells(this, _T("1"), 2, BLUE_MANA_TEXT, BLACK_MANA_TEXT);

	// Spells and abilities your opponents control can't cause their controller to search their library.
	// Not implemented: there are no replacement effects for searching a library (as Aven Mindcensor).

	// -1: Target player mills four cards. Then exile each opponent's graveyard.
	AddPlayerLoyaltyAbility(this, -1, &CAshiokDreamRenderCard::BeforeMill);
}

bool CAshiokDreamRenderCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 4);

	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CZone* pGraveyard = pOpponent->GetZoneById(ZoneId::Graveyard);
		CCountedCardContainer cards;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
			cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);
		CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pController);
		for (int i = 0; i < cards.GetSize(); ++i)
			pExile.ApplyTo(cards.GetAt(i));
	}
	return false;
}

//____________________________________________________________________________
//
CDavrielRogueShadowmageCard::CDavrielRogueShadowmageCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Davriel, Rogue Shadowmage"), nID,
		_T("2") BLACK_MANA_TEXT, PlaneswalkerType::Davriel, 3)
{
	// At the beginning of each opponent's upkeep, if that player has one or fewer cards in hand, Davriel deals 2 damage
	// to them.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDavrielRogueShadowmageCard::SetUpkeepContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDavrielRogueShadowmageCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());

	// -1: Target player discards a card.
	AddPlayerLoyaltyAbility(this, -1, &CDavrielRogueShadowmageCard::BeforeDiscard);
}

bool CDavrielRogueShadowmageCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	CPlayer* pActive = GetGame()->GetActivePlayer();
	if (pActive == GetController() || pActive->GetZoneById(ZoneId::Hand)->GetSize() > 1)
		return false;
	triggerContext.nValue1 = (DWORD)pActive;
	return true;
}

bool CDavrielRogueShadowmageCard::BeforeDamage(TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged >::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (pPlayer && pPlayer->GetZoneById(ZoneId::Hand)->GetSize() <= 1)
		DealDamageToPlayer(this, pPlayer, 2);
	return true;
}

bool CDavrielRogueShadowmageCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);
	return false;
}

//____________________________________________________________________________
//
CDomriAnarchOfBolasCard::CDomriAnarchOfBolasCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Domri, Anarch of Bolas"), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Domri, 3)
{
	// Creatures you control get +1/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+1), Life(+0)));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// +1: Add {R} or {G}. Creature spells you cast this turn can't be countered.
	AddLoyaltyAbility(this, +1, _T("+1: Add {R}. Creature spells you cast this turn can't be countered. Activates"), &CDomriAnarchOfBolasCard::BeforeRedMana);
	AddLoyaltyAbility(this, +1, _T("+1: Add {G}. Creature spells you cast this turn can't be countered. Activates"), &CDomriAnarchOfBolasCard::BeforeGreenMana);

	{
		// -2: Target creature you control fights target creature you don't control. (as Ral Zarek in Dragon's Maze)
		counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpFight(
			::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, false,
				new AnyCreatureComparer, false, _T(""), TRUE));

		cpFight->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpFight->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpFight->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpFight->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpFight->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpFight->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDomriAnarchOfBolasCard::BeforeFight));
		AddAbility(cpFight.GetPointer());
	}
}

void CDomriAnarchOfBolasCard::CreatureSpellsCantBeCountered(CPlayer* pPlayer)
{
	// (as Prowling Serpopard, until end of turn)
	int nFilter = reinterpret_cast<int>(CCardFilter::GetFilter(_T("creatures")));
	CPlayerEffectModifier(PlayerEffectType::SpellsCantBeCountered, nFilter).ApplyTo(pPlayer);
	CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::SpellsCantBeCountered, nFilter),
		TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater);
	pRemove.ApplyTo(pPlayer);
}

bool CDomriAnarchOfBolasCard::BeforeRedMana(CAbilityAction* pAction)
{
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(RED_MANA_TEXT)).ApplyTo(pAction->GetController());
	CreatureSpellsCantBeCountered(pAction->GetController());
	return true;
}

bool CDomriAnarchOfBolasCard::BeforeGreenMana(CAbilityAction* pAction)
{
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(GREEN_MANA_TEXT)).ApplyTo(pAction->GetController());
	CreatureSpellsCantBeCountered(pAction->GetController());
	return true;
}

bool CDomriAnarchOfBolasCard::BeforeFight(CAbilityAction* pAction)
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
CDovinHandOfControlCard::CDovinHandOfControlCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Dovin, Hand of Control"), nID,
		_T("2") WHITE_MANA_TEXT, PlaneswalkerType::Dovin, 5)
{
	// {2}{W/U}
	AddHybridPermanentSpells(this, _T("2"), 1, WHITE_MANA_TEXT, BLUE_MANA_TEXT);

	// Artifact, instant, and sorcery spells your opponents cast cost {1} more to cast. (as Thalia)
	counted_ptr<CConsExtraManaEnchantment> cpAbility(
		::CreateObject<CConsExtraManaEnchantment>(this,
			new CardTypeComparer(CardType::Artifact | CardType::Instant | CardType::Sorcery, false),
			_T("1")));
	cpAbility->SetAffectOpponentCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// -1: Until your next turn, prevent all damage that would be dealt to and dealt by target permanent an opponent
	// controls.
	// Partial: only creatures; the damage they deal and the combat damage dealt to them (as Gideon of the Trials).
	counted_ptr<CActivatedAbility<CTargetSpell>> cpPrevent(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpPrevent->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
	cpPrevent->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpPrevent->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpPrevent->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDovinHandOfControlCard::BeforePrevent));
	AddAbility(cpPrevent.GetPointer());
}

bool CDovinHandOfControlCard::BeforePrevent(CAbilityAction* pAction)
{
	CreatureKeywordUntilYourNextTurn(pAction->GetAssociatedCard(),
		CreatureKeyword::DealNoCombatDamage | CreatureKeyword::DealNoNoncombatDamage | CreatureKeyword::PreventAllCombatDamage,
		pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CGideonBlackbladeCard::CGideonBlackbladeCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Gideon Blackblade"), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Gideon, 4)
	, m_KeywordSelection(pGame, CSelectionSupport::SelectionCallback(this, &CGideonBlackbladeCard::OnKeywordSelected))
{
	// During your turn, Gideon Blackblade is a 4/4 Human Soldier creature with indestructible that's still a
	// planeswalker. Prevent all damage that would be dealt to Gideon Blackblade during your turn.
	// (an IsAlsoA creature from the beginning of your upkeep, or when it enters during your turn, until end of turn,
	// with the damage prevention of the Gideons of Amonkhet)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGideonBlackbladeCard::SetUpkeepContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGideonBlackbladeCard::SetEnterContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// +1: Up to one other target creature you control gains your choice of vigilance, lifelink, or indestructible
		// until end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGideonBlackbladeCard::BeforeKeyword));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -6: Exile target nonland permanent.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -6);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

void CGideonBlackbladeCard::Animate() const
{
	CGideonBlackbladeCard* pThis = const_cast<CGideonBlackbladeCard*>(this);
	if (GetZoneId() != ZoneId::Battlefield || pThis->GetIsAlsoA())
		return;

	CPlayer* pController = GetController();
	CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(ANIMATED_GIDEON_BLACKBLADE_NAME, ANIMATED_GIDEON_BLACKBLADE_ID, pController);
	CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
		TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater);
	pAnimate->ApplyTo(pThis);
	pRemove.ApplyTo(pThis);

	CPlayerEffectModifier(PlayerEffectType::PreventDamagetoGideon2).ApplyTo(pController);
	CScheduledPlayerModifier pRemoveEffect = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::PreventDamagetoGideon2),
		TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater);
	pRemoveEffect.ApplyTo(pController);
}

bool CGideonBlackbladeCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	Animate();
	return false;
}

bool CGideonBlackbladeCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (GetGame()->GetActivePlayer() == GetController())
		Animate();
	return false;
}

bool CGideonBlackbladeCard::BeforeKeyword(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() == 0 || cards.GetAt(0)->GetZoneId() != ZoneId::Battlefield || cards.GetAt(0) == this)
		return false;

	CCard* pCard = cards.GetAt(0);
	LPCTSTR texts[] = { _T("vigilance"), _T("lifelink"), _T("indestructible") };
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 3; ++i)
	{
		SelectionEntry entry;
		entry.dwContext = i;
		entry.strText.Format(_T("%s gains %s until end of turn"), pCard->GetCardName(TRUE), texts[i]);
		entries.push_back(entry);
	}
	m_KeywordSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController(), (DWORD)pCard);
	return false;
}

void CGideonBlackbladeCard::OnKeywordSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if ((int)it->dwContext == 0)
				PumpCreature(pCard, 0, 0, CreatureKeyword::Vigilance);
			else if ((int)it->dwContext == 1)
				GainCardKeyword(pCard, CardKeyword::Lifelink);
			else
				GainCardKeyword(pCard, CardKeyword::Indestructible);
		}
}

//____________________________________________________________________________
//
CGideonTheOathswornCard::CGideonTheOathswornCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Gideon, the Oathsworn"), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Gideon, 4)
{
	{
		// Whenever you attack with two or more non-Gideon creatures, put a +1/+1 counter on each of those creatures.
		// (a trigger for each attacking non-Gideon creature, that checks the number of attackers on resolution)
		counted_ptr<AttackTriggeredAbility> cpAbility(::CreateObject<AttackTriggeredAbility>(this));

		cpAbility->SetOptionalType(AttackTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(AttackTriggeredAbility::ContextFunction(this, &CGideonTheOathswornCard::SetAttackContext));
		cpAbility->SetBeforeResolveSelectionCallback(AttackTriggeredAbility::BeforeResolveSelectionCallback(this, &CGideonTheOathswornCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// +2: Until end of turn, Gideon becomes a 5/5 white Soldier creature that's still a planeswalker. Prevent all
		// damage that would be dealt to him this turn. (as the Gideons of Amonkhet)
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T(""),
				ANIMATED_GIDEON_OATHSWORN_NAME, ANIMATED_GIDEON_OATHSWORN_ID));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->SetAbilityText(_T("+2: Until end of turn, Gideon becomes a 5/5 white Soldier creature. Activates"));

		CPlayerEffectModifier* pEffect = new CPlayerEffectModifier(PlayerEffectType::PreventDamagetoGideon2);
		CScheduledPlayerModifier* pRemove = new CScheduledPlayerModifier(
			GetGame(), pEffect, TurnNumberDelta(-1), NodeId::EndStep, CScheduledPlayerModifier::Operation::RemoveFromLater);
		pEffect->LinkPlayerModifier(pRemove);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(pEffect);
		AddAbility(cpAbility.GetPointer());
	}

	// -9: Exile Gideon and each creature your opponents control.
	AddLoyaltyAbility(this, -9, _T("-9: Exile Gideon and each creature your opponents control. Activates"),
		&CGideonTheOathswornCard::BeforeUltimate);
}

bool CGideonTheOathswornCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	if (!pCreature || CString(pCreature->GetCardName(FALSE)).Find(_T("Gideon")) >= 0)
		return false;
	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CGideonTheOathswornCard::BeforeCounter(AttackTriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCreature = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	// Two or more non-Gideon attacking creatures
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	AttackingCreatureComparer attacking;
	int nAttackers = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (attacking(creatures.GetAt(i)) && CString(creatures.GetAt(i)->GetCardName(FALSE)).Find(_T("Gideon")) < 0)
			++nAttackers;

	if (nAttackers >= 2)
		AddPlusCounter(pCreature, 1);
	return true;
}

bool CGideonTheOathswornCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController);
	if (GetZoneId() == ZoneId::Battlefield)
		pExile.ApplyTo(this);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pExile.ApplyTo(creatures.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CHuatliTheSunsHeartCard::CHuatliTheSunsHeartCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Huatli, the Sun's Heart"), nID,
		_T("2") GREEN_MANA_TEXT, PlaneswalkerType::Huatli, 7)
{
	// {2}{G/W}
	AddHybridPermanentSpells(this, _T("2"), 1, GREEN_MANA_TEXT, WHITE_MANA_TEXT);

	// Each creature you control assigns combat damage equal to its toughness rather than its power. (as Assault Formation)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::ToughnessCombatDamage));
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());

	// -3: You gain life equal to the greatest toughness among creatures you control.
	AddLoyaltyAbility(this, -3, _T("-3: You gain life equal to the greatest toughness among creatures you control. Activates"),
		&CHuatliTheSunsHeartCard::BeforeGainLife);
}

bool CHuatliTheSunsHeartCard::BeforeGainLife(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	int nMax = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && GET_INTEGER(pCreature->GetToughness()) > nMax)
			nMax = GET_INTEGER(pCreature->GetToughness());
	}
	if (nMax > 0)
		GainLife(this, pAction->GetController(), nMax);
	return true;
}

//____________________________________________________________________________
//
CJaceArcaneStrategistCard::CJaceArcaneStrategistCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jace, Arcane Strategist"), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Jace, 4)
	, m_nDrawTurn(-1)
	, m_nDraws(0)
{
	{
		// Whenever you draw your second card each turn, put a +1/+1 counter on target creature you control.
		// (the draws are counted while Jace is on the battlefield)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CJaceArcaneStrategistCard::SetDrawContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJaceArcaneStrategistCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// +1: Draw a card.
	AddLoyaltyAbility(this, +1, _T("+1: Draw a card. Activates"), &CJaceArcaneStrategistCard::BeforeDraw);

	// -7: Creatures you control can't be blocked this turn.
	AddLoyaltyAbility(this, -7, _T("-7: Creatures you control can't be blocked this turn. Activates"),
		&CJaceArcaneStrategistCard::BeforeUnblockable);
}

bool CJaceArcaneStrategistCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	int nTurn = GetGame()->GetGameTurnNumber();
	if (nTurn != m_nDrawTurn)
	{
		m_nDrawTurn = nTurn;
		m_nDraws = 0;
	}
	return ++m_nDraws == 2;
}

bool CJaceArcaneStrategistCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(GetTargetCreature(pAction), 1);
	return false;
}

bool CJaceArcaneStrategistCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CJaceArcaneStrategistCard::BeforeUnblockable(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature)
			pCreature->GetCreatureKeyword()->AddUnblockable(TRUE);
	}
	return true;
}

//____________________________________________________________________________
//
CJaceWielderOfMysteriesCard::CJaceWielderOfMysteriesCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jace, Wielder of Mysteries"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Jace, 4)
{
	// If you would draw a card while your library has no cards in it, you win the game instead. (as Laboratory Maniac)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::WinInsteadTopDeck));
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());

	// +1: Target player mills two cards. Draw a card.
	AddPlayerLoyaltyAbility(this, +1, &CJaceWielderOfMysteriesCard::BeforeMill);

	// -8: Draw seven cards. Then if your library has no cards in it, you win the game.
	AddLoyaltyAbility(this, -8, _T("-8: Draw seven cards. Then if your library has no cards in it, you win the game. Activates"),
		&CJaceWielderOfMysteriesCard::BeforeUltimate);
}

bool CJaceWielderOfMysteriesCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 2);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

bool CJaceWielderOfMysteriesCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 7);
	if (pController->GetZoneById(ZoneId::Library)->GetSize() == 0)
		for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
			if (GetGame()->GetPlayer(ip) != pController)
				GetGame()->GetPlayer(ip)->SetLostByOtherReasons();
	return true;
}

//____________________________________________________________________________
//
CJayaVeneratedFiremageCard::CJayaVeneratedFiremageCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jaya, Venerated Firemage"), nID,
		_T("4") RED_MANA_TEXT, PlaneswalkerType::Jaya, 5)
{
	// If another red source you control would deal damage to a permanent or player, it deals that much damage plus 1 to
	// that permanent or player instead.
	// Not implemented: there are no damage replacement effects.

	// -2: Jaya deals 2 damage to any target. (it can't target planeswalkers)
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CJiangYangguWildcrafterCard::CJiangYangguWildcrafterCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jiang Yanggu, Wildcrafter"), nID,
		_T("2") GREEN_MANA_TEXT, PlaneswalkerType::Yanggu, 3)
{
	// Each creature you control with a +1/+1 counter on it has "{T}: Add one mana of any color."
	// Not implemented: the engine can't give mana abilities to other cards.

	// -1: Put a +1/+1 counter on target creature.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CKarnTheGreatCreatorCard::CKarnTheGreatCreatorCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Karn, the Great Creator"), nID,
		_T("4"), PlaneswalkerType::Karn, 5)
	, m_ArtifactFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	// Activated abilities of artifacts your opponents control can't be activated. (as Linvala, Keeper of Silence)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::CantPlayActivatedAbilities,
			(int)CCardFilter::GetFilter(_T("artifacts"))));
	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());

	{
		// +1: Until your next turn, up to one target noncreature artifact becomes an artifact creature with power and
		// toughness each equal to its mana value. (as Karn, Silver Golem)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAnimate(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AndCardComparer(new CardTypeComparer(CardType::Artifact, false), new NegateCardComparer(new AnyCreatureComparer)),
				FALSE));

		cpAnimate->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAnimate->GetTargeting()->SetSubjectCount(0, 1);
		cpAnimate->GetTargeting()->SetDefaultCharacteristic(Characteristic::Neutral);
		cpAnimate->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKarnTheGreatCreatorCard::BeforeAnimate));
		AddAbility(cpAnimate.GetPointer());
	}

	// -2: You may reveal an artifact card you own from outside the game or choose a face-up artifact card you own in exile.
	// Put that card into your hand.
	// Partial: only the artifact cards you own in exile (there is no outside the game).
	AddLoyaltyAbility(this, -2, _T("-2: Put an artifact card you own in exile into your hand. Activates"),
		&CKarnTheGreatCreatorCard::BeforeReturn);
}

bool CKarnTheGreatCreatorCard::BeforeAnimate(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() == 0)
		return false;

	CCard* pCard = cards.GetAt(0);
	if (pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetIsAlsoA())
		return false;

	int nManaValue = (int)pCard->GetConvertedManaCost();
	CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(ANIMATED_ARTIFACT_B_TOKEN_NAME, ANIMATED_ARTIFACT_B_TOKEN_ID, pAction->GetController());
	CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCardModifier::Operation::RemoveFromLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pAction->GetController());
	pAnimate->ApplyTo(pCard);
	pRemove.ApplyTo(pCard);

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard->GetIsAlsoA());
	if (pCreature)
	{
		pCreature->SetPrintedPower(Power(nManaValue));
		pCreature->SetPrintedToughness(Life(nManaValue));
	}
	return false;
}

bool CKarnTheGreatCreatorCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Exile, 0, 1, &m_ArtifactFilter, ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CKasminaEnigmaticMentorCard::CKasminaEnigmaticMentorCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Kasmina, Enigmatic Mentor"), nID,
		_T("3") BLUE_MANA_TEXT, PlaneswalkerType::Kasmina, 5)
{
	// Spells your opponents cast that target a creature or planeswalker you control cost {2} more to cast.
	// Not implemented: the engine can't increase the cost of a spell depending on its targets.

	// -2: Create a 2/2 blue Wizard creature token. Draw a card, then discard a card.
	AddLoyaltyAbility(this, -2, _T("-2: Create a 2/2 blue Wizard creature token. Draw a card, then discard a card. Activates"),
		&CKasminaEnigmaticMentorCard::BeforeWizard);
}

bool CKasminaEnigmaticMentorCard::BeforeWizard(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), WIZARD_A_TOKEN_NAME, WIZARD_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CKayaBaneOfTheDeadCard::CKayaBaneOfTheDeadCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Kaya, Bane of the Dead"), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Kaya, 7)
{
	// {3}{W/B}{W/B}{W/B}
	AddHybridPermanentSpells(this, _T("3"), 3, WHITE_MANA_TEXT, BLACK_MANA_TEXT);

	// Your opponents and permanents your opponents control with hexproof can be the targets of spells and abilities you
	// control as though they didn't have hexproof. (as Detection Tower)
	// Partial: only the creatures (not the opponents nor other permanents).
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::IgnoreHexproofOnCreatures));
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());

	// -3: Exile target creature.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpExile(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpExile->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
	cpExile->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpExile.GetPointer());
}

//____________________________________________________________________________
//
CKioraBehemothBeckonerCard::CKioraBehemothBeckonerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Kiora, Behemoth Beckoner"), nID,
		_T("2") GREEN_MANA_TEXT, PlaneswalkerType::Kiora, 7)
{
	// {2}{G/U}
	AddHybridPermanentSpells(this, _T("2"), 1, GREEN_MANA_TEXT, BLUE_MANA_TEXT);

	{
		// Whenever a creature you control with power 4 or greater enters, draw a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKioraBehemothBeckonerCard::SetEnterContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKioraBehemothBeckonerCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -1: Untap target permanent.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new TrueCardComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKioraBehemothBeckonerCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	return pCreature && pCreature->GetPower() >= Power(4);
}

bool CKioraBehemothBeckonerCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CLilianaDreadhordeGeneralCard::CLilianaDreadhordeGeneralCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Liliana, Dreadhorde General"), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Liliana, 6)
{
	// Whenever a creature you control dies, draw a card.
	AddAnotherCreatureDiesTrigger<CLilianaDreadhordeGeneralCard>(this, NULL, &CLilianaDreadhordeGeneralCard::BeforeDraw);

	// +1: Create a 2/2 black Zombie creature token.
	AddLoyaltyAbility(this, +1, _T("+1: Create a 2/2 black Zombie creature token. Activates"), &CLilianaDreadhordeGeneralCard::BeforeZombie);

	// -4: Each player sacrifices two creatures of their choice.
	AddLoyaltyAbility(this, -4, _T("-4: Each player sacrifices two creatures. Activates"), &CLilianaDreadhordeGeneralCard::BeforeSacrifice);

	// -9: Each opponent chooses a permanent they control of each permanent type and sacrifices the rest.
	// Partial: the permanent with the greatest mana value of each type is kept (the opponent doesn't choose).
	AddLoyaltyAbility(this, -9, _T("-9: Each opponent keeps a permanent of each permanent type and sacrifices the rest. Activates"),
		&CLilianaDreadhordeGeneralCard::BeforeUltimate);
}

bool CLilianaDreadhordeGeneralCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CLilianaDreadhordeGeneralCard::BeforeZombie(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CLilianaDreadhordeGeneralCard::BeforeSacrifice(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		ChooseAndMove(GetGame(), GetGame()->GetPlayer(ip), ZoneId::Battlefield, 2, 2, CCardFilter::GetFilter(_T("creatures")),
			ZoneId::Graveyard, MoveType::Sacrifice);
	return true;
}

bool CLilianaDreadhordeGeneralCard::BeforeUltimate(CAbilityAction* pAction)
{
	CardType types[] = { CardType::Artifact, CardType::Creature, CardType::_Enchantment, CardType::_Land, CardType::Planeswalker };
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		CCountedCardContainer permanents, kept;
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			permanents.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

		for (int t = 0; t < 5; ++t)
		{
			CardTypeComparer comparer(types[t], false);
			CCard* pBest = NULL;
			for (int i = 0; i < permanents.GetSize(); ++i)
			{
				CCard* pCard = permanents.GetAt(i);
				if (comparer(pCard) && (!pBest || pCard->GetConvertedManaCost() > pBest->GetConvertedManaCost()))
					pBest = pCard;
			}
			if (pBest && !kept.HasCard(pBest))
				kept.AddCard(pBest, CardPlacement::Top);
		}

		CMoveCardModifier pSacrifice = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pOpponent);
		for (int i = 0; i < permanents.GetSize(); ++i)
			if (!kept.HasCard(permanents.GetAt(i)) && permanents.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				pSacrifice.ApplyTo(permanents.GetAt(i));
	}
	return true;
}

//____________________________________________________________________________
//
CNahiriStormOfStoneCard::CNahiriStormOfStoneCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nahiri, Storm of Stone"), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Nahiri, 6)
	, m_DuringYourTurn(this)
{
	// {2}{R/W}{R/W}
	AddHybridPermanentSpells(this, _T("2"), 2, RED_MANA_TEXT, WHITE_MANA_TEXT);

	// During your turn, creatures you control have first strike and equip abilities you activate cost {1} less to activate.
	// Partial: the equip abilities don't cost less.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0), CreatureKeyword::FirstStrike));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
	m_DuringYourTurn.Add(cpAbility.GetPointer());
	m_DuringYourTurn.AddTurnTriggers();

	// -X: Nahiri deals X damage to target tapped creature. (as Huatli, Warrior Poet)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpDamage(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AndCardComparer(new AnyCreatureComparer, new TappedComparer), FALSE));

	cpDamage->GetCost().AddCounterCost(GetLoyaltyCounter(), SpecialNumber::AnyNegative);
	cpDamage->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpDamage->SetAbilityText(_T("-X: Nahiri deals X damage to target tapped creature."));
	cpDamage->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNahiriStormOfStoneCard::BeforeDamage));
	AddAbility(cpDamage.GetPointer());
}

bool CNahiriStormOfStoneCard::BeforeDamage(CAbilityAction* pAction)
{
	int nX = -pAction->GetCostConfigEntry().GetExtraValue();
	CCard* pCard = GetTargetCreature(pAction);
	if (nX > 0 && pCard)
		DealDamageToCreature(this, pCard, nX);
	return false;
}

//____________________________________________________________________________
//
CNarsetParterOfVeilsCard::CNarsetParterOfVeilsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Narset, Parter of Veils"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Narset, 5)
	, m_NoncreatureNonlandFilter(_T("a noncreature, nonland card"), _T("noncreature, nonland cards"),
		new AndCardComparer(new NegateCardComparer(new AnyCreatureComparer),
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false))))
{
	// Each opponent can't draw more than one card each turn. (as Spirit of the Labyrinth)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this, PlayerEffectType::DrawCardLimit, 1));
	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());

	// -2: Look at the top four cards of your library. You may reveal a noncreature, nonland card from among them and put
	// it into your hand. Put the rest on the bottom of your library in a random order.
	AddLoyaltyAbility(this, -2, _T("-2: Look at the top four cards, put a noncreature, nonland card into your hand. Activates"),
		&CNarsetParterOfVeilsCard::BeforeLook);
}

bool CNarsetParterOfVeilsCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 4, 0, 1, &m_NoncreatureNonlandFilter);
	return true;
}

//____________________________________________________________________________
//
CNicolBolasDragonGodCard::CNicolBolasDragonGodCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nicol Bolas, Dragon-God"), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Bolas, 4)
	, m_ExileSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNicolBolasDragonGodCard::OnExileSelected))
{
	// Nicol Bolas has all loyalty abilities of all other planeswalkers on the battlefield.
	// Not implemented: the engine can't give loyalty abilities to other cards.

	// +1: You draw a card. Each opponent exiles a card from their hand or a permanent they control.
	AddLoyaltyAbility(this, +1, _T("+1: You draw a card. Each opponent exiles a card from their hand or a permanent they control. Activates"),
		&CNicolBolasDragonGodCard::BeforeDraw);

	{
		// -3: Destroy target creature or planeswalker.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -8: Each opponent who doesn't control a legendary creature or planeswalker loses the game.
	AddLoyaltyAbility(this, -8, _T("-8: Each opponent who doesn't control a legendary creature or planeswalker loses the game. Activates"),
		&CNicolBolasDragonGodCard::BeforeUltimate);
}

bool CNicolBolasDragonGodCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		std::vector<SelectionEntry> entries;
		ZoneId zones[] = { ZoneId::Hand, ZoneId::Battlefield };
		for (int z = 0; z < 2; ++z)
		{
			CZone* pZone = pOpponent->GetZoneById(zones[z]);
			for (int i = 0; i < pZone->GetSize(); ++i)
			{
				CCard* pCard = pZone->GetAt(i);
				SelectionEntry entry;
				entry.dwContext = (DWORD)pCard;
				entry.cpAssociatedCard = pCard;
				entry.strText.Format(z == 0 ? _T("Exile %s from your hand") : _T("Exile %s"), pCard->GetCardName(TRUE));
				entries.push_back(entry);
			}
		}
		if (!entries.empty())
			m_ExileSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);
	}
	return true;
}

void CNicolBolasDragonGodCard::OnExileSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		ZoneId zone = pCard->GetZoneId();
		if (zone == ZoneId::Hand || zone == ZoneId::Battlefield)
			CMoveCardModifier(zone, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
	}
}

bool CNicolBolasDragonGodCard::BeforeUltimate(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		BOOL bSafe = FALSE;
		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize() && !bSafe; ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsPlaneswalker() || (pCard->GetCardType().IsLegendary() && pCard->GetCardType().IsCreature()))
				bSafe = TRUE;
		}
		if (!bSafe)
			pOpponent->SetLostByOtherReasons();
	}
	return true;
}

//____________________________________________________________________________
//
CNissaWhoShakesTheWorldCard::CNissaWhoShakesTheWorldCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nissa, Who Shakes the World"), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Nissa, 5)
{
	{
		// Whenever you tap a Forest for mana, add an additional {G}. (as Mana Flare in Unlimited and Nikya of the Old Ways)
		counted_ptr<ManaTriggeredAbility> cpAbility(::CreateObject<ManaTriggeredAbility>(this));

		cpAbility->SetOptionalType(ManaTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("Forests")));
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(ManaTriggeredAbility::ContextFunction(this, &CNissaWhoShakesTheWorldCard::SetManaContext));

		m_pManaAbility = cpAbility.GetPointer();
		AddAbility(m_pManaAbility);
	}
	{
		// +1: Put three +1/+1 counters on up to one target noncreature land you control. Untap it. It becomes a 0/0
		// Elemental creature with vigilance and haste that's still a land. (as Waker of the Wilds in Ixalan)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AndCardComparer(new CardTypeComparer(CardType::_Land, false), new NegateCardComparer(new AnyCreatureComparer)),
				FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaWhoShakesTheWorldCard::BeforeAnimate));
		AddAbility(cpAbility.GetPointer());
	}

	// -8: You get an emblem with "Lands you control have indestructible." Search your library for any number of Forest
	// cards, put them onto the battlefield tapped, then shuffle.
	AddLoyaltyAbility(this, -8, _T("-8: You get an emblem with \"Lands you control have indestructible.\" Search for any number of Forest cards. Activates"),
		&CNissaWhoShakesTheWorldCard::BeforeUltimate);
}

bool CNissaWhoShakesTheWorldCard::SetManaContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
	const CManaProductionAbilityAction* pManaAction) const
{
	m_pManaAbility->SetProduceColorless(FALSE);
	m_pManaAbility->SetProduceRed(FALSE);
	m_pManaAbility->SetProduceGreen(TRUE);
	m_pManaAbility->SetProduceBlue(FALSE);
	m_pManaAbility->SetProduceBlack(FALSE);
	m_pManaAbility->SetProduceWhite(FALSE);
	return true;
}

bool CNissaWhoShakesTheWorldCard::BeforeAnimate(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() == 0 || cards.GetAt(0)->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCard* pLand = cards.GetAt(0);
	AddPlusCounter(pLand, 3);
	CCardOrientationModifier(FALSE).ApplyTo(pLand);
	if (!pLand->GetIsAlsoA())
		CCardIsAlsoAModifier(ELEMENTAL_AY_TOKEN_NAME, ELEMENTAL_AY_TOKEN_ID, pAction->GetController()).ApplyTo(pLand);
	return false;
}

bool CNissaWhoShakesTheWorldCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CTokenCreationModifier(GetGame(), NISSA_WHO_SHAKES_EMBLEM_NAME, NISSA_WHO_SHAKES_EMBLEM_ID, 1, FALSE, ZoneId::_Effects).ApplyTo(pController);
	SearchToBattlefield(GetGame(), pController, 99, CCardFilter::GetFilter(_T("Forests")), TRUE);
	return true;
}

//____________________________________________________________________________
//
CObNixilisTheHateTwistedCard::CObNixilisTheHateTwistedCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ob Nixilis, the Hate-Twisted"), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Nixilis, 5)
{
	{
		// Whenever an opponent draws a card, Ob Nixilis deals 1 damage to that player.
		counted_ptr<DrawTriggeredAbility> cpAbility(::CreateObject<DrawTriggeredAbility>(this));

		cpAbility->SetOptionalType(DrawTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetContextFunction(DrawTriggeredAbility::ContextFunction(this, &CObNixilisTheHateTwistedCard::SetDrawContext));
		cpAbility->SetBeforeResolveSelectionCallback(DrawTriggeredAbility::BeforeResolveSelectionCallback(this, &CObNixilisTheHateTwistedCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Destroy target creature. Its controller draws two cards.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CObNixilisTheHateTwistedCard::BeforeDestroy));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CObNixilisTheHateTwistedCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	triggerContext.nValue1 = (DWORD)pPlayer;
	return pPlayer != NULL;
}

bool CObNixilisTheHateTwistedCard::BeforeDamage(DrawTriggeredAbility::TriggeredActionType* pAction)
{
	DealDamageToPlayer(this, (CPlayer*)pAction->GetTriggerContext().nValue1, 1);
	return true;
}

bool CObNixilisTheHateTwistedCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pController = pCard->GetController();
	DestroyPermanent(pCard, pAction->GetController());
	DrawCards(GetGame(), pController, 2);
	return false;
}

//____________________________________________________________________________
//
CRalStormConduitCard::CRalStormConduitCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ral, Storm Conduit"), nID,
		_T("2") BLUE_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Ral, 4)
{
	{
		// Whenever you cast or copy an instant or sorcery spell, Ral deals 1 damage to target opponent or planeswalker.
		// Partial: only when you cast it (not the copies), and it can't target planeswalkers.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRalStormConduitCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// +2: Scry 1.
	AddLoyaltyAbility(this, +2, _T("+2: Scry 1. Activates"), &CRalStormConduitCard::BeforeScry);

	// -2: When you next cast an instant or sorcery spell this turn, copy that spell. You may choose new targets for the
	// copy.
	// Not implemented: there is no delayed copy of a spell.
}

bool CRalStormConduitCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToPlayer(this, pAction->GetAssociatedPlayer(), 1);
	return false;
}

bool CRalStormConduitCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSaheeliSublimeArtificerCard::CSaheeliSublimeArtificerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Saheeli, Sublime Artificer"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Saheeli, 5)
{
	// {1}{U/R}{U/R}
	AddHybridPermanentSpells(this, _T("1"), 2, BLUE_MANA_TEXT, RED_MANA_TEXT);

	// Whenever you cast a noncreature spell, create a 1/1 colorless Servo artifact creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaheeliSublimeArtificerCard::BeforeServo));
	AddAbility(cpAbility.GetPointer());

	// -2: Target artifact you control becomes a copy of another target artifact or creature you control until end of
	// turn, except it's an artifact in addition to its other types.
	// Not implemented: a permanent can't become a copy of another one.
}

bool CSaheeliSublimeArtificerCard::BeforeServo(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), SERVO_A_TOKEN_NAME, SERVO_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSamutTyrantSmasherCard::CSamutTyrantSmasherCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Samut, Tyrant Smasher"), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Samut, 5)
{
	// {2}{R/G}{R/G}
	AddHybridPermanentSpells(this, _T("2"), 2, RED_MANA_TEXT, GREEN_MANA_TEXT);

	// Creatures you control have haste.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0), CreatureKeyword::Haste));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// -1: Target creature gets +2/+1 and gains haste until end of turn. Scry 1.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpPump(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpPump->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
	cpPump->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpPump->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSamutTyrantSmasherCard::BeforePump));
	AddAbility(cpPump.GetPointer());
}

bool CSamutTyrantSmasherCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +2, +1, CreatureKeyword::Haste);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CSarkhanTheMasterlessCard::CSarkhanTheMasterlessCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sarkhan the Masterless"), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Sarkhan, 5)
{
	{
		// Whenever a creature attacks you or a planeswalker you control, each Dragon you control deals 1 damage to that
		// creature.
		counted_ptr<AttackTriggeredAbility> cpAbility(::CreateObject<AttackTriggeredAbility>(this));

		cpAbility->SetOptionalType(AttackTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetContextFunction(AttackTriggeredAbility::ContextFunction(this, &CSarkhanTheMasterlessCard::SetAttackContext));
		cpAbility->SetBeforeResolveSelectionCallback(AttackTriggeredAbility::BeforeResolveSelectionCallback(this, &CSarkhanTheMasterlessCard::BeforeDragons));
		AddAbility(cpAbility.GetPointer());
	}

	// +1: Until end of turn, each planeswalker you control becomes a 4/4 red Dragon creature and gains flying.
	AddLoyaltyAbility(this, +1, _T("+1: Until end of turn, each planeswalker you control becomes a 4/4 red Dragon creature with flying. Activates"),
		&CSarkhanTheMasterlessCard::BeforeAnimate);

	// -3: Create a 4/4 red Dragon creature token with flying.
	AddLoyaltyAbility(this, -3, _T("-3: Create a 4/4 red Dragon creature token with flying. Activates"),
		&CSarkhanTheMasterlessCard::BeforeDragon);
}

bool CSarkhanTheMasterlessCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	BOOL bYou = attacked.pPlayer == GetController() ||
		(attacked.cpPlaneswalker.GetPointer() && attacked.cpPlaneswalker->GetController() == GetController());
	if (!pCreature || !bYou)
		return false;
	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CSarkhanTheMasterlessCard::BeforeDragons(AttackTriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCreature = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCountedCardContainer dragons;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Dragon), dragons);
	for (int i = 0; i < dragons.GetSize() && pCreature->GetZoneId() == ZoneId::Battlefield; ++i)
		DealDamageToCreature(dragons.GetAt(i), pCreature, 1);
	return true;
}

bool CSarkhanTheMasterlessCard::BeforeAnimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer planeswalkers;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsPlaneswalker() && !pBattlefield->GetAt(i)->GetIsAlsoA())
			planeswalkers.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	// (as Sydri: an IsAlsoA creature until end of turn)
	for (int i = 0; i < planeswalkers.GetSize(); ++i)
	{
		CCardIsAlsoAModifier* pAnimate = new CCardIsAlsoAModifier(DRAGON_AF_TOKEN_NAME, DRAGON_AF_TOKEN_ID, pController);
		CScheduledCardModifier pRemove = CScheduledCardModifier(GetGame(), pAnimate,
			TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater);
		pAnimate->ApplyTo(planeswalkers.GetAt(i));
		pRemove.ApplyTo(planeswalkers.GetAt(i));
	}
	return true;
}

bool CSarkhanTheMasterlessCard::BeforeDragon(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), DRAGON_H_TOKEN_NAME, DRAGON_H_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSorinVengefulBloodlordCard::CSorinVengefulBloodlordCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sorin, Vengeful Bloodlord"), nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Sorin, 4)
	, m_DuringYourTurn(this)
{
	// During your turn, creatures and planeswalkers you control have lifelink.
	// Partial: only the creatures.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0)));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
	m_DuringYourTurn.Add(cpAbility.GetPointer());
	m_DuringYourTurn.AddTurnTriggers();

	// +2: Sorin deals 1 damage to target player or planeswalker. (it can't target planeswalkers)
	AddPlayerLoyaltyAbility(this, +2, &CSorinVengefulBloodlordCard::BeforeDamage);

	// -X: Return target creature card with mana value X from your graveyard to the battlefield. That creature is a Vampire
	// in addition to its other types.
	// Partial: the creature doesn't become a Vampire (and the mana value is checked on resolution).
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpReturn(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

	cpReturn->GetCost().AddCounterCost(GetLoyaltyCounter(), SpecialNumber::AnyNegative);
	cpReturn->GetTargeting()->SetIncludeControllerCardsOnly();
	cpReturn->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpReturn->SetAbilityText(_T("-X: Return target creature card with mana value X from your graveyard to the battlefield."));
	cpReturn->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorinVengefulBloodlordCard::BeforeReturn));
	AddAbility(cpReturn.GetPointer());
}

bool CSorinVengefulBloodlordCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToPlayer(this, pAction->GetAssociatedPlayer(), 1);
	return false;
}

bool CSorinVengefulBloodlordCard::BeforeReturn(CAbilityAction* pAction)
{
	int nX = -pAction->GetCostConfigEntry().GetExtraValue();
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard && (int)pCard->GetConvertedManaCost() == nX)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CTamiyoCollectorOfTalesCard::CTamiyoCollectorOfTalesCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tamiyo, Collector of Tales"), nID,
		_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Tamiyo, 5)
	, m_NameSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTamiyoCollectorOfTalesCard::OnNameSelected))
{
	// Spells and abilities your opponents control can't cause you to discard cards or sacrifice permanents.
	// Partial: only the sacrifices.
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::OppCantForceYourSacrifice));
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());

	// +1: Choose a nonland card name, then reveal the top four cards of your library. Put all cards with the chosen name
	// from among them into your hand and the rest into your graveyard.
	// Partial: the name is chosen among the nonland cards of your library (there is no free card name choice).
	AddLoyaltyAbility(this, +1, _T("+1: Choose a nonland card name and reveal the top four cards. Activates"),
		&CTamiyoCollectorOfTalesCard::BeforeChooseName);

	// -3: Return target card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpReturn(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpReturn->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
	cpReturn->GetTargeting()->SetIncludeControllerCardsOnly();
	cpReturn->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpReturn.GetPointer());
}

bool CTamiyoCollectorOfTalesCard::BeforeChooseName(CAbilityAction* pAction)
{
	m_Names.clear();
	CZone* pLibrary = pAction->GetController()->GetZoneById(ZoneId::Library);
	for (int i = 0; i < pLibrary->GetSize(); ++i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		CString strName = pCard->GetCardName(FALSE);
		if (!pCard->GetCardType().IsLand() && std::find(m_Names.begin(), m_Names.end(), strName) == m_Names.end())
			m_Names.push_back(strName);
	}
	std::sort(m_Names.begin(), m_Names.end());

	std::vector<SelectionEntry> entries;
	for (size_t i = 0; i < m_Names.size(); ++i)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)i;
		entry.strText.Format(_T("Choose %s"), (LPCTSTR)m_Names[i]);
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_NameSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CTamiyoCollectorOfTalesCard::OnNameSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CString strName;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && (size_t)it->dwContext < m_Names.size())
			strName = m_Names[(size_t)it->dwContext];

	// Reveal the top four cards: the ones with the name to the hand, the rest to the graveyard
	CZone* pLibrary = pSelectionPlayer->GetZoneById(ZoneId::Library);
	CCountedCardContainer cards;
	for (int i = pLibrary->GetSize() - 1; i >= 0 && cards.GetSize() < 4; --i)
		cards.AddCard(pLibrary->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (!strName.IsEmpty() && pCard->GetCardName(FALSE) == strName)
			CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
		else
			CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
	}
}

//____________________________________________________________________________
//
CTeferiTimeRavelerCard::CTeferiTimeRavelerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Teferi, Time Raveler"), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Teferi, 4)
{
	// Each opponent can cast spells only any time they could cast a sorcery. (as Teferi, Mage of Zhalfir)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::TeferiEffect));
	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());

	// +1: Until your next turn, you may cast sorcery spells as though they had flash.
	// Partial: only the sorcery cards in your hand when it resolves.
	AddLoyaltyAbility(this, +1, _T("+1: Until your next turn, you may cast sorcery spells as though they had flash. Activates"),
		&CTeferiTimeRavelerCard::BeforeFlash);

	// -3: Return up to one target artifact, creature, or enchantment to its owner's hand. Draw a card.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpBounce(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment, false), FALSE));

	cpBounce->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
	cpBounce->GetTargeting()->SetSubjectCount(0, 1);
	cpBounce->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpBounce->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTeferiTimeRavelerCard::BeforeBounce));
	AddAbility(cpBounce.GetPointer());
}

bool CTeferiTimeRavelerCard::BeforeFlash(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	const CCardFilter* pSorceries = CCardFilter::GetFilter(_T("sorcery cards"));
	for (int i = 0; i < pHand->GetSize(); ++i)
		if (pSorceries->IsCardIncluded(pHand->GetAt(i)))
			ApplyUntilYourNextTurn(pHand->GetAt(i), new CCardKeywordModifier(CardKeyword::Pflash, TRUE, FALSE), pController);
	return true;
}

bool CTeferiTimeRavelerCard::BeforeBounce(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() > 0 && cards.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(cards.GetAt(0));
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CTeyoTheShieldmageCard::CTeyoTheShieldmageCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Teyo, the Shieldmage"), nID,
		_T("2") WHITE_MANA_TEXT, PlaneswalkerType::Teyo, 5)
{
	// You have hexproof. (as Leyline of Sanctity, for spells and abilities)
	{
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantBeTargetedByOpponentsSpells));
		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantBeTargetedByOpponentsAbilities));
		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// -2: Create a 0/3 white Wall creature token with defender.
	AddLoyaltyAbility(this, -2, _T("-2: Create a 0/3 white Wall creature token with defender. Activates"), &CTeyoTheShieldmageCard::BeforeWall);
}

bool CTeyoTheShieldmageCard::BeforeWall(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), WALL_C_TOKEN_NAME, WALL_C_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CTezzeretMasterOfTheBridgeCard::CTezzeretMasterOfTheBridgeCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tezzeret, Master of the Bridge"), nID,
		_T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Tezzeret, 5)
{
	// Creature and planeswalker spells you cast have affinity for artifacts.
	// Not implemented: the engine can't give affinity to other spells.

	// +2: Tezzeret deals X damage to each opponent, where X is the number of artifacts you control. You gain X life.
	AddLoyaltyAbility(this, +2, _T("+2: X damage to each opponent and you gain X life, where X is the number of artifacts you control. Activates"),
		&CTezzeretMasterOfTheBridgeCard::BeforeDrain);

	{
		// -3: Return target artifact card from your graveyard to your hand.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Artifact, false),
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}

	// -8: Exile the top ten cards of your library. Put all artifact cards from among them onto the battlefield.
	AddLoyaltyAbility(this, -8, _T("-8: Exile the top ten cards of your library. Put all artifact cards from among them onto the battlefield. Activates"),
		&CTezzeretMasterOfTheBridgeCard::BeforeUltimate);
}

bool CTezzeretMasterOfTheBridgeCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nX = CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nX > 0)
	{
		DamageEachOpponent(this, pController, nX);
		GainLife(this, pController, nX);
	}
	return true;
}

bool CTezzeretMasterOfTheBridgeCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	CCountedCardContainer cards;
	for (int i = pLibrary->GetSize() - 1; i >= 0 && cards.GetSize() < 10; --i)
		cards.AddCard(pLibrary->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		pExile.ApplyTo(cards.GetAt(i));

	CMoveCardModifier pPut = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, FALSE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Exile && cards.GetAt(i)->GetCardType().IsArtifact())
			pPut.ApplyTo(cards.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CTheWandererCard::CTheWandererCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("The Wanderer"), nID,
		_T("3") WHITE_MANA_TEXT, PlaneswalkerType::Null, 5)
{
	// Prevent all noncombat damage that would be dealt to you and other permanents you control.
	// Not implemented: there is no prevention of only the noncombat damage.

	// -2: Exile target creature with power 4 or greater.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CTibaltRakishInstigatorCard::CTibaltRakishInstigatorCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tibalt, Rakish Instigator"), nID,
		_T("2") RED_MANA_TEXT, PlaneswalkerType::Tibalt, 5)
{
	// Your opponents can't gain life.
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::CantGainLife));
	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());

	// -2: Create a 1/1 red Devil creature token with "When this token dies, it deals 1 damage to any target."
	AddLoyaltyAbility(this, -2, _T("-2: Create a 1/1 red Devil creature token. Activates"), &CTibaltRakishInstigatorCard::BeforeDevil);
}

bool CTibaltRakishInstigatorCard::BeforeDevil(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), DEVIL_A_TOKEN_NAME, DEVIL_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CUginTheIneffableCard::CUginTheIneffableCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ugin, the Ineffable"), nID,
		_T("6"), PlaneswalkerType::Ugin, 4)
{
	{
		// Colorless spells you cast cost {2} less to cast.
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new ColorlessComparer,
				_T("2")));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// +1: Exile the top card of your library face down and look at it. Create a 2/2 colorless Spirit creature token. When
	// that token leaves the battlefield, put the exiled card into your hand.
	// Partial: the card is exiled face up, and it goes to your hand only if Ugin is still on the battlefield.
	AddLoyaltyAbility(this, +1, _T("+1: Exile the top card of your library and create a 2/2 colorless Spirit creature token. Activates"),
		&CUginTheIneffableCard::BeforeExile);

	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::_AllZones));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Token, false));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUginTheIneffableCard::SetLeaveContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CUginTheIneffableCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Destroy target permanent that's one or more colors.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new NegateCardComparer(new ColorlessComparer),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CUginTheIneffableCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others, pController).ApplyTo(pCard);

	CCountedCardContainer tokens;
	CTokenCreationModifier(GetGame(), SPIRIT_T_TOKEN_NAME, SPIRIT_T_TOKEN_ID, 1, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pController);
	if (tokens.GetSize() > 0 && pCard->GetZoneId() == ZoneId::Exile)
		m_Exiled.push_back(std::make_pair(tokens.GetAt(0), pCard));
	return true;
}

bool CUginTheIneffableCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	for (size_t i = 0; i < m_Exiled.size(); ++i)
		if (m_Exiled[i].first == pCard)
		{
			triggerContext.nValue1 = (DWORD)m_Exiled[i].second;
			m_Exiled.erase(m_Exiled.begin() + i);
			return true;
		}
	return false;
}

bool CUginTheIneffableCard::BeforeReturn(TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved >::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (pCard && pCard->GetZoneId() == ZoneId::Exile)
		CMoveCardModifier(ZoneId::Exile, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return true;
}

//____________________________________________________________________________
//
CVivienChampionOfTheWildsCard::CVivienChampionOfTheWildsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vivien, Champion of the Wilds"), nID,
		_T("2") GREEN_MANA_TEXT, PlaneswalkerType::Vivien, 4)
{
	// You may cast creature spells as though they had flash. (as Leyline of Anticipation, for creature cards)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0), CreatureKeyword::Null));
	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Pflash);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->SetAffectCardsInTheseZones(ZoneId::Hand | ZoneId::Stack | ZoneId::Graveyard | ZoneId::Library | ZoneId::Exile | ZoneId::_ExileFaceDown | ZoneId::_Effects);
	AddAbility(cpAbility.GetPointer());

	{
		// +1: Until your next turn, up to one target creature gains vigilance and reach.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpKeywords(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpKeywords->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpKeywords->GetTargeting()->SetSubjectCount(0, 1);
		cpKeywords->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpKeywords->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVivienChampionOfTheWildsCard::BeforeKeywords));
		AddAbility(cpKeywords.GetPointer());
	}

	// -2: Look at the top three cards of your library. Exile one face down and put the rest on the bottom of your library
	// in any order. For as long as it remains exiled, you may cast it if it's a creature spell.
	// Not implemented: the engine can't cast cards from exile.
}

bool CVivienChampionOfTheWildsCard::BeforeKeywords(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() > 0)
		CreatureKeywordUntilYourNextTurn(cards.GetAt(0), CreatureKeyword::Vigilance | CreatureKeyword::Reach, pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CVraskaSwarmsEminenceCard::CVraskaSwarmsEminenceCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vraska, Swarm's Eminence"), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Vraska, 5)
{
	// {2}{B/G}{B/G}
	AddHybridPermanentSpells(this, _T("2"), 2, BLACK_MANA_TEXT, GREEN_MANA_TEXT);

	// Whenever a creature you control with deathtouch deals damage to a player or planeswalker, put a +1/+1 counter on
	// that creature.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVraskaSwarmsEminenceCard::SetPlayerDamageContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CVraskaSwarmsEminenceCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::PlaneswalkerEventCallback, &CWhenDamageDealt::SetPlaneswalkerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVraskaSwarmsEminenceCard::SetPlaneswalkerDamageContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CVraskaSwarmsEminenceCard::BeforeCounter2));
		AddAbility(cpAbility.GetPointer());
	}

	// -2: Create a 1/1 black Assassin creature token with deathtouch and "Whenever this token deals damage to a
	// planeswalker, destroy that planeswalker."
	AddLoyaltyAbility(this, -2, _T("-2: Create a 1/1 black Assassin creature token with deathtouch. Activates"),
		&CVraskaSwarmsEminenceCard::BeforeAssassin);
}

bool CVraskaSwarmsEminenceCard::SetPlayerDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	if (!pFromCard || !pFromCard->GetCardType().IsCreature() || !pFromCard->GetCardKeyword()->HasDeathtouch())
		return false;
	triggerContext.nValue1 = (DWORD)pFromCard;
	return true;
}

bool CVraskaSwarmsEminenceCard::SetPlaneswalkerDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlaneswalkerCard* pToPlaneswalker, Damage damage) const
{
	if (!pFromCard || !pFromCard->GetCardType().IsCreature() || !pFromCard->GetCardKeyword()->HasDeathtouch())
		return false;
	triggerContext.nValue1 = (DWORD)pFromCard;
	return true;
}

bool CVraskaSwarmsEminenceCard::BeforeCounter(TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt, CWhenDamageDealt::PlayerEventCallback,
	&CWhenDamageDealt::SetPlayerEventCallback >::TriggeredActionType* pAction)
{
	AddPlusCounter((CCard*)pAction->GetTriggerContext().nValue1, 1);
	return true;
}

bool CVraskaSwarmsEminenceCard::BeforeCounter2(TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt, CWhenDamageDealt::PlaneswalkerEventCallback,
	&CWhenDamageDealt::SetPlaneswalkerEventCallback >::TriggeredActionType* pAction)
{
	AddPlusCounter((CCard*)pAction->GetTriggerContext().nValue1, 1);
	return true;
}

bool CVraskaSwarmsEminenceCard::BeforeAssassin(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ASSASSIN_A_TOKEN_NAME, ASSASSIN_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define MIZZIUM_TANK_VEHICLE_NAME			_T("Mizzium Tank (Vehicle)")
#define MIZZIUM_TANK_VEHICLE_ID				64136
#define PARHELION_II_VEHICLE_NAME			_T("Parhelion II (Vehicle)")
#define PARHELION_II_VEHICLE_ID				64137
#define SILENT_SUBMERSIBLE_VEHICLE_NAME		_T("Silent Submersible (Vehicle)")
#define SILENT_SUBMERSIBLE_VEHICLE_ID		64138

// "Add two mana of different colors": one mana ability for each pair of colors (strCost: the extra cost, e.g. "2")
static void AddTwoColorsManaAbilities(CCard* pCard, LPCTSTR strCost, BOOL bSacrifice)
{
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
		for (int j = i + 1; j < 5; ++j)
		{
			CString strMana;
			strMana.Format(_T("%s%s"), colors[i], colors[j]);

			counted_ptr<CManaProductionAbility> cpAbility(
				::CreateObject<CManaProductionAbility>(pCard, strCost, AbilityType::Activated, (LPCTSTR)strMana));
			cpAbility->AddTapCost();
			if (bSacrifice)
				cpAbility->AddSacrificeCost();
			pCard->AddAbility(cpAbility.GetPointer());
		}
}

//____________________________________________________________________________
//
CFiremindVesselCard::CFiremindVesselCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Firemind Vessel"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
{
	// This artifact enters tapped.
	SetIntoPlayTapped();

	// {T}: Add two mana of different colors.
	AddTwoColorsManaAbilities(this, _T(""), FALSE);
}

//____________________________________________________________________________
//
CGodPharaohsStatueCard::CGodPharaohsStatueCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("God-Pharaoh's Statue"), CardType::Artifact | CardType::Legendary, nID,
		_T("6"), AbilityType::Artifact)
{
	// Spells your opponents cast cost {2} more to cast. (as Thalia)
	counted_ptr<CConsExtraManaEnchantment> cpAbility(
		::CreateObject<CConsExtraManaEnchantment>(this,
			new TrueCardComparer,
			_T("2")));
	cpAbility->SetAffectOpponentCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// At the beginning of your end step, each opponent loses 1 life.
	AddStepTrigger<CGodPharaohsStatueCard>(this, NodeId::EndStep, false, NULL, &CGodPharaohsStatueCard::BeforeLoseLife);
}

bool CGodPharaohsStatueCard::BeforeLoseLife(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, FALSE);
	return true;
}

//____________________________________________________________________________
//
CGuildGlobeCard::CGuildGlobeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Guild Globe"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters, draw a card.
	AddEnterTrigger(this, &CGuildGlobeCard::BeforeDraw);

	// {2}, {T}, Sacrifice this artifact: Add two mana of different colors.
	AddTwoColorsManaAbilities(this, _T("2"), TRUE);
}

bool CGuildGlobeCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CManaGeodeCard::CManaGeodeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mana Geode"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// When this artifact enters, scry 1.
	AddEnterTrigger(this, &CManaGeodeCard::BeforeScry);

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);
}

bool CManaGeodeCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CMizziumTankCard::CMizziumTankCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mizzium Tank"), CardType::Artifact, nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, AbilityType::Artifact)
	, m_Crew(this)
{
	// Trample (in the creature it becomes, Mizzium Tank (Vehicle) in ATokens). Crew 1
	m_Crew.AddCrewAbility(1, MIZZIUM_TANK_VEHICLE_NAME, MIZZIUM_TANK_VEHICLE_ID);

	// Whenever you cast a noncreature spell, this Vehicle becomes an artifact creature and gets +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMizziumTankCard::BeforeAnimate));
	AddAbility(cpAbility.GetPointer());
}

bool CMizziumTankCard::BeforeAnimate(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	// (as the Vehicles of Aether Revolt that become creatures)
	m_Crew.Animate(pAction->GetController());
	if (GetIsAlsoA())
		PumpCreature(GetIsAlsoA(), +1, +1);
	return true;
}

//____________________________________________________________________________
//
CParhelionIICard::CParhelionIICard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Parhelion II"), CardType::Artifact | CardType::Legendary, nID,
		_T("6") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Artifact)
	, m_Crew(this)
{
	// Flying, first strike, vigilance. Whenever Parhelion II attacks, create two 4/4 white Angel creature tokens with
	// flying and vigilance that are attacking. (in the creature it becomes, Parhelion II (Vehicle) in ATokens; the
	// Angels don't enter attacking)
	// Crew 4
	m_Crew.AddCrewAbility(4, PARHELION_II_VEHICLE_NAME, PARHELION_II_VEHICLE_ID);
}

//____________________________________________________________________________
//
CSilentSubmersibleCard::CSilentSubmersibleCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Silent Submersible"), CardType::Artifact, nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Artifact)
	, m_Crew(this)
{
	// Whenever this Vehicle deals combat damage to a player or planeswalker, draw a card. (in the creature it becomes,
	// Silent Submersible (Vehicle) in ATokens)
	// Crew 2
	m_Crew.AddCrewAbility(2, SILENT_SUBMERSIBLE_VEHICLE_NAME, SILENT_SUBMERSIBLE_VEHICLE_ID);
}

//____________________________________________________________________________
//
CViviensArkbowCard::CViviensArkbowCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vivien's Arkbow"), CardType::Artifact | CardType::Legendary, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Artifact)
	, m_nX(0)
	, m_CreatureFilter(_T("a creature card with mana value X or less"), _T("creature cards with mana value X or less"),
		new ManaValueAtMostComparer(&m_nX))
{
	// {X}, {T}, Discard a card: Look at the top X cards of your library. You may put a creature card with mana value X or
	// less from among them onto the battlefield. Put the rest on the bottom of your library in a random order.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetAbilityText(_T("Look at the top X cards, put a creature card with mana value X or less onto the battlefield. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CViviensArkbowCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

bool CViviensArkbowCard::BeforeLook(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	CPlayer* pController = pAction->GetController();
	int nCount = pController->GetZoneById(ZoneId::Library)->GetSize();
	if (nCount > m_nX)
		nCount = m_nX;
	if (nCount <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nCount,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &m_CreatureFilter,
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define SOLDIER_U_TOKEN_NAME		_T("Soldier (U)")
#define SOLDIER_U_TOKEN_ID			55133
#define CITIZEN_B_TOKEN_NAME		_T("Citizen (B)")
#define CITIZEN_B_TOKEN_ID			55134
#define ANGEL_M_TOKEN_NAME			_T("Angel (M)")
#define ANGEL_M_TOKEN_ID			55117

// Gains control of pCard until end of turn, untaps it and gives it haste (as Keldon Overseer in Dominaria)
static void GainControlUntilEndOfTurn(CCard* pSource, CCard* pCard)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CGame* pGame = pSource->GetGame();
	CGainControlModifier(pGame, pSource).ApplyTo(pCard);
	CScheduledCardModifier pReturn = CScheduledCardModifier(pGame, new CGainControlModifier(pGame, pSource, true),
		TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::ApplyToLater);
	pReturn.ApplyTo(pCard);

	CCardOrientationModifier(FALSE).ApplyTo(pCard);
	PumpCreature(pCard, 0, 0, CreatureKeyword::Haste);
}

// Damage to a creature or a planeswalker (the planeswalkers lose loyalty)
static void DealDamageToCreatureOrPlaneswalker(CCard* pSource, CCard* pCard, int nDamage)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || nDamage <= 0)
		return;
	if (pCard->GetCardType().IsCreature())
		DealDamageToCreature(pSource, pCard, nDamage);
	else if (pCard->GetCardType().IsPlaneswalker())
		CCardCounterModifier(LOYALTY_COUNTER, -nDamage).ApplyTo(pCard);
}

//____________________________________________________________________________
//
CAidTheFallenCard::CAidTheFallenCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Aid the Fallen"), CardType::Sorcery, nID)
	, m_PlaneswalkerFilter(_T("a planeswalker card"), _T("planeswalker cards"), new CardTypeComparer(CardType::Planeswalker, false))
{
	// Choose one or both - Return target creature card from your graveyard to your hand; Return target planeswalker card
	// from your graveyard to your hand.
	// Partial: with both modes, the cards are chosen on resolution (they aren't targets).
	CardComparer* comparers[] = { new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false) };
	LPCTSTR texts[] = { _T("Return target creature card from your graveyard to your hand. Casts"),
						_T("Return target planeswalker card from your graveyard to your hand. Casts") };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("1") BLACK_MANA_TEXT,
				comparers[i],
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetAbilityText(texts[i]);
		if (i > 0)
			cpSpell->SetMainSpell(FALSE);
		AddSpell(cpSpell.GetPointer());
	}

	CGenericSpell* pBoth = AddSorcery(this, _T("1") BLACK_MANA_TEXT, &CAidTheFallenCard::BeforeBoth);
	pBoth->SetAbilityText(_T("Both: return a creature card and a planeswalker card from your graveyard to your hand. Casts"));
	pBoth->SetMainSpell(FALSE);
}

bool CAidTheFallenCard::BeforeBoth(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 1, CCardFilter::GetFilter(_T("creatures")), ZoneId::Hand, MoveType::Others);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 1, &m_PlaneswalkerFilter, ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CAngrathsRampageCard::CAngrathsRampageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Angrath's Rampage"), CardType::Sorcery, nID)
	, m_PlaneswalkerFilter(_T("a planeswalker"), _T("planeswalkers"), new CardTypeComparer(CardType::Planeswalker, false))
{
	// Choose one - Target player sacrifices an artifact of their choice; a creature; a planeswalker.
	CTargetSpell* pSpell1 = AddPlayerSorcery(this, BLACK_MANA_TEXT RED_MANA_TEXT, &CAngrathsRampageCard::BeforeArtifact);
	pSpell1->SetAbilityText(_T("Target player sacrifices an artifact. Casts"));
	CTargetSpell* pSpell2 = AddPlayerSorcery(this, BLACK_MANA_TEXT RED_MANA_TEXT, &CAngrathsRampageCard::BeforeCreature);
	pSpell2->SetAbilityText(_T("Target player sacrifices a creature. Casts"));
	pSpell2->SetMainSpell(FALSE);
	CTargetSpell* pSpell3 = AddPlayerSorcery(this, BLACK_MANA_TEXT RED_MANA_TEXT, &CAngrathsRampageCard::BeforePlaneswalker);
	pSpell3->SetAbilityText(_T("Target player sacrifices a planeswalker. Casts"));
	pSpell3->SetMainSpell(FALSE);
}

bool CAngrathsRampageCard::BeforeArtifact(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("artifacts")), ZoneId::Graveyard, MoveType::Sacrifice);
	return false;
}

bool CAngrathsRampageCard::BeforeCreature(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")), ZoneId::Graveyard, MoveType::Sacrifice);
	return false;
}

bool CAngrathsRampageCard::BeforePlaneswalker(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, &m_PlaneswalkerFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	return false;
}

//____________________________________________________________________________
//
CBleedingEdgeCard::CBleedingEdgeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bleeding Edge"), CardType::Sorcery, nID)
{
	// Up to one target creature gets -2/-2 until end of turn. Amass Zombies 2.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Characteristic::Negative,
		&CBleedingEdgeCard::BeforeResolution);
	pSpell->GetTargeting()->SetSubjectCount(0, 1);
}

bool CBleedingEdgeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	if (cards.GetSize() > 0 && cards.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(cards.GetAt(0), -2, -2);
	Amass(this, pAction->GetController(), 2);
	return false;
}

//____________________________________________________________________________
//
CBondOfDisciplineCard::CBondOfDisciplineCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bond of Discipline"), CardType::Sorcery, nID)
{
	// Tap all creatures your opponents control. Creatures you control gain lifelink until end of turn.
	AddSorcery(this, _T("4") WHITE_MANA_TEXT, &CBondOfDisciplineCard::BeforeResolution);
}

bool CBondOfDisciplineCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer theirs, mine;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, theirs);
	GetCreatures(GetGame(), pAction->GetController(), TRUE, mine);

	CCardOrientationModifier pTap = CCardOrientationModifier(TRUE);
	for (int i = 0; i < theirs.GetSize(); ++i)
		pTap.ApplyTo(theirs.GetAt(i));
	for (int i = 0; i < mine.GetSize(); ++i)
		GainCardKeyword(mine.GetAt(i), CardKeyword::Lifelink);
	return true;
}

//____________________________________________________________________________
//
CBondOfFlourishingCard::CBondOfFlourishingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bond of Flourishing"), CardType::Sorcery, nID)
	, m_PermanentFilter(_T("a permanent card"), _T("permanent cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)))
{
	// Look at the top three cards of your library. You may reveal a permanent card from among them and put it into your
	// hand. Put the rest on the bottom of your library in any order. You gain 3 life.
	AddSorcery(this, _T("1") GREEN_MANA_TEXT, &CBondOfFlourishingCard::BeforeResolution);
}

bool CBondOfFlourishingCard::BeforeResolution(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 3, 0, 1, &m_PermanentFilter);
	GainLife(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CBondOfInsightCard::CBondOfInsightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bond of Insight"), CardType::Sorcery, nID)
{
	// Each player mills four cards. Return up to two instant and/or sorcery cards from your graveyard to your hand. Exile
	// Bond of Insight.
	CGenericSpell* pSpell = AddSorcery(this, _T("3") BLUE_MANA_TEXT, &CBondOfInsightCard::BeforeResolution);
	pSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
}

bool CBondOfInsightCard::BeforeResolution(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		Mill(GetGame()->GetPlayer(ip), 4);
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 0, 2,
		CCardFilter::GetFilter(_T("instant cards or sorcery cards")), ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CBondOfPassionCard::CBondOfPassionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bond of Passion"), CardType::Sorcery, nID)
{
	// Gain control of target creature until end of turn. Untap that creature. It gains haste until end of turn. Bond of
	// Passion deals 2 damage to any other target. (it can't target planeswalkers)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("4") RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, TRUE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBondOfPassionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBondOfPassionCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleAction)
		return false;

	CCountedCardContainer cards1, cards2;
	CPlayerContainer players2;
	pDoubleAction->GetTargetGroup1().GetCardSubjects(cards1);
	pDoubleAction->GetTargetGroup2().GetCardSubjects(cards2);
	pDoubleAction->GetTargetGroup2().GetPlayerSubjects(players2);

	CCard* pCreature = cards1.GetSize() > 0 ? cards1.GetAt(0) : NULL;
	GainControlUntilEndOfTurn(this, pCreature);

	if (cards2.GetSize() > 0 && cards2.GetAt(0) != pCreature)
		DealDamageToCreature(this, cards2.GetAt(0), 2);
	else if (players2.GetSize() > 0)
		DealDamageToPlayer(this, players2.GetAt(0), 2);
	return false;
}

//____________________________________________________________________________
//
CBondOfRevivalCard::CBondOfRevivalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bond of Revival"), CardType::Sorcery, nID)
{
	// Return target creature card from your graveyard to the battlefield. It gains haste until your next turn.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("4") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBondOfRevivalCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBondOfRevivalCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;

	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Battlefield)
		CreatureKeywordUntilYourNextTurn(pCard, CreatureKeyword::Haste, pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CCallousDismissalCard::CCallousDismissalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Callous Dismissal"), CardType::Sorcery, nID)
{
	// Return target nonland permanent to its owner's hand. Amass Zombies 1.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("1") BLUE_MANA_TEXT,
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)), ZoneId::Hand, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCallousDismissalCard::BeforeAmass));
}

bool CCallousDismissalCard::BeforeAmass(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	Amass(this, pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CCasualtiesOfWarCard::CCasualtiesOfWarCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Casualties of War"), CardType::Sorcery, nID)
{
	// Choose one or more - Destroy target artifact; creature; enchantment; land; planeswalker.
	// (up to five targets; on resolution each one is destroyed if it can fill a different mode)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment | CardType::_Land | CardType::Planeswalker, false),
			FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(1, 5);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCasualtiesOfWarCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CCasualtiesOfWarCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);

	CardType types[] = { CardType::Artifact, CardType::Creature, CardType::_Enchantment, CardType::_Land, CardType::Planeswalker };
	BOOL bUsed[5] = { FALSE, FALSE, FALSE, FALSE, FALSE };
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		for (int t = 0; t < 5; ++t)
			if (!bUsed[t] && CardTypeComparer(types[t], false)(pCard))
			{
				bUsed[t] = TRUE;
				DestroyPermanent(pCard, pAction->GetController());
				break;
			}
	}
	return false;
}

//____________________________________________________________________________
//
CCommandTheDreadhordeCard::CCommandTheDreadhordeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Command the Dreadhorde"), CardType::Sorcery, nID)
{
	// Choose any number of target creature and/or planeswalker cards in graveyards. Command the Dreadhorde deals damage to
	// you equal to the total mana value of those cards. Put them onto the battlefield under your control.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
			ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(0, 20);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCommandTheDreadhordeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CCommandTheDreadhordeCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);

	int nTotal = 0;
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
			nTotal += (int)cards.GetAt(i)->GetConvertedManaCost();
	if (nTotal > 0)
		DealDamageToPlayer(this, pController, nTotal);

	CMoveCardModifier pPut = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
			pPut.ApplyTo(cards.GetAt(i));
	return false;
}

//____________________________________________________________________________
//
CContentiousPlanCard::CContentiousPlanCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Contentious Plan"), CardType::Sorcery, nID)
	, m_Proliferate(this)
{
	// Proliferate. Draw a card.
	m_Proliferate.AddProliferateTrigger();
	AddSorcery(this, _T("1") BLUE_MANA_TEXT, &CContentiousPlanCard::BeforeResolution);
}

bool CContentiousPlanCard::BeforeResolution(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CCourageInCrisisCard::CCourageInCrisisCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Courage in Crisis"), CardType::Sorcery, nID)
	, m_Proliferate(this)
{
	// Put a +1/+1 counter on target creature, then proliferate.
	m_Proliferate.AddProliferateTrigger();
	AddCreatureSorcery(this, _T("2") GREEN_MANA_TEXT, Characteristic::Positive, &CCourageInCrisisCard::BeforeResolution);
}

bool CCourageInCrisisCard::BeforeResolution(CAbilityAction* pAction)
{
	AddPlusCounter(GetTargetCreature(pAction), 1);
	m_Proliferate.Proliferate(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CDavrielsShadowfugueCard::CDavrielsShadowfugueCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Davriel's Shadowfugue"), CardType::Sorcery, nID)
{
	// Target player discards two cards and loses 2 life.
	AddPlayerSorcery(this, _T("3") BLACK_MANA_TEXT, &CDavrielsShadowfugueCard::BeforeResolution);
}

bool CDavrielsShadowfugueCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		DiscardCards(GetGame(), pPlayer, 2);
		CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
	}
	return false;
}

//____________________________________________________________________________
//
CDeliverUntoEvilCard::CDeliverUntoEvilCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deliver Unto Evil"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDeliverUntoEvilCard::OnCardsSelected))
{
	// Choose up to four target cards in your graveyard. If you control a Bolas planeswalker, return those cards to your
	// hand. Otherwise, an opponent chooses two of them. Leave the chosen cards in your graveyard and put the rest into your
	// hand. Exile Deliver Unto Evil.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(0, 4);
	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeliverUntoEvilCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDeliverUntoEvilCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);

	m_Cards.clear();
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
			m_Cards.push_back(cards.GetAt(i));

	CMoveCardModifier pReturn = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pController);
	if (ControlsPlaneswalker(pController, PlaneswalkerType::Bolas))
	{
		for (size_t i = 0; i < m_Cards.size(); ++i)
			pReturn.ApplyTo(m_Cards[i]);
		m_Cards.clear();
		return false;
	}

	// An opponent chooses two of them (they stay in the graveyard)
	if (m_Cards.size() <= 2)
	{
		m_Cards.clear();
		return false;
	}

	std::vector<SelectionEntry> entries;
	for (size_t i = 0; i < m_Cards.size(); ++i)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)m_Cards[i];
		entry.cpAssociatedCard = m_Cards[i];
		entry.strText.Format(_T("Leave %s in the graveyard"), m_Cards[i]->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_CardSelection.AddSelectionRequest(entries, 2, 2, this, GetGame()->GetNextPlayer(pController), (DWORD)pController);
	return false;
}

void CDeliverUntoEvilCard::OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
	CMoveCardModifier pReturn = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pController);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (!it->bSelected && pCard->GetZoneId() == ZoneId::Graveyard)
			pReturn.ApplyTo(pCard);
	}
	m_Cards.clear();
}

//____________________________________________________________________________
//
CDomrisAmbushCard::CDomrisAmbushCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Domri's Ambush"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on target creature you control. Then that creature deals damage equal to its power to target
	// creature or planeswalker you don't control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDomrisAmbushCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDomrisAmbushCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard1);
	if (!pCreature)
		return false;

	AddPlusCounter(pCreature, 1);
	DealDamageToCreatureOrPlaneswalker(pCreature, pCard2, GET_INTEGER(pCreature->GetPower()));
	return false;
}

//____________________________________________________________________________
//
CEnterTheGodEternalsCard::CEnterTheGodEternalsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Enter the God-Eternals"), CardType::Sorcery, nID)
{
	// Enter the God-Eternals deals 4 damage to target creature and you gain life equal to the damage dealt this way. Target
	// player mills four cards. Amass Zombies 4.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			FALSE_CARD_COMPARER, TRUE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEnterTheGodEternalsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CEnterTheGodEternalsCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleAction)
		return false;

	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	CPlayerContainer players;
	pDoubleAction->GetTargetGroup1().GetCardSubjects(cards);
	pDoubleAction->GetTargetGroup2().GetPlayerSubjects(players);

	if (cards.GetSize() > 0 && cards.GetAt(0)->GetZoneId() == ZoneId::Battlefield)
	{
		DealDamageToCreature(this, cards.GetAt(0), 4);
		GainLife(this, pController, 4);
	}
	if (players.GetSize() > 0)
		Mill(players.GetAt(0), 4);
	Amass(this, pController, 4);
	return false;
}

//____________________________________________________________________________
//
CFinaleOfDevastationCard::CFinaleOfDevastationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Finale of Devastation"), CardType::Sorcery, nID)
	, m_nX(0)
	, m_CreatureFilter(_T("a creature card with mana value X or less"), _T("creature cards with mana value X or less"),
		new ManaValueAtMostComparer(&m_nX))
{
	// Search your library and/or graveyard for a creature card with mana value X or less and put it onto the battlefield.
	// If you search your library this way, shuffle. If X is 10 or more, creatures you control get +X/+X and gain haste
	// until end of turn.
	// Partial: only the library is searched.
	CGenericSpell* pSpell = AddSorcery(this, GREEN_MANA_TEXT GREEN_MANA_TEXT, &CFinaleOfDevastationCard::BeforeResolution);
	pSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
}

bool CFinaleOfDevastationCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, &m_CreatureFilter, FALSE);
	if (m_nX >= 10)
		PumpCreatures(GetGame(), pAction->GetController(), m_nX, m_nX, CreatureKeyword::Haste);
	return true;
}

//____________________________________________________________________________
//
CFinaleOfEternityCard::CFinaleOfEternityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Finale of Eternity"), CardType::Sorcery, nID)
{
	// Destroy up to three target creatures with toughness X or less. If X is 10 or more, return all creature cards from
	// your graveyard to the battlefield.
	// (the toughness of the targets is checked on resolution)
	CTargetSpell* pSpell = AddCreatureSorcery(this, BLACK_MANA_TEXT BLACK_MANA_TEXT, Characteristic::Negative,
		&CFinaleOfEternityCard::BeforeResolution);
	pSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	pSpell->GetTargeting()->SetSubjectCount(0, 3);
}

bool CFinaleOfEternityCard::BeforeResolution(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(cards.GetAt(i));
		if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && GET_INTEGER(pCreature->GetToughness()) <= nX)
			DestroyPermanent(pCreature, pController);
	}

	if (nX >= 10)
	{
		CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
		CCountedCardContainer creatures;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
			if (pGraveyard->GetAt(i)->GetCardType().IsCreature())
				creatures.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);
		CMoveCardModifier pReturn = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController);
		for (int i = 0; i < creatures.GetSize(); ++i)
			pReturn.ApplyTo(creatures.GetAt(i));
	}
	return false;
}

//____________________________________________________________________________
//
CFinaleOfGloryCard::CFinaleOfGloryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Finale of Glory"), CardType::Sorcery, nID)
{
	// Create X 2/2 white Soldier creature tokens with vigilance. If X is 10 or more, also create X 4/4 white Angel creature
	// tokens with flying and vigilance.
	CGenericSpell* pSpell = AddSorcery(this, WHITE_MANA_TEXT WHITE_MANA_TEXT, &CFinaleOfGloryCard::BeforeResolution);
	pSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
}

bool CFinaleOfGloryCard::BeforeResolution(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0)
		CTokenCreationModifier(GetGame(), SOLDIER_U_TOKEN_NAME, SOLDIER_U_TOKEN_ID, nX).ApplyTo(pAction->GetController());
	if (nX >= 10)
		CTokenCreationModifier(GetGame(), ANGEL_M_TOKEN_NAME, ANGEL_M_TOKEN_ID, nX).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CFinaleOfRevelationCard::CFinaleOfRevelationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Finale of Revelation"), CardType::Sorcery, nID)
{
	// Draw X cards. If X is 10 or more, instead shuffle your graveyard into your library, draw X cards, untap up to five
	// lands, and you have no maximum hand size for the rest of the game. Exile Finale of Revelation.
	// (the five lands are the first tapped lands you control)
	CGenericSpell* pSpell = AddSorcery(this, BLUE_MANA_TEXT BLUE_MANA_TEXT, &CFinaleOfRevelationCard::BeforeResolution);
	pSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	pSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
}

bool CFinaleOfRevelationCard::BeforeResolution(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	CPlayer* pController = pAction->GetController();
	if (nX < 10)
	{
		if (nX > 0)
			DrawCards(GetGame(), pController, nX);
		return true;
	}

	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	CCountedCardContainer cards;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i) != this)
			cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);
	CMoveCardModifier pMove = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		pMove.ApplyTo(cards.GetAt(i));
	pController->GetZoneById(ZoneId::Library)->Shuffle();

	DrawCards(GetGame(), pController, nX);

	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer lands;
	for (int i = 0; i < pBattlefield->GetSize() && lands.GetSize() < 5; ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsLand() && pBattlefield->GetAt(i)->GetOrientation()->IsTapped())
			lands.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	for (int i = 0; i < lands.GetSize(); ++i)
		pUntap.ApplyTo(lands.GetAt(i));

	CPlayerEffectModifier(PlayerEffectType::NoMaximumHandSize).ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CGideonsBattleCryCard::CGideonsBattleCryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gideon's Battle Cry"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on each creature you control. You may search your library and/or graveyard for a card named
	// Gideon, the Oathsworn, reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddSorcery(this, _T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, &CGideonsBattleCryCard::BeforeResolution);
}

bool CGideonsBattleCryCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i), 1);
	SearchNamedCardToHand(pAction->GetController(), _T("Gideon, the Oathsworn"));
	return true;
}

//____________________________________________________________________________
//
CHonorTheGodPharaohCard::CHonorTheGodPharaohCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Honor the God-Pharaoh"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, discard a card. Draw two cards. Amass Zombies 1.
	CGenericSpell* pSpell = AddSorcery(this, _T("2") RED_MANA_TEXT, &CHonorTheGodPharaohCard::BeforeResolution);
	pSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
}

bool CHonorTheGodPharaohCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CInvadeTheCityCard::CInvadeTheCityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Invade the City"), CardType::Sorcery, nID)
{
	// Amass Zombies X, where X is the number of instant and sorcery cards in your graveyard.
	AddSorcery(this, _T("1") BLUE_MANA_TEXT RED_MANA_TEXT, &CInvadeTheCityCard::BeforeResolution);
}

bool CInvadeTheCityCard::BeforeResolution(CAbilityAction* pAction)
{
	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nX = CCardFilter::GetFilter(_T("instant cards or sorcery cards"))->CountIncluded(pGraveyard->GetCardContainer());
	Amass(this, pAction->GetController(), nX);
	return true;
}

//____________________________________________________________________________
//
CJacesRuseCard::CJacesRuseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Jace's Ruse"), CardType::Sorcery, nID)
{
	// Return up to two target creatures to their owner's hand. You may search your library and/or graveyard for a card
	// named Jace, Arcane Strategist, reveal it, and put it into your hand. If you search your library this way, shuffle.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Characteristic::Negative,
		&CJacesRuseCard::BeforeResolution);
	pSpell->GetTargeting()->SetSubjectCount(0, 2);
}

bool CJacesRuseCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
		BounceCreature(cards.GetAt(i));
	SearchNamedCardToHand(pAction->GetController(), _T("Jace, Arcane Strategist"));
	return false;
}

//____________________________________________________________________________
//
CJacesTriumphCard::CJacesTriumphCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Jace's Triumph"), CardType::Sorcery, nID)
{
	// Draw two cards. If you control a Jace planeswalker, draw three cards instead.
	AddSorcery(this, _T("2") BLUE_MANA_TEXT, &CJacesTriumphCard::BeforeResolution);
}

bool CJacesTriumphCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, ControlsPlaneswalker(pController, PlaneswalkerType::Jace) ? 3 : 2);
	return true;
}

//____________________________________________________________________________
//
CNeoformCard::CNeoformCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Neoform"), CardType::Sorcery, nID)
	, m_nManaValue(0)
	, m_SearchFilter(_T("a creature card with the chosen mana value"), _T("creature cards with the chosen mana value"),
		new ManaValueEqualComparer(&m_nManaValue))
{
	// As an additional cost to cast this spell, sacrifice a creature. Search your library for a creature card with mana
	// value equal to 1 plus the sacrificed creature's mana value, put that card onto the battlefield with an additional
	// +1/+1 counter on it, then shuffle. (the sacrificed card of the cost, as Prime Speaker Vannifar)
	CGenericSpell* pSpell = AddSorcery(this, GREEN_MANA_TEXT BLUE_MANA_TEXT, &CNeoformCard::BeforeResolution);
	pSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
}

bool CNeoformCard::BeforeResolution(CAbilityAction* pAction)
{
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	if (!pSacrificed || pSacrificed->GetSize() == 0)
		return true;

	m_nManaValue = (int)pSacrificed->GetAt(0)->GetConvertedManaCost() + 1;

	// (as SearchToBattlefield, keeping the card to put the counter on it)
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &m_SearchFilter,
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			AddPlusCounter(cards.GetAt(i), 1);
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
CNissasTriumphCard::CNissasTriumphCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nissa's Triumph"), CardType::Sorcery, nID)
	, m_BasicForestFilter(_T("a basic Forest card"), _T("basic Forest cards"),
		new AndCardComparer(new CardTypeComparer(CardType::BasicLand, false), new CardTypeComparer(CardType::Forest, false)))
{
	// Search your library for up to two basic Forest cards. If you control a Nissa planeswalker, instead search your library
	// for up to three land cards. Reveal those cards, put them into your hand, then shuffle.
	AddSorcery(this, GREEN_MANA_TEXT GREEN_MANA_TEXT, &CNissasTriumphCard::BeforeResolution);
}

bool CNissasTriumphCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (ControlsPlaneswalker(pController, PlaneswalkerType::Nissa))
		SearchToHand(GetGame(), pController, 3, CCardFilter::GetFilter(_T("lands")));
	else
		SearchToHand(GetGame(), pController, 2, &m_BasicForestFilter);
	return true;
}

//____________________________________________________________________________
//
CPlanewideCelebrationCard::CPlanewideCelebrationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Planewide Celebration"), CardType::Sorcery, nID)
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPlanewideCelebrationCard::OnModeSelected))
	, m_Proliferate(this)
	, m_PermanentFilter(_T("a permanent card"), _T("permanent cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)))
	, m_nModesLeft(0)
{
	// Choose four. You may choose the same mode more than once. - Create a 2/2 Citizen creature token that's all colors;
	// Return target permanent card from your graveyard to your hand; Proliferate; You gain 4 life.
	// Partial: the modes are chosen on resolution, one after another, and the permanent card isn't a target.
	m_Proliferate.AddProliferateTrigger();
	AddSorcery(this, _T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, &CPlanewideCelebrationCard::BeforeResolution);
}

bool CPlanewideCelebrationCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nModesLeft = 4;
	AskMode(pAction->GetController());
	return true;
}

void CPlanewideCelebrationCard::AskMode(CPlayer* pPlayer)
{
	LPCTSTR texts[] = { _T("Create a 2/2 Citizen creature token that's all colors"),
						_T("Return a permanent card from your graveyard to your hand"),
						_T("Proliferate"),
						_T("You gain 4 life") };
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 4; ++i)
	{
		SelectionEntry entry;
		entry.dwContext = i;
		entry.strText.Format(_T("%s (%d left)"), texts[i], m_nModesLeft);
		entries.push_back(entry);
	}
	m_ModeSelection.AddSelectionRequest(entries, 1, 1, this, pPlayer);
}

void CPlanewideCelebrationCard::OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int nMode = (int)it->dwContext;
			if (nMode == 0)
				CTokenCreationModifier(GetGame(), CITIZEN_B_TOKEN_NAME, CITIZEN_B_TOKEN_ID, 1).ApplyTo(pSelectionPlayer);
			else if (nMode == 1)
				ChooseAndMove(GetGame(), pSelectionPlayer, ZoneId::Graveyard, 0, 1, &m_PermanentFilter, ZoneId::Hand, MoveType::Others);
			else if (nMode == 2)
				m_Proliferate.Proliferate(pSelectionPlayer);
			else
				GainLife(this, pSelectionPlayer, 4);
		}

	if (--m_nModesLeft > 0)
		AskMode(pSelectionPlayer);
}

//____________________________________________________________________________
//
CPriceOfBetrayalCard::CPriceOfBetrayalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Price of Betrayal"), CardType::Sorcery, nID)
	, m_CounterSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPriceOfBetrayalCard::OnCountersSelected))
{
	// Remove up to five counters from target artifact, creature, planeswalker, or opponent.
	// Partial: only permanents (not the counters of the opponent).
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::Planeswalker, false), FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPriceOfBetrayalCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPriceOfBetrayalCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	// One entry for each counter (as CTargetCounterPumpSpell in the core)
	struct PushBack
	{
		PushBack(CCard* pCard) : m_pCard(pCard) {}
		void operator()(Counter* pCounter)
		{
			for (int i = 0; i < pCounter->GetCount(); ++i)
			{
				SelectionEntry entry;
				entry.dwContext = (DWORD)pCounter;
				entry.strText.Format(_T("Remove a %s from %s"), (LPCTSTR)pCounter->GetName(), m_pCard->GetCardName(TRUE));
				entries.push_back(entry);
			}
		}
		CCard* m_pCard;
		std::vector<SelectionEntry> entries;
	} push(pCard);

	std::vector<SelectionEntry> entries = pCard->GetCounterContainer()->ForEachCounter(push).entries;
	if (!entries.empty())
		m_CounterSelection.AddSelectionRequest(entries, 0, entries.size() < 5 ? (int)entries.size() : 5, this,
			pAction->GetController(), (DWORD)pCard);
	return false;
}

void CPriceOfBetrayalCard::OnCountersSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			Counter* pCounter = (Counter*)it->dwContext;
			CCardCounterModifier(pCounter->GetName(), -1).ApplyTo(pCard);
		}
}

//____________________________________________________________________________
//
CRavnicaAtWarCard::CRavnicaAtWarCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ravnica at War"), CardType::Sorcery, nID)
{
	// Exile all multicolored permanents.
	AddSorcery(this, _T("3") WHITE_MANA_TEXT, &CRavnicaAtWarCard::BeforeResolution);
}

bool CRavnicaAtWarCard::BeforeResolution(CAbilityAction* pAction)
{
	CardMulticoloredComparer multicolored;
	CCountedCardContainer cards;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (multicolored(pBattlefield->GetAt(i)))
				cards.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pExile.ApplyTo(cards.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CRelentlessAdvanceCard::CRelentlessAdvanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Relentless Advance"), CardType::Sorcery, nID)
{
	// Amass Zombies 3.
	AddSorcery(this, _T("3") BLUE_MANA_TEXT, &CRelentlessAdvanceCard::BeforeResolution);
}

bool CRelentlessAdvanceCard::BeforeResolution(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CRoleReversalCard::CRoleReversalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Role Reversal"), CardType::Sorcery, nID)
{
	// Exchange control of two target permanents that share a permanent type. (as Switcheroo in M13; the shared type is
	// checked on resolution)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLUE_MANA_TEXT RED_MANA_TEXT,
			new TrueCardComparer, FALSE,
			new TrueCardComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Neutral);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Neutral);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRoleReversalCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRoleReversalCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (!pCard1 || !pCard2 || pCard1 == pCard2)
		return false;

	CardType types[] = { CardType::Artifact, CardType::Creature, CardType::_Enchantment, CardType::_Land, CardType::Planeswalker };
	BOOL bShare = FALSE;
	for (int t = 0; t < 5 && !bShare; ++t)
	{
		CardTypeComparer comparer(types[t], false);
		bShare = comparer(pCard1) && comparer(pCard2);
	}
	if (!bShare)
		return false;

	CPlayer* pPlayer1 = pCard1->GetController();
	CPlayer* pPlayer2 = pCard2->GetController();
	if (pPlayer1 == pPlayer2)
		return false;
	CTransferControlModifier(GetGame(), pCard1, pCard1).ApplyTo(pPlayer2);
	CTransferControlModifier(GetGame(), pCard2, pCard2).ApplyTo(pPlayer1);
	return false;
}

//____________________________________________________________________________
//
CSingleCombatCard::CSingleCombatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Single Combat"), CardType::Sorcery, nID)
	, m_KeepSelection(pGame, CSelectionSupport::SelectionCallback(this, &CSingleCombatCard::OnKeepSelected))
	, m_CreaturePlaneswalkerFilter(_T("a creature or planeswalker spell"), _T("creature or planeswalker spells"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)))
{
	// Each player chooses a creature or planeswalker they control, then sacrifices the rest. Players can't cast creature
	// or planeswalker spells until the end of your next turn.
	// Partial: the spells can't be cast until the end of the next turn of the opponent.
	AddSorcery(this, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, &CSingleCombatCard::BeforeResolution);
}

bool CSingleCombatCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (!m_CreaturePlaneswalkerFilter.IsCardIncluded(pCard))
				continue;
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Keep %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
		if (entries.size() > 1)
			m_KeepSelection.AddSelectionRequest(entries, 1, 1, this, pPlayer);

		// Players can't cast creature or planeswalker spells
		int nFilter = (int)&m_CreaturePlaneswalkerFilter;
		CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, nFilter).ApplyTo(pPlayer);
		CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, nFilter),
			TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater,
			CScheduledPlayerModifier::DeltaOption::CustomPlayerTurn, GetGame()->GetNextPlayer(pController));
		pRemove.ApplyTo(pPlayer);
	}
	return true;
}

void CSingleCombatCard::OnKeepSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CMoveCardModifier pSacrifice = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (!it->bSelected && pCard->GetZoneId() == ZoneId::Battlefield)
			pSacrifice.ApplyTo(pCard);
	}
}

//____________________________________________________________________________
//
CSolarBlazeCard::CSolarBlazeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Solar Blaze"), CardType::Sorcery, nID)
{
	// Each creature deals damage to itself equal to its power.
	AddSorcery(this, _T("2") RED_MANA_TEXT WHITE_MANA_TEXT, &CSolarBlazeCard::BeforeResolution);
}

bool CSolarBlazeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), NULL, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
			DealDamageToCreature(pCreature, pCreature, GET_INTEGER(pCreature->GetPower()));
	}
	return true;
}

//____________________________________________________________________________
//
CSparkHarvestCard::CSparkHarvestCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spark Harvest"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, sacrifice a creature or pay {3}{B}. Destroy target creature or planeswalker.
	// (one spell for each additional cost)
	CTargetMoveCardSpell* pSpell1 = AddMoveSorcery(this, BLACK_MANA_TEXT,
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell1->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	pSpell1->SetAbilityText(_T("Sacrifice a creature. Casts"));

	CTargetMoveCardSpell* pSpell2 = AddMoveSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell2->SetAbilityText(_T("Pay {3}{B}. Casts"));
	pSpell2->SetMainSpell(FALSE);
}

//____________________________________________________________________________
//
CStealthMissionCard::CStealthMissionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stealth Mission"), CardType::Sorcery, nID)
{
	// Put two +1/+1 counters on target creature you control. That creature can't be blocked this turn.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("2") BLUE_MANA_TEXT, Characteristic::Positive, &CStealthMissionCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeControllerCardsOnly();
}

bool CStealthMissionCard::BeforeResolution(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(GetTargetCreature(pAction));
	if (pCreature)
	{
		AddPlusCounter(pCreature, 2);
		pCreature->GetCreatureKeyword()->AddUnblockable(TRUE);
	}
	return false;
}

//____________________________________________________________________________
//
CStormTheCitadelCard::CStormTheCitadelCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Storm the Citadel"), CardType::Sorcery, nID)
{
	// Until end of turn, creatures you control get +2/+2 and gain "Whenever this creature deals combat damage to a player
	// or planeswalker, destroy target artifact or enchantment defending player controls."
	// Partial: only the +2/+2 (the engine can't give triggered abilities to other creatures).
	AddSorcery(this, _T("4") GREEN_MANA_TEXT, &CStormTheCitadelCard::BeforeResolution);
}

bool CStormTheCitadelCard::BeforeResolution(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +2, +2);
	return true;
}

//____________________________________________________________________________
//
CTamiyosEpiphanyCard::CTamiyosEpiphanyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tamiyo's Epiphany"), CardType::Sorcery, nID)
{
	// Scry 4, then draw two cards.
	AddSorcery(this, _T("3") BLUE_MANA_TEXT, &CTamiyosEpiphanyCard::BeforeResolution);
}

bool CTamiyosEpiphanyCard::BeforeResolution(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 4, this).ApplyTo(pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CTheElderspellCard::CTheElderspellCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("The Elderspell"), CardType::Sorcery, nID)
	, m_PlaneswalkerSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTheElderspellCard::OnPlaneswalkerSelected))
{
	// Destroy any number of target planeswalkers. Choose a planeswalker you control. Put two loyalty counters on it for
	// each planeswalker destroyed this way.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Planeswalker, false), FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(0, 10);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheElderspellCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTheElderspellCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);

	int nDestroyed = 0;
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		DestroyPermanent(pCard, pController);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			++nDestroyed;
	}
	if (nDestroyed == 0)
		return false;

	std::vector<SelectionEntry> entries;
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsPlaneswalker())
			continue;
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %d loyalty counters on %s"), 2 * nDestroyed, pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_PlaneswalkerSelection.AddSelectionRequest(entries, 1, 1, this, pController, (DWORD)nDestroyed);
	return false;
}

void CTheElderspellCard::OnPlaneswalkerSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				CCardCounterModifier(LOYALTY_COUNTER, 2 * (int)dwContext1).ApplyTo(pCard);
		}
}

//____________________________________________________________________________
//
CTimeWipeCard::CTimeWipeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Time Wipe"), CardType::Sorcery, nID)
{
	// Return a creature you control to its owner's hand, then destroy all creatures.
	AddSorcery(this, _T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT BLUE_MANA_TEXT, &CTimeWipeCard::BeforeResolution);
}

bool CTimeWipeCard::BeforeResolution(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Hand, MoveType::Others);
	DestroyAll(GetGame(), AnyCreatureComparer());
	return true;
}

//____________________________________________________________________________
//
CTollOfTheInvasionCard::CTollOfTheInvasionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Toll of the Invasion"), CardType::Sorcery, nID)
	, m_NonlandFilter(_T("a nonland card"), _T("nonland cards"), new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Target opponent reveals their hand. You choose a nonland card from it. That player discards that card. Amass Zombies
	// 1. (as Dark Inquiry in Rivals of Ixalan)
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			1, MoveType::Discard, ZoneId::Graveyard, TRUE,
			FALSE,
			&m_NonlandFilter));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTollOfTheInvasionCard::BeforeAmass));
	AddSpell(cpSpell.GetPointer());
}

bool CTollOfTheInvasionCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CWanderersStrikeCard::CWanderersStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wanderer's Strike"), CardType::Sorcery, nID)
	, m_Proliferate(this)
{
	// Exile target creature, then proliferate.
	m_Proliferate.AddProliferateTrigger();
	AddCreatureSorcery(this, _T("4") WHITE_MANA_TEXT, Characteristic::Negative, &CWanderersStrikeCard::BeforeResolution);
}

bool CWanderersStrikeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	m_Proliferate.Proliferate(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CWidespreadBrutalityCard::CWidespreadBrutalityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Widespread Brutality"), CardType::Sorcery, nID)
{
	// Amass Zombies 2, then the Army you amassed deals damage equal to its power to each non-Army creature.
	AddSorcery(this, _T("1") BLACK_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, &CWidespreadBrutalityCard::BeforeResolution);
}

bool CWidespreadBrutalityCard::BeforeResolution(CAbilityAction* pAction)
{
	CCreatureCard* pArmy = dynamic_cast<CCreatureCard*>(Amass(this, pAction->GetController(), 2));
	if (!pArmy || pArmy->GetZoneId() != ZoneId::Battlefield)
		return true;

	int nPower = GET_INTEGER(pArmy->GetPower());
	if (nPower <= 0)
		return true;

	CreatureTypeComparer armyComparer(CREATURE_TYPE(Army), false);
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), NULL, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (!armyComparer(creatures.GetAt(i)) && creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			DealDamageToCreature(pArmy, creatures.GetAt(i), nPower);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define VITU_GHAZI_A_TOKEN_NAME		_T("Vitu-Ghazi (A)")
#define VITU_GHAZI_A_TOKEN_ID		64139

// Damage to any target: a player, a creature or a planeswalker (the planeswalkers lose loyalty)
static void DealDamageToAnyTarget(CCard* pSource, CAbilityAction* pAction, int nDamage)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DealDamageToPlayer(pSource, pPlayer, nDamage);
	else
		DealDamageToCreatureOrPlaneswalker(pSource, pAction->GetAssociatedCard(), nDamage);
}

//____________________________________________________________________________
//
CAwakeningOfVituGhaziCard::CAwakeningOfVituGhaziCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Awakening of Vitu-Ghazi"), CardType::Instant, nID)
{
	// Put nine +1/+1 counters on target land you control. It becomes a legendary 0/0 Elemental creature with haste named
	// Vitu-Ghazi. It's still a land. (as the lands of Nissa, Who Shakes the World)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false), FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAwakeningOfVituGhaziCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAwakeningOfVituGhaziCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (!pLand || pLand->GetZoneId() != ZoneId::Battlefield)
		return false;

	AddPlusCounter(pLand, 9);
	if (!pLand->GetIsAlsoA())
		CCardIsAlsoAModifier(VITU_GHAZI_A_TOKEN_NAME, VITU_GHAZI_A_TOKEN_ID, pAction->GetController()).ApplyTo(pLand);
	return false;
}

//____________________________________________________________________________
//
CBandTogetherCard::CBandTogetherCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Band Together"), CardType::Instant, nID)
{
	// Up to two target creatures you control each deal damage equal to their power to another target creature.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetSubjectCount(0, 2);
	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBandTogetherCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBandTogetherCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleAction)
		return false;

	CCountedCardContainer cards1, cards2;
	pDoubleAction->GetTargetGroup1().GetCardSubjects(cards1);
	pDoubleAction->GetTargetGroup2().GetCardSubjects(cards2);
	if (cards2.GetSize() == 0)
		return false;

	CCard* pTarget = cards2.GetAt(0);
	for (int i = 0; i < cards1.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(cards1.GetAt(i));
		if (pCreature && pCreature != pTarget && pCreature->GetZoneId() == ZoneId::Battlefield && pTarget->GetZoneId() == ZoneId::Battlefield)
			DealDamageToCreature(pCreature, pTarget, GET_INTEGER(pCreature->GetPower()));
	}
	return false;
}

//____________________________________________________________________________
//
CBattlefieldPromotionCard::CBattlefieldPromotionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Battlefield Promotion"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on target creature. That creature gains first strike until end of turn. You gain 2 life.
	AddCreatureInstant(this, _T("1") WHITE_MANA_TEXT, Characteristic::Positive, &CBattlefieldPromotionCard::BeforeResolution);
}

bool CBattlefieldPromotionCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		AddPlusCounter(pCard, 1);
		PumpCreature(pCard, 0, 0, CreatureKeyword::FirstStrike);
	}
	GainLife(this, pAction->GetController(), 2);
	return false;
}

//____________________________________________________________________________
//
CBlindblastCard::CBlindblastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blindblast"), CardType::Instant, nID)
{
	// Blindblast deals 1 damage to target creature. That creature can't block this turn. Draw a card.
	AddCreatureInstant(this, _T("2") RED_MANA_TEXT, Characteristic::Negative, &CBlindblastCard::BeforeResolution);
}

bool CBlindblastCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		DealDamageToCreature(this, pCard, 1);
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			PumpCreature(pCard, 0, 0, CreatureKeyword::CantBlock);
	}
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CBoltBendCard::CBoltBendCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bolt Bend"), CardType::Instant, nID)
{
	// This spell costs {3} less to cast if you control a creature with power 4 or greater. Change the target of target spell
	// or ability with a single target. (as Deflection; only spells. The reduced cost is a second spell, as Ghalta)
	counted_ptr<CDeflectionSpell> cpSpell(
		::CreateObject<CDeflectionSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT,
			new TrueCardComparer));
	AddSpell(cpSpell.GetPointer());
	AddPlayableIf(this, cpSpell.GetPointer(), &CBoltBendCard::CanCastFull);

	counted_ptr<CDeflectionSpell> cpReduced(
		::CreateObject<CDeflectionSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			new TrueCardComparer));
	cpReduced->SetMainSpell(FALSE);
	AddSpell(cpReduced.GetPointer());
	AddPlayableIf(this, cpReduced.GetPointer(), &CBoltBendCard::CanCastReduced);
}

BOOL CBoltBendCard::CanCastFull(BOOL bIncludeTricks)
{
	return !ControlsPowerFourCreature(GetController());
}

BOOL CBoltBendCard::CanCastReduced(BOOL bIncludeTricks)
{
	return ControlsPowerFourCreature(GetController());
}

//____________________________________________________________________________
//
CChandrasTriumphCard::CChandrasTriumphCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chandra's Triumph"), CardType::Instant, nID)
{
	// Chandra's Triumph deals 3 damage to target creature or planeswalker an opponent controls. Chandra's Triumph deals 5
	// damage instead if you control a Chandra planeswalker.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), FALSE));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandrasTriumphCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CChandrasTriumphCard::BeforeResolution(CAbilityAction* pAction)
{
	int nDamage = ControlsPlaneswalker(pAction->GetController(), PlaneswalkerType::Chandra) ? 5 : 3;
	DealDamageToCreatureOrPlaneswalker(this, pAction->GetAssociatedCard(), nDamage);
	return false;
}

//____________________________________________________________________________
//
CCommenceTheEndgameCard::CCommenceTheEndgameCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Commence the Endgame"), CardType::Instant, nID)
{
	// This spell can't be countered. Draw two cards, then amass Zombies X, where X is the number of cards in your hand.
	GetCardKeyword()->AddCantBeCountered(FALSE);
	AddInstant(this, _T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, &CCommenceTheEndgameCard::BeforeResolution);
}

bool CCommenceTheEndgameCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 2);
	Amass(this, pController, pController->GetZoneById(ZoneId::Hand)->GetSize());
	return true;
}

//____________________________________________________________________________
//
CCrushDissentCard::CCrushDissentCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Crush Dissent"), CardType::Instant, nID,
		_T("3") BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	// Counter target spell unless its controller pays {2}. Amass Zombies 2. (as Mana Leak)
	m_pCounterSpell->SetCanBeDenied();
	m_pCounterSpell->GetDenialCost().SetManaCost(_T("2"));
	m_pCounterSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrushDissentCard::BeforeAmass));
}

bool CCrushDissentCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CDeathsproutCard::CDeathsproutCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deathsprout"), CardType::Instant, nID)
{
	// Destroy target creature. Search your library for a basic land card, put it onto the battlefield tapped, then shuffle.
	AddCreatureInstant(this, _T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT GREEN_MANA_TEXT, Characteristic::Negative,
		&CDeathsproutCard::BeforeResolution);
}

bool CDeathsproutCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		DestroyPermanent(pCard, pAction->GetController());
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("basic lands")), TRUE);
	return false;
}

//____________________________________________________________________________
//
CDesparkCard::CDesparkCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Despark"), CardType::Instant, nID)
{
	// Exile target permanent with mana value 4 or greater.
	AddMoveInstant(this, WHITE_MANA_TEXT BLACK_MANA_TEXT, new ConvertedManaCostComparer<std::greater_equal<int>>(4),
		ZoneId::Exile, MoveType::Others);
}

//____________________________________________________________________________
//
CDesperateLungeCard::CDesperateLungeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Desperate Lunge"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 and gains flying until end of turn. You gain 2 life.
	AddCreatureInstant(this, _T("1") WHITE_MANA_TEXT, Characteristic::Positive, &CDesperateLungeCard::BeforeResolution);
}

bool CDesperateLungeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +2, +2, CreatureKeyword::Flying);
	GainLife(this, pAction->GetController(), 2);
	return false;
}

//____________________________________________________________________________
//
CDivineArrowCard::CDivineArrowCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Divine Arrow"), CardType::Instant, nID)
{
	// Divine Arrow deals 4 damage to target attacking or blocking creature.
	AddDamageInstant(this, _T("1") WHITE_MANA_TEXT, 4, new AttackingBlockingCreatureComparer, FALSE);
}

//____________________________________________________________________________
//
CDovinsVetoCard::CDovinsVetoCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Dovin's Veto"), CardType::Instant, nID,
		WHITE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Instant,
		new NegateCardComparer(new AnyCreatureComparer))
{
	// This spell can't be countered. Counter target noncreature spell.
	GetCardKeyword()->AddCantBeCountered(FALSE);
}

//____________________________________________________________________________
//
CForcedLandingCard::CForcedLandingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Forced Landing"), CardType::Instant, nID)
{
	// Put target creature with flying on the bottom of its owner's library.
	CTargetSpell* pSpell = AddCreatureInstant(this, _T("1") GREEN_MANA_TEXT, Characteristic::Negative,
		&CForcedLandingCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false));
}

bool CForcedLandingCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetToTop(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
CGideonsTriumphCard::CGideonsTriumphCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gideon's Triumph"), CardType::Instant, nID)
	, m_AttackedFilter(_T("a creature that attacked or blocked this turn"), _T("creatures that attacked or blocked this turn"),
		new AttackedOrBlockedThisTurnComparer)
{
	// Target opponent sacrifices a creature of their choice that attacked or blocked this turn. If you control a Gideon
	// planeswalker, that player sacrifices two of those creatures of their choice instead.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			new FalseCardComparer, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGideonsTriumphCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGideonsTriumphCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		int nCount = ControlsPlaneswalker(pAction->GetController(), PlaneswalkerType::Gideon) ? 2 : 1;
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, nCount, nCount, &m_AttackedFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	}
	return false;
}

//____________________________________________________________________________
//
CHeartfireCard::CHeartfireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Heartfire"), CardType::Instant, nID)
	, m_PlaneswalkerFilter(_T("a planeswalker"), _T("planeswalkers"), new CardTypeComparer(CardType::Planeswalker, false))
{
	// As an additional cost to cast this spell, sacrifice a creature or planeswalker. Heartfire deals 4 damage to any target.
	// (one spell for each kind of sacrifice)
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("1") RED_MANA_TEXT,
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), TRUE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		if (i == 0)
		{
			cpSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
			cpSpell->SetAbilityText(_T("Sacrifice a creature. Casts"));
		}
		else
		{
			cpSpell->GetCost().AddSacrificeCardCost(1, &m_PlaneswalkerFilter);
			cpSpell->SetAbilityText(_T("Sacrifice a planeswalker. Casts"));
			cpSpell->SetMainSpell(FALSE);
		}
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeartfireCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CHeartfireCard::BeforeResolution(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 4);
	return false;
}

//____________________________________________________________________________
//
CHeartwarmingRedemptionCard::CHeartwarmingRedemptionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Heartwarming Redemption"), CardType::Instant, nID)
{
	// Discard all the cards in your hand, then draw that many cards plus one. You gain life equal to the number of cards in
	// your hand.
	AddInstant(this, _T("2") RED_MANA_TEXT WHITE_MANA_TEXT, &CHeartwarmingRedemptionCard::BeforeResolution);
}

bool CHeartwarmingRedemptionCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	int nCount = pHand->GetSize();
	if (nCount > 0)
		DiscardCards(GetGame(), pController, nCount);
	DrawCards(GetGame(), pController, nCount + 1);
	GainLife(this, pController, pHand->GetSize());
	return true;
}

//____________________________________________________________________________
//
CIgniteTheBeaconCard::CIgniteTheBeaconCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ignite the Beacon"), CardType::Instant, nID)
	, m_PlaneswalkerFilter(_T("a planeswalker card"), _T("planeswalker cards"), new CardTypeComparer(CardType::Planeswalker, false))
{
	// Search your library for up to two planeswalker cards, reveal them, put them into your hand, then shuffle.
	AddInstant(this, _T("4") WHITE_MANA_TEXT, &CIgniteTheBeaconCard::BeforeResolution);
}

bool CIgniteTheBeaconCard::BeforeResolution(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 2, &m_PlaneswalkerFilter);
	return true;
}

//____________________________________________________________________________
//
CJayasGreetingCard::CJayasGreetingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Jaya's Greeting"), CardType::Instant, nID)
{
	// Jaya's Greeting deals 3 damage to target creature. Scry 1.
	AddCreatureInstant(this, _T("1") RED_MANA_TEXT, Characteristic::Negative, &CJayasGreetingCard::BeforeResolution);
}

bool CJayasGreetingCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		DealDamageToCreature(this, pCard, 3);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CLazotepPlatingCard::CLazotepPlatingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lazotep Plating"), CardType::Instant, nID)
{
	// Amass Zombies 1. You and permanents you control gain hexproof until end of turn.
	// (only the permanents you control on resolution)
	AddInstant(this, _T("1") BLUE_MANA_TEXT, &CLazotepPlatingCard::BeforeResolution);
}

bool CLazotepPlatingCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Amass(this, pController, 1);

	CCountedCardContainer cards;
	GetPermanents(pController, TrueCardComparer(), cards);
	for (int i = 0; i < cards.GetSize(); ++i)
		GainCardKeyword(cards.GetAt(i), CardKeyword::Hexproof);

	// You gain hexproof until end of turn (as Leyline of Sanctity)
	PlayerEffectType effects[] = { PlayerEffectType::CantBeTargetedByOpponentsSpells, PlayerEffectType::CantBeTargetedByOpponentsAbilities };
	for (int i = 0; i < 2; ++i)
	{
		CScheduledPlayerModifier pModifier = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(effects[i]),
			TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::ApplyToNowRemoveLater);
		pModifier.ApplyTo(pController);
	}
	return true;
}

//____________________________________________________________________________
//
CLilianasTriumphCard::CLilianasTriumphCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Liliana's Triumph"), CardType::Instant, nID)
{
	// Each opponent sacrifices a creature of their choice. If you control a Liliana planeswalker, each opponent also
	// discards a card.
	AddInstant(this, _T("1") BLACK_MANA_TEXT, &CLilianasTriumphCard::BeforeResolution);
}

bool CLilianasTriumphCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	BOOL bLiliana = ControlsPlaneswalker(pController, PlaneswalkerType::Liliana);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")), ZoneId::Graveyard, MoveType::Sacrifice);
		if (bLiliana)
			DiscardCards(GetGame(), pPlayer, 1);
	}
	return true;
}

//____________________________________________________________________________
//
CNahirisStonebladesCard::CNahirisStonebladesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nahiri's Stoneblades"), CardType::Instant, nID)
{
	// Up to two target creatures each get +2/+0 until end of turn.
	CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, _T("1") RED_MANA_TEXT, +2, +0);
	pSpell->GetTargeting()->SetSubjectCount(0, 2);
}

//____________________________________________________________________________
//
CNoEscapeCard::CNoEscapeCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("No Escape"), CardType::Instant, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Instant,
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)))
{
	// Counter target creature or planeswalker spell. If that spell is countered this way, exile it instead of putting it
	// into its owner's graveyard. Scry 1. (as Dissipate)
	m_pCounterSpell->SetToZone(ZoneId::Exile, TRUE);
	m_pCounterSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(GetGame(), 1, this));
}

//____________________________________________________________________________
//
CObNixilissCrueltyCard::CObNixilissCrueltyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ob Nixilis's Cruelty"), CardType::Instant, nID)
{
	// Target creature gets -5/-5 until end of turn. If that creature would die this turn, exile it instead.
	// (as Necrotic Wound in Guilds of Ravnica)
	AddCreatureInstant(this, _T("2") BLACK_MANA_TEXT, Characteristic::Negative, &CObNixilissCrueltyCard::BeforeResolution);
}

bool CObNixilissCrueltyCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CReplacementKeywordModifier pModifier;
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	pModifier.ApplyTo(pCard);

	PumpCreature(pCard, -5, -5);
	return false;
}

//____________________________________________________________________________
//
CPledgeOfUnityCard::CPledgeOfUnityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pledge of Unity"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on each creature you control. You gain 1 life for each creature you control.
	AddInstant(this, _T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, &CPledgeOfUnityCard::BeforeResolution);
}

bool CPledgeOfUnityCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i), 1);
	if (creatures.GetSize() > 0)
		GainLife(this, pAction->GetController(), creatures.GetSize());
	return true;
}

//____________________________________________________________________________
//
CRallyOfWingsCard::CRallyOfWingsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rally of Wings"), CardType::Instant, nID)
{
	// Untap all creatures you control. Creatures you control with flying get +2/+2 until end of turn.
	AddInstant(this, _T("1") WHITE_MANA_TEXT, &CRallyOfWingsCard::BeforeResolution);
}

bool CRallyOfWingsCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		pUntap.ApplyTo(pCreature);
		if (pCreature->GetCreatureKeyword()->Flying())
			PumpCreature(pCreature, +2, +2);
	}
	return true;
}

//____________________________________________________________________________
//
CRalsOutburstCard::CRalsOutburstCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ral's Outburst"), CardType::Instant, nID)
{
	// Ral's Outburst deals 3 damage to any target. Look at the top two cards of your library. Put one of them into your hand
	// and the other into your graveyard. (as Ral, Izzet Viceroy)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT RED_MANA_TEXT,
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRalsOutburstCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRalsOutburstCard::BeforeResolution(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 3);

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 2, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::PrimaryPlayer, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Hand, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.SetReorderInformation(true, ZoneId::Graveyard, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CReturnToNatureCard::CReturnToNatureCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Return to Nature"), CardType::Instant, nID)
{
	// Choose one - Destroy target artifact; Destroy target enchantment; Exile target card from a graveyard.
	CTargetMoveCardSpell* pSpell1 = AddMoveInstant(this, _T("1") GREEN_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact, false), ZoneId::Graveyard, MoveType::Destroy);
	pSpell1->SetAbilityText(_T("Destroy target artifact. Casts"));

	CTargetMoveCardSpell* pSpell2 = AddMoveInstant(this, _T("1") GREEN_MANA_TEXT,
		new CardTypeComparer(CardType::_Enchantment, false), ZoneId::Graveyard, MoveType::Destroy);
	pSpell2->SetAbilityText(_T("Destroy target enchantment. Casts"));
	pSpell2->SetMainSpell(FALSE);

	counted_ptr<CTargetMoveCardSpell> cpSpell3(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell3->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell3->SetAbilityText(_T("Exile target card from a graveyard. Casts"));
	cpSpell3->SetMainSpell(FALSE);
	AddSpell(cpSpell3.GetPointer());
}

//____________________________________________________________________________
//
CSamutsSprintCard::CSamutsSprintCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Samut's Sprint"), CardType::Instant, nID)
{
	// Target creature gets +2/+1 and gains haste until end of turn. Scry 1.
	AddCreatureInstant(this, RED_MANA_TEXT, Characteristic::Positive, &CSamutsSprintCard::BeforeResolution);
}

bool CSamutsSprintCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +2, +1, CreatureKeyword::Haste);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CSarkhansCatharsisCard::CSarkhansCatharsisCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sarkhan's Catharsis"), CardType::Instant, nID)
{
	// Sarkhan's Catharsis deals 5 damage to target player or planeswalker.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("4") RED_MANA_TEXT,
			new CardTypeComparer(CardType::Planeswalker, false), TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSarkhansCatharsisCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSarkhansCatharsisCard::BeforeResolution(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 5);
	return false;
}

//____________________________________________________________________________
//
CSteadyAimCard::CSteadyAimCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Steady Aim"), CardType::Instant, nID)
{
	// Untap target creature. It gets +1/+4 and gains reach until end of turn.
	AddCreatureInstant(this, _T("1") GREEN_MANA_TEXT, Characteristic::Positive, &CSteadyAimCard::BeforeResolution);
}

bool CSteadyAimCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		CCardOrientationModifier(FALSE).ApplyTo(pCard);
		PumpCreature(pCard, +1, +4, CreatureKeyword::Reach);
	}
	return false;
}

//____________________________________________________________________________
//
CTeferisTimeTwistCard::CTeferisTimeTwistCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Teferi's Time Twist"), CardType::Instant, nID)
{
	// Exile target permanent you control. Return that card to the battlefield under its owner's control at the beginning of
	// the next end step. If it enters as a creature, it enters with an additional +1/+1 counter on it.
	// Partial: without the additional +1/+1 counter. (the return as Nezahal, Primal Tide)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new TrueCardComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTeferisTimeTwistCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTeferisTimeTwistCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Exile)
		return false;

	CMoveCardModifier* pReturn = new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others);
	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(), pReturn,
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CToppleTheStatueCard::CToppleTheStatueCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Topple the Statue"), CardType::Instant, nID)
{
	// Tap target permanent. If it's an artifact, destroy it. Draw a card.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new TrueCardComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CToppleTheStatueCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CToppleTheStatueCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
		if (CardTypeComparer(CardType::Artifact, false)(pCard))
			DestroyPermanent(pCard, pAction->GetController());
	}
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
CTyrantsScornCard::CTyrantsScornCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tyrant's Scorn"), CardType::Instant, nID)
{
	// Choose one - Destroy target creature with mana value 3 or less; Return target creature to its owner's hand.
	CTargetMoveCardSpell* pSpell1 = AddMoveInstant(this, BLUE_MANA_TEXT BLACK_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::less_equal<int>>(3)),
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell1->SetAbilityText(_T("Destroy target creature with mana value 3 or less. Casts"));

	CTargetMoveCardSpell* pSpell2 = AddMoveInstant(this, BLUE_MANA_TEXT BLACK_MANA_TEXT,
		new AnyCreatureComparer, ZoneId::Hand, MoveType::Others);
	pSpell2->SetAbilityText(_T("Return target creature to its owner's hand. Casts"));
	pSpell2->SetMainSpell(FALSE);
}

//____________________________________________________________________________
//
CUnlikelyAidCard::CUnlikelyAidCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unlikely Aid"), CardType::Instant, nID)
{
	// Target creature gets +2/+0 and gains indestructible until end of turn.
	AddCreatureInstant(this, _T("1") BLACK_MANA_TEXT, Characteristic::Positive, &CUnlikelyAidCard::BeforeResolution);
}

bool CUnlikelyAidCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
	{
		PumpCreature(pCard, +2, +0);
		GainCardKeyword(pCard, CardKeyword::Indestructible);
	}
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define ZOMBIE_WARRIOR_A_TOKEN_NAME		_T("Zombie Warrior (A)")
#define ZOMBIE_WARRIOR_A_TOKEN_ID		55135

//____________________________________________________________________________
//
CBulwarkGiantCard::CBulwarkGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bulwark Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Soldier), nID,
		_T("5") WHITE_MANA_TEXT, Power(3), Life(6))
{
	// When this creature enters, you gain 5 life.
	AddEnterTrigger(this, &CBulwarkGiantCard::BeforeGainLife);
}

bool CBulwarkGiantCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 5);
	return true;
}

//____________________________________________________________________________
//
CCharmedStrayCard::CCharmedStrayCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charmed Stray"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, put a +1/+1 counter on each other creature you control named Charmed Stray.
	AddEnterTrigger(this, &CCharmedStrayCard::BeforeCounters);
}

bool CCharmedStrayCard::BeforeCounters(CAbilityAction* pAction)
{
	CardNameComparer nameComparer(_T("Charmed Stray"));
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this && nameComparer(creatures.GetAt(i)))
			AddPlusCounter(creatures.GetAt(i), 1);
	return true;
}

//____________________________________________________________________________
//
CEnforcerGriffinCard::CEnforcerGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Enforcer Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
}

//____________________________________________________________________________
//
CGideonsCompanyCard::CGideonsCompanyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gideon's Company"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Whenever you gain life, put two +1/+1 counters on this creature. (as Ajani's Pridemate)
	{
		typedef
			TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +2));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGideonsCompanyCard::SetLifeGainContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}

	// {3}{W}: Put a loyalty counter on target Gideon planeswalker.
	{
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("3") WHITE_MANA_TEXT,
				new AndCardComparer(new CardTypeComparer(CardType::Planeswalker, false),
					new PlaneswalkerTypeComparer(PlaneswalkerType::Gideon)), FALSE));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(LOYALTY_COUNTER, +1));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGideonsCompanyCard::SetLifeGainContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

//____________________________________________________________________________
//
CGodEternalOketraCard::CGodEternalOketraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("God-Eternal Oketra"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Zombie, God), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(6))
{
	// Double strike
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// Whenever you cast a creature spell, create a 4/4 black Zombie Warrior creature token with vigilance.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodEternalOketraCard::BeforeZombie));
		AddAbility(cpAbility.GetPointer());
	}

	// When God-Eternal Oketra dies or is put into exile from the battlefield, you may put it into its owner's library third
	// from the top. (as Teferi, Hero of Dominaria -3)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGodEternalOketraCard::SetLeaveContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodEternalOketraCard::BeforeThirdFromTop));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGodEternalOketraCard::BeforeZombie(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ZOMBIE_WARRIOR_A_TOKEN_NAME, ZOMBIE_WARRIOR_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CGodEternalOketraCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pToZone && (pToZone->GetZoneId() == ZoneId::Graveyard || pToZone->GetZoneId() == ZoneId::Exile);
}

bool CGodEternalOketraCard::BeforeThirdFromTop(CAbilityAction* pAction)
{
	ZoneId zone = GetZoneId();
	if (zone != ZoneId::Graveyard && zone != ZoneId::Exile)
		return true;

	CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
	CCountedCardContainer above;	// the cards that will be over it (the second from the top first)
	for (int i = 1; i >= 0; --i)
		if (pLibrary->GetSize() > i)
			above.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(zone, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(this);

	if (GetZoneId() == ZoneId::Library && above.GetSize() > 0)
		pLibrary->ReorderCards(above, CardPlacement::Top);
	return true;
}

//____________________________________________________________________________
//
CGratefulApparitionCard::CGratefulApparitionCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Grateful Apparition"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1))
	, m_Proliferate(this)
{
	m_Proliferate.AddProliferateTrigger();

	// Whenever this creature deals combat damage to a player or planeswalker, proliferate. (as Silent Submersible)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGratefulApparitionCard::BeforeProliferate));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlaneswalkerEventCallback,
							   &CWhenSelfDamageDealt::SetPlaneswalkerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGratefulApparitionCard::BeforeProliferate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGratefulApparitionCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CIroncladKrovodCard::CIroncladKrovodCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ironclad Krovod"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(5))
{
}

//____________________________________________________________________________
//
CLawRuneEnforcerCard::CLawRuneEnforcerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Law-Rune Enforcer"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		WHITE_MANA_TEXT, Power(1), Life(2))
{
	// {1}, {T}: Tap target creature with mana value 2 or greater.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("1"),
			new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::greater_equal<int>>(2)), FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CLoxodonSergeantCard::CLoxodonSergeantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loxodon Sergeant"), CardType::Creature, CREATURE_TYPE2(Elephant, Soldier), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, other creatures you control gain vigilance until end of turn.
	AddEnterTrigger(this, &CLoxodonSergeantCard::BeforeVigilance);
}

bool CLoxodonSergeantCard::BeforeVigilance(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::Vigilance);
	return true;
}

//____________________________________________________________________________
//
CMakeshiftBattalionCard::CMakeshiftBattalionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Makeshift Battalion"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Battalion - Whenever this creature and at least two other creatures attack, put a +1/+1 counter on this creature.
	// (as Boros Elite in Gatecrash)
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMakeshiftBattalionCard::SetTriggerContext));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	cpAbility->SetAbilityName(_T("Battalion ability"));
	AddAbility(cpAbility.GetPointer());
}

bool CMakeshiftBattalionCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
	AttackSubject attacked) const
{
	int nOtherAttackingCreatures = 0;
	CCardFilter filter;
	filter.SetComparer(new AttackingCreatureComparer);
	filter.AddNegateComparer(new SpecificCardComparer(this));

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		nOtherAttackingCreatures += filter.CountIncluded(GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield)->GetCardContainer());

	return nOtherAttackingCreatures >= 2;
}

//____________________________________________________________________________
//
CMartyrForTheCauseCard::CMartyrForTheCauseCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Martyr for the Cause"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Proliferate(this)
{
	m_Proliferate.AddProliferateTrigger();

	// When this creature dies, proliferate.
	AddDiesTrigger(this, &CMartyrForTheCauseCard::BeforeProliferate);
}

bool CMartyrForTheCauseCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CPouncingLynxCard::CPouncingLynxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pouncing Lynx"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
	, m_DuringYourTurn(this)
{
	// During your turn, this creature has first strike.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::FirstStrike));
	AddAbility(cpAbility.GetPointer());
	m_DuringYourTurn.Add(cpAbility.GetPointer());
	m_DuringYourTurn.AddTurnTriggers();
}

//____________________________________________________________________________
//
CRisingPopulaceCard::CRisingPopulaceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rising Populace"), CardType::Creature, CREATURE_TYPE(Human), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever another creature or planeswalker you control dies, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRisingPopulaceCard::SetDiesContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRisingPopulaceCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CRisingPopulaceCard::SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard != this;
}

bool CRisingPopulaceCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CSunbladeAngelCard::CSunbladeAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sunblade Angel"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("5") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Flying, first strike, vigilance, lifelink
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

//____________________________________________________________________________
//
CTeyosLightshieldCard::CTeyosLightshieldCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Teyo's Lightshield"), CardType::Creature, CREATURE_TYPE(Illusion), nID,
		_T("2") WHITE_MANA_TEXT, Power(0), Life(3))
{
	// When this creature enters, put a +1/+1 counter on target creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CTeyosLightshieldCard::BeforeCounter, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CTeyosLightshieldCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

//____________________________________________________________________________
//
CTomikDistinguishedAdvokistCard::CTomikDistinguishedAdvokistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Tomik, Distinguished Advokist"), CardType::Creature | CardType::Legendary,
		CREATURE_TYPE2(Human, Advisor), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Flying
	// Lands on the battlefield and land cards in graveyards can't be the targets of spells or abilities your opponents
	// control. Your opponents can't play land cards from graveyards.
	// Partial: only the flying creature (the engine can't protect lands or graveyard cards from targeting, nor stop the
	// opponents playing lands from graveyards).
}

//____________________________________________________________________________
//
CTrustedPegasusCard::CTrustedPegasusCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Trusted Pegasus"), CardType::Creature, CREATURE_TYPE(Pegasus), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, target attacking creature without flying gains flying until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CTrustedPegasusCard::BeforeFlying, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->GetSubjectCardFilter().AddComparer(
		new NegateCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false)));
}

bool CTrustedPegasusCard::BeforeFlying(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, 0, 0, CreatureKeyword::Flying);
	return false;
}

//____________________________________________________________________________
//
CWarScreecherCard::CWarScreecherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("War Screecher"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(3))
{
	// {5}{W}, {T}: Other creatures you control get +1/+1 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("5") WHITE_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Other creatures you control get +1/+1 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWarScreecherCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CWarScreecherCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			PumpCreature(creatures.GetAt(i), +1, +1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CArborealGrazerCard::CArborealGrazerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Arboreal Grazer"), CardType::Creature, CREATURE_TYPE2(Sloth, Beast), nID,
		GREEN_MANA_TEXT, Power(0), Life(3))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// When this creature enters, you may put a land card from your hand onto the battlefield tapped.
	AddEnterTrigger(this, &CArborealGrazerCard::BeforeLand, true);
}

bool CArborealGrazerCard::BeforeLand(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCardFilter* pLands = CCardFilter::GetFilter(_T("lands"));
	if (pLands->CountIncluded(pController->GetZoneById(ZoneId::Hand)->GetCardContainer()) == 0)
		return true;

	// (as Neoform, keeping the card to tap it)
	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::PrimaryPlayer, pLands,
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			CCardOrientationModifier(TRUE).ApplyTo(cards.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CArlinnsWolfCard::CArlinnsWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Arlinn's Wolf"), CardType::Creature, CREATURE_TYPE(Wolf), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 2 or less. (the filter has the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

//____________________________________________________________________________
//
CBloomHulkCard::CBloomHulkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloom Hulk"), CardType::Creature, CREATURE_TYPE2(Plant, Elemental), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(4))
	, m_Proliferate(this)
{
	// When this creature enters, proliferate.
	m_Proliferate.AddProliferateTrigger();
	AddEnterTrigger(this, &CBloomHulkCard::BeforeProliferate);
}

bool CBloomHulkCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CCentaurNurturerCard::CCentaurNurturerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Centaur Nurturer"), CardType::Creature, CREATURE_TYPE2(Centaur, Druid), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, you gain 3 life.
	AddEnterTrigger(this, &CCentaurNurturerCard::BeforeGainLife);

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);
}

bool CCentaurNurturerCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CChallengerTrollCard::CChallengerTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Challenger Troll"), CardType::Creature, CREATURE_TYPE(Troll), nID,
		_T("4") GREEN_MANA_TEXT, Power(6), Life(5))
{
	// Each creature you control with power 4 or greater can't be blocked by more than one creature.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)),
			Power(+0), Life(+0), CreatureKeyword::CantBeBlockedByMultiple));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CEvolutionSageCard::CEvolutionSageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Evolution Sage"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_Proliferate(this)
{
	m_Proliferate.AddProliferateTrigger();

	// Landfall - Whenever a land you control enters, proliferate.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEvolutionSageCard::BeforeProliferate));
	AddAbility(cpAbility.GetPointer());
}

bool CEvolutionSageCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CGodEternalRhonasCard::CGodEternalRhonasCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("God-Eternal Rhonas"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Zombie, God), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// When God-Eternal Rhonas enters, double the power of each other creature you control until end of turn. Those
	// creatures gain vigilance until end of turn.
	AddEnterTrigger(this, &CGodEternalRhonasCard::BeforeDouble);

	// When God-Eternal Rhonas dies or is put into exile from the battlefield, you may put it into its owner's library third
	// from the top. (as God-Eternal Oketra)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGodEternalRhonasCard::SetLeaveContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodEternalRhonasCard::BeforeThirdFromTop));
	AddAbility(cpAbility.GetPointer());
}

bool CGodEternalRhonasCard::BeforeDouble(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (!pCreature || pCreature == this)
			continue;
		int nPower = GET_INTEGER(pCreature->GetPower());
		PumpCreature(pCreature, nPower > 0 ? nPower : 0, 0, CreatureKeyword::Vigilance);
	}
	return true;
}

bool CGodEternalRhonasCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pToZone && (pToZone->GetZoneId() == ZoneId::Graveyard || pToZone->GetZoneId() == ZoneId::Exile);
}

bool CGodEternalRhonasCard::BeforeThirdFromTop(CAbilityAction* pAction)
{
	ZoneId zone = GetZoneId();
	if (zone != ZoneId::Graveyard && zone != ZoneId::Exile)
		return true;

	CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
	CCountedCardContainer above;	// the cards that will be over it (the second from the top first)
	for (int i = 1; i >= 0; --i)
		if (pLibrary->GetSize() > i)
			above.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(zone, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(this);

	if (GetZoneId() == ZoneId::Library && above.GetSize() > 0)
		pLibrary->ReorderCards(above, CardPlacement::Top);
	return true;
}

//____________________________________________________________________________
//
CKraulStingerCard::CKraulStingerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kraul Stinger"), CardType::Creature, CREATURE_TYPE2(Insect, Assassin), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);
}

//____________________________________________________________________________
//
CKronchWranglerCard::CKronchWranglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kronch Wrangler"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever a creature you control with power 4 or greater enters, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKronchWranglerCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CKronchWranglerCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CMowuLoyalCompanionCard::CMowuLoyalCompanionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mowu, Loyal Companion"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Dog), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
	, m_bAddingExtra(FALSE)
{
	// Vigilance, trample
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// If one or more +1/+1 counters would be put on Mowu, that many plus one +1/+1 counters are put on it instead.
	// Partial: there are no replacement effects on counters; a trigger puts the extra counter after them (as Fathom Mage).
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCounterMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetOnIncreaseOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMowuLoyalCompanionCard::SetCounterContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMowuLoyalCompanionCard::BeforeExtraCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CMowuLoyalCompanionCard::SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	// (the extra counter of this ability doesn't trigger it again)
	return !m_bAddingExtra && pFromCard == this && n_value > old && CString(name) == _T("+1/+1");
}

bool CMowuLoyalCompanionCard::BeforeExtraCounter(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;
	m_bAddingExtra = TRUE;
	AddPlusCounter(this, 1);
	m_bAddingExtra = FALSE;
	return true;
}

//____________________________________________________________________________
//
CParadiseDruidCard::CParadiseDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Paradise Druid"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1))
{
	// This creature has hexproof as long as it's untapped. (as Slippery Scoundrel)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new NegateCardComparer(new TappedComparer)),
			Power(+0), Life(+0), CreatureKeyword::Null));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	AddAbility(cpAbility.GetPointer());

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);
}

//____________________________________________________________________________
//
CPollenbrightDruidCard::CPollenbrightDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pollenbright Druid"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(1))
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPollenbrightDruidCard::OnModeSelected))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPollenbrightDruidCard::OnCreatureSelected))
	, m_Proliferate(this)
{
	// When this creature enters, choose one - Put a +1/+1 counter on target creature; Proliferate.
	// Partial: the mode and the creature are chosen on resolution (the creature isn't a target).
	m_Proliferate.AddProliferateTrigger();
	AddEnterTrigger(this, &CPollenbrightDruidCard::BeforeMode);
}

bool CPollenbrightDruidCard::BeforeMode(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText = _T("Put a +1/+1 counter on a creature");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Proliferate");
		entries.push_back(entry);
	}
	m_ModeSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CPollenbrightDruidCard::OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;
		if (it->dwContext == 1)
		{
			m_Proliferate.Proliferate(pSelectionPlayer);
			continue;
		}

		CCountedCardContainer creatures;
		GetCreatures(GetGame(), NULL, FALSE, creatures);
		std::vector<SelectionEntry> entries;
		for (int i = 0; i < creatures.GetSize(); ++i)
		{
			SelectionEntry entry;
			entry.dwContext = (DWORD)creatures.GetAt(i);
			entry.cpAssociatedCard = creatures.GetAt(i);
			entry.strText.Format(_T("Put a +1/+1 counter on %s"), creatures.GetAt(i)->GetCardName(TRUE));
			entries.push_back(entry);
		}
		if (!entries.empty())
			m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pSelectionPlayer);
	}
}

void CPollenbrightDruidCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				AddPlusCounter(pCard, 1);
		}
}

//____________________________________________________________________________
//
CSnarespinnerCard::CSnarespinnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Snarespinner"), CardType::Creature, CREATURE_TYPE(Spider), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// Whenever this creature blocks a creature with flying, this creature gets +2/+0 until end of turn. (as Illusion (D))
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSnarespinnerCard::SetBlockContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSnarespinnerCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CSnarespinnerCard::SetBlockContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature1, CCreatureCard* pCreature2, int n1, int n2) const
{
	// The blocked creature is the one that isn't this creature
	CCreatureCard* pBlocked = (pCreature1 != this) ? pCreature1 : pCreature2;
	return pBlocked && pBlocked != this && pBlocked->GetCreatureKeyword()->Flying();
}

bool CSnarespinnerCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +0);
	return true;
}

//____________________________________________________________________________
//
CThunderingCeratokCard::CThunderingCeratokCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thundering Ceratok"), CardType::Creature, CREATURE_TYPE(Rhino), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(5))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, other creatures you control gain trample until end of turn.
	AddEnterTrigger(this, &CThunderingCeratokCard::BeforeTrample);
}

bool CThunderingCeratokCard::BeforeTrample(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::Trample);
	return true;
}

//____________________________________________________________________________
//
CViviensGrizzlyCard::CViviensGrizzlyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vivien's Grizzly"), CardType::Creature, CREATURE_TYPE2(Bear, Spirit), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
	, m_CreaturePlaneswalkerFilter(_T("a creature or planeswalker card"), _T("creature or planeswalker cards"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)))
{
	// {3}{G}: Look at the top card of your library. If it's a creature or planeswalker card, you may reveal it and put it
	// into your hand. If you don't put the card into your hand, put it on the bottom of your library.
	AddSelfAbility(this, _T("3") GREEN_MANA_TEXT,
		_T("Look at the top card of your library; a creature or planeswalker card may go to your hand. Activates"),
		&CViviensGrizzlyCard::BeforeLook);
}

bool CViviensGrizzlyCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 1, 0, 1, &m_CreaturePlaneswalkerFilter);
	return true;
}

//____________________________________________________________________________
//
CWardscaleCrocodileCard::CWardscaleCrocodileCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wardscale Crocodile"), CardType::Creature, CREATURE_TYPE(Crocodile), nID,
		_T("4") GREEN_MANA_TEXT, Power(5), Life(3))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// "When this creature dies, <effect on target>" (the callback does the effect and returns false)
template <class T>
static CTargeting* AddDiesTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

//____________________________________________________________________________
//
CAhnCropInvaderCard::CAhnCropInvaderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ahn-Crop Invader"), CardType::Creature, CREATURE_TYPE3(Zombie, Minotaur, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
	, m_DuringYourTurn(this)
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// During your turn, this creature has first strike.
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::FirstStrike));
		AddAbility(cpAbility.GetPointer());
		m_DuringYourTurn.Add(cpAbility.GetPointer());
		m_DuringYourTurn.AddTurnTriggers();
	}

	// {1}, Sacrifice another creature: This creature gets +2/+0 until end of turn.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));

		cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
		cpAbility->SetAbilityText(_T("This creature gets +2/+0 until end of turn. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAhnCropInvaderCard::BeforePump));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAhnCropInvaderCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +0);
	return true;
}

//____________________________________________________________________________
//
CBurningProphetCard::CBurningProphetCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Burning Prophet"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// Whenever you cast a noncreature spell, this creature gets +1/+0 until end of turn, then scry 1.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBurningProphetCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CBurningProphetCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +0);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CChainwhipCyclopsCard::CChainwhipCyclopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Chainwhip Cyclops"), CardType::Creature, CREATURE_TYPE2(Cyclops, Warrior), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(4))
{
	// {3}{R}: Target creature can't block this turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("3") RED_MANA_TEXT, new AnyCreatureComparer, FALSE));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChainwhipCyclopsCard::BeforeCantBlock));
	AddAbility(cpAbility.GetPointer());
}

bool CChainwhipCyclopsCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, 0, 0, CreatureKeyword::CantBlock);
	return false;
}

//____________________________________________________________________________
//
CCyclopsElectromancerCard::CCyclopsElectromancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cyclops Electromancer"), CardType::Creature, CREATURE_TYPE2(Cyclops, Wizard), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(2))
{
	// When this creature enters, it deals X damage to target creature an opponent controls, where X is the number of
	// instant and sorcery cards in your graveyard.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CCyclopsElectromancerCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CCyclopsElectromancerCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nX = CCardFilter::GetFilter(_T("instant cards or sorcery cards"))->CountIncluded(pGraveyard->GetCardContainer());
	if (nX > 0)
		DealDamageToCreature(this, pCard, nX);
	return false;
}

//____________________________________________________________________________
//
CDevouringHellionCard::CDevouringHellionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Devouring Hellion"), CardType::Creature, CREATURE_TYPE(Hellion), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
	, m_SacrificeFilter(_T("another creature or planeswalker"), _T("other creatures or planeswalkers"),
		new AndCardComparer(new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
			new NegateCardComparer(new SpecificCardComparer(this))))
{
	// As this creature enters, you may sacrifice any number of creatures and/or planeswalkers. If you do, it enters with
	// twice that many +1/+1 counters on it.
	// Partial: it's a trigger when it enters (the counters are put after it enters).
	AddEnterTrigger(this, &CDevouringHellionCard::BeforeSacrifice, true);
}

bool CDevouringHellionCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	int nBefore = m_SacrificeFilter.CountIncluded(pBattlefield->GetCardContainer());
	if (nBefore == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 0, nBefore, &m_SacrificeFilter, ZoneId::Graveyard, MoveType::Sacrifice);

	int nSacrificed = nBefore - m_SacrificeFilter.CountIncluded(pBattlefield->GetCardContainer());
	if (nSacrificed > 0 && GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 2 * nSacrificed);
	return true;
}

//____________________________________________________________________________
//
CDreadhordeTwinsCard::CDreadhordeTwinsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dreadhorde Twins"), CardType::Creature, CREATURE_TYPE3(Zombie, Jackal, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, amass Zombies 2.
	AddEnterTrigger(this, &CDreadhordeTwinsCard::BeforeAmass);

	// Zombie tokens you control have trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false), new CardTypeComparer(CardType::Token, false)),
			Power(+0), Life(+0), CreatureKeyword::Trample));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool CDreadhordeTwinsCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CGoblinAssailantCard::CGoblinAssailantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Assailant"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
}

//____________________________________________________________________________
//
CGoblinAssaultTeamCard::CGoblinAssaultTeamCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Assault Team"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(1))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature dies, put a +1/+1 counter on target creature you control.
	CTargeting* pTargeting = AddDiesTargetTrigger(this, &CGoblinAssaultTeamCard::BeforeCounter, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CGoblinAssaultTeamCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

//____________________________________________________________________________
//
CGrimInitiateCard::CGrimInitiateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grim Initiate"), CardType::Creature, CREATURE_TYPE2(Zombie, Warrior), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature dies, amass Zombies 1.
	AddDiesTrigger(this, &CGrimInitiateCard::BeforeAmass);
}

bool CGrimInitiateCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CIlhargTheRazeBoarCard::CIlhargTheRazeBoarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ilharg, the Raze-Boar"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Boar, God), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(6))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever Ilharg attacks, you may put a creature card from your hand onto the battlefield tapped and attacking. Return
	// that creature to your hand at the beginning of the next end step.
	// Partial: the creature enters tapped but not attacking (a card can't enter the battlefield attacking).
	AddSelfAttackTrigger(this, &CIlhargTheRazeBoarCard::BeforePutCreature, true);

	// When Ilharg dies or is put into exile from the battlefield, you may put it into its owner's library third from the
	// top. (as God-Eternal Oketra)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CIlhargTheRazeBoarCard::SetLeaveContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIlhargTheRazeBoarCard::BeforeThirdFromTop));
	AddAbility(cpAbility.GetPointer());
}

bool CIlhargTheRazeBoarCard::BeforePutCreature(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCardFilter* pCreatures = CCardFilter::GetFilter(_T("creatures"));
	if (pCreatures->CountIncluded(pController->GetZoneById(ZoneId::Hand)->GetCardContainer()) == 0)
		return true;

	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::PrimaryPlayer, pCreatures,
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		CCardOrientationModifier(TRUE).ApplyTo(pCard);

		// Return that creature to your hand at the beginning of the next end step (as Long Road Home)
		CScheduledCardModifier pReturn = CScheduledCardModifier(GetGame(),
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others),
			TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
		pReturn.ApplyTo(pCard);
	}
	return true;
}

bool CIlhargTheRazeBoarCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pToZone && (pToZone->GetZoneId() == ZoneId::Graveyard || pToZone->GetZoneId() == ZoneId::Exile);
}

bool CIlhargTheRazeBoarCard::BeforeThirdFromTop(CAbilityAction* pAction)
{
	ZoneId zone = GetZoneId();
	if (zone != ZoneId::Graveyard && zone != ZoneId::Exile)
		return true;

	CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
	CCountedCardContainer above;	// the cards that will be over it (the second from the top first)
	for (int i = 1; i >= 0; --i)
		if (pLibrary->GetSize() > i)
			above.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(zone, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(this);

	if (GetZoneId() == ZoneId::Library && above.GetSize() > 0)
		pLibrary->ReorderCards(above, CardPlacement::Top);
	return true;
}

//____________________________________________________________________________
//
CInvadingManticoreCard::CInvadingManticoreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Invading Manticore"), CardType::Creature, CREATURE_TYPE2(Zombie, Manticore), nID,
		_T("5") RED_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, amass Zombies 2.
	AddEnterTrigger(this, &CInvadingManticoreCard::BeforeAmass);
}

bool CInvadingManticoreCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CKrenkoTinStreetKingpinCard::CKrenkoTinStreetKingpinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Krenko, Tin Street Kingpin"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Goblin), nID,
		_T("2") RED_MANA_TEXT, Power(1), Life(2))
{
	// Whenever Krenko attacks, put a +1/+1 counter on it, then create a number of 1/1 red Goblin creature tokens equal to
	// Krenko's power.
	AddSelfAttackTrigger(this, &CKrenkoTinStreetKingpinCard::BeforeGoblins);
}

bool CKrenkoTinStreetKingpinCard::BeforeGoblins(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	AddPlusCounter(this, 1);
	int nPower = GET_INTEGER(GetPower());
	if (nPower > 0)
		CTokenCreationModifier(GetGame(), GOBLIN_C_TOKEN_NAME, GOBLIN_C_TOKEN_ID, nPower).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CNehebDreadhordeChampionCard::CNehebDreadhordeChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Neheb, Dreadhorde Champion"), CardType::Creature | CardType::Legendary,
		CREATURE_TYPE3(Zombie, Minotaur, Warrior), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever Neheb deals combat damage to a player or planeswalker, you may discard any number of cards. If you do, draw
	// that many cards and add that much {R}. Until end of turn, you don't lose this mana as steps and phases end.
	// Partial: the mana empties as usual at the end of the step.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNehebDreadhordeChampionCard::BeforeRummage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlaneswalkerEventCallback,
							   &CWhenSelfDamageDealt::SetPlaneswalkerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNehebDreadhordeChampionCard::BeforeRummage));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNehebDreadhordeChampionCard::BeforeRummage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	int nBefore = pHand->GetSize();
	if (nBefore == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Hand, 0, nBefore, CCardFilter::GetFilter(_T("cards")), ZoneId::Graveyard, MoveType::Discard);
	int nDiscarded = nBefore - pHand->GetSize();
	if (nDiscarded <= 0)
		return true;

	DrawCards(GetGame(), pController, nDiscarded);

	CString strMana;
	for (int i = 0; i < nDiscarded; ++i)
		strMana += RED_MANA_TEXT;
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool((LPCTSTR)strMana)).ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CRagingKronchCard::CRagingKronchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Raging Kronch"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") RED_MANA_TEXT, Power(4), Life(3))
{
	// This creature can't attack alone.
	// Not implemented: the engine has no "can't attack alone" (as Wojek Bodyguard in Guilds of Ravnica).
}

//____________________________________________________________________________
//
CSpellgorgerWeirdCard::CSpellgorgerWeirdCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spellgorger Weird"), CardType::Creature, CREATURE_TYPE(Weird), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast a noncreature spell, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpellgorgerWeirdCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CSpellgorgerWeirdCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CTibaltsRagerCard::CTibaltsRagerCard(CGame* pGame, UINT nID)
	: CPumpCreatureCard(pGame, _T("Tibalt's Rager"), CardType::Creature, CREATURE_TYPE(Devil), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(2),
		_T("1") RED_MANA_TEXT, Power(+2), Life(+0))
{
	// When this creature dies, it deals 1 damage to any target.
	CTargeting* pTargeting = AddDiesTargetTrigger(this, &CTibaltsRagerCard::BeforeDamage, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	pTargeting->SetIncludePlayers(TRUE);

	// {1}{R}: This creature gets +2/+0 until end of turn. (CPumpCreatureCard)
}

bool CTibaltsRagerCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 1);
	return false;
}

//____________________________________________________________________________
//
CTurretOgreCard::CTurretOgreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Turret Ogre"), CardType::Creature, CREATURE_TYPE2(Ogre, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(3))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// When this creature enters, if you control another creature with power 4 or greater, this creature deals 2 damage to
	// each opponent.
	AddEnterIfTrigger(this, &CTurretOgreCard::SetEnterContext, &CTurretOgreCard::BeforeDamage);
}

bool CTurretOgreCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pBattlefield->GetAt(i));
		if (pCreature && pCreature != this && pCreature->GetCardType().IsCreature() && GET_INTEGER(pCreature->GetPower()) >= 4)
			return true;
	}
	return false;
}

bool CTurretOgreCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CBanehoundCard::CBanehoundCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Banehound"), CardType::Creature, CREATURE_TYPE2(Nightmare, Dog), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Lifelink, haste
	GetCardKeyword()->AddLifelink(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);
}

//____________________________________________________________________________
//
CCharityExtractorCard::CCharityExtractorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charity Extractor"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") BLACK_MANA_TEXT, Power(1), Life(5))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

//____________________________________________________________________________
//
CDreadmalkinCard::CDreadmalkinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dreadmalkin"), CardType::Creature, CREATURE_TYPE2(Zombie, Cat), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
	, m_SacrificeFilter(_T("another creature or planeswalker"), _T("other creatures or planeswalkers"),
		new AndCardComparer(new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)),
			new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// {2}{B}, Sacrifice another creature or planeswalker: Put two +1/+1 counters on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") BLACK_MANA_TEXT));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->SetAbilityText(_T("Put two +1/+1 counters on this creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDreadmalkinCard::BeforeCounters));
	AddAbility(cpAbility.GetPointer());
}

bool CDreadmalkinCard::BeforeCounters(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 2);
	return true;
}

//____________________________________________________________________________
//
CDuskmantleOperativeCard::CDuskmantleOperativeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Duskmantle Operative"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_BlockerFilter(_T("a creature with power 3 or less"), _T("creatures with power 3 or less"),
		new CreaturePowerComparer<std::less_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 4 or greater. (the filter has the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

//____________________________________________________________________________
//
CEternalTaskmasterCard::CEternalTaskmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eternal Taskmaster"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// This creature enters tapped.
	SetIntoPlayTapped();

	// Whenever this creature attacks, you may pay {2}{B}. If you do, return target creature card from your graveyard to
	// your hand.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T("2") BLACK_MANA_TEXT);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEternalTaskmasterCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CEternalTaskmasterCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CGodEternalBontuCard::CGodEternalBontuCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("God-Eternal Bontu"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Zombie, God), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(6))
	, m_OtherPermanentFilter(_T("another permanent"), _T("other permanents"),
		new NegateCardComparer(new SpecificCardComparer(this)))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When God-Eternal Bontu enters, sacrifice any number of other permanents, then draw that many cards.
	AddEnterTrigger(this, &CGodEternalBontuCard::BeforeSacrifice);

	// When God-Eternal Bontu dies or is put into exile from the battlefield, you may put her into her owner's library third
	// from the top. (as God-Eternal Oketra)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGodEternalBontuCard::SetLeaveContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodEternalBontuCard::BeforeThirdFromTop));
	AddAbility(cpAbility.GetPointer());
}

bool CGodEternalBontuCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	int nBefore = m_OtherPermanentFilter.CountIncluded(pBattlefield->GetCardContainer());
	if (nBefore == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 0, nBefore, &m_OtherPermanentFilter, ZoneId::Graveyard, MoveType::Sacrifice);

	int nSacrificed = nBefore - m_OtherPermanentFilter.CountIncluded(pBattlefield->GetCardContainer());
	if (nSacrificed > 0)
		DrawCards(GetGame(), pController, nSacrificed);
	return true;
}

bool CGodEternalBontuCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pToZone && (pToZone->GetZoneId() == ZoneId::Graveyard || pToZone->GetZoneId() == ZoneId::Exile);
}

bool CGodEternalBontuCard::BeforeThirdFromTop(CAbilityAction* pAction)
{
	ZoneId zone = GetZoneId();
	if (zone != ZoneId::Graveyard && zone != ZoneId::Exile)
		return true;

	CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
	CCountedCardContainer above;	// the cards that will be over it (the second from the top first)
	for (int i = 1; i >= 0; --i)
		if (pLibrary->GetSize() > i)
			above.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(zone, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(this);

	if (GetZoneId() == ZoneId::Library && above.GetSize() > 0)
		pLibrary->ReorderCards(above, CardPlacement::Top);
	return true;
}

//____________________________________________________________________________
//
CHeraldOfTheDreadhordeCard::CHeraldOfTheDreadhordeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Herald of the Dreadhorde"), CardType::Creature, CREATURE_TYPE2(Zombie, Warrior), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// When this creature dies, amass Zombies 2.
	AddDiesTrigger(this, &CHeraldOfTheDreadhordeCard::BeforeAmass);
}

bool CHeraldOfTheDreadhordeCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CLazotepBehemothCard::CLazotepBehemothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lazotep Behemoth"), CardType::Creature, CREATURE_TYPE2(Zombie, Hippo), nID,
		_T("4") BLACK_MANA_TEXT, Power(5), Life(4))
{
}

//____________________________________________________________________________
//
CLazotepReaverCard::CLazotepReaverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lazotep Reaver"), CardType::Creature, CREATURE_TYPE2(Zombie, Beast), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, amass Zombies 1.
	AddEnterTrigger(this, &CLazotepReaverCard::BeforeAmass);
}

bool CLazotepReaverCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CMassacreGirlCard::CMassacreGirlCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Massacre Girl"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Assassin), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
	, m_nActiveTurn(-1)
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When Massacre Girl enters, each other creature gets -1/-1 until end of turn. Whenever a creature dies this turn, each
	// creature other than Massacre Girl gets -1/-1 until end of turn.
	// Partial: the "whenever a creature dies this turn" trigger only works while Massacre Girl is on the battlefield.
	AddEnterTrigger(this, &CMassacreGirlCard::BeforeShrink);

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMassacreGirlCard::SetDiesContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMassacreGirlCard::BeforeShrinkAgain));
	AddAbility(cpAbility.GetPointer());
}

bool CMassacreGirlCard::BeforeShrink(CAbilityAction* pAction)
{
	m_nActiveTurn = GetGame()->GetGameTurnNumber();
	ShrinkOthers(1);
	return true;
}

bool CMassacreGirlCard::SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_nActiveTurn == GetGame()->GetGameTurnNumber();
}

bool CMassacreGirlCard::BeforeShrinkAgain(CAbilityAction* pAction)
{
	ShrinkOthers(1);
	return true;
}

void CMassacreGirlCard::ShrinkOthers(int nAmount)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), NULL, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this && creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			PumpCreature(creatures.GetAt(i), -nAmount, -nAmount);
}

//____________________________________________________________________________
//
CShriekdiverCard::CShriekdiverCard(CGame* pGame, UINT nID)
	: CPumpCreatureCard(pGame, _T("Shriekdiver"), CardType::Creature, CREATURE_TYPE3(Zombie, Bird, Warrior), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(1),
		_T("1"), Power(+0), Life(+0), CreatureKeyword::Haste)
{
	// Flying
	GetCreatureKeyword()->AddFlying(FALSE);

	// {1}: This creature gains haste until end of turn. (CPumpCreatureCard)
}

//____________________________________________________________________________
//
CSparkReaperCard::CSparkReaperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spark Reaper"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3))
	, m_SacrificeFilter(_T("a creature or planeswalker"), _T("creatures or planeswalkers"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)))
{
	// {3}, Sacrifice a creature or planeswalker: You gain 1 life and draw a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("3")));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->SetAbilityText(_T("You gain 1 life and draw a card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSparkReaperCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CSparkReaperCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CTithebearerGiantCard::CTithebearerGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tithebearer Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Warrior), nID,
		_T("5") BLACK_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, you draw a card and you lose 1 life.
	AddEnterTrigger(this, &CTithebearerGiantCard::BeforeDraw);
}

bool CTithebearerGiantCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);
	CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CVampireOpportunistCard::CVampireOpportunistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vampire Opportunist"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// {6}{B}: Each opponent loses 2 life and you gain 2 life.
	AddSelfAbility(this, _T("6") BLACK_MANA_TEXT, _T("Each opponent loses 2 life and you gain 2 life. Activates"),
		&CVampireOpportunistCard::BeforeDrain);
}

bool CVampireOpportunistCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 2, TRUE);
	return true;
}

//____________________________________________________________________________
//
CVizierOfTheScorpionCard::CVizierOfTheScorpionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vizier of the Scorpion"), CardType::Creature, CREATURE_TYPE2(Zombie, Wizard), nID,
		_T("2") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, amass Zombies 1.
	AddEnterTrigger(this, &CVizierOfTheScorpionCard::BeforeAmass);

	// Zombie tokens you control have deathtouch.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false), new CardTypeComparer(CardType::Token, false)),
			Power(+0), Life(+0), CreatureKeyword::Null));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool CVizierOfTheScorpionCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CVraskasFinisherCard::CVraskasFinisherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vraska's Finisher"), CardType::Creature, CREATURE_TYPE2(Gorgon, Assassin), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, destroy target creature or planeswalker an opponent controls that was dealt damage this
	// turn.
	// Partial: only creatures (the damage dealt to planeswalkers this turn isn't recorded).
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CVraskasFinisherCard::BeforeDestroy, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(new DamagedThisTurnComparer);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CVraskasFinisherCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		DestroyPermanent(pCard, pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CAshioksSkulkerCard::CAshioksSkulkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ashiok's Skulker"), CardType::Creature, CREATURE_TYPE(Nightmare), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(5))
{
	// {3}{U}: This creature can't be blocked this turn.
	AddSelfAbility(this, _T("3") BLUE_MANA_TEXT, _T("This creature can't be blocked this turn. Activates"),
		&CAshioksSkulkerCard::BeforeUnblockable);
}

bool CAshioksSkulkerCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

//____________________________________________________________________________
//
CAvenEternalCard::CAvenEternalCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Eternal"), CardType::Creature, CREATURE_TYPE3(Zombie, Bird, Warrior), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, amass Zombies 1.
	AddEnterTrigger(this, &CAvenEternalCard::BeforeAmass);
}

bool CAvenEternalCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CErraticVisionaryCard::CErraticVisionaryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Erratic Visionary"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// {1}{U}, {T}: Draw a card, then discard a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1") BLUE_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Draw a card, then discard a card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CErraticVisionaryCard::BeforeLoot));
	AddAbility(cpAbility.GetPointer());
}

bool CErraticVisionaryCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CEternalSkylordCard::CEternalSkylordCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eternal Skylord"), CardType::Creature, CREATURE_TYPE2(Zombie, Wizard), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, amass Zombies 2.
	AddEnterTrigger(this, &CEternalSkylordCard::BeforeAmass);

	// Zombie tokens you control have flying.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false), new CardTypeComparer(CardType::Token, false)),
			Power(+0), Life(+0), CreatureKeyword::Flying));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool CEternalSkylordCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CFblthpTheLostCard::CFblthpTheLostCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fblthp, the Lost"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Homunculus), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(1))
	, m_nDraw(1)
{
	// When Fblthp enters, draw a card. If it entered from your library or was cast from your library, draw two cards
	// instead. (a spell cast from the library isn't detected)
	AddEnterIfTrigger(this, &CFblthpTheLostCard::SetEnterContext, &CFblthpTheLostCard::BeforeDraw);

	// When Fblthp becomes the target of a spell, shuffle Fblthp into its owner's library. (as Departed Deckhand)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFblthpTheLostCard::SetTargetedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFblthpTheLostCard::BeforeShuffle));
	AddAbility(cpAbility.GetPointer());
}

bool CFblthpTheLostCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	m_nDraw = (pFromZone && pFromZone->GetZoneId() == ZoneId::Library) ? 2 : 1;
	return true;
}

bool CFblthpTheLostCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), m_nDraw);
	return true;
}

bool CFblthpTheLostCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	return pTop && pTop->IsSpell();
}

bool CFblthpTheLostCard::BeforeShuffle(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others).ApplyTo(this);
	GetOwner()->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
CFluxChannelerCard::CFluxChannelerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Flux Channeler"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_Proliferate(this)
{
	m_Proliferate.AddProliferateTrigger();

	// Whenever you cast a noncreature spell, proliferate.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFluxChannelerCard::BeforeProliferate));
	AddAbility(cpAbility.GetPointer());
}

bool CFluxChannelerCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CGodEternalKefnetCard::CGodEternalKefnetCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("God-Eternal Kefnet"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Zombie, God), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(5))
{
	// You may reveal the first card you draw each turn as you draw it. Whenever you reveal an instant or sorcery card this
	// way, copy that card and you may cast the copy. That copy costs {2} less to cast.
	// Not implemented: the engine can't cast a copy of a card during a resolution.

	// When God-Eternal Kefnet dies or is put into exile from the battlefield, you may put it into its owner's library third
	// from the top. (as God-Eternal Oketra)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGodEternalKefnetCard::SetLeaveContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodEternalKefnetCard::BeforeThirdFromTop));
	AddAbility(cpAbility.GetPointer());
}

bool CGodEternalKefnetCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pToZone && (pToZone->GetZoneId() == ZoneId::Graveyard || pToZone->GetZoneId() == ZoneId::Exile);
}

bool CGodEternalKefnetCard::BeforeThirdFromTop(CAbilityAction* pAction)
{
	ZoneId zone = GetZoneId();
	if (zone != ZoneId::Graveyard && zone != ZoneId::Exile)
		return true;

	CZone* pLibrary = GetOwner()->GetZoneById(ZoneId::Library);
	CCountedCardContainer above;	// the cards that will be over it (the second from the top first)
	for (int i = 1; i >= 0; --i)
		if (pLibrary->GetSize() > i)
			above.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(zone, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(this);

	if (GetZoneId() == ZoneId::Library && above.GetSize() > 0)
		pLibrary->ReorderCards(above, CardPlacement::Top);
	return true;
}

//____________________________________________________________________________
//
CGuildpactInformantCard::CGuildpactInformantCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Guildpact Informant"), CardType::Creature, CREATURE_TYPE2(Faerie, Rogue), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(1))
	, m_Proliferate(this)
{
	m_Proliferate.AddProliferateTrigger();

	// Whenever this creature deals combat damage to a player or planeswalker, proliferate. (as Grateful Apparition)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGuildpactInformantCard::BeforeProliferate));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlaneswalkerEventCallback,
							   &CWhenSelfDamageDealt::SetPlaneswalkerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGuildpactInformantCard::BeforeProliferate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGuildpactInformantCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CJacesProjectionCard::CJacesProjectionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jace's Projection"), CardType::Creature, CREATURE_TYPE2(Wizard, Illusion), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you draw a card, put a +1/+1 counter on this creature.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJacesProjectionCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// {3}{U}: Put a loyalty counter on target Jace planeswalker. (as Gideon's Company)
	{
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("3") BLUE_MANA_TEXT,
				new AndCardComparer(new CardTypeComparer(CardType::Planeswalker, false),
					new PlaneswalkerTypeComparer(PlaneswalkerType::Jace)), FALSE));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(LOYALTY_COUNTER, +1));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CJacesProjectionCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CKiorasDambreakerCard::CKiorasDambreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kiora's Dambreaker"), CardType::Creature, CREATURE_TYPE(Leviathan), nID,
		_T("5") BLUE_MANA_TEXT, Power(5), Life(6))
	, m_Proliferate(this)
{
	// When this creature enters, proliferate.
	m_Proliferate.AddProliferateTrigger();
	AddEnterTrigger(this, &CKiorasDambreakerCard::BeforeProliferate);
}

bool CKiorasDambreakerCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CNagaEternalCard::CNagaEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Naga Eternal"), CardType::Creature, CREATURE_TYPE2(Zombie, Snake), nID,
		_T("2") BLUE_MANA_TEXT, Power(3), Life(2))
{
}

//____________________________________________________________________________
//
CRescuerSphinxCard::CRescuerSphinxCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rescuer Sphinx"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
	, m_ReturnFilter(_T("another nonland permanent"), _T("other nonland permanents"),
		new AndCardComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			new NegateCardComparer(new SpecificCardComparer(this))))
{
	// As this creature enters, you may return a nonland permanent you control to its owner's hand. If you do, this creature
	// enters with a +1/+1 counter on it.
	// Partial: it's a trigger when it enters (the counter is put after it enters).
	AddEnterTrigger(this, &CRescuerSphinxCard::BeforeReturn, true);
}

bool CRescuerSphinxCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	int nBefore = m_ReturnFilter.CountIncluded(pBattlefield->GetCardContainer());
	if (nBefore == 0)
		return true;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 0, 1, &m_ReturnFilter, ZoneId::Hand, MoveType::Others);
	if (m_ReturnFilter.CountIncluded(pBattlefield->GetCardContainer()) < nBefore && GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CSkyTheaterStrixCard::CSkyTheaterStrixCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sky Theater Strix"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// Whenever you cast a noncreature spell, this creature gets +1/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkyTheaterStrixCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CSkyTheaterStrixCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +0);
	return true;
}

//____________________________________________________________________________
//
CSpellkeeperWeirdCard::CSpellkeeperWeirdCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spellkeeper Weird"), CardType::Creature, CREATURE_TYPE(Weird), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// {2}, {T}, Sacrifice this creature: Return target instant or sorcery card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this, _T("2"),
			new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CThunderDrakeCard::CThunderDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Thunder Drake"), CardType::Creature, CREATURE_TYPE2(Elemental, Drake), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_nTurn(-1)
	, m_nSpells(0)
{
	// Whenever you cast your second spell each turn, put a +1/+1 counter on this creature.
	// (the spells are counted while this creature is on the battlefield)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CThunderDrakeCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThunderDrakeCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CThunderDrakeCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	if (GetGame()->GetGameTurnNumber() != m_nTurn)
	{
		m_nTurn = GetGame()->GetGameTurnNumber();
		m_nSpells = 0;
	}
	return ++m_nSpells == 2;
}

bool CThunderDrakeCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CWallOfRunesCard::CWallOfRunesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wall of Runes"), CardType::Creature, CREATURE_TYPE(Wall), nID,
		BLUE_MANA_TEXT, Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// When this creature enters, scry 1.
	AddEnterTrigger(this, &CWallOfRunesCard::BeforeScry);
}

bool CWallOfRunesCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
#define VOJA_TOKEN_NAME				_T("Voja, Friend to Elves")
#define VOJA_TOKEN_ID				55136

// "Whenever this creature deals combat damage to a player or planeswalker, <effect>" (as Silent Submersible)
template <class T>
static void AddCombatDamagePlayerOrPlaneswalkerTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional = false)
{
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

		cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
		pCard->AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlaneswalkerEventCallback,
							   &CWhenSelfDamageDealt::SetPlaneswalkerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

		cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
		pCard->AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CBioessenceHydraCard::CBioessenceHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bioessence Hydra"), CardType::Creature, CREATURE_TYPE2(Hydra, Mutant), nID,
		_T("3") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// This creature enters with a +1/+1 counter on it for each loyalty counter on planeswalkers you control.
	// Partial: it's a trigger when it enters (the counters are put after it enters).
	AddEnterTrigger(this, &CBioessenceHydraCard::BeforeEnterCounters);

	// Whenever one or more loyalty counters are put on planeswalkers you control, put that many +1/+1 counters on this
	// creature. (as Fathom Mage; the amount in the context, as Gishath)
	counted_ptr<CounterTriggeredAbility> cpAbility(::CreateObject<CounterTriggeredAbility>(this));

	cpAbility->SetOptionalType(CounterTriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetOnIncreaseOnly(TRUE);
	cpAbility->SetContextFunction(CounterTriggeredAbility::ContextFunction(this, &CBioessenceHydraCard::SetLoyaltyContext));
	cpAbility->SetBeforeResolveSelectionCallback(
		CounterTriggeredAbility::BeforeResolveSelectionCallback(this, &CBioessenceHydraCard::BeforeLoyaltyCounters));
	AddAbility(cpAbility.GetPointer());
}

bool CBioessenceHydraCard::BeforeEnterCounters(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	int nLoyalty = 0;
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsPlaneswalker() && pCard->GetCounterContainer()->GetCounter(LOYALTY_COUNTER))
			nLoyalty += pCard->GetCounterContainer()->GetCounter(LOYALTY_COUNTER)->GetCount();
	}
	if (nLoyalty > 0)
		AddPlusCounter(this, nLoyalty);
	return true;
}

bool CBioessenceHydraCard::SetLoyaltyContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value)
{
	if (!pFromCard || !pFromCard->GetCardType().IsPlaneswalker() || CString(name) != LOYALTY_COUNTER || n_value <= old)
		return false;
	triggerContext.nValue1 = (DWORD)(n_value - old);
	return true;
}

bool CBioessenceHydraCard::BeforeLoyaltyCounters(CounterTriggeredAbility::TriggeredActionType* pAction)
{
	int nCount = (int)pAction->GetTriggerContext().nValue1;
	if (nCount > 0 && GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, nCount);
	return true;
}

//____________________________________________________________________________
//
CCruelCelebrantCard::CCruelCelebrantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cruel Celebrant"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(2))
{
	// Whenever this creature or another creature or planeswalker you control dies, each opponent loses 1 life and you gain
	// 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCruelCelebrantCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CCruelCelebrantCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, TRUE);
	return true;
}

//____________________________________________________________________________
//
CDreadhordeButcherCard::CDreadhordeButcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dreadhorde Butcher"), CardType::Creature, CREATURE_TYPE2(Zombie, Warrior), nID,
		BLACK_MANA_TEXT RED_MANA_TEXT, Power(1), Life(1))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever this creature deals combat damage to a player or planeswalker, put a +1/+1 counter on this creature.
	AddCombatDamagePlayerOrPlaneswalkerTrigger(this, &CDreadhordeButcherCard::BeforeCounter);

	// When this creature dies, it deals damage equal to its power to any target.
	CTargeting* pTargeting = AddDiesTargetTrigger(this, &CDreadhordeButcherCard::BeforeDamage, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	pTargeting->SetIncludePlayers(TRUE);
}

bool CDreadhordeButcherCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

bool CDreadhordeButcherCard::BeforeDamage(CAbilityAction* pAction)
{
	int nPower = GET_INTEGER(GetLastKnownPower());
	if (nPower > 0)
		DealDamageToAnyTarget(this, pAction, nPower);
	return false;
}

//____________________________________________________________________________
//
CEliteGuardmageCard::CEliteGuardmageCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Elite Guardmage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, you gain 3 life and draw a card.
	AddEnterTrigger(this, &CEliteGuardmageCard::BeforeResolution);
}

bool CEliteGuardmageCard::BeforeResolution(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CGleamingOverseerCard::CGleamingOverseerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gleaming Overseer"), CardType::Creature, CREATURE_TYPE2(Zombie, Wizard), nID,
		_T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(4))
{
	// When this creature enters, amass Zombies 1.
	AddEnterTrigger(this, &CGleamingOverseerCard::BeforeAmass);

	// Zombie tokens you control have hexproof and menace.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false), new CardTypeComparer(CardType::Token, false)),
			Power(+0), Life(+0), CreatureKeyword::CantBeBlockedBy1));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool CGleamingOverseerCard::BeforeAmass(CAbilityAction* pAction)
{
	Amass(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CHuatlisRaptorCard::CHuatlisRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Huatli's Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Proliferate(this)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, proliferate.
	m_Proliferate.AddProliferateTrigger();
	AddEnterTrigger(this, &CHuatlisRaptorCard::BeforeProliferate);
}

bool CHuatlisRaptorCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CIronBullyCard::CIronBullyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Iron Bully"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("3"), Power(1), Life(1))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When this creature enters, put a +1/+1 counter on target creature.
	AddEnterTargetTrigger(this, &CIronBullyCard::BeforeCounter, false, Characteristic::Positive);
}

bool CIronBullyCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

//____________________________________________________________________________
//
CLeylineProwlerCard::CLeylineProwlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Leyline Prowler"), CardType::Creature, CREATURE_TYPE2(Nightmare, Beast), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);
}

//____________________________________________________________________________
//
CLivingTwisterCard::CLivingTwisterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Living Twister"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		RED_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(5))
	, m_TappedLandFilter(_T("a tapped land"), _T("tapped lands"),
		new AndCardComparer(new CardTypeComparer(CardType::_Land, false), new TappedComparer))
{
	// {1}{R}, Discard a land card: This creature deals 2 damage to any target.
	{
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("1") RED_MANA_TEXT,
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)), TRUE));

		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("lands")));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLivingTwisterCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// {G}: Return a tapped land you control to its owner's hand.
	AddSelfAbility(this, GREEN_MANA_TEXT, _T("Return a tapped land you control to its owner's hand. Activates"),
		&CLivingTwisterCard::BeforeReturnLand);
}

bool CLivingTwisterCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 2);
	return false;
}

bool CLivingTwisterCard::BeforeReturnLand(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Battlefield, 1, 1, &m_TappedLandFilter, ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CMayhemDevilCard::CMayhemDevilCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mayhem Devil"), CardType::Creature, CREATURE_TYPE(Devil), nID,
		_T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Whenever a player sacrifices a permanent, this creature deals 1 damage to any target.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMayhemDevilCard::SetSacrificeContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMayhemDevilCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CMayhemDevilCard::SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Sacrifice;
}

bool CMayhemDevilCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 1);
	return false;
}

//____________________________________________________________________________
//
CMerfolkSkydiverCard::CMerfolkSkydiverCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Merfolk Skydiver"), CardType::Creature, CREATURE_TYPE2(Merfolk, Mutant), nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(1))
	, m_Proliferate(this)
{
	m_Proliferate.AddProliferateTrigger();

	// When this creature enters, put a +1/+1 counter on target creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CMerfolkSkydiverCard::BeforeCounter, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();

	// {3}{G}{U}: Proliferate.
	AddSelfAbility(this, _T("3") GREEN_MANA_TEXT BLUE_MANA_TEXT, _T("Proliferate. Activates"),
		&CMerfolkSkydiverCard::BeforeProliferate);
}

bool CMerfolkSkydiverCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

bool CMerfolkSkydiverCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CNivMizzetRebornCard::CNivMizzetRebornCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Niv-Mizzet Reborn"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Dragon, Avatar), nID,
		WHITE_MANA_TEXT BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// When Niv-Mizzet enters, reveal the top ten cards of your library. For each color pair, choose a card that's exactly
	// those colors from among them. Put the chosen cards into your hand and the rest on the bottom of your library in a
	// random order.
	// Partial: for each color pair, the first card found is chosen.
	AddEnterTrigger(this, &CNivMizzetRebornCard::BeforeReveal);
}

bool CNivMizzetRebornCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	CCountedCardContainer revealed;
	for (int i = 0; i < 10 && i < pLibrary->GetSize(); ++i)
		revealed.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	CCountedCardContainer chosen;
	for (int c1 = 0; c1 < 5; ++c1)
		for (int c2 = c1 + 1; c2 < 5; ++c2)
			for (int i = 0; i < revealed.GetSize(); ++i)
			{
				CCard* pCard = revealed.GetAt(i);
				if (chosen.HasCard(pCard))
					continue;
				int nColors = 0;
				BOOL bPair = TRUE;
				for (int c = 0; c < 5; ++c)
				{
					BOOL bHas = CardTypeComparer(colors[c], false)(pCard);
					if (bHas)
						++nColors;
					if ((c == c1 || c == c2) && !bHas)
						bPair = FALSE;
				}
				if (bPair && nColors == 2)
				{
					chosen.AddCard(pCard, CardPlacement::Top);
					break;
				}
			}

	CMoveCardModifier pToHand = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pController);
	for (int i = 0; i < chosen.GetSize(); ++i)
		pToHand.ApplyTo(chosen.GetAt(i));

	CCountedCardContainer rest;
	for (int i = 0; i < revealed.GetSize(); ++i)
		if (!chosen.HasCard(revealed.GetAt(i)) && revealed.GetAt(i)->GetZoneId() == ZoneId::Library)
			rest.AddCard(revealed.GetAt(i), CardPlacement::Top);
	if (rest.GetSize() > 0)
		pLibrary->ReorderCards(rest, CardPlacement::Bottom);
	return true;
}

//____________________________________________________________________________
//
CPrismiteCard::CPrismiteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prismite"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("2"), Power(2), Life(1))
{
	// {2}: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("2"), AbilityType::Activated, colors[i]));
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CRoaleskApexHybridCard::CRoaleskApexHybridCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Roalesk, Apex Hybrid"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Mutant), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(5))
	, m_Proliferate(this)
{
	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	m_Proliferate.AddProliferateTrigger();

	// When Roalesk enters, put two +1/+1 counters on another target creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CRoaleskApexHybridCard::BeforeCounters, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));

	// When Roalesk dies, proliferate, then proliferate again.
	AddDiesTrigger(this, &CRoaleskApexHybridCard::BeforeProliferate);
}

bool CRoaleskApexHybridCard::BeforeCounters(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard, 2);
	return false;
}

bool CRoaleskApexHybridCard::BeforeProliferate(CAbilityAction* pAction)
{
	m_Proliferate.Proliferate(pAction->GetController());
	m_Proliferate.Proliferate(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CRubblebeltRiotersCard::CRubblebeltRiotersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rubblebelt Rioters"), CardType::Creature, CREATURE_TYPE2(Human, Berserker), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(4))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever this creature attacks, it gets +X/+0 until end of turn, where X is the greatest power among creatures you
	// control.
	AddSelfAttackTrigger(this, &CRubblebeltRiotersCard::BeforePump);
}

bool CRubblebeltRiotersCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	int nMax = 0;
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && GET_INTEGER(pCreature->GetPower()) > nMax)
			nMax = GET_INTEGER(pCreature->GetPower());
	}
	if (nMax > 0)
		PumpCreature(this, nMax, 0);
	return true;
}

//____________________________________________________________________________
//
CSaheelisSilverwingCard::CSaheelisSilverwingCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Saheeli's Silverwing"), CardType::_ArtifactCreature, CREATURE_TYPE(Drake), nID,
		_T("4"), Power(2), Life(3))
{
	// Flying
	// When this creature enters, look at the top card of target opponent's library.
	// Not implemented: looking at the card has no effect on the game.
}

//____________________________________________________________________________
//
CSoulDivinerCard::CSoulDivinerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Soul Diviner"), CardType::Creature, CREATURE_TYPE2(Zombie, Wizard), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
	, m_PermanentFilter(_T("an artifact, creature, land, or planeswalker"), _T("artifacts, creatures, lands, or planeswalkers"),
		new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Land | CardType::Planeswalker, false))
{
	// {T}, Remove a counter from an artifact, creature, land, or planeswalker you control: Draw a card.
	// Partial: only +1/+1 counters and loyalty counters (one ability for each kind).
	LPCTSTR counters[] = { _T("+1/+1"), LOYALTY_COUNTER };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddAnyCardCounterCost(counters[i], -1, 1, &m_PermanentFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CStorrevDevkarinLichCard::CStorrevDevkarinLichCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storrev, Devkarin Lich"), CardType::Creature | CardType::Legendary,
		CREATURE_TYPE3(Zombie, Elf, Wizard), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever Storrev deals combat damage to a player or planeswalker, return to your hand target creature or planeswalker
	// card in your graveyard that wasn't put there this combat.
	// Partial: any creature or planeswalker card in your graveyard.
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
									 CWhenSelfDamageDealt::PlayerEventCallback,
									 &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStorrevDevkarinLichCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
									 CWhenSelfDamageDealt::PlaneswalkerEventCallback,
									 &CWhenSelfDamageDealt::SetPlaneswalkerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStorrevDevkarinLichCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CStorrevDevkarinLichCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CTenthDistrictLegionnaireCard::CTenthDistrictLegionnaireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tenth District Legionnaire"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever you cast a spell that targets this creature, put a +1/+1 counter on this creature, then scry 1.
	// (the top of the stack is a spell of its controller, as Departed Deckhand)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTenthDistrictLegionnaireCard::SetTargetedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTenthDistrictLegionnaireCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CTenthDistrictLegionnaireCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	return pPlayer == GetController() && pTop && pTop->IsSpell();
}

bool CTenthDistrictLegionnaireCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CTolsimirFriendToWolvesCard::CTolsimirFriendToWolvesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tolsimir, Friend to Wolves"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Scout), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_pWolf(NULL)
{
	// When Tolsimir enters, create Voja, Friend to Elves, a legendary 3/3 green and white Wolf creature token.
	AddEnterTrigger(this, &CTolsimirFriendToWolvesCard::BeforeVoja);

	// Whenever a Wolf you control enters, you gain 3 life and that creature fights up to one target creature you don't
	// control.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Wolf), false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetSubjectCount(0, 1);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTolsimirFriendToWolvesCard::SetWolfContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTolsimirFriendToWolvesCard::BeforeFight));
	AddAbility(cpAbility.GetPointer());
}

bool CTolsimirFriendToWolvesCard::BeforeVoja(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), VOJA_TOKEN_NAME, VOJA_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CTolsimirFriendToWolvesCard::SetWolfContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	m_pWolf = pCard;
	return true;
}

bool CTolsimirFriendToWolvesCard::BeforeFight(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);

	CCard* pTarget = pAction->GetAssociatedCard();	// NULL if no target was chosen
	if (m_pWolf && m_pWolf->GetZoneId() == ZoneId::Battlefield && pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		Fight(m_pWolf, pTarget);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
CDreadhordeInvasionCard::CDreadhordeInvasionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dreadhorde Invasion"), CardType::GlobalEnchantment, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, you lose 1 life and amass Zombies 1.
	AddStepTrigger<CDreadhordeInvasionCard>(this, NodeId::UpkeepStep, false, NULL, &CDreadhordeInvasionCard::BeforeAmass);

	// Whenever a Zombie token you control with power 6 or greater attacks, it gains lifelink until end of turn.
	// (as Cavalcade of Calamity in Ravnica Allegiance)
	counted_ptr<AttackTriggeredAbility> cpAbility(::CreateObject<AttackTriggeredAbility>(this));

	cpAbility->SetOptionalType(AttackTriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(AttackTriggeredAbility::ContextFunction(this, &CDreadhordeInvasionCard::SetAttackContext));
	cpAbility->SetBeforeResolveSelectionCallback(
		AttackTriggeredAbility::BeforeResolveSelectionCallback(this, &CDreadhordeInvasionCard::BeforeLifelink));
	AddAbility(cpAbility.GetPointer());
}

bool CDreadhordeInvasionCard::BeforeAmass(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pController);
	Amass(this, pController, 1);
	return true;
}

bool CDreadhordeInvasionCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	if (!pCreature || pCreature->GetPower() < Power(6))
		return false;
	if (!CreatureTypeComparer(CREATURE_TYPE(Zombie), false)(pCreature) || !CardTypeComparer(CardType::Token, false)(pCreature))
		return false;
	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CDreadhordeInvasionCard::BeforeLifelink(AttackTriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCreature = (CCard*)pAction->GetTriggerContext().nValue1;
	GainCardKeyword(pCreature, CardKeyword::Lifelink);
	return true;
}

//____________________________________________________________________________
//
CKayasGhostformCard::CKayasGhostformCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Kaya's Ghostform"), nID,
		BLACK_MANA_TEXT,
		Power(+0), Life(+0))
	, m_pCard(NULL)
{
	// Enchant creature or planeswalker you control. When enchanted creature dies or is put into exile, return it to the
	// battlefield under your control.
	// Partial: it only enchants creatures. (the trigger belongs to the Aura, as Infernal Scarring in M19)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetIncludeControllerCardsOnly();
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);

	ZoneId toZones[] = { ZoneId::Graveyard, ZoneId::Exile };
	for (int i = 0; i < 2; ++i)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, toZones[i]));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKayasGhostformCard::SetLeaveContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKayasGhostformCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKayasGhostformCard::SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard != GetEnchantedOn())
		return false;
	m_pCard = pCard;
	return true;
}

bool CKayasGhostformCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = m_pCard;
	m_pCard = NULL;
	if (!pCard)
		return true;

	ZoneId zone = pCard->GetZoneId();
	if (zone == ZoneId::Graveyard || zone == ZoneId::Exile)
		CMoveCardModifier(zone, ZoneId::Battlefield, FALSE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return true;
}

//____________________________________________________________________________
//
CNewHorizonsCard::CNewHorizonsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("New Horizons"), CardType::EnchantLand, nID)
{
	// Enchant land. Enchanted land has "{T}: Add two mana of any one color."
	// Partial: as Gift of Paradise in M19, whenever enchanted land is tapped for mana, its controller adds one additional
	// mana of any color (the engine can't grant mana abilities)
	counted_ptr<CAbilityEnchant> cpSpell(
		::CreateObject<CAbilityEnchant>(this,
			_T("2") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false),
			CAbilityEnchant::CreateAbilityCallback(this, &CNewHorizonsCard::CreateEnchantAbility),
			CAbilityEnchant::AdditionType::ToEnchantCard));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());

	// When this Aura enters, put a +1/+1 counter on target creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CNewHorizonsCard::BeforeCounter, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
}

counted_ptr<CAbility> CNewHorizonsCard::CreateEnchantAbility(CCard* pEnchantedCard, CCard* pEnchantCard, ContextValue_& contextValue)
{
	typedef
		TTriggeredAbility< CTriggeredProdManaAbility, CWhenSelfTappedForMana > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pEnchantCard, pEnchantedCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
	cpAbility->SetSkipStack(TRUE);

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CNewHorizonsCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard, 1);
	return false;
}

//____________________________________________________________________________
//
COathOfKayaCard::COathOfKayaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Kaya"), CardType::GlobalEnchantment | CardType::Legendary, nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_nTurn(-1)
	, m_pAttacker(NULL)
{
	// When Oath of Kaya enters, it deals 3 damage to any target and you gain 3 life. (as Hieromancer's Cage)
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
			new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COathOfKayaCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// Whenever an opponent attacks a planeswalker you control with one or more creatures, Oath of Kaya deals 2 damage to
	// that player and you gain 2 life. (as Cavalcade of Calamity; once for each attacking player and turn)
	{
		counted_ptr<AttackTriggeredAbility> cpAbility(::CreateObject<AttackTriggeredAbility>(this));

		cpAbility->SetOptionalType(AttackTriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(AttackTriggeredAbility::ContextFunction(this, &COathOfKayaCard::SetAttackContext));
		cpAbility->SetBeforeResolveSelectionCallback(
			AttackTriggeredAbility::BeforeResolveSelectionCallback(this, &COathOfKayaCard::BeforeDrain));
		AddAbility(cpAbility.GetPointer());
	}
}

bool COathOfKayaCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 3);
	GainLife(this, pAction->GetController(), 3);
	return false;
}

bool COathOfKayaCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	CPlaneswalkerCard* pPlaneswalker = attacked.cpPlaneswalker.GetPointer();
	if (!pCreature || !pPlaneswalker || pPlaneswalker->GetController() != GetController())
		return false;

	const CPlayer* pAttacker = pCreature->GetController();
	if (pAttacker == GetController())
		return false;

	// One or more creatures: only the first attacker of that player this turn
	if (m_nTurn == GetGame()->GetGameTurnNumber() && m_pAttacker == pAttacker)
		return false;
	m_nTurn = GetGame()->GetGameTurnNumber();
	m_pAttacker = pAttacker;

	triggerContext.nValue1 = (DWORD)pAttacker;
	return true;
}

bool COathOfKayaCard::BeforeDrain(AttackTriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 2);
	GainLife(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CPrisonRealmCard::CPrisonRealmCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Prison Realm"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, exile target creature or planeswalker an opponent controls until this enchantment
	// leaves the battlefield. When this enchantment enters, scry 1. (as Hieromancer's Cage in M19)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false)));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrisonRealmCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());

	AddLeaveTrigger(this, &CPrisonRealmCard::BeforeReturn);
}

bool CPrisonRealmCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

bool CPrisonRealmCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
