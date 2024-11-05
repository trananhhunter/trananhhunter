#include <bits/stdc++.h>
using namespace std;

int cnt =0;


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


class Giangvien{
	private:
		string  ten,mon,ma;
	public:
		// static int cnt;
		Giangvien();
		void nhap(){
			++cnt;
			string tmp = to_string(cnt);
			tmp = string(2 - tmp.size(),'0')+tmp;
			ma = "GV" + tmp;
			cout << "Ten : "; cin.ignore();
			getline(cin,ten);
			cout << "Mon : "; getline(cin,mon);
			mon = chuanhoa(mon);
		}
		void in(){
			cout << ma << " " << ten << " " << mon << endl;
		}
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


int main(){
	int n; cin >> n;
	cin.ignore();
	map<string,vector<Giangvien>> mp;
	for(int i=0;i<n;i++){
		Giangvien tmp;
		tmp.nhap();
		mp[chuanhoa(tmp.getMon())].push_back(tmp);
		// luu vao map bo mon co giang vien do
	}
	int q; cin >> q; cin.ignore();
	while(q--){
		string s;
		getline(cin,s);
		cout << "Danh sach giang vien bo mon " << chuanhoa(s) << ": " << endl;
		for(Giangvien x : mp[chuanhoa(s)]){
			x.in();
		}
	}
}




