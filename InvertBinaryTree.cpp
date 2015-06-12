TreeNode* invertTree(TreeNode* root)
{
    if(!root) return NULL;
    if(!root->left && !root->right) return root;
    if(root->left) invertTree(root->left);
    if(root->right) invertTree(root->right);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}
