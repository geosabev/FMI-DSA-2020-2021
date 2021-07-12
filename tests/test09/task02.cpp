#include <iostream>
#include <vector>
#include <list>
using namespace std;

int m, n, result = 0;
list<int> g[100000];
vector<bool> visited;

void DFS(int current)
{
    visited[current] = true;

    list<int>::iterator i;

    for (i = g[current].begin(); i != g[current].end(); i++)
        if (visited[*i] == false)
            DFS(*i);
}

void solve()
{
    for (int i = 0; i < m; i++)
    {
        if (visited[i] == false)
        {
            DFS(i);

            if (g[i].empty() == false)
                result += 1;
        }
    }

    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;

    cin >> m >> n;

    visited.resize(m);

    for (int i = 0; i < m; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    solve();
}