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

	void Update(); // 순회하며 Update호출
	void Render(); // 순회하며 Render호출

};