// Input:
// ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
// Output:
// [null, 3, 7, true, 9, true, 15, true, 20, false]
// Explanation:
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();    // return 3
// bSTIterator.next();    // return 7
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 15
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 20
// bSTIterator.hasNext(); // return False

class BSTIterator
{
public:
    stack<TreeNode*>inorder;

    BSTIterator(TreeNode* root)
    {
        pushAllLeft(root);
    }

    void pushAllLeft(TreeNode* node)
    {
        while(node->left)
        {
            inorder.push(node);
            node=node->left;
        }
    }
    
    int next()
    {
        TreeNode* node=inorder.top();
        inorder.pop();
        if(node->right)
            pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext()
    {
        return !inorder.empty();
    }
};
