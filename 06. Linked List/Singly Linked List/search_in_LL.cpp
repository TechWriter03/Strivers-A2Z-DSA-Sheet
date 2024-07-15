// Input:
// n=4
// 1->2->3->4
// Key = 3
// Output:
// True
// Explanation:
// 3 is present in Linked List, so the function returns true.

bool searchKey(int n, struct Node* head, int key) 
{
    Node* ptr=head;
    while(ptr->next!=NULL)
    {
        if(ptr->data==key)
            return true;
        ptr=ptr->next;
    }
    return false;
}
