#include "Framework.h"



PictureManeger::PictureManeger()
{

}

PictureManeger:: ~PictureManeger()
{

}


void PictureManeger::Initialize()
{
	m_pictureList.clear();

	//各画像をロードする
	for (auto& list : UI::ALLTYPE_LIST) {
		for (auto& path : list.path) {
			UI::ALLTYPE_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : UI::CREDIT_LIST) {
		for (auto& path : list.path) {
			UI::CREDIT_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : UI::GAME_LIST) {
		for (auto& path : list.path) {
			UI::GAME_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : UI::OPTION_LIST) {
		for (auto& path : list.path) {
			UI::OPTION_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : UI::STAGESELECT_LIST) {
		for (auto& path : list.path) {
			UI::STAGESELECT_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : UI::TITLE_LIST) {
		for (auto& path : list.path) {
			UI::TITLE_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : ILLUST::GIMMICK_LIST) {
		for (auto& path : list.path) {
			ILLUST::GIMMICK_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : ILLUST::PLAYER_LIST) {
		for (auto& path : list.path) {
			ILLUST::PLAYER_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
	for (auto& list : ILLUST::STAGE_LIST) {
		for (auto& path : list.path) {
			ILLUST::STAGE_LIST[list.type].handle.push_back(LoadGraph(path));
		}
	}
}


void PictureManeger::Update()
{

	//ピクチャーリストの一部削除
	for (auto i = m_pictureList.cbegin(); i != m_pictureList.cend();) {
		if (i->get()->m_isActive) {
			i++;
		}
		else {
			i = m_pictureList.erase(i);
		}
	}


	//ピクチャーのリストの処理
	for (auto& c : m_pictureList) {

		if (!(c->m_isPauseStop && SceneManeger::gameScene->m_isPause)) {
			c->Update();
		}
	}
}

void PictureManeger::Draw()
{
	//ピクチャーのリストの描画
	for (auto& c : m_pictureList) {

		if (c->GetisVisible()) {
			c->Draw();
		}
	}
}


void PictureManeger::AddPicture(std::shared_ptr<Picture> picture)
{
	//ピクチャーのList追加と初期化
	m_pictureList.push_back(picture);

	//並び替え
	m_pictureList.sort(SortChange);

	picture->Initialize();

 }

bool SortChange(std::shared_ptr<Picture>&a, std::shared_ptr<Picture>&b) {
	return a->GetSort() > b->GetSort();
}
