#include "EnemyManager.h"
#include "Bullet.h"

// コンストラクタ：生成処理
EnemyManager::EnemyManager()
{
	for (int i = 0; i < EnemySettings::enemyLimit; i++) {
		int spawnX = EnemySettings::firstEnemyPosx + (EnemySettings::intervalSpace * i);
		// push_backで敵を配列に追加していく
		enemies.push_back(new Enemy(spawnX, EnemySettings::firstEnemyPosy));
	}
}

// デストラクタ：削除処理
EnemyManager::~EnemyManager()
{
	for (Enemy* e : enemies) {
		delete e;
	}
	enemies.clear(); // 中身を空にする
}

// 更新処理
void EnemyManager::Update(const std::vector<Bullet*>& playerBullets)
{
	for (auto it = enemies.begin(); it != enemies.end();) {
		(*it)->Update(playerBullets);

		if ((*it)->GetIsHit()) {
			delete	(*it); // メモリを解放
			it = enemies.erase(it);
		}
		else {
			++it;
		}
	}
	for (Enemy* e : enemies) {
		e->CheckCollision(playerBullets);
	}
}

// 描画処理
void EnemyManager::Draw()
{
	for (Enemy* e : enemies) {
		e->Draw();
	}
}
