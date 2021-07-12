#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N, M;

    long long int arr1[10000], arr2[10000];

    int arr1_count[100001], arr2_count[100001];

    long long int sum = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr1[i];

    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> arr2[i];

    for (int i = 0; i <= 100000; i++)
    {
        arr1_count[i] = 0;
        arr2_count[i] = 0;
    }

    for (int i = 0; i < N; i++)
        arr1_count[arr1[i]]++;

    for (int i = 0; i < M; i++)
        arr2_count[arr2[i]]++;

    for (int i = 0; i <= 100000; i++)
    {
        if (arr1_count[i] >= 1 && arr2_count[i] >= 1)
            sum = sum + i;
    }

    cout << sum;

    return 0;
}