#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct hocsinh {
    string hoten;
    float diemtoan;
    float diemvan;
    float diemanh;
    float diemtrungbinh;
};

// Mô tả: Hàm nhập điểm của một môn học
// Đầu vào: Tên môn học (string)
// Đầu ra: Điểm của môn học (float)
float nhapdiem(const string& mon) {
    float diem;
    do {
        cout << "Nhap diem " << mon << " (0-10): ";
        cin >> diem;
        if (cin.fail() || diem < 0 || diem > 10) {
            cout << "Diem khong hop le. Vui long nhap lai.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);
    return diem;
}

// Mô tả: Hàm nhập họ và tên học sinh
// Đầu vào: Không có
// Đầu ra: Họ và tên (string)
string nhaphoten() {
    string hoten;
    cin.ignore();
    do {
        cout << "Ho va ten: ";
        getline(cin, hoten);
        if (hoten.empty()) {
            cout << "Ho ten khong duoc de trong. Vui long nhap lai.\n";
        } else {
            break;
        }
    } while (true);
    return hoten;
}

// Mô tả: Hàm tính điểm trung bình
// Đầu vào: Điểm Toán, Văn, Anh (float)
// Đầu ra: Điểm trung bình (float)
float tinhdiemtrungbinh(float toan, float van, float anh) {
    return (toan * 2 + van + anh) / 4;
}

// Mô tả: Hàm phân loại học sinh
// Đầu vào: Điểm trung bình (float)
// Đầu ra: Loại học sinh (string)
string phanloai(float diemtb) {
    if (diemtb >= 9) return "Xuat sac";
    if (diemtb >= 8) return "Gioi";
    if (diemtb >= 6.5) return "Kha";
    if (diemtb >= 5) return "Trung binh";
    return "Yeu";
}

// Mô tả: Hàm tìm kiếm học sinh theo tên
// Đầu vào: Danh sách học sinh (vector), từ khóa (string)
// Đầu ra: Không có (xuất ra màn hình)
void timkiemtheoten(const vector<hocsinh>& danhsach, const string& tukhoa) {
    cout << "\nKet qua tim kiem: \n";
    bool found = false;
    for (const auto& hs : danhsach) {
        if (hs.hoten.find(tukhoa) != string::npos) {
            cout << "Ho ten: " << hs.hoten << ", Diem TB: " << hs.diemtrungbinh << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Thong tin hoc sinh khong ton tai.\n";
    }
}

// Mô tả: Hàm tìm học sinh có điểm Toán thấp nhất
// Đầu vào: Danh sách học sinh (vector)
// Đầu ra: Không có (xuất ra màn hình)
void diemsothapnhat(const vector<hocsinh>& danhsach) {
    float mintoan = numeric_limits<float>::max();
    for (const auto& hs : danhsach) {
        if (hs.diemtoan < mintoan) {
            mintoan = hs.diemtoan;
        }
    }
    cout << "\nHoc sinh co diem Toan thap nhat:\n";
    for (const auto& hs : danhsach) {
        if (hs.diemtoan == mintoan) {
            cout << hs.hoten << " - Diem Toan: " << hs.diemtoan << "\n";
        }
    }
}

// Mô tả: Hàm tìm học sinh có điểm trung bình cao nhất
// Đầu vào: Danh sách học sinh (vector)
// Đầu ra: Không có (xuất ra màn hình)
void diemtbcaonhat(const vector<hocsinh>& danhsach) {
    float maxdiem = -1;
    for (const auto& hs : danhsach) {
        if (hs.diemtrungbinh > maxdiem) {
            maxdiem = hs.diemtrungbinh;
        }
    }

    cout << "\nHoc sinh co diem TB cao nhat:\n";
    for (const auto& hs : danhsach) {
        if (hs.diemtrungbinh == maxdiem) {
            cout << hs.hoten << " - Diem TB: " << hs.diemtrungbinh << "\n";
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    vector<hocsinh> danhsach;

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin hoc sinh thu " << i + 1 << ":\n";
        hocsinh hs;
        hs.hoten = nhaphoten();
        hs.diemtoan = nhapdiem("Toan");
        hs.diemvan = nhapdiem("Van");
        hs.diemanh = nhapdiem("Anh");
        hs.diemtrungbinh = tinhdiemtrungbinh(hs.diemtoan, hs.diemvan, hs.diemanh);
        danhsach.push_back(hs);
    }

    cout << "\nDanh sach hoc sinh:\n";
    for (const auto& hs : danhsach) {
        cout << "Ho ten: " << hs.hoten << ", Diem TB: " << hs.diemtrungbinh
             << ", Phan loai: " << phanloai(hs.diemtrungbinh) << "\n";
    }

    diemtbcaonhat(danhsach);

    cin.ignore();
    string tukhoa;
    cout << "\nNhap ten hoc sinh can tim: ";
    getline(cin, tukhoa);
    timkiemtheoten(danhsach, tukhoa);

    diemsothapnhat(danhsach);

    return 0;
}
