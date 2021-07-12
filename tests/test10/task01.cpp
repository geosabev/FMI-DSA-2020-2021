#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int n, m, s;
vector<pair<int, int>> g[20000];

void dijkstra(int from)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);
    vector<bool> used(n, false);

    pq.push({ 0, from });

    dist[from] = 0;

    while (pq.empty() == false)
    {
        int u = pq.top().second;

        pq.pop();

        if (used[u] == true)
            continue;

        used[u] = true;

        for (auto x : g[u])
        {
            int v = x.first;
            int weight = x.second;

            if (used[v] == false && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;

                pq.push({ dist[v], v });
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (i == s - 1)
            continue;

        if (dist[i] == INT_MAX)
            cout << -1 << ' ';
        else
            cout << dist[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        g[a - 1].push_back({ b - 1, c });

        g[b - 1].push_back({ a - 1, c });
    }

    cin >> s;

    dijkstra(s - 1);
}