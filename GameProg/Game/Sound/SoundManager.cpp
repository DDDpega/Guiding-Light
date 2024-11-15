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
// �e�퉹�ʂ̐ݒ�
void SoundManager::ChangeVolume(int volume, Sound::E_Sound soundType)
{
	
	for (auto& sound : m_sounds) {
		//SoundType�������Ȃ�
		if (sound->GetSoundType() == soundType) {
			//volume���}�X�^�[�{�����[���̊����Ō��炵�ĉ��ʂ��Z�b�g����
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
	//�}�X�^�[���ʂ�ύX
	m_masterVolume = volume;

	//�}�X�^�[�ɍ��킹��BGM��SE��ύX
	for (auto& sound : m_sounds) {
		switch (sound->GetSoundType())
		{
		case Sound::BGM:
			//volume���}�X�^�[�{�����[���̊����Ō��炵�ĉ��ʂ��Z�b�g����
			ChangeVolumeSoundMem(m_bgmVolume * (float)(m_masterVolume / MAXVOLUME), sound->GetSound());
			break;
		case Sound::SE:
			//volume���}�X�^�[�{�����[���̊����Ō��炵�ĉ��ʂ��Z�b�g����
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
		// �Đ����~�߂܂�
		StopSoundMem(sound->GetSound());
	}
}