#pragma once

using namespace std;

#include "DxLib.h"
#include <stdio.h>
#include <memory>
#include <math.h>
#include <list>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

//定数
#include "ActorInfo.h"
#include "EnumInfo.h"
#include "SystemInfo.h"
#include "PictureInfo.h"

//システム
#include"Fps.h"
#include "Key.h"
#include "Status.h"
#include "InputManager.h"
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
#include "GameClearUI.h"
#include "GameOverUI.h"


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
#include "DarkPictureCmp.h"
#include "PictureCmp.h"



//アクター
#include "Actor.h"
#include "BackGround.h"
#include "Enemy.h"
#include "Player.h"
#include "GoalLight.h"
#include "Ladder.h"
#include "Pisher.h"
#include "LuminousFigure.h"
#include"SolarPanel.h"
#include"SolarPanelBlock.h"
#include "MapChipActor.h"
#include "RayCast.h"
#include "ActorManager.h"