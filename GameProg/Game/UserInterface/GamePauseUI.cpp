#include "Framework.h"

GamePauseUI::GamePauseUI(bool isVisible)
	:UserInterface(isVisible,true)
{

}

GamePauseUI::~GamePauseUI()
{

}

void GamePauseUI::Initialize(Game* gameInstance_, Scene* scene)
{
	UserInterface::Initialize(gameInstance_, scene);

	//��ʂ̕����擾
	LONG scrX = scene->screenX;
	LONG scrY = scene->screenY;

	//----------------------------------------------------------------
	//���S
	auto pauseLogo = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.8, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(pauseLogo);


	//�^�C�g���ɖ߂�摜
	auto backTitle = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 300 }, 0.1, "Picture/backTitle.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(backTitle);


	//�Q�[���ɖ߂�摜
	auto backGame = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 200 }, 0.1, "Picture/backGame.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(backGame);

	//----------------------------------------------------------------

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].x -= 180;
	}

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture(m_nowpostion[0], 0.05, "Picture/arrow.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);



}

void GamePauseUI::Update()
{
	UserInterface::Update();

	return;

	//����
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::TITLE);
		}
		else if (m_nowcursor == 1) {


		}
		else if (m_nowcursor == 2) {
			//�Q�[�����I������
			// DX���C�u�����I������
			DxLib_End();
			return;
		}
	}

	//�J�[�\���̕ύX
	if (KeyClick(KEY_INPUT_DOWN) >= 1) {
		if (m_nowcursor != 2) {
			//�J�[�\�������ɂ��炷
			m_nowcursor++;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (KeyClick(KEY_INPUT_UP) >= 1) {
		if (m_nowcursor != 0) {
			//�J�[�\������ɂ��炷
			m_nowcursor--;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}


}

void GamePauseUI::Draw()
{
	UserInterface::Draw();
}