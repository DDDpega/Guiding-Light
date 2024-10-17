#pragma once


class CollisionManeger
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CollisionManeger();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CollisionManeger();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// ���X�g���̃R���|�[�l���g�����݂��Ă��邩�ǂ���
	/// </summary>
	void ListCheck();

	/// <summary>
	/// ���X�g�ɒǉ�����
	/// </summary>
	void AddBOXCollisionList(std::shared_ptr<BoxCollisionCmp> collision);

	/// <summary>
	/// ���X�g�ɒǉ�����
	/// </summary>
	void AddCIRCLECollisionList(std::shared_ptr<CircleCollisionCmp> collision);

//-------------------------------BOXtoBOX------------------------
	/// <summary>
	/// �����蔻��̃`�F�b�N
	/// </summary>
	void CheckCollide_BOXtoBOX();

	/// <summary>
	/// ��̃I�u�W�F�N�g���Ԃ����Ă��邩
	/// </summary>
	bool CheckObjectHit_BOXtoBOX(BoxCollisionCmp* obj_i, BoxCollisionCmp* obj_j);


//-------------------------------CIRCLEtoCIRLCE------------------------

	/// <summary>
	/// �����蔻��̃`�F�b�N
	/// </summary>
	void CheckCollide_CIRCLEtoCIRCLE();

	/// <summary>
	/// ��̃I�u�W�F�N�g���Ԃ����Ă��邩
	/// </summary>
	bool CheckObjectHit_CIRCLEtoCIRLCE(CircleCollisionCmp* obj_i, CircleCollisionCmp* obj_j);


//-------------------------------CIRCLEtoBOX------------------------

	/// <summary>
	/// �����蔻��̃`�F�b�N
	/// </summary>
	void CheckCollide_CIRCLEtoBOX();

	/// <summary>
	/// ��̃I�u�W�F�N�g���Ԃ����Ă��邩
	/// </summary>
	bool CheckObjectHit_CIRCLEtoBOX(CircleCollisionCmp* obj_i, BoxCollisionCmp* obj_j);

	/// <summary>
	/// BOX��CIRCLE�̌v�Z
	/// </summary>
	/// <param name="t_x1"></param>
	/// <param name="t_y1"></param>
	/// <param name="t_x2"></param>
	/// <param name="t_y2"></param>
	/// <returns></returns>
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);

//--------------------------------------------------------------------


	/// <summary>
	/// ���X�g�̍폜
	/// </summary>
	void CleanList() {
		m_BOXcollisionList.clear();
		m_CIRCLEcollisionList.clear();
	}

	/// <summary>
	/// ���X�g�̒��g��1����肷��
	/// </summary>
	/// <param name="tag"></param>
	/// <returns></returns>
	std::shared_ptr<BoxCollisionCmp> GetCollisionActor(TAG tag) {
		for (auto& c : m_BOXcollisionList) {
			if (c->m_tag == tag)
				return c;
		}
		return nullptr;
	}

	std::list<std::shared_ptr<BoxCollisionCmp>> m_BOXcollisionList;	//�����蔻�胊�X�g
	std::list<std::shared_ptr<CircleCollisionCmp>> m_CIRCLEcollisionList;	//�����蔻�胊�X�g
};

