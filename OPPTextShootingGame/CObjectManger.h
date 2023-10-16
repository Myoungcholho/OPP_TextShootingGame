#pragma once
#include "linkedlist.h"

class CBaseObject;

class CObjectManger
{
public:
	CList<CBaseObject*> ObjectList;

public:
	CObjectManger();

public:
	void CreateObject(CBaseObject* COBject);
	void DestroyObject(); 
	void List_Clear();

	void Update(); // ��ȸ�ϸ� Updateȣ��
	void Render(); // ��ȸ�ϸ� Renderȣ��

};