#include "Framework.h"

LuminousFigure::LuminousFigure(Point pos)
	:Actor(pos)
	, m_lightOn(false)
	,m_time(0)
	,m_shareNow(false)
{
}

LuminousFigure::~LuminousFigure()
{
}

void LuminousFigure::Initialize()
{
	Actor::Initialize();

	//画像コンポーネント
	m_pictureCmp = shared_ptr<PictureCmp>(new PictureCmp(this, LUMINOUSFIGURE_INFO::SIZE, ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA],0, E_PIVOT::CENTER, E_SORT::SORT_ACTOR));
	AddComponent(m_pictureCmp);

	//当たり判定の作成
	auto collision = std::shared_ptr<BoxCollisionCmp>(new BoxCollisionCmp(this, { 0,0 }, LUMINOUSFIGURE_INFO::COLLISION_SIZE, E_TAG::LUMINOUSFIGURE));
	Actor::AddComponent(collision);
	Game::gameInstance->GetCollisionMNG()->AddRayToHitObjectList(collision);

	//ライトコンポーネントの作成
	m_lightCmp = std::shared_ptr<LightCmp>(new LightCmp(this, false, Game::gameInstance->GetStatus()->FIGURE_LIGHT,E_TAG::FIGURERAY));
	Actor::AddComponent(m_lightCmp);

	//何秒効果時間があるか
	m_maxTime = Game::gameInstance->GetStatus()->FIGURE_MAXTIME;

	//フォントの描画
	m_fontHandle = CreateFontToHandle("MS ゴシック", 20, 1);

	m_figureSound = shared_ptr<Sound>(new Sound(SOUND::GIMMICK_LIST[SOUND::GIMMICK_TYPE::FIGURE], Sound::E_Sound::SE, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_figureSound);

	m_figuaMove = E_FIGUA_MOVE::NONE;
}

void LuminousFigure::Update()
{
	Actor::Update();

	switch (m_figuaMove)
	{
	case E_FIGUA_MOVE::NONE:
		
		//供給されたら
		if (m_shareNow) {
			m_time = 0;
			m_isChargeStop = false;
			m_figuaMove = E_FIGUA_MOVE::CHARGE;
		}
		break;
	case E_FIGUA_MOVE::CHARGE:
		
		if (m_shareNow) {

			//タイムを増やす
			++m_time;
			m_lightCmp->m_nowLightSize += ((float)m_lightCmp->m_lightSize / 30.0f);

			//1秒経ったら
			if (m_time >= 30) {

				//ライトをつける
				m_lightCmp->ChangeLightONOFF();
				m_lightOn = true;

				m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA], 1);

				//リストに含む
				SceneManeger::gameScene->m_figureList.push_back(this);
				m_figureSound->SoundPlay();

				m_time = 0;
				m_figuaMove = E_FIGUA_MOVE::LIGHTNING;

			}
		}
		else {
			m_time = 30 - m_time-1;
			m_figuaMove=E_FIGUA_MOVE::SLOWLY_DOWN;
			m_isChargeStop = true;
		}

		break;
	case E_FIGUA_MOVE::LIGHTNING:

		//タイムを増やす
		++m_time;

		//タイムがマックスタイムまで到達したら
		if (m_time >= m_maxTime) {
			m_time = 0;
			m_figuaMove = E_FIGUA_MOVE::SLOWLY_DOWN;
		}

		break;
	case E_FIGUA_MOVE::SLOWLY_DOWN:

		//タイムを増やす
		++m_time;
		m_lightCmp->m_nowLightSize -= ((float)m_lightCmp->m_lightSize / 30.0f);
		

		//ライトを消す
		if (m_time >= 30) {
			m_lightOn = false;
			m_lightCmp->m_nowLightSize = 0;

			if (!m_isChargeStop) {
				m_lightCmp->ChangeLightONOFF();
			}
		
			m_time = 0;
			m_figuaMove = E_FIGUA_MOVE::NONE;
			m_pictureCmp->m_picture->ChangePicture(&ILLUST::GIMMICK_LIST[ILLUST::GIMMICK_TYPE::FIGUA], 0);
		}
		break;

	}

	m_shareNow = false;
}

void LuminousFigure::Draw()
{
	Actor::Draw();

	if(GAME_INFO::DEBUG)
		DrawFormatStringFToHandle(m_pos.x-70, m_pos.y-50, GetColor(255, 255, 255), m_fontHandle, "%d", m_time);
}

void LuminousFigure::HitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{
	Actor::HitCollision(other, tag, selftag);

	if (tag == E_TAG::PLAYER_RAY && SceneManeger::gameScene->GetPlayer()->GetLightOn()) {
		m_shareNow = true;
	}
}

void LuminousFigure::NoHitCollision(Actor* other, E_TAG tag, E_TAG selftag)
{

}
