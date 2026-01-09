#include <iostream>

using namespace std;

struct Node
{
    long long key;
    int height, size;
    Node *pLeft, *pRight;
};

int sz(Node *p)
{
    return p ? p->size : 0;
}

int h(Node *p)
{
    return p ? p->height : 0;
}

int balance(Node *p)
{
    return p ? h(p->pLeft) - h(p->pRight) : 0;
}

void update(Node *p)
{
    if (!p)
        return;
    p->height = 1 + max(h(p->pLeft), h(p->pRight));
    p->size = 1 + sz(p->pLeft) + sz(p->pRight);
}

Node *CreateNode(long long k)
{
    Node *p = new Node;
    if (!p)
        exit(1);
    else
    {
        p->key = k;
        p->height = 1;
        p->pLeft = nullptr;
        p->pRight = nullptr;
        p->size = 1;
    }
    return p;
}

Node *rotateRight(Node *p)
{
    Node *x = p->pLeft;
    Node *y = x->pRight;

    x->pRight = p;
    p->pLeft = y;

    update(p);
    update(x);

    return x;
}

Node *rotateLeft(Node *p)
{
    Node *x = p->pRight;
    Node *y = x->pLeft;

    x->pLeft = p;
    p->pRight = y;

    update(p);
    update(x);

    return x;
}

Node *insert(Node *root, long long k)
{
    if (!root)
    {
        return CreateNode(k);
    }

    if (k == root->key)
        return root;

    if (k < root->key)
    {
        root->pLeft = insert(root->pLeft, k);
    }
    else if (k > root->key)
    {
        root->pRight = insert(root->pRight, k);
    }

    update(root);
    int bf = balance(root);

    if (bf > 1 && k < root->pLeft->key)
        return rotateRight(root);

    if (bf < -1 && k > root->pRight->key)
        return rotateLeft(root);

    if (bf > 1 && k > root->pLeft->key)
    {
        root->pLeft = rotateLeft(root->pLeft);
        return rotateRight(root);
    }

    if (bf < -1 && k < root->pRight->key)
    {
        root->pRight = rotateRight(root->pRight);
        return rotateLeft(root);
    }

    return root;
}

bool search(Node *root, long long k)
{
    if (!root)
        return false;
    if (root->key == k)
        return true;
    if (root->key > k)
        return search(root->pLeft, k);
    if (root->key < k)
        return search(root->pRight, k);
}

Node *minNode(Node *root)
{
    while (root->pLeft)
        root = root->pLeft;
    return root;
}

Node *remove(Node *root, long long k)
{
    if (!root)
        return root;

    if (k < root->key)
        root->pLeft = remove(root->pLeft, k);
    else if (k > root->key)
        root->pRight = remove(root->pRight, k);
    else
    {
        if (!root->pLeft || !root->pRight)
        {
            Node *temp = root->pLeft ? root->pLeft : root->pRight;
            delete root;
            return temp;
        }

        Node *temp = minNode(root->pRight);
        root->key = temp->key;
        root->pRight = remove(root->pRight, temp->key);
    }

    if (root)
        update(root);
    int bf = balance(root);

    if (bf > 1 && balance(root->pLeft) >= 0)
        return rotateRight(root);

    if (bf > 1 && balance(root->pLeft) < 0)
    {
        root->pLeft = rotateLeft(root->pLeft);
        return rotateRight(root);
    }

    if (bf < -1 && balance(root->pRight) <= 0)
        return rotateLeft(root);

    if (bf < -1 && balance(root->pRight) > 0)
    {
        root->pRight = rotateRight(root->pRight);
        return rotateLeft(root);
    }

    return root;
}

int countless(Node *root, long long k)
{
    if (!root)
        return 0;

    if (k <= root->key)
        return countless(root->pLeft, k);
    else
        return sz(root->pLeft) + 1 + countless(root->pRight, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    long long b;
    Node *T = nullptr;

    while (true)
    {
        cin >> a;
        if (!a)
            break;

        cin >> b;

        if (a == 1)
            T = insert(T, b);
        else if (a == 2)
        {
            if (!search(T, b))
                cout << 0 << "\n";
            else
            {
                cout << countless(T, b) + 1 << "\n";
            }
        }
        else
            T = remove(T, b);
    }

    return 0;
}