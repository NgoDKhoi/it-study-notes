#include <iostream>
#include <vector>

using namespace std;

struct Hocsinh
{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x)
{
    getline(cin >> ws, x.Hodem);
    getline(cin >> ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs)
{
    cout << hs.Hodem
         << ' ' << hs.Ten
         << '\t' << hs.Gioitinh
         << '\t' << hs.Ngay
         << '/' << hs.Thang
         << '/' << hs.Nam
         << '\t' << hs.Toan
         << '\t' << hs.Van
         << '\t' << hs.Ly
         << '\t' << hs.Hoa
         << '\t' << hs.Anh
         << '\t' << hs.Sinh << endl;
    ;
}

void Output(vector<Hocsinh> ls)
{
    for (int i = 0; i < ls.size(); i++)
    {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls)
{
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++)
    {
        InputElement(hs);
        ls.push_back(hs);
    }
}

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}

void Sort(vector<Hocsinh> &ls)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 1; i < ls.size(); i++)
        {
            double dtb1 = (ls[i - 1].Toan + ls[i - 1].Van + ls[i - 1].Ly + ls[i - 1].Hoa + ls[i - 1].Sinh + ls[i - 1].Anh) / 6.0;
            double dtb2 = (ls[i].Toan + ls[i].Van + ls[i].Ly + ls[i].Hoa + ls[i].Sinh + ls[i].Anh) / 6.0;

            bool need_swap = false;
            if (dtb1 < dtb2)
                need_swap = true;
            else if (dtb1 == dtb2)
            {
                if (ls[i - 1].Nam < ls[i].Nam)
                    need_swap = true;
                else if (ls[i - 1].Nam == ls[i].Nam && ls[i - 1].Thang < ls[i].Thang)
                    need_swap = true;
                else if (ls[i - 1].Nam == ls[i].Nam && ls[i - 1].Thang == ls[i].Thang && ls[i - 1].Ngay < ls[i].Ngay)
                    need_swap = true;
            }   
            if (need_swap)
            {
                Hocsinh temp= ls[i-1];
                ls[i-1]= ls[i];
                ls[i]= temp;

                swapped = true;
            }
        }
    }
}
