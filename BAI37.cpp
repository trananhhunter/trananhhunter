# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

struct Sach{
	char masach[20];
	char tensach[100];
	char tacgia[100];
	int namxb;
};

typedef struct Sach S;

void nhap(S *x){
	scanf("%s",&x->masach);
	getchar();
	gets(x->tensach);
	gets(x->tacgia);
	scanf("%d",&x->namxb);
}

void in(S a){
		printf("%s %s %s %d \n",a.masach,a.tensach,a.tacgia,a.namxb);
}

void find(S a[],int n,char m[100]){
	for(int i=0;i<n;i++){
		if(strcmp(m,a[i].tensach)==0){
			in(a[i]); return;
		}
	}
	printf("KHONG THAY SACH VUA NHAP");
}


int main(){
	int n;
	scanf("%d",&n);
	S a[n];
	for(int i=0;i<n;i++) nhap(&a[i]);
	for(int i=0;i<n;i++) in(a[i]);
	char s[100];
	getchar();
	printf("NHAP TEN SACH:");
	gets(s);
	find(a,n,s);
}
