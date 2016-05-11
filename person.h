#pragma once
class person
{
public:
	CRect rt;
	CRect spot;
	CPoint pnt;
	UINT age;
	CString name;
	
	
	person(void);
	~person(void);
	int randmove(int x);
	int randmovey(int y);
};

class bumin : public person{
public:
	UINT warn;
	UINT sin;
	CString sin_name;

	CString bum_name;
	CString bum_age;
	CString bum_sinname;
	CString bum_sin;
	CString bum_warn;
	CString bum_info;
	boolean info;
	boolean ck;
	bumin();


};


class police : public person{
public:
	police();
};
