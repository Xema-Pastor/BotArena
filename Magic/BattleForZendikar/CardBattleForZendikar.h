#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
class CBlisterpodCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBlisterpodCard); };
class CBroodMonitorCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CBroodMonitorCard); };
class CBroodhunterWurmCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBroodhunterWurmCard); };
class CCallTheScionsCard : public CCard { DECLARE_CARD_CSTOR(CCallTheScionsCard); };
class CChasmGuideCard : public CRallyCreatureCard { DECLARE_CARD_CSTOR(CChasmGuideCard); };
class CClutchOfCurrentsCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CClutchOfCurrentsCard); };
class CCloudMantaCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CCloudMantaCard); };
class CCoastalDiscoveryCard : public CCard { DECLARE_CARD_CSTOR(CCoastalDiscoveryCard); };
class CCullingDroneCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CCullingDroneCard); };
class CBoilingEarthCard : public CCard { DECLARE_CARD_CSTOR(CBoilingEarthCard); };
class CEarthenArmsCard : public CCard { DECLARE_CARD_CSTOR(CEarthenArmsCard); };
class CEldraziSkyspawnerCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CEldraziSkyspawnerCard); };
class CEyelessWatcherCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CEyelessWatcherCard); };
class CExpeditionEnvoyCard : public CCreatureCard { DECLARE_CARD_CSTOR(CExpeditionEnvoyCard); };
class CFiremantleMageCard : public CRallyCreatureCard { DECLARE_CARD_CSTOR(CFiremantleMageCard); };
class CFortifiedRampartCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFortifiedRampartCard); };
class CGhostlySentinelCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CGhostlySentinelCard); };
class CKitesailScoutCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CKitesailScoutCard); };
class CMistIntruderCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CMistIntruderCard); };
class CPlanarOutburstCard : public CCard { DECLARE_CARD_CSTOR(CPlanarOutburstCard); };
class CRisingMiasmaCard : public CCard { DECLARE_CARD_CSTOR(CRisingMiasmaCard); };
class CRuinousPathCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CRuinousPathCard); };
class CSheerDropCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CSheerDropCard); };
class CShadowGliderCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CShadowGliderCard); };
class CEncirclingFissureCard : public CCard { DECLARE_CARD_CSTOR(CEncirclingFissureCard); };
class COnduRisingCard : public CCard { DECLARE_CARD_CSTOR(COnduRisingCard); };
class CPartTheWaterveilCard : public CCard { DECLARE_CARD_CSTOR(CPartTheWaterveilCard); };
class CRushOfIceCard : public CCard { DECLARE_CARD_CSTOR(CRushOfIceCard); };
class CScatterToTheWindsCard : public CCard { DECLARE_CARD_CSTOR(CScatterToTheWindsCard); };
class CMiresMaliceCard : public CCard { DECLARE_CARD_CSTOR(CMiresMaliceCard); };
class CRoilSpoutCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CRoilSpoutCard); };
class CGrovetenderDruidsCard : public CCreatureCard { DECLARE_CARD_CSTOR(CGrovetenderDruidsCard); };
class CHeroOfGomaFadaCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHeroOfGomaFadaCard); };
class CKalastriaHealerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKalastriaHealerCard); };
class CKorBladewhirlCard : public CRallyCreatureCard { DECLARE_CARD_CSTOR(CKorBladewhirlCard); };
class CKorEntanglersCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKorEntanglersCard); };
class CLanternScoutCard : public CCreatureCard { DECLARE_CARD_CSTOR(CLanternScoutCard); };
class CMakindiPatrolCard : public CRallyCreatureCard { DECLARE_CARD_CSTOR(CMakindiPatrolCard); };
class COnduChampionCard : public CRallyCreatureCard { DECLARE_CARD_CSTOR(COnduChampionCard); };
class CResoluteBlademasterCard : public CRallyCreatureCard { DECLARE_CARD_CSTOR(CResoluteBlademasterCard); };
class CTajuruBeastmasterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTajuruBeastmasterCard); };
class CTajuruWarcallerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTajuruWarcallerCard); };

//____________________________________________________________________________
//
// Battle lands: this land enters the battlefield tapped unless you control two or more basic lands.
class CBattleLandCard : public CDualLandCard
{
protected:
	CBattleLandCard(CGame* pGame, LPCTSTR strCardName, UINT uID, CardType landType,
					LPCTSTR strPoolText1, LPCTSTR strPoolText2);

	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener>	m_cpAListener;	// Listen to this card's zone changes
};

class CCanopyVistaCard : public CBattleLandCard { DECLARE_CARD_CSTOR(CCanopyVistaCard); };
class CCinderGladeCard : public CBattleLandCard { DECLARE_CARD_CSTOR(CCinderGladeCard); };
class CPrairieStreamCard : public CBattleLandCard { DECLARE_CARD_CSTOR(CPrairieStreamCard); };
class CSmolderingMarshCard : public CBattleLandCard { DECLARE_CARD_CSTOR(CSmolderingMarshCard); };
class CSunkenHollowCard : public CBattleLandCard { DECLARE_CARD_CSTOR(CSunkenHollowCard); };

class CBlightedCataractCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CBlightedCataractCard); };
class CBlightedFenCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CBlightedFenCard); };
class CBlightedGorgeCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CBlightedGorgeCard); };
class CBlightedSteppeCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CBlightedSteppeCard); };
class CBlightedWoodlandCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CBlightedWoodlandCard); };
class CLoomingSpiresCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CLoomingSpiresCard); };
class CLumberingFallsCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CLumberingFallsCard); };
class CMortuaryMireCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CMortuaryMireCard); };
class CSandstoneBridgeCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CSandstoneBridgeCard); };
class CShamblingVentCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CShamblingVentCard); };
class CSkylineCascadeCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CSkylineCascadeCard); };
class CSpawningBedCard : public CNonbasicLandCard { DECLARE_CARD_CSTOR(CSpawningBedCard); };

//____________________________________________________________________________
//
// Planeswalkers
class CGideonAllyOfZendikarCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CGideonAllyOfZendikarCard);

protected:
	ListenerPtr<ResolutionCompletedEventSource::Listener>	m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
};

class CObNixilisReignitedCard : public CPlaneswalkerCard { DECLARE_CARD_CSTOR(CObNixilisReignitedCard); };

//____________________________________________________________________________
//
// Artifacts
class CAlignedHedronNetworkCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAlignedHedronNetworkCard);

protected:
	CCountedCardContainer_ pExiled;

	bool BeforeResolution1(CAbilityAction* pAction);
	bool BeforeResolution2(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbilityAux;
	bool SetTriggerContextAux(CTriggeredAbility<>::TriggerContextType& triggerContext,
										CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolutionAux(TriggeredAbilityAux::TriggeredActionType* pAction);
};

class CHedronArchiveCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CHedronArchiveCard); };

class CHedronBladeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHedronBladeCard);

private:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);

	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback,
						   &CWhenSelfAttackedBlocked::SetBlockedEachTimeEventCallback > TriggeredAbility;
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						   CCreatureCard* pCreature, CCreatureCard* pBlocker, int nBlockedByCount, int nBlockingIndex) const;
};

class CPathwayArrowsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPathwayArrowsCard);

private:
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
	bool BeforeResolution(CAbilityAction* pAction) const;
};

//____________________________________________________________________________
//
// Enchantments
class CAngelicGiftCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CAngelicGiftCard); };
class CDampeningPulseCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CDampeningPulseCard); };
class CTighteningCoilsCard : public CChgPwrTghAttrEnchantCard { DECLARE_CARD_CSTOR(CTighteningCoilsCard); };
class CVampiricRitesCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CVampiricRitesCard); };
class CMoltenNurseryCard : public CInPlaySpellCard { DECLARE_CARD_CSTOR(CMoltenNurseryCard); };

class CFromBeyondCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFromBeyondCard);

protected:
	CCardFilter m_CardFilter;
};

class CStasisSnareCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CStasisSnareCard);

private:
	CCardFlagModifier m_CardFlagModifier1;
	CCardFlagModifier m_CardFlagModifier2;
};

class CQuarantineFieldCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CQuarantineFieldCard);

protected:
	CCountedCardContainer_ pExiled;
	CSelectionSupport m_CardSelection;

	bool BeforeResolution1(CAbilityAction* pAction);
	bool BeforeResolution2(CAbilityAction* pAction);
	void OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbilityAux;
	bool SetTriggerContextAux(CTriggeredAbility<>::TriggerContextType& triggerContext,
										CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolutionAux(TriggeredAbilityAux::TriggeredActionType* pAction);
};

// Retreats: Landfall - Whenever a land you control enters, choose one - mode 1 or mode 2.
// The mode is chosen when the landfall triggers; the chosen mode then goes on the stack
// as a CSpecialTrigger ability (CHOICE_1_TRIGGER_ID / CHOICE_2_TRIGGER_ID), as Quiet Disrepair does.
class CRetreatCard : public CInPlaySpellCard
{
protected:
	CRetreatCard(CGame* pGame, LPCTSTR strCardName, UINT uID, LPCTSTR strCostText,
				 LPCTSTR strMode1Text, LPCTSTR strMode2Text);

	template <class TriggeredAbility>
	counted_ptr<TriggeredAbility> CreateModeAbility(int nTriggerId, LPCTSTR strAbilityName);

	void OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_ModeSelection;
	CString m_strMode1Text;
	CString m_strMode2Text;

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > LandfallAbility;
	bool SetLandfallContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
							CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

class CRetreatToCoralhelmCard : public CRetreatCard
{
	DECLARE_CARD_CSTOR(CRetreatToCoralhelmCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CSpecialTrigger > ScryAbility;
	bool BeforeScry(ScryAbility::TriggeredActionType* pAction) const;
};

//____________________________________________________________________________
//
// Sorceries
class CCrumbleToDustCard : public CTargetMoveCardSpellCard
{
	DECLARE_CARD_CSTOR(CCrumbleToDustCard);

private:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CDemonsGraspCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CDemonsGraspCard); };
class CReclaimingVinesCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CReclaimingVinesCard); };
class CNissasRenewalCard : public CSearchLibrarySpellCard { DECLARE_CARD_CSTOR(CNissasRenewalCard); };
class CTouchOfTheVoidCard : public CCard { DECLARE_CARD_CSTOR(CTouchOfTheVoidCard); };

class CSeekTheWildsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSeekTheWildsCard);

protected:
	CCardFilter m_CardFilter;
};

class CTransgressTheMindCard : public CCard
{
	DECLARE_CARD_CSTOR(CTransgressTheMindCard);

protected:
	CCardFilter m_CardFilter;
};

class CSwarmSurgeCard : public CCard
{
	DECLARE_CARD_CSTOR(CSwarmSurgeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CUginsInsightCard : public CCard
{
	DECLARE_CARD_CSTOR(CUginsInsightCard);

private:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CMarchFromTheTombCard : public CCard
{
	DECLARE_CARD_CSTOR(CMarchFromTheTombCard);

private:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;

	// Ally cards are chosen one at a time while the total mana value stays 8 or less
	void RequestNextAlly(CPlayer* pPlayer);
	void ReturnChosenAllies(CPlayer* pPlayer);
	void OnAllySelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_AllySelection;
	CCountedCardContainer_ m_ChosenAllies;
	int m_nRemainingManaValue;
};

//____________________________________________________________________________
//
// Instants
class CAdverseConditionsCard : public CCard { DECLARE_CARD_CSTOR(CAdverseConditionsCard); };
class CAnticipateCard : public CCard { DECLARE_CARD_CSTOR(CAnticipateCard); };
class CCompleteDisregardCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CCompleteDisregardCard); };
class CGideonsReproachCard : public CCard { DECLARE_CARD_CSTOR(CGideonsReproachCard); };
class CGripOfDesolationCard : public CCard { DECLARE_CARD_CSTOR(CGripOfDesolationCard); };
class CHorriblyAwryCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CHorriblyAwryCard); };
class CNaturalConnectionCard : public CSearchLibrarySpellCard { DECLARE_CARD_CSTOR(CNaturalConnectionCard); };
class COutnumberCard : public CCard { DECLARE_CARD_CSTOR(COutnumberCard); };
class CRoilsRetributionCard : public CCard { DECLARE_CARD_CSTOR(CRoilsRetributionCard); };
class CScourFromExistenceCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CScourFromExistenceCard); };
class CSpellShrivelCard : public CCounterSpellCard { DECLARE_CARD_CSTOR(CSpellShrivelCard); };
class CStonefuryCard : public CCard { DECLARE_CARD_CSTOR(CStonefuryCard); };
class CSureStrikeCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CSureStrikeCard); };
class CTandemTacticsCard : public CChgPwrTghAttrSpellCard { DECLARE_CARD_CSTOR(CTandemTacticsCard); };
class CTurnAgainstCard : public CCard { DECLARE_CARD_CSTOR(CTurnAgainstCard); };
class CVolcanicUpheavalCard : public CTargetMoveCardSpellCard { DECLARE_CARD_CSTOR(CVolcanicUpheavalCard); };

class CGraveBirthingCard : public CCard
{
	DECLARE_CARD_CSTOR(CGraveBirthingCard);

private:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_CardSelection;
};

class CSwellOfGrowthCard : public CChgPwrTghAttrSpellCard
{
	DECLARE_CARD_CSTOR(CSwellOfGrowthCard);

private:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
	void OnLandSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_LandSelection;
};

class CUnnaturalAggressionCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnnaturalAggressionCard);

protected:
	class CUnnaturalAggressionSpell : public CDoubleTargetSpell
	{
	DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		CUnnaturalAggressionSpell(CCard* pCard, AbilityType abilityType, LPCTSTR strManaCost);
		virtual ~CUnnaturalAggressionSpell() {}

		OVERRIDE(void, ResolveGroup)(const CCountedCardContainer& pContainer1, const CCountedCardContainer& pContainer2, const CPlayerContainer& pPContainer1, const CPlayerContainer& pPContainer2);
	};
};

//____________________________________________________________________________
//
// Eldrazi creatures
class CBaneOfBalaGedCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBaneOfBalaGedCard); };
class CBenthicInfiltratorCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CBenthicInfiltratorCard); };
class CBreakerOfArmiesCard : public CCreatureCard { DECLARE_CARD_CSTOR(CBreakerOfArmiesCard); };
class CBroodButcherCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CBroodButcherCard); };
class CDesolationTwinCard : public CCreatureCard { DECLARE_CARD_CSTOR(CDesolationTwinCard); };
class CEldraziDevastatorCard : public CCreatureCard { DECLARE_CARD_CSTOR(CEldraziDevastatorCard); };
class CForerunnerOfSlaughterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CForerunnerOfSlaughterCard); };
class CIncubatorDroneCard : public CScionMakerCreatureCard { DECLARE_CARD_CSTOR(CIncubatorDroneCard); };
class CKozileksChannelerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKozileksChannelerCard); };
class CKozileksSentinelCard : public CCreatureCard { DECLARE_CARD_CSTOR(CKozileksSentinelCard); };
class CRuinationGuideCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CRuinationGuideCard); };
class CSalvageDroneCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CSalvageDroneCard); };
class CSilentSkimmerCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CSilentSkimmerCard); };
class CSludgeCrawlerCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CSludgeCrawlerCard); };
class CTideDrifterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTideDrifterCard); };
class CVestigeOfEmrakulCard : public CCreatureCard { DECLARE_CARD_CSTOR(CVestigeOfEmrakulCard); };
class CVileAggregateCard : public CIngestCreatureCard { DECLARE_CARD_CSTOR(CVileAggregateCard); };

class CBarrageTyrantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBarrageTyrantCard);

protected:
	CCardFilter m_SacrificeFilter;
};

class CCatacombSifterCard : public CScionMakerCreatureCard
{
	DECLARE_CARD_CSTOR(CCatacombSifterCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;
	bool BeforeScry(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CDominatorDroneCard : public CIngestCreatureCard
{
	DECLARE_CARD_CSTOR(CDominatorDroneCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CDrownerOfHopeCard : public CScionMakerCreatureCard
{
	DECLARE_CARD_CSTOR(CDrownerOfHopeCard);

protected:
	CCardFilter m_ScionFilter;
};

class CDustStalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDustStalkerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pNode) const;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CEndlessOneCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEndlessOneCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class CFathomFeederCard : public CIngestCreatureCard
{
	DECLARE_CARD_CSTOR(CFathomFeederCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CNettleDroneCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNettleDroneCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;

	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;
	bool BeforeUntap(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CSireOfStagnationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSireOfStagnationCard);

protected:
	bool SetTriggerContext(CTriggeredDrawCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CUlamogTheCeaselessHungerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUlamogTheCeaselessHungerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > AttackAbility;
	bool BeforeAttackResolution(AttackAbility::TriggeredActionType* pAction) const;
};

//____________________________________________________________________________
//
// Processors (cards that put cards an opponent owns from exile into that player's graveyard, see CProcessCost)

// Spell or activated ability with a processing cost
class CProcessorAssaultCard : public CCard
{
	DECLARE_CARD_CSTOR(CProcessorAssaultCard);

protected:
	CProcessCost m_Process;
	BOOL CanPlay(BOOL bIncludeTricks);
	bool BeforeResolution(CAbilityAction* pAction);
};

class CCrypticCruiserCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCrypticCruiserCard);

protected:
	CProcessCost m_Process;
	BOOL CanPlay(BOOL bIncludeTricks);
	bool BeforeResolution(CAbilityAction* pAction);
};

class COracleOfDustCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COracleOfDustCard);

protected:
	CProcessCost m_Process;
	BOOL CanPlay(BOOL bIncludeTricks);
	bool BeforeResolution(CAbilityAction* pAction);
};

class CVoidAttendantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVoidAttendantCard);

protected:
	CProcessCost m_Process;
	BOOL CanPlay(BOOL bIncludeTricks);
	bool BeforeResolution(CAbilityAction* pAction);
};

// "When you cast this spell / When this creature enters, you may put N cards ... If you do, <effect>"
class CBlightHerderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBlightHerderCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredAbility< CTriggeredCreateTokenAbility, CWhenSelfMoved > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

class CRuinProcessorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRuinProcessorCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredAbility< CTriggeredModifyLifeAbility, CWhenSelfMoved > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

class CMindRakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMindRakerCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);

	void OnDiscardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	CSelectionSupport m_DiscardSelection;
};

class CMurkStriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMurkStriderCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

class CUlamogsReclaimerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUlamogsReclaimerCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

class CWastelandStranglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWastelandStranglerCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfInplay,
								 CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

class CUlamogsDespoilerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUlamogsDespoilerCard);

protected:
	CProcessCost m_Process;
	typedef
		TTriggeredAbility< CTriggeredModifyCardAbility, CWhenSelfInplay,
						   CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback > TriggeredAbility;
	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

class CUlamogsNullifierCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CUlamogsNullifierCard);

protected:
	CProcessCost m_Process;

	// Counter target spell when it resolves (as Mystic Snake)
	class TriggeredAbility :
		public TTriggeredTargetAbility< CTriggeredAbility<>,
		CWhenSelfInplay, CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback >
	{
		DEFINE_CREATE_TO_CPTR_ONLY;

	protected:
		TriggeredAbility(CCard* pCard)
			: TTriggeredTargetAbility(pCard)
		{
		}

		OVERRIDE(BOOL, ResolveSelection)(CPlayer* pPlayer, CTriggeredAction* pAction)
		{
			if (!__super::ResolveSelection(pPlayer, pAction))
				return FALSE;

			counted_ptr<CActivatedAbility<CCounterSpell>>
				cpAbility(CreateResolutionAbility<CActivatedAbility<CCounterSpell>>(
				pPlayer,
				new SpecificCardComparer(pAction->GetAssociatedCard())));

			std::auto_ptr<CActionContainer> apActions(cpAbility->GetAbilityActions(TRUE, FALSE));
			if (!apActions->GetSize())
				return FALSE;

			return cpAbility->Resolve((CAbilityAction*)(apActions->GetAt(0).GetPointer()));
		}
	};

	bool CanProcess(TriggeredAbility::TriggerContextType& triggerContext, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool Process(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
// Other creatures

// Landfall - Whenever a land you control enters, this creature gets +X/+Y (or gains a keyword) until end of turn
class CLandfallPumpCreatureCard : public CCreatureCard
{
protected:
	CLandfallPumpCreatureCard(CGame* pGame, LPCTSTR strCardName, const CreatureType& creatureType, UINT uID,
							  LPCTSTR strCostText, Power nPower, Life nToughness,
							  Power nPowerDelta, Life nLifeDelta, CreatureKeyword landfallKeyword = CreatureKeyword::Null);
};

class CBelligerentWhiptailCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CBelligerentWhiptailCard); };
class CGeyserfieldStalkerCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CGeyserfieldStalkerCard); };
class CGroveRumblerCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CGroveRumblerCard); };
class CMakindiSliderunnerCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CMakindiSliderunnerCard); };
class COnduGreathornCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(COnduGreathornCard); };
class CScytheLeopardCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CScytheLeopardCard); };
class CSnappingGnarlidCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CSnappingGnarlidCard); };
class CValakutPredatorCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CValakutPredatorCard); };
class CWaveWingElementalCard : public CLandfallPumpCreatureCard { DECLARE_CARD_CSTOR(CWaveWingElementalCard); };

class CAkoumStonewakerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CAkoumStonewakerCard); };
class CCarrierThrallCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCarrierThrallCard); };
class CCourierGriffinCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CCourierGriffinCard); };
class CFelidarCubCard : public CCreatureCard { DECLARE_CARD_CSTOR(CFelidarCubCard); };
class CJaddiOffshootCard : public CCreatureCard { DECLARE_CARD_CSTOR(CJaddiOffshootCard); };
class CLavastepRaiderCard : public CCreatureCard { DECLARE_CARD_CSTOR(CLavastepRaiderCard); };
class CLifespringDruidCard : public CCreatureCard { DECLARE_CARD_CSTOR(CLifespringDruidCard); };
class CMurasaRangerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CMurasaRangerCard); };
class COranRiefInvokerCard : public CCreatureCard { DECLARE_CARD_CSTOR(COranRiefInvokerCard); };
class CPlatedCrusherCard : public CCreatureCard { DECLARE_CARD_CSTOR(CPlatedCrusherCard); };
class CRotShamblerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CRotShamblerCard); };
class CStoneHavenMedicCard : public CCreatureCard { DECLARE_CARD_CSTOR(CStoneHavenMedicCard); };
class CTunnelingGeopedeCard : public CCreatureCard { DECLARE_CARD_CSTOR(CTunnelingGeopedeCard); };
class CValakutInvokerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CValakutInvokerCard); };
class CVoraciousNullCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVoraciousNullCard);

protected:
	CCardFilter m_SacrificeFilter;
};

class CAkoumHellkiteCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAkoumHellkiteCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CGuardianOfTazeemCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGuardianOfTazeemCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CGuulDrazOverseerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGuulDrazOverseerCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class COranRiefHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COranRiefHydraCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class COmnathLocusOfRageCard : public CCreatureCard { DECLARE_CARD_CSTOR(COmnathLocusOfRageCard); };

class CDefiantBloodlordCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDefiantBloodlordCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

class CMalakirFamiliarCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMalakirFamiliarCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

class CGreenwardenOfMurasaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGreenwardenOfMurasaCard);

protected:
	typedef
		TTriggeredTargetAbility< CTriggeredMoveCardAbility, CWhenSelfMoved > DiesAbility;
	bool ExileFromGraveyard(DiesAbility::TriggeredActionType* pAction) const;
};

class CWindriderPatrolCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWindriderPatrolCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;
	bool BeforeScry(TriggeredAbility::TriggeredActionType* pAction) const;
};

//____________________________________________________________________________
//
// Allies (without Rally)
class CCoralhelmGuideCard : public CCreatureCard { DECLARE_CARD_CSTOR(CCoralhelmGuideCard); };
class CDranasEmissaryCard : public CFlyingCreatureCard { DECLARE_CARD_CSTOR(CDranasEmissaryCard); };
class CHagraSharpshooterCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHagraSharpshooterCard); };
class CHalimarTidecallerCard : public CCreatureCard { DECLARE_CARD_CSTOR(CHalimarTidecallerCard); };
class CShatterskullRecruitCard : public CCreatureCard { DECLARE_CARD_CSTOR(CShatterskullRecruitCard); };
class CZulaportCutthroatCard : public CCreatureCard { DECLARE_CARD_CSTOR(CZulaportCutthroatCard); };

class CAngelicCaptainCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelicCaptainCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, AttackSubject attacked) const;
};

class CAngelOfRenewalCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfRenewalCard);

protected:
	bool SetTriggerContext(CTriggeredModifyLifeAbility::TriggerContextType& triggerContext,
						   CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CBloodbondVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodbondVampireCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

class CCliffsideLookoutCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCliffsideLookoutCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction) const;
};

class CDranaLiberatorOfMalakirCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDranaLiberatorOfMalakirCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;
	bool BeforeResolution(TriggeredAbility::TriggeredActionType* pAction) const;
};

class CKalastriaNightwatchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKalastriaNightwatchCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

class CNirkanaAssassinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNirkanaAssassinCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

class CKorCastigatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKorCastigatorCard);

protected:
	CCardFilter m_CanBlockFilter;
};

class CRecklessCohortCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRecklessCohortCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, CNode* pNode) const;
};

class CSereneStewardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSereneStewardCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCardAbility::TriggerContextType& triggerContext,
						   const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

class CVeteranWarleaderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVeteranWarleaderCard);

protected:
	CCardFilter m_AllyFilter;
};

class CRetreatToEmeriaCard : public CRetreatCard { DECLARE_CARD_CSTOR(CRetreatToEmeriaCard); };
class CRetreatToHagraCard : public CRetreatCard { DECLARE_CARD_CSTOR(CRetreatToHagraCard); };
class CRetreatToKazanduCard : public CRetreatCard { DECLARE_CARD_CSTOR(CRetreatToKazanduCard); };
class CRetreatToValakutCard : public CRetreatCard { DECLARE_CARD_CSTOR(CRetreatToValakutCard); };