#pragma once
#include "Enemy.h"
#include "../GameParameter.h"
#include <vector>
class Bullet;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update(const std::vector<Bullet*>& playerBullets);
	void Draw();
private:
	std::vector<Enemy*> enemies; // 固定配列からvectorに変更。vectorだと可変のリストを使用することができる。
};