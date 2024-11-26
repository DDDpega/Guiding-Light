#pragma once

class LuminousFigure;

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

	const vector<Map::OnryMapInfo> m_stages;    //�X�e�[�W�̃}�b�v���z��

	const Map::Info m_mapInfo;    //�X�e�[�W�̃}�b�v���z��

	/// <summary>
	/// MapInfo�̃Q�b�^�[
	/// </summary>
	/// <param name="num">�z��̐���</param>
	/// <returns></returns>
	inline Map::OnryMapInfo getInfo(int num) {
		return m_stages[num];
	}

	//���C�g�̐�������
	void LightNumChange(int change);

	/// <summary>
	/// �X�e�[�W�̔ԍ���ύX
	/// </summary>
	/// <param name="num">�X�e�[�W�ԍ�</param>
	void SetNumStage(int num) { m_nowStageNum = num; }

	/// <summary>
	/// �X�e�[�W�̔ԍ����擾
	/// </summary>
	int GetNumStage() { return m_nowStageNum; }


	shared_ptr<Map>	m_map;
	shared_ptr<LightPicture> m_lightPicture;
	vector<LuminousFigure*> m_figureList;	//�~���t�B�M���A�̃��X�g
	vector<shared_ptr<Picture>> m_darkPictureList;
	shared_ptr<GamePauseUI> m_pauseUI;
	shared_ptr<SolarPanel> m_solarpanel;
	shared_ptr<Door> m_door[2];

	vector<GoalLight*> m_goalLightList;

private:
	std::shared_ptr<Player> m_player;	
	int m_LightNum;	//�c��̃��C�g�̐�
	bool isGameOver, isGameClear;

	//�e��UI
	shared_ptr<InGameUI> m_gameUI;

	int m_nowStageNum;
};