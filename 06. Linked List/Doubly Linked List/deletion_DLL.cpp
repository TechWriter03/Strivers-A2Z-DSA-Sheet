// Input:
// LinkedList = 1 <--> 3 <--> 4
// x = 3
// Output:
// 1 3  
// Explanation: 
// After deleting the node at position 3 (position starts from 1), the linked list will be now as 1 <--> 3.

Node* deleteNode(Node* head, int k) 
{
    int count=1;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        if(count==k)
        {
            Node* temp=ptr;
            if(ptr->prev==NULL)
            {
                ptr=ptr->next;
                ptr->prev=NULL;
                head=head->next;
            }
            else if(ptr->next==NULL)
            {
                ptr->prev->next=NULL;
            }
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
            free(temp);
            break;
        }
        ptr=ptr->next;
        count++;
    }
    return head;
}
