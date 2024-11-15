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
	DrawGraph(0, 0, m_videoHandle, TRUE);
}