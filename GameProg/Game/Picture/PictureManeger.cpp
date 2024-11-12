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

	//�e�摜�����[�h����
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

	//�s�N�`���[���X�g�̈ꕔ�폜
	for (auto i = m_pictureList.cbegin(); i != m_pictureList.cend();) {
		if (i->get()->m_isActive) {
			i++;
		}
		else {
			i = m_pictureList.erase(i);
		}
	}


	//�s�N�`���[�̃��X�g�̏���
	for (auto& c : m_pictureList) {

		if (!(c->m_isPauseStop && SceneManeger::gameScene->m_isPause)) {
			c->Update();
		}
	}
}

void PictureManeger::Draw()
{
	//�s�N�`���[�̃��X�g�̕`��
	for (auto& c : m_pictureList) {

		if (c->GetisVisible()) {
			c->Draw();
		}
	}
}


void PictureManeger::AddPicture(std::shared_ptr<Picture> picture)
{
	//�s�N�`���[��List�ǉ��Ə�����
	m_pictureList.push_back(picture);

	//���ёւ�
	m_pictureList.sort(SortChange);

	picture->Initialize();

 }

bool SortChange(std::shared_ptr<Picture>&a, std::shared_ptr<Picture>&b) {
	return a->GetSort() > b->GetSort();
}
