#include "MapCollision.h"
#include "CollisionManeger.h"
#include "Game.h"

MapCollision::MapCollision(Game* gameInstance ,Scene* const scene , Actor* actor,TAG tag)
	:Component(actor)
	,m_scene(scene)
	, m_gameInstance(gameInstance)
	,m_tag(tag)
{}

//マップチップが移動可能かチェックするメソッド
// ture = 移動不可能
bool MapCollision::CheckMapChip(int col, int row)
{

	if (dynamic_cast<GameScene*>(m_scene)->m_map->getChipNo(col, row) != 0) {
		return true;
	}
	else {
		return false;
	}
}


/// <summary>
/// マップのコリジョンを調べる
/// </summary>
/// <param name="pos">ポジション</param>
/// <param name="dx">調べたいxの値</param>
/// <param name="dy">調べたいyの値</param>
/// <param name="isCollect">位置を強制的に戻すかどうか</param>
/// <param name="isTopBottomChk">上下の判定を取るかどうか</param>
/// <returns></returns>
bool MapCollision::CheckMapCollide(POINT pos, float dx, float dy, const bool isCollect, const bool isTopBottomChk)
{
	bool result = false;
	const auto mapChipSize = 40;

	//pos.x + m_game->m_map->getPos().x;


	//TODO rectを作るときに持ってきたposを使ってないからおかしくなっている可能性
	//auto rect = getColRect(pos.x + m_collition.left, pos.y + m_collition.top + 32, pos.x + m_collition.right, pos.y + m_collition.bottom + 32);
	auto rect = m_gameInstance->GetCollisionMNG()->GetCollisionActor(m_tag)->GetChangeCollision(pos);

	unsigned int color;

	color = GetColor(255, 255, 255);

	//DrawBox(rect.left, rect.top, rect.right, rect.bottom, color, TRUE);

	auto pos2 = m_actor->GetPos();

	int left;
	//チップ単位の四隅の位置
	if (rect.left < 0) {
		left = -1;
	}
	else {
		left = rect.left / mapChipSize;
	}
	const int top = rect.top / mapChipSize;
	const int right = (rect.right - 1) / mapChipSize;
	const int bottom = (rect.bottom - 1) / mapChipSize;
	const int middle_x = pos2.x / mapChipSize;
	const int middle_y = pos2.y / mapChipSize;




	//左上、左ッ↓、右上、右のチェックを先に済ませておく
	auto leftTop = CheckMapChip(left, top);
	auto leftMiddle = CheckMapChip(left, middle_y);
	auto leftBottom = CheckMapChip(left, bottom);
	auto rightTop = CheckMapChip(right, top);
	auto rightMiddle = CheckMapChip(right, middle_y);
	auto rightBottom = CheckMapChip(right, bottom);
	auto middleTop = CheckMapChip(middle_x, top);
	auto middleBottom = CheckMapChip(middle_x, bottom);

	if (leftBottom) {
		result = false;
	}

	if (!isTopBottomChk) {
		leftTop = leftBottom = rightTop = rightBottom = false;
	}

	

	//左方向をチェック
	if (dx < 0 && (leftTop || leftMiddle || leftBottom)) {
		result = true;
		if (isCollect) {
			//強制的にもどす
			//右の列数にsizeをかけてピクセル位置を求める
			pos2.x += (left + 1) * mapChipSize - rect.left;
			

		}
	}
	//右方向をチェック
	else if (dx > 0 && (rightTop || rightMiddle || rightBottom)) {
		result = true;
		if (isCollect) {
			//境界線の列数にsizeをかけて、四角形の右側がはみ出したさを求める
			pos2.x -= rect.right - right * mapChipSize;	//差をX座標から引いて逆方向へ戻す
			
		}
	}
	//上方向をチェック
	if (dy < 0 && (rightTop || middleTop || leftTop)) {
		result = true;
		if (isCollect) {
			pos2.y += (top + 2) * mapChipSize - rect.top;
			
		}
	}
	else if (dy > 0 && (rightBottom || middleBottom || leftBottom)) {
		result = true;

		if (isCollect) {
			pos2.y -= rect.bottom - bottom * mapChipSize;
			

		}

	}

	if (result) {
		m_actor->SetPos(pos2);
		m_gameInstance->GetCollisionMNG()->GetCollisionActor(m_tag)->ChangeCollision();
	}

	return result;
}