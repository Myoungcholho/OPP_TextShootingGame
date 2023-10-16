#include "CEnemyBullet.h"
#include "szScreen.h"

#define ENEMY_BULLET 4

CEnemyBullet::CEnemyBullet(int X, int Y) : CBaseObject(ENEMY_BULLET, X, (Y))
{
	// 총알은 플레이어 기준 한칸 위부터지만
	/* 총알 객체는 본인보다 뒤에 있으므로 상관없음*/


}

CEnemyBullet::CEnemyBullet(int X, int Y, int type) : CBaseObject(type, X, Y)
{

}

bool CEnemyBullet::Update()
{
	/* 총알은 아래로 한칸 씩*/
	_iY = _iY + 1;
	/* 총알이 화면 밖을 벗어난다면 type -1로 */
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