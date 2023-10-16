#include "CBulletObject.h"
#include "szScreen.h"

// �Ѿ��� �÷��̾� ���� ��ĭ ������

#define PLAYER_BULLET 3

CBulletObject::CBulletObject(int X, int Y) : CBaseObject(PLAYER_BULLET, X, (Y))
{
	
}

CBulletObject::CBulletObject(int X, int Y, int type) : CBaseObject(type, X, Y)
{
	/* �Ѿ� ���� �߰��Ϸ��� �̰� �۾�*/
}

bool CBulletObject::Update()
{
	/* �Ѿ��� ���� ��ĭ ��*/
	_iY = _iY - 1;
	/* �Ѿ��� ȭ�� ���� ����ٸ� type -1�� */
	if (_iY < 0)
	{
		_ObjectType = -1;
	}

	return true;
}

void CBulletObject::Render()
{
	Sprite_Draw(_iX, _iY, '^');
}