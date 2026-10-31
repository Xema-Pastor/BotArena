#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
// Lands

class CGeierReachSanitariumCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CGeierReachSanitariumCard);

private:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);

	ListenerPtr<ResolutionCompletedEventSource::Listener>	m_cpEventListener;
};

class CHanweirBattlementsCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CHanweirBattlementsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CNephaliaAcademyCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CNephaliaAcademyCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const;
};

// Meld pair of Hanweir Battlements: Hanweir Garrison is the host card (see CMeldCreatureCard)
class CHanweirGarrisonCard : public CMeldCreatureCard
{
	DECLARE_CARD_CSTOR(CHanweirGarrisonCard);

protected:
	bool SetFrontContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const;
	bool SetMeldedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const;
};

class CHanweirTheWrithingTownshipCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CHanweirTheWrithingTownshipCard); };

//____________________________________________________________________________
//
// Planeswalkers

class CLilianaTheLastHopeCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CLilianaTheLastHopeCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction) const;
	bool BeforeResolution2(CAbilityAction* pAction) const;

	CCardFilter m_CreatureFilter;
};

//____________________________________________________________________________
//
// Madness (as in Shadows over Innistrad): the madness spell is cast from exile when the card is discarded
class CMadnessSupport
{
public:
	CMadnessSupport(CCard* pCard);
	void SetMadnessSpell(CSpell* pMadnessSpell);

protected:
	BOOL CanCastMadness(BOOL bIncludeTricks);
	CCard* m_pCard;
};

//____________________________________________________________________________
//
// Sorceries

class CAlchemistsGreetingCard : public CCard
{
	DECLARE_CARD_CSTOR(CAlchemistsGreetingCard);

protected:
	CMadnessSupport m_Madness;
};

class CCemeteryRecruitmentCard : public CCard
{
	DECLARE_CARD_CSTOR(CCemeteryRecruitmentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CCertainDeathCard : public CCard
{
	DECLARE_CARD_CSTOR(CCertainDeathCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CContingencyPlanCard : public CCard
{
	DECLARE_CARD_CSTOR(CContingencyPlanCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDarkSalvationCard : public CCard
{
	DECLARE_CARD_CSTOR(CDarkSalvationCard);

protected:
	void Resolve(CAbilityAction* pAction, CPlayer* pPlayer, CCard* pCreature) const;
	bool BeforeResolution1(CAbilityAction* pAction) const;
	bool BeforeResolution2(CAbilityAction* pAction) const;
};

class CDeployTheGatewatchCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeployTheGatewatchCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_CardFilter;
};

class CDistemperOfTheBloodCard : public CCard
{
	DECLARE_CARD_CSTOR(CDistemperOfTheBloodCard);

protected:
	CMadnessSupport m_Madness;
};

class CDragUnderCard : public CCard { DECLARE_CARD_CSTOR(CDragUnderCard); };

class CEldritchEvolutionCard : public CCard
{
	DECLARE_CARD_CSTOR(CEldritchEvolutionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_CardFilter;
};

class CHarmlessOfferingCard : public CCard { DECLARE_CARD_CSTOR(CHarmlessOfferingCard); };
class CIncendiaryFlowCard : public CCard { DECLARE_CARD_CSTOR(CIncendiaryFlowCard); };
class CIronwrightsCleansingCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CIronwrightsCleansingCard); };
class CMakeMischiefCard : public CCard { DECLARE_CARD_CSTOR(CMakeMischiefCard); };

class CProvidenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CProvidenceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CPryingQuestionsCard : public CCard
{
	DECLARE_CARD_CSTOR(CPryingQuestionsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CRuthlessDisposalCard : public CCard { DECLARE_CARD_CSTOR(CRuthlessDisposalCard); };

class CShredsOfSanityCard : public CCard
{
	DECLARE_CARD_CSTOR(CShredsOfSanityCard);

protected:
	void ReturnAndDiscard(CPlayer* pController, CCard* pCard1, CCard* pCard2) const;
	bool BeforeResolution1(CAbilityAction* pAction) const;
	bool BeforeResolution2(CAbilityAction* pAction) const;
};

class CSpectralReservesCard : public CCard { DECLARE_CARD_CSTOR(CSpectralReservesCard); };

class CSplendidReclamationCard : public CCard
{
	DECLARE_CARD_CSTOR(CSplendidReclamationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CStensiaBanquetCard : public CCard
{
	DECLARE_CARD_CSTOR(CStensiaBanquetCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CTakeInventoryCard : public CCard
{
	DECLARE_CARD_CSTOR(CTakeInventoryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWhispersOfEmrakulCard : public CCard
{
	DECLARE_CARD_CSTOR(CWhispersOfEmrakulCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Instants

class CAbandonReasonCard : public CCard
{
	DECLARE_CARD_CSTOR(CAbandonReasonCard);

protected:
	CMadnessSupport m_Madness;
};

class CChillingGraspCard : public CCard
{
	DECLARE_CARD_CSTOR(CChillingGraspCard);

protected:
	CMadnessSupport m_Madness;
};

class CClearShotCard : public CCard
{
	DECLARE_CARD_CSTOR(CClearShotCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDisplaceCard : public CCard
{
	DECLARE_CARD_CSTOR(CDisplaceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CGalvanicBombardmentCard : public CCard
{
	DECLARE_CARD_CSTOR(CGalvanicBombardmentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CGiveNoGroundCard : public CCard
{
	DECLARE_CARD_CSTOR(CGiveNoGroundCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CGrappleWithThePastCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrappleWithThePastCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_CardFilter;
};

class CLongRoadHomeCard : public CCard
{
	DECLARE_CARD_CSTOR(CLongRoadHomeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class COtherworldlyOutburstCard : public CCard
{
	DECLARE_CARD_CSTOR(COtherworldlyOutburstCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CRideDownCard : public CCard
{
	DECLARE_CARD_CSTOR(CRideDownCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CScourTheLaboratoryCard : public CCard
{
	DECLARE_CARD_CSTOR(CScourTheLaboratoryCard);

protected:
	BOOL CanCastWithDelirium(BOOL bIncludeTricks);
};

class CSpringsageRitualCard : public CCard { DECLARE_CARD_CSTOR(CSpringsageRitualCard); };
class CSuccumbToTemptationCard : public CCard { DECLARE_CARD_CSTOR(CSuccumbToTemptationCard); };
class CUnsubstantiateCard : public CCard { DECLARE_CARD_CSTOR(CUnsubstantiateCard); };

class CWaxingMoonCard : public CCard
{
	DECLARE_CARD_CSTOR(CWaxingMoonCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWoodcuttersGritCard : public CCard { DECLARE_CARD_CSTOR(CWoodcuttersGritCard); };

//____________________________________________________________________________
//
// Enchantments

class CBloodMistCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CBloodMistCard); };
class CBoonOfEmrakulCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CBoonOfEmrakulCard); };

class CCampaignOfVengeanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCampaignOfVengeanceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CChokingRestraintsCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CChokingRestraintsCard);

public:
	OVERRIDE(void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCard* m_pLastEnchantedCard;	// the enchanted creature when this Aura left the battlefield (sacrificed as a cost)
};

class CCropSigilCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCropSigilCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;
	BOOL CanActivate(BOOL bIncludeTricks);
	bool BeforeResolutionBoth(CAbilityAction* pAction) const;
};

class CEmrakulsInfluenceCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CEmrakulsInfluenceCard); };

class CFaithUnbrokenCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CFaithUnbrokenCard);

private:
	CCardFlagModifier m_CardFlagModifier1;
	CCardFlagModifier m_CardFlagModifier2;
};

class CGrafHarvestCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CGrafHarvestCard); };

class CLunarchMantleCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CLunarchMantleCard);

protected:
	counted_ptr<CAbility> CreateFlyingAbility(CCard* pCard);

	CCardFilter m_PermanentFilter;
};

class CLunarForceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLunarForceCard);

protected:
	bool SetTriggerContext(CTriggeredCounterSpellAbility::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeResolution(CAbilityAction* pAction);
};

class COathOfLilianaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfLilianaCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool SetPlaneswalkerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
								CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeZombie(CAbilityAction* pAction) const;

	CSelectionSupport m_CardSelection;
	int_ m_nPlaneswalkerTurn;	// game turn when a planeswalker entered the battlefield under your control
};

class CPeaceOfMindCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CPeaceOfMindCard); };

class CPropheticRavingsCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CPropheticRavingsCard);

protected:
	counted_ptr<CAbility> CreateLootAbility(CCard* pCard);
};

class CStrangeAugmentationCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CStrangeAugmentationCard); };
class CWolfkinBondCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CWolfkinBondCard); };

//____________________________________________________________________________
//
// White creatures

// Meld pair of Gisela, the Broken Blade: Bruna, the Fading Light is the host card (see CMeldCreatureCard)
class CBrunaTheFadingLightCard : public CMeldCreatureCard
{
	DECLARE_CARD_CSTOR(CBrunaTheFadingLightCard);

protected:
	CCardFilter m_SpellFilter;
};

class CBriselaVoiceOfNightmaresCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CBriselaVoiceOfNightmaresCard); };

class CCourageousOutriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCourageousOutriderCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_HumanFilter;
};

class CDawnGryffCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CDawnGryffCard); };
class CDesperateSentryCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDesperateSentryCard); };

class CDrogskolShieldmateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDrogskolShieldmateCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CExtricatorOfSinCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CExtricatorOfSinCard);

protected:
	bool BeforeToken(CAbilityAction* pAction) const;
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);

	CCardFilter m_OtherPermanentFilter;
	CCardFilter m_NonEldraziFilter;
};

class CExtricatorOfFleshCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CExtricatorOfFleshCard); };
class CFaithbearerPaladinCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFaithbearerPaladinCard); };
class CFiendBinderCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFiendBinderCard); };
class CGeistOfTheLonelyVigilCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CGeistOfTheLonelyVigilCard); };

class CGiselaTheBrokenBladeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGiselaTheBrokenBladeCard);

protected:
	bool SetMeldContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeMeld(CAbilityAction* pAction);
};

class CGuardianOfPilgrimsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGuardianOfPilgrimsCard); };
class CIroncladSlayerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CIroncladSlayerCard); };

class CLoneRiderCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CLoneRiderCard);

protected:
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
};

class CItThatRidesAsOneCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CItThatRidesAsOneCard); };

class CSanctifierOfSoulsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSanctifierOfSoulsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSelflessSpiritCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSelflessSpiritCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSigardianPriestCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSigardianPriestCard); };

class CSteadfastCatharCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteadfastCatharCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSubjugatorAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSubjugatorAngelCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CThaliaHereticCatharCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThaliaHereticCatharCard);

protected:
	CCardFilter m_EnterTappedFilter;
};

class CThaliasLancersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThaliasLancersCard);

protected:
	CCardFilter m_LegendaryFilter;
};

class CThrabenStandardBearerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CThrabenStandardBearerCard); };

//____________________________________________________________________________
//
// Green creatures

class CBackwoodsSurvivalistsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBackwoodsSurvivalistsCard); };

class CBloodbriarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodbriarCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolution(CAbilityAction* pAction);
};

class CCrossroadsConsecratorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCrossroadsConsecratorCard); };

class CEmrakulsEvangelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmrakulsEvangelCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_OtherNonEldraziFilter;
};

class CFoulEmissaryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFoulEmissaryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_CreatureFilter;
};

class CGnarlwoodDryadCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGnarlwoodDryadCard); };

class CIshkanahGrafwidowCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIshkanahGrafwidowCard);

protected:
	bool BeforeSpiders(CAbilityAction* pAction) const;
	bool BeforeLifeLoss(CAbilityAction* pAction) const;
};

class CKessigProwlerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CKessigProwlerCard);

protected:
	bool BeforeTransform(CAbilityAction* pAction);
};

class CSinuousPredatorCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CSinuousPredatorCard); };
class CNooseConstrictorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CNooseConstrictorCard); };
class CPrimalDruidCard : public CCreatureCard { DECLARE_CARD_CSTOR(CPrimalDruidCard); };
class CSomberwaldStagCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSomberwaldStagCard); };

class CSpiritOfTheHuntCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpiritOfTheHuntCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSwiftSpinnerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSwiftSpinnerCard); };

class CTangleclawWerewolfCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CTangleclawWerewolfCard);

protected:
	bool BeforeTransform(CAbilityAction* pAction);
};

class CFibrousEntanglerCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CFibrousEntanglerCard); };

class CUlvenwaldCaptiveCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CUlvenwaldCaptiveCard);

protected:
	bool BeforeTransform(CAbilityAction* pAction);
};

class CUlvenwaldAbominationCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CUlvenwaldAbominationCard); };
class CUlvenwaldObserverCard : public CCreatureCard { DECLARE_CARD_CSTOR(CUlvenwaldObserverCard); };
class CWoodlandPatrolCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWoodlandPatrolCard); };

//____________________________________________________________________________
//
// Red creatures

class CAssembledAlphasCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAssembledAlphasCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback2,
						   &CWhenSelfAttackedBlocked::SetBlockingOrBlockedEachTimeEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						   CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CBedlamRevelerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBedlamRevelerCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CCardFilter m_CardFilter;
};

class CBoldImpalerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBoldImpalerCard); };
class CBrazenWolvesCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBrazenWolvesCard); };

class CConduitOfStormsCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CConduitOfStormsCard);

protected:
	bool SetFrontContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const;
	bool SetBackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const;
	bool BeforeRed(CAbilityAction* pAction) const;
	bool BeforeColorless(CAbilityAction* pAction) const;
	bool BeforeTransform(CAbilityAction* pAction);
};

class CConduitOfEmrakulCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CConduitOfEmrakulCard); };
class CDerangedWhelpCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDerangedWhelpCard); };
class CFalkenrathReaverCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFalkenrathReaverCard); };
class CFurybladeVampireCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFurybladeVampireCard); };

class CImpetuousDevilsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImpetuousDevilsCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
};

class CInsatiableGorgersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInsatiableGorgersCard);

protected:
	CMadnessSupport m_Madness;
};

class CSmolderingWerewolfCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CSmolderingWerewolfCard);

protected:
	bool SetBackContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, AttackSubject subject) const;
	bool BeforeTransform(CAbilityAction* pAction);
};

class CEruptingDreadwolfCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CEruptingDreadwolfCard); };
class CStensiaInnkeeperCard : public CCreatureCard { DECLARE_CARD_CSTOR(CStensiaInnkeeperCard); };

class CThermoAlchemistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThermoAlchemistCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CVildinPackOutcastCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CVildinPackOutcastCard);

protected:
	bool BeforeTransform(CAbilityAction* pAction);
};

class CDronepackKindredCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CDronepackKindredCard); };
class CWeaverOfLightningCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWeaverOfLightningCard); };

//____________________________________________________________________________
//
// Black creatures

class CCryptbreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCryptbreakerCard);

protected:
	CCardFilter m_ZombieFilter;
};

class CDuskFeasterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDuskFeasterCard);

protected:
	BOOL CanCastWithDelirium(BOOL bIncludeTricks);
};

class CGavonyUnhallowedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGavonyUnhallowedCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

// Meld pair of Midnight Scavengers: Graf Rats is the host card (see CMeldCreatureCard)
class CGrafRatsCard : public CMeldCreatureCard
{
	DECLARE_CARD_CSTOR(CGrafRatsCard);

protected:
	bool SetMeldContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeMeld(CAbilityAction* pAction);
	bool SetHostContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeHost(CAbilityAction* pAction) const;
};

class CChitteringHostCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CChitteringHostCard); };

class CHauntedDeadCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHauntedDeadCard); };
class CLilianasEliteCard : public CCreatureCard { DECLARE_CARD_CSTOR(CLilianasEliteCard); };
class CMarkovCrusaderCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMarkovCrusaderCard); };
class CMidnightScavengersCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMidnightScavengersCard); };

class CNoosegrafMobCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNoosegrafMobCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	bool BeforeResolution(CAbilityAction* pAction);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class COliviasDragoonCard : public CCreatureCard { DECLARE_CARD_CSTOR(COliviasDragoonCard); };

class CSkirsdagSupplicantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkirsdagSupplicantCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CStromkirkCondemnedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStromkirkCondemnedCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CThrabenFoulbloodsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CThrabenFoulbloodsCard); };
class CVampireCutthroatCard : public CCreatureCard { DECLARE_CARD_CSTOR(CVampireCutthroatCard); };

class CVoldarenPariahCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CVoldarenPariahCard);

protected:
	bool BeforeTransform(CAbilityAction* pAction);
	bool SetTransformContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, int nIndex) const;
	bool BeforeSacrifice(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CMadnessSupport m_Madness;
	CCardFilter m_OtherCreatureFilter;
	CSelectionSupport m_CardSelection;
};

class CAbolisherOfBloodlinesCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CAbolisherOfBloodlinesCard); };

class CWailingGhoulCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWailingGhoulCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CWeirdedVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWeirdedVampireCard);

protected:
	CMadnessSupport m_Madness;
};

//____________________________________________________________________________
//
// Blue creatures

class CAdvancedStitchwingCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CAdvancedStitchwingCard); };

class CDocentOfPerfectionCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CDocentOfPerfectionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CFinalIterationCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CFinalIterationCard); };
class CEnlightenedManiacCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEnlightenedManiacCard); };
class CExultantCultistCard : public CCreatureCard { DECLARE_CARD_CSTOR(CExultantCultistCard); };
class CFogwalkerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFogwalkerCard); };

class CGeistOfTheArchivesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGeistOfTheArchivesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CGrizzledAnglerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CGrizzledAnglerCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
	bool BeforeAttack(CAbilityAction* pAction) const;
};

class CGrislyAnglerfishCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CGrislyAnglerfishCard); };
class CIngeniousSkaabCard : public CCreatureCard { DECLARE_CARD_CSTOR(CIngeniousSkaabCard); };

class CLaboratoryBruteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLaboratoryBruteCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMausoleumWandererCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMausoleumWandererCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	BOOL CanActivate(BOOL bIncludeTricks);

	CCounterSpell* m_pCounterAbility;
};

class CNebelgastHeraldCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CNebelgastHeraldCard); };
class CNiblisOfFrostCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CNiblisOfFrostCard); };

class CWharfInfiltratorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWharfInfiltratorCard);

protected:
	bool SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeToken(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Werewolves (as in Shadows over Innistrad): the day and night transform abilities
class CWerewolfSupport
{
public:
	CWerewolfSupport(CDoubleFacedCreatureCard* pCard);
	void AddTransformAbilities();

protected:
	bool SetDayContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool SetNightContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	CDoubleFacedCreatureCard* m_pCard;
};

//____________________________________________________________________________
//
// Multicolored creatures

class CBloodhallPriestCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodhallPriestCard);

protected:
	bool SetEnterContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetAttackContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, AttackSubject subject) const;

	CMadnessSupport m_Madness;
};

class CGrimFlayerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrimFlayerCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CHeronsGraceChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeronsGraceChampionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMercurialGeistsCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CMercurialGeistsCard); };

class CMournwillowCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMournwillowCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CUlrichOfTheKrallenhordeCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CUlrichOfTheKrallenhordeCard);

protected:
	bool SetEnterContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						 CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetFrontContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CCard* pCard, int nIndex) const;
	bool SetBackContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CCard* pCard, int nIndex) const;

	CWerewolfSupport m_Werewolf;
};

class CUlrichUncontestedAlphaCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CUlrichUncontestedAlphaCard); };

//____________________________________________________________________________
//
// Emerge (Eldritch Moon): "You may cast this spell by sacrificing a creature and paying the emerge cost reduced by
// that creature's mana value." One alternative spell for each reduction of the generic part of the emerge cost: the
// spell for the reduction i requires sacrificing a creature with mana value i (the last one, a creature with mana
// value i or greater). Only the spells whose sacrifice can be paid are playable. The spell's mana value is the
// printed one.
class CEmergeSupport
{
public:
	CEmergeSupport(CCard* pCard);
	~CEmergeSupport();

	void AddEmergeSpells(int nGeneric, LPCTSTR strColored);

protected:
	CCard* m_pCard;
	std::vector<CCardFilter*> m_Filters;
	std::list<CString> m_Texts;		// the cost and ability texts of the spells (kept alive with the card)
};

//____________________________________________________________________________
//
// Colorless creatures

class CAbundantMawCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAbundantMawCard);

protected:
	CEmergeSupport m_Emerge;
};

class CDecimatorOfTheProvincesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDecimatorOfTheProvincesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	CEmergeSupport m_Emerge;
};

class CDistendedMindbenderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDistendedMindbenderCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CEmergeSupport m_Emerge;
	CSelectionSupport m_CardSelection;
};

class CDrownyardBehemothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDrownyardBehemothCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	CEmergeSupport m_Emerge;
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class CElderDeepFiendCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElderDeepFiendCard);

protected:
	CEmergeSupport m_Emerge;
};

class CEternalScourgeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEternalScourgeCard);

protected:
	bool SetTargetedContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pByPlayer) const;
};

class CFieldCreeperCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFieldCreeperCard); };
class CGeistFueledScarecrowCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGeistFueledScarecrowCard); };

class CItOfTheHorridSwarmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CItOfTheHorridSwarmCard);

protected:
	CEmergeSupport m_Emerge;
};

class CLashweedLurkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLashweedLurkerCard);

protected:
	CEmergeSupport m_Emerge;
};

class CMockeryOfNatureCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMockeryOfNatureCard);

protected:
	CEmergeSupport m_Emerge;
};

class CVexingScuttlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVexingScuttlerCard);

protected:
	CEmergeSupport m_Emerge;
};

class CWretchedGryffCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWretchedGryffCard);

protected:
	CEmergeSupport m_Emerge;
};

//____________________________________________________________________________
//
// Artifacts

class CCatharsShieldCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CCatharsShieldCard); };
class CCultistsStaffCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CCultistsStaffCard); };
class CSlayersCleaverCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CSlayersCleaverCard); };

class CStitchersGraftCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CStitchersGraftCard);

protected:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
	bool BeforeNoUntap(CAbilityAction* pAction) const;
	bool SetUnattachContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext,
							CCard* pEquipCard, CCard* pFromCard, CCard* pToCard) const;
};

class CTerrarionCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CTerrarionCard); };

class CThirstingAxeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CThirstingAxeCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						  CCard* pFromCard, CCreatureCard* pToCreature, Damage damage);
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCard* m_pDamageCreature;	// the equipped creature that dealt combat damage to a creature
	int_ m_nDamageTurn;			// and the game turn
};

//____________________________________________________________________________
//
