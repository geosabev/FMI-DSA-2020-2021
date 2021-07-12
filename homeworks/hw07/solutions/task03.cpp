#include <iostream>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

set<int> s;
int min_xor = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, input, current_xor = 0;

    cin >> n;

    s.insert(0);

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        auto new_it = s.insert(input);

        if (new_it.second == true)
        {
            auto it = new_it.first;

            it--;

            current_xor = *it ^ *(++it);

            if (current_xor < min_xor)
                min_xor = current_xor;

            it++;

            if (it != s.end())
            {
                it--;

                current_xor = *it ^ *(++it);

                if (current_xor < min_xor)
                    min_xor = current_xor;
            }
        }

        cout << min_xor << '\n';
    }
}