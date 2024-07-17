// Input: 
// list1: 2 -> 4-> 3
// list2: 5 -> 6 -> 4
// Output:
// 7 -> 0 -> 8
// Explanation:
// 342 + 465 = 807.

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) 
{
    ListNode* dummy=new ListNode(-1);
    ListNode* curr=dummy;
    ListNode* temp1=head1;
    ListNode* temp2=head2;
    int sum=0,carry=0;
    while(temp1!=NULL || temp2!=NULL)
    {
        sum=carry;
        if(temp1)
            sum+=temp1->val;
        if(temp2)
            sum+=temp2->val;
        carry=sum/10;
        sum=sum%10;
        ListNode* result=new ListNode(sum);
        curr->next=result;
        curr=curr->next;
        if(temp1)
            temp1=temp1->next;
        if(temp2)
            temp2=temp2->next;
    }
    if(carry)
    {
        ListNode* result=new ListNode(carry);
        curr->next=result;
        curr=curr->next;
    }
    return dummy->next;
}
