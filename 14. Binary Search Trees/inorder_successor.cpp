// Input:
// root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14]
// k = 8
// Output:
// 10

int inOrderSuccessor(Node *root,Node *x)
{
    int successor=-1;
    Node* temp=root;
    while(temp)
    {
        if(x->data<temp->data)
        {
            successor=temp->data;
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return successor;
}
