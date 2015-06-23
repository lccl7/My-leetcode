vector<int> rightSideView(TreeNode* root)
{
    vector<int> vs;
    if(!root) return vs;
    queue<TreeNode*> qnode;
    qnode.push(root); qnode(NULL);
    while(!qnode.empty())
    {
        TreeNode* tmp = qnode.front();
        qnode.pop();
        if(tmp == NULL)
        {
            if(qnode.empty())
                break;
            else {
                qnode.push(NULL);
            }
        }
        else {
            if(qnode.front() == NULL)
                vs.push_back(tmp->val);
            if(tmp->left)
                qnode.push(tmp->left);
            if(tmp->right)
                qnode.push(tmp->right);
        }
    }
    return vs;
}
