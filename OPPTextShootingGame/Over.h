#include "SceneBase.h"

class Over : public SceneBase
{
public:
	bool check_box = false;

public:
	Over();
public:
	virtual void Update();
	virtual void Render();
};