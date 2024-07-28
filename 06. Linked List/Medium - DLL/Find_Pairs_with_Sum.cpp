// Input:  
// LinkedList: 1 <--> 2 <--> 4 <--> 5 <--> 6 <--> 8 <--> 9
// target = 7
// Output:
// (1, 6), (2,5)
// Explanation:
// We can see that there are two pairs (1, 6) and (2,5) with sum 7.

vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target)
{
    vector<pair<int,int>>ans;
    Node* left=head;
    Node* right=head;
    while(right->next!=NULL)
        right=right->next;
    while(left!=right && right->next!=left)
    {
        int sum = left->data + right->data;
        if(sum<target)
        {
            left=left->next;
        }
        else if(sum>target)
        {
            right=right->prev;
        }
        else
        {
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
    }
    return ans;
}
