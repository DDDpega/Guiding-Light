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
	
	//��񂾂�Ray���΂�
	//if (!m_rayUpdate) {

	//	//���C���΂�
	//	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

	//		//���C���΂�
	//		m_ray[i]->RayStart(m_actor->GetPos(), m_lightSize, i);
	//	}
	//}

	//���C�g��؂�ւ���
	//if (m_lightOn) {
	//	//���C�g������
	//	m_light->m_size = m_lightSize;
	//}
	//else {
	//	//���C�g������
	//	m_light->m_size = 0;
	//}
}

void LightCmp::Update()
{
	Component::Update();

	m_framecnt++;

	//���b���C���΂�
	if (m_rayUpdate &&  m_framecnt % 2 == 0) {

		//���C���΂�
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
			//���C���΂�
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

	//	//�T�C�Y��0�����������
	//	if (m_light->m_size <= 0) {
	//		m_light->m_size = 0;
	//		m_lightOn = false;
	//		m_changeNow = false;
	//	}
	//}
	//else {

	//	m_light->m_size+=0.1;

	//	//�T�C�Y�������̃T�C�Y����������
	//	if (m_light->m_size >= m_lightSize) {
	//		//���C�g������
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

	//	//�T�C�Y��0�����������
	//	if (m_light->m_size <= 0) {
	//		m_light->m_size = 0;
	//		m_lightOn = false;
	//		m_changeNow = false;
	//	}
	//}
	//else {

	//	m_light->m_size += 0.1;

	//	//�T�C�Y�������̃T�C�Y����������
	//	if (m_light->m_size >= m_lightSize) {
	//		//���C�g������
	//		m_light->m_size = m_lightSize;
	//		m_lightOn = true;
	//		m_changeNow = false;
	//	}
	//}
}
