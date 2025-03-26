#include <bits/stdc++.h>
using namespace std;

struct Phan_so {
    long long tu;
    long long mau;
};

// Hàm ucl
// Mô tả: Tìm ước chung lớn nhất (UCLN) của hai số bằng thuật toán Euclid (đệ quy)
// Đầu vào: Hai số nguyên a và b
// Đầu ra: UCLN của a và b (luôn dương)
long long ucl(long long a, long long b) {
    return (b == 0) ? abs(a) : ucl(b, a % b);
}

// Hàm NhapMauSo
// Mô tả: Nhập mẫu số từ bàn phím, kiểm tra nếu không phải số nguyên hoặc bằng 0 thì yêu cầu nhập lại
// Đầu vào: Biến nguyên x (tham chiếu)
// Đầu ra: Gán giá trị hợp lệ vào x
void NhapMauSo(long long &x) {
    while (true) {
        cout << "Nhap mau so: ";
        if (cin >> x) {
            if (x == 0) {
                cout << "Mau so khong duoc bang 0! Vui long nhap lai.\n";
            }
            else {
                break;
            }
        }
        else {
            cout << "Loi! Vui long nhap mot so nguyen.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Hàm NhapPhanSo
// Mô tả: Nhập một phân số từ bàn phím (bỏ kiểm tra tử số, chỉ kiểm tra mẫu số)
// Đầu vào: ps (tham chiếu đến một struct Phan_so)
// Đầu ra: ps.tu và ps.mau chứa phân số hợp lệ
void NhapPhanSo(Phan_so &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    NhapMauSo(ps.mau);
}

// Hàm Rut_Gon
// Mô tả: Rút gọn phân số bằng cách chia cả tử và mẫu cho UCLN
// Đầu vào: ps (tham chiếu đến một struct Phan_so)
// Đầu ra: ps được rút gọn về dạng tối giản
void Rut_Gon(Phan_so &ps) {
    long long u = ucl(abs(ps.tu), abs(ps.mau));
    ps.tu /= u;
    ps.mau /= u;

    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

// Hàm XuatPhanSo
// Mô tả: Xuất phân số ra màn hình, đồng thời rút gọn trước khi in
// Đầu vào: ps (một phân số)
// Đầu ra: Hiển thị phân số đã rút gọn trên màn hình
void XuatPhanSo(Phan_so ps) {
    Rut_Gon(ps);

    if (ps.tu == 0) {
        cout << "0\n";
    }
    else if (ps.mau == 1) {
        cout << ps.tu << "\n";
    }
    else {
        cout << ps.tu << "/" << ps.mau << "\n";
    }
}

// Hàm Cong
// Đầu vào: Hai phân số
// Đầu ra: Tổng hai phân số
Phan_so Cong(Phan_so ps1, Phan_so ps2) {
    return {ps1.tu * ps2.mau + ps2.tu * ps1.mau, ps1.mau * ps2.mau};
}

// Hàm Tru
// Đầu vào: Hai phân số
// Đầu ra: Hiệu hai phân số
Phan_so Tru(Phan_so ps1, Phan_so ps2) {
    return {ps1.tu * ps2.mau - ps2.tu * ps1.mau, ps1.mau * ps2.mau};
}

// Hàm Nhan
// Đầu vào: Hai phân số
// Đầu ra: Nhân hai phân số
Phan_so Nhan(Phan_so ps1, Phan_so ps2) {
    return {ps1.tu * ps2.tu, ps1.mau * ps2.mau};
}

// Hàm Chia
// Đầu vào: Hai phân số
// Đầu ra: Chia hai phân số
Phan_so Chia(Phan_so ps1, Phan_so ps2) {
    return {ps1.tu * ps2.mau, ps1.mau * ps2.tu};
}

// Hàm main
int main() {
    Phan_so ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    NhapPhanSo(ps1);
    cout << "Nhap phan so thu hai:\n";
    NhapPhanSo(ps2);

    cout << "\nKet qua cac phep toan:\n";

    cout << "Tong: ";
    XuatPhanSo(Cong(ps1, ps2));

    cout << "Hieu: ";
    XuatPhanSo(Tru(ps1, ps2));

    cout << "Tich: ";
    XuatPhanSo(Nhan(ps1, ps2));

    if (ps2.tu == 0) {
        cout << "Thuong: Loi! Khong the chia cho 0.\n";
    }
    else {
        cout << "Thuong: ";
        XuatPhanSo(Chia(ps1, ps2));
    }
}
