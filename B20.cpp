#include <bits/stdc++.h>
using namespace std;

int cnt =0;

class Giangvien{
	private:
		string  ten,mon,ma;
	public:
		// static int cnt;
		Giangvien();
		friend istream& operator >> (istream&,Giangvien&);
		friend ostream& operator << (ostream&,Giangvien);
		string getTen(){
			return this->ten;
		}
		string getMon(){
			return this->mon;
		}
};

// Giangvien::cnt =0;

Giangvien::Giangvien(){
	ten = mon = ma ="";
}

string chuanhoa(string s){
	stringstream ss(s);
	string token,res = "";
	while(ss >> token){
		res += toupper(token[0]);
	}
	return res;
}

string chuanhoa2(string s){
	stringstream ss (s);
	string token,res = "";
	while( ss >> token){
		res = token;
	}
	return res;
}


istream& operator >> (istream& in,Giangvien& a){
	++cnt;
	string tmp = to_string(cnt);
	tmp = string(2 - tmp.size(),'0')+tmp;
	a.ma = "GV" + tmp;
	cout << "Ten : "; in.ignore();
	getline(in,a.ten);
	cout << "Mon : "; getline(in,a.mon);
	a.mon = chuanhoa(a.mon);
	return in;
}


ostream& operator << (ostream& out,Giangvien a){
	out << a.ma << " " << a.ten << " " << a.mon << endl;
	return out;
}

bool tim(string name,string word){
	for(char &x : name) x = tolower(x);
	for(char &x : word) x = tolower(x);
	return name.find(word) != string::npos;
}


int main(){
	int n; cin >> n;
	Giangvien a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int q; cin >> q;
	while(q--){
		string s;
		cin >> s;
		cout << "Danh sach giang vien theo tu khoa " << s << ": " << endl;
		for(Giangvien x : a){
			if(tim(x.getTen(),s)){
				cout << x; 
			}
		}
	}
}




