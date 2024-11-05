#include <bits/stdc++.h>
using namespace std;

class Sinhvien{
	private:
		string ma,ten,lop,email;
	public:
		Sinhvien(){
			ma = ten = lop = email ="" ;
		}
		friend istream& operator >> (istream&,Sinhvien&);
		friend ostream& operator << (ostream&,Sinhvien);
		bool operator < (Sinhvien a){
			return this->ma < a.ma;
		}
		string getLop(){
			return this->lop;
		}
};

istream& operator >> (istream& in,Sinhvien& a){
	cout << "Ma sv : "; in >> a.ma;
	cout << "Ten : "; in.ignore();
	getline(in,a.ten);
	cout << "Lop : "; in >> a.lop;
	cout << "Email : "; in >> a.email;
	return in;
}

ostream& operator << (ostream& out,Sinhvien a){
	cout << a.ma << " " << a.ten << " " << a.lop << " " << a.email << endl;
	return out;
}

int main(){
	int n; cin >> n;
	Sinhvien a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int q; cin >> q;
	while(q--){
		string s; cin >> s;
		cout << "Danh sach sinh vien lop " << s << endl;
		for(Sinhvien x : a){
			if(x.getLop() == s){
				cout << x << endl;
			}
		}
	}
	return 0;
}
