/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //two things are important: 1. the any right val of the root is bigger than the root val.
 //2. any left val of the root is less than the root val.
 // In the getInOrder the pre should be called by the reference.
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = NULL;
        return getInOrder(root, pre);
    }
    
    bool getInOrder(TreeNode *root, TreeNode *&pre)
    {
        if(root == NULL) return true;
        if(getInOrder(root->left, pre) == false)
            return false;
        if(pre && pre->val >= root->val) return false;
        pre = root;
        return getInOrder(root->right, pre);
    }

};

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
    vector<int> vi;
    bool isValidBST(TreeNode *root) {
        getInOrder(root, vi);
        return isorted(vi);
    }
    
    void getInOrder(TreeNode *root, vector<int> &vi)
    {
        if(NULL != root)
        {
            getInOrder(root->left, vi);
            vi.push_back(root->val);
            getInOrder(root->right, vi);
        }
    }
    
    bool isorted(vector<int> &vi)
    {
        for(int i = 0; vi.size() > 0 && i < vi.size() - 1; ++i)
        {
            if(vi[i] >= vi[i+1])
                return false;
        }
        return true;
    }

};
