// Implement a Program for Nth node from the end of a Linked List

#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to get the Nth node from
   the last of a linked list*/
void printNthFromLast(struct Node* head, int N)
{
    int len = 0, i;
    struct Node* temp = head;
 
    // Count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
 
    // Check if value of N is not
    // more than length of the linked list
    if (len < N)
        return;
 
    temp = head;
 
    // Get the (len-N+1)th node from the beginning
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;
 
    cout << temp->data;
 
    return;
}
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
// Driver's Code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create linked 95->75->54->25
    push(&head, 25);
    push(&head, 54);
    push(&head, 75);
    push(&head, 95);
     
      // Function call
    printNthFromLast(head, 4);
    return 0;
}

// Output = 95