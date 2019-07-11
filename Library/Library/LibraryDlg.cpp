
// LibraryDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Library.h"
#include "LibraryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLibraryDlg 대화 상자



CLibraryDlg::CLibraryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIBRARY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_ctrlList);
	DDX_Control(pDX, IDC_EDIT_ISBN, m_editISBN);
	DDX_Control(pDX, IDC_EDIT_TITLE, m_editTitle);
	DDX_Control(pDX, IDC_EDIT_AUTHOR, m_editAuthor);
	DDX_Control(pDX, IDC_EDIT_RENT_YN, m_editRentYN);
}

BEGIN_MESSAGE_MAP(CLibraryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CLibraryDlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CLibraryDlg::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CLibraryDlg::OnClickedButtonSearch)
	ON_NOTIFY(NM_CLICK, IDC_LIST, &CLibraryDlg::OnClickList)
END_MESSAGE_MAP()


// CLibraryDlg 메시지 처리기

BOOL CLibraryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CRect rt;
	m_ctrlList.GetWindowRect(&rt);
	m_ctrlList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_ctrlList.InsertColumn(0, _T("ISBN"), LVCFMT_LEFT, rt.Width() * 0.20);
	m_ctrlList.InsertColumn(1, _T("TITLE"), LVCFMT_CENTER, rt.Width() * 0.45);
	m_ctrlList.InsertColumn(2, _T("AUTHOR"), LVCFMT_CENTER, rt.Width() * 0.20);
	m_ctrlList.InsertColumn(3, _T("RENT_YN"), LVCFMT_CENTER, rt.Width() * 0.15);

	SetCtrlList();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CLibraryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CLibraryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CLibraryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLibraryDlg::SetCtrlList()
{
	m_ctrlList.DeleteAllItems();

	if (!books.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결하지 못했습니다."));
	}

	int i = 0;

	while (!books.IsEOF()) {

		m_ctrlList.InsertItem(i, _T("%d", books.m_ID));

		m_ctrlList.SetItemText(i, 0, books.m_BOOK_ISBN);
		m_ctrlList.SetItemText(i, 1, books.m_BOOK_TITLE);
		m_ctrlList.SetItemText(i, 2, books.m_BOOK_AUTHOR);
		m_ctrlList.SetItemText(i, 3, books.m_BOOK_RENT_YN);

		books.MoveNext();

		i++;
	}

	books.Close();
}

void CLibraryDlg::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!books.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결하지 못했습니다."));
	}

	books.AddNew();
	CString str;

	GetDlgItemText(IDC_EDIT_ISBN, str);
	books.m_BOOK_ISBN = str;

	GetDlgItemText(IDC_EDIT_TITLE, str);
	books.m_BOOK_TITLE = str;

	GetDlgItemText(IDC_EDIT_AUTHOR, str);
	books.m_BOOK_AUTHOR = str;

	GetDlgItemText(IDC_EDIT_RENT_YN, str);
	books.m_BOOK_RENT_YN = str;

	if (!books.Update())
	{
		AfxMessageBox(_T("레코드를 추가할 수 없습니다."));
	}

	books.Close();

	SetCtrlList();
}


void CLibraryDlg::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!books.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결하지 못했습니다."));
	}

	int i = 0;

	while (!books.IsEOF()) {

		CString strISBN, strTitle, strAuthor, strRentYN;

		GetDlgItemText(IDC_EDIT_ISBN, strISBN);
		GetDlgItemText(IDC_EDIT_TITLE, strTitle);
		GetDlgItemText(IDC_EDIT_AUTHOR, strAuthor);
		GetDlgItemText(IDC_EDIT_RENT_YN, strRentYN);
		if (books.m_BOOK_ISBN == strISBN &&
			books.m_BOOK_TITLE == strTitle &&
			books.m_BOOK_AUTHOR == strAuthor &&
			books.m_BOOK_RENT_YN == strRentYN) {
			books.Delete();
			break;
		}

		books.MoveNext();

		i++;
	}

	books.Close();

	SetCtrlList();
}


void CLibraryDlg::OnClickedButtonSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlList.DeleteAllItems();
	
	if (!books.Open()) {
		AfxMessageBox(_T("데이터 소스와 연결하지 못했습니다."));
	}

	int i = 0;

	while (!books.IsEOF()) {

		CString strISBN, strTitle, strAuthor, strRentYN;

		GetDlgItemText(IDC_EDIT_ISBN, strISBN);
		GetDlgItemText(IDC_EDIT_TITLE, strTitle);
		GetDlgItemText(IDC_EDIT_AUTHOR, strAuthor);
		GetDlgItemText(IDC_EDIT_RENT_YN, strRentYN);
		if ((strISBN == _T("") || books.m_BOOK_ISBN == strISBN) &&
			(strTitle == _T("") || books.m_BOOK_TITLE == strTitle) &&
			(strAuthor == _T("") || books.m_BOOK_AUTHOR == strAuthor) &&
			(strRentYN == _T("") || books.m_BOOK_RENT_YN == strRentYN)) {
			
			
			m_ctrlList.InsertItem(i, _T("%d", books.m_ID));

			m_ctrlList.SetItemText(i, 0, books.m_BOOK_ISBN);
			m_ctrlList.SetItemText(i, 1, books.m_BOOK_TITLE);
			m_ctrlList.SetItemText(i, 2, books.m_BOOK_AUTHOR);
			m_ctrlList.SetItemText(i, 3, books.m_BOOK_RENT_YN);
			
			i++;
		}

		books.MoveNext();
	}

	books.Close();
}


void CLibraryDlg::OnClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int i = pNMItemActivate->iItem;

	if (i >= 0 && i < m_ctrlList.GetItemCount())
	{
		m_editISBN.SetWindowTextW(m_ctrlList.GetItemText(i, 0));
		m_editTitle.SetWindowTextW(m_ctrlList.GetItemText(i, 1));
		m_editAuthor.SetWindowTextW(m_ctrlList.GetItemText(i, 2));
		m_editRentYN.SetWindowTextW(m_ctrlList.GetItemText(i, 3));
	}

	*pResult = 0;
}
