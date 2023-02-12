#pragma once
#include "PersonManager.h"
#include "TaskManager.h"
#include <memory>
#include <list>
class App final
{
private:
	App() {};
	~App() {};
	void Initialize();
	void Update();
	void Draw();
	void End();
	void ChengeScene(int sceneNo);
	PersonManager* picManager = PersonManager::GetInstance();
	TaskManager* taskManager = TaskManager::GetInstance();

public:
	enum class SceneNum
	{
		Title,
		NewGame,
		GamePlay,
		GameClear
	};
	App(const App& manager) = delete;
	App& operator= (const App& manager) = delete;
	static App* GetInstance();
	int sceneNo = (int)SceneNum::GameClear;

	void Run();
};

