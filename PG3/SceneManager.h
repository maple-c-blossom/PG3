#pragma once
class SceneManager final
{
private:
	SceneManager() {};
	~SceneManager() {};
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
	void Run();
};

