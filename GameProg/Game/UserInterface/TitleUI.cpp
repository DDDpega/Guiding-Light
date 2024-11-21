#include "Framework.h"

TitleUI::TitleUI()
	:UserInterface(true,true)
	, m_isMenuActive(false)
{

}

TitleUI::~TitleUI()
{

}

void TitleUI::Initialize()
{
	UserInterface::Initialize();

	m_isVideo = false;
	m_isVideoPlay = false;

	//��ʂ̕����擾
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//���w�i
	auto background = std::shared_ptr<Picture>(new Picture(Point{ 0,0},0.37 , &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND],0, E_PIVOT::LEFTUP, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	//���S
	auto picture = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 100 }, 1, &UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//----------------------------------------------------------------------------------
	//�Q�[���X�^�[�g�摜
	m_startText[0] = std::shared_ptr<Picture>(new Picture(Point{scrX / 2 ,scrY / 2 + 150}, 0.3, &UI::TITLE_LIST[UI::TITLE_TYPE::GAMESTART], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, true, true));
	m_nowpostion[0] = m_startText[0]->GetPos();
	UserInterface::AddPictureInUI(m_startText[0]);
	

	//���w�i
	m_backGround = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2  }, 5, &UI::ALLTYPE_LIST[UI::ALL_TYPE::BACKGROUND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//�I����Ԃ�����摜
	m_arrow = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 + 200 ,scrY / 2 + 250 }, 0.5, &UI::ALLTYPE_LIST[UI::ALL_TYPE::SELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI,false,true));
	UserInterface::AddPictureInUI(m_arrow);
	m_arrow->SetAlpha(180);

	//�͂��摜
	m_startText[1] = std::shared_ptr<Picture>(new Picture(Point{ 300, scrY / 2 + 200 }, 0.5, &UI::TITLE_LIST[UI::TITLE_TYPE::YES], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	m_nowpostion[1] = m_startText[1]->GetPos();
	UserInterface::AddPictureInUI(m_startText[1]);

	//�������摜
	m_startText[2] = std::shared_ptr<Picture>(new Picture(Point{ scrX -300 ,scrY / 2 + 200 }, 0.5, &UI::TITLE_LIST[UI::TITLE_TYPE::NO], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	m_nowpostion[2] = m_startText[2]->GetPos();
	UserInterface::AddPictureInUI(m_startText[2]);

	//�Q�[���I���摜
	m_gameExitText = std::shared_ptr<Picture>(new Picture(Point{ scrX / 2 ,scrY / 2 - 100 }, 0.7, &UI::TITLE_LIST[UI::TITLE_TYPE::GAMEEND], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_gameExitText);
	//----------------------------------------------------------------------------------

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].y += 50;
	}

	//�t�H���g�̕`��
	m_fontHandle = CreateFontToHandle("MS �S�V�b�N", 20, 1);
}

void TitleUI::Update()
{
	UserInterface::Update();
	if (Game::gameInstance->GetInputMNG()->Click(L"CANCEL")) {
		m_isSoundPlay[1] = true;
		m_isMenuActive = true;
		m_nowcursor = 2;
		for (int i = 1; i < 3; i++) {
			m_startText[i]->SetisVisible(true);
		}
		//�J�[�\���ʒu�̕ύX
		m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		m_gameExitText->SetisVisible(true);
		m_arrow->SetisVisible(true);
		m_backGround->SetisVisible(true);
	}

	//����
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
			//���ɖ߂�
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else if (m_nowcursor == 1) {
			//�Q�[�����I������
			// DX���C�u�����I������
			DxLib_End();
			return;

		}
		else if (m_nowcursor == 2) {
			m_isMenuActive = false;
			m_nowcursor = 0;
			for (int i = 1; i < 3; i++) {
				m_startText[i]->SetisVisible(false);
			}
			m_gameExitText->SetisVisible(false);
			m_arrow->SetisVisible(false);
			m_backGround->SetisVisible(false);
		}
	}

	//�J�[�\���̕ύX
	if (Game::gameInstance->GetInputMNG()->Click(L"RIGHT")&& m_isMenuActive) {
		if (m_nowcursor != 2) {
			m_isSoundPlay[2] = true;
			//�J�[�\�������ɂ��炷
			m_nowcursor++;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"LEFT") && m_isMenuActive) {
		if (m_nowcursor != 1) {
			m_isSoundPlay[2] = true;
			//�J�[�\������ɂ��炷
			m_nowcursor--;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
}


void TitleUI::Draw()
{
	UserInterface::Draw();

	//�ʏ�ł��W���ł�؂�ւ���
	Point pos = Point{ WINDOW_INFO::GAME_WIDTH - 70,WINDOW_INFO::GAME_HEIGHT -70};
	if (Game::gameInstance->GetStatus()->GAME_NORMAL) {
		DrawFormatStringFToHandle(pos.x, pos.y, GetColor(255, 255, 255), m_fontHandle, "�ʏ��");
	}
	else {
		DrawFormatStringFToHandle(pos.x, pos.y, GetColor(255, 255, 255), m_fontHandle, "�W����");
	}

	m_startText[0]->m_alpha += m_add;
	
	if (m_startText[0]->m_alpha <= 0 || m_startText[0]->m_alpha >= 255) {
		m_add *= -1;
	}
	m_startText[0]->SetAlpha(m_startText[0]->m_alpha);
}