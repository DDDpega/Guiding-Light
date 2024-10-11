#pragma once
#include "Picture.h"
#include "DxLib.h"

class LightPicture : public Picture
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	LightPicture(POINT pos);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~LightPicture();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};