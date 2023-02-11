#pragma once
#include "PICManager.h"
#include "TaskManager.h"
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
	PICManager* picManager = PICManager::GetInstance();
	TaskManager* taskManager = TaskManager::GetInstance();
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

	void Run();
};

