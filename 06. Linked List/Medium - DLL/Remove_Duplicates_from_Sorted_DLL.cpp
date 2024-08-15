// Input:
// 1 <-> 1 <-> 2 <-> 3 <-> 4
// Output:
// 1 <-> 2 <-> 3 <-> 4

Node* removeDuplicates(struct Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* front=temp->next;
        while(front!=NULL && temp->data==front->data)
        {
            Node* duplicate=front;
            front=front->next;
            free(duplicate); 
        }
        temp->next=front;
        if(front)
            front->prev=temp;
        temp=temp->next;
    }
    return head;
}
