#include "DxLib.h"
#include "Player.h"
#include "../GameParameter.h"
#include "Bullet.h"
#include <vector>

// コンストラクタ
Player::Player()
{
	playerPosx = 270;	playerPosy = 450;
	moveSpeed = 8;
	playerGraph = LoadGraph("Graph\\Combat2.png"); // メモリにプレイヤーの画像を読み込ませる
	pBullet[bulletLimit];
}

// デストラクタ
Player::~Player()
{
	DeleteGraph(playerGraph);
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
		// ポインタ配列内の空いているところを探索する
		for (int i = 0; i < bulletLimit; i++) {
			if (pBullet[i] == nullptr) {
				pBullet[i] = new Bullet();
			}
		}
	}
}

// 描画処理
void Player::Draw()
{
	DrawGraph(playerPosx, playerPosy, playerGraph, FALSE); // プレイヤーの描画
}