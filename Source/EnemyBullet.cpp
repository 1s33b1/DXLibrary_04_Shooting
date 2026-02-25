#include "EnemyBullet.h"
#include "DxLib.h"
#include "../GameParameter.h"

/// <summary>
/// 敵の弾丸を管理するクラス
/// 敵の弾丸の発射とかを行う
/// </summary>

// コンストラクタ
EnemyBullet::EnemyBullet(int x, int y)
	: bulletPosx(x),bulletPosy(y),
	bulletRadius(4),
	bulletSpeed(10),
	isScreen(true)
{
	color = GetColor(255, 0, 0); // 赤
}

// デストラクタ
EnemyBullet::~EnemyBullet()
{
}

// 更新処理
void EnemyBullet::Update()
{
	bulletPosy += bulletSpeed; // 下方向へ進む

	if (bulletPosy > 700) {
		isScreen = false; // 画面外(下)に出たときフラグを降ろす
	}

	// 画面内に存在しているときはフラグを立てておく
	if (bulletPosx <= ScreenSettings::screenWidth &&
		bulletPosx >= 0 &&
		bulletPosy <= ScreenSettings::screenHeight &&
		bulletPosy >= 0)
	{
		isScreen = true;
	}

}

// 描画処理
void EnemyBullet::Draw()
{
	DrawCircle(bulletPosx, bulletPosy, bulletRadius, color, TRUE);
}
