#pragma once



class BoxCollisionCmp :public Component
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BoxCollisionCmp(Actor* actor, Point offset, Point size,E_TAG name);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BoxCollisionCmp();

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
	BOX m_collision;


protected:
	Point m_size;	//���E�̃T�C�Y
	Point m_offset;	//�ǂꂾ���Â�Ă��邩
};

