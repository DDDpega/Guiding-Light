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
	void AddMapCollisionList(std::shared_ptr<BoxCollisionCmp> collision) {
		//���X�g�ɓ����
		m_mapCollision.push_back(collision);
	}

	/// <summary>
	/// ���X�g�ɒǉ�����
	/// </summary>
	void AddCIRCLECollisionList(std::shared_ptr<CircleCollisionCmp> collision);

	/// <summary>
	/// ���X�g�ɒǉ�����
	/// </summary>
	void AddRayToHitObjectList(std::shared_ptr<BoxCollisionCmp> collision);

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

//-----------Ray---------------------------------------------------------

	/// <summary>
	/// ���C�ƃ}�b�v���Ԃ����Ă��邩�ǂ���
	/// </summary>
	/// <param name="RayPos"></param>
	/// <returns></returns>
	bool RayHitCheck(Point RayPos);

	/// <summary>
	/// ���C�ƂԂ���I�u�W�F�N�g�̔���
	/// </summary>
	/// <param name="ray"></param>
	/// <returns></returns>
	bool RayToHitObjectCheck(RayCast* ray);

	/// <summary>
	/// ���X�g�̍폜
	/// </summary>
	void CleanList() {
		m_BOXcollisionList.clear();
		m_CIRCLEcollisionList.clear();
		m_rayToHitObject.clear();
		m_mapCollision.clear();
	}


	/// <summary>
	/// ���X�g�̒��g��1����肷��
	/// </summary>
	/// <param name="tag"></param>
	/// <returns></returns>
	std::shared_ptr<BoxCollisionCmp> GetCollisionActor(E_TAG tag) {
		for (auto& c : m_BOXcollisionList) {
			if (c->m_tag == tag)
				return c;
		}
		return nullptr;
	}

	list<shared_ptr<BoxCollisionCmp>> m_BOXcollisionList;	//�����蔻�胊�X�g
	list<shared_ptr<BoxCollisionCmp>> m_mapCollision;	//�����蔻�胊�X�g
	list<shared_ptr<CircleCollisionCmp>> m_CIRCLEcollisionList;	//�����蔻�胊�X�g
	list<shared_ptr<BoxCollisionCmp>> m_rayToHitObject;	//���C���L����r���ɓ����郊�X�g

	BOX rayHitCheckCollObj_i;
	Point rayHitCheckCollObj_j;

};

