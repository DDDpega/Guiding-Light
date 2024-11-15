#pragma once

class GameClearUI : public UserInterface
{
public:
	GameClearUI();

	~GameClearUI();

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

protected:
	int sentence1;
};

