#include "Framework.h"



LightPicture::LightPicture()
	:Picture(E_SORT::SORT_LIGHT,true)
{

}

LightPicture::~LightPicture()
{

}

void LightPicture::Initialize()
{
	Picture::Initialize();

	x = WINDOW_INFO::GAME_WIDTH;
	y = WINDOW_INFO::GAME_HEIGHT;
}

void LightPicture::Update()
{
	Picture::Update();

	//ピクチャーリストの一部削除
	for (auto i = pictureList.cbegin(); i != pictureList.cend();) {
		if (i->get()->m_isActive) {
			i++;
		}
		else {
			i = pictureList.erase(i);
		}
	}
}

void LightPicture::Draw()
{
	//透過モードに変える
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//画像を描画するためのスクリーンを作成する
	screenA = MakeScreen(x, y, true);
	screenB = MakeScreen(x, y, true);
	screenC = MakeScreen(x, y, true);

	//スクリーンを色で塗りつぶす
	FillGraph(screenA, 0, 0, 0, 255);			//白
	FillGraph(screenB, 0, 0, 0, 255);			//白に画像を描画
	FillGraph(screenC, 255, 255, 255, 255);		//真っ黒

	//スクリーンを設定する
	SetDrawScreen(screenB);

	//----------------------------------------------------------------------
	//ライトを描画する
	for (auto& c : pictureList) {

		//画像が見えるかどうか
		if (!c->GetisVisible()) {
			continue;
		}

		//スクリーンDに描画先を変更する
		auto screenD = MakeScreen(x, y, true);
		FillGraph(screenD, 0, 0, 0, 255);
		SetDrawScreen(screenD);

		//画像の表示
		DrawRotaGraph2(c->GetPos().x, c->GetPos().y,
			(c->m_pictureSizeX / 2), (c->m_pictureSizeY / 2),
			c->m_size, 0, c->m_handle, true);

		//スクリーンBにスクリーンDを加算する
		GraphBlendBlt(screenB, screenD, screenB, 255,
			DX_GRAPH_BLEND_PMA_LIGHTEN);

		//スクリーンを設定する
		SetDrawScreen(screenB);

		//スクリーンを削除する
		DeleteGraph(screenD);
	}
	//-----------------------------------------------------------------------
	
	//赤色成分を透明成分に移し替える
	GraphBlendBlt(screenB, screenB, screenB, 255,
		DX_GRAPH_BLEND_RGBA_SELECT_MIX,
		DX_RGBA_SELECT_SRC_R,
		DX_RGBA_SELECT_SRC_G,
		DX_RGBA_SELECT_SRC_B,
		DX_RGBA_SELECT_SRC_INV_R
	);

	//screenBの透明成分のみをscreenAに移し替えたものをscreenCにうつす
	GraphBlendBlt(screenA, screenB, screenC, 255,
		DX_GRAPH_BLEND_MULTIPLE_A_ONLY);

	//画面を元に戻す
	SetDrawScreen(DX_SCREEN_BACK);

	//スクリーンを描画する
	DrawGraph(0, 0, screenC, true);

	//スクリーンを削除する
	DeleteGraph(screenA);
	DeleteGraph(screenB);
	DeleteGraph(screenC);
}

void LightPicture::AddLightList(shared_ptr<Picture> picture)
{
	picture->Initialize();
	pictureList.push_back(picture);
}