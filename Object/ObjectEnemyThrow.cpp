#include"ObjectEnemyThrow.h"
#include "DxLib.h"
#include "game.h"

ObjectEnemyThrow::ObjectEnemyThrow():
	m_vec(10.0f,-10.0f)
{
}

ObjectEnemyThrow::~ObjectEnemyThrow()
{


}

void ObjectEnemyThrow::update()
{
	if (!m_isExist)return;
	m_pos += m_vec;
	m_vec.y += 2.0f;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
	if (m_pos.x < -10)
	{
		m_isExist = false;
	}
	if (m_pos.y > Game::kScreenHeight)
	{
		m_isExist = false;
	}
	if (m_pos.y < -10)
	{
		m_isExist = false;
	}
}



