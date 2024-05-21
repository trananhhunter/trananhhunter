# include <stdio.h>
# include <math.h>

int doi_nhi_phan(int n){
	int so_nhi_phan =0;
	int cnt =0;
	while(n>0){
		so_nhi_phan = so_nhi_phan + (n%2)*pow(10,cnt);
		cnt++;
		n=n/2;
	}
	return so_nhi_phan;
}

int doi_thap_phan(int n){
	int so_thap_phan =0;
	int cnt =0;
	while(n>0){
		so_thap_phan = so_thap_phan + (n%10)*pow(2,cnt);
		cnt++;
		n=n/10;
	}
	return so_thap_phan;
}

int main(){
	printf("Doi tu thap phan sang nhi phan 1\n");
	printf("Doi tu nhi phan sang thap phan 2\n");
	printf("MOI BAN NHAP LUA CHON TRONG CAC LUA CHON :\n");
	int chon;
	scanf("%d",&chon);
	printf("Nhap so can doi : ");
	int n;
	scanf("%d",&n);
	switch(chon){
		case 1 : printf("Doi so %d sang nhi phan %d\n",n,doi_nhi_phan(n));
			break;
		case 2 : printf("Doi so %d sang thap phan %d\n",n,doi_thap_phan(n));
			break;
		default : printf("BAN NHAP SAI LUA CHON\n");
			break;
	}
}
