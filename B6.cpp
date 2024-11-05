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
	vector<Sinhvien> v;
	Sinhvien tmp;
	while(cin >> tmp){
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	for(auto x : v){
		cout << x << endl;
	}
	return 0;
}
