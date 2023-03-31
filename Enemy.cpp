#include <DxLib.h>
#include "game.h"
#include "Enemy.h"

Enemy::Enemy():
	m_pos(),
	m_isDead(),
	m_playerPos(0.0f, 0.0f)
{
	for (int i = 0; i < enemyNum; i++)
	{
		m_enemySpeed[i] = static_cast<float>(GetRand(1) + 1);
		m_pos[i] = { static_cast<float>(GetRand(Game::kScreenWidth)),static_cast<float>(GetRand(Game::kScreenHeight)) };
		m_isDead[i] = true;
	}
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
}

void Enemy::End()
{
}

void Enemy::Update()
{


	for (int i = 0; i < enemyNum; i++)
	{
		//マウスに向かうベクトルを生成
		Vec2 toPlayer{ 0,0 };
		toPlayer.x = m_playerPos.x - m_pos[i].x;
		toPlayer.y = m_playerPos.y - m_pos[i].y;

		if (toPlayer.length() < 300) 
		{	
			toPlayer = toPlayer.normalize();
			m_pos[i] += toPlayer * m_enemySpeed[i];
		}

		m_posC = m_pos[i];

	}
}

void Enemy::Draw()
{
	if (m_isDead)
	{
		for (int i = 0; i < enemyNum; i++)
		{
			DrawBox(m_pos[i].x, m_pos[i].y, m_pos[i].x + 10, m_pos[i].y + 10, 0xff0000, true);
		}
	}
}
