// Input:
// 4 -> 2 -> 1 -> 3
// Output:
// 1 -> 2 -> 3 -> 4

ListNode* findMiddle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* head1,ListNode* head2)
{
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy,*temp1=head1,*temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
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

ListNode* mergeSort(ListNode* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* mid=findMiddle(head);
    ListNode* head2=mid->next;
    mid->next=NULL;
    ListNode* left=mergeSort(head);
    ListNode* right=mergeSort(head2);
    return merge(left,right);
}
