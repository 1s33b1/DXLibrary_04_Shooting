#include "Enemy.h"
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
}

// デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(enemyGraph); // 画像の解放
}

// 更新処理
void Enemy::Update()
{
	enemyPosy += enemySpeed;

	if (enemyPosy >= enemyPosLimit) {
		enemySpeed = 0; // 限界のところに来た時移動を止める
	}
}

// 描画処理
void Enemy::Draw()
{
	// 多分後々前後逆転することになると思う(その辺は後で変更する)
	DrawGraph(enemyPosx, enemyPosy, enemyGraph, FALSE);
}