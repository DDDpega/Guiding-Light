#include "Framework.h"


BackGround::BackGround(POINT pos)
	:Actor(pos, 12, "Picture/background.png",PIVOT::LEFTUP,SORT::SORT_BACKGROUND)
{

}

BackGround::~BackGround()
{
	Actor::~Actor();
}

void BackGround::Initialize(Game* gameInstance_,Scene* scene)
{
	Actor::Initialize(gameInstance_, scene);
}


void BackGround::Update()
{
	Actor::Update();
}