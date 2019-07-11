#pragma once

#include "BOOKS.h"

// AddDlg 대화 상자

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~AddDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonApply();
//	CEdit m_editISBN;
//	CEdit m_editTitle;
//	CEdit m_editAuthor;
};
