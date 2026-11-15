#include "stdafx.h"

#define new DEBUG_NEW

//____________________________________________________________________________
//
CPlaneswalkerCard::CPlaneswalkerCard(CGame* pGame, LPCTSTR strCardName, UINT uID,
					  LPCTSTR strCostText, 
					  const PlaneswalkerType& subtype, int nLoyaltyCounter,
					  CardType cardType, 
					  AbilityType abilityType)
	: CInPlaySpellCard(pGame, strCardName, cardType, uID, strCostText, abilityType)
	, m_Subtype(subtype)
	, m_pLoyaltyCounter(GetCounterContainer()->GetCounter(LOYALTY_COUNTER))
	, m_nLoyaltyCounter(nLoyaltyCounter)
	, m_bTurnAbilityUsed(FALSE)
{
	GetCounterContainer()->ScheduleCounter(LOYALTY_COUNTER, m_nLoyaltyCounter, true, ZoneId::_AllZones, ZoneId::Battlefield, true);

	counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(
				m_pUntapAbility,
				CPlayableIfTrait::PlayableCallback(
				this, &CPlaneswalkerCard::CanPlay)));
				this->GetSpells().GetAt(0)->Add(cpTrait.GetPointer());
}

CPlaneswalkerCard::~CPlaneswalkerCard()
{
}

const PlaneswalkerType& CPlaneswalkerCard::GetSubtype() const
{
	return m_Subtype;
}

Counter* CPlaneswalkerCard::GetLoyaltyCounter()
{
	return m_pLoyaltyCounter;
}

const Counter* CPlaneswalkerCard::GetLoyaltyCounter() const
{
	return m_pLoyaltyCounter;
}

void CPlaneswalkerCard::AddAbility(CAbility* pAbility)
{
	counted_ptr<CPlaneswalkerTrait> cpTrait(::CreateObject<CPlaneswalkerTrait>(pAbility));

	pAbility->Add(cpTrait.GetPointer());	
	pAbility->SetAbilityType((pAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);

	__super::AddAbility(pAbility);
}

int CPlaneswalkerCard::GetScore() const
{
	int nScore = __super::GetScore();

	/*
		For each loyalty counter: +600
	*/

	if (m_pGame && (!m_pGame->IsThinking() ||
		m_pGame->IsCardVisible(this)))
	{
		int nLoyaltyCounter = m_pLoyaltyCounter->GetCount();
		nScore += nLoyaltyCounter * 600;
	}

	return nScore;
}

void CPlaneswalkerCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{

	if (GetIsAlsoA() &&  (moveType == MoveType::Destroy || moveType == MoveType::DestroyWithoutRegeneration))
	{
		if ((GetController()->GetPlayerEffect().HasPlayerEffect(PlayerEffectType::IndestructibleCreatures) || GetController()->GetPlayerEffect().HasPlayerEffect(PlayerEffectType::IndestructiblePermanents) || GetIsAlsoA()->GetCardKeyword()->HasIndestructible()) && GetIsAlsoA()->GetCardType().IsCreature())
		return;
	}

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	// Check for other planeswalker cards
	if (IsInplay())
		m_pGame->AddStatebasedHint(CGame::StatebasedHint::PlaneswalkerCards);	
}

void CPlaneswalkerCard::ResetTurnPropertiesNoFlag()
{
	__super::ResetTurnPropertiesNoFlag();

	m_bTurnAbilityUsed = FALSE;
}

void CPlaneswalkerCard::ResetTurnProperties()
{
	__super::ResetTurnProperties();

	m_bTurnAbilityUsed = FALSE;
}

BOOL CPlaneswalkerCard::CanPlay(BOOL bIncludeTricks)
{
	if (!GetController()->IsComputer()) return true;

	CCardFilter cardfilter(new PlaneswalkerTypeComparer(m_Subtype));
	return cardfilter.CountIncluded(GetController()->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0;
}

//____________________________________________________________________________
//
CDoubleFacedPlaneswalkerCard::CDoubleFacedPlaneswalkerCard(CGame* pGame, LPCTSTR strCardName,  UINT uID,  LPCTSTR strCostText, const PlaneswalkerType& subtype, int nLoyaltyCounter,
										LPCTSTR nFlipCardName)
	: CPlaneswalkerCard(pGame, strCardName, uID, strCostText, subtype, nLoyaltyCounter)
	, m_strFlipCardName(nFlipCardName)
	, p_type(-1)
{
	SetDoubleNamed(TRUE);
}

void CDoubleFacedPlaneswalkerCard::Transform()
{
	GetOrientation()->IsSecondFaced() ? FirstFace() : SecondFace();
}

void CDoubleFacedPlaneswalkerCard::SecondFace()
{
	GetOrientation()->SecondFace();
	m_CardModifiers.ApplyTo(this);

	/*	for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
				pEnchantmentAbility->EndSecondaryEnchantment();

			if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
				pEnchantmentAbility->StartSecondaryEnchantment();
		}*/
}

void CDoubleFacedPlaneswalkerCard::FirstFace()
{
	GetOrientation()->FirstFace();
	m_CardModifiers.RemoveFrom(this);

	/*	for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
				pEnchantmentAbility->StartSecondaryEnchantment();

			if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
				pEnchantmentAbility->EndSecondaryEnchantment();
		}*/
}

CString CDoubleFacedPlaneswalkerCard::GetCardName(BOOL bIncludeDetails) const
{
	if (GetOrientation()->IsSecondFaced()) return this->GetPrintedCardName() + __super::GetCardName(bIncludeDetails).Mid(__super::GetOriginalPrintedCardName().GetLength());
	return __super::GetCardName(bIncludeDetails);
}

void CDoubleFacedPlaneswalkerCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	ZoneId fromZoneId = GetZoneId();
	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	if (fromZoneId == ZoneId::Battlefield && pToZone->GetZoneId() != ZoneId::Battlefield)
			m_CardModifiers.RemoveFrom(this);

	/*if (pFromZone->GetZoneId() != ZoneId::Battlefield&&  pToZone->GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced())
	{
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
				pEnchantmentAbility->EndSecondaryEnchantment();

			if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
				pEnchantmentAbility->StartSecondaryEnchantment();
		}
	}*/

	/*if (pFromZone->GetZoneId() != ZoneId::Battlefield&&  pToZone->GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced())
	{
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
				pEnchantmentAbility->StartSecondaryEnchantment();

			if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
				pEnchantmentAbility->EndSecondaryEnchantment();
		}
	}*/
}

BOOL CDoubleFacedPlaneswalkerCard::CanPlaySecondFace(BOOL bIncludeTricks) const
{
	return (GetOrientation()->IsSecondFaced() && !m_bTurnAbilityUsed);
}

BOOL CDoubleFacedPlaneswalkerCard::CanPlayFirstFace(BOOL bIncludeTricks) const
{
	return (!GetOrientation()->IsSecondFaced() && !m_bTurnAbilityUsed);
}

CString CDoubleFacedPlaneswalkerCard::GetPrintedCardName() const
{
	if (GetOrientation()->IsSecondFaced()) return m_strFlipCardName; 
	return __super::GetPrintedCardName();
}

CString CDoubleFacedPlaneswalkerCard::GetSecondPrintedCardName() const
{
	return m_strFlipCardName; 
}

DWORD CDoubleFacedPlaneswalkerCard::GetConvertedManaCost() const
{
	// Current rules: the mana value of a transforming double-faced permanent with its back face up is calculated
	// from the mana cost of its front face (the back face itself has no mana cost, see GetManaCost)
	return __super::GetConvertedManaCost();
}

DWORD CDoubleFacedPlaneswalkerCard::GetManaCost(CManaCostBase::Color manaCost, BOOL bMax)
{
	if (GetOrientation()->IsSecondFaced())
		return 0;
	return __super::GetManaCost(manaCost, bMax);
}

//____________________________________________________________________________
//
CPlaneswalkerTransformCreatureCard::CPlaneswalkerTransformCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType,
	const CreatureType& creatureType, UINT uID, LPCTSTR strCostText, Power nPower, Life nToughness, LPCTSTR strBackName)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_strBackName(strBackName)
{
}

CTransformedPlaneswalkerCard* CPlaneswalkerTransformCreatureCard::ExileAndReturnTransformed(const CPlayer* pByPlayer)
{
	if (GetZoneId() != ZoneId::Battlefield)
		return NULL;

	CPlayer* pOwner = GetOwner();
	Move(pOwner->GetZoneById(ZoneId::Exile), pByPlayer, MoveType::Others);
	if (GetZoneId() != ZoneId::Exile)
		return NULL;

	// The back face's entry follows the front face's one in the .rc
	counted_ptr<CCard> cpBack(CCardFactory::GetInstance()->CreateCard(m_pGame, m_strBackName, GetImageID() + 1));
	CTransformedPlaneswalkerCard* pBack = dynamic_cast<CTransformedPlaneswalkerCard*>(cpBack.GetPointer());
	if (!pBack)
		return NULL;

	pBack->SetFrontFace(this);
	pOwner->GetZoneById(ZoneId::_Tokens)->AddCard(pBack);
	pBack->Move(pOwner->GetZoneById(ZoneId::Battlefield), pOwner, MoveType::Others);
	return pBack;
}

//____________________________________________________________________________
//
CTransformedPlaneswalkerCard::CTransformedPlaneswalkerCard(CGame* pGame, LPCTSTR strCardName, UINT uID, const PlaneswalkerType& subtype,
	int nLoyaltyCounter, CardType colors)
	: CPlaneswalkerCard(pGame, strCardName, uID, _T(""), subtype, nLoyaltyCounter, CardType::Planeswalker | CardType::Legendary)
	, m_pFrontFace(NULL)
{
	// The color indicator of the back face
	AddCardType(colors, CardType::_ColorMask);

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(
			m_pUntapAbility,
			CPlayableIfTrait::PlayableCallback(this, &CTransformedPlaneswalkerCard::CanCast)));
	GetSpells().GetAt(0)->Add(cpTrait.GetPointer());
}

// The mana value of a transformed permanent is that of its front face (rule 712.8e)
DWORD CTransformedPlaneswalkerCard::GetConvertedManaCost() const
{
	return m_pFrontFace ? m_pFrontFace->GetConvertedManaCost() : 0;
}

void CTransformedPlaneswalkerCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	ZoneId toZoneId = pToZone->GetZoneId();

	// Leaving the battlefield to a public or hidden zone: the card that moves is the creature card in exile
	if (m_pFrontFace && GetZoneId() == ZoneId::Battlefield &&
		(toZoneId == ZoneId::Hand || toZoneId == ZoneId::Library || toZoneId == ZoneId::Graveyard || toZoneId == ZoneId::Exile))
	{
		CCard* pFrontFace = m_pFrontFace;
		m_pFrontFace = NULL;

		__super::Move(GetOwner()->GetZoneById(ZoneId::_Tokens), pByPlayer, moveType, cardPlacement, can_dredge);

		if (pFrontFace->GetZoneId() == ZoneId::Exile && toZoneId != ZoneId::Exile)
			pFrontFace->Move(pFrontFace->GetOwner()->GetZoneById(toZoneId), pByPlayer, moveType, cardPlacement, can_dredge);
		return;
	}

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);
}

//____________________________________________________________________________
//
