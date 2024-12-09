#pragma once


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
	void AddLineLightList(LineLightCmp* lightCmp);
	void AddClearLightList(ClearLightCmp* lightCmp);

protected:


	list<LightCmp*> lightCmpList;
	list<LineLightCmp*> lineLightCmpList;
	vector<ClearLightCmp*> clearLightCmpList;

	int x;
	int y;
};