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


	
	//���C�g��؂�ւ���
	if (m_lightOn) {
		//���C�g������
		m_light->m_size = m_lightSize;
	}
	else {
		//���C�g������
		m_light->m_size = 0;
	}
}

void LightCmp::Update()
{
	Component::Update();

	//�e�A�N�^�[��Ǐ]����
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

		//�T�C�Y��0�����������
		if (m_light->m_size <= 0) {
			m_light->m_size = 0;
			m_lightOn = false;
			m_changeNow = false;
		}
	}
	else {

		m_light->m_size+=0.1;

		//�T�C�Y�������̃T�C�Y����������
		if (m_light->m_size >= m_lightSize) {
			//���C�g������
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

		//�T�C�Y��0�����������
		if (m_light->m_size <= 0) {
			m_light->m_size = 0;
			m_lightOn = false;
			m_changeNow = false;
		}
	}
	else {

		m_light->m_size += 0.1;

		//�T�C�Y�������̃T�C�Y����������
		if (m_light->m_size >= m_lightSize) {
			//���C�g������
			m_light->m_size = m_lightSize;
			m_lightOn = true;
			m_changeNow = false;
		}
	}
}
