#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Update();
	void Draw();
private:
	int enemyPosx, enemyPosy; // ˆÊ’uÀ•W
	int enemyPosLimit; // “G‚Ì’â~ˆÊ’u
	int enemyGraph; // “G‚Ì‰æ‘œ
	int enemySpeed; // ˆÚ“®‘¬“x
};
