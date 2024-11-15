#include "Framework.h"


TitleScene::TitleScene()
	:Scene("�^�C�g���V�[��")
	, m_nowcursor(0)
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Scene::Initialize();
	
	Game::gameInstance->GetSoundMNG()->SetMasterVolume(100);

	m_waittime = VideoInfo::WAIT_TIME;
	
	m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);

	//UI��\������
	auto titleUI = shared_ptr<TitleUI>(new TitleUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(titleUI);

	m_bgm->SoundPlay(Sound::LOOP);

	
	
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