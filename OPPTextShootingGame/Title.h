#include "SceneBase.h"

class Title : public SceneBase
{
private:
	bool check_box;
public:
	Title();
public:
	virtual void Update();
	virtual void Render();
};