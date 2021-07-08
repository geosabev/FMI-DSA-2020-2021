#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> arr1, arr2, result;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    arr1.resize(n);
    arr2.resize(m);

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    sort(arr1.begin(), arr1.end());

    for (int i = 0; i < m; i++)
    {
        auto it = lower_bound(arr1.begin(), arr1.end(), arr2[i]);

        if (it == arr1.end())
        {
            cout << n << ' ';

            continue;
        }

        if (*it == arr2[i])
        {
            while (*prev(it) == arr2[i] && it != arr1.begin())
                it--;
        }

        cout << distance(arr1.begin(), it) << ' ';

    }

    return 0;
}
