#pragma once
#include "Bullet.h"
class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	int playerPosx, playerPosy; // X,Y座標
private:
	int moveSpeed; // プレイヤーの移動速度
	int playerGraph; // プレイヤーの画像
	static const int bulletLimit = 10; // 画面上に出せる弾丸の数
	Bullet pBullet[]; // 弾丸のポインタ
};
