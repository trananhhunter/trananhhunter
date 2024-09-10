#include <bits/stdc++.h>
using namespace std;

int n,c[105][105],X[105];
int visited[105],d = 0,ans = INT_MAX,cmin =INT_MAX;

// toi uu : danh gia can duoi : chi phi min co the dat duoc trong loi goi quay lui hien tai

void nhap(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
			if(c[i][j] != 0){
				cmin = min(cmin,c[i][j]);
			}
		}
	}
	memset(visited,0,sizeof(visited));
}

// di tim X[i]
void Try(int i){
	for(int j=1;j<=n;j++){
		if(visited[j] == 0){
			visited[j] = 1;
			X[i] = j; // thanh pho toi
			d += c[X[i-1]][X[i]]; // khoang cach x1 = 1, x2 = 3
			if(i == n){
				ans = min(ans, d + c[X[n]][1]); // phai co ca kc tu thanh pho cuoi ve
			}
			else if(d + (n-i+1)*cmin < ans){
				Try(i+1);
			}
			// backtrack
			visited[j] = 0;
			d -= c[X[i-1]][X[i]]; // sau moi lan cong them vao thi no se phai tru di kc trc
		}
	}
}

int main(){
	nhap();
	X[1] = 1; visited[1] = 1;
	Try(2);
	cout << ans << endl;
}
