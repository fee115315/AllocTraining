#pragma once

#include "ObjectEnemy.h"

//�w�肵�ĕ����ɔ��ł����G
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