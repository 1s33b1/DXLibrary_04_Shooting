#pragma once
#include "Enemy.h"
#include "../GameParameter.h"
#include <vector>
class Bullet;
class EnemyBullet;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update(const std::vector<Bullet*>& playerBullets);
	void Draw();
	void SpawnEnemies(); // 敵が一度全滅した後に新しい敵を生成するためのメソッド
	static void AddEnemyBullet(EnemyBullet* bullet) { enemyBullets.push_back(bullet); }
	const std::vector<EnemyBullet*>& GetEnemyBullets() const { return enemyBullets; }
private:
	std::vector<Enemy*> enemies; // 固定配列からvectorに変更。vectorだと可変のリストを使用することができる。
	static std::vector<EnemyBullet*> enemyBullets; // 敵の弾丸を管理するベクター配列
};