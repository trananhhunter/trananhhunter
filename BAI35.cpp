# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <math.h>


struct Phanso{
	int tuso;
	int mauso;
};

typedef struct Phanso ps;

ps nhap(){
	ps a;
	printf("NHAP TU SO : ");
	scanf("%d",&a.tuso);
	printf("NHAP MAU SO: ");
	scanf("%d",&a.mauso);
	return a;
}
int gcd(int a,int b){
	if(b==0) return a;
	return (b,a%b);
}

void toigian(ps a){
	int ucln = gcd(a.tuso,a.mauso);
	a.tuso /= ucln;
	a.mauso /=ucln;
	if(a.mauso < 0){
		a.tuso = - a.tuso;
		a.mauso = -a.mauso;
	}
	printf("%d /%d",a.tuso,a.mauso);
}

void cong(ps a1, ps a2){
	ps ketqua;
	ketqua.tuso = a1.tuso*a2.mauso + a2.tuso*a1.mauso;
	ketqua.mauso = a1.mauso*a2.mauso;
	toigian(ketqua);
}



int main(){
	ps PS1 = nhap();
	ps PS2 = nhap();
	cong(PS1,PS2);
}

