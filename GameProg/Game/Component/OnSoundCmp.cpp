#include "Framework.h"

OnSoundCmp::OnSoundCmp(Actor* actor)
	:Component(actor)
{
}

OnSoundCmp::~OnSoundCmp()
{
}

void OnSoundCmp::Draw()
{
	Component::Draw();
}

void OnSoundCmp::OnSound()
{
	//�����̐e���Ȃ��Ă郊�X�g�ɑ���
	SceneManeger::gameScene->m_onSoundCmp.push_back(this);
}

void OnSoundCmp::OffSound()
{
	//�Ȃ��Ă郊�X�g���玩�����폜
	auto soundList = SceneManeger::gameScene->m_onSoundCmp;
	for (int i = 0; i < soundList.size(); i++) {
		if (soundList[i] == this) {
			SceneManeger::gameScene->m_onSoundCmp.erase(soundList.begin()+i);
		}
	}
}
