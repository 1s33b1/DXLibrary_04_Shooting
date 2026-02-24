#pragma once

class Bullet;

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Update(Bullet* pBullet[]);
	void Draw();
private:
	int enemyPosx, enemyPosy; // ˆÊ’uÀ•W
	int enemyPosLimit; // “G‚Ì’â~ˆÊ’u
	int enemyGraph; // “G‚Ì‰æ‘œ
	int enemySpeed; // ˆÚ“®‘¬“x
	int enemyRadius; // “G‚Ì”¼Œa
	bool isHit; // true:ƒvƒŒƒCƒ„[‚Ì’e‚É“–‚½‚Á‚½
};
