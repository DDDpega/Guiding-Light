#include "Framework.h"

LineLightCmp::LineLightCmp(Actor* actor, bool lightOn,E_LINE_KIND lineKind, E_TAG tag, PICTURE_TYPE pictureType)
	:Component(actor)
	, m_lightOn(lightOn)
	, m_pictureType(pictureType)
	,m_lineKind(lineKind)
{
}

LineLightCmp::~LineLightCmp()
{
}

void LineLightCmp::Initialize()
{
	Component::Initialize();

	m_lightSize = 20;


	//光の描画
	m_lightPicture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_lightSize * 0.004, &m_pictureType, 0, E_PIVOT::LEFTUP, E_SORT::SORT_LIGHT, true));
	m_lightPicture->Initialize();
	m_lightPicture->m_scaleX = 10;
	SceneManeger::gameScene->m_lightPicture->AddLineLightList(this);

	//レイを追加する
	m_ray = shared_ptr<RayCast>(new RayCast(m_actor->GetPos(), E_TAG::SPOT_LIGHT_RAY));
	Game::gameInstance->GetActorMNG()->AddActor(m_ray);
	m_ray->SetParamLine(m_lineKind);

	//光を消しておく
	m_lightOn = false;
	m_nowLightSize = 0;
	m_ray->RunLine(m_actor->GetPos(), 0);
}

void LineLightCmp::Update()
{
	Component::Update();

	//マップのポジションをプラスする
	auto actorPos = m_actor->GetPos();
	actorPos.x += Game::gameInstance->GetSceneMNG()->gameScene->m_map->getPos().x;

	m_lightPicture->SetPos(actorPos);

	//毎秒レイを飛ばす
	if (m_lightOn) {
		for (int i = 0; i < 20; i++) {
			if (m_nowLightSize <= m_lightSize && m_changeNow) {
				m_nowLightSize++;
			}
			else {
				m_changeNow = false;
			}
		}

		//レイを飛ばす
		m_ray->RunLine(actorPos, m_nowLightSize);
	}
	else {
		for (int i = 0; i < 20; i++) {
			if (m_nowLightSize != 0 && m_changeNow) {
				m_nowLightSize--;
			}
			else {
				m_changeNow = false;
			}
		}

		//レイを飛ばす
		m_ray->RunLine(actorPos, m_nowLightSize);
	}
}

void LineLightCmp::Draw()
{
	Component::Draw();
	if (GAME_INFO::DEBUG && m_ray->m_isRayStart)
		DrawBox(m_actor->GetPos().x, m_actor->GetPos().y, m_ray->linePos.x, m_ray->linePos.y, GetColor(0, 255, 0),false);

}

void LineLightCmp::ChangeLightONOFF()
{
	m_changeNow = true;
	m_lightOn = m_lightOn ? false : true;
}
