#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge
{
    int to, weight;

    Edge(int to = 0, int weight = 0)
    {
        this->to = to;
        this->weight = weight;
    }
};


int n, m, k, q;
vector<Edge> g[(int)1e5 + 1];
vector<int> dist;
vector<bool> visited;

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;

        visited[i] = false;
    }

    pq.push({ 0, s });

    dist[s] = 0;

    while (pq.empty() == false)
    {
        int node = pq.top().second;

        pq.pop();

        if (visited[node] == true)
            continue;

        visited[node] = true;

        for (Edge neighbor : g[node])
        {
            if (dist[node] + neighbor.weight >= dist[neighbor.to])
                continue;

            dist[neighbor.to] = dist[node] + neighbor.weight;

            pq.push({ dist[neighbor.to],neighbor.to });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int from, to, weight;

    cin >> n >> m;

    dist.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> weight;

        g[from].push_back({ to,weight });
        g[to].push_back({ from, weight });
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> to;

        g[n].push_back({ to, 0 });
        g[to].push_back({ n, 0 });
    }

    dijkstra(n);

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> from;

        cout << dist[from] << '\n';
    }
}