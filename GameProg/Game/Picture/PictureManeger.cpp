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
		c->Update();
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


void PictureManeger::AddPicture(std::shared_ptr<Picture> picture, Scene* scene)
{
	//ピクチャーのList追加と初期化
	m_pictureList.push_back(picture);

	//並び替え
	m_pictureList.sort(SortChange);

	picture->Initialize(m_gameInstance,scene);

 }

bool SortChange(std::shared_ptr<Picture>&a, std::shared_ptr<Picture>&b) {
	return a->GetSort() > b->GetSort();
}
