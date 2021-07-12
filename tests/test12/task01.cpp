#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct Edge
{
    int from, to, weight;

    Edge(int f = 0, int t = 0, int w = 0)
    {
        this->from = f;
        this->to = t;
        this->weight = w;
    }
};

int n, m, k, t, l;
vector<vector<bool>> g;
vector<Edge> edges;
unordered_set<int> bad_numbers;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    g.resize(n, vector<bool>(n, false));

    int a, b, c;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        edges.push_back({ a,b,c });
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> a;

        bad_numbers.insert(a);
    }

    for (int i = 0; i < m; i++)
    {
        if (bad_numbers.count(edges[i].weight) == 0)
        {
            g[edges[i].from][edges[i].to] = true;
        }
    }

    cin >> t;

    bool can_pass = true;

    for (int i = 0; i < t; i++)
    {
        cin >> l;

        can_pass = true;

        vector<int> path(l);

        for (int j = 0; j < l; j++)
        {
            cin >> path[j];
        }

        for (int j = 0; j < l - 1; j++)
        {
            if (g[path[j]][path[j + 1]] == false)
            {
                can_pass = false;

                break;
            }
        }

        if (can_pass == true)
            cout << '1';
        else
            cout << '0';
    }
}