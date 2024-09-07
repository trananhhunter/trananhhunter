#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

typedef struct Node* node;

// cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x){
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

// kiem tra rong
bool empty(node a){
	return a == NULL;
}

// dem so phan tu trong danh sach lk
int Size(node a){
	int cnt =0;
	while(a != NULL){
		++cnt;
		a = a->next; // gan dia chi cua node tiep theo cho node hien tai
	}
	return cnt;
}

// them 1 ptu vao dau dslk
void insertfirst(node &a,int x){ // chieu tham chieu
	node tmp = makeNode(x);
	if(a==NULL){
		// dslk rong
		 a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}


// them 1 phan tu vao cuoi ds
void insertLast(node &a,int x){
	node tmp = makeNode(x);
	if(a == NULL){
		a = tmp;
	}
	else{
		node p = a;
		while(p->next != NULL){
			p = p->next;
		}
		// khi nay p se tro toi vi tri cuoi cung
		p->next = tmp;
	}
}

// them 1 phan tu o giua
void insertMiddle(node &a, int x, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n+1){
		cout << "Vi tri khong hop le" << endl;
	}
	if(pos == 1){
		// vi tri dau tien
		insertfirst(a,x); return;
	}
	else if(pos == n + 1){
		insertLast(a,x); return;
	}
	node p = a;
	for(int i=1;i< pos -1;i++){
		p = p->next;
	}
	node tmp = makeNode(x);
	tmp->next = p->next; // tro con tro vao vi tri can them
	p->next = tmp;
}

// xoa phan tu o dau
void deleteFirst(node &a){
	if(a== NULL) return;
	a = a->next;
}

// xoa phan tu o cuoi
void deleteLast(node &a){
	if(a == NULL) return;
	node truoc = NULL, sau = a;
	while(sau->next != NULL){
		truoc = sau;
		sau = sau->next;
		// khi nay truoc se o vi tri gan cuoi cung
	}
	if(truoc == NULL){
		a = NULL;
	}
	else{
		truoc->next = NULL;
	}
}

// xoa o giua
void deleteMiddle(node &a,int pos){
	if(pos <=0 || pos > Size(a)) return;
	node truoc = NULL, sau = a;
	for(int i=1;i<pos;i++){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL){
		a = a->next;
	}
	else{
		truoc->next = sau->next;
		// con tro o truoc pos tro vao sau pos de xoa pos
	}
}

// sap xep
void sapxep(node &a){
	for(node p = a;p->next != NULL;p = p->next){
		node min = p;
		for(node q = p->next;q->next != NULL;q = q->next){
			if(q->data < min->data){
				min = q;
			}
		}
		int tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}

// tim kiem trong dslk




void in(node a){
	cout << "----------------------------------------------" << endl;
	while(a != NULL){
		cout << a->data <<  " ";
		a = a->next;
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
}


int main(){
	node head = NULL;
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
			int x; cout << "Nhap gia tri can chen : "; cin >> x;
			insertfirst(head,x);
		}
		else if(lc == 2){
			int x; cout << "Nhap gia tri can chen : "; cin >> x;
			insertLast(head,x);
		}
		else if(lc ==3){
			int x; cout << "Nhap gia tri can chen : "; cin >> x;
			int pos; cout << "Nhap vi tri can chen : "; cin >> pos;
			insertMiddle(head,x,pos);
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
			in(head);
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

