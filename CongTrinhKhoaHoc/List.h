#pragma once
#include "LopCongTrinhKHoaHoc.h"
class List
{
	int soCongTrinh;
	LopCongTrinhKHoaHoc *congTrinh;
public:
	List();
	~List();
	friend ostream& operator<<(ostream &o, const List &p);
	friend istream& operator>>(istream &i, List &p);	
	LopCongTrinhKHoaHoc& operator[](const int);
	void ThemDoiTuong(int);
	void ThucThiThemDoiTuong();
	void CapNhatDoiTuong();
	void XoaDoiTuong(int a);
	void ThucThiXoaDoiTuong();
	void SapXepDoiTuong(LopCongTrinhKHoaHoc *arr,int ,int, bool(*comparisonFunc)(int, int), bool(*controHamPhai)(int, int));
	void ThucThiSapXep();
	void TimKiemDoiTuong();
	
};

