#include <bits/stdc++.h>
using namespace std;

int N,X[100],used[100];

void in(){
	for(int i=1;i<=N;i++){
		cout << X[i];
	}
	cout << endl;
}

void Try(int i){
	for(int j=1;j<=N;j++){
		if(!used[j]){ // used[j] == 0
			X[i] = j;
			used[j] = 1;
			if(i == N){
				in();
			}
			else{
				Try(i+1);
			}
			// backtrack
			used[j] = 0; // khi nao i = n se thuc hien lenh nay
		}
	}
	// khi xuong toi day no se day try(3) ra roi len try(2)...
}

int main(){
	cin >> N;
	memset(used,0,sizeof(used));
	Try(1);
}
