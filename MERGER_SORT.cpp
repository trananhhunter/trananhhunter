#include <bits/stdc++.h>
using namespace std;

// tron 2 day con : day 1 [l,m], day 2 [m+1, r]

void merge(int a[],int l,int r,int m){
	vector<int> x(a+ l, a+m+1);
	vector<int> y(a+m+1, a+r+1);
	// chia lam 2 mang roi copy vao tung vector
	int i=0,j=0;
	while(i < x.size() && j < y.size()){
		if(x[i] <= y[j]){
			a[l] = x[i]; ++l; ++i;
		}
		else{
			a[l] = y[j]; ++l; ++j;
		}
	}
	// kiem tra phan tu cuoi cung
	while( i < x.size()){
		a[l] = x[i]; ++l; ++i;
	}
	while( j < y.size()){
		a[l] = y[j]; ++l; ++j;
	}
}

void mergeSort(int a[],int l, int r){
	if(l<=r) return;
	int m = (l+r)/2;
	mergeSort(a,l,r);
	mergeSort(a,m+1,r);
	merge(a,l,r,m);
}


// dem so cap nghich the
int merge1(int a[],int l,int r,int m){
	vector<int> x(a+ l, a+m+1);
	vector<int> y(a+m+1, a+r+1);
	// chia lam 2 mang roi copy vao tung vector
	int i=0,j=0;
	int cnt =0;
	while(i < x.size() && j < y.size()){
		if(x[i] <= y[j]){
			a[l] = x[i]; ++l; ++i;
		}
		else{
			cnt += x.size() - i;
			a[l] = y[j]; ++l; ++j;
		}
	}
	// kiem tra phan tu cuoi cung
	while( i < x.size()){
		a[l] = x[i]; ++l; ++i;
	}
	while( j < y.size()){
		a[l] = y[j]; ++l; ++j;
	}
	return cnt;
}
int mergeSort1(int a[],int l, int r){
	int dem =0;
	if(l<r){
		int m = (l+r)/2;
	dem += mergeSort1(a,l,r);
	dem += mergeSort1(a,m+1,r);
	dem += merge1(a,l,r,m);
	}
	return dem;
}


int main(){
	int n=10000;
	int a[10000];
	srand(time(NULL));
	for(int i=0;i<n;i++){
		a[i] = rand() % 1000;
	}
	int ans = mergeSort1(a,0,n-1);
	for(int x:a){
		cout << x << " ";
	}
	cout << ans << endl;
}

