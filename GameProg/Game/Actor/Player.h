#pragma once


class Player : public Actor
{
public:

	struct LadderCol
	{
		int		num;
		bool	isLadder;
		Point	ladderPos;
	};

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	Player(Point pos);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();


	/// <summary>
	/// �Փˏ���
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// �Փ˂��Ă��Ȃ�
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// ���݃v���C���[�̃��C�g�����Ă��邩�ǂ���
	/// </summary>
	/// <returns></returns>
	bool GetLightOn() {
		return m_lightCmp->m_lightOn;
	}

	/// <summary>
	/// �v���C���[����肷��
	/// </summary>
	/// <returns></returns>
	Player* Getthis();

	void AddisLadder(int num,bool isladder,Point pos);

	void SetisLadder(int num, bool isladder);

	/// <summary>
	/// �����܂�̎�����ς���
	/// </summary>
	/// <param name="isPuddle"></param>
	void SetChangePuddleSound(bool isPuddle);

	void GameOver();

	/// <summary>
	/// �O�����烉�C�g�������I�ɂ���
	/// </summary>
	void OnLight();


	bool m_isGoalLight_Tought;	//�S�[�����C�g�̍�ƒ����ǂ���
	bool m_isDoorTouch;	//�h�A���J�������ǂ���
	std::shared_ptr<LightCmp> m_lightCmp;

	bool m_tutorialLight;
	bool m_tutorialMove_X;
	bool m_tutorialMove_Y;
	bool m_tutorialJump;
	bool m_tutorialAllStop;
	bool m_tutorialGoalLight;


private:
	bool m_firstShot;
	
	list <LadderCol> m_isLadder;
	bool m_isRightdir;

	int m_movePictureNum;	//�����Ă���ۂ̃v���C���[�̉摜
	int m_movePictureUp;	//�����Ă���ۂ̃v���C���[�̉摜
	int m_ascendPictureNum;	//�o���Ă���ۂ̃v���C���[�̉摜
	int m_gameOverPictureNum;	//�Q�[���I�[�o�[�ۂ̃v���C���[�̉摜

	int m_gameOverCount;

	shared_ptr<Sound> m_sound[4];//0=jump1=light2=move
	shared_ptr<OnSoundCmp> m_soundCmp;

	int m_soundFrame[3];

	bool m_isPuddle;
	bool m_isLadderTop;		//�͂�����o��؂�����


};