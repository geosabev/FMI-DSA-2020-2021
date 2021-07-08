#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<long long, int> p;

const int MOD = 1000000007;

struct Edge
{
    int to;
    long long weight;

    Edge(int to = 0, long long weight = 0)
    {
        this->to = to;
        this->weight = weight;
    }
};

int n, m;
vector<Edge> g[(int)1e5];
bool visited[(int)1e5];
int paths_to[(int)1e5];

long long dist[(int)1e5];

void dijkstra()
{
    priority_queue<p, vector<p>, greater<p>> pq;

    fill(dist, dist + n, LLONG_MAX);
    fill(paths_to, paths_to + n, 0);

    dist[0] = 0;
    paths_to[0] = 1;

    pq.push({ 0,0 });

    while (pq.empty() == false)
    {
        int node = pq.top().second;

        pq.pop();

        if (visited[node] == true)
            continue;

        visited[node] = true;

        for (Edge neighbor : g[node])
        {
            if (dist[node] + neighbor.weight > dist[neighbor.to])
                continue;

            if (dist[node] + neighbor.weight < dist[neighbor.to])
                paths_to[neighbor.to] = paths_to[node];
            else
                paths_to[neighbor.to] = ((paths_to[neighbor.to] % MOD) + (paths_to[node] % MOD)) % MOD;

            dist[neighbor.to] = dist[node] + neighbor.weight;

            pq.push({ dist[neighbor.to],neighbor.to });
        }
    }

    if (dist[n - 1] == LLONG_MAX)
        dist[n - 1] = -1;

    cout << dist[n - 1] << ' ' << paths_to[n - 1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int from, to;
    long long weight;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> weight;

        g[from - 1].push_back({ to - 1, weight });
    }

    dijkstra();
}