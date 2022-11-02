#pragma once

#include "ObjectEnemy.h"

//指定して方向に飛んでいく敵
class ObjectEnemyThrow :public ObjectEnemy
{
public:
	ObjectEnemyThrow();
	virtual ~ObjectEnemyThrow();

	virtual void update();

	void setThrow(float degree);

private:
	Vec2 m_vec;


};