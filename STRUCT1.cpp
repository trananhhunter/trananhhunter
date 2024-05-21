# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

struct HocSinh{
	char ten[100];
	double diem;
};

typedef HocSinh HS;

// nhap thong tin tra ve 1 struct
HS nhap1(){
	HS x;
	gets(x.ten);
	scanf("%lf",&x.diem);
	return x;
}

// voi con tro

HS nhap2(HS *x){
	getchar();
	gets(x->ten);
	scanf("%lf",&x->diem);
}

void in(HS a){
	printf("%s %.2lf\n",a.ten, a.diem);
}

int main(){
	HS a[1000];
	int n;
	scanf("%d",&n);
	// su dung n sinh vien
	for (int i=0;i<n;i++) nhap2(&a[i]);
	for (int i=0;i<n;i++) in(a[i]);
}
