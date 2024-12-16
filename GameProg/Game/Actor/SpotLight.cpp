#include "Framework.h"

SpotLight::SpotLight(Point pos)
	:Actor(pos)
	, m_moveType(E_SPOTLIGHT_MOVE::NONE)
	, m_time(0)
{
}

SpotLight::~SpotLight()
{
}

void SpotLight::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, SPOTLIGHT_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SPOT_LIGHT_OFF], 0, E_PIVOT::CENTER, E_SORT::SORT_SPOTLIGHT));
	AddComponent(m_pictureCmp);

	//画像を左向きに変える
	if (E_LINE_KIND::LEFT == m_lineKind) {
		m_pictureCmp->m_picture->m_reverse = true;
	}

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, SPOTLIGHT_INFO::COLLISION_SIZE, E_TAG::SPOT_LIGHT));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);


	//ライトコンポーネントの作成
	m_lightCmp = std::shared_ptr<LineLightCmp>(new LineLightCmp(this, false, m_lineKind,  E_TAG::SPOT_LIGHT_RAY));
	Actor::AddComponent(m_lightCmp);
}

void SpotLight::Update()
{
	Actor::Update();

	switch (m_moveType)
	{
	case E_SPOTLIGHT_MOVE::NONE:

		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SPOT_LIGHT_OFF], 0);

		if (m_firstOn) {
			//ソーラーパネルが供給されていたら
			for (auto s : SceneManeger::gameScene->m_solarpanel) {
				if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT && !s->GetIsTrigger()) {
					m_moveType = E_SPOTLIGHT_MOVE::SLOWLY_UP;
					m_time = 0;
				}
			}
		}
		else {
			//ソーラーパネルが供給されていたら
			for (auto s : SceneManeger::gameScene->m_solarpanel) {
				if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT && s->GetIsTrigger()) {
					m_moveType = E_SPOTLIGHT_MOVE::SLOWLY_UP;
					m_time = 0;
				}
			}
		}
		break;
	case E_SPOTLIGHT_MOVE::SLOWLY_UP:

		++m_time;
		m_lightCmp->m_nowLightSize += ((float)m_lightCmp->m_lightSize / 1.0f);

		//1秒経ったら
		if (m_time >= 1) {
			m_moveType = E_SPOTLIGHT_MOVE::LIGHTNING;
			m_time = 0;
			m_lightCmp->ChangeLightONOFF();
			m_lightCmp->m_lightOn = true;
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SPOT_LIGHT_ON], 0);
		}
		break;
	case E_SPOTLIGHT_MOVE::LIGHTNING:


		if (m_firstOn) {
			//供給されて
			for (auto s : SceneManeger::gameScene->m_solarpanel) {
				if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT && s->GetIsTrigger()) {
					m_moveType = E_SPOTLIGHT_MOVE::SLOWLY_DOWN;
					m_time = 0;
				}
			}
		}
		else {
			//供給されて
			for (auto s : SceneManeger::gameScene->m_solarpanel) {
				if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT && !s->GetIsTrigger()) {
					m_moveType = E_SPOTLIGHT_MOVE::SLOWLY_DOWN;
					m_time = 0;
				}
			}
		}
		break;
	case E_SPOTLIGHT_MOVE::SLOWLY_DOWN:

		++m_time;
		m_lightCmp->m_nowLightSize -= ((float)m_lightCmp->m_lightSize / 1);

		//1秒経ったら
		if (m_time >= 1) {
			m_moveType = E_SPOTLIGHT_MOVE::NONE;
			m_time = 0;
			m_lightCmp->m_nowLightSize = 0;
			m_lightCmp->ChangeLightONOFF();
		}

		break;
	}
}

void SpotLight::Draw()
{
	Actor::Draw();
}

void SpotLight::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void SpotLight::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}

void SpotLight::SetParam(E_LINE_KIND lineKind,bool isOn)
{
	m_lineKind = lineKind;
	m_firstOn = isOn;
	if (m_firstOn) m_moveType = E_SPOTLIGHT_MOVE::SLOWLY_UP;
	else m_moveType = E_SPOTLIGHT_MOVE::NONE;
}
