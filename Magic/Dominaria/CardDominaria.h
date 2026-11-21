#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
// Helpers (from Ixalan, see no_vale/PATRONES_MOTOR.md)

class CTransformArtifactBase : public CDoubleFacedInPlaySpellCard
{
protected:
	CTransformArtifactBase(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCostText, LPCTSTR strBackName,
		CardType cardType = CardType::Artifact);

	void SetFace(CAbility* pAbility, BOOL bFirstFace);
	void AddBackManaAbility(LPCTSTR strMana);
	void DoTransform();
	BOOL IsFirstFaceInPlay() const;
};

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

// Comparers (from CardRivalsOfIxalan.h)
// Comparers (from CardIxalan.h)
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

// The controller of the card has the city's blessing
struct CityBlessingComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetController() && pCard->GetController()->HasCityBlessing();
	}

	virtual CityBlessingComparer* Clone() const
	{
		return new CityBlessingComparer();
	}
};

// A land that is the first one with its name among the lands on its battlefield (to count differently named lands)
struct FirstNamedLandComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		if (!pCard->GetCardType().IsLand() || pCard->GetZoneId() != ZoneId::Battlefield)
			return false;

		CZone* pZone = pCard->GetController()->GetZoneById(ZoneId::Battlefield);
		CString strName = pCard->GetPrintedCardName();
		for (int i = 0; i < pZone->GetSize(); ++i)
		{
			const CCard* pOther = pZone->GetAt(i);
			if (pOther == pCard)
				return true;
			if (pOther->GetCardType().IsLand() && pOther->GetPrintedCardName() == strName)
				return false;
		}
		return true;
	}

	virtual FirstNamedLandComparer* Clone() const
	{
		return new FirstNamedLandComparer();
	}
};

// A creature whose power is greater than or equal to the life total of the controller of pSource (Blazing Hope)
struct PowerAtLeastLifeComparer : public CardComparer
{
	PowerAtLeastLifeComparer(const CCard* pSource)
		: m_pSource(pSource)
	{}

	virtual bool operator()(const CCard* pCard) const
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
		if (!pCreature || !pCard->GetCardType().IsCreature() || !m_pSource->GetController())
			return false;
		return (int)pCreature->GetPower() >= (int)m_pSource->GetController()->GetLife();
	}

	virtual PowerAtLeastLifeComparer* Clone() const
	{
		return new PowerAtLeastLifeComparer(m_pSource);
	}

protected:
	const CCard* m_pSource;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

class CCabalStrongholdCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CCabalStrongholdCard);
};

class CMemorialToFollyCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMemorialToFollyCard);
};

class CMemorialToGeniusCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMemorialToGeniusCard);
};

class CMemorialToGloryCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMemorialToGloryCard);
};

class CMemorialToUnityCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMemorialToUnityCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
};

class CMemorialToWarCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMemorialToWarCard);
};

class CZhalfirinVoidCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CZhalfirinVoidCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CChandraBoldPyromancerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraBoldPyromancerCard);

protected:
	bool BeforeMana(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

class CJayaBallardCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJayaBallardCard);

protected:
	bool BeforeMana(CAbilityAction* pAction);
	bool BeforeDiscard(CAbilityAction* pAction);
	void OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CKarnScionOfUrzaCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CKarnScionOfUrzaCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
	void OnRevealedSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeReturn(CAbilityAction* pAction);
	void OnSilverSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_RevealedSelection;
	CSelectionSupport m_SilverSelection;
};

class CTeferiHeroOfDominariaCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTeferiHeroOfDominariaCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeTuck(CAbilityAction* pAction);
};

class CTeferiTimebenderCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTeferiTimebenderCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

// A creature with the greatest power among creatures its controller controls (Triumph of Gerrard)
struct GreatestPowerComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
		if (!pCreature || !pCard->GetCardType().IsCreature() || pCard->GetZoneId() != ZoneId::Battlefield)
			return false;

		CZone* pBattlefield = pCard->GetController()->GetZoneById(ZoneId::Battlefield);
		for (int i = 0; i < pBattlefield->GetSize(); ++i)
		{
			const CCreatureCard* pOther = dynamic_cast<const CCreatureCard*>(pBattlefield->GetAt(i));
			if (pOther && pOther->GetCardType().IsCreature() && (int)pOther->GetPower() > (int)pCreature->GetPower())
				return false;
		}
		return true;
	}

	virtual GreatestPowerComparer* Clone() const
	{
		return new GreatestPowerComparer();
	}
};

class CArcaneFlightCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CArcaneFlightCard);
};

class CChainersTormentCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CChainersTormentCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
	bool BeforeHorror(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CCuratorsWardCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCuratorsWardCard);
};

class CDemonicVigorCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CDemonicVigorCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(TriggeredAbility::TriggeredActionType* pAction);
};

class CDubCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CDubCard);
};

class CFallOfTheThranCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFallOfTheThranCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CFrenziedRageCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CFrenziedRageCard);
};

class CFungalPlotsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFungalPlotsCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);

	CCardFilter m_CreatureCardFilter;
	CCardFilter m_SaprolingFilter;
};

class CHaphazardBombardmentCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHaphazardBombardmentCard);

protected:
	bool BeforeAim(CAbilityAction* pAction);
	void OnPermanentsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDestroy(CAbilityAction* pAction);
	void GetAimed(CPlayer* pController, CCountedCardContainer& aimed) const;

	CSelectionSupport m_PermanentSelection;
};

class CHistoryOfBenaliaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHistoryOfBenaliaCard);

protected:
	bool BeforeKnight(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CInBolassClutchesCard : public CCard
{
	DECLARE_CARD_CSTOR(CInBolassClutchesCard);
};

class COathOfTeferiCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfTeferiCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class COnSerrasWingsCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(COnSerrasWingsCard);
};

class CPhyrexianScripturesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPhyrexianScripturesCard);

protected:
	bool BeforeArtifact(CAbilityAction* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
	bool BeforeExile(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CRiteOfBelzenlokCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRiteOfBelzenlokCard);

protected:
	bool BeforeClerics(CAbilityAction* pAction);
	bool BeforeDemon(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CSealAwayCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSealAwayCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CSongOfFreyaliseCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSongOfFreyaliseCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CTheAntiquitiesWarCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheAntiquitiesWarCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
	bool BeforeAnimate(CAbilityAction* pAction);

	CCardFilter m_ArtifactFilter;
	CSagaSupport m_Saga;
};

class CTheEldestRebornCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheEldestRebornCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool BeforeDiscard(CAbilityAction* pAction);
	bool BeforeReanimate(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCardFilter m_SacrificeFilter;
	CSelectionSupport m_CardSelection;
	CSagaSupport m_Saga;
};

class CTheFirstEruptionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheFirstEruptionCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeMana(CAbilityAction* pAction);
	bool BeforeSacrifice(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CTheFlameOfKeldCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheFlameOfKeldCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeChapter3(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CTheMendingOfDominariaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheMendingOfDominariaCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
	bool BeforeLands(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CTheMirariConjectureCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheMirariConjectureCard);

protected:
	bool BeforeInstant(CAbilityAction* pAction);
	bool BeforeSorcery(CAbilityAction* pAction);
	bool BeforeChapter3(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

class CTimeOfIceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTimeOfIceCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
	bool BeforeBounce(CAbilityAction* pAction);
	bool BeforeRelease(CAbilityAction* pAction);

	CCountedCardContainer_ m_Frozen;
	CSagaSupport m_Saga;
};

class CTriumphOfGerrardCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTriumphOfGerrardCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeKeywords(CAbilityAction* pAction);

	CSagaSupport m_Saga;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

class CBlackbladeReforgedCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBlackbladeReforgedCard);

protected:
	bool BeforeEquip(CAbilityAction* pAction);
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
};

class CBloodtallowCandleCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBloodtallowCandleCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

class CForebearsBladeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CForebearsBladeCard);
};

class CJoustingLanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CJoustingLanceCard);
};

class CMoxAmberCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMoxAmberCard);

protected:
	BOOL HasColor(CardType color) const;
	BOOL HasWhite(BOOL bIncludeTricks) { return HasColor(CardType::White); }
	BOOL HasBlue(BOOL bIncludeTricks) { return HasColor(CardType::Blue); }
	BOOL HasBlack(BOOL bIncludeTricks) { return HasColor(CardType::Black); }
	BOOL HasRed(BOOL bIncludeTricks) { return HasColor(CardType::Red); }
	BOOL HasGreen(BOOL bIncludeTricks) { return HasColor(CardType::Green); }
};

class CNavigatorsCompassCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CNavigatorsCompassCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CPowerstoneShardCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPowerstoneShardCard);

protected:
	int CountShards() const;
	BOOL Has1(BOOL bIncludeTricks) { return CountShards() == 1; }
	BOOL Has2(BOOL bIncludeTricks) { return CountShards() == 2; }
	BOOL Has3(BOOL bIncludeTricks) { return CountShards() == 3; }
	BOOL Has4(BOOL bIncludeTricks) { return CountShards() >= 4; }
};

class CShortSwordCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CShortSwordCard);
};

class CSorcerersWandCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSorcerersWandCard);

protected:
	bool BeforeEquip(CAbilityAction* pAction);
	counted_ptr<CAbility> CreateWandAbility(CCard* pCard);
};

class CThranTemporalGatewayCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CThranTemporalGatewayCard);

protected:
	bool BeforePut(CAbilityAction* pAction);

	CCardFilter m_HistoricPermanentFilter;
};

class CUrzasTomeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CUrzasTomeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CWeatherlightCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWeatherlightCard);

protected:
	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

// A legendary sorcery: "You may cast a legendary sorcery only if you control a legendary creature or planeswalker."
// The derived card calls SetLegendary for each of its spells.
class CLegendarySorceryCard : public CCard
{
protected:
	CLegendarySorceryCard(CGame* pGame, LPCTSTR strCardName, UINT nID)
		: CCard(pGame, strCardName, CardType::Sorcery | CardType::Legendary, nID)
	{
	}

	void SetLegendary(CAbility* pSpell);
	BOOL CanCastLegendary(BOOL bIncludeTricks);
};

class CAdventurousImpulseCard : public CCard
{
	DECLARE_CARD_CSTOR(CAdventurousImpulseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_Filter;
};

class CBoardTheWeatherlightCard : public CCard
{
	DECLARE_CARD_CSTOR(CBoardTheWeatherlightCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_Filter;
};

class CBrokenBondCard : public CCard
{
	DECLARE_CARD_CSTOR(CBrokenBondCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CCallTheCavalryCard : public CCard
{
	DECLARE_CARD_CSTOR(CCallTheCavalryCard);
};

class CChandrasOutburstCard : public CCard
{
	DECLARE_CARD_CSTOR(CChandrasOutburstCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CDivestCard : public CCard
{
	DECLARE_CARD_CSTOR(CDivestCard);

protected:
	CCardFilter m_Filter;
};

class CEviscerateCard : public CCard
{
	DECLARE_CARD_CSTOR(CEviscerateCard);
};

class CFieryInterventionCard : public CCard
{
	DECLARE_CARD_CSTOR(CFieryInterventionCard);
};

class CFightWithFireCard : public CCard
{
	DECLARE_CARD_CSTOR(CFightWithFireCard);
};

class CFinalPartingCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinalPartingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CGoblinBarrageCard : public CCard
{
	DECLARE_CARD_CSTOR(CGoblinBarrageCard);

protected:
	bool BeforeKicked(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

class CGrowFromTheAshesCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrowFromTheAshesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CJayasImmolatingInfernoCard : public CLegendarySorceryCard
{
	DECLARE_CARD_CSTOR(CJayasImmolatingInfernoCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CKamahlsDruidicVowCard : public CLegendarySorceryCard
{
	DECLARE_CARD_CSTOR(CKamahlsDruidicVowCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CKarnsTemporalSunderingCard : public CLegendarySorceryCard
{
	DECLARE_CARD_CSTOR(CKarnsTemporalSunderingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPrimevalsGloriousRebirthCard : public CLegendarySorceryCard
{
	DECLARE_CARD_CSTOR(CPrimevalsGloriousRebirthCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSaprolingMigrationCard : public CCard
{
	DECLARE_CARD_CSTOR(CSaprolingMigrationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CSeismicShiftCard : public CCard
{
	DECLARE_CARD_CSTOR(CSeismicShiftCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSettleTheScoreCard : public CCard
{
	DECLARE_CARD_CSTOR(CSettleTheScoreCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnPlaneswalkerSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PlaneswalkerSelection;
};

class CSoulSalvageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSoulSalvageCard);
};

class CSylvanAwakeningCard : public CCard
{
	DECLARE_CARD_CSTOR(CSylvanAwakeningCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CTemporalMachinationsCard : public CCard
{
	DECLARE_CARD_CSTOR(CTemporalMachinationsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CUrzasRuinousBlastCard : public CLegendarySorceryCard
{
	DECLARE_CARD_CSTOR(CUrzasRuinousBlastCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CWarlordsFuryCard : public CCard
{
	DECLARE_CARD_CSTOR(CWarlordsFuryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CWeightOfMemoryCard : public CCard
{
	DECLARE_CARD_CSTOR(CWeightOfMemoryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CYawgmothsVileOfferingCard : public CLegendarySorceryCard
{
	DECLARE_CARD_CSTOR(CYawgmothsVileOfferingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCardFilter m_Filter;
	CSelectionSupport m_CardSelection;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

class CAdamantWillCard : public CCard
{
	DECLARE_CARD_CSTOR(CAdamantWillCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CAncientAnimusCard : public CCard
{
	DECLARE_CARD_CSTOR(CAncientAnimusCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CArborArmamentCard : public CCard
{
	DECLARE_CARD_CSTOR(CArborArmamentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CBefuddleCard : public CCard
{
	DECLARE_CARD_CSTOR(CBefuddleCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CBlessedLightCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlessedLightCard);
};

class CBlessingOfBelzenlokCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlessingOfBelzenlokCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CBlinkOfAnEyeCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlinkOfAnEyeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CCastDownCard : public CCard
{
	DECLARE_CARD_CSTOR(CCastDownCard);
};

class CChargeCard : public CCard
{
	DECLARE_CARD_CSTOR(CChargeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CDarkBargainCard : public CCard
{
	DECLARE_CARD_CSTOR(CDarkBargainCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CFerventStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CFerventStrikeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CFungalInfectionCard : public CCard
{
	DECLARE_CARD_CSTOR(CFungalInfectionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CGiftOfGrowthCard : public CCard
{
	DECLARE_CARD_CSTOR(CGiftOfGrowthCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CHealingGraceCard : public CCard
{
	DECLARE_CARD_CSTOR(CHealingGraceCard);
};

class CInvokeTheDivineCard : public CCard
{
	DECLARE_CARD_CSTOR(CInvokeTheDivineCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPierceTheSkyCard : public CCard
{
	DECLARE_CARD_CSTOR(CPierceTheSkyCard);
};

class CRadiatingLightningCard : public CCard
{
	DECLARE_CARD_CSTOR(CRadiatingLightningCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CRunAmokCard : public CCard
{
	DECLARE_CARD_CSTOR(CRunAmokCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CShivanFireCard : public CCard
{
	DECLARE_CARD_CSTOR(CShivanFireCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CSporeSwarmCard : public CCard
{
	DECLARE_CARD_CSTOR(CSporeSwarmCard);
};

class CUnwindCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnwindCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnLandsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_LandSelection;
};

class CViciousOfferingCard : public CCard
{
	DECLARE_CARD_CSTOR(CViciousOfferingCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
	bool BeforeKicked(CAbilityAction* pAction);
};

class CWildOnslaughtCard : public CCard
{
	DECLARE_CARD_CSTOR(CWildOnslaughtCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CWizardsLightningCard : public CCard
{
	DECLARE_CARD_CSTOR(CWizardsLightningCard);

protected:
	BOOL ControlsWizard(BOOL bIncludeTricks);
};

class CWizardsRetortCard : public CCard
{
	DECLARE_CARD_CSTOR(CWizardsRetortCard);

protected:
	BOOL ControlsWizard(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

// A player controls a black permanent (Knight of Grace)
struct AnyBlackPermanentComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		CGame* pGame = pCard->GetGame();
		for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		{
			CZone* pBattlefield = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
			for (int i = 0; i < pBattlefield->GetSize(); ++i)
				if ((pBattlefield->GetAt(i)->GetCardType() & CardType::Black).Any())
					return true;
		}
		return false;
	}

	virtual AnyBlackPermanentComparer* Clone() const
	{
		return new AnyBlackPermanentComparer();
	}
};

class CAvenSentryCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenSentryCard);
};

class CBairdStewardOfArgiveCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBairdStewardOfArgiveCard);
};

class CBenalishHonorGuardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBenalishHonorGuardCard);
};

class CBenalishMarshalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBenalishMarshalCard);
};

class CDanithaCapashenParagonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDanithaCapashenParagonCard);
};

class CDaringArchaeologistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDaringArchaeologistCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
	bool BeforeCounter(CAbilityAction* pAction);
};

class CDauntlessBodyguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDauntlessBodyguardCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeIndestructible(CAbilityAction* pAction);

	CSelectionSupport m_CreatureSelection;
	CCountedCardContainer_ m_Chosen;
};

class CDAvenantTrapperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDAvenantTrapperCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CEvraHalcyonWitnessCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEvraHalcyonWitnessCard);

protected:
	bool BeforeExchange(CAbilityAction* pAction);
};

class CExcavationElephantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CExcavationElephantCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CKnightOfGraceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfGraceCard);

protected:
	CHexproofFromSupport m_HexproofFrom;
};

class CKnightOfNewBenaliaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfNewBenaliaCard);
};

class CKwendePrideOfFemerefCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKwendePrideOfFemerefCard);
};

class CLyraDawnbringerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLyraDawnbringerCard);
};

class CMesaUnicornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMesaUnicornCard);
};

class CPegasusCourserCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPegasusCourserCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

class CSanctumSpiritCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSanctumSpiritCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);

	CCardFilter m_HistoricFilter;
};

class CSergeantAtArmsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSergeantAtArmsCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeTokens(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CSerraDiscipleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSerraDiscipleCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CShalaiVoiceOfPlentyCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CShalaiVoiceOfPlentyCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

class CTesharAncestorsApostleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTesharAncestorsApostleCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_ReturnFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

class CBalothGorgerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBalothGorgerCard);

protected:
	CManaCost m_KickerCost;
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

class CElfhameDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElfhameDruidCard);
};

class CGaeasProtectorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGaeasProtectorCard);
};

class CGrunnTheLonelyKingCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrunnTheLonelyKingCard);

protected:
	CManaCost m_KickerCost;
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	bool BeforeDouble(CAbilityAction* pAction);
};

class CKrosanDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKrosanDruidCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeGainLife(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CLlanowarEnvoyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLlanowarEnvoyCard);
};

class CLlanowarScoutCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLlanowarScoutCard);

protected:
	bool BeforePutLand(CAbilityAction* pAction);
};

class CMammothSpiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMammothSpiderCard);
};

class CMarwynTheNurturerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMarwynTheNurturerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
	BOOL HasPower(int nPower) const;
	BOOL Has1(BOOL bIncludeTricks) { return HasPower(1); }
	BOOL Has2(BOOL bIncludeTricks) { return HasPower(2); }
	BOOL Has3(BOOL bIncludeTricks) { return HasPower(3); }
	BOOL Has4(BOOL bIncludeTricks) { return HasPower(4); }
	BOOL Has5(BOOL bIncludeTricks) { return HasPower(5); }
	BOOL Has6(BOOL bIncludeTricks) { return HasPower(6); }
};

class CMultaniYavimayasAvatarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMultaniYavimayasAvatarCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CPrimordialWurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPrimordialWurmCard);
};

class CSporecrownThallidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSporecrownThallidCard);
};

class CSteelLeafChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteelLeafChampionCard);

protected:
	CCardFilter m_BlockerFilter;
};

class CTerritorialAllosaurusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTerritorialAllosaurusCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeFight(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CUntamedKavuCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUntamedKavuCard);

protected:
	CManaCost m_KickerCost;
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

class CYavimayaSapherdCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYavimayaSapherdCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

// The card is a Saga (Keldon Warcaller)
struct SagaComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return CSagaSupport::Find(pCard) != NULL;
	}

	virtual SagaComparer* Clone() const
	{
		return new SagaComparer();
	}
};

// A creature blocked by two or more creatures (Rampaging Cyclops)
struct BlockedByTwoComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
		return pCreature && pCreature->GetBlockedByCount() >= 2;
	}

	virtual BlockedByTwoComparer* Clone() const
	{
		return new BlockedByTwoComparer();
	}
};

class CBloodstoneGoblinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodstoneGoblinCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforePump(CAbilityAction* pAction);
};

class CChampionOfTheFlameCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChampionOfTheFlameCard);
};

class CFirefistAdeptCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFirefistAdeptCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CGhituChroniclerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhituChroniclerCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CGhituJourneymageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhituJourneymageCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

class CGhituLavarunnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhituLavarunnerCard);
};

class CGoblinChainwhirlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinChainwhirlerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CKarplusanHoundCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKarplusanHoundCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CKeldonOverseerCard : public CHasteCreatureCard
{
	DECLARE_CARD_CSTOR(CKeldonOverseerCard);

protected:
	bool SetKickedContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);

	CManaCost m_KickerCost;
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

class CKeldonRaiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKeldonRaiderCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CKeldonWarcallerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKeldonWarcallerCard);

protected:
	bool BeforeLore(CAbilityAction* pAction);
};

class COrcishVandalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrcishVandalCard);
};

class CPyromanticPilgrimCard : public CHasteCreatureCard
{
	DECLARE_CARD_CSTOR(CPyromanticPilgrimCard);
};

class CRampagingCyclopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRampagingCyclopsCard);
};

class CSqueeTheImmortalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSqueeTheImmortalCard);
};

class CTwoHeadedGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTwoHeadedGiantCard);

protected:
	bool BeforeFlip(CAbilityAction* pAction);
};

class CValdukKeeperOfTheFlameCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CValdukKeeperOfTheFlameCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTokens(CAbilityAction* pAction);
};

class CVerixBladewingCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVerixBladewingCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeToken(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CWarcryPhoenixCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWarcryPhoenixCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

// Any player controls a white permanent (Knight of Malice)
struct AnyWhitePermanentComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		CGame* pGame = pCard->GetGame();
		for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		{
			CZone* pBattlefield = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
			for (int i = 0; i < pBattlefield->GetSize(); ++i)
				if ((pBattlefield->GetAt(i)->GetCardType() & CardType::White).Any())
					return true;
		}
		return false;
	}

	virtual AnyWhitePermanentComparer* Clone() const
	{
		return new AnyWhitePermanentComparer();
	}
};

class CCabalEvangelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCabalEvangelCard);
};

class CCabalPaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCabalPaladinCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CCaligoSkinWitchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCaligoSkinWitchCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDiscard(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CDeathbloomThallidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeathbloomThallidCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CDemonlordBelzenlokCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDemonlordBelzenlokCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CDreadShadeCard : public CPumpCreatureCard
{
	DECLARE_CARD_CSTOR(CDreadShadeCard);
};

class CDrudgeSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDrudgeSentinelCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CFeralAbominationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFeralAbominationCard);
};

class CJosuVessLichKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJosuVessLichKnightCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeTokens(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CKazarovSengirPurebloodCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKazarovSengirPurebloodCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CKnightOfMaliceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfMaliceCard);

protected:
	CHexproofFromSupport m_HexproofFrom;
};

class CLingeringPhantomCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLingeringPhantomCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);
};

class CRatColonyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRatColonyCard);
};

class CStrongholdConfessorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStrongholdConfessorCard);

protected:
	CManaCost m_KickerCost;
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

class CThallidOmnivoreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThallidOmnivoreCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforePumpSaproling(CAbilityAction* pAction);

	CCardFilter m_OtherFilter;
	CCardFilter m_SaprolingFilter;
};

class CThallidSoothsayerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThallidSoothsayerCard);
};

class CTorgaarFamineIncarnateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTorgaarFamineIncarnateCard);

protected:
	bool BeforeLife(CAbilityAction* pAction);
};

class CUrgorosTheEmptyOneCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CUrgorosTheEmptyOneCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction);
};

class CWhisperBloodLiturgistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWhisperBloodLiturgistCard);
};

class CWindgraceAcolyteCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWindgraceAcolyteCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CYargleGluttonOfUrborgCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYargleGluttonOfUrborgCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

class CAcademyDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAcademyDrakeCard);

protected:
	CManaCost m_KickerCost;
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

class CAcademyJourneymageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAcademyJourneymageCard);

protected:
	bool BeforeBounce(CAbilityAction* pAction);
	BOOL HasWizard(BOOL bIncludeTricks);
	BOOL HasNoWizard(BOOL bIncludeTricks);
};

class CArtificersAssistantCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArtificersAssistantCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

class CCloudreaderSphinxCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCloudreaderSphinxCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

class CColdWaterSnapperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CColdWaterSnapperCard);
};

class CDiligentExcavatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDiligentExcavatorCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CHomaridExplorerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHomaridExplorerCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CMerfolkTricksterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMerfolkTricksterCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CNaruMehaMasterWizardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNaruMehaMasterWizardCard);

protected:
	bool SetCopyContext(CTriggeredCopyCastAbility1::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

class CRelicRunnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRelicRunnerCard);

protected:
	bool BeforeUnblockable(CTriggeredAbility<>::TriggeredActionType* pAction);
};

class CSentinelOfThePearlTridentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSentinelOfThePearlTridentCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CSlinnVodaTheRisingDeepCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSlinnVodaTheRisingDeepCard);

protected:
	bool SetKickedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeBounce(CAbilityAction* pAction);

	CManaCost m_KickerCost;
};

class CTempestDjinnCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTempestDjinnCard);
};

class CTetsukoUmezawaFugitiveCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTetsukoUmezawaFugitiveCard);
};

class CTolarianScholarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTolarianScholarCard);
};

class CVodalianArcanistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVodalianArcanistCard);
};

class CZahidDjinnOfTheLampCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CZahidDjinnOfTheLampCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

class CAdelizTheCinderWindCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAdelizTheCinderWindCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CAmaranthineWallCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAmaranthineWallCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CArvadTheCursedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArvadTheCursedCard);
};

class CAryelKnightOfWindgraceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAryelKnightOfWindgraceCard);

protected:
	CCardFilter m_KnightFilter;
};

class CDarigaazReincarnatedCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDarigaazReincarnatedCard);
};

class CGarnaTheBloodflameCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGarnaTheBloodflameCard);
};

class CGrandWarlordRadhaCard : public CHasteCreatureCard
{
	DECLARE_CARD_CSTOR(CGrandWarlordRadhaCard);
};

class CGuardiansOfKoilosCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGuardiansOfKoilosCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CHallarTheFirefletcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHallarTheFirefletcherCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CHowlingGolemCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHowlingGolemCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CJhoirasFamiliarCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CJhoirasFamiliarCard);
};

class CJhoiraWeatherlightCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJhoiraWeatherlightCaptainCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CJodahArchmageEternalCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CJodahArchmageEternalCard);
};

class CMishrasSelfReplicatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMishrasSelfReplicatorCard);

protected:
	bool BeforeCopy(CAbilityAction* pAction);
};

class CNiambiFaithfulHealerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNiambiFaithfulHealerCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CPardicWandererCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPardicWandererCard);
};

class CRaffCapashenShipsMageCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRaffCapashenShipsMageCard);
};

class CShannaSisaysLegacyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShannaSisaysLegacyCard);

protected:
	CHexproofFromSupport m_HexproofFrom;
};

class CSkitteringSurveyorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkitteringSurveyorCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

class CSlimefootTheStowawayCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSlimefootTheStowawayCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDrain(CAbilityAction* pAction);
};

class CSparringConstructCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSparringConstructCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CTatyovaBenthicDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTatyovaBenthicDruidCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CTeferisSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTeferisSentinelCard);
};

class CTianaShipsCaretakerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTianaShipsCaretakerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(TriggeredAbility::TriggeredActionType* pAction);
};

class CTraxosScourgeOfKroogCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTraxosScourgeOfKroogCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

class CVoltaicServantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVoltaicServantCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
