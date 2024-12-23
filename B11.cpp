#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Nguoi{
	protected:
		string hten;
		int ns;
	public:
		Nguoi(){
			hten = "";
			ns =0;
		}
		void nhap(){
			cout << "Ho ten : "; getline(cin,hten);
			cout << "Nam sinh : "; cin >> ns;cin.ignore();
		}
		void in(){
			cout << "Ho ten : " << hten << endl;
			cout << "Nam sinh : " << setw(4)<< ns << endl;
			
		}
};

class GiangVien : public Nguoi{
	protected:
		string bomoncongtac,mondangday;
		int sobaibao;
	public:
		GiangVien() : Nguoi(){
		}
		void nhapGiangVien(){
			Nguoi::nhap();
			cout << "Bo mon cong tac : "; getline(cin,bomoncongtac);
			cout << "Mon dang giang day : "; getline(cin,mondangday);
			cout << "So bai bao : "; cin >> sobaibao; cin.ignore();
		}
		void inGiangVien(){
			Nguoi::in();
			cout << "Bo mon cong tac : " << bomoncongtac << endl;
			cout << "Mon dang giang day : " << mondangday << endl;
			cout << "So bai bao : " << setw(3) << setfill('0') <<sobaibao << endl;
		}
		void ghiFile(fstream& file);
		void docFile(fstream& file);
		string getBoMonCongTac(){
			return bomoncongtac;
		}
		int getSoBaiBao(){
			return sobaibao;
		}
};

void GiangVien::ghiFile(fstream& file){
	file << hten << endl << ns << endl << bomoncongtac << endl << mondangday << endl << sobaibao << endl;
}

void GiangVien::docFile(fstream& file){
	getline(file,hten);
	file >> ns; file.ignore();
	getline(file,bomoncongtac);
	getline(file,mondangday);
	file >> sobaibao; file.ignore();
}

void nhapDsGiangVien(vector<GiangVien>& v,int n){
	for(int i=0;i<n;i++){
		cout << "Nhap giang vien thu " << i + 1 << ":\n";
		GiangVien a;
		a.nhapGiangVien();
		v.push_back(a);
	}
	cout << "Da nhap thanh cong " << n << " giang vien !\n";
}

void inDsGiangVien(vector<GiangVien>& v){
	cout << "Danh sach giang vien :\n";
	for(GiangVien& x : v){
		x.inGiangVien();
		cout << "-------------\n";
	}
}


void ghiDsVaoFile(vector<GiangVien>& v, string& tenfile){
	fstream f(tenfile,ios::out | ios::app);
	if(!f){
		cerr << "Khong the mo file ghi \n";
		return;
	}
	 for(auto& gv : v) {
        gv.ghiFile(f);
    }
	f.close();
	cout << "Da ghi ds vao file : " << tenfile << endl;
}


void docDsTuFile(vector<GiangVien>& v, string& tenfile){
	fstream f(tenfile,ios::in);
	if (!f) {
        cerr << "Khong the mo file ghi \n";
        return;
    }
     GiangVien gv;
    while (!f.eof()) {
       
        gv.docFile(f);
        if (f.fail()) break; 
        v.push_back(gv);
    }
	f.close();
}

bool boMonCongTac(GiangVien &a,GiangVien &b){
	return a.getBoMonCongTac() < b.getBoMonCongTac();
}

bool soBaiBao(GiangVien &a,GiangVien &b){
	return a.getSoBaiBao() > b.getSoBaiBao();
}

void sxBoMon(vector<GiangVien>& v){
	sort(v.begin(),v.end(),boMonCongTac);
	cout << "Danh sach giang vien theo tung bo mon :\n";
	inDsGiangVien(v);
}

void sxBaiBao(vector<GiangVien>& v){
	sort(v.begin(),v.end(),soBaiBao);
	cout << "Danh sach giang vien giam dan theo so bai bao :\n";
	inDsGiangVien(v);
}

int main(){
	vector<GiangVien> ds;
	int n;
	string tenfile = "C:\\Users\\user\\OneDrive\\Máy tính\\FILE CODE\\DeCuong\\TXT\\DanhsachGiangVien";
	cout << "Nhap so luong giang vien : "; cin >> n; cin.ignore();
	nhapDsGiangVien(ds,n);
	ghiDsVaoFile(ds,tenfile);
	
	vector<GiangVien> doctuFile;
	docDsTuFile(doctuFile,tenfile);
	inDsGiangVien(doctuFile);
	
	cout << "------------------\n";
	sxBoMon(doctuFile);
	cout << "------------------\n";
	sxBaiBao(doctuFile);
}



















