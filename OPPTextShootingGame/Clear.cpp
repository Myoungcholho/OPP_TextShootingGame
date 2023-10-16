#include "Clear.h"
#include "szScreen.h"
#include <Windows.h>
#include "SceneManger.h"

#define GAME 2
#define EXIT 5
#define END 6

extern SceneManger g_ScManger;

/* 파일 카운트 */
extern int p_iCnt; // 파일 개수
extern int f_count; // 현재 진행하고있는 파일 개수

Clear::Clear()
{

}

Clear::~Clear()
{

}

void Clear::Update()
{
	if ((GetAsyncKeyState(VK_UP) & 0x8001))
		mode_check = true;
	if ((GetAsyncKeyState(VK_DOWN) & 0x8001))
		mode_check = false;

	if ((GetAsyncKeyState(VK_RETURN) & 0x8001))
	{
		if (mode_check) {
			/* 다음 스테이지로 넘어감*/
			/* 스테이지 전부 소모했으면 END*/
			if (p_iCnt == f_count) {
				g_ScManger.LoadScene(END);
			}
			else {
				g_ScManger.LoadScene(GAME);
			}
		}
		else {
			g_ScManger.LoadScene(EXIT);
		}
	}
}

void Clear::Render()
{
	for (int i = 8; i < 72; ++i)
		Sprite_Draw(i, 4, '-');

	// Next Level 
	Sprite_Draw(20, 9, 'N');
	Sprite_Draw(21, 9, 'e');
	Sprite_Draw(22, 9, 'x');
	Sprite_Draw(23, 9, 't');
	Sprite_Draw(24, 9, ' ');
	Sprite_Draw(25, 9, 'L');
	Sprite_Draw(26, 9, 'e');
	Sprite_Draw(27, 9, 'v');
	Sprite_Draw(28, 9, 'e');
	Sprite_Draw(29, 9, 'l');

	Sprite_Draw(24, 14, 'N');
	Sprite_Draw(25, 14, 'e');
	Sprite_Draw(26, 14, 'x');
	Sprite_Draw(27, 14, 't');

	Sprite_Draw(23, 17, 'e');
	Sprite_Draw(24, 17, 'x');
	Sprite_Draw(25, 17, 'i');
	Sprite_Draw(26, 17, 't');


	if (mode_check) {
		Sprite_Draw(29, 14, '<');
		Sprite_Draw(30, 14, '-');
	}
	else {
		Sprite_Draw(29, 17, '<');
		Sprite_Draw(30, 17, '-');
	}

	for (int i = 8; i < 72; ++i)
		Sprite_Draw(i, 20, '-');
}