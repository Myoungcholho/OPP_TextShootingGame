#include "CPlayerObject.h"
#include <Windows.h>
#include "szScreen.h"
//#include "CObjectManger.h"
#include "CBulletObject.h"

extern CObjectManger g_Manger;
extern int Player_count;

#define PLAYER_TYPE 0

CPlayerObject::CPlayerObject( int X, int Y) : CBaseObject(PLAYER_TYPE, X, Y)
{
	_BulletCount = 0;
	_hp = 3;

	char_Hp = 0;

	invincibility_activity = false;
	invincibility = 0;
}

void CPlayerObject::InitBulletCount()
{
	_BulletCount = 0;
}

bool CPlayerObject::isValid()
{
	if (_hp < 0)
		return false;
	else
		return true;
}

bool CPlayerObject::Update()
{
	/* hp char 변환*/
	char_Hp = _hp + 48;

	/*hp 가 0이면 유효 오브젝트가 아님 , 게임 종료되어야함 */
	if (_hp <= 0)
	{
		_ObjectType = -1;
		--Player_count;
	}

	/*움직이는 키*/
	if ((GetAsyncKeyState(VK_LEFT) & 0x8001))
		--_iX;
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8001))
		++_iX;
	if ((GetAsyncKeyState(VK_UP) & 0x8001))
		--_iY;
	if ((GetAsyncKeyState(VK_DOWN) & 0x8001))
		++_iY;

	if (_iY > 23)
		_iY = 23;
	else if (_iY < 0)
		_iY = 0;

	if (_iX > 79)
		_iX = 79;
	else if (_iX < 0)
		_iX = 0;

	/* 사용자 총 쏘는 키*/
	/* 총알 처리는 이거 이전에 돼야 정상임 */
	if ((GetAsyncKeyState(VK_SPACE) & 0x8001)) {
		if(_BulletCount < 14)
			g_Manger.CreateObject(new CBulletObject(_iX, _iY));
	}
	/* 총알 개수 누적하는게 아니니 초기화 */
	InitBulletCount();

	/* 총알 개수 확인 */
	for (CList<CBaseObject*>::iterator iter = g_Manger.ObjectList.begin(); iter != g_Manger.ObjectList.end(); ++iter)
	{
		if ((*iter)->GetObjectType() == 3)
		{
			++_BulletCount;
		}
	}

	/* 만약 무적 이라면 */
	if (invincibility_activity)
	{
		invincibility += 1;
		invincibility %= 4;
		/* 3frame 무적 */
		if (invincibility == 3)
		{
			invincibility_activity = false;
		}
	}

	return true;
}


void CPlayerObject::OnCollision(CBaseObject* para)
{
	/* 충돌한게 적의 총알 (4번) 이라면 */
	if (para->GetObjectType() == 4 && !invincibility_activity)
	{
		_hp = _hp - 1;
		invincibility_activity = true;
	}
}

void CPlayerObject::Render()
{
	Sprite_Draw(_iX, _iY, '#');
	Sprite_Draw(76, 0, 'H');
	Sprite_Draw(77, 0, 'P');
	Sprite_Draw(78, 0, ':');
	/* 0~9의 hp밖에 표현 못함 */
	Sprite_Draw(79, 0, char_Hp);
	
}