#include "Framework.h"

Game::Game()
{
	//�R���X�g���N�^
}

Game::~Game()
{

}

void Game::Initialize() 
{
	//�X�e�[�^�X�̎擾
	m_status = new Status();

	if (!m_status->ReadStatus()) {
		// DX���C�u�����I������
		DxLib_End();
	}

	//�}�l�[�W���[�̏�����
	(m_collisionMNG = new CollisionManeger())->Initialize();
	(m_pictureMNG = new PictureManeger(this))->Initialize();
	(m_sceneMNG = new SceneManeger(this))->Initialize();
	m_inputMNG = new InputManager();

	//���͂̏�����
	KeyInit();
}

void Game::Update()
{
	//�}�l�[�W���[�̍X�V����
	m_sceneMNG->Update();
	m_pictureMNG->Update();
	m_collisionMNG->Update();
	m_collisionMNG->CheckCollide_BOXtoBOX();
	m_collisionMNG->CheckCollide_CIRCLEtoCIRCLE();
	m_collisionMNG->CheckCollide_CIRCLEtoBOX();

	//���͂̍X�V
	m_inputMNG->Update();
	KeyUpdate();
}

void Game::Draw()
{
	//�}�l�[�W���[�̕`�揈��
	m_sceneMNG->Draw();
	m_pictureMNG->Draw();
}