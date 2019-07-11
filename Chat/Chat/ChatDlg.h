
// ChatDlg.h: 헤더 파일
//

#pragma once

#include "CServerSocket.h"


// CChatDlg 대화 상자
class CChatDlg : public CDialogEx
{
// 생성입니다.
public:
	CChatDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CClientSocket *m_pClientSocket;
	CServerSocket *m_pServerSocket;
public:
	CListBox m_list_client; // IDC_LIST_CLIENT
	CListBox m_list_msg; // IDC_LIST_MSG
	CPtrList m_ptrClientSocketList; // For manage Client Sockets
protected:
	afx_msg LRESULT OnAcceptSocket(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClientMsgRecv(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClientClose(WPARAM wParam, LPARAM lParam);
};
