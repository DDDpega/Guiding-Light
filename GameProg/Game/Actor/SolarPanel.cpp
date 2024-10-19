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
	m_maxTime = gameInstance_->GetStatus()->SOLARPANELBLOCK_MAXTIME;
}

void SolarPanel::Update()
{
	Actor::Update();

	//‹Ÿ‹‹ŽžŠÔ‚ªŒo‰ß‚µ‚½‚ç
	if (m_keepTime >= m_maxTime) {
		m_isTrigger = true;
	}

}

void SolarPanel::HitCollision(Actor* other, TAG tag, TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == TAG::PLAYER_LIGHT && m_sceneptr->GetPlayer()->GetLightOn() &&
		m_keepTime < m_maxTime) {
		m_keepTime++;
	}
}

void SolarPanel::NoHitCollision(Actor* other, TAG tag)
{


}

bool SolarPanel::GetIsTrigger()
{
	return m_isTrigger;
}
