#include "stdafx.h"
#include "CardBattleForZendikar.h"

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

		// Add new card class names here:
		// For example:
		// 	DEFINE_CARD(CDefenderEnVecCard);
		DEFINE_CARD(CBlisterpodCard);
		DEFINE_CARD(CBroodMonitorCard);
		DEFINE_CARD(CBroodhunterWurmCard);
		DEFINE_CARD(CCallTheScionsCard);
		DEFINE_CARD(CChasmGuideCard);
		DEFINE_CARD(CClutchOfCurrentsCard);
		DEFINE_CARD(CCloudMantaCard);
		DEFINE_CARD(CCullingDroneCard);
		DEFINE_CARD(CCoastalDiscoveryCard);
		DEFINE_CARD(CEarthenArmsCard);
		DEFINE_CARD(CEldraziSkyspawnerCard);
		DEFINE_CARD(CEyelessWatcherCard);
		DEFINE_CARD(CExpeditionEnvoyCard);
		DEFINE_CARD(CFiremantleMageCard);
		DEFINE_CARD(CFortifiedRampartCard);
		DEFINE_CARD(CGhostlySentinelCard);
		DEFINE_CARD(CKitesailScoutCard);
		DEFINE_CARD(CMistIntruderCard);
		DEFINE_CARD(CPlanarOutburstCard);
		DEFINE_CARD(CRuinousPathCard);
		DEFINE_CARD(CRisingMiasmaCard);
		DEFINE_CARD(CSheerDropCard);
		DEFINE_CARD(CBoilingEarthCard);
		DEFINE_CARD(CShadowGliderCard);
		DEFINE_CARD(CEncirclingFissureCard);
		DEFINE_CARD(COnduRisingCard);
		DEFINE_CARD(CPartTheWaterveilCard);
		DEFINE_CARD(CRushOfIceCard);
		DEFINE_CARD(CScatterToTheWindsCard);
		DEFINE_CARD(CMiresMaliceCard);
		DEFINE_CARD(CRoilSpoutCard);
		DEFINE_CARD(CGrovetenderDruidsCard);
		DEFINE_CARD(CHeroOfGomaFadaCard);
		DEFINE_CARD(CKalastriaHealerCard);
		DEFINE_CARD(CKorBladewhirlCard);
		DEFINE_CARD(CKorEntanglersCard);
		DEFINE_CARD(CLanternScoutCard);
		DEFINE_CARD(CMakindiPatrolCard);
		DEFINE_CARD(COnduChampionCard);
		DEFINE_CARD(CResoluteBlademasterCard);
		DEFINE_CARD(CTajuruBeastmasterCard);
		DEFINE_CARD(CTajuruWarcallerCard);
		DEFINE_CARD(CCanopyVistaCard);
		DEFINE_CARD(CCinderGladeCard);
		DEFINE_CARD(CPrairieStreamCard);
		DEFINE_CARD(CSmolderingMarshCard);
		DEFINE_CARD(CSunkenHollowCard);
		DEFINE_CARD(CBlightedCataractCard);
		DEFINE_CARD(CBlightedFenCard);
		DEFINE_CARD(CBlightedGorgeCard);
		DEFINE_CARD(CBlightedSteppeCard);
		DEFINE_CARD(CBlightedWoodlandCard);
		DEFINE_CARD(CLoomingSpiresCard);
		DEFINE_CARD(CLumberingFallsCard);
		DEFINE_CARD(CMortuaryMireCard);
		DEFINE_CARD(CSandstoneBridgeCard);
		DEFINE_CARD(CShamblingVentCard);
		DEFINE_CARD(CSkylineCascadeCard);
		DEFINE_CARD(CSpawningBedCard);
		DEFINE_CARD(CGideonAllyOfZendikarCard);
		DEFINE_CARD(CObNixilisReignitedCard);
		DEFINE_CARD(CAlignedHedronNetworkCard);
		DEFINE_CARD(CHedronArchiveCard);
		DEFINE_CARD(CHedronBladeCard);
		DEFINE_CARD(CPathwayArrowsCard);
		DEFINE_CARD(CAngelicGiftCard);
		DEFINE_CARD(CDampeningPulseCard);
		DEFINE_CARD(CTighteningCoilsCard);
		DEFINE_CARD(CVampiricRitesCard);
		DEFINE_CARD(CMoltenNurseryCard);
		DEFINE_CARD(CFromBeyondCard);
		DEFINE_CARD(CStasisSnareCard);
		DEFINE_CARD(CQuarantineFieldCard);
		DEFINE_CARD(CRetreatToCoralhelmCard);
		DEFINE_CARD(CRetreatToEmeriaCard);
		DEFINE_CARD(CRetreatToHagraCard);
		DEFINE_CARD(CRetreatToKazanduCard);
		DEFINE_CARD(CRetreatToValakutCard);
		DEFINE_CARD(CCrumbleToDustCard);
		DEFINE_CARD(CDemonsGraspCard);
		DEFINE_CARD(CReclaimingVinesCard);
		DEFINE_CARD(CNissasRenewalCard);
		DEFINE_CARD(CTouchOfTheVoidCard);
		DEFINE_CARD(CSeekTheWildsCard);
		DEFINE_CARD(CTransgressTheMindCard);
		DEFINE_CARD(CSwarmSurgeCard);
		DEFINE_CARD(CUginsInsightCard);
		DEFINE_CARD(CMarchFromTheTombCard);
		DEFINE_CARD(CAdverseConditionsCard);
		DEFINE_CARD(CAnticipateCard);
		DEFINE_CARD(CCompleteDisregardCard);
		DEFINE_CARD(CGideonsReproachCard);
		DEFINE_CARD(CGraveBirthingCard);
		DEFINE_CARD(CGripOfDesolationCard);
		DEFINE_CARD(CHorriblyAwryCard);
		DEFINE_CARD(CNaturalConnectionCard);
		DEFINE_CARD(COutnumberCard);
		DEFINE_CARD(CRoilsRetributionCard);
		DEFINE_CARD(CScourFromExistenceCard);
		DEFINE_CARD(CSpellShrivelCard);
		DEFINE_CARD(CStonefuryCard);
		DEFINE_CARD(CSureStrikeCard);
		DEFINE_CARD(CSwellOfGrowthCard);
		DEFINE_CARD(CTandemTacticsCard);
		DEFINE_CARD(CTurnAgainstCard);
		DEFINE_CARD(CUnnaturalAggressionCard);
		DEFINE_CARD(CVolcanicUpheavalCard);
		DEFINE_CARD(CBaneOfBalaGedCard);
		DEFINE_CARD(CBarrageTyrantCard);
		DEFINE_CARD(CBenthicInfiltratorCard);
		DEFINE_CARD(CBreakerOfArmiesCard);
		DEFINE_CARD(CBroodButcherCard);
		DEFINE_CARD(CCatacombSifterCard);
		DEFINE_CARD(CDesolationTwinCard);
		DEFINE_CARD(CDominatorDroneCard);
		DEFINE_CARD(CDrownerOfHopeCard);
		DEFINE_CARD(CDustStalkerCard);
		DEFINE_CARD(CEldraziDevastatorCard);
		DEFINE_CARD(CEndlessOneCard);
		DEFINE_CARD(CFathomFeederCard);
		DEFINE_CARD(CForerunnerOfSlaughterCard);
		DEFINE_CARD(CIncubatorDroneCard);
		DEFINE_CARD(CKozileksChannelerCard);
		DEFINE_CARD(CKozileksSentinelCard);
		DEFINE_CARD(CNettleDroneCard);
		DEFINE_CARD(CRuinationGuideCard);
		DEFINE_CARD(CSalvageDroneCard);
		DEFINE_CARD(CSilentSkimmerCard);
		DEFINE_CARD(CSireOfStagnationCard);
		DEFINE_CARD(CSludgeCrawlerCard);
		DEFINE_CARD(CTideDrifterCard);
		DEFINE_CARD(CUlamogTheCeaselessHungerCard);
		DEFINE_CARD(CVestigeOfEmrakulCard);
		DEFINE_CARD(CVileAggregateCard);
		DEFINE_CARD(CProcessorAssaultCard);
		DEFINE_CARD(CCrypticCruiserCard);
		DEFINE_CARD(COracleOfDustCard);
		DEFINE_CARD(CVoidAttendantCard);
		DEFINE_CARD(CBlightHerderCard);
		DEFINE_CARD(CRuinProcessorCard);
		DEFINE_CARD(CMindRakerCard);
		DEFINE_CARD(CMurkStriderCard);
		DEFINE_CARD(CUlamogsReclaimerCard);
		DEFINE_CARD(CWastelandStranglerCard);
		DEFINE_CARD(CUlamogsDespoilerCard);
		DEFINE_CARD(CUlamogsNullifierCard);
		DEFINE_CARD(CBelligerentWhiptailCard);
		DEFINE_CARD(CGeyserfieldStalkerCard);
		DEFINE_CARD(CGroveRumblerCard);
		DEFINE_CARD(CMakindiSliderunnerCard);
		DEFINE_CARD(COnduGreathornCard);
		DEFINE_CARD(CScytheLeopardCard);
		DEFINE_CARD(CSnappingGnarlidCard);
		DEFINE_CARD(CValakutPredatorCard);
		DEFINE_CARD(CWaveWingElementalCard);
		DEFINE_CARD(CAkoumStonewakerCard);
		DEFINE_CARD(CCarrierThrallCard);
		DEFINE_CARD(CCourierGriffinCard);
		DEFINE_CARD(CFelidarCubCard);
		DEFINE_CARD(CJaddiOffshootCard);
		DEFINE_CARD(CLavastepRaiderCard);
		DEFINE_CARD(CLifespringDruidCard);
		DEFINE_CARD(CMurasaRangerCard);
		DEFINE_CARD(COranRiefInvokerCard);
		DEFINE_CARD(CPlatedCrusherCard);
		DEFINE_CARD(CRotShamblerCard);
		DEFINE_CARD(CStoneHavenMedicCard);
		DEFINE_CARD(CTunnelingGeopedeCard);
		DEFINE_CARD(CValakutInvokerCard);
		DEFINE_CARD(CVoraciousNullCard);
		DEFINE_CARD(CAkoumHellkiteCard);
		DEFINE_CARD(CGuardianOfTazeemCard);
		DEFINE_CARD(CGuulDrazOverseerCard);
		DEFINE_CARD(COranRiefHydraCard);
		DEFINE_CARD(COmnathLocusOfRageCard);
		DEFINE_CARD(CDefiantBloodlordCard);
		DEFINE_CARD(CMalakirFamiliarCard);
		DEFINE_CARD(CGreenwardenOfMurasaCard);
		DEFINE_CARD(CWindriderPatrolCard);
		DEFINE_CARD(CAngelicCaptainCard);
		DEFINE_CARD(CAngelOfRenewalCard);
		DEFINE_CARD(CBloodbondVampireCard);
		DEFINE_CARD(CCliffsideLookoutCard);
		DEFINE_CARD(CCoralhelmGuideCard);
		DEFINE_CARD(CDranaLiberatorOfMalakirCard);
		DEFINE_CARD(CDranasEmissaryCard);
		DEFINE_CARD(CHagraSharpshooterCard);
		DEFINE_CARD(CHalimarTidecallerCard);
		DEFINE_CARD(CKalastriaNightwatchCard);
		DEFINE_CARD(CKorCastigatorCard);
		DEFINE_CARD(CNirkanaAssassinCard);
		DEFINE_CARD(CRecklessCohortCard);
		DEFINE_CARD(CSereneStewardCard);
		DEFINE_CARD(CShatterskullRecruitCard);
		DEFINE_CARD(CVeteranWarleaderCard);
		DEFINE_CARD(CZulaportCutthroatCard);

	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
// Rally - Whenever this creature or another Ally you control enters the battlefield, ...
// Creates the triggered ability with the Rally trigger; the caller sets the effect and adds it.
template <class TriggeredAbility>
static counted_ptr<TriggeredAbility> CreateRallyAbility(CCard* pCard)
{
	counted_ptr<TriggeredAbility> cpAbility(
		::CreateObject<TriggeredAbility>(pCard, ZoneId::_AllZones, ZoneId::Battlefield));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new CreatureTypeComparer(CREATURE_TYPE(Ally), false));
	return cpAbility;
}

// Rally effect: creatures you control get +X/+X or gain a card keyword until end of turn
typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenCardMoved> RallyModifyCreaturesAbility;

static counted_ptr<RallyModifyCreaturesAbility> CreateRallyModifyCreaturesAbility(CCard* pCard)
{
	counted_ptr<RallyModifyCreaturesAbility> cpAbility(CreateRallyAbility<RallyModifyCreaturesAbility>(pCard));
	cpAbility->SetModifyCreatureOption(
		CTriggeredModifyCreatureAbility::ModifyCreatureOption::ModifyTriggeredPlayersCreatures);
	cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	return cpAbility;
}

//____________________________________________________________________________
//
// Add new card class definitions here

CBlisterpodCard::CBlisterpodCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blisterpod"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, GREEN_MANA_TEXT, Power(1), Life(1))
{
	SetDevoid();
	typedef TTriggeredAbility<CTriggeredCreateTokenAbility, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Scion (A)"), 55056, 1);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CBroodMonitorCard::CBroodMonitorCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Brood Monitor"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT,
		Power(3), Life(3), 3)
{
	SetDevoid();
}

CBroodhunterWurmCard::CBroodhunterWurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Broodhunter Wurm"), CardType::Creature,
		CREATURE_TYPE(Wurm), nID, _T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
}

CCallTheScionsCard::CCallTheScionsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Call the Scions"), CardType::Sorcery, nID)
{
	SetDevoid();
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("2") GREEN_MANA_TEXT,
			_T("Eldrazi Scion (A)"), 55056, 2));
	AddSpell(cpSpell.GetPointer());
}

CChasmGuideCard::CChasmGuideCard(CGame* pGame, UINT nID)
	: CRallyCreatureCard(pGame, _T("Chasm Guide"), CardType::Creature,
		CREATURE_TYPE3(Goblin, Scout, Ally), nID, _T("3") RED_MANA_TEXT,
		Power(3), Life(2), CreatureKeyword::Haste)
{
}

CClutchOfCurrentsCard::CClutchOfCurrentsCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Clutch of Currents"), CardType::Sorcery, nID,
		BLUE_MANA_TEXT, AbilityType::Sorcery, new AnyCreatureComparer,
		ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others)
{
	counted_ptr<CAwakenSpell> cpSpell(
		::CreateObject<CAwakenSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT, new AnyCreatureComparer, ZoneId::Battlefield, 3,
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others)));
	AddSpell(cpSpell.GetPointer());
}

CCoastalDiscoveryCard::CCoastalDiscoveryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Coastal Discovery"), CardType::Sorcery, nID)
{
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT, 2));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenLandSpell> cpAwakenSpell(
		::CreateObject<CAwakenLandSpell>(this, AbilityType::Sorcery,
			_T("5") BLUE_MANA_TEXT, 4));
	cpAwakenSpell->GetControllerModifiers().Add(
		new CDrawCardModifier(GetGame(), MinimumValue(2), MaximumValue(2)));
	AddSpell(cpAwakenSpell.GetPointer());
}

CCloudMantaCard::CCloudMantaCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cloud Manta"), CardType::Creature,
		CREATURE_TYPE(Fish), nID, _T("3") BLUE_MANA_TEXT, Power(3), Life(2))
{
}

CEarthenArmsCard::CEarthenArmsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Earthen Arms"), CardType::Sorcery, nID)
{
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") GREEN_MANA_TEXT, new TrueCardComparer, FALSE));
	cpSpell->GetTargeting()->SetSubjectZoneId(ZoneId::Battlefield);
	cpSpell->GetTargetModifier().CCardModifiers::Add(new CCardCounterModifier(_T("+1/+1"), 2));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenSpell> cpAwakenSpell(
		::CreateObject<CAwakenSpell>(this, AbilityType::Sorcery,
			_T("6") GREEN_MANA_TEXT, new TrueCardComparer, ZoneId::Battlefield, 4,
			new CCardCounterModifier(_T("+1/+1"), 2)));
	AddSpell(cpAwakenSpell.GetPointer());
}

CPlanarOutburstCard::CPlanarOutburstCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Planar Outburst"), CardType::Sorcery, nID)
{
	counted_ptr<CGlobalMoveCardSpell> cpSpell(
		::CreateObject<CGlobalMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT,
			new AnyCreatureComparer, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	cpSpell->GetGlobalCardFilter().AddNegateComparer(
		new CardTypeComparer(CardType::_Land, false));
	cpSpell->GetGlobalCardFilter().AddNegateComparer(
		new AlsoCardTypeComparer(CardType::_Land, false));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenLandSpell> cpAwakenSpell(
		::CreateObject<CAwakenLandSpell>(this, AbilityType::Sorcery,
			_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT,
			4, new AnyCreatureComparer));
	cpAwakenSpell->GetGlobalCardFilter().AddNegateComparer(
		new CardTypeComparer(CardType::_Land, false));
	cpAwakenSpell->GetGlobalCardFilter().AddNegateComparer(
		new AlsoCardTypeComparer(CardType::_Land, false));
	cpAwakenSpell->GetGlobalCardModifiers().Add(
		new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));
	AddSpell(cpAwakenSpell.GetPointer());
}

CCullingDroneCard::CCullingDroneCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Culling Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLACK_MANA_TEXT,
		Power(2), Life(2))
{
	SetDevoid();
}

CEldraziSkyspawnerCard::CEldraziSkyspawnerCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Eldrazi Skyspawner"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") BLUE_MANA_TEXT,
		Power(2), Life(1), 1)
{
	SetDevoid();
	GetCreatureKeyword()->AddFlying(FALSE);
}

CEyelessWatcherCard::CEyelessWatcherCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Eyeless Watcher"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") GREEN_MANA_TEXT,
		Power(1), Life(1), 2)
{
	SetDevoid();
}

CExpeditionEnvoyCard::CExpeditionEnvoyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Expedition Envoy"), CardType::Creature,
		CREATURE_TYPE3(Human, Scout, Ally), nID,
		WHITE_MANA_TEXT, Power(2), Life(1))
{
}

CFiremantleMageCard::CFiremantleMageCard(CGame* pGame, UINT nID)
	: CRallyCreatureCard(pGame, _T("Firemantle Mage"), CardType::Creature,
		CREATURE_TYPE3(Human, Shaman, Ally), nID, _T("2") RED_MANA_TEXT,
		Power(2), Life(2), CreatureKeyword::CantBeBlockedBy1) //Menace
{
}

CFortifiedRampartCard::CFortifiedRampartCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fortified Rampart"), CardType::Creature,
		CREATURE_TYPE(Wall), nID, _T("1") WHITE_MANA_TEXT, Power(0), Life(6))
{
	GetCreatureKeyword()->AddDefender(FALSE);
}

CGhostlySentinelCard::CGhostlySentinelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Ghostly Sentinel"), CardType::Creature,
		CREATURE_TYPE2(Kor, Spirit), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CKitesailScoutCard::CKitesailScoutCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Kitesail Scout"), CardType::Creature,
		CREATURE_TYPE2(Kor, Scout), nID, WHITE_MANA_TEXT, Power(1), Life(1))
{
}

CMistIntruderCard::CMistIntruderCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Mist Intruder"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLUE_MANA_TEXT,
		Power(1), Life(2))
{
	SetDevoid();
	GetCreatureKeyword()->AddFlying(FALSE);
}

CRisingMiasmaCard::CRisingMiasmaCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rising Miasma"), CardType::Sorcery, nID)
{
	counted_ptr<CGlobalChgPwrTghSpell> cpSpell(
		::CreateObject<CGlobalChgPwrTghSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT,
			Power(-2), Life(-2),
			new AnyCreatureComparer));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenLandSpell> cpAwakenSpell(
		::CreateObject<CAwakenLandSpell>(this, AbilityType::Sorcery,
			_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			3, new AnyCreatureComparer));
	cpAwakenSpell->GetGlobalCreatureModifiers().Add(new CPowerModifier(Power(-2), TRUE));
	cpAwakenSpell->GetGlobalCreatureModifiers().Add(new CLifeModifier(Life(-2), this,
		PreventableType::NotPreventable, DamageType::NotDealingDamage, TRUE));
	AddSpell(cpAwakenSpell.GetPointer());
}

CRuinousPathCard::CRuinousPathCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Ruinous Path"), CardType::Sorcery, nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false),
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	counted_ptr<CAwakenSpell> cpSpell(
		::CreateObject<CAwakenSpell>(this, AbilityType::Sorcery,
			_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false),
			ZoneId::Battlefield, 4,
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)));
	AddSpell(cpSpell.GetPointer());
}

CSheerDropCard::CSheerDropCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Sheer Drop"), CardType::Sorcery, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Sorcery,
		new AnyCreatureComparer, ZoneId::Battlefield, ZoneId::Graveyard,
		TRUE, MoveType::Destroy)
{
	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);

	counted_ptr<CAwakenSpell> cpSpell(
		::CreateObject<CAwakenSpell>(this, AbilityType::Sorcery,
			_T("5") WHITE_MANA_TEXT, new AnyCreatureComparer,
			ZoneId::Battlefield, 3,
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy),
			new TappedComparer));
	AddSpell(cpSpell.GetPointer());
}

CBoilingEarthCard::CBoilingEarthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Boiling Earth"), CardType::Sorcery, nID)
{
	counted_ptr<CGlobalChgLifeSpell> cpSpell(
		::CreateObject<CGlobalChgLifeSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT,
			Life(-1), new AnyCreatureComparer, FALSE,
			PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage));
	cpSpell->SetAffectOpponentCardsOnly();
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenLandSpell> cpAwakenSpell(
		::CreateObject<CAwakenLandSpell>(this, AbilityType::Sorcery,
			_T("6") RED_MANA_TEXT, 4, new AnyCreatureComparer));
	cpAwakenSpell->SetAffectOpponentCardsOnly();
	cpAwakenSpell->GetGlobalCreatureModifiers().Add(new CLifeModifier(Life(-1), this,
		PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage, TRUE));
	AddSpell(cpAwakenSpell.GetPointer());
}

CShadowGliderCard::CShadowGliderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Shadow Glider"), CardType::Creature,
		CREATURE_TYPE2(Kor, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
}

CEncirclingFissureCard::CEncirclingFissureCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Encircling Fissure"), CardType::Instant, nID)
{
	// Note: covers the creatures that player controls at resolution; creatures entering later this turn are not affected
	counted_ptr<CTargetPlayerCardsSpell> cpSpell(
		::CreateObject<CTargetPlayerCardsSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			ZoneId::Battlefield,
			CCardFilter::GetFilter(_T("creatures"))));
	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->AddCreatureModifier(new CCreatureKeywordModifier(CreatureKeyword::DealNoCombatDamage, TRUE, TRUE));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenTargetPlayerSpell> cpAwakenSpell(
		::CreateObject<CAwakenTargetPlayerSpell>(this, AbilityType::Instant,
			_T("4") WHITE_MANA_TEXT, 2));
	cpAwakenSpell->GetTargetPlayerCreatureModifiers().Add(
		new CCreatureKeywordModifier(CreatureKeyword::DealNoCombatDamage, TRUE, TRUE));
	AddSpell(cpAwakenSpell.GetPointer());
}

COnduRisingCard::COnduRisingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ondu Rising"), CardType::Sorcery, nID)
{
	// "Whenever a creature attacks this turn, it gains lifelink until end of turn" lives in an effect token
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT));
	cpSpell->GetResolutionModifier().CPlayerModifiers::Add(
		new CTokenCreationModifier(GetGame(), _T("Ondu Rising Effect"), 61140, 1, FALSE, ZoneId::_Effects));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenLandSpell> cpAwakenSpell(
		::CreateObject<CAwakenLandSpell>(this, AbilityType::Sorcery,
			_T("4") WHITE_MANA_TEXT, 4));
	cpAwakenSpell->GetControllerModifiers().Add(
		new CTokenCreationModifier(GetGame(), _T("Ondu Rising Effect"), 61140, 1, FALSE, ZoneId::_Effects));
	AddSpell(cpAwakenSpell.GetPointer());
}

CPartTheWaterveilCard::CPartTheWaterveilCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Part the Waterveil"), CardType::Sorcery, nID)
{
	counted_ptr<CPlayerEffectSpell> cpSpell(
		::CreateObject<CPlayerEffectSpell>(this, AbilityType::Sorcery,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			PlayerEffectType::TimeWalk, FALSE, 1));
	cpSpell->SetAffectControllerOnly();
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenLandSpell> cpAwakenSpell(
		::CreateObject<CAwakenLandSpell>(this, AbilityType::Sorcery,
			_T("6") BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT, 6));
	cpAwakenSpell->GetControllerModifiers().Add(
		new CPlayerEffectModifier(PlayerEffectType::TimeWalk, 1));
	cpAwakenSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	AddSpell(cpAwakenSpell.GetPointer());
}

CRushOfIceCard::CRushOfIceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rush of Ice"), CardType::Sorcery, nID)
{
	{
		counted_ptr<CTargetTapUntapCardSpell> cpSpell(
			::CreateObject<CTargetTapUntapCardSpell>(this, AbilityType::Sorcery,
				BLUE_MANA_TEXT,
				TRUE, FALSE,	// Tap, Untap
				new CardTypeComparer(CardType::Creature, false)));
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CAwakenSpell> cpAwakenSpell(
			::CreateObject<CAwakenSpell>(this, AbilityType::Sorcery,
				_T("4") BLUE_MANA_TEXT, new CardTypeComparer(CardType::Creature, false),
				ZoneId::Battlefield, 3, new CCardOrientationModifier(TRUE)));
		cpAwakenSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);

		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		cpAwakenSpell->GetTargetEffects().push_back(pModifier);

		AddSpell(cpAwakenSpell.GetPointer());
	}
}

CScatterToTheWindsCard::CScatterToTheWindsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Scatter to the Winds"), CardType::Instant, nID)
{
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, new TrueCardComparer));
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenCounterSpell> cpAwakenSpell(
		::CreateObject<CAwakenCounterSpell>(this, AbilityType::Instant,
			_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, 3));
	AddSpell(cpAwakenSpell.GetPointer());
}

CMiresMaliceCard::CMiresMaliceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Mire's Malice"), CardType::Sorcery, nID)
{
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT,
			2, MoveType::Discard, ZoneId::Graveyard, TRUE,
			TRUE,
			CCardFilter::GetFilter(_T("cards"))));
	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	AddSpell(cpSpell.GetPointer());

	counted_ptr<CAwakenTargetPlayerSpell> cpAwakenSpell(
		::CreateObject<CAwakenTargetPlayerSpell>(this, AbilityType::Sorcery,
			_T("5") BLACK_MANA_TEXT, 3));
	cpAwakenSpell->SetTargetPlayerDiscardCount(2);
	AddSpell(cpAwakenSpell.GetPointer());
}

CRoilSpoutCard::CRoilSpoutCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Roil Spout"), CardType::Sorcery, nID,
		_T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Sorcery,
		new AnyCreatureComparer,
		ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others)
{
	counted_ptr<CAwakenSpell> cpSpell(
		::CreateObject<CAwakenSpell>(this, AbilityType::Sorcery,
			_T("4") WHITE_MANA_TEXT BLUE_MANA_TEXT, new AnyCreatureComparer,
			ZoneId::Battlefield, 4,
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Library, TRUE, MoveType::Others)));
	AddSpell(cpSpell.GetPointer());
}

CGrovetenderDruidsCard::CGrovetenderDruidsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grovetender Druids"), CardType::Creature,
		CREATURE_TYPE3(Elf, Druid, Ally), nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	typedef TTriggeredAbility<CTriggeredCreateTokenAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateRallyAbility<TriggeredAbility>(this));
	cpAbility->SetResolutionCost(_T("1"));
	cpAbility->SetCreateTokenOption(TRUE, _T("Plant (B)"), 55064, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CHeroOfGomaFadaCard::CHeroOfGomaFadaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hero of Goma Fada"), CardType::Creature,
		CREATURE_TYPE3(Human, Knight, Ally), nID,
		_T("4") WHITE_MANA_TEXT, Power(4), Life(3))
{
	counted_ptr<RallyModifyCreaturesAbility> cpAbility(CreateRallyModifyCreaturesAbility(this));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Indestructible);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	AddAbility(cpAbility.GetPointer());
}

CKalastriaHealerCard::CKalastriaHealerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kalastria Healer"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Cleric, Ally), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
{
	typedef TTriggeredAbility<CTriggeredModifyLifeAbility, CWhenCardMoved> TriggeredAbility;

	// Note: triggers once per opponent, so in multiplayer you gain 1 life for each opponent
	counted_ptr<TriggeredAbility> cpAbility(CreateRallyAbility<TriggeredAbility>(this));
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetResolutionModifier().CPlayerModifiers::Add(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CKorBladewhirlCard::CKorBladewhirlCard(CGame* pGame, UINT nID)
	: CRallyCreatureCard(pGame, _T("Kor Bladewhirl"), CardType::Creature,
		CREATURE_TYPE3(Kor, Soldier, Ally), nID, _T("1") WHITE_MANA_TEXT,
		Power(2), Life(2), CreatureKeyword::FirstStrike)
{
}

CKorEntanglersCard::CKorEntanglersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kor Entanglers"), CardType::Creature,
		CREATURE_TYPE3(Kor, Soldier, Ally), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
	typedef TTriggeredTargetAbility<CTriggeredTapCardAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateRallyAbility<TriggeredAbility>(this));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->SetTapCardOption(CTriggeredTapCardAbility::TapCardOption::TapSingleCard);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CLanternScoutCard::CLanternScoutCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lantern Scout"), CardType::Creature,
		CREATURE_TYPE3(Human, Scout, Ally), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	counted_ptr<RallyModifyCreaturesAbility> cpAbility(CreateRallyModifyCreaturesAbility(this));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	AddAbility(cpAbility.GetPointer());
}

CMakindiPatrolCard::CMakindiPatrolCard(CGame* pGame, UINT nID)
	: CRallyCreatureCard(pGame, _T("Makindi Patrol"), CardType::Creature,
		CREATURE_TYPE3(Human, Knight, Ally), nID, _T("2") WHITE_MANA_TEXT,
		Power(2), Life(3), CreatureKeyword::Vigilance)
{
}

COnduChampionCard::COnduChampionCard(CGame* pGame, UINT nID)
	: CRallyCreatureCard(pGame, _T("Ondu Champion"), CardType::Creature,
		CREATURE_TYPE3(Minotaur, Warrior, Ally), nID, _T("2") RED_MANA_TEXT RED_MANA_TEXT,
		Power(4), Life(3), CreatureKeyword::Trample)
{
}

CResoluteBlademasterCard::CResoluteBlademasterCard(CGame* pGame, UINT nID)
	: CRallyCreatureCard(pGame, _T("Resolute Blademaster"), CardType::Creature,
		CREATURE_TYPE3(Human, Soldier, Ally), nID, _T("3") RED_MANA_TEXT WHITE_MANA_TEXT,
		Power(2), Life(2), CreatureKeyword::DoubleStrike)
{
}

CTajuruBeastmasterCard::CTajuruBeastmasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tajuru Beastmaster"), CardType::Creature,
		CREATURE_TYPE3(Elf, Warrior, Ally), nID,
		_T("5") GREEN_MANA_TEXT, Power(5), Life(5))
{
	counted_ptr<RallyModifyCreaturesAbility> cpAbility(CreateRallyModifyCreaturesAbility(this));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	AddAbility(cpAbility.GetPointer());
}

CTajuruWarcallerCard::CTajuruWarcallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tajuru Warcaller"), CardType::Creature,
		CREATURE_TYPE3(Elf, Warrior, Ally), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(1))
{
	counted_ptr<RallyModifyCreaturesAbility> cpAbility(CreateRallyModifyCreaturesAbility(this));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+2));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+2));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Lands

CBattleLandCard::CBattleLandCard(CGame* pGame, LPCTSTR strCardName, UINT uID, CardType landType,
								 LPCTSTR strPoolText1, LPCTSTR strPoolText2)
	: CDualLandCard(pGame, strCardName, uID, landType | CardType::NonbasicLand,
		strPoolText1, strPoolText2)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CBattleLandCard::OnZoneChanged))
{
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CBattleLandCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this)
		return;

	CZone* pInplay = GetController()->GetZoneById(ZoneId::Battlefield);

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield &&
		CCardFilter::GetFilter(_T("basic lands"))->CountIncluded(pInplay->GetCardContainer()) < 2)
	{
		this->GetOrientation()->Tap();
	}
}

CCanopyVistaCard::CCanopyVistaCard(CGame* pGame, UINT nID)
	: CBattleLandCard(pGame, _T("Canopy Vista"), nID, CardType::Forest | CardType::Plains,
		GREEN_MANA_TEXT, WHITE_MANA_TEXT)
{
}

CCinderGladeCard::CCinderGladeCard(CGame* pGame, UINT nID)
	: CBattleLandCard(pGame, _T("Cinder Glade"), nID, CardType::Mountain | CardType::Forest,
		RED_MANA_TEXT, GREEN_MANA_TEXT)
{
}

CPrairieStreamCard::CPrairieStreamCard(CGame* pGame, UINT nID)
	: CBattleLandCard(pGame, _T("Prairie Stream"), nID, CardType::Plains | CardType::Island,
		WHITE_MANA_TEXT, BLUE_MANA_TEXT)
{
}

CSmolderingMarshCard::CSmolderingMarshCard(CGame* pGame, UINT nID)
	: CBattleLandCard(pGame, _T("Smoldering Marsh"), nID, CardType::Swamp | CardType::Mountain,
		BLACK_MANA_TEXT, RED_MANA_TEXT)
{
}

CSunkenHollowCard::CSunkenHollowCard(CGame* pGame, UINT nID)
	: CBattleLandCard(pGame, _T("Sunken Hollow"), nID, CardType::Island | CardType::Swamp,
		BLUE_MANA_TEXT, BLACK_MANA_TEXT)
{
}

CBlightedCataractCard::CBlightedCataractCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Blighted Cataract"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T("5") BLUE_MANA_TEXT, 2));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CBlightedFenCard::CBlightedFenCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Blighted Fen"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CTargetPlayerSacrificeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetPlayerSacrificeSpell>>(this,
				_T("4") BLACK_MANA_TEXT,
				CCardFilter::GetFilter(_T("creatures"))));
		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CBlightedGorgeCard::CBlightedGorgeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Blighted Gorge"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("4") RED_MANA_TEXT, new AnyCreatureComparer, TRUE,
				Life(-2), PreventableType::Preventable));
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CBlightedSteppeCard::CBlightedSteppeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Blighted Steppe"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CChgLifeBySurveySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CChgLifeBySurveySpell>>(this,
				_T("3") WHITE_MANA_TEXT));
		cpAbility->SetCardsMultiplier(2, CCardFilter::GetFilter(_T("creatures")), ZoneId::Battlefield);
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CBlightedWoodlandCard::CBlightedWoodlandCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Blighted Woodland"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
				_T("3") GREEN_MANA_TEXT,
				CCardFilter::GetFilter(_T("basic lands")),
				ZoneId::Battlefield, FALSE, TRUE, TRUE));
		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(2));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CLoomingSpiresCard::CLoomingSpiresCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Looming Spires"), nID)
{
	SetIntoPlayTapped();

	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
		cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::FirstStrike);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CLumberingFallsCard::CLumberingFallsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Lumbering Falls"), nID)
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
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T("2") GREEN_MANA_TEXT BLUE_MANA_TEXT,
				_T("Elemental AP"), 64095));
		AddAbility(cpAbility.GetPointer());
	}
}

CMortuaryMireCard::CMortuaryMireCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Mortuary Mire"), nID)
{
	SetIntoPlayTapped();

	{
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Library);
		cpAbility->GetMoveCardModifier().SetToTop(TRUE);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Library));
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CSandstoneBridgeCard::CSandstoneBridgeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Sandstone Bridge"), nID)
{
	SetIntoPlayTapped();

	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
		cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Vigilance);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CShamblingVentCard::CShamblingVentCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Shambling Vent"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT,
				_T("Elemental AQ"), 64096));
		AddAbility(cpAbility.GetPointer());
	}
}

CSkylineCascadeCard::CSkylineCascadeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Skyline Cascade"), nID)
{
	SetIntoPlayTapped();

	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(FALSE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CSpawningBedCard::CSpawningBedCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Spawning Bed"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("6"),
				_T("Eldrazi Scion (A)"), 55056,
				3));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// Planeswalkers

CGideonAllyOfZendikarCard::CGideonAllyOfZendikarCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Gideon, Ally of Zendikar"), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Gideon, 4)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CGideonAllyOfZendikarCard::OnResolutionCompleted))
{
	{
		// +1: Until end of turn, Gideon becomes a 5/5 Human Soldier Ally creature with indestructible
		// that's still a planeswalker. Prevent all damage that would be dealt to him this turn.
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T(""),
				_T("Animated Gideon, Ally of Zendikar"), 64097));

		cpAbility->SetAbilityText(_T("+1: Gideon, Ally of Zendikar becomes a 5/5 creature. Activates"));

		CPlayerEffectModifier* pmodifier = new CPlayerEffectModifier(PlayerEffectType::PreventDamagetoGideon2);
		CScheduledPlayerModifier* pModifier2 = new CScheduledPlayerModifier(
			GetGame(), pmodifier, TurnNumberDelta(-1), NodeId::EndStep, CScheduledPlayerModifier::Operation::RemoveFromLater);

		pmodifier->LinkPlayerModifier(pModifier2);

		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(pmodifier);
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// 0: Create a 2/2 white Knight Ally creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				_T("Knight Ally (A)"), 55060,
				1));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -4: You get an emblem with "Creatures you control get +1/+1."
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -4);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CTokenCreationModifier(GetGame(), _T("Gideon, Ally of Zendikar Emblem"), 61141, 1, FALSE, ZoneId::_Effects));
		cpAbility->SetAbilityText(_T("-4: You get an emblem with - Creatures you control get +1/+1."));

		AddAbility(cpAbility.GetPointer());
	}
}

void CGideonAllyOfZendikarCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;
	CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Indestructible, TRUE);
	pModifier.ApplyTo((CCard*)this);
}

CObNixilisReignitedCard::CObNixilisReignitedCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ob Nixilis Reignited"), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Nixilis, 5)
{
	{
		// +1: You draw a card and you lose 1 life.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T(""), 1));

		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage)); // lost of life, not preventable
		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Destroy target creature.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Creature, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: Target opponent gets an emblem with "Whenever a player draws a card, you lose 2 life."
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, true));

		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CPlayerModifiers::push_back(new CTokenCreationModifier(GetGame(), _T("Ob Nixilis Reignited Emblem"), 61142, 1, FALSE, ZoneId::_Effects));
		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->SetAbilityText(_T("-8: Target opponent gets an emblem with - Whenever a player draws a card, you lose 2 life."));

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// Artifacts

// Colorless means no color at all (colored artifacts are not colorless; devoid cards are)
static bool IsColorless(const CCard* pCard)
{
	return !(pCard->GetCardType() & CardType::_ColorMask).Any();
}

CAlignedHedronNetworkCard::CAlignedHedronNetworkCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Aligned Hedron Network"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CAlignedHedronNetworkCard::OnZoneChanged))
{
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	{
		// When this artifact enters, exile all creatures with power 5 or greater until this artifact leaves the battlefield
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAlignedHedronNetworkCard::BeforeResolution1));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Those creatures return under their owners' control when this artifact leaves the battlefield
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Exile, ZoneId::Battlefield));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAlignedHedronNetworkCard::BeforeResolution2));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Forget exiled cards that leave exile by other means
		counted_ptr<TriggeredAbilityAux> cpAbility(
			::CreateObject<TriggeredAbilityAux>(this, ZoneId::Exile, ZoneId::_AllZones, FALSE, TRUE));

		cpAbility->SetOptionalType(TriggeredAbilityAux::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);

		cpAbility->SetContextFunction(TriggeredAbilityAux::ContextFunction(this, &CAlignedHedronNetworkCard::SetTriggerContextAux));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbilityAux::BeforeResolveSelectionCallback(this, &CAlignedHedronNetworkCard::BeforeResolutionAux));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAlignedHedronNetworkCard::SetTriggerContextAux(CTriggeredAbility<>::TriggerContextType& triggerContext,
													 CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pExiled.HasCard(pCard)) return false;

	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CAlignedHedronNetworkCard::BeforeResolutionAux(TriggeredAbilityAux::TriggeredActionType* pAction)
{
	TriggeredAbilityAux::TriggerContextType triggerContext(pAction->GetTriggerContext());

	pExiled.RemoveCard((CCard*)triggerContext.nValue1);

	return true;
}

bool CAlignedHedronNetworkCard::BeforeResolution1(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController);

	CCountedCardContainer pToExile;

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);

		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);

			if (pCard->GetCardType().IsCreature() && ((CCreatureCard*)pCard)->GetPower() >= 5)
			{
				pExiled.AddCard(pCard, CardPlacement::Top);
				pToExile.AddCard(pCard, CardPlacement::Top);
			}
		}
	}

	for (int i = 0; i < pToExile.GetSize(); ++i)
		pModifier.ApplyTo(pToExile.GetAt(i));

	return true;
}

bool CAlignedHedronNetworkCard::BeforeResolution2(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	while (pExiled.GetSize() > 0)
	{
		CCard* pCard = pExiled.GetAt(0);
		pExiled.RemoveCard(pCard);
		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Battlefield), pController, MoveType::Others);
	}

	return true;
}

void CAlignedHedronNetworkCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this) return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType != MoveType::Phasing)
	{
		pExiled.RemoveAll();
	}
}

CHedronArchiveCard::CHedronArchiveCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hedron Archive"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("2")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T("2"), 2));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CHedronBladeCard::CHedronBladeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hedron Blade"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+1), this,
		PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CHedronBladeCard::CreateEquipmentAbility)));

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CHedronBladeCard::CreateEquipmentAbility(CCard* pCard)
{
	// Whenever equipped creature becomes blocked by one or more colorless creatures, it gains deathtouch until end of turn
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CHedronBladeCard::SetTriggerContext));

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CHedronBladeCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
										 CCreatureCard* pCreature, CCreatureCard* pBlocker, int nBlockedByCount, int nBlockingIndex) const
{
	return pBlocker && IsColorless(pBlocker);
}

CPathwayArrowsCard::CPathwayArrowsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pathway Arrows"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CPathwayArrowsCard::CreateEquipmentAbility)));

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CPathwayArrowsCard::CreateEquipmentAbility(CCard* pCard)
{
	// "{2}, {T}: This creature deals 1 damage to target creature. If a colorless creature is dealt damage this way, tap it."
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(pCard,
			_T("2"), new AnyCreatureComparer, FALSE,
			Life(-1), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPathwayArrowsCard::BeforeResolution));

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CPathwayArrowsCard::BeforeResolution(CAbilityAction* pAction) const
{
	// Note: the colorless target is tapped even if the damage is later prevented
	CCard* pTarget = pAction->GetAssociatedCard();

	if (pTarget && pTarget->GetCardType().IsCreature() && IsColorless(pTarget))
		pTarget->GetOrientation()->Tap();

	return true;
}

//____________________________________________________________________________
//
// Enchantments

CAngelicGiftCard::CAngelicGiftCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Angelic Gift"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Flying)
{
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(1);

	AddAbility(cpAbility.GetPointer());
}

CDampeningPulseCard::CDampeningPulseCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dampening Pulse"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new AnyCreatureComparer,
			Power(-1), Life(+0)));

	cpAbility->SetAffectOpponentCardsOnly();

	AddAbility(cpAbility.GetPointer());
}

CTighteningCoilsCard::CTighteningCoilsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Tightening Coils"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(-6), Life(+0))
{
	m_pChgPwrTghAttrEnchant->GetCreatureKeywordMod().GetModifier().SetToRemove(CreatureKeyword::Flying);
}

CVampiricRitesCard::CVampiricRitesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Vampiric Rites"), CardType::GlobalEnchantment, nID,
		BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// {1}{B}, Sacrifice a creature: You gain 1 life and draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("1") BLACK_MANA_TEXT, 1));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);

	AddAbility(cpAbility.GetPointer());
}

CMoltenNurseryCard::CMoltenNurseryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Molten Nursery"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
{
	SetDevoid();

	// Whenever you cast a colorless spell, this enchantment deals 1 damage to any target.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CardTypeComparer(CardType::_ColorMask, false)));

	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

CFromBeyondCard::CFromBeyondCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("From Beyond"), CardType::GlobalEnchantment, nID,
		_T("3") GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_CardFilter(_T("an Eldrazi card"), _T("Eldrazi cards"), new CreatureTypeComparer(CREATURE_TYPE(Eldrazi), false))
{
	SetDevoid();

	{
		// At the beginning of your upkeep, create a 1/1 colorless Eldrazi Scion creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Scion (A)"), 55056, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{G}, Sacrifice this enchantment: Search your library for an Eldrazi card, reveal it, put it into your hand
		counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
				_T("1") GREEN_MANA_TEXT,
				&m_CardFilter,
				ZoneId::Hand, TRUE, FALSE, FALSE));

		cpAbility->AddSacrificeCost();

		AddAbility(cpAbility.GetPointer());
	}
}

CStasisSnareCard::CStasisSnareCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Stasis Snare"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	GetCardKeyword()->AddFlash(FALSE);

	{
		// When this enchantment enters, exile target creature an opponent controls until this enchantment leaves the battlefield.
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		m_CardFlagModifier1.GetModifier().SetOneTurnOnly(FALSE);
		m_CardFlagModifier1.GetModifier().SetToAdd(CardFlag::AbilityFlag);
		m_CardFlagModifier1.GetModifier().SetAdditionData(cpAbility->GetInstanceID());
		cpAbility->GetMoveCardModifier().LinkCardModifier(&m_CardFlagModifier1); // the exiled card is flagged, to find it again later

		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(FALSE);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this enchantment leaves the battlefield, return the exiled card to the battlefield under its owner's control.
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToAllPlayers);

		m_CardFlagModifier2.GetModifier().SetOneTurnOnly(FALSE);
		m_CardFlagModifier2.GetModifier().SetToRemove(CardFlag::AbilityFlag);
		m_CardFlagModifier2.GetModifier().SetRemovalData(m_CardFlagModifier1.GetModifier().GetAdditionData());
		cpAbility->GetMoveCardModifier().LinkCardModifier(&m_CardFlagModifier2);

		cpAbility->SetMoveCardOption(CTriggeredMoveCardAbility::MoveCardOption::MoveMultipleCards);
		CardFlagComparer* pComparer = new CardFlagComparer(CardFlag::AbilityFlag, false);
		pComparer->SetData(m_CardFlagModifier1.GetModifier().GetAdditionData());
		cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(pComparer);
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Exile, ZoneId::Battlefield));

		AddAbility(cpAbility.GetPointer());
	}
}

#define ISOLATION_COUNTER	_T("isolation counter")

CQuarantineFieldCard::CQuarantineFieldCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Quarantine Field"), CardType::GlobalEnchantment, nID,
		WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CQuarantineFieldCard::OnCardsSelected))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CQuarantineFieldCard::OnZoneChanged))
{
	// {X}{X}{W}{W}: X is half of the extra mana paid
	GetSpells().GetAt(0)->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	{
		// When this enchantment enters, for each isolation counter on it, exile up to one target nonland permanent
		// an opponent controls until this enchantment leaves the battlefield.
		// Note: the permanents are chosen when the ability resolves; cards with shroud or hexproof can't be chosen.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CQuarantineFieldCard::BeforeResolution1));

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Exile, ZoneId::Battlefield));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CQuarantineFieldCard::BeforeResolution2));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Forget exiled cards that leave exile by other means
		counted_ptr<TriggeredAbilityAux> cpAbility(
			::CreateObject<TriggeredAbilityAux>(this, ZoneId::Exile, ZoneId::_AllZones, FALSE, TRUE));

		cpAbility->SetOptionalType(TriggeredAbilityAux::OptionalType::Required);
		cpAbility->SetSkipStack(TRUE);

		cpAbility->SetContextFunction(TriggeredAbilityAux::ContextFunction(this, &CQuarantineFieldCard::SetTriggerContextAux));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbilityAux::BeforeResolveSelectionCallback(this, &CQuarantineFieldCard::BeforeResolutionAux));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CQuarantineFieldCard::SetTriggerContextAux(CTriggeredAbility<>::TriggerContextType& triggerContext,
												CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pExiled.HasCard(pCard)) return false;

	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CQuarantineFieldCard::BeforeResolutionAux(TriggeredAbilityAux::TriggeredActionType* pAction)
{
	TriggeredAbilityAux::TriggerContextType triggerContext(pAction->GetTriggerContext());

	pExiled.RemoveCard((CCard*)triggerContext.nValue1);

	return true;
}

bool CQuarantineFieldCard::BeforeResolution1(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	int nCount = GetCounterContainer()->GetCounter(ISOLATION_COUNTER)->GetCount();
	if (nCount <= 0)
		return true;

	std::vector<SelectionEntry> entries;

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pController)
			continue;

		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);

			if (pCard->GetCardType().IsLand() ||
				pCard->GetCardKeyword()->HasShroud(this) || pCard->GetCardKeyword()->HasHexproof())
				continue;

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));

			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, MIN(nCount, (int)entries.size()), this, pController);

	return true;
}

void CQuarantineFieldCard::OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);

	CCountedCardContainer pToExile;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			pExiled.AddCard(pCard, CardPlacement::Top);
			pToExile.AddCard(pCard, CardPlacement::Top);
		}

	for (int i = 0; i < pToExile.GetSize(); ++i)
		pModifier.ApplyTo(pToExile.GetAt(i));
}

bool CQuarantineFieldCard::BeforeResolution2(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	while (pExiled.GetSize() > 0)
	{
		CCard* pCard = pExiled.GetAt(0);
		pExiled.RemoveCard(pCard);
		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Battlefield), pController, MoveType::Others);
	}

	return true;
}

void CQuarantineFieldCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this) return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType != MoveType::Phasing)
	{
		pExiled.RemoveAll();

		// This enchantment enters with X isolation counters on it
		if (moveType == MoveType::Cast)
		{
			CCardCounterModifier pModifier = CCardCounterModifier(ISOLATION_COUNTER, +GetLastCastingExtraValue());
			pModifier.ApplyTo(this);
		}
	}
}

//____________________________________________________________________________
//
// Retreats

CRetreatCard::CRetreatCard(CGame* pGame, LPCTSTR strCardName, UINT uID, LPCTSTR strCostText,
						   LPCTSTR strMode1Text, LPCTSTR strMode2Text)
	: CInPlaySpellCard(pGame, strCardName, CardType::GlobalEnchantment, uID,
		strCostText, AbilityType::Enchantment)
	, m_ModeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CRetreatCard::OnModeSelected))
	, m_strMode1Text(strMode1Text)
	, m_strMode2Text(strMode2Text)
{
	// Landfall - Whenever a land you control enters, choose one
	counted_ptr<LandfallAbility> cpAbility(::CreateObject<LandfallAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));

	cpAbility->SetOptionalType(LandfallAbility::OptionalType::Required);
	cpAbility->SetContextFunction(LandfallAbility::ContextFunction(this, &CRetreatCard::SetLandfallContext));
	cpAbility->SetSkipStack(TRUE);

	AddAbility(cpAbility.GetPointer());
}

template <class TriggeredAbility>
counted_ptr<TriggeredAbility> CRetreatCard::CreateModeAbility(int nTriggerId, LPCTSTR strAbilityName)
{
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

	cpAbility->GetTrigger().SetTriggerIndex(nTriggerId);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);

	cpAbility->SetAbilityName(strAbilityName);

	return cpAbility;
}

bool CRetreatCard::SetLandfallContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
									  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	std::vector<SelectionEntry> entries;
	{
		SelectionEntry selectionEntry;

		selectionEntry.dwContext = 1;
		selectionEntry.strText.Format(_T("%s: %s"), GetCardName(TRUE), m_strMode1Text);

		entries.push_back(selectionEntry);
	}
	{
		SelectionEntry selectionEntry;

		selectionEntry.dwContext = 2;
		selectionEntry.strText.Format(_T("%s: %s"), GetCardName(TRUE), m_strMode2Text);

		entries.push_back(selectionEntry);
	}

	m_ModeSelection.AddSelectionRequest(entries, 1, 1, NULL, GetController());

	return false;
}

void CRetreatCard::OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	ATLASSERT(nSelectedCount == 1);

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int nMode = (int)it->dwContext;

			if (!m_pGame->IsThinking())
			{
				CString strMessage;
				strMessage.Format(_T("%s chooses %s mode"), pSelectionPlayer->GetPlayerName(), nMode == 1 ? _T("first") : _T("second"));

				m_pGame->Message(
					strMessage,
					pSelectionPlayer->IsComputer() ? m_pGame->GetComputerImage() : m_pGame->GetHumanImage(),
					MessageImportance::High
					);
			}

			CSpecialEffectModifier pModifier = CSpecialEffectModifier(this, nMode == 1 ? CHOICE_1_TRIGGER_ID : CHOICE_2_TRIGGER_ID);
			pModifier.ApplyTo(this);

			return;
		}
}

CRetreatToCoralhelmCard::CRetreatToCoralhelmCard(CGame* pGame, UINT nID)
	: CRetreatCard(pGame, _T("Retreat to Coralhelm"), nID, _T("2") BLUE_MANA_TEXT,
		_T("You may tap or untap target creature"), _T("Scry 1"))
{
	{
		typedef
			TTriggeredTargetAbility< CTriggeredTapCardAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_1_TRIGGER_ID,
			_T("Mode 1 - you may tap or untap target creature")));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetTapCardOption(CTriggeredTapCardAbility::TapCardOption::TapUntapSingleCard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<ScryAbility> cpAbility(CreateModeAbility<ScryAbility>(CHOICE_2_TRIGGER_ID,
			_T("Mode 2 - scry 1")));

		cpAbility->SetBeforeResolveSelectionCallback(ScryAbility::BeforeResolveSelectionCallback(this, &CRetreatToCoralhelmCard::BeforeScry));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CRetreatToCoralhelmCard::BeforeScry(ScryAbility::TriggeredActionType* pAction) const
{
	//Scry 1 start----------------------
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
		pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
		pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
		pModifier->GetSelection(0).moveType = MoveType::Others;
		pModifier->AddSelection(MinimumValue(0), MaximumValue(1), // select cards to bottom
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			NULL,									// any cards
			ZoneId::Library,						// if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Bottom,					// put selected cards on the bottom
			MoveType::Others,						// move type
			CZoneModifier::RoleType::PrimaryPlayer);// order selected cards by this player

		// and finally put the last ones on top of the library
		pModifier->SetReorderInformation(
			true,
			ZoneId::Library,
			CZoneModifier::RoleType::PrimaryPlayer,	// this player's library
			CardPlacement::Top);
	//Scry 1 end--------------------------
	pModifier->ApplyTo(GetController());

	CSpecialEffectModifier pScryModifier = CSpecialEffectModifier((CCard*)this, SCRY_TRIGGER_ID);
	pScryModifier.ApplyTo((CCard*)this);

	return true;
}

CRetreatToEmeriaCard::CRetreatToEmeriaCard(CGame* pGame, UINT nID)
	: CRetreatCard(pGame, _T("Retreat to Emeria"), nID, _T("3") WHITE_MANA_TEXT,
		_T("Create a 1/1 white Kor Ally creature token"), _T("Creatures you control get +1/+1 until end of turn"))
{
	{
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_1_TRIGGER_ID,
			_T("Mode 1 - create a 1/1 white Kor Ally creature token")));

		cpAbility->SetCreateTokenOption(TRUE, _T("Kor Ally (A)"), 55061, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredModifyCreatureAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_2_TRIGGER_ID,
			_T("Mode 2 - creatures you control get +1/+1 until end of turn")));

		cpAbility->SetModifyCreatureOption(TriggeredAbility::ModifyCreatureOption::ModifyTriggeredPlayersCreatures);
		cpAbility->GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
}

CRetreatToHagraCard::CRetreatToHagraCard(CGame* pGame, UINT nID)
	: CRetreatCard(pGame, _T("Retreat to Hagra"), nID, _T("2") BLACK_MANA_TEXT,
		_T("Target creature gets +1/+0 and gains deathtouch until end of turn"), _T("Each opponent loses 1 life and you gain 1 life"))
{
	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_1_TRIGGER_ID,
			_T("Mode 1 - target creature gets +1/+0 and gains deathtouch until end of turn")));

		cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
		cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CSpecialTrigger > TriggeredAbility;

		// Note: triggers once per opponent, so in multiplayer you gain 1 life for each opponent
		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_2_TRIGGER_ID,
			_T("Mode 2 - each opponent loses 1 life and you gain 1 life")));

		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->GetResolutionModifier().CPlayerModifiers::Add(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);

		AddAbility(cpAbility.GetPointer());
	}
}

CRetreatToKazanduCard::CRetreatToKazanduCard(CGame* pGame, UINT nID)
	: CRetreatCard(pGame, _T("Retreat to Kazandu"), nID, _T("2") GREEN_MANA_TEXT,
		_T("Put a +1/+1 counter on target creature"), _T("You gain 2 life"))
{
	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_1_TRIGGER_ID,
			_T("Mode 1 - put a +1/+1 counter on target creature")));

		cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1, false));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_2_TRIGGER_ID,
			_T("Mode 2 - you gain 2 life")));

		cpAbility->GetLifeModifier().SetLifeDelta(Life(+2));
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);

		AddAbility(cpAbility.GetPointer());
	}
}

CRetreatToValakutCard::CRetreatToValakutCard(CGame* pGame, UINT nID)
	: CRetreatCard(pGame, _T("Retreat to Valakut"), nID, _T("2") RED_MANA_TEXT,
		_T("Target creature gets +2/+0 until end of turn"), _T("Target creature can't block this turn"))
{
	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_1_TRIGGER_ID,
			_T("Mode 1 - target creature gets +2/+0 until end of turn")));

		cpAbility->GetPowerModifier().SetPowerDelta(Power(+2));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateModeAbility<TriggeredAbility>(CHOICE_2_TRIGGER_ID,
			_T("Mode 2 - target creature can't block this turn")));

		cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::CantBlock);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// Sorceries

CCrumbleToDustCard::CCrumbleToDustCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Crumble to Dust"), CardType::Sorcery, nID,
		_T("3") RED_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::NonbasicLand, false),
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CCrumbleToDustCard::OnResolutionCompleted))
{
	SetDevoid();

	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pTargetMoveCardSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
}

void CCrumbleToDustCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	// Search its controller's graveyard, hand, and library for any number of cards with the same name and exile them (as Splinter)
	CCard* pCard = pAbilityAction->GetAssociatedCard();
	CPlayer* target = pCard->GetController();
	CZone* pLibrary = target->GetZoneById(ZoneId::Library);

	CCardFilter m_CardFilter_temp;
	m_CardFilter_temp.SetComparer(new CardNameComparer(pCard->GetPrintedCardName()));

	CZoneCardModifier pModifier1 = CZoneCardModifier(ZoneId::Graveyard, &m_CardFilter_temp,
		std::auto_ptr<CCardModifier>(new CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others)));
	CZoneCardModifier pModifier2 = CZoneCardModifier(ZoneId::Hand, &m_CardFilter_temp,
		std::auto_ptr<CCardModifier>(new CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others)));
	CZoneCardModifier pModifier3 = CZoneCardModifier(ZoneId::Library, &m_CardFilter_temp,
		std::auto_ptr<CCardModifier>(new CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others)));

	CZoneModifier pmodifier2 = CZoneModifier(GetGame(), ZoneId::Hand, SpecialNumber::All, CZoneModifier::RoleType::PrimaryPlayer,
													CardPlacement::Top, CZoneModifier::RoleType::AllPlayers);
	CZoneModifier pmodifier3 = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All, CZoneModifier::RoleType::PrimaryPlayer,
													CardPlacement::Top, CZoneModifier::RoleType::AllPlayers);
	if (bResult)
	{
		pModifier1.ApplyTo(target);
		pmodifier2.ApplyTo(target);
		pModifier2.ApplyTo(target);
		pmodifier3.ApplyTo(target);
		pModifier3.ApplyTo(target);

		pLibrary->Shuffle();
	}
}

CDemonsGraspCard::CDemonsGraspCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Demon's Grasp"), CardType::Sorcery, nID, AbilityType::Sorcery,
		_T("4") BLACK_MANA_TEXT,
		Power(-5), Life(-5),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
}

CReclaimingVinesCard::CReclaimingVinesCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Reclaiming Vines"), CardType::Sorcery, nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment | CardType::_Land, false),
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CNissasRenewalCard::CNissasRenewalCard(CGame* pGame, UINT nID)
	: CSearchLibrarySpellCard(pGame, _T("Nissa's Renewal"), CardType::Sorcery, nID,
		_T("5") GREEN_MANA_TEXT, AbilityType::Sorcery,
		CCardFilter::GetFilter(_T("basic lands")),
		ZoneId::Battlefield, FALSE, TRUE, TRUE)
{
	m_pSearchLibrarySpell->SetSearchCount(MinimumValue(0), MaximumValue(3));
	m_pSearchLibrarySpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+7), this, PreventableType::NotPreventable));
	m_pSearchLibrarySpell->AddAbilityTag(AbilityTag::LifeGain);
}

CTouchOfTheVoidCard::CTouchOfTheVoidCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Touch of the Void"), CardType::Sorcery, nID)
{
	SetDevoid();

	// Deals 3 damage to any target. If a creature dealt damage this way would die this turn, exile it instead (as Pillar of Flame)
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-3), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::NonCombatDamage | DamageType::SpellDamage | DamageType::ToExileDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);

	AddSpell(cpSpell.GetPointer());
}

CSeekTheWildsCard::CSeekTheWildsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Seek the Wilds"), CardType::Sorcery, nID)
	, m_CardFilter(_T("a creature or land card"), _T("creature or land cards"),
		new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	// Look at the top four cards; you may reveal a creature or land card and put it into your hand; the rest on the bottom (as Commune with Nature)
	counted_ptr<CRevealLibraryCardSpell> cpSpell(
		::CreateObject<CRevealLibraryCardSpell>(this, AbilityType::Sorcery,
			_T("1") GREEN_MANA_TEXT,
			4));

	cpSpell->SetSelectionOptions(MinimumValue(0), MaximumValue(1), ZoneId::Hand, CardPlacement::NotApplicable, &m_CardFilter);
	cpSpell->SetReorder(TRUE, ZoneId::Library, CardPlacement::Bottom);
	cpSpell->SetRevealCardsToOthers(
		TRUE,	// reveal cards to others
		TRUE);	// reveal only selected cards

	AddSpell(cpSpell.GetPointer());
}

CTransgressTheMindCard::CTransgressTheMindCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Transgress the Mind"), CardType::Sorcery, nID)
	, m_CardFilter(new ConvertedManaCostComparer<std::greater<int>>(2))
{
	SetDevoid();

	// Target player reveals their hand. You choose a card from it with mana value 3 or greater and exile that card.
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			1, MoveType::Others, ZoneId::Exile, TRUE,
			FALSE,	// TRUE -> Targeted player chooses, FALSE -> Caster chooses
			&m_CardFilter));

	AddSpell(cpSpell.GetPointer());
}

CSwarmSurgeCard::CSwarmSurgeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Swarm Surge"), CardType::Sorcery, nID)
{
	SetDevoid();

	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSwarmSurgeCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::CreatureChange);

	AddSpell(cpSpell.GetPointer());
}

bool CSwarmSurgeCard::BeforeResolution(CAbilityAction* pAction) const
{
	// Creatures you control get +2/+0 until end of turn. Colorless creatures you control also gain first strike until end of turn.
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer pCreatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+2));
	CCreatureKeywordModifier pKeywordModifier = CCreatureKeywordModifier(CreatureKeyword::FirstStrike, TRUE);

	for (int i = 0; i < pCreatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)pCreatures.GetAt(i);

		pPowerModifier.ApplyTo(pCreature);
		if (IsColorless(pCreature))
			pKeywordModifier.ApplyTo(pCreature);
	}

	return true;
}

CUginsInsightCard::CUginsInsightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ugin's Insight"), CardType::Sorcery, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CUginsInsightCard::OnResolutionCompleted))
{
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT));

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	AddSpell(cpSpell.GetPointer());
}

void CUginsInsightCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CPlayer* pController = pAbilityAction->GetController();

	// Scry X, where X is the greatest mana value among permanents you control (as Rush of Knowledge)
	CZone* pInplay = pController->GetZoneById(ZoneId::Battlefield);

	int nMaxCost = 0;
	for (int i = 0; i < pInplay->GetSize(); ++i)
	{
		int nCost = pInplay->GetAt(i)->GetConvertedManaCost();
		if (nCost > nMaxCost) nMaxCost = nCost;
	}

	if (nMaxCost > 0)
	{
		//Scry X start----------------------
		CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(nMaxCost), MaximumValue(nMaxCost));
			pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
			pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
			pModifier->GetSelection(0).moveType = MoveType::Others;
			pModifier->AddSelection(MinimumValue(0), MaximumValue(nMaxCost), // select cards to bottom
				CZoneModifier::RoleType::PrimaryPlayer, // select by
				CZoneModifier::RoleType::PrimaryPlayer, // reveal to
				NULL,									// any cards
				ZoneId::Library,						// if selected, move cards to
				CZoneModifier::RoleType::PrimaryPlayer, // select by this player
				CardPlacement::Bottom,					// put selected cards on the bottom
				MoveType::Others,						// move type
				CZoneModifier::RoleType::PrimaryPlayer);// order selected cards by this player

			// and finally put the last ones on top of the library
			pModifier->SetReorderInformation(
				true,
				ZoneId::Library,
				CZoneModifier::RoleType::PrimaryPlayer,	// this player's library
				CardPlacement::Top);
		//Scry X end--------------------------
		pModifier->ApplyTo(pController);

		CSpecialEffectModifier pScryModifier = CSpecialEffectModifier(this, SCRY_TRIGGER_ID);
		pScryModifier.ApplyTo(this);
	}

	// then draw three cards (as Preordain)
	CDrawCardModifier pModifier1 = CDrawCardModifier(GetGame(), MinimumValue(3), MaximumValue(3));
	pModifier1.ApplyTo(pController);
}

CMarchFromTheTombCard::CMarchFromTheTombCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("March from the Tomb"), CardType::Sorcery, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CMarchFromTheTombCard::OnResolutionCompleted))
	, m_AllySelection(pGame, CSelectionSupport::SelectionCallback(this, &CMarchFromTheTombCard::OnAllySelected))
	, m_nRemainingManaValue(0)
{
	// Return any number of target Ally creature cards with total mana value 8 or less from your graveyard to the battlefield.
	// Note: the Allies are chosen one at a time when the spell resolves, not as targets on casting.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	cpSpell->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Battlefield));

	AddSpell(cpSpell.GetPointer());
}

void CMarchFromTheTombCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	m_ChosenAllies.RemoveAll();
	m_nRemainingManaValue = 8;

	RequestNextAlly(pAbilityAction->GetController());
}

void CMarchFromTheTombCard::RequestNextAlly(CPlayer* pPlayer)
{
	CZone* pGraveyard = pPlayer->GetZoneById(ZoneId::Graveyard);
	CreatureTypeComparer allyComparer(CREATURE_TYPE(Ally), false);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);

		if (!pCard->GetCardType().IsCreature() || !allyComparer(pCard) || m_ChosenAllies.HasCard(pCard) ||
			(int)pCard->GetConvertedManaCost() > m_nRemainingManaValue)
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Return %s (%d of %d mana value left)"), pCard->GetCardName(TRUE),
			pCard->GetConvertedManaCost(), m_nRemainingManaValue);

		entries.push_back(entry);
	}

	if (entries.empty())
		ReturnChosenAllies(pPlayer);
	else
		m_AllySelection.AddSelectionRequest(entries, 0, 1, this, pPlayer);
}

void CMarchFromTheTombCard::OnAllySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			m_ChosenAllies.AddCard(pCard, CardPlacement::Top);
			m_nRemainingManaValue -= pCard->GetConvertedManaCost();

			RequestNextAlly(pSelectionPlayer);
			return;
		}

	// Nothing more selected
	ReturnChosenAllies(pSelectionPlayer);
}

void CMarchFromTheTombCard::ReturnChosenAllies(CPlayer* pPlayer)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pPlayer);

	while (m_ChosenAllies.GetSize() > 0)
	{
		CCard* pCard = m_ChosenAllies.GetAt(0);
		m_ChosenAllies.RemoveCard(pCard);

		if (pCard->GetZoneId() == ZoneId::Graveyard)
			pModifier.ApplyTo(pCard);
	}
}

//____________________________________________________________________________
//
// Instants

CAdverseConditionsCard::CAdverseConditionsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Adverse Conditions"), CardType::Instant, nID)
{
	SetDevoid();

	// Tap up to two target creatures. Those creatures don't untap during their controller's next untap step.
	// Create a 1/1 colorless Eldrazi Scion creature token.
	counted_ptr<CTargetTapUntapCardSpell> cpSpell(
		::CreateObject<CTargetTapUntapCardSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT,
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting()->SetSubjectCount(1, 2);

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Eldrazi Scion (A)"), 55056, 1));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);

	AddSpell(cpSpell.GetPointer());
}

CAnticipateCard::CAnticipateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Anticipate"), CardType::Instant, nID)
{
	// Look at the top three cards; put one of them into your hand and the rest on the bottom in any order (as Telling Time)
	counted_ptr<CDrawCardSpellEx> cpSpell(
		::CreateObject<CDrawCardSpellEx>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			3));

	cpSpell->GetZoneModifier().GetSelection(0).nMinSelectionCount = MinimumValue(1);
	cpSpell->GetZoneModifier().GetSelection(0).nMaxSelectionCount = MaximumValue(1);
	cpSpell->GetZoneModifier().GetSelection(0).moveType = MoveType::Others;

	cpSpell->GetZoneModifier().SetReorderInformation(
		true,
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,	// this player's library
		CardPlacement::Bottom);

	AddSpell(cpSpell.GetPointer());
}

CCompleteDisregardCard::CCompleteDisregardCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Complete Disregard"), CardType::Instant, nID,
		_T("2") BLACK_MANA_TEXT, AbilityType::Instant,
		new AnyCreatureComparer,
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
{
	SetDevoid();

	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreaturePowerComparer<std::less<int>>(4));
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CGideonsReproachCard::CGideonsReproachCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gideon's Reproach"), CardType::Instant, nID)
{
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-4), PreventableType::Preventable));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingBlockingCreatureComparer);
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);

	AddSpell(cpSpell.GetPointer());
}

CGraveBirthingCard::CGraveBirthingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grave Birthing"), CardType::Instant, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CGraveBirthingCard::OnCardSelected))
{
	SetDevoid();

	// Target opponent exiles a card from their graveyard. You create a 1/1 colorless Eldrazi Scion creature token. Draw a card.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGraveBirthingCard::BeforeResolution));
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Eldrazi Scion (A)"), 55056, 1));
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);

	AddSpell(cpSpell.GetPointer());
}

bool CGraveBirthingCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CZone* pGraveyard = pOpponent->GetZoneById(ZoneId::Graveyard);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	// The opponent chooses the card
	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);

	return true;
}

void CGraveBirthingCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			return;
		}
}

CGripOfDesolationCard::CGripOfDesolationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grip of Desolation"), CardType::Instant, nID)
{
	SetDevoid();

	// Exile target creature and target land (as Fumarole: the spell targets the creature; when it resolves it moves
	// to the internal _Tokens zone, where two triggered abilities exile the target land and put this card into the graveyard)
	// Note: the land is chosen when the spell resolves.
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetToZoneIfSuccess(ZoneId::_Tokens, TRUE);

		AddSpell(cpSpell.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Stack, ZoneId::_Tokens));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::_Tokens);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Graveyard);
		cpAbility->SetSkipStack(TRUE);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Stack, ZoneId::_Tokens));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		cpAbility->SetSkipStack(TRUE);

		AddAbility(cpAbility.GetPointer());
	}
}

CHorriblyAwryCard::CHorriblyAwryCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Horribly Awry"), CardType::Instant, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Instant,
		new AnyCreatureComparer)
{
	SetDevoid();

	// Counter target creature spell with mana value 4 or less; exile it instead of putting it into its owner's graveyard
	m_pCounterSpell->GetCounterspellCardFilter().AddComparer(new ConvertedManaCostComparer<std::less<int>>(5));
	m_pCounterSpell->SetToZone(ZoneId::Exile, TRUE);
}

CNaturalConnectionCard::CNaturalConnectionCard(CGame* pGame, UINT nID)
	: CSearchLibrarySpellCard(pGame, _T("Natural Connection"), CardType::Instant, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Instant,
		CCardFilter::GetFilter(_T("basic lands")),
		ZoneId::Battlefield, FALSE, TRUE, TRUE)
{
	m_pSearchLibrarySpell->SetSearchCount(MinimumValue(0), MaximumValue(1));
}

COutnumberCard::COutnumberCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Outnumber"), CardType::Instant, nID)
{
	// Deals damage to target creature equal to the number of creatures you control (as Spitting Earth)
	counted_ptr<CTargetChgLifeBySurveySpell> cpSpell(
		::CreateObject<CTargetChgLifeBySurveySpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			ZoneId::Battlefield, TRUE,
			new AnyCreatureComparer, PreventableType::Preventable));

	AddSpell(cpSpell.GetPointer());
}

CRoilsRetributionCard::CRoilsRetributionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Roil's Retribution"), CardType::Instant, nID)
{
	// Deals 5 damage divided as you choose among any number of target attacking or blocking creatures (as Arc Trail)
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-5), PreventableType::Preventable));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingBlockingCreatureComparer);
	cpSpell->GetTargeting()->SetDistributeValues();
	cpSpell->GetTargeting()->SetSubjectCount(1, 5);
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);

	AddSpell(cpSpell.GetPointer());
}

CScourFromExistenceCard::CScourFromExistenceCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Scour from Existence"), CardType::Instant, nID,
		_T("7"), AbilityType::Instant,
		new TrueCardComparer,
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
{
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CSpellShrivelCard::CSpellShrivelCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Spell Shrivel"), CardType::Instant, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	SetDevoid();

	// Counter target spell unless its controller pays {4}; exile it instead of putting it into its owner's graveyard
	m_pCounterSpell->SetCanBeDenied();
	m_pCounterSpell->GetDenialCost().SetManaCost(_T("4"));
	m_pCounterSpell->SetToZone(ZoneId::Exile, TRUE);
}

CStonefuryCard::CStonefuryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stonefury"), CardType::Instant, nID)
{
	// Deals damage to target creature equal to the number of lands you control (as Spitting Earth)
	counted_ptr<CTargetChgLifeBySurveySpell> cpSpell(
		::CreateObject<CTargetChgLifeBySurveySpell>(this, AbilityType::Instant,
			_T("3") RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			ZoneId::Battlefield, TRUE,
			new CardTypeComparer(CardType::_Land, false), PreventableType::Preventable));

	AddSpell(cpSpell.GetPointer());
}

CSureStrikeCard::CSureStrikeCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Sure Strike"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") RED_MANA_TEXT,
		Power(+3), Life(+0),
		CreatureKeyword::FirstStrike, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
}

CSwellOfGrowthCard::CSwellOfGrowthCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Swell of Growth"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") GREEN_MANA_TEXT,
		Power(+2), Life(+2),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CSwellOfGrowthCard::OnResolutionCompleted))
	, m_LandSelection(pGame, CSelectionSupport::SelectionCallback(this, &CSwellOfGrowthCard::OnLandSelected))
{
	m_pTargetChgPwrTghAttrSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
}

void CSwellOfGrowthCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	// You may put a land card from your hand onto the battlefield
	CPlayer* pController = pAbilityAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pHand->GetSize(); ++i)
	{
		CCard* pCard = pHand->GetAt(i);
		if (!pCard->GetCardType().IsLand())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
		m_LandSelection.AddSelectionRequest(entries, 0, 1, this, pController);
}

void CSwellOfGrowthCard::OnLandSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Battlefield, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			return;
		}
}

CTandemTacticsCard::CTandemTacticsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Tandem Tactics"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") WHITE_MANA_TEXT,
		Power(+1), Life(+2),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Up to two target creatures each get +1/+2 until end of turn. You gain 2 life.
	m_pTargetChgPwrTghAttrSpell->GetTargeting()->SetSubjectCount(1, 2);
	m_pTargetChgPwrTghAttrSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+2), this, PreventableType::NotPreventable));
	m_pTargetChgPwrTghAttrSpell->AddAbilityTag(AbilityTag::LifeGain);
}

CTurnAgainstCard::CTurnAgainstCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Turn Against"), CardType::Instant, nID)
{
	SetDevoid();

	// Gain control of target creature until end of turn. Untap that creature. It gains haste until end of turn. (as Threaten)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("4") RED_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpSpell->GetTargetModifier().CCardModifiers::push_back(
		new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);

	cpSpell->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	cpSpell->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep1);

	AddSpell(cpSpell.GetPointer());
}

CUnnaturalAggressionCard::CUnnaturalAggressionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unnatural Aggression"), CardType::Instant, nID)
{
	SetDevoid();

	counted_ptr<CUnnaturalAggressionSpell> cpSpell(
		::CreateObject<CUnnaturalAggressionSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT));

	AddSpell(cpSpell.GetPointer());
}

CUnnaturalAggressionCard::CUnnaturalAggressionSpell::CUnnaturalAggressionSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost)
	: CDoubleTargetSpell(pCard, abilityType, strManaCost,
		new AnyCreatureComparer, false,
		new AnyCreatureComparer, false,
		_T(""))
{
	// Target creature you control fights target creature an opponent controls (as Prey Upon)
	GetTargeting1()->SetDefaultCharacteristic(Characteristic::Neutral);
	GetTargeting1()->SetIncludeControllerCardsOnly();
	GetTargeting2()->SetDefaultCharacteristic(Characteristic::Neutral);
	GetTargeting2()->SetIncludeNonControllerCardsOnly();
}

void CUnnaturalAggressionCard::CUnnaturalAggressionSpell::ResolveGroup(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2,
																	   const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2)
{
	if (!pContainer1.GetSize() || !pContainer2.GetSize()) return;

	CCreatureCard* pCreature1 = dynamic_cast<CCreatureCard*>(pContainer1.GetAt(0));
	CCreatureCard* pCreature2 = dynamic_cast<CCreatureCard*>(pContainer2.GetAt(0));
	if (!pCreature1 || !pCreature2) return;

	// Fight as CFightsModifier does, but if the creature an opponent controls would die this turn, exile it instead
	int nPower1 = GET_INTEGER(pCreature1->GetPower());
	int nPower2 = GET_INTEGER(pCreature2->GetPower());

	CLifeModifier pLifeModifier1 = CLifeModifier(Life(-nPower1), pCreature1, PreventableType::Preventable,
		DamageType::NonCombatDamage | DamageType::ToExileDamage, TRUE);
	CLifeModifier pLifeModifier2 = CLifeModifier(Life(-nPower2), pCreature2, PreventableType::Preventable,
		DamageType::NonCombatDamage, TRUE);

	pLifeModifier1.ApplyTo(pCreature2);
	pLifeModifier2.ApplyTo(pCreature1);
}

CVolcanicUpheavalCard::CVolcanicUpheavalCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Volcanic Upheaval"), CardType::Instant, nID,
		_T("3") RED_MANA_TEXT, AbilityType::Instant,
		new CardTypeComparer(CardType::_Land, false),
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

//____________________________________________________________________________
//
// Eldrazi creatures

struct ColorlessCreatureComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && IsColorless(pCard);
	}

	virtual ColorlessCreatureComparer* Clone() const
	{
		return new ColorlessCreatureComparer;
	}
};

// Does pPlayer control a colorless creature other than pCard?
static bool ControlsAnotherColorlessCreature(const CPlayer* pPlayer, const CCard* pCard)
{
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pOther = pBattlefield->GetAt(i);
		if (pOther != pCard && pOther->GetCardType().IsCreature() && IsColorless(pOther))
			return true;
	}
	return false;
}

// Scry N for pPlayer (as in Theros / Preordain)
static void ApplyScry(CGame* pGame, CPlayer* pPlayer, CCard* pSource, int nCount)
{
	CZoneModifier* pModifier = new CDrawCardModifier(pGame, MinimumValue(nCount), MaximumValue(nCount));
		pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
		pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
		pModifier->GetSelection(0).moveType = MoveType::Others;
		pModifier->AddSelection(MinimumValue(0), MaximumValue(nCount), // select cards to bottom
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			NULL,									// any cards
			ZoneId::Library,						// if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Bottom,					// put selected cards on the bottom
			MoveType::Others,						// move type
			CZoneModifier::RoleType::PrimaryPlayer);// order selected cards by this player

		// and finally put the last ones on top of the library
		pModifier->SetReorderInformation(
			true,
			ZoneId::Library,
			CZoneModifier::RoleType::PrimaryPlayer,	// this player's library
			CardPlacement::Top);
	pModifier->ApplyTo(pPlayer);

	CSpecialEffectModifier pScryModifier = CSpecialEffectModifier(pSource, SCRY_TRIGGER_ID);
	pScryModifier.ApplyTo(pSource);
}

// Exile the top nCount cards of pPlayer's library
static void ExileTopOfLibrary(CPlayer* pPlayer, int nCount)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others);

	for (int i = 0; i < nCount && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
}

CBaneOfBalaGedCard::CBaneOfBalaGedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bane of Bala Ged"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("7"), Power(7), Life(5))
{
	// Whenever this creature attacks, defending player exiles two permanents they control (as Annihilator)
	typedef
		TTriggeredSubjectAbility< CTriggeredMoveCardAbility, CWhenSelfAttackedBlocked,
								CWhenSelfAttackedBlocked::AttackEventCallback,
								&CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);

	cpAbility->GetGatherer().SetIncludeControllerCardsOnly();
	cpAbility->GetGatherer().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetGatherer().SetSubjectCount(2, 2, true);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

	AddAbility(cpAbility.GetPointer());
}

CBarrageTyrantCard::CBarrageTyrantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Barrage Tyrant"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("4") RED_MANA_TEXT, Power(5), Life(3))
	, m_SacrificeFilter(_T("another colorless creature"), _T("other colorless creatures"), new ColorlessCreatureComparer)
{
	SetDevoid();

	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// {2}{R}, Sacrifice another colorless creature: deals damage equal to the sacrificed creature's power to any target (as Fling)
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell2>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell2>>(this,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			&m_SacrificeFilter,
			PreventableType::Preventable, DamageType::AbilityDamage | DamageType::NonCombatDamage));

	AddAbility(cpAbility.GetPointer());
}

CBenthicInfiltratorCard::CBenthicInfiltratorCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Benthic Infiltrator"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") BLUE_MANA_TEXT,
		Power(1), Life(4))
{
	SetDevoid();
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

CBreakerOfArmiesCard::CBreakerOfArmiesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Breaker of Armies"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("8"), Power(10), Life(8))
{
	GetCreatureKeyword()->AddLure(FALSE);
}

CBroodButcherCard::CBroodButcherCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Brood Butcher"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") BLACK_MANA_TEXT GREEN_MANA_TEXT,
		Power(3), Life(3), 1)
{
	SetDevoid();

	// {B}{G}, Sacrifice a creature: Target creature gets -2/-2 until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			BLACK_MANA_TEXT GREEN_MANA_TEXT,
			Power(-2), Life(-2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	AddAbility(cpAbility.GetPointer());
}

CCatacombSifterCard::CCatacombSifterCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Catacomb Sifter"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT,
		Power(2), Life(3), 1)
{
	SetDevoid();

	// Whenever another creature you control dies, scry 1.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CCatacombSifterCard::BeforeScry));

	AddAbility(cpAbility.GetPointer());
}

bool CCatacombSifterCard::BeforeScry(TriggeredAbility::TriggeredActionType* pAction) const
{
	ApplyScry(GetGame(), GetController(), (CCard*)this, 1);
	return true;
}

CDesolationTwinCard::CDesolationTwinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Desolation Twin"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("10"), Power(10), Life(10))
{
	// When you cast this spell, create a 10/10 colorless Eldrazi creature token.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi (A)"), 55059, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CDominatorDroneCard::CDominatorDroneCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Dominator Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") BLACK_MANA_TEXT,
		Power(3), Life(2))
{
	SetDevoid();

	// When this creature enters, if you control another colorless creature, each opponent loses 2 life.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDominatorDroneCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);

	AddAbility(cpAbility.GetPointer());
}

bool CDominatorDroneCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return ControlsAnotherColorlessCreature(GetController(), this);
}

CDrownerOfHopeCard::CDrownerOfHopeCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Drowner of Hope"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("5") BLUE_MANA_TEXT,
		Power(5), Life(5), 2)
	, m_ScionFilter(_T("an Eldrazi Scion"), _T("Eldrazi Scions"), new CreatureTypeComparer(CREATURE_TYPE(Scion), false))
{
	SetDevoid();

	// Sacrifice an Eldrazi Scion: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			_T(""),
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_ScionFilter);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	AddAbility(cpAbility.GetPointer());
}

CDustStalkerCard::CDustStalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dust Stalker"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(5), Life(3))
{
	SetDevoid();
	GetCreatureKeyword()->AddHaste(FALSE);

	// At the beginning of each end step, if you control no other colorless creatures, return this creature to its owner's hand.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDustStalkerCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDustStalkerCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Hand));

	AddAbility(cpAbility.GetPointer());
}

bool CDustStalkerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pNode) const
{
	return GetZoneId() == ZoneId::Battlefield && !ControlsAnotherColorlessCreature(GetController(), this);
}

bool CDustStalkerCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const
{
	// The condition is checked again on resolution
	if (GetZoneId() == ZoneId::Battlefield && !ControlsAnotherColorlessCreature(GetController(), this))
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo((CCard*)this);
	}
	return true;
}

CEldraziDevastatorCard::CEldraziDevastatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eldrazi Devastator"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("8"), Power(8), Life(9))
{
	GetCreatureKeyword()->AddTrample(FALSE);
}

CEndlessOneCard::CEndlessOneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Endless One"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("0"), Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CEndlessOneCard::OnZoneChanged))
{
	// {X}: This creature enters with X +1/+1 counters on it (as Chalice of the Void)
	GetSpells().GetAt(0)->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors);

	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CEndlessOneCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType == MoveType::Cast)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +GetLastCastingExtraValue());
		pModifier.ApplyTo(this);
	}
}

CFathomFeederCard::CFathomFeederCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Fathom Feeder"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, BLUE_MANA_TEXT BLACK_MANA_TEXT,
		Power(1), Life(1))
{
	SetDevoid();
	GetCardKeyword()->AddDeathtouch(FALSE);

	// {3}{U}{B}: Draw a card. Each opponent exiles the top card of their library.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("3") BLUE_MANA_TEXT BLACK_MANA_TEXT, 1));

	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFathomFeederCard::BeforeResolution));

	AddAbility(cpAbility.GetPointer());
}

bool CFathomFeederCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		if (GetGame()->GetPlayer(i) != pController)
			ExileTopOfLibrary(GetGame()->GetPlayer(i), 1);

	return true;
}

CForerunnerOfSlaughterCard::CForerunnerOfSlaughterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Forerunner of Slaughter"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(2))
{
	SetDevoid();

	// {1}: Target colorless creature gains haste until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("1"),
			Power(+0), Life(+0),
			CreatureKeyword::Haste, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new ColorlessCreatureComparer);

	AddAbility(cpAbility.GetPointer());
}

CIncubatorDroneCard::CIncubatorDroneCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Incubator Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") BLUE_MANA_TEXT,
		Power(2), Life(3), 1)
{
	SetDevoid();
}

CKozileksChannelerCard::CKozileksChannelerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kozilek's Channeler"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("5"), Power(4), Life(4))
{
	// {T}: Add {C}{C}.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("2")));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CKozileksSentinelCard::CKozileksSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kozilek's Sentinel"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") RED_MANA_TEXT, Power(1), Life(4))
{
	SetDevoid();

	// Whenever you cast a colorless spell, this creature gets +1/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CardTypeComparer(CardType::_ColorMask, false)));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CNettleDroneCard::CNettleDroneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nettle Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") RED_MANA_TEXT, Power(3), Life(1))
{
	SetDevoid();

	{
		// {T}: This creature deals 1 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNettleDroneCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast a colorless spell, untap this creature.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new NegateCardComparer(new CardTypeComparer(CardType::_ColorMask, false)));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CNettleDroneCard::BeforeUntap));
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CNettleDroneCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(i);
		if (pPlayer == pController)
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}

	return true;
}

bool CNettleDroneCard::BeforeUntap(TriggeredAbility::TriggeredActionType* pAction) const
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetOrientation()->Untap();
	return true;
}

CRuinationGuideCard::CRuinationGuideCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Ruination Guide"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") BLUE_MANA_TEXT,
		Power(3), Life(2))
{
	SetDevoid();

	// Other colorless creatures you control get +1/+0.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new ColorlessCreatureComparer,
			Power(+1), Life(+0)));

	cpAbility->GetEnchantmentCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetAffectControllerCardsOnly();

	AddAbility(cpAbility.GetPointer());
}

CSalvageDroneCard::CSalvageDroneCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Salvage Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, BLUE_MANA_TEXT,
		Power(1), Life(1))
{
	SetDevoid();

	// When this creature dies, you may draw a card. If you do, discard a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetDrawCount(1);
	cpAbility->SetDiscard(1, FALSE, MoveType::Discard);

	AddAbility(cpAbility.GetPointer());
}

CSilentSkimmerCard::CSilentSkimmerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Silent Skimmer"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") BLACK_MANA_TEXT, Power(0), Life(4))
{
	SetDevoid();

	// Whenever this creature attacks, defending player loses 2 life.
	// Note: affects each opponent (the defending player in a two-player game)
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);

	AddAbility(cpAbility.GetPointer());
}

CSireOfStagnationCard::CSireOfStagnationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sire of Stagnation"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(7))
{
	SetDevoid();

	// Whenever a land an opponent controls enters, that player exiles the top two cards of their library and you draw two cards.
	// Note: the cards are exiled when the ability triggers
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(2);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSireOfStagnationCard::SetTriggerContext));

	AddAbility(cpAbility.GetPointer());
}

bool CSireOfStagnationCard::SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext,
											  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	ExileTopOfLibrary(pCard->GetController(), 2);
	return true;
}

CSludgeCrawlerCard::CSludgeCrawlerCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Sludge Crawler"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, BLACK_MANA_TEXT,
		Power(1), Life(1))
{
	SetDevoid();

	// {2}: This creature gets +1/+1 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("2"), Power(+1), Life(+1)));

	AddAbility(cpAbility.GetPointer());
}

CTideDrifterCard::CTideDrifterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tide Drifter"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLUE_MANA_TEXT, Power(0), Life(5))
{
	SetDevoid();

	// Other colorless creatures you control get +0/+1.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new ColorlessCreatureComparer,
			Power(+0), Life(+1)));

	cpAbility->GetEnchantmentCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetAffectControllerCardsOnly();

	AddAbility(cpAbility.GetPointer());
}

CUlamogTheCeaselessHungerCard::CUlamogTheCeaselessHungerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ulamog, the Ceaseless Hunger"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Eldrazi), nID, _T("10"), Power(10), Life(10))
{
	GetCardKeyword()->AddIndestructible(FALSE);

	// When you cast this spell, exile two target permanents (as Ulamog, the Infinite Gyre).
	// Note: done as two cast triggers with one target each, so both could target the same permanent.
	for (int i = 0; i < 2; ++i)
	{
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this,
				ZoneId::_AllZones, ZoneId::Stack));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever Ulamog attacks, defending player exiles the top twenty cards of their library.
		counted_ptr<AttackAbility> cpAbility(::CreateObject<AttackAbility>(this));

		cpAbility->SetOptionalType(AttackAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->SetBeforeResolveSelectionCallback(AttackAbility::BeforeResolveSelectionCallback(this, &CUlamogTheCeaselessHungerCard::BeforeAttackResolution));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Exile));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CUlamogTheCeaselessHungerCard::BeforeAttackResolution(AttackAbility::TriggeredActionType* pAction) const
{
	ExileTopOfLibrary(pAction->GetTriggeredPlayer(), 20);
	return true;
}

CVestigeOfEmrakulCard::CVestigeOfEmrakulCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vestige of Emrakul"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") RED_MANA_TEXT, Power(3), Life(4))
{
	SetDevoid();
	GetCreatureKeyword()->AddTrample(FALSE);
}

CVileAggregateCard::CVileAggregateCard(CGame* pGame, UINT nID)
	: CIngestCreatureCard(pGame, _T("Vile Aggregate"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") RED_MANA_TEXT,
		Power(0), Life(5))
{
	SetDevoid();
	GetCreatureKeyword()->AddTrample(FALSE);

	// Vile Aggregate's power is equal to the number of colorless creatures you control (as Nightmare).
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new ColorlessCreatureComparer));

	cpAbility->SetChangePowerOnly();

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Processors
// Note: a processing cost of a spell or activated ability is checked when it is cast or activated,
// and the cards are put into the graveyard when it resolves.

CProcessorAssaultCard::CProcessorAssaultCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Processor Assault"), CardType::Sorcery, nID)
	, m_Process(this, 1)
{
	SetDevoid();

	// As an additional cost to cast this spell, put a card an opponent owns from exile into that player's graveyard.
	// Processor Assault deals 5 damage to target creature.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-5), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CProcessorAssaultCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CProcessorAssaultCard::CanPlay)));
	cpSpell->Add(cpTrait.GetPointer());

	AddSpell(cpSpell.GetPointer());
}

BOOL CProcessorAssaultCard::CanPlay(BOOL bIncludeTricks)
{
	return m_Process.CanPay(GetController());
}

bool CProcessorAssaultCard::BeforeResolution(CAbilityAction* pAction)
{
	return m_Process.Pay(pAction->GetController()) != FALSE;
}

CCrypticCruiserCard::CCrypticCruiserCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cryptic Cruiser"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("3") BLUE_MANA_TEXT, Power(3), Life(3))
	, m_Process(this, 1)
{
	SetDevoid();

	// {2}{U}, Put a card an opponent owns from exile into that player's graveyard: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			_T("2") BLUE_MANA_TEXT,
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrypticCruiserCard::BeforeResolution));

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CCrypticCruiserCard::CanPlay)));
	cpAbility->Add(cpTrait.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

BOOL CCrypticCruiserCard::CanPlay(BOOL bIncludeTricks)
{
	return m_Process.CanPay(GetController());
}

bool CCrypticCruiserCard::BeforeResolution(CAbilityAction* pAction)
{
	return m_Process.Pay(pAction->GetController()) != FALSE;
}

COracleOfDustCard::COracleOfDustCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oracle of Dust"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("4") BLUE_MANA_TEXT, Power(3), Life(5))
	, m_Process(this, 1)
{
	SetDevoid();

	// {2}, Put a card an opponent owns from exile into that player's graveyard: Draw a card, then discard a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("2"), 1));

	cpAbility->SetDiscard(1, FALSE);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COracleOfDustCard::BeforeResolution));

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &COracleOfDustCard::CanPlay)));
	cpAbility->Add(cpTrait.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

BOOL COracleOfDustCard::CanPlay(BOOL bIncludeTricks)
{
	return m_Process.CanPay(GetController());
}

bool COracleOfDustCard::BeforeResolution(CAbilityAction* pAction)
{
	return m_Process.Pay(pAction->GetController()) != FALSE;
}

CVoidAttendantCard::CVoidAttendantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Void Attendant"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("2") GREEN_MANA_TEXT, Power(2), Life(3))
	, m_Process(this, 1)
{
	SetDevoid();

	// {1}{G}, Put a card an opponent owns from exile into that player's graveyard: Create a 1/1 colorless Eldrazi Scion creature token.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("1") GREEN_MANA_TEXT,
			_T("Eldrazi Scion (A)"), 55056,
			1));

	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVoidAttendantCard::BeforeResolution));

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CVoidAttendantCard::CanPlay)));
	cpAbility->Add(cpTrait.GetPointer());

	AddAbility(cpAbility.GetPointer());
}

BOOL CVoidAttendantCard::CanPlay(BOOL bIncludeTricks)
{
	return m_Process.CanPay(GetController());
}

bool CVoidAttendantCard::BeforeResolution(CAbilityAction* pAction)
{
	return m_Process.Pay(pAction->GetController()) != FALSE;
}

CBlightHerderCard::CBlightHerderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blight Herder"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("5"), Power(4), Life(5))
	, m_Process(this, 2)
{
	// When you cast this spell, you may put two cards your opponents own from exile into their owners' graveyards.
	// If you do, create three 1/1 colorless Eldrazi Scion creature tokens.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Scion (A)"), 55056, 3);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBlightHerderCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CBlightHerderCard::Process));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

bool CBlightHerderCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CBlightHerderCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

CRuinProcessorCard::CRuinProcessorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ruin Processor"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("7"), Power(7), Life(8))
	, m_Process(this, 1)
{
	// When you cast this spell, you may put a card an opponent owns from exile into that player's graveyard. If you do, you gain 5 life.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+5));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRuinProcessorCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CRuinProcessorCard::Process));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);

	AddAbility(cpAbility.GetPointer());
}

bool CRuinProcessorCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CRuinProcessorCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

CMindRakerCard::CMindRakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mind Raker"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("3") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_Process(this, 1)
	, m_DiscardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CMindRakerCard::OnDiscardSelected))
{
	SetDevoid();

	// When this creature enters, you may put a card an opponent owns from exile into that player's graveyard.
	// If you do, each opponent discards a card.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMindRakerCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CMindRakerCard::Process));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Hand, ZoneId::Graveyard));

	AddAbility(cpAbility.GetPointer());
}

bool CMindRakerCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CMindRakerCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pController = GetController();

	if (!m_Process.Pay(pController))
		return false;

	// Each opponent discards a card of their choice
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CZone* pHand = pOpponent->GetZoneById(ZoneId::Hand);

		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pHand->GetSize(); ++i)
		{
			CCard* pCard = pHand->GetAt(i);

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));

			entries.push_back(entry);
		}

		if (!entries.empty())
			m_DiscardSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);
	}

	return true;
}

void CMindRakerCard::OnDiscardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			return;
		}
}

CMurkStriderCard::CMurkStriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Murk Strider"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("3") BLUE_MANA_TEXT, Power(3), Life(2))
	, m_Process(this, 1)
{
	SetDevoid();

	// When this creature enters, you may put a card an opponent owns from exile into that player's graveyard.
	// If you do, return target creature to its owner's hand.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMurkStriderCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CMurkStriderCard::Process));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Hand));

	AddAbility(cpAbility.GetPointer());
}

bool CMurkStriderCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CMurkStriderCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

CUlamogsReclaimerCard::CUlamogsReclaimerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ulamog's Reclaimer"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("4") BLUE_MANA_TEXT, Power(2), Life(5))
	, m_Process(this, 1)
{
	SetDevoid();

	// When this creature enters, you may put a card an opponent owns from exile into that player's graveyard.
	// If you do, return target instant or sorcery card from your graveyard to your hand.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUlamogsReclaimerCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CUlamogsReclaimerCard::Process));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));

	AddAbility(cpAbility.GetPointer());
}

bool CUlamogsReclaimerCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CUlamogsReclaimerCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

CWastelandStranglerCard::CWastelandStranglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wasteland Strangler"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("2") BLACK_MANA_TEXT, Power(3), Life(2))
	, m_Process(this, 1)
{
	SetDevoid();

	// When this creature enters, you may put a card an opponent owns from exile into that player's graveyard.
	// If you do, target creature gets -3/-3 until end of turn.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-3));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(-3));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage);
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWastelandStranglerCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CWastelandStranglerCard::Process));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CWastelandStranglerCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CWastelandStranglerCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

CUlamogsDespoilerCard::CUlamogsDespoilerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ulamog's Despoiler"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("6"), Power(5), Life(5))
	, m_Process(this, 2)
{
	// As this creature enters, you may put two cards your opponents own from exile into their owners' graveyards.
	// If you do, this creature enters with four +1/+1 counters on it.
	// Note: done as a triggered ability when it enters, not as a replacement effect.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +4, false));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUlamogsDespoilerCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CUlamogsDespoilerCard::Process));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CUlamogsDespoilerCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CUlamogsDespoilerCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

CUlamogsNullifierCard::CUlamogsNullifierCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Ulamog's Nullifier"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Processor), nID, _T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
	, m_Process(this, 2)
{
	SetDevoid();
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, you may put two cards your opponents own from exile into their owners' graveyards.
	// If you do, counter target spell.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionCost(_T(""));

	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Stack);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new CardKeywordComparer(CardKeyword::CantBeCountered, false)));

	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUlamogsNullifierCard::CanProcess));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CUlamogsNullifierCard::Process));

	AddAbility(cpAbility.GetPointer());
}

bool CUlamogsNullifierCard::CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Process.CanPay(GetController()) != FALSE;
}

bool CUlamogsNullifierCard::Process(TriggeredAbility::TriggeredActionType* pAction)
{
	return m_Process.Pay(GetController()) != FALSE;
}

//____________________________________________________________________________
//
// Other creatures

// Landfall - Whenever a land you control enters, ...
// Creates the triggered ability with the landfall trigger; the caller sets the effect and adds it.
template <class TriggeredAbility>
static counted_ptr<TriggeredAbility> CreateLandfallAbility(CCard* pCard)
{
	counted_ptr<TriggeredAbility> cpAbility(
		::CreateObject<TriggeredAbility>(pCard, ZoneId::_AllZones, ZoneId::Battlefield));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
	return cpAbility;
}

CLandfallPumpCreatureCard::CLandfallPumpCreatureCard(CGame* pGame, LPCTSTR strCardName, const CreatureType& creatureType, UINT uID,
													 LPCTSTR strCostText, Power nPower, Life nToughness,
													 Power nPowerDelta, Life nLifeDelta, CreatureKeyword landfallKeyword)
	: CCreatureCard(pGame, strCardName, CardType::Creature, creatureType, uID, strCostText, nPower, nToughness)
{
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->GetPowerModifier().SetPowerDelta(nPowerDelta);
	cpAbility->GetLifeModifier().SetLifeDelta(nLifeDelta);
	if (landfallKeyword != CreatureKeyword::Null)
	{
		cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(landfallKeyword);
		cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	}
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CBelligerentWhiptailCard::CBelligerentWhiptailCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Belligerent Whiptail"), CREATURE_TYPE(Wurm), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(2), Power(+0), Life(+0), CreatureKeyword::FirstStrike)
{
}

CGeyserfieldStalkerCard::CGeyserfieldStalkerCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Geyserfield Stalker"), CREATURE_TYPE(Elemental), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(2), Power(+2), Life(+2))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE); // Menace
}

CGroveRumblerCard::CGroveRumblerCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Grove Rumbler"), CREATURE_TYPE(Elemental), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3), Power(+2), Life(+2))
{
	GetCreatureKeyword()->AddTrample(FALSE);
}

CMakindiSliderunnerCard::CMakindiSliderunnerCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Makindi Sliderunner"), CREATURE_TYPE(Beast), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1), Power(+1), Life(+1))
{
	GetCreatureKeyword()->AddTrample(FALSE);
}

COnduGreathornCard::COnduGreathornCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Ondu Greathorn"), CREATURE_TYPE(Beast), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(3), Power(+2), Life(+2))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);
}

CScytheLeopardCard::CScytheLeopardCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Scythe Leopard"), CREATURE_TYPE(Cat), nID,
		GREEN_MANA_TEXT, Power(1), Life(1), Power(+1), Life(+1))
{
}

CSnappingGnarlidCard::CSnappingGnarlidCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Snapping Gnarlid"), CREATURE_TYPE(Beast), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2), Power(+1), Life(+1))
{
}

CValakutPredatorCard::CValakutPredatorCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Valakut Predator"), CREATURE_TYPE(Elemental), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2), Power(+2), Life(+2))
{
}

CWaveWingElementalCard::CWaveWingElementalCard(CGame* pGame, UINT nID)
	: CLandfallPumpCreatureCard(pGame, _T("Wave-Wing Elemental"), CREATURE_TYPE(Elemental), nID,
		_T("5") BLUE_MANA_TEXT, Power(3), Life(4), Power(+2), Life(+2))
{
	GetCreatureKeyword()->AddFlying(FALSE);
}

CAkoumStonewakerCard::CAkoumStonewakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Akoum Stonewaker"), CardType::Creature,
		CREATURE_TYPE2(Human, Shaman), nID, _T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Landfall - you may pay {2}{R}. If you do, create a 3/1 red Elemental creature token with trample and haste.
	// Exile that token at the beginning of the next end step (the token itself does it).
	typedef TTriggeredAbility<CTriggeredCreateTokenAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->SetResolutionCost(_T("2") RED_MANA_TEXT);
	cpAbility->SetCreateTokenOption(TRUE, _T("Elemental (Y)"), 55063, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CCarrierThrallCard::CCarrierThrallCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Carrier Thrall"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// When this creature dies, create a 1/1 colorless Eldrazi Scion creature token (as Blisterpod)
	typedef TTriggeredAbility<CTriggeredCreateTokenAbility, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Scion (A)"), 55056, 1);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CCourierGriffinCard::CCourierGriffinCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Courier Griffin"), CardType::Creature,
		CREATURE_TYPE(Griffin), nID, _T("3") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, you gain 2 life.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+2));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CFelidarCubCard::CFelidarCubCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Felidar Cub"), CardType::Creature,
		CREATURE_TYPE2(Cat, Beast), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Sacrifice this creature: Destroy target enchantment.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T(""),
			new CardTypeComparer(CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CJaddiOffshootCard::CJaddiOffshootCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jaddi Offshoot"), CardType::Creature,
		CREATURE_TYPE(Plant), nID, GREEN_MANA_TEXT, Power(0), Life(3))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	// Landfall - you gain 1 life.
	typedef TTriggeredAbility<CTriggeredModifyLifeAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CLavastepRaiderCard::CLavastepRaiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lavastep Raider"), CardType::Creature,
		CREATURE_TYPE2(Goblin, Warrior), nID, RED_MANA_TEXT, Power(1), Life(2))
{
	// {2}{R}: This creature gets +2/+0 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("2") RED_MANA_TEXT, Power(+2), Life(+0)));
	AddAbility(cpAbility.GetPointer());
}

CLifespringDruidCard::CLifespringDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lifespring Druid"), CardType::Creature,
		CREATURE_TYPE2(Elf, Druid), nID, _T("2") GREEN_MANA_TEXT, Power(2), Life(1))
{
	// {T}: Add one mana of any color (as Birds of Paradise)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CMurasaRangerCard::CMurasaRangerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Murasa Ranger"), CardType::Creature,
		CREATURE_TYPE2(Human, Warrior), nID, _T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Landfall - you may pay {3}{G}. If you do, put two +1/+1 counters on this creature.
	typedef TTriggeredAbility<CTriggeredModifyCardAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->SetResolutionCost(_T("3") GREEN_MANA_TEXT);
	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +2, false));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

COranRiefInvokerCard::COranRiefInvokerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oran-Rief Invoker"), CardType::Creature,
		CREATURE_TYPE2(Human, Shaman), nID, _T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {8}: This creature gets +5/+5 and gains trample until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("8"), Power(+5), Life(+5), CreatureKeyword::Trample));
	AddAbility(cpAbility.GetPointer());
}

CPlatedCrusherCard::CPlatedCrusherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Plated Crusher"), CardType::Creature,
		CREATURE_TYPE(Beast), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(6))
{
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCardKeyword()->AddHexproof(FALSE);
}

CRotShamblerCard::CRotShamblerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rot Shambler"), CardType::Creature,
		CREATURE_TYPE(Fungus), nID, _T("1") GREEN_MANA_TEXT, Power(1), Life(1))
{
	// Whenever another creature you control dies, put a +1/+1 counter on this creature.
	typedef TTriggeredAbility<CTriggeredModifyCardAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1, false));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CStoneHavenMedicCard::CStoneHavenMedicCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stone Haven Medic"), CardType::Creature,
		CREATURE_TYPE2(Kor, Cleric), nID, _T("1") WHITE_MANA_TEXT, Power(1), Life(3))
{
	// {W}, {T}: You gain 1 life.
	counted_ptr<CActivatedAbility<CChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CChgLifeSpell>>(this,
			WHITE_MANA_TEXT,
			Life(+1), PreventableType::NotPreventable));

	cpAbility->AddTapCost();
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CTunnelingGeopedeCard::CTunnelingGeopedeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tunneling Geopede"), CardType::Creature,
		CREATURE_TYPE(Insect), nID, _T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// Landfall - this creature deals 1 damage to each opponent.
	typedef TTriggeredAbility<CTriggeredModifyLifeAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

CValakutInvokerCard::CValakutInvokerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Valakut Invoker"), CardType::Creature,
		CREATURE_TYPE2(Human, Shaman), nID, _T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// {8}: This creature deals 3 damage to any target.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("8"), new AnyCreatureComparer, TRUE,
			Life(-3), PreventableType::Preventable));

	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	AddAbility(cpAbility.GetPointer());
}

CVoraciousNullCard::CVoraciousNullCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Voracious Null"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_SacrificeFilter(_T("another creature"), _T("other creatures"), new AnyCreatureComparer)
{
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	// {1}{B}, Sacrifice another creature: Put two +1/+1 counters on this creature. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") BLACK_MANA_TEXT));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +2, false));
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CAkoumHellkiteCard::CAkoumHellkiteCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Akoum Hellkite"), CardType::Creature,
		CREATURE_TYPE(Dragon), nID, _T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// Landfall - this creature deals 1 damage to any target. If that land is a Mountain, it deals 2 damage instead.
	typedef TTriggeredTargetAbility<CTriggeredModifyLifeAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAkoumHellkiteCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CAkoumHellkiteCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
										   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_LifeModifier.SetLifeDelta((pCard->GetCardType() & CardType::Mountain).Any() ? Life(-2) : Life(-1));
	return true;
}

CGuardianOfTazeemCard::CGuardianOfTazeemCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Guardian of Tazeem"), CardType::Creature,
		CREATURE_TYPE(Sphinx), nID, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(5))
{
	// Landfall - tap target creature an opponent controls. If that land is an Island,
	// that creature doesn't untap during its controller's next untap step.
	typedef TTriggeredTargetAbility<CTriggeredModifyCardAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->GetCardModifiers().push_back(new CCardOrientationModifier(TRUE));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGuardianOfTazeemCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

bool CGuardianOfTazeemCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if ((pCard->GetCardType() & CardType::Island).Any())
	{
		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		triggerContext.m_CardModifiers.push_back(pModifier);
	}
	return true;
}

CGuulDrazOverseerCard::CGuulDrazOverseerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Guul Draz Overseer"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(4))
{
	// Landfall - other creatures you control get +1/+0 until end of turn. If that land is a Swamp, +2/+0 instead.
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->SetModifyCreatureOption(TriggeredAbility::ModifyCreatureOption::ModifyTriggeredPlayersCreatures);
	cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGuulDrazOverseerCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CGuulDrazOverseerCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
											  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_PowerModifier.SetPowerDelta((pCard->GetCardType() & CardType::Swamp).Any() ? Power(+2) : Power(+1));
	return true;
}

COranRiefHydraCard::COranRiefHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oran-Rief Hydra"), CardType::Creature,
		CREATURE_TYPE(Hydra), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Landfall - put a +1/+1 counter on this creature. If that land is a Forest, put two +1/+1 counters instead.
	typedef TTriggeredAbility<CTriggeredModifyCardAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COranRiefHydraCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool COranRiefHydraCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
										   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	int nCounters = (pCard->GetCardType() & CardType::Forest).Any() ? 2 : 1;
	triggerContext.m_CardModifiers.push_back(new CCardCounterModifier(_T("+1/+1"), +nCounters, false));
	return true;
}

COmnathLocusOfRageCard::COmnathLocusOfRageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Omnath, Locus of Rage"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Elemental), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	{
		// Landfall - create a 5/5 red and green Elemental creature token.
		typedef TTriggeredAbility<CTriggeredCreateTokenAbility, CWhenCardMoved> TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(CreateLandfallAbility<TriggeredAbility>(this));
		cpAbility->SetCreateTokenOption(TRUE, _T("Elemental (Z)"), 55065, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever Omnath or another Elemental you control dies, Omnath deals 3 damage to any target.
		typedef TTriggeredTargetAbility<CTriggeredModifyLifeAbility, CWhenCardMoved> TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Elemental), false));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-3));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

CDefiantBloodlordCard::CDefiantBloodlordCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Defiant Bloodlord"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(5))
{
	// Whenever you gain life, target opponent loses that much life. (as Exquisite Blood)
	typedef TTriggeredTargetAbility<CTriggeredModifyLifeAbility, CWhenPlayerLifeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDefiantBloodlordCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	AddAbility(cpAbility.GetPointer());
}

bool CDefiantBloodlordCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											  const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	if (nToLife > nFromLife)
	{
		triggerContext.m_LifeModifier.SetLifeDelta(Life(nFromLife - nToLife));
		triggerContext.m_LifeModifier.SetDamageType(DamageType::NotDealingDamage);
		triggerContext.m_LifeModifier.SetPreventable(PreventableType::NotPreventable);
		return true;
	}
	return false;
}

CMalakirFamiliarCard::CMalakirFamiliarCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Malakir Familiar"), CardType::Creature,
		CREATURE_TYPE(Bat), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(1))
{
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Whenever you gain life, this creature gets +1/+1 until end of turn.
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMalakirFamiliarCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CMalakirFamiliarCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
											 const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return nToLife > nFromLife;
}

CGreenwardenOfMurasaCard::CGreenwardenOfMurasaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Greenwarden of Murasa"), CardType::Creature,
		CREATURE_TYPE(Elemental), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(4))
{
	{
		// When this creature enters, you may return target card from your graveyard to your hand.
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this creature dies, you may exile it. If you do, return target card from your graveyard to your hand.
		counted_ptr<DiesAbility> cpAbility(::CreateObject<DiesAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->SetOptionalType(DiesAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);
		cpAbility->SetBeforeResolveSelectionCallback(DiesAbility::BeforeResolveSelectionCallback(this, &CGreenwardenOfMurasaCard::ExileFromGraveyard));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGreenwardenOfMurasaCard::ExileFromGraveyard(DiesAbility::TriggeredActionType* pAction) const
{
	// "you may exile it. If you do, ..."
	if (GetZoneId() != ZoneId::Graveyard)
		return false;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others);
	pModifier.ApplyTo((CCard*)this);
	return true;
}

CWindriderPatrolCard::CWindriderPatrolCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Windrider Patrol"), CardType::Creature,
		CREATURE_TYPE2(Merfolk, Wizard), nID, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(3))
{
	// Whenever this creature deals combat damage to a player, scry 2.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CWindriderPatrolCard::BeforeScry));
	AddAbility(cpAbility.GetPointer());
}

bool CWindriderPatrolCard::BeforeScry(TriggeredAbility::TriggeredActionType* pAction) const
{
	ApplyScry(GetGame(), GetController(), (CCard*)this, 2);
	return true;
}

//____________________________________________________________________________
//
// Allies (without Rally)

// A card with awaken (any of its spells is an awaken spell)
struct AwakenCardComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		CCard* pNonConstCard = const_cast<CCard*>(pCard);
		for (int i = 0; i < pNonConstCard->GetSpells().GetSize(); ++i)
		{
			CSpell* pSpell = pNonConstCard->GetSpells().GetAt(i);
			if (dynamic_cast<CAwakenSpell*>(pSpell) || dynamic_cast<CAwakenLandSpell*>(pSpell) ||
				dynamic_cast<CAwakenTargetPlayerSpell*>(pSpell) || dynamic_cast<CAwakenCounterSpell*>(pSpell))
				return true;
		}
		return false;
	}

	virtual AwakenCardComparer* Clone() const
	{
		return new AwakenCardComparer;
	}
};

struct LandCreatureComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && pCard->GetCardType().IsLand();
	}

	virtual LandCreatureComparer* Clone() const
	{
		return new LandCreatureComparer;
	}
};

// "Whenever you gain life" (as Exquisite Blood)
#define YOU_GAIN_LIFE (nToLife > nFromLife)

CAngelicCaptainCard::CAngelicCaptainCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angelic Captain"), CardType::Creature,
		CREATURE_TYPE2(Angel, Ally), nID, _T("3") RED_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
{
	// Whenever this creature attacks, it gets +1/+1 until end of turn for each other attacking Ally.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAngelicCaptainCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CAngelicCaptainCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, AttackSubject attacked) const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	CreatureTypeComparer allyComparer(CREATURE_TYPE(Ally), false);

	int nAllies = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard != this && pCard->GetCardType().IsCreature() && allyComparer(pCard) && ((CCreatureCard*)pCard)->IsAttacking())
			++nAllies;
	}

	if (!nAllies)
		return false;

	triggerContext.m_PowerModifier.SetPowerDelta(Power(+nAllies));
	triggerContext.m_LifeModifier.SetLifeDelta(Life(+nAllies));
	return true;
}

CAngelOfRenewalCard::CAngelOfRenewalCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Renewal"), CardType::Creature,
		CREATURE_TYPE2(Angel, Ally), nID, _T("5") WHITE_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you gain 1 life for each creature you control.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAngelOfRenewalCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CAngelOfRenewalCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	int nCreatures = CCardFilter::GetFilter(_T("creatures"))->CountIncluded(
		GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());

	triggerContext.m_LifeModifier.SetLifeDelta(Life(+nCreatures));
	triggerContext.m_LifeModifier.SetPreventable(PreventableType::NotPreventable);
	return nCreatures > 0;
}

CBloodbondVampireCard::CBloodbondVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodbond Vampire"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Shaman, Ally), nID, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// Whenever you gain life, put a +1/+1 counter on this creature.
	typedef TTriggeredAbility<CTriggeredModifyCardAbility, CWhenPlayerLifeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1, false));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodbondVampireCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CBloodbondVampireCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											  const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return YOU_GAIN_LIFE;
}

CCliffsideLookoutCard::CCliffsideLookoutCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cliffside Lookout"), CardType::Creature,
		CREATURE_TYPE3(Kor, Scout, Ally), nID, WHITE_MANA_TEXT, Power(1), Life(1))
{
	// {4}{W}: Creatures you control get +1/+1 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("4") WHITE_MANA_TEXT));

	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCliffsideLookoutCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CCliffsideLookoutCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer pCreatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pCreatures.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));
	}

	return true;
}

CCoralhelmGuideCard::CCoralhelmGuideCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Coralhelm Guide"), CardType::Creature,
		CREATURE_TYPE3(Merfolk, Scout, Ally), nID, _T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// {4}{U}: Target creature can't be blocked this turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("4") BLUE_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::Unblockable, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CDranaLiberatorOfMalakirCard::CDranaLiberatorOfMalakirCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Drana, Liberator of Malakir"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Vampire, Ally), nID, _T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Whenever Drana deals combat damage to a player, put a +1/+1 counter on each attacking creature you control.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDranaLiberatorOfMalakirCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CDranaLiberatorOfMalakirCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer pAttackers;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && ((CCreatureCard*)pCard)->IsAttacking())
			pAttackers.AddCard(pCard, CardPlacement::Top);
	}

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
	for (int i = 0; i < pAttackers.GetSize(); ++i)
		pModifier.ApplyTo(pAttackers.GetAt(i));

	return true;
}

CDranasEmissaryCard::CDranasEmissaryCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Drana's Emissary"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Cleric, Ally), nID, _T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// At the beginning of your upkeep, each opponent loses 1 life and you gain 1 life.
	// Note: triggers once per opponent, so in multiplayer you gain 1 life for each opponent
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetResolutionModifier().CPlayerModifiers::Add(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CHagraSharpshooterCard::CHagraSharpshooterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hagra Sharpshooter"), CardType::Creature,
		CREATURE_TYPE3(Human, Assassin, Ally), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// {4}{B}: Target creature gets -1/-1 until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("4") BLACK_MANA_TEXT,
			Power(-1), Life(-1),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CHalimarTidecallerCard::CHalimarTidecallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Halimar Tidecaller"), CardType::Creature,
		CREATURE_TYPE3(Human, Wizard, Ally), nID, _T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
	{
		// When this creature enters, you may return target card with awaken from your graveyard to your hand.
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AwakenCardComparer);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Land creatures you control have flying.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new LandCreatureComparer,
				Power(+0), Life(+0), CreatureKeyword::Flying));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
}

CKalastriaNightwatchCard::CKalastriaNightwatchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kalastria Nightwatch"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Warrior, Ally), nID, _T("4") BLACK_MANA_TEXT, Power(4), Life(5))
{
	// Whenever you gain life, this creature gains flying until end of turn.
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Flying);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CKalastriaNightwatchCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CKalastriaNightwatchCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
												 const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return YOU_GAIN_LIFE;
}

CKorCastigatorCard::CKorCastigatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kor Castigator"), CardType::Creature,
		CREATURE_TYPE3(Kor, Wizard, Ally), nID, _T("1") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_CanBlockFilter(_T("a creature that isn't an Eldrazi Scion"), _T("creatures that aren't Eldrazi Scions"),
		new NegateCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Scion), false)))
{
	// This creature can't be blocked by Eldrazi Scions (= unblockable except by creatures that aren't Eldrazi Scions)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_CanBlockFilter);
}

CNirkanaAssassinCard::CNirkanaAssassinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nirkana Assassin"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Assassin, Ally), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you gain life, this creature gains deathtouch until end of turn.
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenPlayerLifeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNirkanaAssassinCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CNirkanaAssassinCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
											 const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return YOU_GAIN_LIFE;
}

CRecklessCohortCard::CRecklessCohortCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reckless Cohort"), CardType::Creature,
		CREATURE_TYPE3(Human, Warrior, Ally), nID, _T("1") RED_MANA_TEXT, Power(2), Life(2))
{
	// This creature attacks each combat if able unless you control another Ally.
	// Note: checked at the beginning of combat on your turn
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenNodeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetSkipStack(TRUE);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::MustAttack);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRecklessCohortCard::SetTriggerContext));
	AddAbility(cpAbility.GetPointer());
}

bool CRecklessCohortCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CNode* pNode) const
{
	if (GetZoneId() != ZoneId::Battlefield)
		return false;

	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	CreatureTypeComparer allyComparer(CREATURE_TYPE(Ally), false);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard != this && allyComparer(pCard))
			return false;
	}
	return true;
}

CSereneStewardCard::CSereneStewardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Serene Steward"), CardType::Creature,
		CREATURE_TYPE3(Human, Cleric, Ally), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you gain life, you may pay {W}. If you do, put a +1/+1 counter on target creature.
	typedef TTriggeredTargetAbility<CTriggeredModifyCardAbility, CWhenPlayerLifeChanged> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetResolutionCost(WHITE_MANA_TEXT);
	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1, false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSereneStewardCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CSereneStewardCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
										   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	return YOU_GAIN_LIFE;
}

CShatterskullRecruitCard::CShatterskullRecruitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shatterskull Recruit"), CardType::Creature,
		CREATURE_TYPE3(Giant, Warrior, Ally), nID, _T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE); // Menace
}

CVeteranWarleaderCard::CVeteranWarleaderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Veteran Warleader"), CardType::Creature,
		CREATURE_TYPE3(Human, Soldier, Ally), nID, _T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(0), Life(0))
	, m_AllyFilter(_T("another Ally"), _T("other Allies"), new CreatureTypeComparer(CREATURE_TYPE(Ally), false))
{
	m_AllyFilter.AddComparer(new AnyCreatureComparer);
	m_AllyFilter.AddNegateComparer(new SpecificCardComparer(this));

	{
		// Veteran Warleader's power and toughness are each equal to the number of creatures you control (as Nightmare).
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new AnyCreatureComparer));
		AddAbility(cpAbility.GetPointer());
	}

	// Tap another untapped Ally you control: This creature gains your choice of first strike, vigilance, or trample until end of turn.
	CreatureKeyword keywords[] = { CreatureKeyword::FirstStrike, CreatureKeyword::Vigilance, CreatureKeyword::Trample };
	for (int i = 0; i < 3; ++i)
	{
		counted_ptr<CPumpAbility> cpAbility(
			::CreateObject<CPumpAbility>(this, _T(""), Power(+0), Life(+0), keywords[i]));
		cpAbility->GetCost().AddTapCardCost(1, &m_AllyFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

CZulaportCutthroatCard::CZulaportCutthroatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Zulaport Cutthroat"), CardType::Creature,
		CREATURE_TYPE3(Human, Rogue, Ally), nID, _T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Whenever this creature or another creature you control dies, each opponent loses 1 life and you gain 1 life.
	// Note: triggers once per opponent, so in multiplayer you gain 1 life for each opponent
	typedef TTriggeredAbility<CTriggeredModifyLifeAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetResolutionModifier().CPlayerModifiers::Add(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}