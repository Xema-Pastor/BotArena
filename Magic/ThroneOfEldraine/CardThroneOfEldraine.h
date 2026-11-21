#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

//____________________________________________________________________________
//
// Helpers (from Ixalan, see no_vale/PATRONES_MOTOR.md)

class CRiotSupport
{
public:
	CRiotSupport(CCard* pCard);

	// The card itself has riot
	void AddRiotAbility();

	// pCreature enters with riot (Rhythm of the Wild)
	void ApplyRiot(CCard* pCreature);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	void OnRiotSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCard* m_pCard;
	CSelectionSupport m_Selection;
	ListenerPtr<CardMovementEventSource::Listener> m_cpListener;
};

class CAfterlifeSupport
{
public:
	CAfterlifeSupport(CCard* pCard);

	void AddAfterlifeAbility(int nCount);

protected:
	bool BeforeTokens(CAbilityAction* pAction);

	CCard* m_pCard;
	int m_nCount;
};

class CAdaptSupport
{
public:
	CAdaptSupport(CCard* pCard);

	CAbility* AddAdaptAbility(LPCTSTR strCost, int nCount);

protected:
	bool BeforeAdapt(CAbilityAction* pAction);

	CCard* m_pCard;
	int m_nCount;
};

class CMentorSupport
{
public:
	CMentorSupport(CCreatureCard* pCreature);

	CAbility* AddMentorAbility();

protected:
	bool OnMentorResolving(CAbilityAction* pAction);

	CCreatureCard* m_pCreature;
};

class CLocketCard : public CInPlaySpellCard
{
protected:
	CLocketCard(CGame* pGame, LPCTSTR strName, UINT nID, LPCTSTR strColor1, LPCTSTR strColor2);
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

class CProliferateSupport
{
public:
	CProliferateSupport(CCard* pCard);

	void AddProliferateTrigger();
	void Proliferate(CPlayer* pController);

protected:
	void OnPoisonSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCard* m_pCard;
	CSelectionSupport m_PoisonSelection;
};

class CDuringYourTurnSupport
{
public:
	CDuringYourTurnSupport(CCard* pCard);

	void Add(CEnchantment* pEnchantment);
	void AddTurnTriggers();

protected:
	bool SetNodeContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	void Update() const;

	CCard* m_pCard;
	std::vector<CEnchantment*> m_Enchantments;
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

// Comparers (from CardRavnicaAllegiance.h)
// "During your turn": the card's controller isn't the active player (spells of the opponents during your turn)
struct NotActivePlayerComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		CCard* pThis = const_cast<CCard*>(pCard);
		return pThis->GetController() != pThis->GetGame()->GetActivePlayer();
	}

	virtual NotActivePlayerComparer* Clone() const
	{
		return new NotActivePlayerComparer();
	}
};

// Comparers (from CardWarOfTheSpark.h)
//
// Creature cards with mana value X or less (Vivien's Arkbow; X is a member of the card)
struct ManaValueAtMostComparer : public CardComparer
{
	ManaValueAtMostComparer(const int* pMaxValue) : m_pMaxValue(pMaxValue) {}

	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && (int)pCard->GetConvertedManaCost() <= *m_pMaxValue;
	}

	virtual ManaValueAtMostComparer* Clone() const
	{
		return new ManaValueAtMostComparer(m_pMaxValue);
	}

protected:
	const int* m_pMaxValue;
};

//
// Creature cards with the mana value a card is looking for (Neoform; the value is a member of the card)
struct ManaValueEqualComparer : public CardComparer
{
	ManaValueEqualComparer(const int* pValue) : m_pValue(pValue) {}

	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && (int)pCard->GetConvertedManaCost() == *m_pValue;
	}

	virtual ManaValueEqualComparer* Clone() const
	{
		return new ManaValueEqualComparer(m_pValue);
	}

protected:
	const int* m_pValue;
};

//
// Creatures that attacked or blocked this turn (Gideon's Triumph)
struct AttackedOrBlockedThisTurnComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		const CCreatureCard* pCreature = dynamic_cast<const CCreatureCard*>(pCard);
		return pCreature && pCreature->GetCardType().IsCreature() &&
			(pCreature->AttackedThisTurn() || pCreature->IsBlocking() || pCreature->GetCreatureFlag()->HasBlocked());
	}

	virtual AttackedOrBlockedThisTurnComparer* Clone() const
	{
		return new AttackedOrBlockedThisTurnComparer;
	}
};

//____________________________________________________________________________
//
// "This land enters tapped unless you control <N> other <land type>" (Castles: a Plains...; Dwarven Mine...: three or
// more other Mountains). The land taps itself when it enters, as Glacial Fortress in M10; EntersUntapped is the
// condition, also for the "When this land enters untapped" triggers.
class CEldraineCheckLandCard : public CNonbasicLandCard
{
protected:
	CEldraineCheckLandCard(CGame* pGame, LPCTSTR strCardName, UINT nID, CardType landType, LPCTSTR strTypeFilter, int nRequired);

	BOOL EntersUntapped() const;
	// "When this land enters untapped, <effect>" (the callback does the effect)
	void AddEnterUntappedTrigger(CAbility::ResolutionStartedCallback callback);
	// "When this land enters untapped, <effect on target>" (the callback does the effect and returns false)
	CTargeting* AddEnterUntappedTargetTrigger(CAbility::ResolutionStartedCallback callback, bool bOptional, Characteristic characteristic);
	bool SetUntappedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	LPCTSTR m_strTypeFilter;
	int m_nRequired;
};

//____________________________________________________________________________
//
class CCastleArdenvaleCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CCastleArdenvaleCard);
};

//____________________________________________________________________________
//
class CCastleEmberethCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CCastleEmberethCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCastleGarenbrigCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CCastleGarenbrigCard);
};

//____________________________________________________________________________
//
class CCastleLocthwainCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CCastleLocthwainCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCastleVantressCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CCastleVantressCard);
};

//____________________________________________________________________________
//
class CDwarvenMineCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CDwarvenMineCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFabledPassageCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CFabledPassageCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGingerbreadCabinCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CGingerbreadCabinCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CIdyllicGrangeCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CIdyllicGrangeCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMysticSanctuaryCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CMysticSanctuaryCard);

protected:
	bool BeforeTop(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTournamentGroundsCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CTournamentGroundsCard);
};

//____________________________________________________________________________
//
class CWitchsCottageCard : public CEldraineCheckLandCard
{
	DECLARE_CARD_CSTOR(CWitchsCottageCard);

protected:
	bool BeforeTop(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGarrukCursedHuntsmanCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CGarrukCursedHuntsmanCard);

protected:
	bool BeforeWolves(CAbilityAction* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COkoTheTricksterCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(COkoTheTricksterCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeBase(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COkoThiefOfCrownsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(COkoThiefOfCrownsCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
	bool BeforeElk(CAbilityAction* pAction);
	bool BeforeExchange(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRowanFearlessSparkmageCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CRowanFearlessSparkmageCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeControl(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTheRoyalScionsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTheRoyalScionsCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAllThatGlittersCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CAllThatGlittersCard);

protected:
	counted_ptr<CAbility> CreateBonusAbility(CCard* pCard);
};

//____________________________________________________________________________
//
class CCharmedSleepCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCharmedSleepCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CDeafeningSilenceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDeafeningSilenceCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeLimit(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CDoomForetoldCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDoomForetoldCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_NonlandNontokenFilter;
};

//____________________________________________________________________________
//
class CFerocityOfTheWildsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFerocityOfTheWildsCard);
};

//____________________________________________________________________________
//
class CFortifyingProvisionsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFortifyingProvisionsCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
// Frogify and Kenrith's Transformation: the enchanted creature gets base power and toughness P/T while it's enchanted
// (applied when the Aura resolves and removed when the Aura leaves the battlefield)
class CEldraineBaseAuraCard : public CChgPwrTghAttrEnchantCard
{
protected:
	CEldraineBaseAuraCard(CGame* pGame, LPCTSTR strCardName, UINT nID, LPCTSTR strCost, int nPower, int nToughness);

	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	bool BeforeLeave(CAbilityAction* pAction);

	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
	CPowerModifier m_PowerModifier;
	CLifeModifier m_LifeModifier;
	CCountedCardContainer_ m_Enchanted;
};

//____________________________________________________________________________
//
class CFrogifyCard : public CEldraineBaseAuraCard
{
	DECLARE_CARD_CSTOR(CFrogifyCard);
};

//____________________________________________________________________________
//
class CHappilyEverAfterCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHappilyEverAfterCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeWin(CAbilityAction* pAction);
	BOOL CanWin(CPlayer* pPlayer) const;
};

//____________________________________________________________________________
//
class CImprobableAllianceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CImprobableAllianceCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeFaerie(CAbilityAction* pAction);
	bool BeforeLoot(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CKenrithsTransformationCard : public CEldraineBaseAuraCard
{
	DECLARE_CARD_CSTOR(CKenrithsTransformationCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKnightsChargeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CKnightsChargeCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeDrain(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COutlawsMerrimentCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COutlawsMerrimentCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRevengeOfRavensCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRevengeOfRavensCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeDrain(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CSoTinyCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSoTinyCard);
};

//____________________________________________________________________________
//
class CTallAsABeanstalkCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CTallAsABeanstalkCard);
};

//____________________________________________________________________________
//
class CTrailOfCrumbsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTrailOfCrumbsCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
	bool SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_PermanentFilter;
};

//____________________________________________________________________________
//
class CTrappedInTheTowerCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CTrappedInTheTowerCard);

protected:
	CCardFilter m_CardFilter;
};

//____________________________________________________________________________
//
// A cost reduction that depends on a count (as Ghalta, Primal Hunger): one variant of the spell for each reduction, castable
// only when the count gives exactly that reduction (the last one, when the count is at least its value). See
// AddCountReductionSpells.
class CCountReduction
{
public:
	typedef int (*CountFunction)(CCard* pCard);

	CCountReduction(CCard* pCard, CountFunction count, int nCount, BOOL bAtLeast)
		: m_pCard(pCard), m_Count(count), m_nCount(nCount), m_bAtLeast(bAtLeast)
	{}

	BOOL IsPlayable(BOOL bIncludeTricks)
	{
		int n = m_Count(m_pCard);
		return m_bAtLeast ? n >= m_nCount : n == m_nCount;
	}

protected:
	CCard* m_pCard;
	CountFunction m_Count;
	int m_nCount;
	BOOL m_bAtLeast;
};

//____________________________________________________________________________
//
class CCrystalSlipperCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCrystalSlipperCard);
};

//____________________________________________________________________________
//
class CEmbercleaveCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEmbercleaveCard);

protected:
	bool BeforeAttach(CAbilityAction* pAction);

	std::list<CCountReduction> m_Reductions;
};

//____________________________________________________________________________
//
class CEnchantedCarriageCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEnchantedCarriageCard);

protected:
	bool BeforeMice(CAbilityAction* pAction);

	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
class CFolioOfFanciesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFolioOfFanciesCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGiantsSkewerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGiantsSkewerCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGlassCasketCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGlassCasketCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

//____________________________________________________________________________
//
class CGoldenEggCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGoldenEggCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHeraldicBannerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHeraldicBannerCard);

public:
	DWORD GetChosenColor() const { return m_dwChosenColor; }

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	BOOL IsWhite(BOOL bIncludeTricks) { return m_dwChosenColor == 1; }
	BOOL IsBlue(BOOL bIncludeTricks) { return m_dwChosenColor == 2; }
	BOOL IsBlack(BOOL bIncludeTricks) { return m_dwChosenColor == 3; }
	BOOL IsRed(BOOL bIncludeTricks) { return m_dwChosenColor == 4; }
	BOOL IsGreen(BOOL bIncludeTricks) { return m_dwChosenColor == 5; }

	CSelectionSupport m_ColorSelection;
	DWORD m_dwChosenColor;	// 1..5 (white, blue, black, red, green), 0 before choosing
};

//____________________________________________________________________________
//
class CMaceOfTheValiantCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMaceOfTheValiantCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMantleOfTidesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMantleOfTidesCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeAttach(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CMidnightClockCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMidnightClockCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
	void AddHourCounter(CPlayer* pController);
};

//____________________________________________________________________________
//
class CRosethornHalberdCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRosethornHalberdCard);

protected:
	bool BeforeAttach(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CScaldingCauldronCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CScaldingCauldronCard);
};

//____________________________________________________________________________
//
class CShiningArmorCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CShiningArmorCard);

protected:
	bool BeforeAttach(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSorcerousSpyglassCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSorcerousSpyglassCard);

protected:
	CCardFilter m_CardFilter;
};

//____________________________________________________________________________
//
class CSpinningWheelCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSpinningWheelCard);
};

//____________________________________________________________________________
//
class CSteelclawLanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSteelclawLanceCard);
};

//____________________________________________________________________________
//
class CTheCauldronOfEternityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheCauldronOfEternityCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeBottom(TriggeredAbility::TriggeredActionType* pAction);

	std::list<CCountReduction> m_Reductions;
};

//____________________________________________________________________________
//
class CTheCircleOfLoyaltyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheCircleOfLoyaltyCard);

protected:
	bool BeforeKnight(CAbilityAction* pAction);

	std::list<CCountReduction> m_Reductions;
};

//____________________________________________________________________________
//
class CTheGreatHengeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheGreatHengeCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(TriggeredAbility::TriggeredActionType* pAction);

	std::list<CCountReduction> m_Reductions;
};

//____________________________________________________________________________
//
class CTheMagicMirrorCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheMagicMirrorCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);

	std::list<CCountReduction> m_Reductions;
};

//____________________________________________________________________________
//
class CTomeOfLegendsCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTomeOfLegendsCard);
};

//____________________________________________________________________________
//
class CWeaponRackCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWeaponRackCard);
};

//____________________________________________________________________________
//
class CWishclawTalismanCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWishclawTalismanCard);

protected:
	BOOL IsYourTurn(BOOL bIncludeTricks);
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWitchingWellCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWitchingWellCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWitchsOvenCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWitchsOvenCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBlowYourHouseDownCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlowYourHouseDownCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCauldronsGiftCard : public CCard
{
	DECLARE_CARD_CSTOR(CCauldronsGiftCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CClaimTheFirstbornCard : public CCard
{
	DECLARE_CARD_CSTOR(CClaimTheFirstbornCard);
};

//____________________________________________________________________________
//
class CDanceOfTheManseCard : public CCard
{
	DECLARE_CARD_CSTOR(CDanceOfTheManseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_Filter;	// rebuilt with X on each resolution
};

//____________________________________________________________________________
//
class CEpicDownfallCard : public CCard
{
	DECLARE_CARD_CSTOR(CEpicDownfallCard);
};

//____________________________________________________________________________
//
class CForebodingFruitCard : public CCard
{
	DECLARE_CARD_CSTOR(CForebodingFruitCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CForeverYoungCard : public CCard
{
	DECLARE_CARD_CSTOR(CForeverYoungCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGiantOpportunityCard : public CCard
{
	DECLARE_CARD_CSTOR(CGiantOpportunityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ModeSelection;
};

//____________________________________________________________________________
//
class CIrencragFeatCard : public CCard
{
	DECLARE_CARD_CSTOR(CIrencragFeatCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CJoustCard : public CCard
{
	DECLARE_CARD_CSTOR(CJoustCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMemoryTheftCard : public CCard
{
	DECLARE_CARD_CSTOR(CMemoryTheftCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnAdventureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	void AskAdventure(CPlayer* pController, CPlayer* pPlayer);

	CSelectionSupport m_CardSelection;
	CSelectionSupport m_AdventureSelection;
};

//____________________________________________________________________________
//
class COutmuscleCard : public CCard
{
	DECLARE_CARD_CSTOR(COutmuscleCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CReaveSoulCard : public CCard
{
	DECLARE_CARD_CSTOR(CReaveSoulCard);
};

//____________________________________________________________________________
//
class CSilverflameRitualCard : public CCard
{
	DECLARE_CARD_CSTOR(CSilverflameRitualCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpectersShriekCard : public CCard
{
	DECLARE_CARD_CSTOR(CSpectersShriekCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

//____________________________________________________________________________
//
class CStolenByTheFaeCard : public CCard
{
	DECLARE_CARD_CSTOR(CStolenByTheFaeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSunderingStrokeCard : public CCard
{
	DECLARE_CARD_CSTOR(CSunderingStrokeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTasteOfDeathCard : public CCard
{
	DECLARE_CARD_CSTOR(CTasteOfDeathCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CUnexplainedVisionCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnexplainedVisionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWitchsVengeanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CWitchsVengeanceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnTypeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_TypeSelection;
};

//____________________________________________________________________________
//
class CWolfsQuarryCard : public CCard
{
	DECLARE_CARD_CSTOR(CWolfsQuarryCard);
};

//____________________________________________________________________________
//
class CBakeIntoAPieCard : public CCard
{
	DECLARE_CARD_CSTOR(CBakeIntoAPieCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBanishIntoFableCard : public CCard
{
	DECLARE_CARD_CSTOR(CBanishIntoFableCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBargeInCard : public CCard
{
	DECLARE_CARD_CSTOR(CBargeInCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDidntSayPleaseCard : public CCard
{
	DECLARE_CARD_CSTOR(CDidntSayPleaseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDrownInTheLochCard : public CCard
{
	DECLARE_CARD_CSTOR(CDrownInTheLochCard);
};

//____________________________________________________________________________
//
class CFellThePheasantCard : public CCard
{
	DECLARE_CARD_CSTOR(CFellThePheasantCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFestiveFuneralCard : public CCard
{
	DECLARE_CARD_CSTOR(CFestiveFuneralCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CInsatiableAppetiteCard : public CCard
{
	DECLARE_CARD_CSTOR(CInsatiableAppetiteCard);
};

//____________________________________________________________________________
//
class CIntoTheStoryCard : public CCard
{
	DECLARE_CARD_CSTOR(CIntoTheStoryCard);

protected:
	BOOL OpponentHasSevenInGraveyard(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CLashOfThornsCard : public CCard
{
	DECLARE_CARD_CSTOR(CLashOfThornsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMysticalDisputeCard : public CCard
{
	DECLARE_CARD_CSTOR(CMysticalDisputeCard);
};

//____________________________________________________________________________
//
class COkosHospitalityCard : public CCard
{
	DECLARE_CARD_CSTOR(COkosHospitalityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COnceAndFutureCard : public CCard
{
	DECLARE_CARD_CSTOR(COnceAndFutureCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COnceUponATimeCard : public CCard
{
	DECLARE_CARD_CSTOR(COnceUponATimeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_CreatureLandFilter;
};

//____________________________________________________________________________
//
class COutflankCard : public CCard
{
	DECLARE_CARD_CSTOR(COutflankCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRallyForTheThroneCard : public CCard
{
	DECLARE_CARD_CSTOR(CRallyForTheThroneCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRedcapMeleeCard : public CCard
{
	DECLARE_CARD_CSTOR(CRedcapMeleeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CReturnOfTheWildspeakerCard : public CCard
{
	DECLARE_CARD_CSTOR(CReturnOfTheWildspeakerCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRunAwayTogetherCard : public CCard
{
	DECLARE_CARD_CSTOR(CRunAwayTogetherCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CScorchingDragonfireCard : public CCard
{
	DECLARE_CARD_CSTOR(CScorchingDragonfireCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSearingBarrageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSearingBarrageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSlayingFireCard : public CCard
{
	DECLARE_CARD_CSTOR(CSlayingFireCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThrillOfPossibilityCard : public CCard
{
	DECLARE_CARD_CSTOR(CThrillOfPossibilityCard);
};

//____________________________________________________________________________
//
class CTrueLovesKissCard : public CCard
{
	DECLARE_CARD_CSTOR(CTrueLovesKissCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTurnIntoAPumpkinCard : public CCard
{
	DECLARE_CARD_CSTOR(CTurnIntoAPumpkinCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAcclaimedContenderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAcclaimedContenderCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_LookFilter;
};

//____________________________________________________________________________
//
class CArchonOfAbsolutionCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArchonOfAbsolutionCard);
};

//____________________________________________________________________________
//
class CArdenvalePaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArdenvalePaladinCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

//____________________________________________________________________________
//
class CArdenvaleTacticianCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArdenvaleTacticianCard);

protected:
	bool BeforeSwoop(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CBarteredCowCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBarteredCowCard);

protected:
	bool SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBelovedPrincessCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBelovedPrincessCard);

protected:
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CCharmingPrinceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCharmingPrinceCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void GetOtherOwnedCreatures(CPlayer* pController, CCountedCardContainer& creatures);

	CSelectionSupport m_Selection;
};

//____________________________________________________________________________
//
class CFaerieGuidemotherCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFaerieGuidemotherCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CFlutterfoxCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFlutterfoxCard);
};

//____________________________________________________________________________
//
class CGarrisonGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGarrisonGriffinCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGiantKillerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGiantKillerCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CHushbringerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHushbringerCard);
};

//____________________________________________________________________________
//
class CKenrithTheReturnedKingCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKenrithTheReturnedKingCard);

protected:
	bool BeforeHaste(CAbilityAction* pAction);
	bool BeforeLife(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKnightOfTheKeepCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfTheKeepCard);
};

//____________________________________________________________________________
//
class CLindenTheSteadfastQueenCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLindenTheSteadfastQueenCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attackSubject) const;
	bool BeforeLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLonesomeUnicornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLonesomeUnicornCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CMysteriousPathlighterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMysteriousPathlighterCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CPrizedGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPrizedGriffinCard);
};

//____________________________________________________________________________
//
class CRealmCloakedGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRealmCloakedGiantCard);

protected:
	bool BeforeCastOff(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CShepherdOfTheFlockCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShepherdOfTheFlockCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CSilverflameSquireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSilverflameSquireCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CSilverwingSquadronCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSilverwingSquadronCard);

protected:
	bool BeforeKnights(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSyrAlinTheLionsClawCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyrAlinTheLionsClawCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVenerableKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVenerableKnightCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWorthyKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWorthyKnightCard);

protected:
	bool BeforeHuman(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBeanstalkGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBeanstalkGiantCard);

protected:
	bool BeforeFootsteps(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CBramblefortFinkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBramblefortFinkCard);

protected:
	BOOL ControlsOko(BOOL bIncludeTricks);
	bool BeforeBase(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCuriousPairCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCuriousPairCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CEdgewallInnkeeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEdgewallInnkeeperCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFeastingTrollKingCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFeastingTrollKingCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeFood(CAbilityAction* pAction);
	BOOL IsYourTurn(BOOL bIncludeTricks);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFierceWitchstalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFierceWitchstalkerCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFlaxenIntruderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFlaxenIntruderCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CGarenbrigCarverCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGarenbrigCarverCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CGarenbrigPaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGarenbrigPaladinCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CGarenbrigSquireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGarenbrigSquireCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGildedGooseCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGildedGooseCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKeeperOfFablesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKeeperOfFablesCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	bool BeforeDraw(CAbilityAction* pAction);

	mutable int m_nTurn;	// the turn of the last trigger
};

//____________________________________________________________________________
//
class CLovestruckBeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLovestruckBeastCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class COakhameAdversaryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COakhameAdversaryCard);

protected:
	BOOL OpponentControlsGreen(BOOL bIncludeTricks);
	BOOL NoOpponentControlsGreen(BOOL bIncludeTricks) { return !OpponentControlsGreen(bIncludeTricks); }
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CQuestingBeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CQuestingBeastCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDamage(CAbilityAction* pAction);

	CCardFilter m_BlockerFilter;
	mutable int m_nDamage;	// the combat damage dealt to the opponent
};

//____________________________________________________________________________
//
class CRosethornAcolyteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRosethornAcolyteCard);

protected:
	bool BeforeRitual(CAbilityAction* pAction);
	void OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CAdventureSupport m_Adventure;
	CSelectionSupport m_ColorSelection;
};

//____________________________________________________________________________
//
class CSteelbaneHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteelbaneHydraCard);

protected:
	BOOL Never(BOOL bIncludeTricks) { return FALSE; }
	bool BeforeResolution(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	int m_nX;	// X of the last resolved spell
};

//____________________________________________________________________________
//
class CSyrFarenTheHengehammerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyrFarenTheHengehammerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThornMammothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThornMammothCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTuinvaleTreefolkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTuinvaleTreefolkCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CWickedWolfCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWickedWolfCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWildwoodTrackerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWildwoodTrackerCard);

protected:
	bool SetCombatContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const;
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CYorvoLordOfGarenbrigCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYorvoLordOfGarenbrigCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CBloodhazeWolverineCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodhazeWolverineCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforePump(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CBonecrusherGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBonecrusherGiantCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
	bool BeforeStomp(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CBrimstoneTrebuchetCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrimstoneTrebuchetCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBurningYardTrainerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBurningYardTrainerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEmberethPaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmberethPaladinCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

//____________________________________________________________________________
//
class CEmberethShieldbreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmberethShieldbreakerCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CEmberethSkyblazerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmberethSkyblazerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CDuringYourTurnSupport m_DuringYourTurn;
};

//____________________________________________________________________________
//
class CFerventChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFerventChampionCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CIrencragPyromancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIrencragPyromancerCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeDamage(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CMadRatterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMadRatterCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeRats(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CMerchantOfTheValeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMerchantOfTheValeCard);

protected:
	bool BeforeHaggle(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class COgreErrantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COgreErrantCard);

protected:
	bool BeforeMenace(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COpportunisticDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(COpportunisticDragonCard);

public:
	const CCard* GetStolenCard() const { return m_pStolen; }

protected:
	bool BeforeSteal(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCard* m_pStolen;	// the permanent it controls while it remains on the battlefield
};

//____________________________________________________________________________
//
class CRagingRedcapCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRagingRedcapCard);
};

//____________________________________________________________________________
//
class CRedcapRaidersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRedcapRaidersCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_Selection;
};

//____________________________________________________________________________
//
class CRimrockKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRimrockKnightCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CRowansBattleguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRowansBattleguardCard);
};

//____________________________________________________________________________
//
class CRowansStalwartsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRowansStalwartsCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSevenDwarvesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSevenDwarvesCard);
};

//____________________________________________________________________________
//
class CSkullknockerOgreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkullknockerOgreCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CSyrCarahTheBoldCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyrCarahTheBoldCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWeaselbackRedcapCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWeaselbackRedcapCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAyaraFirstOfLocthwainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAyaraFirstOfLocthwainCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDrain(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CBarrowWitchesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBarrowWitchesCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_KnightFilter;
};

//____________________________________________________________________________
//
class CBelleOfTheBrawlCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBelleOfTheBrawlCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBlacklanceParagonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBlacklanceParagonCard);

protected:
	bool BeforeKeywords(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBogNaughtyCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBogNaughtyCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCauldronFamiliarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCauldronFamiliarCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChitteringWitchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChitteringWitchCard);

protected:
	bool BeforeRats(CAbilityAction* pAction);
	bool BeforeShrink(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CClackbridgeTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CClackbridgeTrollCard);

protected:
	bool BeforeGoats(CAbilityAction* pAction);
	bool BeforeCombat(CAbilityAction* pAction);
	void OnSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_Selection;
};

//____________________________________________________________________________
//
class CEyeCollectorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEyeCollectorCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFoulmireKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFoulmireKnightCard);

protected:
	bool BeforeInsight(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CLocthwainPaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLocthwainPaladinCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

//____________________________________________________________________________
//
class CLostLegionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLostLegionCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMalevolentNobleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMalevolentNobleCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CMurderousRiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMurderousRiderCard);

protected:
	bool BeforeBottom(CAbilityAction* pAction);
	bool BeforeSwiftEnd(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class COathswornKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COathswornKnightCard);
};

//____________________________________________________________________________
//
class COrderOfMidnightCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(COrderOfMidnightCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CPiperOfTheSwarmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPiperOfTheSwarmCard);

protected:
	CCardFilter m_RatFilter;
};

//____________________________________________________________________________
//
class CRankleMasterOfPranksCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRankleMasterOfPranksCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnModesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ModeSelection;
};

//____________________________________________________________________________
//
class CReaperOfNightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CReaperOfNightCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CSmittenSwordmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSmittenSwordmasterCard);

protected:
	bool BeforeCurry(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CSyrKonradTheGrimCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyrKonradTheGrimCard);

protected:
	bool SetToGraveyardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetLeaveGraveyardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTemptingWitchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTemptingWitchCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
	bool BeforeLoseLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWickedGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWickedGuardianCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_Selection;
};

//____________________________________________________________________________
//
class CAnimatingFaerieCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAnimatingFaerieCard);

protected:
	bool BeforeBringToLife(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CBrazenBorrowerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBrazenBorrowerCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CCorridorMonitorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCorridorMonitorCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEmryLurkerOfTheLochCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmryLurkerOfTheLochCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);

	std::list<CCountReduction> m_Reductions;
};

//____________________________________________________________________________
//
class CFaeOfWishesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFaeOfWishesCard);
};

//____________________________________________________________________________
//
class CFaerieFormationCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFaerieFormationCard);

protected:
	bool BeforeFaerie(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFaerieVandalCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFaerieVandalCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeCounter(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CGadwickTheWizenedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGadwickTheWizenedCard);

protected:
	BOOL Never(BOOL bIncludeTricks) { return FALSE; }
	bool BeforeResolution(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeTap(CAbilityAction* pAction);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	int m_nX;		// X of the last resolved spell
	int m_nDrawX;	// X of the spell that put it onto the battlefield
};

//____________________________________________________________________________
//
class CHypnoticSpriteCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHypnoticSpriteCard);

protected:
	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CMerfolkSecretkeeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMerfolkSecretkeeperCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CMistfordRiverTurtleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMistfordRiverTurtleCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMoonlitScavengersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMoonlitScavengersCard);

protected:
	bool BeforeBounce(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COkosAccomplicesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(COkosAccomplicesCard);
};

//____________________________________________________________________________
//
class COverwhelmedApprenticeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COverwhelmedApprenticeCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CQueenOfIceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CQueenOfIceCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::CreatureEventCallback, &CWhenSelfDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeTap(TriggeredAbility::TriggeredActionType* pAction);
	bool BeforeRage(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CSageOfTheFallsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSageOfTheFallsCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CShimmerDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CShimmerDragonCard);

protected:
	CCardFilter m_ArtifactFilter;
};

//____________________________________________________________________________
//
class CSteelgazeGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSteelgazeGriffinCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforePump(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nDraws;	// the cards its controller drew this turn
};

//____________________________________________________________________________
//
class CSyrElenoraTheDiscerningCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyrElenoraTheDiscerningCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTomeRaiderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTomeRaiderCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVantressGargoyleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVantressGargoyleCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVantressPaladinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVantressPaladinCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

//____________________________________________________________________________
//
class CWishfulMerfolkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWishfulMerfolkCard);

protected:
	bool BeforeLoseDefender(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWorkshopEldersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWorkshopEldersCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
// A condition on the colors among the permanents its controller controls (Faeburrow Elder): playable only when they are
// exactly the colors of the mask (1 white, 2 blue, 4 black, 8 red, 16 green)
class CColorMaskCondition
{
public:
	CColorMaskCondition(CCard* pCard, int nMask) : m_pCard(pCard), m_nMask(nMask) {}

	BOOL IsPlayable(BOOL bIncludeTricks);

protected:
	CCard* m_pCard;
	int m_nMask;
};

//____________________________________________________________________________
//
class CAlelaArtfulProvocateurCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAlelaArtfulProvocateurCard);

protected:
	bool BeforeFaerie(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CArcanistsOwlCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArcanistsOwlCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_LookFilter;
};

//____________________________________________________________________________
//
class CChulaneTellerOfTalesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChulaneTellerOfTalesCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CClockworkServantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CClockworkServantCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCrashingDrawbridgeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCrashingDrawbridgeCard);

protected:
	bool BeforeHaste(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDeathlessKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeathlessKnightCard);

protected:
	bool SetLifeContext(CTriggeredAbility<>::TriggerContextType& triggerContext, const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeReturn(CAbilityAction* pAction);

	mutable int m_nTurn;	// the turn of the last trigger
};

//____________________________________________________________________________
//
class CEliteHeadhunterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEliteHeadhunterCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CFaeburrowElderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFaeburrowElderCard);

protected:
	std::list<CColorMaskCondition> m_Conditions;
};

//____________________________________________________________________________
//
class CFirebornKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFirebornKnightCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGingerbruteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGingerbruteCard);

protected:
	bool BeforeEvasion(CAbilityAction* pAction);

	CCardFilter m_HasteFilter;
};

//____________________________________________________________________________
//
class CGluttonousTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGluttonousTrollCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CGrumgullyTheGenerousCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrumgullyTheGenerousCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
};

//____________________________________________________________________________
//
class CHengeWalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHengeWalkerCard);

protected:
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
};

//____________________________________________________________________________
//
class CInquisitivePuppetCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInquisitivePuppetCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CInspiringVeteranCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInspiringVeteranCard);
};

//____________________________________________________________________________
//
class CJoustingDummyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJoustingDummyCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKorvoldFaeCursedKingCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKorvoldFaeCursedKingCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(CAbilityAction* pAction);

	CCardFilter m_AnotherFilter;
};

//____________________________________________________________________________
//
class CLochDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLochDragonCard);

protected:
	bool BeforeRummage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLochmereSerpentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLochmereSerpentCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
	BOOL OpponentHasFiveInGraveyard(BOOL bIncludeTricks);
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLocthwainGargoyleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLocthwainGargoyleCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMaraleafPixieCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMaraleafPixieCard);
};

//____________________________________________________________________________
//
class COakhameRangerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COakhameRangerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CAdventureSupport m_Adventure;
};

//____________________________________________________________________________
//
class CProphetOfThePeakCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CProphetOfThePeakCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRampartSmasherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRampartSmasherCard);

protected:
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CResoluteRiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CResoluteRiderCard);

protected:
	bool BeforeLifelink(CAbilityAction* pAction);
	bool BeforeIndestructible(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRovingKeepCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRovingKeepCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSavvyHunterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSavvyHunterCard);

protected:
	bool BeforeFood(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CShamblingSuitCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShamblingSuitCard);
};

//____________________________________________________________________________
//
class CShinechaserCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CShinechaserCard);
};

//____________________________________________________________________________
//
class CSignpostScarecrowCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSignpostScarecrowCard);
};

//____________________________________________________________________________
//
class CSorcerersBroomCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSorcerersBroomCard);

protected:
	bool SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCopy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CStonecoilSerpentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStonecoilSerpentCard);

protected:
	BOOL Never(BOOL bIncludeTricks) { return FALSE; }
	bool BeforeResolution(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	int m_nX;	// X of the last resolved spell
};

//____________________________________________________________________________
//
class CStormfistCrusaderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormfistCrusaderCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSyrGwynHeroOfAshvaleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyrGwynHeroOfAshvaleCard);

protected:
	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attackSubject) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThunderousSnapperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThunderousSnapperCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWandermareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWandermareCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWintermoorCommanderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWintermoorCommanderCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
