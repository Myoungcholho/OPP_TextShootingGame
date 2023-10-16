#define _CRT_SECURE_NO_WARNINGS
#include "MonsterMoveInfo.h"
#include <Windows.h>
#include <iostream>

#define MOVETYPE_COUNT 10

extern MoveInfo* M_Info[MOVETYPE_COUNT];
extern char* EnemyMovePoint[MOVETYPE_COUNT];

/*
1. 대표 파일명 const char* str을 받아서
2. Move1.txt, Move2.txt, Move3.txt ... 를 받아온다 -> 3개
3. 3개라는 값을 전달하면 3번 반복해서 전역변수 M_Info[i] 에 x,y 이동경로 값을 넣는다
4. Enemy 파일에서 type 형태에 따라 해당 배열에 있는 움직임 좌표를 순차적으로 실행한다. 

*/

/// <summary>
/// sdsdsdsd
/// </summary>
void InitMonsterMove(const char* str)
{

	FILE* pfile;
	int pfileSize;

	pfile = fopen(str, "rt");
	if (pfile == NULL)
	{
		printf("파일 오픈 실패");
		return;
	}

	fseek(pfile, 0, SEEK_END);
	pfileSize = ftell(pfile);
	rewind(pfile);

	char* fileMemory = (char*)malloc(pfileSize);
	char* fileMemory_reset = fileMemory;

	if (1 != fread(fileMemory, pfileSize, 1, pfile))
	{
		/* 파일 읽어오지 못함 */
	}

	
	char* fileName[10];

	/* 파일 개수*/
	int p_iCnt = *fileMemory - '0';

	fileMemory += 2;

	for (int i = 0; i < p_iCnt; ++i)
	{
		fileName[i] = (char*)malloc(20);
		/* 동적할당한 공간 주소를 가르키게 */
		EnemyMovePoint[i] = fileName[i];
	}

	for (int i = 0; i < p_iCnt; ++i)
	{
		while (*fileMemory != 0x0a)
		{
			*fileName[i] = *fileMemory;

			++fileName[i];
			++fileMemory;
		}
		*fileName[i] = '\0';
		++fileMemory;
	}

	free(fileMemory_reset);

	EnemyMoveInput(p_iCnt);
	
}

void EnemyMoveInput(int p_iCnt)
{
	FILE* pfile = NULL;
	int pileSize;

	for (int i = 0; i < p_iCnt; ++i)
	{
		pfile = fopen(EnemyMovePoint[i], "rt");
		if (pfile == NULL)
		{
			printf("파일 열 수 없음");
			return;
		}

		fseek(pfile, 0, SEEK_END);
		pileSize = ftell(pfile);
		rewind(pfile);

		char* fileMemory = (char*)malloc(pileSize);
		char* fileMemory_reset = fileMemory;

		if (1 != fread(fileMemory, pileSize, 1, pfile))
		{
			// "rt"라서 0d 0A가 아니라  1을 반환하지 않고 있음,, 어떻게 처리해야 할까
		}

		/*0x0a = 엔터키, 0이면 다음에 엔터 누를것 */
		/* MoveInfo* M_Info[10] 에 데이터 값 넣는 것 부터 시작  F5번 두번 누르고 */
		int iCnt = 0;
		static int fileCount = 0;

		while (*fileMemory != 0x0a)
		{
			iCnt = iCnt * 10 + (*fileMemory - '0');
			M_Info[fileCount] = (MoveInfo*)malloc(sizeof(MoveInfo));
			M_Info[fileCount]->move_count = iCnt;
			M_Info[fileCount]->d1 = (MoveData*)malloc(sizeof(MoveData) * iCnt);

			++fileMemory;

		}
		if (*fileMemory == 0x0a)
			++fileMemory;

		short input_x;
		short input_y;

		for (int i = 0; i < iCnt; ++i)
		{
			if (*fileMemory == 0x2d)
			{
				++fileMemory;
				input_x = (*fileMemory - '0');
				input_x *= -1;

				M_Info[fileCount]->d1[i].move_x = input_x;
			}
			else
			{
				input_x = (*fileMemory - '0');

				M_Info[fileCount]->d1[i].move_x = input_x;
			}
			fileMemory += 2;


			if (*fileMemory == 0x2d)
			{
				++fileMemory;
				input_y = (*fileMemory - '0');
				input_y *= -1;

				M_Info[fileCount]->d1[i].move_y = input_y;
			}
			else
			{
				input_y = (*fileMemory - '0');

				M_Info[fileCount]->d1[i].move_y = input_y;
			}
			fileMemory += 2;

		}

		// static 변수 1 증가
		++fileCount;

		free(fileMemory_reset);
		fclose(pfile);

	}
}