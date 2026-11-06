#include "stdafx.h"
#include "CardShadowsOverInnistrad.h"

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
		DEFINE_CARD(CChokedEstuaryCard);
		DEFINE_CARD(CDevilthornFoxCard);
		DEFINE_CARD(CDrownyardTempleCard);
		DEFINE_CARD(CForebodingRuinsCard);
		DEFINE_CARD(CForsakenSanctuaryCard);
		DEFINE_CARD(CFortifiedVillageCard);
		DEFINE_CARD(CFoulOrchardCard);
		DEFINE_CARD(CGameTrailCard);
		DEFINE_CARD(CHighlandLakeCard);
		DEFINE_CARD(CHulkingDevilCard);
		DEFINE_CARD(CNiblisOfDuskCard);
		DEFINE_CARD(CPortTownCard);
		DEFINE_CARD(CSanguinaryMageCard);
		DEFINE_CARD(CSeagrafSkaabCard);
		DEFINE_CARD(CSilentObserverCard);
		DEFINE_CARD(CStoneQuarryCard);
		DEFINE_CARD(CThornhideWolvesCard);
		DEFINE_CARD(CVampireNobleCard);
		DEFINE_CARD(CWarpedLandscapeCard);
		DEFINE_CARD(CWoodlandStreamCard);
		DEFINE_CARD(CArlinnKordCard);
		DEFINE_CARD(CArlinnEmbracedByTheMoonCard);
		DEFINE_CARD(CJaceUnravelerOfSecretsCard);
		DEFINE_CARD(CNahiriTheHarbingerCard);
		DEFINE_CARD(CSorinGrimNemesisCard);
		DEFINE_CARD(CEpitaphGolemCard);
		DEFINE_CARD(CExplosiveApparatusCard);
		DEFINE_CARD(CHauntedCloakCard);
		DEFINE_CARD(CMagnifyingGlassCard);
		DEFINE_CARD(CMurderersAxeCard);
		DEFINE_CARD(CWickerWitchCard);
		DEFINE_CARD(CWildFieldScarecrowCard);
		DEFINE_CARD(CThrabenGargoyleCard);
		DEFINE_CARD(CStonewingAntagonizerCard);
		DEFINE_CARD(CCorruptedGrafstoneCard);
		DEFINE_CARD(CRunawayCarriageCard);
		DEFINE_CARD(CShardOfBrokenGlassCard);
		DEFINE_CARD(CSkeletonKeyCard);
		DEFINE_CARD(CSlayersPlateCard);
		DEFINE_CARD(CTamiyosJournalCard);
		DEFINE_CARD(CChaplainsBlessingCard);
		DEFINE_CARD(CDevilsPlaygroundCard);
		DEFINE_CARD(CGoneMissingCard);
		DEFINE_CARD(CPressForAnswersCard);
		DEFINE_CARD(CReduceToAshesCard);
		DEFINE_CARD(CRootOutCard);
		DEFINE_CARD(CShambleBackCard);
		DEFINE_CARD(CBurnFromWithinCard);
		DEFINE_CARD(CAlmsOfTheVeinCard);
		DEFINE_CARD(CAngelicPurgeCard);
		DEFINE_CARD(CBeholdTheBeyondCard);
		DEFINE_CARD(CBitingRainCard);
		DEFINE_CARD(CDeclarationInStoneCard);
		DEFINE_CARD(CDescendUponTheSinfulCard);
		DEFINE_CARD(CEtherealGuidanceCard);
		DEFINE_CARD(CForkInTheRoadCard);
		DEFINE_CARD(CFromUnderTheFloorboardsCard);
		DEFINE_CARD(CGisasBiddingCard);
		DEFINE_CARD(CLilianasIndignationCard);
		DEFINE_CARD(CMalevolentWhispersCard);
		DEFINE_CARD(CMurderousCompulsionCard);
		DEFINE_CARD(CNaggingThoughtsCard);
		DEFINE_CARD(CNotForgottenCard);
		DEFINE_CARD(COpenTheArmoryCard);
		DEFINE_CARD(CPickTheBrainCard);
		DEFINE_CARD(CPiecesOfThePuzzleCard);
		DEFINE_CARD(CPoreOverThePagesCard);
		DEFINE_CARD(CRabidBiteCard);
		DEFINE_CARD(CRiseFromTheTidesCard);
		DEFINE_CARD(CStructuralDistortionCard);
		DEFINE_CARD(CTraverseTheUlvenwaldCard);
		DEFINE_CARD(CWelcomeToTheFoldCard);
		DEFINE_CARD(CAimHighCard);
		DEFINE_CARD(CAnguishedUnmakingCard);
		DEFINE_CARD(CConfirmSuspicionsCard);
		DEFINE_CARD(CDanceWithDevilsCard);
		DEFINE_CARD(CDenyExistenceCard);
		DEFINE_CARD(CDualShotCard);
		DEFINE_CARD(CExposeEvilCard);
		DEFINE_CARD(CGrotesqueMutationCard);
		DEFINE_CARD(CHumbleTheBruteCard);
		DEFINE_CARD(CInvasiveSurgeryCard);
		DEFINE_CARD(CJacesScrutinyCard);
		DEFINE_CARD(CRushOfAdrenalineCard);
		DEFINE_CARD(CSilverstrikeCard);
		DEFINE_CARD(CSurviveTheNightCard);
		DEFINE_CARD(CUncagedFuryCard);
		DEFINE_CARD(CBrokenConcentrationCard);
		DEFINE_CARD(CJustTheWindCard);
		DEFINE_CARD(CClipWingsCard);
		DEFINE_CARD(CCompellingDeterrenceCard);
		DEFINE_CARD(CConfrontTheUnknownCard);
		DEFINE_CARD(CDissensionInTheRanksCard);
		DEFINE_CARD(CEngulfTheShoreCard);
		DEFINE_CARD(CEssenceFluxCard);
		DEFINE_CARD(CInnerStruggleCard);
		DEFINE_CARD(CMercilessResolveCard);
		DEFINE_CARD(CMightBeyondReasonCard);
		DEFINE_CARD(CMoonlightHuntCard);
		DEFINE_CARD(CStrengthOfArmsCard);
		DEFINE_CARD(CTenacityCard);
		DEFINE_CARD(CToTheSlaughterCard);
		DEFINE_CARD(CBoundByMoonsilverCard);
		DEFINE_CARD(CGryffsBoonCard);
		DEFINE_CARD(CSpitefulMotivesCard);
		DEFINE_CARD(CAlwaysWatchingCard);
		DEFINE_CARD(CCallTheBloodlineCard);
		DEFINE_CARD(CHowlpackResurgenceCard);
		DEFINE_CARD(CNahirisMachinationsCard);
		DEFINE_CARD(CTrailOfEvidenceCard);
		DEFINE_CARD(CVesselOfEphemeraCard);
		DEFINE_CARD(CVesselOfMalignityCard);
		DEFINE_CARD(CVesselOfVolatilityCard);
		DEFINE_CARD(CBehindTheScenesCard);
		DEFINE_CARD(CCrawlingSensationCard);
		DEFINE_CARD(CCryptolithRiteCard);
		DEFINE_CARD(CEquestrianSkillCard);
		DEFINE_CARD(CFeveredVisionsCard);
		DEFINE_CARD(CFleetingMemoriesCard);
		DEFINE_CARD(COngoingInvestigationCard);
		DEFINE_CARD(CSenselessRageCard);
		DEFINE_CARD(CSinisterConcoctionCard);
		DEFINE_CARD(CSleepParalysisCard);
		DEFINE_CARD(CStensiaMasqueradeCard);
		DEFINE_CARD(CUlvenwaldMysteriesCard);
		DEFINE_CARD(CVesselOfNascencyCard);
		DEFINE_CARD(CVesselOfParamnesiaCard);
		DEFINE_CARD(CBygoneBishopCard);
		DEFINE_CARD(CCatharsCompanionCard);
		DEFINE_CARD(CDauntlessCatharCard);
		DEFINE_CARD(CInquisitorsOxCard);
		DEFINE_CARD(CMilitantInquisitorCard);
		DEFINE_CARD(CMoorlandDrifterCard);
		DEFINE_CARD(CNearheathChaplainCard);
		DEFINE_CARD(CParanoidParishBladeCard);
		DEFINE_CARD(CSpectralShepherdCard);
		DEFINE_CARD(CSternConstableCard);
		DEFINE_CARD(CThrabenInspectorCard);
		DEFINE_CARD(CAvacynThePurifierCard);
		DEFINE_CARD(CWaywardDiscipleCard);
		DEFINE_CARD(CTownGossipmongerCard);
		DEFINE_CARD(CIncitedRabbleCard);
		DEFINE_CARD(CAngelOfDeliveranceCard);
		DEFINE_CARD(CApothecaryGeistCard);
		DEFINE_CARD(CArchangelAvacynCard);
		DEFINE_CARD(CDrogskolCavalryCard);
		DEFINE_CARD(CEmissaryOfTheSleeplessCard);
		DEFINE_CARD(CInspiringCaptainCard);
		DEFINE_CARD(CPiousEvangelCard);
		DEFINE_CARD(CReaperOfFlightMoonsilverCard);
		DEFINE_CARD(CThaliasLieutenantCard);
		DEFINE_CARD(CTopplegeistCard);
		DEFINE_CARD(CBywayCourierCard);
		DEFINE_CARD(CDeathcapCultivatorCard);
		DEFINE_CARD(CIntrepidProvisionerCard);
		DEFINE_CARD(CKessigDireSwineCard);
		DEFINE_CARD(CMoldgrafScavengerCard);
		DEFINE_CARD(CQuilledWolfCard);
		DEFINE_CARD(CStoicBuilderCard);
		DEFINE_CARD(CUlvenwaldHydraCard);
		DEFINE_CARD(CVeteranCatharCard);
		DEFINE_CARD(CWatcherInTheWebCard);
		DEFINE_CARD(CKrallenhordeHowlerCard);
		DEFINE_CARD(CLoneWolfOfTheNatterknollsCard);
		DEFINE_CARD(CTimberShredderCard);
		DEFINE_CARD(COneOfThePackCard);
		DEFINE_CARD(CBriarbridgePatrolCard);
		DEFINE_CARD(CCultOfTheWaxingMoonCard);
		DEFINE_CARD(CDuskwatchRecruiterCard);
		DEFINE_CARD(CGrafMoleCard);
		DEFINE_CARD(CHermitOfTheNatterknollsCard);
		DEFINE_CARD(CHinterlandLoggerCard);
		DEFINE_CARD(CInexorableBlobCard);
		DEFINE_CARD(CLoamDryadCard);
		DEFINE_CARD(CObsessiveSkinnerCard);
		DEFINE_CARD(CPackGuardianCard);
		DEFINE_CARD(CSolitaryHunterCard);
		DEFINE_CARD(CSoulSwallowerCard);
		DEFINE_CARD(CTirelessTrackerCard);
		DEFINE_CARD(CEmberEyeWolfCard);
		DEFINE_CARD(CHowlpackWolfCard);
		DEFINE_CARD(CInsolentNeonateCard);
		DEFINE_CARD(CRavenousBloodseekerCard);
		DEFINE_CARD(CScourgeWolfCard);
		DEFINE_CARD(CUlrichsKindredCard);
		DEFINE_CARD(CVoldarenDuelistCard);
		DEFINE_CARD(CNeckBreakerCard);
		DEFINE_CARD(CBrandedHowlerCard);
		DEFINE_CARD(CGatstafRavagersCard);
		DEFINE_CARD(CVildinPackAlphaCard);
		DEFINE_CARD(CFlameheartWerewolfCard);
		DEFINE_CARD(CMoonriseIntruderCard);
		DEFINE_CARD(CBloodmadVampireCard);
		DEFINE_CARD(CBreakneckRiderCard);
		DEFINE_CARD(CConvictedKillerCard);
		DEFINE_CARD(CFlamebladeAngelCard);
		DEFINE_CARD(CGatstafArsonistsCard);
		DEFINE_CARD(CGeierReachBanditCard);
		DEFINE_CARD(CGibberingFiendCard);
		DEFINE_CARD(CIncorrigibleYouthsCard);
		DEFINE_CARD(CKessigForgemasterCard);
		DEFINE_CARD(CPyreHoundCard);
		DEFINE_CARD(CVillageMessengerCard);
		DEFINE_CARD(CFarbogRevenantCard);
		DEFINE_CARD(CGhoulcallersAccompliceCard);
		DEFINE_CARD(CGhoulsteedCard);
		DEFINE_CARD(CHoundOfTheFarbogsCard);
		DEFINE_CARD(CMarkovDreadknightCard);
		DEFINE_CARD(COliviasBloodswornCard);
		DEFINE_CARD(CPaleRiderOfTrostadCard);
		DEFINE_CARD(CRancidRatsCard);
		DEFINE_CARD(CRottenheartGhoulCard);
		DEFINE_CARD(CSanitariumSkeletonCard);
		DEFINE_CARD(CStromkirkMentorCard);
		DEFINE_CARD(CInsidiousMistCard);
		DEFINE_CARD(CHeirToTheNightCard);
		DEFINE_CARD(CDemonPossessedWitchCard);
		DEFINE_CARD(CElusiveTormentorCard);
		DEFINE_CARD(CHeirOfFalkenrathCard);
		DEFINE_CARD(CAsylumVisitorCard);
		DEFINE_CARD(CCrowOfDarkTidingsCard);
		DEFINE_CARD(CDiregrafColossusCard);
		DEFINE_CARD(CIndulgentAristocratCard);
		DEFINE_CARD(CKindlyStrangerCard);
		DEFINE_CARD(CMindwrackDemonCard);
		DEFINE_CARD(CMorkrutNecropodCard);
		DEFINE_CARD(CRelentlessDeadCard);
		DEFINE_CARD(CStallionOfAshmouthCard);
		DEFINE_CARD(CToothCollectorCard);
		DEFINE_CARD(CTwinsOfMaurerEstateCard);
		DEFINE_CARD(CDrownyardExplorersCard);
		DEFINE_CARD(CDrunauCorpseTrawlerCard);
		DEFINE_CARD(CFurtiveHomunculusCard);
		DEFINE_CARD(CGeralfsMasterpieceCard);
		DEFINE_CARD(CNephaliaMoondrakesCard);
		DEFINE_CARD(CRattlechainsCard);
		DEFINE_CARD(CStitchedManglerCard);
		DEFINE_CARD(CStitchwingSkaabCard);
		DEFINE_CARD(CStormriderSpiritCard);
		DEFINE_CARD(CPerfectedFormCard);
		DEFINE_CARD(CBearerOfOverwhelmingTruthsCard);
		DEFINE_CARD(CAwokenHorrorCard);
		DEFINE_CARD(CUnimpededTrespasserCard);
		DEFINE_CARD(CAberrantResearcherCard);
		DEFINE_CARD(CDaringSleuthCard);
		DEFINE_CARD(CForgottenCreationCard);
		DEFINE_CARD(CLamplighterOfSelhoffCard);
		DEFINE_CARD(CManicScribeCard);
		DEFINE_CARD(CThingInTheIceCard);
		DEFINE_CARD(CUninvitedGeistCard);
		DEFINE_CARD(CSigardaHeronsGraceCard);
		DEFINE_CARD(COliviaMobilizedForWarCard);
		DEFINE_CARD(CTheGitrogMonsterCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
CDevilthornFoxCard::CDevilthornFoxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Devilthorn Fox"), CardType::Creature, CREATURE_TYPE(Fox), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
{
}

//____________________________________________________________________________
//
CHulkingDevilCard::CHulkingDevilCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hulking Devil"), CardType::Creature, CREATURE_TYPE(Devil), nID,
		_T("3") RED_MANA_TEXT, Power(5), Life(2))
{
}

//____________________________________________________________________________
//
CNiblisOfDuskCard::CNiblisOfDuskCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Niblis of Dusk"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// prowess
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));

	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSeagrafSkaabCard::CSeagrafSkaabCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Seagraf Skaab"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
}

//____________________________________________________________________________
//
CThornhideWolvesCard::CThornhideWolvesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thornhide Wolves"), CardType::Creature, CREATURE_TYPE(Wolf), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(5))
{
}

//____________________________________________________________________________
//
CVampireNobleCard::CVampireNobleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vampire Noble"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
}

//____________________________________________________________________________
//
CWarpedLandscapeCard::CWarpedLandscapeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Warped Landscape"), nID)
{
	counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));

	cpNonbasicLandManaAbility->AddTapCost();

	AddAbility(cpNonbasicLandManaAbility.GetPointer());

	{
		counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
				_T("2"), 
				CCardFilter::GetFilter(_T("basic lands")),		
				ZoneId::Battlefield, FALSE, TRUE, TRUE));

		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();

		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSilentObserverCard::CSilentObserverCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Silent Observer"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("3") BLUE_MANA_TEXT, Power(1), Life(5))
{
}

//____________________________________________________________________________
//
CSanguinaryMageCard::CSanguinaryMageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sanguinary Mage"), CardType::Creature, CREATURE_TYPE2(Vampire, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// prowess
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));

	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CChokedEstuaryCard::CChokedEstuaryCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Choked Estuary"), nID, CardType::NonbasicLand)
	, m_CardFilter(_T("an Island or a Swamp"), _T("Islands or Swamps"), new CardTypeComparer(CardType::Island | CardType::Swamp, false))
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 1, _T("reveal"), &m_CardFilter);
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CForebodingRuinsCard::CForebodingRuinsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Foreboding Ruins"), nID, CardType::NonbasicLand)
	, m_CardFilter(_T("a Swamp or a Mountain"), _T("Swamps or Mountains"), new CardTypeComparer(CardType::Swamp | CardType::Mountain, false))
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 1, _T("reveal"), &m_CardFilter);
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CFortifiedVillageCard::CFortifiedVillageCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Fortified Village"), nID, CardType::NonbasicLand)
	, m_CardFilter(_T("a Forest or a Plains"), _T("Forests or Plains"), new CardTypeComparer(CardType::Forest | CardType::Plains, false))
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 1, _T("reveal"), &m_CardFilter);
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CGameTrailCard::CGameTrailCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Game Trail"), nID, CardType::NonbasicLand)
	, m_CardFilter(_T("a Mountain or a Forest"), _T("Mountains or Forests"), new CardTypeComparer(CardType::Mountain | CardType::Forest, false))
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 1, _T("reveal"), &m_CardFilter);
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CPortTownCard::CPortTownCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Port Town"), nID, CardType::NonbasicLand)
	, m_CardFilter(_T("a Plains or an Island"), _T("Plains or Islands"), new CardTypeComparer(CardType::Plains | CardType::Island, false))
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 1, _T("reveal"), &m_CardFilter);
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CDrownyardTempleCard::CDrownyardTempleCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Drownyard Temple"), nID)
{
	{//{T}: Add {1} to your mana pool.
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{//{3}: Return Drownyard Temple from your graveyard to the battlefield tapped.	
		counted_ptr<CSelfMoveCardAbility> cpAbility(
			::CreateObject<CSelfMoveCardAbility>(this,
				_T("3"),
				ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->SetGraveyardOnly();

		cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));//To tap this card on resolution.

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CHighlandLakeCard::CHighlandLakeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Highland Lake"), nID)
{
	SetIntoPlayTapped();
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CWoodlandStreamCard::CWoodlandStreamCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Woodland Stream"), nID)
{
	SetIntoPlayTapped();
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CFoulOrchardCard::CFoulOrchardCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Foul Orchard"), nID)
{
	SetIntoPlayTapped();
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CForsakenSanctuaryCard::CForsakenSanctuaryCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Forsaken Sanctuary"), nID)
{
	SetIntoPlayTapped();
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CStoneQuarryCard::CStoneQuarryCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Stone Quarry"), nID)
{
	SetIntoPlayTapped();
	{
		counted_ptr<CManaProductionAbility> cpNonbasicLandManaAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));

		cpNonbasicLandManaAbility->AddTapCost();

		AddAbility(cpNonbasicLandManaAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// Planeswalkers

// Adds the trait that makes the ability usable only on the first or on the second face
static void AddFaceTrait(CAbility* pAbility, CCard* pCard, CPlayableIfTrait::PlayableCallback callback)
{
	counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(pAbility, callback));
	pAbility->Add(cpTrait.GetPointer());
}

CArlinnKordCard::CArlinnKordCard(CGame* pGame, UINT nID)
	: CDoubleFacedPlaneswalkerCard(pGame, _T("Arlinn Kord"), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Arlinn, 3, _T("Arlinn, Embraced by the Moon"))
{
	// First face (as Garruk Relentless)
	{
		// +1: Until end of turn, up to one target creature gets +2/+2 and gains vigilance and haste.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T(""),
				Power(+2), Life(+2),
				CreatureKeyword::Vigilance | CreatureKeyword::Haste, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		AddFaceTrait(cpAbility.GetPointer(), this, CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedPlaneswalkerCard::CanPlayFirstFace));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// 0: Create a 2/2 green Wolf creature token. Transform Arlinn Kord.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				_T("Wolf (K)"), 55004,
				1));

		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
		cpAbility->SetAbilityText(_T("0: Create a 2/2 green Wolf creature token. Transform Arlinn Kord."));
		AddFaceTrait(cpAbility.GetPointer(), this, CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedPlaneswalkerCard::CanPlayFirstFace));
		AddAbility(cpAbility.GetPointer());
	}

	// Second face: Arlinn, Embraced by the Moon
	{
		// +1: Creatures you control get +1/+1 and gain trample until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArlinnKordCard::BeforeResolutionPump));
		cpAbility->SetAbilityText(_T("+1: Creatures you control get +1/+1 and gain trample until end of turn."));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddFaceTrait(cpAbility.GetPointer(), this, CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedPlaneswalkerCard::CanPlaySecondFace));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -1: Arlinn deals 3 damage to any target. Transform Arlinn.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-3), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddFaceTrait(cpAbility.GetPointer(), this, CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedPlaneswalkerCard::CanPlaySecondFace));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -6: You get an emblem with "Creatures you control have haste and '{T}: This creature deals damage equal to its power to any target.'"
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -6);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), _T("Arlinn, Embraced by the Moon Emblem"), 61144, 1, FALSE, ZoneId::_Effects));
		cpAbility->SetAbilityText(_T("-6: You get an emblem with - Creatures you control have haste and '{T}: This creature deals damage equal to its power to any target.'"));
		AddFaceTrait(cpAbility.GetPointer(), this, CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedPlaneswalkerCard::CanPlaySecondFace));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CArlinnKordCard::BeforeResolutionPump(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CCreatureKeywordModifier pTrampleModifier;
	pTrampleModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pTrampleModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
		pTrampleModifier.ApplyTo((CCreatureCard*)pCard);
	}

	return true;
}

CArlinnEmbracedByTheMoonCard::CArlinnEmbracedByTheMoonCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Arlinn, Embraced by the Moon"), nID,
		_T(""),
		PlaneswalkerType::Arlinn, 0)
{
	AddCardType(CardType::Red | CardType::Green, CardType::_ColorMask);
}

CJaceUnravelerOfSecretsCard::CJaceUnravelerOfSecretsCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Jace, Unraveler of Secrets"), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT,
		PlaneswalkerType::Jace, 5)
{
	{
		// +1: Scry 1, then draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJaceUnravelerOfSecretsCard::BeforeResolution1));
		cpAbility->SetAbilityText(_T("+1: Scry 1, then draw a card."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Return target creature to its owner's hand.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: You get an emblem with "Whenever an opponent casts their first spell each turn, counter that spell."
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), _T("Jace, Unraveler of Secrets Emblem"), 61143, 1, FALSE, ZoneId::_Effects));
		cpAbility->SetAbilityText(_T("-8: You get an emblem with - Whenever an opponent casts their first spell each turn, counter that spell."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CJaceUnravelerOfSecretsCard::BeforeResolution1(CAbilityAction* pAction) const
{
	// Scry 1, then draw a card (as Ugin's Insight)
	CScryModifier(GetGame(), 1, (CCard*)this).ApplyTo(pAction->GetController());

	CDrawCardModifier pModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
	pModifier.ApplyTo(pAction->GetController());

	return true;
}

// Enchantment, tapped artifact, or tapped creature
struct NahiriTargetComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		if ((pCard->GetCardType() & CardType::_Enchantment).Any())
			return true;

		return ((pCard->GetCardType() & (CardType::Artifact | CardType::Creature)).Any()) && pCard->GetOrientation()->IsTapped();
	}

	virtual NahiriTargetComparer* Clone() const
	{
		return new NahiriTargetComparer;
	}
};

CNahiriTheHarbingerCard::CNahiriTheHarbingerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nahiri, the Harbinger"), nID,
		_T("2") RED_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Nahiri, 4)
	, m_DiscardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNahiriTheHarbingerCard::OnDiscardSelected))
	, m_SearchSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNahiriTheHarbingerCard::OnSearchSelected))
{
	{
		// +2: You may discard a card. If you do, draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNahiriTheHarbingerCard::BeforeResolution1));
		cpAbility->SetAbilityText(_T("+2: You may discard a card. If you do, draw a card."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Exile target enchantment, tapped artifact, or tapped creature.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new NahiriTargetComparer,
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: Search your library for an artifact or creature card, put it onto the battlefield, then shuffle.
		// It gains haste. Return it to your hand at the beginning of the next end step.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNahiriTheHarbingerCard::BeforeResolution3));
		cpAbility->SetAbilityText(_T("-8: Search your library for an artifact or creature card, put it onto the battlefield, then shuffle. It gains haste. Return it to your hand at the beginning of the next end step."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNahiriTheHarbingerCard::BeforeResolution1(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	if (pHand->GetSize() == 0)
		return true;

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Discard %s and draw a card"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}
	{
		SelectionEntry entry;

		entry.dwContext = 0;
		entry.strText = _T("Don't discard");

		entries.push_back(entry);
	}

	m_DiscardSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CNahiriTheHarbingerCard::OnDiscardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
			pDrawModifier.ApplyTo(pSelectionPlayer);

			return;
		}
}

bool CNahiriTheHarbingerCard::BeforeResolution3(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pLibrary->GetSize(); ++i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		if (!(pCard->GetCardType() & (CardType::Artifact | CardType::Creature)).Any())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (entries.empty())
	{
		pLibrary->Shuffle();
		return true;
	}

	{
		SelectionEntry entry;

		entry.dwContext = 0;
		entry.strText = _T("Don't put a card onto the battlefield");

		entries.push_back(entry);
	}

	m_SearchSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CNahiriTheHarbingerCard::OnSearchSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Battlefield, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				// It gains haste
				if (pCard->GetCardType().IsCreature())
				{
					CCreatureKeywordModifier pHasteModifier;
					pHasteModifier.GetModifier().SetToAdd(CreatureKeyword::Haste);
					pHasteModifier.GetModifier().SetOneTurnOnly(TRUE);
					pHasteModifier.ApplyTo((CCreatureCard*)pCard);
				}

				// Return it to your hand at the beginning of the next end step (as Avacyn Restored's "until end of turn" control)
				CScheduledCardModifier pReturnModifier = CScheduledCardModifier(GetGame(),
					new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others),
					TurnNumberDelta(-1), NodeId::EndStep, true, CScheduledCardModifier::Operation::ApplyToLater);
				pReturnModifier.ApplyTo(pCard);
			}
			break;
		}

	pSelectionPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

CSorinGrimNemesisCard::CSorinGrimNemesisCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Sorin, Grim Nemesis"), nID,
		_T("4") WHITE_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Sorin, 6)
{
	{
		// +1: Reveal the top card of your library and put that card into your hand. Each opponent loses life equal to its mana value.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorinGrimNemesisCard::BeforeResolution1));
		cpAbility->SetAbilityText(_T("+1: Reveal the top card of your library and put that card into your hand. Each opponent loses life equal to its mana value."));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -X: Sorin deals X damage to target creature or planeswalker and you gain X life. (X as Chandra, Flamecaller)
		// Note: only creatures can be targeted.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), SpecialNumber::AnyNegative);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorinGrimNemesisCard::BeforeResolutionX));
		cpAbility->SetAbilityText(_T("-X: Sorin deals X damage to target creature and you gain X life."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -9: Create a number of 1/1 black Vampire Knight creature tokens with lifelink equal to the highest life total among all players.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSorinGrimNemesisCard::BeforeResolution3));
		cpAbility->SetAbilityText(_T("-9: Create a number of 1/1 black Vampire Knight creature tokens with lifelink equal to the highest life total among all players."));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSorinGrimNemesisCard::BeforeResolution1(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	int nManaValue = pCard->GetConvertedManaCost();

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pController);
	pModifier.ApplyTo(pCard);

	if (nManaValue > 0)
	{
		CLifeModifier pLifeModifier = CLifeModifier(Life(-nManaValue), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
			if (GetGame()->GetPlayer(i) != pController)
				pLifeModifier.ApplyTo(GetGame()->GetPlayer(i));
	}

	return true;
}

bool CSorinGrimNemesisCard::BeforeResolutionX(CAbilityAction* pAction) const
{
	int nX = -pAction->GetCostConfigEntry().GetExtraValue();
	if (nX <= 0)
		return true;

	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetCardType().IsCreature() && pTarget->GetZoneId() == ZoneId::Battlefield)
	{
		CLifeModifier pDamageModifier = CLifeModifier(Life(-nX), (CCard*)this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pDamageModifier.ApplyTo((CCreatureCard*)pTarget);
	}

	CLifeModifier pGainModifier = CLifeModifier(Life(+nX), (CCard*)this, PreventableType::NotPreventable);
	pGainModifier.ApplyTo(pAction->GetController());

	return true;
}

bool CSorinGrimNemesisCard::BeforeResolution3(CAbilityAction* pAction) const
{
	int nHighest = 0;
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		if (GET_INTEGER(GetGame()->GetPlayer(i)->GetLife()) > nHighest)
			nHighest = GET_INTEGER(GetGame()->GetPlayer(i)->GetLife());

	if (nHighest > 0)
	{
		CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Vampire Knight (A)"), 55077, nHighest);
		pModifier.ApplyTo(pAction->GetController());
	}

	return true;
}

//____________________________________________________________________________
//
// Artifacts

CCorruptedGrafstoneCard::CCorruptedGrafstoneCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Corrupted Grafstone"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// This artifact enters tapped.
	SetIntoPlayTapped();

	// {T}: Choose a color of a card in your graveyard. Add one mana of that color.
	// (one mana ability for each color, usable only while there is a card of that color in your graveyard)
	LPCTSTR manas[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	CPlayableIfTrait::PlayableCallback callbacks[] = {
		CPlayableIfTrait::PlayableCallback(this, &CCorruptedGrafstoneCard::CanAddWhite),
		CPlayableIfTrait::PlayableCallback(this, &CCorruptedGrafstoneCard::CanAddBlue),
		CPlayableIfTrait::PlayableCallback(this, &CCorruptedGrafstoneCard::CanAddBlack),
		CPlayableIfTrait::PlayableCallback(this, &CCorruptedGrafstoneCard::CanAddRed),
		CPlayableIfTrait::PlayableCallback(this, &CCorruptedGrafstoneCard::CanAddGreen) };

	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, manas[i]));
		cpAbility->AddTapCost();

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(), callbacks[i]));
		cpAbility->Add(cpTrait.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CCorruptedGrafstoneCard::HasColorInGraveyard(CardType color) const
{
	CZone* pGraveyard = GetController()->GetZoneById(ZoneId::Graveyard);
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if ((pGraveyard->GetAt(i)->GetCardType() & color).Any())
			return TRUE;
	return FALSE;
}

BOOL CCorruptedGrafstoneCard::CanAddWhite(BOOL bIncludeTricks)	{ return HasColorInGraveyard(CardType::White); }
BOOL CCorruptedGrafstoneCard::CanAddBlue(BOOL bIncludeTricks)	{ return HasColorInGraveyard(CardType::Blue); }
BOOL CCorruptedGrafstoneCard::CanAddBlack(BOOL bIncludeTricks)	{ return HasColorInGraveyard(CardType::Black); }
BOOL CCorruptedGrafstoneCard::CanAddRed(BOOL bIncludeTricks)	{ return HasColorInGraveyard(CardType::Red); }
BOOL CCorruptedGrafstoneCard::CanAddGreen(BOOL bIncludeTricks)	{ return HasColorInGraveyard(CardType::Green); }

CEpitaphGolemCard::CEpitaphGolemCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Epitaph Golem"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Golem), nID, _T("5"), Power(3), Life(5))
{
	// {2}: Put target card from your graveyard on the bottom of your library.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2"),
			new TrueCardComparer,
			ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others));

	cpAbility->GetTargeting()->SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->SetCardPlacement(CardPlacement::Bottom);
	AddAbility(cpAbility.GetPointer());
}

CExplosiveApparatusCard::CExplosiveApparatusCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Explosive Apparatus"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {3}, {T}, Sacrifice this artifact: It deals 2 damage to any target.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("3"),
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

CHauntedCloakCard::CHauntedCloakCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Haunted Cloak"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	// Equipped creature has vigilance, trample, and haste. Equip {1}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Vigilance | CreatureKeyword::Trample | CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CMagnifyingGlassCard::CMagnifyingGlassCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Magnifying Glass"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// {T}: Add {C}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}, {T}: Investigate.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4")));

		cpAbility->AddTapCost();
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

CMurderersAxeCard::CMurderersAxeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Murderer's Axe"), CardType::Artifact | CardType::Equipment, nID,
		_T("4"), AbilityType::Artifact)
{
	// Equipped creature gets +2/+2. Equip-Discard a card.
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+2), this,
		PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CRunawayCarriageCard::CRunawayCarriageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Runaway Carriage"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Construct), nID, _T("4"), Power(5), Life(6))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature attacks or blocks, sacrifice it at end of combat. (as Crumbling Colossus)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::EventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingOrBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRunawayCarriageCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CRunawayCarriageCard::BeforeResolution(CAbilityAction* pAction)
{
	CCountedCardContainer pSubjects;

	if (IsInplay())
		pSubjects.AddCard(this, CardPlacement::Top);

	CContainerEffectModifier pModifier = CContainerEffectModifier(GetGame(), _T("End of Combat Sacrifice Effect"), 61106, &pSubjects);
	pModifier.ApplyTo(pAction->GetController());

	return true;
}

CShardOfBrokenGlassCard::CShardOfBrokenGlassCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Shard of Broken Glass"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature gets +1/+0. Equip {1}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CShardOfBrokenGlassCard::CreateEquipmentAbility)));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CShardOfBrokenGlassCard::CreateEquipmentAbility(CCard* pCard)
{
	// Whenever equipped creature attacks, you may mill two cards. (as Captain's Claws)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShardOfBrokenGlassCard::BeforeMill));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CShardOfBrokenGlassCard::BeforeMill(CAbilityAction* pAction) const
{
	CZone* pLibrary = pAction->GetController()->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < 2 && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));

	return true;
}

CSkeletonKeyCard::CSkeletonKeyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Skeleton Key"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	// Equipped creature has skulk. Equip {2}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Skulk);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);
	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CSkeletonKeyCard::CreateEquipmentAbility)));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CSkeletonKeyCard::CreateEquipmentAbility(CCard* pCard)
{
	// Whenever equipped creature deals combat damage to a player, you may draw a card. If you do, discard a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetDrawCount(1);
	cpAbility->SetDiscard(1, FALSE, MoveType::Discard);

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CSlayersPlateCard::CSlayersPlateCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Slayer's Plate"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	// Equipped creature gets +4/+2. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+2), this,
		PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+4), FALSE));
	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CSlayersPlateCard::CreateEquipmentAbility)));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CSlayersPlateCard::CreateEquipmentAbility(CCard* pCard)
{
	// Whenever equipped creature dies, if it was a Human, create a 1/1 white Spirit creature token with flying.
	// Note: whether it is a Human is checked when the Equipment becomes attached.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

	BOOL bHuman = pCard->GetCardType().IsCreature() &&
		((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Human);
	cpAbility->SetCreateTokenOption(TRUE, _T("Spirit (O)"), 55008, bHuman ? 1 : 0);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CTamiyosJournalCard::CTamiyosJournalCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Tamiyo's Journal"), CardType::_LegendaryArtifact, nID,
		_T("5"), AbilityType::Artifact)
	, m_ClueFilter(_T("a Clue"), _T("Clues"), new CardNameComparer(_T("Clue")))
{
	{
		// At the beginning of your upkeep, investigate.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Sacrifice three Clues: Search your library for a card, put that card into your hand, then shuffle.
		counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
				_T(""),
				CCardFilter::GetFilter(_T("cards")),
				ZoneId::Hand, TRUE, FALSE, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(3, &m_ClueFilter);
		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
		AddAbility(cpAbility.GetPointer());
	}
}

CThrabenGargoyleCard::CThrabenGargoyleCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Thraben Gargoyle"), CardType::_ArtifactCreature, CREATURE_TYPE(Gargoyle), nID,
		_T("1"), Power(2), Life(2), Power(4), Life(2), _T("Stonewing Antagonizer"))
{
	// Defender (first face). The second face is a Gargoyle Horror with flying.
	GetCreatureKeyword()->AddDefender(FALSE);

	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier;
	pKeywordModifier->GetModifier().SetToAdd(CreatureKeyword::Flying);
	pKeywordModifier->GetModifier().SetToRemove(CreatureKeyword::Defender);
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	AddCreatureModifier(pKeywordModifier);
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, TRUE));

	// {6}: Transform this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("6")));

	cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedCreatureCard::CanPlayFirstFace)));
	cpAbility->Add(cpTrait.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

// Back face of Thraben Gargoyle (as Nightfall Predator): its abilities are in CThrabenGargoyleCard
CStonewingAntagonizerCard::CStonewingAntagonizerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Stonewing Antagonizer"), CardType::_ArtifactCreature, CREATURE_TYPE2(Gargoyle, Horror), nID,
		_T(""), Power(4), Life(2), Power(2), Life(2), _T("Thraben Gargoyle"))
{
	GetCreatureKeyword()->AddFlying(FALSE);
}

CWickerWitchCard::CWickerWitchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wicker Witch"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Scarecrow), nID, _T("3"), Power(3), Life(1))
{
}

CWildFieldScarecrowCard::CWildFieldScarecrowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wild-Field Scarecrow"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Scarecrow), nID, _T("3"), Power(1), Life(4))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	// {2}, Sacrifice this creature: Search your library for up to two basic land cards, reveal them, put them into your hand, then shuffle.
	counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
		::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
			_T("2"),
			CCardFilter::GetFilter(_T("basic lands")),
			ZoneId::Hand, TRUE, FALSE, FALSE));

	cpAbility->AddSacrificeCost();
	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(2));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Madness

CMadnessSupport::CMadnessSupport(CCard* pCard)
	: m_pCard(pCard)
{
}

void CMadnessSupport::SetMadnessSpell(CSpell* pMadnessSpell)
{
	m_pCard->GetCardKeyword()->AddMadness(FALSE);

	pMadnessSpell->SetAbilityName(_T("Madness"));
	pMadnessSpell->SetPlayableFrom(ZoneId::Exile);
	pMadnessSpell->SetMainSpell(FALSE);

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(pMadnessSpell,
			CPlayableIfTrait::PlayableCallback(this, &CMadnessSupport::CanCastMadness)));
	pMadnessSpell->Add(cpTrait.GetPointer());

	typedef
		TTriggeredAbility< CTriggeredMadnessAbility, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetTriggerIndex(666);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(m_pCard));

	m_pCard->AddAbility(cpAbility.GetPointer());
}

BOOL CMadnessSupport::CanCastMadness(BOOL bIncludeTricks)
{
	return m_pCard->GetCardKeyword()->HasFreecast();
}

//____________________________________________________________________________
//
// Sorceries

// Creates nCount tapped 2/2 black Zombie creature tokens (as Drana's Chosen in Oath of the Gatewatch)
static void CreateTappedZombies(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	if (nCount <= 0)
		return;

	CCountedCardContainer createdCards;
	CTokenCreationModifier pModifier = CTokenCreationModifier(pGame, _T("Zombie (P)"), 55009, nCount,
		FALSE, ZoneId::Battlefield, &createdCards);
	pModifier.ApplyTo(pPlayer);

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < createdCards.GetSize(); ++i)
		pTapModifier.ApplyTo(createdCards.GetAt(i));
}

// Exile instead of dying this turn (as Flaying Tendrils in Oath of the Gatewatch)
static CCardModifier* CreateExileInsteadModifier()
{
	CReplacementKeywordModifier* pModifier = new CReplacementKeywordModifier;
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	pModifier->GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	return pModifier;
}

CAlmsOfTheVeinCard::CAlmsOfTheVeinCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Alms of the Vein"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// Target opponent loses 3 life and you gain 3 life. Madness {B}
	LPCTSTR costs[] = { _T("2") BLACK_MANA_TEXT, BLACK_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				costs[i],
				FALSE_CARD_COMPARER, TRUE,
				Life(-3), PreventableType::NotPreventable));

		cpSpell->SetDamageType(DamageType::NotDealingDamage);	// life lost
		cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+3), this, PreventableType::NotPreventable));
		cpSpell->AddAbilityTag(AbilityTag::LifeLost);
		cpSpell->AddAbilityTag(AbilityTag::LifeGain);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CAngelicPurgeCard::CAngelicPurgeCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Angelic Purge"), CardType::Sorcery, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment, false),
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
	, m_PermanentFilter(_T("a permanent"), _T("permanents"), new CardTypeComparer(CardType::_Permanent, false))
{
	// As an additional cost to cast this spell, sacrifice a permanent. Exile target artifact, creature, or enchantment.
	m_pTargetMoveCardSpell->GetCost().AddSacrificeCardCost(1, &m_PermanentFilter);
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CBeholdTheBeyondCard::CBeholdTheBeyondCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Behold the Beyond"), CardType::Sorcery, nID)
{
	// Discard your hand. Search your library for three cards, put them into your hand, then shuffle.
	counted_ptr<CSearchLibrarySpell> cpSpell(
		::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
			_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			CCardFilter::GetFilter(_T("cards")),
			ZoneId::Hand, TRUE, FALSE, FALSE));

	cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(3));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBeholdTheBeyondCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBeholdTheBeyondCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	while (pHand->GetSize() > 0)
		pModifier.ApplyTo(pHand->GetAt(pHand->GetSize() - 1));

	return true;
}

CBitingRainCard::CBitingRainCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Biting Rain"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// All creatures get -2/-2 until end of turn. Madness {2}{B}
	LPCTSTR costs[] = { _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, _T("2") BLACK_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, costs[i]));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBitingRainCard::BeforeResolution));
		cpSpell->AddAbilityTag(AbilityTag::CreatureChange);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

bool CBitingRainCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CPowerModifier pPowerModifier = CPowerModifier(Power(-2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pCreatures.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));
	}

	return true;
}

CBurnFromWithinCard::CBurnFromWithinCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Burn from Within"), CardType::Sorcery, nID)
{
	// Burn from Within deals X damage to any target. If a creature is dealt damage this way, it loses indestructible
	// until end of turn. If that creature would die this turn, exile it instead. (X as Blaze)
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(0), PreventableType::Preventable));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors);
	cpSpell->SetExtraActionValueVector(ContextValue(-1));

	CCardKeywordModifier* pIndestructibleModifier = new CCardKeywordModifier;
	pIndestructibleModifier->GetModifier().SetToRemove(CardKeyword::Indestructible);
	pIndestructibleModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(pIndestructibleModifier);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(CreateExileInsteadModifier());

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CChaplainsBlessingCard::CChaplainsBlessingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chaplain's Blessing"), CardType::Sorcery, nID)
{
	// You gain 5 life.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, WHITE_MANA_TEXT));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+5), this, PreventableType::NotPreventable));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

CDeclarationInStoneCard::CDeclarationInStoneCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Declaration in Stone"), CardType::Sorcery, nID)
{
	// Exile target creature and all other creatures its controller controls with the same name as that creature.
	// That player investigates for each nontoken creature exiled this way.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT, new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeclarationInStoneCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
	AddSpell(cpSpell.GetPointer());
}

bool CDeclarationInStoneCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pPlayer = pTarget->GetController();
	CString strName = pTarget->GetCardName(FALSE);
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer toExile;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && pCard->GetCardName(FALSE) == strName)
			toExile.AddCard(pCard, CardPlacement::Top);
	}

	int nNontoken = 0;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others);
	for (int i = 0; i < toExile.GetSize(); ++i)
	{
		CCard* pCard = toExile.GetAt(i);
		BOOL bToken = pCard->GetCardType().IsToken();
		pModifier.ApplyTo(pCard);
		if (!bToken)
			++nNontoken;
	}

	Investigate(GetGame(), pPlayer, nNontoken);
	return true;
}

CDescendUponTheSinfulCard::CDescendUponTheSinfulCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Descend upon the Sinful"), CardType::Sorcery, nID)
{
	// Exile all creatures. Delirium - Create a 4/4 white Angel creature token with flying if there are four or more
	// card types among cards in your graveyard.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDescendUponTheSinfulCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
	AddSpell(cpSpell.GetPointer());
}

bool CDescendUponTheSinfulCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others);
	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pModifier.ApplyTo(pCreatures.GetAt(i));

	if (HasDelirium(pAction->GetController()))
	{
		CTokenCreationModifier pTokenModifier = CTokenCreationModifier(GetGame(), _T("Angel (J)"), 55045, 1);
		pTokenModifier.ApplyTo(pAction->GetController());
	}

	return true;
}

CDevilsPlaygroundCard::CDevilsPlaygroundCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Devils' Playground"), CardType::Sorcery, nID)
{
	// Create four 1/1 red Devil creature tokens. They have "When this token dies, it deals 1 damage to any target."
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("4") RED_MANA_TEXT RED_MANA_TEXT,
			_T("Devil (A)"), 55079, 4));
	AddSpell(cpSpell.GetPointer());
}

CEtherealGuidanceCard::CEtherealGuidanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ethereal Guidance"), CardType::Sorcery, nID)
{
	// Creatures you control get +2/+1 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("2") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEtherealGuidanceCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::CreatureChange);
	AddSpell(cpSpell.GetPointer());
}

bool CEtherealGuidanceCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
	}

	return true;
}

CForkInTheRoadCard::CForkInTheRoadCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fork in the Road"), CardType::Sorcery, nID)
	, m_HandSelection(pGame, CSelectionSupport::SelectionCallback(this, &CForkInTheRoadCard::OnHandSelected))
	, m_GraveyardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CForkInTheRoadCard::OnGraveyardSelected))
{
	// Search your library for up to two basic land cards and reveal them. Put one into your hand and the other into
	// your graveyard. Then shuffle.
	// Note: the land for the hand is chosen first, then the one for the graveyard.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("1") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CForkInTheRoadCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

void CForkInTheRoadCard::RequestLand(CPlayer* pPlayer, CSelectionSupport& selection, LPCTSTR strFormat)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pLibrary->GetSize(); ++i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		if (!(pCard->GetCardType() & CardType::BasicLand).Any())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(strFormat, pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (entries.empty())
	{
		pLibrary->Shuffle();
		return;
	}

	SelectionEntry entry;
	entry.dwContext = 0;
	entry.strText = _T("Don't search for a land");
	entries.push_back(entry);

	selection.AddSelectionRequest(entries, 1, 1, this, pPlayer);
}

bool CForkInTheRoadCard::BeforeResolution(CAbilityAction* pAction)
{
	RequestLand(pAction->GetController(), m_HandSelection, _T("Put %s into your hand"));
	return true;
}

void CForkInTheRoadCard::OnHandSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);

			RequestLand(pSelectionPlayer, m_GraveyardSelection, _T("Put %s into your graveyard"));
			return;
		}

	pSelectionPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

void CForkInTheRoadCard::OnGraveyardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			break;
		}

	pSelectionPlayer->GetZoneById(ZoneId::Library)->Shuffle();
}

CFromUnderTheFloorboardsCard::CFromUnderTheFloorboardsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("From Under the Floorboards"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	{
		// Create three tapped 2/2 black Zombie creature tokens and you gain 3 life.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFromUnderTheFloorboardsCard::BeforeResolution));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Madness {X}{B}{B}: instead create X of those tokens and you gain X life.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT BLACK_MANA_TEXT));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFromUnderTheFloorboardsCard::BeforeMadnessResolution));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());

		m_Madness.SetMadnessSpell(cpSpell.GetPointer());
	}
}

bool CFromUnderTheFloorboardsCard::BeforeResolution(CAbilityAction* pAction) const
{
	CreateTappedZombies(GetGame(), pAction->GetController(), 3);

	CLifeModifier pModifier = CLifeModifier(Life(+3), (CCard*)this, PreventableType::NotPreventable);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CFromUnderTheFloorboardsCard::BeforeMadnessResolution(CAbilityAction* pAction) const
{
	int nX = GetLastCastingExtraValue();
	if (nX <= 0)
		return true;

	CreateTappedZombies(GetGame(), pAction->GetController(), nX);

	CLifeModifier pModifier = CLifeModifier(Life(+nX), (CCard*)this, PreventableType::NotPreventable);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CGisasBiddingCard::CGisasBiddingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gisa's Bidding"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// Create two 2/2 black Zombie creature tokens. Madness {2}{B}
	LPCTSTR costs[] = { _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, _T("2") BLACK_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTokenProductionSpell> cpSpell(
			::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
				costs[i],
				_T("Zombie (P)"), 55009, 2));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CGoneMissingCard::CGoneMissingCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Gone Missing"), CardType::Sorcery, nID,
		_T("4") BLUE_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::_Permanent, false),
		ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others)
{
	// Put target permanent on top of its owner's library. Investigate.
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetMoveCardSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1));
}

CLilianasIndignationCard::CLilianasIndignationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Liliana's Indignation"), CardType::Sorcery, nID)
{
	// Mill X cards. Target player loses 2 life for each creature card put into your graveyard this way.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT, FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianasIndignationCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	AddSpell(cpSpell.GetPointer());
}

bool CLilianasIndignationCard::BeforeResolution(CAbilityAction* pAction) const
{
	int nX = GetLastCastingExtraValue();
	CZone* pLibrary = pAction->GetController()->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	int nCreatures = 0;
	for (int i = 0; i < nX && pLibrary->GetSize() > 0; ++i)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Graveyard && pCard->GetCardType().IsCreature())
			++nCreatures;
	}

	CPlayer* pTarget = pAction->GetAssociatedPlayer();
	if (pTarget && nCreatures > 0)
	{
		CLifeModifier pLifeModifier = CLifeModifier(Life(-2 * nCreatures), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pLifeModifier.ApplyTo(pTarget);
	}

	return true;
}

CMalevolentWhispersCard::CMalevolentWhispersCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Malevolent Whispers"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// Gain control of target creature until end of turn. Untap that creature. It gets +2/+0 and gains haste until end of turn.
	// Madness {3}{R} (as Threaten)
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
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
		cpSpell->GetTargetModifier().CCreatureModifiers::push_back(new CPowerModifier(Power(+2)));

		cpSpell->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep1);

		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CMurderousCompulsionCard::CMurderousCompulsionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Murderous Compulsion"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// Destroy target tapped creature. Madness {1}{B}
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CNaggingThoughtsCard::CNaggingThoughtsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nagging Thoughts"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNaggingThoughtsCard::OnCardSelected))
	, m_Madness(this)
{
	// Look at the top two cards of your library. Put one of them into your hand and the other into your graveyard.
	// Madness {1}{U}
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("1") BLUE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNaggingThoughtsCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

bool CNaggingThoughtsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < 2 && i < pLibrary->GetSize(); ++i)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1 - i);

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s into your hand"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);

	return true;
}

void CNaggingThoughtsCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	// The selected card goes to the hand, the other one to the graveyard
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Library)
			continue;

		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, it->bSelected ? ZoneId::Hand : ZoneId::Graveyard,
			TRUE, MoveType::Others, pSelectionPlayer);
		pModifier.ApplyTo(pCard);
	}
}

CNotForgottenCard::CNotForgottenCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Not Forgotten"), CardType::Sorcery, nID)
	, m_PlaceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNotForgottenCard::OnPlaceSelected))
{
	// Put target card from a graveyard on your choice of the top or bottom of its owner's library.
	// Create a 1/1 white Spirit creature token with flying.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT, new TrueCardComparer, FALSE));

	cpSpell->GetTargeting()->SetSubjectZoneId(ZoneId::Graveyard);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNotForgottenCard::BeforeResolution));
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Spirit (O)"), 55008, 1));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	AddSpell(cpSpell.GetPointer());
}

bool CNotForgottenCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Graveyard)
		return true;

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)pTarget;
		entry.cpAssociatedCard = pTarget;
		entry.strText.Format(_T("Put %s on top of its owner's library"), pTarget->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)pTarget;
		entry.cpAssociatedCard = pTarget;
		entry.strText.Format(_T("Put %s on the bottom of its owner's library"), pTarget->GetCardName(TRUE));
		entries.push_back(entry);
	}

	m_PlaceSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());
	return true;
}

void CNotForgottenCard::OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (size_t i = 0; i < selection.size(); ++i)
		if (selection[i].bSelected)
		{
			CCard* pCard = (CCard*)selection[i].dwContext;
			if (pCard->GetZoneId() != ZoneId::Graveyard)
				return;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.SetToTop(i == 0);
			pModifier.ApplyTo(pCard);
			return;
		}
}

COpenTheArmoryCard::COpenTheArmoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Open the Armory"), CardType::Sorcery, nID)
	, m_Filter(_T("an Aura or Equipment card"), _T("Aura or Equipment cards"), new CardTypeComparer(CardType::_Aura | CardType::Equipment, false))
{
	// Search your library for an Aura or Equipment card, reveal it, put it into your hand, then shuffle.
	counted_ptr<CSearchLibrarySpell> cpSpell(
		::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT,
			&m_Filter,
			ZoneId::Hand, TRUE, FALSE, FALSE));

	cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(1));
	AddSpell(cpSpell.GetPointer());
}

CPickTheBrainCard::CPickTheBrainCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pick the Brain"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPickTheBrainCard::OnCardSelected))
	, m_bDelirium(FALSE)
{
	// Target opponent reveals their hand. You choose a nonland card from it and exile that card.
	// Delirium - If there are four or more card types among cards in your graveyard, search that player's graveyard,
	// hand, and library for any number of cards with the same name as the exiled card, exile those cards, then that
	// player shuffles. (Note: all the cards with that name are exiled)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT, FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPickTheBrainCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Hand, ZoneId::Exile));
	AddSpell(cpSpell.GetPointer());
}

bool CPickTheBrainCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	m_bDelirium = HasDelirium(pAction->GetController());

	CZone* pHand = pOpponent->GetZoneById(ZoneId::Hand);

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
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController());

	return true;
}

void CPickTheBrainCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			CPlayer* pOpponent = pCard->GetOwner();
			CString strName = pCard->GetCardName(FALSE);

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			if (m_bDelirium)
			{
				ZoneId zones[] = { ZoneId::Graveyard, ZoneId::Hand, ZoneId::Library };
				for (int z = 0; z < 3; ++z)
				{
					CZone* pZone = pOpponent->GetZoneById(zones[z]);
					CCountedCardContainer sameName;
					for (int i = 0; i < pZone->GetSize(); ++i)
						if (pZone->GetAt(i)->GetCardName(FALSE) == strName)
							sameName.AddCard(pZone->GetAt(i), CardPlacement::Top);

					CMoveCardModifier pZoneModifier = CMoveCardModifier(zones[z], ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
					for (int i = 0; i < sameName.GetSize(); ++i)
						pZoneModifier.ApplyTo(sameName.GetAt(i));
				}

				pOpponent->GetZoneById(ZoneId::Library)->Shuffle();
			}
			return;
		}
}

CPiecesOfThePuzzleCard::CPiecesOfThePuzzleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pieces of the Puzzle"), CardType::Sorcery, nID)
	, m_Filter(_T("an instant or sorcery card"), _T("instant or sorcery cards"), new CardTypeComparer(CardType::Instant | CardType::Sorcery, false))
{
	// Reveal the top five cards of your library. Put up to two instant and/or sorcery cards from among them into your
	// hand and the rest into your graveyard. (as Grisly Salvage)
	counted_ptr<CRevealLibraryCardSpell> cpSpell(
		::CreateObject<CRevealLibraryCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLUE_MANA_TEXT,
			5));

	cpSpell->SetRevealCardsToOthers(TRUE, FALSE);
	cpSpell->SetSelectionOptions(MinimumValue(0), MaximumValue(2), ZoneId::Hand, CardPlacement::NotApplicable, &m_Filter);
	cpSpell->SetReorder(TRUE, ZoneId::Graveyard);
	AddSpell(cpSpell.GetPointer());
}

CPoreOverThePagesCard::CPoreOverThePagesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Pore Over the Pages"), CardType::Sorcery, nID)
	, m_LandSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPoreOverThePagesCard::OnLandsSelected))
{
	// Draw three cards, untap up to two lands, then discard a card.
	// Note: the lands to untap are chosen before drawing.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, 3));

	cpSpell->SetDiscard(1, FALSE, MoveType::Discard);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPoreOverThePagesCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPoreOverThePagesCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand() || !pCard->GetOrientation()->IsTapped())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Untap %s"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
		m_LandSelection.AddSelectionRequest(entries, 0, 2, this, pController);

	return true;
}

void CPoreOverThePagesCard::OnLandsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			pModifier.ApplyTo((CCard*)it->dwContext);
}

CPressForAnswersCard::CPressForAnswersCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Press for Answers"), CardType::Sorcery, nID)
{
	// Tap target creature. It doesn't untap during its controller's next untap step. Investigate. (as Rush of Ice)
	counted_ptr<CTargetTapUntapCardSpell> cpSpell(
		::CreateObject<CTargetTapUntapCardSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT,
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1));

	AddSpell(cpSpell.GetPointer());
}

CRabidBiteCard::CRabidBiteCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rabid Bite"), CardType::Sorcery, nID)
{
	// Target creature you control deals damage equal to its power to target creature you don't control. (as Prey Upon)
	counted_ptr<CRabidBiteSpell> cpSpell(
		::CreateObject<CRabidBiteSpell>(this, AbilityType::Sorcery,
			_T("1") GREEN_MANA_TEXT));

	AddSpell(cpSpell.GetPointer());
}

CRabidBiteCard::CRabidBiteSpell::CRabidBiteSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost)
	: CDoubleTargetSpell(pCard, abilityType, strManaCost,
		new AnyCreatureComparer, false,
		new AnyCreatureComparer, false,
		_T(""))
{
	GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	GetTargeting1()->SetIncludeControllerCardsOnly();
	GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	GetTargeting2()->SetIncludeNonControllerCardsOnly();
}

void CRabidBiteCard::CRabidBiteSpell::ResolveGroup(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2,
												   const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2)
{
	if (!pContainer1.GetSize() || !pContainer2.GetSize()) return;

	CCreatureCard* pSource = dynamic_cast<CCreatureCard*>(pContainer1.GetAt(0));
	CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(pContainer2.GetAt(0));
	if (!pSource || !pTarget) return;

	int nPower = GET_INTEGER(pSource->GetPower());
	if (nPower <= 0) return;

	CLifeModifier pModifier = CLifeModifier(Life(-nPower), pSource, PreventableType::Preventable, DamageType::NonCombatDamage);
	pModifier.ApplyTo(pTarget);
}

CReduceToAshesCard::CReduceToAshesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reduce to Ashes"), CardType::Sorcery, nID)
{
	// Reduce to Ashes deals 5 damage to target creature. If that creature would die this turn, exile it instead.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("4") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-5), PreventableType::Preventable));

	cpSpell->GetTargetModifier().CCardModifiers::push_back(CreateExileInsteadModifier());
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CRiseFromTheTidesCard::CRiseFromTheTidesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rise from the Tides"), CardType::Sorcery, nID)
{
	// Create a tapped 2/2 black Zombie creature token for each instant and sorcery card in your graveyard.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery, _T("5") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRiseFromTheTidesCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	AddSpell(cpSpell.GetPointer());
}

bool CRiseFromTheTidesCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardFilter filter(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	int nCount = filter.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Graveyard)->GetCardContainer());

	CreateTappedZombies(GetGame(), pAction->GetController(), nCount);
	return true;
}

CRootOutCard::CRootOutCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Root Out"), CardType::Sorcery, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	// Destroy target artifact or enchantment. Investigate.
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetMoveCardSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1));
}

CShambleBackCard::CShambleBackCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shamble Back"), CardType::Sorcery, nID)
{
	// Exile target creature card from a graveyard. Create a 2/2 black Zombie creature token. You gain 2 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectZoneId(ZoneId::Graveyard);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, 1));
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+2), this, PreventableType::NotPreventable));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

CStructuralDistortionCard::CStructuralDistortionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Structural Distortion"), CardType::Sorcery, nID)
{
	// Exile target artifact or land. Structural Distortion deals 2 damage to that permanent's controller.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT, new CardTypeComparer(CardType::Artifact | CardType::_Land, false), FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStructuralDistortionCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CStructuralDistortionCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CPlayer* pController = pTarget->GetController();

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others);
	pModifier.ApplyTo(pTarget);

	CLifeModifier pDamageModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pDamageModifier.ApplyTo(pController);

	return true;
}

CTraverseTheUlvenwaldCard::CTraverseTheUlvenwaldCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Traverse the Ulvenwald"), CardType::Sorcery, nID)
	, m_CreatureOrLandFilter(_T("a creature or land card"), _T("creature or land cards"), new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	// Search your library for a basic land card, reveal it, put it into your hand, then shuffle.
	// Delirium - instead search your library for a creature or land card. (as Ruin in Their Wake: one spell for each case)
	const CCardFilter* filters[] = { CCardFilter::GetFilter(_T("basic lands")), &m_CreatureOrLandFilter };
	CPlayableIfTrait::PlayableCallback callbacks[] = {
		CPlayableIfTrait::PlayableCallback(this, &CTraverseTheUlvenwaldCard::CanCastNormal),
		CPlayableIfTrait::PlayableCallback(this, &CTraverseTheUlvenwaldCard::CanCastDelirium) };

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CSearchLibrarySpell> cpSpell(
			::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
				GREEN_MANA_TEXT,
				filters[i],
				ZoneId::Hand, TRUE, FALSE, FALSE));
		cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(1));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(), callbacks[i]));
		cpSpell->Add(cpTrait.GetPointer());

		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CTraverseTheUlvenwaldCard::CanCastNormal(BOOL bIncludeTricks)
{
	return !HasDelirium(GetController());
}

BOOL CTraverseTheUlvenwaldCard::CanCastDelirium(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

CWelcomeToTheFoldCard::CWelcomeToTheFoldCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Welcome to the Fold"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	{
		// Gain control of target creature if its toughness is 2 or less. (as Threaten, without returning it)
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureToughnessComparer<std::less<int>>(3));
		cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Madness {X}{U}{U}: instead gain control of that creature if its toughness is X or less.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				BLUE_MANA_TEXT BLUE_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors);
		cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWelcomeToTheFoldCard::BeforeMadnessResolution));
		AddSpell(cpSpell.GetPointer());

		m_Madness.SetMadnessSpell(cpSpell.GetPointer());
	}
}

bool CWelcomeToTheFoldCard::BeforeMadnessResolution(CAbilityAction* pAction) const
{
	// The toughness is checked on resolution (X is known when the spell is cast)
	const CCreatureCard* pTarget = dynamic_cast<const CCreatureCard*>(pAction->GetAssociatedCard());
	return pTarget && GET_INTEGER(pTarget->GetToughness()) <= GetLastCastingExtraValue();
}

//____________________________________________________________________________
//
// Instants

static CPlayerModifier* CreateClueModifier(CGame* pGame, int nCount = 1)
{
	return new CTokenCreationModifier(pGame, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, nCount);
}

CAimHighCard::CAimHighCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Aim High"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") GREEN_MANA_TEXT,
		Power(+2), Life(+2),
		CreatureKeyword::Reach, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Untap target creature. It gets +2/+2 and gains reach until end of turn.
	m_pTargetChgPwrTghAttrSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
}

CAnguishedUnmakingCard::CAnguishedUnmakingCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Anguished Unmaking"), CardType::Instant, nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Instant,
		new CardTypeComparer(CardType::_Permanent, false),
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
{
	// Exile target nonland permanent. You lose 3 life.
	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new CardTypeComparer(CardType::_Land, false));
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetMoveCardSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
}

CBrokenConcentrationCard::CBrokenConcentrationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Broken Concentration"), CardType::Instant, nID)
	, m_Madness(this)
{
	// Counter target spell. Madness {3}{U}
	LPCTSTR costs[] = { _T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, _T("3") BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				costs[i], new TrueCardComparer));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CClipWingsCard::CClipWingsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Clip Wings"), CardType::Instant, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CClipWingsCard::OnCardSelected))
{
	// Each opponent sacrifices a creature of their choice with flying.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("1") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CClipWingsCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	AddSpell(cpSpell.GetPointer());
}

bool CClipWingsCard::BeforeResolution(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);

		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (!pCard->GetCardType().IsCreature() || !((CCreatureCard*)pCard)->GetCreatureKeyword()->Flying())
				continue;

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));

			entries.push_back(entry);
		}

		if (!entries.empty())
			m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);
	}

	return true;
}

void CClipWingsCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			return;
		}
}

CCompellingDeterrenceCard::CCompellingDeterrenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Compelling Deterrence"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CCompellingDeterrenceCard::OnResolutionCompleted))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CCompellingDeterrenceCard::OnCardSelected))
{
	// Return target nonland permanent to its owner's hand. Then that player discards a card if you control a Zombie.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::_Permanent, false),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new CardTypeComparer(CardType::_Land, false));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

void CCompellingDeterrenceCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CCard* pCard = pAbilityAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Hand)
		return;

	CCardFilter zombieFilter(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	if (zombieFilter.CountIncluded(pAbilityAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return;

	// That player discards a card of their choice
	CPlayer* pPlayer = pCard->GetOwner();
	CZone* pHand = pPlayer->GetZoneById(ZoneId::Hand);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		SelectionEntry entry;

		entry.dwContext = (DWORD)pHand->GetAt(i);
		entry.cpAssociatedCard = pHand->GetAt(i);
		entry.strText.Format(_T("Discard %s"), pHand->GetAt(i)->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pPlayer);
}

void CCompellingDeterrenceCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			return;
		}
}

CConfirmSuspicionsCard::CConfirmSuspicionsCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Confirm Suspicions"), CardType::Instant, nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	// Counter target spell. Investigate three times.
	m_pCounterSpell->GetResolutionModifier().CPlayerModifiers::push_back(CreateClueModifier(GetGame(), 3));
	m_pCounterSpell->AddAbilityTag(AbilityTag::TokenCreation);
}

CConfrontTheUnknownCard::CConfrontTheUnknownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Confront the Unknown"), CardType::Instant, nID)
{
	// Investigate, then target creature gets +1/+1 until end of turn for each Clue you control.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT, new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConfrontTheUnknownCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::CreatureChange);
	AddSpell(cpSpell.GetPointer());
}

bool CConfrontTheUnknownCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	Investigate(GetGame(), pController);

	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || !pTarget->GetCardType().IsCreature() || pTarget->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardFilter clueFilter(new CardNameComparer(_T("Clue")));
	int nClues = clueFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());

	CPowerModifier pPowerModifier = CPowerModifier(Power(+nClues));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+nClues), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pPowerModifier.ApplyTo((CCreatureCard*)pTarget);
	pLifeModifier.ApplyTo((CCreatureCard*)pTarget);

	return true;
}

CDanceWithDevilsCard::CDanceWithDevilsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dance with Devils"), CardType::Instant, nID)
{
	// Create two 1/1 red Devil creature tokens. They have "When this token dies, it deals 1 damage to any target."
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT,
			_T("Devil (A)"), 55079, 2));
	AddSpell(cpSpell.GetPointer());
}

CDenyExistenceCard::CDenyExistenceCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Deny Existence"), CardType::Instant, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Instant,
		new CardTypeComparer(CardType::Creature, false))
{
	// Counter target creature spell. If that spell is countered this way, exile it instead. (as Dissipate)
	m_pCounterSpell->SetToZone(ZoneId::Exile, TRUE);
}

CDissensionInTheRanksCard::CDissensionInTheRanksCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dissension in the Ranks"), CardType::Instant, nID)
{
	// Target blocking creature fights another target blocking creature. (as Prey Upon)
	counted_ptr<CDissensionInTheRanksSpell> cpSpell(
		::CreateObject<CDissensionInTheRanksSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT RED_MANA_TEXT));

	AddSpell(cpSpell.GetPointer());
}

CDissensionInTheRanksCard::CDissensionInTheRanksSpell::CDissensionInTheRanksSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost)
	: CDoubleTargetSpell(pCard, abilityType, strManaCost,
		new BlockingCreatureComparer, false,
		new BlockingCreatureComparer, false,
		_T(""))
{
	GetTargeting1()->SetDefaultCharacteristic(Characteristic::Neutral);
	GetTargeting2()->SetDefaultCharacteristic(Characteristic::Neutral);
}

void CDissensionInTheRanksCard::CDissensionInTheRanksSpell::ResolveGroup(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2,
																		 const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2)
{
	if (!pContainer1.GetSize() || !pContainer2.GetSize()) return;

	CCreatureCard* pCreature1 = dynamic_cast<CCreatureCard*>(pContainer1.GetAt(0));
	CCreatureCard* pCreature2 = dynamic_cast<CCreatureCard*>(pContainer2.GetAt(0));
	if (!pCreature1 || !pCreature2 || pCreature1 == pCreature2) return;

	CFightsModifier modifier = CFightsModifier(pCreature2);
	modifier.ApplyTo(pCreature1);
}

CDualShotCard::CDualShotCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dual Shot"), CardType::Instant, nID)
{
	// Dual Shot deals 1 damage to each of up to two target creatures. (as Sparkmage's Gambit; one or two must be chosen)
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-1), PreventableType::Preventable));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CEngulfTheShoreCard::CEngulfTheShoreCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Engulf the Shore"), CardType::Instant, nID)
{
	// Return to their owners' hands all creatures with toughness less than or equal to the number of Islands you control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("3") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEngulfTheShoreCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Hand));
	AddSpell(cpSpell.GetPointer());
}

bool CEngulfTheShoreCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardFilter islandFilter(new CardTypeComparer(CardType::Island, false));
	int nIslands = islandFilter.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());

	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() && GET_INTEGER(((CCreatureCard*)pCard)->GetToughness()) <= nIslands)
				pCreatures.AddCard(pCard, CardPlacement::Top);
		}
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pModifier.ApplyTo(pCreatures.GetAt(i));

	return true;
}

CEssenceFluxCard::CEssenceFluxCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Essence Flux"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CEssenceFluxCard::OnResolutionCompleted))
{
	// Exile target creature you control, then return that card to the battlefield under its owner's control.
	// If it's a Spirit, put a +1/+1 counter on it. (as Eldrazi Displacer in Oath of the Gatewatch)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

void CEssenceFluxCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CCard* pCard = pAbilityAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Exile)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others);
	pModifier.ApplyTo(pCard);

	if (pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetCardType().IsCreature() &&
		((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Spirit))
	{
		CCardCounterModifier pCounterModifier = CCardCounterModifier(_T("+1/+1"), +1);
		pCounterModifier.ApplyTo(pCard);
	}
}

CExposeEvilCard::CExposeEvilCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Expose Evil"), CardType::Instant, nID)
{
	// Tap up to two target creatures. Investigate. (one or two creatures must be chosen)
	counted_ptr<CTargetTapUntapCardSpell> cpSpell(
		::CreateObject<CTargetTapUntapCardSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(CreateClueModifier(GetGame()));
	AddSpell(cpSpell.GetPointer());
}

CGrotesqueMutationCard::CGrotesqueMutationCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Grotesque Mutation"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") BLACK_MANA_TEXT,
		Power(+3), Life(+1),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Target creature gets +3/+1 and gains lifelink until end of turn.
	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::Lifelink);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	m_pTargetChgPwrTghAttrSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);
}

CHumbleTheBruteCard::CHumbleTheBruteCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Humble the Brute"), CardType::Instant, nID,
		_T("4") WHITE_MANA_TEXT, AbilityType::Instant,
		new AnyCreatureComparer,
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	// Destroy target creature with power 4 or greater. Investigate.
	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreaturePowerComparer<std::greater<int>>(3));
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetMoveCardSpell->GetResolutionModifier().CPlayerModifiers::push_back(CreateClueModifier(GetGame()));
}

CInnerStruggleCard::CInnerStruggleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Inner Struggle"), CardType::Instant, nID)
{
	// Target creature deals damage to itself equal to its power.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT, new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInnerStruggleCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CInnerStruggleCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	int nPower = GET_INTEGER(pTarget->GetPower());
	if (nPower > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nPower), pTarget, PreventableType::Preventable, DamageType::NonCombatDamage);
		pModifier.ApplyTo(pTarget);
	}
	return true;
}

CInvasiveSurgeryCard::CInvasiveSurgeryCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Invasive Surgery"), CardType::Instant, nID,
		BLUE_MANA_TEXT, AbilityType::Instant,
		new CardTypeComparer(CardType::Sorcery, false))
{
	// Counter target sorcery spell.
	// Note: the delirium part (exile the cards with the same name) is not implemented.
}

CJacesScrutinyCard::CJacesScrutinyCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Jace's Scrutiny"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") BLUE_MANA_TEXT,
		Power(-4), Life(+0),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Target creature gets -4/-0 until end of turn. Investigate.
	m_pTargetChgPwrTghAttrSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetChgPwrTghAttrSpell->GetResolutionModifier().CPlayerModifiers::push_back(CreateClueModifier(GetGame()));
}

CJustTheWindCard::CJustTheWindCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Just the Wind"), CardType::Instant, nID)
	, m_Madness(this)
{
	// Return target creature to its owner's hand. Madness {U}
	LPCTSTR costs[] = { _T("1") BLUE_MANA_TEXT, BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				costs[i],
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CMercilessResolveCard::CMercilessResolveCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Merciless Resolve"), CardType::Instant, nID)
	, m_SacrificeFilter(_T("a creature or land"), _T("creatures or lands"), new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	// As an additional cost to cast this spell, sacrifice a creature or land. Draw two cards.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT, 2));

	cpSpell->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	AddSpell(cpSpell.GetPointer());
}

CMightBeyondReasonCard::CMightBeyondReasonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Might Beyond Reason"), CardType::Instant, nID)
{
	// Put two +1/+1 counters on target creature. Delirium - Put three +1/+1 counters on that creature instead.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") GREEN_MANA_TEXT, new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMightBeyondReasonCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::CreatureChange);
	AddSpell(cpSpell.GetPointer());
}

bool CMightBeyondReasonCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), HasDelirium(pAction->GetController()) ? 3 : 2);
	pModifier.ApplyTo(pTarget);
	return true;
}

CMoonlightHuntCard::CMoonlightHuntCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Moonlight Hunt"), CardType::Instant, nID)
{
	// Choose target creature you don't control. Each creature you control that's a Wolf or a Werewolf deals damage
	// equal to its power to that creature.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT, new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMoonlightHuntCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CMoonlightHuntCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCreatureCard* pTarget = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return false;

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer sources;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		const CreatureType& type = ((CCreatureCard*)pCard)->GetCreatureType();
		if (type.HasType(SingleCreatureType::Wolf) || type.HasType(SingleCreatureType::Werewolf))
			sources.AddCard(pCard, CardPlacement::Top);
	}

	for (int i = 0; i < sources.GetSize(); ++i)
	{
		CCreatureCard* pSource = (CCreatureCard*)sources.GetAt(i);
		int nPower = GET_INTEGER(pSource->GetPower());
		if (nPower <= 0 || pTarget->GetZoneId() != ZoneId::Battlefield)
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-nPower), pSource, PreventableType::Preventable, DamageType::NonCombatDamage);
		pModifier.ApplyTo(pTarget);
	}

	return true;
}

CRushOfAdrenalineCard::CRushOfAdrenalineCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Rush of Adrenaline"), CardType::Instant, nID, AbilityType::Instant,
		RED_MANA_TEXT,
		Power(+2), Life(+1),
		CreatureKeyword::Trample, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
}

CSilverstrikeCard::CSilverstrikeCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Silverstrike"), CardType::Instant, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Instant,
		new AttackingCreatureComparer,
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	// Destroy target attacking creature. You gain 3 life.
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetMoveCardSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+3), this, PreventableType::NotPreventable));
}

CStrengthOfArmsCard::CStrengthOfArmsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Strength of Arms"), CardType::Instant, nID, AbilityType::Instant,
		WHITE_MANA_TEXT,
		Power(+2), Life(+2),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Target creature gets +2/+2 until end of turn. If you control an Equipment, create a 1/1 white Human Soldier creature token.
	m_pTargetChgPwrTghAttrSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStrengthOfArmsCard::BeforeResolution));
}

bool CStrengthOfArmsCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardFilter equipmentFilter(new CardTypeComparer(CardType::Equipment, false));
	if (equipmentFilter.CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
	{
		CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Human Soldier (A)"), 55075, 1);
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CSurviveTheNightCard::CSurviveTheNightCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Survive the Night"), CardType::Instant, nID, AbilityType::Instant,
		_T("2") WHITE_MANA_TEXT,
		Power(+1), Life(+0),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Target creature gets +1/+0 and gains indestructible until end of turn. Investigate.
	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	m_pTargetChgPwrTghAttrSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);
	m_pTargetChgPwrTghAttrSpell->GetResolutionModifier().CPlayerModifiers::push_back(CreateClueModifier(GetGame()));
}

CTenacityCard::CTenacityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tenacity"), CardType::Instant, nID)
{
	// Creatures you control get +1/+1 and gain lifelink until end of turn. Untap those creatures.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant, _T("3") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTenacityCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::CreatureChange);
	AddSpell(cpSpell.GetPointer());
}

bool CTenacityCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CCardKeywordModifier pLifelinkModifier;
	pLifelinkModifier.GetModifier().SetToAdd(CardKeyword::Lifelink);
	pLifelinkModifier.GetModifier().SetOneTurnOnly(TRUE);
	CCardOrientationModifier pUntapModifier = CCardOrientationModifier(FALSE);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
		pLifelinkModifier.ApplyTo(pCard);
		pUntapModifier.ApplyTo(pCard);
	}

	return true;
}

CToTheSlaughterCard::CToTheSlaughterCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("To the Slaughter"), CardType::Instant, nID)
	, m_CreatureOrPlaneswalkerFilter(_T("a creature or planeswalker"), _T("creatures or planeswalkers"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
	, m_PlaneswalkerSelection(pGame, CSelectionSupport::SelectionCallback(this, &CToTheSlaughterCard::OnPlaneswalkerSelected))
{
	// Target player sacrifices a creature or planeswalker of their choice.
	// Delirium - instead that player sacrifices a creature and a planeswalker of their choice.
	// (as Diabolic Edict; one spell for each case)
	{
		counted_ptr<CTargetPlayerSacrificeSpell> cpSpell(
			::CreateObject<CTargetPlayerSacrificeSpell>(this, AbilityType::Instant,
				_T("2") BLACK_MANA_TEXT,
				&m_CreatureOrPlaneswalkerFilter));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CToTheSlaughterCard::CanCastNormal)));
		cpSpell->Add(cpTrait.GetPointer());
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CTargetPlayerSacrificeSpell> cpSpell(
			::CreateObject<CTargetPlayerSacrificeSpell>(this, AbilityType::Instant,
				_T("2") BLACK_MANA_TEXT,
				CCardFilter::GetFilter(_T("creatures"))));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CToTheSlaughterCard::BeforeDeliriumResolution));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CToTheSlaughterCard::CanCastDelirium)));
		cpSpell->Add(cpTrait.GetPointer());
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CToTheSlaughterCard::CanCastNormal(BOOL bIncludeTricks)
{
	return !HasDelirium(GetController());
}

BOOL CToTheSlaughterCard::CanCastDelirium(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

bool CToTheSlaughterCard::BeforeDeliriumResolution(CAbilityAction* pAction)
{
	// The planeswalker is sacrificed here; the creature by the spell
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return true;

	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsPlaneswalker())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
		m_PlaneswalkerSelection.AddSelectionRequest(entries, 1, 1, this, pPlayer);

	return true;
}

void CToTheSlaughterCard::OnPlaneswalkerSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			return;
		}
}

CUncagedFuryCard::CUncagedFuryCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Uncaged Fury"), CardType::Instant, nID, AbilityType::Instant,
		_T("2") RED_MANA_TEXT,
		Power(+1), Life(+1),
		CreatureKeyword::DoubleStrike, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
}

//____________________________________________________________________________
//
// Enchantments

struct NontokenCreatureComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && !pCard->GetCardType().IsToken();
	}

	virtual NontokenCreatureComparer* Clone() const
	{
		return new NontokenCreatureComparer;
	}
};

struct WolfOrWerewolfComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		if (!pCard->GetCardType().IsCreature())
			return false;

		const CreatureType& type = ((const CCreatureCard*)pCard)->GetCreatureType();
		return type.HasType(SingleCreatureType::Wolf) || type.HasType(SingleCreatureType::Werewolf);
	}

	virtual WolfOrWerewolfComparer* Clone() const
	{
		return new WolfOrWerewolfComparer;
	}
};

// Mills nCount cards of pPlayer's library
static void Mill(CPlayer* pPlayer, int nCount)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < nCount && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
}

// Was this move a Clue being sacrificed? (for "Whenever you sacrifice a Clue")
static bool IsClueSacrificed(const CCard* pCard, MoveType moveType)
{
	return moveType == MoveType::Sacrifice && pCard->GetCardName(FALSE) == _T("Clue");
}

CAlwaysWatchingCard::CAlwaysWatchingCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Always Watching"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// Nontoken creatures you control get +1/+1 and have vigilance.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new NontokenCreatureComparer,
			Power(+1), Life(+1), CreatureKeyword::Vigilance));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CBehindTheScenesCard::CBehindTheScenesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Behind the Scenes"), CardType::GlobalEnchantment, nID,
		_T("2") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Creatures you control have skulk.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AnyCreatureComparer,
				Power(+0), Life(+0), CreatureKeyword::Skulk));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{W}: Creatures you control get +1/+1 until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4") WHITE_MANA_TEXT));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBehindTheScenesCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBehindTheScenesCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
	}

	return true;
}

CBoundByMoonsilverCard::CBoundByMoonsilverCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Bound by Moonsilver"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
{
	// Enchanted creature can't attack, block, or transform.
	// Note: "can't transform" and "Sacrifice another permanent: Attach this Aura to target creature" are not implemented.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CCallTheBloodlineCard::CCallTheBloodlineCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Call the Bloodline"), CardType::GlobalEnchantment, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// {1}, Discard a card: Create a 1/1 black Vampire Knight creature token with lifelink. Activate only once each turn.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("1"),
			_T("Vampire Knight (A)"), 55077,
			1));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetMaxTurnUsageCount(1);
	AddAbility(cpAbility.GetPointer());
}

CCrawlingSensationCard::CCrawlingSensationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Crawling Sensation"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_nLastTurn(-1)
{
	{
		// At the beginning of your upkeep, you may mill two cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrawlingSensationCard::BeforeMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever one or more land cards are put into your graveyard from anywhere for the first time each turn,
		// create a 1/1 green Insect creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Insect (J)"), 55080, 1);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCrawlingSensationCard::SetLandContext));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CCrawlingSensationCard::BeforeMill(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 2);
	return true;
}

bool CCrawlingSensationCard::SetLandContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
											CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	// Only the first time each turn
	if (m_nLastTurn == GetGame()->GetGameTurnNumber())
		return false;

	m_nLastTurn = GetGame()->GetGameTurnNumber();
	return true;
}

CCryptolithRiteCard::CCryptolithRiteCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cryptolith Rite"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// Creatures you control have "{T}: Add one mana of any color." (one mana ability of each color, as Birds of Paradise)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(+0), Life(+0)));

	cpAbility->GetOtherCardModifiers().Add(new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CCryptolithRiteCard::CreateWhite)));
	cpAbility->GetOtherCardModifiers().Add(new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CCryptolithRiteCard::CreateBlue)));
	cpAbility->GetOtherCardModifiers().Add(new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CCryptolithRiteCard::CreateBlack)));
	cpAbility->GetOtherCardModifiers().Add(new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CCryptolithRiteCard::CreateRed)));
	cpAbility->GetOtherCardModifiers().Add(new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CCryptolithRiteCard::CreateGreen)));
	cpAbility->SetAffectControllerCardsOnly();

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CCryptolithRiteCard::CreateManaAbility(CCard* pCard, LPCTSTR strMana)
{
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(pCard, _T(""), AbilityType::Activated, strMana));
	cpAbility->AddTapCost();
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

counted_ptr<CAbility> CCryptolithRiteCard::CreateWhite(CCard* pCard)	{ return CreateManaAbility(pCard, WHITE_MANA_TEXT); }
counted_ptr<CAbility> CCryptolithRiteCard::CreateBlue(CCard* pCard)		{ return CreateManaAbility(pCard, BLUE_MANA_TEXT); }
counted_ptr<CAbility> CCryptolithRiteCard::CreateBlack(CCard* pCard)	{ return CreateManaAbility(pCard, BLACK_MANA_TEXT); }
counted_ptr<CAbility> CCryptolithRiteCard::CreateRed(CCard* pCard)		{ return CreateManaAbility(pCard, RED_MANA_TEXT); }
counted_ptr<CAbility> CCryptolithRiteCard::CreateGreen(CCard* pCard)	{ return CreateManaAbility(pCard, GREEN_MANA_TEXT); }

CEquestrianSkillCard::CEquestrianSkillCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Equestrian Skill"), CardType::EnchantCreature, nID)
{
	// Enchanted creature gets +3/+3. As long as enchanted creature is a Human, it has trample.
	// Note: whether it is a Human is checked when the Aura becomes attached.
	counted_ptr<CEquestrianSkillEnchant> cpSpell(
		::CreateObject<CEquestrianSkillEnchant>(this, _T("3") GREEN_MANA_TEXT));
	AddSpell(cpSpell.GetPointer());
}

CEquestrianSkillCard::CEquestrianSkillEnchant::CEquestrianSkillEnchant(CCard* pCard, LPCTSTR strManaCost)
	: CChgPwrTghAttrEnchant(pCard, strManaCost, Power(+3), Life(+3), CreatureKeyword::Null)
{
}

BOOL CEquestrianSkillCard::CEquestrianSkillEnchant::OnEnchant(CCard* pCard, ContextValue_& contextValue)
{
	BOOL bHuman = pCard->GetCardType().IsCreature() &&
		((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Human);
	GetCreatureKeywordMod().GetModifier().SetToAdd(bHuman ? CreatureKeyword::Trample : CreatureKeyword::Null);

	return __super::OnEnchant(pCard, contextValue);
}

CFeveredVisionsCard::CFeveredVisionsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fevered Visions"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of each player's end step, that player draws a card. If the player is your opponent and has
	// four or more cards in hand, this enchantment deals 2 damage to that player.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFeveredVisionsCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

bool CFeveredVisionsCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pPlayer = GetGame()->GetActivePlayer();
	if (!pPlayer)
		return true;

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
	pDrawModifier.ApplyTo(pPlayer);

	if (pPlayer != pAction->GetController() && pPlayer->GetZoneById(ZoneId::Hand)->GetSize() >= 4)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}

	return true;
}

CFleetingMemoriesCard::CFleetingMemoriesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fleeting Memories"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// When this enchantment enters, investigate.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you sacrifice a Clue, target player mills three cards.
		// Note: each opponent mills three cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFleetingMemoriesCard::SetClueContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFleetingMemoriesCard::BeforeMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CFleetingMemoriesCard::SetClueContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
										   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return IsClueSacrificed(pCard, moveType);
}

bool CFleetingMemoriesCard::BeforeMill(CAbilityAction* pAction) const
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		if (GetGame()->GetPlayer(i) != pAction->GetController())
			Mill(GetGame()->GetPlayer(i), 3);
	return true;
}

CGryffsBoonCard::CGryffsBoonCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Gryff's Boon"), nID,
		WHITE_MANA_TEXT,
		Power(+1), Life(+0), CreatureKeyword::Flying)
{
	// Enchanted creature gets +1/+0 and has flying.
	// Note: "{3}{W}: Return this card from your graveyard to the battlefield attached to target creature" is not implemented.
}

CHowlpackResurgenceCard::CHowlpackResurgenceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Howlpack Resurgence"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	GetCardKeyword()->AddFlash(FALSE);

	// Each creature you control that's a Wolf or a Werewolf gets +1/+1 and has trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new WolfOrWerewolfComparer,
			Power(+1), Life(+1), CreatureKeyword::Trample));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CNahirisMachinationsCard::CNahirisMachinationsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Nahiri's Machinations"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// At the beginning of combat on your turn, target creature you control gains indestructible until end of turn.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Indestructible);
		cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{R}: This enchantment deals 1 damage to target blocking creature.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("1") RED_MANA_TEXT,
				new BlockingCreatureComparer, FALSE,
				Life(-1), PreventableType::Preventable));

		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

COngoingInvestigationCard::COngoingInvestigationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ongoing Investigation"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_nLastTurn(-1)
	, m_CreatureFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
{
	{
		// Whenever one or more creatures you control deal combat damage to a player, investigate.
		// Note: once each turn.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback,
							   &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COngoingInvestigationCard::SetDamageContext));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{G}, Exile a creature card from your graveyard: Investigate. You gain 2 life.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") GREEN_MANA_TEXT));

		cpAbility->GetCost().AddExileGraveyardCardCost(1, &m_CreatureFilter);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1));
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+2), this, PreventableType::NotPreventable));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
}

bool COngoingInvestigationCard::SetDamageContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
												 CCard* pFromCard, CPlayer* pToPlayer, Damage damage)
{
	if (m_nLastTurn == GetGame()->GetGameTurnNumber())
		return false;

	m_nLastTurn = GetGame()->GetGameTurnNumber();
	return true;
}

CSenselessRageCard::CSenselessRageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Senseless Rage"), CardType::EnchantCreature, nID)
	, m_Madness(this)
{
	// Enchanted creature gets +2/+2. Madness {1}{R}
	LPCTSTR costs[] = { _T("1") RED_MANA_TEXT, _T("1") RED_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CChgPwrTghAttrEnchant> cpSpell(
			::CreateObject<CChgPwrTghAttrEnchant>(this, costs[i],
				Power(+2), Life(+2), CreatureKeyword::Null));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CSinisterConcoctionCard::CSinisterConcoctionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sinister Concoction"), CardType::GlobalEnchantment, nID,
		BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// {B}, Pay 1 life, Mill a card, Discard a card, Sacrifice this enchantment: Destroy target creature.
	// Note: the card is milled when the ability resolves.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->GetCost().SetPlayerLifeCost(this, Life(-1));
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSinisterConcoctionCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CSinisterConcoctionCard::BeforeResolution(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 1);
	return true;
}

CSleepParalysisCard::CSleepParalysisCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Sleep Paralysis"), nID,
		_T("3") BLUE_MANA_TEXT,
		Power(+0), Life(+0))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CSleepParalysisCard::OnResolutionCompleted))
{
	// When this Aura enters, tap enchanted creature. Enchanted creature doesn't untap during its controller's untap step.
	// (as Claustrophobia)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
}

void CSleepParalysisCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	CCard* pTarget = pAbilityAction->GetAssociatedCard();
	CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
	if (bResult && pTarget) pModifier.ApplyTo(pTarget);
}

CSpitefulMotivesCard::CSpitefulMotivesCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Spiteful Motives"), nID,
		_T("3") RED_MANA_TEXT,
		Power(+3), Life(+0), CreatureKeyword::FirstStrike)
{
	// Flash. Enchanted creature gets +3/+0 and has first strike.
	GetCardKeyword()->AddFlash(FALSE);
}

CStensiaMasqueradeCard::CStensiaMasqueradeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Stensia Masquerade"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_Madness(this)
{
	{
		// Madness {2}{R}
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, AbilityType::Enchantment, _T("2") RED_MANA_TEXT, TRUE));
		AddSpell(cpSpell.GetPointer());
		m_Madness.SetMadnessSpell(cpSpell.GetPointer());
	}
	{
		// Attacking creatures you control have first strike.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AttackingCreatureComparer,
				Power(+0), Life(+0), CreatureKeyword::FirstStrike));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever a Vampire you control deals combat damage to a player, put a +1/+1 counter on it.
		typedef
			TTriggeredAbility< CTriggeredModifyCardAbility, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback,
							   &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CStensiaMasqueradeCard::SetDamageContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CStensiaMasqueradeCard::SetDamageContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											  CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const
{
	triggerContext.m_pCard = pFromCard;
	return true;
}

CTrailOfEvidenceCard::CTrailOfEvidenceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Trail of Evidence"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast an instant or sorcery spell, investigate.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CUlvenwaldMysteriesCard::CUlvenwaldMysteriesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ulvenwald Mysteries"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever a nontoken creature you control dies, investigate. (as Sifter of Skulls in Oath of the Gatewatch)
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new NontokenCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you sacrifice a Clue, create a 1/1 white Human Soldier creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Human Soldier (A)"), 55075, 1);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUlvenwaldMysteriesCard::SetClueContext));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CUlvenwaldMysteriesCard::SetClueContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
											 CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return IsClueSacrificed(pCard, moveType);
}

CVesselOfEphemeraCard::CVesselOfEphemeraCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vessel of Ephemera"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// {2}{W}, Sacrifice this enchantment: Create two 1/1 white Spirit creature tokens with flying.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("2") WHITE_MANA_TEXT,
			_T("Spirit (O)"), 55008,
			2));

	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CVesselOfMalignityCard::CVesselOfMalignityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vessel of Malignity"), CardType::GlobalEnchantment, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// {1}{B}, Sacrifice this enchantment: Target opponent exiles two cards from their hand. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetPlayerDiscardCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetPlayerDiscardCardSpell>>(this,
			_T("1") BLACK_MANA_TEXT,
			2, MoveType::Others, ZoneId::Exile, TRUE,
			TRUE,	// the targeted player chooses
			CCardFilter::GetFilter(_T("cards"))));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

CVesselOfNascencyCard::CVesselOfNascencyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vessel of Nascency"), CardType::GlobalEnchantment, nID,
		GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_Filter(_T("a permanent card"), _T("permanent cards"), new CardTypeComparer(CardType::_Permanent, false))
{
	// {1}{G}, Sacrifice this enchantment: Reveal the top four cards of your library. You may put an artifact, creature,
	// enchantment, land, or planeswalker card from among them into your hand. Put the rest into your graveyard.
	// (as Grisly Salvage)
	counted_ptr<CActivatedAbility<CRevealLibraryCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CRevealLibraryCardSpell>>(this,
			_T("1") GREEN_MANA_TEXT,
			4));

	cpAbility->AddSacrificeCost();
	cpAbility->SetRevealCardsToOthers(TRUE, FALSE);
	cpAbility->SetSelectionOptions(MinimumValue(0), MaximumValue(1), ZoneId::Hand, CardPlacement::NotApplicable, &m_Filter);
	cpAbility->SetReorder(TRUE, ZoneId::Graveyard);
	AddAbility(cpAbility.GetPointer());
}

CVesselOfParamnesiaCard::CVesselOfParamnesiaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vessel of Paramnesia"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// {U}, Sacrifice this enchantment: Target player mills three cards. Draw a card.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddSacrificeCost();
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVesselOfParamnesiaCard::BeforeResolution));
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));
	AddAbility(cpAbility.GetPointer());
}

bool CVesselOfParamnesiaCard::BeforeResolution(CAbilityAction* pAction) const
{
	if (pAction->GetAssociatedPlayer())
		Mill(pAction->GetAssociatedPlayer(), 3);
	return true;
}

CVesselOfVolatilityCard::CVesselOfVolatilityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vessel of Volatility"), CardType::GlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// {1}{R}, Sacrifice this enchantment: Add {R}{R}{R}{R}.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T("1") RED_MANA_TEXT, AbilityType::Activated,
			RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT RED_MANA_TEXT));

	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// White creatures

// Adds a "Delirium - this creature gets +X/+0 and has ... as long as ..." ability (see SetDeliriumCondition)
static void AddDeliriumBonus(CCreatureCard* pCard, Power nPower, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			nPower, Life(+0), keyword));

	SetDeliriumCondition(cpAbility.GetPointer());
	pCard->AddAbility(cpAbility.GetPointer());
}

CAngelOfDeliveranceCard::CAngelOfDeliveranceCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Deliverance"), CardType::Creature,
		CREATURE_TYPE(Angel), nID, _T("6") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(6), Life(6))
{
	// Delirium - Whenever this creature deals damage, if there are four or more card types among cards in your
	// graveyard, exile target creature an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfDamageDealt,
								 CWhenSelfDamageDealt::DamageEventCallback,
								 &CWhenSelfDamageDealt::SetDamageEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAngelOfDeliveranceCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

	AddAbility(cpAbility.GetPointer());
}

bool CAngelOfDeliveranceCard::SetTriggerContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext, Damage damage) const
{
	return HasDelirium(GetController()) ? true : false;
}

CApothecaryGeistCard::CApothecaryGeistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Apothecary Geist"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("3") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, if you control another Spirit, you gain 3 life.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+3));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CApothecaryGeistCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);

	AddAbility(cpAbility.GetPointer());
}

bool CApothecaryGeistCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCardFilter spiritFilter(new CreatureTypeComparer(CREATURE_TYPE(Spirit), false));
	spiritFilter.AddNegateComparer(new SpecificCardComparer(this));
	return spiritFilter.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

CArchangelAvacynCard::CArchangelAvacynCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Archangel Avacyn"), CardType::_LegendaryCreature, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4), Power(6), Life(5), _T("Avacyn, the Purifier"))
	, m_bTransformPending(FALSE)
{
	// Flash. Flying, vigilance. (Avacyn, the Purifier: red, flying)
	GetCardKeyword()->AddFlash(FALSE);
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);

	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier;
	pKeywordModifier->GetModifier().SetToRemove(CreatureKeyword::Vigilance);
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	AddCreatureModifier(pKeywordModifier);
	AddCardModifier(new CCardColorModifier(CardType::Red));

	{
		// When Archangel Avacyn enters, creatures you control gain indestructible until end of turn.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArchangelAvacynCard::BeforeIndestructible));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// When a non-Angel creature you control dies, transform Archangel Avacyn at the beginning of the next upkeep.
		// (remembered here; the transformation is done by the upkeep trigger)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new CreatureTypeComparer(CREATURE_TYPE(Angel), false));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CArchangelAvacynCard::OnCreatureDied));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// ... transform at the beginning of the next upkeep. When this creature transforms into Avacyn, the Purifier,
		// it deals 3 damage to each other creature and each opponent.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CArchangelAvacynCard::SetUpkeepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArchangelAvacynCard::BeforeTransform));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CArchangelAvacynCard::BeforeIndestructible(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pModifier.ApplyTo(pBattlefield->GetAt(i));

	return true;
}

bool CArchangelAvacynCard::OnCreatureDied(CTriggeredAbility<>::TriggerContextType& triggerContext,
										  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced())
		m_bTransformPending = TRUE;
	return false;
}

bool CArchangelAvacynCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return m_bTransformPending && GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced();
}

bool CArchangelAvacynCard::BeforeTransform(CAbilityAction* pAction)
{
	m_bTransformPending = FALSE;
	if (GetZoneId() != ZoneId::Battlefield || GetOrientation()->IsSecondFaced())
		return true;

	CFaceTransformModifier pTransformModifier;
	pTransformModifier.ApplyTo(this);

	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i) != this && pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			pModifier.ApplyTo(GetGame()->GetPlayer(ip));

	return true;
}

// Back face of Archangel Avacyn: its abilities are in CArchangelAvacynCard
CAvacynThePurifierCard::CAvacynThePurifierCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Avacyn, the Purifier"), CardType::_LegendaryCreature, CREATURE_TYPE(Angel), nID,
		_T(""), Power(6), Life(5), Power(4), Life(4), _T("Archangel Avacyn"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
}

CBygoneBishopCard::CBygoneBishopCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bygone Bishop"), CardType::Creature,
		CREATURE_TYPE2(Spirit, Cleric), nID, _T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cast a creature spell with mana value 3 or less, investigate.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new ConvertedManaCostComparer<std::less<int>>(4));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CCatharsCompanionCard::CCatharsCompanionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cathar's Companion"), CardType::Creature,
		CREATURE_TYPE(Dog), nID, _T("2") WHITE_MANA_TEXT, Power(3), Life(1))
{
	// Whenever you cast a noncreature spell, this creature gains indestructible until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Indestructible);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CDauntlessCatharCard::CDauntlessCatharCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dauntless Cathar"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// {1}{W}, Exile this card from your graveyard: Create a 1/1 white Spirit creature token with flying. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("1") WHITE_MANA_TEXT,
			_T("Spirit (O)"), 55008,
			1));

	cpAbility->SetGraveyardOnly();
	cpAbility->AddExileCost();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

CDrogskolCavalryCard::CDrogskolCavalryCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Drogskol Cavalry"), CardType::Creature,
		CREATURE_TYPE2(Spirit, Knight), nID, _T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	{
		// Whenever another Spirit you control enters, you gain 2 life.
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Spirit), false));
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+2));
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{W}: Create a 1/1 white Spirit creature token with flying.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("3") WHITE_MANA_TEXT,
				_T("Spirit (O)"), 55008,
				1));
		AddAbility(cpAbility.GetPointer());
	}
}

CEmissaryOfTheSleeplessCard::CEmissaryOfTheSleeplessCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Emissary of the Sleepless"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("4") WHITE_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, if a creature died this turn, create a 1/1 white Spirit creature token with flying.
	// (as the Morbid cards of Innistrad)
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Spirit (O)"), 55008, 1);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEmissaryOfTheSleeplessCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

bool CEmissaryOfTheSleeplessCard::SetTriggerContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
													CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetGame()->GetCertainTypeDiedCount(CardType::Creature) > 0;
}

CInquisitorsOxCard::CInquisitorsOxCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inquisitor's Ox"), CardType::Creature,
		CREATURE_TYPE(Ox), nID, _T("3") WHITE_MANA_TEXT, Power(2), Life(5))
{
	// Delirium - This creature gets +1/+0 and has vigilance as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+1), CreatureKeyword::Vigilance);
}

CInspiringCaptainCard::CInspiringCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inspiring Captain"), CardType::Creature,
		CREATURE_TYPE2(Human, Knight), nID, _T("3") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, creatures you control get +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInspiringCaptainCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CInspiringCaptainCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
	}

	return true;
}

CMilitantInquisitorCard::CMilitantInquisitorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Militant Inquisitor"), CardType::Creature,
		CREATURE_TYPE2(Human, Cleric), nID, _T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// This creature gets +1/+0 for each Equipment you control. (as Vile Aggregate in Battle for Zendikar)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new CardTypeComparer(CardType::Equipment, false)));

	cpAbility->SetChangePowerOnly();
	AddAbility(cpAbility.GetPointer());
}

CMoorlandDrifterCard::CMoorlandDrifterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Moorland Drifter"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Delirium - This creature has flying as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+0), CreatureKeyword::Flying);
}

CNearheathChaplainCard::CNearheathChaplainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nearheath Chaplain"), CardType::Creature,
		CREATURE_TYPE2(Human, Cleric), nID, _T("3") WHITE_MANA_TEXT, Power(3), Life(1))
{
	GetCardKeyword()->AddLifelink(FALSE);

	// {2}{W}, Exile this card from your graveyard: Create two 1/1 white Spirit creature tokens with flying. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("2") WHITE_MANA_TEXT,
			_T("Spirit (O)"), 55008,
			2));

	cpAbility->SetGraveyardOnly();
	cpAbility->AddExileCost();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

CParanoidParishBladeCard::CParanoidParishBladeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Paranoid Parish-Blade"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Delirium - This creature gets +1/+0 and has first strike as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+1), CreatureKeyword::FirstStrike);
}

CPiousEvangelCard::CPiousEvangelCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Pious Evangel"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2), Power(2), Life(4), _T("Wayward Disciple"))
	, m_SacrificeFilter(_T("another permanent"), _T("other permanents"), new CardTypeComparer(CardType::_Permanent, false))
	, m_bLeftAsSecondFace(FALSE)
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// Wayward Disciple (second face) is black
	AddCardModifier(new CCardColorModifier(CardType::Black));

	{
		// Whenever this creature or another creature you control enters, you gain 1 life. (first face)
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPiousEvangelCard::SetFrontContext));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, {T}, Sacrifice another permanent: Transform this creature.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedCreatureCard::CanPlayFirstFace)));
		cpAbility->Add(cpTrait.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Wayward Disciple: Whenever this creature or another creature you control dies, target opponent loses 1 life
		// and you gain 1 life. (second face)
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPiousEvangelCard::SetBackContext));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CPiousEvangelCard::SetFrontContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
										CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced();
}

bool CPiousEvangelCard::SetBackContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
									   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	// This creature itself dying counts too, if it was Wayward Disciple: when it leaves the battlefield the card is
	// reset to its first face, so the face it had is remembered in Move()
	if (pCard == this)
		return m_bLeftAsSecondFace ? true : false;

	return GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced();
}

void CPiousEvangelCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	if (GetZoneId() == ZoneId::Battlefield && pToZone->GetZoneId() != ZoneId::Battlefield)
		m_bLeftAsSecondFace = GetOrientation()->IsSecondFaced();

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);
}

// Back face of Pious Evangel: its abilities are in CPiousEvangelCard
CWaywardDiscipleCard::CWaywardDiscipleCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Wayward Disciple"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T(""), Power(2), Life(4), Power(2), Life(2), _T("Pious Evangel"))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
}

CReaperOfFlightMoonsilverCard::CReaperOfFlightMoonsilverCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Reaper of Flight Moonsilver"), CardType::Creature,
		CREATURE_TYPE(Angel), nID, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_SacrificeFilter(_T("another creature"), _T("other creatures"), new AnyCreatureComparer)
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// Delirium - Sacrifice another creature: This creature gets +2/+1 until end of turn. Activate only if there are
	// four or more card types among cards in your graveyard.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T(""), Power(+2), Life(+1)));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);

	counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
		CPlayableIfTrait::PlayableCallback(this, &CReaperOfFlightMoonsilverCard::CanActivate)));
	cpAbility->Add(cpTrait.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

BOOL CReaperOfFlightMoonsilverCard::CanActivate(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

CSpectralShepherdCard::CSpectralShepherdCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spectral Shepherd"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// {1}{U}: Return target Spirit you control to its owner's hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("1") BLUE_MANA_TEXT,
			new CreatureTypeComparer(CREATURE_TYPE(Spirit), false),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CSternConstableCard::CSternConstableCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stern Constable"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, WHITE_MANA_TEXT, Power(1), Life(1))
{
	// {T}, Discard a card: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			_T(""),
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CThaliasLieutenantCard::CThaliasLieutenantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thalia's Lieutenant"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("1") WHITE_MANA_TEXT, Power(1), Life(1))
{
	{
		// When this creature enters, put a +1/+1 counter on each other Human you control.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThaliasLieutenantCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever another Human you control enters, put a +1/+1 counter on this creature.
		typedef
			TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false));
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CThaliasLieutenantCard::SetHumanContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CThaliasLieutenantCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard != this && pCard->GetCardType().IsCreature() &&
			((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Human))
			pModifier.ApplyTo(pCard);
	}

	return true;
}

bool CThaliasLieutenantCard::SetHumanContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											 CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	// The counter goes on this creature, not on the Human that entered
	triggerContext.m_pCard = (CCard*)this;
	return GetZoneId() == ZoneId::Battlefield;
}

CThrabenInspectorCard::CThrabenInspectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thraben Inspector"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, WHITE_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, investigate.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CTopplegeistCard::CTopplegeistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Topplegeist"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, WHITE_MANA_TEXT, Power(1), Life(1))
{
	{
		// When this creature enters, tap target creature an opponent controls.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardModifiers().push_back(new CCardOrientationModifier(TRUE));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of each opponent's upkeep, if there are four or more card types among cards in
		// your graveyard, tap target creature that player controls.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardModifiers().push_back(new CCardOrientationModifier(TRUE));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTopplegeistCard::SetUpkeepContext));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CTopplegeistCard::SetUpkeepContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasDelirium(GetController()) ? true : false;
}

CTownGossipmongerCard::CTownGossipmongerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Town Gossipmonger"), CardType::Creature, CREATURE_TYPE(Human), nID,
		WHITE_MANA_TEXT, Power(1), Life(1), Power(2), Life(3), _T("Incited Rabble"))
	, m_TapFilter(_T("an untapped creature"), _T("untapped creatures"), new AnyCreatureComparer)
{
	m_TapFilter.AddNegateComparer(new TappedComparer);
	m_TapFilter.AddNegateComparer(new SpecificCardComparer(this));

	// Incited Rabble (second face): red, attacks each combat if able.
	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier;
	pKeywordModifier->GetModifier().SetToAdd(CreatureKeyword::MustAttack);
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	AddCreatureModifier(pKeywordModifier);
	AddCardModifier(new CCardColorModifier(CardType::Red));

	{
		// {T}, Tap an untapped creature you control: Transform this creature. (first face)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddTapCardCost(1, &m_TapFilter);
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedCreatureCard::CanPlayFirstFace)));
		cpAbility->Add(cpTrait.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}: This creature gets +1/+0 until end of turn. (second face)
		counted_ptr<CPumpAbility> cpAbility(
			::CreateObject<CPumpAbility>(this, _T("2"), Power(+1), Life(+0)));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CDoubleFacedCreatureCard::CanPlaySecondFace)));
		cpAbility->Add(cpTrait.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
}

// Back face of Town Gossipmonger: its abilities are in CTownGossipmongerCard
CIncitedRabbleCard::CIncitedRabbleCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Incited Rabble"), CardType::Creature, CREATURE_TYPE(Human), nID,
		_T(""), Power(2), Life(3), Power(1), Life(1), _T("Town Gossipmonger"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddMustAttack(FALSE);
}

//____________________________________________________________________________
//
// Werewolves

CWerewolfSupport::CWerewolfSupport(CDoubleFacedCreatureCard* pCard)
	: m_pCard(pCard)
{
}

void CWerewolfSupport::AddTransformAbilities()
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWerewolfSupport::SetDayContext));
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);

		m_pCard->AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWerewolfSupport::SetNightContext));
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);

		m_pCard->AddAbility(cpAbility.GetPointer());
	}
}

bool CWerewolfSupport::SetDayContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return (!m_pCard->GetOrientation()->IsSecondFaced() && m_pCard->GetGame()->GetLastTurnCastedSpellCount() == 0);
}

bool CWerewolfSupport::SetNightContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	if (!m_pCard->GetOrientation()->IsSecondFaced())
		return false;

	for (int ip = 0; ip < m_pCard->GetGame()->GetPlayerCount(); ++ip)
		if (m_pCard->GetGame()->GetPlayer(ip)->GetLastTurnCastedSpellCount() >= 2)
			return true;

	return false;
}

// Makes the back face of a werewolf only a Werewolf (removes the other creature types of the first face)
static void RemoveTypesOnSecondFace(CDoubleFacedCreatureCard* pCard, SingleCreatureType type1, SingleCreatureType type2 = SingleCreatureType::Null)
{
	pCard->AddCreatureModifier(new CCreatureTypeModifier(type1, FALSE));
	if (type2 != SingleCreatureType::Null)
		pCard->AddCreatureModifier(new CCreatureTypeModifier(type2, FALSE));
}

static CPlayableIfTrait::PlayableCallback FirstFaceCallback(CDoubleFacedCreatureCard* pCard)
{
	return CPlayableIfTrait::PlayableCallback(pCard, &CDoubleFacedCreatureCard::CanPlayFirstFace);
}

static CPlayableIfTrait::PlayableCallback SecondFaceCallback(CDoubleFacedCreatureCard* pCard)
{
	return CPlayableIfTrait::PlayableCallback(pCard, &CDoubleFacedCreatureCard::CanPlaySecondFace);
}

static void AddTrait(CAbility* pAbility, CPlayableIfTrait::PlayableCallback callback)
{
	counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(pAbility, callback));
	pAbility->Add(cpTrait.GetPointer());
}

//____________________________________________________________________________
//
// Green creatures

CBriarbridgePatrolCard::CBriarbridgePatrolCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Briarbridge Patrol"), CardType::Creature,
		CREATURE_TYPE2(Human, Warrior), nID, _T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Whenever this creature deals damage to one or more creatures, investigate.
	// Note: it investigates for each creature dealt damage. The ability that puts a creature card from your hand onto
	// the battlefield if you sacrificed three or more Clues this turn is not implemented.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::CreatureEventCallback,
						   &CWhenSelfDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CBywayCourierCard::CBywayCourierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Byway Courier"), CardType::Creature,
		CREATURE_TYPE2(Human, Scout), nID, _T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// When this creature dies, investigate.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CCultOfTheWaxingMoonCard::CCultOfTheWaxingMoonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cult of the Waxing Moon"), CardType::Creature,
		CREATURE_TYPE2(Human, Shaman), nID, _T("4") GREEN_MANA_TEXT, Power(5), Life(4))
{
	// Whenever a permanent you control transforms into a non-Human creature, create a 2/2 green Wolf creature token.
	// (as Huntmaster of the Fells in Dark Ascension)
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Wolf (K)"), 55004, 1);
	cpAbility->GetTrigger().SetTriggerIndex(TRANSFORM_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCultOfTheWaxingMoonCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

bool CCultOfTheWaxingMoonCard::SetTriggerContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext, CCard* pCard, int nId) const
{
	if (GetZoneId() != ZoneId::Battlefield || pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetController() != GetController())
		return false;

	return pCard->GetCardType().IsCreature() &&
		!((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Human);
}

CDeathcapCultivatorCard::CDeathcapCultivatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deathcap Cultivator"), CardType::Creature,
		CREATURE_TYPE2(Human, Druid), nID, _T("1") GREEN_MANA_TEXT, Power(2), Life(1))
{
	// {T}: Add {B} or {G}.
	LPCTSTR manas[] = { BLACK_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, manas[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	// Delirium - This creature has deathtouch as long as there are four or more card types among cards in your graveyard.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0)));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	SetDeliriumCondition(cpAbility.GetPointer());
	AddAbility(cpAbility.GetPointer());
}

CDuskwatchRecruiterCard::CDuskwatchRecruiterCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Duskwatch Recruiter"), CardType::Creature, CREATURE_TYPE3(Human, Warrior, Werewolf), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2), Power(3), Life(3), _T("Krallenhorde Howler"))
	, m_CreatureFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Warrior);
	m_Werewolf.AddTransformAbilities();

	{
		// {2}{G}: Look at the top three cards of your library. You may reveal a creature card from among them and put it
		// into your hand. Put the rest on the bottom of your library in any order. (first face)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") GREEN_MANA_TEXT));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDuskwatchRecruiterCard::BeforeResolution));
		AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Krallenhorde Howler: Creature spells you cast cost {1} less to cast. (second face)
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new AnyCreatureComparer,
				_T("1")));

		cpAbility->SetAbilityName(_T("Second Face Enchantment"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDuskwatchRecruiterCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Oath of Nissa in Oath of the Gatewatch)
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(3), MaximumValue(3));
		pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
		pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
		pModifier->GetSelection(0).moveType = MoveType::Others;
		pModifier->AddSelection(MinimumValue(0), MaximumValue(1), // select a card to the hand
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::AllPlayers,	// reveal to
			&m_CreatureFilter,						// creature cards
			ZoneId::Hand,							// if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top,
			MoveType::Others,						// move type
			CZoneModifier::RoleType::PrimaryPlayer);

		// and put the rest on the bottom of the library
		pModifier->SetReorderInformation(
			true,
			ZoneId::Library,
			CZoneModifier::RoleType::PrimaryPlayer,	// this player's library
			CardPlacement::Bottom);

	pModifier->ApplyTo(pAction->GetController());

	return true;
}

// Back face of Duskwatch Recruiter: its abilities are in CDuskwatchRecruiterCard
CKrallenhordeHowlerCard::CKrallenhordeHowlerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Krallenhorde Howler"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(3), Life(3), Power(2), Life(2), _T("Duskwatch Recruiter"))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
}

CGrafMoleCard::CGrafMoleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Graf Mole"), CardType::Creature,
		CREATURE_TYPE2(Mole, Beast), nID, _T("2") GREEN_MANA_TEXT, Power(2), Life(4))
{
	// Whenever you sacrifice a Clue, you gain 3 life.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+3));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGrafMoleCard::SetClueContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);

	AddAbility(cpAbility.GetPointer());
}

bool CGrafMoleCard::SetClueContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
								   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return IsClueSacrificed(pCard, moveType);
}

CHermitOfTheNatterknollsCard::CHermitOfTheNatterknollsCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Hermit of the Natterknolls"), CardType::Creature, CREATURE_TYPE2(Human, Werewolf), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3), Power(3), Life(5), _T("Lone Wolf of the Natterknolls"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human);
	m_Werewolf.AddTransformAbilities();

	// Whenever an opponent casts a spell during your turn, draw a card. (Lone Wolf: draw two cards)
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(true);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
		cpAbility->SetDrawCount(1);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CHermitOfTheNatterknollsCard::SetFrontContext));

		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(true);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
		cpAbility->SetDrawCount(2);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CHermitOfTheNatterknollsCard::SetBackContext));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CHermitOfTheNatterknollsCard::SetFrontContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	return GetGame()->GetActivePlayer() == GetController() && !GetOrientation()->IsSecondFaced();
}

bool CHermitOfTheNatterknollsCard::SetBackContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	return GetGame()->GetActivePlayer() == GetController() && GetOrientation()->IsSecondFaced();
}

// Back face of Hermit of the Natterknolls: its abilities are in CHermitOfTheNatterknollsCard
CLoneWolfOfTheNatterknollsCard::CLoneWolfOfTheNatterknollsCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Lone Wolf of the Natterknolls"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(3), Life(5), Power(2), Life(3), _T("Hermit of the Natterknolls"))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
}

CHinterlandLoggerCard::CHinterlandLoggerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Hinterland Logger"), CardType::Creature, CREATURE_TYPE2(Human, Werewolf), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1), Power(4), Life(2), _T("Timber Shredder"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human);
	m_Werewolf.AddTransformAbilities();

	// Timber Shredder: Trample
	CCreatureKeywordModifier* pKeywordModifier = new CCreatureKeywordModifier;
	pKeywordModifier->GetModifier().SetToAdd(CreatureKeyword::Trample);
	pKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	AddCreatureModifier(pKeywordModifier);
}

// Back face of Hinterland Logger: its abilities are in CHinterlandLoggerCard
CTimberShredderCard::CTimberShredderCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Timber Shredder"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(4), Life(2), Power(2), Life(1), _T("Hinterland Logger"))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
	GetCreatureKeyword()->AddTrample(FALSE);
}

CInexorableBlobCard::CInexorableBlobCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inexorable Blob"), CardType::Creature,
		CREATURE_TYPE(Ooze), nID, _T("2") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Delirium - Whenever this creature attacks, if there are four or more card types among cards in your graveyard,
	// create a 3/3 green Ooze creature token that's tapped and attacking. (as Captain's Claws in Oath of the Gatewatch)
	typedef
		TTriggeredAbility< CAttackingTokenCreationAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTokenName(_T("Ooze (F)"));
	cpAbility->SetTokenNumber(1);
	cpAbility->SetTokenuID(55081);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CInexorableBlobCard::SetTriggerContext));

	AddAbility(cpAbility.GetPointer());
}

bool CInexorableBlobCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return HasDelirium(GetController()) ? true : false;
}

CIntrepidProvisionerCard::CIntrepidProvisionerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Intrepid Provisioner"), CardType::Creature,
		CREATURE_TYPE2(Human, Scout), nID, _T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, another target Human you control gets +2/+2 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+2));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+2));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CKessigDireSwineCard::CKessigDireSwineCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kessig Dire Swine"), CardType::Creature,
		CREATURE_TYPE2(Boar, Horror), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Delirium - This creature has trample as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+0), CreatureKeyword::Trample);
}

CLoamDryadCard::CLoamDryadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loam Dryad"), CardType::Creature,
		CREATURE_TYPE2(Dryad, Horror), nID, GREEN_MANA_TEXT, Power(1), Life(2))
	, m_TapFilter(_T("an untapped creature"), _T("untapped creatures"), new AnyCreatureComparer)
{
	m_TapFilter.AddNegateComparer(new TappedComparer);
	m_TapFilter.AddNegateComparer(new SpecificCardComparer(this));

	// {T}, Tap an untapped creature you control: Add one mana of any color.
	LPCTSTR manas[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, manas[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddTapCardCost(1, &m_TapFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

CMoldgrafScavengerCard::CMoldgrafScavengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Moldgraf Scavenger"), CardType::Creature,
		CREATURE_TYPE(Fungus), nID, _T("1") GREEN_MANA_TEXT, Power(0), Life(4))
{
	// Delirium - This creature gets +3/+0 as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+3), CreatureKeyword::Null);
}

CObsessiveSkinnerCard::CObsessiveSkinnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Obsessive Skinner"), CardType::Creature,
		CREATURE_TYPE2(Human, Rogue), nID, _T("1") GREEN_MANA_TEXT, Power(1), Life(1))
{
	{
		// When this creature enters, put a +1/+1 counter on target creature.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of each opponent's upkeep, if there are four or more card types among cards in
		// your graveyard, put a +1/+1 counter on target creature. (as Topplegeist)
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CObsessiveSkinnerCard::SetUpkeepContext));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CObsessiveSkinnerCard::SetUpkeepContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasDelirium(GetController()) ? true : false;
}

CPackGuardianCard::CPackGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pack Guardian"), CardType::Creature,
		CREATURE_TYPE2(Wolf, Spirit), nID, _T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(3))
	, m_LandFilter(_T("a land card"), _T("land cards"), new CardTypeComparer(CardType::_Land, false))
{
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, you may discard a land card. If you do, create a 2/2 green Wolf creature token.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDiscardResolutionCost(1, &m_LandFilter);
	cpAbility->SetCreateTokenOption(TRUE, _T("Wolf (K)"), 55004, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CQuilledWolfCard::CQuilledWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Quilled Wolf"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {5}{G}: This creature gets +4/+4 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("5") GREEN_MANA_TEXT, Power(+4), Life(+4)));
	AddAbility(cpAbility.GetPointer());
}

CSolitaryHunterCard::CSolitaryHunterCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Solitary Hunter"), CardType::Creature, CREATURE_TYPE3(Human, Warrior, Werewolf), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(4), Power(5), Life(6), _T("One of the Pack"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Warrior);
	m_Werewolf.AddTransformAbilities();
}

// Back face of Solitary Hunter: its abilities are in CSolitaryHunterCard
COneOfThePackCard::COneOfThePackCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("One of the Pack"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(5), Life(6), Power(3), Life(4), _T("Solitary Hunter"))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
}

CSoulSwallowerCard::CSoulSwallowerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Soul Swallower"), CardType::Creature,
		CREATURE_TYPE(Wurm), nID, _T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Delirium - At the beginning of your upkeep, if there are four or more card types among cards in your graveyard,
	// put three +1/+1 counters on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSoulSwallowerCard::SetUpkeepContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSoulSwallowerCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CSoulSwallowerCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasDelirium(GetController()) ? true : false;
}

bool CSoulSwallowerCard::BeforeResolution(CAbilityAction* pAction) const
{
	// The intervening "if" is checked again on resolution
	if (GetZoneId() == ZoneId::Battlefield && HasDelirium(GetController()))
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +3);
		pModifier.ApplyTo((CCard*)this);
	}
	return true;
}

CStoicBuilderCard::CStoicBuilderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stoic Builder"), CardType::Creature,
		CREATURE_TYPE(Human), nID, _T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, you may return target land card from your graveyard to your hand.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));

	AddAbility(cpAbility.GetPointer());
}

CTirelessTrackerCard::CTirelessTrackerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tireless Tracker"), CardType::Creature,
		CREATURE_TYPE2(Human, Scout), nID, _T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	{
		// Landfall - Whenever a land you control enters, investigate.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you sacrifice a Clue, put a +1/+1 counter on this creature.
		typedef
			TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTirelessTrackerCard::SetClueContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CTirelessTrackerCard::SetClueContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
										  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	// The counter goes on this creature, not on the Clue
	triggerContext.m_pCard = (CCard*)this;
	return GetZoneId() == ZoneId::Battlefield && IsClueSacrificed(pCard, moveType);
}

CUlvenwaldHydraCard::CUlvenwaldHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ulvenwald Hydra"), CardType::Creature,
		CREATURE_TYPE(Hydra), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(0), Life(0))
{
	GetCreatureKeyword()->AddReach(FALSE);

	{
		// Ulvenwald Hydra's power and toughness are each equal to the number of lands you control. (as Vile Aggregate)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new CardTypeComparer(CardType::_Land, false)));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this creature enters, you may search your library for a land card, put it onto the battlefield tapped, then shuffle.
		typedef
			TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
		cpAbility->SetToZone(ZoneId::Battlefield);
		cpAbility->SetToOwnersZone(FALSE);
		cpAbility->SetTapped(TRUE);

		AddAbility(cpAbility.GetPointer());
	}
}

CVeteranCatharCard::CVeteranCatharCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Veteran Cathar"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {3}{W}: Target Human gains double strike until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("3") WHITE_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::DoubleStrike, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false));
	AddAbility(cpAbility.GetPointer());
}

CWatcherInTheWebCard::CWatcherInTheWebCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Watcher in the Web"), CardType::Creature,
		CREATURE_TYPE(Spider), nID, _T("4") GREEN_MANA_TEXT, Power(2), Life(5))
{
	GetCreatureKeyword()->AddReach(FALSE);

	// This creature can block an additional seven creatures each combat.
	SetMaxBlockingCount(8);
}

//____________________________________________________________________________
//
// Red creatures

// Creature keywords gained / lost by a double-faced creature on its second face
static void SetSecondFaceKeywords(CDoubleFacedCreatureCard* pCard, CreatureKeyword toAdd, CreatureKeyword toRemove)
{
	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(toAdd);
	pModifier->GetModifier().SetToRemove(toRemove);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	pCard->AddCreatureModifier(pModifier);
}

// Adds the madness spell of a creature (cast as the creature, for its madness cost)
static void AddCreatureMadness(CCard* pCard, CMadnessSupport& madness, LPCTSTR strMadnessCost)
{
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(pCard, pCard->GetSpells().GetAt(0)->GetAbilityType(), strMadnessCost, TRUE));
	pCard->AddSpell(cpSpell.GetPointer());
	madness.SetMadnessSpell(cpSpell.GetPointer());
}

CBloodmadVampireCard::CBloodmadVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodmad Vampire"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Berserker), nID, _T("2") RED_MANA_TEXT, Power(4), Life(1))
	, m_Madness(this)
{
	AddCreatureMadness(this, m_Madness, _T("1") RED_MANA_TEXT);

	// Whenever this creature deals combat damage to a player, put a +1/+1 counter on it.
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodmadVampireCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CBloodmadVampireCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	triggerContext.m_pCard = (CCard*)this;
	return true;
}

CBreakneckRiderCard::CBreakneckRiderCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Breakneck Rider"), CardType::Creature, CREATURE_TYPE3(Human, Scout, Werewolf), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3), Power(4), Life(3), _T("Neck Breaker"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Scout);
	m_Werewolf.AddTransformAbilities();

	// Neck Breaker: Attacking creatures you control get +1/+0 and have trample.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AttackingCreatureComparer,
			Power(+1), Life(+0), CreatureKeyword::Trample));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetAbilityName(_T("Second Face Enchantment"));
	AddAbility(cpAbility.GetPointer());
}

// Back face of Breakneck Rider: its abilities are in CBreakneckRiderCard
CNeckBreakerCard::CNeckBreakerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Neck Breaker"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(4), Life(3), Power(3), Life(3), _T("Breakneck Rider"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
}

CConvictedKillerCard::CConvictedKillerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Convicted Killer"), CardType::Creature, CREATURE_TYPE2(Human, Werewolf), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2), Power(4), Life(4), _T("Branded Howler"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human);
	m_Werewolf.AddTransformAbilities();
}

// Back face of Convicted Killer
CBrandedHowlerCard::CBrandedHowlerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Branded Howler"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(4), Life(4), Power(2), Life(2), _T("Convicted Killer"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
}

CEmberEyeWolfCard::CEmberEyeWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ember-Eye Wolf"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("1") RED_MANA_TEXT, Power(1), Life(2))
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// {1}{R}: This creature gets +2/+0 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("1") RED_MANA_TEXT, Power(+2), Life(+0)));
	AddAbility(cpAbility.GetPointer());
}

CFlamebladeAngelCard::CFlamebladeAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Flameblade Angel"), CardType::Creature,
		CREATURE_TYPE(Angel), nID, _T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// Whenever a source an opponent controls deals damage to you or a permanent you control, you may have this
	// creature deal 1 damage to that source's controller.
	// Note: only damage to you or to creatures you control; the damage goes to each opponent (the source's controller
	// in a two-player game).
	{
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenDamageDealt,
							   CWhenDamageDealt::PlayerEventCallback,
							   &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenDamageDealt,
							   CWhenDamageDealt::CreatureEventCallback,
							   &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFlamebladeAngelCard::SetCreatureContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CFlamebladeAngelCard::SetCreatureContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											  CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const
{
	return pToCreature && pToCreature->GetController() == GetController();
}

CGatstafArsonistsCard::CGatstafArsonistsCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Gatstaf Arsonists"), CardType::Creature, CREATURE_TYPE2(Human, Werewolf), nID,
		_T("4") RED_MANA_TEXT, Power(5), Life(4), Power(6), Life(5), _T("Gatstaf Ravagers"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human);
	SetSecondFaceKeywords(this, CreatureKeyword::CantBeBlockedBy1, CreatureKeyword::Null);	// Gatstaf Ravagers: menace
	m_Werewolf.AddTransformAbilities();
}

// Back face of Gatstaf Arsonists
CGatstafRavagersCard::CGatstafRavagersCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Gatstaf Ravagers"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(6), Life(5), Power(5), Life(4), _T("Gatstaf Arsonists"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CGeierReachBanditCard::CGeierReachBanditCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Geier Reach Bandit"), CardType::Creature, CREATURE_TYPE3(Human, Rogue, Werewolf), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2), Power(4), Life(3), _T("Vildin-Pack Alpha"))
	, m_Werewolf(this)
{
	GetCreatureKeyword()->AddHaste(FALSE);
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Rogue);
	SetSecondFaceKeywords(this, CreatureKeyword::Null, CreatureKeyword::Haste);	// Vildin-Pack Alpha has no haste
	m_Werewolf.AddTransformAbilities();

	// Vildin-Pack Alpha: Whenever a Werewolf you control enters, you may transform it.
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Werewolf), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTriggeredCardModifiers().push_back(new CFaceTransformModifier);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGeierReachBanditCard::SetWerewolfContext));

	AddAbility(cpAbility.GetPointer());
}

bool CGeierReachBanditCard::SetWerewolfContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_pCard = pCard;
	return GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced();
}

// Back face of Geier Reach Bandit
CVildinPackAlphaCard::CVildinPackAlphaCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Vildin-Pack Alpha"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(4), Life(3), Power(3), Life(2), _T("Geier Reach Bandit"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
}

CGibberingFiendCard::CGibberingFiendCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gibbering Fiend"), CardType::Creature,
		CREATURE_TYPE(Devil), nID, _T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	{
		// When this creature enters, it deals 1 damage to each opponent.
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of each opponent's upkeep, if there are four or more card types among cards in
		// your graveyard, this creature deals 1 damage to that player.
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGibberingFiendCard::SetUpkeepContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CGibberingFiendCard::SetUpkeepContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasDelirium(GetController()) ? true : false;
}

CHowlpackWolfCard::CHowlpackWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Howlpack Wolf"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("2") RED_MANA_TEXT, Power(3), Life(3))
{
	// This creature can't block unless you control another Wolf or Werewolf.
	// (can't block while you control no other Wolf or Werewolf: a condition with a maximum of 0)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::CantBlock));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new WolfOrWerewolfComparer);
	cpAbility->GetConditionFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetConditionCheckZone(ZoneId::Battlefield);
	cpAbility->SetConditionIsMaximum();
	cpAbility->SetConditionValue(0);
	AddAbility(cpAbility.GetPointer());
}

CIncorrigibleYouthsCard::CIncorrigibleYouthsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Incorrigible Youths"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(3))
	, m_Madness(this)
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// Madness {2}{R}
	AddCreatureMadness(this, m_Madness, _T("2") RED_MANA_TEXT);
}

CInsolentNeonateCard::CInsolentNeonateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Insolent Neonate"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, RED_MANA_TEXT, Power(1), Life(1))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace

	// Discard a card, Sacrifice this creature: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CKessigForgemasterCard::CKessigForgemasterCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Kessig Forgemaster"), CardType::Creature, CREATURE_TYPE3(Human, Shaman, Werewolf), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1), Power(3), Life(2), _T("Flameheart Werewolf"))
	, m_Werewolf(this)
{
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Shaman);
	m_Werewolf.AddTransformAbilities();

	// Whenever this creature blocks or becomes blocked by a creature, this creature deals 1 damage to that creature.
	// (Flameheart Werewolf: 2 damage) (as Shield of the Righteous in Alara Reborn)
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback2,
						   &CWhenSelfAttackedBlocked::SetBlockingOrBlockedEachTimeEventCallback > TriggeredAbility;

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(i == 0 ? -1 : -2));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::Preventable);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this,
			i == 0 ? &CKessigForgemasterCard::SetFrontContext : &CKessigForgemasterCard::SetBackContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CKessigForgemasterCard::SetFrontContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
											 CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const
{
	triggerContext.m_pCreature = pCreature2;
	return pCreature2 && !GetOrientation()->IsSecondFaced();
}

bool CKessigForgemasterCard::SetBackContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
											CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const
{
	triggerContext.m_pCreature = pCreature2;
	return pCreature2 && GetOrientation()->IsSecondFaced();
}

// Back face of Kessig Forgemaster
CFlameheartWerewolfCard::CFlameheartWerewolfCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Flameheart Werewolf"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(3), Life(2), Power(2), Life(1), _T("Kessig Forgemaster"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
}

CPyreHoundCard::CPyreHoundCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pyre Hound"), CardType::Creature,
		CREATURE_TYPE2(Elemental, Dog), nID, _T("3") RED_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever you cast an instant or sorcery spell, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPyreHoundCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CPyreHoundCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	triggerContext.m_pCard = (CCard*)this;
	return true;
}

CRavenousBloodseekerCard::CRavenousBloodseekerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ravenous Bloodseeker"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Berserker), nID, _T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// Discard a card: This creature gets +2/-2 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T(""), Power(+2), Life(-2)));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	AddAbility(cpAbility.GetPointer());
}

CScourgeWolfCard::CScourgeWolfCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scourge Wolf"), CardType::Creature,
		CREATURE_TYPE2(Wolf, Horror), nID, RED_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Delirium - This creature has double strike as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+0), CreatureKeyword::DoubleStrike);
}

CUlrichsKindredCard::CUlrichsKindredCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ulrich's Kindred"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// {3}{G}: Target attacking Wolf or Werewolf gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("3") GREEN_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new WolfOrWerewolfComparer);
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(pModifier);

	AddAbility(cpAbility.GetPointer());
}

CVillageMessengerCard::CVillageMessengerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Village Messenger"), CardType::Creature, CREATURE_TYPE2(Human, Werewolf), nID,
		RED_MANA_TEXT, Power(1), Life(1), Power(2), Life(2), _T("Moonrise Intruder"))
	, m_Werewolf(this)
{
	GetCreatureKeyword()->AddHaste(FALSE);
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human);
	SetSecondFaceKeywords(this, CreatureKeyword::CantBeBlockedBy1, CreatureKeyword::Haste);	// Moonrise Intruder: menace, no haste
	m_Werewolf.AddTransformAbilities();
}

// Back face of Village Messenger
CMoonriseIntruderCard::CMoonriseIntruderCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Moonrise Intruder"), CardType::Creature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(2), Life(2), Power(1), Life(1), _T("Village Messenger"))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CVoldarenDuelistCard::CVoldarenDuelistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Voldaren Duelist"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Warrior), nID, _T("3") RED_MANA_TEXT, Power(3), Life(2))
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, target creature can't block this turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::CantBlock);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Black creatures

CAsylumVisitorCard::CAsylumVisitorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Asylum Visitor"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Wizard), nID, _T("1") BLACK_MANA_TEXT, Power(3), Life(1))
	, m_Madness(this)
{
	AddCreatureMadness(this, m_Madness, _T("1") BLACK_MANA_TEXT);

	// At the beginning of each player's upkeep, if that player has no cards in hand, you draw a card and you lose 1 life.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToController);
	cpAbility->SetDrawCount(1);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAsylumVisitorCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);

	AddAbility(cpAbility.GetPointer());
}

bool CAsylumVisitorCard::SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	CPlayer* pPlayer = GetGame()->GetActivePlayer();
	return pPlayer && pPlayer->GetZoneById(ZoneId::Hand)->GetSize() == 0;
}

CCrowOfDarkTidingsCard::CCrowOfDarkTidingsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Crow of Dark Tidings"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Bird), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters or dies, mill two cards.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > EnterAbility;
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > DiesAbility;
	{
		counted_ptr<EnterAbility> cpAbility(::CreateObject<EnterAbility>(this));

		cpAbility->SetOptionalType(EnterAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrowOfDarkTidingsCard::BeforeMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<DiesAbility> cpAbility(::CreateObject<DiesAbility>(this));

		cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
		cpAbility->SetOptionalType(DiesAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrowOfDarkTidingsCard::BeforeMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCrowOfDarkTidingsCard::BeforeMill(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 2);
	return true;
}

CDiregrafColossusCard::CDiregrafColossusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Diregraf Colossus"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Giant), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CDiregrafColossusCard::OnZoneChanged))
{
	// This creature enters with a +1/+1 counter on it for each Zombie card in your graveyard. (as Endless One)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// Whenever you cast a Zombie spell, create a tapped 2/2 black Zombie creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDiregrafColossusCard::BeforeZombie));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

void CDiregrafColossusCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		CCardFilter zombieFilter(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
		int nZombies = zombieFilter.CountIncluded(GetController()->GetZoneById(ZoneId::Graveyard)->GetCardContainer());
		if (nZombies > 0)
		{
			CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +nZombies);
			pModifier.ApplyTo(this);
		}
	}
}

bool CDiregrafColossusCard::BeforeZombie(CAbilityAction* pAction) const
{
	CreateTappedZombies(GetGame(), pAction->GetController(), 1);
	return true;
}

CElusiveTormentorCard::CElusiveTormentorCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Elusive Tormentor"), CardType::Creature, CREATURE_TYPE2(Vampire, Wizard), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4), Power(0), Life(1), _T("Insidious Mist"))
{
	// Insidious Mist (second face): blue Elemental 0/1. Hexproof, indestructible. Can't block and can't be blocked.
	// Note: "Whenever this creature attacks and isn't blocked, you may pay {2}{B}. If you do, transform it" is not implemented.
	AddCardModifier(new CCardColorModifier(CardType::Blue));
	RemoveTypesOnSecondFace(this, SingleCreatureType::Vampire, SingleCreatureType::Wizard);
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Elemental, TRUE));
	SetSecondFaceKeywords(this, CreatureKeyword::CantBlock | CreatureKeyword::Unblockable, CreatureKeyword::Null);

	CCardKeywordModifier* pCardKeywordModifier = new CCardKeywordModifier;
	pCardKeywordModifier->GetModifier().SetToAdd(CardKeyword::Hexproof | CardKeyword::Indestructible);
	pCardKeywordModifier->GetModifier().SetOneTurnOnly(FALSE);
	AddCardModifier(pCardKeywordModifier);

	// {1}, Discard a card: Transform this creature. (first face)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
	AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
	AddAbility(cpAbility.GetPointer());
}

// Back face of Elusive Tormentor
CInsidiousMistCard::CInsidiousMistCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Insidious Mist"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T(""), Power(0), Life(1), Power(4), Life(4), _T("Elusive Tormentor"))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCardKeyword()->AddHexproof(FALSE);
	GetCardKeyword()->AddIndestructible(FALSE);
	GetCreatureKeyword()->AddCantBlock(FALSE);
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

CFarbogRevenantCard::CFarbogRevenantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Farbog Revenant"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("2") BLACK_MANA_TEXT, Power(1), Life(3))
{
	GetCreatureKeyword()->AddSkulk(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

CGhoulcallersAccompliceCard::CGhoulcallersAccompliceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghoulcaller's Accomplice"), CardType::Creature,
		CREATURE_TYPE2(Human, Rogue), nID, _T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// {3}{B}, Exile this card from your graveyard: Create a 2/2 black Zombie creature token. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("3") BLACK_MANA_TEXT,
			_T("Zombie (P)"), 55009,
			1));

	cpAbility->SetGraveyardOnly();
	cpAbility->AddExileCost();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

CGhoulsteedCard::CGhoulsteedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghoulsteed"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horse), nID, _T("4") BLACK_MANA_TEXT, Power(4), Life(4))
{
	// {2}{B}, Discard two cards: Return this card from your graveyard to the battlefield tapped. (as Drownyard Temple)
	counted_ptr<CSelfMoveCardAbility> cpAbility(
		::CreateObject<CSelfMoveCardAbility>(this,
			_T("2") BLACK_MANA_TEXT,
			ZoneId::Battlefield, FALSE, MoveType::Others));

	cpAbility->SetGraveyardOnly();
	cpAbility->GetCost().AddDiscardCardCost(2, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddAbility(cpAbility.GetPointer());
}

CHeirOfFalkenrathCard::CHeirOfFalkenrathCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Heir of Falkenrath"), CardType::Creature, CREATURE_TYPE(Vampire), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1), Power(3), Life(2), _T("Heir to the Night"))
{
	// Heir to the Night (second face): Vampire Berserker with flying.
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Berserker, TRUE));
	SetSecondFaceKeywords(this, CreatureKeyword::Flying, CreatureKeyword::Null);

	// Discard a card: Transform this creature. Activate only once each turn. (first face)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetMaxTurnUsageCount(1);
	cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
	AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
	AddAbility(cpAbility.GetPointer());
}

// Back face of Heir of Falkenrath
CHeirToTheNightCard::CHeirToTheNightCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Heir to the Night"), CardType::Creature, CREATURE_TYPE2(Vampire, Berserker), nID,
		_T(""), Power(3), Life(2), Power(2), Life(1), _T("Heir of Falkenrath"))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
}

CHoundOfTheFarbogsCard::CHoundOfTheFarbogsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hound of the Farbogs"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Dog), nID, _T("4") BLACK_MANA_TEXT, Power(5), Life(3))
{
	// Delirium - This creature has menace as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+0), CreatureKeyword::CantBeBlockedBy1);
}

CIndulgentAristocratCard::CIndulgentAristocratCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Indulgent Aristocrat"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Noble), nID, BLACK_MANA_TEXT, Power(1), Life(1))
{
	GetCardKeyword()->AddLifelink(FALSE);

	// {2}, Sacrifice a creature: Put a +1/+1 counter on each Vampire you control.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2")));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIndulgentAristocratCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CIndulgentAristocratCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() &&
			((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Vampire))
			pModifier.ApplyTo(pCard);
	}
	return true;
}

CKindlyStrangerCard::CKindlyStrangerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Kindly Stranger"), CardType::Creature, CREATURE_TYPE(Human), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3), Power(4), Life(3), _T("Demon-Possessed Witch"))
{
	// Demon-Possessed Witch (second face): Human Shaman.
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Shaman, TRUE));

	{
		// Delirium - {2}{B}: Transform this creature. Activate only if there are four or more card types among cards in your graveyard.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLACK_MANA_TEXT));

		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
		AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
		AddTrait(cpAbility.GetPointer(), CPlayableIfTrait::PlayableCallback(this, &CKindlyStrangerCard::HasDeliriumNow));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this creature transforms into Demon-Possessed Witch, you may destroy target creature.
		// (as Huntmaster of the Fells in Dark Ascension)
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetTriggerIndex(TRANSFORM_TRIGGER_ID);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Destroy);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKindlyStrangerCard::SetTransformContext));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));

		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CKindlyStrangerCard::HasDeliriumNow(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

bool CKindlyStrangerCard::SetTransformContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext, CCard* pCard, int nId) const
{
	return GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced();
}

// Back face of Kindly Stranger
CDemonPossessedWitchCard::CDemonPossessedWitchCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Demon-Possessed Witch"), CardType::Creature, CREATURE_TYPE2(Human, Shaman), nID,
		_T(""), Power(4), Life(3), Power(2), Life(3), _T("Kindly Stranger"))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
}

CMarkovDreadknightCard::CMarkovDreadknightCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Markov Dreadknight"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Knight), nID, _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// {2}{B}, Discard a card: Put two +1/+1 counters on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") BLACK_MANA_TEXT));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +2));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CMindwrackDemonCard::CMindwrackDemonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Mindwrack Demon"), CardType::Creature,
		CREATURE_TYPE(Demon), nID, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(5))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	{
		// When this creature enters, mill four cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMindwrackDemonCard::BeforeMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of your upkeep, you lose 4 life unless there are four or more card types among cards in your graveyard.
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-4));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMindwrackDemonCard::SetUpkeepContext));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMindwrackDemonCard::BeforeMill(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 4);
	return true;
}

bool CMindwrackDemonCard::SetUpkeepContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !HasDelirium(GetController());
}

CMorkrutNecropodCard::CMorkrutNecropodCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Morkrut Necropod"), CardType::Creature,
		CREATURE_TYPE2(Slug, Horror), nID, _T("5") BLACK_MANA_TEXT, Power(7), Life(7))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CMorkrutNecropodCard::OnCardSelected))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace

	// Whenever this creature attacks or blocks, sacrifice another creature or land.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::EventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingOrBlockingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMorkrutNecropodCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	AddAbility(cpAbility.GetPointer());
}

bool CMorkrutNecropodCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard == this || !(pCard->GetCardType().IsCreature() || pCard->GetCardType().IsLand()))
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);

	return true;
}

void CMorkrutNecropodCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			return;
		}
}

COliviasBloodswornCard::COliviasBloodswornCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Olivia's Bloodsworn"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Soldier), nID, _T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	GetCreatureKeyword()->AddCantBlock(FALSE);

	// {R}: Target Vampire gains haste until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			RED_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::Haste, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	AddAbility(cpAbility.GetPointer());
}

CPaleRiderOfTrostadCard::CPaleRiderOfTrostadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pale Rider of Trostad"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("1") BLACK_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddSkulk(FALSE);

	// When this creature enters, discard a card.
	typedef
		TTriggeredAbility< CTriggeredDiscardCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDiscardCount(1);
	AddAbility(cpAbility.GetPointer());
}

CRancidRatsCard::CRancidRatsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rancid Rats"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Rat), nID, _T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	GetCreatureKeyword()->AddSkulk(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);
}

CRelentlessDeadCard::CRelentlessDeadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Relentless Dead"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace

	// When this creature dies, you may pay {B}. If you do, return it to its owner's hand.
	// Note: "When this creature dies, you may pay {X}. If you do, return another target Zombie creature card with mana
	// value X from your graveyard to the battlefield" is not implemented.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetResolutionCost(BLACK_MANA_TEXT);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRelentlessDeadCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
	AddAbility(cpAbility.GetPointer());
}

bool CRelentlessDeadCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(this);
	}
	return true;
}

CRottenheartGhoulCard::CRottenheartGhoulCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rottenheart Ghoul"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("3") BLACK_MANA_TEXT, Power(2), Life(4))
{
	// When this creature dies, target player discards a card.
	// Note: each opponent discards a card (the target player in a two-player game).
	typedef
		TTriggeredAbility< CTriggeredDiscardCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->SetDiscardCount(1);
	AddAbility(cpAbility.GetPointer());
}

CSanitariumSkeletonCard::CSanitariumSkeletonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sanitarium Skeleton"), CardType::Creature,
		CREATURE_TYPE(Skeleton), nID, BLACK_MANA_TEXT, Power(1), Life(2))
{
	// {2}{B}: Return this card from your graveyard to your hand.
	counted_ptr<CSelfMoveCardAbility> cpAbility(
		::CreateObject<CSelfMoveCardAbility>(this,
			_T("2") BLACK_MANA_TEXT,
			ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->SetGraveyardOnly();
	AddAbility(cpAbility.GetPointer());
}

CStallionOfAshmouthCard::CStallionOfAshmouthCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stallion of Ashmouth"), CardType::Creature,
		CREATURE_TYPE2(Nightmare, Horse), nID, _T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Delirium - {1}{B}: This creature gets +1/+1 until end of turn. Activate only if there are four or more card types
	// among cards in your graveyard.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("1") BLACK_MANA_TEXT, Power(+1), Life(+1)));

	AddTrait(cpAbility.GetPointer(), CPlayableIfTrait::PlayableCallback(this, &CStallionOfAshmouthCard::CanActivate));
	AddAbility(cpAbility.GetPointer());
}

BOOL CStallionOfAshmouthCard::CanActivate(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

CStromkirkMentorCard::CStromkirkMentorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stromkirk Mentor"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Soldier), nID, _T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// When this creature enters, put a +1/+1 counter on another target Vampire you control.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);

	AddAbility(cpAbility.GetPointer());
}

CToothCollectorCard::CToothCollectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tooth Collector"), CardType::Creature,
		CREATURE_TYPE2(Human, Rogue), nID, _T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	{
		// When this creature enters, target creature an opponent controls gets -1/-1 until end of turn.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetPowerModifier().SetPowerDelta(Power(-1));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of each opponent's upkeep, if there are four or more card types among cards in
		// your graveyard, target creature that player controls gets -1/-1 until end of turn.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetPowerModifier().SetPowerDelta(Power(-1));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CToothCollectorCard::SetUpkeepContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CToothCollectorCard::SetUpkeepContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasDelirium(GetController()) ? true : false;
}

CTwinsOfMaurerEstateCard::CTwinsOfMaurerEstateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Twins of Maurer Estate"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("4") BLACK_MANA_TEXT, Power(3), Life(5))
	, m_Madness(this)
{
	// Madness {2}{B}
	AddCreatureMadness(this, m_Madness, _T("2") BLACK_MANA_TEXT);
}

//____________________________________________________________________________
//
// Blue creatures

CAberrantResearcherCard::CAberrantResearcherCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Aberrant Researcher"), CardType::Creature, CREATURE_TYPE2(Human, Insect), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(2), Power(5), Life(4), _T("Perfected Form"))
{
	GetCreatureKeyword()->AddFlying(FALSE);

	// Perfected Form (second face): Insect Horror with flying.
	RemoveTypesOnSecondFace(this, SingleCreatureType::Human);
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, TRUE));

	// At the beginning of your upkeep, mill a card. If an instant or sorcery card was milled this way, transform this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAberrantResearcherCard::SetUpkeepContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAberrantResearcherCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));

	AddAbility(cpAbility.GetPointer());
}

bool CAberrantResearcherCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !GetOrientation()->IsSecondFaced();
}

bool CAberrantResearcherCard::BeforeResolution(CAbilityAction* pAction)
{
	CZone* pLibrary = pAction->GetController()->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);
	pModifier.ApplyTo(pCard);

	if ((pCard->GetCardType() & (CardType::Instant | CardType::Sorcery)).Any() &&
		GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced())
	{
		CFaceTransformModifier pTransformModifier;
		pTransformModifier.ApplyTo(this);
	}
	return true;
}

// Back face of Aberrant Researcher
CPerfectedFormCard::CPerfectedFormCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Perfected Form"), CardType::Creature, CREATURE_TYPE2(Insect, Horror), nID,
		_T(""), Power(5), Life(4), Power(3), Life(2), _T("Aberrant Researcher"))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
}

CDaringSleuthCard::CDaringSleuthCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Daring Sleuth"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1), Power(3), Life(2), _T("Bearer of Overwhelming Truths"))
{
	// Bearer of Overwhelming Truths (second face): Human Wizard.
	RemoveTypesOnSecondFace(this, SingleCreatureType::Rogue);
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Wizard, TRUE));

	{
		// When you sacrifice a Clue, transform this creature. (first face)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDaringSleuthCard::SetClueContext));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Prowess (second face) (as Jeskai Windscout)
		typedef
			TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
		cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDaringSleuthCard::SetProwessContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature deals combat damage to a player, investigate. (second face)
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDaringSleuthCard::SetDamageContext));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CDaringSleuthCard::SetClueContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
									   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced() && IsClueSacrificed(pCard, moveType);
}

bool CDaringSleuthCard::SetProwessContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	return GetOrientation()->IsSecondFaced() ? true : false;
}

bool CDaringSleuthCard::SetDamageContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	return GetOrientation()->IsSecondFaced() ? true : false;
}

// Back face of Daring Sleuth
CBearerOfOverwhelmingTruthsCard::CBearerOfOverwhelmingTruthsCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Bearer of Overwhelming Truths"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T(""), Power(3), Life(2), Power(2), Life(1), _T("Daring Sleuth"))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
}

CDrownyardExplorersCard::CDrownyardExplorersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Drownyard Explorers"), CardType::Creature,
		CREATURE_TYPE2(Human, Wizard), nID, _T("3") BLUE_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, investigate.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CDrunauCorpseTrawlerCard::CDrunauCorpseTrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Drunau Corpse Trawler"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("3") BLUE_MANA_TEXT, Power(1), Life(1))
{
	{
		// When this creature enters, create a 2/2 black Zombie creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Zombie (P)"), 55009, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{B}: Target Zombie gains deathtouch until end of turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T("2") BLACK_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::Null, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));

		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::Deathtouch);
		pModifier->GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(pModifier);

		AddAbility(cpAbility.GetPointer());
	}
}

CForgottenCreationCard::CForgottenCreationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forgotten Creation"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("3") BLUE_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddSkulk(FALSE);

	// At the beginning of your upkeep, you may discard all the cards in your hand. If you do, draw that many cards.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CForgottenCreationCard::BeforeResolution));

	AddAbility(cpAbility.GetPointer());
}

bool CForgottenCreationCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Chandra, Flamecaller's 0 ability in Oath of the Gatewatch)
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

	int nCount = pHand->GetSize();
	if (nCount == 0)
		return true;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	while (pHand->GetSize() > 0)
		pModifier.ApplyTo(pHand->GetAt(pHand->GetSize() - 1));

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(nCount), MaximumValue(nCount));
	pDrawModifier.ApplyTo(pController);
	return true;
}

CFurtiveHomunculusCard::CFurtiveHomunculusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Furtive Homunculus"), CardType::Creature,
		CREATURE_TYPE(Homunculus), nID, _T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	GetCreatureKeyword()->AddSkulk(FALSE);
}

CGeralfsMasterpieceCard::CGeralfsMasterpieceCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Geralf's Masterpiece"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(7), Life(7))
{
	{
		// This creature gets -1/-1 for each card in your hand. (as Vile Aggregate, with a negative multiplier)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Hand,
				new TrueCardComparer));

		cpAbility->SetPowerMultiplier(Power(-1));
		cpAbility->SetToughnessMultiplier(Life(-1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{U}, Discard three cards: Return this card from your graveyard to the battlefield tapped. (as Ghoulsteed)
		counted_ptr<CSelfMoveCardAbility> cpAbility(
			::CreateObject<CSelfMoveCardAbility>(this,
				_T("3") BLUE_MANA_TEXT,
				ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->SetGraveyardOnly();
		cpAbility->GetCost().AddDiscardCardCost(3, CCardFilter::GetFilter(_T("cards")));
		cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		AddAbility(cpAbility.GetPointer());
	}
}

CLamplighterOfSelhoffCard::CLamplighterOfSelhoffCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lamplighter of Selhoff"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("4") BLUE_MANA_TEXT, Power(3), Life(5))
{
	// When this creature enters, if you control another Zombie, you may draw a card. If you do, discard a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetDrawCount(1);
	cpAbility->SetDiscard(1, FALSE, MoveType::Discard);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLamplighterOfSelhoffCard::SetTriggerContext));

	AddAbility(cpAbility.GetPointer());
}

bool CLamplighterOfSelhoffCard::SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext,
												  CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	CCardFilter zombieFilter(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	zombieFilter.AddNegateComparer(new SpecificCardComparer(this));
	return zombieFilter.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

CManicScribeCard::CManicScribeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Manic Scribe"), CardType::Creature,
		CREATURE_TYPE2(Human, Wizard), nID, _T("1") BLUE_MANA_TEXT, Power(0), Life(3))
{
	{
		// When this creature enters, each opponent mills three cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CManicScribeCard::BeforeEnterMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of each opponent's upkeep, if there are four or more card types among cards in
		// your graveyard, that player mills three cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CManicScribeCard::SetUpkeepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CManicScribeCard::BeforeUpkeepMill));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CManicScribeCard::BeforeEnterMill(CAbilityAction* pAction) const
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		if (GetGame()->GetPlayer(i) != pAction->GetController())
			Mill(GetGame()->GetPlayer(i), 3);
	return true;
}

bool CManicScribeCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasDelirium(GetController()) ? true : false;
}

bool CManicScribeCard::BeforeUpkeepMill(CAbilityAction* pAction) const
{
	CPlayer* pPlayer = GetGame()->GetActivePlayer();
	if (pPlayer && pPlayer != pAction->GetController())
		Mill(pPlayer, 3);
	return true;
}

CNephaliaMoondrakesCard::CNephaliaMoondrakesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Nephalia Moondrakes"), CardType::Creature,
		CREATURE_TYPE(Drake), nID, _T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(5))
{
	{
		// When this creature enters, target creature gains flying until end of turn.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Flying);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{U}{U}, Exile this card from your graveyard: Creatures you control gain flying until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT));

		cpAbility->SetGraveyardOnly();
		cpAbility->AddExileCost();
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CZoneCreatureModifier(ZoneId::Battlefield, CCardFilter::GetFilter(_T("creatures")),
				std::auto_ptr<CCreatureModifier>(new CCreatureKeywordModifier(CreatureKeyword::Flying, TRUE))));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

CRattlechainsCard::CRattlechainsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Rattlechains"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, target Spirit gains hexproof until end of turn.
	// Note: "You may cast Spirit spells as though they had flash" is not implemented.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Spirit), false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CStitchedManglerCard::CStitchedManglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stitched Mangler"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
	// This creature enters tapped.
	SetIntoPlayTapped();

	// When this creature enters, tap target creature an opponent controls. That creature doesn't untap during its
	// controller's next untap step. (as Topplegeist and Rush of Ice)
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().push_back(new CCardOrientationModifier(TRUE));

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->GetCardModifiers().push_back(pModifier);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

	AddAbility(cpAbility.GetPointer());
}

CStitchwingSkaabCard::CStitchwingSkaabCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Stitchwing Skaab"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("3") BLUE_MANA_TEXT, Power(3), Life(1))
{
	// {1}{U}, Discard two cards: Return this card from your graveyard to the battlefield tapped. (as Ghoulsteed)
	counted_ptr<CSelfMoveCardAbility> cpAbility(
		::CreateObject<CSelfMoveCardAbility>(this,
			_T("1") BLUE_MANA_TEXT,
			ZoneId::Battlefield, FALSE, MoveType::Others));

	cpAbility->SetGraveyardOnly();
	cpAbility->GetCost().AddDiscardCardCost(2, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddAbility(cpAbility.GetPointer());
}

CStormriderSpiritCard::CStormriderSpiritCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Stormrider Spirit"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("4") BLUE_MANA_TEXT, Power(3), Life(3))
{
	GetCardKeyword()->AddFlash(FALSE);
}

CThingInTheIceCard::CThingInTheIceCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Thing in the Ice"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		_T("1") BLUE_MANA_TEXT, Power(0), Life(4), Power(7), Life(8), _T("Awoken Horror"))
{
	// Defender. This creature enters with four ice counters on it. (as Coldsnap's ice counters)
	GetCreatureKeyword()->AddDefender(FALSE);
	GetCounterContainer()->ScheduleCounter(ICE_COUNTER, 4, false, ZoneId::_AllZones, ZoneId::Battlefield, false);

	// Awoken Horror (second face): Kraken Horror 7/8 without defender.
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Kraken, TRUE));
	SetSecondFaceKeywords(this, CreatureKeyword::Null, CreatureKeyword::Defender);

	{
		// Whenever you cast an instant or sorcery spell, remove an ice counter from this creature. Then if it has no
		// ice counters on it, transform it.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThingInTheIceCard::BeforeRemoveCounter));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this creature transforms into Awoken Horror, return all non-Horror creatures to their owners' hands.
		// (as Huntmaster of the Fells in Dark Ascension)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetTriggerIndex(TRANSFORM_TRIGGER_ID);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CThingInTheIceCard::SetTransformContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThingInTheIceCard::BeforeBounce));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Hand));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CThingInTheIceCard::BeforeRemoveCounter(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	if (GetCounterContainer()->GetCounter(ICE_COUNTER)->GetCount() > 0)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(ICE_COUNTER, -1);
		pModifier.ApplyTo(this);
	}

	if (GetCounterContainer()->GetCounter(ICE_COUNTER)->GetCount() == 0 && !GetOrientation()->IsSecondFaced())
	{
		CFaceTransformModifier pTransformModifier;
		pTransformModifier.ApplyTo(this);
	}
	return true;
}

bool CThingInTheIceCard::SetTransformContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, int nId) const
{
	return GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced();
}

bool CThingInTheIceCard::BeforeBounce(CAbilityAction* pAction) const
{
	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() &&
				!((CCreatureCard*)pCard)->GetCreatureType().HasType(SingleCreatureType::Horror))
				pCreatures.AddCard(pCard, CardPlacement::Top);
		}
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pModifier.ApplyTo(pCreatures.GetAt(i));

	return true;
}

// Back face of Thing in the Ice
CAwokenHorrorCard::CAwokenHorrorCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Awoken Horror"), CardType::Creature, CREATURE_TYPE2(Kraken, Horror), nID,
		_T(""), Power(7), Life(8), Power(0), Life(4), _T("Thing in the Ice"))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
}

CUninvitedGeistCard::CUninvitedGeistCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Uninvited Geist"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2), Power(3), Life(3), _T("Unimpeded Trespasser"))
{
	GetCreatureKeyword()->AddSkulk(FALSE);

	// Unimpeded Trespasser (second face): can't be blocked (instead of skulk).
	SetSecondFaceKeywords(this, CreatureKeyword::Unblockable, CreatureKeyword::Skulk);

	// When this creature deals combat damage to a player, transform it. (first face)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUninvitedGeistCard::SetDamageContext));

	AddAbility(cpAbility.GetPointer());
}

bool CUninvitedGeistCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	return !GetOrientation()->IsSecondFaced();
}

// Back face of Uninvited Geist
CUnimpededTrespasserCard::CUnimpededTrespasserCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Unimpeded Trespasser"), CardType::Creature, CREATURE_TYPE(Spirit), nID,
		_T(""), Power(3), Life(3), Power(2), Life(2), _T("Uninvited Geist"))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

//____________________________________________________________________________
//
// Multicolored creatures

COliviaMobilizedForWarCard::COliviaMobilizedForWarCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Olivia, Mobilized for War"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Vampire, Knight), nID, _T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// Whenever another creature you control enters, you may discard a card. If you do, put a +1/+1 counter on that
	// creature, it gains haste until end of turn, and it becomes a Vampire in addition to its other types.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDiscardResolutionCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COliviaMobilizedForWarCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &COliviaMobilizedForWarCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool COliviaMobilizedForWarCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
												   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_pCard = pCard;
	return true;
}

bool COliviaMobilizedForWarCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const
{
	// The +1/+1 counter is put by the ability; the haste and the Vampire type are given here
	CCard* pCard = pAction->GetTriggerContext().m_pCard;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	CCreatureKeywordModifier pHasteModifier;
	pHasteModifier.GetModifier().SetToAdd(CreatureKeyword::Haste);
	pHasteModifier.GetModifier().SetOneTurnOnly(TRUE);
	pHasteModifier.ApplyTo((CCreatureCard*)pCard);

	CCreatureTypeModifier pTypeModifier = CCreatureTypeModifier(SingleCreatureType::Vampire, TRUE);
	pTypeModifier.ApplyTo((CCreatureCard*)pCard);

	return true;
}

CSigardaHeronsGraceCard::CSigardaHeronsGraceCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sigarda, Heron's Grace"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Angel), nID, _T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(5))
{
	{
		// You have hexproof. (as Leyline of Sanctity)
		PlayerEffectType effects[] = { PlayerEffectType::CantBeTargetedByOpponentsSpells, PlayerEffectType::CantBeTargetedByOpponentsAbilities };
		for (int i = 0; i < 2; ++i)
		{
			counted_ptr<CPlayerEffectEnchantment> cpAbility(
				::CreateObject<CPlayerEffectEnchantment>(this, effects[i]));

			cpAbility->SetAffectControllerOnly();
			AddAbility(cpAbility.GetPointer());
		}
	}
	{
		// Humans you control have hexproof.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Human), false),
				Power(+0), Life(+0)));

		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, Exile a card from your graveyard: Create a 1/1 white Human Soldier creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2"),
				_T("Human Soldier (A)"), 55075,
				1));

		cpAbility->GetCost().AddExileGraveyardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		AddAbility(cpAbility.GetPointer());
	}
}

CTheGitrogMonsterCard::CTheGitrogMonsterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("The Gitrog Monster"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Frog, Horror), nID, _T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
	, m_SacrificeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTheGitrogMonsterCard::OnSacrificeSelected))
{
	GetCardKeyword()->AddDeathtouch(FALSE);

	{
		// At the beginning of your upkeep, sacrifice The Gitrog Monster unless you sacrifice a land.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheGitrogMonsterCard::BeforeUpkeep));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// You may play an additional land on each of your turns.
		counted_ptr<CPlayExtraLandEnchantment> cpAbility(
			::CreateObject<CPlayExtraLandEnchantment>(this, +1));

		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever one or more land cards are put into your graveyard from anywhere, draw a card.
		// Note: a card is drawn for each land card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(1);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CTheGitrogMonsterCard::BeforeUpkeep(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	// Choose a land to sacrifice, or sacrifice The Gitrog Monster
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}
	{
		SelectionEntry entry;

		entry.dwContext = (DWORD)this;
		entry.cpAssociatedCard = this;
		entry.strText.Format(_T("Sacrifice %s"), GetCardName(TRUE));

		entries.push_back(entry);
	}

	m_SacrificeSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CTheGitrogMonsterCard::OnSacrificeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Battlefield)
				return;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
			return;
		}
}

//____________________________________________________________________________
//
