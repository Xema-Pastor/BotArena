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

// Comparers (from CardM19.h)

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

// The card is colorless (Infernal Reckoning)
struct ColorlessComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		return !(pCard->GetCardType() & CardType::_ColorMask).Any();
	}

	virtual ColorlessComparer* Clone() const
	{
		return new ColorlessComparer();
	}
};

// The creature isn't enchanted or equipped (Novice Knight)
struct NotEnchantedOrEquippedComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		if (pCard->GetEnchantCount() > 0)
			return false;

		CGame* pGame = pCard->GetGame();
		for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
		{
			CZone* pBattlefield = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Battlefield);
			for (int i = 0; i < pBattlefield->GetSize(); ++i)
				if (pBattlefield->GetAt(i)->GetEquippedOn() == pCard)
					return false;
		}
		return true;
	}

	virtual NotEnchantedOrEquippedComparer* Clone() const
	{
		return new NotEnchantedOrEquippedComparer();
	}
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Guilds of Ravnica mechanics (see no_vale/PATRONES_MOTOR.md)

// A creature with less power than the given creature (Mentor)
struct LesserPowerComparer : public CardComparer
{
	LesserPowerComparer(const CCreatureCard* pCreature)
		: m_pCreature(pCreature)
	{}

	virtual bool operator()(const CCard* pCard) const
	{
		const CCreatureCard* pOther = dynamic_cast<const CCreatureCard*>(pCard);
		return pOther && pOther != m_pCreature && pOther->GetPower() < m_pCreature->GetPower();
	}

	virtual LesserPowerComparer* Clone() const
	{
		return new LesserPowerComparer(m_pCreature);
	}

protected:
	const CCreatureCard* m_pCreature;
};

// Mentor (Whenever this creature attacks, put a +1/+1 counter on target attacking creature with lesser power.)
// The creature has a member CMentorSupport m_Mentor, initialized with m_Mentor(this), and calls m_Mentor.AddMentorAbility()
// in its constructor (as CExploreSupport in the core).
class CMentorSupport
{
public:
	CMentorSupport(CCreatureCard* pCreature);

	CAbility* AddMentorAbility();

protected:
	bool OnMentorResolving(CAbilityAction* pAction);

	CCreatureCard* m_pCreature;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

class CGatewayPlazaCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CGatewayPlazaCard);

private:
	CCard* CreateTemporaryAbility();
	void PreRemoveAbilityCallback(CCard* pCard, CPlayer* pTriggeredPlayer);
};

class CGuildmagesForumCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CGuildmagesForumCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CRalCallerOfStormsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CRalCallerOfStormsCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

class CRalIzzetViceroyCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CRalIzzetViceroyCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

class CVraskaGolgariQueenCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVraskaGolgariQueenCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_OtherPermanentFilter;
};

class CVraskaRegalGorgonCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVraskaRegalGorgonCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

class CCandlelightVigilCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCandlelightVigilCard);
};

class CCaptureSphereCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCaptureSphereCard);

protected:
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
};

class CConclaveTribunalCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CConclaveTribunalCard);

protected:
	void AddConvokeSpell(LPCTSTR strCost, int nTapped);
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CDawnOfHopeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDawnOfHopeCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

class CDemotionCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CDemotionCard);

protected:
	CCardFilter m_CardFilter;
};

class CDisinformationCampaignCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDisinformationCampaignCard);

protected:
	bool BeforeDrawDiscard(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

class CDrownedSecretsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDrownedSecretsCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CEnhancedSurveillanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEnhancedSurveillanceCard);

protected:
	bool BeforeShuffle(CAbilityAction* pAction);
};

class CFiremindsResearchCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFiremindsResearchCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CGuildSummitCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGuildSummitCard);

protected:
	bool BeforeTapGates(CAbilityAction* pAction);
	void OnGatesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeDraw(CAbilityAction* pAction);

	CSelectionSupport m_GateSelection;
};

class CStreetRiotCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CStreetRiotCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CUrbanUtopiaCard : public CCard
{
	DECLARE_CARD_CSTOR(CUrbanUtopiaCard);

protected:
	counted_ptr<CAbility> CreateEnchantAbility(CCard* pEnchantedCard, CCard* pEnchantCard, ContextValue_& contextValue);
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

// Lockets: "{T}: Add {C1} or {C2}. {C1/C2}{C1/C2}{C1/C2}{C1/C2}, {T}, Sacrifice this artifact: Draw two cards."
class CLocketCard : public CInPlaySpellCard
{
protected:
	CLocketCard(CGame* pGame, LPCTSTR strName, UINT nID, LPCTSTR strColor1, LPCTSTR strColor2);
};

class CBorosLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CBorosLocketCard);
};

class CDimirLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CDimirLocketCard);
};

class CGolgariLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CGolgariLocketCard);
};

class CIzzetLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CIzzetLocketCard);
};

class CSelesnyaLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CSelesnyaLocketCard);
};

class CGlaiveOfTheGuildpactCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGlaiveOfTheGuildpactCard);

protected:
	bool BeforeEquip(CAbilityAction* pAction);
	counted_ptr<CAbility> CreateEquipmentAbility(CCard* pCard);
};

class CSilentDartCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSilentDartCard);
};

class CWandOfVertebraeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWandOfVertebraeCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
	bool BeforeShuffle(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

class CBeaconBoltCard : public CCard
{
	DECLARE_CARD_CSTOR(CBeaconBoltCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CCamaraderieCard : public CCard
{
	DECLARE_CARD_CSTOR(CCamaraderieCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CCircuitousRouteCard : public CCard
{
	DECLARE_CARD_CSTOR(CCircuitousRouteCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_LandFilter;
};

class CCitywideBustCard : public CCard
{
	DECLARE_CARD_CSTOR(CCitywideBustCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CConniveConcoctCard : public CCard
{
	DECLARE_CARD_CSTOR(CConniveConcoctCard);

protected:
	bool BeforeConnive(CAbilityAction* pAction);
	bool BeforeConcoct(CAbilityAction* pAction);
};

class CCosmotronicWaveCard : public CCard
{
	DECLARE_CARD_CSTOR(CCosmotronicWaveCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CCreepingChillCard : public CCard
{
	DECLARE_CARD_CSTOR(CCreepingChillCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
	bool BeforeExileDrain(CAbilityAction* pAction);
};

class CDeadlyVisitCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeadlyVisitCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CDeafeningClarionCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeafeningClarionCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeLifelink(CAbilityAction* pAction);
	bool BeforeBoth(CAbilityAction* pAction);
};

class CDirectCurrentCard : public CCard
{
	DECLARE_CARD_CSTOR(CDirectCurrentCard);
};

class CDiscoveryDispersalCard : public CCard
{
	DECLARE_CARD_CSTOR(CDiscoveryDispersalCard);

protected:
	bool BeforeDiscovery(CAbilityAction* pAction);
	bool BeforeDispersal(CAbilityAction* pAction);
};

class CFindFinalityCard : public CCard
{
	DECLARE_CARD_CSTOR(CFindFinalityCard);

protected:
	bool BeforeFind(CAbilityAction* pAction);
	bool BeforeFinality(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void ShrinkAll();

	CSelectionSupport m_CreatureSelection;
};

class CFlowerFlourishCard : public CCard
{
	DECLARE_CARD_CSTOR(CFlowerFlourishCard);

protected:
	bool BeforeFlower(CAbilityAction* pAction);
	bool BeforeFlourish(CAbilityAction* pAction);

	CCardFilter m_LandFilter;
};

class CGirdForBattleCard : public CCard
{
	DECLARE_CARD_CSTOR(CGirdForBattleCard);
};

class CGraviticPunchCard : public CCard
{
	DECLARE_CARD_CSTOR(CGraviticPunchCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CGruesomeMenagerieCard : public CCard
{
	DECLARE_CARD_CSTOR(CGruesomeMenagerieCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_Filter1;
	CCardFilter m_Filter2;
	CCardFilter m_Filter3;
};

class CLavaCoilCard : public CCard
{
	DECLARE_CARD_CSTOR(CLavaCoilCard);
};

class CMaximizeAltitudeCard : public CCard
{
	DECLARE_CARD_CSTOR(CMaximizeAltitudeCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CMaximizeVelocityCard : public CCard
{
	DECLARE_CARD_CSTOR(CMaximizeVelocityCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CMephiticVaporsCard : public CCard
{
	DECLARE_CARD_CSTOR(CMephiticVaporsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CNeverHappenedCard : public CCard
{
	DECLARE_CARD_CSTOR(CNeverHappenedCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

class CNotionRainCard : public CCard
{
	DECLARE_CARD_CSTOR(CNotionRainCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPrecisionBoltCard : public CCard
{
	DECLARE_CARD_CSTOR(CPrecisionBoltCard);
};

class CQuasiduplicateCard : public CCard
{
	DECLARE_CARD_CSTOR(CQuasiduplicateCard);

protected:
	bool BeforeCopy(CAbilityAction* pAction);
};

class CResponseResurgenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CResponseResurgenceCard);

protected:
	bool BeforeResurgence(CAbilityAction* pAction);
};

class CRitualOfSootCard : public CCard
{
	DECLARE_CARD_CSTOR(CRitualOfSootCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CSeveredStrandsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSeveredStrandsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSproutingRenewalCard : public CCard
{
	DECLARE_CARD_CSTOR(CSproutingRenewalCard);

protected:
	void AddModeSpells(LPCTSTR strCost, int nTapped);
	bool BeforeToken(CAbilityAction* pAction);
};

class CSwornCompanionsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSwornCompanionsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CThoughtErasureCard : public CCard
{
	DECLARE_CARD_CSTOR(CThoughtErasureCard);

protected:
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);

	CCardFilter m_NonlandFilter;
};

class CUndercityUprisingCard : public CCard
{
	DECLARE_CARD_CSTOR(CUndercityUprisingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CViciousRumorsCard : public CCard
{
	DECLARE_CARD_CSTOR(CViciousRumorsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CVividRevivalCard : public CCard
{
	DECLARE_CARD_CSTOR(CVividRevivalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_MulticoloredFilter;
};

class CVraskasStoneglareCard : public CCard
{
	DECLARE_CARD_CSTOR(CVraskasStoneglareCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

class CArtfulTakedownCard : public CCard
{
	DECLARE_CARD_CSTOR(CArtfulTakedownCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
	bool BeforeBoth(CAbilityAction* pAction);
};

class CAssassinsTrophyCard : public CCard
{
	DECLARE_CARD_CSTOR(CAssassinsTrophyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CAssureAssembleCard : public CCard
{
	DECLARE_CARD_CSTOR(CAssureAssembleCard);

protected:
	bool BeforeAssure(CAbilityAction* pAction);
	bool BeforeAssemble(CAbilityAction* pAction);
};

class CBountyOfMightCard : public CCard
{
	DECLARE_CARD_CSTOR(CBountyOfMightCard);
};

class CChanceForGloryCard : public CCard
{
	DECLARE_CARD_CSTOR(CChanceForGloryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CChemistersInsightCard : public CCard
{
	DECLARE_CARD_CSTOR(CChemistersInsightCard);
};

class CCollarTheCulpritCard : public CCard
{
	DECLARE_CARD_CSTOR(CCollarTheCulpritCard);
};

class CCommandTheStormCard : public CCard
{
	DECLARE_CARD_CSTOR(CCommandTheStormCard);
};

class CCrushContrabandCard : public CCard
{
	DECLARE_CARD_CSTOR(CCrushContrabandCard);

protected:
	bool BeforeBoth(CAbilityAction* pAction);
};

class CDazzlingLightsCard : public CCard
{
	DECLARE_CARD_CSTOR(CDazzlingLightsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CDeviousCoverUpCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeviousCoverUpCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CExpansionExplosionCard : public CCard
{
	DECLARE_CARD_CSTOR(CExpansionExplosionCard);

protected:
	bool BeforeExplosion(CAbilityAction* pAction);
};

class CHypothesizzleCard : public CCard
{
	DECLARE_CARD_CSTOR(CHypothesizzleCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnDiscardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_DiscardSelection;
	CSelectionSupport m_CreatureSelection;
};

class CInescapableBlazeCard : public CCard
{
	DECLARE_CARD_CSTOR(CInescapableBlazeCard);
};

class CIntegrityInterventionCard : public CCard
{
	DECLARE_CARD_CSTOR(CIntegrityInterventionCard);

protected:
	bool BeforeIntervention(CAbilityAction* pAction);
};

class CInvertInventCard : public CCard
{
	DECLARE_CARD_CSTOR(CInvertInventCard);

protected:
	bool BeforeInvent(CAbilityAction* pAction);
};

class CIonizeCard : public CCard
{
	DECLARE_CARD_CSTOR(CIonizeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CJoinShieldsCard : public CCard
{
	DECLARE_CARD_CSTOR(CJoinShieldsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CJusticeStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CJusticeStrikeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CMarchOfTheMultitudesCard : public CCard
{
	DECLARE_CARD_CSTOR(CMarchOfTheMultitudesCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
	bool BeforeConvokedTokens(CAbilityAction* pAction);
};

class CMausoleumSecretsCard : public CCard
{
	DECLARE_CARD_CSTOR(CMausoleumSecretsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CNecroticWoundCard : public CCard
{
	DECLARE_CARD_CSTOR(CNecroticWoundCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPacksFavorCard : public CCard
{
	DECLARE_CARD_CSTOR(CPacksFavorCard);

protected:
	void AddPackSpell(LPCTSTR strCost, int nTapped);
	bool BeforePump(CAbilityAction* pAction);
};

class CPauseForReflectionCard : public CCard
{
	DECLARE_CARD_CSTOR(CPauseForReflectionCard);

protected:
	void AddPauseSpell(LPCTSTR strCost, int nTapped);
};

class CPriceOfFameCard : public CCard
{
	DECLARE_CARD_CSTOR(CPriceOfFameCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CRadicalIdeaCard : public CCard
{
	DECLARE_CARD_CSTOR(CRadicalIdeaCard);
};

class CRalsDispersalCard : public CCard
{
	DECLARE_CARD_CSTOR(CRalsDispersalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CRiskFactorCard : public CCard
{
	DECLARE_CARD_CSTOR(CRiskFactorCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
};

class CSinisterSabotageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSinisterSabotageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSonicAssaultCard : public CCard
{
	DECLARE_CARD_CSTOR(CSonicAssaultCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CStatusStatueCard : public CCard
{
	DECLARE_CARD_CSTOR(CStatusStatueCard);

protected:
	bool BeforeStatus(CAbilityAction* pAction);
};

class CTakeHeartCard : public CCard
{
	DECLARE_CARD_CSTOR(CTakeHeartCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CUnexplainedDisappearanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnexplainedDisappearanceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

class CBladeInstructorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBladeInstructorCard);

protected:
	CMentorSupport m_Mentor;
};

class CBountyAgentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBountyAgentCard);
};

class CFlightOfEquenautsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFlightOfEquenautsCard);
};

class CHaazdaMarshalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHaazdaMarshalCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CHealersHawkCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHealersHawkCard);
};

class CHuntedWitnessCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHuntedWitnessCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CInspiringUnicornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInspiringUnicornCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CIntrusivePackbeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIntrusivePackbeastCard);
};

class CLedevGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLedevGuardianCard);
};

class CLightOfTheLegionCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLightOfTheLegionCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
};

class CLoxodonRestorerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoxodonRestorerCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CParhelionPatrolCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CParhelionPatrolCard);

protected:
	CMentorSupport m_Mentor;
};

class CRocChargerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRocChargerCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

class CSkylineScoutCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkylineScoutCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

class CSunhomeStalwartCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunhomeStalwartCard);

protected:
	CMentorSupport m_Mentor;
};

class CTenthDistrictGuardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTenthDistrictGuardCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CVeneratedLoxodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVeneratedLoxodonCard);

protected:
	bool BeforeConvokedResolution(CAbilityAction* pAction);
	bool BeforeMainResolution(CAbilityAction* pAction);
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounters(CAbilityAction* pAction);

	CCountedCardContainer_ m_Convoked;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

class CAffectionateIndrikCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAffectionateIndrikCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CArboretumElementalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArboretumElementalCard);
};

class CBeastWhispererCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBeastWhispererCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CDevkarinDissidentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDevkarinDissidentCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CDistrictGuideCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDistrictGuideCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_LandFilter;
};

class CGenerousStrayCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGenerousStrayCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CGolgariRaidersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGolgariRaidersCard);

protected:
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

class CGrapplingSundewCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrapplingSundewCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CHatcherySpiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHatcherySpiderCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
};

class CImperviousGreatwurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImperviousGreatwurmCard);
};

class CKraulForagersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKraulForagersCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CKraulHarpoonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKraulHarpoonerCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CNullhideFeroxCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNullhideFeroxCard);

protected:
	CCardFilter m_NoncreatureFilter;
};

class CPeltCollectorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPeltCollectorCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CPortcullisVineCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPortcullisVineCard);

protected:
	CCardFilter m_DefenderFilter;
};

class CSiegeWurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSiegeWurmCard);
};

class CVigorsporeWurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVigorsporeWurmCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CWaryOkapiCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWaryOkapiCard);
};

class CWildCeratokCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWildCeratokCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

class CArclightPhoenixCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArclightPhoenixCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetCombatContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeReturn(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nSpells;
};

class CBargingSergeantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBargingSergeantCard);

protected:
	CMentorSupport m_Mentor;
};

class CBookDevourerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBookDevourerCard);

protected:
	bool BeforeWheel(CAbilityAction* pAction);
};

class CElectrostaticFieldCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElectrostaticFieldCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CErraticCyclopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CErraticCyclopsCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforePump(TriggeredAbility::TriggeredActionType* pAction);
};

class CFearlessHalberdierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFearlessHalberdierCard);
};

class CFireUrchinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFireUrchinCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CGoblinBanneretCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinBanneretCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
};

class CGoblinCratermakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinCratermakerCard);
};

class CGoblinLocksmithCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinLocksmithCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
};

class CHellkiteWhelpCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHellkiteWhelpCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CLegionWarbossCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLegionWarbossCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
};

class COrneryGoblinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrneryGoblinCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::BlockEventCallback2,
						   &CWhenSelfAttackedBlocked::SetBlockingOrBlockedEachTimeEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCreatureCard* pCreature, BOOL bBlocked, CCreatureCard* pCreature2, int nCount, int nIndex) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
};

class CRubblebeltBoarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRubblebeltBoarCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CRunawaySteamKinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRunawaySteamKinCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

class CSmeltWardMinotaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSmeltWardMinotaurCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
};

class CTorchCourierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTorchCourierCard);
};

class CWojekBodyguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWojekBodyguardCard);

protected:
	CMentorSupport m_Mentor;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

class CBarrierOfBonesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBarrierOfBonesCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CBartizanBatsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBartizanBatsCard);
};

class CBloodOperativeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodOperativeCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeReturn(CAbilityAction* pAction);

	CSelectionSupport m_CardSelection;
};

class CBurglarRatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBurglarRatCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CDoomWhispererCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDoomWhispererCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CDouserOfLightsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDouserOfLightsCard);
};

class CHiredPoisonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHiredPoisonerCard);
};

class CKraulRaiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKraulRaiderCard);
};

class CKraulSwarmCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKraulSwarmCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CLotlethGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLotlethGiantCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CMidnightReaperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMidnightReaperCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CMoodmarkPainterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMoodmarkPainterCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CPilferingImpCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPilferingImpCard);

protected:
	CCardFilter m_NonlandFilter;
};

class CPlaguecrafterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPlaguecrafterCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

class CSpinalCentipedeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpinalCentipedeCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CUndercityNecroliskCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUndercityNecroliskCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

class CVeiledShadeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVeiledShadeCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CWhisperingSnitchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWhisperingSnitchCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);

	int m_nTurn;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

class CCitywatchSphinxCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCitywatchSphinxCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CDimirInformantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDimirInformantCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CDreamEaterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDreamEaterCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CLeapfrogCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLeapfrogCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

class CMurmuringMysticCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMurmuringMysticCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CMuseDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMuseDrakeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CNightveilSpriteCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNightveilSpriteCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CPasswallAdeptCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPasswallAdeptCard);
};

class CThoughtboundPhantasmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThoughtboundPhantasmCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CVedalkenMesmeristCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVedalkenMesmeristCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

class CWatcherInTheMistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWatcherInTheMistCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CWishcoinCrabCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWishcoinCrabCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

class CAttendantOfVraskaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAttendantOfVraskaCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CAureliaExemplarOfJusticeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAureliaExemplarOfJusticeCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
};

class CBorosChallengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBorosChallengerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
};

class CCentaurPeacemakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCentaurPeacemakerCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CCharnelTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCharnelTrollCard);

protected:
	bool BeforeUpkeep(CAbilityAction* pAction);
	bool BeforeCounter(CAbilityAction* pAction);
};

class CConclaveCavalierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CConclaveCavalierCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

class CConclaveGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CConclaveGuildmageCard);

protected:
	bool BeforeTrample(CAbilityAction* pAction);
};

class CCracklingDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCracklingDrakeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CDarkbladeAgentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDarkbladeAgentCard);

protected:
	bool BeforeSurveilled(CAbilityAction* pAction);
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDraw(CAbilityAction* pAction);

	int m_nSurveilTurn;
};

class CDimirSpybugCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDimirSpybugCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CEmmaraSoulOfTheAccordCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmmaraSoulOfTheAccordCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CErstwhileTrooperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CErstwhileTrooperCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CEtrataTheSilencerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEtrataTheSilencerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeExile(TriggeredAbility::TriggeredActionType* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void ShuffleIntoLibrary();

	CSelectionSupport m_CreatureSelection;
};

class CFreshFacedRecruitCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFreshFacedRecruitCard);

protected:
	bool BeforeFirstStrike(CAbilityAction* pAction);
};

class CGarrisonSergeantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGarrisonSergeantCard);
};

class CGatekeeperGargoyleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGatekeeperGargoyleCard);

protected:
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

class CGlowsporeShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGlowsporeShamanCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CGolgariFindbrokerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGolgariFindbrokerCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_PermanentFilter;
};

class CHammerDropperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHammerDropperCard);

protected:
	CMentorSupport m_Mentor;
};

class CHouseGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHouseGuildmageCard);

protected:
	bool BeforeNoUntap(CAbilityAction* pAction);
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CIzoniThousandEyedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIzoniThousandEyedCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

class CKnightOfAutumnCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfAutumnCard);

protected:
	bool BeforeChoice(CAbilityAction* pAction);
	void OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnPermanentSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ModeSelection;
	CSelectionSupport m_PermanentSelection;
};

class CLazavTheMultifariousCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLazavTheMultifariousCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CLeagueGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLeagueGuildmageCard);
};

class CLedevChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLedevChampionCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
	void OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

class CLegionGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLegionGuildmageCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeTap(CAbilityAction* pAction);
};

class CMolderhulkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMolderhulkCard);

protected:
	BOOL CanReduceBy(int nReduction) const;
	BOOL CanReduce1(BOOL bIncludeTricks) { return CanReduceBy(1); }
	BOOL CanReduce2(BOOL bIncludeTricks) { return CanReduceBy(2); }
	BOOL CanReduce3(BOOL bIncludeTricks) { return CanReduceBy(3); }
	BOOL CanReduce4(BOOL bIncludeTricks) { return CanReduceBy(4); }
	BOOL CanReduce5(BOOL bIncludeTricks) { return CanReduceBy(5); }
	BOOL CanReduce6(BOOL bIncludeTricks) { return CanReduceBy(6); }
	BOOL CanReduce7(BOOL bIncludeTricks) { return CanReduceBy(7); }
	bool BeforeReturn(CAbilityAction* pAction);
};

class CNightveilPredatorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNightveilPredatorCard);
};

class CNivMizzetParunCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNivMizzetParunCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
};

class COchranAssassinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COchranAssassinCard);
};

class CPistonFistCyclopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPistonFistCyclopsCard);

protected:
	bool BeforeAttackable(CAbilityAction* pAction);
};

class CPitilessGorgonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPitilessGorgonCard);
};

class CRalsStaticasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRalsStaticasterCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CRampagingMonumentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRampagingMonumentCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CRhizomeLurcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRhizomeLurcherCard);

protected:
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

class CRosemaneCentaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRosemaneCentaurCard);
};

class CSumalaWoodshaperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSumalaWoodshaperCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_Filter;
};

class CSwarmGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwarmGuildmageCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CSwathcutterGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwathcutterGiantCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CSwiftbladeVindicatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwiftbladeVindicatorCard);
};

class CTajicLegionsEdgeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTajicLegionsEdgeCard);

protected:
	bool BeforeFirstStrike(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
};

class CTrostaniDiscordantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrostaniDiscordantCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

class CTruefireCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTruefireCaptainCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeDamage(CAbilityAction* pAction);

	CMentorSupport m_Mentor;
	mutable int m_nLastDamage;
};

class CUnderrealmLichCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUnderrealmLichCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CVernadiShieldmateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVernadiShieldmateCard);
};

class CWhisperAgentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWhisperAgentCard);

protected:
	bool BeforeSurveil(CAbilityAction* pAction);
};

class CWorldsoulColossusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWorldsoulColossusCard);

protected:
	BOOL Never(BOOL bIncludeTricks) { return FALSE; }
	bool BeforeResolution(CAbilityAction* pAction);
	bool BeforeConvokedResolution(CAbilityAction* pAction);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	int m_nX;
};

//____________________________________________________________________________
//
