#include "Framework.h"
StageSelectScene::StageSelectScene()
	:Scene("ゲームセレクト")
{

}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Initialize()
{
	Scene::Initialize();

	m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::STAGESELECT], Sound::E_Sound::BGM, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);
	m_bgm->SoundPlay(Sound::LOOP);

	//UIを表示する
	auto stageSelectUI = shared_ptr<StageSelectUI>(new StageSelectUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(stageSelectUI);
}

void StageSelectScene::Update()
{
	Scene::Update();
}

void StageSelectScene::Draw()
{
	Scene::Draw();
}
