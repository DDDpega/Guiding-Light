#include "Framework.h"

MapChipActor::MapChipActor(Point pos)
	:Actor(pos)
{
}

MapChipActor::~MapChipActor()
{
}

void MapChipActor::Initialize()
{
	Actor::Initialize();

	//当たり判定
	m_collisionCmp = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 20,20 }, { 40,40 }, E_TAG::MAP));
	Actor::AddComponent(m_collisionCmp);


	auto collisionList = Game::gameInstance->GetCollisionMNG()->m_mapCollision;
	auto collisionCheck = false;
	for (auto i = collisionList.cbegin(); i != collisionList.cend(); i++) {

		auto other = i->get();

		//左右の検索
		if (other->m_collision.right == m_collisionCmp->m_collision.left &&
				other->m_collision.top == m_collisionCmp->m_collision.top &&
				other->m_collision.bottom== m_collisionCmp->m_collision.bottom) {

			other->m_size.x += 40;
			other->m_offset.x += 20;
			other->ChangeCollision();
			collisionCheck = true;
			break;
		}

		//上下の検索
		if (other->m_collision.right	 == m_collisionCmp->m_collision.right &&
				other->m_collision.left  == m_collisionCmp->m_collision.left &&
				other->m_collision.bottom == m_collisionCmp->m_collision.top) {

			other->m_size.y += 40;
			other->m_offset.y += 20;
			other->ChangeCollision();
			collisionCheck = true;
			break;
		}
	}

	if (!collisionCheck) {
		Game::gameInstance->GetCollisionMNG()->AddMapCollisionList(m_collisionCmp);
	}
	else {
		m_isActive = false;
	
	}

	//フォントの描画
	m_fontHandle = CreateFontToHandle("MS ゴシック", 20, 1);

}

void MapChipActor::Update()
{
	Actor::Update();
}

void MapChipActor::Draw()
{
	Actor::Draw();

	//if (GAME_INFO::DEBUG) {
	//	DrawFormatStringFToHandle(m_collisionCmp->m_collision.right, m_pos.y, GetColor(255, 255, 255), m_fontHandle, "RIGHT : %f", m_collisionCmp->m_collision.right);
	//	DrawFormatStringFToHandle(m_collisionCmp->m_collision.left, m_pos.y, GetColor(255, 255, 255), m_fontHandle, "LEFT : %f", m_collisionCmp->m_collision.left);
	//	//DrawFormatStringFToHandle(m_pos.x+m_collisionCmp->m_offset.x, m_collisionCmp->m_collision.top, GetColor(255, 255, 255), m_fontHandle, "TOP : %f", m_collisionCmp->m_collision.top);
	//	//DrawFormatStringFToHandle(m_pos.x + m_collisionCmp->m_offset.x, m_collisionCmp->m_collision.bottom, GetColor(255, 255, 255), m_fontHandle, "BOTTOM : %f", m_collisionCmp->m_collision.bottom);
	//}
}

void MapChipActor::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void MapChipActor::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
