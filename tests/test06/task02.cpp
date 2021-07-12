#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    Node* left;
    Node* right;

    int value;

    Node(int value)
    {
        this->value = value;

        this->left = NULL;
        this->right = NULL;
    }
};

bool has_grandchildren(Node* node)
{
    if (node->left->left == nullptr && node->left->right == nullptr && node->right->left == nullptr && node->right->right == nullptr)
        return false;

    return true;
}

class BST
{
public:
    BST()
    {
        this->root = NULL;
    }

    void insert(int value)
    {
        this->root = insert(this->root, value);
    }

    void deletePenultimateAndPrint()
    {
        vector<int> to_delete;

        queue<Node*> q;

        q.push(this->root);

        while (q.empty() == false)
        {
            Node* current = q.front();

            q.pop();

            if (current->left || current->right)
            {
                if (current->left && current->right)
                {
                    if (has_grandchildren(current) == false)
                    {
                        to_delete.push_back(current->value);
                    }
                }
                else
                {
                    if (current->left)
                    {
                        if (current->left->left == nullptr && current->left->right == nullptr)
                        {
                            to_delete.push_back(current->value);
                        }
                    }
                    else
                    {
                        if (current->right->left == nullptr && current->right->right == nullptr)
                        {
                            to_delete.push_back(current->value);
                        }
                    }
                }
            }

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        int s = to_delete.size();

        for (int i = 0; i < s; ++i)
            remove(this->root, to_delete[i]);

        print(this->root);
    }

private:
    Node* root;

    void print(Node* node)
    {
        if (node)
        {
            print(node->left);

            cout << node->value << " ";

            print(node->right);
        }
    }

    Node* remove(Node* node, int v)
    {
        if (node == nullptr)
            return nullptr;

        if (v > node->value)
            node->right = remove(node->right, v);
        else
        {
            if (v < node->value)
                node->left = remove(node->left, v);
            else
            {
                if (node->left == nullptr)
                {
                    Node* temp = node->right;

                    delete node;

                    return temp;
                }

                Node* to_replace = node->left;

                while (to_replace->right)
                    to_replace = to_replace->right;

                node->value = to_replace->value;

                node->left = remove(node->left, node->value);
            }
        }

        return node;
    }

    Node* insert(Node* node, int value)
    {
        if (node == NULL)
            node = new Node(value);
        else if (node->value < value)
            node->right = insert(node->right, value);
        else if (node->value > value)
            node->left = insert(node->left, value);
        else
        {
            //if we already have this value at the tree - do nothing
        }

        return node;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, value;

    cin >> n;

    BST tree;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        tree.insert(value);
    }

    tree.deletePenultimateAndPrint();

    return 0;
}