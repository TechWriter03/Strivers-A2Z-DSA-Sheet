// Input:
// n = 5
// arr = [1,2,3,4,5]
// Output:
// 1 2 3 4 5
// Explanation:
// Linked list for the given array will be 1<->2<->3<->4<->5.

Node* constructDLL(vector<int>& arr) 
{
    int n=arr.size();
    Node* head=new Node(arr[0]);
    Node* ptr=head;
    for(int i=1;i<n;i++)
    {
        Node* temp=new Node(arr[i]);
        ptr->next=temp;
        temp->prev=ptr;
        ptr=ptr->next;
    }
    return head;
}
