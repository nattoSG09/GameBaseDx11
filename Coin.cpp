#include "Coin.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Coin::Coin(GameObject* parent)
{
	
}

//������
void Coin::Initialize()
{
	//���f���̃��[�h
	hModel_ = Model::Load("Coin.fbx");
	assert(hModel_ >= 0);

	//���f���̏�����
	{
		transform_.position_ = { 0,1,5 };
		transform_.scale_ = { 0.6,0.6,0.6 };
		transform_.rotate_.x = 90;
	}
	
	//�R���C�_�[�̐���
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
	AddCollider(collision);

}

//�X�V
void Coin::Update()
{
	transform_.rotate_.y--;
}

//�`��
void Coin::Draw()
{
	//���f���̕`��
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Coin::Release()
{
}
