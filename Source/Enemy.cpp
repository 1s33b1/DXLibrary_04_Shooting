#include "Enemy.h"
#include "Bullet.h"
#include "DxLib.h"
#include "../GameParameter.h"

///--------------------------------------------------------
// 敵のクラス
// 最初は上からゆっくりと登場させる感じ

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
void Enemy::Update(Bullet* pBullet[])
{
	if (isHit) return;
	enemyPosy += enemySpeed;

	if (enemyPosy >= enemyPosLimit) {
		enemySpeed = 0; // 限界のところに来た時移動を止める
	}

	CheckCollision(pBullet);
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
void Enemy::CheckCollision(Bullet* pBullet[]) 
{
	for (int i = 0; i < BulletSettings::bulletLimit; i++) {
		if (pBullet[i] != nullptr) {
			int distanceX = pBullet[i]->GetPosX() - enemyPosx;
			int distanceY = pBullet[i]->GetPosY() - enemyPosy;
			int Distance = (distanceX * distanceX) + (distanceY * distanceY);
			int hitDistance = pBullet[i]->GetRadius() + enemyRadius;

			// 三平方の定理で当たり判定の計算を行う
			if (Distance < (hitDistance * hitDistance)) {
				isHit = true;
				pBullet[i]->isScreen = false; // 弾丸が敵に当たった時に当たった弾丸を非表示にする
			}
		}
	}

}