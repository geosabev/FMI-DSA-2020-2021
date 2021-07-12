#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string value;
    Node* left;
    Node* right;

    Node(string v)
    {
        this->value = v;

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

    void insert(string v)
    {
        if (this->root == NULL)
            this->root = new Node(v);
        else
            insert(root, v);
    }

    bool exists(string value) const
    {
        return (find(root, value) != NULL);
    }

    void print_sorted() const
    {
        print_sorted(this->root);
    }

private:
    Node* root;

    Node* find(Node* node, string value) const
    {
        if (node == NULL)
            return node;

        if (node->value == value)
            return node;

        if (node->value < value)
            return find(node->right, value);

        return find(node->left, value);
    }

    Node* insert(Node* node, string value)
    {
        if (node == NULL)
            return new Node(value);
        if (node->value < value)
            node->right = insert(node->right, value);
        else
            node->left = insert(node->left, value);

        return node;
    }

    void print_sorted(Node* root) const
    {
        if (root == NULL)
            return;

        print_sorted(root->left);

        cout << root->value << " ";

        print_sorted(root->right);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    BST tree;

    int n, q;
    string value;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        tree.insert(value);
    }

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> value;

        if (tree.exists(value))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}