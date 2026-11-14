#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Mechanics

// Afflict N: "Whenever this creature becomes blocked, defending player loses N life."
// The creature keeps a CAfflictSupport member and calls AddAfflictAbility(N) in its constructor.
// Several instances of afflict are several calls (each one triggers separately).
class CAfflictSupport
{
public:
	CAfflictSupport(CCreatureCard* pCard) : m_pCard(pCard), m_nAfflict(0) {}

	void AddAfflictAbility(int nAfflict);

protected:
	bool OnBlocked(CAbilityAction* pAction);

	CCreatureCard* m_pCard;
	int m_nAfflict;
};

//____________________________________________________________________________
//
// Lands

class CCryptOfTheEternalsCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CCryptOfTheEternalsCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

// Hour of Devastation cycling Deserts: "This land enters tapped. {T}: Add {C1}. Cycling {1}{C1}"
class CCyclingDesertBase : public CNonbasicLandCard
{
protected:
	CCyclingDesertBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strMana);
};

class CDesertOfTheFerventCard : public CCyclingDesertBase { DECLARE_CARD_CSTOR(CDesertOfTheFerventCard); };
class CDesertOfTheGlorifiedCard : public CCyclingDesertBase { DECLARE_CARD_CSTOR(CDesertOfTheGlorifiedCard); };
class CDesertOfTheIndomitableCard : public CCyclingDesertBase { DECLARE_CARD_CSTOR(CDesertOfTheIndomitableCard); };
class CDesertOfTheMindfulCard : public CCyclingDesertBase { DECLARE_CARD_CSTOR(CDesertOfTheMindfulCard); };
class CDesertOfTheTrueCard : public CCyclingDesertBase { DECLARE_CARD_CSTOR(CDesertOfTheTrueCard); };

class CDunesOfTheDeadCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CDunesOfTheDeadCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CEndlessSandsCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CEndlessSandsCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

// Hour of Devastation Deserts: "{T}: Add {C}. {T}, Pay 1 life: Add {C1}. <cost>, {T}, Sacrifice a Desert: <effect>"
class CSacrificeDesertBase : public CNonbasicLandCard
{
protected:
	CSacrificeDesertBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strMana);

	// Adds "{T}, Sacrifice a Desert" to the cost of the ability
	void AddSacrificeDesertCost(CAbility* pAbility);

	CCardFilter m_DesertFilter;
};

class CHashepOasisCard : public CSacrificeDesertBase
{
	DECLARE_CARD_CSTOR(CHashepOasisCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CHostileDesertCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CHostileDesertCard);
};

class CIfnirDeadlandsCard : public CSacrificeDesertBase
{
	DECLARE_CARD_CSTOR(CIfnirDeadlandsCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CIpnuRivuletCard : public CSacrificeDesertBase
{
	DECLARE_CARD_CSTOR(CIpnuRivuletCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CRamunapRuinsCard : public CSacrificeDesertBase
{
	DECLARE_CARD_CSTOR(CRamunapRuinsCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CScavengerGroundsCard : public CSacrificeDesertBase
{
	DECLARE_CARD_CSTOR(CScavengerGroundsCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CShefetDunesCard : public CSacrificeDesertBase
{
	DECLARE_CARD_CSTOR(CShefetDunesCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CSurvivorsEncampmentCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSurvivorsEncampmentCard);

protected:
	CCardFilter m_CreatureFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CNicolBolasGodPharaohCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNicolBolasGodPharaohCard);

protected:
	bool BeforeExileTop(CAbilityAction* pAction);
	bool BeforeExileHand(CAbilityAction* pAction);
	bool BeforeExilePermanents(CAbilityAction* pAction);
};

class CNicolBolasTheDeceiverCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNicolBolasTheDeceiverCard);

protected:
	bool BeforeChoice(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
	CCardFilter m_NonlandFilter;
};

class CNissaGenesisMageCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNissaGenesisMageCard);

protected:
	bool BeforeUntapLands(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
	void OnLandsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_LandSelection;
	CCardFilter m_CreatureOrLandFilter;
};

class CSamutTheTestedCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSamutTheTestedCard);

protected:
	bool BeforeDoubleStrike(CAbilityAction* pAction);
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_CreatureOrPlaneswalkerFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

class CCrookOfCondemnationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCrookOfCondemnationCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CDaggerOfTheWorthyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDaggerOfTheWorthyCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const;
	bool BeforeAfflict(CAbilityAction* pAction);
};

class CGodPharaohsGiftCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGodPharaohsGiftCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CSunsetPyramidCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSunsetPyramidCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class CVisageOfBolasCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CVisageOfBolasCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

class CDesertsHoldCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CDesertsHoldCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);

	CCardFilter m_CardFilter;
};

class CFrayingSanityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFrayingSanityCard);

protected:
	bool CountMove(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeMill(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nCount;
};

class CImminentDoomCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CImminentDoomCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeDamage(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

class CRiddleformCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRiddleformCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);
};

class CSwarmIntelligenceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSwarmIntelligenceCard);

protected:
	bool SetTriggerContext(CTriggeredCopyCastAbility1::TriggerContextType& triggerContext, CCard* pCard) const;
};

class CTormentOfScarabsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTormentOfScarabsCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeChoice(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
	CCardFilter m_NonlandFilter;
};

class CUnquenchableThirstCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CUnquenchableThirstCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

// The card passes if it passes any of the comparers
struct OrCardComparer : public CardComparer
{
	OrCardComparer(CardComparer* pComparer1, CardComparer* pComparer2, CardComparer* pComparer3 = NULL)
		: m_pComparer1(pComparer1), m_pComparer2(pComparer2), m_pComparer3(pComparer3)
	{}

	virtual bool operator()(const CCard* value) const
	{
		return m_pComparer1->operator()(value) || m_pComparer2->operator()(value) ||
			(m_pComparer3.get() && m_pComparer3->operator()(value));
	}

	virtual OrCardComparer* Clone() const
	{
		return new OrCardComparer(m_pComparer1->Clone(), m_pComparer2->Clone(),
			m_pComparer3.get() ? m_pComparer3->Clone() : NULL);
	}

protected:
	std::auto_ptr<CardComparer> m_pComparer1;
	std::auto_ptr<CardComparer> m_pComparer2;
	std::auto_ptr<CardComparer> m_pComparer3;
};

// The card passes if it passes both comparers
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

class CAppealAuthorityCard : public CCard
{
	DECLARE_CARD_CSTOR(CAppealAuthorityCard);

protected:
	bool BeforeAppeal(CAbilityAction* pAction);
	bool BeforeAuthority(CAbilityAction* pAction);
};

class CBeneathTheSandsCard : public CCard
{
	DECLARE_CARD_CSTOR(CBeneathTheSandsCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CBontusLastReckoningCard : public CCard
{
	DECLARE_CARD_CSTOR(CBontusLastReckoningCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CClaimFameCard : public CCard
{
	DECLARE_CARD_CSTOR(CClaimFameCard);

protected:
	bool BeforeFame(CAbilityAction* pAction);
};

class CConsignOblivionCard : public CCard
{
	DECLARE_CARD_CSTOR(CConsignOblivionCard);
};

class CCrashThroughCard : public CCard
{
	DECLARE_CARD_CSTOR(CCrashThroughCard);

protected:
	bool BeforeTrample(CAbilityAction* pAction);
};

class CDoomfallCard : public CCard
{
	DECLARE_CARD_CSTOR(CDoomfallCard);

protected:
	bool BeforeExileCreature(CAbilityAction* pAction);

	CCardFilter m_NonlandFilter;
};

class CFarmMarketCard : public CCard
{
	DECLARE_CARD_CSTOR(CFarmMarketCard);

protected:
	bool BeforeMarket(CAbilityAction* pAction);
};

class CGrindDustCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrindDustCard);
};

class CHourOfDevastationCard : public CCard
{
	DECLARE_CARD_CSTOR(CHourOfDevastationCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CHourOfEternityCard : public CCard
{
	DECLARE_CARD_CSTOR(CHourOfEternityCard);

protected:
	bool BeforeCopies(CAbilityAction* pAction);
};

class CHourOfPromiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CHourOfPromiseCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CHourOfRevelationCard : public CCard
{
	DECLARE_CARD_CSTOR(CHourOfRevelationCard);

protected:
	BOOL HasTenNonlandPermanents(BOOL bIncludeTricks);
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CInfernoJetCard : public CCard
{
	DECLARE_CARD_CSTOR(CInfernoJetCard);
};

class CKefnetsLastWordCard : public CCard
{
	DECLARE_CARD_CSTOR(CKefnetsLastWordCard);

protected:
	bool BeforeControl(CAbilityAction* pAction);
};

class CLeaveChanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CLeaveChanceCard);

protected:
	bool BeforeChance(CAbilityAction* pAction);
};

class CLethalStingCard : public CCard
{
	DECLARE_CARD_CSTOR(CLethalStingCard);

protected:
	CCardFilter m_CreatureFilter;
};

class CLilianasDefeatCard : public CCard
{
	DECLARE_CARD_CSTOR(CLilianasDefeatCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CNissasDefeatCard : public CCard
{
	DECLARE_CARD_CSTOR(CNissasDefeatCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CNissasEncouragementCard : public CCard
{
	DECLARE_CARD_CSTOR(CNissasEncouragementCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class COketrasLastMercyCard : public CCard
{
	DECLARE_CARD_CSTOR(COketrasLastMercyCard);

protected:
	bool BeforeLife(CAbilityAction* pAction);
};

class COvercomeCard : public CCard
{
	DECLARE_CARD_CSTOR(COvercomeCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CPuncturingBlowCard : public CCard
{
	DECLARE_CARD_CSTOR(CPuncturingBlowCard);
};

class CRazakethsRiteCard : public CCard
{
	DECLARE_CARD_CSTOR(CRazakethsRiteCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CReasonBelieveCard : public CCard
{
	DECLARE_CARD_CSTOR(CReasonBelieveCard);

protected:
	bool BeforeBelieve(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
};

class CRhonassLastStandCard : public CCard
{
	DECLARE_CARD_CSTOR(CRhonassLastStandCard);

protected:
	bool BeforeSkipUntap(CAbilityAction* pAction);
};

class CStruggleSurviveCard : public CCard
{
	DECLARE_CARD_CSTOR(CStruggleSurviveCard);

protected:
	bool BeforeStruggle(CAbilityAction* pAction);
	bool BeforeSurvive(CAbilityAction* pAction);
};

class CTormentOfHailfireCard : public CCard
{
	DECLARE_CARD_CSTOR(CTormentOfHailfireCard);

protected:
	bool BeforeTorment(CAbilityAction* pAction);
	void RequestChoice(CPlayer* pOpponent, int nRemaining);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
	CCardFilter m_NonlandFilter;
};

class CUncageTheMenagerieCard : public CCard
{
	DECLARE_CARD_CSTOR(CUncageTheMenagerieCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_SearchFilter;
};

class CUnconventionalTacticsCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnconventionalTacticsCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

class CAbradeCard : public CCard
{
	DECLARE_CARD_CSTOR(CAbradeCard);
};

class CActOfHeroismCard : public CCard
{
	DECLARE_CARD_CSTOR(CActOfHeroismCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CAmbuscadeCard : public CCard
{
	DECLARE_CARD_CSTOR(CAmbuscadeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CBlurOfBladesCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlurOfBladesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CChandrasDefeatCard : public CCard
{
	DECLARE_CARD_CSTOR(CChandrasDefeatCard);
};

class CCountervailingWindsCard : public CCard
{
	DECLARE_CARD_CSTOR(CCountervailingWindsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCounterSpell* m_pCounterSpell;
};

class CDjerusRenunciationCard : public CCard
{
	DECLARE_CARD_CSTOR(CDjerusRenunciationCard);
};

class CGideonsDefeatCard : public CCard
{
	DECLARE_CARD_CSTOR(CGideonsDefeatCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CGiftOfStrengthCard : public CCard
{
	DECLARE_CARD_CSTOR(CGiftOfStrengthCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CHourOfGloryCard : public CCard
{
	DECLARE_CARD_CSTOR(CHourOfGloryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CImaginaryThreatsCard : public CCard
{
	DECLARE_CARD_CSTOR(CImaginaryThreatsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CJacesDefeatCard : public CCard
{
	DECLARE_CARD_CSTOR(CJacesDefeatCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CLifeGoesOnCard : public CCard
{
	DECLARE_CARD_CSTOR(CLifeGoesOnCard);

protected:
	bool CountDeath(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolution(CAbilityAction* pAction);

	mutable int m_nDeathTurn;
};

class COpenFireCard : public CCard
{
	DECLARE_CARD_CSTOR(COpenFireCard);
};

class CRefuseCooperateCard : public CCard
{
	DECLARE_CARD_CSTOR(CRefuseCooperateCard);

protected:
	bool BeforeRefuse(CAbilityAction* pAction);
};

class CSupremeWillCard : public CCard
{
	DECLARE_CARD_CSTOR(CSupremeWillCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
};

class CTormentOfVenomCard : public CCard
{
	DECLARE_CARD_CSTOR(CTormentOfVenomCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
	CCardFilter m_NonlandFilter;
};

class CTragicLessonCard : public CCard
{
	DECLARE_CARD_CSTOR(CTragicLessonCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
};

class CWithoutWeaknessCard : public CCard
{
	DECLARE_CARD_CSTOR(CWithoutWeaknessCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

class CAdornedPouncerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAdornedPouncerCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CAngelOfCondemnationCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfCondemnationCard);

protected:
	bool BeforeFlicker(CAbilityAction* pAction);
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CAngelOfTheGodPharaohCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfTheGodPharaohCard);
};

class CAvenOfEnduringHopeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenOfEnduringHopeCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CCrestedSunmareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCrestedSunmareCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
};

class CDauntlessAvenCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDauntlessAvenCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CDisposalMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDisposalMummyCard);
};

class CDjeruWithEyesOpenCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDjeruWithEyesOpenCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_PlaneswalkerFilter;
};

class CDutifulServantsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDutifulServantsCard);
};

class CGodPharaohsFaithfulCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGodPharaohsFaithfulCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CMummyParamountCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMummyParamountCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class COketrasAvengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COketrasAvengerCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CSolitaryCamelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSolitaryCamelCard);
};

class CSteadfastSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteadfastSentinelCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CStewardOfSolidarityCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStewardOfSolidarityCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CSunscourgeChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunscourgeChampionCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CVizierOfTheTrueCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVizierOfTheTrueCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

class CAvidReclaimerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAvidReclaimerCard);
};

class CBitterbowSharpshootersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBitterbowSharpshootersCard);
};

class CBrambleweftBehemothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrambleweftBehemothCard);
};

class CDevoteeOfStrengthCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDevoteeOfStrengthCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CDuneDivinerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDuneDivinerCard);

protected:
	CCardFilter m_DesertFilter;
};

class CFeralProwlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFeralProwlerCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CFrilledSandwallaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrilledSandwallaCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CHarrierNagaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHarrierNagaCard);
};

class CHopeTenderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHopeTenderCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);
};

class CMajesticMyriarchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMajesticMyriarchCard);

protected:
	bool BeforeKeywords(CAbilityAction* pAction);
};

class COasisRitualistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COasisRitualistCard);
};

class CPrideSovereignCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPrideSovereignCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

class CQuarryBeetleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CQuarryBeetleCard);
};

class CRampagingHippoCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRampagingHippoCard);
};

class CRamunapExcavatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRamunapExcavatorCard);
};

class CRamunapHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRamunapHydraCard);
};

class CResilientKhenraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CResilientKhenraCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CRhonassStalwartCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRhonassStalwartCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
	CCardFilter m_CanBlockFilter;
};

class CSidewinderNagaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSidewinderNagaCard);
};

class CSifterWurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSifterWurmCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

class CTenaciousHunterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTenaciousHunterCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

// The creature's power is less than or equal to the reference creature's current power
struct PowerAtMostComparer : public CardComparer
{
	PowerAtMostComparer(const CCreatureCard* pReference) : m_pReference(pReference) {}

	virtual bool operator()(const CCard* value) const
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(value);
		return pCreature && pCreature->GetPower() <= m_pReference->GetPower();
	}

	virtual PowerAtMostComparer* Clone() const
	{
		return new PowerAtMostComparer(m_pReference);
	}

protected:
	const CCreatureCard* m_pReference;
};

class CBurningFistMinotaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBurningFistMinotaurCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CChaosMawCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChaosMawCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CDefiantKhenraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDefiantKhenraCard);
};

class CEarthshakerKhenraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEarthshakerKhenraCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CFerventPaincasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFerventPaincasterCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);
};

class CFirebrandArcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFirebrandArcherCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CFrontlineDevastatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrontlineDevastatorCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CAfflictSupport m_Afflict;
};

class CGildedCerodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGildedCerodonCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
};

class CGraniticTitanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGraniticTitanCard);
};

class CKhenraScrapperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKhenraScrapperCard);

protected:
	bool BeforeExert(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CMagmarothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMagmarothCard);

protected:
	bool BeforeAddCounter(CAbilityAction* pAction);
	bool BeforeRemoveCounter(CAbilityAction* pAction);
};

class CManticoreEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CManticoreEternalCard);

protected:
	CAfflictSupport m_Afflict;
};

class CNehebTheEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNehebTheEternalCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeMana(CAbilityAction* pAction);

	CAfflictSupport m_Afflict;
};

class CSandStranglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSandStranglerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CThornedMolochCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThornedMolochCard);

protected:
	bool BeforeFirstStrike(CAbilityAction* pAction);
};

class CWildfireEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWildfireEternalCard);

protected:
	CAfflictSupport m_Afflict;
};

class CZealotOfTheGodPharaohCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CZealotOfTheGodPharaohCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

// The card has a cycling ability
struct HasCyclingComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		for (int i = 0; i < value->GetAbilityCount(); ++i)
			if (dynamic_cast<const CCyclingSpell*>(value->GetAbility(i)))
				return true;
		return false;
	}

	virtual HasCyclingComparer* Clone() const
	{
		return new HasCyclingComparer();
	}
};

class CAccursedHordeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAccursedHordeCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CAmmitEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAmmitEternalCard);

protected:
	bool BeforeAddCounter(CAbilityAction* pAction);
	bool BeforeRemoveCounters(CAbilityAction* pAction);

	CAfflictSupport m_Afflict;
};

class CApocalypseDemonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CApocalypseDemonCard);

protected:
	bool BeforeChoice(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
	CCardFilter m_OtherCreatureFilter;
};

class CBanewhipPunisherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBanewhipPunisherCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CCarrionScreecherCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCarrionScreecherCard);
};

class CDreamstealerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDreamstealerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction);

	CEmbalmSupport m_Embalm;
};

class CGrislySurvivorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrislySurvivorCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CKhenraEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKhenraEternalCard);

protected:
	CAfflictSupport m_Afflict;
};

class CLurchingRotbeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLurchingRotbeastCard);
};

class CMaraudingBoneslasherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMaraudingBoneslasherCard);
};

class CMercilessEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMercilessEternalCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CAfflictSupport m_Afflict;
};

class CMoaningWallCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMoaningWallCard);
};

class CRazakethTheFoulbloodedCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRazakethTheFoulbloodedCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

class CRuinRatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRuinRatCard);
};

class CScroungerOfSoulsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScroungerOfSoulsCard);
};

class CVileManifestationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVileManifestationCard);
};

class CWaspOfTheBitterEndCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWaspOfTheBitterEndCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CWretchedCamelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWretchedCamelCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

// The card has an embalm or eternalize ability (its text starts with "Embalm" or "Eternalize", as CEmbalmSupport)
struct HasEmbalmComparer : public CardComparer
{
	virtual bool operator()(const CCard* value) const
	{
		for (int i = 0; i < value->GetAbilityCount(); ++i)
		{
			CString strText = value->GetAbility(i)->GetAbilityText();
			if (strText.Find(_T("Embalm")) == 0 || strText.Find(_T("Eternalize")) == 0)
				return true;
		}
		return false;
	}

	virtual HasEmbalmComparer* Clone() const
	{
		return new HasEmbalmComparer();
	}
};

class CAerialGuideCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAerialGuideCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

class CAvenReedstalkerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenReedstalkerCard);
};

class CChampionOfWitsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChampionOfWitsCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CCunningSurvivorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCunningSurvivorCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CEternalOfHarshTruthsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEternalOfHarshTruthsCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDraw(CAbilityAction* pAction);

	CAfflictSupport m_Afflict;
};

class CNimbleObstructionistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNimbleObstructionistCard);
};

class COminousSphinxCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(COminousSphinxCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

class CProvenCombatantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CProvenCombatantCard);

protected:
	CEmbalmSupport m_Embalm;
};

class CSeerOfTheLastTomorrowCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSeerOfTheLastTomorrowCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CSinuousStrikerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSinuousStrikerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CEmbalmSupport m_Embalm;
};

class CSpellweaverEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpellweaverEternalCard);

protected:
	CAfflictSupport m_Afflict;
};

class CStripedRiverwinderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStripedRiverwinderCard);
};

class CUneshCriosphinxSovereignCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CUneshCriosphinxSovereignCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
	void OnPileSeparated(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnPileChosen(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_SeparateSelection;
	CSelectionSupport m_PileSelection;
	CCountedCardContainer m_Pile1;
	CCountedCardContainer m_Pile2;
};

class CVizierOfTheAnointedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVizierOfTheAnointedCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_EmbalmFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored creatures

class CBloodwaterEntityCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodwaterEntityCard);
};

class CObeliskSpiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CObeliskSpiderCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::CreatureEventCallback,
						   &CWhenSelfDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeCounter(TriggeredAbility::TriggeredActionType* pAction);
};

class CResoluteSurvivorsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CResoluteSurvivorsCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);

	CExertSupport m_Exert;
};

class CRiverHoopoeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRiverHoopoeCard);
};

class CTheLocustGodCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTheLocustGodCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

class CTheScarabGodCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTheScarabGodCard);

protected:
	bool BeforeUpkeep(CAbilityAction* pAction);
	bool BeforeCopy(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

class CTheScorpionGodCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTheScorpionGodCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

class CUnravelingMummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUnravelingMummyCard);

protected:
	bool BeforeLifelink(CAbilityAction* pAction);
	bool BeforeDeathtouch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
// Colorless creatures

class CGravenAbominationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGravenAbominationCard);
};

class CHollowOneCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHollowOneCard);
};

class CWallOfForgottenPharaohsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWallOfForgottenPharaohsCard);

protected:
	BOOL HasDesertCondition(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
