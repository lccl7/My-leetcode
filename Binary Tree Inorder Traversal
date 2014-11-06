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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vi;
        if(root == NULL) return vi;
        stack<TreeNode*> st;
        while(!st.empty() || root != NULL )
        {
            if(root != NULL)
            {
                st.push(root);
                    root = root->left;
            }
            else
            {
                root = st.top();
                vi.push_back(root->val);
                st.pop();
                    root = root->right;
            }
        }
        return vi;
    }
};
