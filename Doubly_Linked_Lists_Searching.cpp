#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev,*next;
};

struct node *Create(struct node *lead,int value){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=value;
	if(lead==NULL){
		lead=newNode;
		lead->prev=NULL;
		lead->next=NULL;
	}
	else{
		struct node *temp=lead;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		newNode->prev=temp;
		newNode->next=NULL;
		temp->next=newNode;
	}	
	return lead;
}

void PrintingElements(struct node *lead){
	while(lead!=NULL){
		printf("Element is - %d   [%u]\n",lead->data,lead->next);
		lead=lead->next;
	}
}

void Search(struct node *lead,int value){
	int v=1;
	while(lead!=NULL){
		if(lead->data==value){
			printf("Element Found");
			v=0;break;
		}
		lead=lead->next;
	}
	if(v)
	printf("Element Not Found");
}

int main(){
	struct node *head=NULL;
	int n,i=0,value;
	printf("Enter No. of Elements to be enter - ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter Element to be insertred in node - ");
		scanf("%d",&value);
		head=Create(head,value);
	}
	PrintingElements(head);
	
	printf("\nEnter the Element to Search for - ");
	scanf("%d",&value);
	
	Search(head,value);
	return 0;
}
