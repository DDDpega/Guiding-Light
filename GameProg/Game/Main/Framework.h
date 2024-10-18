#pragma once

using namespace std;

#include "DxLib.h"
#include <stdio.h>
#include <memory>
#include <math.h>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

//システム
#include"Fps.h"
#include "Key.h"
#include "Status.h"
#include "Game.h"

//ピクチャー
#include "Picture.h"
#include "LightPicture.h"
#include "PictureManeger.h"

//ユーザーインターフェース
#include "UserInterface.h"
#include "GamePauseUI.h"
#include "TitleUI.h"
#include"StageSelectUI.h"
#include "InGameUI.h"

//マップ
#include "Map.h"

//シーン
#include "Scene.h"
#include "GameScene.h"
#include"StageSelectScene.h"
#include "TitleScene.h"
#include "SceneManeger.h"


//コンポーネント
#include "Component.h"
#include "BoxCollisionCmp.h"
#include "CircleCollisionCmp.h"
#include "CollisionManeger.h"
#include "MapCollision.h"
#include "RigidbodyCmp.h"
#include "LightCmp.h"


//アクター
#include "Actor.h"
#include "BackGround.h"
#include "Enemy.h"
#include "Player.h"
#include "GoalLight.h"
#include "Ladder.h"
