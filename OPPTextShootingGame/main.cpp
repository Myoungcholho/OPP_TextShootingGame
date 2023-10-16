#include <stdio.h>
#include <memory.h>
#include <Windows.h>
#include "CPlayerObject.h"
#include "szScreen.h" 
#include "CObjectManger.h"
#include "CEnemyObject.h"
#include "SceneManger.h"
#include "InfoFile.h" // Enemy 구조체도 포함함
#include "MonsterMoveInfo.h"

#define MOVETYPE_COUNT 10

/*
TYPE
-1: 삭제되길 바라는 객체
0 : player
1 : Enemy
3 : Bullet(player)
4 : Bullet(Enemy)
*/

CObjectManger g_Manger;
SceneManger g_ScManger;

/* 파일 관련 전역변수 */
char* fileStartPoint[FILE_MAX_NUM];		// Enemy 파일명 저장
Enemy _Enemy[ENEMYNUM];					// 읽어오고 저장할 값 Enemy좌표
int f_count = 0;						// 현재 읽는 파일의 번호 저장
int p_iCnt;								// 파일 개수 저장

/* monster 움직임 전역변수*/
MoveInfo* M_Info[MOVETYPE_COUNT];		// 움직임 저장
char* EnemyMovePoint[MOVETYPE_COUNT];	// 파일명 저장


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



