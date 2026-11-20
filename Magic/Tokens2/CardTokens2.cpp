#include "stdafx.h"
#include "CardTokens2.h"

#define new DEBUG_NEW

#define DEFINE_TOKEN(T)	\
	if (!_tcsicmp(strTokenName, _T(#T))) { cpCard = counted_ptr<CCard>(new T(pGame, uID)); break; }

//____________________________________________________________________________
//
counted_ptr<CCard> CreateToken(CGame* pGame, LPCTSTR strTokenName, UINT uID)
{
	counted_ptr<CCard> cpCard;
	do
	{
		DEFINE_TOKEN(CAngelJToken);
		DEFINE_TOKEN(CAngelKToken);
		DEFINE_TOKEN(CAngelLToken);
		DEFINE_TOKEN(CAshayaTheAwokenWorldToken);
		DEFINE_TOKEN(CBearCToken);
		DEFINE_TOKEN(CBeastOToken);
		DEFINE_TOKEN(CBeastPToken);
		DEFINE_TOKEN(CBirdLToken);
		DEFINE_TOKEN(CCatFToken);
		DEFINE_TOKEN(CClericBToken);
		DEFINE_TOKEN(CConstructAToken);
		DEFINE_TOKEN(CDemonDToken);
		DEFINE_TOKEN(CDemonEToken);
		DEFINE_TOKEN(CDevilAToken);
		DEFINE_TOKEN(CDjinnMonkAToken);
		DEFINE_TOKEN(CDragonHToken);
		DEFINE_TOKEN(CDragonIToken);
		DEFINE_TOKEN(CDragonJToken);
		DEFINE_TOKEN(CEldraziAToken);
		DEFINE_TOKEN(CEldraziScionAToken);
		DEFINE_TOKEN(CEldraziScionBToken);
		DEFINE_TOKEN(CEldraziScionCToken);
		DEFINE_TOKEN(CEldraziScionDToken);
		DEFINE_TOKEN(CEldraziScionEToken);
		DEFINE_TOKEN(CEldraziScionFToken);
		DEFINE_TOKEN(CAwakenedLandToken);
		DEFINE_TOKEN(CElementalXToken);
		DEFINE_TOKEN(CElementalYToken);
		DEFINE_TOKEN(CElementalZToken);
		DEFINE_TOKEN(CElementalZAToken);
		DEFINE_TOKEN(CElementalZBToken);
		DEFINE_TOKEN(CElephantEToken);
		DEFINE_TOKEN(CElfWarriorDToken);
		DEFINE_TOKEN(CGoblinNToken);
		DEFINE_TOKEN(CGoblinOToken);
		DEFINE_TOKEN(CGoblinPToken);
		DEFINE_TOKEN(CGoblinQToken);
		DEFINE_TOKEN(CHumanClericAToken);
		DEFINE_TOKEN(CHumanSoldierAToken);
		DEFINE_TOKEN(CHydraAToken);
		DEFINE_TOKEN(CInsectIToken);
		DEFINE_TOKEN(CInsectJToken);
		DEFINE_TOKEN(CKnightAllyAToken);
		DEFINE_TOKEN(CKorAllyAToken);
		DEFINE_TOKEN(CKnightEToken);
		DEFINE_TOKEN(CMonkAToken);
		DEFINE_TOKEN(COctopusAToken);
		DEFINE_TOKEN(COgreAToken);
		DEFINE_TOKEN(COozeFToken);
		DEFINE_TOKEN(CPlantBToken);
		DEFINE_TOKEN(CPlantCToken);
		DEFINE_TOKEN(CSliverDToken);
		DEFINE_TOKEN(CSnakeHToken);
		DEFINE_TOKEN(CSnakeIToken);
		DEFINE_TOKEN(CSoldierRToken);
		DEFINE_TOKEN(CSoldierSToken);
		DEFINE_TOKEN(CSphinxAToken);
		DEFINE_TOKEN(CSpiderDToken);
		DEFINE_TOKEN(CSpiritOToken);
		DEFINE_TOKEN(CSpiritPToken);
		DEFINE_TOKEN(CSpiritQToken);
		DEFINE_TOKEN(CSpiritRToken);
		DEFINE_TOKEN(CSpiritSToken);
		DEFINE_TOKEN(CSpiritWarriorAToken);
		DEFINE_TOKEN(CSquidAToken);
		DEFINE_TOKEN(CSquirrelEToken);
		DEFINE_TOKEN(CThopterDToken);
		DEFINE_TOKEN(CThopterEToken);
		DEFINE_TOKEN(CTreefolkWarriorAToken)
		DEFINE_TOKEN(CVampireDToken);
		DEFINE_TOKEN(CVampireKnightAToken);
		DEFINE_TOKEN(CWarriorAToken);
		DEFINE_TOKEN(CWarriorBToken);
		DEFINE_TOKEN(CWarriorCToken);
		DEFINE_TOKEN(CWarriorDToken);
		DEFINE_TOKEN(CWolfKToken);
		DEFINE_TOKEN(CWolfLToken);
		DEFINE_TOKEN(CZombieHorrorAToken);
		DEFINE_TOKEN(CZombiePToken);
		DEFINE_TOKEN(CZombieQToken);
		DEFINE_TOKEN(CZombieRToken);
		DEFINE_TOKEN(CZombieSToken);
		DEFINE_TOKEN(CZombieTToken);
		DEFINE_TOKEN(CZombieUToken);
		DEFINE_TOKEN(CZombieVToken);
		DEFINE_TOKEN(CClueAToken);
		DEFINE_TOKEN(CHumanDToken);
		DEFINE_TOKEN(CEldraziHorrorAToken);
		DEFINE_TOKEN(CSpiderEToken);
		DEFINE_TOKEN(CHumanWizardAToken);
		DEFINE_TOKEN(CServoAToken);
		DEFINE_TOKEN(CConstructBToken);
		DEFINE_TOKEN(CBeastQToken);
		DEFINE_TOKEN(CEtheriumCellToken);
		DEFINE_TOKEN(CWarriorEToken);
		DEFINE_TOKEN(CWurmIToken);
		DEFINE_TOKEN(CBeastRToken);
		DEFINE_TOKEN(CHippoCToken);
		DEFINE_TOKEN(CCatGToken);
		DEFINE_TOKEN(CSnakeJToken);
		DEFINE_TOKEN(CHorseAToken);
		DEFINE_TOKEN(CInsectKToken);
		DEFINE_TOKEN(CTreasureToken);
		DEFINE_TOKEN(CDinosaurAToken);
		DEFINE_TOKEN(CPirateAToken);
		DEFINE_TOKEN(CIllusionCToken);
		DEFINE_TOKEN(CVampireEToken);
		DEFINE_TOKEN(CMerfolkAToken);
		DEFINE_TOKEN(CElementalZCToken);
		DEFINE_TOKEN(CConstructCToken);
		DEFINE_TOKEN(CClericCToken);
		DEFINE_TOKEN(CDemonFToken);
		DEFINE_TOKEN(CNightmareHorrorAToken);
		DEFINE_TOKEN(CKaroxBladewingToken);
		DEFINE_TOKEN(CZombieKnightToken);
		DEFINE_TOKEN(CAvatarAToken);
		DEFINE_TOKEN(COxAToken);
		DEFINE_TOKEN(CAngelMToken);
		DEFINE_TOKEN(CSoldierTToken);
		DEFINE_TOKEN(CElfKnightAToken);
		DEFINE_TOKEN(CBirdIllusionAToken);
		DEFINE_TOKEN(CInsectLToken);
		DEFINE_TOKEN(CBeastSToken);
		DEFINE_TOKEN(CFrogLizardAToken);
		DEFINE_TOKEN(CSphinxBToken);
		DEFINE_TOKEN(CCentaurEToken);
		DEFINE_TOKEN(COozeGToken);
		DEFINE_TOKEN(CIllusionDToken);
	} while (false);

	return cpCard;
}

//____________________________________________________________________________
//
void CTokenCreature::Move(CZone* pToZone,
							const CPlayer* pByPlayer,
							MoveType moveType,
							CardPlacement cardPlacement, BOOL can_dredge)
{
	__super::Move(pToZone, pByPlayer, moveType, cardPlacement, can_dredge);

	if (GetZoneId() != ZoneId::Battlefield && !this->GetCardType().IsToken())
		__super::Move(GetOwner()->GetZoneById(ZoneId::_Tokens), pByPlayer, MoveType::Others);
}

//____________________________________________________________________________
//
CSnakeHToken::CSnakeHToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Snake"), CardType::Creature | CardType::GlobalEnchantment | CardType::Token,
		CREATURE_TYPE(Snake), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Black | CardType::Green, CardType::_ColorMask);
	GetCardKeyword()->AddDeathtouch(FALSE);
// JOU version: used by Pharika, God of Affliction
}

//____________________________________________________________________________
//
CSphinxAToken::CSphinxAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Sphinx"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Sphinx), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// JOU version: used by Hour of Need 
}

//____________________________________________________________________________
//
CSpiderDToken::CSpiderDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spider"), CardType::Creature | CardType::GlobalEnchantment | CardType::Token,
		CREATURE_TYPE(Spider), nID,
		_T(""),
		Power(1), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
	GetCreatureKeyword()->AddReach(FALSE);
// JOU version: used by Renowned Weaver
}

//____________________________________________________________________________
//
CHydraAToken::CHydraAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Hydra"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Hydra), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// JOU version: used by Hydra Broodmaster
}

//____________________________________________________________________________
//
CConstructAToken::CConstructAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Construct"), CardType::_ArtifactCreature | CardType::Token,
		CREATURE_TYPE(Construct), nID,
		_T(""),
		Power(1), Life(1))
{
	GetCreatureKeyword()->Defender();
// CNS version: used by Flamewright
}

//____________________________________________________________________________
//
CWolfKToken::CWolfKToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Wolf"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Wolf), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// CNS version: used by Predator's Howl
}

//____________________________________________________________________________
//
CSquirrelEToken::CSquirrelEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Squirrel"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Squirrel), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// CNS version: used by Squirrel Nest
}

//____________________________________________________________________________
//
CElephantEToken::CElephantEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elephant"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elephant), nID,
		_T(""),
		Power(3), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// CNS version: used by Selvala's Charge, Terastodon
}

//____________________________________________________________________________
//
COgreAToken::COgreAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Ogre"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Ogre), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
// CNS version: used by Grenzo's Rebuttal
}

//____________________________________________________________________________
//
CDemonDToken::CDemonDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Demon"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Demon), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// CNS version: used by Reign of the Pit
}

//____________________________________________________________________________
//
CSpiritOToken::CSpiritOToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spirit"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// CNS version: used by Custodi Soulbinders, Doomed Traveler
}

//____________________________________________________________________________
//
CZombiePToken::CZombiePToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// CNS version: used by Wakedancer
}

//____________________________________________________________________________
//
CBirdLToken::CBirdLToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Bird"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Bird), nID,
		_T(""),
		Power(3), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// KTK version: used by Wingmate Roc 
}

//____________________________________________________________________________
//
CSpiritPToken::CSpiritPToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spirit"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// KTK version: used by Abzan Ascendancy
}

//____________________________________________________________________________
//
CWarriorAToken::CWarriorAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Warrior), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// KTK version: used by Herald of Anafenza, Mardu Charm,  Mardu Hordechief, Take Up Arms 
}

//____________________________________________________________________________
//
CWarriorBToken::CWarriorBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Warrior), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// KTK version: used by Herald of Anafenza, Mardu Charm,  Mardu Hordechief, Take Up Arms
}

//____________________________________________________________________________
//
CVampireDToken::CVampireDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Vampire"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Vampire), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// KTK version: used by Sorin, Solemn Visitor
}

//____________________________________________________________________________
//
CZombieQToken::CZombieQToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// KTK version: used by Empty the Pits, Sidisi, Brood Tyrant
}

//____________________________________________________________________________
//
CBearCToken::CBearCToken(CGame* pGame, UINT nID)
    : CTokenCreature(pGame, _T("Bear"), CardType::Creature | CardType::Token,
        CREATURE_TYPE(Bear), nID,
        _T(""),
        Power(4), Life(4))
{
    AddCardType(CardType::Green, CardType::_ColorMask);
// KTK version: used by Bear's Companion
}

//____________________________________________________________________________
//
CSnakeIToken::CSnakeIToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Snake"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Snake), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// KTK version: used by Hooded Hydra, Rite of the Serpent
}

//____________________________________________________________________________
//
CGoblinNToken::CGoblinNToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Goblin"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Goblin), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
// KTK version: used by Goblinslide, Hordeling Outburst, Mardu Ascendancy, Ponyback Brigade
}

//____________________________________________________________________________
//
CSpiritWarriorAToken::CSpiritWarriorAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spirit Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Spirit, Warrior), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Green | CardType::Black, CardType::_ColorMask);
// KTK version: used by Kin-Tree Invocation
}

//____________________________________________________________________________
//
CSpiritQToken::CSpiritQToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spirit"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// FRF version: used by Sandsteppe Outcast
}

//____________________________________________________________________________
//
CWarriorCToken::CWarriorCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Warrior), nID,
		_T(""),
		Power(2), Life(1))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// FRF version: used by Mardu Strike Leader 
}

//____________________________________________________________________________
//
CMonkAToken::CMonkAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Monk"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	// prowess
	typedef
		TTriggeredAbility< CTriggeredModifyCreatureAbility, CWhenSpellCast > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->GetTrigger().GetCardFilterHelper().SetPredefinedFilter(CCardFilter::GetFilter(_T("non-creatures")));

	cpAbility->GetPowerModifier().SetPowerDelta(Power(+1));
	cpAbility->GetLifeModifier().SetLifeDelta(Life(+1));
	cpAbility->GetLifeModifier().SetPreventable(PreventableType::NotPreventable);

	cpAbility->AddAbilityTag(AbilityTag::CreatureChange);

	AddAbility(cpAbility.GetPointer());
// FRF version: used by Monastery Mentor
}

//____________________________________________________________________________
//
CCatFToken::CCatFToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Cat"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Cat), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::White, CardType::_ColorMask);

// M14 version used by Ajani, Caller of the Pride and Ajani's Chosen
}

//____________________________________________________________________________
//
CClericBToken::CClericBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Cleric"), CardType::Creature | CardType::GlobalEnchantment | CardType::Token,
		CREATURE_TYPE(Cleric), nID,
		_T(""),
		Power(2), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// THS version: used by Heliod, God of the Sun 
}

//____________________________________________________________________________
//
CDragonHToken::CDragonHToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Dragon"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Dragon), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Dragons of Tarkir version: used by Descent of the Dragons, Dragon Whisperer and Sarkhan Unbroken.
}

//____________________________________________________________________________
//
CWarriorDToken::CWarriorDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Warrior), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// Dragons of Tarkir version: used by Secure the Wastes.
}

//____________________________________________________________________________
//
CDjinnMonkAToken::CDjinnMonkAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Djinn Monk"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Djinn, Monk), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Dragons of Tarkir version: used by Ojutai's Summons and Skywise Teachings. 
}

//____________________________________________________________________________
//
CZombieRToken::CZombieRToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// Dragons of Tarkir version: used by Necromaster Dragon and Rakshasa Gravecaller.
}

//____________________________________________________________________________
//
CZombieHorrorAToken::CZombieHorrorAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie Horror"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Zombie, Horror), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// Dragons of Tarkir version: used by Corpseweft.
}

//____________________________________________________________________________
//
CGoblinOToken::CGoblinOToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Goblin"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Goblin), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
// Dragons of Tarkir version: used by Dragon Fodder.
}

//____________________________________________________________________________
//
CSliverDToken::CSliverDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Sliver"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Sliver), nID,
		_T(""),
		Power(1), Life(1))
{
// M15 version: used by Sliver Hive.
}

//____________________________________________________________________________
//
CSoldierRToken::CSoldierRToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Soldier"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Soldier), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// M15 version: used by First Response and Raise the Alarm.
}
//____________________________________________________________________________
//
CZombieSToken::CZombieSToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// M15 version: used by Necromancer's Stockpile and Waste Not. 
}

//____________________________________________________________________________
//
CGoblinPToken::CGoblinPToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Goblin"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Goblin), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddHaste(FALSE);
// M15 version: used by Goblin Rabblemaster.
}

//____________________________________________________________________________
//
CBeastOToken::CBeastOToken(CGame* pGame, UINT nID)
    : CTokenCreature(pGame, _T("Beast"), CardType::Creature | CardType::Token,
        CREATURE_TYPE(Beast), nID,
        _T(""),
        Power(3), Life(3))
{
    AddCardType(CardType::Green, CardType::_ColorMask);
// M15 version: used by Feral Incarnation and Soul of Zendikar.
}

//____________________________________________________________________________
//
CBeastPToken::CBeastPToken(CGame* pGame, UINT nID)
    : CTokenCreature(pGame, _T("Beast"), CardType::Creature | CardType::Token,
        CREATURE_TYPE(Beast), nID,
        _T(""),
        Power(3), Life(3))
{
    AddCardType(CardType::Black, CardType::_ColorMask);
	GetCardKeyword()->AddDeathtouch(FALSE);
// M15 version: used by Garruk, Apex Predator.
}

//____________________________________________________________________________
//
CInsectIToken::CInsectIToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Insect"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Insect), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCardKeyword()->AddDeathtouch(FALSE);
// M15 version: used by Hornet Nest and Hornet Queen.
}

//____________________________________________________________________________
//
CSpiritRToken::CSpiritRToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spirit"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// M15 version: used by Spirit Bonds and Triplicate Spirits.
}

//____________________________________________________________________________
//
CSquidAToken::CSquidAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Squid"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddLandwalk(CreatureKeyword::Islandwalk, FALSE);
// M15 version: used by Chasm Skulker and Coral Barrier.
}

//____________________________________________________________________________
//
CDragonIToken::CDragonIToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Dragon"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Dragon), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);

	counted_ptr<CPumpAbility> cpAbility(
		::CreateObject<CPumpAbility>(this,
			RED_MANA_TEXT,
			Power(+1), Life(+0)));
	ATLASSERT(cpAbility);

	AddAbility(cpAbility.GetPointer());
// M15 version: used by Brood Keeper.
}

//____________________________________________________________________________
//
CTreefolkWarriorAToken::CTreefolkWarriorAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Treefolk Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Treefolk, Warrior), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Green, CardType::_ColorMask);

	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new CardTypeComparer(CardType::Forest, false)));

	AddAbility(cpAbility.GetPointer());
// M15 version: used by Kalonian Twingrove.
}

//____________________________________________________________________________
//
CAshayaTheAwokenWorldToken::CAshayaTheAwokenWorldToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Ashaya, the Awoken World"), CardType::_LegendaryCreature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Origins version: used by Nissa, Sage Animist.
}

//____________________________________________________________________________
//
CAngelJToken::CAngelJToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Angel"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Angel), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);

	GetCreatureKeyword()->AddFlying(FALSE);

// Origins version: used by Sigil of the Empty Throne.
}

//____________________________________________________________________________
//
CKnightEToken::CKnightEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Knight"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Knight), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::White, CardType::_ColorMask);

	GetCreatureKeyword()->AddVigilance(FALSE);

// Origins version: used by Gideon's Phalanx and Knightly Valor.
}

//____________________________________________________________________________
//
CSoldierSToken::CSoldierSToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Soldier"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Soldier), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// Origins version: used by Murder Investigation.
}
//____________________________________________________________________________
//
CDemonEToken::CDemonEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Demon"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Demon), nID,
		_T(""),
		Power(5), Life(5))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Origins version: used by Priest of the Blood Rite.
}

//____________________________________________________________________________
//
CZombieTToken::CZombieTToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// Origins version: used by Undead Servant and Liliana, Heretical Healer.
}

//____________________________________________________________________________
//
CGoblinQToken::CGoblinQToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Goblin"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Goblin), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
// Origins version: used by Dragon Fodder.
}

//____________________________________________________________________________
//
CElementalXToken::CElementalXToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elemental"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Origins version: used by Zendikar's Roil. 
}

//____________________________________________________________________________
//
CElfWarriorDToken::CElfWarriorDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elf Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Elf, Warrior), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Origins version: used by Dwynen's Elite. 
}

//____________________________________________________________________________
//
CThopterDToken::CThopterDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Thopter"), CardType::_ArtifactCreature | CardType::Token, 
		CREATURE_TYPE(Thopter), nID,
		_T(""),
		Power(1), Life(1))
{
	GetCreatureKeyword()->AddFlying(FALSE);

// Origins version: used by  Aspiring Aeronaut, Foundry of the Consuls, Ghirapur Gearcrafter, 
// Hangarback Walker, Pia and Kiran Nalaar, Thopter Engineer, Thopter Spy Network and Whirler Rogue. 
}

//____________________________________________________________________________
//
CThopterEToken::CThopterEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Thopter"), CardType::_ArtifactCreature | CardType::Token, 
		CREATURE_TYPE(Thopter), nID,
		_T(""),
		Power(1), Life(1))
{
	GetCreatureKeyword()->AddFlying(FALSE);

// Origins version: used by  Aspiring Aeronaut, Foundry of the Consuls, Ghirapur Gearcrafter, 
// Hangarback Walker, Pia and Kiran Nalaar, Thopter Engineer, Thopter Spy Network and Whirler Rogue. 
}

//____________________________________________________________________________
//
COctopusAToken::COctopusAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Octopus"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Octopus), nID,
		_T(""),
		Power(8), Life(8))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
// BFZ / OGW version: used by Kiora, Master of the Depths and Crush of Tentacles.
}

//____________________________________________________________________________
//
CEldraziScionAToken::CEldraziScionAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Scion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Scion), nID,
		_T(""),
		Power(1), Life(1))
{
	counted_ptr<CManaProductionBySacificeAbility> cpAbility(
		::CreateObject<CManaProductionBySacificeAbility>(this,
			_T("1")));

	AddAbility(cpAbility.GetPointer());
// BFZ version: used by Adverse Conditions, Blight Herder, Blisterpod, Brood Butcher, Brood Monitor, 
// Call the Scions, Catacomb Sifter, Drowner of Hope, Eldrazi Skyspawner, Eyeless Watcher, From Beyond, 
// Grave Birthing, Incubator Drone, Spawning Bed and Void Attendant.
}

//____________________________________________________________________________
//
CEldraziScionBToken::CEldraziScionBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Scion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Scion), nID,
		_T(""),
		Power(1), Life(1))
{
	counted_ptr<CManaProductionBySacificeAbility> cpAbility(
		::CreateObject<CManaProductionBySacificeAbility>(this,
			_T("1")));

	AddAbility(cpAbility.GetPointer());
// BFZ version: used by Adverse Conditions, Blight Herder, Blisterpod, Brood Butcher, Brood Monitor, 
// Call the Scions, Catacomb Sifter, Drowner of Hope, Eldrazi Skyspawner, Eyeless Watcher, From Beyond, 
// Grave Birthing, Incubator Drone, Spawning Bed and Void Attendant.
}

//____________________________________________________________________________
//
CEldraziScionCToken::CEldraziScionCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Scion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Scion), nID,
		_T(""),
		Power(1), Life(1))
{
	counted_ptr<CManaProductionBySacificeAbility> cpAbility(
		::CreateObject<CManaProductionBySacificeAbility>(this,
			_T("1")));

	AddAbility(cpAbility.GetPointer());
// BFZ version: used by Adverse Conditions, Blight Herder, Blisterpod, Brood Butcher, Brood Monitor, 
// Call the Scions, Catacomb Sifter, Drowner of Hope, Eldrazi Skyspawner, Eyeless Watcher, From Beyond, 
// Grave Birthing, Incubator Drone, Spawning Bed and Void Attendant.
}

//____________________________________________________________________________
//
CEldraziAToken::CEldraziAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Eldrazi), nID,
		_T(""),
		Power(10), Life(10))
{
// BFZ version: used by Desolation Twin. 
}

//____________________________________________________________________________
//
CKnightAllyAToken::CKnightAllyAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Knight Ally"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Knight, Ally), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::White, CardType::_ColorMask);

// BFZ / OGW version: used by  Gideon, Ally of Zendikar and Allied Reinforcements.
}

//____________________________________________________________________________
//
CKorAllyAToken::CKorAllyAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Kor Ally"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Kor, Ally), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);

// BFZ / OGW version: used by Retreat to Emeria, Unified Front, Captain's Claws and Oath of Gideon.
}

//____________________________________________________________________________
//
CDragonJToken::CDragonJToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Dragon"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Dragon), nID,
		_T(""),
		Power(5), Life(5))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// BFZ version: used by Dragonmaster Outcast.
}

//____________________________________________________________________________
//
CElementalYToken::CElementalYToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elemental"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(3), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddTrample(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Akoum Stonewaker: "Exile that token at the beginning of the next end step." (as Ball Lightning)
	{
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		AddAbility(cpAbility.GetPointer());
	}
// BFZ version: used by Akoum Stonewaker.
}

//____________________________________________________________________________
//
CPlantBToken::CPlantBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Plant"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Plant), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// BFZ version: used by Grovetender Druids.
}

//____________________________________________________________________________
//
CElementalZToken::CElementalZToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elemental"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(5), Life(5))
{
	AddCardType(CardType::Red | CardType::Green, CardType::_ColorMask);
// BFZ version: used by Omnath, Locus of Rage.
}

//____________________________________________________________________________
//
CPlantCToken::CPlantCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Plant"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Plant), nID,
		_T(""),
		Power(0), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// OGW version: used by Nissa, Voice of Zendikar.
}

//____________________________________________________________________________
//
CElementalZAToken::CElementalZAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elemental"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// OGW version: used by Seed Guardian.
}

//____________________________________________________________________________
//
CElementalZBToken::CElementalZBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elemental"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(3), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddHaste(FALSE);

	// Chandra, Flamecaller: "Exile them at the beginning of the next end step." (as Ball Lightning)
	{
		typedef
			TTriggeredAbility< CTriggeredMoveCardAbility, CWhenNodeChanged > TriggeredAbility;

		counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::EndStep));

		cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
		cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Exile);
		cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Others);

		cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Exile));

		AddAbility(cpAbility.GetPointer());
	}
// OGW version: used by Chandra, Flamecaller.
}

//____________________________________________________________________________
//
CZombieUToken::CZombieUToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// OGW version: used by Drana's Chosen, Kalitas, Traitor of Ghet and Null Caller.
}

//____________________________________________________________________________
//
CAngelKToken::CAngelKToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Angel"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Angel), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);

	GetCreatureKeyword()->AddFlying(FALSE);

// OGW version: used by Linvala, the Preserver.
}

//____________________________________________________________________________
//
CEldraziScionDToken::CEldraziScionDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Scion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Scion), nID,
		_T(""),
		Power(1), Life(1))
{
	counted_ptr<CManaProductionBySacificeAbility> cpAbility(
		::CreateObject<CManaProductionBySacificeAbility>(this,
			_T("1")));

	AddAbility(cpAbility.GetPointer());
// OGW version: used by Abstruse Interference, Birthing Hulk, Scion Summoner, Sifter of Skulls, 
// Vile Redeemer and Warping Wail.
}

//____________________________________________________________________________
//
CEldraziScionEToken::CEldraziScionEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Scion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Scion), nID,
		_T(""),
		Power(1), Life(1))
{
	counted_ptr<CManaProductionBySacificeAbility> cpAbility(
		::CreateObject<CManaProductionBySacificeAbility>(this,
			_T("1")));

	AddAbility(cpAbility.GetPointer());
// OGW version: used by Abstruse Interference, Birthing Hulk, Scion Summoner, Sifter of Skulls, 
// Vile Redeemer and Warping Wail.
}

//____________________________________________________________________________
//
CEldraziScionFToken::CEldraziScionFToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Scion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Scion), nID,
		_T(""),
		Power(1), Life(1))
{
	counted_ptr<CManaProductionBySacificeAbility> cpAbility(
		::CreateObject<CManaProductionBySacificeAbility>(this,
			_T("1")));

	AddAbility(cpAbility.GetPointer());
// OGW version: used by Abstruse Interference, Birthing Hulk, Scion Summoner, Sifter of Skulls, 
// Vile Redeemer and Warping Wail.
}

CAwakenedLandToken::CAwakenedLandToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Awakened Land"), CardType::Creature,
		CREATURE_TYPE(Elemental), nID, _T(""), Power(0), Life(0))
{
}

//____________________________________________________________________________
//
CAngelLToken::CAngelLToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Angel"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Angel), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);

	GetCreatureKeyword()->AddFlying(FALSE);
// Shadows over Innistrad version: used by Descend upon the Sinful and Invocation of Saint Traft.
}

//____________________________________________________________________________
//
CHumanSoldierAToken::CHumanSoldierAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Human Soldier"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Human, Soldier), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// Shadows over Innistrad version: used by Sigarda, Heron's Grace, Strength of Arms 
// and Ulvenwald Mysteries.
}
//____________________________________________________________________________
//
CSpiritSToken::CSpiritSToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spirit"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spirit), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Shadows over Innistrad version: used by Dauntless Cathar, Drogskol Cavalry,
// Emissary of the Sleepless, Nearheath Chaplain, Not Forgotten, Slayer's Plate and
// Vessel of Ephemera.
}

//____________________________________________________________________________
//
CVampireKnightAToken::CVampireKnightAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Vampire Knight"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Vampire), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Black, CardType::_ColorMask);

	GetCardKeyword()->AddLifelink(FALSE);
// Shadows over Innistrad version: used by Call the Bloodline and Sorin, Grim Nemesis. 
}

//____________________________________________________________________________
//
CZombieVToken::CZombieVToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Zombie), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// Shadows over Innistrad version: used by Diregraf Colossus, Drunau Corpse Trawler, 
// From Under the Floorboards, Ghoulcaller's Accomplice, Gisa's Bidding, 
// Rise from the Tides and Shamble Back.
}

//____________________________________________________________________________
//
CDevilAToken::CDevilAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Devil"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Devil), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	
	typedef
		TTriggeredTargetAbility< CTriggeredModifyCreatureAbility, CWhenSelfMoved > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(
		::CreateObject<TriggeredAbility>(this,
			ZoneId::Battlefield, ZoneId::Graveyard));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetLifeModifier().SetLifeDelta(Life(-1));
	cpAbility->GetLifeModifier().SetDamageType(DamageType::AbilityDamage | DamageType::NonCombatDamage);

	cpAbility->GetTargeting().GetSubjectCardFilter().AddComparer(new AnyCreatureComparer);
	cpAbility->GetTargeting().SetIncludePlayers(true);

	cpAbility->GetTargeting().SetDefaultCharacteristic(Characteristic::Negative);

	cpAbility->SetTriggerToPlayerOption(TriggerToPlayerOption::TriggerToParameter1);

	cpAbility->AddAbilityTag(AbilityTag::DamageSource);

	AddAbility(cpAbility.GetPointer());
// Shadows over Innistrad version: used by Dance with Devils and Devils' Playground.
}

//____________________________________________________________________________
//
CInsectJToken::CInsectJToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Insect"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Insect), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Shadows over Innistrad version: used by Crawling Sensation.
}

//____________________________________________________________________________
//
COozeFToken::COozeFToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Ooze"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Ooze), nID,
		_T(""),
		Power(3), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Shadows over Innistrad version: used by Inexorable Blob.
}

//____________________________________________________________________________
//
CWolfLToken::CWolfLToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Wolf"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Wolf), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Shadows over Innistrad version: Arlinn Kord, Cult of the Waxing Moon, 
// Pack Guardian and Silverfur Partisan. 
}

//____________________________________________________________________________
//
CHumanClericAToken::CHumanClericAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Human Cleric"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Human, Soldier), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White | CardType::Black, CardType::_ColorMask);
// Shadows over Innistrad version: used by Westvale Abbey and Westvale Cult Leader.
}
//____________________________________________________________________________
//
// Clue: an artifact token, not a creature. There is no noncreature token class (CTokenCreationModifier
// treats every token as a CTokenCreature), so it is a CTokenCreature without the creature card type:
// it can't attack or block and the state-based actions don't check its toughness.
CClueAToken::CClueAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Clue"), CardType::Artifact | CardType::Token,
		CreatureType(SingleCreatureType::Null), nID,
		_T(""),
		Power(0), Life(1))
{
	// {2}, Sacrifice this artifact: Draw a card.
	counted_ptr<CActivatedAbility<CDrawCardSpell>> cpAbility(
		::CreateObject<CActivatedAbility<CDrawCardSpell>>(this,
			_T("2"), 1));

	cpAbility->AddSacrificeCost();

	AddAbility(cpAbility.GetPointer());
}

//____________________________________________________________________________
CHumanDToken::CHumanDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Human"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Human), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
// Eldritch Moon version: used by Hanweir Garrison.
}

//____________________________________________________________________________
CEldraziHorrorAToken::CEldraziHorrorAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Eldrazi Horror"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Eldrazi, Horror), nID,
		_T(""),
		Power(3), Life(2))
{
// Eldritch Moon version: used by Hanweir, the Writhing Township.
}

//____________________________________________________________________________
CSpiderEToken::CSpiderEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Spider"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Spider), nID,
		_T(""),
		Power(1), Life(2))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
	GetCreatureKeyword()->AddReach(FALSE);
// Eldritch Moon version: used by Ishkanah, Grafwidow.
}

//____________________________________________________________________________
CHumanWizardAToken::CHumanWizardAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Human Wizard"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Human, Wizard), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
// Eldritch Moon version: used by Docent of Perfection.
}

//____________________________________________________________________________
CServoAToken::CServoAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Servo"), CardType::_ArtifactCreature | CardType::Token,
		CREATURE_TYPE(Servo), nID,
		_T(""),
		Power(1), Life(1))
{
// Kaladesh version: used by Fabricate and the Servo makers.
}

//____________________________________________________________________________
CConstructBToken::CConstructBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Construct"), CardType::_ArtifactCreature | CardType::Token,
		CREATURE_TYPE(Construct), nID,
		_T(""),
		Power(0), Life(0))
{
// Kaladesh version: used by Metallurgic Summonings (an X/X Construct: its power and toughness are set when created).
}

//____________________________________________________________________________
CBeastQToken::CBeastQToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Beast"), CardType::_ArtifactCreature | CardType::Token,
		CREATURE_TYPE(Beast), nID,
		_T(""),
		Power(6), Life(6))
{
// Kaladesh version: used by Architect of the Untamed.
}

//____________________________________________________________________________
CEtheriumCellToken::CEtheriumCellToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Etherium Cell"), CardType::Artifact | CardType::Token,
		CreatureType(SingleCreatureType::Null), nID,
		_T(""),
		Power(0), Life(1))
{
	// {T}, Sacrifice this token: Add one mana of any color. (one mana ability for each color, as Lotus Petal)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
// Aether Revolt version: used by Tezzeret the Schemer.
}
//____________________________________________________________________________
//
CWarriorEToken::CWarriorEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Warrior"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Warrior), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddVigilance(FALSE);
// Amonkhet version (1/1 white Warrior with vigilance): used by Oketra's Monument.
}
//____________________________________________________________________________
//
CWurmIToken::CWurmIToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Wurm"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Wurm), nID,
		_T(""),
		Power(5), Life(5))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Amonkhet version: used by Sandwurm Convergence.
}
//____________________________________________________________________________
//
CBeastRToken::CBeastRToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Beast"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Beast), nID,
		_T(""),
		Power(4), Life(2))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Amonkhet version: used by Trial of Strength.
}
//____________________________________________________________________________
//
CHippoCToken::CHippoCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Hippo"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Hippo), nID,
		_T(""),
		Power(3), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Amonkhet version: used by Mouth // Feed.
}
//____________________________________________________________________________
//
CCatGToken::CCatGToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Cat"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Cat), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCardKeyword()->AddLifelink(FALSE);
// Amonkhet version (1/1 white Cat with lifelink): used by Regal Caracal.
}
//____________________________________________________________________________
//
CSnakeJToken::CSnakeJToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Snake"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Snake), nID,
		_T(""),
		Power(5), Life(4))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Hour of Devastation version: used by Rhonas's Last Stand.
}
//____________________________________________________________________________
//
CHorseAToken::CHorseAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Horse"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Horse), nID,
		_T(""),
		Power(5), Life(5))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// Hour of Devastation version: used by Crested Sunmare.
}
//____________________________________________________________________________
//
CInsectKToken::CInsectKToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Insect"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Insect), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Blue | CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddHaste(FALSE);
// Hour of Devastation version: used by The Locust God.
}
//____________________________________________________________________________
//
CTreasureToken::CTreasureToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Treasure"), CardType::Artifact | CardType::Token,
		CreatureType(SingleCreatureType::Null), nID,
		_T(""),
		Power(0), Life(1))
{
	// {T}, Sacrifice this token: Add one mana of any color. (as Etherium Cell)
	LPCTSTR colors[] = { WHITE_MANA_TEXT, BLUE_MANA_TEXT, BLACK_MANA_TEXT, RED_MANA_TEXT, GREEN_MANA_TEXT };
	for (int i = 0; i < _countof(colors); ++i)
	{
		counted_ptr<CManaProductionAbility> cpAbility(
			::CreateObject<CManaProductionAbility>(this, _T(""), AbilityType::Activated, colors[i]));
		cpAbility->AddTapCost();
		cpAbility->AddSacrificeCost();
		AddAbility(cpAbility.GetPointer());
	}
// Ixalan version: used by the Treasure makers of Ixalan and Rivals of Ixalan.
}
//____________________________________________________________________________
//
CDinosaurAToken::CDinosaurAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Dinosaur"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Dinosaur), nID,
		_T(""),
		Power(3), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
	GetCreatureKeyword()->AddTrample(FALSE);
// Ixalan version: used by Huatli, Warrior Poet.
}
//____________________________________________________________________________
//
CPirateAToken::CPirateAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Pirate"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Pirate), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
// Ixalan version: used by Vraska, Relic Seeker.
}
//____________________________________________________________________________
//
CIllusionCToken::CIllusionCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Illusion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Illusion), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);

	// When this token becomes the target of a spell, sacrifice it. (as Phantasmal Bear in M12)
	typedef
		TTriggeredAbility< CTriggeredMoveCardAbility, CWhenSubjectTargeted,
							CWhenSubjectTargeted::CardEventCallback, &CWhenSubjectTargeted::SetCardEventCallback > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(
		::CreateObject<TriggeredAbility>(this, TRUE, FALSE));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->GetTrigger().GetCardFilterHelper().SetFilterType(CCardFilterHelper::FilterType::Custom);
	cpAbility->GetTrigger().GetCardFilterHelper().GetCustomFilter().AddComparer(new SpecificCardComparer(this));
	cpAbility->GetMoveCardModifier().SetToZone(ZoneId::Graveyard);
	cpAbility->GetMoveCardModifier().SetMoveType(MoveType::Sacrifice);
	cpAbility->AddAbilityTag(AbilityTag(ZoneId::Battlefield, ZoneId::Graveyard));
	AddAbility(cpAbility.GetPointer());
// Ixalan version: used by Jace, Cunning Castaway.
}
//____________________________________________________________________________
//
CVampireEToken::CVampireEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Vampire"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Vampire), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCardKeyword()->AddLifelink(FALSE);
// Ixalan version: used by Legion's Landing and Adanto, the First Fort.
}
//____________________________________________________________________________
//
CMerfolkAToken::CMerfolkAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Merfolk"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Merfolk), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCardKeyword()->AddHexproof(FALSE);
// Ixalan version: used by Deeproot Waters.
}
//____________________________________________________________________________
//
CElementalZCToken::CElementalZCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elemental"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Elemental), nID,
		_T(""),
		Power(0), Life(1))
{
	AddCardType(CardType::Red, CardType::_ColorMask);

	// At the beginning of your upkeep, sacrifice this token and return target card named Rekindling Phoenix from your
	// graveyard to the battlefield. It gains haste until end of turn.
	// Note: the Phoenix isn't targeted (the first one in the graveyard)
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CElementalZCToken::BeforeReturn));
	AddAbility(cpAbility.GetPointer());
// Rivals of Ixalan version: used by Rekindling Phoenix.
}

bool CElementalZCToken::BeforeReturn(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	if (GetZoneId() == ZoneId::Battlefield)
	{
		CMoveCardModifier pSacrifice = CMoveCardModifier(ZoneId::Battlefield, ZoneId::Graveyard, TRUE, MoveType::Sacrifice, pController);
		pSacrifice.ApplyTo(this);
	}

	CZone* pGraveyard = pController->GetZoneById(ZoneId::Graveyard);
	for (int i = pGraveyard->GetSize() - 1; i >= 0; --i)
	{
		CCard* pCard = pGraveyard->GetAt(i);
		if (pCard->GetCardType().IsToken() || _tcscmp(pCard->GetPrintedCardName(), _T("Rekindling Phoenix")) != 0)
			continue;

		CMoveCardModifier pReturn = CMoveCardModifier(ZoneId::Graveyard, ZoneId::Battlefield, TRUE, MoveType::Others, pController);
		pReturn.ApplyTo(pCard);

		CCreatureCard* pCreature = dynamic_cast<CCreatureCard*>(pCard);
		if (pCreature && pCreature->GetZoneId() == ZoneId::Battlefield)
			pCreature->GetCreatureKeyword()->AddHaste(TRUE);
		break;
	}
	return true;
}
//____________________________________________________________________________
//
CConstructCToken::CConstructCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Construct"), CardType::_ArtifactCreature | CardType::Token,
		CREATURE_TYPE(Construct), nID,
		_T(""),
		Power(0), Life(0))
{
	// This token gets +1/+1 for each artifact you control. (as Nim Grotesque in Fifth Dawn)
	counted_ptr<CTriggeredChgPwrTghWhenCardPlayedAbility> cpAbility(
		::CreateObject<CTriggeredChgPwrTghWhenCardPlayedAbility>(this,
			ZoneId::Battlefield,
			new CardTypeComparer(CardType::Artifact, false)));

	AddAbility(cpAbility.GetPointer());
// Dominaria version: used by Karn, Scion of Urza.
}
//____________________________________________________________________________
//
CClericCToken::CClericCToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Cleric"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Cleric), nID,
		_T(""),
		Power(0), Life(1))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// Dominaria version: used by Rite of Belzenlok.
}
//____________________________________________________________________________
//
CDemonFToken::CDemonFToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Demon"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Demon), nID,
		_T(""),
		Power(6), Life(6))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddTrample(FALSE);

	// At the beginning of your upkeep, sacrifice another creature. If you can't, this token deals 6 damage to you.
	typedef
		TTriggeredAbility< CTriggeredAbility<>, CWhenNodeChanged > TriggeredAbility;

	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this, NodeId::UpkeepStep));

	cpAbility->GetTrigger().SetMonitorControllerOnly(TRUE);
	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetResolutionStartedCallback(CAbility::ResolutionStartedCallback(this, &CDemonFToken::BeforeSacrifice));
	AddAbility(cpAbility.GetPointer());
// Dominaria version: used by Rite of Belzenlok.
}

bool CDemonFToken::BeforeSacrifice(CAbilityAction* pAction)
{
	CPlayer* pController = pAction->GetController();
	CCardFilter others(_T("another creature"), _T("other creatures"), new AnyCreatureComparer);
	others.AddComparer(new NegateCardComparer(new SpecificCardComparer(this)));
	if (others.CountIncluded(pController->GetZoneById(ZoneId::Battlefield)->GetCardContainer()) == 0)
	{
		CLifeModifier pDamage = CLifeModifier(Life(-6), this, PreventableType::Preventable,
			DamageType::AbilityDamage | DamageType::NonCombatDamage);
		pDamage.ApplyTo(pController);
		return true;
	}

	CZoneModifier pModifier = CZoneModifier(GetGame(), ZoneId::Battlefield, SpecialNumber::All,
		CZoneModifier::RoleType::PrimaryPlayer,
		CardPlacement::Top, CZoneModifier::RoleType::PrimaryPlayer);
	pModifier.AddSelection(MinimumValue(1), MaximumValue(1), // another creature
		CZoneModifier::RoleType::PrimaryPlayer, // select by
		CZoneModifier::RoleType::PrimaryPlayer, // reveal to
		&others, // what cards
		ZoneId::Graveyard, // if selected, move cards to
		CZoneModifier::RoleType::PrimaryPlayer, // select by this player
		CardPlacement::Top, // put selected cards on
		MoveType::Sacrifice, // move type
		CZoneModifier::RoleType::PrimaryPlayer); // order selected cards by this player
	pModifier.ApplyTo(pController);
	return true;
}
//____________________________________________________________________________
//
CNightmareHorrorAToken::CNightmareHorrorAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Nightmare Horror"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Nightmare, Horror), nID,
		_T(""),
		Power(0), Life(0))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
// Dominaria version: used by Chainer's Torment (it gets X +1/+1 counters).
}
//____________________________________________________________________________
//
CKaroxBladewingToken::CKaroxBladewingToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Karox Bladewing"), CardType::Creature | CardType::Legendary | CardType::Token,
		CREATURE_TYPE(Dragon), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::Red, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Dominaria version: used by Verix Bladewing.
}
//____________________________________________________________________________
//
CZombieKnightToken::CZombieKnightToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Zombie Knight"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Zombie, Knight), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Black, CardType::_ColorMask);
	GetCreatureKeyword()->AddCantBeBlockedByOne(FALSE);
// Dominaria version: used by Josu Vess, Lich Knight.
}
//____________________________________________________________________________
//
CAvatarAToken::CAvatarAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Avatar"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Avatar), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Core Set 2019 version: used by Ajani's Last Stand.
}
//____________________________________________________________________________
//
COxAToken::COxAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Ox"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Ox), nID,
		_T(""),
		Power(2), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);
// Core Set 2019 version: used by Transmogrifying Wand.
}
//____________________________________________________________________________
//
CAngelMToken::CAngelMToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Angel"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Angel), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
// Core Set 2019 version: used by Resplendent Angel.
}
//____________________________________________________________________________
//
CSoldierTToken::CSoldierTToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Soldier"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Soldier), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::White, CardType::_ColorMask);
	GetCardKeyword()->AddLifelink(FALSE);
// Guilds of Ravnica version: used by Dawn of Hope.
}
//____________________________________________________________________________
//
CElfKnightAToken::CElfKnightAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Elf Knight"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Elf, Knight), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Green | CardType::White, CardType::_ColorMask);
	GetCreatureKeyword()->AddVigilance(FALSE);
// Guilds of Ravnica version: used by Sprouting Renewal.
}
//____________________________________________________________________________
//
CBirdIllusionAToken::CBirdIllusionAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Bird Illusion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Bird, Illusion), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
// Guilds of Ravnica version: used by Murmuring Mystic.
}
//____________________________________________________________________________
//
CInsectLToken::CInsectLToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Insect"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Insect), nID,
		_T(""),
		Power(1), Life(1))
{
	AddCardType(CardType::Black | CardType::Green, CardType::_ColorMask);
// Guilds of Ravnica version: used by Izoni, Thousand-Eyed.
}
//____________________________________________________________________________
//
CBeastSToken::CBeastSToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Beast"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Beast), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::Red | CardType::Green, CardType::_ColorMask);
	GetCreatureKeyword()->AddTrample(FALSE);
// Ravnica Allegiance version: used by the Domri, Chaos Bringer emblem.
}
//____________________________________________________________________________
//
CFrogLizardAToken::CFrogLizardAToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Frog Lizard"), CardType::Creature | CardType::Token,
		CREATURE_TYPE2(Frog, Lizard), nID,
		_T(""),
		Power(3), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Ravnica Allegiance version: used by Incubation // Incongruity.
}
//____________________________________________________________________________
//
CSphinxBToken::CSphinxBToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Sphinx"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Sphinx), nID,
		_T(""),
		Power(4), Life(4))
{
	AddCardType(CardType::White | CardType::Blue, CardType::_ColorMask);
	GetCreatureKeyword()->AddFlying(FALSE);
	GetCreatureKeyword()->AddVigilance(FALSE);
// Ravnica Allegiance version: used by Warrant // Warden.
}
//____________________________________________________________________________
//
CCentaurEToken::CCentaurEToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Centaur"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Centaur), nID,
		_T(""),
		Power(3), Life(3))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Ravnica Allegiance version: used by Rampage of the Clans.
}
//____________________________________________________________________________
//
COozeGToken::COozeGToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Ooze"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Ooze), nID,
		_T(""),
		Power(2), Life(2))
{
	AddCardType(CardType::Green, CardType::_ColorMask);
// Ravnica Allegiance version: used by Biogenic Ooze.
}
//____________________________________________________________________________
//
CIllusionDToken::CIllusionDToken(CGame* pGame, UINT nID)
	: CTokenCreature(pGame, _T("Illusion"), CardType::Creature | CardType::Token,
		CREATURE_TYPE(Illusion), nID,
		_T(""),
		Power(0), Life(2))
{
	AddCardType(CardType::Blue, CardType::_ColorMask);

	// Whenever this token blocks a creature, that creature doesn't untap during its controller's next untap step.
	counted_ptr<TriggeredAbility> cpAbility(::CreateObject<TriggeredAbility>(this));

	cpAbility->SetOptionalType(TriggeredAbility::OptionalType::Required);
	cpAbility->SetContextFunction(TriggeredAbility::ContextFunction(this, &CIllusionDToken::SetBlockContext));
	cpAbility->SetBeforeResolveSelectionCallback(TriggeredAbility::BeforeResolveSelectionCallback(this, &CIllusionDToken::BeforeSkipUntap));
	AddAbility(cpAbility.GetPointer());
// Ravnica Allegiance version: used by Mesmerizing Benthid.
}

bool CIllusionDToken::SetBlockContext(CTriggeredAbility<>::TriggerContextType& triggerContext,
	CCreatureCard* pCreature1, CCreatureCard* pCreature2, int n1, int n2) const
{
	// The blocked creature is the one that isn't this token
	CCreatureCard* pBlocked = (pCreature1 != this) ? pCreature1 : pCreature2;
	if (!pBlocked || pBlocked == this)
		return false;
	triggerContext.nValue1 = (DWORD)pBlocked;
	return true;
}

bool CIllusionDToken::BeforeSkipUntap(TriggeredAbility::TriggeredActionType* pAction)
{
	CCard* pCard = (CCard*)pAction->GetTriggerContext().nValue1;
	if (!pCard || pCard->GetZoneId() != ZoneId::Battlefield)
		return true;

	// (as Watertrap Weaver, without tapping it)
	CScheduledCardModifier pSkip = CScheduledCardModifier(GetGame(),
		new CCardKeywordModifier(CardKeyword::NoUntapInUntapPhase, TRUE, FALSE),
		TurnNumberDelta(-1), NodeId::UpkeepStep, true, CScheduledCardModifier::Operation::ApplyToNowRemoveLater,
		CScheduledCardModifier::DeltaOption::CustomPlayerTurn, pCard->GetController());
	pSkip.ApplyTo(pCard);
	return true;
}
