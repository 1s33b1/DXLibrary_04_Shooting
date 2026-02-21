#include "Bullet.h"
#include "../GameParameter.h"
#include "DxLib.h"

// コンストラクタ
Bullet::Bullet()
{
	graphBullet = LoadGraph("Bullet.png");
	bulletPosx = 320; bulletPosy = 240;
	bulletSpeed = 10;
	isScreen = true;
	Draw(); // 描画をする
}

// デストラクタ
Bullet::~Bullet()
{
	DeleteGraph(graphBullet);
}

// 更新処理
void Bullet::Update()
{
	bulletPosy -= bulletSpeed;

	if (bulletPosy < -50) {
		// ここで弾丸を破壊したい
		//delete this;
	}

	// 画面内に存在しているときはフラグを立てておく
	if (bulletPosx <= ScreenSettings::screenWidth &&
		bulletPosx >= 0 &&
		bulletPosy <= ScreenSettings::screenHeight &&
		bulletPosy >= 0)
	{
		isScreen = true;
	}

	if (isScreen) {

	}
}

// 描画処理
void Bullet::Draw()
{
	DrawGraph(bulletPosx, bulletPosy, graphBullet, FALSE);
}