#include "Enemy.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy")
{
}

//������
void Enemy::Initialize()
{
}

//�X�V
void Enemy::Update()
{
}

//�`��
void Enemy::Draw()
{
}

//�J��
void Enemy::Release()
{
}

#include <cmath>
using std::abs;

//�ŏ��l�����߂�֐�
XMFLOAT3 min_var(XMFLOAT3 a, XMFLOAT3 b, XMFLOAT3 c, XMFLOAT3 d)
{ //���W(�Q�̒l)���ׂ���@�H�H 
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