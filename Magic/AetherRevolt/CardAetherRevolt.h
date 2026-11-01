#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
// Lands

class CSpireOfIndustryCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSpireOfIndustryCard);

protected:
	BOOL CanTap(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
// Planeswalkers

class CAjaniUnyieldingCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniUnyieldingCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction) const;
	bool BeforeExile(CAbilityAction* pAction) const;
	bool BeforeUltimate(CAbilityAction* pAction) const;
};

class CAjaniValiantProtectorCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniValiantProtectorCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction) const;
	bool BeforeReveal(CAbilityAction* pAction) const;
	bool BeforeUltimate(CAbilityAction* pAction) const;
};

class CTezzeretMasterOfMetalCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTezzeretMasterOfMetalCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction) const;
	bool BeforeLifeLoss(CAbilityAction* pAction) const;
	bool BeforeUltimate(CAbilityAction* pAction) const;
};

class CTezzeretTheSchemerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTezzeretTheSchemerCard);

protected:
	bool BeforeChange(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Artifacts

class CConsulateTurretCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CConsulateTurretCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CGontisAetherHeartCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGontisAetherHeartCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CImplementOfCombustionCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CImplementOfCombustionCard); };
class CImplementOfExaminationCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CImplementOfExaminationCard); };

class CImplementOfFerocityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CImplementOfFerocityCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction) const;
};

class CImplementOfImprovementCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CImplementOfImprovementCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CImplementOfMaliceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CImplementOfMaliceCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction) const;
};

class CLifecraftersBestiaryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLifecraftersBestiaryCard);

protected:
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CPacificationArrayCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CPacificationArrayCard); };

class CParadoxEngineCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CParadoxEngineCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction) const;
};

class CPendulumOfPatternsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPendulumOfPatternsCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CPlanarBridgeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPlanarBridgeCard);

protected:
	CCardFilter m_PermanentFilter;
};

class CRenegadeMapCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CRenegadeMapCard); };

class CServoSchematicCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CServoSchematicCard);

protected:
	bool BeforeServo(CAbilityAction* pAction) const;
};

class CUniversalSolventCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CUniversalSolventCard); };

//____________________________________________________________________________
//
// Vehicles (the creature each one becomes when crewed is in ATokens, see CCrewSupport)

class CAethersphereHarvesterCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAethersphereHarvesterCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeLifelink(CAbilityAction* pAction) const;

	CCrewSupport m_Crew;
};

class CConsulateDreadnoughtCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CConsulateDreadnoughtCard);

protected:
	CCrewSupport m_Crew;
};

class CHeartOfKiranCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHeartOfKiranCard);

protected:
	bool BeforeCrew(CAbilityAction* pAction);

	CCrewSupport m_Crew;
};

class CIrontreadCrusherCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CIrontreadCrusherCard);

protected:
	CCrewSupport m_Crew;
};

class CMobileGarrisonCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMobileGarrisonCard);

protected:
	CCrewSupport m_Crew;
};

class CPeacewalkerColossusCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPeacewalkerColossusCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction) const;

	CCrewSupport m_Crew;
};

class CUntetheredExpressCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CUntetheredExpressCard);

protected:
	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
// Enchantments

class CAerialModificationCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CAerialModificationCard); };

class CAidFromTheCowlCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAidFromTheCowlCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeReveal(CAbilityAction* pAction);
	void OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_Selection;
};

class CAjanisAidCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAjanisAidCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction) const;
};

class CCaughtInTheBrightsCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCaughtInTheBrightsCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject subject) const;
	bool BeforeExile(CAbilityAction* pAction) const;
};

class CConsulateCrackdownCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CConsulateCrackdownCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CEfficientConstructionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEfficientConstructionCard);

protected:
	bool BeforeThopter(CAbilityAction* pAction) const;
};

class CGontisMachinationsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGontisMachinationsCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeDrain(CAbilityAction* pAction) const;
};

class CHiddenStockpileCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHiddenStockpileCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeServo(CAbilityAction* pAction);
	bool BeforeScry(CAbilityAction* pAction) const;
};

class CIceOverCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CIceOverCard); };

class COathOfAjaniCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfAjaniCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction) const;
};

class CPiasRevolutionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPiasRevolutionCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeChoice(TriggeredAbility::TriggeredActionType* pAction);
	void OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_Selection;
};

class CSiegeModificationCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CSiegeModificationCard); };

class CThopterArrestCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CThopterArrestCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

//____________________________________________________________________________
//
// Sorceries

class CBaralsExpertiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CBaralsExpertiseCard);
};

class CBattleAtTheBridgeCard : public CCard
{
	DECLARE_CARD_CSTOR(CBattleAtTheBridgeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CChandrasRevolutionCard : public CCard
{
	DECLARE_CARD_CSTOR(CChandrasRevolutionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDaringDemolitionCard : public CCard { DECLARE_CARD_CSTOR(CDaringDemolitionCard); };

class CDarkIntimationsCard : public CCard
{
	DECLARE_CARD_CSTOR(CDarkIntimationsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnSacrificeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_SacrificeSelection;
	CCardFilter m_ReturnFilter;
};

class CDestructiveTamperingCard : public CCard
{
	DECLARE_CARD_CSTOR(CDestructiveTamperingCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction) const;
};

class CInspiringRoarCard : public CCard
{
	DECLARE_CARD_CSTOR(CInspiringRoarCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CKariZevsExpertiseCard : public CCard { DECLARE_CARD_CSTOR(CKariZevsExpertiseCard); };

class CPreyUponCard : public CCard
{
	DECLARE_CARD_CSTOR(CPreyUponCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CResourcefulReturnCard : public CCard
{
	DECLARE_CARD_CSTOR(CResourcefulReturnCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CReverseEngineerCard : public CCard
{
	DECLARE_CARD_CSTOR(CReverseEngineerCard);

protected:
	void AddReverseEngineerSpell(LPCTSTR strCost, int nTapped);
};

class CRishkarsExpertiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CRishkarsExpertiseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSecretSalvageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSecretSalvageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSramsExpertiseCard : public CCard { DECLARE_CARD_CSTOR(CSramsExpertiseCard); };

class CTezzeretsBetrayalCard : public CCard
{
	DECLARE_CARD_CSTOR(CTezzeretsBetrayalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWrangleCard : public CCard { DECLARE_CARD_CSTOR(CWrangleCard); };

class CYahennisExpertiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CYahennisExpertiseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Instants

class CAlleyEvasionCard : public CCard { DECLARE_CARD_CSTOR(CAlleyEvasionCard); };

class CCruelFinalityCard : public CCard
{
	DECLARE_CARD_CSTOR(CCruelFinalityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDecommissionCard : public CCard
{
	DECLARE_CARD_CSTOR(CDecommissionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDeftDismissalCard : public CTargetChgLifeSpellCard { DECLARE_CARD_CSTOR(CDeftDismissalCard); };

class CFatalPushCard : public CCard
{
	DECLARE_CARD_CSTOR(CFatalPushCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CHeroicInterventionCard : public CCard
{
	DECLARE_CARD_CSTOR(CHeroicInterventionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CHighspireInfusionCard : public CCard
{
	DECLARE_CARD_CSTOR(CHighspireInfusionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CHungryFlamesCard : public CCard
{
	DECLARE_CARD_CSTOR(CHungryFlamesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CIllusionistsStratagemCard : public CCard
{
	DECLARE_CARD_CSTOR(CIllusionistsStratagemCard);

protected:
	void Flicker(CCard* pCard, CPlayer* pController) const;
	bool BeforeOne(CAbilityAction* pAction) const;
	bool BeforeTwo(CAbilityAction* pAction) const;
};

class CInvigoratedRampageCard : public CCard
{
	DECLARE_CARD_CSTOR(CInvigoratedRampageCard);

protected:
	bool BeforeTwo(CAbilityAction* pAction) const;
};

class CLeaveInTheDustCard : public CCard
{
	DECLARE_CARD_CSTOR(CLeaveInTheDustCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CLifecraftersGiftCard : public CCard
{
	DECLARE_CARD_CSTOR(CLifecraftersGiftCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMetallicRebukeCard : public CCard
{
	DECLARE_CARD_CSTOR(CMetallicRebukeCard);

protected:
	void AddRebukeSpell(LPCTSTR strCost, int nTapped);
};

class CNaturalObsolescenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CNaturalObsolescenceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CPerilousPredicamentCard : public CCard
{
	DECLARE_CARD_CSTOR(CPerilousPredicamentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void RequestSacrifice(CPlayer* pOpponent, bool bArtifact);
	void OnSacrificeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_SacrificeSelection;
};

class CPreciseStrikeCard : public CCard { DECLARE_CARD_CSTOR(CPreciseStrikeCard); };

class CRenegadesGetawayCard : public CCard
{
	DECLARE_CARD_CSTOR(CRenegadesGetawayCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CTakeIntoCustodyCard : public CCard
{
	DECLARE_CARD_CSTOR(CTakeIntoCustodyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWhirOfInventionCard : public CCard
{
	DECLARE_CARD_CSTOR(CWhirOfInventionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_SearchFilter;
};

//____________________________________________________________________________
//
// White creatures

class CAeronautAdmiralCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CAeronautAdmiralCard); };

class CAethergeodeMinerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAethergeodeMinerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction);
	bool BeforeFlicker(CAbilityAction* pAction) const;
};

class CAetherInspectorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherInspectorCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CAirdropAeronautsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAirdropAeronautsCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeLife(CAbilityAction* pAction);
};

class CAudaciousInfiltratorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAudaciousInfiltratorCard);

protected:
	CCardFilter m_CanBlockFilter;
};

class CBastionEnforcerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBastionEnforcerCard); };

class CCountlessGearsRenegadeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCountlessGearsRenegadeCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeServo(CAbilityAction* pAction);
};

class CDawnfeatherEagleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDawnfeatherEagleCard);

protected:
	bool BeforePump(CAbilityAction* pAction) const;
};

class CDeadeyeHarpoonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyeHarpoonerCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDestroy(CAbilityAction* pAction) const;
};

class CFelidarGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFelidarGuardianCard);

protected:
	bool BeforeFlicker(CAbilityAction* pAction) const;
};

class CGhirapurOspreyCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CGhirapurOspreyCard); };

class CRestorationSpecialistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRestorationSpecialistCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CSolemnRecruitCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSolemnRecruitCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CSramSeniorEdificerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSramSeniorEdificerCard); };

//____________________________________________________________________________
//
// "This creature enters with N +1/+1 counters on it" (optionally only with Revolt: "...if a permanent left the
// battlefield under your control this turn"). The counters are put when it moves onto the battlefield (as the
// fastlands of Kaladesh enter tapped), not with a triggered ability.
class CEntersWithCountersCreatureCard : public CCreatureCard
{
protected:
	CEntersWithCountersCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
		LPCTSTR strCostText, Power nPower, Life nToughness, int nCounters, bool bRevolt);

	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;

	int m_nCounters;
	bool m_bRevolt;
};

// Green creatures

class CAetherHerderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherHerderCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CAetherstreamLeopardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherstreamLeopardCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CAetherwindBaskerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherwindBaskerCard);

protected:
	bool BeforeEnterEnergy(CAbilityAction* pAction) const;
	bool BeforeAttackEnergy(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CAjanisComradeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAjanisComradeCard);

protected:
	bool BeforeCombat(CAbilityAction* pAction);
};

class CDruidOfTheCowlCard : public CManaProductionTCreatureCard { DECLARE_CARD_CSTOR(CDruidOfTheCowlCard); };

class CGreenbeltRampagerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGreenbeltRampagerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CGreenwheelLiberatorCard : public CEntersWithCountersCreatureCard { DECLARE_CARD_CSTOR(CGreenwheelLiberatorCard); };

class CHiddenHerbalistsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHiddenHerbalistsCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeMana(CAbilityAction* pAction);
};

class CLifecraftCavalryCard : public CEntersWithCountersCreatureCard { DECLARE_CARD_CSTOR(CLifecraftCavalryCard); };
class CNarnamRenegadeCard : public CEntersWithCountersCreatureCard { DECLARE_CARD_CSTOR(CNarnamRenegadeCard); };

class CPeemaAetherSeerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPeemaAetherSeerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
};

class CRidgescaleTuskerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRidgescaleTuskerCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction) const;
};

class CScroungingBandarCard : public CEntersWithCountersCreatureCard
{
	DECLARE_CARD_CSTOR(CScroungingBandarCard);

protected:
	bool BeforeMove(CAbilityAction* pAction);
	void OnCountSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CountSelection;
};

class CSilkweaverEliteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSilkweaverEliteCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
// Red creatures

class CAetherChaserCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherChaserCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CEmbraalGearSmasherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmbraalGearSmasherCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction) const;
};

class CEnragedGiantCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEnragedGiantCard); };
class CFreejamRegentCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CFreejamRegentCard); };
class CFrontlineRebelCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFrontlineRebelCard); };
class CKariZevSkyshipRaiderCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKariZevSkyshipRaiderCard); };
class CLathnuSailbackCard : public CCreatureCard { DECLARE_CARD_CSTOR(CLathnuSailbackCard); };

class CLightningRunnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLightningRunnerCard);

protected:
	bool BeforeAttack(CAbilityAction* pAction);
};

class CRavenousIntruderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRavenousIntruderCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CRecklessRacerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRecklessRacerCard); };

class CScrapperChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScrapperChampionCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CSweatworksBrawlerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSweatworksBrawlerCard); };

//____________________________________________________________________________
//
// Black creatures

class CAetherPoisonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherPoisonerCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CAlleyStranglerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CAlleyStranglerCard); };

class CDefiantSalvagerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDefiantSalvagerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

class CFenHaulerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFenHaulerCard);

protected:
	CCardFilter m_CanBlockFilter;
};

class CFoundryHornetCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFoundryHornetCard);

protected:
	bool BeforeWeaken(CAbilityAction* pAction) const;
};

class CFourthBridgeProwlerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFourthBridgeProwlerCard); };
class CGiftedAetherbornCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGiftedAetherbornCard); };

class CGlintSleeveSiphonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGlintSleeveSiphonerCard);

protected:
	bool BeforeEnterEnergy(CAbilityAction* pAction) const;
	bool BeforeAttackEnergy(CAbilityAction* pAction);
	bool BeforeUpkeep(CAbilityAction* pAction);
};

class CHeraldOfAnguishCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHeraldOfAnguishCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CIroncladRevolutionaryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIroncladRevolutionaryCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
};

class CMidnightEntourageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMidnightEntourageCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CNightMarketAeronautCard : public CEntersWithCountersCreatureCard { DECLARE_CARD_CSTOR(CNightMarketAeronautCard); };

class CSlyRequisitionerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSlyRequisitionerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeServo(CAbilityAction* pAction);
};

class CVengefulRebelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVengefulRebelCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeWeaken(CAbilityAction* pAction) const;
};

class CYahenniUndyingPartisanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYahenniUndyingPartisanCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
// Blue creatures

class CAetherSwooperCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAetherSwooperCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeAttack(CAbilityAction* pAction);
};

class CAethertideWhaleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAethertideWhaleCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforeReturn(CAbilityAction* pAction);
};

class CBaralChiefOfComplianceCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBaralChiefOfComplianceCard); };

class CBastionInventorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBastionInventorCard); };

class CDispersalTechnicianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDispersalTechnicianCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CHinterlandDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHinterlandDrakeCard);

protected:
	CCardFilter m_CanBlockFilter;
};

class CSalvageScuttlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSalvageScuttlerCard);

protected:
	bool BeforeAttack(CAbilityAction* pAction);
	void OnArtifactSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ArtifactSelection;
};

class CShieldedAetherThiefCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShieldedAetherThiefCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction);
};

class CShipwreckMorayCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShipwreckMorayCard);

protected:
	bool BeforeEnergy(CAbilityAction* pAction) const;
	bool BeforePump(CAbilityAction* pAction);
};

class CTrophyMageCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTrophyMageCard); };
class CWindKinRaidersCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CWindKinRaidersCard); };

//____________________________________________________________________________
//
// Multicolored creatures

class CMaverickThopteristCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMaverickThopteristCard);

protected:
	bool BeforeThopters(CAbilityAction* pAction) const;
};

class COutlandBoarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COutlandBoarCard);

protected:
	CCardFilter m_CanBlockFilter;
};

class CRenegadeRallierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRenegadeRallierCard);

protected:
	bool RevoltContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction) const;
};

class CRenegadeWheelsmithCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRenegadeWheelsmithCard); };

class CRogueRefinerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRogueRefinerCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction) const;
};

class CSpirePatrolCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSpirePatrolCard);

protected:
	bool BeforeTap(CAbilityAction* pAction) const;
};

class CWeldfastEngineerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWeldfastEngineerCard); };

//____________________________________________________________________________
//
// Colorless creatures

class CAegisAutomatonCard : public CCreatureCard { DECLARE_CARD_CSTOR(CAegisAutomatonCard); };
class CAugmentingAutomatonCard : public CCreatureCard { DECLARE_CARD_CSTOR(CAugmentingAutomatonCard); };
class CBarricadeBreakerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBarricadeBreakerCard); };

class CFiligreeCrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFiligreeCrawlerCard);

protected:
	bool BeforeThopter(CAbilityAction* pAction);
};

class CFoundryAssemblerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFoundryAssemblerCard); };
class CNightMarketGuardCard : public CCreatureCard { DECLARE_CARD_CSTOR(CNightMarketGuardCard); };
class CPrizefighterConstructCard : public CCreatureCard { DECLARE_CARD_CSTOR(CPrizefighterConstructCard); };

class CReservoirWalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CReservoirWalkerCard);

protected:
	bool BeforeLife(CAbilityAction* pAction) const;
};

class CScrapTrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScrapTrawlerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(TriggeredAbility::TriggeredActionType* pAction);

	CCardFilter m_ReturnFilter;
};

class CTezzeretsSimulacrumCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTezzeretsSimulacrumCard);

protected:
	bool BeforeLifeLoss(CAbilityAction* pAction) const;
};

class CVerdantAutomatonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVerdantAutomatonCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CWatchfulAutomatonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWatchfulAutomatonCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

class CWelderAutomatonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWelderAutomatonCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
