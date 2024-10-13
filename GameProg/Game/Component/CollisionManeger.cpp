#include "Framework.h"


CollisionManeger::CollisionManeger()
	:m_collisionList()
{

}

CollisionManeger::~CollisionManeger()
{

}

void CollisionManeger::Initialize()
{
	m_collisionList.clear();
}

void CollisionManeger::Update()
{


}

void CollisionManeger::addCollisionList(std::shared_ptr<BoxCollisionCmp> collision)
{
	//���X�g�ɓ����
	m_collisionList.push_back(collision);
}

void CollisionManeger::CheckCollide()
{
	//�R���W�������񂵂ďՓ˂��Ă��邩��������
	for (auto i = m_collisionList.cbegin(); i != m_collisionList.cend(); i++) {
		for (auto j = m_collisionList.cbegin(); j != m_collisionList.cend(); j++) {
			//����Object���ǂ����E����Object�������Ă��邩�ǂ���
			if (i->get()->GetActor() != j->get()->GetActor() &&
				i->get()->GetActor()->m_isActive && j->get()->GetActor()->m_isActive) {

				//�������Ă��邩�ǂ���
				CheckObjectHit(i->get(), j->get());

			}
		}
	}

	//�A�N�^�[���X�g�̒��g�폜
	for (auto i = m_collisionList.cbegin(); i != m_collisionList.cend();) {
		if (i->get()->GetActor()->m_isActive) {
			i++;
		}
		else {
			i = m_collisionList.erase(i);
		}
	}
}

bool CollisionManeger::CheckObjectHit(BoxCollisionCmp* obj_i, BoxCollisionCmp* obj_j)
{
	auto collObj_i = obj_i->m_collision;
	auto collObj_j = obj_j->m_collision;

	//�����蔻��
	if ((collObj_i.right > collObj_j.left) &&
		(collObj_i.left < collObj_j.right))
	{
		if ((collObj_i.bottom > collObj_j.top) &&
			(collObj_i.top < collObj_j.bottom))
		{
			//�I�u�W�F�N�g�ɏՓ˒ʒm�𑗂�
			obj_i->GetActor()->HitCollision((obj_j->GetActor()), (obj_j->m_tag));
			obj_j->GetActor()->HitCollision((obj_i->GetActor()), (obj_i->m_tag));

			return true;
		}
	}
	return false;
}

