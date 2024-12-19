#include "Framework.h"

GameScene* SceneManeger::gameScene = nullptr;
StageSelectScene* SceneManeger::ssScene = nullptr;

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
	creditScene = new CreditScene();
	optionScene = new OptionScene();
	tvScene = new TitleVideoScene();

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

void SceneManeger::ChangeSceneFlag(E_SCENE scene,bool isRight)
{
	e_NextScene = scene;
	m_isChange = true;
	m_isRight = isRight;
}


void SceneManeger::ChangeScene(E_SCENE nextScene)
{
	
	switch (nextScene)
	{
	case GAME:
		nowScene = gameScene;
		
		break;
	case E_SCENE::TITLE:
		nowScene = titleScene;
		break;
	case TITLEVIDEO:
		nowScene = tvScene;
		break;
	case STAGESELECT:
		nowScene = ssScene;
		break;
	case RESULT:
		break;
	case CREDIT:
		nowScene = creditScene;
		break;
	case OPTION:
		nowScene = optionScene;
		break;
	
	}

	nowScene->m_isRightFade = m_isRight;

	Game::gameInstance->GetSoundMNG()->ClearSound();

	//���݂̃V�[���̏�Ԃ�ύX����
	e_NowScene = e_NextScene;

	//���X�g�̍폜
	Game::gameInstance->GetCollisionMNG()->CleanList();
	Game::gameInstance->GetPictureMNG()->CleanList();
	Game::gameInstance->GetActorMNG()->CleanList();

	nowScene->Initialize();

}