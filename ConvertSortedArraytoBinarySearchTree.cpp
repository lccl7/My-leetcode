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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedBST(num, 0, num.size()-1);
    }
    TreeNode *sortedBST(vector<int> &num, int begin, int end)
    {
        if(begin > end) return NULL;
        int mid = (begin + end)/2;
        TreeNode *root = new TreeNode(num[mid]);
        TreeNode *left = sortedBST(num, begin, mid-1);
        TreeNode *right = sortedBST(num, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};
