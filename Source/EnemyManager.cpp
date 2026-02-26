#include "EnemyManager.h"
#include "EnemyBullet.h"
#include "Explosion.h"
#include "Bullet.h"

std::vector<EnemyBullet*> EnemyManager::enemyBullets; // 敵の弾丸を管理するベクター配列
// コンストラクタ：生成処理
EnemyManager::EnemyManager()
{
	SpawnEnemies();
}

// デストラクタ：削除処理
EnemyManager::~EnemyManager()
{
	// 敵の削除処理
	for (Enemy* e : enemies) {
		delete e;
	}
	enemies.clear(); // 中身を空にする

	// 敵の弾丸の削除処理
	for (EnemyBullet* eb : enemyBullets) {
		delete eb;
	}
	enemyBullets.clear(); // 中身を空にする
}

// 更新処理
void EnemyManager::Update(const std::vector<Bullet*>& playerBullets)
{
	// 敵全員分の更新処理。ゲッターメソッドで弾丸が当たったかどうかのチェックを行い、当たっていたら敵の削除を行う
	for (auto it = enemies.begin(); it != enemies.end();) {
		(*it)->Update(playerBullets);

		if ((*it)->GetIsHit()) {
			Explosion* explosion = new Explosion((*it)->GetPosX(), (*it)->GetPosY()); // 敵が当たったときに爆発を生成する
			explosion->Update(); // 爆発の更新処理
			explosion->Draw(); // 爆発の描画処理
			if (explosion->isFinished()) {
				delete	(*it); // メモリを解放
				it = enemies.erase(it);
				delete explosion; // 爆発のメモリを解放
			}
		}
		else {
			++it;
		}
	}

	// 敵の弾丸すべての更新処理と画面外に出たときにフラグを降ろす処理
	for (auto it = enemyBullets.begin(); it != enemyBullets.end();) {
		(*it)->Update();

		if ((*it)->isScreen == false) {
			delete (*it); // フラグが降りたときにメモリを解放する
			it = enemyBullets.erase(it); // 配列からも削除する
		}
		else {
			++it; // 次の要素に進む
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

	for(EnemyBullet* eb:enemyBullets) {
		eb->Draw();
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

