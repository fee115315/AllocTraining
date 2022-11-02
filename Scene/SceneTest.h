#pragma once
#include "SceneBase.h"
#include <vector>

#include "ObjectPlayer.h"
#include "ObjectEnemy.h"
#include "ObjectEnemyDir.h"
#include"ObjectEnemyThrow.h"

class SceneTest : public SceneBase
{
public:
	SceneTest();
	virtual ~SceneTest();


	virtual void init() override;
	virtual void end() override;

	virtual SceneBase* update() override;
	virtual void draw() override;

private:
	int			m_hPlayer;
	int			m_hEnemy;

	ObjectPlayer*	m_pPlayer;
	std::vector<ObjectEnemy*>	m_pEnemy;

	ObjectEnemy* m_pShot;

	// ìGÇÃê∂ê¨
	int			m_enemyInterval;
};