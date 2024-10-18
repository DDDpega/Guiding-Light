#pragma once

class GameScene;

class MapCollision : public Component
{
public:

    MapCollision(Game* gameInstance, Scene* const scene, Actor* actor,TAG tag);

    ~MapCollision() {};

    bool CheckMapChip(int col, int row);

    bool CheckMapCollide(TAG tag,POINT pos, float dx, float dy, const bool isCollect = true, const bool isTopBottomChk = true);

protected:
    Game* m_gameInstance;
    Scene* m_scene;
    TAG m_tag;
};

