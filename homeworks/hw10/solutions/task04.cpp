#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<string> dictionary;
vector<int> g[26];
vector<bool> visited(26, false);
stack<int> st;

void DFS(int current)
{
    visited[current] = true;

    for (size_t i = 0; i < g[current].size(); i++)
    {
        if (visited[g[current][i]] == false)
            DFS(g[current][i]);
    }

    st.push(current);
}

void solve()
{
    for (int i = 0; i < 26; i++)
    {
        if (g[i].size() > 0 && visited[i] == false)
            DFS(i);
    }

    vector<char> alphabet;

    while (st.empty() == false)
    {
        alphabet.push_back(st.top() + 'a');

        st.pop();
    }

    for (size_t i = 0; i < alphabet.size(); i++)
        cout << alphabet[i] << ' ';
}

void construct()
{
    for (int i = 0; i < n - 1; i++)
    {
        string w1 = dictionary[i];
        string w2 = dictionary[i + 1];

        size_t s1 = w1.size();
        size_t s2 = w2.size();

        size_t idx = 0;

        while (idx < min(s1, s2))
        {
            if (w1[idx] != w2[idx])
            {
                g[w1[idx] - 'a'].push_back((w2[idx] - 'a'));

                break;
            }

            idx++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    dictionary.resize(n);

    for (int i = 0; i < n; i++)
        cin >> dictionary[i];

    construct();

    solve();
}