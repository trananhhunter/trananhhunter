#include <bits/stdc++.h>
using namespace std;

class Diem{
	protected:
		int x,y;
	public:
		Diem(){
			x = y = 0;
		}
		Diem(int x,int y){
			x = x;
			y = y;
		}
		void nhap(){
			cout << "Diem x : "; cin >> x;
			cout << "Diem y : "; cin >> y;
		}
		void in(){
			cout << "(" << x << ","<< y << ")\t";
		}
		double kc(Diem d2){
			return sqrt((x-d2.x)*(x-d2.x) + (y-d2.y)*(y-d2.y));
		}
};

class Tamgiac{
	private:
		Diem a,b,c;
	public:
		Tamgiac(){
		}
		void nhapTamGiac(){
			cout << "Toa do diem a : \n";
			a.nhap();
			cout << "Toa do diem b : \n";
			b.nhap();
			cout << "Toa do diem c : \n";
			c.nhap();
		}
		double chuVi(){
			return a.kc(b) + a.kc(c) + b.kc(c);
		}
		double dienTich(){
			double ab = a.kc(b);
			double ac = a.kc(c);
			double bc = b.kc(c);
			double p = (ab+ac+bc)/2;
			return sqrt(p*(p-ab)*(p-ac)*(p-bc));
		}
		void inTamGiac(){
			cout << "Tam giac co 3 diem : ";
			a.in(); b.in();
			c.in();
			cout << "Chu vi " << chuVi() << "\tDien tich " << dienTich() << endl;
		}
		void checkTamGiac();
		bool check();
};

void sapXepGiamDan(vector<Tamgiac> v){
	Tamgiac a = v[0];
	for(int i =1;i<v.size();i++){
		if(v[i].dienTich() > a.dienTich()){
			swap(v[i],a);
		}
	}
	for(int i =0;i<v.size();i++){
		cout << "Tam giac thu " << i + 1 << ":\n";
		v[i].inTamGiac();
		cout << "\n Dien tich : " << v[i].dienTich() << endl;
	}
}

void Tamgiac::checkTamGiac(){
	double ab = a.kc(b); 
	double ac = a.kc(c); 
	double bc = b.kc(c); 
	if(ab > 0 && ac > 0 && bc > 0 && (ab + ac > bc && ab + bc > ac && bc + ac > ab)){
		// tam giac vuong
		if(ab*ab + ac*ac == bc*bc || ab*ab + bc*bc == ac*ac || bc*bc + ac*ac == ab*ab){
			cout << "Tam giac vuong\n";
		}
		// tam giac can
		else if((ab == ac && ab == bc) || (ab == ac && ac == bc) || (ac == bc && bc == ab )){
			cout << "Tam giac can\n";
		}
		// tam giac deu
		else if(ab == bc && bc == ac && ab == ac){
			cout << "Tam giac deu\n";
		}
		// tam thuong
		else cout << "Tam giac thuong\n";
	}
	else{
		cout << "Khong tao thanh tam giac\n";
	}
}

bool Tamgiac::check(){
	double ab = a.kc(b); 
	double ac = a.kc(c); 
	double bc = b.kc(c); 
	if(ab > 0 && ac > 0 && bc > 0 && (ab + ac > bc && ab + bc > ac && bc + ac > ab)){
		return true;
}
	else{
		return false;
	}
}


void dayTamGiac(vector<Tamgiac> &v){
    for(auto it = v.begin(); it != v.end(); ){
        if(!it->check()){
            it = v.erase(it); // Xóa ph?n t? không h?p l? và c?p nh?t iterator
        } else {
            ++it; // Chuy?n sang ph?n t? ti?p theo
        }
    }
}

void maxTamGiac(vector<Tamgiac> v){
	Tamgiac a = v[0];
	for(int i=1;i<v.size();i++){
		if(v[i].dienTich() > a.dienTich()){
			a = v[i];
		}
	}
	cout << "Tam giac cp dien tich lon nhat la : \n";
	a.inTamGiac();
}

int main(){
    vector<Tamgiac> v;
    while(1){
        cout << "------- Tam giac ---------\n";
        cout << "1. Them tam giac \n";
        cout << "2. Hien thi tam giac\n";
        cout << "3. Sap xep dien tich giam dan\n";
        cout << "4. Tam giac dien tich max\n";
        cout << "5. Exit\n";
        cout << "Nhap lua chon : "; 
        int lc; cin >> lc;

        switch(lc){
            case 1: {
                Tamgiac a; 
                a.nhapTamGiac();
                v.push_back(a);
                cout << "Da them thanh cong\n";
                break;
            }
            case 2: {
                cout << "Danh sach tam giac:\n";
                for(int i = 0; i < v.size(); i++){
                    v[i].inTamGiac();
                    v[i].checkTamGiac();
                }
                break;
            }
            case 3: {
                dayTamGiac(v);
                sapXepGiamDan(v);
                break;
            }
            case 4: {
                dayTamGiac(v);
                maxTamGiac(v);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
}


























