# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

// Tim kiem....
// Sap xep.....
// tan suat...

struct SV{
	char ma[50];
	char ten[100];
	float gpa;
};

typedef struct SV SV;

void nhap(SV *a){
	scanf("%s",a->ma);
	getchar();
	gets(a->ten);
	scanf("%f",&a->gpa);
}

void in(SV a){
	printf("%s %s %.2f\n",a.ma,a.ten,a.gpa);
}

void timkiem1(SV a[], int n, char m[100]){
	for (int i=0;i<n;i++){
		if(strcmp(m,a[i].ma) ==0){
			in(a[i]); return;
		}
	}
	printf("KHONG TON TAI SINH VIEN VUA NHAP");
}

int cmp(const void*a,const void*b){
	SV *x = (SV*)a;
	SV *y = (SV*)b;
	if(x->gpa < y->gpa) return 1;
	return -1;
	// qsort(a,n,sizeof(SV),cmp)
}

void timkiem2(SV a[],int n){
	float res =0; int pos;
	for (int i=0;i<n;i++){
		if(a[i].gpa >res){
			res = a[i].gpa;
			pos = i;
		}
	}
	in(a[pos]);
}

void sx(SV a[],int n){
	for(int i=0;i<n;i++){
		int max_idx = i;
		for (int j=i+1;j<n;j++){
			if (a[i].gpa > a[max_idx].gpa){
				max_idx = j;
			}
		}
		SV tmp = a[i];
		a[i] = a[max_idx];
		a[max_idx] = tmp;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	SV a[n];
	for (int i=0;i<n;i++) nhap(&a[i]);
	for (int i=0;i<n;i++) in(a[i]);
	sx(a,n);
	for (int i=0;i<n;i++) in(a[i]);
}

