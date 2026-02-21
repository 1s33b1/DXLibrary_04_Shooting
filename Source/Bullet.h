#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();
private:
	int bulletGraph;
	int bulletPosx, bulletPosy;
	int bulletSpeed;
};