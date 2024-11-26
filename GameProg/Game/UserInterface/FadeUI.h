#pragma once

class FadeUI :
    public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	FadeUI(bool isFirstTitle = false);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~FadeUI();

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
	/// ポジションとm_isMoveをリセットする
	/// </summary>
	void Reset();

	/// <summary>
	/// Fadeを動かす
	/// </summary>
	void MoveFeed(bool IsfeedIn,bool IsLeft);

private:
	shared_ptr<Picture> m_feedLeft;
	shared_ptr<Picture> m_feedRight;
	bool m_isFeedIn;
	bool m_isMove;
	bool m_isFirstTitle;
	bool m_isInitialize;
};

