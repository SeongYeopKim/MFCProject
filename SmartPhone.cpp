// SmartPhone.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "1121Pro2.h"
#include "SmartPhone.h"
#include "afxdialogex.h"


// CSmartPhone ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSmartPhone, CDialog)

CSmartPhone::CSmartPhone(CWnd* pParent /*=NULL*/)
	: CDialog(CSmartPhone::IDD, pParent)
	, warn(_T(""))
{

}

CSmartPhone::~CSmartPhone()
{
}
 
void CSmartPhone::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT1, warn);
}


BEGIN_MESSAGE_MAP(CSmartPhone, CDialog)
	ON_STN_CLICKED(IDC_TEXT11, &CSmartPhone::OnStnClickedText11)
END_MESSAGE_MAP()


// CSmartPhone �޽��� ó�����Դϴ�.


void CSmartPhone::OnStnClickedText11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
