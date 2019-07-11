
// LibraryDlg.h: 헤더 파일
//

#include "BOOKS.h"
#include "AddDlg.h"

#pragma once


// CLibraryDlg 대화 상자
class CLibraryDlg : public CDialogEx
{
// 생성입니다.
public:
	CLibraryDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIBRARY_DIALOG };
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
public:
	CListCtrl m_ctrlList;

	void SetCtrlList();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonSearch();

	CBOOKS books;
	CEdit m_editISBN;
	CEdit m_editTitle;
	CEdit m_editAuthor;
	CEdit m_editRentYN;
	afx_msg void OnClickList(NMHDR *pNMHDR, LRESULT *pResult);
};
