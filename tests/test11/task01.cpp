#include <iostream>
#include <vector>
using namespace std;

int v, e, result = 0;
vector<vector<int>> g;
vector<bool> visited;

int DFS(int current)
{
    int count = 0;

    visited[current] = true;

    for (size_t i = 0; i < g[current].size(); i++)
    {
        if (visited[g[current][i]] == false)
        {
            int subgraph_count = DFS(g[current][i]);

            if (subgraph_count % 2 == 0)
                result++;
            else
                count += subgraph_count;
        }
    }

    return count + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> e;

    g.resize(v);
    visited.resize(v);

    int a, b;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;

        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    DFS(v - 1);

    cout << result << '\n';
}