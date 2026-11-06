#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

// Amonkhet cycling lands: "Land - A B ({T}: Add {A} or {B}.) This land enters tapped. Cycling {2}"
class CCyclingDualLandBase : public CDualLandCard
{
protected:
	CCyclingDualLandBase(CGame* pGame, LPCTSTR strCardName, UINT nID, CardType landType,
		LPCTSTR strMana1, LPCTSTR strMana2);
};

class CCanyonSloughCard : public CCyclingDualLandBase { DECLARE_CARD_CSTOR(CCanyonSloughCard); };
class CFetidPoolsCard : public CCyclingDualLandBase { DECLARE_CARD_CSTOR(CFetidPoolsCard); };
class CIrrigatedFarmlandCard : public CCyclingDualLandBase { DECLARE_CARD_CSTOR(CIrrigatedFarmlandCard); };
class CScatteredGrovesCard : public CCyclingDualLandBase { DECLARE_CARD_CSTOR(CScatteredGrovesCard); };
class CShelteredThicketCard : public CCyclingDualLandBase { DECLARE_CARD_CSTOR(CShelteredThicketCard); };

class CCascadingCataractsCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CCascadingCataractsCard);
};

class CCradleOfTheAccursedCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CCradleOfTheAccursedCard);
};

class CGraspingDunesCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CGraspingDunesCard);
};

class CPaintedBluffsCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CPaintedBluffsCard);
};

class CSunscorchedDesertCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSunscorchedDesertCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CGideonOfTheTrialsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CGideonOfTheTrialsCard);

protected:
	bool BeforePrevent(CAbilityAction* pAction) const;

	ListenerPtr<ResolutionCompletedEventSource::Listener>	m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
};

class CGideonMartialParagonCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CGideonMartialParagonCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction) const;
	bool BeforeUltimate(CAbilityAction* pAction) const;

	ListenerPtr<ResolutionCompletedEventSource::Listener>	m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
};

class CLilianaDeathsMajestyCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CLilianaDeathsMajestyCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;
	bool BeforeDestroy(CAbilityAction* pAction) const;

	ListenerPtr<ResolutionCompletedEventSource::Listener>	m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
};

class CLilianaDeathWielderCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CLilianaDeathWielderCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

// Monuments: "<Color> creature spells you cast cost {1} less to cast. Whenever you cast a creature spell, <effect>."
class CMonumentBase : public CInPlaySpellCard
{
protected:
	CMonumentBase(CGame* pGame, LPCTSTR strCardName, UINT nID, CardType color);
};

class CBontusMonumentCard : public CMonumentBase
{
	DECLARE_CARD_CSTOR(CBontusMonumentCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction) const;
};

class CHazoretsMonumentCard : public CMonumentBase
{
	DECLARE_CARD_CSTOR(CHazoretsMonumentCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction) const;
};

class CKefnetsMonumentCard : public CMonumentBase
{
	DECLARE_CARD_CSTOR(CKefnetsMonumentCard);

protected:
	bool BeforeFreeze(CAbilityAction* pAction) const;
};

class COketrasMonumentCard : public CMonumentBase
{
	DECLARE_CARD_CSTOR(COketrasMonumentCard);

protected:
	bool BeforeToken(CAbilityAction* pAction) const;
};

class CRhonassMonumentCard : public CMonumentBase
{
	DECLARE_CARD_CSTOR(CRhonassMonumentCard);

protected:
	bool BeforePump(CAbilityAction* pAction) const;
};

class CEdificeOfAuthorityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEdificeOfAuthorityCard);

protected:
	BOOL HasThreeBricks(BOOL bIncludeTricks);
	bool BeforeCantAttack(CAbilityAction* pAction) const;
	bool BeforeCantAttackOrBlock(CAbilityAction* pAction) const;
};

class CEmbalmersToolsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEmbalmersToolsCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;

	CCardFilter m_ZombieFilter;
};

class CGateToTheAfterlifeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGateToTheAfterlifeCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction) const;
};

class CHonedKhopeshCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHonedKhopeshCard);
};

class CLuxaRiverShrineCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLuxaRiverShrineCard);

protected:
	BOOL HasThreeBricks(BOOL bIncludeTricks);
};

class CPyramidOfThePantheonCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPyramidOfThePantheonCard);

protected:
	BOOL HasThreeBricks(BOOL bIncludeTricks);
};

class CThroneOfTheGodPharaohCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CThroneOfTheGodPharaohCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

class CAnointedProcessionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAnointedProcessionCard);
};

class CBountyOfTheLuxaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBountyOfTheLuxaCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeFlood(CAbilityAction* pAction);
};

// Cartouches: "Enchant creature you control. When this Aura enters, <effect>. Enchanted creature gets +1/+1 and has
// <keyword>."
class CCartoucheBase : public CChgPwrTghAttrEnchantCard
{
protected:
	CCartoucheBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCost, CreatureKeyword keyword);
};

class CCartoucheOfAmbitionCard : public CCartoucheBase
{
	DECLARE_CARD_CSTOR(CCartoucheOfAmbitionCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CCartoucheOfKnowledgeCard : public CCartoucheBase
{
	DECLARE_CARD_CSTOR(CCartoucheOfKnowledgeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CCartoucheOfSolidarityCard : public CCartoucheBase
{
	DECLARE_CARD_CSTOR(CCartoucheOfSolidarityCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CCartoucheOfStrengthCard : public CCartoucheBase
{
	DECLARE_CARD_CSTOR(CCartoucheOfStrengthCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CCartoucheOfZealCard : public CCartoucheBase
{
	DECLARE_CARD_CSTOR(CCartoucheOfZealCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
};

class CCastOutCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCastOutCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CCompulsoryRestCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCompulsoryRestCard);

protected:
	counted_ptr<CAbility> CreateLifeAbility(CCard* pCard);
};

class CConsumingFervorCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CConsumingFervorCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CCruelRealityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCruelRealityCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

class CDrakeHavenCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDrakeHavenCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CFaithOfTheDevotedCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFaithOfTheDevotedCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CGideonsResolveCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGideonsResolveCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CHazoretsFavorCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHazoretsFavorCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CLayClaimCard : public CCard
{
	DECLARE_CARD_CSTOR(CLayClaimCard);
};

class CLilianasMasteryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLilianasMasteryCard);
};

class CNewPerspectivesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CNewPerspectivesCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSandwurmConvergenceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSandwurmConvergenceCard);
};

class CSixthSenseCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSixthSenseCard);
};

class CTrespassersCurseCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTrespassersCurseCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

// Trials: "When this enchantment enters, <effect>. When a Cartouche you control enters, return this enchantment to its
// owner's hand."
class CTrialBase : public CInPlaySpellCard
{
protected:
	CTrialBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCost);

	bool BeforeReturnToHand(CAbilityAction* pAction);
};

class CTrialOfAmbitionCard : public CTrialBase
{
	DECLARE_CARD_CSTOR(CTrialOfAmbitionCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
};

class CTrialOfKnowledgeCard : public CTrialBase
{
	DECLARE_CARD_CSTOR(CTrialOfKnowledgeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CTrialOfSolidarityCard : public CTrialBase
{
	DECLARE_CARD_CSTOR(CTrialOfSolidarityCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CTrialOfStrengthCard : public CTrialBase
{
	DECLARE_CARD_CSTOR(CTrialOfStrengthCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CTrialOfZealCard : public CTrialBase
{
	DECLARE_CARD_CSTOR(CTrialOfZealCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

class CBenefactionOfRhonasCard : public CCard
{
	DECLARE_CARD_CSTOR(CBenefactionOfRhonasCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_CreatureFilter;
	CCardFilter m_EnchantmentFilter;
};

class CBlazingVolleyCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlazingVolleyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CByForceCard : public CCard
{
	DECLARE_CARD_CSTOR(CByForceCard);
};

class CCompellingArgumentCard : public CCard
{
	DECLARE_CARD_CSTOR(CCompellingArgumentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CFloodwatersCard : public CCard
{
	DECLARE_CARD_CSTOR(CFloodwatersCard);
};

class CHarvestSeasonCard : public CCard
{
	DECLARE_CARD_CSTOR(CHarvestSeasonCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CLayBareTheHeartCard : public CCard
{
	DECLARE_CARD_CSTOR(CLayBareTheHeartCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CLilianasInfluenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CLilianasInfluenceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CLimitsOfSolidarityCard : public CCard
{
	DECLARE_CARD_CSTOR(CLimitsOfSolidarityCard);
};

class COpenIntoWonderCard : public CCard
{
	DECLARE_CARD_CSTOR(COpenIntoWonderCard);
};

class CPainfulLessonCard : public CCard
{
	DECLARE_CARD_CSTOR(CPainfulLessonCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSacredExcavationCard : public CCard
{
	DECLARE_CARD_CSTOR(CSacredExcavationCard);
};

class CStirTheSandsCard : public CCard
{
	DECLARE_CARD_CSTOR(CStirTheSandsCard);
};

class CSwelteringSunsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSwelteringSunsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CViolentImpactCard : public CCard
{
	DECLARE_CARD_CSTOR(CViolentImpactCard);
};

class CWanderInDeathCard : public CCard
{
	DECLARE_CARD_CSTOR(CWanderInDeathCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

class CCensorCard : public CCounterSpellCard
{
	DECLARE_CARD_CSTOR(CCensorCard);
};

class CDecisionParalysisCard : public CCard
{
	DECLARE_CARD_CSTOR(CDecisionParalysisCard);
};

class CDeemWorthyCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeemWorthyCard);
};

class CDissentersDeliveranceCard : public CCard
{
	DECLARE_CARD_CSTOR(CDissentersDeliveranceCard);
};

class CDjerusResolveCard : public CCard
{
	DECLARE_CARD_CSTOR(CDjerusResolveCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CElectrifyCard : public CCard
{
	DECLARE_CARD_CSTOR(CElectrifyCard);
};

class CFinalRewardCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinalRewardCard);
};

class CForsakeTheWorldlyCard : public CCard
{
	DECLARE_CARD_CSTOR(CForsakeTheWorldlyCard);
};

class CGalestrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CGalestrikeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CHapatrasMarkCard : public CCard
{
	DECLARE_CARD_CSTOR(CHapatrasMarkCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CHazeOfPollenCard : public CCard
{
	DECLARE_CARD_CSTOR(CHazeOfPollenCard);
};

class CHieroglyphicIlluminationCard : public CCard
{
	DECLARE_CARD_CSTOR(CHieroglyphicIlluminationCard);
};

class CInOketrasNameCard : public CCard
{
	DECLARE_CARD_CSTOR(CInOketrasNameCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPullFromTomorrowCard : public CCard
{
	DECLARE_CARD_CSTOR(CPullFromTomorrowCard);

protected:
	ListenerPtr<ResolutionCompletedEventSource::Listener>	m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
};

class CPursueGloryCard : public CCard
{
	DECLARE_CARD_CSTOR(CPursueGloryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CScarabFeastCard : public CCard
{
	DECLARE_CARD_CSTOR(CScarabFeastCard);
};

class CShedWeaknessCard : public CCard
{
	DECLARE_CARD_CSTOR(CShedWeaknessCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSplendidAgonyCard : public CCard
{
	DECLARE_CARD_CSTOR(CSplendidAgonyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CStingingShotCard : public CCard
{
	DECLARE_CARD_CSTOR(CStingingShotCard);
};

class CSynchronizedStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CSynchronizedStrikeCard);
};

class CWindsOfRebukeCard : public CCard
{
	DECLARE_CARD_CSTOR(CWindsOfRebukeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Aftermath (split cards: the first half is cast from the hand, the second one from the graveyard, see
// CAftermathSupport)

class CCommitMemoryCard : public CCard
{
	DECLARE_CARD_CSTOR(CCommitMemoryCard);
};

class CCutRibbonsCard : public CCard
{
	DECLARE_CARD_CSTOR(CCutRibbonsCard);

protected:
	bool BeforeRibbons(CAbilityAction* pAction);
};

class CDestinedLeadCard : public CCard
{
	DECLARE_CARD_CSTOR(CDestinedLeadCard);

protected:
	bool BeforeDestined(CAbilityAction* pAction);
};

class CDuskDawnCard : public CCard
{
	DECLARE_CARD_CSTOR(CDuskDawnCard);

protected:
	bool BeforeDusk(CAbilityAction* pAction);
	bool BeforeDawn(CAbilityAction* pAction);
};

class CFailureComplyCard : public CCard
{
	DECLARE_CARD_CSTOR(CFailureComplyCard);
};

class CHeavenEarthCard : public CCard
{
	DECLARE_CARD_CSTOR(CHeavenEarthCard);

protected:
	bool BeforeHeaven(CAbilityAction* pAction);
	bool BeforeEarth(CAbilityAction* pAction);
};

class CInsultInjuryCard : public CCard
{
	DECLARE_CARD_CSTOR(CInsultInjuryCard);

protected:
	bool BeforeInsult(CAbilityAction* pAction);
	bool BeforeInjury(CAbilityAction* pAction);
};

class CMouthFeedCard : public CCard
{
	DECLARE_CARD_CSTOR(CMouthFeedCard);

protected:
	bool BeforeFeed(CAbilityAction* pAction);
};

class CNeverReturnCard : public CCard
{
	DECLARE_CARD_CSTOR(CNeverReturnCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class COnwardVictoryCard : public CCard
{
	DECLARE_CARD_CSTOR(COnwardVictoryCard);

protected:
	bool BeforeOnward(CAbilityAction* pAction);
};

class CPrepareFightCard : public CCard
{
	DECLARE_CARD_CSTOR(CPrepareFightCard);

protected:
	bool BeforePrepare(CAbilityAction* pAction);
	bool BeforeFight(CAbilityAction* pAction);
};

class CRagsRichesCard : public CCard
{
	DECLARE_CARD_CSTOR(CRagsRichesCard);

protected:
	bool BeforeRags(CAbilityAction* pAction);
	bool BeforeRiches(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

class CReduceRubbleCard : public CCard
{
	DECLARE_CARD_CSTOR(CReduceRubbleCard);
};

class CSpringMindCard : public CCard
{
	DECLARE_CARD_CSTOR(CSpringMindCard);

protected:
	bool BeforeSpring(CAbilityAction* pAction);
};

class CStartFinishCard : public CCard
{
	DECLARE_CARD_CSTOR(CStartFinishCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

class CAngelOfSanctionsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfSanctionsCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
	CEmbalmSupport m_Embalm;
};

class CAnointerPriestCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAnointerPriestCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CAvenMindcensorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenMindcensorCard);
};

class CBindingMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBindingMummyCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CCompanionOfTheTrialsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCompanionOfTheTrialsCard);

protected:
	BOOL ControlsGideon(BOOL bIncludeTricks);
};

class CDevotedCropMateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDevotedCropMateCard);

protected:
	bool BeforeExertReturn(CAbilityAction* pAction);
};

class CFanBearerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFanBearerCard);
};

class CGloryBoundInitiateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGloryBoundInitiateCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CGracefulCatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGracefulCatCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CGustWalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGustWalkerCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class COketrasAttendantCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(COketrasAttendantCard);

protected:
	CEmbalmSupport m_Embalm;
};

class COketraTheTrueCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COketraTheTrueCard);
};

class CRegalCaracalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRegalCaracalCard);
};

class CRhetCropSpearmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRhetCropSpearmasterCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CSacredCatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSacredCatCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CSeraphOfTheSunsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSeraphOfTheSunsCard);
};

class CSparringMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSparringMummyCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CSupplyCaravanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSupplyCaravanCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CTahCropEliteCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTahCropEliteCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CThoseWhoServeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThoseWhoServeCard);
};

class CTrueheartDuelistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrueheartDuelistCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CUnwaveringInitiateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUnwaveringInitiateCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CVizierOfDefermentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVizierOfDefermentCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CWingedShepherdCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWingedShepherdCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

class CBitterbladeWarriorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBitterbladeWarriorCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CChampionOfRhonasCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChampionOfRhonasCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CChannelerInitiateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChannelerInitiateCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CColossapedeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CColossapedeCard);
};

class CCrocodileOfTheCrossingCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCrocodileOfTheCrossingCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CDefiantGreatmawCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDefiantGreatmawCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CExemplarOfStrengthCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CExemplarOfStrengthCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeRemove(CAbilityAction* pAction);
};

class CGreaterSandwurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGreaterSandwurmCard);

protected:
	CCardFilter m_CanBlockFilter;
};

class CHonoredHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHonoredHydraCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CHoodedBrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHoodedBrawlerCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CInitiatesCompanionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInitiatesCompanionCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CManglehornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CManglehornCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CNagaVitalistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNagaVitalistCard);
};

class COashraCultivatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COashraCultivatorCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class COrneryKuduCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrneryKuduCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CPouncingCheetahCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPouncingCheetahCard);
};

class CProwlingSerpopardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CProwlingSerpopardCard);
};

class CRhonasTheIndomitableCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRhonasTheIndomitableCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CScaledBehemothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScaledBehemothCard);
};

class CShefetMonitorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShefetMonitorCard);

protected:
	CCardFilter m_LandFilter;
};

class CWatchfulNagaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWatchfulNagaCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

class CAhnCropCrasherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAhnCropCrasherCard);

protected:
	bool BeforeExertCantBlock(CAbilityAction* pAction);
};

class CBattlefieldScavengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBattlefieldScavengerCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CBloodlustInciterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodlustInciterCard);

protected:
	bool BeforeHaste(CAbilityAction* pAction);
};

class CBloodrageBrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodrageBrawlerCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CDesertCerodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDesertCerodonCard);
};

class CEmberhornMinotaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmberhornMinotaurCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CFlamebladeAdeptCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFlamebladeAdeptCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CGlorybringerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGlorybringerCard);

protected:
	bool BeforeExertDamage(CAbilityAction* pAction);
};

class CHazoretTheFerventCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHazoretTheFerventCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CHeartPiercerManticoreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeartPiercerManticoreCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
	CEmbalmSupport m_Embalm;
};

class CHyenaPackCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHyenaPackCard);
};

class CManticoreOfTheGauntletCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CManticoreOfTheGauntletCard);

protected:
	bool BeforeCounterAndDamage(CAbilityAction* pAction);
};

class CMinotaurSureshotCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMinotaurSureshotCard);
};

class CNefCropEntanglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNefCropEntanglerCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CNimbleBladeKhenraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNimbleBladeKhenraCard);
};

class CPathmakerInitiateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPathmakerInitiateCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
};

class CSoulScarMageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSoulScarMageCard);
};

class CThresherLizardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThresherLizardCard);
};

class CTrueheartTwinsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrueheartTwinsCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CWarfireJavelineerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWarfireJavelineerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

class CArchfiendOfIfnirCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArchfiendOfIfnirCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CBalefulAmmitCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBalefulAmmitCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CBlightedBatCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBlightedBatCard);
};

class CBonePickerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBonePickerCard);

protected:
	BOOL CreatureDiedThisTurn(BOOL bIncludeTricks);
};

class CBontuTheGlorifiedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBontuTheGlorifiedCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeAllowAttack(CAbilityAction* pAction);
	bool BeforeDrain(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

class CCursedMinotaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCursedMinotaurCard);
};

class CDesiccatedNagaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDesiccatedNagaCard);

protected:
	BOOL ControlsLiliana(BOOL bIncludeTricks);
	bool BeforeDrain(CAbilityAction* pAction);
};

class CDoomedDissenterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDoomedDissenterCard);
};

class CDreadWandererCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDreadWandererCard);

protected:
	BOOL OneOrFewerCardsInHand(BOOL bIncludeTricks);
};

class CDuneBeetleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDuneBeetleCard);
};

class CFesteringMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFesteringMummyCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CGrimStriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrimStriderCard);
};

class CHorrorOfTheBrokenLandsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHorrorOfTheBrokenLandsCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CLordOfTheAccursedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLordOfTheAccursedCard);

protected:
	bool BeforeMenace(CAbilityAction* pAction);
};

class CMiasmicMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMiasmicMummyCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CPitilessVizierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPitilessVizierCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CPlagueBelcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPlagueBelcherCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CRuthlessSniperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRuthlessSniperCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CSoulstingerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSoulstingerCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeMoveCounters(CAbilityAction* pAction);
};

class CTatteredMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTatteredMummyCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CWastelandScorpionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWastelandScorpionCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

class CAnglerDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAnglerDrakeCard);

protected:
	bool BeforeBounce(CAbilityAction* pAction);
};

class CAvenInitiateCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenInitiateCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CCrypticSerpentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCrypticSerpentCard);

protected:
	int CountInstantsAndSorceries() const;
	BOOL HasOne(BOOL bIncludeTricks)	{ return CountInstantsAndSorceries() >= 1; }
	BOOL HasTwo(BOOL bIncludeTricks)	{ return CountInstantsAndSorceries() >= 2; }
	BOOL HasThree(BOOL bIncludeTricks)	{ return CountInstantsAndSorceries() >= 3; }
	BOOL HasFour(BOOL bIncludeTricks)	{ return CountInstantsAndSorceries() >= 4; }
	BOOL HasFive(BOOL bIncludeTricks)	{ return CountInstantsAndSorceries() >= 5; }
};

class CCuratorOfMysteriesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCuratorOfMysteriesCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

class CGlyphKeeperCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGlyphKeeperCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CHekmaSentinelsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHekmaSentinelsCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CKefnetTheMindfulCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKefnetTheMindfulCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	void OnLandSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_LandSelection;
};

class CLabyrinthGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLabyrinthGuardianCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CNagaOracleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNagaOracleCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CRiverSerpentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRiverSerpentCard);
};

class CScribeOfTheMindfulCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScribeOfTheMindfulCard);
};

class CSeekerOfInsightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSeekerOfInsightCard);

protected:
	BOOL CastNoncreatureSpell(BOOL bIncludeTricks);
	bool BeforeLoot(CAbilityAction* pAction);
};

class CShimmerscaleDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CShimmerscaleDrakeCard);
};

class CSlitherBladeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSlitherBladeCard);
};

class CTahCropSkirmisherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTahCropSkirmisherCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CVizierOfTumblingSandsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVizierOfTumblingSandsCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CZenithSeekerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CZenithSeekerCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

class CAhnCropChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAhnCropChampionCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CAvenWindGuideCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenWindGuideCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CDecimatorBeetleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDecimatorBeetleCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeMoveCounter(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

class CEnigmaDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEnigmaDrakeCard);
};

class CHapatraVizierOfPoisonsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHapatraVizierOfPoisonsCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CHonoredCropCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHonoredCropCaptainCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CKhenraCharioteerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKhenraCharioteerCard);
};

class CMercilessJavelineerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMercilessJavelineerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CNehebTheWorthyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNehebTheWorthyCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CSamutVoiceOfDissentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSamutVoiceOfDissentCard);
};

class CShadowstormVizierCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CShadowstormVizierCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CTemmetVizierOfNaktamunCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTemmetVizierOfNaktamunCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CWatchersOfTheDeadCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWatchersOfTheDeadCard);

protected:
	bool BeforeExileGraveyards(CAbilityAction* pAction);
	void OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CWaywardServantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWaywardServantCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CWeaverOfCurrentsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWeaverOfCurrentsCard);
};

//____________________________________________________________________________
//
