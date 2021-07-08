#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input[30000] = { 0 };

void add(int amount, int element)
{
    if (amount == 0)
    {
        input[0] = element;
        return;
    }

    int pos = 0;

    while (input[pos] < element&& pos != amount)
        pos++;

    if (pos == amount)
        input[pos] = element;
    else
    {
        for (int i = amount + 1; i > pos; i--)
            input[i] = input[i - 1];

        input[pos] = element;
    }
}

int main()
{
    int N;
    cin >> N;

    int number;

    for (int i = 0; i < N; i++)
    {
        cin >> number;

        add(i, number);

        if ((i + 1) % 2 != 0)
            cout << (double)input[(i + 1) / 2] << endl;
        else
            cout << (double)((input[i / 2] + input[(i + 1) / 2]) / 2.0) << endl;
    }
}