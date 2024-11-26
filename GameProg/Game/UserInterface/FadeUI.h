#pragma once

class FadeUI :
    public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	FadeUI();

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
	/// Fadeを動かす
	/// </summary>
	void MoveFeed(bool IsfeedIn);

private:
	shared_ptr<Picture> m_feedIn;
	shared_ptr<Picture> m_feedOut;
	bool m_isFeedIn;
};

