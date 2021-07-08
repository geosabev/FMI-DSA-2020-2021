#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculate_max_profit(const vector<int>& prices)
{
    int result = 0;

    size_t it = 0, amount = prices.size();

    while (it < amount - 1) {

        int buy_pos = 0, sell_pos = 0;

        while ((it < amount - 1) && (prices[it + 1] <= prices[it]))
            it++;

        if (it == amount - 1)
            break;

        buy_pos = it;

        it++;

        while ((it < amount) && (prices[it] >= prices[it - 1]))
            it++;

        sell_pos = it - 1;

        result += prices[sell_pos] - prices[buy_pos];
    }

    return result;
}

int main() {

    int N;

    vector<int> prices;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int price;

        cin >> price;

        prices.push_back(price);
    }

    cout << calculate_max_profit(prices) << endl;

    return 0;
}