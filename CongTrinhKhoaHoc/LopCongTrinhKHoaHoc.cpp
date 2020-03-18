#include "LopCongTrinhKHoaHoc.h"
#include<iostream>
using namespace std;

istream& operator >> (istream& i, LopCongTrinhKHoaHoc & p)
{
	cout << "Nhap Ma Cong Trinh: ";
	i >> p.MaCongTrinh;
	do
	{
		cout << "Nhap Nam Xuat Ban >=1900  : ";
		i >> p.NamXuatBan;
	} while (p.NamXuatBan < 1900);
	cout << "Nhap Khu Vuc Xuat Ban :\n";
	do
	{
		cout << "\tnhap 1 : QuocTe";
		cout << "\n\tNhap 0: TrongNuoc";
		cout << "\n";
		i >> p.KhuVucXuatBan;
	} while (p.KhuVucXuatBan != 1 && p.KhuVucXuatBan != 0);
	return i;
}

ostream& operator<<(ostream& o, const LopCongTrinhKHoaHoc &p)
{
	cout << endl;
	cout << endl;
	cout << "Ma Cong Trinh: ";
	o << p.MaCongTrinh;
	cout << ", Nam Xuat Ban : ";
	o << p.NamXuatBan;
	cout << ", Khu Vuc Xuat Ban : ";
	if (p.KhuVucXuatBan == 1)
	{
		cout << "Quoc Te"<<endl;
	}
	else if(p.KhuVucXuatBan==0)
	{
		cout << "Trong Nuoc" << endl;
	}
	//o << p.KhuVucXuatBan;
	o << "\n";
	return o;
}

LopCongTrinhKHoaHoc::LopCongTrinhKHoaHoc()
{
}


LopCongTrinhKHoaHoc::~LopCongTrinhKHoaHoc()
{
}
