#include "Framework.h"

BatteryPictureCmp::BatteryPictureCmp(Actor* actor)
	:Component(actor)
{
}

BatteryPictureCmp::~BatteryPictureCmp()
{
}

void BatteryPictureCmp::Initialize()
{
	Component::Initialize();

}

void BatteryPictureCmp::Update()
{
	Component::Update();

	auto pos = m_actor->GetPos();
	pos.y += 40;
	pos.x += 40;
	m_batteryPicture->SetPos(pos);
}

void BatteryPictureCmp::Draw()
{
	Component::Draw();
}

void BatteryPictureCmp::SetParam(int maxFrame, int start)
{
	m_maxFrame = maxFrame;
	m_pictureNumber = start;

	up = start == 0;

	auto pos = m_actor->GetPos();
	if (m_batteryPicture!=nullptr && m_batteryPicture->m_isActive)m_batteryPicture->m_isActive = false;
	m_batteryPicture = shared_ptr<Picture>(new Picture(Point{ pos.x,pos.y - 60.0f }, 2.5f, &UI::GAME_LIST[UI::GAME_TYPE::BATTERY], start, E_PIVOT::CENTER, E_SORT::SORT_BATTERY));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_batteryPicture);	
}

void BatteryPictureCmp::NowFrame(int frame)
{
	auto pixel = m_maxFrame / 4;
	m_nowFrame = frame;
	for (int i = 0; i <= 3; i++) {
		if (m_nowFrame <= (pixel * i)) {
			m_pictureNumber = i;
			m_batteryPicture->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::BATTERY], m_pictureNumber);
			return;
		}
	}

	m_batteryPicture->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::BATTERY], m_pictureNumber);
}
