// Input:
// LinkedList: 3 <--> 4 <--> 5
// Output:
// 5 <--> 4 <--> 3

Node* reverseDLL(Node * head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* temp=head;
    Node* back=NULL;
    while(temp!=NULL)
    {
        back=temp->prev;
        temp->prev=temp->next;
        temp->next=back;
        temp=temp->prev;
    }
    return back->prev;
}
