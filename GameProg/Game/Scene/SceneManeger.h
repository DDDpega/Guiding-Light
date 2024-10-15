#pragma once


class Game;
class GameScene;
class TitleScene;
class StageSelectScene;

enum E_Scene
{
	GAME, TITLE, STAGESELECT ,RESULT
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
	/// �V�[���ύX�̃t���O
	/// </summary>
	/// <param name="scene"></param>
	void ChangeSceneFlag(E_Scene scene);



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
	StageSelectScene* ssScene;

	E_Scene e_NowScene;
	E_Scene e_NextScene;

	//�Q�[���C���X�^���X
	Game* m_gameInstance;
};