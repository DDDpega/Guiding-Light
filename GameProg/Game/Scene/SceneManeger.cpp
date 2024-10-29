#include "Framework.h"

GameScene* SceneManeger::gameScene = nullptr;

SceneManeger::SceneManeger()
{

}

SceneManeger::~SceneManeger()
{

}

void SceneManeger::Initialize()
{
	//�ϐ��̏�����
	gameScene = new GameScene();
	titleScene = new TitleScene();
	ssScene = new StageSelectScene();

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

void SceneManeger::ChangeSceneFlag(E_SCENE scene)
{
	e_NextScene = scene;
	m_isChange = true;
}

void SceneManeger::ChangeScene(E_SCENE nextScene)
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
	Game::gameInstance->GetCollisionMNG()->CleanList();
	Game::gameInstance->GetPictureMNG()->CleanList();
	Game::gameInstance->GetActorMNG()->CleanList();

	nowScene->Initialize();

}