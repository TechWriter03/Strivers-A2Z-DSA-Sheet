// Input:
// LinkedList: 2 -> 2 -> 0 -> 1
// Output:
// 0 -> 1 -> 2 -> 2

Node* segregate(Node *head) 
{
    Node* dummyZero=new Node(-1),*zero=dummyZero;
    Node* dummyOne=new Node(-1),*one=dummyOne;
    Node* dummyTwo=new Node(-1),*two=dummyTwo;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else
        {
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    Node* oneHead=dummyOne->next;
    Node* twoHead=dummyTwo->next;
    zero->next=(oneHead)?oneHead:twoHead;
    one->next=twoHead;
    two->next=NULL;
    return dummyZero->next;
}
