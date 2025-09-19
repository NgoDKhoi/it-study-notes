#include <iostream>
#include <string>
using namespace std;

class KiHieu {
	protected:
		float fTruongDo;
	public:
		virtual void Nhap() {
			int iChoose=0;
			cout << endl << "Truong do cua ky hieu nay la: " << endl;
			cout << "1. 4" << endl;
			cout << "2. 2" << endl;
			cout << "3. 1" << endl;
			cout << "4. 1/2" << endl;
			cout << "5. 1/4" << endl;
			cout << "6. 1/8" << endl;
			cout << "7. 1/16" << endl;
			cout << "Lua chon cua ban la: "; cin >> iChoose;
			
			switch(iChoose) {
				case 1: fTruongDo= 4; break;
				case 2: fTruongDo= 2; break;
				case 3: fTruongDo= 1; break;
				case 4: fTruongDo= 0.5; break;
				case 5: fTruongDo= 0.25; break;
				case 6: fTruongDo= 0.125; break;
				case 7: fTruongDo= 0.0625; break;
				default:
					cout << "Lua chon cua ban khong hop le !!";
			}
		}
		
		virtual void Xuat() {
			if (fTruongDo<1) {
				cout << "1/" << 1/fTruongDo;
			}
			else cout << fTruongDo;
		}
		
		virtual bool LaDauLangDen() =0;
		
		virtual char LayCaoDo() =0;
};

class NotNhac : public KiHieu {
	private:
		char CaoDo;
	public:
		void Nhap() override {
			// Input cao do
			int iChoose=0;
			cout << "Cao do cua ky hieu nay la: " << endl;
			cout << "1. C" << endl;
			cout << "2. D" << endl;
			cout << "3. E" << endl;
			cout << "4. F" << endl;
			cout << "5. G" << endl;
			cout << "6. A" << endl;
			cout << "7. B" << endl;
			cout << "Lua chon cua ban la: "; cin >> iChoose;
	
			switch(iChoose) {
				case 1: CaoDo= 'C'; break;
				case 2: CaoDo= 'D'; break;
				case 3: CaoDo= 'E'; break;
				case 4: CaoDo= 'F'; break;
				case 5: CaoDo= 'G'; break;
				case 6: CaoDo= 'A'; break;
				case 7: CaoDo= 'B'; break;
				default:
					cout << "Lua chon cua ban khong hop le !!";
			}
			
			// Input truong do
            KiHieu::Nhap();
		}
		
		void Xuat() override {
			cout << CaoDo;
			KiHieu::Xuat();
		}
		
		bool LaDauLangDen() override { return false;}
		
		char LayCaoDo() { return CaoDo;}
};

class DauLang : public KiHieu {
	private:
	public:
		void Nhap() override {
			KiHieu::Nhap();
		}
		
		void Xuat() override {
			cout << 'Z';
			KiHieu::Xuat();
		}
		
		bool LaDauLangDen() override {
			if (fTruongDo==1) return true;
			else return false;
		}
		
		char LayCaoDo() override { return '\0';}
};

int main() {
	int n;
	cout << "So ki hieu trong ban nhac cua ban la: "; cin >> n;
	KiHieu *a[n];
	
	for (int i=0;i<n; i++) {
		int iChoose=0;
		cout << "\nKi hieu thu " << i+1 << " la:" << endl;
		cout << "1. Not nhac" << endl;
		cout << "2. Dau lang" << endl;
		cout << "-> Lua chon cua ban la: "; cin >> iChoose;
		switch(iChoose) {
			case 1:
				a[i]= new NotNhac();
				break;
			case 2:
				a[i]= new DauLang();
				break;
			default:
				cout << "Lua chon cua ban khong hop le !!";
		}
		a[i]->Nhap();
	}
	
	// Yeu cau 1
	cout << "\n*** BAN NHAC ***" << endl;
	for (int i=0; i<n; i++) {
		a[i]->Xuat();
		if (i != (n-1)) cout << " - ";
	}
	
	// Yeu cau 2
	int demDauLangDen =0;
	for (int i=0; i<n; i++) {
		demDauLangDen += a[i]->LaDauLangDen(); // Tu ep kieu bool sang int
	}
	cout << "\n\n- So dau lang den trong ban nhac la: " << demDauLangDen;
	
	// Yeu cau 3
	const char ds_CaoDo[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B'};
	bool flag= true;
	for (int k=6; k>=0 && flag; k--) {
		char XCaoDo= ds_CaoDo[k];
		for (int i=0; i<n; i++) {
			if (a[i]->LayCaoDo()==XCaoDo) {
				cout << "\n- Not nhac co cao do cao nhat la: ";
				a[i]->Xuat();
				flag= false;
				break;
			}
		}
	}
	if (flag) cout << "\n- Khong co not nhac trong ban nhac";
	
	for (int i=0; i<n; i++) {
		delete a[i];
	}
	
	return 0;
}



