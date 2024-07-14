// Input:
// n = 5
// arr = [1,2,3,4,5]
// Output:
// 1 2 3 4 5
// Explanation: 
// Linked list for the given array will be 1->2->3->4->5.

Node* constructLL(vector<int>& arr) 
{
    Node* head=new Node(arr[0]);
    Node* ptr=head;
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        Node* temp=new Node(arr[i]);
        ptr->next=temp;
        ptr=ptr->next;
    }
    return head;
}
