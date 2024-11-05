#include <bits/stdc++.h>
using namespace std;

// friend function, friend class
// forward declaration


class Sinhvien{
	friend class Giaovien;
	private:
		string id,ten,ns;
		double gpa;
		static int dem;
	public:
		Sinhvien();
		void nhap();
		void in();
		void tangDem();
		int getDem();
		friend void chuanhoa(Sinhvien&);
};


void chuanhoa(Sinhvien &a){
	string res ="";
	stringstream ss(a.ten);
	string token;
	while(ss >> token){
		res += toupper(token[0]);
		for(int i=1;i<token.length();i++){
			res += tolower(token[i]);
		}
		res += " ";
	}
	res.erase(res.length()-1);
	a.ten = res;
}


class Giaovien{
	private:
		string khoa;
	public:
		void update(Sinhvien&);
};

void Giaovien::update(Sinhvien& x){
	x.gpa = 3.20;
}

int Sinhvien::dem =0;

void Sinhvien::tangDem(){
	++dem;
}

int Sinhvien::getDem(){
	return dem;
}

Sinhvien::Sinhvien(){
	this->id = id;
	this->ten = ten;
	this->ns = ns;
	this->gpa = gpa;
}

void Sinhvien::nhap(){
	++dem;
	this->id = "SV" + string(3-to_string(dem).length(),'0') + to_string(dem);
	cout << "Nhap ten : "; getline(cin,this->ten);
	cout << "Nhap ns : "; cin >> this->ns;
	cout << "Nhap diem : "; cin >> this->gpa;
	cin.ignore();
}

void Sinhvien::in(){
	cout << this->id <<" "<< this->ten << " " << this->ns << " " << this->gpa;
}

int main(){
	Sinhvien x;
	x.nhap();
	Giaovien y;
	y.update(x);
	x.in();
	return 0;
}








