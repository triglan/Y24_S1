//-----------------------------------------------------------------------------
// File: Scene.h
//-----------------------------------------------------------------------------

#pragma once

#include "Shader.h"

class CScene
{
public:
	CScene();
	~CScene();

	void InputPlayer(CPlayer* player);

	// �÷��̾� �̻��� ����
	void CreateMissile();

	// ufo �̻��� ����
	void CreateUfoMissile(int i);

	bool OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	bool OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	void BuildObjects(ID3D12Device* pd3dDevice, ID3D12GraphicsCommandList* pd3dCommandList);
	void ReleaseObjects();

	ID3D12RootSignature* CreateGraphicsRootSignature(ID3D12Device* pd3dDevice);
	ID3D12RootSignature* GetGraphicsRootSignature() { return(m_pd3dGraphicsRootSignature); }

	bool ProcessInput();
	void AnimateObjects(float fTimeElapsed);
	void PrepareRender(ID3D12GraphicsCommandList* pd3dCommandList);
	void Render(ID3D12GraphicsCommandList* pd3dCommandList, CCamera* pCamera = NULL);

	void ReleaseUploadBuffers();

	void PlayerMissileToUfoCollision();
	void UfoMissileToPlayerCollision();

	CGameObject* m_pShield{};

protected:
	ID3D12RootSignature* m_pd3dGraphicsRootSignature = NULL;

	CPlayer* m_pPlayer{};

	int	m_nUfos{};
	CGameObject** m_pUfo{};

	int m_nMissiles{};
	CGameObject** m_pMissile{};

	int m_nUfoMissiles{};
	CGameObject** m_pUfoMissile{};
};
