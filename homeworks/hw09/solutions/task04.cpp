#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, counter = 0;
    vector<int> in_room, needed;
    unordered_map<int, int> keys;

    cin >> n;

    in_room.resize(n);
    needed.resize(n);

    for (int i = 0; i < n - 1; i++)
        cin >> in_room[i];

    for (int i = 0; i < n - 1; i++)
        cin >> needed[i];

    for (int i = 0; i < n - 1; i++)
    {
        keys[in_room[i]]++;

        if (keys.count(needed[i]) == 1)
        {
            if (keys[needed[i]] == 0)
                counter++;
            else
                keys[needed[i]]--;
        }
        else
            counter++;
    }

    cout << counter << '\n';
}