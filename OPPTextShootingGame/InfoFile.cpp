#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "InfoFile.h"


short my_atoi(short* input)
{
	char* imsi = (char*)input;
	short a = 0;

	for (int i = 0; i < 2; ++i)
	{
		a = a * 10 + (*imsi - '0');
		++imsi;
	}

	return a;
}


void stageInput() //char* fileStartPoint[FILE_MAX_NUM], int f_count, Enemy _Enemy[ENEMYNUM]
{
	FILE* pfile = NULL;
	int pileSize;

	pfile = fopen(fileStartPoint[f_count], "rt");
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

	int iCnt = 0;
	while (*fileMemory != 0x0a)
	{
		iCnt = iCnt * 10 + (*fileMemory - '0');

		++fileMemory;
	}
	++fileMemory;

	/* 이전 ENEMY 값 초기화 */
	for (int i = 0; i < ENEMYNUM; ++i)
	{
		_Enemy[i].isValid = false;
	}

	for (int i = 0; i < iCnt; ++i)
	{
		_Enemy[i].isValid = *fileMemory - '0';
		fileMemory += 2;

		_Enemy[i].E_Hp = my_atoi((short*)fileMemory);
		fileMemory += 3;

		_Enemy[i].E_x = my_atoi((short*)fileMemory);
		fileMemory += 3;

		_Enemy[i].E_y = my_atoi((short*)fileMemory);
		fileMemory += 3;

		_Enemy[i].type = *fileMemory - '0';
		fileMemory += 2;
	}

	free(fileMemory_reset);
	fclose(pfile);
}

/* 스테이지 파일 읽어오기*/
/* 한번만 할 것 */
int InitFile(const char* str) //, char* fileStartPoint[FILE_MAX_NUM]
{
	FILE* pfile;
	int pileSize;

	pfile = fopen(str, "rt");
	if (pfile == NULL)
	{
		printf("파일 오픈 실패");
		return 0;
	}
	fseek(pfile, 0, SEEK_END);
	pileSize = ftell(pfile);
	rewind(pfile);

	char* fileMemory = (char*)malloc(pileSize);
	char* fileMemory_reset = fileMemory;

	if (1 != fread(fileMemory, pileSize, 1, pfile))
	{

	}

	char* fileName[FILE_MAX_NUM];

	/* 파일 개수*/
	int p_iCnt = *fileMemory - '0';

	fileMemory += 2;

	for (int i = 0; i < p_iCnt; ++i)
	{
		fileName[i] = (char*)malloc(FILE_MAX_NAME);
		/* 주소를 가르키게 */
		fileStartPoint[i] = fileName[i];
	}

		/* 주소 안에 데이터 값 넣기 */
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

	return p_iCnt;
}