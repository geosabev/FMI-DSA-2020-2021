#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, length;
    string name, prefix;
    unordered_map<string, int> prefixes;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name;

        length = name.length();

        bool name_found = false;

        for (int j = 1; j <= length; j++)
        {
            prefix = name.substr(0, j);

            if (prefixes.count(prefix) == 0)
            {
                prefixes[prefix] = 0;

                if (name_found == false)
                {
                    cout << prefix << '\n';

                    name_found = true;
                }
            }
        }

        prefixes[name]++;

        if (name_found == true)
            continue;

        cout << name;

        if (prefixes[name] == 1)
            cout << '\n';
        else
            cout << ' ' << prefixes[name] << '\n';
    }
}