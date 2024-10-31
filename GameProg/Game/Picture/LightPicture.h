#pragma once

class Picture;
class LightCmp;

class LightPicture : public Picture
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	LightPicture();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~LightPicture();

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
	/// ライトを追加する
	/// </summary>
	void AddLightList(LightCmp* lightCmp);

protected:
	int screenA;
	int screenB;
	int screenC;

	list<LightCmp*> lightCmpList;

	int x;
	int y;
};