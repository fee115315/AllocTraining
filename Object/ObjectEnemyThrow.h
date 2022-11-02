#pragma once

#include "ObjectEnemy.h"

//Žw’è‚µ‚Ä•ûŒü‚É”ò‚ñ‚Å‚¢‚­“G
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