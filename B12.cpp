#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string hoten;
    int ns;
    double d[5], dtb;

public:
    SinhVien() {}

    double tinhDTB() {
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += d[i];
        }
        return sum / 5;
    }

    void nhap() {
        cin.ignore(); // B? dòng th?a tru?c khi nh?p chu?i
        cout << "Ho ten: ";
        getline(cin, hoten);
        cout << "Nam sinh: ";
        cin >> ns;
        for (int i = 0; i < 5; i++) {
            cout << "Diem thu " << i + 1 << ": ";
            cin >> d[i];
        }
        dtb = tinhDTB();
    }

    void in() const {
        cout << "Ho ten: " << hoten << "\tNam sinh: " << ns << endl;
        for (int i = 0; i < 5; i++) {
            cout << fixed << setprecision(1) << d[i] << "\t";
        }
        cout << endl;
        cout << "DTB: " << fixed << setprecision(1) << dtb << endl;
    }

    void ghiFile(fstream &file) const {
        file << hoten << "\n" << ns << "\n";
        for (int i = 0; i < 5; i++) {
            file << d[i] << " ";
        }
        file << "\n" << dtb << "\n";
    }

    void docFile(fstream &file) {
        getline(file, hoten);
        if (file.eof()) return;
        file >> ns;
        for (int i = 0; i < 5; i++) {
            file >> d[i];
        }
        file >> dtb;
        file.ignore(); // B? dòng th?a
    }
};

double gpa(double d) {
    if (d >= 9.0) return 4.0;
    else if (d >= 8.5) return 3.7;
    else if (d >= 8.0) return 3.5;
    else if (d >= 7.0) return 3.0;
    else if (d >= 6.5) return 2.5;
    else if (d >= 5.5) return 2.0;
    else if (d >= 5.0) return 1.5;
    else if (d >= 4.0) return 1.0;
    else return 0.0;
}

void nhapSinhVien(vector<SinhVien> &v) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien thu " << i + 1 << ":\n";
        SinhVien a;
        a.nhap();
        v.push_back(a);
    }
    cout << "Da nhap thanh cong " << n << " sinh vien.\n";
}

void inSinhVien(const vector<SinhVien> &v) {
    cout << "Danh sach sinh vien:\n";
    for (const SinhVien &x : v) {
        x.in();
        cout << "-------OK-------\n";
    }
}

void ghiDsVaoFile(const vector<SinhVien> &v, const string &tenfile) {
    fstream f(tenfile, ios::out);
    if (!f) {
        cerr << "Khong mo duoc file.\n";
        return;
    }
    for (const SinhVien &x : v) {
        x.ghiFile(f);
    }
    f.close();
    cout << "Da ghi du lieu vao file " << tenfile << endl;
}

void docDsRaFile(vector<SinhVien> &v, const string &tenfile) {
    fstream f(tenfile, ios::in);
    if (!f) {
        cerr << "Khong mo duoc file.\n";
        return;
    }
    v.clear();
    while (!f.eof()) {
        SinhVien a;
        a.docFile(f);
        if (f.fail()) break;
        v.push_back(a);
    }
    f.close();
}

void ThiLai(const vector<SinhVien> &v) {
    cout << "Danh sach sinh vien thi lai:\n";
    int cnt = 0;
    for (const SinhVien &x : v) {
        bool thiLai = false;
        for (int i = 0; i < 5; i++) {
            if (x.d[i] < 5) {
                thiLai = true;
                break;
            }
        }
        if (thiLai) {
            x.in();
            cout << "-------OK-------\n";
            cnt++;
        }
    }
    if (cnt == 0) cout << "Khong co sinh vien nao thi lai.\n";
}

void thiTotNghiep(const vector<SinhVien> &v) {
    cout << "Danh sach sinh vien thi tot nghiep:\n";
    int cnt = 0;
    for (const SinhVien &x : v) {
        bool thiTotNghiep = true;
        for (int i = 0; i < 5; i++) {
            if (x.d[i] < 5) {
                thiTotNghiep = false;
                break;
            }
        }
        if (thiTotNghiep && x.tinhDTB() < 7) {
            x.in();
            cout << "-------OK-------\n";
            cnt++;
        }
    }
    if (cnt == 0) cout << "Khong co sinh vien nao thi tot nghiep.\n";
}

void doAnTN(const vector<SinhVien> &v) {
    cout << "Danh sach sinh vien lam do an tot nghiep:\n";
    int cnt = 0;
    for (const SinhVien &x : v) {
        bool lamDATN = true;
        for (int i = 0; i < 5; i++) {
            if (x.d[i] < 5) {
                lamDATN = false;
                break;
            }
        }
        if (lamDATN && x.tinhDTB() >= 7) {
            x.in();
            cout << "-------OK-------\n";
            cnt++;
        }
    }
    if (cnt == 0) cout << "Khong co sinh vien nao lam do an tot nghiep.\n";
}

void gpaSinhVien(const SinhVien &a) {
    a.in();
    cout << "Thang diem 4:\n";
    for (int i = 0; i < 5; i++) {
        cout << gpa(a.d[i]) << " ";
    }
    cout << endl;
}

void GpaDsSV(const vector<SinhVien> &v) {
    cout << "Danh sach sinh vien:\n";
    for (const SinhVien &x : v) {
        gpaSinhVien(x);
        cout << "-------OK-------\n";
    }
}

int main() {
    vector<SinhVien> v;
    string tenfile = "danhsach.txt";

    while (true) {
        cout << "----- Menu ------\n";
        cout << "1. Nhap n sinh vien va ghi vao file\n";
        cout << "2. Hien thi danh sach sinh vien doc tu file\n";
        cout << "3. Danh sach sv thi lai\n";
        cout << "4. Danh sach sv thi tot nghiep\n";
        cout << "5. Danh sach sv lam do an tot nghiep\n";
        cout << "6. Quy doi diem sang thang diem 4\n";
        cout << "0. Thoat\n";
        cout << "---> Nhap lua chon: ";
        int lc;
        cin >> lc;
        if (lc == 1) {
            nhapSinhVien(v);
            ghiDsVaoFile(v, tenfile);
        } else if (lc == 2) {
            docDsRaFile(v, tenfile);
            inSinhVien(v);
        } else if (lc == 3) {
            ThiLai(v);
        } else if (lc == 4) {
            thiTotNghiep(v);
        } else if (lc == 5) {
            doAnTN(v);
        } else if (lc == 6) {
            GpaDsSV(v);
        } else if (lc == 0) {
            break;
        } else {
            cout << "Lua chon khong hop le!\n";
        }
    }
    return 0;
}

