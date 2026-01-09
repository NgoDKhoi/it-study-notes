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

int MaxLevel(TREE root) {
    if (root == NULL) return -1;

    vector<TNode*> currentNodes;
    currentNodes.push_back(root);

    long long maxSum = 0;
    int maxLevel = 0;
    int currentLevel = 0;
    bool isFirst = true;

    while (!currentNodes.empty()) {
        long long currentSum = 0;
        vector<TNode*> nextNodes;

        for (int i = 0; i < currentNodes.size(); i++) {
            TNode* node = currentNodes[i];
            currentSum += node->key;

            if (node->left != NULL) nextNodes.push_back(node->left);
            if (node->right != NULL) nextNodes.push_back(node->right);
        }

        if (isFirst || currentSum > maxSum) {
            maxSum = currentSum;
            maxLevel = currentLevel;
            isFirst = false;
        }

        currentNodes = nextNodes;
        currentLevel++;
    }

    return maxLevel;
}

	
