#pragma once

//____________________________________________________________________________
//
class CORE_EXPORT CTargetChgLifeTCreatureCard : public CCreatureCard
{
protected:
	CTargetChgLifeTCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						  LPCTSTR strCostText, Power nPower, Life nToughness,
						  LPCTSTR strChgLifeCost,
						  CardComparer* pComparer,
						  BOOL bTargetPlayer,
						  Life nLifeDelta,
						  PreventableType preventable);

	virtual ~CTargetChgLifeTCreatureCard() {}

protected:
	CActivatedAbility<CTargetChgLifeSpell>* m_pTargetChgLifeAbility;
};

//____________________________________________________________________________
//
class CORE_EXPORT CPumpCreatureCard : public CCreatureCard
{
protected:
	CPumpCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					  LPCTSTR strCostText, Power nPower, Life nToughness,
					  LPCTSTR strPumpCost,
					  Power nPowerDelta, Life nLifeDelta,
					  CreatureKeyword creatureKeywordToAdd = CreatureKeyword::Null);

	virtual ~CPumpCreatureCard() {}

protected:
	CPumpAbility*	m_pPumpAbility;
};

//____________________________________________________________________________
//
class CORE_EXPORT CRegenerationCreatureCard : public CCreatureCard
{
protected:
	CRegenerationCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
							  LPCTSTR strCostText, Power nPower, Life nToughness,
							  LPCTSTR strRegenerateCost);

	virtual ~CRegenerationCreatureCard() {}

protected:
	CRegenerationAbility* m_pRegenerationAbility;
};

//____________________________________________________________________________
//
class CORE_EXPORT CFirstStrikeCreatureCard : public CCreatureCard
{
protected:
	CFirstStrikeCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
							 LPCTSTR strCostText, Power nPower, Life nToughness);

	virtual ~CFirstStrikeCreatureCard() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CFlyingCreatureCard : public CCreatureCard
{
protected:
	CFlyingCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						LPCTSTR strCostText, Power nPower, Life nToughness);

	virtual ~CFlyingCreatureCard() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CHasteCreatureCard : public CCreatureCard
{
protected:
	CHasteCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					   LPCTSTR strCostText, Power nPower, Life nToughness);

	virtual ~CHasteCreatureCard() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CLandwalkCreatureCard : public CCreatureCard
{
protected:
	CLandwalkCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						  LPCTSTR strCostText, Power nPower, Life nToughness,
						  CreatureKeyword landwalk);

	virtual ~CLandwalkCreatureCard() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CUnblockableCreatureCard : public CCreatureCard
{
protected:
	CUnblockableCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
							 LPCTSTR strCostText, Power nPower, Life nToughness);

	virtual ~CUnblockableCreatureCard() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CManaProductionTCreatureCard : public CCreatureCard
{
protected:
	CManaProductionTCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						   LPCTSTR strCostText, Power nPower, Life nToughness,
						   LPCTSTR strPoolText);

	virtual ~CManaProductionTCreatureCard() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CFearCreatureCard : public CCreatureCard
{
protected:
	CFearCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					  LPCTSTR strCostText, Power nPower, Life nToughness,
					  const CCardFilter* pUnblockableCreatures = CCardFilter::GetFilter(_T("artifact creatures or black creatures")));

	virtual ~CFearCreatureCard() {}
};
//____________________________________________________________________________
//
class CORE_EXPORT CDevourCreatureCard : public CCreatureCard
{
protected:
	CDevourCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						LPCTSTR strCostText, Power nPower, Life nToughness,
						const CCardFilter* pDevourFilter = CCardFilter::GetFilter(_T("creatures")));

	virtual ~CDevourCreatureCard() {}

public:
	void SetDevouredCount(int nDevouredCount);
	int GetDevouredCount() const;
	int				nDevouredGoblins;	//for VoraciousDragon

protected:
	int				m_nDevouredCount;
};
//____________________________________________________________________________
//
// Ingest (Whenever this creature deals combat damage to a player, that player exiles the top card of his or her library.)
class CORE_EXPORT CIngestCreatureCard : public CCreatureCard
{
protected:
	CIngestCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						LPCTSTR strCostText, Power nPower, Life nToughness);

	virtual ~CIngestCreatureCard() {}

private:
	bool SetIngestContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext,
						  CPlayer* pPlayer, Damage damage) const;
};
//____________________________________________________________________________
//
// Rally - Whenever this creature or another Ally enters the battlefield under your control,
// creatures you control gain <keyword> until end of turn.
class CORE_EXPORT CRallyCreatureCard : public CCreatureCard
{
protected:
	CRallyCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					   LPCTSTR strCostText, Power nPower, Life nToughness,
					   CreatureKeyword::Enum rallyKeyword);

	virtual ~CRallyCreatureCard() {}
};
//____________________________________________________________________________
//
// When this creature enters the battlefield, create N 1/1 colorless Eldrazi Scion creature tokens
// with "Sacrifice this creature: Add {C}."
class CORE_EXPORT CScionMakerCreatureCard : public CCreatureCard
{
protected:
	CScionMakerCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
							LPCTSTR strCostText, Power nPower, Life nToughness,
							int nTokenCount);

	virtual ~CScionMakerCreatureCard() {}
};
//____________________________________________________________________________
//
// Processors: "Put a card an opponent owns from exile into that player's graveyard."
// A card keeps one CProcessCost member per processing cost it has (e.g. "put two cards ... into their owners' graveyards").
// - As a cost or condition: check CanPay(), e.g. from a CPlayableIfTrait or a trigger context function.
// - To pay it: call Pay() when the ability resolves. The player chooses the cards (only if there is a choice);
//   Pay() returns FALSE if there are not enough cards, so the ability or spell does nothing.
class CORE_EXPORT CProcessCost
{
public:
	CProcessCost(CCard* pCard, int nCount = 1);
	virtual ~CProcessCost() {}

	// Number of cards in exile owned by pPlayer's opponents
	static int CountProcessableCards(const CPlayer* pPlayer);

	BOOL CanPay(const CPlayer* pPlayer) const;
	BOOL Pay(CPlayer* pPlayer);

protected:
	void ProcessCard(CCard* pCard, CPlayer* pPlayer);
	void OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5);

	CCard* m_pCard;
	int m_nCount;
	CSelectionSupport m_CardSelection;
};
//____________________________________________________________________________
//
class CORE_EXPORT CChancellorCreatureCard : public CCreatureCard
{
protected:
	CChancellorCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
						LPCTSTR strCostText, Power nPower, Life nToughness);

	virtual ~CChancellorCreatureCard() {}

public:
	BOOL_ bIsRevealed;
	void RevealAtBeginning();

protected:
	int EffectUID;
	CString EffectName;
};

//____________________________________________________________________________
//
class CTokenCreature : public CCreatureCard
{
protected:
	CTokenCreature(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
				   LPCTSTR strCostText, Power nPower, Life nToughness)
		: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, bCounterWatching(FALSE)
	, bVariable(FALSE)
	, IsCopied(0)
	{
	}

	virtual ~CTokenCreature() {}

public:
	void SetUID(UINT pInt) {m_uID=pInt;}
	UINT GetUID() {return m_uID;}
	void SetTokenFullName(LPCTSTR pName) {m_strCardName = pName;}
	LPCTSTR GetTokenFullName() {return m_strCardName;}

	bool IsCounterWatching() {return bCounterWatching == TRUE;}
	bool IsVariable() {return bVariable == TRUE;}

	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);
	// values for special tokens
	int_ IsCopied;
	CCard* pPreviousCard;
	CCard* pOriginatingCard;

	SingleCreatureType pCreatureType;
	void SetPrintedCardName(LPCTSTR PrintedCardName) { m_strPrintedCardName = PrintedCardName; };
	CString strVariableName;

protected:
	UINT	m_uID;
	LPCTSTR m_strCardName;

	BOOL bCounterWatching;
	BOOL bVariable;
};

//____________________________________________________________________________
//
class CCounterWatchingTokenCreature : public CTokenCreature
{
protected:
	CCounterWatchingTokenCreature(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
				   LPCTSTR strCostText, Power nPower, Life nToughness)
		: CTokenCreature(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	{
		bCounterWatching = TRUE;
	}

	virtual ~CCounterWatchingTokenCreature() {}
};

//____________________________________________________________________________
//
class CVariableTokenCreature : public CTokenCreature
{
protected:
	CVariableTokenCreature(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
				   LPCTSTR strCostText, Power nPower, Life nToughness)
		: CTokenCreature(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	{
		bVariable = TRUE;
	}

	virtual ~CVariableTokenCreature() {}
};

//____________________________________________________________________________
//
class CORE_EXPORT CFlipCreatureCard : public CCreatureCard
{
protected:
	CFlipCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					  LPCTSTR strCostText, Power nPower, Life nToughness,
					  Power nPower2, Life nToughness2, LPCTSTR nFlipCardName);	

public:
	void Flip();
	BOOL CanPlayFlipped(BOOL bIncludeTricks);
	BOOL CanPlayUnflipped(BOOL bIncludeTricks);

	void AddCardModifier(CCardModifier* pModifier) { m_CardModifiers.Add(pModifier); }
	void AddCreatureModifier(CCreatureModifier* pModifier) { m_CreatureModifiers.Add(pModifier); }

	CCreatureModifiers	GetCreatureModifiers()  {return m_CreatureModifiers;}
	CCardModifiers		GetCardModifiers()  {return m_CardModifiers;}

	OVERRIDE (CString, GetCardName)(BOOL bIncludeDetails = TRUE) const;
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	LPCTSTR m_strFlipCardName;
	Power m_nPowerDelta;
	Life m_nLifeDelta;
	bool b_AddLegendary; //TODO Move to card code

	CCreatureModifiers	m_CreatureModifiers;
	CCardModifiers		m_CardModifiers;

private:
	OVERRIDE (CString, GetPrintedCardName)() const;
	OVERRIDE (CString, GetSecondPrintedCardName)() const;
};

//____________________________________________________________________________
//
class CORE_EXPORT CDoubleFacedCreatureCard : public CCreatureCard
{
protected:
	CDoubleFacedCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					  LPCTSTR strCostText, Power nPower, Life nToughness,
					  Power nPower2, Life nToughness2, LPCTSTR nFlipCardName);	

public:
	void Transform();
	BOOL CanPlaySecondFace(BOOL bIncludeTricks) const;
	BOOL CanPlayFirstFace(BOOL bIncludeTricks) const;

	void AddCardModifier(CCardModifier* pModifier) { m_CardModifiers.Add(pModifier); }
	void AddCreatureModifier(CCreatureModifier* pModifier) { m_CreatureModifiers.Add(pModifier); }

	CCreatureModifiers	GetCreatureModifiers()  {return m_CreatureModifiers;}
	CCardModifiers		GetCardModifiers()  {return m_CardModifiers;}

	OVERRIDE (DWORD, GetConvertedManaCost)() const;
	OVERRIDE (DWORD, GetManaCost)(CManaCostBase::Color manaCost, BOOL bMax = TRUE);
	OVERRIDE (CString, GetCardName)(BOOL bIncludeDetails = TRUE) const;
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	LPCTSTR m_strDFCardName;
	Power m_nPowerDelta;
	Life m_nLifeDelta;

	CCreatureModifiers	m_CreatureModifiers;
	CCardModifiers		m_CardModifiers;

private:
	friend CFaceTransformModifier;
	friend CGraveyardFaceTransformModifier;
	void FirstFace();
	void SecondFace();

	OVERRIDE (CString, GetPrintedCardName)() const;
	OVERRIDE (CString, GetSecondPrintedCardName)() const;
};

//____________________________________________________________________________
//
class CORE_EXPORT CMorphCreatureCard : public CCreatureCard
{
protected:
	CMorphCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					  LPCTSTR strCostText, Power nPower, Life nToughness, LPCTSTR unMorphstrCardName);	

public:
	void Morph();
	void UnMorph();

	CAbility* GetMorphAbility() {return m_nMorphAbility;}

	BOOL CanPlayMorph(BOOL bIncludeTricks);
	BOOL CanPlayUnMorph(BOOL bIncludeTricks);

	void AddCreatureType(SingleCreatureType pType);
	void AddCardKeyword(CardKeyword pKeyword);
	void AddCreatureKeyword(CreatureKeyword pKeyword);

	void AddCardModifier(CCardModifier* pModifier) { m_CardModifiers.Add(pModifier); }
	void AddCreatureModifier(CCreatureModifier* pModifier) { m_CreatureModifiers.Add(pModifier); }

	CCreatureModifiers	GetCreatureModifiers()  {return m_CreatureModifiers;}
	CCardModifiers		GetCardModifiers()		{return m_CardModifiers;}

	int GetMorphNumber() const {return m_number;}

	OVERRIDE (DWORD, GetConvertedManaCost)() const;
	OVERRIDE (DWORD, GetManaCost)(CManaCostBase::Color manaCost, BOOL bMax = TRUE);
	OVERRIDE (CString, GetCardName)(BOOL bIncludeDetails = TRUE) const;
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	LPCTSTR m_strMorphCardName;
	Power m_nPowerDelta;
	Life m_nLifeDelta;

	CCreatureModifiers	m_CreatureModifiers;
	CCardModifiers		m_CardModifiers;

	void RevertMorph();

private:
	int_ p_type;
	int_ m_number;

	OVERRIDE (CString, GetSecondCardName)(BOOL bIncludeDetails = TRUE) const;
	OVERRIDE (CString, GetPrintedCardName)() const;
	OVERRIDE (CString, GetSecondPrintedCardName)() const;

	CAbility* m_nMorphAbility;
};

//____________________________________________________________________________
//