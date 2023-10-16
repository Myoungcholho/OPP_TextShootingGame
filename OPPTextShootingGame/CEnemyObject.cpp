#include "CEnemyObject.h"
#include "szScreen.h"
//#include "CObjectManger.h"
#include "CEnemyBullet.h"
#include "MonsterMoveInfo.h"

#define MONSTER_TYPE 1
#define MOVETYPE_COUNT 10

extern CObjectManger g_Manger;
extern int Monster_count;
/* ������ �����迭 */
extern MoveInfo* M_Info[MOVETYPE_COUNT];

CEnemyObject::CEnemyObject(int hp, int iX, int iY, int type) : CBaseObject(MONSTER_TYPE, iX, iY)
{
	/* �����ڿ� ���� ¥�� ����� �ߴ� �� ������ ? */
	/* �ٵ� �� �ѹ��� �ϰ� ������ ���� �� */
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
	/* �ǰ� 0 ���ϰ� �Ǹ� ��ȿ������ �ƴ�(-1) */
	if (_hp < 0 && _ObjectType != -1)
	{
		_ObjectType = -1;
		--Monster_count;
	}

	/* �Ѿ� ��� ���� */
	if (_BulletCount == 0)
	{
		g_Manger.CreateObject(new CEnemyBullet(_iX,_iY));
	}
	
	/* �Ѿ� ���� �����ϴ°� �ƴϴ� �ʱ�ȭ */
	InitBulletCount();

	/* �Ѿ� ���� Ȯ�� */
	for (CList<CBaseObject*>::iterator iter = g_Manger.ObjectList.begin(); iter != g_Manger.ObjectList.end(); ++iter)
	{
		if ((*iter)->GetObjectType() == 4)
		{
			++_BulletCount;
		}
	}

	/* ������ */
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
	/* �浹ó���� ������ �Ѿ�(3��) �̶�� hp -1 */
	if (para->GetObjectType() == 3)
	{
		_hp = _hp - 1;
	}
}

void CEnemyObject::Render()
{
	Sprite_Draw(_iX, _iY, '@');
}