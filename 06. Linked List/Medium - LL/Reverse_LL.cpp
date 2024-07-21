// Input:
// LinkedList: 1 -> 2 -> 3 -> 4 -> 5
// Output:
// 5 -> 4 -> 3 -> 2 -> 1

ListNode* reverseList(ListNode* head) 
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* back=NULL;
    ListNode* temp=head;
    while(temp!=NULL)
    {
        ListNode* front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }
    return back;
}
