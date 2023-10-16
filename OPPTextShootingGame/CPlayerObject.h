#include "CBaseObject.h"

class CPlayerObject : public CBaseObject
{
public:
	CPlayerObject( int X, int Y);


	virtual bool Update();
	virtual void Render();
	virtual void OnCollision(CBaseObject* para);

	void InitBulletCount();
	bool isValid();
private:
	/* player 에 필요한 변수 추가*/
	int _BulletCount;
	int _hp;

	/* 화면에 보일 hp */
	char char_Hp; 

	/* 무적시간 체크 */
	bool invincibility_activity;
	short invincibility;
};