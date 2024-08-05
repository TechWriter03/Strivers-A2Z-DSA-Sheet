// Input:
// lists: [1->4->5, 1->3->4, 2->6]
// Output:
// 1->1->2->3->4->4->5->6

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int n=lists.size();
    ListNode* dummy=new ListNode(-1), *temp=dummy;
    priority_queue<pair<int,ListNode*>,
    vector<pair<int,ListNode*>>,
    greater<pair<int,ListNode*>>>pq;
    for(int i=0;i<n;i++)
        if(lists[i])
            pq.push({lists[i]->val,lists[i]});
    while(!pq.empty())
    {
        ListNode* minNode=pq.top().second;
        temp->next=minNode;
        temp=minNode;
        pq.pop();
        if(minNode->next)
            pq.push({minNode->next->val,minNode->next});
    }
    return dummy->next;
}
