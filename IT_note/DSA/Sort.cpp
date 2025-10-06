#include <iostream>
#include <vector>

using namespace std;

void Bubble_Sort(vector<int> &v, int n)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] > v[i])
            {
                int temp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = temp;
                swapped = true;
            }
        }
    }
}

void Selection_Sort(vector<int> &v, int n)
{
    int i = 0;
    while (i < n - 1)
    {
        int Min = v[i];
        int ViTriMin = i;
        for (int j = i; j < n; j++)
        {
            if (v[j] < Min)
            {
                Min = v[j];
                ViTriMin = j;
            }
        }

        int temp = v[i];
        v[i] = v[ViTriMin];
        v[ViTriMin] = temp;

        i++;
    }
}

void Insertion_Sort(vector <int> v, int n) {
    int k = v[0];



}
int main()
{

    vector<int> v;
    int n;

    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    Bubble_Sort(v, n);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}