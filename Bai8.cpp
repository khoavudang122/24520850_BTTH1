#include <bits/stdc++.h>

using namespace std;

struct chuyenbay {
    string machuyenbay;
    string ngaybay;
    string giobay;
    string noidi;
    string noiden;
};

// Mô tả: Hàm chuyển ngày từ chuỗi sang số (YYYYMMDD)
// Đầu vào: Chuỗi ngày định dạng DD/MM/YYYY
// Đầu ra: Số nguyên đại diện cho ngày
int chuyendoi_ngay(const string& ngay) {
    int dd = (ngay[0] - '0') * 10 + (ngay[1] - '0');
    int mm = (ngay[3] - '0') * 10 + (ngay[4] - '0');
    int yyyy = (ngay[6] - '0') * 1000 + (ngay[7] - '0') * 100 + (ngay[8] - '0') * 10 + (ngay[9] - '0');
    return yyyy * 10000 + mm * 100 + dd;
}

// Mô tả: Hàm chuyển giờ từ chuỗi sang số (phút từ 00:00)
// Đầu vào: Chuỗi giờ định dạng HH:MM
// Đầu ra: Số nguyên đại diện cho phút
int chuyendoi_gio(const string& gio) {
    int hh = (gio[0] - '0') * 10 + (gio[1] - '0');
    int mm = (gio[3] - '0') * 10 + (gio[4] - '0');
    return hh * 60 + mm;
}

// Mô tả: Hàm sắp xếp chuyến bay theo ngày và giờ
// Đầu vào: Danh sách chuyến bay
// Đầu ra: Danh sách được sắp xếp theo ngày và giờ
void sapxep(vector<chuyenbay>& danhsach) {
    sort(danhsach.begin(), danhsach.end(), [](const chuyenbay& a, const chuyenbay& b) {
        int ngay_a = chuyendoi_ngay(a.ngaybay);
        int ngay_b = chuyendoi_ngay(b.ngaybay);
        if (ngay_a != ngay_b) {
            return ngay_a < ngay_b;
        } else {
            return chuyendoi_gio(a.giobay) < chuyendoi_gio(b.giobay);
        }
    });
}

// Mô tả: Hàm nhập thông tin chuyến bay
// Đầu vào: Không
// Đầu ra: Đối tượng chuyến bay
chuyenbay nhapchuyenbay() {
    chuyenbay cb;
    cout << "Nhap ma chuyen bay: ";
    getline(cin, cb.machuyenbay);
    cout << "Nhap ngay bay (DD/MM/YYYY): ";
    getline(cin, cb.ngaybay);
    cout << "Nhap gio bay (HH:MM): ";
    getline(cin, cb.giobay);
    cout << "Nhap noi di: ";
    getline(cin, cb.noidi);
    cout << "Nhap noi den: ";
    getline(cin, cb.noiden);
    return cb;
}

// Mô tả: Hàm xuất thông tin chuyến bay
// Đầu vào: Đối tượng chuyến bay
// Đầu ra: Thông tin chuyến bay được in ra màn hình
void xuatchuyenbay(const chuyenbay& cb) {
    cout << "Ma chuyen bay: " << cb.machuyenbay << endl;
    cout << "Ngay bay: " << cb.ngaybay << endl;
    cout << "Gio bay: " << cb.giobay << endl;
    cout << "Noi di: " << cb.noidi << endl;
    cout << "Noi den: " << cb.noiden << endl;
    cout << "-------------------------" << endl;
}

// Mô tả: Hàm tìm kiếm chuyến bay
// Đầu vào: Danh sách chuyến bay và từ khóa
// Đầu ra: Kết quả tìm kiếm được in ra màn hình
void timkiem(const vector<chuyenbay>& danhsach, const string& tukhoa) {
    bool found = false;
    for (const auto& cb : danhsach) {
        if (cb.machuyenbay == tukhoa || cb.noidi == tukhoa || cb.noiden == tukhoa) {
            xuatchuyenbay(cb);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay phu hop." << endl;
    }
}

// Mô tả: Hàm liệt kê chuyến bay theo nơi đi và ngày
// Đầu vào: Danh sách chuyến bay, nơi đi và ngày
// Đầu ra: Danh sách chuyến bay được in ra màn hình
void lietke(const vector<chuyenbay>& danhsach, const string& noidi, const string& ngay) {
    bool found = false;
    for (const auto& cb : danhsach) {
        if (cb.noidi == noidi && cb.ngaybay == ngay) {
            xuatchuyenbay(cb);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co chuyen bay nao phu hop." << endl;
    }
}

// Mô tả: Hàm đếm số lượng chuyến bay từ nơi đi đến nơi đến
// Đầu vào: Danh sách chuyến bay, nơi đi và nơi đến
// Đầu ra: Số lượng chuyến bay phù hợp
int demsoluong(const vector<chuyenbay>& danhsach, const string& noidi, const string& noiden) {
    int count = 0;
    for (const auto& cb : danhsach) {
        if (cb.noidi == noidi && cb.noiden == noiden) {
            ++count;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<chuyenbay> danhsach;

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin chuyen bay thu " << i + 1 << ":\n";
        danhsach.push_back(nhapchuyenbay());
    }

    sapxep(danhsach);
    cout << "\nDanh sach chuyen bay da sap xep:\n";
    for (const auto& cb : danhsach) {
        xuatchuyenbay(cb);
    }
    string tukhoa;
    cout << "\nNhap tu khoa tim kiem: ";
    getline(cin, tukhoa);
    timkiem(danhsach, tukhoa);

    string noidi, ngay;
    cout << "\nNhap noi di va ngay (DD/MM/YYYY) de liet ke: ";
    getline(cin, noidi);
    getline(cin, ngay);
    lietke(danhsach, noidi, ngay);

    string noi_di, noi_den;
    cout << "\nNhap noi di va noi den de dem so luong: ";
    getline(cin, noi_di);
    getline(cin, noi_den);
    cout << "So luong chuyen bay: " << demsoluong(danhsach, noi_di, noi_den) << endl;

    return 0;
}
