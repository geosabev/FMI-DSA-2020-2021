#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, q, s, e, max_v = INT_MIN;
vector<pair<int, int>> volunteers;
vector<int> amount;

void precalculate()
{
    amount.resize(max_v + 1);

    for (int i = 0; i < n; i++)
    {
        int current_start = volunteers[i].first;
        int current_end = volunteers[i].second;

        amount[current_start]++;
        amount[current_end + 1]--;
    }

    for (int i = 1; i <= max_v; i++)
        amount[i] = amount[i] + amount[i - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    volunteers.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;

        if (s > max_v)
            max_v = s;

        if (e > max_v)
            max_v = e;

        volunteers[i] = { s,e };
    }

    precalculate();

    for (int i = 0; i < q; i++)
    {
        cin >> s;

        if (s < 0 || s > max_v)
            cout << 0 << ' ';
        else
            cout << amount[s] << ' ';
    }
}