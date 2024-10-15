#include "Framework.h"



LightPicture::LightPicture()
	:Picture(SORT::SORT_LIGHT,true)
{

}

LightPicture::~LightPicture()
{

}

void LightPicture::Initialize(Game* gameInstance, Scene* scene)
{
	Picture::Initialize(gameInstance, scene);

	x = scene->screenX;
	y = scene->screenY;
}

void LightPicture::Update()
{
	Picture::Update();
}

void LightPicture::Draw()
{
	//画像を描画するためのスクリーンを作成する
	screenA = MakeScreen(x, y, true);
	screenB = MakeScreen(x, y, true);
	screenC = MakeScreen(x, y, true);

	//スクリーンを色で塗りつぶす
	FillGraph(screenA, 0, 0, 0, 255);		//真っ黒
	FillGraph(screenB, 0, 0, 0, 0);	//白に画像を描画
	FillGraph(screenC, 255, 255, 255, 255);		//なにもない

	//スクリーンを設定する
	SetDrawScreen(screenB);

	//-----
	//ライトを描画する
	for (auto& c : pictureList) {
		DrawRotaGraph2(c->GetPos().x, c->GetPos().y,
			(c->m_pictureSizeX / 2), (c->m_pictureSizeY / 2),
			c->m_size, 0, c->m_handle, true);
	}
	//------
	
	//赤色成分を透明成分に移し替える
	GraphBlendBlt(screenB, screenB, screenB, 255,
		DX_GRAPH_BLEND_RGBA_SELECT_MIX,
		DX_RGBA_SELECT_SRC_R,
		DX_RGBA_SELECT_SRC_G,
		DX_RGBA_SELECT_SRC_B,
		DX_RGBA_SELECT_SRC_INV_R
	);

	//透明成分のみをscreenAに移し替えたものをscreenCにうつす
	GraphBlendBlt(screenA, screenB, screenC, 255,
		DX_GRAPH_BLEND_MULTIPLE_A_ONLY);

	//画面を元に戻す
	SetDrawScreen(DX_SCREEN_BACK);


	//透過モードに変える
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//スクリーンを描画する
	DrawGraph(0, 0, screenC, true);

	//スクリーンを削除する
	DeleteGraph(screenA);
	DeleteGraph(screenB);
	DeleteGraph(screenC);
}

void LightPicture::AddLightList(shared_ptr<Picture> picture)
{
	picture->Initialize(m_gameInstance,m_sceneptr);
	pictureList.push_back(picture);
}