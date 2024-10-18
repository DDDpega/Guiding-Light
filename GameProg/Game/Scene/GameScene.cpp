#include "Framework.h"


GameScene::GameScene(Game* gameInstance)
	:Scene(gameInstance,"�Q�[���V�[��")
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

	//�w�i�摜
	auto background = std::shared_ptr<BackGround>(new BackGround(POINT{ 0,0 }));
	m_gameInstance->GetPictureMNG()->AddPicture(background,this);

	//���������͂�
	m_lightPicture = std::shared_ptr<LightPicture>(new LightPicture());
	m_gameInstance->GetPictureMNG()->AddPicture(m_lightPicture, this);

	m_player = std::shared_ptr<Player>(new Player(POINT{200,200}));
	m_gameInstance->GetPictureMNG()->AddPicture(m_player, this);
	

	////�S�[�����C�g�̐���
	//light = shared_ptr<GoalLight>(new GoalLight(POINT{ 400,200 }));
	//m_gameInstance->GetPictureMNG()->AddPicture(light, this);
	//m_LightNum++;

	//�}�b�v�̐���
	m_map = std::shared_ptr<Map>(new Map(m_stages[0], "Picture/mapChipData16bit.png"));
	m_gameInstance->GetPictureMNG()->AddPicture(m_map, this);

	

	auto num = 0;
	for (auto& actorPos : m_map->GetActorPosList()) {
		//�v���C���[�̐���
		if (!actorPos.m_isGet && actorPos.m_actorNum == 5) {
			actorPos.m_isGet = true;
			m_player->SetPos(actorPos.m_actorPos);
			m_player->SpawnMove();
		}

		//�����v
		if (!actorPos.m_isGet && actorPos.m_actorNum == 6) {
			actorPos.m_isGet = true;
			//�S�[�����C�g�̐���
			auto light = shared_ptr<GoalLight>(new GoalLight(actorPos.m_actorPos));
			m_gameInstance->GetPictureMNG()->AddPicture(light, this);
			light->SpawnMove();
			m_LightNum++;
		}

		//�͂����̐���
		if (!actorPos.m_isGet && actorPos.m_actorNum == 7) {
			actorPos.m_isGet = true;
			auto ladder = shared_ptr<Ladder>(new Ladder(actorPos.m_actorPos, num));
			m_gameInstance->GetPictureMNG()->AddPicture(ladder, this);
		}
		if (actorPos.m_actorNum == 7) {
			num++;
		}

		//�~��
		if (!actorPos.m_isGet && actorPos.m_actorNum == 8) {
			actorPos.m_isGet = true;
		}
		//�n�G
		if (!actorPos.m_isGet && actorPos.m_actorNum == 9) {
			actorPos.m_isGet = true;
		}

		//�\�[���[�p�l��
		if (!actorPos.m_isGet && actorPos.m_actorNum == 10) {
			actorPos.m_isGet = true;
		}
		
		//�N���o����
		if (!actorPos.m_isGet && actorPos.m_actorNum == 11) {
			actorPos.m_isGet = true;
		}

		//�N�����ŏ�
		if (!actorPos.m_isGet && actorPos.m_actorNum == 12) {
			actorPos.m_isGet = true;
		}
		
	}

	//UI��\������
	m_pauseUI = shared_ptr<GamePauseUI>(new GamePauseUI(false));
	m_gameInstance->GetPictureMNG()->AddPicture(m_pauseUI, this);

	//�Q�[��UI�̕\��
	m_gameUI = shared_ptr<InGameUI>(new InGameUI());
	m_gameInstance->GetPictureMNG()->AddPicture(m_gameUI, this);
	m_gameUI->ChangeLight(m_LightNum);
}

void GameScene::Update()
{
	Scene::Update();

	//�|�[�Y�ɂ���
	if (KeyClick(KEY_INPUT_ESCAPE) >= 1) {
		if (m_isPause) {
			m_isPause = false;

			//UI�̌����ڂ�t����
			m_pauseUI->SetisVisible(false);
			//UI�̑��������

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

void GameScene::LightNumMinus()
{
	//���C�g��1����
	m_LightNum--;

	m_gameUI->ChangeLight(m_LightNum);
}
