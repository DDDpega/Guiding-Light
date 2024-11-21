#include "Framework.h"

Ladder::Ladder(Point pos, int num)
	:Actor(pos)
	, m_num(num)
	, m_pos(pos)
{
}

Ladder::~Ladder()
{
}

void Ladder::Initialize()
{
	Actor::Initialize();
	m_pos.x += (MAPCHIP_WIDTH / 2);
	SceneManeger::gameScene->GetPlayer()->AddisLadder(m_num, false, m_pos);

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, LADDER_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::LADDER],0, E_PIVOT::LEFTUP, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//ボックスコリジョン生成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 20,20 }, LADDER_INFO::COLLISION_SIZE, E_TAG::LADDER));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
}

void Ladder::Update()
{
	Actor::Update();
}

void Ladder::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	//プレイヤーに当たったときの判定
	if (tag == E_TAG::PLAYER && m_isActive) {
		SceneManeger::gameScene->GetPlayer()->SetisLadder(m_num, true);
		
	}
}

void Ladder::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	//プレイヤーが外れたときの判定
	if (tag == E_TAG::PLAYER && m_isActive) {
		SceneManeger::gameScene->GetPlayer()->SetisLadder(m_num, false);

	}
}
