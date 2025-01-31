#include "Framework.h"


GameScene::GameScene()
	:Scene("ゲームシーン")
	, m_figureList()
	, m_LightNum(0)
	, m_mapInfo({
		MAPCHIP_HEIGHT, MAPCHIP_WIDTH,
		L"_=^56789abcdefghijklmvwxyz!",
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

	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage4.txt",
	},

	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage5.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage6.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage7.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage8.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage9.txt",
	},
	{
		MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
		L"Data/stage10.txt",
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

	m_goalLightList.clear();

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
	m_solarpanel.clear();
	m_onSoundCmp.clear();
	isOnceGameClearUI = false;
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
	
	auto ladderNum = 0;
	auto doorNum = 0;
	int arroundGhostNum = 0;
	for (auto& actorPos : m_map->GetMapChipPosList()) {
		//プレイヤーの生成
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::PLAYER) {
			actorPos.m_isGet = true;
			m_player->SetPos(actorPos.m_mapChipPos);
			m_player->SpawnMove(1,1);
		}

		//ランプ
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::LAMP) {
			actorPos.m_isGet = true;
			//ゴールライトの生成
			auto light = shared_ptr<GoalLight>(new GoalLight(actorPos.m_mapChipPos));
			light->SpawnMove(2, 2);
			Game::gameInstance->GetActorMNG()->AddActor(light);
			m_LightNum++;
		}

		//はしごの生成
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::LADDER) {
			actorPos.m_isGet = true;
			auto ladder = shared_ptr<Ladder>(new Ladder(actorPos.m_mapChipPos, ladderNum));
			Game::gameInstance->GetActorMNG()->AddActor(ladder);
		}
		if (actorPos.m_mapChipNum == 7) {
			ladderNum++;
		}

		//蓄光
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::FIGURE) {
			actorPos.m_isGet = true;
			auto figure = shared_ptr<LuminousFigure>(new LuminousFigure(actorPos.m_mapChipPos));
			figure->SpawnMove(1, 2);
			Game::gameInstance->GetActorMNG()->AddActor(figure);
		}
		

		//ソーラーパネル
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SOLARPANEL) {
			actorPos.m_isGet = true;
			auto solarpanel = shared_ptr<SolarPanel>(new SolarPanel(actorPos.m_mapChipPos));
			solarpanel->SetParam(E_SOLARPANEL_KIND::BLOCK);
			m_solarpanel.push_back(solarpanel);
			Game::gameInstance->GetActorMNG()->AddActor(solarpanel);
		}

		//起動出現床
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::LAUNCH) {
			actorPos.m_isGet = true;
			auto solarpanelblock = shared_ptr<SolarPanelBlock>(new SolarPanelBlock(actorPos.m_mapChipPos, false, this));
			Game::gameInstance->GetActorMNG()->AddActor(solarpanelblock);
		}
		//起動出現床
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::LAUNCH2) {
			actorPos.m_isGet = true;
			auto solarpanelblock = shared_ptr<SolarPanelBlock>(new SolarPanelBlock(actorPos.m_mapChipPos, true, this));
			Game::gameInstance->GetActorMNG()->AddActor(solarpanelblock);
		}

		

		//水たまり
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::PUDDLE) {
			actorPos.m_isGet = true;
			auto puddle = shared_ptr<Puddle>(new Puddle(actorPos.m_mapChipPos));
			puddle->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(puddle);
		}

		//ドア
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::DOOR) {
			actorPos.m_isGet = true;
			m_door[doorNum] = shared_ptr<Door>(new Door(actorPos.m_mapChipPos));
			m_door[doorNum]->SpawnMove(1, 2);
			Game::gameInstance->GetActorMNG()->AddActor(m_door[doorNum]);
			doorNum++;
		}

		//カーテン右
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::CURTAINSR) {
			actorPos.m_isGet = true;
			auto curtains = shared_ptr<Curtains>(new Curtains(actorPos.m_mapChipPos,false));
			m_curtains.push_back(curtains);
			curtains->SpawnMove(1, 3);
			Game::gameInstance->GetActorMNG()->AddActor(curtains);
		}
		//カーテン左
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::CURTAINSL) {
			actorPos.m_isGet = true;
			auto curtains = shared_ptr<Curtains>(new Curtains(actorPos.m_mapChipPos, true));
			m_curtains.push_back(curtains);
			curtains->SpawnMove(1, 3);
			Game::gameInstance->GetActorMNG()->AddActor(curtains);
		}

		//スポットライト右
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SPOTLIGHTR) {
			actorPos.m_isGet = true;
			auto spot = shared_ptr<SpotLight>(new SpotLight(actorPos.m_mapChipPos));
			spot->SpawnMove(1, 1);
			spot->SetParam(E_LINE_KIND::RIGHT,true);
			Game::gameInstance->GetActorMNG()->AddActor(spot);
		}
		//スポットライト左
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SPOTLIGHTL) {
			actorPos.m_isGet = true;
			auto spot = shared_ptr<SpotLight>(new SpotLight(actorPos.m_mapChipPos));
			spot->SpawnMove(1, 1);
			spot->SetParam(E_LINE_KIND::LEFT, true);
			Game::gameInstance->GetActorMNG()->AddActor(spot);
		}

		//スポットライトOFF右
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SPOTLIGHTR_OFF) {
			actorPos.m_isGet = true;
			auto spot = shared_ptr<SpotLight>(new SpotLight(actorPos.m_mapChipPos));
			spot->SpawnMove(1, 1);
			spot->SetParam(E_LINE_KIND::RIGHT, false);
			Game::gameInstance->GetActorMNG()->AddActor(spot);
		}
		//スポットライトOFF左
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SPOTLIGHTL_OFF) {
			actorPos.m_isGet = true;
			auto spot = shared_ptr<SpotLight>(new SpotLight(actorPos.m_mapChipPos));
			spot->SpawnMove(1, 1);
			spot->SetParam(E_LINE_KIND::LEFT, false);
			Game::gameInstance->GetActorMNG()->AddActor(spot);
		}
		//ソーラーパネルスポットライト
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SOLARPAEL_SPOT) {
			actorPos.m_isGet = true;
			auto solarpanel = shared_ptr<SolarPanel>(new SolarPanel(actorPos.m_mapChipPos));
			solarpanel->SetParam(E_SOLARPANEL_KIND::SPOT_LIGHT);
			m_solarpanel.push_back(solarpanel);
			Game::gameInstance->GetActorMNG()->AddActor(solarpanel);
		}
		//ソーラーパネルラジカセ
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SOLARPANEL_BOOMBOX) {
			actorPos.m_isGet = true;
			auto solarpanel = shared_ptr<SolarPanel>(new SolarPanel(actorPos.m_mapChipPos));
			solarpanel->SetParam(E_SOLARPANEL_KIND::BOOM_BOX);
			m_solarpanel.push_back(solarpanel);
			Game::gameInstance->GetActorMNG()->AddActor(solarpanel);
		}

		//ラジカセ
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::BOOMBOX) {
			actorPos.m_isGet = true;
			auto boomBox = shared_ptr<Boombox>(new Boombox(actorPos.m_mapChipPos));
			boomBox->SpawnMove(2, 1);
			Game::gameInstance->GetActorMNG()->AddActor(boomBox);
		}

		//追跡幽霊
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::CHASE) {
			actorPos.m_isGet = true;
			auto pisher = shared_ptr<ChaseGhost>(new ChaseGhost(actorPos.m_mapChipPos));
			pisher->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(pisher);
		}

		//パトロール幽霊
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::PATROL) {
			actorPos.m_isGet = true;
			auto pisher = shared_ptr<AroundGhost>(new AroundGhost(actorPos.m_mapChipPos));
			pisher->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(pisher);
			pisher->CreateRoute(++arroundGhostNum);
		}

		//いたずら幽霊
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::TRICK) {
			actorPos.m_isGet = true;
			auto pisher = shared_ptr<PastimeGhost>(new PastimeGhost(actorPos.m_mapChipPos));
			pisher->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(pisher);
		}

		//敏感な幽霊
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SENSITIVE) {
			actorPos.m_isGet = true;
			auto sensitive = shared_ptr<SensitiveGhost>(new SensitiveGhost(actorPos.m_mapChipPos));
			sensitive->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(sensitive);
		}

		//恥ずかしがり屋幽霊
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == MAPCHIPINFO::SHY) {
			actorPos.m_isGet = true;
			
		}

	}
	//pauseのSE
	m_pause[0] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::POSE], Sound::E_Sound::SE, 0));
	m_pause[1] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::CANCEL], Sound::E_Sound::SE, 0));
	m_result[0] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::GAMEOVER], Sound::E_Sound::SE, 0));
	m_result[1] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::GAMECLEAR], Sound::E_Sound::SE, 0));
	

	m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::STAGE], Sound::E_Sound::BGM, 0));

	Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
	m_bgm->SoundPlay(Sound::LOOP);
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_pause[0]);
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_pause[1]);
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_result[0]);
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_result[1]);

	auto isDoorCheek = false;
	doorNum = size(m_door);
	for (int i = 0; i < doorNum; i++) {
		if (m_door[i] == nullptr) {
			isDoorCheek = true;
			break;
		}
	}
	if (!isDoorCheek) {
		m_door[0]->SetTeleportPos(m_door[1]->GetPos());
		m_door[1]->SetTeleportPos(m_door[0]->GetPos());
	}

	if (m_nowStageNum == 0) {
		TutorialBox::SpawnTutorialBox();
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
			m_pause[1]->SoundPlay();
			//UIの見た目を付ける
			m_pauseUI->SetisVisible(false);

			m_gameUI->SetisVisible(true);
		}
		else {
			m_isPause = true;
			m_pause[0]->SoundPlay();
			//UIの見た目を付ける
			m_pauseUI->SetisVisible(true);

			m_gameUI->SetisVisible(false);
		}
	}

	if (isGameOver) 
		GetPlayer()->GameOver();
}

void GameScene::Draw()
{
	Scene::Draw();


}

Player* GameScene::GetPlayer()
{
	return m_player->Getthis();
}

void GameScene::GameClear()
{
	if (isOnceGameClearUI) return;
	
	m_result[1]->SoundPlay();
	m_gameUI->SetisVisible(false);

	if (GetNumStage() == 0) {
		m_isPause = false;
		m_tutorialBoxClear->SetPos(GetPlayer()->GetPos());
		SaveDataControl::saveData->SaveClearData(SceneManeger::gameScene->GetNumStage(), true);
	}
	else {
		isOnceGameClearUI = true;

		auto gameClear = shared_ptr<GameClearUI>(new GameClearUI());
		Game::gameInstance->GetPictureMNG()->AddPicture(gameClear);
	}
}

void GameScene::GameOver()
{
	//現在がゲームオーバーならばreturn
	if (isGameOver)
		return;

	m_result[0]->SoundPlay();
	m_gameUI->SetisVisible(false);


	//各種フラグを変更
	m_isPause = true;
	isGameOver = true;

}

void GameScene::LightNumChange(int change)
{
	//ライトを1引く
	m_LightNum += change;

	m_gameUI->ChangeLight(m_LightNum);

	//残りのライトが0なら
	if (m_LightNum <= 0) {

		m_isPause = true;
		isGameClear = true;

		//クリアライトコンポーネントを入れる
		for (int i = 0; i < m_goalLightList.size(); i++) {
			m_goalLightList[i]->AddComponent(shared_ptr<ClearLightCmp>(new ClearLightCmp(m_goalLightList[i])));
		}
	}
}
