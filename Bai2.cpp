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

// Hàm NhapTuSo
// Mô tả: Nhập tử số từ bàn phím, kiểm tra nếu không phải số nguyên thì yêu cầu nhập lại
// Đầu vào: Biến nguyên x (tham chiếu)
// Đầu ra: Gán giá trị hợp lệ vào x
void NhapTuSo(long long &x) {
    while (true) {
        cout << "Nhap tu so: ";
        if (cin >> x) {
            break;
        }
        cout << "Loi! Vui long nhap mot so nguyen.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
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
// Mô tả: Nhập một phân số từ bàn phím (gồm tử số và mẫu số)
// Đầu vào: ps (tham chiếu đến một struct Phan_so)
// Đầu ra: ps.tu và ps.mau chứa phân số hợp lệ
void NhapPhanSo(Phan_so &ps) {
    NhapTuSo(ps.tu);
    NhapMauSo(ps.mau);
}

// Hàm So_Sanh
// Mô tả: So sánh hai phân số bằng cách nhân chéo tử số
// Đầu vào: ps1, ps2 (hai phân số)
// Đầu ra: Trả về 1 nếu ps1 lớn hơn, 2 nếu ps2 lớn hơn, 0 nếu bằng nhau
int So_Sanh(Phan_so ps1, Phan_so ps2) {
    long long val1 = ps1.tu * ps2.mau;
    long long val2 = ps2.tu * ps1.mau;

    if (val1 > val2) {
        return 1;
    }
    else if (val1 < val2) {
        return 2;
    }
    else {
        return 0; // Hai phân số bằng nhau
    }
}

// Hàm XuatPhanSo
// Mô tả: Xuất phân số ra màn hình, đồng thời rút gọn trước khi in
// Đầu vào: ps (một phân số)
// Đầu ra: Hiển thị phân số đã rút gọn trên màn hình
void XuatPhanSo(Phan_so ps) {
    long long u = ucl(abs(ps.tu), abs(ps.mau));
    ps.tu /= u;
    ps.mau /= u;

    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }

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

// Hàm main
// Mô tả: Nhập 2 phân số, so sánh và in ra phân số lớn nhất (đã rút gọn)
int main() {
    Phan_so ps_1, ps_2;
    cout << "Nhap phan so thu nhat:\n";
    NhapPhanSo(ps_1);
    cout << "Nhap phan so thu hai:\n";
    NhapPhanSo(ps_2);

    int kq = So_Sanh(ps_1, ps_2);

    cout << "Phan so lon hon la: ";
    if (kq == 1) {
        XuatPhanSo(ps_1);
    }
    else if (kq == 2) {
        XuatPhanSo(ps_2);
    }
    else {
        XuatPhanSo(ps_1);
    }
}
