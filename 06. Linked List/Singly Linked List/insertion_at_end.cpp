// Input: 
// LinkedList: 1->2->3->4->5
// x = 6
// Output: 
// 1->2->3->4->5->6
// Explanation: 
// We can see that 6 is inserted at the end of the linkedlist.

Node* insertAtEnd(Node* head, int x) 
{
    Node* temp=new Node(x);
    if(head==NULL)
        return temp;
    Node* ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=temp;
    return head;
}  
