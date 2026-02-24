#include "Enemy.h"
#include "Bullet.h"
#include "DxLib.h"
#include "../GameParameter.h"

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
	enemyRadius = 18; // 敵の画像は32x32の画像を使用しているから
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
	if (isHit) return;
	enemyPosy += enemySpeed;

	if (enemyPosy >= enemyPosLimit) {
		enemySpeed = 0; // 限界のところに来た時移動を止める
	}

	for (int i = 0; i < BulletSettings::bulletLimit; i++) {
		if (pBullet[i] != nullptr) {
			int distanceX = pBullet[i]->GetPosX() - enemyPosx;
			int distanceY = pBullet[i]->GetPosY() - enemyPosy;
			int Distance = (distanceX * distanceX) + (distanceY * distanceY);
			int hitDistance = pBullet[i]->GetRadius() + enemyRadius;

			// 三平方の定理で当たり判定の計算を行う
			if (Distance < (hitDistance * hitDistance)) {
				isHit = true;
			}
		}
	}
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