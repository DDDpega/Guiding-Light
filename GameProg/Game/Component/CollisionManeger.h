#pragma once



class CollisionManeger
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CollisionManeger();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CollisionManeger();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// リスト内のコンポーネントが存在しているかどうか
	/// </summary>
	void ListCheck();

	/// <summary>
	/// リストに追加する
	/// </summary>
	void AddBOXCollisionList(std::shared_ptr<BoxCollisionCmp> collision);

	/// <summary>
	/// リストに追加する
	/// </summary>
	void AddMapCollisionList(std::shared_ptr<BoxCollisionCmp> collision) {
		//リストに入れる
		m_mapCollision.push_back(collision);
	}

	/// <summary>
	/// リストに追加する
	/// </summary>
	void RemoveMapCollisionList(std::shared_ptr<BoxCollisionCmp> collision) {
		auto i = m_mapCollision.begin();
		for (auto c : m_mapCollision) {
			if (c == collision) {
				//リストから消す
				m_mapCollision.erase(i);
				return;
			}
			i++;
		}
		
	}

	/// <summary>
	/// リストに追加する
	/// </summary>
	void AddCIRCLECollisionList(std::shared_ptr<CircleCollisionCmp> collision);

	/// <summary>
	/// リストに追加する
	/// </summary>
	void AddRayToHitObjectList(std::shared_ptr<BoxCollisionCmp> collision);

//-------------------------------BOXtoBOX------------------------
	/// <summary>
	/// 当たり判定のチェック
	/// </summary>
	void CheckCollide_BOXtoBOX();

	/// <summary>
	/// 二つのオブジェクトがぶつかっているか
	/// </summary>
	bool CheckObjectHit_BOXtoBOX(BoxCollisionCmp* obj_i, BoxCollisionCmp* obj_j);


//-------------------------------CIRCLEtoCIRLCE------------------------

	/// <summary>
	/// 当たり判定のチェック
	/// </summary>
	void CheckCollide_CIRCLEtoCIRCLE();

	/// <summary>
	/// 二つのオブジェクトがぶつかっているか
	/// </summary>
	bool CheckObjectHit_CIRCLEtoCIRLCE(CircleCollisionCmp* obj_i, CircleCollisionCmp* obj_j);


//-------------------------------CIRCLEtoBOX------------------------

	/// <summary>
	/// 当たり判定のチェック
	/// </summary>
	void CheckCollide_CIRCLEtoBOX();

	/// <summary>
	/// 二つのオブジェクトがぶつかっているか
	/// </summary>
	bool CheckObjectHit_CIRCLEtoBOX(CircleCollisionCmp* obj_i, BoxCollisionCmp* obj_j);

	/// <summary>
	/// BOXとCIRCLEの計算
	/// </summary>
	/// <param name="t_x1"></param>
	/// <param name="t_y1"></param>
	/// <param name="t_x2"></param>
	/// <param name="t_y2"></param>
	/// <returns></returns>
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);

//-----------Ray---------------------------------------------------------

	/// <summary>
	/// レイとマップがぶつかっているかどうか
	/// </summary>
	/// <param name="RayPos"></param>
	/// <returns></returns>
	bool RayHitCheck(Point RayPos);

	/// <summary>
	/// レイとぶつかるオブジェクトの判定
	/// </summary>
	/// <param name="ray"></param>
	/// <returns></returns>
	bool RayToHitObjectCheck(RayCast* ray, int number);


	bool RayToHitObjectCheckLine(RayCast* ray);

	/// <summary>
	/// リストの削除
	/// </summary>
	void CleanList() {
		m_BOXcollisionList.clear();
		m_CIRCLEcollisionList.clear();
		m_rayToHitObject.clear();
		m_mapCollision.clear();
	}


	/// <summary>
	/// リストの中身の1つを入手する
	/// </summary>
	/// <param name="tag"></param>
	/// <returns></returns>
	std::shared_ptr<BoxCollisionCmp> GetCollisionActor(E_TAG tag) {
		for (auto& c : m_BOXcollisionList) {
			if (c->m_tag == tag)
				return c;
		}
		return nullptr;
	}

	vector<shared_ptr<BoxCollisionCmp>> m_BOXcollisionList;	//当たり判定リスト
	vector<shared_ptr<BoxCollisionCmp>> m_mapCollision;	//当たり判定リスト
	vector<shared_ptr<CircleCollisionCmp>> m_CIRCLEcollisionList;	//当たり判定リスト
	vector<shared_ptr<BoxCollisionCmp>> m_rayToHitObject;	//レイが広がる途中に当たるリスト

	BOX rayHitCheckCollObj_i;
	Point rayHitCheckCollObj_j;

};

