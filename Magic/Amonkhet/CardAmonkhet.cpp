#include "stdafx.h"
#include "CardAmonkhet.h"

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
		DEFINE_CARD(CCanyonSloughCard);
		DEFINE_CARD(CFetidPoolsCard);
		DEFINE_CARD(CIrrigatedFarmlandCard);
		DEFINE_CARD(CScatteredGrovesCard);
		DEFINE_CARD(CShelteredThicketCard);
		DEFINE_CARD(CCascadingCataractsCard);
		DEFINE_CARD(CCradleOfTheAccursedCard);
		DEFINE_CARD(CGraspingDunesCard);
		DEFINE_CARD(CPaintedBluffsCard);
		DEFINE_CARD(CSunscorchedDesertCard);
		DEFINE_CARD(CGideonOfTheTrialsCard);
		DEFINE_CARD(CGideonMartialParagonCard);
		DEFINE_CARD(CLilianaDeathsMajestyCard);
		DEFINE_CARD(CLilianaDeathWielderCard);
		DEFINE_CARD(CBontusMonumentCard);
		DEFINE_CARD(CHazoretsMonumentCard);
		DEFINE_CARD(CKefnetsMonumentCard);
		DEFINE_CARD(COketrasMonumentCard);
		DEFINE_CARD(CRhonassMonumentCard);
		DEFINE_CARD(CEdificeOfAuthorityCard);
		DEFINE_CARD(CEmbalmersToolsCard);
		DEFINE_CARD(CGateToTheAfterlifeCard);
		DEFINE_CARD(CHonedKhopeshCard);
		DEFINE_CARD(CLuxaRiverShrineCard);
		DEFINE_CARD(CPyramidOfThePantheonCard);
		DEFINE_CARD(CThroneOfTheGodPharaohCard);
		DEFINE_CARD(CAnointedProcessionCard);
		DEFINE_CARD(CBountyOfTheLuxaCard);
		DEFINE_CARD(CCartoucheOfAmbitionCard);
		DEFINE_CARD(CCartoucheOfKnowledgeCard);
		DEFINE_CARD(CCartoucheOfSolidarityCard);
		DEFINE_CARD(CCartoucheOfStrengthCard);
		DEFINE_CARD(CCartoucheOfZealCard);
		DEFINE_CARD(CCastOutCard);
		DEFINE_CARD(CCompulsoryRestCard);
		DEFINE_CARD(CConsumingFervorCard);
		DEFINE_CARD(CCruelRealityCard);
		DEFINE_CARD(CDrakeHavenCard);
		DEFINE_CARD(CFaithOfTheDevotedCard);
		DEFINE_CARD(CGideonsResolveCard);
		DEFINE_CARD(CHazoretsFavorCard);
		DEFINE_CARD(CLayClaimCard);
		DEFINE_CARD(CLilianasMasteryCard);
		DEFINE_CARD(CNewPerspectivesCard);
		DEFINE_CARD(CSandwurmConvergenceCard);
		DEFINE_CARD(CSixthSenseCard);
		DEFINE_CARD(CTrespassersCurseCard);
		DEFINE_CARD(CTrialOfAmbitionCard);
		DEFINE_CARD(CTrialOfKnowledgeCard);
		DEFINE_CARD(CTrialOfSolidarityCard);
		DEFINE_CARD(CTrialOfStrengthCard);
		DEFINE_CARD(CTrialOfZealCard);
		DEFINE_CARD(CBenefactionOfRhonasCard);
		DEFINE_CARD(CBlazingVolleyCard);
		DEFINE_CARD(CByForceCard);
		DEFINE_CARD(CCompellingArgumentCard);
		DEFINE_CARD(CFloodwatersCard);
		DEFINE_CARD(CHarvestSeasonCard);
		DEFINE_CARD(CLayBareTheHeartCard);
		DEFINE_CARD(CLilianasInfluenceCard);
		DEFINE_CARD(CLimitsOfSolidarityCard);
		DEFINE_CARD(COpenIntoWonderCard);
		DEFINE_CARD(CPainfulLessonCard);
		DEFINE_CARD(CSacredExcavationCard);
		DEFINE_CARD(CStirTheSandsCard);
		DEFINE_CARD(CSwelteringSunsCard);
		DEFINE_CARD(CViolentImpactCard);
		DEFINE_CARD(CWanderInDeathCard);
		DEFINE_CARD(CCensorCard);
		DEFINE_CARD(CDecisionParalysisCard);
		DEFINE_CARD(CDeemWorthyCard);
		DEFINE_CARD(CDissentersDeliveranceCard);
		DEFINE_CARD(CDjerusResolveCard);
		DEFINE_CARD(CElectrifyCard);
		DEFINE_CARD(CFinalRewardCard);
		DEFINE_CARD(CForsakeTheWorldlyCard);
		DEFINE_CARD(CGalestrikeCard);
		DEFINE_CARD(CHapatrasMarkCard);
		DEFINE_CARD(CHazeOfPollenCard);
		DEFINE_CARD(CHieroglyphicIlluminationCard);
		DEFINE_CARD(CInOketrasNameCard);
		DEFINE_CARD(CPullFromTomorrowCard);
		DEFINE_CARD(CPursueGloryCard);
		DEFINE_CARD(CScarabFeastCard);
		DEFINE_CARD(CShedWeaknessCard);
		DEFINE_CARD(CSplendidAgonyCard);
		DEFINE_CARD(CStingingShotCard);
		DEFINE_CARD(CSynchronizedStrikeCard);
		DEFINE_CARD(CWindsOfRebukeCard);
		DEFINE_CARD(CCommitMemoryCard);
		DEFINE_CARD(CCutRibbonsCard);
		DEFINE_CARD(CDestinedLeadCard);
		DEFINE_CARD(CDuskDawnCard);
		DEFINE_CARD(CFailureComplyCard);
		DEFINE_CARD(CHeavenEarthCard);
		DEFINE_CARD(CInsultInjuryCard);
		DEFINE_CARD(CMouthFeedCard);
		DEFINE_CARD(CNeverReturnCard);
		DEFINE_CARD(COnwardVictoryCard);
		DEFINE_CARD(CPrepareFightCard);
		DEFINE_CARD(CRagsRichesCard);
		DEFINE_CARD(CReduceRubbleCard);
		DEFINE_CARD(CSpringMindCard);
		DEFINE_CARD(CStartFinishCard);
		DEFINE_CARD(CAngelOfSanctionsCard);
		DEFINE_CARD(CAnointerPriestCard);
		DEFINE_CARD(CAvenMindcensorCard);
		DEFINE_CARD(CBindingMummyCard);
		DEFINE_CARD(CCompanionOfTheTrialsCard);
		DEFINE_CARD(CDevotedCropMateCard);
		DEFINE_CARD(CFanBearerCard);
		DEFINE_CARD(CGloryBoundInitiateCard);
		DEFINE_CARD(CGracefulCatCard);
		DEFINE_CARD(CGustWalkerCard);
		DEFINE_CARD(COketrasAttendantCard);
		DEFINE_CARD(COketraTheTrueCard);
		DEFINE_CARD(CRegalCaracalCard);
		DEFINE_CARD(CRhetCropSpearmasterCard);
		DEFINE_CARD(CSacredCatCard);
		DEFINE_CARD(CSeraphOfTheSunsCard);
		DEFINE_CARD(CSparringMummyCard);
		DEFINE_CARD(CSupplyCaravanCard);
		DEFINE_CARD(CTahCropEliteCard);
		DEFINE_CARD(CThoseWhoServeCard);
		DEFINE_CARD(CTrueheartDuelistCard);
		DEFINE_CARD(CUnwaveringInitiateCard);
		DEFINE_CARD(CVizierOfDefermentCard);
		DEFINE_CARD(CWingedShepherdCard);
		DEFINE_CARD(CBitterbladeWarriorCard);
		DEFINE_CARD(CChampionOfRhonasCard);
		DEFINE_CARD(CChannelerInitiateCard);
		DEFINE_CARD(CColossapedeCard);
		DEFINE_CARD(CCrocodileOfTheCrossingCard);
		DEFINE_CARD(CDefiantGreatmawCard);
		DEFINE_CARD(CExemplarOfStrengthCard);
		DEFINE_CARD(CGreaterSandwurmCard);
		DEFINE_CARD(CHonoredHydraCard);
		DEFINE_CARD(CHoodedBrawlerCard);
		DEFINE_CARD(CInitiatesCompanionCard);
		DEFINE_CARD(CManglehornCard);
		DEFINE_CARD(CNagaVitalistCard);
		DEFINE_CARD(COashraCultivatorCard);
		DEFINE_CARD(COrneryKuduCard);
		DEFINE_CARD(CPouncingCheetahCard);
		DEFINE_CARD(CProwlingSerpopardCard);
		DEFINE_CARD(CRhonasTheIndomitableCard);
		DEFINE_CARD(CScaledBehemothCard);
		DEFINE_CARD(CShefetMonitorCard);
		DEFINE_CARD(CWatchfulNagaCard);
		DEFINE_CARD(CAhnCropCrasherCard);
		DEFINE_CARD(CBattlefieldScavengerCard);
		DEFINE_CARD(CBloodlustInciterCard);
		DEFINE_CARD(CBloodrageBrawlerCard);
		DEFINE_CARD(CDesertCerodonCard);
		DEFINE_CARD(CEmberhornMinotaurCard);
		DEFINE_CARD(CFlamebladeAdeptCard);
		DEFINE_CARD(CGlorybringerCard);
		DEFINE_CARD(CHazoretTheFerventCard);
		DEFINE_CARD(CHeartPiercerManticoreCard);
		DEFINE_CARD(CHyenaPackCard);
		DEFINE_CARD(CManticoreOfTheGauntletCard);
		DEFINE_CARD(CMinotaurSureshotCard);
		DEFINE_CARD(CNefCropEntanglerCard);
		DEFINE_CARD(CNimbleBladeKhenraCard);
		DEFINE_CARD(CPathmakerInitiateCard);
		DEFINE_CARD(CSoulScarMageCard);
		DEFINE_CARD(CThresherLizardCard);
		DEFINE_CARD(CTrueheartTwinsCard);
		DEFINE_CARD(CWarfireJavelineerCard);
		DEFINE_CARD(CArchfiendOfIfnirCard);
		DEFINE_CARD(CBalefulAmmitCard);
		DEFINE_CARD(CBlightedBatCard);
		DEFINE_CARD(CBonePickerCard);
		DEFINE_CARD(CBontuTheGlorifiedCard);
		DEFINE_CARD(CCursedMinotaurCard);
		DEFINE_CARD(CDesiccatedNagaCard);
		DEFINE_CARD(CDoomedDissenterCard);
		DEFINE_CARD(CDreadWandererCard);
		DEFINE_CARD(CDuneBeetleCard);
		DEFINE_CARD(CFesteringMummyCard);
		DEFINE_CARD(CGrimStriderCard);
		DEFINE_CARD(CHorrorOfTheBrokenLandsCard);
		DEFINE_CARD(CLordOfTheAccursedCard);
		DEFINE_CARD(CMiasmicMummyCard);
		DEFINE_CARD(CPitilessVizierCard);
		DEFINE_CARD(CPlagueBelcherCard);
		DEFINE_CARD(CRuthlessSniperCard);
		DEFINE_CARD(CSoulstingerCard);
		DEFINE_CARD(CTatteredMummyCard);
		DEFINE_CARD(CWastelandScorpionCard);
		DEFINE_CARD(CAnglerDrakeCard);
		DEFINE_CARD(CAvenInitiateCard);
		DEFINE_CARD(CCrypticSerpentCard);
		DEFINE_CARD(CCuratorOfMysteriesCard);
		DEFINE_CARD(CGlyphKeeperCard);
		DEFINE_CARD(CHekmaSentinelsCard);
		DEFINE_CARD(CKefnetTheMindfulCard);
		DEFINE_CARD(CLabyrinthGuardianCard);
		DEFINE_CARD(CNagaOracleCard);
		DEFINE_CARD(CRiverSerpentCard);
		DEFINE_CARD(CScribeOfTheMindfulCard);
		DEFINE_CARD(CSeekerOfInsightCard);
		DEFINE_CARD(CShimmerscaleDrakeCard);
		DEFINE_CARD(CSlitherBladeCard);
		DEFINE_CARD(CTahCropSkirmisherCard);
		DEFINE_CARD(CVizierOfTumblingSandsCard);
		DEFINE_CARD(CZenithSeekerCard);
		DEFINE_CARD(CAhnCropChampionCard);
		DEFINE_CARD(CAvenWindGuideCard);
		DEFINE_CARD(CDecimatorBeetleCard);
		DEFINE_CARD(CEnigmaDrakeCard);
		DEFINE_CARD(CHapatraVizierOfPoisonsCard);
		DEFINE_CARD(CHonoredCropCaptainCard);
		DEFINE_CARD(CKhenraCharioteerCard);
		DEFINE_CARD(CMercilessJavelineerCard);
		DEFINE_CARD(CNehebTheWorthyCard);
		DEFINE_CARD(CSamutVoiceOfDissentCard);
		DEFINE_CARD(CShadowstormVizierCard);
		DEFINE_CARD(CTemmetVizierOfNaktamunCard);
		DEFINE_CARD(CWatchersOfTheDeadCard);
		DEFINE_CARD(CWaywardServantCard);
		DEFINE_CARD(CWeaverOfCurrentsCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers

#define ZOMBIE_TOKEN_NAME	_T("Zombie (P)")
#define ZOMBIE_TOKEN_ID		55009

// "Activate only as a sorcery."
static void SetAsSorcery(CAbility* pAbility)
{
	pAbility->SetAbilityType((pAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
}

// "Cycling {cost} ({cost}, Discard this card: Draw a card.)" (as Onslaught)
static CAbility* AddCycling(CCard* pCard, LPCTSTR strCost)
{
	counted_ptr<CActivatedAbility<CCyclingSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CCyclingSpell>>(pCard, strCost));

	cpAbility->SetHandOnly();
	cpAbility->AddDiscardCost();

	pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

// "{T}: Add {C}."
static void AddColorlessManaAbility(CCard* pCard)
{
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(pCard, _T(""), AbilityType::Activated, _T("1")));
	cpAbility->AddTapCost();
	pCard->AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Lands

CCyclingDualLandBase::CCyclingDualLandBase(CGame* pGame, LPCTSTR strCardName, UINT nID, CardType landType,
	LPCTSTR strMana1, LPCTSTR strMana2)
	: CDualLandCard(pGame, strCardName, nID, landType | CardType::NonbasicLand, strMana1, strMana2)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CCanyonSloughCard::CCanyonSloughCard(CGame* pGame, UINT nID)
	: CCyclingDualLandBase(pGame, _T("Canyon Slough"), nID, CardType::Swamp | CardType::Mountain,
		BLACK_MANA_TEXT, RED_MANA_TEXT)
{
}

CFetidPoolsCard::CFetidPoolsCard(CGame* pGame, UINT nID)
	: CCyclingDualLandBase(pGame, _T("Fetid Pools"), nID, CardType::Island | CardType::Swamp,
		BLUE_MANA_TEXT, BLACK_MANA_TEXT)
{
}

CIrrigatedFarmlandCard::CIrrigatedFarmlandCard(CGame* pGame, UINT nID)
	: CCyclingDualLandBase(pGame, _T("Irrigated Farmland"), nID, CardType::Plains | CardType::Island,
		WHITE_MANA_TEXT, BLUE_MANA_TEXT)
{
}

CScatteredGrovesCard::CScatteredGrovesCard(CGame* pGame, UINT nID)
	: CCyclingDualLandBase(pGame, _T("Scattered Groves"), nID, CardType::Forest | CardType::Plains,
		GREEN_MANA_TEXT, WHITE_MANA_TEXT)
{
}

CShelteredThicketCard::CShelteredThicketCard(CGame* pGame, UINT nID)
	: CCyclingDualLandBase(pGame, _T("Sheltered Thicket"), nID, CardType::Mountain | CardType::Forest,
		RED_MANA_TEXT, GREEN_MANA_TEXT)
{
}

CCascadingCataractsCard::CCascadingCataractsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Cascading Cataracts"), nID)
{
	// Indestructible (as Darksteel Citadel)
	GetCardKeyword()->AddIndestructible(FALSE);

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {5}, {T}: Add five mana in any combination of colors.
	// Partial: five mana of any one color (all the combinations would be 126 mana abilities)
	LPCTSTR colors[] = {
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT,
		BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT,
		RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT };

	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("5"), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CCradleOfTheAccursedCard::CCradleOfTheAccursedCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Cradle of the Accursed"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {3}, {T}, Sacrifice this land: Create a 2/2 black Zombie creature token. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("3"),
			ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID,
			1));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	SetAsSorcery(cpAbility.GetPointer());
	AddAbility(cpAbility.GetPointer());
}

CGraspingDunesCard::CGraspingDunesCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Grasping Dunes"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {1}, {T}, Sacrifice this land: Put a -1/-1 counter on target creature. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1"),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	SetAsSorcery(cpAbility.GetPointer());
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("-1/-1"), 1));
	AddAbility(cpAbility.GetPointer());
}

CPaintedBluffsCard::CPaintedBluffsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Painted Bluffs"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {1}, {T}: Add one mana of any color. (one mana ability for each color)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("1"), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CSunscorchedDesertCard::CSunscorchedDesertCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Sunscorched Desert"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// When this land enters, it deals 1 damage to target player or planeswalker. (as Goretusk Firebeast)
	// Note: it can't target planeswalkers
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (planeswalkers)

// Mill N cards (as Kaladesh)
static void Mill(CPlayer* pPlayer, int nCount)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < nCount && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
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

// After a Gideon's "becomes a creature" ability resolves: indestructible until end of turn (as Gideon, Ally of Zendikar)
static void GideonIndestructible(CCard* pGideon)
{
	CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Indestructible, TRUE);
	pModifier.ApplyTo(pGideon);
}

// "Until end of turn, Gideon becomes a N/N Human Soldier creature with indestructible that's still a planeswalker.
// Prevent all damage that would be dealt to him this turn." (as Gideon, Ally of Zendikar: the creature is an
// IsAlsoA entry of ATokens and MagicCore prevents the damage to Gideons by name)
static CAbility* AddGideonAnimation(CPlaneswalkerCard* pGideon, LPCTSTR strToken, UINT uID, LPCTSTR strText,
	ResolutionCompletedEventSource::Listener* pListener)
{
	counted_ptr<CIsAlsoAAbility> cpAbility(
		::CreateObject<CIsAlsoAAbility>(pGideon,
			_T(""),
			strToken, uID));

	cpAbility->SetAbilityText(strText);

	CPlayerEffectModifier* pmodifier = new CPlayerEffectModifier(PlayerEffectType::PreventDamagetoGideon2);
	CScheduledPlayerModifier* pModifier2 = new CScheduledPlayerModifier(
		pGideon->GetGame(), pmodifier, TurnNumberDelta(-1), NodeId::EndStep, CScheduledPlayerModifier::Operation::RemoveFromLater);
	pmodifier->LinkPlayerModifier(pModifier2);

	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(pmodifier);
	cpAbility->GetResolutionCompletedEventSource()->AddListener(pListener);

	pGideon->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

//____________________________________________________________________________
//
// Planeswalkers

CGideonOfTheTrialsCard::CGideonOfTheTrialsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Gideon of the Trials"), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Gideon, 3)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CGideonOfTheTrialsCard::OnResolutionCompleted))
{
	{
		// +1: Until your next turn, prevent all damage target permanent would deal.
		// Note: only creatures can be targeted
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGideonOfTheTrialsCard::BeforePrevent));
		AddAbility(cpAbility.GetPointer());
	}

	// 0: Until end of turn, Gideon becomes a 4/4 Human Soldier creature with indestructible that's still a planeswalker.
	// Prevent all damage that would be dealt to him this turn.
	AddGideonAnimation(this, _T("Animated Gideon of the Trials"), 64120,
		_T("0: Gideon of the Trials becomes a 4/4 creature. Activates"), m_cpEventListener.GetPointer());

	// 0: You get an emblem with "As long as you control a Gideon planeswalker, you can't lose the game and your
	// opponents can't win the game."
	// Not implemented: there are no replacement effects for losing the game
}

bool CGideonOfTheTrialsCard::BeforePrevent(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !dynamic_cast<CCreatureCard*>(pCard))
		return true;

	// Until your next turn: removed at the beginning of the controller's next untap step (as Liliana, the Last Hope)
	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier();
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	pKeywordModifier->GetModifier().SetToAdd(CreatureKeyword::DealNoCombatDamage | CreatureKeyword::DealNoNoncombatDamage);

	CScheduledCreatureModifier pModifier = CScheduledCreatureModifier(GetGame(),
		pKeywordModifier,
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pAction->GetController());
	pModifier.ApplyTo((CCreatureCard*)pCard);
	return true;
}

void CGideonOfTheTrialsCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (bResult)
		GideonIndestructible(this);
}

CGideonMartialParagonCard::CGideonMartialParagonCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Gideon, Martial Paragon"), nID,
		_T("4") WHITE_MANA_TEXT,
		PlaneswalkerType::Gideon, 5)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CGideonMartialParagonCard::OnResolutionCompleted))
{
	{
		// +2: Untap all creatures you control. Those creatures get +1/+1 until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGideonMartialParagonCard::BeforeUntap));
		cpAbility->SetAbilityText(_T("+2: Untap all creatures you control. Those creatures get +1/+1 until end of turn."));
		AddAbility(cpAbility.GetPointer());
	}

	// 0: Until end of turn, Gideon becomes a 5/5 Human Soldier creature with indestructible that's still a planeswalker.
	// Prevent all damage that would be dealt to him this turn.
	AddGideonAnimation(this, _T("Animated Gideon, Martial Paragon"), 64121,
		_T("0: Gideon, Martial Paragon becomes a 5/5 creature. Activates"), m_cpEventListener.GetPointer());

	{
		// -10: Creatures you control get +2/+2 until end of turn. Tap all creatures your opponents control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -10);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGideonMartialParagonCard::BeforeUltimate));
		cpAbility->SetAbilityText(_T("-10: Creatures you control get +2/+2 until end of turn. Tap all creatures your opponents control."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGideonMartialParagonCard::BeforeUntap(CAbilityAction* pAction) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	CCardOrientationModifier pUntapModifier = CCardOrientationModifier(FALSE);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard->GetOrientation()->IsTapped())
			pUntapModifier.ApplyTo(pCard);
		PumpCreature(pCard, +1, +1);
	}
	return true;
}

bool CGideonMartialParagonCard::BeforeUltimate(CAbilityAction* pAction) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +2, +2);

	CCountedCardContainer opponentCreatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, opponentCreatures);

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < opponentCreatures.GetSize(); ++i)
		if (!opponentCreatures.GetAt(i)->GetOrientation()->IsTapped())
			pTapModifier.ApplyTo(opponentCreatures.GetAt(i));
	return true;
}

void CGideonMartialParagonCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (bResult)
		GideonIndestructible(this);
}

CLilianaDeathsMajestyCard::CLilianaDeathsMajestyCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Liliana, Death's Majesty"), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Liliana, 5)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CLilianaDeathsMajestyCard::OnResolutionCompleted))
{
	{
		// +1: Create a 2/2 black Zombie creature token. Mill two cards.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaDeathsMajestyCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Return target creature card from your graveyard to the battlefield. That creature is a black Zombie in
		// addition to its other colors and types.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: Destroy all non-Zombie creatures.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaDeathsMajestyCard::BeforeDestroy));
		cpAbility->SetAbilityText(_T("-7: Destroy all non-Zombie creatures."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLilianaDeathsMajestyCard::BeforeMill(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 2);
	return true;
}

bool CLilianaDeathsMajestyCard::BeforeDestroy(CAbilityAction* pAction) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (!pCreature->GetCreatureType().HasType(SingleCreatureType::Zombie))
			pModifier.ApplyTo(pCreature);
	}
	return true;
}

void CLilianaDeathsMajestyCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	// The returned creature is a black Zombie in addition to its other colors and types
	if (!bResult)
		return;

	CCard* pCard = pAbilityAction->GetAssociatedCard();
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	pCreature->AddCardType(CardType::Black, CardType::Null, CardTypeEntry::Temporary);
	CCreatureTypeModifier pTypeModifier = CCreatureTypeModifier(SingleCreatureType::Zombie, TRUE);
	pTypeModifier.ApplyTo(pCreature);
}

CLilianaDeathWielderCard::CLilianaDeathWielderCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Liliana, Death Wielder"), nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Liliana, 5)
{
	{
		// +2: Put a -1/-1 counter on up to one target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("-1/-1"), 1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Destroy target creature with a -1/-1 counter on it.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(
			new CardCounterComparer<std::greater_equal<int>>(_T("-1/-1"), 1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -10: Return all creature cards from your graveyard to the battlefield.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -10);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaDeathWielderCard::BeforeReturn));
		cpAbility->SetAbilityText(_T("-10: Return all creature cards from your graveyard to the battlefield."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLilianaDeathWielderCard::BeforeReturn(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer creatures;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetCardType().IsCreature())
			creatures.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pController);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (artifacts)

#define WARRIOR_TOKEN_NAME	_T("Warrior (E)")
#define WARRIOR_TOKEN_ID	55094
#define BRICK_COUNTER		_T("brick counter")

// The creature doesn't untap during its controller's next untap step (as Aether Revolt)
static void SkipNextUntap(CGame* pGame, CCard* pCard)
{
	CScheduledCardModifier pModifier = CScheduledCardModifier(pGame,
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pModifier.ApplyTo(pCard);
}

// The player discards nCount cards of their choice (as Aether Revolt)
static void DiscardCards(CGame* pGame, CPlayer* pPlayer, int nCount)
{
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

static void DrawCards(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CDrawCardModifier pModifier = CDrawCardModifier(pGame, MinimumValue(nCount), MaximumValue(nCount));
	pModifier.ApplyTo(pPlayer);
}

static void GainLife(CCard* pSource, CPlayer* pPlayer, int nLife)
{
	CLifeModifier pModifier = CLifeModifier(Life(nLife), pSource, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pPlayer);
}

// Each opponent of pPlayer loses nLife life
static void EachOpponentLosesLife(CCard* pSource, CPlayer* pPlayer, int nLife)
{
	if (nLife <= 0)
		return;

	CGame* pGame = pSource->GetGame();
	CLifeModifier pModifier = CLifeModifier(Life(-nLife), pSource, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		if (pGame->GetPlayer(ip) != pPlayer)
			pModifier.ApplyTo(pGame->GetPlayer(ip));
}

static int CountCounters(CCard* pCard, LPCTSTR strCounter)
{
	const Counter* pCounter = ((const CCard*)pCard)->GetCounterContainer()->GetCounter(strCounter);
	return pCounter ? pCounter->GetCount() : 0;
}

// "Activate only if <condition>" (pCard's member returning BOOL)
template <class T>
static void AddPlayableIf(T* pCard, CAbility* pAbility, BOOL (T::*condition)(BOOL))
{
	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(pAbility, CPlayableIfTrait::PlayableCallback(pCard, condition)));
	pAbility->Add(cpTrait.GetPointer());
}

// "Equipped creature gets +N/+N" (as Eldritch Moon)
static void AddEquipBonus(CEquipAbility* pAbility, CCard* pCard, Power nPower, Life nLife)
{
	if (nLife != Life(0))
		pAbility->AddCreatureModifier(new CLifeModifier(nLife, pCard,
			PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	if (nPower != Power(0))
		pAbility->AddCreatureModifier(new CPowerModifier(nPower, FALSE));
}

//____________________________________________________________________________
//
// Artifacts

CMonumentBase::CMonumentBase(CGame* pGame, LPCTSTR strCardName, UINT nID, CardType color)
	: CInPlaySpellCard(pGame, strCardName, CardType::_LegendaryArtifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// <Color> creature spells you cast cost {1} less to cast. (as Ragemonger in Born of the Gods)
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CardTypeComparer(CardType::Creature | color, true),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

// "Whenever you cast a creature spell, <effect>" (as Eyes of the Watcher in Fifth Dawn)
template <class T>
static void AddCreatureSpellTrigger(T* pCard, bool (T::*callback)(CAbilityAction*) const, bool bOptional)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever you cast a creature spell, <effect on target creature>" (bOwn: a creature you control, otherwise one an
// opponent controls). The callback does everything and returns false.
template <class T>
static void AddCreatureSpellTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*) const, bool bOwn)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Creature, false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	if (bOwn)
	{
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	}
	else
	{
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	}
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

CBontusMonumentCard::CBontusMonumentCard(CGame* pGame, UINT nID)
	: CMonumentBase(pGame, _T("Bontu's Monument"), nID, CardType::Black)
{
	// Whenever you cast a creature spell, each opponent loses 1 life and you gain 1 life.
	AddCreatureSpellTrigger(this, &CBontusMonumentCard::BeforeDrain, false);
}

bool CBontusMonumentCard::BeforeDrain(CAbilityAction* pAction) const
{
	EachOpponentLosesLife((CCard*)this, pAction->GetController(), 1);
	GainLife((CCard*)this, pAction->GetController(), 1);
	return true;
}

CHazoretsMonumentCard::CHazoretsMonumentCard(CGame* pGame, UINT nID)
	: CMonumentBase(pGame, _T("Hazoret's Monument"), nID, CardType::Red)
{
	// Whenever you cast a creature spell, you may discard a card. If you do, draw a card.
	AddCreatureSpellTrigger(this, &CHazoretsMonumentCard::BeforeLoot, true);
}

bool CHazoretsMonumentCard::BeforeLoot(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	if (pController->GetZoneById(ZoneId::Hand)->GetSize() == 0)
		return true;

	DiscardCards(GetGame(), pController, 1);
	DrawCards(GetGame(), pController, 1);
	return true;
}

CKefnetsMonumentCard::CKefnetsMonumentCard(CGame* pGame, UINT nID)
	: CMonumentBase(pGame, _T("Kefnet's Monument"), nID, CardType::Blue)
{
	// Whenever you cast a creature spell, target creature an opponent controls doesn't untap during its controller's
	// next untap step.
	AddCreatureSpellTargetTrigger(this, &CKefnetsMonumentCard::BeforeFreeze, false);
}

bool CKefnetsMonumentCard::BeforeFreeze(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		SkipNextUntap(GetGame(), pCard);
	return false;
}

COketrasMonumentCard::COketrasMonumentCard(CGame* pGame, UINT nID)
	: CMonumentBase(pGame, _T("Oketra's Monument"), nID, CardType::White)
{
	// Whenever you cast a creature spell, create a 1/1 white Warrior creature token with vigilance.
	AddCreatureSpellTrigger(this, &COketrasMonumentCard::BeforeToken, false);
}

bool COketrasMonumentCard::BeforeToken(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), WARRIOR_TOKEN_NAME, WARRIOR_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CRhonassMonumentCard::CRhonassMonumentCard(CGame* pGame, UINT nID)
	: CMonumentBase(pGame, _T("Rhonas's Monument"), nID, CardType::Green)
{
	// Whenever you cast a creature spell, target creature you control gets +2/+2 and gains trample until end of turn.
	AddCreatureSpellTargetTrigger(this, &CRhonassMonumentCard::BeforePump, true);
}

bool CRhonassMonumentCard::BeforePump(CAbilityAction* pAction) const
{
	PumpCreature(pAction->GetAssociatedCard(), +2, +2, CreatureKeyword::Trample);
	return false;
}

CEdificeOfAuthorityCard::CEdificeOfAuthorityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Edifice of Authority"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// {1}, {T}: Target creature can't attack this turn. Put a brick counter on this artifact.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(BRICK_COUNTER), +1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEdificeOfAuthorityCard::BeforeCantAttack));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}, {T}: Until your next turn, target creature can't attack or block and its activated abilities can't be
		// activated. Activate only if there are three or more brick counters on this artifact.
		// Partial: its activated abilities can still be activated
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEdificeOfAuthorityCard::BeforeCantAttackOrBlock));
		AddPlayableIf(this, cpAbility.GetPointer(), &CEdificeOfAuthorityCard::HasThreeBricks);
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CEdificeOfAuthorityCard::HasThreeBricks(BOOL bIncludeTricks)
{
	return CountCounters(this, BRICK_COUNTER) >= 3;
}

bool CEdificeOfAuthorityCard::BeforeCantAttack(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::CantAttack);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);
	return true;
}

bool CEdificeOfAuthorityCard::BeforeCantAttackOrBlock(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	// Until your next turn (as Liliana, the Last Hope in Eldritch Moon)
	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier();
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	pKeywordModifier->GetModifier().SetToAdd(CreatureKeyword::CantAttack | CreatureKeyword::CantBlock);

	CScheduledCreatureModifier pModifier = CScheduledCreatureModifier(GetGame(),
		pKeywordModifier,
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pAction->GetController());
	pModifier.ApplyTo(pCreature);
	return true;
}

CEmbalmersToolsCard::CEmbalmersToolsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Embalmer's Tools"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_ZombieFilter(_T("an untapped Zombie you control"), _T("untapped Zombies you control"), new CreatureTypeComparer(CREATURE_TYPE(Zombie), false))
{
	// Activated abilities of creature cards in your graveyard cost {1} less to activate.
	// Not implemented: there are no cost reductions for activated abilities

	// Tap an untapped Zombie you control: Target player mills a card. (as Diregraf Colossus's tap cost in Eldritch Moon)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->GetCost().AddTapCardCost(1, &m_ZombieFilter);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmbalmersToolsCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CEmbalmersToolsCard::BeforeMill(CAbilityAction* pAction) const
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 1);
	return true;
}

CGateToTheAfterlifeCard::CGateToTheAfterlifeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Gate to the Afterlife"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// Whenever a nontoken creature you control dies, you gain 1 life. Then you may draw a card. If you do, discard a
	// card. (as Midnight Entourage in Aether Revolt; the optional part is a second, optional trigger)
	for (int i = 0; i < 2; ++i)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::Token, false)));
		if (i == 0)
		{
			cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
			cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
				new CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
		}
		else
		{
			cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
			cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGateToTheAfterlifeCard::BeforeLoot));
		}
		AddAbility(cpAbility.GetPointer());
	}

	// {2}, {T}, Sacrifice this artifact: Search your graveyard, hand, and/or library for a card named God-Pharaoh's Gift
	// and put it onto the battlefield. ...
	// Not implemented: God-Pharaoh's Gift (Hour of Devastation) isn't in the game yet
}

bool CGateToTheAfterlifeCard::BeforeLoot(CAbilityAction* pAction) const
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CHonedKhopeshCard::CHonedKhopeshCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Honed Khopesh"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature gets +1/+1. Equip {1}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	AddEquipBonus(cpAbility.GetPointer(), this, Power(+1), Life(+1));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CLuxaRiverShrineCard::CLuxaRiverShrineCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Luxa River Shrine"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// {1}, {T}: You gain 1 life. Put a brick counter on this artifact.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(BRICK_COUNTER), +1);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
		cpAbility->SetAbilityText(_T("You gain 1 life. Put a brick counter on Luxa River Shrine. Activates"));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}: You gain 2 life. Activate only if there are three or more brick counters on this artifact.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CLifeModifier(Life(+2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
		cpAbility->SetAbilityText(_T("You gain 2 life. Activates"));
		AddPlayableIf(this, cpAbility.GetPointer(), &CLuxaRiverShrineCard::HasThreeBricks);
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CLuxaRiverShrineCard::HasThreeBricks(BOOL bIncludeTricks)
{
	return CountCounters(this, BRICK_COUNTER) >= 3;
}

CPyramidOfThePantheonCard::CPyramidOfThePantheonCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pyramid of the Pantheon"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };

	// {2}, {T}: Add one mana of any color. Put a brick counter on this artifact.
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("2"), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(BRICK_COUNTER), +1);
		AddAbility(cpAbility.GetPointer());
	}

	// {T}: Add three mana of any one color. Activate only if there are three or more brick counters on this artifact.
	LPCTSTR threeMana[] = {
		WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT,
		BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(threeMana); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, threeMana[i]));
		cpAbility->AddTapCost();
		AddPlayableIf(this, cpAbility.GetPointer(), &CPyramidOfThePantheonCard::HasThreeBricks);
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CPyramidOfThePantheonCard::HasThreeBricks(BOOL bIncludeTricks)
{
	return CountCounters(this, BRICK_COUNTER) >= 3;
}

CThroneOfTheGodPharaohCard::CThroneOfTheGodPharaohCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Throne of the God-Pharaoh"), CardType::_LegendaryArtifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// At the beginning of your end step, each opponent loses life equal to the number of tapped creatures you control.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThroneOfTheGodPharaohCard::BeforeLoseLife));
	AddAbility(cpAbility.GetPointer());
}

bool CThroneOfTheGodPharaohCard::BeforeLoseLife(CAbilityAction* pAction) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	int nTapped = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetOrientation()->IsTapped())
			++nTapped;

	EachOpponentLosesLife((CCard*)this, pAction->GetController(), nTapped);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (enchantments)

#define DRAKE_TOKEN_NAME	_T("Drake (B)")
#define DRAKE_TOKEN_ID		2960
#define WURM_TOKEN_NAME		_T("Wurm (I)")
#define WURM_TOKEN_ID		55095
#define BEAST_TOKEN_NAME	_T("Beast (R)")
#define BEAST_TOKEN_ID		55096
#define FLOOD_COUNTER		_T("flood counter")

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

// "When this enters, <effect on target creature>" (the callback does everything and returns false)
template <class T>
static CAbility* AddEnterTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional,
	bool bOpponentsOnly, Characteristic characteristic)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	if (bOpponentsOnly)
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(characteristic);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

// "When this enchantment leaves the battlefield" (as Aether Revolt)
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

// Exiles the card (until the enchantment leaves the battlefield) and remembers it (as Aether Revolt)
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

// The player sacrifices one permanent of their choice among those that pass pFilter (as Perilous Research in
// Coldsnap). Returns FALSE if the player controls no such permanent.
static BOOL SacrificeOne(CGame* pGame, CPlayer* pPlayer, const CCardFilter* pFilter)
{
	if (pFilter->CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return FALSE;

	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Battlefield, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select the permanent to sacrifice
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		pFilter, // what cards
		ZoneId::Graveyard, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Sacrifice, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);
	return TRUE;
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

// "pCard1 fights pCard2" (each deals damage equal to its power to the other)
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

// The Cartouches (all their names start with "Cartouche"), for the Trials
struct CartoucheComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsEnchantment() && pCard->GetPrintedCardName().Left(9) == _T("Cartouche");
	}

	virtual CartoucheComparer* Clone() const
	{
		return new CartoucheComparer;
	}
};

//____________________________________________________________________________
//
// Enchantments

CAnointedProcessionCard::CAnointedProcessionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Anointed Procession"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// If an effect would create one or more tokens under your control, it creates twice that many of those tokens
	// instead. (as Doubling Season)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::DoubleTokens, 1, TRUE));
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());
}

CBountyOfTheLuxaCard::CBountyOfTheLuxaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Bounty of the Luxa"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your first main phase, remove all flood counters from this enchantment. If no counters were
	// removed this way, put a flood counter on this enchantment and draw a card. Otherwise, add {C}{G}{U}.
	// (as Magus of the Vineyard in Future Sight)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::MainPhaseStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBountyOfTheLuxaCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBountyOfTheLuxaCard::BeforeFlood));
	AddAbility(cpAbility.GetPointer());
}

bool CBountyOfTheLuxaCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetGame()->IsFirstMainPhase() == TRUE;
}

bool CBountyOfTheLuxaCard::BeforeFlood(CAbilityAction* pAction)
{
	int nCounters = CountCounters(this, FLOOD_COUNTER);
	if (nCounters > 0)
	{
		CCardCounterModifier pRemove = CCardCounterModifier(FLOOD_COUNTER, -nCounters);
		pRemove.ApplyTo(this);

		CManaPoolModifier pManaModifier = CManaPoolModifier(CManaPoolModifier::Operation::Add,
			CManaPool::CManaPool(_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT));
		pManaModifier.ApplyTo(pAction->GetController());
	}
	else
	{
		if (GetZoneId() == ZoneId::Battlefield)
		{
			CCardCounterModifier pAdd = CCardCounterModifier(FLOOD_COUNTER, +1);
			pAdd.ApplyTo(this);
		}
		DrawCards(GetGame(), pAction->GetController(), 1);
	}
	return true;
}

CCartoucheBase::CCartoucheBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCost, CreatureKeyword keyword)
	: CChgPwrTghAttrEnchantCard(pGame, strCardName, nID, strCost, Power(+1), Life(+1), keyword)
{
	// Enchant creature you control (as Faith Unbroken in Eldritch Moon)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetIncludeControllerCardsOnly();
}

CCartoucheOfAmbitionCard::CCartoucheOfAmbitionCard(CGame* pGame, UINT nID)
	: CCartoucheBase(pGame, _T("Cartouche of Ambition"), nID, _T("2") BLACK_MANA_TEXT, CreatureKeyword::Null)
{
	// Enchanted creature has lifelink (as Homicidal Seclusion in Avacyn Restored)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);

	// When this Aura enters, you may put a -1/-1 counter on target creature.
	AddEnterTargetTrigger(this, &CCartoucheOfAmbitionCard::BeforeCounter, true, false, Characteristic::Negative);
}

bool CCartoucheOfAmbitionCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CCartoucheOfKnowledgeCard::CCartoucheOfKnowledgeCard(CGame* pGame, UINT nID)
	: CCartoucheBase(pGame, _T("Cartouche of Knowledge"), nID, _T("1") BLUE_MANA_TEXT, CreatureKeyword::Flying)
{
	// When this Aura enters, draw a card.
	AddEnterTrigger(this, &CCartoucheOfKnowledgeCard::BeforeDraw);
}

bool CCartoucheOfKnowledgeCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CCartoucheOfSolidarityCard::CCartoucheOfSolidarityCard(CGame* pGame, UINT nID)
	: CCartoucheBase(pGame, _T("Cartouche of Solidarity"), nID, WHITE_MANA_TEXT, CreatureKeyword::FirstStrike)
{
	// When this Aura enters, create a 1/1 white Warrior creature token with vigilance.
	AddEnterTrigger(this, &CCartoucheOfSolidarityCard::BeforeToken);
}

bool CCartoucheOfSolidarityCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), WARRIOR_TOKEN_NAME, WARRIOR_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CCartoucheOfStrengthCard::CCartoucheOfStrengthCard(CGame* pGame, UINT nID)
	: CCartoucheBase(pGame, _T("Cartouche of Strength"), nID, _T("2") GREEN_MANA_TEXT, CreatureKeyword::Trample)
{
	// When this Aura enters, you may have enchanted creature fight target creature an opponent controls.
	AddEnterTargetTrigger(this, &CCartoucheOfStrengthCard::BeforeFight, true, true, Characteristic::Negative);
}

bool CCartoucheOfStrengthCard::BeforeFight(CAbilityAction* pAction)
{
	Fight(GetEnchantedOn(), pAction->GetAssociatedCard());
	return false;
}

CCartoucheOfZealCard::CCartoucheOfZealCard(CGame* pGame, UINT nID)
	: CCartoucheBase(pGame, _T("Cartouche of Zeal"), nID, RED_MANA_TEXT, CreatureKeyword::Haste)
{
	// When this Aura enters, target creature can't block this turn.
	AddEnterTargetTrigger(this, &CCartoucheOfZealCard::BeforeCantBlock, false, false, Characteristic::Negative);
}

bool CCartoucheOfZealCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return false;
}

CCastOutCard::CCastOutCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cast Out"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	{
		// When this enchantment enters, exile target nonland permanent an opponent controls until this enchantment
		// leaves the battlefield. (as Thopter Arrest in Aether Revolt)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Permanent, false));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCastOutCard::BeforeExile));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		AddAbility(cpAbility.GetPointer());
	}
	AddLeaveTrigger(this, &CCastOutCard::BeforeReturn);

	// Cycling {W}
	AddCycling(this, WHITE_MANA_TEXT);
}

bool CCastOutCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CCastOutCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CCompulsoryRestCard::CCompulsoryRestCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Compulsory Rest"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
{
	// Enchanted creature can't attack or block.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// Enchanted creature has "{2}, Sacrifice this creature: You gain 2 life." (as Lunarch Mantle in Eldritch Moon)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().LinkCardModifier(
		new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CCompulsoryRestCard::CreateLifeAbility)));
}

counted_ptr<CAbility> CCompulsoryRestCard::CreateLifeAbility(CCard* pCard)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("2")));

	cpAbility->AddSacrificeCost();
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+2), pCard, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->SetAbilityText(_T("You gain 2 life (Compulsory Rest). Activates"));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CConsumingFervorCard::CConsumingFervorCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Consuming Fervor"), nID,
		RED_MANA_TEXT,
		Power(+3), Life(+3), CreatureKeyword::Null)
{
	// Enchanted creature gets +3/+3 and has "At the beginning of your upkeep, put a -1/-1 counter on this creature."
	// (the trigger belongs to this Aura: at the beginning of the upkeep of the enchanted creature's controller)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CConsumingFervorCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConsumingFervorCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CConsumingFervorCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	CCard* pCreature = GetEnchantedOn();
	return pCreature && pCreature->GetController() == GetGame()->GetActivePlayer();
}

bool CConsumingFervorCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCreature = GetEnchantedOn();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

CCruelRealityCard::CCruelRealityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cruel Reality"), CardType::GlobalEnchantment, nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_SacrificeFilter(_T("a creature or planeswalker"), _T("creatures or planeswalkers"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
{
	// Enchant player. At the beginning of enchanted player's upkeep, that player sacrifices a creature or planeswalker
	// of their choice. If the player can't, they lose 5 life.
	// Note: the game has no Auras that enchant players: this curse is a global enchantment that always affects the
	// controller's opponent
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCruelRealityCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCruelRealityCard::BeforeSacrifice));
	AddAbility(cpAbility.GetPointer());
}

bool CCruelRealityCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetGame()->GetActivePlayer() != GetController();
}

bool CCruelRealityCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pCursed = GetGame()->GetNextPlayer(pAction->GetController());
	if (!SacrificeOne(GetGame(), pCursed, &m_SacrificeFilter))
	{
		CLifeModifier pModifier = CLifeModifier(Life(-5), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pCursed);
	}
	return true;
}

// "Whenever you cycle or discard a card, you may pay {1}. If you do, <effect>." (cycling discards the card;
// the optional payment is a resolution cost, as Eyes of the Watcher in Fifth Dawn)
template <class T>
static void AddCycleOrDiscardTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionCost(_T("1"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

CDrakeHavenCard::CDrakeHavenCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Drake Haven"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cycle or discard a card, you may pay {1}. If you do, create a 2/2 blue Drake creature token with
	// flying.
	AddCycleOrDiscardTrigger(this, &CDrakeHavenCard::BeforeToken);
}

bool CDrakeHavenCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), DRAKE_TOKEN_NAME, DRAKE_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CFaithOfTheDevotedCard::CFaithOfTheDevotedCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Faith of the Devoted"), CardType::GlobalEnchantment, nID,
		_T("2") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cycle or discard a card, you may pay {1}. If you do, each opponent loses 2 life and you gain 2 life.
	AddCycleOrDiscardTrigger(this, &CFaithOfTheDevotedCard::BeforeDrain);
}

bool CFaithOfTheDevotedCard::BeforeDrain(CAbilityAction* pAction)
{
	EachOpponentLosesLife(this, pAction->GetController(), 2);
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CGideonsResolveCard::CGideonsResolveCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Gideon's Resolve"), CardType::GlobalEnchantment, nID,
		_T("4") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, you may search your library and/or graveyard for a card named Gideon, Martial
	// Paragon, reveal it, and put it into your hand. If you search your library this way, shuffle.
	// (the graveyard is searched first, then the library)
	AddEnterTrigger(this, &CGideonsResolveCard::BeforeSearch, true);

	// Creatures you control get +1/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+1), Life(+1)));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool CGideonsResolveCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ZoneId zones[] = { ZoneId::Graveyard, ZoneId::Library };
	for (int z = 0; z < _countof(zones); ++z)
	{
		CZone* pZone = pController->GetZoneById(zones[z]);
		for (int i = 0; i < pZone->GetSize(); ++i)
		{
			CCard* pCard = pZone->GetAt(i);
			if (pCard->GetPrintedCardName() == _T("Gideon, Martial Paragon"))
			{
				CMoveCardModifier pModifier = CMoveCardModifier(zones[z], ZoneId::Hand, TRUE, MoveType::Others);
				pModifier.ApplyTo(pCard);
				if (zones[z] == ZoneId::Library)
					pZone->Shuffle();
				return true;
			}
		}
	}
	// Nothing found: the library was searched
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CHazoretsFavorCard::CHazoretsFavorCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hazoret's Favor"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of combat on your turn, you may have target creature you control get +2/+0 and gain haste until
	// end of turn. If you do, sacrifice it at the beginning of the next end step.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHazoretsFavorCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CHazoretsFavorCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	PumpCreature(pCard, +2, +0, CreatureKeyword::Haste);

	// Sacrifice it at the beginning of the next end step (as Saheeli Rai in Kaladesh)
	CScheduledCardModifier pSacrificeModifier = CScheduledCardModifier(GetGame(),
		new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice),
		TurnNumberDelta(-1), NodeId::EndStep, true, CScheduledCardModifier::Operation::ApplyToLater);
	pSacrificeModifier.ApplyTo(pCard);
	return false;
}

CLayClaimCard::CLayClaimCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lay Claim"), CardType::EnchantPermanent, nID)
{
	// Enchant permanent. You control enchanted permanent. (as Control Magic)
	counted_ptr<CControlEnchant> cpSpell(
		::CreateObject<CControlEnchant>(this,
			_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::_Permanent, false)));

	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CLilianasMasteryCard::CLilianasMasteryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Liliana's Mastery"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Zombies you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Zombie), false),
				Power(+1), Life(+1)));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this enchantment enters, create two 2/2 black Zombie creature tokens.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID, 2));
		AddAbility(cpAbility.GetPointer());
	}
}

CNewPerspectivesCard::CNewPerspectivesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("New Perspectives"), CardType::GlobalEnchantment, nID,
		_T("5") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, draw three cards.
	AddEnterTrigger(this, &CNewPerspectivesCard::BeforeDraw);

	// As long as you have seven or more cards in hand, you may pay {0} rather than pay cycling costs.
	// Not implemented: the cycling costs of other cards can't be changed
}

bool CNewPerspectivesCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 3);
	return true;
}

CSandwurmConvergenceCard::CSandwurmConvergenceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sandwurm Convergence"), CardType::GlobalEnchantment, nID,
		_T("6") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Creatures with flying can't attack you or planeswalkers you control.
		// (the opponents can't attack with creatures with flying)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantAttackWithCreatures, (int)CCardFilter::GetFilter(_T("flying creatures")), TRUE));
		cpAbility->SetAffectOpponentsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of your end step, create a 5/5 green Wurm creature token.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), WURM_TOKEN_NAME, WURM_TOKEN_ID, 1));
		AddAbility(cpAbility.GetPointer());
	}
}

CSixthSenseCard::CSixthSenseCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Sixth Sense"), nID,
		GREEN_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Null)
{
	// Enchanted creature has "Whenever this creature deals combat damage to a player, you may draw a card."
	// (the trigger belongs to this Aura, as Coastal Piracy)
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

CTrespassersCurseCard::CTrespassersCurseCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Trespasser's Curse"), CardType::GlobalEnchantment, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// Enchant player. Whenever a creature enchanted player controls enters, that player loses 1 life and you gain 1 life.
	// Note: the game has no Auras that enchant players: this curse is a global enchantment that always affects the
	// controller's opponent
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTrespassersCurseCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CTrespassersCurseCard::BeforeDrain(CAbilityAction* pAction)
{
	EachOpponentLosesLife(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CTrialBase::CTrialBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCost)
	: CInPlaySpellCard(pGame, strCardName, CardType::GlobalEnchantment, nID,
		strCost, AbilityType::Enchantment)
{
	// When a Cartouche you control enters, return this enchantment to its owner's hand.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CartoucheComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTrialBase::BeforeReturnToHand));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Hand));
	AddAbility(cpAbility.GetPointer());
}

bool CTrialBase::BeforeReturnToHand(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(this);
	}
	return true;
}

CTrialOfAmbitionCard::CTrialOfAmbitionCard(CGame* pGame, UINT nID)
	: CTrialBase(pGame, _T("Trial of Ambition"), nID, _T("1") BLACK_MANA_TEXT)
{
	// When this enchantment enters, target opponent sacrifices a creature of their choice.
	// Note: the opponent isn't targeted (it's always the next player)
	AddEnterTrigger(this, &CTrialOfAmbitionCard::BeforeSacrifice);
}

bool CTrialOfAmbitionCard::BeforeSacrifice(CAbilityAction* pAction)
{
	SacrificeOne(GetGame(), GetGame()->GetNextPlayer(pAction->GetController()), CCardFilter::GetFilter(_T("creatures")));
	return true;
}

CTrialOfKnowledgeCard::CTrialOfKnowledgeCard(CGame* pGame, UINT nID)
	: CTrialBase(pGame, _T("Trial of Knowledge"), nID, _T("3") BLUE_MANA_TEXT)
{
	// When this enchantment enters, draw three cards, then discard a card.
	AddEnterTrigger(this, &CTrialOfKnowledgeCard::BeforeDraw);
}

bool CTrialOfKnowledgeCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 3);
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CTrialOfSolidarityCard::CTrialOfSolidarityCard(CGame* pGame, UINT nID)
	: CTrialBase(pGame, _T("Trial of Solidarity"), nID, _T("2") WHITE_MANA_TEXT)
{
	// When this enchantment enters, creatures you control get +2/+1 and gain vigilance until end of turn.
	AddEnterTrigger(this, &CTrialOfSolidarityCard::BeforePump);
}

bool CTrialOfSolidarityCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +2, +1, CreatureKeyword::Vigilance);
	return true;
}

CTrialOfStrengthCard::CTrialOfStrengthCard(CGame* pGame, UINT nID)
	: CTrialBase(pGame, _T("Trial of Strength"), nID, _T("2") GREEN_MANA_TEXT)
{
	// When this enchantment enters, create a 4/2 green Beast creature token.
	AddEnterTrigger(this, &CTrialOfStrengthCard::BeforeToken);
}

bool CTrialOfStrengthCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), BEAST_TOKEN_NAME, BEAST_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CTrialOfZealCard::CTrialOfZealCard(CGame* pGame, UINT nID)
	: CTrialBase(pGame, _T("Trial of Zeal"), nID, _T("2") RED_MANA_TEXT)
{
	// When this enchantment enters, it deals 3 damage to any target. (as Goretusk Firebeast; no planeswalkers)
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-3));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (sorceries and instants)

// Cards with cycling (an ability tagged as cycling)
struct HasCyclingComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		CAbilityContainer abilities = pCard->GetAbilities();
		for (int i = 0; i < abilities.GetSize(); ++i)
			if ((abilities.GetAt(i)->GetAbilityTag() & AbilityTag::Cycling).Any())
				return true;
		return false;
	}

	virtual HasCyclingComparer* Clone() const
	{
		return new HasCyclingComparer;
	}
};

// pSource deals nDamage damage to each creature (bControlled: controlled by pPlayer; otherwise by the other players;
// both: all creatures)
static void DamageEachCreature(CCard* pSource, CPlayer* pPlayer, int nDamage, bool bOwn, bool bOthers)
{
	CCountedCardContainer creatures;
	if (bOwn)
		GetCreatures(pSource->GetGame(), pPlayer, TRUE, creatures);
	if (bOthers)
		GetCreatures(pSource->GetGame(), pPlayer, FALSE, creatures);

	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(pSource, creatures.GetAt(i), nDamage);
}

// Searches pPlayer's graveyard and then library for a card named strName and puts it into their hand (shuffling the
// library if it was searched). For "you may search your library and/or graveyard for a card named ..."
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

//____________________________________________________________________________
//
// Sorceries

CBenefactionOfRhonasCard::CBenefactionOfRhonasCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Benefaction of Rhonas"), CardType::Sorcery, nID)
	, m_CreatureFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
	, m_EnchantmentFilter(_T("an enchantment card"), _T("enchantment cards"), new CardTypeComparer(CardType::_Enchantment, false))
{
	// Reveal the top five cards of your library. You may put a creature card and/or an enchantment card from among them
	// into your hand. Put the rest into your graveyard.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBenefactionOfRhonasCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBenefactionOfRhonasCard::BeforeResolution(CAbilityAction* pAction)
{
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 5,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::AllPlayers);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a creature card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		&m_CreatureFilter, // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // to this player's hand
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // an enchantment card
		CZoneModifier::RoleType::PrimaryPlayer,
		CZoneModifier::RoleType::AllPlayers,
		&m_EnchantmentFilter,
		ZoneId::Hand,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top,
		MoveType::Others,
		CZoneModifier::RoleType::PrimaryPlayer);

	// Put the rest into your graveyard
	pModifier.SetReorderInformation(true, ZoneId::Graveyard, CZoneModifier::RoleType::PrimaryPlayer, CardPlacement::Top);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CBlazingVolleyCard::CBlazingVolleyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blazing Volley"), CardType::Sorcery, nID)
{
	// Blazing Volley deals 1 damage to each creature your opponents control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlazingVolleyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBlazingVolleyCard::BeforeResolution(CAbilityAction* pAction)
{
	DamageEachCreature(this, pAction->GetController(), 1, false, true);
	return true;
}

CByForceCard::CByForceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("By Force"), CardType::Sorcery, nID)
{
	// Destroy X target artifacts. (the X targets as Glimpse the Sun God in Born of the Gods)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetCost().SetExtraManaCost();
	cpSpell->AdjustTargetCountWithExtraCostValue();
	AddSpell(cpSpell.GetPointer());
}

CCompellingArgumentCard::CCompellingArgumentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Compelling Argument"), CardType::Sorcery, nID)
{
	// Target player mills five cards.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCompellingArgumentCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	// Cycling {U}
	AddCycling(this, BLUE_MANA_TEXT);
}

bool CCompellingArgumentCard::BeforeResolution(CAbilityAction* pAction)
{
	if (pAction->GetAssociatedPlayer())
		Mill(pAction->GetAssociatedPlayer(), 5);
	return true;
}

CFloodwatersCard::CFloodwatersCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Floodwaters"), CardType::Sorcery, nID)
{
	// Return up to two target creatures to their owners' hands.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CHarvestSeasonCard::CHarvestSeasonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Harvest Season"), CardType::Sorcery, nID)
{
	// Search your library for up to X basic land cards, where X is the number of tapped creatures you control, put
	// those cards onto the battlefield tapped, then shuffle.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHarvestSeasonCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHarvestSeasonCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pController, TRUE, creatures);
	int nTapped = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetOrientation()->IsTapped())
			++nTapped;

	if (nTapped > 0)
	{
		CCountedCardContainer lands;
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &lands);
		pModifier.AddSelection(MinimumValue(0), MaximumValue(nTapped), // up to X basic land cards
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			CCardFilter::GetFilter(_T("basic lands")), // what cards
			ZoneId::Battlefield, // if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
			CardPlacement::Top, // placement
			MoveType::Others, // move type
			CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
		pModifier.ApplyTo(pController);

		// Tapped
		CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
		for (int i = 0; i < lands.GetSize(); ++i)
			if (lands.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
				pTapModifier.ApplyTo(lands.GetAt(i));
	}

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CLayBareTheHeartCard::CLayBareTheHeartCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lay Bare the Heart"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CLayBareTheHeartCard::OnCardSelected))
{
	// Target opponent reveals their hand. You choose a nonlegendary, nonland card from it. That player discards that
	// card. (as Harsh Scrutiny in Kaladesh)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLayBareTheHeartCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CLayBareTheHeartCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CZone* pHand = pOpponent->GetZoneById(ZoneId::Hand);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		if (pCard->GetCardType().IsLand() || (pCard->GetCardType() & CardType::Legendary).Any())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CLayBareTheHeartCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Hand)
				return;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
			return;
		}
}

CLilianasInfluenceCard::CLilianasInfluenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Liliana's Influence"), CardType::Sorcery, nID)
{
	// Put a -1/-1 counter on each creature you don't control. You may search your library and/or graveyard for a card
	// named Liliana, Death Wielder, reveal it, and put it into your hand. If you search your library this way, shuffle.
	// (the graveyard is searched first, then the library)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianasInfluenceCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CLilianasInfluenceCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pModifier.ApplyTo(creatures.GetAt(i));

	SearchNamedCardToHand(pAction->GetController(), _T("Liliana, Death Wielder"));
	return true;
}

CLimitsOfSolidarityCard::CLimitsOfSolidarityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Limits of Solidarity"), CardType::Sorcery, nID)
{
	// Gain control of target creature until end of turn. Untap that creature. It gains haste until end of turn.
	// (as Act of Treason in M10)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpSpell->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	cpSpell->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

COpenIntoWonderCard::COpenIntoWonderCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Open into Wonder"), CardType::Sorcery, nID)
{
	// X target creatures can't be blocked this turn. Until end of turn, those creatures gain "Whenever this creature
	// deals combat damage to a player, draw a card."
	// Partial: the creatures don't gain the draw trigger
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLUE_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::Unblockable, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetCost().SetExtraManaCost();
	cpSpell->AdjustTargetCountWithExtraCostValue();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());
}

CPainfulLessonCard::CPainfulLessonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Painful Lesson"), CardType::Sorcery, nID)
{
	// Target player draws two cards and loses 2 life.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPainfulLessonCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPainfulLessonCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
	{
		DrawCards(GetGame(), pPlayer, 2);
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

CSacredExcavationCard::CSacredExcavationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sacred Excavation"), CardType::Sorcery, nID)
{
	// Return up to two target cards with cycling from your graveyard to your hand.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT,
			new HasCyclingComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddSpell(cpSpell.GetPointer());
}

CStirTheSandsCard::CStirTheSandsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stir the Sands"), CardType::Sorcery, nID)
{
	{
		// Create three 2/2 black Zombie creature tokens.
		counted_ptr<CTokenProductionSpell> cpSpell(
			::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
				_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT,
				ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID,
				3));
		AddSpell(cpSpell.GetPointer());
	}

	// Cycling {3}{B}
	AddCycling(this, _T("3") BLACK_MANA_TEXT);

	{
		// When you cycle this card, create a 2/2 black Zombie creature token. (as Onslaught)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenThisCardCycled > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID, 1));
		AddAbility(cpAbility.GetPointer());
	}
}

CSwelteringSunsCard::CSwelteringSunsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sweltering Suns"), CardType::Sorcery, nID)
{
	// Sweltering Suns deals 3 damage to each creature.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSwelteringSunsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	// Cycling {3}
	AddCycling(this, _T("3"));
}

bool CSwelteringSunsCard::BeforeResolution(CAbilityAction* pAction)
{
	DamageEachCreature(this, pAction->GetController(), 3, true, true);
	return true;
}

CViolentImpactCard::CViolentImpactCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Violent Impact"), CardType::Sorcery, nID)
{
	// Destroy target artifact or land.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::_Land, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CWanderInDeathCard::CWanderInDeathCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wander in Death"), CardType::Sorcery, nID)
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

	// Cycling {2}
	AddCycling(this, _T("2"));
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

CCensorCard::CCensorCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Censor"), CardType::Instant, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	// Counter target spell unless its controller pays {1}. (as Stymied Hopes in Theros)
	m_pCounterSpell->SetCanBeDenied();
	m_pCounterSpell->GetDenialCost().SetManaCost(_T("1"));

	// Cycling {U}
	AddCycling(this, BLUE_MANA_TEXT);
}

CDecisionParalysisCard::CDecisionParalysisCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Decision Paralysis"), CardType::Instant, nID)
{
	// Tap up to two target creatures. Those creatures don't untap during their controller's next untap step.
	// (as Eldritch Moon's AddTapNoUntapModifiers)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

	cpSpell->AddAbilityTag(AbilityTag::OrientationChange);
	AddSpell(cpSpell.GetPointer());
}

CDeemWorthyCard::CDeemWorthyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deem Worthy"), CardType::Instant, nID)
{
	{
		// Deem Worthy deals 7 damage to target creature.
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				_T("4") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-7), PreventableType::Preventable));
		AddSpell(cpSpell.GetPointer());
	}

	// Cycling {3}{R}
	AddCycling(this, _T("3") RED_MANA_TEXT);

	{
		// When you cycle this card, you may have it deal 2 damage to target creature.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenThisCardCycled > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

CDissentersDeliveranceCard::CDissentersDeliveranceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dissenter's Deliverance"), CardType::Instant, nID)
{
	// Destroy target artifact.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	AddSpell(cpSpell.GetPointer());

	// Cycling {G}
	AddCycling(this, GREEN_MANA_TEXT);
}

CDjerusResolveCard::CDjerusResolveCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Djeru's Resolve"), CardType::Instant, nID)
{
	// Untap target creature. Prevent all damage that would be dealt to it this turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDjerusResolveCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CDjerusResolveCard::BeforeResolution(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	if (pCreature->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCreature);
	}

	// Prevent all damage that would be dealt to it this turn (as the animated Gideons' prevention, for one turn)
	Life prevent(PreventionType::PreventAllDamage);
	CDamagePreventionEntry entry(prevent);
	entry.SetOneTurnOnly(TRUE);
	pCreature->GetDamagePrevention().AddDamagePreventionEntry(entry);
	return true;
}

CElectrifyCard::CElectrifyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Electrify"), CardType::Instant, nID)
{
	// Electrify deals 4 damage to target creature.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-4), PreventableType::Preventable));
	AddSpell(cpSpell.GetPointer());
}

CFinalRewardCard::CFinalRewardCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Final Reward"), CardType::Instant, nID)
{
	// Exile target creature.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("4") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));
	AddSpell(cpSpell.GetPointer());
}

CForsakeTheWorldlyCard::CForsakeTheWorldlyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Forsake the Worldly"), CardType::Instant, nID)
{
	// Exile target artifact or enchantment.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CGalestrikeCard::CGalestrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Galestrike"), CardType::Instant, nID)
{
	// Return target tapped creature to its owner's hand. Draw a card. (as Select for Inspection in Kaladesh)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGalestrikeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGalestrikeCard::BeforeResolution(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CHapatrasMarkCard::CHapatrasMarkCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hapatra's Mark"), CardType::Instant, nID)
{
	// Target creature you control gains hexproof until end of turn. Remove all -1/-1 counters from it.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHapatrasMarkCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHapatrasMarkCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardKeywordModifier pHexproof = CCardKeywordModifier(CardKeyword::Hexproof, TRUE);
	pHexproof.ApplyTo(pCard);

	int nCounters = CountCounters(pCard, _T("-1/-1"));
	if (nCounters > 0)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), -nCounters);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CHazeOfPollenCard::CHazeOfPollenCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Haze of Pollen"), CardType::Instant, nID)
{
	// Prevent all combat damage that would be dealt this turn. (as Fog)
	counted_ptr<CPlayerEffectSpell> cpSpell(
		::CreateObject<CPlayerEffectSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			PlayerEffectType::PreventAllCombatDamage, TRUE));
	AddSpell(cpSpell.GetPointer());

	// Cycling {3}
	AddCycling(this, _T("3"));
}

CHieroglyphicIlluminationCard::CHieroglyphicIlluminationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hieroglyphic Illumination"), CardType::Instant, nID)
{
	// Draw two cards.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT, 2));
	AddSpell(cpSpell.GetPointer());

	// Cycling {U}
	AddCycling(this, BLUE_MANA_TEXT);
}

CInOketrasNameCard::CInOketrasNameCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("In Oketra's Name"), CardType::Instant, nID)
{
	// Zombies you control get +2/+1 until end of turn. Other creatures you control get +1/+1 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInOketrasNameCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CInOketrasNameCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (pCreature->GetCreatureType().HasType(SingleCreatureType::Zombie))
			PumpCreature(pCreature, +2, +1);
		else
			PumpCreature(pCreature, +1, +1);
	}
	return true;
}

CPullFromTomorrowCard::CPullFromTomorrowCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pull from Tomorrow"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CPullFromTomorrowCard::OnResolutionCompleted))
{
	// Draw X cards, then discard a card. (X as Mind Spring in M10)
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT BLUE_MANA_TEXT, 0));

	cpSpell->GetCost().SetExtraManaCost();
	cpSpell->SetExtraActionValueVector();
	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

void CPullFromTomorrowCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (bResult)
		DiscardCards(GetGame(), pAbilityAction->GetController(), 1);
}

CPursueGloryCard::CPursueGloryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pursue Glory"), CardType::Instant, nID)
{
	// Attacking creatures get +2/+0 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPursueGloryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CPursueGloryCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (((CCreatureCard*)creatures.GetAt(i))->IsAttacking())
			PumpCreature(creatures.GetAt(i), +2, +0);
	return true;
}

CScarabFeastCard::CScarabFeastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Scarab Feast"), CardType::Instant, nID)
{
	// Exile up to three target cards from a single graveyard.
	// Note: the targets can be in different graveyards
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			BLACK_MANA_TEXT,
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(1, 3);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());

	// Cycling {B}
	AddCycling(this, BLACK_MANA_TEXT);
}

CShedWeaknessCard::CShedWeaknessCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shed Weakness"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 until end of turn. You may remove a -1/-1 counter from it.
	// (the counter is always removed)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShedWeaknessCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CShedWeaknessCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(pCard, +2, +2);
	if (CountCounters(pCard, _T("-1/-1")) > 0)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), -1);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CSplendidAgonyCard::CSplendidAgonyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Splendid Agony"), CardType::Instant, nID)
{
	// Distribute two -1/-1 counters among one or two target creatures.
	// (one target: two counters on it; two targets: one counter on each)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSplendidAgonyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSplendidAgonyCard::BeforeResolution(CAbilityAction* pAction)
{
	CTargetSpellAction* pTargetAction = dynamic_cast<CTargetSpellAction*>(pAction);
	if (!pTargetAction)
		return true;

	CCountedCardContainer targets;
	for (CSubjectGroup::CardSubjectIterator it = pTargetAction->GetTargetGroup().CardSubjectBegin();
		it != pTargetAction->GetTargetGroup().CardSubjectEnd(); ++it)
	{
		CCard* pCard = const_cast<CCard*>(it->GetPointer());
		if (pCard->GetZoneId() == ZoneId::Battlefield)
			targets.AddCard(pCard, CardPlacement::Top);
	}

	int nCounters = targets.GetSize() == 1 ? 2 : 1;
	CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), nCounters);
	for (int i = 0; i < targets.GetSize(); ++i)
		pModifier.ApplyTo(targets.GetAt(i));
	return false;
}

CStingingShotCard::CStingingShotCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stinging Shot"), CardType::Instant, nID)
{
	// Put three -1/-1 counters on target creature with flying.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureKeywordComparer(CreatureKeyword::Flying, false));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("-1/-1"), 3));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CSynchronizedStrikeCard::CSynchronizedStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Synchronized Strike"), CardType::Instant, nID)
{
	// Untap up to two target creatures. They each get +2/+2 until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT,
			Power(+2), Life(+2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
	AddSpell(cpSpell.GetPointer());
}

CWindsOfRebukeCard::CWindsOfRebukeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Winds of Rebuke"), CardType::Instant, nID)
{
	// Return target nonland permanent to its owner's hand. Each player mills two cards.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::_Permanent, false),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWindsOfRebukeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWindsOfRebukeCard::BeforeResolution(CAbilityAction* pAction)
{
	// (the mill happens as the spell starts resolving, before the permanent returns)
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		Mill(GetGame()->GetPlayer(ip), 2);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (Aftermath)

#define HIPPO_TOKEN_NAME	_T("Hippo (C)")
#define HIPPO_TOKEN_ID		55097

// The first half of an Aftermath card: cast only from the hand (as Far // Away in Dragon's Maze for the name)
static void SetFirstHalf(CSpell* pSpell, LPCTSTR strName)
{
	CAftermathSupport::SetFirstHalf(pSpell);
	pSpell->SetAbilityName(strName);

	CString strText;
	strText.Format(_T("%s. Casts"), strName);
	pSpell->SetAbilityText(strText);
}

// pSource deals nDamage damage to each creature with flying (bFlying) or without flying (!bFlying)
static void DamageEachCreatureByFlying(CCard* pSource, CPlayer* pPlayer, int nDamage, bool bFlying)
{
	CCountedCardContainer creatures;
	GetCreatures(pSource->GetGame(), pPlayer, TRUE, creatures);
	GetCreatures(pSource->GetGame(), pPlayer, FALSE, creatures);

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if ((pCreature->GetCreatureKeyword()->Flying() == TRUE) == bFlying)
			DealDamageToCreature(pSource, pCreature, nDamage);
	}
}

//____________________________________________________________________________
//
// Aftermath

CCommitMemoryCard::CCommitMemoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Commit // Memory"), CardType::Instant | CardType::Sorcery, nID)
{
	// Commit: Put target spell or nonland permanent into its owner's library second from the top.
	// Partial: the card is put on top of the library (one spell for spells and another one for permanents)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("3") BLUE_MANA_TEXT,
				new TrueCardComparer));

		cpSpell->SetToZone(ZoneId::Library, TRUE, CardPlacement::Top);
		SetFirstHalf(cpSpell.GetPointer(), _T("Commit (target spell)"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("3") BLUE_MANA_TEXT,
				new CardTypeComparer(CardType::_Permanent, false),
				ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		SetFirstHalf(cpSpell.GetPointer(), _T("Commit (target permanent)"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Memory: Each player shuffles their hand and graveyard into their library, then draws seven cards.
		// (as Timetwister)
		counted_ptr<CGlobalDrawCardSpell> cpSpell(
			::CreateObject<CGlobalDrawCardSpell>(this, AbilityType::Sorcery,
				_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, 7, 7));

		cpSpell->SetMergeGraveyard(TRUE);
		cpSpell->SetMergeHand(TRUE);
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Memory"));
		AddSpell(cpSpell.GetPointer());
	}
}

CCutRibbonsCard::CCutRibbonsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cut // Ribbons"), CardType::Sorcery, nID)
{
	{
		// Cut: Cut deals 4 damage to target creature.
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				_T("1") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		SetFirstHalf(cpSpell.GetPointer(), _T("Cut"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Ribbons: Each opponent loses X life.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT BLACK_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost();
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCutRibbonsCard::BeforeRibbons));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Ribbons"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CCutRibbonsCard::BeforeRibbons(CAbilityAction* pAction)
{
	EachOpponentLosesLife(this, pAction->GetController(), GetLastCastingExtraValue());
	return true;
}

CDestinedLeadCard::CDestinedLeadCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Destined // Lead"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Destined: Target creature gets +1/+0 and gains indestructible until end of turn.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDestinedLeadCard::BeforeDestined));
		SetFirstHalf(cpSpell.GetPointer(), _T("Destined"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Lead: All creatures able to block target creature this turn do so. (Lure until end of turn)
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
				_T("3") GREEN_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::Lure, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Lead"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CDestinedLeadCard::BeforeDestined(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(pCard, +1, +0);
	CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Indestructible, TRUE);
	pModifier.ApplyTo(pCard);
	return true;
}

CDuskDawnCard::CDuskDawnCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dusk // Dawn"), CardType::Sorcery, nID)
{
	{
		// Dusk: Destroy all creatures with power 3 or greater.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDuskDawnCard::BeforeDusk));
		SetFirstHalf(cpSpell.GetPointer(), _T("Dusk"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Dawn: Return all creature cards with power 2 or less from your graveyard to your hand.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDuskDawnCard::BeforeDawn));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Dawn"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CDuskDawnCard::BeforeDusk(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (GET_INTEGER(((CCreatureCard*)creatures.GetAt(i))->GetPower()) >= 3)
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

bool CDuskDawnCard::BeforeDawn(CAbilityAction* pAction)
{
	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer cards;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pGraveyard->GetAt(i));
		if (pCreature && pCreature->GetCardType().IsCreature() && GET_INTEGER(pCreature->GetPower()) <= 2)
			cards.AddCard(pCreature, CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
	for (int i = 0; i < cards.GetSize(); ++i)
		pModifier.ApplyTo(cards.GetAt(i));
	return true;
}

CFailureComplyCard::CFailureComplyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Failure // Comply"), CardType::Instant | CardType::Sorcery, nID)
{
	// Failure: Return target spell to its owner's hand. (as Remand in Ravnica)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetToZone(ZoneId::Hand, TRUE);
	SetFirstHalf(cpSpell.GetPointer(), _T("Failure"));
	AddSpell(cpSpell.GetPointer());

	// Comply: Choose a card name. Until your next turn, your opponents can't cast spells with the chosen name.
	// Not implemented: a card name can't be chosen
}

CHeavenEarthCard::CHeavenEarthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Heaven // Earth"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Heaven: Heaven deals X damage to each creature with flying.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Instant,
				GREEN_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost();
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeavenEarthCard::BeforeHeaven));
		SetFirstHalf(cpSpell.GetPointer(), _T("Heaven"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Earth: Earth deals X damage to each creature without flying.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				RED_MANA_TEXT RED_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost();
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeavenEarthCard::BeforeEarth));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Earth"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CHeavenEarthCard::BeforeHeaven(CAbilityAction* pAction)
{
	DamageEachCreatureByFlying(this, pAction->GetController(), GetLastCastingExtraValue(), true);
	return true;
}

bool CHeavenEarthCard::BeforeEarth(CAbilityAction* pAction)
{
	DamageEachCreatureByFlying(this, pAction->GetController(), GetLastCastingExtraValue(), false);
	return true;
}

CInsultInjuryCard::CInsultInjuryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Insult // Injury"), CardType::Sorcery, nID)
{
	{
		// Insult: Damage can't be prevented this turn. If a source you control would deal damage this turn, it deals
		// double that damage instead.
		// Partial: the damage isn't doubled (there are no damage replacement effects)
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInsultInjuryCard::BeforeInsult));
		SetFirstHalf(cpSpell.GetPointer(), _T("Insult"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Injury: Injury deals 2 damage to target creature and 2 damage to target player or planeswalker.
		// (no planeswalkers)
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				FALSE_CARD_COMPARER, TRUE, _T("")));

		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInsultInjuryCard::BeforeInjury));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Injury"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CInsultInjuryCard::BeforeInsult(CAbilityAction* pAction)
{
	// Damage can't be prevented this turn (for every player, removed at the end step as Gideon, Ally of Zendikar)
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayerEffectModifier* pModifier = new CPlayerEffectModifier(PlayerEffectType::CantPreventDamage);
		CScheduledPlayerModifier* pRemove = new CScheduledPlayerModifier(
			GetGame(), pModifier, TurnNumberDelta(-1), NodeId::EndStep, CScheduledPlayerModifier::Operation::RemoveFromLater);
		pModifier->LinkPlayerModifier(pRemove);
		pModifier->ApplyTo(GetGame()->GetPlayer(ip));
	}
	return true;
}

bool CInsultInjuryCard::BeforeInjury(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	DealDamageToCreature(this, (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(), 2);

	CPlayer* pPlayer = (CPlayer*)pDoubleTargetAction->GetTargetGroup2().GetFirstPlayerSubject();
	if (pPlayer)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}
	return false;
}

CMouthFeedCard::CMouthFeedCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mouth // Feed"), CardType::Sorcery, nID)
{
	{
		// Mouth: Create a 3/3 green Hippo creature token.
		counted_ptr<CTokenProductionSpell> cpSpell(
			::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
				_T("2") GREEN_MANA_TEXT,
				HIPPO_TOKEN_NAME, HIPPO_TOKEN_ID,
				1));

		SetFirstHalf(cpSpell.GetPointer(), _T("Mouth"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Feed: Draw a card for each creature you control with power 3 or greater.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("3") GREEN_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMouthFeedCard::BeforeFeed));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Feed"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CMouthFeedCard::BeforeFeed(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	int nCount = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (GET_INTEGER(((CCreatureCard*)creatures.GetAt(i))->GetPower()) >= 3)
			++nCount;

	if (nCount > 0)
		DrawCards(GetGame(), pAction->GetController(), nCount);
	return true;
}

CNeverReturnCard::CNeverReturnCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Never // Return"), CardType::Sorcery, nID)
{
	{
		// Never: Destroy target creature or planeswalker.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT,
				new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		SetFirstHalf(cpSpell.GetPointer(), _T("Never"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Return: Exile target card from a graveyard. Create a 2/2 black Zombie creature token.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("3") BLACK_MANA_TEXT,
				new TrueCardComparer,
				ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNeverReturnCard::BeforeReturn));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Return"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CNeverReturnCard::BeforeReturn(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

COnwardVictoryCard::COnwardVictoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Onward // Victory"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Onward: Target creature gets +X/+0 until end of turn, where X is its power.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COnwardVictoryCard::BeforeOnward));
		SetFirstHalf(cpSpell.GetPointer(), _T("Onward"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Victory: Target creature gains double strike until end of turn.
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
				_T("2") WHITE_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::DoubleStrike, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Victory"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool COnwardVictoryCard::BeforeOnward(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		int nPower = GET_INTEGER(pCreature->GetPower());
		if (nPower > 0)
			PumpCreature(pCreature, nPower, +0);
	}
	return true;
}

CPrepareFightCard::CPrepareFightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Prepare // Fight"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Prepare: Untap target creature. It gets +2/+2 and gains lifelink until end of turn.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("1") WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrepareFightCard::BeforePrepare));
		SetFirstHalf(cpSpell.GetPointer(), _T("Prepare"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Fight: Target creature you control fights target creature an opponent controls.
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("3") GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrepareFightCard::BeforeFight));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Fight"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CPrepareFightCard::BeforePrepare(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	if (pCard->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
		pUntap.ApplyTo(pCard);
	}
	PumpCreature(pCard, +2, +2);
	CCardKeywordModifier pLifelink = CCardKeywordModifier(CardKeyword::Lifelink, TRUE);
	pLifelink.ApplyTo(pCard);
	return true;
}

bool CPrepareFightCard::BeforeFight(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (pDoubleTargetAction)
		Fight((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
			(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject());
	return false;
}

CRagsRichesCard::CRagsRichesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rags // Riches"), CardType::Sorcery, nID)
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRagsRichesCard::OnCreatureSelected))
{
	{
		// Rags: All creatures get -2/-2 until end of turn.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRagsRichesCard::BeforeRags));
		SetFirstHalf(cpSpell.GetPointer(), _T("Rags"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Riches: Each opponent chooses a creature they control. You gain control of those creatures.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRagsRichesCard::BeforeRiches));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Riches"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CRagsRichesCard::BeforeRags(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), -2, -2);
	return true;
}

bool CRagsRichesCard::BeforeRiches(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CCountedCardContainer creatures;
		GetCreatures(GetGame(), pOpponent, TRUE, creatures);

		std::vector<SelectionEntry> entries;
		for (int i = 0; i < creatures.GetSize(); ++i)
		{
			CCard* pCard = creatures.GetAt(i);
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Give %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}

		// The opponent chooses (dwContext1: the player who gains control)
		if (!entries.empty())
			m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent, (DWORD)pController);
	}
	return true;
}

void CRagsRichesCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Battlefield)
				return;

			// You gain control of it (as Arabian Nights: the control goes to this card's controller)
			CGainControlModifier pModifier = CGainControlModifier(GetGame(), this);
			pModifier.ApplyTo(pCard);
			return;
		}
}

CReduceRubbleCard::CReduceRubbleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reduce // Rubble"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Reduce: Counter target spell unless its controller pays {3}.
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT,
				new TrueCardComparer));

		cpSpell->SetCanBeDenied();
		cpSpell->GetDenialCost().SetManaCost(_T("3"));
		SetFirstHalf(cpSpell.GetPointer(), _T("Reduce"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Rubble: Up to three target lands don't untap during their controller's next untap step.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT,
				new CardTypeComparer(CardType::_Land, false), FALSE));

		cpSpell->GetTargeting()->SetSubjectCount(1, 3);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Rubble"));
		AddSpell(cpSpell.GetPointer());
	}
}

CSpringMindCard::CSpringMindCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spring // Mind"), CardType::Sorcery | CardType::Instant, nID)
{
	{
		// Spring: Search your library for a basic land card, put it onto the battlefield tapped, then shuffle.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("2") GREEN_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpringMindCard::BeforeSpring));
		SetFirstHalf(cpSpell.GetPointer(), _T("Spring"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Mind: Draw two cards.
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
				_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, 2));

		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Mind"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CSpringMindCard::BeforeSpring(CAbilityAction* pAction)
{
	// (as Harvest Season)
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer lands;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &lands);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a basic land card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("basic lands")), // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < lands.GetSize(); ++i)
		if (lands.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pTapModifier.ApplyTo(lands.GetAt(i));

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CStartFinishCard::CStartFinishCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Start // Finish"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Start: Create two 1/1 white Warrior creature tokens with vigilance.
		counted_ptr<CTokenProductionSpell> cpSpell(
			::CreateObject<CTokenProductionSpell>(this, AbilityType::Instant,
				_T("2") WHITE_MANA_TEXT,
				WARRIOR_TOKEN_NAME, WARRIOR_TOKEN_ID,
				2));

		SetFirstHalf(cpSpell.GetPointer(), _T("Start"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Finish: As an additional cost to cast this spell, sacrifice a creature. Destroy target creature.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("2") BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Finish"));
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (creatures)

#define CAT_TOKEN_NAME	_T("Cat (G)")
#define CAT_TOKEN_ID	55098

// "Whenever this creature attacks, <effect>" with the effect in a resolution callback (as Aether Revolt)
template <class T>
static void AddAttackTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional = false)
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

// Other creatures of a creature type (for "Other <type>s you control get ...")
struct OtherCreatureTypeComparer : public CardComparer
{
	OtherCreatureTypeComparer(const CCard* pCard, SingleCreatureType type)
		: m_pCard(pCard)
		, m_Type(type)
	{}

	virtual bool operator()(const CCard* pCard) const
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
		return pCreature && pCard != m_pCard && pCreature->GetCreatureType().HasType(m_Type);
	}

	virtual OtherCreatureTypeComparer* Clone() const
	{
		return new OtherCreatureTypeComparer(m_pCard, m_Type);
	}

protected:
	const CCard* m_pCard;
	SingleCreatureType m_Type;
};

//____________________________________________________________________________
//
// White creatures

CAngelOfSanctionsCard::CAngelOfSanctionsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Sanctions"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(4))
	, m_Embalm(this)
{
	{
		// When this creature enters, you may exile target nonland permanent an opponent controls until this creature
		// leaves the battlefield. (as Cast Out)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Permanent, false));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngelOfSanctionsCard::BeforeExile));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		AddAbility(cpAbility.GetPointer());
	}
	AddLeaveTrigger(this, &CAngelOfSanctionsCard::BeforeReturn);

	// Embalm {5}{W}
	m_Embalm.AddEmbalmAbility(_T("5") WHITE_MANA_TEXT);
}

bool CAngelOfSanctionsCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CAngelOfSanctionsCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CAnointerPriestCard::CAnointerPriestCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Anointer Priest"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(3))
	, m_Embalm(this)
{
	{
		// Whenever a creature token you control enters, you gain 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Creature | CardType::Token, true));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
		AddAbility(cpAbility.GetPointer());
	}

	// Embalm {3}{W}
	m_Embalm.AddEmbalmAbility(_T("3") WHITE_MANA_TEXT);
}

CAvenMindcensorCard::CAvenMindcensorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Mindcensor"), CardType::Creature, CREATURE_TYPE2(Bird, Wizard), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// If an opponent would search a library, that player searches the top four cards of that library instead.
	// Not implemented: there are no replacement effects for searching a library
}

CBindingMummyCard::CBindingMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Binding Mummy"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever another Zombie you control enters, you may tap target artifact or creature.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new OtherCreatureTypeComparer(this, SingleCreatureType::Zombie));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::Creature, false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBindingMummyCard::BeforeTap));
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

bool CBindingMummyCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && !pCard->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CCompanionOfTheTrialsCard::CCompanionOfTheTrialsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Companion of the Trials"), CardType::Creature, CREATURE_TYPE2(Bird, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// {1}{W}: Untap target creature. Activate only if you control a Gideon planeswalker.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddPlayableIf(this, cpAbility.GetPointer(), &CCompanionOfTheTrialsCard::ControlsGideon);
	AddAbility(cpAbility.GetPointer());
}

BOOL CCompanionOfTheTrialsCard::ControlsGideon(BOOL bIncludeTricks)
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CPlaneswalkerCard* pWalker = dynamic_cast<CPlaneswalkerCard*>(pBattlefield->GetAt(i));
		if (pWalker && pWalker->GetSubtype() == PlaneswalkerType::Gideon)
			return TRUE;
	}
	return FALSE;
}

CDevotedCropMateCard::CDevotedCropMateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Devoted Crop-Mate"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// You may exert this creature as it attacks. When you do, return target creature card with mana value 2 or less
	// from your graveyard to the battlefield. (an optional attack trigger with a target; see CExertSupport)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(2));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDevotedCropMateCard::BeforeExertReturn));
	cpAbility->SetAbilityText(_T("Exert: return target creature card with mana value 2 or less from your graveyard to the battlefield."));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Battlefield));
	AddAbility(cpAbility.GetPointer());
}

bool CDevotedCropMateCard::BeforeExertReturn(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CFanBearerCard::CFanBearerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fan Bearer"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		WHITE_MANA_TEXT, Power(1), Life(2))
{
	// {2}, {T}: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2"),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new TappedComparer));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CGloryBoundInitiateCard::CGloryBoundInitiateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glory-Bound Initiate"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, it gets +1/+3 and gains lifelink until end of turn.
	m_Exert.AddExertAbility(_T("it gets +1/+3 and gains lifelink until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CGloryBoundInitiateCard::BeforeExert));
}

bool CGloryBoundInitiateCard::BeforeExert(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(this, +1, +3);
	CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Lifelink, TRUE);
	pModifier.ApplyTo(this);
	return true;
}

CGracefulCatCard::CGracefulCatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Graceful Cat"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, it gets +1/+1 until end of turn.
	AddAttackTrigger(this, &CGracefulCatCard::BeforePump);
}

bool CGracefulCatCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

CGustWalkerCard::CGustWalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gust Walker"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, it gets +1/+1 and gains flying until end of turn.
	m_Exert.AddExertAbility(_T("it gets +1/+1 and gains flying until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CGustWalkerCard::BeforeExert));
}

bool CGustWalkerCard::BeforeExert(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1, CreatureKeyword::Flying);
	return true;
}

COketrasAttendantCard::COketrasAttendantCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Oketra's Attendant"), CardType::Creature, CREATURE_TYPE2(Bird, Soldier), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_Embalm(this)
{
	// Cycling {2}
	AddCycling(this, _T("2"));

	// Embalm {3}{W}{W}
	m_Embalm.AddEmbalmAbility(_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT);
}

COketraTheTrueCard::COketraTheTrueCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oketra the True"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(6))
{
	// Double strike, indestructible
	GetCreatureKeyword()->AddDoubleStrike(FALSE);
	GetCardKeyword()->AddIndestructible(FALSE);

	{
		// Oketra can't attack or block unless you control at least three other creatures.
		// (it can't while you control two or fewer other creatures, as the Delirium conditions)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetConditionFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->SetConditionCheckZone(ZoneId::Battlefield);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(2);
		cpAbility->SetConditionIsMaximum();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{W}: Create a 1/1 white Warrior creature token with vigilance.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("3") WHITE_MANA_TEXT,
				WARRIOR_TOKEN_NAME, WARRIOR_TOKEN_ID,
				1));
		AddAbility(cpAbility.GetPointer());
	}
}

CRegalCaracalCard::CRegalCaracalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Regal Caracal"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	{
		// Other Cats you control get +1/+1 and have lifelink.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new OtherCreatureTypeComparer(this, SingleCreatureType::Cat),
				Power(+1), Life(+1), CreatureKeyword::Null));

		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
		cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this creature enters, create two 1/1 white Cat creature tokens with lifelink.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), CAT_TOKEN_NAME, CAT_TOKEN_ID, 2));
		AddAbility(cpAbility.GetPointer());
	}
}

CRhetCropSpearmasterCard::CRhetCropSpearmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rhet-Crop Spearmaster"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, it gets +1/+0 and gains first strike until end of turn.
	m_Exert.AddExertAbility(_T("it gets +1/+0 and gains first strike until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CRhetCropSpearmasterCard::BeforeExert));
}

bool CRhetCropSpearmasterCard::BeforeExert(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +0, CreatureKeyword::FirstStrike);
	return true;
}

CSacredCatCard::CSacredCatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sacred Cat"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
	, m_Embalm(this)
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// Embalm {W}
	m_Embalm.AddEmbalmAbility(WHITE_MANA_TEXT);
}

CSeraphOfTheSunsCard::CSeraphOfTheSunsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Seraph of the Suns"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Indestructible
	GetCardKeyword()->AddIndestructible(FALSE);
}

CSparringMummyCard::CSparringMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sparring Mummy"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, untap target creature.
	AddEnterTargetTrigger(this, &CSparringMummyCard::BeforeUntap, false, false, Characteristic::Positive);
}

bool CSparringMummyCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CSupplyCaravanCard::CSupplyCaravanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Supply Caravan"), CardType::Creature, CREATURE_TYPE(Camel), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(5))
{
	// When this creature enters, if you control a tapped creature, create a 1/1 white Warrior creature token with
	// vigilance. (checked when it triggers and on resolution)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSupplyCaravanCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSupplyCaravanCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CSupplyCaravanCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetOrientation()->IsTapped())
			return true;
	return false;
}

bool CSupplyCaravanCard::BeforeToken(CAbilityAction* pAction)
{
	CTriggeredAbility<>::TriggerContextType context;
	if (!SetTriggerContext(context, NULL, NULL, NULL, MoveType::Others))
		return true;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), WARRIOR_TOKEN_NAME, WARRIOR_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CTahCropEliteCard::CTahCropEliteCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Tah-Crop Elite"), CardType::Creature, CREATURE_TYPE2(Bird, Warrior), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, creatures you control get +1/+1 until end of turn.
	m_Exert.AddExertAbility(_T("creatures you control get +1/+1 until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CTahCropEliteCard::BeforeExert));
}

bool CTahCropEliteCard::BeforeExert(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +1, +1);
	return true;
}

CThoseWhoServeCard::CThoseWhoServeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Those Who Serve"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(4))
{
}

CTrueheartDuelistCard::CTrueheartDuelistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trueheart Duelist"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Embalm(this)
{
	// This creature can block an additional creature each combat.
	SetMaxBlockingCount(2);

	// Embalm {2}{W}
	m_Embalm.AddEmbalmAbility(_T("2") WHITE_MANA_TEXT);
}

CUnwaveringInitiateCard::CUnwaveringInitiateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Unwavering Initiate"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
	, m_Embalm(this)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Embalm {4}{W}
	m_Embalm.AddEmbalmAbility(_T("4") WHITE_MANA_TEXT);
}

CVizierOfDefermentCard::CVizierOfDefermentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vizier of Deferment"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, you may exile target creature if it attacked or blocked this turn. Return that card
	// to the battlefield under its owner's control at the beginning of the next end step.
	// Partial: "blocked this turn" is checked as "is blocking" (the game doesn't remember blocks)
	AddEnterTargetTrigger(this, &CVizierOfDefermentCard::BeforeExile, true, false, Characteristic::Positive);
}

bool CVizierOfDefermentCard::BeforeExile(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield ||
		(!pCreature->AttackedThisTurn() && !pCreature->IsBlocking()))
		return false;

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pExile.ApplyTo(pCreature);
	if (pCreature->GetZoneId() != ZoneId::Exile || pCreature->GetCardType().IsToken())
		return false;

	// Return it at the beginning of the next end step (as Saheeli Rai's exile in Kaladesh, from the exile)
	CScheduledCardModifier pReturn = CScheduledCardModifier(GetGame(),
		new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others),
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pReturn.ApplyTo(pCreature);
	return false;
}

CWingedShepherdCard::CWingedShepherdCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Winged Shepherd"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("5") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Cycling {W}
	AddCycling(this, WHITE_MANA_TEXT);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (green creatures)

// "When this creature enters, <effect on target creature you control>" (required; the callback does everything and
// returns false)
template <class T>
static void AddEnterOwnCreatureTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// Puts nCount -1/-1 counters on the target of the action (a creature on the battlefield)
static bool PutMinusCountersOnTarget(CAbilityAction* pAction, int nCount)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), nCount);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

// Search pPlayer's library for up to nMax basic land cards, put them onto the battlefield tapped, then shuffle
// (as Harvest Season)
static void SearchBasicLandsTapped(CGame* pGame, CPlayer* pPlayer, int nMax)
{
	CCountedCardContainer lands;
	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &lands);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nMax), // up to N basic land cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("basic lands")), // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < lands.GetSize(); ++i)
		if (lands.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pTapModifier.ApplyTo(lands.GetAt(i));

	pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

//____________________________________________________________________________
//
// Green creatures

CBitterbladeWarriorCard::CBitterbladeWarriorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bitterblade Warrior"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, it gets +1/+0 and gains deathtouch until end of turn.
	m_Exert.AddExertAbility(_T("it gets +1/+0 and gains deathtouch until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CBitterbladeWarriorCard::BeforeExert));
}

bool CBitterbladeWarriorCard::BeforeExert(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(this, +1, +0);
	CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Deathtouch, TRUE);
	pModifier.ApplyTo(this);
	return true;
}

CChampionOfRhonasCard::CChampionOfRhonasCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Champion of Rhonas"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, you may put a creature card from your hand onto the
	// battlefield.
	m_Exert.AddExertAbility(_T("you may put a creature card from your hand onto the battlefield."),
		CAbility::ResolutionStartedCallback(this, &CChampionOfRhonasCard::BeforeExert));
}

bool CChampionOfRhonasCard::BeforeExert(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (CCardFilter::GetFilter(_T("creatures"))->CountIncluded(pController->GetZoneById(ZoneId::Hand)->GetCardContainer()) == 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a creature card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("creatures")), // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);
	return true;
}

CChannelerInitiateCard::CChannelerInitiateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Channeler Initiate"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, put three -1/-1 counters on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CChannelerInitiateCard::BeforeCounters);

	// {T}, Remove a -1/-1 counter from this creature: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(_T("-1/-1")), -1);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CChannelerInitiateCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 3);
}

CColossapedeCard::CColossapedeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Colossapede"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("4") GREEN_MANA_TEXT, Power(5), Life(5))
{
}

CCrocodileOfTheCrossingCard::CCrocodileOfTheCrossingCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Crocodile of the Crossing"), CardType::Creature, CREATURE_TYPE(Crocodile), nID,
		_T("3") GREEN_MANA_TEXT, Power(5), Life(4))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, put a -1/-1 counter on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CCrocodileOfTheCrossingCard::BeforeCounters);
}

bool CCrocodileOfTheCrossingCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

CDefiantGreatmawCard::CDefiantGreatmawCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Defiant Greatmaw"), CardType::Creature, CREATURE_TYPE(Hippo), nID,
		_T("2") GREEN_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, put two -1/-1 counters on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CDefiantGreatmawCard::BeforeCounters);

	// Whenever you put one or more -1/-1 counters on this creature, remove a -1/-1 counter from another target creature
	// you control.
	// Not implemented: there is no event for "you put counters on a creature"
}

bool CDefiantGreatmawCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 2);
}

CExemplarOfStrengthCard::CExemplarOfStrengthCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Exemplar of Strength"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, put three -1/-1 counters on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CExemplarOfStrengthCard::BeforeCounters);

	// Whenever this creature attacks, remove a -1/-1 counter from it. If you do, you gain 1 life.
	AddAttackTrigger(this, &CExemplarOfStrengthCard::BeforeRemove);
}

bool CExemplarOfStrengthCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 3);
}

bool CExemplarOfStrengthCard::BeforeRemove(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || CountCounters(this, _T("-1/-1")) == 0)
		return true;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), -1);
	pModifier.ApplyTo(this);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CGreaterSandwurmCard::CGreaterSandwurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Greater Sandwurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(7))
	, m_CanBlockFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 2 or less. (as Elegant Edgecrafters in Kaladesh)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_CanBlockFilter);

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CHonoredHydraCard::CHonoredHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Honored Hydra"), CardType::Creature, CREATURE_TYPE2(Snake, Hydra), nID,
		_T("5") GREEN_MANA_TEXT, Power(6), Life(6))
	, m_Embalm(this)
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Embalm {3}{G}
	m_Embalm.AddEmbalmAbility(_T("3") GREEN_MANA_TEXT);
}

CHoodedBrawlerCard::CHoodedBrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hooded Brawler"), CardType::Creature, CREATURE_TYPE2(Snake, Warrior), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, it gets +2/+2 until end of turn.
	m_Exert.AddExertAbility(_T("it gets +2/+2 until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CHoodedBrawlerCard::BeforeExert));
}

bool CHoodedBrawlerCard::BeforeExert(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +2);
	return true;
}

CInitiatesCompanionCard::CInitiatesCompanionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Initiate's Companion"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") GREEN_MANA_TEXT, Power(3), Life(1))
{
	// Whenever this creature deals combat damage to a player, untap target creature or land.
	// (as Longtusk Cub in Kaladesh)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
								 CWhenSelfDamageDealt::PlayerEventCallback,
								 &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature | CardType::_Land, false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInitiatesCompanionCard::BeforeUntap));
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

bool CInitiatesCompanionCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CManglehornCard::CManglehornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Manglehorn"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// When this creature enters, you may destroy target artifact.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CManglehornCard::BeforeDestroy));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Artifacts your opponents control enter tapped. (as Kismet)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::InPlayTapped,
				(int)CCardFilter::GetFilter(_T("artifacts")),
				TRUE));
		cpAbility->SetAffectOpponentsOnly();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CManglehornCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CNagaVitalistCard::CNagaVitalistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Naga Vitalist"), CardType::Creature, CREATURE_TYPE2(Snake, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(2))
{
	// {T}: Add one mana of any type that a land you control could produce.
	// Partial: one mana of any color
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

COashraCultivatorCard::COashraCultivatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oashra Cultivator"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		GREEN_MANA_TEXT, Power(0), Life(3))
{
	// {2}{G}, {T}, Sacrifice this creature: Search your library for a basic land card, put it onto the battlefield
	// tapped, then shuffle.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") GREEN_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COashraCultivatorCard::BeforeSearch));
	cpAbility->SetAbilityText(_T("Search your library for a basic land card, put it onto the battlefield tapped. Activates"));
	AddAbility(cpAbility.GetPointer());
}

bool COashraCultivatorCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchBasicLandsTapped(GetGame(), pAction->GetController(), 1);
	return true;
}

COrneryKuduCard::COrneryKuduCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ornery Kudu"), CardType::Creature, CREATURE_TYPE(Antelope), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, put a -1/-1 counter on target creature you control.
	AddEnterOwnCreatureTrigger(this, &COrneryKuduCard::BeforeCounters);
}

bool COrneryKuduCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

CPouncingCheetahCard::CPouncingCheetahCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pouncing Cheetah"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);
}

CProwlingSerpopardCard::CProwlingSerpopardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prowling Serpopard"), CardType::Creature, CREATURE_TYPE2(Cat, Snake), nID,
		_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(3))
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Creature spells you control can't be countered. (as Gaea's Herald)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::SpellsCantBeCountered,
			reinterpret_cast<int>(CCardFilter::GetFilter(_T("creatures")))));
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());
}

CRhonasTheIndomitableCard::CRhonasTheIndomitableCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rhonas the Indomitable"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("2") GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Deathtouch, indestructible
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddIndestructible(FALSE);

	{
		// Rhonas can't attack or block unless you control another creature with power 4 or greater.
		// (as Oketra the True)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetConditionFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetConditionFilter().AddComparer(new CreaturePowerComparer<std::greater_equal<int>>(4));
		cpAbility->SetConditionCheckZone(ZoneId::Battlefield);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(0);
		cpAbility->SetConditionIsMaximum();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{G}: Another target creature gets +2/+0 and gains trample until end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRhonasTheIndomitableCard::BeforePump));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRhonasTheIndomitableCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +2, +0, CreatureKeyword::Trample);
	return true;
}

CScaledBehemothCard::CScaledBehemothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scaled Behemoth"), CardType::Creature, CREATURE_TYPE(Crocodile), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(7))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);
}

CShefetMonitorCard::CShefetMonitorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shefet Monitor"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		_T("5") GREEN_MANA_TEXT, Power(6), Life(5))
	, m_LandFilter(_T("a basic land card or a Desert card"), _T("basic land cards or Desert cards"),
		new CardTypeComparer(CardType::BasicLand | CardType::Desert, false))
{
	// Cycling {3}{G}
	AddCycling(this, _T("3") GREEN_MANA_TEXT);

	{
		// When you cycle this card, you may search your library for a basic land card or a Desert card, put it onto
		// the battlefield, then shuffle. (as Onslaught's landcyclers)
		typedef
			TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenThisCardCycled > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
		cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::BasicLand | CardType::Desert, false));
		cpAbility->SetToZone(ZoneId::Battlefield);
		AddAbility(cpAbility.GetPointer());
	}
}

CWatchfulNagaCard::CWatchfulNagaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Watchful Naga"), CardType::Creature, CREATURE_TYPE2(Snake, Wizard), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, draw a card.
	m_Exert.AddExertAbility(_T("draw a card."),
		CAbility::ResolutionStartedCallback(this, &CWatchfulNagaCard::BeforeExert));
}

bool CWatchfulNagaCard::BeforeExert(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (red creatures)

// Prowess (as Eldritch Moon)
static void AddProwess(CCreatureCard* pCard)
{
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever you exert a creature, <effect>" (listens to EXERT_TRIGGER_ID, as Flamespeaker Adept with Scry in Theros)
template <class T>
static void AddWheneverYouExertTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetTriggerIndex(EXERT_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(pCard));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);
	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "You may exert this creature as it attacks. When you do, <effect on target creature>": an optional attack trigger
// with a target; the callback exerts the creature (CExertSupport::Exert), does the effect and returns false
template <class T>
static CTargeting* AddExertTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), LPCTSTR strText)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	cpAbility->SetAbilityText(strText);
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

// pSource deals nDamage damage to each opponent of pPlayer
static void DamageEachOpponent(CCard* pSource, CPlayer* pPlayer, int nDamage)
{
	CGame* pGame = pSource->GetGame();
	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		if (pGame->GetPlayer(ip) != pPlayer)
			pModifier.ApplyTo(pGame->GetPlayer(ip));
}

//____________________________________________________________________________
//
// Red creatures

CAhnCropCrasherCard::CAhnCropCrasherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ahn-Crop Crasher"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// You may exert this creature as it attacks. When you do, target creature can't block this turn.
	AddExertTargetTrigger(this, &CAhnCropCrasherCard::BeforeExertCantBlock,
		_T("Exert: target creature can't block this turn."));
}

bool CAhnCropCrasherCard::BeforeExertCantBlock(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return false;
}

CBattlefieldScavengerCard::CBattlefieldScavengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Battlefield Scavenger"), CardType::Creature, CREATURE_TYPE2(Jackal, Rogue), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks.
	m_Exert.AddExertAbility(_T("no other effect."));

	// Whenever you exert a creature, you may discard a card. If you do, draw a card.
	AddWheneverYouExertTrigger(this, &CBattlefieldScavengerCard::BeforeLoot, true);
}

bool CBattlefieldScavengerCard::BeforeLoot(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (pController->GetZoneById(ZoneId::Hand)->GetSize() == 0)
		return true;

	DiscardCards(GetGame(), pController, 1);
	DrawCards(GetGame(), pController, 1);
	return true;
}

CBloodlustInciterCard::CBloodlustInciterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodlust Inciter"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// {T}: Target creature gains haste until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBloodlustInciterCard::BeforeHaste));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CBloodlustInciterCard::BeforeHaste(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +0, +0, CreatureKeyword::Haste);
	return true;
}

CBloodrageBrawlerCard::CBloodrageBrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodrage Brawler"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(4), Life(3))
{
	// When this creature enters, discard a card.
	AddEnterTrigger(this, &CBloodrageBrawlerCard::BeforeDiscard);
}

bool CBloodrageBrawlerCard::BeforeDiscard(CAbilityAction* pAction)
{
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CDesertCerodonCard::CDesertCerodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Desert Cerodon"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("5") RED_MANA_TEXT, Power(6), Life(4))
{
	// Cycling {R}
	AddCycling(this, RED_MANA_TEXT);
}

CEmberhornMinotaurCard::CEmberhornMinotaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emberhorn Minotaur"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(3))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, it gets +1/+1 and gains menace until end of turn.
	m_Exert.AddExertAbility(_T("it gets +1/+1 and gains menace until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CEmberhornMinotaurCard::BeforeExert));
}

bool CEmberhornMinotaurCard::BeforeExert(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1, CreatureKeyword::CantBeBlockedBy1);
	return true;
}

CFlamebladeAdeptCard::CFlamebladeAdeptCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Flameblade Adept"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		RED_MANA_TEXT, Power(1), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Whenever you cycle or discard a card, this creature gets +1/+0 until end of turn. (cycling discards the card)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFlamebladeAdeptCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CFlamebladeAdeptCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +0);
	return true;
}

CGlorybringerCard::CGlorybringerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Glorybringer"), CardType::Creature, CREATURE_TYPE(Dragon), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// You may exert this creature as it attacks. When you do, it deals 4 damage to target non-Dragon creature an
	// opponent controls.
	CTargeting* pTargeting = AddExertTargetTrigger(this, &CGlorybringerCard::BeforeExertDamage,
		_T("Exert: Glorybringer deals 4 damage to target non-Dragon creature an opponent controls."));
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Dragon), false)));
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CGlorybringerCard::BeforeExertDamage(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);
	DealDamageToCreature(this, pAction->GetAssociatedCard(), 4);
	return false;
}

CHazoretTheFerventCard::CHazoretTheFerventCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hazoret the Fervent"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("3") RED_MANA_TEXT, Power(5), Life(4))
{
	// Indestructible, haste
	GetCardKeyword()->AddIndestructible(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	{
		// Hazoret can't attack or block unless you have one or fewer cards in hand.
		// (it can't while you have two or more cards in hand, as Oketra the True)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new TrueCardComparer);
		cpAbility->SetConditionCheckZone(ZoneId::Hand);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(2);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{R}, Discard a card: Hazoret deals 2 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") RED_MANA_TEXT));

		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHazoretTheFerventCard::BeforeDamage));
		cpAbility->SetAbilityText(_T("Hazoret deals 2 damage to each opponent. Activates"));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHazoretTheFerventCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 2);
	return true;
}

CHeartPiercerManticoreCard::CHeartPiercerManticoreCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Heart-Piercer Manticore"), CardType::Creature, CREATURE_TYPE(Manticore), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CHeartPiercerManticoreCard::OnCreatureSelected))
	, m_Embalm(this)
{
	{
		// When this creature enters, you may sacrifice another creature. When you do, this creature deals damage equal
		// to that creature's power to any target.
		// (the target is chosen when the ability triggers; no planeswalkers)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeartPiercerManticoreCard::BeforeSacrifice));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}

	// Embalm {5}{R}
	m_Embalm.AddEmbalmAbility(_T("5") RED_MANA_TEXT);
}

bool CHeartPiercerManticoreCard::BeforeSacrifice(CAbilityAction* pAction)
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
		entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	// dwContext1: the target card, dwContext2: the target player
	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController(),
			(DWORD)pAction->GetAssociatedCard(), (DWORD)pAction->GetAssociatedPlayer());
	return false;
}

void CHeartPiercerManticoreCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCreatureCard* pSacrificed = (CCreatureCard*)it->dwContext;
			if (pSacrificed->GetZoneId() != ZoneId::Battlefield)
				return;

			int nPower = GET_INTEGER(pSacrificed->GetPower());
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo(pSacrificed);

			CCard* pTargetCard = (CCard*)dwContext1;
			CPlayer* pTargetPlayer = (CPlayer*)dwContext2;
			if (pTargetCard)
				DealDamageToCreature(this, pTargetCard, nPower);
			else if (pTargetPlayer && nPower > 0)
			{
				CLifeModifier pDamage = CLifeModifier(Life(-nPower), this, PreventableType::Preventable,
					DamageType::AbilityDamage | DamageType::NonCombatDamage);
				pDamage.ApplyTo(pTargetPlayer);
			}
			return;
		}
}

CHyenaPackCard::CHyenaPackCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hyena Pack"), CardType::Creature, CREATURE_TYPE(Hyena), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(4))
{
}

CManticoreOfTheGauntletCard::CManticoreOfTheGauntletCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Manticore of the Gauntlet"), CardType::Creature, CREATURE_TYPE(Manticore), nID,
		_T("4") RED_MANA_TEXT, Power(5), Life(4))
{
	// When this creature enters, put a -1/-1 counter on target creature you control. This creature deals 3 damage to
	// target opponent or planeswalker.
	// (the opponent isn't targeted: it's always the next player; no planeswalkers)
	AddEnterOwnCreatureTrigger(this, &CManticoreOfTheGauntletCard::BeforeCounterAndDamage);
}

bool CManticoreOfTheGauntletCard::BeforeCounterAndDamage(CAbilityAction* pAction)
{
	PutMinusCountersOnTarget(pAction, 1);
	DamageEachOpponent(this, pAction->GetController(), 3);
	return false;
}

CMinotaurSureshotCard::CMinotaurSureshotCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Minotaur Sureshot"), CardType::Creature, CREATURE_TYPE2(Minotaur, Archer), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// {1}{R}: This creature gets +1/+0 until end of turn. (as Lunarch Mantle's ability in Eldritch Moon)
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("1") RED_MANA_TEXT, Power(+1), Life(+0), CreatureKeyword::Null));
	AddAbility(cpAbility.GetPointer());
}

CNefCropEntanglerCard::CNefCropEntanglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nef-Crop Entangler"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
	, m_Exert(this)
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// You may exert this creature as it attacks. When you do, it gets +1/+2 until end of turn.
	m_Exert.AddExertAbility(_T("it gets +1/+2 until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CNefCropEntanglerCard::BeforeExert));
}

bool CNefCropEntanglerCard::BeforeExert(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +2);
	return true;
}

CNimbleBladeKhenraCard::CNimbleBladeKhenraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nimble-Blade Khenra"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// Prowess
	AddProwess(this);
}

CPathmakerInitiateCard::CPathmakerInitiateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pathmaker Initiate"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// {T}: Target creature with power 2 or less can't be blocked this turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreaturePowerComparer<std::less_equal<int>>(2));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPathmakerInitiateCard::BeforeUnblockable));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CPathmakerInitiateCard::BeforeUnblockable(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +0, +0, CreatureKeyword::Unblockable);
	return true;
}

CSoulScarMageCard::CSoulScarMageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Soul-Scar Mage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		RED_MANA_TEXT, Power(1), Life(2))
{
	// Prowess
	AddProwess(this);

	// If a source you control would deal noncombat damage to a creature an opponent controls, put that many -1/-1
	// counters on that creature instead.
	// Not implemented: there are no damage replacement effects
}

CThresherLizardCard::CThresherLizardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thresher Lizard"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// This creature gets +1/+2 as long as you have one or fewer cards in hand.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+2)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new TrueCardComparer);
	cpAbility->SetConditionCheckZone(ZoneId::Hand);
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	cpAbility->SetConditionIsMaximum();
	AddAbility(cpAbility.GetPointer());
}

CTrueheartTwinsCard::CTrueheartTwinsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trueheart Twins"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(4))
	, m_Exert(this)
{
	// You may exert this creature as it attacks.
	m_Exert.AddExertAbility(_T("no other effect."));

	// Whenever you exert a creature, creatures you control get +1/+0 until end of turn.
	AddWheneverYouExertTrigger(this, &CTrueheartTwinsCard::BeforePump, false);
}

bool CTrueheartTwinsCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +1, +0);
	return true;
}

CWarfireJavelineerCard::CWarfireJavelineerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Warfire Javelineer"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, it deals X damage to target creature an opponent controls, where X is the number of
	// instant and sorcery cards in your graveyard.
	AddEnterTargetTrigger(this, &CWarfireJavelineerCard::BeforeDamage, false, true, Characteristic::Negative);
}

bool CWarfireJavelineerCard::BeforeDamage(CAbilityAction* pAction)
{
	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nCount = 0;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if ((pGraveyard->GetAt(i)->GetCardType() & (CardType::Instant | CardType::Sorcery)).Any())
			++nCount;

	DealDamageToCreature(this, pAction->GetAssociatedCard(), nCount);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (black creatures)

// "When this creature dies, <effect>" (as Aether Revolt)
template <class T>
static void AddDiesTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(bOptional ? TriggeredAbility::OptionalType::Optional : TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "When this creature dies, you may <effect on target creature>" (the callback does everything and returns false)
template <class T>
static void AddDiesTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever you cycle or discard a card, <effect>" (no payment; cycling discards the card)
template <class T>
static void AddDiscardTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// The controller controls a planeswalker of the type
static BOOL ControlsPlaneswalkerType(CCard* pCard, PlaneswalkerType type)
{
	CZone* pBattlefield = pCard->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CPlaneswalkerCard* pWalker = dynamic_cast<CPlaneswalkerCard*>(pBattlefield->GetAt(i));
		if (pWalker && pWalker->GetSubtype() == type)
			return TRUE;
	}
	return FALSE;
}

//____________________________________________________________________________
//
// Black creatures

CArchfiendOfIfnirCard::CArchfiendOfIfnirCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Archfiend of Ifnir"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(4))
{
	// Whenever you cycle or discard another card, put a -1/-1 counter on each creature your opponents control.
	// (it only triggers while on the battlefield, so the card itself is never the discarded one)
	AddDiscardTrigger(this, &CArchfiendOfIfnirCard::BeforeCounters);

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CArchfiendOfIfnirCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CBalefulAmmitCard::CBalefulAmmitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Baleful Ammit"), CardType::Creature, CREATURE_TYPE2(Crocodile, Demon), nID,
		_T("2") BLACK_MANA_TEXT, Power(4), Life(3))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, put a -1/-1 counter on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CBalefulAmmitCard::BeforeCounters);
}

bool CBalefulAmmitCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

CBlightedBatCard::CBlightedBatCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Blighted Bat"), CardType::Creature, CREATURE_TYPE2(Zombie, Bat), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// {1}: This creature gains haste until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("1"), Power(+0), Life(+0), CreatureKeyword::Haste));
	AddAbility(cpAbility.GetPointer());
}

CBonePickerCard::CBonePickerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bone Picker"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Flying, deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// This spell costs {3} less to cast if a creature died this turn.
	// (a second spell for {B}, as the Surge spells in Oath of the Gatewatch)
	counted_ptr<CSpell> cpCheapSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), BLACK_MANA_TEXT, TRUE));
	cpCheapSpell->SetMainSpell(FALSE);
	AddPlayableIf(this, cpCheapSpell.GetPointer(), &CBonePickerCard::CreatureDiedThisTurn);
	AddSpell(cpCheapSpell.GetPointer());
}

BOOL CBonePickerCard::CreatureDiedThisTurn(BOOL bIncludeTricks)
{
	// (as Morbid in Innistrad)
	return GetGame()->GetCertainTypeDiedCount(CardType::Creature) > 0;
}

CBontuTheGlorifiedCard::CBontuTheGlorifiedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bontu the Glorified"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("2") BLACK_MANA_TEXT, Power(4), Life(6))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"), new AnyCreatureComparer)
{
	m_OtherCreatureFilter.AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));

	// Menace, indestructible
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
	GetCardKeyword()->AddIndestructible(FALSE);

	// Bontu can't attack or block unless a creature died under your control this turn.
	// (it can't attack or block; when a creature you control dies, or as it enters if one died this turn, it loses
	// that until end of turn)
	GetCreatureKeyword()->AddCantAttack(FALSE);
	GetCreatureKeyword()->AddCantBlock(FALSE);
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBontuTheGlorifiedCard::BeforeAllowAttack));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBontuTheGlorifiedCard::SetEnterContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBontuTheGlorifiedCard::BeforeAllowAttack));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}, Sacrifice another creature: Scry 1. Each opponent loses 1 life and you gain 1 life.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") BLACK_MANA_TEXT));

		cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBontuTheGlorifiedCard::BeforeDrain));
		cpAbility->SetAbilityText(_T("Scry 1. Each opponent loses 1 life and you gain 1 life. Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBontuTheGlorifiedCard::SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetController()->GetCertainTypeDiedCount(CardType::Creature) > 0;
}

bool CBontuTheGlorifiedCard::BeforeAllowAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToRemove(CreatureKeyword::CantAttack | CreatureKeyword::CantBlock);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(this);
	return true;
}

bool CBontuTheGlorifiedCard::BeforeDrain(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	EachOpponentLosesLife(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CCursedMinotaurCard::CCursedMinotaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cursed Minotaur"), CardType::Creature, CREATURE_TYPE2(Zombie, Minotaur), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CDesiccatedNagaCard::CDesiccatedNagaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Desiccated Naga"), CardType::Creature, CREATURE_TYPE2(Zombie, Snake), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// {3}{B}: Target opponent loses 2 life and you gain 2 life. Activate only if you control a Liliana planeswalker.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("3") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDesiccatedNagaCard::BeforeDrain));
	AddPlayableIf(this, cpAbility.GetPointer(), &CDesiccatedNagaCard::ControlsLiliana);
	AddAbility(cpAbility.GetPointer());
}

BOOL CDesiccatedNagaCard::ControlsLiliana(BOOL bIncludeTricks)
{
	return ControlsPlaneswalkerType(this, PlaneswalkerType::Liliana);
}

bool CDesiccatedNagaCard::BeforeDrain(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (pOpponent)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CDoomedDissenterCard::CDoomedDissenterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Doomed Dissenter"), CardType::Creature, CREATURE_TYPE(Human), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature dies, create a 2/2 black Zombie creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID, 1));
	AddAbility(cpAbility.GetPointer());
}

CDreadWandererCard::CDreadWandererCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dread Wanderer"), CardType::Creature, CREATURE_TYPE2(Zombie, Jackal), nID,
		BLACK_MANA_TEXT, Power(2), Life(1))
{
	// This creature enters tapped.
	SetIntoPlayTapped();

	// {2}{B}: Return this card from your graveyard to the battlefield. Activate only as a sorcery and only if you have
	// one or fewer cards in hand. (as Advanced Stitchwing in Eldritch Moon)
	counted_ptr<CSelfMoveCardAbility> cpAbility(
		::CreateObject<CSelfMoveCardAbility>(this,
			_T("2") BLACK_MANA_TEXT,
			ZoneId::Battlefield, FALSE, MoveType::Others));

	cpAbility->SetGraveyardOnly();
	SetAsSorcery(cpAbility.GetPointer());
	AddPlayableIf(this, cpAbility.GetPointer(), &CDreadWandererCard::OneOrFewerCardsInHand);
	AddAbility(cpAbility.GetPointer());
}

BOOL CDreadWandererCard::OneOrFewerCardsInHand(BOOL bIncludeTricks)
{
	return GetController()->GetZoneById(ZoneId::Hand)->GetSize() <= 1;
}

CDuneBeetleCard::CDuneBeetleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dune Beetle"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(4))
{
}

CFesteringMummyCard::CFesteringMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Festering Mummy"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature dies, you may put a -1/-1 counter on target creature.
	AddDiesTargetTrigger(this, &CFesteringMummyCard::BeforeCounter);
}

bool CFesteringMummyCard::BeforeCounter(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

CGrimStriderCard::CGrimStriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grim Strider"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		_T("3") BLACK_MANA_TEXT, Power(6), Life(6))
{
	// This creature gets -1/-1 for each card in your hand. (as Dread Slag in Dissension)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Hand,
			new TrueCardComparer));

	cpAbility->SetPowerMultiplier(Power(-1));
	cpAbility->SetToughnessMultiplier(Life(-1));
	AddAbility(cpAbility.GetPointer());
}

CHorrorOfTheBrokenLandsCard::CHorrorOfTheBrokenLandsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Horror of the Broken Lands"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		_T("4") BLACK_MANA_TEXT, Power(4), Life(4))
{
	// Whenever you cycle or discard another card, this creature gets +2/+1 until end of turn.
	AddDiscardTrigger(this, &CHorrorOfTheBrokenLandsCard::BeforePump);

	// Cycling {B}
	AddCycling(this, BLACK_MANA_TEXT);
}

bool CHorrorOfTheBrokenLandsCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +1);
	return true;
}

CLordOfTheAccursedCard::CLordOfTheAccursedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lord of the Accursed"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	{
		// Other Zombies you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new OtherCreatureTypeComparer(this, SingleCreatureType::Zombie),
				Power(+1), Life(+1)));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}, {T}: All Zombies gain menace until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") BLACK_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLordOfTheAccursedCard::BeforeMenace));
		cpAbility->SetAbilityText(_T("All Zombies gain menace until end of turn. Activates"));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLordOfTheAccursedCard::BeforeMenace(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (((CCreatureCard*)creatures.GetAt(i))->GetCreatureType().HasType(SingleCreatureType::Zombie))
			PumpCreature(creatures.GetAt(i), +0, +0, CreatureKeyword::CantBeBlockedBy1);
	return true;
}

CMiasmicMummyCard::CMiasmicMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Miasmic Mummy"), CardType::Creature, CREATURE_TYPE2(Zombie, Jackal), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, each player discards a card.
	AddEnterTrigger(this, &CMiasmicMummyCard::BeforeDiscard);
}

bool CMiasmicMummyCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

CPitilessVizierCard::CPitilessVizierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pitiless Vizier"), CardType::Creature, CREATURE_TYPE2(Minotaur, Cleric), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// Whenever you cycle or discard a card, this creature gains indestructible until end of turn.
	AddDiscardTrigger(this, &CPitilessVizierCard::BeforeIndestructible);
}

bool CPitilessVizierCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Indestructible, TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CPlagueBelcherCard::CPlagueBelcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Plague Belcher"), CardType::Creature, CREATURE_TYPE2(Zombie, Beast), nID,
		_T("2") BLACK_MANA_TEXT, Power(5), Life(4))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When this creature enters, put two -1/-1 counters on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CPlagueBelcherCard::BeforeCounters);

	{
		// Whenever another Zombie you control dies, each opponent loses 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new OtherCreatureTypeComparer(this, SingleCreatureType::Zombie));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPlagueBelcherCard::BeforeLoseLife));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPlagueBelcherCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 2);
}

bool CPlagueBelcherCard::BeforeLoseLife(CAbilityAction* pAction)
{
	EachOpponentLosesLife(this, pAction->GetController(), 1);
	return true;
}

CRuthlessSniperCard::CRuthlessSniperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ruthless Sniper"), CardType::Creature, CREATURE_TYPE2(Human, Archer), nID,
		BLACK_MANA_TEXT, Power(1), Life(2))
{
	// Whenever you cycle or discard a card, you may pay {1}. If you do, put a -1/-1 counter on target creature.
	// (the payment is a resolution cost, as Drake Haven)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionCost(_T("1"));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRuthlessSniperCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CRuthlessSniperCard::BeforeCounter(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

CSoulstingerCard::CSoulstingerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Soulstinger"), CardType::Creature, CREATURE_TYPE2(Scorpion, Demon), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, put two -1/-1 counters on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CSoulstingerCard::BeforeCounters);

	// When this creature dies, you may put a -1/-1 counter on target creature for each -1/-1 counter on this creature.
	// (the counters it had when it left the battlefield)
	AddDiesTargetTrigger(this, &CSoulstingerCard::BeforeMoveCounters);
}

bool CSoulstingerCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 2);
}

bool CSoulstingerCard::BeforeMoveCounters(CAbilityAction* pAction)
{
	int nCounters = GetLastKnownm11Counters();
	if (nCounters > 0)
		PutMinusCountersOnTarget(pAction, nCounters);
	return false;
}

CTatteredMummyCard::CTatteredMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tattered Mummy"), CardType::Creature, CREATURE_TYPE2(Zombie, Jackal), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
{
	// When this creature dies, each opponent loses 2 life.
	AddDiesTrigger(this, &CTatteredMummyCard::BeforeLoseLife, false);
}

bool CTatteredMummyCard::BeforeLoseLife(CAbilityAction* pAction)
{
	EachOpponentLosesLife(this, pAction->GetController(), 2);
	return true;
}

CWastelandScorpionCard::CWastelandScorpionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wasteland Scorpion"), CardType::Creature, CREATURE_TYPE(Scorpion), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Cycling {2}
	AddCycling(this, _T("2"));
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (blue creatures)

// Untaps the target permanent of the action (returns false: the callback does everything)
static bool UntapTarget(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
// Blue creatures

CAnglerDrakeCard::CAnglerDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angler Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you may return target creature to its owner's hand.
	AddEnterTargetTrigger(this, &CAnglerDrakeCard::BeforeBounce, true, false, Characteristic::Negative);
}

bool CAnglerDrakeCard::BeforeBounce(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CAvenInitiateCard::CAvenInitiateCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Initiate"), CardType::Creature, CREATURE_TYPE2(Bird, Warrior), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(2))
	, m_Embalm(this)
{
	// Embalm {6}{U}
	m_Embalm.AddEmbalmAbility(_T("6") BLUE_MANA_TEXT);
}

CCrypticSerpentCard::CCrypticSerpentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cryptic Serpent"), CardType::Creature, CREATURE_TYPE(Serpent), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(6), Life(5))
{
	// This spell costs {1} less to cast for each instant and sorcery card in your graveyard.
	// (one cheaper spell for each count, as Bone Picker)
	LPCTSTR costs[] = {
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, _T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, BLUE_MANA_TEXT BLUE_MANA_TEXT };
	BOOL (CCrypticSerpentCard::*conditions[])(BOOL) = {
		&CCrypticSerpentCard::HasOne, &CCrypticSerpentCard::HasTwo, &CCrypticSerpentCard::HasThree,
		&CCrypticSerpentCard::HasFour, &CCrypticSerpentCard::HasFive };

	for (int i = 0; i < _countof(costs); ++i)
	{
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), costs[i], TRUE));
		cpSpell->SetMainSpell(FALSE);
		AddPlayableIf(this, cpSpell.GetPointer(), conditions[i]);
		AddSpell(cpSpell.GetPointer());
	}
}

int CCrypticSerpentCard::CountInstantsAndSorceries() const
{
	const CZone* pGraveyard = GetController()->GetZoneById(ZoneId::Graveyard);
	int nCount = 0;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if ((pGraveyard->GetAt(i)->GetCardType() & (CardType::Instant | CardType::Sorcery)).Any())
			++nCount;
	return nCount;
}

CCuratorOfMysteriesCard::CCuratorOfMysteriesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Curator of Mysteries"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
{
	// Whenever you cycle or discard another card, scry 1.
	AddDiscardTrigger(this, &CCuratorOfMysteriesCard::BeforeScry);

	// Cycling {U}
	AddCycling(this, BLUE_MANA_TEXT);
}

bool CCuratorOfMysteriesCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CGlyphKeeperCard::CGlyphKeeperCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Glyph Keeper"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(3))
	, m_Embalm(this)
{
	// Whenever this creature becomes the target of a spell or ability for the first time each turn, counter that
	// spell or ability.
	// Not implemented: abilities can't be countered

	// Embalm {5}{U}{U}
	m_Embalm.AddEmbalmAbility(_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT);
}

CHekmaSentinelsCard::CHekmaSentinelsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hekma Sentinels"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cycle or discard a card, this creature gets +1/+1 until end of turn.
	AddDiscardTrigger(this, &CHekmaSentinelsCard::BeforePump);
}

bool CHekmaSentinelsCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

CKefnetTheMindfulCard::CKefnetTheMindfulCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kefnet the Mindful"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("2") BLUE_MANA_TEXT, Power(5), Life(5))
	, m_LandSelection(pGame, CSelectionSupport::SelectionCallback(this, &CKefnetTheMindfulCard::OnLandSelected))
{
	// Flying, indestructible
	GetCardKeyword()->AddIndestructible(FALSE);

	{
		// Kefnet can't attack or block unless you have seven or more cards in hand.
		// (it can't while you have six or fewer cards in hand, as Oketra the True)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new TrueCardComparer);
		cpAbility->SetConditionCheckZone(ZoneId::Hand);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(6);
		cpAbility->SetConditionIsMaximum();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{U}: Draw a card, then you may return a land you control to its owner's hand.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("3") BLUE_MANA_TEXT));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKefnetTheMindfulCard::BeforeDraw));
		cpAbility->SetAbilityText(_T("Draw a card, then you may return a land you control to its owner's hand. Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CKefnetTheMindfulCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 1);

	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Return %s to your hand"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_LandSelection.AddSelectionRequest(entries, 0, 1, this, pController);
	return true;
}

void CKefnetTheMindfulCard::OnLandSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Battlefield)
				return;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
			pModifier.ApplyTo(pCard);
			return;
		}
}

CLabyrinthGuardianCard::CLabyrinthGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Labyrinth Guardian"), CardType::Creature, CREATURE_TYPE2(Illusion, Warrior), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_Embalm(this)
{
	{
		// When this creature becomes the target of a spell, sacrifice it. (as Crystallization in Alara Reborn)
		// Partial: it also triggers when it becomes the target of an ability
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
							   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, FALSE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLabyrinthGuardianCard::BeforeSacrifice));
		AddAbility(cpAbility.GetPointer());
	}

	// Embalm {3}{U}
	m_Embalm.AddEmbalmAbility(_T("3") BLUE_MANA_TEXT);
}

bool CLabyrinthGuardianCard::BeforeSacrifice(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, GetController());
		pModifier.ApplyTo(this);
	}
	return true;
}

CNagaOracleCard::CNagaOracleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Naga Oracle"), CardType::Creature, CREATURE_TYPE2(Snake, Cleric), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, surveil 3.
	AddEnterTrigger(this, &CNagaOracleCard::BeforeSurveil);
}

bool CNagaOracleCard::BeforeSurveil(CAbilityAction* pAction)
{
	CSurveilModifier(GetGame(), 3, this).ApplyTo(pAction->GetController());
	return true;
}

CRiverSerpentCard::CRiverSerpentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("River Serpent"), CardType::Creature, CREATURE_TYPE(Serpent), nID,
		_T("5") BLUE_MANA_TEXT, Power(5), Life(5))
{
	{
		// This creature can't attack unless there are five or more cards in your graveyard.
		// (it can't while there are four or fewer, as Oketra the True)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+0), Life(+0), CreatureKeyword::CantAttack));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new TrueCardComparer);
		cpAbility->SetConditionCheckZone(ZoneId::Graveyard);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(4);
		cpAbility->SetConditionIsMaximum();
		AddAbility(cpAbility.GetPointer());
	}

	// Cycling {U}
	AddCycling(this, BLUE_MANA_TEXT);
}

CScribeOfTheMindfulCard::CScribeOfTheMindfulCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scribe of the Mindful"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// {1}, {T}, Sacrifice this creature: Return target instant or sorcery card from your graveyard to your hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("1"),
			new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CSeekerOfInsightCard::CSeekerOfInsightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Seeker of Insight"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// {T}: Draw a card, then discard a card. Activate only if you've cast a noncreature spell this turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSeekerOfInsightCard::BeforeLoot));
	cpAbility->SetAbilityText(_T("Draw a card, then discard a card. Activates"));
	AddPlayableIf(this, cpAbility.GetPointer(), &CSeekerOfInsightCard::CastNoncreatureSpell);
	AddAbility(cpAbility.GetPointer());
}

BOOL CSeekerOfInsightCard::CastNoncreatureSpell(BOOL bIncludeTricks)
{
	return GetController()->GetCertainAntiTypeCastedCount(CardType::Creature) > 0;
}

bool CSeekerOfInsightCard::BeforeLoot(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CShimmerscaleDrakeCard::CShimmerscaleDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shimmerscale Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(4))
{
	// Cycling {2}
	AddCycling(this, _T("2"));
}

CSlitherBladeCard::CSlitherBladeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Slither Blade"), CardType::Creature, CREATURE_TYPE2(Snake, Rogue), nID,
		BLUE_MANA_TEXT, Power(1), Life(2))
{
	// This creature can't be blocked.
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

CTahCropSkirmisherCard::CTahCropSkirmisherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tah-Crop Skirmisher"), CardType::Creature, CREATURE_TYPE2(Snake, Warrior), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
	, m_Embalm(this)
{
	// Embalm {3}{U}
	m_Embalm.AddEmbalmAbility(_T("3") BLUE_MANA_TEXT);
}

CVizierOfTumblingSandsCard::CVizierOfTumblingSandsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vizier of Tumbling Sands"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(3))
{
	{
		// {T}: Untap another target permanent.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::_Permanent, false), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
		AddAbility(cpAbility.GetPointer());
	}

	// Cycling {1}{U}
	AddCycling(this, _T("1") BLUE_MANA_TEXT);

	{
		// When you cycle this card, untap target permanent.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenThisCardCycled > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Permanent, false));
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVizierOfTumblingSandsCard::BeforeUntap));
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVizierOfTumblingSandsCard::BeforeUntap(CAbilityAction* pAction)
{
	return UntapTarget(pAction);
}

CZenithSeekerCard::CZenithSeekerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Zenith Seeker"), CardType::Creature, CREATURE_TYPE2(Bird, Wizard), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cycle or discard a card, target creature gains flying until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CZenithSeekerCard::BeforeFlying));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CZenithSeekerCard::BeforeFlying(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +0, +0, CreatureKeyword::Flying);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

CAhnCropChampionCard::CAhnCropChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ahn-Crop Champion"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, untap all other creatures you control.
	m_Exert.AddExertAbility(_T("untap all other creatures you control."),
		CAbility::ResolutionStartedCallback(this, &CAhnCropChampionCard::BeforeExert));
}

bool CAhnCropChampionCard::BeforeExert(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);

	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this && creatures.GetAt(i)->GetOrientation()->IsTapped())
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CAvenWindGuideCard::CAvenWindGuideCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Wind Guide"), CardType::Creature, CREATURE_TYPE2(Bird, Warrior), nID,
		_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
	, m_Embalm(this)
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	{
		// Creature tokens you control have flying and vigilance.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CardTypeComparer(CardType::Creature | CardType::Token, true),
				Power(+0), Life(+0), CreatureKeyword::Flying | CreatureKeyword::Vigilance));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// Embalm {4}{W}{U}
	m_Embalm.AddEmbalmAbility(_T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT);
}

CDecimatorBeetleCard::CDecimatorBeetleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Decimator Beetle"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(5))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDecimatorBeetleCard::OnCreatureSelected))
{
	// When this creature enters, put a -1/-1 counter on target creature you control.
	AddEnterOwnCreatureTrigger(this, &CDecimatorBeetleCard::BeforeCounters);

	{
		// Whenever this creature attacks, remove a -1/-1 counter from target creature you control and put a -1/-1
		// counter on up to one target creature defending player controls.
		// (the second creature is chosen on resolution, it isn't targeted)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
									 CWhenSelfAttackedBlocked::AttackEventCallback,
									 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDecimatorBeetleCard::BeforeMoveCounter));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDecimatorBeetleCard::BeforeCounters(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

bool CDecimatorBeetleCard::BeforeMoveCounter(CAbilityAction* pAction)
{
	CCard* pOwn = pAction->GetAssociatedCard();
	if (pOwn && pOwn->GetZoneId() == ZoneId::Battlefield && CountCounters(pOwn, _T("-1/-1")) > 0)
	{
		CCardCounterModifier pRemove = CCardCounterModifier(_T("-1/-1"), -1);
		pRemove.ApplyTo(pOwn);
	}

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put a -1/-1 counter on %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 0, 1, this, pAction->GetController());
	return false;
}

void CDecimatorBeetleCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
				pModifier.ApplyTo(pCard);
			}
			return;
		}
}

CEnigmaDrakeCard::CEnigmaDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Enigma Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(0), Life(4))
{
	// Enigma Drake's power is equal to the number of instant and sorcery cards in your graveyard.
	// (as Lord of Extinction in Alara Reborn)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Graveyard,
			new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)));

	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());
}

CHapatraVizierOfPoisonsCard::CHapatraVizierOfPoisonsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hapatra, Vizier of Poisons"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Cleric), nID,
		BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Whenever Hapatra deals combat damage to a player, you may put a -1/-1 counter on target creature.
	// (as Initiate's Companion)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
								 CWhenSelfDamageDealt::PlayerEventCallback,
								 &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHapatraVizierOfPoisonsCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());

	// Whenever you put one or more -1/-1 counters on a creature, create a 1/1 green Snake creature token with deathtouch.
	// Not implemented: there is no event for "you put counters on a creature"
}

bool CHapatraVizierOfPoisonsCard::BeforeCounter(CAbilityAction* pAction)
{
	return PutMinusCountersOnTarget(pAction, 1);
}

CHonoredCropCaptainCard::CHonoredCropCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Honored Crop-Captain"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Whenever this creature attacks, other attacking creatures get +1/+0 until end of turn.
	AddAttackTrigger(this, &CHonoredCropCaptainCard::BeforePump);
}

bool CHonoredCropCaptainCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this && ((CCreatureCard*)creatures.GetAt(i))->IsAttacking())
			PumpCreature(creatures.GetAt(i), +1, +0);
	return true;
}

CKhenraCharioteerCard::CKhenraCharioteerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Khenra Charioteer"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Other creatures you control have trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new NegateCardComparer(new SpecificCardComparer(this)),
			Power(+0), Life(+0), CreatureKeyword::Trample));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CMercilessJavelineerCard::CMercilessJavelineerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merciless Javelineer"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(4), Life(2))
{
	// {2}, Discard a card: Put a -1/-1 counter on target creature. That creature can't block this turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2"),
			new AnyCreatureComparer, FALSE));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMercilessJavelineerCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CMercilessJavelineerCard::BeforeCounter(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardCounterModifier pCounter = CCardCounterModifier(_T("-1/-1"), 1);
	pCounter.ApplyTo(pCreature);

	if (pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

CNehebTheWorthyCard::CNehebTheWorthyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Neheb, the Worthy"), CardType::_LegendaryCreature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	{
		// Other Minotaurs you control have first strike.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new OtherCreatureTypeComparer(this, SingleCreatureType::Minotaur),
				Power(+0), Life(+0), CreatureKeyword::FirstStrike));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// As long as you have one or fewer cards in hand, Minotaurs you control get +2/+0. (as Thresher Lizard)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Minotaur), false),
				Power(+2), Life(+0)));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new TrueCardComparer);
		cpAbility->SetConditionCheckZone(ZoneId::Hand);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(1);
		cpAbility->SetConditionIsMaximum();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever Neheb deals combat damage to a player, each player discards a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNehebTheWorthyCard::BeforeDiscard));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNehebTheWorthyCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		DiscardCards(GetGame(), GetGame()->GetPlayer(ip), 1);
	return true;
}

CSamutVoiceOfDissentCard::CSamutVoiceOfDissentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Samut, Voice of Dissent"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Double strike, vigilance, haste
	GetCreatureKeyword()->AddDoubleStrike(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	{
		// Other creatures you control have haste.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new NegateCardComparer(new SpecificCardComparer(this)),
				Power(+0), Life(+0), CreatureKeyword::Haste));
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {W}, {T}: Untap another target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
		AddAbility(cpAbility.GetPointer());
	}
}

CShadowstormVizierCard::CShadowstormVizierCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shadowstorm Vizier"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(3))
{
	// Whenever you cycle or discard a card, this creature gets +1/+1 until end of turn.
	AddDiscardTrigger(this, &CShadowstormVizierCard::BeforePump);
}

bool CShadowstormVizierCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

CTemmetVizierOfNaktamunCard::CTemmetVizierOfNaktamunCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Temmet, Vizier of Naktamun"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
	, m_Embalm(this)
{
	{
		// At the beginning of combat on your turn, target creature token you control gets +1/+1 until end of turn and
		// can't be blocked this turn. (as Hazoret's Favor)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature | CardType::Token, true));
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTemmetVizierOfNaktamunCard::BeforePump));
		AddAbility(cpAbility.GetPointer());
	}

	// Embalm {3}{W}{U}
	m_Embalm.AddEmbalmAbility(_T("3") WHITE_MANA_TEXT BLUE_MANA_TEXT);
}

bool CTemmetVizierOfNaktamunCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +1, +1, CreatureKeyword::Unblockable);
	return false;
}

CWatchersOfTheDeadCard::CWatchersOfTheDeadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Watchers of the Dead"), CardType::_ArtifactCreature, CREATURE_TYPE(Cat), nID,
		_T("2"), Power(2), Life(2))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CWatchersOfTheDeadCard::OnCardsSelected))
{
	// Exile this creature: Each opponent chooses two cards in their graveyard and exiles the rest.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddExileCost();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWatchersOfTheDeadCard::BeforeExileGraveyards));
	cpAbility->SetAbilityText(_T("Each opponent chooses two cards in their graveyard and exiles the rest. Activates"));
	AddAbility(cpAbility.GetPointer());
}

bool CWatchersOfTheDeadCard::BeforeExileGraveyards(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CZone* pGraveyard = pOpponent->GetZoneById(ZoneId::Graveyard);
		if (pGraveyard->GetSize() <= 2)
			continue;

		// The opponent chooses the two cards that stay (dwContext1: the opponent)
		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pCard = pGraveyard->GetAt(i);
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Keep %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
		m_CardSelection.AddSelectionRequest(entries, 2, 2, this, pOpponent, (DWORD)pOpponent);
	}
	return true;
}

void CWatchersOfTheDeadCard::OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCountedCardContainer toExile;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (!it->bSelected && pCard->GetZoneId() == ZoneId::Graveyard)
			toExile.AddCard(pCard, CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others);
	for (int i = 0; i < toExile.GetSize(); ++i)
		pModifier.ApplyTo(toExile.GetAt(i));
}

CWaywardServantCard::CWaywardServantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wayward Servant"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Whenever another Zombie you control enters, each opponent loses 1 life and you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new OtherCreatureTypeComparer(this, SingleCreatureType::Zombie));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWaywardServantCard::BeforeDrain));
	AddAbility(cpAbility.GetPointer());
}

bool CWaywardServantCard::BeforeDrain(CAbilityAction* pAction)
{
	EachOpponentLosesLife(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CWeaverOfCurrentsCard::CWeaverOfCurrentsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weaver of Currents"), CardType::Creature, CREATURE_TYPE2(Snake, Druid), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// {T}: Add {C}{C}.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("2")));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
