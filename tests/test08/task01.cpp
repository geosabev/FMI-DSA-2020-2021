#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> weights;

bool check(int target)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        if (weights[l] + weights[r] > target)
            r--;
        else if (weights[l] + weights[r] < target)
            l++;
        else
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    weights.resize(n);

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    sort(weights.begin(), weights.end());

    for (int i = 0; i < n; i++)
    {
        if (check(weights[i]))
        {
            cout << "true" << '\n';

            return 0;
        }
    }

    cout << "false" << '\n';
}