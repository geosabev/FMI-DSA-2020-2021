#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int v)
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

    void print_level_based() const
    {
        BFS(this->root);
    }

    void insert(int value)
    {
        if (this->root == NULL)
            this->root = new Node(value);
        else
            insert(this->root, value);
    }

    void remove_kth(int k)
    {
        int count = 0;

        int to_remove = (this->get_kth_largest(this->root, k, count))->value;

        this->remove(this->root, to_remove);
    }

private:
    Node* root;

    Node* insert(Node* node, int v)
    {
        if (node == NULL)
            return new Node(v);
        else if (node->value < v)
            node->right = insert(node->right, v);
        else
            node->left = insert(node->left, v);

        return node;
    }

    Node* get_kth_largest(Node* node, int k, int& counter) const
    {
        if (node == NULL)
            return node;

        Node* right = get_kth_largest(node->right, k, counter);

        if (right != NULL)
            return right;

        counter++;

        if (counter == k)
            return node;

        return get_kth_largest(node->left, k, counter);
    }

    Node* leftmost_node(Node* node)
    {
        Node* current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    Node* remove(Node* node, int v)
    {
        if (node == NULL)
            return NULL;
        if (v > node->value)
            node->right = remove(node->right, v);
        else if (v < node->value)
            node->left = remove(node->left, v);
        else
        {
            if (node->left == NULL)
            {
                Node* temp = node->right;

                delete node;

                return temp;
            }
            else if (node->right == NULL)
            {
                Node* temp = node->left;

                delete node;

                return temp;
            }

            Node* temp = leftmost_node(node->right);

            node->value = temp->value;

            node->right = remove(node->right, temp->value);
        }

        return node;
    }

    void BFS(Node* node) const
    {
        queue<Node*> q;

        q.push(node);

        while (q.empty() == false)
        {
            Node* top = q.front();

            cout << top->value << ' ';

            if (top->left)
                q.push(top->left);

            if (top->right)
                q.push(top->right);

            q.pop();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    BST tree;

    int n, k, input;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        tree.insert(input);
    }

    tree.remove_kth(k);

    tree.print_level_based();
}