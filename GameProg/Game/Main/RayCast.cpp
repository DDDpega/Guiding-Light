#include "Framework.h"

RayCast::RayCast(POINT pos)
	:Actor(pos)
	,frame(0)
{
	//当たり判定
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, {5,5}, E_TAG::RAY));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
}

RayCast::~RayCast()
{

}

POINT RayCast::RayStart(POINT pos,int radius,int element)
{
	//位置の更新
	m_pos = pos;
	auto moveradius = 0;

	while (true) {

		moveradius++;

		//ターゲットの設定
		float rad = ((float)element / GAME_INFO::RAYNUM) * (3.14159f * 2.0f);
		m_pos.x = moveradius * cos(rad) + pos.x;
		m_pos.y = moveradius * sin(rad) + (pos.y-15);

		if (radius == moveradius) {
			break;
		}

		//当たり判定のチェック
		if (Game::gameInstance->GetCollisionMNG()->RayHitCheck(m_pos)){

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
