#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    //create new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    //make the new node points to the head node
    newNode->next = head;

    //make the new node as head node
    //so that head will always point the last inserted data
    head = newNode;
}

void pop()
{
    //temp is used to free the head node
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);

        //backup the head node
        temp = head;

        //make the head node points to the next node.
        //logically removing the node
        head = head->next;

        //free the poped element's memory
        free(temp);
    }
}

//print the linked list
void printList()
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch=1,c,val;
    printf("1->push 2->pop 3->show list\n");
    while(ch==1){
        printf("Enter choice\n");
        scanf("%d",&c);
        switch(c){
            case 1: printf("enter value\n");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: pop();
                    break;
            case 3: printList();
                    break;
        }
        printf("Enter 1/0\n");
        scanf("%d",&ch);

    }
    return 0;
}