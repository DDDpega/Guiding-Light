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

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.5, "Picture/stageSelectPoint1.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	auto pauseLogo = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 200 }, 0.5, "Picture/pause.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(pauseLogo);

	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 , 300 }, 0.5, "Picture/UI_61.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2,450 }, 0.5, "Picture/UI_63.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2,600 }, 0.5, "Picture/UI_55.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[2] = picture->GetPos();

	//----------------------------------------------------------------

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].y += 50;
	}
	m_arrow->SetPos(m_nowpostion[0]);

}

void GamePauseUI::Update()
{
	UserInterface::Update();

	//����
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			static_cast<GameScene*>(m_sceneptr)->m_pauseUI->SetisVisible(false);
			static_cast<GameScene*>(m_sceneptr)->m_isPause = false;
			m_arrow->SetPos(m_nowpostion[0]);
		}
		else if (m_nowcursor == 1) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
		}
		else if (m_nowcursor == 2) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::STAGESELECT);
		}
	}

	//�J�[�\���̕ύX
		//�J�[�\���̕ύX
	if (KeyClick(KEY_INPUT_S) >= 1) {
		if (m_nowcursor != 2) {
			//�J�[�\�������ɂ��炷
			m_nowcursor++;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (KeyClick(KEY_INPUT_W) >= 1) {
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