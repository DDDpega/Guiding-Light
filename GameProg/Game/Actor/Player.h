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
	/// コンストラクタ
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	Player(Point pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();


	/// <summary>
	/// 衝突処理
	/// </summary>
	/// <param name="other"></param>
	void HitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// 衝突していない
	/// </summary>
	/// <param name="other"></param>
	/// <param name="tag"></param>
	void NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag);

	/// <summary>
	/// 現在プレイヤーのライトがついているかどうか
	/// </summary>
	/// <returns></returns>
	bool GetLightOn() {
		return m_lightCmp->m_lightOn;
	}

	/// <summary>
	/// プレイヤーを入手する
	/// </summary>
	/// <returns></returns>
	Player* Getthis();

	void AddisLadder(int num,bool isladder,Point pos);

	void SetisLadder(int num, bool isladder);

	/// <summary>
	/// 水たまりの時音を変える
	/// </summary>
	/// <param name="isPuddle"></param>
	void SetChangePuddleSound(bool isPuddle);

	void GameOver();

	/// <summary>
	/// 外部からライトを強制的につける
	/// </summary>
	void OnLight();


	bool m_isGoalLight_Tought;	//ゴールライトの作業中かどうか
	bool m_isDoorTouch;	//ドアを開いたかどうか
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

	int m_movePictureNum;	//動いている際のプレイヤーの画像
	int m_movePictureUp;	//動いている際のプレイヤーの画像
	int m_ascendPictureNum;	//登っている際のプレイヤーの画像
	int m_gameOverPictureNum;	//ゲームオーバー際のプレイヤーの画像

	int m_gameOverCount;

	shared_ptr<Sound> m_sound[4];//0=jump1=light2=move
	shared_ptr<OnSoundCmp> m_soundCmp;

	int m_soundFrame[3];

	bool m_isPuddle;
	bool m_isLadderTop;		//はしごを登り切ったか


};