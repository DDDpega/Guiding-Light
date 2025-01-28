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

	//���S
	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 1, &UI::GAME_LIST[UI::GAME_TYPE::GAMECLEAR], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//���̃X�e�[�W��
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	//�X�e�[�W�Z���N�g��
	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.4f, &UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0, E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_picture.push_back(picture);

	ChangeImage(0);
	SaveDataControl::saveData->SaveClearData(SceneManeger::gameScene->GetNumStage(), true);
}

void GameClearUI::Update()
{
	UserInterface::Update();

	if (m_isChangeScene) {
		if (m_csframe-- < 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(m_scene);

		}
		return;
	}

	//����
	if (Game::gameInstance->GetInputMNG()->Click(L"OK")) {
		m_isSoundPlay[0] = true;
		if (m_nowcursor == 0) {
			if (SceneManeger::gameScene->GetNumStage() != 10) {
				//�X�e�[�W�ԍ���1�グ��
				SceneManeger::gameScene->SetNumStage(SceneManeger::gameScene->GetNumStage() + 1);
				//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
				m_isRightFade = false;
				m_isFeedIn = false;
				m_isChangeScene = true;
				m_scene = E_SCENE::GAME;
			}
		}
		else if (m_nowcursor == 1) {
			//�S�ẴT�E���h���~�߂�
			Game::gameInstance->GetSoundMNG()->ClearSound();
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_isFeedIn = false;
			m_isChangeScene = true;
			m_scene = E_SCENE::STAGESELECT;
		}
	}

	//�J�[�\���̕ύX
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		
		if (m_nowcursor != 1) {
			m_isSoundPlay[2] = true;
			//�J�[�\�������ɂ��炷
			ChangeImage(++m_nowcursor);
		}
	}
	if (Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		m_isSoundPlay[2] = true;
		if (m_nowcursor != 0) {
			m_isSoundPlay[2] = true;
			//�J�[�\������ɂ��炷
			ChangeImage(--m_nowcursor);
		}
	}

}

void GameClearUI::Draw()
{
	UserInterface::Draw();


}

void GameClearUI::ChangeImage(int nowcursor)
{
	if (nowcursor == 0) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 1);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 0);
	}
	else if (nowcursor == 1) {
		m_picture[0]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::NEXT_STAGE], 0);
		m_picture[1]->ChangePicture(&UI::GAME_LIST[UI::GAME_TYPE::STAGESELECT], 1);
	}
}

