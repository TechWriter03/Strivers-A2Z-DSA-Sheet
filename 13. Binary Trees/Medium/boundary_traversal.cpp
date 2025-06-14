// Input:
// root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output:
// [1, 2, 4, 8, 9, 6, 7, 3]
// Explanation:
//      1 
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7
//    / \
//   8   9

bool isLeaf(Node* node)
{
    return (node->left==NULL && node->right==NULL);
}

void addLeftBoundary(Node* root,vector<int>& ans)
{
    Node* temp=root->left;
    while(temp)
    {
        if(!isLeaf(temp))
            ans.push_back(temp->data);
        if(temp->left)
            temp=temp->left;
        else
            temp=temp->right;
    }
}

void addLeaves(Node* root,vector<int>& ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        addLeaves(root->left,ans);
    if(root->right)
        addLeaves(root->right,ans);
}

void addRightBoundary(Node* root,vector<int>& ans)
{
    stack<int>st;
    Node* temp=root->right;
    while(temp)
    {
        if(!isLeaf(temp))
            st.push(temp->data);
        if(temp->right)
            temp=temp->right;
        else
            temp=temp->left;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> boundaryTraversal(Node* root)
{
    vector<int>ans;
    if(root==NULL)
        return ans;
    if(!isLeaf(root))
        ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}
