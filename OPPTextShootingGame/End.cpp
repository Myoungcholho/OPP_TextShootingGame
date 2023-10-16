#include "End.h"
#include "szScreen.h"
#include <Windows.h>
#include "SceneManger.h"

#define EXIT 5

extern SceneManger g_ScManger;

End::End()
{

}

End::~End()
{

}

void End::Update()
{
	if ((GetAsyncKeyState(VK_RETURN) & 0x8001))
	{
		g_ScManger.LoadScene(EXIT);
	}
}

void End::Render()
{
	Sprite_Draw(20, 9, 'E');;
	Sprite_Draw(21, 9, 'N');
	Sprite_Draw(22, 9, 'D');
}