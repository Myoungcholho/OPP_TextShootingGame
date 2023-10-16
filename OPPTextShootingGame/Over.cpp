#include "Over.h"
#include "szScreen.h"
#include <Windows.h>
#include "SceneManger.h"

#define TITLE 1
#define GAME 2
#define OVER 4
#define EXIT 5

extern SceneManger g_ScManger;
extern int f_count;

Over::Over()
{
	/* stage 초기화 */
	f_count = 0;
}

void Over::Update()
{
	if ((GetAsyncKeyState(VK_UP) & 0x8001))
	{
		check_box = true;
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x8001))
	{
		check_box = false;
	}


	/* True인 상태로 space 누르면 */
	if ((GetAsyncKeyState(VK_RETURN) & 0x8001) && check_box == true)
	{
		g_ScManger.LoadScene(TITLE);
	}

	if ((GetAsyncKeyState(VK_RETURN) & 0x8001) && check_box == false)
	{
		g_ScManger.LoadScene(EXIT);
	}
}

void Over::Render()
{
	for (int i = 8; i < 72; ++i)
		Sprite_Draw(i, 4, '-');

	for (int i = 8; i < 72; ++i)
		Sprite_Draw(i, 20, '-');

	{
		Sprite_Draw(20, 9, 'g');
		Sprite_Draw(21, 9, 'a');
		Sprite_Draw(22, 9, 'm');
		Sprite_Draw(23, 9, 'e');
		
		Sprite_Draw(25, 9, 'e');
		Sprite_Draw(26, 9, 'n');
		Sprite_Draw(27, 9, 'd');

		Sprite_Draw(23, 14, 'r');
		Sprite_Draw(24, 14, 'e');
		Sprite_Draw(25, 14, 's');
		Sprite_Draw(26, 14, 'e');
		Sprite_Draw(27, 14, 't');

		Sprite_Draw(23, 17, 'e');
		Sprite_Draw(24, 17, 'x');
		Sprite_Draw(25, 17, 'i');
		Sprite_Draw(26, 17, 't');
	}

	if (check_box == true)
	{
		Sprite_Draw(29, 14, '<');
		Sprite_Draw(30, 14, '-');
	}
	else if (check_box == false)
	{
		Sprite_Draw(29, 17, '<');
		Sprite_Draw(30, 17, '-');
	}
}