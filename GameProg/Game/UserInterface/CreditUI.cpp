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


	//��ʂ̕����擾
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	

	//���w�i
	auto background = std::shared_ptr<Picture>(new Picture(Point{ 0,0 }, 0.3, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	

	//----------------------------------------------------------------------------------
	
	//CreditTitle
	auto title = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,100 }, 0.6, &UI::CREDIT_LIST[UI::CREDIT_TYPE::CREDIT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(title);
	
	//�Q�[���f�B���N�^�[
	m_jobText[0] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 130 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::GDIRECTOR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_jobText[0]);

	//���c
	m_nameText[0] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 55}, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::TAKADA], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[0]);

	//�v�����i�[
	m_jobText[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2, scrY / 2+45 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::GPLANNER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_jobText[1]);

	//�㑺
	m_nameText[1] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 -160,scrY / 2 + 120 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::UEMURA], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[1]);

	//��`
	m_nameText[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2+160 ,scrY / 2 + 120 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::OOGAKI], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[2]);

	//�v���O���}
	m_jobText[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 + 230 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::GPROGRAMMER], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_jobText[2]);

	//�e�r
	m_nameText[3] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2-125 ,scrY / 2 + 305 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::KIKUCHI], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[3]);

	//�c��
	m_nameText[4] = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 +125,scrY / 2 + 305 }, 0.3, &UI::CREDIT_LIST[UI::CREDIT_TYPE::TANAKA], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_nameText[4]);


	//----------------------------------------------------------------------------------
}

void CreditUI::Update()
{
	UserInterface::Update();
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
	}
}

void CreditUI::Draw()
{
	UserInterface::Draw();
}
