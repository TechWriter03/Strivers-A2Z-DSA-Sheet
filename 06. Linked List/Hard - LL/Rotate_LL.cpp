// Input:
// LinkedList: 1 -> 2 -> 3 -> 4 -> 5
// k = 2
// Output:
// 4 -> 5 -> 1 -> 2 -> 3

ListNode* rotateRight(ListNode* head, int k)
{
    if(head==NULL || head->next==NULL)
        return head;
    ListNode* tail=head;
    int len=1;
    while(tail->next!=NULL)
    {
        tail=tail->next;
        len++;
    }
    ListNode* newTail=head;
    k%=len;
    int count=len-k;
    while(count>1)
    {
        newTail=newTail->next;
        count--;
    }
    tail->next=head;
    ListNode* newHead=newTail->next;
    newTail->next=NULL;
    return newHead;
}
