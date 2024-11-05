#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

class Phanso{
	private:
		ll tu,mau;
	public:
		Phanso(ll tu,ll mau);
		friend istream& operator >> (istream&,Phanso&);
		friend ostream& operator << (ostream&,Phanso);
		void rutgon();
		bool operator + (Phanso a);
};

Phanso::Phanso(ll tu,ll mau){
	this->tu = tu;
	this->mau = mau;
}


istream& operator >> (istream& in,Phanso& a){
	in >> a.tu >> a.mau;
	return in;
}

ostream& operator << (ostream& out,Phanso a){
	out << a.tu << "/" << a.mau;
	return out;
}

void Phanso::rutgon(){
	ll g = gcd(tu,mau);
	tu /=g;
	mau/=g;
}

bool Phanso::operator +(Phanso a){
	Phanso tong(1);
	tong.tu = this->tu*a.mau + this->mau*a.tu;
	tong.mau = this->mau*a.mau;
	ll g = gcd(tong.mau,tong.tu);
	tong.tu /= g; tong.mau /= g;
	return tong;
}

int main(){
	Phanso p(1,1), q(1,1);
	cin >> p >> q;
	cout << p + q ;
}

