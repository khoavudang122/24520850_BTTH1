#include <iostream>

using namespace std;

struct N {
    int d, m, y;
};

// Kiểm tra năm nhuận
// Đầu vào: Một số nguyên y (năm cần kiểm tra)
// Đầu ra: Trả về true nếu là năm nhuận, false nếu không
bool Nhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Trả về số ngày trong một tháng
// Đầu vào: Số nguyên m (tháng), số nguyên y (năm)
// Đầu ra: Số ngày trong tháng m của năm y
int NgayTrongThang(int m, int y) {
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && Nhuan(y)) return 29;
    return ngayTrongThang[m];
}

// Kiểm tra xem ngày nhập vào có hợp lệ không
// Đầu vào: Một biến N chứa ngày, tháng, năm
// Đầu ra: Trả về true nếu ngày hợp lệ, false nếu không
bool HopLe(N n) {
    if (n.m < 1 || n.m > 12 || n.d < 1 || n.d > NgayTrongThang(n.m, n.y)) return false;
    return true;
}

// Nhập ngày từ bàn phím và kiểm tra hợp lệ
// Đầu vào: Không có (nhập từ bàn phím)
// Đầu ra: Gán giá trị hợp lệ vào biến n
void Nhap(N &n) {
    do {
        cout << "Nhap ngay: ";
        cin >> n.d;
        cout << "Nhap thang: ";
        cin >> n.m;
        cout << "Nhap nam: ";
        cin >> n.y;
        if (!HopLe(n)) cout << "Nhap khong hop le, vui long nhap lai!\n";
    } while (!HopLe(n));
}

// Tìm ngày kế tiếp
// Đầu vào: Một biến N chứa ngày, tháng, năm
// Đầu ra: Trả về ngày kế tiếp của ngày nhập vào
N NgayKeTiep(N n) {
    if (n.d < NgayTrongThang(n.m, n.y)) n.d++;
    else {
        n.d = 1;
        if (n.m < 12) n.m++;
        else {
            n.m = 1;
            n.y++;
        }
    }
    return n;
}

// Tìm ngày trước đó
// Đầu vào: Một biến N chứa ngày, tháng, năm
// Đầu ra: Trả về ngày trước đó của ngày nhập vào
N NgayTruoc(N n) {
    if (n.d > 1) n.d--;
    else {
        if (n.m > 1) {
            n.m--;
            n.d = NgayTrongThang(n.m, n.y);
        } else {
            n.m = 12;
            n.y--;
            n.d = 31;
        }
    }
    return n;
}

// Tính ngày thứ bao nhiêu trong năm
// Đầu vào: Một biến N chứa ngày, tháng, năm
// Đầu ra: Trả về số thứ tự của ngày trong năm
int ThuTuNgay(N n) {
    int thu = n.d;
    for (int i = 1; i < n.m; i++) thu += NgayTrongThang(i, n.y);
    return thu;
}

// Xuất kết quả
// Đầu vào: Một biến N chứa ngày, tháng, năm
// Đầu ra: In ra ngày kế tiếp, ngày trước đó, thứ tự ngày trong năm
void Xuat(N n) {
    N next = NgayKeTiep(n);
    N prev = NgayTruoc(n);
    int thu = ThuTuNgay(n);

    cout << "Ngay tiep theo: " << next.d << "/" << next.m << "/" << next.y << "\n";
    cout << "Ngay truoc do: " << prev.d << "/" << prev.m << "/" << prev.y << "\n";
    cout << "Ngay thu " << thu << " trong nam\n";
}

// Hàm chính
// Đầu vào: Nhập ngày, tháng, năm từ bàn phím
// Đầu ra: Xuất ngày kế tiếp, ngày trước đó, số thứ tự trong năm
int main() {
    N n;
    Nhap(n);
    Xuat(n);
}
