#pragma once

class Picture;

class PictureManeger
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	PictureManeger(Game* gameInstane);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~PictureManeger();

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

	/// <summary>
	/// ピクチャーリストにpushする
	/// </summary>
	/// <param name=""></param>
	void AddPicture(std::shared_ptr<Picture> picture,  Scene* scene);

	/// <summary>
	/// リストの削除
	/// </summary>
	void CleanList() {
		m_pictureList.clear();
	}

protected:
	std::list<std::shared_ptr<Picture>> m_pictureList;
	Game* m_gameInstance;
};

bool SortChange(std::shared_ptr<Picture>& a, std::shared_ptr<Picture>& b);


