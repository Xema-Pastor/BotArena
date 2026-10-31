#include "stdafx.h"
#include "CardEldritchMoon.h"

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
		DEFINE_CARD(CGeierReachSanitariumCard);
		DEFINE_CARD(CHanweirBattlementsCard);
		DEFINE_CARD(CNephaliaAcademyCard);
		DEFINE_CARD(CHanweirGarrisonCard);
		DEFINE_CARD(CHanweirTheWrithingTownshipCard);
		DEFINE_CARD(CLilianaTheLastHopeCard);
		DEFINE_CARD(CAlchemistsGreetingCard);
		DEFINE_CARD(CCemeteryRecruitmentCard);
		DEFINE_CARD(CCertainDeathCard);
		DEFINE_CARD(CContingencyPlanCard);
		DEFINE_CARD(CDarkSalvationCard);
		DEFINE_CARD(CDeployTheGatewatchCard);
		DEFINE_CARD(CDistemperOfTheBloodCard);
		DEFINE_CARD(CDragUnderCard);
		DEFINE_CARD(CEldritchEvolutionCard);
		DEFINE_CARD(CHarmlessOfferingCard);
		DEFINE_CARD(CIncendiaryFlowCard);
		DEFINE_CARD(CIronwrightsCleansingCard);
		DEFINE_CARD(CMakeMischiefCard);
		DEFINE_CARD(CProvidenceCard);
		DEFINE_CARD(CPryingQuestionsCard);
		DEFINE_CARD(CRuthlessDisposalCard);
		DEFINE_CARD(CShredsOfSanityCard);
		DEFINE_CARD(CSpectralReservesCard);
		DEFINE_CARD(CSplendidReclamationCard);
		DEFINE_CARD(CStensiaBanquetCard);
		DEFINE_CARD(CTakeInventoryCard);
		DEFINE_CARD(CWhispersOfEmrakulCard);
		DEFINE_CARD(CAbandonReasonCard);
		DEFINE_CARD(CChillingGraspCard);
		DEFINE_CARD(CClearShotCard);
		DEFINE_CARD(CDisplaceCard);
		DEFINE_CARD(CGalvanicBombardmentCard);
		DEFINE_CARD(CGiveNoGroundCard);
		DEFINE_CARD(CGrappleWithThePastCard);
		DEFINE_CARD(CLongRoadHomeCard);
		DEFINE_CARD(COtherworldlyOutburstCard);
		DEFINE_CARD(CRideDownCard);
		DEFINE_CARD(CScourTheLaboratoryCard);
		DEFINE_CARD(CSpringsageRitualCard);
		DEFINE_CARD(CSuccumbToTemptationCard);
		DEFINE_CARD(CUnsubstantiateCard);
		DEFINE_CARD(CWaxingMoonCard);
		DEFINE_CARD(CWoodcuttersGritCard);
		DEFINE_CARD(CBloodMistCard);
		DEFINE_CARD(CBoonOfEmrakulCard);
		DEFINE_CARD(CCampaignOfVengeanceCard);
		DEFINE_CARD(CChokingRestraintsCard);
		DEFINE_CARD(CCropSigilCard);
		DEFINE_CARD(CEmrakulsInfluenceCard);
		DEFINE_CARD(CFaithUnbrokenCard);
		DEFINE_CARD(CGrafHarvestCard);
		DEFINE_CARD(CLunarchMantleCard);
		DEFINE_CARD(CLunarForceCard);
		DEFINE_CARD(COathOfLilianaCard);
		DEFINE_CARD(CPeaceOfMindCard);
		DEFINE_CARD(CPropheticRavingsCard);
		DEFINE_CARD(CStrangeAugmentationCard);
		DEFINE_CARD(CWolfkinBondCard);
		DEFINE_CARD(CBrunaTheFadingLightCard);
		DEFINE_CARD(CBriselaVoiceOfNightmaresCard);
		DEFINE_CARD(CCourageousOutriderCard);
		DEFINE_CARD(CDawnGryffCard);
		DEFINE_CARD(CDesperateSentryCard);
		DEFINE_CARD(CDrogskolShieldmateCard);
		DEFINE_CARD(CExtricatorOfSinCard);
		DEFINE_CARD(CExtricatorOfFleshCard);
		DEFINE_CARD(CFaithbearerPaladinCard);
		DEFINE_CARD(CFiendBinderCard);
		DEFINE_CARD(CGeistOfTheLonelyVigilCard);
		DEFINE_CARD(CGiselaTheBrokenBladeCard);
		DEFINE_CARD(CGuardianOfPilgrimsCard);
		DEFINE_CARD(CIroncladSlayerCard);
		DEFINE_CARD(CLoneRiderCard);
		DEFINE_CARD(CItThatRidesAsOneCard);
		DEFINE_CARD(CSanctifierOfSoulsCard);
		DEFINE_CARD(CSelflessSpiritCard);
		DEFINE_CARD(CSigardianPriestCard);
		DEFINE_CARD(CSteadfastCatharCard);
		DEFINE_CARD(CSubjugatorAngelCard);
		DEFINE_CARD(CThaliaHereticCatharCard);
		DEFINE_CARD(CThaliasLancersCard);
		DEFINE_CARD(CThrabenStandardBearerCard);
		DEFINE_CARD(CBackwoodsSurvivalistsCard);
		DEFINE_CARD(CBloodbriarCard);
		DEFINE_CARD(CCrossroadsConsecratorCard);
		DEFINE_CARD(CEmrakulsEvangelCard);
		DEFINE_CARD(CFoulEmissaryCard);
		DEFINE_CARD(CGnarlwoodDryadCard);
		DEFINE_CARD(CIshkanahGrafwidowCard);
		DEFINE_CARD(CKessigProwlerCard);
		DEFINE_CARD(CSinuousPredatorCard);
		DEFINE_CARD(CNooseConstrictorCard);
		DEFINE_CARD(CPrimalDruidCard);
		DEFINE_CARD(CSomberwaldStagCard);
		DEFINE_CARD(CSpiritOfTheHuntCard);
		DEFINE_CARD(CSwiftSpinnerCard);
		DEFINE_CARD(CTangleclawWerewolfCard);
		DEFINE_CARD(CFibrousEntanglerCard);
		DEFINE_CARD(CUlvenwaldCaptiveCard);
		DEFINE_CARD(CUlvenwaldAbominationCard);
		DEFINE_CARD(CUlvenwaldObserverCard);
		DEFINE_CARD(CWoodlandPatrolCard);
		DEFINE_CARD(CAssembledAlphasCard);
		DEFINE_CARD(CBedlamRevelerCard);
		DEFINE_CARD(CBoldImpalerCard);
		DEFINE_CARD(CBrazenWolvesCard);
		DEFINE_CARD(CConduitOfStormsCard);
		DEFINE_CARD(CConduitOfEmrakulCard);
		DEFINE_CARD(CDerangedWhelpCard);
		DEFINE_CARD(CFalkenrathReaverCard);
		DEFINE_CARD(CFurybladeVampireCard);
		DEFINE_CARD(CImpetuousDevilsCard);
		DEFINE_CARD(CInsatiableGorgersCard);
		DEFINE_CARD(CSmolderingWerewolfCard);
		DEFINE_CARD(CEruptingDreadwolfCard);
		DEFINE_CARD(CStensiaInnkeeperCard);
		DEFINE_CARD(CThermoAlchemistCard);
		DEFINE_CARD(CVildinPackOutcastCard);
		DEFINE_CARD(CDronepackKindredCard);
		DEFINE_CARD(CWeaverOfLightningCard);
		DEFINE_CARD(CCryptbreakerCard);
		DEFINE_CARD(CDuskFeasterCard);
		DEFINE_CARD(CGavonyUnhallowedCard);
		DEFINE_CARD(CGrafRatsCard);
		DEFINE_CARD(CChitteringHostCard);
		DEFINE_CARD(CHauntedDeadCard);
		DEFINE_CARD(CLilianasEliteCard);
		DEFINE_CARD(CMarkovCrusaderCard);
		DEFINE_CARD(CMidnightScavengersCard);
		DEFINE_CARD(CNoosegrafMobCard);
		DEFINE_CARD(COliviasDragoonCard);
		DEFINE_CARD(CSkirsdagSupplicantCard);
		DEFINE_CARD(CStromkirkCondemnedCard);
		DEFINE_CARD(CThrabenFoulbloodsCard);
		DEFINE_CARD(CVampireCutthroatCard);
		DEFINE_CARD(CVoldarenPariahCard);
		DEFINE_CARD(CAbolisherOfBloodlinesCard);
		DEFINE_CARD(CWailingGhoulCard);
		DEFINE_CARD(CWeirdedVampireCard);
		DEFINE_CARD(CAdvancedStitchwingCard);
		DEFINE_CARD(CDocentOfPerfectionCard);
		DEFINE_CARD(CFinalIterationCard);
		DEFINE_CARD(CEnlightenedManiacCard);
		DEFINE_CARD(CExultantCultistCard);
		DEFINE_CARD(CFogwalkerCard);
		DEFINE_CARD(CGeistOfTheArchivesCard);
		DEFINE_CARD(CGrizzledAnglerCard);
		DEFINE_CARD(CGrislyAnglerfishCard);
		DEFINE_CARD(CIngeniousSkaabCard);
		DEFINE_CARD(CLaboratoryBruteCard);
		DEFINE_CARD(CMausoleumWandererCard);
		DEFINE_CARD(CNebelgastHeraldCard);
		DEFINE_CARD(CNiblisOfFrostCard);
		DEFINE_CARD(CWharfInfiltratorCard);
		DEFINE_CARD(CBloodhallPriestCard);
		DEFINE_CARD(CGrimFlayerCard);
		DEFINE_CARD(CHeronsGraceChampionCard);
		DEFINE_CARD(CMercurialGeistsCard);
		DEFINE_CARD(CMournwillowCard);
		DEFINE_CARD(CUlrichOfTheKrallenhordeCard);
		DEFINE_CARD(CUlrichUncontestedAlphaCard);
		DEFINE_CARD(CAbundantMawCard);
		DEFINE_CARD(CDecimatorOfTheProvincesCard);
		DEFINE_CARD(CDistendedMindbenderCard);
		DEFINE_CARD(CDrownyardBehemothCard);
		DEFINE_CARD(CElderDeepFiendCard);
		DEFINE_CARD(CEternalScourgeCard);
		DEFINE_CARD(CFieldCreeperCard);
		DEFINE_CARD(CGeistFueledScarecrowCard);
		DEFINE_CARD(CItOfTheHorridSwarmCard);
		DEFINE_CARD(CLashweedLurkerCard);
		DEFINE_CARD(CMockeryOfNatureCard);
		DEFINE_CARD(CVexingScuttlerCard);
		DEFINE_CARD(CWretchedGryffCard);
		DEFINE_CARD(CCatharsShieldCard);
		DEFINE_CARD(CCultistsStaffCard);
		DEFINE_CARD(CSlayersCleaverCard);
		DEFINE_CARD(CStitchersGraftCard);
		DEFINE_CARD(CTerrarionCard);
		DEFINE_CARD(CThirstingAxeCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
// Helpers for double-faced and meld cards (as in Shadows over Innistrad)

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

static void SetSecondFaceKeywords(CDoubleFacedCreatureCard* pCard, CreatureKeyword toAdd, CreatureKeyword toRemove)
{
	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(toAdd);
	pModifier->GetModifier().SetToRemove(toRemove);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	pCard->AddCreatureModifier(pModifier);
}

//____________________________________________________________________________
//
// Lands

CGeierReachSanitariumCard::CGeierReachSanitariumCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Geier Reach Sanitarium"), nID, CardType::NonbasicLand | CardType::Legendary)
	, m_cpEventListener(VAR_NAME(m_cpListener), ResolutionCompletedEventSource::Listener::EventCallback(this,
				&CGeierReachSanitariumCard::OnResolutionCompleted))
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, {T}: Each player draws a card, then discards a card. (as Lore Broker in Ravnica)
		counted_ptr<CActivatedAbility<CGlobalDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGlobalDrawCardSpell>>(this,
				_T("2"), 1, 1));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Each player draws a card, then discards a card. Activates"));
		cpAbility->GetResolutionCompletedEventSource()->AddListener(m_cpEventListener.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

void CGeierReachSanitariumCard::OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult)
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

	pModifier.ApplyTo(GetController());
	pModifier.ApplyTo(m_pGame->GetNextPlayer(GetController()));
}

CHanweirBattlementsCard::CHanweirBattlementsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Hanweir Battlements"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {R}, {T}: Target creature gains haste until end of turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				RED_MANA_TEXT,
				Power(+0), Life(+0),
				CreatureKeyword::Haste, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{R}{R}, {T}: If you both own and control this land and a creature named Hanweir Garrison, exile them,
		// then meld them into Hanweir, the Writhing Township.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("3") RED_MANA_TEXT RED_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Meld into Hanweir, the Writhing Township. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHanweirBattlementsCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHanweirBattlementsCard::BeforeResolution(CAbilityAction* pAction)
{
	ExileAndMeld(this, _T("Hanweir Garrison"), pAction->GetController());
	return true;
}

CNephaliaAcademyCard::CNephaliaAcademyCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Nephalia Academy"), nID)
{
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// If a spell or ability an opponent controls causes you to discard a card, you may reveal that card and put it
		// on top of your library instead of putting it anywhere else.
		// Note: the engine has no replacement for discards caused by other cards: this is a trigger that puts the
		// discarded card from your graveyard on top of your library (the card is in the graveyard for a moment).
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Hand, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNephaliaAcademyCard::SetTriggerContext));
		cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CNephaliaAcademyCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNephaliaAcademyCard::SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
											 CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	// A discard caused by an opponent
	if (moveType != MoveType::Discard || !pByPlayer || pByPlayer == GetController() || pCard->GetOwner() != GetController())
		return false;

	triggerContext.m_pCard = pCard;
	return true;
}

bool CNephaliaAcademyCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const
{
	CCard* pCard = pAction->GetTriggerContext().m_pCard;
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return true;

	CPlayer* pOwner = pCard->GetOwner();
	pCard->Move(pOwner->GetZoneById(ZoneId::Library), pOwner, MoveType::Others, CardPlacement::Top);
	return true;
}

CHanweirGarrisonCard::CHanweirGarrisonCard(CGame* pGame, UINT nID)
	: CMeldCreatureCard(pGame, _T("Hanweir Garrison"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3), Power(7), Life(4), _T("Hanweir, the Writhing Township"))
{
	// Hanweir, the Writhing Township: legendary colorless Eldrazi Ooze with trample and haste
	AddCardModifier(new CCardTypeModifier(CardType::Legendary));
	AddCardModifier(new CCardColorModifier(CardType::Null));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Human, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Soldier, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Ooze, TRUE));
	SetSecondFaceKeywords(this, CreatureKeyword::Trample | CreatureKeyword::Haste, CreatureKeyword::Null);

	// Hanweir Garrison: Whenever this creature attacks, create two 1/1 red Human creature tokens that are tapped and attacking.
	// Hanweir, the Writhing Township: Whenever Hanweir attacks, create two 3/2 colorless Eldrazi Horror creature tokens
	// that are tapped and attacking.
	// (as Inexorable Blob in Shadows over Innistrad)
	for (int i = 0; i < 2; ++i)
	{
		typedef
			TTriggeredAbility< CAttackingTokenCreationAbility, CWhenSelfAttackedBlocked,
							   CWhenSelfAttackedBlocked::AttackEventCallback,
							   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetTokenName(i == 0 ? _T("Human (D)") : _T("Eldrazi Horror (A)"));
		cpAbility->SetTokenNumber(2);
		cpAbility->SetTokenuID(i == 0 ? 55086 : 55087);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this,
			i == 0 ? &CHanweirGarrisonCard::SetFrontContext : &CHanweirGarrisonCard::SetMeldedContext));

		AddAbility(cpAbility.GetPointer());
	}
}

bool CHanweirGarrisonCard::SetFrontContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return !GetOrientation()->IsSecondFaced();
}

bool CHanweirGarrisonCard::SetMeldedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return GetOrientation()->IsSecondFaced() ? true : false;
}

// Melded face of Hanweir Garrison and Hanweir Battlements: its abilities are in CHanweirGarrisonCard
CHanweirTheWrithingTownshipCard::CHanweirTheWrithingTownshipCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Hanweir, the Writhing Township"), CardType::_LegendaryCreature, CREATURE_TYPE2(Eldrazi, Ooze), nID,
		_T(""), Power(7), Life(4), Power(2), Life(3), _T("Hanweir Garrison"))
{
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);
}

//____________________________________________________________________________
//
// Planeswalkers

// Mills nCount cards (the top cards of the player's library are put into the graveyard)
static void Mill(CPlayer* pPlayer, int nCount)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);

	for (int i = 0; i < nCount && pLibrary->GetSize() > 0; ++i)
		pModifier.ApplyTo(pLibrary->GetAt(pLibrary->GetSize() - 1));
}

CLilianaTheLastHopeCard::CLilianaTheLastHopeCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Liliana, the Last Hope"), nID,
		_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Liliana, 3)
	, m_CreatureFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
{
	{
		// +1: Up to one target creature gets -2/-1 until your next turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaTheLastHopeCard::BeforeResolution1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Mill two cards, then you may return a creature card from your graveyard to your hand.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianaTheLastHopeCard::BeforeResolution2));
		cpAbility->SetAbilityText(_T("-2: Mill two cards, then you may return a creature card from your graveyard to your hand."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: You get an emblem with "At the beginning of your end step, create X 2/2 black Zombie creature tokens,
		// where X is two plus the number of Zombies you control."
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CTokenCreationModifier(GetGame(), _T("Liliana, the Last Hope Emblem"), 61145, 1, FALSE, ZoneId::_Effects));
		cpAbility->SetAbilityText(_T("-7: You get an emblem with - At the beginning of your end step, create X 2/2 black Zombie creature tokens, where X is two plus the number of Zombies you control."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLilianaTheLastHopeCard::BeforeResolution1(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	// Until your next turn: removed at the beginning of the controller's next untap step
	CPlayer* pController = pAction->GetController();
	CScheduledCreatureModifier pPowerModifier = CScheduledCreatureModifier(GetGame(),
		new CPowerModifier(Power(-2), FALSE),
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pController);
	CScheduledCreatureModifier pLifeModifier = CScheduledCreatureModifier(GetGame(),
		new CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage, FALSE),
		TurnNumberDelta(-1), NodeId::UntapStep, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCreatureModifier::DeltaOption::CustomPlayerTurn, pController);

	pPowerModifier.ApplyTo((CCreatureCard*)pCard);
	pLifeModifier.ApplyTo((CCreatureCard*)pCard);
	return true;
}

bool CLilianaTheLastHopeCard::BeforeResolution2(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	Mill(pController, 2);

	// Then you may return a creature card from your graveyard to your hand
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // select a creature card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		&m_CreatureFilter,						// creature cards
		ZoneId::Hand,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);

	pModifier.ApplyTo(pController);
	return true;
}

//____________________________________________________________________________
//
// Madness (as in Shadows over Innistrad)

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

// Surveil N (as in Guilds of Ravnica): look at the top N cards of your library, put any number of them into your
// graveyard and the rest on top of your library in any order
static void Surveil(CGame* pGame, CPlayer* pPlayer, int nCount)
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

// The player discards a card of their choice (as Lore Broker in Ravnica)
static void DiscardACard(CGame* pGame, CPlayer* pPlayer)
{
	CZoneModifier pModifier = CZoneModifier(pGame,
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
	pModifier.ApplyTo(pPlayer);
}

static int CountControlled(CPlayer* pPlayer, const CardComparer& comparer)
{
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	int nCount = 0;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (comparer(pBattlefield->GetAt(i)))
			++nCount;
	return nCount;
}

// Exile instead of dying this turn (as Reduce to Ashes in Shadows over Innistrad)
static CCardModifier* CreateExileInsteadModifier()
{
	CReplacementKeywordModifier* pModifier = new CReplacementKeywordModifier;
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	pModifier->GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	return pModifier;
}

// Creature card with mana value nMaxManaValue or less
struct CreatureMaxManaValueComparer : public CardComparer
{
	CreatureMaxManaValueComparer(int nMaxManaValue)
		: m_nMaxManaValue(nMaxManaValue)
	{}

	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && (int)pCard->GetConvertedManaCost() <= m_nMaxManaValue;
	}

	virtual CreatureMaxManaValueComparer* Clone() const
	{
		return new CreatureMaxManaValueComparer(m_nMaxManaValue);
	}

protected:
	int m_nMaxManaValue;
};

CAlchemistsGreetingCard::CAlchemistsGreetingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Alchemist's Greeting"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// Alchemist's Greeting deals 4 damage to target creature. Madness {1}{R}
	LPCTSTR costs[] = { _T("4") RED_MANA_TEXT, _T("1") RED_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
				costs[i],
				new AnyCreatureComparer, FALSE,
				Life(-4), PreventableType::Preventable));

		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CCemeteryRecruitmentCard::CCemeteryRecruitmentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cemetery Recruitment"), CardType::Sorcery, nID)
{
	// Return target creature card from your graveyard to your hand. If it's a Zombie card, draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Hand, true, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCemeteryRecruitmentCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CCemeteryRecruitmentCard::BeforeResolution(CAbilityAction* pAction) const
{
	// The card is returned by the spell after this
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard && CreatureTypeComparer(CREATURE_TYPE(Zombie), false)(pCard))
	{
		CDrawCardModifier pModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CCertainDeathCard::CCertainDeathCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Certain Death"), CardType::Sorcery, nID)
{
	// Destroy target creature. Its controller loses 2 life and you gain 2 life.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("5") BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCertainDeathCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CCertainDeathCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pAction->GetController();
	CPlayer* pTargetController = pCard->GetController();

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pController);
	pModifier.ApplyTo(pCard);

	CLifeModifier pLoseModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLoseModifier.ApplyTo(pTargetController);
	CLifeModifier pGainModifier = CLifeModifier(Life(+2), (CCard*)this, PreventableType::NotPreventable);
	pGainModifier.ApplyTo(pController);
	return true;
}

CContingencyPlanCard::CContingencyPlanCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Contingency Plan"), CardType::Sorcery, nID)
{
	// Surveil 5.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CContingencyPlanCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CContingencyPlanCard::BeforeResolution(CAbilityAction* pAction) const
{
	Surveil(GetGame(), pAction->GetController(), 5);
	return true;
}

CDarkSalvationCard::CDarkSalvationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dark Salvation"), CardType::Sorcery, nID)
{
	// Target player creates X 2/2 black Zombie creature tokens, then up to one target creature gets -1/-1 until end
	// of turn for each Zombie that player controls.
	// {X}{X}{B}: X is half of the extra mana paid (as Quarantine Field in Battle for Zendikar)
	{
		// No target creature
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDarkSalvationCard::BeforeResolution1));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Target player and target creature (as Dawn to Dusk in Born of the Gods)
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDarkSalvationCard::BeforeResolution2));
		cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
		AddSpell(cpSpell.GetPointer());
	}
}

void CDarkSalvationCard::Resolve(CAbilityAction* pAction, CPlayer* pPlayer, CCard* pCreature) const
{
	if (!pPlayer)
		return;

	int nX = pAction->GetCostConfigEntry().GetExtraValue();
	if (nX < 0)
		nX = -nX;

	if (nX > 0)
	{
		CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, nX);
		pModifier.ApplyTo(pPlayer);
	}

	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || !pCreature->GetCardType().IsCreature())
		return;

	int nZombies = CountControlled(pPlayer, CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	if (nZombies <= 0)
		return;

	CPowerModifier pPowerModifier = CPowerModifier(Power(-nZombies));
	pPowerModifier.ApplyTo((CCreatureCard*)pCreature);
	CLifeModifier pLifeModifier = CLifeModifier(Life(-nZombies), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo((CCreatureCard*)pCreature);
}

bool CDarkSalvationCard::BeforeResolution1(CAbilityAction* pAction) const
{
	Resolve(pAction, pAction->GetAssociatedPlayer(), NULL);
	return true;
}

bool CDarkSalvationCard::BeforeResolution2(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CPlayer* pPlayer = (CPlayer*)pDoubleTargetAction->GetTargetGroup1().GetFirstPlayerSubject();
	CCard* pCreature = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	Resolve(pAction, pPlayer, pCreature);
	return true;
}

CDeployTheGatewatchCard::CDeployTheGatewatchCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Deploy the Gatewatch"), CardType::Sorcery, nID)
	, m_CardFilter(_T("a planeswalker card"), _T("planeswalker cards"), new CardTypeComparer(CardType::Planeswalker, false))
{
	// Look at the top seven cards of your library. Put up to two planeswalker cards from among them onto the
	// battlefield. Put the rest on the bottom of your library in a random order.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeployTheGatewatchCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDeployTheGatewatchCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Oath of Nissa in Oath of the Gatewatch)
	// Note: the player orders the rest of the cards instead of a random order
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(7), MaximumValue(7));
		pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
		pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
		pModifier->GetSelection(0).moveType = MoveType::Others;
		pModifier->AddSelection(MinimumValue(0), MaximumValue(2), // select up to two planeswalker cards
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::AllPlayers,	// reveal to
			&m_CardFilter,							// planeswalker cards
			ZoneId::Battlefield,					// if selected, move cards to
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

CDistemperOfTheBloodCard::CDistemperOfTheBloodCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Distemper of the Blood"), CardType::Sorcery, nID)
	, m_Madness(this)
{
	// Target creature gets +2/+2 and gains trample until end of turn. Madness {R}
	LPCTSTR costs[] = { _T("1") RED_MANA_TEXT, RED_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
				costs[i],
				Power(+2), Life(+2),
				CreatureKeyword::Trample, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CDragUnderCard::CDragUnderCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Drag Under"), CardType::Sorcery, nID)
{
	// Return target creature to its owner's hand. Draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLUE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1)));
	AddSpell(cpSpell.GetPointer());
}

CEldritchEvolutionCard::CEldritchEvolutionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Eldritch Evolution"), CardType::Sorcery, nID)
	, m_CardFilter(_T("a creature card"), _T("creature cards"), new CreatureMaxManaValueComparer(2))
{
	// As an additional cost to cast this spell, sacrifice a creature.
	// Search your library for a creature card with mana value X or less, where X is 2 plus the sacrificed creature's
	// mana value. Put that card onto the battlefield, then shuffle. Exile Eldritch Evolution.
	// (the filter is set from the sacrificed creature, as Mind Extraction in Apocalypse)
	counted_ptr<CSearchLibrarySpell> cpSpell(
		::CreateObject<CSearchLibrarySpell>(this, AbilityType::Sorcery,
			_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT,
			&m_CardFilter,
			ZoneId::Battlefield, TRUE, FALSE, FALSE));

	cpSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEldritchEvolutionCard::BeforeResolution));
	cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
	AddSpell(cpSpell.GetPointer());
}

bool CEldritchEvolutionCard::BeforeResolution(CAbilityAction* pAction)
{
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	int nManaValue = (pSacrificed && pSacrificed->GetSize()) ? (int)pSacrificed->GetAt(0)->GetConvertedManaCost() : 0;

	m_CardFilter.SetComparer(new CreatureMaxManaValueComparer(2 + nManaValue));
	return true;
}

CHarmlessOfferingCard::CHarmlessOfferingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Harmless Offering"), CardType::Sorcery, nID)
{
	// Target opponent gains control of target permanent you control. (as Donate in Urza's Destiny)
	counted_ptr<CDonateSpell> cpSpell(
		::CreateObject<CDonateSpell>(this, AbilityType::Sorcery,
			_T("2") RED_MANA_TEXT));

	cpSpell->GetTargeting2()->SetIncludeOpponentPlayersOnly();
	AddSpell(cpSpell.GetPointer());
}

CIncendiaryFlowCard::CIncendiaryFlowCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Incendiary Flow"), CardType::Sorcery, nID)
{
	// Incendiary Flow deals 3 damage to any target. If a creature dealt damage this way would die this turn,
	// exile it instead.
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-3), PreventableType::Preventable));

	cpSpell->GetTargetModifier().CCardModifiers::push_back(CreateExileInsteadModifier());
	AddSpell(cpSpell.GetPointer());
}

CIronwrightsCleansingCard::CIronwrightsCleansingCard(CGame* pGame, UINT nID)
	: CTargetMoveCardSpellCard(pGame, _T("Ironwright's Cleansing"), CardType::Sorcery, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Sorcery,
		new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
		ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others)
{
	// Exile target artifact or enchantment.
	m_pTargetMoveCardSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CMakeMischiefCard::CMakeMischiefCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Make Mischief"), CardType::Sorcery, nID)
{
	// Make Mischief deals 1 damage to any target. Create a 1/1 red Devil creature token. It has "When this token
	// dies, it deals 1 damage to any target."
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-1), PreventableType::Preventable));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Devil (A)"), 55079, 1));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	AddSpell(cpSpell.GetPointer());
}

CProvidenceCard::CProvidenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Providence"), CardType::Sorcery, nID)
{
	// Your life total becomes 26.
	// Note: revealing it from the opening hand is not implemented (the engine has no opening hand actions)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CProvidenceCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CProvidenceCard::BeforeResolution(CAbilityAction* pAction) const
{
	// The player gains or loses the difference
	CPlayer* pController = pAction->GetController();
	int nDelta = 26 - GET_INTEGER(pController->GetLife());
	if (nDelta == 0)
		return true;

	CLifeModifier pModifier = CLifeModifier(Life(nDelta), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pController);
	return true;
}

CPryingQuestionsCard::CPryingQuestionsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Prying Questions"), CardType::Sorcery, nID)
{
	// Target opponent loses 3 life and puts a card from their hand on top of their library.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPryingQuestionsCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	AddSpell(cpSpell.GetPointer());
}

bool CPryingQuestionsCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CLifeModifier pLifeModifier = CLifeModifier(Life(-3), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pOpponent);

	CZoneModifier pModifier = CZoneModifier(GetGame(),
		ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select a card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Library, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pOpponent);
	return true;
}

CRuthlessDisposalCard::CRuthlessDisposalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ruthless Disposal"), CardType::Sorcery, nID)
{
	// As an additional cost to cast this spell, discard a card and sacrifice a creature.
	// Two target creatures each get -13/-13 until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Sorcery,
			_T("4") BLACK_MANA_TEXT,
			Power(-13), Life(-13),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetSubjectCount(2, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpSpell->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	AddSpell(cpSpell.GetPointer());
}

CShredsOfSanityCard::CShredsOfSanityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Shreds of Sanity"), CardType::Sorcery, nID)
{
	// Return up to one target instant card and up to one target sorcery card from your graveyard to your hand,
	// then discard a card. Exile Shreds of Sanity.
	// (one spell for each choice of targets, as Dawn to Dusk in Born of the Gods; it can't be cast without targets)
	CardType types[] = { CardType::Instant, CardType::Sorcery };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT,
				new CardTypeComparer(types[i], false), FALSE));

		cpSpell->GetTargeting()->SetSubjectZoneId(ZoneId::Graveyard);
		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShredsOfSanityCard::BeforeResolution1));
		cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT,
				new CardTypeComparer(CardType::Instant, false), FALSE,
				new CardTypeComparer(CardType::Sorcery, false), FALSE, _T("")));

		cpSpell->GetTargeting1()->SetSubjectZoneId(ZoneId::Graveyard);
		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetSubjectZoneId(ZoneId::Graveyard);
		cpSpell->GetTargeting2()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShredsOfSanityCard::BeforeResolution2));
		cpSpell->SetToZoneIfSuccess(ZoneId::Exile, TRUE);
		AddSpell(cpSpell.GetPointer());
	}
}

void CShredsOfSanityCard::ReturnAndDiscard(CPlayer* pController, CCard* pCard1, CCard* pCard2) const
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pController);
	if (pCard1 && pCard1->GetZoneId() == ZoneId::Graveyard)
		pModifier.ApplyTo(pCard1);
	if (pCard2 && pCard2->GetZoneId() == ZoneId::Graveyard)
		pModifier.ApplyTo(pCard2);

	DiscardACard(GetGame(), pController);
}

bool CShredsOfSanityCard::BeforeResolution1(CAbilityAction* pAction) const
{
	ReturnAndDiscard(pAction->GetController(), pAction->GetAssociatedCard(), NULL);
	return true;
}

bool CShredsOfSanityCard::BeforeResolution2(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	ReturnAndDiscard(pAction->GetController(),
		(CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject(),
		(CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject());
	return true;
}

CSpectralReservesCard::CSpectralReservesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Spectral Reserves"), CardType::Sorcery, nID)
{
	// Create two 1/1 white Spirit creature tokens with flying. You gain 2 life.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT,
			_T("Spirit (S)"), 55076,
			2));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+2), this, PreventableType::NotPreventable));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

CSplendidReclamationCard::CSplendidReclamationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Splendid Reclamation"), CardType::Sorcery, nID)
{
	// Return all land cards from your graveyard to the battlefield tapped.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSplendidReclamationCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSplendidReclamationCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	CCountedCardContainer lands;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetCardType().IsLand())
			lands.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

	// Tapped as the tokens of Drana's Chosen in Oath of the Gatewatch
	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	for (int i = 0; i < lands.GetSize(); ++i)
	{
		CCard* pLand = lands.GetAt(i);
		pLand->Move(pController->GetZoneById(ZoneId::Battlefield), pController, MoveType::Others);
		if (pLand->GetZoneId() == ZoneId::Battlefield)
			pTapModifier.ApplyTo(pLand);
	}
	return true;
}

CStensiaBanquetCard::CStensiaBanquetCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Stensia Banquet"), CardType::Sorcery, nID)
{
	// Stensia Banquet deals damage to target opponent or planeswalker equal to the number of Vampires you control.
	// Draw a card.
	// Note: only opponents can be targeted (not planeswalkers)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") RED_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStensiaBanquetCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CStensiaBanquetCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();

	int nVampires = CountControlled(pController, CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	if (pOpponent && nVampires > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nVampires), (CCard*)this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pOpponent);
	}

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
	pDrawModifier.ApplyTo(pController);
	return true;
}

CTakeInventoryCard::CTakeInventoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Take Inventory"), CardType::Sorcery, nID)
{
	// Draw a card, then draw cards equal to the number of cards named Take Inventory in your graveyard.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTakeInventoryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTakeInventoryCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	CDrawCardModifier pModifier = CDrawCardModifier(GetGame(), MinimumValue(1), MaximumValue(1));
	pModifier.ApplyTo(pController);

	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	int nCount = 0;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetCardName(FALSE) == _T("Take Inventory"))
			++nCount;

	if (nCount > 0)
	{
		CDrawCardModifier pMoreModifier = CDrawCardModifier(GetGame(), MinimumValue(nCount), MaximumValue(nCount));
		pMoreModifier.ApplyTo(pController);
	}
	return true;
}

CWhispersOfEmrakulCard::CWhispersOfEmrakulCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Whispers of Emrakul"), CardType::Sorcery, nID)
{
	// Target opponent discards a card at random.
	// Delirium - If there are four or more card types among cards in your graveyard, that player discards two cards
	// at random instead.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWhispersOfEmrakulCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWhispersOfEmrakulCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CRandomDiscardModifier pModifier = CRandomDiscardModifier(HasDelirium(pAction->GetController()) ? 2 : 1);
	pModifier.ApplyTo(pOpponent);
	return true;
}

//____________________________________________________________________________
//
// Instants

// "Can block any number of creatures": removed from the creature with the scheduled modifier that applies it
class CCanBlockAnyNumberModifier : public CCreatureModifier
{
public:
	enum { AnyNumberOfBlocks = 99 };

	virtual void ApplyTo(CCreatureCard* pCreature) const
	{
		CCreatureModifier::ApplyTo(pCreature);
		pCreature->SetMaxBlockingCount(pCreature->GetMaxBlockingCount() + AnyNumberOfBlocks);
	}

	virtual void RemoveFrom(CCreatureCard* pCreature) const
	{
		pCreature->SetMaxBlockingCount(pCreature->GetMaxBlockingCount() - AnyNumberOfBlocks);
		CCreatureModifier::RemoveFrom(pCreature);
	}

	virtual CCreatureModifier* CloneCreatureModifier() const
	{
		return new CCanBlockAnyNumberModifier(*this);
	}
};

CAbandonReasonCard::CAbandonReasonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Abandon Reason"), CardType::Instant, nID)
	, m_Madness(this)
{
	// Up to two target creatures each get +1/+0 and gain first strike until end of turn. Madness {1}{R}
	LPCTSTR costs[] = { _T("2") RED_MANA_TEXT, _T("1") RED_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
				costs[i],
				Power(+1), Life(+0),
				CreatureKeyword::FirstStrike, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpSpell->GetTargeting()->SetSubjectCount(0, 2);
		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CChillingGraspCard::CChillingGraspCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chilling Grasp"), CardType::Instant, nID)
	, m_Madness(this)
{
	// Tap up to two target creatures. Those creatures don't untap during their controller's next untap step.
	// Madness {3}{U} (as Frost Breath in M12)
	LPCTSTR costs[] = { _T("2") BLUE_MANA_TEXT, _T("3") BLUE_MANA_TEXT };
	CSpell* pSpells[2];

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CTargetTapUntapCardSpell> cpSpell(
			::CreateObject<CTargetTapUntapCardSpell>(this, AbilityType::Instant,
				costs[i],
				TRUE, FALSE,	// Tap, Untap
				new CardTypeComparer(CardType::Creature, false)));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargeting()->SetSubjectCount(0, 2);

		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

		AddSpell(cpSpell.GetPointer());
		pSpells[i] = cpSpell.GetPointer();
	}

	m_Madness.SetMadnessSpell(pSpells[1]);
}

CClearShotCard::CClearShotCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Clear Shot"), CardType::Instant, nID)
{
	// Target creature you control gets +1/+1 until end of turn. It deals damage equal to its power to target creature
	// you don't control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CClearShotCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CClearShotCard::BeforeResolution(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pSource = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pTarget = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (!pSource || pSource->GetZoneId() != ZoneId::Battlefield || !pSource->GetCardType().IsCreature())
		return true;

	CCreatureCard* pCreature = (CCreatureCard*)pSource;
	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	pPowerModifier.ApplyTo(pCreature);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pCreature);

	// (the damage as in the fight cards of Shadows over Innistrad)
	int nPower = GET_INTEGER(pCreature->GetPower());
	if (nPower > 0 && pTarget && pTarget->GetZoneId() == ZoneId::Battlefield && pTarget->GetCardType().IsCreature())
	{
		CLifeModifier pDamageModifier = CLifeModifier(Life(-nPower), pCreature, PreventableType::Preventable, DamageType::NonCombatDamage);
		pDamageModifier.ApplyTo((CCreatureCard*)pTarget);
	}
	return true;
}

CDisplaceCard::CDisplaceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Displace"), CardType::Instant, nID)
{
	// Exile up to two target creatures you control, then return those cards to the battlefield under their owner's control.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDisplaceCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDisplaceCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (the targets as in Dead Ringers in Apocalypse)
	CTargetActionCommon* pTargetAction = dynamic_cast<CTargetActionCommon*>(pAction);
	if (!pTargetAction)
		return true;

	CCountedCardContainer targets;
	pTargetAction->GetTargetGroup().GetCardSubjects(targets);

	CPlayer* pController = pAction->GetController();
	CCountedCardContainer exiled;
	for (int i = 0; i < targets.GetSize(); ++i)
	{
		CCard* pCard = targets.GetAt(i);
		if (pCard->GetZoneId() != ZoneId::Battlefield)
			continue;

		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Exile), pController, MoveType::Others);
		if (pCard->GetZoneId() == ZoneId::Exile && !pCard->GetCardType().IsToken())	// an exiled token ceases to exist
			exiled.AddCard(pCard, CardPlacement::Top);
	}

	for (int i = 0; i < exiled.GetSize(); ++i)
	{
		CCard* pCard = exiled.GetAt(i);
		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Battlefield), pCard->GetOwner(), MoveType::Others);
	}
	return true;
}

CGalvanicBombardmentCard::CGalvanicBombardmentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Galvanic Bombardment"), CardType::Instant, nID)
{
	// Galvanic Bombardment deals X damage to target creature, where X is 2 plus the number of cards named
	// Galvanic Bombardment in your graveyard.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGalvanicBombardmentCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CGalvanicBombardmentCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	CZone* pGraveyard = pAction->GetController()->GetZoneById(ZoneId::Graveyard);
	int nDamage = 2;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
		if (pGraveyard->GetAt(i)->GetCardName(FALSE) == _T("Galvanic Bombardment"))
			++nDamage;

	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), (CCard*)this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo((CCreatureCard*)pCard);
	return true;
}

CGiveNoGroundCard::CGiveNoGroundCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Give No Ground"), CardType::Instant, nID)
{
	// Target creature gets +2/+6 until end of turn and can block any number of creatures this turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("3") WHITE_MANA_TEXT,
			Power(+2), Life(+6),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGiveNoGroundCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGiveNoGroundCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	// Until the cleanup step
	CScheduledCreatureModifier pModifier = CScheduledCreatureModifier(GetGame(),
		new CCanBlockAnyNumberModifier,
		TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCreatureModifier::Operation::ApplyToNowRemoveLater);
	pModifier.ApplyTo((CCreatureCard*)pCard);
	return true;
}

CGrappleWithThePastCard::CGrappleWithThePastCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grapple with the Past"), CardType::Instant, nID)
	, m_CardFilter(_T("a creature or land card"), _T("creature or land cards"), new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	// Mill three cards, then you may return a creature or land card from your graveyard to your hand.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrappleWithThePastCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGrappleWithThePastCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Liliana, the Last Hope)
	CPlayer* pController = pAction->GetController();
	Mill(pController, 3);

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // select a creature or land card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		&m_CardFilter,							// creature or land cards
		ZoneId::Hand,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);

	pModifier.ApplyTo(pController);
	return true;
}

CLongRoadHomeCard::CLongRoadHomeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Long Road Home"), CardType::Instant, nID)
{
	// Exile target creature. At the beginning of the next end step, return that card to the battlefield under its
	// owner's control with a +1/+1 counter on it.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLongRoadHomeCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CLongRoadHomeCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Exile), pAction->GetController(), MoveType::Others);
	if (pCard->GetZoneId() != ZoneId::Exile || pCard->GetCardType().IsToken())	// an exiled token ceases to exist
		return true;

	// The counter is put when the card returns from exile (as Dodecapod in Apocalypse)
	pCard->GetCounterContainer()->ScheduleCounter(_T("+1/+1"), 1, false, ZoneId::Exile, ZoneId::Battlefield, false);

	// Returned at the beginning of the next end step (only if it's still in exile)
	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
		new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others),
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
	return true;
}

COtherworldlyOutburstCard::COtherworldlyOutburstCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Otherworldly Outburst"), CardType::Instant, nID)
{
	// Target creature gets +1/+0 until end of turn. When that creature dies this turn, create a 3/2 colorless
	// Eldrazi Horror creature token. (the delayed trigger is the Otherworldly Outburst Effect)
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			Power(+1), Life(+0),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COtherworldlyOutburstCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	AddSpell(cpSpell.GetPointer());
}

bool COtherworldlyOutburstCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCountedCardContainer subjects;
	subjects.AddCard(pCard, CardPlacement::Top);

	CContainerEffectModifier pModifier = CContainerEffectModifier(GetGame(), _T("Otherworldly Outburst Effect"), 61146, &subjects);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CRideDownCard::CRideDownCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ride Down"), CardType::Instant, nID)
{
	// Destroy target blocking creature. Creatures that were blocked by that creature this combat gain trample until
	// end of turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT WHITE_MANA_TEXT,
			new BlockingCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRideDownCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRideDownCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || !pCard->GetCardType().IsCreature())
		return true;

	// The blocked creatures, before the blocker is destroyed
	CCountedCardContainer blocked;
	const CCountedCardContainer_& blocking = ((CCreatureCard*)pCard)->GetBlocking();
	for (int i = 0; i < blocking.GetSize(); ++i)
		blocked.AddCard(blocking.GetAt(i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
	pModifier.ApplyTo(pCard);

	CCreatureKeywordModifier pTrampleModifier;
	pTrampleModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pTrampleModifier.GetModifier().SetOneTurnOnly(TRUE);
	for (int i = 0; i < blocked.GetSize(); ++i)
		if (blocked.GetAt(i)->GetZoneId() == ZoneId::Battlefield && blocked.GetAt(i)->GetCardType().IsCreature())
			pTrampleModifier.ApplyTo((CCreatureCard*)blocked.GetAt(i));
	return true;
}

CScourTheLaboratoryCard::CScourTheLaboratoryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Scour the Laboratory"), CardType::Instant, nID)
{
	// Delirium - This spell costs {2} less to cast if there are four or more card types among cards in your graveyard.
	// Draw three cards.
	// (the reduced cost is a second spell, castable only with delirium)
	LPCTSTR costs[] = { _T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, _T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT };

	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CDrawCardSpell> cpSpell(
			::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
				costs[i], 3));

		if (i == 1)
		{
			cpSpell->SetMainSpell(FALSE);
			cpSpell->SetAbilityText(_T("Delirium - Casts for {2}{U}{U}"));
			counted_ptr<CPlayableIfTrait> cpTrait(
				::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
					CPlayableIfTrait::PlayableCallback(this, &CScourTheLaboratoryCard::CanCastWithDelirium)));
			cpSpell->Add(cpTrait.GetPointer());
		}
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CScourTheLaboratoryCard::CanCastWithDelirium(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

CSpringsageRitualCard::CSpringsageRitualCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Springsage Ritual"), CardType::Instant, nID)
{
	// Destroy target artifact or enchantment. You gain 4 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("3") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+4), this, PreventableType::NotPreventable));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

CSuccumbToTemptationCard::CSuccumbToTemptationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Succumb to Temptation"), CardType::Instant, nID)
{
	// You draw two cards and you lose 2 life.
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT, 2));

	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	AddSpell(cpSpell.GetPointer());
}

CUnsubstantiateCard::CUnsubstantiateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unsubstantiate"), CardType::Instant, nID)
{
	// Return target spell or creature to its owner's hand.
	{
		// Spell (as Remand in Ravnica)
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT,
				new TrueCardComparer));

		cpSpell->SetToZone(ZoneId::Hand, TRUE);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Creature
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
	}
}

CWaxingMoonCard::CWaxingMoonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Waxing Moon"), CardType::Instant, nID)
{
	// Transform up to one target Werewolf you control. Creatures you control gain trample until end of turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new CreatureTypeComparer(CREATURE_TYPE(Werewolf), false), FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetSubjectCount(0, 1);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWaxingMoonCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWaxingMoonCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CFaceTransformModifier pModifier;
		pModifier.ApplyTo(pCard);
	}

	CCreatureKeywordModifier pTrampleModifier;
	pTrampleModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pTrampleModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pTrampleModifier.ApplyTo((CCreatureCard*)pBattlefield->GetAt(i));
	return true;
}

CWoodcuttersGritCard::CWoodcuttersGritCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Woodcutter's Grit"), CardType::Instant, nID)
{
	// Target creature you control gets +3/+3 and gains hexproof until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT,
			Power(+3), Life(+3),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::Hexproof);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

	AddSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
// Enchantments

CBloodMistCard::CBloodMistCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Blood Mist"), CardType::GlobalEnchantment, nID,
		_T("3") RED_MANA_TEXT, AbilityType::Enchantment)
{
	// At the beginning of combat on your turn, target creature you control gains double strike until end of turn.
	// (as Always Watching in Shadows over Innistrad)
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::DoubleStrike);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CBoonOfEmrakulCard::CBoonOfEmrakulCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Boon of Emrakul"), nID,
		_T("2") BLACK_MANA_TEXT,
		Power(+3), Life(-3), CreatureKeyword::Null)
{
	// Enchanted creature gets +3/-3.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
}

CCampaignOfVengeanceCard::CCampaignOfVengeanceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Campaign of Vengeance"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever a creature you control attacks, defending player loses 1 life and you gain 1 life.
	// Note: the defending player is the next player (two-player games)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCampaignOfVengeanceCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);

	AddAbility(cpAbility.GetPointer());
}

bool CCampaignOfVengeanceCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();

	CLifeModifier pLoseModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLoseModifier.ApplyTo(GetGame()->GetNextPlayer(pController));
	CLifeModifier pGainModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable);
	pGainModifier.ApplyTo(pController);
	return true;
}

CChokingRestraintsCard::CChokingRestraintsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Choking Restraints"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
	, m_pLastEnchantedCard(NULL)
{
	// Enchanted creature can't attack or block.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// {3}{W}{W}, Sacrifice this Aura: Exile enchanted creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Exile enchanted creature. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChokingRestraintsCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
	AddAbility(cpAbility.GetPointer());
}

void CChokingRestraintsCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	if (GetZoneId() == ZoneId::Battlefield && pToZone->GetZoneId() != ZoneId::Battlefield)
		m_pLastEnchantedCard = GetEnchantedOn();

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);
}

bool CChokingRestraintsCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = m_pLastEnchantedCard;
	m_pLastEnchantedCard = NULL;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(pCard);
	return true;
}

CCropSigilCard::CCropSigilCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Crop Sigil"), CardType::GlobalEnchantment, nID,
		GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// At the beginning of your upkeep, you may mill a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCropSigilCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}

	// Delirium - {2}{G}, Sacrifice this enchantment: Return up to one target creature card and up to one target land
	// card from your graveyard to your hand. Activate only if there are four or more card types among cards in your
	// graveyard.
	// (one ability for each choice of targets, as Shreds of Sanity; it can't be activated without targets)
	CardType types[] = { CardType::Creature, CardType::_Land };
	for (int i = 0; i < 2; ++i)
	{
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("2") GREEN_MANA_TEXT,
				new CardTypeComparer(types[i], false),
				ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

		cpAbility->AddSacrificeCost();
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CCropSigilCard::CanActivate)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
	{
		counted_ptr<CActivatedAbility<CDoubleTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDoubleTargetSpell>>(this,
				_T("2") GREEN_MANA_TEXT,
				new CardTypeComparer(CardType::Creature, false), FALSE,
				new CardTypeComparer(CardType::_Land, false), FALSE, _T("")));

		cpAbility->AddSacrificeCost();
		cpAbility->GetTargeting1()->SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargeting2()->SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting2()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCropSigilCard::BeforeResolutionBoth));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CCropSigilCard::CanActivate)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCropSigilCard::BeforeMill(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 1);
	return true;
}

BOOL CCropSigilCard::CanActivate(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

bool CCropSigilCard::BeforeResolutionBoth(CAbilityAction* pAction) const
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

CEmrakulsInfluenceCard::CEmrakulsInfluenceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Emrakul's Influence"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast an Eldrazi creature spell with mana value 7 or greater, draw two cards.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Eldrazi), false));
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new ConvertedManaCostComparer<std::greater_equal<int>>(7));
	cpAbility->SetDrawCount(2);

	AddAbility(cpAbility.GetPointer());
}

CFaithUnbrokenCard::CFaithUnbrokenCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Faith Unbroken"), nID,
		_T("3") WHITE_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::Null)
{
	// Enchant creature you control. Enchanted creature gets +2/+2.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetIncludeControllerCardsOnly();

	{
		// When this Aura enters, exile target creature an opponent controls until this Aura leaves the battlefield.
		// (as Stasis Snare in Battle for Zendikar)
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
		// When this Aura leaves the battlefield, return the exiled card to the battlefield under its owner's control.
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

CGrafHarvestCard::CGrafHarvestCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Graf Harvest"), CardType::GlobalEnchantment, nID,
		BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Zombies you control have menace.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Zombie), false),
				Power(+0), Life(+0), CreatureKeyword::CantBeBlockedBy1));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {3}{B}, Exile a creature card from your graveyard: Create a 2/2 black Zombie creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("3") BLACK_MANA_TEXT,
				_T("Zombie (P)"), 55009,
				1));

		cpAbility->GetCost().AddExileGraveyardCardCost(1, CCardFilter::GetFilter(_T("creatures")));
		AddAbility(cpAbility.GetPointer());
	}
}

CLunarchMantleCard::CLunarchMantleCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Lunarch Mantle"), nID,
		_T("1") WHITE_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::Null)
	, m_PermanentFilter(_T("a permanent"), _T("permanents"), new CardTypeComparer(CardType::_Permanent, false))
{
	// Enchanted creature gets +2/+2 and has "{1}, Sacrifice a permanent: This creature gains flying until end of turn."
	// (the ability is added as in Karametra's Favor in Born of the Gods)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().LinkCardModifier(
		new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CLunarchMantleCard::CreateFlyingAbility)));
}

counted_ptr<CAbility> CLunarchMantleCard::CreateFlyingAbility(CCard* pCard)
{
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(pCard, _T("1"), Power(+0), Life(+0), CreatureKeyword::Flying));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_PermanentFilter);
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CLunarForceCard::CLunarForceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Lunar Force"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// When an opponent casts a spell, sacrifice this enchantment and counter that spell.
	// (as the Jace, Unraveler of Secrets emblem)
	typedef
		TTriggeredAbility< CTriggeredCounterSpellAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorOpponentsOnly(true);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLunarForceCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLunarForceCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::Counterspell);

	AddAbility(cpAbility.GetPointer());
}

bool CLunarForceCard::SetTriggerContext(CTriggeredCounterSpellAbility::TriggerContextType& triggerContext, CCard* pCard) const
{
	triggerContext.m_pCard = pCard;
	return true;
}

bool CLunarForceCard::BeforeResolution(CAbilityAction* pAction)
{
	// Sacrifice this enchantment (the spell is countered by the ability)
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, GetController());
		pModifier.ApplyTo(this);
	}
	return true;
}

COathOfLilianaCard::COathOfLilianaCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Liliana"), CardType::_LegendaryGlobalEnchantment, nID,
		_T("2") BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &COathOfLilianaCard::OnCardSelected))
	, m_nPlaneswalkerTurn(-1)
{
	{
		// When Oath of Liliana enters, each opponent sacrifices a creature of their choice.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COathOfLilianaCard::BeforeSacrifice));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// (a planeswalker entering the battlefield under your control is remembered for the end step)
		// Note: only planeswalkers that enter while Oath of Liliana is on the battlefield are seen
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COathOfLilianaCard::SetPlaneswalkerContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each end step, if a planeswalker entered the battlefield under your control this turn,
		// create a 2/2 black Zombie creature token.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &COathOfLilianaCard::SetEndStepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COathOfLilianaCard::BeforeZombie));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool COathOfLilianaCard::BeforeSacrifice(CAbilityAction* pAction)
{
	// (as Clip Wings in Shadows over Innistrad)
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
			if (!pCard->GetCardType().IsCreature())
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

void COathOfLilianaCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
			pModifier.ApplyTo((CCard*)it->dwContext);
			return;
		}
}

bool COathOfLilianaCard::SetPlaneswalkerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
												CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (GetZoneId() == ZoneId::Battlefield && pCard->GetCardType().IsPlaneswalker())
		m_nPlaneswalkerTurn = GetGame()->GetGameTurnNumber();
	return false;	// nothing goes on the stack
}

bool COathOfLilianaCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return m_nPlaneswalkerTurn == GetGame()->GetGameTurnNumber();
}

bool COathOfLilianaCard::BeforeZombie(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CPeaceOfMindCard::CPeaceOfMindCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Peace of Mind"), CardType::GlobalEnchantment, nID,
		_T("1") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// {W}, Discard a card: You gain 3 life.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			WHITE_MANA_TEXT));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+3), this, PreventableType::NotPreventable));
	cpAbility->SetAbilityText(_T("You gain 3 life. Activates"));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CPropheticRavingsCard::CPropheticRavingsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Prophetic Ravings"), nID,
		RED_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::Haste)
{
	// Enchanted creature has haste and "{T}, Discard a card: Draw a card."
	// (the ability is added as in Karametra's Favor in Born of the Gods)
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().LinkCardModifier(
		new CCardAbilityModifier(CCardAbilityModifier::CreateAbilityCallback(this, &CPropheticRavingsCard::CreateLootAbility)));
}

counted_ptr<CAbility> CPropheticRavingsCard::CreateLootAbility(CCard* pCard)
{
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(pCard,
			_T(""), 1));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

CStrangeAugmentationCard::CStrangeAugmentationCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Strange Augmentation"), nID,
		BLACK_MANA_TEXT,
		Power(+1), Life(+1), CreatureKeyword::Null)
{
	// Enchanted creature gets +1/+1.
	// Delirium - Enchanted creature gets an additional +2/+2 as long as there are four or more card types among cards
	// in your graveyard.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new EnchantedByComparer(this),
			Power(+2), Life(+2)));

	SetDeliriumCondition(cpAbility.GetPointer());
	AddAbility(cpAbility.GetPointer());
}

CWolfkinBondCard::CWolfkinBondCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Wolfkin Bond"), nID,
		_T("4") GREEN_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::Null)
{
	// When this Aura enters, create a 2/2 green Wolf creature token. Enchanted creature gets +2/+2.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Wolf (L)"), 55082, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// White creatures

// Delirium bonus of a creature (as in Shadows over Innistrad)
static void AddDeliriumBonus(CCreatureCard* pCard, Power nPower, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			nPower, Life(+0), keyword));

	SetDeliriumCondition(cpAbility.GetPointer());
	pCard->AddAbility(cpAbility.GetPointer());
}

// A card keyword of the second face
static void SetSecondFaceCardKeyword(CDoubleFacedCreatureCard* pCard, CardKeyword toAdd)
{
	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(toAdd);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	pCard->AddCardModifier(pModifier);
}

// The second face is a colorless Eldrazi Horror (removes the creature types of the first face)
static void SetEldraziHorrorSecondFace(CDoubleFacedCreatureCard* pCard, SingleCreatureType type1, SingleCreatureType type2)
{
	pCard->AddCardModifier(new CCardColorModifier(CardType::Null));
	pCard->AddCreatureModifier(new CCreatureTypeModifier(type1, FALSE));
	pCard->AddCreatureModifier(new CCreatureTypeModifier(type2, FALSE));
	pCard->AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));
	pCard->AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, TRUE));
}

// Creature or nonbasic land (Thalia, Heretic Cathar)
struct CreatureOrNonbasicLandComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() || (pCard->GetCardType() & CardType::NonbasicLand).Any();
	}

	virtual CreatureOrNonbasicLandComparer* Clone() const
	{
		return new CreatureOrNonbasicLandComparer;
	}
};

CBrunaTheFadingLightCard::CBrunaTheFadingLightCard(CGame* pGame, UINT nID)
	: CMeldCreatureCard(pGame, _T("Bruna, the Fading Light"), CardType::_LegendaryCreature, CREATURE_TYPE2(Angel, Horror), nID,
		_T("5") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(7), Power(9), Life(10), _T("Brisela, Voice of Nightmares"))
	, m_SpellFilter(_T("a spell with mana value 3 or less"), _T("spells with mana value 3 or less"),
		new ConvertedManaCostComparer<std::less_equal<int>>(3))
{
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Brisela, Voice of Nightmares: colorless legendary Eldrazi Angel with flying, first strike, vigilance and lifelink
	AddCardModifier(new CCardColorModifier(CardType::Null));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));
	SetSecondFaceKeywords(this, CreatureKeyword::FirstStrike, CreatureKeyword::Null);
	SetSecondFaceCardKeyword(this, CardKeyword::Lifelink);

	{
		// When you cast this spell, you may return target Angel or Human creature card from your graveyard to the
		// battlefield. (as Artisan of Kozilek in Rise of the Eldrazi)
		typedef
			TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(
			::CreateObject<TriggeredAbility>(this,
				ZoneId::_AllZones, ZoneId::Stack));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE2(Angel, Human), false));
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(FALSE);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Battlefield));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Brisela: Your opponents can't cast spells with mana value 3 or less. (as Gaddock Teeg in Lorwyn)
		counted_ptr<CPlayerEffectEnchantment> cpAbility(
			::CreateObject<CPlayerEffectEnchantment>(this,
				PlayerEffectType::CantPlaySpells,
				(int)&m_SpellFilter));

		cpAbility->SetAffectOpponentsOnly();
		cpAbility->SetAbilityName(_T("Second Face Enchantment"));
		AddAbility(cpAbility.GetPointer());
	}
}

// Melded face of Bruna, the Fading Light and Gisela, the Broken Blade: its abilities are in CBrunaTheFadingLightCard
CBriselaVoiceOfNightmaresCard::CBriselaVoiceOfNightmaresCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Brisela, Voice of Nightmares"), CardType::_LegendaryCreature, CREATURE_TYPE2(Eldrazi, Angel), nID,
		_T(""), Power(9), Life(10), Power(5), Life(7), _T("Bruna, the Fading Light"))
{
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

CCourageousOutriderCard::CCourageousOutriderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Courageous Outrider"), CardType::Creature,
		CREATURE_TYPE2(Human, Scout), nID, _T("3") WHITE_MANA_TEXT, Power(3), Life(4))
	, m_HumanFilter(_T("a Human card"), _T("Human cards"), new CreatureTypeComparer(CREATURE_TYPE(Human), false))
{
	// When this creature enters, look at the top four cards of your library. You may reveal a Human card from among
	// them and put it into your hand. Put the rest on the bottom of your library in any order.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCourageousOutriderCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CCourageousOutriderCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Oath of Nissa in Oath of the Gatewatch)
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(4), MaximumValue(4));
		pModifier->GetSelection(0).nMinSelectionCount = MinimumValue(0);
		pModifier->GetSelection(0).nMaxSelectionCount = MaximumValue(0);
		pModifier->GetSelection(0).moveType = MoveType::Others;
		pModifier->AddSelection(MinimumValue(0), MaximumValue(1), // select a card to the hand
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::AllPlayers,	// reveal to
			&m_HumanFilter,							// Human cards
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

CDawnGryffCard::CDawnGryffCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dawn Gryff"), CardType::Creature,
		CREATURE_TYPE(Hippogriff), nID, _T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
}

CDesperateSentryCard::CDesperateSentryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Desperate Sentry"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("2") WHITE_MANA_TEXT, Power(1), Life(2))
{
	{
		// When this creature dies, create a 3/2 colorless Eldrazi Horror creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Horror (A)"), 55087, 1);
		AddAbility(cpAbility.GetPointer());
	}

	// Delirium - This creature gets +3/+0 as long as there are four or more card types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+3), CreatureKeyword::Null);
}

CDrogskolShieldmateCard::CDrogskolShieldmateCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Drogskol Shieldmate"), CardType::Creature,
		CREATURE_TYPE2(Spirit, Soldier), nID, _T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, other creatures you control get +0/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDrogskolShieldmateCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CDrogskolShieldmateCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CLifeModifier pModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard != this && pCard->GetCardType().IsCreature())
			pModifier.ApplyTo((CCreatureCard*)pCard);
	}
	return true;
}

CExtricatorOfSinCard::CExtricatorOfSinCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Extricator of Sin"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("2") WHITE_MANA_TEXT, Power(0), Life(3), Power(3), Life(5), _T("Extricator of Flesh"))
	, m_OtherPermanentFilter(_T("another permanent"), _T("other permanents"), new CardTypeComparer(CardType::_Permanent, false))
	, m_NonEldraziFilter(_T("a non-Eldrazi creature"), _T("non-Eldrazi creatures"), new AnyCreatureComparer)
{
	m_OtherPermanentFilter.AddNegateComparer(new SpecificCardComparer(this));
	m_NonEldraziFilter.AddNegateComparer(new CreatureTypeComparer(CREATURE_TYPE(Eldrazi), false));

	// Extricator of Flesh: colorless Eldrazi Horror
	SetEldraziHorrorSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Cleric);

	{
		// When this creature enters, you may sacrifice another permanent. If you do, create a 3/2 colorless Eldrazi
		// Horror creature token. (as Harvester Troll in Oath of the Gatewatch)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetSacrificeResolutionCost(1, &m_OtherPermanentFilter);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExtricatorOfSinCard::BeforeToken));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Delirium - At the beginning of your upkeep, if there are four or more card types among cards in your
		// graveyard, transform this creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CExtricatorOfSinCard::SetUpkeepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExtricatorOfSinCard::BeforeTransform));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Extricator of Flesh: Eldrazi you control have vigilance.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Eldrazi), false),
				Power(+0), Life(+0), CreatureKeyword::Vigilance));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetAbilityName(_T("Second Face Enchantment"));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Extricator of Flesh: {2}, {T}, Sacrifice a non-Eldrazi creature: Create a 3/2 colorless Eldrazi Horror creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2"),
				_T("Eldrazi Horror (A)"), 55087,
				1));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddSacrificeCardCost(1, &m_NonEldraziFilter);
		AddTrait(cpAbility.GetPointer(), SecondFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CExtricatorOfSinCard::BeforeToken(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Eldrazi Horror (A)"), 55087, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CExtricatorOfSinCard::SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !GetOrientation()->IsSecondFaced() && HasDelirium(GetController());
}

bool CExtricatorOfSinCard::BeforeTransform(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced())
	{
		CFaceTransformModifier pModifier;
		pModifier.ApplyTo(this);
	}
	return true;
}

// Back face of Extricator of Sin: its abilities are in CExtricatorOfSinCard
CExtricatorOfFleshCard::CExtricatorOfFleshCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Extricator of Flesh"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Horror), nID,
		_T(""), Power(3), Life(5), Power(0), Life(3), _T("Extricator of Sin"))
{
}

CFaithbearerPaladinCard::CFaithbearerPaladinCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Faithbearer Paladin"), CardType::Creature,
		CREATURE_TYPE2(Human, Knight), nID, _T("4") WHITE_MANA_TEXT, Power(3), Life(4))
{
	GetCardKeyword()->AddLifelink(FALSE);
}

CFiendBinderCard::CFiendBinderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fiend Binder"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("3") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Whenever this creature attacks, tap target creature defending player controls.
	typedef
		TTriggeredTargetAbility< CTriggeredTapCardAbility, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTapCardOption(CTriggeredTapCardAbility::TapCardOption::TapSingleCard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CGeistOfTheLonelyVigilCard::CGeistOfTheLonelyVigilCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Geist of the Lonely Vigil"), CardType::Creature,
		CREATURE_TYPE2(Spirit, Cleric), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	// Delirium - This creature can attack as though it didn't have defender as long as there are four or more card
	// types among cards in your graveyard.
	AddDeliriumBonus(this, Power(+0), CreatureKeyword::DefenderMayAttack);
}

CGiselaTheBrokenBladeCard::CGiselaTheBrokenBladeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Gisela, the Broken Blade"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Angel, Horror), nID, _T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// At the beginning of your end step, if you both own and control Gisela and a creature named Bruna, the Fading
	// Light, exile them, then meld them into Brisela, Voice of Nightmares.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGiselaTheBrokenBladeCard::SetMeldContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGiselaTheBrokenBladeCard::BeforeMeld));
	AddAbility(cpAbility.GetPointer());
}

bool CGiselaTheBrokenBladeCard::SetMeldContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetOwner() == GetController() && FindMeldPartner(GetController(), _T("Bruna, the Fading Light")) != NULL;
}

bool CGiselaTheBrokenBladeCard::BeforeMeld(CAbilityAction* pAction)
{
	ExileAndMeld(this, _T("Bruna, the Fading Light"), pAction->GetController());
	return true;
}

CGuardianOfPilgrimsCard::CGuardianOfPilgrimsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Guardian of Pilgrims"), CardType::Creature,
		CREATURE_TYPE2(Spirit, Cleric), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, target creature gets +1/+1 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CIroncladSlayerCard::CIroncladSlayerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ironclad Slayer"), CardType::Creature,
		CREATURE_TYPE2(Human, Warrior), nID, _T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you may return target Aura or Equipment card from your graveyard to your hand.
	// (as Stoic Builder in Shadows over Innistrad)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Aura | CardType::Equipment, false));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
	AddAbility(cpAbility.GetPointer());
}

CLoneRiderCard::CLoneRiderCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Lone Rider"), CardType::Creature, CREATURE_TYPE2(Human, Knight), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1), Power(4), Life(4), _T("It That Rides as One"))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// It That Rides as One: colorless Eldrazi Horror with first strike, trample and lifelink
	SetEldraziHorrorSecondFace(this, SingleCreatureType::Human, SingleCreatureType::Knight);
	SetSecondFaceKeywords(this, CreatureKeyword::Trample, CreatureKeyword::Null);

	// At the beginning of the end step, if you gained 3 or more life this turn, transform this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLoneRiderCard::SetEndStepContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLoneRiderCard::BeforeTransform));
	AddAbility(cpAbility.GetPointer());
}

bool CLoneRiderCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !GetOrientation()->IsSecondFaced() && GET_INTEGER(GetController()->GetLifeGainThisTurn()) >= 3;
}

bool CLoneRiderCard::BeforeTransform(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced())
	{
		CFaceTransformModifier pModifier;
		pModifier.ApplyTo(this);
	}
	return true;
}

// Back face of Lone Rider: its abilities are in CLoneRiderCard
CItThatRidesAsOneCard::CItThatRidesAsOneCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("It That Rides as One"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Horror), nID,
		_T(""), Power(4), Life(4), Power(1), Life(1), _T("Lone Rider"))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

CSanctifierOfSoulsCard::CSanctifierOfSoulsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sanctifier of Souls"), CardType::Creature,
		CREATURE_TYPE2(Human, Cleric), nID, _T("3") WHITE_MANA_TEXT, Power(2), Life(3))
{
	{
		// Whenever another creature you control enters, this creature gets +1/+1 until end of turn.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSanctifierOfSoulsCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{W}, Exile a creature card from your graveyard: Create a 1/1 white Spirit creature token with flying.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("2") WHITE_MANA_TEXT,
				_T("Spirit (S)"), 55076,
				1));

		cpAbility->GetCost().AddExileGraveyardCardCost(1, CCardFilter::GetFilter(_T("creatures")));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSanctifierOfSoulsCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);
	return true;
}

CSelflessSpiritCard::CSelflessSpiritCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Selfless Spirit"), CardType::Creature,
		CREATURE_TYPE2(Spirit, Cleric), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Sacrifice this creature: Creatures you control gain indestructible until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Creatures you control gain indestructible until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSelflessSpiritCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CSelflessSpiritCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			pModifier.ApplyTo(pBattlefield->GetAt(i));
	return true;
}

CSigardianPriestCard::CSigardianPriestCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sigardian Priest"), CardType::Creature,
		CREATURE_TYPE2(Human, Cleric), nID, _T("1") WHITE_MANA_TEXT, Power(1), Life(2))
{
	// {1}, {T}: Tap target non-Human creature.
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			_T("1"),
			TRUE, FALSE,	// Tap, Untap
			new AnyCreatureComparer));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddNegateComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CSteadfastCatharCard::CSteadfastCatharCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steadfast Cathar"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks, it gets +0/+2 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSteadfastCatharCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CSteadfastCatharCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CLifeModifier pModifier = CLifeModifier(Life(+2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(this);
	return true;
}

CSubjugatorAngelCard::CSubjugatorAngelCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Subjugator Angel"), CardType::Creature,
		CREATURE_TYPE(Angel), nID, _T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
{
	// When this creature enters, tap all creatures your opponents control.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSubjugatorAngelCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

bool CSubjugatorAngelCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pModifier.ApplyTo(pBattlefield->GetAt(i));
	}
	return true;
}

CThaliaHereticCatharCard::CThaliaHereticCatharCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thalia, Heretic Cathar"), CardType::_LegendaryCreature,
		CREATURE_TYPE2(Human, Soldier), nID, _T("2") WHITE_MANA_TEXT, Power(3), Life(2))
	, m_EnterTappedFilter(_T("a creature or nonbasic land"), _T("creatures and nonbasic lands"), new CreatureOrNonbasicLandComparer)
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Creatures and nonbasic lands your opponents control enter tapped. (as Kismet)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::InPlayTapped,
			(int)&m_EnterTappedFilter));

	cpAbility->SetAffectOpponentsOnly();
	AddAbility(cpAbility.GetPointer());
}

CThaliasLancersCard::CThaliasLancersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thalia's Lancers"), CardType::Creature,
		CREATURE_TYPE2(Human, Knight), nID, _T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
	, m_LegendaryFilter(_T("a legendary card"), _T("legendary cards"), new CardTypeComparer(CardType::Legendary, false))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature enters, you may search your library for a legendary card, reveal it, put it into your hand,
	// then shuffle.
	typedef
		TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetCardFilterHelper().SetPredefinedFilter(&m_LegendaryFilter);
	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpAbility->SetToZone(ZoneId::Hand);
	AddAbility(cpAbility.GetPointer());
}

CThrabenStandardBearerCard::CThrabenStandardBearerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thraben Standard Bearer"), CardType::Creature,
		CREATURE_TYPE2(Human, Soldier), nID, WHITE_MANA_TEXT, Power(1), Life(1))
{
	// {1}{W}, {T}, Discard a card: Create a 1/1 white Human Soldier creature token.
	counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
			_T("1") WHITE_MANA_TEXT,
			_T("Human Soldier (A)"), 55075,
			1));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Green creatures

// Delirium bonus with power, toughness and keyword
static void AddDeliriumPwrTgh(CCreatureCard* pCard, Power nPower, Life nLife, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			nPower, nLife, keyword));

	SetDeliriumCondition(cpAbility.GetPointer());
	pCard->AddAbility(cpAbility.GetPointer());
}

// "{cost}: Transform this creature." (first face)
static void AddTransformAbility(CDoubleFacedCreatureCard* pCard, LPCTSTR strCost, CAbility::ResolutionStartedCallback callback)
{
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(pCard,
			strCost));

	cpAbility->SetAbilityText(_T("Transform this creature. Activates"));
	cpAbility->SetResolutionStartedCallback(callback);
	AddTrait(cpAbility.GetPointer(), FirstFaceCallback(pCard));
	pCard->AddAbility(cpAbility.GetPointer());
}

static void TransformIfFirstFace(CDoubleFacedCreatureCard* pCard)
{
	if (pCard->GetZoneId() == ZoneId::Battlefield && !pCard->GetOrientation()->IsSecondFaced())
	{
		CFaceTransformModifier pModifier;
		pModifier.ApplyTo(pCard);
	}
}

// The second face of the Eldritch Moon werewolves: a colorless Eldrazi Werewolf (loses Horror)
static void SetEldraziWerewolfSecondFace(CDoubleFacedCreatureCard* pCard)
{
	pCard->AddCardModifier(new CCardColorModifier(CardType::Null));
	pCard->AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, FALSE));
	pCard->AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));
}

// The source creature fights the creature this modifier is applied to (as Rabid Bite in Shadows over Innistrad)
class CFightModifier : public CCreatureModifier
{
public:
	CFightModifier(CCreatureCard* pSource)
		: m_pSource(pSource)
	{}

	virtual void ApplyTo(CCreatureCard* pTarget) const
	{
		CCreatureModifier::ApplyTo(pTarget);

		if (m_pSource->GetZoneId() != ZoneId::Battlefield || pTarget->GetZoneId() != ZoneId::Battlefield || m_pSource == pTarget)
			return;

		int nSourcePower = GET_INTEGER(m_pSource->GetPower());
		int nTargetPower = GET_INTEGER(pTarget->GetPower());
		if (nSourcePower > 0)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-nSourcePower), m_pSource, PreventableType::Preventable, DamageType::NonCombatDamage);
			pModifier.ApplyTo(pTarget);
		}
		if (nTargetPower > 0)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-nTargetPower), pTarget, PreventableType::Preventable, DamageType::NonCombatDamage);
			pModifier.ApplyTo(m_pSource);
		}
	}

	virtual void RemoveFrom(CCreatureCard* pTarget) const
	{
		CCreatureModifier::RemoveFrom(pTarget);
	}

	virtual CCreatureModifier* CloneCreatureModifier() const
	{
		return new CFightModifier(*this);
	}

protected:
	CCreatureCard* m_pSource;
};

// Creature with toughness 4 or greater (Ulvenwald Observer)
struct ToughnessFourOrGreaterComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && GET_INTEGER(((const CCreatureCard*)pCard)->GetToughness()) >= 4;
	}

	virtual ToughnessFourOrGreaterComparer* Clone() const
	{
		return new ToughnessFourOrGreaterComparer;
	}
};

CBackwoodsSurvivalistsCard::CBackwoodsSurvivalistsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Backwoods Survivalists"), CardType::Creature,
		CREATURE_TYPE2(Human, Warrior), nID, _T("3") GREEN_MANA_TEXT, Power(4), Life(3))
{
	// Delirium - This creature gets +1/+1 and has trample as long as there are four or more card types among cards in
	// your graveyard.
	AddDeliriumPwrTgh(this, Power(+1), Life(+1), CreatureKeyword::Trample);
}

CBloodbriarCard::CBloodbriarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodbriar"), CardType::Creature,
		CREATURE_TYPE2(Plant, Elemental), nID, _T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you sacrifice another permanent, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::_AllZones));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodbriarCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBloodbriarCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CBloodbriarCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
										CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Sacrifice && pCard != this && pByPlayer == GetController();
}

bool CBloodbriarCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
		pModifier.ApplyTo(this);
	}
	return true;
}

CCrossroadsConsecratorCard::CCrossroadsConsecratorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Crossroads Consecrator"), CardType::Creature,
		CREATURE_TYPE2(Human, Cleric), nID, GREEN_MANA_TEXT, Power(1), Life(2))
{
	// {G}, {T}: Target attacking Human gets +1/+1 until end of turn.
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			GREEN_MANA_TEXT,
			Power(+1), Life(+1),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Human), false));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CEmrakulsEvangelCard::CEmrakulsEvangelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Emrakul's Evangel"), CardType::Creature,
		CREATURE_TYPE2(Human, Horror), nID, _T("2") GREEN_MANA_TEXT, Power(3), Life(2))
	, m_OtherNonEldraziFilter(_T("another non-Eldrazi creature"), _T("other non-Eldrazi creatures"), new AnyCreatureComparer)
{
	m_OtherNonEldraziFilter.AddNegateComparer(new CreatureTypeComparer(CREATURE_TYPE(Eldrazi), false));
	m_OtherNonEldraziFilter.AddNegateComparer(new SpecificCardComparer(this));

	// {T}, Sacrifice this creature and any number of other non-Eldrazi creatures: Create a 3/2 colorless Eldrazi
	// Horror creature token for each creature sacrificed this way.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetCost().AddSacrificeCardCost(SpecialNumber::Any, &m_OtherNonEldraziFilter);
	cpAbility->SetAbilityText(_T("Create a 3/2 Eldrazi Horror for each creature sacrificed. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmrakulsEvangelCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CEmrakulsEvangelCard::BeforeResolution(CAbilityAction* pAction) const
{
	// This creature and the other sacrificed creatures
	int nCount = 1;
	const CCountedCardContainer* pSacrificed = pAction->GetCostConfigEntry().GetSacrificeCards();
	if (pSacrificed)
		for (int i = 0; i < pSacrificed->GetSize(); ++i)
			if (pSacrificed->GetAt(i) != this)
				++nCount;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Eldrazi Horror (A)"), 55087, nCount);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CFoulEmissaryCard::CFoulEmissaryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Foul Emissary"), CardType::Creature,
		CREATURE_TYPE2(Human, Horror), nID, _T("2") GREEN_MANA_TEXT, Power(1), Life(1))
	, m_CreatureFilter(_T("a creature card"), _T("creature cards"), new AnyCreatureComparer)
{
	// When this creature enters, look at the top four cards of your library. You may reveal a creature card from among
	// them and put it into your hand. Put the rest on the bottom of your library in any order.
	// Note: "When you sacrifice this creature while casting a spell with emerge, create a 3/2 colorless Eldrazi Horror
	// creature token." is not implemented yet.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFoulEmissaryCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CFoulEmissaryCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Courageous Outrider)
	CZoneModifier* pModifier = new CDrawCardModifier(GetGame(), MinimumValue(4), MaximumValue(4));
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

		pModifier->SetReorderInformation(
			true,
			ZoneId::Library,
			CZoneModifier::RoleType::PrimaryPlayer,	// this player's library
			CardPlacement::Bottom);

	pModifier->ApplyTo(pAction->GetController());

	return true;
}

CGnarlwoodDryadCard::CGnarlwoodDryadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gnarlwood Dryad"), CardType::Creature,
		CREATURE_TYPE2(Dryad, Horror), nID, GREEN_MANA_TEXT, Power(1), Life(1))
{
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Delirium - This creature gets +2/+2 as long as there are four or more card types among cards in your graveyard.
	AddDeliriumPwrTgh(this, Power(+2), Life(+2), CreatureKeyword::Null);
}

CIshkanahGrafwidowCard::CIshkanahGrafwidowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ishkanah, Grafwidow"), CardType::_LegendaryCreature,
		CREATURE_TYPE(Spider), nID, _T("4") GREEN_MANA_TEXT, Power(3), Life(5))
{
	GetCreatureKeyword()->AddReach(FALSE);

	{
		// Delirium - When Ishkanah enters, if there are four or more card types among cards in your graveyard, create
		// three 1/2 green Spider creature tokens with reach.
		// Note: delirium is checked when the ability resolves
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIshkanahGrafwidowCard::BeforeSpiders));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {6}{B}: Target opponent loses 1 life for each Spider you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("6") BLACK_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIshkanahGrafwidowCard::BeforeLifeLoss));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CIshkanahGrafwidowCard::BeforeSpiders(CAbilityAction* pAction) const
{
	if (!HasDelirium(pAction->GetController()))
		return true;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Spider (E)"), 55088, 3);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CIshkanahGrafwidowCard::BeforeLifeLoss(CAbilityAction* pAction) const
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	int nSpiders = CountControlled(pAction->GetController(), CreatureTypeComparer(CREATURE_TYPE(Spider), false));
	if (nSpiders > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nSpiders), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

CKessigProwlerCard::CKessigProwlerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Kessig Prowler"), CardType::Creature, CREATURE_TYPE2(Werewolf, Horror), nID,
		GREEN_MANA_TEXT, Power(2), Life(1), Power(4), Life(4), _T("Sinuous Predator"))
{
	// Sinuous Predator: colorless Eldrazi Werewolf. This creature can't be blocked by more than one creature.
	SetEldraziWerewolfSecondFace(this);
	SetSecondFaceKeywords(this, CreatureKeyword::CantBeBlockedByMultiple, CreatureKeyword::Null);

	// {4}{G}: Transform this creature.
	AddTransformAbility(this, _T("4") GREEN_MANA_TEXT, CAbility::ResolutionStartedCallback(this, &CKessigProwlerCard::BeforeTransform));
}

bool CKessigProwlerCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

// Back face of Kessig Prowler: its abilities are in CKessigProwlerCard
CSinuousPredatorCard::CSinuousPredatorCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Sinuous Predator"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Werewolf), nID,
		_T(""), Power(4), Life(4), Power(2), Life(1), _T("Kessig Prowler"))
{
	GetCreatureKeyword()->AddCantBeBlockedByMultiple(FALSE);
}

CNooseConstrictorCard::CNooseConstrictorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Noose Constrictor"), CardType::Creature,
		CREATURE_TYPE(Snake), nID, _T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddReach(FALSE);

	// Discard a card: This creature gets +1/+1 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T(""), Power(+1), Life(+1)));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	AddAbility(cpAbility.GetPointer());
}

CPrimalDruidCard::CPrimalDruidCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Primal Druid"), CardType::Creature,
		CREATURE_TYPE2(Human, Druid), nID, _T("1") GREEN_MANA_TEXT, Power(0), Life(3))
{
	// When this creature dies, you may search your library for a basic land card, put it onto the battlefield tapped,
	// then shuffle.
	typedef
		TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("basic lands")));
	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpAbility->SetToZone(ZoneId::Battlefield);
	cpAbility->SetToOwnersZone(FALSE);
	cpAbility->SetTapped(TRUE);
	AddAbility(cpAbility.GetPointer());
}

CSomberwaldStagCard::CSomberwaldStagCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Somberwald Stag"), CardType::Creature,
		CREATURE_TYPE(Elk), nID, _T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(3))
{
	// When this creature enters, you may have it fight target creature you don't control.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetPowerModifier().LinkCreatureModifier(new CFightModifier(this));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

CSpiritOfTheHuntCard::CSpiritOfTheHuntCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spirit of the Hunt"), CardType::Creature,
		CREATURE_TYPE2(Wolf, Spirit), nID, _T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(3))
{
	GetCardKeyword()->AddFlash(FALSE);

	// When this creature enters, each other creature you control that's a Wolf or a Werewolf gets +0/+3 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpiritOfTheHuntCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CSpiritOfTheHuntCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CreatureTypeComparer wolves(CREATURE_TYPE2(Wolf, Werewolf), false);
	CLifeModifier pModifier = CLifeModifier(Life(+3), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard != this && pCard->GetCardType().IsCreature() && wolves(pCard))
			pModifier.ApplyTo((CCreatureCard*)pCard);
	}
	return true;
}

CSwiftSpinnerCard::CSwiftSpinnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Swift Spinner"), CardType::Creature,
		CREATURE_TYPE(Spider), nID, _T("3") GREEN_MANA_TEXT, Power(2), Life(3))
{
	GetCardKeyword()->AddFlash(FALSE);
	GetCreatureKeyword()->AddReach(FALSE);
}

CTangleclawWerewolfCard::CTangleclawWerewolfCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Tangleclaw Werewolf"), CardType::Creature, CREATURE_TYPE2(Werewolf, Horror), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(4), Power(4), Life(6), _T("Fibrous Entangler"))
{
	// This creature can block an additional creature each combat. (both faces)
	SetMaxBlockingCount(2);

	// Fibrous Entangler: colorless Eldrazi Werewolf with vigilance.
	// Note: "This creature must be blocked if able." is not implemented.
	SetEldraziWerewolfSecondFace(this);
	SetSecondFaceKeywords(this, CreatureKeyword::Vigilance, CreatureKeyword::Null);

	// {6}{G}: Transform this creature.
	AddTransformAbility(this, _T("6") GREEN_MANA_TEXT, CAbility::ResolutionStartedCallback(this, &CTangleclawWerewolfCard::BeforeTransform));
}

bool CTangleclawWerewolfCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

// Back face of Tangleclaw Werewolf: its abilities are in CTangleclawWerewolfCard
CFibrousEntanglerCard::CFibrousEntanglerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Fibrous Entangler"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Werewolf), nID,
		_T(""), Power(4), Life(6), Power(2), Life(4), _T("Tangleclaw Werewolf"))
{
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CUlvenwaldCaptiveCard::CUlvenwaldCaptiveCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Ulvenwald Captive"), CardType::Creature, CREATURE_TYPE2(Werewolf, Horror), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(2), Power(4), Life(6), _T("Ulvenwald Abomination"))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	// Ulvenwald Abomination: colorless Eldrazi Werewolf without defender
	SetEldraziWerewolfSecondFace(this);
	SetSecondFaceKeywords(this, CreatureKeyword::Null, CreatureKeyword::Defender);

	{
		// {T}: Add {G}. (first face)
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, GREEN_MANA_TEXT));
		cpAbility->AddTapCost();
		AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Ulvenwald Abomination: {T}: Add {C}{C}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, COLORLESS_MANA_TEXT COLORLESS_MANA_TEXT));
		cpAbility->AddTapCost();
		AddTrait(cpAbility.GetPointer(), SecondFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}

	// {5}{G}{G}: Transform this creature.
	AddTransformAbility(this, _T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, CAbility::ResolutionStartedCallback(this, &CUlvenwaldCaptiveCard::BeforeTransform));
}

bool CUlvenwaldCaptiveCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

// Back face of Ulvenwald Captive: its abilities are in CUlvenwaldCaptiveCard
CUlvenwaldAbominationCard::CUlvenwaldAbominationCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Ulvenwald Abomination"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Werewolf), nID,
		_T(""), Power(4), Life(6), Power(1), Life(2), _T("Ulvenwald Captive"))
{
}

CUlvenwaldObserverCard::CUlvenwaldObserverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ulvenwald Observer"), CardType::Creature,
		CREATURE_TYPE(Treefolk), nID, _T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Whenever a creature you control with toughness 4 or greater dies, draw a card.
	// Note: the toughness is checked in the graveyard (printed toughness)
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new ToughnessFourOrGreaterComparer);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

CWoodlandPatrolCard::CWoodlandPatrolCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Woodland Patrol"), CardType::Creature,
		CREATURE_TYPE2(Human, Scout), nID, _T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	GetCreatureKeyword()->AddVigilance(FALSE);
}

//____________________________________________________________________________
//
// Red creatures

// Mana added at the beginning of the next main phase of this turn
static void AddManaAtNextMainPhase(CGame* pGame, CPlayer* pPlayer, LPCTSTR strMana)
{
	CScheduledPlayerModifier pModifier = CScheduledPlayerModifier(pGame,
		new CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(strMana)),
		TurnNumberDelta(0), NodeId::MainPhaseStep, CScheduledPlayerModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pPlayer);
}

CAssembledAlphasCard::CAssembledAlphasCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Assembled Alphas"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("5") RED_MANA_TEXT, Power(5), Life(5))
{
	// Whenever this creature blocks or becomes blocked by a creature, this creature deals 3 damage to that creature
	// and 3 damage to that creature's controller. (as Kessig Forgemaster in Shadows over Innistrad)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-3));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::Preventable);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CAssembledAlphasCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CAssembledAlphasCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
}

bool CAssembledAlphasCard::SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
											 CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const
{
	triggerContext.m_pCreature = pCreature2;
	return pCreature2 != NULL;
}

bool CAssembledAlphasCard::BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const
{
	// The damage to the creature is dealt by the ability; the damage to its controller here
	CCreatureCard* pCreature = pAction->GetTriggerContext().m_pCreature;
	if (pCreature)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-3), (CCard*)this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCreature->GetController());
	}
	return true;
}

CBedlamRevelerCard::CBedlamRevelerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bedlam Reveler"), CardType::Creature,
		CREATURE_TYPE2(Devil, Horror), nID, _T("6") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(4))
	, m_CardFilter(_T("an instant or sorcery card"), _T("instant and sorcery cards"), new CardTypeComparer(CardType::Instant | CardType::Sorcery, false))
{
	{
		// This spell costs {1} less to cast for each instant and sorcery card in your graveyard. (as Ghoultree in Dark Ascension)
		counted_ptr<CTriggeredAffinityAbility> cpAbility(
			::CreateObject<CTriggeredAffinityAbility>(this,
				&m_CardFilter));

		cpAbility->SetManaReductionColor(CManaCostBase::Color::Generic);
		cpAbility->SetCountingZone(ZoneId::Graveyard);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Prowess (as in Khans of Tarkir)
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
	{
		// When this creature enters, discard your hand, then draw three cards.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBedlamRevelerCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CBedlamRevelerCard::BeforeResolution(CAbilityAction* pAction) const
{
	// (as Chandra, Flamecaller in Oath of the Gatewatch)
	CPlayer* pController = pAction->GetController();
	CZone* pHand = pController->GetZoneById(ZoneId::Hand);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Graveyard, TRUE, MoveType::Discard, pController);
	while (pHand->GetSize() > 0)
		pModifier.ApplyTo(pHand->GetAt(pHand->GetSize() - 1));

	CDrawCardModifier pDrawModifier = CDrawCardModifier(GetGame(), MinimumValue(3), MaximumValue(3));
	pDrawModifier.ApplyTo(pController);
	return true;
}

CBoldImpalerCard::CBoldImpalerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bold Impaler"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Knight), nID, RED_MANA_TEXT, Power(1), Life(2))
{
	// {2}{R}: This creature gets +2/+0 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T("2") RED_MANA_TEXT, Power(+2), Life(+0)));
	AddAbility(cpAbility.GetPointer());
}

CBrazenWolvesCard::CBrazenWolvesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brazen Wolves"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// Whenever this creature attacks, it gets +2/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+2));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CConduitOfStormsCard::CConduitOfStormsCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Conduit of Storms"), CardType::Creature, CREATURE_TYPE2(Werewolf, Horror), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3), Power(5), Life(4), _T("Conduit of Emrakul"))
{
	// Conduit of Emrakul: colorless Eldrazi Werewolf
	SetEldraziWerewolfSecondFace(this);

	// Whenever this creature attacks, add {R} at the beginning of your next main phase this turn.
	// Conduit of Emrakul: Whenever this creature attacks, add {C}{C} at the beginning of your next main phase this turn.
	for (int i = 0; i < 2; ++i)
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
							   CWhenSelfAttackedBlocked::AttackEventCallback,
							   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this,
			i == 0 ? &CConduitOfStormsCard::SetFrontContext : &CConduitOfStormsCard::SetBackContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this,
			i == 0 ? &CConduitOfStormsCard::BeforeRed : &CConduitOfStormsCard::BeforeColorless));
		AddAbility(cpAbility.GetPointer());
	}

	// {3}{R}{R}: Transform this creature.
	AddTransformAbility(this, _T("3") RED_MANA_TEXT RED_MANA_TEXT, CAbility::ResolutionStartedCallback(this, &CConduitOfStormsCard::BeforeTransform));
}

bool CConduitOfStormsCard::SetFrontContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return !GetOrientation()->IsSecondFaced();
}

bool CConduitOfStormsCard::SetBackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return GetOrientation()->IsSecondFaced() ? true : false;
}

bool CConduitOfStormsCard::BeforeRed(CAbilityAction* pAction) const
{
	AddManaAtNextMainPhase(GetGame(), pAction->GetController(), RED_MANA_TEXT);
	return true;
}

bool CConduitOfStormsCard::BeforeColorless(CAbilityAction* pAction) const
{
	AddManaAtNextMainPhase(GetGame(), pAction->GetController(), COLORLESS_MANA_TEXT COLORLESS_MANA_TEXT);
	return true;
}

bool CConduitOfStormsCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

// Back face of Conduit of Storms: its abilities are in CConduitOfStormsCard
CConduitOfEmrakulCard::CConduitOfEmrakulCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Conduit of Emrakul"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Werewolf), nID,
		_T(""), Power(5), Life(4), Power(2), Life(3), _T("Conduit of Storms"))
{
}

CDerangedWhelpCard::CDerangedWhelpCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deranged Whelp"), CardType::Creature,
		CREATURE_TYPE(Wolf), nID, _T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CFalkenrathReaverCard::CFalkenrathReaverCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Falkenrath Reaver"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("1") RED_MANA_TEXT, Power(2), Life(2))
{
}

CFurybladeVampireCard::CFurybladeVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Furyblade Vampire"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Berserker), nID, _T("1") RED_MANA_TEXT, Power(1), Life(2))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// At the beginning of combat on your turn, you may discard a card. If you do, this creature gets +3/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetDiscardResolutionCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+3));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CImpetuousDevilsCard::CImpetuousDevilsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Impetuous Devils"), CardType::Creature,
		CREATURE_TYPE(Devil), nID, _T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(1))
{
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Note: "When this creature attacks, up to one target creature defending player controls blocks it this combat
	// if able." is not implemented.

	// At the beginning of the end step, sacrifice this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImpetuousDevilsCard::BeforeSacrifice));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	AddAbility(cpAbility.GetPointer());
}

bool CImpetuousDevilsCard::BeforeSacrifice(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, GetController());
		pModifier.ApplyTo(this);
	}
	return true;
}

CInsatiableGorgersCard::CInsatiableGorgersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Insatiable Gorgers"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Berserker), nID, _T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(3))
	, m_Madness(this)
{
	// This creature attacks each combat if able.
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);

	// Madness {3}{R} (the creature cast for its madness cost, as in Shadows over Innistrad)
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3") RED_MANA_TEXT, TRUE));
	AddSpell(cpSpell.GetPointer());
	m_Madness.SetMadnessSpell(cpSpell.GetPointer());
}

CSmolderingWerewolfCard::CSmolderingWerewolfCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Smoldering Werewolf"), CardType::Creature, CREATURE_TYPE2(Werewolf, Horror), nID,
		_T("2") RED_MANA_TEXT RED_MANA_TEXT, Power(3), Life(2), Power(6), Life(4), _T("Erupting Dreadwolf"))
{
	// Erupting Dreadwolf: colorless Eldrazi Werewolf
	SetEldraziWerewolfSecondFace(this);

	{
		// When this creature enters, it deals 1 damage to each of up to two target creatures.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetSubjectCount(0, 2);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Erupting Dreadwolf: Whenever this creature attacks, it deals 2 damage to any target. (as in Coldsnap)
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfAttackedBlocked,
									 CWhenSelfAttackedBlocked::AttackEventCallback,
									 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSmolderingWerewolfCard::SetBackContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}

	// {4}{R}{R}: Transform this creature.
	AddTransformAbility(this, _T("4") RED_MANA_TEXT RED_MANA_TEXT, CAbility::ResolutionStartedCallback(this, &CSmolderingWerewolfCard::BeforeTransform));
}

bool CSmolderingWerewolfCard::SetBackContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return GetOrientation()->IsSecondFaced() ? true : false;
}

bool CSmolderingWerewolfCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

// Back face of Smoldering Werewolf: its abilities are in CSmolderingWerewolfCard
CEruptingDreadwolfCard::CEruptingDreadwolfCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Erupting Dreadwolf"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Werewolf), nID,
		_T(""), Power(6), Life(4), Power(3), Life(2), _T("Smoldering Werewolf"))
{
}

CStensiaInnkeeperCard::CStensiaInnkeeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stensia Innkeeper"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, tap target land an opponent controls. That land doesn't untap during its
	// controller's next untap step.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().Add(new CCardOrientationModifier(TRUE));

	CCardKeywordModifier* pModifier = new CCardKeywordModifier;
	pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->GetCardModifiers().Add(pModifier);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CThermoAlchemistCard::CThermoAlchemistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thermo-Alchemist"), CardType::Creature,
		CREATURE_TYPE2(Human, Shaman), nID, _T("1") RED_MANA_TEXT, Power(0), Life(3))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	{
		// {T}: This creature deals 1 damage to each opponent.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Deals 1 damage to each opponent. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThermoAlchemistCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast an instant or sorcery spell, untap this creature.
		typedef
			TTriggeredAbility< CTriggeredTapCardAbility, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
		cpAbility->SetTapCardOption(CTriggeredTapCardAbility::TapCardOption::UntapSingleCard);
		cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CThermoAlchemistCard::BeforeResolution(CAbilityAction* pAction) const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-1), (CCard*)this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

CVildinPackOutcastCard::CVildinPackOutcastCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Vildin-Pack Outcast"), CardType::Creature, CREATURE_TYPE2(Werewolf, Horror), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(4), Power(5), Life(7), _T("Dronepack Kindred"))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Dronepack Kindred: colorless Eldrazi Werewolf with trample
	SetEldraziWerewolfSecondFace(this);

	{
		// {R}: This creature gets +1/-1 until end of turn. (first face)
		counted_ptr<CPumpAbility> cpAbility(
			::CreateObject<CPumpAbility>(this, RED_MANA_TEXT, Power(+1), Life(-1)));
		AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Dronepack Kindred: {1}: This creature gets +1/+0 until end of turn.
		counted_ptr<CPumpAbility> cpAbility(
			::CreateObject<CPumpAbility>(this, _T("1"), Power(+1), Life(+0)));
		AddTrait(cpAbility.GetPointer(), SecondFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}

	// {5}{R}{R}: Transform this creature.
	AddTransformAbility(this, _T("5") RED_MANA_TEXT RED_MANA_TEXT, CAbility::ResolutionStartedCallback(this, &CVildinPackOutcastCard::BeforeTransform));
}

bool CVildinPackOutcastCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

// Back face of Vildin-Pack Outcast: its abilities are in CVildinPackOutcastCard
CDronepackKindredCard::CDronepackKindredCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Dronepack Kindred"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Werewolf), nID,
		_T(""), Power(5), Life(7), Power(4), Life(4), _T("Vildin-Pack Outcast"))
{
	GetCreatureKeyword()->AddTrample(FALSE);
}

CWeaverOfLightningCard::CWeaverOfLightningCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weaver of Lightning"), CardType::Creature,
		CREATURE_TYPE2(Human, Shaman), nID, _T("2") RED_MANA_TEXT, Power(1), Life(4))
{
	GetCreatureKeyword()->AddReach(FALSE);

	// Whenever you cast an instant or sorcery spell, this creature deals 1 damage to target creature an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Black creatures

// The opponents of pPlayer sacrifice nCount creatures of their choice (as Clip Wings in Shadows over Innistrad)
static void RequestCreatureSacrifice(CSelectionSupport& selection, CCard* pSource, CPlayer* pPlayer, int nCount)
{
	for (int ip = 0; ip < pSource->GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = pSource->GetGame()->GetPlayer(ip);
		if (pOpponent == pPlayer)
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

		int nSelect = (int)entries.size() < nCount ? (int)entries.size() : nCount;
		if (nSelect > 0)
			selection.AddSelectionRequest(entries, nSelect, nSelect, pSource, pOpponent);
	}
}

CCryptbreakerCard::CCryptbreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cryptbreaker"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, BLACK_MANA_TEXT, Power(1), Life(1))
	, m_ZombieFilter(_T("an untapped Zombie you control"), _T("untapped Zombies you control"), new CreatureTypeComparer(CREATURE_TYPE(Zombie), false))
{
	{
		// {1}{B}, {T}, Discard a card: Create a 2/2 black Zombie creature token.
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T("1") BLACK_MANA_TEXT,
				_T("Zombie (P)"), 55009,
				1));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Tap three untapped Zombies you control: You draw a card and you lose 1 life.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T(""), 1));

		cpAbility->GetCost().AddTapCardCost(3, &m_ZombieFilter);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
}

CDuskFeasterCard::CDuskFeasterCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dusk Feaster"), CardType::Creature,
		CREATURE_TYPE(Vampire), nID, _T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(5))
{
	// Delirium - This spell costs {2} less to cast if there are four or more card types among cards in your graveyard.
	// (the reduced cost is a second spell, castable only with delirium, as Scour the Laboratory)
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, TRUE));

	cpSpell->SetMainSpell(FALSE);
	cpSpell->SetAbilityText(_T("Delirium - Casts for {3}{B}{B}"));
	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(cpSpell.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CDuskFeasterCard::CanCastWithDelirium)));
	cpSpell->Add(cpTrait.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

BOOL CDuskFeasterCard::CanCastWithDelirium(BOOL bIncludeTricks)
{
	return HasDelirium(GetController());
}

CGavonyUnhallowedCard::CGavonyUnhallowedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gavony Unhallowed"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("3") BLACK_MANA_TEXT, Power(2), Life(4))
{
	// Whenever another creature you control dies, put a +1/+1 counter on this creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGavonyUnhallowedCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CGavonyUnhallowedCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +1);
		pModifier.ApplyTo(this);
	}
	return true;
}

CGrafRatsCard::CGrafRatsCard(CGame* pGame, UINT nID)
	: CMeldCreatureCard(pGame, _T("Graf Rats"), CardType::Creature, CREATURE_TYPE(Rat), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1), Power(5), Life(6), _T("Chittering Host"))
{
	// Chittering Host: colorless Eldrazi Horror with haste and menace
	AddCardModifier(new CCardColorModifier(CardType::Null));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Rat, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, TRUE));
	SetSecondFaceKeywords(this, CreatureKeyword::Haste | CreatureKeyword::CantBeBlockedBy1, CreatureKeyword::Null);

	{
		// At the beginning of combat on your turn, if you both own and control this creature and a creature named
		// Midnight Scavengers, exile them, then meld them into Chittering Host.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGrafRatsCard::SetMeldContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrafRatsCard::BeforeMeld));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Chittering Host: When this creature enters, other creatures you control get +1/+0 and gain menace until end of turn.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGrafRatsCard::SetHostContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrafRatsCard::BeforeHost));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGrafRatsCard::SetMeldContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return !GetOrientation()->IsSecondFaced() && GetOwner() == GetController() &&
		FindMeldPartner(GetController(), _T("Midnight Scavengers")) != NULL;
}

bool CGrafRatsCard::BeforeMeld(CAbilityAction* pAction)
{
	ExileAndMeld(this, _T("Midnight Scavengers"), pAction->GetController());
	return true;
}

bool CGrafRatsCard::SetHostContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
								   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetOrientation()->IsSecondFaced() ? true : false;
}

bool CGrafRatsCard::BeforeHost(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CCreatureKeywordModifier pMenaceModifier;
	pMenaceModifier.GetModifier().SetToAdd(CreatureKeyword::CantBeBlockedBy1);
	pMenaceModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard == this || !pCard->GetCardType().IsCreature())
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pMenaceModifier.ApplyTo((CCreatureCard*)pCard);
	}
	return true;
}

// Melded face of Graf Rats and Midnight Scavengers: its abilities are in CGrafRatsCard
CChitteringHostCard::CChitteringHostCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Chittering Host"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Horror), nID,
		_T(""), Power(5), Life(6), Power(2), Life(1), _T("Graf Rats"))
{
	GetCreatureKeyword()->AddHaste(FALSE);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

CHauntedDeadCard::CHauntedDeadCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Haunted Dead"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("3") BLACK_MANA_TEXT, Power(2), Life(2))
{
	{
		// When this creature enters, create a 1/1 white Spirit creature token with flying.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, _T("Spirit (S)"), 55076, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}, Discard two cards: Return this card from your graveyard to the battlefield tapped.
		// (as in Shadows over Innistrad)
		counted_ptr<CSelfMoveCardAbility> cpAbility(
			::CreateObject<CSelfMoveCardAbility>(this,
				_T("1") BLACK_MANA_TEXT,
				ZoneId::Battlefield, FALSE, MoveType::Others));

		cpAbility->SetGraveyardOnly();
		cpAbility->GetCost().AddDiscardCardCost(2, CCardFilter::GetFilter(_T("cards")));
		cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		AddAbility(cpAbility.GetPointer());
	}
}

CLilianasEliteCard::CLilianasEliteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Liliana's Elite"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("2") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// This creature gets +1/+1 for each creature card in your graveyard. (as Jarad, Golgari Lich Lord in Return to Ravnica)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Graveyard,
			new AnyCreatureComparer));

	AddAbility(cpAbility.GetPointer());
}

CMarkovCrusaderCard::CMarkovCrusaderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Markov Crusader"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Knight), nID, _T("4") BLACK_MANA_TEXT, Power(4), Life(3))
{
	GetCardKeyword()->AddLifelink(FALSE);

	// This creature has haste as long as you control another Vampire. (as Howlpack Wolf in Shadows over Innistrad)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::Haste));

	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Vampire), false));
	cpAbility->GetConditionFilter().AddNegateComparer(new SpecificCardComparer(this));
	cpAbility->SetConditionCheckZone(ZoneId::Battlefield);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

CMidnightScavengersCard::CMidnightScavengersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Midnight Scavengers"), CardType::Creature,
		CREATURE_TYPE2(Human, Rogue), nID, _T("4") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you may return target creature card with mana value 3 or less from your graveyard
	// to your hand. (as Stoic Builder in Shadows over Innistrad)
	// (Melds with Graf Rats: the meld is done by Graf Rats)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(3));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
	AddAbility(cpAbility.GetPointer());
}

CNoosegrafMobCard::CNoosegrafMobCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Noosegraf Mob"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(0), Life(0))
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CNoosegrafMobCard::OnZoneChanged))
{
	// This creature enters with five +1/+1 counters on it. (as Diregraf Colossus in Shadows over Innistrad)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// Whenever a player casts a spell, remove a +1/+1 counter from this creature. If you do, create a 2/2 black Zombie
	// creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNoosegrafMobCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

void CNoosegrafMobCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), +5);
		pModifier.ApplyTo(this);
	}
}

bool CNoosegrafMobCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() <= 0)
		return true;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("+1/+1"), -1);
	pModifier.ApplyTo(this);

	CTokenCreationModifier pTokenModifier = CTokenCreationModifier(GetGame(), _T("Zombie (P)"), 55009, 1);
	pTokenModifier.ApplyTo(pAction->GetController());
	return true;
}

COliviasDragoonCard::COliviasDragoonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Olivia's Dragoon"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Berserker), nID, _T("1") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Discard a card: This creature gains flying until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, _T(""), Power(+0), Life(+0), CreatureKeyword::Flying));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	AddAbility(cpAbility.GetPointer());
}

CSkirsdagSupplicantCard::CSkirsdagSupplicantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Skirsdag Supplicant"), CardType::Creature,
		CREATURE_TYPE2(Human, Cleric), nID, _T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// {B}, {T}, Discard a card: Each player loses 2 life.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			BLACK_MANA_TEXT));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetAbilityText(_T("Each player loses 2 life. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSkirsdagSupplicantCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	AddAbility(cpAbility.GetPointer());
}

bool CSkirsdagSupplicantCard::BeforeResolution(CAbilityAction* pAction) const
{
	CLifeModifier pModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		pModifier.ApplyTo(GetGame()->GetPlayer(ip));
	return true;
}

CStromkirkCondemnedCard::CStromkirkCondemnedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Stromkirk Condemned"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Horror), nID, BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Discard a card: Vampires you control get +1/+1 until end of turn. Activate only once each turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetMaxTurnUsageCount(1);
	cpAbility->SetAbilityText(_T("Vampires you control get +1/+1 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStromkirkCondemnedCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CStromkirkCondemnedCard::BeforeResolution(CAbilityAction* pAction) const
{
	CreatureTypeComparer vampires(CREATURE_TYPE(Vampire), false);
	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature() || !vampires(pCard))
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
	}
	return true;
}

CThrabenFoulbloodsCard::CThrabenFoulbloodsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thraben Foulbloods"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Dog), nID, _T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Delirium - This creature gets +1/+1 and has menace as long as there are four or more card types among cards in
	// your graveyard.
	AddDeliriumPwrTgh(this, Power(+1), Life(+1), CreatureKeyword::CantBeBlockedBy1);
}

CVampireCutthroatCard::CVampireCutthroatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vampire Cutthroat"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Rogue), nID, BLACK_MANA_TEXT, Power(1), Life(1))
{
	GetCreatureKeyword()->AddSkulk(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

CVoldarenPariahCard::CVoldarenPariahCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Voldaren Pariah"), CardType::Creature, CREATURE_TYPE2(Vampire, Horror), nID,
		_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3), Power(6), Life(5), _T("Abolisher of Bloodlines"))
	, m_Madness(this)
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"), new AnyCreatureComparer)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CVoldarenPariahCard::OnCardSelected))
{
	GetCreatureKeyword()->AddFlying(FALSE);
	m_OtherCreatureFilter.AddNegateComparer(new SpecificCardComparer(this));

	// Abolisher of Bloodlines: colorless Eldrazi Vampire with flying
	AddCardModifier(new CCardColorModifier(CardType::Null));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));

	{
		// Sacrifice three other creatures: Transform this creature.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddSacrificeCardCost(3, &m_OtherCreatureFilter);
		cpAbility->SetAbilityText(_T("Transform this creature. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVoldarenPariahCard::BeforeTransform));
		AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Madness {B}{B}{B}
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, TRUE));
		AddSpell(cpSpell.GetPointer());
		m_Madness.SetMadnessSpell(cpSpell.GetPointer());
	}
	{
		// When this creature transforms into Abolisher of Bloodlines, target opponent sacrifices three creatures of
		// their choice. (as Cult of the Waxing Moon in Shadows over Innistrad)
		// Note: the opponent is not targeted (two-player games)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetTriggerIndex(TRANSFORM_TRIGGER_ID);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVoldarenPariahCard::SetTransformContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVoldarenPariahCard::BeforeSacrifice));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVoldarenPariahCard::BeforeTransform(CAbilityAction* pAction)
{
	TransformIfFirstFace(this);
	return true;
}

bool CVoldarenPariahCard::SetTransformContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, int nIndex) const
{
	return pCard == this && GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced();
}

bool CVoldarenPariahCard::BeforeSacrifice(CAbilityAction* pAction)
{
	RequestCreatureSacrifice(m_CardSelection, this, pAction->GetController(), 3);
	return true;
}

void CVoldarenPariahCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected && ((CCard*)it->dwContext)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo((CCard*)it->dwContext);
}

// Back face of Voldaren Pariah: its abilities are in CVoldarenPariahCard
CAbolisherOfBloodlinesCard::CAbolisherOfBloodlinesCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Abolisher of Bloodlines"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Vampire), nID,
		_T(""), Power(6), Life(5), Power(3), Life(3), _T("Voldaren Pariah"))
{
	GetCreatureKeyword()->AddFlying(FALSE);
}

CWailingGhoulCard::CWailingGhoulCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wailing Ghoul"), CardType::Creature,
		CREATURE_TYPE(Zombie), nID, _T("1") BLACK_MANA_TEXT, Power(1), Life(3))
{
	// When this creature enters, mill two cards.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWailingGhoulCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CWailingGhoulCard::BeforeResolution(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 2);
	return true;
}

CWeirdedVampireCard::CWeirdedVampireCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weirded Vampire"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Horror), nID, _T("3") BLACK_MANA_TEXT, Power(3), Life(3))
	, m_Madness(this)
{
	// Madness {2}{B}
	counted_ptr<CSpell> cpSpell(
		::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("2") BLACK_MANA_TEXT, TRUE));
	AddSpell(cpSpell.GetPointer());
	m_Madness.SetMadnessSpell(cpSpell.GetPointer());
}

//____________________________________________________________________________
//
// Blue creatures

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

// Prowess (as in Khans of Tarkir)
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

// "Tap target creature an opponent controls" (the card modifiers of a targeted ability)
static void AddTapNoUntapModifiers(CCardModifiers& modifiers, BOOL bTap, BOOL bNoUntap)
{
	if (bTap)
		modifiers.Add(new CCardOrientationModifier(TRUE));

	if (bNoUntap)
	{
		CCardKeywordModifier* pModifier = new CCardKeywordModifier;
		pModifier->GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier->GetModifier().SetOneTurnOnly(FALSE);
		modifiers.Add(pModifier);
	}
}

CAdvancedStitchwingCard::CAdvancedStitchwingCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Advanced Stitchwing"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(4))
{
	// {2}{U}, Discard two cards: Return this card from your graveyard to the battlefield tapped. (as Haunted Dead)
	counted_ptr<CSelfMoveCardAbility> cpAbility(
		::CreateObject<CSelfMoveCardAbility>(this,
			_T("2") BLUE_MANA_TEXT,
			ZoneId::Battlefield, FALSE, MoveType::Others));

	cpAbility->SetGraveyardOnly();
	cpAbility->GetCost().AddDiscardCardCost(2, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetResolutionModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddAbility(cpAbility.GetPointer());
}

CDocentOfPerfectionCard::CDocentOfPerfectionCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Docent of Perfection"), CardType::Creature, CREATURE_TYPE2(Insect, Horror), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(5), Life(4), Power(6), Life(5), _T("Final Iteration"))
{
	GetCreatureKeyword()->AddFlying(FALSE);

	// Final Iteration: colorless Eldrazi Insect
	AddCardModifier(new CCardColorModifier(CardType::Null));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Horror, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));

	{
		// Whenever you cast an instant or sorcery spell, create a 1/1 blue Human Wizard creature token. Then if you
		// control three or more Wizards, transform this creature. (Final Iteration: only the token)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDocentOfPerfectionCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Final Iteration: Wizards you control get +2/+1 and have flying.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Wizard), false),
				Power(+2), Life(+1), CreatureKeyword::Flying));

		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetAbilityName(_T("Second Face Enchantment"));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDocentOfPerfectionCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Human Wizard (A)"), 55089, 1);
	pModifier.ApplyTo(pController);

	if (!GetOrientation()->IsSecondFaced() && CountControlled(pController, CreatureTypeComparer(CREATURE_TYPE(Wizard), false)) >= 3)
		TransformIfFirstFace(this);
	return true;
}

// Back face of Docent of Perfection: its abilities are in CDocentOfPerfectionCard
CFinalIterationCard::CFinalIterationCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Final Iteration"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Insect), nID,
		_T(""), Power(6), Life(5), Power(5), Life(4), _T("Docent of Perfection"))
{
	GetCreatureKeyword()->AddFlying(FALSE);
}

CEnlightenedManiacCard::CEnlightenedManiacCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Enlightened Maniac"), CardType::Creature,
		CREATURE_TYPE(Human), nID, _T("3") BLUE_MANA_TEXT, Power(0), Life(2))
{
	// When this creature enters, create a 3/2 colorless Eldrazi Horror creature token.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Horror (A)"), 55087, 1);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CExultantCultistCard::CExultantCultistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Exultant Cultist"), CardType::Creature,
		CREATURE_TYPE2(Human, Wizard), nID, _T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
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

CFogwalkerCard::CFogwalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fogwalker"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	GetCreatureKeyword()->AddSkulk(FALSE);

	// When this creature enters, target creature an opponent controls doesn't untap during its controller's next untap step.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	AddTapNoUntapModifiers(cpAbility->GetCardModifiers(), FALSE, TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

CGeistOfTheArchivesCard::CGeistOfTheArchivesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Geist of the Archives"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("2") BLUE_MANA_TEXT, Power(0), Life(4))
{
	GetCreatureKeyword()->AddDefender(FALSE);

	// At the beginning of your upkeep, scry 1.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGeistOfTheArchivesCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CGeistOfTheArchivesCard::BeforeResolution(CAbilityAction* pAction)
{
	ApplyScry(GetGame(), pAction->GetController(), this, 1);
	return true;
}

CGrizzledAnglerCard::CGrizzledAnglerCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Grizzled Angler"), CardType::Creature, CREATURE_TYPE(Human), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3), Power(4), Life(5), _T("Grisly Anglerfish"))
{
	// Grisly Anglerfish: colorless Eldrazi Fish
	AddCardModifier(new CCardColorModifier(CardType::Null));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Human, FALSE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Eldrazi, TRUE));
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Fish, TRUE));

	{
		// {T}: Mill two cards. Then if there is a colorless creature card in your graveyard, transform this creature.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Mill two cards. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrizzledAnglerCard::BeforeMill));
		AddTrait(cpAbility.GetPointer(), FirstFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Grisly Anglerfish: {6}: Creatures your opponents control attack this turn if able.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("6")));

		cpAbility->SetAbilityText(_T("Creatures your opponents control attack this turn if able. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrizzledAnglerCard::BeforeAttack));
		AddTrait(cpAbility.GetPointer(), SecondFaceCallback(this));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGrizzledAnglerCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Mill(pController, 2);

	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (pCard->GetCardType().IsCreature() && !(pCard->GetCardType() & CardType::_ColorMask).Any())
		{
			TransformIfFirstFace(this);
			break;
		}
	}
	return true;
}

bool CGrizzledAnglerCard::BeforeAttack(CAbilityAction* pAction) const
{
	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::MustAttack);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
				pModifier.ApplyTo((CCreatureCard*)pBattlefield->GetAt(i));
	}
	return true;
}

// Back face of Grizzled Angler: its abilities are in CGrizzledAnglerCard
CGrislyAnglerfishCard::CGrislyAnglerfishCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Grisly Anglerfish"), CardType::Creature, CREATURE_TYPE2(Eldrazi, Fish), nID,
		_T(""), Power(4), Life(5), Power(2), Life(3), _T("Grizzled Angler"))
{
}

CIngeniousSkaabCard::CIngeniousSkaabCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ingenious Skaab"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("2") BLUE_MANA_TEXT, Power(2), Life(3))
{
	AddProwess(this);

	// {U}: This creature gets +1/-1 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this, BLUE_MANA_TEXT, Power(+1), Life(-1)));
	AddAbility(cpAbility.GetPointer());
}

CLaboratoryBruteCard::CLaboratoryBruteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Laboratory Brute"), CardType::Creature,
		CREATURE_TYPE2(Zombie, Horror), nID, _T("3") BLUE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, mill four cards.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLaboratoryBruteCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CLaboratoryBruteCard::BeforeResolution(CAbilityAction* pAction) const
{
	Mill(pAction->GetController(), 4);
	return true;
}

CMausoleumWandererCard::CMausoleumWandererCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Mausoleum Wanderer"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, BLUE_MANA_TEXT, Power(1), Life(1))
	, m_pCounterAbility(NULL)
{
	{
		// Whenever another Spirit you control enters, this creature gets +1/+1 until end of turn.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Spirit), false));
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddNegateComparer(new SpecificCardComparer(this));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMausoleumWandererCard::BeforeResolution));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Sacrifice this creature: Counter target instant or sorcery spell unless its controller pays {X}, where X is
		// this creature's power. (as Convolute in Ravnica; X is set when the ability can be activated)
		counted_ptr<CActivatedAbility<CCounterSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CCounterSpell>>(this,
				_T(""),
				new CardTypeComparer(CardType::Instant | CardType::Sorcery, false)));

		cpAbility->AddSacrificeCost();
		cpAbility->SetCanBeDenied();
		cpAbility->GetDenialCost().SetManaCost(_T("1"));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CMausoleumWandererCard::CanActivate)));
		cpAbility->Add(cpTrait.GetPointer());

		m_pCounterAbility = cpAbility.GetPointer();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMausoleumWandererCard::BeforeResolution(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	pPowerModifier.ApplyTo(this);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(this);
	return true;
}

BOOL CMausoleumWandererCard::CanActivate(BOOL bIncludeTricks)
{
	// The denial cost is this creature's current power
	int nPower = GET_INTEGER(GetPower());
	if (nPower < 0)
		nPower = 0;

	CString strCost;
	strCost.Format(_T("%d"), nPower);
	m_pCounterAbility->GetDenialCost().SetManaCost(strCost);
	return TRUE;
}

CNebelgastHeraldCard::CNebelgastHeraldCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Nebelgast Herald"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("2") BLUE_MANA_TEXT, Power(2), Life(1))
{
	GetCardKeyword()->AddFlash(FALSE);

	// Whenever this creature or another Spirit you control enters, tap target creature an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Spirit), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	AddTapNoUntapModifiers(cpAbility->GetCardModifiers(), TRUE, FALSE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CNiblisOfFrostCard::CNiblisOfFrostCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Niblis of Frost"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(3))
{
	AddProwess(this);

	// Whenever you cast an instant or sorcery spell, tap target creature an opponent controls. That creature doesn't
	// untap during its controller's next untap step.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	AddTapNoUntapModifiers(cpAbility->GetCardModifiers(), TRUE, TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CWharfInfiltratorCard::CWharfInfiltratorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wharf Infiltrator"), CardType::Creature,
		CREATURE_TYPE2(Human, Horror), nID, _T("1") BLUE_MANA_TEXT, Power(1), Life(1))
{
	GetCreatureKeyword()->AddSkulk(FALSE);

	{
		// Whenever this creature deals combat damage to a player, you may draw a card. If you do, discard a card.
		// (as the loot ability of Shadows over Innistrad)
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetDrawCount(1);
		cpAbility->SetDiscard(1, FALSE, MoveType::Discard);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you discard a creature card, you may pay {2}. If you do, create a 3/2 colorless Eldrazi Horror
		// creature token.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Hand, ZoneId::_AllZones));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWharfInfiltratorCard::SetDiscardContext));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(_T("2"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWharfInfiltratorCard::BeforeToken));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CWharfInfiltratorCard::SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
											  CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return moveType == MoveType::Discard;
}

bool CWharfInfiltratorCard::BeforeToken(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Eldrazi Horror (A)"), 55087, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
// Werewolves (as in Shadows over Innistrad)

CWerewolfSupport::CWerewolfSupport(CDoubleFacedCreatureCard* pCard)
	: m_pCard(pCard)
{
}

void CWerewolfSupport::AddTransformAbilities()
{
	typedef TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	{
		// At the beginning of each upkeep, if no spells were cast last turn, transform this creature.
		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard, NodeId::UpkeepStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CWerewolfSupport::SetDayContext));
		cpAbility->GetResolutionModifier().CCardModifiers::Add(new CFaceTransformModifier);

		m_pCard->AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each upkeep, if a player cast two or more spells last turn, transform this creature.
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

//____________________________________________________________________________
//
// Multicolored creatures

CBloodhallPriestCard::CBloodhallPriestCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bloodhall Priest"), CardType::Creature,
		CREATURE_TYPE2(Vampire, Cleric), nID, _T("2") BLACK_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
	, m_Madness(this)
{
	{
		// Whenever this creature enters, if you have no cards in hand, this creature deals 2 damage to any target.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodhallPriestCard::SetEnterContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature attacks, if you have no cards in hand, this creature deals 2 damage to any target.
		typedef
			TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfAttackedBlocked,
									 CWhenSelfAttackedBlocked::AttackEventCallback,
									 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetLifeModifier().SetLifeDelta(Life(-2));
		cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetIncludePlayers(TRUE);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CBloodhallPriestCard::SetAttackContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Madness {1}{B}{R}
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("1") BLACK_MANA_TEXT RED_MANA_TEXT, TRUE));
		AddSpell(cpSpell.GetPointer());
		m_Madness.SetMadnessSpell(cpSpell.GetPointer());
	}
}

bool CBloodhallPriestCard::SetEnterContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
										   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetController()->GetZoneById(ZoneId::Hand)->GetSize() == 0;
}

bool CBloodhallPriestCard::SetAttackContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, AttackSubject subject) const
{
	return GetController()->GetZoneById(ZoneId::Hand)->GetSize() == 0;
}

CGrimFlayerCard::CGrimFlayerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grim Flayer"), CardType::Creature,
		CREATURE_TYPE2(Human, Warrior), nID, BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	{
		// Whenever this creature deals combat damage to a player, surveil 3.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrimFlayerCard::BeforeResolution));
		AddAbility(cpAbility.GetPointer());
	}

	// Delirium - This creature gets +2/+2 as long as there are four or more card types among cards in your graveyard.
	AddDeliriumPwrTgh(this, Power(+2), Life(+2), CreatureKeyword::Null);
}

bool CGrimFlayerCard::BeforeResolution(CAbilityAction* pAction) const
{
	Surveil(GetGame(), pAction->GetController(), 3);
	return true;
}

CHeronsGraceChampionCard::CHeronsGraceChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Heron's Grace Champion"), CardType::Creature,
		CREATURE_TYPE2(Human, Knight), nID, _T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	GetCardKeyword()->AddFlash(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);

	// When this creature enters, other Humans you control get +1/+1 and gain lifelink until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeronsGraceChampionCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CHeronsGraceChampionCard::BeforeResolution(CAbilityAction* pAction) const
{
	CreatureTypeComparer humans(CREATURE_TYPE(Human), false);
	CPowerModifier pPowerModifier = CPowerModifier(Power(+1));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+1), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CCardKeywordModifier pLifelinkModifier;
	pLifelinkModifier.GetModifier().SetToAdd(CardKeyword::Lifelink);
	pLifelinkModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard == this || !pCard->GetCardType().IsCreature() || !humans(pCard))
			continue;

		pPowerModifier.ApplyTo((CCreatureCard*)pCard);
		pLifeModifier.ApplyTo((CCreatureCard*)pCard);
		pLifelinkModifier.ApplyTo(pCard);
	}
	return true;
}

CMercurialGeistsCard::CMercurialGeistsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Mercurial Geists"), CardType::Creature,
		CREATURE_TYPE(Spirit), nID, _T("2") BLUE_MANA_TEXT RED_MANA_TEXT, Power(1), Life(3))
{
	// Whenever you cast an instant or sorcery spell, this creature gets +3/+0 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+3));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CMournwillowCard::CMournwillowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mournwillow"), CardType::Creature,
		CREATURE_TYPE2(Plant, Skeleton), nID, _T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(3), Life(2))
{
	GetCreatureKeyword()->AddHaste(FALSE);

	// Delirium - When this creature enters, if there are four or more card types among cards in your graveyard,
	// creatures with power 2 or less can't block this turn.
	// Note: delirium is checked when the ability resolves, and the creatures are the ones with power 2 or less then
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMournwillowCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CMournwillowCard::BeforeResolution(CAbilityAction* pAction) const
{
	if (!HasDelirium(pAction->GetController()))
		return true;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsCreature() && GET_INTEGER(((CCreatureCard*)pCard)->GetPower()) <= 2)
				pModifier.ApplyTo((CCreatureCard*)pCard);
		}
	}
	return true;
}

CUlrichOfTheKrallenhordeCard::CUlrichOfTheKrallenhordeCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Ulrich of the Krallenhorde"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Werewolf), nID,
		_T("3") RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4), Power(6), Life(6), _T("Ulrich, Uncontested Alpha"))
	, m_Werewolf(this)
{
	// Ulrich, Uncontested Alpha: Werewolf (not Human)
	AddCreatureModifier(new CCreatureTypeModifier(SingleCreatureType::Human, FALSE));
	m_Werewolf.AddTransformAbilities();

	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CSpecialTrigger > TransformAbility;
	{
		// Whenever this creature enters or transforms into Ulrich of the Krallenhorde, target creature gets +4/+4
		// until end of turn. (enters)
		typedef
			TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetPowerModifier().SetPowerDelta(Power(+4));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+4));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUlrichOfTheKrallenhordeCard::SetEnterContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// (transforms into Ulrich of the Krallenhorde, as Cult of the Waxing Moon in Shadows over Innistrad)
		counted_ptr<TransformAbility> cpAbility(::CreateObject<TransformAbility>(this));

		cpAbility->SetOptionalType(TransformAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetTriggerIndex(TRANSFORM_TRIGGER_ID);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->GetPowerModifier().SetPowerDelta(Power(+4));
		cpAbility->GetLifeModifier().SetLifeDelta(Life(+4));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetContextFunction(TransformAbility::ContextFunction(this, &CUlrichOfTheKrallenhordeCard::SetFrontContext));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Ulrich, Uncontested Alpha: Whenever this creature transforms into Ulrich, Uncontested Alpha, you may have it
		// fight target non-Werewolf creature you don't control. (the fight as Somberwald Stag)
		counted_ptr<TransformAbility> cpAbility(::CreateObject<TransformAbility>(this));

		cpAbility->SetOptionalType(TransformAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetTriggerIndex(TRANSFORM_TRIGGER_ID);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->GetPowerModifier().LinkCreatureModifier(new CFightModifier(this));
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new CreatureTypeComparer(CREATURE_TYPE(Werewolf), false));
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetContextFunction(TransformAbility::ContextFunction(this, &CUlrichOfTheKrallenhordeCard::SetBackContext));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CUlrichOfTheKrallenhordeCard::SetEnterContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
												   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return !GetOrientation()->IsSecondFaced();
}

bool CUlrichOfTheKrallenhordeCard::SetFrontContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CCard* pCard, int nIndex) const
{
	return pCard == this && GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced();
}

bool CUlrichOfTheKrallenhordeCard::SetBackContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CCard* pCard, int nIndex) const
{
	return pCard == this && GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced();
}

// Back face of Ulrich of the Krallenhorde: its abilities are in CUlrichOfTheKrallenhordeCard
CUlrichUncontestedAlphaCard::CUlrichUncontestedAlphaCard(CGame* pGame, UINT nID)
	: CDoubleFacedCreatureCard(pGame, _T("Ulrich, Uncontested Alpha"), CardType::_LegendaryCreature, CREATURE_TYPE(Werewolf), nID,
		_T(""), Power(6), Life(6), Power(4), Life(4), _T("Ulrich of the Krallenhorde"))
{
	AddCardType(CardType::Red | CardType::Green, CardType::_ColorMask);
}

//____________________________________________________________________________
//
// Emerge

CEmergeSupport::CEmergeSupport(CCard* pCard)
	: m_pCard(pCard)
{
}

CEmergeSupport::~CEmergeSupport()
{
	for (size_t i = 0; i < m_Filters.size(); ++i)
		delete m_Filters[i];
}

void CEmergeSupport::AddEmergeSpells(int nGeneric, LPCTSTR strColored)
{
	for (int i = 0; i <= nGeneric; ++i)
	{
		// The sacrificed creature: mana value i (or i or greater for the last spell)
		CCardFilter* pFilter = new CCardFilter(_T("a creature"), _T("creatures"), new AnyCreatureComparer);
		if (i < nGeneric)
			pFilter->AddComparer(new ConvertedManaCostComparer<std::equal_to<int>>(i));
		else
			pFilter->AddComparer(new ConvertedManaCostComparer<std::greater_equal<int>>(i));
		m_Filters.push_back(pFilter);

		// The emerge cost reduced by i
		CString strCost;
		if (nGeneric - i > 0)
			strCost.Format(_T("%d"), nGeneric - i);
		strCost += strColored;
		m_Texts.push_back(strCost);
		LPCTSTR pCost = m_Texts.back();

		CString strText;
		strText.Format(_T("Emerge (sacrificing a creature with mana value %d%s) - Casts"), i, i == nGeneric ? _T(" or greater") : _T(""));
		m_Texts.push_back(strText);
		LPCTSTR pText = m_Texts.back();

		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(m_pCard, m_pCard->GetSpells().GetAt(0)->GetAbilityType(), pCost, TRUE));

		cpSpell->SetMainSpell(FALSE);
		cpSpell->GetCost().AddSacrificeCardCost(1, pFilter);
		cpSpell->SetAbilityText(pText);
		m_pCard->AddSpell(cpSpell.GetPointer());
	}
}

//____________________________________________________________________________
//
// Colorless creatures
// Note: "When you cast this spell" triggers as Artisan of Kozilek in Rise of the Eldrazi (the card moves to the stack)

CAbundantMawCard::CAbundantMawCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Abundant Maw"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Leech), nID, _T("8"), Power(6), Life(4))
	, m_Emerge(this)
{
	// Emerge {6}{B}
	m_Emerge.AddEmergeSpells(6, BLACK_MANA_TEXT);

	// When you cast this spell, target opponent loses 3 life and you gain 3 life.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyLifeAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-3));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage);
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CLifeModifier(Life(+3), this, PreventableType::NotPreventable));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CDecimatorOfTheProvincesCard::CDecimatorOfTheProvincesCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Decimator of the Provinces"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Boar), nID, _T("10"), Power(7), Life(7))
	, m_Emerge(this)
{
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Emerge {6}{G}{G}{G}
	m_Emerge.AddEmergeSpells(6, GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT);

	// When you cast this spell, creatures you control get +2/+2 and gain trample until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDecimatorOfTheProvincesCard::BeforeResolution));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CDecimatorOfTheProvincesCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(+2));
	CLifeModifier pLifeModifier = CLifeModifier(Life(+2), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	CCreatureKeywordModifier pTrampleModifier;
	pTrampleModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pTrampleModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
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

CDistendedMindbenderCard::CDistendedMindbenderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Distended Mindbender"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Insect), nID, _T("8"), Power(5), Life(5))
	, m_Emerge(this)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDistendedMindbenderCard::OnCardSelected))
{
	// Emerge {5}{B}{B}
	m_Emerge.AddEmergeSpells(5, BLACK_MANA_TEXT BLACK_MANA_TEXT);

	// When you cast this spell, target opponent reveals their hand. You choose from it a nonland card with mana value
	// 3 or less and a card with mana value 4 or greater. That player discards those cards.
	// Note: the opponent is not targeted (two-player games)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDistendedMindbenderCard::BeforeResolution));
	AddAbility(cpAbility.GetPointer());
}

bool CDistendedMindbenderCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = GetGame()->GetNextPlayer(pController);
	CZone* pHand = pOpponent->GetZoneById(ZoneId::Hand);

	// Two choices: a nonland card with mana value 3 or less, and a card with mana value 4 or greater
	for (int nChoice = 0; nChoice < 2; ++nChoice)
	{
		std::vector<SelectionEntry> entries;
		for (int i = 0; i < pHand->GetSize(); ++i)
		{
			CCard* pCard = pHand->GetAt(i);
			int nManaValue = (int)pCard->GetConvertedManaCost();
			if (nChoice == 0 ? (pCard->GetCardType().IsLand() || nManaValue > 3) : nManaValue < 4)
				continue;

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Discard %s"), pCard->GetCardName(TRUE));

			entries.push_back(entry);
		}

		if (!entries.empty())
			m_CardSelection.AddSelectionRequest(entries, 1, 1, this, pController, (DWORD)pOpponent);
	}
	return true;
}

void CDistendedMindbenderCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
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

CDrownyardBehemothCard::CDrownyardBehemothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Drownyard Behemoth"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Crab), nID, _T("9"), Power(5), Life(7))
	, m_Emerge(this)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CDrownyardBehemothCard::OnZoneChanged))
{
	GetCardKeyword()->AddFlash(FALSE);

	// Emerge {7}{U}
	m_Emerge.AddEmergeSpells(7, BLUE_MANA_TEXT);

	// This creature has hexproof as long as it entered this turn. (given when it enters, until end of turn)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CDrownyardBehemothCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CardKeyword::Hexproof);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(this);
	}
}

CElderDeepFiendCard::CElderDeepFiendCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Elder Deep-Fiend"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Octopus), nID, _T("8"), Power(5), Life(6))
	, m_Emerge(this)
{
	GetCardKeyword()->AddFlash(FALSE);

	// Emerge {5}{U}{U}
	m_Emerge.AddEmergeSpells(5, BLUE_MANA_TEXT BLUE_MANA_TEXT);

	// When you cast this spell, tap up to four target permanents.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCardAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCardModifiers().Add(new CCardOrientationModifier(TRUE));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Permanent, false));
	cpAbility->GetTargeting().SetSubjectCount(0, 4);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::OrientationChange);
	AddAbility(cpAbility.GetPointer());
}

CEternalScourgeCard::CEternalScourgeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eternal Scourge"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Horror), nID, _T("3"), Power(3), Life(3))
{
	{
		// You may cast this card from exile.
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, GetSpells().GetAt(0)->GetAbilityType(), _T("3"), TRUE));

		cpSpell->SetPlayableFrom(ZoneId::Exile);
		cpSpell->SetMainSpell(FALSE);
		cpSpell->SetAbilityText(_T("Casts from exile"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// When this creature becomes the target of a spell or ability an opponent controls, exile this creature.
		// (as Spectral Prison in Avacyn Restored)
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenSubjectTargeted,
							   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, TRUE, FALSE));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEternalScourgeCard::SetTargetedContext));
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CEternalScourgeCard::SetTargetedContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pByPlayer) const
{
	return pCard == this && pByPlayer && pByPlayer != GetController();
}

CFieldCreeperCard::CFieldCreeperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Field Creeper"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Scarecrow), nID, _T("2"), Power(2), Life(1))
{
}

CGeistFueledScarecrowCard::CGeistFueledScarecrowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Geist-Fueled Scarecrow"), CardType::_ArtifactCreature,
		CREATURE_TYPE(Scarecrow), nID, _T("4"), Power(4), Life(4))
{
	// Creature spells you cast cost {1} more to cast. (as Thalia, Guardian of Thraben in Dark Ascension)
	counted_ptr<CConsExtraManaEnchantment> cpAbility(
		::CreateObject<CConsExtraManaEnchantment>(this,
			new AnyCreatureComparer,
			_T("1")));

	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());
}

CItOfTheHorridSwarmCard::CItOfTheHorridSwarmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("It of the Horrid Swarm"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Insect), nID, _T("8"), Power(4), Life(4))
	, m_Emerge(this)
{
	// Emerge {6}{G}
	m_Emerge.AddEmergeSpells(6, GREEN_MANA_TEXT);

	// When you cast this spell, create two 1/1 green Insect creature tokens.
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Insect (J)"), 55080, 2);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

CLashweedLurkerCard::CLashweedLurkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lashweed Lurker"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Horror), nID, _T("8"), Power(5), Life(4))
	, m_Emerge(this)
{
	// Emerge {5}{G}{U}
	m_Emerge.AddEmergeSpells(5, GREEN_MANA_TEXT BLUE_MANA_TEXT);

	// When you cast this spell, you may put target nonland permanent on top of its owner's library.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Permanent, false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddNegateComparer(new CardTypeComparer(CardType::_Land, false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Library);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Library));
	AddAbility(cpAbility.GetPointer());
}

CMockeryOfNatureCard::CMockeryOfNatureCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mockery of Nature"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Beast), nID, _T("9"), Power(6), Life(5))
	, m_Emerge(this)
{
	// Emerge {7}{G}
	m_Emerge.AddEmergeSpells(7, GREEN_MANA_TEXT);

	// When you cast this spell, you may destroy target artifact or enchantment.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Destroy);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	AddAbility(cpAbility.GetPointer());
}

CVexingScuttlerCard::CVexingScuttlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vexing Scuttler"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Crab), nID, _T("8"), Power(4), Life(5))
	, m_Emerge(this)
{
	// Emerge {6}{U}
	m_Emerge.AddEmergeSpells(6, BLUE_MANA_TEXT);

	// When you cast this spell, you may return target instant or sorcery card from your graveyard to your hand.
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Hand);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Hand));
	AddAbility(cpAbility.GetPointer());
}

CWretchedGryffCard::CWretchedGryffCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Wretched Gryff"), CardType::Creature,
		CREATURE_TYPE2(Eldrazi, Hippogriff), nID, _T("7"), Power(3), Life(4))
	, m_Emerge(this)
{
	// Emerge {5}{U}
	m_Emerge.AddEmergeSpells(5, BLUE_MANA_TEXT);

	// When you cast this spell, draw a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Stack));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Artifacts
// (Equipment as in Shadows over Innistrad, e.g. Murderer's Axe)

static void AddEquipBonus(CEquipAbility* pAbility, CCard* pCard, Power nPower, Life nLife)
{
	if (nLife != Life(0))
		pAbility->AddCreatureModifier(new CLifeModifier(nLife, pCard,
			PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	if (nPower != Power(0))
		pAbility->AddCreatureModifier(new CPowerModifier(nPower, FALSE));
}

CCatharsShieldCard::CCatharsShieldCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cathar's Shield"), CardType::Artifact | CardType::Equipment, nID,
		_T("0"), AbilityType::Artifact)
{
	// Equipped creature gets +0/+3 and has vigilance. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	AddEquipBonus(cpAbility.GetPointer(), this, Power(+0), Life(+3));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Vigilance);
	pModifier->GetModifier().SetOneTurnOnly(FALSE);
	cpAbility->AddCreatureModifier(pModifier);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CCultistsStaffCard::CCultistsStaffCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Cultist's Staff"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	// Equipped creature gets +2/+2. Equip {3}
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("3")));

	AddEquipBonus(cpAbility.GetPointer(), this, Power(+2), Life(+2));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CSlayersCleaverCard::CSlayersCleaverCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Slayer's Cleaver"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
{
	// Equipped creature gets +3/+1 and must be blocked by an Eldrazi if able. Equip {4}
	// Note: "must be blocked by an Eldrazi if able" is not implemented.
	counted_ptr<CEquipAbility> cpAbility(
		::CreateObject<CEquipAbility>(this, _T("4")));

	AddEquipBonus(cpAbility.GetPointer(), this, Power(+3), Life(+1));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
}

CStitchersGraftCard::CStitchersGraftCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Stitcher's Graft"), CardType::Artifact | CardType::Equipment, nID,
		_T("1"), AbilityType::Artifact)
{
	{
		// Equipped creature gets +3/+3. Whenever equipped creature attacks, it doesn't untap during its controller's
		// next untap step. Equip {2}
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("2")));

		AddEquipBonus(cpAbility.GetPointer(), this, Power(+3), Life(+3));
		cpAbility->AddCardModifier(new CCardAbilityModifier(
			CCardAbilityModifier::CreateAbilityCallback(this, &CStitchersGraftCard::CreateEquipmentAbility)));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this Equipment becomes unattached from a permanent, sacrifice that permanent.
		// (as Grafted Wargear in Fifth Dawn)
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenEquipped > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetOnUnequip();
		cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Battlefield);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Graveyard);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Sacrifice);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CStitchersGraftCard::SetUnattachContext));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));

		AddAbility(cpAbility.GetPointer());
	}
}

counted_ptr<CAbility> CStitchersGraftCard::CreateEquipmentAbility(CCard* pCard)
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStitchersGraftCard::BeforeNoUntap));

	return counted_ptr<CAbility>(cpAbility.GetPointer());
}

bool CStitchersGraftCard::BeforeNoUntap(CAbilityAction* pAction) const
{
	CCard* pCreature = pAction->GetAbility()->GetCard();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CardKeyword::NoUntapInNextContUntap);
		pModifier.GetModifier().SetOneTurnOnly(FALSE);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

bool CStitchersGraftCard::SetUnattachContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext,
											 CCard* pEquipCard, CCard* pFromCard, CCard* pToCard) const
{
	if (!pFromCard)
		return false;

	triggerContext.m_pCard = pFromCard;
	return true;
}

CTerrarionCard::CTerrarionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Terrarion"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// This artifact enters tapped.
	SetIntoPlayTapped();

	// {2}, {T}, Sacrifice this artifact: Add two mana in any combination of colors.
	// (one mana ability for each combination, as Cryptolith Rite in Shadows over Innistrad)
	LPCTSTR combinations[] = {
		WHITE_MANA_TEXT WHITE_MANA_TEXT, WHITE_MANA_TEXT BLUE_MANA_TEXT, WHITE_MANA_TEXT BLACK_MANA_TEXT,
		WHITE_MANA_TEXT RED_MANA_TEXT, WHITE_MANA_TEXT GREEN_MANA_TEXT,
		BLUE_MANA_TEXT BLUE_MANA_TEXT, BLUE_MANA_TEXT BLACK_MANA_TEXT, BLUE_MANA_TEXT RED_MANA_TEXT, BLUE_MANA_TEXT GREEN_MANA_TEXT,
		BLACK_MANA_TEXT BLACK_MANA_TEXT, BLACK_MANA_TEXT RED_MANA_TEXT, BLACK_MANA_TEXT GREEN_MANA_TEXT,
		RED_MANA_TEXT RED_MANA_TEXT, RED_MANA_TEXT GREEN_MANA_TEXT,
		GREEN_MANA_TEXT GREEN_MANA_TEXT };

	for (int i = 0; i < _countof(combinations); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("2"), AbilityType::Activated, combinations[i]));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}

	{
		// When this artifact is put into a graveyard from the battlefield, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}
}

CThirstingAxeCard::CThirstingAxeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Thirsting Axe"), CardType::Artifact | CardType::Equipment, nID,
		_T("3"), AbilityType::Artifact)
	, m_pDamageCreature(NULL)
	, m_nDamageTurn(-1)
{
	{
		// Equipped creature gets +4/+0. Equip {2}
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("2")));

		AddEquipBonus(cpAbility.GetPointer(), this, Power(+4), Life(+0));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

		AddAbility(cpAbility.GetPointer());
	}
	{
		// (the combat damage dealt to a creature by the equipped creature is remembered for the end step)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
							   CWhenDamageDealt::CreatureEventCallback,
							   &CWhenDamageDealt::SetCreatureEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CThirstingAxeCard::SetDamageContext));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of your end step, if equipped creature didn't deal combat damage to a creature this turn,
		// sacrifice it.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CThirstingAxeCard::SetEndStepContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThirstingAxeCard::BeforeSacrifice));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CThirstingAxeCard::SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
										 CCard* pFromCard, CCreatureCard* pToCreature, Damage damage)
{
	CCard* pEquipped = GetEquippedOn();
	if (pEquipped && pFromCard == pEquipped && pToCreature && (damage.m_DamageType & DamageType::CombatDamage).Any())
	{
		m_pDamageCreature = pEquipped;
		m_nDamageTurn = GetGame()->GetGameTurnNumber();
	}
	return false;	// nothing goes on the stack
}

bool CThirstingAxeCard::SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	CCard* pEquipped = GetEquippedOn();
	if (GetZoneId() != ZoneId::Battlefield || !pEquipped)
		return false;

	return !(m_pDamageCreature == pEquipped && m_nDamageTurn == GetGame()->GetGameTurnNumber());
}

bool CThirstingAxeCard::BeforeSacrifice(CAbilityAction* pAction)
{
	CCard* pEquipped = GetEquippedOn();
	if (pEquipped && pEquipped->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pEquipped->GetController());
		pModifier.ApplyTo(pEquipped);
	}
	return true;
}

//____________________________________________________________________________
//
