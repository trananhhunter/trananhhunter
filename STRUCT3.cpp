# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

struct num{
	char val[100];
	int fre; // tan suat
};

typedef struct num num;

int tn(char c[]){
	int l=0, r = strlen(c)-1;
	while(l<r){
		if(c[l] != c[r]) return 0;
		++l;--r;
	}
	return 1;
}

int n=0;
num a[1000];

int find(char x[]){
	for(int i=0;i<n;i++){
		if(strcmp(x, a[i].val)==0) return i; // tim thay
	}
	return -1;
}

int cmp(const void*a,const void*b){
	num* x = (num*)a;
	num* y = (num*)b;
	if(strlen(x->val) != strlen(y->val)){
		return (int)strlen(y->val) -(int)strlen(x->val);
	}
	return -strcmp(x->val,y->val);
}

int main(){
	char x[100];
	while(scanf("%s",x) != -1){
		if(tn(x)){
			int pos = find(x);
			if(pos != -1){
				a[pos].fre++; // tang tan suat
			}
			else{
				strcpy(a[n].val, x);
				a[n].fre =1;
				++n;
			}
		}
	}
	qsort(a,n,sizeof(num),cmp);
	for(int i=0;i<n;i++){
		printf("%s %d \n",a[i].val,a[i].fre);
	}
}
