#include "Framework.h"

Player::Player(POINT pos)
	:Actor(pos, 1, "Picture/jiki2.png")
	,m_firstShot(false)
{

}

Player::~Player()
{

}

void Player::Initialize(Game* gameInstance_,Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 40 * 1,40 * 2 },TAG::PLAYER));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	auto circle = shared_ptr<CircleCollisionCmp>(new CircleCollisionCmp(this, { 0,0 }, gameInstance_->GetStatus()->PLAYER_LIGHT * 295, TAG::PLAYER_LIGHT));
	Actor::AddComponent(circle, scene);
	gameInstance_->GetCollisionMNG()->AddCIRCLECollisionList(circle);

	m_mapCollision = std::shared_ptr<MapCollision>(new MapCollision(m_gameInstance, scene, this, TAG::MAP));
	Actor::AddComponent(m_mapCollision, scene);

	m_rigidBody = std::shared_ptr<RigidbodyCmp>(new RigidbodyCmp(this,STATE::JUMP,TAG::PLAYER));
	Actor::AddComponent(m_rigidBody, scene);

	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this,false,gameInstance_->GetStatus()->PLAYER_LIGHT*100));
	Actor::AddComponent(m_lightCmp, scene);

	//暗闇中に見える画像の生成
	m_darkPicture = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, "Picture/jiki2_dark.png"));
	Actor::AddComponent(m_darkPicture, scene);
}

void Player::Update()
{
	Actor::Update();
	
	for (auto& ladder : m_isLadder) {
		if (ladder.isLadder) {
			m_rigidBody->ChangeState(STATE::FLY);
			break;
		}
		else if(m_rigidBody->m_state!=FALL&& m_rigidBody->m_state != STAND){
			m_rigidBody->ChangeState(STATE::STAND);
		}
	}

	bool isClick_x = false;
	bool isClick_y = false;

	//移動
	if (m_gameInstance->GetInputMNG()->Down(L"RIGHT")) {
		m_vx = m_gameInstance->GetStatus()->PLAYER_SPEED;
		isClick_x = true;
		m_isRightdir = true;
	}
	if (m_gameInstance->GetInputMNG()->Down(L"LEFT")) {
		m_vx = -m_gameInstance->GetStatus()->PLAYER_SPEED;
		//printfDx("Player\n");
		isClick_x = true;
		m_isRightdir = false;
	}

	if (m_isRightdir) {
		ChangePicture("Picture/jiki2.png");
		m_darkPicture->m_darkPicture->ChangePicture("Picture/jiki2_dark.png");
	}
	else {
		ChangePicture("Picture/jiki.png");
		m_darkPicture->m_darkPicture->ChangePicture("Picture/jiki_dark.png");

	}

	//はしご
	if (m_rigidBody->m_state == STATE::FLY) {
		if (m_gameInstance->GetInputMNG()->Down(L"UP")) {
			m_vy = -m_gameInstance->GetStatus()->PLAYER_SPEED;
			isClick_y = true;
		}
		if (m_gameInstance->GetInputMNG()->Down(L"DOWN")) {
			m_vy = m_gameInstance->GetStatus()->PLAYER_SPEED;
			isClick_y = true;
		}
	}
	//ジャンプ
 	else if (m_rigidBody->m_state == STATE::STAND) {
		if (m_gameInstance->GetInputMNG()->Click(L"OK")) {
			m_rigidBody->ChangeState(STATE::JUMPSTT);
			isClick_y = true;
		}
	}

	//ライトのON、OFF
	if (m_gameInstance->GetInputMNG()->Click(L"LIGHT_CHANGE")) {
		if (!m_lightCmp->m_changeNow) {
			m_lightCmp->ChangeLightONOFF();
		}
	}

	SetMoveCheck(isClick_x, isClick_y);
	Actor::Move();
}

void Player::HitCollision(Actor* other, TAG tag, TAG selftag)
{
	Actor::HitCollision(other, tag,selftag);

	if (tag == TAG::PISHER && selftag==TAG::PLAYER && m_isActive) {
		static_cast<GameScene*>(m_sceneptr)->GameOver();
		m_isActive = false;
	}	
}

void Player::NoHitCollision(Actor* other, TAG tag)
{
}

Player* Player::Getthis()
{
	return this;
}

void Player::AddisLadder(int num, bool isladder)
{
	m_isLadder.push_back(LadderCol{ num,isladder });
}

void Player::SetisLadder(int num, bool isladder)
{
	for (auto& ladder : m_isLadder) {
		if (ladder.num == num) {
			ladder.isLadder = isladder;
		}
	}
}
