
// 1121Pro2View.h : CMy1121Pro2View 클래스의 인터페이스
//

#pragma once
 
#include "SmartPhone.h"
#include "atltypes.h"
#include "person.h"
#include "car.h"
#include "Cuserdlg.h"
#include "apps.h"



class CMy1121Pro2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1121Pro2View();
	DECLARE_DYNCREATE(CMy1121Pro2View)

// 특성입니다.
public:
	CMy1121Pro2Doc* GetDocument() const;
	CSmartPhone *m_dlg;
	Cuserdlg *m_dlg2;
	apps *m_dlg3;

public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual void DrawImage(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void CMy1121Pro2View::Init_map1();
	void CMy1121Pro2View::DrawMonitor(CDC *pDC);

protected:

// 구현입니다.
public:
	virtual ~CMy1121Pro2View();

	

	police Pol, Pol1, Pol2;
	bumin Bum, Bum1;
	bumin Bum2_[10];
	bumin Bum4_1; // 범인 4번맵의 1번째를 의미함.
	pol_car Pcar, Pcar1, Pcar2;
	car Car[100], Car1[100], Car2[100];
	person user;
	CRgn CRg;
	CRect CRe;


	CRect house, house1, house2; //집
	CRect map[5]; //미니맵

	CRect school;

	//CRect car[100]; //일반차
	//CRect p_car; //경찰차 
	//CRect bum; //범인
	//CRect poli; //경찰
	//CPoint b_pnt;//범인 포인트
	//CPoint pc_pnt; //경찰차 포인트
	//CPoint c_pnt[100]; //일반차 포인트
	//CPoint p_pnt;//경찰 포인트
	
	CPoint tmp; //임시
	CString str; // 테스트용 글씨 1
	CString str2; // 2 
	CString temp;

	CString test1; // 2 
	CString test2
		; // 2 
	CString warr; //경고창 
	CString msg;
	CString sum;

	UINT isCar;
	UINT movsec;
	UINT movcnt; 
	UINT sec; // 시간 계산용 1초 
	UINT sec1;
	UINT monitor;
	UINT w_cnt, w_cnt1; //경고 카운트
	UINT w_cnt_sec;
	boolean w_cnt_ck;
	UINT w_timer;
	UINT cnt; //경찰차 조명용 카운트 
	UINT ck; //모냐이게
	UINT i, j,c;
	UINT k;
	UINT car_Time, car_Time1, car_Time2;
	UINT moving;
	UINT is_dlg2;
	UINT is_dlg3;
	UINT count;
	UINT text_sec;

	CString jail_msg;
	CPoint foot;

	boolean jail;
	boolean vis_foot;
	boolean police; //경찰 떴나
	boolean stop; // 움직임 중단용
	boolean incar; //범인이 차에 있나없나
	boolean Aincar; // 모두 차에 있나없나
	boolean isUP; // 경찰이 위에 있나
	boolean userclick; //3번맵의 유저 클릭했나 안했나
	boolean useapp; //어플실행
	boolean start; //처음 한번만을 위해
	boolean POLICE, POLICE2;
	boolean OUTPOLI, OUTPOLI2;

	////1번맵
	//CRect School; //여고
	//CRect car1[100]; //일반차
	//CRect p_car1; //경찰차 
	//CRect bum1; //범인
	//CRect poli1; //경찰
	//CRect house1; //집
	

	


	
	COLORREF m_color;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnInitialUpdate();
	int bumclick;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnReset();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	/*
	CPoint bum1_point;
	CString bum_name;
	CString bum_age;
	CString bum_sinname;
	CString bum_sin;
	CString bum_warn;

	CString bum1_name;
	CString bum1_age;
	CString bum1_sinname;
	CString bum1_sin;
	CString bum1_warn;
	int bum1_sin;
	int bum1_warn;
	*/

	afx_msg void OnUser();
	afx_msg void Onapp();
	afx_msg void OnUpdateApp(CCmdUI *pCmdUI);
	afx_msg void Onendapp();
	afx_msg void OnUpdateEndapp(CCmdUI *pCmdUI);
	afx_msg void OnRemove();
	afx_msg void OnUpdateRemove(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // 1121Pro2View.cpp의 디버그 버전
inline CMy1121Pro2Doc* CMy1121Pro2View::GetDocument() const
   { return reinterpret_cast<CMy1121Pro2Doc*>(m_pDocument); }
#endif

