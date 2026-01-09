#include <iostream>

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

// Code 
if (b >= e) return;

int i = b, ii = e;
int x = ls[(b + e) / 2];
while (i <= ii) {
    while (ls[i] < x) ++i;
    while (ls[ii] > x) --ii;
    
    if (i <= ii) {
        swap(ls[i], ls[ii]);
        ++i;
        --ii;
    }
}

QuickSort(ls, b, ii);
QuickSort(ls, i, e);

}   