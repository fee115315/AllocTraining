#pragma once

#include "ObjectEnemy.h"

//指定して方向に飛んでいく敵
class ObjectEnemyDir:public ObjectEnemy
{
public:
	ObjectEnemyDir();
	virtual ~ObjectEnemyDir();

	virtual void update();

	//飛んでいく方向を指定する（角度）(左方向を０として、反時計回りの角度を指定する
	void setDir(float degree);

private:
	Vec2 m_vec;


};