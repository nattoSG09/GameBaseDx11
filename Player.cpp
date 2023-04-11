#include "Player.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//������
void Player::Initialize()
{

	//���f���̃��[�h
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	//�T�E���h�̃��[�h
	hSound_ = Audio::Load("CoinSound.wav");
	assert(hSound_ >= 0);

	//�R���C�_�[�̐���
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 0), XMFLOAT3(1.2, 1.2, 1.2));
	AddCollider(collision);
}

//�X�V
void Player::Update()
{

	//�ړ�����
	{
		//�ړ����x
		float Speed = 0.2;

		//�㉺���E
		if (Input::IsKey(DIK_A)) { transform_.position_.x -= Speed; }
		if (Input::IsKey(DIK_D)) { transform_.position_.x += Speed; }
		if (Input::IsKey(DIK_S)) { transform_.position_.z -= Speed; }
		if (Input::IsKey(DIK_W)) { transform_.position_.z += Speed; }
	}

	Audio::Play(hSound_);
}

//�`��
void Player::Draw()
{
	//���f���̕`��
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}

//�ڐG����
void Player::OnCollision(GameObject* pTarget)
{
	/*if (pTarget->GetObjectName() == "Coin") {
		Audio::Play(hSound_);
	}*/
}



