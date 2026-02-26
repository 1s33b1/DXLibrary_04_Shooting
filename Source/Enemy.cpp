#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "DxLib.h"
#include <vector>
#include "EnemyManager.h"
#include "../GameParameter.h"

///--------------------------------------------------------
// 敵のクラス
// 最初は上からゆっくりと登場させる感じ
// 敵の攻撃はメソッドが実行されたときにEnemyManagerのベクター配列にEnemyBulletを追加していく感じで行う。

// コンストラクタ
Enemy::Enemy(int x, int y)
	:enemyPosx(x),enemyPosy(y),
	enemySpeed(5),
	enemyPosLimit(200),
	enemyRadius(18)
{
	enemyGraph = LoadGraph("Graph\\EnemyCombat.png"); // 敵画像の読み込み
	isHit = false;
}

// デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(enemyGraph); // 画像の解放
}

// 更新処理
void Enemy::Update(const std::vector<Bullet*>& playerBullets)
{
	if (isHit) return;
	enemyPosy += enemySpeed;

	if (enemyPosy >= enemyPosLimit) {
		enemySpeed = 0; // 限界のところに来た時移動を止める
	}

	// 敵の攻撃処理
	{
		shotTimer--;
		if (shotTimer <= 0) {
			Shot();
			shotTimer = 60 + rand() & 60; // タイマーをリセットする
		}
	}

	// 当たり判定処理
	CheckCollision(playerBullets);
}

// 描画処理
void Enemy::Draw()
{
	if (isHit) {
		DrawRotaGraph(enemyPosx, enemyPosy, 1.0, 3.14 / 180 * 90, enemyGraph, FALSE, FALSE);
	}
	else {
		// 前後逆転することになると思う(その辺は後で変更する)
		DrawGraph(enemyPosx, enemyPosy, enemyGraph, FALSE);
	}
}

// 当たり判定メソッド
void Enemy::CheckCollision(const std::vector<Bullet*>& playerBullets)
{
	// 配列の中に弾丸の当たり判定の処理
	for(auto it = playerBullets.begin(); it != playerBullets.end(); ++it) {
		Bullet* bullet = *it;
		if (bullet != nullptr) {
			int distanceX = bullet->GetPosX() - enemyPosx;
			int distanceY = bullet->GetPosY() - enemyPosy;
			int Distance = (distanceX * distanceX) + (distanceY * distanceY); // 弾丸と敵の距離を測るためにXとYの座標を二乗して足す
			int hitDistance = bullet->GetRadius() + enemyRadius; // 三平方の定理の斜辺の距離を求めるために、敵の半径と弾丸の半径を足す

			// 三平方の定理で当たり判定の計算を行う
			if (Distance < (hitDistance * hitDistance)) {
				isHit = true;
				(*it)->isScreen = false; // 弾丸が敵に当たった時に当たった弾丸を非表示にする
			}
		}
	}
}

// 敵の攻撃処理
void Enemy::Shot()
{
	// ここで生成した後にEnemyManagerのベクター配列に追加する
	EnemyBullet* enemyBullet = new EnemyBullet(enemyPosx, enemyPosy); // 敵の弾丸を生成
	EnemyManager::AddEnemyBullet(enemyBullet); // 敵の弾丸をEnemyManagerのベクター配列に追加する
}