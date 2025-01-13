#pragma once

class GamePauseUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GamePauseUI(bool isVisible);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GamePauseUI();

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

	void ChangeImage(int nowcursor);
	vector<shared_ptr<Picture>> m_picture;

};

