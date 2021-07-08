#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct Edge
{
    int to, weight;

    Edge(int t = 0, int w = 0)
    {
        this->to = t;
        this->weight = w;
    }
};

int n, m, a, b;
vector<Edge> g[(int)1e4];
vector<int> dist, paths_to;
vector<bool> visited;

void topological_sort(int current, stack<int>& st)
{
    visited[current] = true;

    for (Edge neighbor : g[current])
    {
        int node = neighbor.to;

        if (visited[node] == false)
            topological_sort(node, st);
    }

    st.push(current);
}

void solve()
{
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            topological_sort(i, st);
        }
    }

    dist[a] = 0;
    paths_to[a] = 1;

    while (st.empty() == false)
    {
        int node = st.top();

        st.pop();

        if (dist[node] != INT_MIN)
        {
            for (Edge neighbor : g[node])
            {
                if (dist[neighbor.to] < dist[node] + neighbor.weight)
                {
                    dist[neighbor.to] = dist[node] + neighbor.weight;

                    paths_to[neighbor.to] = paths_to[node];
                }
                else if (dist[neighbor.to] == dist[node] + neighbor.weight)
                    paths_to[neighbor.to] += paths_to[node];
            }
        }
    }

    if (dist[b] == INT_MIN)
        cout << "-1 0\n";
    else
        cout << dist[b] << ' ' << paths_to[b] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int from, to, weight;

    cin >> n >> m;

    visited.resize(n, false);
    paths_to.resize(n, 0);
    dist.resize(n, INT_MIN);

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> weight;

        g[from].push_back({ to, weight });
    }

    cin >> a >> b;

    solve();
}