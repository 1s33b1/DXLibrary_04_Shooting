#pragma once
#include "../GameParameter.h"

class Explosion
{
public:
	Explosion(int x, int y);
	~Explosion();
	void Update();
	void Draw();
	bool isFinished() { return isfinished; }
	static int graph[ExplosionSettings::divisionNum]; // 爆発の画像を分割して管理するための配列
private:
	int timer; // 爆発のアニメーションを行うタイマー
	int animationFrame; // 爆発のアニメーションのフレーム数。主に配列のインデックスに使用する
	int explosionPosx, explosionPosy; // 爆発の位置座標
	bool isfinished; // true:爆発のアニメーションが終了したとき
};
