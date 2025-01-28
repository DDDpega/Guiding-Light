#include "Framework.h"

MusicalNote::MusicalNote(Point pos)
	: Actor(pos)
	, m_frameCnt(0)
{
}

MusicalNote::~MusicalNote()
{
}

void MusicalNote::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, MUSICAL_NOTE_INFO::SIZE, UI::GAME_LIST[UI::GAME_TYPE::MUSICAL_NOTE], 0, E_PIVOT::CENTER, E_SORT::SORT_PISHER));
	AddComponent(m_pictureCmp);

	//暗闇中に見える画像の生成
	m_darkPictureCmp = shared_ptr<DarkPictureCmp>(new DarkPictureCmp(this, UI::GAME_LIST[UI::GAME_TYPE::MUSICAL_NOTE], rand() % 2 + 1));
	Actor::AddComponent(m_darkPictureCmp);

	m_randomPos.x = rand() % 2 + 1;
	m_randomPos.y = rand() % 2 + 1;

	m_randomPos.x *= rand() % 2 == 0 ? -1 : 1;
	m_randomPos.y *= rand() % 2 == 0 ? -1 : 1;
}

void MusicalNote::Update()
{
	Actor::Update();

	if (++m_frameCnt == 30) m_isActive = false;

	m_pos.x += m_randomPos.x;
	m_pos.y += m_randomPos.y;
}

void MusicalNote::Draw()
{
	Actor::Draw();
}

void MusicalNote::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void MusicalNote::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
