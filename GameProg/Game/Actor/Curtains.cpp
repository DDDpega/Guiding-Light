#include "Framework.h"

Curtains::Curtains(Point pos)
	:Actor(pos)
{
}

Curtains::~Curtains()
{
}

void Curtains::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PASTIME_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOAST_PASTIME], 0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, PASTIME_INFO::COLLISION_SIZE, E_TAG::PASTIME_GHOST));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);
	Game::gameInstance->GetCollisionMNG()->AddMapCollisionList(collision);

	//暗闇中に見える画像の生成
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::GOALLIGHT], 0));
	Actor::AddComponent(m_darkPictureCmp);
}

void Curtains::Update()
{
	Actor::Update();
}

void Curtains::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void Curtains::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
