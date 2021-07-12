#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair
{
    int idx;
    double l, r;
};

bool pair_compare(Pair& left, Pair& right)
{
    double eff_1 = ((left.l * left.l) / left.r);

    double eff_2 = ((right.l * right.l) / right.r);

    if (eff_1 == eff_2)
        return (left.l > right.l);

    return eff_1 > eff_2;
}

int main()
{
    int N;
    cin >> N;

    vector<Pair> arr;

    Pair to_add;
    double l, r;

    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;

        to_add.l = l;
        to_add.r = r;
        to_add.idx = i + 1;

        arr.push_back(to_add);
    }

    sort(arr.begin(), arr.end(), pair_compare);

    for (int i = 0; i < N; i++)
        cout << arr[i].idx << " ";

    return 0;
}