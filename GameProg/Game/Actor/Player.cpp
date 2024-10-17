#include "Framework.h"

Player::Player(POINT pos)
	:Actor(pos, 1, "Picture/jiki.png")
	,m_firstShot(false)
{

}

Player::~Player()
{

}

void Player::Initialize(Game* gameInstance_,Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 50,60 },TAG::PLAYER));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	auto circle = shared_ptr<CircleCollisionCmp>(new CircleCollisionCmp(this, { 0,0 }, gameInstance_->GetStatus()->PLAYER_LIGHT * 295, TAG::PLAYER_LIGHT));
	Actor::AddComponent(circle, scene);
	gameInstance_->GetCollisionMNG()->AddCIRCLECollisionList(circle);

	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(m_gameInstance, scene, this, TAG::PLAYER));
	Actor::AddComponent(m_mapCollision, scene);

	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this,STATE::JUMP));
	Actor::AddComponent(m_rigidBody, scene);

	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this,false,gameInstance_->GetStatus()->PLAYER_LIGHT));
	Actor::AddComponent(m_lightCmp, scene);
}

void Player::Update()
{
	Actor::Update();
	

	bool isClick_x = false;
	bool isClick_y = false;

	//移動
	if (KeyDown(KEY_INPUT_D) >= 1) {
		m_vx = m_gameInstance->GetStatus()->PLAYER_SPEED;
		isClick_x = true;
	}
	if (KeyDown(KEY_INPUT_A) >= 1) {
		m_vx = -m_gameInstance->GetStatus()->PLAYER_SPEED;
		//printfDx("Player\n");
		isClick_x = true;
	}

	if (m_rigidBody->m_state == STATE::FLY) {
		if (KeyDown(KEY_INPUT_W) >= 1) {
			m_vy = -m_gameInstance->GetStatus()->PLAYER_SPEED;
			isClick_y = true;
		}
		if (KeyDown(KEY_INPUT_S) >= 1) {
			m_vy = m_gameInstance->GetStatus()->PLAYER_SPEED;
			isClick_y = true;
		}
	}
	//ジャンプ
	else if (m_rigidBody->m_state == STATE::STAND) {
		if (KeyClick(KEY_INPUT_SPACE) >= 1) {
			m_rigidBody->ChangeState(STATE::JUMPSTT);
			isClick_y = true;
		}
	}

	//ライトのON、OFF
	if (KeyClick(KEY_INPUT_E) >= 1) {
		if (!m_lightCmp->m_changeNow) {
			m_lightCmp->ChangeLightONOFF();
		}
	}

	SetMoveCheck(isClick_x, isClick_y);
	Actor::Move();
}

void Player::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	if (tag == TAG::ENEMY && m_isActive) {
		m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::TITLE);
		m_isActive = false;
	}	
}

void Player::NoHitCollision(Actor* other, TAG tag)
{
}
