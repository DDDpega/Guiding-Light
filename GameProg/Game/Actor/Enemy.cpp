#include "Framework.h"


Enemy::Enemy(POINT pos)
	:Actor(pos, 1 ,"Picture/enemy_0.png")
{

}

Enemy::~Enemy()
{
	Actor::~Actor();
}

void Enemy::Initialize(Game* gameInstance_,Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 80,50 }, TAG::ENEMY));
	gameInstance_->GetActorMNG()->AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->addCollisionList(collision);

	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(m_gameInstance, scene, this, TAG::PLAYER));
	gameInstance_->GetActorMNG()->AddComponent(m_mapCollision, scene);

	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this, STATE::FALL));
	gameInstance_->GetActorMNG()->AddComponent(m_rigidBody, scene);

}

void Enemy::Update()
{
	Actor::Update();

	SetMoveCheck(false, false);
	m_vx = m_gameInstance->GetStatus()->ENEMY_SPEED;	// ‰E‚ÖˆÚ“®
	SetMoveCheck(true, false);

	Actor::Move();

	//‰æ–ÊŠO‚Éo‚½‚çíœ‚·‚é
	if (m_pos.x <= m_pictureSizeX*m_size) {
		m_isActive = false;

		//“G‚Ì¶¬
		auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{ 1000,0 }));
		m_gameInstance->GetPictureMNG()->AddPicture(enemy, m_sceneptr);
	}
}



void Enemy::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	if ((tag == TAG::PLAYER || tag == TAG::BULLET || tag == TAG::CHILD) && m_isActive) {
		m_isActive = false;

		//“G‚Ì¶¬
		auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{ (LONG)(m_sceneptr->screenX + (m_pictureSizeX * m_size)/2) ,rand() % m_sceneptr->screenY }));
		m_gameInstance->GetPictureMNG()->AddPicture(enemy, m_sceneptr);
	}
}