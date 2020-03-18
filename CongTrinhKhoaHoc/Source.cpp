#include<iostream>
#include "LopCongTrinhKHoaHoc.h"
#include<string>
#include"List.h"
using namespace std;
 
int main()
{
	cout << "\t\nTAO DOI TUONG CONG TRINH \n";
	List a;
	cin >> a;

	int chon;
	do
	{
		cout<<("          ======================MENU========================\n");
		cout<<("\t\t 1. Hien thi danh sach cong trinh\n");
		cout<<("\t\t 2. Them cong trinh\n");
		cout<<("\t\t 3. Cap nhat thong tin cong trinh\n");
		cout<<("\t\t 4. Xoa cong trinh\n");
		cout<<("\t\t 5. Tim cong trinh\n");
		cout<<("\t\t 6. Sap xep doi tuong cong trinh\n");
		cout<<("\t\t 7. XOA MAN HINH\n");
		cout<<("\t\t 8. KET THUC\n");
		cout<<("          ==================================================\n");
		cout<<("Ban chon: ");
		cin >> chon;
		switch(chon)
		{
		case 1:	
			cout << a;
			break;
		case 2:
			a.ThucThiThemDoiTuong();
			cout << "\n====>Ban da them cong trinh THANH CONG!!!\n";
			break;
		case 3:
			a.CapNhatDoiTuong();
			cout << "\n====>Ban da cap nhat cong trinh THANH CONG!!!\n";
			break;
		case 4:
			a.ThucThiXoaDoiTuong();
			cout << "\n====>Ban da xoa cong trinh THANH CONG!!!\n";
			break;
		case 5:
			cout << "\nTim Kiem theo thuoc tinh nam san xuat \n";
			a.TimKiemDoiTuong();
			break;
		case 6:
			cout << "\nSap xep theo thuoc tinh nam san xuat \n";
			a.ThucThiSapXep();
			break;
		case 7:
			system("cls");
			break;
		case 8:
			break;
		default:
			cout<<("====>Ban chon sai. Moi ban chon lai MENU!\n");
			break;
		}
	} while (chon != 8);

	system("pause");
	return 0;
}