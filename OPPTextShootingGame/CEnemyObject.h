#include "CBaseObject.h"

class CEnemyObject : public CBaseObject
{
public:
	CEnemyObject(int hp, int iX, int iY, int type);
	virtual ~CEnemyObject();

	virtual bool Update();
	virtual void Render();
	void InitBulletCount();
	virtual void OnCollision(CBaseObject* para);
	void move_monster();

private:
	int _type;
	int _hp;
	int _BulletCount;
};