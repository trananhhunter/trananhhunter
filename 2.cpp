#include <bits/stdc++.h>
using namespace std;

// stactic

class Sinhvien{
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
};

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
	x.in();
	Sinhvien y;
	y.nhap();
	y.in();
	return 0;
}








