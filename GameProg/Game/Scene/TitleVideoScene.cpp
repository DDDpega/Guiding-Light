#include "Framework.h"


TitleVideoScene::TitleVideoScene()
	:Scene("�^�C�g�����[�r�[�V�[��")
{

}

TitleVideoScene::~TitleVideoScene()
{
}

void TitleVideoScene::Initialize()
{
	Scene::Initialize();

	if (Game::gameInstance->GetSoundMNG()->GetSoundLength() == 0)
	{
		m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
		Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
		m_bgm->SoundPlay(Sound::LOOP);
	}

	//UI��\������
	auto videoUI = shared_ptr<TitleVideoUI>(new TitleVideoUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(videoUI);

	m_videoHandle = LoadGraph(VideoInfo::VIDEO_PATH);

	
	
	PlayMovieToGraph(m_videoHandle, DX_MOVIEPLAYTYPE_BCANCEL);

}

void TitleVideoScene::Update()
{
	Scene::Update();
	if (GetMovieStateToGraph(m_videoHandle) == 0) {
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLE);
	}

}

void TitleVideoScene::Draw()
{
	Scene::Draw();
	//���ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// ���[�r�[�f������ʂ����ς��ɕ`�悵�܂�
	DrawExtendGraph(0, 0, WINDOW_INFO::GAME_WIDTH, WINDOW_INFO::GAME_HEIGHT, m_videoHandle, FALSE);
}