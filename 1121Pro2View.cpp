/*
사운드에 필요한 함수
PlaySound((LPCSTR)MAKEINTRESOURCE(IDB_SOUND), NULL, SND_ASYNC | SND_RESOURCE| SND_LOOP );  //무한반복
PlaySound((LPCSTR)MAKEINTRESOURCE(ID_INTRO1), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC );  //1회반복
PlaySound(NULL, AfxGetInstanceHandle(),  NULL);  //소리 중단




*/
// 1121Pro2View.cpp : CMy1121Pro2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1121Pro2.h"
#endif

#include "1121Pro2Doc.h"
#include "1121Pro2View.h"
#include <mmsystem.h> 
#pragma comment(lib, "winmm")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1121Pro2View

IMPLEMENT_DYNCREATE(CMy1121Pro2View, CView)

	BEGIN_MESSAGE_MAP(CMy1121Pro2View, CView)
		ON_WM_CONTEXTMENU()
		ON_WM_RBUTTONUP()
		ON_WM_TIMER()
		ON_WM_CHAR()
		ON_WM_KEYDOWN()
		ON_WM_LBUTTONDOWN()
		ON_COMMAND(ID_RESET, &CMy1121Pro2View::OnReset)
		ON_WM_MOUSEMOVE()
		ON_COMMAND(ID_USER, &CMy1121Pro2View::OnUser)
		ON_COMMAND(ID_app, &CMy1121Pro2View::Onapp)
		ON_UPDATE_COMMAND_UI(ID_app, &CMy1121Pro2View::OnUpdateApp)
		ON_COMMAND(ID_endapp, &CMy1121Pro2View::Onendapp)
		ON_UPDATE_COMMAND_UI(ID_endapp, &CMy1121Pro2View::OnUpdateEndapp)
		ON_COMMAND(ID_REMOVE, &CMy1121Pro2View::OnRemove)
		ON_UPDATE_COMMAND_UI(ID_REMOVE, &CMy1121Pro2View::OnUpdateRemove)
	END_MESSAGE_MAP()

	// CMy1121Pro2View 생성/소멸

	CMy1121Pro2View::CMy1121Pro2View()



	{ 
		count=0;
		m_dlg = new CSmartPhone;
		m_dlg->Create(IDD_DIALOG1);
		m_dlg->ShowWindow(SW_SHOW);
		m_dlg->MoveWindow(1030,0,300,500);
		// TODO: 여기에 생성 코드를 추가합니다.
		Bum.pnt.x=300;
		Bum.pnt.y=400;
		Bum1.pnt.x=650;
		Bum1.pnt.y=200;

		Bum2_[0].pnt.x=500;
		Bum2_[0].pnt.y=400;

		Bum2_[1].pnt.x=600;
		Bum2_[1].pnt.y=100;

		Bum2_[2].pnt.x=500;
		Bum2_[2].pnt.y=200;

		Bum2_[3].pnt.x=300;
		Bum2_[3].pnt.y=300;

		Bum2_[4].pnt.x=300;
		Bum2_[4].pnt.y=500;

		Bum2_[5].pnt.x=320;
		Bum2_[5].pnt.y=500;

		Bum2_[6].pnt.x=250;
		Bum2_[6].pnt.y=300;

		Bum4_1.pnt.x=550;
		Bum4_1.pnt.y=200;


		user.pnt.x=200;
		user.pnt.y=200;

		Pcar.pnt.x=-100;
		Pcar.pnt.y=225;
		Pcar1.pnt.x=-100;
		Pcar1.pnt.y=430;
		Pcar2.pnt.x=-100;
		Pcar2.pnt.y=325;

		//c_pnt.x=800;
		//c_pnt.y=180;
		Pol.pnt.x=-10;
		Pol.pnt.y=-10;
		Pol2.pnt.x=-10;
		Pol2.pnt.y=-10;

		movsec=10;
		movcnt=0;
		moving=0;
		sec=1;
		sec1=1;
		monitor=0;
		car_Time=900;
		car_Time1=900;
		car_Time2=900;
		w_cnt_sec=0;
		w_timer=0;
		i=0;
		j=0;
		c=0;
		ck=0;
		cnt=0;
		w_cnt=10;
		w_cnt1=10;
		m_color = RGB(255,0,0);
		stop=false;
		police=false;
		incar=false;
		Aincar=false;
		isUP=false;
		text_sec=0;


		school.SetRect(150,450,250,550);
		house.SetRect(250,380,350,480);
		house1.SetRect(600,450,700,550);
		house2.SetRect(500,150,600,250);


		bumclick = 0;

		Bum.sin = 32;
		Bum.name="오윤석";
		Bum.sin_name="성범죄 2범";
		Bum.age=22;
		Bum.warn=0;
		


		
		Bum1.sin = 42;
		Bum1.name="김덕배";
		Bum1.sin_name="아동 성추행 1범";
		Bum1.age=34;
		Bum1.warn=0;
	

	
		Bum2_[0].sin = 4;
		Bum2_[0].name="김승화";
		Bum2_[0].sin_name="성추행 미수 1범";
		Bum2_[0].age=42;
		Bum2_[0].warn=0;
	
		
	
		Bum2_[1].sin = 32;
		Bum2_[1].name="김동규";
		Bum2_[1].sin_name="강간등 상해 치사";
		Bum2_[1].age=39;
		Bum2_[1].warn=0;
	
		
		Bum2_[2].sin = 12;
		Bum2_[2].name="이기호";
		Bum2_[2].sin_name="성추행 2범";
		Bum2_[2].age=47;
		Bum2_[2].warn=0;
		
		
		Bum2_[3].sin = 43;
		Bum2_[3].name="김진성";
		Bum2_[3].sin_name="범죄유형1";
		Bum2_[3].age=22;
		Bum2_[3].warn=0;
	
		
		Bum2_[4].sin = 15;
		Bum2_[4].name="김상현";
		Bum2_[4].sin_name="범죄유형2";
		Bum2_[4].age=20;
		Bum2_[4].warn=0;
			
		Bum2_[5].sin = 17;
		Bum2_[5].name="강승연";
		Bum2_[5].sin_name="범죄유형3";
		Bum2_[5].age=21;
		Bum2_[5].warn=0;

		
		Bum2_[6].sin = 13;
		Bum2_[6].name="안홍익";
		Bum2_[6].sin_name="범죄유형4";
		Bum2_[6].age=31;
		Bum2_[6].warn=0;
		
		userclick=0;
		useapp=0;

		Bum4_1.sin = 12;
		Bum4_1.name="김두환";
		Bum4_1.sin_name="범죄유형2";
		Bum4_1.age=61;
		Bum4_1.warn=0;
		 
		for(int b=0;b<7;b++){
		Bum2_[b].ck=1;

		}

		for(int a=0;a<10;a++){
			Bum2_[a].info=0;
		}
		

		for(int i=0; i<100;i++){
			Car[i].pnt.x=1300;
			Car[i].pnt.y=170;
		}
		for(int i=0; i<100;i++){
			Car2[i].pnt.x=1300;
			Car2[i].pnt.y=360;
		}
		
		for(int i=0; i<100;i++){
			Car1[i].pnt.x=rand()%1400+1300;
			Car1[i].pnt.y=270;
		}


		
	}

	CMy1121Pro2View::~CMy1121Pro2View()
	{
	}

	BOOL CMy1121Pro2View::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: CREATESTRUCT cs를 수정하여 여기에서
		//  Window 클래스 또는 스타일을 수정합니다.

		return CView::PreCreateWindow(cs);
	}

	void CMy1121Pro2View::Init_map1(){ // 맵초기화
		m_dlg->DestroyWindow();

		m_dlg = new CSmartPhone;
		m_dlg->Create(IDD_DIALOG1);
		m_dlg->ShowWindow(SW_SHOW);
		m_dlg->MoveWindow(1030,0,300,500);
		
		KillTimer(301);
		KillTimer(290);
		
		count=0;
		m_dlg = new CSmartPhone;
		m_dlg->Create(IDD_DIALOG1);
		m_dlg->ShowWindow(SW_SHOW);
		m_dlg->MoveWindow(1030,0,300,500);
		// TODO: 여기에 생성 코드를 추가합니다.
		Bum.pnt.x=300;
		Bum.pnt.y=400;
		Bum1.pnt.x=650;
		Bum1.pnt.y=200;

		Bum2_[0].pnt.x=500;
		Bum2_[0].pnt.y=400;

		Bum2_[1].pnt.x=600;
		Bum2_[1].pnt.y=100;

		Bum2_[2].pnt.x=500;
		Bum2_[2].pnt.y=200;

		Bum2_[3].pnt.x=300;
		Bum2_[3].pnt.y=300;

		Bum2_[4].pnt.x=300;
		Bum2_[4].pnt.y=500;

		Bum2_[5].pnt.x=320;
		Bum2_[5].pnt.y=500;

		Bum2_[6].pnt.x=250;
		Bum2_[6].pnt.y=300;

		Bum4_1.pnt.x=550;
		Bum4_1.pnt.y=200;


		user.pnt.x=200;
		user.pnt.y=200;

		Pcar.pnt.x=-100;
		Pcar.pnt.y=225;
		Pcar1.pnt.x=-100;
		Pcar1.pnt.y=430;
		Pcar2.pnt.x=-100;
		Pcar2.pnt.y=325;

		//c_pnt.x=800;
		//c_pnt.y=180;
		Pol.pnt.x=-10;
		Pol.pnt.y=-10;
		Pol2.pnt.x=-10;
		Pol2.pnt.y=-10;

		movsec=10;
		movcnt=0;
		moving=0;
		sec=1;
		sec1=1;
		monitor=0;
		car_Time=900;
		car_Time1=900;
		car_Time2=900;
		w_cnt_sec=0;
		w_timer=0;
		i=0;
		j=0;
		c=0;
		ck=0;
		cnt=0;
		w_cnt=10;
		w_cnt1=10;
		m_color = RGB(255,0,0);
		stop=false;
		police=false;
		incar=false;
		Aincar=false;
		isUP=false;
		OUTPOLI=FALSE;
		OUTPOLI2=FALSE;
		POLICE=FALSE;
		POLICE2=FALSE;

		 


		bumclick = 0;

		userclick=0;
		useapp=0;
		 
		for(int b=0;b<7;b++){
		Bum2_[b].ck=1;

		}

		for(int a=0;a<10;a++){
			Bum2_[a].info=0;
		}
		

		for(int i=0; i<100;i++){
			Car[i].pnt.x=1300;
			Car[i].pnt.y=170;
		}
		for(int i=0; i<100;i++){
			Car2[i].pnt.x=1300;
			Car2[i].pnt.y=360;
		}
		
		for(int i=0; i<100;i++){
			Car1[i].pnt.x=rand()%1400+1300;
			Car1[i].pnt.y=270;
		}


		bumclick = 0;
	}

	void CMy1121Pro2View::DrawMonitor(CDC *pDC){
		CDC MemDC, MemDC1, MemDC2;
		CBitmap MyBitmap,*pOldBitmap;
		CBitmap newRoad,*oldRoad;
//		CBitmap Ntest, *Otest;
		CBrush newB, *oldB;
		CBrush newB10, *oldB10;
		CBrush nb_house, *ob_house;

		CDC dc_bum1, dc_pol, dc_bum[10];
		CBitmap nB_bum1, *oB_bum1;
		CBitmap nB_bum[10], *oB_bum[10];
		CBitmap nB_pol, *oB_pol;
		CDC dc_car[100];
		CBitmap nB_car[100], *oB_car[100];
		BITMAP CarInfo[100];
		BITMAP MyInfo;

		

		 
		CRect rectEllipse = CRect(user.pnt.x-100,user.pnt.y-100,user.pnt.x+110,user.pnt.y+110); 
		 CRgn rgnEllipse; 
		 rgnEllipse.CreateEllipticRgnIndirect(rectEllipse); 




		if(useapp==1){
			
			
		//	rgnEllipse.CreateEllipticRgnIndirect(rectEllipse); 
		//	 pDC->SelectClipRgn(&rgnEllipse); 
			
		}

		switch(monitor){
		case 0://1번맵
			pDC->TextOutA(200,0,"1번 시뮬레이션");

			
			nb_house.CreateSolidBrush(RGB(125,125,125));
			ob_house = pDC->SelectObject(&nb_house);
			pDC->Rectangle(house); //집
			pDC->SelectObject(ob_house);
			//pDC->Rectangle(0,175,1800,275); //차선 깔기

		

			MemDC1.CreateCompatibleDC(pDC);
			newRoad.LoadBitmap(IDB_BITMAP3);
			oldRoad=MemDC1.SelectObject(&newRoad);
			pDC->BitBlt(0,175,1800,275,&MemDC1,0,0,SRCCOPY);
			MemDC1.SelectObject(oldRoad);

			 
			MemDC.CreateCompatibleDC(pDC);
			MyBitmap.LoadBitmap(IDB_BITMAP1);
			MyBitmap.GetBitmap(&MyInfo);
			pOldBitmap=MemDC.SelectObject(&MyBitmap);

			pDC->TransparentBlt(Pcar.pnt.x,Pcar.pnt.y, MyInfo.bmWidth, MyInfo.bmHeight,
                           &MemDC,  0, 0, MyInfo.bmWidth, MyInfo.bmHeight,
                           RGB(255,0,255));

			MemDC.SelectObject(pOldBitmap);

			 
		


			//if(!(car.PtInRect(Bum.pnt))){

			

			newB.CreateSolidBrush(m_color);
			oldB = pDC->SelectObject(&newB);


			//	car.SetRect(c_pnt.x,c_pnt.y,c_pnt.x+30,c_pnt.y+20);

			Bum.rt.SetRect(Bum.pnt.x,Bum.pnt.y,Bum.pnt.x+20,Bum.pnt.y+20);
			Pcar.rt.SetRect(Pcar.pnt.x,Pcar.pnt.y,Pcar.pnt.x+30,Pcar.pnt.y+20);
			// pDC->Rectangle(Pcar.rt);


			

			Bum1.rt.SetRect(Bum1.pnt.x,Bum1.pnt.y,Bum1.pnt.x+10,Bum1.pnt.y+10);
			SetTimer(10,10,NULL);
			//SetTimer(20,1000,NULL);	 
			pDC->SelectObject(oldB);

			nB_car[0].LoadBitmap(IDB_CAr0);
			nB_car[0].GetBitmap(&CarInfo[0]);
			nB_car[1].LoadBitmap(IDB_CAR1);
			nB_car[1].GetBitmap(&CarInfo[1]);
			nB_car[2].LoadBitmap(IDB_CAR2);
			nB_car[2].GetBitmap(&CarInfo[2]);
			nB_car[3].LoadBitmap(IDB_CAR3);
			nB_car[3].GetBitmap(&CarInfo[3]);
			nB_car[4].LoadBitmap(IDB_CAR4);
			nB_car[4].GetBitmap(&CarInfo[4]);
			nB_car[5].LoadBitmap(IDB_CAR5);
			nB_car[5].GetBitmap(&CarInfo[5]);
			nB_car[6].LoadBitmap(IDB_CAR6);
			nB_car[6].GetBitmap(&CarInfo[6]);

			for(int j=0;j<30;j++){ //자동차 대 수
				Car[j].rt.SetRect(Car[j].pnt.x,Car[j].pnt.y,Car[j].pnt.x+30,Car[j].pnt.y+20);
				//pDC->Rectangle(Car[j].rt);
				
				dc_car[j].CreateCompatibleDC(pDC);
				 
				oB_car[j]=dc_car[j].SelectObject(&nB_car[j]);
				pDC->TransparentBlt(Car[j].pnt.x,Car[j].pnt.y, CarInfo[j].bmWidth, CarInfo[j].bmHeight,
                           &dc_car[j],  0, 0, CarInfo[j].bmWidth, CarInfo[j].bmHeight,
                           RGB(255,0,255));
				
				dc_car[j].SelectObject(oB_car[j]);
			
			}
				

			if(bumclick==0&&monitor==0){  //범인 클릭안하면
				//pDC->Rectangle(Bum.rt);
					dc_bum1.CreateCompatibleDC(pDC);
					nB_bum1.LoadBitmap(IDB_BUM1a);
					oB_bum1=dc_bum1.SelectObject(&nB_bum1);
					pDC->BitBlt(Bum.pnt.x,Bum.pnt.y,Bum.pnt.x+10,Bum.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
					dc_bum1.SelectObject(oB_bum1);
			}
		

			if(bumclick==0&&monitor==3){  //범인 클릭하면
				//pDC->Rectangle(Bum.rt);
				dc_bum1.CreateCompatibleDC(pDC);
				nB_bum1.LoadBitmap(IDB_BUM1a);
				oB_bum1=dc_bum1.SelectObject(&nB_bum1);
				pDC->BitBlt(Bum4_1.pnt.x,Bum4_1.pnt.y,Bum4_1.pnt.x+10,Bum4_1.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
				dc_bum1.SelectObject(oB_bum1);
			}
			if(bumclick==1&&monitor==0){  //클릭하면 범인상태 빨갱이만듬
				/*CBrush newB1, *oldB1;
				newB1.CreateSolidBrush(RGB(255,0,0));
				oldB1 = pDC->SelectObject(&newB1);
				pDC->Rectangle(Bum.rt);*/
				dc_bum1.CreateCompatibleDC(pDC);
				nB_bum1.LoadBitmap(IDB_BUM1b);
				oB_bum1=dc_bum1.SelectObject(&nB_bum1);
				pDC->BitBlt(Bum.pnt.x,Bum.pnt.y,Bum.pnt.x+10,Bum.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
				dc_bum1.SelectObject(oB_bum1);

			}
			pDC->SelectObject(oldB);
		


			if(Bum.pnt.x<=Pcar.pnt.x+10) {
				police=true;
			}

			if(sec==1){ // 초 설정 1초 마다 반복, 모달리스용!!!
				sec=0;
				if(!house.PtInRect(Bum.pnt)){
					ck=1;
					warr.Format("경고 ! %d초 안으로 집으로 돌아가세요",w_cnt);
					m_dlg->SetDlgItemText(IDC_TEXT1,warr);
					// pDC->TextOutA(300,80,warr);
					
				}
				

			}
			if(house.PtInRect(Bum.pnt)){
					warr.Format(" ");
					m_dlg->SetDlgItemText(IDC_TEXT1,warr);
					
				}
		//테스트 출력
			//	str.Format("car_Time : %d",car_Time);
		//	pDC->TextOutA(300,50,str);

			if(police==TRUE){
				// str.Format("폴리스 : %d, %d",Bum.pnt.x, Bum.pnt.y);
				str2.Format("폴리카 : %d, %d",Pcar.pnt.x, Pcar.pnt.y);

				Pol.rt.SetRect(Pol.pnt.x,Pol.pnt.y,Pol.pnt.x+20,Pol.pnt.y+20);
					dc_pol.CreateCompatibleDC(pDC);
					nB_pol.LoadBitmap(IDB_POLI);
					oB_pol=dc_pol.SelectObject(&nB_pol);
					pDC->BitBlt(Pol.pnt.x,Pol.pnt.y,Pol.pnt.x+10,Pol.pnt.y+10, &dc_pol,0,0,SRCCOPY);
					dc_pol.SelectObject(oB_pol);
				//pDC->Rectangle(Pol.rt);
				pDC->TextOutA(300,10,str);
				pDC->TextOutA(300,50,str2);

			}else 	{
				Pol.pnt.x=Pcar.pnt.x;
				Pol.pnt.y=Pcar.pnt.y;
			}
			if(Aincar==TRUE){
				if(Pcar.pnt.x>1300)
					KillTimer(10);
			}
			if(w_cnt==0)
				KillTimer(11);
			//}
			break;
		case 1: //2번맵
			
			SetTimer(203,10,NULL);
			pDC->TextOutA(200,0,"2번 시뮬레이션");
			Bum1.rt.SetRect(Bum1.pnt.x,Bum1.pnt.y,Bum1.pnt.x+20,Bum1.pnt.y+20);
			
			MemDC1.CreateCompatibleDC(pDC);  //도로 차선 깔기
			newRoad.LoadBitmap(IDB_BITMAP3);
			oldRoad=MemDC1.SelectObject(&newRoad);
			pDC->BitBlt(0,275,1800,375,&MemDC1,0,0,SRCCOPY);
			MemDC1.SelectObject(oldRoad);


			nb_house.CreateSolidBrush(RGB(150,150,150));
			ob_house = pDC->SelectObject(&nb_house);
				pDC->Rectangle(house1); //집
			
			pDC->SelectObject(ob_house);

			nb_house.CreateSolidBrush(RGB(150,150,0));
			ob_house = pDC->SelectObject(&nb_house);
			pDC->Rectangle(school);
			
			pDC->SelectObject(ob_house);

			


		

		//테스트 출력 
		//	test1.Format("w_timer : %d",Pol2.pnt.x); 
		//	test2.Format("car_Time : %d",Pol2.pnt.y);
			//test1.Format("car_Time : %d",Car1[0].pnt.x);
		//	pDC->TextOutA(300,50,test1);
			//test2.Format("car_Time : %d",Car1[1].pnt.x);
		//	pDC->TextOutA(300,80,test2);


			nB_car[0].LoadBitmap(IDB_CAr0);
			nB_car[0].GetBitmap(&CarInfo[0]);
			nB_car[1].LoadBitmap(IDB_CAR1);
			nB_car[1].GetBitmap(&CarInfo[1]);
			nB_car[2].LoadBitmap(IDB_CAR2);
			nB_car[2].GetBitmap(&CarInfo[2]);
			nB_car[3].LoadBitmap(IDB_CAR3);
			nB_car[3].GetBitmap(&CarInfo[3]);
			nB_car[4].LoadBitmap(IDB_CAR4);
			nB_car[4].GetBitmap(&CarInfo[4]);
			nB_car[5].LoadBitmap(IDB_CAR5);
			nB_car[5].GetBitmap(&CarInfo[5]);
			nB_car[6].LoadBitmap(IDB_CAR6);
			nB_car[6].GetBitmap(&CarInfo[6]);

			for(int j=0;j<30;j++){ //자동차 대 수
				Car1[j].rt.SetRect(Car1[j].pnt.x,Car1[j].pnt.y,Car1[j].pnt.x+30,Car1[j].pnt.y+20);
				//pDC->Rectangle(Car[j].rt);
				
				dc_car[j].CreateCompatibleDC(pDC);
				 
				oB_car[j]=dc_car[j].SelectObject(&nB_car[j]);
				pDC->TransparentBlt(Car1[j].pnt.x,Car1[j].pnt.y, CarInfo[j].bmWidth, CarInfo[j].bmHeight,
                           &dc_car[j],  0, 0, CarInfo[j].bmWidth, CarInfo[j].bmHeight,
                           RGB(255,0,255));
				
				dc_car[j].SelectObject(oB_car[j]);
			
			}


			if(bumclick==0) {
					dc_bum1.CreateCompatibleDC(pDC);
					nB_bum1.LoadBitmap(IDB_BUM1a);
					oB_bum1=dc_bum1.SelectObject(&nB_bum1);
					pDC->BitBlt(Bum1.pnt.x,Bum1.pnt.y,Bum1.pnt.x+10,Bum1.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
					dc_bum1.SelectObject(oB_bum1);
			}
			if(bumclick==2){
				CBrush newB1, *oldB1;
				newB1.CreateSolidBrush(RGB(255,0,0));
				oldB1 = pDC->SelectObject(&newB1);
				//pDC->Rectangle(Bum1.rt);
					dc_bum1.CreateCompatibleDC(pDC);
					nB_bum1.LoadBitmap(IDB_BUM1b);
					oB_bum1=dc_bum1.SelectObject(&nB_bum1);
					pDC->BitBlt(Bum1.pnt.x,Bum1.pnt.y,Bum1.pnt.x+10,Bum1.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
					dc_bum1.SelectObject(oB_bum1);
			    pDC->SelectObject(oldB1);
			}

			Pcar2.rt.SetRect(Pcar2.pnt.x,Pcar2.pnt.y,Pcar2.pnt.x+20,Pcar2.pnt.y+20);
			//pDC->Rectangle(Pcar1.rt);

			MemDC.CreateCompatibleDC(pDC);
			MyBitmap.LoadBitmap(IDB_BITMAP1);
			MyBitmap.GetBitmap(&MyInfo);
			pOldBitmap=MemDC.SelectObject(&MyBitmap);

			pDC->TransparentBlt(Pcar2.pnt.x,Pcar2.pnt.y, MyInfo.bmWidth, MyInfo.bmHeight,
                           &MemDC,  0, 0, MyInfo.bmWidth, MyInfo.bmHeight,
                           RGB(255,0,255));

			MemDC.SelectObject(pOldBitmap);

			Pol2.rt.SetRect(Pol2.pnt.x,Pol2.pnt.y,Pol2.pnt.x+20,Pol2.pnt.y+20);
			
			if(OUTPOLI2==TRUE){
					dc_pol.CreateCompatibleDC(pDC);
					nB_pol.LoadBitmap(IDB_POLI);
					oB_pol=dc_pol.SelectObject(&nB_pol);
					pDC->BitBlt(Pol2.pnt.x,Pol2.pnt.y,Pol2.pnt.x+10,Pol2.pnt.y+10, &dc_pol,0,0,SRCCOPY);
					dc_pol.SelectObject(oB_pol);
			}

			if(sec1==1){ // 초 설정 1초 마다 반복, 모달리스용!!!
				sec1=0;

				if(school.PtInRect(Bum1.pnt)){
					//SetTimer(292,1000,NULL);
						//if(w_timer>3){
							warr.Format("경고 ! %d초 안으로 학교를 벗어나세요",w_cnt1);
							m_dlg->SetDlgItemText(IDC_TEXT1,warr);

							if(w_cnt1<=0){
								warr.Format("경찰출동!",w_cnt1);
								m_dlg->SetDlgItemText(IDC_TEXT1,warr);
								SetTimer(301,10,NULL);
								POLICE2=TRUE;

							}
							// pDC->TextOutA(300,80,warr);
							//w_timer=0;

					//}

				}
			}


			break;
		case 2://3번맵
	
			pDC->TextOutA(200,0,"3번 시뮬레이션");

	 
			if(useapp==1){
			//pDC->Rectangle(750,50,900,250);
				MemDC.CreateCompatibleDC(pDC);
				MyBitmap.LoadBitmap(IDB_BITMAP2);
				pOldBitmap=MemDC.SelectObject(&MyBitmap);
				pDC->BitBlt(750,0,900,450,&MemDC,0,0,SRCCOPY);
				MemDC.SelectObject(pOldBitmap);

				pDC->TextOutA(785,100,"주변범죄자알리미");
				pDC->TextOutA(785,130,"  --반경50M범죄자--");
			user.spot.SetRect(user.pnt.x-100,user.pnt.y-100,user.pnt.x+110,user.pnt.y+110);
			pDC->Ellipse(user.spot);
			for(int j=0;j<7;j++){
					if(rgnEllipse.PtInRegion(Bum2_[j].pnt)){
						pDC->TextOutA(800,(160+(count*30)),Bum2_[j].name);
						count++;
					}
					}
				count=0;

			}
			else{
				//pDC->TextOutA(785,100,"스마트폰");
				//어플 종료시 출력 될 내용을 입력하세요.
			}
			
			
			 

			for(int j=0;j<7;j++){
				
				Bum2_[j].rt.SetRect(Bum2_[j].pnt.x,Bum2_[j].pnt.y,Bum2_[j].pnt.x+20,Bum2_[j].pnt.y+20);
				//pDC->Rectangle(Bum2_[j].rt); //시간재설정해야함 
				dc_bum[j].CreateCompatibleDC(pDC);
				nB_bum[j].LoadBitmap(IDB_BUM1a);
				oB_bum[j]=dc_bum[j].SelectObject(&nB_bum[j]);
				pDC->BitBlt(Bum2_[j].pnt.x,Bum2_[j].pnt.y,Bum2_[j].pnt.x+10,Bum2_[j].pnt.y+10, &dc_bum[j],0,0,SRCCOPY);

				oB_bum[j]=dc_bum[j].SelectObject(&nB_bum[j]);

			} 

			user.rt.SetRect(user.pnt.x,user.pnt.y,user.pnt.x+20,user.pnt.y+20);
			
				
				newB10.CreateSolidBrush(RGB(0,0,250));
				oldB10= pDC->SelectObject(&newB10);
				//pDC->Rectangle(user.rt);
					dc_bum1.CreateCompatibleDC(pDC);
					nB_bum1.LoadBitmap(IDB_USER);
					oB_bum1=dc_bum1.SelectObject(&nB_bum1);
					pDC->BitBlt(user.pnt.x,user.pnt.y,user.pnt.x+10,user.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
					dc_bum1.SelectObject(oB_bum1);

			    pDC->SelectObject(oldB10);
				
				
			break; 
		case 3://4번맵
			SetTimer(291,10,NULL);
			CString msg;
			pDC->TextOutA(200,0,"4번 시뮬레이션");
			 
			if(jail==TRUE){
				pDC->TextOutA(800,5,"※공개수배※");
			}

			if(vis_foot==TRUE){
			
				pDC->Rectangle(foot.x,foot.y,foot.x+10,foot.y+4);
			}

			
			MemDC1.CreateCompatibleDC(pDC);  //도로 차선 깔기
			newRoad.LoadBitmap(IDB_BITMAP3);
			oldRoad=MemDC1.SelectObject(&newRoad);
			pDC->BitBlt(0,375,1800,475,&MemDC1,0,0,SRCCOPY);
			MemDC1.SelectObject(oldRoad);



			// 테스트 출력	str.Format("car_Time : %d",foot.x);
			//			pDC->TextOutA(300,50,str);
			//pDC->Rectangle(house2); // house2.SetRect(600,150,700,250);
				nb_house.CreateSolidBrush(RGB(150,150,150));
			ob_house = pDC->SelectObject(&nb_house);
				pDC->Rectangle(house2); //집
			
			pDC->SelectObject(ob_house);
			Bum4_1.rt.SetRect(Bum4_1.pnt.x, Bum4_1.pnt.y, Bum4_1.pnt.x+20,Bum4_1.pnt.y+20);
			
			Pcar1.rt.SetRect(Pcar1.pnt.x,Pcar1.pnt.y,Pcar1.pnt.x+20,Pcar1.pnt.y+20);
			//pDC->Rectangle(Pcar1.rt);

			MemDC.CreateCompatibleDC(pDC);
			MyBitmap.LoadBitmap(IDB_BITMAP1);
			MyBitmap.GetBitmap(&MyInfo);
			pOldBitmap=MemDC.SelectObject(&MyBitmap);



			pDC->TransparentBlt(Pcar1.pnt.x,Pcar1.pnt.y, MyInfo.bmWidth, MyInfo.bmHeight,
                           &MemDC,  0, 0, MyInfo.bmWidth, MyInfo.bmHeight,
                           RGB(255,0,255));

			MemDC.SelectObject(pOldBitmap);

			Pol1.rt.SetRect(Pol1.pnt.x,Pol1.pnt.y,Pol1.pnt.x+20,Pol1.pnt.y+20);
			
			if(OUTPOLI==TRUE){
					dc_pol.CreateCompatibleDC(pDC);
					nB_pol.LoadBitmap(IDB_POLI);
					oB_pol=dc_pol.SelectObject(&nB_pol);
					pDC->BitBlt(Pol1.pnt.x,Pol1.pnt.y,Pol1.pnt.x+10,Pol1.pnt.y+10, &dc_pol,0,0,SRCCOPY);
					dc_pol.SelectObject(oB_pol);
			}
				//pDC->Rectangle(Pol1.rt);
			//pDC->Rectangle(Bum4_1.rt);
			if(bumclick==0){
					dc_bum1.CreateCompatibleDC(pDC);
					nB_bum1.LoadBitmap(IDB_BUM1a);
					oB_bum1=dc_bum1.SelectObject(&nB_bum1);
					pDC->BitBlt(Bum4_1.pnt.x,Bum4_1.pnt.y,Bum4_1.pnt.x+10,Bum4_1.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
					dc_bum1.SelectObject(oB_bum1);}
			if(bumclick==41){  //범인 클릭하면
				//pDC->Rectangle(Bum.rt);
				dc_bum1.CreateCompatibleDC(pDC);
				nB_bum1.LoadBitmap(IDB_BUM1b);
				oB_bum1=dc_bum1.SelectObject(&nB_bum1);
				pDC->BitBlt(Bum4_1.pnt.x,Bum4_1.pnt.y,Bum4_1.pnt.x+10,Bum4_1.pnt.y+10, &dc_bum1,0,0,SRCCOPY);
				dc_bum1.SelectObject(oB_bum1);
			}


			SetTimer(201, 10, NULL);
			if(moving>100){
				if(POLICE==FALSE){
					if(text_sec>100){
						SetTimer(202,10,NULL);
						msg.Format("이상 징후 발견 %d 초 안에 다른위치로 이동바람",movsec);
						m_dlg2->SetDlgItemText(IDC_MSG,msg);
						text_sec=0;
					}
				}
				if(movsec==0){
						
						msg.Format("경찰출동!");
						m_dlg2->SetDlgItemText(IDC_MSG,msg);
						SetTimer(290,10,NULL);
						POLICE=TRUE;
					
				}
			 
			}


			else 	m_dlg2->SetDlgItemText(IDC_MSG," ");
					
			nB_car[0].LoadBitmap(IDB_CAr0);
			nB_car[0].GetBitmap(&CarInfo[0]);
			nB_car[1].LoadBitmap(IDB_CAR1);
			nB_car[1].GetBitmap(&CarInfo[1]);
			nB_car[2].LoadBitmap(IDB_CAR2);
			nB_car[2].GetBitmap(&CarInfo[2]);
			nB_car[3].LoadBitmap(IDB_CAR3);
			nB_car[3].GetBitmap(&CarInfo[3]);
			nB_car[4].LoadBitmap(IDB_CAR4);
			nB_car[4].GetBitmap(&CarInfo[4]);
			nB_car[5].LoadBitmap(IDB_CAR5);
			nB_car[5].GetBitmap(&CarInfo[5]);
			nB_car[6].LoadBitmap(IDB_CAR6);
			nB_car[6].GetBitmap(&CarInfo[6]);

			for(int j=0;j<30;j++){ //자동차 대 수
				Car2[j].rt.SetRect(Car2[j].pnt.x,Car2[j].pnt.y,Car2[j].pnt.x+30,Car2[j].pnt.y+20);
			 
				//pDC->Rectangle(Car[j].rt);
				
				dc_car[j].CreateCompatibleDC(pDC);
				 
				oB_car[j]=dc_car[j].SelectObject(&nB_car[j]);
				pDC->TransparentBlt(Car2[j].pnt.x,Car2[j].pnt.y, CarInfo[j].bmWidth, CarInfo[j].bmHeight,
                           &dc_car[j],  0, 0, CarInfo[j].bmWidth, CarInfo[j].bmHeight,
                           RGB(255,0,255));
				
				dc_car[j].SelectObject(oB_car[j]);

			}

			break;
		}
	}

	void CMy1121Pro2View::DrawImage(CDC *pDC)
	{
		// 모든 맵에 그리기 동작을 수행함.


		map[0].SetRect(0,0,50,50);
		map[1].SetRect(0,50,50,100);
		map[2].SetRect(50,0,100,50);
		map[3].SetRect(50,50,100,100);
		pDC->Rectangle(map[0]);
		pDC->Rectangle(map[1]);
		pDC->Rectangle(map[2]);
		pDC->Rectangle(map[3]);
		
		
	

		DrawMonitor(pDC); // 분기별로 그리기 수행



	}



	// CMy1121Pro2View 그리기

	void CMy1121Pro2View::OnDraw(CDC* pDC)
	{
		CMy1121Pro2Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		
		
		CRect rect;
		GetClientRect(&rect);

		// 메모리 DC 선언
		CDC memDC;
		CBitmap *pOldBitmap, bitmap;

		// 화면 DC와 호환되는 메모리 DC 객체를 생성
		memDC.CreateCompatibleDC(pDC);

		// 마찬가지로 화면 DC와 호환되는 Bitmap 생성
		bitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());

		pOldBitmap = memDC.SelectObject(&bitmap);
		memDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS); // 흰색으로 초기화

		// 메모리 DC에 그리기
		DrawImage(&memDC);

		// 메모리 DC를 화면 DC에 고속 복사
		pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		memDC.SelectObject(pOldBitmap);
		memDC.DeleteDC();
		bitmap.DeleteObject();



	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.




	void CMy1121Pro2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
	{
		ClientToScreen(&point);
		OnContextMenu(this, point);
	}

	void CMy1121Pro2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
	{
#ifndef SHARED_HANDLERS
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
	}


	// CMy1121Pro2View 진단

#ifdef _DEBUG
	void CMy1121Pro2View::AssertValid() const
	{
		CView::AssertValid();
	}

	void CMy1121Pro2View::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CMy1121Pro2Doc* CMy1121Pro2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1121Pro2Doc)));
		return (CMy1121Pro2Doc*)m_pDocument;
	}
#endif //_DEBUG


	// CMy1121Pro2View 메시지 처리기


	void CMy1121Pro2View::OnTimer(UINT_PTR nIDEvent)
	{ 
	
		text_sec++;

		if(nIDEvent==203){ // 맵 2번의 타이머
			for(UINT car=0; car<j; car++){
				if((Bum1.rt.PtInRect(Car1[car].pnt))){
					 while(!(Bum1.rt.PtInRect(Car1[car].pnt))){
							Car1[car].pnt.x++; 
							Car1[car+1].pnt.x+=10; 
							isCar=1;
							
					 }
				}
				else if(!(Bum1.rt.PtInRect(Car1[car].pnt))){ /// 수정ㅈ우 12-03일 
					if(!(Car1[car].rt.PtInRect(Car1[car+1].pnt)))
						Car1[car].pnt.x--;
					else {
						while(!(Car1[car].rt.PtInRect(Car1[car+1].pnt)))
							Car1[car+1].pnt.x=+10;
					}
					  

						//}
				 }

			}
			car_Time1++;
			if(car_Time1>1300){
				j++;
				car_Time1=rand()%(900)+1;
			}

			
		}


		if(nIDEvent==201){
			if(movsec==0)
				ck=2;
			if(!(house2.PtInRect(Bum4_1.pnt))){
				if(POLICE==FALSE)
					moving++;

			}
			if(movcnt==60){
				movsec--;
				movcnt=0;
			}
		}
		if(nIDEvent==202)
			movcnt++;
		if(moving==100){
			movsec=10;
		}
		if(movsec==0){
			KillTimer(201);KillTimer(202);}

				if(nIDEvent==20){

					for(int j=0; j<7;j++){ 
						(Bum2_[j].pnt.x)=Bum2_[j].randmove(Bum2_[j].pnt.x);  // 랜덤움직이게
						(Bum2_[j].pnt.y)=Bum2_[j].randmovey(Bum2_[j].pnt.y); //settime 이부분만 재설정해야해
					}
				}


		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		if(nIDEvent==11){
			// ck=1;  싸이렌
			sec=1;
			w_cnt--;

			if(w_cnt<=0)
				ck=2;
		}

		 
		if(nIDEvent==290){
			movsec=0; // 시간 조절
			 
			 

			if(!(vis_foot==TRUE)){
				if(movsec==0 &&(Bum4_1.pnt.x>=Pcar1.pnt.x+10)) {
					Pcar1.pnt.x+=2;
						Pol1.pnt.x=Pcar1.pnt.x;
						Pol1.pnt.y=Pcar1.pnt.y;
				}
				else{
					if(!(Bum4_1.pnt.y==Pol1.pnt.y)){
						Pol1.pnt.y--;
						OUTPOLI=TRUE;
					}

					else{
						if(!(Pol1.pnt.y==Pcar1.pnt.y)){
							
							Pol1.pnt.y++;
							Bum4_1.pnt.y++;
						}
						else{
							Pol1.pnt.x=-100;
							Bum4_1.pnt.x=-100;
							Pcar1.pnt.x+=2;
						}
					}
				}
				 if(Pcar1.pnt.x>1300)
					 KillTimer(290);
				}
			else{
				if(movsec==0 &&(foot.x>=Pcar1.pnt.x+10)) {
					
					Pcar1.pnt.x+=2;
						Pol1.pnt.x=Pcar1.pnt.x;
						Pol1.pnt.y=Pcar1.pnt.y;
				}
				else{
					if(!(foot.y==Pol1.pnt.y)){
						Pol1.pnt.y--;
						OUTPOLI=TRUE;
					}

					else{
						if(!(Pol1.pnt.y==Pcar1.pnt.y)){
							jail=TRUE;
							Pol1.pnt.y++;
							foot.y++;

						}
						else{
							Pol1.pnt.x=-100;
							foot.x=-100;
							Pcar1.pnt.x+=2;
						}
					}
				}
				 if(Pcar1.pnt.x>1300)
					 KillTimer(290);
				}
			
		}

		if(nIDEvent==301){
			w_cnt1=0; // 시간 조절
			 
			if(w_cnt1<=0 &&(Bum1.pnt.x>=Pcar2.pnt.x+10)) {
				Pcar2.pnt.x+=2;
					Pol2.pnt.x=Pcar2.pnt.x;
					Pol2.pnt.y=Pcar2.pnt.y;
			}
			else{
				if(!(Bum1.pnt.y==Pol2.pnt.y)){
					Pol2.pnt.y++;
					OUTPOLI2=TRUE;
				}

				else{
					if(!(Pol2.pnt.y==Pcar2.pnt.y)){
						Pol2.pnt.y--;
						Bum1.pnt.y--;
					}
					else{
						Pol2.pnt.x=-100;
						Bum1.pnt.x=-100;
						Pcar2.pnt.x+=2;
					}
				} 
			}
		}

		if(nIDEvent==10){
			//if(Bum.pnt.x>Pcar.pnt.x+10) { //범인의 x가 폴리스카의 x보다 크면
			if((house.PtInRect(Bum.pnt))){
				SetTimer(11,1000,NULL);
				w_cnt=(3) +1; // 경고 카운트 괄호 안에 초 입력
			}
			if(w_cnt<=0 && !(house.PtInRect(Bum.pnt))&&(Bum.pnt.x>Pcar.pnt.x+10)) 
				//경고가 0초면서 집에 범인이 없고 범인이 차보다오른쪽이면
				Pcar.pnt.x+=2;
			if(Aincar==TRUE){ //모두 차에 탑승했으면
				Pcar.pnt.x+=2;
			}


			if(Pcar.pnt.x==10||Pcar.pnt.x==11){
				Bum.warn++;//경고추가
					if(Bum.warn>1){
						Bum.sin=Bum.warn+Bum.sin-1;
						}
		
			}
			if(Pcar2.pnt.x==10||Pcar2.pnt.x==11){
				Bum1.warn++;
				if(Bum1.warn>1){
					Bum1.sin=Bum1.warn+Bum1.sin-1;
				}

			}

			//else if(Bum.pnt.x>x)
			//x--;
			//MessageBox("2번");
			if(ck==1){
				if(w_cnt>=1)
					PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE3), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC );  
				//PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP ); 
				ck=0;
			}
			if(ck==2){
				PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC );  
				//PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP ); 
				ck=0;
			}
			if(ck==3){
				PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_ASYNC | SND_RESOURCE | SND_SYNC );  
				//PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP ); 
				ck=0;
			}

			if(police==TRUE){  //폴리스가 출동했으면 
				if(!(Pol.pnt.y==Bum.pnt.y)){ //폴리스의 y가 범인의 y랑 같지 않으면
					if(incar==false)  //차안에 들어가지 않았으면
						if(Pol.pnt.y<Bum.pnt.y) // 폴리스가 범인보다 위에 있을경우 
							Pol.pnt.y++; // 폴리스는 아래로 간다.
						else{
							isUP=true; // 폴리스가 위로 간걸 체크
							Pol.pnt.y--; // 폴리스는 위로 간다.
						}
					else { // 범인이 차안에 들어갔으면                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
						if(isUP==false) 
							Bum.pnt=-50;
						Pol.pnt=-50;
						Aincar=true;

					}

				}
				else { //폴리스의 y가 범인의 y랑 같으면
					stop=true; // 동작금지(키작동불가)

					if(isUP==false){
						if(!(Pol.pnt.y==Pcar.pnt.y)){ //폴리스와 폴리스카가 동일 y값이 아니면
							if(Pol.pnt.y>Pcar.pnt.y+20){ // 폴리스가 폴리스카보다 위에 있을경우
								if(!(Pol.pnt.x<=Bum.pnt.x)){ // 폴리스가 범인보다 오른쪽에 있을 경우
									Pol.pnt.y--;  // 폴리스를 위로 올라가게
									Bum.pnt.y--;  // 범인도 위로 올라가게
								}else{ // 폴리스가 범인보다 왼쪽에 있을 경우

									Pol.pnt.x++;
								}
							}else {
								Bum.pnt=-50;
								incar = true;
							}
						}
					}else{
						if(!(Pol.pnt.y==Pcar.pnt.y)){ //폴리스와 폴리스카가 동일 y값이 아니면
							if(Pol.pnt.y<Pcar.pnt.y-15){
								Pol.pnt.y++;  // 폴리스를 아래로 내려가게
								Bum.pnt.y++;  // 범인도 아래로 올라가게
							}else {
								Bum.pnt=-50;
								incar = true;
							}
						}
					}
				}
				//Pcar.pnt.x++;
				//police=0;
			}
			if(cnt==10){ //컬러를 바꾼다.
				if(m_color==RGB(255,0,0))
					m_color=RGB(0,0,255);
				else m_color=RGB(255,0,0);
				cnt=0;
			}
			cnt++; //컬러를 바꾸기 위한 카운트;
			//Invalidate();
			//Invalidate();
		}

		if(nIDEvent==9){ //onInitialUpdate시 실행되는 타이머 1초에 한번 실행


			// if(!(c_pnt.x-15==Bum.pnt.x))  // 차, 범인 충돌방지
			for(k=0; k<i; k++)
				Car[k].pnt.x--;
			car_Time++;
			if(car_Time>1300){ // 차 간격 조절
				i++;
				car_Time=rand()%(900)+1;
			}
			Invalidate(FALSE);

		}

		if(nIDEvent==99){
			// ck=1;  싸이렌
			sec=1;
			w_cnt--;

			if(w_cnt<=0)
				ck=2;
		}
		if(nIDEvent==98){
			// ck=1;  싸이렌
			sec1=1;
			if(w_cnt_sec>50){
				w_cnt1--;
				w_cnt_sec=0;
			}

			

			if(w_cnt1<=0){
				KillTimer(98);
				ck=3;

			}
		}


		if(school.PtInRect(Bum1.pnt)){
			sec1=1;
			if(!(w_cnt1<=0)){
				SetTimer(98,10,NULL);
				w_cnt_sec++;
			}
			//w_cnt1=(3) +1; // 경고 카운트 괄호 안에 초 입력
		}

		
		  	if(nIDEvent==291){
				for(UINT car2=0; car2<c; car2++){
					Car2[car2].pnt.x--;
				}
				car_Time2++;
				if(car_Time2>1300){
					c++;
					car_Time2=rand()%(900)+1;
				}

			}

			
		if(nIDEvent==292){
			w_timer++;
			w_cnt_ck=TRUE;
			w_cnt1--;

			
		}

		CView::OnTimer(nIDEvent);
	}


	void CMy1121Pro2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


		CView::OnChar(nChar, nRepCnt, nFlags);
	}


	void CMy1121Pro2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		//범인 클릭했을경우에만 움직일수있다
		
			switch(monitor){
			case 0:
				if(stop==false){
				if(bumclick==1){
					switch(nChar){
					case VK_LEFT:
						Bum.pnt.x-=2;
						break;
					case VK_RIGHT:
						Bum.pnt.x+=2;
						break;
					case VK_DOWN:
						Bum.pnt.y+=2;
						break;
					case VK_UP:
						Bum.pnt.y-=2;
						break;
					}
					break;}
				}

			case 1:
				if(bumclick==2){
					if(OUTPOLI2==FALSE){
						switch(nChar){
						case VK_LEFT:
							Bum1.pnt.x-=14;
							break;
						case VK_RIGHT:
							Bum1.pnt.x+=14;
							break;
						case VK_DOWN:
							Bum1.pnt.y+=14;
							break;
						case VK_UP:
							Bum1.pnt.y-=14;
							break;} 
						break;
					}
				}
			case 2:
				if(userclick==1){
					switch(nChar){
					case VK_LEFT:
						user.pnt.x-=4;
						break;
					case VK_RIGHT:
						user.pnt.x+=4;
						break;
					case VK_DOWN:
						user.pnt.y+=4;
						break;
					case VK_UP:
						user.pnt.y-=4;
						break;}}
					break;
				
				case 3:
				 if(bumclick==41){
					 if(OUTPOLI==TRUE && jail==TRUE || OUTPOLI==FALSE){
						switch(nChar){
						case VK_LEFT:
							Bum4_1.pnt.x-=4;
							 
								moving=0;
							break;
						case VK_RIGHT:
							Bum4_1.pnt.x+=4;
							 
								moving=0;
							break;
						case VK_DOWN:
							Bum4_1.pnt.y+=4;
						 
								moving=0;
							break;
						case VK_UP:
							Bum4_1.pnt.y-=4;
							 
								moving=0;
							break;}
					 }
				 }

				
			}
			//	}
			  
			CView::OnKeyDown(nChar, nRepCnt, nFlags);
		}
	

	void CMy1121Pro2View::OnInitialUpdate()
	{
		CView::OnInitialUpdate();

		//PlaySound((LPCSTR)MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_ASYNC | SND_RESOURCE | SND_LOOP );  //시작 배경음
		foot.x=Bum4_1.pnt.x;
		foot.y=Bum4_1.pnt.y;
		
		SetTimer(9,10,NULL);

		SetTimer(20,500,NULL);
		// TODO: Add your specialized code here and/or call the base class
	}


	void CMy1121Pro2View::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		

		if(Bum.rt.PtInRect(point)){
			bumclick=1;
			Bum.bum_name.Format("%s",Bum.name);
			m_dlg->SetDlgItemText(IDC_name,Bum.bum_name);

			Bum.bum_sinname.Format("%s",Bum.sin_name);
			m_dlg->SetDlgItemText(IDC_TEXT2,Bum.bum_sinname);
			Bum.bum_age.Format("%d",Bum.age);
			m_dlg->SetDlgItemText(IDC_TEXT3,Bum.bum_age);
			Bum.bum_sin.Format("%d",Bum.sin);
			m_dlg->SetDlgItemText(IDC_TEXT4,Bum.bum_sin);
			Bum.bum_warn.Format("%d",Bum.warn);
			m_dlg->SetDlgItemText(IDC_TEXT5,Bum.bum_warn);
			
		}
		if(Bum1.rt.PtInRect(point)){
			bumclick=2;
			Bum1.bum_name.Format("%s",Bum1.name);
			m_dlg->SetDlgItemText(IDC_name,Bum1.bum_name);

			Bum1.bum_sinname.Format("%s",Bum1.sin_name);
			m_dlg->SetDlgItemText(IDC_TEXT2,Bum1.bum_sinname);
			Bum1.bum_age.Format("%d",Bum1.age);
			m_dlg->SetDlgItemText(IDC_TEXT3,Bum1.bum_age);
			Bum1.bum_sin.Format("%d",Bum1.sin);
			m_dlg->SetDlgItemText(IDC_TEXT4,Bum1.bum_sin);
			Bum1.bum_warn.Format("%d",Bum1.warn);
			m_dlg->SetDlgItemText(IDC_TEXT5,Bum1.bum_warn);
		}

		if(Bum4_1.rt.PtInRect(point)){
			bumclick=41;
			
			Bum4_1.bum_name.Format("%s",Bum4_1.name);
			m_dlg->SetDlgItemText(IDC_name,Bum4_1.bum_name);

			
			Bum4_1.bum_sinname.Format("%s",Bum4_1.sin_name);
			m_dlg->SetDlgItemText(IDC_TEXT2,Bum4_1.bum_sinname);
			Bum4_1.bum_age.Format("%d",Bum4_1.age);
			m_dlg->SetDlgItemText(IDC_TEXT3,Bum4_1.bum_age);
			Bum4_1.bum_sin.Format("%d",Bum4_1.sin);
			m_dlg->SetDlgItemText(IDC_TEXT4,Bum4_1.bum_sin);
			Bum4_1.bum_warn.Format("%d",Bum4_1.warn);
			m_dlg->SetDlgItemText(IDC_TEXT5,Bum4_1.bum_warn);
		}

		if(!Bum.rt.PtInRect(point)&&!Bum1.rt.PtInRect(point)&&!Bum4_1.rt.PtInRect(point))
			bumclick=0;


		for(int selmap=0;selmap<4;selmap++){
			if(map[selmap].PtInRect(point)){
				monitor=selmap;
				 
				if(is_dlg2==1)
					m_dlg2->DestroyWindow();

				
				/*if(is_dlg3==1)
					m_dlg3->DestroyWindow();*/

				/* m_dlg->DestroyWindow();   // 맵마다 다른 모달리스를 주고 싶다면 
				m_dlg = new CSmartPhone;
				m_dlg->Create(IDD_DIALOG1);
				m_dlg->ShowWindow(SW_SHOW);
				m_dlg->MoveWindow(1030,0,300,500);  */

			}
		}
		
		//if(map[2].PtInRect(point)){ //3번 맵이 클릭 된다면
		//		
		//		is_dlg3=1;
		//		m_dlg3 = new apps; // 3번 맵의 모달리스를 주기
		//		m_dlg3->Create(IDD_DIALOG3);
		//		m_dlg3->ShowWindow(SW_SHOW);
		//		m_dlg3->MoveWindow(1030,510,210,190);  

		//	}


		if(map[3].PtInRect(point)){ //4번 맵이 클릭 된다면
				
				is_dlg2=1;
				m_dlg2 = new Cuserdlg; // 4번 맵의 모달리스를 주기
				m_dlg2->Create(IDD_DIALOG2);
				m_dlg2->ShowWindow(SW_SHOW);
				m_dlg2->MoveWindow(1030,510,210,190);  

			}
		for(int j=0;j<7;j++){
			if(Bum2_[j].rt.PtInRect(point)){
			//bumclick=3;
			Bum2_[j].bum_name.Format("%s",Bum2_[j].name);
			m_dlg->SetDlgItemText(IDC_name,Bum2_[j].bum_name);

			Bum2_[j].bum_sinname.Format("%s",Bum2_[j].sin_name);
			m_dlg->SetDlgItemText(IDC_TEXT2,Bum2_[j].bum_sinname);
			Bum2_[j].bum_age.Format("%d",Bum2_[j].age);
			m_dlg->SetDlgItemText(IDC_TEXT3,Bum2_[j].bum_age);
			Bum2_[j].bum_sin.Format("%d",Bum2_[j].sin);
			m_dlg->SetDlgItemText(IDC_TEXT4,Bum2_[j].bum_sin);
			Bum2_[j].bum_warn.Format("%d",Bum2_[j].warn);
			m_dlg->SetDlgItemText(IDC_TEXT5,Bum2_[j].bum_warn);
			}
		}

		 
		if(user.rt.PtInRect(point)){
			userclick=1;}
		if(!user.rt.PtInRect(point)){
			userclick=0;}
		CView::OnLButtonDown(nFlags, point);
	}


	void CMy1121Pro2View::OnReset()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		Init_map1();
		
	}


	void CMy1121Pro2View::OnMouseMove(UINT nFlags, CPoint point)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

		CView::OnMouseMove(nFlags, point);
	}


	


	void CMy1121Pro2View::OnUser()
	{
		//m_dlg2->DestroyWindow();

		m_dlg2 = new Cuserdlg;
		m_dlg2->Create(IDD_DIALOG2);
		m_dlg2->ShowWindow(SW_SHOW);
		m_dlg2->MoveWindow(1030,500,300,700);
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	}


	void CMy1121Pro2View::Onapp()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		useapp=1;
	}


	void CMy1121Pro2View::OnUpdateApp(CCmdUI *pCmdUI)
	{
		// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
		CMy1121Pro2Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pCmdUI->Enable(monitor==2);

	}


	void CMy1121Pro2View::Onendapp()
	{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		useapp=0;
	}


	void CMy1121Pro2View::OnUpdateEndapp(CCmdUI *pCmdUI)
	{
		// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
		CMy1121Pro2Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pCmdUI->Enable(useapp==1);

	}


	void CMy1121Pro2View::OnRemove()
	{
			foot.x=Bum4_1.pnt.x;
			foot.y=Bum4_1.pnt.y;
				
			vis_foot=TRUE;
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
	}


	void CMy1121Pro2View::OnUpdateRemove(CCmdUI *pCmdUI)
	{
		pCmdUI->Enable(monitor==3 && vis_foot==FALSE);

		// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	}
