#include "Framework.h"

LineRayCast::LineRayCast(Point pos, E_TAG tag)
	:Actor(pos)
{
}

LineRayCast::~LineRayCast()
{
}

void LineRayCast::Initialize()
{
	Actor::Initialize();
}

void LineRayCast::Update()
{
	Actor::Update();
}

void LineRayCast::Draw()
{
	Actor::Draw();
}

void LineRayCast::Run(Point pos, int radius)
{
	
}

void LineRayCast::RayStart(Point pos, int radius, RayCast& ray)
{
}

void LineRayCast::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void LineRayCast::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
