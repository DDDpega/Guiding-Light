#include "Framework.h"

UserInterface::UserInterface(bool isVisible,bool isInput)
	:Picture(E_SORT::SORT_UI,isVisible)
	,m_isInput(isInput)
	,m_pictureList_UI()
	,m_nowcursor(0)
	, m_alpha(0)
	, m_add(3)
	, m_backGround()

{
}

UserInterface::~UserInterface()
{
	
}

void UserInterface::Initialize()
{
	m_nowcursor = 0;

	m_isChangeScene = false;

	m_csframe = 30;

	m_sound[0] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::DECISION], Sound::E_Sound::SE, 0));
	m_sound[1] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::CANCEL], Sound::E_Sound::SE, 0));
	m_sound[2] = shared_ptr<Sound>(new Sound(SOUND::GAMESE_LIST[SOUND::GAMESE_TYPE::CURSORCONTROL], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[0]);
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[1]);
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_sound[2]);
	auto a = Game::gameInstance->GetSoundMNG()->GetSoundLength();
	auto b = a;
	for (int i = 0; i < sizeof(m_isSoundPlay); i++) {
		m_isSoundPlay[i] = false;
	}
		
	m_pictureList_UI.clear();
}

void UserInterface::Update()
{
	for (int i = 0; i < sizeof(m_isSoundPlay); i++) {
		if (m_isSoundPlay[i]) {
			m_sound[i]->SoundPlay();
			m_isSoundPlay[i] = false;
		}
	}
	

	//ピクチャーリストの更新
	for (auto& list : m_pictureList_UI) {
		list->Update();
	}
}

void UserInterface::Draw()
{
	//ピクチャーリストの描画
	for (auto& list : m_pictureList_UI) {
		if (list->GetisVisible()) {
			list->Draw();
		}
	}
}

void UserInterface::AddPictureInUI(shared_ptr<Picture> picture)
{
	picture->Initialize();
	m_pictureList_UI.push_back(picture);
}
