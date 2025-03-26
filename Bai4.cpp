#include <bits/stdc++.h>
using namespace std;
// Mô tả: tính sin(x)
// Đầu vào: Góc (radian)
// Đầu ra: Giá trị sin(x)
double tinhSinX(double x) {
    if (x == 0) return 0;

    double sinx = 0, sohang = x;
    int n = 1;

    do {
        sinx += sohang;
        n += 2;
        sohang = -sohang * x * x / (n * (n - 1));
    } while (fabs(sohang) > 0.0000001);

    return sinx;
}

int main() {
    double x;
    cin >> x;
    cout << fixed << setprecision(5) << tinhSinX(x);
}
