#include "Framework.h"

SolarPanel::SolarPanel(POINT pos)
	:Actor(pos)
	, m_isTrigger(false)
{
}

SolarPanel::~SolarPanel()
{
}

void SolarPanel::Initialize()
{
	Actor::Initialize();

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, SOLARPANEL_INFO::SIZE, "Picture/SolarPanel.png", E_PIVOT::LEFTUP, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//�摜�T�C�Y
	LONG x = (m_pictureCmp->m_picture ->m_pictureSizeX * m_pictureCmp->m_picture->m_size) / 2;
	LONG y = (m_pictureCmp->m_picture->m_pictureSizeY * m_pictureCmp->m_picture->m_size) / 2;

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { x,y }, SOLARPANEL_INFO::COLLISION_SIZE, E_TAG::SOLARPANEL));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//���b���ʎ��Ԃ����邩
	m_maxTime = Game::gameInstance->GetStatus()->SOLARPANELBLOCK_MAXTIME;
}

void SolarPanel::Update()
{
	Actor::Update();

	//�������Ԃ��o�߂�����
	if (m_keepTime >= m_maxTime) {
		m_isTrigger = true;
	}

}

void SolarPanel::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::RAY && SceneManeger::gameScene->GetPlayer()->GetLightOn() &&
		m_keepTime < m_maxTime) {
		m_keepTime++;
	}
}

void SolarPanel::NoHitCollision(Actor* other, E_TAG tag)
{


}

bool SolarPanel::GetIsTrigger()
{
	return m_isTrigger;
}