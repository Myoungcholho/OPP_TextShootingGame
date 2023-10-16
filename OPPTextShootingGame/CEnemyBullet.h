#include "CBaseObject.h"

class CEnemyBullet : public CBaseObject
{
public:
	CEnemyBullet(int X, int Y);
	CEnemyBullet(int X, int Y, int type);
public:
	virtual bool Update();
	virtual void Render();

private:

	bool first_render = false;
};