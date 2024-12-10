#include "Framework.h"

Boombox::Boombox(Point pos)
	:Actor(pos)
	,m_shareNow(false)
{
}

Boombox::~Boombox()
{
}

void Boombox::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, BOOMBOX_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::BOOM_BOX], 0, E_PIVOT::CENTER, E_SORT::SORT_SPOTLIGHT));
	AddComponent(m_pictureCmp);


	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, BOOMBOX_INFO::COLLISION_SIZE, E_TAG::SPOT_LIGHT));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//サウンドコンポーネント
	m_sounndCmp = shared_ptr<OnSoundCmp>(new OnSoundCmp(this));
	Actor::AddComponent(m_sounndCmp);
}

void Boombox::Update()
{
	Actor::Update();

	switch (m_boomBoxKind)
	{
	case E_BOOMBOX_MOVE::NONE:

		//ソーラーパネルが供給されていたら
		for (auto s : SceneManeger::gameScene->m_solarpanel) {
			if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT && s->GetIsTrigger()) {
				m_boomBoxKind = E_BOOMBOX_MOVE::ON_SOUND;
				m_sounndCmp->OnSound();
			}
		}
		break;
	case E_BOOMBOX_MOVE::SLOWLY_UP:
		break;
	case E_BOOMBOX_MOVE::ON_SOUND:
		//ソーラーパネルが供給されていなかったら
		for (auto s : SceneManeger::gameScene->m_solarpanel) {
			if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT && !s->GetIsTrigger()) {
				m_boomBoxKind = E_BOOMBOX_MOVE::NONE;
				m_sounndCmp->OffSound();
			}
		}
		break;
	case E_BOOMBOX_MOVE::SLOWLY_DOWN:
		break;
	}
}

void Boombox::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if ((tag == E_TAG::PLAYER_RAY && SceneManeger::gameScene->GetPlayer()->GetLightOn()) || tag == E_TAG::FIGURERAY) {
		m_shareNow = true;
	}
}

void Boombox::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
