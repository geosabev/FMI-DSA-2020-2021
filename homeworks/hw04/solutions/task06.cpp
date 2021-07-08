#include <iostream>
#include <string>
using namespace std;

int N, to_add;
string keyword;

struct Node
{
    int data;
    Node* next;
    Node* previous;

    Node(int d, Node* previous = nullptr, Node* next = nullptr)
    {
        this->data = d;
        this->previous = previous;
        this->next = next;
    }
};

class MyDoublyLinkedList
{
public:
    MyDoublyLinkedList()
        : head(nullptr), tail(nullptr), rotation_point(nullptr), count(0) {}

    void push_back(int number)
    {
        Node* new_node = new Node(number);

        if (this->head == nullptr)
        {
            this->head = new_node;
            this->rotation_point = this->head;
            this->tail = this->head;
        }
        else
        {
            new_node->previous = this->tail;
            this->tail->next = new_node;
            this->tail = this->tail->next;
        }

        this->count++;

        if (count % 2 == 0 && count > 2)
            this->rotation_point = this->rotation_point->next;
    }

    void pop_back()
    {
        if (this->count > 0)
        {
            if (this->count == 1)
            {
                this->head = nullptr;
                this->tail = nullptr;
                this->rotation_point = nullptr;

                this->count = 0;

                return;
            }

            this->tail = this->tail->previous;
            this->tail->next = nullptr;

            this->count--;

            if (this->count > 2 && this->count % 2 != 0)
                this->rotation_point = this->rotation_point->previous;
        }
    }

    void rotate()
    {
        if (this->count < 2)
            return;

        this->tail->next = this->head;
        this->head->previous = this->tail;

        Node* old_tail = this->tail;

        this->head = this->rotation_point->next;
        this->tail = this->rotation_point;

        if (count % 2 == 0)
            this->rotation_point = old_tail;
        else
            this->rotation_point = old_tail->previous;

        this->tail->next = nullptr;
        this->head->previous = nullptr;
    }

    int get_count() const
    {
        return this->count;
    }

    void print() const
    {
        if (count > 0)
        {
            Node* current = head;

            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }

            cout << endl;
        }
    }

private:
    Node* head;
    Node* tail;
    Node* rotation_point;

    int count;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    MyDoublyLinkedList l;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> keyword;

        if (keyword == "add")
        {
            cin >> to_add;

            l.push_back(to_add);
        }
        else if (keyword == "gun")
            l.pop_back();
        else
            l.rotate();
    }

    cout << l.get_count() << endl;

    l.print();
}