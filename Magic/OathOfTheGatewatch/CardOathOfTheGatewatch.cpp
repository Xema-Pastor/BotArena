#include "stdafx.h"
#include "CardOathOfTheGatewatch.h"

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
		DEFINE_CARD(CAffaProtectorCard);
		DEFINE_CARD(CAlliedReinforcementsCard);
		DEFINE_CARD(CAncientCrabCard);
		DEFINE_CARD(CCallTheGatewatchCard);
		DEFINE_CARD(CCinderBarrensCard);
		DEFINE_CARD(CCanopyGorgerCard);
		DEFINE_CARD(CExpeditionRaptorCard);
		DEFINE_CARD(CImmolatingGlareCard);
		DEFINE_CARD(CIsolationZoneCard);
		DEFINE_CARD(CKorScythemasterCard);
		DEFINE_CARD(CKorSkyClimberCard);
		DEFINE_CARD(CMakeAStandCard);
		DEFINE_CARD(CMakindiAeronautCard);
		DEFINE_CARD(CMeanderingRiverCard);
		DEFINE_CARD(CMundasVanguardCard);
		DEFINE_CARD(COnduWarClericCard);
		DEFINE_CARD(CReliefCaptainCard);
		DEFINE_CARD(CSearingLightCard);
		DEFINE_CARD(CShoulderToShoulderCard);
		DEFINE_CARD(CSpawnbinderMageCard);
		DEFINE_CARD(CSteppeGliderCard);
		DEFINE_CARD(CStoneforgeAcolyteCard);
		DEFINE_CARD(CSubmergedBoneyardCard);
		DEFINE_CARD(CTimberGorgeCard);
		DEFINE_CARD(CTranquilExpanseCard);
		DEFINE_CARD(CWastesCard);
		DEFINE_CARD(CCrumblingVestigeCard);
		DEFINE_CARD(CHissingQuagmireCard);
		DEFINE_CARD(CHoldoutSettlementCard);
		DEFINE_CARD(CMirrorpoolCard);
		DEFINE_CARD(CNeedleSpiresCard);
		DEFINE_CARD(CRuinsOfOranRiefCard);
		DEFINE_CARD(CSeaGateWreckageCard);
		DEFINE_CARD(CWanderingFumaroleCard);
		DEFINE_CARD(CChandraFlamecallerCard);
		DEFINE_CARD(CNissaVoiceOfZendikarCard);
		DEFINE_CARD(CCaptainsClawsCard);
		DEFINE_CARD(CChitinousCloakCard);
		DEFINE_CARD(CHedronCrawlerCard);
		DEFINE_CARD(CSeersLanternCard);
		DEFINE_CARD(CBoulderSalvoCard);
		DEFINE_CARD(CCrushOfTentaclesCard);
		DEFINE_CARD(CDevourInFlamesCard);
		DEFINE_CARD(CFlayingTendrilsCard);
		DEFINE_CARD(COblivionStrikeCard);
		DEFINE_CARD(CRoilingWatersCard);
		DEFINE_CARD(CRuinInTheirWakeCard);
		DEFINE_CARD(CSlipThroughSpaceCard);
		DEFINE_CARD(CSparkmagesGambitCard);
		DEFINE_CARD(CWitnessTheEndCard);
		DEFINE_CARD(CAbstruseInterferenceCard);
		DEFINE_CARD(CBruteStrengthCard);
		DEFINE_CARD(CComparativeAnalysisCard);
		DEFINE_CARD(CConsumingSinkholeCard);
		DEFINE_CARD(CCorpseChurnCard);
		DEFINE_CARD(CExpediteCard);
		DEFINE_CARD(CFallOfTheTitansCard);
		DEFINE_CARD(CGripOfTheRoilCard);
		DEFINE_CARD(CLeadByExampleCard);
		DEFINE_CARD(CNaturalStateCard);
		DEFINE_CARD(COverwhelmingDenialCard);
		DEFINE_CARD(CPulseOfMurasaCard);
		DEFINE_CARD(CRealityHemorrhageCard);
		DEFINE_CARD(CSpatialContortionCard);
		DEFINE_CARD(CTarSnareCard);
		DEFINE_CARD(CTearsOfValakutCard);
		DEFINE_CARD(CUnityOfPurposeCard);
		DEFINE_CARD(CUnnaturalEnduranceCard);
		DEFINE_CARD(CVinesOfTheRecluseCard);
		DEFINE_CARD(CVoidShatterCard);
		DEFINE_CARD(CWarpingWailCard);
		DEFINE_CARD(CBondsOfMortalityCard);
		DEFINE_CARD(CContainmentMembraneCard);
		DEFINE_CARD(CHedronAlignmentCard);
		DEFINE_CARD(CIonasBlessingCard);
		DEFINE_CARD(COathOfChandraCard);
		DEFINE_CARD(COathOfGideonCard);
		DEFINE_CARD(COathOfJaceCard);
		DEFINE_CARD(COathOfNissaCard);
		DEFINE_CARD(CPyromancersAssaultCard);
		DEFINE_CARD(CUntamedHungerCard);
		DEFINE_CARD(CZendikarResurgentCard);
		DEFINE_CARD(CBearerOfSilenceCard);
		DEFINE_CARD(CBirthingHulkCard);
		DEFINE_CARD(CBlindingDroneCard);
		DEFINE_CARD(CDeepfathomSkulkerCard);
		DEFINE_CARD(CDimensionalInfiltratorCard);
		DEFINE_CARD(CEldraziDisplacerCard);
		DEFINE_CARD(CEndbringerCard);
		DEFINE_CARD(CEssenceDepleterCard);
		DEFINE_CARD(CFlayerDroneCard);
		DEFINE_CARD(CGravityNegatorCard);
		DEFINE_CARD(CHavocSowerCard);
		DEFINE_CARD(CImmobilizerEldraziCard);
		DEFINE_CARD(CInverterOfTruthCard);
		DEFINE_CARD(CKozileksShriekerCard);
		DEFINE_CARD(CKozileksTranslatorCard);
		DEFINE_CARD(CMawOfKozilekCard);
		DEFINE_CARD(CMindmelterCard);
		DEFINE_CARD(CProphetOfDistortionCard);
		DEFINE_CARD(CReaverDroneCard);
		DEFINE_CARD(CScionSummonerCard);
		DEFINE_CARD(CSifterOfSkullsCard);
		DEFINE_CARD(CSkyScourerCard);
		DEFINE_CARD(CSlaughterDroneCard);
		DEFINE_CARD(CStalkingDroneCard);
		DEFINE_CARD(CThoughtHarvesterCard);
		DEFINE_CARD(CThoughtKnotSeerCard);
		DEFINE_CARD(CVoidGrafterCard);
		DEFINE_CARD(CWalkerOfTheWastesCard);
		DEFINE_CARD(CWardenOfGeometriesCard);
		DEFINE_CARD(CWorldBreakerCard);
		DEFINE_CARD(CAkoumFlameseekerCard);
		DEFINE_CARD(CCliffhavenVampireCard);
		DEFINE_CARD(CDranasChosenCard);
		DEFINE_CARD(CGeneralTazriCard);
		DEFINE_CARD(CGoblinFreerunnerCard);
		DEFINE_CARD(CJoragaAuxiliaryCard);
		DEFINE_CARD(CMalakirSoothsayerCard);
		DEFINE_CARD(CMinaAndDennWildbornCard);
		DEFINE_CARD(CRecklessBushwhackerCard);
		DEFINE_CARD(CTajuruPathwardenCard);
		DEFINE_CARD(CUmaraEntanglerCard);
		DEFINE_CARD(CVampireEnvoyCard);
		DEFINE_CARD(CZadasCommandoCard);
		DEFINE_CARD(CZulaportChainmageCard);
		DEFINE_CARD(CBalothNullCard);
		DEFINE_CARD(CCinderHellionCard);
		DEFINE_CARD(CGladehartCavalryCard);
		DEFINE_CARD(CHarvesterTrollCard);
		DEFINE_CARD(CJoriEnRuinDiverCard);
		DEFINE_CARD(CJwarIsleAvengerCard);
		DEFINE_CARD(CLinvalaThePreserverCard);
		DEFINE_CARD(CLoamLarvaCard);
		DEFINE_CARD(CNullCallerCard);
		DEFINE_CARD(CReflectorMageCard);
		DEFINE_CARD(CRelentlessHunterCard);
		DEFINE_CARD(CSaddlebackLagacCard);
		DEFINE_CARD(CSphinxOfTheFinalWordCard);
		DEFINE_CARD(CStormchaserMageCard);
		DEFINE_CARD(CTyrantOfValakutCard);

	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
CWastesCard::CWastesCard(CGame* pGame, UINT uID)
	: CBasicLandCard(pGame, _T("Wastes"), uID, COLORLESS_MANA_TEXT, CardType::BasicLand)
{
	AllowUnlimitedCopies(TRUE);
}

//____________________________________________________________________________
//
// Lands

CCrumblingVestigeCard::CCrumblingVestigeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Crumbling Vestige"), nID)
{
	SetIntoPlayTapped();

	{
		// When this land enters, add one mana of any color. (as Quirion Sentinel)
		typedef
			TTriggeredAbility< CTriggeredProdManaAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CHissingQuagmireCard::CHissingQuagmireCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Hissing Quagmire"), nID)
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
	{
		// {1}{B}{G}: becomes a 2/2 black and green Elemental creature with deathtouch until end of turn (as Creeping Tar Pit)
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT,
				_T("Elemental AR"), 64098));
		AddAbility(cpAbility.GetPointer());
	}
}

CHoldoutSettlementCard::CHoldoutSettlementCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Holdout Settlement"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	// {T}, Tap an untapped creature you control: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < 5; ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddTapCardCost(1, CCardFilter::GetFilter(_T("creatures")));
		AddAbility(cpAbility.GetPointer());
	}
}

CMirrorpoolCard::CMirrorpoolCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Mirrorpool"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{C}, {T}, Sacrifice this land: Copy target instant or sorcery spell you control. (as Dual Casting)
		counted_ptr<CActivatedAbility<CTargetCopyCastSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetCopyCastSpell>>(this,
				_T("2") COLORLESS_MANA_TEXT,
				new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
				ZoneId::Stack));

		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}{C}, {T}, Sacrifice this land: Create a token that's a copy of target creature you control. (as Kiki-Jiki)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("4") COLORLESS_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->GetSubjectCardFilter().SetThisCardsControllerOnly(this);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMirrorpoolCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMirrorpoolCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();

	CCardCopyModifier pModifier = CCardCopyModifier(GetGame(), pTarget);
	pModifier.ApplyTo(pTarget);

	return true;
}

CNeedleSpiresCard::CNeedleSpiresCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Needle Spires"), nID)
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
	{
		// {2}{R}{W}: becomes a 2/1 red and white Elemental creature with double strike until end of turn
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T("2") RED_MANA_TEXT WHITE_MANA_TEXT,
				_T("Elemental AS"), 64099));
		AddAbility(cpAbility.GetPointer());
	}
}

CRuinsOfOranRiefCard::CRuinsOfOranRiefCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Ruins of Oran-Rief"), nID)
{
	SetIntoPlayTapped();

	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}: Put a +1/+1 counter on target colorless creature that entered this turn. (as Oran-Rief, the Vastwood)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(
			new NegateCardComparer(new CardTypeComparer(CardType::_ColorMask, false)));
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CameThisTurnIntoPlayComparer);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::Add(new CCardCounterModifier(_T("+1/+1"), +1));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

CSeaGateWreckageCard::CSeaGateWreckageCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Sea Gate Wreckage"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{C}, {T}: Draw a card. Activate only if you have no cards in hand.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T("2") COLORLESS_MANA_TEXT, 1));

		cpAbility->AddTapCost();

		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
				CPlayableIfTrait::PlayableCallback(this, &CSeaGateWreckageCard::CanPlay)));
		cpAbility->Add(cpTrait.GetPointer());

		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CSeaGateWreckageCard::CanPlay(BOOL bIncludeTricks)
{
	return GetController()->GetZoneById(ZoneId::Hand)->GetSize() == 0;
}

CWanderingFumaroleCard::CWanderingFumaroleCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Wandering Fumarole"), nID)
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
	{
		// {2}{U}{R}: becomes a 1/4 blue and red Elemental creature with "{0}: Switch this creature's power and toughness"
		counted_ptr<CIsAlsoAAbility> cpAbility(
			::CreateObject<CIsAlsoAAbility>(this,
				_T("2") BLUE_MANA_TEXT RED_MANA_TEXT,
				_T("Elemental AT"), 64100));
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// Artifacts

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

CCaptainsClawsCard::CCaptainsClawsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Captain's Claws"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("1")));

	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+1), FALSE));
	cpAbility->AddCardModifier(new CCardAbilityModifier(
		CCardAbilityModifier::CreateAbilityCallback(this, &CCaptainsClawsCard::CreateEquipmentAbility)));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

counted_ptr<CAbility> CCaptainsClawsCard::CreateEquipmentAbility(CCard* pCard)
{
	// Whenever equipped creature attacks, create a 1/1 white Kor Ally creature token that's tapped and attacking.
	// (as Hero of Bladehold)
	typedef
		TTriggeredAbility< CAttackingTokenCreationAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTokenName(_T("Kor Ally (A)"));
	cpAbility->SetTokenNumber(1);
	cpAbility->SetTokenuID(55061);

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CChitinousCloakCard::CChitinousCloakCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Chitinous Cloak"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	cpAbility->AddCreatureModifier(new CLifeModifier(Life(+2), this,
		PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	cpAbility->AddCreatureModifier(new CPowerModifier(Power(+2), FALSE));

	CCreatureKeywordModifier* pMenaceModifier = new CCreatureKeywordModifier;
	pMenaceModifier->GetModifier().SetToAdd(CreatureKeyword::CantBeBlockedBy1); // Menace
	pMenaceModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pMenaceModifier);

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CHedronCrawlerCard::CHedronCrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hedron Crawler"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Construct), nID, _T("2"), Power(0), Life(1))
{
	// {T}: Add {C}.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CSeersLanternCard::CSeersLanternCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Seer's Lantern"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, {T}: Scry 1.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddTapCost();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSeersLanternCard::BeforeResolution));
		cpAbility->SetAbilityText(_T("{2}, {T}: Scry 1."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSeersLanternCard::BeforeResolution(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 1);
	return true;
}

//____________________________________________________________________________
//
// Sorceries

CBoulderSalvoCard::CBoulderSalvoCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Boulder Salvo"), CardType::Sorcery, nID)
	, m_Surge(this)
{
	// Boulder Salvo deals 4 damage to target creature. Surge {1}{R}
	LPCTSTR costs[] = { _T("4") RED_MANA_TEXT, _T("1") RED_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				costs[i],
				new AnyCreatureComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

CCrushOfTentaclesCard::CCrushOfTentaclesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Crush of Tentacles"), CardType::Sorcery, nID)
	, m_Surge(this)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CCrushOfTentaclesCard::OnSurgeResolved))
{
	// Return all nonland permanents to their owners' hands. Surge {3}{U}{U}
	// (as Planar Outburst, but to the owners' hands)
	LPCTSTR costs[] = { _T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CGlobalMoveCardSpell> cpSpell(
			::CreateObject<CGlobalMoveCardSpell>(this, AbilityType::Sorcery,
				costs[i],
				new TrueCardComparer, ZoneId::Hand, TRUE, MoveType::Others));
		cpSpell->GetGlobalCardFilter().AddNegateComparer(
			new CardTypeComparer(CardType::_Land, false));
		cpSpell->GetGlobalCardFilter().AddNegateComparer(
			new AlsoCardTypeComparer(CardType::_Land, false));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	// If this spell's surge cost was paid, create an 8/8 blue Octopus creature token (after the permanents are returned)
	pSpells[1]->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

void CCrushOfTentaclesCard::OnSurgeResolved(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Octopus (A)"), 55055, 1);
	pModifier.ApplyTo(pAbilityAction->GetController());
}

CDevourInFlamesCard::CDevourInFlamesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Devour in Flames"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, return a land you control to its owner's hand.
	// Devour in Flames deals 5 damage to target creature or planeswalker.
	// Note: only creatures can be targeted.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-5), PreventableType::Preventable));

	cpSpell->GetCost().AddReturnFromPlayCardCost(1, CCardFilter::GetFilter(_T("lands")));
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CFlayingTendrilsCard::CFlayingTendrilsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Flaying Tendrils"), CardType::Sorcery, nID)
{
	SetDevoid();

	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFlayingTendrilsCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::CreatureChange);
	AddSpell(cpSpell.GetPointer());
}

bool CFlayingTendrilsCard::BeforeResolution(CAbilityAction* pAction) const
{
	// All creatures get -2/-2 until end of turn. If a creature would die this turn, exile it instead.
	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	// The exile replacement is applied first, so it is in place when the toughness drops (as Scourge's exile-instead spells)
	CReplacementKeywordModifier pExileModifier;
	pExileModifier.GetModifier().SetOneTurnOnly(TRUE);
	pExileModifier.GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);

	CPowerModifier pPowerModifier = CPowerModifier(Power(-2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pExileModifier.ApplyTo(pCreatures.GetAt(i));

	for (int i = 0; i < pCreatures.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));
	}

	return true;
}

COblivionStrikeCard::COblivionStrikeCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Oblivion Strike"), CardType::Sorcery, nID,
		_T("3") BLACK_MANA_TEXT, AbilityType::Sorcery,
		new AnyCreatureComparer,
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
{
	SetDevoid();

	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CRoilingWatersCard::CRoilingWatersCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Roiling Waters"), CardType::Sorcery, nID)
{
	counted_ptr<CRoilingWatersSpell> cpSpell(
		::CreateObject<CRoilingWatersSpell>(this, AbilityType::Sorcery,
			_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT));

	AddSpell(cpSpell.GetPointer());
}

CRoilingWatersCard::CRoilingWatersSpell::CRoilingWatersSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost)
	: CDoubleTargetSpell(pCard, abilityType, strManaCost,
		new AnyCreatureComparer, false,
		FALSE_CARD_COMPARER, true,
		_T(""))
{
	// Return up to two target creatures your opponents control to their owners' hands. Target player draws two cards.
	// Note: one or two creatures must be chosen.
	GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	GetTargeting1()->SetIncludeNonControllerCardsOnly();
	GetTargeting1()->SetSubjectCount(1, 2);
	GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
}

void CRoilingWatersCard::CRoilingWatersSpell::ResolveGroup(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2,
														   const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others);
	for (int i = 0; i < pContainer1.GetSize(); ++i)
		pModifier.ApplyTo(pContainer1.GetAt(i));

	if (pPContainer2.GetSize())
	{
		CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(2), MaximumValue(2));
		pDrawModifier.ApplyTo(pPContainer2.GetAt(0));
	}
}

CRuinInTheirWakeCard::CRuinInTheirWakeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ruin in Their Wake"), CardType::Sorcery, nID)
{
	SetDevoid();

	// Search your library for a basic land card and reveal it. You may put that card onto the battlefield tapped
	// if you control a land named Wastes. Otherwise, put that card into your hand.
	// Note: done as two spells, one usable only with a Wastes and the other only without; checked when it is cast.
	{
		counted_ptr<CSearchLibrarySpell> cpSpell(
			::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
				_T("1") GREEN_MANA_TEXT,
				CCardFilter::GetFilter(_T("basic lands")),
				ZoneId::Battlefield, FALSE, TRUE, TRUE));
		cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(1));

		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
				CPlayableIfTrait::PlayableCallback(this, &CRuinInTheirWakeCard::CanPlayToBattlefield)));
		cpSpell->Add(cpTrait.GetPointer());

		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CSearchLibrarySpell> cpSpell(
			::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
				_T("1") GREEN_MANA_TEXT,
				CCardFilter::GetFilter(_T("basic lands")),
				ZoneId::Hand, TRUE, FALSE, FALSE));
		cpSpell->SetSearchCount(MinimumValue(0), MaximumValue(1));

		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
				CPlayableIfTrait::PlayableCallback(this, &CRuinInTheirWakeCard::CanPlayToHand)));
		cpSpell->Add(cpTrait.GetPointer());

		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CRuinInTheirWakeCard::ControlsWastes() const
{
	CCardFilter wastesFilter(new CardNameComparer(_T("Wastes")));
	return wastesFilter.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

BOOL CRuinInTheirWakeCard::CanPlayToBattlefield(BOOL bIncludeTricks)
{
	return ControlsWastes();
}

BOOL CRuinInTheirWakeCard::CanPlayToHand(BOOL bIncludeTricks)
{
	return !ControlsWastes();
}

CSlipThroughSpaceCard::CSlipThroughSpaceCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Slip Through Space"), CardType::Sorcery, nID, AbilityType::Sorcery,
		BLUE_MANA_TEXT,
		Power(+0), Life(+0),
		CreatureKeyword::Unblockable, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	SetDevoid();

	// Target creature can't be blocked this turn. Draw a card.
	m_pTargetChgPwrTghAttrSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));
}

CSparkmagesGambitCard::CSparkmagesGambitCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sparkmage's Gambit"), CardType::Sorcery, nID)
{
	// Deals 1 damage to each of up to two target creatures. Those creatures can't block this turn.
	// Note: one or two creatures must be chosen.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-1), PreventableType::Preventable));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargetModifier().CCreatureModifiers::push_back(new CCreatureKeywordModifier(CreatureKeyword::CantBlock, TRUE));
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CWitnessTheEndCard::CWitnessTheEndCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Witness the End"), CardType::Sorcery, nID)
{
	SetDevoid();

	// Target opponent exiles two cards from their hand and loses 2 life. (as Mire's Malice, exiling)
	counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
		::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT,
			2, MoveType::Others, ZoneId::Exile, TRUE,
			TRUE,	// the targeted player chooses
			CCardFilter::GetFilter(_T("cards"))));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWitnessTheEndCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	AddSpell(cpSpell.GetPointer());
}

bool CWitnessTheEndCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (pOpponent)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

//____________________________________________________________________________
//
// Instants

CAbstruseInterferenceCard::CAbstruseInterferenceCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Abstruse Interference"), CardType::Instant, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	SetDevoid();

	// Counter target spell unless its controller pays {1} (as Mana Leak).
	// You create a 1/1 colorless Eldrazi Scion creature token.
	m_pCounterSpell->SetCanBeDenied();
	m_pCounterSpell->GetDenialCost().SetManaCost(_T("1"));
	m_pCounterSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Eldrazi Scion (A)"), 55056, 1));
	m_pCounterSpell->AddAbilityTag(AbilityTag::TokenCreation);
}

CBruteStrengthCard::CBruteStrengthCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Brute Strength"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") RED_MANA_TEXT,
		Power(+3), Life(+1),
		CreatureKeyword::Trample, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
}

CComparativeAnalysisCard::CComparativeAnalysisCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Comparative Analysis"), CardType::Instant, nID)
	, m_Surge(this)
{
	// Target player draws two cards. Surge {2}{U}
	LPCTSTR costs[] = { _T("3") BLUE_MANA_TEXT, _T("2") BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetDrawCardSpell> cpSpell(
			::CreateObject<CTargetDrawCardSpell>(this, AbilityType::Instant,
				costs[i], 2));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

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

CConsumingSinkholeCard::CConsumingSinkholeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Consuming Sinkhole"), CardType::Instant, nID)
{
	SetDevoid();

	// Choose one:
	{
		// Exile target land creature.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("3") RED_MANA_TEXT,
				new LandCreatureComparer,
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Consuming Sinkhole deals 4 damage to target player or planeswalker.
		// Note: only players can be targeted.
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				_T("3") RED_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE,
				Life(-4), PreventableType::Preventable));
		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		AddSpell(cpSpell.GetPointer());
	}
}

CCorpseChurnCard::CCorpseChurnCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Corpse Churn"), CardType::Instant, nID)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CCorpseChurnCard::OnCardSelected))
{
	// Mill three cards, then you may return a creature card from your graveyard to your hand.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCorpseChurnCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CCorpseChurnCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	CMoveCardModifier pMillModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < 3 && pLibrary->GetSize() > 0; ++i)
		pMillModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));

	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (!pCard->GetCardType().IsCreature())
			continue;

		SelectionEntry entry;

		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Return %s to your hand"), pCard->GetCardName(TRUE));

		entries.push_back(entry);
	}

	if (!entries.empty())
	{
		SelectionEntry entry;

		entry.dwContext = 0;
		entry.strText = _T("Don't return a card");

		entries.push_back(entry);

		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	}

	return true;
}

void CCorpseChurnCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			return;
		}
}

CExpediteCard::CExpediteCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Expedite"), CardType::Instant, nID, AbilityType::Instant,
		RED_MANA_TEXT,
		Power(+0), Life(+0),
		CreatureKeyword::Haste, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Target creature gains haste until end of turn. Draw a card.
	m_pTargetChgPwrTghAttrSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));
}

CFallOfTheTitansCard::CFallOfTheTitansCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fall of the Titans"), CardType::Instant, nID)
	, m_Surge(this)
{
	// Fall of the Titans deals X damage to each of up to two targets. Surge {X}{R}
	// (as Blaze; one or two targets must be chosen)
	LPCTSTR costs[] = { RED_MANA_TEXT, RED_MANA_TEXT };
	BOOL bDoubleX[] = { TRUE, FALSE };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				costs[i],
				new AnyCreatureComparer, TRUE,
				Life(0), PreventableType::Preventable));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, bDoubleX[i]);
		cpSpell->SetExtraActionValueVector(ContextValue(-1));
		cpSpell->GetTargeting()->SetSubjectCount(1, 2);
		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

CGripOfTheRoilCard::CGripOfTheRoilCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grip of the Roil"), CardType::Instant, nID)
	, m_Surge(this)
{
	// Tap target creature. It doesn't untap during its controller's next untap step. Draw a card. Surge {1}{U}
	// (as Rush of Ice)
	LPCTSTR costs[] = { _T("2") BLUE_MANA_TEXT, _T("1") BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetTapUntapCardSpell> cpSpell(
			::CreateObject<CTargetTapUntapCardSpell>(this, AbilityType::Instant,
				costs[i],
				TRUE, FALSE,	// Tap, Untap
				new CardTypeComparer(CardType::Creature, false)));
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

		cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));

		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

CLeadByExampleCard::CLeadByExampleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lead by Example"), CardType::Instant, nID)
{
	// Support 2. (Put a +1/+1 counter on each of up to two target creatures.)
	// Note: one or two creatures must be chosen.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT, new AnyCreatureComparer, FALSE));
	cpSpell->GetTargeting()->SetSubjectZoneId(ZoneId::Battlefield);
	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargetModifier().CCardModifiers::Add(new CCardCounterModifier(_T("+1/+1"), 1));
	AddSpell(cpSpell.GetPointer());
}

CNaturalStateCard::CNaturalStateCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Natural State"), CardType::Instant, nID,
		GREEN_MANA_TEXT, AbilityType::Instant,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
		ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy)
{
	// Destroy target artifact or enchantment with mana value 3 or less.
	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less<int>>(4));
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

COverwhelmingDenialCard::COverwhelmingDenialCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Overwhelming Denial"), CardType::Instant, nID)
	, m_Surge(this)
{
	// Surge {U}{U}. This spell can't be countered. Counter target spell.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	LPCTSTR costs[] = { _T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, BLUE_MANA_TEXT BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				costs[i], new TrueCardComparer));
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

CPulseOfMurasaCard::CPulseOfMurasaCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Pulse of Murasa"), CardType::Instant, nID,
		_T("2") GREEN_MANA_TEXT, AbilityType::Instant,
		new CardTypeComparer(CardType::Creature | CardType::_Land, false),
		ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others)
{
	// Return target creature or land card from a graveyard to its owner's hand. You gain 6 life.
	m_pTargetMoveCardSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+6), this, PreventableType::NotPreventable));
}

CRealityHemorrhageCard::CRealityHemorrhageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reality Hemorrhage"), CardType::Instant, nID)
{
	SetDevoid();

	// Reality Hemorrhage deals 2 damage to any target.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-2), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CSpatialContortionCard::CSpatialContortionCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Spatial Contortion"), CardType::Instant, nID, AbilityType::Instant,
		_T("1") COLORLESS_MANA_TEXT,
		Power(+3), Life(-3),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
}

CTarSnareCard::CTarSnareCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Tar Snare"), CardType::Instant, nID, AbilityType::Instant,
		_T("2") BLACK_MANA_TEXT,
		Power(-3), Life(-2),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	m_pTargetChgPwrTghAttrSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CTearsOfValakutCard::CTearsOfValakutCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tears of Valakut"), CardType::Instant, nID)
{
	// This spell can't be countered.
	GetCardKeyword()->AddCantBeCountered(FALSE);

	// Tears of Valakut deals 5 damage to target creature with flying.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			new CreatureKeywordComparer(CreatureKeyword::Flying, false), FALSE,
			Life(-5), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CUnityOfPurposeCard::CUnityOfPurposeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unity of Purpose"), CardType::Instant, nID)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CUnityOfPurposeCard::OnResolutionCompleted))
{
	// Support 2. (Put a +1/+1 counter on each of up to two target creatures.)
	// Note: one or two creatures must be chosen.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT, new AnyCreatureComparer, FALSE));
	cpSpell->GetTargeting()->SetSubjectZoneId(ZoneId::Battlefield);
	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargetModifier().CCardModifiers::Add(new CCardCounterModifier(_T("+1/+1"), 1));

	// Untap each creature you control with a +1/+1 counter on it (after the counters are put).
	cpSpell->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

void CUnityOfPurposeCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CZone* pBattlefield = pAbilityAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && (pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0))
			pModifier.ApplyTo(pCard);
	}
}

CUnnaturalEnduranceCard::CUnnaturalEnduranceCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Unnatural Endurance"), CardType::Instant, nID, AbilityType::Instant,
		BLACK_MANA_TEXT,
		Power(+2), Life(+0),
		CreatureKeyword::Null, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	SetDevoid();

	// Target creature gets +2/+0 until end of turn. Regenerate it.
	m_pTargetChgPwrTghAttrSpell->GetTargetModifier().CCreatureModifiers::push_back(new CRegenerateModifier());
}

CVinesOfTheRecluseCard::CVinesOfTheRecluseCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrSpellCard(pGame, _T("Vines of the Recluse"), CardType::Instant, nID, AbilityType::Instant,
		GREEN_MANA_TEXT,
		Power(+1), Life(+2),
		CreatureKeyword::Reach, CreatureKeyword::Null,
		TRUE, PreventableType::NotPreventable)
{
	// Target creature gets +1/+2 and gains reach until end of turn. Untap it.
	m_pTargetChgPwrTghAttrSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
}

CVoidShatterCard::CVoidShatterCard(CGame* pGame, UINT nID)
	: CCounterSpellCard(pGame, _T("Void Shatter"), CardType::Instant, nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, AbilityType::Instant,
		new TrueCardComparer)
{
	SetDevoid();

	// Counter target spell. If that spell is countered this way, exile it instead of putting it into its owner's graveyard.
	m_pCounterSpell->SetToZone(ZoneId::Exile, TRUE);
}

struct LowPowerOrToughnessComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		if (!pCard->GetCardType().IsCreature())
			return false;

		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
		if (!pCreature) return false;
		return GET_INTEGER(pCreature->GetPower()) <= 1 || GET_INTEGER(pCreature->GetToughness()) <= 1;
	}

	virtual LowPowerOrToughnessComparer* Clone() const
	{
		return new LowPowerOrToughnessComparer;
	}
};

CWarpingWailCard::CWarpingWailCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Warping Wail"), CardType::Instant, nID)
{
	// Choose one:
	{
		// Exile target creature with power or toughness 1 or less.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("1") COLORLESS_MANA_TEXT,
				new LowPowerOrToughnessComparer,
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Counter target sorcery spell.
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("1") COLORLESS_MANA_TEXT,
				new CardTypeComparer(CardType::Sorcery, false)));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Create a 1/1 colorless Eldrazi Scion creature token.
		counted_ptr<CTokenProductionSpell> cpSpell(
			::CreateObject<CTokenProductionSpell>(this, AbilityType::Instant,
				_T("1") COLORLESS_MANA_TEXT,
				_T("Eldrazi Scion (A)"), 55056,
				1));
		AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
//
// Enchantments

CBondsOfMortalityCard::CBondsOfMortalityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Bonds of Mortality"), CardType::GlobalEnchantment, nID,
		_T("1") GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// When this enchantment enters, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(1);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {G}: Creatures your opponents control lose hexproof and indestructible until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				GREEN_MANA_TEXT));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBondsOfMortalityCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBondsOfMortalityCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToRemove(CardKeyword::Hexproof | CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pAction->GetController())
			continue;

		CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pModifier.ApplyTo(pBattlefield->GetAt(i));
	}

	return true;
}

CContainmentMembraneCard::CContainmentMembraneCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Containment Membrane"), CardType::EnchantCreature, nID)
	, m_Surge(this)
{
	// Enchanted creature doesn't untap during its controller's untap step. Surge {U}
	LPCTSTR costs[] = { _T("2") BLUE_MANA_TEXT, BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CChgPwrTghAttrEnchant> cpSpell(
			::CreateObject<CChgPwrTghAttrEnchant>(this, costs[i],
				Power(+0), Life(+0), CreatureKeyword::Null));

		cpSpell->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Surge.SetSpells(pSpells[0], pSpells[1]);
}

CHedronAlignmentCard::CHedronAlignmentCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hedron Alignment"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	GetCardKeyword()->AddHexproof(FALSE);

	{
		// At the beginning of your upkeep, you may reveal your hand. If you do, you win the game if you own a card
		// named Hedron Alignment in exile, in your hand, in your graveyard, and on the battlefield.
		// (as Felidar Sovereign; the hand is not revealed)
		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CHedronAlignmentCard::SetTriggerContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CHedronAlignmentCard::BeforeResolution));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{U}: Scry 1.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1") BLUE_MANA_TEXT));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHedronAlignmentCard::BeforeScry));
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CHedronAlignmentCard::HasAllHedronAlignments() const
{
	CPlayer* pPlayer = GetController();
	CCardFilter nameFilter(new CardNameComparer(_T("Hedron Alignment")));

	ZoneId zones[] = { ZoneId::Exile, ZoneId::Hand, ZoneId::Graveyard };
	for (int i = 0; i < 3; ++i)
		if (nameFilter.CountIncluded(pPlayer->GetZoneById(zones[i])->GetCardContainer()) == 0)
			return FALSE;

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetOwner() == pPlayer && nameFilter.IsCardIncluded(pBattlefield->GetAt(i)))
				return TRUE;
	}

	return FALSE;
}

bool CHedronAlignmentCard::SetTriggerContext(CTriggeredLoseGameAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasAllHedronAlignments() ? true : false;
}

bool CHedronAlignmentCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction)
{
	return HasAllHedronAlignments() ? true : false;
}

bool CHedronAlignmentCard::BeforeScry(CAbilityAction* pAction) const
{
	ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, 1);
	return true;
}

CIonasBlessingCard::CIonasBlessingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Iona's Blessing"), CardType::EnchantCreature, nID)
{
	// Enchanted creature gets +2/+2, has vigilance, and can block an additional creature each combat.
	counted_ptr<CIonasBlessingEnchant> cpSpell(
		::CreateObject<CIonasBlessingEnchant>(this, _T("3") WHITE_MANA_TEXT));
	AddSpell(cpSpell.GetPointer());
}

CIonasBlessingCard::CIonasBlessingEnchant::CIonasBlessingEnchant(CCard* pCard, LPCTSTR strManaCost)
	: CChgPwrTghAttrEnchant(pCard, strManaCost, Power(+2), Life(+2), CreatureKeyword::Vigilance)
{
}

BOOL CIonasBlessingCard::CIonasBlessingEnchant::OnEnchant(CCard* pCard, ContextValue_& contextValue)
{
	if (!__super::OnEnchant(pCard, contextValue))
		return FALSE;

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (pCreature && pCreature->GetMaxBlockingCount() != SpecialNumber::Any)
		pCreature->SetMaxBlockingCount(pCreature->GetMaxBlockingCount() + 1);

	return TRUE;
}

void CIonasBlessingCard::CIonasBlessingEnchant::OnDisenchant(CCard* pCard, const ContextValue& contextValue)
{
	__super::OnDisenchant(pCard, contextValue);

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (pCreature && pCreature->GetMaxBlockingCount() != SpecialNumber::Any && pCreature->GetMaxBlockingCount() > 1)
		pCreature->SetMaxBlockingCount(pCreature->GetMaxBlockingCount() - 1);
}

COathOfChandraCard::COathOfChandraCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Chandra"), CardType::_LegendaryGlobalEnchantment, nID,
		_T("1") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_nPlaneswalkerTurn(-1)
{
	{
		// When Oath of Chandra enters, it deals 3 damage to target creature an opponent controls.
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
	{
		// Remembers the turn a planeswalker entered the battlefield under your control (never goes to the stack)
		counted_ptr<PlaneswalkerAbility> cpAbility(
			::CreateObject<PlaneswalkerAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Planeswalker, false));
		cpAbility->SetContextFunction(PlaneswalkerAbility::ContextFunction(this, &COathOfChandraCard::OnPlaneswalkerEntered));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each end step, if a planeswalker entered the battlefield under your control this turn,
		// Oath of Chandra deals 2 damage to each opponent.
		counted_ptr<EndStepAbility> cpAbility(::CreateObject<EndStepAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(EndStepAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->SetContextFunction(EndStepAbility::ContextFunction(this, &COathOfChandraCard::SetEndStepContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);

		AddAbility(cpAbility.GetPointer());
	}
}

bool COathOfChandraCard::OnPlaneswalkerEntered(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	m_nPlaneswalkerTurn = GetGame()->GetGameTurnNumber();
	return false;
}

bool COathOfChandraCard::SetEndStepContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return m_nPlaneswalkerTurn == GetGame()->GetGameTurnNumber();
}

COathOfGideonCard::COathOfGideonCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Gideon"), CardType::_LegendaryGlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// When Oath of Gideon enters, create two 1/1 white Kor Ally creature tokens.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Kor Ally (A)"), 55061, 2);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Each planeswalker you control enters with an additional loyalty counter on it.
		// Note: done as a trigger that doesn't use the stack.
		typedef
			TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Planeswalker, false));
		cpAbility->SetSkipStack(TRUE);
		cpAbility->GetTriggeredCardModifiers().push_back(new CCardCounterModifier(LOYALTY_COUNTER, +1));

		AddAbility(cpAbility.GetPointer());
	}
}

COathOfJaceCard::COathOfJaceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Jace"), CardType::_LegendaryGlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// When Oath of Jace enters, draw three cards, then discard two cards.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(3);
		cpAbility->SetDiscard(2, FALSE, MoveType::Discard);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of your upkeep, scry X, where X is the number of planeswalkers you control.
		counted_ptr<UpkeepAbility> cpAbility(::CreateObject<UpkeepAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(UpkeepAbility::OptionalType::Required);
		cpAbility->SetContextFunction(UpkeepAbility::ContextFunction(this, &COathOfJaceCard::SetUpkeepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COathOfJaceCard::BeforeScry));

		AddAbility(cpAbility.GetPointer());
	}
}

int COathOfJaceCard::CountPlaneswalkers() const
{
	CCardFilter filter(new CardTypeComparer(CardType::Planeswalker, false));
	return filter.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
}

bool COathOfJaceCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	// Scry 0 does nothing
	return CountPlaneswalkers() > 0;
}

bool COathOfJaceCard::BeforeScry(CAbilityAction* pAction) const
{
	int nCount = CountPlaneswalkers();
	if (nCount > 0)
		ApplyScry(GetGame(), pAction->GetController(), (CCard*)this, nCount);
	return true;
}

COathOfNissaCard::COathOfNissaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Nissa"), CardType::_LegendaryGlobalEnchantment, nID,
		GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_CardFilter(_T("a creature, land, or planeswalker card"), _T("creature, land, or planeswalker cards"),
		new CardTypeComparer(CardType::Creature | CardType::_Land | CardType::Planeswalker, false))
{
	// When Oath of Nissa enters, look at the top three cards of your library. You may reveal a creature, land,
	// or planeswalker card from among them and put it into your hand. Put the rest on the bottom of your library in any order.
	// Note: "You may spend mana as though it were mana of any color to cast planeswalker spells" is not implemented.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COathOfNissaCard::BeforeResolution));

	AddAbility(cpAbility.GetPointer());
}

bool COathOfNissaCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as the scry selection, with the selected card to the hand and the rest to the bottom)
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(3), MaximumValue(3));
		pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
		pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
		pModifier->GetSelection(0).moveType = MoveType::Others;
		pModifier->AddSelection(MinimumValue(0), MaximumValue(1), // select a card to the hand
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::AllPlayers,	// reveal to
			&m_CardFilter,							// creature, land or planeswalker cards
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

CPyromancersAssaultCard::CPyromancersAssaultCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pyromancer's Assault"), CardType::GlobalEnchantment, nID,
		_T("3") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast your second spell each turn, this enchantment deals 2 damage to any target.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPyromancersAssaultCard::SetTriggerContext));

	cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

bool CPyromancersAssaultCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	// (as Incursion Specialist)
	return (GetController()->GetTurnCastedSpellCount() == 2);
}

CUntamedHungerCard::CUntamedHungerCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Untamed Hunger"), nID,
		_T("2") BLACK_MANA_TEXT,
		Power(+2), Life(+1), CreatureKeyword::CantBeBlockedBy1)	// Menace
{
}

CZendikarResurgentCard::CZendikarResurgentCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Zendikar Resurgent"), CardType::GlobalEnchantment, nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever you tap a land for mana, add one mana of any type that land produced. (as Heartbeat of Spring)
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("lands")));
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
		cpAbility->SetSkipStack(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CZendikarResurgentCard::SetTriggerContext));

		m_pTriggeredAbility = cpAbility.GetPointer();
		AddAbility(m_pTriggeredAbility);
	}
	{
		// Whenever you cast a creature spell, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > DrawAbility;

		counted_ptr<DrawAbility> cpAbility(::CreateObject<DrawAbility>(this));

		cpAbility->SetOptionalType(DrawAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetDrawCount(1);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CZendikarResurgentCard::SetTriggerContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
											const CManaProductionAbilityAction* pManaAction) const
{
	// Only lands you tap
	if (pManaAction->GetAbility()->GetCard()->GetController() != GetController())
		return false;

	// One mana of the first type the land produced
	const auto& pool = m_pTriggeredAbility->GetTrigger().GetManaPool(pManaAction);

	m_pTriggeredAbility->SetProduceColorless(FALSE);
	m_pTriggeredAbility->SetProduceWhite(FALSE);
	m_pTriggeredAbility->SetProduceBlue(FALSE);
	m_pTriggeredAbility->SetProduceBlack(FALSE);
	m_pTriggeredAbility->SetProduceRed(FALSE);
	m_pTriggeredAbility->SetProduceGreen(FALSE);

	if (pool.GetMana(CManaPool::Color::Green))
		m_pTriggeredAbility->SetProduceGreen(TRUE);
	else if (pool.GetMana(CManaPool::Color::White))
		m_pTriggeredAbility->SetProduceWhite(TRUE);
	else if (pool.GetMana(CManaPool::Color::Blue))
		m_pTriggeredAbility->SetProduceBlue(TRUE);
	else if (pool.GetMana(CManaPool::Color::Black))
		m_pTriggeredAbility->SetProduceBlack(TRUE);
	else if (pool.GetMana(CManaPool::Color::Red))
		m_pTriggeredAbility->SetProduceRed(TRUE);
	else if (pool.GetMana(CManaPool::Color::Colorless))
		m_pTriggeredAbility->SetProduceColorless(TRUE);
	else
		return false;

	return true;
}

//____________________________________________________________________________
//
// Eldrazi creatures

// Colorless means no color at all (colored artifacts are not colorless; devoid cards are)
static bool IsColorless(const CCard* pCard)
{
	return !(pCard->GetCardType() & CardType::_ColorMask).Any();
}

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

struct NontokenComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return !pCard->GetCardType().IsToken();
	}

	virtual NontokenComparer* Clone() const
	{
		return new NontokenComparer;
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

// Exiles the top card of pPlayer's library and returns it (NULL if the library is empty)
static CCard* ExileTopOfLibrary(CPlayer* pPlayer)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return NULL;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others);
	pModifier.ApplyTo(pCard);
	return pCard;
}

CBearerOfSilenceCard::CBearerOfSilenceCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bearer of Silence"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("1") BLACK_MANA_TEXT, Power(2), Life(1))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CBearerOfSilenceCard::OnCardSelected))
{
	SetDevoid();
	GetCreatureKeyword()->AddCantBlock(FALSE);

	// When you cast this spell, you may pay {1}{C}. If you do, target opponent sacrifices a creature.
	// Note: affects each opponent (the target opponent in a two-player game)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetResolutionCost(_T("1") COLORLESS_MANA_TEXT);
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CBearerOfSilenceCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));

	AddAbility(cpAbility.GetPointer());
}

bool CBearerOfSilenceCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pController = pAction->GetController();

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);

		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (!pCard->GetCardType().IsCreature())
				continue;

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));

			entries.push_back(entry);
		}

		// The opponent chooses the creature
		if (!entries.empty())
			m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);
	}

	return true;
}

void CBearerOfSilenceCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			return;
		}
}

CBirthingHulkCard::CBirthingHulkCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Birthing Hulk"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("6") GREEN_MANA_TEXT,
		Power(5), Life(4), 2)
{
	SetDevoid();

	// {1}{C}: Regenerate this creature.
	counted_ptr<CRegenerationAbility> cpAbility(
		::CreateObject<CRegenerationAbility>(this,
			_T("1") COLORLESS_MANA_TEXT,
			(CCreatureCard*)this));
	AddAbility(cpAbility.GetPointer());
}

CBlindingDroneCard::CBlindingDroneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Blinding Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	SetDevoid();

	// {C}, {T}: Tap target creature.
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			COLORLESS_MANA_TEXT,
			TRUE, FALSE,	// Tap, Untap
			new CardTypeComparer(CardType::Creature, false)));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CDeepfathomSkulkerCard::CDeepfathomSkulkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deepfathom Skulker"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("5") BLUE_MANA_TEXT, Power(4), Life(4))
{
	SetDevoid();

	{
		// Whenever a creature you control deals combat damage to a player, you may draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenDamageDealt,
								CWhenDamageDealt::PlayerEventCallback,
								&CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().SetCombatDamageOnly(TRUE);
		cpAbility->GetTrigger().GetFromCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetFromCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetDrawCount(1);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{C}: Target creature can't be blocked this turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T("3") COLORLESS_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::Unblockable, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		AddAbility(cpAbility.GetPointer());
	}
}

CDimensionalInfiltratorCard::CDimensionalInfiltratorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dimensional Infiltrator"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("1") BLUE_MANA_TEXT, Power(2), Life(1))
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CDimensionalInfiltratorCard::OnSelected))
{
	SetDevoid();
	GetCardKeyword()->AddFlash(FALSE);

	// {1}{C}: Target opponent exiles the top card of their library. If it's a land card, you may return this creature to its owner's hand.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") COLORLESS_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDimensionalInfiltratorCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CDimensionalInfiltratorCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CCard* pExiled = ExileTopOfLibrary(pOpponent);
	if (pExiled && pExiled->GetCardType().IsLand() && GetZoneId() == ZoneId::Battlefield)
	{
		std::vector<SelectionEntry> entries;
		{
			SelectionEntry entry;
			entry.dwContext = 1;
			entry.strText.Format(_T("Return %s to its owner's hand"), GetCardName(TRUE));
			entries.push_back(entry);
		}
		{
			SelectionEntry entry;
			entry.dwContext = 0;
			entry.strText.Format(_T("Keep %s on the battlefield"), GetCardName(TRUE));
			entries.push_back(entry);
		}
		m_Selection.AddSelectionRequest(entries, 1, 1, NULL, pAction->GetController());
	}

	return true;
}

void CDimensionalInfiltratorCard::OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && it->dwContext == 1 && GetZoneId() == ZoneId::Battlefield)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(this);
			return;
		}
}

CEldraziDisplacerCard::CEldraziDisplacerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eldrazi Displacer"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("2") WHITE_MANA_TEXT, Power(3), Life(3))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
		&CEldraziDisplacerCard::OnResolutionCompleted))
{
	SetDevoid();

	// {2}{C}: Exile another target creature, then return it to the battlefield tapped under its owner's control.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("2") COLORLESS_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
	AddAbility(cpAbility.GetPointer());
}

void CEldraziDisplacerCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	if (!bResult) return;

	CCard* pCard = pAbilityAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Exile)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others);
	pModifier.SetTapped(TRUE);
	pModifier.ApplyTo(pCard);
}

CEndbringerCard::CEndbringerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Endbringer"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("5") COLORLESS_MANA_TEXT, Power(5), Life(5))
{
	{
		// Untap this creature during each other player's untap step. (as Seedborn Muse)
		typedef
			TTriggeredAbility< CTriggeredTapCardAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UntapStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetTapCardOption(CTriggeredTapCardAbility::TapCardOption::UntapSingleCard);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEndbringerCard::SetUntapContext));
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
		cpAbility->SetSkipStack(TRUE);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}: This creature deals 1 damage to any target.
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-1), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {C}, {T}: Target creature can't attack or block this turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				COLORLESS_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::CantAttack | CreatureKeyword::CantBlock, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {C}{C}, {T}: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				COLORLESS_MANA_TEXT COLORLESS_MANA_TEXT, 1));

		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CEndbringerCard::SetUntapContext(CTriggeredTapCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	if (GetZoneId() != ZoneId::Battlefield || !GetOrientation()->IsTapped())
		return false;

	triggerContext.m_pCard = (CCard*)this;
	return true;
}

CEssenceDepleterCard::CEssenceDepleterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Essence Depleter"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	SetDevoid();

	// {1}{C}: Target opponent loses 1 life and you gain 1 life.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("1") COLORLESS_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE,
			Life(-1), PreventableType::NotPreventable));

	cpAbility->SetDamageType(DamageType::NotDealingDamage);	// life lost
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+1), this, PreventableType::NotPreventable));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CFlayerDroneCard::CFlayerDroneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Flayer Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(1))
{
	SetDevoid();
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Whenever another colorless creature you control enters, target opponent loses 1 life.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new ColorlessCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));

	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);

	AddAbility(cpAbility.GetPointer());
}

CGravityNegatorCard::CGravityNegatorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Gravity Negator"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") BLUE_MANA_TEXT, Power(2), Life(3))
{
	SetDevoid();

	// Whenever this creature attacks, you may pay {C}. If you do, another target creature gains flying until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetResolutionCost(COLORLESS_MANA_TEXT);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::Flying);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CHavocSowerCard::CHavocSowerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Havoc Sower"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	SetDevoid();

	// {1}{C}: This creature gets +2/+1 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("1") COLORLESS_MANA_TEXT, Power(+2), Life(+1)));
	AddAbility(cpAbility.GetPointer());
}

CImmobilizerEldraziCard::CImmobilizerEldraziCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Immobilizer Eldrazi"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	SetDevoid();

	// {2}{C}: Each creature with toughness greater than its power can't block this turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") COLORLESS_MANA_TEXT));

	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImmobilizerEldraziCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CImmobilizerEldraziCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
			if (pCreature && pCreature->GetCardType().IsCreature() &&
				GET_INTEGER(pCreature->GetToughness()) > GET_INTEGER(pCreature->GetPower()))
				pModifier.ApplyTo(pCreature);
		}
	}

	return true;
}

CInverterOfTruthCard::CInverterOfTruthCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Inverter of Truth"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(6), Life(6))
{
	SetDevoid();

	// When this creature enters, exile all cards from your library face down, then shuffle all cards from your graveyard into your library.
	// Note: the cards are exiled face up
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Exile));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInverterOfTruthCard::BeforeResolution));

	AddAbility(cpAbility.GetPointer());
}

bool CInverterOfTruthCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CMoveCardModifier pExileModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others);
	while (pLibrary->GetSize() > 0)
		pExileModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));

	CMoveCardModifier pLibraryModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others);
	while (pGraveyard->GetSize() > 0)
		pLibraryModifier.ApplyTo(pGraveyard->GetAt(pGraveyard->GetSize() - 1));

	pLibrary->Shuffle();
	return true;
}

CKozileksShriekerCard::CKozileksShriekerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kozilek's Shrieker"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	SetDevoid();

	// {C}: This creature gets +1/+0 and gains menace until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, COLORLESS_MANA_TEXT, Power(+1), Life(+0),
			CreatureKeyword::CantBeBlockedBy1));
	AddAbility(cpAbility.GetPointer());
}

CKozileksTranslatorCard::CKozileksTranslatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kozilek's Translator"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("4") BLACK_MANA_TEXT, Power(3), Life(5))
{
	SetDevoid();

	// Pay 1 life: Add {C}. Activate only once each turn.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
	cpAbility->GetCost().SetPlayerLifeCost(this, Life(-1));
	cpAbility->SetMaxTurnUsageCount(1);
	AddAbility(cpAbility.GetPointer());
}

CMawOfKozilekCard::CMawOfKozilekCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Maw of Kozilek"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") RED_MANA_TEXT, Power(2), Life(5))
{
	SetDevoid();

	// {C}: This creature gets +2/-2 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, COLORLESS_MANA_TEXT, Power(+2), Life(-2)));
	AddAbility(cpAbility.GetPointer());
}

CMindmelterCard::CMindmelterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mindmelter"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	SetDevoid();
	GetCreatureKeyword()->AddUnblockable(FALSE);

	// {3}{C}: Target opponent exiles a card from their hand. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetPlayerDiscardCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetPlayerDiscardCardSpell>>(this,
			_T("3") COLORLESS_MANA_TEXT,
			1, MoveType::Others, ZoneId::Exile, TRUE,
			TRUE,	// the targeted player chooses
			CCardFilter::GetFilter(_T("cards"))));

	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
	AddAbility(cpAbility.GetPointer());
}

CProphetOfDistortionCard::CProphetOfDistortionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prophet of Distortion"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, BLUE_MANA_TEXT, Power(1), Life(2))
{
	SetDevoid();

	// {3}{C}: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("3") COLORLESS_MANA_TEXT, 1));
	AddAbility(cpAbility.GetPointer());
}

CReaverDroneCard::CReaverDroneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reaver Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, BLACK_MANA_TEXT, Power(2), Life(1))
{
	SetDevoid();

	// At the beginning of your upkeep, you lose 1 life unless you control another colorless creature.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage); // life lost
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CReaverDroneCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);

	AddAbility(cpAbility.GetPointer());
}

bool CReaverDroneCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !ControlsAnotherColorlessCreature(GetController(), this);
}

CScionSummonerCard::CScionSummonerCard(CGame* pGame, UINT nID)
	: CScionMakerCreatureCard(pGame, _T("Scion Summoner"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("2") GREEN_MANA_TEXT,
		Power(2), Life(2), 1)
{
	SetDevoid();
}

CSifterOfSkullsCard::CSifterOfSkullsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sifter of Skulls"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("3") BLACK_MANA_TEXT, Power(4), Life(3))
{
	SetDevoid();

	// Whenever another nontoken creature you control dies, create a 1/1 colorless Eldrazi Scion creature token.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new NontokenComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Scion (A)"), 55056, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

	AddAbility(cpAbility.GetPointer());
}

CSkyScourerCard::CSkyScourerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sky Scourer"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLACK_MANA_TEXT, Power(1), Life(2))
{
	SetDevoid();

	// Whenever you cast a colorless spell, this creature gets +1/+0 until end of turn. (as Kozilek's Sentinel)
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

CSlaughterDroneCard::CSlaughterDroneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Slaughter Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	SetDevoid();

	// {C}: This creature gains deathtouch until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, COLORLESS_MANA_TEXT, Power(+0), Life(+0)));
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	AddAbility(cpAbility.GetPointer());
}

CStalkingDroneCard::CStalkingDroneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stalking Drone"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	SetDevoid();

	// {C}: This creature gets +1/+2 until end of turn. Activate only once each turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, COLORLESS_MANA_TEXT, Power(+1), Life(+2)));
	cpAbility->SetMaxTurnUsageCount(1);
	AddAbility(cpAbility.GetPointer());
}

CThoughtHarvesterCard::CThoughtHarvesterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Thought Harvester"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("3") BLUE_MANA_TEXT, Power(2), Life(4))
{
	SetDevoid();

	// Whenever you cast a colorless spell, target opponent exiles the top card of their library.
	// Note: affects each opponent (the target opponent in a two-player game)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new NegateCardComparer(new CardTypeComparer(CardType::_ColorMask, false)));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CThoughtHarvesterCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Exile));

	AddAbility(cpAbility.GetPointer());
}

bool CThoughtHarvesterCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
		if (GetGame()->GetPlayer(i) != pAction->GetController())
			ExileTopOfLibrary(GetGame()->GetPlayer(i));
	return true;
}

CThoughtKnotSeerCard::CThoughtKnotSeerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thought-Knot Seer"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("3") COLORLESS_MANA_TEXT, Power(4), Life(4))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CThoughtKnotSeerCard::OnCardSelected))
{
	{
		// When this creature enters, target opponent reveals their hand. You choose a nonland card from it and exile that card.
		// Note: affects each opponent (the target opponent in a two-player game)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Hand, ZoneId::Exile));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThoughtKnotSeerCard::BeforeResolution));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// When this creature leaves the battlefield, target opponent draws a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
		cpAbility->SetDrawCount(1);

		AddAbility(cpAbility.GetPointer());
	}
}

bool CThoughtKnotSeerCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();

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
			if (pCard->GetCardType().IsLand())
				continue;

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Exile %s"), pCard->GetCardName(TRUE));

			entries.push_back(entry);
		}

		// You choose the card
		if (!entries.empty())
			m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	}

	return true;
}

void CThoughtKnotSeerCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			return;
		}
}

CVoidGrafterCard::CVoidGrafterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Void Grafter"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(4))
{
	SetDevoid();
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, another target creature you control gains hexproof until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Hexproof);
	cpAbility->GetCardKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CWalkerOfTheWastesCard::CWalkerOfTheWastesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Walker of the Wastes"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("4") COLORLESS_MANA_TEXT, Power(4), Life(4))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// This creature gets +1/+1 for each land you control named Wastes. (as Vile Aggregate)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new CardNameComparer(_T("Wastes"))));

	AddAbility(cpAbility.GetPointer());
}

CWardenOfGeometriesCard::CWardenOfGeometriesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Warden of Geometries"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Drone), nID, _T("4"), Power(2), Life(3))
{
	GetCreatureKeyword()->AddVigilance(FALSE);

	// {T}: Add {C}.
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CWorldBreakerCard::CWorldBreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("World Breaker"), CardType::Creature,
		CREATURE_TYPE(Eldrazi), nID, _T("6") GREEN_MANA_TEXT, Power(5), Life(7))
{
	SetDevoid();
	GetCreatureKeyword()->AddReach(FALSE);

	{
		// When you cast this spell, exile target artifact, enchantment, or land. (as Ulamog, the Ceaseless Hunger)
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this,
				ZoneId::_AllZones, ZoneId::Stack));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment | CardType::_Land, false));
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{C}, Sacrifice a land: Return this card from your graveyard to your hand.
		counted_ptr<CSelfMoveCardAbility> cpAbility(
			::CreateObject<CSelfMoveCardAbility>(this,
				_T("2") COLORLESS_MANA_TEXT,
				ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("lands")));
		cpAbility->SetGraveyardOnly();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// Allies

CCohortCreatureCard::CCohortCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
										 LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_CohortFilter(_T("an untapped Ally"), _T("untapped Allies"), new CreatureTypeComparer(CREATURE_TYPE(Ally), false))
{
	m_CohortFilter.AddNegateComparer(new TappedComparer);
	m_CohortFilter.AddNegateComparer(new SpecificCardComparer(this));
}

void CCohortCreatureCard::AddCohortCost(CAbility* pAbility)
{
	// {T}, Tap an untapped Ally you control
	pAbility->AddTapCost();
	pAbility->GetCost().AddTapCardCost(1, &m_CohortFilter);
}

CAkoumFlameseekerCard::CAkoumFlameseekerCard(CGame* pGame, UINT nID)
	: CCohortCreatureCard(pGame, _T("Akoum Flameseeker"), CardType::Creature,
		CREATURE_TYPE3(Human, Shaman, Ally), nID, _T("2") RED_MANA_TEXT, Power(3), Life(2))
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CAkoumFlameseekerCard::OnCardSelected))
{
	// Cohort - {T}, Tap an untapped Ally you control: Discard a card. If you do, draw a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	AddCohortCost(cpAbility.GetPointer());
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAkoumFlameseekerCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CAkoumFlameseekerCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

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
		m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController);

	return true;
}

void CAkoumFlameseekerCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pSelectionPlayer);
			pModifier.ApplyTo(pCard);

			CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
			pDrawModifier.ApplyTo(pSelectionPlayer);

			return;
		}
}

CCliffhavenVampireCard::CCliffhavenVampireCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Cliffhaven Vampire"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Warrior, Ally), nID, _T("2") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(4))
{
	// Whenever you gain life, each opponent loses 1 life.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenPlayerLifeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToOpponents);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCliffhavenVampireCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);

	AddAbility(cpAbility.GetPointer());
}

bool CCliffhavenVampireCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	if (nToLife <= nFromLife)
		return false;

	triggerContext.m_LifeModifier.SetLifeDelta(Life(-1));
	triggerContext.m_LifeModifier.SetDamageType(DamageType::NotDealingDamage);
	triggerContext.m_LifeModifier.SetPreventable(PreventableType::NotPreventable);
	return true;
}

CDranasChosenCard::CDranasChosenCard(CGame* pGame, UINT nID)
	: CCohortCreatureCard(pGame, _T("Drana's Chosen"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Shaman, Ally), nID, _T("3") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Cohort - {T}, Tap an untapped Ally you control: Create a tapped 2/2 black Zombie creature token.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this, _T("")));

	AddCohortCost(cpAbility.GetPointer());
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDranasChosenCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CDranasChosenCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCountedCardContainer createdCards;
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, 1,
		FALSE, ZoneId::Battlefield, &createdCards);
	pModifier.ApplyTo(pAction->GetController());

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < createdCards.GetSize(); ++i)
		pTapModifier.ApplyTo(createdCards.GetAt(i));

	return true;
}

CGeneralTazriCard::CGeneralTazriCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("General Tazri"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Human, Ally), nID, _T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
	{
		// When General Tazri enters, you may search your library for an Ally creature card, reveal it, put it into your hand, then shuffle.
		typedef
			TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Ally), false));
		cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
		cpAbility->SetToZone(ZoneId::Hand);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {W}{U}{B}{R}{G}: Ally creatures you control get +X/+X until end of turn, where X is the number of colors among those creatures.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				WHITE_MANA_TEXT BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT GREEN_MANA_TEXT));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGeneralTazriCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGeneralTazriCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CreatureTypeComparer allyComparer(CREATURE_TYPE(Ally), false);

	CCountedCardContainer allies;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && allyComparer(pCard))
			allies.AddCard(pCard, CardPlacement::Top);
	}

	CardType colors[] = { CardType::White, CardType::Blue, CardType::Black, CardType::Red, CardType::Green };
	int nColors = 0;
	for (int c = 0; c < 5; ++c)
		for (int i = 0; i < allies.GetSize(); ++i)
			if ((allies.GetAt(i)->GetCardType() & colors[c]).Any())
			{
				++nColors;
				break;
			}

	if (nColors == 0)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+nColors));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+nColors), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < allies.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)allies.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)allies.GetAt(i));
	}

	return true;
}

CGoblinFreerunnerCard::CGoblinFreerunnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Goblin Freerunner"), CardType::Creature,
		CREATURE_TYPE3(Goblin, Warrior, Ally), nID, _T("3") RED_MANA_TEXT, Power(3), Life(2))
	, m_Surge(this)
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace

	// Surge {1}{R}
	counted_ptr<CSpell> cpSurgeSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("1") RED_MANA_TEXT, TRUE));
	AddSpell(cpSurgeSpell.GetPointer());

	m_Surge.SetSpells(GetSpells().GetAt(0), cpSurgeSpell.GetPointer());
}

CJoragaAuxiliaryCard::CJoragaAuxiliaryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Joraga Auxiliary"), CardType::Creature,
		CREATURE_TYPE3(Elf, Soldier, Ally), nID, _T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(3))
{
	// {4}{G}{W}: Support 2. (Put a +1/+1 counter on each of up to two other target creatures.)
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T("4") GREEN_MANA_TEXT WHITE_MANA_TEXT,
			Power(+0), Life(+0),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->GetTargeting()->SetSubjectCount(0, 2);
	cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));
	AddAbility(cpAbility.GetPointer());
}

CMalakirSoothsayerCard::CMalakirSoothsayerCard(CGame* pGame, UINT nID)
	: CCohortCreatureCard(pGame, _T("Malakir Soothsayer"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Shaman, Ally), nID, _T("4") BLACK_MANA_TEXT, Power(4), Life(4))
{
	// Cohort - {T}, Tap an untapped Ally you control: You draw a card and you lose 1 life.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this, _T(""), 1));

	AddCohortCost(cpAbility.GetPointer());
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	AddAbility(cpAbility.GetPointer());
}

CMinaAndDennWildbornCard::CMinaAndDennWildbornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mina and Denn, Wildborn"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Elf, Ally), nID, _T("2") RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	{
		// You may play an additional land on each of your turns.
		counted_ptr<CPlayExtraLandEnchantment> cpAbility(
			::CreateObject<CPlayExtraLandEnchantment>(this, +1));

		cpAbility->SetAffectControllerOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {R}{G}, Return a land you control to its owner's hand: Target creature gains trample until end of turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				RED_MANA_TEXT GREEN_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::Trample, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->GetCost().AddReturnFromPlayCardCost(1, CCardFilter::GetFilter(_T("lands")));
		AddAbility(cpAbility.GetPointer());
	}
}

CRecklessBushwhackerCard::CRecklessBushwhackerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reckless Bushwhacker"), CardType::Creature,
		CREATURE_TYPE3(Goblin, Warrior, Ally), nID, _T("2") RED_MANA_TEXT, Power(2), Life(1))
	, m_Surge(this)
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// Surge {1}{R}
	counted_ptr<CSpell> cpSurgeSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("1") RED_MANA_TEXT, TRUE));
	AddSpell(cpSurgeSpell.GetPointer());

	m_Surge.SetSpells(GetSpells().GetAt(0), cpSurgeSpell.GetPointer());

	// When this creature enters, if its surge cost was paid, other creatures you control get +1/+0 and gain haste until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRecklessBushwhackerCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRecklessBushwhackerCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CRecklessBushwhackerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
												 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Surge.WasSurgeCostPaid() ? true : false;
}

bool CRecklessBushwhackerCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CCreatureKeywordModifier pHasteModifier;
	pHasteModifier.GetModifier().SetToAdd(CreatureKeyword::Haste);
	pHasteModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard == this || !pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pHasteModifier.ApplyTo((CCreatureCard*)pCard);
	}

	return true;
}

CTajuruPathwardenCard::CTajuruPathwardenCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tajuru Pathwarden"), CardType::Creature,
		CREATURE_TYPE3(Elf, Warrior, Ally), nID, _T("4") GREEN_MANA_TEXT, Power(5), Life(4))
{
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
}

CUmaraEntanglerCard::CUmaraEntanglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Umara Entangler"), CardType::Creature,
		CREATURE_TYPE3(Merfolk, Rogue, Ally), nID, _T("1") BLUE_MANA_TEXT, Power(2), Life(1))
{
	// Prowess (as Jeskai Windscout)
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

CVampireEnvoyCard::CVampireEnvoyCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Vampire Envoy"), CardType::Creature,
		CREATURE_TYPE3(Vampire, Cleric, Ally), nID, _T("2") BLACK_MANA_TEXT, Power(1), Life(4))
{
	// Whenever this creature becomes tapped, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfOrientationChanged,
						   CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetTapEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);

	AddAbility(cpAbility.GetPointer());
}

CZadasCommandoCard::CZadasCommandoCard(CGame* pGame, UINT nID)
	: CCohortCreatureCard(pGame, _T("Zada's Commando"), CardType::Creature,
		CREATURE_TYPE3(Goblin, Archer, Ally), nID, _T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Cohort - {T}, Tap an untapped Ally you control: This creature deals 1 damage to target opponent or planeswalker.
	// Note: only opponents can be targeted.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE,
			Life(-1), PreventableType::Preventable));

	AddCohortCost(cpAbility.GetPointer());
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

CZulaportChainmageCard::CZulaportChainmageCard(CGame* pGame, UINT nID)
	: CCohortCreatureCard(pGame, _T("Zulaport Chainmage"), CardType::Creature,
		CREATURE_TYPE3(Human, Shaman, Ally), nID, _T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// Cohort - {T}, Tap an untapped Ally you control: Target opponent loses 2 life.
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE,
			Life(-2), PreventableType::NotPreventable));

	AddCohortCost(cpAbility.GetPointer());
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->SetDamageType(DamageType::NotDealingDamage);	// life lost
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Other creatures

CBalothNullCard::CBalothNullCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Baloth Null"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Beast), nID, _T("4") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, return up to two target creature cards from your graveyard to your hand.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetSubjectCount(0, 2);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));

	AddAbility(cpAbility.GetPointer());
}

CCinderHellionCard::CCinderHellionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cinder Hellion"), CardType::Creature,
		CREATURE_TYPE(Hellion), nID, _T("4") RED_MANA_TEXT, Power(4), Life(4))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, it deals 2 damage to target opponent or planeswalker.
	// Note: only opponents can be targeted.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

CGladehartCavalryCard::CGladehartCavalryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gladehart Cavalry"), CardType::Creature,
		CREATURE_TYPE2(Elf, Knight), nID, _T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// When this creature enters, support 6. (as Expedition Raptor)
	// Note: "Whenever a creature you control with a +1/+1 counter on it dies, you gain 2 life" is not implemented.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Battlefield);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetSubjectCount(0, 6);

	AddAbility(cpAbility.GetPointer());
}

CHarvesterTrollCard::CHarvesterTrollCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Harvester Troll"), CardType::Creature,
		CREATURE_TYPE(Troll), nID, _T("3") GREEN_MANA_TEXT, Power(2), Life(3))
	, m_SacrificeFilter(_T("a creature or land"), _T("creatures or lands"),
		new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	// When this creature enters, you may sacrifice a creature or land. If you do, put two +1/+1 counters on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetSacrificeResolutionCost(1, &m_SacrificeFilter);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHarvesterTrollCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

bool CHarvesterTrollCard::BeforeResolution(CAbilityAction* pAction) const
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +2);
		pModifier.ApplyTo((CCard*)this);
	}
	return true;
}

CJoriEnRuinDiverCard::CJoriEnRuinDiverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Jori En, Ruin Diver"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Merfolk, Wizard), nID, _T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cast your second spell each turn, draw a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CJoriEnRuinDiverCard::SetTriggerContext));
	cpAbility->SetDrawCount(1);

	AddAbility(cpAbility.GetPointer());
}

bool CJoriEnRuinDiverCard::SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	return (GetController()->GetTurnCastedSpellCount() == 2);
}

CJwarIsleAvengerCard::CJwarIsleAvengerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Jwar Isle Avenger"), CardType::Creature,
		CREATURE_TYPE(Sphinx), nID, _T("4") BLUE_MANA_TEXT, Power(3), Life(3))
	, m_Surge(this)
{
	// Surge {2}{U}
	counted_ptr<CSpell> cpSurgeSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("2") BLUE_MANA_TEXT, TRUE));
	AddSpell(cpSurgeSpell.GetPointer());

	m_Surge.SetSpells(GetSpells().GetAt(0), cpSurgeSpell.GetPointer());
}

CLinvalaThePreserverCard::CLinvalaThePreserverCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Linvala, the Preserver"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Angel), nID, _T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	{
		// When Linvala enters, if an opponent has more life than you, you gain 5 life.
		typedef
			TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+5));
		cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLinvalaThePreserverCard::SetLifeContext));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// When Linvala enters, if an opponent controls more creatures than you, create a 3/3 white Angel creature token with flying.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Angel (K)"), 55070, 1);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLinvalaThePreserverCard::SetTokenContext));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);

		AddAbility(cpAbility.GetPointer());
	}
}

static int CountCreatures(const CPlayer* pPlayer)
{
	CCardFilter filter(new AnyCreatureComparer);
	return filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
}

bool CLinvalaThePreserverCard::SetLifeContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											  CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(i);
		if (pPlayer != GetController() && pPlayer->GetLife() > GetController()->GetLife())
			return true;
	}
	return false;
}

bool CLinvalaThePreserverCard::SetTokenContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
											   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	int nMyCreatures = CountCreatures(GetController());

	for (int i = 0; i < GetGame()->GetPlayerCount(); ++i)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(i);
		if (pPlayer != GetController() && CountCreatures(pPlayer) > nMyCreatures)
			return true;
	}
	return false;
}

CLoamLarvaCard::CLoamLarvaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Loam Larva"), CardType::Creature,
		CREATURE_TYPE(Insect), nID, _T("1") GREEN_MANA_TEXT, Power(1), Life(3))
{
	// When this creature enters, you may search your library for a basic land card, reveal it, then shuffle and put that card on top.
	typedef
		TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("basic lands")));
	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpAbility->SetToZone(ZoneId::Library);
	cpAbility->SetPlacement(CardPlacement::Top);

	AddAbility(cpAbility.GetPointer());
}

CNullCallerCard::CNullCallerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Null Caller"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Shaman), nID, _T("3") BLACK_MANA_TEXT, Power(2), Life(4))
	, m_ExileFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
{
	// {3}{B}, Exile a creature card from your graveyard: Create a tapped 2/2 black Zombie creature token.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") BLACK_MANA_TEXT));

	cpAbility->GetCost().AddExileGraveyardCardCost(1, &m_ExileFilter);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNullCallerCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CNullCallerCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Drana's Chosen)
	CCountedCardContainer createdCards;
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, 1,
		FALSE, ZoneId::Battlefield, &createdCards);
	pModifier.ApplyTo(pAction->GetController());

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < createdCards.GetSize(); ++i)
		pTapModifier.ApplyTo(createdCards.GetAt(i));

	return true;
}

CReflectorMageCard::CReflectorMageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reflector Mage"), CardType::Creature,
		CREATURE_TYPE2(Human, Wizard), nID, _T("1") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, return target creature an opponent controls to its owner's hand.
	// Note: "That creature's owner can't cast spells with the same name as that creature until your next turn" is not implemented.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Hand));

	AddAbility(cpAbility.GetPointer());
}

CRelentlessHunterCard::CRelentlessHunterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Relentless Hunter"), CardType::Creature,
		CREATURE_TYPE2(Human, Warrior), nID, _T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	// {1}{R}{G}: This creature gets +1/+1 and gains trample until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("1") RED_MANA_TEXT GREEN_MANA_TEXT, Power(+1), Life(+1),
			CreatureKeyword::Trample));
	AddAbility(cpAbility.GetPointer());
}

CSaddlebackLagacCard::CSaddlebackLagacCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Saddleback Lagac"), CardType::Creature,
		CREATURE_TYPE(Lizard), nID, _T("3") GREEN_MANA_TEXT, Power(3), Life(1))
{
	// When this creature enters, support 2. (as Expedition Raptor)
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
			CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Battlefield);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetSubjectCount(0, 2);

	AddAbility(cpAbility.GetPointer());
}

CSphinxOfTheFinalWordCard::CSphinxOfTheFinalWordCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Sphinx of the Final Word"), CardType::Creature,
		CREATURE_TYPE(Sphinx), nID, _T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(5))
{
	// This spell can't be countered. Flying. Hexproof.
	// Note: "Instant and sorcery spells you control can't be countered" is not implemented.
	GetCardKeyword()->AddCantBeCountered(FALSE);
	GetCardKeyword()->AddHexproof(FALSE);
}

CStormchaserMageCard::CStormchaserMageCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Stormchaser Mage"), CardType::Creature,
		CREATURE_TYPE2(Human, Wizard), nID, BLUE_MANA_TEXT RED_MANA_TEXT, Power(1), Life(3))
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// Prowess (as Jeskai Windscout)
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

CTyrantOfValakutCard::CTyrantOfValakutCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Tyrant of Valakut"), CardType::Creature,
		CREATURE_TYPE(Dragon), nID, _T("5") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(4))
	, m_Surge(this)
{
	// Surge {3}{R}{R}
	counted_ptr<CSpell> cpSurgeSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3") RED_MANA_TEXT RED_MANA_TEXT, TRUE));
	AddSpell(cpSurgeSpell.GetPointer());

	m_Surge.SetSpells(GetSpells().GetAt(0), cpSurgeSpell.GetPointer());

	// When this creature enters, if its surge cost was paid, it deals 3 damage to any target.
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
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTyrantOfValakutCard::SetTriggerContext));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

bool CTyrantOfValakutCard::SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
											 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return m_Surge.WasSurgeCostPaid() ? true : false;
}

//____________________________________________________________________________
//
// Planeswalkers

CChandraFlamecallerCard::CChandraFlamecallerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Chandra, Flamecaller"), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Chandra, 4)
{
	{
		// +1: Create two 3/1 red Elemental creature tokens with haste. Exile them at the beginning of the next end step.
		// (the token exiles itself)
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				_T("Elemental (ZB)"), 55068,
				2));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// 0: Discard all the cards in your hand, then draw that many cards plus one.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandraFlamecallerCard::BeforeResolution0));
		cpAbility->SetAbilityText(_T("0: Discard all the cards in your hand, then draw that many cards plus one."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -X: Chandra deals X damage to each creature. (X as Tezzeret the Seeker)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), SpecialNumber::AnyNegative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandraFlamecallerCard::BeforeResolutionX));
		cpAbility->SetAbilityText(_T("-X: Chandra deals X damage to each creature."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CChandraFlamecallerCard::BeforeResolution0(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

	int nCount = pHand->GetSize();

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	while (pHand->GetSize() > 0)
		pModifier.ApplyTo(pHand->GetAt(pHand->GetSize() - 1));

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(nCount + 1), MaximumValue(nCount + 1));
	pDrawModifier.ApplyTo(pController);

	return true;
}

bool CChandraFlamecallerCard::BeforeResolutionX(CAbilityAction* pAction) const
{
	int nX = -pAction->GetCostConfigEntry().GetExtraValue();
	if (nX <= 0)
		return true;

	CCountedCardContainer pCreatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CLifeModifier pModifier = CLifeModifier(Life(-nX), (CCard*)this, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pModifier.ApplyTo((CCreatureCard*)pCreatures.GetAt(i));

	return true;
}

CNissaVoiceOfZendikarCard::CNissaVoiceOfZendikarCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nissa, Voice of Zendikar"), nID,
		_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Nissa, 3)
{
	{
		// +1: Create a 0/1 green Plant creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				_T("Plant (C)"), 55066,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Put a +1/+1 counter on each creature you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaVoiceOfZendikarCard::BeforeResolution2));
		cpAbility->SetAbilityText(_T("-2: Put a +1/+1 counter on each creature you control."));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: You gain X life and draw X cards, where X is the number of lands you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaVoiceOfZendikarCard::BeforeResolution7));
		cpAbility->SetAbilityText(_T("-7: You gain X life and draw X cards, where X is the number of lands you control."));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNissaVoiceOfZendikarCard::BeforeResolution2(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer pCreatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pCreatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
	for (int i = 0; i < pCreatures.GetSize(); ++i)
		pModifier.ApplyTo(pCreatures.GetAt(i));

	return true;
}

bool CNissaVoiceOfZendikarCard::BeforeResolution7(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	int nLands = CCardFilter::GetFilter(_T("lands"))->CountIncluded(
		pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nLands <= 0)
		return true;

	CLifeModifier pLifeModifier = CLifeModifier(Life(+nLands), (CCard*)this, PreventableType::NotPreventable);
	pLifeModifier.ApplyTo(pController);

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(nLands), MaximumValue(nLands));
	pDrawModifier.ApplyTo(pController);

	return true;
}

//____________________________________________________________________________
//
CMeanderingRiverCard::CMeanderingRiverCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Meandering River"), nID)
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
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLUE_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CSubmergedBoneyardCard::CSubmergedBoneyardCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Submerged Boneyard"), nID)
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
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, BLACK_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CCinderBarrensCard::CCinderBarrensCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Cinder Barrens"), nID)
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
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, RED_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CTimberGorgeCard::CTimberGorgeCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Timber Gorge"), nID)
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
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CTranquilExpanseCard::CTranquilExpanseCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Tranquil Expanse"), nID)
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
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, WHITE_MANA_TEXT));

		cpAbility->AddTapCost();

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CAffaProtectorCard::CAffaProtectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Affa Protector"), CardType::Creature, CREATURE_TYPE3(Human, Soldier, Ally), nID,
		_T("2") WHITE_MANA_TEXT, Power(1), Life(4))
{
	GetCreatureKeyword()->AddVigilance(FALSE);
}

//____________________________________________________________________________
//
CCanopyGorgerCard::CCanopyGorgerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Canopy Gorger"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(5))
{
}

//____________________________________________________________________________
//
CMakindiAeronautCard::CMakindiAeronautCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Makindi Aeronaut"), CardType::Creature, CREATURE_TYPE3(Kor, Scout, Ally), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(3))
{
}

//____________________________________________________________________________
//
CKorSkyClimberCard::CKorSkyClimberCard(CGame* pGame, UINT nID)
	: CPumpCreatureCard(pGame, _T("Kor Sky Climber"), CardType::Creature, CREATURE_TYPE3(Kor, Soldier, Ally), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2),
		_T("1") WHITE_MANA_TEXT, Power(+0), Life(+0), CreatureKeyword::Flying)
{
}

//____________________________________________________________________________
//
CSearingLightCard::CSearingLightCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Searing Light"), CardType::Instant, nID,
		WHITE_MANA_TEXT, AbilityType::Instant,
		new CreaturePowerComparer<std::less<int>>(3),		//with power 2 or less
		ZoneId::Battlefield, ZoneId::Graveyard,	TRUE, MoveType::Destroy)
{
	m_pTargetMoveCardSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(
		new AttackingBlockingCreatureComparer);
}

//____________________________________________________________________________
//
CShoulderToShoulderCard::CShoulderToShoulderCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shoulder to Shoulder"), CardType::Sorcery, nID)
{
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
			_T("2") WHITE_MANA_TEXT,
			Power(+0), Life(+0), 
			CreatureKeyword::Null, CreatureKeyword::Null,
			true, PreventableType::NotPreventable));
	ATLASSERT(cpSpell);

	cpSpell->GetTargeting()->SetSubjectCount(0, 2); // Support 2 on each of up to two target creatures
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("+1/+1"), +1));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));

	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CCallTheGatewatchCard::CCallTheGatewatchCard(CGame* pGame, UINT nID)
	: CSearchLibrarySpellCard(pGame, _T("Call the Gatewatch"), CardType::Sorcery, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Sorcery,
		&m_CardFilter,
		ZoneId::Hand, TRUE, TRUE, FALSE)
	, m_CardFilter(_T("a planeswalker"), _T("planeswalkers"), new CardTypeComparer(CardType::Planeswalker, false)) //must declare filter this way for cards involved in the search to be filtered
{
	m_pSearchLibrarySpell->SetSearchCount(MinimumValue(0), MaximumValue(1));
}

//____________________________________________________________________________
//
CMakeAStandCard::CMakeAStandCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Make a Stand"), CardType::Instant, nID)
{
	counted_ptr<CPwrTghAttrEnchantment> cpSpell(
		::CreateObject<CPwrTghAttrEnchantment>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new AnyCreatureComparer,
			Power(+1), Life(+0)));

    cpSpell->SetAffectControllerCardsOnly();
	cpSpell->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Indestructible);

	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CKorScythemasterCard::CKorScythemasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kor Scythemaster"), CardType::Creature, CREATURE_TYPE3(Kor, Soldier, Ally), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(1))
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0)));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->GetConditionFilter().AddComparer(new AttackingCreatureComparer);
		
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::FirstStrike);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(FALSE);

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CSpawnbinderMageCard::CSpawnbinderMageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spawnbinder Mage"), CardType::Creature, CREATURE_TYPE3(Human, Wizard, Ally), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(4))
	, m_CardFilter(_T("an Ally"), _T("Allies"), new CreatureTypeComparer(CREATURE_TYPE(Ally), false))
{	
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			_T(""),
			TRUE, FALSE,
			new CardTypeComparer(CardType::Creature, false)));
	
	cpAbility->AddTapCost();
	cpAbility->GetCost().AddTapCardCost(1, &m_CardFilter); // Cohort

	AddAbility(cpAbility.GetPointer());	
}

//____________________________________________________________________________
//
COnduWarClericCard::COnduWarClericCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ondu War Cleric"), CardType::Creature, CREATURE_TYPE3(Human, Cleric, Ally), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
	, m_CardFilter(_T("an Ally"), _T("Allies"), new CreatureTypeComparer(CREATURE_TYPE(Ally), false))
{	
	counted_ptr<CActivatedAbility<CChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CChgLifeSpell>>(this,
			_T(""),
			Life(+2), PreventableType::NotPreventable));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddTapCardCost(1, &m_CardFilter); // Cohort

	AddAbility(cpAbility.GetPointer());	
}

//____________________________________________________________________________
//
CStoneforgeAcolyteCard::CStoneforgeAcolyteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stoneforge Acolyte"), CardType::Creature, CREATURE_TYPE3(Human, Artificer, Ally), nID,
		WHITE_MANA_TEXT, Power(1), Life(2))
	, m_CardFilter1(_T("an Ally"), _T("Allies"), new CreatureTypeComparer(CREATURE_TYPE(Ally), false))
	, m_CardFilter2(_T("an Equipment card"), _T("Equipment cards"), new CardTypeComparer(CardType::Equipment, false)) //must declare filter this way for cards involved in the search to be filtered
{	
	counted_ptr<CActivatedAbility<CRevealLibraryCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CRevealLibraryCardSpell>>(this,
			_T(""),
			4));
	
	ATLASSERT(cpAbility);

	cpAbility->SetSelectionOptions(MinimumValue(0), MaximumValue(1), ZoneId::Hand, CardPlacement::NotApplicable, &m_CardFilter2);
	cpAbility->SetReorder(TRUE, ZoneId::Library, CardPlacement::Bottom);
	cpAbility->SetRevealCardsToOthers(
		TRUE,	// reveal cards to others
		TRUE);	// reveal only selected cards

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddTapCardCost(1, &m_CardFilter1); // Cohort

	AddAbility(cpAbility.GetPointer());	
}

//____________________________________________________________________________
//
CMundasVanguardCard::CMundasVanguardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Munda's Vanguard"), CardType::Creature, CREATURE_TYPE3(Kor, Knight, Ally), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
	, m_CardFilter(_T("an Ally"), _T("Allies"), new CreatureTypeComparer(CREATURE_TYPE(Ally), false))
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
					&CMundasVanguardCard::OnResolutionCompleted))
{	
	counted_ptr<CActivatedAbility<CPwrTghAttrEnchantment>> cpAbility(
			::CreateObject<CActivatedAbility<CPwrTghAttrEnchantment>>(this,
				_T(""),
				new AnyCreatureComparer,
				Power(+0), Life(+0)));
	ATLASSERT(cpAbility);

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddTapCardCost(1, &m_CardFilter); // Cohort

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());

	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on each creature you control. Activates"));

	AddAbility(cpAbility.GetPointer());
}

void CMundasVanguardCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
{
	CZone* pBattle =  pAbilityAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
	for (int i = 0; i < pBattle->GetSize(); ++i)
	{
		CCard* pOppCard = pBattle->GetAt(i);
		if (pOppCard->GetCardType().IsCreature())
			pModifier.ApplyTo(pOppCard);
	}
}
//____________________________________________________________________________
//
CSteppeGliderCard::CSteppeGliderCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Steppe Glider"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("4") WHITE_MANA_TEXT, Power(2), Life(4))
{
	GetCreatureKeyword()->AddVigilance(FALSE);
	{
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T("1") WHITE_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::Flying | CreatureKeyword::Vigilance, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable,
				new CardCounterComparer<std::greater_equal<int>>(_T("+1/+1"), 1)));
		
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);

		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
CReliefCaptainCard::CReliefCaptainCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Relief Captain"), CardType::Creature, CREATURE_TYPE3(Kor, Knight, Ally), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
				CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
		
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Battlefield);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this))); // Not this card
		cpAbility->GetTargeting().SetSubjectCount(0, 3); // Support 3 on each of up to three target creatures

		AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CExpeditionRaptorCard::CExpeditionRaptorCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Expedition Raptor"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
				CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->GetCardModifiers().Add(new CCardCounterModifier(_T("+1/+1"), +1));
		
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Battlefield);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this))); // Not this card
		cpAbility->GetTargeting().SetSubjectCount(0, 2); // Support 2 on each of up to two target creatures

		AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CIsolationZoneCard::CIsolationZoneCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Isolation Zone"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay, 
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Creature | CardType::_Enchantment, false));

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		m_CardFlagModifier1.GetModifier().SetOneTurnOnly(FALSE);
		m_CardFlagModifier1.GetModifier().SetToAdd(CardFlag::AbilityFlag);
		m_CardFlagModifier1.GetModifier().SetAdditionData(cpAbility->GetInstanceID());
		cpAbility->GetMoveCardModifier().LinkCardModifier(&m_CardFlagModifier1);							// link card flag modifier with the move card modifier; when a card is moved, the card will be flagged also

		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(FALSE);

		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenSelfInplay, 
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);

		cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToAllPlayers);

		m_CardFlagModifier2.GetModifier().SetOneTurnOnly(FALSE);
		m_CardFlagModifier2.GetModifier().SetToRemove(CardFlag::AbilityFlag);
		m_CardFlagModifier2.GetModifier().SetRemovalData(m_CardFlagModifier1.GetModifier().GetAdditionData()); // remove 'flag' flagged by the first trigger
		cpAbility->GetMoveCardModifier().LinkCardModifier(&m_CardFlagModifier2);							   // when the card is returned, unflag card

		cpAbility->SetMoveCardOption(CTriggeredMoveCardAbility::MoveCardOption::MoveMultipleCards);			   // not specific card -> need to use the search filter below
		CardFlagComparer* pComparer = new CardFlagComparer(CardFlag::AbilityFlag, false);
		pComparer->SetData(m_CardFlagModifier1.GetModifier().GetAdditionData());							   // note: find card flagged by the first trigger
		cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(pComparer);							   // find flagged card
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Exile);										   // in Exile
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Battlefield);									   // to owner's Battlefield
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Exile, ZoneId::Battlefield));

		AddAbility(cpAbility.GetPointer());
	}
}

//___________________________________________________________________________________
//
CAncientCrabCard::CAncientCrabCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ancient Crab"), CardType::Creature, CREATURE_TYPE(Crab), nID,
		_T("1") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(5))
{
}

//____________________________________________________________________________
//
CAlliedReinforcementsCard::CAlliedReinforcementsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Allied Reinforcements"), CardType::Sorcery, nID)
{
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT,
			_T("Knight Ally A"), 55060,
			2));

	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
CImmolatingGlareCard::CImmolatingGlareCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Immolating Glare"), CardType::Instant, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Instant,
		new AttackingCreatureComparer,
		ZoneId::Battlefield, ZoneId::Graveyard, true, MoveType::Destroy)
{
}

//____________________________________________________________________________
//
