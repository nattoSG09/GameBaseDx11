#pragma once
#include "Engine/GameObject.h"
#include <cmath>
using std::abs;

class Enemy : public GameObject
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Enemy(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	// original function �[�|�|�|�|�|�|�|�|�|

	//�Q�̍��W���r����֐�
	bool isCloser(XMFLOAT3 A_, XMFLOAT3 B_, XMFLOAT3 T_);

	//�S�̍��W���r���āA�ł��ړI�n�ɋ߂��ꏊ��Ԃ��֐�
	XMFLOAT3 FindShortestDistance(XMFLOAT3 n, XMFLOAT3 s, XMFLOAT3 e, XMFLOAT3 w, XMFLOAT3 Target);

	//�i�s����ړI�n�����肷��ꏊ��Ԃ��֐�
	XMFLOAT3 DIJKSTRA(XMFLOAT3 NowPos, XMFLOAT3 TargetPos);

	//�ړI�n�ɓ���������True��Ԃ��֐�
	bool isArrival(XMFLOAT3 NowPos_, XMFLOAT3 TargetPos_);

	//Enemy�̒Ǐ]�������s���֐�
	void FollowingMove();

	//Enemy�̜p�j�������s���֐�
	void WanderingMove();
};
