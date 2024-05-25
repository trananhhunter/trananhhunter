#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check(char c[]){
	for (int i=0;i<strlen(c);i++){
		if(!islower(c[i])) // kiem tra ki tu in hoa
			return 0;
	}
	return 1;
}

void trim(char str[]) {
    int start = 0; // V? trí b?t ð?u c?a chu?i không có k? t? vô ngh?a
    int end = strlen(str) - 1; // V? trí k?t thúc c?a chu?i không có k? t? vô ngh?a

    // Lo?i b? k? t? vô ngh?a ? ð?u chu?i
    while ((str[start] == ' ' || str[start] == '\t' || str[start] == '\n') && str[start] != '\0') {
        start++;
    }

    // Lo?i b? k? t? vô ngh?a ? cu?i chu?i
    while ((str[end] == ' ' || str[end] == '\t' || str[end] == '\n') && end >= start) {
        end--;
    }

    // Di chuy?n các k? t? v? ð?u chu?i và thêm k? t? k?t thúc chu?i
    int i, j;
    for (i = start, j = 0; i <= end; i++, j++) {
        str[j] = str[i];
    }
    str[j] = '\0'; // Thêm k? t? k?t thúc chu?i
}

void loaikhoangtrang(char c[1000]){
	char *token =strtok(c, " ");
		while(token != NULL){
			if(check(token)){
				printf("%s",token);
				token = strtok(NULL, " ");
			}
		}
		printf("\n");
}

void demtu(char c[1000]){
	char *token = strtok(c, " "); // tach cac ki tu duoc cach nhau boi dau cach
	int max=0;
	char idx[100];
	int cnt =0;
	while (token!= NULL){
		++cnt;
		if(strlen(token)>max){
			max = strlen(token);
			strcpy(idx,token);
		}
		token = strtok(NULL, " ");
		}
	printf("So luong tu trong cau: %d\n",cnt);
	printf("Tu co do dai dai nhat: %s ",idx);
}


void inhoa(char c[1000]){
	for(int i=0;i<strlen(c);i++){
		if(i==0) {
			c[i] = toupper(c[i]); // in hoa chua cai dau
		}
	}	
	printf("%s ",c); // dua ra ca xau con %c la dua ra ki tu
}

int main() {
	printf("MOI LUA CHON:\n");
	printf("1. LOAI BO KI VO NGHIA \n");
	printf("2. CHU CAI DAU CAU VIET HOA\n");
	printf("3. DEM SO TU TRONG XAU VA IN RA TU CO DO DAI LON NHAT\n");
	int chon;
	scanf("%d",&chon);
	getchar();
    char c[1000];
    gets(c);
    switch(chon){
    	case 1: trim(c); loaikhoangtrang(c); break;
    	case 2: inhoa(c); break;
    	case 3: demtu(c); break;
    	default : printf("KHONG CO LUA CHON NAO !!!");
	}
}

