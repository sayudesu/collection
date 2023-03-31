#pragma once
#include "Util/Vec2.h"
namespace
{
	constexpr int enemyNum = 100;
}
class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

	void GetPos(Vec2 playerPos) {m_playerPos = playerPos;}
	void* GetDead(bool dead)
	{
		int* ip = NULL;

		ip = (int*)malloc(sizeof(int) * enemyNum);

		if (ip == NULL) {
			printfDx("配列作成失敗\n");
		}

		m_isDead[dead] = dead;
		for (int i = 0; i < enemyNum; i++)
		{
		}
	}

	Vec2* EnemyLeft() 
	{
		
		int* ip = NULL;

		ip = (int*)malloc(sizeof(int) * enemyNum);

		if (ip == NULL) {
			printfDx("配列作成失敗\n");
		}

		return m_pos; 
	}
private:
	float m_enemySpeed[enemyNum];
	bool m_isDead[enemyNum];
	Vec2 m_pos[enemyNum];//プレイヤーの位置
	Vec2 m_posC;
	Vec2 m_playerPos;
};

