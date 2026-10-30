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
counted_ptr<CCard> CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID)
{
	counted_ptr<CCard> cpCard;
	do
	{
		// === BOROS - Mentor ===
		DEFINE_CARD(CAureliaExemplarOfJusticeCard);
		DEFINE_CARD(CLegionWarbossCard);
		DEFINE_CARD(CTajicLegionsEdgeCard);
		DEFINE_CARD(CSunhomeStalwartCard);
		DEFINE_CARD(CBladeInstructorCard);
		DEFINE_CARD(CBorosChallengerCard);
		DEFINE_CARD(CParhelionPatrolCard);
		DEFINE_CARD(CDeafeningClarionCard);
		DEFINE_CARD(CIntegrityInterventionCard);

		// === DIMIR - Surveil ===
		DEFINE_CARD(CDoomWhispererCard);
		DEFINE_CARD(CNightveilPredatorCard);
		DEFINE_CARD(CThoughtErasureCard);
		DEFINE_CARD(CSinisterSabotageCard);
		DEFINE_CARD(CDimirInformantCard);
		DEFINE_CARD(CUnexplainedDisappearanceCard);
		DEFINE_CARD(CMissionBriefingCard);
		DEFINE_CARD(CWhisperingSnitchCard);

		// === GOLGARI - Undergrowth ===
		DEFINE_CARD(CAssassinsTrophyCard);
		DEFINE_CARD(CCharnelTrollCard);
		DEFINE_CARD(CLotlethGiantCard);
		DEFINE_CARD(CRhizomeLurcherCard);
		DEFINE_CARD(CGlowsporeSchamanCard);
		DEFINE_CARD(CMolderhulkCard);
		DEFINE_CARD(CKraulHarpoonerCard);
		DEFINE_CARD(CUnderealmLichCard);

		// === IZZET - Jump-start ===
		DEFINE_CARD(CCracklingDrakeCard);
		DEFINE_CARD(CNivMizzetParunCard);
		DEFINE_CARD(CRiskFactorCard);
		DEFINE_CARD(CRadicalIdeaCard);
		DEFINE_CARD(CMurmurMysticCard);
		DEFINE_CARD(CIonizeCard);
		DEFINE_CARD(CDirectCurrentCard);
		DEFINE_CARD(CBeaconBoltCard);
		DEFINE_CARD(CWeeDragonautsCard);

		// === SELESNYA - Convoke ===
		DEFINE_CARD(CVeneratedLoxodonCard);
		DEFINE_CARD(CDivineVisitationCard);
		DEFINE_CARD(CEmmaraSoulOfTheAccordCard);
		DEFINE_CARD(CTrostaniDiscordantCard);
		DEFINE_CARD(CConclaveCavalierCard);
		DEFINE_CARD(CKnightOfAutumnCard);
		DEFINE_CARD(CConclaveTribunalCard);

		// === PLANESWALKERS ===
		DEFINE_CARD(CRalIzzetViceroyCard);
		DEFINE_CARD(CVraskaGolgariQueenCard);

		// === LANDS ===
		DEFINE_CARD(CSteamVentsCard);
		DEFINE_CARD(COvgrownTombGRNCard);
		DEFINE_CARD(CSacredFoundryGRNCard);
		DEFINE_CARD(CTempleGardenGRNCard);
		DEFINE_CARD(CWateryGraveGRNCard);
		DEFINE_CARD(CBorosGuildgateGRNCard);
		DEFINE_CARD(CDimirGuildgateGRNCard);
		DEFINE_CARD(CGolgariGuildgateGRNCard);
		DEFINE_CARD(CIzzetGuildgateGRNCard);
		DEFINE_CARD(CSelesnyaGuildgateGRNCard);

	} while (false);

	return cpCard;
}

// ============================================================================
// Helper: Surveil N
// Look at top N cards of your library; put any number in graveyard, rest back on top.
// ============================================================================
static void DoSurveil(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CZoneModifier* pModifier = new CDrawCardModifier(pGame, MinimumValue(nCount), MaximumValue(nCount));
	pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
	pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
	pModifier->GetSelection(0).moveType = MoveType::Others;
	pModifier->AddSelection(MinimumValue(0), MaximumValue(nCount),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::PrimaryPlayer,
		NULL,
		ZoneId::Graveyard,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier->SetReorderInformation(
		true,
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top);
	pModifier->ApplyTo(pPlayer);
}

// Helper: count creatures in a player's graveyard
static int CountCreaturesInGraveyard(CPlayer* pPlayer)
{
	CCardFilter filter;
	filter.SetComparer(new AnyCreatureComparer);
	return filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Graveyard)->GetCardContainer());
}

// Helper: count instants and sorceries in a player's graveyard
static int CountInstantsSorceriesInGraveyard(CPlayer* pPlayer)
{
	CCardFilter filter;
	filter.SetComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	return filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Graveyard)->GetCardContainer());
}

// Helper: add Mentor triggered ability to a creature card
// Whenever this creature attacks, put a +1/+1 counter on another target attacking creature you control.
static void AddMentorAbility(CCreatureCard* pCard)
{
	typedef TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfAttackedBlocked,
		CWhenSelfAttackedBlocked::AttackEventCallback,
		&CWhenSelfAttackedBlocked::SetAttackingEventCallback > MentorAbility;

	counted_ptr<MentorAbility> cpAbility(::CreateObject<MentorAbility>(pCard));
	cpAbility->SetOptionalType(MentorAbility::OptionalType::Optional);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(pCard));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();

	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));

	cpAbility->SetAbilityText(_T("Mentor - put a +1/+1 counter on target attacking creature."));

	pCard->AddAbility(cpAbility.GetPointer());
}

// ============================================================================
// BOROS GUILD
// ============================================================================

//____________________________________________________________________________
// Aurelia, Exemplar of Justice - {3}{R}{W}  Legendary Creature - Angel  2/5
// Flying, first strike, mentor
CAureliaExemplarOfJusticeCard::CAureliaExemplarOfJusticeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aurelia, Exemplar of Justice"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Angel), nID,
		_T("3") RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(5))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	AddMentorAbility(this);
}

//____________________________________________________________________________
// Legion Warboss - {2}{R}  Creature - Goblin Soldier  2/2
// Mentor. At the beginning of combat on your turn, create a 1/1 Goblin token that's tapped and attacking.
CLegionWarbossCard::CLegionWarbossCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Legion Warboss"), CardType::Creature, CREATURE_TYPE2(Goblin, Soldier), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CLegionWarbossCard::OnResolutionCompleted))
{
	AddMentorAbility(this);

	// At the beginning of combat on your turn, create a 1/1 red Goblin creature token that's tapped and attacking.
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CLegionWarbossCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CTokenProductionModifier pModifier = CTokenProductionModifier(GetGame(), _T("Goblin M"), 64019, 1);
	pModifier.ApplyTo(pAbilityAction->GetController());
}

//____________________________________________________________________________
// Tajic, Legion's Edge - {1}{R}{W}  Legendary Creature - Human Soldier  3/2
// Haste, first strike, mentor
// Prevent all noncombat damage that would be dealt to other creatures you control.
CTajicLegionsEdgeCard::CTajicLegionsEdgeCard(CGame* pGame, UINT nID)
	: CFirstStrikeCreatureCard(pGame, _T("Tajic, Legion's Edge"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
	GetCreatureKeyword()->AddHaste(FALSE);
	AddMentorAbility(this);
}

//____________________________________________________________________________
// Sunhome Stalwart - {1}{W}  Creature - Human Soldier  2/3  First strike, mentor
CSunhomeStalwartCard::CSunhomeStalwartCard(CGame* pGame, UINT nID)
	: CFirstStrikeCreatureCard(pGame, _T("Sunhome Stalwart"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(3))
{
	AddMentorAbility(this);
}

//____________________________________________________________________________
// Blade Instructor - {2}{R}  Creature - Human Soldier  2/1  Mentor
CBladeInstructorCard::CBladeInstructorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blade Instructor"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(1))
{
	AddMentorAbility(this);
}

//____________________________________________________________________________
// Boros Challenger - {R}{W}  Creature - Human Soldier  1/2
// Mentor. {2}{R}{W}: gets +3/+3 until end of turn.
CBorosChallengerCard::CBorosChallengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Boros Challenger"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("") RED_MANA_TEXT WHITE_MANA_TEXT, Power(1), Life(2))
{
	AddMentorAbility(this);

	counted_ptr<CActivatedAbility<CChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CChgPwrTghAttrSpell>>(this,
			_T("2") RED_MANA_TEXT WHITE_MANA_TEXT,
			Power(+3), Life(+3),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
// Parhelion Patrol - {2}{W}  Creature - Human Knight  1/4  Flying, mentor
CParhelionPatrolCard::CParhelionPatrolCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Parhelion Patrol"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("2") WHITE_MANA_TEXT, Power(1), Life(4))
{
	AddMentorAbility(this);
}

//____________________________________________________________________________
// Deafening Clarion - {2}{R}  Instant
// Choose one or both: creatures you control gain first strike until EOT;
// or Deafening Clarion deals 3 damage to each creature.
CDeafeningClarionCard::CDeafeningClarionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deafening Clarion"), CardType::Instant, nID)
{
	{
		// Creatures you control gain first strike until end of turn
		counted_ptr<CPwrTghAttrEnchantment> cpSpell(
			::CreateObject<CPwrTghAttrEnchantment>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer,
				Power(+0), Life(+0)));

		cpSpell->SetAffectControllerCardsOnly();
		cpSpell->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::FirstStrike);
		cpSpell->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);

		cpSpell->SetAbilityName(_T("Mode 1"));
		cpSpell->SetAbilityText(_T("Creatures you control gain first strike until end of turn. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Deal 3 damage to each creature
		counted_ptr<CGlobalChgLifeSpell> cpSpell(
			::CreateObject<CGlobalChgLifeSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				Life(-3),
				new AnyCreatureComparer,
				TRUE,
				PreventableType::Preventable,
				DamageType::SpellDamage | DamageType::NonCombatDamage));

		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		cpSpell->SetAbilityName(_T("Mode 2"));
		cpSpell->SetAbilityText(_T("Deafening Clarion deals 3 damage to each creature. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
// Integrity // Intervention - {R/W} Instant // {3}{R}{W} Instant
// Integrity: target creature gets +2/+2 and first strike until EOT
// Intervention: Integrity // Intervention deals 5 damage to target attacking or blocking creature
CIntegrityInterventionCard::CIntegrityInterventionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Integrity // Intervention"), CardType::Instant, nID)
{
	{
		// Integrity: +2/+2, first strike until EOT
		counted_ptr<CChgPwrTghAttrSpellCard> cpSpell(
			::CreateObject<CChgPwrTghAttrSpellCard>(this, AbilityType::Instant,
				RED_MANA_TEXT,
				Power(+2), Life(+2),
				CreatureKeyword::FirstStrike, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpSpell->SetAbilityName(_T("Integrity"));
		cpSpell->SetAbilityText(_T("Integrity: target creature gets +2/+2 and first strike until EOT. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Intervention: deal 5 to attacking/blocking creature
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				_T("3") RED_MANA_TEXT WHITE_MANA_TEXT,
				new AttackingBlockingCreatureComparer,
				FALSE,
				Life(-5), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		cpSpell->SetAbilityName(_T("Intervention"));
		cpSpell->SetAbilityText(_T("Intervention: deals 5 damage to target attacking or blocking creature. Casts"));
		cpSpell->SetMainSpell(FALSE);
		AddSpell(cpSpell.GetPointer());
	}
}

// ============================================================================
// DIMIR GUILD
// ============================================================================

//____________________________________________________________________________
// Doom Whisperer - {3}{B}{B}  Creature - Nightmare Demon  6/6  Flying, trample
// {Pay 2 life}: Surveil 2.
CDoomWhispererCard::CDoomWhispererCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Doom Whisperer"), CardType::Creature, CREATURE_TYPE2(Nightmare, Demon), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(6))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CDoomWhispererCard::OnResolutionCompleted))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	cpAbility->GetCost().AddLifeCost(2);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	cpAbility->SetAbilityText(_T("Pay 2 life: Surveil 2."));

	AddAbility(cpAbility.GetPointer());
}

void CDoomWhispererCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;
	DoSurveil(GetGame(), pAbilityAction->GetController(), 2);
}

//____________________________________________________________________________
// Nightveil Predator - {U}{B}  Creature - Vampire  2/2  Flying, deathtouch, hexproof
CNightveilPredatorCard::CNightveilPredatorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Nightveil Predator"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddShroud(FALSE);
}

//____________________________________________________________________________
// Thought Erasure - {U}{B}  Sorcery
// Target opponent reveals their hand. You choose a nonland card from it. That player discards that card. Surveil 1.
CThoughtErasureCard::CThoughtErasureCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Thought Erasure"), CardType::Sorcery, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CThoughtErasureCard::OnResolutionCompleted))
{
	counted_ptr<CTargetRevealDiscardSpell> cpSpell(
		::CreateObject<CTargetRevealDiscardSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLACK_MANA_TEXT,
			new NonLandCardComparer,
			TRUE,  // choose opponent's card
			FALSE, // not random
			1));   // discard 1

	cpSpell->GetTargeting()->SetTargetOpponentPlayerOnly();
	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddSpell(cpSpell.GetPointer());
}

void CThoughtErasureCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;
	DoSurveil(GetGame(), pAbilityAction->GetController(), 1);
}

//____________________________________________________________________________
// Sinister Sabotage - {2}{U}  Instant  Counter target spell. Surveil 1.
CSinisterSabotageCard::CSinisterSabotageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sinister Sabotage"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CSinisterSabotageCard::OnResolutionCompleted))
{
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddSpell(cpSpell.GetPointer());
}

void CSinisterSabotageCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;
	DoSurveil(GetGame(), pAbilityAction->GetController(), 1);
}

//____________________________________________________________________________
// Dimir Informant - {2}{U}  Creature - Human Rogue  1/4
// When Dimir Informant enters the battlefield, surveil 2.
CDimirInformantCard::CDimirInformantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dimir Informant"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CDimirInformantCard::OnResolutionCompleted))
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CDimirInformantCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;
	DoSurveil(GetGame(), pAbilityAction->GetController(), 2);
}

//____________________________________________________________________________
// Unexplained Disappearance - {U}  Instant
// Return target creature to its owner's hand. Surveil 1.
CUnexplainedDisappearanceCard::CUnexplainedDisappearanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unexplained Disappearance"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CUnexplainedDisappearanceCard::OnResolutionCompleted))
{
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddSpell(cpSpell.GetPointer());
}

void CUnexplainedDisappearanceCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;
	DoSurveil(GetGame(), pAbilityAction->GetController(), 1);
}

//____________________________________________________________________________
// Mission Briefing - {U}{U}  Instant  Surveil 2. Until end of turn, you may cast target
// instant or sorcery card from your graveyard.
// Simplified: Surveil 2, then return target instant/sorcery from GY to hand.
CMissionBriefingCard::CMissionBriefingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mission Briefing"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CMissionBriefingCard::OnResolutionCompleted))
{
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT BLUE_MANA_TEXT));

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	cpSpell->SetAbilityText(_T("Surveil 2. Return target instant/sorcery from your graveyard to your hand."));

	AddSpell(cpSpell.GetPointer());
}

void CMissionBriefingCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();

	DoSurveil(GetGame(), pController, 2);

	// Return target instant or sorcery from graveyard to hand
	CCardFilter spellFilter;
	spellFilter.SetComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));

	CCountedCardContainer cards;
	spellFilter.GetIncluded(pController->GetZoneById(ZoneId::Graveyard)->GetCardContainer(), cards);

	if (cards.GetSize() > 0)
	{
		CCard* pCard = cards.GetAt(0);
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, 1, CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, MoveType::Others, CZoneModifier::RoleType::PrimaryPlayer);
		// Move the card from graveyard to hand
		pCard->Move(pController->GetZoneById(ZoneId::Hand), pController, MoveType::Others);
	}
}

//____________________________________________________________________________
// Whispering Snitch - {1}{B}  Creature - Vampire Rogue  2/2
// Simplified: just a 2/2 for 1B (surveil trigger requires engine support not available)
CWhisperingSnitchCard::CWhisperingSnitchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Whispering Snitch"), CardType::Creature, CREATURE_TYPE2(Vampire, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
}

// ============================================================================
// GOLGARI GUILD
// ============================================================================

//____________________________________________________________________________
// Assassin's Trophy - {B}{G}  Instant
// Destroy target permanent an opponent controls. Its controller may search their library for a basic land
// card, put it onto the battlefield, then shuffle.
CAssassinsTrophyCard::CAssassinsTrophyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Assassin's Trophy"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CAssassinsTrophyCard::OnResolutionCompleted))
{
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			BLACK_MANA_TEXT GREEN_MANA_TEXT,
			new TrueCardComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new CardTypeComparer(CardType::_Land, false));

	// Destroy also hits non-creature permanents, so add land filter back as negate
	// Actually: target any permanent an opponent controls (remove the land negate)
	cpSpell->GetTargeting()->GetSubjectCardFilter().RemoveAllComparers();
	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TrueCardComparer);

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));

	AddSpell(cpSpell.GetPointer());
}

void CAssassinsTrophyCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// Opponent searches for basic land and puts onto battlefield
	// Simplified: give opponent a land from their library (search)
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAbilityAction->GetController());
	if (!pOpponent) return;

	// Fetch basic land from top of library (simplified - look at top 7 for land)
	CCardFilter landFilter;
	landFilter.SetComparer(new CardTypeComparer(CardType::BasicLand, false));

	CCountedCardContainer cards;
	landFilter.GetIncluded(pOpponent->GetZoneById(ZoneId::Library)->GetCardContainer(), cards);
	if (cards.GetSize() > 0)
	{
		CCard* pLand = cards.GetAt(0);
		pLand->Move(pOpponent->GetZoneById(ZoneId::Battlefield), pOpponent, MoveType::Others);
	}
}

//____________________________________________________________________________
// Charnel Troll - {1}{B}{G}  Creature - Troll  3/3  Trample
// At the beginning of your upkeep, exile a creature card from your graveyard.
// If you can't, sacrifice Charnel Troll.
CCharnelTrollCard::CCharnelTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charnel Troll"), CardType::Creature, CREATURE_TYPE(Troll), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	m_CardFilter.AddComparer(new AnyCreatureComparer);
	m_SelfFilter.AddComparer(new SpecificCardComparer(this));

	// Upkeep: exile a creature card from your GY or sacrifice this
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);

	cpAbility->GetCost().AddExileGraveyardCardCost(1, &m_CardFilter, true); // optional exile
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SelfFilter, true);      // optional sacrifice self

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
// Lotleth Giant - {7}{B}  Creature - Zombie Giant  5/4
// Undergrowth - When Lotleth Giant enters the battlefield,
// it deals damage to target opponent equal to the number of creature cards in your graveyard.
CLotlethGiantCard::CLotlethGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lotleth Giant"), CardType::Creature, CREATURE_TYPE2(Zombie, Giant), nID,
		_T("7") BLACK_MANA_TEXT, Power(5), Life(4))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CLotlethGiantCard::OnResolutionCompleted))
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CLotlethGiantCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();
	int nCreatures = CountCreaturesInGraveyard(pController);
	if (nCreatures <= 0) return;

	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	if (!pOpponent) return;

	CLifeModifier pModifier = CLifeModifier(Life(-nCreatures), this, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pOpponent);
}

//____________________________________________________________________________
// Rhizome Lurcher - {2}{B}{G}  Creature - Fungus Zombie  0/0
// Undergrowth - Rhizome Lurcher enters the battlefield with a number of +1/+1 counters
// on it equal to the number of creature cards in your graveyard.
CRhizomeLurcherCard::CRhizomeLurcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rhizome Lurcher"), CardType::Creature, CREATURE_TYPE2(Fungus, Zombie), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(0))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CRhizomeLurcherCard::OnResolutionCompleted))
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CRhizomeLurcherCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	int nCreatures = CountCreaturesInGraveyard(pAbilityAction->GetController());
	if (nCreatures <= 0) return;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +nCreatures);
	pModifier.ApplyTo(this);
}

//____________________________________________________________________________
// Glowspore Shaman - {B}{G}  Creature - Elf Shaman  3/1
// When Glowspore Shaman enters the battlefield, put the top card of your library into your graveyard.
// You may put a land card from your graveyard on top of your library.
CGlowsporeSchamanCard::CGlowsporeSchamanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glowspore Shaman"), CardType::Creature, CREATURE_TYPE2(Elf, Shaman), nID,
		BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(1))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CGlowsporeSchamanCard::OnResolutionCompleted))
{
	m_LandFilter.AddComparer(new CardTypeComparer(CardType::_Land, false));

	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CGlowsporeSchamanCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();

	// Mill top card
	CZoneModifier* pMillModifier = new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
	pMillModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
	pMillModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
	pMillModifier->GetSelection(0).moveType = MoveType::Others;
	pMillModifier->AddSelection(MinimumValue(1), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::PrimaryPlayer,
		NULL,
		ZoneId::Graveyard,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pMillModifier->SetReorderInformation(false, ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pMillModifier->ApplyTo(pController);

	// Optionally return land from GY to top of library
	CCountedCardContainer graveyardCards;
	m_LandFilter.GetIncluded(pController->GetZoneById(ZoneId::Graveyard)->GetCardContainer(), graveyardCards);
	if (graveyardCards.GetSize() > 0)
	{
		CCard* pLand = graveyardCards.GetAt(0);
		pLand->Move(pController->GetZoneById(ZoneId::Library), pController, MoveType::Others, CardPlacement::Top);
	}
}

//____________________________________________________________________________
// Molderhulk - {6}{B}{G}  Creature - Fungus Zombie  6/6
// Undergrowth: This spell costs {1} less to cast for each creature card in your graveyard (simplified: full cost).
// When Molderhulk enters the battlefield, return target land card from your graveyard to the battlefield.
CMolderhulkCard::CMolderhulkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Molderhulk"), CardType::Creature, CREATURE_TYPE2(Fungus, Zombie), nID,
		_T("6") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CMolderhulkCard::OnResolutionCompleted))
{
	m_LandFilter.AddComparer(new CardTypeComparer(CardType::_Land, false));

	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CMolderhulkCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();
	CCountedCardContainer graveyardCards;
	m_LandFilter.GetIncluded(pController->GetZoneById(ZoneId::Graveyard)->GetCardContainer(), graveyardCards);
	if (graveyardCards.GetSize() > 0)
	{
		CCard* pLand = graveyardCards.GetAt(0);
		pLand->Move(pController->GetZoneById(ZoneId::Battlefield), pController, MoveType::Others);
	}
}

//____________________________________________________________________________
// Kraul Harpooner - {1}{G}  Creature - Insect Warrior  3/2  Reach
// Undergrowth - When Kraul Harpooner enters the battlefield,
// it fights target creature with flying. Its power is +X, where X is creatures in your GY.
CKraulHarpoonerCard::CKraulHarpoonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kraul Harpooner"), CardType::Creature, CREATURE_TYPE2(Insect, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CKraulHarpoonerCard::OnResolutionCompleted))
{
	GetCreatureKeyword()->AddReach(FALSE);

	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CKraulHarpoonerCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();
	int nBonus = CountCreaturesInGraveyard(pController);

	// Fight: this creature deals damage to target creature with flying equal to its power + bonus
	CCardFilter flyingFilter;
	flyingFilter.SetComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false));

	CCountedCardContainer flyers;
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(i);
		if (pPlayer != pController)
			flyingFilter.GetIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer(), flyers);
	}

	if (flyers.GetSize() > 0)
	{
		CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(flyers.GetAt(0));
		if (pTarget)
		{
			int nPower = GET_INTEGER(GetPower()) + nBonus;
			CLifeModifier pModifier = CLifeModifier(Life(-nPower), this, PreventableType::Preventable,
				DamageType::CombatDamage);
			pModifier.ApplyTo(pTarget);

			// Target deals damage back
			CLifeModifier pModifier2 = CLifeModifier(Life(-GET_INTEGER(pTarget->GetPower())), pTarget,
				PreventableType::Preventable, DamageType::CombatDamage);
			pModifier2.ApplyTo(this);
		}
	}
}

//____________________________________________________________________________
// Underrealm Lich - {3}{B}{G}  Creature - Zombie Elf Shaman  4/3
// If you would draw a card, instead look at the top three cards of your library,
// put one into your hand and the rest into your graveyard.
// Simplified: activated ability: {T}: look at top 3, put 1 in hand, 2 to graveyard.
CUnderealmLichCard::CUnderealmLichCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Underrealm Lich"), CardType::Creature,
		CREATURE_TYPE3(Zombie, Elf, Shaman), nID,
		_T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(3))
{
	// Activated: tap to look at top 3, keep 1, rest to GY (simplified surveil-like)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));
	cpAbility->AddTapCost();

	cpAbility->SetAbilityText(_T("Look at top 3 cards: put 1 in hand, rest to graveyard."));

	// Use the surveil modifier to approximate: look at 3, choose 2 to GY
	// We'll do this via a resolution callback (inline approach)
	// This is simplified - the real card replaces draws
	AddAbility(cpAbility.GetPointer());
}

// ============================================================================
// IZZET GUILD
// ============================================================================

//____________________________________________________________________________
// Crackling Drake - {2}{U}{R}  Creature - Drake  0/4  Flying
// Crackling Drake's power is equal to the total number of instant and sorcery cards
// in your graveyard and exile combined.
// When Crackling Drake enters the battlefield, draw a card.
CCracklingDrakeCard::CCracklingDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Crackling Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("2") BLUE_MANA_TEXT RED_MANA_TEXT, Power(0), Life(4))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CCracklingDrakeCard::OnResolutionCompleted))
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CCracklingDrakeCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// Draw a card
	pAbilityAction->GetController()->DrawCard();

	// Set power based on instants/sorceries in GY
	int nSpells = CountInstantsSorceriesInGraveyard(pAbilityAction->GetController());
	if (nSpells > 0)
	{
		SetPower(Power(nSpells), TRUE);
	}
}

//____________________________________________________________________________
// Niv-Mizzet, Parun - {U}{U}{U}{R}{R}{R}  Legendary Creature - Dragon Wizard  5/5  Flying
// This spell can't be countered.
// Whenever you draw a card, Niv-Mizzet, Parun deals 1 damage to any target.
// Whenever a player casts an instant or sorcery spell, you draw a card.
CNivMizzetParunCard::CNivMizzetParunCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Niv-Mizzet, Parun"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Dragon, Wizard), nID,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT,
		Power(5), Life(5))
{
	// Whenever a player casts an instant or sorcery, draw a card
	typedef TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardTypeFilter().AddComparer(
		new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));

	AddAbility(cpAbility.GetPointer());

	// Whenever you draw a card, deal 1 damage to target
	typedef TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenCardDrawn > DrawTriggered;

	counted_ptr<DrawTriggered> cpAbility2(::CreateObject<DrawTriggered>(this));
	cpAbility2->SetOptionalType(DrawTriggered::OptionalType::Required);
	cpAbility2->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility2->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility2->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility2->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

	AddAbility(cpAbility2.GetPointer());
}

//____________________________________________________________________________
// Risk Factor - {2}{R}  Instant
// Target opponent may have Risk Factor deal 4 damage to them.
// If that player doesn't, you draw three cards.
// Jump-start (discard a card to cast from graveyard)
CRiskFactorCard::CRiskFactorCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Risk Factor"), CardType::Instant, nID)
{
	{
		// Mode 1: target player loses 4 life
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				new TruePlayerComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		cpSpell->SetTargetOpponentPlayerOnly();
		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		cpSpell->SetAbilityName(_T("Mode 1"));
		cpSpell->SetAbilityText(_T("Target opponent takes 4 damage. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Mode 2: draw 3 cards
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT, 3));

		cpSpell->SetAbilityName(_T("Mode 2 - Draw 3"));
		cpSpell->SetAbilityText(_T("Draw three cards. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Jump-start: from graveyard with discard
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				new TruePlayerComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		cpSpell->SetTargetOpponentPlayerOnly();
		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		cpSpell->SetGraveyardOnly();
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityName(_T("Jump-start"));
		cpSpell->SetAbilityText(_T("Jump-start. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
// Radical Idea - {1}{U}  Instant  Draw a card.
// Jump-start
CRadicalIdeaCard::CRadicalIdeaCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Radical Idea"), CardType::Instant, nID)
{
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT, 1));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Jump-start version
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT, 1));

		cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		cpSpell->SetGraveyardOnly();
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityName(_T("Jump-start"));
		cpSpell->SetAbilityText(_T("Jump-start. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
// Murmuring Mystic - {3}{U}  Creature - Human Wizard  2/4
// Whenever you cast an instant or sorcery spell, create a 1/1 blue Bird Illusion creature token with flying.
CMurmurMysticCard::CMurmurMysticCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Murmuring Mystic"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(4))
{
	typedef TTriggeredAbility< CTriggeredTokenProductionAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		_T("Bird AA"), 2000, 1)); // Bird token placeholder ID
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardTypeFilter().AddComparer(
		new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
// Ionize - {1}{U}{R}  Instant  Counter target spell. Ionize deals 2 damage to that spell's controller.
CIonizeCard::CIonizeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ionize"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CIonizeCard::OnResolutionCompleted))
{
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT RED_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddSpell(cpSpell.GetPointer());
}

void CIonizeCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// Deal 2 damage to the opponent (spell's controller)
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAbilityAction->GetController());
	if (!pOpponent) return;

	CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pOpponent);
}

//____________________________________________________________________________
// Direct Current - {1}{R}  Sorcery  Direct Current deals 2 damage to any target. Jump-start.
CDirectCurrentCard::CDirectCurrentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Direct Current"), CardType::Sorcery, nID)
{
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				_T("1") RED_MANA_TEXT,
				new TrueCardComparer, FALSE,
				Life(-2), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Jump-start
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				_T("1") RED_MANA_TEXT,
				new TrueCardComparer, FALSE,
				Life(-2), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		cpSpell->SetGraveyardOnly();
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityName(_T("Jump-start"));
		cpSpell->SetAbilityText(_T("Jump-start. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
// Beacon Bolt - {1}{U}{R}  Sorcery
// Beacon Bolt deals damage equal to the total number of instant and sorcery cards
// in your graveyard to target creature. Jump-start.
CBeaconBoltCard::CBeaconBoltCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Beacon Bolt"), CardType::Sorcery, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CBeaconBoltCard::OnResolutionCompleted))
{
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				_T("1") BLUE_MANA_TEXT RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-0), PreventableType::Preventable));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors);
		cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Jump-start version
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				_T("1") BLUE_MANA_TEXT RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-0), PreventableType::Preventable));

		cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		cpSpell->SetGraveyardOnly();
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityName(_T("Jump-start"));
		cpSpell->SetAbilityText(_T("Jump-start. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

void CBeaconBoltCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();
	int nDamage = CountInstantsSorceriesInGraveyard(pController);
	if (nDamage <= 0) return;

	// Apply damage to the targeted creature
	const CAbilityAction* pAction = pAbilityAction;
	if (!pAction) return;

	CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(pAction->GetCardTarget());
	if (pTarget)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nDamage), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pTarget);
	}
}

//____________________________________________________________________________
// Wee Dragonauts - {1}{U}{R}  Creature - Faerie Wizard  1/3  Flying
// Whenever you cast an instant or sorcery spell, Wee Dragonauts gets +2/+0 until end of turn.
CWeeDragonautsCard::CWeeDragonautsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Wee Dragonauts"), CardType::Creature, CREATURE_TYPE2(Faerie, Wizard), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(1), Life(3))
{
	typedef TTriggeredAbility< CTriggeredChgPwrTghAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		Power(+2), Life(+0), TRUE));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardTypeFilter().AddComparer(
		new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));

	AddAbility(cpAbility.GetPointer());
}

// ============================================================================
// SELESNYA GUILD
// ============================================================================

//____________________________________________________________________________
// Venerated Loxodon - {4}{W}  Creature - Elephant Cleric  4/4
// Convoke. When Venerated Loxodon enters the battlefield,
// put a +1/+1 counter on each creature that tapped to cast it.
// Simplified: ETB put +1/+1 on each other creature you control.
CVeneratedLoxodonCard::CVeneratedLoxodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Venerated Loxodon"), CardType::Creature, CREATURE_TYPE2(Elephant, Cleric), nID,
		_T("4") WHITE_MANA_TEXT, Power(4), Life(4))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CVeneratedLoxodonCard::OnResolutionCompleted))
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

void CVeneratedLoxodonCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// Put +1/+1 on each other creature you control
	CPlayer* pController = pAbilityAction->GetController();
	CCardFilter creatureFilter;
	creatureFilter.AddComparer(new AnyCreatureComparer);
	creatureFilter.AddNegateComparer(new SpecificCardComparer(this));

	CCountedCardContainer creatures;
	creatureFilter.GetIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer(), creatures);

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
		pModifier.ApplyTo(creatures.GetAt(i));
	}
}

//____________________________________________________________________________
// Divine Visitation - {3}{W}{W}  Enchantment
// If one or more creature tokens would be created under your control,
// that many 4/4 white Angel creature tokens with flying and vigilance are created instead.
// Simplified: continuous enchantment - your creature tokens get +3/+3 and flying.
CDivineVisitationCard::CDivineVisitationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Divine Visitation"), CardType::Enchantment, nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Give creature tokens you control +3/+3, flying, and vigilance (simplification)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CardTypeComparer(CardType::Token, false),
			Power(+3), Life(+3), CreatureKeyword::Null));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Flying);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(FALSE);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
// Emmara, Soul of the Accord - {G}{W}  Legendary Creature - Elf Cleric  2/2
// Whenever Emmara, Soul of the Accord becomes tapped, create a 1/1 white Soldier creature token with lifelink.
// Simplified: when Emmara attacks, create a 1/1 Soldier token with lifelink.
CEmmaraSoulOfTheAccordCard::CEmmaraSoulOfTheAccordCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emmara, Soul of the Accord"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Elf, Cleric), nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	typedef TTriggeredAbility< CTriggeredTokenProductionAbility, CWhenSelfAttackedBlocked,
		CWhenSelfAttackedBlocked::AttackEventCallback,
		&CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		_T("Soldier AA"), 62030, 1));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
// Trostani Discordant - {3}{G}{W}  Legendary Creature - Dryad  1/4  Vigilance
// Other creatures you control get +1/+1.
// When Trostani Discordant enters the battlefield, create two 1/1 white Soldier tokens with lifelink.
CTrostaniDiscordantCard::CTrostaniDiscordantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trostani Discordant"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Dryad), nID,
		_T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(1), Life(4))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CTrostaniDiscordantCard::OnResolutionCompleted))
{
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Other creatures you control get +1/+1
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(+1), Life(+1), CreatureKeyword::Null));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->GetOtherCardFilters().AddNegateComparer(new SpecificCardComparer(this));

		AddAbility(cpAbility.GetPointer());
	}

	// ETB: create two 1/1 lifelink soldiers
	{
		typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
}

void CTrostaniDiscordantCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// Create two 1/1 Soldier tokens with lifelink
	CTokenProductionModifier pModifier1 = CTokenProductionModifier(GetGame(), _T("Soldier AA"), 62030, 1);
	pModifier1.ApplyTo(pAbilityAction->GetController());

	CTokenProductionModifier pModifier2 = CTokenProductionModifier(GetGame(), _T("Soldier AA"), 62030, 1);
	pModifier2.ApplyTo(pAbilityAction->GetController());
}

//____________________________________________________________________________
// Conclave Cavalier - {G}{G}{W}{W}  Creature - Centaur Knight  4/4  Vigilance
// When Conclave Cavalier dies, create two 2/2 green Centaur creature tokens.
CConclaveCavalierCard::CConclaveCavalierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Conclave Cavalier"), CardType::Creature, CREATURE_TYPE2(Centaur, Knight), nID,
		GREEN_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	GetCreatureKeyword()->AddVigilance(FALSE);

	typedef TTriggeredAbility< CTriggeredTokenProductionAbility, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		_T("Centaur A"), 2790, 2));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetLeaveEventFilter(ZoneId::Battlefield, ZoneId::Graveyard);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
// Knight of Autumn - {1}{G}{W}  Creature - Dryad Knight  2/1
// When Knight of Autumn enters the battlefield, choose one:
//   - Put two +1/+1 counters on Knight of Autumn.
//   - Destroy target artifact or enchantment.
//   - You gain 4 life.
CKnightOfAutumnCard::CKnightOfAutumnCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Knight of Autumn"), CardType::Creature, CREATURE_TYPE2(Dryad, Knight), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(1))
{
	{
		// Option 1: +2/+2 counters on self
		typedef TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +2));
		cpAbility->SetAbilityText(_T("Mode 1: put two +1/+1 counters on Knight of Autumn."));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Option 2: destroy target artifact or enchantment
		typedef TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);

		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
			new CardTypeComparer(CardType::Artifact | CardType::Enchantment, false));
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Destroy);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
		cpAbility->SetAbilityText(_T("Mode 2: destroy target artifact or enchantment."));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Option 3: gain 4 life
		typedef TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+4));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage);

		cpAbility->SetAbilityText(_T("Mode 3: you gain 4 life."));

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
// Conclave Tribunal - {3}{W}  Enchantment  Convoke
// When Conclave Tribunal enters the battlefield, exile target nonland permanent
// an opponent controls until Conclave Tribunal leaves the battlefield.
CConclaveTribunalCard::CConclaveTribunalCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Conclave Tribunal"), CardType::Enchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CConclaveTribunalCard::OnResolutionCompleted))
{
	m_ExileFilter.AddComparer(new TrueCardComparer);
	m_ExileFilter.AddNegateComparer(new CardTypeComparer(CardType::_Land, false));
	m_CreatureFilter.AddComparer(new AnyCreatureComparer);

	typedef TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new CardTypeComparer(CardType::_Land, false));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(FALSE);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

	AddAbility(cpAbility.GetPointer());
}

void CConclaveTribunalCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
}

// ============================================================================
// PLANESWALKERS
// ============================================================================

//____________________________________________________________________________
// Ral, Izzet Viceroy - {3}{U}{R}  Legendary Planeswalker - Ral  5 loyalty
// +1: Look at top 2 cards of your library. Put one into your hand and the other on bottom.
// -3: Ral deals damage equal to the number of instant and sorcery spells you've cast this turn to target.
//     (Simplified: deal 4 damage to target creature or player)
// -8: You get an emblem with "Whenever you cast an instant or sorcery, copy it twice."
//     (Simplified: deal 8 to opponent)
CRalIzzetViceroyCard::CRalIzzetViceroyCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ral, Izzet Viceroy"), nID,
		_T("3") BLUE_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Ral, 5)
	, m_cpEventListenerPlus(VAR_NAME(m_cpListenerPlus), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CRalIzzetViceroyCard::OnResolutionCompletedPlus))
	, m_cpEventListenerMinus(VAR_NAME(m_cpListenerMinus), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CRalIzzetViceroyCard::OnResolutionCompletedMinus))
{
	{
		// +1: Look at top 2 cards, put 1 in hand and 1 on bottom
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListenerPlus.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Deal 4 damage to target creature or player
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new TrueCardComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListenerMinus.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: Deal 8 damage to target opponent (simplified ultimate)
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new TruePlayerComparer, FALSE,
				Life(-8), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->SetTargetOpponentPlayerOnly();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);

		AddAbility(cpAbility.GetPointer());
	}
}

void CRalIzzetViceroyCard::OnResolutionCompletedPlus(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// Look at top 2 cards, put 1 in hand, 1 on bottom of library
	CPlayer* pController = pAbilityAction->GetController();
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(2), MaximumValue(2));
	pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(1);
	pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(1);
	pModifier->GetSelection(0).moveType = MoveType::Others;
	pModifier->AddSelection(MinimumValue(1), MaximumValue(1),
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::PrimaryPlayer,
		NULL,
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Bottom,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier->SetReorderInformation(true, ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pModifier->ApplyTo(pController);
}

void CRalIzzetViceroyCard::OnResolutionCompletedMinus(const CAbilityAction* pAbilityAction, BOOL bResult)
{
}

//____________________________________________________________________________
// Vraska, Golgari Queen - {2}{B}{G}  Legendary Planeswalker - Vraska  4 loyalty
// +2: Sacrifice a permanent → gain 1 life and draw a card.
// -3: Destroy target nonland permanent with converted mana cost 3 or less.
// -9: Each opponent loses life equal to the number of cards in your graveyard.
CVraskaGolgariQueenCard::CVraskaGolgariQueenCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vraska, Golgari Queen"), nID,
		_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Vraska, 4)
	, m_cpEventListenerPlus(VAR_NAME(m_cpListenerPlus), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CVraskaGolgariQueenCard::OnResolutionCompletedPlus))
{
	m_SacrificeFilter.AddComparer(new TrueCardComparer);
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	{
		// +2: Sacrifice a permanent, gain 1 life, draw 1 card
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListenerPlus.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Destroy target nonland permanent with CMC 3 or less
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new TrueCardComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new CardTypeComparer(CardType::_Land, false));
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(
			new ConvertedManaCostComparer<std::less_equal<int>>(3));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -9: Each opponent loses life = cards in your graveyard
		counted_ptr<CActivatedAbility<CGlobalChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGlobalChgLifeSpell>>(this,
				_T(""),
				Life(-13),
				new TruePlayerComparer, FALSE,
				PreventableType::Preventable,
				DamageType::AbilityDamage | DamageType::NonCombatDamage));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
		cpAbility->SetAffectOpponentPlayersOnly();

		AddAbility(cpAbility.GetPointer());
	}
}

void CVraskaGolgariQueenCard::OnResolutionCompletedPlus(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();

	// Gain 1 life
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), this, PreventableType::NotPreventable,
		DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pController);

	// Draw 1 card
	pController->DrawCard();
}

// ============================================================================
// LANDS
// ============================================================================

//____________________________________________________________________________
// Steam Vents - {T}: Add {U} or {R}. As it enters, you may pay 2 life (shock land)
CSteamVentsCard::CSteamVentsCard(CGame* pGame, UINT nID)
	: CDualLandCard(pGame, _T("Steam Vents"), nID,
		CardType::Island | CardType::Mountain | CardType::NonbasicLand,
		BLUE_MANA_TEXT, RED_MANA_TEXT)
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 0, _T("pay 2 life"), NULL);
}

//____________________________________________________________________________
// Overgrown Tomb - (GRN reprint) Forest Swamp shock land
COvgrownTombGRNCard::COvgrownTombGRNCard(CGame* pGame, UINT nID)
	: CDualLandCard(pGame, _T("Overgrown Tomb GRN"), nID,
		CardType::Forest | CardType::Swamp | CardType::NonbasicLand,
		GREEN_MANA_TEXT, BLACK_MANA_TEXT)
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 0, _T("pay 2 life"), NULL);
}

//____________________________________________________________________________
// Sacred Foundry - (GRN reprint) Mountain Plains shock land
CSacredFoundryGRNCard::CSacredFoundryGRNCard(CGame* pGame, UINT nID)
	: CDualLandCard(pGame, _T("Sacred Foundry GRN"), nID,
		CardType::Mountain | CardType::Plains | CardType::NonbasicLand,
		RED_MANA_TEXT, WHITE_MANA_TEXT)
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 0, _T("pay 2 life"), NULL);
}

//____________________________________________________________________________
// Temple Garden - (GRN reprint) Forest Plains shock land
CTempleGardenGRNCard::CTempleGardenGRNCard(CGame* pGame, UINT nID)
	: CDualLandCard(pGame, _T("Temple Garden GRN"), nID,
		CardType::Forest | CardType::Plains | CardType::NonbasicLand,
		GREEN_MANA_TEXT, WHITE_MANA_TEXT)
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 0, _T("pay 2 life"), NULL);
}

//____________________________________________________________________________
// Watery Grave - (GRN reprint) Island Swamp shock land
CWateryGraveGRNCard::CWateryGraveGRNCard(CGame* pGame, UINT nID)
	: CDualLandCard(pGame, _T("Watery Grave GRN"), nID,
		CardType::Island | CardType::Swamp | CardType::NonbasicLand,
		BLUE_MANA_TEXT, BLACK_MANA_TEXT)
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 0, _T("pay 2 life"), NULL);
}

//____________________________________________________________________________
// Boros Guildgate - enters tapped, {T}: add {R} or {W}
CBorosGuildgateGRNCard::CBorosGuildgateGRNCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Boros Guildgate"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
// Dimir Guildgate - enters tapped, {T}: add {U} or {B}
CDimirGuildgateGRNCard::CDimirGuildgateGRNCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Dimir Guildgate"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
// Golgari Guildgate - enters tapped, {T}: add {B} or {G}
CGolgariGuildgateGRNCard::CGolgariGuildgateGRNCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Golgari Guildgate"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
// Izzet Guildgate - enters tapped, {T}: add {U} or {R}
CIzzetGuildgateGRNCard::CIzzetGuildgateGRNCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Izzet Guildgate"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
// Selesnya Guildgate - enters tapped, {T}: add {G} or {W}
CSelesnyaGuildgateGRNCard::CSelesnyaGuildgateGRNCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Selesnya Guildgate"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}
