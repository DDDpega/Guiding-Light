#include "Framework.h"


Actor::Actor(Point pos)
	:m_pos(pos)
{
	
}

Actor::~Actor()
{
	for (auto& c : m_componentList) {
		c.reset();
	}
	m_componentList.clear();
}

void Actor::Initialize()
 {
	m_isActive = true;
}

void Actor::Update()
{
	//コンポーネントリストの更新処理
	for (auto& c : m_componentList) {
		c->Update();
	}
}


void Actor::Draw()
{
	//コンポーネントリストの描画
	for (auto& c : m_componentList) {
		c->Draw();
	}
}

void Actor::Move()
{
	//printfDx("ポジションChange\n");
	m_pos.x += m_vx;	//右移動
	m_pos.y += m_vy;	//下移動
}


void Actor::HitCollision(Actor* other,E_TAG tag,E_TAG selftag)
{
}

bool Actor::GetIsMove(string shaft)
{
	if (shaft == "x")return m_isMove_x;
	if (shaft == "y")return m_isMove_y;
}

void Actor::SpawnMove(int x,int y)
{
	//ピボットが真ん中なら画像の幅分右下にずらす
	m_pos.x += 20*x;
	m_pos.y += 20*y;
}

void Actor::AddComponent(std::shared_ptr<Component> component)
{
	//コンポーネントのList追加と初期化
	component->Initialize();
	m_componentList.push_back(component);
}
