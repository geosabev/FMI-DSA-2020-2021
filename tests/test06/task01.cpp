#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool rotate_row = false;

struct Node
{
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    BST()
    {
        this->root = NULL;
    }

    void insert(int v)
    {
        if (this->root == NULL)
            this->root = new Node(v);
        else
            this->insert(this->root, v);
    }

    void printSFB() const
    {
        this->BFS(this->root);
    }

private:
    Node* root;

    Node* insert(Node* node, int v)
    {
        if (node == NULL)
            return new Node(v);
        else if (v < node->value)
            node->left = this->insert(node->left, v);
        else if (v > node->value)
            node->right = this->insert(node->right, v);

        return node;
    }

    void BFS(Node* node) const
    {
        if (node == NULL)
            return;

        vector<int> row;

        queue<Node*> q;

        q.push(node);

        int count = 1;

        while (q.empty() == false)
        {
            Node* front = q.front();

            q.pop();

            count--;

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);

            row.push_back(front->value);

            if (count == 0)
            {
                if (rotate_row == true)
                {
                    reverse(row.begin(), row.end());

                    rotate_row = false;
                }
                else
                    rotate_row = true;

                for (size_t i = 0; i < row.size(); i++)
                    cout << row[i] << ' ';

                row.clear();

                count = q.size();
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    int value;

    BST tree;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        tree.insert(value);
    }

    tree.printSFB();

    return 0;
}