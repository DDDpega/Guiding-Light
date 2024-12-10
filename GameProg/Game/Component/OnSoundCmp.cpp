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
	//自分の親をなってるリストに送る
	SceneManeger::gameScene->m_onSoundCmp.push_back(this);
}

void OnSoundCmp::OffSound()
{
	//なってるリストから自分を削除
	auto soundList = SceneManeger::gameScene->m_onSoundCmp;
	for (int i = 0; i < soundList.size(); i++) {
		if (soundList[i] == this) {
			SceneManeger::gameScene->m_onSoundCmp.erase(soundList.begin()+i);
		}
	}
}
