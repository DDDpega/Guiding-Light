#pragma once

class Actor;

//�����蔻���BOX
struct BOX
{
	float left, right, top, bottom;
};

//�R���W�����^�O
enum TAG
{
	PLAYER, BULLET, ENEMY, CHILD, BACKGROUND, LADDER,
	PLAYER_LIGHT,MAP, LUMINOUSFIGURE,PISHER
};

class BoxCollisionCmp :public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BoxCollisionCmp(Actor* actor,POINT offset,POINT size,TAG name);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BoxCollisionCmp();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(Game* gameInstance,Scene* scene);

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
	BOX m_collision;


protected:
	POINT m_size;	//���E�̃T�C�Y
	POINT m_offset;	//�ǂꂾ���Â�Ă��邩
};

