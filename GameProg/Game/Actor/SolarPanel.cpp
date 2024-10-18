#include "Framework.h"

SolarPanel::SolarPanel(POINT pos)
	:Actor(pos, 2.5, "Picture/SolarPanel.png", PIVOT::LEFTUP)
	, m_isTrigger(false)
{
}

SolarPanel::~SolarPanel()
{
}

void SolarPanel::Initialize(Game* gameInstance_, Scene* scene)
{
	Actor::Initialize(gameInstance_,scene);

	LONG x = (m_pictureSizeX * m_size) / 2;
	LONG y = (m_pictureSizeY * m_size) / 2;

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { x,y }, { 40,40 }, TAG::SOLARPANEL));
	Actor::AddComponent(collision, scene);
	gameInstance_->GetCollisionMNG()->AddBOXCollisionList(collision);

	//‰½•bŒø‰ÊŽžŠÔ‚ª‚ ‚é‚©
	m_maxTime = gameInstance_->GetStatus()->FIGURE_MAXTIME;
}

void SolarPanel::Update()
{
	Actor::Update();
	if (m_keepTime > 0) {
		//‹Ÿ‹‹’†‚È‚çŒ¸‚ç‚³‚È‚¢
		if (!m_shareNow) {
			m_keepTime--;
		}
	}
	else {
		m_isTrigger = false;
	}
}

void SolarPanel::HitCollision(Actor* other, TAG tag, TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == TAG::PLAYER_LIGHT && m_sceneptr->GetPlayer()->GetLightOn() &&
		m_keepTime < m_maxTime) {
		m_keepTime++;
		m_shareNow = true;
		m_isTrigger = true;
	}
}

void SolarPanel::NoHitCollision(Actor* other, TAG tag)
{
	if (tag == TAG::PLAYER_LIGHT && !m_sceneptr->GetPlayer()->GetLightOn() ) {
		m_shareNow = false;
	}
}

bool SolarPanel::GetIsTrigger()
{
	return m_isTrigger;
}
