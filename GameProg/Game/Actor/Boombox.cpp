#include "Framework.h"

Boombox::Boombox(Point pos)
	:Actor(pos)
	,m_shareNow(false)
	,m_soundNoteFrame(0)
{
}

Boombox::~Boombox()
{
}

void Boombox::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, BOOMBOX_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::BOOM_BOX], 0, E_PIVOT::CENTER, E_SORT::SORT_SPOTLIGHT));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, BOOMBOX_INFO::COLLISION_SIZE, E_TAG::SPOT_LIGHT));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddBOXCollisionList(collision);

	m_SEsound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::RADIO], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_SEsound);
	//サウンドコンポーネント
	m_soundCmp = shared_ptr<OnSoundCmp>(new OnSoundCmp(this));
	Actor::AddComponent(m_soundCmp);
}

void Boombox::Update()
{
	Actor::Update();
	auto isTrigger = false;

	for (auto s : SceneManeger::gameScene->m_solarpanel) {
		if (s->GetParam() == E_SOLARPANEL_KIND::BOOM_BOX) {
			isTrigger = s->GetIsTrigger();
			if (isTrigger) {

				if (!m_soundCmp->m_isSoundOn) 
					m_soundCmp->OnSound();

				if(CheckSoundMem(m_SEsound->GetSound())==0)
					m_SEsound->SoundPlay(Sound::BACK);

				if (++m_soundNoteFrame % 20 == 0)
					Game::gameInstance->GetActorMNG()->AddActor(shared_ptr<MusicalNote>(new MusicalNote(m_pos)));

				return;
			}
		}
	}

	m_SEsound->SoundStop();
	m_soundCmp->OffSound();
}

void Boombox::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);
}

void Boombox::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
}
