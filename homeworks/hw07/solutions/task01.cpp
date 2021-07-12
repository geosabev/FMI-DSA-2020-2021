#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int value, height;

    Node* left;
    Node* right;

    Node(int v)
    {
        this->value = v;
        this->height = 1;

        this->left = NULL;
        this->right = NULL;
    }
};

class AVL_Tree
{
public:
    AVL_Tree()
    {
        this->root = NULL;
    }

    void insert(int v)
    {
        if (this->root == NULL)
            this->root = new Node(v);
        else
            this->root = this->insert(this->root, v);
    }

    void remove(int v)
    {
        this->root = this->remove(this->root, v);
    }

    void print() const
    {
        this->DFS(this->root);
    }

private:
    Node* root;

    Node* insert(Node* node, int v)
    {
        if (node == NULL)
            return new Node(v);

        if (v < node->value)
            node->left = this->insert(node->left, v);
        else if (v > node->value)
            node->right = this->insert(node->right, v);
        else
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int new_balance = balance(node);

        if ((new_balance > 1) && (v < node->left->value))
            return this->rotate_right(node);

        if ((new_balance < -1) && (v > node->right->value))
            return this->rotate_left(node);

        if ((new_balance > 1) && (v > node->left->value))
        {
            node->left = this->rotate_left(node->left);

            return this->rotate_right(node);
        }

        if ((new_balance < -1) && (v < node->right->value))
        {
            node->right = this->rotate_right(node->right);

            return this->rotate_left(node);
        }

        return node;
    }

    Node* remove(Node* node, int v)
    {
        if (node == NULL)
            return node;
        else if (v < node->value)
            node->left = this->remove(node->left, v);
        else if (v > node->value)
            node->right = this->remove(node->right, v);
        else
        {
            if (node->left == NULL)
            {
                Node* temp = node->right;

                delete node;

                return temp;
            }

            if (node->right == NULL)
            {
                Node* temp = node->left;

                delete node;

                return temp;
            }

            Node* temp = min_node(node->right);

            node->value = temp->value;

            node->right = this->remove(node->right, temp->value);
        }

        if (node == NULL)
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int new_balance = balance(node);

        if (new_balance > 1 && balance(node->left) >= 0)
            return rotate_right(node);

        if (new_balance < -1 && balance(node->right) <= 0)
            return rotate_left(node);

        if (new_balance > 1 && balance(node->left) < 0)
        {
            node->left = rotate_left(node->left);

            return rotate_right(node);
        }

        if (new_balance < -1 && balance(node->right) > 0)
        {
            node->right = rotate_right(node->right);

            return rotate_left(node);
        }

        return node;
    }

    Node* rotate_left(Node* node)
    {
        Node* y = node->right;
        Node* T2 = y->left;

        y->left = node;
        node->right = T2;

        node->height = max(height(node->left), height(node->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* rotate_right(Node* node)
    {
        Node* x = node->left;
        Node* T2 = x->right;

        x->right = node;
        node->left = T2;

        node->height = max(height(node->left), height(node->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    int height(Node* node) const
    {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int balance(Node* node) const
    {
        if (node == NULL)
            return 0;

        return (height(node->left) - height(node->right));
    }

    void DFS(Node* node) const
    {
        if (node == NULL)
            return;

        this->DFS(node->left);

        cout << node->value << ' ';

        this->DFS(node->right);
    }

    Node* min_node(Node* node) const
    {
        if (node == NULL)
            return node;

        Node* pivot = node;

        while (pivot->left)
            pivot = pivot->left;

        return pivot;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, input;
    string keyword;

    AVL_Tree tree;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> keyword;

        if (keyword == "add")
        {
            cin >> input;

            tree.insert(input);
        }
        else if (keyword == "del")
        {
            cin >> input;

            tree.remove(input);
        }
        else
        {
            tree.print();

            cout << '\n';
        }

    }
}