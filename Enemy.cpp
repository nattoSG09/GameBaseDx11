#include "Enemy.h"
#include "Player.h"
#include "Engine/Input.h"

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

	//Enemy�̓��쏈��
	{
		bool flag_Find = false;

		//Player���m����
		{
			//�f�o�b�O�p�Fflag_Find
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

		//�����FPlayer�𔭌��������ۂ�
		if (flag_Find) {
			//Enemy�̒Ǐ]����
			FollowingMove();
		}
		else {
			//Enemy�̜p�j����
			WanderingMove();
		}
	}
}

//�`��
void Enemy::Draw()
{
}

//�J��
void Enemy::Release()
{
}

// original function


//�Q�̍��W���r����֐�
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

//�S�̍��W���r���āA�ł��ړI�n�ɋ߂��ꏊ��Ԃ��֐�
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

//�i�s����ړI�n�����肷��ꏊ��Ԃ��֐�
XMFLOAT3 Enemy::DIJKSTRA(XMFLOAT3 NowPos_, XMFLOAT3 TargetPos_)
{
	XMFLOAT3 E,W,N,S;
	//�E 
	E = { NowPos_.x + 2.0f,0,NowPos_.z }; 
	//�� 
	W = { NowPos_.x - 2.0f,0,NowPos_.z };
	//�� 
	N = { NowPos_.x,0,NowPos_.z + 2.0f }; 
	//��O 
	S = { NowPos_.x,0,NowPos_.z - 2.0f };

	XMFLOAT3 CclosePos = FindShortestDistance(E, W, N, S, TargetPos_);
	return CclosePos;
}

//�ړI�n�ɓ���������True��Ԃ��֐�
bool Enemy::isArrival(XMFLOAT3 NowPos_, XMFLOAT3 TargetPos_)
{
	bool Arr = false;
	if (NowPos_.x == TargetPos_.x && NowPos_.z == TargetPos_.z) {
		Arr = true;
	}
	return (Arr);
}

//Enemy�̒Ǐ]�������s���֐�
void Enemy::FollowingMove()
{
	//�ړI�n���擾(player�̈ʒu)
	Player* p = (Player*)FindObject("Player");
	XMFLOAT3 TargetPos = p->GetPosition();

	//�ړI�n�܂ł̌o�R�n���擾
	XMFLOAT3 WayPoint = DIJKSTRA(transform_.position_,TargetPos);

	//�o�R�n�ɂ��ǂ���܂�
	if (!isArrival) {

		//���ݒn�ƌo�R�n�̍����v�Z����
		XMFLOAT3 deltaPosition = XMFLOAT3(
			WayPoint.x - transform_.position_.x,
			0,
			WayPoint.z - transform_.position_.z
		);

		//Enemy�̐i�s�������v�Z����
		XMVECTOR EnemyDir = XMVector3Normalize(XMLoadFloat3(&deltaPosition));


	}
	


}

//Enemy�̜p�j�������s���֐�
void Enemy::WanderingMove()
{
	//�ړI�n���擾(�����_���Ȉʒu)
	if (isArrival) {
		XMFLOAT3 TargetPos;
	}
}
