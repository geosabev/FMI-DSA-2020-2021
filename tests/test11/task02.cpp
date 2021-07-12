#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>>& g, vector<bool>& visited, int current, vector<bool>& done)
{
    visited[current] = true;
    done[current] = true;

    for (size_t i = 0; i < g[current].size(); i++)
    {
        if (visited[g[current][i]] == true)
            return true;

        if (DFS(g, visited, g[current][i], done))
            return true;
    }

    visited[current] = false;

    return false;
}

bool has_cycle(vector<vector<int>> g)
{
    size_t size = g.size();

    vector<bool> done(size, false), visited(size, false);

    for (size_t i = 0; i < size; i++)
    {
        if (g[i].size() == 0)
            continue;

        if (done[i] == false)
        {
            for (size_t j = 0; j < size; j++)
                visited[i] = false;

            if (DFS(g, visited, i, done))
                return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, v, e, x, y, w;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v >> e;

        vector<vector<int>> g(v);

        for (int j = 0; j < e; j++)
        {
            cin >> x >> y >> w;

            g[x - 1].push_back(y - 1);
        }

        if (has_cycle(g))
            cout << '1';
        else
            cout << '0';
    }
}