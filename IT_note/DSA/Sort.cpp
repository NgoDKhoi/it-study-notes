#include <iostream>
#include <vector>

using namespace std;

void Bubble_Sort(vector<int> &v, int n)
{
    
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

void Merge_Sort(int l, int r, vector<int> &v) {
    int m= (l+r)/2;

    Merge_Sort(l, m, v);
    Merge_Sort(m+1, r, v);
    combine
}

void combine(int l, int m, int r, vector<int> &v) {
    if ()
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