#include "CEnemyBullet.h"
#include "szScreen.h"

#define ENEMY_BULLET 4

CEnemyBullet::CEnemyBullet(int X, int Y) : CBaseObject(ENEMY_BULLET, X, (Y))
{
	// �Ѿ��� �÷��̾� ���� ��ĭ ����������
	/* �Ѿ� ��ü�� ���κ��� �ڿ� �����Ƿ� �������*/


}

CEnemyBullet::CEnemyBullet(int X, int Y, int type) : CBaseObject(type, X, Y)
{

}

bool CEnemyBullet::Update()
{
	/* �Ѿ��� �Ʒ��� ��ĭ ��*/
	_iY = _iY + 1;
	/* �Ѿ��� ȭ�� ���� ����ٸ� type -1�� */
	if (_iY > 23)
	{
		_ObjectType = -1;
	}

	return true;
}

void CEnemyBullet::Render()
{
	Sprite_Draw(_iX, _iY, 'w');
}