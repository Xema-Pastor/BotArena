#include "stdafx.h"
#include "CardKaladesh.h"

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
		DEFINE_CARD(CAetherHubCard);
		DEFINE_CARD(CBloomingMarshCard);
		DEFINE_CARD(CBotanicalSanctumCard);
		DEFINE_CARD(CConcealedCourtyardCard);
		DEFINE_CARD(CInspiringVantageCard);
		DEFINE_CARD(CSpirebluffCanalCard);
		DEFINE_CARD(CInventorsFairCard);
		DEFINE_CARD(CSequesteredStashCard);
		DEFINE_CARD(CChandraPyrogeniusCard);
		DEFINE_CARD(CChandraTorchOfDefianceCard);
		DEFINE_CARD(CDovinBaanCard);
		DEFINE_CARD(CNissaNaturesArtisanCard);
		DEFINE_CARD(CNissaVitalForceCard);
		DEFINE_CARD(CSaheeliRaiCard);
		DEFINE_CARD(CAetherfluxReservoirCard);
		DEFINE_CARD(CCogworkersPuzzleknotCard);
		DEFINE_CARD(CDeadlockTrapCard);
		DEFINE_CARD(CDecoctionModuleCard);
		DEFINE_CARD(CDynavoltTowerCard);
		DEFINE_CARD(CFireforgersPuzzleknotCard);
		DEFINE_CARD(CGhirapurOrreryCard);
		DEFINE_CARD(CGlassblowersPuzzleknotCard);
		DEFINE_CARD(CInventorsGogglesCard);
		DEFINE_CARD(CKeyToTheCityCard);
		DEFINE_CARD(CMetalspinnersPuzzleknotCard);
		DEFINE_CARD(CPerpetualTimepieceCard);
		DEFINE_CARD(CPropheticPrismCard);
		DEFINE_CARD(CTorchGauntletCard);
		DEFINE_CARD(CWhirlermakerCard);
		DEFINE_CARD(CWoodweaversPuzzleknotCard);
		DEFINE_CARD(CAradaraExpressCard);
		DEFINE_CARD(CBallistaChargerCard);
		DEFINE_CARD(CBomatBazaarBargeCard);
		DEFINE_CARD(CCultivatorsCaravanCard);
		DEFINE_CARD(CDemolitionStomperCard);
		DEFINE_CARD(CFleetwheelCruiserCard);
		DEFINE_CARD(COvalchaseDragsterCard);
		DEFINE_CARD(CRenegadeFreighterCard);
		DEFINE_CARD(CSkySkiffCard);
		DEFINE_CARD(CSkysovereignConsulFlagshipCard);
		DEFINE_CARD(CSmugglersCopterCard);
		DEFINE_CARD(CAetherMeltdownCard);
		DEFINE_CARD(CAuthorityOfTheConsulsCard);
		DEFINE_CARD(CConsulateSurveillanceCard);
		DEFINE_CARD(CDurableHandicraftCard);
		DEFINE_CARD(CEraOfInnovationCard);
		DEFINE_CARD(CGiantSpectacleCard);
		DEFINE_CARD(CMalfunctionCard);
		DEFINE_CARD(CMetallurgicSummoningsCard);
		DEFINE_CARD(CRevokePrivilegesCard);
		DEFINE_CARD(CUnderhandedDesignsCard);
		DEFINE_CARD(CAttuneWithAetherCard);
		DEFINE_CARD(CCatharticReunionCard);
		DEFINE_CARD(CConfiscationCoupCard);
		DEFINE_CARD(CDieYoungCard);
		DEFINE_CARD(CEngineeredMightCard);
		DEFINE_CARD(CFortuitousFindCard);
		DEFINE_CARD(CFragmentizeCard);
		DEFINE_CARD(CFumigateCard);
		DEFINE_CARD(CFuriousReprisalCard);
		DEFINE_CARD(CHarshScrutinyCard);
		DEFINE_CARD(CHazardousConditionsCard);
		DEFINE_CARD(CHijackCard);
		DEFINE_CARD(CLargerThanLifeCard);
		DEFINE_CARD(CLiberatingCombustionCard);
		DEFINE_CARD(CLiveFastCard);
		DEFINE_CARD(CMadcapExperimentCard);
		DEFINE_CARD(CMorbidCuriosityCard);
		DEFINE_CARD(CNaturesWayCard);
		DEFINE_CARD(CRefurbishCard);
		DEFINE_CARD(CRenegadeTacticsCard);
		DEFINE_CARD(CSaheelisArtistryCard);
		DEFINE_CARD(CServoExhibitionCard);
		DEFINE_CARD(CTakeDownCard);
		DEFINE_CARD(CTezzeretsAmbitionCard);
		DEFINE_CARD(CVerdantCrescendoCard);
		DEFINE_CARD(CWildestDreamsCard);
		DEFINE_CARD(CAcrobaticManeuverCard);
		DEFINE_CARD(CAetherTradewindsCard);
		DEFINE_CARD(CAppetiteForTheUnnaturalCard);
		DEFINE_CARD(CBlossomingDefenseCard);
		DEFINE_CARD(CBuiltToLastCard);
		DEFINE_CARD(CBuiltToSmashCard);
		DEFINE_CARD(CCeremoniousRejectionCard);
		DEFINE_CARD(CChandrasPyrohelixCard);
		DEFINE_CARD(CCommencementOfFestivitiesCard);
		DEFINE_CARD(CDisappearingActCard);
		DEFINE_CARD(CDramaticReversalCard);
		DEFINE_CARD(CEssenceExtractionCard);
		DEFINE_CARD(CFailedInspectionCard);
		DEFINE_CARD(CFatefulShowdownCard);
		DEFINE_CARD(CFlameLashCard);
		DEFINE_CARD(CGlimmerOfGeniusCard);
		DEFINE_CARD(CHarnessedLightningCard);
		DEFINE_CARD(CImpeccableTimingCard);
		DEFINE_CARD(CIncendiarySabotageCard);
		DEFINE_CARD(CMakeObsoleteCard);
		DEFINE_CARD(COrnamentalCourageCard);
		DEFINE_CARD(CParadoxicalOutcomeCard);
		DEFINE_CARD(CRevolutionaryRebuffCard);
		DEFINE_CARD(CRushOfVitalityCard);
		DEFINE_CARD(CSelectForInspectionCard);
		DEFINE_CARD(CSkywhalersShotCard);
		DEFINE_CARD(CSubtleStrikeCard);
		DEFINE_CARD(CTidyConclusionCard);
		DEFINE_CARD(CUnlicensedDisintegrationCard);
		DEFINE_CARD(CWeldingSparksCard);
		DEFINE_CARD(CAerialResponderCard);
		DEFINE_CARD(CAetherstormRocCard);
		DEFINE_CARD(CAngelOfInventionCard);
		DEFINE_CARD(CAviaryMechanicCard);
		DEFINE_CARD(CConsulsShieldguardCard);
		DEFINE_CARD(CEddytrailHawkCard);
		DEFINE_CARD(CGlintSleeveArtisanCard);
		DEFINE_CARD(CHeraldOfTheFairCard);
		DEFINE_CARD(CMasterTrinketeerCard);
		DEFINE_CARD(CNinthBridgePatrolCard);
		DEFINE_CARD(CPropellerPioneerCard);
		DEFINE_CARD(CSkyswirlHarrierCard);
		DEFINE_CARD(CTasseledDromedaryCard);
		DEFINE_CARD(CThrivingIbexCard);
		DEFINE_CARD(CToolcraftExemplarCard);
		DEFINE_CARD(CVisionaryAugmenterCard);
		DEFINE_CARD(CWispweaverAngelCard);
		DEFINE_CARD(CFairgroundsWardenCard);
		DEFINE_CARD(CArborbackStomperCard);
		DEFINE_CARD(CArchitectOfTheUntamedCard);
		DEFINE_CARD(CArmorcraftJudgeCard);
		DEFINE_CARD(CBristlingHydraCard);
		DEFINE_CARD(CCowlProwlerCard);
		DEFINE_CARD(CCultivatorOfBladesCard);
		DEFINE_CARD(CElegantEdgecraftersCard);
		DEFINE_CARD(CGhirapurGuideCard);
		DEFINE_CARD(CHighspireArtisanCard);
		DEFINE_CARD(CKujarSeedsculptorCard);
		DEFINE_CARD(CLongtuskCubCard);
		DEFINE_CARD(COviyaPashiriSageLifecrafterCard);
		DEFINE_CARD(CPeemaOutriderCard);
		DEFINE_CARD(CRiparianTigerCard);
		DEFINE_CARD(CSageOfShailasClaimCard);
		DEFINE_CARD(CServantOfTheConduitCard);
		DEFINE_CARD(CTerrainElementalCard);
		DEFINE_CARD(CThrivingRhinoCard);
		DEFINE_CARD(CVerdurousGearhulkCard);
		DEFINE_CARD(CWildWandererCard);
		DEFINE_CARD(CWilyBandarCard);
		DEFINE_CARD(CAethertorchRenegadeCard);
		DEFINE_CARD(CBrazenScourgeCard);
		DEFINE_CARD(CCombustibleGearhulkCard);
		DEFINE_CARD(CInventorsApprenticeCard);
		DEFINE_CARD(CLathnuHellionCard);
		DEFINE_CARD(CMaulfistDoorbusterCard);
		DEFINE_CARD(CPiaNalaarCard);
		DEFINE_CARD(CQuicksmithGeniusCard);
		DEFINE_CARD(CRecklessFireweaverCard);
		DEFINE_CARD(CRenegadeFirebrandCard);
		DEFINE_CARD(CRuinousGremlinCard);
		DEFINE_CARD(CSalivatingGremlinsCard);
		DEFINE_CARD(CSkyshipStalkerCard);
		DEFINE_CARD(CSpiresideInfiltratorCard);
		DEFINE_CARD(CSpontaneousArtistCard);
		DEFINE_CARD(CTerrorOfTheFairgroundsCard);
		DEFINE_CARD(CThrivingGrubsCard);
		DEFINE_CARD(CWaywardGiantCard);
		DEFINE_CARD(CGuardianOfTheGreatConduitCard);
		DEFINE_CARD(CAetherbornMarauderCard);
		DEFINE_CARD(CAmbitiousAetherbornCard);
		DEFINE_CARD(CDemonOfDarkSchemesCard);
		DEFINE_CARD(CDhundOperativeCard);
		DEFINE_CARD(CDukharaScavengerCard);
		DEFINE_CARD(CEmbraalBruiserCard);
		DEFINE_CARD(CFoundryScreecherCard);
		DEFINE_CARD(CFretworkColonyCard);
		DEFINE_CARD(CLawlessBrokerCard);
		DEFINE_CARD(CMarionetteMasterCard);
		DEFINE_CARD(CMaulfistSquadCard);
		DEFINE_CARD(CNightMarketLookoutCard);
		DEFINE_CARD(CNoxiousGearhulkCard);
		DEFINE_CARD(COvalchaseDaredevilCard);
		DEFINE_CARD(CPrakhataClubSecurityCard);
		DEFINE_CARD(CSyndicateTraffickerCard);
		DEFINE_CARD(CThrivingRatsCard);
		DEFINE_CARD(CWeaponcraftEnthusiastCard);
		DEFINE_CARD(CAethersquallAncientCard);
		DEFINE_CARD(CAetherTheoristCard);
		DEFINE_CARD(CCurioVendorCard);
		DEFINE_CARD(CExperimentalAviatorCard);
		DEFINE_CARD(CGearseekerSerpentCard);
		DEFINE_CARD(CGlintNestCraneCard);
		DEFINE_CARD(CHightideHermitCard);
		DEFINE_CARD(CJanjeetSentryCard);
		DEFINE_CARD(CLongFinnedSkywhaleCard);
		DEFINE_CARD(CMinisterOfInquiriesCard);
		DEFINE_CARD(CNimbleInnovatorCard);
		DEFINE_CARD(CPadeemConsulOfInnovationCard);
		DEFINE_CARD(CThrivingTurtleCard);
		DEFINE_CARD(CVedalkenBlademasterCard);
		DEFINE_CARD(CWeldfastWingsmithCard);
		DEFINE_CARD(CCloudblazerCard);
		DEFINE_CARD(CContrabandKingpinCard);
		DEFINE_CARD(CEmpyrealVoyagerCard);
		DEFINE_CARD(CKambalConsulOfAllocationCard);
		DEFINE_CARD(CRestorationGearsmithCard);
		DEFINE_CARD(CVeteranMotoristCard);
		DEFINE_CARD(CVoltaicBrawlerCard);
		DEFINE_CARD(CWhirlerVirtuosoCard);
		DEFINE_CARD(CAccomplishedAutomatonCard);
		DEFINE_CARD(CBastionMastodonCard);
		DEFINE_CARD(CChiefOfTheFoundryCard);
		DEFINE_CARD(CConsulateSkygateCard);
		DEFINE_CARD(CDukharaPeafowlCard);
		DEFINE_CARD(CEagerConstructCard);
		DEFINE_CARD(CElectrostaticPummelerCard);
		DEFINE_CARD(CFiligreeFamiliarCard);
		DEFINE_CARD(CFoundryInspectorCard);
		DEFINE_CARD(CIronLeagueSteedCard);
		DEFINE_CARD(CMultiformWonderCard);
		DEFINE_CARD(CNarnamCobraCard);
		DEFINE_CARD(CPrakhataPillarBugCard);
		DEFINE_CARD(CSelfAssemblerCard);
		DEFINE_CARD(CSnareThopterCard);
		DEFINE_CARD(CWeldfastMonitorCard);
		DEFINE_CARD(CWorkshopAssistantCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
// Lands

// Mills nCount cards (the top cards of the player's library are put into the graveyard)
static void Mill(CPlayer* pPlayer, int nCount)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < nCount && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
}

CFastlandBase::CFastlandBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strMana1, LPCTSTR strMana2)
	: CNonbasicLandCard(pGame, strCardName, nID)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CFastlandBase::OnZoneChanged))
{
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	LPCTSTR manas[] = { strMana1, strMana2 };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, manas[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

void CFastlandBase::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this)
		return;

	// Enters tapped if you control three or more other lands (this land is already on the battlefield)
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield &&
		CCardFilter::GetFilter(_T("lands"))->CountIncluded(pBattlefield->GetCardContainer()) > 3)
	{
		GetOrientation()->Tap();
	}
}

CAetherHubCard::CAetherHubCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Aether Hub"), nID)
{
	{
		// When this land enters, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherHubCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}: Add {C}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	// {T}, Pay {E}: Add one mana of any color. (one mana ability for each color, as Cryptolith Rite)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 1);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAetherHubCard::BeforeEnergy(CAbilityAction* pAction) const
{
	CEnergyModifier pModifier = CEnergyModifier(GetGame(), 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CBloomingMarshCard::CBloomingMarshCard(CGame* pGame, UINT nID)
	: CFastlandBase(pGame, _T("Blooming Marsh"), nID, BLACK_MANA_TEXT, GREEN_MANA_TEXT)
{
}

CBotanicalSanctumCard::CBotanicalSanctumCard(CGame* pGame, UINT nID)
	: CFastlandBase(pGame, _T("Botanical Sanctum"), nID, GREEN_MANA_TEXT, BLUE_MANA_TEXT)
{
}

CConcealedCourtyardCard::CConcealedCourtyardCard(CGame* pGame, UINT nID)
	: CFastlandBase(pGame, _T("Concealed Courtyard"), nID, WHITE_MANA_TEXT, BLACK_MANA_TEXT)
{
}

CInspiringVantageCard::CInspiringVantageCard(CGame* pGame, UINT nID)
	: CFastlandBase(pGame, _T("Inspiring Vantage"), nID, RED_MANA_TEXT, WHITE_MANA_TEXT)
{
}

CSpirebluffCanalCard::CSpirebluffCanalCard(CGame* pGame, UINT nID)
	: CFastlandBase(pGame, _T("Spirebluff Canal"), nID, BLUE_MANA_TEXT, RED_MANA_TEXT)
{
}

CInventorsFairCard::CInventorsFairCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Inventors' Fair"), nID, CardType::NonbasicLand | CardType::Legendary)
	, m_ArtifactFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	{
		// At the beginning of your upkeep, if you control three or more artifacts, you gain 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CInventorsFairCard::SetUpkeepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInventorsFairCard::BeforeLife));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}: Add {C}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}, {T}, Sacrifice Inventors' Fair: Search your library for an artifact card, reveal it, put it into your
		// hand, then shuffle. Activate only if you control three or more artifacts.
		counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
				_T("4"), &m_ArtifactFilter,
				ZoneId::Hand, TRUE, FALSE, FALSE));

		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CInventorsFairCard::CanSearch)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CInventorsFairCard::HasThreeArtifacts() const
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pBattlefield->GetCardContainer()) >= 3;
}

bool CInventorsFairCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasThreeArtifacts() ? true : false;
}

bool CInventorsFairCard::BeforeLife(CAbilityAction* pAction) const
{
	// (intervening if: checked again on resolution)
	if (!HasThreeArtifacts())
		return true;

	CLifeModifier pModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

BOOL CInventorsFairCard::CanSearch(BOOL bIncludeTricks)
{
	return HasThreeArtifacts();
}

CSequesteredStashCard::CSequesteredStashCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Sequestered Stash"), nID)
	, m_ArtifactFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	{
		// {T}: Add {C}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}, {T}, Sacrifice this land: Mill five cards. Then you may put an artifact card from your graveyard on top
		// of your library.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4")));

		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Mill five cards, then you may put an artifact card from your graveyard on top of your library. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSequesteredStashCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSequesteredStashCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	Mill(pController, 5);

	// (as Liliana, the Last Hope in Eldritch Moon)
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // select an artifact card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		&m_ArtifactFilter,						// artifact cards
		ZoneId::Library,						// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);

	pModifier.ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
// Planeswalkers

// Scry N (as in Shadows over Innistrad)
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

// The source deals nDamage damage to each opponent of pPlayer
static void DamageEachOpponent(CCard* pSource, CPlayer* pPlayer, int nDamage)
{
	for (int ip = 0; ip < pSource->GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = pSource->GetGame()->GetPlayer(ip);
		if (pOpponent == pPlayer)
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pOpponent);
	}
}

// "-N: This planeswalker deals nDamage damage to target creature."
static void AddCreatureDamageAbility(CPlaneswalkerCard* pCard, int nLoyalty, int nDamage)
{
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(pCard,
			_T(""),
			new AnyCreatureComparer, FALSE,
			Life(-nDamage), PreventableType::Preventable));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	pCard->AddAbility(cpAbility.GetPointer());
}

// "-N: You get an emblem with ..."
static void AddEmblemAbility(CPlaneswalkerCard* pCard, int nLoyalty, LPCTSTR strEmblem, UINT uID, LPCTSTR strText)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			_T("")));

	cpAbility->GetCost().AddCounterCost(pCard->GetLoyaltyCounter(), nLoyalty);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(pCard->GetGame(), strEmblem, uID, 1, FALSE, ZoneId::_Effects));
	cpAbility->SetAbilityText(strText);
	pCard->AddAbility(cpAbility.GetPointer());
}

CChandraPyrogeniusCard::CChandraPyrogeniusCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Pyrogenius"), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Chandra, 5)
{
	{
		// +2: Chandra deals 2 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandraPyrogeniusCard::BeforeResolution1));
		cpAbility->SetAbilityText(_T("+2: Chandra deals 2 damage to each opponent."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}

	// -3: Chandra deals 4 damage to target creature.
	AddCreatureDamageAbility(this, -3, 4);

	{
		// -10: Chandra deals 6 damage to target player or planeswalker and each creature that player or that
		// planeswalker's controller controls.
		// Note: only players can be targeted
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -10);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandraPyrogeniusCard::BeforeResolution3));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CChandraPyrogeniusCard::BeforeResolution1(CAbilityAction* pAction) const
{
	DamageEachOpponent((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CChandraPyrogeniusCard::BeforeResolution3(CAbilityAction* pAction) const
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (!pPlayer)
		return true;

	CLifeModifier pModifier = CLifeModifier(Life(-6), (CCard*)this, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pPlayer);

	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer creatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
	return true;
}

CChandraTorchOfDefianceCard::CChandraTorchOfDefianceCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Torch of Defiance"), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Chandra, 4)
{
	{
		// +1: Exile the top card of your library. You may cast that card. If you don't, Chandra deals 2 damage to each
		// opponent.
		// Note: the engine can't let you cast the exiled card (paying its cost): it is exiled and Chandra deals the damage.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandraTorchOfDefianceCard::BeforeResolution1));
		cpAbility->SetAbilityText(_T("+1: Exile the top card of your library. Chandra deals 2 damage to each opponent."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// +1: Add {R}{R}.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(RED_MANA_TEXT RED_MANA_TEXT)));
		cpAbility->SetAbilityText(_T("+1: Add {R}{R}."));
		AddAbility(cpAbility.GetPointer());
	}

	// -3: Chandra deals 4 damage to target creature.
	AddCreatureDamageAbility(this, -3, 4);

	// -7: You get an emblem with "Whenever you cast a spell, this emblem deals 5 damage to any target."
	AddEmblemAbility(this, -7, _T("Chandra, Torch of Defiance Emblem"), 61147,
		_T("-7: You get an emblem with - Whenever you cast a spell, this emblem deals 5 damage to any target."));
}

bool CChandraTorchOfDefianceCard::BeforeResolution1(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() > 0)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others);
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
	}

	DamageEachOpponent((CCard*)this, pController, 2);
	return true;
}

CDovinBaanCard::CDovinBaanCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Dovin Baan"), nID,
		_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT,
		PlaneswalkerType::Dovin, 3)
	, m_ActivationFilter(new SpecificCardComparer(NULL))
{
	{
		// +1: Until your next turn, up to one target creature gets -3/-0 and its activated abilities can't be activated.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDovinBaanCard::BeforeResolution1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -1: You gain 2 life and draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T(""), 1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -1);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+2), this, PreventableType::NotPreventable));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}

	// -7: You get an emblem with "Your opponents can't untap more than two permanents during their untap steps."
	AddEmblemAbility(this, -7, _T("Dovin Baan Emblem"), 61148,
		_T("-7: You get an emblem with - Your opponents can't untap more than two permanents during their untap steps."));
}

bool CDovinBaanCard::BeforeResolution1(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	// Until your next turn: removed at the beginning of the controller's next untap step (as Liliana, the Last Hope)
	CPlayer* pController = pAction->GetController();
	CScheduledCreatureModifier pPowerModifier = CScheduledCreatureModifier(GetGame(),
		new CPowerModifier(Power(-3), FALSE),
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pController);
	pPowerModifier.ApplyTo((CCreatureCard*)pCard);

	// Its activated abilities can't be activated (as Stony Silence in Innistrad, for this creature only)
	m_ActivationFilter.SetComparer(new SpecificCardComparer(pCard));
	CScheduledPlayerModifier pEffectModifier = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::CantPlayActivatedAbilities, reinterpret_cast<int>(&m_ActivationFilter)),
		TurnNumberDelta(-1), NodeId::UntapStep, CScheduledPlayerModifier::Operation::ApplyToNowRemoveLater,
		CScheduledPlayerModifier::DeltaOption::CustomPlayerTurn, pController);
	pEffectModifier.ApplyTo(pCard->GetController());
	return true;
}

CNissaNaturesArtisanCard::CNissaNaturesArtisanCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nissa, Nature's Artisan"), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Nissa, 5)
{
	{
		// +3: You gain 3 life.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +3);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+3), this, PreventableType::NotPreventable));
		cpAbility->SetAbilityText(_T("+3: You gain 3 life."));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -4: Reveal the top two cards of your library. Put all land cards from among them onto the battlefield and
		// the rest into your hand.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -4);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaNaturesArtisanCard::BeforeResolution2));
		cpAbility->SetAbilityText(_T("-4: Reveal the top two cards of your library. Put all land cards from among them onto the battlefield and the rest into your hand."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -12: Creatures you control get +5/+5 and gain trample until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -12);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaNaturesArtisanCard::BeforeResolution3));
		cpAbility->SetAbilityText(_T("-12: Creatures you control get +5/+5 and gain trample until end of turn."));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNissaNaturesArtisanCard::BeforeResolution2(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	CCountedCardContainer revealed;
	for (int i = 0; i < 2 && i < pLibrary->GetSize(); ++i)
		revealed.AddCard(pLibrary->GetAt(pLibrary->GetSize() - 1 - i), CardPlacement::Top);

	CString strMessage = _T("Nissa, Nature's Artisan reveals:");
	for (int i = 0; i < revealed.GetSize(); ++i)
	{
		strMessage += (i == 0) ? _T(" ") : _T(", ");
		strMessage += revealed.GetAt(i)->GetCardName(TRUE);
	}
	if (!GetGame()->IsThinking() && revealed.GetSize())
		GetGame()->Message(strMessage, pController->IsComputer() ? GetGame()->GetComputerImage() : GetGame()->GetHumanImage(),
			MessageImportance::High);

	for (int i = 0; i < revealed.GetSize(); ++i)
	{
		CCard* pCard = revealed.GetAt(i);
		ZoneId toZone = pCard->GetCardType().IsLand() ? ZoneId::Battlefield : ZoneId::Hand;
		pCard->Move(pController->GetZoneById(toZone), pController, MoveType::Others);
	}
	return true;
}

bool CNissaNaturesArtisanCard::BeforeResolution3(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(+5));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+5), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CCreatureKeywordModifier pTrampleModifier;
	pTrampleModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pTrampleModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
		if (!pCreature)
			pCreature = dynamic_cast<CCreatureCard*>(pCard->GetIsAlsoA());	// an animated permanent
		if (!pCreature)
			continue;

		pPowerModifier.ApplyTo(pCreature);
		pLifeModifier.ApplyTo(pCreature);
		pTrampleModifier.ApplyTo(pCreature);
	}
	return true;
}

CNissaVitalForceCard::CNissaVitalForceCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nissa, Vital Force"), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Nissa, 5)
{
	{
		// +1: Untap target land you control. Until your next turn, it becomes a 5/5 Elemental creature with haste.
		// It's still a land.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::_Land, false), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaVitalForceCard::BeforeResolution1));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Return target permanent card from your graveyard to your hand.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::_Permanent, false),
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}

	// -6: You get an emblem with "Whenever a land you control enters, you may draw a card."
	AddEmblemAbility(this, -6, _T("Nissa, Vital Force Emblem"), 61149,
		_T("-6: You get an emblem with - Whenever a land you control enters, you may draw a card."));
}

bool CNissaVitalForceCard::BeforeResolution1(CAbilityAction* pAction) const
{
	CCard* pLand = pAction->GetAssociatedCard();
	if (!pLand || pLand->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardOrientationModifier pUntapModifier = CCardOrientationModifier(FALSE);
	pUntapModifier.ApplyTo(pLand);

	// Until your next turn (as Tezzeret the Seeker's -5 in Shards of Alara, removed at your next untap step)
	CScheduledCardModifier pAnimationModifier = CScheduledCardModifier(GetGame(),
		new CCardIsAlsoAModifier(_T("Elemental AU"), 64101, pAction->GetController()),
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pAction->GetController());
	pAnimationModifier.ApplyTo(pLand);
	return true;
}

CSaheeliRaiCard::CSaheeliRaiCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Saheeli Rai"), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Saheeli, 3)
	, m_ArtifactFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	{
		// +1: Scry 1. Saheeli Rai deals 1 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaheeliRaiCard::BeforeResolution1));
		cpAbility->SetAbilityText(_T("+1: Scry 1. Saheeli Rai deals 1 damage to each opponent."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Create a token that's a copy of target artifact or creature you control, except it's an artifact in
		// addition to its other types. That token gains haste. Exile it at the beginning of the next end step.
		// (the copy as Kiki-Jiki, Mirror Breaker in Champions of Kamigawa)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Artifact | CardType::Creature, false), FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaheeliRaiCard::BeforeResolution2));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: Search your library for up to three artifact cards with different names, put them onto the battlefield,
		// then shuffle.
		// Note: the different names are not checked
		counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
			::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
				_T(""), &m_ArtifactFilter,
				ZoneId::Battlefield, FALSE, FALSE, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(3));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSaheeliRaiCard::BeforeResolution1(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ApplyScry(GetGame(), pController, this, 1);
	DamageEachOpponent(this, pController, 1);
	return true;
}

bool CSaheeliRaiCard::BeforeResolution2(CAbilityAction* pAction) const
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield)
		return true;

	// An artifact in addition to its other types; haste if it's a creature
	CCreatureKeywordModifier* pHasteModifier = NULL;
	if (pTarget->GetCardType().IsCreature())
	{
		pHasteModifier = new CCreatureKeywordModifier();
		pHasteModifier->GetModifier().SetOneTurnOnly(FALSE);
		pHasteModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	}

	CCountedCardContainer tokens;
	CCardCopyModifier pCopyModifier = CCardCopyModifier(GetGame(), pTarget,
		new CCardTypeModifier(CardType::Artifact), pHasteModifier, &tokens);
	pCopyModifier.ApplyTo(pTarget);

	// Exile it at the beginning of the next end step (as Long Road Home in Eldritch Moon)
	for (int i = 0; i < tokens.GetSize(); ++i)
	{
		CScheduledCardModifier pExileModifier = CScheduledCardModifier(GetGame(),
			new CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others),
			TurnNumberDelta(-1), NodeId::EndStep, true, CScheduledCardModifier::Operation::ApplyToLater);
		pExileModifier.ApplyTo(tokens.GetAt(i));
	}
	return true;
}

//____________________________________________________________________________
//
// Artifacts

#define SERVO_TOKEN_NAME	_T("Servo (A)")
#define SERVO_TOKEN_ID		55090

// "{cost}, {T}: Add one mana of any color." (one mana ability for each color, as Cryptolith Rite)
static void AddAnyColorManaAbilities(CCard* pCard, LPCTSTR strCost)
{
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(pCard, strCost, AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		pCard->AddAbility(cpAbility.GetPointer());
	}
}

static void GetEnergy(CCard* pCard, CPlayer* pPlayer, int nCount)
{
	CEnergyModifier pModifier = CEnergyModifier(pCard->GetGame(), nCount);
	pModifier.ApplyTo(pPlayer);
}

// "When this enters, <effect>" with the effect in a resolution callback
template <class T>
static void AddEnterTrigger(T* pCard, bool (T::*callback)(CAbilityAction*) const)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "{cost}, Sacrifice this artifact: <effect>" with the effect in a resolution callback (the Puzzleknots)
template <class T>
static void AddSacrificeAbility(T* pCard, LPCTSTR strCost, bool (T::*callback)(CAbilityAction*) const, LPCTSTR strText)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			strCost));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

CAetherfluxReservoirCard::CAetherfluxReservoirCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Aetherflux Reservoir"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
{
	{
		// Whenever you cast a spell, you gain 1 life for each spell you've cast this turn.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherfluxReservoirCard::BeforeLife));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay 50 life: This artifact deals 50 damage to any target.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-50), PreventableType::Preventable));

		cpAbility->GetCost().SetPlayerLifeCost(this, Life(-50));
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAetherfluxReservoirCard::BeforeLife(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	int nSpells = pController->GetTurnCastedSpellCount();
	if (nSpells > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(+nSpells), (CCard*)this, PreventableType::NotPreventable);
		pModifier.ApplyTo(pController);
	}
	return true;
}

CCogworkersPuzzleknotCard::CCogworkersPuzzleknotCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cogworker's Puzzleknot"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// When this artifact enters, create a 1/1 colorless Servo artifact creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{W}, Sacrifice this artifact: Create a 1/1 colorless Servo artifact creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("1") WHITE_MANA_TEXT,
				SERVO_TOKEN_NAME, SERVO_TOKEN_ID,
				1));

		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CDeadlockTrapCard::CDeadlockTrapCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Deadlock Trap"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_ActivationFilter(new SpecificCardComparer(NULL))
{
	// This artifact enters tapped.
	SetIntoPlayTapped();

	// When this artifact enters, you get {E}{E}.
	AddEnterTrigger(this, &CDeadlockTrapCard::BeforeEnergy);

	{
		// {T}, Pay {E}: Tap target creature or planeswalker. Its activated abilities can't be activated this turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeadlockTrapCard::BeforeTap));
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDeadlockTrapCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CDeadlockTrapCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	pTapModifier.ApplyTo(pCard);

	// Its activated abilities can't be activated this turn (as Dovin Baan's +1)
	m_ActivationFilter.SetComparer(new SpecificCardComparer(pCard));
	CScheduledPlayerModifier pEffectModifier = CScheduledPlayerModifier(GetGame(),
		new CPlayerEffectModifier(PlayerEffectType::CantPlayActivatedAbilities, reinterpret_cast<int>(&m_ActivationFilter)),
		TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::ApplyToNowRemoveLater);
	pEffectModifier.ApplyTo(pCard->GetController());
	return true;
}

CDecoctionModuleCard::CDecoctionModuleCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Decoction Module"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// Whenever a creature you control enters, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDecoctionModuleCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}, {T}: Return target creature you control to its owner's hand.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("4"),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDecoctionModuleCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

CDynavoltTowerCard::CDynavoltTowerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dynavolt Tower"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// Whenever you cast an instant or sorcery spell, you get {E}{E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDynavoltTowerCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Pay {E}{E}{E}{E}{E}: This artifact deals 3 damage to any target.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-3), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 5);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDynavoltTowerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CFireforgersPuzzleknotCard::CFireforgersPuzzleknotCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fireforger's Puzzleknot"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// When this artifact enters, it deals 1 damage to any target.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{R}, Sacrifice this artifact: It deals 1 damage to any target.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer, TRUE,
				Life(-1), PreventableType::Preventable));

		cpAbility->AddSacrificeCost();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

CGhirapurOrreryCard::CGhirapurOrreryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ghirapur Orrery"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
{
	{
		// Each player may play an additional land on each of their turns.
		counted_ptr<CPlayExtraLandEnchantment> cpAbility(
			::CreateObject<CPlayExtraLandEnchantment>(this, +1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each player's upkeep, if that player has no cards in hand, that player draws three cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGhirapurOrreryCard::SetUpkeepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGhirapurOrreryCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGhirapurOrreryCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetGame()->GetActivePlayer()->GetZoneById(ZoneId::Hand)->GetSize() == 0;
}

bool CGhirapurOrreryCard::BeforeDraw(CAbilityAction* pAction) const
{
	// (intervening if: checked again on resolution)
	CPlayer* pPlayer = GetGame()->GetActivePlayer();
	if (pPlayer->GetZoneById(ZoneId::Hand)->GetSize() == 0)
	{
		CDrawCardModifier pModifier = CDrawCardModifier(GetGame(), MinimumValue(3), MaximumValue(3));
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

CGlassblowersPuzzleknotCard::CGlassblowersPuzzleknotCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Glassblower's Puzzleknot"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters, scry 2, then you get {E}{E}.
	// {2}{U}, Sacrifice this artifact: Scry 2, then you get {E}{E}.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGlassblowersPuzzleknotCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLUE_MANA_TEXT));

		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Scry 2, then you get {E}{E}. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGlassblowersPuzzleknotCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGlassblowersPuzzleknotCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	ApplyScry(GetGame(), pController, this, 2);
	GetEnergy(this, pController, 2);
	return true;
}

CInventorsGogglesCard::CInventorsGogglesCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Inventor's Goggles"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	{
		// Equipped creature gets +1/+2. Equip {2}
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("2")));

		cpAbility->AddCreatureModifier(new CLifeModifier(Life(+2), this,
			PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
		cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever an Artificer you control enters, you may attach this Equipment to it.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Artificer), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CInventorsGogglesCard::SetTriggerContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CInventorsGogglesCard::BeforeAttach));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CInventorsGogglesCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_pCard = pCard;
	return true;
}

bool CInventorsGogglesCard::BeforeAttach(TriggeredAbility::TriggeredActionType* pAction)
{
	// (as the equip of Lorwyn)
	CCard* pCard = pAction->GetTriggerContext().m_pCard;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || GetZoneId() != ZoneId::Battlefield ||
		!pCard->GetCardType().IsCreature() || pCard->GetController() != GetController())
		return true;

	CEquipModifier pModifier = CEquipModifier(this);
	pModifier.ApplyTo((CCreatureCard*)pCard);
	return true;
}

CKeyToTheCityCard::CKeyToTheCityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Key to the City"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// {T}, Discard a card: Up to one target creature can't be blocked this turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T(""),
				Power(+0), Life(+0),
				CreatureKeyword::Unblockable, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this artifact becomes untapped, you may pay {2}. If you do, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfOrientationChanged,
							   CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetUntapEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("2"));
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}
}

CMetalspinnersPuzzleknotCard::CMetalspinnersPuzzleknotCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Metalspinner's Puzzleknot"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters, you draw a card and you lose 1 life.
	AddEnterTrigger(this, &CMetalspinnersPuzzleknotCard::BeforeResolution);

	// {2}{B}, Sacrifice this artifact: You draw a card and you lose 1 life.
	AddSacrificeAbility(this, _T("2") BLACK_MANA_TEXT, &CMetalspinnersPuzzleknotCard::BeforeResolution,
		_T("You draw a card and you lose 1 life. Activates"));
}

bool CMetalspinnersPuzzleknotCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
	pDrawModifier.ApplyTo(pController);
	CLifeModifier pLifeModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pController);
	return true;
}

CPerpetualTimepieceCard::CPerpetualTimepieceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Perpetual Timepiece"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// {T}: Mill two cards.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Mill two cards. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPerpetualTimepieceCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, Exile this artifact: Shuffle any number of target cards from your graveyard into your library.
		// Note: the cards are chosen on resolution (not targeted)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddExileCost();
		cpAbility->SetAbilityText(_T("Shuffle any number of cards from your graveyard into your library. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPerpetualTimepieceCard::BeforeShuffle));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPerpetualTimepieceCard::BeforeMill(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 2);
	return true;
}

bool CPerpetualTimepieceCard::BeforeShuffle(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(pGraveyard->GetSize()), // select any number of cards
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		CCardFilter::GetFilter(_T("cards")),	// any cards
		ZoneId::Library,						// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CPropheticPrismCard::CPropheticPrismCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Prophetic Prism"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// When this artifact enters, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}

	// {1}, {T}: Add one mana of any color.
	AddAnyColorManaAbilities(this, _T("1"));
}

CTorchGauntletCard::CTorchGauntletCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Torch Gauntlet"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	// Equipped creature gets +2/+0. Equip {2}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("2")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CWhirlermakerCard::CWhirlermakerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Whirlermaker"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// {4}, {T}: Create a 1/1 colorless Thopter artifact creature token with flying.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("4"),
			_T("Thopter (D)"), 55053,
			1));

	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CWoodweaversPuzzleknotCard::CWoodweaversPuzzleknotCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Woodweaver's Puzzleknot"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters, you gain 3 life and get {E}{E}{E}.
	AddEnterTrigger(this, &CWoodweaversPuzzleknotCard::BeforeResolution);

	// {2}{G}, Sacrifice this artifact: You gain 3 life and get {E}{E}{E}.
	AddSacrificeAbility(this, _T("2") GREEN_MANA_TEXT, &CWoodweaversPuzzleknotCard::BeforeResolution,
		_T("You gain 3 life and get {E}{E}{E}. Activates"));
}

bool CWoodweaversPuzzleknotCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	CLifeModifier pModifier = CLifeModifier(Life(+3), (CCard*)this, PreventableType::NotPreventable);
	pModifier.ApplyTo(pController);
	GetEnergy((CCard*)this, pController, 3);
	return true;
}

//____________________________________________________________________________
//
// Vehicles

CAradaraExpressCard::CAradaraExpressCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Aradara Express"), CardType::Artifact, nID,
		_T("5"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Menace. Crew 4
	m_Crew.AddCrewAbility(4, _T("Aradara Express (Vehicle)"), 64102);
}

CBallistaChargerCard::CBallistaChargerCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ballista Charger"), CardType::Artifact, nID,
		_T("5"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Whenever this Vehicle attacks, it deals 1 damage to any target. (in the crewed creature) Crew 3
	m_Crew.AddCrewAbility(3, _T("Ballista Charger (Vehicle)"), 64103);
}

CBomatBazaarBargeCard::CBomatBazaarBargeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Bomat Bazaar Barge"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_Crew(this)
{
	{
		// When this Vehicle enters, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}

	// Crew 3
	m_Crew.AddCrewAbility(3, _T("Bomat Bazaar Barge (Vehicle)"), 64104);
}

CCultivatorsCaravanCard::CCultivatorsCaravanCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cultivator's Caravan"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	// {T}: Add one mana of any color.
	AddAnyColorManaAbilities(this, _T(""));

	// Crew 3
	m_Crew.AddCrewAbility(3, _T("Cultivator's Caravan (Vehicle)"), 64105);
}

CDemolitionStomperCard::CDemolitionStomperCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Demolition Stomper"), CardType::Artifact, nID,
		_T("6"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Crew 5 (note: "can't be blocked by creatures with power 2 or less" is not implemented)
	m_Crew.AddCrewAbility(5, _T("Demolition Stomper (Vehicle)"), 64106);
}

CFleetwheelCruiserCard::CFleetwheelCruiserCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fleetwheel Cruiser"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Trample, haste. Crew 2
	m_Crew.AddCrewAbility(2, _T("Fleetwheel Cruiser (Vehicle)"), 64107);

	// When this Vehicle enters, it becomes an artifact creature until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFleetwheelCruiserCard::BeforeAnimate));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CFleetwheelCruiserCard::BeforeAnimate(CAbilityAction* pAction)
{
	m_Crew.Animate(pAction->GetController());
	return true;
}

COvalchaseDragsterCard::COvalchaseDragsterCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ovalchase Dragster"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Trample, haste. Crew 1
	m_Crew.AddCrewAbility(1, _T("Ovalchase Dragster (Vehicle)"), 64108);
}

CRenegadeFreighterCard::CRenegadeFreighterCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Renegade Freighter"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Whenever this Vehicle attacks, it gets +1/+1 and gains trample until end of turn. (in the crewed creature) Crew 2
	m_Crew.AddCrewAbility(2, _T("Renegade Freighter (Vehicle)"), 64109);
}

CSkySkiffCard::CSkySkiffCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sky Skiff"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Flying. Crew 1
	m_Crew.AddCrewAbility(1, _T("Sky Skiff (Vehicle)"), 64110);
}

CSkysovereignConsulFlagshipCard::CSkysovereignConsulFlagshipCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Skysovereign, Consul Flagship"), CardType::Artifact | CardType::Legendary, nID,
		_T("5"), AbilityType::Artifact)
	, m_Crew(this)
{
	{
		// Whenever Skysovereign enters or attacks, it deals 3 damage to target creature or planeswalker an opponent
		// controls. (enters; attacks is in the crewed creature; only creatures can be targeted)
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-3));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}

	// Flying. Crew 3
	m_Crew.AddCrewAbility(3, _T("Skysovereign, Consul Flagship (Vehicle)"), 64111);
}

CSmugglersCopterCard::CSmugglersCopterCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Smuggler's Copter"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Flying. Whenever this Vehicle attacks or blocks, you may draw a card. If you do, discard a card.
	// (in the crewed creature) Crew 1
	m_Crew.AddCrewAbility(1, _T("Smuggler's Copter (Vehicle)"), 64112);
}

//____________________________________________________________________________
//
// Enchantments

// An artifact or an Artificer (Era of Innovation)
struct ArtifactOrArtificerComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsArtifact() || CreatureTypeComparer(CREATURE_TYPE(Artificer), false)(pCard);
	}

	virtual ArtifactOrArtificerComparer* Clone() const
	{
		return new ArtifactOrArtificerComparer;
	}
};

CAetherMeltdownCard::CAetherMeltdownCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Aether Meltdown"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(-4), Life(+0), CreatureKeyword::Null)
{
	// Flash. Enchant creature or Vehicle. Enchanted creature gets -4/-0.
	// Note: an uncrewed Vehicle can't be enchanted (it isn't a creature)
	GetCardKeyword()->AddFlash(FALSE);
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// When this Aura enters, you get {E}{E}.
	AddEnterTrigger(this, &CAetherMeltdownCard::BeforeEnergy);
}

bool CAetherMeltdownCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CAuthorityOfTheConsulsCard::CAuthorityOfTheConsulsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Authority of the Consuls"), CardType::GlobalEnchantment, nID,
		WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Creatures your opponents control enter tapped. (as Thalia, Heretic Cathar in Eldritch Moon)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::InPlayTapped,
				(int)CCardFilter::GetFilter(_T("creatures"))));

		cpAbility->SetAffectOpponentsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever a creature an opponent controls enters, you gain 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAuthorityOfTheConsulsCard::BeforeLife));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAuthorityOfTheConsulsCard::BeforeLife(CAbilityAction* pAction) const
{
	CLifeModifier pModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CConsulateSurveillanceCard::CConsulateSurveillanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Consulate Surveillance"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, you get {E}{E}{E}{E}.
	AddEnterTrigger(this, &CConsulateSurveillanceCard::BeforeEnergy);

	// Pay {E}{E}: Prevent all damage that would be dealt to you this turn by a source of your choice.
	// (as Circle of Protection: Red in Unlimited, any source)
	counted_ptr<CActivatedAbility<CDamagePreventionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDamagePreventionSpell>>(this,
			_T(""),
			Life(PreventionType::PreventAllDamage),
			SourceColor::_AllSources, TRUE));

	cpAbility->GetCost().AddEnergyCost(this, 2);
	AddAbility(cpAbility.GetPointer());
}

bool CConsulateSurveillanceCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 4);
	return true;
}

CDurableHandicraftCard::CDurableHandicraftCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Durable Handicraft"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever a creature you control enters, you may pay {1}. If you do, put a +1/+1 counter on that creature.
		// (as Olivia, Mobilized for War in Shadows over Innistrad)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("1"));
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDurableHandicraftCard::SetTriggerContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {5}{G}, Sacrifice this enchantment: Put a +1/+1 counter on each creature you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("5") GREEN_MANA_TEXT));

		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Put a +1/+1 counter on each creature you control. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDurableHandicraftCard::BeforeCounters));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDurableHandicraftCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	triggerContext.m_pCard = pCard;
	return true;
}

bool CDurableHandicraftCard::BeforeCounters(CAbilityAction* pAction) const
{
	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pModifier.ApplyTo(pBattlefield->GetAt(i));
	return true;
}

CEraOfInnovationCard::CEraOfInnovationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Era of Innovation"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever an artifact or Artificer you control enters, you may pay {1}. If you do, you get {E}{E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new ArtifactOrArtificerComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("1"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEraOfInnovationCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay six {E}, Sacrifice this enchantment: Draw three cards.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T(""), 3));

		cpAbility->GetCost().AddEnergyCost(this, 6);
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CEraOfInnovationCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CGiantSpectacleCard::CGiantSpectacleCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Giant Spectacle"), nID,
		_T("1") RED_MANA_TEXT,
		Power(+2), Life(+1), CreatureKeyword::CantBeBlockedBy1)
{
	// Enchanted creature gets +2/+1 and has menace.
}

CMalfunctionCard::CMalfunctionCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Malfunction"), nID,
		_T("3") BLUE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Null)
{
	// Enchant artifact or creature. Enchanted permanent doesn't untap during its controller's untap step.
	// (as Spectral Prison in Avacyn Restored) Note: only creatures can be enchanted
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// When this Aura enters, tap enchanted permanent.
	AddEnterTrigger(this, &CMalfunctionCard::BeforeTap);
}

bool CMalfunctionCard::BeforeTap(CAbilityAction* pAction) const
{
	CCard* pEnchanted = GetEnchantedOn();
	if (pEnchanted && pEnchanted->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pEnchanted);
	}
	return true;
}

CMetallurgicSummoningsCard::CMetallurgicSummoningsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Metallurgic Summonings"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever you cast an instant or sorcery spell, create an X/X colorless Construct artifact creature token,
		// where X is that spell's mana value.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CMetallurgicSummoningsCard::SetTriggerContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CMetallurgicSummoningsCard::BeforeConstruct));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{U}{U}, Exile this enchantment: Return all instant and sorcery cards from your graveyard to your hand.
		// Activate only if you control six or more artifacts.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT));

		cpAbility->AddExileCost();
		cpAbility->SetAbilityText(_T("Return all instant and sorcery cards from your graveyard to your hand. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMetallurgicSummoningsCard::BeforeReturn));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CMetallurgicSummoningsCard::CanReturn)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMetallurgicSummoningsCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	triggerContext.m_pCard = pCard;
	return true;
}

bool CMetallurgicSummoningsCard::BeforeConstruct(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pSpell = pAction->GetTriggerContext().m_pCard;
	int nX = pSpell ? (int)pSpell->GetConvertedManaCost() : 0;

	// A 0/0 Construct whose power and toughness become X (as Tezzeret the Seeker's -5 in Shards of Alara)
	CCountedCardContainer tokens;
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Construct (B)"), 55091, 1,
		FALSE, ZoneId::Battlefield, &tokens);
	pModifier.ApplyTo(pAction->GetController());

	CPowerModifier powerModifier;
	powerModifier.SetPowerDelta(Power(nX));
	powerModifier.SetToBase(TRUE);
	powerModifier.SetReplacement(TRUE);
	powerModifier.SetOneTurnOnly(FALSE);

	CLifeModifier lifeModifier;
	lifeModifier.SetLifeDelta(Life(nX));
	lifeModifier.SetToBase(TRUE);
	lifeModifier.SetReplacement(TRUE);
	lifeModifier.SetOneTurnOnly(FALSE);

	for (int i = 0; i < tokens.GetSize(); ++i)
	{
		CCreatureCard* pToken = dynamic_cast<CCreatureCard*>(tokens.GetAt(i));
		if (!pToken)
			continue;

		powerModifier.ApplyTo(pToken);
		lifeModifier.ApplyTo(pToken);
	}
	return true;
}

BOOL CMetallurgicSummoningsCard::CanReturn(BOOL bIncludeTricks)
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pBattlefield->GetCardContainer()) >= 6;
}

bool CMetallurgicSummoningsCard::BeforeReturn(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer cards;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if ((pGraveyard->GetAt(i)->GetCardType() & (CardType::Instant | CardType::Sorcery)).Any())
			cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		pModifier.ApplyTo(cards.GetAt(i));
	return true;
}

CRevokePrivilegesCard::CRevokePrivilegesCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Revoke Privileges"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
{
	// Enchanted creature can't attack, block, or crew Vehicles.
	// Note: "or crew Vehicles" is not implemented
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CUnderhandedDesignsCard::CUnderhandedDesignsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Underhanded Designs"), CardType::GlobalEnchantment, nID,
		_T("1") BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever an artifact you control enters, you may pay {1}. If you do, each opponent loses 1 life and you gain
		// 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("1"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUnderhandedDesignsCard::BeforeDrain));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}, Sacrifice this enchantment: Destroy target creature. Activate only if you control two or more artifacts.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->AddSacrificeCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CUnderhandedDesignsCard::CanDestroy)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

bool CUnderhandedDesignsCard::BeforeDrain(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CLifeModifier pLoseModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pLoseModifier.ApplyTo(pOpponent);
	}

	CLifeModifier pGainModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable);
	pGainModifier.ApplyTo(pController);
	return true;
}

BOOL CUnderhandedDesignsCard::CanDestroy(BOOL bIncludeTricks)
{
	CZone* pBattlefield = GetController()->GetZoneById(ZoneId::Battlefield);
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pBattlefield->GetCardContainer()) >= 2;
}

//____________________________________________________________________________
//
// Sorceries

// Puts a card named strName from the player's graveyard or library into their hand (the library is shuffled if searched)
static void FindNamedCard(CPlayer* pPlayer, LPCTSTR strName)
{
	ZoneId zones[] = { ZoneId::Graveyard, ZoneId::Library };
	for (int z = 0; z < 2; ++z)
	{
		CZone* pZone = pPlayer->GetZoneById(zones[z]);
		for (int i = 0; i < pZone->GetSize(); ++i)
		{
			CCard* pCard = pZone->GetAt(i);
			if (pCard->GetCardName(FALSE) != strName)
				continue;

			pCard->Move(pPlayer->GetZoneById(ZoneId::Hand), pPlayer, MoveType::Others);
			if (zones[z] == ZoneId::Library)
				pZone->Shuffle();
			return;
		}
	}
}

CAttuneWithAetherCard::CAttuneWithAetherCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Attune with Aether"), CardType::Sorcery, nID)
{
	// Search your library for a basic land card, reveal it, put it into your hand, then shuffle. You get {E}{E}.
	counted_ptr<CSearchLibrarySpell> cpSpell(
		::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT,
			CCardFilter::GetFilter(_T("basic lands")),
			ZoneId::Hand, TRUE, FALSE, FALSE));

	cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAttuneWithAetherCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAttuneWithAetherCard::BeforeResolution(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CCatharticReunionCard::CCatharticReunionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cathartic Reunion"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, discard two cards. Draw three cards.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT, 3));

	cpSpell->GetCost().AddDiscardCardCost(2, CCardFilter::GetFilter(_T("cards")));
	AddSpell(cpSpell.GetPointer());
}

CConfiscationCoupCard::CConfiscationCoupCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Confiscation Coup"), CardType::Sorcery, nID)
{
	// Choose target artifact or creature. You get {E}{E}{E}{E}, then you may pay an amount of {E} equal to that
	// permanent's mana value. If you do, gain control of it.
	// Note: the energy is paid whenever you have enough
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature, false), FALSE));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConfiscationCoupCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CConfiscationCoupCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	GetEnergy((CCard*)this, pController, 4);

	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	int nManaValue = (int)pCard->GetConvertedManaCost();
	if (pController->GetEnergyCounters() < nManaValue)
		return true;

	if (nManaValue > 0)
		GetEnergy((CCard*)this, pController, -nManaValue);

	// Gain control of it (as Welcome to the Fold in Shadows over Innistrad)
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others, pController);
	pModifier.ApplyTo(pCard);
	return true;
}

CDieYoungCard::CDieYoungCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Die Young"), CardType::Sorcery, nID)
	, m_PaySelection(pGame, CSelectionSupport::SelectionCallback(this, &CDieYoungCard::OnPaySelected))
{
	// Choose target creature. You get {E}{E}, then you may pay any amount of {E}. The creature gets -1/-1 until end
	// of turn for each {E} paid this way.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDieYoungCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDieYoungCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	GetEnergy(this, pController, 2);

	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	// The amount of energy to pay
	std::vector<SelectionEntry> entries;
	for (int n = pController->GetEnergyCounters(); n >= 0; --n)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)n;
		entry.strText.Format(_T("Pay %d energy (-%d/-%d)"), n, n, n);
		entries.push_back(entry);
	}
	m_PaySelection.AddSelectionRequest(entries, 1, 1, this, pController, (DWORD)pCard);
	return true;
}

void CDieYoungCard::OnPaySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int nPaid = (int)it->dwContext;
			if (nPaid <= 0 || pSelectionPlayer->GetEnergyCounters() < nPaid)
				return;

			GetEnergy(this, pSelectionPlayer, -nPaid);
			if (pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
				return;

			CPowerModifier pPowerModifier = CPowerModifier(Power(-nPaid));
			pPowerModifier.ApplyTo((CCreatureCard*)pCard);
			CLifeModifier pLifeModifier = CLifeModifier(Life(-nPaid), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pLifeModifier.ApplyTo((CCreatureCard*)pCard);
			return;
		}
}

CEngineeredMightCard::CEngineeredMightCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Engineered Might"), CardType::Sorcery, nID)
{
	// Choose one -
	{
		// Target creature gets +5/+5 and gains trample until end of turn.
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
				_T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT,
				Power(+5), Life(+5),
				CreatureKeyword::Trample, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Creatures you control get +2/+2 and gain vigilance until end of turn.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("3") GREEN_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->SetAbilityText(_T("Creatures you control get +2/+2 and gain vigilance until end of turn. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEngineeredMightCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CEngineeredMightCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(+2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CCreatureKeywordModifier pVigilanceModifier;
	pVigilanceModifier.GetModifier().SetToAdd(CreatureKeyword::Vigilance);
	pVigilanceModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
		if (!pCreature || !pCreature->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo(pCreature);
		pLifeModifier.ApplyTo(pCreature);
		pVigilanceModifier.ApplyTo(pCreature);
	}
	return true;
}

CFortuitousFindCard::CFortuitousFindCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fortuitous Find"), CardType::Sorcery, nID)
{
	// Choose one or both - Return target artifact card from your graveyard to your hand; and/or return target
	// creature card from your graveyard to your hand. (as Dawn to Dusk in Born of the Gods)
	CardType types[] = { CardType::Artifact, CardType::Creature };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("2") BLACK_MANA_TEXT,
				new CardTypeComparer(types[i], false),
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("2") BLACK_MANA_TEXT,
				new CardTypeComparer(CardType::Artifact, false), FALSE,
				new CardTypeComparer(CardType::Creature, false), FALSE, _T("")));

		cpSpell->GetTargeting1()->SetSubjectZoneId(ZoneId::Graveyard);
		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting2()->SetSubjectZoneId(ZoneId::Graveyard);
		cpSpell->GetTargeting2()->SetIncludeControllerCardsOnly();
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFortuitousFindCard::BeforeResolutionBoth));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CFortuitousFindCard::BeforeResolutionBoth(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
	CCard* pCards[] = { (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
						(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject() };
	for (int i = 0; i < 2; ++i)
		if (pCards[i] && pCards[i]->GetZoneId() == ZoneId::Graveyard)
			pModifier.ApplyTo(pCards[i]);
	return true;
}

CFragmentizeCard::CFragmentizeCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Fragmentize"), CardType::Sorcery, nID,
		WHITE_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	// Destroy target artifact or enchantment with mana value 4 or less.
	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(4));
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CFumigateCard::CFumigateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fumigate"), CardType::Sorcery, nID)
{
	// Destroy all creatures. You gain 1 life for each creature destroyed this way.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFumigateCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CFumigateCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CPlayer* pController = pAction->GetController();
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pController);
	int nDestroyed = 0;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCard* pCard = creatures.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;

		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			++nDestroyed;
	}

	if (nDestroyed > 0)
	{
		CLifeModifier pLifeModifier = CLifeModifier(Life(+nDestroyed), (CCard*)this, PreventableType::NotPreventable);
		pLifeModifier.ApplyTo(pController);
	}
	return true;
}

CFuriousReprisalCard::CFuriousReprisalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Furious Reprisal"), CardType::Sorcery, nID)
{
	// Furious Reprisal deals 2 damage to each of two targets.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpSpell->GetTargeting()->SetSubjectCount(2, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CHarshScrutinyCard::CHarshScrutinyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Harsh Scrutiny"), CardType::Sorcery, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CHarshScrutinyCard::OnCardSelected))
{
	// Target opponent reveals their hand. You choose a creature card from it. That player discards that card. Scry 1.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHarshScrutinyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHarshScrutinyCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (pOpponent)
	{
		// (as Distended Mindbender in Eldritch Moon)
		CZone* pHand = pOpponent->GetZoneById(ZoneId::Hand);
		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pHand->GetSize(); ++i)
		{
			CCard* pCard = pHand->GetAt(i);
			if (!pCard->GetCardType().IsCreature())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}

		if (!entries.empty())
			m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	}

	ApplyScry(GetGame(), pController, this, 1);
	return true;
}

void CHarshScrutinyCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
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

CHazardousConditionsCard::CHazardousConditionsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hazardous Conditions"), CardType::Sorcery, nID)
{
	// Creatures with no counters on them get -2/-2 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHazardousConditionsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHazardousConditionsCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(-2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() && dynamic_cast<CCreatureCard*>(pCard) &&
				pCard->GetCounterContainer()->GetTotalCount() == 0)
				creatures.AddCard(pCard, CardPlacement::Top);
		}
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
	}
	return true;
}

CHijackCard::CHijackCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hijack"), CardType::Sorcery, nID)
{
	// Gain control of target artifact or creature until end of turn. Untap it. It gains haste until end of turn.
	// (as Act of Treason in M10)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT RED_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature, false),
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpSpell->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	cpSpell->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);
	AddSpell(cpSpell.GetPointer());
}

CLargerThanLifeCard::CLargerThanLifeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Larger Than Life"), CardType::Sorcery, nID)
{
	// Target creature gets +4/+4 and gains trample until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
			_T("1") GREEN_MANA_TEXT,
			Power(+4), Life(+4),
			CreatureKeyword::Trample, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));
	AddSpell(cpSpell.GetPointer());
}

CLiberatingCombustionCard::CLiberatingCombustionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Liberating Combustion"), CardType::Sorcery, nID)
{
	// Liberating Combustion deals 6 damage to target creature. You may search your library and/or graveyard for a card
	// named Chandra, Pyrogenius, reveal it, and put it into your hand. If you search your library this way, shuffle.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("4") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-6), PreventableType::Preventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLiberatingCombustionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CLiberatingCombustionCard::BeforeResolution(CAbilityAction* pAction) const
{
	FindNamedCard(pAction->GetController(), _T("Chandra, Pyrogenius"));
	return true;
}

CLiveFastCard::CLiveFastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Live Fast"), CardType::Sorcery, nID)
{
	// You draw two cards, lose 2 life, and get {E}{E}.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT, 2));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLiveFastCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	AddSpell(cpSpell.GetPointer());
}

bool CLiveFastCard::BeforeResolution(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CMadcapExperimentCard::CMadcapExperimentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Madcap Experiment"), CardType::Sorcery, nID)
{
	// Reveal cards from the top of your library until you reveal an artifact card. Put that card onto the battlefield
	// and the rest on the bottom of your library in a random order. Madcap Experiment deals damage to you equal to the
	// number of cards revealed this way.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMadcapExperimentCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CMadcapExperimentCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	CCountedCardContainer revealed;
	CCard* pArtifact = NULL;
	for (int i = pLibrary->GetSize() - 1; i >= 0; --i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		revealed.AddCard(pCard, CardPlacement::Top);
		if (pCard->GetCardType().IsArtifact())
		{
			pArtifact = pCard;
			break;
		}
	}

	if (pArtifact)
		pArtifact->Move(pController->GetZoneById(ZoneId::Battlefield), pController, MoveType::Others);

	for (int i = 0; i < revealed.GetSize(); ++i)
	{
		CCard* pCard = revealed.GetAt(i);
		if (pCard != pArtifact && pCard->GetZoneId() == ZoneId::Library)
			pCard->Move(pLibrary, pController, MoveType::Others, CardPlacement::Bottom);
	}

	if (revealed.GetSize() > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-revealed.GetSize()), (CCard*)this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pController);
	}
	return true;
}

CMorbidCuriosityCard::CMorbidCuriosityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Morbid Curiosity"), CardType::Sorcery, nID)
	, m_SacrificeFilter(_T("an artifact or creature"), _T("artifacts or creatures"), new CardTypeComparer(CardType::Artifact | CardType::Creature, false))
{
	// As an additional cost to cast this spell, sacrifice an artifact or creature.
	// Draw cards equal to the mana value of the sacrificed permanent.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMorbidCuriosityCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CMorbidCuriosityCard::BeforeResolution(CAbilityAction* pAction) const
{
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	int nCount = (pSacrificed && pSacrificed->GetSize()) ? (int)pSacrificed->GetAt(0)->GetConvertedManaCost() : 0;
	if (nCount > 0)
	{
		CDrawCardModifier pModifier = CDrawCardModifier(GetGame(), MinimumValue(nCount), MaximumValue(nCount));
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CNaturesWayCard::CNaturesWayCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nature's Way"), CardType::Sorcery, nID)
{
	// Target creature you control gains vigilance and trample until end of turn. It deals damage equal to its power
	// to target creature you don't control. (as Clear Shot in Eldritch Moon)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("1") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNaturesWayCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CNaturesWayCard::BeforeResolution(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pSource = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (!pSource || pSource->GetZoneId() != ZoneId::Battlefield || !dynamic_cast<CCreatureCard*>(pSource))
		return true;

	CCreatureCard* pCreature = (CCreatureCard*)pSource;
	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::Vigilance | CreatureKeyword::Trample);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);

	int nPower = GET_INTEGER(pCreature->GetPower());
	if (nPower > 0 && pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && dynamic_cast<CCreatureCard*>(pTarget))
	{
		CLifeModifier pDamageModifier = CLifeModifier(Life(-nPower), pCreature, PreventableType::Preventable, DamageType::NonCombatDamage);
		pDamageModifier.ApplyTo((CCreatureCard*)pTarget);
	}
	return true;
}

CRefurbishCard::CRefurbishCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Refurbish"), CardType::Sorcery, nID,
		_T("3") WHITE_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Artifact, false),
		ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others)
{
	// Return target artifact card from your graveyard to the battlefield.
	m_pTargetMoveCardSpell->GetTargeting()->SetIncludeControllerCardsOnly();
}

CRenegadeTacticsCard::CRenegadeTacticsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Renegade Tactics"), CardType::Sorcery, nID)
{
	// Target creature can't block this turn. Draw a card.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::CantBlock, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));
	AddSpell(cpSpell.GetPointer());
}

CSaheelisArtistryCard::CSaheelisArtistryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Saheeli's Artistry"), CardType::Sorcery, nID)
{
	// Choose one or both - Create a token that's a copy of target artifact; and/or create a token that's a copy of
	// target creature, except it's an artifact in addition to its other types. (as Saheeli Rai's -2)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
				new CardTypeComparer(CardType::Artifact, false), FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaheelisArtistryCard::BeforeArtifact));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaheelisArtistryCard::BeforeCreature));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT,
				new CardTypeComparer(CardType::Artifact, false), FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSaheelisArtistryCard::BeforeBoth));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());
	}
}

void CSaheelisArtistryCard::CopyCard(CCard* pCard, BOOL bArtifact) const
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CCardCopyModifier pModifier = CCardCopyModifier(GetGame(), pCard,
		bArtifact ? new CCardTypeModifier(CardType::Artifact) : NULL);
	pModifier.ApplyTo(pCard);
}

bool CSaheelisArtistryCard::BeforeArtifact(CAbilityAction* pAction) const
{
	CopyCard(pAction->GetAssociatedCard(), FALSE);
	return true;
}

bool CSaheelisArtistryCard::BeforeCreature(CAbilityAction* pAction) const
{
	CopyCard(pAction->GetAssociatedCard(), TRUE);
	return true;
}

bool CSaheelisArtistryCard::BeforeBoth(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CopyCard((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(), FALSE);
	CopyCard((CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject(), TRUE);
	return true;
}

CServoExhibitionCard::CServoExhibitionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Servo Exhibition"), CardType::Sorcery, nID)
{
	// Create two 1/1 colorless Servo artifact creature tokens.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT,
			SERVO_TOKEN_NAME, SERVO_TOKEN_ID,
			2));
	AddSpell(cpSpell.GetPointer());
}

CTakeDownCard::CTakeDownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Take Down"), CardType::Sorcery, nID)
{
	// Choose one -
	{
		// Take Down deals 4 damage to target creature with flying.
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				GREEN_MANA_TEXT,
				new CreatureKeywordComparer(CreatureKeyword::Flying, false), FALSE,
				Life(-4), PreventableType::Preventable));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Take Down deals 1 damage to each creature with flying.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				GREEN_MANA_TEXT));

		cpSpell->SetAbilityText(_T("Take Down deals 1 damage to each creature with flying. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTakeDownCard::BeforeResolution));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CTakeDownCard::BeforeResolution(CAbilityAction* pAction) const
{
	CLifeModifier pModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);

	CCountedCardContainer flyers;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
			if (pCreature && pCreature->GetCardType().IsCreature() && pCreature->GetCreatureKeyword()->Flying())
				flyers.AddCard(pCreature, CardPlacement::Top);
		}
	}

	for (int i = 0; i < flyers.GetSize(); ++i)
		pModifier.ApplyTo((CCreatureCard*)flyers.GetAt(i));
	return true;
}

CTezzeretsAmbitionCard::CTezzeretsAmbitionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tezzeret's Ambition"), CardType::Sorcery, nID)
{
	// Draw three cards. If you control no artifacts, discard a card.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretsAmbitionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTezzeretsAmbitionCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(3), MaximumValue(3));
	pDrawModifier.ApplyTo(pController);

	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	if (CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pBattlefield->GetCardContainer()) == 0)
	{
		CZoneModifier pModifier = CZoneModifier(GetGame(),
			ZoneId::Hand, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select a card to discard
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::PrimaryPlayer, // reveal to
			CCardFilter::GetFilter(_T("cards")), // what cards
			ZoneId::Graveyard, // if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top, // put selected cards on
			MoveType::Discard, // move type
			CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
		pModifier.ApplyTo(pController);
	}
	return true;
}

CVerdantCrescendoCard::CVerdantCrescendoCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Verdant Crescendo"), CardType::Sorcery, nID)
{
	// Search your library for a basic land card and put it onto the battlefield tapped. Search your library and
	// graveyard for a card named Nissa, Nature's Artisan, reveal it, put it into your hand, then shuffle.
	counted_ptr<CSearchLibrarySpell> cpSpell(
		::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT,
			CCardFilter::GetFilter(_T("basic lands")),
			ZoneId::Battlefield, FALSE, FALSE, TRUE));

	cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVerdantCrescendoCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CVerdantCrescendoCard::BeforeResolution(CAbilityAction* pAction) const
{
	FindNamedCard(pAction->GetController(), _T("Nissa, Nature's Artisan"));
	return true;
}

CWildestDreamsCard::CWildestDreamsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wildest Dreams"), CardType::Sorcery, nID)
{
	// Return X target cards from your graveyard to your hand. Exile Wildest Dreams.
	// Note: the cards are chosen on resolution (not targeted)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT));

	// {X}{X}{G}: X is half of the extra mana paid (as Dark Salvation in Eldritch Moon)
	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWildestDreamsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWildestDreamsCard::BeforeResolution(CAbilityAction* pAction) const
{
	int nX = pAction->GetCostConfigEntry().GetExtraValue();
	if (nX < 0)
		nX = -nX;
	if (nX <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nX), // select up to X cards
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		CCardFilter::GetFilter(_T("cards")),	// any cards
		ZoneId::Hand,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
// Instants

// The player discards nCount cards of their choice
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

static int CountArtifacts(CPlayer* pPlayer)
{
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
}

static void DrawCards(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CDrawCardModifier pModifier = CDrawCardModifier(pGame, MinimumValue(nCount), MaximumValue(nCount));
	pModifier.ApplyTo(pPlayer);
}

static void GainLife(CCard* pSource, CPlayer* pPlayer, int nLife)
{
	CLifeModifier pModifier = CLifeModifier(Life(+nLife), pSource, PreventableType::NotPreventable);
	pModifier.ApplyTo(pPlayer);
}

// The spell pSource deals nDamage damage to the creature pCard (if it's still a creature on the battlefield)
static void DamageCreature(CCard* pSource, CCard* pCard, int nDamage)
{
	if (nDamage <= 0 || !pCard || pCard->GetZoneId() != ZoneId::Battlefield ||
		!pCard->GetCardType().IsCreature() || !dynamic_cast<CCreatureCard*>(pCard))
		return;

	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo((CCreatureCard*)pCard);
}

static void DamagePlayer(CCard* pSource, CPlayer* pPlayer, int nDamage)
{
	if (nDamage <= 0 || !pPlayer)
		return;

	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pPlayer);
}

struct ColorlessCardComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return !(pCard->GetCardType() & CardType::_ColorMask).Any();
	}

	virtual ColorlessCardComparer* Clone() const
	{
		return new ColorlessCardComparer;
	}
};

CAcrobaticManeuverCard::CAcrobaticManeuverCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Acrobatic Maneuver"), CardType::Instant, nID)
{
	// Exile target creature you control, then return that card to the battlefield under its owner's control.
	// Draw a card.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAcrobaticManeuverCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAcrobaticManeuverCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CPlayer* pOwner = pCard->GetOwner();
		CMoveCardModifier pExileModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pExileModifier.ApplyTo(pCard);

		if (pCard->GetZoneId() == ZoneId::Exile)
		{
			CMoveCardModifier pReturnModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pOwner);
			pReturnModifier.ApplyTo(pCard);
		}
	}

	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CAetherTradewindsCard::CAetherTradewindsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Aether Tradewinds"), CardType::Instant, nID)
{
	// Return target permanent you control and target permanent you don't control to their owners' hands.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new TrueCardComparer, FALSE,
			new TrueCardComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherTradewindsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CAetherTradewindsCard::BeforeResolution(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
	CCard* pCards[] = { (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
						(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject() };
	for (int i = 0; i < 2; ++i)
		if (pCards[i] && pCards[i]->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(pCards[i]);
	return true;
}

CAppetiteForTheUnnaturalCard::CAppetiteForTheUnnaturalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Appetite for the Unnatural"), CardType::Instant, nID)
{
	// Destroy target artifact or enchantment. You gain 2 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAppetiteForTheUnnaturalCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CAppetiteForTheUnnaturalCard::BeforeResolution(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 2);
	return true;
}

CBlossomingDefenseCard::CBlossomingDefenseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blossoming Defense"), CardType::Instant, nID)
{
	// Target creature you control gets +2/+2 and gains hexproof until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT,
			Power(+2), Life(+2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	cpSpell->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	AddSpell(cpSpell.GetPointer());
}

CBuiltToLastCard::CBuiltToLastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Built to Last"), CardType::Instant, nID)
{
	// Target creature gets +2/+2 until end of turn. If it's an artifact creature, it gains indestructible until end
	// of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT,
			Power(+2), Life(+2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBuiltToLastCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBuiltToLastCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetCardType().IsArtifact())
	{
		CCardKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CBuiltToSmashCard::CBuiltToSmashCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Built to Smash"), CardType::Instant, nID)
{
	// Target attacking creature gets +3/+3 until end of turn. If it's an artifact creature, it gains trample until
	// end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			Power(+3), Life(+3),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBuiltToSmashCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CBuiltToSmashCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetCardType().IsArtifact() &&
		dynamic_cast<CCreatureCard*>(pCard))
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo((CCreatureCard*)pCard);
	}
	return true;
}

CCeremoniousRejectionCard::CCeremoniousRejectionCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Ceremonious Rejection"), CardType::Instant, nID,
		BLUE_MANA_TEXT, AbilityType::Instant,
		new ColorlessCardComparer)
{
	// Counter target colorless spell.
}

CChandrasPyrohelixCard::CChandrasPyrohelixCard(CGame* pGame, UINT nID)
	: CTargetChgLifeSpellCard(pGame, _T("Chandra's Pyrohelix"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") RED_MANA_TEXT,
		new AnyCreatureComparer,
		TRUE,
		Life(-2),
		PreventableType::Preventable)
{
	// Chandra's Pyrohelix deals 2 damage divided as you choose among one or two targets. (as Forked Bolt)
	m_pTargetChgLifeSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	m_pTargetChgLifeSpell->GetTargeting()->SetDistributeValues();
}

CCommencementOfFestivitiesCard::CCommencementOfFestivitiesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Commencement of Festivities"), CardType::Instant, nID)
{
	// Prevent all combat damage that would be dealt to players this turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCommencementOfFestivitiesCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CCommencementOfFestivitiesCard::BeforeResolution(CAbilityAction* pAction) const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CScheduledPlayerModifier pModifier = CScheduledPlayerModifier(GetGame(),
			new CPlayerEffectModifier(PlayerEffectType::PreventPlayerCombatDamage),
			TurnNumberDelta(-1), NodeId::CleanupStep2, CScheduledPlayerModifier::Operation::ApplyToNowRemoveLater);
		pModifier.ApplyTo(GetGame()->GetPlayer(ip));
	}
	return true;
}

CDisappearingActCard::CDisappearingActCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Disappearing Act"), CardType::Instant, nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	// As an additional cost to cast this spell, return a permanent you control to its owner's hand.
	// Counter target spell.
	m_pCounterSpell->GetCost().AddReturnFromPlayCardCost(1, CCardFilter::GetFilter(_T("permanents")));
}

CDramaticReversalCard::CDramaticReversalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dramatic Reversal"), CardType::Instant, nID)
{
	// Untap all nonland permanents you control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDramaticReversalCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDramaticReversalCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsLand() && pCard->GetOrientation()->IsTapped())
			pModifier.ApplyTo(pCard);
	}
	return true;
}

CEssenceExtractionCard::CEssenceExtractionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Essence Extraction"), CardType::Instant, nID)
{
	// Essence Extraction deals 3 damage to target creature and you gain 3 life.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-3), PreventableType::Preventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEssenceExtractionCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CEssenceExtractionCard::BeforeResolution(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 3);
	return true;
}

CFailedInspectionCard::CFailedInspectionCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Failed Inspection"), CardType::Instant, nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	// Counter target spell. Draw a card, then discard a card.
	m_pCounterSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFailedInspectionCard::BeforeResolution));
}

bool CFailedInspectionCard::BeforeResolution(CAbilityAction* pAction) const
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CFatefulShowdownCard::CFatefulShowdownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fateful Showdown"), CardType::Instant, nID)
{
	// Fateful Showdown deals damage to any target equal to the number of cards in your hand. Discard all the cards in
	// your hand, then draw that many cards.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFatefulShowdownCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CFatefulShowdownCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);
	int nCards = pHand->GetSize();

	if (pAction->GetAssociatedCard())
		DamageCreature((CCard*)this, pAction->GetAssociatedCard(), nCards);
	else
		DamagePlayer((CCard*)this, pAction->GetAssociatedPlayer(), nCards);

	CCountedCardContainer hand;
	for (int i = 0; i < pHand->GetSize(); ++i)
		hand.AddCard(pHand->GetAt(i), CardPlacement::Top);

	int nDiscarded = 0;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	for (int i = 0; i < hand.GetSize(); ++i)
		if (hand.GetAt(i)->GetZoneId() == ZoneId::Hand)
		{
			pModifier.ApplyTo(hand.GetAt(i));
			++nDiscarded;
		}

	if (nDiscarded > 0)
		DrawCards(GetGame(), pController, nDiscarded);
	return true;
}

CFlameLashCard::CFlameLashCard(CGame* pGame, UINT nID)
	: CTargetChgLifeSpellCard(pGame, _T("Flame Lash"), CardType::Instant, nID, AbilityType::Instant,
		_T("3") RED_MANA_TEXT,
		new AnyCreatureComparer,
		TRUE,
		Life(-4),
		PreventableType::Preventable)
{
	// Flame Lash deals 4 damage to any target.
	m_pTargetChgLifeSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
}

CGlimmerOfGeniusCard::CGlimmerOfGeniusCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Glimmer of Genius"), CardType::Instant, nID)
{
	// Scry 2, then draw two cards. You get {E}{E}.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGlimmerOfGeniusCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGlimmerOfGeniusCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	ApplyScry(GetGame(), pController, (CCard*)this, 2);
	DrawCards(GetGame(), pController, 2);
	GetEnergy((CCard*)this, pController, 2);
	return true;
}

CHarnessedLightningCard::CHarnessedLightningCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Harnessed Lightning"), CardType::Instant, nID)
	, m_PaySelection(pGame, CSelectionSupport::SelectionCallback(this, &CHarnessedLightningCard::OnPaySelected))
{
	// Choose target creature. You get {E}{E}{E}, then you may pay any amount of {E}. Harnessed Lightning deals that
	// much damage to that creature.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHarnessedLightningCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHarnessedLightningCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	GetEnergy(this, pController, 3);

	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	// The amount of energy to pay (as Die Young)
	std::vector<SelectionEntry> entries;
	for (int n = pController->GetEnergyCounters(); n >= 0; --n)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)n;
		entry.strText.Format(_T("Pay %d energy (%d damage)"), n, n);
		entries.push_back(entry);
	}
	m_PaySelection.AddSelectionRequest(entries, 1, 1, this, pController, (DWORD)pCard);
	return true;
}

void CHarnessedLightningCard::OnPaySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int nPaid = (int)it->dwContext;
			if (nPaid <= 0 || pSelectionPlayer->GetEnergyCounters() < nPaid)
				return;

			GetEnergy(this, pSelectionPlayer, -nPaid);
			DamageCreature(this, pCard, nPaid);
			return;
		}
}

CImpeccableTimingCard::CImpeccableTimingCard(CGame* pGame, UINT nID)
	: CTargetChgLifeSpellCard(pGame, _T("Impeccable Timing"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") WHITE_MANA_TEXT,
		new AttackingBlockingCreatureComparer,
		FALSE,
		Life(-3),
		PreventableType::Preventable)
{
	// Impeccable Timing deals 3 damage to target attacking or blocking creature.
	m_pTargetChgLifeSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
}

CIncendiarySabotageCard::CIncendiarySabotageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Incendiary Sabotage"), CardType::Instant, nID)
{
	// As an additional cost to cast this spell, sacrifice an artifact.
	// Incendiary Sabotage deals 3 damage to each creature.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT RED_MANA_TEXT));

	cpSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIncendiarySabotageCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CIncendiarySabotageCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		DamageCreature((CCard*)this, creatures.GetAt(i), 3);
	return true;
}

CMakeObsoleteCard::CMakeObsoleteCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Make Obsolete"), CardType::Instant, nID)
{
	// Creatures your opponents control get -1/-1 until end of turn.
	counted_ptr<CPwrTghAttrEnchantment> cpSpell(
		::CreateObject<CPwrTghAttrEnchantment>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			Power(-1), Life(-1)));

	cpSpell->SetAffectOpponentCardsOnly();
	AddSpell(cpSpell.GetPointer());
}

COrnamentalCourageCard::COrnamentalCourageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ornamental Courage"), CardType::Instant, nID)
{
	// Untap target creature. It gets +1/+3 until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			GREEN_MANA_TEXT,
			Power(+1), Life(+3),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COrnamentalCourageCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool COrnamentalCourageCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && pCard->GetOrientation()->IsTapped())
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CParadoxicalOutcomeCard::CParadoxicalOutcomeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Paradoxical Outcome"), CardType::Instant, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CParadoxicalOutcomeCard::OnCardsSelected))
{
	// Return any number of target nonland, nontoken permanents you control to their owners' hands. Draw a card for
	// each card returned to your hand this way.
	// Note: the permanents are chosen on resolution (not targeted)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CParadoxicalOutcomeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CParadoxicalOutcomeCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsLand() || pCard->GetCardType().IsToken())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Return %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this, pController);
	return true;
}

void CParadoxicalOutcomeCard::OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	int nReturned = 0;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;

		pModifier.ApplyTo(pCard);
		if (pCard->GetZoneId() == ZoneId::Hand && pCard->GetOwner() == pSelectionPlayer)
			++nReturned;
	}

	if (nReturned > 0)
		DrawCards(GetGame(), pSelectionPlayer, nReturned);
}

CRevolutionaryRebuffCard::CRevolutionaryRebuffCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Revolutionary Rebuff"), CardType::Instant, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Instant,
		new NegateCardComparer(new CardTypeComparer(CardType::Artifact, false)))
{
	// Counter target nonartifact spell unless its controller pays {2}. (as Mana Leak)
	m_pCounterSpell->SetCanBeDenied();
	m_pCounterSpell->GetDenialCost().SetManaCost(_T("2"));
}

CRushOfVitalityCard::CRushOfVitalityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rush of Vitality"), CardType::Instant, nID)
{
	// Target creature gets +1/+0 and gains lifelink and indestructible until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT,
			Power(+1), Life(+0),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Lifelink | CardKeyword::Indestructible);
	cpSpell->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	AddSpell(cpSpell.GetPointer());
}

CSelectForInspectionCard::CSelectForInspectionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Select for Inspection"), CardType::Instant, nID)
{
	// Return target tapped creature to its owner's hand. Scry 1.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new TappedComparer);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSelectForInspectionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSelectForInspectionCard::BeforeResolution(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 1);
	return true;
}

CSkywhalersShotCard::CSkywhalersShotCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Skywhaler's Shot"), CardType::Instant, nID)
{
	// Destroy target creature with power 3 or greater. Scry 1.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new CreaturePowerComparer<std::greater_equal<int>>(3),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkywhalersShotCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSkywhalersShotCard::BeforeResolution(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 1);
	return true;
}

CSubtleStrikeCard::CSubtleStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Subtle Strike"), CardType::Instant, nID)
{
	// Choose one or both - Target creature gets -1/-1 until end of turn; and/or put a +1/+1 counter on target
	// creature.
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Target creature gets -1/-1 until end of turn. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSubtleStrikeCard::BeforeWeaken));
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetAbilityText(_T("Put a +1/+1 counter on target creature. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSubtleStrikeCard::BeforeCounter));
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSubtleStrikeCard::BeforeBoth));
		AddSpell(cpSpell.GetPointer());
	}
}

void CSubtleStrikeCard::Weaken(CCard* pCard) const
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature() ||
		!dynamic_cast<CCreatureCard*>(pCard))
		return;

	CPowerModifier pPowerModifier = CPowerModifier(Power(-1));
	pPowerModifier.ApplyTo((CCreatureCard*)pCard);
	CLifeModifier pLifeModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo((CCreatureCard*)pCard);
}

void CSubtleStrikeCard::AddCounter(CCard* pCard) const
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
	pModifier.ApplyTo(pCard);
}

bool CSubtleStrikeCard::BeforeWeaken(CAbilityAction* pAction) const
{
	Weaken(pAction->GetAssociatedCard());
	return true;
}

bool CSubtleStrikeCard::BeforeCounter(CAbilityAction* pAction) const
{
	AddCounter(pAction->GetAssociatedCard());
	return true;
}

bool CSubtleStrikeCard::BeforeBoth(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	Weaken((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	AddCounter((CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject());
	return true;
}

CTidyConclusionCard::CTidyConclusionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tidy Conclusion"), CardType::Instant, nID)
{
	// Destroy target creature. You gain 1 life for each artifact you control.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTidyConclusionCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CTidyConclusionCard::BeforeResolution(CAbilityAction* pAction) const
{
	int nArtifacts = CountArtifacts(pAction->GetController());
	if (nArtifacts > 0)
		GainLife((CCard*)this, pAction->GetController(), nArtifacts);
	return true;
}

CUnlicensedDisintegrationCard::CUnlicensedDisintegrationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unlicensed Disintegration"), CardType::Instant, nID)
{
	// Destroy target creature. If you control an artifact, Unlicensed Disintegration deals 3 damage to that
	// creature's controller.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUnlicensedDisintegrationCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CUnlicensedDisintegrationCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && CountArtifacts(pAction->GetController()) > 0)
		DamagePlayer((CCard*)this, pCard->GetController(), 3);
	return true;
}

CWeldingSparksCard::CWeldingSparksCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Welding Sparks"), CardType::Instant, nID)
{
	// Welding Sparks deals X damage to target creature, where X is 3 plus the number of artifacts you control.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWeldingSparksCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWeldingSparksCard::BeforeResolution(CAbilityAction* pAction) const
{
	DamageCreature((CCard*)this, pAction->GetAssociatedCard(), 3 + CountArtifacts(pAction->GetController()));
	return true;
}

//____________________________________________________________________________
//
// Fabricate

CFabricateSupport::CFabricateSupport(CCreatureCard* pCard, int nCount)
	: m_pCard(pCard)
	, m_nCount(nCount)
	, m_Selection(pCard->GetGame(), CSelectionSupport::SelectionCallback(this, &CFabricateSupport::OnSelected))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFabricateSupport::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	pCard->AddAbility(cpAbility.GetPointer());
}

bool CFabricateSupport::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

	// If the creature isn't on the battlefield, the Servos are created
	if (m_pCard->GetZoneId() != ZoneId::Battlefield)
	{
		CreateServos(pController);
		return true;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText.Format(_T("Put %d +1/+1 counter%s on %s"), m_nCount, m_nCount > 1 ? _T("s") : _T(""), m_pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText.Format(_T("Create %d 1/1 Servo token%s"), m_nCount, m_nCount > 1 ? _T("s") : _T(""));
		entries.push_back(entry);
	}
	m_Selection.AddSelectionRequest(entries, 1, 1, m_pCard, pController);
	return true;
}

void CFabricateSupport::OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 0 && m_pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +m_nCount);
				pModifier.ApplyTo(m_pCard);
			}
			else
				CreateServos(pSelectionPlayer);
			return;
		}
}

void CFabricateSupport::CreateServos(CPlayer* pPlayer) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(m_pCard->GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, m_nCount);
	pModifier.ApplyTo(pPlayer);
}

//____________________________________________________________________________
//
// White creatures

// Pays nCount energy if the player has enough
static bool PayEnergy(CCard* pCard, CPlayer* pPlayer, int nCount)
{
	if (pPlayer->GetEnergyCounters() < nCount)
		return false;

	GetEnergy(pCard, pPlayer, -nCount);
	return true;
}

// "Whenever this creature attacks, you may pay {E}...{E}. If you do, <effect>": the effect is in the callback, which
// returns false (the ability does nothing else)
template <class T>
static void AddEnergyAttackTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// Same, with a target: another attacking creature
template <class T>
static void AddEnergyAttackTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(pCard)));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "When this creature enters, you may <effect> another target creature/permanent you control"
template <class T>
static void AddEnterTargetOwnTrigger(T* pCard, CardComparer* pComparer, bool (T::*callback)(CAbilityAction*) const)
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(pComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(pCard)));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

CAerialResponderCard::CAerialResponderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aerial Responder"), CardType::Creature, CREATURE_TYPE2(Dwarf, Soldier), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
{
	// Flying, vigilance, lifelink
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

CAetherstormRocCard::CAetherstormRocCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aetherstorm Roc"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	{
		// Whenever this creature or another creature you control enters, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherstormRocCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it and tap up to one
		// target creature defending player controls.
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
									 CWhenSelfAttackedBlocked::AttackEventCallback,
									 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherstormRocCard::BeforeAttack));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAetherstormRocCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

bool CAetherstormRocCard::BeforeAttack(CAbilityAction* pAction)
{
	if (!PayEnergy(this, pAction->GetController(), 2))
		return false;

	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
		pModifier.ApplyTo(this);
	}

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CAngelOfInventionCard::CAngelOfInventionCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Invention"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Fabricate(this, 2)
{
	// Flying, vigilance, lifelink
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// Other creatures you control get +1/+1. (as Veteran Armorsmith in M10)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new NegateCardComparer(new SpecificCardComparer(this)),
			Power(+1), Life(+1)));

	cpAbility->GetEnchantmentCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CAviaryMechanicCard::CAviaryMechanicCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aviary Mechanic"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, you may return another permanent you control to its owner's hand.
	// Note: the permanent is targeted
	AddEnterTargetOwnTrigger(this, new TrueCardComparer, &CAviaryMechanicCard::BeforeReturn);
}

bool CAviaryMechanicCard::BeforeReturn(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CConsulsShieldguardCard::CConsulsShieldguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Consul's Shieldguard"), CardType::Creature, CREATURE_TYPE2(Dwarf, Soldier), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CConsulsShieldguardCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}. If you do, another target attacking creature gains
	// indestructible until end of turn.
	AddEnergyAttackTargetTrigger(this, &CConsulsShieldguardCard::BeforeAttack);
}

bool CConsulsShieldguardCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CConsulsShieldguardCard::BeforeAttack(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 1))
		return false;

	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCard);
	return false;
}

CEddytrailHawkCard::CEddytrailHawkCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Eddytrail Hawk"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CEddytrailHawkCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}. If you do, another target attacking creature gains flying until
	// end of turn.
	AddEnergyAttackTargetTrigger(this, &CEddytrailHawkCard::BeforeAttack);
}

bool CEddytrailHawkCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CEddytrailHawkCard::BeforeAttack(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !dynamic_cast<CCreatureCard*>(pCard) ||
		!PayEnergy(this, pAction->GetController(), 1))
		return false;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::Flying);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo((CCreatureCard*)pCard);
	return false;
}

CGlintSleeveArtisanCard::CGlintSleeveArtisanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glint-Sleeve Artisan"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_Fabricate(this, 1)
{
	// Fabricate 1
}

CHeraldOfTheFairCard::CHeraldOfTheFairCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Herald of the Fair"), CardType::Creature, CREATURE_TYPE(Human), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, target creature you control gets +1/+1 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CMasterTrinketeerCard::CMasterTrinketeerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Master Trinketeer"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	{
		// Servos and Thopters you control get +1/+1.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE2(Servo, Thopter), false),
				Power(+1), Life(+1)));

		cpAbility->GetEnchantmentCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{W}: Create a 1/1 colorless Servo artifact creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("3") WHITE_MANA_TEXT,
				SERVO_TOKEN_NAME, SERVO_TOKEN_ID,
				1));
		AddAbility(cpAbility.GetPointer());
	}
}

CNinthBridgePatrolCard::CNinthBridgePatrolCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ninth Bridge Patrol"), CardType::Creature, CREATURE_TYPE2(Dwarf, Soldier), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1))
{
	// Whenever another creature you control leaves the battlefield, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::_AllZones));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	AddAbility(cpAbility.GetPointer());
}

CPropellerPioneerCard::CPropellerPioneerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Propeller Pioneer"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Fabricate(this, 1)
{
	// Flying, Fabricate 1
}

CSkyswirlHarrierCard::CSkyswirlHarrierCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skyswirl Harrier"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
}

CTasseledDromedaryCard::CTasseledDromedaryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tasseled Dromedary"), CardType::Creature, CREATURE_TYPE(Camel), nID,
		WHITE_MANA_TEXT, Power(0), Life(4))
{
}

CThrivingIbexCard::CThrivingIbexCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thriving Ibex"), CardType::Creature, CREATURE_TYPE(Goat), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(4))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CThrivingIbexCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it.
	AddEnergyAttackTrigger(this, &CThrivingIbexCard::BeforeAttack);
}

bool CThrivingIbexCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CThrivingIbexCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
	pModifier.ApplyTo(this);
	return false;
}

CToolcraftExemplarCard::CToolcraftExemplarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Toolcraft Exemplar"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		WHITE_MANA_TEXT, Power(1), Life(1))
{
	// At the beginning of combat on your turn, if you control an artifact, this creature gets +2/+1 until end of
	// turn. If you control three or more artifacts, it also gains first strike until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CToolcraftExemplarCard::BeforeCombat));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CToolcraftExemplarCard::BeforeCombat(CAbilityAction* pAction)
{
	int nArtifacts = CountArtifacts(GetController());
	if (nArtifacts == 0 || GetZoneId() != ZoneId::Battlefield)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+2));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);

	if (nArtifacts >= 3)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::FirstStrike);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

CVisionaryAugmenterCard::CVisionaryAugmenterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Visionary Augmenter"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(1))
	, m_Fabricate(this, 2)
{
	// Fabricate 2
}

CWispweaverAngelCard::CWispweaverAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Wispweaver Angel"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you may exile another target creature you control, then return that card to the
	// battlefield under its owner's control.
	AddEnterTargetOwnTrigger(this, new AnyCreatureComparer, &CWispweaverAngelCard::BeforeFlicker);
}

bool CWispweaverAngelCard::BeforeFlicker(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CPlayer* pOwner = pCard->GetOwner();
		CMoveCardModifier pExileModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pExileModifier.ApplyTo(pCard);

		if (pCard->GetZoneId() == ZoneId::Exile)
		{
			CMoveCardModifier pReturnModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pOwner);
			pReturnModifier.ApplyTo(pCard);
		}
	}
	return false;
}

CFairgroundsWardenCard::CFairgroundsWardenCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fairgrounds Warden"), CardType::Creature, CREATURE_TYPE2(Dwarf, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(1), Life(3))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CFairgroundsWardenCard::OnZoneChanged))
{
	// When this creature enters, exile target creature an opponent controls until this creature leaves the
	// battlefield. (as Banisher Priest in M14)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	{
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFairgroundsWardenCard::SetTriggerContext1));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CFairgroundsWardenCard::BeforeResolution));
		
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility < CTriggeredAbility<>, CWhenSelfInplay, 
										 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Exile, ZoneId::Battlefield));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFairgroundsWardenCard::SetTriggerContext2));

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this, ZoneId::Exile, ZoneId::_AllZones, FALSE, TRUE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFairgroundsWardenCard::SetTriggerContextAux));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFairgroundsWardenCard::SetTriggerContextAux(CTriggeredAbility<>::TriggerContextType& triggerContext, 
										CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pExiled.HasCard(pCard)) return false;

	pExiled.RemoveCard(pCard);
	return false;
}

bool CFairgroundsWardenCard::SetTriggerContext1(CTriggeredAbility<>::TriggerContextType& triggerContext, 
										 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType) const
{
	CCountedCardContainer pSubjects;
	CCountedCardContainer pCreated;

	if (IsInplay())
		pSubjects.AddCard((CCard*)this, CardPlacement::Top);

	CContainerEffectModifier pModifier = CContainerEffectModifier(GetGame(), _T("Generic Container - Battlefield"), 61128, &pSubjects, &pCreated);
	pModifier.ApplyTo(GetController());

	triggerContext.nValue1 = (DWORD)pCreated.GetAt(0);

	return true;
}

bool CFairgroundsWardenCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();

	CCard* pContainer = (CCard*)pAction->GetTriggerContext().nValue1;
	
	if (pContainer->GetZoneId() == ZoneId::_Effects)
	{
		CMoveCardModifier pModifier1 = CMoveCardModifier(ZoneId::_Effects, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pModifier1.ApplyTo(pContainer);

		CMoveCardModifier pModifier2 = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pModifier2.ApplyTo(pTarget);

		if (pTarget->GetZoneId() == ZoneId::Exile)
			pExiled.AddCard(pTarget, CardPlacement::Top);
	}
	return true;
}

bool CFairgroundsWardenCard::SetTriggerContext2(CTriggeredAbility<>::TriggerContextType& triggerContext, 
										CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	while (pExiled.GetSize() > 0)
	{
		CCard* pCard = pExiled.GetAt(0);
		pExiled.RemoveCard(pCard);
		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Battlefield), GetController(), MoveType::Others);
	}

	return false;
}

void CFairgroundsWardenCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone) return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && moveType != MoveType::Phasing)
	{
		pExiled.RemoveAll();
	}
}

//____________________________________________________________________________
//
// Green creatures

static void AddCounters(CCard* pCard, int nCount)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +nCount);
	pModifier.ApplyTo(pCard);
}

CArborbackStomperCard::CArborbackStomperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Arborback Stomper"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(4))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, you gain 5 life.
	AddEnterTrigger(this, &CArborbackStomperCard::BeforeLife);
}

bool CArborbackStomperCard::BeforeLife(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 5);
	return true;
}

CArchitectOfTheUntamedCard::CArchitectOfTheUntamedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Architect of the Untamed"), CardType::Creature, CREATURE_TYPE3(Elf, Artificer, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	{
		// Landfall - Whenever a land you control enters, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CArchitectOfTheUntamedCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay eight {E}: Create a 6/6 colorless Beast artifact creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				_T("Beast (Q)"), 55092,
				1));

		cpAbility->GetCost().AddEnergyCost(this, 8);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CArchitectOfTheUntamedCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

CArmorcraftJudgeCard::CArmorcraftJudgeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Armorcraft Judge"), CardType::Creature, CREATURE_TYPE2(Elf, Artificer), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, draw a card for each creature you control with a +1/+1 counter on it.
	AddEnterTrigger(this, &CArmorcraftJudgeCard::BeforeDraw);
}

bool CArmorcraftJudgeCard::BeforeDraw(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	int nCount = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0)
			++nCount;
	}

	if (nCount > 0)
		DrawCards(GetGame(), pController, nCount);
	return true;
}

CBristlingHydraCard::CBristlingHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bristling Hydra"), CardType::Creature, CREATURE_TYPE(Hydra), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(3))
{
	// When this creature enters, you get {E}{E}{E}.
	AddEnterTrigger(this, &CBristlingHydraCard::BeforeEnergy);

	// Pay {E}{E}{E}: Put a +1/+1 counter on this creature. It gains hexproof until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 3);
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. It gains hexproof until end of turn."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBristlingHydraCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CBristlingHydraCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

bool CBristlingHydraCard::BeforeCounter(CAbilityAction* pAction) const
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	AddCounters((CCard*)this, 1);

	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Hexproof);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo((CCard*)this);
	return true;
}

CCowlProwlerCard::CCowlProwlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cowl Prowler"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
}

CCultivatorOfBladesCard::CCultivatorOfBladesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cultivator of Blades"), CardType::Creature, CREATURE_TYPE2(Elf, Artificer), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(1), Life(1))
	, m_Fabricate(this, 2)
{
	// Whenever this creature attacks, you may have other attacking creatures get +X/+X until end of turn, where X is
	// this creature's power.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCultivatorOfBladesCard::BeforeAttack));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CCultivatorOfBladesCard::BeforeAttack(CAbilityAction* pAction)
{
	int nX = GET_INTEGER(GetPower());
	if (nX <= 0)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+nX));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+nX), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	AttackingCreatureComparer attacking;

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
		if (!pCreature || pCreature == this || !attacking(pCreature))
			continue;

		pPowerModifier.ApplyTo(pCreature);
		pLifeModifier.ApplyTo(pCreature);
	}
	return true;
}

CElegantEdgecraftersCard::CElegantEdgecraftersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elegant Edgecrafters"), CardType::Creature, CREATURE_TYPE2(Elf, Artificer), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(4))
	, m_CanBlockFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
	, m_Fabricate(this, 2)
{
	// This creature can't be blocked by creatures with power 2 or less.
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_CanBlockFilter);

	// Fabricate 2
}

CGhirapurGuideCard::CGhirapurGuideCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ghirapur Guide"), CardType::Creature, CREATURE_TYPE2(Elf, Scout), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_CanBlockFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// {2}{G}: Target creature you control can't be blocked by creatures with power 2 or less this turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGhirapurGuideCard::BeforeEvasion));
	AddAbility(cpAbility.GetPointer());
}

bool CGhirapurGuideCard::BeforeEvasion(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
		pCreature->GetCreatureKeyword()->AddUnblockable(TRUE, &m_CanBlockFilter);
	return true;
}

CHighspireArtisanCard::CHighspireArtisanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Highspire Artisan"), CardType::Creature, CREATURE_TYPE2(Elf, Artificer), nID,
		_T("2") GREEN_MANA_TEXT, Power(0), Life(3))
	, m_Fabricate(this, 1)
{
	// Reach, Fabricate 1
	GetCreatureKeyword()->AddReach(FALSE);
}

CKujarSeedsculptorCard::CKujarSeedsculptorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kujar Seedsculptor"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, put a +1/+1 counter on target creature you control.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKujarSeedsculptorCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CKujarSeedsculptorCard::BeforeCounter(CAbilityAction* pAction) const
{
	AddCounters(pAction->GetAssociatedCard(), 1);
	return false;
}

CLongtuskCubCard::CLongtuskCubCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Longtusk Cub"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// Whenever this creature deals combat damage to a player, you get {E}{E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLongtuskCubCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay {E}{E}: Put a +1/+1 counter on this creature.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddEnergyCost(this, 2);
		cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLongtuskCubCard::BeforeCounter));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLongtuskCubCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CLongtuskCubCard::BeforeCounter(CAbilityAction* pAction) const
{
	AddCounters((CCard*)this, 1);
	return true;
}

COviyaPashiriSageLifecrafterCard::COviyaPashiriSageLifecrafterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oviya Pashiri, Sage Lifecrafter"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Artificer), nID,
		GREEN_MANA_TEXT, Power(1), Life(2))
{
	{
		// {2}{G}, {T}: Create a 1/1 colorless Servo artifact creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2") GREEN_MANA_TEXT,
				SERVO_TOKEN_NAME, SERVO_TOKEN_ID,
				1));

		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{G}, {T}: Create an X/X colorless Construct artifact creature token, where X is the number of creatures
		// you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4") GREEN_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Create an X/X colorless Construct artifact creature token, where X is the number of creatures you control."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COviyaPashiriSageLifecrafterCard::BeforeConstruct));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool COviyaPashiriSageLifecrafterCard::BeforeConstruct(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	int nX = CCardFilter::GetFilter(_T("creatures"))->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());

	// A 0/0 Construct whose power and toughness become X (as Metallurgic Summonings)
	CCountedCardContainer tokens;
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Construct (B)"), 55091, 1,
		FALSE, ZoneId::Battlefield, &tokens);
	pModifier.ApplyTo(pController);

	CPowerModifier powerModifier;
	powerModifier.SetPowerDelta(Power(nX));
	powerModifier.SetToBase(TRUE);
	powerModifier.SetReplacement(TRUE);
	powerModifier.SetOneTurnOnly(FALSE);

	CLifeModifier lifeModifier;
	lifeModifier.SetLifeDelta(Life(nX));
	lifeModifier.SetToBase(TRUE);
	lifeModifier.SetReplacement(TRUE);
	lifeModifier.SetOneTurnOnly(FALSE);

	for (int i = 0; i < tokens.GetSize(); ++i)
	{
		CCreatureCard* pToken = dynamic_cast<CCreatureCard*>(tokens.GetAt(i));
		if (!pToken)
			continue;

		powerModifier.ApplyTo(pToken);
		lifeModifier.ApplyTo(pToken);
	}
	return true;
}

CPeemaOutriderCard::CPeemaOutriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Peema Outrider"), CardType::Creature, CREATURE_TYPE2(Elf, Artificer), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
	, m_Fabricate(this, 1)
{
	// Trample, Fabricate 1
	GetCreatureKeyword()->AddTrample(FALSE);
}

CRiparianTigerCard::CRiparianTigerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Riparian Tiger"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CRiparianTigerCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, it gets +2/+2 until end of turn.
	AddEnergyAttackTrigger(this, &CRiparianTigerCard::BeforeAttack);
}

bool CRiparianTigerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CRiparianTigerCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+2));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);
	return false;
}

CSageOfShailasClaimCard::CSageOfShailasClaimCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sage of Shaila's Claim"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters, you get {E}{E}{E}.
	AddEnterTrigger(this, &CSageOfShailasClaimCard::BeforeEnergy);
}

bool CSageOfShailasClaimCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

CServantOfTheConduitCard::CServantOfTheConduitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Servant of the Conduit"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CServantOfTheConduitCard::BeforeEnergy);

	// {T}, Pay {E}: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 1);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CServantOfTheConduitCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CTerrainElementalCard::CTerrainElementalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Terrain Elemental"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") GREEN_MANA_TEXT, Power(3), Life(2))
{
}

CThrivingRhinoCard::CThrivingRhinoCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thriving Rhino"), CardType::Creature, CREATURE_TYPE(Rhino), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CThrivingRhinoCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it.
	AddEnergyAttackTrigger(this, &CThrivingRhinoCard::BeforeAttack);
}

bool CThrivingRhinoCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CThrivingRhinoCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	AddCounters(this, 1);
	return false;
}

CVerdurousGearhulkCard::CVerdurousGearhulkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Verdurous Gearhulk"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_CreatureSelection(pGame, CSelectionSupport::SelectionCallback(this, &CVerdurousGearhulkCard::OnCreatureSelected))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, distribute four +1/+1 counters among any number of target creatures you control.
	// Note: the creatures are chosen on resolution, one counter at a time (not targeted)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVerdurousGearhulkCard::BeforeCounters));
	AddAbility(cpAbility.GetPointer());
}

bool CVerdurousGearhulkCard::BeforeCounters(CAbilityAction* pAction)
{
	RequestCounter(pAction->GetController(), 4);
	return true;
}

void CVerdurousGearhulkCard::RequestCounter(CPlayer* pPlayer, int nRemaining)
{
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("+1/+1 counter on %s (%d left)"), pCard->GetCardName(TRUE), nRemaining);
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_CreatureSelection.AddSelectionRequest(entries, 1, 1, this, pPlayer, (DWORD)nRemaining);
}

void CVerdurousGearhulkCard::OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	int nRemaining = (int)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			AddCounters((CCard*)it->dwContext, 1);
			break;
		}

	if (nRemaining > 1)
		RequestCounter(pSelectionPlayer, nRemaining - 1);
}

CWildWandererCard::CWildWandererCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wild Wanderer"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you may search your library for a basic land card, put it onto the battlefield
	// tapped, then shuffle. (as Yavimaya Granger in Urza's Legacy)
	typedef
		TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("basic lands")));
	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpAbility->SetToZone(ZoneId::Battlefield);
	cpAbility->SetToOwnersZone(FALSE);
	cpAbility->SetTapped(TRUE);
	AddAbility(cpAbility.GetPointer());
}

CWilyBandarCard::CWilyBandarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wily Bandar"), CardType::Creature, CREATURE_TYPE2(Cat, Monkey), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// {2}{G}: This creature gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") GREEN_MANA_TEXT));

	cpAbility->SetAbilityText(_T("This creature gains indestructible until end of turn."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWilyBandarCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CWilyBandarCard::BeforeIndestructible(CAbilityAction* pAction) const
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo((CCard*)this);
	return true;
}

//____________________________________________________________________________
//
// Red creatures

// "Whenever an artifact you control enters, ..." trigger setup
template <class TriggeredAbility>
static void SetArtifactEntersTrigger(TriggeredAbility* pAbility)
{
	pAbility->GetTrigger().SetToControllerOnly(TRUE);
	pAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
}

CAethertorchRenegadeCard::CAethertorchRenegadeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aethertorch Renegade"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("2") RED_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, you get {E}{E}{E}{E}.
	AddEnterTrigger(this, &CAethertorchRenegadeCard::BeforeEnergy);

	{
		// {T}, Pay {E}{E}: This creature deals 1 damage to target creature.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE,
				Life(-1), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 2);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Pay eight {E}: This creature deals 6 damage to target player or planeswalker.
		// Note: players only
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE,
				Life(-6), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 8);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAethertorchRenegadeCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 4);
	return true;
}

CBrazenScourgeCard::CBrazenScourgeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brazen Scourge"), CardType::Creature, CREATURE_TYPE(Gremlin), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	GetCreatureKeyword()->AddHaste(FALSE);
}

CCombustibleGearhulkCard::CCombustibleGearhulkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Combustible Gearhulk"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(6))
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CCombustibleGearhulkCard::OnChoiceSelected))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature enters, target opponent may have you draw three cards. If the player doesn't, you mill three
	// cards, then this creature deals damage to that player equal to the total mana value of those cards.
	// Note: the opponent is chosen automatically (the first one)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCombustibleGearhulkCard::BeforeChoice));
	AddAbility(cpAbility.GetPointer());
}

bool CCombustibleGearhulkCard::BeforeChoice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = NULL;
	for (int ip = 0; ip < GetGame()->GetPlayerCount() && !pOpponent; ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			pOpponent = GetGame()->GetPlayer(ip);

	if (!pOpponent)
		return true;

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText.Format(_T("%s draws three cards"), pController->GetPlayerName());
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Mill three cards and take damage equal to their total mana value");
		entries.push_back(entry);
	}
	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent, (DWORD)pController);
	return true;
}

void CCombustibleGearhulkCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 0)
			{
				DrawCards(GetGame(), pController, 3);
				return;
			}

			CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
			int nTotal = 0;
			for (int i = 0; i < 3 && i < pLibrary->GetSize(); ++i)
				nTotal += (int)pLibrary->GetAt(pLibrary->GetSize() - 1 - i)->GetConvertedManaCost();

			Mill(pController, 3);

			if (nTotal > 0)
			{
				CLifeModifier pModifier = CLifeModifier(Life(-nTotal), this, PreventableType::Preventable,
					DamageType::AbilityDamage | DamageType::NonCombatDamage);
				pModifier.ApplyTo(pSelectionPlayer);
			}
			return;
		}
}

CInventorsApprenticeCard::CInventorsApprenticeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Inventor's Apprentice"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		RED_MANA_TEXT, Power(1), Life(2))
{
	// This creature gets +1/+1 as long as you control an artifact. (as Carapace Forger in Scars of Mirrodin)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+1)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CLathnuHellionCard::CLathnuHellionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lathnu Hellion"), CardType::Creature, CREATURE_TYPE(Hellion), nID,
		_T("2") RED_MANA_TEXT, Power(4), Life(4))
	, m_PaySelection(pGame, CSelectionSupport::SelectionCallback(this, &CLathnuHellionCard::OnPaySelected))
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CLathnuHellionCard::BeforeEnergy);

	// At the beginning of your end step, sacrifice this creature unless you pay {E}{E}.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLathnuHellionCard::BeforeEndStep));
	AddAbility(cpAbility.GetPointer());
}

bool CLathnuHellionCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CLathnuHellionCard::BeforeEndStep(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pAction->GetController();
	if (pController->GetEnergyCounters() < 2)
	{
		Sacrifice();
		return true;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Pay 2 energy");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.strText.Format(_T("Sacrifice %s"), GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_PaySelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CLathnuHellionCard::OnPaySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 1 && PayEnergy(this, pSelectionPlayer, 2))
				return;

			Sacrifice();
			return;
		}
}

void CLathnuHellionCard::Sacrifice()
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, GetController());
	pModifier.ApplyTo(this);
}

CMaulfistDoorbusterCard::CMaulfistDoorbusterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Maulfist Doorbuster"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CMaulfistDoorbusterCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}. If you do, target creature can't block this turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMaulfistDoorbusterCard::BeforeAttack));
	AddAbility(cpAbility.GetPointer());
}

bool CMaulfistDoorbusterCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CMaulfistDoorbusterCard::BeforeAttack(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 1))
		return false;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);
	return false;
}

CPiaNalaarCard::CPiaNalaarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pia Nalaar"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// When Pia Nalaar enters, create a 1/1 colorless Thopter artifact creature token with flying.
	AddEnterTrigger(this, &CPiaNalaarCard::BeforeThopter);

	{
		// {1}{R}: Target artifact creature gets +1/+0 until end of turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T("1") RED_MANA_TEXT,
				Power(+1), Life(+0),
				CreatureKeyword::Null, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}, Sacrifice an artifact: Target creature can't block this turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T("1"),
				Power(+0), Life(+0),
				CreatureKeyword::CantBlock, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPiaNalaarCard::BeforeThopter(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Thopter (D)"), 55053, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CQuicksmithGeniusCard::CQuicksmithGeniusCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Quicksmith Genius"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// Whenever an artifact you control enters, you may discard a card. If you do, draw a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	SetArtifactEntersTrigger(cpAbility.GetPointer());
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetDiscardResolutionCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

CRecklessFireweaverCard::CRecklessFireweaverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reckless Fireweaver"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// Whenever an artifact you control enters, this creature deals 1 damage to each opponent.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	SetArtifactEntersTrigger(cpAbility.GetPointer());
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRecklessFireweaverCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CRecklessFireweaverCard::BeforeDamage(CAbilityAction* pAction) const
{
	DamageEachOpponent((CCard*)this, pAction->GetController(), 1);
	return true;
}

CRenegadeFirebrandCard::CRenegadeFirebrandCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Renegade Firebrand"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// As long as you control a Chandra planeswalker, this creature gets +1/+0 and has first strike.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+0), CreatureKeyword::FirstStrike));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Chandra));
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CRuinousGremlinCard::CRuinousGremlinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ruinous Gremlin"), CardType::Creature, CREATURE_TYPE(Gremlin), nID,
		RED_MANA_TEXT, Power(1), Life(1))
{
	// {2}{R}, Sacrifice this creature: Destroy target artifact.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2") RED_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CSalivatingGremlinsCard::CSalivatingGremlinsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Salivating Gremlins"), CardType::Creature, CREATURE_TYPE(Gremlin), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// Whenever an artifact you control enters, this creature gets +2/+0 and gains trample until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	SetArtifactEntersTrigger(cpAbility.GetPointer());
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+2));
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Trample);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CSkyshipStalkerCard::CSkyshipStalkerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Skyship Stalker"), CardType::Creature, CREATURE_TYPE2(Cat, Dragon), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// {R}: This creature gets +1/+0 until end of turn.
	// {R}: This creature gains first strike until end of turn.
	// {R}: This creature gains haste until end of turn.
	CreatureKeyword keywords[] = { CreatureKeyword::Null, CreatureKeyword::FirstStrike, CreatureKeyword::Haste };
	for (int i = 0; i < _countof(keywords); ++i)
	{
		counted_ptr<CPumpAbility> cpAbility(
			::CreateObject<CPumpAbility>(this,
				RED_MANA_TEXT,
				Power(i == 0 ? +1 : +0), Life(+0), keywords[i]));
		AddAbility(cpAbility.GetPointer());
	}
}

CSpiresideInfiltratorCard::CSpiresideInfiltratorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spireside Infiltrator"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(2))
{
	// Whenever this creature becomes tapped, it deals 1 damage to each opponent.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfOrientationChanged,
						   CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetTapEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpiresideInfiltratorCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CSpiresideInfiltratorCard::BeforeDamage(CAbilityAction* pAction) const
{
	DamageEachOpponent((CCard*)this, pAction->GetController(), 1);
	return true;
}

CSpontaneousArtistCard::CSpontaneousArtistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spontaneous Artist"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you get {E}.
	AddEnterTrigger(this, &CSpontaneousArtistCard::BeforeEnergy);

	// Pay {E}: Target creature gains haste until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T(""),
			Power(+0), Life(+0),
			CreatureKeyword::Haste, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetCost().AddEnergyCost(this, 1);
	AddAbility(cpAbility.GetPointer());
}

bool CSpontaneousArtistCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

CTerrorOfTheFairgroundsCard::CTerrorOfTheFairgroundsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Terror of the Fairgrounds"), CardType::Creature, CREATURE_TYPE(Gremlin), nID,
		_T("3") RED_MANA_TEXT, Power(5), Life(2))
{
}

CThrivingGrubsCard::CThrivingGrubsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thriving Grubs"), CardType::Creature, CREATURE_TYPE(Gremlin), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CThrivingGrubsCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it.
	AddEnergyAttackTrigger(this, &CThrivingGrubsCard::BeforeAttack);
}

bool CThrivingGrubsCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CThrivingGrubsCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	AddCounters(this, 1);
	return false;
}

CWaywardGiantCard::CWaywardGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wayward Giant"), CardType::Creature, CREATURE_TYPE(Giant), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(5))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace
}

CGuardianOfTheGreatConduitCard::CGuardianOfTheGreatConduitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Guardian of the Great Conduit"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(4))
{
	GetCreatureKeyword()->AddReach(FALSE);

	// As long as you control a Nissa planeswalker, this creature gets +2/+0 and has vigilance.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+2), Life(+0), CreatureKeyword::Vigilance));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Nissa));
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Black creatures

CAetherbornMarauderCard::CAetherbornMarauderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aetherborn Marauder"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Rogue), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_PermanentSelection(pGame, CSelectionSupport::SelectionCallback(this, &CAetherbornMarauderCard::OnPermanentsSelected))
{
	// Flying, lifelink
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, move any number of +1/+1 counters from other permanents you control onto this
	// creature.
	// Note: all the +1/+1 counters of each chosen permanent are moved
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherbornMarauderCard::BeforeCounters));
	AddAbility(cpAbility.GetPointer());
}

bool CAetherbornMarauderCard::BeforeCounters(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard == this)
			continue;

		int nCounters = pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
		if (nCounters <= 0)
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Move %d +1/+1 counter%s from %s"), nCounters, nCounters > 1 ? _T("s") : _T(""), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_PermanentSelection.AddSelectionRequest(entries, 0, (int)entries.size(), this, pController);
	return true;
}

void CAetherbornMarauderCard::OnPermanentsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
	{
		if (!it->bSelected)
			continue;

		CCard* pCard = (CCard*)it->dwContext;
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;

		int nCounters = pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
		if (nCounters <= 0)
			continue;

		CCardCounterModifier pRemoveModifier = CCardCounterModifier(_T("+1/+1"), -nCounters);
		pRemoveModifier.ApplyTo(pCard);
		AddCounters(this, nCounters);
	}
}

CAmbitiousAetherbornCard::CAmbitiousAetherbornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ambitious Aetherborn"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Artificer), nID,
		_T("4") BLACK_MANA_TEXT, Power(4), Life(3))
	, m_Fabricate(this, 1)
{
	// Fabricate 1
}

CDemonOfDarkSchemesCard::CDemonOfDarkSchemesCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Demon of Dark Schemes"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(5))
{
	// When this creature enters, all other creatures get -2/-2 until end of turn.
	AddEnterTrigger(this, &CDemonOfDarkSchemesCard::BeforeWeaken);

	{
		// Whenever another creature dies, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDemonOfDarkSchemesCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{B}, Pay {E}{E}{E}{E}: Put target creature card from a graveyard onto the battlefield tapped under your
		// control.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("2") BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->GetCost().AddEnergyCost(this, 4);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDemonOfDarkSchemesCard::BeforeWeaken(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(-2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard != this && pCard->GetCardType().IsCreature() && dynamic_cast<CCreatureCard*>(pCard))
				creatures.AddCard(pCard, CardPlacement::Top);
		}
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
	}
	return true;
}

bool CDemonOfDarkSchemesCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

CDhundOperativeCard::CDhundOperativeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dhund Operative"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// As long as you control an artifact, this creature gets +1/+0 and has deathtouch.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+0)));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CDukharaScavengerCard::CDukharaScavengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dukhara Scavenger"), CardType::Creature, CREATURE_TYPE(Crocodile), nID,
		_T("5") BLACK_MANA_TEXT, Power(4), Life(6))
{
	// When this creature enters, you may put target artifact or creature card from your graveyard on top of your
	// library.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::Creature, false));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDukharaScavengerCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CDukharaScavengerCard::BeforeReturn(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Library), pAction->GetController(), MoveType::Others, CardPlacement::Top);
	return false;
}

CEmbraalBruiserCard::CEmbraalBruiserCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Embraal Bruiser"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") BLACK_MANA_TEXT, Power(3), Life(1))
{
	// This creature enters tapped.
	SetIntoPlayTapped();

	// This creature has menace as long as you control an artifact.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::CantBeBlockedBy1));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CFoundryScreecherCard::CFoundryScreecherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Foundry Screecher"), CardType::Creature, CREATURE_TYPE(Bat), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// This creature gets +1/+0 as long as you control an artifact.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+1), Life(+0)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CFretworkColonyCard::CFretworkColonyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fretwork Colony"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// This creature can't block.
	GetCreatureKeyword()->AddCantBlock(FALSE);

	// At the beginning of your upkeep, put a +1/+1 counter on this creature and you lose 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFretworkColonyCard::BeforeUpkeep));
	AddAbility(cpAbility.GetPointer());
}

bool CFretworkColonyCard::BeforeUpkeep(CAbilityAction* pAction) const
{
	AddCounters((CCard*)this, 1);

	CLifeModifier pModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CLawlessBrokerCard::CLawlessBrokerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lawless Broker"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Rogue), nID,
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
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLawlessBrokerCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CLawlessBrokerCard::BeforeCounter(CAbilityAction* pAction) const
{
	AddCounters(pAction->GetAssociatedCard(), 1);
	return false;
}

CMarionetteMasterCard::CMarionetteMasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Marionette Master"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(3))
	, m_Fabricate(this, 3)
{
	// Whenever an artifact you control is put into a graveyard from the battlefield, target opponent loses life equal
	// to this creature's power.
	// Note: each opponent loses the life (the target opponent in a two-player game)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMarionetteMasterCard::BeforeLifeLoss));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	AddAbility(cpAbility.GetPointer());
}

bool CMarionetteMasterCard::BeforeLifeLoss(CAbilityAction* pAction) const
{
	int nPower = GET_INTEGER(GetPower());
	if (nPower <= 0)
		return true;

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-nPower), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

CMaulfistSquadCard::CMaulfistSquadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Maulfist Squad"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(1))
	, m_Fabricate(this, 1)
{
	// Menace, Fabricate 1
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CNightMarketLookoutCard::CNightMarketLookoutCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Night Market Lookout"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Whenever this creature becomes tapped, each opponent loses 1 life and you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfOrientationChanged,
						   CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetTapEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNightMarketLookoutCard::BeforeDrain));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CNightMarketLookoutCard::BeforeDrain(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}

	GainLife((CCard*)this, pController, 1);
	return true;
}

CNoxiousGearhulkCard::CNoxiousGearhulkCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Noxious Gearhulk"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(4))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace

	// When this creature enters, you may destroy another target creature. If a creature is destroyed this way, you
	// gain life equal to its toughness.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNoxiousGearhulkCard::BeforeDestroy));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CNoxiousGearhulkCard::BeforeDestroy(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return false;

	int nToughness = GET_INTEGER(pCreature->GetToughness());

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	pModifier.ApplyTo(pCreature);

	if (pCreature->GetZoneId() != ZoneId::Battlefield && nToughness > 0)
		GainLife((CCard*)this, pAction->GetController(), nToughness);
	return false;
}

COvalchaseDaredevilCard::COvalchaseDaredevilCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ovalchase Daredevil"), CardType::Creature, CREATURE_TYPE2(Human, Pilot), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// Whenever an artifact you control enters, you may return this card from your graveyard to your hand.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield, FALSE, TRUE, FALSE));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COvalchaseDaredevilCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COvalchaseDaredevilCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool COvalchaseDaredevilCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Graveyard;
}

bool COvalchaseDaredevilCard::BeforeReturn(CAbilityAction* pAction) const
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo((CCard*)this);
	}
	return true;
}

CPrakhataClubSecurityCard::CPrakhataClubSecurityCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prakhata Club Security"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Warrior), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(4))
{
}

CSyndicateTraffickerCard::CSyndicateTraffickerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Syndicate Trafficker"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(3), Life(1))
{
	// {1}, Sacrifice an artifact: Put a +1/+1 counter on this creature. It gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature. It gains indestructible until end of turn."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSyndicateTraffickerCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CSyndicateTraffickerCard::BeforeCounter(CAbilityAction* pAction) const
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	AddCounters((CCard*)this, 1);

	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo((CCard*)this);
	return true;
}

CThrivingRatsCard::CThrivingRatsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thriving Rats"), CardType::Creature, CREATURE_TYPE(Rat), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CThrivingRatsCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it.
	AddEnergyAttackTrigger(this, &CThrivingRatsCard::BeforeAttack);
}

bool CThrivingRatsCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CThrivingRatsCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	AddCounters(this, 1);
	return false;
}

CWeaponcraftEnthusiastCard::CWeaponcraftEnthusiastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weaponcraft Enthusiast"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Artificer), nID,
		_T("2") BLACK_MANA_TEXT, Power(0), Life(1))
	, m_Fabricate(this, 2)
{
	// Fabricate 2
}

//____________________________________________________________________________
//
// Blue creatures

CAethersquallAncientCard::CAethersquallAncientCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aethersquall Ancient"), CardType::Creature, CREATURE_TYPE(Leviathan), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(6), Life(6))
{
	{
		// At the beginning of your upkeep, you get {E}{E}{E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAethersquallAncientCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay eight {E}: Return all other creatures to their owners' hands. Activate only as a sorcery.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddEnergyCost(this, 8);
		cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
		cpAbility->SetAbilityText(_T("Return all other creatures to their owners' hands."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAethersquallAncientCard::BeforeBounce));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAethersquallAncientCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

bool CAethersquallAncientCard::BeforeBounce(CAbilityAction* pAction) const
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

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(creatures.GetAt(i));
	return true;
}

CAetherTheoristCard::CAetherTheoristCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aether Theorist"), CardType::Creature, CREATURE_TYPE2(Vedalken, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// When this creature enters, you get {E}{E}{E}.
	AddEnterTrigger(this, &CAetherTheoristCard::BeforeEnergy);

	// {T}, Pay {E}: Scry 1.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddEnergyCost(this, 1);
	cpAbility->SetAbilityText(_T("Scry 1."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherTheoristCard::BeforeScry));
	AddAbility(cpAbility.GetPointer());
}

bool CAetherTheoristCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

bool CAetherTheoristCard::BeforeScry(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 1);
	return true;
}

CCurioVendorCard::CCurioVendorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Curio Vendor"), CardType::Creature, CREATURE_TYPE(Vedalken), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
}

CExperimentalAviatorCard::CExperimentalAviatorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Experimental Aviator"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(0), Life(3))
{
	// When this creature enters, create two 1/1 colorless Thopter artifact creature tokens with flying.
	AddEnterTrigger(this, &CExperimentalAviatorCard::BeforeThopters);
}

bool CExperimentalAviatorCard::BeforeThopters(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Thopter (D)"), 55053, 2);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CGearseekerSerpentCard::CGearseekerSerpentCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gearseeker Serpent"), CardType::Creature, CREATURE_TYPE(Serpent), nID,
		_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(6))
	, m_CardFilter(_T("artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	{
		// Affinity for artifacts (as Frogmite in Mirrodin)
		counted_ptr<CTriggeredAffinityAbility> cpAbility(
			::CreateObject<CTriggeredAffinityAbility>(this,
				&m_CardFilter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {5}{U}: This creature can't be blocked this turn.
		counted_ptr<CPumpAbility> cpAbility(
			::CreateObject<CPumpAbility>(this,
				_T("5") BLUE_MANA_TEXT,
				Power(+0), Life(+0), CreatureKeyword::Unblockable));
		AddAbility(cpAbility.GetPointer());
	}
}

CGlintNestCraneCard::CGlintNestCraneCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Glint-Nest Crane"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// When this creature enters, look at the top four cards of your library. You may reveal an artifact card from
	// among them and put it into your hand. Put the rest on the bottom of your library in any order.
	AddEnterTrigger(this, &CGlintNestCraneCard::BeforeLook);
}

bool CGlintNestCraneCard::BeforeLook(CAbilityAction* pAction) const
{
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, 4,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // select an artifact card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		CCardFilter::GetFilter(_T("artifacts")),	// artifact cards
		ZoneId::Hand,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);

	// the rest on the bottom of the library
	pModifier.SetReorderInformation(
		true,
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Bottom);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CHightideHermitCard::CHightideHermitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hightide Hermit"), CardType::Creature, CREATURE_TYPE(Crab), nID,
		_T("4") BLUE_MANA_TEXT, Power(4), Life(4))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	// When this creature enters, you get {E}{E}{E}{E}.
	AddEnterTrigger(this, &CHightideHermitCard::BeforeEnergy);

	// Pay {E}{E}: This creature can attack this turn as though it didn't have defender.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 2);
	cpAbility->SetAbilityText(_T("This creature can attack this turn as though it didn't have defender."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHightideHermitCard::BeforeAttack));
	AddAbility(cpAbility.GetPointer());
}

bool CHightideHermitCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 4);
	return true;
}

bool CHightideHermitCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddDefenderMayAttack(TRUE);
	return true;
}

CJanjeetSentryCard::CJanjeetSentryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Janjeet Sentry"), CardType::Creature, CREATURE_TYPE2(Vedalken, Soldier), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CJanjeetSentryCard::BeforeEnergy);

	// {T}, Pay {E}{E}: You may tap or untap target artifact or creature.
	// Note: the target is tapped if it's untapped, and untapped if it's tapped
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			new CardTypeComparer(CardType::Artifact | CardType::Creature, false), FALSE));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddEnergyCost(this, 2);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJanjeetSentryCard::BeforeTap));
	AddAbility(cpAbility.GetPointer());
}

bool CJanjeetSentryCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CJanjeetSentryCard::BeforeTap(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(!pCard->GetOrientation()->IsTapped());
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CLongFinnedSkywhaleCard::CLongFinnedSkywhaleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Long-Finned Skywhale"), CardType::Creature, CREATURE_TYPE(Whale), nID,
		_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(3))
{
	// This creature can block only creatures with flying.
	GetCreatureKeyword()->AddCanOnlyBlockFlying(FALSE);
}

CMinisterOfInquiriesCard::CMinisterOfInquiriesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Minister of Inquiries"), CardType::Creature, CREATURE_TYPE2(Vedalken, Advisor), nID,
		BLUE_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CMinisterOfInquiriesCard::BeforeEnergy);

	// {T}, Pay {E}: Target player mills three cards.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddEnergyCost(this, 1);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMinisterOfInquiriesCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CMinisterOfInquiriesCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CMinisterOfInquiriesCard::BeforeMill(CAbilityAction* pAction) const
{
	if (pAction->GetAssociatedPlayer())
		Mill(pAction->GetAssociatedPlayer(), 3);
	return true;
}

CNimbleInnovatorCard::CNimbleInnovatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Nimble Innovator"), CardType::Creature, CREATURE_TYPE2(Vedalken, Artificer), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, draw a card.
	AddEnterTrigger(this, &CNimbleInnovatorCard::BeforeDraw);
}

bool CNimbleInnovatorCard::BeforeDraw(CAbilityAction* pAction) const
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CPadeemConsulOfInnovationCard::CPadeemConsulOfInnovationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Padeem, Consul of Innovation"), CardType::_LegendaryCreature, CREATURE_TYPE2(Vedalken, Artificer), nID,
		_T("3") BLUE_MANA_TEXT, Power(1), Life(4))
{
	{
		// Artifacts you control have hexproof. (as Leonin Abunas in Mirrodin)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CardTypeComparer(CardType::Artifact, false),
				Power(+0), Life(+0)));

		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of your upkeep, if you control the artifact with the greatest mana value or tied for the
		// greatest mana value, draw a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPadeemConsulOfInnovationCard::BeforeUpkeep));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPadeemConsulOfInnovationCard::BeforeUpkeep(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	int nMine = -1, nOthers = -1;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (!pCard->GetCardType().IsArtifact())
				continue;

			int nValue = (int)pCard->GetConvertedManaCost();
			int& nMax = (pPlayer == pController) ? nMine : nOthers;
			if (nValue > nMax)
				nMax = nValue;
		}
	}

	if (nMine >= 0 && nMine >= nOthers)
		DrawCards(GetGame(), pController, 1);
	return true;
}

CThrivingTurtleCard::CThrivingTurtleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thriving Turtle"), CardType::Creature, CREATURE_TYPE(Turtle), nID,
		BLUE_MANA_TEXT, Power(0), Life(3))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CThrivingTurtleCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it.
	AddEnergyAttackTrigger(this, &CThrivingTurtleCard::BeforeAttack);
}

bool CThrivingTurtleCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CThrivingTurtleCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	AddCounters(this, 1);
	return false;
}

CVedalkenBlademasterCard::CVedalkenBlademasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vedalken Blademaster"), CardType::Creature, CREATURE_TYPE2(Vedalken, Soldier), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
	// Prowess (as Khans of Tarkir)
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

CWeldfastWingsmithCard::CWeldfastWingsmithCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weldfast Wingsmith"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// Whenever an artifact you control enters, this creature gains flying until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	SetArtifactEntersTrigger(cpAbility.GetPointer());
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Flying);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Multicolored creatures

CCloudblazerCard::CCloudblazerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cloudblazer"), CardType::Creature, CREATURE_TYPE2(Human, Scout), nID,
		_T("3") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, you gain 2 life and draw two cards.
	AddEnterTrigger(this, &CCloudblazerCard::BeforeDraw);
}

bool CCloudblazerCard::BeforeDraw(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 2);
	DrawCards(GetGame(), pAction->GetController(), 2);
	return true;
}

CContrabandKingpinCard::CContrabandKingpinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Contraband Kingpin"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Rogue), nID,
		BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(1), Life(4))
{
	GetCardKeyword()->AddLifelink(FALSE);

	// Whenever an artifact you control enters, scry 1.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	SetArtifactEntersTrigger(cpAbility.GetPointer());
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CContrabandKingpinCard::BeforeScry));
	AddAbility(cpAbility.GetPointer());
}

bool CContrabandKingpinCard::BeforeScry(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 1);
	return true;
}

CEmpyrealVoyagerCard::CEmpyrealVoyagerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Empyreal Voyager"), CardType::Creature, CREATURE_TYPE2(Vedalken, Scout), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever this creature deals combat damage to a player, you get that many {E}.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEmpyrealVoyagerCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CEmpyrealVoyagerCard::BeforeEnergy));
	AddAbility(cpAbility.GetPointer());
}

bool CEmpyrealVoyagerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	int nDamage = -GET_INTEGER(damage.m_nLifeDelta);
	if (nDamage <= 0)
		return false;

	triggerContext.nValue1 = (DWORD)nDamage;
	return true;
}

bool CEmpyrealVoyagerCard::BeforeEnergy(TriggeredAbility::TriggeredActionType* pAction)
{
	int nEnergy = (int)pAction->GetTriggerContext().nValue1;
	if (nEnergy > 0)
		GetEnergy(this, pAction->GetController(), nEnergy);
	return true;
}

CKambalConsulOfAllocationCard::CKambalConsulOfAllocationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kambal, Consul of Allocation"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Advisor), nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Whenever an opponent casts a noncreature spell, that player loses 2 life and you gain 2 life.
	// Note: each opponent loses the life (the caster in a two-player game)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKambalConsulOfAllocationCard::BeforeDrain));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CKambalConsulOfAllocationCard::BeforeDrain(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}

	GainLife((CCard*)this, pController, 2);
	return true;
}

CRestorationGearsmithCard::CRestorationGearsmithCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Restoration Gearsmith"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, return target artifact or creature card from your graveyard to your hand.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::Creature, false));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRestorationGearsmithCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CRestorationGearsmithCard::BeforeReturn(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CVeteranMotoristCard::CVeteranMotoristCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Veteran Motorist"), CardType::Creature, CREATURE_TYPE2(Dwarf, Pilot), nID,
		RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(1))
{
	// When this creature enters, scry 2.
	AddEnterTrigger(this, &CVeteranMotoristCard::BeforeScry);

	// Note: "Whenever this creature crews a Vehicle, that Vehicle gets +1/+1 until end of turn." is not implemented.
}

bool CVeteranMotoristCard::BeforeScry(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 2);
	return true;
}

CVoltaicBrawlerCard::CVoltaicBrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Voltaic Brawler"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CVoltaicBrawlerCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}. If you do, it gets +1/+1 and gains trample until end of turn.
	AddEnergyAttackTrigger(this, &CVoltaicBrawlerCard::BeforeAttack);
}

bool CVoltaicBrawlerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CVoltaicBrawlerCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 1))
		return false;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(this);
	return false;
}

CWhirlerVirtuosoCard::CWhirlerVirtuosoCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Whirler Virtuoso"), CardType::Creature, CREATURE_TYPE2(Vedalken, Artificer), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, you get {E}{E}{E}.
	AddEnterTrigger(this, &CWhirlerVirtuosoCard::BeforeEnergy);

	// Pay {E}{E}{E}: Create a 1/1 colorless Thopter artifact creature token with flying.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T(""),
			_T("Thopter (D)"), 55053,
			1));

	cpAbility->GetCost().AddEnergyCost(this, 3);
	AddAbility(cpAbility.GetPointer());
}

bool CWhirlerVirtuosoCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

//____________________________________________________________________________
//
// Colorless creatures

// "<cost>: This creature gains <card keyword> until end of turn." (deathtouch, lifelink...)
template <class T>
static void AddCardKeywordAbility(T* pCard, LPCTSTR strCost, LPCTSTR strText, bool (T::*callback)(CAbilityAction*) const)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			strCost));

	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

static void AddCardKeywordUntilEndOfTurn(CCard* pCard, CardKeyword keyword)
{
	if (pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(keyword);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCard);
}

CAccomplishedAutomatonCard::CAccomplishedAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Accomplished Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("7"), Power(5), Life(7))
	, m_Fabricate(this, 1)
{
	// Fabricate 1
}

CBastionMastodonCard::CBastionMastodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bastion Mastodon"), CardType::_ArtifactCreature, CREATURE_TYPE(Elephant), nID,
		_T("5"), Power(4), Life(5))
{
	// {W}: This creature gains vigilance until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this,
			WHITE_MANA_TEXT,
			Power(+0), Life(+0), CreatureKeyword::Vigilance));
	AddAbility(cpAbility.GetPointer());
}

CChiefOfTheFoundryCard::CChiefOfTheFoundryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Chief of the Foundry"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(2), Life(3))
{
	// Other artifact creatures you control get +1/+1. (as Veteran Armorsmith in M10)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new NegateCardComparer(new SpecificCardComparer(this)),
			Power(+1), Life(+1)));

	cpAbility->GetEnchantmentCardFilter().AddComparer(new CardTypeComparer(CardType::_ArtifactCreature, true));
	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CConsulateSkygateCard::CConsulateSkygateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Consulate Skygate"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("2"), Power(0), Life(4))
{
	GetCreatureKeyword()->AddDefender(FALSE);
	GetCreatureKeyword()->AddReach(FALSE);
}

CDukharaPeafowlCard::CDukharaPeafowlCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dukhara Peafowl"), CardType::_ArtifactCreature, CREATURE_TYPE(Bird), nID,
		_T("4"), Power(2), Life(4))
{
	// {U}: This creature gains flying until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this,
			BLUE_MANA_TEXT,
			Power(+0), Life(+0), CreatureKeyword::Flying));
	AddAbility(cpAbility.GetPointer());
}

CEagerConstructCard::CEagerConstructCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eager Construct"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("2"), Power(2), Life(2))
{
	// When this creature enters, each player may scry 1.
	AddEnterTrigger(this, &CEagerConstructCard::BeforeScry);
}

bool CEagerConstructCard::BeforeScry(CAbilityAction* pAction) const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		ApplyScry(GetGame(), GetGame()->GetPlayer(ip), (CCard*)this, 1);
	return true;
}

CElectrostaticPummelerCard::CElectrostaticPummelerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Electrostatic Pummeler"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(1), Life(1))
{
	// When this creature enters, you get {E}{E}{E}.
	AddEnterTrigger(this, &CElectrostaticPummelerCard::BeforeEnergy);

	// Pay {E}{E}{E}: This creature gets +X/+X until end of turn, where X is its power.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 3);
	cpAbility->SetAbilityText(_T("This creature gets +X/+X until end of turn, where X is its power."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CElectrostaticPummelerCard::BeforePump));
	AddAbility(cpAbility.GetPointer());
}

bool CElectrostaticPummelerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

bool CElectrostaticPummelerCard::BeforePump(CAbilityAction* pAction)
{
	int nX = GET_INTEGER(GetPower());
	if (GetZoneId() != ZoneId::Battlefield || nX <= 0)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+nX));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+nX), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);
	return true;
}

CFiligreeFamiliarCard::CFiligreeFamiliarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Filigree Familiar"), CardType::_ArtifactCreature, CREATURE_TYPE(Fox), nID,
		_T("3"), Power(2), Life(2))
{
	// When this creature enters, you gain 2 life.
	AddEnterTrigger(this, &CFiligreeFamiliarCard::BeforeLife);

	// When this creature dies, draw a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

bool CFiligreeFamiliarCard::BeforeLife(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 2);
	return true;
}

CFoundryInspectorCard::CFoundryInspectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Foundry Inspector"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(3), Life(2))
{
	// Artifact spells you cast cost {1} less to cast. (as Etherium Sculptor in Shards of Alara)
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CardTypeComparer(CardType::Artifact, false),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CIronLeagueSteedCard::CIronLeagueSteedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Iron League Steed"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("4"), Power(2), Life(2))
	, m_Fabricate(this, 1)
{
	// Haste, Fabricate 1
	GetCreatureKeyword()->AddHaste(FALSE);
}

CMultiformWonderCard::CMultiformWonderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Multiform Wonder"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("5"), Power(3), Life(3))
{
	// When this creature enters, you get {E}{E}{E}.
	AddEnterTrigger(this, &CMultiformWonderCard::BeforeEnergy);

	// Pay {E}: This creature gains your choice of flying, vigilance, or lifelink until end of turn.
	// Pay {E}: This creature gets +2/-2 or -2/+2 until end of turn.
	// (one ability for each choice)
	typedef bool (CMultiformWonderCard::*Callback)(CAbilityAction*);
	Callback callbacks[] = { &CMultiformWonderCard::BeforeFlying, &CMultiformWonderCard::BeforeVigilance,
							 &CMultiformWonderCard::BeforeLifelink, &CMultiformWonderCard::BeforePowerUp,
							 &CMultiformWonderCard::BeforeToughnessUp };
	LPCTSTR texts[] = { _T("This creature gains flying until end of turn."),
						_T("This creature gains vigilance until end of turn."),
						_T("This creature gains lifelink until end of turn."),
						_T("This creature gets +2/-2 until end of turn."),
						_T("This creature gets -2/+2 until end of turn.") };
	for (int i = 0; i < _countof(callbacks); ++i)
	{
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddEnergyCost(this, 1);
		cpAbility->SetAbilityText(texts[i]);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, callbacks[i]));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMultiformWonderCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

bool CMultiformWonderCard::BeforeFlying(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::Flying);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

bool CMultiformWonderCard::BeforeVigilance(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCreatureKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CreatureKeyword::Vigilance);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

bool CMultiformWonderCard::BeforeLifelink(CAbilityAction* pAction)
{
	AddCardKeywordUntilEndOfTurn(this, CardKeyword::Lifelink);
	return true;
}

bool CMultiformWonderCard::BeforePowerUp(CAbilityAction* pAction)
{
	ChangePowerToughness(+2, -2);
	return true;
}

bool CMultiformWonderCard::BeforeToughnessUp(CAbilityAction* pAction)
{
	ChangePowerToughness(-2, +2);
	return true;
}

void CMultiformWonderCard::ChangePowerToughness(int nPower, int nToughness)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return;

	CPowerModifier pPowerModifier = CPowerModifier(Power(nPower));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(nToughness), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);
}

CNarnamCobraCard::CNarnamCobraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Narnam Cobra"), CardType::_ArtifactCreature, CREATURE_TYPE(Snake), nID,
		_T("2"), Power(2), Life(1))
{
	// {G}: This creature gains deathtouch until end of turn.
	AddCardKeywordAbility(this, GREEN_MANA_TEXT, _T("This creature gains deathtouch until end of turn."),
		&CNarnamCobraCard::BeforeDeathtouch);
}

bool CNarnamCobraCard::BeforeDeathtouch(CAbilityAction* pAction) const
{
	AddCardKeywordUntilEndOfTurn((CCard*)this, CardKeyword::Deathtouch);
	return true;
}

CPrakhataPillarBugCard::CPrakhataPillarBugCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prakhata Pillar-Bug"), CardType::_ArtifactCreature, CREATURE_TYPE(Insect), nID,
		_T("3"), Power(2), Life(3))
{
	// {B}: This creature gains lifelink until end of turn.
	AddCardKeywordAbility(this, BLACK_MANA_TEXT, _T("This creature gains lifelink until end of turn."),
		&CPrakhataPillarBugCard::BeforeLifelink);
}

bool CPrakhataPillarBugCard::BeforeLifelink(CAbilityAction* pAction) const
{
	AddCardKeywordUntilEndOfTurn((CCard*)this, CardKeyword::Lifelink);
	return true;
}

CSelfAssemblerCard::CSelfAssemblerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Self-Assembler"), CardType::_ArtifactCreature, CREATURE_TYPE(AssemblyWorker), nID,
		_T("5"), Power(4), Life(4))
{
	// When this creature enters, you may search your library for an Assembly-Worker creature card, reveal it, put it
	// into your hand, then shuffle. (as Trinket Mage in Fifth Dawn)
	typedef
		TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(AssemblyWorker), false));
	cpAbility->SetToZone(ZoneId::Hand);
	AddAbility(cpAbility.GetPointer());
}

CSnareThopterCard::CSnareThopterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Snare Thopter"), CardType::_ArtifactCreature, CREATURE_TYPE(Thopter), nID,
		_T("4"), Power(3), Life(2))
{
	GetCreatureKeyword()->AddHaste(FALSE);
}

CWeldfastMonitorCard::CWeldfastMonitorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weldfast Monitor"), CardType::_ArtifactCreature, CREATURE_TYPE(Lizard), nID,
		_T("3"), Power(3), Life(2))
{
	// {R}: This creature gains menace until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this,
			RED_MANA_TEXT,
			Power(+0), Life(+0), CreatureKeyword::CantBeBlockedBy1));
	AddAbility(cpAbility.GetPointer());
}

CWorkshopAssistantCard::CWorkshopAssistantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Workshop Assistant"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(1), Life(2))
{
	// When this creature dies, return another target artifact card from your graveyard to your hand.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWorkshopAssistantCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CWorkshopAssistantCard::BeforeReturn(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
