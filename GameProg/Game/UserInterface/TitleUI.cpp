#include "Framework.h"

TitleUI::TitleUI()
	:UserInterface(true,true)

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

	//���S
	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 - 100 }, 0.8, "Picture/logo.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(picture);

	//----------------------------------------------------------------------------------
	//�Q�[���X�^�[�g�摜
	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 100 }, 0.1, "Picture/gamestart.png", PIVOT::CENTER, SORT::SORT_UI));
	m_nowpostion[0] = picture->GetPos();
	UserInterface::AddPictureInUI(picture);

	//�I�v�V�����摜
	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 , scrY / 2 + 200 }, 0.1, "Picture/option.png", PIVOT::CENTER, SORT::SORT_UI));
	m_nowpostion[1] = picture->GetPos();
	UserInterface::AddPictureInUI(picture);

	//�Q�[���G���h�摜
	picture = std::shared_ptr<Picture>(new Picture(POINT{ scrX / 2 ,scrY / 2 + 300 }, 0.1, "Picture/gameend.png", PIVOT::CENTER, SORT::SORT_UI));
	m_nowpostion[2] = picture->GetPos();
	UserInterface::AddPictureInUI(picture);
	//----------------------------------------------------------------------------------

	//�ʒu�̒���
	for (int i = 0; i <= 2; i++) {
		m_nowpostion[i].x -= 180;
	}

	//���
	m_arrow = std::shared_ptr<Picture>(new Picture(m_nowpostion[0], 0.05, "Picture/arrow.png", PIVOT::CENTER, SORT::SORT_UI));
	UserInterface::AddPictureInUI(m_arrow);

}

void TitleUI::Update()
{
	UserInterface::Update();

	//����
	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs�t���O���I���ɂ���
			m_gameInstance->GetSceneMNG()->ChangeSceneFlag(E_Scene::GAME);
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

void TitleUI::Draw()
{
	UserInterface::Draw();
}