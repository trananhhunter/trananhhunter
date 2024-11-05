#include <bits/stdc++.h>
using namespace std;

int cnt =0;

class Giangvien{
	private:
		string  ten,mon,ma;
	public:
		// static int cnt;
		Giangvien();
		friend istream& operator >> (istream&,Giangvien&);
		friend ostream& operator << (ostream&,Giangvien);
		string getTen(){
			return this->ten;
		}
		string getMon(){
			return this->mon;
		}
};

// Giangvien::cnt =0;

Giangvien::Giangvien(){
	ten = mon = ma ="";
}

string chuanhoa(string s){
	stringstream ss(s);
	string token,res = "";
	while(ss >> token){
		res += toupper(token[0]);
	}
	return res;
}

string chuanhoa2(string s){
	stringstream ss (s);
	string token,res = "";
	while( ss >> token){
		res = token;
	}
	return res;
}


istream& operator >> (istream& in,Giangvien& a){
	++cnt;
	string tmp = to_string(cnt);
	tmp = string(2 - tmp.size(),'0')+tmp;
	a.ma = "GV" + tmp;
	cout << "Ten : "; in.ignore();
	getline(in,a.ten);
	cout << "Mon : "; getline(in,a.mon);
	a.mon = chuanhoa(a.mon);
	return in;
}


ostream& operator << (ostream& out,Giangvien a){
	out << a.ma << " " << a.ten << " " << a.mon << endl;
	return out;
}

bool cmp(Giangvien a,Giangvien b){
	if(chuanhoa2(a.getTen()) != chuanhoa2(b.getTen())) return chuanhoa2(a.getTen()) < chuanhoa2(b.getTen());
	return a.getMon() < b.getMon();
}


int main(){
	int n; cin >> n;
	Giangvien a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout << a[i];
}




