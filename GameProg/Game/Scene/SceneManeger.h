#pragma once
#include "GameScene.h"
#include "TitleScene.h"

class Game;
class GameScene;
class TitleScene;

enum E_Scene
{
	GAME, TITLE, RESULT
};

#define IniScene E_Scene::TITLE	//���߂̃V�[���ݒ�

class SceneManeger
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SceneManeger(Game* gameInstance);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SceneManeger();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �V�[���̐؂�ւ�
	/// </summary>
	void ChangeScene(E_Scene nextScene);

	/// <summary>
	/// ���̃V�[������肷��
	/// </summary>
	/// <returns></returns>
	Scene* GetNowScene() {
		return nowScene;
	}



private:
	//�V�[��
	Scene* nowScene;
	GameScene* gameScene;
	TitleScene* titleScene;

	//�Q�[���C���X�^���X
	Game* m_gameInstance;
};