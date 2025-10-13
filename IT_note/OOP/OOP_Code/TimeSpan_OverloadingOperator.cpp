#include <iostream>
#include <iomanip>
using namespace std;

class CTimeSpan {
	private:
		int iGio, iPhut, iGiay;	
	public:
	    CTimeSpan ChuanHoa_TimeSpan();
        int ToSecond_TimeSpan() const { return 3600*iGio + 60*iPhut + iGiay; }
		CTimeSpan(int iGio=0, int iPhut=0, int iGiay=0);
		
		void setGiay_TS(int a) {	iGiay = a;	}
		void setPhut_TS(int a) {	iPhut = a;	}
		void setGio_TS(int a) {	iGio = a;	}
		
		CTimeSpan operator+ (const CTimeSpan &b) const;
		CTimeSpan operator- (const CTimeSpan &b) const;	
		bool operator== (const CTimeSpan &b) const {	return (this->ToSecond_TimeSpan() == b.ToSecond_TimeSpan());	}
		bool operator!= (const CTimeSpan &b) const {	return (this->ToSecond_TimeSpan() != b.ToSecond_TimeSpan());	}
		bool operator< (const CTimeSpan &b) const {	return (this->ToSecond_TimeSpan() < b.ToSecond_TimeSpan());	}
		bool operator> (const CTimeSpan &b) const {	return (this->ToSecond_TimeSpan() > b.ToSecond_TimeSpan());	}
		bool operator<= (const CTimeSpan &b) const {	return !(*this > b);	}
		bool operator>= (const CTimeSpan &b) const {	return !(*this < b);	}
		
		
};

CTimeSpan CTimeSpan::ChuanHoa_TimeSpan() { // Chuc nang la xx:58:67 -> xx:59:07
    int iDau= 1;
	int tongGiay= this->ToSecond_TimeSpan();
    if (tongGiay < 0) {
    	tongGiay= -tongGiay;
    	iDau= -1;
	}
	
	iGio= tongGiay / 3600;
	tongGiay %= 3600;
	iPhut= tongGiay / 60;
	iGiay= tongGiay % 60;
	
	iGiay *= iDau;
	iPhut *= iDau;
	iGio *= iDau;
	
	return *this;
}

CTimeSpan::CTimeSpan(int iGio, int iPhut, int iGiay) { // Ham gan gia tri khi khoi tao
	this->iGio= iGio;
	this->iPhut= iPhut;
	this->iGiay= iGiay;
	this->ChuanHoa_TimeSpan();
}

CTimeSpan CTimeSpan::operator+ (const CTimeSpan &b) const { // Cong 2 khoang tgian
	CTimeSpan temp;
	temp.iGio= iGio + b.iGio;
	temp.iPhut= iPhut + b.iPhut;
	temp.iGiay= iGiay + b.iGiay;
	
	temp.ChuanHoa_TimeSpan();
	return temp;
}

CTimeSpan CTimeSpan::operator- (const CTimeSpan &b) const { // Tru 2 khoang tgian
	CTimeSpan temp;
	temp.setGiay_TS(this->ToSecond_TimeSpan() - b.ToSecond_TimeSpan());
	temp.setPhut_TS(0);
	temp.setGio_TS(0);
	temp.ChuanHoa_TimeSpan();
	return temp;
}

class CTime {
	private: 
		int iGio, iPhut, iGiay;
	public:
		CTime ChuanHoa_Time();
		int ToSecond_Time() const {	return 3600*iGio + 60*iPhut + iGiay;	}
		CTime(int iGio=0, int iPhut=0, int iGiay=0);
		
		void setGiay_T(int a) {	iGiay = a;	}
		void setPhut_T(int a) {	iPhut = a;	}
		void setGio_T(int a) {	iGio = a;	}
		
		friend istream& operator>> (istream &is, CTime &a);
		friend ostream& operator<< (ostream &os, const CTime &a);
		CTime& operator++();
		CTime& operator--();
		CTime operator++(int);
		CTime operator--(int);
		CTime operator+ (int b) const;
		CTime operator- (int b) const;
		
		CTimeSpan operator- (const CTime &b) const;
		CTime operator+ (const CTimeSpan &b) const;
};

CTime CTime::ChuanHoa_Time() {
	
	iPhut += iGiay / 60;
	iGiay %= 60;
	iGio += iPhut / 60;
	iPhut %= 60;
	
	while (iGio >= 24) iGio -= 24;
	return *this;
}

CTime::CTime(int iGio, int iPhut, int iGiay) { // Ham gan gia tri khi khoi tao
	this->iGio= iGio;
	this->iPhut= iPhut;
	this->iGiay= iGiay;
	this->ChuanHoa_Time();
}

istream& operator>> (istream &is, CTime &a) {
	cout << "Nhap gio: "; is >> a.iGio;
	cout << "Nhap phut: "; is >> a.iPhut;
	cout << "Nhap giay: "; is >> a.iGiay;
	a.ChuanHoa_Time();
	return is;
}

ostream& operator<< (ostream &os, const CTime &a) {
	os << setfill('0') << setw(2) << a.iGio << ":" << setw(2) << a.iPhut << ":"<< setw(2) << a.iGiay;
	return os;
}

CTime& CTime::operator++() { // Tang them 1 giay (++a)
	if (iGiay == 59) {
		iGiay = 0;
		if (iPhut == 59) {
			iPhut = 0;
			if (iGio == 23) iGio = 0;	
		}
		else iPhut += 1;
	}
	else iGiay += 1;
	return *this;
}

CTime& CTime::operator--() { // Tru di 1 giay (--a)
	if (iGiay == 0) {
		iGiay = 59;
		if (iPhut == 0) {
			iPhut = 59;
			if (iGio == 0) iGio= 23;
			else iGio -= 1;
		}
		else iPhut -= 1; 
	}
	else iGiay -= 1;
	return *this;
}

CTime CTime::operator++(int) { // Tang them 1 giay (a++)
	CTime temp = *this;
	++(*this);
	return temp;
}

CTime CTime::operator--(int) { // Tru di 1 giay (a--)
	CTime temp = *this;
	--(*this);
	return temp;
}

CTime CTime::operator+ (int b) const { // Cong them b giay
	CTime temp= *this;
	if (b<0) {
		b= -b;
		temp.iGiay = iGiay - b;
	}
	else temp.iGiay += b;
	
	temp.ChuanHoa_Time();
	return temp;
}

CTime CTime::operator- (int b) const { // Tru di b giay
	CTime temp= *this;
	if (b<0) {
		b= -b;
		temp.iGiay += b;
	}
	else {
		temp.iGiay -= b;
		while (temp.iGiay < 0) {
			temp.iGiay += 60;
			temp.iPhut -= 1;
			while (temp.iPhut < 0) {
				temp.iPhut += 60;
				temp.iGio -= 1;
				while (temp.iGio < 0) temp.iGio = 23;
			}
		}
	}
	return temp;
}

CTimeSpan CTime::operator- (const CTime &b) const { // Tinh khoang tgian khi tru 2 moc tgian
	CTimeSpan temp;	
	temp.setGiay_TS(this->ToSecond_Time() - b.ToSecond_Time());
	temp.setPhut_TS(0);
	temp.setGio_TS(0);
	temp.ChuanHoa_TimeSpan();
	return temp;
}

CTime CTime::operator+ (const CTimeSpan &b) const { // Tinh moc tgian khi cong moc tgian voi kohang tgian
	CTime temp;
	int tongGiay= b.ToSecond_TimeSpan();
	temp= (*this) + tongGiay;
	return temp;
}
 
int main() {
	CTime a,b(6,0,0);
	CTimeSpan c;
	cin >> a;
	a++;
	cout << a << " " << b;
	return 0;
}
