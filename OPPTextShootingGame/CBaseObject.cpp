#include "CBaseObject.h"


CBaseObject::CBaseObject()
{

}

CBaseObject::CBaseObject(int ObjectType, int X, int Y)
{
	_iX = X;
	_iY = Y;
	_ObjectType = ObjectType;
}

CBaseObject::~CBaseObject()
{

}

int CBaseObject::GetObjectType()
{
	return _ObjectType;
}



void CBaseObject::OnCollision(CBaseObject* para)
{

}