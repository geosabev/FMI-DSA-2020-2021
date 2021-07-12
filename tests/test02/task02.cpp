#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    bool stat[50001] = { false };

    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
        stat[arr[i]] = true;

    for (int i = 0; i <= 50000; i++)
        if (stat[i] == true)
            cout << i << " ";

    return 0;
}