#include "Framework.h"


MapCollision::MapCollision(Actor* actor, E_TAG tag)
	:Component(actor)
	,m_tag(tag)
{}

//マップチップが移動可能かチェックするメソッド
void MapCollision::CheckPuddle(int col, int row, E_TAG tag)
{
	if (tag != E_TAG::PLAYER)return;
	auto chipNo = SceneManeger::gameScene->m_map->getChipNo(col, row);
	if (chipNo == MAPCHIPINFO::PUDDLE) {
		SceneManeger::gameScene->GetPlayer()->SetChangePuddleSound(true);
	}
	else {
		SceneManeger::gameScene->GetPlayer()->SetChangePuddleSound(false);
	}

}

//マップチップが移動可能かチェックするメソッド
// ture = 移動不可能
bool MapCollision::CheckMapChip(int col, int row,bool isFly)
{
	auto chipNo = SceneManeger::gameScene->m_map->getChipNo(col, row);
	auto solarpanel = SceneManeger::gameScene->m_solarpanel;
	bool isTrigger = false;
	bool isTrigger2 = false;
	
	for (auto s : solarpanel) {
		if (s->GetParam() == E_SOLARPANEL_KIND::BLOCK) {
			isTrigger = s->GetIsTrigger();
		}
		
		if (isTrigger) {
			break;
		}
	}
	isTrigger2 = SceneManeger::gameScene->GetPlayer()->GetIsTrigger();

	if (chipNo == MAPCHIPINFO::LADDER && isFly) {
		return true;
	}
	else if (isFly) {
		return false;
	}
	if (chipNo==-1||chipNo==MAPCHIPINFO::FLOOR2
		||chipNo == MAPCHIPINFO::FLOOR||chipNo==MAPCHIPINFO::PUDDLE
		||(chipNo == MAPCHIPINFO::LAUNCH && isTrigger)|| 
		(chipNo == MAPCHIPINFO::LAUNCH2 && !isTrigger)||
		((chipNo == MAPCHIPINFO::CURTAINSR || chipNo == MAPCHIPINFO::CLEANNESSBLOCK) && !isTrigger2)||
		((chipNo == MAPCHIPINFO::CURTAINSL || chipNo == MAPCHIPINFO::CLEANNESSBLOCK) && !isTrigger2)
		) {
		return true;
	}

	
	return false;
}

bool MapCollision::CheckLadder(E_TAG tag,Point pos)
{
	auto rect = Game::gameInstance->GetCollisionMNG()->GetCollisionActor(tag)->GetChangeCollision(pos);
	const auto mapChipSize = 40;
	auto pos2 = m_actor->GetPos();

	const int bottom = ((rect.bottom - 1) / mapChipSize)+1;
	const int middle_x = pos2.x / mapChipSize;

	int left;
	//チップ単位の四隅の位置
	if (rect.left < 0) {
		left = -1;
	}
	else {
		left = rect.left / mapChipSize;
	}
	const int right = (rect.right - 1) / mapChipSize;
	auto middleBottom = CheckMapChip(middle_x, bottom, true);
	auto rightBottom = CheckMapChip(right, bottom, true);
	auto leftBottom = CheckMapChip(left, bottom, true);

	auto isladder = false;
	if (middleBottom) {
		isladder = true;
	}

	return isladder;
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
bool MapCollision::CheckMapCollide(E_TAG tag, Point pos, float dx, float dy, const bool isCollect, const bool isTopBottomChk, const bool isFlayChk)
{
	bool result = false;
	const auto mapChipSize = 40;

	//pos.x + m_game->m_map->getPos().x;


	//TODO rectを作るときに持ってきたposを使ってないからおかしくなっている可能性
	//auto rect = getColRect(pos.x + m_collition.left, pos.y + m_collition.top + 32, pos.x + m_collition.right, pos.y + m_collition.bottom + 32);
	auto rect = Game::gameInstance->GetCollisionMNG()->GetCollisionActor(tag)->GetChangeCollision(pos);

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
	int top = rect.top / mapChipSize;
	int right = (rect.right - 1) / mapChipSize;
	int bottom = (rect.bottom - 1) / mapChipSize;
	int middle_x = pos2.x / mapChipSize;
	int middle_y = pos2.y / mapChipSize;


	auto middleBottomNum = SceneManeger::gameScene->m_map->getChipNo(middle_x, bottom);
	auto rightBottomNum = SceneManeger::gameScene->m_map->getChipNo(right, bottom);
	auto leftBottomNum = SceneManeger::gameScene->m_map->getChipNo(left, bottom);

	//左上、左ッ↓、右上、右のチェックを先に済ませておく
	auto leftTop = CheckMapChip(left, top);
	auto leftMiddle = CheckMapChip(left, middle_y);
	auto leftBottom = CheckMapChip(left, bottom);
	auto rightTop = CheckMapChip(right, top);
	auto rightMiddle = CheckMapChip(right, middle_y);
	auto rightBottom = CheckMapChip(right, bottom);
	auto middleTop = CheckMapChip(middle_x, top);
	auto middleBottom = CheckMapChip(middle_x, bottom,isFlayChk);

	

	auto bottmLadder = false;
	if (middleBottomNum == 7 || rightBottomNum == 7 || leftBottomNum == 7)
		bottmLadder = true;

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
			pos2.y += (top + 1) * mapChipSize - rect.top;
			
		}
	}
	//下方向をチェックs
	//TODO定数に変更したい+プレイヤーの方ではしごに当たった数を取得する
	//はしご
	else if (dy > 0 && (rightBottom || middleBottom || leftBottom)/* || (bottmLadder && m_actor->m_rigidBody->m_state == FLY)*/) {
		result = true;

		if (isCollect) {
			pos2.y -= rect.bottom - bottom * mapChipSize;
			

		}

	}

	rect = Game::gameInstance->GetCollisionMNG()->GetCollisionActor(tag)->GetChangeCollision(pos2);

	//チップ単位の四隅の位置
	if (rect.left < 0) {
		left = -1;
	}
	else {
		left = rect.left / mapChipSize;
	}
	right = (rect.right - 1) / mapChipSize;
	bottom = (rect.bottom - 1) / mapChipSize;
	middle_x = pos2.x / mapChipSize;
	

	if (result) {
		m_actor->SetPos(pos2);
		Game::gameInstance->GetCollisionMNG()->GetCollisionActor(tag)->ChangeCollision();
		bottom++;
	}

	
	//水たまりチェック
	CheckPuddle(middle_x, bottom, tag);
	CheckPuddle(right, bottom, tag);
	CheckPuddle(left, bottom, tag);

	return result;
}