#include "Framework.h"


BackGround::BackGround(Point pos)
	:Actor(pos)
{

}

BackGround::~BackGround()
{
}

void BackGround::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, BACKGROUND_INFO::SIZE, ILLUST::STAGE_LIST[ILLUST::STAGE_TYPE::BACKGROUND],0, E_PIVOT::LEFTUP, E_SORT::SORT_BACKGROUND));
	AddComponent(m_pictureCmp);
}


void BackGround::Update()
{
	Actor::Update();
}

void BackGround::NoHitCollision(Actor* other, E_TAG tag)
{
}

