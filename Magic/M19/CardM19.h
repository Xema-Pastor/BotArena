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

// Comparers (from CardDominaria.h)

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

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Creatures that transform into a planeswalker (CPlaneswalkerTransformCreatureCard, in the core)

class CNicolBolasTheRavagerCard : public CPlaneswalkerTransformCreatureCard
{
	DECLARE_CARD_CSTOR(CNicolBolasTheRavagerCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
	bool BeforeTransform(CAbilityAction* pAction);
};

class CNicolBolasTheArisenCard : public CTransformedPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CNicolBolasTheArisenCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeExile(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

class CDetectionTowerCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CDetectionTowerCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CAjaniAdversaryOfTyrantsCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniAdversaryOfTyrantsCard);
};

class CAjaniWiseCounselorCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAjaniWiseCounselorCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeCounters(CAbilityAction* pAction);
};

class CLilianaTheNecromancerCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CLilianaTheNecromancerCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
	void OnCreaturesSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

class CLilianaUntouchedByDeathCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CLilianaUntouchedByDeathCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
	bool BeforeShrink(CAbilityAction* pAction);
};

class CSarkhanDragonsoulCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSarkhanDragonsoulCard);

protected:
	bool BeforeDamageAll(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_DragonFilter;
};

class CSarkhanFirebloodCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CSarkhanFirebloodCard);

protected:
	bool BeforeLoot(CAbilityAction* pAction);
};

class CTezzeretArtificeMasterCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTezzeretArtificeMasterCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CTezzeretCruelMachinistCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CTezzeretCruelMachinistCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);
};

class CVivienOfTheArkbowCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVivienOfTheArkbowCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CVivienReidCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVivienReidCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_CreatureOrLandFilter;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

class CAetherTunnelCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CAetherTunnelCard);
};

class CAjanisLastStandCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAjanisLastStandCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CAjanisWelcomeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAjanisWelcomeCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CColossalMajestyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CColossalMajestyCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

class CDwindleCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CDwindleCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const;
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CGiftOfParadiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CGiftOfParadiseCard);

protected:
	counted_ptr<CAbility> CreateEnchantAbility(CCard* pEnchantedCard, CCard* pEnchantCard, ContextValue_& contextValue);
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CHieromancersCageCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CHieromancersCageCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CInfernalScarringCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CInfernalScarringCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

class CKnightsPledgeCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CKnightsPledgeCard);
};

class CLilianasContractCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CLilianasContractCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredLoseGameAbility, CWhenNodeChanged > WinAbility;

	bool BeforeDraw(CAbilityAction* pAction);
	bool SetWinContext(CTriggeredLoseGameAbility::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeWin(WinAbility::TriggeredActionType* pAction);
};

class COpenTheGravesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COpenTheGravesCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CPatientRebuildingCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPatientRebuildingCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CProdigiousGrowthCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CProdigiousGrowthCard);
};

class CPsychicCorrosionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPsychicCorrosionCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CSarkhansUnsealingCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSarkhansUnsealingCard);

protected:
	bool SetSmallContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool SetBigContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeDamageAll(CAbilityAction* pAction);
};

class CTalonsOfWildwoodCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CTalonsOfWildwoodCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

class CAmuletOfSafekeepingCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAmuletOfSafekeepingCard);
};

class CArcaneEncyclopediaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CArcaneEncyclopediaCard);
};

class CDesecratedTombCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDesecratedTombCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CDragonsHoardCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDragonsHoardCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CFountainOfRenewalCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFountainOfRenewalCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CMaraudersAxeCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CMaraudersAxeCard);
};

class CRoguesGlovesCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRoguesGlovesCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSigiledSwordOfValeronCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSigiledSwordOfValeronCard);

protected:
	bool SetAttackContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, AttackSubject attackSubject) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CTezzeretsGatebreakerCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTezzeretsGatebreakerCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
	bool BeforeUnblockable(CAbilityAction* pAction);

	CCardFilter m_BlueOrArtifactFilter;
};

class CTransmogrifyingWandCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTransmogrifyingWandCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

class CAjanisInfluenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CAjanisInfluenceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_WhiteFilter;
};

class CBloodDivinationCard : public CCard
{
	DECLARE_CARD_CSTOR(CBloodDivinationCard);
};

class CCleansingNovaCard : public CCard
{
	DECLARE_CARD_CSTOR(CCleansingNovaCard);

protected:
	bool BeforeCreatures(CAbilityAction* pAction);
	bool BeforeArtifacts(CAbilityAction* pAction);
};

class CDeclareDominanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeclareDominanceCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CFieryFinishCard : public CCard
{
	DECLARE_CARD_CSTOR(CFieryFinishCard);
};

class CFrayingOmnipotenceCard : public CCard
{
	DECLARE_CARD_CSTOR(CFrayingOmnipotenceCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CHeroicReinforcementsCard : public CCard
{
	DECLARE_CARD_CSTOR(CHeroicReinforcementsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CLichsCaressCard : public CCard
{
	DECLARE_CARD_CSTOR(CLichsCaressCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CLilianasSpoilsCard : public CCard
{
	DECLARE_CARD_CSTOR(CLilianasSpoilsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_BlackFilter;
};

class COneWithTheMachineCard : public CCard
{
	DECLARE_CARD_CSTOR(COneWithTheMachineCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSarkhansDragonfireCard : public CCard
{
	DECLARE_CARD_CSTOR(CSarkhansDragonfireCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_RedFilter;
};

class CSovereignsBiteCard : public CCard
{
	DECLARE_CARD_CSTOR(CSovereignsBiteCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CTakeVengeanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CTakeVengeanceCard);
};

class CThudCard : public CCard
{
	DECLARE_CARD_CSTOR(CThudCard);
};

class CViviensInvocationCard : public CCard
{
	DECLARE_CARD_CSTOR(CViviensInvocationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnTargetSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCardFilter m_CreatureFilter;
	CSelectionSupport m_TargetSelection;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

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

class CAbnormalEnduranceCard : public CCard
{
	DECLARE_CARD_CSTOR(CAbnormalEnduranceCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);

	CCard* m_pTarget;	// the creature that gained the ability, until the end of the turn m_nTurn
	int m_nTurn;
};

class CAegisOfTheHeavensCard : public CCard
{
	DECLARE_CARD_CSTOR(CAegisOfTheHeavensCard);
};

class CInfernalReckoningCard : public CCard
{
	DECLARE_CARD_CSTOR(CInfernalReckoningCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CIsolateCard : public CCard
{
	DECLARE_CARD_CSTOR(CIsolateCard);
};

class CNexusOfFateCard : public CCard
{
	DECLARE_CARD_CSTOR(CNexusOfFateCard);

public:
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);
};

class CNightmaresThirstCard : public CCard
{
	DECLARE_CARD_CSTOR(CNightmaresThirstCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

class CRevitalizeCard : public CCard
{
	DECLARE_CARD_CSTOR(CRevitalizeCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CRootSnareCard : public CCard
{
	DECLARE_CARD_CSTOR(CRootSnareCard);
};

class CSpitFlameCard : public CCard
{
	DECLARE_CARD_CSTOR(CSpitFlameCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeReturn(CAbilityAction* pAction);
};

class CStranglingSporesCard : public CCard
{
	DECLARE_CARD_CSTOR(CStranglingSporesCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

class CUncomfortableChillCard : public CCard
{
	DECLARE_CARD_CSTOR(CUncomfortableChillCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

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

class CAethershieldArtificerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAethershieldArtificerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CAngelOfTheDawnCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAngelOfTheDawnCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CCavalryDrillmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCavalryDrillmasterCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CCourtClericCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCourtClericCard);
};

class CDaybreakChaplainCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDaybreakChaplainCard);
};

class CDwarvenPriestCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDwarvenPriestCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CGallantCavalryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGallantCavalryCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CHeraldOfFaithCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CHeraldOfFaithCard);

protected:
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CKnightOfTheTuskCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfTheTuskCard);
};

class CLenaSelflessChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLenaSelflessChampionCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
	bool BeforeIndestructible(CAbilityAction* pAction);
};

class CLeoninVanguardCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLeoninVanguardCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforePump(CAbilityAction* pAction);
};

class CLeoninWarleaderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLeoninWarleaderCard);

protected:
	bool BeforeTokens(CAbilityAction* pAction);
};

class CLoxodonLineBreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLoxodonLineBreakerCard);
};

class CMilitiaBuglerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMilitiaBuglerCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_SmallCreatureFilter;
};

class CNoviceKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNoviceKnightCard);
};

class CRemorsefulClericCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRemorsefulClericCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CResplendentAngelCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CResplendentAngelCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeToken(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CRustwingFalconCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRustwingFalconCard);
};

class CSerrasGuardianCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSerrasGuardianCard);
};

class CShieldMareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CShieldMareCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeGainLife(CAbilityAction* pAction);

	CCardFilter m_BlockerFilter;
};

class CSilverbeakGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSilverbeakGriffinCard);
};

class CStarCrownedStagCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStarCrownedStagCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

class CTrustyPackbeastCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrustyPackbeastCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CValiantKnightCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CValiantKnightCard);

protected:
	bool BeforeDoubleStrike(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

class CAggressiveMammothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAggressiveMammothCard);
};

class CBristlingBoarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBristlingBoarCard);
};

class CDruidOfHornsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDruidOfHornsCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CDryadGreenseekerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDryadGreenseekerCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
};

class CElvishClancallerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElvishClancallerCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);

	CCardFilter m_ClancallerFilter;
};

class CElvishRejuvenatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElvishRejuvenatorCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);
};

class CGhastbarkTwinsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhastbarkTwinsCard);
};

class CGigantosaurusCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGigantosaurusCard);
};

class CGoreclawTerrorOfQalSismaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoreclawTerrorOfQalSismaCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CGreenwoodSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGreenwoodSentinelCard);
};

class CRhoxOracleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRhoxOracleCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSkallaWolfCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkallaWolfCard);

protected:
	bool BeforeLook(CAbilityAction* pAction);

	CCardFilter m_GreenFilter;
};

class CThornLieutenantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThornLieutenantCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeToken(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CUrsineChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUrsineChampionCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CVigilantBalothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVigilantBalothCard);
};

class CVineMareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVineMareCard);

protected:
	CCardFilter m_BlockerFilter;
};

class CViviensJaguarCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CViviensJaguarCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
	BOOL HasVivien(BOOL bIncludeTricks);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

class CCatalystElementalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCatalystElementalCard);
};

class CDemandingDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDemandingDragonCard);

protected:
	bool BeforeChoice(CAbilityAction* pAction);
	void OnChoiceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_ChoiceSelection;
};

class CDismissivePyromancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDismissivePyromancerCard);
};

class CGoblinInstigatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinInstigatorCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CGoblinMotivatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinMotivatorCard);
};

class CGoblinTrashmasterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinTrashmasterCard);

protected:
	CCardFilter m_GoblinFilter;
};

class CHavocDevilsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHavocDevilsCard);
};

class CHostileMinotaurCard : public CHasteCreatureCard
{
	DECLARE_CARD_CSTOR(CHostileMinotaurCard);
};

class CInfernoHellionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CInfernoHellionCard);

protected:
	bool SetCombatContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature) const;
	bool SetEndStepContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeShuffle(CAbilityAction* pAction);

	mutable int m_nCombatTurn;	// the last turn this creature attacked or blocked
};

class CKarganDragonriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKarganDragonriderCard);
};

class CLathlissDragonQueenCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CLathlissDragonQueenCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeToken(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CLightningMareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLightningMareCard);

protected:
	bool BeforePump(CAbilityAction* pAction);

	CCardFilter m_BlockerFilter;
};

class COnakkeOgreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COnakkeOgreCard);
};

class CSarkhansWhelpCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSarkhansWhelpCard);
};

class CSiegebreakerGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSiegebreakerGiantCard);
};

class CSparktongueDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSparktongueDragonCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CViashinoPyromancerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CViashinoPyromancerCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CVolleyVeteranCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVolleyVeteranCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

class CArisenGorgonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CArisenGorgonCard);
};

class CBogstomperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBogstomperCard);
};

class CBoneDragonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CBoneDragonCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);

	CCardFilter m_OtherCardsFilter;
};

class CDemonOfCatastrophesCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDemonOfCatastrophesCard);
};

class CEpicureOfBloodCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEpicureOfBloodCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CFellSpecterCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CFellSpecterCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardDiscarded > DiscardAbility;

	bool BeforeDiscard(CAbilityAction* pAction);
	bool SetDiscardContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CPlayer* pPlayer, CCard* pCard, CPlayer* pByPlayer) const;
	bool BeforeLoseLife(DiscardAbility::TriggeredActionType* pAction);
};

class CGravewakerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CGravewakerCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CGraveyardMarshalCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGraveyardMarshalCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CHiredBladeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHiredBladeCard);
};

class CIsarethTheAwakenerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CIsarethTheAwakenerCard);
};

class CPlagueMareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPlagueMareCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);

	CCardFilter m_BlockerFilter;
};

class CRavenousHarpyCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRavenousHarpyCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

class CSkeletonArcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkeletonArcherCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CStitchersSupplierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStitchersSupplierCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
};

class CTwoHeadedZombieCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTwoHeadedZombieCard);
};

class CVampireNeonateCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireNeonateCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

class CVampireSovereignCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireSovereignCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

class CAvenWindMageCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAvenWindMageCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CAviationPioneerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAviationPioneerCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CDepartedDeckhandCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDepartedDeckhandCard);

protected:
	bool SetTargetedContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard, CPlayer* pPlayer) const;
	bool BeforeSacrifice(CAbilityAction* pAction);
	bool BeforeEvasion(CAbilityAction* pAction);

	CCardFilter m_SpiritFilter;
};

class CExclusionMageCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CExclusionMageCard);

protected:
	bool BeforeBounce(CAbilityAction* pAction);
};

class CFrilledSeaSerpentCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrilledSeaSerpentCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
};

class CGearsmithProdigyCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGearsmithProdigyCard);
};

class CMysticArchaeologistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMysticArchaeologistCard);
};

class CRiddlemasterSphinxCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRiddlemasterSphinxCard);

protected:
	bool BeforeBounce(CAbilityAction* pAction);
};

class CSaiMasterThopteristCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSaiMasterThopteristCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CSalvagerOfSecretsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSalvagerOfSecretsCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CScholarOfStarsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CScholarOfStarsCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSkilledAnimatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkilledAnimatorCard);

protected:
	bool BeforeAnimate(CAbilityAction* pAction);
	bool BeforeRemove(CAbilityAction* pAction);

	std::auto_ptr<CCardIsAlsoAModifier> m_apAnimate;	// the animation, while this creature remains on the battlefield
	CCard* m_pAnimated;
};

class CSupremePhantomCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSupremePhantomCard);
};

class CSurgeMareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSurgeMareCard);

protected:
	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeLoot(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);

	CCardFilter m_BlockerFilter;
};

class CWallOfMistCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWallOfMistCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored and colorless creatures

class CAerialEngineerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAerialEngineerCard);
};

class CArcadesTheStrategistCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CArcadesTheStrategistCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CBrawlBashOgreCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrawlBashOgreCard);

protected:
	bool BeforeSacrifice(CAbilityAction* pAction);

	CCardFilter m_OtherCreatureFilter;
};

class CChromiumTheMutableCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CChromiumTheMutableCard);

protected:
	bool BeforeChange(CAbilityAction* pAction);
};

class CDiamondMareCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDiamondMareCard);

protected:
	bool BeforeChoose(CAbilityAction* pAction);
	void OnColorSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer,
		DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	bool SetCastContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCard* pCard) const;
	bool BeforeGainLife(CAbilityAction* pAction);

	CSelectionSupport m_ColorSelection;
	DWORD m_dwChosenColor;	// the CardType of the chosen color (0 before choosing)
};

class CDraconicDiscipleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDraconicDiscipleCard);
};

class CGearsmithGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGearsmithGuardianCard);
};

class CMeteorGolemCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMeteorGolemCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CPalladiaMorsTheRuinerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPalladiaMorsTheRuinerCard);

protected:
	bool SetCreatureDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const;
	bool SetPlayerDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	void LoseHexproof() const;
};

class CPoisonTipArcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPoisonTipArcherCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CPsychicSymbiontCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CPsychicSymbiontCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
};

class CRegalBloodlordCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRegalBloodlordCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CSatyrEnchanterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSatyrEnchanterCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSkyriderPatrolCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkyriderPatrolCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CSkyscannerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSkyscannerCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSuspiciousBookcaseCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSuspiciousBookcaseCard);
};

class CTezzeretsStriderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTezzeretsStriderCard);
};

class CVaevictisAsmadiTheDireCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVaevictisAsmadiTheDireCard);
};

//____________________________________________________________________________
//
