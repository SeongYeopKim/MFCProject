// SmartPhone.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "1121Pro2.h"
#include "SmartPhone.h"
#include "afxdialogex.h"


// CSmartPhone 대화 상자입니다.

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


// CSmartPhone 메시지 처리기입니다.


void CSmartPhone::OnStnClickedText11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
