#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();
	// 更新処理
	void Update();
	// 描画処理
	void Draw();
private:
	int graphBullet; // 弾丸の画像
	int bulletPosx, bulletPosy; // 弾丸の座標
	int bulletSpeed; // 弾丸のスピード
	bool isScreen; // true:画面内にいてるとき
};