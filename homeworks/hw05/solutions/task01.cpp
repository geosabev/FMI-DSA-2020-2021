#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MinStack
{
public:
    void push(int x)
    {
        this->elements.push(x);

        if (this->min_elements.empty())
            this->min_elements.push(x);
        else
        {
            if (this->min_elements.top() > x)
                this->min_elements.push(x);
            else
                this->min_elements.push(this->min_elements.top());
        }
    }

    void pop()
    {
        if (this->elements.empty())
            return;

        this->elements.pop();
        this->min_elements.pop();
    }

    int peek() const
    {
        if (this->elements.empty())
            throw out_of_range("Empty!");

        return this->elements.top();
    }

    int min() const
    {
        if (this->elements.empty())
            throw out_of_range("Empty!");

        return this->min_elements.top();
    }

private:
    stack<int> elements;
    stack<int> min_elements;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string keyword;

    MinStack st;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> keyword;

        if (keyword == "push")
        {
            int to_push;

            cin >> to_push;

            st.push(to_push);
        }
        else if (keyword == "pop")
            st.pop();
        else if (keyword == "peek")
            cout << st.peek() << endl;
        else
            cout << st.min() << endl;
    }
}