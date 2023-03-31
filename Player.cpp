#include <DxLib.h>
#include "game.h"
#include "Player.h"

Player::Player():
	m_pos(0.0f,0.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_pos = { Game::kScreenWidth / 2,Game::kScreenHeight / 2 };
}

void Player::End()
{
}

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_W))
	{
		m_pos.y -= 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		m_pos.y += 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		m_pos.x -= 3.0f;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		m_pos.x += 3.0f;
	}

}

void Player::Draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + 10, m_pos.y + 10, 0xffffff, true);
}
