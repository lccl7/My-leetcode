/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()) return NULL;
        int n = preorder.size();
        return buildtree(preorder, 0, n-1, inorder, 0, n-1);
    }
    
    TreeNode *buildtree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend)
    {
        if(prestart > preend || instart > inend)
            return NULL;
            
        int rootval = preorder[prestart];
        int rootindex = instart;
        while(rootindex < inend)
        {
            if(inorder[rootindex++] == rootval)
                break;
            else
                ++rootindex;
        }
        TreeNode *root = new TreeNode(rootval);
        int len = rootindex - instart;
        root->left = buildtree(preorder, prestart+1, prestart+len, inorder, instart, rootindex-1);
        root->right = buildtree(preorder, prestart+len+1, preend, inorder, rootindex+1, inend);
        return root;
    }
};
