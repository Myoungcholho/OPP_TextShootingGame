#pragma once
class SceneBase
{
public:
	int _type;
	bool check_on;

public:
	SceneBase();
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};