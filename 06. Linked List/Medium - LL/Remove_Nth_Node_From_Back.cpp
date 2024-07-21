// Input:
// LinkedList: 1 -> 2 -> 3 -> 4 -> 5
// n = 2
// Output:
// 1 -> 2 -> 3 -> 5

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* fast=head;
    for(int i=0;i<n;i++)
        fast=fast->next;
    if(fast==NULL)
        return head->next;
    ListNode* slow=head;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    ListNode* temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    return head;
}
