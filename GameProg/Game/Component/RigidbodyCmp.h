#pragma once


enum STATE {
	FLY,FLYOK, WALK, JUMP, STAND,FALL,JUMPSTT
};

class RigidbodyCmp : public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	RigidbodyCmp(Actor* actor,STATE state, E_TAG tag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~RigidbodyCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

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


	STATE m_state;			//���݂̏��
	E_TAG m_tag;
private:

};

