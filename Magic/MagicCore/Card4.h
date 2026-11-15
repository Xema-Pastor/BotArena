#pragma once

//____________________________________________________________________________
//
class CORE_EXPORT CPlaneswalkerCard : public CInPlaySpellCard
{
	friend class CPlaneswalkerTrait;

protected:
	CPlaneswalkerCard(CGame* pGame, LPCTSTR strCardName, UINT uID,
					  LPCTSTR strCostText, 
					  const PlaneswalkerType& subtype, int nLoyaltyCounter,
					  CardType cardType = CardType::Planeswalker, 
					  AbilityType abilityType = AbilityType::Creature);
	virtual ~CPlaneswalkerCard();

public:
	const PlaneswalkerType& GetSubtype() const;

	Counter* GetLoyaltyCounter();
	const Counter* GetLoyaltyCounter() const;
	BOOL GetTurnAbilityUsed() const {return m_bTurnAbilityUsed;}

	OVERRIDE(void, AddAbility)(CAbility* pAbility);

	OVERRIDE(int, GetScore)() const;

	OVERRIDE(void, Move)(CZone* pToZone,
					     const CPlayer* pByPlayer,	// Card moved by this player (NULL if not applicable)
						 MoveType moveType,
						 CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

	OVERRIDE(void, ResetTurnPropertiesNoFlag)();
	OVERRIDE(void, ResetTurnProperties)();

protected:
	BOOL CanPlay(BOOL bIncludeTricks);

	PlaneswalkerType		m_Subtype;
	Counter*				m_pLoyaltyCounter;
	int						m_nLoyaltyCounter;
	BOOL_					m_bTurnAbilityUsed;
};

//____________________________________________________________________________
//
class CORE_EXPORT CDoubleFacedPlaneswalkerCard : public CPlaneswalkerCard
{
protected:
	CDoubleFacedPlaneswalkerCard(CGame* pGame, LPCTSTR strCardName, UINT uID, LPCTSTR strCostText, const PlaneswalkerType& subtype, int nLoyaltyCounter,
								LPCTSTR nFlipCardName);	

public:
	void Transform();
	BOOL CanPlaySecondFace(BOOL bIncludeTricks) const;
	BOOL CanPlayFirstFace(BOOL bIncludeTricks) const;

	void AddCardModifier(CCardModifier* pModifier) { m_CardModifiers.Add(pModifier); }

	CCardModifiers		GetCardModifiers()  {return m_CardModifiers;}

	OVERRIDE (DWORD, GetConvertedManaCost)() const;
	OVERRIDE (DWORD, GetManaCost)(CManaCostBase::Color manaCost, BOOL bMax = TRUE);
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	LPCTSTR m_strFlipCardName;

	CCardModifiers m_CardModifiers;

private:
	friend CFaceTransformModifier;
	friend CGraveyardFaceTransformModifier;
	void FirstFace();
	void SecondFace();

	int_ p_type;

	OVERRIDE (CString, GetCardName)(BOOL bIncludeDetails = TRUE) const;
	OVERRIDE (CString, GetPrintedCardName)() const;
	OVERRIDE (CString, GetSecondPrintedCardName)() const;
};

//____________________________________________________________________________
//
// Creatures that transform into a planeswalker (Magic Origins, Core Set 2019: "Exile <this>, then return it to the
// battlefield transformed under its owner's control"). A creature card can't become a CPlaneswalkerCard, so the
// planeswalker face is another object, linked to the exiled creature card (as Meld): the card of the back face
// (a CTransformedPlaneswalkerCard, with its own .rc entry, right after the front face's one) is created when the
// creature transforms. While the planeswalker is on the battlefield the creature card waits in exile; when the
// planeswalker leaves the battlefield, the creature card goes to that zone instead and the planeswalker object is
// put away in the _Tokens zone. Outside the battlefield the card is always the front face, as the rules say.
class CTransformedPlaneswalkerCard;

class CORE_EXPORT CPlaneswalkerTransformCreatureCard : public CCreatureCard
{
protected:
	CPlaneswalkerTransformCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType,
									   UINT uID, LPCTSTR strCostText, Power nPower, Life nToughness, LPCTSTR strBackName);

public:
	// Exiles this creature and returns it to the battlefield transformed under its owner's control. Returns the
	// planeswalker, or NULL if the creature wasn't on the battlefield or couldn't be exiled.
	CTransformedPlaneswalkerCard* ExileAndReturnTransformed(const CPlayer* pByPlayer);

	LPCTSTR GetBackName() const { return m_strBackName; }

protected:
	LPCTSTR m_strBackName;
};

class CORE_EXPORT CTransformedPlaneswalkerCard : public CPlaneswalkerCard
{
protected:
	CTransformedPlaneswalkerCard(CGame* pGame, LPCTSTR strCardName, UINT uID, const PlaneswalkerType& subtype, int nLoyaltyCounter,
								 CardType colors);

public:
	void SetFrontFace(CCard* pFrontFace) { m_pFrontFace = pFrontFace; }
	CCard* GetFrontFace() const { return m_pFrontFace; }

	OVERRIDE (DWORD, GetConvertedManaCost)() const;
	OVERRIDE (void, Move)(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement = CardPlacement::Top, BOOL can_dredge = TRUE);

protected:
	BOOL CanCast(BOOL bIncludeTricks) { return FALSE; }	// the back face is never cast (it only exists on the battlefield)

	CCard* m_pFrontFace;	// the creature card in exile, NULL once the planeswalker has left the battlefield
};

//____________________________________________________________________________
//
