#pragma once

#define WM_CLIENT_MSG_RECV WM_USER + 2
#define WM_CLIENT_CLOSE WM_USER + 3

// CClientSocket 명령 대상

class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();
	void SetWnd(HWND hWnd); // Sendmessage 활용을 위한 메인의 핸들을 맏는 함수
	HWND m_hWnd;

	virtual void OnReceive(int nErrorCode); // 서버 통신 받을 시의 처리 함수
	virtual void OnClose(int nErrorCode); // 소켓 해제 시의 처리 함수
};


