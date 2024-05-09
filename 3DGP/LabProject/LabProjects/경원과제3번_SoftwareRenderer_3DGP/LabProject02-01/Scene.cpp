#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

CScene::CScene(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

CScene::~CScene()
{
}

void CScene::BuildObjects()
{
	CExplosiveObject::PrepareExplosion();

	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 200.0f;
	// 벽 오브젝트 생성
	CWallMesh* pWallCubeMesh = new CWallMesh(fHalfWidth * 2.0f, fHalfHeight * 2.0f, fHalfDepth * 2.0f, 30);

	m_pWallsObject = new CWallsObject();
	m_pWallsObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pWallsObject->SetMesh(pWallCubeMesh);
	m_pWallsObject->SetColor(RGB(0, 0, 0));
	m_pWallsObject->m_pxmf4WallPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, fHalfDepth);
	m_pWallsObject->m_pxmf4WallPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, fHalfDepth);
	m_pWallsObject->m_xmOOBBPlayerMoveCheck = BoundingOrientedBox(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.05f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));

	// 쉴드 오브젝트 생성
	CShieldMesh* pShieldCubeMesh = new CShieldMesh(fHalfWidth * 0.12f, fHalfHeight * 0.12f, fHalfDepth * 0.027f);

	m_pShieldObject = new CShieldObject();
	m_pShieldObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pShieldObject->SetMesh(pShieldCubeMesh);
	m_pShieldObject->SetColor(RGB(0, 0, 0));
	m_pShieldObject->m_pxmf4ShiledPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pShieldObject->m_pxmf4ShiledPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pShieldObject->m_pxmf4ShiledPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	m_pShieldObject->m_pxmf4ShiledPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	m_pShieldObject->m_pxmf4ShiledPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, fHalfDepth);
	m_pShieldObject->m_pxmf4ShiledPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, fHalfDepth);
	m_pShieldObject->m_xmOOBBPlayerMoveCheck = BoundingOrientedBox(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.05f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	m_pShieldObject->m_tog = false;

	// 시작 오브젝트 생성
	CStartMesh* pStartCubeMesh = new CStartMesh(fHalfWidth * 0.3f, fHalfHeight * 0.15f, fHalfDepth * 0.f);

	m_pStartObject = new CStartObject();
	m_pStartObject->SetPosition(0.0f, 3.0f, 0.0f);
	m_pStartObject->SetMesh(pStartCubeMesh);
	m_pStartObject->SetColor(RGB(0, 0, 0));
	m_pStartObject->m_pxmf4StartPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pStartObject->m_pxmf4StartPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pStartObject->m_pxmf4StartPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	m_pStartObject->m_pxmf4StartPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	m_pStartObject->m_pxmf4StartPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, fHalfDepth);
	m_pStartObject->m_pxmf4StartPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, fHalfDepth);
	m_pStartObject->m_xmOOBBPlayerMoveCheck = BoundingOrientedBox(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.05f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));
	m_pStartObject->m_tog = true;

	// 큐브 오브젝트의 크기를 4 4 4로 생성
	CCubeMesh* pCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);

	// 큐브 오브젝트를 10개 생성
	m_nObjects = 10;
	m_ppObjects = new CGameObject * [m_nObjects];

	CExplosiveObject *pExplosiveObject = new CExplosiveObject();
	// 객체 종류
	pExplosiveObject->SetMesh(pCubeMesh);
	// 색 좌표
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	// 위치 좌표
	pExplosiveObject->SetPosition(-13.5f, 0.0f, -14.0f);
	// 회전축 설정
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	// 회전하는 속도
	pExplosiveObject->SetRotationSpeed(90.0f);
	// 이동방향 설정
	pExplosiveObject->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 0.0f));
	// 움직이는 속도
	pExplosiveObject->SetMovingSpeed(10.5f);
	// 집어 넣기
	m_ppObjects[0] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 0, 255));
	pExplosiveObject->SetPosition(+13.5f, 0.0f, -14.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(180.0f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(-1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetMovingSpeed(8.8f);
	m_ppObjects[1] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 255, 0));
	pExplosiveObject->SetPosition(0.0f, +5.0f, 20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(30.15f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(1.0f, -1.0f, 0.0f));
	pExplosiveObject->SetMovingSpeed(5.2f);
	m_ppObjects[2] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(0, 255, 255));
	pExplosiveObject->SetPosition(0.0f, 0.0f, 0.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	pExplosiveObject->SetRotationSpeed(40.6f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, 1.0f));
	pExplosiveObject->SetMovingSpeed(20.4f);
	m_ppObjects[3] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 0, 255));
	pExplosiveObject->SetPosition(10.0f, 0.0f, 0.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(50.06f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(0.0f, 1.0f, 1.0f));
	pExplosiveObject->SetMovingSpeed(6.4f);
	m_ppObjects[4] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 255));
	pExplosiveObject->SetPosition(-10.0f, 0.0f, -10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(60.06f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 1.0f));
	pExplosiveObject->SetMovingSpeed(8.9f);
	m_ppObjects[5] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 255));
	pExplosiveObject->SetPosition(-10.0f, 10.0f, -10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(60.06f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(1.0f, 1.0f, 1.0f));
	pExplosiveObject->SetMovingSpeed(9.7f);
	m_ppObjects[6] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 128));
	pExplosiveObject->SetPosition(-10.0f, 10.0f, -20.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(70.06f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(-1.0f, 1.0f, 1.0f));
	pExplosiveObject->SetMovingSpeed(15.6f);
	m_ppObjects[7] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(128, 0, 255));
	pExplosiveObject->SetPosition(-15.0f, 10.0f, -30.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	pExplosiveObject->SetMovingSpeed(15.0f);
	m_ppObjects[8] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(+15.0f, 10.0f, 0.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	pExplosiveObject->SetMovingDirection(XMFLOAT3(-0.0f, 0.0f, -1.0f));
	pExplosiveObject->SetMovingSpeed(15.0f);
	m_ppObjects[9] = pExplosiveObject;

#ifdef _WITH_DRAW_AXIS
	m_pWorldAxis = new CGameObject();
	CAxisMesh* pAxisMesh = new CAxisMesh(0.5f, 0.5f, 0.5f);
	m_pWorldAxis->SetMesh(pAxisMesh);
#endif
}

void CScene::ReleaseObjects()
{
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;

	if (m_pWallsObject) delete m_pWallsObject;

	if (m_pShieldObject) delete m_pShieldObject;

#ifdef _WITH_DRAW_AXIS
	if (m_pWorldAxis) delete m_pWorldAxis;
#endif
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{

}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[int(wParam - '1')];
			pExplosiveObject->m_bBlowingUp = true;
			break;
		}
		case 'A':
			for (int i = 0; i < m_nObjects; i++)
			{
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
			}
			break;
		case 'Z':
			m_pShieldObject->SetPosition(m_pPlayer->m_xmf3Position);
			m_pShieldObject->m_tog = true;
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case 'Z':
			m_pShieldObject->m_tog = false;
			break;
		}
		break;
	default:
		break;
	}

}

CGameObject* CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera)
{
	// 마우스 커서가 가리키는 위치를 저장할 변수
	XMFLOAT3 xmf3PickPosition;

	// 윈도우 좌표계 DirectX 좌표계 차이 보정
	xmf3PickPosition.x = (((2.0f * xClient) / (float)pCamera->m_Viewport.m_nWidth) - 1) / pCamera->m_xmf4x4PerspectiveProject._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / (float)pCamera->m_Viewport.m_nHeight) - 1) / pCamera->m_xmf4x4PerspectiveProject._22;

	// 렌더링된 객체들 중 가장 가까운 객체를 찾기 위해 z좌표 설정
	xmf3PickPosition.z = 1.0f;

	// 계산된 마우스 클릭 위치 로드
	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);

	// 뷰 행렬 로드
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	// 교차된 객체의 수를 나타내는 변수 초기화
	int nIntersected = 0;

	// 가장 가까운 교차 지점의 거리를 나타내는 변수 초기화
	float fNearestHitDistance = FLT_MAX;

	// 가장 가까운 객체를 가리키는 포인터 초기화
	CGameObject* pNearestObject = NULL;

	// 모든 객체 반복
	for (int i = 0; i < m_nObjects; i++)
	{
		// 현재 객체의 교차 지점의 거리를 초기화
		float fHitDistance = FLT_MAX;

		// 현재 객체와 레이의 교차를 계산하고 교차된 경우 nIntersected 증가
		nIntersected = m_ppObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);

		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance))
		{
			// 현재 객체의 교차 지점 거리를 최근에 계산된 교차 지점 거리로 설정
			fNearestHitDistance = fHitDistance;
			// 현재 객체를 가장 가까운 객체로 설정
			pNearestObject = m_ppObjects[i];
		}
	}
	// 리턴
	return(pNearestObject);
}
void CScene::CheckObjectByObjectCollisions()
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = (i + 1); j < m_nObjects; j++)
		{
			if (m_ppObjects[i]->m_xmOOBB.Intersects(m_ppObjects[j]->m_xmOOBB))
			{
				m_ppObjects[i]->m_pObjectCollided = m_ppObjects[j];
				m_ppObjects[j]->m_pObjectCollided = m_ppObjects[i];
			}
		}
	}
	for (int i = 0; i < m_nObjects; i++)
	{
		if (m_ppObjects[i]->m_pObjectCollided)
		{
			XMFLOAT3 xmf3MovingDirection = m_ppObjects[i]->m_xmf3MovingDirection;
			float fMovingSpeed = m_ppObjects[i]->m_fMovingSpeed;
			m_ppObjects[i]->m_xmf3MovingDirection = m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection;
			m_ppObjects[i]->m_fMovingSpeed = m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection = xmf3MovingDirection;
			m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed = fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_pObjectCollided = NULL;
			m_ppObjects[i]->m_pObjectCollided = NULL;
		}
	}
}

void CScene::CheckObjectByWallCollisions()
{
	for (int i = 0; i < m_nObjects; i++)
	{
		ContainmentType containType = m_pWallsObject->m_xmOOBB.Contains(m_ppObjects[i]->m_xmOOBB);
		switch (containType)
		{
		case DISJOINT:
		{
			int nPlaneIndex = -1;
			for (int j = 0; j < 6; j++)
			{
				PlaneIntersectionType intersectType = m_ppObjects[i]->m_xmOOBB.Intersects(XMLoadFloat4(&m_pWallsObject->m_pxmf4WallPlanes[j]));
				if (intersectType == BACK)
				{
					nPlaneIndex = j;
					break;
				}
			}
			if (nPlaneIndex != -1)
			{
				XMVECTOR xmvNormal = XMVectorSet(m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].x, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].y, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].z, 0.0f);
				XMVECTOR xmvReflect = XMVector3Reflect(XMLoadFloat3(&m_ppObjects[i]->m_xmf3MovingDirection), xmvNormal);
				XMStoreFloat3(&m_ppObjects[i]->m_xmf3MovingDirection, xmvReflect);
			}
			break;
		}
		case INTERSECTS:
		{
			int nPlaneIndex = -1;
			for (int j = 0; j < 6; j++)
			{
				PlaneIntersectionType intersectType = m_ppObjects[i]->m_xmOOBB.Intersects(XMLoadFloat4(&m_pWallsObject->m_pxmf4WallPlanes[j]));
				if (intersectType == INTERSECTING)
				{
					nPlaneIndex = j;
					break;
				}
			}
			if (nPlaneIndex != -1)
			{
				XMVECTOR xmvNormal = XMVectorSet(m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].x, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].y, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].z, 0.0f);
				XMVECTOR xmvReflect = XMVector3Reflect(XMLoadFloat3(&m_ppObjects[i]->m_xmf3MovingDirection), xmvNormal);
				XMStoreFloat3(&m_ppObjects[i]->m_xmf3MovingDirection, xmvReflect);
			}
			break;
		}
		case CONTAINS:
			break;
		}
	}
}

void CScene::CheckPlayerByWallCollision()
{
	BoundingOrientedBox xmOOBBPlayerMoveCheck;
	m_pWallsObject->m_xmOOBBPlayerMoveCheck.Transform(xmOOBBPlayerMoveCheck, XMLoadFloat4x4(&m_pWallsObject->m_xmf4x4World));
	XMStoreFloat4(&xmOOBBPlayerMoveCheck.Orientation, XMQuaternionNormalize(XMLoadFloat4(&xmOOBBPlayerMoveCheck.Orientation)));

	if (!xmOOBBPlayerMoveCheck.Intersects(m_pPlayer->m_xmOOBB)) m_pWallsObject->SetPosition(m_pPlayer->m_xmf3Position);
}

void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject** ppBullets = ((CAirplanePlayer*)m_pPlayer)->m_ppBullets;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_ppObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
				ppBullets[j]->Reset();
			}
		}
	}
}

void CScene::Animate(float fElapsedTime)
{
	m_pWallsObject->Animate(fElapsedTime);

	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Animate(fElapsedTime);

	CheckPlayerByWallCollision();

	CheckObjectByWallCollisions();

	CheckObjectByObjectCollisions();

	CheckObjectByBulletCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);

	CGraphicsPipeline::SetViewPerspectiveProjectTransform(&pCamera->m_xmf4x4ViewPerspectiveProject);
	m_pWallsObject->Render(hDCFrameBuffer, pCamera);
	m_pShieldObject->Render(hDCFrameBuffer, pCamera);
	m_pStartObject->Render(hDCFrameBuffer, pCamera);
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);

	if (m_pPlayer) m_pPlayer->Render(hDCFrameBuffer, pCamera);

//UI
#ifdef _WITH_DRAW_AXIS
	CGraphicsPipeline::SetViewOrthographicProjectTransform(&pCamera->m_xmf4x4ViewOrthographicProject);
	m_pWorldAxis->SetRotationTransform(&m_pPlayer->m_xmf4x4World);
	m_pWorldAxis->Render(hDCFrameBuffer, pCamera);
#endif
}
