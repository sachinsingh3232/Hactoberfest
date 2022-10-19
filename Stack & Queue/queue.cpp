#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

template <typename T>
class Queue
{
public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get_size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // print first element of queue after enqueue
    cout << "first element is : " << q.front() << endl;

    // print all elements in queue :
    cout << "Elements present in queue : ";
    while (!q.isEmpty())
    {
        // print first element in queue
        cout << q.front() << " ";
        // remove first element in queue
        q.dequeue();
    }
}
