#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
class CDevilthornFoxCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDevilthornFoxCard);
};

//___________________________________________________________________________
//
class CHulkingDevilCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHulkingDevilCard);
};

//____________________________________________________________________________
//
class CNiblisOfDuskCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNiblisOfDuskCard);
};

//____________________________________________________________________________
//
class CSeagrafSkaabCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSeagrafSkaabCard);
};

//____________________________________________________________________________
//
class CThornhideWolvesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThornhideWolvesCard);
};

//____________________________________________________________________________
//
class CVampireNobleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireNobleCard);
};

//____________________________________________________________________________
//
class CWarpedLandscapeCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CWarpedLandscapeCard);
};

//____________________________________________________________________________
//
class CSilentObserverCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSilentObserverCard);
};

//____________________________________________________________________________
//
class CSanguinaryMageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSanguinaryMageCard);
};

//____________________________________________________________________________
//
class CChokedEstuaryCard : public CNonbasicLandCard 
{
	DECLARE_CARD_CSTOR(CChokedEstuaryCard);

protected:
	CCardFilter m_CardFilter;
private:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CForebodingRuinsCard : public CNonbasicLandCard 
{
	DECLARE_CARD_CSTOR(CForebodingRuinsCard);

protected:
	CCardFilter m_CardFilter;
private:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CFortifiedVillageCard : public CNonbasicLandCard 
{
	DECLARE_CARD_CSTOR(CFortifiedVillageCard);

protected:
	CCardFilter m_CardFilter;
private:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CGameTrailCard : public CNonbasicLandCard 
{
	DECLARE_CARD_CSTOR(CGameTrailCard);

protected:
	CCardFilter m_CardFilter;
private:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CPortTownCard : public CNonbasicLandCard 
{
	DECLARE_CARD_CSTOR(CPortTownCard);

protected:
	CCardFilter m_CardFilter;
private:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CDrownyardTempleCard : public CNonbasicLandCard 
{
	DECLARE_CARD_CSTOR(CDrownyardTempleCard);
};

//____________________________________________________________________________
//
class CHighlandLakeCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CHighlandLakeCard);
};

//____________________________________________________________________________
//
class CWoodlandStreamCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CWoodlandStreamCard);
};

//____________________________________________________________________________
//
class CFoulOrchardCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CFoulOrchardCard);
};

//____________________________________________________________________________
//
class CForsakenSanctuaryCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CForsakenSanctuaryCard);
};

//____________________________________________________________________________
//
class CStoneQuarryCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CStoneQuarryCard);
};

//____________________________________________________________________________
//
// Planeswalkers
class CArlinnKordCard : public CDoubleFacedPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CArlinnKordCard);

protected:
	bool BeforeResolutionPump(CAbilityAction* pAction) const;
};

// Back face of Arlinn Kord (as Garruk, the Veil-Cursed): its abilities are in CArlinnKordCard
class CArlinnEmbracedByTheMoonCard : public CPlaneswalkerCard { DECLARE_CARD_CSTOR(CArlinnEmbracedByTheMoonCard); };

class CJaceUnravelerOfSecretsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJaceUnravelerOfSecretsCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction) const;
};

class CNahiriTheHarbingerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNahiriTheHarbingerCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction);
	bool BeforeResolution3(CAbilityAction* pAction);
	void OnDiscardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnSearchSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_DiscardSelection;
	CSelectionSupport m_SearchSelection;
};

class CSorinGrimNemesisCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSorinGrimNemesisCard);

protected:
	bool BeforeResolution1(CAbilityAction* pAction) const;
	bool BeforeResolutionX(CAbilityAction* pAction) const;
	bool BeforeResolution3(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Artifacts
class CEpitaphGolemCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEpitaphGolemCard); };
class CExplosiveApparatusCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CExplosiveApparatusCard); };
class CHauntedCloakCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CHauntedCloakCard); };
class CMagnifyingGlassCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CMagnifyingGlassCard); };
class CMurderersAxeCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CMurderersAxeCard); };
class CWickerWitchCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWickerWitchCard); };
class CWildFieldScarecrowCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWildFieldScarecrowCard); };
class CThrabenGargoyleCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CThrabenGargoyleCard); };
class CStonewingAntagonizerCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CStonewingAntagonizerCard); };

class CCorruptedGrafstoneCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCorruptedGrafstoneCard);

protected:
	BOOL HasColorInGraveyard(CardType color) const;
	BOOL CanAddWhite(BOOL bIncludeTricks);
	BOOL CanAddBlue(BOOL bIncludeTricks);
	BOOL CanAddBlack(BOOL bIncludeTricks);
	BOOL CanAddRed(BOOL bIncludeTricks);
	BOOL CanAddGreen(BOOL bIncludeTricks);
};

class CRunawayCarriageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRunawayCarriageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CShardOfBrokenGlassCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CShardOfBrokenGlassCard);

protected:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
	bool BeforeMill(CAbilityAction* pAction) const;
};

class CSkeletonKeyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSkeletonKeyCard);

protected:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
};

class CSlayersPlateCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSlayersPlateCard);

protected:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
};

class CTamiyosJournalCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTamiyosJournalCard);

protected:
	CCardFilter m_ClueFilter;
};

//____________________________________________________________________________
//
// Madness (as Fiery Temper): the card adds its normal spell and a madness spell, then calls SetMadnessSpell().
// The madness spell can be cast only from exile, after the card is discarded (the madness trigger gives it Freecast).
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
class CChaplainsBlessingCard : public CCard { DECLARE_CARD_CSTOR(CChaplainsBlessingCard); };
class CDevilsPlaygroundCard : public CCard { DECLARE_CARD_CSTOR(CDevilsPlaygroundCard); };
class CGoneMissingCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CGoneMissingCard); };
class CPressForAnswersCard : public CCard { DECLARE_CARD_CSTOR(CPressForAnswersCard); };
class CReduceToAshesCard : public CCard { DECLARE_CARD_CSTOR(CReduceToAshesCard); };
class CRootOutCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CRootOutCard); };
class CShambleBackCard : public CCard { DECLARE_CARD_CSTOR(CShambleBackCard); };
class CBurnFromWithinCard : public CCard { DECLARE_CARD_CSTOR(CBurnFromWithinCard); };

class CAlmsOfTheVeinCard : public CCard
{
	DECLARE_CARD_CSTOR(CAlmsOfTheVeinCard);

protected:
	CMadnessSupport m_Madness;
};

class CAngelicPurgeCard : public CTargetMoveCardSpellCard
{
	DECLARE_CARD_CSTOR(CAngelicPurgeCard);

protected:
	CCardFilter m_PermanentFilter;
};

class CBeholdTheBeyondCard : public CCard
{
	DECLARE_CARD_CSTOR(CBeholdTheBeyondCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CBitingRainCard : public CCard
{
	DECLARE_CARD_CSTOR(CBitingRainCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	CMadnessSupport m_Madness;
};

class CDeclarationInStoneCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeclarationInStoneCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDescendUponTheSinfulCard : public CCard
{
	DECLARE_CARD_CSTOR(CDescendUponTheSinfulCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CEtherealGuidanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CEtherealGuidanceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CForkInTheRoadCard : public CCard
{
	DECLARE_CARD_CSTOR(CForkInTheRoadCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void RequestLand(CPlayer* pPlayer, CSelectionSupport& selection, LPCTSTR strFormat);
	void OnHandSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnGraveyardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_HandSelection;
	CSelectionSupport m_GraveyardSelection;
};

class CFromUnderTheFloorboardsCard : public CCard
{
	DECLARE_CARD_CSTOR(CFromUnderTheFloorboardsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	bool BeforeMadnessResolution(CAbilityAction* pAction) const;
	CMadnessSupport m_Madness;
};

class CGisasBiddingCard : public CCard
{
	DECLARE_CARD_CSTOR(CGisasBiddingCard);

protected:
	CMadnessSupport m_Madness;
};

class CLilianasIndignationCard : public CCard
{
	DECLARE_CARD_CSTOR(CLilianasIndignationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMalevolentWhispersCard : public CCard
{
	DECLARE_CARD_CSTOR(CMalevolentWhispersCard);

protected:
	CMadnessSupport m_Madness;
};

class CMurderousCompulsionCard : public CCard
{
	DECLARE_CARD_CSTOR(CMurderousCompulsionCard);

protected:
	CMadnessSupport m_Madness;
};

class CNaggingThoughtsCard : public CCard
{
	DECLARE_CARD_CSTOR(CNaggingThoughtsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
	CMadnessSupport m_Madness;
};

class CNotForgottenCard : public CCard
{
	DECLARE_CARD_CSTOR(CNotForgottenCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_PlaceSelection;
};

class COpenTheArmoryCard : public CCard
{
	DECLARE_CARD_CSTOR(COpenTheArmoryCard);

protected:
	CCardFilter m_Filter;
};

class CPickTheBrainCard : public CCard
{
	DECLARE_CARD_CSTOR(CPickTheBrainCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
	BOOL_ m_bDelirium;
};

class CPiecesOfThePuzzleCard : public CCard
{
	DECLARE_CARD_CSTOR(CPiecesOfThePuzzleCard);

protected:
	CCardFilter m_Filter;
};

class CPoreOverThePagesCard : public CCard
{
	DECLARE_CARD_CSTOR(CPoreOverThePagesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnLandsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_LandSelection;
};

class CRabidBiteCard : public CCard
{
	DECLARE_CARD_CSTOR(CRabidBiteCard);

protected:
	class CRabidBiteSpell : public CDoubleTargetSpell
	{
	DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		CRabidBiteSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost);
		virtual ~CRabidBiteSpell() {}

		OVERRIDE(void, ResolveGroup)(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2, const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2);
	};
};

class CRiseFromTheTidesCard : public CCard
{
	DECLARE_CARD_CSTOR(CRiseFromTheTidesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CStructuralDistortionCard : public CCard
{
	DECLARE_CARD_CSTOR(CStructuralDistortionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CTraverseTheUlvenwaldCard : public CCard
{
	DECLARE_CARD_CSTOR(CTraverseTheUlvenwaldCard);

protected:
	BOOL CanCastNormal(BOOL bIncludeTricks);
	BOOL CanCastDelirium(BOOL bIncludeTricks);
	CCardFilter m_CreatureOrLandFilter;
};

class CWelcomeToTheFoldCard : public CCard
{
	DECLARE_CARD_CSTOR(CWelcomeToTheFoldCard);

protected:
	bool BeforeMadnessResolution(CAbilityAction* pAction) const;
	CMadnessSupport m_Madness;
};

//____________________________________________________________________________
//
// Instants
class CAimHighCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CAimHighCard); };
class CAnguishedUnmakingCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CAnguishedUnmakingCard); };
class CConfirmSuspicionsCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CConfirmSuspicionsCard); };
class CDanceWithDevilsCard : public CCard { DECLARE_CARD_CSTOR(CDanceWithDevilsCard); };
class CDenyExistenceCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CDenyExistenceCard); };
class CDualShotCard : public CCard { DECLARE_CARD_CSTOR(CDualShotCard); };
class CExposeEvilCard : public CCard { DECLARE_CARD_CSTOR(CExposeEvilCard); };
class CGrotesqueMutationCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CGrotesqueMutationCard); };
class CHumbleTheBruteCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CHumbleTheBruteCard); };
class CInvasiveSurgeryCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CInvasiveSurgeryCard); };
class CJacesScrutinyCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CJacesScrutinyCard); };
class CRushOfAdrenalineCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CRushOfAdrenalineCard); };
class CSilverstrikeCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CSilverstrikeCard); };
class CSurviveTheNightCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CSurviveTheNightCard); };
class CUncagedFuryCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CUncagedFuryCard); };

class CBrokenConcentrationCard : public CCard
{
	DECLARE_CARD_CSTOR(CBrokenConcentrationCard);

protected:
	CMadnessSupport m_Madness;
};

class CJustTheWindCard : public CCard
{
	DECLARE_CARD_CSTOR(CJustTheWindCard);

protected:
	CMadnessSupport m_Madness;
};

class CClipWingsCard : public CCard
{
	DECLARE_CARD_CSTOR(CClipWingsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

class CCompellingDeterrenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CCompellingDeterrenceCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
	CSelectionSupport m_CardSelection;
};

class CConfrontTheUnknownCard : public CCard
{
	DECLARE_CARD_CSTOR(CConfrontTheUnknownCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDissensionInTheRanksCard : public CCard
{
	DECLARE_CARD_CSTOR(CDissensionInTheRanksCard);

protected:
	class CDissensionInTheRanksSpell : public CDoubleTargetSpell
	{
	DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		CDissensionInTheRanksSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost);
		virtual ~CDissensionInTheRanksSpell() {}

		OVERRIDE(void, ResolveGroup)(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2, const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2);
	};
};

class CEngulfTheShoreCard : public CCard
{
	DECLARE_CARD_CSTOR(CEngulfTheShoreCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CEssenceFluxCard : public CCard
{
	DECLARE_CARD_CSTOR(CEssenceFluxCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CInnerStruggleCard : public CCard
{
	DECLARE_CARD_CSTOR(CInnerStruggleCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMercilessResolveCard : public CCard
{
	DECLARE_CARD_CSTOR(CMercilessResolveCard);

protected:
	CCardFilter m_SacrificeFilter;
};

class CMightBeyondReasonCard : public CCard
{
	DECLARE_CARD_CSTOR(CMightBeyondReasonCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CMoonlightHuntCard : public CCard
{
	DECLARE_CARD_CSTOR(CMoonlightHuntCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CStrengthOfArmsCard : public CChgPwrTghAttrSpellCard
{
	DECLARE_CARD_CSTOR(CStrengthOfArmsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CTenacityCard : public CCard
{
	DECLARE_CARD_CSTOR(CTenacityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CToTheSlaughterCard : public CCard
{
	DECLARE_CARD_CSTOR(CToTheSlaughterCard);

protected:
	BOOL CanCastNormal(BOOL bIncludeTricks);
	BOOL CanCastDelirium(BOOL bIncludeTricks);
	bool BeforeDeliriumResolution(CAbilityAction* pAction);
	void OnPlaneswalkerSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CCardFilter m_CreatureOrPlaneswalkerFilter;
	CSelectionSupport m_PlaneswalkerSelection;
};

//____________________________________________________________________________
//
// Enchantments
class CBoundByMoonsilverCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CBoundByMoonsilverCard); };
class CGryffsBoonCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CGryffsBoonCard); };
class CSpitefulMotivesCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CSpitefulMotivesCard); };
class CAlwaysWatchingCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CAlwaysWatchingCard); };
class CCallTheBloodlineCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CCallTheBloodlineCard); };
class CHowlpackResurgenceCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CHowlpackResurgenceCard); };
class CNahirisMachinationsCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CNahirisMachinationsCard); };
class CTrailOfEvidenceCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CTrailOfEvidenceCard); };
class CVesselOfEphemeraCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CVesselOfEphemeraCard); };
class CVesselOfMalignityCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CVesselOfMalignityCard); };
class CVesselOfVolatilityCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CVesselOfVolatilityCard); };

class CBehindTheScenesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBehindTheScenesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CCrawlingSensationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCrawlingSensationCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;
	bool SetLandContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	int_ m_nLastTurn;
};

class CCryptolithRiteCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCryptolithRiteCard);

protected:
	counted_ptr<CAbility> CreateManaAbility(CCard* pCard, LPCTSTR strMana);
	counted_ptr<CAbility> CreateWhite(CCard* pCard);
	counted_ptr<CAbility> CreateBlue(CCard* pCard);
	counted_ptr<CAbility> CreateBlack(CCard* pCard);
	counted_ptr<CAbility> CreateRed(CCard* pCard);
	counted_ptr<CAbility> CreateGreen(CCard* pCard);
};

class CEquestrianSkillCard : public CCard
{
	DECLARE_CARD_CSTOR(CEquestrianSkillCard);

protected:
	class CEquestrianSkillEnchant : public CChgPwrTghAttrEnchant
	{
	DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		CEquestrianSkillEnchant(CCard* pCard, LPCTSTR strManaCost);
		virtual ~CEquestrianSkillEnchant() {}

		OVERRIDE(BOOL, OnEnchant)(CCard* pCard, ContextValue_& contextValue);
	};
};

class CFeveredVisionsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFeveredVisionsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CFleetingMemoriesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFleetingMemoriesCard);

protected:
	bool SetClueContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeMill(CAbilityAction* pAction) const;
};

class COngoingInvestigationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COngoingInvestigationCard);

protected:
	bool SetDamageContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
						  CCard* pFromCard, CPlayer* pToPlayer, Damage damage);
	int_ m_nLastTurn;
	CCardFilter m_CreatureFilter;
};

class CSenselessRageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSenselessRageCard);

protected:
	CMadnessSupport m_Madness;
};

class CSinisterConcoctionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSinisterConcoctionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CSleepParalysisCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSleepParalysisCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CStensiaMasqueradeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CStensiaMasqueradeCard);

protected:
	bool SetDamageContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						  CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	CMadnessSupport m_Madness;
};

class CUlvenwaldMysteriesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CUlvenwaldMysteriesCard);

protected:
	bool SetClueContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CVesselOfNascencyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CVesselOfNascencyCard);

protected:
	CCardFilter m_Filter;
};

class CVesselOfParamnesiaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CVesselOfParamnesiaCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// White creatures
class CBygoneBishopCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CBygoneBishopCard); };
class CCatharsCompanionCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCatharsCompanionCard); };
class CDauntlessCatharCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDauntlessCatharCard); };
class CInquisitorsOxCard : public CCreatureCard { DECLARE_CARD_CSTOR(CInquisitorsOxCard); };
class CMilitantInquisitorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMilitantInquisitorCard); };
class CMoorlandDrifterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMoorlandDrifterCard); };
class CNearheathChaplainCard : public CCreatureCard { DECLARE_CARD_CSTOR(CNearheathChaplainCard); };
class CParanoidParishBladeCard : public CCreatureCard { DECLARE_CARD_CSTOR(CParanoidParishBladeCard); };
class CSpectralShepherdCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSpectralShepherdCard); };
class CSternConstableCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSternConstableCard); };
class CThrabenInspectorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CThrabenInspectorCard); };
class CAvacynThePurifierCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CAvacynThePurifierCard); };
class CWaywardDiscipleCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CWaywardDiscipleCard); };
class CTownGossipmongerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CTownGossipmongerCard);

protected:
	CCardFilter m_TapFilter;
};

class CIncitedRabbleCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CIncitedRabbleCard); };

class CAngelOfDeliveranceCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfDeliveranceCard);

protected:
	bool SetTriggerContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext, Damage damage) const;
};

class CApothecaryGeistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CApothecaryGeistCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CArchangelAvacynCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CArchangelAvacynCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction) const;
	bool OnCreatureDied(CTriggeredAbility<>::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
	BOOL_ m_bTransformPending;
};

class CDrogskolCavalryCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDrogskolCavalryCard);
};

class CEmissaryOfTheSleeplessCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEmissaryOfTheSleeplessCard);

protected:
	bool SetTriggerContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CInspiringCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInspiringCaptainCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CPiousEvangelCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CPiousEvangelCard);

protected:
	bool SetFrontContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						 CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetBackContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);
	CCardFilter m_SacrificeFilter;
	BOOL_ m_bLeftAsSecondFace;	// the face it had when it left the battlefield (the card is reset to its first face)
};

class CReaperOfFlightMoonsilverCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CReaperOfFlightMoonsilverCard);

protected:
	BOOL CanActivate(BOOL bIncludeTricks);
	CCardFilter m_SacrificeFilter;
};

class CThaliasLieutenantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThaliasLieutenantCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	bool SetHumanContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						 CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CTopplegeistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTopplegeistCard);

protected:
	bool SetUpkeepContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

//____________________________________________________________________________
//
// Werewolves (as Daybreak Ranger // Nightfall Predator in Innistrad):
// "At the beginning of each upkeep, if no spells were cast last turn, transform this creature." (first face)
// "At the beginning of each upkeep, if a player cast two or more spells last turn, transform this creature." (second face)
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
// Green creatures
class CBywayCourierCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBywayCourierCard); };
class CDeathcapCultivatorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDeathcapCultivatorCard); };
class CIntrepidProvisionerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CIntrepidProvisionerCard); };
class CKessigDireSwineCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKessigDireSwineCard); };
class CMoldgrafScavengerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMoldgrafScavengerCard); };
class CQuilledWolfCard : public CCreatureCard { DECLARE_CARD_CSTOR(CQuilledWolfCard); };
class CStoicBuilderCard : public CCreatureCard { DECLARE_CARD_CSTOR(CStoicBuilderCard); };
class CUlvenwaldHydraCard : public CCreatureCard { DECLARE_CARD_CSTOR(CUlvenwaldHydraCard); };
class CVeteranCatharCard : public CCreatureCard { DECLARE_CARD_CSTOR(CVeteranCatharCard); };
class CWatcherInTheWebCard : public CCreatureCard { DECLARE_CARD_CSTOR(CWatcherInTheWebCard); };
class CKrallenhordeHowlerCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CKrallenhordeHowlerCard); };
class CLoneWolfOfTheNatterknollsCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CLoneWolfOfTheNatterknollsCard); };
class CTimberShredderCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CTimberShredderCard); };
class COneOfThePackCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(COneOfThePackCard); };

class CBriarbridgePatrolCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBriarbridgePatrolCard);
};

class CCultOfTheWaxingMoonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCultOfTheWaxingMoonCard);

protected:
	bool SetTriggerContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext, CCard* pCard, int nId) const;
};

class CDuskwatchRecruiterCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CDuskwatchRecruiterCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
	CCardFilter m_CreatureFilter;
	CWerewolfSupport m_Werewolf;
};

class CGrafMoleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrafMoleCard);

protected:
	bool SetClueContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CHermitOfTheNatterknollsCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CHermitOfTheNatterknollsCard);

protected:
	bool SetFrontContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CCard* pCard) const;
	bool SetBackContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CCard* pCard) const;
	CWerewolfSupport m_Werewolf;
};

class CHinterlandLoggerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CHinterlandLoggerCard);

protected:
	CWerewolfSupport m_Werewolf;
};

class CInexorableBlobCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInexorableBlobCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, AttackSubject subject) const;
};

class CLoamDryadCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoamDryadCard);

protected:
	CCardFilter m_TapFilter;
};

class CObsessiveSkinnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CObsessiveSkinnerCard);

protected:
	bool SetUpkeepContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CPackGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPackGuardianCard);

protected:
	CCardFilter m_LandFilter;
};

class CSolitaryHunterCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CSolitaryHunterCard);

protected:
	CWerewolfSupport m_Werewolf;
};

class CSoulSwallowerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSoulSwallowerCard);

protected:
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CTirelessTrackerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTirelessTrackerCard);

protected:
	bool SetClueContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
// Red creatures
class CEmberEyeWolfCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEmberEyeWolfCard); };
class CHowlpackWolfCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHowlpackWolfCard); };
class CInsolentNeonateCard : public CCreatureCard { DECLARE_CARD_CSTOR(CInsolentNeonateCard); };
class CRavenousBloodseekerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRavenousBloodseekerCard); };
class CScourgeWolfCard : public CCreatureCard { DECLARE_CARD_CSTOR(CScourgeWolfCard); };
class CUlrichsKindredCard : public CCreatureCard { DECLARE_CARD_CSTOR(CUlrichsKindredCard); };
class CVoldarenDuelistCard : public CCreatureCard { DECLARE_CARD_CSTOR(CVoldarenDuelistCard); };
class CNeckBreakerCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CNeckBreakerCard); };
class CBrandedHowlerCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CBrandedHowlerCard); };
class CGatstafRavagersCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CGatstafRavagersCard); };
class CVildinPackAlphaCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CVildinPackAlphaCard); };
class CFlameheartWerewolfCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CFlameheartWerewolfCard); };
class CMoonriseIntruderCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CMoonriseIntruderCard); };

class CBloodmadVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodmadVampireCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	CMadnessSupport m_Madness;
};

class CBreakneckRiderCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CBreakneckRiderCard);

protected:
	CWerewolfSupport m_Werewolf;
};

class CConvictedKillerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CConvictedKillerCard);

protected:
	CWerewolfSupport m_Werewolf;
};

class CFlamebladeAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFlamebladeAngelCard);

protected:
	bool SetCreatureContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
							CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
};

class CGatstafArsonistsCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CGatstafArsonistsCard);

protected:
	CWerewolfSupport m_Werewolf;
};

class CGeierReachBanditCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CGeierReachBanditCard);

protected:
	bool SetWerewolfContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
							CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	CWerewolfSupport m_Werewolf;
};

class CGibberingFiendCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGibberingFiendCard);

protected:
	bool SetUpkeepContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CIncorrigibleYouthsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIncorrigibleYouthsCard);

protected:
	CMadnessSupport m_Madness;
};

class CKessigForgemasterCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CKessigForgemasterCard);

protected:
	bool SetFrontContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						 CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const;
	bool SetBackContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const;
	CWerewolfSupport m_Werewolf;
};

class CPyreHoundCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPyreHoundCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext, CCard* pCard) const;
};

class CVillageMessengerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CVillageMessengerCard);

protected:
	CWerewolfSupport m_Werewolf;
};

//____________________________________________________________________________
//
// Black creatures
class CFarbogRevenantCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFarbogRevenantCard); };
class CGhoulcallersAccompliceCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGhoulcallersAccompliceCard); };
class CGhoulsteedCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGhoulsteedCard); };
class CHoundOfTheFarbogsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHoundOfTheFarbogsCard); };
class CMarkovDreadknightCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CMarkovDreadknightCard); };
class COliviasBloodswornCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(COliviasBloodswornCard); };
class CPaleRiderOfTrostadCard : public CCreatureCard { DECLARE_CARD_CSTOR(CPaleRiderOfTrostadCard); };
class CRancidRatsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRancidRatsCard); };
class CRottenheartGhoulCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRottenheartGhoulCard); };
class CSanitariumSkeletonCard : public CCreatureCard { DECLARE_CARD_CSTOR(CSanitariumSkeletonCard); };
class CStromkirkMentorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CStromkirkMentorCard); };
class CInsidiousMistCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CInsidiousMistCard); };
class CHeirToTheNightCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CHeirToTheNightCard); };
class CDemonPossessedWitchCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CDemonPossessedWitchCard); };
class CElusiveTormentorCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CElusiveTormentorCard); };
class CHeirOfFalkenrathCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CHeirOfFalkenrathCard); };

class CAsylumVisitorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAsylumVisitorCard);

protected:
	bool SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
	CMadnessSupport m_Madness;
};

class CCrowOfDarkTidingsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCrowOfDarkTidingsCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;
};

class CDiregrafColossusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDiregrafColossusCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	bool BeforeZombie(CAbilityAction* pAction) const;
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class CIndulgentAristocratCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIndulgentAristocratCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CKindlyStrangerCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CKindlyStrangerCard);

protected:
	BOOL HasDeliriumNow(BOOL bIncludeTricks);
	bool SetTransformContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext, CCard* pCard, int nId) const;
};

class CMindwrackDemonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMindwrackDemonCard);

protected:
	bool BeforeMill(CAbilityAction* pAction) const;
	bool SetUpkeepContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CMorkrutNecropodCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMorkrutNecropodCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

class CRelentlessDeadCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRelentlessDeadCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CStallionOfAshmouthCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStallionOfAshmouthCard);

protected:
	BOOL CanActivate(BOOL bIncludeTricks);
};

class CToothCollectorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CToothCollectorCard);

protected:
	bool SetUpkeepContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CTwinsOfMaurerEstateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTwinsOfMaurerEstateCard);

protected:
	CMadnessSupport m_Madness;
};

//____________________________________________________________________________
//
// Blue creatures
class CDrownyardExplorersCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDrownyardExplorersCard); };
class CDrunauCorpseTrawlerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDrunauCorpseTrawlerCard); };
class CFurtiveHomunculusCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFurtiveHomunculusCard); };
class CGeralfsMasterpieceCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CGeralfsMasterpieceCard); };
class CNephaliaMoondrakesCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CNephaliaMoondrakesCard); };
class CRattlechainsCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CRattlechainsCard); };
class CStitchedManglerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CStitchedManglerCard); };
class CStitchwingSkaabCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CStitchwingSkaabCard); };
class CStormriderSpiritCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CStormriderSpiritCard); };
class CPerfectedFormCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CPerfectedFormCard); };
class CBearerOfOverwhelmingTruthsCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CBearerOfOverwhelmingTruthsCard); };
class CAwokenHorrorCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CAwokenHorrorCard); };
class CUnimpededTrespasserCard : public CDoubleFacedCreatureCard { DECLARE_CARD_CSTOR(CUnimpededTrespasserCard); };

class CAberrantResearcherCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CAberrantResearcherCard);

protected:
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeResolution(CAbilityAction* pAction);
};

class CDaringSleuthCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CDaringSleuthCard);

protected:
	bool SetClueContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
						CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetProwessContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CCard* pCard) const;
	bool SetDamageContext(CTriggeredCreateTokenAbility::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
};

class CForgottenCreationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CForgottenCreationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CLamplighterOfSelhoffCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLamplighterOfSelhoffCard);

protected:
	bool SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CManicScribeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CManicScribeCard);

protected:
	bool BeforeEnterMill(CAbilityAction* pAction) const;
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeUpkeepMill(CAbilityAction* pAction) const;
};

class CThingInTheIceCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CThingInTheIceCard);

protected:
	bool BeforeRemoveCounter(CAbilityAction* pAction);
	bool SetTransformContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, int nId) const;
	bool BeforeBounce(CAbilityAction* pAction) const;
};

class CUninvitedGeistCard : public CDoubleFacedCreatureCard
{
	DECLARE_CARD_CSTOR(CUninvitedGeistCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
};

//____________________________________________________________________________
//
// Multicolored creatures
class CSigardaHeronsGraceCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSigardaHeronsGraceCard);
};

class COliviaMobilizedForWarCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(COliviaMobilizedForWarCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CTheGitrogMonsterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTheGitrogMonsterCard);

protected:
	bool BeforeUpkeep(CAbilityAction* pAction);
	void OnSacrificeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_SacrificeSelection;
};

//____________________________________________________________________________
//
