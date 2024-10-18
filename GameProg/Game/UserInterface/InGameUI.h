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
	void Initialize(Game* gameInstance_, Scene* scene);

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
		m_lightnum = num;
	}


protected:
	int m_stageNum;		//ステージ数
	int m_lightnum;		//残りのライトの数
};


