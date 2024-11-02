#include "Framework.h"

GamePauseUI::GamePauseUI(bool isVisible)
	:UserInterface(isVisible,true)
{

}

GamePauseUI::~GamePauseUI()
{

}

void GamePauseUI::Initialize()
{
	UserInterface::Initialize();

	//��ʂ̕����擾
	LONG scrX = WINDOW_INFO::GAME_WIDTH;
	LONG scrY = WINDOW_INFO::GAME_HEIGHT;

	//----------------------------------------------------------------
	//���S

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	auto pauseLogo = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 200 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(pauseLogo);

	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 , 300 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2,450 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2,600 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
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

	if (!GetisVisible()) {
		return;
	}

	//����
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			SceneManeger::gameScene->m_pauseUI->SetisVisible(false);
			SceneManeger::gameScene->m_isPause = false;
			m_arrow->SetPos(m_nowpostion[0]);
		}
		else if (m_nowcursor == 1) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
		}
		else if (m_nowcursor == 2) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
		}
	}

	//�J�[�\���̕ύX
		//�J�[�\���̕ύX
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		if (m_nowcursor != 2) {
			//�J�[�\�������ɂ��炷
			m_nowcursor++;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
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