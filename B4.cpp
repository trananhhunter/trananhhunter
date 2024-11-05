#include <bits/stdc++.h>
using namespace std;

class Sv{
	private:
		string ma,ten,lop,ns;
		double gpa;
	public:
		Sv(){
			ma = ten = lop = ns;
			gpa =0;
		}
		Sv(string ma,string ten,string lop, string ns, double gpa){
			this->ten = ten;
			this->lop = lop;
			this->ns = ns;
			this->gpa =gpa;
		}
		friend istream& operator >> (istream&, Sv&);
		friend ostream& operator << (ostream&,Sv);
};

istream& operator >> (istream& in, Sv& a){
	a.ma = "B20DCCN001";
	getline(in,a.ten);
	in >> a.lop >> a.ns >> a.gpa;
	if(a.ns[2] != '/') a.ns = "0" + a.ns;
	if(a.ns[5] != '/') a.ns.insert(3,"0");
	return in;
}

ostream& operator << (ostream& out,Sv a){
	out << a.ma << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed << setprecision(2) <<a.gpa << endl;
	return out;
}

#define a() a

int main(){
	Sv a();
	cin >> a;
	cout << a;
	return 0;
}
