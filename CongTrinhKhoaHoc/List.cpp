#include "List.h"
#include"LopCongTrinhKHoaHoc.h"
#include<iostream>
#include<iomanip>
using namespace std;

List::List()
{
}
List::~List()
{
	delete[] this->congTrinh;
}
istream& operator>>(istream&i, List &p)
{
	cout << "Nhap so Cong Trinh : ";
	i>>p.soCongTrinh;
	p.congTrinh = new LopCongTrinhKHoaHoc[1000]; // vi khi them doi tuong , mang can tang so luong phan tu nen truyen truoc vao` 1000

	for (int i = 0; i <p.soCongTrinh; i++)
	{
		cout << "====================== \n";
		cout << "\n\tNhap CONG TRINH thu " << i + 1 << endl;

		LopCongTrinhKHoaHoc a;
		cin >> a;
		p.congTrinh[i] = a;
	}
	return i;
}
ostream& operator<<(ostream& o, const List &p)
{
	o << "\n======= HIEN THI CONG TRINH ("<<p.soCongTrinh<<" CONG TRINH) =======\n";
	for (int i = 0; i < p.soCongTrinh; i++)
			{
				//o << "====================== \n";
				o << "\nCONG TRINH thu " << i + 1;
				o << p.congTrinh[i] << endl;
			}
	return o;
}
LopCongTrinhKHoaHoc& List::operator[](const int i)
{
//	return (i < this->soCongTrinh && i >= 0) ? this->congTrinh[i] : LopCongTrinhKHoaHoc();
	return this->congTrinh[i];
}
void List::ThemDoiTuong(int k)
{
	
	cout << "\t\t\nNhap CONG TRINH can them \n";
	LopCongTrinhKHoaHoc a;
	cin >> a;

	for (int i = this->soCongTrinh; i > k; i--)
	{
		this->congTrinh[i] = this->congTrinh[i - 1];
	}
	this->congTrinh[k] = a;
	this->soCongTrinh++;
}
void List::ThucThiThemDoiTuong()
{
	cout << "\n\tNhap 1: Them vao vi tri dau tien\n";
	cout << "\tNhap 2: Them vao vi tri bat ky \n";
	cout << "\tNhap 3: Them vao vi tri cuoi cung \n";
	int kiemtra;
	do {
		cout << "ban chon : ";
		cin >> kiemtra;
	} while (kiemtra!=1 && kiemtra!=2 && kiemtra !=3);

	if (kiemtra == 1)
	{
		cout << "\nBan chon them vao vi tri dau tien\n";
		ThemDoiTuong(0);
	}
	else if (kiemtra==2)
	{
		cout << "\nBan chon them vao vi tri bat ky\n";
		int k;
		do {
			cout << "\t\t\t\nNhap vi tri can them :\n ";
			cin >> k;
		} while (k<=0 || k>=this->soCongTrinh);
		ThemDoiTuong(k);
	}
	else if(kiemtra==3)
	{
		cout << "\nBan chon them vao vi tri cuoi cung\n";
		ThemDoiTuong(this->soCongTrinh);
	}
}

void List::CapNhatDoiTuong()
{
	int k;
	do
	{
		cout << "\nNhap thu tu can Cap Nhat :";
		cin >> k;
	} while (k<1||k>this->soCongTrinh);
	cout << "\t\t\n Sau Khi CAP NHAT \n";
	LopCongTrinhKHoaHoc a;
	cin >> a;
	--k;
	this->congTrinh[k] = a;
}
void List::XoaDoiTuong(int k)
{
	if (this->soCongTrinh == 0) return;

	for (int i = k-1; i < this->soCongTrinh - 1; i++)
		this->congTrinh[i] = this->congTrinh[i + 1]; //Dịch các phần tử sang trái 1 vị trí
	this->soCongTrinh--; //Giảm số phần tử bớt 1
}
void List::ThucThiXoaDoiTuong()
{
	cout << "\n\tNhap 1: Xoa vi tri dau tien\n";
	cout << "\tNhap 2: Xoa vi tri bat ky \n";
	cout << "\tNhap 3: Xoa vi tri cuoi cung \n";
	int kiemtra;
	do {
		cout << "ban chon : ";
		cin >> kiemtra;
	} while (kiemtra != 1 && kiemtra != 2 && kiemtra != 3);

	if (kiemtra == 1)
	{
		cout << "\nBan chon xoa vi tri dau tien\n";
		XoaDoiTuong(0);
	}
	else if (kiemtra == 2)
	{
		cout << "\nBan chon xoa vi tri bat ky\n";
		int k;
		do {
			cout << "\t\t\t\nNhap vi tri can XOA :\n ";
			cin >> k;
		} while (k <= 0 || k >= this->soCongTrinh);
		XoaDoiTuong(k);
	}
	else if (kiemtra == 3)
	{
		cout << "\nBan chon xoa vi tri cuoi cung\n";
		XoaDoiTuong(this->soCongTrinh);
	}
}

void List::TimKiemDoiTuong()
{
	//this->SapXepDoiTuong(this->congTrinh, 0, this->soCongTrinh - 1);
	
	bool kiemtra=false;
	int x;
	cout << "\n      BINARY SEARCH \n";
	cout << "\nNam xuat ban can tim kiem :";
	cin >> x;

	int l=0, r,mid;
	r = this->soCongTrinh-1;
	while (l<=r)
	{
		mid = (l + r) / 2;
		if (this->congTrinh[mid].NamXuatBan == x )
		{
			kiemtra = true;
			break;
		}
		else if(this->congTrinh[mid].NamXuatBan>x)
		{
			r = mid - 1;
		}
		else 
		{
			l = mid + 1;
		}
	}
	if (kiemtra)
	{
		cout << "\n===>Da tim thay \n";
		cout << this->congTrinh[mid] << endl;
	}
	else
	{
		cout << "\n===>KHONG TIM THAY\n";
	}
}


//sap xep bang QUICKSORT
void List::SapXepDoiTuong(LopCongTrinhKHoaHoc *arr, int trai, int phai, bool(*controHamTrai)(int, int), bool(*controHamPhai)(int, int))
{
	if (trai < phai)
	{
		int i = trai;
		int j = phai;
		float chot;
		chot = arr[(trai + phai) / 2].NamXuatBan; //chon phan tu o giua lam chot
		while (i < j)
		{
			while (controHamTrai(arr[i].NamXuatBan,chot))
			{
				i++;
			}
			//while (arr[i].NamXuatBan < chot) i++;
			
			while (controHamPhai(arr[j].NamXuatBan, chot))
			{
				j--;
			}
			//while (arr[j].NamXuatBan > chot) j--;

			if (i <= j)
			{
				//hoanvi;
				LopCongTrinhKHoaHoc t;
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				i++;
				j--;
			}
		}
		SapXepDoiTuong(arr, trai, j,controHamTrai,controHamPhai);
		SapXepDoiTuong(arr, i, phai,controHamTrai,controHamPhai);
	}
}

bool soSanhBeHon(int a, int b)
{
	return a < b;
}
bool soSanhLonHon(int a, int b)
{
	return a > b;
}

void List::ThucThiSapXep()
{
	cout << "\nNhap 1 : Sap xep tang dan \n";
	cout << "\nNhap 2 : Sap xep giam dan \n";
	int kiemtra;
	do
	{
		cout << "Ban chon :";
		cin >> kiemtra;
	} while (kiemtra != 1 && kiemtra != 2);
	if (kiemtra == 1)
	{
		this->SapXepDoiTuong(this->congTrinh, 0, this->soCongTrinh - 1, soSanhBeHon, soSanhLonHon);
	}
	else if (kiemtra == 2)
	{
		this->SapXepDoiTuong(this->congTrinh, 0, this->soCongTrinh - 1, soSanhLonHon, soSanhBeHon);
	}
	cout << "\n==>Ban da sap xep cac cong trinh THANH CONG!!!\n" << endl;
}
