#include <iostream>
#include <unordered_map>
#include <vector> 
using namespace std;

int q, n, m;

void DFS(unordered_map<int, vector<int>>& g, unordered_map<int, bool>& visited, int current)
{
    visited[current] = true;

    for (auto neighbor : g[current])
    {
        if (visited[neighbor] == false)
        {
            DFS(g, visited, neighbor);
        }
    }
}

bool is_connected(unordered_map<int, vector<int>>& g, unordered_map<int, bool>& visited)
{
    int start = -1;

    if ((int)g.size() != n)
        return false;

    for (auto v : g)
    {
        if (g[v.first].size() != 0)
        {
            start = v.first;

            break;
        }
    }

    if (start == -1)
        return true;

    DFS(g, visited, start);

    for (auto v : g)
    {
        if (visited[v.first] == false)
        {
            return false;
        }
    }

    return true;
}

void check(unordered_map<int, vector<int>>& g, unordered_map<int, bool>& visited)
{
    if (is_connected(g, visited) == false)
    {
        cout << "none\n";

        return;
    }

    int odd = 0;

    for (auto v : g)
    {
        if (v.second.size() % 2 != 0)
        {
            odd++;
        }
    }

    if (odd > 2)
    {
        cout << "none\n";

        return;
    }

    if (odd == 2)
    {
        cout << "epath\n";

        return;
    }

    cout << "ecycle\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> n >> m;

        unordered_map<int, vector<int>> g;
        unordered_map<int, bool> visited;

        int a, b;

        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;

            g[a].push_back(b);
            g[b].push_back(a);
        }

        for (auto v : g)
            visited[v.first] = false;

        check(g, visited);
    }
}