#pragma once


class Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Component(Actor* actor);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Component();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// �A�N�^�[���擾����
	/// </summary>
	/// <returns></returns>
	Actor* GetActor() {
		return m_actor;
	}


	Point m_pos;	//���S�ʒu

protected:
	Actor* m_actor;	//�ǂ̐e�ɂ�������
};

