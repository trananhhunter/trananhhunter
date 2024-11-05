#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}

class Phanso{
	private:
		ll tu,mau;
	public:
		Phanso(ll tu,ll mau);
		friend istream& operator >> (istream&,Phanso&);
		friend ostream& operator << (ostream&,Phanso);
		void rutgon();
		friend Phanso operator + (Phanso a,Phanso b);
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

Phanso operator + (Phanso a,Phanso b){
	Phanso tong(1,1);
	ll mc = lcm(a.mau,b.mau);
	tong.tu = mc / a.mau * a.tu + mc / b.mau *b.tu;
	tong.mau = mc;
	ll g = gcd(tong.mau,tong.tu);
	tong.tu /= g; tong.mau /= g;
	return tong;
}

int main(){
	Phanso p(1,1), q(1,1);
	cin >> p >> q;
	cout << p + q ;
}

