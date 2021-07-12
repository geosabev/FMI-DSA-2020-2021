#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> first, last;
int next_pos;

void dfs(int node)
{
    first[node] = next_pos;

    next_pos++;

    for (size_t i = 0; i < graph[node].size(); i++)
        dfs(graph[node][i]);

    last[node] = next_pos;

    next_pos++;
}

bool is_parent(int p, int c)
{
    return ((first[p] <= first[c]) && (last[c] <= last[p]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    int p, c;

    cin >> n;

    graph.resize(n);
    first.resize(n);
    last.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> p >> c;

        graph[p].push_back(c);
    }

    next_pos = 0;

    dfs(0);

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> p >> c;

        if (is_parent(p, c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}