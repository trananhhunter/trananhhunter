#include <bits/stdc++.h>
using namespace std;

int N,X[100],cot[100],d1[100],d2[100];

// d1 la duong cheo chinh i - j + n
// d2 la duong cheo phu i + j -1
int a[100][100],cnt =0;

void inkq(){
//	for(int i=1;i<=N;i++){
//		cout << "Con hau o hang thu " << i << " nam o cot " << X[i] << endl;
//	}
	memset(a,0,sizeof(a));
	for(int i=1;i<=N;i++){
		a[i][X[i]] = 1;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Try(int i){
	for(int j = 1;j<=N;j++){
		// kiem tra xem cot dc co bi chiem hay chua 
		if(cot[j] == 1 && d1[i - j + N] == 1 && d2[i +j -1] == 1){
			X[i] = j;
			cot[j] = d1[i-j+N] = d2[i+j-1] = 0;
			// danh dau da bi chiem
			if(i == N){
				inkq();
				++cnt;
			}
			else{
				Try(i+1);
			}
			// backtrack
			cot[j] = d1[i-j+N] = d2[i+j-1] = 1;
		}
	}
}

int main(){
	cin >> N;
	for(int i=1;i<=99;i++){
		cot[i] = d1[i] = d2[i] = 1;
	}
	Try(1);
	cout << cnt << endl;
}
