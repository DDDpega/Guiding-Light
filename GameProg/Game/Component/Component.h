#pragma once


class Actor;
class Scene;

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
	virtual void Initialize(Scene* scene);

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
	Actor* GetActor();

	void Destroy(bool isSet) {
		m_destroy = isSet;
	}



	bool m_destroy;
	POINT m_pos;	//���S�ʒu

protected:
	Scene* m_sceneptr;
	Actor* m_actor;	//�ǂ̐e�ɂ�������

};

