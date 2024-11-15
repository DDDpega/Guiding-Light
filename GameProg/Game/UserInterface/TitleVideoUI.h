#pragma once

class TitleVideoUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleVideoUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TitleVideoUI();

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

private:
	shared_ptr<Picture> m_startText;
	shared_ptr<Picture> m_demoText;

};

