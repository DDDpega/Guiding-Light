#include"Framework.h"

SolarPanelBlock::SolarPanelBlock(POINT pos,bool isBlock, Scene* scene)
	:Actor(pos, 2.5, "Picture/SolarPanelBlock.png", PIVOT::LEFTUP)
	,m_isBlock(isBlock)
	, m_scene(scene)
{
}

SolarPanelBlock::~SolarPanelBlock()
{
}

void SolarPanelBlock::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_,scene);
	SetisVisible(m_isBlock);
}

void SolarPanelBlock::Update()
{
	Actor::Update();
	m_isBlock = static_cast<GameScene*>(m_scene)->m_solarpanel->GetIsTrigger();
	SetisVisible(m_isBlock);
}

void SolarPanelBlock::HitCollision(Actor* other, TAG tag, TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void SolarPanelBlock::NoHitCollision(Actor* other, TAG tag)
{
}
