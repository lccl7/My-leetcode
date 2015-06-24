//Use a recursive way(dfs)

int maxDepth(TreeNode* root)
{
    if(root == NULL) return 0;
    int m = maxDepth(root->left) + 1;
    int n = maxDepth(root->right) + 1;
    return max(m, n);
}

// BFS

int maxDepth(TreeNode* root)
{
    if(root == NULL) return 0;
    queue<TreeNode*> qNode;
    qNode.push(root); qNode.push(NULL);
    int res = 0;
    while(!qNode.empty())
    {
        TreeNode* tmp = qNode.front();
        qNode.pop();
        if(tmp)
        {
            if(tmp->left) qNode.push(tmp->left);
            if(tmp->right) qNode.push(tmp->right);
        }
        else {
            res++;
            if(!qNode.empty()) qNode.push(NULL);
        }
    }
    return res;
}
