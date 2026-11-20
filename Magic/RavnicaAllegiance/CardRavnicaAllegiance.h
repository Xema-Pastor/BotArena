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

class CMentorSupport
{
public:
	CMentorSupport(CCreatureCard* pCreature);

	CAbility* AddMentorAbility();

protected:
	bool OnMentorResolving(CAbilityAction* pAction);

	CCreatureCard* m_pCreature;
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

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CPlazaOfHarmonyCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CPlazaOfHarmonyCard);

protected:
	bool SetGatesContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CDomriChaosBringerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDomriChaosBringerCard);

protected:
	bool BeforeRedMana(CAbilityAction* pAction);
	bool BeforeGreenMana(CAbilityAction* pAction);
	bool BeforeLook(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDomriCitySmasherCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDomriCitySmasherCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDovinArchitectOfLawCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDovinArchitectOfLawCard);

protected:
	bool BeforeGainDraw(CAbilityAction* pAction);
	bool BeforeTap(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDovinGrandArbiterCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CDovinGrandArbiterCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
						   CWhenDamageDealt::PlayerEventCallback,
						   &CWhenDamageDealt::SetPlayerEventCallback > DamageTriggeredAbility;

	bool BeforeActivate(CAbilityAction* pAction);
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	bool BeforeLoyalty(CAbilityAction* pAction);
	bool BeforeThopter(CAbilityAction* pAction);
	bool BeforeLook(CAbilityAction* pAction);

	int m_nActiveTurn;	// turn in which the +1 ability was activated
};

//____________________________________________________________________________
//
class CKayaOrzhovUsurperCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CKayaOrzhovUsurperCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Riot: "This creature enters with your choice of a +1/+1 counter or haste." The choice is made by the controller of
// the creature just after it enters (there are no "as it enters" replacement choices). The haste is a permanent
// keyword: it goes away when the creature leaves the battlefield (ResetCreatureAttributesToPrinted).
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

//____________________________________________________________________________
//
class CAngelicExaltationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAngelicExaltationCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback,
						   &CWhenAttackedBlocked::SetAttackingAloneEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforePump(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CCaptiveAudienceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCaptiveAudienceCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeChoose(CAbilityAction* pAction);
	void OnModeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ModeSelection;
	mutable BOOL m_bChosen[3];	// modes already chosen
};

//____________________________________________________________________________
//
class CCavalcadeOfCalamityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCavalcadeOfCalamityCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenAttackedBlocked,
						   CWhenAttackedBlocked::PlayerEventCallback,
						   &CWhenAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attacked) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CCindervinesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCindervinesCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSpellCast > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDovinsAcuityCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDovinsAcuityCard);

protected:
	bool BeforeGainDraw(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEtherealAbsolutionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEtherealAbsolutionCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEyesEverywhereCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CEyesEverywhereCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
	bool BeforeExchange(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGuardianProjectCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGuardianProjectCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHighAlertCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHighAlertCard);
};

//____________________________________________________________________________
//
class CIllGottenInheritanceCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CIllGottenInheritanceCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
	bool BeforeSacrifice(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CLawmagesBindingCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CLawmagesBindingCard);

protected:
	CCardFilter m_CardFilter;
};

//____________________________________________________________________________
//
class CMirrorMarchCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMirrorMarchCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCopies(TriggeredAbility::TriggeredActionType* pAction);
};

//____________________________________________________________________________
//
class CRhythmOfTheWildCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRhythmOfTheWildCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;

	mutable CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CSentinelsMarkCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSentinelsMarkCard);

protected:
	bool SetAddendumContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeLifelink(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSimicAscendancyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSimicAscendancyCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCounterMoved > TriggeredAbility;

	bool SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value);
	bool BeforeGrowth(TriggeredAbility::TriggeredActionType* pAction);
	bool SetUpkeepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeWin(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSkyTetherCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSkyTetherCard);
};

//____________________________________________________________________________
//
class CSlimebindCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSlimebindCard);
};

//____________________________________________________________________________
//
class CSmotheringTitheCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSmotheringTitheCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CVerityCircleCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CVerityCircleCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, Orientation fromOrientation, Orientation toOrientation) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWildernessReclamationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CWildernessReclamationCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lockets (as in Guilds of Ravnica)
class CLocketCard : public CInPlaySpellCard
{
protected:
	CLocketCard(CGame* pGame, LPCTSTR strName, UINT nID, LPCTSTR strColor1, LPCTSTR strColor2);
};

class CAzoriusLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CAzoriusLocketCard);
};

class CGruulLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CGruulLocketCard);
};

class COrzhovLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(COrzhovLocketCard);
};

class CRakdosLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CRakdosLocketCard);
};

class CSimicLocketCard : public CLocketCard
{
	DECLARE_CARD_CSTOR(CSimicLocketCard);
};

//____________________________________________________________________________
//
class CGlassOfTheGuildpactCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CGlassOfTheGuildpactCard);
};

//____________________________________________________________________________
//
class CScreamingShieldCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CScreamingShieldCard);

protected:
	bool BeforeEquip(CAbilityAction* pAction);
	counted_ptr<CAbility> CreateMillAbility(CCard* pCard);
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTomeOfTheGuildpactCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTomeOfTheGuildpactCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CAwakenTheErstwhileCard : public CCard
{
	DECLARE_CARD_CSTOR(CAwakenTheErstwhileCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBankruptInBloodCard : public CCard
{
	DECLARE_CARD_CSTOR(CBankruptInBloodCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBiogenicUpgradeCard : public CCard
{
	DECLARE_CARD_CSTOR(CBiogenicUpgradeCard);

protected:
	bool BeforeOne(CAbilityAction* pAction);
	bool BeforeTwo(CAbilityAction* pAction);
	bool BeforeThree(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBringToTrialCard : public CCard
{
	DECLARE_CARD_CSTOR(CBringToTrialCard);
};

//____________________________________________________________________________
//
class CCarnivalCarnageCard : public CCard
{
	DECLARE_CARD_CSTOR(CCarnivalCarnageCard);

protected:
	bool BeforeCarnival(CAbilityAction* pAction);
	bool BeforeCarnage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CClearTheMindCard : public CCard
{
	DECLARE_CARD_CSTOR(CClearTheMindCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CConsecrateConsumeCard : public CCard
{
	DECLARE_CARD_CSTOR(CConsecrateConsumeCard);

protected:
	bool BeforeConsecrate(CAbilityAction* pAction);
	bool BeforeConsume(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CConsignToThePitCard : public CCard
{
	DECLARE_CARD_CSTOR(CConsignToThePitCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCryOfTheCarnariumCard : public CCard
{
	DECLARE_CARD_CSTOR(CCryOfTheCarnariumCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDeadRevelsCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeadRevelsCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CDefaceCard : public CCard
{
	DECLARE_CARD_CSTOR(CDefaceCard);
};

//____________________________________________________________________________
//
class CDrillBitCard : public CCard
{
	DECLARE_CARD_CSTOR(CDrillBitCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);

	CCardFilter m_NonlandFilter;
};

//____________________________________________________________________________
//
class CGatesAblazeCard : public CCard
{
	DECLARE_CARD_CSTOR(CGatesAblazeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGoblinGatheringCard : public CCard
{
	DECLARE_CARD_CSTOR(CGoblinGatheringCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CIncubationIncongruityCard : public CCard
{
	DECLARE_CARD_CSTOR(CIncubationIncongruityCard);

protected:
	bool BeforeIncubation(CAbilityAction* pAction);
	bool BeforeIncongruity(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKayasWrathCard : public CCard
{
	DECLARE_CARD_CSTOR(CKayasWrathCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMassManipulationCard : public CCard
{
	DECLARE_CARD_CSTOR(CMassManipulationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class COpenTheGatesCard : public CCard
{
	DECLARE_CARD_CSTOR(COpenTheGatesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_Filter;
};

//____________________________________________________________________________
//
class CRagefireCard : public CCard
{
	DECLARE_CARD_CSTOR(CRagefireCard);
};

//____________________________________________________________________________
//
class CRepudiateReplicateCard : public CCard
{
	DECLARE_CARD_CSTOR(CRepudiateReplicateCard);

protected:
	bool BeforeReplicate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRevivalRevengeCard : public CCard
{
	DECLARE_CARD_CSTOR(CRevivalRevengeCard);

protected:
	bool BeforeRevenge(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRubbleReadingCard : public CCard
{
	DECLARE_CARD_CSTOR(CRubbleReadingCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSavageSmashCard : public CCard
{
	DECLARE_CARD_CSTOR(CSavageSmashCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CShimmerOfPossibilityCard : public CCard
{
	DECLARE_CARD_CSTOR(CShimmerOfPossibilityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSkewerTheCriticsCard : public CCard
{
	DECLARE_CARD_CSTOR(CSkewerTheCriticsCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CSwirlingTorrentCard : public CCard
{
	DECLARE_CARD_CSTOR(CSwirlingTorrentCard);

protected:
	bool BeforeTop(CAbilityAction* pAction);
	bool BeforeBounce(CAbilityAction* pAction);
	bool BeforeBoth(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThrashThreatCard : public CCard
{
	DECLARE_CARD_CSTOR(CThrashThreatCard);

protected:
	bool BeforeThrash(CAbilityAction* pAction);
	bool BeforeThreat(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWarrantWardenCard : public CCard
{
	DECLARE_CARD_CSTOR(CWarrantWardenCard);

protected:
	bool BeforeWarrant(CAbilityAction* pAction);
	bool BeforeWarden(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CAppliedBiomancyCard : public CCard
{
	DECLARE_CARD_CSTOR(CAppliedBiomancyCard);

protected:
	bool BeforeBoth(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CArrestersAdmonitionCard : public CCard
{
	DECLARE_CARD_CSTOR(CArrestersAdmonitionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CArrestersZealCard : public CCard
{
	DECLARE_CARD_CSTOR(CArrestersZealCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBedeckBedazzleCard : public CCard
{
	DECLARE_CARD_CSTOR(CBedeckBedazzleCard);

protected:
	bool BeforeBedazzle(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBedevilCard : public CCard
{
	DECLARE_CARD_CSTOR(CBedevilCard);
};

//____________________________________________________________________________
//
class CBladebrandCard : public CCard
{
	DECLARE_CARD_CSTOR(CBladebrandCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBurnBrightCard : public CCard
{
	DECLARE_CARD_CSTOR(CBurnBrightCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CClearTheStageCard : public CCard
{
	DECLARE_CARD_CSTOR(CClearTheStageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCodeOfConstraintCard : public CCard
{
	DECLARE_CARD_CSTOR(CCodeOfConstraintCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCollisionColossusCard : public CCard
{
	DECLARE_CARD_CSTOR(CCollisionColossusCard);
};

//____________________________________________________________________________
//
class CDeposeDeployCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeposeDeployCard);

protected:
	bool BeforeDepose(CAbilityAction* pAction);
	bool BeforeDeploy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDovinsDismissalCard : public CCard
{
	DECLARE_CARD_CSTOR(CDovinsDismissalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CElectrodominanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CElectrodominanceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEmergencyPowersCard : public CCard
{
	DECLARE_CARD_CSTOR(CEmergencyPowersCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_PermanentFilter;
};

//____________________________________________________________________________
//
class CEssenceCaptureCard : public CCard
{
	DECLARE_CARD_CSTOR(CEssenceCaptureCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

//____________________________________________________________________________
//
class CExposeToDaylightCard : public CCard
{
	DECLARE_CARD_CSTOR(CExposeToDaylightCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFinalPaymentCard : public CCard
{
	DECLARE_CARD_CSTOR(CFinalPaymentCard);

protected:
	CCardFilter m_SacrificeFilter;
};

//____________________________________________________________________________
//
class CFlamesOfTheRazeBoarCard : public CCard
{
	DECLARE_CARD_CSTOR(CFlamesOfTheRazeBoarCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGetThePointCard : public CCard
{
	DECLARE_CARD_CSTOR(CGetThePointCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGrotesqueDemiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrotesqueDemiseCard);
};

//____________________________________________________________________________
//
class CGrowthSpiralCard : public CCard
{
	DECLARE_CARD_CSTOR(CGrowthSpiralCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CJusticiarsPortalCard : public CCard
{
	DECLARE_CARD_CSTOR(CJusticiarsPortalCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CMacabreMockeryCard : public CCard
{
	DECLARE_CARD_CSTOR(CMacabreMockeryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPrecognitivePerceptionCard : public CCard
{
	DECLARE_CARD_CSTOR(CPrecognitivePerceptionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPryingEyesCard : public CCard
{
	DECLARE_CARD_CSTOR(CPryingEyesCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CQuenchCard : public CCard
{
	DECLARE_CARD_CSTOR(CQuenchCard);
};

//____________________________________________________________________________
//
class CRallyToBattleCard : public CCard
{
	DECLARE_CARD_CSTOR(CRallyToBattleCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRampageOfTheClansCard : public CCard
{
	DECLARE_CARD_CSTOR(CRampageOfTheClansCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRegenesisCard : public CCard
{
	DECLARE_CARD_CSTOR(CRegenesisCard);
};

//____________________________________________________________________________
//
class CSagittarsVolleyCard : public CCard
{
	DECLARE_CARD_CSTOR(CSagittarsVolleyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CScorchmarkCard : public CCard
{
	DECLARE_CARD_CSTOR(CScorchmarkCard);
};

//____________________________________________________________________________
//
class CSphinxsInsightCard : public CCard
{
	DECLARE_CARD_CSTOR(CSphinxsInsightCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CStonyStrengthCard : public CCard
{
	DECLARE_CARD_CSTOR(CStonyStrengthCard);
};

//____________________________________________________________________________
//
class CStormStrikeCard : public CCard
{
	DECLARE_CARD_CSTOR(CStormStrikeCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSummaryJudgmentCard : public CCard
{
	DECLARE_CARD_CSTOR(CSummaryJudgmentCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThoughtCollapseCard : public CCard
{
	DECLARE_CARD_CSTOR(CThoughtCollapseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTitanicBrawlCard : public CCard
{
	DECLARE_CARD_CSTOR(CTitanicBrawlCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CUnbreakableFormationCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnbreakableFormationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CUndercitysEmbraceCard : public CCard
{
	DECLARE_CARD_CSTOR(CUndercitysEmbraceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Afterlife N: "When this creature dies, create N 1/1 white and black Spirit creature tokens with flying." (member
// CAfterlifeSupport m_Afterlife, initialized with m_Afterlife(this), and m_Afterlife.AddAfterlifeAbility(N))
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
class CAngelOfGraceCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfGraceCard);

protected:
	bool BeforeWorship(CAbilityAction* pAction);
	bool BeforeLife(CAbilityAction* pAction);

	CCardFilter m_SelfFilter;
};

//____________________________________________________________________________
//
class CArchwayAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArchwayAngelCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCivicStalwartCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCivicStalwartCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CConcordiaPegasusCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CConcordiaPegasusCard);
};

//____________________________________________________________________________
//
class CEliteArresterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEliteArresterCard);
};

//____________________________________________________________________________
//
class CForbiddingSpiritCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CForbiddingSpiritCard);

public:
	BOOL IsTaxActive() const;

protected:
	bool BeforeTax(CAbilityAction* pAction);

	int m_nEnterTurn;		// turn in which the enter ability resolved
	BOOL m_bEnteredOnOwnTurn;
};

// The attacking creature is taxed while the window of Forbidding Spirit is active
struct ForbiddingSpiritComparer : public CardComparer
{
	ForbiddingSpiritComparer(const CForbiddingSpiritCard* pSpirit) : m_pSpirit(pSpirit) {}

	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && m_pSpirit->IsTaxActive() == TRUE;
	}

	virtual ForbiddingSpiritComparer* Clone() const
	{
		return new ForbiddingSpiritComparer(m_pSpirit);
	}

protected:
	const CForbiddingSpiritCard* m_pSpirit;
};

//____________________________________________________________________________
//
class CHaazdaOfficerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHaazdaOfficerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHeroOfPrecinctOneCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHeroOfPrecinctOneCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CImpassionedOratorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImpassionedOratorCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKnightOfSorrowsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfSorrowsCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CLumberingBattlementCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLumberingBattlementCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	void OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool BeforeReturn(CAbilityAction* pAction);

	CSelectionSupport m_CreatureSelection;
	CCountedCardContainer_ m_Exiled;
};

//____________________________________________________________________________
//
class CMinistrantOfObligationCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMinistrantOfObligationCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CProwlingCaracalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CProwlingCaracalCard);
};

//____________________________________________________________________________
//
class CResoluteWatchdogCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CResoluteWatchdogCard);

protected:
	bool BeforeIndestructible(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpiritOfTheSpiresCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSpiritOfTheSpiresCard);
};

//____________________________________________________________________________
//
class CSyndicateMessengerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSyndicateMessengerCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CTenthDistrictVeteranCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTenthDistrictVeteranCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTitheTakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTitheTakerCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CTwilightPantherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTwilightPantherCard);

protected:
	bool BeforeDeathtouch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWatchfulGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWatchfulGiantCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Adapt N: "{cost}: If this creature has no +1/+1 counters on it, put N +1/+1 counters on it." (member CAdaptSupport
// m_Adapt, initialized with m_Adapt(this), and m_Adapt.AddAdaptAbility(cost, N); the condition is checked on
// resolution, so the ability can always be activated)
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

//____________________________________________________________________________
//
class CAxebaneBeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAxebaneBeastCard);
};

//____________________________________________________________________________
//
class CBiogenicOozeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBiogenicOozeCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
	bool BeforeCounters(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEndRazeForerunnersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEndRazeForerunnersCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CEnragedCeratokCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEnragedCeratokCard);

protected:
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CGatebreakerRamCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGatebreakerRamCard);
};

//____________________________________________________________________________
//
class CGrowthChamberGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGrowthChamberGuardianCard);

protected:
	bool SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value);
	bool BeforeSearch(CAbilityAction* pAction);

	CAdaptSupport m_Adapt;
	CCardFilter m_NameFilter;
};

//____________________________________________________________________________
//
class CGruulBeastmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGruulBeastmasterCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CIncubationDruidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIncubationDruidCard);

protected:
	BOOL HasPlusCounter(BOOL bIncludeTricks);

	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CMammothSpiderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMammothSpiderCard);
};

//____________________________________________________________________________
//
class CRampagingRendhornCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRampagingRendhornCard);

protected:
	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CSaruliCaretakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSaruliCaretakerCard);

protected:
	CCardFilter m_CreatureFilter;
};

//____________________________________________________________________________
//
class CSauroformHybridCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSauroformHybridCard);

protected:
	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CSilhanaWayfinderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSilhanaWayfinderCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_CreatureOrLandFilter;
};

//____________________________________________________________________________
//
class CSteepleCreeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSteepleCreeperCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSylvanBrushstriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSylvanBrushstriderCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTerritorialBoarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTerritorialBoarCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTrollbredGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrollbredGuardianCard);

protected:
	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CWreckingBeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWreckingBeastCard);

protected:
	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CAmplifireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAmplifireCard);

protected:
	bool BeforeReset(CAbilityAction* pAction);
	bool BeforeReveal(CAbilityAction* pAction);
	void SetBaseDelta(int nPowerDelta, int nToughnessDelta);

	int m_nPowerDelta;		// applied change from the printed power and toughness
	int m_nToughnessDelta;
};

//____________________________________________________________________________
//
class CBurningTreeVandalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBurningTreeVandalCard);

protected:
	bool BeforeRummage(CAbilityAction* pAction);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CClamorShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CClamorShamanCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CDaggerCasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDaggerCasterCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFeralMaakaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFeralMaakaCard);
};

//____________________________________________________________________________
//
class CGhorClanWreckerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhorClanWreckerCard);

protected:
	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CGravelHideGoblinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGravelHideGoblinCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CImmolationShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImmolationShamanCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRixMaadiRevelerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRixMaadiRevelerCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
	bool BeforeMainResolution(CAbilityAction* pAction);
	bool BeforeSpectacleResolution(CAbilityAction* pAction);
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeRummage(CAbilityAction* pAction);

	BOOL m_bSpectacle;			// the last cast paid the spectacle cost
	mutable BOOL m_bCastWithSpectacle;	// remembered when it enters
};

//____________________________________________________________________________
//
class CRubblebeltRecluseCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRubblebeltRecluseCard);
};

//____________________________________________________________________________
//
class CRumblingRuinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRumblingRuinCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSkarrganHellkiteCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkarrganHellkiteCard);

protected:
	BOOL HasPlusCounter(BOOL bIncludeTricks);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CSmeltWardIgnusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSmeltWardIgnusCard);
};

//____________________________________________________________________________
//
class CSpearSpewerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpearSpewerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpikewheelAcrobatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSpikewheelAcrobatCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
class CTinStreetDodgerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTinStreetDodgerCard);

protected:
	bool BeforeEvasion(CAbilityAction* pAction);

	CCardFilter m_DefenderFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CBladeJugglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBladeJugglerCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBloodmistInfiltratorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBloodmistInfiltratorCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
class CCarrionImpCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCarrionImpCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
};

//____________________________________________________________________________
//
class CCatacombCrocodileCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCatacombCrocodileCard);
};

//____________________________________________________________________________
//
class CDebtorsTransportCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDebtorsTransportCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CGutterbonesCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGutterbonesCard);

protected:
	BOOL CanReturn(BOOL bIncludeTricks);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CNoxiousGroodionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNoxiousGroodionCard);
};

//____________________________________________________________________________
//
class COrzhovEnforcerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrzhovEnforcerCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class COrzhovRacketeersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrzhovRacketeersCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDiscard(TriggeredAbility::TriggeredActionType* pAction);

	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CPestilentSpiritCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPestilentSpiritCard);
};

//____________________________________________________________________________
//
class CPlagueWightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPlagueWightCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPriestOfForgottenGodsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPriestOfForgottenGodsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
class CRakdosTrumpeterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRakdosTrumpeterCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpawnOfMayhemCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSpawnOfMayhemCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSpireManglerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSpireManglerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CTheHauntOfHightowerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTheHauntOfHightowerCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CThirstingShadeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThirstingShadeCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CUndercityScavengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUndercityScavengerCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
class CVindictiveVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVindictiveVampireCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CBenthicBiomancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBenthicBiomancerCard);

protected:
	bool SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value);
	bool BeforeLoot(CAbilityAction* pAction);

	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CChillbringerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CChillbringerCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCoralCommandoCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCoralCommandoCard);
};

//____________________________________________________________________________
//
class CFaerieDuelistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFaerieDuelistCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGatewaySneakCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGatewaySneakCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > DamageTriggeredAbility;

	bool BeforeUnblockable(CAbilityAction* pAction);
	bool BeforeDraw(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHumongulusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHumongulusCard);
};

//____________________________________________________________________________
//
class CMesmerizingBenthidCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMesmerizingBenthidCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CPersistentPetitionersCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPersistentPetitionersCard);

protected:
	bool BeforeMillOne(CAbilityAction* pAction);
	bool BeforeMillTwelve(CAbilityAction* pAction);

	CCardFilter m_AdvisorFilter;
};

//____________________________________________________________________________
//
// The cost reductions of Pteramander's adapt ability: one ability for each reduction, castable if there are at least
// that many instant and sorcery cards in your graveyard
#define PTERAMANDER_CONDITION(n)	BOOL HasSpells##n(BOOL bIncludeTricks) { return CountInstantSorcery() >= n; }

class CPteramanderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPteramanderCard);

protected:
	int CountInstantSorcery() const;
	PTERAMANDER_CONDITION(1)
	PTERAMANDER_CONDITION(2)
	PTERAMANDER_CONDITION(3)
	PTERAMANDER_CONDITION(4)
	PTERAMANDER_CONDITION(5)
	PTERAMANDER_CONDITION(6)
	PTERAMANDER_CONDITION(7)

	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CSagesRowSavantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSagesRowSavantCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSenateCourierCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSenateCourierCard);

protected:
	bool BeforeVigilance(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSkatewingSpyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkatewingSpyCard);

protected:
	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CSkitterEelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkitterEelCard);

protected:
	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CSphinxOfForesightCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSphinxOfForesightCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWallOfLostThoughtsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWallOfLostThoughtsCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CWindstormDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWindstormDrakeCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
class CAeromunculusCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAeromunculusCard);

protected:
	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CAzoriusKnightArbiterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAzoriusKnightArbiterCard);
};

//____________________________________________________________________________
//
class CAzoriusSkyguardCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAzoriusSkyguardCard);
};

//____________________________________________________________________________
//
class CBasilicaBellHauntCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBasilicaBellHauntCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CBolracClanCrusherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBolracClanCrusherCard);
};

//____________________________________________________________________________
//
class CChargingWarBoarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChargingWarBoarCard);
};

//____________________________________________________________________________
//
class CClanGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CClanGuildmageCard);

protected:
	bool BeforeCantBlock(CAbilityAction* pAction);
	bool BeforeAnimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CCombineGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCombineGuildmageCard);

protected:
	bool BeforeActivate(CAbilityAction* pAction);
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeMove(CAbilityAction* pAction);

	int m_nCounterTurn;		// turn in which the first ability resolved
};

//____________________________________________________________________________
//
class CCultGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCultGuildmageCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDeputyOfDetentionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeputyOfDetentionCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

//____________________________________________________________________________
//
class CDomrisNodorogCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDomrisNodorogCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CDovinsAutomatonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDovinsAutomatonCard);
};

//____________________________________________________________________________
//
class CFirebladeArtistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFirebladeArtistCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFootlightFiendCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFootlightFiendCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CFrenziedArynxCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrenziedArynxCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CFrilledMysticCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrilledMysticCard);

protected:
	// (as Mystic Snake in Apocalypse)
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
};

//____________________________________________________________________________
//
class CGallopingLizrogCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGallopingLizrogCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

//____________________________________________________________________________
//
// The cost reductions of Gate Colossus (affinity for Gates): one spell for each reduction
#define GATE_COLOSSUS_CONDITION(n)	BOOL HasGates##n(BOOL bIncludeTricks) { return CountGates() >= n; }

class CGateColossusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGateColossusCard);

protected:
	int CountGates() const;
	GATE_COLOSSUS_CONDITION(1)
	GATE_COLOSSUS_CONDITION(2)
	GATE_COLOSSUS_CONDITION(3)
	GATE_COLOSSUS_CONDITION(4)
	GATE_COLOSSUS_CONDITION(5)
	GATE_COLOSSUS_CONDITION(6)
	GATE_COLOSSUS_CONDITION(7)
	GATE_COLOSSUS_CONDITION(8)

	bool SetGateContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeTop(CAbilityAction* pAction);

	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CGraspingThrullCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGraspingThrullCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CGruulSpellbreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGruulSpellbreakerCard);

protected:
	bool BeforeHexproof(CAbilityAction* pAction);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CGyreEngineerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGyreEngineerCard);
};

//____________________________________________________________________________
//
class CHackrobatCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHackrobatCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
	bool BeforeDeathtouch(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CHydroidKrasisCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHydroidKrasisCard);

protected:
	BOOL Never(BOOL bIncludeTricks) { return FALSE; }
	bool BeforeResolution(CAbilityAction* pAction);
	bool BeforeCastTrigger(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;	// Listen to this card's zone changes
	int m_nX;
};

//____________________________________________________________________________
//
class CImperiousOligarchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImperiousOligarchCard);

protected:
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CJudithTheScourgeDivaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJudithTheScourgeDivaCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CKnightOfTheLastBreathCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfTheLastBreathCard);

protected:
	CCardFilter m_SacrificeFilter;
	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
// "Noncreature spells with mana value greater than the number of lands their controller controls" (Lavinia)
struct LaviniaSpellComparer : public CardComparer
{
	virtual bool operator()(const CCard* pCard) const
	{
		if (pCard->GetCardType().IsCreature())
			return false;
		CPlayer* pController = pCard->GetController();
		if (!pController)
			return false;
		int nLands = CCardFilter::GetFilter(_T("lands"))->CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer());
		return (int)pCard->GetConvertedManaCost() > nLands;
	}

	virtual LaviniaSpellComparer* Clone() const
	{
		return new LaviniaSpellComparer();
	}
};

class CLaviniaAzoriusRenegadeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLaviniaAzoriusRenegadeCard);

protected:
	CCardFilter m_SpellFilter;
};

//____________________________________________________________________________
//
class CNikyaOfTheOldWaysCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNikyaOfTheOldWaysCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredSpecialProdManaAbility, CWhenTappedForMana > TriggeredAbility;

	bool SetTriggerContext(CTriggeredSpecialProdManaAbility::TriggerContextType& triggerContext,
		const CManaProductionAbilityAction* pManaAction) const;

	TriggeredAbility* m_pTriggeredAbility;
	CCardFilter m_NoncreatureFilter;
};

//____________________________________________________________________________
//
class CPitilessPontiffCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPitilessPontiffCard);

protected:
	bool BeforeKeywords(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

//____________________________________________________________________________
//
// Creature cards with the mana value Prime Speaker Vannifar is looking for
struct VannifarComparer : public CardComparer
{
	VannifarComparer(const int* pManaValue) : m_pManaValue(pManaValue) {}

	virtual bool operator()(const CCard* pCard) const
	{
		return pCard->GetCardType().IsCreature() && (int)pCard->GetConvertedManaCost() == *m_pManaValue;
	}

	virtual VannifarComparer* Clone() const
	{
		return new VannifarComparer(m_pManaValue);
	}

protected:
	const int* m_pManaValue;
};

class CPrimeSpeakerVannifarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPrimeSpeakerVannifarCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	int m_nManaValue;
	CCardFilter m_OtherCreatureFilter;
	CCardFilter m_SearchFilter;
};

//____________________________________________________________________________
//
class CRafterDemonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRafterDemonCard);

protected:
	BOOL CanSpectacle(BOOL bIncludeTricks);
	bool BeforeMainResolution(CAbilityAction* pAction);
	bool BeforeSpectacleResolution(CAbilityAction* pAction);
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDiscard(CAbilityAction* pAction);

	BOOL m_bSpectacle;
};

//____________________________________________________________________________
//
class CRakdosFirewheelerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRakdosFirewheelerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRakdosRoustaboutCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRakdosRoustaboutCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRakdosTheShowstopperCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRakdosTheShowstopperCard);

protected:
	bool BeforeFlips(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CRavagerWurmCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRavagerWurmCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);

	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
class CRubblebeltRunnerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRubblebeltRunnerCard);

protected:
	CCardFilter m_BlockerFilter;
};

//____________________________________________________________________________
//
class CRubbleSlingerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRubbleSlingerCard);
};

//____________________________________________________________________________
//
class CScuttlegatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScuttlegatorCard);

protected:
	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CSenateGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSenateGriffinCard);

protected:
	bool BeforeScry(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSenateGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSenateGuildmageCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforeLoot(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSeraphOfTheScalesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSeraphOfTheScalesCard);

protected:
	bool BeforeVigilance(CAbilityAction* pAction);
	bool BeforeDeathtouch(CAbilityAction* pAction);

	CAfterlifeSupport m_Afterlife;
};

//____________________________________________________________________________
//
class CSharktocrabCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSharktocrabCard);

protected:
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenCounterMoved > CounterTriggeredAbility;

	bool SetCounterContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pFromCard, LPCTSTR name, int old, int n_value);
	bool BeforeTap(CAbilityAction* pAction);

	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CSphinxOfNewPrahvCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSphinxOfNewPrahvCard);
};

//____________________________________________________________________________
//
class CSphinxOfTheGuildpactCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSphinxOfTheGuildpactCard);

protected:
	CHexproofFromSupport m_HexproofFrom;
};

//____________________________________________________________________________
//
class CSunderShamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunderShamanCard);

protected:
	typedef
		TTriggeredTargetAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
								 CWhenSelfDamageDealt::PlayerEventCallback,
								 &CWhenSelfDamageDealt::SetPlayerEventCallback > DamageTriggeredAbility;

	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
class CSyndicateGuildmageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSyndicateGuildmageCard);
};

//____________________________________________________________________________
//
class CTeysaKarlovCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTeysaKarlovCard);
};

//____________________________________________________________________________
//
class CVizkopaVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVizkopaVampireCard);
};

//____________________________________________________________________________
//
class CZeganaUtopianSpeakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CZeganaUtopianSpeakerCard);

protected:
	bool SetEnterContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);

	CAdaptSupport m_Adapt;
};

//____________________________________________________________________________
//
class CZhurTaaGoblinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CZhurTaaGoblinCard);

protected:
	CRiotSupport m_Riot;
};

//____________________________________________________________________________
//
