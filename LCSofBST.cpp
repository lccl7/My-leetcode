TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(p == root || q == root)
        return root;
    if(root->val >= p->val && root->val <= q->val)
        return root;
    if(root->val < p->val)
        return lowestCommonAncestor(root->right, p, q);
    else {
        return lowestCommonAncestor(root->left, p, q);
    }
}
