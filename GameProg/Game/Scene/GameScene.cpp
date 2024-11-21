#include "Framework.h"


GameScene::GameScene()
	:Scene("�Q�[���V�[��")
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

	//�ϐ��̏�����
	m_figureList.clear();
	m_isPause = false;
	m_LightNum = 0;
	isGameOver = false;
	isGameClear = false;
	m_darkPictureList.clear();
	
	//TODO ��Ŗ����ɕ\���ł���悤�ɂ���
	for (int i = 0; i < 5; i++) {
		//x�̈ʒu
		float x = WINDOW_INFO::GAME_WIDTH * i;
		//�w�i�摜
		auto background = std::shared_ptr<BackGround>(new BackGround(Point{ x  ,0 }));
		Game::gameInstance->GetActorMNG()->AddActor(background);
	}
	////�w�i�摜
	//auto background = std::shared_ptr<BackGround>(new BackGround(Point{ 0,0 }));
	//Game::gameInstance->GetActorMNG()->AddActor(background);

	



	//���������͂�
	m_lightPicture = std::shared_ptr<LightPicture>(new LightPicture());
	Game::gameInstance->GetPictureMNG()->AddPicture(m_lightPicture);

	


	//�}�b�v�̐���
	m_map = std::shared_ptr<Map>(new Map(m_stages[SceneManeger::gameScene->GetNumStage()], m_mapInfo, "Picture/mapChipData16bit.png"));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_map);

	//�v���C���[�̐���
	m_player = std::shared_ptr<Player>(new Player(Point{-1000,-1000 }));
	Game::gameInstance->GetActorMNG()->AddActor(m_player);
	
	auto num = 0;
	for (auto& actorPos : m_map->GetMapChipPosList()) {
		//�v���C���[�̐���
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 5) {
			actorPos.m_isGet = true;
			m_player->SetPos(actorPos.m_mapChipPos);
			m_player->SpawnMove(1,1);
		}

		//�����v
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 6) {
			actorPos.m_isGet = true;
			//�S�[�����C�g�̐���
			auto light = shared_ptr<GoalLight>(new GoalLight(actorPos.m_mapChipPos));
			light->SpawnMove(2, 2);
			Game::gameInstance->GetActorMNG()->AddActor(light);
			m_LightNum++;
		}

		//�͂����̐���
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 7) {
			actorPos.m_isGet = true;
			auto ladder = shared_ptr<Ladder>(new Ladder(actorPos.m_mapChipPos, num));
			Game::gameInstance->GetActorMNG()->AddActor(ladder);
		}
		if (actorPos.m_mapChipNum == 7) {
			num++;
		}

		//�~��
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 8) {
			actorPos.m_isGet = true;
			auto figure = shared_ptr<LuminousFigure>(new LuminousFigure(actorPos.m_mapChipPos));
			figure->SpawnMove(1, 2);
			Game::gameInstance->GetActorMNG()->AddActor(figure);
		}
		//�n�G
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 9) {
			actorPos.m_isGet = true;
			auto pisher = shared_ptr<Pisher>(new Pisher(actorPos.m_mapChipPos));
			pisher->SpawnMove(1, 1);
			Game::gameInstance->GetActorMNG()->AddActor(pisher);
		}

		//�\�[���[�p�l��
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 10) {
			actorPos.m_isGet = true;
			m_solarpanel = shared_ptr<SolarPanel>(new SolarPanel(actorPos.m_mapChipPos));
			Game::gameInstance->GetActorMNG()->AddActor(m_solarpanel);
		}

		//�N���o����
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 11) {
			actorPos.m_isGet = true;
			auto solarpanelblock = shared_ptr<SolarPanelBlock>(new SolarPanelBlock(actorPos.m_mapChipPos, false, this));
			Game::gameInstance->GetActorMNG()->AddActor(solarpanelblock);
		}

		//�����܂�
		if (!actorPos.m_isGet && actorPos.m_mapChipNum == 12) {
			actorPos.m_isGet = true;
			auto puddle = shared_ptr<Puddle>(new Puddle(actorPos.m_mapChipPos));
			Game::gameInstance->GetActorMNG()->AddActor(puddle);
		}

	}

	//UI��\������
	m_pauseUI = shared_ptr<GamePauseUI>(new GamePauseUI(false));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_pauseUI);

	//�Q�[��UI�̕\��
	m_gameUI = shared_ptr<InGameUI>(new InGameUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(m_gameUI);
	m_gameUI->ChangeLight(m_LightNum);
}

void GameScene::Update()
{
	Scene::Update();

	//�|�[�Y�ɂ���
	if (Game::gameInstance->GetInputMNG()->Click(L"PAUSE") && !isGameClear && !isGameOver) {
		if (m_isPause) {
			m_isPause = false;

			//UI�̌����ڂ�t����
			m_pauseUI->SetisVisible(false);
		}
		else {
			m_isPause = true;

			//UI�̌����ڂ�t����
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
	//���݂��Q�[���I�[�o�[�Ȃ��return
	if (isGameOver)
		return;

	//�e��t���O��ύX
	m_isPause = true;
	isGameOver = true;

	//�Q�[���I�[�o�[��UI
	auto gameOver = shared_ptr<GameOverUI>(new GameOverUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(gameOver);

}

void GameScene::LightNumChange(int change)
{
	//���C�g��1����
	m_LightNum+=change;

	m_gameUI->ChangeLight(m_LightNum);

	//�c��̃��C�g��0�Ȃ�
	if (m_LightNum <= 0) {

		m_isPause = true;
		isGameClear = true;

		//�Q�[���N���A��UI
		auto gameClear = shared_ptr<GameClearUI>(new GameClearUI());
		Game::gameInstance->GetPictureMNG()->AddPicture(gameClear);
	}
}
