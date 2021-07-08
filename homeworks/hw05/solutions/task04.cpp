#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

long long sum_of_min_elements(vector<long long>& elements, int subarray_size)
{
    deque<size_t> min_indices;
    size_t size = elements.size();

    long long sum = 0;

    for (size_t i = 0; i < subarray_size; i++)
    {
        while (min_indices.empty() == false && elements[min_indices.back()] >= elements[i])
            min_indices.pop_back();

        min_indices.push_back(i);
    }

    sum += elements[min_indices.front()];

    for (size_t i = subarray_size; i < size; i++)
    {
        while (min_indices.empty() == false && elements[min_indices.back()] >= elements[i])
            min_indices.pop_back();

        while (min_indices.empty() == false && min_indices.front() < (i - subarray_size) + 1)
            min_indices.pop_front();

        min_indices.push_back(i);

        sum += elements[min_indices.front()];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<long long> input;
    int N, d;

    cin >> N >> d;

    input.resize(N);

    for (int i = 0; i < N; i++)
        cin >> input[i];

    cout << sum_of_min_elements(input, d);

    return 0;
}