// Input:
// root = [10, 5, 11, 4, 7, N, N, N, N, N, 8]
// key = 6
// Output:
// 7

int findCeil(struct Node* root,int key)
{
    int ceil=-1;
    while(root)
    {
        if(root->data==key)
        {
            ceil=root->data;
            break;
        }
        else if(root->data>key)
        {
            ceil=root->data;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return ceil;
}