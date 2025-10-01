#include <iostream>
using namespace std;

// Hàm tính ước chung lớn nhất
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

class PhanSo {
private:
    int tuso;
    int mauso;

public:
    void NhapPhanSo();
    void XuatPhanSo();
    void RutGon();
    PhanSo CongPhanSo(PhanSo b);
    PhanSo TruPhanSo(PhanSo b);
    PhanSo NhanPhanSo(PhanSo b);
    PhanSo ChiaPhanSo(PhanSo b);
};

// ---------- Hàm thành viên ----------

void PhanSo::NhapPhanSo() {
    cout << "Nhap tu so: "; cin >> tuso;
    do {
        cout << "Nhap mau so (khac 0): "; cin >> mauso;
    } while (mauso == 0);
}

void PhanSo::XuatPhanSo() {
    int choice;
    do {
        cout << "\n----- MENU XUAT PHAN SO -----\n";
        cout << "1. Dinh dang tu/mau\n";
        cout << "2. Dinh dang so thap phan\n";
        cout << "3. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Phan so: ";
            if (mauso == 1) {
                cout << tuso << endl;
            } else {
                cout << tuso << "/" << mauso << endl;
            }
            break;
        case 2:
            cout << "Dang thap phan: " << (double)tuso / mauso << endl;
            break;
        case 3:
            cout << "Thoat xuat!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 3);
}

void PhanSo::RutGon() {
    int ucln = UCLN(abs(tuso), abs(mauso));
    tuso /= ucln;
    mauso /= ucln;
    if (mauso < 0) { // Đưa dấu âm lên tử số
        tuso *= -1;
        mauso *= -1;
    }
}

PhanSo PhanSo::CongPhanSo(PhanSo b) {
    PhanSo kq;
    kq.tuso = tuso * b.mauso + mauso * b.tuso;
    kq.mauso = mauso * b.mauso;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::TruPhanSo(PhanSo b) {
    PhanSo kq;
    kq.tuso = tuso * b.mauso - mauso * b.tuso;
    kq.mauso = mauso * b.mauso;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::NhanPhanSo(PhanSo b) {
    PhanSo kq;
    kq.tuso = tuso * b.tuso;
    kq.mauso = mauso * b.mauso;
    kq.RutGon();
    return kq;
}

PhanSo PhanSo::ChiaPhanSo(PhanSo b) {
    PhanSo kq;
    kq.tuso = tuso * b.mauso;
    kq.mauso = mauso * b.tuso;
    kq.RutGon();
    return kq;
}

// ---------- Main ----------

int main() {
    PhanSo a, b, kq;

    cout << "Nhap phan so thu nhat:\n";
    a.NhapPhanSo();

    cout << "Nhap phan so thu hai:\n";
    b.NhapPhanSo();

    cout << "\n== Ket qua ==\n";

    kq = a.CongPhanSo(b);
    kq.XuatPhanSo();

    kq = a.TruPhanSo(b);
    kq.XuatPhanSo();

    kq = a.NhanPhanSo(b);
    kq.XuatPhanSo();

    kq = a.ChiaPhanSo(b);
    kq.XuatPhanSo();

    return 0;
}
