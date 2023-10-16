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
	/* hp char ��ȯ*/
	char_Hp = _hp + 48;

	/*hp �� 0�̸� ��ȿ ������Ʈ�� �ƴ� , ���� ����Ǿ���� */
	if (_hp <= 0)
	{
		_ObjectType = -1;
		--Player_count;
	}

	/*�����̴� Ű*/
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

	/* ����� �� ��� Ű*/
	/* �Ѿ� ó���� �̰� ������ �ž� ������ */
	if ((GetAsyncKeyState(VK_SPACE) & 0x8001)) {
		if(_BulletCount < 14)
			g_Manger.CreateObject(new CBulletObject(_iX, _iY));
	}
	/* �Ѿ� ���� �����ϴ°� �ƴϴ� �ʱ�ȭ */
	InitBulletCount();

	/* �Ѿ� ���� Ȯ�� */
	for (CList<CBaseObject*>::iterator iter = g_Manger.ObjectList.begin(); iter != g_Manger.ObjectList.end(); ++iter)
	{
		if ((*iter)->GetObjectType() == 3)
		{
			++_BulletCount;
		}
	}

	/* ���� ���� �̶�� */
	if (invincibility_activity)
	{
		invincibility += 1;
		invincibility %= 4;
		/* 3frame ���� */
		if (invincibility == 3)
		{
			invincibility_activity = false;
		}
	}

	return true;
}


void CPlayerObject::OnCollision(CBaseObject* para)
{
	/* �浹�Ѱ� ���� �Ѿ� (4��) �̶�� */
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
	/* 0~9�� hp�ۿ� ǥ�� ���� */
	Sprite_Draw(79, 0, char_Hp);
	
}