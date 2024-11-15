#include "Framework.h"

RayCast::RayCast(Point pos,E_TAG tag)
	:Actor(pos)
	,frame(0)
	,m_tag(tag)
	,m_isRayStart(false)
{
	//�����蔻��
	/*auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, {5,5}, E_TAG::RAY));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);*/
}

RayCast::~RayCast()
{

}

void RayCast::Update()
{
	//���C�ƂԂ���I�u�W�F�N�g�̔���`�F�b�N
	Game::gameInstance->GetCollisionMNG()->RayToHitObjectCheck(this);

}

void RayCast::Draw()
{
	if (GAME_INFO::DEBUG) {
		DrawPixel(m_pos.x, m_pos.y, GetColor(255, 0, 0));
	}
}

Point RayCast::RayStart(Point pos,int radius,int element)
{
	//�ʒu�̍X�V
	m_pos = pos;
	m_moveradius = 0;
	m_isRayStart = true;

	//���C������
	if (radius == 0) {
		m_pos.x = -10.0f;
		m_pos.y = -10.0f;
		m_isRayStart = false;
		return m_pos;
	}

	//���C���O���Ɍ������ď���
	while (true) {

		++m_moveradius;

		//�^�[�Q�b�g�̐ݒ�
		m_rad = ((float)element / GAME_INFO::RAYNUM) * (3.14f * 2.0f);
		m_pos.x = m_moveradius * cos(m_rad) + pos.x;
		m_pos.y = m_moveradius * sin(m_rad) + (pos.y-15);

		//���C�ƂԂ���I�u�W�F�N�g�̔���`�F�b�N
		Game::gameInstance->GetCollisionMNG()->RayToHitObjectCheck(this);

		//�ő�l�ɂȂ�����I������
		if (radius == m_moveradius) {
			break;
		}

		//�ȉ��d���̂ŉ񐔂��i��
		if (m_moveradius % 2 != 0)
			continue;

		//�����蔻��̃`�F�b�N
		if (Game::gameInstance->GetCollisionMNG()->RayHitCheck(m_pos)){


			if (m_moveradius >= (radius - 8)) {
				break;
			}
			//x+
			if (pos.x <= m_pos.x) {
				m_pos.x += 10;
			}
			//x-
			else if (pos.x > m_pos.x) {
				m_pos.x -= 10;
			}
			//y+
			if (pos.y <= m_pos.y) {
				m_pos.y += 10;
			}
			//y-
			else if (pos.y > m_pos.y) {
				m_pos.y -= 10;
			}

			break;
		}
	}
	return m_pos;
}



void RayCast::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}

void RayCast::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
