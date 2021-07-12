#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

int n, m, k;
vector<pi> g[(int)1e4];

bool dijkstra(int from, int to, int cap)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<int> dist(n, INT_MAX);
    vector<bool> used(n, false);

    pq.push(make_pair(0, from));

    dist[from] = 0;

    while (pq.empty() == false)
    {
        int u = pq.top().second;

        pq.pop();

        used[u] = true;

        for (const auto& x : g[u])
        {
            int v = x.first;
            int w = x.second;

            if (used[v] == false && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;

                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[to] == INT_MAX)
        return false;

    if (dist[to] <= cap)
        return true;

    return false;
}

int bs(int from, int to)
{
    int l = 0, r = k, mid = 0, result = INT_MAX;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (dijkstra(from, to, mid) == true)
        {
            r = mid - 1;

            result = mid;
        }
        else
            l = mid + 1;
    }

    if (result == INT_MAX)
        return -1;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        g[a].push_back({ b,0 });
        g[b].push_back({ a,0 });
    }

    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;

        g[a].push_back({ b,1 });
        g[b].push_back({ a,1 });
    }

    cout << bs(n - 1, 0);
}