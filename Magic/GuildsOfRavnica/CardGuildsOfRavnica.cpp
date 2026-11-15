#include "stdafx.h"
#include "CardGuildsOfRavnica.h"

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
		DEFINE_CARD(CGatewayPlazaCard);
		DEFINE_CARD(CGuildmagesForumCard);
		DEFINE_CARD(CRalCallerOfStormsCard);
		DEFINE_CARD(CRalIzzetViceroyCard);
		DEFINE_CARD(CVraskaGolgariQueenCard);
		DEFINE_CARD(CVraskaRegalGorgonCard);
		DEFINE_CARD(CCandlelightVigilCard);
		DEFINE_CARD(CCaptureSphereCard);
		DEFINE_CARD(CConclaveTribunalCard);
		DEFINE_CARD(CDawnOfHopeCard);
		DEFINE_CARD(CDemotionCard);
		DEFINE_CARD(CDisinformationCampaignCard);
		DEFINE_CARD(CDrownedSecretsCard);
		DEFINE_CARD(CEnhancedSurveillanceCard);
		DEFINE_CARD(CFiremindsResearchCard);
		DEFINE_CARD(CGuildSummitCard);
		DEFINE_CARD(CStreetRiotCard);
		DEFINE_CARD(CUrbanUtopiaCard);
		DEFINE_CARD(CBorosLocketCard);
		DEFINE_CARD(CDimirLocketCard);
		DEFINE_CARD(CGolgariLocketCard);
		DEFINE_CARD(CIzzetLocketCard);
		DEFINE_CARD(CSelesnyaLocketCard);
		DEFINE_CARD(CGlaiveOfTheGuildpactCard);
		DEFINE_CARD(CSilentDartCard);
		DEFINE_CARD(CWandOfVertebraeCard);
		DEFINE_CARD(CBeaconBoltCard);
		DEFINE_CARD(CCamaraderieCard);
		DEFINE_CARD(CCircuitousRouteCard);
		DEFINE_CARD(CCitywideBustCard);
		DEFINE_CARD(CConniveConcoctCard);
		DEFINE_CARD(CCosmotronicWaveCard);
		DEFINE_CARD(CCreepingChillCard);
		DEFINE_CARD(CDeadlyVisitCard);
		DEFINE_CARD(CDeafeningClarionCard);
		DEFINE_CARD(CDirectCurrentCard);
		DEFINE_CARD(CDiscoveryDispersalCard);
		DEFINE_CARD(CFindFinalityCard);
		DEFINE_CARD(CFlowerFlourishCard);
		DEFINE_CARD(CGirdForBattleCard);
		DEFINE_CARD(CGraviticPunchCard);
		DEFINE_CARD(CGruesomeMenagerieCard);
		DEFINE_CARD(CLavaCoilCard);
		DEFINE_CARD(CMaximizeAltitudeCard);
		DEFINE_CARD(CMaximizeVelocityCard);
		DEFINE_CARD(CMephiticVaporsCard);
		DEFINE_CARD(CNeverHappenedCard);
		DEFINE_CARD(CNotionRainCard);
		DEFINE_CARD(CPrecisionBoltCard);
		DEFINE_CARD(CQuasiduplicateCard);
		DEFINE_CARD(CResponseResurgenceCard);
		DEFINE_CARD(CRitualOfSootCard);
		DEFINE_CARD(CSeveredStrandsCard);
		DEFINE_CARD(CSproutingRenewalCard);
		DEFINE_CARD(CSwornCompanionsCard);
		DEFINE_CARD(CThoughtErasureCard);
		DEFINE_CARD(CUndercityUprisingCard);
		DEFINE_CARD(CViciousRumorsCard);
		DEFINE_CARD(CVividRevivalCard);
		DEFINE_CARD(CVraskasStoneglareCard);
		DEFINE_CARD(CArtfulTakedownCard);
		DEFINE_CARD(CAssassinsTrophyCard);
		DEFINE_CARD(CAssureAssembleCard);
		DEFINE_CARD(CBountyOfMightCard);
		DEFINE_CARD(CChanceForGloryCard);
		DEFINE_CARD(CChemistersInsightCard);
		DEFINE_CARD(CCollarTheCulpritCard);
		DEFINE_CARD(CCommandTheStormCard);
		DEFINE_CARD(CCrushContrabandCard);
		DEFINE_CARD(CDazzlingLightsCard);
		DEFINE_CARD(CDeviousCoverUpCard);
		DEFINE_CARD(CExpansionExplosionCard);
		DEFINE_CARD(CHypothesizzleCard);
		DEFINE_CARD(CInescapableBlazeCard);
		DEFINE_CARD(CIntegrityInterventionCard);
		DEFINE_CARD(CInvertInventCard);
		DEFINE_CARD(CIonizeCard);
		DEFINE_CARD(CJoinShieldsCard);
		DEFINE_CARD(CJusticeStrikeCard);
		DEFINE_CARD(CMarchOfTheMultitudesCard);
		DEFINE_CARD(CMausoleumSecretsCard);
		DEFINE_CARD(CNecroticWoundCard);
		DEFINE_CARD(CPacksFavorCard);
		DEFINE_CARD(CPauseForReflectionCard);
		DEFINE_CARD(CPriceOfFameCard);
		DEFINE_CARD(CRadicalIdeaCard);
		DEFINE_CARD(CRalsDispersalCard);
		DEFINE_CARD(CRiskFactorCard);
		DEFINE_CARD(CSinisterSabotageCard);
		DEFINE_CARD(CSonicAssaultCard);
		DEFINE_CARD(CStatusStatueCard);
		DEFINE_CARD(CTakeHeartCard);
		DEFINE_CARD(CUnexplainedDisappearanceCard);
		DEFINE_CARD(CBladeInstructorCard);
		DEFINE_CARD(CBountyAgentCard);
		DEFINE_CARD(CFlightOfEquenautsCard);
		DEFINE_CARD(CHaazdaMarshalCard);
		DEFINE_CARD(CHealersHawkCard);
		DEFINE_CARD(CHuntedWitnessCard);
		DEFINE_CARD(CInspiringUnicornCard);
		DEFINE_CARD(CIntrusivePackbeastCard);
		DEFINE_CARD(CLedevGuardianCard);
		DEFINE_CARD(CLightOfTheLegionCard);
		DEFINE_CARD(CLoxodonRestorerCard);
		DEFINE_CARD(CParhelionPatrolCard);
		DEFINE_CARD(CRocChargerCard);
		DEFINE_CARD(CSkylineScoutCard);
		DEFINE_CARD(CSunhomeStalwartCard);
		DEFINE_CARD(CTenthDistrictGuardCard);
		DEFINE_CARD(CVeneratedLoxodonCard);
		DEFINE_CARD(CAffectionateIndrikCard);
		DEFINE_CARD(CArboretumElementalCard);
		DEFINE_CARD(CBeastWhispererCard);
		DEFINE_CARD(CDevkarinDissidentCard);
		DEFINE_CARD(CDistrictGuideCard);
		DEFINE_CARD(CGenerousStrayCard);
		DEFINE_CARD(CGolgariRaidersCard);
		DEFINE_CARD(CGrapplingSundewCard);
		DEFINE_CARD(CHatcherySpiderCard);
		DEFINE_CARD(CImperviousGreatwurmCard);
		DEFINE_CARD(CKraulForagersCard);
		DEFINE_CARD(CKraulHarpoonerCard);
		DEFINE_CARD(CNullhideFeroxCard);
		DEFINE_CARD(CPeltCollectorCard);
		DEFINE_CARD(CPortcullisVineCard);
		DEFINE_CARD(CSiegeWurmCard);
		DEFINE_CARD(CVigorsporeWurmCard);
		DEFINE_CARD(CWaryOkapiCard);
		DEFINE_CARD(CWildCeratokCard);
		DEFINE_CARD(CArclightPhoenixCard);
		DEFINE_CARD(CBargingSergeantCard);
		DEFINE_CARD(CBookDevourerCard);
		DEFINE_CARD(CElectrostaticFieldCard);
		DEFINE_CARD(CErraticCyclopsCard);
		DEFINE_CARD(CFearlessHalberdierCard);
		DEFINE_CARD(CFireUrchinCard);
		DEFINE_CARD(CGoblinBanneretCard);
		DEFINE_CARD(CGoblinCratermakerCard);
		DEFINE_CARD(CGoblinLocksmithCard);
		DEFINE_CARD(CHellkiteWhelpCard);
		DEFINE_CARD(CLegionWarbossCard);
		DEFINE_CARD(COrneryGoblinCard);
		DEFINE_CARD(CRubblebeltBoarCard);
		DEFINE_CARD(CRunawaySteamKinCard);
		DEFINE_CARD(CSmeltWardMinotaurCard);
		DEFINE_CARD(CTorchCourierCard);
		DEFINE_CARD(CWojekBodyguardCard);
		DEFINE_CARD(CBarrierOfBonesCard);
		DEFINE_CARD(CBartizanBatsCard);
		DEFINE_CARD(CBloodOperativeCard);
		DEFINE_CARD(CBurglarRatCard);
		DEFINE_CARD(CDoomWhispererCard);
		DEFINE_CARD(CDouserOfLightsCard);
		DEFINE_CARD(CHiredPoisonerCard);
		DEFINE_CARD(CKraulRaiderCard);
		DEFINE_CARD(CKraulSwarmCard);
		DEFINE_CARD(CLotlethGiantCard);
		DEFINE_CARD(CMidnightReaperCard);
		DEFINE_CARD(CMoodmarkPainterCard);
		DEFINE_CARD(CPilferingImpCard);
		DEFINE_CARD(CPlaguecrafterCard);
		DEFINE_CARD(CSpinalCentipedeCard);
		DEFINE_CARD(CUndercityNecroliskCard);
		DEFINE_CARD(CVeiledShadeCard);
		DEFINE_CARD(CWhisperingSnitchCard);
		DEFINE_CARD(CCitywatchSphinxCard);
		DEFINE_CARD(CDimirInformantCard);
		DEFINE_CARD(CDreamEaterCard);
		DEFINE_CARD(CLeapfrogCard);
		DEFINE_CARD(CMurmuringMysticCard);
		DEFINE_CARD(CMuseDrakeCard);
		DEFINE_CARD(CNightveilSpriteCard);
		DEFINE_CARD(CPasswallAdeptCard);
		DEFINE_CARD(CThoughtboundPhantasmCard);
		DEFINE_CARD(CVedalkenMesmeristCard);
		DEFINE_CARD(CWatcherInTheMistCard);
		DEFINE_CARD(CWishcoinCrabCard);
		DEFINE_CARD(CAttendantOfVraskaCard);
		DEFINE_CARD(CAureliaExemplarOfJusticeCard);
		DEFINE_CARD(CBorosChallengerCard);
		DEFINE_CARD(CCentaurPeacemakerCard);
		DEFINE_CARD(CCharnelTrollCard);
		DEFINE_CARD(CConclaveCavalierCard);
		DEFINE_CARD(CConclaveGuildmageCard);
		DEFINE_CARD(CCracklingDrakeCard);
		DEFINE_CARD(CDarkbladeAgentCard);
		DEFINE_CARD(CDimirSpybugCard);
		DEFINE_CARD(CEmmaraSoulOfTheAccordCard);
		DEFINE_CARD(CErstwhileTrooperCard);
		DEFINE_CARD(CEtrataTheSilencerCard);
		DEFINE_CARD(CFreshFacedRecruitCard);
		DEFINE_CARD(CGarrisonSergeantCard);
		DEFINE_CARD(CGatekeeperGargoyleCard);
		DEFINE_CARD(CGlowsporeShamanCard);
		DEFINE_CARD(CGolgariFindbrokerCard);
		DEFINE_CARD(CHammerDropperCard);
		DEFINE_CARD(CHouseGuildmageCard);
		DEFINE_CARD(CIzoniThousandEyedCard);
		DEFINE_CARD(CKnightOfAutumnCard);
		DEFINE_CARD(CLazavTheMultifariousCard);
		DEFINE_CARD(CLeagueGuildmageCard);
		DEFINE_CARD(CLedevChampionCard);
		DEFINE_CARD(CLegionGuildmageCard);
		DEFINE_CARD(CMolderhulkCard);
		DEFINE_CARD(CNightveilPredatorCard);
		DEFINE_CARD(CNivMizzetParunCard);
		DEFINE_CARD(COchranAssassinCard);
		DEFINE_CARD(CPistonFistCyclopsCard);
		DEFINE_CARD(CPitilessGorgonCard);
		DEFINE_CARD(CRalsStaticasterCard);
		DEFINE_CARD(CRampagingMonumentCard);
		DEFINE_CARD(CRhizomeLurcherCard);
		DEFINE_CARD(CRosemaneCentaurCard);
		DEFINE_CARD(CSumalaWoodshaperCard);
		DEFINE_CARD(CSwarmGuildmageCard);
		DEFINE_CARD(CSwathcutterGiantCard);
		DEFINE_CARD(CSwiftbladeVindicatorCard);
		DEFINE_CARD(CTajicLegionsEdgeCard);
		DEFINE_CARD(CTrostaniDiscordantCard);
		DEFINE_CARD(CTruefireCaptainCard);
		DEFINE_CARD(CUnderrealmLichCard);
		DEFINE_CARD(CVernadiShieldmateCard);
		DEFINE_CARD(CWhisperAgentCard);
		DEFINE_CARD(CWorldsoulColossusCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Guilds of Ravnica mechanics (see no_vale/PATRONES_MOTOR.md)

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

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

CGatewayPlazaCard::CGatewayPlazaCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Gateway Plaza"), nID, CardType::_GateLand)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add one mana of any color.
	AddAnyColorManaAbility(this);

	// When this land enters, sacrifice it unless you pay {1}. (as Rupture Spire in Conflux)
	typedef
		TTriggeredAbility< CTriggeredCreateTemporaryAbilityAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback,
						   &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetCreateAbilityCallback(
		CCreateTempTriggeredAbilityAbility::CreateAbilityCallback2(this,
			&CGatewayPlazaCard::CreateTemporaryAbility), _T("1"),
		CCreateTempTriggeredAbilityAbility::PreRemoveAbilityCallback(this,
			&CGatewayPlazaCard::PreRemoveAbilityCallback));

	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	AddAbility(cpAbility.GetPointer());
}

CCard* CGatewayPlazaCard::CreateTemporaryAbility()
{
	return this;
}

void CGatewayPlazaCard::PreRemoveAbilityCallback(CCard* pCard, CPlayer* pTriggeredPlayer)
{
	CMoveCardModifier modifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice);
	modifier.ApplyTo(pCard);
}

CGuildmagesForumCard::CGuildmagesForumCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Guildmages' Forum"), nID)
{
	// {T}: Add {C}.
	AddTapManaAbility(this, _T("1"));

	// {1}, {T}: Add one mana of any color. If that mana is spent on a multicolored creature spell, that creature enters
	// with an additional +1/+1 counter on it.
	// Partial: the mana has no effect when it's spent (the engine has no restricted or tracked mana)
	static LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("1"), AbilityType::Activated, colors[i]));

		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

#define RAL_IZZET_VICEROY_EMBLEM_NAME		_T("Ral, Izzet Viceroy Emblem")
#define RAL_IZZET_VICEROY_EMBLEM_ID			61158
#define VRASKA_GOLGARI_QUEEN_EMBLEM_NAME	_T("Vraska, Golgari Queen Emblem")
#define VRASKA_GOLGARI_QUEEN_EMBLEM_ID		61159

CRalCallerOfStormsCard::CRalCallerOfStormsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ral, Caller of Storms"), nID,
		_T("4") BLUE_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Ral, 4)
{
	// +1: Draw a card.
	AddLoyaltyAbility(this, +1, _T("+1: Draw a card. Activates"), &CRalCallerOfStormsCard::BeforeDraw);

	{
		// -2: Ral deals 3 damage divided as you choose among one, two, or three targets. (as Forked Bolt)
		// Note: it can't target planeswalkers
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-3), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetSubjectCount(1, 3);
		cpAbility->GetTargeting()->SetDistributeValues();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -7: Draw seven cards. Ral deals 7 damage to each creature your opponents control.
	AddLoyaltyAbility(this, -7, _T("-7: Draw seven cards and 7 damage to each creature your opponents control. Activates"),
		&CRalCallerOfStormsCard::BeforeUltimate);
}

bool CRalCallerOfStormsCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CRalCallerOfStormsCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 7);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 7);
	return true;
}

CRalIzzetViceroyCard::CRalIzzetViceroyCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ral, Izzet Viceroy"), nID,
		_T("3") BLUE_MANA_TEXT RED_MANA_TEXT, PlaneswalkerType::Ral, 5)
{
	// +1: Look at the top two cards of your library. Put one of them into your hand and the other into your graveyard.
	AddLoyaltyAbility(this, +1, _T("+1: Look at the top two cards. Activates"), &CRalIzzetViceroyCard::BeforeLook);

	{
		// -3: Ral deals damage to target creature equal to the total number of instant and sorcery cards you own in exile
		// and in your graveyard.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRalIzzetViceroyCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// -8: You get an emblem with "Whenever you cast an instant or sorcery spell, this emblem deals 4 damage to any target
	// and you draw two cards."
	AddEmblemLoyaltyAbility(this, -8, RAL_IZZET_VICEROY_EMBLEM_NAME, RAL_IZZET_VICEROY_EMBLEM_ID,
		_T("You get an emblem with \"Whenever you cast an instant or sorcery spell, this emblem deals 4 damage to any target and you draw two cards.\" Activates"));
}

bool CRalIzzetViceroyCard::BeforeLook(CAbilityAction* pAction)
{
	// One card into the hand, the other into the graveyard
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 2, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::PrimaryPlayer, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Hand, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.SetReorderInformation(true, ZoneId::Graveyard, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CRalIzzetViceroyCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pController = pAction->GetController();
	const CCardFilter* pFilter = CCardFilter::GetFilter(_T("instant cards or sorcery cards"));
	int nCount = pFilter->CountIncluded(pController->GetZoneById(ZoneId::Graveyard)->GetCardContainer())
		+ pFilter->CountIncluded(pController->GetZoneById(ZoneId::Exile)->GetCardContainer());
	if (nCount > 0)
		DealDamageToCreature(this, pCard, nCount);
	return false;
}

CVraskaGolgariQueenCard::CVraskaGolgariQueenCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vraska, Golgari Queen"), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Vraska, 4)
	, m_OtherPermanentFilter(_T("another permanent"), _T("other permanents"), new NegateCardComparer(new SpecificCardComparer(this)))
{
	// +2: You may sacrifice another permanent. If you do, you gain 1 life and draw a card.
	AddLoyaltyAbility(this, +2, _T("+2: You may sacrifice another permanent to gain 1 life and draw a card. Activates"),
		&CVraskaGolgariQueenCard::BeforeSacrifice);

	{
		// -3: Destroy target nonland permanent with mana value 3 or less.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AndCardComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
					new ConvertedManaCostComparer<std::less_equal<int>>(3)),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}

	// -9: You get an emblem with "Whenever a creature you control deals combat damage to a player, that player loses the
	// game."
	AddEmblemLoyaltyAbility(this, -9, VRASKA_GOLGARI_QUEEN_EMBLEM_NAME, VRASKA_GOLGARI_QUEEN_EMBLEM_ID,
		_T("You get an emblem with \"Whenever a creature you control deals combat damage to a player, that player loses the game.\" Activates"));
}

bool CVraskaGolgariQueenCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	if (m_OtherPermanentFilter.CountIncluded(pBattlefield->GetCardContainer()) == 0)
		return true;

	int nBefore = pBattlefield->GetSize();
	ChooseAndMove(GetGame(), pController, ZoneId::Battlefield, 0, 1, &m_OtherPermanentFilter, ZoneId::Graveyard, MoveType::Sacrifice);
	if (pBattlefield->GetSize() < nBefore)
	{
		GainLife(this, pController, 1);
		DrawCards(GetGame(), pController, 1);
	}
	return true;
}

CVraskaRegalGorgonCard::CVraskaRegalGorgonCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vraska, Regal Gorgon"), nID,
		_T("5") BLACK_MANA_TEXT GREEN_MANA_TEXT, PlaneswalkerType::Vraska, 5)
{
	{
		// +2: Put a +1/+1 counter on up to one target creature. That creature gains menace until end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVraskaRegalGorgonCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
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

	// -10: For each creature card in your graveyard, put a +1/+1 counter on each creature you control.
	AddLoyaltyAbility(this, -10, _T("-10: +1/+1 counters for each creature card in your graveyard. Activates"),
		&CVraskaRegalGorgonCard::BeforeUltimate);
}

bool CVraskaRegalGorgonCard::BeforeCounter(CAbilityAction* pAction)
{
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (!pTargetAction)
		return false;

	CCountedCardContainer targets;
	pTargetAction->GetTargetGroup().GetCardSubjects(targets);
	for (int i = 0; i < targets.GetSize(); ++i)
	{
		CCard* pCard = targets.GetAt(i);
		if (pCard->GetZoneId() == ZoneId::Battlefield)
		{
			CCardCounterModifier(_T("+1/+1"), +1).ApplyTo(pCard);
			PumpCreature(pCard, +0, +0, CreatureKeyword::CantBeBlockedBy1);
		}
	}
	return false;
}

bool CVraskaRegalGorgonCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = CountCreatureCardsInGraveyard(pController);
	if (nCount <= 0)
		return true;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		CCardCounterModifier(_T("+1/+1"), nCount).ApplyTo(creatures.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

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

CCandlelightVigilCard::CCandlelightVigilCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Candlelight Vigil"), nID,
		_T("3") WHITE_MANA_TEXT,
		Power(+3), Life(+2), CreatureKeyword::Vigilance)
{
	// Enchant creature. Enchanted creature gets +3/+2 and has vigilance.
}

CCaptureSphereCard::CCaptureSphereCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Capture Sphere"), nID,
		_T("3") BLUE_MANA_TEXT,
		Power(+0), Life(+0))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CCaptureSphereCard::OnResolutionCompleted))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Enchant creature. When this Aura enters, tap enchanted creature. Enchanted creature doesn't untap during its
	// controller's untap step. (as Claustrophobia in M14)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
	m_pChgPwrTghAttrEnchant->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
}

void CCaptureSphereCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	CCard* pTarget = pAbilityAction->GetAssociatedCard();
	if (bResult && pTarget)
		CCardOrientationModifier(TRUE).ApplyTo(pTarget);
}

CConclaveTribunalCard::CConclaveTribunalCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Conclave Tribunal"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Convoke (partial: the creatures pay only generic mana)
	AddConvokeSpells(this, 3, WHITE_MANA_TEXT, &CConclaveTribunalCard::AddConvokeSpell, 1);

	// When this enchantment enters, exile target nonland permanent an opponent controls until this enchantment leaves
	// the battlefield. (as Hieromancer's Cage in M19)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConclaveTribunalCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());

	AddLeaveTrigger(this, &CConclaveTribunalCard::BeforeReturn);
}

void CConclaveTribunalCard::AddConvokeSpell(LPCTSTR strCost, int nTapped)
{
	counted_ptr<CSpell> cpSpell(::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), strCost, TRUE));
	SetConvoke(cpSpell.GetPointer(), nTapped);
	AddSpell(cpSpell.GetPointer());
}

bool CConclaveTribunalCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CConclaveTribunalCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CDawnOfHopeCard::CDawnOfHopeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dawn of Hope"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you gain life, you may pay {2}. If you do, draw a card. (as Ajani's Pridemate in M11)
	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("2"));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDawnOfHopeCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDawnOfHopeCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}

	// {3}{W}: Create a 1/1 white Soldier creature token with lifelink.
	{
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this, _T("3") WHITE_MANA_TEXT,
				_T("Soldier (T)"), 55118, 1));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDawnOfHopeCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

bool CDawnOfHopeCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDemotionCard::CDemotionCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Demotion"), nID,
		WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantBlock)
	, m_CardFilter(_T("enchanted by this"), _T("enchanted by this"), new EnchantedByComparer(this))
{
	// Enchant creature. Enchanted creature can't block, and its activated abilities can't be activated.
	// (as Arrest in Mercadian Masques)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	CCantActivateAbilitiesModifier* pModifier = new CCantActivateAbilitiesModifier(GetGame(), &m_CardFilter);
	m_pChgPwrTghAttrEnchant->GetCreatureKeywordMod().LinkCardModifier(pModifier);
}

CDisinformationCampaignCard::CDisinformationCampaignCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Disinformation Campaign"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, you draw a card and each opponent discards a card.
	AddEnterTrigger(this, &CDisinformationCampaignCard::BeforeDrawDiscard);

	// Whenever you surveil, return this enchantment to its owner's hand.
	AddWheneverYouSurveilTrigger(this, &CDisinformationCampaignCard::BeforeReturn);
}

bool CDisinformationCampaignCard::BeforeDrawDiscard(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);

	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(i);
		if (pPlayer != pController)
			DiscardCards(GetGame(), pPlayer, 1);
	}
	return true;
}

bool CDisinformationCampaignCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(this);
	return true;
}

CDrownedSecretsCard::CDrownedSecretsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Drowned Secrets"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast a blue spell, target player mills two cards.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Blue, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDrownedSecretsCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CDrownedSecretsCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 2);
	return false;
}

CEnhancedSurveillanceCard::CEnhancedSurveillanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Enhanced Surveillance"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// You may look at an additional two cards each time you surveil.
	// (in the core: CSurveilModifier looks at two more cards for each Enhanced Surveillance the player controls)

	// Exile this enchantment: Shuffle your graveyard into your library.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->AddExileCost();
	cpAbility->SetAbilityText(_T("Shuffle your graveyard into your library"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEnhancedSurveillanceCard::BeforeShuffle));
	AddAbility(cpAbility.GetPointer());
}

bool CEnhancedSurveillanceCard::BeforeShuffle(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer cards;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < cards.GetSize(); ++i)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pController).ApplyTo(cards.GetAt(i));

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CFiremindsResearchCard::CFiremindsResearchCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Firemind's Research"), CardType::GlobalEnchantment, nID,
		BLUE_MANA_TEXT RED_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast an instant or sorcery spell, put a charge counter on this enchantment.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFiremindsResearchCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// {1}{U}, Remove two charge counters from this enchantment: Draw a card.
	{
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("1") BLUE_MANA_TEXT, 1));

		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(CHARGE_COUNTER), -2);
		AddAbility(cpAbility.GetPointer());
	}

	// {1}{R}, Remove five charge counters from this enchantment: It deals 5 damage to any target.
	// (it can't target planeswalkers)
	{
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this, _T("1") RED_MANA_TEXT,
				new AnyCreatureComparer, TRUE, Life(-5), PreventableType::Preventable));

		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(CHARGE_COUNTER), -5);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFiremindsResearchCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		CCardCounterModifier(CHARGE_COUNTER, +1).ApplyTo(this);
	return true;
}

CGuildSummitCard::CGuildSummitCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Guild Summit"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_GateSelection(pGame, CSelectionSupport::SelectionCallback(this, &CGuildSummitCard::OnGatesSelected))
{
	// When this enchantment enters, you may tap any number of untapped Gates you control. Draw a card for each Gate
	// tapped this way.
	AddEnterTrigger(this, &CGuildSummitCard::BeforeTapGates);

	// Whenever a Gate you control enters, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("Gates")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGuildSummitCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CGuildSummitCard::BeforeTapGates(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCountedCardContainer& battlefield = pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer();

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < battlefield.GetSize(); ++i)
	{
		CCard* pCard = battlefield.GetAt(i);
		if (CCardFilter::GetFilter(_T("Gates"))->IsCardIncluded(pCard) && !pCard->GetOrientation()->IsTapped())
		{
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Tap %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_GateSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this, pController);
	return true;
}

void CGuildSummitCard::OnGatesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	int nTapped = 0;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pGate = (CCard*)it->dwContext;
		if (pGate->GetZoneId() == ZoneId::Battlefield && !pGate->GetOrientation()->IsTapped())
		{
			CCardOrientationModifier(TRUE).ApplyTo(pGate);
			++nTapped;
		}
	}

	if (nTapped > 0)
		DrawCards(GetGame(), pSelectionPlayer, nTapped);
}

bool CGuildSummitCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CStreetRiotCard::CStreetRiotCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Street Riot"), CardType::GlobalEnchantment, nID,
		_T("4") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// During your turn, creatures you control get +1/+0 and have trample.
	// Partial (as Hardy Veteran in Rivals of Ixalan): at the beginning of your upkeep, creatures you control get +1/+0
	// and gain trample until end of turn (creatures that enter later this turn don't get the bonus)
	AddStepTrigger<CStreetRiotCard>(this, NodeId::UpkeepStep, false, NULL, &CStreetRiotCard::BeforePump);
}

bool CStreetRiotCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreatures(GetGame(), pAction->GetController(), +1, +0, CreatureKeyword::Trample);
	return true;
}

CUrbanUtopiaCard::CUrbanUtopiaCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Urban Utopia"), CardType::EnchantLand, nID)
{
	// Enchant land. Enchanted land has "{T}: Add one mana of any color."
	// Partial: as Fertile Ground in Eighth Edition (and Gift of Paradise in M19), whenever enchanted land is tapped for
	// mana, its controller adds one additional mana of any color (the engine can't grant mana abilities)
	counted_ptr<CAbilityEnchant> cpSpell(
		::CreateObject<CAbilityEnchant>(this,
			_T("1") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false),
			CAbilityEnchant::CreateAbilityCallback(this, &CUrbanUtopiaCard::CreateEnchantAbility),
			CAbilityEnchant::AdditionType::ToEnchantCard));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());

	// When this Aura enters, draw a card.
	AddEnterTrigger(this, &CUrbanUtopiaCard::BeforeDraw);
}

counted_ptr<CAbility> CUrbanUtopiaCard::CreateEnchantAbility(CCard* pEnchantedCard, CCard* pEnchantCard, ContextValue_& contextValue)
{
	typedef
		TTriggeredAbility< CTriggeredProdManaAbility, CWhenSelfTappedForMana > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pEnchantCard, pEnchantedCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
	cpAbility->SetSkipStack(TRUE);

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CUrbanUtopiaCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

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

CBorosLocketCard::CBorosLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Boros Locket"), nID, RED_MANA_TEXT, WHITE_MANA_TEXT)
{
}

CDimirLocketCard::CDimirLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Dimir Locket"), nID, BLUE_MANA_TEXT, BLACK_MANA_TEXT)
{
}

CGolgariLocketCard::CGolgariLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Golgari Locket"), nID, BLACK_MANA_TEXT, GREEN_MANA_TEXT)
{
}

CIzzetLocketCard::CIzzetLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Izzet Locket"), nID, BLUE_MANA_TEXT, RED_MANA_TEXT)
{
}

CSelesnyaLocketCard::CSelesnyaLocketCard(CGame* pGame, UINT nID)
	: CLocketCard(pGame, _T("Selesnya Locket"), nID, GREEN_MANA_TEXT, WHITE_MANA_TEXT)
{
}

CGlaiveOfTheGuildpactCard::CGlaiveOfTheGuildpactCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Glaive of the Guildpact"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	// Equipped creature gets +1/+0 for each Gate you control and has vigilance and menace. Equip {3}
	// (the equipment gives the creature an ability that counts the Gates, as Blackblade Reforged in Dominaria)
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CGlaiveOfTheGuildpactCard::CreateEquipmentAbility)));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Vigilance | CreatureKeyword::CantBeBlockedBy1);	// menace
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);

	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGlaiveOfTheGuildpactCard::BeforeEquip));
	AddAbility(cpAbility.GetPointer());
}

bool CGlaiveOfTheGuildpactCard::BeforeEquip(CAbilityAction* pAction)
{
	UnequipAll(this);
	return true;
}

counted_ptr<CAbility> CGlaiveOfTheGuildpactCard::CreateEquipmentAbility(CCard* pCard)
{
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(pCard,
			ZoneId::Battlefield,
			new CardTypeComparer(CardType::Gate, false)));

	cpAbility->SetChangePowerOnly();
	cpAbility->StartListening(GetController());
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CSilentDartCard::CSilentDartCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Silent Dart"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {4}, {T}, Sacrifice this artifact: It deals 3 damage to target creature.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this, _T("4"),
			new AnyCreatureComparer, FALSE, Life(-3), PreventableType::Preventable));

	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CWandOfVertebraeCard::CWandOfVertebraeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Wand of Vertebrae"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {T}: Mill a card.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Mill a card"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWandOfVertebraeCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}

	// {2}, {T}, Exile this artifact: Shuffle up to five target cards from your graveyard into your library.
	// (the cards are chosen on resolution, as Memory's Journey in Innistrad: they aren't targets)
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2")));

		cpAbility->AddTapCost();
		cpAbility->AddExileCost();
		cpAbility->SetAbilityText(_T("Shuffle up to five cards from your graveyard into your library"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWandOfVertebraeCard::BeforeShuffle));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CWandOfVertebraeCard::BeforeMill(CAbilityAction* pAction)
{
	Mill(pAction->GetController(), 1);
	return true;
}

bool CWandOfVertebraeCard::BeforeShuffle(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 5, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Library, MoveType::Others);
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

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

CBeaconBoltCard::CBeaconBoltCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Beacon Bolt"), CardType::Sorcery, nID)
{
	// Beacon Bolt deals damage to target creature equal to the total number of instant and sorcery cards you own in exile
	// and in your graveyard. Jump-start
	AddCreatureSorcery(this, _T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Characteristic::Negative, &CBeaconBoltCard::BeforeDamage);
	SetJumpStart(AddCreatureSorcery(this, _T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Characteristic::Negative, &CBeaconBoltCard::BeforeDamage));
}

bool CBeaconBoltCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCardFilter* pFilter = CCardFilter::GetFilter(_T("instant cards or sorcery cards"));
	int nCount = pFilter->CountIncluded(pController->GetZoneById(ZoneId::Graveyard)->GetCardContainer())
		+ pFilter->CountIncluded(pController->GetZoneById(ZoneId::Exile)->GetCardContainer());
	DealDamageToCreature(this, pAction->GetAssociatedCard(), nCount);
	return false;
}

CCamaraderieCard::CCamaraderieCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Camaraderie"), CardType::Sorcery, nID)
{
	// You gain X life and draw X cards, where X is the number of creatures you control. Creatures you control get +1/+1
	// until end of turn.
	AddSorcery(this, _T("4") GREEN_MANA_TEXT WHITE_MANA_TEXT, &CCamaraderieCard::BeforeResolution);
}

bool CCamaraderieCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = CountCreatures(GetGame(), pController);
	if (nCount > 0)
	{
		GainLife(this, pController, nCount);
		DrawCards(GetGame(), pController, nCount);
	}
	PumpCreatures(GetGame(), pController, +1, +1);
	return true;
}

CCircuitousRouteCard::CCircuitousRouteCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Circuitous Route"), CardType::Sorcery, nID)
	, m_LandFilter(_T("a basic land card or Gate card"), _T("basic land cards or Gate cards"),
		new OrCardComparer(new CardTypeComparer(CardType::BasicLand, false), new CardTypeComparer(CardType::Gate, false)))
{
	// Search your library for up to two basic land cards and/or Gate cards, put them onto the battlefield tapped, then
	// shuffle.
	AddSorcery(this, _T("3") GREEN_MANA_TEXT, &CCircuitousRouteCard::BeforeSearch);
}

bool CCircuitousRouteCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 2, &m_LandFilter, TRUE);
	return true;
}

CCitywideBustCard::CCitywideBustCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Citywide Bust"), CardType::Sorcery, nID)
{
	// Destroy all creatures with toughness 4 or greater.
	AddSorcery(this, _T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, &CCitywideBustCard::BeforeDestroy);
}

bool CCitywideBustCard::BeforeDestroy(CAbilityAction* pAction)
{
	AndCardComparer comparer(new AnyCreatureComparer, new CreatureToughnessComparer<std::greater_equal<int>>(4));
	DestroyAll(GetGame(), comparer);
	return true;
}

CConniveConcoctCard::CConniveConcoctCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Connive // Concoct"), CardType::Sorcery, nID)
{
	// Connive {2}{U/B}{U/B}: Gain control of target creature with power 2 or less. (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T("2"), 2, BLUE_MANA_TEXT, BLACK_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery, costs[i],
				new AndCardComparer(new AnyCreatureComparer, new CreaturePowerComparer<std::less_equal<int>>(2)), FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConniveConcoctCard::BeforeConnive));
		cpSpell->SetAbilityText(_T("Connive. Casts"));
		cpSpell->SetAbilityName(_T("Connive"));
		AddSpell(cpSpell.GetPointer());
	}

	// Concoct {3}{U}{B}: Surveil 3, then return a creature card from your graveyard to the battlefield.
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("3") BLUE_MANA_TEXT BLACK_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConniveConcoctCard::BeforeConcoct));
		cpSpell->SetAbilityText(_T("Concoct. Casts"));
		cpSpell->SetAbilityName(_T("Concoct"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CConniveConcoctCard::BeforeConnive(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CGainControlModifier(GetGame(), this).ApplyTo(pCard);
	return false;
}

bool CConniveConcoctCard::BeforeConcoct(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CSurveilModifier(GetGame(), 3, this).ApplyTo(pController);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Battlefield, MoveType::Others);
	return true;
}

CCosmotronicWaveCard::CCosmotronicWaveCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cosmotronic Wave"), CardType::Sorcery, nID)
{
	// Cosmotronic Wave deals 1 damage to each creature your opponents control. Creatures your opponents control can't
	// block this turn.
	AddSorcery(this, _T("3") RED_MANA_TEXT, &CCosmotronicWaveCard::BeforeResolution);
}

bool CCosmotronicWaveCard::BeforeResolution(CAbilityAction* pAction)
{
	std::vector<CPlayer*> opponents;
	GetOpponents(GetGame(), pAction->GetController(), opponents);
	for (size_t ip = 0; ip < opponents.size(); ++ip)
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), opponents[ip], TRUE, creatures);
		for (int i = 0; i < creatures.GetSize(); ++i)
			DealDamageToCreature(this, creatures.GetAt(i), 1);
		for (int i = 0; i < creatures.GetSize(); ++i)
			if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::CantBlock);
	}
	return true;
}

CCreepingChillCard::CCreepingChillCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Creeping Chill"), CardType::Sorcery, nID)
{
	// Creeping Chill deals 3 damage to each opponent and you gain 3 life.
	AddSorcery(this, _T("3") BLACK_MANA_TEXT, &CCreepingChillCard::BeforeDrain);

	// When Creeping Chill is put into your graveyard from your library, you may exile it. If you do, Creeping Chill deals
	// 3 damage to each opponent and you gain 3 life. (as Narcomoeba in Future Sight)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Library, ZoneId::Graveyard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCreepingChillCard::BeforeExileDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CCreepingChillCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 3, TRUE);
	return true;
}

bool CCreepingChillCard::BeforeExileDrain(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Graveyard)
		return true;

	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others).ApplyTo(this);
	DrainOpponents(this, pAction->GetController(), 3, TRUE);
	return true;
}

CDeadlyVisitCard::CDeadlyVisitCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deadly Visit"), CardType::Sorcery, nID)
{
	// Destroy target creature. Surveil 2.
	AddCreatureSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Characteristic::Negative, &CDeadlyVisitCard::BeforeResolution);
}

bool CDeadlyVisitCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);

	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return false;
}

CDeafeningClarionCard::CDeafeningClarionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deafening Clarion"), CardType::Sorcery, nID)
{
	// Choose one or both -
	// * Deafening Clarion deals 3 damage to each creature.
	// * Creatures you control gain lifelink until end of turn.
	CGenericSpell* pSpell = AddSorcery(this, _T("1") RED_MANA_TEXT WHITE_MANA_TEXT, &CDeafeningClarionCard::BeforeDamage);
	pSpell->SetAbilityText(_T("3 damage to each creature. Casts"));
	pSpell = AddSorcery(this, _T("1") RED_MANA_TEXT WHITE_MANA_TEXT, &CDeafeningClarionCard::BeforeLifelink);
	pSpell->SetAbilityText(_T("Creatures you control gain lifelink. Casts"));
	pSpell = AddSorcery(this, _T("1") RED_MANA_TEXT WHITE_MANA_TEXT, &CDeafeningClarionCard::BeforeBoth);
	pSpell->SetAbilityText(_T("Both modes. Casts"));
}

bool CDeafeningClarionCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachCreature(this, 3, FALSE);
	return true;
}

bool CDeafeningClarionCard::BeforeLifelink(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		GainCardKeyword(creatures.GetAt(i), CardKeyword::Lifelink);
	return true;
}

bool CDeafeningClarionCard::BeforeBoth(CAbilityAction* pAction)
{
	BeforeDamage(pAction);
	return BeforeLifelink(pAction);
}

CDirectCurrentCard::CDirectCurrentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Direct Current"), CardType::Sorcery, nID)
{
	// Direct Current deals 2 damage to any target. Jump-start
	// (it can't target planeswalkers)
	AddDamageSorcery(this, _T("1") RED_MANA_TEXT RED_MANA_TEXT, 2, new AnyCreatureComparer, TRUE);
	SetJumpStart(AddDamageSorcery(this, _T("1") RED_MANA_TEXT RED_MANA_TEXT, 2, new AnyCreatureComparer, TRUE));
}

CDiscoveryDispersalCard::CDiscoveryDispersalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Discovery // Dispersal"), CardType::Sorcery | CardType::Instant, nID)
{
	// Discovery {1}{U/B}: Surveil 2, then draw a card. (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T("1"), 1, BLUE_MANA_TEXT, BLACK_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, costs[i]));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDiscoveryDispersalCard::BeforeDiscovery));
		cpSpell->SetAbilityText(_T("Discovery. Casts"));
		cpSpell->SetAbilityName(_T("Discovery"));
		AddSpell(cpSpell.GetPointer());
	}

	// Dispersal {3}{U}{B} (instant): Each opponent returns a nonland permanent they control with the greatest mana value
	// among permanents they control to its owner's hand, then discards a card.
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("3") BLUE_MANA_TEXT BLACK_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDiscoveryDispersalCard::BeforeDispersal));
		cpSpell->SetAbilityText(_T("Dispersal. Casts"));
		cpSpell->SetAbilityName(_T("Dispersal"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CDiscoveryDispersalCard::BeforeDiscovery(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CDiscoveryDispersalCard::BeforeDispersal(CAbilityAction* pAction)
{
	std::vector<CPlayer*> opponents;
	GetOpponents(GetGame(), pAction->GetController(), opponents);
	for (size_t ip = 0; ip < opponents.size(); ++ip)
	{
		CPlayer* pOpponent = opponents[ip];

		// The greatest mana value among the permanents they control (lands have mana value 0)
		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		int nMax = -1;
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (!pCard->GetCardType().IsLand() && pCard->GetConvertedManaCost() > nMax)
				nMax = pCard->GetConvertedManaCost();
		}

		if (nMax >= 0)
		{
			CCardFilter filter(_T("a nonland permanent with the greatest mana value"), _T("nonland permanents with the greatest mana value"),
				new AndCardComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
					new ConvertedManaCostComparer<std::equal_to<int>>(nMax)));
			ChooseAndMove(GetGame(), pOpponent, ZoneId::Battlefield, 1, 1, &filter, ZoneId::Hand, MoveType::Others);
		}

		DiscardCards(GetGame(), pOpponent, 1);
	}
	return true;
}

CFindFinalityCard::CFindFinalityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Find // Finality"), CardType::Sorcery, nID)
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CFindFinalityCard::OnCreatureSelected))
{
	// Find {B/G}{B/G}: Return up to two target creature cards from your graveyard to your hand.
	// (one spell for each hybrid cost; the cards are chosen on resolution, they aren't targets)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, BLACK_MANA_TEXT, GREEN_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, costs[i]));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFindFinalityCard::BeforeFind));
		cpSpell->SetAbilityText(_T("Find. Casts"));
		cpSpell->SetAbilityName(_T("Find"));
		AddSpell(cpSpell.GetPointer());
	}

	// Finality {4}{B}{G}: You may put two +1/+1 counters on a creature you control. Then all creatures get -4/-4 until
	// end of turn.
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("4") BLACK_MANA_TEXT GREEN_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFindFinalityCard::BeforeFinality));
		cpSpell->SetAbilityText(_T("Finality. Casts"));
		cpSpell->SetAbilityName(_T("Finality"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CFindFinalityCard::BeforeFind(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 0, 2, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Hand, MoveType::Others);
	return true;
}

bool CFindFinalityCard::BeforeFinality(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	if (creatures.GetSize() == 0)
	{
		ShrinkAll();
		return true;
	}

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put two +1/+1 counters on %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_CreatureSelection.AddSelectionRequest(entries, 0, 1, this, pAction->GetController());
	return true;
}

void CFindFinalityCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			AddPlusCounter(pCard, 2);
	}
	ShrinkAll();
}

void CFindFinalityCard::ShrinkAll()
{
	PumpAllCreatures(GetGame(), -4, -4);
}

CFlowerFlourishCard::CFlowerFlourishCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Flower // Flourish"), CardType::Sorcery, nID)
	, m_LandFilter(_T("a basic Forest or Plains card"), _T("basic Forest or Plains cards"),
		new AndCardComparer(new CardTypeComparer(CardType::BasicLand, false),
			new CardTypeComparer(CardType::Forest | CardType::Plains, false)))
{
	// Flower {G/W}: Search your library for a basic Forest or Plains card, reveal it, put it into your hand, then shuffle.
	// (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 1, GREEN_MANA_TEXT, WHITE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, costs[i]));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFlowerFlourishCard::BeforeFlower));
		cpSpell->SetAbilityText(_T("Flower. Casts"));
		cpSpell->SetAbilityName(_T("Flower"));
		AddSpell(cpSpell.GetPointer());
	}

	// Flourish {4}{G}{W}: Creatures you control get +2/+2 until end of turn.
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("4") GREEN_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFlowerFlourishCard::BeforeFlourish));
		cpSpell->SetAbilityText(_T("Flourish. Casts"));
		cpSpell->SetAbilityName(_T("Flourish"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CFlowerFlourishCard::BeforeFlower(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, &m_LandFilter);
	return true;
}

bool CFlowerFlourishCard::BeforeFlourish(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +2, +2);
	return true;
}

CGirdForBattleCard::CGirdForBattleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gird for Battle"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on each of up to two target creatures.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery, WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(0, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	AddSpell(cpSpell.GetPointer());
}

CGraviticPunchCard::CGraviticPunchCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gravitic Punch"), CardType::Sorcery, nID)
{
	// Target creature you control deals damage equal to its power to target player. Jump-start
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("3") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				FALSE_CARD_COMPARER, TRUE, _T("")));

		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGraviticPunchCard::BeforeResolution));
		if (i == 1)
			SetJumpStart(cpSpell.GetPointer());
		AddSpell(cpSpell.GetPointer());
	}
}

bool CGraviticPunchCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	CPlayer* pPlayer = (CPlayer*)pDoubleTargetAction->GetTargetGroup2().GetFirstPlayerSubject();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && pPlayer)
		DealDamageToPlayer(pCreature, pPlayer, GET_INTEGER(pCreature->GetPower()));
	return false;
}

CGruesomeMenagerieCard::CGruesomeMenagerieCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gruesome Menagerie"), CardType::Sorcery, nID)
	, m_Filter1(_T("a creature card with mana value 1"), _T("creature cards with mana value 1"),
		new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::equal_to<int>>(1)))
	, m_Filter2(_T("a creature card with mana value 2"), _T("creature cards with mana value 2"),
		new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::equal_to<int>>(2)))
	, m_Filter3(_T("a creature card with mana value 3"), _T("creature cards with mana value 3"),
		new AndCardComparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::equal_to<int>>(3)))
{
	// Choose a creature card with mana value 1 in your graveyard, then do the same for creature cards with mana value 2
	// and 3. Return those cards to the battlefield.
	AddSorcery(this, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CGruesomeMenagerieCard::BeforeResolution);
}

bool CGruesomeMenagerieCard::BeforeResolution(CAbilityAction* pAction)
{
	// (each card returns as it is chosen)
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, &m_Filter1, ZoneId::Battlefield, MoveType::Others);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, &m_Filter2, ZoneId::Battlefield, MoveType::Others);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, &m_Filter3, ZoneId::Battlefield, MoveType::Others);
	return true;
}

CLavaCoilCard::CLavaCoilCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lava Coil"), CardType::Sorcery, nID)
{
	// Lava Coil deals 4 damage to target creature. If that creature would die this turn, exile it instead.
	// (as Magma Spray in Shards of Alara)
	CTargetChgLifeSpell* pSpell = AddDamageSorcery(this, _T("1") RED_MANA_TEXT, 4, new AnyCreatureComparer, FALSE);

	CReplacementKeywordModifier* pModifier = new CReplacementKeywordModifier();
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	pModifier->GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	pSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);
}

CMaximizeAltitudeCard::CMaximizeAltitudeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Maximize Altitude"), CardType::Sorcery, nID)
{
	// Target creature gets +1/+1 and gains flying until end of turn. Jump-start
	AddCreatureSorcery(this, BLUE_MANA_TEXT, Characteristic::Positive, &CMaximizeAltitudeCard::BeforePump);
	SetJumpStart(AddCreatureSorcery(this, BLUE_MANA_TEXT, Characteristic::Positive, &CMaximizeAltitudeCard::BeforePump));
}

bool CMaximizeAltitudeCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +1, +1, CreatureKeyword::Flying);
	return false;
}

CMaximizeVelocityCard::CMaximizeVelocityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Maximize Velocity"), CardType::Sorcery, nID)
{
	// Target creature gets +1/+1 and gains haste until end of turn. Jump-start
	AddCreatureSorcery(this, RED_MANA_TEXT, Characteristic::Positive, &CMaximizeVelocityCard::BeforePump);
	SetJumpStart(AddCreatureSorcery(this, RED_MANA_TEXT, Characteristic::Positive, &CMaximizeVelocityCard::BeforePump));
}

bool CMaximizeVelocityCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +1, +1, CreatureKeyword::Haste);
	return false;
}

CMephiticVaporsCard::CMephiticVaporsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mephitic Vapors"), CardType::Sorcery, nID)
{
	// All creatures get -1/-1 until end of turn. Surveil 2.
	AddSorcery(this, _T("2") BLACK_MANA_TEXT, &CMephiticVaporsCard::BeforeResolution);
}

bool CMephiticVaporsCard::BeforeResolution(CAbilityAction* pAction)
{
	PumpAllCreatures(GetGame(), -1, -1);
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CNeverHappenedCard::CNeverHappenedCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Never Happened"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNeverHappenedCard::OnCardSelected))
{
	// Target opponent reveals their hand. You choose a nonland card from that player's graveyard or hand and exile it.
	CTargetSpell* pSpell = AddPlayerSorcery(this, _T("2") BLACK_MANA_TEXT, &CNeverHappenedCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
}

bool CNeverHappenedCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return false;

	std::vector<SelectionEntry> entries;
	ZoneId zones[] = { ZoneId::Hand, ZoneId::Graveyard };
	for (int z = 0; z < _countof(zones); ++z)
	{
		CZone* pZone = pOpponent->GetZoneById(zones[z]);
		for (int i = 0; i < pZone->GetSize(); ++i)
		{
			CCard* pCard = pZone->GetAt(i);
			if (pCard->GetCardType().IsLand())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Exile %s (%s)"), pCard->GetCardName(TRUE),
				zones[z] == ZoneId::Hand ? _T("hand") : _T("graveyard"));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return false;
}

void CNeverHappenedCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		ZoneId zone = pCard->GetZoneId();
		if (zone == ZoneId::Hand || zone == ZoneId::Graveyard)
			CMoveCardModifier(zone, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
	}
}

CNotionRainCard::CNotionRainCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Notion Rain"), CardType::Sorcery, nID)
{
	// Surveil 2, then draw two cards. Notion Rain deals 2 damage to you.
	AddSorcery(this, _T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT, &CNotionRainCard::BeforeResolution);
}

bool CNotionRainCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pController);
	DrawCards(GetGame(), pController, 2);
	DealDamageToPlayer(this, pController, 2);
	return true;
}

CPrecisionBoltCard::CPrecisionBoltCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Precision Bolt"), CardType::Sorcery, nID)
{
	// Precision Bolt deals 3 damage to any target. (it can't target planeswalkers)
	AddDamageSorcery(this, _T("2") RED_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
}

CQuasiduplicateCard::CQuasiduplicateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Quasiduplicate"), CardType::Sorcery, nID)
{
	// Create a token that's a copy of target creature you control. Jump-start (as Rite of Replication in Zendikar)
	for (int i = 0; i < 2; ++i)
	{
		CTargetSpell* pSpell = AddCreatureSorcery(this, _T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, Characteristic::Positive,
			&CQuasiduplicateCard::BeforeCopy);
		pSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		if (i == 1)
			SetJumpStart(pSpell);
	}
}

bool CQuasiduplicateCard::BeforeCopy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardCopyModifier(GetGame(), this).ApplyTo(pCard);
	return false;
}

CResponseResurgenceCard::CResponseResurgenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Response // Resurgence"), CardType::Instant | CardType::Sorcery, nID)
{
	// Response {R/W}{R/W} (instant): Response deals 5 damage to target attacking or blocking creature.
	// (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, RED_MANA_TEXT, WHITE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant, costs[i],
				new AttackingBlockingCreatureComparer, FALSE,
				Life(-5), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Response. Casts"));
		cpSpell->SetAbilityName(_T("Response"));
		AddSpell(cpSpell.GetPointer());
	}

	// Resurgence {3}{R}{W}: Creatures you control gain first strike and vigilance until end of turn. After this main
	// phase, there is an additional combat phase followed by an additional main phase. (as Relentless Assault)
	{
		counted_ptr<CExtraCombatSpell> cpSpell(
			::CreateObject<CExtraCombatSpell>(this, AbilityType::Sorcery,
				_T("3") RED_MANA_TEXT WHITE_MANA_TEXT,
				FALSE, 1, TRUE));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CResponseResurgenceCard::BeforeResurgence));
		cpSpell->SetAbilityText(_T("Resurgence. Casts"));
		cpSpell->SetAbilityName(_T("Resurgence"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CResponseResurgenceCard::BeforeResurgence(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), 0, 0, CreatureKeyword::FirstStrike | CreatureKeyword::Vigilance);
	return true;
}

CRitualOfSootCard::CRitualOfSootCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ritual of Soot"), CardType::Sorcery, nID)
{
	// Destroy all creatures with mana value 3 or less.
	AddSorcery(this, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, &CRitualOfSootCard::BeforeDestroy);
}

bool CRitualOfSootCard::BeforeDestroy(CAbilityAction* pAction)
{
	AndCardComparer comparer(new AnyCreatureComparer, new ConvertedManaCostComparer<std::less_equal<int>>(3));
	DestroyAll(GetGame(), comparer);
	return true;
}

CSeveredStrandsCard::CSeveredStrandsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Severed Strands"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, sacrifice a creature. You gain life equal to the sacrificed creature's
	// toughness. Destroy target creature an opponent controls. (the sacrificed creature as in Fling)
	CTargetSpell* pSpell = AddCreatureSorcery(this, _T("1") BLACK_MANA_TEXT, Characteristic::Negative, &CSeveredStrandsCard::BeforeResolution);
	pSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	pSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
}

bool CSeveredStrandsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	if (pSacrificed && pSacrificed->GetSize() > 0)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pSacrificed->GetAt(0));
		if (pCreature)
			GainLife(this, pController, GET_INTEGER(pCreature->GetLastKnownToughness()));
	}

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pController).ApplyTo(pCard);
	return false;
}

CSproutingRenewalCard::CSproutingRenewalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sprouting Renewal"), CardType::Sorcery, nID)
{
	// Convoke (partial: the creatures pay only generic mana)
	// Choose one - Create a 2/2 green and white Elf Knight creature token with vigilance; or destroy target artifact or
	// enchantment. (two spells for each number of tapped creatures)
	AddConvokeSpells(this, 2, GREEN_MANA_TEXT, &CSproutingRenewalCard::AddModeSpells);
}

void CSproutingRenewalCard::AddModeSpells(LPCTSTR strCost, int nTapped)
{
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, strCost));

		SetConvoke(cpSpell.GetPointer(), nTapped);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSproutingRenewalCard::BeforeToken));
		cpSpell->SetAbilityText(_T("Create an Elf Knight token. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery, strCost,
				new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		SetConvoke(cpSpell.GetPointer(), nTapped);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Destroy target artifact or enchantment. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CSproutingRenewalCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Elf Knight (A)"), 55119, 1).ApplyTo(pAction->GetController());
	return true;
}

CSwornCompanionsCard::CSwornCompanionsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sworn Companions"), CardType::Sorcery, nID)
{
	// Create two 1/1 white Soldier creature tokens with lifelink.
	AddSorcery(this, _T("2") WHITE_MANA_TEXT, &CSwornCompanionsCard::BeforeResolution);
}

bool CSwornCompanionsCard::BeforeResolution(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, 2).ApplyTo(pAction->GetController());
	return true;
}

CThoughtErasureCard::CThoughtErasureCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thought Erasure"), CardType::Sorcery, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CThoughtErasureCard::OnResolutionCompleted))
	, m_NonlandFilter(_T("a nonland card"), _T("nonland cards"), new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Target opponent reveals their hand. You choose a nonland card from it. That player discards that card.
	// (as Dark Inquiry in Rivals of Ixalan) Surveil 1.
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLACK_MANA_TEXT,
			1, MoveType::Discard, ZoneId::Graveyard, TRUE,
			FALSE,
			&m_NonlandFilter));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

void CThoughtErasureCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (bResult)
		CSurveilModifier(GetGame(), 1, this).ApplyTo(pAbilityAction->GetController());
}

CUndercityUprisingCard::CUndercityUprisingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Undercity Uprising"), CardType::Sorcery, nID)
{
	// Creatures you control gain deathtouch until end of turn. Then target creature you control fights target creature
	// you don't control. (as Hunt the Weak)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUndercityUprisingCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CUndercityUprisingCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		GainCardKeyword(creatures.GetAt(i), CardKeyword::Deathtouch);

	CCard* pCreature = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (pCreature && pTarget)
		Fight(pCreature, pTarget);
	return false;
}

CViciousRumorsCard::CViciousRumorsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vicious Rumors"), CardType::Sorcery, nID)
{
	// Vicious Rumors deals 1 damage to each opponent. Each opponent discards a card, then mills a card. You gain 1 life.
	AddSorcery(this, BLACK_MANA_TEXT, &CViciousRumorsCard::BeforeResolution);
}

bool CViciousRumorsCard::BeforeResolution(CAbilityAction* pAction)
{
	std::vector<CPlayer*> opponents;
	GetOpponents(GetGame(), pAction->GetController(), opponents);
	for (size_t i = 0; i < opponents.size(); ++i)
		DealDamageToPlayer(this, opponents[i], 1);
	for (size_t i = 0; i < opponents.size(); ++i)
	{
		DiscardCards(GetGame(), opponents[i], 1);
		Mill(opponents[i], 1);
	}
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CVividRevivalCard::CVividRevivalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vivid Revival"), CardType::Sorcery, nID)
	, m_MulticoloredFilter(_T("a multicolored card"), _T("multicolored cards"), new CardMulticoloredComparer)
{
	// Return up to three target multicolored cards from your graveyard to your hand. Exile Vivid Revival.
	// (the cards are chosen on resolution, they aren't targets)
	CGenericSpell* pSpell = AddSorcery(this, _T("4") GREEN_MANA_TEXT, &CVividRevivalCard::BeforeResolution);
	pSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
}

bool CVividRevivalCard::BeforeResolution(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 0, 3, &m_MulticoloredFilter,
		ZoneId::Hand, MoveType::Others);
	return true;
}

CVraskasStoneglareCard::CVraskasStoneglareCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vraska's Stoneglare"), CardType::Sorcery, nID)
{
	// Destroy target creature. You gain life equal to its toughness. You may search your library and/or graveyard for a
	// card named Vraska, Regal Gorgon, reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddCreatureSorcery(this, _T("4") BLACK_MANA_TEXT GREEN_MANA_TEXT, Characteristic::Negative, &CVraskasStoneglareCard::BeforeResolution);
}

bool CVraskasStoneglareCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pController).ApplyTo(pCreature);
		GainLife(this, pController, GET_INTEGER(pCreature->GetLastKnownToughness()));
	}

	SearchNamedCardToHand(pController, _T("Vraska, Regal Gorgon"));
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

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

CArtfulTakedownCard::CArtfulTakedownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Artful Takedown"), CardType::Instant, nID)
{
	// Choose one or both - Tap target creature; and/or target creature gets -2/-4 until end of turn.
	{
		CTargetSpell* pSpell = AddCreatureInstant(this, _T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT, Characteristic::Negative,
			&CArtfulTakedownCard::BeforeTap);
		pSpell->SetAbilityText(_T("Tap target creature. Casts"));
	}
	{
		CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, _T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT, -2, -4);
		pSpell->SetAbilityText(_T("Target creature gets -2/-4. Casts"));
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArtfulTakedownCard::BeforeBoth));
		cpSpell->SetAbilityText(_T("Both modes (tap the first, -2/-4 to the second). Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CArtfulTakedownCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
	return false;
}

bool CArtfulTakedownCard::BeforeBoth(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pTap = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pShrink = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (pTap && pTap->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(TRUE).ApplyTo(pTap);
	if (pShrink && pShrink->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pShrink, -2, -4);
	return false;
}

CAssassinsTrophyCard::CAssassinsTrophyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Assassin's Trophy"), CardType::Instant, nID)
{
	// Destroy target permanent an opponent controls. Its controller may search their library for a basic land card, put
	// it onto the battlefield, then shuffle.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			BLACK_MANA_TEXT GREEN_MANA_TEXT,
			new TrueCardComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAssassinsTrophyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAssassinsTrophyCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pController = pCard->GetController();
	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	SearchToBattlefield(GetGame(), pController, 1, CCardFilter::GetFilter(_T("basic lands")), FALSE);
	return false;
}

CAssureAssembleCard::CAssureAssembleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Assure // Assemble"), CardType::Instant, nID)
{
	// Assure {G/W}{G/W}: Put a +1/+1 counter on target creature. That creature gains indestructible until end of turn.
	// (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, GREEN_MANA_TEXT, WHITE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		CTargetSpell* pSpell = AddCreatureInstant(this, costs[i], Characteristic::Positive, &CAssureAssembleCard::BeforeAssure);
		SetSplitHalf(pSpell, _T("Assure"));
	}

	// Assemble {4}{G}{W}: Create three 2/2 green and white Elf Knight creature tokens with vigilance.
	SetSplitHalf(AddInstant(this, _T("4") GREEN_MANA_TEXT WHITE_MANA_TEXT, &CAssureAssembleCard::BeforeAssemble), _T("Assemble"));
}

bool CAssureAssembleCard::BeforeAssure(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		AddPlusCounter(pCard);
		GainCardKeyword(pCard, CardKeyword::Indestructible);
	}
	return false;
}

bool CAssureAssembleCard::BeforeAssemble(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Elf Knight (A)"), 55119, 3).ApplyTo(pAction->GetController());
	return true;
}

CBountyOfMightCard::CBountyOfMightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bounty of Might"), CardType::Instant, nID)
{
	// Target creature gets +3/+3 until end of turn. (three times)
	// Partial: two spells, one for the same target three times (+9/+9) and one for up to three different targets
	{
		CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, +9, +9);
		pSpell->SetAbilityText(_T("The same target creature three times (+9/+9). Casts"));
	}
	{
		CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, +3, +3);
		pSpell->GetTargeting()->SetSubjectCount(1, 3);
		pSpell->SetAbilityText(_T("Up to three different target creatures (+3/+3 each). Casts"));
		pSpell->SetMainSpell(FALSE);
	}
}

CChanceForGloryCard::CChanceForGloryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chance for Glory"), CardType::Instant, nID)
{
	// Creatures you control gain indestructible. Take an extra turn after this one. At the beginning of that turn's end
	// step, you lose the game. (as Final Fortune in Sixth Edition)
	counted_ptr<CPlayerEffectSpell> cpSpell(
		::CreateObject<CPlayerEffectSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT WHITE_MANA_TEXT,
			PlayerEffectType::TimeWalk, false, 1));

	cpSpell->SetAffectControllerOnly();
	cpSpell->GetResolutionModifier().CPlayerModifiers::Add(
		new CScheduledPlayerModifier(GetGame(),
			new CPlayerLostModifier,
			TurnNumberDelta(+1), NodeId::EndStep,
			CScheduledPlayerModifier::Operation::ApplyToLater));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChanceForGloryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CChanceForGloryCard::BeforeResolution(CAbilityAction* pAction)
{
	// (indestructible without duration)
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		CCardKeywordModifier(CardKeyword::Indestructible, FALSE).ApplyTo(creatures.GetAt(i));
	return true;
}

CChemistersInsightCard::CChemistersInsightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chemister's Insight"), CardType::Instant, nID)
{
	// Draw two cards. Jump-start
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant, _T("3") BLUE_MANA_TEXT, 2));
		if (i == 1)
			SetJumpStart(cpSpell.GetPointer());
		AddSpell(cpSpell.GetPointer());
	}
}

CCollarTheCulpritCard::CCollarTheCulpritCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Collar the Culprit"), CardType::Instant, nID)
{
	// Destroy target creature with toughness 4 or greater.
	AddMoveInstant(this, _T("3") WHITE_MANA_TEXT,
		new AndCardComparer(new AnyCreatureComparer, new CreatureToughnessComparer<std::greater_equal<int>>(4)),
		ZoneId::Graveyard, MoveType::Destroy);
}

CCommandTheStormCard::CCommandTheStormCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Command the Storm"), CardType::Instant, nID)
{
	// Command the Storm deals 5 damage to target creature.
	AddDamageInstant(this, _T("4") RED_MANA_TEXT, 5, new AnyCreatureComparer, FALSE);
}

CCrushContrabandCard::CCrushContrabandCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Crush Contraband"), CardType::Instant, nID)
{
	// Choose one or both - Exile target artifact; and/or exile target enchantment.
	AddMoveInstant(this, _T("3") WHITE_MANA_TEXT, new CardTypeComparer(CardType::Artifact, false), ZoneId::Exile, MoveType::Others)
		->SetAbilityText(_T("Exile target artifact. Casts"));
	AddMoveInstant(this, _T("3") WHITE_MANA_TEXT, new CardTypeComparer(CardType::_Enchantment, false), ZoneId::Exile, MoveType::Others)
		->SetAbilityText(_T("Exile target enchantment. Casts"));

	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("3") WHITE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact, false), FALSE,
			new CardTypeComparer(CardType::_Enchantment, false), FALSE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrushContrabandCard::BeforeBoth));
	cpSpell->SetAbilityText(_T("Exile target artifact and target enchantment. Casts"));
	AddSpell(cpSpell.GetPointer());
}

bool CCrushContrabandCard::BeforeBoth(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pCards[] = {
		(CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
		(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject() };
	for (int i = 0; i < 2; ++i)
		if (pCards[i] && pCards[i]->GetZoneId() == ZoneId::Battlefield)
			CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController()).ApplyTo(pCards[i]);
	return false;
}

CDazzlingLightsCard::CDazzlingLightsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dazzling Lights"), CardType::Instant, nID)
{
	// Target creature gets -3/-0 until end of turn. Surveil 2.
	AddCreatureInstant(this, BLUE_MANA_TEXT, Characteristic::Negative, &CDazzlingLightsCard::BeforeResolution);
}

bool CDazzlingLightsCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, -3, 0);
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return false;
}

CDeviousCoverUpCard::CDeviousCoverUpCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Devious Cover-Up"), CardType::Instant, nID)
{
	// Counter target spell. If that spell is countered this way, exile it instead of putting it into its owner's
	// graveyard. (as Dissipate) You may shuffle up to four target cards from your graveyard into your library.
	// (the cards are chosen on resolution, they aren't targets)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetToZone(ZoneId::Exile, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeviousCoverUpCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDeviousCoverUpCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 4, CCardFilter::GetFilter(_T("cards")),
		ZoneId::Library, MoveType::Others);
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CExpansionExplosionCard::CExpansionExplosionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Expansion // Explosion"), CardType::Instant, nID)
{
	// Expansion {U/R}{U/R}: Copy target instant or sorcery spell with mana value 4 or less. You may choose new targets
	// for the copy. (as Twincast; one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 2, BLUE_MANA_TEXT, RED_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		counted_ptr<CTargetCopyCastSpell> cpSpell(
			::CreateObject<CTargetCopyCastSpell>(this, AbilityType::Instant,
				costs[i],
				new AndCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
					new ConvertedManaCostComparer<std::less_equal<int>>(4)),
				ZoneId::Stack));

		SetSplitHalf(cpSpell.GetPointer(), _T("Expansion"));
		AddSpell(cpSpell.GetPointer());
	}

	// Explosion {X}{U}{U}{R}{R}: Explosion deals X damage to any target. Target player draws X cards.
	// (it can't target planeswalkers)
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				BLUE_MANA_TEXT BLUE_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT,
				new AnyCreatureComparer, TRUE,
				FALSE_CARD_COMPARER, TRUE, _T("")));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExpansionExplosionCard::BeforeExplosion));
		SetSplitHalf(cpSpell.GetPointer(), _T("Explosion"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CExpansionExplosionCard::BeforeExplosion(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	int nX = GetX(pAction);
	if (nX > 0)
	{
		CCard* pCard = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
		CPlayer* pPlayer = (CPlayer*)pDoubleTargetAction->GetTargetGroup1().GetFirstPlayerSubject();
		CLifeModifier pDamage = CLifeModifier(Life(-nX), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		if (pPlayer)
			pDamage.ApplyTo(pPlayer);
		else if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
			pDamage.ApplyTo((CCreatureCard*)pCard);

		CPlayer* pDrawer = (CPlayer*)pDoubleTargetAction->GetTargetGroup2().GetFirstPlayerSubject();
		if (pDrawer)
			DrawCards(GetGame(), pDrawer, nX);
	}
	return false;
}

CHypothesizzleCard::CHypothesizzleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hypothesizzle"), CardType::Instant, nID)
	, m_DiscardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CHypothesizzleCard::OnDiscardSelected))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CHypothesizzleCard::OnCreatureSelected))
{
	// Draw two cards. Then you may discard a nonland card. When you do, Hypothesizzle deals 4 damage to target creature.
	// Partial: the creature is chosen on resolution (it isn't targeted)
	AddInstant(this, _T("3") BLUE_MANA_TEXT RED_MANA_TEXT, &CHypothesizzleCard::BeforeResolution);
}

bool CHypothesizzleCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 2);

	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
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

	if (!entries.empty() && CountCreatures(GetGame(), pController) + CountCreatures(GetGame(), GetGame()->GetNextPlayer(pController)) > 0)
		m_DiscardSelection.AddSelectionRequest(entries, 0, 1, this, pController);
	return true;
}

void CHypothesizzleCard::OnDiscardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	BOOL bDiscarded = FALSE;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() == ZoneId::Hand)
		{
			CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard).ApplyTo(pCard);
			bDiscarded = TRUE;
		}
	}
	if (!bDiscarded)
		return;

	// When you do, Hypothesizzle deals 4 damage to a creature
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), GetGame()->GetPlayer(ip), TRUE, creatures);
		for (int i = 0; i < creatures.GetSize(); ++i)
		{
			CCard* pCard = creatures.GetAt(i);
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("4 damage to %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}
	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pSelectionPlayer);
}

void CHypothesizzleCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			DealDamageToCreature(this, (CCard*)it->dwContext, 4);
}

CInescapableBlazeCard::CInescapableBlazeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Inescapable Blaze"), CardType::Instant, nID)
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Inescapable Blaze deals 6 damage to any target. (it can't target planeswalkers)
	AddDamageInstant(this, _T("4") RED_MANA_TEXT RED_MANA_TEXT, 6, new AnyCreatureComparer, TRUE);
}

CIntegrityInterventionCard::CIntegrityInterventionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Integrity // Intervention"), CardType::Instant, nID)
{
	// Integrity {R/W}: Target creature gets +2/+2 until end of turn. (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 1, RED_MANA_TEXT, WHITE_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		SetSplitHalf(AddPumpInstant(this, costs[i], +2, +2), _T("Integrity"));

	// Intervention {2}{R}{W}: Intervention deals 3 damage to any target and you gain 3 life.
	// (it can't target planeswalkers)
	CTargetChgLifeSpell* pSpell = AddDamageInstant(this, _T("2") RED_MANA_TEXT WHITE_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	pSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIntegrityInterventionCard::BeforeIntervention));
	SetSplitHalf(pSpell, _T("Intervention"));
}

bool CIntegrityInterventionCard::BeforeIntervention(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CInvertInventCard::CInvertInventCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Invert // Invent"), CardType::Instant, nID)
{
	// Invert {U/R}: Switch the power and toughness of each of up to two target creatures until end of turn.
	// (as Twisted Image in Scars of Mirrodin; one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 1, BLUE_MANA_TEXT, RED_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
	{
		CTargetChgPwrTghAttrSpell* pSpell = AddPumpInstant(this, costs[i], 0, 0, CreatureKeyword::SwitchedPT);
		pSpell->GetTargeting()->SetSubjectCount(0, 2);
		SetSplitHalf(pSpell, _T("Invert"));
	}

	// Invent {4}{U}{R}: Search your library for an instant card and/or a sorcery card, reveal them, put them into your
	// hand, then shuffle.
	SetSplitHalf(AddInstant(this, _T("4") BLUE_MANA_TEXT RED_MANA_TEXT, &CInvertInventCard::BeforeInvent), _T("Invent"));
}

bool CInvertInventCard::BeforeInvent(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("instant cards")));
	SearchToHand(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("sorcery cards")));
	return true;
}

CIonizeCard::CIonizeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ionize"), CardType::Instant, nID)
{
	// Counter target spell. Ionize deals 2 damage to that spell's controller.
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT RED_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIonizeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CIonizeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCard->GetController());
	}
	return true;
}

CJoinShieldsCard::CJoinShieldsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Join Shields"), CardType::Instant, nID)
{
	// Untap all creatures you control. They gain hexproof and indestructible until end of turn.
	AddInstant(this, _T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT, &CJoinShieldsCard::BeforeResolution);
}

bool CJoinShieldsCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		CCardOrientationModifier(FALSE).ApplyTo(pCard);
		GainCardKeyword(pCard, CardKeyword::Hexproof);
		GainCardKeyword(pCard, CardKeyword::Indestructible);
	}
	return true;
}

CJusticeStrikeCard::CJusticeStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Justice Strike"), CardType::Instant, nID)
{
	// Target creature deals damage to itself equal to its power.
	AddCreatureInstant(this, RED_MANA_TEXT WHITE_MANA_TEXT, Characteristic::Negative, &CJusticeStrikeCard::BeforeResolution);
}

bool CJusticeStrikeCard::BeforeResolution(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		DealDamageToCreature(pCreature, pCreature, GET_INTEGER(pCreature->GetPower()));
	return false;
}

CMarchOfTheMultitudesCard::CMarchOfTheMultitudesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("March of the Multitudes"), CardType::Instant, nID)
{
	// Convoke. Create X 1/1 white Soldier creature tokens with lifelink.
	// Partial Convoke: one spell for each number of tapped creatures (1 to 6), each of them adds 1 to X (the tapped
	// creatures are counted with GetTapCards); they pay only generic mana
	for (int nTapped = 0; nTapped <= 6; ++nTapped)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Instant, GREEN_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
		SetConvoke(cpSpell.GetPointer(), nTapped);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this,
			nTapped == 0 ? &CMarchOfTheMultitudesCard::BeforeTokens : &CMarchOfTheMultitudesCard::BeforeConvokedTokens));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CMarchOfTheMultitudesCard::BeforeTokens(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0)
		CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, nX).ApplyTo(pAction->GetController());
	return true;
}

bool CMarchOfTheMultitudesCard::BeforeConvokedTokens(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	const CCountedCardContainer* pTapped = pAction->GetCostConfigEntry().GetTapCards();
	if (pTapped)
		nX += pTapped->GetSize();
	if (nX > 0)
		CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, nX).ApplyTo(pAction->GetController());
	return true;
}

CMausoleumSecretsCard::CMausoleumSecretsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mausoleum Secrets"), CardType::Instant, nID)
{
	// Undergrowth - Search your library for a black card with mana value less than or equal to the number of creature
	// cards in your graveyard, reveal it, put it into your hand, then shuffle.
	AddInstant(this, _T("1") BLACK_MANA_TEXT, &CMausoleumSecretsCard::BeforeResolution);
}

bool CMausoleumSecretsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = CountCreatureCardsInGraveyard(pController);
	CCardFilter filter(_T("a black card"), _T("black cards"),
		new AndCardComparer(new CardTypeComparer(CardType::Black, false),
			new ConvertedManaCostComparer<std::less_equal<int>>(nCount)));
	SearchToHand(GetGame(), pController, 1, &filter);
	return true;
}

CNecroticWoundCard::CNecroticWoundCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Necrotic Wound"), CardType::Instant, nID)
{
	// Undergrowth - Target creature gets -X/-X until end of turn, where X is the number of creature cards in your
	// graveyard. If that creature would die this turn, exile it instead. (as Magma Spray)
	AddCreatureInstant(this, BLACK_MANA_TEXT, Characteristic::Negative, &CNecroticWoundCard::BeforeResolution);
}

bool CNecroticWoundCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CReplacementKeywordModifier pModifier;
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	pModifier.ApplyTo(pCard);

	int nX = CountCreatureCardsInGraveyard(pAction->GetController());
	if (nX > 0)
		PumpCreature(pCard, -nX, -nX);
	return false;
}

CPacksFavorCard::CPacksFavorCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pack's Favor"), CardType::Instant, nID)
{
	// Convoke (partial: the creatures pay only generic mana). Target creature gets +3/+3 until end of turn.
	AddConvokeSpells(this, 2, GREEN_MANA_TEXT, &CPacksFavorCard::AddPackSpell);
}

void CPacksFavorCard::AddPackSpell(LPCTSTR strCost, int nTapped)
{
	SetConvoke(AddPumpInstant(this, strCost, +3, +3), nTapped);
}

CPauseForReflectionCard::CPauseForReflectionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pause for Reflection"), CardType::Instant, nID)
{
	// Convoke (partial: the creatures pay only generic mana). Prevent all combat damage that would be dealt this turn.
	// (as Fog)
	AddConvokeSpells(this, 2, GREEN_MANA_TEXT, &CPauseForReflectionCard::AddPauseSpell);
}

void CPauseForReflectionCard::AddPauseSpell(LPCTSTR strCost, int nTapped)
{
	counted_ptr<CPlayerEffectSpell> cpSpell(
		::CreateObject<CPlayerEffectSpell>(this, AbilityType::Instant,
			strCost,
			PlayerEffectType::PreventAllCombatDamage, TRUE));

	SetConvoke(cpSpell.GetPointer(), nTapped);
	AddSpell(cpSpell.GetPointer());
}

CPriceOfFameCard::CPriceOfFameCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Price of Fame"), CardType::Instant, nID)
{
	// This spell costs {2} less to cast if it targets a legendary creature. Destroy target creature. Surveil 2.
	// (a second spell, {1}{B}, that can only target legendary creatures)
	AddCreatureInstant(this, _T("3") BLACK_MANA_TEXT, Characteristic::Negative, &CPriceOfFameCard::BeforeResolution);

	CTargetSpell* pSpell = AddCreatureInstant(this, _T("1") BLACK_MANA_TEXT, Characteristic::Negative, &CPriceOfFameCard::BeforeResolution);
	pSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Legendary, false));
	pSpell->SetAbilityText(_T("Target a legendary creature. Casts"));
	pSpell->SetMainSpell(FALSE);
}

bool CPriceOfFameCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController()).ApplyTo(pCard);
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return false;
}

CRadicalIdeaCard::CRadicalIdeaCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Radical Idea"), CardType::Instant, nID)
{
	// Draw a card. Jump-start
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant, _T("1") BLUE_MANA_TEXT, 1));
		if (i == 1)
			SetJumpStart(cpSpell.GetPointer());
		AddSpell(cpSpell.GetPointer());
	}
}

CRalsDispersalCard::CRalsDispersalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ral's Dispersal"), CardType::Instant, nID)
{
	// Return target creature to its owner's hand. You may search your library and/or graveyard for a card named Ral,
	// Caller of Storms, reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddCreatureInstant(this, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Characteristic::Negative, &CRalsDispersalCard::BeforeResolution);
}

bool CRalsDispersalCard::BeforeResolution(CAbilityAction* pAction)
{
	BounceCreature(pAction->GetAssociatedCard());
	SearchNamedCardToHand(pAction->GetController(), _T("Ral, Caller of Storms"));
	return false;
}

CRiskFactorCard::CRiskFactorCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Risk Factor"), CardType::Instant, nID)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRiskFactorCard::OnChoiceSelected))
{
	// Target opponent may have Risk Factor deal 4 damage to them. If that player doesn't, you draw three cards. Jump-start
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));

		cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRiskFactorCard::BeforeResolution));
		if (i == 1)
			SetJumpStart(cpSpell.GetPointer());
		AddSpell(cpSpell.GetPointer());
	}
}

bool CRiskFactorCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return false;

	// (as Demanding Dragon in M19: the opponent chooses)
	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Risk Factor deals 4 damage to you");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText = _T("Your opponent draws three cards");
		entries.push_back(entry);
	}
	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, NULL, pOpponent, (DWORD)pAction->GetController());
	return false;
}

void CRiskFactorCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		if (it->dwContext == 1)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-4), this, PreventableType::Preventable,
				DamageType::SpellDamage | DamageType::NonCombatDamage);
			pModifier.ApplyTo(pSelectionPlayer);
		}
		else if (pController)
			DrawCards(GetGame(), pController, 3);
	}
}

CSinisterSabotageCard::CSinisterSabotageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sinister Sabotage"), CardType::Instant, nID)
{
	// Counter target spell. Surveil 1.
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSinisterSabotageCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSinisterSabotageCard::BeforeResolution(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CSonicAssaultCard::CSonicAssaultCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sonic Assault"), CardType::Instant, nID)
{
	// Tap target creature. Sonic Assault deals 2 damage to that creature's controller. Jump-start
	AddCreatureInstant(this, _T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Characteristic::Negative, &CSonicAssaultCard::BeforeResolution);
	SetJumpStart(AddCreatureInstant(this, _T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Characteristic::Negative, &CSonicAssaultCard::BeforeResolution));
}

bool CSonicAssaultCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCard->GetController());
	}
	return false;
}

CStatusStatueCard::CStatusStatueCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Status // Statue"), CardType::Instant, nID)
{
	// Status {B/G}: Target creature gets +1/+1 and gains deathtouch until end of turn. (one spell for each hybrid cost)
	std::vector<CString> costs;
	GetHybridCosts(_T(""), 1, BLACK_MANA_TEXT, GREEN_MANA_TEXT, costs);
	for (size_t i = 0; i < costs.size(); ++i)
		SetSplitHalf(AddCreatureInstant(this, costs[i], Characteristic::Positive, &CStatusStatueCard::BeforeStatus), _T("Status"));

	// Statue {2}{B}{G}: Destroy target artifact, creature, or enchantment.
	SetSplitHalf(AddMoveInstant(this, _T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT,
		new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment, false),
		ZoneId::Graveyard, MoveType::Destroy), _T("Statue"));
}

bool CStatusStatueCard::BeforeStatus(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		PumpCreature(pCard, +1, +1);
		GainCardKeyword(pCard, CardKeyword::Deathtouch);
	}
	return false;
}

CTakeHeartCard::CTakeHeartCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Take Heart"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 until end of turn. You gain 1 life for each attacking creature you control.
	AddCreatureInstant(this, WHITE_MANA_TEXT, Characteristic::Positive, &CTakeHeartCard::BeforeResolution);
}

bool CTakeHeartCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +2, +2);

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	AttackingCreatureComparer attacking;
	int nAttacking = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (attacking(creatures.GetAt(i)))
			++nAttacking;
	if (nAttacking > 0)
		GainLife(this, pAction->GetController(), nAttacking);
	return false;
}

CUnexplainedDisappearanceCard::CUnexplainedDisappearanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unexplained Disappearance"), CardType::Instant, nID)
{
	// Return target creature to its owner's hand. Surveil 1.
	AddCreatureInstant(this, _T("1") BLUE_MANA_TEXT, Characteristic::Negative, &CUnexplainedDisappearanceCard::BeforeResolution);
}

bool CUnexplainedDisappearanceCard::BeforeResolution(CAbilityAction* pAction)
{
	BounceCreature(pAction->GetAssociatedCard());
	CSurveilModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

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

CBladeInstructorCard::CBladeInstructorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blade Instructor"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_Mentor(this)
{
	// Mentor
	m_Mentor.AddMentorAbility();
}

CBountyAgentCard::CBountyAgentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bounty Agent"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// {T}, Sacrifice this creature: Destroy target legendary permanent that's an artifact, creature, or enchantment.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this, _T(""),
			new AndCardComparer(new CardTypeComparer(CardType::Legendary, false),
				new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment, false)),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CFlightOfEquenautsCard::CFlightOfEquenautsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Flight of Equenauts"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("7") WHITE_MANA_TEXT, Power(4), Life(5))
{
	// Convoke (partial: the creatures pay only generic mana). Flying
	AddPermanentConvoke(this, 7, WHITE_MANA_TEXT);
}

CHaazdaMarshalCard::CHaazdaMarshalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Haazda Marshal"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Whenever this creature and at least two other creatures attack, create a 1/1 white Soldier creature token with
	// lifelink. (the attackers are counted on resolution)
	AddSelfAttackTrigger(this, &CHaazdaMarshalCard::BeforeToken);
}

bool CHaazdaMarshalCard::BeforeToken(CAbilityAction* pAction)
{
	if (CountAttackingCreatures(GetGame(), pAction->GetController()) >= 3)
		CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, 1).ApplyTo(pAction->GetController());
	return true;
}

CHealersHawkCard::CHealersHawkCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Healer's Hawk"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Flying, lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

CHuntedWitnessCard::CHuntedWitnessCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hunted Witness"), CardType::Creature, CREATURE_TYPE(Human), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// When this creature dies, create a 1/1 white Soldier creature token with lifelink.
	AddDiesTrigger(this, &CHuntedWitnessCard::BeforeToken);
}

bool CHuntedWitnessCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, 1).ApplyTo(pAction->GetController());
	return true;
}

CInspiringUnicornCard::CInspiringUnicornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inspiring Unicorn"), CardType::Creature, CREATURE_TYPE(Unicorn), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, creatures you control get +1/+1 until end of turn.
	AddSelfAttackTrigger(this, &CInspiringUnicornCard::BeforePump);
}

bool CInspiringUnicornCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, +1);
	return true;
}

CIntrusivePackbeastCard::CIntrusivePackbeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Intrusive Packbeast"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, tap up to two target creatures your opponents control. (as Niblis of the Mist)
	typedef
		TTriggeredTargetAbility< CTriggeredTapCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetTapCardOption(CTriggeredTapCardAbility::TapCardOption::TapSingleCard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetSubjectCount(0, 2);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CLedevGuardianCard::CLedevGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ledev Guardian"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(4))
{
	// Convoke (partial: the creatures pay only generic mana)
	AddPermanentConvoke(this, 3, WHITE_MANA_TEXT);
}

CLightOfTheLegionCard::CLightOfTheLegionCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Light of the Legion"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
	, m_Mentor(this)
{
	// Flying. Mentor
	m_Mentor.AddMentorAbility();

	// When this creature dies, put a +1/+1 counter on each white creature you control.
	AddDiesTrigger(this, &CLightOfTheLegionCard::BeforeCounters);
}

bool CLightOfTheLegionCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if ((creatures.GetAt(i)->GetCardType() & CardType::White).Any())
			AddPlusCounter(creatures.GetAt(i));
	return true;
}

CLoxodonRestorerCard::CLoxodonRestorerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loxodon Restorer"), CardType::Creature, CREATURE_TYPE2(Elephant, Cleric), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(4))
{
	// Convoke (partial: the creatures pay only generic mana)
	AddPermanentConvoke(this, 4, WHITE_MANA_TEXT WHITE_MANA_TEXT);

	// When this creature enters, you gain 4 life.
	AddEnterTrigger(this, &CLoxodonRestorerCard::BeforeGainLife);
}

bool CLoxodonRestorerCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 4);
	return true;
}

CParhelionPatrolCard::CParhelionPatrolCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Parhelion Patrol"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Mentor(this)
{
	// Flying, vigilance. Mentor
	GetCreatureKeyword()->AddVigilance(FALSE);
	m_Mentor.AddMentorAbility();
}

CRocChargerCard::CRocChargerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Roc Charger"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("2") WHITE_MANA_TEXT, Power(1), Life(3))
{
	// Flying. Whenever this creature attacks, target attacking creature without flying gains flying until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CRocChargerCard::BeforeFlying, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false)));
}

bool CRocChargerCard::BeforeFlying(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, 0, 0, CreatureKeyword::Flying);
	return false;
}

CSkylineScoutCard::CSkylineScoutCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skyline Scout"), CardType::Creature, CREATURE_TYPE2(Human, Scout), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks, you may pay {1}{W}. If you do, it gains flying until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T("1") WHITE_MANA_TEXT);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkylineScoutCard::BeforeFlying));
	AddAbility(cpAbility.GetPointer());
}

bool CSkylineScoutCard::BeforeFlying(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::Flying);
	return true;
}

CSunhomeStalwartCard::CSunhomeStalwartCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sunhome Stalwart"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Mentor(this)
{
	// First strike. Mentor
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	m_Mentor.AddMentorAbility();
}

CTenthDistrictGuardCard::CTenthDistrictGuardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tenth District Guard"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, target creature gets +0/+1 until end of turn.
	AddEnterTargetTrigger(this, &CTenthDistrictGuardCard::BeforePump, false, Characteristic::Positive);
}

bool CTenthDistrictGuardCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, 0, +1);
	return false;
}

CVeneratedLoxodonCard::CVeneratedLoxodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Venerated Loxodon"), CardType::Creature, CREATURE_TYPE2(Elephant, Cleric), nID,
		_T("4") WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Convoke (partial: the creatures pay only generic mana)
	// When this creature enters, put a +1/+1 counter on each creature that convoked it.
	// (the convoke spells remember the tapped creatures when they resolve; the main spell forgets them)
	GetSpells().GetAt(0)->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVeneratedLoxodonCard::BeforeMainResolution));
	AddPermanentConvoke(this, 4, WHITE_MANA_TEXT, &CVeneratedLoxodonCard::BeforeConvokedResolution);

	AddEnterIfTrigger(this, &CVeneratedLoxodonCard::SetEnterContext, &CVeneratedLoxodonCard::BeforeCounters);
}

bool CVeneratedLoxodonCard::BeforeMainResolution(CAbilityAction* pAction)
{
	while (m_Convoked.GetSize() > 0)
		m_Convoked.RemoveCard(m_Convoked.GetAt(0));
	return true;
}

bool CVeneratedLoxodonCard::BeforeConvokedResolution(CAbilityAction* pAction)
{
	BeforeMainResolution(pAction);

	const CCountedCardContainer* pTapped = pAction->GetCostConfigEntry().GetTapCards();
	if (pTapped)
		for (int i = 0; i < pTapped->GetSize(); ++i)
			m_Convoked.AddCard(pTapped->GetAt(i), CardPlacement::Top);
	return true;
}

bool CVeneratedLoxodonCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Cast && m_Convoked.GetSize() > 0;
}

bool CVeneratedLoxodonCard::BeforeCounters(CAbilityAction* pAction)
{
	while (m_Convoked.GetSize() > 0)
	{
		CCard* pCard = m_Convoked.GetAt(0);
		m_Convoked.RemoveCard(pCard);
		if (pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetCardType().IsCreature())
			AddPlusCounter(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

CAffectionateIndrikCard::CAffectionateIndrikCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Affectionate Indrik"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("5") GREEN_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you may have it fight target creature you don't control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CAffectionateIndrikCard::BeforeFight, true, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CAffectionateIndrikCard::BeforeFight(CAbilityAction* pAction)
{
	Fight(this, pAction->GetAssociatedCard());
	return false;
}

CArboretumElementalCard::CArboretumElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Arboretum Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("7") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(5))
{
	// Convoke (partial: the creatures pay only generic mana). Hexproof
	AddPermanentConvoke(this, 7, GREEN_MANA_TEXT GREEN_MANA_TEXT);
	GetCardKeyword()->AddHexproof(FALSE);
}

CBeastWhispererCard::CBeastWhispererCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Beast Whisperer"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cast a creature spell, draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBeastWhispererCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CBeastWhispererCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDevkarinDissidentCard::CDevkarinDissidentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Devkarin Dissident"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {4}{G}: This creature gets +2/+2 until end of turn.
	AddPumpAbility(this, _T("4") GREEN_MANA_TEXT, _T("+2/+2 until end of turn. Activates"), &CDevkarinDissidentCard::BeforePump);
}

bool CDevkarinDissidentCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +2);
	return true;
}

CDistrictGuideCard::CDistrictGuideCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("District Guide"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_LandFilter(_T("a basic land card or Gate card"), _T("basic land cards or Gate cards"),
		new OrCardComparer(new CardTypeComparer(CardType::BasicLand, false), new CardTypeComparer(CardType::Gate, false)))
{
	// When this creature enters, you may search your library for a basic land card or Gate card, reveal it, put it into
	// your hand, then shuffle.
	AddEnterTrigger(this, &CDistrictGuideCard::BeforeSearch, true);
}

bool CDistrictGuideCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToHand(GetGame(), pAction->GetController(), 1, &m_LandFilter);
	return true;
}

CGenerousStrayCard::CGenerousStrayCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Generous Stray"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("2") GREEN_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CGenerousStrayCard::BeforeDraw);
}

bool CGenerousStrayCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CGolgariRaidersCard::CGolgariRaidersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Golgari Raiders"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("3") GREEN_MANA_TEXT, Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CGolgariRaidersCard::OnZoneChanged))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Undergrowth - This creature enters with a +1/+1 counter on it for each creature card in your graveyard.
	// (as AEther Figment in Zendikar)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CGolgariRaidersCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		int nCount = CountCreatureCardsInGraveyard(GetController());
		if (nCount > 0)
			CCardCounterModifier(_T("+1/+1"), nCount).ApplyTo(this);
	}
}

CGrapplingSundewCard::CGrapplingSundewCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grappling Sundew"), CardType::Creature, CREATURE_TYPE(Plant), nID,
		_T("1") GREEN_MANA_TEXT, Power(0), Life(4))
{
	// Defender, reach
	GetCreatureKeyword()->AddDefender(FALSE);
	GetCreatureKeyword()->AddReach(FALSE);

	// {4}{G}: This creature gains indestructible until end of turn.
	AddPumpAbility(this, _T("4") GREEN_MANA_TEXT, _T("Indestructible until end of turn. Activates"),
		&CGrapplingSundewCard::BeforeIndestructible);
}

bool CGrapplingSundewCard::BeforeIndestructible(CAbilityAction* pAction)
{
	GainCardKeyword(this, CardKeyword::Indestructible);
	return true;
}

CHatcherySpiderCard::CHatcherySpiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hatchery Spider"), CardType::Creature, CREATURE_TYPE(Spider), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(7))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// Undergrowth - When you cast this spell, reveal the top X cards of your library, where X is the number of creature
	// cards in your graveyard. You may put a green permanent card with mana value X or less from among them onto the
	// battlefield. Put the rest on the bottom of your library in a random order.
	// (as Decimator of the Provinces in Eldritch Moon; the rest go to the bottom in any order)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHatcherySpiderCard::BeforeReveal));
	AddAbility(cpAbility.GetPointer());
}

bool CHatcherySpiderCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nX = CountCreatureCardsInGraveyard(pController);
	if (nX <= 0)
		return true;

	CCardFilter filter(_T("a green permanent card"), _T("green permanent cards"),
		new AndCardComparer(
			new AndCardComparer(new CardTypeComparer(CardType::Green, false),
				new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false))),
			new ConvertedManaCostComparer<std::less_equal<int>>(nX)));

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nX,
		CZoneModifier::RoleType::AllPlayers, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &filter,
		ZoneId::Battlefield, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);
	return true;
}

CImperviousGreatwurmCard::CImperviousGreatwurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Impervious Greatwurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("7") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(16), Life(16))
{
	// Convoke (partial: the creatures pay only generic mana). Indestructible
	AddPermanentConvoke(this, 7, GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT);
	GetCardKeyword()->AddIndestructible(FALSE);
}

CKraulForagersCard::CKraulForagersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kraul Foragers"), CardType::Creature, CREATURE_TYPE2(Insect, Scout), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Undergrowth - When this creature enters, you gain 1 life for each creature card in your graveyard.
	AddEnterTrigger(this, &CKraulForagersCard::BeforeGainLife);
}

bool CKraulForagersCard::BeforeGainLife(CAbilityAction* pAction)
{
	int nCount = CountCreatureCardsInGraveyard(pAction->GetController());
	if (nCount > 0)
		GainLife(this, pAction->GetController(), nCount);
	return true;
}

CKraulHarpoonerCard::CKraulHarpoonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kraul Harpooner"), CardType::Creature, CREATURE_TYPE2(Insect, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// Undergrowth - When this creature enters, choose up to one target creature you don't control with flying. This
	// creature gets +X/+0 until end of turn, where X is the number of creature cards in your graveyard, then you may
	// have this creature fight that creature. (partial: it always fights)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CKraulHarpoonerCard::BeforeFight, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false));
	pTargeting->SetIncludeNonControllerCardsOnly();
	pTargeting->SetSubjectCount(0, 1);
}

bool CKraulHarpoonerCard::BeforeFight(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return false;

	int nX = CountCreatureCardsInGraveyard(pAction->GetController());
	if (nX > 0)
		PumpCreature(this, nX, 0);

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard)
		Fight(this, pCard);
	return false;
}

CNullhideFeroxCard::CNullhideFeroxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nullhide Ferox"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
	, m_NoncreatureFilter(_T("a noncreature card"), _T("noncreature cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Creature, false)))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);

	// You can't cast noncreature spells. (as Gaddock Teeg in Lorwyn)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::CantPlaySpells,
			(int)&m_NoncreatureFilter));

	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());

	// Not implemented: "{2}: This creature loses all abilities until end of turn. Any player may activate this ability."
	// and "If a spell or ability an opponent controls causes you to discard this card, put it onto the battlefield".
}

CPeltCollectorCard::CPeltCollectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pelt Collector"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever another creature you control enters or dies, if that creature's power is greater than this creature's,
	// put a +1/+1 counter on this creature.
	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPeltCollectorCard::SetEnterContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPeltCollectorCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPeltCollectorCard::SetDiesContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPeltCollectorCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// As long as this creature has three or more +1/+1 counters on it, it has trample.
	counted_ptr<CPwrTghAttrEnchantment> cpTrample(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this),
				new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 3)),
			Power(+0), Life(+0), CreatureKeyword::Trample));
	AddAbility(cpTrample.GetPointer());
}

bool CPeltCollectorCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
	return pCard != this && pCreature && GetZoneId() == ZoneId::Battlefield &&
		GET_INTEGER(pCreature->GetPower()) > GET_INTEGER(GetPower());
}

bool CPeltCollectorCard::SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
	return pCard != this && pCreature && GetZoneId() == ZoneId::Battlefield &&
		GET_INTEGER(pCreature->GetLastKnownPower()) > GET_INTEGER(GetPower());
}

bool CPeltCollectorCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this);
	return true;
}

CPortcullisVineCard::CPortcullisVineCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Portcullis Vine"), CardType::Creature, CREATURE_TYPE2(Plant, Wall), nID,
		GREEN_MANA_TEXT, Power(0), Life(3))
	, m_DefenderFilter(_T("a creature with defender"), _T("creatures with defender"),
		new AndCardComparer(new AnyCreatureComparer, new CreatureKeywordComparer(CreatureKeyword::Defender, false)))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {2}, {T}, Sacrifice a creature with defender: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("2"), 1));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_DefenderFilter);
	AddAbility(cpAbility.GetPointer());
}

CSiegeWurmCard::CSiegeWurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Siege Wurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Convoke (partial: the creatures pay only generic mana). Trample
	AddPermanentConvoke(this, 5, GREEN_MANA_TEXT GREEN_MANA_TEXT);
	GetCreatureKeyword()->AddTrample(FALSE);
}

CVigorsporeWurmCard::CVigorsporeWurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vigorspore Wurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("5") GREEN_MANA_TEXT, Power(6), Life(4))
{
	// Undergrowth - When this creature enters, target creature gains vigilance and gets +X/+X until end of turn, where X
	// is the number of creature cards in your graveyard.
	AddEnterTargetTrigger(this, &CVigorsporeWurmCard::BeforePump, false, Characteristic::Positive);

	// This creature can't be blocked by more than one creature.
	GetCreatureKeyword()->AddCantBeBlockedByMultiple(FALSE);
}

bool CVigorsporeWurmCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		int nX = CountCreatureCardsInGraveyard(pAction->GetController());
		PumpCreature(pCard, nX, nX, CreatureKeyword::Vigilance);
	}
	return false;
}

CWaryOkapiCard::CWaryOkapiCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wary Okapi"), CardType::Creature, CREATURE_TYPE(Antelope), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CWildCeratokCard::CWildCeratokCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wild Ceratok"), CardType::Creature, CREATURE_TYPE(Rhino), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

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

CArclightPhoenixCard::CArclightPhoenixCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Arclight Phoenix"), CardType::Creature, CREATURE_TYPE(Phoenix), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(2))
	, m_nTurn(-1)
	, m_nSpells(0)
{
	// Flying, haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// (counts the instant and sorcery spells its controller casts this turn, from any zone, without triggering)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack, FALSE, TRUE, FALSE));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CArclightPhoenixCard::SetCastContext));
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of combat on your turn, if you've cast three or more instant and sorcery spells this turn, return
	// this card from your graveyard to the battlefield.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep, FALSE));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetPlayableFrom(ZoneId::Graveyard);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CArclightPhoenixCard::SetCombatContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArclightPhoenixCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CArclightPhoenixCard::SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (moveType != MoveType::Cast)
		return false;

	if (GetGame()->GetGameTurnNumber() != m_nTurn)
	{
		m_nTurn = GetGame()->GetGameTurnNumber();
		m_nSpells = 0;
	}
	++m_nSpells;
	return false;
}

bool CArclightPhoenixCard::SetCombatContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetZoneId() == ZoneId::Graveyard && GetGame()->GetActivePlayer() == GetController() &&
		m_nTurn == GetGame()->GetGameTurnNumber() && m_nSpells >= 3;
}

bool CArclightPhoenixCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, GetOwner()).ApplyTo(this);
	return true;
}

CBargingSergeantCard::CBargingSergeantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Barging Sergeant"), CardType::Creature, CREATURE_TYPE2(Minotaur, Soldier), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(2))
	, m_Mentor(this)
{
	// Haste. Mentor
	GetCreatureKeyword()->AddHaste(FALSE);
	m_Mentor.AddMentorAbility();
}

CBookDevourerCard::CBookDevourerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Book Devourer"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("5") RED_MANA_TEXT, Power(4), Life(5))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever this creature deals combat damage to a player, you may discard all the cards in your hand. If you do, draw
	// that many cards.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBookDevourerCard::BeforeWheel));
	AddAbility(cpAbility.GetPointer());
}

bool CBookDevourerCard::BeforeWheel(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

	CCountedCardContainer cards;
	for (int i = 0; i < pHand->GetSize(); ++i)
		cards.AddCard(pHand->GetAt(i), CardPlacement::Top);

	int nDiscarded = 0;
	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard).ApplyTo(cards.GetAt(i));
		if (cards.GetAt(i)->GetZoneId() != ZoneId::Hand)
			++nDiscarded;
	}

	if (nDiscarded > 0)
		DrawCards(GetGame(), pController, nDiscarded);
	return true;
}

CElectrostaticFieldCard::CElectrostaticFieldCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Electrostatic Field"), CardType::Creature, CREATURE_TYPE(Wall), nID,
		_T("1") RED_MANA_TEXT, Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// Whenever you cast an instant or sorcery spell, this creature deals 1 damage to each opponent.
	AddInstantSorceryCastTrigger(this, &CElectrostaticFieldCard::BeforeDamage);
}

bool CElectrostaticFieldCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

CErraticCyclopsCard::CErraticCyclopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Erratic Cyclops"), CardType::Creature, CREATURE_TYPE2(Cyclops, Shaman), nID,
		_T("3") RED_MANA_TEXT, Power(0), Life(8))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever you cast an instant or sorcery spell, this creature gets +X/+0 until end of turn, where X is that spell's
	// mana value. (the mana value is kept in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CErraticCyclopsCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CErraticCyclopsCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CErraticCyclopsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	triggerContext.nValue1 = (DWORD)pCard->GetConvertedManaCost();
	return true;
}

bool CErraticCyclopsCard::BeforePump(TriggeredAbility::TriggeredActionType* pAction)
{
	int nX = (int)pAction->GetTriggerContext().nValue1;
	if (nX > 0 && GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, nX, 0);
	return true;
}

CFearlessHalberdierCard::CFearlessHalberdierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fearless Halberdier"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
}

CFireUrchinCard::CFireUrchinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fire Urchin"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever you cast an instant or sorcery spell, this creature gets +1/+0 until end of turn.
	AddInstantSorceryCastTrigger(this, &CFireUrchinCard::BeforePump);
}

bool CFireUrchinCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, 0);
	return true;
}

CGoblinBanneretCard::CGoblinBanneretCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Banneret"), CardType::Creature, CREATURE_TYPE2(Goblin, Soldier), nID,
		RED_MANA_TEXT, Power(1), Life(1))
	, m_Mentor(this)
{
	// Mentor
	m_Mentor.AddMentorAbility();

	// {1}{R}: This creature gets +2/+0 until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("+2/+0 until end of turn. Activates"), &CGoblinBanneretCard::BeforePump);
}

bool CGoblinBanneretCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, 0);
	return true;
}

CGoblinCratermakerCard::CGoblinCratermakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Cratermaker"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// {1}, Sacrifice this creature: Choose one -
	// * This creature deals 2 damage to target creature.
	{
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this, _T("1"),
				new AnyCreatureComparer, FALSE, Life(-2), PreventableType::Preventable));

		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->AddSacrificeCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	// * Destroy target colorless nonland permanent.
	{
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this, _T("1"),
				new AndCardComparer(new ColorlessComparer,
					new NegateCardComparer(new CardTypeComparer(CardType::_Land, false))),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->AddSacrificeCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

CGoblinLocksmithCard::CGoblinLocksmithCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Locksmith"), CardType::Creature, CREATURE_TYPE2(Goblin, Rogue), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks, creatures with defender can't block this turn.
	AddSelfAttackTrigger(this, &CGoblinLocksmithCard::BeforeCantBlock);
}

bool CGoblinLocksmithCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CreatureKeywordComparer defender(CreatureKeyword::Defender, false);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), GetGame()->GetPlayer(ip), TRUE, creatures);
		for (int i = 0; i < creatures.GetSize(); ++i)
			if (defender(creatures.GetAt(i)))
				PumpCreature(creatures.GetAt(i), 0, 0, CreatureKeyword::CantBlock);
	}
	return true;
}

CHellkiteWhelpCard::CHellkiteWhelpCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Hellkite Whelp"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("4") RED_MANA_TEXT, Power(3), Life(3))
{
	// Flying. Whenever this creature attacks, it deals 1 damage to target creature defending player controls.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CHellkiteWhelpCard::BeforeDamage, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CHellkiteWhelpCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToCreature(this, pAction->GetAssociatedCard(), 1);
	return false;
}

CLegionWarbossCard::CLegionWarbossCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Legion Warboss"), CardType::Creature, CREATURE_TYPE2(Goblin, Soldier), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
	, m_Mentor(this)
{
	// Mentor
	m_Mentor.AddMentorAbility();

	// At the beginning of combat on your turn, create a 1/1 red Goblin creature token. That token gains haste until end
	// of turn and attacks this combat if able. (as Goblin Rabblemaster in M15)
	AddStepTrigger<CLegionWarbossCard>(this, NodeId::BeginningOfCombatStep, false, NULL, &CLegionWarbossCard::BeforeToken);
}

bool CLegionWarbossCard::BeforeToken(CAbilityAction* pAction)
{
	CCountedCardContainer tokens;
	CTokenCreationModifier(GetGame(), _T("Goblin (C)"), 2702, 1, FALSE, ZoneId::Battlefield, &tokens).ApplyTo(pAction->GetController());
	for (int i = 0; i < tokens.GetSize(); ++i)
	{
		CCreatureCard* pToken = dynamic_cast<CCreatureCard*>(tokens.GetAt(i));
		if (pToken)
		{
			pToken->GetCreatureKeyword()->AddHaste(TRUE);
			pToken->GetCreatureKeyword()->AddMustAttack(TRUE);
		}
	}
	return true;
}

COrneryGoblinCard::COrneryGoblinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ornery Goblin"), CardType::Creature, CREATURE_TYPE2(Goblin, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature blocks or becomes blocked by a creature, this creature deals 1 damage to that creature.
	// (as Frostweb Spider in Coldsnap; the other creature is kept in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COrneryGoblinCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &COrneryGoblinCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool COrneryGoblinCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const
{
	CCreatureCard* pOther = (pCreature2 && pCreature2 != this) ? pCreature2 : pCreature;
	if (!pOther || pOther == this)
		return false;

	triggerContext.nValue1 = (DWORD)pOther;
	return true;
}

bool COrneryGoblinCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (pCard)
		DealDamageToCreature(this, pCard, 1);
	return true;
}

CRubblebeltBoarCard::CRubblebeltBoarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rubblebelt Boar"), CardType::Creature, CREATURE_TYPE(Boar), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, target creature gets +2/+0 until end of turn.
	AddEnterTargetTrigger(this, &CRubblebeltBoarCard::BeforePump, false, Characteristic::Positive);
}

bool CRubblebeltBoarCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, +2, 0);
	return false;
}

CRunawaySteamKinCard::CRunawaySteamKinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Runaway Steam-Kin"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(1))
{
	// Whenever you cast a red spell, if this creature has fewer than three +1/+1 counters on it, put a +1/+1 counter on
	// this creature.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Red, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRunawaySteamKinCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRunawaySteamKinCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// Remove three +1/+1 counters from this creature: Add {R}{R}{R}.
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT));

		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("+1/+1")), -3);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRunawaySteamKinCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return CountCounters(this, _T("+1/+1")) < 3;
}

bool CRunawaySteamKinCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield && CountCounters(this, _T("+1/+1")) < 3)
		AddPlusCounter(this);
	return true;
}

CSmeltWardMinotaurCard::CSmeltWardMinotaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Smelt-Ward Minotaur"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cast an instant or sorcery spell, target creature an opponent controls can't block this turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSmeltWardMinotaurCard::BeforeCantBlock));
	AddAbility(cpAbility.GetPointer());
}

bool CSmeltWardMinotaurCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, 0, 0, CreatureKeyword::CantBlock);
	return false;
}

CTorchCourierCard::CTorchCourierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Torch Courier"), CardType::Creature, CREATURE_TYPE(Goblin), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Sacrifice this creature: Another target creature gains haste until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this, _T(""),
			Power(+0), Life(+0), CreatureKeyword::Haste, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CWojekBodyguardCard::CWojekBodyguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wojek Bodyguard"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(3))
	, m_Mentor(this)
{
	// Mentor
	m_Mentor.AddMentorAbility();

	// Not implemented: "This creature can't attack or block alone." (the engine has no such restriction)
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

CBarrierOfBonesCard::CBarrierOfBonesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Barrier of Bones"), CardType::Creature, CREATURE_TYPE2(Skeleton, Wall), nID,
		BLACK_MANA_TEXT, Power(0), Life(3))
{
	// Defender. When this creature enters, surveil 1.
	GetCreatureKeyword()->AddDefender(FALSE);
	AddEnterTrigger(this, &CBarrierOfBonesCard::BeforeSurveil);
}

bool CBarrierOfBonesCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CBartizanBatsCard::CBartizanBatsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bartizan Bats"), CardType::Creature, CREATURE_TYPE(Bat), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(1))
{
}

CBloodOperativeCard::CBloodOperativeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blood Operative"), CardType::Creature, CREATURE_TYPE2(Vampire, Assassin), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(1))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CBloodOperativeCard::OnCardSelected))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, you may exile target card from a graveyard.
	// (partial: the card is chosen on resolution, it isn't targeted)
	AddEnterTrigger(this, &CBloodOperativeCard::BeforeExile, true);

	// Whenever you surveil, if this card is in your graveyard, you may pay 3 life. If you do, return this card to your
	// hand. (as AddWheneverYouSurveilTrigger, listening in the graveyard)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetTriggerIndex(SURVEIL_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(this));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Graveyard);
	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBloodOperativeCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CBloodOperativeCard::BeforeExile(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pCard = pGraveyard->GetAt(i);
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

void CBloodOperativeCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() == ZoneId::Graveyard)
			CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
	}
}

bool CBloodOperativeCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Graveyard)
		return true;

	// Pay 3 life (life loss, not damage)
	CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage).ApplyTo(GetOwner());
	CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(this);
	return true;
}

CBurglarRatCard::CBurglarRatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Burglar Rat"), CardType::Creature, CREATURE_TYPE(Rat), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, each opponent discards a card.
	AddEnterTrigger(this, &CBurglarRatCard::BeforeDiscard);
}

bool CBurglarRatCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		if (GetGame()->GetPlayer(i) != pAction->GetController())
			DiscardCards(GetGame(), GetGame()->GetPlayer(i), 1);
	return true;
}

CDoomWhispererCard::CDoomWhispererCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Doom Whisperer"), CardType::Creature, CREATURE_TYPE2(Nightmare, Demon), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(6))
{
	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Pay 2 life: Surveil 2.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->AddPayLifeDeltaCost(Life(-2));
	cpAbility->SetAbilityText(_T("Surveil 2"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDoomWhispererCard::BeforeSurveil));
	AddAbility(cpAbility.GetPointer());
}

bool CDoomWhispererCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CDouserOfLightsCard::CDouserOfLightsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Douser of Lights"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		_T("4") BLACK_MANA_TEXT, Power(4), Life(5))
{
}

CHiredPoisonerCard::CHiredPoisonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hired Poisoner"), CardType::Creature, CREATURE_TYPE2(Human, Assassin), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);
}

CKraulRaiderCard::CKraulRaiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kraul Raider"), CardType::Creature, CREATURE_TYPE2(Insect, Warrior), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CKraulSwarmCard::CKraulSwarmCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kraul Swarm"), CardType::Creature, CREATURE_TYPE2(Insect, Warrior), nID,
		_T("4") BLACK_MANA_TEXT, Power(4), Life(1))
{
	// Flying. {2}{B}, Discard a creature card: Return this card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") BLACK_MANA_TEXT));

	cpAbility->SetPlayableFrom(ZoneId::Graveyard);
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetAbilityText(_T("Return this card from your graveyard to your hand"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKraulSwarmCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CKraulSwarmCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
		CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(this);
	return true;
}

CLotlethGiantCard::CLotlethGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lotleth Giant"), CardType::Creature, CREATURE_TYPE2(Zombie, Giant), nID,
		_T("6") BLACK_MANA_TEXT, Power(6), Life(5))
{
	// Undergrowth - When this creature enters, it deals 1 damage to target opponent for each creature card in your
	// graveyard.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLotlethGiantCard::BeforeDamage));
	AddAbility(cpAbility.GetPointer());
}

bool CLotlethGiantCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToPlayer(this, pAction->GetAssociatedPlayer(), CountCreatureCardsInGraveyard(pAction->GetController()));
	return false;
}

CMidnightReaperCard::CMidnightReaperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Midnight Reaper"), CardType::Creature, CREATURE_TYPE2(Zombie, Knight), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Whenever a nontoken creature you control dies, this creature deals 1 damage to you and you draw a card.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CardTypeComparer(CardType::Token, false)));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMidnightReaperCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CMidnightReaperCard::BeforeDraw(CAbilityAction* pAction)
{
	DealDamageToPlayer(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CMoodmarkPainterCard::CMoodmarkPainterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Moodmark Painter"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Undergrowth - When this creature enters, target creature gains menace and gets +X/+0 until end of turn, where X is
	// the number of creature cards in your graveyard.
	AddEnterTargetTrigger(this, &CMoodmarkPainterCard::BeforePump, false, Characteristic::Positive);
}

bool CMoodmarkPainterCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, CountCreatureCardsInGraveyard(pAction->GetController()), 0, CreatureKeyword::CantBeBlockedBy1);
	return false;
}

CPilferingImpCard::CPilferingImpCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Pilfering Imp"), CardType::Creature, CREATURE_TYPE(Imp), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
	, m_NonlandFilter(_T("a nonland card"), _T("nonland cards"), new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Flying. {1}{B}, {T}, Sacrifice this creature: Target opponent reveals their hand. You choose a nonland card from
	// it. That player discards that card. Activate only as a sorcery. (as Dark Inquiry)
	counted_ptr<CActivatedAbility<CTargetPlayerDiscardCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetPlayerDiscardCardSpell>>(this,
			_T("1") BLACK_MANA_TEXT,
			1, MoveType::Discard, ZoneId::Graveyard, TRUE,
			FALSE,
			&m_NonlandFilter));

	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CPlaguecrafterCard::CPlaguecrafterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Plaguecrafter"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
	, m_SacrificeFilter(_T("a creature or planeswalker"), _T("creatures or planeswalkers"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
{
	// When this creature enters, each player sacrifices a creature or planeswalker of their choice. Each player who
	// can't discards a card.
	AddEnterTrigger(this, &CPlaguecrafterCard::BeforeSacrifice);
}

bool CPlaguecrafterCard::BeforeSacrifice(CAbilityAction* pAction)
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(i);
		if (m_SacrificeFilter.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
			ChooseAndMove(GetGame(), pPlayer, ZoneId::Battlefield, 1, 1, &m_SacrificeFilter, ZoneId::Graveyard, MoveType::Sacrifice);
		else
			DiscardCards(GetGame(), pPlayer, 1);
	}
	return true;
}

CSpinalCentipedeCard::CSpinalCentipedeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spinal Centipede"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
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
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpinalCentipedeCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CSpinalCentipedeCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(pCard);
	return false;
}

CUndercityNecroliskCard::CUndercityNecroliskCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Undercity Necrolisk"), CardType::Creature, CREATURE_TYPE2(Zombie, Lizard), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// {1}, Sacrifice another creature: Put a +1/+1 counter on this creature. It gains menace until end of turn. Activate
	// only as a sorcery.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1")));

	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
	cpAbility->SetAbilityText(_T("+1/+1 counter and menace. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUndercityNecroliskCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CUndercityNecroliskCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		AddPlusCounter(this);
		PumpCreature(this, 0, 0, CreatureKeyword::CantBeBlockedBy1);
	}
	return true;
}

CVeiledShadeCard::CVeiledShadeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Veiled Shade"), CardType::Creature, CREATURE_TYPE(Shade), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// {1}{B}: This creature gets +1/+1 until end of turn.
	AddPumpAbility(this, _T("1") BLACK_MANA_TEXT, _T("+1/+1 until end of turn. Activates"), &CVeiledShadeCard::BeforePump);
}

bool CVeiledShadeCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

CWhisperingSnitchCard::CWhisperingSnitchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Whispering Snitch"), CardType::Creature, CREATURE_TYPE2(Vampire, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(3))
	, m_nTurn(-1)
{
	// Whenever you surveil for the first time each turn, this creature deals 1 damage to each opponent and you gain 1
	// life. (the trigger does nothing after the first one of the turn)
	AddWheneverYouSurveilTrigger(this, &CWhisperingSnitchCard::BeforeDrain);
}

bool CWhisperingSnitchCard::BeforeDrain(CAbilityAction* pAction)
{
	if (m_nTurn == GetGame()->GetGameTurnNumber())
		return true;

	m_nTurn = GetGame()->GetGameTurnNumber();
	DamageEachOpponent(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

CCitywatchSphinxCard::CCitywatchSphinxCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Citywatch Sphinx"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("5") BLUE_MANA_TEXT, Power(5), Life(4))
{
	// Flying. When this creature dies, surveil 2.
	AddDiesTrigger(this, &CCitywatchSphinxCard::BeforeSurveil);
}

bool CCitywatchSphinxCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CDimirInformantCard::CDimirInformantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dimir Informant"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// When this creature enters, surveil 2.
	AddEnterTrigger(this, &CDimirInformantCard::BeforeSurveil);
}

bool CDimirInformantCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CDreamEaterCard::CDreamEaterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dream Eater"), CardType::Creature, CREATURE_TYPE2(Nightmare, Sphinx), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(3))
{
	// Flash. Flying
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, surveil 4. When you do, you may return target nonland permanent an opponent controls to
	// its owner's hand. (partial: the target, up to one, is chosen when the creature enters, before surveilling)
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CDreamEaterCard::BeforeSurveil, false, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	pTargeting->SetIncludeNonControllerCardsOnly();
	pTargeting->SetSubjectCount(0, 1);
}

bool CDreamEaterCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 4, this).ApplyTo(pAction->GetController());

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others).ApplyTo(pCard);
	return false;
}

CLeapfrogCard::CLeapfrogCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Leapfrog"), CardType::Creature, CREATURE_TYPE(Frog), nID,
		_T("2") BLUE_MANA_TEXT, Power(3), Life(1))
{
	// This creature has flying as long as you've cast an instant or sorcery spell this turn.
	// Partial: whenever you cast an instant or sorcery spell, it gains flying until end of turn (spells cast before it
	// entered this turn don't count)
	AddInstantSorceryCastTrigger(this, &CLeapfrogCard::BeforeFlying);
}

bool CLeapfrogCard::BeforeFlying(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::Flying);
	return true;
}

CMurmuringMysticCard::CMurmuringMysticCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Murmuring Mystic"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("3") BLUE_MANA_TEXT, Power(1), Life(5))
{
	// Whenever you cast an instant or sorcery spell, create a 1/1 blue Bird Illusion creature token with flying.
	AddInstantSorceryCastTrigger(this, &CMurmuringMysticCard::BeforeToken);
}

bool CMurmuringMysticCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Bird Illusion (A)"), 55120, 1).ApplyTo(pAction->GetController());
	return true;
}

CMuseDrakeCard::CMuseDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Muse Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("3") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// Flying. When this creature enters, draw a card.
	AddEnterTrigger(this, &CMuseDrakeCard::BeforeDraw);
}

bool CMuseDrakeCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CNightveilSpriteCard::CNightveilSpriteCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Nightveil Sprite"), CardType::Creature, CREATURE_TYPE2(Faerie, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// Flying. Whenever this creature attacks, surveil 1.
	AddSelfAttackTrigger(this, &CNightveilSpriteCard::BeforeSurveil);
}

bool CNightveilSpriteCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CPasswallAdeptCard::CPasswallAdeptCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Passwall Adept"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// {2}{U}: Target creature can't be blocked this turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this, _T("2") BLUE_MANA_TEXT,
			Power(+0), Life(+0), CreatureKeyword::Unblockable, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CThoughtboundPhantasmCard::CThoughtboundPhantasmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thoughtbound Phantasm"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Defender. As long as this creature has three or more +1/+1 counters on it, it can attack as though it didn't have
	// defender. (defender is a static ability that only applies with fewer than three counters, as Novice Knight in M19)
	counted_ptr<CPwrTghAttrEnchantment> cpDefender(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AndCardComparer(new SpecificCardComparer(this),
				new NegateCardComparer(new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 3))),
			Power(+0), Life(+0), CreatureKeyword::Defender));
	AddAbility(cpDefender.GetPointer());

	// Whenever you surveil, put a +1/+1 counter on this creature.
	AddWheneverYouSurveilTrigger(this, &CThoughtboundPhantasmCard::BeforeCounter);
}

bool CThoughtboundPhantasmCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this);
	return true;
}

CVedalkenMesmeristCard::CVedalkenMesmeristCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vedalken Mesmerist"), CardType::Creature, CREATURE_TYPE2(Vedalken, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks, target creature an opponent controls gets -2/-0 until end of turn.
	CTargeting* pTargeting = AddSelfAttackTargetTrigger(this, &CVedalkenMesmeristCard::BeforeShrink, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CVedalkenMesmeristCard::BeforeShrink(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		PumpCreature(pCard, -2, 0);
	return false;
}

CWatcherInTheMistCard::CWatcherInTheMistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Watcher in the Mist"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(4))
{
	// Flying. When this creature enters, surveil 2.
	AddEnterTrigger(this, &CWatcherInTheMistCard::BeforeSurveil);
}

bool CWatcherInTheMistCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CWishcoinCrabCard::CWishcoinCrabCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wishcoin Crab"), CardType::Creature, CREATURE_TYPE(Crab), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(5))
{
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

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

CAttendantOfVraskaCard::CAttendantOfVraskaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Attendant of Vraska"), CardType::Creature, CREATURE_TYPE2(Zombie, Soldier), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// When this creature dies, if you control a Vraska planeswalker, you gain life equal to this creature's power.
	// (the condition is checked on resolution)
	AddDiesTrigger(this, &CAttendantOfVraskaCard::BeforeGainLife);
}

bool CAttendantOfVraskaCard::BeforeGainLife(CAbilityAction* pAction)
{
	if (ControlsPlaneswalker(pAction->GetController(), PlaneswalkerType::Vraska))
	{
		int nPower = GET_INTEGER(GetLastKnownPower());
		if (nPower > 0)
			GainLife(this, pAction->GetController(), nPower);
	}
	return true;
}

CAureliaExemplarOfJusticeCard::CAureliaExemplarOfJusticeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aurelia, Exemplar of Justice"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Angel), nID,
		_T("2") RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(5))
	, m_Mentor(this)
{
	// Flying. Mentor
	m_Mentor.AddMentorAbility();

	// At the beginning of combat on your turn, choose up to one target creature you control. Until end of turn, that
	// creature gets +2/+0, gains trample if it's red, and gains vigilance if it's white.
	CTargeting* pTargeting = AddStepTargetTrigger<CAureliaExemplarOfJusticeCard>(this, NodeId::BeginningOfCombatStep, NULL,
		&CAureliaExemplarOfJusticeCard::BeforePump, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->SetSubjectCount(0, 1);
}

bool CAureliaExemplarOfJusticeCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	PumpCreature(pCard, +2, 0);
	if ((pCard->GetCardType() & CardType::Red).Any())
		PumpCreature(pCard, 0, 0, CreatureKeyword::Trample);
	if ((pCard->GetCardType() & CardType::White).Any())
		PumpCreature(pCard, 0, 0, CreatureKeyword::Vigilance);
	return false;
}

CBorosChallengerCard::CBorosChallengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Boros Challenger"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Mentor(this)
{
	// Mentor
	m_Mentor.AddMentorAbility();

	// {2}{R}{W}: This creature gets +1/+1 until end of turn.
	AddPumpAbility(this, _T("2") RED_MANA_TEXT WHITE_MANA_TEXT, _T("+1/+1 until end of turn. Activates"), &CBorosChallengerCard::BeforePump);
}

bool CBorosChallengerCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +1, +1);
	return true;
}

CCentaurPeacemakerCard::CCentaurPeacemakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Centaur Peacemaker"), CardType::Creature, CREATURE_TYPE2(Centaur, Cleric), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, each player gains 4 life.
	AddEnterTrigger(this, &CCentaurPeacemakerCard::BeforeGainLife);
}

bool CCentaurPeacemakerCard::BeforeGainLife(CAbilityAction* pAction)
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		GainLife(this, GetGame()->GetPlayer(i), 4);
	return true;
}

CCharnelTrollCard::CCharnelTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charnel Troll"), CardType::Creature, CREATURE_TYPE(Troll), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// At the beginning of your upkeep, exile a creature card from your graveyard. If you do, put a +1/+1 counter on this
	// creature. Otherwise, sacrifice it.
	AddStepTrigger<CCharnelTrollCard>(this, NodeId::UpkeepStep, false, NULL, &CCharnelTrollCard::BeforeUpkeep);

	// {B}{G}, Discard a creature card: Put a +1/+1 counter on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, BLACK_MANA_TEXT GREEN_MANA_TEXT));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCharnelTrollCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CCharnelTrollCard::BeforeUpkeep(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pAction->GetController();
	int nBefore = CountCreatureCardsInGraveyard(pController);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("creatures")),
		ZoneId::Exile, MoveType::Others);

	if (CountCreatureCardsInGraveyard(pController) < nBefore)
		AddPlusCounter(this);
	else
		SacrificeSelf(this, pController);
	return true;
}

bool CCharnelTrollCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this);
	return true;
}

CConclaveCavalierCard::CConclaveCavalierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Conclave Cavalier"), CardType::Creature, CREATURE_TYPE2(Centaur, Knight), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Vigilance. When this creature dies, create two 2/2 green and white Elf Knight creature tokens with vigilance.
	GetCreatureKeyword()->AddVigilance(FALSE);
	AddDiesTrigger(this, &CConclaveCavalierCard::BeforeTokens);
}

bool CConclaveCavalierCard::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Elf Knight (A)"), 55119, 2).ApplyTo(pAction->GetController());
	return true;
}

CConclaveGuildmageCard::CConclaveGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Conclave Guildmage"), CardType::Creature, CREATURE_TYPE2(Elf, Cleric), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// {G}, {T}: Creatures you control gain trample until end of turn.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, GREEN_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Creatures you control gain trample. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConclaveGuildmageCard::BeforeTrample));
		AddAbility(cpAbility.GetPointer());
	}
	// {5}{W}, {T}: Create a 2/2 green and white Elf Knight creature token with vigilance.
	{
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this, _T("5") WHITE_MANA_TEXT,
				_T("Elf Knight (A)"), 55119, 1));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CConclaveGuildmageCard::BeforeTrample(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), 0, 0, CreatureKeyword::Trample);
	return true;
}

CCracklingDrakeCard::CCracklingDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Crackling Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(0), Life(4))
{
	// Flying. Crackling Drake's power is equal to the total number of instant and sorcery cards you own in exile and in
	// your graveyard. (one ability for each zone, as Multani in Dominaria)
	ZoneId zones[] = { ZoneId::Graveyard, ZoneId::Exile };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this, zones[i],
				new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)));
		cpAbility->SetChangePowerOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CCracklingDrakeCard::BeforeDraw);
}

bool CCracklingDrakeCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDarkbladeAgentCard::CDarkbladeAgentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Darkblade Agent"), CardType::Creature, CREATURE_TYPE2(Human, Assassin), nID,
		_T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
	, m_nSurveilTurn(-1)
{
	// As long as you've surveilled this turn, this creature has deathtouch and "Whenever this creature deals combat
	// damage to a player, you draw a card."
	// Partial: when you surveil (while it's on the battlefield) it gains deathtouch until end of turn and remembers the
	// turn for the draw trigger
	AddWheneverYouSurveilTrigger(this, &CDarkbladeAgentCard::BeforeSurveilled);

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDarkbladeAgentCard::SetDamageContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDarkbladeAgentCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CDarkbladeAgentCard::BeforeSurveilled(CAbilityAction* pAction)
{
	m_nSurveilTurn = GetGame()->GetGameTurnNumber();
	GainCardKeyword(this, CardKeyword::Deathtouch);
	return true;
}

bool CDarkbladeAgentCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	return m_nSurveilTurn == GetGame()->GetGameTurnNumber();
}

bool CDarkbladeAgentCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDimirSpybugCard::CDimirSpybugCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dimir Spybug"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Flying, menace. Whenever you surveil, put a +1/+1 counter on this creature.
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
	AddWheneverYouSurveilTrigger(this, &CDimirSpybugCard::BeforeCounter);
}

bool CDimirSpybugCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this);
	return true;
}

CEmmaraSoulOfTheAccordCard::CEmmaraSoulOfTheAccordCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emmara, Soul of the Accord"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Cleric), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever Emmara becomes tapped, create a 1/1 white Soldier creature token with lifelink.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfOrientationChanged,
						   CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetTapEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmmaraSoulOfTheAccordCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CEmmaraSoulOfTheAccordCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, 1).ApplyTo(pAction->GetController());
	return true;
}

CErstwhileTrooperCard::CErstwhileTrooperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Erstwhile Trooper"), CardType::Creature, CREATURE_TYPE2(Zombie, Soldier), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Discard a creature card: This creature gets +2/+2 and gains trample until end of turn. Activate only once each turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetMaxTurnUsageCount(1);
	cpAbility->SetAbilityText(_T("+2/+2 and trample until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CErstwhileTrooperCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CErstwhileTrooperCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, +2, +2, CreatureKeyword::Trample);
	return true;
}

CEtrataTheSilencerCard::CEtrataTheSilencerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Etrata, the Silencer"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Vampire, Assassin), nID,
		_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(5))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CEtrataTheSilencerCard::OnCreatureSelected))
{
	// Etrata can't be blocked.
	GetCreatureKeyword()->AddUnblockable(FALSE);

	// Whenever Etrata deals combat damage to a player, exile target creature that player controls and put a hit counter
	// on that card. That player loses the game if they own three or more exiled cards with hit counters on them.
	// Etrata's owner shuffles Etrata into their library.
	// (partial: the creature is chosen on resolution, it isn't targeted; the player is kept in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEtrataTheSilencerCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CEtrataTheSilencerCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());
}

bool CEtrataTheSilencerCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	triggerContext.nValue1 = (DWORD)pPlayer;
	return true;
}

bool CEtrataTheSilencerCard::BeforeExile(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;

	std::vector<SelectionEntry> entries;
	if (pPlayer)
	{
		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pPlayer, TRUE, creatures);
		for (int i = 0; i < creatures.GetSize(); ++i)
		{
			CCard* pCard = creatures.GetAt(i);
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (entries.empty())
		ShuffleIntoLibrary();
	else
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController(), (DWORD)pPlayer);
	return true;
}

void CEtrataTheSilencerCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;

		CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer).ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Exile)
			CCardCounterModifier(_T("hit counter"), +1).ApplyTo(pCard);
	}

	// That player loses the game if they own three or more exiled cards with hit counters on them
	CPlayer* pPlayer = (CPlayer*)dwContext1;
	if (pPlayer)
	{
		CardCounterComparer<std::greater_equal<int>> hit(_T("hit counter"), 1);
		CZone* pExile = pPlayer->GetZoneById(ZoneId::Exile);
		int nHit = 0;
		for (int i = 0; i < pExile->GetSize(); ++i)
			if (hit(pExile->GetAt(i)))
				++nHit;
		if (nHit >= 3)
			pPlayer->SetLostByOtherReasons();
	}

	ShuffleIntoLibrary();
}

void CEtrataTheSilencerCard::ShuffleIntoLibrary()
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others).ApplyTo(this);
	GetOwner()->GetZoneById(ZoneId::Library)->Shuffle();
}

CFreshFacedRecruitCard::CFreshFacedRecruitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fresh-Faced Recruit"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// {1}{R/W}
	AddHybridPermanentSpells(this, _T("1"), 1, RED_MANA_TEXT, WHITE_MANA_TEXT);

	// During your turn, this creature has first strike.
	// Partial (as Hardy Veteran in Rivals of Ixalan): it gains first strike at the beginning of your upkeep until end of turn
	AddStepTrigger<CFreshFacedRecruitCard>(this, NodeId::UpkeepStep, false, NULL, &CFreshFacedRecruitCard::BeforeFirstStrike);
}

bool CFreshFacedRecruitCard::BeforeFirstStrike(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::FirstStrike);
	return true;
}

CGarrisonSergeantCard::CGarrisonSergeantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Garrison Sergeant"), CardType::Creature, CREATURE_TYPE2(Lizard, Soldier), nID,
		_T("3") RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// This creature has double strike as long as you control a Gate. (as AddDinosaurKeyword)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::DoubleStrike));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Gate, false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CGatekeeperGargoyleCard::CGatekeeperGargoyleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Gatekeeper Gargoyle"), CardType::_ArtifactCreature, CREATURE_TYPE(Gargoyle), nID,
		_T("6"), Power(3), Life(3))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CGatekeeperGargoyleCard::OnZoneChanged))
{
	// Flying. This creature enters with a +1/+1 counter on it for each Gate you control. (as AEther Figment)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CGatekeeperGargoyleCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		int nGates = CCardFilter::GetFilter(_T("Gates"))->CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
		if (nGates > 0)
			CCardCounterModifier(_T("+1/+1"), nGates).ApplyTo(this);
	}
}

CGlowsporeShamanCard::CGlowsporeShamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glowspore Shaman"), CardType::Creature, CREATURE_TYPE2(Elf, Shaman), nID,
		BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(1))
{
	// When this creature enters, mill three cards. You may put a land card from your graveyard on top of your library.
	AddEnterTrigger(this, &CGlowsporeShamanCard::BeforeMill);
}

bool CGlowsporeShamanCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Mill(pController, 3);
	ChooseAndMove(GetGame(), pController, ZoneId::Graveyard, 0, 1, CCardFilter::GetFilter(_T("lands")),
		ZoneId::Library, MoveType::Others);
	return true;
}

CGolgariFindbrokerCard::CGolgariFindbrokerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Golgari Findbroker"), CardType::Creature, CREATURE_TYPE2(Elf, Shaman), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
	, m_PermanentFilter(_T("a permanent card"), _T("permanent cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)))
{
	// When this creature enters, return target permanent card from your graveyard to your hand.
	// (partial: the card is chosen on resolution, it isn't targeted)
	AddEnterTrigger(this, &CGolgariFindbrokerCard::BeforeReturn);
}

bool CGolgariFindbrokerCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, &m_PermanentFilter, ZoneId::Hand, MoveType::Others);
	return true;
}

CHammerDropperCard::CHammerDropperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hammer Dropper"), CardType::Creature, CREATURE_TYPE2(Giant, Soldier), nID,
		_T("2") RED_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(2))
	, m_Mentor(this)
{
	// Mentor
	m_Mentor.AddMentorAbility();
}

CHouseGuildmageCard::CHouseGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("House Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// {1}{U}, {T}: Target creature doesn't untap during its controller's next untap step.
	{
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("1") BLUE_MANA_TEXT, new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHouseGuildmageCard::BeforeNoUntap));
		AddAbility(cpAbility.GetPointer());
	}
	// {2}{B}, {T}: Surveil 2.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("2") BLACK_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Surveil 2"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHouseGuildmageCard::BeforeSurveil));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHouseGuildmageCard::BeforeNoUntap(CAbilityAction* pAction)
{
	// (as Watertrap Weaver in Ixalan, without tapping)
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pModifier.ApplyTo(pCard);
	return false;
}

bool CHouseGuildmageCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 2, this).ApplyTo(pAction->GetController());
	return true;
}

CIzoniThousandEyedCard::CIzoniThousandEyedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Izoni, Thousand-Eyed"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Elf, Shaman), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(3))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Undergrowth - When Izoni enters, create a 1/1 black and green Insect creature token for each creature card in your
	// graveyard.
	AddEnterTrigger(this, &CIzoniThousandEyedCard::BeforeTokens);

	// {B}{G}, Sacrifice another creature: You gain 1 life and draw a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, BLACK_MANA_TEXT GREEN_MANA_TEXT));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
	cpAbility->SetAbilityText(_T("Gain 1 life and draw a card. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIzoniThousandEyedCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CIzoniThousandEyedCard::BeforeTokens(CAbilityAction* pAction)
{
	int nCount = CountCreatureCardsInGraveyard(pAction->GetController());
	if (nCount > 0)
		CTokenCreationModifier(GetGame(), _T("Insect (L)"), 55121, nCount).ApplyTo(pAction->GetController());
	return true;
}

bool CIzoniThousandEyedCard::BeforeDraw(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CKnightOfAutumnCard::CKnightOfAutumnCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of Autumn"), CardType::Creature, CREATURE_TYPE2(Dryad, Knight), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(1))
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CKnightOfAutumnCard::OnModeSelected))
	, m_PermanentSelection(pGame, CSelectionSupport::SelectionCallback(this, &CKnightOfAutumnCard::OnPermanentSelected))
{
	// When this creature enters, choose one - Put two +1/+1 counters on this creature; or destroy target artifact or
	// enchantment; or you gain 4 life.
	// (partial: the mode is chosen on resolution, and so is the artifact or enchantment, which isn't targeted)
	AddEnterTrigger(this, &CKnightOfAutumnCard::BeforeChoice);
}

bool CKnightOfAutumnCard::BeforeChoice(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Put two +1/+1 counters on Knight of Autumn");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 2;
		entry.strText = _T("Destroy an artifact or enchantment");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 3;
		entry.strText = _T("You gain 4 life");
		entries.push_back(entry);
	}
	m_ModeSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CKnightOfAutumnCard::OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		if (it->dwContext == 1)
		{
			if (GetZoneId() == ZoneId::Battlefield)
				AddPlusCounter(this, 2);
		}
		else if (it->dwContext == 3)
			GainLife(this, pSelectionPlayer, 4);
		else
		{
			CardTypeComparer comparer(CardType::Artifact | CardType::_Enchantment, false);
			std::vector<SelectionEntry> entries;
			for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
			{
				CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
				for (int i = 0; i < pBattlefield->GetSize(); ++i)
				{
					CCard* pCard = pBattlefield->GetAt(i);
					if (!comparer(pCard))
						continue;

					SelectionEntry entry;
					entry.dwContext = (DWORD)pCard;
					entry.cpAssociatedCard = pCard;
					entry.strText.Format(_T("Destroy %s"), pCard->GetCardName(TRUE));
					entries.push_back(entry);
				}
			}
			if (!entries.empty())
				m_PermanentSelection.AddSelectionRequest(entries, 1, 1, this, pSelectionPlayer);
		}
	}
}

void CKnightOfAutumnCard::OnPermanentSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pSelectionPlayer).ApplyTo(pCard);
	}
}

CLazavTheMultifariousCard::CLazavTheMultifariousCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lazav, the Multifarious"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Shapeshifter), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(3))
{
	// When Lazav enters, surveil 1.
	AddEnterTrigger(this, &CLazavTheMultifariousCard::BeforeSurveil);

	// Not implemented: "{X}: Lazav becomes a copy of target creature card in your graveyard with mana value X..." (the
	// engine can't make a permanent become a copy of a card)
}

bool CLazavTheMultifariousCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CLeagueGuildmageCard::CLeagueGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("League Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// {3}{U}, {T}: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T("3") BLUE_MANA_TEXT, 1));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());

	// Not implemented: "{X}{R}, {T}: Copy target instant or sorcery spell you control with mana value X." (the mana value
	// would have to match the X paid when the target is chosen)
}

CLedevChampionCard::CLedevChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ledev Champion"), CardType::Creature, CREATURE_TYPE2(Elf, Knight), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CLedevChampionCard::OnCreaturesSelected))
{
	// Whenever this creature attacks, you may tap any number of untapped creatures you control. This creature gets +1/+1
	// until end of turn for each creature tapped this way.
	AddSelfAttackTrigger(this, &CLedevChampionCard::BeforeTap);

	// {3}{G}{W}: Create a 1/1 white Soldier creature token with lifelink.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this, _T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT,
			_T("Soldier (T)"), 55118, 1));
	AddAbility(cpAbility.GetPointer());
}

bool CLedevChampionCard::BeforeTap(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard->GetOrientation()->IsTapped())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Tap %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this, pAction->GetController());
	return true;
}

void CLedevChampionCard::OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount,
	CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	int nTapped = 0;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() == ZoneId::Battlefield && !pCard->GetOrientation()->IsTapped())
		{
			CCardOrientationModifier(TRUE).ApplyTo(pCard);
			++nTapped;
		}
	}

	if (nTapped > 0 && GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, nTapped, nTapped);
}

CLegionGuildmageCard::CLegionGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Legion Guildmage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// {5}{R}, {T}: This creature deals 3 damage to each opponent.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("5") RED_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("3 damage to each opponent. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLegionGuildmageCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}
	// {2}{W}, {T}: Tap another target creature.
	{
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this, _T("2") WHITE_MANA_TEXT, new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLegionGuildmageCard::BeforeTap));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLegionGuildmageCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 3);
	return true;
}

bool CLegionGuildmageCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		CCardOrientationModifier(TRUE).ApplyTo(pCard);
	return false;
}

CMolderhulkCard::CMolderhulkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Molderhulk"), CardType::Creature, CREATURE_TYPE2(Fungus, Zombie), nID,
		_T("7") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Undergrowth - This spell costs {1} less to cast for each creature card in your graveyard.
	// (one more spell for each reduction, from 1 to 7, as Ghalta, Primal Hunger in Rivals of Ixalan)
	static LPCTSTR costs[] = { _T("6"), _T("5"), _T("4"), _T("3"), _T("2"), _T("1"), _T("") };
	typedef BOOL (CMolderhulkCard::*Condition)(BOOL);
	Condition conditions[] = {
		&CMolderhulkCard::CanReduce1, &CMolderhulkCard::CanReduce2, &CMolderhulkCard::CanReduce3,
		&CMolderhulkCard::CanReduce4, &CMolderhulkCard::CanReduce5, &CMolderhulkCard::CanReduce6,
		&CMolderhulkCard::CanReduce7 };

	for (int i = 0; i < 7; ++i)
	{
		CString strCost = CString(costs[i]) + BLACK_MANA_TEXT + GREEN_MANA_TEXT;
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Creature, strCost));

		cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
		AddPlayableIf(this, cpSpell.GetPointer(), conditions[i]);
		AddSpell(cpSpell.GetPointer());
	}

	// When this creature enters, return target land card from your graveyard to the battlefield.
	// (partial: the land is chosen on resolution, it isn't targeted)
	AddEnterTrigger(this, &CMolderhulkCard::BeforeReturn);
}

BOOL CMolderhulkCard::CanReduceBy(int nReduction) const
{
	int nCount = CountCreatureCardsInGraveyard(GetController());
	return nReduction == 7 ? nCount >= 7 : nCount == nReduction;
}

bool CMolderhulkCard::BeforeReturn(CAbilityAction* pAction)
{
	ChooseAndMove(GetGame(), pAction->GetController(), ZoneId::Graveyard, 1, 1, CCardFilter::GetFilter(_T("lands")),
		ZoneId::Battlefield, MoveType::Others);
	return true;
}

CNightveilPredatorCard::CNightveilPredatorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Nightveil Predator"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Flying, deathtouch, hexproof
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddHexproof(FALSE);
}

CNivMizzetParunCard::CNivMizzetParunCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Niv-Mizzet, Parun"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Dragon, Wizard), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(5))
{
	// This spell can't be countered. Flying
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Whenever you draw a card, Niv-Mizzet deals 1 damage to any target. (it can't target planeswalkers)
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDrew > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNivMizzetParunCard::BeforeDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// Whenever a player casts an instant or sorcery spell, you draw a card.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("instant cards or sorcery cards")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNivMizzetParunCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNivMizzetParunCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToTarget(this, pAction, 1);
	return false;
}

bool CNivMizzetParunCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

COchranAssassinCard::COchranAssassinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ochran Assassin"), CardType::Creature, CREATURE_TYPE2(Elf, Assassin), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Deathtouch. All creatures able to block this creature do so. (Lure)
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCreatureKeyword()->AddLure(FALSE);
}

CPistonFistCyclopsCard::CPistonFistCyclopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Piston-Fist Cyclops"), CardType::Creature, CREATURE_TYPE(Cyclops), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(3))
{
	// {1}{U/R}{U/R}
	AddHybridPermanentSpells(this, _T("1"), 2, BLUE_MANA_TEXT, RED_MANA_TEXT);

	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// As long as you've cast an instant or sorcery spell this turn, this creature can attack as though it didn't have
	// defender. (partial: when you cast one, it loses defender until end of turn; spells cast before it entered don't count)
	AddInstantSorceryCastTrigger(this, &CPistonFistCyclopsCard::BeforeAttackable);
}

bool CPistonFistCyclopsCard::BeforeAttackable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToRemove(CreatureKeyword::Defender);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CPitilessGorgonCard::CPitilessGorgonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pitiless Gorgon"), CardType::Creature, CREATURE_TYPE(Gorgon), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// {1}{B/G}{B/G}
	AddHybridPermanentSpells(this, _T("1"), 2, BLACK_MANA_TEXT, GREEN_MANA_TEXT);

	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);
}

CRalsStaticasterCard::CRalsStaticasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ral's Staticaster"), CardType::Creature, CREATURE_TYPE2(Lizard, Wizard), nID,
		_T("2") BLUE_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever this creature attacks, if you control a Ral planeswalker, this creature gets +1/+0 for each card in your
	// hand until end of turn. (the condition is checked on resolution)
	AddSelfAttackTrigger(this, &CRalsStaticasterCard::BeforePump);
}

bool CRalsStaticasterCard::BeforePump(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (GetZoneId() == ZoneId::Battlefield && ControlsPlaneswalker(pController, PlaneswalkerType::Ral))
	{
		int nCards = pController->GetZoneById(ZoneId::Hand)->GetSize();
		if (nCards > 0)
			PumpCreature(this, nCards, 0);
	}
	return true;
}

CRampagingMonumentCard::CRampagingMonumentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rampaging Monument"), CardType::_ArtifactCreature, CREATURE_TYPE(Cleric), nID,
		_T("4"), Power(0), Life(0))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// This creature enters with three +1/+1 counters on it. (as the charge counters of M19)
	GetCounterContainer()->ScheduleCounter(_T("+1/+1"), 3, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	// Whenever you cast a multicolored spell, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardMulticoloredComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRampagingMonumentCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CRampagingMonumentCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		AddPlusCounter(this);
	return true;
}

CRhizomeLurcherCard::CRhizomeLurcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rhizome Lurcher"), CardType::Creature, CREATURE_TYPE2(Fungus, Zombie), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CRhizomeLurcherCard::OnZoneChanged))
{
	// Undergrowth - This creature enters with a number of +1/+1 counters on it equal to the number of creature cards in
	// your graveyard. (as Golgari Raiders)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CRhizomeLurcherCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard != this || !pFromZone || !pToZone)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		int nCount = CountCreatureCardsInGraveyard(GetController());
		if (nCount > 0)
			CCardCounterModifier(_T("+1/+1"), nCount).ApplyTo(this);
	}
}

CRosemaneCentaurCard::CRosemaneCentaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rosemane Centaur"), CardType::Creature, CREATURE_TYPE2(Centaur, Soldier), nID,
		_T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Convoke (partial: the creatures pay only generic mana). Vigilance
	AddPermanentConvoke(this, 3, GREEN_MANA_TEXT WHITE_MANA_TEXT);
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CSumalaWoodshaperCard::CSumalaWoodshaperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sumala Woodshaper"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Filter(_T("a creature or enchantment card"), _T("creature or enchantment cards"),
		new CardTypeComparer(CardType::Creature | CardType::_Enchantment, false))
{
	// When this creature enters, look at the top four cards of your library. You may reveal a creature or enchantment
	// card from among them and put it into your hand. Put the rest on the bottom of your library in a random order.
	// (the rest go to the bottom in any order)
	AddEnterTrigger(this, &CSumalaWoodshaperCard::BeforeLook);
}

bool CSumalaWoodshaperCard::BeforeLook(CAbilityAction* pAction)
{
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 4,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer, CZoneModifier::RoleType::AllPlayers, &m_Filter,
		ZoneId::Hand, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top, MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSwarmGuildmageCard::CSwarmGuildmageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swarm Guildmage"), CardType::Creature, CREATURE_TYPE2(Elf, Shaman), nID,
		BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {4}{B}, {T}: Creatures you control get +1/+0 and gain menace until end of turn.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("4") BLACK_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Creatures you control get +1/+0 and menace. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSwarmGuildmageCard::BeforePump));
		AddAbility(cpAbility.GetPointer());
	}
	// {1}{G}, {T}: You gain 2 life.
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("1") GREEN_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("You gain 2 life. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSwarmGuildmageCard::BeforeGainLife));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSwarmGuildmageCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreatures(GetGame(), pAction->GetController(), +1, 0, CreatureKeyword::CantBeBlockedBy1);
	return true;
}

bool CSwarmGuildmageCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CSwathcutterGiantCard::CSwathcutterGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swathcutter Giant"), CardType::Creature, CREATURE_TYPE2(Giant, Soldier), nID,
		_T("4") RED_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	// Vigilance. Whenever this creature attacks, it deals 1 damage to each creature defending player controls.
	GetCreatureKeyword()->AddVigilance(FALSE);
	AddSelfAttackTrigger(this, &CSwathcutterGiantCard::BeforeDamage);
}

bool CSwathcutterGiantCard::BeforeDamage(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pAction->GetController())
			continue;

		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pPlayer, TRUE, creatures);
		for (int i = 0; i < creatures.GetSize(); ++i)
			DealDamageToCreature(this, creatures.GetAt(i), 1);
	}
	return true;
}

CSwiftbladeVindicatorCard::CSwiftbladeVindicatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swiftblade Vindicator"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Double strike, vigilance, trample
	GetCreatureKeyword()->AddDoubleStrike(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
}

CTajicLegionsEdgeCard::CTajicLegionsEdgeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tajic, Legion's Edge"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
	, m_Mentor(this)
{
	// Haste. Mentor
	GetCreatureKeyword()->AddHaste(FALSE);
	m_Mentor.AddMentorAbility();

	// Not implemented: "Prevent all noncombat damage that would be dealt to other creatures you control."

	// {R}{W}: Tajic gains first strike until end of turn.
	AddPumpAbility(this, RED_MANA_TEXT WHITE_MANA_TEXT, _T("First strike until end of turn. Activates"), &CTajicLegionsEdgeCard::BeforeFirstStrike);
}

bool CTajicLegionsEdgeCard::BeforeFirstStrike(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		PumpCreature(this, 0, 0, CreatureKeyword::FirstStrike);
	return true;
}

CTrostaniDiscordantCard::CTrostaniDiscordantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trostani Discordant"), CardType::Creature | CardType::Legendary, CREATURE_TYPE(Dryad), nID,
		_T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(1), Life(4))
{
	// Other creatures you control get +1/+1. (as Goblin Rabblemaster)
	counted_ptr<CPwrTghAttrEnchantment> cpLord(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+1), Life(+1)));

	cpLord->GetEnchantmentCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpLord->SetAffectControllerCardsOnly();
	AddAbility(cpLord.GetPointer());

	// When Trostani enters, create two 1/1 white Soldier creature tokens with lifelink.
	AddEnterTrigger(this, &CTrostaniDiscordantCard::BeforeTokens);

	// Not implemented: "At the beginning of your end step, each player gains control of all creatures they own."
}

bool CTrostaniDiscordantCard::BeforeTokens(CAbilityAction* pAction)
{
	CTokenCreationModifier(GetGame(), _T("Soldier (T)"), 55118, 2).ApplyTo(pAction->GetController());
	return true;
}

CTruefireCaptainCard::CTruefireCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Truefire Captain"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		RED_MANA_TEXT RED_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
	, m_Mentor(this)
	, m_nLastDamage(0)
{
	// Mentor
	m_Mentor.AddMentorAbility();

	// Whenever this creature is dealt damage, it deals that much damage to target player. (an Enrage trigger with a
	// player target; the amount is remembered when it triggers)
	CTargeting* pTargeting = AddEnrageTargetTrigger(this, &CTruefireCaptainCard::SetDamageContext,
		&CTruefireCaptainCard::BeforeDamage, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().RemoveAllComparers();
	pTargeting->GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	pTargeting->SetIncludePlayers(TRUE);
}

bool CTruefireCaptainCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	if (pToCreature != this)
		return false;

	m_nLastDamage = -(int)damage.m_nLifeDelta;
	return m_nLastDamage > 0;
}

bool CTruefireCaptainCard::BeforeDamage(CAbilityAction* pAction)
{
	DealDamageToPlayer(this, pAction->GetAssociatedPlayer(), m_nLastDamage);
	return false;
}

CUnderrealmLichCard::CUnderrealmLichCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Underrealm Lich"), CardType::Creature, CREATURE_TYPE3(Zombie, Elf, Shaman), nID,
		_T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(3))
{
	// Not implemented: "If you would draw a card, instead look at the top three cards of your library, then put one into
	// your hand and the rest into your graveyard." (the engine has no replacement effects on drawing)

	// Pay 4 life: This creature gains indestructible until end of turn. Tap it.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->AddPayLifeDeltaCost(Life(-4));
	cpAbility->SetAbilityText(_T("Indestructible until end of turn, tap it. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUnderrealmLichCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CUnderrealmLichCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		GainCardKeyword(this, CardKeyword::Indestructible);
		CCardOrientationModifier(TRUE).ApplyTo(this);
	}
	return true;
}

CVernadiShieldmateCard::CVernadiShieldmateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vernadi Shieldmate"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {1}{G/W}
	AddHybridPermanentSpells(this, _T("1"), 1, GREEN_MANA_TEXT, WHITE_MANA_TEXT);

	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CWhisperAgentCard::CWhisperAgentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Whisper Agent"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// {1}{U/B}{U/B}
	AddHybridPermanentSpells(this, _T("1"), 2, BLUE_MANA_TEXT, BLACK_MANA_TEXT);

	// Flash. When this creature enters, surveil 1.
	GetCardKeyword()->AddFlash(FALSE);
	AddEnterTrigger(this, &CWhisperAgentCard::BeforeSurveil);
}

bool CWhisperAgentCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CWorldsoulColossusCard::CWorldsoulColossusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Worldsoul Colossus"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CWorldsoulColossusCard::OnZoneChanged))
	, m_nX(0)
{
	// {X}{G}{W}. Convoke. This creature enters with X +1/+1 counters on it.
	// (the main spell can't be cast; creature spells with {X} as Ghalta, Primal Hunger: the resolution remembers X, adding
	// the creatures tapped by the partial Convoke, and the creature gets the counters when it enters)
	AddPlayableIf(this, GetSpells().GetAt(0), &CWorldsoulColossusCard::Never);

	for (int nTapped = 0; nTapped <= 6; ++nTapped)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Creature, GREEN_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
		cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
		SetConvoke(cpSpell.GetPointer(), nTapped);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this,
			nTapped == 0 ? &CWorldsoulColossusCard::BeforeResolution : &CWorldsoulColossusCard::BeforeConvokedResolution));
		AddSpell(cpSpell.GetPointer());
	}

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

bool CWorldsoulColossusCard::BeforeResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	return true;
}

bool CWorldsoulColossusCard::BeforeConvokedResolution(CAbilityAction* pAction)
{
	m_nX = GetX(pAction);
	const CCountedCardContainer* pTapped = pAction->GetCostConfigEntry().GetTapCards();
	if (pTapped)
		m_nX += pTapped->GetSize();
	return true;
}

void CWorldsoulColossusCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
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
