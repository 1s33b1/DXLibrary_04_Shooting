#include "Explosion.h"
#include "DxLib.h"
#include "../GameParameter.h"

int Explosion::graph[ExplosionSettings::divisionNum]; // 爆発の画像を分割して管理するための配列

Explosion::Explosion(int x, int y)
	:explosionPosx(x), explosionPosy(y),
	animationFrame(0),
	isfinished(false),
	timer(0)
{
	LoadDivGraph("Graph\\Explosion.png", 
		          ExplosionSettings::divisionNum,
				  8, 2, 768, 192, graph);
}
Explosion::~Explosion()
{
	for(int i = 0; i < ExplosionSettings::divisionNum; i++) {
		DeleteGraph(graph[i]);
	}
}
void Explosion::Update()
{
	timer++;
	if (timer % 5 == 0) { // 5フレームごとにアニメーションのフレームを進める
		animationFrame++;
		if (animationFrame >= ExplosionSettings::divisionNum) {
			isfinished = true; // アニメーションが終了したときフラグを立てる
		}
	}
}
void Explosion::Draw()
{
	DrawGraph(explosionPosx, explosionPosy, graph[animationFrame], TRUE);
}
