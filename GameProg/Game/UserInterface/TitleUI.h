#pragma once


class TitleUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleUI(bool isFirst);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TitleUI();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// フェードインアウトを管理
	/// </summary>
	/// <param name="frame"></param>
	void FadeInOut(bool isFadeIn);

	/// <summary>
	/// プレイヤーのanimation
	/// </summary>
	void PlayerAnim();


	bool m_isVideo;			//動画が流すかどうか
	bool m_isVideoPlay;		//動画が流れているかどうか
private:
	shared_ptr<Picture> m_startText[3];
	shared_ptr<Picture> m_gameExitText;
	shared_ptr<Picture> m_lamp;
	bool m_isMenuActive;	//メニュー画面
	bool m_isFirst;
	shared_ptr<Picture> m_fadeUI;
	shared_ptr<Picture> m_player;
	int m_waittime;
	int m_frame;
	int m_lampFrame;
	int m_animCnt;						//animationの画像切り替え
	bool m_animMax;						//animationの画像の最大になるかどうか
	shared_ptr<Sound> m_startSound;		//スタート時のSE
};

