#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, a, q;
vector<int> attacks;

bool can_lie(int x)
{
    int ship_count = 0, counter = 0;

    vector<bool> battlefield(n + 1);

    for (int i = 1; i <= x; i++)
        battlefield[attacks[i]] = true;

    for (int i = 1; i <= n; i++)
    {
        if (battlefield[i] == false)
        {
            counter++;

            if (counter == a)
            {
                ship_count++;

                i++;

                counter = 0;
            }
        }
        else
            counter = 0;
    }

    if (ship_count >= k)
        return true;

    return false;
}

int bs()
{
    int l = 1, r = q, result = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (can_lie(mid) == false)
        {
            result = mid;

            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> a >> q;

    attacks.resize(q + 1);

    for (int i = 1; i <= q; i++)
        cin >> attacks[i];

    cout << bs() << '\n';
}