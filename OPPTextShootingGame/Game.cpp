#include "Game.h"
#include "szScreen.h"
#include "SceneManger.h"
#include "CObjectManger.h"
#include "CPlayerObject.h"
#include "CEnemyObject.h"
#include "InfoFile.h"

#define CLEAR 3
#define OVER 4
#define END 6

extern SceneManger g_ScManger;
extern CObjectManger g_Manger;

/* 파일 카운트 */
extern int p_iCnt; // 파일 개수
extern int f_count; // 현재 진행하고있는 파일 개수

/* 개체 수 저장 */
int Monster_count;
int Player_count;

//extern Enemy _Enemy[ENEMYNUM];

Game::Game()
{
	/* 개체 수 정리 */
	Monster_count =0;
	Player_count =0;
	/* List 내 메모리 정리*/
	g_Manger.List_Clear();

	/* 파일 정보 불러오기 */
	if (p_iCnt > f_count) {
		stageInput(); //fileStartPoint, f_count, _Enemy
		++f_count;
	}
	else {
		g_ScManger.LoadScene(END);
	}


	g_Manger.CreateObject(new CPlayerObject(20, 20));
	++Player_count;

	
	for (int i = 0; _Enemy[i].isValid == true; ++i)
	{
		/*  hp, x좌표 y좌표, type */
		g_Manger.CreateObject(new CEnemyObject(_Enemy[i].E_Hp,_Enemy[i].E_x, _Enemy[i].E_y, _Enemy[i].type));
		++Monster_count;
	}	
}

Game::~Game()
{

}

void Game::Update()
{
	/* 그냥 옵젝 순회함 */
	g_Manger.Update();

	/* type -1 정리 erase해서 update에서 빼버림 */
	g_Manger.DestroyObject();


	/* 몬스터 다 처리하면 */
	if (Monster_count == 0)
	{
		g_ScManger.LoadScene(CLEAR);
	}

	/* 플레이어가 죽으면 */
	else if (Player_count == 0)
	{
		g_ScManger.LoadScene(OVER);
	}


}

void Game::Render()
{
	g_Manger.Render();
}