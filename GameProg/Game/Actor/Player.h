#pragma once


class Player : public Actor
{
public:

	struct LadderCol
	{
		int		num;
		bool	isLadder;
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

	void AddisLadder(int num,bool isladder);

	void SetisLadder(int num, bool isladder);

private:
	bool m_firstShot;
	std::shared_ptr<LightCmp> m_lightCmp;
	list <LadderCol> m_isLadder;
	bool m_isRightdir;

	int m_movePictureNum;	//動いている際のプレイヤーの画像
	int m_movePictureUp;	//動いている際のプレイヤーの画像
	int m_ascendPictureNum;	//登っている際のプレイヤーの画像

	shared_ptr<Sound> m_sound[4];//0=jump1=light2=move

	int m_soundFrame[3];
};