//reverse a linked list
#include<iostream>
using namespace std;
//linked list node
struct Node{
  int info;
  struct Node* next;
  Node(int info)
  {
    this->info=info;
    next=NULL;
  }};
struct LinkedList{
  Node* head;
  LinkedList()
  {
    head=NULL;}
  //func to reverse the linked lint
  void reverse()
  {
    Node* current =head;
    Node* prev =NULL, *next=NULL;
    while(current!=NULL)
    {
      //store next
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
    }
    head=prev;
  }
  void print()
  {struct Node* temp=head;
   while(temp!=NULL)
   {
     cout<<temp->info<<" ";
     temp=temp->next;
   }
  }
  void push(int data)
  {
    Node* temp=new Node(data);
    temp>next=head;
    head=temp;
  }
};
//driver code
int main()
{
  LinkedList ll;
  ll.push(1);
  ll.push(2);
  ll.push(3);
  ll.push(4);
  ll.push(5);
  cout<< "given linked list";
  ll.print();
  ll.reverse();
  cout<<"reverse linked list";
  ll.print();
  return 0;
}
  
  
