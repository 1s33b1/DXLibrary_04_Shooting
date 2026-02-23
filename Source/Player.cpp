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

	// 実行してすぐは配列の中身をすべて空にする
	for (int i = 0; i < bulletLimit; i++) {
		pBullet[i] = nullptr;
	}
}

// デストラクタ
Player::~Player()
{
	DeleteGraph(playerGraph);

	for (int i = 0; i < bulletLimit; i++) {
		delete pBullet[i];
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
		// ポインタ配列内の空いているところを探索する
		for (int i = 0; i < bulletLimit; i++) {
			if (pBullet[i] == nullptr) {
				int graphSizex, graphSizey;
				GetGraphSize(playerGraph, &graphSizex, &graphSizey); // プレイヤー画像のサイズを取得
				pBullet[i] = new Bullet(playerPosx + graphSizex / 2, playerPosy - 20 + graphSizey / 2);
				break; // 一発作ったらループを強制的に終わらせる
			}
		}
	}

	// 配列の中に弾丸の更新処理と、画面外に出た時の処理
	for (int i = 0; i < bulletLimit; i++) {
		if (pBullet[i] != nullptr) {
			pBullet[i]->Update(); // 更新処理をさせる

			// 配列の中に弾丸の更新処理と、画面外に出た時の処理
			if (pBullet[i]->isScreen == false) {
				delete pBullet[i];
				pBullet[i] = nullptr; // インスタンスを削除したときにポインタ配列の中を削除する
			}
		}
	}
}

// 描画処理
void Player::Draw()
{
	DrawGraph(playerPosx, playerPosy, playerGraph, FALSE); // プレイヤーの描画

	// 弾丸の描画
	for (int i = 0; i < bulletLimit; i++) {
		if (pBullet[i] != nullptr) {
			pBullet[i]->Draw();
		}
	}
}