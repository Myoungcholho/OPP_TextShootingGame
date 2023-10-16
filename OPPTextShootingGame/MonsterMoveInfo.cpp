#define _CRT_SECURE_NO_WARNINGS
#include "MonsterMoveInfo.h"
#include <Windows.h>
#include <iostream>

#define MOVETYPE_COUNT 10

extern MoveInfo* M_Info[MOVETYPE_COUNT];
extern char* EnemyMovePoint[MOVETYPE_COUNT];

/*
1. ��ǥ ���ϸ� const char* str�� �޾Ƽ�
2. Move1.txt, Move2.txt, Move3.txt ... �� �޾ƿ´� -> 3��
3. 3����� ���� �����ϸ� 3�� �ݺ��ؼ� �������� M_Info[i] �� x,y �̵���� ���� �ִ´�
4. Enemy ���Ͽ��� type ���¿� ���� �ش� �迭�� �ִ� ������ ��ǥ�� ���������� �����Ѵ�. 

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
		printf("���� ���� ����");
		return;
	}

	fseek(pfile, 0, SEEK_END);
	pfileSize = ftell(pfile);
	rewind(pfile);

	char* fileMemory = (char*)malloc(pfileSize);
	char* fileMemory_reset = fileMemory;

	if (1 != fread(fileMemory, pfileSize, 1, pfile))
	{
		/* ���� �о���� ���� */
	}

	
	char* fileName[10];

	/* ���� ����*/
	int p_iCnt = *fileMemory - '0';

	fileMemory += 2;

	for (int i = 0; i < p_iCnt; ++i)
	{
		fileName[i] = (char*)malloc(20);
		/* �����Ҵ��� ���� �ּҸ� ����Ű�� */
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
			printf("���� �� �� ����");
			return;
		}

		fseek(pfile, 0, SEEK_END);
		pileSize = ftell(pfile);
		rewind(pfile);

		char* fileMemory = (char*)malloc(pileSize);
		char* fileMemory_reset = fileMemory;

		if (1 != fread(fileMemory, pileSize, 1, pfile))
		{
			// "rt"�� 0d 0A�� �ƴ϶�  1�� ��ȯ���� �ʰ� ����,, ��� ó���ؾ� �ұ�
		}

		/*0x0a = ����Ű, 0�̸� ������ ���� ������ */
		/* MoveInfo* M_Info[10] �� ������ �� �ִ� �� ���� ����  F5�� �ι� ������ */
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

		// static ���� 1 ����
		++fileCount;

		free(fileMemory_reset);
		fclose(pfile);

	}
}