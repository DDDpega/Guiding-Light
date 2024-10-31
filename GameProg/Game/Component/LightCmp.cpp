#include "Framework.h"

LightCmp::LightCmp(Actor* actor,bool lightOn,float lightSize,bool rayUpdate)
	:Component(actor)
	,m_lightOn(lightOn)
	,m_lightSize(lightSize)
	,m_changeNow(false)
	,m_rayUpdate(rayUpdate)
	,m_framecnt(0)
{

}

LightCmp::~LightCmp()
{
	//m_light->m_isActive = false;
}

void LightCmp::Initialize()
{
	Component::Initialize();

	SceneManeger::gameScene->m_lightPicture->AddLightList(this);

	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

		m_ray[i] = shared_ptr<RayCast>(new RayCast(m_actor->GetPos()));
		Game::gameInstance->GetActorMNG()->AddActor(m_ray[i]);
	}
	
	//一回だけRayを飛ばす
	//if (!m_rayUpdate) {

	//	//レイを飛ばす
	//	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

	//		//レイを飛ばす
	//		m_ray[i]->RayStart(m_actor->GetPos(), m_lightSize, i);
	//	}
	//}

	//ライトを切り替える
	//if (m_lightOn) {
	//	//ライトをつける
	//	m_light->m_size = m_lightSize;
	//}
	//else {
	//	//ライトを消す
	//	m_light->m_size = 0;
	//}
}

void LightCmp::Update()
{
	Component::Update();

	m_framecnt++;

	//毎秒レイを飛ばす
	if (m_rayUpdate &&  m_framecnt % 2 == 0) {

		//レイを飛ばす
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
			//レイを飛ばす
			m_ray[i]->RayStart(m_actor->GetPos(), m_lightSize,i);
		}
	}

	if (m_changeNow) {
		ChangeLightONOFF();
	}
}

void LightCmp::Draw()
{
	Component::Draw();
}

void LightCmp::ChangeLightONOFF()
{
	m_changeNow = true;

	//if (m_lightOn) {

	//	m_light->m_size -= 0.1;

	//	//サイズが0を下回ったら
	//	if (m_light->m_size <= 0) {
	//		m_light->m_size = 0;
	//		m_lightOn = false;
	//		m_changeNow = false;
	//	}
	//}
	//else {

	//	m_light->m_size+=0.1;

	//	//サイズが初期のサイズを上回ったら
	//	if (m_light->m_size >= m_lightSize) {
	//		//ライトをつける
	//		m_light->m_size = m_lightSize;
	//		m_lightOn = true;
	//		m_changeNow = false;
	//	}
	//}
}

void LightCmp::ChangeLightONOFF(bool lightOn)
{
	m_changeNow = true;

	//if (!lightOn) {

	//	m_light->m_size -= 0.1;

	//	//サイズが0を下回ったら
	//	if (m_light->m_size <= 0) {
	//		m_light->m_size = 0;
	//		m_lightOn = false;
	//		m_changeNow = false;
	//	}
	//}
	//else {

	//	m_light->m_size += 0.1;

	//	//サイズが初期のサイズを上回ったら
	//	if (m_light->m_size >= m_lightSize) {
	//		//ライトをつける
	//		m_light->m_size = m_lightSize;
	//		m_lightOn = true;
	//		m_changeNow = false;
	//	}
	//}
}
