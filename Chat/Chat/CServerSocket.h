#pragma once

#define WM_ACCEPT_SOCKET WM_USER + 1

#include "CClientSocket.h"

// CServerSocket 명령 대상

class CServerSocket : public CSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	void SetWnd(HWND hWnd); // Sendmessage 활용을 위한 메인의 핸들을 받는 함수
	HWND m_hWnd;

	virtual void OnAccept(int nErrorCode); // 클라이언트가 서버와 연결 시의 처리 함수
};


