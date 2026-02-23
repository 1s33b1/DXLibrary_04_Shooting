#include "Enemy.h"
#include "Bullet.h"
#include "DxLib.h"

///--------------------------------------------------------
// 敵のクラス
// 最初は上からゆっくりと登場させる感じ

// コンストラクタ
Enemy::Enemy()
{
	enemyGraph = LoadGraph("Graph\\EnemyCombat.png"); // 敵画像の読み込み
	enemyPosx = 320; enemyPosy = -50;
	enemySpeed = 5;
	enemyPosLimit = 200;
	isHit = false;
}

// デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(enemyGraph); // 画像の解放
}

// 更新処理
void Enemy::Update(Bullet* pBullet[])
{
	enemyPosy += enemySpeed;

	if (enemyPosy >= enemyPosLimit) {
		enemySpeed = 0; // 限界のところに来た時移動を止める
	}

	for (int i = 0; i < 10; i++) {
		if (pBullet[i] != nullptr) {
			int distanceX = pBullet[i]->GetPosX() - enemyPosx;
			int distanceY = pBullet[i]->GetPosY() - enemyPosy;
			int distance = (distanceX * distanceX) + (distanceY * distanceY);

			// 三平方の定理で当たり判定の計算を行う
			if (distance < (pBullet[i]->GetRadius() * pBullet[i]->GetRadius())) {
				isHit = true;
			}
		}
	}

	if (isHit) {
		DrawRotaGraph(enemyPosx, enemyPosy, 1.0, 3.14 / 180 * 90, enemyGraph, FALSE, FALSE);
	}
}

// 描画処理
void Enemy::Draw()
{
	// 前後逆転することになると思う(その辺は後で変更する)
	DrawGraph(enemyPosx, enemyPosy, enemyGraph, FALSE);
}