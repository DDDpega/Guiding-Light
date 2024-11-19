#pragma once
#include "Scene.h"
class CreditScene :
    public Scene
{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CreditScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CreditScene();

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

