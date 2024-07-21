// Input:
// LinkedList: 1 -> 2 -> 3 -> 4
// Output:
// 1 -> 2 -> 4

ListNode* deleteMiddle(ListNode* head) 
{
    if(head->next==NULL)
        return NULL;
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* back=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        back=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    back->next=back->next->next;
    delete slow;
    return head;
}
