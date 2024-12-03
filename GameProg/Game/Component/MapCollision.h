#pragma once


class MapCollision : public Component
{
public:

    MapCollision(Actor* actor,E_TAG tag);

    

    ~MapCollision() {};

    void CheckPuddle(int col, int row, E_TAG tag);

    bool CheckMapChip(int col, int row, bool isFly=false);

    bool CheckLadder(E_TAG tag,Point pos);

    bool CheckMapCollide(E_TAG tag, Point pos, float dx, float dy, const bool isCollect = true, const bool isTopBottomChk = true, const bool isFlayChk = false);

protected:
    E_TAG m_tag;
};

