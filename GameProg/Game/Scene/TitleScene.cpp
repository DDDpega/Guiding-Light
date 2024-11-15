#include "Framework.h"


TitleScene::TitleScene()
	:Scene("タイトルシーン")
	, m_nowcursor(0)
	, m_waitTime()
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Scene::Initialize();
	
	m_waitTime = VideoInfo::WAIT_TIME;
	
	m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);

	//UIを表示する
	m_titleUI = shared_ptr<TitleUI>(new TitleUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(m_titleUI);

	m_bgm->SoundPlay(Sound::LOOP);
	PlayMovie(VideoInfo::VIDEO_PATH, 1, DX_MOVIEPLAYTYPE_NORMAL);
}

void TitleScene::Update()
{
	Scene::Update();

	if (m_waitTime-- < 0&&!m_titleUI->m_isVideo) {
		m_titleUI->m_isVideo = true;
	}

	if (m_titleUI->m_isVideo) {
		
	}

}

void TitleScene::Draw()
{
	Scene::Draw();
}