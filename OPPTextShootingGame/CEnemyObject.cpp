#include "CEnemyObject.h"
#include "szScreen.h"
//#include "CObjectManger.h"
#include "CEnemyBullet.h"
#include "MonsterMoveInfo.h"

#define MONSTER_TYPE 1
#define MOVETYPE_COUNT 10

extern CObjectManger g_Manger;
extern int Monster_count;
/* 움직임 전역배열 */
extern MoveInfo* M_Info[MOVETYPE_COUNT];

CEnemyObject::CEnemyObject(int hp, int iX, int iY, int type) : CBaseObject(MONSTER_TYPE, iX, iY)
{
	/* 생성자에 로직 짜지 말라고 했던 것 같은데 ? */
	/* 근데 딱 한번만 하고 싶은데 어디다 써 */
	_hp = hp;
	_type = type;
	_BulletCount = 0;
	s_count = 0;
}

CEnemyObject::~CEnemyObject()
{

}

void CEnemyObject::InitBulletCount()
{
	_BulletCount = 0;
}

bool CEnemyObject::Update()
{
	/* 피가 0 이하가 되면 유효옵젝이 아님(-1) */
	if (_hp < 0 && _ObjectType != -1)
	{
		_ObjectType = -1;
		--Monster_count;
	}

	/* 총알 쏘는 로직 */
	if (_BulletCount == 0)
	{
		g_Manger.CreateObject(new CEnemyBullet(_iX,_iY));
	}
	
	/* 총알 개수 누적하는게 아니니 초기화 */
	InitBulletCount();

	/* 총알 개수 확인 */
	for (CList<CBaseObject*>::iterator iter = g_Manger.ObjectList.begin(); iter != g_Manger.ObjectList.end(); ++iter)
	{
		if ((*iter)->GetObjectType() == 4)
		{
			++_BulletCount;
		}
	}

	/* 움직임 */
	move_monster();

	return true;
}

void CEnemyObject::move_monster()
{
	if (M_Info[_type]->move_count == 0)
		return;
	_iX += M_Info[_type]->d1[s_count].move_x;
	_iY += M_Info[_type]->d1[s_count].move_y;

	s_count = (s_count + 1) % M_Info[_type]->move_count;
}

void CEnemyObject::OnCollision(CBaseObject* para)
{
	/* 충돌처리된 옵젝이 총알(3번) 이라면 hp -1 */
	if (para->GetObjectType() == 3)
	{
		_hp = _hp - 1;
	}
}

void CEnemyObject::Render()
{
	Sprite_Draw(_iX, _iY, '@');
}