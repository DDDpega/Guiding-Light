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
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	/*auto circleCollision = std::shared_ptr<CircleCollisionCmp>(new CircleCollisionCmp(this, { 0,0 }, 100, TAG::ENEMY));
	Actor::AddComponent(circleCollision, scene);
	gameInstance_->GetCollisionMNG()->AddCIRCLECollisionList(circleCollision);*/

	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(m_gameInstance, scene, this, TAG::PLAYER));
	Actor::AddComponent(m_mapCollision, scene);

	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this, STATE::FALL));
	Actor::AddComponent(m_rigidBody, scene);

	auto m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, 0.4));
	Actor::AddComponent(m_lightCmp, scene);

}

void Enemy::Update()
{
	Actor::Update();

	SetMoveCheck(false, false);
	m_vx = m_gameInstance->GetStatus()->ENEMY_SPEED;	// 右へ移動
	SetMoveCheck(true, false);

	Actor::Move();

	//画面外に出たら削除する
	if (m_pos.x <= m_pictureSizeX*m_size) {
		m_isActive = false;

		//敵の生成
		auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{ 1000,200 }));
		m_gameInstance->GetPictureMNG()->AddPicture(enemy, m_sceneptr);
	}
}



void Enemy::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	if ((tag == TAG::PLAYER || tag == TAG::BULLET || tag == TAG::CHILD) && m_isActive) {
		m_isActive = false;

		//敵の生成
		auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{ (LONG)(m_sceneptr->screenX + (m_pictureSizeX * m_size)/2) ,rand() % m_sceneptr->screenY }));
		m_gameInstance->GetPictureMNG()->AddPicture(enemy, m_sceneptr);
	}
}