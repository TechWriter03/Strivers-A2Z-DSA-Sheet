// Input:
// LinkedList: 9 -> 9 -> 9
// Output:
// 1 -> 0 -> 0 -> 0

int add(Node* temp)
{
    if(temp==NULL)
        return 1;
    int carry=add(temp->next);
    temp->data=temp->data+carry;
    if(temp->data==10)
    {
        temp->data=0;
        return 1;
    }
    else
    {
        return 0;
    }
}
Node* addOne(Node *head) 
{
    int carry=add(head);
    if(carry)
    {
        Node* newHead=new Node(1);
        newHead->next=head;
        return newHead;
    }
    return head;
}
