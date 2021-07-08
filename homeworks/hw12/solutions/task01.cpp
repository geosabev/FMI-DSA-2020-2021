#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> visited;
vector<pair<int, int>> edges;

int traverse(int node)
{
    int count = 1;

    visited[node] = true;

    for (size_t i = 0; i < g[node].size(); i++)
    {
        if (visited[g[node][i]] == false)
            count += traverse(g[node][i]);
    }

    return count;
}

bool is_connected(int current_hour)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;

        g[i].clear();
    }

    for (int i = 0; i < current_hour; i++)
    {
        g[edges[i].first].push_back(edges[i].second);

        g[edges[i].second].push_back(edges[i].first);
    }

    return (traverse(0) == n);
}

int BS()
{
    int l = 0, r = m, result = -1, mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (is_connected(mid))
        {
            result = mid;

            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    g.resize(n);
    visited.resize(n);


    int a, b;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        edges.push_back({ a - 1, b - 1 });
    }

    cout << BS();
}