#include "SceneBase.h"

class SceneManger
{
private:
	SceneBase *ScnenList;
	SceneBase* Destory;

protected:
	
public:
	SceneManger();
	~SceneManger();

	void run();
	void LoadScene(int SceneType);
	//void DestroyScene();
};