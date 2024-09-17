// Input:
// 3 -> 2 -> 0 -> -4
//     /           \
//     \ _________ /
// Output:
// tail connects to node 2.

ListNode* detectCycle(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
