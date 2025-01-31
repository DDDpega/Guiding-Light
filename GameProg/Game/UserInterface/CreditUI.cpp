#include "Framework.h"
#include "CreditUI.h"

CreditUI::CreditUI()
	:UserInterface(true, true)
{
}

CreditUI::~CreditUI()
{
}

void CreditUI::Initialize()
{
	UserInterface::Initialize();


	//画面の幅を取得
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	

	//黒背景
	auto background = std::shared_ptr<Picture>(new Picture(Point{ 0,0 }, 0.3, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	

	//----------------------------------------------------------------------------------
	
	//CreditTitle
	auto title = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,100 }, 0.6, &UI::CREDIT_LIST[UI::CREDIT_TYPE::CREDIT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(title);
	
	//ゲームディレクター
	m_jobText[0] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 130 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::GDIRECTOR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_jobText[0]);

	//��田
	m_nameText[0] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 55}, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::TAKADA], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[0]);

	//プランナー
	m_jobText[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2, scrY / 2+45 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::GPLANNER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_jobText[1]);

	//上村
	m_nameText[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 -260,scrY / 2 + 120 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::UEMURA], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[1]);

	//大柿
	m_nameText[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2+260 ,scrY / 2 + 120 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::OOGAKI], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[2]);

	//プログラマ
	m_jobText[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 + 230 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::GPROGRAMMER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_jobText[2]);

	//菊池
	m_nameText[3] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2-225 ,scrY / 2 + 305 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::KIKUCHI], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[3]);

	//田中
	m_nameText[4] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 +225,scrY / 2 + 305 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::TANAKA], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[4]);


	//----------------------------------------------------------------------------------

	//フェード
	m_fadeUI = shared_ptr<FadeUI>(new FadeUI());
	m_fadeUI->Initialize();

	m_isRightFade = Game::gameInstance->GetSceneMNG()->GetNowScene()->m_isRightFade;

}

void CreditUI::Update()
{
	UserInterface::Update();

	if (m_isChangeScene) {
		m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);
		if (m_csframe-- < 0) {
			//ゲームシーンへ移行フラグをオンにする
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene, m_isRightFade);

		}
		return;
	}
	m_fadeUI->MoveFeed(m_isFeedIn, m_isRightFade);


	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		m_isRightFade = true;
		m_isFeedIn = false;
		m_isChangeScene = true;
		//ゲームシーンへ移行フラグをオンにする
		m_scene = E_SCENE::STAGESELECT;
		m_fadeUI->Reset();
		
	}
}

void CreditUI::Draw()
{
	UserInterface::Draw();
}
