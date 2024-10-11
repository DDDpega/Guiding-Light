#include "Framework.h"


TitleScene::TitleScene(Game* gameInstance)
	:Scene(gameInstance,"�^�C�g���V�[��")
	, m_nowcursor(0)
{

}

TitleScene::~TitleScene()
{
	Scene::~Scene();
}

void TitleScene::Initialize()
{
	Scene::Initialize();

	//���S
	auto picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 - 100 }, 0.8, "Picture/logo.png",PIVOT::CENTER,SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);

	
	//----------------------------------------------------------------------------------
	//�Q�[���X�^�[�g�摜
	picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 100 }, 0.1, "Picture/gamestart.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);
	m_nowpostion[0] = picture->GetPos();

	//�I�v�V�����摜
	picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 200 }, 0.1, "Picture/option.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);
	m_nowpostion[1] = picture->GetPos();

	//�Q�[���G���h�摜
	picture = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 300 }, 0.1, "Picture/gameend.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(picture, this);
	m_nowpostion[2] = picture->GetPos();
	//----------------------------------------------------------------------------------
	
	//�ʒu�̒���
	for (int i = 0; i <= 2; i++){
		m_nowpostion[i].x -= 180;
	}
	//���
	m_arrow = std::shared_ptr<Picture>(new Picture(m_nowpostion[0], 0.05, "Picture/arrow.png", PIVOT::CENTER, SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(m_arrow, this);

}

void TitleScene::Update()
{
	Scene::Update();

	if (KeyClick(KEY_INPUT_SPACE) >= 1) {

		if (m_nowcursor == 0) {
			//�Q�[���V�[���ֈڍs
			m_gameInstance->GetSceneMNG()->ChangeScene(E_Scene::GAME);
		}
		else if (m_nowcursor == 1) {


		}
		else if (m_nowcursor == 2) {
			//�Q�[�����I������
			// DX���C�u�����I������
			DxLib_End();

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

void TitleScene::Draw()
{
	Scene::Draw();
}