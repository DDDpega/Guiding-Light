#pragma once
#include "Component.h"

enum STATE {
	FLY, WALK, JUMP, STAND,FALL,JUMPSTT
};

class RigidbodyCmp : public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	RigidbodyCmp(Actor* actor,STATE state);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~RigidbodyCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void ChangeState(STATE state){
		m_state = state;
	}

	void JumpByFall();

	
	
private:
	STATE m_state;			//���݂̏��

};

