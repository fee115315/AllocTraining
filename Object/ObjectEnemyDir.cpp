#include"ObjectEnemyDir.h"
#include "DxLib.h"
#include "game.h"

ObjectEnemyDir::ObjectEnemyDir():
	m_vec()
{
}

ObjectEnemyDir::~ObjectEnemyDir()
{


}

void ObjectEnemyDir::update()
{
	if (!m_isExist)return;
	m_pos += m_vec;

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

void ObjectEnemyDir::setDir(float degree)
{

	float rad = degree * DX_PI_F / 180.0;			//ƒ‰ƒWƒAƒ“•ÏŠ·

	m_vec.x = cosf(rad);
	m_vec.y = sinf(rad);
	m_vec *= 21;

}