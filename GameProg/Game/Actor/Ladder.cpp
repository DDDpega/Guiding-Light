#include "Framework.h"

Ladder::Ladder(POINT pos,int num)
	:Actor(pos, 2.5, "Picture/ladder.png",PIVOT::LEFTUP)
	, m_num(num)
{
}

Ladder::~Ladder()
{
}

void Ladder::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);
	m_sceneptr->GetPlayer()->AddisLadder(m_num, false);


	LONG x = (m_pictureSizeX * m_size) / 2;
	LONG y = (m_pictureSizeY * m_size) / 2;

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { x,y }, { 40,40 }, TAG::LADDER));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);
}

void Ladder::Update()
{
	Actor::Update();
}

void Ladder::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	if (tag == TAG::PLAYER && m_isActive) {
		m_sceneptr->GetPlayer()->SetisLadder(m_num, true);
		
	}
}

void Ladder::NoHitCollision(Actor* other, TAG tag)
{

	if (tag == TAG::PLAYER && m_isActive) {
		m_sceneptr->GetPlayer()->SetisLadder(m_num, false);

	}
}
