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


	void GameClear();

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
	/// �������̃X�e�[�W���̎擾
	/// </summary>
	/// <returns></returns>
	int GetStageSize() { return size(m_stages); }

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
	vector<shared_ptr<SolarPanel>> m_solarpanel;
	vector<shared_ptr<Curtains>> m_curtains;
	shared_ptr<Door> m_door[2];
	shared_ptr<TutorialBox> m_tutorialBoxClear;
	vector<GoalLight*> m_goalLightList;
	vector<shared_ptr<TutorialBox>> m_tutorialBox;

	vector<OnSoundCmp*> m_onSoundCmp;

	bool isOnceGameClearUI;

	//�e��UI
	shared_ptr<InGameUI> m_gameUI;

private:
	shared_ptr<Sound> m_pause[2];
	shared_ptr<Sound> m_bgm;

	shared_ptr<Sound> m_result[2];	//0...over,1...clear

	std::shared_ptr<Player> m_player;	
	int m_LightNum;	//�c��̃��C�g�̐�
	bool isGameOver, isGameClear;



	int m_nowStageNum;
};