#include "Framework.h"

SoundManager::SoundManager()
	:m_masterVolume(256)
	, m_bgmVolume(256)
	, m_seVolume(256)
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

	//�e�T�E���h�����[�h����
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
	m_sounds.remove(sound);

	sound->Initialize();
	m_sounds.push_back(sound);
}

void SoundManager::DelateSoundList(shared_ptr<Sound> sound)
{
	
	m_sounds.remove(sound);
}

void SoundManager::SetVolume()
{

	for (auto& sound : m_sounds) {
		switch (sound->GetSoundType())
		{
		case Sound::BGM:
			ChangeVolumeSoundMem(int(m_bgmVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100), sound->GetSound());
			break;
		case Sound::SE:
			ChangeVolumeSoundMem(int(m_seVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100), sound->GetSound());
			break;
		}
	}
}

int SoundManager::GetTypeVolumeNum(Sound::E_Sound soundType) 
{
	int vol;
	switch (soundType)
	{
	case Sound::MASTER:
		vol = m_masterVolume;
		break;

	case Sound::BGM:
		vol = m_bgmVolume;;
		break;
	case Sound::SE:
		vol = m_seVolume;
		break;
	}

	vol /= SETTINGVOLRATE;


	return vol;
}


int SoundManager::GetVolume(Sound::E_Sound soundType)
{
	int vol;
	switch (soundType)
	{
	case Sound::BGM:
		vol=(int(m_bgmVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100));
		break;
	case Sound::SE:
		vol = (int(m_seVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100));
		break;
	}


	return vol;
}

// �e�퉹�ʂ̐ݒ�
void SoundManager::ChangeVolume(int volume, Sound::E_Sound soundType)
{
	
	int vol = volume * SETTINGVOLRATE;

	for (auto& sound : m_sounds) {
		//SoundType�������Ȃ�
		if (sound->GetSoundType() == soundType) {
			//volume���}�X�^�[�{�����[���̊����Ō��炵�ĉ��ʂ��Z�b�g����

			ChangeVolumeSoundMem(int(vol * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100), sound->GetSound());
		}
	}
	switch (soundType)
	{
	case Sound::BGM:
		m_bgmVolume = vol;
		break;
	case Sound::SE:
		m_seVolume = vol;
		break;
	}

	

}


void SoundManager::SetMasterVolume(int volume)
{
	//�}�X�^�[���ʂ�ύX
	m_masterVolume = volume* SETTINGVOLRATE;

	//�}�X�^�[�ɍ��킹��BGM��SE��ύX
	for (auto& sound : m_sounds) {
		switch (sound->GetSoundType())
		{
		case Sound::BGM:
			ChangeVolumeSoundMem(int(m_bgmVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100), sound->GetSound());
			break;
		case Sound::SE:
			ChangeVolumeSoundMem(int(m_seVolume * floor(((float)m_masterVolume / (float)MAXVOLUME) * 100) / 100), sound->GetSound());
			break;
		}


	}

}

void SoundManager::ClearSound()
{
	SoundStopAll();
	for (auto& sound : m_sounds) {
		sound.reset();
	}
	m_sounds.clear();
}

void SoundManager::SoundStopAll()
{
	for (auto& sound : m_sounds) {
		// �Đ����~�߂܂�
		StopSoundMem(sound->GetSound());
	}
}