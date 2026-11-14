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

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Lands

class CArchOfOrazcaCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CArchOfOrazcaCard);

protected:
	BOOL HasBlessing(BOOL bIncludeTricks);

	CAscendSupport m_Ascend;
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Planeswalkers

class CAngrathMinotaurPirateCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAngrathMinotaurPirateCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CAngrathTheFlameChainedCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CAngrathTheFlameChainedCard);

protected:
	bool BeforeDiscard(CAbilityAction* pAction);
	bool BeforeSteal(CAbilityAction* pAction);
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CHuatliRadiantChampionCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CHuatliRadiantChampionCard);

protected:
	bool BeforeLoyalty(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CVraskaSchemingGorgonCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVraskaSchemingGorgonCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
	bool BeforeUltimate(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Enchantments

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

class CAquaticIncursionCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CAquaticIncursionCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
	bool BeforeUnblockable(CAbilityAction* pAction);
};

class CBafflingEndCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CBafflingEndCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeToken(CAbilityAction* pAction);
};

class CCuriousObsessionCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CCuriousObsessionCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeSacrifice(CAbilityAction* pAction);
};

class CFormOfTheDinosaurCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CFormOfTheDinosaurCard);

protected:
	bool BeforeLife(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);
};

class CHadanasClimbCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CHadanasClimbCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);
};

class CWingedTempleOfOrazcaCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CWingedTempleOfOrazcaCard);
};

class CInducedAmnesiaCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CInducedAmnesiaCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CKumenasAwakeningCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CKumenasAwakeningCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CLuminousBondsCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CLuminousBondsCard);
};

class CPathOfDiscoveryCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CPathOfDiscoveryCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeExplore(TriggeredAbility::TriggeredActionType* pAction);
};

class CPathOfMettleCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CPathOfMettleCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);
	bool BeforeDrain(CAbilityAction* pAction);
};

class CMetzaliTowerOfTriumphCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CMetzaliTowerOfTriumphCard);
};

class CProfaneProcessionCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CProfaneProcessionCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeChoose(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCountedCardContainer_ m_Exiled;
	CSelectionSupport m_CreatureSelection;
};

class CTombOfTheDuskRoseCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CTombOfTheDuskRoseCard);
};

class CRadiantDestinyCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CRadiantDestinyCard);

protected:
	OVERRIDE(void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType,
		CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);
	void OnTypeSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);
	counted_ptr<CAbility> CreateBonusAbility(CCard* pCard);
	counted_ptr<CAbility> CreateVigilanceAbility(CCard* pCard);

	CSelectionSupport m_TypeSelection;
	SingleCreatureType m_SelectedType;
	CAscendSupport m_Ascend;
};

class CSeaLegsCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSeaLegsCard);
};

class CSeeRedCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSeeRedCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeSacrifice(CAbilityAction* pAction);
};

class CSquiresDevotionCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CSquiresDevotionCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CStormTheVaultCard : public CTransformEnchantmentBase
{
	DECLARE_CARD_CSTOR(CStormTheVaultCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenDamageDealt,
						   CWhenDamageDealt::PlayerEventCallback,
						   &CWhenDamageDealt::SetPlayerEventCallback > DamageTriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CPlayer* pToPlayer, Damage damage) const;
	bool BeforeTreasure(CAbilityAction* pAction);
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeTransform(CAbilityAction* pAction);

	mutable int m_nTreasureTurn;
};

class CVaultOfCatlacanCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CVaultOfCatlacanCard);
};

class CTilonallisCrownCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CTilonallisCrownCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CWaterknotCard : public CChgPwrTghAttrEnchantCard
{
	DECLARE_CARD_CSTOR(CWaterknotCard);

protected:
	bool BeforeTap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Artifacts

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

class CAwakenedAmalgamCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAwakenedAmalgamCard);
};

class CAzorsGatewayCard : public CTransformArtifactBase
{
	DECLARE_CARD_CSTOR(CAzorsGatewayCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
	void OnCardSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CardSelection;
	std::vector<int> m_ManaValues;	// the different mana values of the cards exiled with it
};

class CSanctumOfTheSunCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSanctumOfTheSunCard);
};

class CCaptainsHookCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CCaptainsHookCard);
};

class CGleamingBarrierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGleamingBarrierCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CGoldenGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoldenGuardianCard);

protected:
	bool BeforeFight(CAbilityAction* pAction);
};

class CGoldForgeGarrisonCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CGoldForgeGarrisonCard);
};

class COrazcaRelicCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(COrazcaRelicCard);

protected:
	BOOL HasBlessing(BOOL bIncludeTricks);
	bool BeforeDraw(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CSilentGravestoneCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CSilentGravestoneCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CTheImmortalSunCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CTheImmortalSunCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Sorceries

class CAngrathsFuryCard : public CCard
{
	DECLARE_CARD_CSTOR(CAngrathsFuryCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CArterialFlowCard : public CCard
{
	DECLARE_CARD_CSTOR(CArterialFlowCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CBrasssBountyCard : public CCard
{
	DECLARE_CARD_CSTOR(CBrasssBountyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CCleansingRayCard : public CCard
{
	DECLARE_CARD_CSTOR(CCleansingRayCard);
};

class CCrashingTideCard : public CCard
{
	DECLARE_CARD_CSTOR(CCrashingTideCard);

protected:
	BOOL ControlsMerfolk(BOOL bIncludeTricks);
	bool BeforeDraw(CAbilityAction* pAction);
};

class CDarkInquiryCard : public CCard
{
	DECLARE_CARD_CSTOR(CDarkInquiryCard);

protected:
	CCardFilter m_NonlandFilter;
};

class CEnterTheUnknownCard : public CCard
{
	DECLARE_CARD_CSTOR(CEnterTheUnknownCard);

protected:
	bool BeforeExplore(CAbilityAction* pAction);
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
};

class CFloodOfRecollectionCard : public CCard
{
	DECLARE_CARD_CSTOR(CFloodOfRecollectionCard);
};

class CGoldenDemiseCard : public CCard
{
	DECLARE_CARD_CSTOR(CGoldenDemiseCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CGruesomeFateCard : public CCard
{
	DECLARE_CARD_CSTOR(CGruesomeFateCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CHuntTheWeakCard : public CCard
{
	DECLARE_CARD_CSTOR(CHuntTheWeakCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CImpaleCard : public CCard
{
	DECLARE_CARD_CSTOR(CImpaleCard);
};

class CMastermindsAcquisitionCard : public CCard
{
	DECLARE_CARD_CSTOR(CMastermindsAcquisitionCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CMutinyCard : public CCard
{
	DECLARE_CARD_CSTOR(CMutinyCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPiratesPillageCard : public CCard
{
	DECLARE_CARD_CSTOR(CPiratesPillageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSecretsOfTheGoldenCityCard : public CCard
{
	DECLARE_CARD_CSTOR(CSecretsOfTheGoldenCityCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CSlaughterTheStrongCard : public CCard
{
	DECLARE_CARD_CSTOR(CSlaughterTheStrongCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void ChooseNext();
	void OnCreatureSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_CreatureSelection;
	std::vector<CCard*> m_Kept;		// the creatures the players keep
	int m_nPlayer;					// the player who is choosing
	int m_nPower;					// the power the player can still keep
	CPlayer* m_pCaster;
};

class CSphinxsDecreeCard : public CCard
{
	DECLARE_CARD_CSTOR(CSphinxsDecreeCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CStrengthOfThePackCard : public CCard
{
	DECLARE_CARD_CSTOR(CStrengthOfThePackCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CThunderherdMigrationCard : public CCard
{
	DECLARE_CARD_CSTOR(CThunderherdMigrationCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);

	CCardFilter m_DinosaurFilter;
};

class CVraskasScornCard : public CCard
{
	DECLARE_CARD_CSTOR(CVraskasScornCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Instants

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

class CAdmiralsOrderCard : public CCard
{
	DECLARE_CARD_CSTOR(CAdmiralsOrderCard);

protected:
	BOOL HasRaidCondition(BOOL bIncludeTricks);
};

class CBlazingHopeCard : public CCard
{
	DECLARE_CARD_CSTOR(CBlazingHopeCard);
};

class CBombardCard : public CCard
{
	DECLARE_CARD_CSTOR(CBombardCard);
};

class CBuccaneersBravadoCard : public CCard
{
	DECLARE_CARD_CSTOR(CBuccaneersBravadoCard);

protected:
	bool BeforeFirstStrike(CAbilityAction* pAction);
	bool BeforeDoubleStrike(CAbilityAction* pAction);
};

class CExpelFromOrazcaCard : public CCard
{
	DECLARE_CARD_CSTOR(CExpelFromOrazcaCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
	void OnPlaceSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CSelectionSupport m_PlaceSelection;
};

class CHornswoggleCard : public CCard
{
	DECLARE_CARD_CSTOR(CHornswoggleCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CMomentOfCravingCard : public CCard
{
	DECLARE_CARD_CSTOR(CMomentOfCravingCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CMomentOfTriumphCard : public CCard
{
	DECLARE_CARD_CSTOR(CMomentOfTriumphCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CPrideOfConquerorsCard : public CCard
{
	DECLARE_CARD_CSTOR(CPrideOfConquerorsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CReaverAmbushCard : public CCard
{
	DECLARE_CARD_CSTOR(CReaverAmbushCard);
};

class CRecklessRageCard : public CCard
{
	DECLARE_CARD_CSTOR(CRecklessRageCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CShakeTheFoundationsCard : public CCard
{
	DECLARE_CARD_CSTOR(CShakeTheFoundationsCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

class CVonasHungerCard : public CCard
{
	DECLARE_CARD_CSTOR(CVonasHungerCard);

protected:
	bool BeforeResolution(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// White creatures

class CBishopOfBindingCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBishopOfBindingCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CEverdawnChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEverdawnChampionCard);
};

class CExultantSkymarcherCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CExultantSkymarcherCard);
};

class CFamishedPaladinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFamishedPaladinCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenPlayerLifeChanged > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		const CPlayer* pPlayer, Life nFromLife, Life nToLife) const;
	bool BeforeUntap(CAbilityAction* pAction);
};

class CForerunnerOfTheLegionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CForerunnerOfTheLegionCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
	bool BeforePump(CAbilityAction* pAction);

	CCardFilter m_VampireFilter;
};

class CImperialCeratopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CImperialCeratopsCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CMajesticHeliopterusCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMajesticHeliopterusCard);

protected:
	bool BeforeFlying(CAbilityAction* pAction);
};

class CMartyrOfDuskCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMartyrOfDuskCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CPaladinOfAtonementCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPaladinOfAtonementCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeGainLife(CAbilityAction* pAction);
};

class CSanguineGlorifierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSanguineGlorifierCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CSkymarcherAspirantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSkymarcherAspirantCard);

protected:
	CAscendSupport m_Ascend;
};

class CSnubhornSentryCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSnubhornSentryCard);

protected:
	CAscendSupport m_Ascend;
};

class CSunCrestedPterodonCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSunCrestedPterodonCard);
};

class CSunSentinelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunSentinelCard);
};

class CTrapjawTyrantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrapjawTyrantCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeExile(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);

	CCountedCardContainer_ m_Exiled;
};

class CZetalpaPrimalDawnCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CZetalpaPrimalDawnCard);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Green creatures

class CCacophodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCacophodonCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeUntap(CAbilityAction* pAction);
};

class CCrestedHerdcallerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCrestedHerdcallerCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CDeeprootEliteCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeeprootEliteCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CForerunnerOfTheHeraldsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CForerunnerOfTheHeraldsCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
	bool BeforeCounter(CAbilityAction* pAction);

	CCardFilter m_MerfolkFilter;
};

class CGhaltaPrimalHungerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGhaltaPrimalHungerCard);

protected:
	int TotalPower() const;
	BOOL CanReduceBy(int nReduction) const { int nPower = TotalPower(); return nReduction == 10 ? nPower >= 10 : nPower == nReduction; }
	BOOL CanReduce1(BOOL bIncludeTricks) { return CanReduceBy(1); }
	BOOL CanReduce2(BOOL bIncludeTricks) { return CanReduceBy(2); }
	BOOL CanReduce3(BOOL bIncludeTricks) { return CanReduceBy(3); }
	BOOL CanReduce4(BOOL bIncludeTricks) { return CanReduceBy(4); }
	BOOL CanReduce5(BOOL bIncludeTricks) { return CanReduceBy(5); }
	BOOL CanReduce6(BOOL bIncludeTricks) { return CanReduceBy(6); }
	BOOL CanReduce7(BOOL bIncludeTricks) { return CanReduceBy(7); }
	BOOL CanReduce8(BOOL bIncludeTricks) { return CanReduceBy(8); }
	BOOL CanReduce9(BOOL bIncludeTricks) { return CanReduceBy(9); }
	BOOL CanReduce10(BOOL bIncludeTricks) { return CanReduceBy(10); }
};

class CGiltgroveStalkerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGiltgroveStalkerCard);

protected:
	CCardFilter m_BlockerFilter;
};

class CHardyVeteranCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CHardyVeteranCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CJadeBearerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJadeBearerCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

class CJadecraftArtisanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJadecraftArtisanCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CJadelightRangerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJadelightRangerCard);

protected:
	bool AfterExplore(CAbilityAction* pAction);

	CExploreSupport m_Explore;
};

class CJunglebornPioneerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJunglebornPioneerCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CKnightOfTheStampedeCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfTheStampedeCard);
};

class COrazcaFrillbackCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrazcaFrillbackCard);
};

class COvergrownArmasaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COvergrownArmasaurCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeToken(CAbilityAction* pAction);
};

class CSwiftWardenCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwiftWardenCard);

protected:
	bool BeforeHexproof(CAbilityAction* pAction);
};

class CTendershootDryadCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTendershootDryadCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CThrashingBrontodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CThrashingBrontodonCard);
};

class CWaywardSwordtoothCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWaywardSwordtoothCard);

protected:
	CAscendSupport m_Ascend;
};

class CWorldShaperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWorldShaperCard);

protected:
	bool BeforeMill(CAbilityAction* pAction);
	bool BeforeReturn(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Red creatures

class CBrazenFreebooterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBrazenFreebooterCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CChargingTuskodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChargingTuskodonCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDamage(TriggeredAbility::TriggeredActionType* pAction);
};

class CDaringBuccaneerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDaringBuccaneerCard);

protected:
	CCardFilter m_PirateFilter;
};

class CDireFleetDaredevilCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetDaredevilCard);
};

class CFanaticalFirebrandCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFanaticalFirebrandCard);
};

class CForerunnerOfTheEmpireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CForerunnerOfTheEmpireCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
	bool BeforeDamage(CAbilityAction* pAction);

	CCardFilter m_DinosaurFilter;
};

class CFrilledDeathspitterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFrilledDeathspitterCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

class CGoblinTrailblazerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGoblinTrailblazerCard);
};

class CNeedletoothRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNeedletoothRaptorCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeDamage(CAbilityAction* pAction);
};

class COrazcaRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COrazcaRaptorCard);
};

class CRekindlingPhoenixCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CRekindlingPhoenixCard);

protected:
	bool BeforeToken(CAbilityAction* pAction);
};

class CSilvercladFerocidonsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSilvercladFerocidonsCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeSacrifice(CAbilityAction* pAction);
};

class CStampedingHorncrestCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStampedingHorncrestCard);
};

class CStormFleetSwashbucklerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormFleetSwashbucklerCard);

protected:
	CAscendSupport m_Ascend;
};

class CSunCollaredRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSunCollaredRaptorCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CSwabGoblinCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwabGoblinCard);
};

class CSwaggeringCorsairCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwaggeringCorsairCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Black creatures

class CAngrathsAmbusherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAngrathsAmbusherCard);
};

class CCanalMonitorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCanalMonitorCard);
};

class CChampionOfDuskCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CChampionOfDuskCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CDinosaurHunterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDinosaurHunterCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::CreatureEventCallback,
						   &CWhenSelfDamageDealt::SetCreatureEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CCreatureCard* pCreature, Damage damage) const;
	bool BeforeDestroy(TriggeredAbility::TriggeredActionType* pAction);
};

class CDireFleetPoisonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetPoisonerCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CDuskChargerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDuskChargerCard);

protected:
	CAscendSupport m_Ascend;
};

class CDuskLegionZealotCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDuskLegionZealotCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CFathomFleetBoarderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CFathomFleetBoarderCard);

protected:
	bool BeforeLoseLife(CAbilityAction* pAction);
};

class CForerunnerOfTheCoalitionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CForerunnerOfTheCoalitionCard);

protected:
	bool BeforeSearch(CAbilityAction* pAction);
	bool BeforeDrain(CAbilityAction* pAction);

	CCardFilter m_PirateFilter;
};

class CGraspingScoundrelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGraspingScoundrelCard);
};

class CMausoleumHarpyCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CMausoleumHarpyCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class COathswornVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(COathswornVampireCard);

protected:
	BOOL GainedLifeThisTurn(BOOL bIncludeTricks);
};

class CPitilessPlundererCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CPitilessPlundererCard);

protected:
	bool BeforeTreasure(CAbilityAction* pAction);
};

class CRavenousChupacabraCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRavenousChupacabraCard);

protected:
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CSadisticSkymarcherCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSadisticSkymarcherCard);

protected:
	CCardFilter m_VampireFilter;
};

class CTetzimocPrimalDeathCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTetzimocPrimalDeathCard);

protected:
	BOOL IsYourTurn(BOOL bIncludeTricks);
	bool BeforeDestroy(CAbilityAction* pAction);
};

class CTombRobberCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTombRobberCard);

protected:
	bool BeforeExplore(CAbilityAction* pAction);
};

class CTwilightProphetCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CTwilightProphetCard);

protected:
	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CNode* pToNode) const;
	bool BeforeReveal(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CVampireChampionCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireChampionCard);
};

class CVampireRevenantCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CVampireRevenantCard);
};

class CVoraciousVampireCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVoraciousVampireCard);

protected:
	bool BeforePump(CAbilityAction* pAction);
};

class CVraskasConquistadorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVraskasConquistadorCard);

protected:
	bool BeforeDrain(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Blue creatures

class CDeadeyeRigHaulerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyeRigHaulerCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CKitesailCorsairCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKitesailCorsairCard);
};

class CMistCloakedHeraldCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMistCloakedHeraldCard);
};

class CNezahalPrimalTideCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CNezahalPrimalTideCard);

protected:
	bool BeforeExile(CAbilityAction* pAction);
};

class CRiverDarterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRiverDarterCard);

protected:
	CCardFilter m_BlockerFilter;
};

class CRiverwiseAugurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRiverwiseAugurCard);

protected:
	bool BeforeDraw(CAbilityAction* pAction);
};

class CSeafloorOracleCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSeafloorOracleCard);
};

class CSirenReaverCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSirenReaverCard);

protected:
	BOOL HasRaidCondition(BOOL bIncludeTricks);
};

class CSlipperyScoundrelCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSlipperyScoundrelCard);

protected:
	CAscendSupport m_Ascend;
};

class CSoulOfTheRapidsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSoulOfTheRapidsCard);
};

class CSpireWinderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CSpireWinderCard);

protected:
	CAscendSupport m_Ascend;
};

class CSwornGuardianCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSwornGuardianCard);
};

class CTimestreamNavigatorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTimestreamNavigatorCard);

protected:
	BOOL HasBlessing(BOOL bIncludeTricks);
	bool BeforeExtraTurn(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CWarkiteMarauderCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWarkiteMarauderCard);

protected:
	bool BeforeShrink(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
//____________________________________________________________________________
//
// Multicolored creatures

class CAtzocanSeerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CAtzocanSeerCard);
};

class CAzorTheLawbringerCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAzorTheLawbringerCard);

protected:
	bool BeforeDecree(CAbilityAction* pAction);
};

class CDeadeyeBrawlerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDeadeyeBrawlerCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfDamageDealt,
						   CWhenSelfDamageDealt::PlayerEventCallback,
						   &CWhenSelfDamageDealt::SetPlayerEventCallback > TriggeredAbility;

	bool SetDamageContext(CTriggeredAbility<>::TriggerContextType& triggerContext, CPlayer* pPlayer, Damage damage) const;
	bool BeforeDraw(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CDireFleetNeckbreakerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDireFleetNeckbreakerCard);
};

class CElendaTheDuskRoseCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CElendaTheDuskRoseCard);

protected:
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenCardMoved > TriggeredAbility;

	bool SetTriggerContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType) const;
	bool BeforeCounter(CAbilityAction* pAction);
	bool BeforeTokens(CAbilityAction* pAction);
};

class CJungleCreeperCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CJungleCreeperCard);

protected:
	bool BeforeReturn(CAbilityAction* pAction);
};

class CKumenaTyrantOfOrazcaCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKumenaTyrantOfOrazcaCard);

protected:
	bool BeforeUnblockable(CAbilityAction* pAction);
	bool BeforeCounters(CAbilityAction* pAction);

	CCardFilter m_OtherMerfolkFilter;
	CCardFilter m_MerfolkFilter;
};

class CLegionLieutenantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLegionLieutenantCard);
};

class CMerfolkMistbinderCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMerfolkMistbinderCard);
};

class CRagingRegisaurCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRagingRegisaurCard);

protected:
	bool BeforeDamage(CAbilityAction* pAction);
};

class CRelentlessRaptorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRelentlessRaptorCard);
};

class CResplendentGriffinCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CResplendentGriffinCard);

protected:
	bool BeforeCounter(CAbilityAction* pAction);

	CAscendSupport m_Ascend;
};

class CSiegehornCeratopsCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CSiegehornCeratopsCard);

protected:
	bool SetEnrageContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
		CCard* pFromCard, CCreatureCard* pToCreature, Damage damage) const;
	bool BeforeCounters(CAbilityAction* pAction);
};

class CStormFleetSprinterCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CStormFleetSprinterCard);
};

class CZacamaPrimalCalamityCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CZacamaPrimalCalamityCard);

protected:
	bool BeforeUntap(CAbilityAction* pAction);
};

//____________________________________________________________________________
//
