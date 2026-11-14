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

class CFieldOfRuinCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CFieldOfRuinCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CHuatliDinosaurKnightCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CHuatliDinosaurKnightCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CHuatliWarriorPoetCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CHuatliWarriorPoetCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

class CJaceCunningCastawayCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJaceCunningCastawayCard);

protected:
	bool BeforeLootEffect(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CPlayer* pPlayer, Damage damage) const;
	bool BeforeLoot(CAbilityAction* pAction);

	int m_nLootTurn;		// the turn of the +1 activations
	int m_nLootCount;		// the +1 activations in that turn
	mutable int m_nLootedTurn;	// the turn the loot already triggered
};

class CJaceIngeniousMindMageCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJaceIngeniousMindMageCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CVraskaRelicSeekerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVraskaRelicSeekerCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
	bool BeforeLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

// Ixalan transform cards (Legendary Enchantment // Legendary Land): the front face abilities are only playable on the
// first face, the back face abilities on the second face; transforming makes the card a land (as Chalice of Life in
// Dark Ascension)
class CTransformEnchantmentBase : public CDoubleFacedInPlaySpellCard
{
protected:
	CTransformEnchantmentBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText, LPCTSTR strBackName);

	// The ability works on the first (bFirstFace) or the second face only
	void SetFace(CAbility* pAbility, BOOL bFirstFace);
	// "{T}: Add <mana>." on the second face
	void AddBackManaAbility(LPCTSTR strMana);
	// Transforms the card if it's on the battlefield on its first face
	void DoTransform();

	BOOL IsFirstFaceInPlay() const;
};

class CArguelsBloodFastCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CArguelsBloodFastCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
	bool BeforeGainLife(CAbilityAction* pAction);

	CCardFilter m_CreatureFilter;
};

class CTempleOfAclazotzCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CTempleOfAclazotzCard);
};

class CGrowingRitesOfItlimocCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CGrowingRitesOfItlimocCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
};

class CItlimocCradleOfTheSunCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CItlimocCradleOfTheSunCard);
};

class CLegionsLandingCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CLegionsLandingCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
};

class CAdantoTheFirstFortCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CAdantoTheFirstFortCard);
};

class CSearchForAzcantaCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CSearchForAzcantaCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeSurveil(CAbilityAction* pAction);
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_LookFilter;
};

class CAzcantaTheSunkenRuinCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CAzcantaTheSunkenRuinCard);
};

class CAshesOfTheAbhorrentCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAshesOfTheAbhorrentCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CAxisOfMortalityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAxisOfMortalityCard);

protected:
	bool BeforeExchange(CAbilityAction* pAction);
};

class CCastawaysDespairCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCastawaysDespairCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CDeeprootWatersCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDeeprootWatersCard);
};

class CIxalansBindingCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CIxalansBindingCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CMakeshiftMunitionsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMakeshiftMunitionsCard);

protected:
	CCardFilter m_SacrificeFilter;
};

class CNavigatorsRuinCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CNavigatorsRuinCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeMill(CAbilityAction* pAction);
};

class COneWithTheWindCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(COneWithTheWindCard);
};

class CPiousInterdictionCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CPiousInterdictionCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CRaidersWakeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRaidersWakeCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CRevelInRichesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRevelInRichesCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredLoseGameAbility, CWhenNodeChanged > WinAbility;

	bool SetWinContext(CTriggeredLoseGameAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeWin(WinAbility::TriggeredActionType* pAction);
	BOOL HasTenTreasures() const;
};

class CShapersSanctuaryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CShapersSanctuaryCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSwashbucklingCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSwashbucklingCard);
};

class CTroveOfTemptationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTroveOfTemptationCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

// Ixalan transform artifacts (Artifact // Land), as CTransformEnchantmentBase
class CTransformArtifactBase : public CDoubleFacedInPlaySpellCard
{
protected:
	CTransformArtifactBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText, LPCTSTR strBackName);

	void SetFace(CAbility* pAbility, BOOL bFirstFace);
	void AddBackManaAbility(LPCTSTR strMana);
	void DoTransform();
	BOOL IsFirstFaceInPlay() const;
};

class CPrimalAmuletCard : public CTransformArtifactBase
{
	DECLARE_CARD_CSTOR(CPrimalAmuletCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CPrimalWellspringCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CPrimalWellspringCard);
};

class CThaumaticCompassCard : public CTransformArtifactBase
{
	DECLARE_CARD_CSTOR(CThaumaticCompassCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
	bool BeforeRemove(CAbilityAction* pAction);
};

class CSpiresOfOrazcaCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSpiresOfOrazcaCard);
};

class CTreasureMapCard : public CTransformArtifactBase
{
	DECLARE_CARD_CSTOR(CTreasureMapCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);

	CCardFilter m_TreasureFilter;
};

class CTreasureCoveCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CTreasureCoveCard);
};

class CDuskLegionDreadnoughtCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDuskLegionDreadnoughtCard);

protected:
	CCrewSupport m_Crew;
};

class CElaborateFirecannonCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CElaborateFirecannonCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CFellFlagshipCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFellFlagshipCard);

protected:
	CCrewSupport m_Crew;
};

class CHierophantsChaliceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHierophantsChaliceCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CPiratesCutlassCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPiratesCutlassCard);

protected:
	bool BeforeAttach(CAbilityAction* pAction);
};

class CPryingBladeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPryingBladeCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CPlayer* pPlayer, Damage damage) const;
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CSentinelTotemCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSentinelTotemCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CShadowedCaravelCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CShadowedCaravelCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);

	CCrewSupport m_Crew;
};

class CSleekSchoonerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSleekSchoonerCard);

protected:
	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

// The card passes if it passes any of the comparers (as Hour of Devastation)
struct OrCardComparer : public CardComparer
{
	OrCardComparer(CardComparer* pComparer1, CardComparer* pComparer2)
		: m_pComparer1(pComparer1), m_pComparer2(pComparer2)
	{}

	virtual bool operator()(const CCard* value) const
	{
		return m_pComparer1->operator()(value) || m_pComparer2->operator()(value);
	}

	virtual OrCardComparer* Clone() const
	{
		return new OrCardComparer(m_pComparer1->Clone(), m_pComparer2->Clone());
	}

protected:
	std::auto_ptr<CardComparer> m_pComparer1;
	std::auto_ptr<CardComparer> m_pComparer2;
};

class CBoneyardParleyCard : public CCard
{
	DECLARE_CARD_CSTOR(CBoneyardParleyCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnCardsChosen(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnPileSeparated(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnPileChosen(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
	CSelectionSupport m_SeparateSelection;
	CSelectionSupport m_PileSelection;
	CCountedCardContainer m_Pile1;
	CCountedCardContainer m_Pile2;
};

class CCallToTheFeastCard : public CCard
{
	DECLARE_CARD_CSTOR(CCallToTheFeastCard);
};

class CChartACourseCard : public CCard
{
	DECLARE_CARD_CSTOR(CChartACourseCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CCommuneWithDinosaursCard : public CCard
{
	DECLARE_CARD_CSTOR(CCommuneWithDinosaursCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_LookFilter;
};

class CContractKillingCard : public CCard
{
	DECLARE_CARD_CSTOR(CContractKillingCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CEmergentGrowthCard : public CCard
{
	DECLARE_CARD_CSTOR(CEmergentGrowthCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CEntrancingMelodyCard : public CCard
{
	DECLARE_CARD_CSTOR(CEntrancingMelodyCard);

protected:
	bool BeforeControl(CAbilityAction* pAction);
};

class CFirecannonBlastCard : public CCard
{
	DECLARE_CARD_CSTOR(CFirecannonBlastCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CGraspingCurrentCard : public CCard
{
	DECLARE_CARD_CSTOR(CGraspingCurrentCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CGrimCaptainsCallCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrimCaptainsCallCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CHeartlessPillageCard : public CCard
{
	DECLARE_CARD_CSTOR(CHeartlessPillageCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CLegionsJudgmentCard : public CCard
{
	DECLARE_CARD_CSTOR(CLegionsJudgmentCard);
};

class CMarchOfTheDrownedCard : public CCard
{
	DECLARE_CARD_CSTOR(CMarchOfTheDrownedCard);
};

class COverflowingInsightCard : public CCard
{
	DECLARE_CARD_CSTOR(COverflowingInsightCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CPiratesPrizeCard : public CCard
{
	DECLARE_CARD_CSTOR(CPiratesPrizeCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CQueensCommissionCard : public CCard
{
	DECLARE_CARD_CSTOR(CQueensCommissionCard);
};

class CRepeatingBarrageCard : public CCard
{
	DECLARE_CARD_CSTOR(CRepeatingBarrageCard);

protected:
	BOOL HasRaidCondition(BOOL bIncludeTricks);
	bool BeforeReturn(CAbilityAction* pAction);
};

class CRileCard : public CCard
{
	DECLARE_CARD_CSTOR(CRileCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CRiversRebukeCard : public CCard
{
	DECLARE_CARD_CSTOR(CRiversRebukeCard);

protected:
	bool BeforeBounce(CAbilityAction* pAction);
};

class CSavageStompCard : public CCard
{
	DECLARE_CARD_CSTOR(CSavageStompCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CSpreadingRotCard : public CCard
{
	DECLARE_CARD_CSTOR(CSpreadingRotCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CStarOfExtinctionCard : public CCard
{
	DECLARE_CARD_CSTOR(CStarOfExtinctionCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CSwordPointDiplomacyCard : public CCard
{
	DECLARE_CARD_CSTOR(CSwordPointDiplomacyCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
	void OnPaid(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PaySelection;
};

class CWalkThePlankCard : public CCard
{
	DECLARE_CARD_CSTOR(CWalkThePlankCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

class CBlindingFogCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlindingFogCard);

protected:
	bool BeforeFog(CAbilityAction* pAction);
};

class CBrightReprisalCard : public CCard
{
	DECLARE_CARD_CSTOR(CBrightReprisalCard);
};

class CCostlyPlunderCard : public CCard
{
	DECLARE_CARD_CSTOR(CCostlyPlunderCard);

protected:
	CCardFilter m_SacrificeFilter;
};

class CCrashTheRampartsCard : public CCard
{
	DECLARE_CARD_CSTOR(CCrashTheRampartsCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CCrushingCanopyCard : public CCard
{
	DECLARE_CARD_CSTOR(CCrushingCanopyCard);
};

class CDarkNourishmentCard : public CCard
{
	DECLARE_CARD_CSTOR(CDarkNourishmentCard);
};

class CDepthsOfDesireCard : public CCard
{
	DECLARE_CARD_CSTOR(CDepthsOfDesireCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CDinosaurStampedeCard : public CCard
{
	DECLARE_CARD_CSTOR(CDinosaurStampedeCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CDiveDownCard : public CCard
{
	DECLARE_CARD_CSTOR(CDiveDownCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CFieryCannonadeCard : public CCard
{
	DECLARE_CARD_CSTOR(CFieryCannonadeCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CHuatlisSpurringCard : public CCard
{
	DECLARE_CARD_CSTOR(CHuatlisSpurringCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CLookoutsDispersalCard : public CCard
{
	DECLARE_CARD_CSTOR(CLookoutsDispersalCard);

protected:
	BOOL ControlsPirate(BOOL bIncludeTricks);
};

class CPerilousVoyageCard : public CCard
{
	DECLARE_CARD_CSTOR(CPerilousVoyageCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

class CPounceCard : public CCard
{
	DECLARE_CARD_CSTOR(CPounceCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CRallyingRoarCard : public CCard
{
	DECLARE_CARD_CSTOR(CRallyingRoarCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CRitualOfRejuvenationCard : public CCard
{
	DECLARE_CARD_CSTOR(CRitualOfRejuvenationCard);
};

class CRiverHeraldsBoonCard : public CCard
{
	DECLARE_CARD_CSTOR(CRiverHeraldsBoonCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CRunAgroundCard : public CCard
{
	DECLARE_CARD_CSTOR(CRunAgroundCard);
};

class CSanguineSacramentCard : public CCard
{
	DECLARE_CARD_CSTOR(CSanguineSacramentCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CSettleTheWreckageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSettleTheWreckageCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CShelteringLightCard : public CCard
{
	DECLARE_CARD_CSTOR(CShelteringLightCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CSirensRuseCard : public CCard
{
	DECLARE_CARD_CSTOR(CSirensRuseCard);

protected:
	bool BeforeFlicker(CAbilityAction* pAction);
};

class CSkulduggeryCard : public CCard
{
	DECLARE_CARD_CSTOR(CSkulduggeryCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CSlashOfTalonsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSlashOfTalonsCard);
};

class CSpellSwindleCard : public CCard
{
	DECLARE_CARD_CSTOR(CSpellSwindleCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CUnfriendlyFireCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnfriendlyFireCard);
};

class CVampiresZealCard : public CCard
{
	DECLARE_CARD_CSTOR(CVampiresZealCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CVanquishTheWeakCard : public CCard
{
	DECLARE_CARD_CSTOR(CVanquishTheWeakCard);
};

class CVerdantRebirthCard : public CCard
{
	DECLARE_CARD_CSTOR(CVerdantRebirthCard);

protected:
	bool BeforeMark(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);

	CCard* m_pMarked;		// the creature that gained the ability
	int m_nMarkedTurn;
};

class CVraskasContemptCard : public CCard
{
	DECLARE_CARD_CSTOR(CVraskasContemptCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

class CAdantoVanguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAdantoVanguardCard);

protected:
	bool BeforeAttackBonus(CAbilityAction* pAction);
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CBellowingAegisaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBellowingAegisaurCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeCounters(CAbilityAction* pAction);
};

class CBishopOfRebirthCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBishopOfRebirthCard);
};

class CBishopsSoldierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBishopsSoldierCard);
};

class CDuskborneSkymarcherCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDuskborneSkymarcherCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CEmissaryOfSunriseCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmissaryOfSunriseCard);

protected:
	CExploreSupport m_Explore;
};

class CEncampmentKeeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEncampmentKeeperCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CGlorifierOfDuskCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGlorifierOfDuskCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
	bool BeforeVigilance(CAbilityAction* pAction);
};

class CGoringCeratopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoringCeratopsCard);

protected:
	bool BeforeDoubleStrike(CAbilityAction* pAction);
};

class CHuatlisSnubhornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHuatlisSnubhornCard);
};

class CImperialAerosaurCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CImperialAerosaurCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CImperialLancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImperialLancerCard);
};

class CInspiringClericCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInspiringClericCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CKinjallisCallerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKinjallisCallerCard);
};

class CKinjallisSunwingCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKinjallisSunwingCard);
};

class CLegionConquistadorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLegionConquistadorCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_NameFilter;
};

class CLoomingAltisaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoomingAltisaurCard);
};

class CMavrenFeinDuskApostleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMavrenFeinDuskApostleCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CPaladinOfTheBloodstainedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPaladinOfTheBloodstainedCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CPriestOfTheWakeningSunCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPriestOfTheWakeningSunCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_DinosaurFilter;
};

class CPterodonKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPterodonKnightCard);
};

class CRaptorCompanionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRaptorCompanionCard);
};

class CShiningAerosaurCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CShiningAerosaurCard);
};

class CSkybladeOfTheLegionCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkybladeOfTheLegionCard);
};

class CSteadfastArmasaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteadfastArmasaurCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CSunriseSeekerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunriseSeekerCard);

protected:
	CExploreSupport m_Explore;
};

class CTerritorialHammerskullCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTerritorialHammerskullCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CWakeningSunsAvatarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWakeningSunsAvatarCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

// The card passes if it passes both comparers (as Hour of Devastation)
struct AndCardComparer : public CardComparer
{
	AndCardComparer(CardComparer* pComparer1, CardComparer* pComparer2)
		: m_pComparer1(pComparer1), m_pComparer2(pComparer2)
	{}

	virtual bool operator()(const CCard* value) const
	{
		return m_pComparer1->operator()(value) && m_pComparer2->operator()(value);
	}

	virtual AndCardComparer* Clone() const
	{
		return new AndCardComparer(m_pComparer1->Clone(), m_pComparer2->Clone());
	}

protected:
	std::auto_ptr<CardComparer> m_pComparer1;
	std::auto_ptr<CardComparer> m_pComparer2;
};

class CAncientBrontodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAncientBrontodonCard);
};

class CAtzocanArcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAtzocanArcherCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CBlossomDryadCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBlossomDryadCard);
};

class CCarnageTyrantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCarnageTyrantCard);
};

class CColossalDreadmawCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CColossalDreadmawCard);
};

class CDeathgorgeScavengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeathgorgeScavengerCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CDeeprootChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeeprootChampionCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CDeeprootWarriorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeeprootWarriorCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CDroverOfTheMightyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDroverOfTheMightyCard);
};

class CEmperorsVanguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmperorsVanguardCard);

protected:
	bool BeforeExplore(CAbilityAction* pAction);
};

class CGrazingWhiptailCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrazingWhiptailCard);
};

class CIxallisDivinerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIxallisDivinerCard);

protected:
	CExploreSupport m_Explore;
};

class CIxallisKeeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIxallisKeeperCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CJadeGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJadeGuardianCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CJungleDelverCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJungleDelverCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CKumenasSpeakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKumenasSpeakerCard);
};

class CMerfolkBranchwalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMerfolkBranchwalkerCard);

protected:
	CExploreSupport m_Explore;
};

class COldGrowthDryadsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COldGrowthDryadsCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CRangingRaptorsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRangingRaptorsCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeSearch(CAbilityAction* pAction);
};

class CRavenousDaggertoothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRavenousDaggertoothCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CRipjawRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRipjawRaptorCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSnappingSailbackCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSnappingSailbackCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CSpikeTailedCeratopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpikeTailedCeratopsCard);
};

class CThunderingSpinebackCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThunderingSpinebackCard);
};

class CTishanasWayfinderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTishanasWayfinderCard);

protected:
	CExploreSupport m_Explore;
};

class CVerdantSunsAvatarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVerdantSunsAvatarCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeGainLife(TriggeredAbility::TriggeredActionType* pAction);
};

class CVineshaperMysticCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVineshaperMysticCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnMerfolkSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_MerfolkSelection;
};

class CWakerOfTheWildsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWakerOfTheWildsCard);

protected:
	bool BeforeAwaken(CAbilityAction* pAction);
};

class CWildgrowthWalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWildgrowthWalkerCard);

protected:
	bool BeforeExplored(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

class CAngrathsMaraudersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAngrathsMaraudersCard);
};

class CBrazenBuccaneersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrazenBuccaneersCard);

protected:
	CExploreSupport m_Explore;
};

class CBurningSunsAvatarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBurningSunsAvatarCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CCaptainLanneryStormCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCaptainLanneryStormCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforePump(CAbilityAction* pAction);
};

class CCaptivatingCrewCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCaptivatingCrewCard);
};

class CChargingMonstrosaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChargingMonstrosaurCard);
};

class CFathomFleetFirebrandCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFathomFleetFirebrandCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CFireShrineKeeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFireShrineKeeperCard);
};

class CFrenziedRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrenziedRaptorCard);
};

class CHeadstrongBruteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeadstrongBruteCard);
};

class CLightningRigCrewCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLightningRigCrewCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeUntap(CAbilityAction* pAction);
};

class CNestRobberCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNestRobberCard);
};

class COtepecHuntmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COtepecHuntmasterCard);

protected:
	bool BeforeHaste(CAbilityAction* pAction);
};

class CRampagingFerocidonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRampagingFerocidonCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
};

class CRaptorHatchlingCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRaptorHatchlingCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CRiggingRunnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRiggingRunnerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CRowdyCrewCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRowdyCrewCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CStormFleetArsonistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormFleetArsonistCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_PermanentFilter;
};

class CStormFleetPyromancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormFleetPyromancerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CSunCrownedHuntersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunCrownedHuntersCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pSource, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

class CThrashOfRaptorsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrashOfRaptorsCard);
};

class CTilonallisKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTilonallisKnightCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CWilyGoblinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWilyGoblinCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

// The creature was dealt damage this turn
struct DamagedThisTurnComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(const_cast<CCard*>(value));
		return pCreature && pCreature->GetDamageTakenThisTurn() > 0;
	}

	virtual DamagedThisTurnComparer* Clone() const
	{
		return new DamagedThisTurnComparer();
	}
};

class CAnointedDeaconCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAnointedDeaconCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CBishopOfTheBloodstainedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBishopOfTheBloodstainedCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CBlightKeeperCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBlightKeeperCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CBloodcrazedPaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodcrazedPaladinCard);

protected:
	bool CountDeath(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounters(CAbilityAction* pAction);

	mutable int m_nDeathTurn;
	mutable int m_nDeaths;
};

class CDeadeyeTormentorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyeTormentorCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CDeadeyeTrackerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyeTrackerCard);

protected:
	bool BeforeExplore(CAbilityAction* pAction);
};

class CDeathlessAncientCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDeathlessAncientCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_VampireFilter;
};

class CDesperateCastawaysCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDesperateCastawaysCard);
};

class CDireFleetHoarderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetHoarderCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CDireFleetInterloperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetInterloperCard);

protected:
	CExploreSupport m_Explore;
};

class CDireFleetRavagerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetRavagerCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CFathomFleetCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFathomFleetCaptainCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CFathomFleetCutthroatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFathomFleetCutthroatCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CKitesailFreebooterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKitesailFreebooterCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeReturn(CAbilityAction* pAction);

	CSelectionSupport m_CardSelection;
	CCard* m_pExiled;
};

class CLurkingChupacabraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLurkingChupacabraCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

class CQueensAgentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CQueensAgentCard);

protected:
	CExploreSupport m_Explore;
};

class CQueensBaySoldierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CQueensBaySoldierCard);
};

class CRuinRaiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRuinRaiderCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeReveal(CAbilityAction* pAction);
};

class CRuthlessKnaveCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRuthlessKnaveCard);

protected:
	bool BeforeTreasures(CAbilityAction* pAction);

	CCardFilter m_CreatureFilter;
	CCardFilter m_TreasureFilter;
};

class CSanctumSeekerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSanctumSeekerCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject subject) const;
	bool BeforeDrain(CAbilityAction* pAction);
};

class CSeekersSquireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSeekersSquireCard);

protected:
	CExploreSupport m_Explore;
};

class CSkitteringHeartstopperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkitteringHeartstopperCard);

protected:
	bool BeforeDeathtouch(CAbilityAction* pAction);
};

class CSkymarchBloodletterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkymarchBloodletterCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CViciousConquistadorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CViciousConquistadorCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CWantedScoundrelsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWantedScoundrelsCard);

protected:
	bool BeforeTreasures(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

// The card is a Vehicle (it has a crew ability)
struct VehicleComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		return CCrewSupport::Find(value) != NULL;
	}

	virtual VehicleComparer* Clone() const
	{
		return new VehicleComparer();
	}
};

class CDaringSaboteurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDaringSaboteurCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
	bool BeforeLoot(CAbilityAction* pAction);
};

class CDeadeyeQuartermasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyeQuartermasterCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_SearchFilter;
};

class CDreamcallerSirenCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDreamcallerSirenCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnPermanentsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PermanentSelection;
};

class CFleetSwallowerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFleetSwallowerCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CHeadwaterSentriesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeadwaterSentriesCard);
};

class CHeraldOfSecretStreamsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeraldOfSecretStreamsCard);
};

class CJacesSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJacesSentinelCard);
};

class CProsperousPiratesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CProsperousPiratesCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CRiverSneakCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRiverSneakCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CSailorOfMeansCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSailorOfMeansCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CShaperApprenticeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShaperApprenticeCard);
};

class CShipwreckLooterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShipwreckLooterCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
};

class CShoreKeeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShoreKeeperCard);
};

class CSirenLookoutCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSirenLookoutCard);

protected:
	CExploreSupport m_Explore;
};

class CSirenStormtamerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSirenStormtamerCard);
};

class CStormFleetAerialistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CStormFleetAerialistCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CStormFleetSpyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormFleetSpyCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CStormSculptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormSculptorCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CTempestCallerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTempestCallerCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CWatertrapWeaverCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWatertrapWeaverCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CWindStriderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWindStriderCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

class CAdmiralBeckettBrassCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAdmiralBeckettBrassCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
						   CWhenDamageDealt::PlayerEventCallback,
						   &CWhenDamageDealt::SetPlayerEventCallback > DamageTriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeChoose(CAbilityAction* pAction);
	void OnPermanentSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	int CountPirates(const CPlayer* pPlayer) const;

	CSelectionSupport m_PermanentSelection;

	// The Pirates that dealt combat damage to each player this turn
	mutable int m_nTurn;
	mutable std::vector<std::pair<const CPlayer*, const CCard*>> m_Damaged;
};

class CDeadeyePlunderersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyePlunderersCard);
};

class CDireFleetCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetCaptainCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CGildedSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGildedSentinelCard);
};

class CGishathSunsAvatarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGishathSunsAvatarCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeReveal(TriggeredAbility::TriggeredActionType* pAction);

	CCardFilter m_DinosaurFilter;
};

class CHostageTakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHostageTakerCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CMaraudingLooterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMaraudingLooterCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeLoot(CAbilityAction* pAction);
};

class CRagingSwordtoothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRagingSwordtoothCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CRegisaurAlphaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRegisaurAlphaCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CShapersOfNatureCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShapersOfNatureCard);
};

class CSkyTerrorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkyTerrorCard);
};

class CSunBlessedMountCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunBlessedMountCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CTishanaVoiceOfThunderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTishanaVoiceOfThunderCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CVonaButcherOfMaganCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVonaButcherOfMaganCard);

protected:
	BOOL IsYourTurn(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
