#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

void CreateTree(TREE &t)
{
    t = NULL;
}

TNode *CreateTNode(int x)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x)
{
    TNode *p = CreateTNode(x);

    if (t == NULL)
    {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL)
    {
        if (x == q->key)
            return;
        if (x > q->key)
        {
            if (q->right == NULL)
            {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else
        {
            if (q->left == NULL)
            {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t)
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int SearchNode(TREE &t, int x)
{
    TREE q = t;
    while (q != NULL)
    {
        if (x == q->key)
        {
            return 1;
        }

        if (x < q->key)
        {
            q = q->left;
        }
        else
        {
            q = q->right;
        }
    }
    return 0;
}

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}

void Duyet(TREE t, vector<int> &result, int currentLevel, int &maxLevel) {
    if (t == NULL) return;

    TREE q = t;
    if (currentLevel >= maxLevel) {
        if (currentLevel > maxLevel) {
            result.clear();
            maxLevel= currentLevel;
        }
        result.push_back(q->key);
    }
    Duyet(q->left, result, currentLevel + 1, maxLevel);
    Duyet(q->right, result, currentLevel + 1, maxLevel);
}

void MaxFindingCost(TREE t)
{
    vector<int> result;
    int maxLevel = 0;

    Duyet(t, result, 0, maxLevel);

    for (int i=0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}


