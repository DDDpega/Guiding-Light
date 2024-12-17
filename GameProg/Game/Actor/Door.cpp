#include "Framework.h"

Door::Door(Point pos)
	:Actor(pos)
	, m_teleportPos(Point{0,0})
{
}

Door::~Door()
{
}

void Door::Initialize()
{
	Actor::Initialize();

	//m_soundFrame = 0;

	m_isDoor = false;

	m_doorFrame = 0;

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, DOOR_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::DOOR], 0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, DOOR_INFO::COLLISION_SIZE, E_TAG::DOOR));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	m_isLightOn = false;

}

void Door::Update()
{
	Actor::Update();


	if (m_isDoor) {
		SceneManeger::gameScene->GetPlayer()->m_isDoorTouch = true;
		switch (m_doorFrame++)
		{
		case 10:
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::DOOR], 1);
			break;
		case 20:
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::DOOR], 2);
			m_isLightOn = SceneManeger::gameScene->GetPlayer()->GetLightOn();
			break;
		case 25:
			if(m_isLightOn)SceneManeger::gameScene->GetPlayer()->m_lightCmp->ChangeLightONOFF();
			break;
		case 30:
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::DOOR], 0);
			
			
			//teleport
			SceneManeger::gameScene->GetPlayer()->SetPos(m_teleportPos);
			

			break;
		case 40:
			SceneManeger::gameScene->GetPlayer()->m_isDoorTouch = false;
			m_isDoor = false;
			m_doorFrame = 0;
			if (m_isLightOn)SceneManeger::gameScene->GetPlayer()->m_lightCmp->ChangeLightONOFF();
			break;
		}
		
	}
	//m_isDoor = false;
}

void Door::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER && Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		m_isDoor = true;
		
	}
}

void Door::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{


}
