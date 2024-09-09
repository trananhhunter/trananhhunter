#include <bits/stdc++.h>
using namespace std;

int N,K,X[100];

void in(){
	for(int i=1;i<=K;i++){
		cout << X[i];
	}
	cout << endl;
}

// gia tri lon nhat n-k+i
// gia tri nho nhat X[i-1] + 1

void Try(int i){
	for(int j = X[i-1] + 1; j <= N-K+i;j++){
		X[i] = j;
		if(i == K){
			in();
		}
		else{
			Try(i+1);
		}
	}
}

int main(){
	cin >> N >> K;
	X[0] = 0;
	Try(1);
}
