#include "Framework.h"
#include "Puddle.h"

Puddle::Puddle(Point pos)
	:Actor(pos)
{
}

Puddle::~Puddle()
{
}

void Puddle::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, PUDDLE_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA], 0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, PUDDLE_INFO::COLLISION_SIZE, E_TAG::PUDDLE));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

}

void Puddle::Update()
{
	Actor::Update();
}

void Puddle::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	//プレイヤーが光らせていたら
	if (tag == E_TAG::PLAYER_RAY && SceneManeger::gameScene->GetPlayer()->GetLightOn()){
		SceneManeger::gameScene->GameOver();
	}
}

void Puddle::NoHitCollision(Actor* other, E_TAG tag)
{
}
