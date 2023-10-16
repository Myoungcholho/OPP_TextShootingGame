#include <stdio.h>
#include <memory.h>
#include <Windows.h>
#include "CPlayerObject.h"
#include "szScreen.h" 
#include "CObjectManger.h"
#include "CEnemyObject.h"
#include "SceneManger.h"
#include "InfoFile.h" // Enemy ����ü�� ������
#include "MonsterMoveInfo.h"

#define MOVETYPE_COUNT 10

/*
TYPE
-1: �����Ǳ� �ٶ�� ��ü
0 : player
1 : Enemy
3 : Bullet(player)
4 : Bullet(Enemy)
*/

CObjectManger g_Manger;
SceneManger g_ScManger;

/* ���� ���� �������� */
char* fileStartPoint[FILE_MAX_NUM];		// Enemy ���ϸ� ����
Enemy _Enemy[ENEMYNUM];					// �о���� ������ �� Enemy��ǥ
int f_count = 0;						// ���� �д� ������ ��ȣ ����
int p_iCnt;								// ���� ���� ����

/* monster ������ ��������*/
MoveInfo* M_Info[MOVETYPE_COUNT];		// ������ ����
char* EnemyMovePoint[MOVETYPE_COUNT];	// ���ϸ� ����


int main(void)
{
	cs_Initial();
	
	p_iCnt = InitFile("stageinfo.txt");
	InitMonsterMove("EnemyMoveInfo.txt");
	while (1)
	{
		g_ScManger.run();
		
		Sleep(100);
	}
	
	//free(EnemyMovePoint);
	//free(M_Info);
	//free(fileStartPoint);

}



