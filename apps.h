#pragma once


// apps ��ȭ �����Դϴ�.

class apps : public CDialog
{
	DECLARE_DYNAMIC(apps)

public:
	apps(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~apps();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
