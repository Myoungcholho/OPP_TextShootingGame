#pragma once
#include"structEnemy.h"

#define FILE_MAX_NAME 20
#define FILE_MAX_NUM 10
#define ENEMYNUM 20

extern char* fileStartPoint[FILE_MAX_NUM]; // 파일 이름 저장
extern int f_count;				// 현재 몇번째 파일인지 확인
extern Enemy _Enemy[ENEMYNUM];	// 파일 데이터 저장 용

short my_atoi(short* input);
void stageInput(); //char* fileStartPoint[10], int p_count, Enemy e[20]
int InitFile(const char* str); //, char* fileStartPoint[10]