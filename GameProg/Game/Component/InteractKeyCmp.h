#pragma once

class InteractKeyCmp : public Component
{
public:
	InteractKeyCmp(Actor* actor, E_INTERACT_KIND kind);

	virtual ~InteractKeyCmp();

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
	/// 画像を削除する
	/// </summary>
	void DeletePicture();

	/// <summary>
	/// パラメーター設定
	/// </summary>
	void SetParam(E_INTERACT_KIND kind);

	/// <summary>
	/// 画像切り替え
	/// </summary>
	void PictureSwitch();

	/// <summary>
	/// 入力があったら画像を削除する
	/// </summary>
	void IsInput_PictureDelete();

	shared_ptr<Picture> m_interactPicture;
	E_INTERACT_KIND m_interactKind;
	int m_pictureNum;
};

