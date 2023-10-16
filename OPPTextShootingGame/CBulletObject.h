#include "CBaseObject.h"

class CBulletObject : public CBaseObject
{
public:
	CBulletObject(int X, int Y);
	CBulletObject(int X, int Y, int type);
public:
	virtual bool Update();
	virtual void Render();

private:

	bool first_render = false;
};