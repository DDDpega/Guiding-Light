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

	//�S�[�����C�g�̐���
	auto light = shared_ptr<GoalLight>(new GoalLight(POINT{1000,500}));
	m_gameInstance->GetPictureMNG()->AddPicture(light, this);
	m_LightNum++;

	//�S�[�����C�g�̐���
	light = shared_ptr<GoalLight>(new GoalLight(POINT{ 400,200 }));
	m_gameInstance->GetPictureMNG()->AddPicture(light, this);
	m_LightNum++;

	//�}�b�v�̐���
	m_map = std::shared_ptr<Map>(new Map(m_stages[0], "Picture/mapChipData16bit.png"));
	m_gameInstance->GetPictureMNG()->AddPicture(m_map, this);

	
	//�v���C���[�̐���
	m_player = std::shared_ptr<Player>(new Player(POINT{200,500}));
	m_gameInstance->GetPictureMNG()->AddPicture(m_player, this);

	//�͂����̐���
	auto num = 0;
	for (auto& ladderPos : m_map->GetActorPosList()) {
		if (!ladderPos.m_isGet && ladderPos.m_actorNum == 7) {
			ladderPos.m_isGet = true;
			auto ladder = shared_ptr<Ladder>(new Ladder(ladderPos.m_actorPos, num));
			m_gameInstance->GetPictureMNG()->AddPicture(ladder, this);
		}
		num++;
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
