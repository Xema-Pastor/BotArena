#include "stdafx.h"
#include "CardAetherRevolt.h"

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
		DEFINE_CARD(CSpireOfIndustryCard);
		DEFINE_CARD(CAjaniUnyieldingCard);
		DEFINE_CARD(CAjaniValiantProtectorCard);
		DEFINE_CARD(CTezzeretMasterOfMetalCard);
		DEFINE_CARD(CTezzeretTheSchemerCard);
		DEFINE_CARD(CConsulateTurretCard);
		DEFINE_CARD(CGontisAetherHeartCard);
		DEFINE_CARD(CImplementOfCombustionCard);
		DEFINE_CARD(CImplementOfExaminationCard);
		DEFINE_CARD(CImplementOfFerocityCard);
		DEFINE_CARD(CImplementOfImprovementCard);
		DEFINE_CARD(CImplementOfMaliceCard);
		DEFINE_CARD(CLifecraftersBestiaryCard);
		DEFINE_CARD(CPacificationArrayCard);
		DEFINE_CARD(CParadoxEngineCard);
		DEFINE_CARD(CPendulumOfPatternsCard);
		DEFINE_CARD(CPlanarBridgeCard);
		DEFINE_CARD(CRenegadeMapCard);
		DEFINE_CARD(CServoSchematicCard);
		DEFINE_CARD(CUniversalSolventCard);
		DEFINE_CARD(CAethersphereHarvesterCard);
		DEFINE_CARD(CConsulateDreadnoughtCard);
		DEFINE_CARD(CHeartOfKiranCard);
		DEFINE_CARD(CIrontreadCrusherCard);
		DEFINE_CARD(CMobileGarrisonCard);
		DEFINE_CARD(CPeacewalkerColossusCard);
		DEFINE_CARD(CUntetheredExpressCard);
		DEFINE_CARD(CAerialModificationCard);
		DEFINE_CARD(CAidFromTheCowlCard);
		DEFINE_CARD(CAjanisAidCard);
		DEFINE_CARD(CCaughtInTheBrightsCard);
		DEFINE_CARD(CConsulateCrackdownCard);
		DEFINE_CARD(CEfficientConstructionCard);
		DEFINE_CARD(CGontisMachinationsCard);
		DEFINE_CARD(CHiddenStockpileCard);
		DEFINE_CARD(CIceOverCard);
		DEFINE_CARD(COathOfAjaniCard);
		DEFINE_CARD(CPiasRevolutionCard);
		DEFINE_CARD(CSiegeModificationCard);
		DEFINE_CARD(CThopterArrestCard);
		DEFINE_CARD(CBaralsExpertiseCard);
		DEFINE_CARD(CBattleAtTheBridgeCard);
		DEFINE_CARD(CChandrasRevolutionCard);
		DEFINE_CARD(CDaringDemolitionCard);
		DEFINE_CARD(CDarkIntimationsCard);
		DEFINE_CARD(CDestructiveTamperingCard);
		DEFINE_CARD(CInspiringRoarCard);
		DEFINE_CARD(CKariZevsExpertiseCard);
		DEFINE_CARD(CPreyUponCard);
		DEFINE_CARD(CResourcefulReturnCard);
		DEFINE_CARD(CReverseEngineerCard);
		DEFINE_CARD(CRishkarsExpertiseCard);
		DEFINE_CARD(CSecretSalvageCard);
		DEFINE_CARD(CSramsExpertiseCard);
		DEFINE_CARD(CTezzeretsBetrayalCard);
		DEFINE_CARD(CWrangleCard);
		DEFINE_CARD(CYahennisExpertiseCard);
		DEFINE_CARD(CAlleyEvasionCard);
		DEFINE_CARD(CCruelFinalityCard);
		DEFINE_CARD(CDecommissionCard);
		DEFINE_CARD(CDeftDismissalCard);
		DEFINE_CARD(CFatalPushCard);
		DEFINE_CARD(CHeroicInterventionCard);
		DEFINE_CARD(CHighspireInfusionCard);
		DEFINE_CARD(CHungryFlamesCard);
		DEFINE_CARD(CIllusionistsStratagemCard);
		DEFINE_CARD(CInvigoratedRampageCard);
		DEFINE_CARD(CLeaveInTheDustCard);
		DEFINE_CARD(CLifecraftersGiftCard);
		DEFINE_CARD(CMetallicRebukeCard);
		DEFINE_CARD(CNaturalObsolescenceCard);
		DEFINE_CARD(CPerilousPredicamentCard);
		DEFINE_CARD(CPreciseStrikeCard);
		DEFINE_CARD(CRenegadesGetawayCard);
		DEFINE_CARD(CTakeIntoCustodyCard);
		DEFINE_CARD(CWhirOfInventionCard);
		DEFINE_CARD(CAeronautAdmiralCard);
		DEFINE_CARD(CAethergeodeMinerCard);
		DEFINE_CARD(CAetherInspectorCard);
		DEFINE_CARD(CAirdropAeronautsCard);
		DEFINE_CARD(CAudaciousInfiltratorCard);
		DEFINE_CARD(CBastionEnforcerCard);
		DEFINE_CARD(CCountlessGearsRenegadeCard);
		DEFINE_CARD(CDawnfeatherEagleCard);
		DEFINE_CARD(CDeadeyeHarpoonerCard);
		DEFINE_CARD(CFelidarGuardianCard);
		DEFINE_CARD(CGhirapurOspreyCard);
		DEFINE_CARD(CRestorationSpecialistCard);
		DEFINE_CARD(CSolemnRecruitCard);
		DEFINE_CARD(CSramSeniorEdificerCard);
		DEFINE_CARD(CAetherHerderCard);
		DEFINE_CARD(CAetherstreamLeopardCard);
		DEFINE_CARD(CAetherwindBaskerCard);
		DEFINE_CARD(CAjanisComradeCard);
		DEFINE_CARD(CDruidOfTheCowlCard);
		DEFINE_CARD(CGreenbeltRampagerCard);
		DEFINE_CARD(CGreenwheelLiberatorCard);
		DEFINE_CARD(CHiddenHerbalistsCard);
		DEFINE_CARD(CLifecraftCavalryCard);
		DEFINE_CARD(CNarnamRenegadeCard);
		DEFINE_CARD(CPeemaAetherSeerCard);
		DEFINE_CARD(CRidgescaleTuskerCard);
		DEFINE_CARD(CScroungingBandarCard);
		DEFINE_CARD(CSilkweaverEliteCard);
		DEFINE_CARD(CAetherChaserCard);
		DEFINE_CARD(CEmbraalGearSmasherCard);
		DEFINE_CARD(CEnragedGiantCard);
		DEFINE_CARD(CFreejamRegentCard);
		DEFINE_CARD(CFrontlineRebelCard);
		DEFINE_CARD(CKariZevSkyshipRaiderCard);
		DEFINE_CARD(CLathnuSailbackCard);
		DEFINE_CARD(CLightningRunnerCard);
		DEFINE_CARD(CRavenousIntruderCard);
		DEFINE_CARD(CRecklessRacerCard);
		DEFINE_CARD(CScrapperChampionCard);
		DEFINE_CARD(CSweatworksBrawlerCard);
		DEFINE_CARD(CAetherPoisonerCard);
		DEFINE_CARD(CAlleyStranglerCard);
		DEFINE_CARD(CDefiantSalvagerCard);
		DEFINE_CARD(CFenHaulerCard);
		DEFINE_CARD(CFoundryHornetCard);
		DEFINE_CARD(CFourthBridgeProwlerCard);
		DEFINE_CARD(CGiftedAetherbornCard);
		DEFINE_CARD(CGlintSleeveSiphonerCard);
		DEFINE_CARD(CHeraldOfAnguishCard);
		DEFINE_CARD(CIroncladRevolutionaryCard);
		DEFINE_CARD(CMidnightEntourageCard);
		DEFINE_CARD(CNightMarketAeronautCard);
		DEFINE_CARD(CSlyRequisitionerCard);
		DEFINE_CARD(CVengefulRebelCard);
		DEFINE_CARD(CYahenniUndyingPartisanCard);
		DEFINE_CARD(CAetherSwooperCard);
		DEFINE_CARD(CAethertideWhaleCard);
		DEFINE_CARD(CBaralChiefOfComplianceCard);
		DEFINE_CARD(CBastionInventorCard);
		DEFINE_CARD(CDispersalTechnicianCard);
		DEFINE_CARD(CHinterlandDrakeCard);
		DEFINE_CARD(CSalvageScuttlerCard);
		DEFINE_CARD(CShieldedAetherThiefCard);
		DEFINE_CARD(CShipwreckMorayCard);
		DEFINE_CARD(CTrophyMageCard);
		DEFINE_CARD(CWindKinRaidersCard);
		DEFINE_CARD(CMaverickThopteristCard);
		DEFINE_CARD(COutlandBoarCard);
		DEFINE_CARD(CRenegadeRallierCard);
		DEFINE_CARD(CRenegadeWheelsmithCard);
		DEFINE_CARD(CRogueRefinerCard);
		DEFINE_CARD(CSpirePatrolCard);
		DEFINE_CARD(CWeldfastEngineerCard);
		DEFINE_CARD(CAegisAutomatonCard);
		DEFINE_CARD(CAugmentingAutomatonCard);
		DEFINE_CARD(CBarricadeBreakerCard);
		DEFINE_CARD(CFiligreeCrawlerCard);
		DEFINE_CARD(CFoundryAssemblerCard);
		DEFINE_CARD(CNightMarketGuardCard);
		DEFINE_CARD(CPrizefighterConstructCard);
		DEFINE_CARD(CReservoirWalkerCard);
		DEFINE_CARD(CScrapTrawlerCard);
		DEFINE_CARD(CTezzeretsSimulacrumCard);
		DEFINE_CARD(CVerdantAutomatonCard);
		DEFINE_CARD(CWatchfulAutomatonCard);
		DEFINE_CARD(CWelderAutomatonCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
// Helpers

// The cost of a spell: nGeneric generic mana plus the colored part ("" when there's no generic mana left)
static CString MakeCost(int nGeneric, LPCTSTR strColored)
{
	CString strCost;
	if (nGeneric > 0)
		strCost.Format(_T("%d"), nGeneric);
	strCost += strColored;
	return strCost.IsEmpty() ? CString(_T("0")) : strCost;	// a free spell costs {0} (as Lotus Petal)
}

// Improvise (Your artifacts can help cast this spell. Each artifact you tap after you're done activating mana
// abilities pays for {1}.)
// As Delve in Khans of Tarkir: besides the normal spell, the card gets one spell for each number of artifacts that
// can be tapped, with that much less generic mana and the cost "tap N untapped artifacts you control".
// addSpell(strCost, nTapped) creates the spell with that cost, calls SetImprovise(spell, nTapped) and adds it.
template <class T>
static void AddImproviseSpells(T* pCard, int nGeneric, LPCTSTR strColored, void (T::*addSpell)(LPCTSTR, int))
{
	for (int nTapped = 0; nTapped <= nGeneric; ++nTapped)
		(pCard->*addSpell)(MakeCost(nGeneric - nTapped, strColored), nTapped);
}

static void SetImprovise(CSpell* pSpell, int nTapped)
{
	if (nTapped <= 0)
		return;

	pSpell->GetCost().AddTapCardCost(nTapped, CCardFilter::GetFilter(_T("artifacts")));
	pSpell->SetMainSpell(FALSE);
}

// Revolt - "if a permanent left the battlefield under your control this turn" (counted by the core in CPlayer)
static bool HasRevolt(const CPlayer* pPlayer)
{
	return pPlayer && pPlayer->HasRevolt() != FALSE;
}

//____________________________________________________________________________
//
// Lands

CSpireOfIndustryCard::CSpireOfIndustryCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Spire of Industry"), nID)
{
	{
		// {T}: Add {C}.
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, _T("1")));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}

	// {T}, Pay 1 life: Add one mana of any color. Activate only if you control an artifact.
	// (one mana ability for each color, as Mana Confluence in Journey into Nyx)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->AddPayLifeDeltaCost(Life(-1));

		counted_ptr<CPlayableIfTrait> cpTrait(::CreateObject<CPlayableIfTrait>(cpAbility.GetPointer(),
			CPlayableIfTrait::PlayableCallback(this, &CSpireOfIndustryCard::CanTap)));
		cpAbility->Add(cpTrait.GetPointer());
		AddAbility(cpAbility.GetPointer());
	}
}

BOOL CSpireOfIndustryCard::CanTap(BOOL bIncludeTricks)
{
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0;
}

//____________________________________________________________________________
//
// Planeswalkers

static int CountArtifacts(const CPlayer* pPlayer)
{
	return CCardFilter::GetFilter(_T("artifacts"))->CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
}

static void AddCounters(CCard* pCard, LPCTSTR strCounter, int nCount)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield || nCount <= 0)
		return;

	CCardCounterModifier pModifier = CCardCounterModifier(strCounter, +nCount);
	pModifier.ApplyTo(pCard);
}

// Reveals cards from the top of the player's library until a card that matches the comparer is revealed; that card
// is put into the player's hand and the rest on the bottom of the library.
// Note: the rest are put on the bottom in the order they were revealed (not in a random order)
static void RevealUntil(CPlayer* pPlayer, const CardComparer& comparer)
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);

	CCountedCardContainer revealed;
	CCard* pFound = NULL;
	for (int i = pLibrary->GetSize() - 1; i >= 0; --i)
	{
		CCard* pCard = pLibrary->GetAt(i);
		revealed.AddCard(pCard, CardPlacement::Top);
		if (comparer(pCard))
		{
			pFound = pCard;
			break;
		}
	}

	if (pFound)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pPlayer);
		pModifier.ApplyTo(pFound);
	}

	for (int i = 0; i < revealed.GetSize(); ++i)
	{
		CCard* pCard = revealed.GetAt(i);
		if (pCard != pFound && pCard->GetZoneId() == ZoneId::Library)
			pCard->Move(pLibrary, pPlayer, MoveType::Others, CardPlacement::Bottom);
	}
}

// A nonland permanent card: artifact, creature, enchantment or planeswalker
struct NonlandPermanentCardComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return !pCard->GetCardType().IsLand() &&
			(pCard->GetCardType() & (CardType::Artifact | CardType::Creature | CardType::_Enchantment | CardType::Planeswalker)).Any();
	}

	virtual NonlandPermanentCardComparer* Clone() const
	{
		return new NonlandPermanentCardComparer;
	}
};

CAjaniUnyieldingCard::CAjaniUnyieldingCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani Unyielding"), nID,
		_T("4") GREEN_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Ajani, 4)
{
	{
		// +2: Reveal the top three cards of your library. Put all nonland permanent cards revealed this way into your
		// hand and the rest on the bottom of your library in any order.
		// Note: the rest are put on the bottom in the order they were revealed
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->SetAbilityText(_T("+2: Reveal the top three cards of your library. Put all nonland permanent cards revealed this way into your hand and the rest on the bottom of your library."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniUnyieldingCard::BeforeReveal));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Exile target creature. Its controller gains life equal to its power.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniUnyieldingCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -9: Put five +1/+1 counters on each creature you control and five loyalty counters on each other
		// planeswalker you control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -9);
		cpAbility->SetAbilityText(_T("-9: Put five +1/+1 counters on each creature you control and five loyalty counters on each other planeswalker you control."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniUnyieldingCard::BeforeUltimate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAjaniUnyieldingCard::BeforeReveal(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	CCountedCardContainer revealed;
	for (int i = pLibrary->GetSize() - 1; i >= 0 && revealed.GetSize() < 3; --i)
		revealed.AddCard(pLibrary->GetAt(i), CardPlacement::Top);

	NonlandPermanentCardComparer permanents;
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pController);
	for (int i = 0; i < revealed.GetSize(); ++i)
	{
		CCard* pCard = revealed.GetAt(i);
		if (permanents(pCard))
			pModifier.ApplyTo(pCard);
		else
			pCard->Move(pLibrary, pController, MoveType::Others, CardPlacement::Bottom);
	}
	return true;
}

bool CAjaniUnyieldingCard::BeforeExile(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	int nPower = GET_INTEGER(pCreature->GetPower());
	CPlayer* pPlayer = pCreature->GetController();

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(pCreature);

	if (nPower > 0)
	{
		CLifeModifier pLifeModifier = CLifeModifier(Life(+nPower), (CCard*)this, PreventableType::NotPreventable);
		pLifeModifier.ApplyTo(pPlayer);
	}
	return true;
}

bool CAjaniUnyieldingCard::BeforeUltimate(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);

	CCountedCardContainer cards;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		cards.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < cards.GetSize(); ++i)
	{
		CCard* pCard = cards.GetAt(i);
		if (pCard->GetCardType().IsCreature())
			AddCounters(pCard, _T("+1/+1"), 5);
		if (pCard != this && pCard->GetCardType().IsPlaneswalker())
			AddCounters(pCard, LOYALTY_COUNTER, 5);
	}
	return true;
}

CAjaniValiantProtectorCard::CAjaniValiantProtectorCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Ajani, Valiant Protector"), nID,
		_T("4") GREEN_MANA_TEXT WHITE_MANA_TEXT,
		PlaneswalkerType::Ajani, 4)
{
	{
		// +2: Put two +1/+1 counters on up to one target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniValiantProtectorCard::BeforeCounters));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// +1: Reveal cards from the top of your library until you reveal a creature card. Put that card into your hand
		// and the rest on the bottom of your library in a random order.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetAbilityText(_T("+1: Reveal cards from the top of your library until you reveal a creature card. Put that card into your hand and the rest on the bottom of your library."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniValiantProtectorCard::BeforeReveal));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -11: Put X +1/+1 counters on target creature, where X is your life total. That creature gains trample until
		// end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -11);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjaniValiantProtectorCard::BeforeUltimate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAjaniValiantProtectorCard::BeforeCounters(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetCardType().IsCreature())
		AddCounters(pCard, _T("+1/+1"), 2);
	return true;
}

bool CAjaniValiantProtectorCard::BeforeReveal(CAbilityAction* pAction) const
{
	RevealUntil(pAction->GetController(), AnyCreatureComparer());
	return true;
}

bool CAjaniValiantProtectorCard::BeforeUltimate(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	AddCounters(pCreature, _T("+1/+1"), pAction->GetController()->GetLife());

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::Trample);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);
	return true;
}

CTezzeretMasterOfMetalCard::CTezzeretMasterOfMetalCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tezzeret, Master of Metal"), nID,
		_T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Tezzeret, 5)
{
	{
		// +1: Reveal cards from the top of your library until you reveal an artifact card. Put that card into your
		// hand and the rest on the bottom of your library in a random order.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetAbilityText(_T("+1: Reveal cards from the top of your library until you reveal an artifact card. Put that card into your hand and the rest on the bottom of your library."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretMasterOfMetalCard::BeforeReveal));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Target opponent loses life equal to the number of artifacts you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretMasterOfMetalCard::BeforeLifeLoss));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -8: Gain control of all artifacts and creatures target opponent controls.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -8);
		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretMasterOfMetalCard::BeforeUltimate));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CTezzeretMasterOfMetalCard::BeforeReveal(CAbilityAction* pAction) const
{
	RevealUntil(pAction->GetController(), CardTypeComparer(CardType::Artifact, false));
	return true;
}

bool CTezzeretMasterOfMetalCard::BeforeLifeLoss(CAbilityAction* pAction) const
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	int nArtifacts = CountArtifacts(pAction->GetController());
	if (pOpponent && nArtifacts > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nArtifacts), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

bool CTezzeretMasterOfMetalCard::BeforeUltimate(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer cards;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsArtifact() || pCard->GetCardType().IsCreature())
			cards.AddCard(pCard, CardPlacement::Top);
	}

	// Gain control of them (as Confiscation Coup in Kaladesh)
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others, pController);
	for (int i = 0; i < cards.GetSize(); ++i)
		if (cards.GetAt(i)->GetZoneId() == ZoneId::Battlefield && cards.GetAt(i)->GetController() == pOpponent)
			pModifier.ApplyTo(cards.GetAt(i));
	return true;
}

CTezzeretTheSchemerCard::CTezzeretTheSchemerCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Tezzeret the Schemer"), nID,
		_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT,
		PlaneswalkerType::Tezzeret, 5)
{
	{
		// +1: Create a colorless artifact token named Etherium Cell with "{T}, Sacrifice this token: Add one mana of
		// any color."
		counted_ptr<CActivatedAbility<CTokenProductionSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTokenProductionSpell>>(this,
				_T(""),
				_T("Etherium Cell"), 55093,
				1));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Target creature gets +X/-X until end of turn, where X is the number of artifacts you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretTheSchemerCard::BeforeChange));
		AddAbility(cpAbility.GetPointer());
	}

	// -7: You get an emblem with "At the beginning of combat on your turn, target artifact you control becomes an
	// artifact creature with base power and toughness 5/5."
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CTokenCreationModifier(GetGame(), _T("Tezzeret the Schemer Emblem"), 61150, 1, FALSE, ZoneId::_Effects));
	cpAbility->SetAbilityText(_T("-7: You get an emblem with - At the beginning of combat on your turn, target artifact you control becomes an artifact creature with base power and toughness 5/5."));
	AddAbility(cpAbility.GetPointer());
}

bool CTezzeretTheSchemerCard::BeforeChange(CAbilityAction* pAction) const
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	int nX = CountArtifacts(pAction->GetController());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || nX <= 0)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+nX));
	pPowerModifier.ApplyTo(pCreature);
	CLifeModifier pLifeModifier = CLifeModifier(Life(-nX), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pCreature);
	return true;
}

//____________________________________________________________________________
//
// Artifacts

#define SERVO_TOKEN_NAME	_T("Servo (A)")
#define SERVO_TOKEN_ID		55090

static void GetEnergy(CCard* pCard, CPlayer* pPlayer, int nCount)
{
	CEnergyModifier pModifier = CEnergyModifier(pCard->GetGame(), nCount);
	pModifier.ApplyTo(pPlayer);
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

// "When this <permanent> is put into a graveyard from the battlefield, draw a card." (the Implements)
static void AddGraveyardDrawTrigger(CCard* pCard)
{
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetDrawCount(1);
	pCard->AddAbility(cpAbility.GetPointer());
}

// Restricts an activated ability to sorcery speed
static void SetAsSorcery(CAbility* pAbility)
{
	pAbility->SetAbilityType((pAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);
}

CConsulateTurretCard::CConsulateTurretCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Consulate Turret"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// {T}: You get {E}.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("You get {E}."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConsulateTurretCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Pay {E}{E}{E}: This artifact deals 2 damage to target player or planeswalker.
		// Note: players only
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE,
				Life(-2), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 3);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CConsulateTurretCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

CGontisAetherHeartCard::CGontisAetherHeartCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Gonti's Aether Heart"), CardType::_LegendaryArtifact, nID,
		_T("6"), AbilityType::Artifact)
{
	{
		// Whenever Gonti's Aether Heart or another artifact you control enters, you get {E}{E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGontisAetherHeartCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay eight {E}, Exile Gonti's Aether Heart: Take an extra turn after this one. (as Time Walk)
		counted_ptr<CActivatedAbility<CPlayerEffectSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CPlayerEffectSpell>>(this,
				_T(""), PlayerEffectType::TimeWalk, FALSE, 1));

		cpAbility->SetAffectControllerOnly();
		cpAbility->GetCost().AddEnergyCost(this, 8);
		cpAbility->AddExileCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGontisAetherHeartCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CImplementOfCombustionCard::CImplementOfCombustionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Implement of Combustion"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {R}, Sacrifice this artifact: It deals 1 damage to target player or planeswalker.
	// Note: players only
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			RED_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE,
			Life(-1), PreventableType::Preventable));

	cpAbility->AddSacrificeCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	AddAbility(cpAbility.GetPointer());

	// When this artifact is put into a graveyard from the battlefield, draw a card.
	AddGraveyardDrawTrigger(this);
}

CImplementOfExaminationCard::CImplementOfExaminationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Implement of Examination"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	// {U}, Sacrifice this artifact: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			BLUE_MANA_TEXT, 1));

	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());

	// When this artifact is put into a graveyard from the battlefield, draw a card.
	AddGraveyardDrawTrigger(this);
}

CImplementOfFerocityCard::CImplementOfFerocityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Implement of Ferocity"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {G}, Sacrifice this artifact: Put a +1/+1 counter on target creature. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImplementOfFerocityCard::BeforeCounter));
	SetAsSorcery(cpAbility.GetPointer());
	AddAbility(cpAbility.GetPointer());

	// When this artifact is put into a graveyard from the battlefield, draw a card.
	AddGraveyardDrawTrigger(this);
}

bool CImplementOfFerocityCard::BeforeCounter(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetCardType().IsCreature())
		AddCounters(pCard, _T("+1/+1"), 1);
	return true;
}

CImplementOfImprovementCard::CImplementOfImprovementCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Implement of Improvement"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {W}, Sacrifice this artifact: You gain 2 life.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			WHITE_MANA_TEXT));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("You gain 2 life."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImplementOfImprovementCard::BeforeLife));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());

	// When this artifact is put into a graveyard from the battlefield, draw a card.
	AddGraveyardDrawTrigger(this);
}

bool CImplementOfImprovementCard::BeforeLife(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 2);
	return true;
}

CImplementOfMaliceCard::CImplementOfMaliceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Implement of Malice"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// {B}, Sacrifice this artifact: Target player discards a card. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			BLACK_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImplementOfMaliceCard::BeforeDiscard));
	SetAsSorcery(cpAbility.GetPointer());
	AddAbility(cpAbility.GetPointer());

	// When this artifact is put into a graveyard from the battlefield, draw a card.
	AddGraveyardDrawTrigger(this);
}

bool CImplementOfMaliceCard::BeforeDiscard(CAbilityAction* pAction) const
{
	if (pAction->GetAssociatedPlayer())
		DiscardCards(GetGame(), pAction->GetAssociatedPlayer(), 1);
	return true;
}

CLifecraftersBestiaryCard::CLifecraftersBestiaryCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Lifecrafter's Bestiary"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
{
	{
		// At the beginning of your upkeep, scry 1.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLifecraftersBestiaryCard::BeforeScry));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever you cast a creature spell, you may pay {G}. If you do, draw a card.
		typedef
			TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetResolutionCost(GREEN_MANA_TEXT);
		cpAbility->SetDrawCount(1);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLifecraftersBestiaryCard::BeforeScry(CAbilityAction* pAction) const
{
	CScryModifier(GetGame(), 1, (CCard*)this).ApplyTo(pAction->GetController());
	return true;
}

CPacificationArrayCard::CPacificationArrayCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pacification Array"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {2}, {T}: Tap target artifact or creature.
	counted_ptr<CActivatedAbility<CTargetTapUntapCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetTapUntapCardSpell>>(this,
			_T("2"),
			TRUE, FALSE,
			new CardTypeComparer(CardType::Artifact | CardType::Creature, false)));

	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CParadoxEngineCard::CParadoxEngineCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Paradox Engine"), CardType::_LegendaryArtifact, nID,
		_T("5"), AbilityType::Artifact)
{
	// Whenever you cast a spell, untap all nonland permanents you control.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CParadoxEngineCard::BeforeUntap));
	AddAbility(cpAbility.GetPointer());
}

bool CParadoxEngineCard::BeforeUntap(CAbilityAction* pAction) const
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

CPendulumOfPatternsCard::CPendulumOfPatternsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pendulum of Patterns"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters, you gain 3 life.
	AddEnterTrigger(this, &CPendulumOfPatternsCard::BeforeLife);

	// {5}, {T}, Sacrifice this artifact: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("5"), 1));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

bool CPendulumOfPatternsCard::BeforeLife(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 3);
	return true;
}

CPlanarBridgeCard::CPlanarBridgeCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Planar Bridge"), CardType::_LegendaryArtifact, nID,
		_T("6"), AbilityType::Artifact)
	, m_PermanentFilter(_T("a permanent card"), _T("permanent cards"),
		new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment | CardType::_Land | CardType::Planeswalker, false))
{
	// {8}, {T}: Search your library for a permanent card, put it onto the battlefield, then shuffle.
	counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
		::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
			_T("8"), &m_PermanentFilter,
			ZoneId::Battlefield, FALSE, FALSE, FALSE));

	cpAbility->AddTapCost();
	AddAbility(cpAbility.GetPointer());
}

CRenegadeMapCard::CRenegadeMapCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Renegade Map"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// This artifact enters tapped.
	SetIntoPlayTapped();

	// {T}, Sacrifice this artifact: Search your library for a basic land card, reveal it, put it into your hand,
	// then shuffle.
	counted_ptr<CActivatedAbility<CSearchLibrarySpell>> cpAbility(
		::CreateObject<CActivatedAbility<CSearchLibrarySpell>>(this,
			_T(""), CCardFilter::GetFilter(_T("basic lands")),
			ZoneId::Hand, TRUE, FALSE, FALSE));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	AddAbility(cpAbility.GetPointer());
}

CServoSchematicCard::CServoSchematicCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Servo Schematic"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	// When this artifact enters or is put into a graveyard from the battlefield, create a 1/1 colorless Servo
	// artifact creature token.
	AddEnterTrigger(this, &CServoSchematicCard::BeforeServo);

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CServoSchematicCard::BeforeServo));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CServoSchematicCard::BeforeServo(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CUniversalSolventCard::CUniversalSolventCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Universal Solvent"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
{
	// {7}, {T}, Sacrifice this artifact: Destroy target permanent.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("7"),
			new TrueCardComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddTapCost();
	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Vehicles

// A Vehicle: a card with crew support (see CCrewSupport::Find)
struct VehicleComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return CCrewSupport::Find(pCard) != NULL;
	}

	virtual VehicleComparer* Clone() const
	{
		return new VehicleComparer;
	}
};

CAethersphereHarvesterCard::CAethersphereHarvesterCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Aethersphere Harvester"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Flying (in the crewed creature)
	// When this Vehicle enters, you get {E}{E}.
	AddEnterTrigger(this, &CAethersphereHarvesterCard::BeforeEnergy);

	{
		// Pay {E}: This Vehicle gains lifelink until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddEnergyCost(this, 1);
		cpAbility->SetAbilityText(_T("This Vehicle gains lifelink until end of turn."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAethersphereHarvesterCard::BeforeLifelink));
		AddAbility(cpAbility.GetPointer());
	}

	// Crew 1
	m_Crew.AddCrewAbility(1, _T("Aethersphere Harvester (Vehicle)"), 64113);
}

bool CAethersphereHarvesterCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CAethersphereHarvesterCard::BeforeLifelink(CAbilityAction* pAction) const
{
	// Lifelink matters for the creature it is while crewed (and for the card, in case it's crewed later this turn)
	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Lifelink);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	if (GetZoneId() == ZoneId::Battlefield)
		pModifier.ApplyTo((CCard*)this);
	if (GetIsAlsoA())
		pModifier.ApplyTo(GetIsAlsoA());
	return true;
}

CConsulateDreadnoughtCard::CConsulateDreadnoughtCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Consulate Dreadnought"), CardType::Artifact, nID,
		_T("1"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Crew 6
	m_Crew.AddCrewAbility(6, _T("Consulate Dreadnought (Vehicle)"), 64114);
}

CHeartOfKiranCard::CHeartOfKiranCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Heart of Kiran"), CardType::_LegendaryArtifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Flying, vigilance (in the crewed creature)
	// Crew 3
	m_Crew.AddCrewAbility(3, _T("Heart of Kiran (Vehicle)"), 64115);

	// You may remove a loyalty counter from a planeswalker you control rather than pay Heart of Kiran's crew cost.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddAnyCardCounterCost(LOYALTY_COUNTER, -1, 1, CCardFilter::GetFilter(_T("planeswalkers")));
	cpAbility->SetAbilityText(_T("Crew (remove a loyalty counter from a planeswalker you control): this Vehicle becomes an artifact creature until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeartOfKiranCard::BeforeCrew));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CHeartOfKiranCard::BeforeCrew(CAbilityAction* pAction)
{
	m_Crew.Animate(pAction->GetController());
	return true;
}

CIrontreadCrusherCard::CIrontreadCrusherCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Irontread Crusher"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Crew 3
	m_Crew.AddCrewAbility(3, _T("Irontread Crusher (Vehicle)"), 64116);
}

CMobileGarrisonCard::CMobileGarrisonCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Mobile Garrison"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Whenever this Vehicle attacks, untap another target artifact or creature you control. (in the crewed creature)
	// Crew 2
	m_Crew.AddCrewAbility(2, _T("Mobile Garrison (Vehicle)"), 64117);
}

CPeacewalkerColossusCard::CPeacewalkerColossusCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Peacewalker Colossus"), CardType::Artifact, nID,
		_T("3"), AbilityType::Artifact)
	, m_Crew(this)
{
	// {1}{W}: Another target Vehicle you control becomes an artifact creature until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") WHITE_MANA_TEXT,
			new VehicleComparer, FALSE));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPeacewalkerColossusCard::BeforeAnimate));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());

	// Crew 4
	m_Crew.AddCrewAbility(4, _T("Peacewalker Colossus (Vehicle)"), 64118);
}

bool CPeacewalkerColossusCard::BeforeAnimate(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	CCrewSupport* pCrew = CCrewSupport::Find(pCard);
	if (pCrew && pCard->GetZoneId() == ZoneId::Battlefield)
		pCrew->Animate(pAction->GetController());
	return true;
}

CUntetheredExpressCard::CUntetheredExpressCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Untethered Express"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
	, m_Crew(this)
{
	// Trample. Whenever this Vehicle attacks, put a +1/+1 counter on it. (in the crewed creature)
	// Crew 1
	m_Crew.AddCrewAbility(1, _T("Untethered Express (Vehicle)"), 64119);
}

//____________________________________________________________________________
//
// Enchantments

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

// "Revolt - At the beginning of your end step, if a permanent left the battlefield under your control this turn, ..."
template <class T>
static void AddRevoltEndStepTrigger(T* pCard, bool (T::*context)(CTriggeredAbility<>::TriggerContextType&, CNode*) const,
	bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard, NodeId::EndStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(pCard, context));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "When this enchantment leaves the battlefield" (the return of the "exile until" enchantments)
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

// Exiles the card (until the enchantment leaves the battlefield) and remembers it
static void ExileUntilLeaves(CCountedCardContainer_& exiled, CCard* pCard, CPlayer* pByPlayer)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pByPlayer);
	pModifier.ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Exile && !pCard->GetCardType().IsToken())
		exiled.AddCard(pCard, CardPlacement::Top);
}

// Returns the exiled cards to the battlefield under their owners' control
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

CAerialModificationCard::CAerialModificationCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Aerial Modification"), nID,
		_T("4") WHITE_MANA_TEXT,
		Power(+2), Life(+2), CreatureKeyword::Flying)
{
	// Enchant creature or Vehicle. Enchanted creature gets +2/+2 and has flying.
	// Note: an uncrewed Vehicle can't be enchanted (it isn't a creature), so the Vehicle part isn't implemented
}

CAidFromTheCowlCard::CAidFromTheCowlCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Aid from the Cowl"), CardType::GlobalEnchantment, nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, AbilityType::Enchantment)
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CAidFromTheCowlCard::OnSelected))
{
	// Revolt - At the beginning of your end step, if a permanent left the battlefield under your control this turn,
	// reveal the top card of your library. If it's a permanent card, you may put it onto the battlefield. Otherwise,
	// you may put it on the bottom of your library.
	AddRevoltEndStepTrigger(this, &CAidFromTheCowlCard::SetTriggerContext, &CAidFromTheCowlCard::BeforeReveal);
}

bool CAidFromTheCowlCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRevolt(GetController());
}

bool CAidFromTheCowlCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (!HasRevolt(pController) || pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	bool bPermanent = NonlandPermanentCardComparer()(pCard) || pCard->GetCardType().IsLand();

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(bPermanent ? _T("Put %s onto the battlefield") : _T("Put %s on the bottom of your library"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 0;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Leave %s on top of your library"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_Selection.AddSelectionRequest(entries, 1, 1, this, pController, (DWORD)pCard, bPermanent ? 1 : 0);
	return true;
}

void CAidFromTheCowlCard::OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 0 || pCard->GetZoneId() != ZoneId::Library)
				return;

			if (dwContext2)
				pCard->Move(pSelectionPlayer->GetZoneById(ZoneId::Battlefield), pSelectionPlayer, MoveType::Others);
			else
				pCard->Move(pSelectionPlayer->GetZoneById(ZoneId::Library), pSelectionPlayer, MoveType::Others, CardPlacement::Bottom);
			return;
		}
}

CAjanisAidCard::CAjanisAidCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Ajani's Aid"), CardType::GlobalEnchantment, nID,
		_T("2") GREEN_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, you may search your library and/or graveyard for a card named Ajani, Valiant
	// Protector, reveal it, and put it into your hand. If you search your library this way, shuffle.
	AddEnterTrigger(this, &CAjanisAidCard::BeforeSearch);

	// Sacrifice this enchantment: Prevent all combat damage a creature of your choice would deal this turn.
	// Note: the creature is targeted (as Maze of Ith)
	counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
			_T(""),
			Power(+0), Life(+0),
			CreatureKeyword::DealNoCombatDamage, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

bool CAjanisAidCard::BeforeSearch(CAbilityAction* pAction) const
{
	FindNamedCard(pAction->GetController(), _T("Ajani, Valiant Protector"));
	return true;
}

CCaughtInTheBrightsCard::CCaughtInTheBrightsCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Caught in the Brights"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+0), CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
{
	// Enchanted creature can't attack or block.
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);

	// When a Vehicle you control attacks, exile enchanted creature.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCaughtInTheBrightsCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCaughtInTheBrightsCard::BeforeExile));
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
	AddAbility(cpAbility.GetPointer());
}

bool CCaughtInTheBrightsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject subject) const
{
	// The attacking creature of a crewed Vehicle is linked (IsAlsoA) to the Vehicle card
	return pCreature && pCreature->GetIsAlsoOf() && CCrewSupport::Find(pCreature->GetIsAlsoOf()) != NULL;
}

bool CCaughtInTheBrightsCard::BeforeExile(CAbilityAction* pAction) const
{
	CCard* pCreature = GetEnchantedOn();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

CConsulateCrackdownCard::CConsulateCrackdownCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Consulate Crackdown"), CardType::GlobalEnchantment, nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, exile all artifacts your opponents control until this enchantment leaves the
	// battlefield.
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CConsulateCrackdownCard::BeforeExile));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		AddAbility(cpAbility.GetPointer());
	}
	AddLeaveTrigger(this, &CConsulateCrackdownCard::BeforeReturn);
}

bool CConsulateCrackdownCard::BeforeExile(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCountedCardContainer artifacts;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsArtifact())
				artifacts.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	// If the enchantment already left the battlefield, the artifacts aren't exiled
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	for (int i = 0; i < artifacts.GetSize(); ++i)
		ExileUntilLeaves(m_Exiled, artifacts.GetAt(i), pController);
	return true;
}

bool CConsulateCrackdownCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CEfficientConstructionCard::CEfficientConstructionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Efficient Construction"), CardType::GlobalEnchantment, nID,
		_T("3") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast an artifact spell, create a 1/1 colorless Thopter artifact creature token with flying.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEfficientConstructionCard::BeforeThopter));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CEfficientConstructionCard::BeforeThopter(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Thopter (D)"), 55053, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CGontisMachinationsCard::CGontisMachinationsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Gonti's Machinations"), CardType::GlobalEnchantment, nID,
		BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever you lose life for the first time each turn, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CGontisMachinationsCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGontisMachinationsCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Pay {E}{E}, Sacrifice this enchantment: Each opponent loses 3 life. You gain life equal to the life lost this
		// way.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddEnergyCost(this, 2);
		cpAbility->AddSacrificeCost();
		cpAbility->SetAbilityText(_T("Each opponent loses 3 life. You gain life equal to the life lost this way."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGontisMachinationsCard::BeforeDrain));
		cpAbility->AddAbilityTag(AbilityTag::LifeGain);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CGontisMachinationsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, const CPlayer* pPlayer, Life nFromLife, Life nToLife) const
{
	if (nToLife >= nFromLife)
		return false;

	// The life lost this turn is updated before the event: the first loss of the turn is all of it
	return GET_INTEGER(pPlayer->GetLifeLossTakenThisTurn()) == GET_INTEGER(nFromLife - nToLife);
}

bool CGontisMachinationsCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

bool CGontisMachinationsCard::BeforeDrain(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	int nLost = 0;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		int nBefore = GET_INTEGER(pOpponent->GetLife());
		CLifeModifier pModifier = CLifeModifier(Life(-3), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
		nLost += nBefore - GET_INTEGER(pOpponent->GetLife());
	}

	if (nLost > 0)
		GainLife((CCard*)this, pController, nLost);
	return true;
}

CHiddenStockpileCard::CHiddenStockpileCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Hidden Stockpile"), CardType::GlobalEnchantment, nID,
		WHITE_MANA_TEXT BLACK_MANA_TEXT, AbilityType::Enchantment)
{
	// Revolt - At the beginning of your end step, if a permanent left the battlefield under your control this turn,
	// create a 1/1 colorless Servo artifact creature token.
	AddRevoltEndStepTrigger(this, &CHiddenStockpileCard::SetTriggerContext, &CHiddenStockpileCard::BeforeServo);

	// {1}, Sacrifice a creature: Scry 1.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("creatures")));
	cpAbility->SetAbilityText(_T("Scry 1."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHiddenStockpileCard::BeforeScry));
	AddAbility(cpAbility.GetPointer());
}

bool CHiddenStockpileCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRevolt(GetController());
}

bool CHiddenStockpileCard::BeforeServo(CAbilityAction* pAction)
{
	if (!HasRevolt(pAction->GetController()))
		return true;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

bool CHiddenStockpileCard::BeforeScry(CAbilityAction* pAction) const
{
	CScryModifier(GetGame(), 1, (CCard*)this).ApplyTo(pAction->GetController());
	return true;
}

CIceOverCard::CIceOverCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Ice Over"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(+0), Life(+0))
{
	// Enchant artifact or creature. Enchanted permanent doesn't untap during its controller's untap step.
	// (as Dehydration in Eighth Edition)
	m_pChgPwrTghAttrEnchant->GetTargeting()->GetSubjectCardFilter().SetComparer(new CardTypeComparer(CardType::Artifact | CardType::Creature, false));
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);
}

COathOfAjaniCard::COathOfAjaniCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Oath of Ajani"), CardType::GlobalEnchantment | CardType::Legendary, nID,
		GREEN_MANA_TEXT WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When Oath of Ajani enters, put a +1/+1 counter on each creature you control.
	AddEnterTrigger(this, &COathOfAjaniCard::BeforeCounters);

	// Planeswalker spells you cast cost {1} less to cast. (as Etherium Sculptor in Shards of Alara)
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CardTypeComparer(CardType::Planeswalker, false),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

bool COathOfAjaniCard::BeforeCounters(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer creatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < creatures.GetSize(); ++i)
		AddCounters(creatures.GetAt(i), _T("+1/+1"), 1);
	return true;
}

CPiasRevolutionCard::CPiasRevolutionCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Pia's Revolution"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_Selection(pGame, CSelectionSupport::SelectionCallback(this, &CPiasRevolutionCard::OnSelected))
{
	// Whenever a nontoken artifact is put into your graveyard from the battlefield, return that card to your hand
	// unless target opponent has this enchantment deal 3 damage to them.
	// Note: the opponent is chosen automatically (the first one)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CPiasRevolutionCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CPiasRevolutionCard::BeforeChoice));
	AddAbility(cpAbility.GetPointer());
}

bool CPiasRevolutionCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard || pCard->GetCardType().IsToken())
		return false;

	triggerContext.nValue1 = (DWORD)pCard;
	return true;
}

bool CPiasRevolutionCard::BeforeChoice(TriggeredAbility::TriggeredActionType* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return true;

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
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("%s returns %s to their hand"), pController->GetPlayerName(), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 1;
		entry.strText = _T("Take 3 damage");
		entries.push_back(entry);
	}
	m_Selection.AddSelectionRequest(entries, 1, 1, this, pOpponent, (DWORD)pCard, (DWORD)pController);
	return true;
}

void CPiasRevolutionCard::OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	CPlayer* pController = (CPlayer*)dwContext2;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == 1)
			{
				CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::Preventable,
					DamageType::AbilityDamage | DamageType::NonCombatDamage);
				pModifier.ApplyTo(pSelectionPlayer);
			}
			else if (pCard->GetZoneId() == ZoneId::Graveyard)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others, pController);
				pModifier.ApplyTo(pCard);
			}
			return;
		}
}

CSiegeModificationCard::CSiegeModificationCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Siege Modification"), nID,
		_T("1") RED_MANA_TEXT RED_MANA_TEXT,
		Power(+3), Life(+0), CreatureKeyword::FirstStrike)
{
	// Enchant creature or Vehicle. Enchanted creature gets +3/+0 and has first strike.
	// Note: an uncrewed Vehicle can't be enchanted (it isn't a creature), so the Vehicle part isn't implemented
}

CThopterArrestCard::CThopterArrestCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Thopter Arrest"), CardType::GlobalEnchantment, nID,
		_T("2") WHITE_MANA_TEXT, AbilityType::Enchantment)
{
	// When this enchantment enters, exile target artifact or creature an opponent controls until this enchantment
	// leaves the battlefield.
	{
		typedef
			TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
									 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::Creature, false));
		cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CThopterArrestCard::BeforeExile));
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));
		AddAbility(cpAbility.GetPointer());
	}
	AddLeaveTrigger(this, &CThopterArrestCard::BeforeReturn);
}

bool CThopterArrestCard::BeforeExile(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

bool CThopterArrestCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

//____________________________________________________________________________
//
// Sorceries
// Note: the Expertise cards don't implement "You may cast a spell with mana value N or less from your hand without
// paying its mana cost." (the engine can't cast a card from the hand during the resolution of another spell)

// A creature or a Vehicle
struct CreatureOrVehicleComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() || CCrewSupport::Find(pCard) != NULL;
	}

	virtual CreatureOrVehicleComparer* Clone() const
	{
		return new CreatureOrVehicleComparer;
	}
};

// The greatest power among creatures the player controls
static int GreatestPower(const CPlayer* pPlayer)
{
	int nGreatest = 0;
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pBattlefield->GetAt(i));
		if (pCreature && pCreature->GetCardType().IsCreature() && GET_INTEGER(pCreature->GetPower()) > nGreatest)
			nGreatest = GET_INTEGER(pCreature->GetPower());
	}
	return nGreatest;
}

// "Gain control of target ... until end of turn. Untap it. It gains haste until end of turn." (as Act of Treason)
static void SetThreaten(CTargetMoveCardSpell* pSpell)
{
	pSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));

	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier;
	pModifier->GetModifier().SetToAdd(CreatureKeyword::Haste);
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	pSpell->GetTargetModifier().CCreatureModifiers::push_back(pModifier);

	pSpell->SetReturnToPreviousControllerAtNext(NodeId::CleanupStep2);
}

CBaralsExpertiseCard::CBaralsExpertiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Baral's Expertise"), CardType::Sorcery, nID)
{
	// Return up to three target artifacts and/or creatures to their owners' hands.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature, false),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetSubjectCount(1, 3);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CBattleAtTheBridgeCard::CBattleAtTheBridgeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Battle at the Bridge"), CardType::Sorcery, nID)
{
	// Target creature gets -X/-X until end of turn. You gain X life.
	// Note: improvise isn't implemented for this card (its generic mana is X)
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBattleAtTheBridgeCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool CBattleAtTheBridgeCard::BeforeResolution(CAbilityAction* pAction) const
{
	int nX = pAction->GetCostConfigEntry().GetExtraValue();
	if (nX < 0)
		nX = -nX;
	if (nX <= 0)
		return true;

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CPowerModifier pPowerModifier = CPowerModifier(Power(-nX));
		pPowerModifier.ApplyTo(pCreature);
		CLifeModifier pLifeModifier = CLifeModifier(Life(-nX), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pLifeModifier.ApplyTo(pCreature);
	}

	GainLife((CCard*)this, pAction->GetController(), nX);
	return true;
}

CChandrasRevolutionCard::CChandrasRevolutionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chandra's Revolution"), CardType::Sorcery, nID)
{
	// Chandra's Revolution deals 4 damage to target creature. Tap target land. That land doesn't untap during its
	// controller's next untap step.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new CardTypeComparer(CardType::_Land, false), FALSE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CChandrasRevolutionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CChandrasRevolutionCard::BeforeResolution(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-4), (CCard*)this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCreature);
	}

	CCard* pLand = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (pLand && pLand->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
		pTapModifier.ApplyTo(pLand);

		// It doesn't untap during its controller's next untap step: removed at the upkeep of that turn
		CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
			new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
			TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
			CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pLand->GetController());
		pModifier.ApplyTo(pLand);
	}
	return true;
}

CDaringDemolitionCard::CDaringDemolitionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Daring Demolition"), CardType::Sorcery, nID)
{
	// Destroy target creature or Vehicle.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new CreatureOrVehicleComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CDarkIntimationsCard::CDarkIntimationsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Dark Intimations"), CardType::Sorcery, nID)
	, m_SacrificeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CDarkIntimationsCard::OnSacrificeSelected))
	, m_ReturnFilter(_T("a creature or planeswalker card"), _T("creature or planeswalker cards"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
{
	// Each opponent sacrifices a creature or planeswalker of their choice, then discards a card. You return a
	// creature or planeswalker card from your graveyard to your hand, then draw a card.
	// Note: "When you cast a Bolas planeswalker spell, exile this card from your graveyard..." isn't implemented
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDarkIntimationsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDarkIntimationsCard::BeforeResolution(CAbilityAction* pAction)
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
			if (!pCard->GetCardType().IsCreature() && !pCard->GetCardType().IsPlaneswalker())
				continue;

			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
		if (!entries.empty())
			m_SacrificeSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);

		DiscardCards(GetGame(), pOpponent, 1);
	}

	// You return a creature or planeswalker card from your graveyard to your hand
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select a card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		&m_ReturnFilter,						// creature or planeswalker cards
		ZoneId::Hand,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	DrawCards(GetGame(), pController, 1);
	return true;
}

void CDarkIntimationsCard::OnSacrificeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
			return;
		}
}

CDestructiveTamperingCard::CDestructiveTamperingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Destructive Tampering"), CardType::Sorcery, nID)
{
	// Choose one -
	{
		// Destroy target artifact.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT,
				new CardTypeComparer(CardType::Artifact, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Creatures without flying can't block this turn.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("2") RED_MANA_TEXT));

		cpSpell->SetAbilityText(_T("Creatures without flying can't block this turn. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDestructiveTamperingCard::BeforeCantBlock));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CDestructiveTamperingCard::BeforeCantBlock(CAbilityAction* pAction) const
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
			if (pCreature && pCreature->GetCardType().IsCreature() && !pCreature->GetCreatureKeyword()->Flying())
				pModifier.ApplyTo(pCreature);
		}
	}
	return true;
}

CInspiringRoarCard::CInspiringRoarCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Inspiring Roar"), CardType::Sorcery, nID)
{
	// Put a +1/+1 counter on each creature you control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInspiringRoarCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CInspiringRoarCard::BeforeResolution(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer creatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < creatures.GetSize(); ++i)
		AddCounters(creatures.GetAt(i), _T("+1/+1"), 1);
	return true;
}

CKariZevsExpertiseCard::CKariZevsExpertiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Kari Zev's Expertise"), CardType::Sorcery, nID)
{
	// Gain control of target creature or Vehicle until end of turn. Untap it. It gains haste until end of turn.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT RED_MANA_TEXT,
			new CreatureOrVehicleComparer,
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	SetThreaten(cpSpell.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

CPreyUponCard::CPreyUponCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Prey Upon"), CardType::Sorcery, nID)
{
	// Target creature you control fights target creature you don't control.
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPreyUponCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPreyUponCard::BeforeResolution(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCreatureCard* pMine = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	CCreatureCard* pTheirs = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject());
	if (!pMine || !pTheirs || pMine->GetZoneId() != ZoneId::Battlefield || pTheirs->GetZoneId() != ZoneId::Battlefield)
		return true;

	// Each deals damage equal to its power to the other (the powers are taken before any damage)
	int nMine = GET_INTEGER(pMine->GetPower());
	int nTheirs = GET_INTEGER(pTheirs->GetPower());
	if (nMine > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nMine), pMine, PreventableType::Preventable, DamageType::NonCombatDamage);
		pModifier.ApplyTo(pTheirs);
	}
	if (nTheirs > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nTheirs), pTheirs, PreventableType::Preventable, DamageType::NonCombatDamage);
		pModifier.ApplyTo(pMine);
	}
	return true;
}

CResourcefulReturnCard::CResourcefulReturnCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Resourceful Return"), CardType::Sorcery, nID)
{
	// Return target creature card from your graveyard to your hand. If you control an artifact, draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CResourcefulReturnCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CResourcefulReturnCard::BeforeResolution(CAbilityAction* pAction) const
{
	if (CountArtifacts(pAction->GetController()) > 0)
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CReverseEngineerCard::CReverseEngineerCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reverse Engineer"), CardType::Sorcery, nID)
{
	// Improvise. Draw three cards.
	AddImproviseSpells(this, 3, BLUE_MANA_TEXT BLUE_MANA_TEXT, &CReverseEngineerCard::AddReverseEngineerSpell);
}

void CReverseEngineerCard::AddReverseEngineerSpell(LPCTSTR strCost, int nTapped)
{
	counted_ptr<CDrawCardSpell> cpSpell(
		::CreateObject<CDrawCardSpell>(this, AbilityType::Sorcery,
			strCost, 3));

	SetImprovise(cpSpell.GetPointer(), nTapped);
	AddSpell(cpSpell.GetPointer());
}

CRishkarsExpertiseCard::CRishkarsExpertiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rishkar's Expertise"), CardType::Sorcery, nID)
{
	// Draw cards equal to the greatest power among creatures you control.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRishkarsExpertiseCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CRishkarsExpertiseCard::BeforeResolution(CAbilityAction* pAction) const
{
	int nCount = GreatestPower(pAction->GetController());
	if (nCount > 0)
		DrawCards(GetGame(), pAction->GetController(), nCount);
	return true;
}

CSecretSalvageCard::CSecretSalvageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Secret Salvage"), CardType::Sorcery, nID)
{
	// Exile target nonland card from your graveyard. Search your library for any number of cards with the same name
	// as that card, reveal them, put them into your hand, then shuffle.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSecretSalvageCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CSecretSalvageCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Graveyard)
		return true;

	// Note: every card with that name is put into the hand (the search finds all of them)
	CString strName = pTarget->GetCardName(FALSE);
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);

	CCountedCardContainer found;
	for (int i = 0; i < pLibrary->GetSize(); ++i)
		if (pLibrary->GetAt(i)->GetCardName(FALSE) == strName)
			found.AddCard(pLibrary->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others, pController);
	for (int i = 0; i < found.GetSize(); ++i)
		pModifier.ApplyTo(found.GetAt(i));
	pLibrary->Shuffle();
	return true;
}

CSramsExpertiseCard::CSramsExpertiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Sram's Expertise"), CardType::Sorcery, nID)
{
	// Create three 1/1 colorless Servo artifact creature tokens.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT,
			SERVO_TOKEN_NAME, SERVO_TOKEN_ID,
			3));
	AddSpell(cpSpell.GetPointer());
}

CTezzeretsBetrayalCard::CTezzeretsBetrayalCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tezzeret's Betrayal"), CardType::Sorcery, nID)
{
	// Destroy target creature. You may search your library and/or graveyard for a card named Tezzeret, Master of
	// Metal, reveal it, and put it into your hand. If you search your library this way, shuffle.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("3") BLUE_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretsBetrayalCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTezzeretsBetrayalCard::BeforeResolution(CAbilityAction* pAction) const
{
	FindNamedCard(pAction->GetController(), _T("Tezzeret, Master of Metal"));
	return true;
}

CWrangleCard::CWrangleCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Wrangle"), CardType::Sorcery, nID)
{
	// Gain control of target creature with power 4 or less until end of turn. Untap that creature. It gains haste
	// until end of turn.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("1") RED_MANA_TEXT,
			new CreaturePowerComparer<std::less_equal<int>>(4),
			ZoneId::Battlefield, ZoneId::Battlefield, FALSE, MoveType::Others));

	SetThreaten(cpSpell.GetPointer());
	AddSpell(cpSpell.GetPointer());
}

CYahennisExpertiseCard::CYahennisExpertiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Yahenni's Expertise"), CardType::Sorcery, nID)
{
	// All creatures get -3/-3 until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CYahennisExpertiseCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CYahennisExpertiseCard::BeforeResolution(CAbilityAction* pAction) const
{
	CPowerModifier pPowerModifier = CPowerModifier(Power(-3));
	CLifeModifier pLifeModifier = CLifeModifier(Life(-3), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);

	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (pBattlefield->GetAt(i)->GetCardType().IsCreature() && dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i)))
				creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		pPowerModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
		pLifeModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
	}
	return true;
}

//____________________________________________________________________________
//
// Instants

// "It doesn't untap during its controller's next untap step": removed at the upkeep of that turn
static void SkipNextUntap(CGame* pGame, CCard* pCard)
{
	CScheduledCardModifier pModifier = CScheduledCardModifier(pGame,
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pModifier.ApplyTo(pCard);
}

static void PumpCreature(CCard* pCard, int nPower, int nToughness, CreatureKeyword keyword)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	CPowerModifier pPowerModifier = CPowerModifier(Power(nPower));
	pPowerModifier.ApplyTo(pCreature);
	CLifeModifier pLifeModifier = CLifeModifier(Life(nToughness), pCreature, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pCreature);

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(keyword);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);
}

CAlleyEvasionCard::CAlleyEvasionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Alley Evasion"), CardType::Instant, nID)
{
	// Choose one -
	{
		// Target creature you control gets +1/+2 until end of turn.
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
				WHITE_MANA_TEXT,
				Power(+1), Life(+2),
				CreatureKeyword::Null, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Return target creature you control to its owner's hand.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				WHITE_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		AddSpell(cpSpell.GetPointer());
	}
}

CCruelFinalityCard::CCruelFinalityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Cruel Finality"), CardType::Instant, nID)
{
	// Target creature gets -2/-2 until end of turn. Scry 1.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			Power(-2), Life(-2),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCruelFinalityCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CCruelFinalityCard::BeforeResolution(CAbilityAction* pAction) const
{
	CScryModifier(GetGame(), 1, (CCard*)this).ApplyTo(pAction->GetController());
	return true;
}

CDecommissionCard::CDecommissionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Decommission"), CardType::Instant, nID)
{
	// Destroy target artifact or enchantment.
	// Revolt - If a permanent left the battlefield under your control this turn, you gain 3 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("2") WHITE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::_Enchantment, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDecommissionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CDecommissionCard::BeforeResolution(CAbilityAction* pAction) const
{
	if (HasRevolt(pAction->GetController()))
		GainLife((CCard*)this, pAction->GetController(), 3);
	return true;
}

CDeftDismissalCard::CDeftDismissalCard(CGame* pGame, UINT nID)
	: CTargetChgLifeSpellCard(pGame, _T("Deft Dismissal"), CardType::Instant, nID, AbilityType::Instant,
		_T("3") WHITE_MANA_TEXT,
		new AttackingBlockingCreatureComparer,
		FALSE,
		Life(-3),
		PreventableType::Preventable)
{
	// Deft Dismissal deals 3 damage divided as you choose among one, two, or three target attacking or blocking
	// creatures. (as Forked Bolt)
	m_pTargetChgLifeSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	m_pTargetChgLifeSpell->GetTargeting()->SetSubjectCount(1, 3);
	m_pTargetChgLifeSpell->GetTargeting()->SetDistributeValues();
}

CFatalPushCard::CFatalPushCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Fatal Push"), CardType::Instant, nID)
{
	// Destroy target creature if it has mana value 2 or less.
	// Revolt - Destroy that creature if it has mana value 4 or less instead if a permanent left the battlefield under
	// your control this turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(4));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFatalPushCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CFatalPushCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	int nLimit = HasRevolt(pAction->GetController()) ? 4 : 2;
	if ((int)pCard->GetConvertedManaCost() <= nLimit)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CHeroicInterventionCard::CHeroicInterventionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Heroic Intervention"), CardType::Instant, nID)
{
	// Permanents you control gain hexproof and indestructible until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeroicInterventionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHeroicInterventionCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCardKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CardKeyword::Hexproof | CardKeyword::Indestructible);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		pModifier.ApplyTo(pBattlefield->GetAt(i));
	return true;
}

CHighspireInfusionCard::CHighspireInfusionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Highspire Infusion"), CardType::Instant, nID)
{
	// Target creature gets +3/+3 until end of turn. You get {E}{E}.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			Power(+3), Life(+3),
			CreatureKeyword::Null, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHighspireInfusionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHighspireInfusionCard::BeforeResolution(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CHungryFlamesCard::CHungryFlamesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hungry Flames"), CardType::Instant, nID)
{
	// Hungry Flames deals 3 damage to target creature and 2 damage to target player or planeswalker.
	// Note: the second target is a player
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			FALSE_CARD_COMPARER, TRUE, _T("")));

	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHungryFlamesCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHungryFlamesCard::BeforeResolution(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-3), (CCard*)this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCreature);
	}

	CPlayer* pPlayer = (CPlayer*)pDoubleTargetAction->GetTargetGroup2().GetFirstPlayerSubject();
	if (pPlayer)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pPlayer);
	}
	return true;
}

CIllusionistsStratagemCard::CIllusionistsStratagemCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Illusionist's Stratagem"), CardType::Instant, nID)
{
	// Exile up to two target creatures you control, then return those cards to the battlefield under their owner's
	// control. Draw a card.
	// (one spell for one target and another for two targets)
	{
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("3") BLUE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIllusionistsStratagemCard::BeforeOne));
		AddSpell(cpSpell.GetPointer());
	}
	{
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				_T("3") BLUE_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIllusionistsStratagemCard::BeforeTwo));
		AddSpell(cpSpell.GetPointer());
	}
}

void CIllusionistsStratagemCard::Flicker(CCard* pCard, CPlayer* pController) const
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CPlayer* pOwner = pCard->GetOwner();
	CMoveCardModifier pExileModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pController);
	pExileModifier.ApplyTo(pCard);

	if (pCard->GetZoneId() == ZoneId::Exile)
	{
		CMoveCardModifier pReturnModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pOwner);
		pReturnModifier.ApplyTo(pCard);
	}
}

bool CIllusionistsStratagemCard::BeforeOne(CAbilityAction* pAction) const
{
	Flicker(pAction->GetAssociatedCard(), pAction->GetController());
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CIllusionistsStratagemCard::BeforeTwo(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pFirst = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pSecond = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	Flicker(pFirst, pAction->GetController());
	if (pSecond != pFirst)
		Flicker(pSecond, pAction->GetController());

	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CInvigoratedRampageCard::CInvigoratedRampageCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Invigorated Rampage"), CardType::Instant, nID)
{
	// Choose one -
	{
		// Target creature gets +4/+0 and gains trample until end of turn.
		counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
			::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
				_T("1") RED_MANA_TEXT,
				Power(+4), Life(+0),
				CreatureKeyword::Trample, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Two target creatures each get +2/+0 and gain trample until end of turn.
		counted_ptr<CDoubleTargetSpell> cpSpell(
			::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
				_T("1") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				new AnyCreatureComparer, FALSE, _T("")));

		cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CInvigoratedRampageCard::BeforeTwo));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CInvigoratedRampageCard::BeforeTwo(CAbilityAction* pAction) const
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return true;

	CCard* pFirst = (CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject();
	CCard* pSecond = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	PumpCreature(pFirst, +2, +0, CreatureKeyword::Trample);
	if (pSecond != pFirst)
		PumpCreature(pSecond, +2, +0, CreatureKeyword::Trample);
	return true;
}

CLeaveInTheDustCard::CLeaveInTheDustCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Leave in the Dust"), CardType::Instant, nID)
{
	// Return target nonland permanent to its owner's hand. Draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("3") BLUE_MANA_TEXT,
			new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLeaveInTheDustCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CLeaveInTheDustCard::BeforeResolution(CAbilityAction* pAction) const
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CLifecraftersGiftCard::CLifecraftersGiftCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lifecrafter's Gift"), CardType::Instant, nID)
{
	// Put a +1/+1 counter on target creature, then put a +1/+1 counter on each creature you control with a +1/+1
	// counter on it.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("3") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLifecraftersGiftCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CLifecraftersGiftCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pTarget = pAction->GetAssociatedCard();
	if (pTarget && pTarget->GetCardType().IsCreature())
		AddCounters(pTarget, _T("+1/+1"), 1);

	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer creatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (pCard->GetCardType().IsCreature() && pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0)
			creatures.AddCard(pCard, CardPlacement::Top);
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		AddCounters(creatures.GetAt(i), _T("+1/+1"), 1);
	return true;
}

CMetallicRebukeCard::CMetallicRebukeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Metallic Rebuke"), CardType::Instant, nID)
{
	// Improvise. Counter target spell unless its controller pays {3}.
	AddImproviseSpells(this, 2, BLUE_MANA_TEXT, &CMetallicRebukeCard::AddRebukeSpell);
}

void CMetallicRebukeCard::AddRebukeSpell(LPCTSTR strCost, int nTapped)
{
	// (as Mana Leak)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			strCost,
			new TrueCardComparer));

	cpSpell->SetCanBeDenied();
	cpSpell->GetDenialCost().SetManaCost(_T("3"));
	SetImprovise(cpSpell.GetPointer(), nTapped);
	AddSpell(cpSpell.GetPointer());
}

CNaturalObsolescenceCard::CNaturalObsolescenceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Natural Obsolescence"), CardType::Instant, nID)
{
	// Put target artifact on the bottom of its owner's library.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact, false), FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNaturalObsolescenceCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CNaturalObsolescenceCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
		pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Library), pAction->GetController(), MoveType::Others, CardPlacement::Bottom);
	return true;
}

CPerilousPredicamentCard::CPerilousPredicamentCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Perilous Predicament"), CardType::Instant, nID)
	, m_SacrificeSelection(pGame, CSelectionSupport::SelectionCallback(this, &CPerilousPredicamentCard::OnSacrificeSelected))
{
	// Each opponent sacrifices an artifact creature and a nonartifact creature of their choice.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("4") BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPerilousPredicamentCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CPerilousPredicamentCard::BeforeResolution(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		RequestSacrifice(pOpponent, true);
		RequestSacrifice(pOpponent, false);
	}
	return true;
}

void CPerilousPredicamentCard::RequestSacrifice(CPlayer* pOpponent, bool bArtifact)
{
	CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsCreature() || pCard->GetCardType().IsArtifact() != bArtifact)
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Sacrifice %s"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_SacrificeSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);
}

void CPerilousPredicamentCard::OnSacrificeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
			return;
		}
}

CPreciseStrikeCard::CPreciseStrikeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Precise Strike"), CardType::Instant, nID)
{
	// Target creature gets +1/+0 and gains first strike until end of turn.
	counted_ptr<CTargetChgPwrTghAttrSpell> cpSpell(
		::CreateObject<CTargetChgPwrTghAttrSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			Power(+1), Life(+0),
			CreatureKeyword::FirstStrike, CreatureKeyword::Null,
			TRUE, PreventableType::NotPreventable));
	AddSpell(cpSpell.GetPointer());
}

CRenegadesGetawayCard::CRenegadesGetawayCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Renegade's Getaway"), CardType::Instant, nID)
{
	// Target permanent gains indestructible until end of turn. Create a 1/1 colorless Servo artifact creature token.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT,
			new TrueCardComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRenegadesGetawayCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	AddSpell(cpSpell.GetPointer());
}

bool CRenegadesGetawayCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(pCard);
	}

	CTokenCreationModifier pTokenModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pTokenModifier.ApplyTo(pAction->GetController());
	return true;
}

CTakeIntoCustodyCard::CTakeIntoCustodyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Take into Custody"), CardType::Instant, nID)
{
	// Tap target creature. It doesn't untap during its controller's next untap step.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTakeIntoCustodyCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTakeIntoCustodyCard::BeforeResolution(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
	pTapModifier.ApplyTo(pCard);
	SkipNextUntap(GetGame(), pCard);
	return true;
}

CWhirOfInventionCard::CWhirOfInventionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Whir of Invention"), CardType::Instant, nID)
	, m_SearchFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	// Search your library for an artifact card with mana value X or less, put it onto the battlefield, then shuffle.
	// Note: improvise isn't implemented for this card (its generic mana is X)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWhirOfInventionCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CWhirOfInventionCard::BeforeResolution(CAbilityAction* pAction)
{
	int nX = pAction->GetCostConfigEntry().GetExtraValue();
	if (nX < 0)
		nX = -nX;

	m_SearchFilter.SetComparer(new CardTypeComparer(CardType::Artifact, false));
	m_SearchFilter.AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(nX));

	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // select an artifact card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		&m_SearchFilter,						// artifact cards with mana value X or less
		ZoneId::Battlefield,					// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
// Creatures: helpers

// Pays nCount energy if the player has enough
static bool PayEnergy(CCard* pCard, CPlayer* pPlayer, int nCount)
{
	if (pPlayer->GetEnergyCounters() < nCount)
		return false;

	GetEnergy(pCard, pPlayer, -nCount);
	return true;
}

// Exiles the card, then returns it to the battlefield under its owner's control
static void Flicker(CCard* pCard, CPlayer* pByPlayer)
{
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CPlayer* pOwner = pCard->GetOwner();
	CMoveCardModifier pExileModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others, pByPlayer);
	pExileModifier.ApplyTo(pCard);

	if (pCard->GetZoneId() == ZoneId::Exile)
	{
		CMoveCardModifier pReturnModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others, pOwner);
		pReturnModifier.ApplyTo(pCard);
	}
}

// "Whenever this creature attacks, <effect>" with the effect in a resolution callback (bOptional: "you may pay...":
// the callback returns false when the cost can't be paid)
template <class T>
static void AddAttackTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional)
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

// "Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, <effect>"
// (the condition is checked when it triggers and again on resolution)
template <class T>
static void AddRevoltEnterTrigger(T* pCard,
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

// A creature that a crewed Vehicle has become (the creature linked to the Vehicle card)
struct CrewedVehicleComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetIsAlsoOf() && CCrewSupport::Find(pCard->GetIsAlsoOf()) != NULL;
	}

	virtual CrewedVehicleComparer* Clone() const
	{
		return new CrewedVehicleComparer;
	}
};

//____________________________________________________________________________
//
// White creatures

CAeronautAdmiralCard::CAeronautAdmiralCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aeronaut Admiral"), CardType::Creature, CREATURE_TYPE2(Human, Pilot), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(1))
{
	// Vehicles you control have flying.
	// Note: only while they are creatures (an uncrewed Vehicle doesn't need it)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new CrewedVehicleComparer,
			Power(+0), Life(+0), CreatureKeyword::Flying));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());
}

CAethergeodeMinerCard::CAethergeodeMinerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aethergeode Miner"), CardType::Creature, CREATURE_TYPE2(Dwarf, Scout), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
{
	// Whenever this creature attacks, you get {E}{E}.
	AddAttackTrigger(this, &CAethergeodeMinerCard::BeforeEnergy, false);

	// Pay {E}{E}: Exile this creature, then return it to the battlefield under its owner's control.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 2);
	cpAbility->SetAbilityText(_T("Exile this creature, then return it to the battlefield under its owner's control."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAethergeodeMinerCard::BeforeFlicker));
	AddAbility(cpAbility.GetPointer());
}

bool CAethergeodeMinerCard::BeforeEnergy(CAbilityAction* pAction)
{
	GetEnergy(this, pAction->GetController(), 2);
	return true;
}

bool CAethergeodeMinerCard::BeforeFlicker(CAbilityAction* pAction) const
{
	Flicker((CCard*)this, pAction->GetController());
	return true;
}

CAetherInspectorCard::CAetherInspectorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aether Inspector"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CAetherInspectorCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, create a 1/1 colorless Servo artifact creature
	// token.
	AddAttackTrigger(this, &CAetherInspectorCard::BeforeAttack, true);
}

bool CAetherInspectorCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CAetherInspectorCard::BeforeAttack(CAbilityAction* pAction)
{
	if (!PayEnergy(this, pAction->GetController(), 2))
		return false;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

CAirdropAeronautsCard::CAirdropAeronautsCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Airdrop Aeronauts"), CardType::Creature, CREATURE_TYPE2(Dwarf, Scout), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
{
	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, you gain
	// 5 life.
	AddRevoltEnterTrigger(this, &CAirdropAeronautsCard::RevoltContext, &CAirdropAeronautsCard::BeforeLife);
}

bool CAirdropAeronautsCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CAirdropAeronautsCard::BeforeLife(CAbilityAction* pAction)
{
	if (HasRevolt(pAction->GetController()))
		GainLife(this, pAction->GetController(), 5);
	return true;
}

CAudaciousInfiltratorCard::CAudaciousInfiltratorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Audacious Infiltrator"), CardType::Creature, CREATURE_TYPE2(Dwarf, Rogue), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_CanBlockFilter(_T("a nonartifact creature"), _T("nonartifact creatures"),
		new NegateCardComparer(new CardTypeComparer(CardType::Artifact, false)))
{
	// This creature can't be blocked by artifact creatures. (as Elegant Edgecrafters in Kaladesh)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_CanBlockFilter);
}

CBastionEnforcerCard::CBastionEnforcerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bastion Enforcer"), CardType::Creature, CREATURE_TYPE2(Dwarf, Soldier), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
}

CCountlessGearsRenegadeCard::CCountlessGearsRenegadeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Countless Gears Renegade"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, create a
	// 1/1 colorless Servo artifact creature token.
	AddRevoltEnterTrigger(this, &CCountlessGearsRenegadeCard::RevoltContext, &CCountlessGearsRenegadeCard::BeforeServo);
}

bool CCountlessGearsRenegadeCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CCountlessGearsRenegadeCard::BeforeServo(CAbilityAction* pAction)
{
	if (HasRevolt(pAction->GetController()))
	{
		CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CDawnfeatherEagleCard::CDawnfeatherEagleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dawnfeather Eagle"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, creatures you control get +1/+1 and gain vigilance until end of turn.
	AddEnterTrigger(this, &CDawnfeatherEagleCard::BeforePump);
}

bool CDawnfeatherEagleCard::BeforePump(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer creatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsCreature())
			creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +1, +1, CreatureKeyword::Vigilance);
	return true;
}

CDeadeyeHarpoonerCard::CDeadeyeHarpoonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Deadeye Harpooner"), CardType::Creature, CREATURE_TYPE2(Dwarf, Warrior), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, destroy
	// target tapped creature an opponent controls.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TappedComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDeadeyeHarpoonerCard::RevoltContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDeadeyeHarpoonerCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CDeadeyeHarpoonerCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CDeadeyeHarpoonerCard::BeforeDestroy(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && HasRevolt(pAction->GetController()))
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CFelidarGuardianCard::CFelidarGuardianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Felidar Guardian"), CardType::Creature, CREATURE_TYPE2(Cat, Beast), nID,
		_T("3") WHITE_MANA_TEXT, Power(1), Life(4))
{
	// When this creature enters, you may exile another target permanent you control, then return that card to the
	// battlefield under its owner's control.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFelidarGuardianCard::BeforeFlicker));
	AddAbility(cpAbility.GetPointer());
}

bool CFelidarGuardianCard::BeforeFlicker(CAbilityAction* pAction) const
{
	Flicker(pAction->GetAssociatedCard(), pAction->GetController());
	return false;
}

CGhirapurOspreyCard::CGhirapurOspreyCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Ghirapur Osprey"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(2))
{
}

CRestorationSpecialistCard::CRestorationSpecialistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Restoration Specialist"), CardType::Creature, CREATURE_TYPE2(Dwarf, Artificer), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// {W}, Sacrifice this creature: Return up to one target artifact card and up to one target enchantment card from
	// your graveyard to your hand.
	// Note: the cards are chosen on resolution (not targeted)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			WHITE_MANA_TEXT));

	cpAbility->AddSacrificeCost();
	cpAbility->SetAbilityText(_T("Return up to one artifact card and up to one enchantment card from your graveyard to your hand."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRestorationSpecialistCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CRestorationSpecialistCard::BeforeReturn(CAbilityAction* pAction) const
{
	LPCTSTR filters[] = { _T("artifacts"), _T("enchantments") };
	for (int i = 0; i < 2; ++i)
	{
		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // select up to one card
			CZoneModifier::RoleType::PrimaryPlayer,	// select by
			CZoneModifier::RoleType::AllPlayers,	// reveal to
			CCardFilter::GetFilter(filters[i]),		// artifact / enchantment cards
			ZoneId::Hand,							// if selected, move cards to
			CZoneModifier::RoleType::PrimaryPlayer, // select by this player
			CardPlacement::Top,
			MoveType::Others,						// move type
			CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CSolemnRecruitCard::CSolemnRecruitCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Solemn Recruit"), CardType::Creature, CREATURE_TYPE2(Dwarf, Warrior), nID,
		_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// Revolt - At the beginning of your end step, if a permanent left the battlefield under your control this turn,
	// put a +1/+1 counter on this creature.
	AddRevoltEndStepTrigger(this, &CSolemnRecruitCard::SetTriggerContext, &CSolemnRecruitCard::BeforeCounter);
}

bool CSolemnRecruitCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return HasRevolt(GetController());
}

bool CSolemnRecruitCard::BeforeCounter(CAbilityAction* pAction)
{
	if (HasRevolt(pAction->GetController()))
		AddCounters(this, _T("+1/+1"), 1);
	return true;
}

// An Aura, Equipment, or Vehicle card (Sram, Senior Edificer)
struct AuraEquipmentVehicleComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return (pCard->GetCardType() & (CardType::_Aura | CardType::Equipment)).Any() || CCrewSupport::Find(pCard) != NULL;
	}

	virtual AuraEquipmentVehicleComparer* Clone() const
	{
		return new AuraEquipmentVehicleComparer;
	}
};

CSramSeniorEdificerCard::CSramSeniorEdificerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sram, Senior Edificer"), CardType::_LegendaryCreature, CREATURE_TYPE2(Dwarf, Advisor), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever you cast an Aura, Equipment, or Vehicle spell, draw a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AuraEquipmentVehicleComparer);
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Enters with counters

CEntersWithCountersCreatureCard::CEntersWithCountersCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType,
	const CreatureType& creatureType, UINT uID, LPCTSTR strCostText, Power nPower, Life nToughness, int nCounters, bool bRevolt)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CEntersWithCountersCreatureCard::OnZoneChanged))
	, m_nCounters(nCounters)
	, m_bRevolt(bRevolt)
{
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CEntersWithCountersCreatureCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this || moveType == MoveType::Phasing)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield &&
		(!m_bRevolt || HasRevolt(GetController())))
		AddCounters(this, _T("+1/+1"), m_nCounters);
}

//____________________________________________________________________________
//
// Green creatures

CAetherHerderCard::CAetherHerderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aether Herder"), CardType::Creature, CREATURE_TYPE3(Elf, Artificer, Druid), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CAetherHerderCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, create a 1/1 colorless Servo artifact creature
	// token.
	AddAttackTrigger(this, &CAetherHerderCard::BeforeAttack, true);
}

bool CAetherHerderCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CAetherHerderCard::BeforeAttack(CAbilityAction* pAction)
{
	if (!PayEnergy(this, pAction->GetController(), 2))
		return false;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

CAetherstreamLeopardCard::CAetherstreamLeopardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aetherstream Leopard"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, you get {E}.
	AddEnterTrigger(this, &CAetherstreamLeopardCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}. If you do, it gets +2/+0 until end of turn.
	AddAttackTrigger(this, &CAetherstreamLeopardCard::BeforeAttack, true);
}

bool CAetherstreamLeopardCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

bool CAetherstreamLeopardCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 1))
		return false;

	PumpCreature(this, +2, +0, CreatureKeyword::Null);
	return false;
}

CAetherwindBaskerCard::CAetherwindBaskerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aetherwind Basker"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(7))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Whenever this creature enters or attacks, you get {E} for each creature you control.
	AddEnterTrigger(this, &CAetherwindBaskerCard::BeforeEnterEnergy);
	AddAttackTrigger(this, &CAetherwindBaskerCard::BeforeAttackEnergy, false);

	// Pay {E}: This creature gets +1/+1 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 1);
	cpAbility->SetAbilityText(_T("This creature gets +1/+1 until end of turn."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAetherwindBaskerCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CAetherwindBaskerCard::BeforeEnterEnergy(CAbilityAction* pAction) const
{
	int nCreatures = CCardFilter::GetFilter(_T("creatures"))->CountIncluded(pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nCreatures > 0)
		GetEnergy((CCard*)this, pAction->GetController(), nCreatures);
	return true;
}

bool CAetherwindBaskerCard::BeforeAttackEnergy(CAbilityAction* pAction)
{
	return BeforeEnterEnergy(pAction);
}

bool CAetherwindBaskerCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1, CreatureKeyword::Null);
	return true;
}

CAjanisComradeCard::CAjanisComradeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ajani's Comrade"), CardType::Creature, CREATURE_TYPE2(Elf, Soldier), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// At the beginning of combat on your turn, if you control an Ajani planeswalker, put a +1/+1 counter on this
	// creature.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAjanisComradeCard::BeforeCombat));
	AddAbility(cpAbility.GetPointer());
}

bool CAjanisComradeCard::BeforeCombat(CAbilityAction* pAction)
{
	PlaneswalkerTypeComparer ajani(PlaneswalkerType::Ajani);
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (ajani(pBattlefield->GetAt(i)))
		{
			AddCounters(this, _T("+1/+1"), 1);
			break;
		}
	return true;
}

CDruidOfTheCowlCard::CDruidOfTheCowlCard(CGame* pGame, UINT nID)
	: CManaProductionTCreatureCard(pGame, _T("Druid of the Cowl"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3),
		GREEN_MANA_TEXT)
{
	// {T}: Add {G}.
}

CGreenbeltRampagerCard::CGreenbeltRampagerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Greenbelt Rampager"), CardType::Creature, CREATURE_TYPE(Elephant), nID,
		GREEN_MANA_TEXT, Power(3), Life(4))
{
	// When this creature enters, pay {E}{E}. If you can't, return this creature to its owner's hand and you get {E}.
	AddEnterTrigger(this, &CGreenbeltRampagerCard::BeforeEnergy);
}

bool CGreenbeltRampagerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	if (PayEnergy((CCard*)this, pController, 2))
		return true;

	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pController);
		pModifier.ApplyTo((CCard*)this);
	}
	GetEnergy((CCard*)this, pController, 1);
	return true;
}

CGreenwheelLiberatorCard::CGreenwheelLiberatorCard(CGame* pGame, UINT nID)
	: CEntersWithCountersCreatureCard(pGame, _T("Greenwheel Liberator"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(1), 2, true)
{
	// Revolt - This creature enters with two +1/+1 counters on it if a permanent left the battlefield under your
	// control this turn.
}

CHiddenHerbalistsCard::CHiddenHerbalistsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hidden Herbalists"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, add
	// {G}{G}.
	AddRevoltEnterTrigger(this, &CHiddenHerbalistsCard::RevoltContext, &CHiddenHerbalistsCard::BeforeMana);
}

bool CHiddenHerbalistsCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CHiddenHerbalistsCard::BeforeMana(CAbilityAction* pAction)
{
	if (HasRevolt(pAction->GetController()))
	{
		CManaPoolModifier pModifier = CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(GREEN_MANA_TEXT GREEN_MANA_TEXT));
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CLifecraftCavalryCard::CLifecraftCavalryCard(CGame* pGame, UINT nID)
	: CEntersWithCountersCreatureCard(pGame, _T("Lifecraft Cavalry"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4), 2, true)
{
	GetCreatureKeyword()->AddTrample(FALSE);

	// Revolt - This creature enters with two +1/+1 counters on it if a permanent left the battlefield under your
	// control this turn.
}

CNarnamRenegadeCard::CNarnamRenegadeCard(CGame* pGame, UINT nID)
	: CEntersWithCountersCreatureCard(pGame, _T("Narnam Renegade"), CardType::Creature, CREATURE_TYPE2(Elf, Warrior), nID,
		GREEN_MANA_TEXT, Power(1), Life(2), 1, true)
{
	GetCardKeyword()->AddDeathtouch(FALSE);

	// Revolt - This creature enters with a +1/+1 counter on it if a permanent left the battlefield under your control
	// this turn.
}

CPeemaAetherSeerCard::CPeemaAetherSeerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Peema Aether-Seer"), CardType::Creature, CREATURE_TYPE2(Elf, Druid), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you get an amount of {E} equal to the greatest power among creatures you control.
	AddEnterTrigger(this, &CPeemaAetherSeerCard::BeforeEnergy);

	// Note: "Pay {E}{E}{E}: Target creature blocks this turn if able." isn't implemented (the engine doesn't have
	// "must block")
}

bool CPeemaAetherSeerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	int nEnergy = GreatestPower(pAction->GetController());
	if (nEnergy > 0)
		GetEnergy((CCard*)this, pAction->GetController(), nEnergy);
	return true;
}

CRidgescaleTuskerCard::CRidgescaleTuskerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ridgescale Tusker"), CardType::Creature, CREATURE_TYPE2(Pangolin, Beast), nID,
		_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(5))
{
	// When this creature enters, put a +1/+1 counter on each other creature you control.
	AddEnterTrigger(this, &CRidgescaleTuskerCard::BeforeCounters);
}

bool CRidgescaleTuskerCard::BeforeCounters(CAbilityAction* pAction) const
{
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer creatures;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i) != this && pBattlefield->GetAt(i)->GetCardType().IsCreature())
			creatures.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < creatures.GetSize(); ++i)
		AddCounters(creatures.GetAt(i), _T("+1/+1"), 1);
	return true;
}

CScroungingBandarCard::CScroungingBandarCard(CGame* pGame, UINT nID)
	: CEntersWithCountersCreatureCard(pGame, _T("Scrounging Bandar"), CardType::Creature, CREATURE_TYPE2(Cat, Monkey), nID,
		_T("1") GREEN_MANA_TEXT, Power(0), Life(0), 2, false)
	, m_CountSelection(pGame, CSelectionSupport::SelectionCallback(this, &CScroungingBandarCard::OnCountSelected))
{
	// This creature enters with two +1/+1 counters on it.
	// At the beginning of your upkeep, you may move any number of +1/+1 counters from this creature onto another
	// target creature.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CScroungingBandarCard::BeforeMove));
	AddAbility(cpAbility.GetPointer());
}

bool CScroungingBandarCard::BeforeMove(CAbilityAction* pAction)
{
	CCard* pTarget = pAction->GetAssociatedCard();
	int nCounters = GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount();
	if (!pTarget || pTarget->GetZoneId() != ZoneId::Battlefield || GetZoneId() != ZoneId::Battlefield || nCounters <= 0)
		return false;

	std::vector<SelectionEntry> entries;
	for (int n = nCounters; n >= 0; --n)
	{
		SelectionEntry entry;
		entry.dwContext = (DWORD)n;
		entry.strText.Format(_T("Move %d +1/+1 counter%s to %s"), n, n == 1 ? _T("") : _T("s"), pTarget->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_CountSelection.AddSelectionRequest(entries, 1, 1, this, pAction->GetController(), (DWORD)pTarget);
	return false;
}

void CScroungingBandarCard::OnCountSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pTarget = (CCard*)dwContext1;
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			int n = (int)it->dwContext;
			if (n <= 0 || GetZoneId() != ZoneId::Battlefield || pTarget->GetZoneId() != ZoneId::Battlefield)
				return;

			CCardCounterModifier pRemoveModifier = CCardCounterModifier(_T("+1/+1"), -n);
			pRemoveModifier.ApplyTo(this);
			AddCounters(pTarget, _T("+1/+1"), n);
			return;
		}
}

CSilkweaverEliteCard::CSilkweaverEliteCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Silkweaver Elite"), CardType::Creature, CREATURE_TYPE2(Elf, Archer), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddReach(FALSE);

	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, draw a
	// card.
	AddRevoltEnterTrigger(this, &CSilkweaverEliteCard::RevoltContext, &CSilkweaverEliteCard::BeforeDraw);
}

bool CSilkweaverEliteCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CSilkweaverEliteCard::BeforeDraw(CAbilityAction* pAction)
{
	if (HasRevolt(pAction->GetController()))
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

//____________________________________________________________________________
//
// Improvise for creature cards: the creature spell of the card has the full cost; these spells have N less generic
// mana and tap N artifacts, and put the creature onto the battlefield (as Delve in Gurmag Angler, Fate Reforged)
static void AddImproviseCreatureSpells(CCard* pCard, int nGeneric, LPCTSTR strColored)
{
	for (int nTapped = 1; nTapped <= nGeneric; ++nTapped)
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(pCard, AbilityType::Creature,
				MakeCost(nGeneric - nTapped, strColored)));

		cpSpell->SetToZoneIfSuccess(ZoneId::Battlefield, TRUE);
		SetImprovise(cpSpell.GetPointer(), nTapped);
		pCard->AddSpell(cpSpell.GetPointer());
	}
}

// Red creatures

CAetherChaserCard::CAetherChaserCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aether Chaser"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CAetherChaserCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, create a 1/1 colorless Servo artifact creature
	// token.
	AddAttackTrigger(this, &CAetherChaserCard::BeforeAttack, true);
}

bool CAetherChaserCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CAetherChaserCard::BeforeAttack(CAbilityAction* pAction)
{
	if (!PayEnergy(this, pAction->GetController(), 2))
		return false;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

CEmbraalGearSmasherCard::CEmbraalGearSmasherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Embraal Gear-Smasher"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	// {T}, Sacrifice an artifact: This creature deals 2 damage to each opponent.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetAbilityText(_T("This creature deals 2 damage to each opponent."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmbraalGearSmasherCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CEmbraalGearSmasherCard::BeforeDamage(CAbilityAction* pAction) const
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-2), (CCard*)this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

CEnragedGiantCard::CEnragedGiantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Enraged Giant"), CardType::Creature, CREATURE_TYPE(Giant), nID,
		_T("5") RED_MANA_TEXT, Power(4), Life(4))
{
	// Improvise. Trample, haste
	AddImproviseCreatureSpells(this, 5, RED_MANA_TEXT);
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);
}

CFreejamRegentCard::CFreejamRegentCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Freejam Regent"), CardType::Creature, CREATURE_TYPE2(Cat, Dragon), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	// Improvise. Flying
	AddImproviseCreatureSpells(this, 4, RED_MANA_TEXT RED_MANA_TEXT);

	// {1}{R}: This creature gets +2/+0 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this,
			_T("1") RED_MANA_TEXT,
			Power(+2), Life(+0)));
	AddAbility(cpAbility.GetPointer());
}

CFrontlineRebelCard::CFrontlineRebelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frontline Rebel"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(3))
{
	// This creature attacks each combat if able.
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);
}

CKariZevSkyshipRaiderCard::CKariZevSkyshipRaiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Kari Zev, Skyship Raider"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Pirate), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(3))
{
	// First strike, menace
	GetCreatureKeyword()->AddFirstStrike(FALSE);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Note: "Whenever Kari Zev attacks, create Ragavan, a legendary 2/1 red Monkey creature token. Ragavan enters
	// tapped and attacking. Exile that token at end of combat." isn't implemented (a token can't enter attacking)
}

CLathnuSailbackCard::CLathnuSailbackCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lathnu Sailback"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		_T("4") RED_MANA_TEXT, Power(5), Life(4))
{
}

CLightningRunnerCard::CLightningRunnerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lightning Runner"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddDoubleStrike(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Whenever this creature attacks, you get {E}{E}, then you may pay eight {E}. If you pay, untap all creatures you
	// control, and after this phase, there is an additional combat phase.
	// Note: only the energy is implemented: an additional combat phase can't be added from a triggered ability
	AddAttackTrigger(this, &CLightningRunnerCard::BeforeAttack, false);
}

bool CLightningRunnerCard::BeforeAttack(CAbilityAction* pAction)
{
	GetEnergy(this, pAction->GetController(), 2);
	return true;
}

CRavenousIntruderCard::CRavenousIntruderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ravenous Intruder"), CardType::Creature, CREATURE_TYPE(Gremlin), nID,
		_T("1") RED_MANA_TEXT, Power(1), Life(2))
{
	// Sacrifice an artifact: This creature gets +2/+2 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetAbilityText(_T("This creature gets +2/+2 until end of turn."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRavenousIntruderCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CRavenousIntruderCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +2, CreatureKeyword::Null);
	return true;
}

CRecklessRacerCard::CRecklessRacerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reckless Racer"), CardType::Creature, CREATURE_TYPE2(Human, Pilot), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// Whenever this creature becomes tapped, you may discard a card. If you do, draw a card.
	typedef
		TTriggeredAbility< CTriggeredDrawCardAbility, CWhenSelfOrientationChanged,
						   CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetTapEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetDiscardResolutionCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetDrawCount(1);
	AddAbility(cpAbility.GetPointer());
}

CScrapperChampionCard::CScrapperChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scrapper Champion"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") RED_MANA_TEXT, Power(2), Life(2))
{
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CScrapperChampionCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, put a +1/+1 counter on it.
	AddAttackTrigger(this, &CScrapperChampionCard::BeforeAttack, true);
}

bool CScrapperChampionCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CScrapperChampionCard::BeforeAttack(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || !PayEnergy(this, pAction->GetController(), 2))
		return false;

	AddCounters(this, _T("+1/+1"), 1);
	return false;
}

CSweatworksBrawlerCard::CSweatworksBrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sweatworks Brawler"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// Improvise. Menace
	AddImproviseCreatureSpells(this, 3, RED_MANA_TEXT);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
}

//____________________________________________________________________________
//
// Black creatures

CAetherPoisonerCard::CAetherPoisonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aether Poisoner"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	GetCardKeyword()->AddDeathtouch(FALSE);

	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CAetherPoisonerCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, create a 1/1 colorless Servo artifact creature
	// token.
	AddAttackTrigger(this, &CAetherPoisonerCard::BeforeAttack, true);
}

bool CAetherPoisonerCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CAetherPoisonerCard::BeforeAttack(CAbilityAction* pAction)
{
	if (!PayEnergy(this, pAction->GetController(), 2))
		return false;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

CAlleyStranglerCard::CAlleyStranglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Alley Strangler"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Rogue), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace
}

CDefiantSalvagerCard::CDefiantSalvagerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Defiant Salvager"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Artificer), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_SacrificeFilter(_T("an artifact or creature"), _T("artifacts or creatures"), new CardTypeComparer(CardType::Artifact | CardType::Creature, false))
{
	// Sacrifice an artifact or creature: Put a +1/+1 counter on this creature. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDefiantSalvagerCard::BeforeCounter));
	SetAsSorcery(cpAbility.GetPointer());
	AddAbility(cpAbility.GetPointer());
}

bool CDefiantSalvagerCard::BeforeCounter(CAbilityAction* pAction)
{
	AddCounters(this, _T("+1/+1"), 1);
	return true;
}

CFenHaulerCard::CFenHaulerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fen Hauler"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("6") BLACK_MANA_TEXT, Power(5), Life(5))
	, m_CanBlockFilter(_T("a nonartifact creature"), _T("nonartifact creatures"),
		new NegateCardComparer(new CardTypeComparer(CardType::Artifact, false)))
{
	// Improvise
	AddImproviseCreatureSpells(this, 6, BLACK_MANA_TEXT);

	// This creature can't be blocked by artifact creatures.
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_CanBlockFilter);
}

CFoundryHornetCard::CFoundryHornetCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Foundry Hornet"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, if you control a creature with a +1/+1 counter on it, creatures your opponents
	// control get -1/-1 until end of turn.
	// Note: the condition is checked on resolution
	AddEnterTrigger(this, &CFoundryHornetCard::BeforeWeaken);
}

bool CFoundryHornetCard::BeforeWeaken(CAbilityAction* pAction) const
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);
	bool bCounter = false;
	for (int i = 0; i < pBattlefield->GetSize() && !bCounter; ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		bCounter = pCard->GetCardType().IsCreature() && pCard->GetCounterContainer()->GetCounter(_T("+1/+1"))->GetCount() > 0;
	}
	if (!bCounter)
		return true;

	CCountedCardContainer creatures;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pController)
			continue;

		CZone* pZone = pOpponent->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pZone->GetSize(); ++i)
			if (pZone->GetAt(i)->GetCardType().IsCreature())
				creatures.AddCard(pZone->GetAt(i), CardPlacement::Top);
	}

	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), -1, -1, CreatureKeyword::Null);
	return true;
}

CFourthBridgeProwlerCard::CFourthBridgeProwlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fourth Bridge Prowler"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		BLACK_MANA_TEXT, Power(1), Life(1))
{
	// When this creature enters, you may have target creature get -1/-1 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(-1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::NotDealingDamage);
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CGiftedAetherbornCard::CGiftedAetherbornCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gifted Aetherborn"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Vampire), nID,
		BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Deathtouch, lifelink
	GetCardKeyword()->AddDeathtouch(FALSE);
	GetCardKeyword()->AddLifelink(FALSE);
}

CGlintSleeveSiphonerCard::CGlintSleeveSiphonerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Glint-Sleeve Siphoner"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);	// Menace

	// Whenever this creature enters or attacks, you get {E}.
	AddEnterTrigger(this, &CGlintSleeveSiphonerCard::BeforeEnterEnergy);
	AddAttackTrigger(this, &CGlintSleeveSiphonerCard::BeforeAttackEnergy, false);

	// At the beginning of your upkeep, you may pay {E}{E}. If you do, you draw a card and you lose 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGlintSleeveSiphonerCard::BeforeUpkeep));
	AddAbility(cpAbility.GetPointer());
}

bool CGlintSleeveSiphonerCard::BeforeEnterEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 1);
	return true;
}

bool CGlintSleeveSiphonerCard::BeforeAttackEnergy(CAbilityAction* pAction)
{
	return BeforeEnterEnergy(pAction);
}

bool CGlintSleeveSiphonerCard::BeforeUpkeep(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (!PayEnergy(this, pController, 2))
		return false;

	DrawCards(GetGame(), pController, 1);
	CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pController);
	return false;
}

CHeraldOfAnguishCard::CHeraldOfAnguishCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Herald of Anguish"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(5))
{
	// Improvise. Flying
	AddImproviseCreatureSpells(this, 5, BLACK_MANA_TEXT BLACK_MANA_TEXT);

	{
		// At the beginning of your end step, each opponent discards a card.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHeraldOfAnguishCard::BeforeDiscard));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}, Sacrifice an artifact: Target creature gets -2/-2 until end of turn.
		counted_ptr<CActivatedAbility<CTargetChgPwrTghAttrSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgPwrTghAttrSpell>>(this,
				_T("1") BLACK_MANA_TEXT,
				Power(-2), Life(-2),
				CreatureKeyword::Null, CreatureKeyword::Null,
				TRUE, PreventableType::NotPreventable));

		cpAbility->GetCost().AddSacrificeCardCost(1, CCardFilter::GetFilter(_T("artifacts")));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHeraldOfAnguishCard::BeforeDiscard(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent != pAction->GetController())
			DiscardCards(GetGame(), pOpponent, 1);
	}
	return true;
}

CIroncladRevolutionaryCard::CIroncladRevolutionaryCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ironclad Revolutionary"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Artificer), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(4), Life(4))
{
	// When this creature enters, you may sacrifice an artifact. If you do, put two +1/+1 counters on this creature
	// and each opponent loses 2 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetSacrificeResolutionCost(1, CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIroncladRevolutionaryCard::BeforeSacrifice));
	AddAbility(cpAbility.GetPointer());
}

bool CIroncladRevolutionaryCard::BeforeSacrifice(CAbilityAction* pAction)
{
	AddCounters(this, _T("+1/+1"), 2);

	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pOpponent);
	}
	return true;
}

CMidnightEntourageCard::CMidnightEntourageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Midnight Entourage"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Rogue), nID,
		_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(3), Life(3))
{
	{
		// Other Aetherborn you control get +1/+1. (as Veteran Armorsmith in M10)
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new NegateCardComparer(new SpecificCardComparer(this)),
				Power(+1), Life(+1)));

		cpAbility->GetEnchantmentCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Aetherborn), false));
		cpAbility->GetEnchantmentCardFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature or another Aetherborn you control dies, you draw a card and you lose 1 life.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Aetherborn), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMidnightEntourageCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMidnightEntourageCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CNightMarketAeronautCard::CNightMarketAeronautCard(CGame* pGame, UINT nID)
	: CEntersWithCountersCreatureCard(pGame, _T("Night Market Aeronaut"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Warrior), nID,
		_T("3") BLACK_MANA_TEXT, Power(2), Life(2), 1, true)
{
	GetCreatureKeyword()->AddFlying(FALSE);

	// Revolt - This creature enters with a +1/+1 counter on it if a permanent left the battlefield under your control
	// this turn.
}

CSlyRequisitionerCard::CSlyRequisitionerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sly Requisitioner"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("4") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// Improvise
	AddImproviseCreatureSpells(this, 4, BLACK_MANA_TEXT);

	// Whenever a nontoken artifact you control is put into a graveyard from the battlefield, create a 1/1 colorless
	// Servo artifact creature token.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSlyRequisitionerCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSlyRequisitionerCard::BeforeServo));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CSlyRequisitionerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return pCard && !pCard->GetCardType().IsToken();
}

bool CSlyRequisitionerCard::BeforeServo(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CVengefulRebelCard::CVengefulRebelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vengeful Rebel"), CardType::Creature, CREATURE_TYPE2(Aetherborn, Warrior), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(2))
{
	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, target
	// creature an opponent controls gets -3/-3 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CVengefulRebelCard::RevoltContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVengefulRebelCard::BeforeWeaken));
	AddAbility(cpAbility.GetPointer());
}

bool CVengefulRebelCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CVengefulRebelCard::BeforeWeaken(CAbilityAction* pAction) const
{
	if (HasRevolt(pAction->GetController()))
		PumpCreature(pAction->GetAssociatedCard(), -3, -3, CreatureKeyword::Null);
	return false;
}

CYahenniUndyingPartisanCard::CYahenniUndyingPartisanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Yahenni, Undying Partisan"), CardType::_LegendaryCreature, CREATURE_TYPE2(Aetherborn, Vampire), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_SacrificeFilter(_T("another creature"), _T("other creatures"), new AnyCreatureComparer)
{
	GetCreatureKeyword()->AddHaste(FALSE);
	m_SacrificeFilter.AddNegateComparer(new SpecificCardComparer(this));

	{
		// Whenever a creature an opponent controls dies, put a +1/+1 counter on Yahenni.
		typedef
			TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetFromOpponentsOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetCardModifiers().push_back(new CCardCounterModifier(_T("+1/+1"), +1));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Sacrifice another creature: Yahenni gains indestructible until end of turn.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddSacrificeCardCost(1, &m_SacrificeFilter);
		cpAbility->SetAbilityText(_T("Yahenni gains indestructible until end of turn."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CYahenniUndyingPartisanCard::BeforeIndestructible));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CYahenniUndyingPartisanCard::BeforeIndestructible(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier;
		pModifier.GetModifier().SetToAdd(CardKeyword::Indestructible);
		pModifier.GetModifier().SetOneTurnOnly(TRUE);
		pModifier.ApplyTo(this);
	}
	return true;
}

//____________________________________________________________________________
//
// Blue creatures

CAetherSwooperCard::CAetherSwooperCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aether Swooper"), CardType::Creature, CREATURE_TYPE2(Vedalken, Artificer), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(2))
{
	// When this creature enters, you get {E}{E}.
	AddEnterTrigger(this, &CAetherSwooperCard::BeforeEnergy);

	// Whenever this creature attacks, you may pay {E}{E}. If you do, create a 1/1 colorless Servo artifact creature
	// token.
	AddAttackTrigger(this, &CAetherSwooperCard::BeforeAttack, true);
}

bool CAetherSwooperCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

bool CAetherSwooperCard::BeforeAttack(CAbilityAction* pAction)
{
	if (!PayEnergy(this, pAction->GetController(), 2))
		return false;

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), SERVO_TOKEN_NAME, SERVO_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return false;
}

CAethertideWhaleCard::CAethertideWhaleCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aethertide Whale"), CardType::Creature, CREATURE_TYPE(Whale), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(6), Life(4))
{
	// When this creature enters, you get six {E}.
	AddEnterTrigger(this, &CAethertideWhaleCard::BeforeEnergy);

	// Pay {E}{E}{E}{E}: Return this creature to its owner's hand.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 4);
	cpAbility->SetAbilityText(_T("Return this creature to its owner's hand."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAethertideWhaleCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CAethertideWhaleCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 6);
	return true;
}

bool CAethertideWhaleCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(this);
	}
	return true;
}

CBaralChiefOfComplianceCard::CBaralChiefOfComplianceCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Baral, Chief of Compliance"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// Instant and sorcery spells you cast cost {1} less to cast. (as Etherium Sculptor in Shards of Alara)
	counted_ptr<CConsLessManaEnchantment> cpAbility(
		::CreateObject<CConsLessManaEnchantment>(this,
			new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
			_T("1")));

	cpAbility->SetAffectControllerCardsOnly();
	AddAbility(cpAbility.GetPointer());

	// Note: "Whenever a spell or ability you control counters a spell, you may draw a card. If you do, discard a
	// card." isn't implemented (the engine has no event for a countered spell)
}

CBastionInventorCard::CBastionInventorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bastion Inventor"), CardType::Creature, CREATURE_TYPE2(Vedalken, Artificer), nID,
		_T("5") BLUE_MANA_TEXT, Power(4), Life(4))
{
	// Improvise. Hexproof
	AddImproviseCreatureSpells(this, 5, BLUE_MANA_TEXT);
	GetCardKeyword()->AddHexproof(FALSE);
}

CDispersalTechnicianCard::CDispersalTechnicianCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dispersal Technician"), CardType::Creature, CREATURE_TYPE2(Vedalken, Artificer), nID,
		_T("4") BLUE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, you may return target artifact to its owner's hand.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDispersalTechnicianCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CDispersalTechnicianCard::BeforeReturn(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CHinterlandDrakeCard::CHinterlandDrakeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Hinterland Drake"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(3))
	, m_CanBlockFilter(_T("a nonartifact creature"), _T("nonartifact creatures"),
		new NegateCardComparer(new CardTypeComparer(CardType::Artifact, false)))
{
	// This creature can't block artifact creatures. (it can block only the creatures of the filter)
	GetCreatureKeyword()->AddCantBlock(FALSE, &m_CanBlockFilter);
}

CSalvageScuttlerCard::CSalvageScuttlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Salvage Scuttler"), CardType::Creature, CREATURE_TYPE(Crab), nID,
		_T("4") BLUE_MANA_TEXT, Power(4), Life(4))
	, m_ArtifactSelection(pGame, CSelectionSupport::SelectionCallback(this, &CSalvageScuttlerCard::OnArtifactSelected))
{
	// Whenever this creature attacks, return an artifact you control to its owner's hand.
	AddAttackTrigger(this, &CSalvageScuttlerCard::BeforeAttack, false);
}

bool CSalvageScuttlerCard::BeforeAttack(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pBattlefield = pController->GetZoneById(ZoneId::Battlefield);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsArtifact())
			continue;

		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Return %s to its owner's hand"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	if (!entries.empty())
		m_ArtifactSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CSalvageScuttlerCard::OnArtifactSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
			{
				CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others, pSelectionPlayer);
				pModifier.ApplyTo(pCard);
			}
			return;
		}
}

CShieldedAetherThiefCard::CShieldedAetherThiefCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shielded Aether Thief"), CardType::Creature, CREATURE_TYPE2(Vedalken, Rogue), nID,
		_T("1") BLUE_MANA_TEXT, Power(0), Life(4))
{
	GetCardKeyword()->AddFlash(FALSE);

	{
		// Whenever this creature blocks, you get {E}.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
							   CWhenSelfAttackedBlocked::BlockEventCallback,
							   &CWhenSelfAttackedBlocked::SetBlockingEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShieldedAetherThiefCard::BeforeEnergy));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Pay {E}{E}{E}: Draw a card.
		counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
				_T(""), 1));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddEnergyCost(this, 3);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CShieldedAetherThiefCard::BeforeEnergy(CAbilityAction* pAction)
{
	GetEnergy(this, pAction->GetController(), 1);
	return true;
}

CShipwreckMorayCard::CShipwreckMorayCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Shipwreck Moray"), CardType::Creature, CREATURE_TYPE(Fish), nID,
		_T("3") BLUE_MANA_TEXT, Power(0), Life(5))
{
	// When this creature enters, you get {E}{E}{E}{E}.
	AddEnterTrigger(this, &CShipwreckMorayCard::BeforeEnergy);

	// Pay {E}: This creature gets +2/-2 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->GetCost().AddEnergyCost(this, 1);
	cpAbility->SetAbilityText(_T("This creature gets +2/-2 until end of turn."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShipwreckMorayCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CShipwreckMorayCard::BeforeEnergy(CAbilityAction* pAction) const
{
	GetEnergy((CCard*)this, pAction->GetController(), 4);
	return true;
}

bool CShipwreckMorayCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, -2, CreatureKeyword::Null);
	return true;
}

CTrophyMageCard::CTrophyMageCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Trophy Mage"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, you may search your library for an artifact card with mana value 3, reveal it, put
	// it into your hand, then shuffle. (as Trinket Mage in Fifth Dawn)
	typedef
		TTriggeredAbility< CTriggeredSearchLibraryAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetSearchCount(MinimumValue(0), MaximumValue(1));
	cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new CardTypeComparer(CardType::Artifact, false));
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new ConvertedManaCostComparer<std::equal_to<int>>(3));
	cpAbility->SetToZone(ZoneId::Hand);
	AddAbility(cpAbility.GetPointer());
}

CWindKinRaidersCard::CWindKinRaidersCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Wind-Kin Raiders"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(3))
{
	// Improvise. Flying
	AddImproviseCreatureSpells(this, 4, BLUE_MANA_TEXT BLUE_MANA_TEXT);
}

//____________________________________________________________________________
//
// Multicolored creatures

CMaverickThopteristCard::CMaverickThopteristCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Maverick Thopterist"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("3") BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Improvise
	AddImproviseCreatureSpells(this, 3, BLUE_MANA_TEXT RED_MANA_TEXT);

	// When this creature enters, create two 1/1 colorless Thopter artifact creature tokens with flying.
	AddEnterTrigger(this, &CMaverickThopteristCard::BeforeThopters);
}

bool CMaverickThopteristCard::BeforeThopters(CAbilityAction* pAction) const
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Thopter (D)"), 55053, 2);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

COutlandBoarCard::COutlandBoarCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Outland Boar"), CardType::Creature, CREATURE_TYPE(Boar), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
	, m_CanBlockFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// This creature can't be blocked by creatures with power 2 or less. (as Elegant Edgecrafters in Kaladesh)
	GetCreatureKeyword()->AddUnblockable(FALSE, &m_CanBlockFilter);
}

CRenegadeRallierCard::CRenegadeRallierCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Renegade Rallier"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") GREEN_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Revolt - When this creature enters, if a permanent left the battlefield under your control this turn, return
	// target permanent card with mana value 2 or less from your graveyard to the battlefield.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment | CardType::_Land | CardType::Planeswalker, false));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(2));
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CRenegadeRallierCard::RevoltContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRenegadeRallierCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CRenegadeRallierCard::RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return HasRevolt(GetController());
}

bool CRenegadeRallierCard::BeforeReturn(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Graveyard && HasRevolt(pAction->GetController()))
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, FALSE, MoveType::Others, pAction->GetController());
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CRenegadeWheelsmithCard::CRenegadeWheelsmithCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Renegade Wheelsmith"), CardType::Creature, CREATURE_TYPE2(Dwarf, Pilot), nID,
		_T("1") RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(2))
{
	// Whenever this creature becomes tapped, target creature can't block this turn.
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfOrientationChanged,
								 CWhenSelfOrientationChanged::EventCallback, &CWhenSelfOrientationChanged::SetTapEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(CreatureKeyword::CantBlock);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

CRogueRefinerCard::CRogueRefinerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rogue Refiner"), CardType::Creature, CREATURE_TYPE2(Human, Rogue), nID,
		_T("1") GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, draw a card and you get {E}{E}.
	AddEnterTrigger(this, &CRogueRefinerCard::BeforeDraw);
}

bool CRogueRefinerCard::BeforeDraw(CAbilityAction* pAction) const
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	GetEnergy((CCard*)this, pAction->GetController(), 2);
	return true;
}

CSpirePatrolCard::CSpirePatrolCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Spire Patrol"), CardType::Creature, CREATURE_TYPE2(Human, Soldier), nID,
		_T("2") WHITE_MANA_TEXT BLUE_MANA_TEXT, Power(3), Life(2))
{
	// When this creature enters, tap target creature an opponent controls. That creature doesn't untap during its
	// controller's next untap step.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSpirePatrolCard::BeforeTap));
	AddAbility(cpAbility.GetPointer());
}

bool CSpirePatrolCard::BeforeTap(CAbilityAction* pAction) const
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pTapModifier = CCardOrientationModifier(TRUE);
		pTapModifier.ApplyTo(pCard);
		SkipNextUntap(GetGame(), pCard);
	}
	return false;
}

CWeldfastEngineerCard::CWeldfastEngineerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Weldfast Engineer"), CardType::Creature, CREATURE_TYPE2(Human, Artificer), nID,
		_T("1") BLACK_MANA_TEXT RED_MANA_TEXT, Power(3), Life(3))
{
	// At the beginning of combat on your turn, target artifact creature you control gets +2/+0 until end of turn.
	// (as Always Watching in Shadows over Innistrad)
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetPowerModifier().SetPowerDelta(Power(+2));
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_ArtifactCreature, true));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Colorless creatures

CAegisAutomatonCard::CAegisAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Aegis Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("2"), Power(0), Life(3))
{
	// {4}{W}: Return another target creature you control to its owner's hand.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			_T("4") WHITE_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	AddAbility(cpAbility.GetPointer());
}

CAugmentingAutomatonCard::CAugmentingAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Augmenting Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("1"), Power(1), Life(1))
{
	// {1}{B}: This creature gets +1/+1 until end of turn.
	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this,
			_T("1") BLACK_MANA_TEXT,
			Power(+1), Life(+1)));
	AddAbility(cpAbility.GetPointer());
}

CBarricadeBreakerCard::CBarricadeBreakerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Barricade Breaker"), CardType::_ArtifactCreature, CREATURE_TYPE(Juggernaut), nID,
		_T("7"), Power(7), Life(5))
{
	// Improvise. This creature attacks each combat if able.
	AddImproviseCreatureSpells(this, 7, _T(""));
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);
}

CFiligreeCrawlerCard::CFiligreeCrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Filigree Crawler"), CardType::_ArtifactCreature, CREATURE_TYPE(Insect), nID,
		_T("4"), Power(2), Life(2))
{
	// When this creature dies, create a 1/1 colorless Thopter artifact creature token with flying.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFiligreeCrawlerCard::BeforeThopter));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CFiligreeCrawlerCard::BeforeThopter(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), _T("Thopter (D)"), 55053, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CFoundryAssemblerCard::CFoundryAssemblerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Foundry Assembler"), CardType::_ArtifactCreature, CREATURE_TYPE(AssemblyWorker), nID,
		_T("5"), Power(3), Life(3))
{
	// Improvise
	AddImproviseCreatureSpells(this, 5, _T(""));
}

CNightMarketGuardCard::CNightMarketGuardCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Night Market Guard"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(3), Life(1))
{
	// This creature can block an additional creature each combat.
	SetMaxBlockingCount(2);
}

CPrizefighterConstructCard::CPrizefighterConstructCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Prizefighter Construct"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("5"), Power(6), Life(2))
{
}

CReservoirWalkerCard::CReservoirWalkerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Reservoir Walker"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("5"), Power(3), Life(3))
{
	// When this creature enters, you gain 3 life and get {E}{E}{E}.
	AddEnterTrigger(this, &CReservoirWalkerCard::BeforeLife);
}

bool CReservoirWalkerCard::BeforeLife(CAbilityAction* pAction) const
{
	GainLife((CCard*)this, pAction->GetController(), 3);
	GetEnergy((CCard*)this, pAction->GetController(), 3);
	return true;
}

CScrapTrawlerCard::CScrapTrawlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scrap Trawler"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(3), Life(2))
	, m_ReturnFilter(_T("an artifact card"), _T("artifact cards"), new CardTypeComparer(CardType::Artifact, false))
{
	// Whenever this creature dies or another artifact you control is put into a graveyard from the battlefield,
	// return to your hand target artifact card in your graveyard with lesser mana value.
	// Note: the card is chosen on resolution (not targeted)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->GetTrigger().SetFromControllerOnly(TRUE);
	cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("artifacts")));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CScrapTrawlerCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CScrapTrawlerCard::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
}

bool CScrapTrawlerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard)
		return false;

	triggerContext.nValue1 = (DWORD)pCard->GetConvertedManaCost();
	return true;
}

bool CScrapTrawlerCard::BeforeReturn(TriggeredAbility::TriggeredActionType* pAction)
{
	int nManaValue = (int)pAction->GetTriggerContext().nValue1;
	if (nManaValue <= 0)
		return true;

	m_ReturnFilter.SetComparer(new CardTypeComparer(CardType::Artifact, false));
	m_ReturnFilter.AddComparer(new ConvertedManaCostComparer<std::less<int>>(nManaValue));

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select an artifact card
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		&m_ReturnFilter,						// artifact cards with lesser mana value
		ZoneId::Hand,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CTezzeretsSimulacrumCard::CTezzeretsSimulacrumCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tezzeret's Simulacrum"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("3"), Power(2), Life(3))
{
	// {T}: Target opponent loses 1 life. If you control a Tezzeret planeswalker, that player loses 3 life instead.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddTapCost();
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTezzeretsSimulacrumCard::BeforeLifeLoss));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	AddAbility(cpAbility.GetPointer());
}

bool CTezzeretsSimulacrumCard::BeforeLifeLoss(CAbilityAction* pAction) const
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	int nLoss = 1;
	PlaneswalkerTypeComparer tezzeret(PlaneswalkerType::Tezzeret);
	CZone* pBattlefield = pAction->GetController()->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (tezzeret(pBattlefield->GetAt(i)))
		{
			nLoss = 3;
			break;
		}

	CLifeModifier pModifier = CLifeModifier(Life(-nLoss), (CCard*)this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pModifier.ApplyTo(pOpponent);
	return true;
}

CVerdantAutomatonCard::CVerdantAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Verdant Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("2"), Power(1), Life(2))
{
	// {3}{G}: Put a +1/+1 counter on this creature.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") GREEN_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Put a +1/+1 counter on this creature."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVerdantAutomatonCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

bool CVerdantAutomatonCard::BeforeCounter(CAbilityAction* pAction)
{
	AddCounters(this, _T("+1/+1"), 1);
	return true;
}

CWatchfulAutomatonCard::CWatchfulAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Watchful Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("3"), Power(2), Life(2))
{
	// {2}{U}: Scry 1.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") BLUE_MANA_TEXT));

	cpAbility->SetAbilityText(_T("Scry 1."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWatchfulAutomatonCard::BeforeScry));
	AddAbility(cpAbility.GetPointer());
}

bool CWatchfulAutomatonCard::BeforeScry(CAbilityAction* pAction)
{
	CScryModifier(GetGame(), 1, this).ApplyTo(pAction->GetController());
	return true;
}

CWelderAutomatonCard::CWelderAutomatonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Welder Automaton"), CardType::_ArtifactCreature, CREATURE_TYPE(Construct), nID,
		_T("2"), Power(2), Life(1))
{
	// {3}{R}: This creature deals 1 damage to each opponent.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") RED_MANA_TEXT));

	cpAbility->SetAbilityText(_T("This creature deals 1 damage to each opponent."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWelderAutomatonCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CWelderAutomatonCard::BeforeDamage(CAbilityAction* pAction) const
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

//____________________________________________________________________________
//
