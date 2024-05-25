# include <stdio.h>
# include <string.h>
# include <conio.h>
main(){
	printf("Nhap xau ki tu :\n");
	char c[1001];
	fflush(stdin);
	gets(c);
	puts(c);
	printf("DO DAI XAU : %d\n",(int)strlen(c));
	printf("IN HOA XAU : %s \n",strupr(c));
	printf("DAO NGUOC XAU : %s ",strrev(c));
	getch();
}
