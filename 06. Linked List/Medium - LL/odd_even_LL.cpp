// Input:
// head: 1 -> 2 -> 3 -> 4 -> 5
// Output:
// 1 -> 3 -> 5 -> 2 -> 4

ListNode* oddEvenList(ListNode* head) 
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* odd=head,*even=odd->next,*evenHead=even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}
