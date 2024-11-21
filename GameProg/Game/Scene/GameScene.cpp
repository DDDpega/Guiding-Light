#include "Framework.h"


GameScene::GameScene()
	:Scene("ゲームシーン")
	, m_figureList()
	, m_LightNum(0)
	, m_mapInfo({
		MAPCHIP_HEIGHT, MAPCHIP_WIDTH,
		L"_=^56789abcd",
	})
	, m_stages({
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage0.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage1.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage2.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage3.txt",
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

	m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::STAGE], Sound::E_Sound::BGM, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
	m_bgm->SoundPlay(Sound::LOOP);

	//変数の初期化
	m_figureList.clear();
	m_isPause = false;
	m_LightNum = 0;
	isGameOver = false;
	isGameClear = false;
	m_darkPictureList.clear();
	
	//TODO 後で無限に表示できるようにする
	for (int i = 0; i < 5; i++) {
		//xの位置
		float x = WINDOW_INFO::GAME_WIDTH * i;
		//背景画像
		auto background = std::shared_ptr<BackGround>(new BackGround(Point{ x  ,0 }));
		Game::gameInstance->GetActorMNG()->AddActor(background);
	}
	////背景画像
	//auto background = std::shared_ptr<BackGround>(new BackGround(Point{ 0,0 }));
	//Game::gameInstance->GetActorMNG()->AddActor(background);

	



	//黒い紙をはる
	m_lightPicture = std::shared_ptr<LightPicture>(new LightPicture());
	Game::gameInstance->GetPictureMNG()->AddPicture(m_lightPicture);

	


	//マップの生成
	m_map = std::shared_ptr<Map>(new Map(m_stages[SceneManeger::gameScene->GetNumStage()], m_mapInfo, "Picture/mapChipData16bit.png"));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_map);

	//プレイヤーの生成
	m_player = std::shared_ptr<Player>(new Player(Point{-1000,-1000 }));
	Game::gameInstance->GetActorMNG()->AddActor(m_player);
	
	auto num = 0;
	for (auto& actorPos : m_map->GetMapChipPosList()) {
		//プレイヤーの生成
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 5) {
			actorPos.m_isGet = true;
			m_player->SetPos(actorPos.m_mapChipPos);
			m_player->SpawnMove(1,1);
		}

		//ランプ
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 6) {
			actorPos.m_isGet = true;
			//ゴールライトの生成
			auto light = shared_ptr<GoalLight>(new GoalLight(actorPos.m_mapChipPos));
			light->SpawnMove(2, 2);
			Game::gameInstance->GetActorMNG()->AddActor(light);
			m_LightNum++;
		}

		//はしごの生成
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 7) {
			actorPos.m_isGet = true;
			auto ladder = shared_ptr<Ladder>(new Ladder(actorPos.m_mapChipPos, num));
			Game::gameInstance->GetActorMNG()->AddActor(ladder);
		}
		if (actorPos.m_mapChipNum == 7) {
			num++;
		}

		//蓄光
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 8) {
			actorPos.m_isGet = true;
			auto figure = shared_ptr<LuminousFigure>(new LuminousFigure(actorPos.m_mapChipPos));
			figure->SpawnMove(1, 2);
			Game::gameInstance->GetActorMNG()->AddActor(figure);
		}
		//ハエ
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 9) {
			actorPos.m_isGet = true;
			auto pisher = shared_ptr<Pisher>(new Pisher(actorPos.m_mapChipPos));
			pisher->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(pisher);
		}

		//ソーラーパネル
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 10) {
			actorPos.m_isGet = true;
			m_solarpanel = shared_ptr<SolarPanel>(new SolarPanel(actorPos.m_mapChipPos));
			Game::gameInstance->GetActorMNG()->AddActor(m_solarpanel);
		}

		//起動出現床
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 11) {
			actorPos.m_isGet = true;
			auto solarpanelblock = shared_ptr<SolarPanelBlock>(new SolarPanelBlock(actorPos.m_mapChipPos, false, this));
			Game::gameInstance->GetActorMNG()->AddActor(solarpanelblock);
		}

		//水たまり
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 12) {
			actorPos.m_isGet = true;
			auto puddle = shared_ptr<Puddle>(new Puddle(actorPos.m_mapChipPos));
			Game::gameInstance->GetActorMNG()->AddActor(puddle);
		}

	}

	//UIを表示する
	m_pauseUI = shared_ptr<GamePauseUI>(new GamePauseUI(false));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_pauseUI);

	//ゲームUIの表示
	m_gameUI = shared_ptr<InGameUI>(new InGameUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(m_gameUI);
	m_gameUI->ChangeLight(m_LightNum);
}

void GameScene::Update()
{
	Scene::Update();

	//ポーズにする
	if (Game::gameInstance->GetInputMNG()->Click(L"PAUSE") && !isGameClear && !isGameOver) {
		if (m_isPause) {
			m_isPause = false;

			//UIの見た目を付ける
			m_pauseUI->SetisVisible(false);
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

Player* GameScene::GetPlayer()
{
	return m_player->Getthis();
}

void GameScene::GameOver()
{
	//現在がゲームオーバーならばreturn
	if (isGameOver)
		return;

	//各種フラグを変更
	m_isPause = true;
	isGameOver = true;

	//ゲームオーバーのUI
	auto gameOver = shared_ptr<GameOverUI>(new GameOverUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(gameOver);

}

void GameScene::LightNumChange(int change)
{
	//ライトを1引く
	m_LightNum+=change;

	m_gameUI->ChangeLight(m_LightNum);

	//残りのライトが0なら
	if (m_LightNum <= 0) {

		m_isPause = true;
		isGameClear = true;

		//ゲームクリアのUI
		auto gameClear = shared_ptr<GameClearUI>(new GameClearUI());
		Game::gameInstance->GetPictureMNG()->AddPicture(gameClear);
	}
}
