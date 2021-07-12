#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int x, y, index;

    Node* left;
    Node* right;

    bool is_visible;

    Node(int x, int y, int idx)
    {
        this->x = x;
        this->y = y;
        this->index = idx;

        this->is_visible = true;

        this->left = NULL;
        this->right = NULL;
    }
};

bool my_compare(Node* l, Node* r)
{
    return (l->x < r->x);
}

int main()
{
    int n, l, r;

    int far_x_neg = 0, far_x_pos = 0;

    cin >> n;

    vector<Node*> nodes;

    nodes.resize(n);

    nodes[0] = new Node(0, 0, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;

        if (l != -1)
        {
            if (nodes[l] == NULL)
            {
                nodes[l] = new Node(nodes[i]->x - 1, nodes[i]->y - 1, l);
                nodes[i]->left = nodes[l];

                if (nodes[l]->x < far_x_neg)
                    far_x_neg = nodes[l]->x;
                else if (nodes[l]->x > far_x_pos)
                    far_x_pos = nodes[l]->x;
                else
                    nodes[l]->is_visible = false;
            }
            else
            {
                nodes[i]->left = nodes[l];
            }
        }

        if (r != -1)
        {
            if (nodes[r] == NULL)
            {
                nodes[r] = new Node(nodes[i]->x + 1, nodes[i]->y - 1, r);
                nodes[i]->right = nodes[r];

                if (nodes[r]->x < far_x_neg)
                    far_x_neg = nodes[r]->x;
                else if (nodes[r]->x > far_x_pos)
                    far_x_pos = nodes[r]->x;
                else
                    nodes[r]->is_visible = false;
            }
            else
            {
                nodes[i]->right = nodes[l];
            }
        }
    }

    sort(nodes.begin(), nodes.end(), my_compare);

    for (int i = 0; i < n; i++)
        if (nodes[i]->is_visible == true)
            cout << nodes[i]->index << " ";
}