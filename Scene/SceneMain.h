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
			//printfDx("�z��쐬���s\n");
		}

		return m_deadEnemy;
	}
private:
	Vec2 m_pos;//�v���C���[�̈ʒu
	bool m_deadEnemy[100];
	Player* m_pPlayer;
	Enemy* m_pEnemy;
};
