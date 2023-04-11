#include "Enemy.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy")
{
}

//初期化
void Enemy::Initialize()
{
}

//更新
void Enemy::Update()
{
}

//描画
void Enemy::Draw()
{
}

//開放
void Enemy::Release()
{
}

#include <cmath>
using std::abs;

//最小値を求める関数
XMFLOAT3 min_var(XMFLOAT3 a, XMFLOAT3 b, XMFLOAT3 c, XMFLOAT3 d)
{ //座標(２つの値)を比べる方法？？ 
	XMFLOAT3 min_val = a; 
	if (abs(b.x) < abs(min_val.x)) {
		min_val = b; 
	} 
	if (c < min_val) { 
		min_val = c; 
	} 
	if (d < min_val) { 
		min_val = d; 
	} 
	return min_val; 
}