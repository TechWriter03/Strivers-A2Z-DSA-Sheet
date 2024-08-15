// Input:
// 2 <-> 2 <-> 10 <-> 8 <-> 4 <-> 2 <-> 5 <-> 2
// 2
// Output: 
// 10 <-> 8 <-> 4 <-> 5

void deleteAllOccurOfX(struct Node** head_ref, int x)
{
    Node* temp=*head_ref;
    while(temp!=NULL)
    {
        Node* back=temp->prev;
        Node* front=temp->next;
        if(temp->data==x)
        {
            if(temp==*head_ref)
                *head_ref=(*head_ref)->next;
            if(back)
                back->next=front;
            if(front)
                front->prev=back;
            free(temp);
        }
        temp=temp->next;
    }
}
