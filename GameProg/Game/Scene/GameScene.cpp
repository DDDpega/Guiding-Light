#include "GameScene.h"
#include "SceneManeger.h"
#include "PictureManeger.h"
#include "include.h"
#include "Game.h"
#include "LightPicture.h"

GameScene::GameScene(Game* gameInstance)
	:Scene(gameInstance,"�Q�[���V�[��")
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
	Scene::~Scene();
}

void GameScene::Initialize()
{
	Scene::Initialize();
	

	//�w�i�摜
	/*auto background = std::shared_ptr<BackGround>(new BackGround(POINT{ 0,0 }));
	m_gameInstance->GetPictureMNG()->AddPicture(background,this);*/

	auto light = std::shared_ptr<LightPicture>(new LightPicture(POINT{ 0,0 }));
	m_gameInstance->GetPictureMNG()->AddPicture(light, this);

	//�v���C���[�̐���
	m_player = std::shared_ptr<Player>(new Player(POINT{300,300}));
	m_gameInstance->GetPictureMNG()->AddPicture(m_player, this);

	//�G�̐���
	auto enemy = std::shared_ptr<Enemy>(new Enemy(POINT{1000,0}));
	m_gameInstance->GetPictureMNG()->AddPicture(enemy, this);

	//�}�b�v�̐���
	m_map = std::shared_ptr<Map>(new Map(m_stages[0], "Picture/mapChipData40bit.png"));
	m_gameInstance->GetPictureMNG()->AddPicture(m_map, this);

	//----------------------------------------------------------------
	//���S
	m_pauseLogo = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 - 100 }, 0.8, "Picture/logo.png", PIVOT::CENTER,SORT::SORT_UI));
	m_gameInstance->GetPictureMNG()->AddPicture(m_pauseLogo, this);

	//�^�C�g���ɖ߂�摜
	m_backTitle = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 300 }, 0.1, "Picture/backTitle.png", PIVOT::CENTER, SORT::SORT_UI,false));
	m_gameInstance->GetPictureMNG()->AddPicture(m_backTitle, this);


	//�Q�[���ɖ߂�摜
	m_backGame = std::shared_ptr<Picture>(new Picture(POINT{ (LONG)screenX / 2 ,(LONG)screenY / 2 + 200 }, 0.1, "Picture/backGame.png", PIVOT::CENTER,  SORT::SORT_UI,false));
	m_gameInstance->GetPictureMNG()->AddPicture(m_backGame, this);

	//----------------------------------------------------------------
}

void GameScene::Update()
{
	Scene::Update();

	//�|�[�Y�ɂ���
	if (KeyClick(KEY_INPUT_ESCAPE) >= 1) {
		if (m_isPause) {
			m_isPause = false;

			//UI�̌����ڂ�t����
			m_backGame->SetisLook(false);
			m_backTitle->SetisLook(false);
			m_pauseLogo->SetisLook(false);
		}
		else {
			m_isPause = true;

			//UI�̌����ڂ�t����
			m_backGame->SetisLook(true);
			m_backTitle->SetisLook(true);
			m_pauseLogo->SetisLook(true);
		}
	}

	if (!m_player->m_isActive) {
		m_gameInstance->GetSceneMNG()->ChangeScene(E_Scene::TITLE);
	}

	//�|�[�Y��ԂȂ瓮�����Ȃ�
	if (m_isPause) {



		return;
	}		
}

void GameScene::Draw()
{
	Scene::Draw();


}