//#include "CObjectManger.h"
//#include "CPlayerObject.h"
#include "CBaseObject.h"

CObjectManger::CObjectManger()
{

}

void CObjectManger::CreateObject(CBaseObject* COBject)
{
	ObjectList.push_back(COBject);
}

void CObjectManger::DestroyObject()
{
	/* 특정 객체를 찾는 기준 type이 -1 이라면 */
	CList<CBaseObject*>::iterator iter;
	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		if ((*iter)->GetObjectType() == -1)
		{
			iter = ObjectList.erase(*iter);
			if (iter == ObjectList.end())
				break;
		}
	}
}

void CObjectManger::Update()
{
	CList<CBaseObject*>::iterator iter;
	CBaseObject* pObject;
	CBaseObject* target_pObject;
	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		pObject = (*iter);
		pObject->Update();

		CList<CBaseObject*>::iterator target;
		for (target = ObjectList.begin(); target != ObjectList.end(); ++target)
		{
			target_pObject = (*target);
			/* 본인은 충돌처리 할 필요 없음*/
			if (*iter == *target)
				continue;

			if (target_pObject->_iX == pObject->_iX)
			{
				if (target_pObject->_iY == pObject->_iY)
				{
					/* 좌표가 좀 오래 겹치면 hp가 연달아서 깎일 수 있음 -> 무적시간으로 처리 */
					pObject->OnCollision(target_pObject);
					target_pObject->OnCollision(pObject);
				}
			}
			

			
		}
	}

}

void CObjectManger::Render()
{
	CList<CBaseObject*>::iterator iter;
	for (iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		(*iter)->Render();
	}
}

void CObjectManger::List_Clear()
{
	ObjectList.clear();
}