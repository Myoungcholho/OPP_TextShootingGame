#include "SceneBase.h"

class End : public SceneBase
{
private:
	bool mode_check = false;
public:
	End();
	~End();
public:
	virtual void Update();
	virtual void Render();
};