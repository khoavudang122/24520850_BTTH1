#include <bits/stdc++.h>
using namespace std;

// Hàm tìm và đếm số lần mảng con xuất hiện trong mảng chính
void timSoLanXuatHien(const vector<int>& mangCon, const vector<int>& mangChinh) {
    int kichThuocCon = mangCon.size();
    int kichThuocChinh = mangChinh.size();

    int dem = 0;
    vector<int> viTriBatDau;

    for (int i = 0; i <= kichThuocChinh - kichThuocCon; i++) {
        bool timThay = true;
        for (int j = 0; j < kichThuocCon; j++) {
            if (mangChinh[i + j] != mangCon[j]) {
                timThay = false;
                break;
            }
        }
        if (timThay) {
            dem++;
            viTriBatDau.push_back(i);
        }
    }

    cout << dem << "\n";
    for (int viTri : viTriBatDau) {
        cout << viTri << " ";
    }
    cout << "\n";
}

int main() {
    int kichThuocCon, kichThuocChinh;
    cin >> kichThuocCon >> kichThuocChinh;

    // Kiểm tra nếu mảng rỗng TRƯỚC khi đọc mảng
    if (kichThuocCon == 0 || kichThuocChinh == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> mangCon(kichThuocCon), mangChinh(kichThuocChinh);

    for (int i = 0; i < kichThuocCon; i++) cin >> mangCon[i];
    for (int i = 0; i < kichThuocChinh; i++) cin >> mangChinh[i];

    timSoLanXuatHien(mangCon, mangChinh);

}
