#pragma once
#include <vector>
#include "Bullet.h"
class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	int GetPosX() const { return playerPosx; }
	int GetPosY() const { return playerPosy; }
	int GetBulletLimit() const { return bulletLimit; }
	Bullet** GetBulletArray() { return pBullet; }
private:
	int playerPosx, playerPosy; // X,Y座標
	int moveSpeed; // プレイヤーの移動速度
	int playerGraph; // プレイヤーの画像
	static const int bulletLimit = 10; // 画面上に出せる弾丸の数
	Bullet* pBullet[bulletLimit]; // 弾丸のポインタ
	std::vector<Bullet*> bullets; // 弾丸のベクター配列
};
