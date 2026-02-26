#include "DxLib.h"
#include "Player.h"
#include "../GameParameter.h"
#include "Bullet.h"

// コンストラクタ
Player::Player()
{
	playerPosx = 270;	playerPosy = 450;
	moveSpeed = 8;
	isHit = false;
	GetGraphSize(playerGraph, &graphWidth, &graphHeight);
	playerGraph = LoadGraph("Graph\\Combat2.png"); // メモリにプレイヤーの画像を読み込ませる
}

// デストラクタ
Player::~Player()
{
	DeleteGraph(playerGraph);

	for(Bullet* b : bullets) {
		delete b;
	}
}

// 更新処理
void Player::Update(const std::vector<EnemyBullet*>& enemyBullets)
{
	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) {
		playerPosx -= moveSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) {
		playerPosx += moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) {
		playerPosy -= moveSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) {
		playerPosy += moveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		// もし弾丸の数が上限に達していなければ弾丸を生成する
		if (bullets.size() < BulletSettings::bulletLimit) {
			int gx, gy;
			GetGraphSize(playerGraph, &gx, &gy);

			// push_backで弾丸を生成して配列に追加する
			bullets.push_back(new Bullet(playerPosx + gx / 2, playerPosy));
		}
	}

	// 配列の中に弾丸の更新処理と、画面外に出た時の処理
	for (auto it = bullets.begin(); it != bullets.end();) {
		(*it)->Update();

		if((*it)->isScreen == false) {
			delete *it; // 画面外に出た弾丸を削除する
			it = bullets.erase(it); // 配列からも削除する
		}
		else {
			++it; // 次の弾丸の処理に移る
		}
	}

	CheckCollision(enemyBullets); // 敵の弾丸との当たり判定
}

// 描画処理
void Player::Draw()
{
	if (isHit) {
		DrawRotaGraph(playerPosx, playerPosy, 1.0, 3.14 / 180 * 90, playerGraph, FALSE, FALSE);
	}
	else {
		DrawGraph(playerPosx, playerPosy, playerGraph, FALSE); // プレイヤーの描画
	}

	// 弾丸の描画
	for(Bullet* b : bullets) {
		if (b != nullptr) {
			b->Draw();
		}
	}
}

void Player::CheckCollision(const std::vector<EnemyBullet*>& enemyBullets)
{
	// 配列の中に弾丸の当たり判定の処理
	for (auto it = enemyBullets.begin(); it != enemyBullets.end(); ++it) {
		EnemyBullet* bullet = *it;
		if (bullet != nullptr) {
			int distanceX = bullet->GetPosX() - playerPosx;
			int distanceY = bullet->GetPosY() - playerPosy;
			int Distance = (distanceX * distanceX) + (distanceY * distanceY); // 弾丸と敵の距離を測るためにXとYの座標を二乗して足す
			int hitDistance = bullet->GetRadius() + (graphWidth / 2); // 三平方の定理の斜辺の距離を求めるために、敵の半径と弾丸の半径を足す

			// 三平方の定理で当たり判定の計算を行う
			if (Distance < (hitDistance * hitDistance)) {
				isHit = true;
				(*it)->isScreen = false; // 弾丸が敵に当たった時に当たった弾丸を非表示にする
			}
		}
	}

}
