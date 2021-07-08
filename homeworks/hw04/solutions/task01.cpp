#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node()
    {
        this->data = NULL;
        this->next = NULL;
    }

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class List
{
public:
    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_back(int d)
    {
        if (head == nullptr)
        {
            head = new Node(d);
            tail = head;
        }

        else
        {
            tail->next = new Node(d);
            tail = tail->next;
        }

    }

    void print() const
    {
        Node* current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    Node* head;
    Node* tail;
};

Node* partial_reverse(Node* head, int reverse_size, int skip_size)
{
    Node* previous = NULL;

    Node* current = head;

    Node* next = NULL;

    Node* tail = NULL;

    Node* new_head = NULL;

    Node* before = NULL;

    while (current != nullptr)
    {
        int steps_to_make = reverse_size;

        before = current;

        previous = NULL;

        while (current != nullptr && steps_to_make > 0)
        {
            next = current->next;

            current->next = previous;

            previous = current;

            current = next;

            steps_to_make--;
        }

        if (new_head == nullptr)
            new_head = previous;

        if (tail != nullptr)
            tail->next = previous;

        tail = before;

        tail->next = current;

        steps_to_make = skip_size;

        while (current != nullptr && steps_to_make > 0)
        {
            previous = current;

            current = current->next;

            steps_to_make--;
        }

        tail = previous;
    }

    return new_head;
}

void print(Node* n)
{
    Node* it = n;

    while (it != nullptr)
    {
        cout << it->data << endl;
        it = it->next;
    }
}

int main()
{
    int N, X, Y;
    int to_add;

    List l;

    cin >> N;
    cin >> X >> Y;

    for (int i = 0; i < N; i++)
    {
        cin >> to_add;

        l.push_back(to_add);
    }

    Node* reversed = partial_reverse(l.head, X, Y);

    print(reversed);
}