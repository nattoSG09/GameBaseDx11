#include "Coin.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Coin::Coin(GameObject* parent)
{
	
}

//初期化
void Coin::Initialize()
{
	//モデルのロード
	hModel_ = Model::Load("Coin.fbx");
	assert(hModel_ >= 0);

	//モデルの初期化
	{
		transform_.position_ = { 0,1,5 };
		transform_.scale_ = { 0.6,0.6,0.6 };
		transform_.rotate_.x = 90;
	}
	
	//コライダーの生成
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
	AddCollider(collision);

}

//更新
void Coin::Update()
{
	transform_.rotate_.y--;
}

//描画
void Coin::Draw()
{
	//モデルの描画
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Coin::Release()
{
}
