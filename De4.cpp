#include <bits/stdc++.h>
using namespace std;

class Khachhang{
	private:
		string hoten,masocongto;
	public:
		Khachhang(){
		}
		void nhap(){
			cout << "Nhap ho ten chu ho : "; getline(cin,hoten);
			cout << "Nhap ma so cong to : "; cin >> masocongto;
		}
		void in(){
			cout << "Ho ten : " << hoten << endl;
			cout << "Ma so cong to : " << masocongto << endl;
		}
};

class Bienlai : public Khachhang{
	private:
		int chiSoCu,chiSoMoi;
		double soTienPhaiTra;
	public:
		Bienlai(){
		}
		void nhapBienLai(){
			Khachhang::nhap();
			cout << "Chi so cu : "; cin >> chiSoCu;
			cout << "Chi so moi : "; cin >> chiSoMoi;
			soTienPhaiTra = (chiSoMoi - chiSoCu)*750;
			cin.ignore();
		}
		void inBienLai(){
			Khachhang::in();
			cout << "Chi so cu : " << chiSoCu << endl;
			cout << "Chi so moi : " << chiSoMoi << endl;
			cout << "So tien phai tra : " << fixed << setprecision(2) << soTienPhaiTra << endl;
		}
};


int main(){
	Bienlai a[100];
	int n;
	cout << "Nhap n so ho : "; cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cout << "Ho thu " << i + 1 << ":\n";
		a[i].nhapBienLai();
		cout << "Da them thanh cong \n";
	}
	for(int i=0;i<n;i++){
		cout << "Ho thu " << i + 1 << ":\n";
		a[i].inBienLai();
	}
}



