#pragma once
#include "Component.h"

enum STATE {
	FLY, WALK, JUMP, STAND,FALL,JUMPSTT
};

class RigidbodyCmp : public Component
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	RigidbodyCmp(Actor* actor,STATE state);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~RigidbodyCmp();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(Scene* scene);

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

	void JumpByFall();

	
	
private:
	STATE m_state;			//現在の状態

};

