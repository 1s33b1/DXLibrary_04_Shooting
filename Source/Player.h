#pragma once
#include <vector>
#include "Bullet.h"
#include "EnemyBullet.h"
class Player
{
public:
	Player();
	~Player();
	void Update(const std::vector<EnemyBullet*>& enemyBullets);
	void Draw();
	void CheckCollision(const std::vector<EnemyBullet*>& enemyBullets);
	int GetPosX() const { return playerPosx; }
	int GetPosY() const { return playerPosy; }
	int GetBulletLimit() const { return bulletLimit; }
	const std::vector<Bullet*>& GetBullets() const { return bullets; }
private:
	int playerPosx, playerPosy; // X,Y座標
	int moveSpeed; // プレイヤーの移動速度
	int playerGraph; // プレイヤーの画像
	int graphWidth, graphHeight; // プレイヤーの画像の幅と高さ
	bool isHit; // true:敵の弾に当たった時
	static const int bulletLimit = 10; // 画面上に出せる弾丸の数
	std::vector<Bullet*> bullets; // 弾丸のベクター配列
};
