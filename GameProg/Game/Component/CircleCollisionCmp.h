#pragma once

struct CIRCLE
{
	POINT CENTER;
	float RADIUS;
};

class CircleCollisionCmp : public Component
{
public:
	CircleCollisionCmp(Actor* actor, POINT offset, float radius, TAG name);

	virtual ~CircleCollisionCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance, Scene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �����蔻��̕ύX
	/// </summary>
	void ChangeCollision();

	/// <summary>
	/// �����蔻����|�W�V���������ύX���擾����
	/// </summary>
	BOX GetChangeCollision(POINT pos);

	TAG m_tag;		//�^�O
	CIRCLE m_collision;


protected:
	POINT m_offset;	//�ǂꂾ���Â�Ă��邩
};

