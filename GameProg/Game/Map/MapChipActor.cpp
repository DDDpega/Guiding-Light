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

	SpawnMove(1, 1);

	//“–‚½‚è”»’è
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, {40,40}, E_TAG::MAP));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddMapCollisionList(collision);
}

void MapChipActor::Update()
{
	Actor::Update();
}

void MapChipActor::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void MapChipActor::NoHitCollision(Actor* other, E_TAG tag)
{
}
