// Input:
// head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output:
// [[7,null],[13,0],[11,4],[10,2],[1,0]]

void insertBetween(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        Node* copy=new Node(temp->val);
        copy->next=temp->next;
        temp->next=copy;
        temp=temp->next->next;
    }
}

void copyRandom(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        temp->next->random=(temp->random)?temp->random->next:NULL;
        temp=temp->next->next;
    }
}

Node* copyNext(Node* head)
{
    Node* dummy=new Node(-1), *result=dummy;
    Node* temp=head;
    while(temp!=NULL)
    {
        result->next=temp->next;
        result=result->next;
        temp->next=result->next;
        temp=temp->next;
    }
    return dummy->next;
}

Node* copyRandomList(Node* head)
{
    insertBetween(head);
    copyRandom(head);
    return copyNext(head);
}
