#include "Framework.h"

//ゲームインスタンスの初期化
Game* Game::gameInstance = nullptr;

Game::Game()
{
	//ゲームインスタンスの初期化
	gameInstance = this;
}

Game::~Game()
{

}

void Game::Initialize() 
{
	//ステータスの取得
	m_status = new Status();

	if (!m_status->ReadStatus()) {
		// DXライブラリ終了処理
		DxLib_End();
	}

	//マネージャーの初期化
	(m_collisionMNG = new CollisionManeger())->Initialize();
	(m_pictureMNG = new PictureManeger())->Initialize();
	(m_actorMNG = new ActorManager())->Initialize();
	(m_sceneMNG = new SceneManeger())->Initialize();
	m_inputMNG = new InputManager();

	//入力の初期化
	KeyInit();
}

void Game::Update()
{
	//マネージャーの更新処理
	m_sceneMNG->Update();
	m_pictureMNG->Update();
	m_actorMNG->Update();
	m_collisionMNG->Update();
	m_collisionMNG->CheckCollide_BOXtoBOX();
	m_collisionMNG->CheckCollide_CIRCLEtoCIRCLE();
	m_collisionMNG->CheckCollide_CIRCLEtoBOX();


	//入力の更新
	m_inputMNG->Update();
	KeyUpdate();
}

void Game::Draw()
{
	//マネージャーの描画処理
	m_sceneMNG->Draw();
	m_pictureMNG->Draw();
	m_actorMNG->Draw();
}