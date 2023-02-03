#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "IShape.h"
#include <memory>
#include <list>
class SceneManager final
{
private:
	SceneManager() {};
	~SceneManager() {};
	void Initialize();
	void Update();
	void Draw();
	void ChengeScene(int sceneNo);
public:
	enum class SceneNum
	{
		Title,
		NewGame,
		GamePlay,
		GameClear
	};
	SceneManager(const SceneManager& manager) = delete;
	SceneManager& operator= (const SceneManager& manager) = delete;
	static SceneManager* GetInstance();
	int sceneNo = (int)SceneNum::GameClear;
	std::unique_ptr<IShape> shapeC;
	std::unique_ptr<IShape> shapeR;
	void Run();
};

