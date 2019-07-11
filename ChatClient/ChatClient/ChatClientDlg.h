﻿
// ChatClientDlg.h: 헤더 파일
//

#include "CClientSocket.h"

#pragma once


// CChatClientDlg 대화 상자
class CChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CChatClientDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	CClientSocket m_ClientSocket;


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list_msg;
	CEdit m_edit_send;
	afx_msg void OnClickedBtnSend();
protected:
	afx_msg LRESULT OnClientRecv(WPARAM wParam, LPARAM lParam);
};
