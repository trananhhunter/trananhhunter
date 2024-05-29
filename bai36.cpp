# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <ctype.h>
struct Sinhvien{
	char hoten[100];
	int nam;
	float diemtb;
};

typedef struct Sinhvien Sv;

void nhap(Sv *x){
	printf("\nHo ten :");
	getchar();
	gets(x->hoten);
	printf("\nNam sinh : ");
	scanf("%d",&x->nam);
	printf("\nDiem trung binh :");
	scanf("%f",&x->diemtb);
}

void in(Sv x){
	printf("%s %d %.2f \n",x.hoten,x.nam,x.diemtb);
}

void xeploai(Sv a[],int n){
	for(int i=1;i<=n;i++){
		printf("Cac hoc sinh xep loai kha tro len: \n");
		printf("%d . ",i);
		if(a[i].diemtb >7 ){
			in(a[i]); return;
		}
	}
	printf("KHONG CO HOC SINH NAO!!!");
}

void namsinh(Sv a[],int n){
	for(int i=1;i<=n;i++){
		printf("Cac hoc sinh co nam sinh nho hon 1997 la :\n");
		printf("%d . ",i);
		if(a[i].nam <1997 ){
			in(a[i]);
			return;
		}
	}
	printf("Khong co hoc sinh nao sinh truoc nam 1997");
}



void sx(Sv a[],int n){
	for(int i=1;i<=n;i++){
		int max=i;
		for(int j=i+1;j<=n;j++){
			if(a[j].diemtb > a[max].diemtb) max =j;
		}
		Sv tmp = a[i]; // khai bao cung struct
		a[i] = a[max];
		a[max] = tmp;
	}
	for(int i=0;i<n;i++) {
			printf("%d . ",i);
			in(a[i]);
	}
}



int main(){
	printf("Moi ban nhap so sinh vien can nhap :\n");
	int n;
	scanf("%d",&n);
	printf("Moi ban nhap thong tin cho tung sinh vien:\n");
	Sv a[n];
	for(int i=1;i<=n;i++){
		printf("%d. ",i);
		nhap(&a[i]);
	}
	printf("Moi ban nhap lua chon ban can:\n");
	printf("1. In ra danh sach sinh vien xep loai kha tro len\n");
	printf("2. In ra danh sach sinh vien co nam sinh <1997 \n");
	printf("3. In ra danh sach sinh vien theo thu tu giam dan cua diem trung binh\n");
	int chon;
	scanf("%d",&chon);
	switch(chon){
		case 1 : xeploai(a,n); break;
		case 2 : namsinh(a,n); break;
		case 3 : sx(a,n); break;
	}
	printf("Cam on da su dung chuong trinh !!!\n");
	printf("Thanks<3");
}
