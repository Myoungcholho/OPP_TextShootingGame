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

/* ���� ī��Ʈ */
extern int p_iCnt; // ���� ����
extern int f_count; // ���� �����ϰ��ִ� ���� ����

/* ��ü �� ���� */
int Monster_count;
int Player_count;

//extern Enemy _Enemy[ENEMYNUM];

Game::Game()
{
	/* ��ü �� ���� */
	Monster_count =0;
	Player_count =0;
	/* List �� �޸� ����*/
	g_Manger.List_Clear();

	/* ���� ���� �ҷ����� */
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
		/*  hp, x��ǥ y��ǥ, type */
		g_Manger.CreateObject(new CEnemyObject(_Enemy[i].E_Hp,_Enemy[i].E_x, _Enemy[i].E_y, _Enemy[i].type));
		++Monster_count;
	}	
}

Game::~Game()
{

}

void Game::Update()
{
	/* �׳� ���� ��ȸ�� */
	g_Manger.Update();

	/* type -1 ���� erase�ؼ� update���� ������ */
	g_Manger.DestroyObject();


	/* ���� �� ó���ϸ� */
	if (Monster_count == 0)
	{
		g_ScManger.LoadScene(CLEAR);
	}

	/* �÷��̾ ������ */
	else if (Player_count == 0)
	{
		g_ScManger.LoadScene(OVER);
	}


}

void Game::Render()
{
	g_Manger.Render();
}