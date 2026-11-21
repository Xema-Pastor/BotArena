#include "stdafx.h"
#include "CardThroneOfEldraine.h"

#define new DEBUG_NEW

#define DEFINE_CARD(C)	\
	if (!_tcslen(strCardName))	\
	{ cardClassNames.push_back(_T(#C)); }	\
	else	\
	if (!_tcsicmp(strCardName, _T(#C))) { cpCard = counted_ptr<CCard>(new C(pGame, uID)); break; }

//____________________________________________________________________________
//
// Helpers (from Ixalan, see no_vale/PATRONES_MOTOR.md)

// Helpers of War of the Spark (war_helpers.cpp) plus the generic helpers of Magic/M20/CardM20.cpp

#define ELEMENTAL_BIRD_A_TOKEN_NAME		_T("Elemental Bird (A)")
#define ELEMENTAL_BIRD_A_TOKEN_ID		55137
#define AJANIS_PRIDEMATE_TOKEN_NAME		_T("Ajani's Pridemate")
#define AJANIS_PRIDEMATE_TOKEN_ID		55138
#define CHANDRA_AWAKENED_EMBLEM_NAME	_T("Chandra, Awakened Inferno Emblem")
#define CHANDRA_AWAKENED_EMBLEM_ID		61162
#define ELEMENTAL_S_TOKEN_NAME			_T("Elemental (S)")
#define ELEMENTAL_S_TOKEN_ID			62052
#define DEMON_E_TOKEN_NAME		_T("Demon (E)")
#define DEMON_E_TOKEN_ID		55048
#define GOLEM_F_TOKEN_NAME		_T("Golem (F)")
#define GOLEM_F_TOKEN_ID		55139
#define SPIRIT_S_TOKEN_NAME		_T("Spirit (S)")
#define SPIRIT_S_TOKEN_ID		55076
#define ELEMENTAL_AZ_TOKEN_NAME		_T("Elemental (AZ)")
#define ELEMENTAL_AZ_TOKEN_ID		64140
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

// Helpers of Magic/M20/CardM20.cpp
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
// "pPlayer loses nLife life"
static void LoseLife(CCard* pSource, CPlayer* pPlayer, int nLife)
{
	if (pPlayer && nLife > 0)
		CLifeModifier(Life(-nLife), pSource, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(pPlayer);
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

// Adamant (Throne of Eldraine): "if at least three <color> mana was spent to cast this spell". The engine keeps the mana
// spent by color (as Sunburst in Fifth Dawn): for a resolving instant or sorcery, the mana of its cost; for a permanent,
// the mana of its last cast (check it with MoveType::Cast, as the kicker of Gatekeeper of Malakir).
// Note: the engine chooses the mana that pays the generic part of the cost.
static BOOL IsAdamantSpell(CAbilityAction* pAction, CManaPool::Color color)
{
	return pAction->GetCostConfigEntry().GetManaPool().GetMana(color) >= 3;
}

static BOOL IsAdamantPermanent(const CCard* pCard, CManaPool::Color color)
{
	return pCard->GetLastCastingManaCost().GetMana(color) >= 3;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
counted_ptr<CCard> CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID)
{
	counted_ptr<CCard> cpCard;
	do
	{
		DEFINE_CARD(CCastleArdenvaleCard);
		DEFINE_CARD(CCastleEmberethCard);
		DEFINE_CARD(CCastleGarenbrigCard);
		DEFINE_CARD(CCastleLocthwainCard);
		DEFINE_CARD(CCastleVantressCard);
		DEFINE_CARD(CDwarvenMineCard);
		DEFINE_CARD(CFabledPassageCard);
		DEFINE_CARD(CGingerbreadCabinCard);
		DEFINE_CARD(CIdyllicGrangeCard);
		DEFINE_CARD(CMysticSanctuaryCard);
		DEFINE_CARD(CTournamentGroundsCard);
		DEFINE_CARD(CWitchsCottageCard);
		DEFINE_CARD(CGarrukCursedHuntsmanCard);
		DEFINE_CARD(COkoTheTricksterCard);
		DEFINE_CARD(COkoThiefOfCrownsCard);
		DEFINE_CARD(CRowanFearlessSparkmageCard);
		DEFINE_CARD(CTheRoyalScionsCard);
		DEFINE_CARD(CAllThatGlittersCard);
		DEFINE_CARD(CCharmedSleepCard);
		DEFINE_CARD(CDeafeningSilenceCard);
		DEFINE_CARD(CDoomForetoldCard);
		DEFINE_CARD(CFerocityOfTheWildsCard);
		DEFINE_CARD(CFortifyingProvisionsCard);
		DEFINE_CARD(CFrogifyCard);
		DEFINE_CARD(CHappilyEverAfterCard);
		DEFINE_CARD(CImprobableAllianceCard);
		DEFINE_CARD(CKenrithsTransformationCard);
		DEFINE_CARD(CKnightsChargeCard);
		DEFINE_CARD(COutlawsMerrimentCard);
		DEFINE_CARD(CRevengeOfRavensCard);
		DEFINE_CARD(CSoTinyCard);
		DEFINE_CARD(CTallAsABeanstalkCard);
		DEFINE_CARD(CTrailOfCrumbsCard);
		DEFINE_CARD(CTrappedInTheTowerCard);
		DEFINE_CARD(CCrystalSlipperCard);
		DEFINE_CARD(CEmbercleaveCard);
		DEFINE_CARD(CEnchantedCarriageCard);
		DEFINE_CARD(CFolioOfFanciesCard);
		DEFINE_CARD(CGiantsSkewerCard);
		DEFINE_CARD(CGlassCasketCard);
		DEFINE_CARD(CGoldenEggCard);
		DEFINE_CARD(CHeraldicBannerCard);
		DEFINE_CARD(CMaceOfTheValiantCard);
		DEFINE_CARD(CMantleOfTidesCard);
		DEFINE_CARD(CMidnightClockCard);
		DEFINE_CARD(CRosethornHalberdCard);
		DEFINE_CARD(CScaldingCauldronCard);
		DEFINE_CARD(CShiningArmorCard);
		DEFINE_CARD(CSorcerousSpyglassCard);
		DEFINE_CARD(CSpinningWheelCard);
		DEFINE_CARD(CSteelclawLanceCard);
		DEFINE_CARD(CTheCauldronOfEternityCard);
		DEFINE_CARD(CTheCircleOfLoyaltyCard);
		DEFINE_CARD(CTheGreatHengeCard);
		DEFINE_CARD(CTheMagicMirrorCard);
		DEFINE_CARD(CTomeOfLegendsCard);
		DEFINE_CARD(CWeaponRackCard);
		DEFINE_CARD(CWishclawTalismanCard);
		DEFINE_CARD(CWitchingWellCard);
		DEFINE_CARD(CWitchsOvenCard);
		DEFINE_CARD(CBlowYourHouseDownCard);
		DEFINE_CARD(CCauldronsGiftCard);
		DEFINE_CARD(CClaimTheFirstbornCard);
		DEFINE_CARD(CDanceOfTheManseCard);
		DEFINE_CARD(CEpicDownfallCard);
		DEFINE_CARD(CForebodingFruitCard);
		DEFINE_CARD(CForeverYoungCard);
		DEFINE_CARD(CGiantOpportunityCard);
		DEFINE_CARD(CIrencragFeatCard);
		DEFINE_CARD(CJoustCard);
		DEFINE_CARD(CMemoryTheftCard);
		DEFINE_CARD(COutmuscleCard);
		DEFINE_CARD(CReaveSoulCard);
		DEFINE_CARD(CSilverflameRitualCard);
		DEFINE_CARD(CSpectersShriekCard);
		DEFINE_CARD(CStolenByTheFaeCard);
		DEFINE_CARD(CSunderingStrokeCard);
		DEFINE_CARD(CTasteOfDeathCard);
		DEFINE_CARD(CUnexplainedVisionCard);
		DEFINE_CARD(CWitchsVengeanceCard);
		DEFINE_CARD(CWolfsQuarryCard);
		DEFINE_CARD(CBakeIntoAPieCard);
		DEFINE_CARD(CBanishIntoFableCard);
		DEFINE_CARD(CBargeInCard);
		DEFINE_CARD(CDidntSayPleaseCard);
		DEFINE_CARD(CDrownInTheLochCard);
		DEFINE_CARD(CFellThePheasantCard);
		DEFINE_CARD(CFestiveFuneralCard);
		DEFINE_CARD(CInsatiableAppetiteCard);
		DEFINE_CARD(CIntoTheStoryCard);
		DEFINE_CARD(CLashOfThornsCard);
		DEFINE_CARD(CMysticalDisputeCard);
		DEFINE_CARD(COkosHospitalityCard);
		DEFINE_CARD(COnceAndFutureCard);
		DEFINE_CARD(COnceUponATimeCard);
		DEFINE_CARD(COutflankCard);
		DEFINE_CARD(CRallyForTheThroneCard);
		DEFINE_CARD(CRedcapMeleeCard);
		DEFINE_CARD(CReturnOfTheWildspeakerCard);
		DEFINE_CARD(CRunAwayTogetherCard);
		DEFINE_CARD(CScorchingDragonfireCard);
		DEFINE_CARD(CSearingBarrageCard);
		DEFINE_CARD(CSlayingFireCard);
		DEFINE_CARD(CThrillOfPossibilityCard);
		DEFINE_CARD(CTrueLovesKissCard);
		DEFINE_CARD(CTurnIntoAPumpkinCard);
		DEFINE_CARD(CAcclaimedContenderCard);
		DEFINE_CARD(CArchonOfAbsolutionCard);
		DEFINE_CARD(CArdenvalePaladinCard);
		DEFINE_CARD(CArdenvaleTacticianCard);
		DEFINE_CARD(CBarteredCowCard);
		DEFINE_CARD(CBelovedPrincessCard);
		DEFINE_CARD(CCharmingPrinceCard);
		DEFINE_CARD(CFaerieGuidemotherCard);
		DEFINE_CARD(CFlutterfoxCard);
		DEFINE_CARD(CGarrisonGriffinCard);
		DEFINE_CARD(CGiantKillerCard);
		DEFINE_CARD(CHushbringerCard);
		DEFINE_CARD(CKenrithTheReturnedKingCard);
		DEFINE_CARD(CKnightOfTheKeepCard);
		DEFINE_CARD(CLindenTheSteadfastQueenCard);
		DEFINE_CARD(CLonesomeUnicornCard);
		DEFINE_CARD(CMysteriousPathlighterCard);
		DEFINE_CARD(CPrizedGriffinCard);
		DEFINE_CARD(CRealmCloakedGiantCard);
		DEFINE_CARD(CShepherdOfTheFlockCard);
		DEFINE_CARD(CSilverflameSquireCard);
		DEFINE_CARD(CSilverwingSquadronCard);
		DEFINE_CARD(CSyrAlinTheLionsClawCard);
		DEFINE_CARD(CVenerableKnightCard);
		DEFINE_CARD(CWorthyKnightCard);
		DEFINE_CARD(CBeanstalkGiantCard);
		DEFINE_CARD(CBramblefortFinkCard);
		DEFINE_CARD(CCuriousPairCard);
		DEFINE_CARD(CEdgewallInnkeeperCard);
		DEFINE_CARD(CFeastingTrollKingCard);
		DEFINE_CARD(CFierceWitchstalkerCard);
		DEFINE_CARD(CFlaxenIntruderCard);
		DEFINE_CARD(CGarenbrigCarverCard);
		DEFINE_CARD(CGarenbrigPaladinCard);
		DEFINE_CARD(CGarenbrigSquireCard);
		DEFINE_CARD(CGildedGooseCard);
		DEFINE_CARD(CKeeperOfFablesCard);
		DEFINE_CARD(CLovestruckBeastCard);
		DEFINE_CARD(COakhameAdversaryCard);
		DEFINE_CARD(CQuestingBeastCard);
		DEFINE_CARD(CRosethornAcolyteCard);
		DEFINE_CARD(CSteelbaneHydraCard);
		DEFINE_CARD(CSyrFarenTheHengehammerCard);
		DEFINE_CARD(CThornMammothCard);
		DEFINE_CARD(CTuinvaleTreefolkCard);
		DEFINE_CARD(CWickedWolfCard);
		DEFINE_CARD(CWildwoodTrackerCard);
		DEFINE_CARD(CYorvoLordOfGarenbrigCard);
		DEFINE_CARD(CBloodhazeWolverineCard);
		DEFINE_CARD(CBonecrusherGiantCard);
		DEFINE_CARD(CBrimstoneTrebuchetCard);
		DEFINE_CARD(CBurningYardTrainerCard);
		DEFINE_CARD(CEmberethPaladinCard);
		DEFINE_CARD(CEmberethShieldbreakerCard);
		DEFINE_CARD(CEmberethSkyblazerCard);
		DEFINE_CARD(CFerventChampionCard);
		DEFINE_CARD(CIrencragPyromancerCard);
		DEFINE_CARD(CMadRatterCard);
		DEFINE_CARD(CMerchantOfTheValeCard);
		DEFINE_CARD(COgreErrantCard);
		DEFINE_CARD(COpportunisticDragonCard);
		DEFINE_CARD(CRagingRedcapCard);
		DEFINE_CARD(CRedcapRaidersCard);
		DEFINE_CARD(CRimrockKnightCard);
		DEFINE_CARD(CRowansBattleguardCard);
		DEFINE_CARD(CRowansStalwartsCard);
		DEFINE_CARD(CSevenDwarvesCard);
		DEFINE_CARD(CSkullknockerOgreCard);
		DEFINE_CARD(CSyrCarahTheBoldCard);
		DEFINE_CARD(CWeaselbackRedcapCard);
		DEFINE_CARD(CAyaraFirstOfLocthwainCard);
		DEFINE_CARD(CBarrowWitchesCard);
		DEFINE_CARD(CBelleOfTheBrawlCard);
		DEFINE_CARD(CBlacklanceParagonCard);
		DEFINE_CARD(CBogNaughtyCard);
		DEFINE_CARD(CCauldronFamiliarCard);
		DEFINE_CARD(CChitteringWitchCard);
		DEFINE_CARD(CClackbridgeTrollCard);
		DEFINE_CARD(CEyeCollectorCard);
		DEFINE_CARD(CFoulmireKnightCard);
		DEFINE_CARD(CLocthwainPaladinCard);
		DEFINE_CARD(CLostLegionCard);
		DEFINE_CARD(CMalevolentNobleCard);
		DEFINE_CARD(CMurderousRiderCard);
		DEFINE_CARD(COathswornKnightCard);
		DEFINE_CARD(COrderOfMidnightCard);
		DEFINE_CARD(CPiperOfTheSwarmCard);
		DEFINE_CARD(CRankleMasterOfPranksCard);
		DEFINE_CARD(CReaperOfNightCard);
		DEFINE_CARD(CSmittenSwordmasterCard);
		DEFINE_CARD(CSyrKonradTheGrimCard);
		DEFINE_CARD(CTemptingWitchCard);
		DEFINE_CARD(CWickedGuardianCard);
		DEFINE_CARD(CAnimatingFaerieCard);
		DEFINE_CARD(CBrazenBorrowerCard);
		DEFINE_CARD(CCorridorMonitorCard);
		DEFINE_CARD(CEmryLurkerOfTheLochCard);
		DEFINE_CARD(CFaeOfWishesCard);
		DEFINE_CARD(CFaerieFormationCard);
		DEFINE_CARD(CFaerieVandalCard);
		DEFINE_CARD(CGadwickTheWizenedCard);
		DEFINE_CARD(CHypnoticSpriteCard);
		DEFINE_CARD(CMerfolkSecretkeeperCard);
		DEFINE_CARD(CMistfordRiverTurtleCard);
		DEFINE_CARD(CMoonlitScavengersCard);
		DEFINE_CARD(COkosAccomplicesCard);
		DEFINE_CARD(COverwhelmedApprenticeCard);
		DEFINE_CARD(CQueenOfIceCard);
		DEFINE_CARD(CSageOfTheFallsCard);
		DEFINE_CARD(CShimmerDragonCard);
		DEFINE_CARD(CSteelgazeGriffinCard);
		DEFINE_CARD(CSyrElenoraTheDiscerningCard);
		DEFINE_CARD(CTomeRaiderCard);
		DEFINE_CARD(CVantressGargoyleCard);
		DEFINE_CARD(CVantressPaladinCard);
		DEFINE_CARD(CWishfulMerfolkCard);
		DEFINE_CARD(CWorkshopEldersCard);
		DEFINE_CARD(CAlelaArtfulProvocateurCard);
		DEFINE_CARD(CArcanistsOwlCard);
		DEFINE_CARD(CChulaneTellerOfTalesCard);
		DEFINE_CARD(CClockworkServantCard);
		DEFINE_CARD(CCrashingDrawbridgeCard);
		DEFINE_CARD(CDeathlessKnightCard);
		DEFINE_CARD(CEliteHeadhunterCard);
		DEFINE_CARD(CFaeburrowElderCard);
		DEFINE_CARD(CFirebornKnightCard);
		DEFINE_CARD(CGingerbruteCard);
		DEFINE_CARD(CGluttonousTrollCard);
		DEFINE_CARD(CGrumgullyTheGenerousCard);
		DEFINE_CARD(CHengeWalkerCard);
		DEFINE_CARD(CInquisitivePuppetCard);
		DEFINE_CARD(CInspiringVeteranCard);
		DEFINE_CARD(CJoustingDummyCard);
		DEFINE_CARD(CKorvoldFaeCursedKingCard);
		DEFINE_CARD(CLochDragonCard);
		DEFINE_CARD(CLochmereSerpentCard);
		DEFINE_CARD(CLocthwainGargoyleCard);
		DEFINE_CARD(CMaraleafPixieCard);
		DEFINE_CARD(COakhameRangerCard);
		DEFINE_CARD(CProphetOfThePeakCard);
		DEFINE_CARD(CRampartSmasherCard);
		DEFINE_CARD(CResoluteRiderCard);
		DEFINE_CARD(CRovingKeepCard);
		DEFINE_CARD(CSavvyHunterCard);
		DEFINE_CARD(CShamblingSuitCard);
		DEFINE_CARD(CShinechaserCard);
		DEFINE_CARD(CSignpostScarecrowCard);
		DEFINE_CARD(CSorcerersBroomCard);
		DEFINE_CARD(CStonecoilSerpentCard);
		DEFINE_CARD(CStormfistCrusaderCard);
		DEFINE_CARD(CSyrGwynHeroOfAshvaleCard);
		DEFINE_CARD(CThunderousSnapperCard);
		DEFINE_CARD(CWandermareCard);
		DEFINE_CARD(CWintermoorCommanderCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
#define DWARF_A_TOKEN_NAME		_T("Dwarf (A)")
#define DWARF_A_TOKEN_ID		55148

//____________________________________________________________________________
//
CEldraineCheckLandCard::CEldraineCheckLandCard(CGame* pGame, LPCTSTR strCardName, UINT nID, CardType landType,
	LPCTSTR strTypeFilter, int nRequired)
	: CNonbasicLandCard(pGame, strCardName, nID, landType)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CEldraineCheckLandCard::OnZoneChanged))
	, m_strTypeFilter(strTypeFilter)
	, m_nRequired(nRequired)
{
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

BOOL CEldraineCheckLandCard::EntersUntapped() const
{
	// The other lands of the type that its controller controls
	const CCardFilter* pFilter = CCardFilter::GetFilter(m_strTypeFilter);
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	int nCount = pFilter->CountIncluded(pBattlefield->GetCardContainer());
	if (GetZoneId() == ZoneId::Battlefield && pFilter->IsCardIncluded(this))
		--nCount;
	return nCount >= m_nRequired;
}

void CEldraineCheckLandCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	// (as Glacial Fortress in M10)
	if (!pFromZone || !pToZone || pCard != this)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && !EntersUntapped())
		GetOrientation()->Tap();
}

bool CEldraineCheckLandCard::SetUntappedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return EntersUntapped() == TRUE;
}

void CEldraineCheckLandCard::AddEnterUntappedTrigger(CAbility::ResolutionStartedCallback callback)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEldraineCheckLandCard::SetUntappedContext));
	cpAbility->SetResolutionStartedCallback(callback);
	AddAbility(cpAbility.GetPointer());
}

CTargeting* CEldraineCheckLandCard::AddEnterUntappedTargetTrigger(CAbility::ResolutionStartedCallback callback, bool bOptional,
	Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEldraineCheckLandCard::SetUntappedContext));
	cpAbility->SetResolutionStartedCallback(callback);
	AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

//____________________________________________________________________________
//
CCastleArdenvaleCard::CCastleArdenvaleCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Castle Ardenvale"), nID, CardType::NonbasicLand, _T("Plains"), 1)
{
	// This land enters tapped unless you control a Plains. {T}: Add {W}.
	AddTapManaAbility(this, WHITE_MANA_TEXT);

	// {2}{W}{W}, {T}: Create a 1/1 white Human creature token.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT,
			HUMAN_C_TOKEN_NAME, HUMAN_C_TOKEN_ID, 1));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CCastleEmberethCard::CCastleEmberethCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Castle Embereth"), nID, CardType::NonbasicLand, _T("Mountains"), 1)
{
	// This land enters tapped unless you control a Mountain. {T}: Add {R}.
	AddTapManaAbility(this, RED_MANA_TEXT);

	// {1}{R}{R}, {T}: Creatures you control get +1/+0 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") RED_MANA_TEXT RED_MANA_TEXT));
	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Creatures you control get +1/+0 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCastleEmberethCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CCastleEmberethCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, 0);
	return true;
}

//____________________________________________________________________________
//
CCastleGarenbrigCard::CCastleGarenbrigCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Castle Garenbrig"), nID, CardType::NonbasicLand, _T("Forests"), 1)
{
	// This land enters tapped unless you control a Forest. {T}: Add {G}.
	AddTapManaAbility(this, GREEN_MANA_TEXT);

	// {2}{G}{G}, {T}: Add six {G}. Spend this mana only to cast creature spells or activate abilities of creatures.
	// Partial: the mana isn't restricted (the engine has no restricted mana).
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Activated,
			GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CCastleLocthwainCard::CCastleLocthwainCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Castle Locthwain"), nID, CardType::NonbasicLand, _T("Swamps"), 1)
{
	// This land enters tapped unless you control a Swamp. {T}: Add {B}.
	AddTapManaAbility(this, BLACK_MANA_TEXT);

	// {1}{B}{B}, {T}: Draw a card, then you lose life equal to the number of cards in your hand.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT));
	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Draw a card, then lose life equal to the number of cards in your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCastleLocthwainCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CCastleLocthwainCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);
	LoseLife(this, pController, pController->GetZoneById(ZoneId::Hand)->GetSize());
	return true;
}

//____________________________________________________________________________
//
CCastleVantressCard::CCastleVantressCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Castle Vantress"), nID, CardType::NonbasicLand, _T("Islands"), 1)
{
	// This land enters tapped unless you control an Island. {T}: Add {U}.
	AddTapManaAbility(this, BLUE_MANA_TEXT);

	// {2}{U}{U}, {T}: Scry 2.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT));
	cpAbility->AddTapCost();
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(pGame, 2, this));
	cpAbility->SetAbilityText(_T("Scry 2. Activates"));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CDwarvenMineCard::CDwarvenMineCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Dwarven Mine"), nID, CardType::NonbasicLand | CardType::Mountain, _T("Mountains"), 3)
{
	// ({T}: Add {R}.) This land enters tapped unless you control three or more other Mountains.
	AddTapManaAbility(this, RED_MANA_TEXT);

	// When this land enters untapped, create a 1/1 red Dwarf creature token.
	AddEnterUntappedTrigger(CAbility::ResolutionStartedCallback(this, &CDwarvenMineCard::BeforeToken));
}

bool CDwarvenMineCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), DWARF_A_TOKEN_NAME, DWARF_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CFabledPassageCard::CFabledPassageCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Fabled Passage"), nID)
{
	// {T}, Sacrifice this land: Search your library for a basic land card, put it onto the battlefield tapped, then
	// shuffle. Then if you control four or more lands, untap that land.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));
	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Search your library for a basic land card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFabledPassageCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CFabledPassageCard::BeforeSearch(CAbilityAction* pAction)
{
	// (as SearchToHand, with the land kept in a container to tap it and maybe untap it)
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &cards);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::AllPlayers,
		CCardFilter::GetFilter(_T("basic lands")),
		ZoneId::Battlefield,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);
	pController->GetZoneById(ZoneId::Library)->Shuffle();

	BOOL bUntap = CCardFilter::GetFilter(_T("lands"))->CountIncluded(
		pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= 4;
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pLand = cards.GetAt(i);
		if (pLand->GetZoneId() == ZoneId::Battlefield && !bUntap)
			CCardOrientationModifier(TRUE).ApplyTo(pLand);
	}
	return true;
}

//____________________________________________________________________________
//
CGingerbreadCabinCard::CGingerbreadCabinCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Gingerbread Cabin"), nID, CardType::NonbasicLand | CardType::Forest, _T("Forests"), 3)
{
	// ({T}: Add {G}.) This land enters tapped unless you control three or more other Forests.
	AddTapManaAbility(this, GREEN_MANA_TEXT);

	// When this land enters untapped, create a Food token.
	AddEnterUntappedTrigger(CAbility::ResolutionStartedCallback(this, &CGingerbreadCabinCard::BeforeFood));
}

bool CGingerbreadCabinCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CIdyllicGrangeCard::CIdyllicGrangeCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Idyllic Grange"), nID, CardType::NonbasicLand | CardType::Plains, _T("Plains"), 3)
{
	// ({T}: Add {W}.) This land enters tapped unless you control three or more other Plains.
	AddTapManaAbility(this, WHITE_MANA_TEXT);

	// When this land enters untapped, put a +1/+1 counter on target creature you control.
	CTargeting* pTargeting = AddEnterUntappedTargetTrigger(CAbility::ResolutionStartedCallback(this, &CIdyllicGrangeCard::BeforeCounter),
		false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CIdyllicGrangeCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(pAction->GetAssociatedCard(), 1);
	return false;
}

//____________________________________________________________________________
//
CMysticSanctuaryCard::CMysticSanctuaryCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Mystic Sanctuary"), nID, CardType::NonbasicLand | CardType::Island, _T("Islands"), 3)
{
	// ({T}: Add {U}.) This land enters tapped unless you control three or more other Islands.
	AddTapManaAbility(this, BLUE_MANA_TEXT);

	// When this land enters untapped, you may put target instant or sorcery card from your graveyard on top of your
	// library.
	CTargeting* pTargeting = AddEnterUntappedTargetTrigger(CAbility::ResolutionStartedCallback(this, &CMysticSanctuaryCard::BeforeTop),
		true, Characteristic::Positive);
	pTargeting->SetSubjectZoneId(ZoneId::Graveyard);
	pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CMysticSanctuaryCard::BeforeTop(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetToTop(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
CTournamentGroundsCard::CTournamentGroundsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Tournament Grounds"), nID)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {T}: Add {R}, {W}, or {B}. Spend this mana only to cast a Knight or Equipment spell.
	// Partial: the mana isn't restricted (the engine has no restricted mana).
	AddTapManaAbility(this, RED_MANA_TEXT);
	AddTapManaAbility(this, WHITE_MANA_TEXT);
	AddTapManaAbility(this, BLACK_MANA_TEXT);
}

//____________________________________________________________________________
//
CWitchsCottageCard::CWitchsCottageCard(CGame* pGame, UINT nID)
	: CEldraineCheckLandCard(pGame, _T("Witch's Cottage"), nID, CardType::NonbasicLand | CardType::Swamp, _T("Swamps"), 3)
{
	// ({T}: Add {B}.) This land enters tapped unless you control three or more other Swamps.
	AddTapManaAbility(this, BLACK_MANA_TEXT);

	// When this land enters untapped, you may put target creature card from your graveyard on top of your library.
	CTargeting* pTargeting = AddEnterUntappedTargetTrigger(CAbility::ResolutionStartedCallback(this, &CWitchsCottageCard::BeforeTop),
		true, Characteristic::Positive);
	pTargeting->SetSubjectZoneId(ZoneId::Graveyard);
	pTargeting->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CWitchsCottageCard::BeforeTop(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetToTop(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
#define WOLF_M_TOKEN_NAME				_T("Wolf (M)")
#define WOLF_M_TOKEN_ID					55149
#define ELK_A_TOKEN_NAME				_T("Elk (A)")
#define ELK_A_TOKEN_ID					64141
#define GARRUK_CURSED_EMBLEM_NAME		_T("Garruk, Cursed Huntsman Emblem")
#define GARRUK_CURSED_EMBLEM_ID			61163

// "<creature> has base power and toughness P/T" (as Tezzeret the Schemer's emblem: base and replacement modifiers);
// bOneTurnOnly: until end of turn
static void SetBasePowerToughness(CCard* pCard, int nPower, int nToughness, BOOL bOneTurnOnly)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || !pCreature->GetCardType().IsCreature() || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	CPowerModifier powerModifier;
	powerModifier.SetPowerDelta(Power(nPower));
	powerModifier.SetToBase(TRUE);
	powerModifier.SetReplacement(TRUE);
	powerModifier.SetOneTurnOnly(bOneTurnOnly);
	powerModifier.ApplyTo(pCreature);

	CLifeModifier lifeModifier;
	lifeModifier.SetLifeDelta(Life(nToughness));
	lifeModifier.SetToBase(TRUE);
	lifeModifier.SetReplacement(TRUE);
	lifeModifier.SetOneTurnOnly(bOneTurnOnly);
	lifeModifier.ApplyTo(pCreature);
}

//____________________________________________________________________________
//
CGarrukCursedHuntsmanCard::CGarrukCursedHuntsmanCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Garruk, Cursed Huntsman"), nID,
		_T("4") BLACK_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Garruk, 5)
{
	// 0: Create two 2/2 black and green Wolf creature tokens with "When this token dies, put a loyalty counter on each
	// Garruk you control."
	AddLoyaltyAbility(this, 0, _T("0: Create two 2/2 black and green Wolf creature tokens. Activates"),
		&CGarrukCursedHuntsmanCard::BeforeWolves);

	// -3: Destroy target creature. Draw a card.
	AddTargetLoyaltyAbility(this, -3, new AnyCreatureComparer, FALSE, Characteristic::Negative,
		&CGarrukCursedHuntsmanCard::BeforeDestroy);

	// -6: You get an emblem with "Creatures you control get +3/+3 and have trample."
	AddEmblemLoyaltyAbility(this, -6, GARRUK_CURSED_EMBLEM_NAME, GARRUK_CURSED_EMBLEM_ID,
		_T("-6: You get an emblem with \"Creatures you control get +3/+3 and have trample.\" Activates"));
}

bool CGarrukCursedHuntsmanCard::BeforeWolves(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), WOLF_M_TOKEN_NAME, WOLF_M_TOKEN_ID, 2).ApplyTo(pAction->GetController());
	return true;
}

bool CGarrukCursedHuntsmanCard::BeforeDestroy(CAbilityAction* pAction)
{
	DestroyPermanent(GetTargetCreature(pAction), pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 1);
	return false;
}

//____________________________________________________________________________
//
COkoTheTricksterCard::COkoTheTricksterCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Oko, the Trickster"), nID,
		_T("4") GREEN_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Oko, 4)
{
	// +1: Put two +1/+1 counters on up to one target creature you control.
	CActivatedAbility<CTargetSpell>* pCounters = AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &COkoTheTricksterCard::BeforeCounters);
	pCounters->GetTargeting()->SetSubjectCount(0, 1);
	pCounters->GetTargeting()->SetIncludeControllerCardsOnly();

	// 0: Until end of turn, Oko becomes a copy of target creature you control. Prevent all damage that would be dealt to
	// him this turn.
	// Not implemented: a permanent can't become a copy of another one.

	// -7: Until end of turn, each creature you control has base power and toughness 10/10 and gains trample.
	AddLoyaltyAbility(this, -7, _T("-7: Until end of turn, each creature you control has base power and toughness 10/10 and gains trample. Activates"),
		&COkoTheTricksterCard::BeforeBase);
}

bool COkoTheTricksterCard::BeforeCounters(CAbilityAction* pAction)
{
	AddPlusCounter(GetTargetCreature(pAction), 2);
	return false;
}

bool COkoTheTricksterCard::BeforeBase(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		SetBasePowerToughness(creatures.GetAt(i), 10, 10, TRUE);
		PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::Trample);
	}
	return true;
}

//____________________________________________________________________________
//
COkoThiefOfCrownsCard::COkoThiefOfCrownsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Oko, Thief of Crowns"), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, PlaneswalkerType::Oko, 4)
{
	// +2: Create a Food token.
	AddLoyaltyAbility(this, +2, _T("+2: Create a Food token. Activates"), &COkoThiefOfCrownsCard::BeforeFood);

	// +1: Target artifact or creature loses all abilities and becomes a green Elk creature with base power and toughness
	// 3/3.
	// Partial: a creature gets base power and toughness 3/3 but keeps its abilities, colors and types (the engine can't
	// remove all abilities); a noncreature artifact becomes a 3/3 green Elk creature (IsAlsoA Elk (A)) keeping its abilities.
	AddTargetLoyaltyAbility(this, +1,
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new AnyCreatureComparer), FALSE,
		Characteristic::Negative, &COkoThiefOfCrownsCard::BeforeElk);

	// -5: Exchange control of target artifact or creature you control and target creature an opponent controls with power
	// 3 or less. (two targets as Domri, Anarch of Bolas; the exchange as Eyes Everywhere)
	counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpExchange(
		::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
			_T(""),
			new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new AnyCreatureComparer), false,
			new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::less_equal<int>>(3)), false,
			_T(""), TRUE));

	cpExchange->GetCost().AddCounterCost(GetLoyaltyCounter(), -5);
	cpExchange->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpExchange->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpExchange->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpExchange->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpExchange->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COkoThiefOfCrownsCard::BeforeExchange));
	AddAbility(cpExchange.GetPointer());
}

bool COkoThiefOfCrownsCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool COkoThiefOfCrownsCard::BeforeElk(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	if (pCard->GetCardType().IsCreature())
		SetBasePowerToughness(pCard, 3, 3, FALSE);
	else if (!pCard->GetIsAlsoA())
		CCardIsAlsoAModifier(ELK_A_TOKEN_NAME, ELK_A_TOKEN_ID, pAction->GetController()).ApplyTo(pCard);
	return false;
}

bool COkoThiefOfCrownsCard::BeforeExchange(CAbilityAction* pAction)
{
	CCard* pCard1;
	CCard* pCard2;
	GetDoubleTargets(pAction, pCard1, pCard2);
	if (!pCard1 || !pCard2)
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
CRowanFearlessSparkmageCard::CRowanFearlessSparkmageCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Rowan, Fearless Sparkmage"), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Rowan, 5)
{
	// +1: Up to one target creature gets +3/+0 and gains first strike until end of turn.
	CActivatedAbility<CTargetSpell>* pPump = AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE,
		Characteristic::Positive, &CRowanFearlessSparkmageCard::BeforePump);
	pPump->GetTargeting()->SetSubjectCount(0, 1);

	// -2: Rowan deals 1 damage to each of up to two target creatures. Those creatures can't block this turn.
	CActivatedAbility<CTargetSpell>* pDamage = AddTargetLoyaltyAbility(this, -2, new AnyCreatureComparer, FALSE,
		Characteristic::Negative, &CRowanFearlessSparkmageCard::BeforeDamage);
	pDamage->GetTargeting()->SetSubjectCount(0, 2);

	// -9: Gain control of all creatures until end of turn. Untap them. They gain haste until end of turn.
	AddLoyaltyAbility(this, -9, _T("-9: Gain control of all creatures until end of turn. Untap them. They gain haste until end of turn. Activates"),
		&CRowanFearlessSparkmageCard::BeforeControl);
}

bool CRowanFearlessSparkmageCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +3, 0, CreatureKeyword::FirstStrike);
	return false;
}

bool CRowanFearlessSparkmageCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		DealDamageToCreature(this, pCard, 1);
		PumpCreature(pCard, 0, 0, CreatureKeyword::CantBlock);
	}
	return false;
}

bool CRowanFearlessSparkmageCard::BeforeControl(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		GetCreatures(GetGame(), GetGame()->GetPlayer(ip), TRUE, creatures);

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		if (pCard->GetController() != pController)
			GainControlUntilEndOfTurn(this, pCard);	// (it also untaps it and gives it haste)
		else
		{
			CCardOrientationModifier(FALSE).ApplyTo(pCard);
			PumpCreature(pCard, 0, 0, CreatureKeyword::Haste);
		}
	}
	return true;
}

//____________________________________________________________________________
//
CTheRoyalScionsCard::CTheRoyalScionsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("The Royal Scions"), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Will, 5)
{
	// (Legendary Planeswalker - Will Rowan) Partial: the engine keeps one planeswalker type, Will.

	// +1: Draw a card, then discard a card.
	AddLoyaltyAbility(this, +1, _T("+1: Draw a card, then discard a card. Activates"), &CTheRoyalScionsCard::BeforeLoot);

	// +1: Target creature gets +2/+0 and gains first strike and trample until end of turn.
	AddTargetLoyaltyAbility(this, +1, new AnyCreatureComparer, FALSE, Characteristic::Positive,
		&CTheRoyalScionsCard::BeforePump);

	// -8: Draw four cards. When you do, The Royal Scions deals damage to any target equal to the number of cards in your
	// hand. (the target is chosen when the ability is activated)
	AddTargetLoyaltyAbility(this, -8, NewCreatureOrPlaneswalkerComparer(), TRUE, Characteristic::Negative,
		&CTheRoyalScionsCard::BeforeDraw);
}

bool CTheRoyalScionsCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

bool CTheRoyalScionsCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = GetTargetCreature(pAction);
	if (pCard)
		PumpCreature(pCard, +2, 0, CreatureKeyword::FirstStrike | CreatureKeyword::Trample);
	return false;
}

bool CTheRoyalScionsCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 4);
	DealDamageToAnyTarget(this, pAction, pController->GetZoneById(ZoneId::Hand)->GetSize());
	return false;
}

//____________________________________________________________________________
//
#define FAERIE_A_TOKEN_NAME				_T("Faerie (A)")
#define FAERIE_A_TOKEN_ID				55150
#define HUMAN_WARRIOR_A_TOKEN_NAME		_T("Human Warrior (A)")
#define HUMAN_WARRIOR_A_TOKEN_ID		55151
#define HUMAN_CLERIC_B_TOKEN_NAME		_T("Human Cleric (B)")
#define HUMAN_CLERIC_B_TOKEN_ID			55152
#define HUMAN_ROGUE_A_TOKEN_NAME		_T("Human Rogue (A)")
#define HUMAN_ROGUE_A_TOKEN_ID			55153

// The controller of the card has seven or more cards in their graveyard (So Tiny)
struct SevenInGraveyardComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		return value->GetController()->GetZoneById(ZoneId::Graveyard)->GetSize() >= 7;
	}

	virtual SevenInGraveyardComparer* Clone() const
	{
		return new SevenInGraveyardComparer();
	}
};

//____________________________________________________________________________
//
CAllThatGlittersCard::CAllThatGlittersCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("All That Glitters"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+0), Life(+0))
{
	// Enchanted creature gets +1/+1 for each artifact and/or enchantment you control. (as Ethereal Armor)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().LinkCardModifier(
		new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CAllThatGlittersCard::CreateBonusAbility)));
}

counted_ptr<CAbility> CAllThatGlittersCard::CreateBonusAbility(CCard* pCard)
{
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(pCard,
			ZoneId::Battlefield,
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false)));

	cpAbility->StartListening(GetZone()->GetPlayer());
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CCharmedSleepCard::CCharmedSleepCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Charmed Sleep"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT,
		Power(+0), Life(+0))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CCharmedSleepCard::OnResolutionCompleted))
{
	// Enchant creature. When this Aura enters, tap enchanted creature. Enchanted creature doesn't untap during its
	// controller's untap step. (as Capture Sphere / Claustrophobia)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
	m_pChgPwrTghAttrEnchant->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
}

void CCharmedSleepCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	CCard* pTarget = pAbilityAction->GetAssociatedCard();
	if (bResult && pTarget)
		CCardOrientationModifier(TRUE).ApplyTo(pTarget);
}

//____________________________________________________________________________
//
CDeafeningSilenceCard::CDeafeningSilenceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Deafening Silence"), CardType::GlobalEnchantment, nID,
		WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Each player can't cast more than one noncreature spell each turn.
	// (when a player casts a noncreature spell, that player can't cast noncreature spells for the rest of the turn, as
	// Sphinx's Decree; without the stack)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetSkipStack(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDeafeningSilenceCard::SetCastContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDeafeningSilenceCard::BeforeLimit));
	AddAbility(cpAbility.GetPointer());
}

bool CDeafeningSilenceCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	if (!pCard)
		return false;
	triggerContext.nValue1 = (DWORD)pCard->GetController();
	return true;
}

bool CDeafeningSilenceCard::BeforeLimit(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (!pPlayer)
		return true;

	// (until end of turn, as Domri, Anarch of Bolas)
	int nFilter = reinterpret_cast<int>(CCardFilter::GetFilter(_T("non-creatures")));
	CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, nFilter).ApplyTo(pPlayer);
	CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::CantPlaySpells, nFilter),
		TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater);
	pRemove.ApplyTo(pPlayer);
	return true;
}

//____________________________________________________________________________
//
CDoomForetoldCard::CDoomForetoldCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Doom Foretold"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_NonlandNontokenFilter(_T("a nonland, nontoken permanent"), _T("nonland, nontoken permanents"),
		new AndCardComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			new NegateCardComparer(new CardTypeComparer(CardType::Token, false))))
{
	// At the beginning of each player's upkeep, that player sacrifices a nonland, nontoken permanent of their choice. If
	// that player can't, they discard a card, they lose 2 life, you draw a card, you gain 2 life, you create a 2/2 white
	// Knight creature token with vigilance, then you sacrifice this enchantment. (each upkeep, as Consuming Fervor)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDoomForetoldCard::BeforeSacrifice));
	AddAbility(cpAbility.GetPointer());
}

bool CDoomForetoldCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pPlayer = GetGame()->GetActivePlayer();

	if (m_NonlandNontokenFilter.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
	{
		ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, &m_NonlandNontokenFilter, ZoneId::Graveyard, MoveType::Sacrifice);
		return true;
	}

	DiscardCards(GetGame(), pPlayer, 1);
	LoseLife(this, pPlayer, 2);
	DrawCards(GetGame(), pController, 1);
	GainLife(this, pController, 2);
	CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1).ApplyTo(pController);
	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pController).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CFerocityOfTheWildsCard::CFerocityOfTheWildsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ferocity of the Wilds"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// Attacking non-Human creatures you control get +1/+0 and have trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AttackingCreatureComparer, new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false))),
			Power(+1), Life(+0), CreatureKeyword::Trample));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CFortifyingProvisionsCard::CFortifyingProvisionsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fortifying Provisions"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Creatures you control get +0/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+1)));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// When this enchantment enters, create a Food token.
	AddEnterTrigger(this, &CFortifyingProvisionsCard::BeforeFood);
}

bool CFortifyingProvisionsCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CEldraineBaseAuraCard::CEldraineBaseAuraCard(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCost, int nPower, int nToughness)
	: CChgPwrTghAttrEnchantCard(pGame, strCardName, nID, strCost, Power(+0), Life(+0))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CEldraineBaseAuraCard::OnResolutionCompleted))
{
	// Enchanted creature loses all abilities and is a <color> <type> creature with base power and toughness P/T.
	// Partial: it gets the base power and toughness (as Tezzeret the Schemer's emblem) while it's enchanted, but it keeps
	// its abilities, colors and types (the engine can't remove all abilities).
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	m_PowerModifier.SetPowerDelta(Power(nPower));
	m_PowerModifier.SetToBase(TRUE);
	m_PowerModifier.SetReplacement(TRUE);
	m_PowerModifier.SetOneTurnOnly(FALSE);
	m_LifeModifier.SetLifeDelta(Life(nToughness));
	m_LifeModifier.SetToBase(TRUE);
	m_LifeModifier.SetReplacement(TRUE);
	m_LifeModifier.SetOneTurnOnly(FALSE);

	AddLeaveTrigger(this, &CEldraineBaseAuraCard::BeforeLeave);
}

void CEldraineBaseAuraCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAbilityAction->GetAssociatedCard());
	if (!bResult || !pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	m_PowerModifier.ApplyTo(pCreature);
	m_LifeModifier.ApplyTo(pCreature);
	m_Enchanted.AddCard(pCreature, CardPlacement::Top);
}

bool CEldraineBaseAuraCard::BeforeLeave(CAbilityAction* pAction)
{
	while (m_Enchanted.GetSize() > 0)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(m_Enchanted.GetAt(0));
		m_Enchanted.RemoveCard(m_Enchanted.GetAt(0));
		if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		{
			m_PowerModifier.RemoveFrom(pCreature);
			m_LifeModifier.RemoveFrom(pCreature);
		}
	}
	return true;
}

//____________________________________________________________________________
//
CFrogifyCard::CFrogifyCard(CGame* pGame, UINT nID)
	: CEldraineBaseAuraCard(pGame, _T("Frogify"), nID, _T("1") BLUE_MANA_TEXT, 1, 1)
{
	// Enchant creature. Enchanted creature loses all abilities and is a blue Frog creature with base power and toughness
	// 1/1. (partial, see CEldraineBaseAuraCard)
}

//____________________________________________________________________________
//
CHappilyEverAfterCard::CHappilyEverAfterCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Happily Ever After"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, each player gains 5 life and draws a card.
	AddEnterTrigger(this, &CHappilyEverAfterCard::BeforeGainLife);

	// At the beginning of your upkeep, if there are five colors among permanents you control, there are six or more card
	// types among permanents you control and/or cards in your graveyard, and your life total is greater than or equal to
	// your starting life total, you win the game.
	AddStepTrigger(this, NodeId::UpkeepStep, false, &CHappilyEverAfterCard::SetUpkeepContext, &CHappilyEverAfterCard::BeforeWin);
}

bool CHappilyEverAfterCard::BeforeGainLife(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		GainLife(this, pPlayer, 5);
		DrawCards(GetGame(), pPlayer, 1);
	}
	return true;
}

BOOL CHappilyEverAfterCard::CanWin(CPlayer* pPlayer) const
{
	if (pPlayer->GetLife() < pPlayer->GetStartingLife())
		return FALSE;

	// Five colors among permanents you control
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	CardType colors = CardType::Null;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		colors |= pBattlefield->GetAt(i)->GetCardType() & CardType::_ColorMask;
	CardType allColors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	for (int c = 0; c < _countof(allColors); ++c)
		if (!(colors & allColors[c]).Any())
			return FALSE;

	// Six or more card types among permanents you control and/or cards in your graveyard
	CardType types[] = { CardType::Artifact, CardType::Creature, CardType::_Enchantment, CardType::Instant, CardType::_Land,
		CardType::Planeswalker, CardType::Sorcery, CardType::Tribal };
	CZone* pGraveyard = pPlayer->GetZoneById(ZoneId::Graveyard);
	int nTypes = 0;
	for (int t = 0; t < _countof(types); ++t)
	{
		BOOL bFound = FALSE;
		for (int i = 0; i < pBattlefield->GetSize() && !bFound; ++i)
			bFound = (pBattlefield->GetAt(i)->GetCardType() & types[t]).Any();
		for (int i = 0; i < pGraveyard->GetSize() && !bFound; ++i)
			bFound = (pGraveyard->GetAt(i)->GetCardType() & types[t]).Any();
		if (bFound)
			++nTypes;
	}
	return nTypes >= 6;
}

bool CHappilyEverAfterCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return CanWin(GetController()) == TRUE;
}

bool CHappilyEverAfterCard::BeforeWin(CAbilityAction* pAction)
{
	// "you win the game": each opponent loses it (as Ral, Izzet Viceroy's emblem)
	CPlayer* pController = pAction->GetController();
	if (!CanWin(pController))
		return true;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			GetGame()->GetPlayer(ip)->SetLostByOtherReasons();
	return true;
}

//____________________________________________________________________________
//
CImprobableAllianceCard::CImprobableAllianceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Improbable Alliance"), CardType::GlobalEnchantment, nID,
		BLUE_MANA_TEXT RED_MANA_TEXT, AbilityType::Enchantment)
	, m_nTurn(-1)
	, m_nDraws(0)
{
	{
		// Whenever you draw your second card each turn, create a 1/1 blue Faerie creature token with flying.
		// (the draws of the turn are counted in the context function)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CImprobableAllianceCard::SetDrawContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImprobableAllianceCard::BeforeFaerie));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{U}{R}: Draw a card, then discard a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4") BLUE_MANA_TEXT RED_MANA_TEXT));
		cpAbility->SetAbilityText(_T("Draw a card, then discard a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImprobableAllianceCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CImprobableAllianceCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	if (GetGame()->GetGameTurnNumber() != m_nTurn)
	{
		m_nTurn = GetGame()->GetGameTurnNumber();
		m_nDraws = 0;
	}
	++m_nDraws;
	return m_nDraws == 2;
}

bool CImprobableAllianceCard::BeforeFaerie(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FAERIE_A_TOKEN_NAME, FAERIE_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CImprobableAllianceCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CKenrithsTransformationCard::CKenrithsTransformationCard(CGame* pGame, UINT nID)
	: CEldraineBaseAuraCard(pGame, _T("Kenrith's Transformation"), nID, _T("1") GREEN_MANA_TEXT, 3, 3)
{
	// Enchant creature. When this Aura enters, draw a card.
	AddEnterTrigger(this, &CKenrithsTransformationCard::BeforeDraw);

	// Enchanted creature loses all abilities and is a green Elk creature with base power and toughness 3/3. (partial,
	// see CEldraineBaseAuraCard)
}

bool CKenrithsTransformationCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CKnightsChargeCard::CKnightsChargeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Knights' Charge"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever a Knight you control attacks, each opponent loses 1 life and you gain 1 life.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKnightsChargeCard::SetAttackContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKnightsChargeCard::BeforeDrain));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {6}{W}{B}, Sacrifice this enchantment: Return all Knight creature cards from your graveyard to the battlefield.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("6") WHITE_MANA_TEXT BLACK_MANA_TEXT));
		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Return all Knight creature cards from your graveyard to the battlefield. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKnightsChargeCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKnightsChargeCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attacked) const
{
	return pCreature && pCreature->GetController() == GetController() &&
		CreatureTypeComparer(CREATURE_TYPE(Knight), false)(pCreature);
}

bool CKnightsChargeCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			LoseLife(this, GetGame()->GetPlayer(ip), 1);
	GainLife(this, pController, 1);
	return true;
}

bool CKnightsChargeCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	CCountedCardContainer knights;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (pCard->GetCardType().IsCreature() && CreatureTypeComparer(CREATURE_TYPE(Knight), false)(pCard))
			knights.AddCard(pCard, CardPlacement::Top);
	}
	for (int i = 0; i < knights.GetSize(); ++i)
		if (knights.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
			CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController).ApplyTo(knights.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
COutlawsMerrimentCard::COutlawsMerrimentCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Outlaws' Merriment"), CardType::GlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, choose one at random. Create a red and white creature token with those
	// characteristics: 3/1 Human Warrior with trample and haste; 2/1 Human Cleric with lifelink and haste; 1/2 Human Rogue
	// with haste and "When this token enters, it deals 1 damage to any target."
	AddStepTrigger<COutlawsMerrimentCard>(this, NodeId::UpkeepStep, false, NULL, &COutlawsMerrimentCard::BeforeToken);
}

bool COutlawsMerrimentCard::BeforeToken(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	switch (pController->GetRand() % 3)
	{
	case 0:
		CTokenCreationModifier(GetGame(), HUMAN_WARRIOR_A_TOKEN_NAME, HUMAN_WARRIOR_A_TOKEN_ID, 1).ApplyTo(pController);
		break;
	case 1:
		CTokenCreationModifier(GetGame(), HUMAN_CLERIC_B_TOKEN_NAME, HUMAN_CLERIC_B_TOKEN_ID, 1).ApplyTo(pController);
		break;
	default:
		CTokenCreationModifier(GetGame(), HUMAN_ROGUE_A_TOKEN_NAME, HUMAN_ROGUE_A_TOKEN_ID, 1).ApplyTo(pController);
		break;
	}
	return true;
}

//____________________________________________________________________________
//
CRevengeOfRavensCard::CRevengeOfRavensCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Revenge of Ravens"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature attacks you or a planeswalker you control, that creature's controller loses 1 life and you gain
	// 1 life. (as Sarkhan the Masterless; the attacking player in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRevengeOfRavensCard::SetAttackContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CRevengeOfRavensCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CRevengeOfRavensCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attacked) const
{
	BOOL bYou = attacked.pPlayer == GetController() ||
		(attacked.cpPlaneswalker.GetPointer() && attacked.cpPlaneswalker->GetController() == GetController());
	if (!pCreature || !bYou)
		return false;
	triggerContext.nValue1 = (DWORD)pCreature->GetController();
	return true;
}

bool CRevengeOfRavensCard::BeforeDrain(TriggeredAbility::TriggeredActionType* pAction)
{
	LoseLife(this, (CPlayer*)pAction->GetTriggerContext().nValue1, 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CSoTinyCard::CSoTinyCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("So Tiny"), nID,
		BLUE_MANA_TEXT,
		Power(-2), Life(+0))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Enchant creature. Enchanted creature gets -2/-0. It gets -6/-0 instead as long as its controller has seven or more
	// cards in their graveyard. (the other -4/-0 with a condition, as Sea Legs)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new EnchantedByComparer(this), new SevenInGraveyardComparer),
			Power(-4), Life(+0)));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CTallAsABeanstalkCard::CTallAsABeanstalkCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Tall as a Beanstalk"), nID,
		_T("3") GREEN_MANA_TEXT,
		Power(+3), Life(+3), CreatureKeyword::Reach)
{
	// Enchant creature. Enchanted creature gets +3/+3, has reach, and is a Giant in addition to its other types.
	// Partial: the creature doesn't become a Giant.
}

//____________________________________________________________________________
//
CTrailOfCrumbsCard::CTrailOfCrumbsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Trail of Crumbs"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_PermanentFilter(_T("a permanent card"), _T("permanent cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)))
{
	// When this enchantment enters, create a Food token.
	AddEnterTrigger(this, &CTrailOfCrumbsCard::BeforeFood);

	// Whenever you sacrifice a Food, you may pay {1}. If you do, look at the top two cards of your library. You may reveal
	// a permanent card from among them and put it into your hand. Put the rest on the bottom of your library in any order.
	// Note: the rest go to the bottom in a random order.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("Foods")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T("1"));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTrailOfCrumbsCard::SetSacrificeContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTrailOfCrumbsCard::BeforeLook));
	AddAbility(cpAbility.GetPointer());
}

bool CTrailOfCrumbsCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CTrailOfCrumbsCard::SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Sacrifice;
}

bool CTrailOfCrumbsCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 2, 0, 1, &m_PermanentFilter);
	return true;
}

//____________________________________________________________________________
//
CTrappedInTheTowerCard::CTrappedInTheTowerCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Trapped in the Tower"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
	, m_CardFilter(_T("enchanted by this"), _T("enchanted by this"), new EnchantedByComparer(this))
{
	// Enchant creature without flying. Enchanted creature can't attack or block, and its activated abilities can't be
	// activated. (as Demotion in Guilds of Ravnica)
	m_pChgPwrTghAttrEnchant->GetTargeting()->GetSubjectCardFilter().AddComparer(
		new NegateCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false)));
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	CCantActivateAbilitiesModifier* pModifier = new CCantActivateAbilitiesModifier(GetGame(), &m_CardFilter);
	m_pChgPwrTghAttrEnchant->GetCreatureKeywordMod().LinkCardModifier(pModifier);
}

//____________________________________________________________________________
//
#define MOUSE_A_TOKEN_NAME				_T("Mouse (A)")
#define MOUSE_A_TOKEN_ID				55154
#define ENCHANTED_CARRIAGE_VEHICLE_NAME	_T("Enchanted Carriage (Vehicle)")
#define ENCHANTED_CARRIAGE_VEHICLE_ID	64142

// Adds the variants of a spell whose cost is reduced by nPerCount generic mana for each <count> (see CCountReduction):
// the main spell is castable only with a count of 0
static void AddCountReductionSpells(CCard* pCard, std::list<CCountReduction>& reductions, int nGeneric, LPCTSTR strColored,
	int nPerCount, CCountReduction::CountFunction count)
{
	int nMax = (nGeneric + nPerCount - 1) / nPerCount;	// the count that leaves no generic mana

	reductions.push_back(CCountReduction(pCard, count, 0, FALSE));
	{
		CSpell* pMain = pCard->GetSpells().GetAt(0);
		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(pMain, CPlayableIfTrait::PlayableCallback(&reductions.back(), &CCountReduction::IsPlayable)));
		pMain->Add(cpTrait.GetPointer());
	}

	for (int k = 1; k <= nMax; ++k)
	{
		int nLeft = nGeneric - k * nPerCount;
		CString strCost = MakeCost(nLeft > 0 ? nLeft : 0, strColored);

		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(pCard, pCard->GetSpells().GetAt(0)->GetAbilityType(), (LPCTSTR)strCost, TRUE));
		cpSpell->SetMainSpell(FALSE);

		reductions.push_back(CCountReduction(pCard, count, k, k == nMax));
		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(), CPlayableIfTrait::PlayableCallback(&reductions.back(), &CCountReduction::IsPlayable)));
		cpSpell->Add(cpTrait.GetPointer());
		pCard->AddSpell(cpSpell.GetPointer());
	}
}

// The counts of the cost reductions
static int CountYourAttackingCreatures(CCard* pCard)
{
	return CountAttackingCreatures(pCard->GetGame(), pCard->GetController());
}

static int CountYourKnights(CCard* pCard)
{
	CCountedCardContainer knights;
	GetCreaturesOfType(pCard->GetGame(), pCard->GetController(), CREATURE_TYPE(Knight), knights);
	return knights.GetSize();
}

static int GetGreatestPower(CCard* pCard)
{
	CCountedCardContainer creatures;
	GetCreatures(pCard->GetGame(), pCard->GetController(), TRUE, creatures);
	int nMax = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && GET_INTEGER(pCreature->GetPower()) > nMax)
			nMax = GET_INTEGER(pCreature->GetPower());
	}
	return nMax;
}

static int CountInstantsSorceriesInGraveyard(CCard* pCard)
{
	return CCardFilter::GetFilter(_T("instant cards or sorcery cards"))->CountIncluded(
		pCard->GetController()->GetZoneById(ZoneId::Graveyard)->GetCardContainer());
}

static int CountYourCreatureCardsInGraveyard(CCard* pCard)
{
	return CountCreatureCardsInGraveyard(pCard->GetController());
}

// Attaches the Equipment to the creature ("attach it to target creature you control", as CreateTokenAndAttach)
static void AttachEquipment(CCard* pEquipment, CCard* pCard)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || pEquipment->GetZoneId() != ZoneId::Battlefield)
		return;

	CEquipAbility* pFirst = NULL;
	for (int i = 0; i < pEquipment->GetAbilityCount(); ++i)
	{
		CEquipAbility* pEquipAbility = dynamic_cast<CEquipAbility*>(pEquipment->GetAbility(i));
		if (!pEquipAbility)
			continue;
		pEquipAbility->Unequip();
		if (!pFirst)
			pFirst = pEquipAbility;
	}
	if (pFirst)
		pFirst->Equip(pCreature);
}

// "Equipped creature gets +P/+T (and has <keywords>)" on an equip ability
static void AddEquipBonus(CEquipAbility* pAbility, CCard* pEquipment, int nPower, int nToughness, CreatureKeyword keywords)
{
	if (nPower != 0)
		pAbility->AddCreatureModifier(new CPowerModifier(Power(nPower), FALSE));
	if (nToughness != 0)
		pAbility->AddCreatureModifier(new CLifeModifier(Life(nToughness), pEquipment, PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE));
	if (keywords != CreatureKeyword::Null)
	{
		CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
		pModifier->GetModifier().SetToAdd(keywords);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		pAbility->AddCreatureModifier(pModifier);
	}
	pAbility->AddAbilityTag(AbilityTag::CreatureChange);
}

// A creature of the color chosen for Heraldic Banner
struct ChosenColorComparer : public CardComparer
{
	ChosenColorComparer(const CHeraldicBannerCard* pBanner) : m_pBanner(pBanner) {}

	virtual bool operator()(const CCard* value) const
	{
		static const CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
		DWORD dwColor = m_pBanner->GetChosenColor();
		return dwColor >= 1 && dwColor <= 5 && (value->GetCardType() & colors[dwColor - 1]).Any();
	}

	virtual ChosenColorComparer* Clone() const
	{
		return new ChosenColorComparer(m_pBanner);
	}

	const CHeraldicBannerCard* m_pBanner;
};

// The card has at least N charge counters (Mace of the Valiant)
struct ChargeAtLeastComparer : public CardComparer
{
	ChargeAtLeastComparer(const CCard* pCard, int nCount) : m_pCard(pCard), m_nCount(nCount) {}

	virtual bool operator()(const CCard* value) const
	{
		return CountCounters(m_pCard, CHARGE_COUNTER) >= m_nCount;
	}

	virtual ChargeAtLeastComparer* Clone() const
	{
		return new ChargeAtLeastComparer(m_pCard, m_nCount);
	}

	const CCard* m_pCard;
	int m_nCount;
};

//____________________________________________________________________________
//
CCrystalSlipperCard::CCrystalSlipperCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Crystal Slipper"), CardType::Artifact | CardType::Equipment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Artifact)
{
	// Equipped creature gets +1/+0 and has haste. Equip {1}
	counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("1")));
	AddEquipBonus(cpAbility.GetPointer(), this, +1, 0, CreatureKeyword::Haste);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CEmbercleaveCard::CEmbercleaveCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Embercleave"), CardType::Artifact | CardType::Legendary | CardType::Equipment, nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, AbilityType::Artifact)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// This spell costs {1} less to cast for each attacking creature you control.
	AddCountReductionSpells(this, m_Reductions, 4, RED_MANA_TEXT RED_MANA_TEXT, 1, &CountYourAttackingCreatures);

	// When Embercleave enters, attach it to target creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CEmbercleaveCard::BeforeAttach, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();

	// Equipped creature gets +1/+1 and has double strike and trample. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("3")));
	AddEquipBonus(cpAbility.GetPointer(), this, +1, +1, CreatureKeyword::DoubleStrike | CreatureKeyword::Trample);
	AddAbility(cpAbility.GetPointer());
}

bool CEmbercleaveCard::BeforeAttach(CAbilityAction* pAction)
{
	AttachEquipment(this, pAction->GetAssociatedCard());
	return false;
}

//____________________________________________________________________________
//
CEnchantedCarriageCard::CEnchantedCarriageCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Enchanted Carriage"), CardType::Artifact, nID,
		_T("5"), AbilityType::Artifact)
	, m_Crew(this)
{
	// When this Vehicle enters, create two 1/1 white Mouse creature tokens.
	AddEnterTrigger(this, &CEnchantedCarriageCard::BeforeMice);

	// Crew 2 (a 4/4, Enchanted Carriage (Vehicle) in ATokens)
	m_Crew.AddCrewAbility(2, ENCHANTED_CARRIAGE_VEHICLE_NAME, ENCHANTED_CARRIAGE_VEHICLE_ID);
}

bool CEnchantedCarriageCard::BeforeMice(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), MOUSE_A_TOKEN_NAME, MOUSE_A_TOKEN_ID, 2).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CFolioOfFanciesCard::CFolioOfFanciesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Folio of Fancies"), CardType::Artifact, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Artifact)
{
	{
		// Players have no maximum hand size.
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this, PlayerEffectType::NoMaximumHandSize));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {X}{X}, {T}: Each player draws X cards. (a doubled X as in Alliances)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
		cpAbility->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);
		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Each player draws X cards. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFolioOfFanciesCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{U}, {T}: Each opponent mills cards equal to the number of cards in their hand.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") BLUE_MANA_TEXT));
		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Each opponent mills cards equal to the number of cards in their hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFolioOfFanciesCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFolioOfFanciesCard::BeforeDraw(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0)
		for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
			DrawCards(GetGame(), GetGame()->GetPlayer(ip), nX);
	return true;
}

bool CFolioOfFanciesCard::BeforeMill(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer != pAction->GetController())
			Mill(pPlayer, pPlayer->GetZoneById(ZoneId::Hand)->GetSize());
	}
	return true;
}

//____________________________________________________________________________
//
CGiantsSkewerCard::CGiantsSkewerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Giant's Skewer"), CardType::Artifact | CardType::Equipment, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Artifact)
{
	{
		// Equipped creature gets +2/+1. Equip {3}
		counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("3")));
		AddEquipBonus(cpAbility.GetPointer(), this, +2, +1, CreatureKeyword::Null);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever equipped creature deals combat damage to a creature, create a Food token. (as Kazarov)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::CreatureEventCallback, &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGiantsSkewerCard::SetDamageContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGiantsSkewerCard::BeforeFood));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGiantsSkewerCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pFromCard && EquippedByComparer(this)(pFromCard);
}

bool CGiantsSkewerCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CGlassCasketCard::CGlassCasketCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Glass Casket"), CardType::Artifact, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Artifact)
{
	// When this artifact enters, exile target creature an opponent controls with mana value 3 or less until this artifact
	// leaves the battlefield. (as Hieromancer's Cage in M19)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CGlassCasketCard::BeforeExile, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(3));
	pTargeting->SetIncludeNonControllerCardsOnly();

	AddLeaveTrigger(this, &CGlassCasketCard::BeforeReturn);
}

bool CGlassCasketCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CGlassCasketCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CGoldenEggCard::CGoldenEggCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Golden Egg"), CardType::Artifact | CardType::Food, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters, draw a card.
	AddEnterTrigger(this, &CGoldenEggCard::BeforeDraw);

	// {1}, {T}, Sacrifice this artifact: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("1"), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}

	// {2}, {T}, Sacrifice this artifact: You gain 3 life. (as the Food token)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2")));
	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->SetAbilityText(_T("You gain 3 life. Activates"));
	AddAbility(cpAbility.GetPointer());
}

bool CGoldenEggCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CHeraldicBannerCard::CHeraldicBannerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Heraldic Banner"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_ColorSelection(pGame, CSelectionSupport::SelectionCallback(this, &CHeraldicBannerCard::OnColorSelected))
	, m_dwChosenColor(0)
{
	// As this artifact enters, choose a color. (chosen by a trigger when it enters, as Diamond Mare in M19)
	AddEnterTrigger(this, &CHeraldicBannerCard::BeforeChoose);

	// Creatures you control of the chosen color get +1/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpLord(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new AnyCreatureComparer, new ChosenColorComparer(this)),
			Power(+1), Life(+0)));
	cpLord->SetAffectControllerCardsOnly();
	AddAbility(cpLord.GetPointer());

	// {T}: Add one mana of the chosen color. (one mana ability for each color, as Mox Amber)
	LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	typedef BOOL (CHeraldicBannerCard::*Condition)(BOOL);
	Condition conditions[] = { &CHeraldicBannerCard::IsWhite, &CHeraldicBannerCard::IsBlue, &CHeraldicBannerCard::IsBlack,
		&CHeraldicBannerCard::IsRed, &CHeraldicBannerCard::IsGreen };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, mana[i]));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), conditions[i]);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHeraldicBannerCard::BeforeChoose(CAbilityAction* pAction)
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

void CHeraldicBannerCard::OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			m_dwChosenColor = it->dwContext + 1;
}

//____________________________________________________________________________
//
CMaceOfTheValiantCard::CMaceOfTheValiantCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mace of the Valiant"), CardType::Artifact | CardType::Equipment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Artifact)
{
	{
		// Equipped creature ... has vigilance. Equip {3}
		counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("3")));
		AddEquipBonus(cpAbility.GetPointer(), this, 0, 0, CreatureKeyword::Vigilance);
		AddAbility(cpAbility.GetPointer());
	}

	// Equipped creature gets +1/+1 for each charge counter on this Equipment.
	// (one +1/+1 for each number of counters, up to 10, with a condition on the counters; pending to test that the bonus is
	// updated when a counter is put)
	for (int n = 1; n <= 10; ++n)
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new EquippedByComparer(this), new ChargeAtLeastComparer(this, n)),
				Power(+1), Life(+1)));
		AddAbility(cpAbility.GetPointer());
	}

	// Whenever a creature you control enters, put a charge counter on this Equipment.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMaceOfTheValiantCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CMaceOfTheValiantCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(CHARGE_COUNTER, +1).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CMantleOfTidesCard::CMantleOfTidesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mantle of Tides"), CardType::Artifact | CardType::Equipment, nID,
		BLUE_MANA_TEXT, AbilityType::Artifact)
	, m_nTurn(-1)
	, m_nDraws(0)
{
	{
		// Equipped creature gets +1/+2. Equip {3}
		counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("3")));
		AddEquipBonus(cpAbility.GetPointer(), this, +1, +2, CreatureKeyword::Null);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you draw your second card each turn, attach this Equipment to target creature you control.
		// (the draws counted in the context function, as Improbable Alliance)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMantleOfTidesCard::SetDrawContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMantleOfTidesCard::BeforeAttach));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMantleOfTidesCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	if (GetGame()->GetGameTurnNumber() != m_nTurn)
	{
		m_nTurn = GetGame()->GetGameTurnNumber();
		m_nDraws = 0;
	}
	++m_nDraws;
	return m_nDraws == 2;
}

bool CMantleOfTidesCard::BeforeAttach(CAbilityAction* pAction)
{
	AttachEquipment(this, pAction->GetAssociatedCard());
	return false;
}

//____________________________________________________________________________
//
CMidnightClockCard::CMidnightClockCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Midnight Clock"), CardType::Artifact, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Artifact)
{
	// {T}: Add {U}.
	AddTapManaAbility(this, BLUE_MANA_TEXT);

	{
		// {2}{U}: Put an hour counter on this artifact.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") BLUE_MANA_TEXT));
		cpAbility->SetAbilityText(_T("Put an hour counter on this artifact. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMidnightClockCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each upkeep, put an hour counter on this artifact. (each upkeep, as Consuming Fervor)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMidnightClockCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// When the twelfth hour counter is put on this artifact, shuffle your hand and graveyard into your library, then draw
	// seven cards. Exile this artifact.
	// Note: done when the twelfth counter is put (without the stack)
}

bool CMidnightClockCard::BeforeCounter(CAbilityAction* pAction)
{
	AddHourCounter(pAction->GetController());
	return true;
}

void CMidnightClockCard::AddHourCounter(CPlayer* pController)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	int nBefore = CountCounters(this, _T("hour counter"));
	CCardCounterModifier(_T("hour counter"), +1).ApplyTo(this);
	if (nBefore >= 12 || CountCounters(this, _T("hour counter")) < 12)
		return;

	// Shuffle your hand and graveyard into your library
	ZoneId zones[] = { ZoneId::Hand, ZoneId::Graveyard };
	for (int z = 0; z < _countof(zones); ++z)
	{
		CZone* pZone = pController->GetZoneById(zones[z]);
		CCountedCardContainer cards;
		for (int i = 0; i < pZone->GetSize(); ++i)
			cards.AddCard(pZone->GetAt(i), CardPlacement::Top);
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == zones[z])
				CMoveCardModifier(zones[z], ZoneId::Library, TRUE, MoveType::Others, pController).ApplyTo(cards.GetAt(i));
	}
	pController->GetZoneById(ZoneId::Library)->Shuffle();

	// then draw seven cards. Exile this artifact.
	DrawCards(GetGame(), pController, 7);
	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController).ApplyTo(this);
}

//____________________________________________________________________________
//
CRosethornHalberdCard::CRosethornHalberdCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Rosethorn Halberd"), CardType::Artifact | CardType::Equipment, nID,
		GREEN_MANA_TEXT, AbilityType::Artifact)
{
	// When this Equipment enters, attach it to target non-Human creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CRosethornHalberdCard::BeforeAttach, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false)));
	pTargeting->SetIncludeControllerCardsOnly();

	// Equipped creature gets +2/+1. Equip {5}
	counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("5")));
	AddEquipBonus(cpAbility.GetPointer(), this, +2, +1, CreatureKeyword::Null);
	AddAbility(cpAbility.GetPointer());
}

bool CRosethornHalberdCard::BeforeAttach(CAbilityAction* pAction)
{
	AttachEquipment(this, pAction->GetAssociatedCard());
	return false;
}

//____________________________________________________________________________
//
CScaldingCauldronCard::CScaldingCauldronCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Scalding Cauldron"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {3}, {T}, Sacrifice this artifact: It deals 3 damage to target creature.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("3"),
			new AnyCreatureComparer, FALSE,
			Life(-3), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CShiningArmorCard::CShiningArmorCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Shining Armor"), CardType::Artifact | CardType::Equipment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Artifact)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this Equipment enters, attach it to target Knight you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CShiningArmorCard::BeforeAttach, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	pTargeting->SetIncludeControllerCardsOnly();

	// Equipped creature gets +0/+2 and has vigilance. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("3")));
	AddEquipBonus(cpAbility.GetPointer(), this, 0, +2, CreatureKeyword::Vigilance);
	AddAbility(cpAbility.GetPointer());
}

bool CShiningArmorCard::BeforeAttach(CAbilityAction* pAction)
{
	AttachEquipment(this, pAction->GetAssociatedCard());
	return false;
}

//____________________________________________________________________________
//
CSorcerousSpyglassCard::CSorcerousSpyglassCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sorcerous Spyglass"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_CardFilter(new CardAbilityTypeComparer(AbilityType::Activated, true, AbilityType::ManaSource))
{
	// As this artifact enters, look at an opponent's hand, then choose any card name. Activated abilities of sources with
	// the chosen name can't be activated unless they're mana abilities. (as Pithing Needle in Ten)
	// Partial: the opponent's hand isn't shown.
	typedef
		TTriggeredAbility< CTriggeredPlayerEffectAbility2, CWhenSelfInplay,
							CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetCardFilters(NULL, &m_CardFilter);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetSelectByControllerOnly(TRUE);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToAllPlayers);
	cpAbility->SetPlayerEffect(PlayerEffectType::CantPlayActivatedAbilities2, FALSE);
	cpAbility->SetRemoveEffectWhenLeaveInplay(TRUE);
	cpAbility->SetSkipStack(TRUE);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSpinningWheelCard::CSpinningWheelCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Spinning Wheel"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);

	// {5}, {T}: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("5"),
			new AnyCreatureComparer, FALSE));
	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSteelclawLanceCard::CSteelclawLanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Steelclaw Lance"), CardType::Artifact | CardType::Equipment, nID,
		BLACK_MANA_TEXT RED_MANA_TEXT, AbilityType::Artifact)
{
	// Equipped creature gets +2/+2.
	// Equip Knight {1} (the third parameter of CEquipAbility, as Blackblade Reforged)
	{
		counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("1"),
			new AndCardComparer(new AnyCreatureComparer, new CreatureTypeComparer(CREATURE_TYPE(Knight), false))));
		AddEquipBonus(cpAbility.GetPointer(), this, +2, +2, CreatureKeyword::Null);
		AddAbility(cpAbility.GetPointer());
	}
	// Equip {3}
	{
		counted_ptr<CEquipAbility> cpAbility(::CreateObject<CEquipAbility>(this, _T("3")));
		AddEquipBonus(cpAbility.GetPointer(), this, +2, +2, CreatureKeyword::Null);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CTheCauldronOfEternityCard::CTheCauldronOfEternityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Cauldron of Eternity"), CardType::Artifact | CardType::Legendary, nID,
		_T("10") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Artifact)
{
	// This spell costs {2} less to cast for each creature card in your graveyard.
	AddCountReductionSpells(this, m_Reductions, 10, BLACK_MANA_TEXT BLACK_MANA_TEXT, 2, &CountYourCreatureCardsInGraveyard);

	{
		// Whenever a creature you control dies, put it on the bottom of its owner's library. (the card in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTheCauldronOfEternityCard::SetDiesContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CTheCauldronOfEternityCard::BeforeBottom));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{B}, {T}, Pay 2 life: Return target creature card from your graveyard to the battlefield. Activate only as a
		// sorcery.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("2") BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

		cpAbility->AddTapCost();
		cpAbility->AddPayLifeDeltaCost(Life(-2));
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTheCauldronOfEternityCard::SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard->GetCardType().IsToken())
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CTheCauldronOfEternityCard::BeforeBottom(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetToTop(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
CTheCircleOfLoyaltyCard::CTheCircleOfLoyaltyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Circle of Loyalty"), CardType::Artifact | CardType::Legendary, nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Artifact)
{
	// Affinity for Knights (This spell costs {1} less to cast for each Knight you control.)
	AddCountReductionSpells(this, m_Reductions, 4, WHITE_MANA_TEXT WHITE_MANA_TEXT, 1, &CountYourKnights);

	{
		// Creatures you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this, new AnyCreatureComparer, Power(+1), Life(+1)));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast a legendary spell, create a 2/2 white Knight creature token with vigilance.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Legendary, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheCircleOfLoyaltyCard::BeforeKnight));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{W}, {T}: Create a 2/2 white Knight creature token with vigilance.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("3") WHITE_MANA_TEXT,
				KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTheCircleOfLoyaltyCard::BeforeKnight(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CTheGreatHengeCard::CTheGreatHengeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Great Henge"), CardType::Artifact | CardType::Legendary, nID,
		_T("7") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Artifact)
{
	// This spell costs {X} less to cast, where X is the greatest power among creatures you control.
	AddCountReductionSpells(this, m_Reductions, 7, GREEN_MANA_TEXT GREEN_MANA_TEXT, 1, &GetGreatestPower);

	// {T}: Add {G}{G}. You gain 2 life.
	// Partial: without the life (the mana abilities have no effects).
	AddTapManaAbility(this, GREEN_MANA_TEXT GREEN_MANA_TEXT);

	// Whenever a nontoken creature you control enters, put a +1/+1 counter on it and draw a card. (the creature in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTheGreatHengeCard::SetEnterContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CTheGreatHengeCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CTheGreatHengeCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard->GetCardType().IsToken())
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CTheGreatHengeCard::BeforeCounter(TriggeredAbility::TriggeredActionType* pAction)
{
	AddPlusCounter((CCard*)pAction->GetTriggerContext().nValue1, 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CTheMagicMirrorCard::CTheMagicMirrorCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("The Magic Mirror"), CardType::Artifact | CardType::Legendary, nID,
		_T("6") BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Artifact)
{
	// This spell costs {1} less to cast for each instant and sorcery card in your graveyard.
	AddCountReductionSpells(this, m_Reductions, 6, BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, 1, &CountInstantsSorceriesInGraveyard);

	{
		// You have no maximum hand size.
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this, PlayerEffectType::NoMaximumHandSize));
		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your upkeep, put a knowledge counter on The Magic Mirror, then draw a card for each knowledge
	// counter on The Magic Mirror.
	AddStepTrigger<CTheMagicMirrorCard>(this, NodeId::UpkeepStep, false, NULL, &CTheMagicMirrorCard::BeforeDraw);
}

bool CTheMagicMirrorCard::BeforeDraw(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(_T("knowledge counter"), +1).ApplyTo(this);
	int nCount = CountCounters(this, _T("knowledge counter"));
	if (nCount > 0)
		DrawCards(GetGame(), pAction->GetController(), nCount);
	return true;
}

//____________________________________________________________________________
//
CTomeOfLegendsCard::CTomeOfLegendsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Tome of Legends"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// This artifact enters with a page counter on it.
	GetCounterContainer()->ScheduleCounter(_T("page counter"), 1, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// Whenever your commander enters or attacks, put a page counter on this artifact.
	// Not implemented: the cards of the other modules can't know which card is the commander.

	// {1}, {T}, Remove a page counter from this artifact: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("1"), 1));
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("page counter")), -1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CWeaponRackCard::CWeaponRackCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Weapon Rack"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
{
	// This artifact enters with three +1/+1 counters on it.
	GetCounterContainer()->ScheduleCounter(_T("+1/+1"), 3, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// {T}: Move a +1/+1 counter from this artifact onto target creature. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("+1/+1")), -1);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CWishclawTalismanCard::CWishclawTalismanCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Wishclaw Talisman"), CardType::Artifact, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Artifact)
{
	// This artifact enters with three wish counters on it.
	GetCounterContainer()->ScheduleCounter(_T("wish counter"), 3, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// {1}, {T}, Remove a wish counter from this artifact: Search your library for a card, put it into your hand, then
	// shuffle. An opponent gains control of this artifact. Activate only during your turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("wish counter")), -1);
	cpAbility->SetAbilityText(_T("Search your library for a card. An opponent gains control of this artifact. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWishclawTalismanCard::BeforeSearch));
	AddPlayableIf(this, cpAbility.GetPointer(), &CWishclawTalismanCard::IsYourTurn);
	AddAbility(cpAbility.GetPointer());
}

BOOL CWishclawTalismanCard::IsYourTurn(BOOL bIncludeTricks)
{
	return GetGame()->GetActivePlayer() == GetController();
}

bool CWishclawTalismanCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	SearchToHand(GetGame(), pController, 1, CCardFilter::GetFilter(_T("cards")));

	// (as Captive Audience in Ravnica Allegiance)
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	if (pOpponent && pOpponent != pController && GetZoneId() == ZoneId::Battlefield)
		CTransferControlModifier(GetGame(), this, this).ApplyTo(pOpponent);
	return true;
}

//____________________________________________________________________________
//
CWitchingWellCard::CWitchingWellCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Witching Well"), CardType::Artifact, nID,
		BLUE_MANA_TEXT, AbilityType::Artifact)
{
	// When this artifact enters, scry 2.
	AddEnterTrigger(this, &CWitchingWellCard::BeforeScry);

	// {3}{U}, Sacrifice this artifact: Draw two cards.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3") BLUE_MANA_TEXT, 2));
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

bool CWitchingWellCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CWitchsOvenCard::CWitchsOvenCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Witch's Oven"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {T}, Sacrifice a creature: Create a Food token. If the sacrificed creature's toughness was 4 or greater, create two
	// Food tokens instead.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetAbilityText(_T("Create a Food token (two if the toughness was 4 or greater). Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWitchsOvenCard::BeforeFood));
	AddAbility(cpAbility.GetPointer());
}

bool CWitchsOvenCard::BeforeFood(CAbilityAction* pAction)
{
	// (the sacrificed creature, as Severed Strands in Guilds of Ravnica)
	int nCount = 1;
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	if (pSacrificed && pSacrificed->GetSize() > 0)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pSacrificed->GetAt(0));
		if (pCreature && GET_INTEGER(pCreature->GetLastKnownToughness()) >= 4)
			nCount = 2;
	}
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, nCount).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
#define GIANT_AC_TOKEN_NAME				_T("Giant (AC)")
#define GIANT_AC_TOKEN_ID				55155
#define BOAR_C_TOKEN_NAME				_T("Boar (C)")
#define BOAR_C_TOKEN_ID					55156

// Deals the damage to a creature or a player (not to a planeswalker)
static void DealSpellDamage(CCard* pSource, CCard* pCard, CPlayer* pPlayer, int nDamage)
{
	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	if (pPlayer)
		pModifier.ApplyTo(pPlayer);
	else if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
		if (pCreature && pCard->GetCardType().IsCreature())
			pModifier.ApplyTo(pCreature);
	}
}

//____________________________________________________________________________
//
CBlowYourHouseDownCard::CBlowYourHouseDownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blow Your House Down"), CardType::Sorcery, nID)
{
	// Up to three target creatures can't block this turn. Destroy any of them that are Walls.
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("2") RED_MANA_TEXT, Characteristic::Negative,
		&CBlowYourHouseDownCard::BeforeResolution);
	pSpell->GetTargeting()->SetSubjectCount(0, 3);
}

bool CBlowYourHouseDownCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(cards.GetAt(i));
		if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
			continue;
		pCreature->GetCreatureKeyword()->AddCantBlock(TRUE);
		if (CreatureTypeComparer(CREATURE_TYPE(Wall), false)(pCreature))
			DestroyPermanent(pCreature, pAction->GetController());
	}
	return false;
}

//____________________________________________________________________________
//
CCauldronsGiftCard::CCauldronsGiftCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cauldron's Gift"), CardType::Sorcery, nID)
{
	AddSorcery(this, _T("4") BLACK_MANA_TEXT, &CCauldronsGiftCard::BeforeResolution);
}

bool CCauldronsGiftCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	// Adamant - If at least three black mana was spent to cast this spell, mill four cards.
	if (IsAdamantSpell(pAction, CManaPool::Color::Black))
		Mill(pController, 4);

	// You may choose a creature card in your graveyard. If you do, return it to the battlefield with an additional +1/+1
	// counter on it. (the returned creature found comparing the battlefield before and after, as Vivien's Invocation)
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer before;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		before.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Battlefield, MoveType::Others);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!before.HasCard(pCard) && pCard->GetCardType().IsCreature())
		{
			AddPlusCounter(pCard, 1);
			break;
		}
	}
	return true;
}

//____________________________________________________________________________
//
CClaimTheFirstbornCard::CClaimTheFirstbornCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Claim the Firstborn"), CardType::Sorcery, nID)
{
	// Gain control of target creature with mana value 3 or less until end of turn. Untap that creature. It gains haste
	// until end of turn. (as Act of Treason in M10)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::less_equal<int>>(3)),
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);

	cpSpell->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	cpSpell->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);

	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CDanceOfTheManseCard::CDanceOfTheManseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dance of the Manse"), CardType::Sorcery, nID)
	, m_Filter(_T("an artifact or non-Aura enchantment card"), _T("artifact or non-Aura enchantment cards"), new TrueCardComparer)
{
	// Return up to X target artifact and/or non-Aura enchantment cards each with mana value X or less from your graveyard
	// to the battlefield. If X is 6 or more, those permanents are 4/4 creatures in addition to their other types.
	// Partial: the cards are chosen on resolution (they aren't targets), and they don't become 4/4 creatures.
	CGenericSpell* pSpell = AddSorcery(this, WHITE_MANA_TEXT BLUE_MANA_TEXT, &CDanceOfTheManseCard::BeforeResolution);
	pSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
}

bool CDanceOfTheManseCard::BeforeResolution(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX <= 0)
		return true;

	m_Filter.RemoveAllComparers();
	m_Filter.AddComparer(new OrCardComparer(
		new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::GlobalEnchantment, false)));
	m_Filter.AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(nX));

	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 0, nX, &m_Filter, ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CEpicDownfallCard::CEpicDownfallCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Epic Downfall"), CardType::Sorcery, nID)
{
	// Exile target creature with mana value 3 or greater.
	AddMoveSorcery(this, _T("1") BLACK_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::greater_equal<int>>(3)),
		ZoneId::Exile, MoveType::Others);
}

//____________________________________________________________________________
//
CForebodingFruitCard::CForebodingFruitCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Foreboding Fruit"), CardType::Sorcery, nID)
{
	// Target player draws two cards and loses 2 life.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("2") BLACK_MANA_TEXT, &CForebodingFruitCard::BeforeResolution);
	pSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
}

bool CForebodingFruitCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		DrawCards(GetGame(), pPlayer, 2);
		LoseLife(this, pPlayer, 2);
	}

	// Adamant - If at least three black mana was spent to cast this spell, create a Food token.
	if (IsAdamantSpell(pAction, CManaPool::Color::Black))
		CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CForeverYoungCard::CForeverYoungCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Forever Young"), CardType::Sorcery, nID)
{
	// Put any number of target creature cards from your graveyard on top of your library. Draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetSubjectCount(0, 20);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CForeverYoungCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CForeverYoungCard::BeforeResolution(CAbilityAction* pAction)
{
	// (the cards are moved here, so that the draw comes after them)
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard && cards.GetAt(i)->GetOwner() == pController)
			CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pController).ApplyTo(cards.GetAt(i));

	DrawCards(GetGame(), pController, 1);
	return false;
}

//____________________________________________________________________________
//
CGiantOpportunityCard::CGiantOpportunityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Giant Opportunity"), CardType::Sorcery, nID)
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CGiantOpportunityCard::OnModeSelected))
{
	// You may sacrifice two Foods. If you do, create a 7/7 green Giant creature token. Otherwise, create three Food tokens.
	AddSorcery(this, _T("2") GREEN_MANA_TEXT, &CGiantOpportunityCard::BeforeResolution);
}

bool CGiantOpportunityCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nFoods = CCardFilter::GetFilter(_T("Foods"))->CountIncluded(
		pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nFoods < 2)
	{
		CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 3).ApplyTo(pController);
		return true;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Sacrifice two Foods and create a 7/7 Giant");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText = _T("Create three Food tokens");
		entries.push_back(entry);
	}
	m_ModeSelection.AddSelectionRequest(entries, 1, 1, NULL, pController);
	return true;
}

void CGiantOpportunityCard::OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;
		if (it->dwContext == 1)
		{
			ChooseAndMove(GetGame(), pSelectionPlayer, ZoneId::Battlefield, 2, 2, CCardFilter::GetFilter(_T("Foods")),
				ZoneId::Graveyard, MoveType::Sacrifice);
			CTokenCreationModifier(GetGame(), GIANT_AC_TOKEN_NAME, GIANT_AC_TOKEN_ID, 1).ApplyTo(pSelectionPlayer);
		}
		else
			CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 3).ApplyTo(pSelectionPlayer);
	}
}

//____________________________________________________________________________
//
CIrencragFeatCard::CIrencragFeatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Irencrag Feat"), CardType::Sorcery, nID)
{
	// Add seven {R}. You can cast only one more spell this turn.
	// Partial: without the restriction to one more spell.
	AddSorcery(this, _T("1") RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, &CIrencragFeatCard::BeforeResolution);
}

bool CIrencragFeatCard::BeforeResolution(CAbilityAction* pAction)
{
	CManaPoolModifier(CManaPoolModifier::Operation::Add,
		CManaPool::CManaPool(RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT))
		.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CJoustCard::CJoustCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Joust"), CardType::Sorcery, nID)
{
	// Choose target creature you control and target creature you don't control. The creature you control gets +2/+1
	// until end of turn if it's a Knight. Then those creatures fight each other.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJoustCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CJoustCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pYours = NULL;
	CCard* pTheirs = NULL;
	GetDoubleTargets(pAction, pYours, pTheirs);

	if (pYours && CreatureTypeComparer(CREATURE_TYPE(Knight), false)(pYours))
		PumpCreature(pYours, +2, +1);
	if (pYours && pTheirs)
		Fight(pYours, pTheirs);
	return false;
}

//____________________________________________________________________________
//
CMemoryTheftCard::CMemoryTheftCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Memory Theft"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CMemoryTheftCard::OnCardSelected))
	, m_AdventureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CMemoryTheftCard::OnAdventureSelected))
{
	// Target opponent reveals their hand. You choose a nonland card from it. That player discards that card. You may put a
	// card that has an Adventure that player owns from exile into that player's graveyard.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("2") BLACK_MANA_TEXT, &CMemoryTheftCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
}

bool CMemoryTheftCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		if (pCard->GetCardType().IsLand())
			continue;
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (entries.empty())
		AskAdventure(pController, pPlayer);
	else
		m_CardSelection.AddSelectionRequest(entries, 1, 1, NULL, pController, (DWORD)pPlayer);
	return false;
}

void CMemoryTheftCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pPlayer = (CPlayer*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (it->bSelected && pCard->GetZoneId() == ZoneId::Hand)
			CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pPlayer).ApplyTo(pCard);
	}
	AskAdventure(pSelectionPlayer, pPlayer);
}

void CMemoryTheftCard::AskAdventure(CPlayer* pController, CPlayer* pPlayer)
{
	CZone* pExile = pPlayer->GetZoneById(ZoneId::Exile);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pExile->GetSize(); ++i)
	{
		CCard* pCard = pExile->GetAt(i);
		if (!CAdventureSupport::Find(pCard) || pCard->GetOwner() != pPlayer)
			continue;
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s into its owner's graveyard"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_AdventureSelection.AddSelectionRequest(entries, 0, 1, NULL, pController);
}

void CMemoryTheftCard::OnAdventureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (it->bSelected && pCard->GetZoneId() == ZoneId::Exile)
			CMoveCardModifier(ZoneId::Exile, ZoneId::Graveyard, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
	}
}

//____________________________________________________________________________
//
COutmuscleCard::COutmuscleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Outmuscle"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on target creature you control, then it fights target creature you don't control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COutmuscleCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool COutmuscleCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pYours = NULL;
	CCard* pTheirs = NULL;
	GetDoubleTargets(pAction, pYours, pTheirs);
	if (!pYours)
		return false;

	AddPlusCounter(pYours, 1);

	// Adamant - If at least three green mana was spent to cast this spell, the creature you control gains indestructible
	// until end of turn. (before the fight)
	if (IsAdamantSpell(pAction, CManaPool::Color::Green))
		pYours->GetCardKeyword()->AddIndestructible(TRUE);

	if (pTheirs)
		Fight(pYours, pTheirs);
	return false;
}

//____________________________________________________________________________
//
CReaveSoulCard::CReaveSoulCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reave Soul"), CardType::Sorcery, nID)
{
	// Destroy target creature with power 3 or less.
	AddMoveSorcery(this, _T("1") BLACK_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::less_equal<int>>(3)),
		ZoneId::Graveyard, MoveType::Destroy);
}

//____________________________________________________________________________
//
CSilverflameRitualCard::CSilverflameRitualCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Silverflame Ritual"), CardType::Sorcery, nID)
{
	AddSorcery(this, _T("3") WHITE_MANA_TEXT, &CSilverflameRitualCard::BeforeResolution);
}

bool CSilverflameRitualCard::BeforeResolution(CAbilityAction* pAction)
{
	// Put a +1/+1 counter on each creature you control.
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		AddPlusCounter(creatures.GetAt(i), 1);

	// Adamant - If at least three white mana was spent to cast this spell, creatures you control gain vigilance until end
	// of turn.
	if (IsAdamantSpell(pAction, CManaPool::Color::White))
		PumpCreatures(GetGame(), pAction->GetController(), 0, 0, CreatureKeyword::Vigilance);
	return true;
}

//____________________________________________________________________________
//
CSpectersShriekCard::CSpectersShriekCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Specter's Shriek"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CSpectersShriekCard::OnCardSelected))
{
	// Target opponent reveals their hand. You may choose a nonland card from it. If you do, that player exiles that card.
	// If a nonblack card is exiled this way, exile a card from your hand.
	CTargetSpell* pSpell = AddPlayerSorcery(this, BLACK_MANA_TEXT, &CSpectersShriekCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
}

bool CSpectersShriekCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return false;

	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		if (pCard->GetCardType().IsLand())
			continue;
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, 1, NULL, pAction->GetController(), (DWORD)pPlayer);
	return false;
}

void CSpectersShriekCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pPlayer = (CPlayer*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (!it->bSelected || pCard->GetZoneId() != ZoneId::Hand)
			continue;

		BOOL bNonblack = !pCard->IsColor(CManaPool::Color::Black);
		CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pPlayer).ApplyTo(pCard);
		if (bNonblack)
			ChooseAndMove(GetGame(), pSelectionPlayer, ZoneId::Hand, 1, 1, CCardFilter::GetFilter(_T("cards")),
				ZoneId::Exile, MoveType::Others);
	}
}

//____________________________________________________________________________
//
CStolenByTheFaeCard::CStolenByTheFaeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stolen by the Fae"), CardType::Sorcery, nID)
{
	// Return target creature with mana value X to its owner's hand. You create X 1/1 blue Faerie creature tokens with
	// flying. (one variant of the spell for each X from 0 to 10, as Aryel in Dominaria)
	for (int nX = 0; nX <= 10; ++nX)
	{
		CString strCost = MakeCost(nX, BLUE_MANA_TEXT BLUE_MANA_TEXT);
		CTargetMoveCardSpell* pSpell = AddMoveSorcery(this, (LPCTSTR)strCost,
			new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::equal_to<int>>(nX)),
			ZoneId::Hand, MoveType::Others);
		pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStolenByTheFaeCard::BeforeResolution));
	}
}

bool CStolenByTheFaeCard::BeforeResolution(CAbilityAction* pAction)
{
	// X is the mana value of the target (each variant only targets creatures with its X)
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
	{
		int nX = pTarget->GetConvertedManaCost();
		if (nX > 0)
			CTokenCreationModifier(GetGame(), FAERIE_A_TOKEN_NAME, FAERIE_A_TOKEN_ID, nX).ApplyTo(pAction->GetController());
	}
	return true;
}

//____________________________________________________________________________
//
CSunderingStrokeCard::CSunderingStrokeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sundering Stroke"), CardType::Sorcery, nID)
{
	// Sundering Stroke deals 7 damage divided as you choose among one, two, or three targets. (as Forked Bolt)
	// Note: it can't target planeswalkers
	CTargetChgLifeSpell* pSpell = AddDamageSorcery(this, _T("6") RED_MANA_TEXT, 7, new AnyCreatureComparer, TRUE);
	pSpell->GetTargeting()->SetSubjectCount(1, 3);
	pSpell->GetTargeting()->SetDistributeValues();
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSunderingStrokeCard::BeforeResolution));
}

bool CSunderingStrokeCard::BeforeResolution(CAbilityAction* pAction)
{
	// If at least seven red mana was spent to cast this spell, instead Sundering Stroke deals 7 damage to each of those
	// permanents and/or players.
	if (pAction->GetCostConfigEntry().GetManaPool().GetMana(CManaPool::Color::Red) < 7)
		return true;

	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (!pTargetAction)
		return true;

	CCountedCardContainer cards;
	CPlayerContainer players;
	pTargetAction->GetTargetGroup().GetCardSubjects(cards);
	pTargetAction->GetTargetGroup().GetPlayerSubjects(players);
	for (int i = 0; i < cards.GetSize(); ++i)
		DealSpellDamage(this, cards.GetAt(i), NULL, 7);
	for (int i = 0; i < players.GetSize(); ++i)
		DealSpellDamage(this, NULL, players.GetAt(i), 7);
	return false;
}

//____________________________________________________________________________
//
CTasteOfDeathCard::CTasteOfDeathCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Taste of Death"), CardType::Sorcery, nID)
{
	AddSorcery(this, _T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CTasteOfDeathCard::BeforeResolution);
}

bool CTasteOfDeathCard::BeforeResolution(CAbilityAction* pAction)
{
	// Each player sacrifices three creatures of their choice.
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		ChooseAndMove(GetGame(), GetGame()->GetPlayer(ip), ZoneId::Battlefield, 3, 3, CCardFilter::GetFilter(_T("creatures")),
			ZoneId::Graveyard, MoveType::Sacrifice);

	// You create three Food tokens.
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 3).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CUnexplainedVisionCard::CUnexplainedVisionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unexplained Vision"), CardType::Sorcery, nID)
{
	AddSorcery(this, _T("4") BLUE_MANA_TEXT, &CUnexplainedVisionCard::BeforeResolution);
}

bool CUnexplainedVisionCard::BeforeResolution(CAbilityAction* pAction)
{
	// Draw three cards.
	DrawCards(GetGame(), pAction->GetController(), 3);

	// Adamant - If at least three blue mana was spent to cast this spell, scry 3.
	if (IsAdamantSpell(pAction, CManaPool::Color::Blue))
		CScryModifier(GetGame(), 3, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CWitchsVengeanceCard::CWitchsVengeanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Witch's Vengeance"), CardType::Sorcery, nID)
	, m_TypeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CWitchsVengeanceCard::OnTypeSelected))
{
	// Creatures of the creature type of your choice get -3/-3 until end of turn.
	AddSorcery(this, _T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CWitchsVengeanceCard::BeforeResolution);
}

bool CWitchsVengeanceCard::BeforeResolution(CAbilityAction* pAction)
{
	// Only the types of the creatures on the battlefield are offered (as Radiant Destiny); the others have no effect
	std::vector<SelectionEntry> entries;
	for (int i = 1; i < SingleCreatureType::_SingleTypeCount; ++i)
	{
		SingleCreatureType::Enum creatureType = (SingleCreatureType::Enum)i;

		BOOL bAdd = FALSE;
		for (int ip = 0; ip < GetGame()->GetPlayerCount() && !bAdd; ++ip)
		{
			CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
			for (int k = 0; k < pBattlefield->GetSize() && !bAdd; ++k)
			{
				CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(k));
				if (pCreature && pCreature->GetCardType().IsCreature() && pCreature->GetCreatureType().HasType(creatureType))
					bAdd = TRUE;
			}
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
		m_TypeSelection.AddSelectionRequest(entries, 1, 1, NULL, pAction->GetController());
	return true;
}

void CWitchsVengeanceCard::OnTypeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;
		SingleCreatureType::Enum creatureType = (SingleCreatureType::Enum)it->dwContext;

		CCountedCardContainer creatures;
		for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		{
			CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
			for (int k = 0; k < pBattlefield->GetSize(); ++k)
			{
				CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(k));
				if (pCreature && pCreature->GetCardType().IsCreature() && pCreature->GetCreatureType().HasType(creatureType))
					creatures.AddCard(pCreature, CardPlacement::Top);
			}
		}
		for (int k = 0; k < creatures.GetSize(); ++k)
			PumpCreature(creatures.GetAt(k), -3, -3);
	}
}

//____________________________________________________________________________
//
CWolfsQuarryCard::CWolfsQuarryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wolf's Quarry"), CardType::Sorcery, nID)
{
	// Create three 1/1 green Boar creature tokens with "When this token dies, create a Food token."
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT,
			BOAR_C_TOKEN_NAME, BOAR_C_TOKEN_ID, 3));
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
#define HUMAN_A_TOKEN_NAME				_T("Human (A)")
#define HUMAN_A_TOKEN_ID				2948

// Mana value less than or equal to the number of cards in its controller's graveyard (Drown in the Loch)
struct GraveyardManaValueComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		CPlayer* pController = value->GetController();
		return pController &&
			value->GetConvertedManaCost() <= pController->GetZoneById(ZoneId::Graveyard)->GetSize();
	}

	virtual GraveyardManaValueComparer* Clone() const
	{
		return new GraveyardManaValueComparer;
	}
};

static void CreateFood(CCard* pSource, CPlayer* pPlayer, int nCount = 1)
{
	CTokenCreationModifier(pSource->GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, nCount).ApplyTo(pPlayer);
}

//____________________________________________________________________________
//
CBakeIntoAPieCard::CBakeIntoAPieCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bake into a Pie"), CardType::Instant, nID)
{
	// Destroy target creature. Create a Food token.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		new AnyCreatureComparer, ZoneId::Graveyard, MoveType::Destroy);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBakeIntoAPieCard::BeforeResolution));
}

bool CBakeIntoAPieCard::BeforeResolution(CAbilityAction* pAction)
{
	CreateFood(this, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CBanishIntoFableCard::CBanishIntoFableCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Banish into Fable"), CardType::Instant, nID)
{
	// When you cast this spell from your hand, copy it if you control an artifact, then copy it if you control an
	// enchantment. You may choose new targets for the copies.
	// Partial: without the copies.

	// Return target nonland permanent to its owner's hand. You create a 2/2 white Knight creature token with vigilance.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT,
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)), ZoneId::Hand, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBanishIntoFableCard::BeforeResolution));
}

bool CBanishIntoFableCard::BeforeResolution(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CBargeInCard::CBargeInCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Barge In"), CardType::Instant, nID)
{
	// Target attacking creature gets +2/+2 until end of turn. Each attacking non-Human creature gains trample until end of
	// turn.
	CTargetSpell* pSpell = AddCreatureInstant(this, RED_MANA_TEXT, Characteristic::Positive, &CBargeInCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
}

bool CBargeInCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pTarget, +2, +2);

	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (AttackingCreatureComparer()(pCard) && !CreatureTypeComparer(CREATURE_TYPE(Human), false)(pCard))
				creatures.AddCard(pCard, CardPlacement::Top);
		}
	}
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature)
			pCreature->GetCreatureKeyword()->AddTrample(TRUE);
	}
	return false;
}

//____________________________________________________________________________
//
CDidntSayPleaseCard::CDidntSayPleaseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Didn't Say Please"), CardType::Instant, nID)
{
	// Counter target spell. Its controller mills three cards. (as Ionize in Guilds of Ravnica)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDidntSayPleaseCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDidntSayPleaseCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard)
		Mill(pCard->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CDrownInTheLochCard::CDrownInTheLochCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Drown in the Loch"), CardType::Instant, nID)
{
	{
		// Counter target spell with mana value less than or equal to the number of cards in its controller's graveyard.
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				BLUE_MANA_TEXT BLACK_MANA_TEXT,
				new GraveyardManaValueComparer));
		cpSpell->SetAbilityText(_T("Counter target spell with mana value less than or equal to the number of cards in its controller's graveyard"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Destroy target creature with mana value less than or equal to the number of cards in its controller's graveyard.
		CTargetMoveCardSpell* pSpell = AddMoveInstant(this, BLUE_MANA_TEXT BLACK_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer, new GraveyardManaValueComparer),
			ZoneId::Graveyard, MoveType::Destroy);
		pSpell->SetAbilityText(_T("Destroy target creature with mana value less than or equal to the number of cards in its controller's graveyard"));
	}
}

//____________________________________________________________________________
//
CFellThePheasantCard::CFellThePheasantCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fell the Pheasant"), CardType::Instant, nID)
{
	// Fell the Pheasant deals 5 damage to target creature with flying. Create a Food token.
	CTargetChgLifeSpell* pSpell = AddDamageInstant(this, _T("1") GREEN_MANA_TEXT, 5,
		new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Flying, false)), FALSE);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFellThePheasantCard::BeforeResolution));
}

bool CFellThePheasantCard::BeforeResolution(CAbilityAction* pAction)
{
	CreateFood(this, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CFestiveFuneralCard::CFestiveFuneralCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Festive Funeral"), CardType::Instant, nID)
{
	// Target creature gets -X/-X until end of turn, where X is the number of cards in your graveyard.
	AddCreatureInstant(this, _T("4") BLACK_MANA_TEXT, Characteristic::Negative, &CFestiveFuneralCard::BeforeResolution);
}

bool CFestiveFuneralCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	int nX = pAction->GetController()->GetZoneById(ZoneId::Graveyard)->GetSize();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && nX > 0)
		PumpCreature(pTarget, -nX, -nX);
	return false;
}

//____________________________________________________________________________
//
CInsatiableAppetiteCard::CInsatiableAppetiteCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Insatiable Appetite"), CardType::Instant, nID)
{
	// You may sacrifice a Food. If you do, target creature gets +5/+5 until end of turn. Otherwise, that creature gets
	// +3/+3 until end of turn. (the Food is sacrificed as a cost of a second spell)
	AddPumpInstant(this, _T("1") GREEN_MANA_TEXT, +3, +3);

	CTargetChgPwrTghAttrSpell* pFood = AddPumpInstant(this, _T("1") GREEN_MANA_TEXT, +5, +5);
	pFood->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Foods")));
	pFood->SetMainSpell(FALSE);
}

//____________________________________________________________________________
//
CIntoTheStoryCard::CIntoTheStoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Into the Story"), CardType::Instant, nID)
{
	// Draw four cards.
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant, _T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, 4));
		AddSpell(cpSpell.GetPointer());
	}

	// This spell costs {3} less to cast if an opponent has seven or more cards in their graveyard.
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant, _T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, 4));
		cpSpell->SetMainSpell(FALSE);
		AddPlayableIf(this, cpSpell.GetPointer(), &CIntoTheStoryCard::OpponentHasSevenInGraveyard);
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CIntoTheStoryCard::OpponentHasSevenInGraveyard(BOOL bIncludeTricks)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer != GetController() && pPlayer->GetZoneById(ZoneId::Graveyard)->GetSize() >= 7)
			return TRUE;
	}
	return FALSE;
}

//____________________________________________________________________________
//
CLashOfThornsCard::CLashOfThornsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lash of Thorns"), CardType::Instant, nID)
{
	// Target creature gets +2/+1 and gains deathtouch until end of turn.
	AddCreatureInstant(this, BLACK_MANA_TEXT, Characteristic::Positive, &CLashOfThornsCard::BeforeResolution);
}

bool CLashOfThornsCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
	{
		PumpCreature(pTarget, +2, +1);
		pTarget->GetCardKeyword()->AddDeathtouch(TRUE);
	}
	return false;
}

//____________________________________________________________________________
//
CMysticalDisputeCard::CMysticalDisputeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mystical Dispute"), CardType::Instant, nID)
{
	// Counter target spell unless its controller pays {3}. (as Mana Leak)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT,
				new TrueCardComparer));
		cpSpell->SetCanBeDenied();
		cpSpell->GetDenialCost().SetManaCost(_T("3"));
		AddSpell(cpSpell.GetPointer());
	}

	// This spell costs {2} less to cast if it targets a blue spell. (a second spell that can only target blue spells, as
	// Price of Fame)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				BLUE_MANA_TEXT,
				new CardTypeComparer(CardType::Blue, false)));
		cpSpell->SetCanBeDenied();
		cpSpell->GetDenialCost().SetManaCost(_T("3"));
		cpSpell->SetMainSpell(FALSE);
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
//
COkosHospitalityCard::COkosHospitalityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Oko's Hospitality"), CardType::Instant, nID)
{
	AddInstant(this, _T("3") GREEN_MANA_TEXT BLUE_MANA_TEXT, &COkosHospitalityCard::BeforeResolution);
}

bool COkosHospitalityCard::BeforeResolution(CAbilityAction* pAction)
{
	// Creatures you control have base power and toughness 3/3 until end of turn.
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		SetBasePowerToughness(creatures.GetAt(i), 3, 3, TRUE);

	// You may search your library and/or graveyard for a card named Oko, the Trickster, reveal it, and put it into your
	// hand. If you search your library this way, shuffle.
	SearchNamedCardToHand(pAction->GetController(), _T("Oko, the Trickster"));
	return true;
}

//____________________________________________________________________________
//
COnceAndFutureCard::COnceAndFutureCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Once and Future"), CardType::Instant, nID)
{
	// Return target card from your graveyard to your hand. Put up to one other target card from your graveyard on top of
	// your library. Exile Once and Future.
	// Partial: the cards are chosen on resolution (they aren't targets).
	CGenericSpell* pSpell = AddInstant(this, _T("3") GREEN_MANA_TEXT, &COnceAndFutureCard::BeforeResolution);
	pSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
}

bool COnceAndFutureCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Hand, MoveType::Others);

	// Adamant - If at least three green mana was spent to cast this spell, instead return those cards to your hand
	BOOL bAdamant = IsAdamantSpell(pAction, CManaPool::Color::Green);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 1, CCardFilter::GetFilter(_T("cards")),
		bAdamant ? ZoneId::Hand : ZoneId::Library, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
COnceUponATimeCard::COnceUponATimeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Once Upon a Time"), CardType::Instant, nID)
	, m_CreatureLandFilter(_T("a creature or land card"), _T("creature or land cards"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::_Land, false)))
{
	// If this spell is the first spell you've cast this game, you may cast it without paying its mana cost.
	// Partial: it can't be cast without paying its mana cost.
	AddInstant(this, _T("1") GREEN_MANA_TEXT, &COnceUponATimeCard::BeforeResolution);
}

bool COnceUponATimeCard::BeforeResolution(CAbilityAction* pAction)
{
	// Look at the top five cards of your library. You may reveal a creature or land card from among them and put it into
	// your hand. Put the rest on the bottom of your library in a random order. (as Gishath)
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 5,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &m_CreatureLandFilter,
		ZoneId::Hand, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
COutflankCard::COutflankCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Outflank"), CardType::Instant, nID)
{
	// Outflank deals damage to target attacking or blocking creature equal to the number of creatures you control.
	CTargetSpell* pSpell = AddCreatureInstant(this, WHITE_MANA_TEXT, Characteristic::Negative, &COutflankCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingBlockingCreatureComparer);
}

bool COutflankCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		DealDamageToCreature(this, pTarget, CountCreatures(GetGame(), pAction->GetController()));
	return false;
}

//____________________________________________________________________________
//
CRallyForTheThroneCard::CRallyForTheThroneCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rally for the Throne"), CardType::Instant, nID)
{
	AddInstant(this, _T("2") WHITE_MANA_TEXT, &CRallyForTheThroneCard::BeforeResolution);
}

bool CRallyForTheThroneCard::BeforeResolution(CAbilityAction* pAction)
{
	// Create two 1/1 white Human creature tokens.
	CPlayer* pController = pAction->GetController();
	CTokenCreationModifier(GetGame(), HUMAN_A_TOKEN_NAME, HUMAN_A_TOKEN_ID, 2).ApplyTo(pController);

	// Adamant - If at least three white mana was spent to cast this spell, you gain 1 life for each creature you control.
	if (IsAdamantSpell(pAction, CManaPool::Color::White))
		GainLife(this, pController, CountCreatures(GetGame(), pController));
	return true;
}

//____________________________________________________________________________
//
CRedcapMeleeCard::CRedcapMeleeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Redcap Melee"), CardType::Instant, nID)
{
	// Redcap Melee deals 4 damage to target creature or planeswalker. If a nonred permanent is dealt damage this way, you
	// sacrifice a land.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			NewCreatureOrPlaneswalkerComparer(), FALSE));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRedcapMeleeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRedcapMeleeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	BOOL bNonred = !pTarget->IsColor(CManaPool::Color::Red);
	DealDamageToCreatureOrPlaneswalker(this, pTarget, 4);
	if (bNonred)
		ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("lands")),
			ZoneId::Graveyard, MoveType::Sacrifice);
	return false;
}

//____________________________________________________________________________
//
CReturnOfTheWildspeakerCard::CReturnOfTheWildspeakerCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Return of the Wildspeaker"), CardType::Instant, nID)
{
	// Choose one -
	// * Draw cards equal to the greatest power among non-Human creatures you control.
	CGenericSpell* pDraw = AddInstant(this, _T("4") GREEN_MANA_TEXT, &CReturnOfTheWildspeakerCard::BeforeDraw);
	pDraw->SetAbilityText(_T("Draw cards equal to the greatest power among non-Human creatures you control"));

	// * Non-Human creatures you control get +3/+3 until end of turn.
	CGenericSpell* pPump = AddInstant(this, _T("4") GREEN_MANA_TEXT, &CReturnOfTheWildspeakerCard::BeforePump);
	pPump->SetAbilityText(_T("Non-Human creatures you control get +3/+3 until end of turn"));
}

bool CReturnOfTheWildspeakerCard::BeforeDraw(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	int nMax = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature && !CreatureTypeComparer(CREATURE_TYPE(Human), false)(pCreature) && GET_INTEGER(pCreature->GetPower()) > nMax)
			nMax = GET_INTEGER(pCreature->GetPower());
	}
	if (nMax > 0)
		DrawCards(GetGame(), pAction->GetController(), nMax);
	return true;
}

bool CReturnOfTheWildspeakerCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (!CreatureTypeComparer(CREATURE_TYPE(Human), false)(creatures.GetAt(i)))
			PumpCreature(creatures.GetAt(i), +3, +3);
	return true;
}

//____________________________________________________________________________
//
CRunAwayTogetherCard::CRunAwayTogetherCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Run Away Together"), CardType::Instant, nID)
{
	// Choose two target creatures controlled by different players. Return those creatures to their owners' hands.
	// (one creature you control and one you don't, as in a two-player game)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRunAwayTogetherCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRunAwayTogetherCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pYours = NULL;
	CCard* pTheirs = NULL;
	GetDoubleTargets(pAction, pYours, pTheirs);
	if (pYours)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pYours);
	if (pTheirs)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pTheirs);
	return false;
}

//____________________________________________________________________________
//
CScorchingDragonfireCard::CScorchingDragonfireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Scorching Dragonfire"), CardType::Instant, nID)
{
	// Scorching Dragonfire deals 3 damage to target creature or planeswalker. If that creature or planeswalker would die
	// this turn, exile it instead. (as Lava Coil and Necrotic Wound in Guilds of Ravnica)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			NewCreatureOrPlaneswalkerComparer(), FALSE));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CScorchingDragonfireCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CScorchingDragonfireCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CReplacementKeywordModifier pModifier;
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	pModifier.ApplyTo(pTarget);

	DealDamageToCreatureOrPlaneswalker(this, pTarget, 3);
	return false;
}

//____________________________________________________________________________
//
CSearingBarrageCard::CSearingBarrageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Searing Barrage"), CardType::Instant, nID)
{
	// Searing Barrage deals 5 damage to target creature.
	CTargetChgLifeSpell* pSpell = AddDamageInstant(this, _T("4") RED_MANA_TEXT, 5, new AnyCreatureComparer, FALSE);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSearingBarrageCard::BeforeResolution));
}

bool CSearingBarrageCard::BeforeResolution(CAbilityAction* pAction)
{
	// Adamant - If at least three red mana was spent to cast this spell, Searing Barrage deals 3 damage to that creature's
	// controller.
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && IsAdamantSpell(pAction, CManaPool::Color::Red))
		DealDamageToPlayer(this, pTarget->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
CSlayingFireCard::CSlayingFireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Slaying Fire"), CardType::Instant, nID)
{
	// Slaying Fire deals 3 damage to any target.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT,
			NewCreatureOrPlaneswalkerComparer(), TRUE));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSlayingFireCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSlayingFireCard::BeforeResolution(CAbilityAction* pAction)
{
	// Adamant - If at least three red mana was spent to cast this spell, it deals 4 damage instead.
	DealDamageToAnyTarget(this, pAction, IsAdamantSpell(pAction, CManaPool::Color::Red) ? 4 : 3);
	return false;
}

//____________________________________________________________________________
//
CThrillOfPossibilityCard::CThrillOfPossibilityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thrill of Possibility"), CardType::Instant, nID)
{
	// As an additional cost to cast this spell, discard a card. Draw two cards.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Instant, _T("1") RED_MANA_TEXT, 2));
	cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CTrueLovesKissCard::CTrueLovesKissCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("True Love's Kiss"), CardType::Instant, nID)
{
	// Exile target artifact or enchantment. Draw a card.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT,
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)),
		ZoneId::Exile, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTrueLovesKissCard::BeforeResolution));
}

bool CTrueLovesKissCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CTurnIntoAPumpkinCard::CTurnIntoAPumpkinCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Turn into a Pumpkin"), CardType::Instant, nID)
{
	// Return target nonland permanent to its owner's hand. Draw a card.
	CTargetMoveCardSpell* pSpell = AddMoveInstant(this, _T("3") BLUE_MANA_TEXT,
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)), ZoneId::Hand, MoveType::Others);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTurnIntoAPumpkinCard::BeforeResolution));
}

bool CTurnIntoAPumpkinCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);

	// Adamant - If at least three blue mana was spent to cast this spell, create a Food token.
	if (IsAdamantSpell(pAction, CManaPool::Color::Blue))
		CreateFood(this, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
// The player controls a Knight other than pCard
static BOOL ControlsAnotherKnight(CPlayer* pPlayer, const CCard* pCard)
{
	CCountedCardContainer knights;
	GetCreaturesOfType(pPlayer->GetGame(), pPlayer, CREATURE_TYPE(Knight), knights);
	for (int i = 0; i < knights.GetSize(); ++i)
		if (knights.GetAt(i) != pCard)
			return TRUE;
	return FALSE;
}

//____________________________________________________________________________
//
CAcclaimedContenderCard::CAcclaimedContenderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Acclaimed Contender"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(3))
	, m_LookFilter(_T("a Knight, Aura, Equipment, or legendary artifact card"), _T("Knight, Aura, Equipment, or legendary artifact cards"),
		new OrCardComparer(
			new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false), new CardTypeComparer(CardType::_Aura, false)),
			new OrCardComparer(new CardTypeComparer(CardType::Equipment, false),
				new AndCardComparer(new CardTypeComparer(CardType::Legendary, false), new CardTypeComparer(CardType::Artifact, false)))))
{
	// When this creature enters, if you control another Knight, look at the top five cards of your library. You may reveal
	// a Knight, Aura, Equipment, or legendary artifact card from among them and put it into your hand. Put the rest on the
	// bottom of your library in a random order.
	AddEnterIfTrigger(this, &CAcclaimedContenderCard::SetEnterContext, &CAcclaimedContenderCard::BeforeLook);
}

bool CAcclaimedContenderCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return ControlsAnotherKnight(GetController(), this) == TRUE;
}

bool CAcclaimedContenderCard::BeforeLook(CAbilityAction* pAction)
{
	if (!ControlsAnotherKnight(pAction->GetController(), this))
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 5,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &m_LookFilter,
		ZoneId::Hand, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CArchonOfAbsolutionCard::CArchonOfAbsolutionCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Archon of Absolution"), CardType::Creature, CREATURE_TYPE(Archon), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Protection from white
	GetCardKeyword()->AddProtection(CardKeyword::ProtectionFromWhite, FALSE);

	// Creatures can't attack you or planeswalkers you control unless their controller pays {1} for each of those
	// creatures. (as Ghostly Prison and Baird, Steward of Argive)
	counted_ptr<CConsAttackExtraManaEnchantment> cpAbility(
		::CreateObject<CConsAttackExtraManaEnchantment>(this,
			new AnyCreatureComparer,
			_T("1")));

	cpAbility->SetAffectOpponentCardsOnly();
	cpAbility->SetAffectOnlyPlayerDeclaration();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CArdenvalePaladinCard::CArdenvalePaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ardenvale Paladin"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(5))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CArdenvalePaladinCard::OnZoneChanged))
{
	// Adamant - If at least three white mana was spent to cast this spell, this creature enters with a +1/+1 counter on it.
	// (a listener of its zone changes, as AEther Figment in Zendikar)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CArdenvalePaladinCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		IsAdamantPermanent(this, CManaPool::Color::White))
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
}

//____________________________________________________________________________
//
CArdenvaleTacticianCard::CArdenvaleTacticianCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Ardenvale Tactician"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Adventure(this)
{
	// Dizzying Swoop {1}{W}, Instant - Adventure: Tap up to two target creatures.
	counted_ptr<CTargetSpell> cpSwoop(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));
	cpSwoop->GetTargeting()->SetSubjectCount(0, 2);
	cpSwoop->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSwoop->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArdenvaleTacticianCard::BeforeSwoop));
	m_Adventure.SetAdventureSpell(cpSwoop.GetPointer(), _T("Dizzying Swoop"));
	AddSpell(cpSwoop.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT);
}

bool CArdenvaleTacticianCard::BeforeSwoop(CAbilityAction* pAction)
{
	CCountedCardContainer cards;
	GetCardTargets(pAction, cards);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			CCardOrientationModifier(TRUE).ApplyTo(cards.GetAt(i));
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CBarteredCowCard::CBarteredCowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bartered Cow"), CardType::Creature, CREATURE_TYPE(Ox), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature dies ... create a Food token.
	AddDiesTrigger(this, &CBarteredCowCard::BeforeFood);

	// ... and when you discard this card, create a Food token. (a trigger of the card in the graveyard, as Unconventional
	// Tactics in Hour of Devastation)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Hand, ZoneId::Graveyard, FALSE, TRUE, FALSE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBarteredCowCard::SetDiscardContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBarteredCowCard::BeforeFood));
	AddAbility(cpAbility.GetPointer());
}

bool CBarteredCowCard::SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard == this && moveType == MoveType::Discard;
}

bool CBarteredCowCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CBelovedPrincessCard::CBelovedPrincessCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Beloved Princess"), CardType::Creature, CREATURE_TYPE2(Human, Noble), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
	, m_BlockerFilter(_T("a creature with power 2 or less"), _T("creatures with power 2 or less"),
		new CreaturePowerComparer<std::less_equal<int>>(2))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// This creature can't be blocked by creatures with power 3 or greater. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

//____________________________________________________________________________
//
CCharmingPrinceCard::CCharmingPrinceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charming Prince"), CardType::Creature, CREATURE_TYPE2(Human, Noble), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CCharmingPrinceCard::OnSelected))
{
	// When this creature enters, choose one - Scry 2; You gain 3 life; Exile another target creature you own. Return it to
	// the battlefield under your control at the beginning of the next end step.
	// Partial: the mode and the creature are chosen on resolution (the creature isn't a target).
	AddEnterTrigger(this, &CCharmingPrinceCard::BeforeChoose);
}

void CCharmingPrinceCard::GetOtherOwnedCreatures(CPlayer* pController, CCountedCardContainer& creatures)
{
	CCountedCardContainer all;
	GetCreatures(GetGame(), pController, TRUE, all);
	for (int i = 0; i < all.GetSize(); ++i)
		if (all.GetAt(i) != this && all.GetAt(i)->GetOwner() == pController)
			creatures.AddCard(all.GetAt(i), CardPlacement::Top);
}

bool CCharmingPrinceCard::BeforeChoose(CAbilityAction* pAction)
{
	static LPCTSTR modes[] = { _T("Scry 2"), _T("You gain 3 life"), _T("Exile another creature you own and return it at the next end step") };

	CCountedCardContainer creatures;
	GetOtherOwnedCreatures(pAction->GetController(), creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && creatures.GetSize() == 0)
			continue;
		SelectionEntry entry;
		entry.dwContext = (DWORD)i;
		entry.strText = modes[i];
		entries.push_back(entry);
	}
	m_Selection.AddSelectionRequest(entries, 1, 1, NULL, pAction->GetController(), 0);
	return true;
}

void CCharmingPrinceCard::OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		if (dwContext1 == 0)
		{
			// The mode
			if (it->dwContext == 0)
				CScryModifier(GetGame(), 2, this).ApplyTo(pSelectionPlayer);
			else if (it->dwContext == 1)
				GainLife(this, pSelectionPlayer, 3);
			else
			{
				CCountedCardContainer creatures;
				GetOtherOwnedCreatures(pSelectionPlayer, creatures);
				std::vector<SelectionEntry> entries;
				for (int i = 0; i < creatures.GetSize(); ++i)
				{
					SelectionEntry entry;
					entry.dwContext = (DWORD)creatures.GetAt(i);
					entry.cpAssociatedCard = creatures.GetAt(i);
					entry.strText.Format(_T("Exile %s"), creatures.GetAt(i)->GetCardName(TRUE));
					entries.push_back(entry);
				}
				if (!entries.empty())
					m_Selection.AddSelectionRequest(entries, 1, 1, NULL, pSelectionPlayer, 1);
			}
		}
		else
		{
			// The creature: exile it and return it at the beginning of the next end step (as Nezahal, Primal Tide)
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Battlefield)
				continue;
			CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
			if (pCard->GetZoneId() != ZoneId::Exile)
				continue;

			CMoveCardModifier* pReturn = new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others);
			CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(), pReturn,
				TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
			pModifier.ApplyTo(pCard);
		}
	}
}

//____________________________________________________________________________
//
CFaerieGuidemotherCard::CFaerieGuidemotherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Faerie Guidemother"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
	, m_Adventure(this)
{
	// Gift of the Fae {1}{W}, Sorcery - Adventure: Target creature gets +2/+1 and gains flying until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpGift(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT,
			Power(+2), Life(+1),
			CreatureKeyword::Flying, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));
	cpGift->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	m_Adventure.SetAdventureSpell(cpGift.GetPointer(), _T("Gift of the Fae"));
	AddSpell(cpGift.GetPointer());

	m_Adventure.AddCastFromExileSpell(WHITE_MANA_TEXT);
}

//____________________________________________________________________________
//
CFlutterfoxCard::CFlutterfoxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Flutterfox"), CardType::Creature, CREATURE_TYPE(Fox), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// As long as you control an artifact or enchantment, this creature has flying. (as Garrison Sergeant)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::Flying));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CGarrisonGriffinCard::CGarrisonGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Garrison Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, target Knight you control gains flying until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CGarrisonGriffinCard::BeforeFlying, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CGarrisonGriffinCard::BeforeFlying(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		pCreature->GetCreatureKeyword()->AddFlying(TRUE);
	return false;
}

//____________________________________________________________________________
//
CGiantKillerCard::CGiantKillerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Giant Killer"), CardType::Creature, CREATURE_TYPE2(Human, Peasant), nID,
		WHITE_MANA_TEXT, Power(1), Life(2))
	, m_Adventure(this)
{
	{
		// {1}{W}, {T}: Tap target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));
		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		AddAbility(cpAbility.GetPointer());
	}

	// Chop Down {2}{W}, Instant - Adventure: Destroy target creature with power 4 or greater.
	counted_ptr<CTargetMoveCardSpell> cpChop(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::greater_equal<int>>(4)),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	cpChop->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_Adventure.SetAdventureSpell(cpChop.GetPointer(), _T("Chop Down"));
	AddSpell(cpChop.GetPointer());

	m_Adventure.AddCastFromExileSpell(WHITE_MANA_TEXT);
}

//____________________________________________________________________________
//
CHushbringerCard::CHushbringerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Hushbringer"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(2))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// Creatures entering or dying don't cause abilities to trigger.
	// Not implemented: the engine can't stop the triggers (there's no Torpor Orb).
}

//____________________________________________________________________________
//
CKenrithTheReturnedKingCard::CKenrithTheReturnedKingCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kenrith, the Returned King"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Noble), nID,
		_T("4") WHITE_MANA_TEXT, Power(5), Life(5))
{
	{
		// {R}: All creatures gain trample and haste until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, RED_MANA_TEXT));
		cpAbility->SetAbilityText(_T("All creatures gain trample and haste until end of turn. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKenrithTheReturnedKingCard::BeforeHaste));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{G}: Put a +1/+1 counter on target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{W}: Target player gains 5 life.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") WHITE_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKenrithTheReturnedKingCard::BeforeLife));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{U}: Target player draws a card.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("3") BLUE_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKenrithTheReturnedKingCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{B}: Put target creature card from a graveyard onto the battlefield under its owner's control.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("4") BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKenrithTheReturnedKingCard::BeforeHaste(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		GetCreatures(GetGame(), GetGame()->GetPlayer(ip), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(creatures.GetAt(i));
		if (pCreature)
		{
			pCreature->GetCreatureKeyword()->AddTrample(TRUE);
			pCreature->GetCreatureKeyword()->AddHaste(TRUE);
		}
	}
	return true;
}

bool CKenrithTheReturnedKingCard::BeforeLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetAssociatedPlayer(), 5);
	return false;
}

bool CKenrithTheReturnedKingCard::BeforeDraw(CAbilityAction* pAction)
{
	if (pAction->GetAssociatedPlayer())
		DrawCards(GetGame(), pAction->GetAssociatedPlayer(), 1);
	return false;
}

//____________________________________________________________________________
//
CKnightOfTheKeepCard::CKnightOfTheKeepCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of the Keep"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
}

//____________________________________________________________________________
//
CLindenTheSteadfastQueenCard::CLindenTheSteadfastQueenCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Linden, the Steadfast Queen"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Noble), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Whenever a white creature you control attacks, you gain 1 life.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLindenTheSteadfastQueenCard::SetAttackContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLindenTheSteadfastQueenCard::BeforeLife));
	AddAbility(cpAbility.GetPointer());
}

bool CLindenTheSteadfastQueenCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attackSubject) const
{
	return pCreature && pCreature->GetController() == GetController() && pCreature->IsColor(CManaPool::Color::White);
}

bool CLindenTheSteadfastQueenCard::BeforeLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CLonesomeUnicornCard::CLonesomeUnicornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lonesome Unicorn"), CardType::Creature, CREATURE_TYPE(Unicorn), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
	, m_Adventure(this)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Rider in Need {2}{W}, Sorcery - Adventure: Create a 2/2 white Knight creature token with vigilance.
	counted_ptr<CTokenProductionSpell> cpRider(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("2") WHITE_MANA_TEXT,
			KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, 1));
	m_Adventure.SetAdventureSpell(cpRider.GetPointer(), _T("Rider in Need"));
	AddSpell(cpRider.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("4") WHITE_MANA_TEXT);
}

//____________________________________________________________________________
//
CMysteriousPathlighterCard::CMysteriousPathlighterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Mysterious Pathlighter"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Each creature you control that has an Adventure enters with an additional +1/+1 counter on it.
	// (the counter is put when it enters, in the context function, without a trigger)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMysteriousPathlighterCard::SetEnterContext));
	AddAbility(cpAbility.GetPointer());
}

bool CMysteriousPathlighterCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (pCard && pCard->GetCardType().IsCreature() && CAdventureSupport::Find(pCard))
		AddPlusCounter(pCard, 1);
	return false;
}

//____________________________________________________________________________
//
CPrizedGriffinCard::CPrizedGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Prized Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
}

//____________________________________________________________________________
//
CRealmCloakedGiantCard::CRealmCloakedGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Realm-Cloaked Giant"), CardType::Creature, CREATURE_TYPE(Giant), nID,
		_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(7), Life(7))
	, m_Adventure(this)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Cast Off {3}{W}{W}, Sorcery - Adventure: Destroy all non-Giant creatures.
	counted_ptr<CGenericSpell> cpCastOff(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT));
	cpCastOff->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRealmCloakedGiantCard::BeforeCastOff));
	m_Adventure.SetAdventureSpell(cpCastOff.GetPointer(), _T("Cast Off"));
	AddSpell(cpCastOff.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT);
}

bool CRealmCloakedGiantCard::BeforeCastOff(CAbilityAction* pAction)
{
	DestroyAll(GetGame(), AndCardComparer(new AnyCreatureComparer,
		new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Giant), false))));
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CShepherdOfTheFlockCard::CShepherdOfTheFlockCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shepherd of the Flock"), CardType::Creature, CREATURE_TYPE2(Human, Peasant), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_Adventure(this)
{
	// Usher to Safety {W}, Instant - Adventure: Return target permanent you control to its owner's hand.
	counted_ptr<CTargetMoveCardSpell> cpUsher(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT,
			new TrueCardComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));
	cpUsher->GetTargeting()->SetIncludeControllerCardsOnly();
	cpUsher->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	m_Adventure.SetAdventureSpell(cpUsher.GetPointer(), _T("Usher to Safety"));
	AddSpell(cpUsher.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") WHITE_MANA_TEXT);
}

//____________________________________________________________________________
//
CSilverflameSquireCard::CSilverflameSquireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Silverflame Squire"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Adventure(this)
{
	// On Alert {2}{W}, Instant - Adventure: Target creature gets +2/+2 until end of turn. Untap it.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpOnAlert(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			Power(+2), Life(+2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));
	cpOnAlert->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpOnAlert->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
	m_Adventure.SetAdventureSpell(cpOnAlert.GetPointer(), _T("On Alert"));
	AddSpell(cpOnAlert.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") WHITE_MANA_TEXT);
}

//____________________________________________________________________________
//
CSilverwingSquadronCard::CSilverwingSquadronCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Silverwing Squadron"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("5") WHITE_MANA_TEXT, Power(0), Life(0))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Silverwing Squadron's power and toughness are each equal to the number of creatures you control.
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, ZoneId::Battlefield, new AnyCreatureComparer));
	AddAbility(cpAbility.GetPointer());

	// Whenever this creature attacks, create a number of 2/2 white Knight creature tokens with vigilance equal to the
	// number of opponents you have.
	AddSelfAttackTrigger(this, &CSilverwingSquadronCard::BeforeKnights);
}

bool CSilverwingSquadronCard::BeforeKnights(CAbilityAction* pAction)
{
	int nOpponents = GetGame()->GetPlayerCount() - 1;
	if (nOpponents > 0)
		CTokenCreationModifier(GetGame(), KNIGHT_E_TOKEN_NAME, KNIGHT_E_TOKEN_ID, nOpponents).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CSyrAlinTheLionsClawCard::CSyrAlinTheLionsClawCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syr Alin, the Lion's Claw"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Whenever Syr Alin attacks, other creatures you control get +1/+1 until end of turn.
	AddSelfAttackTrigger(this, &CSyrAlinTheLionsClawCard::BeforePump);
}

bool CSyrAlinTheLionsClawCard::BeforePump(CAbilityAction* pAction)
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
CVenerableKnightCard::CVenerableKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Venerable Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT, Power(2), Life(1))
{
	// When this creature dies, put a +1/+1 counter on target Knight you control.
	CTargeting* pTargeting = AddDiesTargetTrigger(this, &CVenerableKnightCard::BeforeCounter, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CVenerableKnightCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pTarget, 1);
	return false;
}

//____________________________________________________________________________
//
CWorthyKnightCard::CWorthyKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Worthy Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast a Knight spell, create a 1/1 white Human creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWorthyKnightCard::BeforeHuman));
	AddAbility(cpAbility.GetPointer());
}

bool CWorthyKnightCard::BeforeHuman(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), HUMAN_A_TOKEN_NAME, HUMAN_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
#define BEAR_A_TOKEN_NAME				_T("Bear (A)")
#define BEAR_A_TOKEN_ID					2830

// "Whenever you cast a creature spell that has an Adventure" (it doesn't need to have gone on the adventure first): the
// spell is a creature card with an Adventure, cast as the creature (not as its Adventure, the spell on top of the stack)
static BOOL IsAdventureCreatureSpell(CGame* pGame, const CCard* pCard)
{
	if (!pCard || !pCard->GetCardType().IsCreature() || !CAdventureSupport::Find(pCard))
		return FALSE;
	const CStackAbilityAction* pTop = pGame->GetStack().GetTopAction();
	if (pTop && CAdventureSupport::IsAdventureSpell(pTop->GetAbility()))
		return FALSE;
	return TRUE;
}

// The player controls a non-Human creature other than pCard
static BOOL ControlsAnotherNonHuman(CPlayer* pPlayer, const CCard* pCard)
{
	CCountedCardContainer creatures;
	GetCreatures(pPlayer->GetGame(), pPlayer, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != pCard && !CreatureTypeComparer(CREATURE_TYPE(Human), false)(creatures.GetAt(i)))
			return TRUE;
	return FALSE;
}

// The controller of the creature doesn't control a 1/1 creature (Lovestruck Beast)
struct NoOneOneCreatureComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		CPlayer* pController = value->GetController();
		if (!pController)
			return false;
		CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() &&
				CreaturePowerComparer<std::equal_to<int>>(1)(pCard) && CreatureToughnessComparer<std::equal_to<int>>(1)(pCard))
				return false;
		}
		return true;
	}

	virtual NoOneOneCreatureComparer* Clone() const
	{
		return new NoOneOneCreatureComparer;
	}
};

//____________________________________________________________________________
//
CBeanstalkGiantCard::CBeanstalkGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Beanstalk Giant"), CardType::Creature, CREATURE_TYPE(Giant), nID,
		_T("6") GREEN_MANA_TEXT, Power(0), Life(0))
	, m_Adventure(this)
{
	// Beanstalk Giant's power and toughness are each equal to the number of lands you control.
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, ZoneId::Battlefield,
			new CardTypeComparer(CardType::_Land, false)));
	AddAbility(cpAbility.GetPointer());

	// Fertile Footsteps {2}{G}, Sorcery - Adventure: Search your library for a basic land card, put it onto the
	// battlefield, then shuffle.
	counted_ptr<CGenericSpell> cpFootsteps(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("2") GREEN_MANA_TEXT));
	cpFootsteps->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBeanstalkGiantCard::BeforeFootsteps));
	m_Adventure.SetAdventureSpell(cpFootsteps.GetPointer(), _T("Fertile Footsteps"));
	AddSpell(cpFootsteps.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("6") GREEN_MANA_TEXT);
}

bool CBeanstalkGiantCard::BeforeFootsteps(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("basic lands")), FALSE);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CBramblefortFinkCard::CBramblefortFinkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bramblefort Fink"), CardType::Creature, CREATURE_TYPE(Ouphe), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {8}: This creature has base power and toughness 10/10 until end of turn. Activate only if you control an Oko
	// planeswalker.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("8")));
	cpAbility->SetAbilityText(_T("This creature has base power and toughness 10/10 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBramblefortFinkCard::BeforeBase));
	AddPlayableIf(this, cpAbility.GetPointer(), &CBramblefortFinkCard::ControlsOko);
	AddAbility(cpAbility.GetPointer());
}

BOOL CBramblefortFinkCard::ControlsOko(BOOL bIncludeTricks)
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (PlaneswalkerTypeComparer(PlaneswalkerType::Oko)(pBattlefield->GetAt(i)))
			return TRUE;
	return FALSE;
}

bool CBramblefortFinkCard::BeforeBase(CAbilityAction* pAction)
{
	SetBasePowerToughness(this, 10, 10, TRUE);
	return true;
}

//____________________________________________________________________________
//
CCuriousPairCard::CCuriousPairCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Curious Pair"), CardType::Creature, CREATURE_TYPE2(Human, Peasant), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3))
	, m_Adventure(this)
{
	// Treats to Share {G}, Sorcery - Adventure: Create a Food token.
	counted_ptr<CTokenProductionSpell> cpTreats(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT,
			FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1));
	m_Adventure.SetAdventureSpell(cpTreats.GetPointer(), _T("Treats to Share"));
	AddSpell(cpTreats.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") GREEN_MANA_TEXT);
}

//____________________________________________________________________________
//
CEdgewallInnkeeperCard::CEdgewallInnkeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Edgewall Innkeeper"), CardType::Creature, CREATURE_TYPE2(Human, Peasant), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever you cast a creature spell that has an Adventure, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEdgewallInnkeeperCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEdgewallInnkeeperCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CEdgewallInnkeeperCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return IsAdventureCreatureSpell(GetGame(), pCard) == TRUE;
}

bool CEdgewallInnkeeperCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CFeastingTrollKingCard::CFeastingTrollKingCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Feasting Troll King"), CardType::Creature, CREATURE_TYPE2(Troll, Noble), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(6))
{
	// Vigilance, trample
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, if you cast it from your hand, create three Food tokens.
	// (the creature spells can only be cast from the hand, so it checks that it was cast)
	AddEnterIfTrigger(this, &CFeastingTrollKingCard::SetEnterContext, &CFeastingTrollKingCard::BeforeFood);

	// Sacrifice three Foods: Return this card from your graveyard to the battlefield. Activate only during your turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
	cpAbility->GetCost().AddSacrificeCardCost(3, CCardFilter::GetFilter(_T("Foods")));
	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to the battlefield. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFeastingTrollKingCard::BeforeReturn));
	AddPlayableIf(this, cpAbility.GetPointer(), &CFeastingTrollKingCard::IsYourTurn);
	AddAbility(cpAbility.GetPointer());
}

bool CFeastingTrollKingCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Cast;
}

bool CFeastingTrollKingCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 3).ApplyTo(pAction->GetController());
	return true;
}

BOOL CFeastingTrollKingCard::IsYourTurn(BOOL bIncludeTricks)
{
	return GetGame()->GetActivePlayer() == GetController();
}

bool CFeastingTrollKingCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CFierceWitchstalkerCard::CFierceWitchstalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fierce Witchstalker"), CardType::Creature, CREATURE_TYPE(Wolf), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, create a Food token.
	AddEnterTrigger(this, &CFierceWitchstalkerCard::BeforeFood);
}

bool CFierceWitchstalkerCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CFlaxenIntruderCard::CFlaxenIntruderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Flaxen Intruder"), CardType::Creature, CREATURE_TYPE2(Human, Berserker), nID,
		GREEN_MANA_TEXT, Power(1), Life(2))
	, m_Adventure(this)
{
	// Whenever this creature deals combat damage to a player, you may sacrifice it. When you do, destroy target artifact
	// or enchantment.
	// Partial: the target is chosen when it triggers.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
								 CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFlaxenIntruderCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());

	// Welcome Home {5}{G}{G}, Sorcery - Adventure: Create three 2/2 green Bear creature tokens.
	counted_ptr<CTokenProductionSpell> cpWelcome(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT,
			BEAR_A_TOKEN_NAME, BEAR_A_TOKEN_ID, 3));
	m_Adventure.SetAdventureSpell(cpWelcome.GetPointer(), _T("Welcome Home"));
	AddSpell(cpWelcome.GetPointer());

	m_Adventure.AddCastFromExileSpell(GREEN_MANA_TEXT);
}

bool CFlaxenIntruderCard::BeforeDestroy(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return false;

	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pAction->GetController()).ApplyTo(this);

	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		DestroyPermanent(pTarget, pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
CGarenbrigCarverCard::CGarenbrigCarverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Garenbrig Carver"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_Adventure(this)
{
	// Shield's Might {1}{G}, Instant - Adventure: Target creature gets +2/+2 until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpMight(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			Power(+2), Life(+2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));
	cpMight->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	m_Adventure.SetAdventureSpell(cpMight.GetPointer(), _T("Shield's Might"));
	AddSpell(cpMight.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("3") GREEN_MANA_TEXT);
}

//____________________________________________________________________________
//
CGarenbrigPaladinCard::CGarenbrigPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Garenbrig Paladin"), CardType::Creature, CREATURE_TYPE2(Giant, Knight), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CGarenbrigPaladinCard::OnZoneChanged))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// Adamant - If at least three green mana was spent to cast this spell, this creature enters with a +1/+1 counter on it.
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// This creature can't be blocked by creatures with power 2 or less. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

void CGarenbrigPaladinCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		IsAdamantPermanent(this, CManaPool::Color::Green))
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
}

//____________________________________________________________________________
//
CGarenbrigSquireCard::CGarenbrigSquireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Garenbrig Squire"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast a creature spell that has an Adventure, this creature gets +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGarenbrigSquireCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGarenbrigSquireCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CGarenbrigSquireCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return IsAdventureCreatureSpell(GetGame(), pCard) == TRUE;
}

bool CGarenbrigSquireCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

//____________________________________________________________________________
//
CGildedGooseCard::CGildedGooseCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Gilded Goose"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		GREEN_MANA_TEXT, Power(0), Life(2))
{
	// When this creature enters, create a Food token.
	AddEnterTrigger(this, &CGildedGooseCard::BeforeFood);

	{
		// {1}{G}, {T}: Create a Food token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("1") GREEN_MANA_TEXT,
				FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	// {T}, Sacrifice a Food: Add one mana of any color.
	LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, mana[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Foods")));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGildedGooseCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CKeeperOfFablesCard::CKeeperOfFablesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Keeper of Fables"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(5))
	, m_nTurn(-1)
{
	// Whenever one or more non-Human creatures you control deal combat damage to a player, draw a card.
	// (as Admiral Beckett Brass; only the first time each turn, as Storm the Vault)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
						   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
	cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
	cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKeeperOfFablesCard::SetDamageContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKeeperOfFablesCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CKeeperOfFablesCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	if (!pFromCard || !pFromCard->GetCardType().IsCreature() || m_nTurn == GetGame()->GetGameTurnNumber())
		return false;
	m_nTurn = GetGame()->GetGameTurnNumber();
	return true;
}

bool CKeeperOfFablesCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CLovestruckBeastCard::CLovestruckBeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lovestruck Beast"), CardType::Creature, CREATURE_TYPE2(Beast, Noble), nID,
		_T("2") GREEN_MANA_TEXT, Power(5), Life(5))
	, m_Adventure(this)
{
	// This creature can't attack unless you control a 1/1 creature. (as Novice Knight: pending to test that it's updated
	// when a 1/1 creature enters or leaves)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this), new NoOneOneCreatureComparer),
			Power(+0), Life(+0), CreatureKeyword::CantAttack));
	AddAbility(cpAbility.GetPointer());

	// Heart's Desire {G}, Sorcery - Adventure: Create a 1/1 white Human creature token.
	counted_ptr<CTokenProductionSpell> cpDesire(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT,
			HUMAN_A_TOKEN_NAME, HUMAN_A_TOKEN_ID, 1));
	m_Adventure.SetAdventureSpell(cpDesire.GetPointer(), _T("Heart's Desire"));
	AddSpell(cpDesire.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("2") GREEN_MANA_TEXT);
}

//____________________________________________________________________________
//
COakhameAdversaryCard::COakhameAdversaryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oakhame Adversary"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// This spell costs {2} less to cast if an opponent controls a green permanent. (as Academy Journeymage)
	AddPlayableIf(this, GetSpells().GetAt(0), &COakhameAdversaryCard::NoOpponentControlsGreen);
	{
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("1") GREEN_MANA_TEXT, TRUE));
		cpSpell->SetMainSpell(FALSE);
		AddPlayableIf(this, cpSpell.GetPointer(), &COakhameAdversaryCard::OpponentControlsGreen);
		AddSpell(cpSpell.GetPointer());
	}

	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Whenever this creature deals combat damage to a player, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COakhameAdversaryCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

BOOL COakhameAdversaryCard::OpponentControlsGreen(BOOL bIncludeTricks)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == GetController())
			continue;
		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->IsColor(CManaPool::Color::Green))
				return TRUE;
	}
	return FALSE;
}

bool COakhameAdversaryCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CQuestingBeastCard::CQuestingBeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Questing Beast"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Beast), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_BlockerFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
	, m_nDamage(0)
{
	// Vigilance, deathtouch, haste
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Questing Beast can't be blocked by creatures with power 2 or less.
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);

	// Combat damage that would be dealt by creatures you control can't be prevented.
	// Not implemented: the engine has no effect for it.

	// Whenever Questing Beast deals combat damage to an opponent, it deals that much damage to target planeswalker that
	// player controls. (the planeswalker loses loyalty; the damage remembered in the context function)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
								 CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Planeswalker, false));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CQuestingBeastCard::SetDamageContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CQuestingBeastCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CQuestingBeastCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	if (!pPlayer || pPlayer == GetController())
		return false;
	m_nDamage = -(int)damage.m_nLifeDelta;
	return m_nDamage > 0;
}

bool CQuestingBeastCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && m_nDamage > 0)
		DealDamageToCreatureOrPlaneswalker(this, pTarget, m_nDamage);
	return false;
}

//____________________________________________________________________________
//
CRosethornAcolyteCard::CRosethornAcolyteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rosethorn Acolyte"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
	, m_Adventure(this)
	, m_ColorSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRosethornAcolyteCard::OnColorSelected))
{
	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);

	// Seasonal Ritual {G}, Sorcery - Adventure: Add one mana of any color.
	counted_ptr<CGenericSpell> cpRitual(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, GREEN_MANA_TEXT));
	cpRitual->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRosethornAcolyteCard::BeforeRitual));
	m_Adventure.SetAdventureSpell(cpRitual.GetPointer(), _T("Seasonal Ritual"));
	AddSpell(cpRitual.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("2") GREEN_MANA_TEXT);
}

bool CRosethornAcolyteCard::BeforeRitual(CAbilityAction* pAction)
{
	static LPCTSTR names[] = { _T("white"), _T("blue"), _T("black"), _T("red"), _T("green") };

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 5; ++i)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)i;
		entry.strText.Format(_T("Add one %s mana"), names[i]);
		entries.push_back(entry);
	}
	m_ColorSelection.AddSelectionRequest(entries, 1, 1, NULL, pAction->GetController());
	return true;	// (the Adventure must resolve to go to exile)
}

void CRosethornAcolyteCard::OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	static LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext < 5)
			CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(mana[it->dwContext])).ApplyTo(pSelectionPlayer);
}

//____________________________________________________________________________
//
CSteelbaneHydraCard::CSteelbaneHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steelbane Hydra"), CardType::Creature, CREATURE_TYPE2(Turtle, Hydra), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CSteelbaneHydraCard::OnZoneChanged))
	, m_nX(0)
{
	// {X}{G}{G}. This creature enters with X +1/+1 counters on it.
	// (creature spell with {X} as Hydroid Krasis in Ravnica Allegiance: the main spell can't be cast, the X spell
	// remembers X when it resolves and the creature gets the counters when it enters)
	AddPlayableIf(this, GetSpells().GetAt(0), &CSteelbaneHydraCard::Never);

	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Creature, GREEN_MANA_TEXT GREEN_MANA_TEXT));
	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSteelbaneHydraCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// {2}{G}, Remove a +1/+1 counter from this creature: Destroy target artifact or enchantment.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2") GREEN_MANA_TEXT,
			new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("+1/+1")), -1);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

bool CSteelbaneHydraCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	return true;
}

void CSteelbaneHydraCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
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
CSyrFarenTheHengehammerCard::CSyrFarenTheHengehammerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syr Faren, the Hengehammer"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Whenever Syr Faren attacks, another target attacking creature gets +X/+X until end of turn, where X is Syr Faren's
	// power.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CSyrFarenTheHengehammerCard::BeforePump, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CSyrFarenTheHengehammerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	int nX = GET_INTEGER(GetZoneId() == ZoneId::Battlefield ? GetPower() : GetLastKnownPower());
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && nX > 0)
		PumpCreature(pTarget, nX, nX);
	return false;
}

//____________________________________________________________________________
//
CThornMammothCard::CThornMammothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thorn Mammoth"), CardType::Creature, CREATURE_TYPE(Elephant), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever this creature or another creature you control enters, this creature fights up to one target creature you
	// don't control. (as Forerunner of the Legion)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetSubjectCount(0, 1);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThornMammothCard::BeforeFight));
	AddAbility(cpAbility.GetPointer());
}

bool CThornMammothCard::BeforeFight(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && GetZoneId() == ZoneId::Battlefield)
		Fight(this, pTarget);
	return false;
}

//____________________________________________________________________________
//
CTuinvaleTreefolkCard::CTuinvaleTreefolkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tuinvale Treefolk"), CardType::Creature, CREATURE_TYPE2(Treefolk, Druid), nID,
		_T("5") GREEN_MANA_TEXT, Power(6), Life(5))
	, m_Adventure(this)
{
	// Oaken Boon {3}{G}, Sorcery - Adventure: Put two +1/+1 counters on target creature.
	counted_ptr<CTargetSpell> cpBoon(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));
	cpBoon->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpBoon->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +2));
	m_Adventure.SetAdventureSpell(cpBoon.GetPointer(), _T("Oaken Boon"));
	AddSpell(cpBoon.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("5") GREEN_MANA_TEXT);
}

//____________________________________________________________________________
//
CWickedWolfCard::CWickedWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wicked Wolf"), CardType::Creature, CREATURE_TYPE(Wolf), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, it fights up to one target creature you don't control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CWickedWolfCard::BeforeFight, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
	pTargeting->SetSubjectCount(0, 1);

	// Sacrifice a Food: Put a +1/+1 counter on this creature. It gains indestructible until end of turn. Tap it.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Foods")));
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. It gains indestructible until end of turn. Tap it. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWickedWolfCard::BeforeFood));
	AddAbility(cpAbility.GetPointer());
}

bool CWickedWolfCard::BeforeFight(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && GetZoneId() == ZoneId::Battlefield)
		Fight(this, pTarget);
	return false;
}

bool CWickedWolfCard::BeforeFood(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;
	AddPlusCounter(this, 1);
	GetCardKeyword()->AddIndestructible(TRUE);
	CCardOrientationModifier(TRUE).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CWildwoodTrackerCard::CWildwoodTrackerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wildwood Tracker"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever this creature attacks or blocks, if you control another non-Human creature, this creature gets +1/+1 until
	// end of turn. (as Inferno Hellion in M19)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::EventCallback, &CWhenSelfAttackedBlocked::SetAttackingOrBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWildwoodTrackerCard::SetCombatContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWildwoodTrackerCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CWildwoodTrackerCard::SetCombatContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const
{
	return ControlsAnotherNonHuman(GetController(), this) == TRUE;
}

bool CWildwoodTrackerCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield && ControlsAnotherNonHuman(pAction->GetController(), this))
		PumpCreature(this, +1, +1);
	return true;
}

//____________________________________________________________________________
//
CYorvoLordOfGarenbrigCard::CYorvoLordOfGarenbrigCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yorvo, Lord of Garenbrig"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Giant, Noble), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(0))
{
	// Yorvo enters with four +1/+1 counters on it.
	GetCounterContainer()->ScheduleCounter(_T("+1/+1"), 4, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// Whenever another green creature you control enters, put a +1/+1 counter on Yorvo. Then if that creature's power is
	// greater than Yorvo's power, put another +1/+1 counter on Yorvo. (the creature in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CYorvoLordOfGarenbrigCard::SetEnterContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CYorvoLordOfGarenbrigCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CYorvoLordOfGarenbrigCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard == this || !pCard->GetCardType().IsCreature() || !pCard->IsColor(CManaPool::Color::Green))
		return false;
	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CYorvoLordOfGarenbrigCard::BeforeCounter(TriggeredAbility::TriggeredActionType* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	AddPlusCounter(this, 1);

	// (the power of the creature: its current power, or its last known power if it left the battlefield)
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)pAction->GetTriggerContext().nValue1);
	if (pCreature)
	{
		int nPower = GET_INTEGER(pCreature->GetZoneId() == ZoneId::Battlefield ? pCreature->GetPower() : pCreature->GetLastKnownPower());
		if (nPower > GET_INTEGER(GetPower()))
			AddPlusCounter(this, 1);
	}
	return true;
}

//____________________________________________________________________________
//
#define RAT_A_TOKEN_NAME				_T("Rat (A)")
#define RAT_A_TOKEN_ID					2745

// "Whenever you draw your second card each turn": counts the draws of the turn (in the context function of a CWhenCardDrew
// trigger, as Mantle of Tides)
static bool IsSecondDrawThisTurn(CGame* pGame, int& nTurn, int& nDraws)
{
	if (pGame->GetGameTurnNumber() != nTurn)
	{
		nTurn = pGame->GetGameTurnNumber();
		nDraws = 0;
	}
	++nDraws;
	return nDraws == 2;
}

// "Another target attacking Knight (you control)": the targeting of an attack trigger
static void SetAnotherAttackingKnightTarget(CTargeting* pTargeting, CCard* pCard, BOOL bYours)
{
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(pCard)));
	if (bYours)
		pTargeting->SetIncludeControllerCardsOnly();
}

// The permanent stolen by Opportunistic Dragon
struct DragonStolenCardComparer : public CardComparer
{
	DragonStolenCardComparer(const COpportunisticDragonCard* pDragon) : m_pDragon(pDragon) {}

	virtual bool operator()(const CCard* value) const
	{
		return value && value == m_pDragon->GetStolenCard();
	}

	virtual DragonStolenCardComparer* Clone() const
	{
		return new DragonStolenCardComparer(m_pDragon);
	}

	const COpportunisticDragonCard* m_pDragon;
};

//____________________________________________________________________________
//
CBloodhazeWolverineCard::CBloodhazeWolverineCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodhaze Wolverine"), CardType::Creature, CREATURE_TYPE(Wolverine), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
	, m_nTurn(-1)
	, m_nDraws(0)
{
	// Whenever you draw your second card each turn, this creature gets +1/+1 and gains first strike until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodhazeWolverineCard::SetDrawContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBloodhazeWolverineCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CBloodhazeWolverineCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	return IsSecondDrawThisTurn(GetGame(), m_nTurn, m_nDraws);
}

bool CBloodhazeWolverineCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1, CreatureKeyword::FirstStrike);
	return true;
}

//____________________________________________________________________________
//
CBonecrusherGiantCard::CBonecrusherGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bonecrusher Giant"), CardType::Creature, CREATURE_TYPE(Giant), nID,
		_T("2") RED_MANA_TEXT, Power(4), Life(3))
	, m_Adventure(this)
{
	{
		// Whenever this creature becomes the target of a spell, this creature deals 2 damage to that spell's controller.
		// (as Departed Deckhand in M19; the spell's controller is the player that chooses the target, in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBonecrusherGiantCard::SetTargetedContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CBonecrusherGiantCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// Stomp {1}{R}, Instant - Adventure: Damage can't be prevented this turn. Stomp deals 2 damage to any target.
	// Partial: the damage can still be prevented.
	counted_ptr<CTargetSpell> cpStomp(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			NewCreatureOrPlaneswalkerComparer(), TRUE));
	cpStomp->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpStomp->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBonecrusherGiantCard::BeforeStomp));
	m_Adventure.SetAdventureSpell(cpStomp.GetPointer(), _T("Stomp"));
	AddSpell(cpStomp.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("2") RED_MANA_TEXT);
}

bool CBonecrusherGiantCard::SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	const CStackAbilityAction* pTop = GetGame()->GetStack().GetTopAction();
	if (!pPlayer || !pTop || !pTop->IsSpell())
		return false;
	triggerContext.nValue1 = (DWORD)pPlayer;
	return true;
}

bool CBonecrusherGiantCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (pPlayer)
		DealDamageToPlayer(this, pPlayer, 2);
	return true;
}

bool CBonecrusherGiantCard::BeforeStomp(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 2);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CBrimstoneTrebuchetCard::CBrimstoneTrebuchetCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brimstone Trebuchet"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("2") RED_MANA_TEXT, Power(1), Life(3))
{
	// Defender, reach
	GetCreatureKeyword()->AddDefender(FALSE);
	GetCreatureKeyword()->AddReach(FALSE);

	{
		// {T}: This creature deals 1 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("This creature deals 1 damage to each opponent. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBrimstoneTrebuchetCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever a Knight you control enters, untap this creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBrimstoneTrebuchetCard::BeforeUntap));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBrimstoneTrebuchetCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

bool CBrimstoneTrebuchetCard::BeforeUntap(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(FALSE).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CBurningYardTrainerCard::CBurningYardTrainerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Burning-Yard Trainer"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("4") RED_MANA_TEXT, Power(3), Life(3))
{
	// Trample, haste
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, another target Knight you control gets +2/+2 and gains trample and haste until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CBurningYardTrainerCard::BeforePump, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CBurningYardTrainerCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pTarget, +2, +2, CreatureKeyword::Trample | CreatureKeyword::Haste);
	return false;
}

//____________________________________________________________________________
//
CEmberethPaladinCard::CEmberethPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Embereth Paladin"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(1))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CEmberethPaladinCard::OnZoneChanged))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Adamant - If at least three red mana was spent to cast this spell, this creature enters with a +1/+1 counter on it.
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CEmberethPaladinCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		IsAdamantPermanent(this, CManaPool::Color::Red))
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
}

//____________________________________________________________________________
//
CEmberethShieldbreakerCard::CEmberethShieldbreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Embereth Shieldbreaker"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
	, m_Adventure(this)
{
	// Battle Display {R}, Sorcery - Adventure: Destroy target artifact.
	counted_ptr<CTargetMoveCardSpell> cpDisplay(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	cpDisplay->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_Adventure.SetAdventureSpell(cpDisplay.GetPointer(), _T("Battle Display"));
	AddSpell(cpDisplay.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") RED_MANA_TEXT);
}

//____________________________________________________________________________
//
CEmberethSkyblazerCard::CEmberethSkyblazerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Embereth Skyblazer"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(3))
	, m_DuringYourTurn(this)
{
	{
		// During your turn, this creature has flying.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::Flying));
		AddAbility(cpAbility.GetPointer());
		m_DuringYourTurn.Add(cpAbility.GetPointer());
		m_DuringYourTurn.AddTurnTriggers();
	}
	{
		// Whenever this creature attacks, you may pay {2}{R}. If you do, creatures you control get +X/+0 until end of turn,
		// where X is the number of opponents you have.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
							   CWhenSelfAttackedBlocked::AttackEventCallback,
							   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("2") RED_MANA_TEXT);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmberethSkyblazerCard::BeforePump));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CEmberethSkyblazerCard::BeforePump(CAbilityAction* pAction)
{
	int nOpponents = GetGame()->GetPlayerCount() - 1;
	if (nOpponents > 0)
		PumpCreatures(GetGame(), pAction->GetController(), nOpponents, 0);
	return true;
}

//____________________________________________________________________________
//
CFerventChampionCard::CFerventChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fervent Champion"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// First strike, haste
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever this creature attacks, another target attacking Knight you control gets +1/+0 until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CFerventChampionCard::BeforePump, Characteristic::Positive);
	SetAnotherAttackingKnightTarget(pTargeting, this, TRUE);

	// Equip abilities you activate that target this creature cost {3} less to activate.
	// Not implemented: the engine can't reduce the equip costs.
}

bool CFerventChampionCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pTarget, +1, 0);
	return false;
}

//____________________________________________________________________________
//
CIrencragPyromancerCard::CIrencragPyromancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Irencrag Pyromancer"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") RED_MANA_TEXT, Power(0), Life(4))
	, m_nTurn(-1)
	, m_nDraws(0)
{
	// Whenever you draw your second card each turn, this creature deals 3 damage to any target.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(NewCreatureOrPlaneswalkerComparer());
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CIrencragPyromancerCard::SetDrawContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIrencragPyromancerCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CIrencragPyromancerCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	return IsSecondDrawThisTurn(GetGame(), m_nTurn, m_nDraws);
}

bool CIrencragPyromancerCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 3);
	return false;
}

//____________________________________________________________________________
//
CMadRatterCard::CMadRatterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mad Ratter"), CardType::Creature, CREATURE_TYPE(Goblin), nID,
		_T("3") RED_MANA_TEXT, Power(1), Life(2))
	, m_nTurn(-1)
	, m_nDraws(0)
{
	// Whenever you draw your second card each turn, create two 1/1 black Rat creature tokens.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMadRatterCard::SetDrawContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMadRatterCard::BeforeRats));
	AddAbility(cpAbility.GetPointer());
}

bool CMadRatterCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	return IsSecondDrawThisTurn(GetGame(), m_nTurn, m_nDraws);
}

bool CMadRatterCard::BeforeRats(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), RAT_A_TOKEN_NAME, RAT_A_TOKEN_ID, 2).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CMerchantOfTheValeCard::CMerchantOfTheValeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merchant of the Vale"), CardType::Creature, CREATURE_TYPE2(Human, Peasant), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
	, m_Adventure(this)
{
	{
		// {2}{R}, Discard a card: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("2") RED_MANA_TEXT, 1));
		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		AddAbility(cpAbility.GetPointer());
	}

	// Haggle {R}, Instant - Adventure: You may discard a card. If you do, draw a card.
	counted_ptr<CGenericSpell> cpHaggle(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, RED_MANA_TEXT));
	cpHaggle->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMerchantOfTheValeCard::BeforeHaggle));
	m_Adventure.SetAdventureSpell(cpHaggle.GetPointer(), _T("Haggle"));
	AddSpell(cpHaggle.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("2") RED_MANA_TEXT);
}

bool CMerchantOfTheValeCard::BeforeHaggle(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	int nBefore = pHand->GetSize();
	ChooseAndMove(GetGame(), pController, ZoneId::Hand, 0, 1, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Graveyard, MoveType::Discard);
	if (pHand->GetSize() < nBefore)
		DrawCards(GetGame(), pController, 1);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
COgreErrantCard::COgreErrantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ogre Errant"), CardType::Creature, CREATURE_TYPE2(Ogre, Knight), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(4))
{
	// Whenever this creature attacks, another target attacking Knight gains menace until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &COgreErrantCard::BeforeMenace, Characteristic::Positive);
	SetAnotherAttackingKnightTarget(pTargeting, this, FALSE);
}

bool COgreErrantCard::BeforeMenace(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		pCreature->GetCreatureKeyword()->AddCantBeBlockedByOne(TRUE);
	return false;
}

//____________________________________________________________________________
//
COpportunisticDragonCard::COpportunisticDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Opportunistic Dragon"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
	, m_pStolen(NULL)
{
	// When this creature enters, choose target Human or artifact an opponent controls. For as long as this creature
	// remains on the battlefield, gain control of that permanent, it loses all abilities, and it can't attack or block.
	// Partial: the permanent doesn't lose its abilities.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &COpportunisticDragonCard::BeforeSteal, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false), new CardTypeComparer(CardType::Artifact, false)));
	pTargeting->SetIncludeNonControllerCardsOnly();

	AddLeaveTrigger(this, &COpportunisticDragonCard::BeforeReturn);

	// (it can't attack or block: a static ability of this creature on the stolen permanent)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new DragonStolenCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock));
	AddAbility(cpAbility.GetPointer());
}

bool COpportunisticDragonCard::BeforeSteal(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield || GetZoneId() != ZoneId::Battlefield)
		return false;

	m_pStolen = pTarget;
	CGainControlModifier pModifier = CGainControlModifier(GetGame(), this);
	pModifier.ApplyTo(pTarget);
	return false;
}

bool COpportunisticDragonCard::BeforeReturn(CAbilityAction* pAction)
{
	// (the control goes back to its owner, as Switcheroo in Ravnica Allegiance)
	CCard* pCard = m_pStolen;
	m_pStolen = NULL;
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetController() != pCard->GetOwner())
		CTransferControlModifier(GetGame(), pCard, pCard).ApplyTo(pCard->GetOwner());
	return true;
}

//____________________________________________________________________________
//
CRagingRedcapCard::CRagingRedcapCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Raging Redcap"), CardType::Creature, CREATURE_TYPE2(Goblin, Knight), nID,
		_T("2") RED_MANA_TEXT, Power(1), Life(2))
{
	// Double strike
	GetCreatureKeyword()->AddDoubleStrike(FALSE);
}

//____________________________________________________________________________
//
CRedcapRaidersCard::CRedcapRaidersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Redcap Raiders"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CRedcapRaidersCard::OnCreatureSelected))
{
	// Whenever this creature attacks, you may tap an untapped non-Human creature you control. If you do, this creature
	// gets +1/+1 and gains trample until end of turn.
	AddSelfAttackTrigger(this, &CRedcapRaidersCard::BeforeTap);
}

bool CRedcapRaidersCard::BeforeTap(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard->GetOrientation()->IsTapped() || CreatureTypeComparer(CREATURE_TYPE(Human), false)(pCard))
			continue;
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Tap %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_Selection.AddSelectionRequest(entries, 0, 1, NULL, pAction->GetController());
	return true;
}

void CRedcapRaidersCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (!it->bSelected || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetOrientation()->IsTapped())
			continue;
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
		if (GetZoneId() == ZoneId::Battlefield)
			PumpCreature(this, +1, +1, CreatureKeyword::Trample);
	}
}

//____________________________________________________________________________
//
CRimrockKnightCard::CRimrockKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rimrock Knight"), CardType::Creature, CREATURE_TYPE2(Dwarf, Knight), nID,
		_T("1") RED_MANA_TEXT, Power(3), Life(1))
	, m_Adventure(this)
{
	// This creature can't block.
	GetCreatureKeyword()->AddCantBlock(FALSE);

	// Boulder Rush {R}, Instant - Adventure: Target creature gets +2/+0 until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpRush(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			Power(+2), Life(+0),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));
	cpRush->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	m_Adventure.SetAdventureSpell(cpRush.GetPointer(), _T("Boulder Rush"));
	AddSpell(cpRush.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") RED_MANA_TEXT);
}

//____________________________________________________________________________
//
CRowansBattleguardCard::CRowansBattleguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rowan's Battleguard"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// As long as you control a Rowan planeswalker, this creature gets +3/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+3), Life(+0)));
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Rowan));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CRowansStalwartsCard::CRowansStalwartsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rowan's Stalwarts"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("4") RED_MANA_TEXT, Power(5), Life(2))
{
	// When this creature enters, you may search your library and/or graveyard for a card named Rowan, Fearless
	// Sparkmage, reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CRowansStalwartsCard::BeforeSearch, true);
}

bool CRowansStalwartsCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Rowan, Fearless Sparkmage"));
	return true;
}

//____________________________________________________________________________
//
CSevenDwarvesCard::CSevenDwarvesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Seven Dwarves"), CardType::Creature, CREATURE_TYPE(Dwarf), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// This creature gets +1/+1 for each other creature named Seven Dwarves you control.
	// (A deck can have up to seven cards named Seven Dwarves.)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, ZoneId::Battlefield,
			new AndCardComparer(new CardNameComparer(_T("Seven Dwarves")), new NegateCardComparer(new SpecificCardComparer(this)))));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSkullknockerOgreCard::CSkullknockerOgreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skullknocker Ogre"), CardType::Creature, CREATURE_TYPE(Ogre), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(3))
{
	// Whenever this creature deals damage to an opponent, that player discards a card at random. If the player does, they
	// draw a card. (the player in nValue1, as Urgoros)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSkullknockerOgreCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CSkullknockerOgreCard::BeforeDiscard));
	AddAbility(cpAbility.GetPointer());
}

bool CSkullknockerOgreCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	if (!pPlayer || pPlayer == GetController())
		return false;
	triggerContext.nValue1 = (DWORD)pPlayer;
	return true;
}

bool CSkullknockerOgreCard::BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (!pPlayer)
		return true;

	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
	if (pHand->GetSize() == 0)
		return true;

	CCard* pCard = pHand->GetAt(pPlayer->GetRand() % pHand->GetSize());
	CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pPlayer).ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Hand)
		DrawCards(GetGame(), pPlayer, 1);
	return true;
}

//____________________________________________________________________________
//
CSyrCarahTheBoldCard::CSyrCarahTheBoldCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syr Carah, the Bold"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Whenever Syr Carah or an instant or sorcery spell you control deals damage to a player, exile the top card of your
	// library. You may play that card this turn.
	// Not implemented: the engine can't play the exiled cards.

	// {T}: Syr Carah deals 1 damage to any target.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			NewCreatureOrPlaneswalkerComparer(), TRUE));
	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSyrCarahTheBoldCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CSyrCarahTheBoldCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToAnyTarget(this, pAction, 1);
	return false;
}

//____________________________________________________________________________
//
CWeaselbackRedcapCard::CWeaselbackRedcapCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weaselback Redcap"), CardType::Creature, CREATURE_TYPE2(Goblin, Knight), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// {1}{R}: This creature gets +2/+0 until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("This creature gets +2/+0 until end of turn. Activates"),
		&CWeaselbackRedcapCard::BeforePump);
}

bool CWeaselbackRedcapCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, 0);
	return true;
}

//____________________________________________________________________________
//
#define GOAT_A_TOKEN_NAME				_T("Goat (A)")
#define GOAT_A_TOKEN_ID					2847

//____________________________________________________________________________
//
CAyaraFirstOfLocthwainCard::CAyaraFirstOfLocthwainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ayara, First of Locthwain"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Noble), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
	, m_SacrificeFilter(_T("another black creature"), _T("other black creatures"),
		new AndCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Black, false)))
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	{
		// Whenever Ayara or another black creature you control enters, each opponent loses 1 life and you gain 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAyaraFirstOfLocthwainCard::SetEnterContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAyaraFirstOfLocthwainCard::BeforeDrain));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Sacrifice another black creature: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAyaraFirstOfLocthwainCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard->GetCardType().IsCreature() && pCard->IsColor(CManaPool::Color::Black);
}

bool CAyaraFirstOfLocthwainCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, TRUE);
	return true;
}

//____________________________________________________________________________
//
CBarrowWitchesCard::CBarrowWitchesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Barrow Witches"), CardType::Creature, CREATURE_TYPE2(Human, Warlock), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(4))
	, m_KnightFilter(_T("a Knight card"), _T("Knight cards"), new CreatureTypeComparer(CREATURE_TYPE(Knight), false))
{
	// When this creature enters, return target Knight card from your graveyard to your hand.
	// Partial: the card is chosen on resolution (it isn't a target).
	AddEnterTrigger(this, &CBarrowWitchesCard::BeforeReturn);
}

bool CBarrowWitchesCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, &m_KnightFilter, ZoneId::Hand, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CBelleOfTheBrawlCard::CBelleOfTheBrawlCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Belle of the Brawl"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Whenever this creature attacks, other Knights you control get +1/+0 until end of turn.
	AddSelfAttackTrigger(this, &CBelleOfTheBrawlCard::BeforePump);
}

bool CBelleOfTheBrawlCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer knights;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Knight), knights);
	for (int i = 0; i < knights.GetSize(); ++i)
		if (knights.GetAt(i) != this)
			PumpCreature(knights.GetAt(i), +1, 0);
	return true;
}

//____________________________________________________________________________
//
CBlacklanceParagonCard::CBlacklanceParagonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blacklance Paragon"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") BLACK_MANA_TEXT, Power(3), Life(1))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, target Knight gains deathtouch and lifelink until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CBlacklanceParagonCard::BeforeKeywords, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
}

bool CBlacklanceParagonCard::BeforeKeywords(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
	{
		pTarget->GetCardKeyword()->AddDeathtouch(TRUE);
		pTarget->GetCardKeyword()->AddLifelink(TRUE);
	}
	return false;
}

//____________________________________________________________________________
//
CBogNaughtyCard::CBogNaughtyCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bog Naughty"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// {2}{B}, Sacrifice a Food: Target creature gets -3/-3 until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2") BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Foods")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBogNaughtyCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());
}

bool CBogNaughtyCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pTarget, -3, -3);
	return false;
}

//____________________________________________________________________________
//
CCauldronFamiliarCard::CCauldronFamiliarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cauldron Familiar"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, each opponent loses 1 life and you gain 1 life.
	AddEnterTrigger(this, &CCauldronFamiliarCard::BeforeDrain);

	// Sacrifice a Food: Return this card from your graveyard to the battlefield.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Foods")));
	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to the battlefield. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCauldronFamiliarCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CCauldronFamiliarCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, TRUE);
	return true;
}

bool CCauldronFamiliarCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CChitteringWitchCard::CChitteringWitchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Chittering Witch"), CardType::Creature, CREATURE_TYPE2(Human, Warlock), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, create a number of 1/1 black Rat creature tokens equal to the number of opponents you have.
	AddEnterTrigger(this, &CChitteringWitchCard::BeforeRats);

	// {1}{B}, Sacrifice a creature: Target creature gets -2/-2 until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChitteringWitchCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());
}

bool CChitteringWitchCard::BeforeRats(CAbilityAction* pAction)
{
	int nOpponents = GetGame()->GetPlayerCount() - 1;
	if (nOpponents > 0)
		CTokenCreationModifier(GetGame(), RAT_A_TOKEN_NAME, RAT_A_TOKEN_ID, nOpponents).ApplyTo(pAction->GetController());
	return true;
}

bool CChitteringWitchCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pTarget, -2, -2);
	return false;
}

//____________________________________________________________________________
//
CClackbridgeTrollCard::CClackbridgeTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Clackbridge Troll"), CardType::Creature, CREATURE_TYPE(Troll), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(8), Life(8))
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CClackbridgeTrollCard::OnSelected))
{
	// Trample, haste
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, target opponent creates three 0/1 white Goat creature tokens.
	// (the opponent, as in a two-player game)
	AddEnterTrigger(this, &CClackbridgeTrollCard::BeforeGoats);

	// At the beginning of combat on your turn, any opponent may sacrifice a creature of their choice. If a player does,
	// tap this creature, you gain 3 life, and you draw a card.
	AddStepTrigger<CClackbridgeTrollCard>(this, NodeId::BeginningOfCombatStep, false, NULL, &CClackbridgeTrollCard::BeforeCombat);
}

bool CClackbridgeTrollCard::BeforeGoats(CAbilityAction* pAction)
{
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAction->GetController());
	if (pOpponent && pOpponent != pAction->GetController())
		CTokenCreationModifier(GetGame(), GOAT_A_TOKEN_NAME, GOAT_A_TOKEN_ID, 3).ApplyTo(pOpponent);
	return true;
}

bool CClackbridgeTrollCard::BeforeCombat(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	if (!pOpponent || pOpponent == pController || CountCreatures(GetGame(), pOpponent) == 0)
		return true;

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText.Format(_T("Sacrifice a creature (%s is tapped, its controller gains 3 life and draws a card)"), GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText = _T("Don't sacrifice a creature");
		entries.push_back(entry);
	}
	m_Selection.AddSelectionRequest(entries, 1, 1, NULL, pOpponent, (DWORD)pController);
	return true;
}

void CClackbridgeTrollCard::OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected || it->dwContext != 1)
			continue;

		int nBefore = CountCreatures(GetGame(), pSelectionPlayer);
		ChooseAndMove(GetGame(), pSelectionPlayer, ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
			ZoneId::Graveyard, MoveType::Sacrifice);
		if (CountCreatures(GetGame(), pSelectionPlayer) >= nBefore)
			continue;

		if (GetZoneId() == ZoneId::Battlefield)
			CCardOrientationModifier(TRUE).ApplyTo(this);
		GainLife(this, pController, 3);
		DrawCards(GetGame(), pController, 1);
	}
}

//____________________________________________________________________________
//
CEyeCollectorCard::CEyeCollectorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Eye Collector"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Whenever this creature deals combat damage to a player, each player mills a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEyeCollectorCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CEyeCollectorCard::BeforeMill(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		Mill(GetGame()->GetPlayer(ip), 1);
	return true;
}

//____________________________________________________________________________
//
CFoulmireKnightCard::CFoulmireKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Foulmire Knight"), CardType::Creature, CREATURE_TYPE2(Zombie, Knight), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
	, m_Adventure(this)
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Profane Insight {2}{B}, Instant - Adventure: You draw a card and you lose 1 life.
	counted_ptr<CGenericSpell> cpInsight(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("2") BLACK_MANA_TEXT));
	cpInsight->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFoulmireKnightCard::BeforeInsight));
	m_Adventure.SetAdventureSpell(cpInsight.GetPointer(), _T("Profane Insight"));
	AddSpell(cpInsight.GetPointer());

	m_Adventure.AddCastFromExileSpell(BLACK_MANA_TEXT);
}

bool CFoulmireKnightCard::BeforeInsight(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	LoseLife(this, pAction->GetController(), 1);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CLocthwainPaladinCard::CLocthwainPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Locthwain Paladin"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(2))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CLocthwainPaladinCard::OnZoneChanged))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Adamant - If at least three black mana was spent to cast this spell, this creature enters with a +1/+1 counter on it.
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CLocthwainPaladinCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		IsAdamantPermanent(this, CManaPool::Color::Black))
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
}

//____________________________________________________________________________
//
CLostLegionCard::CLostLegionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lost Legion"), CardType::Creature, CREATURE_TYPE2(Spirit, Knight), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, scry 2.
	AddEnterTrigger(this, &CLostLegionCard::BeforeScry);
}

bool CLostLegionCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CMalevolentNobleCard::CMalevolentNobleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Malevolent Noble"), CardType::Creature, CREATURE_TYPE2(Human, Noble), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_SacrificeFilter(_T("an artifact or another creature"), _T("artifacts or other creatures"),
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new AnyCreatureComparer))
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// {2}, Sacrifice an artifact or another creature: Put a +1/+1 counter on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2")));
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMalevolentNobleCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CMalevolentNobleCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CMurderousRiderCard::CMurderousRiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Murderous Rider"), CardType::Creature, CREATURE_TYPE2(Zombie, Knight), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
	, m_Adventure(this)
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature dies, put it on the bottom of its owner's library.
	AddDiesTrigger(this, &CMurderousRiderCard::BeforeBottom);

	// Swift End {1}{B}{B}, Instant - Adventure: Destroy target creature or planeswalker. You lose 2 life.
	counted_ptr<CTargetMoveCardSpell> cpSwiftEnd(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			NewCreatureOrPlaneswalkerComparer(),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	cpSwiftEnd->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSwiftEnd->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMurderousRiderCard::BeforeSwiftEnd));
	m_Adventure.SetAdventureSpell(cpSwiftEnd.GetPointer(), _T("Swift End"));
	AddSpell(cpSwiftEnd.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT);
}

bool CMurderousRiderCard::BeforeBottom(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pAction->GetController());
		pModifier.SetToTop(FALSE);
		pModifier.ApplyTo(this);
	}
	return true;
}

bool CMurderousRiderCard::BeforeSwiftEnd(CAbilityAction* pAction)
{
	LoseLife(this, pAction->GetController(), 2);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
COathswornKnightCard::COathswornKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oathsworn Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(0), Life(0))
{
	// This creature enters with four +1/+1 counters on it.
	GetCounterContainer()->ScheduleCounter(_T("+1/+1"), 4, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// This creature attacks each combat if able.
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);

	// If damage would be dealt to this creature while it has a +1/+1 counter on it, prevent that damage and remove a +1/+1
	// counter from it.
	// Not implemented: the engine has no damage replacement effects.
}

//____________________________________________________________________________
//
COrderOfMidnightCard::COrderOfMidnightCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Order of Midnight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_Adventure(this)
{
	// This creature can't block.
	GetCreatureKeyword()->AddCantBlock(FALSE);

	// Alter Fate {1}{B}, Sorcery - Adventure: Return target creature card from your graveyard to your hand.
	counted_ptr<CTargetMoveCardSpell> cpAlter(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));
	cpAlter->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAlter->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	m_Adventure.SetAdventureSpell(cpAlter.GetPointer(), _T("Alter Fate"));
	AddSpell(cpAlter.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") BLACK_MANA_TEXT);
}

//____________________________________________________________________________
//
CPiperOfTheSwarmCard::CPiperOfTheSwarmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Piper of the Swarm"), CardType::Creature, CREATURE_TYPE2(Human, Warlock), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(3))
	, m_RatFilter(_T("a Rat"), _T("Rats"), new CreatureTypeComparer(CREATURE_TYPE(Rat), false))
{
	{
		// Rats you control have menace.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Rat), false),
				Power(+0), Life(+0), CreatureKeyword::CantBeBlockedBy1));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}, {T}: Create a 1/1 black Rat creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("1") BLACK_MANA_TEXT,
				RAT_A_TOKEN_NAME, RAT_A_TOKEN_ID, 1));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{B}{B}, {T}, Sacrifice three Rats: Gain control of target creature. (as Old Man of the Sea in Arabian Nights)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(3, &m_RatFilter);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CGainControlModifier(GetGame(), (CCard*)this));
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CRankleMasterOfPranksCard::CRankleMasterOfPranksCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rankle, Master of Pranks"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Faerie, Rogue), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRankleMasterOfPranksCard::OnModesSelected))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever Rankle deals combat damage to a player, choose any number - ...
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRankleMasterOfPranksCard::BeforeChoose));
	AddAbility(cpAbility.GetPointer());
}

bool CRankleMasterOfPranksCard::BeforeChoose(CAbilityAction* pAction)
{
	static LPCTSTR modes[] = { _T("Each player discards a card"), _T("Each player loses 1 life and draws a card"),
		_T("Each player sacrifices a creature of their choice") };

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 3; ++i)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)i;
		entry.strText = modes[i];
		entries.push_back(entry);
	}
	m_ModeSelection.AddSelectionRequest(entries, 0, 3, NULL, pAction->GetController());
	return true;
}

void CRankleMasterOfPranksCard::OnModesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	BOOL bModes[3] = { FALSE, FALSE, FALSE };
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext < 3)
			bModes[it->dwContext] = TRUE;

	CGame* pGame = GetGame();
	if (bModes[0])
		for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
			ChooseAndMove(pGame, pGame->GetPlayer(ip), ZoneId::Hand, 1, 1, CCardFilter::GetFilter(_T("cards")),
				ZoneId::Graveyard, MoveType::Discard);
	if (bModes[1])
		for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		{
			LoseLife(this, pGame->GetPlayer(ip), 1);
			DrawCards(pGame, pGame->GetPlayer(ip), 1);
		}
	if (bModes[2])
		for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
			ChooseAndMove(pGame, pGame->GetPlayer(ip), ZoneId::Battlefield, 1, 1, CCardFilter::GetFilter(_T("creatures")),
				ZoneId::Graveyard, MoveType::Sacrifice);
}

//____________________________________________________________________________
//
CReaperOfNightCard::CReaperOfNightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reaper of Night"), CardType::Creature, CREATURE_TYPE(Specter), nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(5))
	, m_Adventure(this)
{
	// Whenever this creature attacks, if defending player has two or fewer cards in hand, it gains flying until end of
	// turn. (the defending player is the opponent, as in a two-player game)
	AddSelfAttackTrigger(this, &CReaperOfNightCard::BeforeFlying);

	// Harvest Fear {3}{B}, Sorcery - Adventure: Target opponent discards two cards.
	counted_ptr<CTargetPlayerDiscardCardSpell> cpHarvest(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT,
			2, MoveType::Discard, ZoneId::Graveyard, TRUE, TRUE, CCardFilter::GetFilter(_T("cards"))));
	cpHarvest->GetTargeting()->SetIncludeOpponentPlayersOnly();
	m_Adventure.SetAdventureSpell(cpHarvest.GetPointer(), _T("Harvest Fear"));
	AddSpell(cpHarvest.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT);
}

bool CReaperOfNightCard::BeforeFlying(CAbilityAction* pAction)
{
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAction->GetController());
	if (pOpponent && GetZoneId() == ZoneId::Battlefield && pOpponent->GetZoneById(ZoneId::Hand)->GetSize() <= 2)
		GetCreatureKeyword()->AddFlying(TRUE);
	return true;
}

//____________________________________________________________________________
//
CSmittenSwordmasterCard::CSmittenSwordmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Smitten Swordmaster"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
	, m_Adventure(this)
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// Curry Favor {B}, Sorcery - Adventure: You gain X life and each opponent loses X life, where X is the number of
	// Knights you control.
	counted_ptr<CGenericSpell> cpCurry(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, BLACK_MANA_TEXT));
	cpCurry->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSmittenSwordmasterCard::BeforeCurry));
	m_Adventure.SetAdventureSpell(cpCurry.GetPointer(), _T("Curry Favor"));
	AddSpell(cpCurry.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") BLACK_MANA_TEXT);
}

bool CSmittenSwordmasterCard::BeforeCurry(CAbilityAction* pAction)
{
	CCountedCardContainer knights;
	GetCreaturesOfType(GetGame(), pAction->GetController(), CREATURE_TYPE(Knight), knights);
	DrainOpponents(this, pAction->GetController(), knights.GetSize(), TRUE);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CSyrKonradTheGrimCard::CSyrKonradTheGrimCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syr Konrad, the Grim"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(4))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	{
		// Whenever another creature dies, or a creature card is put into a graveyard from anywhere other than the
		// battlefield, Syr Konrad deals 1 damage to each opponent.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Graveyard));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSyrKonradTheGrimCard::SetToGraveyardContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSyrKonradTheGrimCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// ... or a creature card leaves your graveyard, ...
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Graveyard, ZoneId::_AllZones));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSyrKonradTheGrimCard::SetLeaveGraveyardContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSyrKonradTheGrimCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}: Each player mills a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1") BLACK_MANA_TEXT));
		cpAbility->SetAbilityText(_T("Each player mills a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSyrKonradTheGrimCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSyrKonradTheGrimCard::SetToGraveyardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard != this && pCard->GetCardType().IsCreature();
}

bool CSyrKonradTheGrimCard::SetLeaveGraveyardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard->GetCardType().IsCreature();
}

bool CSyrKonradTheGrimCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

bool CSyrKonradTheGrimCard::BeforeMill(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		Mill(GetGame()->GetPlayer(ip), 1);
	return true;
}

//____________________________________________________________________________
//
CTemptingWitchCard::CTemptingWitchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tempting Witch"), CardType::Creature, CREATURE_TYPE2(Human, Warlock), nID,
		_T("2") BLACK_MANA_TEXT, Power(1), Life(3))
{
	// When this creature enters, create a Food token.
	AddEnterTrigger(this, &CTemptingWitchCard::BeforeFood);

	// {2}, {T}, Sacrifice a Food: Target player loses 3 life.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2"),
			FALSE_CARD_COMPARER, TRUE));
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Foods")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTemptingWitchCard::BeforeLoseLife));
	AddAbility(cpAbility.GetPointer());
}

bool CTemptingWitchCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

bool CTemptingWitchCard::BeforeLoseLife(CAbilityAction* pAction)
{
	LoseLife(this, pAction->GetAssociatedPlayer(), 3);
	return false;
}

//____________________________________________________________________________
//
CWickedGuardianCard::CWickedGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wicked Guardian"), CardType::Creature, CREATURE_TYPE2(Human, Noble), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(2))
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CWickedGuardianCard::OnCreatureSelected))
{
	// When this creature enters, you may have it deal 2 damage to another creature you control. If you do, draw a card.
	AddEnterTrigger(this, &CWickedGuardianCard::BeforeChoose);
}

bool CWickedGuardianCard::BeforeChoose(CAbilityAction* pAction)
{
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
		entry.strText.Format(_T("Deal 2 damage to %s and draw a card"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	if (!entries.empty())
		m_Selection.AddSelectionRequest(entries, 0, 1, NULL, pAction->GetController());
	return true;
}

void CWickedGuardianCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
	DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (!it->bSelected || pCard->GetZoneId() != ZoneId::Battlefield)
			continue;
		DealDamageToCreature(this, pCard, 2);
		DrawCards(GetGame(), pSelectionPlayer, 1);
	}
}

//____________________________________________________________________________
//
// "Target noncreature artifact becomes a 0/0 artifact creature. Put four +1/+1 counters on it." (permanently, with the
// IsAlsoA of Karn, the Great Creator; the counters on the creature)
static void AnimateArtifactWithCounters(CCard* pCard, CPlayer* pController, int nCounters)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetIsAlsoA() || pCard->GetCardType().IsCreature())
		return;

	CCardIsAlsoAModifier(ANIMATED_ARTIFACT_B_TOKEN_NAME, ANIMATED_ARTIFACT_B_TOKEN_ID, pController).ApplyTo(pCard);

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard->GetIsAlsoA());
	if (pCreature)
	{
		pCreature->SetPrintedPower(Power(0));
		pCreature->SetPrintedToughness(Life(0));
		AddPlusCounter(pCreature, nCounters);
	}
}

// The noncreature artifacts
static CardComparer* NewNoncreatureArtifactComparer()
{
	return new AndCardComparer(new CardTypeComparer(CardType::Artifact, false),
		new NegateCardComparer(new CardTypeComparer(CardType::Creature, false)));
}

static int CountYourArtifacts(CCard* pCard)
{
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(
		pCard->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
}

// The opponent of the creature's controller has fewer than seven cards in their graveyard (Vantress Gargoyle)
struct OpponentGraveyardUnderSevenComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		CPlayer* pController = value->GetController();
		CPlayer* pOpponent = pController ? pController->GetGame()->GetNextPlayer(pController) : NULL;
		return pOpponent && pOpponent->GetZoneById(ZoneId::Graveyard)->GetSize() < 7;
	}

	virtual OpponentGraveyardUnderSevenComparer* Clone() const
	{
		return new OpponentGraveyardUnderSevenComparer;
	}
};

// The creature's controller has fewer than four cards in hand (Vantress Gargoyle)
struct HandUnderFourComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		CPlayer* pController = value->GetController();
		return pController && pController->GetZoneById(ZoneId::Hand)->GetSize() < 4;
	}

	virtual HandUnderFourComparer* Clone() const
	{
		return new HandUnderFourComparer;
	}
};

//____________________________________________________________________________
//
CAnimatingFaerieCard::CAnimatingFaerieCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Animating Faerie"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_Adventure(this)
{
	// Bring to Life {2}{U}, Sorcery - Adventure: Target noncreature artifact you control becomes a 0/0 artifact creature.
	// Put four +1/+1 counters on it.
	counted_ptr<CTargetSpell> cpBring(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLUE_MANA_TEXT,
			NewNoncreatureArtifactComparer(), FALSE));
	cpBring->GetTargeting()->SetIncludeControllerCardsOnly();
	cpBring->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpBring->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAnimatingFaerieCard::BeforeBringToLife));
	m_Adventure.SetAdventureSpell(cpBring.GetPointer(), _T("Bring to Life"));
	AddSpell(cpBring.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("2") BLUE_MANA_TEXT);
}

bool CAnimatingFaerieCard::BeforeBringToLife(CAbilityAction* pAction)
{
	AnimateArtifactWithCounters(pAction->GetAssociatedCard(), pAction->GetController(), 4);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CBrazenBorrowerCard::CBrazenBorrowerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Brazen Borrower"), CardType::Creature, CREATURE_TYPE2(Faerie, Rogue), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(1))
	, m_Adventure(this)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// This creature can block only creatures with flying.
	GetCreatureKeyword()->AddCanOnlyBlockFlying(FALSE);

	// Petty Theft {1}{U}, Instant - Adventure: Return target nonland permanent an opponent controls to its owner's hand.
	counted_ptr<CTargetMoveCardSpell> cpTheft(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));
	cpTheft->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpTheft->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_Adventure.SetAdventureSpell(cpTheft.GetPointer(), _T("Petty Theft"));
	AddSpell(cpTheft.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT);
}

//____________________________________________________________________________
//
CCorridorMonitorCard::CCorridorMonitorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Corridor Monitor"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// When this creature enters, untap target artifact or creature you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CCorridorMonitorCard::BeforeUntap, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new AnyCreatureComparer));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CCorridorMonitorCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(FALSE).ApplyTo(pTarget);
	return false;
}

//____________________________________________________________________________
//
CEmryLurkerOfTheLochCard::CEmryLurkerOfTheLochCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emry, Lurker of the Loch"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// Affinity for artifacts (This spell costs {1} less to cast for each artifact you control.)
	AddCountReductionSpells(this, m_Reductions, 2, BLUE_MANA_TEXT, 1, &CountYourArtifacts);

	// When Emry enters, mill four cards.
	AddEnterTrigger(this, &CEmryLurkerOfTheLochCard::BeforeMill);

	// {T}: Choose target artifact card in your graveyard. You may cast that card this turn.
	// Not implemented: the engine can't cast cards from the graveyard this way.
}

bool CEmryLurkerOfTheLochCard::BeforeMill(CAbilityAction* pAction)
{
	Mill(pAction->GetController(), 4);
	return true;
}

//____________________________________________________________________________
//
CFaeOfWishesCard::CFaeOfWishesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Fae of Wishes"), CardType::Creature, CREATURE_TYPE2(Faerie, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// {1}{U}, Discard two cards: Return this creature to its owner's hand.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1") BLUE_MANA_TEXT));
	cpAbility->GetCost().AddDiscardCardCost(2, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CCardModifiers::push_back(
		new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));
	cpAbility->SetAbilityText(_T("Return this creature to its owner's hand. Activates"));
	AddAbility(cpAbility.GetPointer());

	// Granted {3}{U}, Sorcery - Adventure: You may reveal a noncreature card you own from outside the game and put it into
	// your hand.
	// Not implemented: there are no cards outside the game.
}

//____________________________________________________________________________
//
CFaerieFormationCard::CFaerieFormationCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Faerie Formation"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("4") BLUE_MANA_TEXT, Power(5), Life(4))
{
	// {3}{U}: Create a 1/1 blue Faerie creature token with flying. Draw a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("3") BLUE_MANA_TEXT));
	cpAbility->SetAbilityText(_T("Create a 1/1 blue Faerie creature token with flying. Draw a card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFaerieFormationCard::BeforeFaerie));
	AddAbility(cpAbility.GetPointer());
}

bool CFaerieFormationCard::BeforeFaerie(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FAERIE_A_TOKEN_NAME, FAERIE_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CFaerieVandalCard::CFaerieVandalCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Faerie Vandal"), CardType::Creature, CREATURE_TYPE2(Faerie, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(2))
	, m_nTurn(-1)
	, m_nDraws(0)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Whenever you draw your second card each turn, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFaerieVandalCard::SetDrawContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFaerieVandalCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CFaerieVandalCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	return IsSecondDrawThisTurn(GetGame(), m_nTurn, m_nDraws);
}

bool CFaerieVandalCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CGadwickTheWizenedCard::CGadwickTheWizenedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gadwick, the Wizened"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Wizard), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CGadwickTheWizenedCard::OnZoneChanged))
	, m_nX(0)
	, m_nDrawX(0)
{
	// {X}{U}{U}{U} (creature spell with {X} as Hydroid Krasis in Ravnica Allegiance: the main spell can't be cast, the X
	// spell remembers X when it resolves)
	AddPlayableIf(this, GetSpells().GetAt(0), &CGadwickTheWizenedCard::Never);

	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Creature, BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT));
	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGadwickTheWizenedCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// When Gadwick enters, draw X cards.
	AddEnterIfTrigger(this, &CGadwickTheWizenedCard::SetEnterContext, &CGadwickTheWizenedCard::BeforeDraw);

	// Whenever you cast a blue spell, tap target nonland permanent an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Blue, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGadwickTheWizenedCard::BeforeTap));
	AddAbility(cpAbility.GetPointer());
}

bool CGadwickTheWizenedCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	return true;
}

void CGadwickTheWizenedCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		m_nDrawX = (moveType == MoveType::Cast) ? m_nX : 0;
		m_nX = 0;
	}
}

bool CGadwickTheWizenedCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Cast;
}

bool CGadwickTheWizenedCard::BeforeDraw(CAbilityAction* pAction)
{
	int nX = m_nDrawX;
	m_nDrawX = 0;
	if (nX > 0)
		DrawCards(GetGame(), pAction->GetController(), nX);
	return true;
}

bool CGadwickTheWizenedCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(TRUE).ApplyTo(pTarget);
	return false;
}

//____________________________________________________________________________
//
CHypnoticSpriteCard::CHypnoticSpriteCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Hypnotic Sprite"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(1))
	, m_Adventure(this)
{
	// Mesmeric Glare {2}{U}, Instant - Adventure: Counter target spell with mana value 3 or less.
	counted_ptr<CCounterSpell> cpGlare(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new ConvertedManaCostComparer<std::less_equal<int>>(3)));
	m_Adventure.SetAdventureSpell(cpGlare.GetPointer(), _T("Mesmeric Glare"));
	AddSpell(cpGlare.GetPointer());

	m_Adventure.AddCastFromExileSpell(BLUE_MANA_TEXT BLUE_MANA_TEXT);
}

//____________________________________________________________________________
//
CMerfolkSecretkeeperCard::CMerfolkSecretkeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merfolk Secretkeeper"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		BLUE_MANA_TEXT, Power(0), Life(4))
	, m_Adventure(this)
{
	// Venture Deeper {U}, Sorcery - Adventure: Target player mills four cards.
	counted_ptr<CTargetSpell> cpVenture(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));
	cpVenture->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpVenture->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMerfolkSecretkeeperCard::BeforeMill));
	m_Adventure.SetAdventureSpell(cpVenture.GetPointer(), _T("Venture Deeper"));
	AddSpell(cpVenture.GetPointer());

	m_Adventure.AddCastFromExileSpell(BLUE_MANA_TEXT);
}

bool CMerfolkSecretkeeperCard::BeforeMill(CAbilityAction* pAction)
{
	if (pAction->GetAssociatedPlayer())
		Mill(pAction->GetAssociatedPlayer(), 4);
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CMistfordRiverTurtleCard::CMistfordRiverTurtleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mistford River Turtle"), CardType::Creature, CREATURE_TYPE(Turtle), nID,
		_T("3") BLUE_MANA_TEXT, Power(1), Life(5))
{
	// Whenever this creature attacks, another target attacking non-Human creature can't be blocked this turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CMistfordRiverTurtleCard::BeforeUnblockable, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false)));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CMistfordRiverTurtleCard::BeforeUnblockable(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		pCreature->GetCreatureKeyword()->AddUnblockable(TRUE);
	return false;
}

//____________________________________________________________________________
//
CMoonlitScavengersCard::CMoonlitScavengersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Moonlit Scavengers"), CardType::Creature, CREATURE_TYPE2(Merfolk, Rogue), nID,
		_T("5") BLUE_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, if you control an artifact or enchantment, return target creature an opponent controls to
	// its owner's hand. (the condition is checked when it resolves)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CMoonlitScavengersCard::BeforeBounce, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CMoonlitScavengersCard::BeforeBounce(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardFilter filter(_T("an artifact or enchantment"), _T("artifacts or enchantments"),
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)));
	if (filter.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pTarget);
	return false;
}

//____________________________________________________________________________
//
COkosAccomplicesCard::COkosAccomplicesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Oko's Accomplices"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
}

//____________________________________________________________________________
//
COverwhelmedApprenticeCard::COverwhelmedApprenticeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Overwhelmed Apprentice"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		BLUE_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, each opponent mills two cards. Then you scry 2.
	AddEnterTrigger(this, &COverwhelmedApprenticeCard::BeforeMill);
}

bool COverwhelmedApprenticeCard::BeforeMill(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			Mill(GetGame()->GetPlayer(ip), 2);
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CQueenOfIceCard::CQueenOfIceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Queen of Ice"), CardType::Creature, CREATURE_TYPE3(Human, Noble, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_Adventure(this)
{
	{
		// Whenever this creature deals combat damage to a creature, tap that creature. It doesn't untap during its
		// controller's next untap step. (the creature in nValue1)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CQueenOfIceCard::SetDamageContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CQueenOfIceCard::BeforeTap));
		AddAbility(cpAbility.GetPointer());
	}

	// Rage of Winter {1}{U}, Sorcery - Adventure: Tap target creature. It doesn't untap during its controller's next untap
	// step.
	counted_ptr<CTargetSpell> cpRage(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));
	cpRage->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpRage->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CQueenOfIceCard::BeforeRage));
	m_Adventure.SetAdventureSpell(cpRage.GetPointer(), _T("Rage of Winter"));
	AddSpell(cpRage.GetPointer());

	m_Adventure.AddCastFromExileSpell(_T("2") BLUE_MANA_TEXT);
}

bool CQueenOfIceCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const
{
	if (!pCreature)
		return false;
	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CQueenOfIceCard::BeforeTap(TriggeredAbility::TriggeredActionType* pAction)
{
	TapAndSkipUntap((CCard*)pAction->GetTriggerContext().nValue1);
	return true;
}

bool CQueenOfIceCard::BeforeRage(CAbilityAction* pAction)
{
	TapAndSkipUntap(pAction->GetAssociatedCard());
	return true;	// (the Adventure must resolve to go to exile)
}

//____________________________________________________________________________
//
CSageOfTheFallsCard::CSageOfTheFallsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sage of the Falls"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("4") BLUE_MANA_TEXT, Power(2), Life(5))
{
	// Whenever this creature or another non-Human creature you control enters, you may draw a card. If you do, discard a
	// card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false))));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSageOfTheFallsCard::BeforeLoot));
	AddAbility(cpAbility.GetPointer());
}

bool CSageOfTheFallsCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CShimmerDragonCard::CShimmerDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shimmer Dragon"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(6))
	, m_ArtifactFilter(_T("an untapped artifact"), _T("untapped artifacts"), new CardTypeComparer(CardType::Artifact, false))
{
	{
		// As long as you control four or more artifacts, this creature has hexproof. (as Slippery Scoundrel)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0)));
		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(4);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Tap two untapped artifacts you control: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));
		cpAbility->GetCost().AddTapCardCost(2, &m_ArtifactFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSteelgazeGriffinCard::CSteelgazeGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Steelgaze Griffin"), CardType::Creature, CREATURE_TYPE(Griffin), nID,
		_T("4") BLUE_MANA_TEXT, Power(2), Life(4))
	, m_nTurn(-1)
	, m_nDraws(0)
{
	// Whenever you draw your second card each turn, this creature gets +2/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSteelgazeGriffinCard::SetDrawContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSteelgazeGriffinCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CSteelgazeGriffinCard::SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const
{
	return IsSecondDrawThisTurn(GetGame(), m_nTurn, m_nDraws);
}

bool CSteelgazeGriffinCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, 0);
	return true;
}

//____________________________________________________________________________
//
CSyrElenoraTheDiscerningCard::CSyrElenoraTheDiscerningCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syr Elenora, the Discerning"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(0), Life(4))
{
	// Syr Elenora's power is equal to the number of cards in your hand. (as Maro, Tishana)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, ZoneId::Hand, new TrueCardComparer));
	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());

	// When Syr Elenora enters, draw a card.
	AddEnterTrigger(this, &CSyrElenoraTheDiscerningCard::BeforeDraw);

	// Spells your opponents cast that target Syr Elenora cost {2} more to cast.
	// Not implemented: the engine has no cost increase that depends on the targets.
}

bool CSyrElenoraTheDiscerningCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CTomeRaiderCard::CTomeRaiderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Tome Raider"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CTomeRaiderCard::BeforeDraw);
}

bool CTomeRaiderCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CVantressGargoyleCard::CVantressGargoyleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vantress Gargoyle"), CardType::_ArtifactCreature, CREATURE_TYPE(Gargoyle), nID,
		_T("1") BLUE_MANA_TEXT, Power(5), Life(4))
{
	// This creature can't attack unless defending player has seven or more cards in their graveyard.
	// (the defending player is the opponent, as in a two-player game; pending to test that it's updated)
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new SpecificCardComparer(this), new OpponentGraveyardUnderSevenComparer),
				Power(+0), Life(+0), CreatureKeyword::CantAttack));
		AddAbility(cpAbility.GetPointer());
	}
	// This creature can't block unless you have four or more cards in hand.
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new SpecificCardComparer(this), new HandUnderFourComparer),
				Power(+0), Life(+0), CreatureKeyword::CantBlock));
		AddAbility(cpAbility.GetPointer());
	}
	// {T}: Each player mills a card.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Each player mills a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVantressGargoyleCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVantressGargoyleCard::BeforeMill(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		Mill(GetGame()->GetPlayer(ip), 1);
	return true;
}

//____________________________________________________________________________
//
CVantressPaladinCard::CVantressPaladinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vantress Paladin"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CVantressPaladinCard::OnZoneChanged))
{
	// Adamant - If at least three blue mana was spent to cast this spell, this creature enters with a +1/+1 counter on it.
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CVantressPaladinCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		IsAdamantPermanent(this, CManaPool::Color::Blue))
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
}

//____________________________________________________________________________
//
CWishfulMerfolkCard::CWishfulMerfolkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wishful Merfolk"), CardType::Creature, CREATURE_TYPE(Merfolk), nID,
		_T("1") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {1}{U}: This creature loses defender and becomes a Human until end of turn.
	// Partial: it doesn't become a Human.
	AddPumpAbility(this, _T("1") BLUE_MANA_TEXT, _T("This creature loses defender until end of turn. Activates"),
		&CWishfulMerfolkCard::BeforeLoseDefender);
}

bool CWishfulMerfolkCard::BeforeLoseDefender(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	// (as Piston-Fist Cyclops in Guilds of Ravnica)
	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToRemove(CreatureKeyword::Defender);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CWorkshopEldersCard::CWorkshopEldersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Workshop Elders"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("6") BLUE_MANA_TEXT, Power(4), Life(4))
{
	{
		// Artifact creatures you control have flying.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Artifact, false)),
				Power(+0), Life(+0), CreatureKeyword::Flying));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of combat on your turn, you may have target noncreature artifact you control become a 0/0 artifact
	// creature. If you do, put four +1/+1 counters on it. (up to one target)
	CTargeting* pTargeting = AddStepTargetTrigger<CWorkshopEldersCard>(this, NodeId::BeginningOfCombatStep, NULL,
		&CWorkshopEldersCard::BeforeAnimate, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(NewNoncreatureArtifactComparer());
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->SetSubjectCount(0, 1);
}

bool CWorkshopEldersCard::BeforeAnimate(CAbilityAction* pAction)
{
	AnimateArtifactWithCounters(pAction->GetAssociatedCard(), pAction->GetController(), 4);
	return false;
}

//____________________________________________________________________________
//
// The colors among the permanents the player controls, as a mask (1 white, 2 blue, 4 black, 8 red, 16 green)
static int GetColorsAmongPermanents(CPlayer* pPlayer)
{
	static const CManaPool::Color colors[] = { CManaPool::Color::White, CManaPool::Color::Blue, CManaPool::Color::Black,
		CManaPool::Color::Red, CManaPool::Color::Green };

	int nMask = 0;
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		for (int c = 0; c < 5; ++c)
			if (pBattlefield->GetAt(i)->IsColor(colors[c]))
				nMask |= 1 << c;
	return nMask;
}

BOOL CColorMaskCondition::IsPlayable(BOOL bIncludeTricks)
{
	return GetColorsAmongPermanents(m_pCard->GetController()) == m_nMask;
}

// Adamant with any color: "if at least three mana of the same color was spent to cast it"
static BOOL IsAdamantPermanentAnyColor(const CCard* pCard)
{
	static const CManaPool::Color colors[] = { CManaPool::Color::White, CManaPool::Color::Blue, CManaPool::Color::Black,
		CManaPool::Color::Red, CManaPool::Color::Green };
	for (int c = 0; c < 5; ++c)
		if (IsAdamantPermanent(pCard, colors[c]))
			return TRUE;
	return FALSE;
}

// The creature is equipped by an Equipment its controller controls
static BOOL IsEquippedCreature(const CCard* pCreature)
{
	CPlayer* pController = pCreature->GetController();
	if (!pController)
		return FALSE;
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (CardTypeComparer(CardType::Equipment, false)(pCard) && EquippedByComparer(pCard)(pCreature))
			return TRUE;
	}
	return FALSE;
}

// "You may discard a card. If you do, draw a card."
static void Rummage(CGame* pGame, CPlayer* pPlayer)
{
	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);
	int nBefore = pHand->GetSize();
	ChooseAndMove(pGame, pPlayer, ZoneId::Hand, 0, 1, CCardFilter::GetFilter(_T("cards")), ZoneId::Graveyard, MoveType::Discard);
	if (pHand->GetSize() < nBefore)
		DrawCards(pGame, pPlayer, 1);
}

//____________________________________________________________________________
//
CAlelaArtfulProvocateurCard::CAlelaArtfulProvocateurCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Alela, Artful Provocateur"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Faerie, Warlock), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	{
		// Other creatures you control with flying get +1/+0.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false),
					new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+1), Life(+0)));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast an artifact or enchantment spell, create a 1/1 blue Faerie creature token with flying.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAlelaArtfulProvocateurCard::BeforeFaerie));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAlelaArtfulProvocateurCard::BeforeFaerie(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FAERIE_A_TOKEN_NAME, FAERIE_A_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CArcanistsOwlCard::CArcanistsOwlCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Arcanist's Owl"), CardType::_ArtifactCreature, CREATURE_TYPE(Bird), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_LookFilter(_T("an artifact or enchantment card"), _T("artifact or enchantment cards"),
		new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false)))
{
	// {W/U}{W/U}{W/U}{W/U}
	AddHybridPermanentSpells(this, _T(""), 4, WHITE_MANA_TEXT, BLUE_MANA_TEXT);

	// When this creature enters, look at the top four cards of your library. You may reveal an artifact or enchantment
	// card from among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	AddEnterTrigger(this, &CArcanistsOwlCard::BeforeLook);
}

bool CArcanistsOwlCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHandRestBottom(GetGame(), pAction->GetController(), 4, 0, 1, &m_LookFilter);
	return true;
}

//____________________________________________________________________________
//
CChulaneTellerOfTalesCard::CChulaneTellerOfTalesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Chulane, Teller of Tales"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Druid), nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(4))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	{
		// Whenever you cast a creature spell, draw a card, then you may put a land card from your hand onto the battlefield.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChulaneTellerOfTalesCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}, {T}: Return target creature you control to its owner's hand.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("3"),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));
		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CChulaneTellerOfTalesCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Hand, 0, 1, CCardFilter::GetFilter(_T("lands")),
		ZoneId::Battlefield, MoveType::Others);
	return true;
}

//____________________________________________________________________________
//
CClockworkServantCard::CClockworkServantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Clockwork Servant"), CardType::_ArtifactCreature, CREATURE_TYPE(Gnome), nID,
		_T("3"), Power(2), Life(3))
{
	// Adamant - When this creature enters, if at least three mana of the same color was spent to cast it, draw a card.
	AddEnterIfTrigger(this, &CClockworkServantCard::SetEnterContext, &CClockworkServantCard::BeforeDraw);
}

bool CClockworkServantCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Cast && IsAdamantPermanentAnyColor(this);
}

bool CClockworkServantCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CCrashingDrawbridgeCard::CCrashingDrawbridgeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Crashing Drawbridge"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("2"), Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {T}: Creatures you control gain haste until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Creatures you control gain haste until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrashingDrawbridgeCard::BeforeHaste));
	AddAbility(cpAbility.GetPointer());
}

bool CCrashingDrawbridgeCard::BeforeHaste(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), 0, 0, CreatureKeyword::Haste);
	return true;
}

//____________________________________________________________________________
//
CDeathlessKnightCard::CDeathlessKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deathless Knight"), CardType::Creature, CREATURE_TYPE2(Skeleton, Knight), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(2))
	, m_nTurn(-1)
{
	// {B/G}{B/G}{B/G}{B/G}
	AddHybridPermanentSpells(this, _T(""), 4, BLACK_MANA_TEXT, GREEN_MANA_TEXT);

	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// When you gain life for the first time each turn, return this card from your graveyard to your hand.
	// (a trigger of the card in the graveyard; pending to test)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDeathlessKnightCard::SetLifeContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeathlessKnightCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CDeathlessKnightCard::SetLifeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	if (nToLife <= nFromLife || GetZoneId() != ZoneId::Graveyard || m_nTurn == GetGame()->GetGameTurnNumber())
		return false;

	// The first life gain this turn: the life gained this turn is (at most) this gain
	if (GetController()->GetLifeGainThisTurn() > nToLife - nFromLife)
		return false;

	m_nTurn = GetGame()->GetGameTurnNumber();
	return true;
}

bool CDeathlessKnightCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CEliteHeadhunterCard::CEliteHeadhunterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elite Headhunter"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
	, m_SacrificeFilter(_T("another creature or an artifact"), _T("other creatures or artifacts"),
		new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Artifact, false)))
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// {B/R}{B/R}{B/R}{B/R}
	AddHybridPermanentSpells(this, _T(""), 4, BLACK_MANA_TEXT, RED_MANA_TEXT);

	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// {B/R}{B/R}{B/R}, Sacrifice another creature or an artifact: This creature deals 2 damage to target creature or
	// planeswalker. (one ability for each combination of the hybrid mana, as the Lockets)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 3, BLACK_MANA_TEXT, RED_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				(LPCTSTR)costs[i],
				NewCreatureOrPlaneswalkerComparer(), FALSE));
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEliteHeadhunterCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CEliteHeadhunterCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToCreatureOrPlaneswalker(this, pAction->GetAssociatedCard(), 2);
	return false;
}

//____________________________________________________________________________
//
CFaeburrowElderCard::CFaeburrowElderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Faeburrow Elder"), CardType::Creature, CREATURE_TYPE2(Treefolk, Druid), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(0), Life(0))
{
	static const CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	static LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };

	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// This creature gets +1/+1 for each color among permanents you control. (one +1/+1 for each color, with the condition
	// of controlling a permanent of that color)
	for (int c = 0; c < 5; ++c)
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+1), Life(+1)));
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(colors[c], false));
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(1);
		AddAbility(cpAbility.GetPointer());
	}

	// {T}: For each color among permanents you control, add one mana of that color. (one mana ability for each set of
	// colors, playable only with exactly those colors, as Mox Amber)
	for (int nMask = 1; nMask < 32; ++nMask)
	{
		CString strMana;
		for (int c = 0; c < 5; ++c)
			if (nMask & (1 << c))
				strMana += mana[c];

		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, (LPCTSTR)strMana));
		cpAbility->AddTapCost();

		m_Conditions.push_back(CColorMaskCondition(this, nMask));
		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
				CPlayableIfTrait::PlayableCallback(&m_Conditions.back(), &CColorMaskCondition::IsPlayable)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CFirebornKnightCard::CFirebornKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fireborn Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(2), Life(3))
{
	// {R/W}{R/W}{R/W}{R/W}
	AddHybridPermanentSpells(this, _T(""), 4, RED_MANA_TEXT, WHITE_MANA_TEXT);

	// Double strike
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// {R/W}{R/W}{R/W}{R/W}: This creature gets +1/+1 until end of turn.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 4, RED_MANA_TEXT, WHITE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		AddPumpAbility(this, (LPCTSTR)costs[i], _T("This creature gets +1/+1 until end of turn. Activates"),
			&CFirebornKnightCard::BeforePump);
}

bool CFirebornKnightCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

//____________________________________________________________________________
//
CGingerbruteCard::CGingerbruteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gingerbrute"), CardType::_ArtifactCreature | CardType::Food, CREATURE_TYPE(Golem), nID,
		_T("1"), Power(1), Life(1))
	, m_HasteFilter(_T("a creature with haste"), _T("creatures with haste"), new CreatureKeywordComparer(CreatureKeyword::Haste, false))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// {1}: This creature can't be blocked this turn except by creatures with haste.
	AddPumpAbility(this, _T("1"), _T("This creature can't be blocked this turn except by creatures with haste. Activates"),
		&CGingerbruteCard::BeforeEvasion);

	// {2}, {T}, Sacrifice this creature: You gain 3 life. (as the Food token)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2")));
	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->SetAbilityText(_T("You gain 3 life. Activates"));
	AddAbility(cpAbility.GetPointer());
}

bool CGingerbruteCard::BeforeEvasion(CAbilityAction* pAction)
{
	// (the filter of the creatures that can block it)
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE, &m_HasteFilter);
	return true;
}

//____________________________________________________________________________
//
CGluttonousTrollCard::CGluttonousTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gluttonous Troll"), CardType::Creature, CREATURE_TYPE(Troll), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
	, m_SacrificeFilter(_T("another nonland permanent"), _T("other nonland permanents"),
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, create a number of Food tokens equal to the number of opponents you have.
	AddEnterTrigger(this, &CGluttonousTrollCard::BeforeFood);

	// {1}{G}, Sacrifice another nonland permanent: This creature gets +2/+2 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1") GREEN_MANA_TEXT));
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->SetAbilityText(_T("This creature gets +2/+2 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGluttonousTrollCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CGluttonousTrollCard::BeforeFood(CAbilityAction* pAction)
{
	int nOpponents = GetGame()->GetPlayerCount() - 1;
	if (nOpponents > 0)
		CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, nOpponents).ApplyTo(pAction->GetController());
	return true;
}

bool CGluttonousTrollCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +2);
	return true;
}

//____________________________________________________________________________
//
CGrumgullyTheGenerousCard::CGrumgullyTheGenerousCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grumgully, the Generous"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Goblin, Shaman), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Each other non-Human creature you control enters with an additional +1/+1 counter on it.
	// (the counter is put when it enters, in the context function, without a trigger, as Mysterious Pathlighter)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGrumgullyTheGenerousCard::SetEnterContext));
	AddAbility(cpAbility.GetPointer());
}

bool CGrumgullyTheGenerousCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (pCard && pCard != this && pCard->GetCardType().IsCreature() && !CreatureTypeComparer(CREATURE_TYPE(Human), false)(pCard))
		AddPlusCounter(pCard, 1);
	return false;
}

//____________________________________________________________________________
//
CHengeWalkerCard::CHengeWalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Henge Walker"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("3"), Power(2), Life(2))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CHengeWalkerCard::OnZoneChanged))
{
	// Adamant - If at least three mana of the same color was spent to cast this spell, this creature enters with a +1/+1
	// counter on it.
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CHengeWalkerCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast &&
		IsAdamantPermanentAnyColor(this))
		CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(this);
}

//____________________________________________________________________________
//
CInquisitivePuppetCard::CInquisitivePuppetCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inquisitive Puppet"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("1"), Power(0), Life(2))
{
	// When this creature enters, scry 1.
	AddEnterTrigger(this, &CInquisitivePuppetCard::BeforeScry);

	// Exile this creature: Create a 1/1 white Human creature token.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T(""),
			HUMAN_A_TOKEN_NAME, HUMAN_A_TOKEN_ID, 1));
	cpAbility->AddExileCost();
	AddAbility(cpAbility.GetPointer());
}

bool CInquisitivePuppetCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CInspiringVeteranCard::CInspiringVeteranCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inspiring Veteran"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Other Knights you control get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false), new NegateCardComparer(new SpecificCardComparer(this))),
			Power(+1), Life(+1)));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CJoustingDummyCard::CJoustingDummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jousting Dummy"), CardType::_ArtifactCreature, CREATURE_TYPE2(Scarecrow, Knight), nID,
		_T("2"), Power(2), Life(1))
{
	// {3}: This creature gets +1/+0 until end of turn.
	AddPumpAbility(this, _T("3"), _T("This creature gets +1/+0 until end of turn. Activates"), &CJoustingDummyCard::BeforePump);
}

bool CJoustingDummyCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, 0);
	return true;
}

//____________________________________________________________________________
//
CKorvoldFaeCursedKingCard::CKorvoldFaeCursedKingCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Korvold, Fae-Cursed King"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Dragon, Noble), nID,
		_T("2") BLACK_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_AnotherFilter(_T("another permanent"), _T("other permanents"), new TrueCardComparer)
{
	m_AnotherFilter.AddNegateComparer(new SpecificCardComparer(this));

	// Whenever Korvold enters or attacks, sacrifice another permanent.
	AddEnterTrigger(this, &CKorvoldFaeCursedKingCard::BeforeSacrifice);
	AddSelfAttackTrigger(this, &CKorvoldFaeCursedKingCard::BeforeSacrifice);

	// Whenever you sacrifice a permanent, put a +1/+1 counter on Korvold and draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKorvoldFaeCursedKingCard::SetSacrificeContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKorvoldFaeCursedKingCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CKorvoldFaeCursedKingCard::BeforeSacrifice(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Battlefield, 1, 1, &m_AnotherFilter,
		ZoneId::Graveyard, MoveType::Sacrifice);
	return true;
}

bool CKorvoldFaeCursedKingCard::SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Sacrifice;
}

bool CKorvoldFaeCursedKingCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CLochDragonCard::CLochDragonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Loch Dragon"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// {U/R}{U/R}{U/R}{U/R}
	AddHybridPermanentSpells(this, _T(""), 4, BLUE_MANA_TEXT, RED_MANA_TEXT);

	// Whenever this creature enters or attacks, you may discard a card. If you do, draw a card.
	AddEnterTrigger(this, &CLochDragonCard::BeforeRummage, true);
	AddSelfAttackTrigger(this, &CLochDragonCard::BeforeRummage, true);
}

bool CLochDragonCard::BeforeRummage(CAbilityAction* pAction)
{
	Rummage(GetGame(), pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CLochmereSerpentCard::CLochmereSerpentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lochmere Serpent"), CardType::Creature, CREATURE_TYPE(Serpent), nID,
		_T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(7), Life(7))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	{
		// {U}, Sacrifice an Island: This creature can't be blocked this turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, BLUE_MANA_TEXT));
		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Islands")));
		cpAbility->SetAbilityText(_T("This creature can't be blocked this turn. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLochmereSerpentCard::BeforeUnblockable));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {B}, Sacrifice a Swamp: You gain 1 life and draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, BLACK_MANA_TEXT));
		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("Swamps")));
		cpAbility->SetAbilityText(_T("You gain 1 life and draw a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLochmereSerpentCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {U}{B}: Exile five target cards from an opponent's graveyard. Return this card from your graveyard to your hand.
		// Activate only as a sorcery.
		// Partial: the five cards aren't chosen (the last five cards put into the graveyard).
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, BLUE_MANA_TEXT BLACK_MANA_TEXT));
		cpAbility->SetPlayableFrom(ZoneId::Graveyard);
		cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
		cpAbility->SetAbilityText(_T("Exile five cards from an opponent's graveyard. Return this card from your graveyard to your hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLochmereSerpentCard::BeforeExile));
		AddPlayableIf(this, cpAbility.GetPointer(), &CLochmereSerpentCard::OpponentHasFiveInGraveyard);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLochmereSerpentCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

bool CLochmereSerpentCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

BOOL CLochmereSerpentCard::OpponentHasFiveInGraveyard(BOOL bIncludeTricks)
{
	CPlayer* pOpponent = GetGame()->GetNextPlayer(GetController());
	return pOpponent && pOpponent != GetController() && pOpponent->GetZoneById(ZoneId::Graveyard)->GetSize() >= 5;
}

bool CLochmereSerpentCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAction->GetController());
	if (pOpponent && pOpponent != pAction->GetController())
	{
		CZone* pGraveyard = pOpponent->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < 5 && pGraveyard->GetSize() > 0; ++i)
			CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController())
				.ApplyTo(pGraveyard->GetAt(pGraveyard->GetSize() - 1));
	}

	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CLocthwainGargoyleCard::CLocthwainGargoyleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Locthwain Gargoyle"), CardType::_ArtifactCreature, CREATURE_TYPE(Gargoyle), nID,
		_T("1"), Power(0), Life(3))
{
	// {4}: This creature gets +2/+0 and gains flying until end of turn.
	AddPumpAbility(this, _T("4"), _T("This creature gets +2/+0 and gains flying until end of turn. Activates"),
		&CLocthwainGargoyleCard::BeforePump);
}

bool CLocthwainGargoyleCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, 0, CreatureKeyword::Flying);
	return true;
}

//____________________________________________________________________________
//
CMaraleafPixieCard::CMaraleafPixieCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Maraleaf Pixie"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// {T}: Add {G} or {U}.
	AddTapManaAbility(this, GREEN_MANA_TEXT);
	AddTapManaAbility(this, BLUE_MANA_TEXT);
}

//____________________________________________________________________________
//
COakhameRangerCard::COakhameRangerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oakhame Ranger"), CardType::Creature, CREATURE_TYPE3(Elf, Knight, Ranger), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Adventure(this)
{
	// {G/W}{G/W}{G/W}{G/W}
	AddHybridPermanentSpells(this, _T(""), 4, GREEN_MANA_TEXT, WHITE_MANA_TEXT);

	// {T}: Creatures you control get +1/+1 until end of turn.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Creatures you control get +1/+1 until end of turn. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COakhameRangerCard::BeforePump));
		AddAbility(cpAbility.GetPointer());
	}

	// Bring Back {G/W}{G/W}{G/W}{G/W}, Sorcery - Adventure: Create two 1/1 white Human creature tokens.
	// (one Adventure spell and one spell from exile for each combination of the hybrid mana)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 4, GREEN_MANA_TEXT, WHITE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTokenProductionSpell> cpBring(
			::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
				(LPCTSTR)costs[i],
				HUMAN_A_TOKEN_NAME, HUMAN_A_TOKEN_ID, 2));
		m_Adventure.SetAdventureSpell(cpBring.GetPointer(), _T("Bring Back"));
		AddSpell(cpBring.GetPointer());

		m_Adventure.AddCastFromExileSpell((LPCTSTR)costs[i]);
	}
}

bool COakhameRangerCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, +1);
	return true;
}

//____________________________________________________________________________
//
CProphetOfThePeakCard::CProphetOfThePeakCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prophet of the Peak"), CardType::_ArtifactCreature, CREATURE_TYPE(Cat), nID,
		_T("6"), Power(5), Life(5))
{
	// When this creature enters, scry 2.
	AddEnterTrigger(this, &CProphetOfThePeakCard::BeforeScry);
}

bool CProphetOfThePeakCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CRampartSmasherCard::CRampartSmasherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rampart Smasher"), CardType::Creature, CREATURE_TYPE(Giant), nID,
		RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(5))
	, m_BlockerFilter(_T("a creature that isn't a Knight or Wall"), _T("creatures that aren't Knights or Walls"),
		new AndCardComparer(new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false)),
			new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Wall), false))))
{
	// {R/G}{R/G}{R/G}{R/G}
	AddHybridPermanentSpells(this, _T(""), 4, RED_MANA_TEXT, GREEN_MANA_TEXT);

	// This creature can't be blocked by Knights or Walls. (the filter of the creatures that can block it)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_BlockerFilter);
}

//____________________________________________________________________________
//
CResoluteRiderCard::CResoluteRiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Resolute Rider"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(2))
{
	// {W/B}{W/B}{W/B}{W/B}
	AddHybridPermanentSpells(this, _T(""), 4, WHITE_MANA_TEXT, BLACK_MANA_TEXT);

	// {W/B}{W/B}: This creature gains lifelink until end of turn.
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, WHITE_MANA_TEXT, BLACK_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		AddPumpAbility(this, (LPCTSTR)costs[i], _T("This creature gains lifelink until end of turn. Activates"),
			&CResoluteRiderCard::BeforeLifelink);

	// {W/B}{W/B}{W/B}: This creature gains indestructible until end of turn.
	costs.clear();
	GetHybridCosts(_T(""), 3, WHITE_MANA_TEXT, BLACK_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		AddPumpAbility(this, (LPCTSTR)costs[i], _T("This creature gains indestructible until end of turn. Activates"),
			&CResoluteRiderCard::BeforeIndestructible);
}

bool CResoluteRiderCard::BeforeLifelink(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCardKeyword()->AddLifelink(TRUE);
	return true;
}

bool CResoluteRiderCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCardKeyword()->AddIndestructible(TRUE);
	return true;
}

//____________________________________________________________________________
//
CRovingKeepCard::CRovingKeepCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Roving Keep"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("7"), Power(5), Life(7))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {7}: This creature gets +2/+0 and gains trample until end of turn. It can attack this turn as though it didn't have
	// defender.
	AddPumpAbility(this, _T("7"), _T("This creature gets +2/+0 and gains trample until end of turn. It can attack this turn. Activates"),
		&CRovingKeepCard::BeforePump);
}

bool CRovingKeepCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;
	PumpCreature(this, +2, 0, CreatureKeyword::Trample);
	GetCreatureKeyword()->AddDefenderMayAttack(TRUE);
	return true;
}

//____________________________________________________________________________
//
CSavvyHunterCard::CSavvyHunterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Savvy Hunter"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	{
		// Whenever this creature attacks or blocks, create a Food token. (as Inferno Hellion in M19)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
							   CWhenSelfAttackedBlocked::EventCallback, &CWhenSelfAttackedBlocked::SetAttackingOrBlockingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSavvyHunterCard::BeforeFood));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Sacrifice two Foods: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));
		cpAbility->GetCost().AddSacrificeCardCost(2, CCardFilter::GetFilter(_T("Foods")));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSavvyHunterCard::BeforeFood(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), FOOD_TOKEN_NAME, FOOD_TOKEN_ID, 1).ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
CShamblingSuitCard::CShamblingSuitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shambling Suit"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(0), Life(3))
{
	// Shambling Suit's power is equal to the number of artifacts and/or enchantments you control.
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, ZoneId::Battlefield,
			new OrCardComparer(new CardTypeComparer(CardType::Artifact, false), new CardTypeComparer(CardType::_Enchantment, false))));
	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CShinechaserCard::CShinechaserCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shinechaser"), CardType::Creature, CREATURE_TYPE(Faerie), nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(1))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// This creature gets +1/+1 as long as you control an artifact.
	// This creature gets +1/+1 as long as you control an enchantment.
	CardType types[] = { CardType::Artifact, CardType::_Enchantment };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+1), Life(+1)));
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(types[i], false));
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(1);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSignpostScarecrowCard::CSignpostScarecrowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Signpost Scarecrow"), CardType::_ArtifactCreature, CREATURE_TYPE(Scarecrow), nID,
		_T("4"), Power(2), Life(4))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// {2}: Add one mana of any color.
	LPCTSTR mana[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("2"), AbilityType::Activated, mana[i]));
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSorcerersBroomCard::CSorcerersBroomCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sorcerer's Broom"), CardType::_ArtifactCreature, CREATURE_TYPE(Spirit), nID,
		_T("2"), Power(2), Life(1))
{
	// Whenever you sacrifice another permanent, you may pay {3}. If you do, create a token that's a copy of this creature.
	// (the payment and the copy as Mishra's Self-Replicator in Dominaria)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T("3"));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSorcerersBroomCard::SetSacrificeContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorcerersBroomCard::BeforeCopy));
	AddAbility(cpAbility.GetPointer());
}

bool CSorcerersBroomCard::SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard != this && moveType == MoveType::Sacrifice;
}

bool CSorcerersBroomCard::BeforeCopy(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCopyModifier(GetGame(), this).ApplyTo(this);
	return true;
}

//____________________________________________________________________________
//
CStonecoilSerpentCard::CStonecoilSerpentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stonecoil Serpent"), CardType::_ArtifactCreature, CREATURE_TYPE(Snake), nID,
		_T(""), Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CStonecoilSerpentCard::OnZoneChanged))
	, m_nX(0)
{
	// {X}. This creature enters with X +1/+1 counters on it. (as Hydroid Krasis in Ravnica Allegiance)
	AddPlayableIf(this, GetSpells().GetAt(0), &CStonecoilSerpentCard::Never);

	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Creature, _T("")));
	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStonecoilSerpentCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// Reach, trample, protection from multicolored
	// Partial: without the protection from multicolored.
	GetCreatureKeyword()->AddReach(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
}

bool CStonecoilSerpentCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	return true;
}

void CStonecoilSerpentCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
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
CStormfistCrusaderCard::CStormfistCrusaderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stormfist Crusader"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// At the beginning of your upkeep, each player draws a card and loses 1 life.
	AddStepTrigger<CStormfistCrusaderCard>(this, NodeId::UpkeepStep, false, NULL, &CStormfistCrusaderCard::BeforeDraw);
}

bool CStormfistCrusaderCard::BeforeDraw(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		DrawCards(GetGame(), GetGame()->GetPlayer(ip), 1);
		LoseLife(this, GetGame()->GetPlayer(ip), 1);
	}
	return true;
}

//____________________________________________________________________________
//
CSyrGwynHeroOfAshvaleCard::CSyrGwynHeroOfAshvaleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syr Gwyn, Hero of Ashvale"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") RED_MANA_TEXT WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(5))
{
	// Vigilance, menace
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Whenever an equipped creature you control attacks, you draw a card and you lose 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSyrGwynHeroOfAshvaleCard::SetAttackContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSyrGwynHeroOfAshvaleCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());

	// Equipment you control have equip Knight {0}.
	// Not implemented: the engine can't grant equip abilities.
}

bool CSyrGwynHeroOfAshvaleCard::SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, AttackSubject attackSubject) const
{
	return pCreature && pCreature->GetController() == GetController() && IsEquippedCreature(pCreature);
}

bool CSyrGwynHeroOfAshvaleCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	LoseLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CThunderousSnapperCard::CThunderousSnapperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thunderous Snapper"), CardType::Creature, CREATURE_TYPE2(Turtle, Hydra), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// {G/U}{G/U}{G/U}{G/U}
	AddHybridPermanentSpells(this, _T(""), 4, GREEN_MANA_TEXT, BLUE_MANA_TEXT);

	// Whenever you cast a spell with mana value 5 or greater, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new ConvertedManaCostComparer<std::greater_equal<int>>(5));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThunderousSnapperCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CThunderousSnapperCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
CWandermareCard::CWandermareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wandermare"), CardType::Creature, CREATURE_TYPE(Horse), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Whenever you cast a creature spell that has an Adventure, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWandermareCard::SetCastContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWandermareCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CWandermareCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return IsAdventureCreatureSpell(GetGame(), pCard) == TRUE;
}

bool CWandermareCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this, 1);
	return true;
}

//____________________________________________________________________________
//
CWintermoorCommanderCard::CWintermoorCommanderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wintermoor Commander"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(0))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Wintermoor Commander's toughness is equal to the number of Knights you control.
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, ZoneId::Battlefield,
			new CreatureTypeComparer(CREATURE_TYPE(Knight), false)));
	cpAbility->SetChangeToughnessOnly();
	AddAbility(cpAbility.GetPointer());

	// Whenever this creature attacks, another target Knight you control gains indestructible until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CWintermoorCommanderCard::BeforeIndestructible, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Knight), false));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CWintermoorCommanderCard::BeforeIndestructible(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetZoneId() == ZoneId::Battlefield)
		pTarget->GetCardKeyword()->AddIndestructible(TRUE);
	return false;
}

//____________________________________________________________________________
//
