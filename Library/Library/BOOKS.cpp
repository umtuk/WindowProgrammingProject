// BOOKS.h : CBOOKS Ŭ������ �����Դϴ�.



// CBOOKS �����Դϴ�.

// �ڵ� ���� ��ġ 2019�� 6�� 6�� �����, ���� 11:22

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

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[BOOK_ISBN]"), m_BOOK_ISBN);
	RFX_Text(pFX, _T("[BOOK_TITLE]"), m_BOOK_TITLE);
	RFX_Text(pFX, _T("[BOOK_AUTHOR]"), m_BOOK_AUTHOR);
	RFX_Text(pFX, _T("[BOOK_RENT_YN]"), m_BOOK_RENT_YN);

}
/////////////////////////////////////////////////////////////////////////////
// CBOOKS ����

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