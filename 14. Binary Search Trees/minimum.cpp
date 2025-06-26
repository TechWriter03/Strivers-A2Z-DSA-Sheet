// Input:
// root = [10, 5, 20, 2]
// Output:
// 2

int minValue(Node* root)
{
    if(root==NULL)
        return -1;
    Node* temp=root;
    while(temp->left)
        temp=temp->left;
    return temp->data;
}
