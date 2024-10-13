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
	void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};

