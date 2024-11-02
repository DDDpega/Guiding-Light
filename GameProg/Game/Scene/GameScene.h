#pragma once



class GameScene : public Scene
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GameScene();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameScene();

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
	/// Player�̃Q�b�^�[
	/// </summary>
	Player* GetPlayer();

	/// <summary>
	/// �Q�[���I�[�o�[
	/// </summary>
	void GameOver();
	

	struct  Size {
		float x, y;
	};

	const vector<Map::Info> m_stages;    //�X�e�[�W�̃}�b�v���z��

	/// <summary>
	/// MapInfo�̃Q�b�^�[
	/// </summary>
	/// <param name="num">�z��̐���</param>
	/// <returns></returns>
	inline Map::Info getInfo(int num) {
		return m_stages[num];
	}

	//���C�g�̐�������
	void LightNumMinus();


	std::shared_ptr<Map>	m_map;
	shared_ptr<LightPicture> m_lightPicture;
	list<shared_ptr<Pisher>> m_pisherList;	//�~���t�B�M���A�̃��X�g
	shared_ptr<GamePauseUI> m_pauseUI;
	shared_ptr<SolarPanel> m_solarpanel;

private:
	std::shared_ptr<Player> m_player;	
	int m_LightNum;	//�c��̃��C�g�̐�
	bool isGameOver, isGameClear;

	//�e��UI
	shared_ptr<InGameUI> m_gameUI;
};