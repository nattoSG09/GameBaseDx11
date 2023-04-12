#include "Enemy.h"
#include "Player.h"
#include "Engine/Input.h"

//コンストラクタ
Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy")
{
}

//初期化
void Enemy::Initialize()
{
	WayPoint = transform_.position_;
}

//更新
void Enemy::Update()
{

	//Enemyの動作処理
	{
		bool flag_Find = false;

		//Player感知処理
		{
			//デバッグ用：flag_Find
			#if 1
			{
				if (Input::IsKeyDown(DIK_U)) {
					flag_Find = false;
				}

				if (Input::IsKeyDown(DIK_I)) {
					flag_Find = true;
				}
			}
			#endif
		}

		//条件：Playerを発見したか否か
		if (flag_Find) {
			//Enemyの追従処理
			FollowingMove();
		}
		else {
			//Enemyの徘徊処理
			WanderingMove();
		}
	}
}

//描画
void Enemy::Draw()
{
}

//開放
void Enemy::Release()
{
}

// original function


//２つの座標を比較する関数
bool Enemy::isCloser(XMFLOAT3 A_, XMFLOAT3 B_,XMFLOAT3 T_)
{
	bool closest = false;
	float disA = (abs(T_.x) + abs(T_.z)) - (abs(A_.x) + abs(A_.z));
	float disB = (abs(T_.x) + abs(T_.z)) - abs(B_.x) + abs(B_.z);

	if (disA < disB) {
		closest = true;
	}
	return (closest);
}

//４つの座標を比較して、最も目的地に近い場所を返す関数
XMFLOAT3 Enemy::FindShortestDistance(XMFLOAT3 a, XMFLOAT3 b, XMFLOAT3 c, XMFLOAT3 d,XMFLOAT3 Target)
{
	XMFLOAT3 closePos = a;
	if (isCloser(b, closePos,Target)) {
		closePos = b;
	}
	if (isCloser(c, closePos, Target)) {
		closePos = c;
	}
	if (isCloser(d, closePos, Target)) {
		closePos = d;
	}

	return (closePos);
}

//進行する目的地を決定する場所を返す関数
XMFLOAT3 Enemy::DIJKSTRA(XMFLOAT3 NowPos_, XMFLOAT3 TargetPos_)
{
	XMFLOAT3 E,W,N,S;
	//右 
	E = { NowPos_.x + 2.0f,0,NowPos_.z }; 
	//左 
	W = { NowPos_.x - 2.0f,0,NowPos_.z };
	//奥 
	N = { NowPos_.x,0,NowPos_.z + 2.0f }; 
	//手前 
	S = { NowPos_.x,0,NowPos_.z - 2.0f };

	XMFLOAT3 CclosePos = FindShortestDistance(E, W, N, S, TargetPos_);
	return CclosePos;
}

//目的地に到着したらTrueを返す関数
bool Enemy::isArrival(XMFLOAT3 NowPos_, XMFLOAT3 TargetPos_)
{
	bool Arr = false;
	if (NowPos_.x == TargetPos_.x && NowPos_.z == TargetPos_.z) {
		Arr = true;
	}
	return (Arr);
}

//Enemyの追従処理を行う関数
void Enemy::FollowingMove()
{
	//メモ
	{
		//TargetPosはヘッダーで宣言する
		//WayPointはヘッダーを宣言する
	}

	//目的地を取得(playerの位置)
	Player* p = (Player*)FindObject("Player");
	XMFLOAT3 TargetPos = p->GetPosition();

	//経由地にたどりつくまで
	if (!isArrival) {

		//EnemyとWayPointの差を計算する
		XMFLOAT3 deltaPosition = XMFLOAT3(
			WayPoint.x - transform_.position_.x,
			0,
			WayPoint.z - transform_.position_.z
		);

		//Enemyの進行方向を計算する
		XMVECTOR EnemyDir = XMVector3Normalize(XMLoadFloat3(&deltaPosition));

		//Enemyの移動速度
		float Speed = 0.05f;

		//EnemyをWayPointに向かって移動させる
		transform_.position_.x += (XMVectorGetX(EnemyDir) * Speed);
		transform_.position_.y += (XMVectorGetY(EnemyDir) * Speed);
		transform_.position_.z += (XMVectorGetZ(EnemyDir) * Speed);

		//ベクトルの長さを求める
		XMVECTOR vLength = XMVector3Length(EnemyDir);
		float length = XMVectorGetX(vLength);

		if (length != 0)
		{
			XMVECTOR vFront = { 0,0,1,0 };//奥向きのベクトル

			XMVECTOR vDot = XMVector3Dot(vFront, EnemyDir);
			//↑の二つのベクトルの内積を求める
			float dot = XMVectorGetX(vDot);
			float angle = acos(dot);//アークコサインで計算すると"狭い角度"のほうの角度を求める

			XMVECTOR vCross = XMVector3Cross(vFront, EnemyDir);
			//↑二つのベクトルの外積を求める
			//外積のYが０より小さかったら
			if (XMVectorGetY(vCross) < 0) {
				//angleに -1 をかける
				angle *= -1;
			}

			transform_.rotate_.y = XMConvertToDegrees(angle);
		}
	}
	//たどり着いたら
	else {
		//TargetPosまでのWayPointを取得
		XMFLOAT3 WayPoint = DIJKSTRA(transform_.position_, TargetPos);
	}
}

//Enemyの徘徊処理を行う関数
void Enemy::WanderingMove()
{
	//目的地を取得(ランダムな位置)
	if (isArrival) {
		XMFLOAT3 TargetPos;
	}
}
