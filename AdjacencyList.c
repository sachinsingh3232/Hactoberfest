#include <stdio.h>
#include <stdlib.h>
int i;

struct node
{
    int data;
    struct node* link;
}*temp=NULL;

struct list
{
    int vdata;
    struct node *start;//points to the node structure
}*trav=NULL;
 struct list *vertexblock[100];//array of pointers

void nodecreate(int data,struct list* pointer)
{

    if(pointer->start==NULL)
    {
        pointer->start=(struct node*) malloc (sizeof(struct node));
        pointer->start->data=data;
        pointer->start->link=NULL;
    }
    else if(pointer->start->link==NULL)
    {
        struct node* new = (struct node*) malloc (sizeof(struct node));
        new->data=data;
        printf("The end node reached is %d",pointer->start->data);
        printf("\n");
        pointer->start->link=new;
        new->link=NULL;
    }
    else
    {
        struct node* newn = (struct node*) malloc (sizeof(struct node));//creating a pointer to structure using newn
        newn->data=data;
        temp=pointer->start;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        printf("The end node reached is %d",temp->data);
        printf("\n");
        temp->link=newn;
        newn->link=NULL;
    }
}

void listcreate(struct list* ptr )
{
    ptr->start=NULL;
    int neighbours,data;
    printf("How many neighbours does this vertex has: ");
    scanf("%d",&neighbours);
    if(neighbours!=0)
    {
        printf("\nEnter the neighbours\n");
        for(i=1;i<=neighbours;i++)
            {
                printf("Neighbour %d: ",i);
                scanf("%d",&data);
                printf("\n");
                nodecreate(data,ptr);
            }       
    }        
}

void graphcreate(int n)
{
    int iteration;//A good practice is while a func call another function in a loop better use different variables in each function
    
    for(i=0;i<n;i++)
        vertexblock[i]=NULL;
    
    for(iteration=0;iteration<n;iteration++)
    {
        vertexblock[iteration]=(struct list* ) malloc(sizeof(struct list));
        printf("Enter the value of vertex: ");
        scanf("%d",&vertexblock[iteration]->vdata);
        printf("\n");
        listcreate(vertexblock[iteration]);
    }  
}

void displaygraph(int n)
{
    for(i=0;i<n;i++)
    {
        printf("%d",vertexblock[i]->vdata);
            temp=vertexblock[i]->start;
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    printf(" -> %d",temp->data);
                    temp=temp->link;
                }
            } printf("\n");  
    }
}

void main()
{
    int n;
    printf("You're going to create a graph\n");
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    graphcreate(n);
    printf("The adjacency list for the graph is:\n");
    displaygraph(n);
}