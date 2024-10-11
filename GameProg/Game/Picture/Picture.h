#pragma once
#include "DxLib.h"

class Game;
class Scene;

enum PIVOT
{
	CENTER,LEFTUP
};

enum SORT
{
	SORT_UI,
	SORT_ACTOR,
	SORT_LIGHT,
	SORT_MAP,
	SORT_BACKGROUND,
};

class Picture
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Picture(POINT pos, float size, const TCHAR* picture, PIVOT pivot, SORT sort, bool isVisible=true);

	/// <summary>
	/// 描画しないPicture
	/// </summary>
	Picture(SORT sort);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Picture();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize(Game* gameInstance_, Scene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// 画像の変更
	/// </summary>
	/// <param name="picture"></param>
	void ChangePicture(const TCHAR* picture);

	/// <summary>
	/// 現在のポジションを得る
	/// </summary>
	/// <returns></returns>
	POINT GetPos() {
		return m_pos;
	}

	/// <summary>
	/// ポジションの変更
	/// </summary>
	/// <returns></returns>
	void SetPos(POINT changepos) {
		m_pos = changepos;
	}

	/// <summary>
	/// 見た目の変更
	/// </summary>
	/// <param name="islook"></param>
	void SetisLook(bool islook) {
		m_isVisible = islook;
	}

	SORT GetSort() {
		return m_sort;
	}

	bool m_isActive;			//生存するかどうか

protected:
	SORT m_sort;			//描画順番
	POINT m_pos;			//位置
	float m_size;		//画像の倍率
	int m_handle;				// データハンドル格納用変数
	const TCHAR* m_picture;	//画像のファイル名
	int m_framecnt;			//フレームカウント
	int m_pictureSizeX;		//画像サイズ
	int m_pictureSizeY;		//画像サイズ
	PIVOT m_pivot;			//画像の中心位置
	bool m_isVisible;			//見た目を消す
	bool m_pictureNull;			//描画しないPicture
};

