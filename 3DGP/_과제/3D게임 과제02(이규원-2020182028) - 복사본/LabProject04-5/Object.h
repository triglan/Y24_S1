//------------------------------------------------------- ----------------------
// File: Object.h
//-----------------------------------------------------------------------------

#pragma once

#include "Mesh.h"
#include "Camera.h"

class CShader;

class CGameObject
{
public:
	CGameObject(float x, float y, float z);
	CGameObject();
	virtual ~CGameObject();

public:
	XMFLOAT4X4						m_xmf4x4World;
	CMesh							*m_pMesh = NULL;
	CShader							*m_pShader = NULL;
	XMFLOAT3						m_xmf3Color = XMFLOAT3(1.0f, 1.0f, 1.0f);

	//+���� �ִϸ��̼�
	void AnimateShield(XMFLOAT3 position, float fTimeElapsed);
	//+ �̻��� �̵�, �̻��� ����,  �̻��� �����̴� ���� ����, �̻��� �ִϸ��̼�, ���̻���
	void Move(XMFLOAT3& vDirection, float fSpeed);
	void LookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	void SetMovingDirection(XMFLOAT3& xmf3MovingDirection);
	void AnimateMissile(float fTimeElapsed);
	void AnimateEnemyMissile(float fTimeElapsed);

	//+ �����̴� ���� �� ��ġ
	float x_pos, y_pos, z_pos;
	int move_direction;

	//+ �̻��� ��� ����, �̻��� ����, �̻��� �ִ� �̵� �Ÿ�, ������
	bool isMissile = true;
	XMFLOAT3 MovingDirection = XMFLOAT3(0.0f, 0.0f, 1.0f);
	double moveDistance{};
	float EnemyMissileDelay{};
	float DefaultEnemyMissileDelay = 50;

	//+ �ٿ�� �ڽ�
	BoundingOrientedBox m_OBB = BoundingOrientedBox();
	void UpdateBoundingBox();
	//+���� ���� ����
	bool isAlive = true;
	float hp = 100;

	void SetScale(float x, float y, float z);
	void SetScale(XMFLOAT3 scale);
	void SetMesh(CMesh *pMesh);
	void SetShader(CShader *pShader);

	virtual void CreateShaderVariables(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void UpdateShaderVariables(ID3D12GraphicsCommandList* pd3dCommandList);
	virtual void ReleaseShaderVariables();

	virtual void Animate(float fTimeElapsed);
	virtual void OnPrepareRender() { }
	virtual void Render(ID3D12GraphicsCommandList *pd3dCommandList, CCamera *pCamera = NULL);

	virtual void ReleaseUploadBuffers();

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetLook();
	XMFLOAT3 GetUp();
	XMFLOAT3 GetRight();

	void SetPosition(float x, float y, float z);
	void SetPosition(XMFLOAT3 xmf3Position);

	void SetColor(XMFLOAT3 xmf3Color) { m_xmf3Color = xmf3Color; }

	void MoveStrafe(float fDistance = 1.0f);
	void MoveUp(float fDistance = 1.0f);
	void MoveForward(float fDistance = 1.0f);

	void Rotate(float fPitch = 10.0f, float fYaw = 10.0f, float fRoll = 10.0f);
	void Rotate(XMFLOAT3 *pxmf3Axis, float fAngle);
};

class CUfoObject : public CGameObject
{
public:
	CUfoObject();
	virtual ~CUfoObject();
};

