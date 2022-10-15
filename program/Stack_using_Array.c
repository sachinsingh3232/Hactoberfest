//Vibodh Bhosure
//12-10-2022

#include<stdio.h>
#define MAX 10
typedef struct{
	int a[MAX];
	int top;
}stack;
void push(stack *s,int ele){
	if(s->top==MAX-1){
		printf("Stack Overflow\n");
		return;
	}
	s->top++;
	s->a[s->top]=ele;
}
int isempty(stack *s){
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int stacktop(stack *s){
	if(isempty(s))
		return -1;
	return s->a[s->top];
}
int pop(stack *s){
	int x;
	if(isempty(s))
	return -1;
	x=s->a[s->top];
	s->top--;
	return x;
}
void display(stack *s){
	int i;
	if(isempty(s)){
		printf("Stack Underflow\n");
	}
	else{
		for(i=s->top;i>=0;i--)
		printf("%d\t",s->a[i]);
		printf("\n");
	}
}
int main(){
	int ch,ele;
	stack s1;
	s1.top=-1;
	while(1){
		printf("1:Push\n2:Pop\n3:StackTop\n");
		printf("4:Display\n5:Exit\n");
		scanf("%d",&ch);
		if(ch==5)
			break;
		switch(ch){
			case 1: printf("Enter element to Push\n");
					scanf("%d",&ele);
					push(&s1,ele);
				break;
			case 2: ele=pop(&s1);
					if(ele==-1)
						printf("Stack UnderFlow\n");
					else
						printf("Element Popped = %d\n",ele);
				break;
			case 3: ele=stacktop(&s1);
					if(ele==-1)
						printf("Stack UnderFlow\n");
					else
						printf("Stack top element = %d\n",ele);
				break;
			case 4: display(&s1);
				break;
			default: printf("Invalid Choice\n");
		}
	}
	return 0;
}
