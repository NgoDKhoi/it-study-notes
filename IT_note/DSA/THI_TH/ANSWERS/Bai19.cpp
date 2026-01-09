#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	string Text;
	string Explanation;
};

void loadData(Word dictionary[], int &n) {
	string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin>>ws, s);
        dictionary[i].Text = s;
        getline(cin>>ws, s);
        dictionary[i].Explanation = s;
    }
}
void saveData(Word dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dictionary[i].Text << endl << dictionary[i].Explanation << endl;
    }
}
void Sort(Word [], int );

int main() {
    Word *dictionary = new Word[15000];
	int n;
	loadData(dictionary, n);
	Sort(dictionary, n);

	saveData(dictionary, n);
	delete [] dictionary;
	return 0;
}

// Code
bool lessWord(Word* a, Word* b) {
    return a->Text < b->Text;
}

int partition_ptr(Word* p[], int low, int high) {
    Word* pivot = p[high];
#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	string Text;
	string Explanation;
};

void loadData(Word dictionary[], int &n) {
	string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin>>ws, s);
        dictionary[i].Text = s;
        getline(cin>>ws, s);
        dictionary[i].Explanation = s;
    }
}
void saveData(Word dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dictionary[i].Text << endl << dictionary[i].Explanation << endl;
    }
}
void Sort(Word [], int );

int main() {
    Word *dictionary = new Word[15000];
	int n;
	loadData(dictionary, n);
	Sort(dictionary, n);

	saveData(dictionary, n);
	delete [] dictionary;
	return 0;
}


    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (lessWord(p[j], pivot)) {
            ++i;
            swap(p[i], p[j]);
        }
    }
    swap(p[i + 1], p[high]);
    return i + 1;
}

void quick_ptr(Word* p[], int low, int high) {
    while (low < high) {
        int pi = partition_ptr(p, low, high);
        if (pi - low < high - pi) {
            quick_ptr(p, low, pi - 1);
            low = pi + 1;
        } else {
            quick_ptr(p, pi + 1, high);
            high = pi - 1;
        }
    }
}

void Sort(Word w[], int n) {
    Word** p = new Word*[n];
    for (int i = 0; i < n; ++i)
        p[i] = &w[i];

    quick_ptr(p, 0, n - 1);

    Word* tmp = new Word[n];
    for (int i = 0; i < n; ++i)
        tmp[i] = *p[i];

    for (int i = 0; i < n; ++i)
        w[i] = tmp[i];

    delete[] p;
    delete[] tmp;
}