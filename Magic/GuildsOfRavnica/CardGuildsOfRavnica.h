#pragma once

//____________________________________________________________________________
//
__declspec(dllexport)
counted_ptr<CCard> _cdecl CreateCard(CGame* pGame, LPCTSTR strCardName, StringArray& cardClassNames, UINT uID);

// ============================================================================
// BOROS GUILD - Mentor mechanic
// ============================================================================

class CAureliaExemplarOfJusticeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CAureliaExemplarOfJusticeCard);
};

//____________________________________________________________________________
//
class CLegionWarbossCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLegionWarbossCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CTajicLegionsEdgeCard : public CFirstStrikeCreatureCard
{
	DECLARE_CARD_CSTOR(CTajicLegionsEdgeCard);
};

//____________________________________________________________________________
//
class CSunhomeStalwartCard : public CFirstStrikeCreatureCard
{
	DECLARE_CARD_CSTOR(CSunhomeStalwartCard);
};

//____________________________________________________________________________
//
class CBladeInstructorCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBladeInstructorCard);
};

//____________________________________________________________________________
//
class CBorosChallengerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CBorosChallengerCard);
};

//____________________________________________________________________________
//
class CParhelionPatrolCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CParhelionPatrolCard);
};

//____________________________________________________________________________
//
class CDeafeningClarionCard : public CCard
{
	DECLARE_CARD_CSTOR(CDeafeningClarionCard);
};

//____________________________________________________________________________
//
class CIntegrityInterventionCard : public CCard
{
	DECLARE_CARD_CSTOR(CIntegrityInterventionCard);
};

// ============================================================================
// DIMIR GUILD - Surveil mechanic
// ============================================================================

class CDoomWhispererCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CDoomWhispererCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CNightveilPredatorCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNightveilPredatorCard);
};

//____________________________________________________________________________
//
class CThoughtErasureCard : public CCard
{
	DECLARE_CARD_CSTOR(CThoughtErasureCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CSinisterSabotageCard : public CCard
{
	DECLARE_CARD_CSTOR(CSinisterSabotageCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CDimirInformantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CDimirInformantCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CUnexplainedDisappearanceCard : public CCard
{
	DECLARE_CARD_CSTOR(CUnexplainedDisappearanceCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CMissionBriefingCard : public CCard
{
	DECLARE_CARD_CSTOR(CMissionBriefingCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CWhisperingSnitchCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CWhisperingSnitchCard);
};

// ============================================================================
// GOLGARI GUILD - Undergrowth mechanic
// ============================================================================

class CAssassinsTrophyCard : public CCard
{
	DECLARE_CARD_CSTOR(CAssassinsTrophyCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CCharnelTrollCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CCharnelTrollCard);

protected:
	CCardFilter m_CardFilter;
	CCardFilter m_SelfFilter;
};

//____________________________________________________________________________
//
class CLotlethGiantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CLotlethGiantCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CRhizomeLurcherCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CRhizomeLurcherCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CGlowsporeSchamanCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CGlowsporeSchamanCard);

protected:
	CCardFilter m_LandFilter;

	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CMolderhulkCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMolderhulkCard);

protected:
	CCardFilter m_LandFilter;

	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CKraulHarpoonerCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKraulHarpoonerCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CUnderealmLichCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CUnderealmLichCard);
};

// ============================================================================
// IZZET GUILD - Jump-start mechanic
// ============================================================================

class CCracklingDrakeCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CCracklingDrakeCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CNivMizzetParunCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CNivMizzetParunCard);
};

//____________________________________________________________________________
//
class CRiskFactorCard : public CCard
{
	DECLARE_CARD_CSTOR(CRiskFactorCard);
};

//____________________________________________________________________________
//
class CRadicalIdeaCard : public CCard
{
	DECLARE_CARD_CSTOR(CRadicalIdeaCard);
};

//____________________________________________________________________________
//
class CMurmurMysticCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CMurmurMysticCard);
};

//____________________________________________________________________________
//
class CIonizeCard : public CCard
{
	DECLARE_CARD_CSTOR(CIonizeCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CDirectCurrentCard : public CCard
{
	DECLARE_CARD_CSTOR(CDirectCurrentCard);
};

//____________________________________________________________________________
//
class CBeaconBoltCard : public CCard
{
	DECLARE_CARD_CSTOR(CBeaconBoltCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CWeeDragonautsCard : public CFlyingCreatureCard
{
	DECLARE_CARD_CSTOR(CWeeDragonautsCard);
};

// ============================================================================
// SELESNYA GUILD - Convoke mechanic
// ============================================================================

class CVeneratedLoxodonCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CVeneratedLoxodonCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CDivineVisitationCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CDivineVisitationCard);
};

//____________________________________________________________________________
//
class CEmmaraSoulOfTheAccordCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CEmmaraSoulOfTheAccordCard);
};

//____________________________________________________________________________
//
class CTrostaniDiscordantCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CTrostaniDiscordantCard);

protected:
	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

//____________________________________________________________________________
//
class CConclaveCavalierCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CConclaveCavalierCard);
};

//____________________________________________________________________________
//
class CKnightOfAutumnCard : public CCreatureCard
{
	DECLARE_CARD_CSTOR(CKnightOfAutumnCard);
};

//____________________________________________________________________________
//
class CConclaveTribunalCard : public CInPlaySpellCard
{
	DECLARE_CARD_CSTOR(CConclaveTribunalCard);

protected:
	CCardFilter m_ExileFilter;
	CCardFilter m_CreatureFilter;

	void OnResolutionCompleted(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListener;
};

// ============================================================================
// PLANESWALKERS
// ============================================================================

class CRalIzzetViceroyCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CRalIzzetViceroyCard);

protected:
	void OnResolutionCompletedPlus(const CAbilityAction* pAbilityAction, BOOL bResult);
	void OnResolutionCompletedMinus(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListenerPlus;
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListenerMinus;
};

//____________________________________________________________________________
//
class CVraskaGolgariQueenCard : public CPlaneswalkerCard
{
	DECLARE_CARD_CSTOR(CVraskaGolgariQueenCard);

protected:
	void OnResolutionCompletedPlus(const CAbilityAction* pAbilityAction, BOOL bResult);
	ListenerPtr<ResolutionCompletedEventSource::Listener> m_cpEventListenerPlus;
	CCardFilter m_SacrificeFilter;
};

// ============================================================================
// LANDS
// ============================================================================

class CSteamVentsCard : public CDualLandCard
{
	DECLARE_CARD_CSTOR(CSteamVentsCard);
};

//____________________________________________________________________________
//
class COvgrownTombGRNCard : public CDualLandCard
{
	DECLARE_CARD_CSTOR(COvgrownTombGRNCard);
};

//____________________________________________________________________________
//
class CSacredFoundryGRNCard : public CDualLandCard
{
	DECLARE_CARD_CSTOR(CSacredFoundryGRNCard);
};

//____________________________________________________________________________
//
class CTempleGardenGRNCard : public CDualLandCard
{
	DECLARE_CARD_CSTOR(CTempleGardenGRNCard);
};

//____________________________________________________________________________
//
class CWateryGraveGRNCard : public CDualLandCard
{
	DECLARE_CARD_CSTOR(CWateryGraveGRNCard);
};

//____________________________________________________________________________
//
class CBorosGuildgateGRNCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CBorosGuildgateGRNCard);
};

//____________________________________________________________________________
//
class CDimirGuildgateGRNCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CDimirGuildgateGRNCard);
};

//____________________________________________________________________________
//
class CGolgariGuildgateGRNCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CGolgariGuildgateGRNCard);
};

//____________________________________________________________________________
//
class CIzzetGuildgateGRNCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CIzzetGuildgateGRNCard);
};

//____________________________________________________________________________
//
class CSelesnyaGuildgateGRNCard : public CNonbasicLandCard
{
	DECLARE_CARD_CSTOR(CSelesnyaGuildgateGRNCard);
};
