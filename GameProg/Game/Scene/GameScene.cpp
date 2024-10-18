#include "Framework.h"


GameScene::GameScene(Game* gameInstance)
	:Scene(gameInstance,"ゲームシーン")
	, m_stages({
		{
			MAPCHIP_HEIGHT,MAPCHIP_WIDTH,
			MAP_SIZE_HEIGHT,MAP_SIZE_WIDTH,
			L"_=56789abc",
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

	//黒い紙をはる
	m_lightPicture = std::shared_ptr<LightPicture>(new LightPicture());
	m_gameInstance->GetPictureMNG()->AddPicture(m_lightPicture, this);

	m_player = std::shared_ptr<Player>(new Player(POINT{200,200}));
	m_gameInstance->GetPictureMNG()->AddPicture(m_player, this);
	

	////ゴールライトの生成
	//light = shared_ptr<GoalLight>(new GoalLight(POINT{ 400,200 }));
	//m_gameInstance->GetPictureMNG()->AddPicture(light, this);
	//m_LightNum++;

	//マップの生成
	m_map = std::shared_ptr<Map>(new Map(m_stages[0], "Picture/mapChipData16bit.png"));
	m_gameInstance->GetPictureMNG()->AddPicture(m_map, this);

	

	auto num = 0;
	for (auto& actorPos : m_map->GetActorPosList()) {
		//プレイヤーの生成
		if (!actorPos.m_isGet && actorPos.m_actorNum == 5) {
			actorPos.m_isGet = true;
			m_player->SetPos(actorPos.m_actorPos);
			m_player->SpawnMove();
		}

		//ランプ
		if (!actorPos.m_isGet && actorPos.m_actorNum == 6) {
			actorPos.m_isGet = true;
			//ゴールライトの生成
			auto light = shared_ptr<GoalLight>(new GoalLight(actorPos.m_actorPos));
			m_gameInstance->GetPictureMNG()->AddPicture(light, this);
			light->SpawnMove();
			m_LightNum++;
		}

		//はしごの生成
		if (!actorPos.m_isGet && actorPos.m_actorNum == 7) {
			actorPos.m_isGet = true;
			auto ladder = shared_ptr<Ladder>(new Ladder(actorPos.m_actorPos, num));
			m_gameInstance->GetPictureMNG()->AddPicture(ladder, this);
		}
		if (actorPos.m_actorNum == 7) {
			num++;
		}

		//蓄光
		if (!actorPos.m_isGet && actorPos.m_actorNum == 8) {
			actorPos.m_isGet = true;
		}
		//ハエ
		if (!actorPos.m_isGet && actorPos.m_actorNum == 9) {
			actorPos.m_isGet = true;
		}

		//ソーラーパネル
		if (!actorPos.m_isGet && actorPos.m_actorNum == 10) {
			actorPos.m_isGet = true;
		}
		
		//起動出現床
		if (!actorPos.m_isGet && actorPos.m_actorNum == 11) {
			actorPos.m_isGet = true;
		}

		//起動消滅床
		if (!actorPos.m_isGet && actorPos.m_actorNum == 12) {
			actorPos.m_isGet = true;
		}
		
	}

	//UIを表示する
	m_pauseUI = shared_ptr<GamePauseUI>(new GamePauseUI(false));
	m_gameInstance->GetPictureMNG()->AddPicture(m_pauseUI, this);

	//ゲームUIの表示
	m_gameUI = shared_ptr<InGameUI>(new InGameUI());
	m_gameInstance->GetPictureMNG()->AddPicture(m_gameUI, this);
	m_gameUI->ChangeLight(m_LightNum);
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

void GameScene::LightNumMinus()
{
	//ライトを1引く
	m_LightNum--;

	m_gameUI->ChangeLight(m_LightNum);
}
