#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int idx;
    Node* parent;

    Node(int index)
    {
        this->idx = index;
        this->parent = NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p, c;

    vector<Node*> nodes;
    vector<int> count;

    cin >> n;

    nodes.resize(n);
    count.resize(n);

    nodes[0] = new Node(0);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> p >> c;

        nodes[c] = new Node(c);

        nodes[c]->parent = nodes[p];

        if (p != 0)
        {
            Node* pivot = nodes[c];

            while (pivot->parent != NULL)
            {
                count[pivot->parent->idx]++;

                pivot = pivot->parent;
            }
        }
        else
            count[p]++;
    }

    for (int i = 0; i < n; i++)
        cout << count[i] << ' ';

}