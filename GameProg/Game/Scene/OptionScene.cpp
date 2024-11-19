#include "Framework.h"
#include "OptionScene.h"

OptionScene::OptionScene()
	:Scene("オプション")
{
}

OptionScene::~OptionScene()
{
}

void OptionScene::Initialize()
{
	Scene::Initialize();
	if (Game::gameInstance->GetSoundMNG()->GetSoundLength() == 0)
	{
		m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
		Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
		m_bgm->SoundPlay(Sound::LOOP);
	}

	//UIを表示する
	auto optionUI = shared_ptr<OptionUI>(new OptionUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(optionUI);
}

void OptionScene::Update()
{
	Scene::Update();
}

void OptionScene::Draw()
{
	Scene::Draw();
}
