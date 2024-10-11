#include "Framework.h"


Player::Player(POINT pos)
	:Actor(pos, 1, "Picture/jiki.png")
	,m_firstShot(false)
	,m_bulletframe(0)
{

}

Player::~Player()
{
}

void Player::Initialize(Game* gameInstance_,Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	/*lightPicture = std::shared_ptr<Picture>(new Picture(m_pos, 1, "Picture/light.png", PIVOT::CENTER, SORT::SORT_LIGHT));
	gameInstance_->GetPictureMNG()->AddPicture(lightPicture,scene);*/

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 80,80 },TAG::PLAYER));
	gameInstance_->GetActorMNG()->AddComponent(collision,scene);
	gameInstance_->GetCollisionMNG()->addCollisionList(collision);


	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(m_gameInstance, scene, this, TAG::PLAYER));
	gameInstance_->GetActorMNG()->AddComponent(m_mapCollision, scene);

	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this,STATE::JUMP));
	gameInstance_->GetActorMNG()->AddComponent(m_rigidBody, scene);
}

void Player::Update()
{
	Actor::Update();
	

	bool isClick_x = false;
	bool isClick_y = false;

	//ˆÚ“®
	if (KeyDown(KEY_INPUT_RIGHT) >= 1) {
		m_vx = m_gameInstance->GetStatus()->PLAYER_SPEED;
		isClick_x = true;
	}
	if (KeyDown(KEY_INPUT_LEFT) >= 1) {
		m_vx = -m_gameInstance->GetStatus()->PLAYER_SPEED;
		printfDx("Player\n");
		isClick_x = true;
	}

	//ƒWƒƒƒ“ƒv
	if (KeyClick(KEY_INPUT_UP) >= 1) {
		m_rigidBody->ChangeState(STATE::JUMPSTT);
		isClick_y = true;
	}


	SetMoveCheck(isClick_x, isClick_y);
	Actor::Move();
}

void Player::HitCollision(Actor* other, TAG tag)
{
	Actor::HitCollision(other, tag);

	if (tag == TAG::ENEMY) {
		m_isActive = false;
	}
}