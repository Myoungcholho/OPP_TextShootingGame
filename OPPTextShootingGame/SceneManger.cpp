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
	/* 프로그램 끝낼 때 현재 화면 정리 후 종료
		지금은 exit로 강제종료 중이라 여기 들어올 일 없음. */
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
	/* 파괴 */
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