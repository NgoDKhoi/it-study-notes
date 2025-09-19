#include <iostream>
#include <string>
using namespace std;

class GiaoDich_BDS {
	protected:
		string Ma_GD;
		int Ngay_GD, Thang_GD, Nam_GD;
		int iDon_Gia, iDien_Tich;
		long lTien;
	public:
		virtual void Nhap() {
			cout << endl;
			cout << "Nhap ma giao dich: ";
			cin.ignore();
			getline(cin,Ma_GD);
			cout << "Nhap ngay giao dich: "; cin >> Ngay_GD >> Thang_GD >> Nam_GD;
			while(KiemTraNgay()) {
				cout << "Dinh dang ngay ban nhap KHONG HOP LE, vui long nhap lai!!" << endl;
				cout << "Nhap ngay giao dich: "; cin >> Ngay_GD >> Thang_GD >> Nam_GD;
			}
			cout << "Nhap don gia: "; cin >> iDon_Gia;
			cout << "Nhap dien tich: "; cin >> iDien_Tich;
			lTien= TinhTien();
		}
		virtual void Xuat() {
			cout << "Ma giao dich: " << Ma_GD << endl;
			cout << "Ngay giao dich: " << Ngay_GD << "/"<< Thang_GD << "/" << Nam_GD << endl;
			cout << "Don gia: " << iDon_Gia << endl;
			cout << "Dien tich: " << iDien_Tich << endl;
		}
		virtual long TinhTien() =0;
		virtual int Loai_GD() =0;
		long get_lTien() {	return lTien; }
		bool KiemTraNgay() {
			int SoNgayTrongThang;
			switch (Thang_GD) {
				case 4: case 6: case 9: case 11:
					SoNgayTrongThang= 30;
					break;
				case 2:
					SoNgayTrongThang= (Nam_GD % 4 == 0 && Nam_GD % 100 != 0) || (Nam_GD % 400 == 0) ? 29 : 28;
					break;
				default:
					SoNgayTrongThang= 31;
			}
			if (Ngay_GD < 1 || Ngay_GD > SoNgayTrongThang) return true;
			return false;
		}
		bool ds_Ngay(int iNgay, int iThang, int iNam) { // vd: Tham so truyen vao iNgay la 0 => ko quan tam ngay bao nhieu (tuong tu voi nam va thang)
			bool flag= true;
			if ((Ngay_GD != iNgay) && (iNgay != 0)) flag= false;
			if ((Thang_GD != iThang) && (iThang != 0)) flag= false;
			if ((Nam_GD != iNam) && (iNam != 0)) flag= false;
			return flag;
		}
};

class GD_Dat : public GiaoDich_BDS {
	private:	
		char cLoai_Dat;
	public:
		void Nhap() override  {
			GiaoDich_BDS::Nhap();
			cout << "Nhap loai dat: ";
			cin >> cLoai_Dat;
		}
		void Xuat() override  {
			cout << endl;
			GiaoDich_BDS::Xuat();
			cout << "Loai dat: " << cLoai_Dat << endl;
			cout << "Thanh tien: " << lTien << endl;
		}
		long TinhTien() override {
			if (cLoai_Dat == 'A') {
				return iDien_Tich*iDon_Gia*1.5;
			}
			else {
				 return iDien_Tich*iDon_Gia;
		    }
		}
		int Loai_GD() override { return 1;}
};

class GD_NhaPho : public GiaoDich_BDS {
	private:
		string Loai_Nha,Dia_Chi;
	public:
		void Nhap() override  {
			GiaoDich_BDS::Nhap();
			cout << "Nhap loai nha: ";
			cin.ignore();
			getline(cin,Loai_Nha);
			cout << "Nhap dia chi: ";
			getline(cin,Dia_Chi);
		}
		void Xuat() override {
			cout << endl;
			GiaoDich_BDS::Xuat();
			cout << "Loai nha: " << Loai_Nha << endl;
			cout << "Dia chi: " << Dia_Chi << endl;
			cout << "Thanh tien: " << lTien << endl;
		}
		long TinhTien() override {
			if (Loai_Nha=="CaoCap") return iDien_Tich*iDon_Gia;
			else return iDien_Tich*iDon_Gia*0.9;
		}
		int Loai_GD() override { return 2;}
};

class GD_ChungCu : public GiaoDich_BDS {
	private:
		string Ma_Can;
		int iViTri_Tang;
	public:
		void Nhap() override  {
			GiaoDich_BDS::Nhap();
			cin.ignore();
			cout << "Nhap ma can: ";
			getline(cin,Ma_Can);
			cout << "Nhap vi tri tang: ";
			cin >> iViTri_Tang;
		}
		void Xuat() override  {
			cout << endl;
			GiaoDich_BDS::Xuat();
			cout << "Ma can: " << Ma_Can << endl;
			cout << "Vi tri tang: " << iViTri_Tang << endl;
			cout << "Thanh tien: " << lTien << endl;
		}
		long TinhTien() override {
			if (iViTri_Tang==1) return iDien_Tich*iDon_Gia*2;
			else {
				if (iViTri_Tang>15) return iDien_Tich*iDon_Gia*1.2;
				else return iDien_Tich*iDon_Gia;
			}
		}
		int Loai_GD() override { return 3;}
};

int main () {
	GiaoDich_BDS *a[100];
	int iLuaChon, i= -1;
	
	// Yeu cau 1
	do {
		i += 1;
		cout << "**Hay chon loai giao dich cua ban**" << endl;
		cout << "1. Giao dich dat" << endl;
		cout << "2. Giao dich nha pho" << endl;
		cout << "3. Giao dich chung cu" << endl;
		cout << "Lua chon cua ban la: "; cin >> iLuaChon;
		system("cls");
		switch(iLuaChon) {
			case 1:
				a[i] = new GD_Dat();
				break;
			case 2:	
		        a[i] = new GD_NhaPho();
		        break;
			case 3:
 		    	a[i] = new GD_ChungCu();
 		    	break;
  			default:
			  	cout << "Lua chon cua ban khong hop le !!!" << endl;	
				  i--;	  
		}
		a[i]->Nhap();
		cout << "Ban co tiep tuc nhap giao dich khong ? " << endl;
		cout << "0. Khong" << endl;
		cout << "1. Co" << endl;
		cout << "Lua chon cua ban la: "; cin >> iLuaChon;
	}
	while (iLuaChon);
	
	// Yeu cau 2
	int n1=0,n2=0,n3=0;
	for (int j=0; j<i+1; j++) {
		switch(a[j]->Loai_GD()) {
			case 1:
				n1 += 1; break;
			case 2:
				n2 += 1; break;
			case 3:
				n3 += 1; break;
		}
	}
	cout << endl << "- Tong so luong giao dich tung loai la:" << endl;
	cout << " + Dat: "  << n1 << endl;
	cout << " + Nha pho: "  << n2 << endl;
	cout << " + Chung cu: "  << n3 << endl;
	
	// Yeu cau 3
	long t3= 0; // tong tien cua giao dich loai 3
	for (int j=0; j<i+1; j++) {
		if (a[j]->Loai_GD()==3) t3 += a[j]->TinhTien();
	}
	cout << "- Trung binh thanh tien cua chung cu la: " << t3/n3 << endl;
	
	// Yeu cau 4
	long max2= 0; // max cua giao dich loai 2
	for (int j=0; j<i+1; j++) {
		if (a[j]->Loai_GD()==2) {
			long temp= a[j]->TinhTien();
			if (temp>max2) max2= temp; 
		}
	}
	cout << "- Giao dich nha pho co tri gia cao nhat: " <<  max2 << endl;
	
	// Yeu cau 5
	cout << "- Danh sach cac giao dich cua thang 12 nam 2024: " << endl;
	for (int j=0; j<i+1; j++) {
		if (a[j]->ds_Ngay(0,12,2024)) a[j]->Xuat();
	}
	
	
	// Giai phong bo nho
	for (int j=0; j<i+1; j++) {
		delete a[j];
	}
	
	return 0;
}
