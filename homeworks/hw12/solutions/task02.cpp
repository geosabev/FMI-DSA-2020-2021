#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int from, to, weight;

    bool operator<(const Edge& target) const
    {
        return (this->weight < target.weight);
    }
};

int n, m, min_speed = 1, max_speed = 30000;
Edge edges[(int)1e4 + 5];
int parent[(int)1e3 + 5];

int find_root(int node)
{
    if (parent[node] == -1)
        return node;

    int root = find_root(parent[node]);

    parent[node] = root;

    return root;
}

void kruskal()
{
    sort(edges, edges + m);

    for (int i = 0; i < m; i++)
    {
        int vertices_count = 1;

        int current_min = edges[i].weight;

        for (int j = 0; j < n; j++)
            parent[j] = -1;

        for (int j = i; j < m; j++)
        {
            int root_from = find_root(edges[j].from);
            int root_to = find_root(edges[j].to);

            if (root_from == root_to)
                continue;

            parent[root_from] = root_to;

            vertices_count++;

            if (vertices_count == n)
            {
                if (edges[j].weight - current_min < max_speed - min_speed)
                {
                    min_speed = current_min;
                    max_speed = edges[j].weight;
                }

                break;
            }
        }

        if (vertices_count < n)
            break;
    }

    cout << min_speed << ' ' << max_speed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    int a, b;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> edges[i].weight;

        edges[i].from = a - 1;
        edges[i].to = b - 1;
    }

    kruskal();

    return 0;
}