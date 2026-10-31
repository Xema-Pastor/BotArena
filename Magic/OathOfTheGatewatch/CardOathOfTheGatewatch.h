#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
// Wastes: basic land without a basic land type; {T}: Add {C}.
class CWastesCard : public CBasicLandCard
{
	DECLARE_CARD_CSTOR(CWastesCard);
};

//____________________________________________________________________________
//
class CCrumblingVestigeCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CCrumblingVestigeCard); };
class CHissingQuagmireCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CHissingQuagmireCard); };
class CHoldoutSettlementCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CHoldoutSettlementCard); };
class CNeedleSpiresCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CNeedleSpiresCard); };
class CRuinsOfOranRiefCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CRuinsOfOranRiefCard); };
class CWanderingFumaroleCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CWanderingFumaroleCard); };

class CMirrorpoolCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMirrorpoolCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSeaGateWreckageCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSeaGateWreckageCard);

protected:
	BOOL CanPlay(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
// Artifacts
class CChitinousCloakCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CChitinousCloakCard); };
class CHedronCrawlerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHedronCrawlerCard); };

class CCaptainsClawsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCaptainsClawsCard);

private:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
};

class CSeersLanternCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSeersLanternCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Sorceries
class CDevourInFlamesCard : public CCard { DECLARE_CARD_CSTOR(CDevourInFlamesCard); };
class COblivionStrikeCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(COblivionStrikeCard); };
class CSlipThroughSpaceCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CSlipThroughSpaceCard); };
class CSparkmagesGambitCard : public CCard { DECLARE_CARD_CSTOR(CSparkmagesGambitCard); };

class CBoulderSalvoCard : public CCard
{
	DECLARE_CARD_CSTOR(CBoulderSalvoCard);

protected:
	CSurgeSupport m_Surge;
};

class CCrushOfTentaclesCard : public CCard
{
	DECLARE_CARD_CSTOR(CCrushOfTentaclesCard);

protected:
	CSurgeSupport m_Surge;
	void OnSurgeResolved(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CFlayingTendrilsCard : public CCard
{
	DECLARE_CARD_CSTOR(CFlayingTendrilsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CRoilingWatersCard : public CCard
{
	DECLARE_CARD_CSTOR(CRoilingWatersCard);

protected:
	class CRoilingWatersSpell : public CDoubleTargetSpell
	{
	DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		CRoilingWatersSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost);
		virtual ~CRoilingWatersSpell() {}

		OVERRIDE(void, ResolveGroup)(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2, const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2);
	};
};

class CRuinInTheirWakeCard : public CCard
{
	DECLARE_CARD_CSTOR(CRuinInTheirWakeCard);

protected:
	BOOL ControlsWastes() const;
	BOOL CanPlayToBattlefield(BOOL bIncludeTricks);
	BOOL CanPlayToHand(BOOL bIncludeTricks);
};

class CWitnessTheEndCard : public CCard
{
	DECLARE_CARD_CSTOR(CWitnessTheEndCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Other creatures
class CBalothNullCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBalothNullCard); };
class CCinderHellionCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCinderHellionCard); };
class CGladehartCavalryCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGladehartCavalryCard); };
class CLoamLarvaCard : public CCreatureCard { DECLARE_CARD_CSTOR(CLoamLarvaCard); };
class CReflectorMageCard : public CCreatureCard { DECLARE_CARD_CSTOR(CReflectorMageCard); };
class CRelentlessHunterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRelentlessHunterCard); };
class CSaddlebackLagacCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSaddlebackLagacCard); };
class CSphinxOfTheFinalWordCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSphinxOfTheFinalWordCard); };
class CStormchaserMageCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CStormchaserMageCard); };

class CHarvesterTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHarvesterTrollCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	CCardFilter m_SacrificeFilter;
};

class CJoriEnRuinDiverCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJoriEnRuinDiverCard);

protected:
	bool SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CCard* pCard) const;
};

class CJwarIsleAvengerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CJwarIsleAvengerCard);

protected:
	CSurgeSupport m_Surge;
};

class CLinvalaThePreserverCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLinvalaThePreserverCard);

protected:
	bool SetLifeContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetTokenContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
						 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CNullCallerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNullCallerCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	CCardFilter m_ExileFilter;
};

class CTyrantOfValakutCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTyrantOfValakutCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	CSurgeSupport m_Surge;
};

//____________________________________________________________________________
//
// Allies

// Cohort - {T}, Tap an untapped Ally you control: ...
class CCohortCreatureCard : public CCreatureCard
{
protected:
	CCohortCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						LPCTSTR strCostText, Power nPower, Life nToughness);

	void AddCohortCost(CAbility* pAbility);

	CCardFilter m_CohortFilter;
};

class CCliffhavenVampireCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCliffhavenVampireCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};
class CJoragaAuxiliaryCard : public CCreatureCard { DECLARE_CARD_CSTOR(CJoragaAuxiliaryCard); };
class CMalakirSoothsayerCard : public CCohortCreatureCard { DECLARE_CARD_CSTOR(CMalakirSoothsayerCard); };
class CMinaAndDennWildbornCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMinaAndDennWildbornCard); };
class CTajuruPathwardenCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTajuruPathwardenCard); };
class CUmaraEntanglerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CUmaraEntanglerCard); };
class CVampireEnvoyCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CVampireEnvoyCard); };
class CZadasCommandoCard : public CCohortCreatureCard { DECLARE_CARD_CSTOR(CZadasCommandoCard); };
class CZulaportChainmageCard : public CCohortCreatureCard { DECLARE_CARD_CSTOR(CZulaportChainmageCard); };

class CAkoumFlameseekerCard : public CCohortCreatureCard
{
	DECLARE_CARD_CSTOR(CAkoumFlameseekerCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

class CDranasChosenCard : public CCohortCreatureCard
{
	DECLARE_CARD_CSTOR(CDranasChosenCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CGeneralTazriCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGeneralTazriCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CGoblinFreerunnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinFreerunnerCard);

protected:
	CSurgeSupport m_Surge;
};

class CRecklessBushwhackerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRecklessBushwhackerCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolution(CAbilityAction* pAction) const;
	CSurgeSupport m_Surge;
};

//____________________________________________________________________________
//
// Eldrazi creatures
class CBirthingHulkCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CBirthingHulkCard); };
class CBlindingDroneCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBlindingDroneCard); };
class CEssenceDepleterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEssenceDepleterCard); };
class CFlayerDroneCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFlayerDroneCard); };
class CGravityNegatorCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CGravityNegatorCard); };
class CHavocSowerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHavocSowerCard); };
class CKozileksShriekerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKozileksShriekerCard); };
class CKozileksTranslatorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKozileksTranslatorCard); };
class CMawOfKozilekCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMawOfKozilekCard); };
class CMindmelterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMindmelterCard); };
class CProphetOfDistortionCard : public CCreatureCard { DECLARE_CARD_CSTOR(CProphetOfDistortionCard); };
class CScionSummonerCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CScionSummonerCard); };
class CSifterOfSkullsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSifterOfSkullsCard); };
class CSkyScourerCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSkyScourerCard); };
class CSlaughterDroneCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSlaughterDroneCard); };
class CStalkingDroneCard : public CCreatureCard { DECLARE_CARD_CSTOR(CStalkingDroneCard); };
class CVoidGrafterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CVoidGrafterCard); };
class CWalkerOfTheWastesCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWalkerOfTheWastesCard); };
class CWardenOfGeometriesCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWardenOfGeometriesCard); };
class CWorldBreakerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWorldBreakerCard); };

class CBearerOfSilenceCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBearerOfSilenceCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfMoved > TriggeredAbility;

	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

class CDeepfathomSkulkerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDeepfathomSkulkerCard); };

class CDimensionalInfiltratorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDimensionalInfiltratorCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_Selection;
};

class CEldraziDisplacerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEldraziDisplacerCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CEndbringerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEndbringerCard);

protected:
	bool SetUntapContext(CTriggeredTapCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CImmobilizerEldraziCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImmobilizerEldraziCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CInverterOfTruthCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CInverterOfTruthCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CReaverDroneCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CReaverDroneCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CThoughtHarvesterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CThoughtHarvesterCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CThoughtKnotSeerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThoughtKnotSeerCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

//____________________________________________________________________________
//
// Enchantments
class CUntamedHungerCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CUntamedHungerCard); };

class CBondsOfMortalityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBondsOfMortalityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CContainmentMembraneCard : public CCard
{
	DECLARE_CARD_CSTOR(CContainmentMembraneCard);

protected:
	CSurgeSupport m_Surge;
};

class CHedronAlignmentCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHedronAlignmentCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredLoseGameAbility, CWhenNodeChanged > TriggeredAbility;

	BOOL HasAllHedronAlignments() const;
	bool SetTriggerContext(CTriggeredLoseGameAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction);
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CIonasBlessingCard : public CCard
{
	DECLARE_CARD_CSTOR(CIonasBlessingCard);

protected:
	class CIonasBlessingEnchant : public CChgPwrTghAttrEnchant
	{
	DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		CIonasBlessingEnchant(CCard* pCard, LPCTSTR strManaCost);
		virtual ~CIonasBlessingEnchant() {}

		OVERRIDE(BOOL, OnEnchant)(CCard* pCard, ContextValue_& contextValue);
		OVERRIDE(void, OnDisenchant)(CCard* pCard, const ContextValue& contextValue);
	};
};

class COathOfChandraCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfChandraCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > PlaneswalkerAbility;
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenNodeChanged > EndStepAbility;

	bool OnPlaneswalkerEntered(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	bool SetEndStepContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
	int_ m_nPlaneswalkerTurn;
};

class COathOfGideonCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(COathOfGideonCard); };

class COathOfJaceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfJaceCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > UpkeepAbility;

	int CountPlaneswalkers() const;
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeScry(CAbilityAction* pAction) const;
};

class COathOfNissaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfNissaCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	CCardFilter m_CardFilter;
};

class CPyromancersAssaultCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPyromancersAssaultCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CCard* pCard) const;
};

class CZendikarResurgentCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CZendikarResurgentCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredSpecialProdManaAbility, CWhenTappedForMana > TriggeredAbility;
	bool SetTriggerContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
							const CManaProductionAbilityAction* pManaAction) const;
	TriggeredAbility* m_pTriggeredAbility;
};

//____________________________________________________________________________
//
// Instants
class CAbstruseInterferenceCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CAbstruseInterferenceCard); };
class CBruteStrengthCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CBruteStrengthCard); };
class CConsumingSinkholeCard : public CCard { DECLARE_CARD_CSTOR(CConsumingSinkholeCard); };
class CExpediteCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CExpediteCard); };
class CLeadByExampleCard : public CCard { DECLARE_CARD_CSTOR(CLeadByExampleCard); };
class CNaturalStateCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CNaturalStateCard); };
class CPulseOfMurasaCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CPulseOfMurasaCard); };
class CRealityHemorrhageCard : public CCard { DECLARE_CARD_CSTOR(CRealityHemorrhageCard); };
class CSpatialContortionCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CSpatialContortionCard); };
class CTarSnareCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CTarSnareCard); };
class CTearsOfValakutCard : public CCard { DECLARE_CARD_CSTOR(CTearsOfValakutCard); };
class CVinesOfTheRecluseCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CVinesOfTheRecluseCard); };
class CVoidShatterCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CVoidShatterCard); };
class CWarpingWailCard : public CCard { DECLARE_CARD_CSTOR(CWarpingWailCard); };

class CComparativeAnalysisCard : public CCard
{
	DECLARE_CARD_CSTOR(CComparativeAnalysisCard);

protected:
	CSurgeSupport m_Surge;
};

class CFallOfTheTitansCard : public CCard
{
	DECLARE_CARD_CSTOR(CFallOfTheTitansCard);

protected:
	CSurgeSupport m_Surge;
};

class CGripOfTheRoilCard : public CCard
{
	DECLARE_CARD_CSTOR(CGripOfTheRoilCard);

protected:
	CSurgeSupport m_Surge;
};

class COverwhelmingDenialCard : public CCard
{
	DECLARE_CARD_CSTOR(COverwhelmingDenialCard);

protected:
	CSurgeSupport m_Surge;
};

class CCorpseChurnCard : public CCard
{
	DECLARE_CARD_CSTOR(CCorpseChurnCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

class CUnityOfPurposeCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnityOfPurposeCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CUnnaturalEnduranceCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CUnnaturalEnduranceCard); };

//____________________________________________________________________________
//
// Planeswalkers
class CChandraFlamecallerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraFlamecallerCard);

protected:
	bool BeforeResolution0(CAbilityAction* pAction) const;
	bool BeforeResolutionX(CAbilityAction* pAction) const;
};

class CNissaVoiceOfZendikarCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNissaVoiceOfZendikarCard);

protected:
	bool BeforeResolution2(CAbilityAction* pAction) const;
	bool BeforeResolution7(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
class CMeanderingRiverCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMeanderingRiverCard);
};

//____________________________________________________________________________
//
class CSubmergedBoneyardCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSubmergedBoneyardCard);
};

//____________________________________________________________________________
//
class CCinderBarrensCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CCinderBarrensCard);
};

//____________________________________________________________________________
//
class CTimberGorgeCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CTimberGorgeCard);
};

//____________________________________________________________________________
//
class CTranquilExpanseCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CTranquilExpanseCard);
};

//____________________________________________________________________________
//
class CAffaProtectorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAffaProtectorCard);
};

//____________________________________________________________________________
//
class CCanopyGorgerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCanopyGorgerCard);
};

//____________________________________________________________________________
//
class CMakindiAeronautCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMakindiAeronautCard);
};

//____________________________________________________________________________
//
class CKorSkyClimberCard : public CPumpCreatureCard
{
	DECLARE_CARD_CSTOR(CKorSkyClimberCard);
};

//____________________________________________________________________________
//
class CSearingLightCard : public CTargetMoveCardSpellCard
{
	DECLARE_CARD_CSTOR(CSearingLightCard);
};

//____________________________________________________________________________
//
class CShoulderToShoulderCard : public CCard
{
	DECLARE_CARD_CSTOR(CShoulderToShoulderCard);
};

//____________________________________________________________________________
//
class CCallTheGatewatchCard : public CSearchLibrarySpellCard
{
	DECLARE_CARD_CSTOR(CCallTheGatewatchCard);
protected:
	CCardFilter m_CardFilter;
};

//____________________________________________________________________________
//
class CMakeAStandCard : public CCard
{
	DECLARE_CARD_CSTOR(CMakeAStandCard);
};

//____________________________________________________________________________
//
class CKorScythemasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKorScythemasterCard);
};

//____________________________________________________________________________
//
class CSpawnbinderMageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpawnbinderMageCard);

protected:
	CCardFilter m_CardFilter;
};

//____________________________________________________________________________
//
class COnduWarClericCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COnduWarClericCard);

protected:
	CCardFilter m_CardFilter;
};

//____________________________________________________________________________
//
class CStoneforgeAcolyteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStoneforgeAcolyteCard);

protected:
	CCardFilter m_CardFilter1;
	CCardFilter m_CardFilter2;
};

//____________________________________________________________________________
//
class CMundasVanguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMundasVanguardCard);

protected:
	CCardFilter m_CardFilter;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CSteppeGliderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSteppeGliderCard);
};

//____________________________________________________________________________
//
class CReliefCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CReliefCaptainCard);
};

//____________________________________________________________________________
//
class CExpeditionRaptorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CExpeditionRaptorCard);
};

//____________________________________________________________________________
//
class CIsolationZoneCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CIsolationZoneCard);

private:
	CCardFlagModifier m_CardFlagModifier1;
	CCardFlagModifier m_CardFlagModifier2;
};

//_____________________________________________________________________________
//
class CAncientCrabCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAncientCrabCard);
};

//____________________________________________________________________________
//
class CAlliedReinforcementsCard : public CCard
{
	DECLARE_CARD_CSTOR(CAlliedReinforcementsCard);
};

//____________________________________________________________________________
//
class CImmolatingGlareCard : public CTargetMoveCardSpellCard
{
	DECLARE_CARD_CSTOR(CImmolatingGlareCard);
};

//____________________________________________________________________________
//
