#include "Framework.h"

Sound::Sound(SOUND_TYPE soundType, E_Sound playType, int num)
	:m_soundType(soundType)
	, m_playType(playType)
	, m_pitch(-1)
	, m_volumeRate(1)
	, m_num(num)
	, m_volume(255)
{
	
}


Sound::~Sound()
{
	// サウンドハンドルの削除
	//DeleteSoundMem(m_sound);
}

void Sound::Initialize() throw()
{
	ChangeSound(m_soundType, m_num);


	//周波数を代入する
	m_pitch = GetFrequencySoundMem(m_sound);
}


void Sound::SoundPlay(E_PlaySound type)
{
	
	
	

	
	
	switch (type)
	{
	case Sound::NOMAL:
		// 読みこんだ音をノーマル再生します
		PlaySoundMem(m_sound, DX_PLAYTYPE_NORMAL);
		break;
	case Sound::BACK:
		// 読みこんだ音をバックグラウンド再生します
		PlaySoundMem(m_sound, DX_PLAYTYPE_BACK);
		break;
	case Sound::LOOP:
		// 読みこんだ音をループ再生します
		PlaySoundMem(m_sound, DX_PLAYTYPE_LOOP);
		break;
	}
	m_volume = Game::gameInstance->GetSoundMNG()->GetVolume(m_playType);
	
	SetPlaySoundVolume(m_volumeRate);

	//周波数に変更する
	//SetFrequencySoundMem(m_pitch, m_sound);
	
}

void Sound::SoundStop()
{
	// 再生を止めます
	StopSoundMem(m_sound);
}

void Sound::AddPitch(int pitch,bool isReset)
{
	if (isReset == true) {
		//周波数を代入する
		m_pitch = GetFrequencySoundMem(m_sound);
	}
	else
	{
		//ピッチ数を上げる
		m_pitch += pitch;
	}
}

void Sound::SetPlaySoundVolume(float vol)
{
	m_volumeRate = vol;

	ChangeVolumeSoundMem(int(m_volume * m_volumeRate), m_sound);
}

void Sound::ChangeSound(SOUND_TYPE soundType, int num)
{
	m_soundType = soundType;
	
	m_num = num;

	m_sound = m_soundType.handle[m_num];
}
