#include "Bullet.h"
#include "DxLib.h"

// コンストラクタ
Bullet::Bullet()
{
	bulletGraph = LoadGraph("Bullet.png");
	bulletPosx = 320; bulletPosy = 240;
	bulletSpeed = 10;
}

// デストラクタ
Bullet::~Bullet()
{
	DeleteGraph(bulletGraph);
}

// 更新処理
void Bullet::Update()
{
	bulletPosy -= bulletSpeed;
}

// 描画処理
void Bullet::Draw()
{
	DrawGraph(bulletPosx, bulletPosy, bulletGraph, FALSE);
}