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
	//変数の初期化
	gameScene = new GameScene(m_gameInstance);
	titleScene = new TitleScene(m_gameInstance);

	//初期をゲームシーンに変更
	ChangeScene(IniScene);
}

void SceneManeger::Update()
{
	nowScene->Update();
}

void SceneManeger::Draw()
{
	nowScene->Draw();
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
	case RESULT:
		break;
	}

	//リストの削除
	m_gameInstance->GetCollisionMNG()->CleanList();
	m_gameInstance->GetPictureMNG()->CleanList();
	m_gameInstance->GetActorMNG()->CleanList();

	nowScene->Initialize();
}