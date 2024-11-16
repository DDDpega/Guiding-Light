#include "Framework.h"


TitleScene::TitleScene()
	:Scene("�^�C�g���V�[��")
	, m_nowcursor(0)
{
	//Game::gameInstance->GetSoundMNG()->SetMasterVolume(100);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Scene::Initialize();
	
	

	m_waittime = VideoInfo::WAIT_TIME;
	
	if (Game::gameInstance->GetSoundMNG()->GetSoundLength() == 0)
	{
		m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
		Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
		m_bgm->SoundPlay(Sound::LOOP);
	}

	//UI��\������
	auto titleUI = shared_ptr<TitleUI>(new TitleUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(titleUI);

	

	
	
}

void TitleScene::Update()
{
	Scene::Update();
	
	//���Ԍo�߂Ńf�����[�r�[�𗬂��V�[����
	if (m_waittime-- < 0) {
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLEVIDEO);
	}

}

void TitleScene::Draw()
{
	Scene::Draw();
}