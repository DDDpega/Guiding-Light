#include "Framework.h"

LightCmp::LightCmp(Actor* actor,bool lightOn,float lightSize,bool rayUpdate,E_TAG tag)
	:Component(actor)
	,m_lightOn(lightOn)
	,m_lightSize(lightSize)
	,m_changeNow(false)
	,m_rayUpdate(rayUpdate)
	,m_framecnt(0)
	,m_rayTag(tag)
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
	m_lightPicture = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_lightSize*0.004, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::LIGHT], 0, E_PIVOT::CENTER, E_SORT::SORT_LIGHT, true));
	m_lightPicture->Initialize();
	SceneManeger::gameScene->m_lightPicture->AddLightList(this);

	//レイを追加する
	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
		m_ray[i] = shared_ptr<RayCast>(new RayCast(m_actor->GetPos(), m_rayTag));
		Game::gameInstance->GetActorMNG()->AddActor(m_ray[i]);
	}

	//ライトを切り替える
	if (m_lightOn) {
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
			//レイを飛ばす
			m_ray[i]->RayStart(m_actor->GetPos(), m_lightSize, i);
		}
	}
	else {
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
			//レイを消す
			m_ray[i]->RayStart(m_actor->GetPos(), 0, i);

		}
	}
}

void LightCmp::Update()
{
	Component::Update();

	auto actorPos = m_actor->GetPos();

	m_framecnt++;
	m_lightPicture->SetPos(actorPos);

	//毎秒レイを飛ばす
	if (m_rayUpdate &&  m_framecnt % 2 == 0 && m_lightOn) {

		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
			//レイを飛ばす
			m_ray[i]->RayStart(actorPos, m_lightSize,i);
		}

	}
}

void LightCmp::Draw()
{
	Component::Draw();
	/*for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

		if (GAME_INFO::DEBUG && m_ray[i]->m_isRayStart) {
			DrawLine(m_actor->GetPos().x, m_actor->GetPos().y, m_ray[i]->GetPos().x, m_ray[i]->GetPos().y, GetColor(100, 100, 100));
		}
	}*/
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
