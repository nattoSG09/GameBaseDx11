#include "Player.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	/*BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(2, 2, 2));
	AddCollider(collision);*/
}

//�X�V
void Player::Update()
{
}

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}

