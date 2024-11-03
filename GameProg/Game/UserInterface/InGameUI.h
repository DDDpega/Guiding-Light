#pragma once

class InGameUI : public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	InGameUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~InGameUI();

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
	/// 残りのライトの数
	/// </summary>
	/// <param name="num"></param>
	void ChangeLight(int num) {
		m_pictureLightNum->ChangePicture(UI::GAME_LIST[UI::GAME_TYPE::LAMP_1], num-1);
	}


protected:
	shared_ptr<Picture> m_pictureLightNum;
};


