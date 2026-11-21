#include "stdafx.h"
#include "CardM20.h"

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
#define PROLIFERATE_TRIGGER_INDEX	7701		// index of the special trigger of CProliferateSupport (per card)
#define CITIZEN_A_TOKEN_NAME		_T("Citizen (A)")
#define CITIZEN_A_TOKEN_ID			64131
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
#define MIZZIUM_TANK_VEHICLE_NAME			_T("Mizzium Tank (Vehicle)")
#define MIZZIUM_TANK_VEHICLE_ID				64136
#define PARHELION_II_VEHICLE_NAME			_T("Parhelion II (Vehicle)")
#define PARHELION_II_VEHICLE_ID				64137
#define SILENT_SUBMERSIBLE_VEHICLE_NAME		_T("Silent Submersible (Vehicle)")
#define SILENT_SUBMERSIBLE_VEHICLE_ID		64138
#define SOLDIER_U_TOKEN_NAME		_T("Soldier (U)")
#define SOLDIER_U_TOKEN_ID			55133
#define CITIZEN_B_TOKEN_NAME		_T("Citizen (B)")
#define CITIZEN_B_TOKEN_ID			55134
#define ANGEL_M_TOKEN_NAME			_T("Angel (M)")
#define ANGEL_M_TOKEN_ID			55117
#define VITU_GHAZI_A_TOKEN_NAME		_T("Vitu-Ghazi (A)")
#define VITU_GHAZI_A_TOKEN_ID		64139
#define ZOMBIE_WARRIOR_A_TOKEN_NAME		_T("Zombie Warrior (A)")
#define ZOMBIE_WARRIOR_A_TOKEN_ID		55135
#define VOJA_TOKEN_NAME				_T("Voja, Friend to Elves")
#define VOJA_TOKEN_ID				55136

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

// Damage to any target: a player, a creature or a planeswalker (the planeswalkers lose loyalty)
static void DealDamageToAnyTarget(CCard* pSource, CAbilityAction* pAction, int nDamage)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DealDamageToPlayer(pSource, pPlayer, nDamage);
	else
		DealDamageToCreatureOrPlaneswalker(pSource, pAction->GetAssociatedCard(), nDamage);
}

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
counted_ptr<CCard> CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID)
{
	counted_ptr<CCard> cpCard;
	do
	{
		DEFINE_CARD(CCrypticCavesCard);
		DEFINE_CARD(CFieldOfTheDeadCard);
		DEFINE_CARD(CLotusFieldCard);
		DEFINE_CARD(CAjaniInspiringLeaderCard);
		DEFINE_CARD(CAjaniStrengthOfThePrideCard);
		DEFINE_CARD(CChandraAcolyteOfFlameCard);
		DEFINE_CARD(CChandraAwakenedInfernoCard);
		DEFINE_CARD(CChandraFlamesFuryCard);
		DEFINE_CARD(CChandraNovicePyromancerCard);
		DEFINE_CARD(CMuYanlingCelestialWindCard);
		DEFINE_CARD(CMuYanlingSkyDancerCard);
		DEFINE_CARD(CSorinImperiousBloodlordCard);
		DEFINE_CARD(CSorinVampireLordCard);
		DEFINE_CARD(CVivienArkbowRangerCard);
		DEFINE_CARD(CVivienNaturesAvengerCard);
		DEFINE_CARD(CGauntletsOfLightCard);
		DEFINE_CARD(CGlaringAegisCard);
		DEFINE_CARD(CHardCoverCard);
		DEFINE_CARD(CLeylineOfAbundanceCard);
		DEFINE_CARD(CLeylineOfCombustionCard);
		DEFINE_CARD(CMoldervineReclamationCard);
		DEFINE_CARD(CSeasonOfGrowthCard);
		DEFINE_CARD(CUnholyIndentureCard);
		DEFINE_CARD(CAncestralBladeCard);
		DEFINE_CARD(CBagOfHoldingCard);
		DEFINE_CARD(CBloodsoakedAltarCard);
		DEFINE_CARD(CChandrasRegulatorCard);
		DEFINE_CARD(CColossusHammerCard);
		DEFINE_CARD(CDivinersLockboxCard);
		DEFINE_CARD(CHeartPiercerBowCard);
		DEFINE_CARD(CIconOfAncestryCard);
		DEFINE_CARD(CManifoldKeyCard);
		DEFINE_CARD(CMaskOfImmolationCard);
		DEFINE_CARD(CPortalOfSanctuaryCard);
		DEFINE_CARD(CRetributiveWandCard);
		DEFINE_CARD(CWolfridersSaddleCard);
		DEFINE_CARD(CAerialAssaultCard);
		DEFINE_CARD(CAgonizingSyphonCard);
		DEFINE_CARD(CBloodForBonesCard);
		DEFINE_CARD(CCaptivatingGyreCard);
		DEFINE_CARD(CChandrasFlameWaveCard);
		DEFINE_CARD(CDevoutDecreeCard);
		DEFINE_CARD(CDrawnFromDreamsCard);
		DEFINE_CARD(CEngulfingEruptionCard);
		DEFINE_CARD(CEternalIsolationCard);
		DEFINE_CARD(CFloodOfTearsCard);
		DEFINE_CARD(CLegionsEndCard);
		DEFINE_CARD(CRecklessAirStrikeCard);
		DEFINE_CARD(CSchemingSymmetryCard);
		DEFINE_CARD(CThoughtDistortionCard);
		DEFINE_CARD(CWingedWordsCard);
		DEFINE_CARD(CAetherGustCard);
		DEFINE_CARD(CBroughtBackCard);
		DEFINE_CARD(CDarkRemedyCard);
		DEFINE_CARD(CFlameSweepCard);
		DEFINE_CARD(CFryCard);
		DEFINE_CARD(CGrowthCycleCard);
		DEFINE_CARD(CInfuriateCard);
		DEFINE_CARD(CMasterfulReplicationCard);
		DEFINE_CARD(CNoxiousGraspCard);
		DEFINE_CARD(CSharedSummonsCard);
		DEFINE_CARD(CTalesEndCard);
		DEFINE_CARD(CVeilOfSummerCard);
		DEFINE_CARD(CAngelicGuardianCard);
		DEFINE_CARD(CAngelOfVitalityCard);
		DEFINE_CARD(CApostleOfPurifyingLightCard);
		DEFINE_CARD(CBattalionFootSoldierCard);
		DEFINE_CARD(CBishopOfWingsCard);
		DEFINE_CARD(CCavalierOfDawnCard);
		DEFINE_CARD(CDawningAngelCard);
		DEFINE_CARD(CGoldmaneGriffinCard);
		DEFINE_CARD(CHangedExecutionerCard);
		DEFINE_CARD(CHeraldOfTheSunCard);
		DEFINE_CARD(CImperialOutriderCard);
		DEFINE_CARD(CLoxodonLifechanterCard);
		DEFINE_CARD(CLoyalPegasusCard);
		DEFINE_CARD(CSavannahSageCard);
		DEFINE_CARD(CSepharaSkysBladeCard);
		DEFINE_CARD(CSquadCaptainCard);
		DEFINE_CARD(CStarfieldMysticCard);
		DEFINE_CARD(CSteadfastSentryCard);
		DEFINE_CARD(CTwinbladePaladinCard);
		DEFINE_CARD(CBarkhideTrollCard);
		DEFINE_CARD(CBrightwoodTrackerCard);
		DEFINE_CARD(CCavalierOfThornsCard);
		DEFINE_CARD(CElvishReclaimerCard);
		DEFINE_CARD(CEtherealElkCard);
		DEFINE_CARD(CFerociousPupCard);
		DEFINE_CARD(CGargosViciousWatcherCard);
		DEFINE_CARD(CGnarlbackRhinoCard);
		DEFINE_CARD(CHealerOfTheGladeCard);
		DEFINE_CARD(CHowlingGiantCard);
		DEFINE_CARD(CLeafkinDruidCard);
		DEFINE_CARD(CLoamingShamanCard);
		DEFINE_CARD(CNightpackAmbusherCard);
		DEFINE_CARD(COvergrowthElementalCard);
		DEFINE_CARD(CShiftingCeratopsCard);
		DEFINE_CARD(CSilverbackShamanCard);
		DEFINE_CARD(CThicketCrasherCard);
		DEFINE_CARD(CViviensCrocodileCard);
		DEFINE_CARD(CVoraciousHydraCard);
		DEFINE_CARD(CWakerootElementalCard);
		DEFINE_CARD(CWoodlandChampionCard);
		DEFINE_CARD(CWoodlandMysticCard);
		DEFINE_CARD(CCavalierOfFlameCard);
		DEFINE_CARD(CChandrasEmbercatCard);
		DEFINE_CARD(CDaggersailAeronautCard);
		DEFINE_CARD(CDestructiveDiggerCard);
		DEFINE_CARD(CDrakusethMawOfFlamesCard);
		DEFINE_CARD(CGlintHornBuccaneerCard);
		DEFINE_CARD(CGoblinBirdGrabberCard);
		DEFINE_CARD(CGoblinSmugglerCard);
		DEFINE_CARD(CImmortalPhoenixCard);
		DEFINE_CARD(CLavakinBrawlerCard);
		DEFINE_CARD(CMaraudingRaptorCard);
		DEFINE_CARD(CNimbleBirdstickerCard);
		DEFINE_CARD(CPackMastiffCard);
		DEFINE_CARD(CPyroclasticElementalCard);
		DEFINE_CARD(CRapaciousDragonCard);
		DEFINE_CARD(CScamperingScorcherCard);
		DEFINE_CARD(CScorchSpitterCard);
		DEFINE_CARD(CThunderkinAwakenerCard);
		DEFINE_CARD(CUnchainedBerserkerCard);
		DEFINE_CARD(CWildfireElementalCard);
		DEFINE_CARD(CAudaciousThiefCard);
		DEFINE_CARD(CBlightbeetleCard);
		DEFINE_CARD(CBloodBurglarCard);
		DEFINE_CARD(CBloodthirstyAerialistCard);
		DEFINE_CARD(CBonecladNecromancerCard);
		DEFINE_CARD(CCavalierOfNightCard);
		DEFINE_CARD(CDreadPresenceCard);
		DEFINE_CARD(CEmbodimentOfAgoniesCard);
		DEFINE_CARD(CGorgingVultureCard);
		DEFINE_CARD(CGruesomeScourgerCard);
		DEFINE_CARD(CKnightOfTheEbonLegionCard);
		DEFINE_CARD(CRottingRegisaurCard);
		DEFINE_CARD(CSavageGorgerCard);
		DEFINE_CARD(CSorcererOfTheFangCard);
		DEFINE_CARD(CSorinsGuideCard);
		DEFINE_CARD(CThirstingBloodlordCard);
		DEFINE_CARD(CUndeadServantCard);
		DEFINE_CARD(CVampireOfTheDireMoonCard);
		DEFINE_CARD(CVengefulWarchiefCard);
		DEFINE_CARD(CVilisBrokerOfBloodCard);
		DEFINE_CARD(CYaroksFenlurkerCard);
		DEFINE_CARD(CAgentOfTreacheryCard);
		DEFINE_CARD(CAtemsisAllSeeingCard);
		DEFINE_CARD(CBorealElementalCard);
		DEFINE_CARD(CBrinebornCutthroatCard);
		DEFINE_CARD(CCavalierOfGalesCard);
		DEFINE_CARD(CCelestialMessengerCard);
		DEFINE_CARD(CCeruleanDrakeCard);
		DEFINE_CARD(CCloudkinSeerCard);
		DEFINE_CARD(CDungeonGeistsCard);
		DEFINE_CARD(CFaerieMiscreantCard);
		DEFINE_CARD(CFrostLynxCard);
		DEFINE_CARD(CMoatPiranhasCard);
		DEFINE_CARD(COctoprophetCard);
		DEFINE_CARD(CRenownedWeaponsmithCard);
		DEFINE_CARD(CScholarOfTheAgesCard);
		DEFINE_CARD(CSpectralSailorCard);
		DEFINE_CARD(CWardenOfEvosIsleCard);
		DEFINE_CARD(CWaterkinShamanCard);
		DEFINE_CARD(CYanlingsHarbingerCard);
		DEFINE_CARD(CYaroksWavecrasherCard);
		DEFINE_CARD(CCorpseKnightCard);
		DEFINE_CARD(CCreepingTrailblazerCard);
		DEFINE_CARD(CEmpyreanEagleCard);
		DEFINE_CARD(CIronrootWarlordCard);
		DEFINE_CARD(CKaaliaZenithSeekerCard);
		DEFINE_CARD(CKethisTheHiddenHandCard);
		DEFINE_CARD(CKykarWindsFuryCard);
		DEFINE_CARD(CLightningStormkinCard);
		DEFINE_CARD(COgreSiegebreakerCard);
		DEFINE_CARD(COmnathLocusOfTheRoilCard);
		DEFINE_CARD(CRienneAngelOfRebirthCard);
		DEFINE_CARD(CRisenReefCard);
		DEFINE_CARD(CSkyknightVanguardCard);
		DEFINE_CARD(CTomeboundLichCard);
		DEFINE_CARD(CYarokTheDesecratedCard);
		DEFINE_CARD(CDiamondKnightCard);
		DEFINE_CARD(CGolosTirelessPilgrimCard);
		DEFINE_CARD(CPatternMatcherCard);
		DEFINE_CARD(CSalvagerOfRuinCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
CCrypticCavesCard::CCrypticCavesCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Cryptic Caves"), nID)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {1}, {T}, Sacrifice this land: Draw a card. Activate only if you control five or more lands.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("1"), 1));
	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddPlayableIf(this, cpAbility.GetPointer(), &CCrypticCavesCard::CanDraw);
	AddAbility(cpAbility.GetPointer());
}

BOOL CCrypticCavesCard::CanDraw(BOOL bIncludeTricks)
{
	return CCardFilter::GetFilter(_T("lands"))->CountIncluded(
		GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= 5;
}

//____________________________________________________________________________
//
CFieldOfTheDeadCard::CFieldOfTheDeadCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Field of the Dead"), nID)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// Whenever this land or another land you control enters, if you control seven or more lands with different names,
	// create a 2/2 black Zombie creature token. (Landfall as Tatyova, Benthic Druid)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFieldOfTheDeadCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFieldOfTheDeadCard::BeforeZombie));
	AddAbility(cpAbility.GetPointer());
}

BOOL CFieldOfTheDeadCard::HasSevenDifferentLands(CPlayer* pPlayer) const
{
	std::vector<CString> names;
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand())
			continue;
		CString strName = pCard->GetCardName(FALSE);
		if (std::find(names.begin(), names.end(), strName) == names.end())
			names.push_back(strName);
	}
	return names.size() >= 7;
}

bool CFieldOfTheDeadCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	// "if" intervening: checked when it triggers and again on resolution
	return HasSevenDifferentLands(GetController()) == TRUE;
}

bool CFieldOfTheDeadCard::BeforeZombie(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (!HasSevenDifferentLands(pController))
		return true;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, 1);
	pModifier.ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CLotusFieldCard::CLotusFieldCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Lotus Field"), nID)
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);

	// This land enters tapped.
	SetIntoPlayTapped();

	// When this land enters, sacrifice two lands.
	AddEnterTrigger(this, &CLotusFieldCard::BeforeSacrifice);

	// {T}: Add three mana of any one color. (as Gilded Lotus)
	AddTapManaAbility(this, WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT);
	AddTapManaAbility(this, BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT);
	AddTapManaAbility(this, BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT);
	AddTapManaAbility(this, RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT);
	AddTapManaAbility(this, GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT);
}

bool CLotusFieldCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 2, 2, CCardFilter::GetFilter(_T("lands")),
		ZoneId::Graveyard, MoveType::Sacrifice);
	return true;
}

//____________________________________________________________________________
//
#define ELEMENTAL_BIRD_A_TOKEN_NAME		_T("Elemental Bird (A)")
#define ELEMENTAL_BIRD_A_TOKEN_ID		55137
#define AJANIS_PRIDEMATE_TOKEN_NAME		_T("Ajani's Pridemate")
#define AJANIS_PRIDEMATE_TOKEN_ID		55138
#define CHANDRA_AWAKENED_EMBLEM_NAME	_T("Chandra, Awakened Inferno Emblem")
#define CHANDRA_AWAKENED_EMBLEM_ID		61162
#define ELEMENTAL_S_TOKEN_NAME			_T("Elemental (S)")
#define ELEMENTAL_S_TOKEN_ID			62052

// A loyalty ability with targets (the callback does the effect and returns false). Returns the ability, to adjust the
// targeting (SetSubjectCount, SetIncludeControllerCardsOnly...)
template <class T>
static CActivatedAbility<CTargetSpell>* AddTargetLoyaltyAbility(T* pCard, int nLoyalty, CardComparer* pComparer, BOOL bPlayers,
	Characteristic characteristic, bool (T::*callback)(CAbilityAction*))
{
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(pCard,
			_T(""),
			pComparer, bPlayers));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

// "Any target": a player, a creature or a planeswalker (with DealDamageToAnyTarget in the callback)
static CardComparer* NewCreatureOrPlaneswalkerComparer()
{
	return new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Planeswalker, false));
}

// "Until your next turn, <creature modifier>" (as Eldritch Moon: removed at the beginning of the controller's next
// untap step)
static void ApplyCreatureUntilYourNextTurn(CCard* pCard, CCreatureModifier* pModifier, CPlayer* pController)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
	{
		delete pModifier;
		return;
	}

	CScheduledCreatureModifier pScheduled = CScheduledCreatureModifier(pCard->GetGame(), pModifier,
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pController);
	pScheduled.ApplyTo(pCreature);
}

// Reveals cards from the top of the player's library until a card that matches the comparer is revealed; that card is
// put into the player's hand and the rest on the bottom of the library in a random order (as RevealUntil in Aether
// Revolt, with the random order)
static void RevealUntilToHand(CPlayer* pPlayer, const CardComparer& comparer)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);

	CCountedCardContainer revealed;
	CCard* pFound = NULL;
	for (int i = pLibrary->GetSize() - 1; i >= 0; --i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		if (comparer(pCard))
		{
			pFound = pCard;
			break;
		}
		revealed.AddCard(pCard, CardPlacement::Top);
	}

	if (pFound)
		CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pPlayer).ApplyTo(pFound);

	std::vector<CCard*> rest;
	for (int i = 0; i < revealed.GetSize(); ++i)
		rest.push_back(revealed.GetAt(i));
	while (!rest.empty())
	{
		int n = pPlayer->GetRand() % (int)rest.size();
		CCard* pCard = rest[n];
		rest.erase(rest.begin() + n);
		if (pCard->GetZoneId() == ZoneId::Library)
			pCard->Move(pLibrary, pPlayer, MoveType::Others, CardPlacement::Bottom);
	}
}

//____________________________________________________________________________
//
CAjaniInspiringLeaderCard::CAjaniInspiringLeaderCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani, Inspiring Leader"), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Ajani, 5)
{
	// +2: You gain 2 life. Put two +1/+1 counters on up to one target creature.
	CActivatedAbility<CTargetSpell>* pCounters = AddTargetLoyaltyAbility(this, +2, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &CAjaniInspiringLeaderCard::BeforeCounters);
	pCounters->GetTargeting()->SetSubjectCount(0, 1);

	// -3: Exile target creature. Its controller gains 2 life.
	AddTargetLoyaltyAbility(this, -3, new AnyCreatureComparer, FALSE,
		Characteristic::Negative, &CAjaniInspiringLeaderCard::BeforeExile);

	// -10: Creatures you control gain flying and double strike until end of turn.
	AddLoyaltyAbility(this, -10, _T("-10: Creatures you control gain flying and double strike until end of turn. Activates"),
		&CAjaniInspiringLeaderCard::BeforeFlying);
}

bool CAjaniInspiringLeaderCard::BeforeCounters(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	AddPlusCounter(GetTargetCreature(pAction), 2);
	return false;
}

bool CAjaniInspiringLeaderCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pPlayer = pCard->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	GainLife(this, pPlayer, 2);
	return false;
}

bool CAjaniInspiringLeaderCard::BeforeFlying(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), 0, 0, CreatureKeyword::Flying | CreatureKeyword::DoubleStrike);
	return true;
}

//____________________________________________________________________________
//
CAjaniStrengthOfThePrideCard::CAjaniStrengthOfThePrideCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani, Strength of the Pride"), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, PlaneswalkerType::Ajani, 5)
{
	// +1: You gain life equal to the number of creatures you control plus the number of planeswalkers you control.
	AddLoyaltyAbility(this, +1, _T("+1: You gain life equal to the number of creatures and planeswalkers you control. Activates"),
		&CAjaniStrengthOfThePrideCard::BeforeGainLife);

	// -2: Create a 2/2 white Cat Soldier creature token named Ajani's Pridemate with "Whenever you gain life, put a +1/+1
	// counter on this token."
	AddLoyaltyAbility(this, -2, _T("-2: Create a 2/2 white Cat Soldier creature token named Ajani's Pridemate. Activates"),
		&CAjaniStrengthOfThePrideCard::BeforePridemate);

	// 0: If you have at least 15 life more than your starting life total, exile Ajani and each artifact and creature your
	// opponents control.
	AddLoyaltyAbility(this, 0, _T("0: If you have at least 15 life more than your starting life total, exile Ajani and each artifact and creature your opponents control. Activates"),
		&CAjaniStrengthOfThePrideCard::BeforeExile);
}

bool CAjaniStrengthOfThePrideCard::BeforeGainLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	int nCount = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature())
			++nCount;
		if (pCard->GetCardType().IsPlaneswalker())
			++nCount;
	}
	if (nCount > 0)
		GainLife(this, pController, nCount);
	return true;
}

bool CAjaniStrengthOfThePrideCard::BeforePridemate(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), AJANIS_PRIDEMATE_TOKEN_NAME, AJANIS_PRIDEMATE_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CAjaniStrengthOfThePrideCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (pController->GetLife() - pController->GetStartingLife() < Life(15))
		return true;

	CCountedCardContainer cards;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;
		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() || pCard->GetCardType().IsArtifact())
				cards.AddCard(pCard, CardPlacement::Top);
		}
	}

	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController).ApplyTo(this);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController).ApplyTo(cards.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CChandraAcolyteOfFlameCard::CChandraAcolyteOfFlameCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Acolyte of Flame"), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Chandra, 4)
{
	// 0: Put a loyalty counter on each red planeswalker you control.
	AddLoyaltyAbility(this, 0, _T("0: Put a loyalty counter on each red planeswalker you control. Activates"),
		&CChandraAcolyteOfFlameCard::BeforeLoyalty);

	// 0: Create two 1/1 red Elemental creature tokens. They gain haste. Sacrifice them at the beginning of the next end step.
	AddLoyaltyAbility(this, 0, _T("0: Create two 1/1 red Elemental creature tokens with haste. Sacrifice them at the beginning of the next end step. Activates"),
		&CChandraAcolyteOfFlameCard::BeforeElementals);

	// -2: You may cast target instant or sorcery card with mana value 3 or less from your graveyard. If that spell would be
	// put into your graveyard, exile it instead.
	// Not implemented: the engine can't cast a card from another zone during a resolution.
}

bool CChandraAcolyteOfFlameCard::BeforeLoyalty(CAbilityAction* pAction)
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer planeswalkers;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsPlaneswalker() && CardTypeComparer(CardType::Red, false)(pCard))
			planeswalkers.AddCard(pCard, CardPlacement::Top);
	}
	for (int i = 0; i < planeswalkers.GetSize(); ++i)
		CCardCounterModifier(LOYALTY_COUNTER, +1).ApplyTo(planeswalkers.GetAt(i));
	return true;
}

bool CChandraAcolyteOfFlameCard::BeforeElementals(CAbilityAction* pAction)
{
	// (the haste and the sacrifice as Fury Charm / Kiki-Jiki: End Step Sacrifice Effect)
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer tokens;
	CTokenCreationModifier(GetGame(), ELEMENTAL_S_TOKEN_NAME, ELEMENTAL_S_TOKEN_ID, 2, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pController);

	CCountedCardContainer subjects;
	for (int i = 0; i < tokens.GetSize(); ++i)
	{
		CCard* pToken = tokens.GetAt(i);
		if (pToken->GetZoneId() != ZoneId::Battlefield)
			continue;
		PumpCreature(pToken, 0, 0, CreatureKeyword::Haste);
		subjects.AddCard(pToken, CardPlacement::Top);
	}
	if (subjects.GetSize() > 0)
		CContainerEffectModifier(GetGame(), _T("End Step Sacrifice Effect"), 61058, &subjects).ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
CChandraAwakenedInfernoCard::CChandraAwakenedInfernoCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Awakened Inferno"), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Chandra, 6)
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// +2: Each opponent gets an emblem with "At the beginning of your upkeep, this emblem deals 1 damage to you."
	AddLoyaltyAbility(this, +2, _T("+2: Each opponent gets an emblem with \"At the beginning of your upkeep, this emblem deals 1 damage to you.\" Activates"),
		&CChandraAwakenedInfernoCard::BeforeEmblem);

	// -3: Chandra deals 3 damage to each non-Elemental creature.
	AddLoyaltyAbility(this, -3, _T("-3: Chandra deals 3 damage to each non-Elemental creature. Activates"),
		&CChandraAwakenedInfernoCard::BeforeDamageEach);

	// -X: Chandra deals X damage to target creature or planeswalker. If a permanent dealt damage this way would die this
	// turn, exile it instead. (-X as Nahiri, Storm of Stone; the exile as Lava Coil)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpDamage(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			NewCreatureOrPlaneswalkerComparer(), FALSE));

	cpDamage->GetCost().AddCounterCost(GetLoyaltyCounter(), SpecialNumber::AnyNegative);
	cpDamage->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpDamage->SetAbilityText(_T("-X: Chandra deals X damage to target creature or planeswalker."));
	cpDamage->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandraAwakenedInfernoCard::BeforeDamageX));
	AddAbility(cpDamage.GetPointer());
}

bool CChandraAwakenedInfernoCard::BeforeEmblem(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer != pController)
			CTokenCreationModifier(GetGame(), CHANDRA_AWAKENED_EMBLEM_NAME, CHANDRA_AWAKENED_EMBLEM_ID, 1, FALSE, ZoneId::_Effects).ApplyTo(pPlayer);
	}
	return true;
}

bool CChandraAwakenedInfernoCard::BeforeDamageEach(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() && !CreatureTypeComparer(CREATURE_TYPE(Elemental), false)(pCard))
				creatures.AddCard(pCard, CardPlacement::Top);
		}
	}
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 3);
	return true;
}

bool CChandraAwakenedInfernoCard::BeforeDamageX(CAbilityAction* pAction)
{
	int nX = -pAction->GetCostConfigEntry().GetExtraValue();
	CCard* pCard = pAction->GetAssociatedCard();
	if (nX <= 0 || !pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CReplacementKeywordModifier pModifier;
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	pModifier.ApplyTo(pCard);

	DealDamageToCreatureOrPlaneswalker(this, pCard, nX);
	return false;
}

//____________________________________________________________________________
//
CChandraFlamesFuryCard::CChandraFlamesFuryCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Flame's Fury"), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Chandra, 4)
{
	// +1: Chandra deals 2 damage to any target.
	AddTargetLoyaltyAbility(this, +1, NewCreatureOrPlaneswalkerComparer(), TRUE,
		Characteristic::Negative, &CChandraFlamesFuryCard::BeforeDamage2);

	// -2: Chandra deals 4 damage to target creature and 2 damage to that creature's controller.
	AddTargetLoyaltyAbility(this, -2, new AnyCreatureComparer, FALSE,
		Characteristic::Negative, &CChandraFlamesFuryCard::BeforeDamage4);

	// -8: Chandra deals 10 damage to target player and each creature that player controls.
	AddPlayerLoyaltyAbility(this, -8, &CChandraFlamesFuryCard::BeforeDamage10);
}

bool CChandraFlamesFuryCard::BeforeDamage2(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 2);
	return false;
}

bool CChandraFlamesFuryCard::BeforeDamage4(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pPlayer = pCard->GetController();
	DealDamageToCreature(this, pCard, 4);
	DealDamageToPlayer(this, pPlayer, 2);
	return false;
}

bool CChandraFlamesFuryCard::BeforeDamage10(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	DealDamageToPlayer(this, pPlayer, 10);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 10);
	return false;
}

//____________________________________________________________________________
//
CChandraNovicePyromancerCard::CChandraNovicePyromancerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Novice Pyromancer"), nID,
		_T("3") RED_MANA_TEXT, PlaneswalkerType::Chandra, 5)
{
	// +1: Elementals you control get +2/+0 until end of turn.
	AddLoyaltyAbility(this, +1, _T("+1: Elementals you control get +2/+0 until end of turn. Activates"),
		&CChandraNovicePyromancerCard::BeforePump);

	// -1: Add {R}{R}.
	AddLoyaltyAbility(this, -1, _T("-1: Add {R}{R}. Activates"), &CChandraNovicePyromancerCard::BeforeMana);

	// -2: Chandra deals 2 damage to any target.
	AddTargetLoyaltyAbility(this, -2, NewCreatureOrPlaneswalkerComparer(), TRUE,
		Characteristic::Negative, &CChandraNovicePyromancerCard::BeforeDamage);
}

bool CChandraNovicePyromancerCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Elemental), creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +2, 0);
	return true;
}

bool CChandraNovicePyromancerCard::BeforeMana(CAbilityAction* pAction)
{
	CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(RED_MANA_TEXT RED_MANA_TEXT)).ApplyTo(pAction->GetController());
	return true;
}

bool CChandraNovicePyromancerCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 2);
	return false;
}

//____________________________________________________________________________
//
CMuYanlingCelestialWindCard::CMuYanlingCelestialWindCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Mu Yanling, Celestial Wind"), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Yanling, 5)
{
	// +1: Until your next turn, up to one target creature gets -5/-0.
	CActivatedAbility<CTargetSpell>* pWeaken = AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE,
		Characteristic::Negative, &CMuYanlingCelestialWindCard::BeforeWeaken);
	pWeaken->GetTargeting()->SetSubjectCount(0, 1);

	// -3: Return up to two target creatures to their owners' hands.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpReturn(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpReturn->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
	cpReturn->GetTargeting()->SetSubjectCount(0, 2);
	cpReturn->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpReturn.GetPointer());

	// -7: Creatures you control with flying get +5/+5 until end of turn.
	AddLoyaltyAbility(this, -7, _T("-7: Creatures you control with flying get +5/+5 until end of turn. Activates"),
		&CMuYanlingCelestialWindCard::BeforePump);
}

bool CMuYanlingCelestialWindCard::BeforeWeaken(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		ApplyCreatureUntilYourNextTurn(pCard, new CPowerModifier(Power(-5), FALSE), pAction->GetController());
	return false;
}

bool CMuYanlingCelestialWindCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && pCreature->GetCreatureKeyword()->Flying())
			PumpCreature(pCreature, +5, +5);
	}
	return true;
}

//____________________________________________________________________________
//
CMuYanlingSkyDancerCard::CMuYanlingSkyDancerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Mu Yanling, Sky Dancer"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Yanling, 2)
{
	// +2: Until your next turn, up to one target creature gets -2/-0 and loses flying.
	CActivatedAbility<CTargetSpell>* pWeaken = AddTargetLoyaltyAbility(this, +2, new AnyCreatureComparer, FALSE,
		Characteristic::Negative, &CMuYanlingSkyDancerCard::BeforeWeaken);
	pWeaken->GetTargeting()->SetSubjectCount(0, 1);

	// -3: Create a 4/4 blue Elemental Bird creature token with flying.
	AddLoyaltyAbility(this, -3, _T("-3: Create a 4/4 blue Elemental Bird creature token with flying. Activates"),
		&CMuYanlingSkyDancerCard::BeforeToken);

	// -8: You get an emblem with "Islands you control have '{T}: Draw a card.'"
	// Not implemented: the engine can't grant activated abilities to other cards.
}

bool CMuYanlingSkyDancerCard::BeforeWeaken(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pController = pAction->GetController();
	ApplyCreatureUntilYourNextTurn(pCard, new CPowerModifier(Power(-2), FALSE), pController);

	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier();
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	pKeywordModifier->GetModifier().SetToRemove(CreatureKeyword::Flying);
	ApplyCreatureUntilYourNextTurn(pCard, pKeywordModifier, pController);
	return false;
}

bool CMuYanlingSkyDancerCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), ELEMENTAL_BIRD_A_TOKEN_NAME, ELEMENTAL_BIRD_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSorinImperiousBloodlordCard::CSorinImperiousBloodlordCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sorin, Imperious Bloodlord"), nID,
		_T("2") BLACK_MANA_TEXT, PlaneswalkerType::Sorin, 4)
	, m_VampireFilter(_T("a Vampire"), _T("Vampires"), new CreatureTypeComparer(CREATURE_TYPE(Vampire), false))
	, m_VampireCardFilter(_T("a Vampire creature card"), _T("Vampire creature cards"),
		new AndCardComparer(new CardTypeComparer(CardType::Creature, false), new CreatureTypeComparer(CREATURE_TYPE(Vampire), false)))
{
	// +1: Target creature you control gains deathtouch and lifelink until end of turn. If it's a Vampire, put a +1/+1
	// counter on it.
	CActivatedAbility<CTargetSpell>* pKeywords = AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &CSorinImperiousBloodlordCard::BeforeKeywords);
	pKeywords->GetTargeting()->SetIncludeControllerCardsOnly();

	// +1: You may sacrifice a Vampire. When you do, Sorin deals 3 damage to any target and you gain 3 life.
	// Partial: the target is chosen when the ability is activated, and the Vampire is sacrificed on resolution.
	AddTargetLoyaltyAbility(this, +1, NewCreatureOrPlaneswalkerComparer(), TRUE,
		Characteristic::Negative, &CSorinImperiousBloodlordCard::BeforeSacrifice);

	// -3: You may put a Vampire creature card from your hand onto the battlefield.
	AddLoyaltyAbility(this, -3, _T("-3: You may put a Vampire creature card from your hand onto the battlefield. Activates"),
		&CSorinImperiousBloodlordCard::BeforePutVampire);
}

bool CSorinImperiousBloodlordCard::BeforeKeywords(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	GainCardKeyword(pCard, CardKeyword::Deathtouch);
	GainCardKeyword(pCard, CardKeyword::Lifelink);
	if (CreatureTypeComparer(CREATURE_TYPE(Vampire), false)(pCard))
		AddPlusCounter(pCard, 1);
	return false;
}

bool CSorinImperiousBloodlordCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCountedCardContainer& battlefield = pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer();
	int nBefore = m_VampireFilter.CountIncluded(battlefield);
	if (nBefore == 0)
		return false;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 0, 1, &m_VampireFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	if (m_VampireFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= nBefore)
		return false;

	DealDamageToAnyTarget(this, pAction, 3);
	GainLife(this, pController, 3);
	return false;
}

bool CSorinImperiousBloodlordCard::BeforePutVampire(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, &m_VampireCardFilter, ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CSorinVampireLordCard::CSorinVampireLordCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sorin, Vampire Lord"), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, PlaneswalkerType::Sorin, 4)
{
	// +1: Up to one target creature gets +2/+0 until end of turn.
	CActivatedAbility<CTargetSpell>* pPump = AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &CSorinVampireLordCard::BeforePump);
	pPump->GetTargeting()->SetSubjectCount(0, 1);

	// -2: Sorin deals 4 damage to any target. You gain 4 life.
	AddTargetLoyaltyAbility(this, -2, NewCreatureOrPlaneswalkerComparer(), TRUE,
		Characteristic::Negative, &CSorinVampireLordCard::BeforeDamage);

	// -8: Until end of turn, each Vampire you control gains "{T}: Gain control of target creature."
	// Not implemented: the engine can't grant activated abilities to other cards.
}

bool CSorinVampireLordCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +2, 0);
	return false;
}

bool CSorinVampireLordCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 4);
	GainLife(this, pAction->GetController(), 4);
	return false;
}

//____________________________________________________________________________
//
CVivienArkbowRangerCard::CVivienArkbowRangerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vivien, Arkbow Ranger"), nID,
		_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Vivien, 4)
{
	// +1: Distribute two +1/+1 counters among up to two target creatures. They gain trample until end of turn.
	// (one target gets both counters; two targets get one each)
	CActivatedAbility<CTargetSpell>* pCounters = AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &CVivienArkbowRangerCard::BeforeCounters);
	pCounters->GetTargeting()->SetSubjectCount(1, 2);

	// -3: Target creature you control deals damage equal to its power to target creature or planeswalker.
	// (two targets as Domri, Anarch of Bolas)
	{
		counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpDamage(
			::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, false,
				NewCreatureOrPlaneswalkerComparer(), false, _T(""), TRUE));

		cpDamage->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpDamage->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpDamage->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpDamage->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpDamage->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVivienArkbowRangerCard::BeforeDamage));
		AddAbility(cpDamage.GetPointer());
	}

	// -5: You may reveal a creature card you own from outside the game and put it into your hand.
	// Not implemented: the engine has no cards outside the game.
}

bool CVivienArkbowRangerCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);

	CCountedCardContainer creatures;
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			creatures.AddCard(cards.GetAt(i), CardPlacement::Top);

	int nCounters = creatures.GetSize() == 1 ? 2 : 1;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		AddPlusCounter(creatures.GetAt(i), nCounters);
		PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::Trample);
	}
	return false;
}

bool CVivienArkbowRangerCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard1);
	if (!pCreature || !pCard2)
		return false;

	int nPower = GET_INTEGER(pCreature->GetPower());
	DealDamageToCreatureOrPlaneswalker(pCreature, pCard2, nPower);
	return false;
}

//____________________________________________________________________________
//
CVivienNaturesAvengerCard::CVivienNaturesAvengerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vivien, Nature's Avenger"), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Vivien, 3)
{
	// +1: Put three +1/+1 counters on up to one target creature.
	AddCountersLoyaltyAbility(this, +1, 3, 1);

	// -1: Reveal cards from the top of your library until you reveal a creature card. Put that card into your hand and the
	// rest on the bottom of your library in a random order.
	AddLoyaltyAbility(this, -1, _T("-1: Reveal cards from the top of your library until you reveal a creature card and put it into your hand. Activates"),
		&CVivienNaturesAvengerCard::BeforeReveal);

	// -6: Target creature gets +10/+10 and gains trample until end of turn.
	AddTargetLoyaltyAbility(this, -6, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &CVivienNaturesAvengerCard::BeforePump);
}

bool CVivienNaturesAvengerCard::BeforeReveal(CAbilityAction* pAction)
{
	RevealUntilToHand(pAction->GetController(), CardTypeComparer(CardType::Creature, false));
	return true;
}

bool CVivienNaturesAvengerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +10, +10, CreatureKeyword::Trample);
	return false;
}

//____________________________________________________________________________
//
CGauntletsOfLightCard::CGauntletsOfLightCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Gauntlets of Light"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+2))
{
	// Enchanted creature gets +0/+2 and assigns combat damage equal to its toughness rather than its power.
	// Partial: the combat damage by toughness only exists as a player effect (Assault Formation), not for one creature.

	// Enchanted creature has "{2}{W}: Untap this creature." (as Compulsory Rest)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().LinkCardModifier(
		new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CGauntletsOfLightCard::CreateUntapAbility)));
}

counted_ptr<CAbility> CGauntletsOfLightCard::CreateUntapAbility(CCard* pCard)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("2") WHITE_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Untap this creature (Gauntlets of Light). Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGauntletsOfLightCard::BeforeUntap));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CGauntletsOfLightCard::BeforeUntap(CAbilityAction* pAction)
{
	// (the creature is the source of the ability, as Stitcher's Graft in Eldritch Moon)
	CCard* pCreature = pAction->GetAbility()->GetCard();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(FALSE).ApplyTo(pCreature);
	return true;
}

//____________________________________________________________________________
//
CGlaringAegisCard::CGlaringAegisCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Glaring Aegis"), nID,
		WHITE_MANA_TEXT,
		Power(+1), Life(+3))
{
	// Enchanted creature gets +1/+3.

	// When this Aura enters, tap target creature an opponent controls.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CGlaringAegisCard::BeforeTap, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CGlaringAegisCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CHardCoverCard::CHardCoverCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Hard Cover"), nID,
		BLUE_MANA_TEXT,
		Power(+0), Life(+2))
{
	// Enchanted creature gets +0/+2 and has "{T}: Draw a card, then discard a card." (as Compulsory Rest)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().LinkCardModifier(
		new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CHardCoverCard::CreateLootAbility)));
}

counted_ptr<CAbility> CHardCoverCard::CreateLootAbility(CCard* pCard)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Draw a card, then discard a card (Hard Cover). Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHardCoverCard::BeforeLoot));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CHardCoverCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CLeylineOfAbundanceCard::CLeylineOfAbundanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Leyline of Abundance"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_pManaAbility(NULL)
{
	// If this card is in your opening hand, you may begin the game with it on the battlefield.
	// (the core does it by name: LeylineCardNameComparer in CardFilter.cpp)

	{
		// Whenever you tap a creature for mana, add an additional {G}. (as Nissa, Who Shakes the World)
		counted_ptr<ManaTriggeredAbility> cpAbility(::CreateObject<ManaTriggeredAbility>(this));

		cpAbility->SetOptionalType(ManaTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(ManaTriggeredAbility::ContextFunction(this, &CLeylineOfAbundanceCard::SetManaContext));

		m_pManaAbility = cpAbility.GetPointer();
		AddAbility(m_pManaAbility);
	}
	{
		// {6}{G}{G}: Put a +1/+1 counter on each creature you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("6") GREEN_MANA_TEXT GREEN_MANA_TEXT));

		cpAbility->SetAbilityText(_T("Put a +1/+1 counter on each creature you control. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLeylineOfAbundanceCard::BeforeCounters));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLeylineOfAbundanceCard::SetManaContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
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

bool CLeylineOfAbundanceCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i), 1);
	return true;
}

//____________________________________________________________________________
//
CLeylineOfCombustionCard::CLeylineOfCombustionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Leyline of Combustion"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, AbilityType::Enchantment)
	, m_pLastAction(NULL)
{
	// If this card is in your opening hand, you may begin the game with it on the battlefield.
	// (the core does it by name: LeylineCardNameComparer in CardFilter.cpp)

	// Whenever you and/or at least one permanent you control becomes the target of a spell or ability an opponent controls,
	// this enchantment deals 2 damage to that player.
	// (two triggers of CWhenSubjectTargeted, as Rayne, Academy Chancellor; only once for each spell or ability on the stack)
	{
		counted_ptr<CardTriggeredAbility> cpAbility(::CreateObject<CardTriggeredAbility>(this, TRUE, FALSE));

		cpAbility->SetOptionalType(CardTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer);
		cpAbility->SetContextFunction(CardTriggeredAbility::ContextFunction(this, &CLeylineOfCombustionCard::SetCardContext));
		cpAbility->SetBeforeResolveSelectionCallback(CardTriggeredAbility::BeforeResolveSelectionCallback(this, &CLeylineOfCombustionCard::BeforeCardDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<PlayerTriggeredAbility> cpAbility(::CreateObject<PlayerTriggeredAbility>(this, FALSE, FALSE));

		cpAbility->SetOptionalType(PlayerTriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(PlayerTriggeredAbility::ContextFunction(this, &CLeylineOfCombustionCard::SetPlayerContext));
		cpAbility->SetBeforeResolveSelectionCallback(PlayerTriggeredAbility::BeforeResolveSelectionCallback(this, &CLeylineOfCombustionCard::BeforePlayerDamage));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLeylineOfCombustionCard::CheckTargeting(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pByPlayer) const
{
	if (!pByPlayer || pByPlayer == GetController())
		return false;

	// Once for each spell or ability (the top of the stack when the targets are chosen)
	const void* pTop = GetGame()->GetStack().GetTopAction();
	if (pTop && pTop == m_pLastAction)
		return false;
	m_pLastAction = pTop;

	triggerContext.nValue1 = (DWORD)pByPlayer;
	return true;
}

bool CLeylineOfCombustionCard::SetCardContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pByPlayer) const
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetController() != GetController())
		return false;
	return CheckTargeting(triggerContext, pByPlayer);
}

bool CLeylineOfCombustionCard::SetPlayerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CPlayer* pByPlayer) const
{
	if (pPlayer != GetController())
		return false;
	return CheckTargeting(triggerContext, pByPlayer);
}

void CLeylineOfCombustionCard::DamagePlayer(CPlayer* pPlayer)
{
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 2);
}

bool CLeylineOfCombustionCard::BeforeCardDamage(CardTriggeredAbility::TriggeredActionType* pAction)
{
	DamagePlayer((CPlayer*)pAction->GetTriggerContext().nValue1);
	return true;
}

bool CLeylineOfCombustionCard::BeforePlayerDamage(PlayerTriggeredAbility::TriggeredActionType* pAction)
{
	DamagePlayer((CPlayer*)pAction->GetTriggerContext().nValue1);
	return true;
}

//____________________________________________________________________________
//
CMoldervineReclamationCard::CMoldervineReclamationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Moldervine Reclamation"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control dies, you gain 1 life and draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMoldervineReclamationCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CMoldervineReclamationCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CSeasonOfGrowthCard::CSeasonOfGrowthCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Season of Growth"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_pLastSpell(NULL)
{
	{
		// Whenever a creature you control enters, scry 1.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSeasonOfGrowthCard::BeforeScry));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast a spell that targets a creature you control, draw a card.
		// (when a creature you control becomes the target of a spell of yours, as Druid of Horns in M19)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
							   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, FALSE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSeasonOfGrowthCard::SetTargetedContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSeasonOfGrowthCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSeasonOfGrowthCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

bool CSeasonOfGrowthCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	if (!pPlayer || pPlayer != GetController())
		return false;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetController() != GetController())
		return false;

	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	if (!pTop || !pTop->IsSpell() || !pTop->GetAbility())
		return false;

	CCard* pSpellCard = pTop->GetAbility()->GetCard();
	if (!pSpellCard || pSpellCard->GetController() != GetController())
		return false;

	// A spell with several targets draws only one card
	if (pTop == m_pLastSpell)
		return false;
	m_pLastSpell = pTop;
	return true;
}

bool CSeasonOfGrowthCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CUnholyIndentureCard::CUnholyIndentureCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Unholy Indenture"), nID,
		_T("2") BLACK_MANA_TEXT,
		Power(+0), Life(+0))
{
	// When enchanted creature dies, return that card to the battlefield under your control with a +1/+1 counter on it.
	// (the trigger belongs to the Aura, as Infernal Scarring in M19)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUnholyIndentureCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CUnholyIndentureCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CUnholyIndentureCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard != GetEnchantedOn())
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CUnholyIndentureCard::BeforeReturn(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard || pCard->GetCardType().IsToken())
		return true;

	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	AddPlusCounter(pCard, 1);
	return true;
}

//____________________________________________________________________________
//
#define DEMON_E_TOKEN_NAME		_T("Demon (E)")
#define DEMON_E_TOKEN_ID		55048

// "When this Equipment enters, create <token>, then attach this Equipment to it." (as Flayer Husk in Mirrodin Besieged,
// with the token created by the trigger)
static void CreateTokenAndAttach(CCard* pEquipment, CPlayer* pController, LPCTSTR strToken, UINT uTokenID)
{
	CCountedCardContainer tokens;
	CTokenCreationModifier(pEquipment->GetGame(), strToken, uTokenID, 1, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pController);
	if (tokens.GetSize() == 0 || pEquipment->GetZoneId() != ZoneId::Battlefield)
		return;

	CCreatureCard* pToken = dynamic_cast<CCreatureCard*>(tokens.GetAt(0));
	if (!pToken || pToken->GetZoneId() != ZoneId::Battlefield)
		return;

	for (int i = 0; i < pEquipment->GetAbilityCount(); ++i)
	{
		CEquipAbility* pEquipAbility = dynamic_cast<CEquipAbility*>(pEquipment->GetAbility(i));
		if (pEquipAbility)
		{
			pEquipAbility->Unequip();
			pEquipAbility->Equip(pToken);
		}
	}
}

//____________________________________________________________________________
//
CAncestralBladeCard::CAncestralBladeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ancestral Blade"), CardType::Artifact | CardType::Equipment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Artifact)
{
	// When this Equipment enters, create a 1/1 white Soldier creature token, then attach this Equipment to it.
	AddEnterTrigger(this, &CAncestralBladeCard::BeforeToken);

	// Equipped creature gets +1/+1. Equip {1}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CAncestralBladeCard::BeforeToken(CAbilityAction* pAction)
{
	CreateTokenAndAttach(this, pAction->GetController(), SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID);
	return true;
}

//____________________________________________________________________________
//
CBagOfHoldingCard::CBagOfHoldingCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Bag of Holding"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	{
		// Whenever you discard a card, exile that card from your graveyard. (the card in nValue1, as Fell Specter)
		counted_ptr<DiscardAbility> cpAbility(::CreateObject<DiscardAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(DiscardAbility::OptionalType::Required);
		cpAbility->SetContextFunction(DiscardAbility::ContextFunction(this, &CBagOfHoldingCard::SetDiscardContext));
		cpAbility->SetBeforeResolveSelectionCallback(DiscardAbility::BeforeResolveSelectionCallback(this, &CBagOfHoldingCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, {T}: Draw a card, then discard a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Draw a card, then discard a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBagOfHoldingCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}, {T}, Sacrifice this artifact: Return all cards exiled with this artifact to their owner's hand.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4")));

		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Return all cards exiled with this artifact to their owner's hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBagOfHoldingCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBagOfHoldingCard::SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	if (!pCard)
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CBagOfHoldingCard::BeforeExile(DiscardAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return true;

	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Exile)
		m_Exiled.AddCard(pCard, CardPlacement::Top);
	return true;
}

bool CBagOfHoldingCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

bool CBagOfHoldingCard::BeforeReturn(CAbilityAction* pAction)
{
	while (m_Exiled.GetSize() > 0)
	{
		CCard* pCard = m_Exiled.GetAt(0);
		m_Exiled.RemoveCard(pCard);
		if (pCard->GetZoneId() == ZoneId::Exile)
			CMoveCardModifier(ZoneId::Exile, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
CBloodsoakedAltarCard::CBloodsoakedAltarCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Bloodsoaked Altar"), CardType::Artifact, nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Artifact)
{
	// {T}, Pay 2 life, Discard a card, Sacrifice a creature: Create a 5/5 black Demon creature token with flying.
	// Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this, _T(""),
			DEMON_E_TOKEN_NAME, DEMON_E_TOKEN_ID, 1));

	cpAbility->AddTapCost();
	cpAbility->AddPayLifeDeltaCost(Life(-2));
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CChandrasRegulatorCard::CChandrasRegulatorCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Chandra's Regulator"), CardType::Artifact | CardType::Legendary, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Artifact)
	, m_DiscardFilter(_T("a Mountain card or a red card"), _T("Mountain cards or red cards"),
		new OrCardComparer(new CardTypeComparer(CardType::Mountain, false), new CardTypeComparer(CardType::Red, false)))
{
	// Whenever you activate a loyalty ability of a Chandra planeswalker, you may pay {1}. If you do, copy that ability.
	// You may choose new targets for the copy.
	// Not implemented: there is no event for activating an ability, and abilities can't be copied.

	// {1}, {T}, Discard a Mountain card or a red card: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("1"), 1));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, &m_DiscardFilter);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CColossusHammerCard::CColossusHammerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Colossus Hammer"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature gets +10/+10 and loses flying. Equip {8}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("8")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+10), FALSE));
	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+10), this, PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToRemove(CreatureKeyword::Flying);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CDivinersLockboxCard::CDivinersLockboxCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Diviner's Lockbox"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_NameSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDivinersLockboxCard::OnNameSelected))
{
	// {1}, {T}: Choose a card name, then reveal the top card of your library. If that card has the chosen name, sacrifice
	// this artifact and draw three cards. Activate only as a sorcery.
	// (the name is chosen among the names of the cards in your library, as Tamiyo, Collector of Tales)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->SetAbilityText(_T("Choose a card name, then reveal the top card of your library. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDivinersLockboxCard::BeforeChooseName));
	AddAbility(cpAbility.GetPointer());
}

bool CDivinersLockboxCard::BeforeChooseName(CAbilityAction* pAction)
{
	m_Names.clear();
	CZone* pLibrary = pAction->GetController()->GetZoneById(ZoneId::Library);
	for (int i = 0; i < pLibrary->GetSize(); ++i)
	{
		CString strName = pLibrary->GetAt(i)->GetCardName(FALSE);
		if (std::find(m_Names.begin(), m_Names.end(), strName) == m_Names.end())
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

void CDivinersLockboxCard::OnNameSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CString strName;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && (size_t)it->dwContext < m_Names.size())
			strName = m_Names[(size_t)it->dwContext];

	CZone* pLibrary = pSelectionPlayer->GetZoneById(ZoneId::Library);
	if (strName.IsEmpty() || pLibrary->GetSize() == 0)
		return;

	// Reveal the top card: if it has the chosen name, sacrifice this artifact and draw three cards
	CCard* pTop = pLibrary->GetAt(pLibrary->GetSize() - 1);
	if (pTop->GetCardName(FALSE) != strName)
		return;

	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer).ApplyTo(this);
	DrawCards(GetGame(), pSelectionPlayer, 3);
}

//____________________________________________________________________________
//
CHeartPiercerBowCard::CHeartPiercerBowCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Heart-Piercer Bow"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// Whenever equipped creature attacks, this Equipment deals 1 damage to target creature defending player controls.
		// (as Sigiled Sword of Valeron in M19, with a target)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
									 CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CHeartPiercerBowCard::SetAttackContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeartPiercerBowCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Equip {1}
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("1")));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHeartPiercerBowCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attackSubject) const
{
	return pCreature && EquippedByComparer(this)(pCreature);
}

bool CHeartPiercerBowCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToCreature(this, pAction->GetAssociatedCard(), 1);
	return false;
}

//____________________________________________________________________________
//
CIconOfAncestryCard::CIconOfAncestryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Icon of Ancestry"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_TypeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CIconOfAncestryCard::OnTypeSelected))
	, m_SelectedType(SingleCreatureType::Null)
{
	// As this artifact enters, choose a creature type. Creatures you control of the chosen type get +1/+1.
	// (the bonus is added when the type is chosen, as Radiant Destiny in Rivals of Ixalan)

	// {3}, {T}: Look at the top three cards of your library. You may reveal a creature card of the chosen type from among
	// them and put it into your hand. Put the rest on the bottom of your library in a random order.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Look at the top three cards of your library. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIconOfAncestryCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

void CIconOfAncestryCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType,
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
			CCardAbilityModifier::CreateAbilityCallback(this, &CIconOfAncestryCard::CreateBonusAbility));
		pBonus.RemoveFrom(this);
	}
}

void CIconOfAncestryCard::OnTypeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			m_SelectedType = SingleCreatureType((SingleCreatureType::Enum)it->dwContext);

			CCardAbilityModifier pBonus = CCardAbilityModifier(
				CCardAbilityModifier::CreateAbilityCallback(this, &CIconOfAncestryCard::CreateBonusAbility));
			pBonus.ApplyTo(this);

			for (int i = 0; i < GetAbilities().GetSize(); ++i)
			{
				CPwrTghAttrEnchantment* pEnchantment = dynamic_cast<CPwrTghAttrEnchantment*>(GetAbilities().GetAt(i).GetPointer());
				if (pEnchantment)
					pEnchantment->StartEnchantment();
			}
			break;
		}
}

counted_ptr<CAbility> CIconOfAncestryCard::CreateBonusAbility(CCard* pCard)
{
	// Creatures you control of the chosen type get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetEnchantmentCardFilter().AddComparer(new CreatureTypeComparer(m_SelectedType, false));
	cpAbility->SetAbilityName(_T("Icon of Ancestry boost"));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CIconOfAncestryCard::BeforeLook(CAbilityAction* pAction)
{
	if (m_SelectedType == SingleCreatureType::Null)
	{
		// No chosen type: look at the cards and put them on the bottom (no card can be chosen)
		CCardFilter filter(_T("a card"), _T("cards"), new FalseCardComparer);
		LookTopToHandRestBottom(GetGame(), pAction->GetController(), 3, 0, 1, &filter);
		return true;
	}

	CCardFilter filter(_T("a creature card of the chosen type"), _T("creature cards of the chosen type"),
		new AndCardComparer(new CardTypeComparer(CardType::Creature, false), new CreatureTypeComparer(m_SelectedType, false)));
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 3, 0, 1, &filter);
	return true;
}

//____________________________________________________________________________
//
CManifoldKeyCard::CManifoldKeyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Manifold Key"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	{
		// {1}, {T}: Untap another target artifact.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				new AndCardComparer(new CardTypeComparer(CardType::Artifact, false), new NegateCardComparer(new SpecificCardComparer(this))),
				FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		AddAbility(cpAbility.GetPointer());
	}
	{
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
}

//____________________________________________________________________________
//
CMaskOfImmolationCard::CMaskOfImmolationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mask of Immolation"), CardType::Artifact | CardType::Equipment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Artifact)
{
	// When this Equipment enters, create a 1/1 red Elemental creature token, then attach this Equipment to it.
	AddEnterTrigger(this, &CMaskOfImmolationCard::BeforeToken);

	// Equipped creature has "Sacrifice this creature: It deals 1 damage to any target." Equip {2}
	// (as Sorcerer's Wand in Dominaria; it can't target planeswalkers)
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CMaskOfImmolationCard::CreateSacrificeAbility)));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMaskOfImmolationCard::BeforeEquip));
	AddAbility(cpAbility.GetPointer());
}

bool CMaskOfImmolationCard::BeforeEquip(CAbilityAction* pAction)
{
	UnequipAll(this);
	return true;
}

bool CMaskOfImmolationCard::BeforeToken(CAbilityAction* pAction)
{
	CreateTokenAndAttach(this, pAction->GetController(), ELEMENTAL_S_TOKEN_NAME, ELEMENTAL_S_TOKEN_ID);
	return true;
}

counted_ptr<CAbility> CMaskOfImmolationCard::CreateSacrificeAbility(CCard* pCard)
{
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(pCard,
			_T(""),
			new AnyCreatureComparer, TRUE,
			Life(-1), PreventableType::Preventable));

	cpAbility->AddSacrificeCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CPortalOfSanctuaryCard::CPortalOfSanctuaryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Portal of Sanctuary"), CardType::Artifact, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Artifact)
{
	// {1}, {T}: Return target creature you control and each Aura attached to it to their owners' hands. Activate only
	// during your turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1"),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPortalOfSanctuaryCard::BeforeReturn));
	AddPlayableIf(this, cpAbility.GetPointer(), &CPortalOfSanctuaryCard::CanActivate);
	AddAbility(cpAbility.GetPointer());
}

BOOL CPortalOfSanctuaryCard::CanActivate(BOOL bIncludeTricks)
{
	return GetGame()->GetActivePlayer() == GetController();
}

bool CPortalOfSanctuaryCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCreature = GetTargetCreature(pAction);
	if (!pCreature)
		return false;

	// The Auras attached to it (on any battlefield)
	CCountedCardContainer auras;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if ((pCard->GetCardType() & CardType::_Aura).Any() && pCard->GetEnchantedOn() == pCreature)
				auras.AddCard(pCard, CardPlacement::Top);
		}
	}

	CPlayer* pController = pAction->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pController).ApplyTo(pCreature);
	for (int i = 0; i < auras.GetSize(); ++i)
		if (auras.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pController).ApplyTo(auras.GetAt(i));
	return false;
}

//____________________________________________________________________________
//
CRetributiveWandCard::CRetributiveWandCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Retributive Wand"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// {3}, {T}: This artifact deals 1 damage to any target.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("3"),
				NewCreatureOrPlaneswalkerComparer(), TRUE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRetributiveWandCard::BeforeDamage1));
		AddAbility(cpAbility.GetPointer());
	}

	// When this artifact is put into a graveyard from the battlefield, it deals 5 damage to any target.
	CTargeting* pTargeting = AddDiesTargetTrigger(this, &CRetributiveWandCard::BeforeDamage5, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(NewCreatureOrPlaneswalkerComparer());
	pTargeting->SetIncludePlayers(TRUE);
}

bool CRetributiveWandCard::BeforeDamage1(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 1);
	return false;
}

bool CRetributiveWandCard::BeforeDamage5(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 5);
	return false;
}

//____________________________________________________________________________
//
CWolfridersSaddleCard::CWolfridersSaddleCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Wolfrider's Saddle"), CardType::Artifact | CardType::Equipment, nID,
		_T("3") GREEN_MANA_TEXT, AbilityType::Artifact)
{
	// When this Equipment enters, create a 2/2 green Wolf creature token, then attach this Equipment to it.
	AddEnterTrigger(this, &CWolfridersSaddleCard::BeforeToken);

	// Equipped creature gets +1/+1 and can't be blocked by more than one creature. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::CantBeBlockedByMultiple);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CWolfridersSaddleCard::BeforeToken(CAbilityAction* pAction)
{
	CreateTokenAndAttach(this, pAction->GetController(), WOLF_K_TOKEN_NAME, WOLF_K_TOKEN_ID);
	return true;
}

//____________________________________________________________________________
//
// The number of creatures with flying that pPlayer controls
static int CountFlyers(CGame* pGame, CPlayer* pPlayer)
{
	CCountedCardContainer creatures;
	GetCreatures(pGame, pPlayer, TRUE, creatures);
	int nCount = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && pCreature->GetCreatureKeyword()->Flying())
			++nCount;
	}
	return nCount;
}

// Exiles every card named strName in the zone of pPlayer
static void ExileNamedCards(CPlayer* pPlayer, ZoneId zoneId, const CString& strName, CPlayer* pByPlayer)
{
	CZone* pZone = pPlayer->GetZoneById(zoneId);
	CCountedCardContainer cards;
	for (int i = 0; i < pZone->GetSize(); ++i)
		if (pZone->GetAt(i)->GetCardName(FALSE) == strName)
			cards.AddCard(pZone->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == zoneId)
			CMoveCardModifier(zoneId, ZoneId::Exile, TRUE, MoveType::Others, pByPlayer).ApplyTo(cards.GetAt(i));
}

//____________________________________________________________________________
//
CAerialAssaultCard::CAerialAssaultCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Aerial Assault"), CardType::Sorcery, nID)
{
	// Destroy target tapped creature. You gain 1 life for each creature you control with flying.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("2") WHITE_MANA_TEXT, Characteristic::Negative, &CAerialAssaultCard::BeforeDestroy);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
}

bool CAerialAssaultCard::BeforeDestroy(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DestroyPermanent(GetTargetCreature(pAction), pController);

	int nCount = CountFlyers(GetGame(), pController);
	if (nCount > 0)
		GainLife(this, pController, nCount);
	return false;
}

//____________________________________________________________________________
//
CAgonizingSyphonCard::CAgonizingSyphonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Agonizing Syphon"), CardType::Sorcery, nID)
{
	// Agonizing Syphon deals 3 damage to any target and you gain 3 life.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT,
			NewCreatureOrPlaneswalkerComparer(), TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAgonizingSyphonCard::BeforeDamage));
	AddSpell(cpSpell.GetPointer());
}

bool CAgonizingSyphonCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 3);
	GainLife(this, pAction->GetController(), 3);
	return false;
}

//____________________________________________________________________________
//
CBloodForBonesCard::CBloodForBonesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blood for Bones"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, sacrifice a creature.
	// Return a creature card from your graveyard to the battlefield, then return another creature card from your graveyard
	// to your hand.
	CGenericSpell* pSpell = AddSorcery(this, _T("3") BLACK_MANA_TEXT, &CBloodForBonesCard::BeforeReturn);
	pSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
}

bool CBloodForBonesCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Battlefield, MoveType::Others);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CCaptivatingGyreCard::CCaptivatingGyreCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Captivating Gyre"), CardType::Sorcery, nID)
{
	// Return up to three target creatures to their owners' hands.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, new AnyCreatureComparer,
		ZoneId::Hand, MoveType::Others);
	pSpell->GetTargeting()->SetSubjectCount(0, 3);
}

//____________________________________________________________________________
//
CChandrasFlameWaveCard::CChandrasFlameWaveCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chandra's Flame Wave"), CardType::Sorcery, nID)
{
	// Chandra's Flame Wave deals 2 damage to target player and each creature that player controls. Search your library
	// and/or graveyard for a card named Chandra, Flame's Fury, reveal it, and put it into your hand. If you search your
	// library this way, shuffle.
	AddPlayerSorcery(this, _T("3") RED_MANA_TEXT RED_MANA_TEXT, &CChandrasFlameWaveCard::BeforeDamage);
}

bool CChandrasFlameWaveCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pPlayer, TRUE, creatures);
		DealDamageToPlayer(this, pPlayer, 2);
		for (int i = 0; i < creatures.GetSize(); ++i)
			DealDamageToCreature(this, creatures.GetAt(i), 2);
	}

	// (the graveyard first, then the library)
	SearchNamedCardToHand(pAction->GetController(), _T("Chandra, Flame's Fury"));
	return false;
}

//____________________________________________________________________________
//
CDevoutDecreeCard::CDevoutDecreeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Devout Decree"), CardType::Sorcery, nID)
{
	// Exile target creature or planeswalker that's black or red. Scry 1.
	CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, _T("1") WHITE_MANA_TEXT,
		new AndCardComparer(NewCreatureOrPlaneswalkerComparer(),
			new OrCardComparer(new CardTypeComparer(CardType::Black, false), new CardTypeComparer(CardType::Red, false))),
		ZoneId::Exile, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDevoutDecreeCard::BeforeScry));
}

bool CDevoutDecreeCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;	// the target is exiled by the spell
}

//____________________________________________________________________________
//
CDrawnFromDreamsCard::CDrawnFromDreamsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Drawn from Dreams"), CardType::Sorcery, nID)
{
	// Look at the top seven cards of your library. Put two of them into your hand and the rest on the bottom of your
	// library in a random order.
	AddSorcery(this, _T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, &CDrawnFromDreamsCard::BeforeLook);
}

bool CDrawnFromDreamsCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 7, 2, 2, CCardFilter::GetFilter(_T("cards")));
	return true;
}

//____________________________________________________________________________
//
CEngulfingEruptionCard::CEngulfingEruptionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Engulfing Eruption"), CardType::Sorcery, nID)
{
	// Engulfing Eruption deals 5 damage to target creature.
	AddDamageSorcery(this, _T("2") RED_MANA_TEXT RED_MANA_TEXT, 5, new AnyCreatureComparer, FALSE);
}

//____________________________________________________________________________
//
CEternalIsolationCard::CEternalIsolationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Eternal Isolation"), CardType::Sorcery, nID)
{
	// Put target creature with power 4 or greater on the bottom of its owner's library.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("1") WHITE_MANA_TEXT, Characteristic::Negative, &CEternalIsolationCard::BeforeBottom);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreaturePowerComparer<std::greater_equal<int>>(4));
}

bool CEternalIsolationCard::BeforeBottom(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	// (as Nezahal: SetToTop(FALSE) puts it on the bottom)
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
	pModifier.SetToTop(FALSE);
	pModifier.ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CFloodOfTearsCard::CFloodOfTearsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Flood of Tears"), CardType::Sorcery, nID)
	, m_PermanentFilter(_T("a permanent card"), _T("permanent cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)))
{
	// Return all nonland permanents to their owners' hands. If you return four or more nontoken permanents you control
	// this way, you may put a permanent card from your hand onto the battlefield.
	AddSorcery(this, _T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, &CFloodOfTearsCard::BeforeReturn);
}

bool CFloodOfTearsCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	CCountedCardContainer cards;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (!pBattlefield->GetAt(i)->GetCardType().IsLand())
				cards.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	int nOwn = 0;
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		BOOL bOwn = pCard->GetController() == pController && !pCard->GetCardType().IsToken();
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pController).ApplyTo(pCard);
		if (bOwn && pCard->GetZoneId() == ZoneId::Hand)
			++nOwn;
	}

	if (nOwn >= 4)
		ChooseAndMove(GetGame(), pController, ZoneId::Hand, 0, 1, &m_PermanentFilter, ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CLegionsEndCard::CLegionsEndCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Legion's End"), CardType::Sorcery, nID)
{
	// Exile target creature an opponent controls with mana value 2 or less and all other creatures that player controls
	// with the same name as that creature. Then that player reveals their hand and exiles all cards with that name from
	// their hand and graveyard.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("1") BLACK_MANA_TEXT, Characteristic::Negative, &CLegionsEndCard::BeforeExile);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(2));
	pSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
}

bool CLegionsEndCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CPlayer* pPlayer = pCard->GetController();
	CPlayer* pController = pAction->GetController();
	CString strName = pCard->GetCardName(FALSE);

	// The target and the other creatures of that player with the same name
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCreature = creatures.GetAt(i);
		if (pCreature->GetZoneId() == ZoneId::Battlefield && pCreature->GetCardName(FALSE) == strName)
			CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController).ApplyTo(pCreature);
	}

	ExileNamedCards(pPlayer, ZoneId::Hand, strName, pController);
	ExileNamedCards(pPlayer, ZoneId::Graveyard, strName, pController);
	return false;
}

//____________________________________________________________________________
//
CRecklessAirStrikeCard::CRecklessAirStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reckless Air Strike"), CardType::Sorcery, nID)
{
	// Choose one -
	// - Reckless Air Strike deals 3 damage to target creature with flying.
	CTargetChgLifeSpell* pDamage = AddDamageSorcery(this, RED_MANA_TEXT, 3,
		new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false)), FALSE);
	pDamage->SetAbilityText(_T("Deals 3 damage to target creature with flying. Casts"));

	// - Destroy target artifact.
	CTargetMoveCardSpell* pDestroy = AddMoveSorcery(this, RED_MANA_TEXT, new CardTypeComparer(CardType::Artifact, false),
		ZoneId::Graveyard, MoveType::Destroy);
	pDestroy->SetAbilityText(_T("Destroy target artifact. Casts"));
}

//____________________________________________________________________________
//
CSchemingSymmetryCard::CSchemingSymmetryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Scheming Symmetry"), CardType::Sorcery, nID)
{
	// Choose two target players. Each of them searches their library for a card, then shuffles and puts that card on top.
	// Note: with two players both are always chosen, so it doesn't target (each player shuffles, then puts the card on top)
	AddSorcery(this, BLACK_MANA_TEXT, &CSchemingSymmetryCard::BeforeSearch);
}

bool CSchemingSymmetryCard::BeforeSearch(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		SearchToTop(GetGame(), GetGame()->GetPlayer(ip), CCardFilter::GetFilter(_T("cards")));
	return true;
}

//____________________________________________________________________________
//
CThoughtDistortionCard::CThoughtDistortionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thought Distortion"), CardType::Sorcery, nID)
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Target opponent reveals their hand. Exile all noncreature, nonland cards from that player's hand and graveyard.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CThoughtDistortionCard::BeforeExile);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
}

bool CThoughtDistortionCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	ZoneId zones[] = { ZoneId::Hand, ZoneId::Graveyard };
	for (int z = 0; z < _countof(zones); ++z)
	{
		CZone* pZone = pPlayer->GetZoneById(zones[z]);
		CCountedCardContainer cards;
		for (int i = 0; i < pZone->GetSize(); ++i)
		{
			CCard* pCard = pZone->GetAt(i);
			if (!pCard->GetCardType().IsCreature() && !pCard->GetCardType().IsLand())
				cards.AddCard(pCard, CardPlacement::Top);
		}
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == zones[z])
				CMoveCardModifier(zones[z], ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(cards.GetAt(i));
	}
	return false;
}

//____________________________________________________________________________
//
CWingedWordsCard::CWingedWordsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Winged Words"), CardType::Sorcery, nID)
{
	// This spell costs {1} less to cast if you control a creature with flying. Draw two cards.
	// (two spells with AddPlayableIf, as Academy Journeymage in Dominaria)
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery, _T("2") BLUE_MANA_TEXT, 2));
		AddPlayableIf(this, cpSpell.GetPointer(), &CWingedWordsCard::HasNoFlyer);
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery, _T("1") BLUE_MANA_TEXT, 2));
		cpSpell->SetMainSpell(FALSE);
		AddPlayableIf(this, cpSpell.GetPointer(), &CWingedWordsCard::HasFlyer);
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CWingedWordsCard::HasNoFlyer(BOOL bIncludeTricks)
{
	return CountFlyers(GetGame(), GetController()) == 0;
}

BOOL CWingedWordsCard::HasFlyer(BOOL bIncludeTricks)
{
	return CountFlyers(GetGame(), GetController()) > 0;
}

//____________________________________________________________________________
//
#define GOLEM_F_TOKEN_NAME		_T("Golem (F)")
#define GOLEM_F_TOKEN_ID		55139

// A permanent card put into a graveyard from the battlefield this turn (recorded by Brought Back)
struct PutIntoGraveyardThisTurnComparer : public CardComparer
{
	PutIntoGraveyardThisTurnComparer(const CBroughtBackCard* pSource) : m_pSource(pSource) {}

	virtual bool operator()(const CCard* value) const
	{
		return m_pSource->WasPutThisTurn(value) == TRUE;
	}

	virtual PutIntoGraveyardThisTurnComparer* Clone() const
	{
		return new PutIntoGraveyardThisTurnComparer(m_pSource);
	}

	const CBroughtBackCard* m_pSource;
};

//____________________________________________________________________________
//
CAetherGustCard::CAetherGustCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Aether Gust"), CardType::Instant, nID)
	, m_PlaceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CAetherGustCard::OnPlaceSelected))
{
	// Choose target spell or permanent that's red or green. Its owner puts it on their choice of the top or bottom of
	// their library.
	CardComparer* pRedGreen = new OrCardComparer(new CardTypeComparer(CardType::Red, false), new CardTypeComparer(CardType::Green, false));
	{
		// A spell (as Memory Lapse in Fifth Edition)
		// Partial: the spell is always put on top of its owner's library.
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT,
				pRedGreen->Clone()));

		cpSpell->SetToZone(ZoneId::Library, TRUE);
		cpSpell->SetAbilityText(_T("Target spell that's red or green. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// A permanent (its owner chooses the top or the bottom)
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT,
				pRedGreen, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Target permanent that's red or green. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherGustCard::BeforePermanent));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CAetherGustCard::BeforePermanent(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s on top of the library"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s on the bottom of the library"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_PlaceSelection.AddSelectionRequest(entries, 1, 1, NULL, pCard->GetOwner(), (DWORD)pCard);
	return false;
}

void CAetherGustCard::OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.SetToTop(it->dwContext == 1);
			pModifier.ApplyTo(pCard);
			break;
		}
}

//____________________________________________________________________________
//
CBroughtBackCard::CBroughtBackCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Brought Back"), CardType::Instant, nID)
	, m_nTurn(-1)
{
	// (records the permanents put into a graveyard from the battlefield this turn, from any zone and without triggering,
	// as Arclight Phoenix in Guilds of Ravnica)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard, FALSE, TRUE, FALSE));

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBroughtBackCard::SetMovedContext));
		AddAbility(cpAbility.GetPointer());
	}

	// Choose up to two target permanent cards in your graveyard that were put there from the battlefield this turn. Return
	// them to the battlefield tapped.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT WHITE_MANA_TEXT,
			new PutIntoGraveyardThisTurnComparer(this),
			ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(0, 2);
	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBroughtBackCard::BeforeReturn));
	AddSpell(cpSpell.GetPointer());
}

BOOL CBroughtBackCard::WasPutThisTurn(const CCard* pCard) const
{
	if (m_nTurn != GetGame()->GetGameTurnNumber())
		return FALSE;
	return std::find(m_Moved.begin(), m_Moved.end(), pCard) != m_Moved.end();
}

bool CBroughtBackCard::SetMovedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (GetGame()->GetGameTurnNumber() != m_nTurn)
	{
		m_nTurn = GetGame()->GetGameTurnNumber();
		m_Moved.clear();
	}
	if (pCard && !pCard->GetCardType().IsToken())
		m_Moved.push_back(pCard);
	return false;
}

bool CBroughtBackCard::BeforeReturn(CAbilityAction* pAction)
{
	// (returned tapped, as Gravewaker in M19)
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Graveyard)
			continue;
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetTapped(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
CDarkRemedyCard::CDarkRemedyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dark Remedy"), CardType::Instant, nID)
{
	// Target creature gets +1/+3 until end of turn.
	AddPumpInstant(this, _T("1") BLACK_MANA_TEXT, +1, +3);
}

//____________________________________________________________________________
//
CFlameSweepCard::CFlameSweepCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Flame Sweep"), CardType::Instant, nID)
{
	// Flame Sweep deals 2 damage to each creature except for creatures you control with flying.
	AddInstant(this, _T("2") RED_MANA_TEXT, &CFlameSweepCard::BeforeDamage);
}

bool CFlameSweepCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
			if (!pCreature || !pCreature->GetCardType().IsCreature())
				continue;
			if (pCreature->GetController() == pController && pCreature->GetCreatureKeyword()->Flying())
				continue;
			creatures.AddCard(pCreature, CardPlacement::Top);
		}
	}
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 2);
	return true;
}

//____________________________________________________________________________
//
CFryCard::CFryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fry"), CardType::Instant, nID)
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Fry deals 5 damage to target creature or planeswalker that's white or blue.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			new AndCardComparer(NewCreatureOrPlaneswalkerComparer(),
				new OrCardComparer(new CardTypeComparer(CardType::White, false), new CardTypeComparer(CardType::Blue, false))),
			FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFryCard::BeforeDamage));
	AddSpell(cpSpell.GetPointer());
}

bool CFryCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToCreatureOrPlaneswalker(this, pAction->GetAssociatedCard(), 5);
	return false;
}

//____________________________________________________________________________
//
CGrowthCycleCard::CGrowthCycleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Growth Cycle"), CardType::Instant, nID)
{
	// Target creature gets +3/+3 until end of turn. It gets an additional +2/+2 until end of turn for each card named
	// Growth Cycle in your graveyard.
	AddCreatureInstant(this, _T("1") GREEN_MANA_TEXT, Characteristic::Positive, &CGrowthCycleCard::BeforePump);
}

bool CGrowthCycleCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (!pCard)
		return false;

	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nCount = 0;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetPrintedCardName() == _T("Growth Cycle"))
			++nCount;

	PumpCreature(pCard, 3 + 2 * nCount, 3 + 2 * nCount);
	return false;
}

//____________________________________________________________________________
//
CInfuriateCard::CInfuriateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Infuriate"), CardType::Instant, nID)
{
	// Target creature gets +3/+2 until end of turn.
	AddPumpInstant(this, RED_MANA_TEXT, +3, +2);
}

//____________________________________________________________________________
//
CMasterfulReplicationCard::CMasterfulReplicationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Masterful Replication"), CardType::Instant, nID)
{
	// Choose one -
	// - Create two 3/3 colorless Golem artifact creature tokens.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Instant,
			_T("5") BLUE_MANA_TEXT,
			GOLEM_F_TOKEN_NAME, GOLEM_F_TOKEN_ID, 2));
	AddSpell(cpSpell.GetPointer());

	// - Choose target artifact you control. Each other artifact you control becomes a copy of that artifact until end of
	// turn.
	// Not implemented: a permanent can't become a copy of another one.
}

//____________________________________________________________________________
//
CNoxiousGraspCard::CNoxiousGraspCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Noxious Grasp"), CardType::Instant, nID)
{
	// Destroy target creature or planeswalker that's green or white. You gain 1 life.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("1") BLACK_MANA_TEXT,
		new AndCardComparer(NewCreatureOrPlaneswalkerComparer(),
			new OrCardComparer(new CardTypeComparer(CardType::Green, false), new CardTypeComparer(CardType::White, false))),
		ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNoxiousGraspCard::BeforeGainLife));
}

bool CNoxiousGraspCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;	// the target is destroyed by the spell
}

//____________________________________________________________________________
//
CSharedSummonsCard::CSharedSummonsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shared Summons"), CardType::Instant, nID)
{
	// Search your library for up to two creature cards with different names, reveal them, put them into your hand, then
	// shuffle.
	AddInstant(this, _T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, &CSharedSummonsCard::BeforeSearch);
}

bool CSharedSummonsCard::BeforeSearch(CAbilityAction* pAction)
{
	// Two searches: the second one excludes the name of the first card (as SearchToHand)
	CPlayer* pController = pAction->GetController();
	CString strName;
	for (int n = 0; n < 2; ++n)
	{
		CCardFilter filter(_T("a creature card"), _T("creature cards"), new CardTypeComparer(CardType::Creature, false));
		if (!strName.IsEmpty())
			filter.AddComparer(new NegateCardComparer(new CardNameComparer(strName)));

		CCountedCardContainer cards;
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
		pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
			CZoneModifier::RoleType::PrimaryPlayer,
			CZoneModifier::RoleType::AllPlayers,
			&filter,
			ZoneId::Hand,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top,
			MoveType::Others,
			CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.ApplyTo(pController);

		if (cards.GetSize() == 0)
			break;
		strName = cards.GetAt(0)->GetPrintedCardName();
	}
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
CTalesEndCard::CTalesEndCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tale's End"), CardType::Instant, nID)
{
	// Counter target activated ability, triggered ability, or legendary spell.
	// Partial: only legendary spells (abilities can't be countered).
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Legendary, false)));
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CVeilOfSummerCard::CVeilOfSummerCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Veil of Summer"), CardType::Instant, nID)
	, m_nTurn(-1)
{
	// (records the turn an opponent casts a blue or black spell, from any zone, as Arclight Phoenix)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack, FALSE, TRUE, FALSE));

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVeilOfSummerCard::SetCastContext));
		AddAbility(cpAbility.GetPointer());
	}

	// Draw a card if an opponent has cast a blue or black spell this turn. Spells you control can't be countered this turn.
	// You and permanents you control gain hexproof from blue and from black until end of turn.
	// Partial: without the hexproof from blue and from black.
	AddInstant(this, GREEN_MANA_TEXT, &CVeilOfSummerCard::BeforeResolution);
}

bool CVeilOfSummerCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast || !pCard || pCard->GetController() == GetController())
		return false;

	if (CardTypeComparer(CardType::Blue, false)(pCard) || CardTypeComparer(CardType::Black, false)(pCard))
		m_nTurn = GetGame()->GetGameTurnNumber();
	return false;
}

bool CVeilOfSummerCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (m_nTurn == GetGame()->GetGameTurnNumber())
		DrawCards(GetGame(), pController, 1);

	// Spells you control can't be countered this turn (as Domri, Anarch of Bolas, with every card)
	int nFilter = reinterpret_cast<int>(CCardFilter::GetFilter(_T("cards")));
	CPlayerEffectModifier(PlayerEffectType::SpellsCantBeCountered, nFilter).ApplyTo(pController);
	CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::SpellsCantBeCountered, nFilter),
		TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater);
	pRemove.ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
#define SPIRIT_S_TOKEN_NAME		_T("Spirit (S)")
#define SPIRIT_S_TOKEN_ID		55076

// "This creature gets +N/+N (and has <keyword>) as long as you have N or more life" (as Serra Ascendant in M11)
static void AddLifeBonus(CCard* pCard, int nLife, int nPower, int nToughness, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			Power(nPower), Life(nToughness)));

	cpAbility->SetConditionWork();
	cpAbility->SetConditionCheckLife();
	cpAbility->SetConditionValue(nLife);
	if (keyword != CreatureKeyword::Null)
	{
		cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(keyword);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	}
	pCard->AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CAngelicGuardianCard::CAngelicGuardianCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angelic Guardian"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	// Whenever one or more creatures you control attack, they gain indestructible until end of turn.
	// (one trigger for each attacking creature, which gives it indestructible)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAngelicGuardianCard::SetAttackContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CAngelicGuardianCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CAngelicGuardianCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attackSubject) const
{
	if (!pCreature || pCreature->GetController() != GetController())
		return false;
	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CAngelicGuardianCard::BeforeIndestructible(TriggeredAbility::TriggeredActionType* pAction)
{
	GainCardKeyword((CCard*)pAction->GetTriggerContext().nValue1, CardKeyword::Indestructible);
	return true;
}

//____________________________________________________________________________
//
bool CAngelOfVitalityCard::s_bGaining = false;

CAngelOfVitalityCard::CAngelOfVitalityCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Vitality"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// If you would gain life, you gain that much life plus 1 instead.
	// Partial: there are no replacement effects on life; whenever you gain life, you gain 1 more life (without the stack).
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAngelOfVitalityCard::SetLifeContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngelOfVitalityCard::BeforeGainLife));
		AddAbility(cpAbility.GetPointer());
	}

	// This creature gets +2/+2 as long as you have 25 or more life.
	AddLifeBonus(this, 25, +2, +2, CreatureKeyword::Null);
}

bool CAngelOfVitalityCard::SetLifeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return !s_bGaining && nToLife > nFromLife;
}

bool CAngelOfVitalityCard::BeforeGainLife(CAbilityAction* pAction)
{
	s_bGaining = true;
	GainLife(this, pAction->GetController(), 1);
	s_bGaining = false;
	return true;
}

//____________________________________________________________________________
//
CApostleOfPurifyingLightCard::CApostleOfPurifyingLightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Apostle of Purifying Light"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Protection from black
	GetCardKeyword()->AddProtection(CardKeyword::ProtectionFromBlack, FALSE);

	// {2}: Exile target card from a graveyard.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2"),
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CBattalionFootSoldierCard::CBattalionFootSoldierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Battalion Foot Soldier"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_NameFilter(_T("a card named Battalion Foot Soldier"), _T("cards named Battalion Foot Soldier"),
		new CardNameComparer(_T("Battalion Foot Soldier")))
{
	// When this creature enters, you may search your library for any number of cards named Battalion Foot Soldier,
	// reveal them, put them into your hand, then shuffle.
	AddEnterTrigger(this, &CBattalionFootSoldierCard::BeforeSearch, true);
}

bool CBattalionFootSoldierCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 99, &m_NameFilter);
	return true;
}

//____________________________________________________________________________
//
CBishopOfWingsCard::CBishopOfWingsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bishop of Wings"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(1), Life(4))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;
	{
		// Whenever an Angel you control enters, you gain 4 life. (as River Sneak)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Angel), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBishopOfWingsCard::BeforeGainLife));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever an Angel you control dies, create a 1/1 white Spirit creature token with flying.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Angel), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBishopOfWingsCard::BeforeSpirit));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBishopOfWingsCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 4);
	return true;
}

bool CBishopOfWingsCard::BeforeSpirit(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), SPIRIT_S_TOKEN_NAME, SPIRIT_S_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CCavalierOfDawnCard::CCavalierOfDawnCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cavalier of Dawn"), CardType::Creature, CREATURE_TYPE2(Elemental, Knight), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(6))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, destroy up to one target nonland permanent. Its controller creates a 3/3 colorless Golem
	// artifact creature token.
	{
		CTargeting* pTargeting = AddEnterTargetTrigger(this, &CCavalierOfDawnCard::BeforeDestroy, false, Characteristic::Negative);
		pTargeting->GetSubjectCardFilter().RemoveAllComparers();
		pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
		pTargeting->SetSubjectCount(0, 1);
	}

	// When this creature dies, return target artifact or enchantment card from your graveyard to your hand.
	{
		CTargeting* pTargeting = AddDiesTargetTrigger(this, &CCavalierOfDawnCard::BeforeReturn, Characteristic::Positive);
		pTargeting->SetSubjectZoneId(ZoneId::Graveyard);
		pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false));
		pTargeting->SetIncludeControllerCardsOnly();
	}
}

bool CCavalierOfDawnCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pPlayer = pCard->GetController();
	DestroyPermanent(pCard, pAction->GetController());
	CTokenCreationModifier(GetGame(), GOLEM_F_TOKEN_NAME, GOLEM_F_TOKEN_ID, 1).ApplyTo(pPlayer);
	return false;
}

bool CCavalierOfDawnCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CDawningAngelCard::CDawningAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dawning Angel"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you gain 4 life.
	AddEnterTrigger(this, &CDawningAngelCard::BeforeGainLife);
}

bool CDawningAngelCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 4);
	return true;
}

//____________________________________________________________________________
//
CGoldmaneGriffinCard::CGoldmaneGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Goldmane Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, you may search your library and/or graveyard for a card named Ajani, Inspiring Leader,
	// reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CGoldmaneGriffinCard::BeforeSearch, true);
}

bool CGoldmaneGriffinCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Ajani, Inspiring Leader"));
	return true;
}

//____________________________________________________________________________
//
CHangedExecutionerCard::CHangedExecutionerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Hanged Executioner"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("2") WHITE_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, create a 1/1 white Spirit creature token with flying.
	AddEnterTrigger(this, &CHangedExecutionerCard::BeforeToken);

	// {3}{W}, Exile this creature: Exile target creature.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("3") WHITE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpAbility->AddExileCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

bool CHangedExecutionerCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), SPIRIT_S_TOKEN_NAME, SPIRIT_S_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CHeraldOfTheSunCard::CHeraldOfTheSunCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Herald of the Sun"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// {3}{W}: Put a +1/+1 counter on another target creature with flying.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("3") WHITE_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer,
				new AndCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false), new NegateCardComparer(new SpecificCardComparer(this)))),
			FALSE));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CImperialOutriderCard::CImperialOutriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Imperial Outrider"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(1), Life(5))
{
}

//____________________________________________________________________________
//
CLoxodonLifechanterCard::CLoxodonLifechanterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loxodon Lifechanter"), CardType::Creature, CREATURE_TYPE2(Elephant, Cleric), nID,
		_T("5") WHITE_MANA_TEXT, Power(4), Life(6))
{
	// When this creature enters, you may have your life total become the total toughness of creatures you control.
	AddEnterTrigger(this, &CLoxodonLifechanterCard::BeforeSetLife, true);

	// {5}{W}: This creature gets +X/+X until end of turn, where X is your life total.
	AddPumpAbility(this, _T("5") WHITE_MANA_TEXT, _T("+X/+X until end of turn, where X is your life total. Activates"),
		&CLoxodonLifechanterCard::BeforePump);
}

bool CLoxodonLifechanterCard::BeforeSetLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, TRUE, creatures);
	int nTotal = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature)
			nTotal += GET_INTEGER(pCreature->GetToughness());
	}

	// (as Dominaria: the difference with the current life total)
	Life nDelta = Life(nTotal) - pController->GetLife();
	if (nDelta != Life(0))
		CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pController);
	return true;
}

bool CLoxodonLifechanterCard::BeforePump(CAbilityAction* pAction)
{
	int nX = GET_INTEGER(pAction->GetController()->GetLife());
	if (nX > 0)
		PumpCreature(this, nX, nX);
	return true;
}

//____________________________________________________________________________
//
CLoyalPegasusCard::CLoyalPegasusCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Loyal Pegasus"), CardType::Creature, CREATURE_TYPE(Pegasus), nID,
		WHITE_MANA_TEXT, Power(2), Life(1))
{
	// This creature can't attack or block alone.
	// Not implemented: there is no "can't attack or block alone" in the engine.
}

//____________________________________________________________________________
//
CSavannahSageCard::CSavannahSageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Savannah Sage"), CardType::Creature, CREATURE_TYPE2(Cat, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, you gain 2 life.
	AddEnterTrigger(this, &CSavannahSageCard::BeforeGainLife);
}

bool CSavannahSageCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CSepharaSkysBladeCard::CSepharaSkysBladeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sephara, Sky's Blade"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(7), Life(7))
	, m_FlyerFilter(_T("a creature with flying"), _T("creatures with flying"),
		new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false)))
{
	// Flying, lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// You may pay {W} and tap four untapped creatures you control with flying rather than pay this spell's mana cost.
	// (an alternative cost as a second spell, as Zahid, Djinn of the Lamp)
	{
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), WHITE_MANA_TEXT, TRUE));

		cpSpell->GetCost().AddTapCardCost(4, &m_FlyerFilter);
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityText(_T("Pay {W} and tap four creatures with flying. Casts"));
		AddSpell(cpSpell.GetPointer());
	}

	// Other creatures you control with flying have indestructible.
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false), new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+0), Life(+0)));

		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Indestructible);
		cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSquadCaptainCard::CSquadCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Squad Captain"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("4") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CSquadCaptainCard::OnZoneChanged))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// This creature enters with a +1/+1 counter on it for each other creature you control. (as Golgari Raiders)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CSquadCaptainCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), GetController(), TRUE, creatures);
		int nCount = 0;
		for (int i = 0; i < creatures.GetSize(); ++i)
			if (creatures.GetAt(i) != this)
				++nCount;
		if (nCount > 0)
			CCardCounterModifier(_T("+1/+1"), nCount).ApplyTo(this);
	}
}

//____________________________________________________________________________
//
CStarfieldMysticCard::CStarfieldMysticCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Starfield Mystic"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	{
		// Enchantment spells you cast cost {1} less to cast.
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new CardTypeComparer(CardType::_Enchantment, false),
				_T("1")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever an enchantment you control is put into a graveyard from the battlefield, put a +1/+1 counter on this
		// creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("enchantments")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStarfieldMysticCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CStarfieldMysticCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CSteadfastSentryCard::CSteadfastSentryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steadfast Sentry"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature dies, put a +1/+1 counter on target creature you control.
	CTargeting* pTargeting = AddDiesTargetTrigger(this, &CSteadfastSentryCard::BeforeCounter, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CSteadfastSentryCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(pAction->GetAssociatedCard(), 1);
	return false;
}

//____________________________________________________________________________
//
CTwinbladePaladinCard::CTwinbladePaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Twinblade Paladin"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	{
		// Whenever you gain life, put a +1/+1 counter on this creature. (as Ajani's Pridemate)
		typedef
			TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTwinbladePaladinCard::SetTriggerContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}

	// As long as you have 25 or more life, this creature has double strike.
	AddLifeBonus(this, 25, 0, 0, CreatureKeyword::DoubleStrike);
}

bool CTwinbladePaladinCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

//____________________________________________________________________________
//
#define ELEMENTAL_AZ_TOKEN_NAME		_T("Elemental (AZ)")
#define ELEMENTAL_AZ_TOKEN_ID		64140

// The player has three or more land cards in their graveyard (Elvish Reclaimer)
struct ThreeLandsInGraveyardComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		CZone* pGraveyard = value->GetController()->GetZoneById(ZoneId::Graveyard);
		return CCardFilter::GetFilter(_T("lands"))->CountIncluded(pGraveyard->GetCardContainer()) >= 3;
	}

	virtual ThreeLandsInGraveyardComparer* Clone() const
	{
		return new ThreeLandsInGraveyardComparer();
	}
};

//____________________________________________________________________________
//
CBarkhideTrollCard::CBarkhideTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Barkhide Troll"), CardType::Creature, CREATURE_TYPE(Troll), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// This creature enters with a +1/+1 counter on it.
	GetCounterContainer()->ScheduleCounter(_T("+1/+1"), 1, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// {1}, Remove a +1/+1 counter from this creature: This creature gains hexproof until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("+1/+1")), -1);
	cpAbility->SetAbilityText(_T("Hexproof until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBarkhideTrollCard::BeforeHexproof));
	AddAbility(cpAbility.GetPointer());
}

bool CBarkhideTrollCard::BeforeHexproof(CAbilityAction* pAction)
{
	GainCardKeyword(this, CardKeyword::Hexproof);
	return true;
}

//____________________________________________________________________________
//
CBrightwoodTrackerCard::CBrightwoodTrackerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brightwood Tracker"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(4))
{
	// {5}{G}, {T}: Look at the top four cards of your library. You may reveal a creature card from among them and put it
	// into your hand. Put the rest on the bottom of your library in a random order.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("5") GREEN_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Look at the top four cards of your library. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBrightwoodTrackerCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

bool CBrightwoodTrackerCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 4, 0, 1, CCardFilter::GetFilter(_T("creatures")));
	return true;
}

//____________________________________________________________________________
//
CCavalierOfThornsCard::CCavalierOfThornsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cavalier of Thorns"), CardType::Creature, CREATURE_TYPE2(Elemental, Knight), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(6))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// When this creature enters, reveal the top five cards of your library. Put a land card from among them onto the
	// battlefield and the rest into your graveyard.
	AddEnterTrigger(this, &CCavalierOfThornsCard::BeforeReveal);

	// When this creature dies, you may exile it. If you do, put another target card from your graveyard on top of your
	// library.
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCavalierOfThornsCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCavalierOfThornsCard::BeforeReveal(CAbilityAction* pAction)
{
	// (as Ral, Izzet Viceroy: a selection and the rest to the graveyard)
	CPlayer* pController = pAction->GetController();
	int nCount = pController->GetZoneById(ZoneId::Library)->GetSize();
	if (nCount > 5)
		nCount = 5;
	if (nCount <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nCount, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::AllPlayers,
		CCardFilter::GetFilter(_T("lands")),
		ZoneId::Battlefield,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.SetReorderInformation(true, ZoneId::Graveyard, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pModifier.ApplyTo(pController);
	return true;
}

bool CCavalierOfThornsCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Graveyard)
		return false;

	CPlayer* pController = pAction->GetController();
	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pController).ApplyTo(this);

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pController);
		pModifier.SetToTop(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
CElvishReclaimerCard::CElvishReclaimerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elvish Reclaimer"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		GREEN_MANA_TEXT, Power(1), Life(2))
{
	{
		// This creature gets +2/+2 as long as there are three or more land cards in your graveyard.
		// (a comparer on the card itself, as the city's blessing in Rivals of Ixalan)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new SpecificCardComparer(this), new ThreeLandsInGraveyardComparer),
				Power(+2), Life(+2)));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, {T}, Sacrifice a land: Search your library for a land card, put it onto the battlefield tapped, then shuffle.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("lands")));
		cpAbility->SetAbilityText(_T("Search your library for a land card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CElvishReclaimerCard::BeforeSearch));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CElvishReclaimerCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("lands")), TRUE);
	return true;
}

//____________________________________________________________________________
//
CEtherealElkCard::CEtherealElkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ethereal Elk"), CardType::Creature, CREATURE_TYPE2(Elk, Spirit), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, you may search your library and/or graveyard for a card named Vivien, Nature's Avenger,
	// reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CEtherealElkCard::BeforeSearch, true);
}

bool CEtherealElkCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Vivien, Nature's Avenger"));
	return true;
}

//____________________________________________________________________________
//
CFerociousPupCard::CFerociousPupCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ferocious Pup"), CardType::Creature, CREATURE_TYPE(Wolf), nID,
		_T("2") GREEN_MANA_TEXT, Power(0), Life(1))
{
	// When this creature enters, create a 2/2 green Wolf creature token.
	AddEnterTrigger(this, &CFerociousPupCard::BeforeToken);
}

bool CFerociousPupCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), WOLF_K_TOKEN_NAME, WOLF_K_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CGargosViciousWatcherCard::CGargosViciousWatcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gargos, Vicious Watcher"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Hydra), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(8), Life(7))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	{
		// Hydra spells you cast cost {4} less to cast.
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Hydra), false),
				_T("4")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever a creature you control becomes the target of a spell, Gargos fights up to one target creature you don't
		// control. (CWhenSubjectTargeted, as Druid of Horns in M19, with a target)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
									 CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, FALSE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetSubjectCount(0, 1);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGargosViciousWatcherCard::SetTargetedContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGargosViciousWatcherCard::BeforeFight));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGargosViciousWatcherCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetController() != GetController())
		return false;

	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	return pTop && pTop->IsSpell();
}

bool CGargosViciousWatcherCard::BeforeFight(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && GetZoneId() == ZoneId::Battlefield)
		Fight(this, pCard);
	return false;
}

//____________________________________________________________________________
//
CGnarlbackRhinoCard::CGnarlbackRhinoCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gnarlback Rhino"), CardType::Creature, CREATURE_TYPE(Rhino), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_pLastSpell(NULL)
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever you cast a spell that targets this creature, draw a card. (as Druid of Horns in M19)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGnarlbackRhinoCard::SetTargetedContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGnarlbackRhinoCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CGnarlbackRhinoCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	if (!pPlayer || pPlayer != GetController())
		return false;

	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	if (!pTop || !pTop->IsSpell() || !pTop->GetAbility())
		return false;

	CCard* pSpellCard = pTop->GetAbility()->GetCard();
	if (!pSpellCard || pSpellCard->GetController() != GetController() || pTop == m_pLastSpell)
		return false;
	m_pLastSpell = pTop;
	return true;
}

bool CGnarlbackRhinoCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CHealerOfTheGladeCard::CHealerOfTheGladeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Healer of the Glade"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		GREEN_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, you gain 3 life.
	AddEnterTrigger(this, &CHealerOfTheGladeCard::BeforeGainLife);
}

bool CHealerOfTheGladeCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CHowlingGiantCard::CHowlingGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Howling Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Druid), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// When this creature enters, create two 2/2 green Wolf creature tokens.
	AddEnterTrigger(this, &CHowlingGiantCard::BeforeTokens);
}

bool CHowlingGiantCard::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), WOLF_K_TOKEN_NAME, WOLF_K_TOKEN_ID, 2).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CLeafkinDruidCard::CLeafkinDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Leafkin Druid"), CardType::Creature, CREATURE_TYPE2(Elemental, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(0), Life(3))
{
	// {T}: Add {G}. If you control four or more creatures, add {G}{G} instead.
	// (one mana ability for each case, as Mox Amber in Dominaria)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), &CLeafkinDruidCard::HasFewCreatures);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT GREEN_MANA_TEXT));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), &CLeafkinDruidCard::HasFourCreatures);
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CLeafkinDruidCard::HasFewCreatures(BOOL bIncludeTricks)
{
	return CountCreatures(GetGame(), GetController()) < 4;
}

BOOL CLeafkinDruidCard::HasFourCreatures(BOOL bIncludeTricks)
{
	return CountCreatures(GetGame(), GetController()) >= 4;
}

//____________________________________________________________________________
//
CLoamingShamanCard::CLoamingShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loaming Shaman"), CardType::Creature, CREATURE_TYPE2(Centaur, Shaman), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, target player shuffles any number of target cards from their graveyard into their library.
	// Partial: the cards are chosen on resolution by that player (they aren't targets).
	AddEnterTargetPlayerTrigger(this, &CLoamingShamanCard::BeforeShuffle, Characteristic::Positive);
}

bool CLoamingShamanCard::BeforeShuffle(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	ChooseAndMove(GetGame(), pPlayer, ZoneId::Graveyard, 0, 99, CCardFilter::GetFilter(_T("cards")), ZoneId::Library, MoveType::Others);
	pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
	return false;
}

//____________________________________________________________________________
//
CNightpackAmbusherCard::CNightpackAmbusherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nightpack Ambusher"), CardType::Creature, CREATURE_TYPE(Wolf), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_nTurn(-1)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	{
		// Other Wolves and Werewolves you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(
					new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Wolf), false), new CreatureTypeComparer(CREATURE_TYPE(Werewolf), false)),
					new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+1), Life(+1)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// (records the turns its controller casts a spell, from any zone and without triggering, as Arclight Phoenix)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack, FALSE, TRUE, FALSE));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNightpackAmbusherCard::SetCastContext));
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your end step, if you didn't cast a spell this turn, create a 2/2 green Wolf creature token.
	AddStepTrigger(this, NodeId::EndStep, false, &CNightpackAmbusherCard::SetEndStepContext, &CNightpackAmbusherCard::BeforeToken);
}

bool CNightpackAmbusherCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType == MoveType::Cast)
		m_nTurn = GetGame()->GetGameTurnNumber();
	return false;
}

bool CNightpackAmbusherCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return m_nTurn != GetGame()->GetGameTurnNumber();
}

bool CNightpackAmbusherCard::BeforeToken(CAbilityAction* pAction)
{
	if (m_nTurn == GetGame()->GetGameTurnNumber())
		return true;
	CTokenCreationModifier(GetGame(), WOLF_K_TOKEN_NAME, WOLF_K_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
COvergrowthElementalCard::COvergrowthElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Overgrowth Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	{
		// When this creature enters, put a +1/+1 counter on another target Elemental you control.
		CTargeting* pTargeting = AddEnterTargetTrigger(this, &COvergrowthElementalCard::BeforeCounter, false, Characteristic::Positive);
		pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false));
		pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		pTargeting->SetIncludeControllerCardsOnly();
	}
	{
		// Whenever another creature you control dies, you gain 1 life. If that creature was an Elemental, put a +1/+1
		// counter on this creature. (Elemental or not in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COvergrowthElementalCard::SetDiesContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &COvergrowthElementalCard::BeforeGainLife));
		AddAbility(cpAbility.GetPointer());
	}
}

bool COvergrowthElementalCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(pAction->GetAssociatedCard(), 1);
	return false;
}

bool COvergrowthElementalCard::SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard == this)
		return false;
	triggerContext.nValue1 = CreatureTypeComparer(CREATURE_TYPE(Elemental), false)(pCard) ? 1 : 0;
	return true;
}

bool COvergrowthElementalCard::BeforeGainLife(TriggeredAbility::TriggeredActionType* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	if (pAction->GetTriggerContext().nValue1 == 1)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CShiftingCeratopsCard::CShiftingCeratopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shifting Ceratops"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(4))
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Protection from blue
	GetCardKeyword()->AddProtection(CardKeyword::ProtectionFromBlue, FALSE);

	// {G}: This creature gains your choice of reach, trample, or haste until end of turn. (one ability for each)
	AddPumpAbility(this, GREEN_MANA_TEXT, _T("Reach until end of turn. Activates"), &CShiftingCeratopsCard::BeforeReach);
	AddPumpAbility(this, GREEN_MANA_TEXT, _T("Trample until end of turn. Activates"), &CShiftingCeratopsCard::BeforeTrample);
	AddPumpAbility(this, GREEN_MANA_TEXT, _T("Haste until end of turn. Activates"), &CShiftingCeratopsCard::BeforeHaste);
}

bool CShiftingCeratopsCard::BeforeReach(CAbilityAction* pAction)
{
	PumpCreature(this, 0, 0, CreatureKeyword::Reach);
	return true;
}

bool CShiftingCeratopsCard::BeforeTrample(CAbilityAction* pAction)
{
	PumpCreature(this, 0, 0, CreatureKeyword::Trample);
	return true;
}

bool CShiftingCeratopsCard::BeforeHaste(CAbilityAction* pAction)
{
	PumpCreature(this, 0, 0, CreatureKeyword::Haste);
	return true;
}

//____________________________________________________________________________
//
CSilverbackShamanCard::CSilverbackShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Silverback Shaman"), CardType::Creature, CREATURE_TYPE2(Ape, Shaman), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature dies, draw a card.
	AddDiesTrigger(this, &CSilverbackShamanCard::BeforeDraw);
}

bool CSilverbackShamanCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CThicketCrasherCard::CThicketCrasherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thicket Crasher"), CardType::Creature, CREATURE_TYPE2(Elemental, Rhino), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Other Elementals you control have trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false), new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+0), Life(+0), CreatureKeyword::Trample));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CViviensCrocodileCard::CViviensCrocodileCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vivien's Crocodile"), CardType::Creature, CREATURE_TYPE2(Crocodile, Spirit), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// This creature gets +1/+1 as long as you control a Vivien planeswalker.
	AddPlaneswalkerTypeBonus(this, PlaneswalkerType::Vivien, +1, +1, CreatureKeyword::Null);
}

//____________________________________________________________________________
//
CVoraciousHydraCard::CVoraciousHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Voracious Hydra"), CardType::Creature, CREATURE_TYPE(Hydra), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(1))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CVoraciousHydraCard::OnZoneChanged))
	, m_nX(0)
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// {X}{G}{G}. This creature enters with X +1/+1 counters on it.
	// (the main spell can't be cast; a spell with {X} remembers X, as Worldsoul Colossus in Guilds of Ravnica)
	AddPlayableIf(this, GetSpells().GetAt(0), &CVoraciousHydraCard::Never);
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Creature, GREEN_MANA_TEXT GREEN_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
		cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVoraciousHydraCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// When this creature enters, choose one - Double the number of +1/+1 counters on this creature; or this creature fights
	// target creature you don't control.
	// (up to one target: with a target it fights it, without a target it doubles its counters)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CVoraciousHydraCard::BeforeMode, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
	pTargeting->SetSubjectCount(0, 1);
}

bool CVoraciousHydraCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	return true;
}

void CVoraciousHydraCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
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

bool CVoraciousHydraCard::BeforeMode(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return false;

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard)
	{
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			Fight(this, pCard);
	}
	else
		DoublePlusCounters(this);
	return false;
}

//____________________________________________________________________________
//
CWakerootElementalCard::CWakerootElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wakeroot Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// {G}{G}{G}{G}{G}: Untap target land you control. It becomes a 5/5 Elemental creature with haste. It's still a land.
	// (as Nissa, Who Shakes the World: IsAlsoA token Elemental (AZ) in ATokens)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false), FALSE));

	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWakerootElementalCard::BeforeAnimate));
	AddAbility(cpAbility.GetPointer());
}

bool CWakerootElementalCard::BeforeAnimate(CAbilityAction* pAction)
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (!pLand || pLand->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardOrientationModifier(FALSE).ApplyTo(pLand);
	if (!pLand->GetIsAlsoA())
		CCardIsAlsoAModifier(ELEMENTAL_AZ_TOKEN_NAME, ELEMENTAL_AZ_TOKEN_ID, pAction->GetController()).ApplyTo(pLand);
	return false;
}

//____________________________________________________________________________
//
CWoodlandChampionCard::CWoodlandChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Woodland Champion"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Whenever one or more tokens you control enter, put that many +1/+1 counters on this creature.
	// (one trigger for each token, each one puts a counter)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Token, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWoodlandChampionCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CWoodlandChampionCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CWoodlandMysticCard::CWoodlandMysticCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Woodland Mystic"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(1))
{
	// {T}: Add {G}.
	AddTapManaAbility(this, GREEN_MANA_TEXT);
}

//____________________________________________________________________________
//
// An attack trigger on any target: a player, a creature or a planeswalker (with DealDamageToAnyTarget in the callback)
template <class T>
static CTargeting* AddSelfAttackAnyTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(pCard, callback, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(NewCreatureOrPlaneswalkerComparer());
	pTargeting->SetIncludePlayers(TRUE);
	return pTargeting;
}

//____________________________________________________________________________
//
CCavalierOfFlameCard::CCavalierOfFlameCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cavalier of Flame"), CardType::Creature, CREATURE_TYPE2(Elemental, Knight), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(5))
{
	// {1}{R}: Creatures you control get +1/+0 and gain haste until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("Creatures you control get +1/+0 and gain haste until end of turn. Activates"),
		&CCavalierOfFlameCard::BeforePump);

	// When this creature enters, discard any number of cards, then draw that many cards.
	AddEnterTrigger(this, &CCavalierOfFlameCard::BeforeRummage);

	// When this creature dies, it deals X damage to each opponent and each planeswalker they control, where X is the
	// number of land cards in your graveyard.
	AddDiesTrigger(this, &CCavalierOfFlameCard::BeforeDamage);
}

bool CCavalierOfFlameCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, 0, CreatureKeyword::Haste);
	return true;
}

bool CCavalierOfFlameCard::BeforeRummage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	int nBefore = pHand->GetSize();
	ChooseAndMove(GetGame(), pController, ZoneId::Hand, 0, nBefore, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Graveyard, MoveType::Discard);
	int nDiscarded = nBefore - pHand->GetSize();
	if (nDiscarded > 0)
		DrawCards(GetGame(), pController, nDiscarded);
	return true;
}

bool CCavalierOfFlameCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nX = CCardFilter::GetFilter(_T("lands"))->CountIncluded(pController->GetZoneById(ZoneId::Graveyard)->GetCardContainer());
	if (nX <= 0)
		return true;

	DamageEachOpponent(this, pController, nX);
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
			DealDamageToCreatureOrPlaneswalker(this, planeswalkers.GetAt(i), nX);
	}
	return true;
}

//____________________________________________________________________________
//
CChandrasEmbercatCard::CChandrasEmbercatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Chandra's Embercat"), CardType::Creature, CREATURE_TYPE2(Elemental, Cat), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// {T}: Add {R}. Spend this mana only to cast an Elemental spell or a Chandra planeswalker spell.
	// Partial: the mana isn't restricted (the engine has no restricted mana).
	AddTapManaAbility(this, RED_MANA_TEXT);
}

//____________________________________________________________________________
//
CDaggersailAeronautCard::CDaggersailAeronautCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Daggersail Aeronaut"), CardType::Creature, CREATURE_TYPE(Goblin), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(2))
	, m_DuringYourTurn(this)
{
	// During your turn, this creature has flying. (CDuringYourTurnSupport, as Sorin, Vengeful Bloodlord)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::Flying));
	AddAbility(cpAbility.GetPointer());
	m_DuringYourTurn.Add(cpAbility.GetPointer());
	m_DuringYourTurn.AddTurnTriggers();
}

//____________________________________________________________________________
//
CDestructiveDiggerCard::CDestructiveDiggerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Destructive Digger"), CardType::Creature, CREATURE_TYPE(Goblin), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
	, m_SacrificeFilter(_T("an artifact or land"), _T("artifacts or lands"),
		new CardTypeComparer(CardType::Artifact | CardType::_Land, false))
{
	// {3}, {T}, Sacrifice an artifact or land: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3"), 1));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CDrakusethMawOfFlamesCard::CDrakusethMawOfFlamesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Drakuseth, Maw of Flames"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Dragon), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(7), Life(7))
{
	// Whenever Drakuseth attacks, Drakuseth deals 4 damage to any target and 3 damage to each of up to two other targets.
	// Partial: three attack triggers (4 damage to a target, and 3 damage to up to one target twice); the targets aren't
	// required to be different.
	AddSelfAttackAnyTargetTrigger(this, &CDrakusethMawOfFlamesCard::BeforeDamage4);
	AddSelfAttackAnyTargetTrigger(this, &CDrakusethMawOfFlamesCard::BeforeDamage3)->SetSubjectCount(0, 1);
	AddSelfAttackAnyTargetTrigger(this, &CDrakusethMawOfFlamesCard::BeforeDamage3)->SetSubjectCount(0, 1);
}

bool CDrakusethMawOfFlamesCard::BeforeDamage4(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 4);
	return false;
}

bool CDrakusethMawOfFlamesCard::BeforeDamage3(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 3);
	return false;
}

//____________________________________________________________________________
//
CGlintHornBuccaneerCard::CGlintHornBuccaneerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glint-Horn Buccaneer"), CardType::Creature, CREATURE_TYPE2(Minotaur, Pirate), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, Power(2), Life(4))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	{
		// Whenever you discard a card, this creature deals 1 damage to each opponent.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGlintHornBuccaneerCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{R}, Discard a card: Draw a card. Activate only if this creature is attacking.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("1") RED_MANA_TEXT, 1));

		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		AddPlayableIf(this, cpAbility.GetPointer(), &CGlintHornBuccaneerCard::IsAttackingNow);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGlintHornBuccaneerCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

BOOL CGlintHornBuccaneerCard::IsAttackingNow(BOOL bIncludeTricks)
{
	return IsAttacking();
}

//____________________________________________________________________________
//
CGoblinBirdGrabberCard::CGoblinBirdGrabberCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Bird-Grabber"), CardType::Creature, CREATURE_TYPE(Goblin), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// {R}: This creature gains flying until end of turn. Activate only if you control a creature with flying.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			RED_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Flying until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGoblinBirdGrabberCard::BeforeFlying));
	AddPlayableIf(this, cpAbility.GetPointer(), &CGoblinBirdGrabberCard::ControlsFlyer);
	AddAbility(cpAbility.GetPointer());
}

bool CGoblinBirdGrabberCard::BeforeFlying(CAbilityAction* pAction)
{
	PumpCreature(this, 0, 0, CreatureKeyword::Flying);
	return true;
}

BOOL CGoblinBirdGrabberCard::ControlsFlyer(BOOL bIncludeTricks)
{
	return CountFlyers(GetGame(), GetController()) > 0;
}

//____________________________________________________________________________
//
CGoblinSmugglerCard::CGoblinSmugglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Smuggler"), CardType::Creature, CREATURE_TYPE2(Goblin, Rogue), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// {T}: Another target creature with power 2 or less can't be blocked this turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T(""),
			Power(+0), Life(+0),
			CreatureKeyword::Unblockable, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreaturePowerComparer<std::less_equal<int>>(2));
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CImmortalPhoenixCard::CImmortalPhoenixCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Immortal Phoenix"), CardType::Creature, CREATURE_TYPE(Phoenix), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(3))
{
	// When this creature dies, return it to its owner's hand.
	AddDiesTrigger(this, &CImmortalPhoenixCard::BeforeReturn);
}

bool CImmortalPhoenixCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, GetOwner()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CLavakinBrawlerCard::CLavakinBrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lavakin Brawler"), CardType::Creature, CREATURE_TYPE2(Elemental, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(4))
{
	// Whenever this creature attacks, it gets +1/+0 until end of turn for each Elemental you control.
	AddSelfAttackTrigger(this, &CLavakinBrawlerCard::BeforePump);
}

bool CLavakinBrawlerCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer elementals;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Elemental), elementals);
	if (elementals.GetSize() > 0)
		PumpCreature(this, elementals.GetSize(), 0);
	return true;
}

//____________________________________________________________________________
//
CMaraudingRaptorCard::CMaraudingRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Marauding Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(3))
{
	{
		// Creature spells you cast cost {1} less to cast.
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new AnyCreatureComparer,
				_T("1")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever another creature you control enters, this creature deals 2 damage to it. If a Dinosaur is dealt damage
		// this way, this creature gets +2/+0 until end of turn. (the creature in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMaraudingRaptorCard::SetEnterContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CMaraudingRaptorCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMaraudingRaptorCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard == this)
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CMaraudingRaptorCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)pAction->GetTriggerContext().nValue1);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	BOOL bDinosaur = CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false)(pCreature);
	DealDamageToCreature(this, pCreature, 2);
	if (bDinosaur && GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, 0);
	return true;
}

//____________________________________________________________________________
//
CNimbleBirdstickerCard::CNimbleBirdstickerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nimble Birdsticker"), CardType::Creature, CREATURE_TYPE(Goblin), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);
}

//____________________________________________________________________________
//
CPackMastiffCard::CPackMastiffCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pack Mastiff"), CardType::Creature, CREATURE_TYPE(Dog), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// {1}{R}: Each creature you control named Pack Mastiff gets +1/+0 until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("Each creature you control named Pack Mastiff gets +1/+0 until end of turn. Activates"),
		&CPackMastiffCard::BeforePump);
}

bool CPackMastiffCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetCardName(FALSE) == _T("Pack Mastiff"))
			PumpCreature(creatures.GetAt(i), +1, 0);
	return true;
}

//____________________________________________________________________________
//
CPyroclasticElementalCard::CPyroclasticElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pyroclastic Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(4))
{
	// {1}{R}{R}: This creature deals 1 damage to target player.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("1") RED_MANA_TEXT RED_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE,
			Life(-1), PreventableType::Preventable));

	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CRapaciousDragonCard::CRapaciousDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rapacious Dragon"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("4") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, create two Treasure tokens.
	AddEnterTrigger(this, &CRapaciousDragonCard::BeforeTreasures);
}

bool CRapaciousDragonCard::BeforeTreasures(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 2);
	return true;
}

//____________________________________________________________________________
//
CScamperingScorcherCard::CScamperingScorcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scampering Scorcher"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("3") RED_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, create two 1/1 red Elemental creature tokens. Elementals you control gain haste until end
	// of turn.
	AddEnterTrigger(this, &CScamperingScorcherCard::BeforeTokens);
}

bool CScamperingScorcherCard::BeforeTokens(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CTokenCreationModifier(GetGame(), ELEMENTAL_S_TOKEN_NAME, ELEMENTAL_S_TOKEN_ID, 2).ApplyTo(pController);

	CCountedCardContainer elementals;
	GetCreaturesOfType(GetGame(), pController, CREATURE_TYPE(Elemental), elementals);
	for (int i = 0; i < elementals.GetSize(); ++i)
		PumpCreature(elementals.GetAt(i), 0, 0, CreatureKeyword::Haste);
	return true;
}

//____________________________________________________________________________
//
CScorchSpitterCard::CScorchSpitterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scorch Spitter"), CardType::Creature, CREATURE_TYPE2(Elemental, Lizard), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// Whenever this creature attacks, it deals 1 damage to the player or planeswalker it's attacking.
	// (CWhenAttackedBlocked as Sarkhan the Masterless; the player in nValue1 and the planeswalker in nValue2)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CScorchSpitterCard::SetAttackContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CScorchSpitterCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CScorchSpitterCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const
{
	if (pCreature != this)
		return false;
	triggerContext.nValue1 = (DWORD)attacked.pPlayer;
	triggerContext.nValue2 = (DWORD)attacked.cpPlaneswalker.GetPointer();
	return attacked.pPlayer || attacked.cpPlaneswalker.GetPointer();
}

bool CScorchSpitterCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	CCard* pPlaneswalker = (CCard*)pAction->GetTriggerContext().nValue2;
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 1);
	else if (pPlaneswalker)
		DealDamageToCreatureOrPlaneswalker(this, pPlaneswalker, 1);
	return true;
}

//____________________________________________________________________________
//
CThunderkinAwakenerCard::CThunderkinAwakenerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thunderkin Awakener"), CardType::Creature, CREATURE_TYPE2(Elemental, Shaman), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(2))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever this creature attacks, choose target Elemental creature card in your graveyard with toughness less than this
	// creature's toughness. Return that card to the battlefield tapped and attacking. Sacrifice it at the beginning of the
	// next end step.
	// Partial: it isn't attacking (a card can't enter the battlefield attacking), and the toughness is checked on
	// resolution.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CThunderkinAwakenerCard::BeforeReturn, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false));
	pTargeting->SetSubjectZoneId(ZoneId::Graveyard);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CThunderkinAwakenerCard::BeforeReturn(CAbilityAction* pAction)
{
	CCreatureCard* pCard = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;
	if (GET_INTEGER(pCard->GetToughness()) >= GET_INTEGER(GetToughness()))
		return false;

	CPlayer* pController = pAction->GetController();
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController);
	pModifier.SetTapped(TRUE);
	pModifier.ApplyTo(pCard);

	if (pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCountedCardContainer subjects;
		subjects.AddCard(pCard, CardPlacement::Top);
		CContainerEffectModifier(GetGame(), _T("End Step Sacrifice Effect"), 61058, &subjects).ApplyTo(pController);
	}
	return false;
}

//____________________________________________________________________________
//
CUnchainedBerserkerCard::CUnchainedBerserkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Unchained Berserker"), CardType::Creature, CREATURE_TYPE2(Human, Berserker), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(1))
{
	// Protection from white
	GetCardKeyword()->AddProtection(CardKeyword::ProtectionFromWhite, FALSE);

	// This creature gets +2/+0 as long as it's attacking.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new AttackingCreatureComparer),
			Power(+2), Life(+0)));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CWildfireElementalCard::CWildfireElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wildfire Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Whenever an opponent is dealt noncombat damage, creatures you control get +1/+0 until end of turn.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWildfireElementalCard::SetDamageContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWildfireElementalCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CWildfireElementalCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	return pToPlayer && pToPlayer != GetController() && (damage.m_DamageType & DamageType::NonCombatDamage).Any();
}

bool CWildfireElementalCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, 0);
	return true;
}

//____________________________________________________________________________
//
// "pPlayer loses nLife life"
static void LoseLife(CCard* pSource, CPlayer* pPlayer, int nLife)
{
	if (pPlayer && nLife > 0)
		CLifeModifier(Life(-nLife), pSource, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
}

//____________________________________________________________________________
//
CAudaciousThiefCard::CAudaciousThiefCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Audacious Thief"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, you draw a card and you lose 1 life.
	AddSelfAttackTrigger(this, &CAudaciousThiefCard::BeforeDraw);
}

bool CAudaciousThiefCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	LoseLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CBlightbeetleCard::CBlightbeetleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blightbeetle"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Protection from green
	GetCardKeyword()->AddProtection(CardKeyword::ProtectionFromGreen, FALSE);

	// Creatures your opponents control can't have +1/+1 counters put on them.
	// Partial: CardKeyword::CantGetCounters, so they can't get any counter (also -1/-1 counters).
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0)));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::CantGetCounters);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->SetAffectOpponentCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CBloodBurglarCard::CBloodBurglarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blood Burglar"), CardType::Creature, CREATURE_TYPE2(Vampire, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_DuringYourTurn(this)
{
	// During your turn, this creature has lifelink. (CDuringYourTurnSupport, as Sorin, Vengeful Bloodlord)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0)));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
	AddAbility(cpAbility.GetPointer());
	m_DuringYourTurn.Add(cpAbility.GetPointer());
	m_DuringYourTurn.AddTurnTriggers();
}

//____________________________________________________________________________
//
CBloodthirstyAerialistCard::CBloodthirstyAerialistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bloodthirsty Aerialist"), CardType::Creature, CREATURE_TYPE2(Vampire, Rogue), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you gain life, put a +1/+1 counter on this creature. (as Ajani's Pridemate)
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodthirstyAerialistCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CBloodthirstyAerialistCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

//____________________________________________________________________________
//
CBonecladNecromancerCard::CBonecladNecromancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Boneclad Necromancer"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you may exile target creature card from a graveyard. If you do, create a 2/2 black Zombie
	// creature token.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CBonecladNecromancerCard::BeforeExile, true, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
	pTargeting->SetSubjectZoneId(ZoneId::Graveyard);
}

bool CBonecladNecromancerCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;

	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Exile)
		CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CCavalierOfNightCard::CCavalierOfNightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cavalier of Night"), CardType::Creature, CREATURE_TYPE2(Elemental, Knight), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(5))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, you may sacrifice another creature. When you do, destroy target creature an opponent
	// controls.
	// Partial: the target is chosen when it triggers, and the creature is sacrificed on resolution.
	{
		CTargeting* pTargeting = AddEnterTargetTrigger(this, &CCavalierOfNightCard::BeforeSacrifice, true, Characteristic::Negative);
		pTargeting->SetIncludeNonControllerCardsOnly();
	}

	// When this creature dies, return target creature card with mana value 3 or less from your graveyard to the
	// battlefield.
	{
		CTargeting* pTargeting = AddDiesTargetTrigger(this, &CCavalierOfNightCard::BeforeReturn, Characteristic::Positive);
		pTargeting->SetSubjectZoneId(ZoneId::Graveyard);
		pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
		pTargeting->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(3));
		pTargeting->SetIncludeControllerCardsOnly();
	}
}

bool CCavalierOfNightCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCountedCardContainer& battlefield = pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer();
	int nBefore = m_OtherCreatureFilter.CountIncluded(battlefield);
	if (nBefore == 0)
		return false;

	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 0, 1, &m_OtherCreatureFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	if (m_OtherCreatureFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) < nBefore)
		DestroyPermanent(pAction->GetAssociatedCard(), pController);
	return false;
}

bool CCavalierOfNightCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCard);
	return false;
}

//____________________________________________________________________________
//
CDreadPresenceCard::CDreadPresenceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dread Presence"), CardType::Creature, CREATURE_TYPE(Nightmare), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Whenever a Swamp you control enters, choose one - You draw a card and you lose 1 life; or this creature deals 2
	// damage to any target and you gain 2 life.
	// (up to one target: with a target, the second mode; without a target, the first one)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Swamp, false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(NewCreatureOrPlaneswalkerComparer());
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetSubjectCount(0, 1);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDreadPresenceCard::BeforeMode));
	AddAbility(cpAbility.GetPointer());
}

bool CDreadPresenceCard::BeforeMode(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (pAction->GetAssociatedPlayer() || pAction->GetAssociatedCard())
	{
		DealDamageToAnyTarget(this, pAction, 2);
		GainLife(this, pController, 2);
	}
	else
	{
		DrawCards(GetGame(), pController, 1);
		LoseLife(this, pController, 1);
	}
	return false;
}

//____________________________________________________________________________
//
CEmbodimentOfAgoniesCard::CEmbodimentOfAgoniesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Embodiment of Agonies"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CEmbodimentOfAgoniesCard::OnZoneChanged))
{
	// Flying, deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// This creature enters with a +1/+1 counter on it for each different mana cost among nonland cards in your graveyard.
	// (as Golgari Raiders; the mana costs are compared as text, and cards without a mana cost don't count)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CEmbodimentOfAgoniesCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		std::vector<CString> costs;
		CZone* pGraveyard = GetController()->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pGraveCard = pGraveyard->GetAt(i);
			if (pGraveCard->GetCardType().IsLand() || pGraveCard->GetSpells().GetSize() == 0)
				continue;
			CString strCost = pGraveCard->GetSpells().GetAt(0)->GetCost().GetManaCost().ToString();
			if (!strCost.IsEmpty() && std::find(costs.begin(), costs.end(), strCost) == costs.end())
				costs.push_back(strCost);
		}
		if (!costs.empty())
			CCardCounterModifier(_T("+1/+1"), (int)costs.size()).ApplyTo(this);
	}
}

//____________________________________________________________________________
//
CGorgingVultureCard::CGorgingVultureCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Gorging Vulture"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, mill four cards. You gain 1 life for each creature card milled this way.
	AddEnterTrigger(this, &CGorgingVultureCard::BeforeMill);
}

bool CGorgingVultureCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	const CCardFilter* pCreatures = CCardFilter::GetFilter(_T("creatures"));
	int nBefore = pCreatures->CountIncluded(pGraveyard->GetCardContainer());
	Mill(pController, 4);
	int nMilled = pCreatures->CountIncluded(pGraveyard->GetCardContainer()) - nBefore;
	if (nMilled > 0)
		GainLife(this, pController, nMilled);
	return true;
}

//____________________________________________________________________________
//
CGruesomeScourgerCard::CGruesomeScourgerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gruesome Scourger"), CardType::Creature, CREATURE_TYPE2(Orc, Warrior), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, it deals damage to target opponent or planeswalker equal to the number of creatures you
	// control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CGruesomeScourgerCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Planeswalker, false));
	pTargeting->SetIncludePlayers(TRUE);
	pTargeting->SetIncludeOpponentPlayersOnly();
}

bool CGruesomeScourgerCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, CountCreatures(GetGame(), pAction->GetController()));
	return false;
}

//____________________________________________________________________________
//
CKnightOfTheEbonLegionCard::CKnightOfTheEbonLegionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of the Ebon Legion"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		BLACK_MANA_TEXT, Power(1), Life(2))
{
	// {2}{B}: This creature gets +3/+3 and gains deathtouch until end of turn.
	AddPumpAbility(this, _T("2") BLACK_MANA_TEXT, _T("+3/+3 and deathtouch until end of turn. Activates"),
		&CKnightOfTheEbonLegionCard::BeforePump);

	// At the beginning of your end step, if a player lost 4 or more life this turn, put a +1/+1 counter on this creature.
	AddStepTrigger(this, NodeId::EndStep, false, &CKnightOfTheEbonLegionCard::SetEndStepContext, &CKnightOfTheEbonLegionCard::BeforeCounter);
}

bool CKnightOfTheEbonLegionCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +3, +3);
	GainCardKeyword(this, CardKeyword::Deathtouch);
	return true;
}

BOOL CKnightOfTheEbonLegionCard::PlayerLostFourLife() const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip)->GetLifeLossTakenThisTurn() >= Life(4))
			return TRUE;
	return FALSE;
}

bool CKnightOfTheEbonLegionCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return PlayerLostFourLife() == TRUE;
}

bool CKnightOfTheEbonLegionCard::BeforeCounter(CAbilityAction* pAction)
{
	if (PlayerLostFourLife())
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CRottingRegisaurCard::CRottingRegisaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rotting Regisaur"), CardType::Creature, CREATURE_TYPE2(Zombie, Dinosaur), nID,
		_T("2") BLACK_MANA_TEXT, Power(7), Life(6))
{
	// At the beginning of your upkeep, discard a card.
	AddStepTrigger<CRottingRegisaurCard>(this, NodeId::UpkeepStep, false, NULL, &CRottingRegisaurCard::BeforeDiscard);
}

bool CRottingRegisaurCard::BeforeDiscard(CAbilityAction* pAction)
{
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CSavageGorgerCard::CSavageGorgerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Savage Gorger"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(1))
{
	// At the beginning of your end step, if an opponent lost life this turn, put a +1/+1 counter on this creature.
	AddStepTrigger(this, NodeId::EndStep, false, &CSavageGorgerCard::SetEndStepContext, &CSavageGorgerCard::BeforeCounter);
}

bool CSavageGorgerCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return OpponentLostLifeThisTurn(GetController()) == TRUE;
}

bool CSavageGorgerCard::BeforeCounter(CAbilityAction* pAction)
{
	if (OpponentLostLifeThisTurn(pAction->GetController()))
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CSorcererOfTheFangCard::CSorcererOfTheFangCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sorcerer of the Fang"), CardType::Creature, CREATURE_TYPE3(Human, Wizard, Sorcerer), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(3))
{
	// {5}{B}, {T}: This creature deals 2 damage to target opponent or planeswalker.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("5") BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Planeswalker, false), TRUE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorcererOfTheFangCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CSorcererOfTheFangCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 2);
	return false;
}

//____________________________________________________________________________
//
CSorinsGuideCard::CSorinsGuideCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sorin's Guide"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(2))
{
	// When this creature enters, you may search your library and/or graveyard for a card named Sorin, Vampire Lord, reveal
	// it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CSorinsGuideCard::BeforeSearch, true);
}

bool CSorinsGuideCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Sorin, Vampire Lord"));
	return true;
}

//____________________________________________________________________________
//
CThirstingBloodlordCard::CThirstingBloodlordCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thirsting Bloodlord"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Other Vampires you control get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false), new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CUndeadServantCard::CUndeadServantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Undead Servant"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, create a 2/2 black Zombie creature token for each card named Undead Servant in your
	// graveyard.
	AddEnterTrigger(this, &CUndeadServantCard::BeforeTokens);
}

bool CUndeadServantCard::BeforeTokens(CAbilityAction* pAction)
{
	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nCount = 0;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetPrintedCardName() == _T("Undead Servant"))
			++nCount;
	if (nCount > 0)
		CTokenCreationModifier(GetGame(), ZOMBIE_P_TOKEN_NAME, ZOMBIE_P_TOKEN_ID, nCount).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CVampireOfTheDireMoonCard::CVampireOfTheDireMoonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vampire of the Dire Moon"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

//____________________________________________________________________________
//
CVengefulWarchiefCard::CVengefulWarchiefCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vengeful Warchief"), CardType::Creature, CREATURE_TYPE2(Orc, Warrior), nID,
		_T("4") BLACK_MANA_TEXT, Power(4), Life(4))
	, m_nTurn(-1)
{
	// Whenever you lose life for the first time each turn, put a +1/+1 counter on this creature.
	// (as Ajani's Pridemate, with the turn remembered in the context function)
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVengefulWarchiefCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CVengefulWarchiefCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	if (!(nToLife < nFromLife) || m_nTurn == GetGame()->GetGameTurnNumber())
		return false;
	m_nTurn = GetGame()->GetGameTurnNumber();
	return true;
}

//____________________________________________________________________________
//
CVilisBrokerOfBloodCard::CVilisBrokerOfBloodCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vilis, Broker of Blood"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Demon), nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(8), Life(8))
{
	{
		// {B}, Pay 2 life: Target creature gets -1/-1 until end of turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				BLACK_MANA_TEXT,
				Power(-1), Life(-1),
				CreatureKeyword::Null, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->AddPayLifeDeltaCost(Life(-2));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you lose life, draw that many cards. (the life lost in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVilisBrokerOfBloodCard::SetLifeContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CVilisBrokerOfBloodCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVilisBrokerOfBloodCard::SetLifeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	if (!(nToLife < nFromLife))
		return false;
	triggerContext.nValue1 = GET_INTEGER(nFromLife - nToLife);
	return true;
}

bool CVilisBrokerOfBloodCard::BeforeDraw(TriggeredAbility::TriggeredActionType* pAction)
{
	int nCount = (int)pAction->GetTriggerContext().nValue1;
	if (nCount > 0)
		DrawCards(GetGame(), pAction->GetController(), nCount);
	return true;
}

//____________________________________________________________________________
//
CYaroksFenlurkerCard::CYaroksFenlurkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yarok's Fenlurker"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, each opponent exiles a card from their hand.
	AddEnterTrigger(this, &CYaroksFenlurkerCard::BeforeExile);

	// {2}{B}: This creature gets +1/+1 until end of turn.
	AddPumpAbility(this, _T("2") BLACK_MANA_TEXT, _T("+1/+1 until end of turn. Activates"), &CYaroksFenlurkerCard::BeforePump);
}

bool CYaroksFenlurkerCard::BeforeExile(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer != pAction->GetController())
			ChooseAndMove(GetGame(), pPlayer, ZoneId::Hand, 1, 1, CCardFilter::GetFilter(_T("cards")), ZoneId::Exile, MoveType::Others);
	}
	return true;
}

bool CYaroksFenlurkerCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

//____________________________________________________________________________
//
CAgentOfTreacheryCard::CAgentOfTreacheryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Agent of Treachery"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, gain control of target permanent.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CAgentOfTreacheryCard::BeforeControl, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new TrueCardComparer);

	// At the beginning of your end step, if you control three or more permanents you don't own, draw three cards.
	AddStepTrigger(this, NodeId::EndStep, false, &CAgentOfTreacheryCard::SetEndStepContext, &CAgentOfTreacheryCard::BeforeDraw);
}

bool CAgentOfTreacheryCard::BeforeControl(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CGainControlModifier(GetGame(), this).ApplyTo(pCard);
	return false;
}

int CAgentOfTreacheryCard::CountNotOwned(CPlayer* pPlayer) const
{
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	int nCount = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetOwner() != pPlayer)
			++nCount;
	return nCount;
}

bool CAgentOfTreacheryCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return CountNotOwned(GetController()) >= 3;
}

bool CAgentOfTreacheryCard::BeforeDraw(CAbilityAction* pAction)
{
	if (CountNotOwned(pAction->GetController()) >= 3)
		DrawCards(GetGame(), pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CAtemsisAllSeeingCard::CAtemsisAllSeeingCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Atemsis, All-Seeing"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Sphinx), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(5))
{
	{
		// {2}{U}, {T}: Draw two cards, then discard a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLUE_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Draw two cards, then discard a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAtemsisAllSeeingCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever Atemsis deals damage to an opponent, you may reveal your hand. If cards with at least six different mana
		// values are revealed this way, that player loses the game. (the player in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAtemsisAllSeeingCard::SetDamageContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CAtemsisAllSeeingCard::BeforeReveal));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAtemsisAllSeeingCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CAtemsisAllSeeingCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	if (!pPlayer || pPlayer == GetController())
		return false;
	triggerContext.nValue1 = (DWORD)pPlayer;
	return true;
}

bool CAtemsisAllSeeingCard::BeforeReveal(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (!pPlayer)
		return true;

	std::vector<int> values;
	CZone* pHand = pAction->GetController()->GetZoneById(ZoneId::Hand);
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		int nValue = (int)pHand->GetAt(i)->GetConvertedManaCost();
		if (std::find(values.begin(), values.end(), nValue) == values.end())
			values.push_back(nValue);
	}
	if (values.size() >= 6)
		pPlayer->SetLostByOtherReasons();
	return true;
}

//____________________________________________________________________________
//
CBorealElementalCard::CBorealElementalCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Boreal Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(4))
{
	// Spells your opponents cast that target this creature cost {2} more to cast.
	// Not implemented: there is no cost increase that depends on the targets.
}

//____________________________________________________________________________
//
CBrinebornCutthroatCard::CBrinebornCutthroatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brineborn Cutthroat"), CardType::Creature, CREATURE_TYPE2(Merfolk, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Whenever you cast a spell during an opponent's turn, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBrinebornCutthroatCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBrinebornCutthroatCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CBrinebornCutthroatCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return GetGame()->GetActivePlayer() != GetController();
}

bool CBrinebornCutthroatCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CCavalierOfGalesCard::CCavalierOfGalesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cavalier of Gales"), CardType::Creature, CREATURE_TYPE2(Elemental, Knight), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(5))
{
	// When this creature enters, draw three cards, then put two cards from your hand on top of your library in any order.
	AddEnterTrigger(this, &CCavalierOfGalesCard::BeforeDraw);

	// When this creature dies, shuffle it into its owner's library, then scry 2.
	AddDiesTrigger(this, &CCavalierOfGalesCard::BeforeShuffle);
}

bool CCavalierOfGalesCard::BeforeDraw(CAbilityAction* pAction)
{
	// (as Riverwise Augur in Rivals of Ixalan)
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
	pModifier.AddSelection(MinimumValue(nCount), MaximumValue(nCount),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::PrimaryPlayer,
		CCardFilter::GetFilter(_T("cards")),
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);
	return true;
}

bool CCavalierOfGalesCard::BeforeShuffle(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, GetOwner()).ApplyTo(this);
		GetOwner()->GetZoneById(ZoneId::Library)->Shuffle();
	}
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CCelestialMessengerCard::CCelestialMessengerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Celestial Messenger"), CardType::Creature, CREATURE_TYPE2(Bird, Spirit), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// Flash, flying
	GetCardKeyword()->AddFlash(FALSE);

	// This creature gets +1/+1 as long as you control a Yanling planeswalker.
	AddPlaneswalkerTypeBonus(this, PlaneswalkerType::Yanling, +1, +1, CreatureKeyword::Null);
}

//____________________________________________________________________________
//
CCeruleanDrakeCard::CCeruleanDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cerulean Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(1))
	, m_NothingFilter(_T("nothing"), _T("nothing"), FALSE_CARD_COMPARER)
{
	// Flying, protection from red
	GetCardKeyword()->AddProtection(CardKeyword::ProtectionFromRed, FALSE);

	// Sacrifice this creature: Counter target spell that targets you. (as Dawn Charm in Planar Chaos)
	counted_ptr<CActivatedAbility<CCounterSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CCounterSpell>>(this,
			_T(""),
			new TrueCardComparer));

	cpAbility->GetCounterspellCardFilter().AddComparer(new StackTargetingComparer(&m_NothingFilter, this, TRUE));
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CCloudkinSeerCard::CCloudkinSeerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cloudkin Seer"), CardType::Creature, CREATURE_TYPE2(Elemental, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CCloudkinSeerCard::BeforeDraw);
}

bool CCloudkinSeerCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CDungeonGeistsCard::CDungeonGeistsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dungeon Geists"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, tap target creature an opponent controls. That creature doesn't untap during its
	// controller's untap step for as long as you control this creature.
	// (the creature is remembered and the keyword removed when this creature leaves, as Time of Ice in Dominaria)
	// Note: it isn't removed if you lose control of this creature without it leaving the battlefield.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CDungeonGeistsCard::BeforeTap, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();

	AddLeaveTrigger(this, &CDungeonGeistsCard::BeforeLeave);
}

bool CDungeonGeistsCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardOrientationModifier(TRUE).ApplyTo(pCard);
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE).ApplyTo(pCard);
		m_Tapped.AddCard(pCard, CardPlacement::Top);
	}
	return false;
}

bool CDungeonGeistsCard::BeforeLeave(CAbilityAction* pAction)
{
	while (m_Tapped.GetSize() > 0)
	{
		CCard* pCard = m_Tapped.GetAt(0);
		m_Tapped.RemoveCard(pCard);
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE).RemoveFrom(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
CFaerieMiscreantCard::CFaerieMiscreantCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Faerie Miscreant"), CardType::Creature, CREATURE_TYPE2(Faerie, Rogue), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, if you control another creature named Faerie Miscreant, draw a card.
	AddEnterIfTrigger(this, &CFaerieMiscreantCard::SetEnterContext, &CFaerieMiscreantCard::BeforeDraw);
}

bool CFaerieMiscreantCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this && creatures.GetAt(i)->GetCardName(FALSE) == _T("Faerie Miscreant"))
			return true;
	return false;
}

bool CFaerieMiscreantCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CFrostLynxCard::CFrostLynxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frost Lynx"), CardType::Creature, CREATURE_TYPE2(Elemental, Cat), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, tap target creature an opponent controls. That creature doesn't untap during its
	// controller's next untap step. (as Watertrap Weaver)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CFrostLynxCard::BeforeTap, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CFrostLynxCard::BeforeTap(CAbilityAction* pAction)
{
	TapAndSkipUntap(pAction->GetAssociatedCard());
	return false;
}

//____________________________________________________________________________
//
CMoatPiranhasCard::CMoatPiranhasCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Moat Piranhas"), CardType::Creature, CREATURE_TYPE(Fish), nID,
		_T("1") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);
}

//____________________________________________________________________________
//
COctoprophetCard::COctoprophetCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Octoprophet"), CardType::Creature, CREATURE_TYPE(Octopus), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, scry 2.
	AddEnterTrigger(this, &COctoprophetCard::BeforeScry);
}

bool COctoprophetCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CRenownedWeaponsmithCard::CRenownedWeaponsmithCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Renowned Weaponsmith"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
	, m_NameFilter(_T("a card named Heart-Piercer Bow or Vial of Dragonfire"), _T("cards named Heart-Piercer Bow or Vial of Dragonfire"),
		new OrCardComparer(new CardNameComparer(_T("Heart-Piercer Bow")), new CardNameComparer(_T("Vial of Dragonfire"))))
{
	// {T}: Add {C}{C}. Spend this mana only to cast artifact spells or activate abilities of artifacts.
	// Partial: the mana isn't restricted (the engine has no restricted mana).
	AddTapManaAbility(this, _T("2"));

	// {U}, {T}: Search your library for a card named Heart-Piercer Bow or Vial of Dragonfire, reveal it, put it into your
	// hand, then shuffle.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			BLUE_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Search your library for Heart-Piercer Bow or Vial of Dragonfire. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRenownedWeaponsmithCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CRenownedWeaponsmithCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, &m_NameFilter);
	return true;
}

//____________________________________________________________________________
//
CScholarOfTheAgesCard::CScholarOfTheAgesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scholar of the Ages"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, return up to two target instant and/or sorcery cards from your graveyard to your hand.
	// Partial: the cards are chosen on resolution (they aren't targets).
	AddEnterTrigger(this, &CScholarOfTheAgesCard::BeforeReturn);
}

bool CScholarOfTheAgesCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 0, 2,
		CCardFilter::GetFilter(_T("instant cards or sorcery cards")), ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CSpectralSailorCard::CSpectralSailorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spectral Sailor"), CardType::Creature, CREATURE_TYPE2(Spirit, Pirate), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
{
	// Flash, flying
	GetCardKeyword()->AddFlash(FALSE);

	// {3}{U}: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3") BLUE_MANA_TEXT, 1));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CWardenOfEvosIsleCard::CWardenOfEvosIsleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Warden of Evos Isle"), CardType::Creature, CREATURE_TYPE2(Bird, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Creature spells with flying you cast cost {1} less to cast.
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false)),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CWaterkinShamanCard::CWaterkinShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Waterkin Shaman"), CardType::Creature, CREATURE_TYPE2(Elemental, Shaman), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// Whenever a creature you control with flying enters, this creature gets +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWaterkinShamanCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CWaterkinShamanCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

//____________________________________________________________________________
//
CYanlingsHarbingerCard::CYanlingsHarbingerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Yanling's Harbinger"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, you may search your library and/or graveyard for a card named Mu Yanling, Celestial Wind,
	// reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CYanlingsHarbingerCard::BeforeSearch, true);
}

bool CYanlingsHarbingerCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Mu Yanling, Celestial Wind"));
	return true;
}

//____________________________________________________________________________
//
CYaroksWavecrasherCard::CYaroksWavecrasherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yarok's Wavecrasher"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("3") BLUE_MANA_TEXT, Power(4), Life(4))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// When this creature enters, return another creature you control to its owner's hand.
	AddEnterTrigger(this, &CYaroksWavecrasherCard::BeforeReturn);
}

bool CYaroksWavecrasherCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Battlefield, 1, 1, &m_OtherCreatureFilter,
		ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
// A card with one of the names in the list (Pattern Matcher)
struct NameListComparer : public CardComparer
{
	NameListComparer(const std::vector<CString>& names) : m_Names(names) {}

	virtual bool operator()(const CCard* value) const
	{
		CString strName = const_cast<CCard*>(value)->GetCardName(FALSE);
		return std::find(m_Names.begin(), m_Names.end(), strName) != m_Names.end();
	}

	virtual NameListComparer* Clone() const
	{
		return new NameListComparer(m_Names);
	}

	std::vector<CString> m_Names;
};

// A permanent card put into a graveyard from the battlefield this turn (recorded by Salvager of Ruin, as Brought Back)
struct SalvagerMovedComparer : public CardComparer
{
	SalvagerMovedComparer(const CSalvagerOfRuinCard* pSource) : m_pSource(pSource) {}

	virtual bool operator()(const CCard* value) const
	{
		return m_pSource->WasPutThisTurn(value) == TRUE;
	}

	virtual SalvagerMovedComparer* Clone() const
	{
		return new SalvagerMovedComparer(m_pSource);
	}

	const CSalvagerOfRuinCard* m_pSource;
};

//____________________________________________________________________________
//
CCorpseKnightCard::CCorpseKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Corpse Knight"), CardType::Creature, CREATURE_TYPE2(Zombie, Knight), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Whenever another creature you control enters, each opponent loses 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCorpseKnightCard::SetEnterContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCorpseKnightCard::BeforeLoseLife));
	AddAbility(cpAbility.GetPointer());
}

bool CCorpseKnightCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard != this;
}

bool CCorpseKnightCard::BeforeLoseLife(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			LoseLife(this, GetGame()->GetPlayer(ip), 1);
	return true;
}

//____________________________________________________________________________
//
CCreepingTrailblazerCard::CCreepingTrailblazerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Creeping Trailblazer"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		RED_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// Other Elementals you control get +1/+0.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false), new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+1), Life(+0)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// {2}{R}{G}: This creature gets +1/+1 until end of turn for each Elemental you control.
	AddPumpAbility(this, _T("2") RED_MANA_TEXT GREEN_MANA_TEXT, _T("+1/+1 until end of turn for each Elemental you control. Activates"),
		&CCreepingTrailblazerCard::BeforePump);
}

bool CCreepingTrailblazerCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer elementals;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Elemental), elementals);
	int nCount = elementals.GetSize();
	if (nCount > 0)
		PumpCreature(this, nCount, nCount);
	return true;
}

//____________________________________________________________________________
//
CEmpyreanEagleCard::CEmpyreanEagleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Empyrean Eagle"), CardType::Creature, CREATURE_TYPE2(Bird, Spirit), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// Other creatures you control with flying get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false), new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CIronrootWarlordCard::CIronrootWarlordCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ironroot Warlord"), CardType::Creature, CREATURE_TYPE2(Treefolk, Soldier), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(0), Life(5))
{
	{
		// Ironroot Warlord's power is equal to the number of creatures you control. (as Nim Grotesque)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new AnyCreatureComparer));

		cpAbility->SetChangePowerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{G}{W}: Create a 1/1 white Soldier creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT,
				SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID, 1));
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CKaaliaZenithSeekerCard::CKaaliaZenithSeekerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kaalia, Zenith Seeker"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Cleric), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
	, m_TypeFilter(_T("an Angel, Demon or Dragon card"), _T("Angel, Demon or Dragon cards"),
		new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Angel), false),
			new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Demon), false), new CreatureTypeComparer(CREATURE_TYPE(Dragon), false))))
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When Kaalia enters, look at the top six cards of your library. You may reveal an Angel card, a Demon card, and/or a
	// Dragon card from among them and put them into your hand. Put the rest on the bottom of your library in a random order.
	// Partial: up to three Angel, Demon or Dragon cards (not necessarily one of each type).
	AddEnterTrigger(this, &CKaaliaZenithSeekerCard::BeforeLook);
}

bool CKaaliaZenithSeekerCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 6, 0, 3, &m_TypeFilter);
	return true;
}

//____________________________________________________________________________
//
CKethisTheHiddenHandCard::CKethisTheHiddenHandCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kethis, the Hidden Hand"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Advisor), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
{
	// Legendary spells you cast cost {1} less to cast.
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CardTypeComparer(CardType::Legendary, false),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// Exile two legendary cards from your graveyard: Until end of turn, each legendary card in your graveyard gains "You may
	// play this card from your graveyard."
	// Not implemented: the engine can't let other cards be played from the graveyard.
}

//____________________________________________________________________________
//
CKykarWindsFuryCard::CKykarWindsFuryCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kykar, Wind's Fury"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Bird, Wizard), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_SpiritFilter(_T("a Spirit"), _T("Spirits"), new CreatureTypeComparer(CREATURE_TYPE(Spirit), false))
{
	{
		// Whenever you cast a noncreature spell, create a 1/1 white Spirit creature token with flying.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKykarWindsFuryCard::BeforeSpirit));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Sacrifice a Spirit: Add {R}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SpiritFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKykarWindsFuryCard::BeforeSpirit(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), SPIRIT_S_TOKEN_NAME, SPIRIT_S_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CLightningStormkinCard::CLightningStormkinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Lightning Stormkin"), CardType::Creature, CREATURE_TYPE2(Elemental, Wizard), nID,
		BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Flying, haste
	GetCreatureKeyword()->AddHaste(FALSE);
}

//____________________________________________________________________________
//
COgreSiegebreakerCard::COgreSiegebreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ogre Siegebreaker"), CardType::Creature, CREATURE_TYPE2(Ogre, Berserker), nID,
		_T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
{
	// {2}{B}{R}: Destroy target creature that was dealt damage this turn.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2") BLACK_MANA_TEXT RED_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer, new DamagedThisTurnComparer),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
COmnathLocusOfTheRoilCard::COmnathLocusOfTheRoilCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Omnath, Locus of the Roil"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Elemental), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	{
		// When Omnath enters, it deals damage to any target equal to the number of Elementals you control.
		CTargeting* pTargeting = AddEnterTargetTrigger(this, &COmnathLocusOfTheRoilCard::BeforeDamage, false, Characteristic::Negative);
		pTargeting->GetSubjectCardFilter().RemoveAllComparers();
		pTargeting->GetSubjectCardFilter().AddComparer(NewCreatureOrPlaneswalkerComparer());
		pTargeting->SetIncludePlayers(TRUE);
	}
	{
		// Landfall - Whenever a land you control enters, put a +1/+1 counter on target Elemental you control. If you control
		// eight or more lands, draw a card. (landfall as Tatyova, Benthic Druid, with a target)
		// Note: without an Elemental to target, the trigger doesn't draw either.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false));
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COmnathLocusOfTheRoilCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
}

bool COmnathLocusOfTheRoilCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer elementals;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Elemental), elementals);
	DealDamageToAnyTarget(this, pAction, elementals.GetSize());
	return false;
}

bool COmnathLocusOfTheRoilCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(pAction->GetAssociatedCard(), 1);

	CPlayer* pController = pAction->GetController();
	if (CCardFilter::GetFilter(_T("lands"))->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= 8)
		DrawCards(GetGame(), pController, 1);
	return false;
}

//____________________________________________________________________________
//
CRienneAngelOfRebirthCard::CRienneAngelOfRebirthCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rienne, Angel of Rebirth"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Angel), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(4))
{
	{
		// Other multicolored creatures you control get +1/+0.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new AndCardComparer(new AnyCreatureComparer, new CardMulticoloredComparer),
					new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+1), Life(+0)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever another multicolored creature you control dies, return it to its owner's hand at the beginning of the next
		// end step. (as Tiana, Ship's Caretaker in Dominaria)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new AndCardComparer(new AnyCreatureComparer, new CardMulticoloredComparer));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRienneAngelOfRebirthCard::SetDiesContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CRienneAngelOfRebirthCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRienneAngelOfRebirthCard::SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard == this)
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CRienneAngelOfRebirthCard::BeforeReturn(TriggeredAbility::TriggeredActionType* pAction)
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

//____________________________________________________________________________
//
CRisenReefCard::CRisenReefCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Risen Reef"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(1))
	, m_PlaceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRisenReefCard::OnPlaceSelected))
{
	// Whenever this creature or another Elemental you control enters, look at the top card of your library. If it's a land
	// card, you may put it onto the battlefield tapped. If you don't put the card onto the battlefield, put it into your
	// hand.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRisenReefCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

bool CRisenReefCard::BeforeLook(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pTop = pLibrary->GetAt(pLibrary->GetSize() - 1);
	if (!pTop->GetCardType().IsLand())
	{
		CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pController).ApplyTo(pTop);
		return true;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.cpAssociatedCard = pTop;
		entry.strText.Format(_T("Put %s onto the battlefield tapped"), pTop->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.cpAssociatedCard = pTop;
		entry.strText.Format(_T("Put %s into your hand"), pTop->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_PlaceSelection.AddSelectionRequest(entries, 1, 1, NULL, pController, (DWORD)pTop);
	return true;
}

void CRisenReefCard::OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Library)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 1)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Battlefield, TRUE, MoveType::Others, pSelectionPlayer);
				pModifier.SetTapped(TRUE);
				pModifier.ApplyTo(pCard);
			}
			else
				CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
			break;
		}
}

//____________________________________________________________________________
//
CSkyknightVanguardCard::CSkyknightVanguardCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skyknight Vanguard"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(1), Life(2))
{
	// Whenever this creature attacks, create a 1/1 white Soldier creature token that's tapped and attacking.
	// Partial: the token is tapped but not attacking (a token can't enter the battlefield attacking).
	AddSelfAttackTrigger(this, &CSkyknightVanguardCard::BeforeToken);
}

bool CSkyknightVanguardCard::BeforeToken(CAbilityAction* pAction)
{
	CCountedCardContainer tokens;
	CTokenCreationModifier(GetGame(), SOLDIER_O_TOKEN_NAME, SOLDIER_O_TOKEN_ID, 1, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pAction->GetController());
	for (int i = 0; i < tokens.GetSize(); ++i)
		if (tokens.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			CCardOrientationModifier(TRUE).ApplyTo(tokens.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
CTomeboundLichCard::CTomeboundLichCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tomebound Lich"), CardType::Creature, CREATURE_TYPE2(Zombie, Wizard), nID,
		_T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(3))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// Whenever this creature enters or deals combat damage to a player, draw a card, then discard a card.
	AddEnterTrigger(this, &CTomeboundLichCard::BeforeLoot);
	{
		// (as Daring Saboteur)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTomeboundLichCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTomeboundLichCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CYarokTheDesecratedCard::CYarokTheDesecratedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yarok, the Desecrated"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elemental, Horror), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(5))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// If a permanent entering causes a triggered ability of a permanent you control to trigger, that ability triggers an
	// additional time.
	// Not implemented: the engine can't make an ability trigger an additional time.
}

//____________________________________________________________________________
//
CDiamondKnightCard::CDiamondKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Diamond Knight"), CardType::_ArtifactCreature, CREATURE_TYPE(Knight), nID,
		_T("3"), Power(1), Life(1))
	, m_ColorSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDiamondKnightCard::OnColorSelected))
	, m_dwChosenColor(0)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// As this creature enters, choose a color. (chosen by a trigger when it enters, as Diamond Mare in M19)
	AddEnterTrigger(this, &CDiamondKnightCard::BeforeChoose);

	// Whenever you cast a spell of the chosen color, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDiamondKnightCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDiamondKnightCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CDiamondKnightCard::BeforeChoose(CAbilityAction* pAction)
{
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

void CDiamondKnightCard::OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			m_dwChosenColor = it->dwContext + 1;
}

bool CDiamondKnightCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	static const CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	if (!pCard || m_dwChosenColor == 0 || m_dwChosenColor > 5)
		return false;

	return (pCard->GetCardType() & colors[m_dwChosenColor - 1]).Any();
}

bool CDiamondKnightCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CGolosTirelessPilgrimCard::CGolosTirelessPilgrimCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Golos, Tireless Pilgrim"), CardType::_ArtifactCreature | CardType::Legendary, CREATURE_TYPE(Scout), nID,
		_T("5"), Power(3), Life(5))
{
	// When Golos enters, you may search your library for a land card, put that card onto the battlefield tapped, then
	// shuffle.
	AddEnterTrigger(this, &CGolosTirelessPilgrimCard::BeforeSearch, true);

	// {2}{W}{U}{B}{R}{G}: Exile the top three cards of your library. You may play them this turn without paying their mana
	// costs.
	// Not implemented: the engine can't play cards from exile without paying their costs.
}

bool CGolosTirelessPilgrimCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("lands")), TRUE);
	return true;
}

//____________________________________________________________________________
//
CPatternMatcherCard::CPatternMatcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pattern Matcher"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("4"), Power(3), Life(3))
{
	// When this creature enters, you may search your library for a card with the same name as another creature you
	// control, reveal it, put it into your hand, then shuffle.
	AddEnterTrigger(this, &CPatternMatcherCard::BeforeSearch, true);
}

bool CPatternMatcherCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	std::vector<CString> names;
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			names.push_back(creatures.GetAt(i)->GetCardName(FALSE));
	if (names.empty())
		return true;

	CCardFilter filter(_T("a card with the same name as another creature you control"),
		_T("cards with the same name as another creature you control"), new NameListComparer(names));
	SearchToHand(GetGame(), pController, 1, &filter);
	return true;
}

//____________________________________________________________________________
//
CSalvagerOfRuinCard::CSalvagerOfRuinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Salvager of Ruin"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(2), Life(1))
	, m_nTurn(-1)
{
	// (records the permanents put into a graveyard from the battlefield this turn, from any zone and without triggering,
	// as Brought Back)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard, FALSE, TRUE, FALSE));

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSalvagerOfRuinCard::SetMovedContext));
		AddAbility(cpAbility.GetPointer());
	}

	// Sacrifice this creature: Choose target permanent card in your graveyard that was put there from the battlefield this
	// turn. Return it to your hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new SalvagerMovedComparer(this),
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

BOOL CSalvagerOfRuinCard::WasPutThisTurn(const CCard* pCard) const
{
	if (m_nTurn != GetGame()->GetGameTurnNumber())
		return FALSE;
	return std::find(m_Moved.begin(), m_Moved.end(), pCard) != m_Moved.end();
}

bool CSalvagerOfRuinCard::SetMovedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (GetGame()->GetGameTurnNumber() != m_nTurn)
	{
		m_nTurn = GetGame()->GetGameTurnNumber();
		m_Moved.clear();
	}
	if (pCard && !pCard->GetCardType().IsToken())
		m_Moved.push_back(pCard);
	return false;
}

//____________________________________________________________________________
//
