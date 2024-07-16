// Input:
// LinkedList: 2<->4<->5
// p = 2, x = 6 
// Output:
// 2 4 5 6
// Explanation: 
// p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 3 (0-based indexing).

void addNode(Node* head, int pos, int data)
{
    int count=0;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        if(count==pos)
        {
            Node* temp=new Node(data);
            if(ptr->next==NULL)
            {
                ptr->next=temp;
                temp->prev=ptr;
            }
            else
            {
                Node* front=ptr->next;
                ptr->next=temp;
                temp->prev=ptr;
                temp->next=front;
                front->prev=temp;
            }
            break;
        }
        ptr=ptr->next;
        count++;
    }
}
