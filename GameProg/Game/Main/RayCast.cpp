#include "Framework.h"

RayCast::RayCast(POINT pos,E_TAG tag)
	:Actor(pos)
	,frame(0)
	,m_tag(tag)
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

POINT RayCast::RayStart(POINT pos,int radius,int element)
{
	//�ʒu�̍X�V
	m_pos = pos;
	auto moveradius = 0;

	//���C������
	if (radius == 0) {
		m_pos.x = 0;
		m_pos.y = 0;
		return m_pos;
	}

	//���C���O���Ɍ������ď���
	while (true) {

		moveradius++;

		//�^�[�Q�b�g�̐ݒ�
		float rad = ((float)element / GAME_INFO::RAYNUM) * (3.14159f * 2.0f);
		m_pos.x = moveradius * cos(rad) + pos.x;
		m_pos.y = moveradius * sin(rad) + (pos.y-15);

		//���C�ƂԂ���I�u�W�F�N�g�̔���`�F�b�N
		Game::gameInstance->GetCollisionMNG()->RayToHitObjectCheck(this);

		//�ő�l�ɂȂ�����I������
		if (radius == moveradius) {
			break;
		}

		//�ȉ��d���̂ŉ񐔂��i��
		if (moveradius % 2 != 0)
			continue;

		//�����蔻��̃`�F�b�N
		if (Game::gameInstance->GetCollisionMNG()->RayHitCheck(m_pos)){


			if (moveradius >= (radius - 8)) {
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

void RayCast::NoHitCollision(Actor* other, E_TAG tag)
{
}
