#include "Framework.h"

SolarPanel::SolarPanel(Point pos)
	:Actor(pos)
	, m_isTrigger(false)
{
}

SolarPanel::~SolarPanel()
{
}

void SolarPanel::Initialize()
{
	Actor::Initialize();

	m_soundFrame = 0;

	

	//�摜�R���|�[�l���g
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, SOLARPANEL_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::SOLARPANEL],0, E_PIVOT::LEFTUP, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//�摜�T�C�Y
	LONG x = (m_pictureCmp->m_picture ->m_pictureSizeX * m_pictureCmp->m_picture->m_size) / 2;
	LONG y = (m_pictureCmp->m_picture->m_pictureSizeY * m_pictureCmp->m_picture->m_size) / 2;

	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 20,20 }, SOLARPANEL_INFO::COLLISION_SIZE, E_TAG::SOLARPANEL));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//���b���ʎ��Ԃ����邩
	m_maxTime = Game::gameInstance->GetStatus()->SOLARPANELBLOCK_MAXTIME;

	//�`���[�W��
	m_spanelSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::SOLARPANEL ], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_spanelSound);

	//���o����
	m_floorSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::LAUNCH], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_floorSound);
}

void SolarPanel::Update()
{
	Actor::Update();

	//�������Ԃ��o�߂�����
	if (m_keepTime >= m_maxTime) {
		if (!m_isTrigger) {
			m_spanelSound->SoundStop();
			m_floorSound->SoundPlay();
		}
		m_isTrigger = true;
		
	}

	//�������Ȃ�
	if (m_shareNow) {
		m_keepTime++;
		if (m_soundFrame-- < 0&& !m_isTrigger) {
			m_spanelSound->SoundStop();
			m_soundFrame = SOLARPANEL_INFO::PANELFRAME;
			m_spanelSound->SoundPlay();
		}
		
	}
	else {
		m_spanelSound->SoundStop();
		m_soundFrame = 0;
	}
}

void SolarPanel::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER_RAY && SceneManeger::gameScene->GetPlayer()->GetLightOn() &&
		m_keepTime < m_maxTime) {
		m_shareNow = true;
	}
}

void SolarPanel::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{


}

bool SolarPanel::GetIsTrigger()
{
	return m_isTrigger;
}
