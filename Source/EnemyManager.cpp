#include "EnemyManager.h"
#include "Bullet.h"

// コンストラクタ：生成処理
EnemyManager::EnemyManager()
{
	SpawnEnemies();
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
	// 敵全員分の更新処理。ゲッターメソッドで弾丸が当たったかどうかのチェックを行い、当たっていたら敵の削除を行う
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

	// 敵全員分の当たり判定　
	for (Enemy* e : enemies) {
		e->CheckCollision(playerBullets);
	}

	// ベクター配列が空になった時新しい敵を生成する
	if (enemies.empty()) {
		SpawnEnemies();
	}
}

// 描画処理
void EnemyManager::Draw()
{
	for (Enemy* e : enemies) {
		e->Draw();
	}
}

// 敵が一度全滅した後に新しい敵を生成するためのメソッド
void EnemyManager::SpawnEnemies()
{
	for(int i = 0; i < EnemySettings::enemyLimit; i++) {
		int spawnX = EnemySettings::firstEnemyPosx + (EnemySettings::intervalSpace * i);
		enemies.push_back(new Enemy(spawnX, EnemySettings::firstEnemyPosy));
	}
}

