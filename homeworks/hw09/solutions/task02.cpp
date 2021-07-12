#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, difference = 0, max_size = 0;
    vector<int> input;
    unordered_map<int, int> indices;

    cin >> n;

    input.resize(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    indices.insert({ 0,-1 });

    for (int i = 0; i < n; i++)
    {
        if (input[i] == 1)
            difference++;
        else
            difference--;

        if (indices.count(difference) == 1)
        {
            if (i - indices[difference] > max_size)
                max_size = i - indices[difference];
        }
        else
            indices.insert({ difference, i });
    }

    cout << max_size << '\n';
}