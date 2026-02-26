#include "Bullet.h"
#include "../GameParameter.h"
#include "DxLib.h"

// コンストラクタ
// 引数：弾丸を描画し始めるときの初期位置をプレイヤーの位置から取得
Bullet::Bullet(int x, int y)
	:bulletPosx(x),bulletPosy(y),
	bulletRadius(4),
	bulletSpeed(10),
	isScreen(true)
{
	color = GetColor(0, 255, 0); // 緑
}

// デストラクタ
Bullet::~Bullet()
{
}

// 更新処理
void Bullet::Update()
{
	bulletPosy -= bulletSpeed; // 上方向へ進む

	if (bulletPosy < -50) {
		isScreen = false; // 画面外に出たときフラグを降ろす
	}

	// 画面内に存在しているときはフラグを立てておく
	//if (bulletPosx <= ScreenSettings::screenWidth &&
	//	bulletPosx >= 0 &&
	//	bulletPosy <= ScreenSettings::screenHeight &&
	//	bulletPosy >= 0)
	//{
	//	isScreen = true;
	//}
}

// 描画処理
void Bullet::Draw()
{
	DrawCircle(bulletPosx, bulletPosy,bulletRadius, color, TRUE);
}