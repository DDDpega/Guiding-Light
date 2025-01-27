#include "Framework.h"

OnSoundCmp::OnSoundCmp(Actor* actor)
	:Component(actor)
	, m_isSoundOn(false)

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
	m_isSoundOn = true;
}

void OnSoundCmp::OffSound()
{
	//�Ȃ��Ă郊�X�g���玩�����폜
	auto list = SceneManeger::gameScene->m_onSoundCmp;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == this) {
			list.erase(list.begin()+i);
			m_isSoundOn = false;

			break;
		}
	}
	SceneManeger::gameScene->m_onSoundCmp = list;
}
