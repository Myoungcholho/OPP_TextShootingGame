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
	/* Ư�� ��ü�� ã�� ���� type�� -1 �̶�� */
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
			/* ������ �浹ó�� �� �ʿ� ����*/
			if (*iter == *target)
				continue;

			if (target_pObject->_iX == pObject->_iX)
			{
				if (target_pObject->_iY == pObject->_iY)
				{
					/* ��ǥ�� �� ���� ��ġ�� hp�� ���޾Ƽ� ���� �� ���� -> �����ð����� ó�� */
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