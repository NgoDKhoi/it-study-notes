#include <iostream>
#include <algorithm>
using namespace std;

void QuickSort(int [] , int, int);

int main()
{
    int *ls = NULL;
    int n;
    cin >> n;
    ls = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    QuickSort(ls, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << ls[i] << ' ';
    }
    delete [] ls;
    return 0;
}

void QuickSort(int ls[], int b, int e) {
    if (b >= e) return;

    int pivot= e;
    int i= b-1;
    for (int j=b; j<= e-1; j++) {
        if(ls[j] < ls[pivot]) {
            i++;
            swap(ls[i], ls[j]);
        }
    }
    i++;
    swap(ls[i], ls[pivot]);

    QuickSort(ls, b, i-1);
    QuickSort(ls, i+1, e);
}