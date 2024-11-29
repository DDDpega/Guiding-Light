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


	bool m_isVideo;			//動画が流すかどうか
	bool m_isVideoPlay;		//動画が流れているかどうか
private:
	shared_ptr<Picture> m_startText[3];
	shared_ptr<Picture> m_gameExitText;
	bool m_isMenuActive;	//メニュー画面
	bool m_isFirst;
	shared_ptr<Picture> m_fadeUI;

};

