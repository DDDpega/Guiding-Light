#pragma once


class MapCollision : public Component
{
public:

    MapCollision(Actor* actor,E_TAG tag);

    ~MapCollision() {};

    bool CheckMapChip(int col, int row);

    bool CheckMapCollide(E_TAG tag,POINT pos, float dx, float dy, const bool isCollect = true, const bool isTopBottomChk = true);

protected:
    E_TAG m_tag;
};

