#pragma once
#include "Ball.h"
class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	int playerPosx, playerPosy;
private:
	int moveSpeed;
	int color;
	int playerGraph;
};
