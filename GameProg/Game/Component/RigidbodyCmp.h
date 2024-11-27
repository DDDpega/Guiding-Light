#pragma once


enum STATE {
	FLY,FLYOK, WALK, JUMP, STAND,FALL,JUMPSTT
};

class RigidbodyCmp : public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	RigidbodyCmp(Actor* actor,STATE state, E_TAG tag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~RigidbodyCmp();

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

	void ChangeState(STATE state){
		m_state = state;
	}


	STATE m_state;			//現在の状態
	E_TAG m_tag;
private:

};

