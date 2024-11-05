#include <bits/stdc++.h>
using namespace std;

class Sinhvien{
	private:
		string ma,ten,lop,email;
	public:
		Sinhvien(){
			ma = ten = lop = email ="" ;
		}
		friend istream& operator >> (istream&,Sinhvien&);
		friend ostream& operator << (ostream&,Sinhvien);
		bool operator < (Sinhvien a){
			return this->ma < a.ma;
		}
		string getLop(){
			return this->lop;
		}
		string getMa(){
			return this->ma;
		}
};

istream& operator >> (istream& in,Sinhvien& a){
	cout << "Ma sv : "; in >> a.ma;
	cout << "Ten : "; in.ignore();
	getline(in,a.ten);
	cout << "Lop : "; in >> a.lop;
	cout << "Email : "; in >> a.email;
	return in;
}

ostream& operator << (ostream& out,Sinhvien a){
	cout << a.ma << " " << a.ten << " " << a.lop << " " << a.email << endl;
	return out;
}


void viethoa(string &s){
	for(char &x : s) x = toupper(x);
}

string convert(string s){
	// lay char[0] cua 2 token dau
	stringstream ss(s);
	vector<string> v;
	string token,res = "";
	while(ss >> token){
		v.push_back(token);
	}
	for(int i=0;i<2;i++){
		res += toupper(v[i][0]);
	}
	return res;
}

int main(){
	int n; cin >> n;
	map<string, vector<Sinhvien>> mp;
	for(int i=0;i<n;i++){
		Sinhvien tmp; cin >> tmp;
		mp[tmp.getMa().substr(5,2)].push_back(tmp);
		// dua cac sinh vien cung nganh vao 1 vector
	}
	int q; cin >> q;
	cin.ignore();
	while(q--){
			string s; getline(cin,s);
			viethoa(s);
			cout << "Danh sach sinh vien nganh " << s  << ":"<< endl;
			string ng = convert(s);
			if(ng == "CN" || ng == "AI"){
				for(Sinhvien x : mp[ng]){
					if(x.getMa().find("E") != string::npos){
						cout << x;
					}
				}
			}
			else{
				for(Sinhvien x : mp[ng]){
					cout << x;
				}
			}
		}
	}
