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
    for (int i = 0; i < n - 1; i++)
    {
        int ViTriMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[ViTriMin])
                ViTriMin = j;
        }

        int temp = v[i];
        v[i] = v[ViTriMin];
        v[ViTriMin] = temp;
    }
}

void Insertion_Sort(vector<int> &v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp= v[i];
        int j= i; 
        while (j > 0 && v[j-1] > temp) {
            v[j]= v[j-1]; 
            j--;
        }
        v[j]= temp;
    }
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

    Insertion_Sort(v, n);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}