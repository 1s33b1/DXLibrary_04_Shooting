#pragma once
class EnemyBullet
{
public:
	EnemyBullet(int x, int y);
	~EnemyBullet();
	// 更新処理
	void Update();
	// 描画処理
	void Draw();
	bool isScreen; // true:画面内にいてるとき

	int GetPosX() const { return bulletPosx; }
	int GetPosY() const { return bulletPosy; }
	int GetRadius() const { return bulletRadius; }
private:
	int color;
	int bulletPosx, bulletPosy; // 弾丸の座標
	int bulletRadius; // 弾丸の半径
	int bulletSpeed; // 弾丸のスピード
};