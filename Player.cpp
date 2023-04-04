#include "Player.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//初期化
void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	/*BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(2, 2, 2));
	AddCollider(collision);*/
}

//更新
void Player::Update()
{
}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

