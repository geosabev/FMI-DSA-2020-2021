#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
pair<int, int> edges[2000];
vector<int> parent;

int find_root(int node)
{
    if (parent[node] == -1)
        return node;

    int root = find_root(parent[node]);

    parent[node] = root;

    return root;
}

bool is_cleaned(int from, int to)
{
    int root_from = find_root(from);
    int root_to = find_root(to);

    return (root_from == root_to);
}

void connect(int from, int to)
{
    int root_from = find_root(from);
    int root_to = find_root(to);

    if (root_from != root_to)
        parent[root_to] = root_from;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    parent.resize(n);

    int a, b;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        edges[i].first = a - 1;
        edges[i].second = b - 1;
    }

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    cin >> q;

    for (int i = 0; i < m; i++)
        connect(edges[i].first, edges[i].second);

    int type;

    for (int i = 0; i < q; i++)
    {
        cin >> type >> a >> b;

        if (type == 1)
            cout << is_cleaned(a - 1, b - 1);
        else
            connect(a - 1, b - 1);
    }
}