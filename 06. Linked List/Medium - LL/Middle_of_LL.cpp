// Input:
// head: 1 -> 2 -> 3 -> 4 -> 5 -> 6
// Output:
// 4 -> 5 -> 6
// Explanation:
// Since the list has two middle nodes, we return the second one.

ListNode* middleNode(ListNode* head)
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
