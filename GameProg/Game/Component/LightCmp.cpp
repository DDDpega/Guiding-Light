#include "Framework.h"

LightCmp::LightCmp(Actor* actor,bool lightOn,float lightSize)
	:Component(actor)
	,m_lightOn(lightOn)
	,m_lightSize(lightSize)
	,m_changeNow(false)
{

}

LightCmp::~LightCmp()
{
	m_light->m_isActive = false;
}

void LightCmp::Initialize()
{
	Component::Initialize();

	m_light = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_lightSize, "Picture/light.png", E_PIVOT::CENTER, E_SORT::SORT_LIGHT, true));
	SceneManeger::gameScene->m_lightPicture->AddLightList(m_light);


	
	//ライトを切り替える
	if (m_lightOn) {
		//ライトをつける
		m_light->m_size = m_lightSize;
	}
	else {
		//ライトを消す
		m_light->m_size = 0;
	}
}

void LightCmp::Update()
{
	Component::Update();

	//親アクターを追従する
	m_light->SetPos(m_actor->GetPos());

	
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

	if (m_lightOn) {

		m_light->m_size -= 0.1;

		//サイズが0を下回ったら
		if (m_light->m_size <= 0) {
			m_light->m_size = 0;
			m_lightOn = false;
			m_changeNow = false;
		}
	}
	else {

		m_light->m_size+=0.1;

		//サイズが初期のサイズを上回ったら
		if (m_light->m_size >= m_lightSize) {
			//ライトをつける
			m_light->m_size = m_lightSize;
			m_lightOn = true;
			m_changeNow = false;
		}
	}
}

void LightCmp::ChangeLightONOFF(bool lightOn)
{
	m_changeNow = true;

	if (!lightOn) {

		m_light->m_size -= 0.1;

		//サイズが0を下回ったら
		if (m_light->m_size <= 0) {
			m_light->m_size = 0;
			m_lightOn = false;
			m_changeNow = false;
		}
	}
	else {

		m_light->m_size += 0.1;

		//サイズが初期のサイズを上回ったら
		if (m_light->m_size >= m_lightSize) {
			//ライトをつける
			m_light->m_size = m_lightSize;
			m_lightOn = true;
			m_changeNow = false;
		}
	}
}
