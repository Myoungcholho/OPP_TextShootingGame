#include "SceneBase.h"

class Clear : public SceneBase
{
private:
	bool mode_check = false;
public:
	Clear();
	~Clear();
public:
	virtual void Update();
	virtual void Render();
};