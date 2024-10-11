#include "Game.h"
#include "Key.h"

Game::Game()
{
	//コンストラクタ
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
	(m_pictureMNG = new PictureManeger(this))->Initialize();
	(m_actorMNG = new ActorManager(this))->Initialize();
	(m_sceneMNG = new SceneManeger(this))->Initialize();

	//入力の初期化
	KeyInit();
}

void Game::Update()
{
	//マネージャーの更新処理
	m_sceneMNG->Update();
	m_actorMNG->Update();
	m_pictureMNG->Update();
	m_collisionMNG->Update();
	m_collisionMNG->CheckCollide();

	//入力の更新
	KeyUpdate();
}

void Game::Draw()
{
	//マネージャーの描画処理
	m_sceneMNG->Draw();
	m_pictureMNG->Draw();
	m_actorMNG->Draw();
}