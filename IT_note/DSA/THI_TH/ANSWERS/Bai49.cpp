#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode * TREE;

void CreateTree(TREE &t) {
    t = NULL;
}

TNode * CreateTNode(int x) {
    TNode * p = new TNode;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x) {
    TNode *p = CreateTNode(x);

    if (t == NULL) {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->right == NULL) {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else {
            if (q->left == NULL) {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}

	
// Code 
int MaxDepth(TREE root) {
    if (root == NULL) return 0;
    int l = MaxDepth(root->left);
    int r = MaxDepth(root->right);

    return 1 + max(l, r);
}

void find(TREE root, int depth, int maxDepth, vector<int>& res) {
    if (root == NULL) return;

    if (depth == maxDepth) {
        res.push_back(root->key);
        return;
    }

    find(root->left, depth + 1, maxDepth, res);
    find(root->right, depth + 1, maxDepth, res);
}

void MaxFindingCost(TREE root) {
    if (root == NULL) return;

    int maxDepth = MaxDepth(root);

    vector<int> res;
    find(root, 1, maxDepth, res);

    sort(res.begin(), res.end());

    for (int k : res) {
        cout << k << " ";
    }
}