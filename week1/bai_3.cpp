// Bài tập 3: Viết chương trình C++ cài đặt đối tượng hình chữ nhật trong không gian Oxy gồm có 4 
// đỉnh (theo thứ tự kim đồng hồ, đỉnh đầu tiên ở góc trái trên), trong đo mỗi đỉnh của hình chữ nhật 
// là 1 điểm (x, y) trong không gian Oxy. Sinh viên hãy cài đặt các thao tác trên đối tượng hình chữ 
// nhật này: 
// • Nhập và xuất thông tin hình chữ nhật ra màn hình console 
// • Kiểm tra xem hình chữ nhật có hợp lệ hay không dựa trên thông tin các đỉnh, xuất ra màn 
// hình kết quả kiểm tra hợp lệ hay không hợp lệ. 
// • Tính chu vi và diện tích hình chữ nhật nếu hình chữ nhật hợp lệ. 
// • Vẽ sơ đồ lớp UML cho bài tập này

#include <iostream>
#include <cmath>
using namespace std;

class ToaDo {
public:
    int x, y;
    void Nhap() {
        cout << "Nhap toa do x: "; cin >> x;
        cout << "Nhap toa do y: "; cin >> y;
    }
    void Xuat() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class HinhChuNhat {
private:
    ToaDo dinh[4]; // Lưu 4 đỉnh theo chiều kim đồng hồ

    double TinhKhoangCach(ToaDo a, ToaDo b) {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }

public:
    void Nhap() {
        cout << "Nhap 4 dinh cua hinh chu nhat (theo chieu kim dong ho, dinh 1 o goc trai tren):\n";
        for (int i = 0; i < 4; ++i) {
            cout << "Dinh " << i + 1 << ": ";
            dinh[i].Nhap();
        }
    }

    void Xuat() {
        cout << "Toa do 4 dinh cua hinh chu nhat:\n";
        for (int i = 0; i < 4; ++i) {
            cout << "Dinh " << i + 1 << ": ";
            dinh[i].Xuat();
            cout << endl;
        }
    }

    bool KiemTraHopLe() {
        double d1 = TinhKhoangCach(dinh[0], dinh[1]);
        double d2 = TinhKhoangCach(dinh[1], dinh[2]);
        double d3 = TinhKhoangCach(dinh[2], dinh[3]);
        double d4 = TinhKhoangCach(dinh[3], dinh[0]);

        double duongCheo1 = TinhKhoangCach(dinh[0], dinh[2]);
        double duongCheo2 = TinhKhoangCach(dinh[1], dinh[3]);

        // Kiểm tra cạnh đối bằng nhau và hai đường chéo bằng nhau
        return (d1 == d3 && d2 == d4 && duongCheo1 == duongCheo2);
    }

    double TinhChuVi() {
        double d1 = TinhKhoangCach(dinh[0], dinh[1]);
        double d2 = TinhKhoangCach(dinh[1], dinh[2]);
        return 2 * (d1 + d2);
    }

    double TinhDienTich() {
        double d1 = TinhKhoangCach(dinh[0], dinh[1]);
        double d2 = TinhKhoangCach(dinh[1], dinh[2]);
        return d1 * d2;
    }
};

int main() {
    HinhChuNhat hcn;
    hcn.Nhap();
    hcn.Xuat();

    if (hcn.KiemTraHopLe()) {
        cout << "Hinh chu nhat hop le.\n";
        cout << "Chu vi: " << hcn.TinhChuVi() << endl;
        cout << "Dien tich: " << hcn.TinhDienTich() << endl;
    } else {
        cout << "Hinh chu nhat khong hop le.\n";
    }

    return 0;
}
