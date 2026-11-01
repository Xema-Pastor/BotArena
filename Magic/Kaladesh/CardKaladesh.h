#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
// Lands

// "This land enters tapped unless you control two or fewer other lands." {T}: Add one of two colors.
// (as Copperline Gorge in Scars of Mirrodin)
class CFastlandBase : public CNonbasicLandCard
{
protected:
	CFastlandBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strMana1, LPCTSTR strMana2);

	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class CAetherHubCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CAetherHubCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};
class CBloomingMarshCard : public CFastlandBase { DECLARE_CARD_CSTOR(CBloomingMarshCard); };
class CBotanicalSanctumCard : public CFastlandBase { DECLARE_CARD_CSTOR(CBotanicalSanctumCard); };
class CConcealedCourtyardCard : public CFastlandBase { DECLARE_CARD_CSTOR(CConcealedCourtyardCard); };
class CInspiringVantageCard : public CFastlandBase { DECLARE_CARD_CSTOR(CInspiringVantageCard); };
class CSpirebluffCanalCard : public CFastlandBase { DECLARE_CARD_CSTOR(CSpirebluffCanalCard); };

class CInventorsFairCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CInventorsFairCard);

protected:
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeLife(CAbilityAction* pAction) const;
	BOOL CanSearch(BOOL bIncludeTricks);
	BOOL HasThreeArtifacts() const;

	CCardFilter m_ArtifactFilter;
};

class CSequesteredStashCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSequesteredStashCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_ArtifactFilter;
};

//____________________________________________________________________________
//
// Planeswalkers

class CChandraPyrogeniusCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraPyrogeniusCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction) const;
	bool BeforeResolution3(CAbilityAction* pAction) const;
};

class CChandraTorchOfDefianceCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraTorchOfDefianceCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction) const;
};

class CDovinBaanCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDovinBaanCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction);

	CCardFilter m_ActivationFilter;		// the creature whose activated abilities can't be activated
};

class CNissaNaturesArtisanCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNissaNaturesArtisanCard);

protected:
	bool BeforeResolution2(CAbilityAction* pAction) const;
	bool BeforeResolution3(CAbilityAction* pAction) const;
};

class CNissaVitalForceCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNissaVitalForceCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction) const;
};

class CSaheeliRaiCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSaheeliRaiCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction);
	bool BeforeResolution2(CAbilityAction* pAction) const;

	CCardFilter m_ArtifactFilter;
};

//____________________________________________________________________________
//
// Artifacts

class CAetherfluxReservoirCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAetherfluxReservoirCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CCogworkersPuzzleknotCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CCogworkersPuzzleknotCard); };

class CDeadlockTrapCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDeadlockTrapCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeTap(CAbilityAction* pAction);

	CCardFilter m_ActivationFilter;		// the permanent whose activated abilities can't be activated this turn
};

class CDecoctionModuleCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDecoctionModuleCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CDynavoltTowerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDynavoltTowerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CFireforgersPuzzleknotCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CFireforgersPuzzleknotCard); };

class CGhirapurOrreryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGhirapurOrreryCard);

protected:
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDraw(CAbilityAction* pAction) const;
};

class CGlassblowersPuzzleknotCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGlassblowersPuzzleknotCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CInventorsGogglesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CInventorsGogglesCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeAttach(TriggeredAbility::TriggeredActionType* pAction);
};

class CKeyToTheCityCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CKeyToTheCityCard); };

class CMetalspinnersPuzzleknotCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMetalspinnersPuzzleknotCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CPerpetualTimepieceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPerpetualTimepieceCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;
	bool BeforeShuffle(CAbilityAction* pAction) const;
};

class CPropheticPrismCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CPropheticPrismCard); };
class CTorchGauntletCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CTorchGauntletCard); };
class CWhirlermakerCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CWhirlermakerCard); };

class CWoodweaversPuzzleknotCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWoodweaversPuzzleknotCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Vehicles (the creatures they become are in ATokens, see CCrewSupport)

class CAradaraExpressCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAradaraExpressCard);

protected:
	CCrewSupport m_Crew;
};

class CBallistaChargerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBallistaChargerCard);

protected:
	CCrewSupport m_Crew;
};

class CBomatBazaarBargeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBomatBazaarBargeCard);

protected:
	CCrewSupport m_Crew;
};

class CCultivatorsCaravanCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCultivatorsCaravanCard);

protected:
	CCrewSupport m_Crew;
};

class CDemolitionStomperCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDemolitionStomperCard);

protected:
	CCrewSupport m_Crew;
};

class CFleetwheelCruiserCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFleetwheelCruiserCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);

	CCrewSupport m_Crew;
};

class COvalchaseDragsterCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COvalchaseDragsterCard);

protected:
	CCrewSupport m_Crew;
};

class CRenegadeFreighterCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRenegadeFreighterCard);

protected:
	CCrewSupport m_Crew;
};

class CSkySkiffCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSkySkiffCard);

protected:
	CCrewSupport m_Crew;
};

class CSkysovereignConsulFlagshipCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSkysovereignConsulFlagshipCard);

protected:
	CCrewSupport m_Crew;
};

class CSmugglersCopterCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSmugglersCopterCard);

protected:
	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
// Enchantments

class CAetherMeltdownCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CAetherMeltdownCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CAuthorityOfTheConsulsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAuthorityOfTheConsulsCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CConsulateSurveillanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CConsulateSurveillanceCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CDurableHandicraftCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDurableHandicraftCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounters(CAbilityAction* pAction) const;
};

class CEraOfInnovationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEraOfInnovationCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CGiantSpectacleCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CGiantSpectacleCard); };

class CMalfunctionCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CMalfunctionCard);

protected:
	bool BeforeTap(CAbilityAction* pAction) const;
};

class CMetallurgicSummoningsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMetallurgicSummoningsCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenSpellCast > TriggeredAbility;

	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeConstruct(TriggeredAbility::TriggeredActionType* pAction);
	BOOL CanReturn(BOOL bIncludeTricks);
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CRevokePrivilegesCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CRevokePrivilegesCard); };

class CUnderhandedDesignsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CUnderhandedDesignsCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction) const;
	BOOL CanDestroy(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
// Sorceries

class CAttuneWithAetherCard : public CCard
{
	DECLARE_CARD_CSTOR(CAttuneWithAetherCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CCatharticReunionCard : public CCard { DECLARE_CARD_CSTOR(CCatharticReunionCard); };

class CConfiscationCoupCard : public CCard
{
	DECLARE_CARD_CSTOR(CConfiscationCoupCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDieYoungCard : public CCard
{
	DECLARE_CARD_CSTOR(CDieYoungCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnPaySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PaySelection;
};

class CEngineeredMightCard : public CCard
{
	DECLARE_CARD_CSTOR(CEngineeredMightCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CFortuitousFindCard : public CCard
{
	DECLARE_CARD_CSTOR(CFortuitousFindCard);

protected:
	bool BeforeResolutionBoth(CAbilityAction* pAction) const;
};

class CFragmentizeCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CFragmentizeCard); };

class CFumigateCard : public CCard
{
	DECLARE_CARD_CSTOR(CFumigateCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CFuriousReprisalCard : public CCard { DECLARE_CARD_CSTOR(CFuriousReprisalCard); };

class CHarshScrutinyCard : public CCard
{
	DECLARE_CARD_CSTOR(CHarshScrutinyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CHazardousConditionsCard : public CCard
{
	DECLARE_CARD_CSTOR(CHazardousConditionsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CHijackCard : public CCard { DECLARE_CARD_CSTOR(CHijackCard); };
class CLargerThanLifeCard : public CCard { DECLARE_CARD_CSTOR(CLargerThanLifeCard); };

class CLiberatingCombustionCard : public CCard
{
	DECLARE_CARD_CSTOR(CLiberatingCombustionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CLiveFastCard : public CCard
{
	DECLARE_CARD_CSTOR(CLiveFastCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMadcapExperimentCard : public CCard
{
	DECLARE_CARD_CSTOR(CMadcapExperimentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMorbidCuriosityCard : public CCard
{
	DECLARE_CARD_CSTOR(CMorbidCuriosityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_SacrificeFilter;
};

class CNaturesWayCard : public CCard
{
	DECLARE_CARD_CSTOR(CNaturesWayCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CRefurbishCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CRefurbishCard); };
class CRenegadeTacticsCard : public CCard { DECLARE_CARD_CSTOR(CRenegadeTacticsCard); };

class CSaheelisArtistryCard : public CCard
{
	DECLARE_CARD_CSTOR(CSaheelisArtistryCard);

protected:
	void CopyCard(CCard* pCard, BOOL bArtifact) const;
	bool BeforeArtifact(CAbilityAction* pAction) const;
	bool BeforeCreature(CAbilityAction* pAction) const;
	bool BeforeBoth(CAbilityAction* pAction) const;
};

class CServoExhibitionCard : public CCard { DECLARE_CARD_CSTOR(CServoExhibitionCard); };

class CTakeDownCard : public CCard
{
	DECLARE_CARD_CSTOR(CTakeDownCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CTezzeretsAmbitionCard : public CCard
{
	DECLARE_CARD_CSTOR(CTezzeretsAmbitionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CVerdantCrescendoCard : public CCard
{
	DECLARE_CARD_CSTOR(CVerdantCrescendoCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWildestDreamsCard : public CCard
{
	DECLARE_CARD_CSTOR(CWildestDreamsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Instants

class CAcrobaticManeuverCard : public CCard
{
	DECLARE_CARD_CSTOR(CAcrobaticManeuverCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CAetherTradewindsCard : public CCard
{
	DECLARE_CARD_CSTOR(CAetherTradewindsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CAppetiteForTheUnnaturalCard : public CCard
{
	DECLARE_CARD_CSTOR(CAppetiteForTheUnnaturalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CBlossomingDefenseCard : public CCard { DECLARE_CARD_CSTOR(CBlossomingDefenseCard); };

class CBuiltToLastCard : public CCard
{
	DECLARE_CARD_CSTOR(CBuiltToLastCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CBuiltToSmashCard : public CCard
{
	DECLARE_CARD_CSTOR(CBuiltToSmashCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CCeremoniousRejectionCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CCeremoniousRejectionCard); };
class CChandrasPyrohelixCard : public CTargetChgLifeSpellCard { DECLARE_CARD_CSTOR(CChandrasPyrohelixCard); };

class CCommencementOfFestivitiesCard : public CCard
{
	DECLARE_CARD_CSTOR(CCommencementOfFestivitiesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDisappearingActCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CDisappearingActCard); };

class CDramaticReversalCard : public CCard
{
	DECLARE_CARD_CSTOR(CDramaticReversalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CEssenceExtractionCard : public CCard
{
	DECLARE_CARD_CSTOR(CEssenceExtractionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CFailedInspectionCard : public CCounterSpellCard
{
	DECLARE_CARD_CSTOR(CFailedInspectionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CFatefulShowdownCard : public CCard
{
	DECLARE_CARD_CSTOR(CFatefulShowdownCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CFlameLashCard : public CTargetChgLifeSpellCard { DECLARE_CARD_CSTOR(CFlameLashCard); };

class CGlimmerOfGeniusCard : public CCard
{
	DECLARE_CARD_CSTOR(CGlimmerOfGeniusCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CHarnessedLightningCard : public CCard
{
	DECLARE_CARD_CSTOR(CHarnessedLightningCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnPaySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PaySelection;
};

class CImpeccableTimingCard : public CTargetChgLifeSpellCard { DECLARE_CARD_CSTOR(CImpeccableTimingCard); };

class CIncendiarySabotageCard : public CCard
{
	DECLARE_CARD_CSTOR(CIncendiarySabotageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMakeObsoleteCard : public CCard { DECLARE_CARD_CSTOR(CMakeObsoleteCard); };

class COrnamentalCourageCard : public CCard
{
	DECLARE_CARD_CSTOR(COrnamentalCourageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CParadoxicalOutcomeCard : public CCard
{
	DECLARE_CARD_CSTOR(CParadoxicalOutcomeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CRevolutionaryRebuffCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CRevolutionaryRebuffCard); };
class CRushOfVitalityCard : public CCard { DECLARE_CARD_CSTOR(CRushOfVitalityCard); };

class CSelectForInspectionCard : public CCard
{
	DECLARE_CARD_CSTOR(CSelectForInspectionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSkywhalersShotCard : public CCard
{
	DECLARE_CARD_CSTOR(CSkywhalersShotCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSubtleStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CSubtleStrikeCard);

protected:
	void Weaken(CCard* pCard) const;
	void AddCounter(CCard* pCard) const;
	bool BeforeWeaken(CAbilityAction* pAction) const;
	bool BeforeCounter(CAbilityAction* pAction) const;
	bool BeforeBoth(CAbilityAction* pAction) const;
};

class CTidyConclusionCard : public CCard
{
	DECLARE_CARD_CSTOR(CTidyConclusionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CUnlicensedDisintegrationCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnlicensedDisintegrationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWeldingSparksCard : public CCard
{
	DECLARE_CARD_CSTOR(CWeldingSparksCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Fabricate N (When this creature enters, put N +1/+1 counters on it or create N 1/1 colorless Servo artifact
// creature tokens.)
class CFabricateSupport
{
public:
	CFabricateSupport(CCreatureCard* pCard, int nCount);
	virtual ~CFabricateSupport() {}

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void CreateServos(CPlayer* pPlayer) const;

	CCreatureCard* m_pCard;
	int m_nCount;
	CSelectionSupport m_Selection;
};

// White creatures

class CAerialResponderCard : public CCreatureCard { DECLARE_CARD_CSTOR(CAerialResponderCard); };

class CAetherstormRocCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherstormRocCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CAngelOfInventionCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfInventionCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CAviaryMechanicCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAviaryMechanicCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CConsulsShieldguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CConsulsShieldguardCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CEddytrailHawkCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEddytrailHawkCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CGlintSleeveArtisanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGlintSleeveArtisanCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CHeraldOfTheFairCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHeraldOfTheFairCard); };
class CMasterTrinketeerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMasterTrinketeerCard); };
class CNinthBridgePatrolCard : public CCreatureCard { DECLARE_CARD_CSTOR(CNinthBridgePatrolCard); };

class CPropellerPioneerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPropellerPioneerCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CSkyswirlHarrierCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSkyswirlHarrierCard); };
class CTasseledDromedaryCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTasseledDromedaryCard); };

class CThrivingIbexCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrivingIbexCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CToolcraftExemplarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CToolcraftExemplarCard);

protected:
	bool BeforeCombat(CAbilityAction* pAction);
};

class CVisionaryAugmenterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVisionaryAugmenterCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CWispweaverAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWispweaverAngelCard);

protected:
	bool BeforeFlicker(CAbilityAction* pAction) const;
};

class CFairgroundsWardenCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFairgroundsWardenCard);

protected:
	CCountedCardContainer_ pExiled;
	
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfInplay, 
									CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;
	
	bool SetTriggerContext1(CTriggeredAbility<>::TriggerContextType& triggerContext, 
										 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType) const;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction);

	bool SetTriggerContext2(CTriggeredAbility<>::TriggerContextType& triggerContext, 
										CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;

	bool SetTriggerContextAux(CTriggeredAbility<>::TriggerContextType& triggerContext, 
										CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

//____________________________________________________________________________
//
// Green creatures

class CArborbackStomperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArborbackStomperCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CArchitectOfTheUntamedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArchitectOfTheUntamedCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CArmorcraftJudgeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArmorcraftJudgeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction) const;
};

class CBristlingHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBristlingHydraCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeCounter(CAbilityAction* pAction) const;
};

class CCowlProwlerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCowlProwlerCard); };

class CCultivatorOfBladesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCultivatorOfBladesCard);

protected:
	bool BeforeAttack(CAbilityAction* pAction);

	CFabricateSupport m_Fabricate;
};

class CElegantEdgecraftersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElegantEdgecraftersCard);

protected:
	CCardFilter m_CanBlockFilter;
	CFabricateSupport m_Fabricate;
};

class CGhirapurGuideCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhirapurGuideCard);

protected:
	bool BeforeEvasion(CAbilityAction* pAction) const;

	CCardFilter m_CanBlockFilter;
};

class CHighspireArtisanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHighspireArtisanCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CKujarSeedsculptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKujarSeedsculptorCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction) const;
};

class CLongtuskCubCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLongtuskCubCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeCounter(CAbilityAction* pAction) const;
};

class COviyaPashiriSageLifecrafterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COviyaPashiriSageLifecrafterCard);

protected:
	bool BeforeConstruct(CAbilityAction* pAction) const;
};

class CPeemaOutriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPeemaOutriderCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CRiparianTigerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRiparianTigerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CSageOfShailasClaimCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSageOfShailasClaimCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CServantOfTheConduitCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CServantOfTheConduitCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CTerrainElementalCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTerrainElementalCard); };

class CThrivingRhinoCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrivingRhinoCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CVerdurousGearhulkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVerdurousGearhulkCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	void RequestCounter(CPlayer* pPlayer, int nRemaining);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

class CWildWandererCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWildWandererCard); };

class CWilyBandarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWilyBandarCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Red creatures

class CAethertorchRenegadeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAethertorchRenegadeCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CBrazenScourgeCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBrazenScourgeCard); };

class CCombustibleGearhulkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCombustibleGearhulkCard);

protected:
	bool BeforeChoice(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
};

class CInventorsApprenticeCard : public CCreatureCard { DECLARE_CARD_CSTOR(CInventorsApprenticeCard); };

class CLathnuHellionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLathnuHellionCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeEndStep(CAbilityAction* pAction);
	void OnPaySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void Sacrifice();

	CSelectionSupport m_PaySelection;
};

class CMaulfistDoorbusterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMaulfistDoorbusterCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CPiaNalaarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPiaNalaarCard);

protected:
	bool BeforeThopter(CAbilityAction* pAction) const;
};

class CQuicksmithGeniusCard : public CCreatureCard { DECLARE_CARD_CSTOR(CQuicksmithGeniusCard); };

class CRecklessFireweaverCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRecklessFireweaverCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction) const;
};

class CRenegadeFirebrandCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRenegadeFirebrandCard); };
class CRuinousGremlinCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRuinousGremlinCard); };
class CSalivatingGremlinsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSalivatingGremlinsCard); };
class CSkyshipStalkerCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSkyshipStalkerCard); };

class CSpiresideInfiltratorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpiresideInfiltratorCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction) const;
};

class CSpontaneousArtistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpontaneousArtistCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CTerrorOfTheFairgroundsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTerrorOfTheFairgroundsCard); };

class CThrivingGrubsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrivingGrubsCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CWaywardGiantCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWaywardGiantCard); };

// Green (skipped before)
class CGuardianOfTheGreatConduitCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGuardianOfTheGreatConduitCard); };

//____________________________________________________________________________
//
// Black creatures

class CAetherbornMarauderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherbornMarauderCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	void OnPermanentsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PermanentSelection;
};

class CAmbitiousAetherbornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAmbitiousAetherbornCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CDemonOfDarkSchemesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDemonOfDarkSchemesCard);

protected:
	bool BeforeWeaken(CAbilityAction* pAction) const;
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CDhundOperativeCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDhundOperativeCard); };

class CDukharaScavengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDukharaScavengerCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CEmbraalBruiserCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEmbraalBruiserCard); };
class CFoundryScreecherCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CFoundryScreecherCard); };

class CFretworkColonyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFretworkColonyCard);

protected:
	bool BeforeUpkeep(CAbilityAction* pAction) const;
};

class CLawlessBrokerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLawlessBrokerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction) const;
};

class CMarionetteMasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMarionetteMasterCard);

protected:
	bool BeforeLifeLoss(CAbilityAction* pAction) const;

	CFabricateSupport m_Fabricate;
};

class CMaulfistSquadCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMaulfistSquadCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CNightMarketLookoutCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNightMarketLookoutCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction) const;
};

class CNoxiousGearhulkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNoxiousGearhulkCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction) const;
};

class COvalchaseDaredevilCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COvalchaseDaredevilCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CPrakhataClubSecurityCard : public CCreatureCard { DECLARE_CARD_CSTOR(CPrakhataClubSecurityCard); };

class CSyndicateTraffickerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyndicateTraffickerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction) const;
};

class CThrivingRatsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrivingRatsCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CWeaponcraftEnthusiastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWeaponcraftEnthusiastCard);

protected:
	CFabricateSupport m_Fabricate;
};

//____________________________________________________________________________
//
// Blue creatures

class CAethersquallAncientCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAethersquallAncientCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeBounce(CAbilityAction* pAction) const;
};

class CAetherTheoristCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherTheoristCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CCurioVendorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCurioVendorCard); };

class CExperimentalAviatorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CExperimentalAviatorCard);

protected:
	bool BeforeThopters(CAbilityAction* pAction) const;
};

class CGearseekerSerpentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGearseekerSerpentCard);

protected:
	CCardFilter m_CardFilter;
};

class CGlintNestCraneCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGlintNestCraneCard);

protected:
	bool BeforeLook(CAbilityAction* pAction) const;
};

class CHightideHermitCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHightideHermitCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CJanjeetSentryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJanjeetSentryCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeTap(CAbilityAction* pAction) const;
};

class CLongFinnedSkywhaleCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CLongFinnedSkywhaleCard); };

class CMinisterOfInquiriesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMinisterOfInquiriesCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeMill(CAbilityAction* pAction) const;
};

class CNimbleInnovatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNimbleInnovatorCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction) const;
};

class CPadeemConsulOfInnovationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPadeemConsulOfInnovationCard);

protected:
	bool BeforeUpkeep(CAbilityAction* pAction) const;
};

class CThrivingTurtleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrivingTurtleCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CVedalkenBlademasterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CVedalkenBlademasterCard); };
class CWeldfastWingsmithCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWeldfastWingsmithCard); };

//____________________________________________________________________________
//
// Multicolored creatures

class CCloudblazerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCloudblazerCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction) const;
};

class CContrabandKingpinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CContrabandKingpinCard);

protected:
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CEmpyrealVoyagerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEmpyrealVoyagerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeEnergy(TriggeredAbility::TriggeredActionType* pAction);
};

class CKambalConsulOfAllocationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKambalConsulOfAllocationCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction) const;
};

class CRestorationGearsmithCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRestorationGearsmithCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CVeteranMotoristCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVeteranMotoristCard);

protected:
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CVoltaicBrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVoltaicBrawlerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CWhirlerVirtuosoCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWhirlerVirtuosoCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Colorless creatures

class CAccomplishedAutomatonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAccomplishedAutomatonCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CBastionMastodonCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBastionMastodonCard); };
class CChiefOfTheFoundryCard : public CCreatureCard { DECLARE_CARD_CSTOR(CChiefOfTheFoundryCard); };
class CConsulateSkygateCard : public CCreatureCard { DECLARE_CARD_CSTOR(CConsulateSkygateCard); };
class CDukharaPeafowlCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDukharaPeafowlCard); };

class CEagerConstructCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEagerConstructCard);

protected:
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CElectrostaticPummelerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElectrostaticPummelerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforePump(CAbilityAction* pAction);
};

class CFiligreeFamiliarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFiligreeFamiliarCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CFoundryInspectorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFoundryInspectorCard); };

class CIronLeagueSteedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIronLeagueSteedCard);

protected:
	CFabricateSupport m_Fabricate;
};

class CMultiformWonderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMultiformWonderCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeFlying(CAbilityAction* pAction);
	bool BeforeVigilance(CAbilityAction* pAction);
	bool BeforeLifelink(CAbilityAction* pAction);
	bool BeforePowerUp(CAbilityAction* pAction);
	bool BeforeToughnessUp(CAbilityAction* pAction);
	void ChangePowerToughness(int nPower, int nToughness);
};

class CNarnamCobraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNarnamCobraCard);

protected:
	bool BeforeDeathtouch(CAbilityAction* pAction) const;
};

class CPrakhataPillarBugCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPrakhataPillarBugCard);

protected:
	bool BeforeLifelink(CAbilityAction* pAction) const;
};

class CSelfAssemblerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSelfAssemblerCard); };
class CSnareThopterCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSnareThopterCard); };
class CWeldfastMonitorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWeldfastMonitorCard); };

class CWorkshopAssistantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWorkshopAssistantCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
