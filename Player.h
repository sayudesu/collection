#pragma once
#include "Util/Vec2.h"
class Player
{
public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

	Vec2 SetPos() { return m_pos; }

	Vec2 playerLeft() { return m_pos; }

private:
	Vec2 m_pos;//プレイヤーの位置
};

