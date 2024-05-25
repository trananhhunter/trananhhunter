# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int main(){
	char c[100], a[50][50];
	gets(c);
	int n =0, cnt =0;
	char *token = strtok(c, " ");
	while(token!=NULL){
		strcpy(a[n++],token);
		token = strtok(NULL, " ");
	}
	for (int i=0; i<n;i++){
		while(strcmp(a[i],a[i+1])==0){
			++cnt;
		}
	}
	printf("%d ",cnt);
}
