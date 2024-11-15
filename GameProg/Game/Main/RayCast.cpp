#include "Framework.h"

RayCast::RayCast(Point pos,E_TAG tag)
	:Actor(pos)
	,frame(0)
	,m_tag(tag)
	,m_isRayStart(false)
{
	//当たり判定
	/*auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, {5,5}, E_TAG::RAY));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);*/
}

RayCast::~RayCast()
{

}

void RayCast::Update()
{
	//レイとぶつかるオブジェクトの判定チェック
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
	//位置の更新
	m_pos = pos;
	m_moveradius = 0;
	m_isRayStart = true;

	//レイを消す
	if (radius == 0) {
		m_pos.x = -10.0f;
		m_pos.y = -10.0f;
		m_isRayStart = false;
		return m_pos;
	}

	//レイを外側に向かって消す
	while (true) {

		++m_moveradius;

		//ターゲットの設定
		m_rad = ((float)element / GAME_INFO::RAYNUM) * (3.14f * 2.0f);
		m_pos.x = m_moveradius * cos(m_rad) + pos.x;
		m_pos.y = m_moveradius * sin(m_rad) + (pos.y-15);

		//レイとぶつかるオブジェクトの判定チェック
		Game::gameInstance->GetCollisionMNG()->RayToHitObjectCheck(this);

		//最大値になったら終了する
		if (radius == m_moveradius) {
			break;
		}

		//以下重いので回数を絞る
		if (m_moveradius % 2 != 0)
			continue;

		//当たり判定のチェック
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
