#include "stdafx.h"
#include "CardHourOfDevastation.h"

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
		DEFINE_CARD(CCryptOfTheEternalsCard);
		DEFINE_CARD(CDesertOfTheFerventCard);
		DEFINE_CARD(CDesertOfTheGlorifiedCard);
		DEFINE_CARD(CDesertOfTheIndomitableCard);
		DEFINE_CARD(CDesertOfTheMindfulCard);
		DEFINE_CARD(CDesertOfTheTrueCard);
		DEFINE_CARD(CDunesOfTheDeadCard);
		DEFINE_CARD(CEndlessSandsCard);
		DEFINE_CARD(CHashepOasisCard);
		DEFINE_CARD(CHostileDesertCard);
		DEFINE_CARD(CIfnirDeadlandsCard);
		DEFINE_CARD(CIpnuRivuletCard);
		DEFINE_CARD(CRamunapRuinsCard);
		DEFINE_CARD(CScavengerGroundsCard);
		DEFINE_CARD(CShefetDunesCard);
		DEFINE_CARD(CSurvivorsEncampmentCard);
		DEFINE_CARD(CNicolBolasGodPharaohCard);
		DEFINE_CARD(CNicolBolasTheDeceiverCard);
		DEFINE_CARD(CNissaGenesisMageCard);
		DEFINE_CARD(CSamutTheTestedCard);
		DEFINE_CARD(CCrookOfCondemnationCard);
		DEFINE_CARD(CDaggerOfTheWorthyCard);
		DEFINE_CARD(CGodPharaohsGiftCard);
		DEFINE_CARD(CSunsetPyramidCard);
		DEFINE_CARD(CVisageOfBolasCard);
		DEFINE_CARD(CDesertsHoldCard);
		DEFINE_CARD(CFrayingSanityCard);
		DEFINE_CARD(CImminentDoomCard);
		DEFINE_CARD(CRiddleformCard);
		DEFINE_CARD(CSwarmIntelligenceCard);
		DEFINE_CARD(CTormentOfScarabsCard);
		DEFINE_CARD(CUnquenchableThirstCard);
		DEFINE_CARD(CAppealAuthorityCard);
		DEFINE_CARD(CBeneathTheSandsCard);
		DEFINE_CARD(CBontusLastReckoningCard);
		DEFINE_CARD(CClaimFameCard);
		DEFINE_CARD(CConsignOblivionCard);
		DEFINE_CARD(CCrashThroughCard);
		DEFINE_CARD(CDoomfallCard);
		DEFINE_CARD(CFarmMarketCard);
		DEFINE_CARD(CGrindDustCard);
		DEFINE_CARD(CHourOfDevastationCard);
		DEFINE_CARD(CHourOfEternityCard);
		DEFINE_CARD(CHourOfPromiseCard);
		DEFINE_CARD(CHourOfRevelationCard);
		DEFINE_CARD(CInfernoJetCard);
		DEFINE_CARD(CKefnetsLastWordCard);
		DEFINE_CARD(CLeaveChanceCard);
		DEFINE_CARD(CLethalStingCard);
		DEFINE_CARD(CLilianasDefeatCard);
		DEFINE_CARD(CNissasDefeatCard);
		DEFINE_CARD(CNissasEncouragementCard);
		DEFINE_CARD(COketrasLastMercyCard);
		DEFINE_CARD(COvercomeCard);
		DEFINE_CARD(CPuncturingBlowCard);
		DEFINE_CARD(CRazakethsRiteCard);
		DEFINE_CARD(CReasonBelieveCard);
		DEFINE_CARD(CRhonassLastStandCard);
		DEFINE_CARD(CStruggleSurviveCard);
		DEFINE_CARD(CTormentOfHailfireCard);
		DEFINE_CARD(CUncageTheMenagerieCard);
		DEFINE_CARD(CUnconventionalTacticsCard);
		DEFINE_CARD(CAbradeCard);
		DEFINE_CARD(CActOfHeroismCard);
		DEFINE_CARD(CAmbuscadeCard);
		DEFINE_CARD(CBlurOfBladesCard);
		DEFINE_CARD(CChandrasDefeatCard);
		DEFINE_CARD(CCountervailingWindsCard);
		DEFINE_CARD(CDjerusRenunciationCard);
		DEFINE_CARD(CGideonsDefeatCard);
		DEFINE_CARD(CGiftOfStrengthCard);
		DEFINE_CARD(CHourOfGloryCard);
		DEFINE_CARD(CImaginaryThreatsCard);
		DEFINE_CARD(CJacesDefeatCard);
		DEFINE_CARD(CLifeGoesOnCard);
		DEFINE_CARD(COpenFireCard);
		DEFINE_CARD(CRefuseCooperateCard);
		DEFINE_CARD(CSupremeWillCard);
		DEFINE_CARD(CTormentOfVenomCard);
		DEFINE_CARD(CTragicLessonCard);
		DEFINE_CARD(CWithoutWeaknessCard);
		DEFINE_CARD(CAdornedPouncerCard);
		DEFINE_CARD(CAngelOfCondemnationCard);
		DEFINE_CARD(CAngelOfTheGodPharaohCard);
		DEFINE_CARD(CAvenOfEnduringHopeCard);
		DEFINE_CARD(CCrestedSunmareCard);
		DEFINE_CARD(CDauntlessAvenCard);
		DEFINE_CARD(CDisposalMummyCard);
		DEFINE_CARD(CDjeruWithEyesOpenCard);
		DEFINE_CARD(CDutifulServantsCard);
		DEFINE_CARD(CGodPharaohsFaithfulCard);
		DEFINE_CARD(CMummyParamountCard);
		DEFINE_CARD(COketrasAvengerCard);
		DEFINE_CARD(CSolitaryCamelCard);
		DEFINE_CARD(CSteadfastSentinelCard);
		DEFINE_CARD(CStewardOfSolidarityCard);
		DEFINE_CARD(CSunscourgeChampionCard);
		DEFINE_CARD(CVizierOfTheTrueCard);
		DEFINE_CARD(CAvidReclaimerCard);
		DEFINE_CARD(CBitterbowSharpshootersCard);
		DEFINE_CARD(CBrambleweftBehemothCard);
		DEFINE_CARD(CDevoteeOfStrengthCard);
		DEFINE_CARD(CDuneDivinerCard);
		DEFINE_CARD(CFeralProwlerCard);
		DEFINE_CARD(CFrilledSandwallaCard);
		DEFINE_CARD(CHarrierNagaCard);
		DEFINE_CARD(CHopeTenderCard);
		DEFINE_CARD(CMajesticMyriarchCard);
		DEFINE_CARD(COasisRitualistCard);
		DEFINE_CARD(CPrideSovereignCard);
		DEFINE_CARD(CQuarryBeetleCard);
		DEFINE_CARD(CRampagingHippoCard);
		DEFINE_CARD(CRamunapExcavatorCard);
		DEFINE_CARD(CRamunapHydraCard);
		DEFINE_CARD(CResilientKhenraCard);
		DEFINE_CARD(CRhonassStalwartCard);
		DEFINE_CARD(CSidewinderNagaCard);
		DEFINE_CARD(CSifterWurmCard);
		DEFINE_CARD(CTenaciousHunterCard);
		DEFINE_CARD(CBurningFistMinotaurCard);
		DEFINE_CARD(CChaosMawCard);
		DEFINE_CARD(CDefiantKhenraCard);
		DEFINE_CARD(CEarthshakerKhenraCard);
		DEFINE_CARD(CFerventPaincasterCard);
		DEFINE_CARD(CFirebrandArcherCard);
		DEFINE_CARD(CFrontlineDevastatorCard);
		DEFINE_CARD(CGildedCerodonCard);
		DEFINE_CARD(CGraniticTitanCard);
		DEFINE_CARD(CKhenraScrapperCard);
		DEFINE_CARD(CMagmarothCard);
		DEFINE_CARD(CManticoreEternalCard);
		DEFINE_CARD(CNehebTheEternalCard);
		DEFINE_CARD(CSandStranglerCard);
		DEFINE_CARD(CThornedMolochCard);
		DEFINE_CARD(CWildfireEternalCard);
		DEFINE_CARD(CZealotOfTheGodPharaohCard);
		DEFINE_CARD(CAccursedHordeCard);
		DEFINE_CARD(CAmmitEternalCard);
		DEFINE_CARD(CApocalypseDemonCard);
		DEFINE_CARD(CBanewhipPunisherCard);
		DEFINE_CARD(CCarrionScreecherCard);
		DEFINE_CARD(CDreamstealerCard);
		DEFINE_CARD(CGrislySurvivorCard);
		DEFINE_CARD(CKhenraEternalCard);
		DEFINE_CARD(CLurchingRotbeastCard);
		DEFINE_CARD(CMaraudingBoneslasherCard);
		DEFINE_CARD(CMercilessEternalCard);
		DEFINE_CARD(CMoaningWallCard);
		DEFINE_CARD(CRazakethTheFoulbloodedCard);
		DEFINE_CARD(CRuinRatCard);
		DEFINE_CARD(CScroungerOfSoulsCard);
		DEFINE_CARD(CVileManifestationCard);
		DEFINE_CARD(CWaspOfTheBitterEndCard);
		DEFINE_CARD(CWretchedCamelCard);
		DEFINE_CARD(CAerialGuideCard);
		DEFINE_CARD(CAvenReedstalkerCard);
		DEFINE_CARD(CChampionOfWitsCard);
		DEFINE_CARD(CCunningSurvivorCard);
		DEFINE_CARD(CEternalOfHarshTruthsCard);
		DEFINE_CARD(CNimbleObstructionistCard);
		DEFINE_CARD(COminousSphinxCard);
		DEFINE_CARD(CProvenCombatantCard);
		DEFINE_CARD(CSeerOfTheLastTomorrowCard);
		DEFINE_CARD(CSinuousStrikerCard);
		DEFINE_CARD(CSpellweaverEternalCard);
		DEFINE_CARD(CStripedRiverwinderCard);
		DEFINE_CARD(CUneshCriosphinxSovereignCard);
		DEFINE_CARD(CVizierOfTheAnointedCard);
		DEFINE_CARD(CBloodwaterEntityCard);
		DEFINE_CARD(CObeliskSpiderCard);
		DEFINE_CARD(CResoluteSurvivorsCard);
		DEFINE_CARD(CRiverHoopoeCard);
		DEFINE_CARD(CTheLocustGodCard);
		DEFINE_CARD(CTheScarabGodCard);
		DEFINE_CARD(CTheScorpionGodCard);
		DEFINE_CARD(CUnravelingMummyCard);
		DEFINE_CARD(CGravenAbominationCard);
		DEFINE_CARD(CHollowOneCard);
		DEFINE_CARD(CWallOfForgottenPharaohsCard);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (from Amonkhet)

#define ZOMBIE_TOKEN_NAME	_T("Zombie (P)")
#define ZOMBIE_TOKEN_ID		55009
#define ELEMENTAL_AV_TOKEN_NAME	_T("Elemental (AV)")
#define ELEMENTAL_AV_TOKEN_ID	64122

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

// "{T}, Pay 1 life: Add <mana>." (as Mana Confluence)
static void AddPayLifeManaAbility(CCard* pCard, LPCTSTR strMana)
{
	counted_ptr<CManaProductionAbility> cpAbility(
		::CreateObject<CManaProductionAbility>(pCard, _T(""), AbilityType::Activated, strMana));
	cpAbility->AddTapCost();
	cpAbility->AddPayLifeDeltaCost(Life(-1));
	pCard->AddAbility(cpAbility.GetPointer());
}

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

//____________________________________________________________________________
//
// Mechanics

// Afflict N (as Slate Street Ruffian's "becomes blocked" trigger in Gatecrash)
void CAfflictSupport::AddAfflictAbility(int nAfflict)
{
	m_nAfflict = nAfflict;

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockedEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAfflictSupport::OnBlocked));
	cpAbility->AddAbilityTag(AbilityTag::LifeLost);
	m_pCard->AddAbility(cpAbility.GetPointer());
}

// The defending player is the opponent (two-player games)
bool CAfflictSupport::OnBlocked(CAbilityAction* pAction)
{
	EachOpponentLosesLife(m_pCard, pAction->GetController(), m_nAfflict);
	return true;
}

//____________________________________________________________________________
//
// Lands

CCryptOfTheEternalsCard::CCryptOfTheEternalsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Crypt of the Eternals"), nID)
{
	// When this land enters, you gain 1 life.
	AddEnterTrigger(this, &CCryptOfTheEternalsCard::BeforeGainLife);

	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {1}, {T}: Add {U}, {B}, or {R}. (as Painted Bluffs)
	LPCTSTR colors[] = { BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T("1"), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCryptOfTheEternalsCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CCyclingDesertBase::CCyclingDesertBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strMana)
	: CNonbasicLandCard(pGame, strCardName, nID, CardType::_DesertLand)
{
	// This land enters tapped.
	SetIntoPlayTapped();

	// {T}: Add {C1}.
	AddTapManaAbility(this, strMana);

	// Cycling {1}{C1}
	CString strCost(_T("1"));
	strCost += strMana;
	AddCycling(this, strCost);
}

CDesertOfTheFerventCard::CDesertOfTheFerventCard(CGame* pGame, UINT nID)
	: CCyclingDesertBase(pGame, _T("Desert of the Fervent"), nID, RED_MANA_TEXT)
{
}

CDesertOfTheGlorifiedCard::CDesertOfTheGlorifiedCard(CGame* pGame, UINT nID)
	: CCyclingDesertBase(pGame, _T("Desert of the Glorified"), nID, BLACK_MANA_TEXT)
{
}

CDesertOfTheIndomitableCard::CDesertOfTheIndomitableCard(CGame* pGame, UINT nID)
	: CCyclingDesertBase(pGame, _T("Desert of the Indomitable"), nID, GREEN_MANA_TEXT)
{
}

CDesertOfTheMindfulCard::CDesertOfTheMindfulCard(CGame* pGame, UINT nID)
	: CCyclingDesertBase(pGame, _T("Desert of the Mindful"), nID, BLUE_MANA_TEXT)
{
}

CDesertOfTheTrueCard::CDesertOfTheTrueCard(CGame* pGame, UINT nID)
	: CCyclingDesertBase(pGame, _T("Desert of the True"), nID, WHITE_MANA_TEXT)
{
}

CDunesOfTheDeadCard::CDunesOfTheDeadCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Dunes of the Dead"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// When this land is put into a graveyard from the battlefield, create a 2/2 black Zombie creature token.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDunesOfTheDeadCard::BeforeToken));
	AddAbility(cpAbility.GetPointer());
}

bool CDunesOfTheDeadCard::BeforeToken(CAbilityAction* pAction)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CEndlessSandsCard::CEndlessSandsCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Endless Sands"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	{
		// {2}, {T}: Exile target creature you control.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2"),
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetIncludeControllerCardsOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEndlessSandsCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {4}, {T}, Sacrifice this land: Return each creature card exiled with this land to the battlefield under its
		// owner's control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("4")));

		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEndlessSandsCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

// The exiled cards are remembered even if this land leaves the battlefield before the second ability
bool CEndlessSandsCard::BeforeExile(CAbilityAction* pAction)
{
	ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return true;
}

bool CEndlessSandsCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CSacrificeDesertBase::CSacrificeDesertBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strMana)
	: CNonbasicLandCard(pGame, strCardName, nID, CardType::_DesertLand)
	, m_DesertFilter(_T("a Desert"), _T("Deserts"), new CardTypeComparer(CardType::Desert, false))
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {T}, Pay 1 life: Add {C1}.
	if (strMana)
		AddPayLifeManaAbility(this, strMana);
}

// "{T}, Sacrifice a Desert" (this land can be the sacrificed Desert)
void CSacrificeDesertBase::AddSacrificeDesertCost(CAbility* pAbility)
{
	pAbility->AddTapCost();
	pAbility->GetCost().AddSacrificeCardCost(1, &m_DesertFilter);
}

CHashepOasisCard::CHashepOasisCard(CGame* pGame, UINT nID)
	: CSacrificeDesertBase(pGame, _T("Hashep Oasis"), nID, GREEN_MANA_TEXT)
{
	// {1}{G}{G}, {T}, Sacrifice a Desert: Target creature gets +3/+3 until end of turn. Activate only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") GREEN_MANA_TEXT GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	AddSacrificeDesertCost(cpAbility.GetPointer());
	SetAsSorcery(cpAbility.GetPointer());
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHashepOasisCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CHashepOasisCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +3, +3);
	return true;
}

CHostileDesertCard::CHostileDesertCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Hostile Desert"), nID, CardType::_DesertLand)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {2}, Exile a land card from your graveyard: This land becomes a 3/4 Elemental creature until end of turn.
	// It's still a land. (as Lumbering Falls in Battle for Zendikar)
	counted_ptr<CIsAlsoAAbility> cpAbility(
		::CreateObject<CIsAlsoAAbility>(this,
			_T("2"),
			ELEMENTAL_AV_TOKEN_NAME, ELEMENTAL_AV_TOKEN_ID));

	cpAbility->GetCost().AddExileGraveyardCardCost(1, CCardFilter::GetFilter(_T("lands")));
	AddAbility(cpAbility.GetPointer());
}

CIfnirDeadlandsCard::CIfnirDeadlandsCard(CGame* pGame, UINT nID)
	: CSacrificeDesertBase(pGame, _T("Ifnir Deadlands"), nID, BLACK_MANA_TEXT)
{
	// {2}{B}{B}, {T}, Sacrifice a Desert: Put two -1/-1 counters on target creature an opponent controls. Activate
	// only as a sorcery.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	AddSacrificeDesertCost(cpAbility.GetPointer());
	SetAsSorcery(cpAbility.GetPointer());
	cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIfnirDeadlandsCard::BeforeCounters));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CIfnirDeadlandsCard::BeforeCounters(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 2);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CIpnuRivuletCard::CIpnuRivuletCard(CGame* pGame, UINT nID)
	: CSacrificeDesertBase(pGame, _T("Ipnu Rivulet"), nID, BLUE_MANA_TEXT)
{
	// {1}{U}, {T}, Sacrifice a Desert: Target player mills four cards. (as Embalmer's Tools in Amonkhet)
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	AddSacrificeDesertCost(cpAbility.GetPointer());
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CIpnuRivuletCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CIpnuRivuletCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 4);
	return true;
}

CRamunapRuinsCard::CRamunapRuinsCard(CGame* pGame, UINT nID)
	: CSacrificeDesertBase(pGame, _T("Ramunap Ruins"), nID, RED_MANA_TEXT)
{
	// {2}{R}{R}, {T}, Sacrifice a Desert: This land deals 2 damage to each opponent.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") RED_MANA_TEXT RED_MANA_TEXT));

	AddSacrificeDesertCost(cpAbility.GetPointer());
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRamunapRuinsCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CRamunapRuinsCard::BeforeDamage(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pController)
			pModifier.ApplyTo(GetGame()->GetPlayer(ip));
	return true;
}

CScavengerGroundsCard::CScavengerGroundsCard(CGame* pGame, UINT nID)
	: CSacrificeDesertBase(pGame, _T("Scavenger Grounds"), nID, NULL)
{
	// {2}, {T}, Sacrifice a Desert: Exile all graveyards.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2")));

	AddSacrificeDesertCost(cpAbility.GetPointer());
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CScavengerGroundsCard::BeforeExile));
	AddAbility(cpAbility.GetPointer());
}

bool CScavengerGroundsCard::BeforeExile(CAbilityAction* pAction)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others,
		pAction->GetController());
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pGraveyard = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Graveyard);

		// Copy the cards first: the zone changes while they are moved
		CCountedCardContainer cards;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
			cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
				pModifier.ApplyTo(cards.GetAt(i));
	}
	return true;
}

CShefetDunesCard::CShefetDunesCard(CGame* pGame, UINT nID)
	: CSacrificeDesertBase(pGame, _T("Shefet Dunes"), nID, WHITE_MANA_TEXT)
{
	// {2}{W}{W}, {T}, Sacrifice a Desert: Creatures you control get +1/+1 until end of turn. Activate only as a
	// sorcery.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	AddSacrificeDesertCost(cpAbility.GetPointer());
	SetAsSorcery(cpAbility.GetPointer());
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CShefetDunesCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CShefetDunesCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +1, +1);
	return true;
}

CSurvivorsEncampmentCard::CSurvivorsEncampmentCard(CGame* pGame, UINT nID)
	: CNonbasicLandCard(pGame, _T("Survivors' Encampment"), nID, CardType::_DesertLand)
	, m_CreatureFilter(_T("an untapped creature you control"), _T("untapped creatures you control"),
		new AnyCreatureComparer)
{
	// {T}: Add {C}.
	AddColorlessManaAbility(this);

	// {T}, Tap an untapped creature you control: Add one mana of any color. (as Springleaf Drum in Lorwyn)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->GetCost().AddTapCardCost(1, &m_CreatureFilter);
		AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (planeswalkers)

static void DrawCards(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CDrawCardModifier pModifier = CDrawCardModifier(pGame, MinimumValue(nCount), MaximumValue(nCount));
	pModifier.ApplyTo(pPlayer);
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

// The player discards nCount cards of their choice (as Amonkhet)
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

// The player exiles nCount cards of their choice from their hand (as DiscardCards)
static void ExileFromHand(CGame* pGame, CPlayer* pPlayer, int nCount)
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
	pModifier.AddSelection(MinimumValue(nCount), MaximumValue(nCount), // select cards to exile
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Exile, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);
}

// The player sacrifices one permanent of their choice among those that pass pFilter (as Amonkhet). Returns FALSE
// if the player controls no such permanent.
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

//____________________________________________________________________________
//
// Planeswalkers

CNicolBolasGodPharaohCard::CNicolBolasGodPharaohCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nicol Bolas, God-Pharaoh"), nID,
		_T("4") BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Bolas, 7)
{
	{
		// +2: Target opponent exiles cards from the top of their library until they exile a nonland card. Until end
		// of turn, you may cast that card without paying its mana cost.
		// Partial: the card is exiled, but it can't be cast (the engine can't cast cards from exile for free)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasGodPharaohCard::BeforeExileTop));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// +1: Each opponent exiles two cards from their hand.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasGodPharaohCard::BeforeExileHand));
		cpAbility->SetAbilityText(_T("+1: Each opponent exiles two cards from their hand."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -4: Nicol Bolas deals 7 damage to target opponent, creature an opponent controls, or planeswalker an
		// opponent controls.
		// Note: it can't target planeswalkers
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-7), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -4);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -12: Exile each nonland permanent your opponents control.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -12);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasGodPharaohCard::BeforeExilePermanents));
		cpAbility->SetAbilityText(_T("-12: Exile each nonland permanent your opponents control."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CNicolBolasGodPharaohCard::BeforeExileTop(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CZone* pLibrary = pOpponent->GetZoneById(ZoneId::Library);
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Exile, TRUE, MoveType::Others, pOpponent);
	while (pLibrary->GetSize() > 0)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
		BOOL bLand = pCard->GetCardType().IsLand();
		pModifier.ApplyTo(pCard);
		if (!bLand || pCard->GetZoneId() != ZoneId::Exile)
			break;
	}
	return true;
}

bool CNicolBolasGodPharaohCard::BeforeExileHand(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAction->GetController())
			ExileFromHand(GetGame(), GetGame()->GetPlayer(ip), 2);
	return true;
}

bool CNicolBolasGodPharaohCard::BeforeExilePermanents(CAbilityAction* pAction)
{
	CCountedCardContainer permanents;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		CZone* pBattlefield = pOpponent->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (!pBattlefield->GetAt(i)->GetCardType().IsLand())
				permanents.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others,
		pAction->GetController());
	for (int i = 0; i < permanents.GetSize(); ++i)
		if (permanents.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo(permanents.GetAt(i));
	return true;
}

#define BOLAS_CHOICE_SACRIFICE	1
#define BOLAS_CHOICE_DISCARD	2
#define BOLAS_CHOICE_LOSE_LIFE	3

CNicolBolasTheDeceiverCard::CNicolBolasTheDeceiverCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nicol Bolas, the Deceiver"), nID,
		_T("5") BLUE_MANA_TEXT BLACK_MANA_TEXT RED_MANA_TEXT,
		PlaneswalkerType::Bolas, 5)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNicolBolasTheDeceiverCard::OnChoiceSelected))
	, m_NonlandFilter(_T("a nonland permanent"), _T("nonland permanents"),
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	{
		// +3: Each opponent loses 3 life unless that player sacrifices a nonland permanent of their choice or
		// discards a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +3);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasTheDeceiverCard::BeforeChoice));
		cpAbility->SetAbilityText(_T("+3: Each opponent loses 3 life unless that player sacrifices a nonland permanent or discards a card."));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Destroy target creature. Draw a card.
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T(""),
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -11: Nicol Bolas deals 7 damage to each opponent. You draw seven cards.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -11);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNicolBolasTheDeceiverCard::BeforeUltimate));
		cpAbility->SetAbilityText(_T("-11: Nicol Bolas deals 7 damage to each opponent. You draw seven cards."));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

// Each opponent chooses: sacrifice a nonland permanent, discard a card or lose 3 life
bool CNicolBolasTheDeceiverCard::BeforeChoice(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pOpponent = GetGame()->GetPlayer(ip);
		if (pOpponent == pAction->GetController())
			continue;

		std::vector<SelectionEntry> entries;
		if (m_NonlandFilter.CountIncluded(pOpponent->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
		{
			SelectionEntry entry;
			entry.dwContext = BOLAS_CHOICE_SACRIFICE;
			entry.strText = _T("Sacrifice a nonland permanent");
			entries.push_back(entry);
		}
		if (pOpponent->GetZoneById(ZoneId::Hand)->GetSize() > 0)
		{
			SelectionEntry entry;
			entry.dwContext = BOLAS_CHOICE_DISCARD;
			entry.strText = _T("Discard a card");
			entries.push_back(entry);
		}
		{
			SelectionEntry entry;
			entry.dwContext = BOLAS_CHOICE_LOSE_LIFE;
			entry.strText = _T("Lose 3 life");
			entries.push_back(entry);
		}

		m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent);
	}
	return true;
}

void CNicolBolasTheDeceiverCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == BOLAS_CHOICE_SACRIFICE &&
				SacrificeOne(GetGame(), pSelectionPlayer, &m_NonlandFilter))
				return;

			if (it->dwContext == BOLAS_CHOICE_DISCARD &&
				pSelectionPlayer->GetZoneById(ZoneId::Hand)->GetSize() > 0)
			{
				DiscardCards(GetGame(), pSelectionPlayer, 1);
				return;
			}

			CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pSelectionPlayer);
			return;
		}
}

bool CNicolBolasTheDeceiverCard::BeforeUltimate(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 7);
	DrawCards(GetGame(), pAction->GetController(), 7);
	return true;
}

CNissaGenesisMageCard::CNissaGenesisMageCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Nissa, Genesis Mage"), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Nissa, 5)
	, m_LandSelection(pGame, CSelectionSupport::SelectionCallback(this, &CNissaGenesisMageCard::OnLandsSelected))
	, m_CreatureOrLandFilter(_T("a creature or land card"), _T("creature and/or land cards"),
		new CardTypeComparer(CardType::Creature | CardType::_Land, false))
{
	{
		// +2: Untap up to two target creatures and up to two target lands.
		// Partial: the lands are chosen on resolution, they aren't targeted
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +2);
		cpAbility->GetTargeting()->SetSubjectCount(0, 2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaGenesisMageCard::BeforeUntapLands));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -3: Target creature gets +5/+5 until end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -3);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaGenesisMageCard::BeforePump));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -10: Look at the top ten cards of your library. You may put any number of creature and/or land cards from
		// among them onto the battlefield. Put the rest on the bottom of your library in a random order.
		// Note: the controller orders the rest (as Mitotic Manipulation in Mirrodin Besieged)
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -10);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissaGenesisMageCard::BeforeUltimate));
		cpAbility->SetAbilityText(_T("-10: Look at the top ten cards of your library. Put any number of creature and/or land cards from among them onto the battlefield."));
		AddAbility(cpAbility.GetPointer());
	}
}

// Up to two tapped lands on the battlefield, chosen by the controller
bool CNissaGenesisMageCard::BeforeUntapLands(CAbilityAction* pAction)
{
	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CCard* pCard = pBattlefield->GetAt(i);
			if (pCard->GetCardType().IsLand() && pCard->GetOrientation()->IsTapped())
			{
				SelectionEntry entry;
				entry.dwContext = (DWORD)pCard;
				entry.cpAssociatedCard = pCard;
				entry.strText.Format(_T("Untap %s"), pCard->GetCardName(TRUE));
				entries.push_back(entry);
			}
		}
	}

	if (!entries.empty())
		m_LandSelection.AddSelectionRequest(entries, 0, 2, this, pAction->GetController());
	return true;
}

void CNissaGenesisMageCard::OnLandsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() == ZoneId::Battlefield)
				pModifier.ApplyTo(pCard);
		}
}

bool CNissaGenesisMageCard::BeforePump(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CPowerModifier pPowerModifier = CPowerModifier(Power(+5));
	pPowerModifier.ApplyTo(pCreature);
	CLifeModifier pLifeModifier = CLifeModifier(Life(+5), pCreature, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	pLifeModifier.ApplyTo(pCreature);
	return true;
}

bool CNissaGenesisMageCard::BeforeUltimate(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = pController->GetZoneById(ZoneId::Library)->GetSize();
	if (nCount > 10)
		nCount = 10;
	if (nCount <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nCount, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nCount), // any number of creature and/or land cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		&m_CreatureOrLandFilter, // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
		CardPlacement::NotApplicable, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player

	// the rest go to the bottom of the library
	pModifier.SetReorderInformation(
		true,
		ZoneId::Library,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Bottom);

	pModifier.ApplyTo(pController);
	return true;
}

CSamutTheTestedCard::CSamutTheTestedCard(CGame* pGame, UINT nID)
	: CPlaneswalkerCard(pGame, _T("Samut, the Tested"), nID,
		_T("2") RED_MANA_TEXT GREEN_MANA_TEXT,
		PlaneswalkerType::Samut, 4)
	, m_CreatureOrPlaneswalkerFilter(_T("a creature or planeswalker card"), _T("creature and/or planeswalker cards"),
		new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false))
{
	{
		// +1: Up to one target creature gains double strike until end of turn.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), +1);
		cpAbility->GetTargeting()->SetSubjectCount(0, 1);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSamutTheTestedCard::BeforeDoubleStrike));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -2: Samut deals 2 damage divided as you choose among one or two targets. (as Forked Bolt)
		// Note: it can't target planeswalkers
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, TRUE,
				Life(-2), PreventableType::Preventable));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -2);
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetSubjectCount(1, 2);
		cpAbility->GetTargeting()->SetDistributeValues();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// -7: Search your library for up to two creature and/or planeswalker cards, put them onto the battlefield,
		// then shuffle.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("")));

		cpAbility->GetCost().AddCounterCost(GetLoyaltyCounter(), -7);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSamutTheTestedCard::BeforeSearch));
		cpAbility->SetAbilityText(_T("-7: Search your library for up to two creature and/or planeswalker cards and put them onto the battlefield."));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CSamutTheTestedCard::BeforeDoubleStrike(CAbilityAction* pAction)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::DoubleStrike);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);
	return true;
}

// (as Harvest Season's search in Amonkhet)
bool CSamutTheTestedCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(2), // up to two creature and/or planeswalker cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		&m_CreatureOrPlaneswalkerFilter, // what cards
		ZoneId::Battlefield, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // under this player's control
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (artifacts)

#define BRICK_COUNTER		_T("brick counter")

// "Equipped creature gets +N/+N" (as Eldritch Moon)
static void AddEquipBonus(CEquipAbility* pAbility, CCard* pCard, Power nPower, Life nLife)
{
	if (nLife != Life(0))
		pAbility->AddCreatureModifier(new CLifeModifier(nLife, pCard,
			PreventableType::NotPreventable, DamageType::NonCombatDamage, FALSE));
	if (nPower != Power(0))
		pAbility->AddCreatureModifier(new CPowerModifier(nPower, FALSE));
}

// Searches pPlayer's graveyard and then library for a card named strName and puts it into their hand (shuffling the
// library if it was searched). For "you may search your library and/or graveyard for a card named ..." (as Amonkhet)
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

// Exiles every card in every graveyard
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

//____________________________________________________________________________
//
// Artifacts

CCrookOfCondemnationCard::CCrookOfCondemnationCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Crook of Condemnation"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// {1}, {T}: Exile target card from a graveyard. (as Secret Salvage in Aether Revolt)
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("1"),
				new TrueCardComparer,
				ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->AddTapCost();
		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Exile));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}, Exile this artifact: Exile all graveyards.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("1")));

		cpAbility->AddExileCost();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrookOfCondemnationCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCrookOfCondemnationCard::BeforeExile(CAbilityAction* pAction)
{
	ExileAllGraveyards(GetGame(), pAction->GetController());
	return true;
}

CDaggerOfTheWorthyCard::CDaggerOfTheWorthyCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Dagger of the Worthy"), CardType::Artifact | CardType::Equipment, nID,
		_T("2"), AbilityType::Artifact)
{
	{
		// Equipped creature gets +2/+0. Equip {2}
		counted_ptr<CEquipAbility> cpAbility(
			::CreateObject<CEquipAbility>(this, _T("2")));

		AddEquipBonus(cpAbility.GetPointer(), this, Power(+2), Life(+0));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Equipped creature has afflict 1. (Whenever it becomes blocked, defending player loses 1 life.)
		// The trigger is on the equipment (as Primal Cocoon in M11)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
							   CWhenAttackedBlocked::EventCallback, &CWhenAttackedBlocked::SetBlockedEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDaggerOfTheWorthyCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDaggerOfTheWorthyCard::BeforeAfflict));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CDaggerOfTheWorthyCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const
{
	return pCreature && GetEquippedOn() == pCreature;
}

// The defending player is the opponent of the equipped creature's controller (two-player games)
bool CDaggerOfTheWorthyCard::BeforeAfflict(CAbilityAction* pAction)
{
	CCard* pEquipped = GetEquippedOn();
	CPlayer* pAttacker = pEquipped ? pEquipped->GetController() : pAction->GetController();
	CLifeModifier pModifier = CLifeModifier(Life(-1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
		if (GetGame()->GetPlayer(ip) != pAttacker)
			pModifier.ApplyTo(GetGame()->GetPlayer(ip));
	return true;
}

CGodPharaohsGiftCard::CGodPharaohsGiftCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("God-Pharaoh's Gift"), CardType::Artifact, nID,
		_T("7"), AbilityType::Artifact)
	, m_CardSelection(pGame, CSelectionSupport::SelectionCallback(this, &CGodPharaohsGiftCard::OnCardSelected))
{
	// At the beginning of combat on your turn, you may exile a creature card from your graveyard. If you do, create a
	// token that's a copy of that card, except it's a 4/4 black Zombie. It gains haste until end of turn.
	// Note: the token is made as with Eternalize, so it keeps its other creature types
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodPharaohsGiftCard::BeforeChoose));
	AddAbility(cpAbility.GetPointer());
}

// The controller chooses up to one creature card in their graveyard
bool CGodPharaohsGiftCard::BeforeChoose(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < pGraveyard->GetSize(); ++i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (pCard->GetCardType().IsCreature())
		{
			SelectionEntry entry;
			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Exile %s and create a 4/4 Zombie copy"), pCard->GetCardName(TRUE));
			entries.push_back(entry);
		}
	}

	if (!entries.empty())
		m_CardSelection.AddSelectionRequest(entries, 0, 1, this, pController);
	return true;
}

void CGodPharaohsGiftCard::OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCard* pCard = (CCard*)it->dwContext;
			if (pCard->GetZoneId() != ZoneId::Graveyard)
				return;

			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
			if (pCard->GetZoneId() != ZoneId::Exile)
				return;

			// The creatures already on the battlefield, to find the new tokens
			CZone* pBattlefield = pSelectionPlayer->GetZoneById(ZoneId::Battlefield);
			CCountedCardContainer before;
			for (int i = 0; i < pBattlefield->GetSize(); ++i)
				before.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

			CEmbalmSupport::CreateZombieCopy(pCard, pSelectionPlayer, TRUE);

			// It gains haste until end of turn
			for (int i = 0; i < pBattlefield->GetSize(); ++i)
			{
				CCreatureCard* pToken = dynamic_cast<CCreatureCard*>(pBattlefield->GetAt(i));
				if (pToken && !before.HasCard(pToken) && pToken->GetCardType().IsToken())
				{
					CCreatureKeywordModifier pHaste;
					pHaste.GetModifier().SetToAdd(CreatureKeyword::Haste);
					pHaste.GetModifier().SetOneTurnOnly(TRUE);
					pHaste.ApplyTo(pToken);
				}
			}
			return;
		}
}

CSunsetPyramidCard::CSunsetPyramidCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Sunset Pyramid"), CardType::Artifact, nID,
		_T("2"), AbilityType::Artifact)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CSunsetPyramidCard::OnZoneChanged))
{
	// This artifact enters with three brick counters on it. (as CEntersWithCountersCreatureCard in Aether Revolt)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	{
		// {2}, {T}, Remove a brick counter from this artifact: Draw a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddTapCost();
		cpAbility->GetCost().AddCounterCost(GetCounterContainer()->GetCounter(BRICK_COUNTER), -1);
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
			new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}, {T}: Scry 1.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2")));

		cpAbility->AddTapCost();
		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(pGame, 1, this));
		AddAbility(cpAbility.GetPointer());
	}
}

void CSunsetPyramidCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this || moveType == MoveType::Phasing)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(BRICK_COUNTER, +3);
		pModifier.ApplyTo(this);
	}
}

CVisageOfBolasCard::CVisageOfBolasCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Visage of Bolas"), CardType::Artifact, nID,
		_T("4"), AbilityType::Artifact)
{
	{
		// When this artifact enters, you may search your library and/or graveyard for a card named Nicol Bolas, the
		// Deceiver, reveal it, and put it into your hand. If you search your library this way, shuffle.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
							   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CVisageOfBolasCard::BeforeSearch));
		AddAbility(cpAbility.GetPointer());
	}

	// {T}: Add {U}, {B}, or {R}.
	LPCTSTR colors[] = { BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		AddAbility(cpAbility.GetPointer());
	}
}

bool CVisageOfBolasCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Nicol Bolas, the Deceiver"));
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (enchantments)

#define DOOM_COUNTER			_T("doom counter")
#define SPHINX_AA_TOKEN_NAME	_T("Sphinx (AA)")
#define SPHINX_AA_TOKEN_ID		64123

// "if you control a Desert or there is a Desert card in your graveyard"
static BOOL HasDesert(CPlayer* pPlayer)
{
	CCardFilter filter(_T("a Desert"), _T("Deserts"), new CardTypeComparer(CardType::Desert, false));
	return filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0 ||
		filter.CountIncluded(pPlayer->GetZoneById(ZoneId::Graveyard)->GetCardContainer()) > 0;
}

// "pSource deals nDamage damage to pTarget" (a creature, as Amonkhet)
static void DealDamageToCreature(CCard* pSource, CCard* pTarget, int nDamage)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pTarget);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield || nDamage <= 0)
		return;

	CLifeModifier pModifier = CLifeModifier(Life(-nDamage), pSource, PreventableType::Preventable,
		DamageType::AbilityDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pCreature);
}

//____________________________________________________________________________
//
// Enchantments

CDesertsHoldCard::CDesertsHoldCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Desert's Hold"), nID,
		_T("2") WHITE_MANA_TEXT,
		Power(+0), Life(+0),
		CreatureKeyword::CantAttack | CreatureKeyword::CantBlock)
	, m_CardFilter(_T("enchanted by this"), _T("enchanted by this"), new EnchantedByComparer(this))
{
	// Enchanted creature can't attack or block, and its activated abilities can't be activated. (as Arrest)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	CCantActivateAbilitiesModifier* pModifier = new CCantActivateAbilitiesModifier(GetGame(), &m_CardFilter);
	m_pChgPwrTghAttrEnchant->GetCreatureKeywordMod().LinkCardModifier(pModifier);

	// When this Aura enters, if you control a Desert or there is a Desert card in your graveyard, you gain 3 life.
	AddEnterTrigger(this, &CDesertsHoldCard::BeforeGainLife);
}

bool CDesertsHoldCard::BeforeGainLife(CAbilityAction* pAction)
{
	if (HasDesert(pAction->GetController()))
		GainLife(this, pAction->GetController(), 3);
	return true;
}

CFrayingSanityCard::CFrayingSanityCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Fraying Sanity"), CardType::GlobalEnchantment, nID,
		_T("2") BLUE_MANA_TEXT, AbilityType::Enchantment)
	, m_nTurn(-1)
	, m_nCount(0)
{
	// Enchant player. At the beginning of each end step, enchanted player mills X cards, where X is the number of
	// cards put into their graveyard from anywhere this turn.
	// Note: the game has no Auras that enchant players: this curse is a global enchantment that always affects the
	// controller's opponent (as Cruel Reality in Amonkhet). The cards are counted while this enchantment is on the
	// battlefield.
	{
		// Counts the cards put into the opponent's graveyard (it never triggers)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Graveyard));

		cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CFrayingSanityCard::CountMove));
		AddAbility(cpAbility.GetPointer());
	}
	{
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFrayingSanityCard::BeforeMill));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFrayingSanityCard::CountMove(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	int nTurn = GetGame()->GetGameTurnNumber();
	if (nTurn != m_nTurn)
	{
		m_nTurn = nTurn;
		m_nCount = 0;
	}
	++m_nCount;
	return false;
}

bool CFrayingSanityCard::BeforeMill(CAbilityAction* pAction)
{
	int nCount = (m_nTurn == GetGame()->GetGameTurnNumber()) ? m_nCount : 0;
	if (nCount > 0)
		Mill(GetGame()->GetNextPlayer(pAction->GetController()), nCount);
	return true;
}

CImminentDoomCard::CImminentDoomCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Imminent Doom"), CardType::GlobalEnchantment, nID,
		_T("2") RED_MANA_TEXT, AbilityType::Enchantment)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CImminentDoomCard::OnZoneChanged))
{
	// This enchantment enters with a doom counter on it. (as Sunset Pyramid)
	GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());

	// Whenever you cast a spell with mana value equal to the number of doom counters on this enchantment, this
	// enchantment deals that much damage to any target. Then put a doom counter on this enchantment.
	// Note: the damage is the number of doom counters on resolution; it can't target planeswalkers
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CImminentDoomCard::SetTriggerContext));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImminentDoomCard::BeforeDamage));
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

bool CImminentDoomCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const
{
	const Counter* pCounter = ((const CCard*)this)->GetCounterContainer()->GetCounter(DOOM_COUNTER);
	int nDoom = pCounter ? pCounter->GetCount() : 0;
	return pCard && (int)pCard->GetConvertedManaCost() == nDoom;
}

bool CImminentDoomCard::BeforeDamage(CAbilityAction* pAction)
{
	const Counter* pCounter = ((const CCard*)this)->GetCounterContainer()->GetCounter(DOOM_COUNTER);
	int nDamage = pCounter ? pCounter->GetCount() : 0;

	if (nDamage > 0)
	{
		CPlayer* pPlayer = pAction->GetAssociatedPlayer();
		if (pPlayer)
		{
			CLifeModifier pModifier = CLifeModifier(Life(-nDamage), this, PreventableType::Preventable,
				DamageType::AbilityDamage | DamageType::NonCombatDamage);
			pModifier.ApplyTo(pPlayer);
		}
		else
			DealDamageToCreature(this, pAction->GetAssociatedCard(), nDamage);
	}

	// Then put a doom counter on this enchantment.
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(DOOM_COUNTER, +1);
		pModifier.ApplyTo(this);
	}
	return false;
}

void CImminentDoomCard::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (!pFromZone || !pToZone || pCard != this || moveType == MoveType::Phasing)
		return;

	if (pFromZone->GetZoneId() != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(DOOM_COUNTER, +1);
		pModifier.ApplyTo(this);
	}
}

CRiddleformCard::CRiddleformCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Riddleform"), CardType::GlobalEnchantment, nID,
		_T("1") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	{
		// Whenever you cast a noncreature spell, you may have this enchantment become a 3/3 Sphinx creature with
		// flying in addition to its other types until end of turn. (as Sydri, Galvanic Genius in Commander 2013)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new NegateCardComparer(new CardTypeComparer(CardType::Creature, false)));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRiddleformCard::BeforeAnimate));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{U}: Scry 1.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLUE_MANA_TEXT));

		cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(pGame, 1, this));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CRiddleformCard::BeforeAnimate(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield || GetIsAlsoA())
		return true;

	CCardIsAlsoAModifier* pModifier1 = new CCardIsAlsoAModifier(SPHINX_AA_TOKEN_NAME, SPHINX_AA_TOKEN_ID, pAction->GetController());
	CScheduledCardModifier pModifier2 = CScheduledCardModifier(
		GetGame(), pModifier1, TurnNumberDelta(-1), NodeId::CleanupStep2, true, CScheduledCardModifier::Operation::RemoveFromLater);

	pModifier1->ApplyTo(this);
	pModifier2.ApplyTo(this);
	return true;
}

CSwarmIntelligenceCard::CSwarmIntelligenceCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Swarm Intelligence"), CardType::GlobalEnchantment, nID,
		_T("6") BLUE_MANA_TEXT, AbilityType::Enchantment)
{
	// Whenever you cast an instant or sorcery spell, you may copy that spell. You may choose new targets for the copy.
	// (as Cloven Casting in Alara Reborn)
	typedef
		TTriggeredAbility< CTriggeredCopyCastAbility1, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CSwarmIntelligenceCard::SetTriggerContext));
	AddAbility(cpAbility.GetPointer());
}

bool CSwarmIntelligenceCard::SetTriggerContext(CTriggeredCopyCastAbility1::TriggerContextType& triggerContext, CCard* pCard) const
{
	triggerContext.m_pCard = pCard;

	const CStack& stack = m_pGame->GetStack();
	for (int l = 0; l < stack.GetStackSize(); ++l)
	{
		triggerContext.m_pStackAction = const_cast<CStackAbilityAction*>(stack.GetStackAction(l).GetPointer());
		if (triggerContext.m_pStackAction->IsSpell() && (triggerContext.m_pStackAction->GetAbility()->GetCard() == pCard))
			break;
	}
	return true;
}

CTormentOfScarabsCard::CTormentOfScarabsCard(CGame* pGame, UINT nID)
	: CInPlaySpellCard(pGame, _T("Torment of Scarabs"), CardType::GlobalEnchantment, nID,
		_T("3") BLACK_MANA_TEXT, AbilityType::Enchantment)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTormentOfScarabsCard::OnChoiceSelected))
	, m_NonlandFilter(_T("a nonland permanent"), _T("nonland permanents"),
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Enchant player. At the beginning of enchanted player's upkeep, that player loses 3 life unless they sacrifice a
	// nonland permanent of their choice or discard a card.
	// Note: the game has no Auras that enchant players: this curse is a global enchantment that always affects the
	// controller's opponent (as Cruel Reality in Amonkhet)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTormentOfScarabsCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTormentOfScarabsCard::BeforeChoice));
	AddAbility(cpAbility.GetPointer());
}

bool CTormentOfScarabsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetGame()->GetActivePlayer() != GetController();
}

// The cursed player chooses: sacrifice a nonland permanent, discard a card or lose 3 life (as Nicol Bolas, the Deceiver)
bool CTormentOfScarabsCard::BeforeChoice(CAbilityAction* pAction)
{
	CPlayer* pCursed = GetGame()->GetNextPlayer(pAction->GetController());

	std::vector<SelectionEntry> entries;
	if (m_NonlandFilter.CountIncluded(pCursed->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_SACRIFICE;
		entry.strText = _T("Sacrifice a nonland permanent");
		entries.push_back(entry);
	}
	if (pCursed->GetZoneById(ZoneId::Hand)->GetSize() > 0)
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_DISCARD;
		entry.strText = _T("Discard a card");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_LOSE_LIFE;
		entry.strText = _T("Lose 3 life");
		entries.push_back(entry);
	}

	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pCursed);
	return true;
}

void CTormentOfScarabsCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == BOLAS_CHOICE_SACRIFICE &&
				SacrificeOne(GetGame(), pSelectionPlayer, &m_NonlandFilter))
				return;

			if (it->dwContext == BOLAS_CHOICE_DISCARD &&
				pSelectionPlayer->GetZoneById(ZoneId::Hand)->GetSize() > 0)
			{
				DiscardCards(GetGame(), pSelectionPlayer, 1);
				return;
			}

			CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pSelectionPlayer);
			return;
		}
}

CUnquenchableThirstCard::CUnquenchableThirstCard(CGame* pGame, UINT nID)
	: CChgPwrTghAttrEnchantCard(pGame, _T("Unquenchable Thirst"), nID,
		_T("1") BLUE_MANA_TEXT,
		Power(+0), Life(+0))
{
	// Enchanted creature doesn't untap during its controller's untap step. (as Claustrophobia)
	m_pChgPwrTghAttrEnchant->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	m_pChgPwrTghAttrEnchant->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::NoUntapInUntapPhase);

	// When this Aura enters, if you control a Desert or there is a Desert card in your graveyard, tap enchanted
	// creature.
	AddEnterTrigger(this, &CUnquenchableThirstCard::BeforeTap);
}

bool CUnquenchableThirstCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCreature = m_pChgPwrTghAttrEnchant->GetEnchantedOnCard();
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && HasDesert(pAction->GetController()))
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (sorceries)

#define SNAKE_J_TOKEN_NAME	_T("Snake (J)")
#define SNAKE_J_TOKEN_ID	55099

// The first half of an Aftermath card: cast only from the hand (as Amonkhet)
static void SetFirstHalf(CSpell* pSpell, LPCTSTR strName)
{
	CAftermathSupport::SetFirstHalf(pSpell);
	pSpell->SetAbilityName(strName);

	CString strText;
	strText.Format(_T("%s. Casts"), strName);
	pSpell->SetAbilityText(strText);
}

// The permanent doesn't untap during its controller's next untap step (as Aether Revolt)
static void SkipNextUntap(CGame* pGame, CCard* pCard)
{
	CScheduledCardModifier pModifier = CScheduledCardModifier(pGame,
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pModifier.ApplyTo(pCard);
}

// "Lands you control don't untap during your next untap step."
static void SkipLandsUntap(CGame* pGame, CPlayer* pPlayer)
{
	CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	CCountedCardContainer lands;
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
		if (pBattlefield->GetAt(i)->GetCardType().IsLand())
			lands.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);

	for (int i = 0; i < lands.GetSize(); ++i)
		SkipNextUntap(pGame, lands.GetAt(i));
}

// Search pPlayer's library for up to nMax cards that pass pFilter, put them onto the battlefield tapped, then shuffle
// (as Harvest Season's search in Amonkhet)
static void SearchLandsTapped(CGame* pGame, CPlayer* pPlayer, int nMax, const CCardFilter* pFilter)
{
	CCountedCardContainer lands;
	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &lands);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nMax), // up to N land cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		pFilter, // what cards
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

// The player exiles one permanent of their choice among those that pass pFilter (as SacrificeOne)
static BOOL ExileOne(CGame* pGame, CPlayer* pPlayer, const CCardFilter* pFilter)
{
	if (pFilter->CountIncluded(pPlayer->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
		return FALSE;

	CZoneModifier pModifier = CZoneModifier(pGame, ZoneId::Battlefield, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // select the permanent to exile
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		pFilter, // what cards
		ZoneId::Exile, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pPlayer);
	return TRUE;
}

// The creatures controlled by pPlayer gain the keyword until end of turn
static void CreaturesGainKeyword(CGame* pGame, CPlayer* pPlayer, CreatureKeyword keyword)
{
	CCountedCardContainer creatures;
	GetCreatures(pGame, pPlayer, TRUE, creatures);

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(keyword);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
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

// The permanent is destroyed (it goes to its owner's graveyard)
static void DestroyPermanent(CCard* pCard, CPlayer* pByPlayer)
{
	if (pCard->GetZoneId() != ZoneId::Battlefield)
		return;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy, pByPlayer);
	pModifier.ApplyTo(pCard);
}

//____________________________________________________________________________
//
// Sorceries

CAppealAuthorityCard::CAppealAuthorityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Appeal // Authority"), CardType::Sorcery, nID)
{
	{
		// Appeal: Until end of turn, target creature gains trample and gets +X/+X, where X is the number of creatures
		// you control.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				GREEN_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAppealAuthorityCard::BeforeAppeal));
		SetFirstHalf(cpSpell.GetPointer(), _T("Appeal"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Authority: Tap up to two target creatures your opponents control. Creatures you control gain vigilance until
		// end of turn.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("1") WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetSubjectCount(0, 2);
		cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAppealAuthorityCard::BeforeAuthority));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Authority"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CAppealAuthorityCard::BeforeAppeal(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	int nX = creatures.GetSize();
	PumpCreature(pAction->GetAssociatedCard(), nX, nX, CreatureKeyword::Trample);
	return true;
}

bool CAppealAuthorityCard::BeforeAuthority(CAbilityAction* pAction)
{
	CreaturesGainKeyword(GetGame(), pAction->GetController(), CreatureKeyword::Vigilance);
	return true;
}

CBeneathTheSandsCard::CBeneathTheSandsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Beneath the Sands"), CardType::Sorcery, nID)
{
	// Search your library for a basic land card, put it onto the battlefield tapped, then shuffle.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("2") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBeneathTheSandsCard::BeforeSearch));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CBeneathTheSandsCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchLandsTapped(GetGame(), pAction->GetController(), 1, CCardFilter::GetFilter(_T("basic lands")));
	return true;
}

CBontusLastReckoningCard::CBontusLastReckoningCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Bontu's Last Reckoning"), CardType::Sorcery, nID)
{
	// Destroy all creatures. Lands you control don't untap during your next untap step.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBontusLastReckoningCard::BeforeDestroy));
	AddSpell(cpSpell.GetPointer());
}

bool CBontusLastReckoningCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		DestroyPermanent(creatures.GetAt(i), pAction->GetController());

	SkipLandsUntap(GetGame(), pAction->GetController());
	return true;
}

CClaimFameCard::CClaimFameCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Claim // Fame"), CardType::Sorcery, nID)
{
	{
		// Claim: Return target creature card with mana value 2 or less from your graveyard to the battlefield.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new ConvertedManaCostComparer<std::less_equal<int>>(2));
		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		SetFirstHalf(cpSpell.GetPointer(), _T("Claim"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Fame: Target creature gets +2/+0 and gains haste until end of turn.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("1") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CClaimFameCard::BeforeFame));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Fame"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CClaimFameCard::BeforeFame(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +2, +0, CreatureKeyword::Haste);
	return true;
}

CConsignOblivionCard::CConsignOblivionCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Consign // Oblivion"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Consign: Return target nonland permanent to its owner's hand.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("1") BLUE_MANA_TEXT,
				new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)),
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		SetFirstHalf(cpSpell.GetPointer(), _T("Consign"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Oblivion: Target opponent discards two cards.
		counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
			::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
				_T("4") BLACK_MANA_TEXT,
				2, MoveType::Discard, ZoneId::Graveyard, TRUE,
				TRUE,
				CCardFilter::GetFilter(_T("cards"))));

		cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Oblivion"));
		AddSpell(cpSpell.GetPointer());
	}
}

CCrashThroughCard::CCrashThroughCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Crash Through"), CardType::Sorcery, nID)
{
	// Creatures you control gain trample until end of turn. Draw a card.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrashThroughCard::BeforeTrample));
	cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
	AddSpell(cpSpell.GetPointer());
}

bool CCrashThroughCard::BeforeTrample(CAbilityAction* pAction)
{
	CreaturesGainKeyword(GetGame(), pAction->GetController(), CreatureKeyword::Trample);
	return true;
}

CDoomfallCard::CDoomfallCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Doomfall"), CardType::Sorcery, nID)
	, m_NonlandFilter(_T("a nonland card"), _T("nonland cards"),
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Choose one -
	{
		// Target opponent exiles a creature they control.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("2") BLACK_MANA_TEXT,
				FALSE_CARD_COMPARER, TRUE));

		cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetAbilityText(_T("Target opponent exiles a creature they control. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDoomfallCard::BeforeExileCreature));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Target opponent reveals their hand. You choose a nonland card from it. Exile that card.
		counted_ptr<CTargetPlayerDiscardCardSpell> cpSpell(
			::CreateObject<CTargetPlayerDiscardCardSpell>(this, AbilityType::Sorcery,
				_T("2") BLACK_MANA_TEXT,
				1, MoveType::Others, ZoneId::Exile, TRUE,
				FALSE,
				&m_NonlandFilter));

		cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
		cpSpell->SetShowHandBeforeDiscards();
		cpSpell->SetAbilityText(_T("Target opponent reveals their hand. You choose a nonland card from it. Exile that card. Casts"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CDoomfallCard::BeforeExileCreature(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (pOpponent)
		ExileOne(GetGame(), pOpponent, CCardFilter::GetFilter(_T("creatures")));
	return true;
}

CFarmMarketCard::CFarmMarketCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Farm // Market"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Farm: Destroy target attacking or blocking creature.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("2") WHITE_MANA_TEXT,
				new AttackingBlockingCreatureComparer,
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		SetFirstHalf(cpSpell.GetPointer(), _T("Farm"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Market: Draw two cards, then discard two cards.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("2") BLUE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFarmMarketCard::BeforeMarket));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Market"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CFarmMarketCard::BeforeMarket(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 2);
	DiscardCards(GetGame(), pAction->GetController(), 2);
	return true;
}

CGrindDustCard::CGrindDustCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Grind // Dust"), CardType::Sorcery, nID)
{
	{
		// Grind: Put a -1/-1 counter on each of up to two target creatures.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("1") BLACK_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetSubjectCount(1, 2);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("-1/-1"), 1));
		SetFirstHalf(cpSpell.GetPointer(), _T("Grind"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Dust: Exile any number of target creatures that have -1/-1 counters on them.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
				_T("3") WHITE_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(
			new CardCounterComparer<std::greater_equal<int>>(_T("-1/-1"), 1));
		cpSpell->GetTargeting()->SetSubjectCount(1, SpecialNumber::Any);
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Dust"));
		AddSpell(cpSpell.GetPointer());
	}
}

CHourOfDevastationCard::CHourOfDevastationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hour of Devastation"), CardType::Sorcery, nID)
{
	// All creatures lose indestructible until end of turn. Hour of Devastation deals 5 damage to each creature and
	// each non-Bolas planeswalker.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") RED_MANA_TEXT RED_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHourOfDevastationCard::BeforeDamage));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CHourOfDevastationCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);

	CCardKeywordModifier pIndestructible;
	pIndestructible.GetModifier().SetToRemove(CardKeyword::Indestructible);
	pIndestructible.GetModifier().SetOneTurnOnly(TRUE);
	for (int i = 0; i < creatures.GetSize(); ++i)
		pIndestructible.ApplyTo(creatures.GetAt(i));

	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-5), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		if (creatures.GetAt(i)->GetZoneId() == ZoneId::Battlefield)
			pModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
	}

	// The damage to a planeswalker removes that many loyalty counters
	CCountedCardContainer planeswalkers;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			CPlaneswalkerCard* pPlaneswalker = dynamic_cast<CPlaneswalkerCard*>(pBattlefield->GetAt(i));
			if (pPlaneswalker && pPlaneswalker->GetSubtype() != PlaneswalkerType::Bolas)
				planeswalkers.AddCard(pPlaneswalker, CardPlacement::Top);
		}
	}
	CCardCounterModifier pLoyalty = CCardCounterModifier(LOYALTY_COUNTER, -5);
	for (int i = 0; i < planeswalkers.GetSize(); ++i)
		pLoyalty.ApplyTo(planeswalkers.GetAt(i));
	return true;
}

CHourOfEternityCard::CHourOfEternityCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hour of Eternity"), CardType::Sorcery, nID)
{
	// Exile X target creature cards from your graveyard. For each card exiled this way, create a token that's a copy
	// of that card, except it's a 4/4 black Zombie.
	// Note: the cards are chosen on resolution (not targeted); the tokens keep their other creature types (as Eternalize)
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			BLUE_MANA_TEXT BLUE_MANA_TEXT BLUE_MANA_TEXT));

	// {X}{X}{U}{U}{U}: X is half of the extra mana paid (as Wildest Dreams in Kaladesh)
	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, TRUE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHourOfEternityCard::BeforeCopies));
	cpSpell->AddAbilityTag(AbilityTag::TokenCreation);
	AddSpell(cpSpell.GetPointer());
}

bool CHourOfEternityCard::BeforeCopies(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX <= 0)
		return true;

	CPlayer* pController = pAction->GetController();
	CCountedCardContainer exiled;
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Graveyard, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &exiled);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nX), // up to X creature cards
		CZoneModifier::RoleType::PrimaryPlayer,	// select by
		CZoneModifier::RoleType::AllPlayers,	// reveal to
		CCardFilter::GetFilter(_T("creatures")),	// creature cards
		ZoneId::Exile,							// if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top,
		MoveType::Others,						// move type
		CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.ApplyTo(pController);

	for (int i = 0; i < exiled.GetSize(); ++i)
		if (exiled.GetAt(i)->GetZoneId() == ZoneId::Exile)
			CEmbalmSupport::CreateZombieCopy(exiled.GetAt(i), pController, TRUE);
	return true;
}

CHourOfPromiseCard::CHourOfPromiseCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hour of Promise"), CardType::Sorcery, nID)
{
	// Search your library for up to two land cards, put them onto the battlefield tapped, then shuffle. Then if you
	// control three or more Deserts, create two 2/2 black Zombie creature tokens.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHourOfPromiseCard::BeforeSearch));
	AddSpell(cpSpell.GetPointer());
}

bool CHourOfPromiseCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	SearchLandsTapped(GetGame(), pController, 2, CCardFilter::GetFilter(_T("lands")));

	CCardFilter filter(_T("a Desert"), _T("Deserts"), new CardTypeComparer(CardType::Desert, false));
	if (filter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) >= 3)
	{
		CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), ZOMBIE_TOKEN_NAME, ZOMBIE_TOKEN_ID, 2);
		pModifier.ApplyTo(pController);
	}
	return true;
}

CHourOfRevelationCard::CHourOfRevelationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hour of Revelation"), CardType::Sorcery, nID)
{
	// Destroy all nonland permanents.
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHourOfRevelationCard::BeforeDestroy));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// This spell costs {3} less to cast if there are ten or more nonland permanents on the battlefield.
		// (a second way to cast it)
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				WHITE_MANA_TEXT WHITE_MANA_TEXT WHITE_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHourOfRevelationCard::BeforeDestroy));
		cpSpell->SetAbilityText(_T("Destroy all nonland permanents (costs {3} less: ten or more nonland permanents). Casts"));
		AddPlayableIf(this, cpSpell.GetPointer(), &CHourOfRevelationCard::HasTenNonlandPermanents);
		AddSpell(cpSpell.GetPointer());
	}
}

BOOL CHourOfRevelationCard::HasTenNonlandPermanents(BOOL bIncludeTricks)
{
	int nCount = 0;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (!pBattlefield->GetAt(i)->GetCardType().IsLand())
				++nCount;
	}
	return nCount >= 10;
}

bool CHourOfRevelationCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCountedCardContainer permanents;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CZone* pBattlefield = GetGame()->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
			if (!pBattlefield->GetAt(i)->GetCardType().IsLand())
				permanents.AddCard(pBattlefield->GetAt(i), CardPlacement::Top);
	}

	for (int i = 0; i < permanents.GetSize(); ++i)
		DestroyPermanent(permanents.GetAt(i), pAction->GetController());
	return true;
}

CInfernoJetCard::CInfernoJetCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Inferno Jet"), CardType::Sorcery, nID)
{
	// Inferno Jet deals 6 damage to target opponent or planeswalker.
	// Note: it can't target planeswalkers
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("5") RED_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE,
			Life(-6), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CKefnetsLastWordCard::CKefnetsLastWordCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Kefnet's Last Word"), CardType::Sorcery, nID)
{
	// Gain control of target artifact, creature, or enchantment. Lands you control don't untap during your next untap
	// step.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
			_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Artifact | CardType::Creature | CardType::_Enchantment, false), FALSE));

	cpSpell->GetTargeting()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CKefnetsLastWordCard::BeforeControl));
	AddSpell(cpSpell.GetPointer());
}

bool CKefnetsLastWordCard::BeforeControl(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		// (as Rags // Riches in Amonkhet: the control goes to this card's controller)
		CGainControlModifier pModifier = CGainControlModifier(GetGame(), this);
		pModifier.ApplyTo(pCard);
	}

	SkipLandsUntap(GetGame(), pAction->GetController());
	return true;
}

CLeaveChanceCard::CLeaveChanceCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Leave // Chance"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Leave: Return any number of target permanents you own to your hand.
		// Note: the permanents you control
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("1") WHITE_MANA_TEXT,
				new TrueCardComparer,
				ZoneId::Battlefield, ZoneId::Hand, TRUE, MoveType::Others));

		cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
		cpSpell->GetTargeting()->SetSubjectCount(1, SpecialNumber::Any);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		SetFirstHalf(cpSpell.GetPointer(), _T("Leave"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Chance: Discard any number of cards, then draw that many cards.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("3") RED_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLeaveChanceCard::BeforeChance));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Chance"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CLeaveChanceCard::BeforeChance(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nHand = pController->GetZoneById(ZoneId::Hand)->GetSize();
	if (nHand <= 0)
		return true;

	CCountedCardContainer discarded;
	CZoneModifier pModifier = CZoneModifier(GetGame(),
		ZoneId::Hand, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer, &discarded);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(nHand), // any number of cards
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Graveyard, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Discard, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	if (discarded.GetSize() > 0)
		DrawCards(GetGame(), pController, discarded.GetSize());
	return true;
}

CLethalStingCard::CLethalStingCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Lethal Sting"), CardType::Sorcery, nID)
	, m_CreatureFilter(_T("a creature you control"), _T("creatures you control"), new AnyCreatureComparer)
{
	// As an additional cost to cast this spell, put a -1/-1 counter on a creature you control. Destroy target creature.
	// (the counter cost as Alliances)
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetCost().AddAnyCardCounterCost(_T("-1/-1"), +1, 1, &m_CreatureFilter);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddSpell(cpSpell.GetPointer());
}

CLilianasDefeatCard::CLilianasDefeatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Liliana's Defeat"), CardType::Sorcery, nID)
{
	// Destroy target black creature or black planeswalker. If that permanent was a Liliana planeswalker, her controller
	// loses 3 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT,
			new CardTypeComparer(CardType::Creature | CardType::Planeswalker, false),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Black, false));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLilianasDefeatCard::BeforeDestroy));
	AddSpell(cpSpell.GetPointer());
}

bool CLilianasDefeatCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && PlaneswalkerTypeComparer(PlaneswalkerType::Liliana)(pCard))
	{
		CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pCard->GetController());
	}
	return true;
}

CNissasDefeatCard::CNissasDefeatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nissa's Defeat"), CardType::Sorcery, nID)
{
	// Destroy target Forest, green enchantment, or green planeswalker. If that permanent was a Nissa planeswalker,
	// draw a card.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Sorcery,
			_T("2") GREEN_MANA_TEXT,
			new OrCardComparer(
				new CardTypeComparer(CardType::Forest, false),
				new AndCardComparer(new CardTypeComparer(CardType::_Enchantment, false), new CardTypeComparer(CardType::Green, false)),
				new AndCardComparer(new CardTypeComparer(CardType::Planeswalker, false), new CardTypeComparer(CardType::Green, false))),
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissasDefeatCard::BeforeDestroy));
	AddSpell(cpSpell.GetPointer());
}

bool CNissasDefeatCard::BeforeDestroy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield && PlaneswalkerTypeComparer(PlaneswalkerType::Nissa)(pCard))
		DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CNissasEncouragementCard::CNissasEncouragementCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Nissa's Encouragement"), CardType::Sorcery, nID)
{
	// Search your library and graveyard for a card named Forest, a card named Brambleweft Behemoth, and a card named
	// Nissa, Genesis Mage. Reveal those cards, put them into your hand, then shuffle.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("4") GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNissasEncouragementCard::BeforeSearch));
	AddSpell(cpSpell.GetPointer());
}

bool CNissasEncouragementCard::BeforeSearch(CAbilityAction* pAction)
{
	SearchNamedCardToHand(pAction->GetController(), _T("Forest"));
	SearchNamedCardToHand(pAction->GetController(), _T("Brambleweft Behemoth"));
	SearchNamedCardToHand(pAction->GetController(), _T("Nissa, Genesis Mage"));
	return true;
}

COketrasLastMercyCard::COketrasLastMercyCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Oketra's Last Mercy"), CardType::Sorcery, nID)
{
	// Your life total becomes equal to your starting life total. Lands you control don't untap during your next untap
	// step.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("1") WHITE_MANA_TEXT WHITE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COketrasLastMercyCard::BeforeLife));
	cpSpell->AddAbilityTag(AbilityTag::LifeGain);
	AddSpell(cpSpell.GetPointer());
}

bool COketrasLastMercyCard::BeforeLife(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	Life nDelta = pController->GetStartingLife() - pController->GetLife();
	if (nDelta != Life(0))
	{
		CLifeModifier pModifier = CLifeModifier(nDelta, this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
		pModifier.ApplyTo(pController);
	}

	SkipLandsUntap(GetGame(), pController);
	return true;
}

COvercomeCard::COvercomeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Overcome"), CardType::Sorcery, nID)
{
	// Creatures you control get +2/+2 and gain trample until end of turn.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") GREEN_MANA_TEXT GREEN_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COvercomeCard::BeforePump));
	AddSpell(cpSpell.GetPointer());
}

bool COvercomeCard::BeforePump(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		PumpCreature(creatures.GetAt(i), +2, +2, CreatureKeyword::Trample);
	return true;
}

CPuncturingBlowCard::CPuncturingBlowCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Puncturing Blow"), CardType::Sorcery, nID)
{
	// Puncturing Blow deals 5 damage to target creature. If that creature would die this turn, exile it instead.
	// (as Magma Spray in Shards of Alara)
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Sorcery,
			_T("2") RED_MANA_TEXT RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-5), PreventableType::Preventable));

	CReplacementKeywordModifier* pModifier = new CReplacementKeywordModifier();
	pModifier->GetModifier().SetOneTurnOnly(TRUE);
	pModifier->GetModifier().SetToAdd(ReplacementKeyword::GraveyardToExile);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(pModifier);

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CRazakethsRiteCard::CRazakethsRiteCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Razaketh's Rite"), CardType::Sorcery, nID)
{
	// Search your library for a card, put that card into your hand, then shuffle.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			_T("3") BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRazakethsRiteCard::BeforeSearch));
	AddSpell(cpSpell.GetPointer());

	// Cycling {B}
	AddCycling(this, BLACK_MANA_TEXT);
}

bool CRazakethsRiteCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

#define BELIEVE_BATTLEFIELD	1
#define BELIEVE_HAND		2

CReasonBelieveCard::CReasonBelieveCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Reason // Believe"), CardType::Sorcery, nID)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CReasonBelieveCard::OnChoiceSelected))
{
	{
		// Reason: Scry 3.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				BLUE_MANA_TEXT));

		cpSpell->GetResolutionModifier().CPlayerModifiers::push_back(new CScryModifier(pGame, 3, this));
		SetFirstHalf(cpSpell.GetPointer(), _T("Reason"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Believe: Look at the top card of your library. You may put it onto the battlefield if it's a creature card.
		// If you don't, put it into your hand.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("4") GREEN_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CReasonBelieveCard::BeforeBelieve));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Believe"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CReasonBelieveCard::BeforeBelieve(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() == 0)
		return true;

	CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1);
	if (!pCard->GetCardType().IsCreature())
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(pCard);
		return true;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = BELIEVE_BATTLEFIELD;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s onto the battlefield"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = BELIEVE_HAND;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s into your hand"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}
	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pController, (DWORD)pCard);
	return true;
}

void CReasonBelieveCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CCard* pCard = (CCard*)dwContext1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Library)
		return;

	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Library,
				it->dwContext == BELIEVE_BATTLEFIELD ? ZoneId::Battlefield : ZoneId::Hand,
				TRUE, MoveType::Others, pSelectionPlayer);
			pModifier.ApplyTo(pCard);
			return;
		}
}

CRhonassLastStandCard::CRhonassLastStandCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Rhonas's Last Stand"), CardType::Sorcery, nID)
{
	// Create a 5/4 green Snake creature token. Lands you control don't untap during your next untap step.
	counted_ptr<CTokenProductionSpell> cpSpell(
		::CreateObject<CTokenProductionSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT GREEN_MANA_TEXT,
			SNAKE_J_TOKEN_NAME, SNAKE_J_TOKEN_ID,
			1));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRhonassLastStandCard::BeforeSkipUntap));
	AddSpell(cpSpell.GetPointer());
}

bool CRhonassLastStandCard::BeforeSkipUntap(CAbilityAction* pAction)
{
	SkipLandsUntap(GetGame(), pAction->GetController());
	return true;
}

CStruggleSurviveCard::CStruggleSurviveCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Struggle // Survive"), CardType::Instant | CardType::Sorcery, nID)
{
	{
		// Struggle: Struggle deals damage to target creature equal to the number of lands you control.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Instant,
				_T("2") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStruggleSurviveCard::BeforeStruggle));
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		SetFirstHalf(cpSpell.GetPointer(), _T("Struggle"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Survive: Each player shuffles their graveyard into their library.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
				_T("1") GREEN_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStruggleSurviveCard::BeforeSurvive));
		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Survive"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CStruggleSurviveCard::BeforeStruggle(CAbilityAction* pAction)
{
	int nLands = CCardFilter::GetFilter(_T("lands"))->CountIncluded(
		pAction->GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer());

	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pAction->GetAssociatedCard());
	if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield && nLands > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nLands), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCreature);
	}
	return true;
}

bool CStruggleSurviveCard::BeforeSurvive(CAbilityAction* pAction)
{
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		CZone* pGraveyard = pPlayer->GetZoneById(ZoneId::Graveyard);

		CCountedCardContainer cards;
		for (int i = 0; i < pGraveyard->GetSize(); ++i)
			if (pGraveyard->GetAt(i) != this)	// this card is still resolving
				cards.AddCard(pGraveyard->GetAt(i), CardPlacement::Top);

		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Library, TRUE, MoveType::Others);
		for (int i = 0; i < cards.GetSize(); ++i)
			if (cards.GetAt(i)->GetZoneId() == ZoneId::Graveyard)
				pModifier.ApplyTo(cards.GetAt(i));

		pPlayer->GetZoneById(ZoneId::Library)->Shuffle();
	}
	return true;
}

CTormentOfHailfireCard::CTormentOfHailfireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Torment of Hailfire"), CardType::Sorcery, nID)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTormentOfHailfireCard::OnChoiceSelected))
	, m_NonlandFilter(_T("a nonland permanent"), _T("nonland permanents"),
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Repeat the following process X times. Each opponent loses 3 life unless that player sacrifices a nonland
	// permanent of their choice or discards a card.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			BLACK_MANA_TEXT BLACK_MANA_TEXT));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTormentOfHailfireCard::BeforeTorment));
	cpSpell->AddAbilityTag(AbilityTag::LifeLost);
	AddSpell(cpSpell.GetPointer());
}

bool CTormentOfHailfireCard::BeforeTorment(CAbilityAction* pAction)
{
	int nX = GetX(pAction);
	if (nX > 0)
		RequestChoice(GetGame()->GetNextPlayer(pAction->GetController()), nX);
	return true;
}

// The opponent chooses (dwContext1: the number of times left, this one included)
void CTormentOfHailfireCard::RequestChoice(CPlayer* pOpponent, int nRemaining)
{
	std::vector<SelectionEntry> entries;
	if (m_NonlandFilter.CountIncluded(pOpponent->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_SACRIFICE;
		entry.strText = _T("Sacrifice a nonland permanent");
		entries.push_back(entry);
	}
	if (pOpponent->GetZoneById(ZoneId::Hand)->GetSize() > 0)
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_DISCARD;
		entry.strText = _T("Discard a card");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_LOSE_LIFE;
		entry.strText = _T("Lose 3 life");
		entries.push_back(entry);
	}

	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pOpponent, (DWORD)nRemaining);
}

void CTormentOfHailfireCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == BOLAS_CHOICE_SACRIFICE &&
				SacrificeOne(GetGame(), pSelectionPlayer, &m_NonlandFilter))
				break;

			if (it->dwContext == BOLAS_CHOICE_DISCARD &&
				pSelectionPlayer->GetZoneById(ZoneId::Hand)->GetSize() > 0)
			{
				DiscardCards(GetGame(), pSelectionPlayer, 1);
				break;
			}

			CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pSelectionPlayer);
			break;
		}

	// Repeat the process
	int nRemaining = (int)dwContext1 - 1;
	if (nRemaining > 0)
		RequestChoice(pSelectionPlayer, nRemaining);
}

CUncageTheMenagerieCard::CUncageTheMenagerieCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Uncage the Menagerie"), CardType::Sorcery, nID)
	, m_SearchFilter(_T("a creature card"), _T("creature cards"), new CardTypeComparer(CardType::Creature, false))
{
	// Search your library for up to X creature cards with different names that each have mana value X, reveal them,
	// put them into your hand, then shuffle.
	// Partial: the names aren't checked
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Sorcery,
			GREEN_MANA_TEXT GREEN_MANA_TEXT));

	cpSpell->GetCost().SetExtraManaCost(SpecialNumber::Any, TRUE, CManaCost::AllCostColors, FALSE);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUncageTheMenagerieCard::BeforeSearch));
	AddSpell(cpSpell.GetPointer());
}

bool CUncageTheMenagerieCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nX = GetX(pAction);
	if (nX > 0)
	{
		// (as Scrap Trawler in Aether Revolt)
		m_SearchFilter.SetComparer(new CardTypeComparer(CardType::Creature, false));
		m_SearchFilter.AddComparer(new ConvertedManaCostComparer<std::equal_to<int>>(nX));

		CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
			CZoneModifier::RoleType::PrimaryPlayer,
			CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
		pModifier.AddSelection(MinimumValue(0), MaximumValue(nX), // up to X creature cards with mana value X
			CZoneModifier::RoleType::PrimaryPlayer, // select by
			CZoneModifier::RoleType::AllPlayers, // reveal to
			&m_SearchFilter, // what cards
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

CUnconventionalTacticsCard::CUnconventionalTacticsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Unconventional Tactics"), CardType::Sorcery, nID)
{
	{
		// Target creature gets +3/+3 and gains flying until end of turn.
		counted_ptr<CTargetSpell> cpSpell(
			::CreateObject<CTargetSpell>(this, AbilityType::Sorcery,
				_T("2") WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUnconventionalTacticsCard::BeforePump));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Whenever a Zombie you control enters, you may pay {W}. If you do, return this card from your graveyard to
		// your hand. (a trigger of a card in the graveyard)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield, FALSE, TRUE, FALSE));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
		cpAbility->SetResolutionCost(WHITE_MANA_TEXT);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CUnconventionalTacticsCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUnconventionalTacticsCard::BeforeReturn));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CUnconventionalTacticsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	return GetZoneId() == ZoneId::Graveyard;
}

bool CUnconventionalTacticsCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +3, +3, CreatureKeyword::Flying);
	return true;
}

bool CUnconventionalTacticsCard::BeforeReturn(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Graveyard)
	{
		CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others);
		pModifier.ApplyTo(this);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

CAbradeCard::CAbradeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Abrade"), CardType::Instant, nID)
{
	// Choose one -
	{
		// Abrade deals 3 damage to target creature.
		counted_ptr<CTargetChgLifeSpell> cpSpell(
			::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
				_T("1") RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE,
				Life(-3), PreventableType::Preventable));

		cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Destroy target artifact.
		counted_ptr<CTargetMoveCardSpell> cpSpell(
			::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
				_T("1") RED_MANA_TEXT,
				new CardTypeComparer(CardType::Artifact, false),
				ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

		cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		AddSpell(cpSpell.GetPointer());
	}
}

CActOfHeroismCard::CActOfHeroismCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Act of Heroism"), CardType::Instant, nID)
{
	// Untap target creature. It gets +2/+2 until end of turn and can block an additional creature this turn.
	// Partial: it can't block an additional creature
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CActOfHeroismCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CActOfHeroismCard::BeforeResolution(CAbilityAction* pAction)
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
	return true;
}

CAmbuscadeCard::CAmbuscadeCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Ambuscade"), CardType::Instant, nID)
{
	// Target creature you control gets +1/+0 until end of turn. It deals damage equal to its power to target creature
	// an opponent controls. (as Prepare // Fight in Amonkhet)
	counted_ptr<CDoubleTargetSpell> cpSpell(
		::CreateObject<CDoubleTargetSpell>(this, AbilityType::Instant,
			_T("2") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			new AnyCreatureComparer, FALSE, _T("")));

	cpSpell->GetTargeting1()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting1()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->GetTargeting2()->SetIncludeNonControllerCardsOnly();
	cpSpell->GetTargeting2()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAmbuscadeCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CAmbuscadeCard::BeforeResolution(CAbilityAction* pAction)
{
	CDoubleTargetSpellAction* pDoubleTargetAction = dynamic_cast<CDoubleTargetSpellAction*>(pAction);
	if (!pDoubleTargetAction)
		return false;

	CCreatureCard* pOwn = dynamic_cast<CCreatureCard*>((CCard*)pDoubleTargetAction->GetTargetGroup1().GetFirstCardSubject());
	CCard* pOther = (CCard*)pDoubleTargetAction->GetTargetGroup2().GetFirstCardSubject();
	if (!pOwn || pOwn->GetZoneId() != ZoneId::Battlefield)
		return false;

	PumpCreature(pOwn, +1, +0);
	DealDamageToCreature(pOwn, pOther, pOwn->GetPower());
	return false;
}

CBlurOfBladesCard::CBlurOfBladesCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Blur of Blades"), CardType::Instant, nID)
{
	// Put a -1/-1 counter on target creature. Blur of Blades deals 2 damage to that creature's controller.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBlurOfBladesCard::BeforeResolution));
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

bool CBlurOfBladesCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pCard->GetController();
	CCardCounterModifier pCounter = CCardCounterModifier(_T("-1/-1"), 1);
	pCounter.ApplyTo(pCard);

	CLifeModifier pModifier = CLifeModifier(Life(-2), this, PreventableType::Preventable,
		DamageType::SpellDamage | DamageType::NonCombatDamage);
	pModifier.ApplyTo(pController);
	return true;
}

CChandrasDefeatCard::CChandrasDefeatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Chandra's Defeat"), CardType::Instant, nID)
{
	// Chandra's Defeat deals 5 damage to target red creature or red planeswalker. If that permanent is a Chandra
	// planeswalker, you may discard a card. If you do, draw a card.
	// Partial: it can only target red creatures (the damage spells can't target planeswalkers)
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			RED_MANA_TEXT,
			new AnyCreatureComparer, FALSE,
			Life(-5), PreventableType::Preventable));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Red, false));
	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CCountervailingWindsCard::CCountervailingWindsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Countervailing Winds"), CardType::Instant, nID)
{
	// Counter target spell unless its controller pays {1} for each card in your graveyard.
	// (the cost is set when the spell resolves)
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT,
			new TrueCardComparer));

	cpSpell->SetCanBeDenied();
	cpSpell->GetDenialCost().SetManaCost(_T("0"));
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCountervailingWindsCard::BeforeResolution));
	m_pCounterSpell = cpSpell.GetPointer();
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CCountervailingWindsCard::BeforeResolution(CAbilityAction* pAction)
{
	int nCards = pAction->GetController()->GetZoneById(ZoneId::Graveyard)->GetSize();
	CString strCost;
	strCost.Format(_T("%d"), nCards);
	m_pCounterSpell->GetDenialCost().SetManaCost(strCost);
	return true;
}

CDjerusRenunciationCard::CDjerusRenunciationCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Djeru's Renunciation"), CardType::Instant, nID)
{
	// Tap up to two target creatures.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") WHITE_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetSubjectCount(1, 2);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(TRUE));
	AddSpell(cpSpell.GetPointer());

	// Cycling {W}
	AddCycling(this, WHITE_MANA_TEXT);
}

CGideonsDefeatCard::CGideonsDefeatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gideon's Defeat"), CardType::Instant, nID)
{
	// Exile target white creature that's attacking or blocking. If it was a Gideon planeswalker, you gain 5 life.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			WHITE_MANA_TEXT,
			new AttackingBlockingCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::White, false));
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGideonsDefeatCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

// A Gideon that became a creature (its animated creature has "Gideon" in its name)
bool CGideonsDefeatCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield &&
		(PlaneswalkerTypeComparer(PlaneswalkerType::Gideon)(pCard) || pCard->GetCardName().Find(_T("Gideon")) >= 0))
		GainLife(this, pAction->GetController(), 5);
	return true;
}

CGiftOfStrengthCard::CGiftOfStrengthCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Gift of Strength"), CardType::Instant, nID)
{
	// Target creature gets +3/+3 and gains reach until end of turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGiftOfStrengthCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CGiftOfStrengthCard::BeforeResolution(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +3, +3, CreatureKeyword::Reach);
	return true;
}

CHourOfGloryCard::CHourOfGloryCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Hour of Glory"), CardType::Instant, nID)
{
	// Exile target creature. If that creature was a God, its controller reveals their hand and exiles all cards from it
	// with the same name as that creature.
	counted_ptr<CTargetMoveCardSpell> cpSpell(
		::CreateObject<CTargetMoveCardSpell>(this, AbilityType::Instant,
			_T("3") BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Exile, TRUE, MoveType::Others));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHourOfGloryCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CHourOfGloryCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield ||
		!CreatureTypeComparer(CREATURE_TYPE(God), false)(pCard))
		return true;

	CZone* pHand = pCard->GetController()->GetZoneById(ZoneId::Hand);
	CCountedCardContainer cards;
	for (int i = 0; i < pHand->GetSize(); ++i)
		if (pHand->GetAt(i)->GetPrintedCardName() == pCard->GetPrintedCardName())
			cards.AddCard(pHand->GetAt(i), CardPlacement::Top);

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Hand, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	for (int i = 0; i < cards.GetSize(); ++i)
		pModifier.ApplyTo(cards.GetAt(i));
	return true;
}

CImaginaryThreatsCard::CImaginaryThreatsCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Imaginary Threats"), CardType::Instant, nID)
{
	// Creatures target opponent controls attack this turn if able. During that player's next untap step, creatures
	// they control don't untap.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpSpell->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CImaginaryThreatsCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CImaginaryThreatsCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pOpponent = pAction->GetAssociatedPlayer();
	if (!pOpponent)
		return true;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pOpponent, TRUE, creatures);

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::MustAttack);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		pModifier.ApplyTo((CCreatureCard*)creatures.GetAt(i));
		SkipNextUntap(GetGame(), creatures.GetAt(i));
	}
	return true;
}

CJacesDefeatCard::CJacesDefeatCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Jace's Defeat"), CardType::Instant, nID)
{
	// Counter target blue spell. If it was a Jace planeswalker spell, scry 2.
	counted_ptr<CCounterSpell> cpSpell(
		::CreateObject<CCounterSpell>(this, AbilityType::Instant,
			_T("1") BLUE_MANA_TEXT,
			new CardTypeComparer(CardType::Blue, false)));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CJacesDefeatCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

// (the target of a counterspell, as Hydroblast in Fifth Edition)
bool CJacesDefeatCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && PlaneswalkerTypeComparer(PlaneswalkerType::Jace)(pCard))
	{
		CScryModifier pModifier = CScryModifier(GetGame(), 2, this);
		pModifier.ApplyTo(pAction->GetController());
	}
	return true;
}

CLifeGoesOnCard::CLifeGoesOnCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Life Goes On"), CardType::Instant, nID)
	, m_nDeathTurn(-1)
{
	// You gain 4 life. If a creature died this turn, you gain 8 life instead.
	{
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Instant,
				GREEN_MANA_TEXT));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CLifeGoesOnCard::BeforeResolution));
		cpSpell->AddAbilityTag(AbilityTag::LifeGain);
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Remembers the turn a creature died (it never triggers; it works in any zone)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard, FALSE, TRUE, FALSE));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CLifeGoesOnCard::CountDeath));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CLifeGoesOnCard::CountDeath(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	m_nDeathTurn = GetGame()->GetGameTurnNumber();
	return false;
}

bool CLifeGoesOnCard::BeforeResolution(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), m_nDeathTurn == GetGame()->GetGameTurnNumber() ? 8 : 4);
	return true;
}

COpenFireCard::COpenFireCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Open Fire"), CardType::Instant, nID)
{
	// Open Fire deals 3 damage to any target.
	// Note: it can't target planeswalkers
	counted_ptr<CTargetChgLifeSpell> cpSpell(
		::CreateObject<CTargetChgLifeSpell>(this, AbilityType::Instant,
			_T("2") RED_MANA_TEXT,
			new AnyCreatureComparer, TRUE,
			Life(-3), PreventableType::Preventable));

	cpSpell->SetDamageType(DamageType::SpellDamage | DamageType::NonCombatDamage);
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->AddAbilityTag(AbilityTag::DamageSource);
	AddSpell(cpSpell.GetPointer());
}

CRefuseCooperateCard::CRefuseCooperateCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Refuse // Cooperate"), CardType::Instant, nID)
{
	{
		// Refuse: Refuse deals damage to target spell's controller equal to that spell's mana value.
		// (a counterspell that doesn't counter: the callback does everything and returns false)
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("3") RED_MANA_TEXT,
				new TrueCardComparer));

		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRefuseCooperateCard::BeforeRefuse));
		cpSpell->AddAbilityTag(AbilityTag::DamageSource);
		SetFirstHalf(cpSpell.GetPointer(), _T("Refuse"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Cooperate: Copy target instant or sorcery spell. You may choose new targets for the copy. (as Twincast)
		counted_ptr<CTargetCopyCastSpell> cpSpell(
			::CreateObject<CTargetCopyCastSpell>(this, AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT,
				new CardTypeComparer(CardType::Instant | CardType::Sorcery, false),
				ZoneId::Stack));

		CAftermathSupport::SetSecondHalf(cpSpell.GetPointer(), _T("Cooperate"));
		AddSpell(cpSpell.GetPointer());
	}
}

bool CRefuseCooperateCard::BeforeRefuse(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard)
		return false;

	int nDamage = (int)pCard->GetConvertedManaCost();
	if (nDamage > 0)
	{
		CLifeModifier pModifier = CLifeModifier(Life(-nDamage), this, PreventableType::Preventable,
			DamageType::SpellDamage | DamageType::NonCombatDamage);
		pModifier.ApplyTo(pCard->GetController());
	}
	return false;
}

CSupremeWillCard::CSupremeWillCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Supreme Will"), CardType::Instant, nID)
{
	// Choose one -
	{
		// Counter target spell unless its controller pays {3}.
		counted_ptr<CCounterSpell> cpSpell(
			::CreateObject<CCounterSpell>(this, AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT,
				new TrueCardComparer));

		cpSpell->SetCanBeDenied();
		cpSpell->GetDenialCost().SetManaCost(_T("3"));
		AddSpell(cpSpell.GetPointer());
	}
	{
		// Look at the top four cards of your library. Put one of them into your hand and the rest on the bottom of
		// your library in any order.
		counted_ptr<CGenericSpell> cpSpell(
			::CreateObject<CGenericSpell>(this, AbilityType::Instant,
				_T("2") BLUE_MANA_TEXT));

		cpSpell->SetAbilityText(_T("Look at the top four cards of your library. Put one of them into your hand. Casts"));
		cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSupremeWillCard::BeforeLook));
		AddSpell(cpSpell.GetPointer());
	}
}

// (as Mitotic Manipulation in Mirrodin Besieged)
bool CSupremeWillCard::BeforeLook(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	int nCount = pController->GetZoneById(ZoneId::Library)->GetSize();
	if (nCount > 4)
		nCount = 4;
	if (nCount <= 0)
		return true;

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, nCount, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // one of them
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // any cards
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

	pModifier.ApplyTo(pController);
	return true;
}

CTormentOfVenomCard::CTormentOfVenomCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Torment of Venom"), CardType::Instant, nID)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTormentOfVenomCard::OnChoiceSelected))
	, m_NonlandFilter(_T("a nonland permanent"), _T("nonland permanents"),
		new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)))
{
	// Put three -1/-1 counters on target creature. Its controller loses 3 life unless they sacrifice another nonland
	// permanent of their choice or discard a card.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("2") BLACK_MANA_TEXT BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTormentOfVenomCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTormentOfVenomCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	CPlayer* pController = pCard->GetController();
	CCardCounterModifier pCounter = CCardCounterModifier(_T("-1/-1"), 3);
	pCounter.ApplyTo(pCard);

	// "another nonland permanent" (as Scrap Trawler's filter in Aether Revolt)
	m_NonlandFilter.SetComparer(new NegateCardComparer(new CardTypeComparer(CardType::_Land, false)));
	m_NonlandFilter.AddComparer(new NegateCardComparer(new SpecificCardComparer(pCard)));

	std::vector<SelectionEntry> entries;
	if (m_NonlandFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_SACRIFICE;
		entry.strText = _T("Sacrifice another nonland permanent");
		entries.push_back(entry);
	}
	if (pController->GetZoneById(ZoneId::Hand)->GetSize() > 0)
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_DISCARD;
		entry.strText = _T("Discard a card");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = BOLAS_CHOICE_LOSE_LIFE;
		entry.strText = _T("Lose 3 life");
		entries.push_back(entry);
	}

	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CTormentOfVenomCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == BOLAS_CHOICE_SACRIFICE &&
				SacrificeOne(GetGame(), pSelectionPlayer, &m_NonlandFilter))
				return;

			if (it->dwContext == BOLAS_CHOICE_DISCARD &&
				pSelectionPlayer->GetZoneById(ZoneId::Hand)->GetSize() > 0)
			{
				DiscardCards(GetGame(), pSelectionPlayer, 1);
				return;
			}

			CLifeModifier pModifier = CLifeModifier(Life(-3), this, PreventableType::NotPreventable, DamageType::NotDealingDamage);
			pModifier.ApplyTo(pSelectionPlayer);
			return;
		}
}

#define LESSON_RETURN_LAND	1
#define LESSON_DISCARD		2

CTragicLessonCard::CTragicLessonCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Tragic Lesson"), CardType::Instant, nID)
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CTragicLessonCard::OnChoiceSelected))
{
	// Draw two cards. Then discard a card unless you return a land you control to its owner's hand.
	counted_ptr<CGenericSpell> cpSpell(
		::CreateObject<CGenericSpell>(this, AbilityType::Instant,
			_T("2") BLUE_MANA_TEXT));

	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTragicLessonCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());
}

bool CTragicLessonCard::BeforeResolution(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, 2);

	if (CCardFilter::GetFilter(_T("lands"))->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
	{
		DiscardCards(GetGame(), pController, 1);
		return true;
	}

	std::vector<SelectionEntry> entries;
	{
		SelectionEntry entry;
		entry.dwContext = LESSON_RETURN_LAND;
		entry.strText = _T("Return a land you control to its owner's hand");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = LESSON_DISCARD;
		entry.strText = _T("Discard a card");
		entries.push_back(entry);
	}
	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CTragicLessonCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == LESSON_RETURN_LAND)
			{
				CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Battlefield, SpecialNumber::All,
					CZoneModifier::RoleType::PrimaryPlayer,
					CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
				pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // a land you control
					CZoneModifier::RoleType::PrimaryPlayer, // select by
					CZoneModifier::RoleType::PrimaryPlayer, // reveal to
					CCardFilter::GetFilter(_T("lands")), // what cards
					ZoneId::Hand, // if selected, move cards to
					CZoneModifier::RoleType::PrimaryPlayer, // select by this player
					CardPlacement::Top, // put selected cards on
					MoveType::Others, // move type
					CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
				pModifier.ApplyTo(pSelectionPlayer);
			}
			else
				DiscardCards(GetGame(), pSelectionPlayer, 1);
			return;
		}
}

CWithoutWeaknessCard::CWithoutWeaknessCard(CGame* pGame, UINT nID)
	: CCard(pGame, _T("Without Weakness"), CardType::Instant, nID)
{
	// Target creature you control gains indestructible until end of turn.
	counted_ptr<CTargetSpell> cpSpell(
		::CreateObject<CTargetSpell>(this, AbilityType::Instant,
			_T("1") BLACK_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpSpell->GetTargeting()->SetIncludeControllerCardsOnly();
	cpSpell->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWithoutWeaknessCard::BeforeResolution));
	AddSpell(cpSpell.GetPointer());

	// Cycling {2}
	AddCycling(this, _T("2"));
}

bool CWithoutWeaknessCard::BeforeResolution(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		// (as Prepare // Fight's lifelink in Amonkhet)
		CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Indestructible, TRUE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (creatures)

#define WARRIOR_TOKEN_NAME	_T("Warrior (E)")
#define WARRIOR_TOKEN_ID	55094
#define HORSE_A_TOKEN_NAME	_T("Horse (A)")
#define HORSE_A_TOKEN_ID	55100

// "When this creature leaves the battlefield, <effect>" (as Amonkhet)
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

// "Whenever you exert a creature, <effect on target creature>" (listens to EXERT_TRIGGER_ID, as
// AddWheneverYouExertTrigger in Amonkhet). The callback does the effect and returns false. Returns the targeting.
template <class T>
static CTargeting* AddWheneverYouExertTargetTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CSpecialTrigger > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->GetTrigger().SetTriggerIndex(EXERT_TRIGGER_ID);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new TrueCardComparer());
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new CardControllerComparer(pCard));
	cpAbility->GetTrigger().SetTriggerinZone(ZoneId::Battlefield);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
	return &cpAbility->GetTargeting();
}

// "This creature has <keyword> as long as you control a Desert or there is a Desert card in your graveyard"
// (two conditional abilities: one counts the Deserts on the battlefield and the other the Desert cards in the
// graveyard, as Thresher Lizard in Amonkhet)
static void AddDesertKeyword(CCard* pCard, CardKeyword cardKeyword, CreatureKeyword creatureKeyword)
{
	ZoneId zones[] = { ZoneId::Battlefield, ZoneId::Graveyard };
	for (int z = 0; z < _countof(zones); ++z)
	{
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(pCard,
				new SpecificCardComparer(pCard),
				Power(+0), Life(+0), creatureKeyword));

		if (cardKeyword != CardKeyword::Null)
			cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(cardKeyword);
		cpAbility->SetAffectControllerCardsOnly();
		cpAbility->SetConditionWork();
		cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Desert, false));
		cpAbility->SetConditionCheckZone(zones[z]);
		cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
		cpAbility->SetConditionValue(1);
		pCard->AddAbility(cpAbility.GetPointer());
	}
}

//____________________________________________________________________________
//
// White creatures

CAdornedPouncerCard::CAdornedPouncerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Adorned Pouncer"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") WHITE_MANA_TEXT, Power(1), Life(1))
	, m_Embalm(this)
{
	// Double strike
	GetCreatureKeyword()->AddDoubleStrike(FALSE);

	// Eternalize {3}{W}{W}
	m_Embalm.AddEternalizeAbility(_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT);
}

CAngelOfCondemnationCard::CAngelOfCondemnationCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of Condemnation"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
{
	// Flying, vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	{
		// {2}{W}, {T}: Exile another target creature. Return that card to the battlefield under its owner's control at
		// the beginning of the next end step. (as Long Road Home in Eldritch Moon)
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngelOfCondemnationCard::BeforeFlicker));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{W}, {T}, Exert this creature: Exile another target creature until this creature leaves the battlefield.
		// Note: the creature is exerted when the ability resolves
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("2") WHITE_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetAbilityText(_T("Exert: exile another target creature until this creature leaves the battlefield."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAngelOfCondemnationCard::BeforeExile));
		AddAbility(cpAbility.GetPointer());
	}

	AddLeaveTrigger(this, &CAngelOfCondemnationCard::BeforeReturn);
}

bool CAngelOfCondemnationCard::BeforeFlicker(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Exile), pAction->GetController(), MoveType::Others);
	if (pCard->GetZoneId() != ZoneId::Exile || pCard->GetCardType().IsToken())	// an exiled token ceases to exist
		return true;

	// Returned at the beginning of the next end step (only if it's still in exile)
	CScheduledCardModifier pModifier = CScheduledCardModifier(GetGame(),
		new CMoveCardModifier(ZoneId::Exile, ZoneId::Battlefield, TRUE, MoveType::Others),
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
	return true;
}

bool CAngelOfCondemnationCard::BeforeExile(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);
	if (GetZoneId() == ZoneId::Battlefield)
		ExileUntilLeaves(m_Exiled, pAction->GetAssociatedCard(), pAction->GetController());
	return true;
}

bool CAngelOfCondemnationCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnExiled(m_Exiled, pAction->GetController());
	return true;
}

CAngelOfTheGodPharaohCard::CAngelOfTheGodPharaohCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Angel of the God-Pharaoh"), CardType::Creature, CREATURE_TYPE(Angel), nID,
		_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(4))
{
	// Cycling {2}
	AddCycling(this, _T("2"));
}

CAvenOfEnduringHopeCard::CAvenOfEnduringHopeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven of Enduring Hope"), CardType::Creature, CREATURE_TYPE2(Bird, Cleric), nID,
		_T("4") WHITE_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, you gain 3 life.
	AddEnterTrigger(this, &CAvenOfEnduringHopeCard::BeforeGainLife);
}

bool CAvenOfEnduringHopeCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 3);
	return true;
}

CCrestedSunmareCard::CCrestedSunmareCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Crested Sunmare"), CardType::Creature, CREATURE_TYPE(Horse), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(5), Life(5))
{
	{
		// Other Horses you control have indestructible.
		counted_ptr<CPwrTghAttrEnchantment> cpAbility(
			::CreateObject<CPwrTghAttrEnchantment>(this,
				new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Horse), false),
					new NegateCardComparer(new SpecificCardComparer(this))),
				Power(+0), Life(+0)));

		cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Indestructible);
		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each end step, if you gained life this turn, create a 5/5 white Horse creature token.
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CCrestedSunmareCard::SetTriggerContext));
		cpAbility->SetCreateTokenOption(TRUE, HORSE_A_TOKEN_NAME, HORSE_A_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CCrestedSunmareCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetController()->GetLifeGainThisTurn() > Life(0);
}

CDauntlessAvenCard::CDauntlessAvenCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Dauntless Aven"), CardType::Creature, CREATURE_TYPE2(Bird, Warrior), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(1))
{
	// Whenever this creature attacks, untap target creature you control.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDauntlessAvenCard::BeforeUntap));
	AddAbility(cpAbility.GetPointer());
}

bool CDauntlessAvenCard::BeforeUntap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(FALSE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CDisposalMummyCard::CDisposalMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Disposal Mummy"), CardType::Creature, CREATURE_TYPE2(Zombie, Jackal), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
{
	// When this creature enters, exile target card from an opponent's graveyard. (as Mortuary Mire in Battle for Zendikar)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Exile));
	AddAbility(cpAbility.GetPointer());
}

CDjeruWithEyesOpenCard::CDjeruWithEyesOpenCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Djeru, With Eyes Open"), CardType::_LegendaryCreature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("3") WHITE_MANA_TEXT WHITE_MANA_TEXT, Power(4), Life(3))
	, m_PlaneswalkerFilter(_T("a planeswalker card"), _T("planeswalker cards"), new CardTypeComparer(CardType::Planeswalker, false))
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// When Djeru enters, you may search your library for a planeswalker card, reveal it, put it into your hand, then
	// shuffle.
	AddEnterTrigger(this, &CDjeruWithEyesOpenCard::BeforeSearch, true);

	// If a source would deal damage to a planeswalker you control, prevent 1 of that damage.
	// Not implemented: there are no replacement effects on the damage dealt to planeswalkers
}

bool CDjeruWithEyesOpenCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a planeswalker card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::AllPlayers, // reveal to
		&m_PlaneswalkerFilter, // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CDutifulServantsCard::CDutifulServantsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dutiful Servants"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(5))
{
}

CGodPharaohsFaithfulCard::CGodPharaohsFaithfulCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("God-Pharaoh's Faithful"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		WHITE_MANA_TEXT, Power(0), Life(4))
{
	// Whenever you cast a blue, black, or red spell, you gain 1 life.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new CardTypeComparer(CardType::Blue | CardType::Black | CardType::Red, false));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGodPharaohsFaithfulCard::BeforeGainLife));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

bool CGodPharaohsFaithfulCard::BeforeGainLife(CAbilityAction* pAction)
{
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CMummyParamountCard::CMummyParamountCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Mummy Paramount"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever another Zombie you control enters, this creature gets +1/+1 until end of turn.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
		ZoneId::_AllZones, ZoneId::Battlefield));

	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMummyParamountCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CMummyParamountCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +1);
	return true;
}

COketrasAvengerCard::COketrasAvengerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oketra's Avenger"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") WHITE_MANA_TEXT, Power(3), Life(1))
	, m_Exert(this)
{
	// You may exert this creature as it attacks. When you do, prevent all combat damage that would be dealt to it
	// this turn.
	m_Exert.AddExertAbility(_T("prevent all combat damage that would be dealt to it this turn."),
		CAbility::ResolutionStartedCallback(this, &COketrasAvengerCard::BeforeExert));
}

bool COketrasAvengerCard::BeforeExert(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::PreventAllCombatDamage);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(this);
	return true;
}

CSolitaryCamelCard::CSolitaryCamelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Solitary Camel"), CardType::Creature, CREATURE_TYPE(Camel), nID,
		_T("2") WHITE_MANA_TEXT, Power(3), Life(2))
{
	// This creature has lifelink as long as you control a Desert or there is a Desert card in your graveyard.
	AddDesertKeyword(this, CardKeyword::Lifelink, CreatureKeyword::Null);
}

CSteadfastSentinelCard::CSteadfastSentinelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steadfast Sentinel"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("3") WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Embalm(this)
{
	// Vigilance
	GetCreatureKeyword()->AddVigilance(FALSE);

	// Eternalize {4}{W}{W}
	m_Embalm.AddEternalizeAbility(_T("4") WHITE_MANA_TEXT WHITE_MANA_TEXT);
}

CStewardOfSolidarityCard::CStewardOfSolidarityCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Steward of Solidarity"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") WHITE_MANA_TEXT, Power(2), Life(2))
{
	// {T}, Exert this creature: Create a 1/1 white Warrior creature token with vigilance.
	// Note: the creature is exerted when the ability resolves
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddTapCost();
	cpAbility->SetAbilityText(_T("Exert: create a 1/1 white Warrior creature token with vigilance."));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CStewardOfSolidarityCard::BeforeToken));
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

bool CStewardOfSolidarityCard::BeforeToken(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), WARRIOR_TOKEN_NAME, WARRIOR_TOKEN_ID, 1);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSunscourgeChampionCard::CSunscourgeChampionCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sunscourge Champion"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") WHITE_MANA_TEXT, Power(2), Life(3))
	, m_Embalm(this)
{
	// When this creature enters, you gain life equal to its power.
	AddEnterTrigger(this, &CSunscourgeChampionCard::BeforeGainLife);

	// Eternalize - {2}{W}{W}, Discard a card.
	CAbility* pAbility = m_Embalm.AddEternalizeAbility(_T("2") WHITE_MANA_TEXT WHITE_MANA_TEXT);
	pAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
}

bool CSunscourgeChampionCard::BeforeGainLife(CAbilityAction* pAction)
{
	int nPower = GetZoneId() == ZoneId::Battlefield ? (int)GetPower() : (int)GetPrintedPower();
	if (nPower > 0)
		GainLife(this, pAction->GetController(), nPower);
	return true;
}

CVizierOfTheTrueCard::CVizierOfTheTrueCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vizier of the True"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("3") WHITE_MANA_TEXT, Power(3), Life(2))
	, m_Exert(this)
{
	// You may exert this creature as it attacks.
	m_Exert.AddExertAbility(_T("no other effect."));

	// Whenever you exert a creature, tap target creature an opponent controls.
	CTargeting* pTargeting = AddWheneverYouExertTargetTrigger(this, &CVizierOfTheTrueCard::BeforeTap);
	pTargeting->SetIncludeNonControllerCardsOnly();
	pTargeting->SetDefaultCharacteristic(Characteristic::Negative);
}

bool CVizierOfTheTrueCard::BeforeTap(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (green creatures)

#define CAT_G_TOKEN_NAME	_T("Cat (G)")
#define CAT_G_TOKEN_ID		55098

// "When this creature dies, <effect>" (as Amonkhet)
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

// "When this creature enters, you may have <effect on target creature>" (the callback does everything and returns false)
template <class T>
static void AddEnterTargetCreatureTrigger(T* pCard, bool (T::*callback)(CAbilityAction*), bool bOptional, Characteristic characteristic)
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
}

// "<this> gets +N/+N (and the creature keyword) as long as you control a Desert" (bGraveyard: "as long as there is a
// Desert card in your graveyard")
static void AddDesertBonus(CCard* pCard, BOOL bGraveyard, int nPower, int nToughness, CreatureKeyword keyword)
{
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(pCard,
			new SpecificCardComparer(pCard),
			Power(nPower), Life(nToughness), keyword));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CardTypeComparer(CardType::Desert, false));
	cpAbility->SetConditionCheckZone(bGraveyard ? ZoneId::Graveyard : ZoneId::Battlefield);
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	pCard->AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Green creatures

CAvidReclaimerCard::CAvidReclaimerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Avid Reclaimer"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	// {T}: Add {G} or {U}. If you control a Nissa planeswalker, you gain 2 life.
	// Partial: no life is gained (the mana abilities have no effects on resolution)
	LPCTSTR colors[] = { GREEN_MANA_TEXT, BLUE_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
		AddTapManaAbility(this, colors[i]);
}

CBitterbowSharpshootersCard::CBitterbowSharpshootersCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Bitterbow Sharpshooters"), CardType::Creature, CREATURE_TYPE2(Jackal, Archer), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(4))
{
	// Reach, vigilance
	GetCreatureKeyword()->AddReach(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
}

CBrambleweftBehemothCard::CBrambleweftBehemothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Brambleweft Behemoth"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(6), Life(6))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);
}

CDevoteeOfStrengthCard::CDevoteeOfStrengthCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Devotee of Strength"), CardType::Creature, CREATURE_TYPE2(Snake, Wizard), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// {4}{G}: Target creature gets +2/+2 until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("4") GREEN_MANA_TEXT,
			new AnyCreatureComparer, FALSE));

	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDevoteeOfStrengthCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CDevoteeOfStrengthCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +2, +2);
	return true;
}

CDuneDivinerCard::CDuneDivinerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dune Diviner"), CardType::Creature, CREATURE_TYPE2(Snake, Cleric), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
	, m_DesertFilter(_T("an untapped Desert you control"), _T("untapped Deserts you control"),
		new CardTypeComparer(CardType::Desert, false))
{
	// {1}, Tap an untapped Desert you control: You gain 1 life. (the tap cost as Springleaf Drum in Lorwyn)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1")));

	cpAbility->GetCost().AddTapCardCost(1, &m_DesertFilter);
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+1), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->SetAbilityText(_T("You gain 1 life. Activates"));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CFeralProwlerCard::CFeralProwlerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Feral Prowler"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("1") GREEN_MANA_TEXT, Power(1), Life(3))
{
	// When this creature dies, draw a card.
	AddDiesTrigger(this, &CFeralProwlerCard::BeforeDraw, false);
}

bool CFeralProwlerCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CFrilledSandwallaCard::CFrilledSandwallaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frilled Sandwalla"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		GREEN_MANA_TEXT, Power(1), Life(1))
{
	// {1}{G}: This creature gets +2/+2 until end of turn. Activate only once each turn. (as Stromkirk Condemned in
	// Eldritch Moon)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") GREEN_MANA_TEXT));

	cpAbility->SetMaxTurnUsageCount(1);
	cpAbility->SetAbilityText(_T("This creature gets +2/+2 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFrilledSandwallaCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CFrilledSandwallaCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +2);
	return true;
}

CHarrierNagaCard::CHarrierNagaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Harrier Naga"), CardType::Creature, CREATURE_TYPE2(Snake, Warrior), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(3))
{
}

CHopeTenderCard::CHopeTenderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hope Tender"), CardType::Creature, CREATURE_TYPE2(Human, Druid), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// {1}, {T}: Untap target land.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				new CardTypeComparer(CardType::_Land, false), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}, {T}, Exert this creature: Untap two target lands.
		// Note: the creature is exerted when the ability resolves
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1"),
				new CardTypeComparer(CardType::_Land, false), FALSE));

		cpAbility->AddTapCost();
		cpAbility->GetTargeting()->SetSubjectCount(2, 2);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardOrientationModifier(FALSE));
		cpAbility->SetAbilityText(_T("Exert: untap two target lands."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CHopeTenderCard::BeforeExert));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CHopeTenderCard::BeforeExert(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);
	return true;
}

CMajesticMyriarchCard::CMajesticMyriarchCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Majestic Myriarch"), CardType::Creature, CREATURE_TYPE(Chimera), nID,
		_T("4") GREEN_MANA_TEXT, Power(0), Life(0))
{
	{
		// Majestic Myriarch's power and toughness are each equal to twice the number of creatures you control.
		// (as Crusader of Odric in M13)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new AnyCreatureComparer));

		cpAbility->SetPowerMultiplier(Power(2));
		cpAbility->SetToughnessMultiplier(Life(2));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of each combat, this creature gains flying until end of turn if you control a creature with
		// flying. The same is true for first strike, double strike, deathtouch, haste, hexproof, indestructible,
		// lifelink, menace, reach, trample, and vigilance.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::BeginningOfCombatStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMajesticMyriarchCard::BeforeKeywords));
		cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CMajesticMyriarchCard::BeforeKeywords(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	CCountedCardContainer creatures;
	GetCreatures(GetGame(), GetController(), TRUE, creatures);

	BOOL bFlying = FALSE, bFirstStrike = FALSE, bDoubleStrike = FALSE, bDeathtouch = FALSE, bHaste = FALSE;
	BOOL bHexproof = FALSE, bIndestructible = FALSE, bLifelink = FALSE, bMenace = FALSE, bReach = FALSE;
	BOOL bTrample = FALSE, bVigilance = FALSE;
	for (int i = 0; i < creatures.GetSize(); ++i)
	{
		CCreatureCard* pCreature = (CCreatureCard*)creatures.GetAt(i);
		if (pCreature == this)
			continue;

		bFlying |= pCreature->GetCreatureKeyword()->Flying();
		bFirstStrike |= pCreature->GetCreatureKeyword()->FirstStrike();
		bDoubleStrike |= pCreature->GetCreatureKeyword()->DoubleStrike();
		bDeathtouch |= pCreature->GetCardKeyword()->HasDeathtouch();
		bHaste |= pCreature->GetCreatureKeyword()->Haste();
		bHexproof |= pCreature->GetCardKeyword()->HasHexproof();
		bIndestructible |= pCreature->GetCardKeyword()->HasIndestructible();
		bLifelink |= pCreature->GetCardKeyword()->HasLifelink();
		bMenace |= pCreature->GetCreatureKeyword()->CantBeBlockedByOne(this);
		bReach |= pCreature->GetCreatureKeyword()->CanReach(this);
		bTrample |= pCreature->GetCreatureKeyword()->Trample();
		bVigilance |= pCreature->GetCreatureKeyword()->Vigilance();
	}

	if (bFlying) GetCreatureKeyword()->AddFlying(TRUE);
	if (bFirstStrike) GetCreatureKeyword()->AddFirstStrike(TRUE);
	if (bDoubleStrike) GetCreatureKeyword()->AddDoubleStrike(TRUE);
	if (bDeathtouch) GetCardKeyword()->AddDeathtouch(TRUE);
	if (bHaste) GetCreatureKeyword()->AddHaste(TRUE);
	if (bHexproof) GetCardKeyword()->AddHexproof(TRUE);
	if (bIndestructible) GetCardKeyword()->AddIndestructible(TRUE);
	if (bLifelink) GetCardKeyword()->AddLifelink(TRUE);
	if (bMenace) GetCreatureKeyword()->AddCantBeBlockedByOne(TRUE);
	if (bReach) GetCreatureKeyword()->AddReach(TRUE);
	if (bTrample) GetCreatureKeyword()->AddTrample(TRUE);
	if (bVigilance) GetCreatureKeyword()->AddVigilance(TRUE);
	return true;
}

COasisRitualistCard::COasisRitualistCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Oasis Ritualist"), CardType::Creature, CREATURE_TYPE2(Snake, Druid), nID,
		_T("3") GREEN_MANA_TEXT, Power(2), Life(4))
{
	// {T}: Add one mana of any color.
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
		AddTapManaAbility(this, colors[i]);

	// {T}, Exert this creature: Add two mana of any one color.
	// Not implemented: a mana ability can't exert the creature
}

CPrideSovereignCard::CPrideSovereignCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Pride Sovereign"), CardType::Creature, CREATURE_TYPE(Cat), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(2))
{
	{
		// This creature gets +1/+1 for each other Cat you control. (as Crusader of Odric in M13)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Battlefield,
				new AndCardComparer(new CreatureTypeComparer(CREATURE_TYPE(Cat), false),
					new NegateCardComparer(new SpecificCardComparer(this)))));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// {W}, {T}, Exert this creature: Create two 1/1 white Cat creature tokens with lifelink.
		// Note: the creature is exerted when the ability resolves
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				WHITE_MANA_TEXT));

		cpAbility->AddTapCost();
		cpAbility->SetAbilityText(_T("Exert: create two 1/1 white Cat creature tokens with lifelink."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CPrideSovereignCard::BeforeTokens));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CPrideSovereignCard::BeforeTokens(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);

	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), CAT_G_TOKEN_NAME, CAT_G_TOKEN_ID, 2);
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CQuarryBeetleCard::CQuarryBeetleCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Quarry Beetle"), CardType::Creature, CREATURE_TYPE(Insect), nID,
		_T("4") GREEN_MANA_TEXT, Power(4), Life(5))
{
	// When this creature enters, you may return target land card from your graveyard to the battlefield.
	// (as Mortuary Mire in Battle for Zendikar)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::_Land, false));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Battlefield);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Battlefield));
	AddAbility(cpAbility.GetPointer());
}

CRampagingHippoCard::CRampagingHippoCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rampaging Hippo"), CardType::Creature, CREATURE_TYPE(Hippo), nID,
		_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(5), Life(6))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CRamunapExcavatorCard::CRamunapExcavatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ramunap Excavator"), CardType::Creature, CREATURE_TYPE2(Snake, Cleric), nID,
		_T("2") GREEN_MANA_TEXT, Power(2), Life(3))
{
	// You may play lands from your graveyard. (as Crucible of Worlds in Tenth Edition)
	counted_ptr<CPlayerEffectEnchantment> cpAbility(
		::CreateObject<CPlayerEffectEnchantment>(this,
			PlayerEffectType::PlayCardsFromGraveyard,
			(int)CCardFilter::GetFilter(_T("lands"))));

	cpAbility->SetAffectControllerOnly();
	AddAbility(cpAbility.GetPointer());
}

CRamunapHydraCard::CRamunapHydraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ramunap Hydra"), CardType::Creature, CREATURE_TYPE2(Snake, Hydra), nID,
		_T("3") GREEN_MANA_TEXT, Power(3), Life(3))
{
	// Reach, vigilance, trample
	GetCreatureKeyword()->AddReach(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// This creature gets +1/+1 as long as you control a Desert.
	AddDesertBonus(this, FALSE, +1, +1, CreatureKeyword::Null);

	// This creature gets +1/+1 as long as there is a Desert card in your graveyard.
	AddDesertBonus(this, TRUE, +1, +1, CreatureKeyword::Null);
}

CResilientKhenraCard::CResilientKhenraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Resilient Khenra"), CardType::Creature, CREATURE_TYPE2(Jackal, Wizard), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Embalm(this)
{
	// When this creature enters, you may have target creature get +X/+X until end of turn, where X is this
	// creature's power.
	AddEnterTargetCreatureTrigger(this, &CResilientKhenraCard::BeforePump, true, Characteristic::Positive);

	// Eternalize {4}{G}{G}
	m_Embalm.AddEternalizeAbility(_T("4") GREEN_MANA_TEXT GREEN_MANA_TEXT);
}

bool CResilientKhenraCard::BeforePump(CAbilityAction* pAction)
{
	int nX = GetZoneId() == ZoneId::Battlefield ? (int)GetPower() : (int)GetPrintedPower();
	if (nX > 0)
		PumpCreature(pAction->GetAssociatedCard(), nX, nX);
	return false;
}

CRhonassStalwartCard::CRhonassStalwartCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Rhonas's Stalwart"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") GREEN_MANA_TEXT, Power(2), Life(2))
	, m_Exert(this)
	, m_CanBlockFilter(_T("a creature with power 3 or greater"), _T("creatures with power 3 or greater"),
		new CreaturePowerComparer<std::greater_equal<int>>(3))
{
	// You may exert this creature as it attacks. When you do, it gets +1/+1 until end of turn and can't be blocked by
	// creatures with power 2 or less this turn.
	m_Exert.AddExertAbility(_T("it gets +1/+1 and can't be blocked by creatures with power 2 or less this turn."),
		CAbility::ResolutionStartedCallback(this, &CRhonassStalwartCard::BeforeExert));
}

bool CRhonassStalwartCard::BeforeExert(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(this, +1, +1);
	// (as Elegant Edgecrafters in Kaladesh, this turn only)
	GetCreatureKeyword()->AddUnblockable(TRUE, &m_CanBlockFilter);
	return true;
}

CSidewinderNagaCard::CSidewinderNagaCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sidewinder Naga"), CardType::Creature, CREATURE_TYPE2(Snake, Warrior), nID,
		_T("2") GREEN_MANA_TEXT, Power(3), Life(2))
{
	// As long as you control a Desert or there is a Desert card in your graveyard, this creature gets +1/+0 and has
	// trample.
	// Note: with a Desert only in the graveyard, it has trample but doesn't get +1/+0 (the bonuses can't be combined)
	AddDesertBonus(this, FALSE, +1, +0, CreatureKeyword::Trample);
	AddDesertBonus(this, TRUE, +0, +0, CreatureKeyword::Trample);
}

CSifterWurmCard::CSifterWurmCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sifter Wurm"), CardType::Creature, CREATURE_TYPE(Wurm), nID,
		_T("5") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(7), Life(7))
{
	// Trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// When this creature enters, scry 3, then reveal the top card of your library. You gain life equal to that card's
	// mana value.
	AddEnterTrigger(this, &CSifterWurmCard::BeforeScry);
}

bool CSifterWurmCard::BeforeScry(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CScryModifier pScry = CScryModifier(GetGame(), 3, this);
	pScry.ApplyTo(pController);

	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	if (pLibrary->GetSize() > 0)
	{
		int nLife = (int)pLibrary->GetAt(pLibrary->GetSize() - 1)->GetConvertedManaCost();
		if (nLife > 0)
			GainLife(this, pController, nLife);
	}
	return true;
}

CTenaciousHunterCard::CTenaciousHunterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Tenacious Hunter"), CardType::Creature, CREATURE_TYPE(Crocodile), nID,
		_T("2") GREEN_MANA_TEXT GREEN_MANA_TEXT, Power(4), Life(4))
{
	// As long as a creature has a -1/-1 counter on it, this creature has vigilance and deathtouch.
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::Vigilance));

	cpAbility->GetCardKeywordMod().GetModifier().SetToAdd(CardKeyword::Deathtouch);
	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetConditionFilter().AddComparer(new CardCounterComparer<std::greater_equal<int>>(_T("-1/-1"), 1));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckAllPlayers);
	cpAbility->SetConditionValue(1);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (red creatures)

// Prowess (as Amonkhet)
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

// "Whenever you cast a noncreature spell, <effect>"
template <class T>
static void AddNoncreatureSpellTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// "Whenever this creature attacks, <effect>"
template <class T>
static void AddSelfAttackTrigger(T* pCard, bool (T::*callback)(CAbilityAction*))
{
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(pCard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(pCard, callback));
	pCard->AddAbility(cpAbility.GetPointer());
}

// The creature can't block this turn
static void CantBlockThisTurn(CCard* pCard)
{
	CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	CCreatureKeywordModifier pModifier;
	pModifier.GetModifier().SetToAdd(CreatureKeyword::CantBlock);
	pModifier.GetModifier().SetOneTurnOnly(TRUE);
	pModifier.ApplyTo(pCreature);
}

//____________________________________________________________________________
//
// Red creatures

CBurningFistMinotaurCard::CBurningFistMinotaurCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Burning-Fist Minotaur"), CardType::Creature, CREATURE_TYPE2(Minotaur, Wizard), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// First strike
	GetCreatureKeyword()->AddFirstStrike(FALSE);

	// {1}{R}, Discard a card: This creature gets +2/+0 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") RED_MANA_TEXT));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetAbilityText(_T("This creature gets +2/+0 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CBurningFistMinotaurCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CBurningFistMinotaurCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +0);
	return true;
}

CChaosMawCard::CChaosMawCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Chaos Maw"), CardType::Creature, CREATURE_TYPE(Hellion), nID,
		_T("5") RED_MANA_TEXT RED_MANA_TEXT, Power(6), Life(6))
{
	// When this creature enters, it deals 3 damage to each other creature.
	AddEnterTrigger(this, &CChaosMawCard::BeforeDamage);
}

bool CChaosMawCard::BeforeDamage(CAbilityAction* pAction)
{
	CCountedCardContainer creatures;
	GetCreatures(GetGame(), pAction->GetController(), TRUE, creatures);
	GetCreatures(GetGame(), pAction->GetController(), FALSE, creatures);
	for (int i = 0; i < creatures.GetSize(); ++i)
		if (creatures.GetAt(i) != this)
			DealDamageToCreature(this, creatures.GetAt(i), 3);
	return true;
}

CDefiantKhenraCard::CDefiantKhenraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Defiant Khenra"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(2))
{
}

CEarthshakerKhenraCard::CEarthshakerKhenraCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Earthshaker Khenra"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
	, m_Embalm(this)
{
	// Haste
	GetCreatureKeyword()->AddHaste(FALSE);

	// When this creature enters, target creature with power less than or equal to this creature's power can't block
	// this turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new PowerAtMostComparer(this));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEarthshakerKhenraCard::BeforeCantBlock));
	AddAbility(cpAbility.GetPointer());

	// Eternalize {4}{R}{R}
	m_Embalm.AddEternalizeAbility(_T("4") RED_MANA_TEXT RED_MANA_TEXT);
}

bool CEarthshakerKhenraCard::BeforeCantBlock(CAbilityAction* pAction)
{
	CantBlockThisTurn(pAction->GetAssociatedCard());
	return false;
}

CFerventPaincasterCard::CFerventPaincasterCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Fervent Paincaster"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") RED_MANA_TEXT, Power(3), Life(1))
{
	{
		// {T}: This creature deals 1 damage to target player or planeswalker.
		// Note: it can't target planeswalkers
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				FALSE_CARD_COMPARER, TRUE,
				Life(-1), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {T}, Exert this creature: It deals 1 damage to target creature.
		// Note: the creature is exerted when the ability resolves
		counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
				_T(""),
				new AnyCreatureComparer, FALSE,
				Life(-1), PreventableType::Preventable));

		cpAbility->AddTapCost();
		cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->SetAbilityText(_T("Exert: it deals 1 damage to target creature."));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFerventPaincasterCard::BeforeExert));
		cpAbility->AddAbilityTag(AbilityTag::DamageSource);
		AddAbility(cpAbility.GetPointer());
	}
}

bool CFerventPaincasterCard::BeforeExert(CAbilityAction* pAction)
{
	CExertSupport::Exert(this);
	return true;
}

CFirebrandArcherCard::CFirebrandArcherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Firebrand Archer"), CardType::Creature, CREATURE_TYPE2(Human, Archer), nID,
		_T("1") RED_MANA_TEXT, Power(2), Life(1))
{
	// Whenever you cast a noncreature spell, this creature deals 1 damage to each opponent.
	AddNoncreatureSpellTrigger(this, &CFirebrandArcherCard::BeforeDamage);
}

bool CFirebrandArcherCard::BeforeDamage(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	return true;
}

CFrontlineDevastatorCard::CFrontlineDevastatorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Frontline Devastator"), CardType::Creature, CREATURE_TYPE3(Zombie, Minotaur, Warrior), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
	, m_Afflict(this)
{
	// Afflict 2
	m_Afflict.AddAfflictAbility(2);

	// {1}{R}: This creature gets +1/+0 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("1") RED_MANA_TEXT));

	cpAbility->SetAbilityText(_T("This creature gets +1/+0 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CFrontlineDevastatorCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CFrontlineDevastatorCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, +0);
	return true;
}

CGildedCerodonCard::CGildedCerodonCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Gilded Cerodon"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("4") RED_MANA_TEXT, Power(4), Life(4))
{
	// Whenever this creature attacks, if you control a Desert or there is a Desert card in your graveyard, target
	// creature can't block this turn. (the condition is checked on resolution)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGildedCerodonCard::BeforeCantBlock));
	AddAbility(cpAbility.GetPointer());
}

bool CGildedCerodonCard::BeforeCantBlock(CAbilityAction* pAction)
{
	if (HasDesert(pAction->GetController()))
		CantBlockThisTurn(pAction->GetAssociatedCard());
	return false;
}

CGraniticTitanCard::CGraniticTitanCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Granitic Titan"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("4") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(4))
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CKhenraScrapperCard::CKhenraScrapperCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Khenra Scrapper"), CardType::Creature, CREATURE_TYPE2(Jackal, Warrior), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(3))
	, m_Exert(this)
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// You may exert this creature as it attacks. When you do, it gets +2/+0 until end of turn.
	m_Exert.AddExertAbility(_T("it gets +2/+0 until end of turn."),
		CAbility::ResolutionStartedCallback(this, &CKhenraScrapperCard::BeforeExert));
}

bool CKhenraScrapperCard::BeforeExert(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +0);
	return true;
}

CMagmarothCard::CMagmarothCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Magmaroth"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("3") RED_MANA_TEXT, Power(5), Life(5))
{
	{
		// At the beginning of your upkeep, put a -1/-1 counter on this creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMagmarothCard::BeforeAddCounter));
		AddAbility(cpAbility.GetPointer());
	}

	// Whenever you cast a noncreature spell, remove a -1/-1 counter from this creature.
	AddNoncreatureSpellTrigger(this, &CMagmarothCard::BeforeRemoveCounter);
}

bool CMagmarothCard::BeforeAddCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), +1);
		pModifier.ApplyTo(this);
	}
	return true;
}

bool CMagmarothCard::BeforeRemoveCounter(CAbilityAction* pAction)
{
	const Counter* pCounter = ((const CCard*)this)->GetCounterContainer()->GetCounter(_T("-1/-1"));
	if (GetZoneId() == ZoneId::Battlefield && pCounter && pCounter->GetCount() > 0)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), -1);
		pModifier.ApplyTo(this);
	}
	return true;
}

CManticoreEternalCard::CManticoreEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Manticore Eternal"), CardType::Creature, CREATURE_TYPE2(Zombie, Manticore), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(5), Life(4))
	, m_Afflict(this)
{
	// Afflict 3
	m_Afflict.AddAfflictAbility(3);

	// This creature attacks each combat if able. (as Aether Revolt)
	GetCreatureKeyword()->AddMustAttackEachCombat(FALSE);
}

CNehebTheEternalCard::CNehebTheEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Neheb, the Eternal"), CardType::_LegendaryCreature, CREATURE_TYPE3(Zombie, Minotaur, Warrior), nID,
		_T("3") RED_MANA_TEXT RED_MANA_TEXT, Power(4), Life(6))
	, m_Afflict(this)
{
	// Afflict 3
	m_Afflict.AddAfflictAbility(3);

	// At the beginning of each of your postcombat main phases, add {R} for each 1 life your opponents have lost this
	// turn. (as Bounty of the Luxa in Amonkhet)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::MainPhaseStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CNehebTheEternalCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CNehebTheEternalCard::BeforeMana));
	AddAbility(cpAbility.GetPointer());
}

bool CNehebTheEternalCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return GetGame()->IsFirstMainPhase() == FALSE;
}

bool CNehebTheEternalCard::BeforeMana(CAbilityAction* pAction)
{
	int nLost = 0;
	for (int ip = 0; ip < GetGame()->GetPlayerCount(); ++ip)
	{
		CPlayer* pPlayer = GetGame()->GetPlayer(ip);
		if (pPlayer == pAction->GetController())
			continue;

		int nPlayerLost = (int)pPlayer->GetLifeLossTakenThisTurn();
		nLost += nPlayerLost < 0 ? -nPlayerLost : nPlayerLost;
	}
	if (nLost <= 0)
		return true;

	CString strMana;
	for (int i = 0; i < nLost; ++i)
		strMana += RED_MANA_TEXT;

	CManaPoolModifier pModifier = CManaPoolModifier(CManaPoolModifier::Operation::Add, CManaPool::CManaPool(strMana));
	pModifier.ApplyTo(pAction->GetController());
	return true;
}

CSandStranglerCard::CSandStranglerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sand Strangler"), CardType::Creature, CREATURE_TYPE(Beast), nID,
		_T("3") RED_MANA_TEXT, Power(3), Life(3))
{
	// When this creature enters, if you control a Desert or there is a Desert card in your graveyard, you may have
	// this creature deal 3 damage to target creature. (the condition is checked on resolution)
	AddEnterTargetCreatureTrigger(this, &CSandStranglerCard::BeforeDamage, true, Characteristic::Negative);
}

bool CSandStranglerCard::BeforeDamage(CAbilityAction* pAction)
{
	if (HasDesert(pAction->GetController()))
		DealDamageToCreature(this, pAction->GetAssociatedCard(), 3);
	return false;
}

CThornedMolochCard::CThornedMolochCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Thorned Moloch"), CardType::Creature, CREATURE_TYPE(Lizard), nID,
		_T("2") RED_MANA_TEXT, Power(2), Life(2))
{
	// Prowess
	AddProwess(this);

	// This creature has first strike as long as it's attacking.
	// Note: it gains first strike until end of turn when it attacks
	AddSelfAttackTrigger(this, &CThornedMolochCard::BeforeFirstStrike);
}

bool CThornedMolochCard::BeforeFirstStrike(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
		GetCreatureKeyword()->AddFirstStrike(TRUE);
	return true;
}

CWildfireEternalCard::CWildfireEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wildfire Eternal"), CardType::Creature, CREATURE_TYPE3(Zombie, Jackal, Cleric), nID,
		_T("3") RED_MANA_TEXT, Power(1), Life(4))
	, m_Afflict(this)
{
	// Afflict 4
	m_Afflict.AddAfflictAbility(4);

	// Whenever this creature attacks and isn't blocked, you may cast an instant or sorcery spell from your hand
	// without paying its mana cost.
	// Not implemented: a spell can't be cast without paying its mana cost
}

CZealotOfTheGodPharaohCard::CZealotOfTheGodPharaohCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Zealot of the God-Pharaoh"), CardType::Creature, CREATURE_TYPE2(Minotaur, Archer), nID,
		_T("3") RED_MANA_TEXT, Power(4), Life(3))
{
	// {4}{R}: This creature deals 2 damage to target opponent or planeswalker.
	// Note: it can't target planeswalkers
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T("4") RED_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE,
			Life(-2), PreventableType::Preventable));

	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetIncludeOpponentPlayersOnly();
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

CAccursedHordeCard::CAccursedHordeCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Accursed Horde"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// {1}{B}: Target attacking Zombie gains indestructible until end of turn.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			_T("1") BLACK_MANA_TEXT,
			new AttackingCreatureComparer, FALSE));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAccursedHordeCard::BeforeIndestructible));
	AddAbility(cpAbility.GetPointer());
}

bool CAccursedHordeCard::BeforeIndestructible(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Indestructible, TRUE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

CAmmitEternalCard::CAmmitEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ammit Eternal"), CardType::Creature, CREATURE_TYPE3(Zombie, Crocodile, Demon), nID,
		_T("2") BLACK_MANA_TEXT, Power(5), Life(5))
	, m_Afflict(this)
{
	// Afflict 3
	m_Afflict.AddAfflictAbility(3);

	{
		// Whenever an opponent casts a spell, put a -1/-1 counter on this creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetMonitorOpponentsOnly(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAmmitEternalCard::BeforeAddCounter));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever this creature deals combat damage to a player, remove all -1/-1 counters from it.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
							   CWhenSelfDamageDealt::PlayerEventCallback,
							   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetTrigger().SetCombatDamageOnly();
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAmmitEternalCard::BeforeRemoveCounters));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CAmmitEternalCard::BeforeAddCounter(CAbilityAction* pAction)
{
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), +1);
		pModifier.ApplyTo(this);
	}
	return true;
}

bool CAmmitEternalCard::BeforeRemoveCounters(CAbilityAction* pAction)
{
	const Counter* pCounter = ((const CCard*)this)->GetCounterContainer()->GetCounter(_T("-1/-1"));
	if (GetZoneId() == ZoneId::Battlefield && pCounter && pCounter->GetCount() > 0)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), -pCounter->GetCount());
		pModifier.ApplyTo(this);
	}
	return true;
}

#define DEMON_SACRIFICE	1
#define DEMON_TAP		2

CApocalypseDemonCard::CApocalypseDemonCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Apocalypse Demon"), CardType::Creature, CREATURE_TYPE(Demon), nID,
		_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(0), Life(0))
	, m_ChoiceSelection(pGame, CSelectionSupport::SelectionCallback(this, &CApocalypseDemonCard::OnChoiceSelected))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	{
		// Apocalypse Demon's power and toughness are each equal to the number of cards in your graveyard.
		// (as Crusader of Odric in M13)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Graveyard,
				new TrueCardComparer));

		AddAbility(cpAbility.GetPointer());
	}
	{
		// At the beginning of your upkeep, tap this creature unless you sacrifice another creature.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CApocalypseDemonCard::BeforeChoice));
		AddAbility(cpAbility.GetPointer());
	}
}

bool CApocalypseDemonCard::BeforeChoice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	std::vector<SelectionEntry> entries;
	if (m_OtherCreatureFilter.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) > 0)
	{
		SelectionEntry entry;
		entry.dwContext = DEMON_SACRIFICE;
		entry.strText = _T("Sacrifice another creature");
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = DEMON_TAP;
		entry.strText = _T("Tap Apocalypse Demon");
		entries.push_back(entry);
	}
	m_ChoiceSelection.AddSelectionRequest(entries, 1, 1, this, pController);
	return true;
}

void CApocalypseDemonCard::OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			if (it->dwContext == DEMON_SACRIFICE && SacrificeOne(GetGame(), pSelectionPlayer, &m_OtherCreatureFilter))
				return;

			if (GetZoneId() == ZoneId::Battlefield)
			{
				CCardOrientationModifier pModifier = CCardOrientationModifier(TRUE);
				pModifier.ApplyTo(this);
			}
			return;
		}
}

CBanewhipPunisherCard::CBanewhipPunisherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Banewhip Punisher"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
{
	// When this creature enters, you may put a -1/-1 counter on target creature.
	AddEnterTargetCreatureTrigger(this, &CBanewhipPunisherCard::BeforeCounter, true, Characteristic::Negative);

	// {B}, Sacrifice this creature: Destroy target creature that has a -1/-1 counter on it.
	counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
			BLACK_MANA_TEXT,
			new AnyCreatureComparer,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Destroy));

	cpAbility->AddSacrificeCost();
	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(
		new CardCounterComparer<std::greater_equal<int>>(_T("-1/-1"), 1));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	AddAbility(cpAbility.GetPointer());
}

bool CBanewhipPunisherCard::BeforeCounter(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
		pModifier.ApplyTo(pCard);
	}
	return false;
}

CCarrionScreecherCard::CCarrionScreecherCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Carrion Screecher"), CardType::Creature, CREATURE_TYPE2(Zombie, Bird), nID,
		_T("3") BLACK_MANA_TEXT, Power(3), Life(1))
{
}

CDreamstealerCard::CDreamstealerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Dreamstealer"), CardType::Creature, CREATURE_TYPE2(Human, Wizard), nID,
		_T("2") BLACK_MANA_TEXT, Power(1), Life(2))
	, m_Embalm(this)
{
	// Menace
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);

	// Whenever this creature deals combat damage to a player, that player discards that many cards.
	// (as Empyreal Voyager in Kaladesh)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CDreamstealerCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CDreamstealerCard::BeforeDiscard));
	AddAbility(cpAbility.GetPointer());

	// Eternalize {4}{B}{B}
	m_Embalm.AddEternalizeAbility(_T("4") BLACK_MANA_TEXT BLACK_MANA_TEXT);
}

// nValue1: the damage; nValue2: the damaged player
bool CDreamstealerCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const
{
	int nDamage = -GET_INTEGER(damage.m_nLifeDelta);
	if (nDamage <= 0 || !pPlayer)
		return false;

	triggerContext.nValue1 = (DWORD)nDamage;
	triggerContext.nValue2 = (DWORD)pPlayer;
	return true;
}

bool CDreamstealerCard::BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction)
{
	int nCount = (int)pAction->GetTriggerContext().nValue1;
	CPlayer* pPlayer = (CPlayer*)pAction->GetTriggerContext().nValue2;
	int nHand = pPlayer ? pPlayer->GetZoneById(ZoneId::Hand)->GetSize() : 0;
	if (nCount > nHand)
		nCount = nHand;
	if (nCount > 0)
		DiscardCards(GetGame(), pPlayer, nCount);
	return true;
}

CGrislySurvivorCard::CGrislySurvivorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Grisly Survivor"), CardType::Creature, CREATURE_TYPE2(Minotaur, Warrior), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(3))
{
	// Whenever you cycle or discard a card, this creature gets +2/+0 until end of turn. (cycling discards the card,
	// as AddCycleOrDiscardTrigger in Amonkhet)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CGrislySurvivorCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CGrislySurvivorCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +0);
	return true;
}

CKhenraEternalCard::CKhenraEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Khenra Eternal"), CardType::Creature, CREATURE_TYPE3(Zombie, Jackal, Warrior), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_Afflict(this)
{
	// Afflict 1
	m_Afflict.AddAfflictAbility(1);
}

CLurchingRotbeastCard::CLurchingRotbeastCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Lurching Rotbeast"), CardType::Creature, CREATURE_TYPE2(Zombie, Beast), nID,
		_T("3") BLACK_MANA_TEXT, Power(4), Life(2))
{
	// Cycling {B}
	AddCycling(this, BLACK_MANA_TEXT);
}

CMaraudingBoneslasherCard::CMaraudingBoneslasherCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Marauding Boneslasher"), CardType::Creature, CREATURE_TYPE2(Zombie, Minotaur), nID,
		_T("2") BLACK_MANA_TEXT, Power(3), Life(3))
{
	// This creature can't block unless you control another Zombie. (it can't block as long as you control one Zombie
	// or fewer, as Thresher Lizard in Amonkhet)
	counted_ptr<CPwrTghAttrEnchantment> cpAbility(
		::CreateObject<CPwrTghAttrEnchantment>(this,
			new SpecificCardComparer(this),
			Power(+0), Life(+0), CreatureKeyword::CantBlock));

	cpAbility->SetAffectControllerCardsOnly();
	cpAbility->SetConditionWork();
	cpAbility->GetConditionFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	cpAbility->SetConditionCheckPlayer(CEnchantment::ConditionCheckPlayerType::CheckControllerOnly);
	cpAbility->SetConditionValue(1);
	cpAbility->SetConditionIsMaximum();
	AddAbility(cpAbility.GetPointer());
}

CMercilessEternalCard::CMercilessEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Merciless Eternal"), CardType::Creature, CREATURE_TYPE2(Zombie, Cleric), nID,
		_T("2") BLACK_MANA_TEXT, Power(2), Life(2))
	, m_Afflict(this)
{
	// Afflict 2
	m_Afflict.AddAfflictAbility(2);

	// {2}{B}, Discard a card: This creature gets +2/+2 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("2") BLACK_MANA_TEXT));

	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->SetAbilityText(_T("This creature gets +2/+2 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CMercilessEternalCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CMercilessEternalCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +2, +2);
	return true;
}

CMoaningWallCard::CMoaningWallCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Moaning Wall"), CardType::Creature, CREATURE_TYPE2(Zombie, Wall), nID,
		_T("2") BLACK_MANA_TEXT, Power(0), Life(5))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CRazakethTheFoulbloodedCard::CRazakethTheFoulbloodedCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Razaketh, the Foulblooded"), CardType::_LegendaryCreature, CREATURE_TYPE(Demon), nID,
		_T("5") BLACK_MANA_TEXT BLACK_MANA_TEXT BLACK_MANA_TEXT, Power(8), Life(8))
	, m_OtherCreatureFilter(_T("another creature"), _T("other creatures"),
		new AndCardComparer(new AnyCreatureComparer, new NegateCardComparer(new SpecificCardComparer(this))))
{
	// Flying, trample
	GetCreatureKeyword()->AddTrample(FALSE);

	// Pay 2 life, Sacrifice another creature: Search your library for a card, put that card into your hand, then
	// shuffle.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("")));

	cpAbility->AddPayLifeDeltaCost(Life(-2));
	cpAbility->GetCost().AddSacrificeCardCost(1, &m_OtherCreatureFilter);
	cpAbility->SetAbilityText(_T("Search your library for a card and put it into your hand. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CRazakethTheFoulbloodedCard::BeforeSearch));
	AddAbility(cpAbility.GetPointer());
}

bool CRazakethTheFoulbloodedCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a card
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		CCardFilter::GetFilter(_T("cards")), // what cards
		ZoneId::Hand, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

CRuinRatCard::CRuinRatCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Ruin Rat"), CardType::Creature, CREATURE_TYPE(Rat), nID,
		_T("1") BLACK_MANA_TEXT, Power(1), Life(1))
{
	// Deathtouch
	GetCardKeyword()->AddDeathtouch(FALSE);

	// When this creature dies, exile target card from an opponent's graveyard. (as Disposal Mummy)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Exile));
	AddAbility(cpAbility.GetPointer());
}

CScroungerOfSoulsCard::CScroungerOfSoulsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Scrounger of Souls"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		_T("4") BLACK_MANA_TEXT, Power(3), Life(4))
{
	// Lifelink
	GetCardKeyword()->AddLifelink(FALSE);
}

CVileManifestationCard::CVileManifestationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vile Manifestation"), CardType::Creature, CREATURE_TYPE(Horror), nID,
		_T("1") BLACK_MANA_TEXT, Power(0), Life(4))
{
	{
		// This creature gets +1/+0 for each card with cycling in your graveyard. (as Crusader of Odric in M13)
		counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
			::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
				ZoneId::Graveyard,
				new HasCyclingComparer));

		cpAbility->SetChangePowerOnly();
		AddAbility(cpAbility.GetPointer());
	}

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CWaspOfTheBitterEndCard::CWaspOfTheBitterEndCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Wasp of the Bitter End"), CardType::Creature, CREATURE_TYPE2(Insect, Horror), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// Whenever you cast a Bolas planeswalker spell, you may sacrifice this creature. If you do, destroy target creature.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new PlaneswalkerTypeComparer(PlaneswalkerType::Bolas));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWaspOfTheBitterEndCard::BeforeDestroy));
	AddAbility(cpAbility.GetPointer());
}

bool CWaspOfTheBitterEndCard::BeforeDestroy(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return false;

	CMoveCardModifier pSacrifice = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pAction->GetController());
	pSacrifice.ApplyTo(this);
	if (GetZoneId() == ZoneId::Battlefield)
		return false;

	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard)
		DestroyPermanent(pCard, pAction->GetController());
	return false;
}

CWretchedCamelCard::CWretchedCamelCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wretched Camel"), CardType::Creature, CREATURE_TYPE2(Zombie, Camel), nID,
		_T("1") BLACK_MANA_TEXT, Power(2), Life(1))
{
	// When this creature dies, if you control a Desert or there is a Desert card in your graveyard, target player
	// discards a card. (the condition is checked on resolution)
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetLeaveEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetToThisZoneOnly(ZoneId::Graveyard);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new FalseCardComparer);
	cpAbility->GetTargeting().SetIncludePlayers(TRUE);
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CWretchedCamelCard::BeforeDiscard));
	AddAbility(cpAbility.GetPointer());
}

bool CWretchedCamelCard::BeforeDiscard(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer && HasDesert(pAction->GetController()) && pPlayer->GetZoneById(ZoneId::Hand)->GetSize() > 0)
		DiscardCards(GetGame(), pPlayer, 1);
	return false;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

CAerialGuideCard::CAerialGuideCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aerial Guide"), CardType::Creature, CREATURE_TYPE(Drake), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
{
	// Whenever this creature attacks, another target attacking creature gains flying until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AttackingCreatureComparer);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CAerialGuideCard::BeforeFlying));
	AddAbility(cpAbility.GetPointer());
}

bool CAerialGuideCard::BeforeFlying(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), +0, +0, CreatureKeyword::Flying);
	return false;
}

CAvenReedstalkerCard::CAvenReedstalkerCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Aven Reedstalker"), CardType::Creature, CREATURE_TYPE2(Bird, Warrior), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(3))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);
}

CChampionOfWitsCard::CChampionOfWitsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Champion of Wits"), CardType::Creature, CREATURE_TYPE2(Snake, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(1))
	, m_Embalm(this)
{
	// When this creature enters, you may draw cards equal to its power. If you do, discard two cards.
	AddEnterTrigger(this, &CChampionOfWitsCard::BeforeDraw, true);

	// Eternalize {5}{U}{U}
	m_Embalm.AddEternalizeAbility(_T("5") BLUE_MANA_TEXT BLUE_MANA_TEXT);
}

bool CChampionOfWitsCard::BeforeDraw(CAbilityAction* pAction)
{
	int nPower = GetZoneId() == ZoneId::Battlefield ? (int)GetPower() : (int)GetPrintedPower();
	if (nPower <= 0)
		return true;

	CPlayer* pController = pAction->GetController();
	DrawCards(GetGame(), pController, nPower);

	int nDiscard = pController->GetZoneById(ZoneId::Hand)->GetSize();
	if (nDiscard > 2)
		nDiscard = 2;
	if (nDiscard > 0)
		DiscardCards(GetGame(), pController, nDiscard);
	return true;
}

CCunningSurvivorCard::CCunningSurvivorCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Cunning Survivor"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") BLUE_MANA_TEXT, Power(1), Life(3))
{
	// Whenever you cycle or discard a card, this creature gets +1/+0 until end of turn and can't be blocked this turn.
	// (as Grisly Survivor)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCunningSurvivorCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

bool CCunningSurvivorCard::BeforePump(CAbilityAction* pAction)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return true;

	PumpCreature(this, +1, +0);
	GetCreatureKeyword()->AddUnblockable(TRUE);
	return true;
}

CEternalOfHarshTruthsCard::CEternalOfHarshTruthsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Eternal of Harsh Truths"), CardType::Creature, CREATURE_TYPE2(Zombie, Cleric), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(3))
	, m_Afflict(this)
{
	// Afflict 2
	m_Afflict.AddAfflictAbility(2);

	// Whenever this creature attacks and isn't blocked, draw a card.
	// (a trigger after the blockers are declared, if this creature is attacking and isn't blocked)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::DeclareBlockersStep2));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CEternalOfHarshTruthsCard::SetTriggerContext));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEternalOfHarshTruthsCard::BeforeDraw));
	AddAbility(cpAbility.GetPointer());
}

bool CEternalOfHarshTruthsCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const
{
	return IsAttacking() && !IsBlocked();
}

bool CEternalOfHarshTruthsCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

CNimbleObstructionistCard::CNimbleObstructionistCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Nimble Obstructionist"), CardType::Creature, CREATURE_TYPE2(Bird, Wizard), nID,
		_T("2") BLUE_MANA_TEXT, Power(3), Life(1))
{
	// Flash
	GetCardKeyword()->AddFlash(FALSE);

	// Cycling {2}{U}
	AddCycling(this, _T("2") BLUE_MANA_TEXT);

	// When you cycle this card, counter target activated or triggered ability you don't control.
	// Not implemented: the abilities can't be countered
}

COminousSphinxCard::COminousSphinxCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Ominous Sphinx"), CardType::Creature, CREATURE_TYPE(Sphinx), nID,
		_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
{
	// Whenever you cycle or discard a card, target creature an opponent controls gets -2/-0 until end of turn.
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCardDiscarded > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &COminousSphinxCard::BeforeShrink));
	AddAbility(cpAbility.GetPointer());
}

bool COminousSphinxCard::BeforeShrink(CAbilityAction* pAction)
{
	PumpCreature(pAction->GetAssociatedCard(), -2, +0);
	return false;
}

CProvenCombatantCard::CProvenCombatantCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Proven Combatant"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		BLUE_MANA_TEXT, Power(1), Life(1))
	, m_Embalm(this)
{
	// Eternalize {4}{U}{U}
	m_Embalm.AddEternalizeAbility(_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT);
}

CSeerOfTheLastTomorrowCard::CSeerOfTheLastTomorrowCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Seer of the Last Tomorrow"), CardType::Creature, CREATURE_TYPE2(Snake, Cleric), nID,
		_T("2") BLUE_MANA_TEXT, Power(1), Life(4))
{
	// {U}, {T}, Discard a card: Target player mills three cards.
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(this,
			BLUE_MANA_TEXT,
			FALSE_CARD_COMPARER, TRUE));

	cpAbility->AddTapCost();
	cpAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSeerOfTheLastTomorrowCard::BeforeMill));
	AddAbility(cpAbility.GetPointer());
}

bool CSeerOfTheLastTomorrowCard::BeforeMill(CAbilityAction* pAction)
{
	CPlayer* pPlayer = pAction->GetAssociatedPlayer();
	if (pPlayer)
		Mill(pPlayer, 3);
	return true;
}

CSinuousStrikerCard::CSinuousStrikerCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Sinuous Striker"), CardType::Creature, CREATURE_TYPE2(Snake, Warrior), nID,
		_T("2") BLUE_MANA_TEXT, Power(2), Life(2))
	, m_Embalm(this)
{
	// {U}: This creature gets +1/-1 until end of turn.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			BLUE_MANA_TEXT));

	cpAbility->SetAbilityText(_T("This creature gets +1/-1 until end of turn. Activates"));
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSinuousStrikerCard::BeforePump));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());

	// Eternalize - {3}{U}{U}, Discard a card.
	CAbility* pAbility = m_Embalm.AddEternalizeAbility(_T("3") BLUE_MANA_TEXT BLUE_MANA_TEXT);
	pAbility->GetCost().AddDiscardCardCost(1, CCardFilter::GetFilter(_T("cards")));
}

bool CSinuousStrikerCard::BeforePump(CAbilityAction* pAction)
{
	PumpCreature(this, +1, -1);
	return true;
}

CSpellweaverEternalCard::CSpellweaverEternalCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Spellweaver Eternal"), CardType::Creature, CREATURE_TYPE3(Zombie, Snake, Wizard), nID,
		_T("1") BLUE_MANA_TEXT, Power(2), Life(1))
	, m_Afflict(this)
{
	// Prowess
	AddProwess(this);

	// Afflict 2
	m_Afflict.AddAfflictAbility(2);
}

CStripedRiverwinderCard::CStripedRiverwinderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Striped Riverwinder"), CardType::Creature, CREATURE_TYPE(Serpent), nID,
		_T("6") BLUE_MANA_TEXT, Power(5), Life(5))
{
	// Hexproof
	GetCardKeyword()->AddHexproof(FALSE);

	// Cycling {U}
	AddCycling(this, BLUE_MANA_TEXT);
}

CUneshCriosphinxSovereignCard::CUneshCriosphinxSovereignCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Unesh, Criosphinx Sovereign"), CardType::_LegendaryCreature, CREATURE_TYPE(Sphinx), nID,
		_T("4") BLUE_MANA_TEXT BLUE_MANA_TEXT, Power(4), Life(4))
	, m_SeparateSelection(pGame, CSelectionSupport::SelectionCallback(this, &CUneshCriosphinxSovereignCard::OnPileSeparated))
	, m_PileSelection(pGame, CSelectionSupport::SelectionCallback(this, &CUneshCriosphinxSovereignCard::OnPileChosen))
{
	{
		// Sphinx spells you cast cost {2} less to cast. (as the Monuments in Amonkhet)
		counted_ptr<CConsLessManaEnchantment> cpAbility(
			::CreateObject<CConsLessManaEnchantment>(this,
				new CreatureTypeComparer(CREATURE_TYPE(Sphinx), false),
				_T("2")));

		cpAbility->SetAffectControllerCardsOnly();
		AddAbility(cpAbility.GetPointer());
	}
	{
		// Whenever Unesh or another Sphinx you control enters, reveal the top four cards of your library. An opponent
		// separates those cards into two piles. Put one pile into your hand and the other into your graveyard.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::_AllZones, ZoneId::Battlefield));

		cpAbility->GetTrigger().SetToControllerOnly(TRUE);
		cpAbility->GetTrigger().SetReportSelfMoves(TRUE);
		cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
		cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
			new CreatureTypeComparer(CREATURE_TYPE(Sphinx), false));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CUneshCriosphinxSovereignCard::BeforeReveal));
		AddAbility(cpAbility.GetPointer());
	}
}

// The opponent chooses the cards of the first pile (the rest are the second pile)
bool CUneshCriosphinxSovereignCard::BeforeReveal(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZone* pLibrary = pController->GetZoneById(ZoneId::Library);
	int nCount = pLibrary->GetSize() < 4 ? pLibrary->GetSize() : 4;
	if (nCount <= 0)
		return true;

	std::vector<SelectionEntry> entries;
	for (int i = 0; i < nCount; ++i)
	{
		CCard* pCard = pLibrary->GetAt(pLibrary->GetSize() - 1 - i);
		SelectionEntry entry;
		entry.dwContext = (DWORD)pCard;
		entry.cpAssociatedCard = pCard;
		entry.strText.Format(_T("Put %s in the first pile"), pCard->GetCardName(TRUE));
		entries.push_back(entry);
	}

	m_SeparateSelection.AddSelectionRequest(entries, 0, nCount, this, GetGame()->GetNextPlayer(pController),
		(DWORD)pController);
	return true;
}

// The controller (dwContext1) chooses the pile that goes to the hand
void CUneshCriosphinxSovereignCard::OnPileSeparated(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	CPlayer* pController = (CPlayer*)dwContext1;
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
		entry.strText.Format(_T("Put into your hand: %s"), strPile1.IsEmpty() ? _T("(empty pile)") : (LPCTSTR)strPile1);
		entries.push_back(entry);
	}
	{
		SelectionEntry entry;
		entry.dwContext = 2;
		entry.strText.Format(_T("Put into your hand: %s"), strPile2.IsEmpty() ? _T("(empty pile)") : (LPCTSTR)strPile2);
		entries.push_back(entry);
	}
	m_PileSelection.AddSelectionRequest(entries, 1, 1, this, pController);
}

void CUneshCriosphinxSovereignCard::OnPileChosen(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
		{
			CCountedCardContainer& hand = it->dwContext == 1 ? m_Pile1 : m_Pile2;
			CCountedCardContainer& graveyard = it->dwContext == 1 ? m_Pile2 : m_Pile1;

			CMoveCardModifier pToHand = CMoveCardModifier(ZoneId::Library, ZoneId::Hand, TRUE, MoveType::Others);
			for (int i = 0; i < hand.GetSize(); ++i)
				if (hand.GetAt(i)->GetZoneId() == ZoneId::Library)
					pToHand.ApplyTo(hand.GetAt(i));

			CMoveCardModifier pToGraveyard = CMoveCardModifier(ZoneId::Library, ZoneId::Graveyard, TRUE, MoveType::Others);
			for (int i = 0; i < graveyard.GetSize(); ++i)
				if (graveyard.GetAt(i)->GetZoneId() == ZoneId::Library)
					pToGraveyard.ApplyTo(graveyard.GetAt(i));
			break;
		}

	m_Pile1.RemoveAll();
	m_Pile2.RemoveAll();
}

CVizierOfTheAnointedCard::CVizierOfTheAnointedCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Vizier of the Anointed"), CardType::Creature, CREATURE_TYPE2(Human, Cleric), nID,
		_T("3") BLUE_MANA_TEXT, Power(2), Life(4))
	, m_EmbalmFilter(_T("a creature card with eternalize or embalm"), _T("creature cards with eternalize or embalm"),
		new AndCardComparer(new CardTypeComparer(CardType::Creature, false), new HasEmbalmComparer))
{
	// When this creature enters, you may search your library for a creature card with eternalize or embalm, put that
	// card into your graveyard, then shuffle.
	AddEnterTrigger(this, &CVizierOfTheAnointedCard::BeforeSearch, true);

	// Whenever you activate an eternalize or embalm ability, draw a card.
	// Not implemented: there are no events for activated abilities
}

bool CVizierOfTheAnointedCard::BeforeSearch(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Library, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(0), MaximumValue(1), // a creature card with eternalize or embalm
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		&m_EmbalmFilter, // what cards
		ZoneId::Graveyard, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // placement
		MoveType::Others, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);

	pController->GetZoneById(ZoneId::Library)->Shuffle();
	return true;
}

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Helpers (multicolored creatures)

#define INSECT_K_TOKEN_NAME	_T("Insect (K)")
#define INSECT_K_TOKEN_ID	55101

// "Whenever you exert a creature, <effect>" (as Amonkhet)
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

// "When this God dies, return it to its owner's hand at the beginning of the next end step." (as Long Road Home in
// Eldritch Moon)
static void ReturnToHandAtNextEndStep(CCard* pCard)
{
	if (pCard->GetZoneId() != ZoneId::Graveyard)
		return;

	CScheduledCardModifier pModifier = CScheduledCardModifier(pCard->GetGame(),
		new CMoveCardModifier(ZoneId::Graveyard, ZoneId::Hand, TRUE, MoveType::Others),
		TurnNumberDelta(-1), NodeId::EndStep, false, CScheduledCardModifier::Operation::ApplyToLater);
	pModifier.ApplyTo(pCard);
}

// "Target attacking Zombie gains <keyword> until end of turn"
static void AddAttackingZombieKeywordAbility(CCard* pCard, LPCTSTR strCost, CAbility::ResolutionStartedCallback callback)
{
	counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetSpell>>(pCard,
			strCost,
			new AttackingCreatureComparer, FALSE));

	cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->SetResolutionStartedCallback(callback);
	pCard->AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
// Multicolored creatures

CBloodwaterEntityCard::CBloodwaterEntityCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("Bloodwater Entity"), CardType::Creature, CREATURE_TYPE(Elemental), nID,
		_T("1") BLUE_MANA_TEXT RED_MANA_TEXT, Power(2), Life(2))
{
	// Prowess
	AddProwess(this);

	// When this creature enters, you may put target instant or sorcery card from your graveyard on top of your library.
	// (as Mortuary Mire in Battle for Zendikar)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new CardTypeComparer(CardType::Instant | CardType::Sorcery, false));
	cpAbility->GetTargeting().SetIncludeControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Positive);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Library);
	cpAbility->GetMoveCardModifier().SetToTop(TRUE);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Library));
	AddAbility(cpAbility.GetPointer());
}

CObeliskSpiderCard::CObeliskSpiderCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Obelisk Spider"), CardType::Creature, CREATURE_TYPE(Spider), nID,
		_T("1") BLACK_MANA_TEXT GREEN_MANA_TEXT, Power(1), Life(4))
{
	// Reach
	GetCreatureKeyword()->AddReach(FALSE);

	// Whenever this creature deals combat damage to a creature, put a -1/-1 counter on that creature.
	// Whenever you put one or more -1/-1 counters on a creature, each opponent loses 1 life and you gain 1 life.
	// Partial: the drain only happens with this creature's own counters (there are no events for counters)
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CObeliskSpiderCard::SetTriggerContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CObeliskSpiderCard::BeforeCounter));
	AddAbility(cpAbility.GetPointer());
}

// nValue1: the damaged creature
bool CObeliskSpiderCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const
{
	if (!pCreature)
		return false;

	triggerContext.nValue1 = (DWORD)pCreature;
	return true;
}

bool CObeliskSpiderCard::BeforeCounter(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCreature = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCreature || pCreature->GetZoneId() != ZoneId::Battlefield)
		return true;

	CCardCounterModifier pModifier = CCardCounterModifier(_T("-1/-1"), 1);
	pModifier.ApplyTo(pCreature);

	EachOpponentLosesLife(this, GetController(), 1);
	GainLife(this, GetController(), 1);
	return true;
}

CResoluteSurvivorsCard::CResoluteSurvivorsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Resolute Survivors"), CardType::Creature, CREATURE_TYPE2(Human, Warrior), nID,
		_T("1") RED_MANA_TEXT WHITE_MANA_TEXT, Power(3), Life(3))
	, m_Exert(this)
{
	// You may exert this creature as it attacks.
	m_Exert.AddExertAbility(_T("no other effect."));

	// Whenever you exert a creature, this creature deals 1 damage to each opponent and you gain 1 life.
	AddWheneverYouExertTrigger(this, &CResoluteSurvivorsCard::BeforeDrain, false);
}

bool CResoluteSurvivorsCard::BeforeDrain(CAbilityAction* pAction)
{
	DamageEachOpponent(this, pAction->GetController(), 1);
	GainLife(this, pAction->GetController(), 1);
	return true;
}

CRiverHoopoeCard::CRiverHoopoeCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("River Hoopoe"), CardType::Creature, CREATURE_TYPE(Bird), nID,
		GREEN_MANA_TEXT BLUE_MANA_TEXT, Power(1), Life(3))
{
	// {3}{G}{U}: You gain 2 life and draw a card.
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(this,
			_T("3") GREEN_MANA_TEXT BLUE_MANA_TEXT));

	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CLifeModifier(Life(+2), this, PreventableType::NotPreventable, DamageType::NotDealingDamage));
	cpAbility->GetResolutionModifier().CPlayerModifiers::push_back(
		new CDrawCardModifier(pGame, MinimumValue(1), MaximumValue(1)));
	cpAbility->SetAbilityText(_T("You gain 2 life and draw a card. Activates"));
	cpAbility->AddAbilityTag(AbilityTag::LifeGain);
	AddAbility(cpAbility.GetPointer());
}

CTheLocustGodCard::CTheLocustGodCard(CGame* pGame, UINT nID)
	: CFlyingCreatureCard(pGame, _T("The Locust God"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("4") BLUE_MANA_TEXT RED_MANA_TEXT, Power(4), Life(4))
{
	{
		// Whenever you draw a card, create a 1/1 blue and red Insect creature token with flying and haste.
		// (the draw trigger as Primitive Etchings in Scourge)
		typedef
			TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenCardDrew > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("cards")));
		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetCreateTokenOption(TRUE, INSECT_K_TOKEN_NAME, INSECT_K_TOKEN_ID, 1);
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{U}{R}: Draw a card, then discard a card.
		counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CGenericSpell>>(this,
				_T("2") BLUE_MANA_TEXT RED_MANA_TEXT));

		cpAbility->SetAbilityText(_T("Draw a card, then discard a card. Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheLocustGodCard::BeforeLoot));
		AddAbility(cpAbility.GetPointer());
	}

	// When The Locust God dies, return it to its owner's hand at the beginning of the next end step.
	AddDiesTrigger(this, &CTheLocustGodCard::BeforeReturn, false);
}

bool CTheLocustGodCard::BeforeLoot(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	if (pAction->GetController()->GetZoneById(ZoneId::Hand)->GetSize() > 0)
		DiscardCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CTheLocustGodCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnToHandAtNextEndStep(this);
	return true;
}

CTheScarabGodCard::CTheScarabGodCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("The Scarab God"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("3") BLUE_MANA_TEXT BLACK_MANA_TEXT, Power(5), Life(5))
{
	{
		// At the beginning of your upkeep, each opponent loses X life and you scry X, where X is the number of
		// Zombies you control.
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

		cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheScarabGodCard::BeforeUpkeep));
		cpAbility->AddAbilityTag(AbilityTag::LifeLost);
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {2}{U}{B}: Exile target creature card from a graveyard. Create a token that's a copy of it, except it's a
		// 4/4 black Zombie. (the token is made as with Eternalize, so it keeps its other creature types)
		counted_ptr<CActivatedAbility<CTargetMoveCardSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetMoveCardSpell>>(this,
				_T("2") BLUE_MANA_TEXT BLACK_MANA_TEXT,
				new AnyCreatureComparer,
				ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others));

		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheScarabGodCard::BeforeCopy));
		cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
		AddAbility(cpAbility.GetPointer());
	}

	// When The Scarab God dies, return it to its owner's hand at the beginning of the next end step.
	AddDiesTrigger(this, &CTheScarabGodCard::BeforeReturn, false);
}

bool CTheScarabGodCard::BeforeUpkeep(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCardFilter zombies(_T("a Zombie"), _T("Zombies"), new CreatureTypeComparer(CREATURE_TYPE(Zombie), false));
	int nX = zombies.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
	if (nX <= 0)
		return true;

	EachOpponentLosesLife(this, pController, nX);
	CScryModifier pScry = CScryModifier(GetGame(), nX, this);
	pScry.ApplyTo(pController);
	return true;
}

// The callback exiles the card itself and returns false
bool CTheScarabGodCard::BeforeCopy(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (!pCard || pCard->GetZoneId() != ZoneId::Graveyard)
		return false;

	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Exile, TRUE, MoveType::Others, pAction->GetController());
	pModifier.ApplyTo(pCard);
	if (pCard->GetZoneId() == ZoneId::Exile)
		CEmbalmSupport::CreateZombieCopy(pCard, pAction->GetController(), TRUE);
	return false;
}

bool CTheScarabGodCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnToHandAtNextEndStep(this);
	return true;
}

CTheScorpionGodCard::CTheScorpionGodCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("The Scorpion God"), CardType::_LegendaryCreature, CREATURE_TYPE(God), nID,
		_T("3") BLACK_MANA_TEXT RED_MANA_TEXT, Power(6), Life(5))
{
	{
		// Whenever a creature with a -1/-1 counter on it dies, draw a card. (a trigger before the creature moves, so
		// its counters can be checked)
		typedef
			TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard, TRUE, FALSE));

		cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("creatures")));
		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CTheScorpionGodCard::SetTriggerContext));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CTheScorpionGodCard::BeforeDraw));
		AddAbility(cpAbility.GetPointer());
	}
	{
		// {1}{B}{R}: Put a -1/-1 counter on another target creature.
		counted_ptr<CActivatedAbility<CTargetSpell>> cpAbility(
			::CreateObject<CActivatedAbility<CTargetSpell>>(this,
				_T("1") BLACK_MANA_TEXT RED_MANA_TEXT,
				new AnyCreatureComparer, FALSE));

		cpAbility->GetTargeting()->GetSubjectCardFilter().AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
		cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
		cpAbility->GetTargetModifier().CCardModifiers::push_back(new CCardCounterModifier(_T("-1/-1"), 1));
		AddAbility(cpAbility.GetPointer());
	}

	// When The Scorpion God dies, return it to its owner's hand at the beginning of the next end step.
	AddDiesTrigger(this, &CTheScorpionGodCard::BeforeReturn, false);
}

bool CTheScorpionGodCard::SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const
{
	if (!pCard)
		return false;

	const Counter* pCounter = ((const CCard*)pCard)->GetCounterContainer()->GetCounter(_T("-1/-1"));
	return pCounter && pCounter->GetCount() > 0;
}

bool CTheScorpionGodCard::BeforeDraw(CAbilityAction* pAction)
{
	DrawCards(GetGame(), pAction->GetController(), 1);
	return true;
}

bool CTheScorpionGodCard::BeforeReturn(CAbilityAction* pAction)
{
	ReturnToHandAtNextEndStep(this);
	return true;
}

CUnravelingMummyCard::CUnravelingMummyCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Unraveling Mummy"), CardType::Creature, CREATURE_TYPE(Zombie), nID,
		_T("1") WHITE_MANA_TEXT BLACK_MANA_TEXT, Power(2), Life(3))
{
	// {1}{W}: Target attacking Zombie gains lifelink until end of turn.
	AddAttackingZombieKeywordAbility(this, _T("1") WHITE_MANA_TEXT,
		CAbility::ResolutionStartedCallback(this, &CUnravelingMummyCard::BeforeLifelink));

	// {1}{B}: Target attacking Zombie gains deathtouch until end of turn.
	AddAttackingZombieKeywordAbility(this, _T("1") BLACK_MANA_TEXT,
		CAbility::ResolutionStartedCallback(this, &CUnravelingMummyCard::BeforeDeathtouch));
}

bool CUnravelingMummyCard::BeforeLifelink(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Lifelink, TRUE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

bool CUnravelingMummyCard::BeforeDeathtouch(CAbilityAction* pAction)
{
	CCard* pCard = pAction->GetAssociatedCard();
	if (pCard && pCard->GetZoneId() == ZoneId::Battlefield)
	{
		CCardKeywordModifier pModifier = CCardKeywordModifier(CardKeyword::Deathtouch, TRUE);
		pModifier.ApplyTo(pCard);
	}
	return true;
}

//____________________________________________________________________________
//
// Colorless creatures

CGravenAbominationCard::CGravenAbominationCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Graven Abomination"), CardType::_ArtifactCreature, CREATURE_TYPE(Horror), nID,
		_T("3"), Power(3), Life(1))
{
	// Whenever this creature attacks, exile target card from defending player's graveyard. (as Disposal Mummy)
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfAttackedBlocked,
								 CWhenSelfAttackedBlocked::AttackEventCallback,
								 &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTargeting().SetSubjectZoneId(ZoneId::Graveyard);
	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new TrueCardComparer);
	cpAbility->GetTargeting().SetIncludeNonControllerCardsOnly();
	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->GetMoveCardModifier().SetFromZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->GetMoveCardModifier().SetToOwnersZone(TRUE);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Graveyard, ZoneId::Exile));
	AddAbility(cpAbility.GetPointer());
}

CHollowOneCard::CHollowOneCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Hollow One"), CardType::_ArtifactCreature, CREATURE_TYPE(Golem), nID,
		_T("5"), Power(4), Life(4))
{
	// This spell costs {2} less to cast for each card you've cycled or discarded this turn.
	// Not implemented: the cost isn't reduced

	// Cycling {2}
	AddCycling(this, _T("2"));
}

CWallOfForgottenPharaohsCard::CWallOfForgottenPharaohsCard(CGame* pGame, UINT nID)
	: CCreatureCard(pGame, _T("Wall of Forgotten Pharaohs"), CardType::_ArtifactCreature, CREATURE_TYPE(Wall), nID,
		_T("2"), Power(0), Life(4))
{
	// Defender
	GetCreatureKeyword()->AddDefender(FALSE);

	// {T}: This creature deals 1 damage to target player or planeswalker. Activate only if you control a Desert or
	// there is a Desert card in your graveyard.
	// Note: it can't target planeswalkers
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this,
			_T(""),
			FALSE_CARD_COMPARER, TRUE,
			Life(-1), PreventableType::Preventable));

	cpAbility->AddTapCost();
	cpAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);
	cpAbility->GetTargeting()->SetDefaultCharacteristic(Characteristic::Negative);
	cpAbility->AddAbilityTag(AbilityTag::DamageSource);
	AddPlayableIf(this, cpAbility.GetPointer(), &CWallOfForgottenPharaohsCard::HasDesertCondition);
	AddAbility(cpAbility.GetPointer());
}

BOOL CWallOfForgottenPharaohsCard::HasDesertCondition(BOOL bIncludeTricks)
{
	return HasDesert(GetController());
}

//____________________________________________________________________________
//
