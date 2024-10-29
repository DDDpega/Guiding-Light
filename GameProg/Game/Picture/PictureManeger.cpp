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
