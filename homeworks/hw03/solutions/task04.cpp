#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, Q;
int S, P;
vector<long long int> numbers;
vector<long long int> sums;

int solve()
{
    vector<long long int>::iterator lesser_or_equal = upper_bound(numbers.begin(), numbers.end(), P) - 1;

    size_t p1 = distance(numbers.begin(), lesser_or_equal);

    if ((sums[p1] - S) < 0)
        return (p1 + 1);

    vector<long long int>::iterator start_pos = lower_bound(sums.begin(), sums.begin() + p1, (sums[p1] - S));

    size_t p2 = distance(sums.begin(), start_pos);

    return (p1 - p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    scanf("%d %d", &N, &Q);

    numbers.resize(N);
    sums.resize(N);

    for (int i = 0; i < N; i++)
        scanf("%lli", &numbers[i]);

    sort(numbers.begin(), numbers.end());

    long long int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum = sum + numbers[i];
        sums[i] = sum;
    }

    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &S, &P);

        printf("%d\n", solve());
    }
}