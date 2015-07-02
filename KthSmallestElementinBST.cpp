//pay attention that when k is smaller than count, keep it unchanged

class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int count = countTreeNode(root->left) + 1;
        if(count == k) return root->val;
        else if(count < k)
            return kthSmallest(root->right, k-count);
        else return kthSmallest(root->left, k);
    }
private:
    int countTree(TreeNode* root)
    {
        if(!root) return 0;
        int cl = 0, cr = 0;
        if(root->left) cl = countTree(root->left);
        if(root->right) cr = countTree(root->right);
        return cl + cr + 1;
    }
}
