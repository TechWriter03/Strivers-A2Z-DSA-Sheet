// Input:
// 1 -> 2 -> 3
//      |    |
//      5 <- 4
// Output:
// 4

int findLength(Node* slow, Node* fast)
{
    int count=1;
    fast=fast->next;
    while(fast!=slow)
    {
        count++;
        fast=fast->next;
    }
    return count;
}

int countNodesinLoop(struct Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return findLength(slow,fast);
    }
    return 0;
}
