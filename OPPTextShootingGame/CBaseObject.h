#pragma once
#include "CObjectManger.h"

class CBaseObject
{
public:
	CBaseObject();
	CBaseObject(int ObjectType, int X, int Y);


	virtual ~CBaseObject();

	virtual bool Update() = 0;
	virtual void Render() = 0;
	virtual void OnCollision(CBaseObject* para);

	int GetObjectType();


	friend void CObjectManger::Update();

protected:
	int _iX;
	int _iY;
	int _ObjectType;
	int s_count;
};