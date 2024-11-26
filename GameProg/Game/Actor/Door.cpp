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

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, DOOR_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::DOOR], 0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, DOOR_INFO::COLLISION_SIZE, E_TAG::DOOR));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	//チャージ音
	/*m_spanelSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::SOLARPANEL], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_spanelSound);*/
}

void Door::Update()
{
	Actor::Update();
}

void Door::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER && Game::gameInstance->GetInputMNG()->Click(L"UP")) {
		//teleport
		SceneManeger::gameScene->GetPlayer()->SetPos(m_teleportPos);
		
	}
}

void Door::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{


}
