#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Bắt buộc phải có thư viện này

using namespace std;

/**
 * Class (Đối tượng) để lưu trữ thông tin
 * gồm Mã Số và Số Lượng
 */
class Line
{
public:
    string MaSo;
    int SoLuong;

    // Hàm khởi tạo (constructor) để gán giá trị lúc tạo
    Line(string s, int x)
    {
        MaSo = s;
        SoLuong = x;
    }
};

/**
 * HÀM SO SÁNH (Luật của đề bài)
 * Trả về 'true' nếu 'a' nên đứng TRƯỚC 'b'.
 */
bool compareLines(const Line &a, const Line &b)
{
    // Ưu tiên 1: Sắp xếp theo Số Lượng GIẢM DẦN
    if (a.SoLuong > b.SoLuong)
    {
        return true;
    }
    if (a.SoLuong < b.SoLuong)
    {
        return false;
    }

    // Ưu tiên 2: Sắp xếp theo Mã Số TĂNG DẦN
    return a.MaSo < b.MaSo;
}


int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // --- MẢNG 1: Đọc N mã hàng ---
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // --- SẮP XẾP LẦN 1: Sắp xếp Mảng 1 để đếm ---
    // Sắp xếp các string theo thứ tự từ điển (A-Z)
    // để các mã giống nhau nằm cạnh nhau.
    sort(v.begin(), v.end());

    // --- MẢNG 2: Đếm tần suất ---
    vector<Line> lines; // Khởi tạo mảng rỗng
    
    string current_maso = v[0];
    int current_count = 1;

    // Duyệt từ phần tử thứ 2 (chỉ số 1)
    for (int i = 1; i < n; i++)
    {
        if (v[i] == current_maso)
        {
            // Nếu vẫn là mã đó, tăng số đếm
            current_count++;
        }
        else
        {
            // Nếu gặp mã mới, lưu lại mã cũ vào Mảng 2
            lines.push_back(Line(current_maso, current_count));
            
            // Bắt đầu đếm cho mã mới
            current_maso = v[i];
            current_count = 1;
        }
    }
    
    // Lưu lại nhóm mã hàng cuối cùng (rất quan trọng)
    lines.push_back(Line(current_maso, current_count));


    // --- SẮP XẾP LẦN 2: Sắp xếp Mảng 2 theo yêu cầu ---
    // Dùng hàm so sánh 'compareLines' mà ta đã định nghĩa
    sort(lines.begin(), lines.end(), compareLines);


    // --- In kết quả cuối cùng ---
    for (int i = 0; i < lines.size(); i++)
    {
        cout << lines[i].MaSo << " " << lines[i].SoLuong << "\n";
    }

    return 0;
}