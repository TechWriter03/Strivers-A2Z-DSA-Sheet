// Input:
// LinkedList1: 1 -> 2 -> 4
// LinkedList2: 1 -> 3 -> 4
// Output:
// 1 -> 1 -> 2 -> 3 -> 4 -> 4

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
{
    ListNode* dummy=new ListNode(-1), *temp=dummy;
    ListNode* temp1=head1, *temp2=head2;
    while(temp1 && temp2)
    {
        if(temp1->val<=temp2->val)
        {
            temp->next=temp1;
            temp1=temp1->next;
        }
        else
        {
            temp->next=temp2;
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    if(temp1)
        temp->next=temp1;
    else
        temp->next=temp2;
    return dummy->next;
}
