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
	// �T�E���h�n���h���̍폜
	//DeleteSoundMem(m_sound);
}

void Sound::Initialize() throw()
{
	ChangeSound(m_soundType, m_num);


	//���g����������
	m_pitch = GetFrequencySoundMem(m_sound);
}


void Sound::SoundPlay(E_PlaySound type)
{
	
	
	

	
	
	switch (type)
	{
	case Sound::NOMAL:
		// �ǂ݂��񂾉����m�[�}���Đ����܂�
		PlaySoundMem(m_sound, DX_PLAYTYPE_NORMAL);
		break;
	case Sound::BACK:
		// �ǂ݂��񂾉����o�b�N�O���E���h�Đ����܂�
		PlaySoundMem(m_sound, DX_PLAYTYPE_BACK);
		break;
	case Sound::LOOP:
		// �ǂ݂��񂾉������[�v�Đ����܂�
		PlaySoundMem(m_sound, DX_PLAYTYPE_LOOP);
		break;
	}
	m_volume = Game::gameInstance->GetSoundMNG()->GetVolume(m_playType);
	
	SetPlaySoundVolume(m_volumeRate);

	//���g���ɕύX����
	//SetFrequencySoundMem(m_pitch, m_sound);
	
}

void Sound::SoundStop()
{
	// �Đ����~�߂܂�
	StopSoundMem(m_sound);
}

void Sound::AddPitch(int pitch,bool isReset)
{
	if (isReset == true) {
		//���g����������
		m_pitch = GetFrequencySoundMem(m_sound);
	}
	else
	{
		//�s�b�`�����グ��
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
