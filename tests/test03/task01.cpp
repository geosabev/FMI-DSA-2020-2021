#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int N, Q, rotation_count = 0;
vector<long long int> input;
vector<long long int> to_find;

long long int min_pos()
{
    int min_idx = 0;

    for (int i = 1; i < N; i++)
    {
        if (input[i] < input[min_idx])
            min_idx = i;
    }

    return min_idx;
}

long long int bs(long long int key)
{
    int l = 0, r = input.size() - 1, mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (input[mid] == key)
            return mid;
        else if (input[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    input.resize(N);

    for (int i = 0; i < N; i++)
        cin >> input[i];

    rotation_count = min_pos();

    sort(input.begin(), input.end());

    cin >> Q;

    to_find.resize(Q);

    for (int i = 0; i < Q; i++)
        cin >> to_find[i];

    for (int i = 0; i < Q; i++)
    {
        long long int pos = bs(to_find[i]);

        if (pos == -1)
            cout << -1 << endl;
        else if ((pos + rotation_count) <= input.size() - 1)
            cout << pos + rotation_count << endl;
        else
            cout << pos + rotation_count - input.size() << endl;
    }
}