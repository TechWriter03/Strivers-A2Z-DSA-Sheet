// Input: 
// 1 -> 3 -> 4 
// x = 3
// Output:
// 1 -> 3
// Explanation:
// After deleting the node at 3rd position (1-base indexing), the linked list is as 1 -> 3. 

Node* deleteNode(Node *head,int k)
{
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    Node* temp=head;
    if(k==1)
    {
        head=head->next;
        free(temp);
        return head;
    }
    int count=1;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        if(count==k)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
        count++;
    }
    return head;
}
