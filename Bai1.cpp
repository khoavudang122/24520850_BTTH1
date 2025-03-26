#include <bits/stdc++.h>
using namespace std;

struct Phan_so {
    int tu, mau;
};

// Hàm tìm ước chung lớn nhất (ƯCLN)
int UCL(int a, int b) {
    return b == 0 ? abs(a) : UCL(b, a % b);
}

// Hàm nhập và kiểm tra tử số có phải là số nguyên
void NhapTuSo(int &x) {
    while (true) {
        cout << "Nhap tu so: ";
        cin >> x;
        if (cin.fail()) {
            cout << "Loi! Vui long nhap mot so nguyen.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
}

// Hàm nhập và kiểm tra mẫu số xem có phải là số nguyên và !=0
void NhapMauSo(int &x) {
    while (true) {
        cout << "Nhap mau so: ";
        cin >> x;
        if (cin.fail()) {
            cout << "Loi! Vui long nhap mot so nguyen.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (x == 0) {
            cout << "Mau so khong duoc bang 0! Vui long nhap lai.\n";
        } else {
            break;
        }
    }
}

// Hàm nhập phân số
void NhapPhanSo(Phan_so &ps) {
    NhapTuSo(ps.tu);
    NhapMauSo(ps.mau);
}

// Hàm rút gọn phân số
void RutGonPhanSo(Phan_so &ps) {
    if (ps.tu == 0) {
        ps.mau = 1;
        return;
    }
    int uoc = UCL(ps.tu, ps.mau);
    ps.tu /= uoc;
    ps.mau /= uoc;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

// Hàm xuất phân số
void XuatPhanSo(Phan_so ps) {
    if (ps.tu == 0) {
        cout << "Phan so: 0\n";
    } else if (ps.mau == 1) {
        cout << "Phan so: " << ps.tu << "\n";
    } else {
        cout << "Phan so: " << ps.tu << "/" << ps.mau << "\n";
    }
}

int main() {
    Phan_so ps;
    NhapPhanSo(ps);
    RutGonPhanSo(ps);
    XuatPhanSo(ps);
}
