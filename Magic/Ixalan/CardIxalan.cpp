#include "stdafx.h"
#include "CardIxalan.h"

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
		DEFINE_CARD(CFieldOfRuinCard);
		DEFINE_CARD(CHuatliDinosaurKnightCard);
		DEFINE_CARD(CHuatliWarriorPoetCard);
		DEFINE_CARD(CJaceCunningCastawayCard);
		DEFINE_CARD(CJaceIngeniousMindMageCard);
		DEFINE_CARD(CVraskaRelicSeekerCard);
		DEFINE_CARD(CArguelsBloodFastCard);
		DEFINE_CARD(CTempleOfAclazotzCard);
		DEFINE_CARD(CGrowingRitesOfItlimocCard);
		DEFINE_CARD(CItlimocCradleOfTheSunCard);
		DEFINE_CARD(CLegionsLandingCard);
		DEFINE_CARD(CAdantoTheFirstFortCard);
		DEFINE_CARD(CSearchForAzcantaCard);
		DEFINE_CARD(CAzcantaTheSunkenRuinCard);
		DEFINE_CARD(CAshesOfTheAbhorrentCard);
		DEFINE_CARD(CAxisOfMortalityCard);
		DEFINE_CARD(CCastawaysDespairCard);
		DEFINE_CARD(CDeeprootWatersCard);
		DEFINE_CARD(CIxalansBindingCard);
		DEFINE_CARD(CMakeshiftMunitionsCard);
		DEFINE_CARD(CNavigatorsRuinCard);
		DEFINE_CARD(COneWithTheWindCard);
		DEFINE_CARD(CPiousInterdictionCard);
		DEFINE_CARD(CRaidersWakeCard);
		DEFINE_CARD(CRevelInRichesCard);
		DEFINE_CARD(CShapersSanctuaryCard);
		DEFINE_CARD(CSwashbucklingCard);
		DEFINE_CARD(CTroveOfTemptationCard);
		DEFINE_CARD(CPrimalAmuletCard);
		DEFINE_CARD(CPrimalWellspringCard);
		DEFINE_CARD(CThaumaticCompassCard);
		DEFINE_CARD(CSpiresOfOrazcaCard);
		DEFINE_CARD(CTreasureMapCard);
		DEFINE_CARD(CTreasureCoveCard);
		DEFINE_CARD(CDuskLegionDreadnoughtCard);
		DEFINE_CARD(CElaborateFirecannonCard);
		DEFINE_CARD(CFellFlagshipCard);
		DEFINE_CARD(CHierophantsChaliceCard);
		DEFINE_CARD(CPiratesCutlassCard);
		DEFINE_CARD(CPryingBladeCard);
		DEFINE_CARD(CSentinelTotemCard);
		DEFINE_CARD(CShadowedCaravelCard);
		DEFINE_CARD(CSleekSchoonerCard);
		DEFINE_CARD(CBoneyardParleyCard);
		DEFINE_CARD(CCallToTheFeastCard);
		DEFINE_CARD(CChartACourseCard);
		DEFINE_CARD(CCommuneWithDinosaursCard);
		DEFINE_CARD(CContractKillingCard);
		DEFINE_CARD(CEmergentGrowthCard);
		DEFINE_CARD(CEntrancingMelodyCard);
		DEFINE_CARD(CFirecannonBlastCard);
		DEFINE_CARD(CGraspingCurrentCard);
		DEFINE_CARD(CGrimCaptainsCallCard);
		DEFINE_CARD(CHeartlessPillageCard);
		DEFINE_CARD(CLegionsJudgmentCard);
		DEFINE_CARD(CMarchOfTheDrownedCard);
		DEFINE_CARD(COverflowingInsightCard);
		DEFINE_CARD(CPiratesPrizeCard);
		DEFINE_CARD(CQueensCommissionCard);
		DEFINE_CARD(CRepeatingBarrageCard);
		DEFINE_CARD(CRileCard);
		DEFINE_CARD(CRiversRebukeCard);
		DEFINE_CARD(CSavageStompCard);
		DEFINE_CARD(CSpreadingRotCard);
		DEFINE_CARD(CStarOfExtinctionCard);
		DEFINE_CARD(CSwordPointDiplomacyCard);
		DEFINE_CARD(CWalkThePlankCard);
		DEFINE_CARD(CBlindingFogCard);
		DEFINE_CARD(CBrightReprisalCard);
		DEFINE_CARD(CCostlyPlunderCard);
		DEFINE_CARD(CCrashTheRampartsCard);
		DEFINE_CARD(CCrushingCanopyCard);
		DEFINE_CARD(CDarkNourishmentCard);
		DEFINE_CARD(CDepthsOfDesireCard);
		DEFINE_CARD(CDinosaurStampedeCard);
		DEFINE_CARD(CDiveDownCard);
		DEFINE_CARD(CFieryCannonadeCard);
		DEFINE_CARD(CHuatlisSpurringCard);
		DEFINE_CARD(CLookoutsDispersalCard);
		DEFINE_CARD(CPerilousVoyageCard);
		DEFINE_CARD(CPounceCard);
		DEFINE_CARD(CRallyingRoarCard);
		DEFINE_CARD(CRitualOfRejuvenationCard);
		DEFINE_CARD(CRiverHeraldsBoonCard);
		DEFINE_CARD(CRunAgroundCard);
		DEFINE_CARD(CSanguineSacramentCard);
		DEFINE_CARD(CSettleTheWreckageCard);
		DEFINE_CARD(CShelteringLightCard);
		DEFINE_CARD(CSirensRuseCard);
		DEFINE_CARD(CSkulduggeryCard);
		DEFINE_CARD(CSlashOfTalonsCard);
		DEFINE_CARD(CSpellSwindleCard);
		DEFINE_CARD(CUnfriendlyFireCard);
		DEFINE_CARD(CVampiresZealCard);
		DEFINE_CARD(CVanquishTheWeakCard);
		DEFINE_CARD(CVerdantRebirthCard);
		DEFINE_CARD(CVraskasContemptCard);
		DEFINE_CARD(CAdantoVanguardCard);
		DEFINE_CARD(CBellowingAegisaurCard);
		DEFINE_CARD(CBishopOfRebirthCard);
		DEFINE_CARD(CBishopsSoldierCard);
		DEFINE_CARD(CDuskborneSkymarcherCard);
		DEFINE_CARD(CEmissaryOfSunriseCard);
		DEFINE_CARD(CEncampmentKeeperCard);
		DEFINE_CARD(CGlorifierOfDuskCard);
		DEFINE_CARD(CGoringCeratopsCard);
		DEFINE_CARD(CHuatlisSnubhornCard);
		DEFINE_CARD(CImperialAerosaurCard);
		DEFINE_CARD(CImperialLancerCard);
		DEFINE_CARD(CInspiringClericCard);
		DEFINE_CARD(CKinjallisCallerCard);
		DEFINE_CARD(CKinjallisSunwingCard);
		DEFINE_CARD(CLegionConquistadorCard);
		DEFINE_CARD(CLoomingAltisaurCard);
		DEFINE_CARD(CMavrenFeinDuskApostleCard);
		DEFINE_CARD(CPaladinOfTheBloodstainedCard);
		DEFINE_CARD(CPriestOfTheWakeningSunCard);
		DEFINE_CARD(CPterodonKnightCard);
		DEFINE_CARD(CRaptorCompanionCard);
		DEFINE_CARD(CShiningAerosaurCard);
		DEFINE_CARD(CSkybladeOfTheLegionCard);
		DEFINE_CARD(CSteadfastArmasaurCard);
		DEFINE_CARD(CSunriseSeekerCard);
		DEFINE_CARD(CTerritorialHammerskullCard);
		DEFINE_CARD(CWakeningSunsAvatarCard);
		DEFINE_CARD(CAncientBrontodonCard);
		DEFINE_CARD(CAtzocanArcherCard);
		DEFINE_CARD(CBlossomDryadCard);
		DEFINE_CARD(CCarnageTyrantCard);
		DEFINE_CARD(CColossalDreadmawCard);
		DEFINE_CARD(CDeathgorgeScavengerCard);
		DEFINE_CARD(CDeeprootChampionCard);
		DEFINE_CARD(CDeeprootWarriorCard);
		DEFINE_CARD(CDroverOfTheMightyCard);
		DEFINE_CARD(CEmperorsVanguardCard);
		DEFINE_CARD(CGrazingWhiptailCard);
		DEFINE_CARD(CIxallisDivinerCard);
		DEFINE_CARD(CIxallisKeeperCard);
		DEFINE_CARD(CJadeGuardianCard);
		DEFINE_CARD(CJungleDelverCard);
		DEFINE_CARD(CKumenasSpeakerCard);
		DEFINE_CARD(CMerfolkBranchwalkerCard);
		DEFINE_CARD(COldGrowthDryadsCard);
		DEFINE_CARD(CRangingRaptorsCard);
		DEFINE_CARD(CRavenousDaggertoothCard);
		DEFINE_CARD(CRipjawRaptorCard);
		DEFINE_CARD(CSnappingSailbackCard);
		DEFINE_CARD(CSpikeTailedCeratopsCard);
		DEFINE_CARD(CThunderingSpinebackCard);
		DEFINE_CARD(CTishanasWayfinderCard);
		DEFINE_CARD(CVerdantSunsAvatarCard);
		DEFINE_CARD(CVineshaperMysticCard);
		DEFINE_CARD(CWakerOfTheWildsCard);
		DEFINE_CARD(CWildgrowthWalkerCard);
		DEFINE_CARD(CAngrathsMaraudersCard);
		DEFINE_CARD(CBrazenBuccaneersCard);
		DEFINE_CARD(CBurningSunsAvatarCard);
		DEFINE_CARD(CCaptainLanneryStormCard);
		DEFINE_CARD(CCaptivatingCrewCard);
		DEFINE_CARD(CChargingMonstrosaurCard);
		DEFINE_CARD(CFathomFleetFirebrandCard);
		DEFINE_CARD(CFireShrineKeeperCard);
		DEFINE_CARD(CFrenziedRaptorCard);
		DEFINE_CARD(CHeadstrongBruteCard);
		DEFINE_CARD(CLightningRigCrewCard);
		DEFINE_CARD(CNestRobberCard);
		DEFINE_CARD(COtepecHuntmasterCard);
		DEFINE_CARD(CRampagingFerocidonCard);
		DEFINE_CARD(CRaptorHatchlingCard);
		DEFINE_CARD(CRiggingRunnerCard);
		DEFINE_CARD(CRowdyCrewCard);
		DEFINE_CARD(CStormFleetArsonistCard);
		DEFINE_CARD(CStormFleetPyromancerCard);
		DEFINE_CARD(CSunCrownedHuntersCard);
		DEFINE_CARD(CThrashOfRaptorsCard);
		DEFINE_CARD(CTilonallisKnightCard);
		DEFINE_CARD(CWilyGoblinCard);
		DEFINE_CARD(CAnointedDeaconCard);
		DEFINE_CARD(CBishopOfTheBloodstainedCard);
		DEFINE_CARD(CBlightKeeperCard);
		DEFINE_CARD(CBloodcrazedPaladinCard);
		DEFINE_CARD(CDeadeyeTormentorCard);
		DEFINE_CARD(CDeadeyeTrackerCard);
		DEFINE_CARD(CDeathlessAncientCard);
		DEFINE_CARD(CDesperateCastawaysCard);
		DEFINE_CARD(CDireFleetHoarderCard);
		DEFINE_CARD(CDireFleetInterloperCard);
		DEFINE_CARD(CDireFleetRavagerCard);
		DEFINE_CARD(CFathomFleetCaptainCard);
		DEFINE_CARD(CFathomFleetCutthroatCard);
		DEFINE_CARD(CKitesailFreebooterCard);
		DEFINE_CARD(CLurkingChupacabraCard);
		DEFINE_CARD(CQueensAgentCard);
		DEFINE_CARD(CQueensBaySoldierCard);
		DEFINE_CARD(CRuinRaiderCard);
		DEFINE_CARD(CRuthlessKnaveCard);
		DEFINE_CARD(CSanctumSeekerCard);
		DEFINE_CARD(CSeekersSquireCard);
		DEFINE_CARD(CSkitteringHeartstopperCard);
		DEFINE_CARD(CSkymarchBloodletterCard);
		DEFINE_CARD(CViciousConquistadorCard);
		DEFINE_CARD(CWantedScoundrelsCard);
		DEFINE_CARD(CDaringSaboteurCard);
		DEFINE_CARD(CDeadeyeQuartermasterCard);
		DEFINE_CARD(CDreamcallerSirenCard);
		DEFINE_CARD(CFleetSwallowerCard);
		DEFINE_CARD(CHeadwaterSentriesCard);
		DEFINE_CARD(CHeraldOfSecretStreamsCard);
		DEFINE_CARD(CJacesSentinelCard);
		DEFINE_CARD(CProsperousPiratesCard);
		DEFINE_CARD(CRiverSneakCard);
		DEFINE_CARD(CSailorOfMeansCard);
		DEFINE_CARD(CShaperApprenticeCard);
		DEFINE_CARD(CShipwreckLooterCard);
		DEFINE_CARD(CShoreKeeperCard);
		DEFINE_CARD(CSirenLookoutCard);
		DEFINE_CARD(CSirenStormtamerCard);
		DEFINE_CARD(CStormFleetAerialistCard);
		DEFINE_CARD(CStormFleetSpyCard);
		DEFINE_CARD(CStormSculptorCard);
		DEFINE_CARD(CTempestCallerCard);
		DEFINE_CARD(CWatertrapWeaverCard);
		DEFINE_CARD(CWindStriderCard);
		DEFINE_CARD(CAdmiralBeckettBrassCard);
		DEFINE_CARD(CDeadeyePlunderersCard);
		DEFINE_CARD(CDireFleetCaptainCard);
		DEFINE_CARD(CGildedSentinelCard);
		DEFINE_CARD(CGishathSunsAvatarCard);
		DEFINE_CARD(CHostageTakerCard);
		DEFINE_CARD(CMaraudingLooterCard);
		DEFINE_CARD(CRagingSwordtoothCard);
		DEFINE_CARD(CRegisaurAlphaCard);
		DEFINE_CARD(CShapersOfNatureCard);
		DEFINE_CARD(CSkyTerrorCard);
		DEFINE_CARD(CSunBlessedMountCard);
		DEFINE_CARD(CTishanaVoiceOfThunderCard);
		DEFINE_CARD(CVonaButcherOfMaganCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers

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

//____________________________________________________________________________
//
// Lands

CFieldOfRuinCard::CFieldOfRuinCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Field of Ruin"), nID)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {2}, {T}, Sacrifice this land: Destroy target nonbasic land an opponent controls. Each player searches their
	// library for a basic land card, puts it onto the battlefield, then shuffles.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2"),
			new CardTypeComparer(CardType::NonbasicLand, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFieldOfRuinCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

// The destruction happens first, then each player searches (the callback destroys the land itself and returns false)
bool CFieldOfRuinCard::BeforeSearch(CAbilityAction* pAction)
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (pLand && pLand->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy,
			pAction->GetController());
		pModifier.ApplyTo(pLand);
	}

	// Each player, starting with the controller
	CPlayer* pController = pAction->GetController();
	SearchToBattlefield(GetGame(), pController, 1, CCardFilter::GetFilter(_T("basic lands")), FALSE);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			SearchToBattlefield(GetGame(), GetGame()->GetPlayer(ip), 1, CCardFilter::GetFilter(_T("basic lands")), FALSE);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (planeswalkers)

#define TREASURE_TOKEN_NAME		_T("Treasure")
#define TREASURE_TOKEN_ID		55102
#define DINOSAUR_A_TOKEN_NAME	_T("Dinosaur (A)")
#define DINOSAUR_A_TOKEN_ID		55103
#define PIRATE_A_TOKEN_NAME		_T("Pirate (A)")
#define PIRATE_A_TOKEN_ID		55104
#define ILLUSION_C_TOKEN_NAME	_T("Illusion (C)")
#define ILLUSION_C_TOKEN_ID		55105

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

//____________________________________________________________________________
//
// Planeswalkers

CHuatliDinosaurKnightCard::CHuatliDinosaurKnightCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Huatli, Dinosaur Knight"), nID,
		_T("4") RED_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Huatli, 4)
{
	{
		// +2: Put two +1/+1 counters on up to one target Dinosaur you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), 2));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Target Dinosaur you control deals damage equal to its power to target creature you don't control.
		// (as Ral Zarek in Dragon's Maze)
		counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
				_T(""),
				new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false), false,
				new AnyCreatureComparer, false, _T(""), TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHuatliDinosaurKnightCard::BeforeFight));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: Dinosaurs you control get +4/+4 until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHuatliDinosaurKnightCard::BeforePump));
		cpAbility->SetAbilityText(_T("-7: Dinosaurs you control get +4/+4 until end of turn."));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHuatliDinosaurKnightCard::BeforeFight(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return false;

	CCreatureCard* pDinosaur = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (pDinosaur && pDinosaur->GetZoneId() == ZoneId::Battlefield)
		DealDamageToCreature(pDinosaur, pTarget, (int)pDinosaur->GetPower());
	return false;
}

bool CHuatliDinosaurKnightCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CreatureTypeComparer dinosaurs(CREATURE_TYPE(Dinosaur), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (dinosaurs(creatures.GetAt(i)))
			PumpCreature(creatures.GetAt(i), +4, +4);
	return true;
}

CHuatliWarriorPoetCard::CHuatliWarriorPoetCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Huatli, Warrior Poet"), nID,
		_T("3") RED_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Huatli, 3)
{
	{
		// +2: You gain life equal to the greatest power among creatures you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHuatliWarriorPoetCard::BeforeGainLife));
		cpAbility->SetAbilityText(_T("+2: You gain life equal to the greatest power among creatures you control."));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// 0: Create a 3/3 green Dinosaur creature token with trample. (as Theros)
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				DINOSAUR_A_TOKEN_NAME, DINOSAUR_A_TOKEN_ID,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), 0);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -X: Huatli deals X damage divided as you choose among any number of target creatures. Creatures dealt damage
		// this way can't block this turn.
		// Partial: X damage to one target creature (the damage can't be divided with a variable X)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), SpecialNumber::AnyNegative);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHuatliWarriorPoetCard::BeforeDamage));
		cpAbility->SetAbilityText(_T("-X: Huatli deals X damage to target creature. It can't block this turn."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHuatliWarriorPoetCard::BeforeGainLife(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	int nGreatest = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		int nPower = (int)((CCreatureCard*)creatures.GetAt(i))->GetPower();
		if (nPower > nGreatest)
			nGreatest = nPower;
	}
	if (nGreatest > 0)
		GainLife(this, pAction->GetController(), nGreatest);
	return true;
}

// (X as Chandra, Flamecaller in Oath of the Gatewatch)
bool CHuatliWarriorPoetCard::BeforeDamage(CAbilityAction* pAction)
{
	int nX = -pAction->GetCostConfigEntry().GetExtraValue();
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (nX <= 0 || !pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	DealDamageToCreature(this, pCreature, nX);
	if (pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

CJaceCunningCastawayCard::CJaceCunningCastawayCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jace, Cunning Castaway"), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT,
		PlaneswalkerType::Jace, 3)
	, m_nLootTurn(-1)
	, m_nLootCount(0)
	, m_nLootedTurn(-1)
{
	{
		// +1: Whenever one or more creatures you control deal combat damage to a player this turn, draw a card, then
		// discard a card.
		// Partial: the effect works while Jace is on the battlefield, and it loots once per turn
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJaceCunningCastawayCard::BeforeLootEffect));
		cpAbility->SetAbilityText(_T("+1: Whenever creatures you control deal combat damage to a player this turn, draw a card, then discard a card."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// The loot (a combat damage trigger enabled by the +1)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CJaceCunningCastawayCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJaceCunningCastawayCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Create a 2/2 blue Illusion creature token with "When this token becomes the target of a spell, sacrifice
		// it."
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				ILLUSION_C_TOKEN_NAME, ILLUSION_C_TOKEN_ID,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		AddAbility(cpAbility.GetPointer());
	}

	// -5: Create two tokens that are copies of Jace, except they're not legendary.
	// Not implemented: the planeswalkers can't be copied as tokens
}

bool CJaceCunningCastawayCard::BeforeLootEffect(CAbilityAction* pAction)
{
	int nTurn = GetGame()->GetGameTurnNumber();
	if (m_nLootTurn != nTurn)
	{
		m_nLootTurn = nTurn;
		m_nLootCount = 0;
	}
	++m_nLootCount;
	return true;
}

// Once per turn, if the +1 was activated this turn and the damage is dealt to an opponent
bool CJaceCunningCastawayCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CPlayer* pPlayer, Damage damage) const
{
	int nTurn = GetGame()->GetGameTurnNumber();
	if (m_nLootTurn != nTurn || m_nLootedTurn == nTurn || !pPlayer || pPlayer == GetController())
		return false;

	m_nLootedTurn = nTurn;
	return true;
}

bool CJaceCunningCastawayCard::BeforeLoot(CAbilityAction* pAction)
{
	for (int i = 0; i < m_nLootCount; ++i)
	{
		DrawCards(GetGame(), pAction->GetController(), 1);
		DiscardCards(GetGame(), pAction->GetController(), 1);
	}
	return true;
}

CJaceIngeniousMindMageCard::CJaceIngeniousMindMageCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jace, Ingenious Mind-Mage"), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
		PlaneswalkerType::Jace, 5)
{
	{
		// +1: Draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
		cpAbility->SetAbilityText(_T("+1: Draw a card."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// +1: Untap all creatures you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJaceIngeniousMindMageCard::BeforeUntap));
		cpAbility->SetAbilityText(_T("+1: Untap all creatures you control."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -9: Gain control of up to three target creatures.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
		cpAbility->GetTargeting()->SetSubjectCount(0, 3);
		cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CGainControlModifier(pGame, this));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CJaceIngeniousMindMageCard::BeforeUntap(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetOrientation()->IsTapped())
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CVraskaRelicSeekerCard::CVraskaRelicSeekerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Vraska, Relic Seeker"), nID,
		_T("4") BLACK_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Vraska, 6)
{
	{
		// +2: Create a 2/2 black Pirate creature token with menace.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				PIRATE_A_TOKEN_NAME, PIRATE_A_TOKEN_ID,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Destroy target artifact, creature, or enchantment. Create a Treasure token.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVraskaRelicSeekerCard::BeforeTreasure));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -10: Target player's life total becomes 1.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -10);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVraskaRelicSeekerCard::BeforeLife));
		AddAbility(cpAbility.GetPointer());
	}
}

// The Treasure is created before the destruction (the callback returns true: ResolveImpl destroys the target)
bool CVraskaRelicSeekerCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CVraskaRelicSeekerCard::BeforeLife(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return true;

	Life nDelta = Life(1) - pPlayer->GetLife();
	if (nDelta != Life(0))
	{
		CLifeModifier pModifier = CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (enchantments)

#define VAMPIRE_E_TOKEN_NAME	_T("Vampire (E)")
#define VAMPIRE_E_TOKEN_ID		55106
#define MERFOLK_A_TOKEN_NAME	_T("Merfolk (A)")
#define MERFOLK_A_TOKEN_ID		55107

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

//____________________________________________________________________________
//
// Transform enchantments

CTransformEnchantmentBase::CTransformEnchantmentBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText,
	LPCTSTR strBackName)
	: CDoubleFacedInPlaySpellCard(pGame, strCardName, CardType::_LegendaryGlobalEnchantment, nID,
		strCostText, strBackName, AbilityType::Enchantment)
{
	// The back face is a legendary land (it isn't an enchantment)
	AddCardModifier(new CCardTypeModifier(CardType::NonbasicLand, FALSE, CardType::GlobalEnchantment));
}

// (as Chalice of Life in Dark Ascension)
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

CArguelsBloodFastCard::CArguelsBloodFastCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Arguel's Blood Fast"), nID,
		_T("1") BLACK_MANA_TEXT, _T("Temple of Aclazotz"))
	, m_CreatureFilter(_T("a creature"), _T("creatures"), new AnyCreatureComparer)
{
	{
		// {1}{B}, Pay 2 life: Draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") BLACK_MANA_TEXT));

		cpAbility->AddPayLifeDeltaCost(Life(-2));
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
		cpAbility->SetAbilityText(_T("Pay 2 life: draw a card. Activates"));
		SetFace(cpAbility.GetPointer(), TRUE);
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your upkeep, if you have 5 or less life, you may transform Arguel's Blood Fast.
	AddStepTrigger(this, NodeId::UpkeepStep, true, &CArguelsBloodFastCard::SetTriggerContext, &CArguelsBloodFastCard::BeforeTransform);

	// Temple of Aclazotz: {T}: Add {B}.
	AddBackManaAbility(BLACK_MANA_TEXT);
	{
		// Temple of Aclazotz: {T}, Sacrifice a creature: You gain life equal to the sacrificed creature's toughness.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_CreatureFilter);
		cpAbility->SetAbilityText(_T("Sacrifice a creature: you gain life equal to its toughness. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArguelsBloodFastCard::BeforeGainLife));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CArguelsBloodFastCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return IsFirstFaceInPlay() && GetController()->GetLife() <= Life(5);
}

bool CArguelsBloodFastCard::BeforeTransform(CAbilityAction* pAction)
{
	if (GetController()->GetLife() <= Life(5))
		DoTransform();
	return true;
}

// The toughness of the sacrificed creature (as the sacrifice costs in Eldritch Moon)
bool CArguelsBloodFastCard::BeforeGainLife(CAbilityAction* pAction)
{
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	if (!pSacrificed || pSacrificed->GetSize() == 0)
		return true;

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pSacrificed->GetAt(0));
	int nToughness = pCreature ? (int)pCreature->GetLastKnownToughness() : 0;
	if (nToughness > 0)
		GainLife(this, pAction->GetController(), nToughness);
	return true;
}

CTempleOfAclazotzCard::CTempleOfAclazotzCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Temple of Aclazotz"), nID, CardType::Legendary)
{
	// The back face of Arguel's Blood Fast (its abilities are in that card)
	AddTapManaAbility(this, BLACK_MANA_TEXT);
}

CGrowingRitesOfItlimocCard::CGrowingRitesOfItlimocCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Growing Rites of Itlimoc"), nID,
		_T("2") GREEN_MANA_TEXT, _T("Itlimoc, Cradle of the Sun"))
{
	// When Growing Rites of Itlimoc enters, look at the top four cards of your library. You may reveal a creature card
	// from among them and put it into your hand. Put the rest on the bottom of your library in any order.
	AddEnterTrigger(this, &CGrowingRitesOfItlimocCard::BeforeLook);

	// At the beginning of your end step, if you control four or more creatures, transform Growing Rites of Itlimoc.
	AddStepTrigger(this, NodeId::EndStep, false, &CGrowingRitesOfItlimocCard::SetTriggerContext, &CGrowingRitesOfItlimocCard::BeforeTransform);

	// Itlimoc, Cradle of the Sun: {T}: Add {G}.
	AddBackManaAbility(GREEN_MANA_TEXT);

	// Itlimoc, Cradle of the Sun: {T}: Add {G} for each creature you control.
	// Not implemented: a mana ability can't add a variable amount of mana
}

bool CGrowingRitesOfItlimocCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 4, CCardFilter::GetFilter(_T("creatures")));
	return true;
}

bool CGrowingRitesOfItlimocCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return IsFirstFaceInPlay() && CountCreatures(GetGame(), GetController()) >= 4;
}

bool CGrowingRitesOfItlimocCard::BeforeTransform(CAbilityAction* pAction)
{
	if (CountCreatures(GetGame(), GetController()) >= 4)
		DoTransform();
	return true;
}

CItlimocCradleOfTheSunCard::CItlimocCradleOfTheSunCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Itlimoc, Cradle of the Sun"), nID, CardType::Legendary)
{
	// The back face of Growing Rites of Itlimoc (its abilities are in that card)
	AddTapManaAbility(this, GREEN_MANA_TEXT);
}

CLegionsLandingCard::CLegionsLandingCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Legion's Landing"), nID,
		WHITE_MANA_TEXT, _T("Adanto, the First Fort"))
{
	// When Legion's Landing enters, create a 1/1 white Vampire creature token with lifelink.
	AddEnterTrigger(this, &CLegionsLandingCard::BeforeToken);

	// When you attack with three or more creatures, transform Legion's Landing. (a trigger after the attackers are
	// declared)
	AddStepTrigger(this, NodeId::DeclareAttackersStep2, false, &CLegionsLandingCard::SetTriggerContext, &CLegionsLandingCard::BeforeTransform);

	// Adanto, the First Fort: {T}: Add {W}.
	AddBackManaAbility(WHITE_MANA_TEXT);
	{
		// Adanto, the First Fort: {2}{W}, {T}: Create a 1/1 white Vampire creature token with lifelink.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2") WHITE_MANA_TEXT,
				VAMPIRE_E_TOKEN_NAME, VAMPIRE_E_TOKEN_ID,
				1));

		cpAbility->AddTapCost();
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLegionsLandingCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), VAMPIRE_E_TOKEN_NAME, VAMPIRE_E_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CLegionsLandingCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	if (!IsFirstFaceInPlay())
		return false;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	int nAttacking = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (((CCreatureCard*)creatures.GetAt(i))->IsAttacking())
			++nAttacking;
	return nAttacking >= 3;
}

bool CLegionsLandingCard::BeforeTransform(CAbilityAction* pAction)
{
	DoTransform();
	return true;
}

CAdantoTheFirstFortCard::CAdantoTheFirstFortCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Adanto, the First Fort"), nID, CardType::Legendary)
{
	// The back face of Legion's Landing (its abilities are in that card)
	AddTapManaAbility(this, WHITE_MANA_TEXT);
}

CSearchForAzcantaCard::CSearchForAzcantaCard(CGame* pGame, UINT nID)
	: CTransformEnchantmentBase(pGame, _T("Search for Azcanta"), nID,
		_T("1") BLUE_MANA_TEXT, _T("Azcanta, the Sunken Ruin"))
	, m_LookFilter(_T("a noncreature, nonland card"), _T("noncreature, nonland cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::Creature | CardType::_Land, false)))
{
	// At the beginning of your upkeep, surveil 1. Then if you have seven or more cards in your graveyard, you may
	// transform Search for Azcanta.
	// Note: it transforms without asking
	AddStepTrigger(this, NodeId::UpkeepStep, false, &CSearchForAzcantaCard::SetTriggerContext, &CSearchForAzcantaCard::BeforeSurveil);

	// Azcanta, the Sunken Ruin: {T}: Add {U}.
	AddBackManaAbility(BLUE_MANA_TEXT);
	{
		// Azcanta, the Sunken Ruin: {2}{U}, {T}: Look at the top four cards of your library. You may reveal a
		// noncreature, nonland card from among them and put it into your hand. Put the rest on the bottom of your
		// library in any order.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLUE_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Look at the top four cards of your library; put a noncreature, nonland card into your hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSearchForAzcantaCard::BeforeLook));
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSearchForAzcantaCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return IsFirstFaceInPlay();
}

bool CSearchForAzcantaCard::BeforeSurveil(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CSurveilModifier pSurveil = CSurveilModifier(GetGame(), 1, this);
	pSurveil.ApplyTo(pController);

	if (pController->GetZoneById(ZoneId::Graveyard)->GetSize() >= 7)
		DoTransform();
	return true;
}

bool CSearchForAzcantaCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 4, &m_LookFilter);
	return true;
}

CAzcantaTheSunkenRuinCard::CAzcantaTheSunkenRuinCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Azcanta, the Sunken Ruin"), nID, CardType::Legendary)
{
	// The back face of Search for Azcanta (its abilities are in that card)
	AddTapManaAbility(this, BLUE_MANA_TEXT);
}

//____________________________________________________________________________
//
// Enchantments

CAshesOfTheAbhorrentCard::CAshesOfTheAbhorrentCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ashes of the Abhorrent"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Players can't cast spells from graveyards or activate abilities of cards in graveyards.
	// Not implemented: there is no restriction on the graveyards

	// Whenever a creature dies, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAshesOfTheAbhorrentCard::BeforeGainLife));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CAshesOfTheAbhorrentCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CAxisOfMortalityCard::CAxisOfMortalityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Axis of Mortality"), CardType::GlobalEnchantment, nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of your upkeep, you may have two target players exchange life totals.
	// Note: the players are you and your opponent (two-player games)
	AddStepTrigger(this, NodeId::UpkeepStep, true,
		(bool (CAxisOfMortalityCard::*)(CTriggeredAbility<>::TriggerContextType&, CNode*) const)NULL,
		&CAxisOfMortalityCard::BeforeExchange);
}

bool CAxisOfMortalityCard::BeforeExchange(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	Life nDelta = pOpponent->GetLife() - pController->GetLife();
	if (nDelta == Life(0))
		return true;

	CLifeModifier pToController = CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CLifeModifier pToOpponent = CLifeModifier(Life(0) - nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pToController.ApplyTo(pController);
	pToOpponent.ApplyTo(pOpponent);
	return true;
}

CCastawaysDespairCard::CCastawaysDespairCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Castaway's Despair"), nID,
		_T("3") BLUE_MANA_TEXT,
		Power(+0), Life(+0))
{
	// Enchanted creature doesn't untap during its controller's untap step. (as Claustrophobia)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);

	// When this Aura enters, tap enchanted creature.
	AddEnterTrigger(this, &CCastawaysDespairCard::BeforeTap);
}

bool CCastawaysDespairCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCreature = m_pChgPwrTghAttrEnchant->GetEnchantedOnCard();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

CDeeprootWatersCard::CDeeprootWatersCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Deeproot Waters"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast a Merfolk spell, create a 1/1 blue Merfolk creature token with hexproof.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, MERFOLK_A_TOKEN_NAME, MERFOLK_A_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CIxalansBindingCard::CIxalansBindingCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ixalan's Binding"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// When this enchantment enters, exile target nonland permanent an opponent controls until this enchantment
		// leaves the battlefield. (as Cast Out in Amonkhet)
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIxalansBindingCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}

	AddLeaveTrigger(this, &CIxalansBindingCard::BeforeReturn);

	// Your opponents can't cast spells with the same name as the exiled card.
	// Not implemented: there is no restriction by name
}

bool CIxalansBindingCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CIxalansBindingCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CMakeshiftMunitionsCard::CMakeshiftMunitionsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Makeshift Munitions"), CardType::GlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_SacrificeFilter(_T("an artifact or creature"), _T("artifacts or creatures"),
		new CardTypeComparer(CardType::Artifact | CardType::Creature, false))
{
	// {1}, Sacrifice an artifact or creature: This enchantment deals 1 damage to any target.
	// Note: it can't target planeswalkers
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("1"),
			new AnyCreatureComparer, TRUE,
			Life(-1), PreventableType::Preventable));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

CNavigatorsRuinCard::CNavigatorsRuinCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Navigator's Ruin"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Raid - At the beginning of your end step, if you attacked this turn, target opponent mills four cards.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNavigatorsRuinCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNavigatorsRuinCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CNavigatorsRuinCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRaid(GetController()) == TRUE;
}

bool CNavigatorsRuinCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 4);
	return false;
}

COneWithTheWindCard::COneWithTheWindCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("One With the Wind"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::Flying)
{
	// Enchanted creature gets +2/+2 and has flying.
}

CPiousInterdictionCard::CPiousInterdictionCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Pious Interdiction"), nID,
		_T("3") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
{
	// Enchanted creature can't attack or block.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// When this Aura enters, you gain 2 life.
	AddEnterTrigger(this, &CPiousInterdictionCard::BeforeGainLife);
}

bool CPiousInterdictionCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CRaidersWakeCard::CRaidersWakeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Raiders' Wake"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever an opponent discards a card, that player loses 2 life.
		// Note: the player is the opponent (two-player games)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRaidersWakeCard::BeforeLoseLife));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Raid - At the beginning of your end step, if you attacked this turn, target opponent discards a card.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
		cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRaidersWakeCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRaidersWakeCard::BeforeDiscard));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRaidersWakeCard::BeforeLoseLife(CAbilityAction* pAction)
{
	CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(GetGame()->GetNextPlayer(pAction->GetController()));
	return true;
}

bool CRaidersWakeCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRaid(GetController()) == TRUE;
}

bool CRaidersWakeCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DiscardCards(GetGame(), pPlayer, 1);
	return false;
}

CRevelInRichesCard::CRevelInRichesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Revel in Riches"), CardType::GlobalEnchantment, nID,
		_T("4") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever a creature an opponent controls dies, create a Treasure token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromOpponentsOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, TREASURE_TOKEN_NAME, TREASURE_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of your upkeep, if you control ten or more Treasures, you win the game. (each opponent loses
		// the game, as Felidar Sovereign in Zendikar)
		counted_ptr<WinAbility> cpAbility(::CreateObject<WinAbility>(this, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(WinAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(WinAbility::ContextFunction(this, &CRevelInRichesCard::SetWinContext));
		cpAbility->SetBeforeResolveSelectionCallback(WinAbility::BeforeResolveSelectionCallback(this, &CRevelInRichesCard::BeforeWin));
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CRevelInRichesCard::HasTenTreasures() const
{
	CCardFilter treasures(_T("a Treasure"), _T("Treasures"), new CardNameComparer(_T("Treasure")));
	return treasures.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= 10;
}

bool CRevelInRichesCard::SetWinContext(CTriggeredLoseGameAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasTenTreasures() == TRUE;
}

bool CRevelInRichesCard::BeforeWin(WinAbility::TriggeredActionType* pAction)
{
	return HasTenTreasures() == TRUE;
}

CShapersSanctuaryCard::CShapersSanctuaryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Shapers' Sanctuary"), CardType::GlobalEnchantment, nID,
		GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control becomes the target of a spell or ability an opponent controls, you may draw a
	// card. (as Phantasmal Bear in M12)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, TRUE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CShapersSanctuaryCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShapersSanctuaryCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

// The spell or ability is controlled by an opponent
bool CShapersSanctuaryCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const
{
	return pPlayer && pPlayer != GetController();
}

bool CShapersSanctuaryCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSwashbucklingCard::CSwashbucklingCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Swashbuckling"), nID,
		_T("1") RED_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::Haste)
{
	// Enchanted creature gets +2/+2 and has haste.
}

CTroveOfTemptationCard::CTroveOfTemptationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Trove of Temptation"), CardType::GlobalEnchantment, nID,
		_T("3") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// Each opponent must attack you or a planeswalker you control with at least one creature each combat if able.
	// Not implemented: there is no "must attack with at least one creature"

	// At the beginning of your end step, create a Treasure token.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, TREASURE_TOKEN_NAME, TREASURE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (artifacts)

#define LANDMARK_COUNTER	_T("landmark counter")
#define CHARGE_COUNTER		_T("charge counter")

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

//____________________________________________________________________________
//
// Transform artifacts

CTransformArtifactBase::CTransformArtifactBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText,
	LPCTSTR strBackName)
	: CDoubleFacedInPlaySpellCard(pGame, strCardName, CardType::Artifact, nID,
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

CPrimalAmuletCard::CPrimalAmuletCard(CGame* pGame, UINT nID)
	: CTransformArtifactBase(pGame, _T("Primal Amulet"), nID,
		_T("4"), _T("Primal Wellspring"))
{
	{
		// Instant and sorcery spells you cast cost {1} less to cast. (the enchantment of the first face ends when it
		// transforms, as CDoubleFacedInPlaySpellCard::SecondFace)
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
				_T("1")));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetAbilityName(_T("First Face Enchantment"));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast an instant or sorcery spell, put a charge counter on this artifact. Then if there are four
		// or more charge counters on it, you may remove those counters and transform it.
		// Note: it transforms without asking
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPrimalAmuletCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrimalAmuletCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// Primal Wellspring: {T}: Add one mana of any color. When that mana is spent to cast an instant or sorcery spell,
	// copy that spell and you may choose new targets for the copy.
	// Partial: the spell isn't copied (the engine doesn't know where the mana is spent)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
		AddBackManaAbility(colors[i]);
}

bool CPrimalAmuletCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	return IsFirstFaceInPlay() == TRUE;
}

bool CPrimalAmuletCard::BeforeCounter(CAbilityAction* pAction)
{
	if (!IsFirstFaceInPlay())
		return true;

	CCardCounterModifier pAdd = CCardCounterModifier(CHARGE_COUNTER, +1);
	pAdd.ApplyTo(this);

	int nCounters = CountCounters(this, CHARGE_COUNTER);
	if (nCounters >= 4)
	{
		CCardCounterModifier pRemove = CCardCounterModifier(CHARGE_COUNTER, -nCounters);
		pRemove.ApplyTo(this);
		DoTransform();
	}
	return true;
}

CPrimalWellspringCard::CPrimalWellspringCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Primal Wellspring"), nID)
{
	// The back face of Primal Amulet (its abilities are in that card)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
		AddTapManaAbility(this, colors[i]);
}

CThaumaticCompassCard::CThaumaticCompassCard(CGame* pGame, UINT nID)
	: CTransformArtifactBase(pGame, _T("Thaumatic Compass"), nID,
		_T("2"), _T("Spires of Orazca"))
{
	{
		// {3}, {T}: Search your library for a basic land card, reveal it, put it into your hand, then shuffle.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("3")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Search your library for a basic land card and put it into your hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThaumaticCompassCard::BeforeSearch));
		SetFace(cpAbility.GetPointer(), TRUE);
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your end step, if you control seven or more lands, transform this artifact.
	AddStepTrigger(this, NodeId::EndStep, false, &CThaumaticCompassCard::SetTriggerContext, &CThaumaticCompassCard::BeforeTransform);

	// Spires of Orazca: {T}: Add {C}.
	AddBackManaAbility(_T("1"));
	{
		// Spires of Orazca: {T}: Untap target attacking creature an opponent controls and remove it from combat.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AttackingCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThaumaticCompassCard::BeforeRemove));
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CThaumaticCompassCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a basic land card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		CCardFilter::GetFilter(_T("basic lands")), // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

bool CThaumaticCompassCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return IsFirstFaceInPlay() &&
		CCardFilter::GetFilter(_T("lands"))->CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= 7;
}

bool CThaumaticCompassCard::BeforeTransform(CAbilityAction* pAction)
{
	DoTransform();
	return true;
}

bool CThaumaticCompassCard::BeforeRemove(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	if (pCreature->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCreature);
	}
	pCreature->RemoveFromCombat(TRUE);
	return true;
}

CSpiresOfOrazcaCard::CSpiresOfOrazcaCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Spires of Orazca"), nID)
{
	// The back face of Thaumatic Compass (its abilities are in that card)
	AddTapManaAbility(this, _T("1"));
}

CTreasureMapCard::CTreasureMapCard(CGame* pGame, UINT nID)
	: CTransformArtifactBase(pGame, _T("Treasure Map"), nID,
		_T("2"), _T("Treasure Cove"))
	, m_TreasureFilter(_T("a Treasure"), _T("Treasures"), new CardNameComparer(_T("Treasure")))
{
	{
		// {1}, {T}: Scry 1. Put a landmark counter on this artifact. Then if there are three or more landmark counters
		// on it, remove those counters, transform this artifact, and create three Treasure tokens.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Scry 1 and put a landmark counter on this artifact. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTreasureMapCard::BeforeScry));
		SetFace(cpAbility.GetPointer(), TRUE);
		AddAbility(cpAbility.GetPointer());
	}

	// Treasure Cove: {T}: Add {C}.
	AddBackManaAbility(_T("1"));
	{
		// Treasure Cove: {T}, Sacrifice a Treasure: Draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_TreasureFilter);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
		cpAbility->SetAbilityText(_T("Sacrifice a Treasure: draw a card. Activates"));
		SetFace(cpAbility.GetPointer(), FALSE);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTreasureMapCard::BeforeScry(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CScryModifier pScry = CScryModifier(GetGame(), 1, this);
	pScry.ApplyTo(pController);

	if (!IsFirstFaceInPlay())
		return true;

	CCardCounterModifier pAdd = CCardCounterModifier(LANDMARK_COUNTER, +1);
	pAdd.ApplyTo(this);

	int nCounters = CountCounters(this, LANDMARK_COUNTER);
	if (nCounters >= 3)
	{
		CCardCounterModifier pRemove = CCardCounterModifier(LANDMARK_COUNTER, -nCounters);
		pRemove.ApplyTo(this);
		DoTransform();
		CreateTreasure(GetGame(), pController, 3);
	}
	return true;
}

CTreasureCoveCard::CTreasureCoveCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Treasure Cove"), nID)
{
	// The back face of Treasure Map (its abilities are in that card)
	AddTapManaAbility(this, _T("1"));
}

//____________________________________________________________________________
//
// Artifacts

CDuskLegionDreadnoughtCard::CDuskLegionDreadnoughtCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dusk Legion Dreadnought"), CardType::Artifact, nID,
		_T("5"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Vigilance (in the crewed creature). Crew 2
	m_Crew.AddCrewAbility(2, _T("Dusk Legion Dreadnought (Vehicle)"), 64124);
}

CElaborateFirecannonCard::CElaborateFirecannonCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Elaborate Firecannon"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// This artifact doesn't untap during your untap step.
	GetCardKeyword()->AddNoUntapInUntapPhase();

	{
		// {4}, {T}: This artifact deals 2 damage to any target.
		// Note: it can't target planeswalkers
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("4"),
				new AnyCreatureComparer, TRUE,
				Life(-2), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your upkeep, you may discard a card. If you do, untap this artifact.
	AddStepTrigger(this, NodeId::UpkeepStep, true,
		(bool (CElaborateFirecannonCard::*)(CTriggeredAbility<>::TriggerContextType&, CNode*) const)NULL,
		&CElaborateFirecannonCard::BeforeUntap);
}

bool CElaborateFirecannonCard::BeforeUntap(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (pController->GetZoneById(ZoneId::Hand)->GetSize() == 0 || GetZoneId() != ZoneId::Battlefield)
		return true;

	DiscardCards(GetGame(), pController, 1);
	if (GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CFellFlagshipCard::CFellFlagshipCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fell Flagship"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	{
		// Pirates you control get +1/+0.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Pirate), false),
				Power(+1), Life(+0)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// Whenever this Vehicle deals combat damage to a player, that player discards a card. (in the crewed creature)
	// Crew 3
	m_Crew.AddCrewAbility(3, _T("Fell Flagship (Vehicle)"), 64125);
}

CHierophantsChaliceCard::CHierophantsChaliceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hierophant's Chalice"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// When this artifact enters, target opponent loses 1 life and you gain 1 life.
	// Note: the opponent isn't targeted (two-player games)
	AddEnterTrigger(this, &CHierophantsChaliceCard::BeforeDrain);

	// {T}: Add {C}.
	AddTapManaAbility(this, _T("1"));
}

bool CHierophantsChaliceCard::BeforeDrain(CAbilityAction* pAction)
{
	CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(GetGame()->GetNextPlayer(pAction->GetController()));
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CPiratesCutlassCard::CPiratesCutlassCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pirate's Cutlass"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// Equipped creature gets +2/+1. Equip {2} (as Inventor's Goggles in Kaladesh)
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("2")));

		cpAbility->AddCreatureModifier(new CLifeModifier(Life(+1), this,
			PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
		cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this Equipment enters, attach it to target Pirate you control.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false));
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPiratesCutlassCard::BeforeAttach));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPiratesCutlassCard::BeforeAttach(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && GetZoneId() == ZoneId::Battlefield &&
		pCard->GetCardType().IsCreature() && pCard->GetController() == GetController())
	{
		CEquipModifier pModifier = CEquipModifier(this);
		pModifier.ApplyTo((CCreatureCard*)pCard);
	}
	return false;
}

CPryingBladeCard::CPryingBladeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Prying Blade"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	{
		// Equipped creature gets +1/+0. Equip {2}
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("2")));

		cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever equipped creature deals combat damage to a player, create a Treasure token. (the trigger is on the
		// equipment, as Dagger of the Worthy in Hour of Devastation)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPryingBladeCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPryingBladeCard::BeforeTreasure));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPryingBladeCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CPlayer* pPlayer, Damage damage) const
{
	return pSource && GetEquippedOn() == pSource;
}

bool CPryingBladeCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CSentinelTotemCard::CSentinelTotemCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sentinel Totem"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	{
		// When this artifact enters, scry 1.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(pGame, 1, this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Exile this artifact: Exile all graveyards.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->AddExileCost();
		cpAbility->SetAbilityText(_T("Exile all graveyards. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSentinelTotemCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSentinelTotemCard::BeforeExile(CAbilityAction* pAction)
{
	ExileAllGraveyards(GetGame(), pAction->GetController());
	return true;
}

CShadowedCaravelCard::CShadowedCaravelCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Shadowed Caravel"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Whenever a creature you control explores, put a +1/+1 counter on this Vehicle. (listens to EXPLORE_TRIGGER_ID,
	// as AddWheneverYouExertTrigger in Hour of Devastation)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetTriggerIndex(EXPLORE_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(this));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShadowedCaravelCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());

	// Crew 2
	m_Crew.AddCrewAbility(2, _T("Shadowed Caravel (Vehicle)"), 64126);
}

// The counter goes on the Vehicle card (as Untethered Express in Aether Revolt)
bool CShadowedCaravelCard::BeforeCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
		pModifier.ApplyTo(this);
	}
	return true;
}

CSleekSchoonerCard::CSleekSchoonerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sleek Schooner"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Crew 1
	m_Crew.AddCrewAbility(1, _T("Sleek Schooner (Vehicle)"), 64127);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (sorceries)

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

//____________________________________________________________________________
//
// Sorceries

CBoneyardParleyCard::CBoneyardParleyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Boneyard Parley"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CBoneyardParleyCard::OnCardsChosen))
	, m_SeparateSelection(pGame, CSelectionSupport::SelectionCallback(this, &CBoneyardParleyCard::OnPileSeparated))
	, m_PileSelection(pGame, CSelectionSupport::SelectionCallback(this, &CBoneyardParleyCard::OnPileChosen))
{
	// Exile up to five target creature cards from graveyards. An opponent separates those cards into two piles. Put all
	// cards from the pile of your choice onto the battlefield under your control and the rest into their owners'
	// graveyards.
	// Note: the cards are chosen on resolution (not targeted); the piles as Unesh in Hour of Devastation
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBoneyardParleyCard::BeforeChoose));
	AddSpell(cpSpell.GetPointer());
}

bool CBoneyardParleyCard::BeforeChoose(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
		{
			CCard* pCard = pGraveyard->GetAt(i);
			if (pCard != this && pCard->GetCardType().IsCreature())
			{
				SelectionEntry entry;
				entry.dwContext = (DWORD)pCard;
				entry.cpAssociatedCard = pCard;
				entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
				entries.push_back(entry);
			}
		}
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, entries.size() < 5 ? (int)entries.size() : 5, this, pAction->GetController());
	return true;
}

// The chosen cards are exiled; an opponent chooses the cards of the first pile
void CBoneyardParleyCard::OnCardsChosen(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	std::vector<SelectionEntry> entries;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Graveyard)
				continue;

			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() != ZoneId::Exile)
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Put %s in the first pile"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}

	if (!entries.empty())
		m_SeparateSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this,
			GetGame()->GetNextPlayer(pSelectionPlayer), (DWORD)pSelectionPlayer);
}

// The caster (dwContext1) chooses the pile that goes onto the battlefield
void CBoneyardParleyCard::OnPileSeparated(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	m_Pile1.RemoveAll();
	m_Pile2.RemoveAll();

	CString strPile1, strPile2;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		CCountedCardContainer& pile = it->bSelected ? m_Pile1 : m_Pile2;
		CString& strPile = it->bSelected ? strPile1 : strPile2;
		pile.AddCard(pCard, CardPlacement::Top);
		if (!strPile.IsEmpty())
			strPile += _T(", ");
		strPile += pCard->GetCardName(TRUE);
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText.Format(_T("Put onto the battlefield: %s"), strPile1.IsEmpty() ? _T("(empty pile)") : (LPCTSTR)strPile1);
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 2;
		entry.strText.Format(_T("Put onto the battlefield: %s"), strPile2.IsEmpty() ? _T("(empty pile)") : (LPCTSTR)strPile2);
		entries.push_back(entry);
	}
	m_PileSelection.AddSelectionRequest(entries, 1, 1, this, (CPlayer*)dwContext1);
}

void CBoneyardParleyCard::OnPileChosen(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCountedCardContainer& battlefield = it->dwContext == 1 ? m_Pile1 : m_Pile2;
			CCountedCardContainer& graveyard = it->dwContext == 1 ? m_Pile2 : m_Pile1;

			// Under the caster's control
			CMoveCardModifier pToBattlefield = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, FALSE, MoveType::Others, pSelectionPlayer);
			for (int i = 0; i < battlefield.GetSize(); ++i)
				if (battlefield.GetAt(i)->GetZoneId() == ZoneId::Exile)
					pToBattlefield.ApplyTo(battlefield.GetAt(i));

			CMoveCardModifier pToGraveyard = CMoveCardModifier(ZoneId::Exile, ZoneId::Graveyard, TRUE, MoveType::Others);
			for (int i = 0; i < graveyard.GetSize(); ++i)
				if (graveyard.GetAt(i)->GetZoneId() == ZoneId::Exile)
					pToGraveyard.ApplyTo(graveyard.GetAt(i));
			break;
		}

	m_Pile1.RemoveAll();
	m_Pile2.RemoveAll();
}

CCallToTheFeastCard::CCallToTheFeastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Call to the Feast"), CardType::Sorcery, nID)
{
	// Create three 1/1 white Vampire creature tokens with lifelink.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT,
			VAMPIRE_E_TOKEN_NAME, VAMPIRE_E_TOKEN_ID,
			3));
	AddSpell(cpSpell.GetPointer());
}

CChartACourseCard::CChartACourseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chart a Course"), CardType::Sorcery, nID)
{
	// Draw two cards. Then discard a card unless you attacked this turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChartACourseCard::BeforeDraw));
	AddSpell(cpSpell.GetPointer());
}

bool CChartACourseCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 2);
	if (!HasRaid(pController))
		DiscardCards(GetGame(), pController, 1);
	return true;
}

CCommuneWithDinosaursCard::CCommuneWithDinosaursCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Commune with Dinosaurs"), CardType::Sorcery, nID)
	, m_LookFilter(_T("a Dinosaur or land card"), _T("Dinosaur or land cards"),
		new OrCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false), new CardTypeComparer(CardType::_Land, false)))
{
	// Look at the top five cards of your library. You may reveal a Dinosaur or land card from among them and put it
	// into your hand. Put the rest on the bottom of your library in any order.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCommuneWithDinosaursCard::BeforeLook));
	AddSpell(cpSpell.GetPointer());
}

bool CCommuneWithDinosaursCard::BeforeLook(CAbilityAction* pAction)
{
	LookTopToHand(GetGame(), pAction->GetController(), 5, &m_LookFilter);
	return true;
}

CContractKillingCard::CContractKillingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Contract Killing"), CardType::Sorcery, nID)
{
	// Destroy target creature. Create two Treasure tokens.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CContractKillingCard::BeforeTreasure));
	AddSpell(cpSpell.GetPointer());
}

bool CContractKillingCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 2);
	return true;
}

CEmergentGrowthCard::CEmergentGrowthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Emergent Growth"), CardType::Sorcery, nID)
{
	// Target creature gets +5/+5 until end of turn and must be blocked this turn if able.
	// Partial: it doesn't have to be blocked (there is no "must be blocked")
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmergentGrowthCard::BeforePump));
	AddSpell(cpSpell.GetPointer());
}

bool CEmergentGrowthCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +5, +5);
	return true;
}

CEntrancingMelodyCard::CEntrancingMelodyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Entrancing Melody"), CardType::Sorcery, nID)
{
	// Gain control of target creature with mana value X.
	// Note: any creature can be targeted; the control is gained only if its mana value is X
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEntrancingMelodyCard::BeforeControl));
	AddSpell(cpSpell.GetPointer());
}

bool CEntrancingMelodyCard::BeforeControl(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && (int)pCard->GetConvertedManaCost() == GetX(pAction))
	{
		CGainControlModifier pModifier = CGainControlModifier(GetGame(), this);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CFirecannonBlastCard::CFirecannonBlastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Firecannon Blast"), CardType::Sorcery, nID)
{
	// Firecannon Blast deals 3 damage to target creature.
	// Raid - Firecannon Blast deals 6 damage instead if you attacked this turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFirecannonBlastCard::BeforeDamage));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CFirecannonBlastCard::BeforeDamage(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CLifeModifier pModifier = CLifeModifier(Life(HasRaid(pAction->GetController()) ? -6 : -3), this,
			PreventableType::Preventable, DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

CGraspingCurrentCard::CGraspingCurrentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grasping Current"), CardType::Sorcery, nID)
{
	// Return up to two target creatures to their owner's hand. Search your library and/or graveyard for a card named
	// Jace, Ingenious Mind-Mage, reveal it, and put it into your hand. If you search your library this way, shuffle.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(0, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGraspingCurrentCard::BeforeSearch));
	AddSpell(cpSpell.GetPointer());
}

bool CGraspingCurrentCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Jace, Ingenious Mind-Mage"));
	return true;
}

CGrimCaptainsCallCard::CGrimCaptainsCallCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grim Captain's Call"), CardType::Sorcery, nID)
{
	// Return a Pirate card from your graveyard to your hand, then do the same for Vampire, Dinosaur, and Merfolk.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrimCaptainsCallCard::BeforeReturn));
	AddSpell(cpSpell.GetPointer());
}

bool CGrimCaptainsCallCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	SingleCreatureType types[] = { SingleCreatureType::Pirate, SingleCreatureType::Vampire, SingleCreatureType::Dinosaur, SingleCreatureType::Merfolk };
	LPCTSTR names[] = { _T("Pirate"), _T("Vampire"), _T("Dinosaur"), _T("Merfolk") };
	for (int t = 0; t < _countof(types); ++t)
	{
		CString strOne, strMany;
		strOne.Format(_T("a %s card"), names[t]);
		strMany.Format(_T("%s cards"), names[t]);
		CCardFilter filter(strOne, strMany, new CreatureTypeComparer(CreatureType(types[t]), false));
		if (filter.CountIncluded(pGraveyard->GetCardContainer()) == 0)
			continue;

		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // a card of that type
			CZoneModifier::RoleType::PrimaryPlayer,	// select by
			CZoneModifier::RoleType::AllPlayers,	// reveal to
			&filter,								// what cards
			ZoneId::Hand,							// if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top,
			MoveType::Others,						// move type
			CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.ApplyTo(pController);
	}
	return true;
}

CHeartlessPillageCard::CHeartlessPillageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Heartless Pillage"), CardType::Sorcery, nID)
{
	// Target opponent discards two cards.
	// Raid - If you attacked this turn, create a Treasure token.
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			2, MoveType::Discard, ZoneId::Graveyard, TRUE,
			TRUE,
			CCardFilter::GetFilter(_T("cards"))));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeartlessPillageCard::BeforeTreasure));
	AddSpell(cpSpell.GetPointer());
}

bool CHeartlessPillageCard::BeforeTreasure(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CLegionsJudgmentCard::CLegionsJudgmentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Legion's Judgment"), CardType::Sorcery, nID)
{
	// Destroy target creature with power 4 or greater.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") WHITE_MANA_TEXT,
			new CreaturePowerComparer<std::greater_equal<int>>(4),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CMarchOfTheDrownedCard::CMarchOfTheDrownedCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("March of the Drowned"), CardType::Sorcery, nID)
{
	// Choose one -
	{
		// Return target creature card from your graveyard to your hand.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->SetAbilityText(_T("Return target creature card from your graveyard to your hand. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Return two target Pirate cards from your graveyard to your hand.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT,
				new CreatureTypeComparer(CREATURE_TYPE(Pirate), false),
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetSubjectCount(2, 2);
		cpSpell->SetAbilityText(_T("Return two target Pirate cards from your graveyard to your hand. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

COverflowingInsightCard::COverflowingInsightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Overflowing Insight"), CardType::Sorcery, nID)
{
	// Target player draws seven cards.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COverflowingInsightCard::BeforeDraw));
	AddSpell(cpSpell.GetPointer());
}

bool COverflowingInsightCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		DrawCards(GetGame(), pPlayer, 7);
	return true;
}

CPiratesPrizeCard::CPiratesPrizeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pirate's Prize"), CardType::Sorcery, nID)
{
	// Draw two cards. Create a Treasure token.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(2), MaximumValue(2)));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPiratesPrizeCard::BeforeTreasure));
	AddSpell(cpSpell.GetPointer());
}

bool CPiratesPrizeCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CQueensCommissionCard::CQueensCommissionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Queen's Commission"), CardType::Sorcery, nID)
{
	// Create two 1/1 white Vampire creature tokens with lifelink.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("2") WHITE_MANA_TEXT,
			VAMPIRE_E_TOKEN_NAME, VAMPIRE_E_TOKEN_ID,
			2));
	AddSpell(cpSpell.GetPointer());
}

CRepeatingBarrageCard::CRepeatingBarrageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Repeating Barrage"), CardType::Sorcery, nID)
{
	{
		// Repeating Barrage deals 3 damage to any target.
		// Note: it can't target planeswalkers
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				_T("1") RED_MANA_TEXT RED_MANA_TEXT,
				new AnyCreatureComparer, TRUE,
				Life(-3), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Raid - {3}{R}{R}: Return this card from your graveyard to your hand. Activate only if you attacked this turn.
		// (a graveyard ability, as Embalm)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("3") RED_MANA_TEXT RED_MANA_TEXT));

		cpAbility->SetGraveyardOnly();
		cpAbility->SetAbilityText(_T("Raid: return this card from your graveyard to your hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRepeatingBarrageCard::BeforeReturn));
		AddPlayableIf(this, cpAbility.GetPointer(), &CRepeatingBarrageCard::HasRaidCondition);
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CRepeatingBarrageCard::HasRaidCondition(BOOL bIncludeTricks)
{
	return HasRaid(GetController());
}

bool CRepeatingBarrageCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(this);
	}
	return true;
}

CRileCard::CRileCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rile"), CardType::Sorcery, nID)
{
	// Rile deals 1 damage to target creature you control. That creature gains trample until end of turn. Draw a card.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRileCard::BeforeDamage));
	AddSpell(cpSpell.GetPointer());
}

bool CRileCard::BeforeDamage(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pCreature);
	PumpCreature(pCreature, +0, +0, CreatureKeyword::Trample);
	return true;
}

CRiversRebukeCard::CRiversRebukeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("River's Rebuke"), CardType::Sorcery, nID)
{
	// Return all nonland permanents target player controls to their owner's hand.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRiversRebukeCard::BeforeBounce));
	AddSpell(cpSpell.GetPointer());
}

bool CRiversRebukeCard::BeforeBounce(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return true;

	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer permanents;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (!pBattlefield->GetAt(i)->GetCardType().IsLand())
			permanents.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
	for (int i = 0; i < permanents.GetSize(); ++i)
		if (permanents.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(permanents.GetAt(i));
	return true;
}

CSavageStompCard::CSavageStompCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Savage Stomp"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on target creature you control. Then that creature fights target creature you don't control.
	// This spell costs {2} less to cast if it targets a Dinosaur you control. (a second spell for {G} whose first
	// target is a Dinosaur, as Prepare // Fight in Amonkhet for the targets)
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				i == 0 ? _T("2") GREEN_MANA_TEXT : GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		if (i == 1)
		{
			cpSpell->GetTargeting1()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false));
			cpSpell->SetAbilityText(_T("Savage Stomp targeting a Dinosaur you control. Casts"));
		}
		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSavageStompCard::BeforeFight));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CSavageStompCard::BeforeFight(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return false;

	CCard* pOwn = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pOther = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (pOwn && pOwn->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), 1);
		pModifier.ApplyTo(pOwn);
		Fight(pOwn, pOther);
	}
	return false;
}

CSpreadingRotCard::CSpreadingRotCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spreading Rot"), CardType::Sorcery, nID)
{
	// Destroy target land. Its controller loses 2 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("4") BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpreadingRotCard::BeforeLoseLife));
	AddSpell(cpSpell.GetPointer());
}

// The controller loses the life before the land is destroyed (the callback returns true: ResolveImpl destroys it)
bool CSpreadingRotCard::BeforeLoseLife(CAbilityAction* pAction)
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (pLand && pLand->GetZoneId() == ZoneId::Battlefield)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pLand->GetController());
	}
	return true;
}

CStarOfExtinctionCard::CStarOfExtinctionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Star of Extinction"), CardType::Sorcery, nID)
{
	// Destroy target land. Star of Extinction deals 20 damage to each creature and each planeswalker.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("5") RED_MANA_TEXT RED_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStarOfExtinctionCard::BeforeDamage));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

// The land is destroyed by the callback first, then the damage (the damage to a planeswalker removes loyalty counters)
bool CStarOfExtinctionCard::BeforeDamage(CAbilityAction* pAction)
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (pLand && pLand->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		pModifier.ApplyTo(pLand);
	}

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-20), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
	}

	CCountedCardContainer planeswalkers;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (dynamic_cast<CPlaneswalkerCard*>(pBattlefield->GetAt(i)))
				planeswalkers.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}
	CCardCounterModifier pLoyalty = CCardCounterModifier(LOYALTY_COUNTER, -20);
	for (int i = 0; i < planeswalkers.GetSize(); ++i)
		pLoyalty.ApplyTo(planeswalkers.GetAt(i));
	return false;
}

CSwordPointDiplomacyCard::CSwordPointDiplomacyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sword-Point Diplomacy"), CardType::Sorcery, nID)
	, m_PaySelection(pGame, CSelectionSupport::SelectionCallback(this, &CSwordPointDiplomacyCard::OnPaid))
{
	// Reveal the top three cards of your library. For each of those cards, put that card into your hand unless any
	// opponent pays 3 life. Then exile the rest.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSwordPointDiplomacyCard::BeforeReveal));
	AddSpell(cpSpell.GetPointer());
}

// The opponent chooses the cards they pay 3 life for (dwContext1: the caster)
bool CSwordPointDiplomacyCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	int nCount = pLibrary->GetSize() < 3 ? pLibrary->GetSize() : 3;
	if (nCount <= 0)
		return true;

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < nCount; ++i)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1 - i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Pay 3 life so %s is exiled"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_PaySelection.AddSelectionRequest(entries, 0, nCount, this, GetGame()->GetNextPlayer(pController), (DWORD)pController);
	return true;
}

void CSwordPointDiplomacyCard::OnPaid(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pCaster = (CPlayer*)dwContext1;
	CMoveCardModifier pToHand = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others);
	CMoveCardModifier pToExile = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others, pCaster);
	CLifeModifier pPay = CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Library)
			continue;

		if (it->bSelected)
		{
			pPay.ApplyTo(pSelectionPlayer);
			pToExile.ApplyTo(pCard);
		}
		else
			pToHand.ApplyTo(pCard);
	}
}

CWalkThePlankCard::CWalkThePlankCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Walk the Plank"), CardType::Sorcery, nID)
{
	// Destroy target non-Merfolk creature.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(
		new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false)));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (instants)

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

//____________________________________________________________________________
//
// Instants

CBlindingFogCard::CBlindingFogCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blinding Fog"), CardType::Instant, nID)
{
	// Prevent all damage that would be dealt to creatures this turn. Creatures you control gain hexproof until end of
	// turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlindingFogCard::BeforeFog));
	AddSpell(cpSpell.GetPointer());
}

// The prevention is a player effect of each player until the cleanup step (as Safe Passage in M10)
bool CBlindingFogCard::BeforeFog(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CPlayerEffectModifier pEffect = CPlayerEffectModifier(PlayerEffectType::PreventAllDamageToCreatures);
		CScheduledPlayerModifier pRemove = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::PreventAllDamageToCreatures),
			TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::RemoveFromLater);
		pEffect.ApplyTo(pPlayer);
		pRemove.ApplyTo(pPlayer);
	}

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		GainCardKeyword(creatures.GetAt(i), CardKeyword::Hexproof);
	return true;
}

CBrightReprisalCard::CBrightReprisalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bright Reprisal"), CardType::Instant, nID)
{
	// Destroy target attacking creature. Draw a card.
	CTargetMoveCardSpell* pSpell = AddDestroySpell(this, _T("4") WHITE_MANA_TEXT, new AttackingCreatureComparer);
	pSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
}

CCostlyPlunderCard::CCostlyPlunderCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Costly Plunder"), CardType::Instant, nID)
	, m_SacrificeFilter(_T("an artifact or creature"), _T("artifacts or creatures"),
		new CardTypeComparer(CardType::Artifact | CardType::Creature, false))
{
	// As an additional cost to cast this spell, sacrifice an artifact or creature. Draw two cards.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT));

	cpSpell->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(2), MaximumValue(2)));
	AddSpell(cpSpell.GetPointer());
}

CCrashTheRampartsCard::CCrashTheRampartsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Crash the Ramparts"), CardType::Instant, nID)
{
	// Target creature gets +3/+3 and gains trample until end of turn.
	AddCreatureSpell(this, _T("2") GREEN_MANA_TEXT, FALSE, &CCrashTheRampartsCard::BeforePump);
}

bool CCrashTheRampartsCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +3, +3, CreatureKeyword::Trample);
	return true;
}

CCrushingCanopyCard::CCrushingCanopyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Crushing Canopy"), CardType::Instant, nID)
{
	// Choose one -
	// Destroy target creature with flying.
	CTargetMoveCardSpell* pSpell1 = AddDestroySpell(this, _T("2") GREEN_MANA_TEXT,
		new CreatureKeywordComparer(CreatureKeyword::Flying, false));
	pSpell1->SetAbilityText(_T("Destroy target creature with flying. Casts"));

	// Destroy target enchantment.
	CTargetMoveCardSpell* pSpell2 = AddDestroySpell(this, _T("2") GREEN_MANA_TEXT,
		new CardTypeComparer(CardType::_Enchantment, false));
	pSpell2->SetAbilityText(_T("Destroy target enchantment. Casts"));
}

CDarkNourishmentCard::CDarkNourishmentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dark Nourishment"), CardType::Instant, nID)
{
	// Dark Nourishment deals 3 damage to any target. You gain 3 life.
	CTargetChgLifeSpell* pSpell = AddDamageSpell(this, _T("4") BLACK_MANA_TEXT, 3, new AnyCreatureComparer, TRUE);
	pSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	pSpell->AddAbilityTag(AbilityTag::LifeGain);
}

CDepthsOfDesireCard::CDepthsOfDesireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Depths of Desire"), CardType::Instant, nID)
{
	// Return target creature to its owner's hand. Create a Treasure token.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDepthsOfDesireCard::BeforeTreasure));
	AddSpell(cpSpell.GetPointer());
}

bool CDepthsOfDesireCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CDinosaurStampedeCard::CDinosaurStampedeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dinosaur Stampede"), CardType::Instant, nID)
{
	// Attacking creatures get +2/+0 until end of turn. Dinosaurs you control gain trample until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDinosaurStampedeCard::BeforePump));
	AddSpell(cpSpell.GetPointer());
}

bool CDinosaurStampedeCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	CreatureTypeComparer dinosaurs(CREATURE_TYPE(Dinosaur), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (pCreature->IsAttacking())
			PumpCreature(pCreature, +2, +0);
		if (pCreature->GetController() == pAction->GetController() && dinosaurs(pCreature))
			PumpCreature(pCreature, +0, +0, CreatureKeyword::Trample);
	}
	return true;
}

CDiveDownCard::CDiveDownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dive Down"), CardType::Instant, nID)
{
	// Target creature you control gets +0/+3 and gains hexproof until end of turn.
	AddCreatureSpell(this, BLUE_MANA_TEXT, TRUE, &CDiveDownCard::BeforePump);
}

bool CDiveDownCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +0, +3);
	GainCardKeyword(pAction->GetAssociatedCard(), CardKeyword::Hexproof);
	return true;
}

CFieryCannonadeCard::CFieryCannonadeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fiery Cannonade"), CardType::Instant, nID)
{
	// Fiery Cannonade deals 2 damage to each non-Pirate creature.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFieryCannonadeCard::BeforeDamage));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CFieryCannonadeCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	CreatureTypeComparer pirates(CREATURE_TYPE(Pirate), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (!pirates(creatures.GetAt(i)) && creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
				DamageType::SpellDamage | DamageType::NonCombatDamage);
			pModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
		}
	return true;
}

CHuatlisSpurringCard::CHuatlisSpurringCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Huatli's Spurring"), CardType::Instant, nID)
{
	// Target creature gets +2/+0 until end of turn. If you control a Huatli planeswalker, that creature gets +4/+0
	// until end of turn instead.
	AddCreatureSpell(this, RED_MANA_TEXT, FALSE, &CHuatlisSpurringCard::BeforePump);
}

bool CHuatlisSpurringCard::BeforePump(CAbilityAction* pAction)
{
	CCardFilter huatli(_T("a Huatli planeswalker"), _T("Huatli planeswalkers"), new PlaneswalkerTypeComparer(PlaneswalkerType::Huatli));
	BOOL bHuatli = huatli.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
	PumpCreature(pAction->GetAssociatedCard(), bHuatli ? +4 : +2, +0);
	return true;
}

CLookoutsDispersalCard::CLookoutsDispersalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lookout's Dispersal"), CardType::Instant, nID)
{
	// Counter target spell unless its controller pays {4}.
	// This spell costs {1} less to cast if you control a Pirate. (a second spell for {1}{U}, as Hour of Revelation)
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				i == 0 ? _T("2") BLUE_MANA_TEXT : _T("1") BLUE_MANA_TEXT,
				new TrueCardComparer));

		cpSpell->SetCanBeDenied();
		cpSpell->GetDenialCost().SetManaCost(_T("4"));
		if (i == 1)
		{
			cpSpell->SetAbilityText(_T("Lookout's Dispersal (costs {1} less: you control a Pirate). Casts"));
			AddPlayableIf(this, cpSpell.GetPointer(), &CLookoutsDispersalCard::ControlsPirate);
		}
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CLookoutsDispersalCard::ControlsPirate(BOOL bIncludeTricks)
{
	CCardFilter pirates(_T("a Pirate"), _T("Pirates"), new CreatureTypeComparer(CREATURE_TYPE(Pirate), false));
	return pirates.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

CPerilousVoyageCard::CPerilousVoyageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Perilous Voyage"), CardType::Instant, nID)
{
	// Return target nonland permanent you don't control to its owner's hand. If its mana value was 2 or less, scry 2.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPerilousVoyageCard::BeforeScry));
	AddSpell(cpSpell.GetPointer());
}

// The callback bounces the permanent itself (to know its mana value) and returns false
bool CPerilousVoyageCard::BeforeScry(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	int nManaValue = (int)pCard->GetConvertedManaCost();
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(pCard);

	if (nManaValue <= 2)
	{
		CScryModifier pScry = CScryModifier(GetGame(), 2, this);
		pScry.ApplyTo(pAction->GetController());
	}
	return false;
}

CPounceCard::CPounceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pounce"), CardType::Instant, nID)
{
	// Target creature you control fights target creature you don't control. (as Prepare // Fight in Amonkhet)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPounceCard::BeforeFight));
	AddSpell(cpSpell.GetPointer());
}

bool CPounceCard::BeforeFight(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (pDoubleTargetAction)
		Fight((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
			(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject());
	return false;
}

CRallyingRoarCard::CRallyingRoarCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rallying Roar"), CardType::Instant, nID)
{
	// Creatures you control get +1/+1 until end of turn. Untap them.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRallyingRoarCard::BeforePump));
	AddSpell(cpSpell.GetPointer());
}

bool CRallyingRoarCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CCardOrientationModifier pUntap = CCardOrientationModifier(FALSE);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		PumpCreature(creatures.GetAt(i), +1, +1);
		if (creatures.GetAt(i)->GetOrientation()->IsTapped())
			pUntap.ApplyTo(creatures.GetAt(i));
	}
	return true;
}

CRitualOfRejuvenationCard::CRitualOfRejuvenationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ritual of Rejuvenation"), CardType::Instant, nID)
{
	// You gain 4 life. Draw a card.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+4), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

CRiverHeraldsBoonCard::CRiverHeraldsBoonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("River Heralds' Boon"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on target creature and a +1/+1 counter on up to one target Merfolk.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false), FALSE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetSubjectCount(0, 1);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRiverHeraldsBoonCard::BeforeCounters));
	AddSpell(cpSpell.GetPointer());
}

bool CRiverHeraldsBoonCard::BeforeCounters(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return false;

	CCard* pTargets[] = { (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
		(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject() };
	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), 1);
	for (int i = 0; i < _countof(pTargets); ++i)
		if (pTargets[i] && pTargets[i]->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(pTargets[i]);
	return false;
}

CRunAgroundCard::CRunAgroundCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Run Aground"), CardType::Instant, nID)
{
	// Put target artifact or creature on top of its owner's library. (as Commit in Amonkhet)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature, false),
			ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CSanguineSacramentCard::CSanguineSacramentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sanguine Sacrament"), CardType::Instant, nID)
{
	// You gain twice X life. Put Sanguine Sacrament on the bottom of its owner's library.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetToZoneIfSuccess(ZoneId::Library, TRUE, CardPlacement::Bottom);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSanguineSacramentCard::BeforeGainLife));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CSanguineSacramentCard::BeforeGainLife(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0)
		GainLife(this, pAction->GetController(), 2 * nX);
	return true;
}

CSettleTheWreckageCard::CSettleTheWreckageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Settle the Wreckage"), CardType::Instant, nID)
{
	// Exile all attacking creatures target player controls. That player may search their library for that many basic
	// land cards, put those cards onto the battlefield tapped, then shuffle.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSettleTheWreckageCard::BeforeExile));
	AddSpell(cpSpell.GetPointer());
}

bool CSettleTheWreckageCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return true;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pPlayer, TRUE, creatures);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	int nExiled = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (!pCreature->IsAttacking())
			continue;

		pModifier.ApplyTo(pCreature);
		if (pCreature->GetZoneId() != ZoneId::Battlefield)
			++nExiled;
	}

	if (nExiled > 0)
		SearchToBattlefield(GetGame(), pPlayer, nExiled, CCardFilter::GetFilter(_T("basic lands")), TRUE);
	return true;
}

CShelteringLightCard::CShelteringLightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sheltering Light"), CardType::Instant, nID)
{
	// Target creature gains indestructible until end of turn. Scry 1.
	CTargetSpell* pSpell = AddCreatureSpell(this, WHITE_MANA_TEXT, FALSE, &CShelteringLightCard::BeforeIndestructible);
	pSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(pGame, 1, this));
}

bool CShelteringLightCard::BeforeIndestructible(CAbilityAction* pAction)
{
	GainCardKeyword(pAction->GetAssociatedCard(), CardKeyword::Indestructible);
	return true;
}

CSirensRuseCard::CSirensRuseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Siren's Ruse"), CardType::Instant, nID)
{
	// Exile target creature you control, then return that card to the battlefield under its owner's control. If a
	// Pirate was exiled this way, draw a card.
	AddCreatureSpell(this, _T("1") BLUE_MANA_TEXT, TRUE, &CSirensRuseCard::BeforeFlicker);
}

bool CSirensRuseCard::BeforeFlicker(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	BOOL bPirate = CreatureTypeComparer(CREATURE_TYPE(Pirate), false)(pCard);
	BOOL bToken = pCard->GetCardType().IsToken();

	CMoveCardModifier pExile = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pExile.ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Exile && !bToken)
		return true;

	if (!bToken)
	{
		CMoveCardModifier pReturn = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pAction->GetController());
		pReturn.ApplyTo(pCard);
	}
	if (bPirate)
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSkulduggeryCard::CSkulduggeryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Skulduggery"), CardType::Instant, nID)
{
	// Until end of turn, target creature you control gets +1/+1 and target creature an opponent controls gets -1/-1.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkulduggeryCard::BeforePump));
	AddSpell(cpSpell.GetPointer());
}

bool CSkulduggeryCard::BeforePump(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return false;

	PumpCreature((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(), +1, +1);
	PumpCreature((CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject(), -1, -1);
	return false;
}

CSlashOfTalonsCard::CSlashOfTalonsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Slash of Talons"), CardType::Instant, nID)
{
	// Slash of Talons deals 2 damage to target attacking or blocking creature.
	AddDamageSpell(this, WHITE_MANA_TEXT, 2, new AttackingBlockingCreatureComparer, FALSE);
}

CSpellSwindleCard::CSpellSwindleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spell Swindle"), CardType::Instant, nID)
{
	// Counter target spell. Create X Treasure tokens, where X is that spell's mana value.
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpellSwindleCard::BeforeTreasure));
	AddSpell(cpSpell.GetPointer());
}

// (the target of a counterspell, as Hydroblast in Fifth Edition)
bool CSpellSwindleCard::BeforeTreasure(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	int nX = pCard ? (int)pCard->GetConvertedManaCost() : 0;
	if (nX > 0)
		CreateTreasure(GetGame(), pAction->GetController(), nX);
	return true;
}

CUnfriendlyFireCard::CUnfriendlyFireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unfriendly Fire"), CardType::Instant, nID)
{
	// Unfriendly Fire deals 4 damage to any target.
	AddDamageSpell(this, _T("4") RED_MANA_TEXT, 4, new AnyCreatureComparer, TRUE);
}

CVampiresZealCard::CVampiresZealCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vampire's Zeal"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 until end of turn. If it's a Vampire, it gains first strike until end of turn.
	AddCreatureSpell(this, WHITE_MANA_TEXT, FALSE, &CVampiresZealCard::BeforePump);
}

bool CVampiresZealCard::BeforePump(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	BOOL bVampire = pCard && CreatureTypeComparer(CREATURE_TYPE(Vampire), false)(pCard);
	PumpCreature(pCard, +2, +2, bVampire ? CreatureKeyword::FirstStrike : CreatureKeyword::Null);
	return true;
}

CVanquishTheWeakCard::CVanquishTheWeakCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vanquish the Weak"), CardType::Instant, nID)
{
	// Destroy target creature with power 3 or less.
	AddDestroySpell(this, _T("2") BLACK_MANA_TEXT, new CreaturePowerComparer<std::less_equal<int>>(3));
}

CVerdantRebirthCard::CVerdantRebirthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Verdant Rebirth"), CardType::Instant, nID)
	, m_pMarked(NULL)
	, m_nMarkedTurn(-1)
{
	{
		// Until end of turn, target creature gains "When this creature dies, return it to its owner's hand." Draw a
		// card. (the trigger is of this card, in any zone, as Life Goes On in Hour of Devastation)
		CTargetSpell* pSpell = AddCreatureSpell(this, _T("1") GREEN_MANA_TEXT, FALSE, &CVerdantRebirthCard::BeforeMark);
		pSpell->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard, FALSE, TRUE, FALSE));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVerdantRebirthCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVerdantRebirthCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVerdantRebirthCard::BeforeMark(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		m_pMarked = pCard;
		m_nMarkedTurn = GetGame()->GetGameTurnNumber();
	}
	return true;
}

bool CVerdantRebirthCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && pCard == m_pMarked && m_nMarkedTurn == GetGame()->GetGameTurnNumber();
}

bool CVerdantRebirthCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = m_pMarked;
	m_pMarked = NULL;
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CVraskasContemptCard::CVraskasContemptCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Vraska's Contempt"), CardType::Instant, nID)
{
	// Exile target creature or planeswalker. You gain 2 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false),
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (creatures)

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

//____________________________________________________________________________
//
// White creatures

CAdantoVanguardCard::CAdantoVanguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Adanto Vanguard"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1))
{
	// As long as this creature is attacking, it gets +2/+0.
	// Note: it gets +2/+0 until end of turn when it attacks
	AddSelfAttackTrigger(this, &CAdantoVanguardCard::BeforeAttackBonus);

	// Pay 4 life: This creature gains indestructible until end of turn.
	AddPayLifeKeywordAbility(this, 4, _T("Pay 4 life: this creature gains indestructible until end of turn. Activates"),
		&CAdantoVanguardCard::BeforeIndestructible);
}

bool CAdantoVanguardCard::BeforeAttackBonus(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +0);
	return true;
}

bool CAdantoVanguardCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCardKeyword()->AddIndestructible(TRUE);
	return true;
}

CBellowingAegisaurCard::CBellowingAegisaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bellowing Aegisaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("5") WHITE_MANA_TEXT, Power(3), Life(5))
{
	// Enrage - Whenever this creature is dealt damage, put a +1/+1 counter on each other creature you control.
	AddEnrageTrigger(this, &CBellowingAegisaurCard::SetEnrageContext, &CBellowingAegisaurCard::BeforeCounters);
}

bool CBellowingAegisaurCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CBellowingAegisaurCard::BeforeCounters(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), 1);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CBishopOfRebirthCard::CBishopOfRebirthCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bishop of Rebirth"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(4))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Whenever this creature attacks, you may return target creature card with mana value 3 or less from your
	// graveyard to the battlefield. (as Mortuary Mire in Battle for Zendikar)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(3));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Battlefield));
	AddAbility(cpAbility.GetPointer());
}

CBishopsSoldierCard::CBishopsSoldierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bishop's Soldier"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

CDuskborneSkymarcherCard::CDuskborneSkymarcherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Duskborne Skymarcher"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// {W}, {T}: Target attacking Vampire gets +1/+1 until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			WHITE_MANA_TEXT,
			new AttackingCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDuskborneSkymarcherCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CDuskborneSkymarcherCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +1, +1);
	return true;
}

CEmissaryOfSunriseCard::CEmissaryOfSunriseCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emissary of Sunrise"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Explore(this)
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CEncampmentKeeperCard::CEncampmentKeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Encampment Keeper"), CardType::Creature, CREATURE_TYPE(Dog), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// {7}{W}, {T}, Sacrifice this creature: Creatures you control get +2/+2 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("7") WHITE_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Creatures you control get +2/+2 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEncampmentKeeperCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CEncampmentKeeperCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +2, +2);
	return true;
}

CGlorifierOfDuskCard::CGlorifierOfDuskCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glorifier of Dusk"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Pay 2 life: This creature gains flying until end of turn.
	AddPayLifeKeywordAbility(this, 2, _T("Pay 2 life: this creature gains flying until end of turn. Activates"),
		&CGlorifierOfDuskCard::BeforeFlying);

	// Pay 2 life: This creature gains vigilance until end of turn.
	AddPayLifeKeywordAbility(this, 2, _T("Pay 2 life: this creature gains vigilance until end of turn. Activates"),
		&CGlorifierOfDuskCard::BeforeVigilance);
}

bool CGlorifierOfDuskCard::BeforeFlying(CAbilityAction* pAction)
{
	PumpCreature(this, +0, +0, CreatureKeyword::Flying);
	return true;
}

bool CGlorifierOfDuskCard::BeforeVigilance(CAbilityAction* pAction)
{
	PumpCreature(this, +0, +0, CreatureKeyword::Vigilance);
	return true;
}

CGoringCeratopsCard::CGoringCeratopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goring Ceratops"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Double strike
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// Whenever this creature attacks, other creatures you control gain double strike until end of turn.
	AddSelfAttackTrigger(this, &CGoringCeratopsCard::BeforeDoubleStrike);
}

bool CGoringCeratopsCard::BeforeDoubleStrike(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			PumpCreature(creatures.GetAt(i), +0, +0, CreatureKeyword::DoubleStrike);
	return true;
}

CHuatlisSnubhornCard::CHuatlisSnubhornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Huatli's Snubhorn"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CImperialAerosaurCard::CImperialAerosaurCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Imperial Aerosaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, another target creature you control gets +1/+1 and gains flying until end of turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CImperialAerosaurCard::BeforePump, false, Characteristic::Positive);
	pTargeting->SetIncludeControllerCardsOnly();
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CImperialAerosaurCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +1, +1, CreatureKeyword::Flying);
	return false;
}

CImperialLancerCard::CImperialLancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Imperial Lancer"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// This creature has double strike as long as you control a Dinosaur.
	AddDinosaurKeyword(this, CreatureKeyword::DoubleStrike);
}

CInspiringClericCard::CInspiringClericCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inspiring Cleric"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you gain 4 life.
	AddEnterTrigger(this, &CInspiringClericCard::BeforeGainLife);
}

bool CInspiringClericCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 4);
	return true;
}

CKinjallisCallerCard::CKinjallisCallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kinjalli's Caller"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT, Power(0), Life(3))
{
	// Dinosaur spells you cast cost {1} less to cast. (as the Monuments in Amonkhet)
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CKinjallisSunwingCard::CKinjallisSunwingCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kinjalli's Sunwing"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Creatures your opponents control enter tapped. (as Kismet in Fourth Edition)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::InPlayTapped,
			(int)CCardFilter::GetFilter(_T("creatures"))));

	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());
}

CLegionConquistadorCard::CLegionConquistadorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Legion Conquistador"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_NameFilter(_T("a card named Legion Conquistador"), _T("cards named Legion Conquistador"),
		new CardNameComparer(_T("Legion Conquistador")))
{
	// When this creature enters, you may search your library for any number of cards named Legion Conquistador,
	// reveal them, put them into your hand, then shuffle.
	AddEnterTrigger(this, &CLegionConquistadorCard::BeforeSearch, true);
}

bool CLegionConquistadorCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = m_NameFilter.CountIncluded(pController->GetZoneById(ZoneId::Library)->GetCardContainer());
	if (nCount > 0)
	{
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(0), MaximumValue(nCount), // any number of them
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::AllPlayers, // reveal to
			&m_NameFilter, // what cards
			ZoneId::Hand, // if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top, // placement
			MoveType::Others, // move type
			CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
		pModifier.ApplyTo(pController);
	}
	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CLoomingAltisaurCard::CLoomingAltisaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Looming Altisaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") WHITE_MANA_TEXT, Power(1), Life(7))
{
}

CMavrenFeinDuskApostleCard::CMavrenFeinDuskApostleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mavren Fein, Dusk Apostle"), CardType::_LegendaryCreature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever one or more nontoken Vampires you control attack, create a 1/1 white Vampire creature token with
	// lifelink. (a trigger after the attackers are declared, as Legion's Landing)
	AddStepTrigger(this, NodeId::DeclareAttackersStep2, false, &CMavrenFeinDuskApostleCard::SetTriggerContext, &CMavrenFeinDuskApostleCard::BeforeToken);
}

bool CMavrenFeinDuskApostleCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	if (GetZoneId() != ZoneId::Battlefield)
		return false;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);
	CreatureTypeComparer vampires(CREATURE_TYPE(Vampire), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (pCreature->IsAttacking() && !pCreature->GetCardType().IsToken() && vampires(pCreature))
			return true;
	}
	return false;
}

bool CMavrenFeinDuskApostleCard::BeforeToken(CAbilityAction* pAction)
{
	CreateVampire(GetGame(), pAction->GetController(), 1);
	return true;
}

CPaladinOfTheBloodstainedCard::CPaladinOfTheBloodstainedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Paladin of the Bloodstained"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, create a 1/1 white Vampire creature token with lifelink.
	AddEnterTrigger(this, &CPaladinOfTheBloodstainedCard::BeforeToken);
}

bool CPaladinOfTheBloodstainedCard::BeforeToken(CAbilityAction* pAction)
{
	CreateVampire(GetGame(), pAction->GetController(), 1);
	return true;
}

CPriestOfTheWakeningSunCard::CPriestOfTheWakeningSunCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Priest of the Wakening Sun"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
	, m_DinosaurFilter(_T("a Dinosaur card"), _T("Dinosaur cards"), new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false))
{
	// At the beginning of your upkeep, you may reveal a Dinosaur card from your hand. If you do, you gain 2 life.
	// Note: it doesn't reveal the card
	AddStepTrigger(this, NodeId::UpkeepStep, true, &CPriestOfTheWakeningSunCard::SetTriggerContext, &CPriestOfTheWakeningSunCard::BeforeGainLife);

	// {3}{W}{W}, Sacrifice this creature: Search your library for a Dinosaur card, reveal it, put it into your hand,
	// then shuffle.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Search your library for a Dinosaur card and put it into your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPriestOfTheWakeningSunCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CPriestOfTheWakeningSunCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return m_DinosaurFilter.CountIncluded(GetController()->GetZoneById(ZoneId::Hand)->GetCardContainer()) > 0;
}

bool CPriestOfTheWakeningSunCard::BeforeGainLife(CAbilityAction* pAction)
{
	if (m_DinosaurFilter.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Hand)->GetCardContainer()) > 0)
		GainLife(this, pAction->GetController(), 2);
	return true;
}

bool CPriestOfTheWakeningSunCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a Dinosaur card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		&m_DinosaurFilter, // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CPterodonKnightCard::CPterodonKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pterodon Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// This creature has flying as long as you control a Dinosaur.
	AddDinosaurKeyword(this, CreatureKeyword::Flying);
}

CRaptorCompanionCard::CRaptorCompanionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Raptor Companion"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
{
}

CShiningAerosaurCard::CShiningAerosaurCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shining Aerosaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
}

CSkybladeOfTheLegionCard::CSkybladeOfTheLegionCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skyblade of the Legion"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(3))
{
}

CSteadfastArmasaurCard::CSteadfastArmasaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steadfast Armasaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// {1}{W}, {T}: This creature deals damage equal to its toughness to target creature blocking or blocked by it.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") WHITE_MANA_TEXT,
			new AttackingBlockingThisCreatureComparer(this), FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSteadfastArmasaurCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CSteadfastArmasaurCard::BeforeDamage(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		DealDamageToCreature(this, pAction->GetAssociatedCard(), (int)GetToughness());
	return true;
}

CSunriseSeekerCard::CSunriseSeekerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sunrise Seeker"), CardType::Creature, CREATURE_TYPE2(Human, Scout), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
	, m_Explore(this)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CTerritorialHammerskullCard::CTerritorialHammerskullCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Territorial Hammerskull"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Whenever this creature attacks, tap target creature an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTerritorialHammerskullCard::BeforeTap));
	AddAbility(cpAbility.GetPointer());
}

bool CTerritorialHammerskullCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CWakeningSunsAvatarCard::CWakeningSunsAvatarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wakening Sun's Avatar"), CardType::Creature, CREATURE_TYPE2(Dinosaur, Avatar), nID,
		_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(7), Life(7))
{
	// When this creature enters, if you cast it from your hand, destroy all non-Dinosaur creatures.
	// (it enters from the stack: cast from the hand, or from other zones)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Stack, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWakeningSunsAvatarCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CWakeningSunsAvatarCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	CreatureTypeComparer dinosaurs(CREATURE_TYPE(Dinosaur), false);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (!dinosaurs(creatures.GetAt(i)) && creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (green creatures)

#define ELEMENTAL_AW_TOKEN_NAME	_T("Elemental (AW)")
#define ELEMENTAL_AW_TOKEN_ID	64128

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

//____________________________________________________________________________
//
// Green creatures

CAncientBrontodonCard::CAncientBrontodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ancient Brontodon"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("6") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(9), Life(9))
{
}

CAtzocanArcherCard::CAtzocanArcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Atzocan Archer"), CardType::Creature, CREATURE_TYPE2(Human, Archer), nID,
		_T("2") GREEN_MANA_TEXT, Power(1), Life(4))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// When this creature enters, you may have it fight another target creature.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CAtzocanArcherCard::BeforeFight, true, Characteristic::Negative);
	pTargeting->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
}

bool CAtzocanArcherCard::BeforeFight(CAbilityAction* pAction)
{
	Fight(this, pAction->GetAssociatedCard());
	return false;
}

CBlossomDryadCard::CBlossomDryadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blossom Dryad"), CardType::Creature, CREATURE_TYPE(Dryad), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {T}: Untap target land.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new CardTypeComparer(CardType::_Land, false), FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
	AddAbility(cpAbility.GetPointer());
}

CCarnageTyrantCard::CCarnageTyrantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Carnage Tyrant"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(6))
{
	// This spell can't be countered. (as Dragons of Tarkir)
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Trample, hexproof
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCardKeyword()->AddHexproof(FALSE);
}

CColossalDreadmawCard::CColossalDreadmawCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Colossal Dreadmaw"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);
}

CDeathgorgeScavengerCard::CDeathgorgeScavengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deathgorge Scavenger"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// Whenever this creature enters or attacks, you may exile target card from a graveyard. If a creature card is
	// exiled this way, you gain 2 life. If a noncreature card is exiled this way, this creature gets +1/+1 until end of
	// turn.
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeathgorgeScavengerCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
									 CWhenSelfAttackedBlocked::AttackEventCallback,
									 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeathgorgeScavengerCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDeathgorgeScavengerCard::BeforeExile(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;

	BOOL bCreature = pCard->GetCardType().IsCreature();
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(pCard);
	if (pCard->GetZoneId() != ZoneId::Exile)
		return false;

	if (bCreature)
		GainLife(this, pAction->GetController(), 2);
	else
		PumpCreature(this, +1, +1);
	return false;
}

CDeeprootChampionCard::CDeeprootChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deeproot Champion"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever you cast a noncreature spell, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeeprootChampionCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CDeeprootChampionCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

CDeeprootWarriorCard::CDeeprootWarriorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deeproot Warrior"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature becomes blocked, it gets +1/+1 until end of turn. (as Slate Street Ruffian in Gatecrash)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockedEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeeprootWarriorCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CDeeprootWarriorCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

CDroverOfTheMightyCard::CDroverOfTheMightyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Drover of the Mighty"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(1))
{
	{
		// This creature gets +2/+2 as long as you control a Dinosaur.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new SpecificCardComparer(this),
				Power(+2), Life(+2)));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false));
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(1);
		AddAbility(cpAbility.GetPointer());
	}

	// {T}: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
		AddTapManaAbility(this, colors[i]);
}

CEmperorsVanguardCard::CEmperorsVanguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emperor's Vanguard"), CardType::Creature, CREATURE_TYPE2(Human, Scout), nID,
		_T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
	// Whenever this creature deals combat damage to a player, it explores.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmperorsVanguardCard::BeforeExplore));
	AddAbility(cpAbility.GetPointer());
}

bool CEmperorsVanguardCard::BeforeExplore(CAbilityAction* pAction)
{
	CExploreSupport::Explore(this);
	return true;
}

CGrazingWhiptailCard::CGrazingWhiptailCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grazing Whiptail"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);
}

CIxallisDivinerCard::CIxallisDivinerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ixalli's Diviner"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(0), Life(3))
	, m_Explore(this)
{
	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CIxallisKeeperCard::CIxallisKeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ixalli's Keeper"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {7}{G}, {T}, Sacrifice this creature: Target creature gets +5/+5 and gains trample until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("7") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIxallisKeeperCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CIxallisKeeperCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +5, +5, CreatureKeyword::Trample);
	return true;
}

CJadeGuardianCard::CJadeGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jade Guardian"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);

	// When this creature enters, put a +1/+1 counter on target Merfolk you control.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CJadeGuardianCard::BeforeCounter, false, Characteristic::Positive);
	pTargeting->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	pTargeting->SetIncludeControllerCardsOnly();
}

bool CJadeGuardianCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(pAction->GetAssociatedCard());
	return false;
}

CJungleDelverCard::CJungleDelverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jungle Delver"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// {3}{G}: Put a +1/+1 counter on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") GREEN_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJungleDelverCard::BeforeCounter));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CJungleDelverCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

CKumenasSpeakerCard::CKumenasSpeakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kumena's Speaker"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// This creature gets +1/+1 as long as you control another Merfolk or an Island.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+1)));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new OrCardComparer(
		new CardTypeComparer(CardType::Island, false),
		new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false), new NegateCardComparer(new SpecificCardComparer(this)))));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CMerfolkBranchwalkerCard::CMerfolkBranchwalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merfolk Branchwalker"), CardType::Creature, CREATURE_TYPE2(Merfolk, Scout), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1))
	, m_Explore(this)
{
	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

COldGrowthDryadsCard::COldGrowthDryadsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Old-Growth Dryads"), CardType::Creature, CREATURE_TYPE(Dryad), nID,
		GREEN_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, each opponent may search their library for a basic land card, put it onto the
	// battlefield tapped, then shuffle.
	AddEnterTrigger(this, &COldGrowthDryadsCard::BeforeSearch);
}

bool COldGrowthDryadsCard::BeforeSearch(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			SearchToBattlefield(GetGame(), GetGame()->GetPlayer(ip), 1, CCardFilter::GetFilter(_T("basic lands")), TRUE);
	return true;
}

CRangingRaptorsCard::CRangingRaptorsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ranging Raptors"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Enrage - Whenever this creature is dealt damage, you may search your library for a basic land card, put it onto
	// the battlefield tapped, then shuffle.
	AddEnrageTrigger(this, &CRangingRaptorsCard::SetEnrageContext, &CRangingRaptorsCard::BeforeSearch);
}

bool CRangingRaptorsCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CRangingRaptorsCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchToBattlefield(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("basic lands")), TRUE);
	return true;
}

CRavenousDaggertoothCard::CRavenousDaggertoothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ravenous Daggertooth"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// Enrage - Whenever this creature is dealt damage, you gain 2 life.
	AddEnrageTrigger(this, &CRavenousDaggertoothCard::SetEnrageContext, &CRavenousDaggertoothCard::BeforeGainLife);
}

bool CRavenousDaggertoothCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CRavenousDaggertoothCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 2);
	return true;
}

CRipjawRaptorCard::CRipjawRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ripjaw Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(5))
{
	// Enrage - Whenever this creature is dealt damage, draw a card.
	AddEnrageTrigger(this, &CRipjawRaptorCard::SetEnrageContext, &CRipjawRaptorCard::BeforeDraw);
}

bool CRipjawRaptorCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CRipjawRaptorCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CSnappingSailbackCard::CSnappingSailbackCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Snapping Sailback"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Enrage - Whenever this creature is dealt damage, put a +1/+1 counter on it.
	AddEnrageTrigger(this, &CSnappingSailbackCard::SetEnrageContext, &CSnappingSailbackCard::BeforeCounter);
}

bool CSnappingSailbackCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CSnappingSailbackCard::BeforeCounter(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	return true;
}

CSpikeTailedCeratopsCard::CSpikeTailedCeratopsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spike-Tailed Ceratops"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4))
{
	// This creature can block an additional creature each combat.
	SetMaxBlockingCount(2);
}

CThunderingSpinebackCard::CThunderingSpinebackCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thundering Spineback"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	{
		// Other Dinosaurs you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false),
					new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+1), Life(+1)));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {5}{G}: Create a 3/3 green Dinosaur creature token with trample.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("5") GREEN_MANA_TEXT,
				DINOSAUR_A_TOKEN_NAME, DINOSAUR_A_TOKEN_ID,
				1));
		AddAbility(cpAbility.GetPointer());
	}
}

CTishanasWayfinderCard::CTishanasWayfinderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tishana's Wayfinder"), CardType::Creature, CREATURE_TYPE2(Merfolk, Scout), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Explore(this)
{
	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CVerdantSunsAvatarCard::CVerdantSunsAvatarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Verdant Sun's Avatar"), CardType::Creature, CREATURE_TYPE2(Dinosaur, Avatar), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Whenever this creature or another creature you control enters, you gain life equal to that creature's
	// toughness. (the creature in the context, as Scrap Trawler in Aether Revolt)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVerdantSunsAvatarCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CVerdantSunsAvatarCard::BeforeGainLife));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CVerdantSunsAvatarCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard)
		return false;

	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CVerdantSunsAvatarCard::BeforeGainLife(TriggeredAbility::TriggeredActionType* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)pAction->GetTriggerContext().nValue1);
	int nToughness = pCreature ? (int)pCreature->GetLastKnownToughness() : 0;
	if (nToughness > 0)
		GainLife(this, GetController(), nToughness);
	return true;
}

CVineshaperMysticCard::CVineshaperMysticCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vineshaper Mystic"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("2") GREEN_MANA_TEXT, Power(1), Life(3))
	, m_MerfolkSelection(pGame, CSelectionSupport::SelectionCallback(this, &CVineshaperMysticCard::OnMerfolkSelected))
{
	// When this creature enters, put a +1/+1 counter on each of up to two target Merfolk you control.
	// Note: the Merfolk are chosen on resolution (not targeted)
	AddEnterTrigger(this, &CVineshaperMysticCard::BeforeChoose);
}

bool CVineshaperMysticCard::BeforeChoose(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CreatureTypeComparer merfolk(CREATURE_TYPE(Merfolk), false);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (!merfolk(pCard))
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put a +1/+1 counter on %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_MerfolkSelection.AddSelectionRequest(entries, 0, entries.size() < 2 ? (int)entries.size() : 2, this, pAction->GetController());
	return true;
}

void CVineshaperMysticCard::OnMerfolkSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			AddPlusCounter((CCard*)it->dwContext);
}

CWakerOfTheWildsCard::CWakerOfTheWildsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Waker of the Wilds"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// {X}{G}{G}: Put X +1/+1 counters on target land you control. That land becomes a 0/0 Elemental creature with
	// haste. It's still a land. (the animation as Balduvian Frostwaker in Coldsnap)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			GREEN_MANA_TEXT GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::_Land, false), FALSE));

	cpAbility->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWakerOfTheWildsCard::BeforeAwaken));
	AddAbility(cpAbility.GetPointer());
}

bool CWakerOfTheWildsCard::BeforeAwaken(CAbilityAction* pAction)
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (!pLand || pLand->GetZoneId() != ZoneId::Battlefield)
		return true;

	int nX = GetX(pAction);
	AddPlusCounter(pLand, nX);
	if (!pLand->GetIsAlsoA())
	{
		CCardIsAlsoAModifier pModifier = CCardIsAlsoAModifier(ELEMENTAL_AW_TOKEN_NAME, ELEMENTAL_AW_TOKEN_ID, pAction->GetController());
		pModifier.ApplyTo(pLand);
	}
	return true;
}

CWildgrowthWalkerCard::CWildgrowthWalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wildgrowth Walker"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3))
{
	// Whenever a creature you control explores, put a +1/+1 counter on this creature and you gain 3 life.
	AddWheneverExploresTrigger(this, &CWildgrowthWalkerCard::BeforeExplored);
}

bool CWildgrowthWalkerCard::BeforeExplored(CAbilityAction* pAction)
{
	AddPlusCounter(this);
	GainLife(this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (red creatures)

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

//____________________________________________________________________________
//
// Red creatures

CAngrathsMaraudersCard::CAngrathsMaraudersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Angrath's Marauders"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("5") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// If a source you control would deal damage to a permanent or player, it deals double that damage to that
	// permanent or player instead. (as Furnace of Rath in Eighth Edition, only for the controller's sources)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::MultiplyDamage, 1));

	cpAbility->SetMultipleEffectType(TRUE);
	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());
}

CBrazenBuccaneersCard::CBrazenBuccaneersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brazen Buccaneers"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(2))
	, m_Explore(this)
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CBurningSunsAvatarCard::CBurningSunsAvatarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Burning Sun's Avatar"), CardType::Creature, CREATURE_TYPE2(Dinosaur, Avatar), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(6))
{
	// When this creature enters, it deals 3 damage to target opponent or planeswalker and 3 damage to up to one target
	// creature.
	// Note: the opponent isn't targeted (two-player games); it can't target planeswalkers
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CBurningSunsAvatarCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->SetSubjectCount(0, 1);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

bool CBurningSunsAvatarCard::BeforeDamage(CAbilityAction* pAction)
{
	CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(GetGame()->GetNextPlayer(pAction->GetController()));
	DealDamageToCreature(this, pAction->GetAssociatedCard(), 3);
	return false;
}

CCaptainLanneryStormCard::CCaptainLanneryStormCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Captain Lannery Storm"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever Captain Lannery Storm attacks, create a Treasure token.
	AddSelfAttackTrigger(this, &CCaptainLanneryStormCard::BeforeTreasure);

	// Whenever you sacrifice a Treasure, Captain Lannery Storm gets +1/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardNameComparer(_T("Treasure")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCaptainLanneryStormCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCaptainLanneryStormCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CCaptainLanneryStormCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CCaptainLanneryStormCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Sacrifice;
}

bool CCaptainLanneryStormCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +0);
	return true;
}

CCaptivatingCrewCard::CCaptivatingCrewCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Captivating Crew"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(3))
{
	// {3}{R}: Gain control of target creature an opponent controls until end of turn. Untap that creature. It gains
	// haste until end of turn. Activate only as a sorcery. (as Hijack in Kaladesh)
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	cpAbility->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);
	AddAbility(cpAbility.GetPointer());
}

CChargingMonstrosaurCard::CChargingMonstrosaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Charging Monstrosaur"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") RED_MANA_TEXT, Power(5), Life(5))
{
	// Trample, haste
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);
}

CFathomFleetFirebrandCard::CFathomFleetFirebrandCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fathom Fleet Firebrand"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// {1}{R}: This creature gets +1/+0 until end of turn.
	AddPumpAbility(this, _T("1") RED_MANA_TEXT, _T("This creature gets +1/+0 until end of turn. Activates"),
		&CFathomFleetFirebrandCard::BeforePump);
}

bool CFathomFleetFirebrandCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +0);
	return true;
}

CFireShrineKeeperCard::CFireShrineKeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fire Shrine Keeper"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// {7}{R}, {T}, Sacrifice this creature: It deals 3 damage to each of up to two target creatures.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("7") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-3), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetSubjectCount(1, 2);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

CFrenziedRaptorCard::CFrenziedRaptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frenzied Raptor"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") RED_MANA_TEXT, Power(4), Life(2))
{
}

CHeadstrongBruteCard::CHeadstrongBruteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Headstrong Brute"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(3))
{
	// This creature can't block.
	GetCreatureKeyword()->AddCantBlock(FALSE);

	// This creature has menace as long as you control another Pirate.
	AddAnotherTypeBonus(this, CREATURE_TYPE(Pirate), +0, CreatureKeyword::CantBeBlockedBy1);
}

CLightningRigCrewCard::CLightningRigCrewCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lightning-Rig Crew"), CardType::Creature, CREATURE_TYPE2(Goblin, Pirate), nID,
		_T("2") RED_MANA_TEXT, Power(0), Life(5))
{
	{
		// {T}: This creature deals 1 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("This creature deals 1 damage to each opponent. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLightningRigCrewCard::BeforeDamage));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast a Pirate spell, untap this creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLightningRigCrewCard::BeforeUntap));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLightningRigCrewCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

bool CLightningRigCrewCard::BeforeUntap(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CNestRobberCard::CNestRobberCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nest Robber"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);
}

COtepecHuntmasterCard::COtepecHuntmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Otepec Huntmaster"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(2))
{
	{
		// Dinosaur spells you cast cost {1} less to cast. (as Kinjalli's Caller)
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false),
				_T("1")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}: Target Dinosaur gains haste until end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COtepecHuntmasterCard::BeforeHaste));
		AddAbility(cpAbility.GetPointer());
	}
}

bool COtepecHuntmasterCard::BeforeHaste(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +0, +0, CreatureKeyword::Haste);
	return true;
}

CRampagingFerocidonCard::CRampagingFerocidonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rampaging Ferocidon"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(3))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	{
		// Players can't gain life.
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantGainLife));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever another creature enters, this creature deals 1 damage to that creature's controller.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRampagingFerocidonCard::SetTriggerContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CRampagingFerocidonCard::BeforeDamage));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

// nValue1: the controller of the creature
bool CRampagingFerocidonCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard == this)
		return false;

	triggerContext.nValue1 = (DWORD)pCard->GetController();
	return true;
}

bool CRampagingFerocidonCard::BeforeDamage(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue1;
	if (pPlayer)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

CRaptorHatchlingCard::CRaptorHatchlingCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Raptor Hatchling"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(1))
{
	// Enrage - Whenever this creature is dealt damage, create a 3/3 green Dinosaur creature token with trample.
	AddEnrageTrigger(this, &CRaptorHatchlingCard::SetEnrageContext, &CRaptorHatchlingCard::BeforeToken);
}

bool CRaptorHatchlingCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CRaptorHatchlingCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), DINOSAUR_A_TOKEN_NAME, DINOSAUR_A_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CRiggingRunnerCard::CRiggingRunnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rigging Runner"), CardType::Creature, CREATURE_TYPE2(Goblin, Pirate), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Raid - This creature enters with a +1/+1 counter on it if you attacked this turn.
	// Note: the counter is put by a trigger when it enters
	AddEnterTrigger(this, &CRiggingRunnerCard::BeforeCounter);
}

bool CRiggingRunnerCard::BeforeCounter(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		AddPlusCounter(this);
	return true;
}

CRowdyCrewCard::CRowdyCrewCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rowdy Crew"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, draw three cards, then discard two cards at random. If two cards that share a card
	// type are discarded this way, put two +1/+1 counters on this creature.
	AddEnterTrigger(this, &CRowdyCrewCard::BeforeDraw);
}

bool CRowdyCrewCard::BeforeDraw(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 3);

	// Two cards at random
	CardType types[2] = { CardType::Null, CardType::Null };
	int nDiscarded = 0;
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	for (int i = 0; i < 2 && pHand->GetSize() > 0; ++i)
	{
		CCard* pCard = pHand->GetAt((int)(pController->GetRand() % pHand->GetSize()));
		types[nDiscarded] = pCard->GetCardType() & (CardType::Artifact | CardType::Creature | CardType::_Enchantment |
			CardType::Instant | CardType::_Land | CardType::Planeswalker | CardType::Sorcery);
		pModifier.ApplyTo(pCard);
		++nDiscarded;
	}

	if (nDiscarded == 2 && (types[0] & types[1]).Any())
		AddPlusCounter(this, 2);
	return true;
}

CStormFleetArsonistCard::CStormFleetArsonistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storm Fleet Arsonist"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(4))
	, m_PermanentFilter(_T("a permanent"), _T("permanents"), new CardTypeComparer(CardType::_Permanent, false))
{
	// Raid - When this creature enters, if you attacked this turn, target opponent sacrifices a permanent of their
	// choice.
	// Note: the opponent isn't targeted and the condition is checked on resolution
	AddEnterTrigger(this, &CStormFleetArsonistCard::BeforeSacrifice);
}

bool CStormFleetArsonistCard::BeforeSacrifice(CAbilityAction* pAction)
{
	if (!HasRaid(pAction->GetController()))
		return true;

	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAction->GetController());
	if (m_PermanentFilter.CountIncluded(pOpponent->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Battlefield, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select the permanent to sacrifice
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		&m_PermanentFilter, // what cards
		ZoneId::Graveyard, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Sacrifice, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pOpponent);
	return true;
}

CStormFleetPyromancerCard::CStormFleetPyromancerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storm Fleet Pyromancer"), CardType::Creature, CREATURE_TYPE3(Human, Pirate, Wizard), nID,
		_T("4") RED_MANA_TEXT, Power(3), Life(2))
{
	// Raid - When this creature enters, if you attacked this turn, this creature deals 2 damage to any target.
	// Note: the condition is checked on resolution; it can't target planeswalkers
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CStormFleetPyromancerCard::BeforeDamage, false, Characteristic::Negative);
	pTargeting->SetIncludePlayers(TRUE);
}

bool CStormFleetPyromancerCard::BeforeDamage(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		DealDamageToTarget(this, pAction, 2);
	return false;
}

CSunCrownedHuntersCard::CSunCrownedHuntersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sun-Crowned Hunters"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(4))
{
	// Enrage - Whenever this creature is dealt damage, it deals 3 damage to target opponent or planeswalker.
	// Note: the opponent isn't targeted (two-player games)
	AddEnrageTrigger(this, &CSunCrownedHuntersCard::SetEnrageContext, &CSunCrownedHuntersCard::BeforeDamage);
}

bool CSunCrownedHuntersCard::SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const
{
	return pCreature == this;
}

bool CSunCrownedHuntersCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 3);
	return true;
}

CThrashOfRaptorsCard::CThrashOfRaptorsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thrash of Raptors"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// As long as you control another Dinosaur, this creature gets +2/+0 and has trample.
	AddAnotherTypeBonus(this, CREATURE_TYPE(Dinosaur), +2, CreatureKeyword::Trample);
}

CTilonallisKnightCard::CTilonallisKnightCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tilonalli's Knight"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, if you control a Dinosaur, this creature gets +1/+1 until end of turn.
	// (the condition is checked on resolution)
	AddSelfAttackTrigger(this, &CTilonallisKnightCard::BeforePump);
}

bool CTilonallisKnightCard::BeforePump(CAbilityAction* pAction)
{
	if (ControlsDinosaur(pAction->GetController()))
		PumpCreature(this, +1, +1);
	return true;
}

CWilyGoblinCard::CWilyGoblinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wily Goblin"), CardType::Creature, CREATURE_TYPE2(Goblin, Pirate), nID,
		RED_MANA_TEXT RED_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, create a Treasure token.
	AddEnterTrigger(this, &CWilyGoblinCard::BeforeTreasure);
}

bool CWilyGoblinCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (black creatures)

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

//____________________________________________________________________________
//
// Black creatures

CAnointedDeaconCard::CAnointedDeaconCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Anointed Deacon"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// At the beginning of combat on your turn, you may have target Vampire get +2/+0 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAnointedDeaconCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CAnointedDeaconCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +2, +0);
	return false;
}

CBishopOfTheBloodstainedCard::CBishopOfTheBloodstainedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bishop of the Bloodstained"), CardType::Creature, CREATURE_TYPE2(Vampire, Cleric), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, target opponent loses 1 life for each Vampire you control.
	// Note: the opponent isn't targeted (two-player games)
	AddEnterTrigger(this, &CBishopOfTheBloodstainedCard::BeforeLoseLife);
}

bool CBishopOfTheBloodstainedCard::BeforeLoseLife(CAbilityAction* pAction)
{
	CCardFilter vampires(_T("a Vampire"), _T("Vampires"), new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	int nCount = vampires.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	DrainOpponents(this, pAction->GetController(), nCount, FALSE);
	return true;
}

CBlightKeeperCard::CBlightKeeperCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Blight Keeper"), CardType::Creature, CREATURE_TYPE2(Bat, Imp), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// {7}{B}, {T}, Sacrifice this creature: Target opponent loses 4 life and you gain 4 life.
	// Note: the opponent isn't targeted (two-player games)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("7") BLACK_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Target opponent loses 4 life and you gain 4 life. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlightKeeperCard::BeforeDrain));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CBlightKeeperCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 4, TRUE);
	return true;
}

CBloodcrazedPaladinCard::CBloodcrazedPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodcrazed Paladin"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
	, m_nDeathTurn(-1)
	, m_nDeaths(0)
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// This creature enters with a +1/+1 counter on it for each creature that died this turn.
	// Note: the counters are put by a trigger when it enters; the deaths are counted by this card in any zone (as Life
	// Goes On in Hour of Devastation)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard, FALSE, TRUE, FALSE));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodcrazedPaladinCard::CountDeath));
		AddAbility(cpAbility.GetPointer());
	}
	AddEnterTrigger(this, &CBloodcrazedPaladinCard::BeforeCounters);
}

bool CBloodcrazedPaladinCard::CountDeath(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	int nTurn = GetGame()->GetGameTurnNumber();
	if (m_nDeathTurn != nTurn)
	{
		m_nDeathTurn = nTurn;
		m_nDeaths = 0;
	}
	++m_nDeaths;
	return false;
}

bool CBloodcrazedPaladinCard::BeforeCounters(CAbilityAction* pAction)
{
	if (m_nDeathTurn == GetGame()->GetGameTurnNumber())
		AddPlusCounter(this, m_nDeaths);
	return true;
}

CDeadeyeTormentorCard::CDeadeyeTormentorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Tormentor"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Raid - When this creature enters, if you attacked this turn, target opponent discards a card.
	// Note: the opponent isn't targeted and the condition is checked on resolution
	AddEnterTrigger(this, &CDeadeyeTormentorCard::BeforeDiscard);
}

bool CDeadeyeTormentorCard::BeforeDiscard(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		DiscardCards(GetGame(), GetGame()->GetNextPlayer(pAction->GetController()), 1);
	return true;
}

CDeadeyeTrackerCard::CDeadeyeTrackerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Tracker"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// {1}{B}, {T}: Exile two target cards from an opponent's graveyard. This creature explores.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("1") BLACK_MANA_TEXT,
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetSubjectCount(2, 2);
	cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeadeyeTrackerCard::BeforeExplore));
	AddAbility(cpAbility.GetPointer());
}

// The creature explores before the cards are exiled (the callback returns true: ResolveImpl exiles them)
bool CDeadeyeTrackerCard::BeforeExplore(CAbilityAction* pAction)
{
	CExploreSupport::Explore(this);
	return true;
}

CDeathlessAncientCard::CDeathlessAncientCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Deathless Ancient"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
	, m_VampireFilter(_T("an untapped Vampire you control"), _T("untapped Vampires you control"),
		new CreatureTypeComparer(CREATURE_TYPE(Vampire), false))
{
	// Tap three untapped Vampires you control: Return this card from your graveyard to your hand.
	// (a graveyard ability, as Embalm)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->SetGraveyardOnly();
	cpAbility->GetCost().AddTapCardCost(3, &m_VampireFilter);
	cpAbility->SetAbilityText(_T("Tap three Vampires: return this card from your graveyard to your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeathlessAncientCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CDeathlessAncientCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(this);
	}
	return true;
}

CDesperateCastawaysCard::CDesperateCastawaysCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Desperate Castaways"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// This creature can't attack unless you control an artifact. (it can't attack as long as you control no
	// artifacts, as Marauding Boneslasher in Hour of Devastation)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::CantAttack));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(0);
	cpAbility->SetConditionIsMaximum();
	AddAbility(cpAbility.GetPointer());
}

CDireFleetHoarderCard::CDireFleetHoarderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Hoarder"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// When this creature dies, create a Treasure token.
	AddDiesTrigger(this, &CDireFleetHoarderCard::BeforeTreasure);
}

bool CDireFleetHoarderCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CDireFleetInterloperCard::CDireFleetInterloperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Interloper"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_Explore(this)
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CDireFleetRavagerCard::CDireFleetRavagerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Ravager"), CardType::Creature, CREATURE_TYPE3(Orc, Pirate, Wizard), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
{
	// Menace, deathtouch
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);

	// When this creature enters, each player loses a third of their life, rounded up.
	AddEnterTrigger(this, &CDireFleetRavagerCard::BeforeLoseLife);
}

bool CDireFleetRavagerCard::BeforeLoseLife(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		int nLife = (int)pPlayer->GetLife();
		int nLoss = nLife > 0 ? (nLife + 2) / 3 : 0;
		if (nLoss > 0)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-nLoss), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pPlayer);
		}
	}
	return true;
}

CFathomFleetCaptainCard::CFathomFleetCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fathom Fleet Captain"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Whenever this creature attacks, if you control another nontoken Pirate, you may pay {2}. If you do, create a 2/2
	// black Pirate creature token with menace. (the payment is a resolution cost; the condition is checked on
	// resolution)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionCost(_T("2"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFathomFleetCaptainCard::BeforeToken));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CFathomFleetCaptainCard::BeforeToken(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	CreatureTypeComparer pirates(CREATURE_TYPE(Pirate), false);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard != this && !pCard->GetCardType().IsToken() && pirates(pCard))
		{
			CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), PIRATE_A_TOKEN_NAME, PIRATE_A_TOKEN_ID, 1);
			pModifier.ApplyTo(pAction->GetController());
			break;
		}
	}
	return true;
}

CFathomFleetCutthroatCard::CFathomFleetCutthroatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fathom Fleet Cutthroat"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, destroy target creature an opponent controls that was dealt damage this turn.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CFathomFleetCutthroatCard::BeforeDestroy, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
	pTargeting->GetSubjectCardFilter().AddComparer(new DamagedThisTurnComparer);
}

bool CFathomFleetCutthroatCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CKitesailFreebooterCard::CKitesailFreebooterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kitesail Freebooter"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CKitesailFreebooterCard::OnCardSelected))
	, m_pExiled(NULL)
{
	// When this creature enters, target opponent reveals their hand. You choose a noncreature, nonland card from it.
	// Exile that card until this creature leaves the battlefield.
	// Note: the opponent isn't targeted (two-player games)
	AddEnterTrigger(this, &CKitesailFreebooterCard::BeforeReveal);
	AddLeaveTrigger(this, &CKitesailFreebooterCard::BeforeReturn);
}

bool CKitesailFreebooterCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pAction->GetController());
	CZone* pHand = pOpponent->GetZoneById(ZoneId::Hand);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		if (pCard->GetCardType().IsCreature() || pCard->GetCardType().IsLand())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty() && GetZoneId() == ZoneId::Battlefield)
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CKitesailFreebooterCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Hand || GetZoneId() != ZoneId::Battlefield)
				return;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() == ZoneId::Exile)
				m_pExiled = pCard;
			return;
		}
}

// The exiled card returns to its owner's hand
bool CKitesailFreebooterCard::BeforeReturn(CAbilityAction* pAction)
{
	CCard* pCard = m_pExiled;
	m_pExiled = NULL;
	if (pCard && pCard->GetZoneId() == ZoneId::Exile)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CLurkingChupacabraCard::CLurkingChupacabraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lurking Chupacabra"), CardType::Creature, CREATURE_TYPE2(Beast, Horror), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Whenever a creature you control explores, target creature an opponent controls gets -2/-2 until end of turn.
	// (listens to EXPLORE_TRIGGER_ID, as Wildgrowth Walker)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetTriggerIndex(EXPLORE_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(this));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLurkingChupacabraCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());
}

bool CLurkingChupacabraCard::BeforeShrink(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), -2, -2);
	return false;
}

CQueensAgentCard::CQueensAgentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Queen's Agent"), CardType::Creature, CREATURE_TYPE2(Vampire, Scout), nID,
		_T("5") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_Explore(this)
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CQueensBaySoldierCard::CQueensBaySoldierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Queen's Bay Soldier"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
}

CRuinRaiderCard::CRuinRaiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ruin Raider"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Raid - At the beginning of your end step, if you attacked this turn, reveal the top card of your library and put
	// that card into your hand. You lose life equal to the card's mana value.
	AddStepTrigger(this, NodeId::EndStep, false, &CRuinRaiderCard::SetTriggerContext, &CRuinRaiderCard::BeforeReveal);
}

bool CRuinRaiderCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRaid(GetController()) == TRUE;
}

bool CRuinRaiderCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	int nManaValue = (int)pCard->GetConvertedManaCost();
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others);
	pModifier.ApplyTo(pCard);

	if (nManaValue > 0)
	{
		CLifeModifier pLose = CLifeModifier(Life(-nManaValue), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pLose.ApplyTo(pController);
	}
	return true;
}

CRuthlessKnaveCard::CRuthlessKnaveCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ruthless Knave"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
	, m_CreatureFilter(_T("a creature"), _T("creatures"), new AnyCreatureComparer)
	, m_TreasureFilter(_T("a Treasure"), _T("Treasures"), new CardNameComparer(_T("Treasure")))
{
	{
		// {2}{B}, Sacrifice a creature: Create two Treasure tokens.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLACK_MANA_TEXT));

		cpAbility->GetCost().AddSacrificeCardCost(1, &m_CreatureFilter);
		cpAbility->SetAbilityText(_T("Sacrifice a creature: create two Treasure tokens. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRuthlessKnaveCard::BeforeTreasures));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Sacrifice three Treasures: Draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddSacrificeCardCost(3, &m_TreasureFilter);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
		cpAbility->SetAbilityText(_T("Sacrifice three Treasures: draw a card. Activates"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRuthlessKnaveCard::BeforeTreasures(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 2);
	return true;
}

CSanctumSeekerCard::CSanctumSeekerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sanctum Seeker"), CardType::Creature, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(4))
{
	// Whenever a Vampire you control attacks, each opponent loses 1 life and you gain 1 life. (as Campaign of Vengeance
	// in Eldritch Moon)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSanctumSeekerCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSanctumSeekerCard::BeforeDrain));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CSanctumSeekerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject subject) const
{
	return pCreature && CreatureTypeComparer(CREATURE_TYPE(Vampire), false)(pCreature);
}

bool CSanctumSeekerCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, TRUE);
	return true;
}

CSeekersSquireCard::CSeekersSquireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Seekers' Squire"), CardType::Creature, CREATURE_TYPE2(Human, Scout), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
	, m_Explore(this)
{
	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CSkitteringHeartstopperCard::CSkitteringHeartstopperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skittering Heartstopper"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		BLACK_MANA_TEXT, Power(1), Life(2))
{
	// {B}: This creature gains deathtouch until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			BLACK_MANA_TEXT));

	cpAbility->SetAbilityText(_T("This creature gains deathtouch until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkitteringHeartstopperCard::BeforeDeathtouch));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CSkitteringHeartstopperCard::BeforeDeathtouch(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCardKeyword()->AddDeathtouch(TRUE);
	return true;
}

CSkymarchBloodletterCard::CSkymarchBloodletterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skymarch Bloodletter"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, target opponent loses 1 life and you gain 1 life.
	// Note: the opponent isn't targeted (two-player games)
	AddEnterTrigger(this, &CSkymarchBloodletterCard::BeforeDrain);
}

bool CSkymarchBloodletterCard::BeforeDrain(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, TRUE);
	return true;
}

CViciousConquistadorCard::CViciousConquistadorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vicious Conquistador"), CardType::Creature, CREATURE_TYPE2(Vampire, Soldier), nID,
		BLACK_MANA_TEXT, Power(1), Life(2))
{
	// Whenever this creature attacks, each opponent loses 1 life.
	AddSelfAttackTrigger(this, &CViciousConquistadorCard::BeforeLoseLife);
}

bool CViciousConquistadorCard::BeforeLoseLife(CAbilityAction* pAction)
{
	DrainOpponents(this, pAction->GetController(), 1, FALSE);
	return true;
}

CWantedScoundrelsCard::CWantedScoundrelsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wanted Scoundrels"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLACK_MANA_TEXT, Power(4), Life(3))
{
	// When this creature dies, target opponent creates two Treasure tokens.
	// Note: the opponent isn't targeted (two-player games)
	AddDiesTrigger(this, &CWantedScoundrelsCard::BeforeTreasures);
}

bool CWantedScoundrelsCard::BeforeTreasures(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), GetGame()->GetNextPlayer(pAction->GetController()), 2);
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (blue creatures)

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

//____________________________________________________________________________
//
// Blue creatures

CDaringSaboteurCard::CDaringSaboteurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Daring Saboteur"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	{
		// {2}{U}: This creature can't be blocked this turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLUE_MANA_TEXT));

		cpAbility->SetAbilityText(_T("This creature can't be blocked this turn. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDaringSaboteurCard::BeforeUnblockable));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature deals combat damage to a player, you may draw a card. If you do, discard a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDaringSaboteurCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDaringSaboteurCard::BeforeUnblockable(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

bool CDaringSaboteurCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

CDeadeyeQuartermasterCard::CDeadeyeQuartermasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Quartermaster"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_SearchFilter(_T("an Equipment or Vehicle card"), _T("Equipment or Vehicle cards"),
		new OrCardComparer(new CardTypeComparer(CardType::Equipment, false), new VehicleComparer))
{
	// When this creature enters, you may search your library for an Equipment or Vehicle card, reveal it, put it into
	// your hand, then shuffle.
	AddEnterTrigger(this, &CDeadeyeQuartermasterCard::BeforeSearch, true);
}

bool CDeadeyeQuartermasterCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // an Equipment or Vehicle card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		&m_SearchFilter, // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CDreamcallerSirenCard::CDreamcallerSirenCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dreamcaller Siren"), CardType::Creature, CREATURE_TYPE2(Siren, Pirate), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
	, m_PermanentSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDreamcallerSirenCard::OnPermanentsSelected))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// This creature can block only creatures with flying.
	GetCreatureKeyword()->AddCanOnlyBlockFlying(FALSE);

	// When this creature enters, if you control another Pirate, tap up to two target nonland permanents.
	// Note: the permanents are chosen on resolution (not targeted), and the condition is checked then
	AddEnterTrigger(this, &CDreamcallerSirenCard::BeforeChoose);
}

bool CDreamcallerSirenCard::BeforeChoose(CAbilityAction* pAction)
{
	CCardFilter pirates(_T("another Pirate"), _T("other Pirates"),
		new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false), new NegateCardComparer(new SpecificCardComparer(this))));
	if (pirates.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return true;

	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsLand() || pCard->GetOrientation()->IsTapped())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Tap %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_PermanentSelection.AddSelectionRequest(entries, 0, entries.size() < 2 ? (int)entries.size() : 2, this, pAction->GetController());
	return true;
}

void CDreamcallerSirenCard::OnPermanentsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				pModifier.ApplyTo(pCard);
		}
}

CFleetSwallowerCard::CFleetSwallowerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fleet Swallower"), CardType::Creature, CREATURE_TYPE(Fish), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(6), Life(6))
{
	// Whenever this creature attacks, target player mills half their library, rounded up.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFleetSwallowerCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CFleetSwallowerCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, (pPlayer->GetZoneById(ZoneId::Library)->GetSize() + 1) / 2);
	return false;
}

CHeadwaterSentriesCard::CHeadwaterSentriesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Headwater Sentries"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(5))
{
}

CHeraldOfSecretStreamsCard::CHeraldOfSecretStreamsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Herald of Secret Streams"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(3))
{
	// Creatures you control with +1/+1 counters on them can't be blocked.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1),
			Power(+0), Life(+0), CreatureKeyword::Unblockable));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CJacesSentinelCard::CJacesSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jace's Sentinel"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// As long as you control a Jace planeswalker, this creature gets +1/+0 and can't be blocked.
	AddPlaneswalkerBonus(this, PlaneswalkerType::Jace, +1, CreatureKeyword::Unblockable);
}

CProsperousPiratesCard::CProsperousPiratesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prosperous Pirates"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, create two Treasure tokens.
	AddEnterTrigger(this, &CProsperousPiratesCard::BeforeTreasure);
}

bool CProsperousPiratesCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 2);
	return true;
}

CRiverSneakCard::CRiverSneakCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("River Sneak"), CardType::Creature, CREATURE_TYPE2(Merfolk, Warrior), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(1))
{
	// This creature can't be blocked.
	GetCreatureKeyword()->AddUnblockable(FALSE);

	// Whenever another Merfolk you control enters, this creature gets +1/+1 until end of turn. (as Mummy Paramount in
	// Hour of Devastation)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Merfolk), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRiverSneakCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CRiverSneakCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

CSailorOfMeansCard::CSailorOfMeansCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sailor of Means"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// When this creature enters, create a Treasure token.
	AddEnterTrigger(this, &CSailorOfMeansCard::BeforeTreasure);
}

bool CSailorOfMeansCard::BeforeTreasure(CAbilityAction* pAction)
{
	CreateTreasure(GetGame(), pAction->GetController(), 1);
	return true;
}

CShaperApprenticeCard::CShaperApprenticeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shaper Apprentice"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// This creature has flying as long as you control another Merfolk.
	AddAnotherTypeBonus(this, CREATURE_TYPE(Merfolk), +0, CreatureKeyword::Flying);
}

CShipwreckLooterCard::CShipwreckLooterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shipwreck Looter"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// Raid - When this creature enters, if you attacked this turn, you may draw a card. If you do, discard a card.
	// Note: the condition is checked on resolution
	AddEnterTrigger(this, &CShipwreckLooterCard::BeforeLoot, true);
}

bool CShipwreckLooterCard::BeforeLoot(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		Loot(GetGame(), pAction->GetController());
	return true;
}

CShoreKeeperCard::CShoreKeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shore Keeper"), CardType::Creature, CREATURE_TYPE(Trilobite), nID,
		BLUE_MANA_TEXT, Power(0), Life(3))
{
	// {7}{U}, {T}, Sacrifice this creature: Draw three cards.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("7") BLUE_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(3), MaximumValue(3)));
	cpAbility->SetAbilityText(_T("Draw three cards. Activates"));
	AddAbility(cpAbility.GetPointer());
}

CSirenLookoutCard::CSirenLookoutCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Siren Lookout"), CardType::Creature, CREATURE_TYPE2(Siren, Pirate), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(2))
	, m_Explore(this)
{
	// When this creature enters, it explores.
	m_Explore.AddExploreEnterAbility();
}

CSirenStormtamerCard::CSirenStormtamerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Siren Stormtamer"), CardType::Creature, CREATURE_TYPE3(Siren, Pirate, Wizard), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
{
	// {U}, Sacrifice this creature: Counter target spell or ability that targets you or a creature you control.
	// Not implemented: the abilities can't be countered, and a counterspell can't check the targets of the spell
}

CStormFleetAerialistCard::CStormFleetAerialistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Storm Fleet Aerialist"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// Raid - This creature enters with a +1/+1 counter on it if you attacked this turn.
	// Note: the counter is put by a trigger when it enters (as Rigging Runner)
	AddEnterTrigger(this, &CStormFleetAerialistCard::BeforeCounter);
}

bool CStormFleetAerialistCard::BeforeCounter(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		AddPlusCounter(this);
	return true;
}

CStormFleetSpyCard::CStormFleetSpyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storm Fleet Spy"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Raid - When this creature enters, if you attacked this turn, draw a card.
	// Note: the condition is checked on resolution
	AddEnterTrigger(this, &CStormFleetSpyCard::BeforeDraw);
}

bool CStormFleetSpyCard::BeforeDraw(CAbilityAction* pAction)
{
	if (HasRaid(pAction->GetController()))
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CStormSculptorCard::CStormSculptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Storm Sculptor"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// This creature can't be blocked.
	GetCreatureKeyword()->AddUnblockable(FALSE);

	// When this creature enters, return a creature you control to its owner's hand.
	AddEnterTrigger(this, &CStormSculptorCard::BeforeReturn);
}

bool CStormSculptorCard::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (CountCreatures(GetGame(), pController) == 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Battlefield, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // a creature you control
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("creatures")), // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);
	return true;
}

CTempestCallerCard::CTempestCallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tempest Caller"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, tap all creatures target opponent controls.
	// Note: the opponent isn't targeted (two-player games)
	AddEnterTrigger(this, &CTempestCallerCard::BeforeTap);
}

bool CTempestCallerCard::BeforeTap(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CWatertrapWeaverCard::CWatertrapWeaverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Watertrap Weaver"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, tap target creature an opponent controls. That creature doesn't untap during its
	// controller's next untap step.
	CTargeting* pTargeting = AddEnterTargetTrigger(this, &CWatertrapWeaverCard::BeforeTap, false, Characteristic::Negative);
	pTargeting->SetIncludeNonControllerCardsOnly();
}

// (the untap as SkipNextUntap in Aether Revolt)
bool CWatertrapWeaverCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardOrientationModifier pTap = CCardOrientationModifier(TRUE);
	pTap.ApplyTo(pCard);

	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pModifier.ApplyTo(pCard);
	return false;
}

CWindStriderCard::CWindStriderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Wind Strider"), CardType::Creature, CREATURE_TYPE2(Merfolk, Wizard), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (multicolored creatures)

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

//____________________________________________________________________________
//
// Multicolored and colorless creatures

CAdmiralBeckettBrassCard::CAdmiralBeckettBrassCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Admiral Beckett Brass"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
	, m_PermanentSelection(pGame, CSelectionSupport::SelectionCallback(this, &CAdmiralBeckettBrassCard::OnPermanentSelected))
	, m_nTurn(-1)
{
	// Other Pirates you control get +1/+1.
	AddOtherTypeLord(this, CREATURE_TYPE(Pirate), +1, CreatureKeyword::Null);

	{
		// Counts the Pirates you control that deal combat damage to each opponent (it never triggers)
		counted_ptr<DamageTriggeredAbility> cpAbility(::CreateObject<DamageTriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Pirate), false));
		cpAbility->SetOptionalType(DamageTriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(DamageTriggeredAbility::ContextFunction(this, &CAdmiralBeckettBrassCard::SetDamageContext));
		AddAbility(cpAbility.GetPointer());
	}

	// At the beginning of your end step, gain control of target nonland permanent controlled by a player who was dealt
	// combat damage by three or more Pirates this turn.
	// Note: the permanent is chosen on resolution (not targeted)
	AddStepTrigger(this, NodeId::EndStep, false, &CAdmiralBeckettBrassCard::SetTriggerContext, &CAdmiralBeckettBrassCard::BeforeChoose);
}

bool CAdmiralBeckettBrassCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	int nTurn = GetGame()->GetGameTurnNumber();
	if (nTurn != m_nTurn)
	{
		m_nTurn = nTurn;
		m_Damaged.clear();
	}

	std::pair<const CPlayer*, const CCard*> entry(pToPlayer, pFromCard);
	if (pFromCard && pToPlayer && std::find(m_Damaged.begin(), m_Damaged.end(), entry) == m_Damaged.end())
		m_Damaged.push_back(entry);
	return false;
}

int CAdmiralBeckettBrassCard::CountPirates(const CPlayer* pPlayer) const
{
	if (m_nTurn != GetGame()->GetGameTurnNumber())
		return 0;

	int nCount = 0;
	for (size_t i = 0; i < m_Damaged.size(); ++i)
		if (m_Damaged[i].first == pPlayer)
			++nCount;
	return nCount;
}

bool CAdmiralBeckettBrassCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer != GetController() && CountPirates(pPlayer) >= 3)
			return true;
	}
	return false;
}

bool CAdmiralBeckettBrassCard::BeforeChoose(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pAction->GetController() || CountPirates(pPlayer) < 3)
			continue;

		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsLand())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Gain control of %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_PermanentSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CAdmiralBeckettBrassCard::OnPermanentSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CGainControlModifier pModifier = CGainControlModifier(GetGame(), this);
				pModifier.ApplyTo(pCard);
			}
		}
}

CDeadeyePlunderersCard::CDeadeyePlunderersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Plunderers"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("3") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	{
		// This creature gets +1/+1 for each artifact you control. (as Nim Grotesque in Fifth Dawn)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new CardTypeComparer(CardType::Artifact, false)));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{U}{B}: Create a Treasure token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT,
				TREASURE_TOKEN_NAME, TREASURE_TOKEN_ID,
				1));

		AddAbility(cpAbility.GetPointer());
	}
}

CDireFleetCaptainCard::CDireFleetCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dire Fleet Captain"), CardType::Creature, CREATURE_TYPE2(Orc, Pirate), nID,
		BLACK_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, it gets +1/+1 until end of turn for each other attacking Pirate.
	AddSelfAttackTrigger(this, &CDireFleetCaptainCard::BeforePump);
}

bool CDireFleetCaptainCard::BeforePump(CAbilityAction* pAction)
{
	int nCount = 0;
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
		if (pCreature && pCreature != this && pCreature->IsAttacking() &&
			CreatureTypeComparer(CREATURE_TYPE(Pirate), false)(pCreature))
			++nCount;
	}

	if (nCount > 0)
		PumpCreature(this, nCount, nCount);
	return true;
}

CGildedSentinelCard::CGildedSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gilded Sentinel"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("4"), Power(3), Life(3))
{
}

CGishathSunsAvatarCard::CGishathSunsAvatarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gishath, Sun's Avatar"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Dinosaur, Avatar), nID,
		_T("5") RED_MANA_TEXT GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(7), Life(6))
	, m_DinosaurFilter(_T("a Dinosaur creature card"), _T("Dinosaur creature cards"),
		new AndCardComparer(new AnyCreatureComparer, new CreatureTypeComparer(CREATURE_TYPE(Dinosaur), false)))
{
	// Vigilance, trample, haste
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever Gishath deals combat damage to a player, reveal that many cards from the top of your library. Put any
	// number of Dinosaur creature cards from among them onto the battlefield and the rest on the bottom of your
	// library in a random order. (the damage in nValue1)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGishathSunsAvatarCard::SetDamageContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CGishathSunsAvatarCard::BeforeReveal));
	AddAbility(cpAbility.GetPointer());
}

bool CGishathSunsAvatarCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	int nDamage = -(int)damage.m_nLifeDelta;
	if (nDamage <= 0)
		return false;

	triggerContext.nValue1 = (DWORD)nDamage;
	return true;
}

bool CGishathSunsAvatarCard::BeforeReveal(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pController = GetController();
	int nCount = (int)pAction->GetTriggerContext().nValue1;
	int nLibrary = pController->GetZoneById(ZoneId::Library)->GetSize();
	if (nCount > nLibrary)
		nCount = nLibrary;
	if (nCount <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nCount,
		CZoneModifier::RoleType::AllPlayers,
		CardPlacement::Bottom, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nCount), // any number of Dinosaur creature cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		&m_DinosaurFilter, // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);
	return true;
}

CHostageTakerCard::CHostageTakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hostage Taker"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	{
		// When this creature enters, exile another target creature or artifact until this creature leaves the
		// battlefield.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
			new AndCardComparer(
				new OrCardComparer(new AnyCreatureComparer, new CardTypeComparer(CardType::Artifact, false)),
				new NegateCardComparer(new SpecificCardComparer(this))));
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHostageTakerCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}

	AddLeaveTrigger(this, &CHostageTakerCard::BeforeReturn);

	// You may cast that card for as long as it remains exiled, and mana of any type can be spent to cast that spell.
	// Not implemented: cards can't be cast from exile
}

bool CHostageTakerCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CHostageTakerCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CMaraudingLooterCard::CMaraudingLooterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Marauding Looter"), CardType::Creature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("2") BLUE_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
{
	// Raid - At the beginning of your end step, if you attacked this turn, you may draw a card. If you do, discard a
	// card.
	AddStepTrigger(this, NodeId::EndStep, true, &CMaraudingLooterCard::SetTriggerContext, &CMaraudingLooterCard::BeforeLoot);
}

bool CMaraudingLooterCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRaid(GetController()) == TRUE;
}

bool CMaraudingLooterCard::BeforeLoot(CAbilityAction* pAction)
{
	Loot(GetGame(), pAction->GetController());
	return true;
}

CRagingSwordtoothCard::CRagingSwordtoothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Raging Swordtooth"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, it deals 1 damage to each other creature.
	AddEnterTrigger(this, &CRagingSwordtoothCard::BeforeDamage);
}

bool CRagingSwordtoothCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard != this && pCard->GetCardType().IsCreature())
				creatures.AddCard(pCard, CardPlacement::Top);
		}
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		DealDamageToCreature(this, creatures.GetAt(i), 1);
	return true;
}

CRegisaurAlphaCard::CRegisaurAlphaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Regisaur Alpha"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Other Dinosaurs you control have haste.
	AddOtherTypeLord(this, CREATURE_TYPE(Dinosaur), +0, CreatureKeyword::Haste);

	// When this creature enters, create a 3/3 green Dinosaur creature token with trample.
	AddEnterTrigger(this, &CRegisaurAlphaCard::BeforeToken);
}

bool CRegisaurAlphaCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), DINOSAUR_A_TOKEN_NAME, DINOSAUR_A_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CShapersOfNatureCard::CShapersOfNatureCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shapers of Nature"), CardType::Creature, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	{
		// {3}{G}: Put a +1/+1 counter on target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("3") GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{U}, Remove a +1/+1 counter from a creature you control: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T("2") BLUE_MANA_TEXT, 1));

		cpAbility->GetCost().AddAnyCardCounterCost(_T("+1/+1"), -1, 1, CCardFilter::GetFilter(_T("creatures")));
		AddAbility(cpAbility.GetPointer());
	}
}

CSkyTerrorCard::CSkyTerrorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sky Terror"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CSunBlessedMountCard::CSunBlessedMountCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sun-Blessed Mount"), CardType::Creature, CREATURE_TYPE(Dinosaur), nID,
		_T("3") RED_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you may search your library and/or graveyard for a card named Huatli, Dinosaur
	// Knight, reveal it, then put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CSunBlessedMountCard::BeforeSearch, true);
}

bool CSunBlessedMountCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Huatli, Dinosaur Knight"));
	return true;
}

CTishanaVoiceOfThunderCard::CTishanaVoiceOfThunderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tishana, Voice of Thunder"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Merfolk, Shaman), nID,
		_T("5") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(0), Life(0))
{
	{
		// Tishana's power and toughness are each equal to the number of cards in your hand. (as Maro)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Hand,
				new TrueCardComparer));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// You have no maximum hand size.
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::NoMaximumHandSize));

		AddAbility(cpAbility.GetPointer());
	}

	// When Tishana enters, draw a card for each creature you control.
	AddEnterTrigger(this, &CTishanaVoiceOfThunderCard::BeforeDraw);
}

bool CTishanaVoiceOfThunderCard::BeforeDraw(CAbilityAction* pAction)
{
	int nCount = CountCreatures(GetGame(), pAction->GetController());
	if (nCount > 0)
		DrawCards(GetGame(), pAction->GetController(), nCount);
	return true;
}

CVonaButcherOfMaganCard::CVonaButcherOfMaganCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vona, Butcher of Magan"), CardType::Creature | CardType::Legendary, CREATURE_TYPE2(Vampire, Knight), nID,
		_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
{
	// Vigilance, lifelink
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// {T}, Pay 7 life: Destroy target nonland permanent. Activate only during your turn.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddTapCost();
	cpAbility->AddPayLifeDeltaCost(Life(-7));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddPlayableIf(this, cpAbility.GetPointer(), &CVonaButcherOfMaganCard::IsYourTurn);
	AddAbility(cpAbility.GetPointer());
}

BOOL CVonaButcherOfMaganCard::IsYourTurn(BOOL bIncludeTricks)
{
	return GetGame()->GetActivePlayer() == GetController();
}

//____________________________________________________________________________
//
