#include "Framework.h"

TitleUI::TitleUI()
	:UserInterface(true,true)
	, m_isMenuActive(false)
{

}

TitleUI::~TitleUI()
{

}

void TitleUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);

	//��ʂ̕����擾
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	//���w�i
	auto background = std::shared_ptr<Picture>(new Picture(POINT{ 0,0},0.37 , "Picture/Tbackground.png", PIVOT::LEFTUP, SORT::SORT_UI));
	UserInterface::AddPictureInUI(background);

	//���S
	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.3, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//----------------------------------------------------------------------------------
	//�Q�[���X�^�[�g�摜
	m_startText[0] = std::shared_ptr<Picture>(new Picture(POINT{scrX / 2 ,scrY / 2 + 150}, 0.5, "Picture/PressAnyButton.png", PIVOT::CENTER, SORT::SORT_UI, true, true));
	m_nowpostion[0] = m_startText[0]->GetPos();
	UserInterface::AddPictureInUI(m_startText[0]);
	

	//���w�i
	m_backGround = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2  }, 5, "Picture/stageSelectPoint2.png", PIVOT::CENTER, SORT::SORT_UI, false, true));
	UserInterface::AddPictureInUI(m_backGround);
	m_backGround->SetAlpha(180);

	//�I����Ԃ�����摜
	m_arrow = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 + 200 ,scrY / 2 + 250 }, 0.5, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI,false,true));
	UserInterface::AddPictureInUI(m_arrow);
	m_arrow->SetAlpha(180);

	//�͂��摜
	m_startText[1] = std::shared_ptr<Picture>(new Picture(POINT{ 300, scrY / 2 + 200 }, 0.5, "Picture/Yes.png", PIVOT::CENTER, SORT::SORT_UI, false));
	m_nowpostion[1] = m_startText[1]->GetPos();
	UserInterface::AddPictureInUI(m_startText[1]);

	//�������摜
	m_startText[2] = std::shared_ptr<Picture>(new Picture(POINT{ scrX -300 ,scrY / 2 + 200 }, 0.5, "Picture/No.png", PIVOT::CENTER, SORT::SORT_UI, false));
	m_nowpostion[2] = m_startText[2]->GetPos();
	UserInterface::AddPictureInUI(m_startText[2]);

	//�Q�[���I���摜
	m_gameExitText = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.7, "Picture/GameExit.png", PIVOT::CENTER, SORT::SORT_UI, false));
	UserInterface::AddPictureInUI(m_gameExitText);
	//----------------------------------------------------------------------------------

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].y += 50;
	}

	

}

void TitleUI::Update()
{
	UserInterface::Update();

	if (KeyClick(KEY_INPUT_BACK) >= 1) {
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
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::STAGESELECT);
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
	if (KeyClick(KEY_INPUT_RIGHT) >= 1) {
		if (m_nowcursor != 2) {
			//�J�[�\�������ɂ��炷
			m_nowcursor++;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (KeyClick(KEY_INPUT_LEFT) >= 1) {
		if (m_nowcursor != 1) {
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

	m_alpha += m_add;
	
	if (m_alpha <= 0 || m_alpha >= 255) {
		m_add *= -1;
	}
	m_startText[0]->SetAlpha(m_alpha);
}