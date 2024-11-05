#include <bits/stdc++.h>
using namespace std;

class Sinhvien{
	private:
		string ma,ten,ns;
		double gpa;
	public:
		Sinhvien(){
			ma = ten = ns = "";
			gpa = 0;
		}
		Sinhvien(string ma,string ten,string ns,double gpa){
			this->ten = ten;
			this->ns = ns;
			this->gpa = gpa;
		}
		friend void nhap(Sinhvien&);
		friend void in(Sinhvien);
};

void nhap(Sinhvien &a){
	a.ma = "B20DCCN001";
	getline(cin,a.ten);
	cin >> a.ns >> a.gpa;
	if(a.ns[2] != '/') a.ns = "0" + a.ns;
	if(a.ns[5] != '/') a.ns.insert(3,"0");
}

void in(Sinhvien a){
	cout << a.ma << " " << a.ten << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
}

#define a() a;

int main(){
	Sinhvien a();
	nhap(a);
	in(a);
	return 0;
}
