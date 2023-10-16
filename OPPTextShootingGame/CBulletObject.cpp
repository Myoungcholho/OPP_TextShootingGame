#include "CBulletObject.h"
#include "szScreen.h"

// 총알은 플레이어 기준 한칸 위부터

#define PLAYER_BULLET 3

CBulletObject::CBulletObject(int X, int Y) : CBaseObject(PLAYER_BULLET, X, (Y))
{
	
}

CBulletObject::CBulletObject(int X, int Y, int type) : CBaseObject(type, X, Y)
{
	/* 총알 형태 추가하려면 이곳 작업*/
}

bool CBulletObject::Update()
{
	/* 총알은 위로 한칸 씩*/
	_iY = _iY - 1;
	/* 총알이 화면 밖을 벗어난다면 type -1로 */
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