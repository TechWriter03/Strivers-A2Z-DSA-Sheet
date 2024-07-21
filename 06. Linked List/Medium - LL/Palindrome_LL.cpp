// Input:
// LinkedList: 1 -> 2 -> 2 -> 1
// Output:
// true

ListNode* findMiddle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* reverseList(ListNode* head)
{
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
bool isPalindrome(ListNode* head) 
{
    if(head->next==NULL)
        return true;
    ListNode* middle=findMiddle(head);
    ListNode* head2=reverseList(middle);
    ListNode* temp1=head;
    ListNode* temp2=head2;
    while(temp2!=NULL)
    {
        if(temp1->val!=temp2->val)
            return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}
