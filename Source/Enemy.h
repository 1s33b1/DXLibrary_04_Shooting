#pragma once
#include <vector>
class Bullet;

class Enemy
{
public:
	Enemy(int x,int y);
	~Enemy();
	void Update(const std::vector<Bullet*>& playerBullets);
	void Draw();
	void CheckCollision(const std::vector<Bullet*>& playerBullets);
	void Shot();
	bool GetIsHit() { return isHit; }
private:
	int enemyPosx, enemyPosy; // ˆÊ’uÀ•W
	int enemyPosLimit; // “G‚Ì’â~ˆÊ’u
	int enemyGraph; // “G‚Ì‰æ‘œ
	int enemySpeed; // ˆÚ“®‘¬“x
	int enemyRadius; // “G‚Ì”¼Œa
	bool isHit; // true:ƒvƒŒƒCƒ„[‚Ì’e‚É“–‚½‚Á‚½
	int shotTimer = 1000; // “G‚ªÅ‰‚Ì’e‚ğŒ‚‚Â‚Æ‚«‚Ìƒ^ƒCƒ}[
};
