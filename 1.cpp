#include <bits/stdc++.h>
using namespace std;

// class : lop
// thuoc tinh : attribute
// phuong thuc : method, behavior
// object : doi tuong
// constructor : ham khoi tao
// destructor : ham huy
// this pointer
// setter getter
// - encapsulation : dong goi
// - access modifier
// - private
// - public
// - protected
// static bai 2
// friend function, friend class
// Operator overloading
// << >> 
// cout : ostream
// cin : istream
class SinhVien{
	// ko the truy cap duoc
	private:
		string id,ten,ns;
		double gpa;
	// xay dung phuong thuc
	public:
		SinhVien();
		SinhVien(string,string,string,double);
		void xinchao();
		void dihoc();
		void nhap();
		void in();
		double getGpa();
		~SinhVien(); // ham huy
};


// implementation
// toan tu pham vi ::
SinhVien::SinhVien(){
	id = ten= ns = "";
	gpa = 0;
}

SinhVien::SinhVien(string ma,string name,string birth,double diem){
	this->id = id;
	this->ten= ten;
	this->ns = ns;
	this->gpa=gpa;
}

void SinhVien::xinchao(){
	cout << "Hello" << endl;
}
void SinhVien::dihoc(){
	cout << "Di hoc" << endl;
}


SinhVien::~SinhVien(){
	cout << "Doi tuong duoc huy tai day" << endl;
}


void SinhVien::nhap(){
	cin >> this->id;
	cin.ignore();
	getline(cin,this->ten);
	cin >> this->ns;
	cin >> this->gpa;
}

void SinhVien::in(){
	cout << this->id << " " << this->ten << " " << this->ns << " " << this->gpa << endl;
}

double SinhVien::getGpa(){
	return this->gpa; // return gpa
}

bool cmp(SinhVien a,SinhVien b){
	return a.getGpa() > b.getGpa();
}


int main(){
	SinhVien x("123","Tran Anh Hunter","07/12/2005",4.0);
	x.xinchao();
	x.dihoc();
}





