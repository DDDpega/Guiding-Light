#include "Framework.h"

GameClearUI::GameClearUI()
	:UserInterface(true,true)
{

}

GameClearUI::~GameClearUI()
{

}

void GameClearUI::Initialize()
{
	UserInterface::Initialize();


	//��ʂ̕����擾
	float scrX = WINDOW_INFO::GAME_WIDTH;
	float scrY = WINDOW_INFO::GAME_HEIGHT;

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.4f, UI::ALLTYPE_LIST[UI::ALL_TYPE::SELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	//���S
	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 1, UI::GAME_LIST[UI::GAME_TYPE::GAMECLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//���̃X�e�[�W��
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.4f, UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	//�X�e�[�W�Z���N�g��
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.4f, UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[1] = picture->GetPos();

	for (int i = 0; i <= 1; i++) {
		m_nowpostion[i].y += 50;
	}

	m_arrow->SetPos(m_nowpostion[0]);
}

void GameClearUI::Update()
{
	UserInterface::Update();

	//����
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (m_nowcursor == 0) {
			if (SceneManeger::gameScene->GetNumStage() != 3) {
				//�X�e�[�W�ԍ���1�グ��
				SceneManeger::gameScene->SetNumStage(SceneManeger::gameScene->GetNumStage() + 1);
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
			}
		}
		else if (m_nowcursor == 1) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
		}
	}

	//�J�[�\���̕ύX
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		
		if (m_nowcursor != 1) {
			m_isSoundPlay[2] = true;
			//�J�[�\�������ɂ��炷
			m_nowcursor++;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		m_isSoundPlay[2] = true;
		if (m_nowcursor != 0) {
			m_isSoundPlay[2] = true;
			//�J�[�\������ɂ��炷
			m_nowcursor--;

			//�J�[�\���ʒu�̕ύX
			m_arrow->SetPos(m_nowpostion[m_nowcursor]);
		}
	}

}

void GameClearUI::Draw()
{
	UserInterface::Draw();


}
