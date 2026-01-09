if (!T.root)
    return;

int a, b;
while (q--)
{
    cin >> a >> b;
    if (isBrother(T, a, b))
    {
        cout << a << " va " << b << " la anh em\n";
    }
    else
    {
        cout << a << " va " << b << " khong phai la anh em\n";
    }
}
}

bool isBrother(Tree T, int a, int b)
{
    if (!T.root)
        return false;

    if (T.root->pLeft && T.root->pRight)
    {
        int l = T.root->pLeft->key;
        int r = T.root->pRight->key;
        if ((l == a && r == b) || (l == b && r == b))
            return true;
    }

    Tree leftTree, rightTree;
    leftTree.root = T.root->pLeft;
    rightTree.root = T.root->pRight;

    return isBrother(leftTree, a, b) || isBrother(rightTree, a, b);
}

void Insert(Tree &T, int k)
{
    if (!T.root)
    {
        T.root = CreateTNode(k);
        return;
    }

    TNode *cur = T.root;
    while (true)
    {
        if (k < cur->key)
        {
            if (!cur->pLeft)
            {
                cur->pLeft = CreateTNode(k);
                return;
            }
            else
            {
                cur = cur->pLeft;
            }
        }
        else if (k > cur->key)
        {
            if (!cur->pRight)
            {
                cur->pRight = CreateTNode(k);
                return;
            }
            else
            {
                cur = cur->pRight;
            }
        }
        else
        {
            return;
        }
    }
}