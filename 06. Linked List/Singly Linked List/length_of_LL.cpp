// Input:
// LinkedList : 1->2->3->4->5
// Output:
// 5
// Explanation:
// Count of nodes in the linked list is 5.

int getCount(struct Node* head) 
{
    int count=1;
    Node* ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
}
