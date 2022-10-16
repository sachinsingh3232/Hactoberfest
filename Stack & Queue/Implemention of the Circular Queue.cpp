#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Circular
{
public:
    int Size;
    int Rear;
    int Front;
    int *A;

protected:
private:
};
void Circular_Enqueue(Circular *Q, int e)
{
    if ((Q->Rear + 1) % Q->Size == Q->Front)
        cout << "Circular Queue is Fulled!" << endl;
    else
    {
        Q->Rear = (Q->Rear + 1) % Q->Size;
        Q->A[Q->Rear] = e;
    }
}
int Circular_Dequeue(Circular *Q)
{
    int x = -1;
    if (Q->Front == Q->Rear)
        cout << "Queue is Empty!" << endl;
    else
    {
        Q->Front = (Q->Front + 1) % Q->Size;
        x = Q->A[Q->Front];
    }
    return x;
}
void Display(Circular Q)
{
    int i = Q.Front + 1;
    do
    {
        cout << Q.A[i] << " ";
        i = (i + 1) % Q.Size;
    } while (i != (Q.Rear + 1) % Q.Size);
    cout << endl;
}
int main()
{
    Circular Q;
    cout << "Enter the Size of the Queue: ";
    cin >> Q.Size;
    Q.A = new int[Q.Size];
    Q.Front = Q.Rear = 0;
    int ch;
    do
    {
        cout << "\n\n\tCircular Queue Operations\t\n\n";
        cout << "1.Insert Element In Circular Queue(EnQueue)" << endl;
        cout << "2.Delete Element In Circular Queue(DeQueue)" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 1:
            int ele;
            cout << "Enter the Element: ";
            cin >> ele;
            Circular_Enqueue(&Q, ele);
            break;
        case 2:
            cout << "Deleted Element is: " << Circular_Dequeue(&Q) << endl;
            break;
        case 3:
            Display(Q);
            break;
        }
    } while (ch != 4);
    return 0;
}