#include <bits/stdc++.h>
using namespace std;
int cnt =0;

class Nhanvien{
	private:
		string ten,gt,ns,dc,mst,hd;
		int ma;
	public:
		friend istream& operator >> (istream&, Nhanvien&);
		friend ostream& operator << (ostream&,Nhanvien);
		friend bool operator < (Nhanvien a,Nhanvien b);
};

istream& operator >> (istream &in,Nhanvien &a){
	cnt++;
	a.ma = cnt;
	in.ignore();
	getline(in,a.ten);
	in >> a.gt >> a.ns;
	in.ignore();
	getline(in,a.dc);
	in >> a.mst >> a.hd;
	return in;
}

ostream& operator << (ostream& out,Nhanvien a){
	out << setfill('0') << setw(5) << a.ma << " ";
	out << a.ten << " " << a.gt << " " << a.ns << " " << a.dc << " " << a.mst << " " << a.hd << endl;
	return out;
}


bool operator < (Nhanvien a,Nhanvien b){
	string s1 = a.ns, s2 = b.ns;
	int ng1 = (s1[0]-'0')*10 + s1[1]-'0',t1 = (s1[3]-'0')*10 + s1[4]-'0', n1 = stoi(s1.substr(6));
	int ng2 = (s2[0]-'0')*10 + s2[1]-'0',t2 = (s2[3]-'0')*10 + s2[4]-'0', n2 = stoi(s2.substr(6));
	if(n1 != n2) return n1 < n2;
	if(t1 != t2) return t1 < t2;
	return n1 < n2;
}


int main(){
	int n; cin >> n;
	Nhanvien a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++) cout << a[i];
	return 0;
}

