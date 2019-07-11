// BOOKS.h : CBOOKS 클래스의 구현입니다.



// CBOOKS 구현입니다.

// 코드 생성 위치 2019년 6월 6일 목요일, 오후 11:22

#include "stdafx.h"
#include "BOOKS.h"
IMPLEMENT_DYNAMIC(CBOOKS, CRecordset)

CBOOKS::CBOOKS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_BOOK_ISBN = L"";
	m_BOOK_TITLE = L"";
	m_BOOK_AUTHOR = L"";
	m_BOOK_RENT_YN = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CBOOKS::GetDefaultConnect()
{
	return _T("DSN=Library;DBQ=C:\\Users\\\xc5c4\xd0dc\xc6b1\\Documents\\LibraryDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CBOOKS::GetDefaultSQL()
{
	return _T("[BOOKS]");
}

void CBOOKS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[BOOK_ISBN]"), m_BOOK_ISBN);
	RFX_Text(pFX, _T("[BOOK_TITLE]"), m_BOOK_TITLE);
	RFX_Text(pFX, _T("[BOOK_AUTHOR]"), m_BOOK_AUTHOR);
	RFX_Text(pFX, _T("[BOOK_RENT_YN]"), m_BOOK_RENT_YN);

}
/////////////////////////////////////////////////////////////////////////////
// CBOOKS 진단

#ifdef _DEBUG
void CBOOKS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBOOKS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

CBOOKS books;