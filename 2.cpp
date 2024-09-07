#include <bits/stdc++.h>
using namespace std;

struct Student{
	string name,id;
	double gpa;
};

struct SV{
	Student s;
	SV* next;
};

typedef struct SV* sv;

sv makeNode(){
	Student s;
	cout << "Nhap thong tin sinh vien : " << endl;
	cout << "Nhap ID : "; cin >> s.id;
	cout << "Nhap ten : "; cin.ignore();
	getline(cin,s.name);
	cout << "Nhap GPA : "; cin >> s.gpa;
	sv tmp= new SV();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

// kiem tra rong
bool empty(sv a){
	return a == NULL;
}

// dem so sv trong dslk
int Size(sv a){
	int cnt =0;
	while(a != NULL){
		++cnt;
		a = a->next;
	}
	return cnt;
}

// them 1 sv vao dau ds
void insertFirst(sv &a){
	sv tmp = makeNode();
	if(a==NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}


// them 1 sv vao cuoi ds
void insertLast(sv &a){
	sv tmp = makeNode();
	if(a== NULL){
		a = tmp;
	}
	else{
		sv p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}

// them 1 sv vao giua
void insertMiddle(sv &a,int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n+1){
		cout << "Vi tri khong hop le" << endl; return;
	}
	if(pos==1){
		insertFirst(a); return;
	}
	else if(n + 1 == pos){
		insertLast(a); return;
	}
	sv p = a;
	for(int i=1;i<pos -1;i++){
		p = p->next;
	}
	sv tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}

// xoa phan tu o dau
void deleteFirst(sv &a){
	if(a== NULL) return;
	a = a->next;
}

// xoa phan tu o cuoi
void deleteLast(sv &a){
	if(a==NULL) return;
	sv truoc = NULL, sau = a;
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

// xoa phan tu o giua
void deleteMiddle(sv &a,int pos){
	if(pos <= 0 || pos > Size(a)) return;
	sv truoc = NULL, sau = a;
	for(int i=1;i<pos;i++){
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

void in(Student s){
	cout << "---------------------------------------------------" << endl;
	cout << "ID : " << s.id << endl;
	cout << "Ten : " << s.name << endl;
	cout << "GPA : " << fixed << setprecision(2) << s.gpa << endl;
	cout << "---------------------------------------------------" << endl;
}

void sapxep(sv &a){
	for(sv p=a; p->next != NULL; p = p->next){
		sv min = p;
		for(sv q = p->next; q != NULL;q = q->next){
			if(q->s.gpa < min->s.gpa){
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}

void inds(sv a){
	cout << "Danh sach sinh vien " << endl;
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	cout << endl;
	cout << "---------------------------------------------------" << endl;
}










int main(){
	sv head = NULL;
	while(1){
		cout << "-----------------------Menu-----------------------" << endl;
		cout << "1. Chen phan tu vao dau danh sach" << endl;
		cout << "2. Chen phan tu vao cuoi danh sach" << endl;
		cout << "3. Chen phan tu vao giua danh sach" << endl;
		cout << "4. Xoa phan tu o dau" << endl;
		cout << "5. Xoa phan tu o cuoi" << endl;
		cout << "6. Xoa phan tu o giua" << endl;
		cout << "7. Duyet danh sach lien ket" << endl;
		cout << "8. Sap xep tang dan" << endl;
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
			int pos; cout << "Nhap vi tri can chen : "; cin >> pos;
			insertMiddle(head,pos);
		}
		else if(lc == 4){
			deleteFirst(head);
		}
		else if(lc == 5){
			deleteLast(head);
		}
		else if(lc == 6){
			int pos; cout << "Nhap vi tri can xoa : "; cin >> pos;
			deleteMiddle(head,pos);
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














