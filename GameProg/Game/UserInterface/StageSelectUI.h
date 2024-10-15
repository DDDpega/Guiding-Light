#pragma once

class StageSelectUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageSelectUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~StageSelectUI();

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

	void LordFile();
private:

};

