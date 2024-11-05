#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Doanhnghiep{
	private:
		string ma,ten;
		int soLuong;
	public:
		void nhap();
		void in();
		int getSoluong(){
			return this->soLuong;
		}
		string getMa(){
			return this->ma;
		}
};


void Doanhnghiep::nhap(){
	cin >> ma;
	cin.ignore();
	getline(cin,ten);
	cin >> soLuong;
}

void Doanhnghiep::in(){
	cout << ma << " " << ten << " " << soLuong << endl;
}


bool cmp(Doanhnghiep a,Doanhnghiep b){
	if(a.getSoluong() != b.getSoluong())
		return a.getSoluong() > b.getSoluong();
	return a.getMa() < b.getMa();
}

int main(){
	int n; cin >> n;
	Doanhnghiep a[1000];
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
	sort(a,a+n,cmp);
	for(auto x : a){
		x.in();
	}
	return 0;
}

