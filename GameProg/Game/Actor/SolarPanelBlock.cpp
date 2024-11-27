#include"Framework.h"

SolarPanelBlock::SolarPanelBlock(Point pos,bool isBlock, Scene* scene)
	:Actor(pos)
	,m_isBlock(isBlock)
	, m_scene(scene)
{
}

SolarPanelBlock::~SolarPanelBlock()
{
}

void SolarPanelBlock::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, SOLARPANELBLOCK_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SOLARPANEL_BLOCK], 0, E_PIVOT::LEFTUP, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);



	//m_pictureCmp->m_picture->SetisVisible(m_isBlock);
}

void SolarPanelBlock::Update()
{
	Actor::Update();
	auto isblock = false;
	bool isTrigger = false;

	for (auto s : static_cast<GameScene*>(m_scene)->m_solarpanel) {
		isTrigger = s->GetIsTrigger();
		if (isTrigger) {
			break;
		}
	}

	//最初にブロックがあるかどうか
	if (m_isBlock) {
		//当たっていいない時
		isblock = !isTrigger;
		
	}
	else {
		//当たっているとき
		isblock = isTrigger;
	}

	if (isblock) {
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SOLARPANEL_BLOCK], 0);
	}
	else {
		m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SOLARPANEL_BLOCK], 1);
	}
}

void SolarPanelBlock::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void SolarPanelBlock::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
