#include <bits/stdc++.h>
using namespace std;

struct Hocsinh{
	string ten;
	double toan,van,tb;
};

struct HS{
	Hocsinh s;
	HS* next;
};

typedef struct HS* hs;

hs makeNode(){
	Hocsinh s;
	cout << "Nhap ten : "; cin.ignore();
	getline(cin,s.ten);
	cout << "Nhap diem toan : "; cin >> s.toan;
	cout << "Nhap diem van : "; cin >> s.van;
	s.tb = (s.toan + s.van) / 2;
	hs tmp = new HS();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

bool empty(hs a){
	return a == NULL;
}

int Size(hs a){
	int cnt =0;
	while(a != NULL){
		++cnt;
		a = a->next;
	}
	return cnt;
}

void insertFirst(hs &a){
	hs tmp = makeNode();
	if(a==NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

void insertLast(hs &a){
	hs tmp = makeNode();
	if(a==NULL){
		a = tmp;
	}
	else{
		hs p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

void insertMiddle(hs &a, int k){
	int n = Size(a);
	if(k <= 0 || k > n+1) return;
	if(k == 1){
		insertFirst(a); return;
	}
	else if(k == n+1){
		insertLast(a); return;
	}
	hs p =a;
	for(int i=0;i<k-1;i++){
		p= p->next;
	}
	hs tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}


void deleteFirst(hs &a){
	if(a == NULL) return;
	a = a->next;
}

void deleteLast(hs &a){
	if(a == NULL) return;
	hs truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == sau){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}


void deleteMiddle(hs &a,int k){
	if(k <= 0 || k > Size(a)) return;
	hs truoc = NULL, sau = a;
	for(int i=1;i<k;i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
	}
}

void in(Hocsinh a){
	cout << "--------------------------------" << endl;
	cout << "Ten : " << a.ten << endl;
	cout << "Toan : " << a.toan << endl;
	cout << "Van : " << a.van << endl;
	cout << "TB : " << fixed << setprecision(2) << a.tb << endl;
	cout << "--------------------------------" << endl;
}

void sapxep(hs &a){
	for(hs p = a;p->next != NULL; p= p->next){
		hs min = p;
		for(hs q = p->next; q != NULL; q= q->next){
			if(q->s.tb > min->s.tb){
				min = q;
			}
		}
		Hocsinh tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}

void inds(hs a){
	cout << "Danh sach hoc sinh " << endl;
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	cout << endl;
	cout << "--------------------------------" << endl;
}



int main(){
	hs head = NULL;
	while(1){
		cout << "-----------------------Menu-----------------------" << endl;
		cout << "1. Chen hoc sinh vao dau danh sach" << endl;
		cout << "2. Chen hoc sinh vao cuoi danh sach" << endl;
		cout << "3. Chen hoc sinh vao giua danh sach" << endl;
		cout << "4. Xoa hoc sinh o dau" << endl;
		cout << "5. Xoa hoc sinh o cuoi" << endl;
		cout << "6. Xoa hoc sinh o giua" << endl;
		cout << "7. Duyet danh sach lien ket" << endl;
		cout << "8. Sap xep diem tb giam dan" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Nhap lua chon : ";
		int lc; cin >> lc;
		if(lc ==1){
			insertFirst(head);
		}
		else if(lc == 2){
			insertLast(head);
		}
		else if(lc ==3){
			int k; cout << "Nhap vi tri can chen : "; cin >> k;
			insertMiddle(head,k);
		}
		else if(lc == 4){
			deleteFirst(head);
		}
		else if(lc == 5){
			deleteLast(head);
		}
		else if(lc == 6){
			int k; cout << "Nhap vi tri can xoa : "; cin >> k;
			deleteMiddle(head,k);
		}
		else if(lc == 7){
			inds(head);
		}
		else if(lc == 8){
			sapxep(head);
		}
		else if(lc == 0){
			cout << "Tam biet ban" << endl;
			break;
		}
	}
}




