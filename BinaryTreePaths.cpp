vector<string> binaryTreePaths(TreeNode *t)
{
    vector<string> vs;
    if(!root) return vs;
    string s;
    printPath(root, s, vs);
    return vs;
}

void printPath(TreeNode* root, string s, vector<string>& vs)
{
    if(s == "")
        s += to_string(root->val);
    else s += "->" + to_string(root->val);
    if(!root->left && !root->right)
    {
        vs.push_back(s);
        return;
    }
    else if(!root->left)
        printPath(root->right, s, vs);
    else if(!root->right)
        printPath(root->left, s, vs);
    else {
        printPath(root->left, s, vs);
        printPath(root->right, s, vs);
    }
}
