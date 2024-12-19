#pragma once






#define IniScene E_SCENE::TITLE	//���߂̃V�[���ݒ�

class SceneManeger
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SceneManeger();

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
	void ChangeScene(E_SCENE nextScene);

	/// <summary>
	/// �V�[���ύX�̃t���O
	/// </summary>
	/// <param name="scene"></param>
	void ChangeSceneFlag(E_SCENE scene, bool isRight = true);

	/// <summary>
	/// ���̃V�[������肷��
	/// </summary>
	/// <returns></returns>
	Scene* GetNowScene() {
		return nowScene;
	}

	static GameScene* gameScene;
	static StageSelectScene* ssScene;


private:
	//�V�[��
	Scene* nowScene;
	TitleScene* titleScene;
	
	OptionScene* optionScene;
	CreditScene* creditScene;
	TitleVideoScene* tvScene;

	E_SCENE e_NowScene;
	E_SCENE e_NextScene;


	bool m_isChange;

	bool m_isRight;
};