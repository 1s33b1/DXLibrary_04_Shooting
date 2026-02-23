#pragma once

class Bullet;

class Enemy
{
public:
	Enemy();
	~Enemy();
	void Update(Bullet* pBullet[]);
	void Draw();
private:
	int enemyPosx, enemyPosy; // 位置座標
	int enemyPosLimit; // 敵の停止位置
	int enemyGraph; // 敵の画像
	int enemySpeed; // 移動速度
	bool isHit; // true:プレイヤーの弾に当たった
};
