#include "ObjectEnemy.h"
#include "game.h"
#include "DxLib.h"
#include "Pad.h"

namespace
{
	constexpr float kSpeed = 8.0f;
}

ObjectEnemy::ObjectEnemy() :
	m_hGraph(-1),
	m_isExist(false),
	m_pos()
{

}

ObjectEnemy::~ObjectEnemy()
{

}

void ObjectEnemy::init()
{
	m_isExist = false;
}

void ObjectEnemy::end()
{

}

void ObjectEnemy::update()
{
	if (!m_isExist)	return;
	m_pos.x -= kSpeed;
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

void ObjectEnemy::draw()
{
	if (!m_isExist)	return;
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_hGraph, true);
}
