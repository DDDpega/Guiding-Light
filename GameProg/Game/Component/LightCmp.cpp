#include "Framework.h"

LightCmp::LightCmp(Actor* actor,bool lightOn,float lightSize,E_TAG tag,PICTURE_TYPE pictureType)
	:Component(actor)
	,m_lightOn(lightOn)
	,m_lightSize(lightSize)
	,m_changeNow(false)
	,m_framecnt(0)
	,m_rayTag(tag)
	,m_pictureType(pictureType)

{

}

LightCmp::~LightCmp()
{
	//m_light->m_isActive = false;
}

void LightCmp::Initialize()
{
	Component::Initialize();


	//光の描画
	m_lightPicture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_lightSize*0.004, &m_pictureType, 0, E_PIVOT::CENTER, E_SORT::SORT_LIGHT, true));
	m_lightPicture->Initialize();
	SceneManeger::gameScene->m_lightPicture->AddLightList(this);

	//レイを追加する
	m_ray = shared_ptr<RayCast>(new RayCast(m_actor->GetPos(), m_rayTag));
	Game::gameInstance->GetActorMNG()->AddActor(m_ray);

	//光を消しておく
	m_lightOn = false;
	m_nowLightSize = 0;
	m_ray->RunCircle(m_actor->GetPos(), 0);

}

void LightCmp::Update()
{
	Component::Update();

	//マップのポジションをプラスする
	auto actorPos = m_actor->GetPos();
	actorPos.x += Game::gameInstance->GetSceneMNG()->gameScene->m_map->getPos().x;

	m_framecnt++;
	m_lightPicture->SetPos(actorPos);

	//暗い時に見える画像を全て見えるようにする
	/*if (m_actor->m_darkPictureCmp != nullptr) {
		m_actor->m_darkPictureCmp->m_darkPicture->SetisVisible(true);
	}*/

	//毎秒レイを飛ばす
	if (m_lightOn) {
		for (int i = 0; i < 20; i++) {
			if (m_nowLightSize <= m_lightSize && m_changeNow) {
				m_nowLightSize ++;
			}
			else {
				m_changeNow = false;
			}
		}

		
		//レイを飛ばす
		m_ray->RunCircle( actorPos, m_nowLightSize);
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
		m_ray->RunCircle(actorPos, m_nowLightSize);
	}
}

void LightCmp::Draw()
{
	Component::Draw();

	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

		if (GAME_INFO::DEBUG && m_ray->m_isRayStart) {
			DrawLine(m_actor->GetPos().x, m_actor->GetPos().y, m_ray->rayPos[i].x, m_ray->rayPos[i].y, GetColor(100, 100, 100));
	
		}
	}
}

void LightCmp::ChangeLightONOFF()
{
	m_changeNow = true;
	m_lightOn = m_lightOn ? false : true;
}
