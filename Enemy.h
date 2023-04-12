#pragma once
#include "Engine/GameObject.h"
#include <cmath>
using std::abs;

class Enemy : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	// original function ー－－－－－－－－－

	//２つの座標を比較する関数
	bool isCloser(XMFLOAT3 A_, XMFLOAT3 B_, XMFLOAT3 T_);

	//４つの座標を比較して、最も目的地に近い場所を返す関数
	XMFLOAT3 FindShortestDistance(XMFLOAT3 n, XMFLOAT3 s, XMFLOAT3 e, XMFLOAT3 w, XMFLOAT3 Target);

	//進行する目的地を決定する場所を返す関数
	XMFLOAT3 DIJKSTRA(XMFLOAT3 NowPos, XMFLOAT3 TargetPos);

	//目的地に到着したらTrueを返す関数
	bool isArrival(XMFLOAT3 NowPos_, XMFLOAT3 TargetPos_);

	//Enemyの追従処理を行う関数
	void FollowingMove();

	//Enemyの徘徊処理を行う関数
	void WanderingMove();
};
