#pragma once

#include "ObjectEnemy.h"

//�w�肵�ĕ����ɔ��ł����G
class ObjectEnemyDir:public ObjectEnemy
{
public:
	ObjectEnemyDir();
	virtual ~ObjectEnemyDir();

	virtual void update();

	//���ł����������w�肷��i�p�x�j(���������O�Ƃ��āA�����v���̊p�x���w�肷��
	void setDir(float degree);

private:
	Vec2 m_vec;


};