#include "Framework.h"

LightCmp::LightCmp(Actor* actor,bool lightOn,float lightSize)
	:Component(actor)
	,m_lightOn(lightOn)
	,m_lightSize(lightSize)
{

}

LightCmp::~LightCmp()
{
	m_light->m_isActive = false;
}

void LightCmp::Initialize(Game* gameInstance, Scene* scene)
{
	Component::Initialize(gameInstance, scene);

	m_light = shared_ptr<Picture>(new Picture(m_actor->GetPos(), m_lightSize, "Picture/light.png", PIVOT::CENTER, SORT::SORT_LIGHT, true));
	dynamic_cast<GameScene*>(scene)->m_lightPicture->AddLightList(m_light);
	
	//ライトを切り替える
	if (m_lightOn) {
		//ライトを消す
		m_light->SetisVisible(false);
		m_lightOn = false;
	}
	else {
		//ライトをつける
		m_light->SetisVisible(true);
		m_lightOn = true;
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
