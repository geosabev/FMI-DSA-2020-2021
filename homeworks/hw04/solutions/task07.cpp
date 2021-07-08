#include <iostream>
#include <string>
#include <vector>
using namespace std;

int counter = 0;

struct Node
{
    int data;
    int id;
    Node* next;
    Node* previous;

    Node(int data, int id, Node* previous = nullptr, Node* next = nullptr)
    {
        this->data = data;
        this->id = id;

        this->previous = previous;
        this->next = next;
    }
};

vector<Node*> locations;

class MyDoublyLinkedList
{
public:
    MyDoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;

        this->count = 0;
    }

    void push_back(int number)
    {
        Node* new_node = new Node(number, counter++);

        if (this->head == nullptr)
        {
            this->head = new_node;
            this->tail = this->head;

            locations[counter - 1] = this->head;
        }
        else
        {
            new_node->previous = this->tail;
            this->tail->next = new_node;
            this->tail = this->tail->next;

            locations[counter - 1] = this->tail;
        }

        this->count++;
    }

    void insert_after(Node* previous, int number)
    {
        if (previous == this->tail)
            this->push_back(number);
        else
        {
            Node* new_node = new Node(number, counter++);

            new_node->next = previous->next;

            previous->next = new_node;

            new_node->previous = previous;

            if (new_node->next != nullptr)
                new_node->next->previous = new_node;

            locations[counter - 1] = new_node;

            this->count++;
        }
    }

    Node* get_node(int id) const
    {
        if (this->count == 0)
            throw out_of_range("Empty list!");
        else if (id > counter)
            throw out_of_range("Invalid id!");
        else if (id == this->head->id)
            return this->head;
        else if (id == this->tail->id)
            return this->tail;

        return locations[id];
    }

    int destroy_sequence(Node* new_ball)
    {
        if (this->count < 3)
            return 0;
        else if ((new_ball->previous != nullptr && new_ball->previous->data != new_ball->data)
            && (new_ball->next != nullptr && new_ball->next->data != new_ball->data))
            return 0;

        int equal = 1;

        Node* start = new_ball;
        Node* end = new_ball;

        while ((start->previous != nullptr && end->next != nullptr)
            && (start->previous->data == new_ball->data) && (end->next->data == new_ball->data))
        {
            start = start->previous;
            end = end->next;

            equal += 2;
        }

        while (start->previous != nullptr && start->previous->data == new_ball->data)
        {
            start = start->previous;

            equal++;
        }

        while (end->next != nullptr && end->next->data == new_ball->data)
        {
            end = end->next;

            equal++;
        }

        if (equal < 3)
            return 0;

        this->count = this->count - equal;

        if (start == this->head && end == this->tail)
        {
            this->head = nullptr;
            this->tail = nullptr;

            this->count = 0;

            return equal;
        }

        else if (start == this->head)
        {
            end->next->previous = nullptr;

            this->head = end->next;

            return equal;
        }

        else if (end == this->tail)
        {
            start->previous->next = nullptr;
            this->tail = start->previous;

            return equal;
        }

        end->next->previous = start->previous;
        start->previous->next = end->next;

        Node* left_check = start->previous;
        Node* right_check = end->next;

        if (left_check->data == right_check->data)
            return (equal + this->destroy_sequence(left_check));

        return equal;
    }

    void print() const
    {
        if (count > 0)
        {
            Node* current = head;

            while (current != nullptr)
            {
                printf("%d ", current->data);

                current = current->next;
            }

            printf("\n");

            return;
        }

        printf("-1\n");

    }

    int count;

private:
    Node* head;
    Node* tail;
};



int shoot(MyDoublyLinkedList& list, int target_id, int ball_color)
{
    if (list.count == 0)
        return -1;

    int result = 0;

    Node* add_after = list.get_node(target_id);

    list.insert_after(add_after, ball_color);

    Node* newly_added = add_after->next;

    result = list.destroy_sequence(newly_added);

    return result;
}

int main()
{
    MyDoublyLinkedList color;
    int N, Q, to_add, target, ball_color;

    scanf("%d", &N);

    locations.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &to_add);

        color.push_back(to_add);
    }

    scanf("%d", &Q);

    locations.resize(N + Q);

    int answer;

    bool game_over = false;

    for (int i = 0; i < Q; i++)
    {
        cin >> target >> ball_color;

        if (game_over == false)
        {
            answer = shoot(color, target, ball_color);

            if (answer == -1)
            {
                printf("Game Over\n");
                game_over = true;
            }
            else
                printf("%d\n", answer);
        }
        else
            printf("Game Over\n");
    }

    color.print();
}