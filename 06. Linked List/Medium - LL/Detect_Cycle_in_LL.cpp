// Input:
// 3 -> 2 -> 0 -> -4
//     /           \
//     \ _________ /
// Output:
// true

bool hasCycle(ListNode* head) 
{
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
