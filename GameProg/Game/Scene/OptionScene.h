#pragma once
#include "Scene.h"
class OptionScene :
    public Scene
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	OptionScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~OptionScene();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
private:
};

