// apps.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "1121Pro2.h"
#include "apps.h"
#include "afxdialogex.h"


// apps 대화 상자입니다.

IMPLEMENT_DYNAMIC(apps, CDialog)

apps::apps(CWnd* pParent /*=NULL*/)
	: CDialog(apps::IDD, pParent)
{

}

apps::~apps()
{
}

void apps::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(apps, CDialog)
END_MESSAGE_MAP()


// apps 메시지 처리기입니다.
