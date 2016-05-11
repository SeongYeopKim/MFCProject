// Cuserdlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "1121Pro2.h"
#include "Cuserdlg.h"
#include "afxdialogex.h"


// Cuserdlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(Cuserdlg, CDialog)

Cuserdlg::Cuserdlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cuserdlg::IDD, pParent)
{

}

Cuserdlg::~Cuserdlg()
{
}

void Cuserdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cuserdlg, CDialog)
END_MESSAGE_MAP()


// Cuserdlg 메시지 처리기입니다.
