#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    int l, r;
};

int l_bound(vector<int>& arr, int n, int to_find)
{
    int l = 0, r = n;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (to_find <= arr[m])
            r = m;

        else
            l = m + 1;
    }

    return l;
}

int u_bound(vector<int>& arr, int n, int to_find)
{
    int l = 0, r = n;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (to_find >= arr[m])
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;

    cin >> n >> q;

    vector<int> input(n);
    vector<Pair> requests(q);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 0; i < q; i++)
        cin >> requests[i].l >> requests[i].r;

    sort(input.begin(), input.end());

    for (int i = 0; i < q; i++)
    {
        if (requests[i].l > requests[i].r)
        {
            cout << 0 << endl;
            continue;
        }

        int l_pos = l_bound(input, n, requests[i].l);
        int r_pos = u_bound(input, n, requests[i].r);

        cout << r_pos - l_pos << endl;
    }
}