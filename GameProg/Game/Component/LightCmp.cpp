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
	m_lightPicture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_lightSize*0.004, m_pictureType, 0, E_PIVOT::CENTER, E_SORT::SORT_LIGHT, true));
	m_lightPicture->Initialize();
	SceneManeger::gameScene->m_lightPicture->AddLightList(this);

	//レイを追加する
	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
		m_ray[i] = shared_ptr<RayCast>(new RayCast(m_actor->GetPos(), m_rayTag));
		Game::gameInstance->GetActorMNG()->AddActor(m_ray[i]);
	}

	ChangeLightONOFF(false);
}

void LightCmp::Update()
{
	Component::Update();

	//マップのポジションをプラスする
	auto actorPos = m_actor->GetPos();
	actorPos.x += Game::gameInstance->GetSceneMNG()->gameScene->m_map->getPos().x;

	//auto actorPos = m_actor->GetPos();

	

	m_framecnt++;
	m_lightPicture->SetPos(actorPos);

	if (m_actor->m_darkPictureCmp != nullptr) {
		m_actor->m_darkPictureCmp->m_darkPicture->SetisVisible(true);
	}

	//毎秒レイを飛ばす
	if (m_lightOn) {

		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
			//レイを飛ばす
			m_ray[i]->RayStart( actorPos, m_lightSize, i);
		}
	}
}

void LightCmp::Draw()
{
	Component::Draw();
	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

		if (GAME_INFO::DEBUG && m_ray[i]->m_isRayStart) {
			DrawLine(m_actor->GetPos().x, m_actor->GetPos().y, m_ray[i]->GetPos().x, m_ray[i]->GetPos().y, GetColor(100, 100, 100));
		}
	}
}

void LightCmp::ChangeLightONOFF()
{
	if (m_lightOn) {

		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			//レイを飛ばす
			m_ray[i]->RayStart(m_actor->GetPos(), 0, i);
		}
		m_lightOn = false;
	}
	else {

		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			//レイを飛ばす
			m_ray[i]->RayStart(m_actor->GetPos(), m_lightSize, i);
		}
		m_lightOn = true;

	}
}

void LightCmp::ChangeLightONOFF(bool lightOn)
{
	m_changeNow = true;

	if (!lightOn) {

		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			//レイを飛ばす
			m_ray[i]->RayStart(m_actor->GetPos(), 0, i);
		}
		m_lightOn = false;
	}
	else {
		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			//レイを飛ばす
			m_ray[i]->RayStart(m_actor->GetPos(), m_lightSize, i);
		}
		m_lightOn = true;

	}

	m_changeNow = false;
}
