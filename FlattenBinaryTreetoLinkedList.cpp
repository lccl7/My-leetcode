void flatten(TreeNode* root)
{
    if(root == NULL) return;
    if(root->left)
    {
        TreeNode* Lnode = root->left, rNode = root->right;
        root->left = NULL;
        root->right = leftNode;
        TreeNode* p = Lnode;
        while(p->right)
            p = p->right;
        p->right = rNode;
    }
    flatten(root->right);
}

void flatten(TreeNode* root)
{
    while(root)
    {
        if(root->left && root->right)
        {
            TreeNode* p = root->left;
            while(p->right)
                p = p->right;
            p->right = root->right;
        }
        if(root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}
