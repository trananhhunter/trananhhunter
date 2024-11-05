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
	map<int, vector<Sinhvien>> mp;
	for(int i=0;i<n;i++){
		Sinhvien tmp; cin >> tmp;
		mp[stoi(tmp.getLop().substr(1,2))].push_back(tmp);
	}
	int q; cin >> q;
	while(q--){
		int nam; cin >> nam;
		cout << "Danh sach sinh vien khoa " << nam << endl;
		for(Sinhvien x : mp[nam%100]){
			cout << x;
			}
		}
	}
