#include "Framework.h"



PictureManeger::PictureManeger(Game* gameInstane)
	:m_gameInstance(gameInstane)
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
		c->Update();
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


void PictureManeger::AddPicture(std::shared_ptr<Picture> picture, Scene* scene)
{
	//�s�N�`���[��List�ǉ��Ə�����
	m_pictureList.push_back(picture);

	//���ёւ�
	m_pictureList.sort(SortChange);

	picture->Initialize(m_gameInstance,scene);

 }

bool SortChange(std::shared_ptr<Picture>&a, std::shared_ptr<Picture>&b) {
	return a->GetSort() > b->GetSort();
}
