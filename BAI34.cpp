# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

int main(){
	char c[100];
	gets(c);
	int cnt[256] ={0}; // dem tan suat ki tu
	for (int i=0;i<strlen(c);i++){  // kiem tra lan luot cac ki tu trong xau va tang bien dem 
		cnt[c[i]]++;
	}
	for (int i=0;i<256;i++){
		if (cnt[i]!=0){
			printf("%d%c",cnt[i],i);
		}
	}
}
