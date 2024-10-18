#include "Framework.h"


SceneManeger::SceneManeger(Game* gameInstance)
	:m_gameInstance(gameInstance)
{

}

SceneManeger::~SceneManeger()
{

}

void SceneManeger::Initialize()
{
	//�ϐ��̏�����
	gameScene = new GameScene(m_gameInstance);
	titleScene = new TitleScene(m_gameInstance);
	ssScene = new StageSelectScene(m_gameInstance);

	//�������Q�[���V�[���ɕύX
	e_NextScene = IniScene;
	ChangeScene(IniScene);
}

void SceneManeger::Update()
{
	nowScene->Update();

	if (m_isChange) {
		ChangeScene(e_NextScene);
		m_isChange = false;
	}
}

void SceneManeger::Draw()
{
	nowScene->Draw();
}

void SceneManeger::ChangeSceneFlag(E_Scene scene)
{
	e_NextScene = scene;
	m_isChange = true;
}

void SceneManeger::ChangeScene(E_Scene nextScene)
{
	switch (nextScene)
	{
	case GAME:
		nowScene = gameScene;
		break;
	case TITLE:
		nowScene = titleScene;
		break;
	case STAGESELECT:
		nowScene = ssScene;
		break;
	case RESULT:
		break;
	
	}

	//���݂̃V�[���̏�Ԃ�ύX����
	e_NowScene = e_NextScene;


	//���X�g�̍폜
	m_gameInstance->GetCollisionMNG()->CleanList();
	m_gameInstance->GetPictureMNG()->CleanList();

	nowScene->Initialize();

}