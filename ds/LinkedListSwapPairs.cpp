/* C program to pairwise swap elements in a given linked list */
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to pairwise swap elements of a linked list */
struct node* pairWiseSwap(struct node *head)
{
    if ( head == NULL || head->next == NULL)
        return head;
        
    struct node *curr = head, *next;
    bool firstNode = 1;
 
    /* Traverse further only if there are at-least two nodes left */
    while (curr->next->next != NULL)
    {
        //struct node* temp = curr;
        next = curr->next;
        curr->next = next->next;
        next->next = curr;
        curr = curr->next->next;
        
        //printf("%d ", curr->data);
        if (firstNode)
        {
            head = next;
            firstNode = false;
        }
    
    }
    return head;
}
 
/* UTILITY FUNCTIONS */
/* Function to swap two integers */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
/* Function to add a node at the begining of Linked List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
              (struct node*) malloc(sizeof(struct node));
  
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
       node = node->next;
    }
}
 
/* Driver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("Linked list before calling  pairWiseSwap()\n");
    printList(start);
 
    start = pairWiseSwap(start);
 
    printf("\nLinked list after calling  pairWiseSwap()\n");
    printList(start);
 
    return 0;
}