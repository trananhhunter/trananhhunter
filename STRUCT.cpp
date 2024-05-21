# include <stdlib.h>

struct struct_Name{
	// data
};

struct SinhVien{
	char ma[20];
	char ten[50];
	double gpa;
	char lop[20];
};

struct date{
	int ngay, thang, nam;
};

struct hour{
	int gio, phut, giay;
};

struct Ve{
	date NgayXem;
	hour GioXem;
	char tenPhim;
	double giaVe;
};

typedef struct SinhVien SV; 

int main(){
	struct Ve v;
	v.giaVe;
	v.tenPhim;
	v.NgayXem.thang;
	v.NgayXem.nam;
}
