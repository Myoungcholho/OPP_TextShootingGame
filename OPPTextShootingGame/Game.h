#include "SceneBase.h"

class Game : public SceneBase
{
public:
	Game();
	~Game();

public:
	virtual void Update();
	virtual void Render();

};