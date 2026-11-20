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

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Proliferate (as Contagion Clasp and Steady Progress in Scars of Mirrodin): member CProliferateSupport m_Proliferate,
// initialized with m_Proliferate(this); AddProliferateTrigger() in the constructor registers the special trigger that
// chooses the permanents (CTriggeredProliferateAbility, without the stack), and Proliferate(controller) from a resolution
// callback fires it and then lets the controller choose the players with poison counters.
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

//____________________________________________________________________________
//
class CBlastZoneCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CBlastZoneCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
	void OnCounterMoved(CCard* pFromCard, LPCTSTR name, int old, int n_value);

	ListenerPtr<CounterMovedEventSource::Listener> m_cpCListener;
	int m_nChargeCounters;	// charge counters while it was on the battlefield (it's sacrificed as a cost)
};

//____________________________________________________________________________
//
class CEmergenceZoneCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CEmergenceZoneCard);

protected:
	bool BeforeFlash(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CInterplanarBeaconCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CInterplanarBeaconCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKarnsBastionCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CKarnsBastionCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
// The cost reductions of Mobilized District: one ability for each reduction
#define MOBILIZED_DISTRICT_CONDITION(n)	BOOL HasLegends##n(BOOL bIncludeTricks) { return CountLegends() >= n; }

class CMobilizedDistrictCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMobilizedDistrictCard);

protected:
	int CountLegends() const;
	MOBILIZED_DISTRICT_CONDITION(1)
	MOBILIZED_DISTRICT_CONDITION(2)
	MOBILIZED_DISTRICT_CONDITION(3)
	MOBILIZED_DISTRICT_CONDITION(4)
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// "During your turn, <static ability>": the static abilities aren't reevaluated when the turn changes, so this class
// starts them at the beginning of your upkeep and ends them at the beginning of the other players' upkeeps (and when the
// permanent enters during another player's turn), with StartEnchantment / EndEnchantment (as the Commander module).
// Member CDuringYourTurnSupport m_DuringYourTurn, initialized with m_DuringYourTurn(this); Add(enchantment) for each
// static ability and AddTurnTriggers() once in the constructor.
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

//____________________________________________________________________________
//
class CAjaniTheGreatheartedCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniTheGreatheartedCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforeCounters(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAngrathCaptainOfChaosCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAngrathCaptainOfChaosCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CArlinnVoiceOfThePackCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CArlinnVoiceOfThePackCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeWolf(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAshiokDreamRenderCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAshiokDreamRenderCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDavrielRogueShadowmageCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDavrielRogueShadowmageCard);

protected:
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDamage(TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged >::TriggeredActionType* pAction);
	bool BeforeDiscard(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDomriAnarchOfBolasCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDomriAnarchOfBolasCard);

protected:
	bool BeforeRedMana(CAbilityAction* pAction);
	bool BeforeGreenMana(CAbilityAction* pAction);
	void CreatureSpellsCantBeCountered(CPlayer* pPlayer);
	bool BeforeFight(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDovinHandOfControlCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDovinHandOfControlCard);

protected:
	bool BeforePrevent(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGideonBlackbladeCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CGideonBlackbladeCard);

protected:
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	void Animate() const;
	bool BeforeKeyword(CAbilityAction* pAction);
	void OnKeywordSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_KeywordSelection;
};

//____________________________________________________________________________
//
class CGideonTheOathswornCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CGideonTheOathswornCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback,
						   &CWhenAttackedBlocked::SetAttackingEventCallback > AttackTriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeCounter(AttackTriggeredAbility::TriggeredActionType* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHuatliTheSunsHeartCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CHuatliTheSunsHeartCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CJaceArcaneStrategistCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJaceArcaneStrategistCard);

protected:
	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeUnblockable(CAbilityAction* pAction);

	mutable int m_nDrawTurn;	// the turn of the counted draws
	mutable int m_nDraws;
};

//____________________________________________________________________________
//
class CJaceWielderOfMysteriesCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJaceWielderOfMysteriesCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CJayaVeneratedFiremageCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJayaVeneratedFiremageCard);
};

//____________________________________________________________________________
//
class CJiangYangguWildcrafterCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CJiangYangguWildcrafterCard);
};

//____________________________________________________________________________
//
class CKarnTheGreatCreatorCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CKarnTheGreatCreatorCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_ArtifactFilter;
};

//____________________________________________________________________________
//
class CKasminaEnigmaticMentorCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CKasminaEnigmaticMentorCard);

protected:
	bool BeforeWizard(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKayaBaneOfTheDeadCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CKayaBaneOfTheDeadCard);
};

//____________________________________________________________________________
//
class CKioraBehemothBeckonerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CKioraBehemothBeckonerCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLilianaDreadhordeGeneralCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CLilianaDreadhordeGeneralCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeZombie(CAbilityAction* pAction);
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CNahiriStormOfStoneCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNahiriStormOfStoneCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);

	CDuringYourTurnSupport m_DuringYourTurn;
};

//____________________________________________________________________________
//
class CNarsetParterOfVeilsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNarsetParterOfVeilsCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_NoncreatureNonlandFilter;
};

//____________________________________________________________________________
//
class CNicolBolasDragonGodCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNicolBolasDragonGodCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	void OnExileSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeUltimate(CAbilityAction* pAction);

	CSelectionSupport m_ExileSelection;
};

//____________________________________________________________________________
//
class CNissaWhoShakesTheWorldCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNissaWhoShakesTheWorldCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredSpecialProdManaAbility, CWhenTappedForMana > ManaTriggeredAbility;

	bool SetManaContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
		const CManaProductionAbilityAction* pManaAction) const;
	bool BeforeAnimate(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);

	ManaTriggeredAbility* m_pManaAbility;
};

//____________________________________________________________________________
//
class CObNixilisTheHateTwistedCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CObNixilisTheHateTwistedCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDrew > DrawTriggeredAbility;

	bool SetDrawContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeDamage(DrawTriggeredAbility::TriggeredActionType* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRalStormConduitCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CRalStormConduitCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSaheeliSublimeArtificerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSaheeliSublimeArtificerCard);

protected:
	bool BeforeServo(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSamutTyrantSmasherCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSamutTyrantSmasherCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSarkhanTheMasterlessCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSarkhanTheMasterlessCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback,
						   &CWhenAttackedBlocked::SetAttackingEventCallback > AttackTriggeredAbility;

	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeDragons(AttackTriggeredAbility::TriggeredActionType* pAction);
	bool BeforeAnimate(CAbilityAction* pAction);
	bool BeforeDragon(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSorinVengefulBloodlordCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSorinVengefulBloodlordCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CDuringYourTurnSupport m_DuringYourTurn;
};

//____________________________________________________________________________
//
class CTamiyoCollectorOfTalesCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTamiyoCollectorOfTalesCard);

protected:
	bool BeforeChooseName(CAbilityAction* pAction);
	void OnNameSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_NameSelection;
	std::vector<CString> m_Names;
};

//____________________________________________________________________________
//
class CTeferiTimeRavelerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTeferiTimeRavelerCard);

protected:
	bool BeforeFlash(CAbilityAction* pAction);
	bool BeforeBounce(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTeyoTheShieldmageCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTeyoTheShieldmageCard);

protected:
	bool BeforeWall(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTezzeretMasterOfTheBridgeCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTezzeretMasterOfTheBridgeCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTheWandererCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTheWandererCard);
};

//____________________________________________________________________________
//
class CTibaltRakishInstigatorCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTibaltRakishInstigatorCard);

protected:
	bool BeforeDevil(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CUginTheIneffableCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CUginTheIneffableCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved >::TriggeredActionType* pAction);

	mutable std::vector<std::pair<CCard*, CCard*>> m_Exiled;	// (Spirit token, exiled card)
};

//____________________________________________________________________________
//
class CVivienChampionOfTheWildsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVivienChampionOfTheWildsCard);

protected:
	bool BeforeKeywords(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVraskaSwarmsEminenceCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVraskaSwarmsEminenceCard);

protected:
	bool SetPlayerDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	bool SetPlaneswalkerDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, CPlaneswalkerCard* pToPlaneswalker, Damage damage) const;
	bool BeforeCounter(TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt, CWhenDamageDealt::PlayerEventCallback,
		&CWhenDamageDealt::SetPlayerEventCallback >::TriggeredActionType* pAction);
	bool BeforeCounter2(TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt, CWhenDamageDealt::PlaneswalkerEventCallback,
		&CWhenDamageDealt::SetPlaneswalkerEventCallback >::TriggeredActionType* pAction);
	bool BeforeAssassin(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CFiremindVesselCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFiremindVesselCard);
};

//____________________________________________________________________________
//
class CGodPharaohsStatueCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGodPharaohsStatueCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGuildGlobeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGuildGlobeCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CManaGeodeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CManaGeodeCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMizziumTankCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMizziumTankCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);

	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
class CParhelionIICard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CParhelionIICard);

protected:
	CCrewSupport m_Crew;
};

//____________________________________________________________________________
//
class CSilentSubmersibleCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSilentSubmersibleCard);

protected:
	CCrewSupport m_Crew;
};

//____________________________________________________________________________
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

class CViviensArkbowCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CViviensArkbowCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	int m_nX;
	CCardFilter m_CreatureFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
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

//____________________________________________________________________________
//
class CAidTheFallenCard : public CCard
{
	DECLARE_CARD_CSTOR(CAidTheFallenCard);

protected:
	bool BeforeBoth(CAbilityAction* pAction);

	CCardFilter m_PlaneswalkerFilter;
};

//____________________________________________________________________________
//
class CAngrathsRampageCard : public CCard
{
	DECLARE_CARD_CSTOR(CAngrathsRampageCard);

protected:
	bool BeforeArtifact(CAbilityAction* pAction);
	bool BeforeCreature(CAbilityAction* pAction);
	bool BeforePlaneswalker(CAbilityAction* pAction);

	CCardFilter m_PlaneswalkerFilter;
};

//____________________________________________________________________________
//
class CBleedingEdgeCard : public CCard
{
	DECLARE_CARD_CSTOR(CBleedingEdgeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBondOfDisciplineCard : public CCard
{
	DECLARE_CARD_CSTOR(CBondOfDisciplineCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBondOfFlourishingCard : public CCard
{
	DECLARE_CARD_CSTOR(CBondOfFlourishingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_PermanentFilter;
};

//____________________________________________________________________________
//
class CBondOfInsightCard : public CCard
{
	DECLARE_CARD_CSTOR(CBondOfInsightCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBondOfPassionCard : public CCard
{
	DECLARE_CARD_CSTOR(CBondOfPassionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBondOfRevivalCard : public CCard
{
	DECLARE_CARD_CSTOR(CBondOfRevivalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCallousDismissalCard : public CCard
{
	DECLARE_CARD_CSTOR(CCallousDismissalCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCasualtiesOfWarCard : public CCard
{
	DECLARE_CARD_CSTOR(CCasualtiesOfWarCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCommandTheDreadhordeCard : public CCard
{
	DECLARE_CARD_CSTOR(CCommandTheDreadhordeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CContentiousPlanCard : public CCard
{
	DECLARE_CARD_CSTOR(CContentiousPlanCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CCourageInCrisisCard : public CCard
{
	DECLARE_CARD_CSTOR(CCourageInCrisisCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CDavrielsShadowfugueCard : public CCard
{
	DECLARE_CARD_CSTOR(CDavrielsShadowfugueCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDeliverUntoEvilCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeliverUntoEvilCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
	std::vector<CCard*> m_Cards;	// the targets, until the opponent chooses
};

//____________________________________________________________________________
//
class CDomrisAmbushCard : public CCard
{
	DECLARE_CARD_CSTOR(CDomrisAmbushCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEnterTheGodEternalsCard : public CCard
{
	DECLARE_CARD_CSTOR(CEnterTheGodEternalsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFinaleOfDevastationCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinaleOfDevastationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	int m_nX;
	CCardFilter m_CreatureFilter;
};

//____________________________________________________________________________
//
class CFinaleOfEternityCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinaleOfEternityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFinaleOfGloryCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinaleOfGloryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFinaleOfRevelationCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinaleOfRevelationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGideonsBattleCryCard : public CCard
{
	DECLARE_CARD_CSTOR(CGideonsBattleCryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHonorTheGodPharaohCard : public CCard
{
	DECLARE_CARD_CSTOR(CHonorTheGodPharaohCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CInvadeTheCityCard : public CCard
{
	DECLARE_CARD_CSTOR(CInvadeTheCityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CJacesRuseCard : public CCard
{
	DECLARE_CARD_CSTOR(CJacesRuseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CJacesTriumphCard : public CCard
{
	DECLARE_CARD_CSTOR(CJacesTriumphCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CNeoformCard : public CCard
{
	DECLARE_CARD_CSTOR(CNeoformCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	int m_nManaValue;
	CCardFilter m_SearchFilter;
};

//____________________________________________________________________________
//
class CNissasTriumphCard : public CCard
{
	DECLARE_CARD_CSTOR(CNissasTriumphCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_BasicForestFilter;
};

//____________________________________________________________________________
//
class CPlanewideCelebrationCard : public CCard
{
	DECLARE_CARD_CSTOR(CPlanewideCelebrationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void AskMode(CPlayer* pPlayer);
	void OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ModeSelection;
	CProliferateSupport m_Proliferate;
	CCardFilter m_PermanentFilter;
	int m_nModesLeft;
};

//____________________________________________________________________________
//
class CPriceOfBetrayalCard : public CCard
{
	DECLARE_CARD_CSTOR(CPriceOfBetrayalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCountersSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CounterSelection;
};

//____________________________________________________________________________
//
class CRavnicaAtWarCard : public CCard
{
	DECLARE_CARD_CSTOR(CRavnicaAtWarCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRelentlessAdvanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CRelentlessAdvanceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRoleReversalCard : public CCard
{
	DECLARE_CARD_CSTOR(CRoleReversalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSingleCombatCard : public CCard
{
	DECLARE_CARD_CSTOR(CSingleCombatCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnKeepSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_KeepSelection;
	CCardFilter m_CreaturePlaneswalkerFilter;
};

//____________________________________________________________________________
//
class CSolarBlazeCard : public CCard
{
	DECLARE_CARD_CSTOR(CSolarBlazeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSparkHarvestCard : public CCard
{
	DECLARE_CARD_CSTOR(CSparkHarvestCard);
};

//____________________________________________________________________________
//
class CStealthMissionCard : public CCard
{
	DECLARE_CARD_CSTOR(CStealthMissionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CStormTheCitadelCard : public CCard
{
	DECLARE_CARD_CSTOR(CStormTheCitadelCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTamiyosEpiphanyCard : public CCard
{
	DECLARE_CARD_CSTOR(CTamiyosEpiphanyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTheElderspellCard : public CCard
{
	DECLARE_CARD_CSTOR(CTheElderspellCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnPlaneswalkerSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PlaneswalkerSelection;
};

//____________________________________________________________________________
//
class CTimeWipeCard : public CCard
{
	DECLARE_CARD_CSTOR(CTimeWipeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTollOfTheInvasionCard : public CCard
{
	DECLARE_CARD_CSTOR(CTollOfTheInvasionCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);

	CCardFilter m_NonlandFilter;
};

//____________________________________________________________________________
//
class CWanderersStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CWanderersStrikeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CWidespreadBrutalityCard : public CCard
{
	DECLARE_CARD_CSTOR(CWidespreadBrutalityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
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
class CAwakeningOfVituGhaziCard : public CCard
{
	DECLARE_CARD_CSTOR(CAwakeningOfVituGhaziCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBandTogetherCard : public CCard
{
	DECLARE_CARD_CSTOR(CBandTogetherCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBattlefieldPromotionCard : public CCard
{
	DECLARE_CARD_CSTOR(CBattlefieldPromotionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBlindblastCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlindblastCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBoltBendCard : public CCard
{
	DECLARE_CARD_CSTOR(CBoltBendCard);

protected:
	BOOL CanCastFull(BOOL bIncludeTricks);
	BOOL CanCastReduced(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CChandrasTriumphCard : public CCard
{
	DECLARE_CARD_CSTOR(CChandrasTriumphCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCommenceTheEndgameCard : public CCard
{
	DECLARE_CARD_CSTOR(CCommenceTheEndgameCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCrushDissentCard : public CCounterSpellCard
{
	DECLARE_CARD_CSTOR(CCrushDissentCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDeathsproutCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeathsproutCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDesparkCard : public CCard
{
	DECLARE_CARD_CSTOR(CDesparkCard);
};

//____________________________________________________________________________
//
class CDesperateLungeCard : public CCard
{
	DECLARE_CARD_CSTOR(CDesperateLungeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDivineArrowCard : public CCard
{
	DECLARE_CARD_CSTOR(CDivineArrowCard);
};

//____________________________________________________________________________
//
class CDovinsVetoCard : public CCounterSpellCard
{
	DECLARE_CARD_CSTOR(CDovinsVetoCard);
};

//____________________________________________________________________________
//
class CForcedLandingCard : public CCard
{
	DECLARE_CARD_CSTOR(CForcedLandingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGideonsTriumphCard : public CCard
{
	DECLARE_CARD_CSTOR(CGideonsTriumphCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_AttackedFilter;
};

//____________________________________________________________________________
//
class CHeartfireCard : public CCard
{
	DECLARE_CARD_CSTOR(CHeartfireCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_PlaneswalkerFilter;
};

//____________________________________________________________________________
//
class CHeartwarmingRedemptionCard : public CCard
{
	DECLARE_CARD_CSTOR(CHeartwarmingRedemptionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CIgniteTheBeaconCard : public CCard
{
	DECLARE_CARD_CSTOR(CIgniteTheBeaconCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_PlaneswalkerFilter;
};

//____________________________________________________________________________
//
class CJayasGreetingCard : public CCard
{
	DECLARE_CARD_CSTOR(CJayasGreetingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLazotepPlatingCard : public CCard
{
	DECLARE_CARD_CSTOR(CLazotepPlatingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLilianasTriumphCard : public CCard
{
	DECLARE_CARD_CSTOR(CLilianasTriumphCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CNahirisStonebladesCard : public CCard
{
	DECLARE_CARD_CSTOR(CNahirisStonebladesCard);
};

//____________________________________________________________________________
//
class CNoEscapeCard : public CCounterSpellCard
{
	DECLARE_CARD_CSTOR(CNoEscapeCard);
};

//____________________________________________________________________________
//
class CObNixilissCrueltyCard : public CCard
{
	DECLARE_CARD_CSTOR(CObNixilissCrueltyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPledgeOfUnityCard : public CCard
{
	DECLARE_CARD_CSTOR(CPledgeOfUnityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRallyOfWingsCard : public CCard
{
	DECLARE_CARD_CSTOR(CRallyOfWingsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRalsOutburstCard : public CCard
{
	DECLARE_CARD_CSTOR(CRalsOutburstCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CReturnToNatureCard : public CCard
{
	DECLARE_CARD_CSTOR(CReturnToNatureCard);
};

//____________________________________________________________________________
//
class CSamutsSprintCard : public CCard
{
	DECLARE_CARD_CSTOR(CSamutsSprintCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSarkhansCatharsisCard : public CCard
{
	DECLARE_CARD_CSTOR(CSarkhansCatharsisCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSteadyAimCard : public CCard
{
	DECLARE_CARD_CSTOR(CSteadyAimCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTeferisTimeTwistCard : public CCard
{
	DECLARE_CARD_CSTOR(CTeferisTimeTwistCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CToppleTheStatueCard : public CCard
{
	DECLARE_CARD_CSTOR(CToppleTheStatueCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTyrantsScornCard : public CCard
{
	DECLARE_CARD_CSTOR(CTyrantsScornCard);
};

//____________________________________________________________________________
//
class CUnlikelyAidCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnlikelyAidCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CBulwarkGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBulwarkGiantCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCharmedStrayCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCharmedStrayCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEnforcerGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEnforcerGriffinCard);
};

//____________________________________________________________________________
//
class CGideonsCompanyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGideonsCompanyCard);

protected:
	bool SetLifeGainContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
};

//____________________________________________________________________________
//
class CGodEternalOketraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGodEternalOketraCard);

protected:
	bool BeforeZombie(CAbilityAction* pAction);
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeThirdFromTop(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGratefulApparitionCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGratefulApparitionCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CIroncladKrovodCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIroncladKrovodCard);
};

//____________________________________________________________________________
//
class CLawRuneEnforcerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLawRuneEnforcerCard);
};

//____________________________________________________________________________
//
class CLoxodonSergeantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoxodonSergeantCard);

protected:
	bool BeforeVigilance(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMakeshiftBattalionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMakeshiftBattalionCard);

protected:
	bool SetTriggerContext(CTriggeredModifyCreatureAbility::TriggerContextType& triggerContext, AttackSubject attacked) const;
};

//____________________________________________________________________________
//
class CMartyrForTheCauseCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMartyrForTheCauseCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CPouncingLynxCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPouncingLynxCard);

protected:
	CDuringYourTurnSupport m_DuringYourTurn;
};

//____________________________________________________________________________
//
class CRisingPopulaceCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRisingPopulaceCard);

protected:
	bool SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSunbladeAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSunbladeAngelCard);
};

//____________________________________________________________________________
//
class CTeyosLightshieldCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTeyosLightshieldCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTomikDistinguishedAdvokistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTomikDistinguishedAdvokistCard);
};

//____________________________________________________________________________
//
class CTrustedPegasusCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTrustedPegasusCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWarScreecherCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWarScreecherCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CArborealGrazerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArborealGrazerCard);

protected:
	bool BeforeLand(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CArlinnsWolfCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArlinnsWolfCard);

protected:
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CBloomHulkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloomHulkCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CCentaurNurturerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCentaurNurturerCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChallengerTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChallengerTrollCard);
};

//____________________________________________________________________________
//
class CEvolutionSageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEvolutionSageCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CGodEternalRhonasCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGodEternalRhonasCard);

protected:
	bool BeforeDouble(CAbilityAction* pAction);
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeThirdFromTop(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKraulStingerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKraulStingerCard);
};

//____________________________________________________________________________
//
class CKronchWranglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKronchWranglerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMowuLoyalCompanionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMowuLoyalCompanionCard);

protected:
	bool SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value);
	bool BeforeExtraCounter(CAbilityAction* pAction);

	BOOL m_bAddingExtra;
};

//____________________________________________________________________________
//
class CParadiseDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CParadiseDruidCard);
};

//____________________________________________________________________________
//
class CPollenbrightDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPollenbrightDruidCard);

protected:
	bool BeforeMode(CAbilityAction* pAction);
	void OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ModeSelection;
	CSelectionSupport m_CreatureSelection;
	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CSnarespinnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSnarespinnerCard);

protected:
	bool SetBlockContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCreatureCard* pCreature1, CCreatureCard* pCreature2, int n1, int n2) const;
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThunderingCeratokCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThunderingCeratokCard);

protected:
	bool BeforeTrample(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CViviensGrizzlyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CViviensGrizzlyCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_CreaturePlaneswalkerFilter;
};

//____________________________________________________________________________
//
class CWardscaleCrocodileCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWardscaleCrocodileCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CAhnCropInvaderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAhnCropInvaderCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CDuringYourTurnSupport m_DuringYourTurn;
	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
class CBurningProphetCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBurningProphetCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CChainwhipCyclopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChainwhipCyclopsCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCyclopsElectromancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCyclopsElectromancerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDevouringHellionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDevouringHellionCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CDreadhordeTwinsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDreadhordeTwinsCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGoblinAssailantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinAssailantCard);
};

//____________________________________________________________________________
//
class CGoblinAssaultTeamCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinAssaultTeamCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGrimInitiateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrimInitiateCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CIlhargTheRazeBoarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIlhargTheRazeBoarCard);

protected:
	bool BeforePutCreature(CAbilityAction* pAction);
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeThirdFromTop(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CInvadingManticoreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInvadingManticoreCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKrenkoTinStreetKingpinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKrenkoTinStreetKingpinCard);

protected:
	bool BeforeGoblins(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CNehebDreadhordeChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNehebDreadhordeChampionCard);

protected:
	bool BeforeRummage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRagingKronchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRagingKronchCard);
};

//____________________________________________________________________________
//
class CSpellgorgerWeirdCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpellgorgerWeirdCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTibaltsRagerCard : public CPumpCreatureCard
{
	DECLARE_CARD_CSTOR(CTibaltsRagerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTurretOgreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTurretOgreCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CBanehoundCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBanehoundCard);
};

//____________________________________________________________________________
//
class CCharityExtractorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCharityExtractorCard);
};

//____________________________________________________________________________
//
class CDreadmalkinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDreadmalkinCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CDuskmantleOperativeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDuskmantleOperativeCard);

protected:
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CEternalTaskmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEternalTaskmasterCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGodEternalBontuCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGodEternalBontuCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeThirdFromTop(CAbilityAction* pAction);

	CCardFilter m_OtherPermanentFilter;
};

//____________________________________________________________________________
//
class CHeraldOfTheDreadhordeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeraldOfTheDreadhordeCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLazotepBehemothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLazotepBehemothCard);
};

//____________________________________________________________________________
//
class CLazotepReaverCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLazotepReaverCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMassacreGirlCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMassacreGirlCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
	bool SetDiesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeShrinkAgain(CAbilityAction* pAction);
	void ShrinkOthers(int nAmount);

	int m_nActiveTurn;	// the turn in which "whenever a creature dies this turn" works (-1: none)
};

//____________________________________________________________________________
//
class CShriekdiverCard : public CPumpCreatureCard
{
	DECLARE_CARD_CSTOR(CShriekdiverCard);
};

//____________________________________________________________________________
//
class CSparkReaperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSparkReaperCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);

	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CTithebearerGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTithebearerGiantCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVampireOpportunistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireOpportunistCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVizierOfTheScorpionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVizierOfTheScorpionCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVraskasFinisherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVraskasFinisherCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CAshioksSkulkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAshioksSkulkerCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CAvenEternalCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenEternalCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CErraticVisionaryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CErraticVisionaryCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEternalSkylordCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEternalSkylordCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFblthpTheLostCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFblthpTheLostCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeShuffle(CAbilityAction* pAction);

	mutable int m_nDraw;
};

//____________________________________________________________________________
//
class CFluxChannelerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFluxChannelerCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CGodEternalKefnetCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGodEternalKefnetCard);

protected:
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeThirdFromTop(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGuildpactInformantCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGuildpactInformantCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CJacesProjectionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJacesProjectionCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKiorasDambreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKiorasDambreakerCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CNagaEternalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNagaEternalCard);
};

//____________________________________________________________________________
//
class CRescuerSphinxCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRescuerSphinxCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_ReturnFilter;
};

//____________________________________________________________________________
//
class CSkyTheaterStrixCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkyTheaterStrixCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpellkeeperWeirdCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpellkeeperWeirdCard);
};

//____________________________________________________________________________
//
class CThunderDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CThunderDrakeCard);

protected:
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeCounter(CAbilityAction* pAction);

	mutable int m_nTurn;
	mutable int m_nSpells;
};

//____________________________________________________________________________
//
class CWallOfRunesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWallOfRunesCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CBioessenceHydraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBioessenceHydraCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCounterMoved > CounterTriggeredAbility;

	bool BeforeEnterCounters(CAbilityAction* pAction);
	bool SetLoyaltyContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value);
	bool BeforeLoyaltyCounters(CounterTriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CCruelCelebrantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCruelCelebrantCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDreadhordeButcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDreadhordeButcherCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEliteGuardmageCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CEliteGuardmageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGleamingOverseerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGleamingOverseerCard);

protected:
	bool BeforeAmass(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHuatlisRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHuatlisRaptorCard);

protected:
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CIronBullyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIronBullyCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLeylineProwlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLeylineProwlerCard);
};

//____________________________________________________________________________
//
class CLivingTwisterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLivingTwisterCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeReturnLand(CAbilityAction* pAction);

	CCardFilter m_TappedLandFilter;
};

//____________________________________________________________________________
//
class CMayhemDevilCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMayhemDevilCard);

protected:
	bool SetSacrificeContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMerfolkSkydiverCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMerfolkSkydiverCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CNivMizzetRebornCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNivMizzetRebornCard);

protected:
	bool BeforeReveal(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPrismiteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPrismiteCard);
};

//____________________________________________________________________________
//
class CRoaleskApexHybridCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRoaleskApexHybridCard);

protected:
	bool BeforeCounters(CAbilityAction* pAction);
	bool BeforeProliferate(CAbilityAction* pAction);

	CProliferateSupport m_Proliferate;
};

//____________________________________________________________________________
//
class CRubblebeltRiotersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRubblebeltRiotersCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSaheelisSilverwingCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSaheelisSilverwingCard);
};

//____________________________________________________________________________
//
class CSoulDivinerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSoulDivinerCard);

protected:
	CCardFilter m_PermanentFilter;
};

//____________________________________________________________________________
//
class CStorrevDevkarinLichCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStorrevDevkarinLichCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTenthDistrictLegionnaireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTenthDistrictLegionnaireCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTolsimirFriendToWolvesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTolsimirFriendToWolvesCard);

protected:
	bool BeforeVoja(CAbilityAction* pAction);
	bool SetWolfContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeFight(CAbilityAction* pAction);

	mutable CCard* m_pWolf;		// the Wolf that entered
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CDreadhordeInvasionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDreadhordeInvasionCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback,
						   &CWhenAttackedBlocked::SetAttackingEventCallback > AttackTriggeredAbility;

	bool BeforeAmass(CAbilityAction* pAction);
	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeLifelink(AttackTriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CKayasGhostformCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CKayasGhostformCard);

protected:
	bool SetLeaveContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);

	mutable CCard* m_pCard;		// the enchanted creature that died or was exiled
};

//____________________________________________________________________________
//
class CNewHorizonsCard : public CCard
{
	DECLARE_CARD_CSTOR(CNewHorizonsCard);

protected:
	counted_ptr<CAbility> CreateEnchantAbility(CCard* pEnchantedCard, CCard* pEnchantCard, ContextValue_& contextValue);
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COathOfKayaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COathOfKayaCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback,
						   &CWhenAttackedBlocked::SetAttackingEventCallback > AttackTriggeredAbility;

	bool BeforeDamage(CAbilityAction* pAction);
	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeDrain(AttackTriggeredAbility::TriggeredActionType* pAction);

	mutable int m_nTurn;				// the turn of the last trigger (once per combat)
	mutable const CPlayer* m_pAttacker;	// the opponent of that trigger
};

//____________________________________________________________________________
//
class CPrisonRealmCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPrisonRealmCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

//____________________________________________________________________________
//
