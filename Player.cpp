#include "Player.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//初期化
void Player::Initialize()
{

	//モデルのロード
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	//サウンドのロード
	hSound_ = Audio::Load("CoinSound.wav");
	assert(hSound_ >= 0);

	//コライダーの生成
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 0), XMFLOAT3(1.2, 1.2, 1.2));
	AddCollider(collision);
}

//更新
void Player::Update()
{

	//移動処理
	{
		//移動速度
		float Speed = 0.2;

		//上下左右
		if (Input::IsKey(DIK_A)) { transform_.position_.x -= Speed; }
		if (Input::IsKey(DIK_D)) { transform_.position_.x += Speed; }
		if (Input::IsKey(DIK_S)) { transform_.position_.z -= Speed; }
		if (Input::IsKey(DIK_W)) { transform_.position_.z += Speed; }
	}

	Audio::Play(hSound_);
}

//描画
void Player::Draw()
{
	//モデルの描画
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

//接触判定
void Player::OnCollision(GameObject* pTarget)
{
	/*if (pTarget->GetObjectName() == "Coin") {
		Audio::Play(hSound_);
	}*/
}



