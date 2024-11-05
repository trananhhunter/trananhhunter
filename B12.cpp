#include <bits/stdc++.h>
using namespace std;

class Nhanvien{
	private:
		string ma,ten,gt,ns,dc,mst,hd;
	public:
		Nhanvien();
		friend istream& operator >> (istream&,Nhanvien&);
		friend ostream& operator << (ostream&,Nhanvien);
};

Nhanvien::Nhanvien(){
	ma = ten = gt = ns = dc = mst = hd = "";
}

istream& operator >> (istream& in,Nhanvien& a){
	a.ma = "00001";
	cout << "Ten : "; in.ignore();
	getline(in,a.ten);
	cout << "Gioi tinh : "; in >> a.gt;
	cout << "Ngay sinh : "; in >> a.ns;
	cin.ignore();
	cout << "Dia chi : "; getline(in,a.dc);
	cout << "Ma so thuc : "; in >> a.mst;
	cout << "Ngay ki hop dong : "; in >> a.hd;
	return in;
}

ostream& operator << (ostream& out,Nhanvien a){
	out << a.ma << " " << a.ten << " " << a.gt << " " << a.ns << " " << a.dc << " " << a.mst << " " << a.hd << endl;
	return out;
}

#define a() a

int main(){
	Nhanvien a();
	cin >> a;
	cout << a;
}
