//count the height from the root to the leftmost while
//count the height from the root to the rightmost
//If they are the same, then the nodes are pow(2, h)-1
//If not, do it in a recursive way

int countNodes(TreeNode* root)
{
    if(!root) return 0;
    int cl = 1, cr = 1;
    TreeNode *root1 = root, *root2 = root;
    while(root1->left)
    {
        cl++;
        root1 = root1->left;
    }
    while(root2->right)
    {
        cr++;
        root2 = root2->right;
    }

    if(cl == cr) return (1 << cl)-1;
    else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}
