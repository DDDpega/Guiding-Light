#pragma once
#include "include.h"
#include "BoxCollisionCmp.h"


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
	/// ���X�g�ɒǉ�����
	/// </summary>
	void addCollisionList(std::shared_ptr<BoxCollisionCmp> collision);


	/// <summary>
	/// �����蔻��̃`�F�b�N
	/// </summary>
	void CheckCollide();

	/// <summary>
	/// ��̃I�u�W�F�N�g���Ԃ����Ă��邩
	/// </summary>
	bool CheckObjectHit(BoxCollisionCmp* obj_i, BoxCollisionCmp* obj_j);

	/// <summary>
	/// ���X�g�̍폜
	/// </summary>
	void CleanList() {
		m_collisionList.clear();
	}

	/// <summary>
	/// ���X�g�̈ꕔ���폜����
	/// </summary>
	void ListDestroy();


	/// <summary>
	/// ���X�g�̒��g��1����肷��
	/// </summary>
	/// <param name="tag"></param>
	/// <returns></returns>
	std::shared_ptr<BoxCollisionCmp> GetCollisionActor(TAG tag) {
		for (auto& c : m_collisionList) {
			if (c->m_tag == tag)
				return c;
		}
		return nullptr;
	}

	std::list<std::shared_ptr<BoxCollisionCmp>> m_collisionList;	//�����蔻�胊�X�g
};

