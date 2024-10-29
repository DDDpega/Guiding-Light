#pragma once

class Picture;
class Actor;

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
	void AddLightList(shared_ptr<Picture> picture);

protected:
	int screenA;
	int screenB;
	int screenC;

	list<shared_ptr<Picture>> pictureList;

	int x;
	int y;
};