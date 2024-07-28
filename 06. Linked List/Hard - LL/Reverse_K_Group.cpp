// Input:
// Linked List: 1 -> 2 -> 3 -> 4 -> 5
// k = 3
// Output:
// 3 -> 2 -> 1 -> 4 -> 5

ListNode* findKthNode(ListNode* temp,int k)
{
    while(temp && k>1)
    {
        temp=temp->next;
        k--;
    }
    return temp;
}

void reverse(ListNode* head)
{
    ListNode* temp=head;
    ListNode* front;
    ListNode* back=NULL;
    while(temp!=NULL)
    {
        front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }
    return;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* temp=head;
    ListNode* last=NULL;
    while(temp!=NULL)
    {
        ListNode* KthNode=findKthNode(temp,k);
        if(KthNode==NULL)
        {
            if(last)
                last->next=temp;
            break;
        }
        ListNode* first=KthNode->next;
        KthNode->next=NULL;
        reverse(temp);
        if(temp==head)
            head=KthNode;
        else
            last->next=KthNode;
        last=temp;
        temp=first;
    }
    return head;
}
