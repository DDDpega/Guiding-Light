#pragma once

struct CIRCLE
{
	float posX;
	float posY;
	float RADIUS;
};

class CircleCollisionCmp : public Component
{
public:
	CircleCollisionCmp(Actor* actor, Point offset, float radius, E_TAG name);

	virtual ~CircleCollisionCmp();

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

	/// <summary>
	/// �����蔻��̕ύX
	/// </summary>
	void ChangeCollision();

	/// <summary>
	/// �����蔻����|�W�V���������ύX���擾����
	/// </summary>
	BOX GetChangeCollision(Point pos);

	E_TAG m_tag;		//�^�O
	CIRCLE m_collision;


protected:
	float m_radius;
	Point m_offset;	//�ǂꂾ���Â�Ă��邩
};

