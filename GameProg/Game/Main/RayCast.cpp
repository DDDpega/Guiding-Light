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

void RayCast::Initialize()
{
	Actor::Initialize();

	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
		rayPos.push_back(Point{ 0, 0 });
		m_ismapHit.push_back(false);
	}
}

void RayCast::Update()
{
	Actor::Update();

	//レイとぶつかるオブジェクトの判定チェック
	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {
		Game::gameInstance->GetCollisionMNG()->RayToHitObjectCheck(this,i);
	}
}

void RayCast::Draw()
{
	Actor::Draw();

	if (GAME_INFO::DEBUG) {

		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			if (GAME_INFO::DEBUG && m_isRayStart) {
				DrawPixel(rayPos[i].x, rayPos[i].y, GetColor(255, 0, 0));
			}
		}
	}
}

void RayCast::Run(Point pos, int radius)
{

	async(launch::async, RayCast::RayStart, pos, radius , ref(*this));

	/*for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

		if (radius == 0) {
			m_isRayStart = false;
			break;
		}
		m_isRayStart = true;


		rayPos[i] = RayCast::RayStart(pos, radius, i, &rayPos[i]);
	}*/
}

void RayCast::RayStart(Point pos,int radius, RayCast& ray)
{

	vector<Point>& m_pos = ray.rayPos;
	bool& isRayStart = ray.m_isRayStart;
	for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

		ray.m_ismapHit[i]=false;

		//レイを消す
		if (radius == 0) {
			m_pos[i].x = -10.0f;
			m_pos[i].y = -10.0f;
			isRayStart = false;
			continue;
		}

		isRayStart = true;
		auto m_moveradius = 0;


		auto circle = 3.14f * 2.0f;
		float element_f = (float)i;

		//レイを外側に向かって消す
		while (true) {

			++m_moveradius;

			//ターゲットの設定
			auto m_rad = (element_f / GAME_INFO::RAYNUM) * circle;
			m_pos[i].x = m_moveradius * cos(m_rad) + pos.x;
			m_pos[i].y = m_moveradius * sin(m_rad) + (pos.y - 15);

			//レイとぶつかるオブジェクトの判定チェック
			Game::gameInstance->GetCollisionMNG()->RayToHitObjectCheck(&ray,i);

			//最大値になったら終了する
			if (radius == m_moveradius) {
				break;
			}

			//以下重いので回数を絞る
			if (m_moveradius % 2 != 0)
				continue;


			//当たり判定のチェック
			if (Game::gameInstance->GetCollisionMNG()->RayHitCheck(m_pos[i])) {


				if (m_moveradius >= (radius - 8)) {
					break;
				}
				//x+
				if (pos.x <= m_pos[i].x) {
					m_pos[i].x += 10;
				}
				//x-
				else if (pos.x > m_pos[i].x) {
					m_pos[i].x -= 10;
				}
				//y+
				if (pos.y <= m_pos[i].y) {
					m_pos[i].y += 10;
				}
				//y-
				else if (pos.y > m_pos[i].y) {
					m_pos[i].y -= 10;
				}

				break;
			}
		}
	}
}



void RayCast::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}

void RayCast::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
