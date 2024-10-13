#include "Framework.h"


Enemy::Enemy(POINT pos)
	:Actor(pos, 1 ,"Picture/enemy_0.png")
{

}

Enemy::~Enemy()
{
}

void Enemy::Initialize(Game* gameInstance_,Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 80,50 }, TAG::ENEMY));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->addCollisionList(collision);

	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(m_gameInstance, scene, this, TAG::PLAYER));
	Actor::AddComponent(m_mapCollision, scene);

	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this, STATE::FALL));
	Actor::AddComponent(m_rigidBody, scene);

}

void Enemy::Update()
{
	Actor::Update();

	SetMoveCheck(false, false);
	m_vx = m_gameInstance->GetStatus()->ENEMY_SPEED;	// âEÇ÷à⁄ìÆ
	SetMoveCheck(true, false);

	Actor::Move();

	//âÊñ äOÇ…èoÇΩÇÁçÌèúÇ∑ÇÈ
	if (m_pos.x <= m_pictureSizeX*m_size) {
		m_isActive = false;

		//ìGÇÃê∂ê¨
		auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{ 1000,0 }));
		m_gameInstance->GetPictureMNG()->AddPicture(enemy, m_sceneptr);
	}
}



void Enemy::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	if ((tag == TAG::PLAYER || tag == TAG::BULLET || tag == TAG::CHILD) && m_isActive) {
		m_isActive = false;

		//ìGÇÃê∂ê¨
		auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{ (LONG)(m_sceneptr->screenX + (m_pictureSizeX * m_size)/2) ,rand() % m_sceneptr->screenY }));
		m_gameInstance->GetPictureMNG()->AddPicture(enemy, m_sceneptr);
	}
}