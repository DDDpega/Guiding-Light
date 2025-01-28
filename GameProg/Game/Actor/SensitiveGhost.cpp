#include "Framework.h"

SensitiveGhost::SensitiveGhost(Point pos)
	:Actor(pos)
	, m_frame(0)

{
}

SensitiveGhost::~SensitiveGhost()
{
}

void SensitiveGhost::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, SENSITIVE_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_SENSITIVE], 0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, SENSITIVE_INFO::COLLISION_SIZE, E_TAG::GHOST));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//暗闇中に見える画像の生成
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_SENSITIVE_EYE], 0));
	Actor::AddComponent(m_darkPictureCmp);
}

void SensitiveGhost::Update()
{
	Actor::Update();

	//画像の変更
	if (++m_frame % 30 == 0) {
		m_pictureNumber = m_pictureNumber == 0 ? 1 : 0;
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_SENSITIVE], m_pictureNumber);
		m_darkPictureCmp->m_darkPicture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_SENSITIVE_EYE], m_pictureNumber);
	}

	m_target = nullptr;
	if (!SceneManeger::gameScene->m_onSoundCmp.empty()) {
		m_target=SceneManeger::gameScene->m_onSoundCmp[0]->GetActor();
	}
	if (m_target == nullptr) {
		return;
	}

	//移動の速度決定
	float radial = atan2f((m_target->GetPos().y - m_pos.y), (m_target->GetPos().x - m_pos.x));
	m_vx = cos(radial) * Game::gameInstance->GetStatus()->SENSITIVE_GHOST_SPEED;
	m_vy = sin(radial) * Game::gameInstance->GetStatus()->SENSITIVE_GHOST_SPEED;

	//左右反転
	if ((int)m_pos.x != (int)m_target->GetPos().x && (int)m_pos.y != (int)m_target->GetPos().y) {
		m_pictureCmp->m_picture->m_reverse = (m_vx > 0);
		m_darkPictureCmp->m_darkPicture->m_reverse = (m_vx > 0);
	}

	Actor::Move();

	//変数の初期化
	m_vy = 0;
	m_vx = 0;
	
}

void SensitiveGhost::Draw()
{
	Actor::Draw();
}

void SensitiveGhost::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if ((tag == E_TAG::SPOT_LIGHT_RAY || tag == E_TAG::RAY || tag == E_TAG::PLAYER_RAY || tag == E_TAG::FIGURERAY || tag == E_TAG::GOALLIGHTRAY) && m_isActive) {
		m_darkPictureCmp->m_darkPicture->SetisVisible(false);
	}
}

void SensitiveGhost::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
