#pragma once

class CreditUI :
    public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CreditUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CreditUI();

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

private:
	shared_ptr<Picture> m_nameText[5];
	shared_ptr<Picture> m_jobText[3];
	shared_ptr<Picture> m_creditTitle;



};

