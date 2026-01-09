#include <iostream>
#include <vector>
#include <map>



using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int MaxLevel(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);


    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cout << MaxLevel(r) << endl;

    return 0;
}

	
// Code
int height(TREE t) {
    if (t == NULL) return 0;
    return 1 + max(height(t->left), height(t->right));
}

void DFS(TREE t, int levelFromRoot, int h, map<int, int>& sum) {
    if (t == NULL) return;

    int levelFromBottom = h - levelFromRoot - 1;
    sum[levelFromBottom] += t->key;

    DFS(t->left, levelFromRoot + 1, h, sum);
    DFS(t->right, levelFromRoot + 1, h, sum);
}

int MaxLevel(TREE t) {
    if (t == NULL) return -1;

    int h = height(t);
    map<int, int> sum;

    DFS(t, 0, h, sum);

    int bestLevelFromBottom = -1;
    int maxSum = -1;

    for (auto it : sum) {
        int levelFromBottom = it.first;
        int levelFromRoot = h - levelFromBottom - 1;

        if (it.second > maxSum) {
            maxSum = it.second;
            bestLevelFromBottom = levelFromBottom;
        }
        else if (it.second == maxSum) {
            // CHỌN LEVEL NHỎ HƠN TÍNH TỪ GỐC
            int curRoot = h - levelFromBottom - 1;
            int bestRoot = h - bestLevelFromBottom - 1;

            if (curRoot < bestRoot) {
                bestLevelFromBottom = levelFromBottom;
            }
        }
    }

    return h - bestLevelFromBottom - 1;
}