#include "Framework.h"


GameScene::GameScene(Game* gameInstance)
	:Scene(gameInstance,"ゲームシーン")
	, m_stages({
		{
			MAPCHIP_HEIGHT,MAPCHIP_WIDTH,
			MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
			L"_=",
			L"Data/Map1.txt",
			POINT{3,15},
		},
		{
			MAPCHIP_HEIGHT,MAPCHIP_WIDTH,
			MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
			L"_=",
			L"Data/Map1.txt",
			POINT{3,15},
		},

		})

{

}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	Scene::Initialize();
	

	//背景画像
	auto background = std::shared_ptr<BackGround>(new BackGround(POINT{ 0,0 }));
	m_gameInstance->GetPictureMNG()->AddPicture(background,this);

	m_lightPicture = std::shared_ptr<LightPicture>(new LightPicture());
	m_gameInstance->GetPictureMNG()->AddPicture(m_lightPicture, this);

	//プレイヤーの生成
	m_player = std::shared_ptr<Player>(new Player(POINT{200,500}));
	m_gameInstance->GetPictureMNG()->AddPicture(m_player, this);

	//敵の生成
	auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{1000,200}));
	m_gameInstance->GetPictureMNG()->AddPicture(enemy, this);

	//マップの生成
	m_map = std::shared_ptr<Map>(new Map(m_stages[0], "Picture/mapChipData16bit.png"));
	m_gameInstance->GetPictureMNG()->AddPicture(m_map, this);

	//UIを表示する
	m_pauseUI = shared_ptr<GamePauseUI>(new GamePauseUI(false));
	m_gameInstance->GetPictureMNG()->AddPicture(m_pauseUI, this);

}

void GameScene::Update()
{
	Scene::Update();

	//ポーズにする
	if (KeyClick(KEY_INPUT_ESCAPE) >= 1) {
		if (m_isPause) {
			m_isPause = false;

			//UIの見た目を付ける
			m_pauseUI->SetisVisible(false);
			//UIの操作をする

		}
		else {
			m_isPause = true;

			//UIの見た目を付ける
			m_pauseUI->SetisVisible(true);

		}
	}		
}

void GameScene::Draw()
{
	Scene::Draw();


}