if (!T.root)
    return;

int a, b;
while (q--)
{
    cin >> a >> b;
    if (isFather(T, a, b))
    {
        cout << a << " la cha cua " << b << "\n";
    }
    else if (isFather(T, b, a))
    {
        cout << b << " la cha cua " << a << "\n";
    }
    else
    {
        cout << a << " va " << b << " khong co quan he cha con\n";
    }
}
}

bool isFather(Tree T, int father, int child)
{
    if (!T.root)
        return false;

    if (T.root->key == father)
    {
        if ((T.root->pLeft && T.root->pLeft->key == child) || T.root->pRight && T.root->pRight->key == child)
            return true;
        else
            return false;
    }

    Tree leftTree, rightTree;
    leftTree.root = T.root->pLeft;
    rightTree.root = T.root->pRight;

    return isFather(leftTree, father, child) || isFather(rightTree, father, child);
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