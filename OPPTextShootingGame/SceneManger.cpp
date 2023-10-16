#include "SceneManger.h"
#include "Title.h"
#include "Over.h"
#include "Game.h"
#include "Clear.h"
#include "End.h"
#include "szScreen.h"
#include <stdlib.h>

#define TITLE 1
#define GAME 2
#define CLEAR 3
#define OVER 4
#define EXIT 5
#define END 6

SceneManger::SceneManger()
{
	ScnenList  = new Title();
}

SceneManger::~SceneManger()
{
	/* ���α׷� ���� �� ���� ȭ�� ���� �� ����
		������ exit�� �������� ���̶� ���� ���� �� ����. */
	if (ScnenList != nullptr)
	{
		delete ScnenList;
	}
}

void SceneManger::run()
{
	ScnenList->Update();


	Buffer_Clear();

	ScnenList->Render();

	Buffer_Flip();

	if (Destory != nullptr)
	{
		delete Destory;
		Destory = nullptr;
	}
}

void SceneManger::LoadScene(int ScnenType)
{
	/* �ı� */
	Destory = ScnenList;

	switch (ScnenType)
	{
	case TITLE:
		ScnenList = new Title();
		break;
	case GAME:
		ScnenList = new Game();
		break;
	case CLEAR:
		ScnenList = new Clear();
		break;
	case OVER:
		ScnenList = new Over();
		break;
	case END:
		ScnenList = new End();
		break;
	case EXIT:
		exit(0);
		break;
	}
}