// Bài tập 2: Viết chương trình C++ cài đặt đối tượng điểm trong không gian Oxy, trong đó một điểm
// được định nghĩa gồm có tọa độ x và tọa độ y đều là số thực. Sinh viên hãy cài đặt các thao tác trên
// đối tượng điểm này:
// • Nhập và xuất điểm ra màn hình console
// • Tính khoảng cách giữa 2 điểm trong không gian Oxy, xuất ra thông tin khoảng cách

#include <iostream>
#include <cmath>
using namespace std;

class DiemToaDo
{
private:
    int x;
    int y;

public:
    void NhapToaDo();
    void XuatToaDo();
    double TinhKhoangCach(DiemToaDo b);
};

void DiemToaDo::NhapToaDo()
{
    cout << "Nhap toa do x: ";
    cin >> this->x;
    cout << "Nhap toa do y: ";
    cin >> this->y;
    return;
}

void DiemToaDo::XuatToaDo()
{
    cout << "Toa do x: ";
    cout << this->x << " ";
    cout << "Toa do y: ";
    cout << this->y << endl;
    return;
}

double DiemToaDo::TinhKhoangCach(DiemToaDo b){
    return sqrt(pow(x - b.x, 2) + pow(y-b.y,2));
}

int main(){
    DiemToaDo a, b;
    a.NhapToaDo();
    b.NhapToaDo();
    a.XuatToaDo();
    b.XuatToaDo();
    double kc = a.TinhKhoangCach(b);
    cout <<"KC: " << kc << endl;
    return 0;
}