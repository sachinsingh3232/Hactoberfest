//a program to add 2 polynomials using linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coef;
    int exp;
    struct Node *next;
};


struct Node *create(struct Node *head, int exp, int coef){
    struct Node *ptr, *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->coef = coef;
    new->exp = exp;
    new->next = NULL;
    if(head == NULL){
        head = new;
    }
    else{
        ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

void traverse(struct Node *head){
    struct Node *ptr = head;
    while(ptr!=NULL){
        printf(" %dx^%d",ptr->coef, ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *polyAddition(struct Node *head1, struct Node *head2){
    struct Node *head3, *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exp == ptr2->exp){
            head3 = create(head3, ptr1->exp, ptr1->coef+ptr2->coef);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp){
            head3 = create(head3, ptr1->exp, ptr1->coef);
            ptr1 = ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp){
            head3 = create(head3, ptr2->exp, ptr2->coef);
            ptr2 = ptr2->next;
        }
        else if(ptr1!=NULL){
            head3 = create(head3, ptr1->exp, ptr1->coef);
            ptr1 = ptr1->next;
        }
        else if(ptr2!=NULL){
         head3 = create(head3, ptr2->exp, ptr2->coef);
            ptr2 = ptr2->next;   
        }
    }
    return head3;
}


int main(){
    struct Node *head1=NULL, *head2=NULL, *head3=NULL;
    int num, coef, exp, i=0;
    while(i!=1){
        printf("\n\n1. Add element to polynimial 1\n2. Add element to polynomial 2\n3. Add the polynomials\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &num);

        switch(num){
            case 1:
                printf("Enter the coefficient and polynomial: ");
                scanf("%d %d", &coef, &exp);
                head1 = create(head1, exp, coef);
                printf("The polynomial is:");
                traverse(head1);
                break;
            case 2:
                printf("Enter the coefficient and polynomial: ");
                scanf("%d %d", &coef, &exp);
                head2 = create(head2, exp, coef);
                printf("The polynomial is:");
                traverse(head2);
                break;
            case 3:
                printf("The first polynomial is:");
                traverse(head1);
                printf("The second polynomial is:");
                traverse(head2);
                head3 = polyAddition(head1, head2);
                printf("The sum is:");
                traverse(head3);
                break;
            case 4:
                i = 1;
                printf("Exited");
                break;
            default:
                printf("Invalid input");
        }
    }

    return 0;
}