#include "Framework.h"


Pisher::Pisher(POINT pos)
	:Actor(pos,0.5,"Picture/UFO_dot.png")
	,m_target(nullptr)
{

}

Pisher::~Pisher()
{

}

void Pisher::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, { 40,40 }, TAG::PISHER));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	//暗闇中に見える画像の生成
	auto dark = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this,"Picture/pisherEye.png"));
	Actor::AddComponent(dark, scene);

	//プレイヤーを入手する
	m_player = scene->GetPlayer();

	//速度を入手する
	m_speed = m_gameInstance->GetStatus()->PISHER_SPEED;
}

void Pisher::Update()
{
	Actor::Update();

	//フィギュアがターゲット先だったら
	if (!m_isFigure) {

		//プレイヤーのライトが着いたらターゲットをプレイヤーに変更する
		if (m_player->GetLightOn()) {
			//m_target = m_player;
		}
		else {
			m_target = nullptr;
		}
	}

	//ターゲットが存在したら
	if (m_target != nullptr) {

		//ターゲットの位置
		auto targetPos = m_target->GetPos();

		//ターゲットを追いかけるX
		if (m_pos.x - targetPos.x >= 0) {
			m_vx = -m_speed;
		}
		else {
			m_vx  = m_speed;
		}

		//ターゲットを追いかけるY
		if (m_pos.y - targetPos.y >= 0) {
			m_vy = -m_speed;
		}
		else {
			m_vy = m_speed;
		}
	}

	Actor::Move();

	//変数の初期化
	m_vy = 0;
	m_vx = 0;
}

void Pisher::HitCollision(Actor* other, TAG tag,TAG selftag)
{
	Actor::HitCollision(other,tag, selftag);
}

void Pisher::NoHitCollision(Actor* other, TAG tag)
{
}
