#include "Framework.h"

FadeUI::FadeUI()
	:UserInterface(true, true)
{
}

FadeUI::~FadeUI()
{
	m_feedIn.reset();
	m_feedOut.reset();
}

void FadeUI::Initialize()
{
	UserInterface::Initialize();

	//FadeƒCƒ“
	m_feedIn = std::shared_ptr<Picture>(new Picture(Point{ -5504,0 }, 1, &UI::FEED_LIST[UI::FEED_TYPE::FEEDIN], 0, E_PIVOT::LEFTUP, E_SORT::SORT_FADE));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_feedIn);

	//Fadeout
	m_feedOut = std::shared_ptr<Picture>(new Picture(Point{ 5504,0 }, 1, &UI::FEED_LIST[UI::FEED_TYPE::FEEDOUT], 0, E_PIVOT::LEFTUP, E_SORT::SORT_FADE));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_feedOut);
}

void FadeUI::Update()
{
	UserInterface::Update();
}

void FadeUI::Draw()
{
	UserInterface::Draw();
}

void FadeUI::MoveFeed(bool IsFadeIn)
{
	if (m_csframe < 0) {
		m_csframe = 30;
	}

	if (IsFadeIn && m_csframe >= 0) {
		auto pos = m_feedIn->GetPos();
		pos.x += 100;
		m_feedIn->SetPos(pos);
	}
	else if (m_csframe >= 0) {
		auto pos = m_feedOut->GetPos();
		pos.x -= 100;
		m_feedOut->SetPos(pos);
	}
	m_csframe--;
}
