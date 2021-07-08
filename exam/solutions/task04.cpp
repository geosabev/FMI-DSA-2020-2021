#include <iostream>
#include <climits>
#include <map>
#include <vector>
using namespace std;

int n;
vector<int> arr;
map<int, int> last_pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    arr.resize(n);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int last_idx = 0;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];

        last_idx = max(last_pos[num], last_idx);

        result = max(result, i - last_idx + 1);

        last_pos[num] = i + 1;
    }

    cout << result;
}