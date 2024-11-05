#include <bits/stdc++.h>
using namespace std;

int cnt =0;

class Sinhvien{
	private:
		string ten,lop,ns;
		int ma;
		double gpa;
	public:
		Sinhvien();
		friend istream& operator >> (istream&,Sinhvien&);
		friend ostream& operator << (ostream&,Sinhvien);
		double getGpa();
		friend bool operator < (Sinhvien a,Sinhvien b){
			return a.gpa < b.gpa;
		}
};


Sinhvien::Sinhvien(){
	ten = lop = ns ="";
	ma = 0;
	gpa =0;
}

ostream& operator << (ostream& out,Sinhvien a){
	out << "B20DCCN" << setfill('0') << setw(3) << a.ma << " " << a.ten << " " << a.lop << " " <<  a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
	return out;
}


string chuanhoa(string s){
	stringstream ss(s);
	string token,res="";
	while(ss >> token){
		res += toupper(token[0]);
		for(int i=1;i<token.length();i++) res += tolower(token[i]);
		res +=" ";
	}
	res.erase(res.length()-1);
	return res;
}


istream& operator >> (istream& in,Sinhvien& a){
	++cnt;
	a.ma = cnt;
//	string tmp = to_string(cnt);
//	tmp = string(3-tmp.size(),'0') + tmp;
//	a.ma = "B20DCCN" + tmp;
	cout << "Ten : "; in.ignore();
	getline(in,a.ten);
	a.ten = chuanhoa(a.ten);
	cout << "Lop : "; in >> a.lop;
	cout << "Ngay sinh :"; in >> a.ns;
	cout << "Gpa : "; in >> a.gpa;
	if(a.ns[2] != '/') a.ns = "0" + a.ns;
	if(a.ns[5] != '/') a.ns.insert(3,"0");
	return in;
}

int main(){
	int n; cin >> n;
	Sinhvien a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++) cout << a[i];
}

