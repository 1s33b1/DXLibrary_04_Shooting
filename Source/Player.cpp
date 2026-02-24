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

	// 実行してすぐは配列の中身をすべて空にする
	for (int i = 0; i < BulletSettings::bulletLimit; i++) {
		bullets.push_back(nullptr);
	}
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
		// ポインタ配列内の空いているところを探索する
		for(auto b : bullets) {
			if (b == nullptr) {
				int graphSizex, graphSizey;
				GetGraphSize(playerGraph, &graphSizex, &graphSizey); // プレイヤー画像のサイズを取得
				bullets.push_back(new Bullet(playerPosx + graphSizex / 2, playerPosy - 20 + graphSizey / 2));
				break; // 一発作ったらループを強制的に終わらせる
			}
		}
	}

	// 配列の中に弾丸の更新処理と、画面外に出た時の処理
	for (auto b = bullets.begin(); b != bullets.end();) {
		(*b)->Update();
		if (!(*b)->isScreen) {
			delete (*b); // メモリを解放
			b = bullets.erase(b); // 配列から削除
		}
		else {
			++b; // 次の弾丸へ
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