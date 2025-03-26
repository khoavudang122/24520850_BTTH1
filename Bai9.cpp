#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct SoTietKiem {
    char maSo[10];
    char hoTen[50];
    char cmnd[15];
    char ngayMo[11]; // dd/mm/yyyy
    int kyHan;
    double soTienGui;
    double laiSuat;
};

// Nhap danh sach so tiet kiem
// Dau vao: mang so tiet kiem arr, so luong n
// Dau ra: cap nhat noi dung mang arr
void nhapDS(SoTietKiem arr[], int &n) {
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin so tiet kiem thu " << i + 1 << ":\n";
        cout << "Ma so: "; cin.getline(arr[i].maSo, 10);
        cout << "Ho ten: "; cin.getline(arr[i].hoTen, 50);
        cout << "CMND: "; cin.getline(arr[i].cmnd, 15);
        cout << "Ngay mo (dd/mm/yyyy): "; cin.getline(arr[i].ngayMo, 11);
        cout << "Ky han (thang): "; cin >> arr[i].kyHan;
        cout << "So tien gui: "; cin >> arr[i].soTienGui;
        cout << "Lai suat (%/nam): "; cin >> arr[i].laiSuat;
        cin.ignore();
    }
}

// Xuat danh sach so tiet kiem
// Dau vao: mang so tiet kiem arr, so luong n
// Dau ra: hien thi thong tin tung so
void xuatDS(SoTietKiem arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nSo tiet kiem thu " << i + 1 << ":\n";
        cout << "Ma so: " << arr[i].maSo << endl;
        cout << "Ho ten: " << arr[i].hoTen << endl;
        cout << "CMND: " << arr[i].cmnd << endl;
        cout << "Ngay mo: " << arr[i].ngayMo << endl;
        cout << "Ky han: " << arr[i].kyHan << " thang" << endl;
        cout << "So tien gui: " << arr[i].soTienGui << endl;
        cout << "Lai suat: " << arr[i].laiSuat << "%\n";
    }
}

// Tinh lai cho tung so tiet kiem
// Dau vao: mang so tiet kiem arr, so luong n
// Dau ra: hien thi so tien lai cho moi so
void tinhLaiChoDS(SoTietKiem arr[], int n) {
    for (int i = 0; i < n; i++) {
        double tienLai = arr[i].soTienGui * arr[i].laiSuat / 100 * arr[i].kyHan / 12;
        cout << "\nSo " << arr[i].maSo << " co tien lai: " << tienLai << endl;
    }
}

// Rut tien tu mot so tiet kiem
// Dau vao: mang arr, so luong n
// Dau ra: cap nhat soTienGui cua so tiet kiem
void rutTien(SoTietKiem arr[], int n) {
    char ma[10];
    cout << "Nhap ma so can rut tien: ";
    cin.getline(ma, 10);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].maSo, ma) == 0) {
            double tien;
            cout << "Nhap so tien muon rut: ";
            cin >> tien;
            if (tien <= arr[i].soTienGui) {
                arr[i].soTienGui -= tien;
                cout << "Rut tien thanh cong. So tien con lai: " << arr[i].soTienGui << endl;
            } else {
                cout << "So tien khong du de rut.\n";
            }
            return;
        }
    }
    cout << "Khong tim thay so tiet kiem voi ma so da nhap.\n";
}

// Tim kiem theo ma so
// Dau vao: mang arr, so luong n
// Dau ra: hien thi so tiet kiem co ma trung khop
void timKiemTheoMa(SoTietKiem arr[], int n) {
    char ma[10];
    cout << "Nhap ma so can tim: ";
    cin.getline(ma, 10);
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].maSo, ma) == 0) {
            cout << "\nTim thay so tiet kiem:\n";
            cout << "Ma so: " << arr[i].maSo << endl;
            cout << "Ho ten: " << arr[i].hoTen << endl;
            cout << "CMND: " << arr[i].cmnd << endl;
            cout << "Ngay mo: " << arr[i].ngayMo << endl;
            cout << "Ky han: " << arr[i].kyHan << endl;
            cout << "So tien gui: " << arr[i].soTienGui << endl;
            cout << "Lai suat: " << arr[i].laiSuat << endl;
            return;
        }
    }
    cout << "Khong tim thay so tiet kiem voi ma da nhap.\n";
}

// Liet ke cac so mo trong khoang thoi gian
// Dau vao: mang arr, so luong n
// Dau ra: hien thi cac so co ngay mo nam trong khoang
void lietKeTheoKhoangThoiGian(SoTietKiem arr[], int n) {
    char tuNgay[11], denNgay[11];
    cout << "Nhap ngay bat dau (dd/mm/yyyy): "; cin.ignore(); cin.getline(tuNgay, 11);
    cout << "Nhap ngay ket thuc (dd/mm/yyyy): "; cin.getline(denNgay, 11);
    cout << "\nDanh sach cac so mo trong khoang thoi gian:\n";
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].ngayMo, tuNgay) >= 0 && strcmp(arr[i].ngayMo, denNgay) <= 0) {
            cout << "- " << arr[i].maSo << " | Ngay mo: " << arr[i].ngayMo << endl;
        }
    }
}

// Sap xep theo tien gui giam dan
// Dau vao: mang arr, so luong n
// Dau ra: sap xep mang giam dan theo soTienGui
void sapXepTheoTienGiamDan(SoTietKiem arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i].soTienGui < arr[j].soTienGui) {
                SoTietKiem temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Sap xep theo ngay mo so tang dan
// Dau vao: mang arr, so luong n
// Dau ra: sap xep theo ngayMo tang dan (dung strcmp)
void sapXepTheoNgayTangDan(SoTietKiem arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[i].ngayMo, arr[j].ngayMo) > 0) {
                SoTietKiem temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    SoTietKiem arr[100];
    int n = 0;
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap danh sach so tiet kiem\n";
        cout << "2. Xuat danh sach so tiet kiem\n";
        cout << "3. Tinh lai cho tung so\n";
        cout << "4. Rut tien\n";
        cout << "5. Tim kiem so theo ma\n";
        cout << "6. Liet ke cac so mo trong khoang thoi gian\n";
        cout << "7. Sap xep danh sach theo so tien gui giam dan\n";
        cout << "8. Sap xep danh sach theo ngay mo so tang dan\n";
        cout << "9. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                nhapDS(arr, n);
                break;
            case 2:
                xuatDS(arr, n);
                break;
            case 3:
                tinhLaiChoDS(arr, n);
                break;
            case 4:
                rutTien(arr, n);
                break;
            case 5:
                timKiemTheoMa(arr, n);
                break;
            case 6:
                lietKeTheoKhoangThoiGian(arr, n);
                break;
            case 7:
                sapXepTheoTienGiamDan(arr, n);
                cout << "Da sap xep theo so tien gui giam dan.\n";
                break;
            case 8:
                sapXepTheoNgayTangDan(arr, n);
                cout << "Da sap xep theo ngay mo so tang dan.\n";
                break;
            case 9:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while(choice != 9);
}
