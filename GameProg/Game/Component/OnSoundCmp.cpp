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
	SceneManeger::gameScene->m_onSoundObj.push_back(m_actor);
}

void OnSoundCmp::OffSound()
{
	//なってるリストから自分を削除
	auto soundList = SceneManeger::gameScene->m_onSoundObj;
	for (int i = 0; i < soundList.size(); i++) {
		if (soundList[i] == m_actor) {
			SceneManeger::gameScene->m_onSoundObj.erase(soundList.begin()+i);
		}
	}
}
