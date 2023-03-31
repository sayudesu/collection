#include<DxLib.h>
#include "SceneMain.h"
#include "../Player.h"
#include "../Enemy.h"

SceneMain::SceneMain():
	m_pos(0.0f, 0.0f),
	m_deadEnemy(),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr)
{
	m_pPlayer = new Player;
	m_pEnemy = new Enemy;
}

SceneMain::~SceneMain()
{

}

void SceneMain::Init()
{
	for (int  i = 0; i < 10; i++)
	{
		m_deadEnemy[i] = true;
	}
	m_pPlayer->Init();
	m_pEnemy->Init();
}
void SceneMain::End()
{
	m_pPlayer->End();
	m_pEnemy->End();
}

SceneBase* SceneMain::Update()
{

	m_pPlayer->Update();
	m_pEnemy->Update();

	m_pEnemy->GetPos(m_pPlayer->SetPos());

	for (int i = 0; i < 10; i++)
	{
		if ((m_pPlayer->playerLeft().x + 10 > m_pEnemy->EnemyLeft()[i].x) &&
			(m_pPlayer->playerLeft().x < m_pEnemy->EnemyLeft()[i].x + 10))
		{
			if ((m_pPlayer->playerLeft().y + 10 > m_pEnemy->EnemyLeft()[i].y) &&
				(m_pPlayer->playerLeft().y < m_pEnemy->EnemyLeft()[i].y + 10))
			{
				printfDx("HIT\n");
			}
		}


		//マウスに向かうベクトルを生成
		Vec2 toPlayer{ 0,0 };
		toPlayer.x = m_pPlayer->playerLeft().x - m_pEnemy->EnemyLeft()[i].x;
		toPlayer.y = m_pPlayer->playerLeft().y - m_pEnemy->EnemyLeft()[i].y;

		if (toPlayer.length() < 100)
		{
			toPlayer = toPlayer.normalize();
			DrawLine(m_pPlayer->playerLeft().x, m_pPlayer->playerLeft().y,
				m_pEnemy->EnemyLeft()[i].x, m_pEnemy->EnemyLeft()[i].y, 0xffff00);// 線を描画

			m_deadEnemy[i] = false;
		}


	}


	return this;
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
	m_pEnemy->Draw();

	DrawCircle(m_pPlayer->playerLeft().x, m_pPlayer->playerLeft().y, 100, 0xffffff, FALSE);
}