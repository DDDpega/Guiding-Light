#include "Framework.h"
#include "CreditScene.h"

CreditScene::CreditScene()
	:Scene("クレジット")
{
}

CreditScene::~CreditScene()
{
}

void CreditScene::Initialize()
{
	Scene::Initialize();
	int a = Game::gameInstance->GetSoundMNG()->GetSoundLength();
	if (Game::gameInstance->GetSoundMNG()->GetSoundLength() == 0)
	{
		m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
		Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
		m_bgm->SoundPlay(Sound::LOOP);
	}

	//UIを表示する
	auto creditUI = shared_ptr<CreditUI>(new CreditUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(creditUI);
}

void CreditScene::Update()
{
	Scene::Update();
}

void CreditScene::Draw()
{
	Scene::Draw();
}
