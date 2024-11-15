#include "Framework.h"

TitleVideoUI::TitleVideoUI()
	:UserInterface(true, true)
{
}

TitleVideoUI::~TitleVideoUI()
{
}

void TitleVideoUI::Initialize()
{
	UserInterface::Initialize();

	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//デモ中の画像
	m_demoText = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,100 }, 0.3, UI::TITLE_LIST[UI::TITLE_TYPE::GAMEEND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, true, true));
	UserInterface::AddPictureInUI(m_demoText);

	//ゲームスタート画像
	m_startText = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 + 300 }, 0.3, UI::TITLE_LIST[UI::TITLE_TYPE::GAMESTART], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, true, true));
	UserInterface::AddPictureInUI(m_startText);
}

void TitleVideoUI::Update()
{
	UserInterface::Update();

	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLE);
	}
}

void TitleVideoUI::Draw()
{
	UserInterface::Draw();
	m_alpha += m_add;

	if (m_alpha <= 0 || m_alpha >= 255) {
		m_add *= -1;
	}
	m_startText->SetAlpha(m_alpha);
	m_demoText->SetAlpha(m_alpha);
}
