#pragma once


// Cuserdlg ��ȭ �����Դϴ�.

class Cuserdlg : public CDialog
{
	DECLARE_DYNAMIC(Cuserdlg)

public:
	Cuserdlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Cuserdlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
