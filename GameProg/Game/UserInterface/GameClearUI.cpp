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
	LONG scrX = WINDOW_INFO::GAME_WIDTH;
	LONG scrY = WINDOW_INFO::GAME_HEIGHT;

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture({0,0}, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

	auto picture = shared_ptr<Picture>(new Picture({ scrX / 2,200 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	picture = shared_ptr<Picture>(new Picture({ scrX / 2,400 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);
	m_nowpostion[0] = picture->GetPos();

	picture = shared_ptr<Picture>(new Picture({ scrX / 2,600 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::TITLE], E_PIVOT::CENTER, E_SORT::SORT_UI));
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

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::GAME);
		}
		else if (m_nowcursor == 1) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::STAGESELECT);
		}
	}

	//�J�[�\���̕ύX
	if (Game::gameInstance->GetInputMNG()->Click(L"DOWN")) {
		if (m_nowcursor != 1) {
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

void GameClearUI::Draw()
{
	UserInterface::Draw();


}
