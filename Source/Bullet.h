#pragma once
class Bullet
{
public:
	Bullet(int x, int y);
	~Bullet();
	// XVˆ—
	void Update();
	// •`‰æˆ—
	void Draw();
	bool isScreen; // true:‰æ–Ê“à‚É‚¢‚Ä‚é‚Æ‚«

	int GetPosX() const { return bulletPosx; }
	int GetPosY() const { return bulletPosy; }
	int GetRadius() const { return bulletRadius; }
private:
	//int graphBullet; // ’eŠÛ‚Ì‰æ‘œ
	int color;
	int bulletPosx, bulletPosy; // ’eŠÛ‚ÌÀ•W
	int bulletRadius; // ’eŠÛ‚Ì”¼Œa
	int bulletSpeed; // ’eŠÛ‚ÌƒXƒs[ƒh
};

