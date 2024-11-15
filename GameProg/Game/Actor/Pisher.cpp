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
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PISHER_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER],0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 },PISHER_INFO::COLLISION_SIZE, E_TAG::PISHER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//暗闇中に見える画像の生成
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER_EYE], 0));
	Actor::AddComponent(m_darkPictureCmp);

	//プレイヤーを入手する
	m_player = SceneManeger::gameScene->GetPlayer();

	//速度を入手する
	m_speed = Game::gameInstance->GetStatus()->PISHER_SPEED;
}

void Pisher::Update()
{
	Actor::Update();

	//現在電気がついているもののリストを回す
	auto figureList = SceneManeger::gameScene->m_figureList;
	for (int i = 0; i < figureList.size(); i++) {
		if (figureList[i]->m_lightOn) {
			m_isFigure = true;
			m_target = figureList[i];
			break;
		}
		else {
			m_isFigure = false;
		}
	}

	//蠅のターゲットをフィギュアから解除する
	SceneManeger::gameScene->m_figureList.clear();
	for (int i = 0; i < figureList.size(); i++) {
		if (figureList[i]->m_lightOn) {
			SceneManeger::gameScene->m_figureList.push_back(figureList[i]);
		}
	}

	//フィギュアがターゲット先だったら
	if (!m_isFigure) {

		//プレイヤーのライトが着いたらターゲットをプレイヤーに変更する
		if (m_player->GetLightOn()) {
			m_target = m_player;
		}
		else {
			m_target = nullptr;
		}
	}

	//ターゲットが存在したら
	if (m_target != nullptr) {

		//ターゲットの位置
		auto targetPos = m_target->GetPos();
		if (m_isFigure) {
			targetPos.y -= 80;
		}
		//移動の速度決定
		float radial = atan2f((targetPos.y - m_pos.y), (targetPos.x - m_pos.x));
		m_vx = cos(radial) * m_speed;
		m_vy = sin(radial) * m_speed;

		//左右反転
		if ((int)m_pos.x != (int)targetPos.x && (int)m_pos.y != (int)targetPos.y) {
			m_pictureCmp->m_picture->m_reverse = (m_vx < 0);
			m_darkPictureCmp->m_darkPicture->m_reverse = (m_vx < 0);
		}

		//10フレームごとに画像を変更する
		if (Game::gameInstance->m_framecnt % 10 == 0) {
			if (m_pictureCmp->m_picture->m_handle == ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER].handle[0]) {
				m_pictureCmp->m_picture->ChangePicture(ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER], 1);
			}
			else {
				m_pictureCmp->m_picture->ChangePicture(ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::PISHER], 0);
			}
		}
	}

	//サウンド
	float distance = (1.0f/sqrt(abs(m_pos.x - m_player->GetPos().x) + abs(m_pos.y - m_player->GetPos().y)))*10;
	//printfDx("%f\n", distance);

	Actor::Move();

	//変数の初期化
	m_vy = 0;
	m_vx = 0;
}

void Pisher::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other,tag, selftag);
}

void Pisher::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	//暗い所に来た
	if (tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY && m_isActive) {

	}
}
