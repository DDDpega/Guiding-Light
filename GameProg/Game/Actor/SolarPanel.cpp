#include "Framework.h"

SolarPanel::SolarPanel(Point pos)
	:Actor(pos)
	
{
}

SolarPanel::~SolarPanel()
{
}

void SolarPanel::Initialize()
{
	Actor::Initialize();

	m_soundFrame = 0;

	

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, SOLARPANEL_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SOLARPANEL],0, E_PIVOT::LEFTUP, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	auto pos = m_pictureCmp->m_picture->GetPos();
	pos.y -= 10;

	m_pictureCmp2 = shared_ptr<Picture>(new Picture(pos, SOLARPANEL_INFO::SIZE, &UI::GAME_LIST[UI::GAME_TYPE::THUNDER], 0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	Game::gameInstance->GetPictureMNG()->AddPicture(m_pictureCmp2);


	//画像サイズ
	LONG x = (m_pictureCmp->m_picture ->m_pictureSizeX * m_pictureCmp->m_picture->m_size) / 2;
	LONG y = (m_pictureCmp->m_picture->m_pictureSizeY * m_pictureCmp->m_picture->m_size) / 2;

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 20,20 }, SOLARPANEL_INFO::COLLISION_SIZE, E_TAG::SOLARPANEL));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//何秒効果時間があるか
	m_maxTime = Game::gameInstance->GetStatus()->SOLARPANELBLOCK_MAXTIME;

	//チャージ音
	m_spanelSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::SOLARPANEL ], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_spanelSound);

	//床出現音
	m_floorSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::LAUNCH], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_floorSound);
}

void SolarPanel::Update()
{
	Actor::Update();
	


	//供給中なら
	if (m_shareNow) {
		m_isTrigger = true;
		m_pictureCmp2->SetisVisible(true);
		if (m_soundFrame-- < 0&& !m_isTrigger) {
			m_spanelSound->SoundStop();
			m_soundFrame = SOLARPANEL_INFO::PANELFRAME;
			m_spanelSound->SoundPlay();
		}
		
	}
	else {
		m_isTrigger = false;
		m_spanelSound->SoundStop();
		m_soundFrame = 0;
		m_pictureCmp2->SetisVisible(false);
	}

	m_shareNow = false;
	
}

void SolarPanel::SetParam(E_SOLARPANEL_KIND kind)
{
	m_Kind = kind;
}

void SolarPanel::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if ((tag == E_TAG::PLAYER_RAY||tag==E_TAG::FIGURERAY || tag==E_TAG::SPOT_LIGHT_RAY) ) {
		m_shareNow = true;
	}
}

void SolarPanel::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{

}


