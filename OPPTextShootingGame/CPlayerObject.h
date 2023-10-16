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
	/* player �� �ʿ��� ���� �߰�*/
	int _BulletCount;
	int _hp;

	/* ȭ�鿡 ���� hp */
	char char_Hp; 

	/* �����ð� üũ */
	bool invincibility_activity;
	short invincibility;
};