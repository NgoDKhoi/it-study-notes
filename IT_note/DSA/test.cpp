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
    int i, j, l, t, min;
    i = 0;
    while (i < ls.size() - 1)
    {
        min = i;
        j = i + 1;
        while (j < ls.size())
        {
            l = ls[min].Ten.size();
            if (ls[min].Ten.size() < ls[j].Ten.size())
            {
                l = ls[j].Ten.size();
            }
            t = 0;
            while (t < l)
            {
                if (t == ls[j].Ten.size())
                {
                    min = j;
                    break;
                }
                if (ls[min].Ten[t] > ls[j].Ten[t])
                {
                    min = j;
                    break;
                }
                else if (ls[min].Ten[t] < ls[j].Ten[t])
                {
                    break;
                }
                t++;
            }
            j++;
        }
        swap(ls[i], ls[min]);
        i++;
    }
}
