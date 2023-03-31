#pragma once
#include "SceneBase.h"
#include "../Util/Vec2.h"

class Player;
class Enemy;
class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	bool* SetDeadEnemy()
	{

		int* ip = NULL;

		ip = (int*)malloc(sizeof(int) * 100);

		if (ip == NULL) {
			//printfDx("配列作成失敗\n");
		}

		return m_deadEnemy;
	}
private:
	Vec2 m_pos;//プレイヤーの位置
	bool m_deadEnemy[100];
	Player* m_pPlayer;
	Enemy* m_pEnemy;
};
