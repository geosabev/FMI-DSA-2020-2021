#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counter[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 200000; i++)
        counter[i] = 0;

    int N, num;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        counter[num]++;
    }

    for (int i = 200000; i >= 0; i--)
        for (int j = 0; j < counter[i]; j++)
            cout << i << ' ';

    return 0;
}