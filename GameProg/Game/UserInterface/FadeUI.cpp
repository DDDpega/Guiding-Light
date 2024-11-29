#include "Framework.h"

FadeUI::FadeUI(bool isFirstTitle)
	:UserInterface(true, true)
	, m_isFirstTitle(isFirstTitle)
{

}

FadeUI::~FadeUI()
{
	m_feedLeft.reset();
	m_feedRight.reset();
}

void FadeUI::Initialize()
{
	UserInterface::Initialize();

	m_isInitialize = false;

	//Fadeイン
	m_feedLeft = std::shared_ptr<Picture>(new Picture(Point{ -1000,0 }, 1, &UI::FEED_LIST[UI::FEED_TYPE::FADELEFT], 0, E_PIVOT::LEFTUP, E_SORT::SORT_FADE));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_feedLeft);

	//Fadeout
	m_feedRight = std::shared_ptr<Picture>(new Picture(Point{ 0,0 }, 1, &UI::FEED_LIST[UI::FEED_TYPE::FADERIGHT], 0, E_PIVOT::LEFTUP, E_SORT::SORT_FADE));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_feedRight);

	if (m_isFirstTitle) {
		m_feedRight->SetisVisible(false);
		m_feedLeft->SetisVisible(false);
	}

}

void FadeUI::Update()
{
	UserInterface::Update();
}

void FadeUI::Draw()
{
	UserInterface::Draw();
}

void FadeUI::Reset()
{
	m_feedLeft->SetPos(Point{ -2000, 0 });
	m_feedRight->SetPos(Point{ 0, 0 });

	m_isInitialize = false;
}

void FadeUI::MoveFeed(bool IsFadeIn, bool IsRight)
{
	if (m_csframe < 0) {
		m_csframe = FADEFRAME;
	}
	if (!m_isInitialize) {
		m_isInitialize = true;
		m_feedLeft->SetPos(Point{ -2000, 0 });
		m_feedRight->SetPos(Point{ -500, 0 });
		//右にスライド(はじまり)
		if (IsFadeIn&& IsRight) {
			m_feedLeft->SetisVisible(true);
			m_feedRight->SetisVisible(false);
		}
		//左にスライド(はじまり)
		else if (IsFadeIn && !IsRight) {
			m_feedLeft->SetisVisible(false);
			m_feedRight->SetisVisible(true);
		}
		//右にスライド(終わり)
		else if (!IsFadeIn && IsRight) {
			m_feedRight->SetPos(Point{ -5504, 0 });
			m_feedLeft->SetisVisible(false);
			m_feedRight->SetisVisible(true);
		}
		//左にスライド(終わり)
		else if (!IsFadeIn && !IsRight) {


			m_feedLeft->SetPos(Point{ 1280, 0 });
			m_feedLeft->SetisVisible(true);
			m_feedRight->SetisVisible(false);
		}
	}

	if (IsRight) {
		if (IsFadeIn && m_csframe >= 0) {
			auto pos = m_feedLeft->GetPos();
			pos.x += 100;
			m_feedLeft->SetPos(pos);
		}
		else if (m_csframe >= 0) {
			auto pos = m_feedRight->GetPos();
			pos.x += 100;
			m_feedRight->SetPos(pos);
		}
	}
	else {
		if (IsFadeIn && m_csframe >= 0) {
			auto pos = m_feedRight->GetPos();
			pos.x -= 100;
			m_feedRight->SetPos(pos);
		}
		else if (m_csframe >= 0) {
			auto pos = m_feedLeft->GetPos();
			pos.x -= 100;
			m_feedLeft->SetPos(pos);
			
		}
	}
	m_csframe--;
}
