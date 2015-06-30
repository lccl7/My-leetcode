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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty()) return NULL;
        int leng = inorder.size();
        return buildtree(inorder, 0, leng-1, postorder, 0, leng-1);
    }
    
    TreeNode *buildtree(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend)
    {
        if(instart > inend || poststart > postend)
            return NULL;
        int rootval = postorder[postend];
        int rootindex = instart;
        while(rootindex < inend)
        {
            if(rootval == inorder[rootindex])
                break;
            else
                ++rootindex;
        }
        TreeNode *root = new TreeNode(rootval);
        int len = rootindex - instart;
        root->left = buildtree(inorder, instart, rootindex-1, postorder, poststart, poststart+len-1);
        root->right = buildtree(inorder, rootindex+1, inend, postorder, poststart+len, postend-1);
        return root;
    }
};
