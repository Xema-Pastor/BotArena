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
// Delirium (Shadows over Innistrad): four or more card types among cards in your graveyard.
// The card types are artifact, creature, enchantment, instant, land, planeswalker, sorcery and tribal.
// For "as long as" effects, use CEnchantment::SetConditionCountCardTypes() (see SetDeliriumCondition()).
CORE_EXPORT int CountCardTypes(const CZone* pZone);
CORE_EXPORT BOOL HasDelirium(const CPlayer* pPlayer);

// Makes the enchantment ability work only while its controller has delirium
CORE_EXPORT void SetDeliriumCondition(CEnchantment* pEnchantment);

// Investigate (Shadows over Innistrad): create a colorless Clue artifact token with
// "{2}, Sacrifice this artifact: Draw a card." (Tokens2 module). For abilities, a CTokenCreationModifier
// with CLUE_TOKEN_NAME and CLUE_TOKEN_ID can also be used as resolution modifier.
#define CLUE_TOKEN_NAME		_T("Clue (A)")
#define CLUE_TOKEN_ID		55085
CORE_EXPORT void Investigate(CGame* pGame, CPlayer* pPlayer, int nCount = 1);

// Meld (Eldritch Moon), see CMeldCreatureCard.
// A nontoken permanent named strCardName that pPlayer both owns and controls, or NULL
CORE_EXPORT CCard* FindMeldPartner(const CPlayer* pPlayer, LPCTSTR strCardName);
// "If you both own and control X and a permanent named Y, exile them, then meld them": exiles both cards
// and, if both are in exile, melds them (one of them must be a CMeldCreatureCard). Returns TRUE if melded.
CORE_EXPORT BOOL ExileAndMeld(CCard* pCard, LPCTSTR strPartnerName, const CPlayer* pPlayer);
//____________________________________________________________________________
//
// Surge (You may cast this spell for its surge cost if you or a teammate has cast another spell this turn.)
// The card adds two spells: the normal one and a copy with the surge cost, then calls SetSpells().
// Note: there are no teams in the game, so only the spells cast by the controller count.
// - WasSurgeCostPaid(): for "if its surge cost was paid". It is set when either spell starts resolving
//   (so it is right for "When this creature enters" triggers) and cleared when the permanent leaves the battlefield.
// - Both spells' resolution started callbacks are used by this class.
class CORE_EXPORT CSurgeSupport
{
public:
	CSurgeSupport(CCard* pCard);
	virtual ~CSurgeSupport() {}

	void SetSpells(CSpell* pNormalSpell, CSpell* pSurgeSpell);

	BOOL WasSurgeCostPaid() const { return m_bSurgeCostPaid; }

protected:
	BOOL CanCastWithSurge(BOOL bIncludeTricks);
	bool OnNormalSpellResolving(CAbilityAction* pAction);
	bool OnSurgeSpellResolving(CAbilityAction* pAction);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);

	CCard* m_pCard;
	BOOL_ m_bSurgeCostPaid;
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
};

//____________________________________________________________________________
//
// Crew N (Kaladesh): "Tap any number of other untapped creatures you control with total power N or greater: This
// Vehicle becomes an artifact creature until end of turn." The vehicle becomes the creature strCreature/uID (an
// IsAlsoA entry with the vehicle's power, toughness and keywords, e.g. in ATokens) until the cleanup step, as
// Tezzeret the Seeker's -5 in Shards of Alara. The cost is CCost::AddCrewCost.
class CORE_EXPORT CCrewSupport
{
public:
	CCrewSupport(CCard* pVehicle);
	virtual ~CCrewSupport() {}

	// Adds the crew ability to the vehicle; returns it (for the abilities that also need a trait, etc.)
	CAbility* AddCrewAbility(int nCrew, LPCTSTR strCreature, UINT uID);

	// The vehicle becomes an artifact creature until end of turn (e.g. "When this Vehicle enters, it becomes an
	// artifact creature until end of turn"). Call AddCrewAbility first: it sets the creature.
	void Animate(CPlayer* pController);

protected:
	bool OnCrewResolving(CAbilityAction* pAction);

	CCard* m_pVehicle;
	CString m_strCreature;
	UINT m_uID;
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

	friend CFaceTransformModifier;
	friend CGraveyardFaceTransformModifier;
	void FirstFace();
	void SecondFace(BOOL bFireTransformTrigger = TRUE);	// melding is not transforming: no transform trigger

private:
	OVERRIDE (CString, GetPrintedCardName)() const;
	OVERRIDE (CString, GetSecondPrintedCardName)() const;
};

//____________________________________________________________________________
//
// Meld (Eldritch Moon): two cards a player both owns and controls are exiled and melded into one permanent,
// represented by both cards. The meld pair has a host card: a double-faced creature whose second face is
// the melded permanent; the other card stays in exile, linked to the host, while they are melded.
// When the melded permanent leaves the battlefield, both cards go to the same zone (the host returns to its
// first face, as any double-faced card). Its mana value is the total of the mana values of both cards.
// The abilities of the melded permanent go in the host class, gated with CanPlaySecondFace (as transform cards).
class CORE_EXPORT CMeldCreatureCard : public CDoubleFacedCreatureCard
{
protected:
	CMeldCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
					  LPCTSTR strCostText, Power nPower, Life nToughness,
					  Power nMeldedPower, Life nMeldedToughness, LPCTSTR strMeldedCardName);

public:
	// Both cards must be in exile: puts the host onto the battlefield as the melded permanent under its owner's control
	void MeldWith(CCard* pPartner);
	CCard* GetMeldedCard() const { return m_pMeldedCard; }

	OVERRIDE (DWORD, GetConvertedManaCost)() const;
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	CCard* m_pMeldedCard;	// the other card of the melded permanent (in exile), NULL if not melded
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