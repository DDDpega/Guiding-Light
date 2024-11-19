#pragma once
#include "UserInterface.h"
class OptionUI :
    public UserInterface
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	OptionUI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~OptionUI();

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
	shared_ptr<Picture> m_modeText;

};

