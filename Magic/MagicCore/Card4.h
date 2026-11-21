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
// Adventure (Throne of Eldraine, rule 715): an adventurer card can be cast normally or as its Adventure (an instant or
// sorcery with its own name, cost and effect). The card has a CAdventureSupport member and:
//   - creates its Adventure spell (any CSpell, with its cost and effect) and calls SetAdventureSpell: the Adventure is
//     cast only from the hand and, if it resolves, the card is exiled instead of going to the graveyard (if it's
//     countered, it goes to the graveyard);
//   - calls AddCastFromExileSpell with the normal mana cost: while the card is exiled after its Adventure, its owner may
//     cast it normally from exile (not as an Adventure). Exiled by any other way, it can't be cast.
// Find(card) says whether a card "has an Adventure" (Edgewall Innkeeper, Lonesome Unicorn...), and IsAdventureSpell
// whether a spell on the stack is an Adventure (its ability name is ADVENTURE_ABILITY_NAME).
// Limitation: while the Adventure is on the stack the card keeps its normal characteristics (types, colors, mana value).
// Important: the resolution callback of the Adventure spell must return true (use CTargetSpell or CGenericSpell, with
// the effect in the callback). A callback that returns false makes the resolution fail (CAbility::Resolve), and the card
// would go to the graveyard instead of exile. With true, CTargetSpell::ResolveImpl fails only if every target is illegal.
#define ADVENTURE_ABILITY_NAME	_T("Adventure")

class CORE_EXPORT CAdventureSupport
{
public:
	CAdventureSupport(CCard* pCard);
	virtual ~CAdventureSupport();

	// The Adventure support of a card (NULL if the card doesn't have an Adventure)
	static CAdventureSupport* Find(const CCard* pCard);
	// Is the ability an Adventure spell?
	static BOOL IsAdventureSpell(const CAbility* pAbility);

	// The card's Adventure spell (strName: the Adventure's name, for the ability text)
	void SetAdventureSpell(CSpell* pSpell, LPCTSTR strName);
	// The spell that casts the card normally from exile after its Adventure; returns it
	CSpell* AddCastFromExileSpell(LPCTSTR strManaCost);

	// Is the card exiled after its Adventure (so it can be cast from exile)?
	BOOL IsOnAdventure() const;
	LPCTSTR GetAdventureName() const { return m_strName; }

protected:
	BOOL CanCastFromExile(BOOL bIncludeTricks);
	void OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType);
	void OnAdventureResolved(const CAbilityAction* pAction, BOOL bResult);

	CCard* m_pCard;
	CString m_strName;
	BOOL_ m_bOnAdventure;
	ListenerPtr<CardMovementEventSource::Listener> m_cpAListener;
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpRListener;
};

//____________________________________________________________________________
//
// Predefined tokens (rule 111.10), in Tokens2. Their artifact or enchantment type is a CardType flag (CardType::Food,
// CardType::Treasure...), with the predefined filters "Foods", "Treasures"... "Sacrifice a Food" refers to any Food
// artifact (a token or a card such as Gingerbrute, Artifact Creature - Food Golem), so the filters use the CardType flag,
// never the name. The Treasure (55102, TREASURE_TOKEN_NAME in the module helpers) and the Clue (CLUE_TOKEN_NAME, Card3.h)
// already existed.
// Not created yet: Incubator (a double-faced token), Junk (play the exiled card this turn) and the Roles (Aura tokens).
#define FOOD_TOKEN_NAME			_T("Food")
#define FOOD_TOKEN_ID			55140
#define GOLD_TOKEN_NAME			_T("Gold")
#define GOLD_TOKEN_ID			55141
#define BLOOD_TOKEN_NAME		_T("Blood")
#define BLOOD_TOKEN_ID			55142
#define POWERSTONE_TOKEN_NAME	_T("Powerstone")
#define POWERSTONE_TOKEN_ID		55143
#define MAP_TOKEN_NAME			_T("Map")
#define MAP_TOKEN_ID			55144
#define LANDER_TOKEN_NAME		_T("Lander")
#define LANDER_TOKEN_ID			55145
#define SHARD_TOKEN_NAME		_T("Shard")
#define SHARD_TOKEN_ID			55146
#define WALKER_TOKEN_NAME		_T("Walker")
#define WALKER_TOKEN_ID			55147

//____________________________________________________________________________
//
