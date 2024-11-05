#include "Framework.h"


Pisher::Pisher(Point pos)
	:Actor(pos)
	,m_target(nullptr)
{

}

Pisher::~Pisher()
{

}

void Pisher::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PISHER_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 },PISHER_INFO::COLLISION_SIZE, E_TAG::PISHER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//暗闇中に見える画像の生成
	auto dark = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER], 1));
	Actor::AddComponent(dark);

	//プレイヤーを入手する
	m_player = SceneManeger::gameScene->GetPlayer();

	//速度を入手する
	m_speed = Game::gameInstance->GetStatus()->PISHER_SPEED;
}

void Pisher::Update()
{
	Actor::Update();

	//フィギュアがターゲット先だったら
	if (!m_isFigure) {

		//プレイヤーのライトが着いたらターゲットをプレイヤーに変更する
		if (m_player->GetLightOn()) {
			m_target = m_player;
		}
	}

	//ターゲットが存在したら
	if (m_target != nullptr) {

		//ターゲットの位置
		auto targetPos = m_target->GetPos();

		//移動の速度決定
		float radial = atan2f((targetPos.y - m_pos.y), (targetPos.x - m_pos.x));
		m_vx = cos(radial) * m_speed;
		m_vy = sin(radial) * m_speed;
	}

	Actor::Move();

	//変数の初期化
	m_vy = 0;
	m_vx = 0;
}

void Pisher::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other,tag, selftag);
}

void Pisher::NoHitCollision(Actor* other, E_TAG tag)
{
}
