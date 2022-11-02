#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"
#include"ObjectEnemyThrow.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";
	const char* const kEnemyFilename = "Data/enemy.bmp";

	// �����ɓo�ꂷ��G�̍ő吔
	constexpr int kEnemyMax = 32;

	// �G�̐����Ԋu(�t���[����)
	constexpr int kEnemyInterval = 30;
}

SceneTest::SceneTest() :
	m_hPlayer(-1),
	m_hEnemy(-1),
	m_pPlayer(nullptr),
	m_pEnemy(kEnemyMax,nullptr),
	m_enemyInterval(0)
{
	m_pPlayer = new ObjectPlayer;

	/*for (auto& pEnemy : m_pEnemy)
	{
		pEnemy = new ObjectEnemy;
	}*/
}
SceneTest::~SceneTest()
{
	delete m_pPlayer;

	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy) //�k���o�Ȃ���
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}
}

void SceneTest::init()
{
	m_hPlayer = LoadGraph(kPlayerFilename);
	m_hEnemy = LoadGraph(kEnemyFilename);

	m_pPlayer->init();
	m_pPlayer->setHandle(m_hPlayer);

	m_enemyInterval = 0;
}

void SceneTest::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hEnemy);

	for (auto& pEnemy : m_pEnemy)
	{
		delete pEnemy;
	}
}

SceneBase* SceneTest::update()
{
	m_pPlayer->update();
	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy) continue;

		pEnemy->update();
		if (!pEnemy->isExist())
		{
			delete pEnemy;
			pEnemy = nullptr;
		}

	}

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		// �g�p����Ă��Ȃ��G��T���Ă�����g��
		for (auto& pEnemy : m_pEnemy)
		{
			if (!pEnemy) //null�̂Ƃ�
			{
				switch (GetRand(2))
				{
				case 0:
					pEnemy = new ObjectEnemy;
					break;
				case 1:
				{
				    ObjectEnemyDir* pTempEnemy = new ObjectEnemyDir;
 
				    pEnemy = pTempEnemy;
				    break;
				}
				case 2:
				default:
					pEnemy = new ObjectEnemyThrow;
					break;
				}

				pEnemy->init();
				pEnemy->setHandle(m_hEnemy);
				pEnemy->setExist(true);

				ObjectEnemyDir* pTemp = dynamic_cast<ObjectEnemyDir*>(pEnemy);  //�p�����̃|�C���g���p����ɕϊ��o����B�t���\�B
				if (pTemp)
				{
					pTemp->setDir(120.0f);

				}
				Vec2 pos{ Game::kScreenWidth/2, Game::kScreenHeight/2 };
				pEnemy->setPos(pos);
				break;

			}
					
			
		}

		m_enemyInterval = 0;
	}
	return this;
}

void SceneTest::draw()
{
	m_pPlayer->draw();
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy) pEnemy->draw();
	}


	int num = 0;

	for (auto& pEnemy : m_pEnemy)
	{
		if ((pEnemy)&&(pEnemy->isExist()))
		{
			num++;
		}
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�G�̐�%d", num);
}

