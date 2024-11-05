#include "Framework.h"


CollisionManeger::CollisionManeger()
	:m_BOXcollisionList()
{

}

CollisionManeger::~CollisionManeger()
{

}

void CollisionManeger::Initialize()
{
	m_BOXcollisionList.clear();
}

void CollisionManeger::Update()
{
	ListCheck();
}

void CollisionManeger::ListCheck()
{
	//アクターリストの中身削除
	for (auto i = m_CIRCLEcollisionList.cbegin(); i != m_CIRCLEcollisionList.cend();) {
		if (i->get()->GetActor()->m_isActive) {
			i++;
		}
		else {
			i = m_CIRCLEcollisionList.erase(i);
		}
	}

	//アクターリストの中身削除
	for (auto i = m_BOXcollisionList.cbegin(); i != m_BOXcollisionList.cend();) {
		if (i->get()->GetActor()->m_isActive) {
			i++;
		}
		else {
			i = m_BOXcollisionList.erase(i);
		}
	}
}

void CollisionManeger::AddBOXCollisionList(std::shared_ptr<BoxCollisionCmp> collision)
{
	//リストに入れる
	m_BOXcollisionList.push_back(collision);
}


void CollisionManeger::AddCIRCLECollisionList(std::shared_ptr<CircleCollisionCmp> collision)
{
	//リストに入れる
	m_CIRCLEcollisionList.push_back(collision);

}

void CollisionManeger::AddRayToHitObjectList(std::shared_ptr<BoxCollisionCmp> collision)
{
	m_rayToHitObject.push_back(collision);
}

//-------------------------------BOXtoBOX------------------------

void CollisionManeger::CheckCollide_BOXtoBOX()
{
	//コリジョンを回して衝突しているか検索する
	for (auto i = m_BOXcollisionList.cbegin(); i != m_BOXcollisionList.cend(); i++) {
		for (auto j = m_BOXcollisionList.cbegin(); j != m_BOXcollisionList.cend(); j++) {
			//同じObjectかどうか・そのObjectが生きているかどうか
			if (i->get()->GetActor() != j->get()->GetActor() &&
				i->get()->GetActor()->m_isActive && j->get()->GetActor()->m_isActive) {

				//当たっているかどうか
				CheckObjectHit_BOXtoBOX(i->get(), j->get());

			}
		}
	}

	ListCheck();
}

bool CollisionManeger::CheckObjectHit_BOXtoBOX(BoxCollisionCmp* obj_i, BoxCollisionCmp* obj_j)
{
	auto collObj_i = obj_i->m_collision;
	auto collObj_j = obj_j->m_collision;

	//当たり判定
	if ((collObj_i.right > collObj_j.left) &&
		(collObj_i.left < collObj_j.right))
	{
		if ((collObj_i.bottom > collObj_j.top) &&
			(collObj_i.top < collObj_j.bottom))
		{
			//オブジェクトに衝突通知を送る
			obj_i->GetActor()->HitCollision((obj_j->GetActor()), (obj_j->m_tag), (obj_i->m_tag));
			obj_j->GetActor()->HitCollision((obj_i->GetActor()), (obj_i->m_tag), (obj_j->m_tag));

			return true;
		}
	}

	//オブジェクトに衝突通知を送る
	obj_i->GetActor()->NoHitCollision((obj_j->GetActor()), (obj_j->m_tag));
	obj_j->GetActor()->NoHitCollision((obj_i->GetActor()), (obj_i->m_tag));
	return false;
}

//-------------------------------CIRCLEtoCIRLCE------------------------

void CollisionManeger::CheckCollide_CIRCLEtoCIRCLE()
{
	//コリジョンを回して衝突しているか検索する
	for (auto i = m_CIRCLEcollisionList.cbegin(); i != m_CIRCLEcollisionList.cend(); i++) {
		for (auto j = m_CIRCLEcollisionList.cbegin(); j != m_CIRCLEcollisionList.cend(); j++) {
			//同じObjectかどうか・そのObjectが生きているかどうか
			if (i->get()->GetActor() != j->get()->GetActor() &&
				i->get()->GetActor()->m_isActive && j->get()->GetActor()->m_isActive) {

				//当たっているかどうか
				CheckObjectHit_CIRCLEtoCIRLCE(i->get(), j->get());

			}
		}
	}

	ListCheck();
}

bool CollisionManeger::CheckObjectHit_CIRCLEtoCIRLCE(CircleCollisionCmp* obj_i, CircleCollisionCmp* obj_j)
{
	//当たり判定の取得
	auto collObj_i = obj_i->m_collision;
	auto collObj_j = obj_j->m_collision;

	//三角形をつくる
	float a = 0.0;
	float b = 0.0;
	float c = 0.0;

	//三角関数
	a = collObj_i.posX - collObj_j.posX;
	b = collObj_i.posY - collObj_j.posY;
	c = sqrt(a * a + b * b);

	//当たり判定がある
	if (c <= collObj_i.RADIUS + collObj_j.RADIUS) {

		//オブジェクトに衝突通知を送る
		obj_i->GetActor()->HitCollision((obj_j->GetActor()), (obj_j->m_tag), (obj_i->m_tag));
		obj_j->GetActor()->HitCollision((obj_i->GetActor()), (obj_i->m_tag), (obj_j->m_tag));

		return true;
	}

	//オブジェクトに衝突通知を送る
	obj_i->GetActor()->NoHitCollision((obj_j->GetActor()), (obj_j->m_tag));
	obj_j->GetActor()->NoHitCollision((obj_i->GetActor()), (obj_i->m_tag));
	return false;
}



//-------------------------------CIRCLEtoBOX------------------------

void CollisionManeger::CheckCollide_CIRCLEtoBOX()
{
	//コリジョンを回して衝突しているか検索する
	for (auto i = m_CIRCLEcollisionList.cbegin(); i != m_CIRCLEcollisionList.cend(); i++) {
		for (auto j = m_BOXcollisionList.cbegin(); j != m_BOXcollisionList.cend(); j++) {
			//同じObjectかどうか・そのObjectが生きているかどうか
			if (i->get()->GetActor() != j->get()->GetActor() &&
				i->get()->GetActor()->m_isActive && j->get()->GetActor()->m_isActive) {

				//当たっているかどうか
				CheckObjectHit_CIRCLEtoBOX(i->get(), j->get());

			}
		}
	}

	ListCheck();
}

bool CollisionManeger::CheckObjectHit_CIRCLEtoBOX(CircleCollisionCmp* obj_i, BoxCollisionCmp* obj_j)
{
	//当たり判定の取得
	auto circleObj_i = obj_i->m_collision;
	auto boxObj_j = obj_j->m_collision;

	bool isHit = true;


	// 四角形の四辺に対して円の半径分だけ足したとき円が重なっていたら
	if ((circleObj_i.posX > boxObj_j.left - circleObj_i.RADIUS) &&
		(circleObj_i.posX < boxObj_j.right + circleObj_i.RADIUS) &&
		(circleObj_i.posY > boxObj_j.top - circleObj_i.RADIUS) &&
		(circleObj_i.posY < boxObj_j.bottom + circleObj_i.RADIUS))
	{
		float fl = circleObj_i.RADIUS * circleObj_i.RADIUS;


		// 左
		if (circleObj_i.posX < boxObj_j.left) {
			// 左上
			if ((circleObj_i.posY < boxObj_j.top)) {
				if ((DistanceSqrf(boxObj_j.left, boxObj_j.top, circleObj_i.posX, circleObj_i.posY) >= fl)) {
					isHit = false;
				}
			}
			else {
				// 左下
				if ((circleObj_i.posY > boxObj_j.bottom)) {
					if ((DistanceSqrf(boxObj_j.left, boxObj_j.bottom, circleObj_i.posX, circleObj_i.posY) >= fl)) {
						isHit = false;

					}
				}
			}
		}
		else {
			// 右
			if (circleObj_i.posX > boxObj_j.right) {
				// 右上
				if ((circleObj_i.posY < boxObj_j.top)) {
					if ((DistanceSqrf(boxObj_j.right, boxObj_j.top, circleObj_i.posX, circleObj_i.posY) >= fl)) {
						isHit = false;

					}
				}
				else
				{
					// 右下
					if ((circleObj_i.posY > boxObj_j.bottom)) {
						if ((DistanceSqrf(boxObj_j.right, boxObj_j.bottom, circleObj_i.posX, circleObj_i.posY) >= fl)) {
							isHit = false;

						}
					}
				}
			}
		}

	}
	else {
		isHit = false;
	}

	if (isHit) {

		//オブジェクトに衝突通知を送る
		obj_i->GetActor()->HitCollision((obj_j->GetActor()), (obj_j->m_tag), (obj_i->m_tag));
		obj_j->GetActor()->HitCollision((obj_i->GetActor()), (obj_i->m_tag), (obj_j->m_tag));
		return true;
	}
	else {

		//オブジェクトに衝突通知を送る
		obj_i->GetActor()->NoHitCollision((obj_j->GetActor()), (obj_j->m_tag));
		obj_j->GetActor()->NoHitCollision((obj_i->GetActor()), (obj_i->m_tag));
		return false;
	}
}

float CollisionManeger::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

//-------------------------------RayCheck-----------------------

bool CollisionManeger::RayHitCheck(Point RayPos)
{
	//コリジョンを回して衝突しているか検索する
	for (auto i = m_mapCollision.cbegin(); i != m_mapCollision.cend(); i++) {

		//当たっているかどうか
		rayHitCheckCollObj_i = i->get()->m_collision;
		rayHitCheckCollObj_j = RayPos;

		//当たり判定
		if (((int)rayHitCheckCollObj_i.left<= (int)rayHitCheckCollObj_j.x) &&((int)rayHitCheckCollObj_i.right>= (int)rayHitCheckCollObj_j.x)&&
			((int)rayHitCheckCollObj_i.top <= (int)rayHitCheckCollObj_j.y) && ((int)rayHitCheckCollObj_i.bottom >= (int)rayHitCheckCollObj_j.y))
		{
			return true;
		}
	}
	return false;
}

bool CollisionManeger::RayToHitObjectCheck(RayCast* ray)
{
	BOX collObj_i;
	Point collObj_j;

	//コリジョンを回して衝突しているか検索する
	for (auto i = m_rayToHitObject.cbegin(); i != m_rayToHitObject.cend(); i++) {

		//当たっているかどうか
		collObj_i = i->get()->m_collision;
		collObj_j = ray->GetPos();

		//当たり判定
		if ((collObj_i.left <= collObj_j.x) && (collObj_i.right >= collObj_j.x))
		{
			if ((collObj_i.top <= collObj_j.y) && (collObj_i.bottom >= collObj_j.y))
			{
				i->get()->GetActor()->HitCollision(ray,ray->m_tag,i->get()->m_tag);
			}
		}
		i->get()->GetActor()->NoHitCollision(ray, ray->m_tag);
	}
	return false;
}

