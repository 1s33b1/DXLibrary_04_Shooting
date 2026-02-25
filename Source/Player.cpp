#include "DxLib.h"
#include "Player.h"
#include "../GameParameter.h"
#include "Bullet.h"

// コンストラクタ
Player::Player()
{
	playerPosx = 270;	playerPosy = 450;
	moveSpeed = 8;
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
void Player::Update()
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
}

// 描画処理
void Player::Draw()
{
	DrawGraph(playerPosx, playerPosy, playerGraph, FALSE); // プレイヤーの描画

	// 弾丸の描画
	for(Bullet* b : bullets) {
		if (b != nullptr) {
			b->Draw();
		}
	}
}