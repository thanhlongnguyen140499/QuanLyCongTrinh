#pragma once
#include<iostream>
#include<string>
using namespace std;

class LopCongTrinhKHoaHoc
{
public:
	LopCongTrinhKHoaHoc();
	~LopCongTrinhKHoaHoc();

	string MaCongTrinh;
	int NamXuatBan;
	bool KhuVucXuatBan;
public:
	friend istream& operator >> (istream& i, LopCongTrinhKHoaHoc& p);
	friend ostream& operator<<(ostream& o, const LopCongTrinhKHoaHoc &p);
};

