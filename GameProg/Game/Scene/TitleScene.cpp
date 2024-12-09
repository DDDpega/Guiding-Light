#include "Framework.h"


TitleScene::TitleScene()
	:Scene("タイトルシーン")
	, m_nowcursor(0)
	, m_isFirst(true)
{
	//Game::gameInstance->GetSoundMNG()->SetMasterVolume(100);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Scene::Initialize();
	
	

	
	
	if (Game::gameInstance->GetSoundMNG()->GetSoundLength() == 0)
	{
		m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
		Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
		m_bgm->SoundPlay(Sound::LOOP);
	}

	//UIを表示する
	auto titleUI = shared_ptr<TitleUI>(new TitleUI(m_isFirst));
	Game::gameInstance->GetPictureMNG()->AddPicture(titleUI);

	
	m_isFirst = false;
	
	
}

void TitleScene::Update()
{
	Scene::Update();
	
	

}

void TitleScene::Draw()
{
	Scene::Draw();
}