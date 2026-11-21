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
class CCrypticCavesCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CCrypticCavesCard);

protected:
	BOOL CanDraw(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CFieldOfTheDeadCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CFieldOfTheDeadCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeZombie(CAbilityAction* pAction);
	BOOL HasSevenDifferentLands(CPlayer* pPlayer) const;
};

//____________________________________________________________________________
//
class CLotusFieldCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CLotusFieldCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAjaniInspiringLeaderCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniInspiringLeaderCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeFlying(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAjaniStrengthOfThePrideCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniStrengthOfThePrideCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforePridemate(CAbilityAction* pAction);
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChandraAcolyteOfFlameCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraAcolyteOfFlameCard);

protected:
	bool BeforeLoyalty(CAbilityAction* pAction);
	bool BeforeElementals(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChandraAwakenedInfernoCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraAwakenedInfernoCard);

protected:
	bool BeforeEmblem(CAbilityAction* pAction);
	bool BeforeDamageEach(CAbilityAction* pAction);
	bool BeforeDamageX(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChandraFlamesFuryCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraFlamesFuryCard);

protected:
	bool BeforeDamage2(CAbilityAction* pAction);
	bool BeforeDamage4(CAbilityAction* pAction);
	bool BeforeDamage10(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChandraNovicePyromancerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CChandraNovicePyromancerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeMana(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMuYanlingCelestialWindCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CMuYanlingCelestialWindCard);

protected:
	bool BeforeWeaken(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMuYanlingSkyDancerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CMuYanlingSkyDancerCard);

protected:
	bool BeforeWeaken(CAbilityAction* pAction);
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSorinImperiousBloodlordCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSorinImperiousBloodlordCard);

protected:
	bool BeforeKeywords(CAbilityAction* pAction);
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool BeforePutVampire(CAbilityAction* pAction);

	CCardFilter m_VampireFilter;
	CCardFilter m_VampireCardFilter;
};

//____________________________________________________________________________
//
class CSorinVampireLordCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSorinVampireLordCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVivienArkbowRangerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVivienArkbowRangerCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVivienNaturesAvengerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVivienNaturesAvengerCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGauntletsOfLightCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CGauntletsOfLightCard);

protected:
	counted_ptr<CAbility> CreateUntapAbility(CCard* pCard);
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGlaringAegisCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CGlaringAegisCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHardCoverCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CHardCoverCard);

protected:
	counted_ptr<CAbility> CreateLootAbility(CCard* pCard);
	bool BeforeLoot(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLeylineOfAbundanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLeylineOfAbundanceCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredSpecialProdManaAbility, CWhenTappedForMana > ManaTriggeredAbility;

	bool SetManaContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
		const CManaProductionAbilityAction* pManaAction) const;
	bool BeforeCounters(CAbilityAction* pAction);

	ManaTriggeredAbility* m_pManaAbility;
};

//____________________________________________________________________________
//
class CLeylineOfCombustionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLeylineOfCombustionCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > CardTriggeredAbility;
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSubjectTargeted,
						   CWhenSubjectTargeted::PlayerEventCallback, &CWhenSubjectTargeted::SetPlayerEventCallback > PlayerTriggeredAbility;

	bool SetCardContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pByPlayer) const;
	bool SetPlayerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CPlayer* pByPlayer) const;
	bool CheckTargeting(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pByPlayer) const;
	bool BeforeCardDamage(CardTriggeredAbility::TriggeredActionType* pAction);
	bool BeforePlayerDamage(PlayerTriggeredAbility::TriggeredActionType* pAction);
	void DamagePlayer(CPlayer* pPlayer);

	mutable const void* m_pLastAction;	// the spell or ability of the last trigger ("you and/or permanents": once each)
};

//____________________________________________________________________________
//
class CMoldervineReclamationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMoldervineReclamationCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSeasonOfGrowthCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSeasonOfGrowthCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeDraw(CAbilityAction* pAction);

	mutable const void* m_pLastSpell;	// the spell of the last trigger (a spell with several targets draws once)
};

//____________________________________________________________________________
//
class CUnholyIndentureCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CUnholyIndentureCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CAncestralBladeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAncestralBladeCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBagOfHoldingCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBagOfHoldingCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > DiscardAbility;

	bool SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeExile(DiscardAbility::TriggeredActionType* pAction);
	bool BeforeLoot(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

//____________________________________________________________________________
//
class CBloodsoakedAltarCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBloodsoakedAltarCard);
};

//____________________________________________________________________________
//
class CChandrasRegulatorCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CChandrasRegulatorCard);

protected:
	CCardFilter m_DiscardFilter;
};

//____________________________________________________________________________
//
class CColossusHammerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CColossusHammerCard);
};

//____________________________________________________________________________
//
class CDivinersLockboxCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDivinersLockboxCard);

protected:
	bool BeforeChooseName(CAbilityAction* pAction);
	void OnNameSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_NameSelection;
	std::vector<CString> m_Names;
};

//____________________________________________________________________________
//
class CHeartPiercerBowCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHeartPiercerBowCard);

protected:
	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attackSubject) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CIconOfAncestryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CIconOfAncestryCard);

protected:
	OVERRIDE(void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType,
		CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);
	void OnTypeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	counted_ptr<CAbility> CreateBonusAbility(CCard* pCard);
	bool BeforeLook(CAbilityAction* pAction);

	CSelectionSupport m_TypeSelection;
	SingleCreatureType m_SelectedType;
};

//____________________________________________________________________________
//
class CManifoldKeyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CManifoldKeyCard);
};

//____________________________________________________________________________
//
class CMaskOfImmolationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMaskOfImmolationCard);

protected:
	bool BeforeEquip(CAbilityAction* pAction);
	bool BeforeToken(CAbilityAction* pAction);
	counted_ptr<CAbility> CreateSacrificeAbility(CCard* pCard);
};

//____________________________________________________________________________
//
class CPortalOfSanctuaryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPortalOfSanctuaryCard);

protected:
	BOOL CanActivate(BOOL bIncludeTricks);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRetributiveWandCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRetributiveWandCard);

protected:
	bool BeforeDamage1(CAbilityAction* pAction);
	bool BeforeDamage5(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWolfridersSaddleCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWolfridersSaddleCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAerialAssaultCard : public CCard
{
	DECLARE_CARD_CSTOR(CAerialAssaultCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAgonizingSyphonCard : public CCard
{
	DECLARE_CARD_CSTOR(CAgonizingSyphonCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBloodForBonesCard : public CCard
{
	DECLARE_CARD_CSTOR(CBloodForBonesCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCaptivatingGyreCard : public CCard
{
	DECLARE_CARD_CSTOR(CCaptivatingGyreCard);
};

//____________________________________________________________________________
//
class CChandrasFlameWaveCard : public CCard
{
	DECLARE_CARD_CSTOR(CChandrasFlameWaveCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDevoutDecreeCard : public CCard
{
	DECLARE_CARD_CSTOR(CDevoutDecreeCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDrawnFromDreamsCard : public CCard
{
	DECLARE_CARD_CSTOR(CDrawnFromDreamsCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEngulfingEruptionCard : public CCard
{
	DECLARE_CARD_CSTOR(CEngulfingEruptionCard);
};

//____________________________________________________________________________
//
class CEternalIsolationCard : public CCard
{
	DECLARE_CARD_CSTOR(CEternalIsolationCard);

protected:
	bool BeforeBottom(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFloodOfTearsCard : public CCard
{
	DECLARE_CARD_CSTOR(CFloodOfTearsCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_PermanentFilter;
};

//____________________________________________________________________________
//
class CLegionsEndCard : public CCard
{
	DECLARE_CARD_CSTOR(CLegionsEndCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRecklessAirStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CRecklessAirStrikeCard);
};

//____________________________________________________________________________
//
class CSchemingSymmetryCard : public CCard
{
	DECLARE_CARD_CSTOR(CSchemingSymmetryCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThoughtDistortionCard : public CCard
{
	DECLARE_CARD_CSTOR(CThoughtDistortionCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWingedWordsCard : public CCard
{
	DECLARE_CARD_CSTOR(CWingedWordsCard);

protected:
	BOOL HasNoFlyer(BOOL bIncludeTricks);
	BOOL HasFlyer(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CAetherGustCard : public CCard
{
	DECLARE_CARD_CSTOR(CAetherGustCard);

protected:
	bool BeforePermanent(CAbilityAction* pAction);
	void OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PlaceSelection;
};

//____________________________________________________________________________
//
class CBroughtBackCard : public CCard
{
	DECLARE_CARD_CSTOR(CBroughtBackCard);

public:
	BOOL WasPutThisTurn(const CCard* pCard) const;

protected:
	bool SetMovedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable std::vector<const CCard*> m_Moved;	// permanents put into a graveyard from the battlefield this turn
};

//____________________________________________________________________________
//
class CDarkRemedyCard : public CCard
{
	DECLARE_CARD_CSTOR(CDarkRemedyCard);
};

//____________________________________________________________________________
//
class CFlameSweepCard : public CCard
{
	DECLARE_CARD_CSTOR(CFlameSweepCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFryCard : public CCard
{
	DECLARE_CARD_CSTOR(CFryCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGrowthCycleCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrowthCycleCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CInfuriateCard : public CCard
{
	DECLARE_CARD_CSTOR(CInfuriateCard);
};

//____________________________________________________________________________
//
class CMasterfulReplicationCard : public CCard
{
	DECLARE_CARD_CSTOR(CMasterfulReplicationCard);
};

//____________________________________________________________________________
//
class CNoxiousGraspCard : public CCard
{
	DECLARE_CARD_CSTOR(CNoxiousGraspCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSharedSummonsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSharedSummonsCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTalesEndCard : public CCard
{
	DECLARE_CARD_CSTOR(CTalesEndCard);
};

//____________________________________________________________________________
//
class CVeilOfSummerCard : public CCard
{
	DECLARE_CARD_CSTOR(CVeilOfSummerCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeResolution(CAbilityAction* pAction);

	mutable int m_nTurn;	// the last turn an opponent cast a blue or black spell
};

//____________________________________________________________________________
//
class CAngelicGuardianCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelicGuardianCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attackSubject) const;
	bool BeforeIndestructible(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CAngelOfVitalityCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfVitalityCard);

protected:
	bool SetLifeContext(CTriggeredAbility<>::TriggerContextType& triggerContext, const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeGainLife(CTriggeredAbility<>::TriggeredActionType* pAction);

	static bool s_bGaining;	// the extra life is being gained (it doesn't trigger any Angel of Vitality again)
};

//____________________________________________________________________________
//
class CApostleOfPurifyingLightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CApostleOfPurifyingLightCard);
};

//____________________________________________________________________________
//
class CBattalionFootSoldierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBattalionFootSoldierCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_NameFilter;
};

//____________________________________________________________________________
//
class CBishopOfWingsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBishopOfWingsCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforeSpirit(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCavalierOfDawnCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCavalierOfDawnCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDawningAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDawningAngelCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGoldmaneGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGoldmaneGriffinCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHangedExecutionerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHangedExecutionerCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHeraldOfTheSunCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHeraldOfTheSunCard);
};

//____________________________________________________________________________
//
class CImperialOutriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImperialOutriderCard);
};

//____________________________________________________________________________
//
class CLoxodonLifechanterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoxodonLifechanterCard);

protected:
	bool BeforeSetLife(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLoyalPegasusCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLoyalPegasusCard);
};

//____________________________________________________________________________
//
class CSavannahSageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSavannahSageCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSepharaSkysBladeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSepharaSkysBladeCard);

protected:
	CCardFilter m_FlyerFilter;
};

//____________________________________________________________________________
//
class CSquadCaptainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSquadCaptainCard);

protected:
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

//____________________________________________________________________________
//
class CStarfieldMysticCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStarfieldMysticCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSteadfastSentryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteadfastSentryCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTwinbladePaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTwinbladePaladinCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

//____________________________________________________________________________
//
class CBarkhideTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBarkhideTrollCard);

protected:
	bool BeforeHexproof(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBrightwoodTrackerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrightwoodTrackerCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCavalierOfThornsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCavalierOfThornsCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CElvishReclaimerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElvishReclaimerCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEtherealElkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEtherealElkCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFerociousPupCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFerociousPupCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGargosViciousWatcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGargosViciousWatcherCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeFight(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGnarlbackRhinoCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGnarlbackRhinoCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeDraw(CAbilityAction* pAction);

	mutable const void* m_pLastSpell;	// the spell of the last trigger
};

//____________________________________________________________________________
//
class CHealerOfTheGladeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHealerOfTheGladeCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHowlingGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHowlingGiantCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLeafkinDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLeafkinDruidCard);

protected:
	BOOL HasFewCreatures(BOOL bIncludeTricks);
	BOOL HasFourCreatures(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CLoamingShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoamingShamanCard);

protected:
	bool BeforeShuffle(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CNightpackAmbusherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNightpackAmbusherCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeToken(CAbilityAction* pAction);

	mutable int m_nTurn;	// the last turn its controller cast a spell
};

//____________________________________________________________________________
//
class COvergrowthElementalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COvergrowthElementalCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool BeforeCounter(CAbilityAction* pAction);
	bool SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeGainLife(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CShiftingCeratopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShiftingCeratopsCard);

protected:
	bool BeforeReach(CAbilityAction* pAction);
	bool BeforeTrample(CAbilityAction* pAction);
	bool BeforeHaste(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSilverbackShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSilverbackShamanCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThicketCrasherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThicketCrasherCard);
};

//____________________________________________________________________________
//
class CViviensCrocodileCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CViviensCrocodileCard);
};

//____________________________________________________________________________
//
class CVoraciousHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVoraciousHydraCard);

protected:
	BOOL Never(BOOL bIncludeTricks) { return FALSE; }
	bool BeforeResolution(CAbilityAction* pAction);
	bool BeforeMode(CAbilityAction* pAction);
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	int m_nX;
};

//____________________________________________________________________________
//
class CWakerootElementalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWakerootElementalCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWoodlandChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWoodlandChampionCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWoodlandMysticCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWoodlandMysticCard);
};

//____________________________________________________________________________
//
class CCavalierOfFlameCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCavalierOfFlameCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeRummage(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChandrasEmbercatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChandrasEmbercatCard);
};

//____________________________________________________________________________
//
class CDaggersailAeronautCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDaggersailAeronautCard);

protected:
	CDuringYourTurnSupport m_DuringYourTurn;
};

//____________________________________________________________________________
//
class CDestructiveDiggerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDestructiveDiggerCard);

protected:
	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CDrakusethMawOfFlamesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDrakusethMawOfFlamesCard);

protected:
	bool BeforeDamage4(CAbilityAction* pAction);
	bool BeforeDamage3(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGlintHornBuccaneerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGlintHornBuccaneerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	BOOL IsAttackingNow(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CGoblinBirdGrabberCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinBirdGrabberCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
	BOOL ControlsFlyer(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CGoblinSmugglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinSmugglerCard);
};

//____________________________________________________________________________
//
class CImmortalPhoenixCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CImmortalPhoenixCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLavakinBrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLavakinBrawlerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMaraudingRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMaraudingRaptorCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CNimbleBirdstickerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNimbleBirdstickerCard);
};

//____________________________________________________________________________
//
class CPackMastiffCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPackMastiffCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPyroclasticElementalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPyroclasticElementalCard);
};

//____________________________________________________________________________
//
class CRapaciousDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRapaciousDragonCard);

protected:
	bool BeforeTreasures(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CScamperingScorcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScamperingScorcherCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CScorchSpitterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScorchSpitterCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback, &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CThunderkinAwakenerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThunderkinAwakenerCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CUnchainedBerserkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUnchainedBerserkerCard);
};

//____________________________________________________________________________
//
class CWildfireElementalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWildfireElementalCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
						   CWhenDamageDealt::PlayerEventCallback, &CWhenDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAudaciousThiefCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAudaciousThiefCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBlightbeetleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBlightbeetleCard);
};

//____________________________________________________________________________
//
class CBloodBurglarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodBurglarCard);

protected:
	CDuringYourTurnSupport m_DuringYourTurn;
};

//____________________________________________________________________________
//
class CBloodthirstyAerialistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodthirstyAerialistCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

//____________________________________________________________________________
//
class CBonecladNecromancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBonecladNecromancerCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCavalierOfNightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCavalierOfNightCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
class CDreadPresenceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDreadPresenceCard);

protected:
	bool BeforeMode(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEmbodimentOfAgoniesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEmbodimentOfAgoniesCard);

protected:
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
};

//____________________________________________________________________________
//
class CGorgingVultureCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGorgingVultureCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGruesomeScourgerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGruesomeScourgerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKnightOfTheEbonLegionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfTheEbonLegionCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeCounter(CAbilityAction* pAction);
	BOOL PlayerLostFourLife() const;
};

//____________________________________________________________________________
//
class CRottingRegisaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRottingRegisaurCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSavageGorgerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSavageGorgerCard);

protected:
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSorcererOfTheFangCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSorcererOfTheFangCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSorinsGuideCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSorinsGuideCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThirstingBloodlordCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThirstingBloodlordCard);
};

//____________________________________________________________________________
//
class CUndeadServantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUndeadServantCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVampireOfTheDireMoonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireOfTheDireMoonCard);
};

//____________________________________________________________________________
//
class CVengefulWarchiefCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVengefulWarchiefCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;

	mutable int m_nTurn;	// the last turn its controller lost life
};

//____________________________________________________________________________
//
class CVilisBrokerOfBloodCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVilisBrokerOfBloodCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

	bool SetLifeContext(CTriggeredAbility<>::TriggerContextType& triggerContext, const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeDraw(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CYaroksFenlurkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYaroksFenlurkerCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAgentOfTreacheryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAgentOfTreacheryCard);

protected:
	bool BeforeControl(CAbilityAction* pAction);
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDraw(CAbilityAction* pAction);
	int CountNotOwned(CPlayer* pPlayer) const;
};

//____________________________________________________________________________
//
class CAtemsisAllSeeingCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAtemsisAllSeeingCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback, &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool BeforeDraw(CAbilityAction* pAction);
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeReveal(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CBorealElementalCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBorealElementalCard);
};

//____________________________________________________________________________
//
class CBrinebornCutthroatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrinebornCutthroatCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCavalierOfGalesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCavalierOfGalesCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeShuffle(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCelestialMessengerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCelestialMessengerCard);
};

//____________________________________________________________________________
//
class CCeruleanDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCeruleanDrakeCard);

protected:
	CCardFilter m_NothingFilter;
};

//____________________________________________________________________________
//
class CCloudkinSeerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCloudkinSeerCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDungeonGeistsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDungeonGeistsCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
	bool BeforeLeave(CAbilityAction* pAction);

	CCountedCardContainer_ m_Tapped;	// the creature that doesn't untap while this creature remains
};

//____________________________________________________________________________
//
class CFaerieMiscreantCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFaerieMiscreantCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFrostLynxCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrostLynxCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMoatPiranhasCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMoatPiranhasCard);
};

//____________________________________________________________________________
//
class COctoprophetCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COctoprophetCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRenownedWeaponsmithCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRenownedWeaponsmithCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_NameFilter;
};

//____________________________________________________________________________
//
class CScholarOfTheAgesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScholarOfTheAgesCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpectralSailorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSpectralSailorCard);
};

//____________________________________________________________________________
//
class CWardenOfEvosIsleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWardenOfEvosIsleCard);
};

//____________________________________________________________________________
//
class CWaterkinShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWaterkinShamanCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CYanlingsHarbingerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CYanlingsHarbingerCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CYaroksWavecrasherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYaroksWavecrasherCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
class CCorpseKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCorpseKnightCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeLoseLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCreepingTrailblazerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCreepingTrailblazerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEmpyreanEagleCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEmpyreanEagleCard);
};

//____________________________________________________________________________
//
class CIronrootWarlordCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIronrootWarlordCard);
};

//____________________________________________________________________________
//
class CKaaliaZenithSeekerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKaaliaZenithSeekerCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_TypeFilter;
};

//____________________________________________________________________________
//
class CKethisTheHiddenHandCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKethisTheHiddenHandCard);
};

//____________________________________________________________________________
//
class CKykarWindsFuryCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CKykarWindsFuryCard);

protected:
	bool BeforeSpirit(CAbilityAction* pAction);

	CCardFilter m_SpiritFilter;
};

//____________________________________________________________________________
//
class CLightningStormkinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLightningStormkinCard);
};

//____________________________________________________________________________
//
class COgreSiegebreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COgreSiegebreakerCard);
};

//____________________________________________________________________________
//
class COmnathLocusOfTheRoilCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COmnathLocusOfTheRoilCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRienneAngelOfRebirthCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRienneAngelOfRebirthCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CRisenReefCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRisenReefCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
	void OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PlaceSelection;
};

//____________________________________________________________________________
//
class CSkyknightVanguardCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkyknightVanguardCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTomeboundLichCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTomeboundLichCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CYarokTheDesecratedCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CYarokTheDesecratedCard);
};

//____________________________________________________________________________
//
class CDiamondKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDiamondKnightCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);

	CSelectionSupport m_ColorSelection;
	DWORD m_dwChosenColor;	// 1..5 (white, blue, black, red, green), 0 before choosing
};

//____________________________________________________________________________
//
class CGolosTirelessPilgrimCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGolosTirelessPilgrimCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPatternMatcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPatternMatcherCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSalvagerOfRuinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSalvagerOfRuinCard);

public:
	BOOL WasPutThisTurn(const CCard* pCard) const;

protected:
	bool SetMovedContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;

	mutable int m_nTurn;
	mutable std::vector<const CCard*> m_Moved;	// permanents put into a graveyard from the battlefield this turn
};

//____________________________________________________________________________
//
