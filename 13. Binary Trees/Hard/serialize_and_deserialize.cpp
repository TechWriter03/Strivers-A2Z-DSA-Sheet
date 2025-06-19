// Input:
// root = [1,2,3,null,null,4,5]
// Output:
// [1,2,3,null,null,4,5]
// Explanation:
//   1
//  / \
// 2   3
//    / \
//   4   5

string serialize(TreeNode* root)
{
    if(root==NULL)
        return "";
    string data="";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            data+="N,";
        }
        else
        {
            data+=to_string(temp->val)+',';
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return data;
}

string getValue(int& ind,string data)
{
    int n=data.size();
    string value="";
    while(data[ind]!=',' && ind<n)
        value+=data[ind++];
    ind++;
    return value;
}

TreeNode* deserialize(string data)
{
    if(data=="")
        return NULL;
    int ind=0;
    queue<TreeNode*>q;
    TreeNode* root=new TreeNode(stoi(getValue(ind,data)));
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        string leftVal=getValue(ind,data);
        if(leftVal=="N")
        {
            node->left=NULL;
        }
        else
        {
            node->left=new TreeNode(stoi(leftVal));
            q.push(node->left);
        }
        string rightVal=getValue(ind,data);
        if(rightVal=="N")
        {
            node->right=NULL;
        }
        else
        {
            node->right=new TreeNode(stoi(rightVal));
            q.push(node->right);
        }
    }
    return root;
}
