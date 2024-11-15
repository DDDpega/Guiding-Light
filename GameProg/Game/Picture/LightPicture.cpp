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

}

void LightPicture::Draw()
{
	//透過モードに変える
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//画像を描画するためのスクリーンを作成する
	auto screenA = MakeScreen(x, y, true);
	auto screenB = MakeScreen(x, y, true);
	auto screenC = MakeScreen(x, y, true);

	//スクリーンを色で塗りつぶす
	FillGraph(screenA, 0, 0, 0, 255);			//白
	FillGraph(screenB, 0, 0, 0, 255);			//白に画像を描画
	FillGraph(screenC, 255, 255, 255, 255);		//真っ黒

	//スクリーンを設定する
	SetDrawScreen(screenB);

	//----------------------------------------------------------------------
	//ライトを描画する
	for (auto& c : lightCmpList) {

		//スクリーンDに描画先を変更する
		auto screenD = MakeScreen(x, y, true);
		FillGraph(screenD, 0, 0, 0, 255);
		SetDrawScreen(screenD);

		//レイを元に三角形を作成する
		for (int i = 0; i < GAME_INFO::RAYNUM; i++) {

			if (!c->m_ray[i]->m_isRayStart)
				continue;

			if (i == GAME_INFO::RAYNUM-1) {
				DrawTriangle(c->m_ray[i]->GetPos().x, c->m_ray[i]->GetPos().y,
					c->m_ray[0]->GetPos().x, c->m_ray[0]->GetPos().y,
					c->GetActor()->GetPos().x, c->GetActor()->GetPos().y,
					GetColor(255, 0, 0), true);
			}
			else {
				DrawTriangle(c->m_ray[i]->GetPos().x, c->m_ray[i]->GetPos().y,
					c->m_ray[i + 1]->GetPos().x, c->m_ray[i + 1]->GetPos().y,
					c->GetActor()->GetPos().x, c->GetActor()->GetPos().y,
					GetColor(255, 0, 0), true);
			}
		}

		auto screenE = MakeScreen(x, y, true);
		FillGraph(screenE, 0, 0, 0, 255);
		SetDrawScreen(screenE);

		//ライトの画像を描画
		DrawRotaGraph2(c->m_lightPicture->GetPos().x, c->m_lightPicture->GetPos().y,
			(c->m_lightPicture->m_pictureSizeX / 2), (c->m_lightPicture->m_pictureSizeY / 2),
			c->m_lightPicture->m_size, 0, c->m_lightPicture->m_handle, true);

		GraphBlend(screenD,screenE, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX,
			DX_RGBA_SELECT_BLEND_R,    // 出力結果の赤成分は AlphaHandle の緑成分
			DX_RGBA_SELECT_SRC_G,    // 出力結果の緑成分は AlphaHandle の赤成分
			DX_RGBA_SELECT_SRC_B,    // 出力結果の青成分は AlphaHandle の青成分
			DX_RGBA_SELECT_SRC_R   // 出力結果のアルファ成分は BlendHandle の赤成分
		);

		
		//スクリーンを設定する
		SetDrawScreen(screenD);
		//スクリーンを削除する
		DeleteGraph(screenE);


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

void LightPicture::AddLightList(LightCmp* lightCmp)
{
	lightCmpList.push_back(lightCmp);

}