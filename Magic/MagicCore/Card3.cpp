#include "stdafx.h"
#include <map>


#define new DEBUG_NEW

//____________________________________________________________________________
//
CTargetChgLifeTCreatureCard::CTargetChgLifeTCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
											 LPCTSTR strCostText, Power nPower, Life nToughness,
											 LPCTSTR strChgLifeCost,
											 CardComparer* pComparer,
											 BOOL bTargetPlayer,
											 Life nLifeDelta,
											 PreventableType preventable)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	counted_ptr<CActivatedAbility<CTargetChgLifeSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CTargetChgLifeSpell>>(this, strChgLifeCost, pComparer, bTargetPlayer,
			nLifeDelta, preventable));

	m_pTargetChgLifeAbility = cpAbility.GetPointer();
	ATLASSERT(m_pTargetChgLifeAbility);

	m_pTargetChgLifeAbility->SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);

	m_pTargetChgLifeAbility->AddTapCost();

	AddAbility(m_pTargetChgLifeAbility);
}

//____________________________________________________________________________
//
CPumpCreatureCard::CPumpCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness,
									 LPCTSTR strPumpCost,
									 Power nPowerDelta, Life nLifeDelta,
									 CreatureKeyword creatureKeywordToAdd)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	counted_ptr<CPumpAbility> cpAbility1(
		::CreateObject<CPumpAbility>(this, strPumpCost, nPowerDelta, nLifeDelta, creatureKeywordToAdd));
	ATLASSERT(cpAbility1);

	m_pPumpAbility = cpAbility1.GetPointer();

	AddAbility(m_pPumpAbility);
}

//____________________________________________________________________________
//

CRegenerationCreatureCard::CRegenerationCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
													 LPCTSTR strCostText, Power nPower, Life nToughness,
													 LPCTSTR strRegenerateCost)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	counted_ptr<CRegenerationAbility> cpAbility1(
		::CreateObject<CRegenerationAbility>(this, strRegenerateCost));
	ATLASSERT(cpAbility1);

	m_pRegenerationAbility = cpAbility1.GetPointer();

	AddAbility(m_pRegenerationAbility);
}

//____________________________________________________________________________
//
CFirstStrikeCreatureCard::CFirstStrikeCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
												   LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	GetCreatureKeyword()->AddFirstStrike(FALSE);
}

//____________________________________________________________________________
//
CFlyingCreatureCard::CFlyingCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
										 LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	GetCreatureKeyword()->AddFlying(FALSE);
}

//____________________________________________________________________________
//
CHasteCreatureCard::CHasteCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									   LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	GetCreatureKeyword()->AddHaste(FALSE);

//	CAttackAbility* pAbility1 = (CAttackAbility*)GetAbility(_T("Attack"));
//	CTrait* pTrait1 = pAbility1->RemoveTraitById(BOT_CONTROLLER_TRAIT);
//	delete pTrait1;
}

//____________________________________________________________________________
//
CLandwalkCreatureCard::CLandwalkCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
											 LPCTSTR strCostText, Power nPower, Life nToughness,
											 CreatureKeyword landwalk)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	GetCreatureKeyword()->AddLandwalk(landwalk, FALSE);
}

//____________________________________________________________________________
//
CUnblockableCreatureCard::CUnblockableCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
												   LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	GetCreatureKeyword()->AddUnblockable(FALSE);
}

//____________________________________________________________________________
//
CManaProductionTCreatureCard::CManaProductionTCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
											   LPCTSTR strCostText, Power nPower, Life nToughness,
											   LPCTSTR strPoolText)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	counted_ptr<CManaProductionAbility> cpAbility1(
		::CreateObject<CManaProductionAbility>(this, _T("Tap"), AbilityType::Activated, strPoolText));

	cpAbility1->AddTapCost();

	AddAbility(cpAbility1.GetPointer());
}

//____________________________________________________________________________
//
CFearCreatureCard::CFearCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness,
									 const CCardFilter* pUnblockableCreatures)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	GetCreatureKeyword()->AddUnblockable(FALSE, pUnblockableCreatures);
}
//____________________________________________________________________________
//

CDevourCreatureCard::CDevourCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness,
									 const CCardFilter* pDevourFilter)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_nDevouredCount(0)
{
	GetCardKeyword()->AddMovementReplacement(FALSE, ZoneId::_AllZones, ZoneId::Battlefield, MoveType::Others, 1, _T("devour"), (CCardFilter*)pDevourFilter);
}

void CDevourCreatureCard::SetDevouredCount(int nDevouredCount)
{
	m_nDevouredCount = nDevouredCount;
}

int CDevourCreatureCard::GetDevouredCount() const
{
	return m_nDevouredCount;
}

//____________________________________________________________________________
//
CIngestCreatureCard::CIngestCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
										 LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	typedef TTriggeredAbility<CTriggeredMoveCardAbility, CWhenSelfDamageDealt,
		CWhenSelfDamageDealt::PlayerEventCallback,
		&CWhenSelfDamageDealt::SetPlayerEventCallback> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->GetTrigger().SetCombatDamageOnly();
	cpAbility->GetTrigger().SetToOpponentsOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(
		this, &CIngestCreatureCard::SetIngestContext));
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Library, ZoneId::Exile));
	AddAbility(cpAbility.GetPointer());
}

bool CIngestCreatureCard::SetIngestContext(CTriggeredMoveCardAbility::TriggerContextType& triggerContext,
										   CPlayer* pPlayer, Damage damage) const
{
	CZone* pLibrary = pPlayer->GetZoneById(ZoneId::Library);
	if (!pLibrary->GetSize())
		return false;

	triggerContext.m_pCard = pLibrary->GetAt(0);
	return true;
}

//____________________________________________________________________________
//
CRallyCreatureCard::CRallyCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									   LPCTSTR strCostText, Power nPower, Life nToughness,
									   CreatureKeyword::Enum rallyKeyword)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	typedef TTriggeredAbility<CTriggeredModifyCreatureAbility, CWhenCardMoved> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(
		::CreateObject<TriggeredAbility>(this, ZoneId::_AllZones, ZoneId::Battlefield));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetToControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(
		new CreatureTypeComparer(CREATURE_TYPE(Ally), false));
	cpAbility->SetModifyCreatureOption(
		CTriggeredModifyCreatureAbility::ModifyCreatureOption::ModifyTriggeredPlayersCreatures);
	cpAbility->GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetCardFilterHelper().GetCustomFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetToAdd(rallyKeyword);
	cpAbility->GetCreatureKeywordMod().GetModifier().SetOneTurnOnly(TRUE);
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CScionMakerCreatureCard::CScionMakerCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
												 LPCTSTR strCostText, Power nPower, Life nToughness,
												 int nTokenCount)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
{
	typedef TTriggeredAbility<CTriggeredCreateTokenAbility, CWhenSelfInplay,
		CWhenSelfInplay::EventCallback, &CWhenSelfInplay::SetEnterEventCallback> TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetCreateTokenOption(TRUE, _T("Eldrazi Scion (A)"), 55056, nTokenCount);
	cpAbility->AddAbilityTag(AbilityTag::TokenCreation);
	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
//
CProcessCost::CProcessCost(CCard* pCard, int nCount)
	: m_pCard(pCard)
	, m_nCount(nCount)
	, m_CardSelection(pCard->GetGame(), CSelectionSupport::SelectionCallback(this, &CProcessCost::OnCardsSelected))
{
}

int CProcessCost::CountProcessableCards(const CPlayer* pPlayer)
{
	CGame* pGame = pPlayer->GetGame();
	int nCount = 0;

	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CZone* pExile = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Exile);

		for (int i = 0; i < pExile->GetSize(); ++i)
			if (pExile->GetAt(i)->GetOwner() != pPlayer)
				++nCount;
	}

	return nCount;
}

BOOL CProcessCost::CanPay(const CPlayer* pPlayer) const
{
	return CountProcessableCards(pPlayer) >= m_nCount;
}

BOOL CProcessCost::Pay(CPlayer* pPlayer)
{
	if (!CanPay(pPlayer))
		return FALSE;

	CGame* pGame = pPlayer->GetGame();

	std::vector<SelectionEntry> entries;
	for (int ip = 0; ip < pGame->GetPlayerCount(); ++ip)
	{
		CZone* pExile = pGame->GetPlayer(ip)->GetZoneById(ZoneId::Exile);

		for (int i = 0; i < pExile->GetSize(); ++i)
		{
			CCard* pCard = pExile->GetAt(i);
			if (pCard->GetOwner() == pPlayer)
				continue;

			SelectionEntry entry;

			entry.dwContext = (DWORD)pCard;
			entry.cpAssociatedCard = pCard;
			entry.strText.Format(_T("Put %s into %s's graveyard"), pCard->GetCardName(TRUE), pCard->GetOwner()->GetPlayerName());

			entries.push_back(entry);
		}
	}

	if ((int)entries.size() == m_nCount)
	{
		// No choice: process all of them
		for (std::vector<SelectionEntry>::const_iterator it = entries.begin(); it != entries.end(); ++it)
			ProcessCard((CCard*)it->dwContext, pPlayer);
	}
	else
		m_CardSelection.AddSelectionRequest(entries, m_nCount, m_nCount, m_pCard, pPlayer);

	return TRUE;
}

void CProcessCost::ProcessCard(CCard* pCard, CPlayer* pPlayer)
{
	CMoveCardModifier pModifier = CMoveCardModifier(ZoneId::Exile, ZoneId::Graveyard, TRUE, MoveType::Others, pPlayer);
	pModifier.ApplyTo(pCard);
}

void CProcessCost::OnCardsSelected(const std::vector<SelectionEntry>& selection, int nSelectedCount, CPlayer* pSelectionPlayer, DWORD dwContext1, DWORD dwContext2, DWORD dwContext3, DWORD dwContext4, DWORD dwContext5)
{
	for (std::vector<SelectionEntry>::const_iterator it = selection.begin(); it != selection.end(); ++it)
		if (it->bSelected)
			ProcessCard((CCard*)it->dwContext, pSelectionPlayer);
}

//____________________________________________________________________________
//
int CountCardTypes(const CZone* pZone)
{
	const CardType types[] = { CardType::Artifact, CardType::Creature, CardType::_Enchantment, CardType::Instant,
							   CardType::_Land, CardType::Planeswalker, CardType::Sorcery, CardType::Tribal };
	int nCount = 0;

	for (int t = 0; t < _countof(types); ++t)
		for (int i = 0; i < pZone->GetSize(); ++i)
			if ((pZone->GetAt(i)->GetCardType() & types[t]).Any())
			{
				++nCount;
				break;
			}

	return nCount;
}

BOOL HasDelirium(const CPlayer* pPlayer)
{
	return CountCardTypes(pPlayer->GetZoneById(ZoneId::Graveyard)) >= 4;
}

void SetDeliriumCondition(CEnchantment* pEnchantment)
{
	pEnchantment->SetConditionWork();
	pEnchantment->SetConditionCheckZone(ZoneId::Graveyard);
	pEnchantment->SetConditionCountCardTypes();
	pEnchantment->SetConditionValue(4);
}

void Investigate(CGame* pGame, CPlayer* pPlayer, int nCount)
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(pGame, CLUE_TOKEN_NAME, CLUE_TOKEN_ID, nCount);
	pModifier.ApplyTo(pPlayer);
}

CCard* FindMeldPartner(const CPlayer* pPlayer, LPCTSTR strCardName)
{
	const CZone* pBattlefield = pPlayer->GetZoneById(ZoneId::Battlefield);
	for (int i = 0; i < pBattlefield->GetSize(); ++i)
	{
		CCard* pCard = pBattlefield->GetAt(i);
		if (!pCard->GetCardType().IsToken() && pCard->GetOwner() == pPlayer && pCard->GetCardName(FALSE) == strCardName)
			return pCard;
	}
	return NULL;
}

BOOL ExileAndMeld(CCard* pCard, LPCTSTR strPartnerName, const CPlayer* pPlayer)
{
	if (pCard->GetZoneId() != ZoneId::Battlefield || pCard->GetCardType().IsToken() ||
		pCard->GetOwner() != pPlayer || pCard->GetController() != pPlayer)
		return FALSE;

	CCard* pPartner = FindMeldPartner(pPlayer, strPartnerName);
	if (!pPartner)
		return FALSE;

	CMeldCreatureCard* pHost = dynamic_cast<CMeldCreatureCard*>(pCard);
	CCard* pOther = pPartner;
	if (!pHost)
	{
		pHost = dynamic_cast<CMeldCreatureCard*>(pPartner);
		pOther = pCard;
	}
	if (!pHost)
		return FALSE;

	pCard->Move(pCard->GetOwner()->GetZoneById(ZoneId::Exile), pPlayer, MoveType::Others);
	pPartner->Move(pPartner->GetOwner()->GetZoneById(ZoneId::Exile), pPlayer, MoveType::Others);

	// Melded only if both cards were exiled
	if (pHost->GetZoneId() != ZoneId::Exile || pOther->GetZoneId() != ZoneId::Exile)
		return FALSE;

	pHost->MeldWith(pOther);
	return TRUE;
}

//____________________________________________________________________________
//
CSurgeSupport::CSurgeSupport(CCard* pCard)
	: m_pCard(pCard)
	, m_bSurgeCostPaid(FALSE)
	, m_cpAListener(VAR_NAME(m_cpAListener), CardMovementEventSource::Listener::EventCallback(this, &CSurgeSupport::OnZoneChanged))
{
	pCard->GetMovedEventSource()->AddListener(m_cpAListener.GetPointer());
}

void CSurgeSupport::SetSpells(CSpell* pNormalSpell, CSpell* pSurgeSpell)
{
	pNormalSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSurgeSupport::OnNormalSpellResolving));
	pSurgeSpell->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CSurgeSupport::OnSurgeSpellResolving));

	counted_ptr<CPlayableIfTrait> cpTrait(
		::CreateObject<CPlayableIfTrait>(pSurgeSpell,
			CPlayableIfTrait::PlayableCallback(this, &CSurgeSupport::CanCastWithSurge)));
	pSurgeSpell->Add(cpTrait.GetPointer());
}

BOOL CSurgeSupport::CanCastWithSurge(BOOL bIncludeTricks)
{
	// "if you have cast another spell this turn" (as Talara's Battalion)
	return m_pCard->GetController()->GetTurnCastedSpellCount() > 0;
}

bool CSurgeSupport::OnNormalSpellResolving(CAbilityAction* pAction)
{
	m_bSurgeCostPaid = FALSE;
	return true;
}

bool CSurgeSupport::OnSurgeSpellResolving(CAbilityAction* pAction)
{
	m_bSurgeCostPaid = TRUE;
	return true;
}

void CSurgeSupport::OnZoneChanged(CCard* pCard, CZone* pFromZone, CZone* pToZone, CPlayer* pByPlayer, MoveType moveType)
{
	if (pCard == m_pCard && pFromZone && pFromZone->GetZoneId() == ZoneId::Battlefield)
		m_bSurgeCostPaid = FALSE;
}

//____________________________________________________________________________
//
// Every Vehicle registers its crew support here (see Find)
static std::map<const CCard*, CCrewSupport*>& GetCrewSupports()
{
	static std::map<const CCard*, CCrewSupport*> crewSupports;
	return crewSupports;
}

CCrewSupport::CCrewSupport(CCard* pVehicle)
	: m_pVehicle(pVehicle)
	, m_uID(0)
{
	GetCrewSupports()[pVehicle] = this;
}

CCrewSupport::~CCrewSupport()
{
	std::map<const CCard*, CCrewSupport*>::iterator it = GetCrewSupports().find(m_pVehicle);
	if (it != GetCrewSupports().end() && it->second == this)
		GetCrewSupports().erase(it);
}

CCrewSupport* CCrewSupport::Find(const CCard* pCard)
{
	std::map<const CCard*, CCrewSupport*>::const_iterator it = GetCrewSupports().find(pCard);
	return it != GetCrewSupports().end() ? it->second : NULL;
}

CAbility* CCrewSupport::AddCrewAbility(int nCrew, LPCTSTR strCreature, UINT uID)
{
	m_strCreature = strCreature;
	m_uID = uID;

	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(m_pVehicle,
			_T("")));

	cpAbility->GetCost().AddCrewCost(m_pVehicle, nCrew);

	CString strText;
	strText.Format(_T("Crew %d (this Vehicle becomes an artifact creature until end of turn). Activates"), nCrew);
	cpAbility->SetAbilityText(strText);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CCrewSupport::OnCrewResolving));
	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	m_pVehicle->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

bool CCrewSupport::OnCrewResolving(CAbilityAction* pAction)
{
	Animate(pAction->GetController());
	return true;
}

void CCrewSupport::Animate(CPlayer* pController)
{
	// Already a creature (e.g. crewed twice): nothing changes
	if (m_pVehicle->GetZoneId() != ZoneId::Battlefield || m_pVehicle->GetCardType().IsCreature())
		return;

	CScheduledCardModifier animationModifier = CScheduledCardModifier(m_pVehicle->GetGame(),
		new CCardIsAlsoAModifier(m_strCreature, m_uID, pController),
		TurnNumberDelta(-1), NodeId::CleanupStep2,
		true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater);
	animationModifier.ApplyTo(m_pVehicle);
}

//____________________________________________________________________________
//
void CAftermathSupport::SetFirstHalf(CSpell* pSpell)
{
	pSpell->SetHandOnly();
}

void CAftermathSupport::SetSecondHalf(CSpell* pSpell, LPCTSTR strName)
{
	pSpell->SetGraveyardOnly();
	pSpell->SetMainSpell(FALSE);
	pSpell->SetAbilityName(AFTERMATH_ABILITY_NAME);

	CString strText;
	strText.Format(_T("%s (Aftermath). Casts"), strName);
	pSpell->SetAbilityText(strText);
}

//____________________________________________________________________________
//
CEmbalmSupport::CEmbalmSupport(CCard* pCard)
	: m_pCard(pCard)
{
	m_ThisCardFilter.AddComparer(new SpecificCardComparer(pCard));
}

CAbility* CEmbalmSupport::AddEmbalmAbility(LPCTSTR strCost)
{
	return AddAbility(strCost, FALSE);
}

CAbility* CEmbalmSupport::AddEternalizeAbility(LPCTSTR strCost)
{
	return AddAbility(strCost, TRUE);
}

CAbility* CEmbalmSupport::AddAbility(LPCTSTR strCost, BOOL bEternalize)
{
	// "{cost}, Exile this card from your graveyard: ... Activate only as a sorcery." (as Scavenge in Return to Ravnica)
	counted_ptr<CActivatedAbility<CGenericSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CGenericSpell>>(m_pCard, strCost));

	cpAbility->SetGraveyardOnly();
	cpAbility->GetCost().AddExileGraveyardCardCost(1, &m_ThisCardFilter);
	cpAbility->SetAbilityType((cpAbility->GetAbilityType() & ~AbilityType::Activated) | AbilityType::AsSorcery);

	if (bEternalize)
	{
		cpAbility->SetAbilityText(_T("Eternalize (create a 4/4 black Zombie token copy of this card). Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmbalmSupport::OnEternalizeResolving));
	}
	else
	{
		cpAbility->SetAbilityText(_T("Embalm (create a white Zombie token copy of this card). Activates"));
		cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CEmbalmSupport::OnEmbalmResolving));
	}

	m_pCard->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

bool CEmbalmSupport::OnEmbalmResolving(CAbilityAction* pAction)
{
	CreateZombieCopy(m_pCard, pAction->GetController(), FALSE);
	return true;
}

bool CEmbalmSupport::OnEternalizeResolving(CAbilityAction* pAction)
{
	CreateZombieCopy(m_pCard, pAction->GetController(), TRUE);
	return true;
}

void CEmbalmSupport::CreateZombieCopy(CCard* pCard, CPlayer* pController, BOOL bEternalize)
{
	CGame* pGame = pCard->GetGame();

	// Doubling Season, Primal Vigor... (as CCardCopyModifier)
	int nTokens = 1;
	int nMultiplier = 0;
	if (pController->GetPlayerEffect().HasPlayerEffectSum(PlayerEffectType::DoubleTokens, nMultiplier, FALSE))
		nTokens <<= nMultiplier;
	if (pController->GetPlayerEffect().HasPlayerEffectSum(PlayerEffectType::DoubleTokensAlways, nMultiplier, FALSE))
		nTokens <<= nMultiplier;

	for (int i = 0; i < nTokens; ++i)
	{
		counted_ptr<CCard> cpToken(CCardFactory::GetInstance()->CreateCard(pGame, pCard->GetOriginalPrintedCardName(), pCard->GetImageID()));
		if (!cpToken.GetPointer())
			return;

		pController->GetZoneById(ZoneId::_Tokens)->AddCard(cpToken.GetPointer());
		cpToken->AddCardType(CardType::Token, CardType::Null, CardTypeEntry::Permanent);
		cpToken->AddCardType(CardType::Copy, CardType::Null, CardTypeEntry::Permanent);

		// The exceptions of the copy are part of its copiable values, so they are set before it enters
		cpToken->AddCardType(bEternalize ? CardType::Black : CardType::White, CardType::_ColorMask, CardTypeEntry::Permanent);

		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(cpToken.GetPointer());
		if (pCreature)
		{
			pCreature->GetCreatureType().AddType(SingleCreatureType::Zombie);
			if (bEternalize)
			{
				pCreature->SetPrintedPower(Power(4));
				pCreature->SetPrintedToughness(Life(4));
			}
		}

		cpToken->Move(pController->GetZoneById(ZoneId::Battlefield), pController, MoveType::Others);
	}
}

//____________________________________________________________________________
//
CExertSupport::CExertSupport(CCard* pCreature)
	: m_pCreature(pCreature)
{
}

CAbility* CExertSupport::AddExertAbility(LPCTSTR strText, CAbility::ResolutionStartedCallback callback)
{
	m_Callback = callback;

	// "You may exert this creature as it attacks. When you do, ..." (as an optional attack trigger)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenSelfAttackedBlocked,
						   CWhenSelfAttackedBlocked::AttackEventCallback,
						   &CWhenSelfAttackedBlocked::SetAttackingEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(m_pCreature));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Optional);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CExertSupport::OnExertResolving));

	CString strAbilityText;
	strAbilityText.Format(_T("Exert: %s"), strText);
	cpAbility->SetAbilityText(strAbilityText);

	m_pCreature->AddAbility(cpAbility.GetPointer());
	return cpAbility.GetPointer();
}

bool CExertSupport::OnExertResolving(CAbilityAction* pAction)
{
	Exert(m_pCreature);

	if (!m_Callback.empty())
		return m_Callback(pAction);
	return true;
}

void CExertSupport::Exert(CCard* pCreature)
{
	if (pCreature->GetZoneId() != ZoneId::Battlefield)
		return;

	// It won't untap during its controller's next untap step (as Aether Revolt's SkipNextUntap)
	CScheduledCardModifier untapModifier = CScheduledCardModifier(pCreature->GetGame(),
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCreature->GetController());
	untapModifier.ApplyTo(pCreature);

	CGame* pGame = pCreature->GetGame();
	if (!pGame->IsThinking())
	{
		CPlayer* pPlayer = pCreature->GetController();
		CString strMessage;
		strMessage.Format(_T("%s exerts %s"), pPlayer->GetPlayerName(), pCreature->GetCardName(TRUE));
		pGame->Message(
			strMessage,
			pPlayer->IsComputer() ? pGame->GetComputerImage() : pGame->GetHumanImage(),
			MessageImportance::High
			);
	}

	// "Whenever you exert a creature"
	CSpecialEffectModifier exertEffect(pCreature, EXERT_TRIGGER_ID);
	exertEffect.ApplyTo(pCreature);
}

//____________________________________________________________________________
//
CChancellorCreatureCard::CChancellorCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
										 LPCTSTR strCostText, Power nPower, Life nToughness)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, bIsRevealed(FALSE)
{
}

void CChancellorCreatureCard::RevealAtBeginning()
{
	CTokenCreationModifier pModifier = CTokenCreationModifier(GetGame(), EffectName, EffectUID, 1, FALSE, ZoneId::_Effects);
	pModifier.ApplyTo(GetController());

	bIsRevealed = TRUE;
}

//____________________________________________________________________________
//
CFlipCreatureCard::CFlipCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness,
									 Power nPower2, Life nToughness2, LPCTSTR nFlipCardName)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_strFlipCardName(nFlipCardName)
{
	m_nPowerDelta = nPower2 - nPower;
	m_nLifeDelta = nToughness2 - nToughness;

	b_AddLegendary = !(GetCardType() & CardType::Legendary).Any();

	SetDoubleNamed(TRUE);
}

void CFlipCreatureCard::Flip()
{
	GetOrientation()->Flip();

	IncreasePermanentPower(m_nPowerDelta, TRUE);
	IncreasePower(m_nPowerDelta, TRUE);

	IncreasePermanentLife(m_nLifeDelta, TRUE);
	ChangeLife(Damage(this, m_nLifeDelta, PreventableType::NotPreventable, DamageType::NotDealingDamage), TRUE);

	if (b_AddLegendary)	AddCardType(CardType::Legendary, CardType::Null, CardTypeEntry::Temporary);
	GetGame()->AddStatebasedHint(CGame::StatebasedHint::LegendaryCards);

	m_CardModifiers.ApplyTo(this);
	m_CreatureModifiers.ApplyTo(this);
}

CString CFlipCreatureCard::GetCardName(BOOL bIncludeDetails) const
{
	if (GetOrientation()->IsFlipped()) return this->GetPrintedCardName() + __super::GetCardName(bIncludeDetails).Mid(__super::GetOriginalPrintedCardName().GetLength());
	return __super::GetCardName(bIncludeDetails);
}

void CFlipCreatureCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	ZoneId fromZoneId = GetZoneId();
	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	if (fromZoneId == ZoneId::Battlefield && pToZone->GetZoneId() != ZoneId::Battlefield)
	{
		m_CardModifiers.RemoveFrom(this);
		m_CreatureModifiers.RemoveFrom(this);
	}
}

BOOL CFlipCreatureCard::CanPlayFlipped(BOOL bIncludeTricks)
{
	return (GetOrientation()->IsFlipped());
}

BOOL CFlipCreatureCard::CanPlayUnflipped(BOOL bIncludeTricks)
{
	return (!GetOrientation()->IsFlipped());
}

CString CFlipCreatureCard::GetPrintedCardName() const
{
	if (GetOrientation()->IsFlipped()) return m_strFlipCardName; 
	return __super::GetPrintedCardName();
}

CString CFlipCreatureCard::GetSecondPrintedCardName() const
{
	return m_strFlipCardName; 
}

//____________________________________________________________________________
//
CDoubleFacedCreatureCard::CDoubleFacedCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness,
									 Power nPower2, Life nToughness2, LPCTSTR nFlipCardName)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_strDFCardName(nFlipCardName)
{
	m_nPowerDelta = nPower2 - nPower;
	m_nLifeDelta = nToughness2 - nToughness;

	SetDoubleNamed(TRUE);
}

void CDoubleFacedCreatureCard::Transform()
{
	GetOrientation()->IsSecondFaced() ? FirstFace() : SecondFace();
}

void CDoubleFacedCreatureCard::SecondFace(BOOL bFireTransformTrigger)
{
	GetOrientation()->SecondFace();

	IncreasePermanentPower(m_nPowerDelta, TRUE);
	IncreasePower(m_nPowerDelta, TRUE);

	IncreasePermanentLife(m_nLifeDelta, TRUE);
	ChangeLife(Damage(this, m_nLifeDelta, PreventableType::NotPreventable, DamageType::NotDealingDamage), TRUE);

	m_CardModifiers.ApplyTo(this);
	m_CreatureModifiers.ApplyTo(this);

	for (int i = 0; i < GetAbilityCount(); ++i)
	{
		CAbility* pAbility = GetAbility(i);

		CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
		if (!pEnchantmentAbility) 
			continue;
		if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
			pEnchantmentAbility->EndEnchantment();

		if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
			pEnchantmentAbility->StartEnchantment();
	}

	if (!bFireTransformTrigger)
		return;

	CSpecialEffectModifier modifier(this, TRANSFORM_TRIGGER_ID);
	modifier.ApplyTo(this);
}

void CDoubleFacedCreatureCard::FirstFace()
{
	GetOrientation()->FirstFace();

	DecreasePermanentPower(m_nPowerDelta, TRUE);
	DecreasePower(m_nPowerDelta, TRUE);

	DecreasePermanentLife(m_nLifeDelta, TRUE);
	ChangeLife(Damage(this, -m_nLifeDelta, PreventableType::NotPreventable, DamageType::NotDealingDamage), TRUE);

	m_CardModifiers.RemoveFrom(this);
	m_CreatureModifiers.RemoveFrom(this);

	for (int i = 0; i < GetAbilityCount(); ++i)
	{
		CAbility* pAbility = GetAbility(i);

		CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
		if (!pEnchantmentAbility) 
			continue;
		if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
			pEnchantmentAbility->StartEnchantment();

		if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
			pEnchantmentAbility->EndEnchantment();
	}

	CSpecialEffectModifier modifier(this, TRANSFORM_TRIGGER_ID);
	modifier.ApplyTo(this);
}

CString CDoubleFacedCreatureCard::GetCardName(BOOL bIncludeDetails) const
{
	if (GetOrientation()->IsSecondFaced()) return this->GetPrintedCardName() + __super::GetCardName(bIncludeDetails).Mid(__super::GetOriginalPrintedCardName().GetLength());
	return __super::GetCardName(bIncludeDetails);
}

void CDoubleFacedCreatureCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	ZoneId fromZoneId = GetZoneId();
	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	if (fromZoneId == ZoneId::Battlefield && pToZone->GetZoneId() != ZoneId::Battlefield)
	{
		m_CardModifiers.RemoveFrom(this);
		m_CreatureModifiers.RemoveFrom(this);
	}

	if (fromZoneId != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsSecondFaced())
	{
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
				pEnchantmentAbility->EndEnchantment();

			if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
				pEnchantmentAbility->StartEnchantment();
		}
	}

	if (fromZoneId != ZoneId::Battlefield && pToZone->GetZoneId() == ZoneId::Battlefield && !GetOrientation()->IsSecondFaced())
	{
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("First Face Enchantment"))
				pEnchantmentAbility->StartEnchantment();

			if ( pEnchantmentAbility->GetAbilityName() == _T("Second Face Enchantment"))
				pEnchantmentAbility->EndEnchantment();
		}
	}
}

BOOL CDoubleFacedCreatureCard::CanPlaySecondFace(BOOL bIncludeTricks) const
{
	return (GetOrientation()->IsSecondFaced());
}

BOOL CDoubleFacedCreatureCard::CanPlayFirstFace(BOOL bIncludeTricks) const
{
	return (!GetOrientation()->IsSecondFaced());
}

CString CDoubleFacedCreatureCard::GetPrintedCardName() const
{
	if (GetOrientation()->IsSecondFaced()) return m_strDFCardName; 
	return __super::GetPrintedCardName();
}

CString CDoubleFacedCreatureCard::GetSecondPrintedCardName() const
{
	return m_strDFCardName; 
}

DWORD CDoubleFacedCreatureCard::GetConvertedManaCost() const
{
	// Current rules: the mana value of a transforming double-faced permanent with its back face up is calculated
	// from the mana cost of its front face (the back face itself has no mana cost, see GetManaCost)
	return __super::GetConvertedManaCost();
}

DWORD CDoubleFacedCreatureCard::GetManaCost(CManaCostBase::Color manaCost, BOOL bMax)
{
	if (GetOrientation()->IsSecondFaced())
		return 0;
	return __super::GetManaCost(manaCost, bMax);
}

//____________________________________________________________________________
//
CMeldCreatureCard::CMeldCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness,
									 Power nMeldedPower, Life nMeldedToughness, LPCTSTR strMeldedCardName)
	: CDoubleFacedCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness,
							   nMeldedPower, nMeldedToughness, strMeldedCardName)
	, m_pMeldedCard(NULL)
{
}

void CMeldCreatureCard::MeldWith(CCard* pPartner)
{
	// The host turns to the melded face in exile and enters the battlefield as a new object
	// (as cards returned to the battlefield transformed, see CGraveyardFaceTransformModifier)
	m_pMeldedCard = pPartner;
	SecondFace(FALSE);
	Move(GetOwner()->GetZoneById(ZoneId::Battlefield), GetOwner(), MoveType::Others);
}

DWORD CMeldCreatureCard::GetConvertedManaCost() const
{
	DWORD nManaValue = __super::GetConvertedManaCost();
	if (m_pMeldedCard && GetOrientation()->IsSecondFaced())
		nManaValue += m_pMeldedCard->GetConvertedManaCost();
	return nManaValue;
}

void CMeldCreatureCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	CCard* pMeldedCard = NULL;
	ZoneId toZoneId = pToZone->GetZoneId();

	// Leaving the battlefield (phasing out keeps the cards melded)
	if (m_pMeldedCard && GetZoneId() == ZoneId::Battlefield &&
		(toZoneId == ZoneId::Hand || toZoneId == ZoneId::Library || toZoneId == ZoneId::Graveyard || toZoneId == ZoneId::Exile))
	{
		pMeldedCard = m_pMeldedCard;
		m_pMeldedCard = NULL;
	}

	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	// The other card goes to the same zone (it is already in exile)
	if (pMeldedCard && pMeldedCard->GetZoneId() == ZoneId::Exile && toZoneId != ZoneId::Exile)
		pMeldedCard->Move(pMeldedCard->GetOwner()->GetZoneById(toZoneId), pByPlayer, MoveType::Others, cardPlacement, can_dredge);
}

//____________________________________________________________________________
//
CMorphCreatureCard::CMorphCreatureCard(CGame* pGame, LPCTSTR strCardName, CardType cardType, const CreatureType& creatureType, UINT uID,
									 LPCTSTR strCostText, Power nPower, Life nToughness, LPCTSTR unMorphstrCardName)
	: CCreatureCard(pGame, strCardName, cardType, creatureType, uID, strCostText, nPower, nToughness)
	, m_strMorphCardName(_T("Morph"))
	, p_type(-1)
	, m_number(0)
{
	m_nPowerDelta = nPower - Power(2);
	m_nLifeDelta = nToughness - Life(2);

	SetDoubleNamed(TRUE);

	{
		counted_ptr<CSpell> cpSpell(
			::CreateObject<CSpell>(this, AbilityType::Creature, _T("3"), TRUE));

		cpSpell->SetMorph();

		AddSpell(cpSpell.GetPointer());
	}
	{			
		counted_ptr<CMorphAbility1> cpAbility(::CreateObject<CMorphAbility1>(this, unMorphstrCardName));

		counted_ptr<CPlayableIfTrait> cpTrait(
			::CreateObject<CPlayableIfTrait>(
				m_pUntapAbility,
				CPlayableIfTrait::PlayableCallback(this,
				&CMorphCreatureCard::CanPlayMorph)));
  
		cpAbility->Add(cpTrait.GetPointer());

		m_nMorphAbility = cpAbility.GetPointer();
		AddAbility(cpAbility.GetPointer());
	}
	
	m_number = 0;
}

void CMorphCreatureCard::AddCreatureType(SingleCreatureType pType)
{
	CCreatureTypeModifier* pModifier = new CCreatureTypeModifier(pType, TRUE);
	m_CreatureModifiers.Add(pModifier);
}

void CMorphCreatureCard::AddCardKeyword(CardKeyword pKeyword)
{
	CCardKeywordModifier* pModifier = new CCardKeywordModifier(pKeyword, TRUE, FALSE);
	m_CardModifiers.Add(pModifier);
}

void CMorphCreatureCard::AddCreatureKeyword(CreatureKeyword pKeyword)
{
	CCreatureKeywordModifier* pModifier = new CCreatureKeywordModifier(pKeyword, TRUE, FALSE);
	m_CreatureModifiers.Add(pModifier);
}

void CMorphCreatureCard::Morph()
{
	GetOrientation()->Morph();

	DecreasePermanentPower(m_nPowerDelta, TRUE);
	DecreasePower(m_nPowerDelta, TRUE);

	DecreasePermanentLife(m_nLifeDelta, TRUE);
	ChangeLife(Damage(this, -m_nLifeDelta, PreventableType::NotPreventable, DamageType::NotDealingDamage), TRUE);

	p_type = this->AddCardType(CardType::Creature, CardType::_All, CardTypeEntry::Temporary);
	m_pGame->IncreaseGameMorphNumber();
	m_number = m_pGame->GetGameMorphNumber();

	if (GetZoneId() == ZoneId::Battlefield)
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if (pEnchantmentAbility->GetAbilityName() == _T("Morph Enchantment"))
				pEnchantmentAbility->EndEnchantment();
		}
}

void CMorphCreatureCard::RevertMorph()
{
	GetOrientation()->UnMorph();

	IncreasePermanentPower(m_nPowerDelta, TRUE);
	IncreasePower(m_nPowerDelta, TRUE);

	IncreasePermanentLife(m_nLifeDelta, TRUE);
	ChangeLife(Damage(this, m_nLifeDelta, PreventableType::NotPreventable, DamageType::NotDealingDamage), TRUE);

	RemoveCardType(p_type);
	m_pGame->AddStatebasedHint(CGame::StatebasedHint::LegendaryCards);

	m_CardModifiers.ApplyTo(this);
	m_CreatureModifiers.ApplyTo(this);

	if (GetZoneId() == ZoneId::Battlefield)
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) 
				continue;
			if ( pEnchantmentAbility->GetAbilityName() == _T("Morph Enchantment"))
				pEnchantmentAbility->StartEnchantment();
		}
}

void CMorphCreatureCard::UnMorph()
{
	RevertMorph();
	CSpecialEffectModifier modifier(this, UNMORPH_TRIGGER_ID);
	modifier.ApplyTo(this);
}

CString CMorphCreatureCard::GetCardName(BOOL bIncludeDetails) const
{
	if (GetOrientation()->IsMorphed())
	{
		int k = m_number;  // Needed for getting correct text from int, because of int_ doesn't convert to string properly
		CString strTemp;
		strTemp.Format(_T("%d"), k);
		return this->GetPrintedCardName() + strTemp;
	}

	return __super::GetCardName(bIncludeDetails);
}

void CMorphCreatureCard::Move(CZone* pToZone, const CPlayer* pByPlayer, MoveType moveType, CardPlacement cardPlacement, BOOL can_dredge)
{
	ZoneId fromZoneId = GetZoneId();
	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	if ((fromZoneId & (ZoneId::Battlefield | ZoneId::Stack)).Any() && !(pToZone->GetZoneId() & (ZoneId::Battlefield | ZoneId::Stack)).Any()
		&& GetOrientation()->IsMorphed())
	{
		RevertMorph();
	}

	if (fromZoneId == ZoneId::Stack && pToZone->GetZoneId() == ZoneId::Battlefield && GetOrientation()->IsMorphed())
	{
		for (int i = 0; i < GetAbilityCount(); ++i)
		{
			CAbility* pAbility = GetAbility(i);

			CEnchantment* pEnchantmentAbility = dynamic_cast<CEnchantment*>(GetAbility(i));
			if (!pEnchantmentAbility) continue;

			if ( pEnchantmentAbility->GetAbilityName() == _T("Morph Enchantment"))
				pEnchantmentAbility->EndEnchantment();
		}
	}
}

BOOL CMorphCreatureCard::CanPlayMorph(BOOL bIncludeTricks)
{
	return (GetOrientation()->IsMorphed());
}

BOOL CMorphCreatureCard::CanPlayUnMorph(BOOL bIncludeTricks)
{
	return (!GetOrientation()->IsMorphed());
}

CString CMorphCreatureCard::GetPrintedCardName() const
{
	if (GetOrientation()->IsMorphed()) return m_strMorphCardName; 
	return __super::GetPrintedCardName();
}

CString CMorphCreatureCard::GetSecondPrintedCardName() const
{
	return m_strMorphCardName; 
}

CString CMorphCreatureCard::GetSecondCardName(BOOL bIncludeDetails) const
{
	return m_strMorphCardName + __super::GetCardName(bIncludeDetails).Mid(__super::GetPrintedCardName().GetLength());	
}

DWORD CMorphCreatureCard::GetConvertedManaCost() const
{
	if (GetOrientation()->IsMorphed())
		return 0;
	return __super::GetConvertedManaCost();
}

DWORD CMorphCreatureCard::GetManaCost(CManaCostBase::Color manaCost, BOOL bMax)
{
	if (GetOrientation()->IsMorphed())
		return 0;

	return __super::GetManaCost(manaCost, bMax);
}

//____________________________________________________________________________
//