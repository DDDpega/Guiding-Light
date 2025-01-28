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

	auto isTrigger = false;

	for (auto s : SceneManeger::gameScene->m_solarpanel) {
		if (s->GetParam() == E_SOLARPANEL_KIND::SPOT_LIGHT) {
			isTrigger = s->GetIsTrigger();
			if (isTrigger) {
				break;
			}
		}
	}

	if (isTrigger && m_firstOn && m_lightCmp->m_lightOn) {
		m_lightCmp->m_nowLightSize -= (float)m_lightCmp->m_lightSize;
		m_lightCmp->m_nowLightSize = 0;
		m_lightCmp->ChangeLightONOFF();
		m_lightCmp->m_lightOn = false;
	}
	else if (isTrigger && !m_firstOn && !m_lightCmp->m_lightOn) {
		m_lightCmp->m_nowLightSize += (float)m_lightCmp->m_lightSize;
		m_lightCmp->ChangeLightONOFF();
		m_lightCmp->m_lightOn = true;
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SPOT_LIGHT_ON], 0);
	}
	else if (!isTrigger && m_firstOn && !m_lightCmp->m_lightOn) {
		m_lightCmp->m_nowLightSize += (float)m_lightCmp->m_lightSize;
		m_lightCmp->ChangeLightONOFF();
		m_lightCmp->m_lightOn = true;
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SPOT_LIGHT_ON], 0);

	}
	else if (!isTrigger && !m_firstOn && m_lightCmp->m_lightOn) {
		m_lightCmp->m_nowLightSize -= (float)m_lightCmp->m_lightSize;
		m_lightCmp->m_nowLightSize = 0;
		m_lightCmp->ChangeLightONOFF();
		m_lightCmp->m_lightOn = false;
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
