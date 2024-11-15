#include "Framework.h"

SoundManager::SoundManager()
	:m_masterVolume(255)
	, m_bgmVolume(255)
	, m_seVolume(255)
{
}

SoundManager::~SoundManager()
{
	for (auto& s : m_sounds) {
		s.reset();
	}
	m_sounds.clear();
}

void SoundManager::Initialize()
{
	m_sounds.clear();

	//各サウンドをロードする
	for (auto& list : SOUND::BGM_LIST) {
		for (auto& path : list.path) {
			SOUND::BGM_LIST[list.type].handle.push_back(LoadSoundMem(path));
		}
	}
	for (auto& list : SOUND::GAMESE_LIST) {
		for (auto& path : list.path) {
			SOUND::GAMESE_LIST[list.type].handle.push_back(LoadSoundMem(path));
		}
	}
	for (auto& list : SOUND::PLAYERSE_LIST) {
		for (auto& path : list.path) {
			SOUND::PLAYERSE_LIST[list.type].handle.push_back(LoadSoundMem(path));
		}
	}
	for (auto& list : SOUND::GIMMICK_LIST) {
		for (auto& path : list.path) {
			SOUND::GIMMICK_LIST[list.type].handle.push_back(LoadSoundMem(path));
		}
	}
	
}

void SoundManager::AddSoundList(shared_ptr<Sound> sound)
{
	sound->Initialize();
	m_sounds.push_back(sound);
}

void SoundManager::SetVolume()
{

	for (auto& sound : m_sounds) {
		switch (sound->GetSoundType())
		{
		case Sound::BGM:
			ChangeVolumeSoundMem(int(m_bgmVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 10) / 10), sound->GetSound());
			break;
		case Sound::SE:
			ChangeVolumeSoundMem(int(m_seVolume * (float)(m_masterVolume / MAXVOLUME)), sound->GetSound());
			break;
		}
	}
}
// 各種音量の設定
void SoundManager::ChangeVolume(int volume, Sound::E_Sound soundType)
{
	
	for (auto& sound : m_sounds) {
		//SoundTypeが同じなら
		if (sound->GetSoundType() == soundType) {
			//volumeをマスターボリュームの割合で減らして音量をセットする
			ChangeVolumeSoundMem(volume * (float)(m_masterVolume / MAXVOLUME), sound->GetSound());
		}
	}
	switch (soundType)
	{
	case Sound::BGM:
		m_bgmVolume = volume;
		break;
	case Sound::SE:
		m_seVolume = volume;
		break;
	}

}


void SoundManager::SetMasterVolume(int volume)
{
	//マスター音量を変更
	m_masterVolume = volume;

	//マスターに合わせてBGMとSEを変更
	for (auto& sound : m_sounds) {
		switch (sound->GetSoundType())
		{
		case Sound::BGM:
			//volumeをマスターボリュームの割合で減らして音量をセットする
			ChangeVolumeSoundMem(m_bgmVolume * (float)(m_masterVolume / MAXVOLUME), sound->GetSound());
			break;
		case Sound::SE:
			//volumeをマスターボリュームの割合で減らして音量をセットする
			ChangeVolumeSoundMem(m_seVolume * (float)(m_masterVolume / MAXVOLUME), sound->GetSound());
			break;
		}


	}

}

void SoundManager::ClearSound()
{
	SoundStopAll();
	m_sounds.clear();
}

void SoundManager::SoundStopAll()
{
	for (auto& sound : m_sounds) {
		// 再生を止めます
		StopSoundMem(sound->GetSound());
	}
}